
// ========================================================================
// ??1idPonytail@@QAA@XZ
// EA  : 0x82B35E08
// RVA : 0x00B35E08
// PDB : w:\tech5\tungsten\game\animation\ponytail.cpp
// ========================================================================

void __fastcall idPonytail::~idPonytail(idPonytail *this)
{
  idAnimator_Ponytail::~idAnimator_Ponytail(this: &this->ponytailAnimator);
  idAnimStack::~idAnimStack(this: &this->animStack);
}


// ========================================================================
// __unwind$487274
// EA  : 0x82B35E50
// RVA : 0x00B35E50
// PDB : w:\tech5\tungsten\game\animation\ponytail.cpp
// ========================================================================

void _unwind_487274()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ??0idPonytail@@QAA@XZ
// EA  : 0x82B35EF8
// RVA : 0x00B35EF8
// PDB : w:\tech5\tungsten\game\animation\ponytail.cpp
// ========================================================================

idPonytail *__fastcall idPonytail::idPonytail(idPonytail *this)
{
  this->declPonytail = nullptr;
  this->parent.spawnId.value = 0x1FFF;
  idAnimStack::idAnimStack(this: &this->animStack);
  this->attachmentHandle.value = -1;
  idAnimator_Ponytail::idAnimator_Ponytail(this: &this->ponytailAnimator);
  this->usingParentAnimStack = false;
  this->initialized = false;
  return this;
}


// ========================================================================
// __unwind$487615
// EA  : 0x82B35F5C
// RVA : 0x00B35F5C
// PDB : w:\tech5\tungsten\game\animation\ponytail.cpp
// ========================================================================

void _unwind_487615()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ?Update@idPonytail@@QAAXXZ
// EA  : 0x82B35F88
// RVA : 0x00B35F88
// PDB : w:\tech5\tungsten\game\animation\ponytail.cpp
// ========================================================================

void __fastcall idPonytail::Update(idPonytail *this)
{
  idGameTimeManager *p_gameTimeManager; // r28
  idGameTimeManager *v3; // r27
  int GameMsPerFrame; // r26
  int PreviousGameMs; // r29
  int GameMs; // r3
  float *v7; // [sp+8h] [-98h]
  float *v8; // [sp+Ch] [-94h]
  float *v9; // [sp+10h] [-90h]

  if ( this->initialized && !this->usingParentAnimStack )
  {
    p_gameTimeManager = &clientGame->gameTimeManager;
    v3 = (idGameTimeManager *)(timeManager.gameTimePerFrame.value * timeManager.gameHz);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAnimStack::BlendStackInternal(
      this: &this->animStack,
      currentTime: GameMs,
      previousTime: PreviousGameMs,
      gameMsPerFrame: GameMsPerFrame,
      ticksPerSec: v3,
      game: p_gameTimeManager,
      parallelJobList: gameLocal->parallelJobList,
      localR: nullptr,
      localS: v7,
      localT: v8,
      localU: v9);
  }
}


// ========================================================================
// ?Shutdown@idPonytail@@QAAXXZ
// EA  : 0x82B36058
// RVA : 0x00B36058
// PDB : w:\tech5\tungsten\game\animation\ponytail.cpp
// ========================================================================

void __fastcall idPonytail::Shutdown(idPonytail *this)
{
  int value; // r10
  idEntity *v3; // r3
  int v4; // r9
  idEntity *v5; // r3
  idEntity *v6; // r3
  idAttachmentCollection *v7; // r3

  value = this->parent.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr && idEntity::CastTo(c: v3) != nullptr && this->attachmentHandle.value != -1 )
    {
      v4 = this->parent.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13 && (v5 = gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
        v6 = idEntity::CastTo(c: v5);
      else
        v6 = nullptr;
      v7 = v6->GetAttachments_2(this: v6);
      if ( v7 != nullptr )
        idAttachmentCollection::RemoveAttachment(this: v7, handle: &this->attachmentHandle);
      this->attachmentHandle.value = -1;
    }
  }
  this->initialized = false;
}


// ========================================================================
// ?Init@idPonytail@@QAA_NPAVidEntity@@@Z
// EA  : 0x82B36148
// RVA : 0x00B36148
// PDB : w:\tech5\tungsten\game\animation\ponytail.cpp
// ========================================================================

