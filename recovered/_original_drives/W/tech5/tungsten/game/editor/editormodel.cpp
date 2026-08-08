
// ========================================================================
// ?GetAnimTime@idEditorModelInterface@@UBAMXZ
// EA  : 0x82BD7C48
// RVA : 0x00BD7C48
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

float __fastcall idEditorModelInterface::GetAnimTime(idEditorModelInterface *this)
{
  idEditorModelEntity *v1; // r3
  idEditorModelEntity *v2; // r3
  double caretTime; // fp1

  v1 = (idEditorModelEntity *)this->GetEntity(this);
  v2 = idEditorModelEntity::CastTo(c: v1);
  if ( v2 != nullptr )
    caretTime = v2->caretTime;
  else
    caretTime = 0.0;
  return *((float *)&caretTime + 1);
}


// ========================================================================
// ?SetModel@idEditorModelEntity@@UAAXPAVidRenderModel@@@Z
// EA  : 0x82BD7CC8
// RVA : 0x00BD7CC8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelEntity::SetModel(idEditorModelEntity *this, idRenderModel *model)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v5; // r30

  idAnimatedEntity::SetModel(this, model);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v5 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v5 != nullptr )
  {
    idTreeAnimator::SetRemoveOriginRotation(this: v5, removeRotation: false);
    idTreeAnimator::SetRemoveOriginRotation(this: v5, removeRotation: false);
  }
}


// ========================================================================
// ?UpdateUncompressedTransform@idEditorModelEntity@@QAAXXZ
// EA  : 0x82BD7D48
// RVA : 0x00BD7D48
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelEntity::UpdateUncompressedTransform(idEditorModelEntity *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r31
  idTreeAnimator *TreeAnimator; // r3
  idTreeAnimator *v4; // r29
  float *p_x; // r11
  idPresentableAnimatedEntity *uncompressedModelView; // r10
  float *p_deferredAxis; // r10
  float *p_axis; // r11
  bool v9; // r3
  bool v10; // r3

  if ( this->uncompressedModelView != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: this->uncompressedModelView);
    v4 = TreeAnimator;
    if ( TreeAnimatorFromPresentable != nullptr && TreeAnimator != nullptr )
    {
      p_x = &TreeAnimatorFromPresentable->deferredOrigin.x;
      if ( !TreeAnimatorFromPresentable->useDeferredPosition )
        p_x = &TreeAnimatorFromPresentable->g.origin.x;
      uncompressedModelView = this->uncompressedModelView;
      uncompressedModelView->origin.x = *p_x;
      uncompressedModelView->origin.y = p_x[1];
      uncompressedModelView->origin.z = p_x[2];
      p_deferredAxis = (float *)&TreeAnimatorFromPresentable->deferredAxis;
      if ( !TreeAnimatorFromPresentable->useDeferredPosition )
        p_deferredAxis = (float *)&TreeAnimatorFromPresentable->g.axis;
      p_axis = (float *)&this->uncompressedModelView->axis;
      *p_axis = *p_deferredAxis;
      p_axis[1] = p_deferredAxis[1];
      p_axis[2] = p_deferredAxis[2];
      p_axis[3] = p_deferredAxis[3];
      p_axis[4] = p_deferredAxis[4];
      p_axis[5] = p_deferredAxis[5];
      p_axis[6] = p_deferredAxis[6];
      p_axis[7] = p_deferredAxis[7];
      p_axis[8] = p_deferredAxis[8];
      v9 = idTreeAnimator::GetRemoveOriginTranslation(ptr: TreeAnimatorFromPresentable);
      idTreeAnimator::SetRemoveOriginRotation(this: v4, removeRotation: v9);
      v10 = idTreeAnimator::GetRemoveOriginTranslation(ptr: TreeAnimatorFromPresentable);
      idTreeAnimator::SetRemoveOriginRotation(this: v4, removeRotation: v10);
      idPresentable::UpdateModelTransform(this: this->uncompressedModelView);
      this->uncompressedModelView->Present(this: this->uncompressedModelView);
    }
  }
}


// ========================================================================
// ?SetAnimTime@idEditorModelEntity@@QAAXM@Z
// EA  : 0x82BD7E68
// RVA : 0x00BD7E68
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelEntity::SetAnimTime(idEditorModelEntity *this, double timeSeconds)
{
  __int64 v4; // r11
  idMD6Leaf::wrapMode_t v5; // r5
  const idMD6Anim *curAnim; // r4
  idMD6AnimData *animData; // r11
  double v8; // fp31
  idMD6Leaf::wrapMode_t v9; // r5
  idPresentableAnimatedEntity *uncompressedModelView; // r10
  const idMD6Anim *curAnimUncompressed; // r4

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    curAnim = this->curAnim;
    if ( curAnim != nullptr )
    {
      animData = curAnim->animData;
      if ( animData != nullptr )
        LODWORD(v4) = animData->frameRate;
      else
        LODWORD(v4) = 30;
      v8 = (float)((float)v4 * (float)timeSeconds);
      idMD6LeafPause::Init(
        this: &this->leafPause,
        anim: curAnim,
        frame: v8,
        wrapMode: v5,
        weightGroup: MD6_WEIGHTGROUP_LEGS,
        a6: 0);
      uncompressedModelView = this->uncompressedModelView;
      this->leaf = &this->leafPause;
      if ( uncompressedModelView != nullptr )
      {
        curAnimUncompressed = this->curAnimUncompressed;
        if ( curAnimUncompressed != nullptr )
        {
          idMD6LeafPause::Init(
            this: &this->leafPauseUncompressed,
            anim: curAnimUncompressed,
            frame: v8,
            wrapMode: v9,
            weightGroup: MD6_WEIGHTGROUP_LEGS,
            a6: 0);
          this->leafUncompressed = &this->leafPauseUncompressed;
        }
      }
    }
  }
}


// ========================================================================
// ?SetRemoveOriginTranslation@idEditorModelEntity@@QAAX_N@Z
// EA  : 0x82BD7F40
// RVA : 0x00BD7F40
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelEntity::SetRemoveOriginTranslation(idEditorModelEntity *this, bool remove)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r30

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v6 != nullptr )
  {
    this->movement = (_cntlzw(remove) & 0x20) != 0;
    idTreeAnimator::SetRemoveOriginRotation(this: v6, removeRotation: remove);
  }
}


// ========================================================================
// ?GetRemoveOriginRotation@idEditorModelEntity@@QBA_NXZ
// EA  : 0x82BD7FA8
// RVA : 0x00BD7FA8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

BOOL __fastcall idEditorModelEntity::GetRemoveOriginRotation(idEditorModelEntity *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r30

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  return v4 != nullptr && idTreeAnimator::GetRemoveOriginTranslation(ptr: v4);
}


// ========================================================================
// ?AnimEvent_VoiceOver@idEditorModelEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82BD8018
// RVA : 0x00BD8018
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

idEditorModelEntity *__fastcall idEditorModelEntity::AnimEvent_VoiceOver(
        idEditorModelEntity *this,
        idAI2 *result,
        const idMD6Anim *animHandle,
        const idDeclVoiceOver *vo)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v10; // r30

  if ( vo != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    presentable = result->presentable;
    v10 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    result->UpdateModelTransform(this: result);
    if ( v10 != nullptr )
      idFaceMgr::StartVoiceOver(this: (idFaceMgr *)&result->disassembleLoot.lootBoxes.num, owner: result, ta: v10, vo);
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Invalid voice over decl specified for AnimEvent_VoiceOver");
    return this;
  }
}


// ========================================================================
// ?AnimEvent_VoiceTrack@idEditorModelEntity@@QAA?AVeventVoid@@PBVidDeclVoiceOver@@H@Z
// EA  : 0x82BD80B8
// RVA : 0x00BD80B8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

idEditorModelEntity *__fastcall idEditorModelEntity::AnimEvent_VoiceTrack(
        idEditorModelEntity *this,
        idAI2 *result,
        const idDeclVoiceOver *vo,
        int trackIndex)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v11; // r30

  if ( vo != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    presentable = result->presentable;
    v11 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v11 != nullptr )
      idFaceMgr::StartVoiceTrack(
        this: (idFaceMgr *)&result->disassembleLoot.lootBoxes.num,
        owner: result,
        ta: v11,
        vo,
        trackIndex);
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Invalid voice over decl specified for AnimEvent_VoiceOver");
    return this;
  }
}


// ========================================================================
// ?AnimEvent_LeftRearFoot@idEditorModelEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BD8150
// RVA : 0x00BD8150
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

idEditorModelEntity *__fastcall idEditorModelEntity::AnimEvent_LeftRearFoot(
        idEditorModelEntity *this,
        idEntity *result,
        const idMD6Anim *animHandle)
{
  const idSoundShader *y_low; // r5

  y_low = (const idSoundShader *)LODWORD(result[11].bindInfo.bindTag.trans.y);
  if ( y_low != nullptr )
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_ANY,
      shader: y_low,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?GetTreeAnimator@idEditorModelInterface@@UAAPAVidTreeAnimator@@H@Z
// EA  : 0x82BD81D8
// RVA : 0x00BD81D8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

idTreeAnimator *__fastcall idEditorModelInterface::GetTreeAnimator(idEditorModelInterface *this, const int id)
{
  idEditorModelEntity *v3; // r3
  idEditorModelEntity *v4; // r3
  idAnimatedEntity *v5; // r31
  idPresentable *presentable; // r3
  idPresentableAnimatedEntity *allocedAndFlag; // r3

  v3 = (idEditorModelEntity *)this->GetEntity(this);
  v4 = idEditorModelEntity::CastTo(c: v3);
  v5 = v4;
  if ( v4 != nullptr )
  {
    presentable = v4->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v5);
      presentable = v5->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( id != 1 )
      return idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v5);
    allocedAndFlag = (idPresentableAnimatedEntity *)v5[1].name.allocedAndFlag;
    if ( allocedAndFlag != nullptr )
      return idPresentableAnimatedEntity::GetTreeAnimator(this: allocedAndFlag);
  }
  return nullptr;
}


