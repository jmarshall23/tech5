
// ========================================================================
// ?GetSubWebAndStateNames@@YAXPBDAAVidStr@@1@Z
// EA  : 0x82CACF10
// RVA : 0x00CACF10
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void __fastcall GetSubWebAndStateNames(const char *animRef, idStr *subWebName, idStr *stateName)
{
  int v6; // r3
  int v7; // r30
  idStr v8[2]; // [sp+50h] [-50h] BYREF

  idStr::idStr(this: v8, text: animRef);
  v6 = idStr::Find(str: v8[0].data, c: 58, start: 0, end: v8[0].len);
  v7 = v6;
  if ( v6 == -1 )
  {
    idStr::operator=(this: subWebName, text: SPECTATOR_SUBWEB_NAME);
    idStr::operator=(this: stateName, text: animRef);
  }
  else
  {
    idStr::Mid(this: v8, start: 0, len: v6, result: subWebName);
    idStr::Right(this: v8, len: v8[0].len - v7 - 1, result: stateName);
  }
  idStr::FreeData(this: v8);
}


// ========================================================================
// __unwind$488213
// EA  : 0x82CACFB4
// RVA : 0x00CACFB4
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488213()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?OnActivate@idRaceSpectator@@EAAXPAVidEntity@@@Z
// EA  : 0x82CACFE8
// RVA : 0x00CACFE8
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void __fastcall idRaceSpectator::OnActivate(idRaceSpectator *this, idEntity *activator)
{
  idStr v3; // [sp+50h] [-B0h] BYREF
  idStr v4; // [sp+70h] [-90h] BYREF
  idStr v5; // [sp+90h] [-70h] BYREF
  idStr v6[2]; // [sp+B0h] [-50h] BYREF

  v6[0].len = 0;
  v6[0].allocedAndFlag = 20;
  v6[0].data = v6[0].baseBuffer;
  v6[0].baseBuffer[0] = 0;
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  v5.len = 0;
  v5.baseBuffer[0] = 0;
  GetSubWebAndStateNames(animRef: this->idleAnim.data, subWebName: v6, stateName: &v5);
  v4.allocedAndFlag = 20;
  v4.data = v4.baseBuffer;
  v4.len = 0;
  v4.baseBuffer[0] = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.len = 0;
  v3.baseBuffer[0] = 0;
  GetSubWebAndStateNames(animRef: this->triggerAnim.data, subWebName: &v4, stateName: &v3);
  if ( idAnimator_AnimWeb::ChangeStateVia(
         this: &this->animWebAnimator,
         subWebName: v6[0].data,
         stateName: v5.data,
         viaSubWebName: v4.data,
         viaStateName: v3.data,
         interruptPath_: INTR_PATH_YES,
         interruptBlend_: INTR_BLEND_NO,
         blendEventMask_: 0) == 0 )
    idLib::Warning(fmt: "idRaceSpectator '%s' - Failed to path to anim node '%s:%s'", this->name.data, v4.data, v3.data);
  idStr::FreeData(this: &v3);
  idStr::FreeData(this: &v4);
  idStr::FreeData(this: &v5);
  idStr::FreeData(this: v6);
}


// ========================================================================
// __unwind$488246
// EA  : 0x82CAD0E0
// RVA : 0x00CAD0E0
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488246()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 176));
}


// ========================================================================
// __unwind$488247_0
// EA  : 0x82CAD108
// RVA : 0x00CAD108
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488247_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$488248
// EA  : 0x82CAD130
// RVA : 0x00CAD130
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488248()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$488249
// EA  : 0x82CAD158
// RVA : 0x00CAD158
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488249()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 80));
}