int __fastcall idPonytail::Init(idPonytail *this, idEntity *parent_)
{
  int value; // r9
  idEntity *v4; // r3
  idAnimatedEntity *v5; // r3
  idAnimatedEntity *v6; // r3
  idAnimatedEntity *v7; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v9; // r28
  const idDeclMD6 *decl; // r11
  const char *v11; // r4
  int v12; // r9
  idEntity *v13; // r3
  idEntity *v14; // r3
  idAnimStack *p_animStack; // r4
  idHandle<int,enum invalidAttachment_t,-1> *v16; // r3
  idAttachmentCollection *v17; // r29
  const idAttachment *v18; // r3
  idPresentable **p_presentable; // r29
  idPresentable *presentable; // r3
  idPresentableAnimatedEntity *v21; // r3
  idTreeAnimator *TreeAnimator; // r25
  idGameTimeManager *v23; // r3
  idTreeAnimator *v25; // [sp+8h] [-E8h]
  int v26; // [sp+Ch] [-E4h]
  int v27; // [sp+10h] [-E0h]
  int v28; // [sp+14h] [-DCh]
  int v29; // [sp+18h] [-D8h]
  int v30; // [sp+1Ch] [-D4h]
  int v31; // [sp+20h] [-D0h]
  int v32; // [sp+24h] [-CCh]
  int v33; // [sp+28h] [-C8h]
  int v34; // [sp+2Ch] [-C4h]
  int v35; // [sp+30h] [-C0h]
  int v36; // [sp+34h] [-BCh]
  int v37; // [sp+38h] [-B8h]
  int v38; // [sp+3Ch] [-B4h]
  int v39; // [sp+40h] [-B0h]
  int v40; // [sp+44h] [-ACh]
  int v41; // [sp+48h] [-A8h]
  int v42; // [sp+4Ch] [-A4h]
  int v43; // [sp+50h] [-A0h]
  int v44; // [sp+58h] [-98h]
  idAttachmentCollection v45; // [sp+60h] [-90h] BYREF
  idStr v46[3]; // [sp+74h] [-7Ch] BYREF

  if ( parent_ != nullptr )
  {
    v45.attachments.list = (idAttachment *)parent_->entityNumber;
    this->parent.spawnId.value = (*((_DWORD *)&gameLocal->__vftable + (int)&v45.attachments.list[275].originOffset.z + 3) << 13)
                               | (int)v45.attachments.list;
  }
  else
  {
    this->parent.spawnId.value = 0x1FFF;
  }
  value = this->parent.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = (idAnimatedEntity *)idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  v6 = idAnimatedEntity::CastTo(c: v5);
  v7 = v6;
  if ( v6 != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v6);
    v9 = TreeAnimatorFromPresentable;
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      decl = TreeAnimatorFromPresentable->decl;
      v11 = decl != nullptr ? decl->name.str : &byte_8200D768;
      if ( idStr::Icmp(s1: this->declPonytail->modelDef->name.str, s2: v11) == 0 )
      {
        p_animStack = v7->GetAnimStack_2(this: v7);
        this->usingParentAnimStack = true;
LABEL_28:
        idAnimatorParms_Ponytail::idAnimatorParms_Ponytail(
          this: (idAnimatorParms_Ponytail *)&v45.parent,
          animStack_: p_animStack,
          name_: "ponytail",
          blendOp_: BOP_LERP,
          originBlend_: ORIGINBLEND_BRANCH,
          weightGroup_: MD6_WEIGHTGROUP_ALL,
          filterGroup_: MD6_WEIGHTGROUP_ALL,
          alpha_: 1.0,
          declPonytail_: this->declPonytail,
          parentAnimator_: v25,
          a11: v26,
          a12: v27,
          a13: v28,
          a14: v29,
          a15: v30,
          a16: v31,
          a17: v32,
          a18: v33,
          a19: v34,
          a20: v35,
          a21: v36,
          a22: v37,
          a23: v38,
          a24: v39,
          a25: v40,
          a26: v41,
          a27: v42,
          a28: v43,
          a29: this->declPonytail,
          a30: v44,
          a31: v9);
        v23 = gameLocal->GetGameTimeManager(this: gameLocal);
        idAnimator_Base::Init(
          this: &this->ponytailAnimator,
          gametimeManager: v23,
          parms: (const idAnimatorParms_Base *)&v45.parent);
        this->initialized = true;
        idStr::FreeData(this: v46);
        return 1;
      }
    }
  }
  else
  {
    v9 = nullptr;
  }
  v12 = this->parent.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13 && (v13 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr )
    v14 = idEntity::CastTo(c: v13);
  else
    v14 = nullptr;
  v16 = (idHandle<int,enum invalidAttachment_t,-1> *)v14->GetAttachments_2(this: v14);
  v17 = (idAttachmentCollection *)v16;
  if ( v16 != nullptr )
  {
    this->attachmentHandle = (idHandle<int,enum invalidAttachment_t,-1>)idAttachmentCollection::AddAttachment(
                                                                          this: &v45,
                                                                          result: v16,
                                                                          modelName: this->declPonytail->modelDef->name.str,
                                                                          tag: this->declPonytail->tagName.str)->value;
    v18 = idAttachmentCollection::Get(this: v17, handle: &this->attachmentHandle);
    p_presentable = &v18->presentable;
    if ( v18 != nullptr )
    {
      if ( (*((_BYTE *)v18 + 104) & 0x80) != 0 )
      {
        presentable = v18->presentable;
        if ( *p_presentable != nullptr && presentable->GetAnimatedEntityInterface(this: presentable) != nullptr )
        {
          v21 = (*p_presentable)->GetAnimatedEntityInterface(this: *p_presentable);
          TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v21);
          idPresentable::UpdateModelTransform(this: *p_presentable);
          idAnimStack::Init(this: &this->animStack, treeAnimator: TreeAnimator);
          p_animStack = &this->animStack;
          goto LABEL_28;
        }
      }
      idPonytail::Shutdown(this);
      idLib::Warning(fmt: "Ponytail attachments must be animated models");
    }
    else
    {
      idPonytail::Shutdown(this);
      idLib::Warning(fmt: "Failed to create ponytail attachment");
    }
  }
  else
  {
    idPonytail::Shutdown(this);
    idLib::Warning(fmt: "Parent must have an attachment collection to attach a ponytail");
  }
  return 0;
}


// ========================================================================
// __unwind$488044_0
// EA  : 0x82B3641C
// RVA : 0x00B3641C
// PDB : w:\tech5\tungsten\game\animation\ponytail.cpp
// ========================================================================

void _unwind_488044_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 240 + 112));
}