// ========================================================================
// ?PlayVTR@idEditorModelInterface@@UAA_NPBVidDeclVoiceOver@@H@Z
// EA  : 0x82BD8268
// RVA : 0x00BD8268
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

idAI2 *__fastcall idEditorModelInterface::PlayVTR(
        idEditorModelInterface *this,
        const idDeclVoiceOver *vo,
        int trackIndex)
{
  idEditorModelEntity *v5; // r3
  idAI2 *result; // r3
  char v7; // [sp+50h] [-20h] BYREF

  v5 = (idEditorModelEntity *)this->GetEntity(this);
  result = (idAI2 *)idEditorModelEntity::CastTo(c: v5);
  if ( result != nullptr )
  {
    idEditorModelEntity::AnimEvent_VoiceTrack(this: (idEditorModelEntity *)&v7, result, vo, trackIndex);
    return (idAI2 *)1;
  }
  return result;
}


// ========================================================================
// ?StopVTR@idEditorModelInterface@@UAA_NXZ
// EA  : 0x82BD82D0
// RVA : 0x00BD82D0
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

idEditorModelEntity *__fastcall idEditorModelInterface::StopVTR(idEditorModelInterface *this)
{
  idEditorModelEntity *v1; // r3
  idEditorModelEntity *result; // r3
  idEditorModelEntity *v3; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  v1 = (idEditorModelEntity *)this->GetEntity(this);
  result = idEditorModelEntity::CastTo(c: v1);
  v3 = result;
  if ( result != nullptr )
  {
    idEntity::StopSound(this: result, channel: (const soundChannel_t)result->faceMgr.voiceChannel, peerMask: 0xFFu);
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v3);
    idFaceMgr::Reset(this: &v3->faceMgr, owner: v3, ta: TreeAnimatorFromPresentable);
    return (idEditorModelEntity *)1;
  }
  return result;
}


// ========================================================================
// ?SetRemoveOriginTranslation@idEditorModelInterface@@UAAX_N@Z
// EA  : 0x82BD8358
// RVA : 0x00BD8358
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelInterface::SetRemoveOriginTranslation(idEditorModelInterface *this, bool remove)
{
  idEditorModelEntity *v3; // r3
  idEditorModelEntity *v4; // r3

  v3 = (idEditorModelEntity *)this->GetEntity(this);
  v4 = idEditorModelEntity::CastTo(c: v3);
  if ( v4 != nullptr )
    idEditorModelEntity::SetRemoveOriginTranslation(this: v4, remove);
}


// ========================================================================
// ?GetRemoveOriginTranslation@idEditorModelInterface@@UBA_NXZ
// EA  : 0x82BD83A8
// RVA : 0x00BD83A8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

BOOL __fastcall idEditorModelInterface::GetRemoveOriginTranslation(idEditorModelInterface *this)
{
  idEditorModelEntity *v1; // r3
  idEditorModelEntity *v2; // r3

  v1 = (idEditorModelEntity *)this->GetEntity(this);
  v2 = idEditorModelEntity::CastTo(c: v1);
  return v2 != nullptr && idEditorModelEntity::GetRemoveOriginRotation(this: v2);
}


// ========================================================================
// ?SetAnimTime@idEditorModelInterface@@UAAXM@Z
// EA  : 0x82BD83F8
// RVA : 0x00BD83F8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelInterface::SetAnimTime(idEditorModelInterface *this, double timeSeconds)
{
  idEditorModelEntity *v3; // r3
  idEditorModelEntity *v4; // r3

  v3 = (idEditorModelEntity *)this->GetEntity(this);
  v4 = idEditorModelEntity::CastTo(c: v3);
  if ( v4 != nullptr )
    idEditorModelEntity::SetAnimTime(this: v4, timeSeconds);
}


// ========================================================================
// ?SetModelByName@idEditorModelEntity@@UAAXPBD@Z
// EA  : 0x82BD84D8
// RVA : 0x00BD84D8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelEntity::SetModelByName(idEditorModelEntity *this, const char *modelName)
{
  idAnimStack *p_animStackUncompressed; // r28
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v6; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r26
  const idMD6Model *model; // r24
  const idMD6Skel *skeleton; // r11
  const idMD6Anim *defaultAnim; // r27
  idAnimStack *v12; // r3
  const char *v13; // r6
  idAnimStack *v14; // r5
  idAnimStack *v15; // r3
  idGameTimeManager *v16; // r3
  int v17; // [sp+8h] [-188h]
  int v18; // [sp+Ch] [-184h]
  int v19; // [sp+10h] [-180h]
  int v20; // [sp+14h] [-17Ch]
  int v21; // [sp+18h] [-178h]
  int v22; // [sp+1Ch] [-174h]
  int v23; // [sp+20h] [-170h]
  int v24; // [sp+24h] [-16Ch]
  int v25; // [sp+28h] [-168h]
  int v26; // [sp+2Ch] [-164h]
  int v27; // [sp+30h] [-160h]
  int v28; // [sp+34h] [-15Ch]
  int v29; // [sp+38h] [-158h]
  int v30; // [sp+3Ch] [-154h]
  int v31; // [sp+40h] [-150h]
  int v32; // [sp+44h] [-14Ch]
  int v33; // [sp+48h] [-148h]
  int v34; // [sp+4Ch] [-144h]
  int v35; // [sp+50h] [-140h]
  int v36; // [sp+58h] [-138h]
  int v37; // [sp+60h] [-130h]
  int v38; // [sp+68h] [-128h]
  idAnimatorParms_Base v39; // [sp+70h] [-120h] BYREF
  idAnimatorParms_Base v40; // [sp+B0h] [-E0h] BYREF
  idAnimatorParms_Pause v41; // [sp+F0h] [-A0h] BYREF

  if ( this->uncompressedModelView != nullptr )
  {
    p_animStackUncompressed = &this->animStackUncompressed;
    idAnimator_Base::Shutdown(this: &this->basePoseAnimatorUncompressed, stack: &this->animStackUncompressed);
    idAnimator_Base::Shutdown(this: &this->proxyAnimatorUncompressed, stack: p_animStackUncompressed);
    idAnimator_Base::Shutdown(this: &this->faceAnimatorUncompressed, stack: p_animStackUncompressed);
    idAnimStack::Shutdown(this: p_animStackUncompressed);
    idMD6LeafPause::Clear(this: &this->leafPauseUncompressed);
    idMD6LeafPlay::Clear(this: &this->leafPlayUncompressed);
    idPresentable::Delete(this: this->uncompressedModelView);
    this->uncompressedModelView = nullptr;
  }
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idFaceMgr::Shutdown(this: &this->faceMgr, owner: this, ta: TreeAnimatorFromPresentable);
  idAI2::SetModelByName((idAI2 *)this, modelName);
  v6 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = v6;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    model = v8->decl->model;
    if ( model != nullptr )
    {
      skeleton = model->skeleton;
      defaultAnim = nullptr;
      if ( skeleton != nullptr )
        defaultAnim = skeleton->defaultAnim;
      v12 = this->GetAnimStack_2(this);
      idAnimatorParms_Pause::idAnimatorParms_Pause(
        this: &v41,
        anim_: defaultAnim,
        startFrame_: 0.0,
        normalizedStartFrame_: 0.0,
        animStack_: v14,
        name_: v13,
        blendOp_: v12,
        originBlend_: "basepose",
        weightGroup_: BOP_LERP,
        filterGroup_: ORIGINBLEND_BRANCH,
        alpha_: 1.0,
        a12: v17,
        a13: v18,
        a14: v19,
        a15: v20,
        a16: v21,
        a17: v22,
        a18: v23,
        a19: v24,
        a20: v25,
        a21: v26,
        a22: v27,
        a23: v28,
        a24: v29,
        a25: v30,
        a26: v31,
        a27: v32,
        a28: v33,
        a29: v34,
        a30: v35,
        a31: MD6_WEIGHTGROUP_ALL,
        a32: v36,
        a33: MD6_WEIGHTGROUP_ALL);
      idAnimator_Base::Init(this: &this->basePoseAnimator, gametimeManager: &clientGame->gameTimeManager, parms: &v41);
      v15 = this->GetAnimStack_2(this);
      idAnimator_Base::SetEnabled(this: &this->basePoseAnimator, animStack: v15, enabled: false);
      idStr::FreeData(this: &v41.name);
    }
    v39.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v39.name, text: "proxy");
    v39.alpha = 1.0;
    memset(&v39.originBlend, 0, 12);
    v39.blendOp = BOP_LERP;
    idAnimator_Base::Init(this: &this->proxyAnimator, gametimeManager: &clientGame->gameTimeManager, parms: &v39);
    idFaceMgr::Init(
      this: &this->faceMgr,
      owner: this,
      ta: v8,
      mood: MOOD_NONE,
      voiceChannel: SND_CHANNEL_VOICE,
      enableMoodAnimation: true,
      enableLipSyncAnimation: true,
      enableGestureAnimation: true,
      enableEyeTracking: v17,
      useFaceSetupEyeTracking_: v18,
      enableBlinking: v19,
      enableLidDeformation: v20,
      a13: v21,
      a14: v22,
      a15: v23,
      a16: v24,
      a17: v25,
      a18: v26,
      a19: v27,
      a20: v28,
      a21: v29,
      a22: v30,
      a23: v31,
      a24: v32,
      a25: v33,
      a26: v34,
      a27: v35,
      a28: 0,
      a29: v36,
      a30: false,
      a31: v37,
      a32: 0,
      a33: v38,
      a34: 0);
    idTreeAnimator::SetRemoveOriginRotation(this: v8, removeRotation: false);
    idTreeAnimator::SetRemoveOriginRotation(this: v8, removeRotation: false);
    if ( model != nullptr )
    {
      v40.animStack = this->GetAnimStack_2(this);
      idStr::idStr(this: &v40.name, text: "faceTracks");
      v40.alpha = 1.0;
      v40.originBlend = ORIGINBLEND_BRANCH;
      v40.blendOp = BOP_ADD_RIGHT;
      v40.weightGroup = MD6_WEIGHTGROUP_FACE;
      v40.filterGroup = MD6_WEIGHTGROUP_FACE;
      v16 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->faceAnimator, gametimeManager: v16, parms: &v40);
      idStr::FreeData(this: &v40.name);
    }
    idStr::FreeData(this: &v39.name);
  }
  this->Show(this);
  idEntity::UpdateVisuals(this);
}