// ========================================================================
// ?Spawn@idRaceSpectator@@QAAXXZ
// EA  : 0x82CAD188
// RVA : 0x00CAD188
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void __fastcall idRaceSpectator::Spawn(idRaceSpectator *this)
{
  idPresentable *presentable; // r3
  int v3; // r29
  int GameMs; // r28
  const idDeclAnimWeb *animWeb; // r27
  char *data; // r26
  char *v7; // r25
  idAnimStack *v8; // r3
  idGameTimeManager *v9; // r3
  int i; // r28
  const char *v11; // [sp+8h] [-188h]
  const char *v12; // [sp+Ch] [-184h]
  int v13; // [sp+10h] [-180h]
  int v14; // [sp+14h] [-17Ch]
  int v15; // [sp+18h] [-178h]
  int v16; // [sp+1Ch] [-174h]
  int v17; // [sp+20h] [-170h]
  int v18; // [sp+24h] [-16Ch]
  int v19; // [sp+28h] [-168h]
  int v20; // [sp+2Ch] [-164h]
  int v21; // [sp+30h] [-160h]
  int v22; // [sp+34h] [-15Ch]
  int v23; // [sp+38h] [-158h]
  int v24; // [sp+3Ch] [-154h]
  int v25; // [sp+40h] [-150h]
  int v26; // [sp+44h] [-14Ch]
  int v27; // [sp+48h] [-148h]
  int v28; // [sp+4Ch] [-144h]
  int v29; // [sp+50h] [-140h]
  int v30; // [sp+58h] [-138h]
  int v31; // [sp+60h] [-130h]
  int v32; // [sp+68h] [-128h]
  idStr v33; // [sp+70h] [-120h] BYREF
  idStr v34; // [sp+90h] [-100h] BYREF
  idAttachmentCollection v35[11]; // [sp+B0h] [-E0h] BYREF

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) == nullptr )
    idLib::Error(fmt: "idRaceSpectator: model is not an MD6!");
  if ( this->animWeb == nullptr )
    idLib::Error(fmt: "idRaceSpectator: NULL anim web decl!");
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  v3 = 0;
  v34.len = 0;
  v34.baseBuffer[0] = 0;
  v34.allocedAndFlag = 20;
  v34.data = v34.baseBuffer;
  v33.len = 0;
  v33.baseBuffer[0] = 0;
  v33.allocedAndFlag = 20;
  v33.data = v33.baseBuffer;
  GetSubWebAndStateNames(animRef: this->idleAnim.data, subWebName: &v34, stateName: &v33);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  animWeb = this->animWeb;
  data = v33.data;
  v7 = v34.data;
  v8 = this->GetAnimStack_2(this);
  idAnimatorParms_AnimWeb::idAnimatorParms_AnimWeb(
    this: (idAnimatorParms_AnimWeb *)&v35[0].parent,
    animStack_: v8,
    name_: "spectator",
    blendOp_: BOP_LERP,
    originBlend_: ORIGINBLEND_BRANCH,
    weightGroup_: MD6_WEIGHTGROUP_ALL,
    filterGroup_: MD6_WEIGHTGROUP_ALL,
    alpha_: 1.0,
    webDecl_: (const idDeclAnimWeb *)&unk_82150000,
    initialSubWebName_: v11,
    initialStateName_: v12,
    curTime_: v13,
    a13: v14,
    a14: v15,
    a15: v16,
    a16: v17,
    a17: v18,
    a18: v19,
    a19: v20,
    a20: v21,
    a21: v22,
    a22: v23,
    a23: v24,
    a24: v25,
    a25: v26,
    a26: v27,
    a27: v28,
    a28: v29,
    a29: animWeb,
    a30: v30,
    a31: v7,
    a32: v31,
    a33: data,
    a34: v32,
    a35: GameMs);
  v9 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(
    this: &this->animWebAnimator,
    gametimeManager: v9,
    parms: (const idAnimatorParms_Base *)&v35[0].parent);
  for ( i = 0; i < this->attachedItems.num; ++v3 )
  {
    idAttachmentCollection::AddAttachment(
      this: v35,
      result: &this->attachments.attachments,
      decl: (idDeclInventory *)this->attachedItems.list[v3].inventoryItem,
      tagName: this->attachedItems.list[v3].tagName.data,
      fxAttachInfo: nullptr);
    ++i;
  }
  idEntity::BecomeActive(this, flags: ((_cntlzw(this->alwaysUpdate) & 0x20) == 0) + 4);
  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: (idAnimatorParms_AnimWeb *)&v35[0].parent);
  idStr::FreeData(this: &v33);
  idStr::FreeData(this: &v34);
}


// ========================================================================
// $LN60_1
// EA  : 0x82CAD34C
// RVA : 0x00CAD34C
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _LN60_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 144));
}


// ========================================================================
// __unwind$488601
// EA  : 0x82CAD374
// RVA : 0x00CAD374
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488601()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$488602
// EA  : 0x82CAD39C
// RVA : 0x00CAD39C
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488602()
{
  int v0; // r12

  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: (idAnimatorParms_AnimWeb *)(v0 - 400 + 192));
}