// ========================================================================
// __unwind$489627
// EA  : 0x82BD87BC
// RVA : 0x00BD87BC
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_489627()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 400 + 240));
}


// ========================================================================
// __unwind$489628
// EA  : 0x82BD87E4
// RVA : 0x00BD87E4
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_489628()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$489629_0
// EA  : 0x82BD880C
// RVA : 0x00BD880C
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_489629_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 400 + 176));
}


// ========================================================================
// ?CreateEntityInterface@idEditorModelEntity@@UAAPAVidEntityInterface@@PAVidGame@@@Z
// EA  : 0x82BD8840
// RVA : 0x00BD8840
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

idEntityInterface *__fastcall idEditorModelEntity::CreateEntityInterface(idEditorModelEntity *this, idGame *game)
{
  idAnimatedEntityInterface *v4; // r3
  _DWORD *v5; // r30

  v4 = (idAnimatedEntityInterface *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x14u,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  v5 = &v4->__vftable;
  if ( v4 == nullptr )
    return nullptr;
  idAnimatedEntityInterface::idAnimatedEntityInterface(this: v4, game, ent: this);
  *v5 = &idEditorModelInterface::`vftable';
  return (idEntityInterface *)v5;
}


// ========================================================================
// __unwind$489748_0
// EA  : 0x82BD88BC
// RVA : 0x00BD88BC
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall _unwind_489748_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?Spawn@idEditorModelEntity@@QAAXXZ
// EA  : 0x82BD88F0
// RVA : 0x00BD88F0
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelEntity::Spawn(idEditorModelEntity *this)
{
  const idDecl *v2; // r3
  const idDecl *v3; // r29
  int v4; // r28
  const char *v5; // r3
  const idSoundShader *v6; // r3
  idTypeInfoTree v7; // [sp+60h] [-90h] BYREF
  idStr v8; // [sp+80h] [-70h] BYREF
  idStr v9[2]; // [sp+A0h] [-50h] BYREF

  idEntity::BecomeActive(this, flags: 1);
  this->attachments.parent = this;
  idStr::idStr(this: v9, text: modelEditor_entityDef.valueString.data);
  if ( v9[0].data != nullptr
    && (v2 = idDeclInfo::FindWithInheritance(this: &idDeclEntityDef::resourceList, name: v9[0].data, makeDefault: false),
        v3 = v2,
        v2 != nullptr) )
  {
    v4 = (int)v2->__vftable[1].GetDeclInfo(this: v2);
    v5 = (const char *)v3->__vftable[1].GetDeclTimestamp(this: (idDecl *)v3);
    idTypeInfoTree::idTypeInfoTree(this: &v7, text: v5, length: v4);
    v8.len = 0;
    v8.allocedAndFlag = 20;
    v8.data = v8.baseBuffer;
    v8.baseBuffer[0] = 0;
    idTypeInfoTree::GetStrType(this: &v7, path: "actorConstants.actorSounds.sndFootsteps", value: &v8);
    if ( v8.len != 0 )
    {
      if ( v8.data != nullptr )
        v6 = (const idSoundShader *)idDeclInfo::FindWithInheritance(
                                      this: &idSoundShader::resourceList,
                                      name: v8.data,
                                      makeDefault: false);
      else
        v6 = nullptr;
      this->sndFootsteps = v6;
    }
    idStr::FreeData(this: &v8);
    idTypeInfoTree::~idTypeInfoTree(this: &v7);
  }
  else
  {
    idLib::Warning(fmt: "Invalid entity def for the model editor: %s", modelEditor_entityDef.valueString.data);
  }
  this->baseOrigin.x = this->spawnPosition.x;
  this->baseOrigin.y = this->spawnPosition.y;
  this->baseOrigin.z = this->spawnPosition.z;
  this->baseAxis.mat[0].x = this->spawnOrientation.mat[0].x;
  this->baseAxis.mat[0].y = this->spawnOrientation.mat[0].y;
  this->baseAxis.mat[0].z = this->spawnOrientation.mat[0].z;
  this->baseAxis.mat[1].x = this->spawnOrientation.mat[1].x;
  this->baseAxis.mat[1].y = this->spawnOrientation.mat[1].y;
  this->baseAxis.mat[1].z = this->spawnOrientation.mat[1].z;
  this->baseAxis.mat[2].x = this->spawnOrientation.mat[2].x;
  this->baseAxis.mat[2].y = this->spawnOrientation.mat[2].y;
  this->baseAxis.mat[2].z = this->spawnOrientation.mat[2].z;
  idStr::FreeData(this: v9);
}


// ========================================================================
// __unwind$489934_0
// EA  : 0x82BD8AB8
// RVA : 0x00BD8AB8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_489934_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 160));
}


// ========================================================================
// __unwind$489935
// EA  : 0x82BD8AE0
// RVA : 0x00BD8AE0
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_489935()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$489936
// EA  : 0x82BD8B08
// RVA : 0x00BD8B08
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_489936()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// ?Think@idEditorModelEntity@@UAAXXZ
// EA  : 0x82BD8B30
// RVA : 0x00BD8B30
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelEntity::Think(idEditorModelEntity *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r18
  int v5; // r28
  unsigned int GameMsPerFrame; // r27
  int GameMs; // r3
  idPresentable *v8; // r11
  int v9; // r26
  idAnimStack *v10; // r3
  idMD6Leaf *leaf; // r11
  idAnimStack *v12; // r25
  const idMD6Anim *anim; // r11
  idMD6AnimData *animData; // r11
  idAnimator_Proxy *p_proxyAnimator; // r23
  idMD6Branch *v16; // r3
  idMD6Branch *v17; // r3
  idGameTimeManager *p_gameTimeManager; // r27
  idGameTimeManager *v19; // r26
  int v20; // r17
  int PreviousGameMs; // r16
  int v22; // r3
  idMD6Leaf *leafUncompressed; // r11
  const idMD6Anim *v24; // r11
  idMD6AnimData *v25; // r11
  idAnimStack *p_animStackUncompressed; // r26
  idAnimator_Proxy *p_proxyAnimatorUncompressed; // r27
  idMD6Branch *v28; // r3
  idMD6Branch *v29; // r3
  idGameTimeManager *v30; // r27
  idGameTimeManager *v31; // r21
  int v32; // r17
  int v33; // r16
  int v34; // r3
  char v35; // r23
  __int64 v36; // r11
  __int64 v37; // r8
  int v38; // r5
  int AnimatorIndex; // r3
  int v40; // r27
  idAnimator_Base *AnimatorByIndex; // r3
  int Length; // r28
  signed int v43; // r26
  int v44; // r3
  signed int LoopCount; // r30
  int v46; // r3
  __int64 v47; // r10
  int (__fastcall *GetGameMsPerRealSec)(struct idGameLocal *); // ctr
  __int64 v49; // r9
  double v50; // fp8
  idPhysics *Physics; // r3
  idPhysics *v52; // r3
  const idMD6Anim *curAnim; // r11
  idMD6AnimData *v54; // r11
  double frame; // fp0
  idPhysics *v56; // r3
  idPhysics *v57; // r3
  idVec3 *p_baseOrigin; // r4
  idPhysics *v59; // r3
  int v60; // r3
  float *p_y; // r10
  _DWORD *v62; // r11
  int i; // ctr
  idPhysics *v64; // r3
  int v65; // r3
  float v66; // r7
  float v67; // r6
  const idMat3 *v68; // r3
  const idMat3 *v69; // r3
  const idMat3 *v70; // r3
  idPhysics *v71; // r3
  float *v72; // [sp+8h] [-2B8h]
  float *v73; // [sp+8h] [-2B8h]
  float *v74; // [sp+Ch] [-2B4h]
  float *v75; // [sp+Ch] [-2B4h]
  float *v76; // [sp+10h] [-2B0h]
  float *v77; // [sp+10h] [-2B0h]
  idMat3 v78; // [sp+70h] [-250h] BYREF
  float v79; // [sp+94h] [-22Ch]
  float v80; // [sp+98h] [-228h]
  float v81; // [sp+9Ch] [-224h]
  float v82; // [sp+A0h] [-220h]
  float v83; // [sp+A4h] [-21Ch]
  float v84; // [sp+A8h] [-218h]
  float v85; // [sp+ACh] [-214h]
  float v86; // [sp+B0h] [-210h]
  idVec3 v87; // [sp+B8h] [-208h] BYREF
  idRotation v88; // [sp+D0h] [-1F0h] BYREF
  idRotation v89; // [sp+120h] [-1A0h] BYREF
  idRotation v90; // [sp+170h] [-150h] BYREF
  idMat3 v91[3]; // [sp+1C0h] [-100h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 != nullptr )
  {
    idFaceMgr::Update(this: &this->faceMgr, owner: (idAI2 *)this, ta: v4, focusPoint: &vec3_origin);
    v5 = idAccolade::Count(this: &clientGame->gameTimeManager);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v8 = this->presentable;
    v9 = GameMs;
    if ( v8 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v8 = this->presentable;
    }
    idFXManager::Update(
      this: &v8->fxManager,
      parentOrigin: &vec3_origin,
      parentAxis: &mat3_identity,
      parentVel: &vec3_origin,
      time: v9,
      gameMsPerFrame: GameMsPerFrame,
      frameNum: v5,
      fovScale: 1.0,
      depthHack: 0.0);
    v10 = this->GetAnimStack_2(this);
    leaf = this->leaf;
    v12 = v10;
    if ( leaf != nullptr
      && (anim = leaf->anim) != nullptr
      && (animData = anim->animData) != nullptr
      && (animData->flags & 1) != 0 )
    {
      idAnimator_Base::SetEnabled(this: &this->basePoseAnimator, animStack: v10, enabled: true);
      p_proxyAnimator = &this->proxyAnimator;
      v16 = this->proxyAnimator.InternalGetMergeBranch_2(this: &this->proxyAnimator);
      if ( v16 != nullptr )
        v16->op = 4;
    }
    else
    {
      idAnimator_Base::SetEnabled(this: &this->basePoseAnimator, animStack: v10, enabled: false);
      p_proxyAnimator = &this->proxyAnimator;
      v17 = this->proxyAnimator.InternalGetMergeBranch_2(this: &this->proxyAnimator);
      if ( v17 != nullptr )
        v17->op = 1;
    }
    idAnimator_Proxy::SetTree(this: p_proxyAnimator, tree: this->leaf);
    p_gameTimeManager = &clientGame->gameTimeManager;
    v19 = (idGameTimeManager *)(timeManager.gameTimePerFrame.value * timeManager.gameHz);
    v20 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v22 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAnimStack::BlendStackInternal(
      this: v12,
      currentTime: v22,
      previousTime: PreviousGameMs,
      gameMsPerFrame: v20,
      ticksPerSec: v19,
      game: p_gameTimeManager,
      parallelJobList: nullptr,
      localR: nullptr,
      localS: v72,
      localT: v74,
      localU: v76);
    if ( this->uncompressedModelView != nullptr )
    {
      leafUncompressed = this->leafUncompressed;
      if ( leafUncompressed != nullptr
        && (v24 = leafUncompressed->anim) != nullptr
        && (v25 = v24->animData) != nullptr
        && (v25->flags & 1) != 0 )
      {
        p_animStackUncompressed = &this->animStackUncompressed;
        idAnimator_Base::SetEnabled(
          this: &this->basePoseAnimatorUncompressed,
          animStack: &this->animStackUncompressed,
          enabled: true);
        p_proxyAnimatorUncompressed = &this->proxyAnimatorUncompressed;
        v28 = this->proxyAnimatorUncompressed.InternalGetMergeBranch_2(this: &this->proxyAnimatorUncompressed);
        if ( v28 != nullptr )
          v28->op = 4;
      }
      else
      {
        p_animStackUncompressed = &this->animStackUncompressed;
        idAnimator_Base::SetEnabled(
          this: &this->basePoseAnimatorUncompressed,
          animStack: &this->animStackUncompressed,
          enabled: false);
        p_proxyAnimatorUncompressed = &this->proxyAnimatorUncompressed;
        v29 = this->proxyAnimatorUncompressed.InternalGetMergeBranch_2(this: &this->proxyAnimatorUncompressed);
        if ( v29 != nullptr )
          v29->op = 1;
      }
      idAnimator_Proxy::SetTree(this: p_proxyAnimatorUncompressed, tree: this->leafUncompressed);
      v30 = &clientGame->gameTimeManager;
      v31 = (idGameTimeManager *)(timeManager.gameTimePerFrame.value * timeManager.gameHz);
      v32 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v33 = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v34 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idAnimStack::BlendStackInternal(
        this: p_animStackUncompressed,
        currentTime: v34,
        previousTime: v33,
        gameMsPerFrame: v32,
        ticksPerSec: v31,
        game: v30,
        parallelJobList: nullptr,
        localR: nullptr,
        localS: v73,
        localT: v75,
        localU: v77);
    }
    idAnimatedEntity::UpdateFrameCommands(this);
    this->UpdateAttachments(this);
    idEntity::UpdateVisuals(this);
    AnimatorIndex = idAnimStack::GetAnimatorIndex(this: v12, animator: p_proxyAnimator);
    v35 = 0;
    if ( AnimatorIndex >= 0 )
    {
      v40 = AnimatorIndex + 1;
      v35 = 1;
      if ( AnimatorIndex + 1 < v12->blendStack.num )
      {
        while ( 1 )
        {
          if ( idAnimStack::GetAnimatorByIndex(this: v12, index: v40) != &this->faceAnimator )
          {
            AnimatorByIndex = idAnimStack::GetAnimatorByIndex(this: v12, index: v40);
            if ( idAnimator_Base::IsContributing(this: AnimatorByIndex) )
              break;
          }
          if ( ++v40 >= v12->blendStack.num )
            goto LABEL_31;
        }
        v35 = 0;
      }
    }
LABEL_31:
    if ( v35 != 0 )
    {
      if ( this->leaf == &this->leafPlay )
      {
        Length = idMD6Leaf::GetLength(
                   this: &this->leafPlay,
                   ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                   a3: v38,
                   a4: v37);
        v43 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        v44 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LoopCount = idMD6LeafPlay::GetLoopCount(this: &this->leafPlay, gameTime: v44, ticksPerSec: v43);
        v46 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        HIDWORD(v47) = &idEventDef::eventDefList[3154];
        LODWORD(v47) = v46 - LoopCount * Length - this->leafPlay.startTime;
        GetGameMsPerRealSec = gameLocal->GetGameMsPerRealSec;
        *(_QWORD *)&v78.mat[0].x = v47;
        LODWORD(v49) = GetGameMsPerRealSec(this: gameLocal);
        HIDWORD(v49) = this->lastLoopCount;
        v50 = (float)((float)*(__int64 *)&v78.mat[0].x / (float)v49);
        *(_QWORD *)&v78.mat[0].x = v49;
        this->caretTime = v50;
        if ( SHIDWORD(v49) < LoopCount )
        {
          this->lastLoopCount = LoopCount;
          Physics = idEntity::GetPhysics(this);
          Physics->SetOrigin(this: Physics, a2: &this->baseOrigin, a3: -1);
          v52 = idEntity::GetPhysics(this);
          v52->SetAxis(this: v52, a2: &this->baseAxis, a3: -1);
          if ( !this->cycle )
          {
            this->leaf = nullptr;
            idMD6LeafPlay::Clear(this: &this->leafPlay);
          }
        }
      }
      else
      {
        curAnim = this->curAnim;
        if ( curAnim != nullptr )
        {
          v54 = curAnim->animData;
          frame = this->leafPause.frame;
          if ( v54 != nullptr )
            LODWORD(v36) = v54->frameRate;
          else
            LODWORD(v36) = 30;
          *(_QWORD *)&v78.mat[0].x = v36;
          this->caretTime = (float)frame / (float)v36;
        }
        else
        {
          this->caretTime = 0.0;
        }
      }
    }
    if ( idTreeAnimator::GetRemoveOriginTranslation(ptr: v4) )
    {
      idTreeAnimator::GetLastOriginDeltas(this: v4, rot: v91, trans: &v87);
      v59 = idEntity::GetPhysics(this);
      v60 = (int)v59->GetAxis(this: v59, a2: 0);
      p_y = &v78.mat[2].y;
      v62 = (_DWORD *)(v60 - 4);
      for ( i = 9; i != 0; --i )
        *++p_y = *(float *)++v62;
      v64 = idEntity::GetPhysics(this);
      v65 = (int)v64->GetOrigin(this: v64, a2: 0);
      v66 = *(float *)(v65 + 4);
      v67 = *(float *)(v65 + 8);
      v78.mat[1].y = *(float *)v65;
      v78.mat[1].z = v66;
      v78.mat[2].x = v67;
      idMat3::ToAngles(this: &v78, result: (idAngles *)v91);
      v88.origin.x = vec3_origin.x;
      v88.axisValid = false;
      v88.origin.y = vec3_origin.y;
      v88.origin.z = vec3_origin.z;
      v88.vec.x = v81;
      v88.vec.y = v82;
      v88.axis.mat[0].x = mat3_identity.mat[0].x;
      v88.vec.z = v83;
      v88.axis.mat[0].y = mat3_identity.mat[0].y;
      v88.axis.mat[0].z = mat3_identity.mat[0].z;
      v88.axis.mat[1].y = mat3_identity.mat[1].y;
      v88.axis.mat[1].z = mat3_identity.mat[1].z;
      v88.axis.mat[1].x = mat3_identity.mat[1].x;
      v88.angle = v78.mat[0].x;
      v88.axis.mat[2].x = mat3_identity.mat[2].x;
      v88.axis.mat[2].y = mat3_identity.mat[2].y;
      v88.axis.mat[2].z = mat3_identity.mat[2].z;
      v78.mat[1].y = (float)((float)(v78.mat[2].z * v87.x) + (float)((float)(v81 * v87.y) + (float)(v84 * v87.z)))
                   + v78.mat[1].y;
      v78.mat[1].z = v78.mat[1].z + (float)((float)(v79 * v87.x) + (float)((float)(v82 * v87.y) + (float)(v85 * v87.z)));
      v78.mat[2].x = v78.mat[2].x + (float)((float)(v87.z * v86) + (float)((float)(v83 * v87.y) + (float)(v80 * v87.x)));
      v68 = idRotation::ToMat3(this: &v88);
      idMat3::operator*=(this: (idMat3 *)&v78.mat[2].z, a: v68);
      v89.axisValid = false;
      v89.origin.x = vec3_origin.x;
      v89.origin.y = vec3_origin.y;
      v89.origin.z = vec3_origin.z;
      v89.axis.mat[0].x = mat3_identity.mat[0].x;
      v89.axis.mat[0].y = mat3_identity.mat[0].y;
      v89.axis.mat[0].z = mat3_identity.mat[0].z;
      v89.axis.mat[1].x = mat3_identity.mat[1].x;
      v89.axis.mat[1].y = mat3_identity.mat[1].y;
      v89.vec.x = v84;
      v89.vec.y = v85;
      v89.vec.z = v86;
      v89.angle = v78.mat[0].y;
      v89.axis.mat[1].z = mat3_identity.mat[1].z;
      v89.axis.mat[2].x = mat3_identity.mat[2].x;
      v89.axis.mat[2].y = mat3_identity.mat[2].y;
      v89.axis.mat[2].z = mat3_identity.mat[2].z;
      v69 = idRotation::ToMat3(this: &v89);
      idMat3::operator*=(this: (idMat3 *)&v78.mat[2].z, a: v69);
      v90.axisValid = false;
      v90.axis.mat[0].y = mat3_identity.mat[0].y;
      v90.axis.mat[0].z = mat3_identity.mat[0].z;
      v90.axis.mat[1].x = mat3_identity.mat[1].x;
      v90.axis.mat[1].y = mat3_identity.mat[1].y;
      v90.origin.x = vec3_origin.x;
      v90.origin.y = vec3_origin.y;
      v90.origin.z = vec3_origin.z;
      v90.axis.mat[0].x = mat3_identity.mat[0].x;
      v90.vec.x = v78.mat[2].z;
      v90.vec.y = v79;
      v90.vec.z = v80;
      v90.angle = v78.mat[0].z;
      v90.axis.mat[1].z = mat3_identity.mat[1].z;
      v90.axis.mat[2].x = mat3_identity.mat[2].x;
      v90.axis.mat[2].y = mat3_identity.mat[2].y;
      v90.axis.mat[2].z = mat3_identity.mat[2].z;
      v70 = idRotation::ToMat3(this: &v90);
      idMat3::operator*=(this: (idMat3 *)&v78.mat[2].z, a: v70);
      v71 = idEntity::GetPhysics(this);
      v71->SetAxis(this: v71, a2: (idMat3 *)&v78.mat[2].z, a3: -1);
      v57 = idEntity::GetPhysics(this);
      p_baseOrigin = (idVec3 *)&v78.mat[1].y;
    }
    else
    {
      v56 = idEntity::GetPhysics(this);
      v56->SetAxis(this: v56, a2: &this->baseAxis, a3: -1);
      v57 = idEntity::GetPhysics(this);
      p_baseOrigin = &this->baseOrigin;
    }
    v57->SetOrigin(this: v57, a2: p_baseOrigin, a3: -1);
  }
  idEntity::RunPhysics(this);
  idEditorModelEntity::UpdateUncompressedTransform(this);
}


// ========================================================================
// ?ShowUncompressed@idEditorModelEntity@@QAAX_N@Z
// EA  : 0x82BD9448
// RVA : 0x00BD9448
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelEntity::ShowUncompressed(idEditorModelEntity *this, const bool showUncompressed)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int numFrames; // r28
  const idDeclMD6 *decl; // r11
  const char *str; // r4
  idTreeAnimator *v7; // r29
  idTreeAnimator *v8; // r26
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  idPresentableAnimatedEntity *v13; // r3
  idPresentableAnimatedEntity *v14; // r4
  const char *v15; // r6
  idAnimStack *v16; // r5
  const idMD6Anim *defaultAnim; // r4
  const idMD6Skel *skeleton; // r11
  idGameTimeManager *v19; // r3
  idPhysics *Physics; // r3
  float *v21; // r3
  idPresentableAnimatedEntity *uncompressedModelView; // r11
  idPhysics *v23; // r3
  float *v24; // r3
  float *v25; // r11
  idPhysics *v26; // r3
  idPhysics *v27; // r3
  const idMD6Anim *curAnim; // r11
  const idMD6Anim *v29; // r3
  idMD6AnimData *animData; // r11
  signed int frameRate; // r29
  int v32; // r3
  idGameLocal *v33; // r11
  int v34; // r8
  int (__fastcall *GetGameMsPerRealSec)(struct idGameLocal *); // ctr
  signed int v36; // r28
  __int64 v37; // r3
  double caretTime; // fp0
  const idMD6Anim *curAnimUncompressed; // r11
  idMD6AnimData *v40; // r11
  int v41; // r9
  int v42; // r29
  int v43; // r28
  signed int v44; // r3
  idClientGame *v45; // r11
  int gameHz; // r9
  unsigned int v47; // r7
  int value; // r10
  int v49; // r28
  int v50; // r27
  int GameMs; // r3
  idMD6Leaf::wrapMode_t v52; // r8
  idMD6Leaf *leaf; // r5
  int v54; // [sp+8h] [-1D8h]
  int v55; // [sp+8h] [-1D8h]
  int v56; // [sp+Ch] [-1D4h]
  int v57; // [sp+Ch] [-1D4h]
  int v58; // [sp+10h] [-1D0h]
  int v59; // [sp+10h] [-1D0h]
  int v60; // [sp+14h] [-1CCh]
  int v61; // [sp+14h] [-1CCh]
  int v62; // [sp+18h] [-1C8h]
  int v63; // [sp+18h] [-1C8h]
  idPresentable *v64; // [sp+1Ch] [-1C4h]
  int v65; // [sp+1Ch] [-1C4h]
  int v66; // [sp+20h] [-1C0h]
  int v67; // [sp+24h] [-1BCh]
  int v68; // [sp+28h] [-1B8h]
  int v69; // [sp+2Ch] [-1B4h]
  int v70; // [sp+30h] [-1B0h]
  int v71; // [sp+34h] [-1ACh]
  int v72; // [sp+38h] [-1A8h]
  int v73; // [sp+3Ch] [-1A4h]
  int v74; // [sp+40h] [-1A0h]
  int v75; // [sp+44h] [-19Ch]
  int v76; // [sp+48h] [-198h]
  int v77; // [sp+4Ch] [-194h]
  int v78; // [sp+50h] [-190h]
  int v79; // [sp+58h] [-188h]
  idAnimatorParms_Base v80; // [sp+80h] [-160h] BYREF
  idAnimatorParms_Base v81; // [sp+C0h] [-120h] BYREF
  idStr v82; // [sp+100h] [-E0h] BYREF
  idStr v83; // [sp+120h] [-C0h] BYREF
  idAnimatorParms_Pause v84; // [sp+140h] [-A0h] BYREF

  if ( showUncompressed )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    numFrames = 0;
    if ( this->uncompressedModelView == nullptr && TreeAnimatorFromPresentable != nullptr )
    {
      decl = TreeAnimatorFromPresentable->decl;
      if ( decl != nullptr )
        str = decl->name.str;
      else
        str = &byte_8200D768;
      v7 = (idTreeAnimator *)clientGame->renderWorld->AllocRenderModel(
                               this: clientGame->renderWorld,
                               a2: str,
                               a3: 0,
                               a4: -1);
      v8 = (idTreeAnimator *)_RTDynamicCast(
                               inptr: v7,
                               VfDelta: 0,
                               SrcType: &idRenderModel `RTTI Type Descriptor',
                               TargetType: &idTreeAnimator `RTTI Type Descriptor',
                               isReference: 0);
      if ( v8 != nullptr )
      {
        v13 = (idPresentableAnimatedEntity *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                               size: 0x4E0u,
                                               tag: TAG_PRESENTABLE,
                                               zeroBuffer: false,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
        if ( v13 != nullptr )
          v14 = idPresentableAnimatedEntity::idPresentableAnimatedEntity(
                  this: v13,
                  ent: nullptr,
                  renderModel_: v7,
                  animStack_: nullptr,
                  entityNumber_: 0x1FFF,
                  fxDecl_: nullptr,
                  useSphereModel_: false);
        else
          v14 = nullptr;
        this->uncompressedModelView = v14;
        idClientGame::AddPresentable(
          this: clientGame,
          presentable: v14,
          index: -1,
          skipReplication: false,
          a5: v12,
          a6: v11,
          a7: v10,
          a8: v9,
          a9: v54,
          a10: v56,
          a11: v58,
          a12: v60,
          a13: v62,
          a14: v64);
        idAnimStack::Init(this: &this->animStackUncompressed, treeAnimator: v8);
        defaultAnim = nullptr;
        skeleton = v8->decl->model->skeleton;
        if ( skeleton != nullptr )
          defaultAnim = skeleton->defaultAnim;
        idAnimatorParms_Pause::idAnimatorParms_Pause(
          this: &v84,
          anim_: defaultAnim,
          startFrame_: 0.0,
          normalizedStartFrame_: 0.0,
          animStack_: v16,
          name_: v15,
          blendOp_: &this->animStackUncompressed,
          originBlend_: "basepose",
          weightGroup_: BOP_LERP,
          filterGroup_: ORIGINBLEND_BRANCH,
          alpha_: 1.0,
          a12: v55,
          a13: v57,
          a14: v59,
          a15: v61,
          a16: v63,
          a17: v65,
          a18: v66,
          a19: v67,
          a20: v68,
          a21: v69,
          a22: v70,
          a23: v71,
          a24: v72,
          a25: v73,
          a26: v74,
          a27: v75,
          a28: v76,
          a29: v77,
          a30: v78,
          a31: MD6_WEIGHTGROUP_ALL,
          a32: v79,
          a33: MD6_WEIGHTGROUP_ALL);
        idAnimator_Base::Init(
          this: &this->basePoseAnimatorUncompressed,
          gametimeManager: &clientGame->gameTimeManager,
          parms: &v84);
        idAnimator_Base::SetEnabled(
          this: &this->basePoseAnimatorUncompressed,
          animStack: &this->animStackUncompressed,
          enabled: false);
        v80.animStack = &this->animStackUncompressed;
        idStr::idStr(this: &v80.name, text: "proxy");
        v80.alpha = 1.0;
        memset(&v80.originBlend, 0, 12);
        v80.blendOp = BOP_LERP;
        idAnimator_Base::Init(
          this: &this->proxyAnimatorUncompressed,
          gametimeManager: &clientGame->gameTimeManager,
          parms: &v80);
        idTreeAnimator::SetRemoveOriginRotation(this: v8, removeRotation: false);
        idTreeAnimator::SetRemoveOriginRotation(this: v8, removeRotation: false);
        v81.animStack = &this->animStackUncompressed;
        idStr::idStr(this: &v81.name, text: "faceTracks");
        v81.alpha = 1.0;
        v81.originBlend = ORIGINBLEND_BRANCH;
        v81.blendOp = BOP_ADD_RIGHT;
        v81.weightGroup = MD6_WEIGHTGROUP_FACE;
        v81.filterGroup = MD6_WEIGHTGROUP_FACE;
        v19 = gameLocal->GetGameTimeManager(this: gameLocal);
        idAnimator_Base::Init(this: &this->faceAnimatorUncompressed, gametimeManager: v19, parms: &v81);
        Physics = idEntity::GetPhysics(this);
        v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        uncompressedModelView = this->uncompressedModelView;
        uncompressedModelView->origin.x = *v21;
        uncompressedModelView->origin.y = v21[1];
        uncompressedModelView->origin.z = v21[2];
        v23 = idEntity::GetPhysics(this);
        v24 = (float *)v23->GetAxis(this: v23, a2: 0);
        v25 = (float *)this->uncompressedModelView;
        v25[33] = *v24;
        v25[34] = v24[1];
        v25[35] = v24[2];
        v25[36] = v24[3];
        v25[37] = v24[4];
        v25[38] = v24[5];
        v25[39] = v24[6];
        v25[40] = v24[7];
        v25[41] = v24[8];
        this->uncompressedModelView->Present(this: this->uncompressedModelView);
        v26 = idEntity::GetPhysics(this);
        v26->SetOrigin(this: v26, a2: &this->baseOrigin, a3: -1);
        v27 = idEntity::GetPhysics(this);
        v27->SetAxis(this: v27, a2: &this->baseAxis, a3: -1);
        idStr::FreeData(this: &v81.name);
        idStr::FreeData(this: &v80.name);
        idStr::FreeData(this: &v84.name);
      }
      else if ( v7 != nullptr )
      {
        v7->unlinked = true;
        v7->deleteOnSync = true;
        idRenderModel::CommitThisFrame(this: v7);
      }
    }
    if ( this->uncompressedModelView != nullptr )
    {
      curAnim = this->curAnim;
      if ( curAnim != nullptr )
      {
        idStr::idStr(this: &v82, text: curAnim->name.str);
        idStr::StripPath(this: &v82);
        if ( idStr::Cmp(s1: v82.data, s2: idMD6Model::DEFAULT_ANIM_NAME) != 0 )
        {
          idStr::idStr(this: &v83, text: this->curAnim->name.str);
          idStr::Replace(this: &v83, old: ".md6anim", nw: idMD6Anim::UNCOMPRESSED_ANIM_NAME);
          v29 = (const idMD6Anim *)idResourceList::Load(
                                     this: &idMD6Anim::resourceList,
                                     name: v83.data,
                                     makeDefault: true,
                                     skipStaleCheck: true);
          this->curAnimUncompressed = v29;
          if ( v29 != nullptr )
          {
            animData = v29->animData;
            if ( animData != nullptr )
            {
              numFrames = animData->numFrames;
              frameRate = animData->frameRate;
            }
            else
            {
              frameRate = 30;
            }
            v32 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
            v33 = gameLocal;
            __twllei(frameRate, 0);
            v34 = v32 * (numFrames - 1);
            GetGameMsPerRealSec = v33->GetGameMsPerRealSec;
            v36 = v34 / frameRate;
            __twlgei(frameRate & ~(__ROL4__(v34, 1) - 1), 0xFFFFFFFF);
            LODWORD(v37) = GetGameMsPerRealSec(this: v33);
            caretTime = this->caretTime;
            curAnimUncompressed = this->curAnimUncompressed;
            __twllei(v36, 0);
            v40 = curAnimUncompressed->animData;
            v41 = (int)(float)((float)v37 * (float)caretTime);
            v42 = v41 % v36;
            __twlgei(v36 & ~(__ROL4__(v41, 1) - 1), 0xFFFFFFFF);
            v43 = 30;
            if ( v40 != nullptr )
              v43 = v40->frameRate;
            v44 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
            v45 = clientGame;
            gameHz = timeManager.gameHz;
            v47 = v44 & ~(__ROL4__(v43 * v42, 1) - 1);
            value = timeManager.gameTimePerFrame.value;
            v49 = v43 * v42 / v44;
            __twllei(v44, 0);
            __twlgei(v47, 0xFFFFFFFF);
            v50 = value * gameHz;
            GameMs = idGameTimeManager::GetGameMs(this: &v45->gameTimeManager, type: GAMETIME_SCALED);
            idMD6LeafPlay::Init(
              this: &this->leafPlayUncompressed,
              anim: this->curAnimUncompressed,
              gameTime: GameMs,
              ticksPerSec: v50,
              frame: v49,
              rateScale: 1.0,
              wrapMode: v52,
              weightGroup: MD6_WEIGHTGROUP_LEGS,
              a9: 0);
            leaf = this->leaf;
            this->leafUncompressed = &this->leafPlayUncompressed;
            if ( leaf == &this->leafPause )
            {
              idMD6LeafPause::Init(
                this: &this->leafPauseUncompressed,
                anim: this->curAnimUncompressed,
                frame: this->leafPause.frame,
                wrapMode: (const idMD6Leaf::wrapMode_t)leaf,
                weightGroup: MD6_WEIGHTGROUP_LEGS,
                a6: 0);
              this->leafUncompressed = &this->leafPauseUncompressed;
            }
          }
          idStr::FreeData(this: &v83);
        }
        idStr::FreeData(this: &v82);
      }
    }
  }
  else if ( this->uncompressedModelView != nullptr )
  {
    idAnimator_Base::Shutdown(this: &this->basePoseAnimatorUncompressed, stack: &this->animStackUncompressed);
    idAnimator_Base::Shutdown(this: &this->proxyAnimatorUncompressed, stack: &this->animStackUncompressed);
    idAnimator_Base::Shutdown(this: &this->faceAnimatorUncompressed, stack: &this->animStackUncompressed);
    idAnimStack::Shutdown(this: &this->animStackUncompressed);
    idMD6LeafPause::Clear(this: &this->leafPauseUncompressed);
    idMD6LeafPlay::Clear(this: &this->leafPlayUncompressed);
    idPresentable::Delete(this: this->uncompressedModelView);
    this->uncompressedModelView = nullptr;
  }
}


// ========================================================================
// __unwind$490746_0
// EA  : 0x82BD9A90
// RVA : 0x00BD9A90
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_490746_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 480 + 112), tag: TAG_PRESENTABLE);
}


// ========================================================================
// __unwind$490747_0
// EA  : 0x82BD9ABC
// RVA : 0x00BD9ABC
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_490747_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 480 + 320));
}


// ========================================================================
// __unwind$490748_0
// EA  : 0x82BD9AE4
// RVA : 0x00BD9AE4
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_490748_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 480 + 128));
}


// ========================================================================
// __unwind$490749_0
// EA  : 0x82BD9B0C
// RVA : 0x00BD9B0C
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_490749_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 480 + 192));
}


// ========================================================================
// __unwind$490750_0
// EA  : 0x82BD9B34
// RVA : 0x00BD9B34
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_490750_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 256));
}


// ========================================================================
// __unwind$490751_0
// EA  : 0x82BD9B5C
// RVA : 0x00BD9B5C
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_490751_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 288));
}


// ========================================================================
// ?GetCurrentAnimFrame@idEditorModelEntity@@QBAHXZ
// EA  : 0x82BD9B88
// RVA : 0x00BD9B88
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

int __fastcall idEditorModelEntity::GetCurrentAnimFrame(idEditorModelEntity *this)
{
  idMD6LeafPlay *p_leafPlay; // r31
  signed int v2; // r30
  int GameMs; // r3
  __int64 v4; // r10
  int v5; // r8
  int v6; // r7
  int v7; // r6
  __int64 v8; // r6

  p_leafPlay = &this->leafPlay;
  if ( this->leaf == &this->leafPlay )
  {
    v2 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v8) = (unsigned __int16)idMD6LeafPlay::GetFrame(
                                      this: p_leafPlay,
                                      gameTime: GameMs,
                                      ticksPerSec: v2,
                                      a4: v7,
                                      a5: v6,
                                      a6: v5,
                                      a7: v4);
    return (int)(float)v8;
  }
  else
  {
    return (int)this->leafPause.frame;
  }
}


// ========================================================================
// ?IsAnimPlaying@idEditorModelEntity@@QBA_NXZ
// EA  : 0x82BD9C28
// RVA : 0x00BD9C28
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

int __fastcall idEditorModelEntity::IsAnimPlaying(idEditorModelEntity *this)
{
  idMD6LeafPlay *p_leafPlay; // r31
  int v2; // r30
  int GameMs; // r3
  __int64 v4; // r10
  int v5; // r8
  int v6; // r7
  int v7; // r6
  bool IsPlaying; // r3
  unsigned __int8 v9; // r11

  p_leafPlay = &this->leafPlay;
  if ( this->leaf != &this->leafPlay )
    return 0;
  v2 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  IsPlaying = idMD6LeafPlay::IsPlaying(
                this: p_leafPlay,
                gameTime: GameMs,
                ticksPerSec: v2,
                a4: v7,
                a5: v6,
                a6: v5,
                a7: v4);
  v9 = 1;
  if ( !IsPlaying )
    return 0;
  return v9;
}


// ========================================================================
// ?IsAnimPlaying@idEditorModelInterface@@UBA_NXZ
// EA  : 0x82BD9CB8
// RVA : 0x00BD9CB8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

int __fastcall idEditorModelInterface::IsAnimPlaying(idEditorModelInterface *this)
{
  idEditorModelEntity *v1; // r3
  idEditorModelEntity *v2; // r3

  v1 = (idEditorModelEntity *)this->GetEntity(this);
  v2 = idEditorModelEntity::CastTo(c: v1);
  if ( v2 != nullptr )
    return idEditorModelEntity::IsAnimPlaying(this: v2);
  else
    return 0;
}


// ========================================================================
// ?ShowUncompressed@idEditorModelInterface@@UAAX_N@Z
// EA  : 0x82BD9D08
// RVA : 0x00BD9D08
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelInterface::ShowUncompressed(idEditorModelInterface *this, bool showUncompressed)
{
  idEditorModelEntity *v3; // r3
  idEditorModelEntity *v4; // r3

  v3 = (idEditorModelEntity *)this->GetEntity(this);
  v4 = idEditorModelEntity::CastTo(c: v3);
  if ( v4 != nullptr )
    idEditorModelEntity::ShowUncompressed(this: v4, showUncompressed);
}


// ========================================================================
// ?GetCurrentAnimFrame@idEditorModelInterface@@UBAHXZ
// EA  : 0x82BD9D58
// RVA : 0x00BD9D58
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

int __fastcall idEditorModelInterface::GetCurrentAnimFrame(idEditorModelInterface *this)
{
  idEditorModelEntity *v1; // r3
  idEditorModelEntity *v2; // r3

  v1 = (idEditorModelEntity *)this->GetEntity(this);
  v2 = idEditorModelEntity::CastTo(c: v1);
  if ( v2 != nullptr )
    return idEditorModelEntity::GetCurrentAnimFrame(this: v2);
  else
    return 0;
}


// ========================================================================
// ?PlayAnim@idEditorModelEntity@@QAA_NPBVidMD6Anim@@_N@Z
// EA  : 0x82BD9DA8
// RVA : 0x00BD9DA8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

int __fastcall idEditorModelEntity::PlayAnim(idEditorModelEntity *this, const idMD6Anim *anim, bool cycle)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r30
  int numFrames; // r28
  idMD6AnimData *animData; // r11
  signed int frameRate; // r29
  int v13; // r3
  idGameLocal *v14; // r11
  int v15; // r8
  int (__fastcall *GetGameMsPerRealSec)(struct idGameLocal *); // ctr
  signed int v17; // r28
  __int64 v18; // r3
  double caretTime; // fp0
  idMD6AnimData *v20; // r11
  int v21; // r26
  int v22; // r9
  unsigned int v23; // r5
  int v24; // r28
  int v25; // r3
  int gameHz; // r9
  unsigned int v27; // r6
  int value; // r10
  unsigned int v29; // r7
  idGameTimeManager *p_gameTimeManager; // r3
  int v31; // r24
  int v32; // r23
  int GameMs; // r3
  idMD6Leaf::wrapMode_t v34; // r8
  signed int v35; // r29
  int v36; // r3
  idPhysics *Physics; // r3
  idPhysics *v38; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 == nullptr || anim == nullptr )
    return 0;
  this->curAnim = anim;
  numFrames = 0;
  this->cycle = cycle;
  animData = anim->animData;
  if ( animData != nullptr )
  {
    numFrames = animData->numFrames;
    frameRate = animData->frameRate;
  }
  else
  {
    frameRate = 30;
  }
  v13 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
  v14 = gameLocal;
  __twllei(frameRate, 0);
  v15 = v13 * (numFrames - 1);
  GetGameMsPerRealSec = v14->GetGameMsPerRealSec;
  v17 = v15 / frameRate;
  __twlgei(frameRate & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
  LODWORD(v18) = GetGameMsPerRealSec(this: v14);
  caretTime = this->caretTime;
  v20 = anim->animData;
  __twllei(v17, 0);
  v21 = 30;
  v22 = (int)(float)((float)v18 * (float)caretTime);
  v23 = v17 & ~(__ROL4__(v22, 1) - 1);
  v24 = v22 % v17;
  __twlgei(v23, 0xFFFFFFFF);
  if ( v20 != nullptr )
    v21 = v20->frameRate;
  v25 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
  gameHz = timeManager.gameHz;
  v27 = v25;
  value = timeManager.gameTimePerFrame.value;
  v29 = v25 & ~(__ROL4__(v21 * v24, 1) - 1);
  v31 = v21 * v24 / v25;
  p_gameTimeManager = &clientGame->gameTimeManager;
  __twllei(v27, 0);
  __twlgei(v29, 0xFFFFFFFF);
  v32 = value * gameHz;
  GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
  idMD6LeafPlay::Init(
    this: &this->leafPlay,
    anim,
    gameTime: GameMs,
    ticksPerSec: v32,
    frame: v31,
    rateScale: 1.0,
    wrapMode: v34,
    weightGroup: MD6_WEIGHTGROUP_LEGS,
    a9: 0);
  this->leaf = &this->leafPlay;
  v35 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  v36 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->lastLoopCount = idMD6LeafPlay::GetLoopCount(this: &this->leafPlay, gameTime: v36, ticksPerSec: v35);
  Physics = idEntity::GetPhysics(this);
  Physics->SetOrigin(this: Physics, a2: &this->baseOrigin, a3: -1);
  v38 = idEntity::GetPhysics(this);
  v38->SetAxis(this: v38, a2: &this->baseAxis, a3: -1);
  if ( this->uncompressedModelView != nullptr )
    idEditorModelEntity::ShowUncompressed(this, showUncompressed: true);
  return 1;
}


// ========================================================================
// ?PlayAnim@idEditorModelInterface@@UAA_NPBVidMD6Anim@@_N@Z
// EA  : 0x82BDA008
// RVA : 0x00BDA008
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

idEditorModelEntity *__fastcall idEditorModelInterface::PlayAnim(
        idEditorModelInterface *this,
        const idMD6Anim *anim,
        bool cycle)
{
  idEditorModelEntity *v5; // r3
  idEditorModelEntity *result; // r3

  v5 = (idEditorModelEntity *)this->GetEntity(this);
  result = idEditorModelEntity::CastTo(c: v5);
  if ( result != nullptr )
    return (idEditorModelEntity *)idEditorModelEntity::PlayAnim(this: result, anim, cycle);
  return result;
}


// ========================================================================
// ??1idEditorModelEntity@@UAA@XZ
// EA  : 0x82BDA070
// RVA : 0x00BDA070
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __fastcall idEditorModelEntity::~idEditorModelEntity(idEditorModelEntity *this)
{
  idFaceMgr *p_faceMgr; // r28
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  this->__vftable = (idEditorModelEntity_vtbl *)&idEditorModelEntity::`vftable';
  p_faceMgr = &this->faceMgr;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idFaceMgr::Shutdown(this: p_faceMgr, owner: this, ta: TreeAnimatorFromPresentable);
  idAttachmentCollection::FreeAttachments(this: &this->attachments);
  if ( this->uncompressedModelView != nullptr )
  {
    idAnimStack::Shutdown(this: &this->animStackUncompressed);
    idPresentable::Delete(this: this->uncompressedModelView);
    this->uncompressedModelView = nullptr;
  }
  idMD6LeafPause::~idMD6LeafPause(this: &this->leafPauseUncompressed);
  idMD6LeafPause::~idMD6LeafPause(this: &this->leafPause);
  idFaceMgr::~idFaceMgr(this: p_faceMgr);
  idAnimator_Paused::~idAnimator_Paused(this: &this->basePoseAnimatorUncompressed);
  idAnimator_FaceTracks::~idAnimator_FaceTracks(this: &this->faceAnimatorUncompressed);
  idAnimator_Proxy::~idAnimator_Proxy(this: &this->proxyAnimatorUncompressed);
  idAnimStack::~idAnimStack(this: &this->animStackUncompressed);
  idAnimator_Paused::~idAnimator_Paused(this: &this->basePoseAnimator);
  idAnimator_FaceTracks::~idAnimator_FaceTracks(this: &this->faceAnimator);
  idAnimator_Proxy::~idAnimator_Proxy(this: &this->proxyAnimator);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachments);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$491615
// EA  : 0x82BDA148
// RVA : 0x00BDA148
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491615()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$491616
// EA  : 0x82BDA170
// RVA : 0x00BDA170
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491616()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5200));
}


// ========================================================================
// __unwind$491617
// EA  : 0x82BDA19C
// RVA : 0x00BDA19C
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491617()
{
  int v0; // r12

  idAnimator_Proxy::~idAnimator_Proxy(this: (idAnimator_Proxy *)(*(_DWORD *)(v0 - 128 + 148) + 5236));
}


// ========================================================================
// __unwind$491618
// EA  : 0x82BDA1C8
// RVA : 0x00BDA1C8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491618()
{
  int v0; // r12

  idAnimator_FaceTracks::~idAnimator_FaceTracks(this: (idAnimator_FaceTracks *)(*(_DWORD *)(v0 - 128 + 148) + 5280));
}


// ========================================================================
// __unwind$491619
// EA  : 0x82BDA1F4
// RVA : 0x00BDA1F4
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491619()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 128 + 148) + 5420));
}


// ========================================================================
// __unwind$491620
// EA  : 0x82BDA220
// RVA : 0x00BDA220
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491620()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 128 + 148) + 5472));
}


// ========================================================================
// __unwind$491621
// EA  : 0x82BDA24C
// RVA : 0x00BDA24C
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491621()
{
  int v0; // r12

  idAnimator_Proxy::~idAnimator_Proxy(this: (idAnimator_Proxy *)(*(_DWORD *)(v0 - 128 + 148) + 7044));
}