// ========================================================================
// ??1idRaceSpectator@@UAA@XZ
// EA  : 0x82CAD490
// RVA : 0x00CAD490
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void __fastcall idRaceSpectator::~idRaceSpectator(idRaceSpectator *this)
{
  idAttachmentCollection *p_attachments; // r29

  this->__vftable = (idRaceSpectator_vtbl *)&idRaceSpectator::`vftable';
  p_attachments = &this->attachments;
  idAttachmentCollection::FreeAttachments(this: &this->attachments);
  idStaticList<idRaceSpectator::spectatorAttachment_t,2>::~idStaticList<idRaceSpectator::spectatorAttachment_t,2>(this: &this->attachedItems);
  this->animWebAnimator.__vftable = (idAnimWebSpectator_vtbl *)&idAnimWebSpectator::`vftable';
  idAnimator_AnimWeb::~idAnimator_AnimWeb(this: &this->animWebAnimator);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_attachments);
  idStr::FreeData(this: &this->triggerAnim);
  idStr::FreeData(this: &this->idleAnim);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$488796_0
// EA  : 0x82CAD508
// RVA : 0x00CAD508
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488796_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488797
// EA  : 0x82CAD530
// RVA : 0x00CAD530
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488797()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 5204));
}


// ========================================================================
// __unwind$488798_0
// EA  : 0x82CAD55C
// RVA : 0x00CAD55C
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488798_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 5236));
}


// ========================================================================
// __unwind$488799_0
// EA  : 0x82CAD588
// RVA : 0x00CAD588
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488799_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5272));
}


// ========================================================================
// __unwind$488800
// EA  : 0x82CAD5B4
// RVA : 0x00CAD5B4
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488800()
{
  int v0; // r12

  idAnimWebSpectator::~idAnimWebSpectator(this: (idAnimWebSpectator *)(*(_DWORD *)(v0 - 128 + 148) + 5292));
}


// ========================================================================
// __unwind$488801
// EA  : 0x82CAD5E0
// RVA : 0x00CAD5E0
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_488801()
{
  int v0; // r12

  idStaticList<idRaceSpectator::spectatorAttachment_t,2>::~idStaticList<idRaceSpectator::spectatorAttachment_t,2>(this: (idStaticList<idRaceSpectator::spectatorAttachment_t,2> *)(*(_DWORD *)(v0 - 128 + 148) + 5940));
}


// ========================================================================
// ??0idRaceSpectator@@QAA@XZ
// EA  : 0x82CAD6D8
// RVA : 0x00CAD6D8
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

idRaceSpectator *__fastcall idRaceSpectator::idRaceSpectator(idRaceSpectator *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->animWeb = nullptr;
  this->__vftable = (idRaceSpectator_vtbl *)&idRaceSpectator::`vftable';
  this->idleAnim.allocedAndFlag = 20;
  this->idleAnim.data = this->idleAnim.baseBuffer;
  this->idleAnim.len = 0;
  this->idleAnim.baseBuffer[0] = 0;
  this->triggerAnim.allocedAndFlag = 20;
  this->triggerAnim.len = 0;
  this->triggerAnim.data = this->triggerAnim.baseBuffer;
  this->triggerAnim.baseBuffer[0] = 0;
  this->alwaysUpdate = false;
  idMQBuffer::idMQBuffer(this: &this->attachments);
  idAnimator_AnimWeb::idAnimator_AnimWeb(this: &this->animWebAnimator);
  this->animWebAnimator.__vftable = (idAnimWebSpectator_vtbl *)&idAnimWebSpectator::`vftable';
  idStaticList<idRaceSpectator::spectatorAttachment_t,2>::idStaticList<idRaceSpectator::spectatorAttachment_t,2>(this: &this->attachedItems);
  memset(Dst: this->attachedItems.list, Val: 0, Size: 36 * this->attachedItems.size);
  return this;
}


// ========================================================================
// __unwind$489139_0
// EA  : 0x82CAD7A4
// RVA : 0x00CAD7A4
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_489139_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489140_0
// EA  : 0x82CAD7CC
// RVA : 0x00CAD7CC
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_489140_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 5204));
}


// ========================================================================
// __unwind$489141_1
// EA  : 0x82CAD7F8
// RVA : 0x00CAD7F8
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_489141_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 5236));
}


// ========================================================================
// __unwind$489142_0
// EA  : 0x82CAD824
// RVA : 0x00CAD824
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_489142_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5272));
}


// ========================================================================
// __unwind$489143_0
// EA  : 0x82CAD850
// RVA : 0x00CAD850
// PDB : w:\tech5\tungsten\game\entities\racespectator.cpp
// ========================================================================

void _unwind_489143_0()
{
  int v0; // r12

  idAnimWebSpectator::~idAnimWebSpectator(this: (idAnimWebSpectator *)(*(_DWORD *)(v0 - 112 + 132) + 5292));
}