// ========================================================================
// __unwind$491622
// EA  : 0x82BDA278
// RVA : 0x00BDA278
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491622()
{
  int v0; // r12

  idAnimator_FaceTracks::~idAnimator_FaceTracks(this: (idAnimator_FaceTracks *)(*(_DWORD *)(v0 - 128 + 148) + 7088));
}


// ========================================================================
// __unwind$491623
// EA  : 0x82BDA2A4
// RVA : 0x00BDA2A4
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491623()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 128 + 148) + 7228));
}


// ========================================================================
// __unwind$491624
// EA  : 0x82BDA2D0
// RVA : 0x00BDA2D0
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491624()
{
  int v0; // r12

  idFaceMgr::~idFaceMgr(this: (idFaceMgr *)(*(_DWORD *)(v0 - 128 + 148) + 7280));
}


// ========================================================================
// __unwind$491625
// EA  : 0x82BDA2FC
// RVA : 0x00BDA2FC
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491625()
{
  int v0; // r12

  idMD6LeafPause::~idMD6LeafPause(this: (idMD6LeafPause *)(*(_DWORD *)(v0 - 128 + 148) + 9256));
}


// ========================================================================
// __unwind$491626
// EA  : 0x82BDA328
// RVA : 0x00BDA328
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491626()
{
  int v0; // r12

  idMD6LeafPause::~idMD6LeafPause(this: (idMD6LeafPause *)(*(_DWORD *)(v0 - 128 + 148) + 9368));
}


// ========================================================================
// ??0idEditorModelEntity@@QAA@XZ
// EA  : 0x82BDA370
// RVA : 0x00BDA370
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

idEditorModelEntity *__fastcall idEditorModelEntity::idEditorModelEntity(idEditorModelEntity *this)
{
  float *p_z; // r9
  float *p_y; // r10
  int i; // ctr

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idEditorModelEntity_vtbl *)&idEditorModelEntity::`vftable';
  idMQBuffer::idMQBuffer(this: &this->attachments);
  this->uncompressedModelView = nullptr;
  this->movement = false;
  this->cycle = false;
  this->moveSpeed = 0.0;
  this->cycleFrom = true;
  this->caretTime = 0.0;
  this->cycleTo = true;
  idAnimator_Proxy::idAnimator_Proxy(this: &this->proxyAnimator);
  idAnimator_FaceTracks::idAnimator_FaceTracks(this: &this->faceAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->basePoseAnimator);
  idAnimStack::idAnimStack(this: &this->animStackUncompressed);
  idAnimator_Proxy::idAnimator_Proxy(this: &this->proxyAnimatorUncompressed);
  idAnimator_FaceTracks::idAnimator_FaceTracks(this: &this->faceAnimatorUncompressed);
  idAnimator_Paused::idAnimator_Paused(this: &this->basePoseAnimatorUncompressed);
  idFaceMgr::idFaceMgr(this: &this->faceMgr);
  this->sndFootsteps = nullptr;
  this->curAnim = nullptr;
  this->leaf = nullptr;
  idMD6Leaf::idMD6Leaf(this: &this->leafPlay, type_: NODE_LEAF_PLAY);
  this->leafPlay.startTime = 0;
  this->leafPlay.syncGroup = 0;
  this->leafPlay.syncEnabled = 0;
  this->leafPlay.rateScale = 1.0;
  idMD6LeafPause::idMD6LeafPause(this: &this->leafPause);
  this->leafUncompressed = nullptr;
  idMD6Leaf::idMD6Leaf(this: &this->leafPlayUncompressed, type_: NODE_LEAF_PLAY);
  this->leafPlayUncompressed.rateScale = 1.0;
  this->leafPlayUncompressed.startTime = 0;
  this->leafPlayUncompressed.syncGroup = 0;
  this->leafPlayUncompressed.syncEnabled = 0;
  idMD6LeafPause::idMD6LeafPause(this: &this->leafPauseUncompressed);
  this->lastLoopCount = 0;
  this->baseOrigin.x = 0.0;
  this->baseOrigin.y = 0.0;
  this->baseOrigin.z = 0.0;
  p_z = &this->baseOrigin.z;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_z = *++p_y;
  return this;
}


// ========================================================================
// __unwind$491930
// EA  : 0x82BDA4C4
// RVA : 0x00BDA4C4
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491930()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$491931
// EA  : 0x82BDA4EC
// RVA : 0x00BDA4EC
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491931()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5200));
}


// ========================================================================
// __unwind$491932
// EA  : 0x82BDA518
// RVA : 0x00BDA518
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491932()
{
  int v0; // r12

  idAnimator_Proxy::~idAnimator_Proxy(this: (idAnimator_Proxy *)(*(_DWORD *)(v0 - 144 + 164) + 5236));
}


// ========================================================================
// __unwind$491933
// EA  : 0x82BDA544
// RVA : 0x00BDA544
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491933()
{
  int v0; // r12

  idAnimator_FaceTracks::~idAnimator_FaceTracks(this: (idAnimator_FaceTracks *)(*(_DWORD *)(v0 - 144 + 164) + 5280));
}


// ========================================================================
// __unwind$491934
// EA  : 0x82BDA570
// RVA : 0x00BDA570
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491934()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 144 + 164) + 5420));
}


// ========================================================================
// __unwind$491935
// EA  : 0x82BDA59C
// RVA : 0x00BDA59C
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491935()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 144 + 164) + 5472));
}


// ========================================================================
// __unwind$491936
// EA  : 0x82BDA5C8
// RVA : 0x00BDA5C8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491936()
{
  int v0; // r12

  idAnimator_Proxy::~idAnimator_Proxy(this: (idAnimator_Proxy *)(*(_DWORD *)(v0 - 144 + 164) + 7044));
}


// ========================================================================
// __unwind$491937
// EA  : 0x82BDA5F4
// RVA : 0x00BDA5F4
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491937()
{
  int v0; // r12

  idAnimator_FaceTracks::~idAnimator_FaceTracks(this: (idAnimator_FaceTracks *)(*(_DWORD *)(v0 - 144 + 164) + 7088));
}


// ========================================================================
// __unwind$491938_0
// EA  : 0x82BDA620
// RVA : 0x00BDA620
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491938_0()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 144 + 164) + 7228));
}


// ========================================================================
// __unwind$491939
// EA  : 0x82BDA64C
// RVA : 0x00BDA64C
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491939()
{
  int v0; // r12

  idFaceMgr::~idFaceMgr(this: (idFaceMgr *)(*(_DWORD *)(v0 - 144 + 164) + 7280));
}


// ========================================================================
// __unwind$491940
// EA  : 0x82BDA678
// RVA : 0x00BDA678
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void _unwind_491940()
{
  int v0; // r12

  idMD6LeafPause::~idMD6LeafPause(this: (idMD6LeafPause *)(*(_DWORD *)(v0 - 144 + 164) + 9256));
}


// ========================================================================
// `dynamic initializer for 'modelEditor_entityDef''
// EA  : 0x833745A8
// RVA : 0x013745A8
// PDB : w:\tech5\tungsten\game\editor\editormodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__modelEditor_entityDef__()
{
  idCVar::idCVar(
    this: &modelEditor_entityDef,
    name: "modelEditor_entityDef",
    value: "player",
    flags: 0,
    description: "Default entity def to use for footstep sounds and other defaults",
    valueCompletion: (const char **)idDeclManager::ArgCompletion_Decl<idDeclEntityDef>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__modelEditor_entityDef__);
}

