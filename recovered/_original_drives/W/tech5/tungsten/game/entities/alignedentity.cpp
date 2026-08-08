
// ========================================================================
// ?JobSync@idAlignedEntity@@UAAXXZ
// EA  : 0x82BEF040
// RVA : 0x00BEF040
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAlignedEntity::JobSync(idAlignedEntity *this)
{
  idAnimatedEntity::JobSync(this);
}


// ========================================================================
// ?SetAnimRateScale@idAlignedEntity@@QAAXM@Z
// EA  : 0x82BEF048
// RVA : 0x00BEF048
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::SetAnimRateScale(idAlignedEntity *this, double rateScale)
{
  idMD6LeafPlay *LastPlayedLeaf; // r31
  int v4; // r3
  __int64 v5; // r10
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5

  if ( rateScale > 0.0 )
  {
    LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->baseAnimator);
    if ( LastPlayedLeaf != nullptr )
    {
      v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idMD6LeafPlay::SetRateScale(
        this: LastPlayedLeaf,
        gameTime: v4,
        rs: rateScale,
        a4: v9,
        a5: v8,
        a6: v7,
        a7: v6,
        a8: v5);
    }
  }
}


// ========================================================================
// ?IsAnimating@idAlignedEntity@@UBA_NXZ
// EA  : 0x82BEF0C8
// RVA : 0x00BEF0C8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

unsigned int __fastcall idAlignedEntity::IsAnimating(idAlignedEntity *this)
{
  int animDurationMS; // r11
  int v4; // r30
  const idAnimStack *v5; // r3

  animDurationMS = this->baseAnimInfo.animDurationMS;
  if ( animDurationMS >= 0 )
    return (-animDurationMS & (unsigned int)~animDurationMS) >> 31;
  v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v5 = this->GetAnimStack(this);
  return (_cntlzw(idAnimator_Channel::IsDone(this: &this->baseAnimator, stack: v5, curTime: v4)) & 0x20) != 0;
}


// ========================================================================
// ?GetSoundTransform@idAlignedEntity@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BEF168
// RVA : 0x00BEF168
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::GetSoundTransform(idAlignedEntity *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r30
  idPropsCollection *decl; // r11
  const tagData_t *Tag; // r3
  char *v11; // r10
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r11
  int i; // ctr
  char v14; // [sp+4Ch] [-54h] BYREF
  tagData_t v15[2]; // [sp+50h] [-50h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr
    && (decl = (idPropsCollection *)v8->decl) != nullptr
    && decl != (idPropsCollection *)-352
    && this->soundTagName.len != 0 )
  {
    Tag = idPropsCollection::GetTag(this: decl + 22, propName: "_info", tagName: this->soundTagName.data);
    v11 = &v14;
    p_parentJoint = &Tag[-1].parentJoint;
    for ( i = 8; i != 0; --i )
    {
      p_parentJoint += 2;
      v11 += 4;
      *(_DWORD *)v11 = *(_DWORD *)&p_parentJoint->value;
    }
    idTreeAnimator::GetWorldSpaceTagTransform(this: v8, tagData: v15, origin: soundOrigin, axis: soundAxis);
  }
  else
  {
    idEntity::GetSoundTransform(this, soundOrigin, soundAxis);
  }
}


// ========================================================================
// ?GetModelTransform@idAlignedEntity@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BEF238
// RVA : 0x00BEF238
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::GetModelTransform(idAlignedEntity *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  idAnimator_AF *v6; // r3
  char v7; // r11
  idPhysics *Physics; // r3
  float *v9; // r3
  idPhysics *v10; // r3
  float *v11; // r3

  v6 = (idAnimator_AF *)this->GetAF(this);
  if ( v6 == nullptr )
    goto LABEL_7;
  if ( v6->isActive || (v7 = 0, v6->isClientAuthoritativeActive) )
    v7 = 1;
  if ( v7 != 0 )
  {
    idAnimator_AF::GetModelTransform(this: v6, modelOrigin, modelAxis);
  }
  else
  {
LABEL_7:
    Physics = idEntity::GetPhysics(this);
    v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    modelOrigin->x = *v9;
    modelOrigin->y = v9[1];
    modelOrigin->z = v9[2];
    v10 = idEntity::GetPhysics(this);
    v11 = (float *)v10->GetAxis(this: v10, a2: 0);
    modelAxis->mat[0].x = *v11;
    modelAxis->mat[0].y = v11[1];
    modelAxis->mat[0].z = v11[2];
    modelAxis->mat[1].x = v11[3];
    modelAxis->mat[1].y = v11[4];
    modelAxis->mat[1].z = v11[5];
    modelAxis->mat[2].x = v11[6];
    modelAxis->mat[2].y = v11[7];
    modelAxis->mat[2].z = v11[8];
    if ( this->attachToOwnerStart != -1 && this->owner != nullptr )
    {
      modelOrigin->x = this->attachedModelOrigin.x;
      modelOrigin->y = this->attachedModelOrigin.y;
      modelOrigin->z = this->attachedModelOrigin.z;
      modelAxis->mat[0].x = this->attachedModelAxis.mat[0].x;
      modelAxis->mat[0].y = this->attachedModelAxis.mat[0].y;
      modelAxis->mat[0].z = this->attachedModelAxis.mat[0].z;
      modelAxis->mat[1].x = this->attachedModelAxis.mat[1].x;
      modelAxis->mat[1].y = this->attachedModelAxis.mat[1].y;
      modelAxis->mat[1].z = this->attachedModelAxis.mat[1].z;
      modelAxis->mat[2].x = this->attachedModelAxis.mat[2].x;
      modelAxis->mat[2].y = this->attachedModelAxis.mat[2].y;
      modelAxis->mat[2].z = this->attachedModelAxis.mat[2].z;
    }
  }
}


// ========================================================================
// ?InternalPlayAnim@idAlignedEntity@@AAA_NAAVidAnimator_Channel@@AAUanimInfo_t@1@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHABVblendParms_t@@M@Z
// EA  : 0x82BEF3D0
// RVA : 0x00BEF3D0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

int __fastcall idAlignedEntity::InternalPlayAnim(
        idAlignedEntity *this,
        idAnimator_Channel *channelAnimator,
        idAlignedEntity::animInfo_t *animInfo,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        bool loop,
        int durationMS,
        blendParms_t *blendParms,
        double rateScale)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int value; // r11
  idTreeAnimator *v18; // r10
  int result; // r3
  int v20; // r29
  __int64 v21; // r8
  const idAnimStack *v22; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  value = aliasHandle->value;
  v18 = TreeAnimatorFromPresentable;
  result = 0;
  if ( value != 0xFFFF && v18 != nullptr )
  {
    animInfo->curAliasHandle.value = value;
    animInfo->startTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v20 = ((int (*)(void))gameLocal->GetGameMs)();
    v22 = this->GetAnimStack_2(this);
    if ( loop )
    {
      LODWORD(v21) = blendParms;
      result = idAnimator_Channel::CycleAnim(
                 this: channelAnimator,
                 stack: v22,
                 ah: &animInfo->curAliasHandle,
                 curTime: v20,
                 rateScale,
                 leafStarted: v21,
                 a7: nullptr);
    }
    else
    {
      result = idAnimator_Channel::PlayAnim(
                 this: channelAnimator,
                 stack: v22,
                 ah: &animInfo->curAliasHandle,
                 curTime: v20,
                 rateScale,
                 blendParms: (const blendParms_t *)HIDWORD(v21),
                 blendOutDurationMS_: blendParms,
                 leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                 a9: nullptr);
    }
    if ( (_BYTE)result != 0 )
      animInfo->animDurationMS = durationMS;
  }
  return result;
}


// ========================================================================
// ?IsAnimDone@idAlignedEntity@@QAA_NV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@H@Z
// EA  : 0x82BEF500
// RVA : 0x00BEF500
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

BOOL __fastcall idAlignedEntity::IsAnimDone(
        idAlignedEntity *this,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        int numFramesAhead,
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
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> a14)
{
  int v16; // r30
  int v17; // r30
  const idAnimStack *v18; // r3

  a14.value = (unsigned __int16)aliasHandle;
  if ( (unsigned __int16)aliasHandle == 0xFFFF )
    return true;
  v16 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED) * numFramesAhead;
  v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + v16;
  v18 = this->GetAnimStack_2(this);
  return (_cntlzw((unsigned __int8)idAnimator_Channel::IsAnimPlaying(
                                     this: &this->baseAnimator,
                                     stack: v18,
                                     ah: &a14,
                                     curTime: v17))
        & 0x20) != 0;
}


// ========================================================================
// ?GetCurAnimName@idAlignedEntity@@QAAPBDXZ
// EA  : 0x82BEF5B0
// RVA : 0x00BEF5B0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

const char *__fastcall idAlignedEntity::GetCurAnimName(idAlignedEntity *this)
{
  unsigned __int16 v3[4]; // [sp+50h] [-20h] BYREF

  if ( !this->IsAnimating(this) || idAnimatedEntity::GetTreeAnimatorFromPresentable(this) == nullptr )
    return "<not animating>";
  v3[0] = this->baseAnimInfo.curAliasHandle.value;
  return animation->FindAliasName(
           this: animation,
           a2: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v3);
}


// ========================================================================
// ?GetLastOriginDeltas@idAlignedEntity@@QAAXAAVidMat3@@AAVidVec3@@PAH@Z
// EA  : 0x82BEF640
// RVA : 0x00BEF640
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::GetLastOriginDeltas(
        idAlignedEntity *this,
        idMat3 *deltaRot,
        idVec3 *deltaTrans,
        int *time)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v8; // r31

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v8 = TreeAnimatorFromPresentable;
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idTreeAnimator::GetLastOriginDeltas(this: TreeAnimatorFromPresentable, rot: deltaRot, trans: deltaTrans);
    if ( time != nullptr )
      *time = idTreeAnimator::GetLastOriginDeltaTime(this: v8);
  }
}


// ========================================================================
// ?StopAdditiveAnim@idAlignedEntity@@QAAXXZ
// EA  : 0x82BEF690
// RVA : 0x00BEF690
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::StopAdditiveAnim(idAlignedEntity *this)
{
  this->additiveAnimInfo.startTime = 0;
  this->additiveAnimInfo.curAliasHandle.value = -1;
  this->additiveAnimInfo.animDurationMS = 0;
}


// ========================================================================
// ?SetAdditiveAnimAlpha@idAlignedEntity@@QAAXMM@Z
// EA  : 0x82BEF6A8
// RVA : 0x00BEF6A8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::SetAdditiveAnimAlpha(idAlignedEntity *this, double alpha, double alphaRate)
{
  double valueFloat; // fp31
  idMD6Branch *v5; // r3

  valueFloat = alphaRate;
  if ( alphaRate < 0.0 )
    valueFloat = alignedEnt_defaultAdditiveAlphaRate.valueFloat;
  v5 = this->additiveAnimator.InternalGetMergeBranch_2(this: &this->additiveAnimator);
  if ( v5 != nullptr )
  {
    v5->targetAlpha = alpha;
    if ( valueFloat <= 0.0 )
    {
      v5->currentAlpha = alpha;
      v5->alphaRate = 0.0;
    }
    else
    {
      v5->alphaRate = valueFloat;
    }
  }
}


// ========================================================================
// ?ForceNonDeferredAnimationUpdate@idAlignedEntity@@QAA_NXZ
// EA  : 0x82BEF738
// RVA : 0x00BEF738
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

int __fastcall idAlignedEntity::ForceNonDeferredAnimationUpdate(idAlignedEntity *this)
{
  int v2; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  if ( gameLocal->GetGameFrame(this: gameLocal) == this->lastAnimBlendFrame )
    return 0;
  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idTreeAnimator::SyncJoints(this: TreeAnimatorFromPresentable, time: v2);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: true);
  this->lastAnimBlendFrame = gameLocal->GetGameFrame(this: gameLocal);
  idEntity::UpdateVisuals(this);
  this->UpdateAttachments(this);
  return 1;
}


// ========================================================================
// ?Align@idAlignedEntity@@QAAXABVidVec3@@ABVidMat3@@W4ALIGNMODE@1@@Z
// EA  : 0x82BEF7F0
// RVA : 0x00BEF7F0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::Align(
        idAlignedEntity *this,
        const idVec3 *origin,
        idMat3 *axis,
        idAlignedEntity::ALIGNMODE alignMode)
{
  idRenderWorld *v8; // r3
  const idMat3 *v9; // r4
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v13; // fp10
  double v14; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  int *v18; // r10
  int *v19; // r11
  int i; // ctr
  idPresentable *presentable; // r11
  double v22; // fp6
  double v23; // fp3
  void (__fastcall *SetOrigin)(idAlignedEntity *, const idVec3 *); // ctr
  double v25; // fp1
  idRenderWorld *v26; // r3
  idRenderWorld *v27; // r3
  float v28; // [sp+50h] [-160h] BYREF
  float v29; // [sp+54h] [-15Ch]
  float v30; // [sp+58h] [-158h]
  float v31; // [sp+60h] [-150h] BYREF
  float v32; // [sp+64h] [-14Ch]
  float v33; // [sp+68h] [-148h]
  idVec3 v34; // [sp+70h] [-140h] BYREF
  idVec3 v35; // [sp+80h] [-130h] BYREF
  idAngles v36; // [sp+90h] [-120h] BYREF
  float v37; // [sp+9Ch] [-114h]
  float v38; // [sp+A0h] [-110h]
  float v39; // [sp+A4h] [-10Ch]
  float v40; // [sp+A8h] [-108h]
  float v41; // [sp+ACh] [-104h]
  float v42; // [sp+B0h] [-100h]
  int v43; // [sp+BCh] [-F4h] BYREF
  idMat3 v44; // [sp+C0h] [-F0h] BYREF
  idMat3 v45; // [sp+F0h] [-C0h] BYREF
  idMat3 v46; // [sp+120h] [-90h] BYREF
  int v47; // [sp+14Ch] [-64h] BYREF
  idMat3 v48[2]; // [sp+150h] [-60h] BYREF

  if ( alignedEnt_traceAlign.valueInteger != 0 )
    idLib::Printf(fmt: "\n%s - start of align trace\n", "idAlignedEntity::Align");
  if ( alignMode == SET_POS_SET_AXIS )
  {
    this->SetOrigin(this, a2: origin);
    this->SetAxis(this, a2: axis);
    if ( alignedEnt_drawTargetJoint.valueInteger != 0 )
    {
      v8 = gameLocal->GetRenderWorld(this: gameLocal);
      v8->DebugAxis_2(this: v8, a2: origin, a3: axis, a4: 0, a5: false);
    }
    if ( alignedEnt_traceAlign.valueInteger != 0 )
    {
      idMat3::ToAngles(this: (idMat3 *)&v28, result: (idAngles *)axis);
      idLib::Printf(
        fmt: "%s - SET_POS_SET_AXIS\torigin=(%0.2f,%0.2f,%0.2f)\tangles=(%0.2f,%0.2f,%0.2f)\n",
        (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(origin->x)),
        origin->x,
        origin->y,
        origin->z,
        v28,
        v29,
        v30);
    }
    return;
  }
  if ( (unsigned __int8)idAlignedEntity::ForceNonDeferredAnimationUpdate(this) != 0
    && alignedEnt_traceAlign.valueInteger != 0 )
  {
    idLib::Printf(fmt: "%s - updating animation\n", "idAlignedEntity::Align");
  }
  if ( !idAnimatedEntity::GetJointLocalTransform(this, jointName: this->alignNodeName.data, offset: &v35, axis: &v44) )
  {
    idLib::Warning(
      fmt: "%s: node <%s> not found in entity <%s>",
      "idAlignedEntity::Align",
      this->alignNodeName.data,
      this->name.data);
    return;
  }
  if ( alignedEnt_traceAlign.valueInteger != 0 )
  {
    idMat3::ToAngles(this: (idMat3 *)&v28, result: (idAngles *)&v44);
    idLib::Printf(
      fmt: "%s - joint local axis\torigin=(%0.2f,%0.2f,%0.2f)\tangles=(%0.2f,%0.2f,%0.2f)\n",
      (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v35.x)),
      v35.x,
      v35.y,
      v35.z,
      v28,
      v29,
      v30);
  }
  if ( alignMode == ALIGN_NODE_POS_SET_AXIS )
  {
    v9 = axis;
    y = axis->mat[0].y;
    z = axis->mat[0].z;
    x = axis->mat[1].x;
    v13 = axis->mat[1].y;
    v14 = axis->mat[1].z;
    v15 = axis->mat[2].x;
    v16 = axis->mat[2].y;
    v17 = axis->mat[2].z;
    v36.pitch = axis->mat[0].x;
    v36.yaw = y;
    v36.roll = z;
    v37 = x;
    v38 = v13;
    v39 = v14;
    v40 = v15;
    v41 = v16;
    v42 = v17;
  }
  else
  {
    if ( alignMode != ALIGN_NODE_POS_ALIGN_NODE_AXIS )
      goto LABEL_20;
    v46.mat[0].x = v44.mat[0].x;
    v46.mat[0].y = v44.mat[1].x;
    v46.mat[0].z = v44.mat[2].x;
    v46.mat[1].x = v44.mat[0].y;
    v46.mat[1].y = v44.mat[1].y;
    v46.mat[1].z = v44.mat[2].y;
    v46.mat[2].x = v44.mat[0].z;
    v46.mat[2].y = v44.mat[1].z;
    v46.mat[2].z = v44.mat[2].z;
    idMat3::operator*(this: &v45, result: &v46, a: axis);
    v9 = &v45;
    v36.pitch = v45.mat[0].x;
    v36.yaw = v45.mat[0].y;
    v36.roll = v45.mat[0].z;
    v37 = v45.mat[1].x;
    v38 = v45.mat[1].y;
    v39 = v45.mat[1].z;
    v40 = v45.mat[2].x;
    v41 = v45.mat[2].y;
    v42 = v45.mat[2].z;
  }
  this->SetAxis(this, a2: v9);
LABEL_20:
  v18 = &v47;
  v19 = &v43;
  v34 = v35;
  for ( i = 9; i != 0; --i )
    *++v18 = *++v19;
  idEntity::ConvertLocalToWorldTransform(this, offset: &v34, axis: v48);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v22 = (float)(origin->x - v34.x);
  v23 = presentable->origin.x;
  SetOrigin = this->SetOrigin;
  v25 = (float)(presentable->origin.z + (float)(origin->z - v34.z));
  v32 = presentable->origin.y + (float)(origin->y - v34.y);
  v33 = v25;
  v31 = (float)v23 + (float)v22;
  SetOrigin(this, a2: (const idVec3 *)&v31);
  if ( alignedEnt_traceAlign.valueInteger != 0 )
  {
    idMat3::ToAngles(this: (idMat3 *)&v28, result: &v36);
    if ( alignMode == ALIGN_NODE_POS_SET_AXIS )
    {
      idLib::Printf(
        fmt: "%s - NODE_POS_SET_AXIS\torigin=(%0.2f,%0.2f,%0.2f)\tangles=(%0.2f,%0.2f,%0.2f)\n",
        (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v31)),
        v31,
        v32,
        v33,
        v28,
        v29,
        v30);
    }
    else if ( alignMode == ALIGN_NODE_POS_ALIGN_NODE_AXIS )
    {
      idLib::Printf(
        fmt: "%s - ALIGN_NODE_POS_ALIGN_NODE_AXIS\torigin=(%0.2f,%0.2f,%0.2f)\tangles=(%0.2f,%0.2f,%0.2f)\n",
        (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v31)),
        v31,
        v32,
        v33,
        v28,
        v29,
        v30);
    }
  }
  if ( alignedEnt_drawAlignJoint.valueInteger != 0 )
  {
    v26 = gameLocal->GetRenderWorld(this: gameLocal);
    v26->DebugAxis_2(this: v26, a2: &v34, a3: v48, a4: 0, a5: false);
  }
  if ( alignedEnt_drawTargetJoint.valueInteger != 0 )
  {
    v27 = gameLocal->GetRenderWorld(this: gameLocal);
    v27->DebugAxis_2(this: v27, a2: origin, a3: axis, a4: 0, a5: false);
  }
}


// ========================================================================
// ?AttachToOwner@idAlignedEntity@@QAAXH@Z
// EA  : 0x82BEFD68
// RVA : 0x00BEFD68
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::AttachToOwner(idAlignedEntity *this, int blendTime)
{
  idPhysics *Physics; // r3
  idPhysics *v5; // r3
  idQuat *v6; // r3
  idPresentable *presentable; // r11
  idMat3 v8; // [sp+50h] [-30h] BYREF

  this->attachToOwnerStart = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->attachToOwnerBlend = blendTime;
  Physics = idEntity::GetPhysics(this);
  this->startBlendOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
  v5 = idEntity::GetPhysics(this);
  v6 = (idQuat *)v5->GetAxis(this: v5, a2: 0);
  this->startBlendRot = *idMat3::ToQuat(this: &v8, result: v6);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->model->useDeferredPosition = false;
}


// ========================================================================
// ?DetachFromOwner@idAlignedEntity@@QAAXHABVidVec3@@ABVidQuat@@@Z
// EA  : 0x82BEFE60
// RVA : 0x00BEFE60
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::DetachFromOwner(
        idAlignedEntity *this,
        int blendTime,
        const idVec3 *fromPosition,
        const idQuat *fromQuat)
{
  idPhysics *Physics; // r3
  idPhysics *v9; // r3
  idQuat *v10; // r3
  idMat3 v11; // [sp+50h] [-40h] BYREF

  this->attachToOwnerStart = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->attachToOwnerBlend = -blendTime;
  this->endBlendOrigin = *fromPosition;
  this->endBlendRot = *fromQuat;
  Physics = idEntity::GetPhysics(this);
  this->startBlendOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
  v9 = idEntity::GetPhysics(this);
  v10 = (idQuat *)v9->GetAxis(this: v9, a2: 0);
  this->startBlendRot = *idMat3::ToQuat(this: &v11, result: v10);
}


// ========================================================================
// ?SetManualUpdateCamera@idAlignedEntity@@QAAX_N@Z
// EA  : 0x82BEFF60
// RVA : 0x00BEFF60
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::SetManualUpdateCamera(idAlignedEntity *this, bool _updateCamera)
{
  idPlayer *owner; // r11
  idSpringCamera *springCamera; // r11

  owner = this->owner;
  this->updateCamera = _updateCamera;
  springCamera = owner->springCamera;
  if ( springCamera != nullptr )
    springCamera->manualUpdate = _updateCamera;
}


// ========================================================================
// ?SetOrigin@idAlignedEntity@@UAAXABVidVec3@@@Z
// EA  : 0x82BEFF80
// RVA : 0x00BEFF80
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::SetOrigin(idAlignedEntity *this, const idVec3 *origin)
{
  idPresentable *presentable; // r11
  idPresentable *v5; // r11
  idPresentable *v6; // r11
  idRenderModel *model; // r11

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->origin.x = origin->x;
  presentable->origin.y = origin->y;
  presentable->origin.z = origin->z;
  v5 = this->presentable;
  if ( v5 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v5 = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: v5);
  v6 = this->presentable;
  if ( v6 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v6 = this->presentable;
  }
  model = v6->model;
  if ( !model->deferredPositionInitialized || !model->useDeferredPosition )
  {
    model->g.origin.x = origin->x;
    model->g.origin.y = origin->y;
    model->g.origin.z = origin->z;
  }
  model->deferredOrigin.x = origin->x;
  model->deferredOrigin.y = origin->y;
  model->deferredOrigin.z = origin->z;
  idEntity::SetOrigin(this, org: origin);
}


// ========================================================================
// ?SetAxis@idAlignedEntity@@UAAXABVidMat3@@@Z
// EA  : 0x82BF0070
// RVA : 0x00BF0070
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::SetAxis(idAlignedEntity *this, const idMat3 *axis)
{
  float *presentable; // r11
  idPresentable *v5; // r11
  idPresentable *v6; // r11

  presentable = (float *)this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = (float *)this->presentable;
  }
  presentable[33] = axis->mat[0].x;
  presentable[34] = axis->mat[0].y;
  presentable[35] = axis->mat[0].z;
  presentable[36] = axis->mat[1].x;
  presentable[37] = axis->mat[1].y;
  presentable[38] = axis->mat[1].z;
  presentable[39] = axis->mat[2].x;
  presentable[40] = axis->mat[2].y;
  presentable[41] = axis->mat[2].z;
  v5 = this->presentable;
  if ( v5 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v5 = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: v5);
  v6 = this->presentable;
  if ( v6 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v6 = this->presentable;
  }
  idRenderModel::SetAxis(this: v6->model, a: axis);
  idEntity::SetAxis(this, axis);
}


// ========================================================================
// ?DetachCamera@idAlignedEntity@@QAAX_N@Z
// EA  : 0x82BF0158
// RVA : 0x00BF0158
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::DetachCamera(idAlignedEntity *this, bool instantBlend)
{
  idSpringCamera *springCamera; // r3

  springCamera = this->owner->springCamera;
  if ( springCamera != nullptr )
    idSpringCamera::BlendOut(this: springCamera, instantBlend);
}


// ========================================================================
// ?AnimEvent_DetachAttachmentByModel@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclMD6@@@Z
// EA  : 0x82BF0170
// RVA : 0x00BF0170
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_DetachAttachmentByModel(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idDeclMD6 *model)
{
  idAttachmentCollection *v7; // r30
  int v8; // r6
  int v9; // r11
  int v10; // r10
  eventVoid *v11; // r7
  int v12; // r9
  int v14; // r10
  int v15; // r10
  int v16; // r9
  int v17; // r11
  _DWORD *v18; // r8
  _DWORD *v19; // r7
  idAttachmentCollection v20[2]; // [sp+50h] [-30h] BYREF

  if ( model != nullptr )
  {
    v7 = (idAttachmentCollection *)&result[6396];
    idAttachmentCollection::FindAttachment(
      this: v20,
      result: (idHandle<int,enum invalidAttachment_t,-1> *)&result[6396],
      modelName: model->name.str);
    if ( v20[0].attachments.list == (idAttachment *)-1 )
      idLib::Warning(
        fmt: "idAlignedEntity::AnimEvent_DetachAttachmentByModel: Couldn't find attachment for model %s",
        model->name.str);
    idAttachmentCollection::DetachAttachment(this: v7, handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v20);
    v8 = *(_DWORD *)&result[6420];
    v9 = 0;
    if ( v8 > 0 )
    {
      v10 = 0;
      v11 = result + 6416;
      v12 = *(_DWORD *)&result[6416];
      while ( *(idAttachment **)(v12 + 8) != v20[0].attachments.list )
      {
        ++v9;
        v10 += 16;
        v12 = v10 + *(_DWORD *)&result[6416];
        if ( v9 >= v8 )
          return this;
      }
      if ( v9 >= 0 )
      {
        v14 = *(_DWORD *)&result[6420];
        if ( v9 < v14 )
        {
          v15 = v14 - 1;
          *(_DWORD *)&result[6420] = v15;
          if ( v9 != v15 )
          {
            v16 = *(_DWORD *)v11;
            v17 = 16 * v9;
            v18 = (_DWORD *)(16 * v15 + *(_DWORD *)v11);
            v19 = (_DWORD *)(v17 + *(_DWORD *)v11);
            *(_DWORD *)(v17 + v16) = *v18;
            v19[1] = v18[1];
            v19[2] = v18[2];
            v19[3] = v18[3];
          }
        }
      }
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_StartWeaponFX@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82BF0280
// RVA : 0x00BF0280
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_StartWeaponFX(
        idAlignedEntity *this,
        idActor *result,
        const idMD6Anim *anim,
        int condition)
{
  int v7; // r19
  int v8; // r26
  int v9; // r30
  idLaserCutter *v10; // r31
  idFXManager *FXMgrForAttachment; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v12; // r3
  idAttachmentCollection *v13; // r3
  const idAttachment *v14; // r3
  const idTreeAnimator *v15; // r4
  unsigned int GameMs; // r3
  idLaserCutter *v17; // r3
  idAttachmentCollection v19; // [sp+50h] [-C0h] BYREF
  idMat3 v20[4]; // [sp+70h] [-A0h] BYREF

  v7 = 0;
  if ( SLODWORD(result->afProperties.physicsObj.current.pushVelocity.p[5]) > 0 )
  {
    v8 = 0;
    do
    {
      v9 = v8 + LODWORD(result->afProperties.physicsObj.current.pushVelocity.p[4]);
      v10 = (idLaserCutter *)idWeapon::CastTo(c: *(idWeapon **)(v9 + 4));
      if ( v10 != nullptr )
      {
        FXMgrForAttachment = idAlignedEntity::GetFXMgrForAttachment(this: result, item: *(idInventoryItem **)(v9 + 4));
        if ( FXMgrForAttachment != nullptr )
        {
          v12 = (idHandle<int,enum invalidAttachment_t,-1> *)result->GetAttachments_2(this: result);
          idAttachmentCollection::FindAttachment(this: &v19, result: v12, item: v10);
          if ( v19.attachments.list == (idAttachment *)-1 )
          {
            idLib::Warning(fmt: "idActor::GetEquippedWeaponAnimator - could not find weapon attachment");
          }
          else
          {
            v13 = result->GetAttachments_2(this: result);
            v14 = idAttachmentCollection::Get(
                    this: v13,
                    handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v19);
            if ( v14 == nullptr || v14->handle.value == -1 )
            {
              idLib::Warning(fmt: "idActor::GetEquippedWeaponAnimator - attachment is null or has no handle");
            }
            else if ( v14->presentable != nullptr )
            {
              v15 = (const idTreeAnimator *)_RTDynamicCast(
                                              inptr: v14->presentable->model,
                                              VfDelta: 0,
                                              SrcType: &idRenderModel `RTTI Type Descriptor',
                                              TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                              isReference: 0);
              if ( v15 != nullptr )
              {
                idWeapon::GetMuzzleFlashWorldTransform(
                  this: v10,
                  ta: v15,
                  attackType: ATTACK_DEFAULT,
                  origin: (idVec3 *)&v19.attachments.size,
                  axis: v20);
                GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                idFXManager::StartFX(
                  this: FXMgrForAttachment,
                  org: (const idVec3 *)&v19.attachments.size,
                  axis: v20,
                  time: GameMs,
                  startCondition: condition,
                  extraCond: 68);
                v17 = idLaserCutter::CastTo(c: v10);
                if ( v17 != nullptr && condition == 73 )
                  idLaserCutter::FakeCutEffect(this: v17);
              }
            }
            else
            {
              idLib::Warning(fmt: "idActor::GetEquippedWeaponAnimator - attachment has no model");
            }
          }
        }
      }
      ++v7;
      v8 += 16;
    }
    while ( v7 < SLODWORD(result->afProperties.physicsObj.current.pushVelocity.p[5]) );
  }
  return this;
}


// ========================================================================
// ?AnimEvent_StopWeaponFX@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82BF0440
// RVA : 0x00BF0440
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_StopWeaponFX(
        idAlignedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        int condition)
{
  int v7; // r27
  int v8; // r29
  idInventoryItem *v9; // r31
  idHandle<int,enum invalidAttachment_t,-1> *v10; // r3
  idAttachmentCollection *v11; // r3
  const idAttachment *v12; // r3
  idPresentable *presentable; // r11
  idFXManager *p_fxManager; // r31
  int GameMs; // r3
  idAttachmentCollection v17[4]; // [sp+50h] [-50h] BYREF

  v7 = 0;
  if ( result[8].name.allocedAndFlag > 0 )
  {
    v8 = 0;
    do
    {
      v9 = *(idInventoryItem **)&result[8].name.data[v8 + 4];
      if ( v9 != nullptr )
      {
        v10 = (idHandle<int,enum invalidAttachment_t,-1> *)result->GetAttachments_2(this: result);
        idAttachmentCollection::FindAttachment(this: v17, result: v10, item: v9);
        if ( v17[0].attachments.list == (idAttachment *)-1
          || (v11 = result->GetAttachments_2(this: result),
              (v12 = idAttachmentCollection::Get(
                       this: v11,
                       handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v17)) == nullptr)
          || (presentable = v12->presentable, v12->presentable == nullptr) )
        {
          presentable = result->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: result);
            presentable = result->presentable;
          }
        }
        p_fxManager = &presentable->fxManager;
        if ( presentable != (idPresentable *)-288 )
        {
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idFXManager::StopFX(this: p_fxManager, time: GameMs, stopCondition: condition, immediateStop: false);
        }
      }
      ++v7;
      v8 += 16;
    }
    while ( v7 < result[8].name.allocedAndFlag );
  }
  return this;
}


// ========================================================================
// ?AnimEvent_StartSlowMotion@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA  : 0x82BF0558
// RVA : 0x00BF0558
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_StartSlowMotion(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        double easeInSecs,
        double easeOutSecs,
        double timeScale)
{
  const char *str; // r31
  int v11; // r3
  int v12; // r3
  idGameTimeManager *v13; // r3
  slowmoParms_t v15; // [sp+50h] [-40h] BYREF

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v11 = idAccolade::Count(this: &clientGame->gameTimeManager);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v11, "idAlignedEntity::AnimEvent_StartSlowMotion", str);
  }
  v12 = ((int (__fastcall *)(idCommon *, eventVoid *, const idMD6Anim *))common->Game)(
          a1: common,
          a2: result,
          a3: animHandle);
  v13 = (idGameTimeManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v12 + 140))(a1: v12);
  v15.easeInDuration = easeInSecs;
  v15.easeOutDuration = easeOutSecs;
  v15.timeScale = timeScale;
  v15.slowmoDuration = 0.0;
  idGameTimeManager::StartSlowmotion(this: v13, slowmoParms: &v15);
  return this;
}


// ========================================================================
// ?AnimEvent_StopSlowMotion@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF0658
// RVA : 0x00BF0658
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_StopSlowMotion(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v5; // r3
  int v6; // r3
  idGameTimeManager *v7; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v5 = idAccolade::Count(this: &clientGame->gameTimeManager);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v5, "idAlignedEntity::AnimEvent_StopSlowMotion", str);
  }
  v6 = ((int (__fastcall *)(idCommon *, eventVoid *, const idMD6Anim *))common->Game)(
         a1: common,
         a2: result,
         a3: animHandle);
  v7 = (idGameTimeManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v6 + 140))(a1: v6);
  idGameTimeManager::StopSlowmotion(this: v7);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBody@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF0718
// RVA : 0x00BF0718
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SoundBody(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idSoundShader *shader)
{
  const char *str; // r31
  int v8; // r3
  idEntity *v9; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v8 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v8, "idAlignedEntity::AnimEvent_SoundBody", str);
  }
  v9 = *(idEntity **)&result[6436];
  if ( v9 != nullptr )
    idEntity::StartSoundShader(this: v9, channel: SND_CHANNEL_BODY, shader, soundShaderFlags: 0, peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBody2@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF07C0
// RVA : 0x00BF07C0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SoundBody2(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idSoundShader *shader)
{
  const char *str; // r31
  int v8; // r3
  idEntity *v9; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v8 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v8, "idAlignedEntity::AnimEvent_SoundBody2", str);
  }
  v9 = *(idEntity **)&result[6436];
  if ( v9 != nullptr )
    idEntity::StartSoundShader(this: v9, channel: SND_CHANNEL_BODY2, shader, soundShaderFlags: 0, peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBody3@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF0868
// RVA : 0x00BF0868
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SoundBody3(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idSoundShader *shader)
{
  const char *str; // r31
  int v8; // r3
  idEntity *v9; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v8 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v8, "idAlignedEntity::AnimEvent_SoundBody3", str);
  }
  v9 = *(idEntity **)&result[6436];
  if ( v9 != nullptr )
    idEntity::StartSoundShader(this: v9, channel: SND_CHANNEL_BODY3, shader, soundShaderFlags: 0, peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBodyLoopUntilStopped@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF0910
// RVA : 0x00BF0910
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SoundBodyLoopUntilStopped(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idSoundShader *shader)
{
  const char *str; // r30
  int v8; // r3
  idEntity *v9; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v8 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v8, "idAlignedEntity::AnimEvent_SoundBodyLoopUntilStopped", str);
  }
  v9 = *(idEntity **)&result[6436];
  if ( v9 != nullptr && shader != *(const idSoundShader **)&result[5200] )
  {
    *(_DWORD *)&result[5200] = shader;
    if ( shader != nullptr )
    {
      idEntity::StartSoundShader(this: v9, channel: SND_CHANNEL_BODY, shader, soundShaderFlags: 0, peerMask: 0xFFu);
      *(_WORD *)&result[5204] = -1;
      return this;
    }
    idEntity::StopSound(this: v9, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    *(_WORD *)&result[5204] = -1;
  }
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBodyLoopStop@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF09F8
// RVA : 0x00BF09F8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SoundBodyLoopStop(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3
  idEntity *v7; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_SoundBodyLoopStop", str);
  }
  v7 = *(idEntity **)&result[6436];
  if ( v7 != nullptr && *(_DWORD *)&result[5200] != 0 )
  {
    idEntity::StopSound(this: v7, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    *(_DWORD *)&result[5200] = 0;
    *(_WORD *)&result[5204] = -1;
  }
  return this;
}


// ========================================================================
// ?AnimEvent_DetachCamera@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF0AB0
// RVA : 0x00BF0AB0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_DetachCamera(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3
  idSpringCamera *v7; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_DetachCamera", str);
  }
  v7 = *(idSpringCamera **)(*(_DWORD *)&result[6436] + 13252);
  if ( v7 != nullptr )
    idSpringCamera::BlendOut(this: v7, instantBlend: false);
  return this;
}


// ========================================================================
// ?AnimEvent_StartCameraShake@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@HH@Z
// EA  : 0x82BF0B50
// RVA : 0x00BF0B50
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_StartCameraShake(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        int scale,
        int decay)
{
  const char *str; // r31
  int v7; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v7 = idAccolade::Count(this: &clientGame->gameTimeManager);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v7, "idAlignedEntity::AnimEvent_StartCameraShake", str);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_SetControllerShake@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@MHMH@Z
// EA  : 0x82BF0BE8
// RVA : 0x00BF0BE8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SetControllerShake(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        double highMagnitude,
        int highDuration,
        double lowMagnitude,
        int lowDuration)
{
  const char *str; // r31
  int v13; // r3
  int v14; // r11
  int v15; // r3
  int v16; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v13 = idAccolade::Count(this: &clientGame->gameTimeManager);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v13, "idAlignedEntity::AnimEvent_SetControllerShake", str);
  }
  v14 = *(_DWORD *)&result[6436];
  if ( v14 != 0 )
  {
    v15 = *(_DWORD *)(v14 + 488);
    if ( v15 != 0 )
      v16 = (*(int (__fastcall **)(int))(*(_DWORD *)v15 + 104))(a1: v15);
    else
      v16 = 0;
    idView::SetControllerShake(
      this: (idView *)(v16 + 16224),
      highMagnitude,
      highDuration: (int)result,
      lowMagnitude,
      lowDuration);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_HideHands@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF0CD0
// RVA : 0x00BF0CD0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_HideHands(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_HideHands", str);
  }
  idPlayer::HideHands(this: *(idPlayer **)&result[6436]);
  return this;
}


// ========================================================================
// ?AnimEvent_ShowHands@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF0D60
// RVA : 0x00BF0D60
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_ShowHands(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_ShowHands", str);
  }
  idPlayer::ShowHands(this: *(idPlayer **)&result[6436]);
  return this;
}


// ========================================================================
// ?AnimEvent_CarryNPC@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF0DF0
// RVA : 0x00BF0DF0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_CarryNPC(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v5; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v5 = ((int (__fastcall *)(idGameLocal *, eventVoid *))gameLocal->GetGameFrame)(a1: gameLocal, a2: result);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v5, "idAlignedEntity::AnimEvent_CarryNPC", str);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_EntitySnapToPlayer@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF0E88
// RVA : 0x00BF0E88
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_EntitySnapToPlayer(
        idAlignedEntity *this,
        idEntity *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3
  int v7; // r31
  int v8; // r11
  int v9; // r3
  const idAngles *v10; // r4
  idPresentablePlayer *ViewAngles; // r3
  char v13; // [sp+50h] [-30h] BYREF

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_EntitySnapToPlayer", str);
  }
  v7 = *(_DWORD *)&result[8].name.baseBuffer[12];
  v8 = *(_DWORD *)(v7 + 488);
  if ( v8 == 0 )
  {
    idEntity::InitPresentableInternal(this: *(idEntity **)&result[8].name.baseBuffer[12]);
    v8 = *(_DWORD *)(v7 + 488);
  }
  ((void (__fastcall *)(idEntity *, int))result->__vftable[1].JobSync)(a1: result, a2: v8 + 120);
  v9 = *(_DWORD *)(*(_DWORD *)&result[8].name.baseBuffer[12] + 488);
  if ( v9 != 0 )
    v10 = (const idAngles *)(*(int (__fastcall **)(int))(*(_DWORD *)v9 + 104))(a1: v9);
  else
    v10 = nullptr;
  ViewAngles = idPresentablePlayer::GetViewAngles(
                 this: (idPresentablePlayer *)&v13,
                 result: v10,
                 includeWeaponKick: true);
  idEntity::SetAngles(this: result, ang: (const idAngles *)ViewAngles);
  return this;
}


// ========================================================================
// ?AnimEvent_PlayerSnapToEntity@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF0F88
// RVA : 0x00BF0F88
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_PlayerSnapToEntity(
        idAlignedEntity *this,
        idEntity *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3
  idPresentable *presentable; // r11
  const idVec3 *p_origin; // r29
  idVec3 *mat; // r31
  int v10; // r28
  float *v11; // r11
  int v12; // r29
  float *v13; // r11
  int v14; // r3
  const idAngles *v15; // r4
  double v16; // fp1
  int v17; // r10
  int v18; // r3
  idPresentablePlayer *v19; // r3
  int v20; // r3
  idPresentablePlayer *v21; // r3
  idAngles v23[5]; // [sp+50h] [-40h] BYREF

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_PlayerSnapToEntity", str);
  }
  if ( common->IsMultiplayer(this: common) )
    idLib::Warning(fmt: "idAlignedEntity::AnimEvent_PlayerSnapToEntity used in multiplayer mode. see hansoft://hansoft/Task/146436");
  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  p_origin = &presentable->origin;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  mat = presentable->axis.mat;
  idEntity::SetOrigin(this: *(idEntity **)&result[8].name.baseBuffer[12], org: p_origin);
  v10 = *(_DWORD *)&result[8].name.baseBuffer[12];
  v11 = *(float **)(v10 + 488);
  if ( v11 == nullptr )
  {
    idEntity::InitPresentableInternal(this: *(idEntity **)&result[8].name.baseBuffer[12]);
    v11 = *(float **)(v10 + 488);
  }
  v11[30] = p_origin->x;
  v11[31] = p_origin->y;
  v11[32] = p_origin->z;
  (*(void (__fastcall **)(_DWORD, idVec3 *))(**(_DWORD **)&result[8].name.baseBuffer[12] + 248))(
    a1: *(_DWORD *)&result[8].name.baseBuffer[12],
    a2: mat);
  v12 = *(_DWORD *)&result[8].name.baseBuffer[12];
  v13 = *(float **)(v12 + 488);
  if ( v13 == nullptr )
  {
    idEntity::InitPresentableInternal(this: *(idEntity **)&result[8].name.baseBuffer[12]);
    v13 = *(float **)(v12 + 488);
  }
  v13[33] = mat->x;
  v13[34] = mat->y;
  v13[35] = mat->z;
  v13[36] = mat[1].x;
  v13[37] = mat[1].y;
  v13[38] = mat[1].z;
  v13[39] = mat[2].x;
  v13[40] = mat[2].y;
  v13[41] = mat[2].z;
  v14 = *(_DWORD *)(*(_DWORD *)&result[8].name.baseBuffer[12] + 488);
  if ( v14 != 0 )
    v15 = (const idAngles *)(*(int (__fastcall **)(int))(*(_DWORD *)v14 + 104))(a1: v14);
  else
    v15 = nullptr;
  idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)v23, result: v15, includeWeaponKick: true);
  v16 = idVec3::ToYaw(this: mat);
  v17 = *(_DWORD *)&result[8].name.baseBuffer[12];
  v23[0].yaw = v16;
  v23[0].pitch = 0.0;
  v18 = *(_DWORD *)(v17 + 488);
  if ( v18 != 0 )
    v19 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v18 + 104))(a1: v18);
  else
    v19 = nullptr;
  idPresentablePlayer::SetViewAngles(this: v19, angles: v23, force: true);
  v20 = *(_DWORD *)(*(_DWORD *)&result[8].name.baseBuffer[12] + 488);
  if ( v20 != 0 )
  {
    v21 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v20 + 104))(a1: v20);
    idPresentablePlayer::CalculateView(this: v21);
  }
  else
  {
    idPresentablePlayer::CalculateView(this: nullptr);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_LeftFoot@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF11F0
// RVA : 0x00BF11F0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_LeftFoot(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_LeftFoot", str);
  }
  idActor::PlayFootStepEffect(this: *(idActor **)&result[6436], footstepType: FOOTSTEP_LEFT_FOOT);
  return this;
}


// ========================================================================
// ?AnimEvent_RightFoot@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1280
// RVA : 0x00BF1280
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_RightFoot(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_RightFoot", str);
  }
  idActor::PlayFootStepEffect(this: *(idActor **)&result[6436], footstepType: FOOTSTEP_RIGHT_FOOT);
  return this;
}


// ========================================================================
// ?AnimEvent_LeftRearFoot@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1310
// RVA : 0x00BF1310
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_LeftRearFoot(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_LeftRearFoot", str);
  }
  idActor::PlayFootStepEffect(this: *(idActor **)&result[6436], footstepType: FOOTSTEP_LEFT_REAR_FOOT);
  return this;
}


// ========================================================================
// ?AnimEvent_RightRearFoot@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF13A0
// RVA : 0x00BF13A0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_RightRearFoot(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_RightRearFoot", str);
  }
  idActor::PlayFootStepEffect(this: *(idActor **)&result[6436], footstepType: FOOTSTEP_RIGHT_REAR_FOOT);
  return this;
}


// ========================================================================
// ?AnimEvent_Land@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1430
// RVA : 0x00BF1430
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_Land(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_Land", str);
  }
  idActor::PlayFootStepEffect(this: *(idActor **)&result[6436], footstepType: FOOTSTEP_LAND);
  return this;
}


// ========================================================================
// ?AnimEvent_LeftFootLadder@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF14C0
// RVA : 0x00BF14C0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_LeftFootLadder(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_LeftFootLadder", str);
  }
  idActor::PlayFootStepEffect(this: *(idActor **)&result[6436], footstepType: FOOTSTEP_LEFT_FOOT_LADDER);
  return this;
}


// ========================================================================
// ?AnimEvent_RightFootLadder@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1550
// RVA : 0x00BF1550
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_RightFootLadder(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_RightFootLadder", str);
  }
  idActor::PlayFootStepEffect(this: *(idActor **)&result[6436], footstepType: FOOTSTEP_RIGHT_FOOT_LADDER);
  return this;
}


// ========================================================================
// ?AnimEvent_LegsCrossing@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF15E0
// RVA : 0x00BF15E0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_LegsCrossing(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v5; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v5 = ((int (__fastcall *)(idGameLocal *, eventVoid *))gameLocal->GetGameFrame)(a1: gameLocal, a2: result);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v5, "idAlignedEntity::AnimEvent_LegsCrossing", str);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_AnimStartBlendOut@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1678
// RVA : 0x00BF1678
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AnimStartBlendOut(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_AnimStartBlendOut", str);
  }
  result[6288] = (eventVoid)1;
  return this;
}


// ========================================================================
// ?AnimEvent_AdditiveAnimStartBlendOut@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1708
// RVA : 0x00BF1708
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AdditiveAnimStartBlendOut(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_AdditiveAnimStartBlendOut", str);
  }
  result[6320] = (eventVoid)1;
  return this;
}


// ========================================================================
// ?AnimEvent_Unbind@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1798
// RVA : 0x00BF1798
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_Unbind(
        idAlignedEntity *this,
        idEntity *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3
  idEntity *v7; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = idAccolade::Count(this: &clientGame->gameTimeManager);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_Unbind", str);
  }
  v7 = *(idEntity **)&result[8].name.baseBuffer[12];
  if ( v7 == nullptr )
    v7 = result;
  idEntity::Unbind(this: v7);
  return this;
}


// ========================================================================
// ?AnimEvent_SwitchLedge@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1830
// RVA : 0x00BF1830
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SwitchLedge(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  idPlayer *v4; // r3
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r31
  idAlignedEntity *v6; // r3
  bool v7; // zf
  int nextLedgeBit; // r11

  v4 = *(idPlayer **)&result[6436];
  p_contextualShimmy = &v4->behaviors.contextualShimmy;
  v7 = !idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this: v4);
  v6 = this;
  if ( !v7 )
  {
    nextLedgeBit = p_contextualShimmy->nextLedgeBit;
    if ( nextLedgeBit != -1 )
    {
      p_contextualShimmy->currentLedgeBit = nextLedgeBit;
      p_contextualShimmy->nextLedgeBit = -1;
    }
  }
  return v6;
}


// ========================================================================
// ?AnimEvent_SprintSlideStartLoopingSlideSound@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1898
// RVA : 0x00BF1898
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SprintSlideStartLoopingSlideSound(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = idAccolade::Count(this: &clientGame->gameTimeManager);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_SprintSlideStartLoopingSlideSound", str);
  }
  *(_BYTE *)(*(_DWORD *)&result[6436] + 11147) = 1;
  return this;
}


// ========================================================================
// ?AnimEvent_SprintSlideStopLoopingSlideSound@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF1928
// RVA : 0x00BF1928
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SprintSlideStopLoopingSlideSound(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = idAccolade::Count(this: &clientGame->gameTimeManager);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_SprintSlideStopLoopingSlideSound", str);
  }
  *(_BYTE *)(*(_DWORD *)&result[6436] + 11147) = 0;
  return this;
}


// ========================================================================
// ?AnimEvent_SprintSlideStop@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF19B8
// RVA : 0x00BF19B8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SprintSlideStop(
        idAlignedEntity *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = idAccolade::Count(this: &clientGame->gameTimeManager);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_SprintSlideStop", str);
  }
  idPlayer::PlayerBehavior_SprintSlide_ForceEndSlide(this: *(idPlayer **)&result[6436]);
  return this;
}


// ========================================================================
// ?GetAnimatedAttachmentHandle@idAlignedEntity@@QAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PBD0@Z
// EA  : 0x82BF1A40
// RVA : 0x00BF1A40
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::GetAnimatedAttachmentHandle(
        idAlignedEntity *this,
        idAnimatedEntity *result,
        const char *propName,
        const char *tagName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idIndex<short,enum invalidJointIndex_t> *v9; // r29
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *Tag; // r3
  idAnimatedEntity *v13; // r3
  idAttachmentCollection *(__fastcall *GetAttachments_2)(struct idAnimatedEntity *); // ctr
  idIndex<short,enum invalidJointIndex_t> *v15; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v16; // r3
  int list; // r11
  unsigned __int16 v19; // [sp+50h] [-40h] BYREF
  idAttachmentCollection v20[3]; // [sp+54h] [-3Ch] BYREF

  if ( propName != nullptr
    && tagName != nullptr
    && (TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result),
        v9 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable,
        TreeAnimatorFromPresentable != nullptr) )
  {
    decl = TreeAnimatorFromPresentable->decl;
    p_props = &decl->props;
    if ( decl == nullptr )
      p_props = nullptr;
    Tag = idPropsCollection::GetTag(this: p_props, propName, tagName);
    idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v19, result: v9, jointHandle: &Tag->parentJoint);
    v13 = result;
    GetAttachments_2 = result->GetAttachments_2;
    v15 = (idIndex<short,enum invalidJointIndex_t> *)v19;
    v16 = (idHandle<int,enum invalidAttachment_t,-1> *)GetAttachments_2(this: v13);
    idAttachmentCollection::FindAttachment(this: v20, result: v16, modelName: propName, jointIndex: v15);
    list = (int)v20[0].attachments.list;
    if ( v20[0].attachments.list == (idAttachment *)-1 )
    {
      idLib::Warning(
        fmt: "%s - no attachment with prop %s - tag %s.",
        "idAlignedEntity::GetAnimatedAttachmentHandle",
        propName,
        tagName);
      this->__vftable = (idAlignedEntity_vtbl *)-1;
      return this;
    }
  }
  else
  {
    list = -1;
  }
  this->__vftable = (idAlignedEntity_vtbl *)list;
  return this;
}


// ========================================================================
// ?AnimEvent_AnimatedAttachment_Show@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD1@Z
// EA  : 0x82BF1B30
// RVA : 0x00BF1B30
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AnimatedAttachment_Show(
        idAlignedEntity *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        const char *propName,
        const char *tagName)
{
  idAttachmentCollection *v7; // r3
  idHandle<int,enum invalidAttachment_t,-1> v9[2]; // [sp+50h] [-20h] BYREF

  idAlignedEntity::GetAnimatedAttachmentHandle(this: (idAlignedEntity *)v9, result, propName, tagName);
  if ( v9[0].value != -1 )
  {
    v7 = result->GetAttachments_2(this: result);
    idAttachmentCollection::ShowAttachment(this: v7, handle: v9);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_AnimatedAttachment_Hide@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD1@Z
// EA  : 0x82BF1BA0
// RVA : 0x00BF1BA0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AnimatedAttachment_Hide(
        idAlignedEntity *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        const char *propName,
        const char *tagName)
{
  idAttachmentCollection *v7; // r3
  idHandle<int,enum invalidAttachment_t,-1> v9[2]; // [sp+50h] [-20h] BYREF

  idAlignedEntity::GetAnimatedAttachmentHandle(this: (idAlignedEntity *)v9, result, propName, tagName);
  if ( v9[0].value != -1 )
  {
    v7 = result->GetAttachments_2(this: result);
    idAttachmentCollection::HideAttachment(this: v7, handle: v9, ignoreShowAll: false);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_AnimatedAttachment_PlayAnim@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD11H@Z
// EA  : 0x82BF1C18
// RVA : 0x00BF1C18
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AnimatedAttachment_PlayAnim(
        idAlignedEntity *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        const char *propName,
        const char *tagName,
        const char *animAlias,
        int loop)
{
  char v9; // [sp+50h] [-20h] BYREF

  idAlignedEntity::GetAnimatedAttachmentHandle(this: (idAlignedEntity *)&v9, result, propName, tagName);
  return this;
}


// ========================================================================
// ?IsCurAnimDone@idAlignedEntity@@QAA_NH_N@Z
// EA  : 0x82BF1D10
// RVA : 0x00BF1D10
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

BOOL __fastcall idAlignedEntity::IsCurAnimDone(idAlignedEntity *this, int numFramesAhead, bool ignoreQueuedAnims)
{
  int valueInteger; // r30
  int v6; // r28
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // [sp+8h] [-78h]
  int v14; // [sp+Ch] [-74h]
  int v15; // [sp+10h] [-70h]
  int v16; // [sp+14h] [-6Ch]
  int v17; // [sp+18h] [-68h]
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v18; // [sp+1Ch] [-64h]

  valueInteger = numFramesAhead;
  if ( numFramesAhead < 0 )
    valueInteger = alignedEnt_animIsDoneFrames.valueInteger;
  if ( this->baseAnimInfo.curAliasHandle.value != 0xFFFF )
  {
    v6 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    if ( this->baseAnimInfo.startTime >= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v6 )
      return false;
  }
  v9 = this->IsAnimating(this);
  if ( v9 == 0 )
    return true;
  if ( !ignoreQueuedAnims && this->baseAnimInfo.queuedAnims.num != 0 )
    return false;
  return idAlignedEntity::IsAnimDone(
           this,
           aliasHandle: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)this->baseAnimInfo.curAliasHandle.value,
           numFramesAhead: valueInteger,
           a4: v12,
           a5: v11,
           a6: v10,
           a7: v9,
           a8: v8,
           a9: v13,
           a10: v14,
           a11: v15,
           a12: v16,
           a13: v17,
           a14: v18);
}


// ========================================================================
// ?ApplyOriginDeltas@idAlignedEntity@@QAAX_N@Z
// EA  : 0x82BF1E00
// RVA : 0x00BF1E00
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::ApplyOriginDeltas(idAlignedEntity *this, bool clip)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r29
  int valueInteger; // r30
  double v6; // fp7
  double v7; // fp6
  idQuat *v8; // r3
  double y; // fp1
  double z; // fp9
  double v11; // fp10
  double v12; // fp8
  double v13; // fp7
  idMat3 *v14; // r3
  idMat3 *v15; // r3
  float *v16; // r3
  double x; // fp0
  double v18; // fp9
  double v19; // fp13
  double v20; // fp8
  double v21; // fp7
  double v22; // fp12
  double v23; // fp11
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  idPhysics *v26; // r30
  idPhysics *v27; // r3
  int entityNumber; // r30
  int (__fastcall *GetClipMask)(idPhysics *, int); // ctr
  int v30; // r3
  idVec3 v31; // [sp+50h] [-230h] BYREF
  idVec3 v32; // [sp+60h] [-220h] BYREF
  idMat3 v33; // [sp+70h] [-210h] BYREF
  float v34; // [sp+94h] [-1ECh]
  float v35; // [sp+98h] [-1E8h]
  idMat3 v36; // [sp+A0h] [-1E0h] BYREF
  idVec3 v37; // [sp+C8h] [-1B8h] BYREF
  idVec3 v38; // [sp+D8h] [-1A8h] BYREF
  idMat3 v39; // [sp+F0h] [-190h] BYREF
  idQuat v40; // [sp+120h] [-160h] BYREF
  idVec3 v41; // [sp+130h] [-150h] BYREF
  float v42; // [sp+13Ch] [-144h]
  idQuat v43; // [sp+140h] [-140h] BYREF
  idQuat v44; // [sp+150h] [-130h] BYREF
  idMat3 v45; // [sp+160h] [-120h] BYREF
  idVec3 v46[2]; // [sp+188h] [-F8h] BYREF
  trace_t v47; // [sp+1A0h] [-E0h] BYREF
  idMat3 v48; // [sp+220h] [-60h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    this->GetModelTransform(this, a2: &v32, a3: &v39);
    valueInteger = alignedEnt_traceOriginDeltas.valueInteger;
    if ( alignedEnt_traceOriginDeltas.valueInteger != 0 )
    {
      idTreeAnimator::GetLastOriginDeltas(this: TreeAnimatorFromPresentable, rot: &v45, trans: &v37);
      if ( valueInteger == 1 || valueInteger == 3 )
        idLib::Printf(
          fmt: "%s: <%s> deltaTrans=(%0.2f,%0.2f,%0.2f)\n",
          "idAlignedEntity::ApplyOriginDeltas",
          this->name.data,
          v37.x,
          v37.y,
          v37.z);
      if ( valueInteger == 2 || valueInteger == 3 )
      {
        idMat3::ToAngles(this: &v33, result: (idAngles *)&v45);
        idLib::Printf(
          fmt: "%s: <%s> deltaAngles=(%0.2f,%0.2f,%0.2f)\n",
          "idAlignedEntity::ApplyOriginDeltas",
          this->name.data,
          v33.mat[0].x,
          v33.mat[0].y,
          v33.mat[0].z);
      }
    }
    if ( alignedEnt_useTAanimDeltaLogic.valueInteger != 0 )
    {
      v33.mat[1].y = 1.0;
      v33.mat[1].z = 1.0;
      v33.mat[2].x = 1.0;
      idTreeAnimator::ApplyOriginDeltas(
        this: TreeAnimatorFromPresentable,
        axis: &v39,
        origin: &v32,
        outAxis: &v36,
        outOrigin: &v31,
        extraScale: (const idVec3 *)&v33.mat[1].y);
    }
    else
    {
      idTreeAnimator::GetTotalOriginTransform(this: TreeAnimatorFromPresentable, rot: &v40, trans: v46);
      idTreeAnimator::GetLastOriginDeltas(this: TreeAnimatorFromPresentable, rot: &v43, trans: &v38);
      v6 = (float)(TreeAnimatorFromPresentable->g.scale.y * v38.y);
      v7 = (float)(TreeAnimatorFromPresentable->g.scale.z * v38.z);
      v33.mat[0].x = TreeAnimatorFromPresentable->g.scale.x * v38.x;
      v33.mat[0].y = v6;
      v33.mat[0].z = v7;
      v8 = idQuat::Inverse(this: &v44, result: &v43);
      y = v8->y;
      z = v8->z;
      v11 = (float)((float)(v8->z * v40.y) + (float)((float)(v8->w * v40.x) + (float)(v8->x * v40.w)));
      v12 = (float)((float)(v8->w * v40.y) + (float)((float)(v8->y * v40.w) + (float)(v8->x * v40.z)));
      v13 = (float)-(float)((float)(v8->y * v40.y) - (float)((float)(v8->w * v40.w) - (float)(v8->x * v40.x)));
      v41.z = -(float)((float)(v8->x * v40.y)
                     - (float)((float)(v8->z * v40.w) + (float)((float)(v8->y * v40.x) + (float)(v8->w * v40.z))));
      v41.x = -(float)((float)((float)y * v40.z) - (float)v11);
      v41.y = -(float)((float)((float)z * v40.x) - (float)v12);
      v42 = -(float)((float)((float)z * v40.z) - (float)v13);
      idQuat::operator*(this: (idQuat *)&v33.mat[2].z, result: &v41, a: v33.mat);
      v31.x = (float)((float)(v39.mat[0].x * v33.mat[2].z)
                    + (float)((float)(v39.mat[1].x * v34) + (float)(v39.mat[2].x * v35)))
            + v32.x;
      v31.y = v32.y
            + (float)((float)(v39.mat[0].y * v33.mat[2].z)
                    + (float)((float)(v39.mat[1].y * v34) + (float)(v39.mat[2].y * v35)));
      v31.z = v32.z
            + (float)((float)(v39.mat[0].z * v33.mat[2].z)
                    + (float)((float)(v39.mat[1].z * v34) + (float)(v39.mat[2].z * v35)));
      v14 = (idMat3 *)idQuat::Inverse(this: &v44, result: &v43);
      v15 = idQuat::ToMat3(this: (idQuat *)&v45, result: v14);
      v16 = (float *)idMat3::operator*(this: &v48, result: v15, a: &v39);
      v36.mat[0].x = *v16;
      v36.mat[0].y = v16[1];
      v36.mat[0].z = v16[2];
      v36.mat[1].x = v16[3];
      v36.mat[1].y = v16[4];
      v36.mat[1].z = v16[5];
      v36.mat[2].x = v16[6];
      v36.mat[2].y = v16[7];
      v36.mat[2].z = v16[8];
      idMat3::OrthoNormalizeSelf(this: &v36);
    }
    this->deltaTransScale.z = 1.0;
    x = v31.x;
    v18 = v32.x;
    this->deltaTransScale.y = 1.0;
    v19 = (float)((float)x - (float)v18);
    this->deltaTransScale.x = 1.0;
    v20 = v32.y;
    v21 = v32.z;
    v22 = (float)(v31.y - v32.y);
    v23 = (float)(v31.z - v32.z);
    if ( (float)((float)(this->deltaTransExternalWorld.z * this->deltaTransExternalWorld.z)
               + (float)((float)(this->deltaTransExternalWorld.x * this->deltaTransExternalWorld.x)
                       + (float)(this->deltaTransExternalWorld.y * this->deltaTransExternalWorld.y))) != 0.0 )
    {
      v19 = (float)(this->deltaTransExternalWorld.x + (float)((float)x - (float)v18));
      v22 = (float)((float)(v31.y - v32.y) + this->deltaTransExternalWorld.y);
      v23 = (float)(this->deltaTransExternalWorld.z + (float)(v31.z - v32.z));
      this->deltaTransExternalWorld = vec3_origin;
    }
    v31.x = (float)v19 + (float)v18;
    v31.y = (float)v22 + (float)v20;
    v31.z = (float)v23 + (float)v21;
    if ( clip )
    {
      Physics = idEntity::GetPhysics(this: this->owner);
      presentable = this->presentable;
      v26 = Physics;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      v27 = v26;
      GetClipMask = v26->GetClipMask;
      entityNumber = presentable->entityNumber;
      v30 = GetClipMask(this: v27, a2: -1);
      if ( idClip::TracePoint(
             this: &clientGame->clip,
             result: &v47,
             start: &v32,
             end: &v31,
             clipMask: v30,
             passEntityNumber: entityNumber) )
      {
        v31.x = v47.c.point.x;
        v31.y = v47.c.point.y;
        v31.z = v47.c.point.z;
      }
    }
    this->SetAxis(this, a2: &v36);
    this->SetOrigin(this, a2: &v31);
  }
}


// ========================================================================
// ?PlayAdditiveAnim@idAlignedEntity@@QAA_NABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHPBVblendParms_t@@@Z
// EA  : 0x82BF22A0
// RVA : 0x00BF22A0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

int __fastcall idAlignedEntity::PlayAdditiveAnim(
        idAlignedEntity *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        bool loop,
        int durationMS,
        const blendParms_t *_blendParms)
{
  char *v10; // r10
  char *p_flags; // r11
  int i; // ctr
  int v13; // r30
  char v15; // [sp+4Ch] [-54h] BYREF
  blendParms_t v16[4]; // [sp+50h] [-50h] BYREF

  blendParms_t::blendParms_t(this: v16);
  if ( _blendParms != nullptr )
  {
    v10 = &v15;
    p_flags = &_blendParms[-1].parms.flags;
    for ( i = 5; i != 0; --i )
    {
      p_flags += 4;
      v10 += 4;
      *(_DWORD *)v10 = *(_DWORD *)p_flags;
    }
  }
  else
  {
    blendParms_t::SetDuration(this: v16, frame: alignedEnt_defaultBlendDurationFrames.valueInteger);
  }
  v13 = idAlignedEntity::InternalPlayAnim(
          this,
          channelAnimator: &this->additiveAnimator,
          animInfo: &this->additiveAnimInfo,
          aliasHandle,
          loop,
          durationMS,
          blendParms: v16,
          rateScale: 1.0);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->additiveAnimInfo.queuedAnims);
  this->additiveAnimInfo.startBlendOut = false;
  if ( (_BYTE)v13 != 0 )
  {
    idEntity::BecomeActive(this, flags: 4);
    idEntity::BecomeActive(this, flags: 1);
  }
  return v13;
}


// ========================================================================
// ?UpdateOwnerFromCamera@idAlignedEntity@@QAAX_N0000@Z
// EA  : 0x82BF2370
// RVA : 0x00BF2370
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::UpdateOwnerFromCamera(
        idAlignedEntity *this,
        bool updatePosition,
        bool updateOrientation,
        bool updateVelocityFromPhysics,
        bool updateVelocityFromCamera,
        bool clipMove)
{
  idPlayer *owner; // r11
  idSpringCamera *springCamera; // r28
  BOOL v13; // r25
  idPresentable *presentable; // r3
  const idAngles *v15; // r4
  float y; // r10
  float z; // r9
  idPlayer *v18; // r3
  idPhysics *Physics; // r3
  double valueFloat; // fp31
  float *v21; // r3
  double v22; // fp31
  double v23; // fp30
  double v24; // fp29
  idPhysics *v25; // r3
  float *v26; // r3
  double v27; // fp1
  double v28; // fp11
  double v29; // fp12
  idPlayer *v30; // r3
  idPhysics_Player *PhysicsObj; // r3
  float *v32; // r3
  idPlayer *v33; // r11
  idPresentable *v34; // r3
  idPresentablePlayer *v35; // r3
  char *v36; // r10
  idSpringCamera *p_z; // r11
  int i; // ctr
  idPhysics_Player *v39; // r3
  int v40; // r3
  char *v41; // r10
  _DWORD *v42; // r11
  int j; // ctr
  const idMat3 *v44; // r3
  float *v45; // r3
  idPlayer *v46; // r3
  idPhysics_Player *v47; // r3
  idMat3 v48; // [sp+50h] [-160h] BYREF
  float x; // [sp+74h] [-13Ch]
  float v50; // [sp+78h] [-138h]
  float v51; // [sp+7Ch] [-134h]
  int v52; // [sp+80h] [-130h]
  char v53; // [sp+8Ch] [-124h] BYREF
  idMat3 v54; // [sp+90h] [-120h] BYREF
  idAngles v55; // [sp+B8h] [-F8h] BYREF
  char v56; // [sp+CCh] [-E4h] BYREF
  idMat3 v57; // [sp+D0h] [-E0h] BYREF
  idMat3 v58; // [sp+100h] [-B0h] BYREF
  idMat3 v59; // [sp+130h] [-80h] BYREF

  owner = this->owner;
  springCamera = owner->springCamera;
  if ( springCamera != nullptr )
  {
    v13 = updatePosition;
    if ( updatePosition )
    {
      presentable = owner->presentable;
      if ( presentable != nullptr )
        v15 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
      else
        v15 = nullptr;
      idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)&v55, result: v15, includeWeaponKick: true);
      y = springCamera->viewOrigin.y;
      z = springCamera->viewOrigin.z;
      v18 = this->owner;
      v48.mat[0].x = springCamera->viewOrigin.x;
      v48.mat[0].y = y;
      v48.mat[0].z = z;
      Physics = idEntity::GetPhysics(this: v18);
      valueFloat = pm_normalviewheight.valueFloat;
      v21 = (float *)Physics->GetGravityNormal(this: Physics);
      v23 = (float)(v48.mat[0].y + (float)(v21[1] * (float)valueFloat));
      v24 = (float)(v48.mat[0].z + (float)(v21[2] * (float)valueFloat));
      v22 = (float)(v48.mat[0].x + (float)((float)valueFloat * *v21));
      v25 = idEntity::GetPhysics(this: this->owner);
      v26 = (float *)v25->GetOrigin(this: v25, a2: 0);
      v27 = (float)((float)v23 - v26[1]);
      v28 = (float)((float)v24 - v26[2]);
      v48.mat[1].y = (float)v22 - *v26;
      x = vec3_origin.x;
      v52 = 0x1FFF;
      v29 = vec3_origin.z;
      HIBYTE(v48.mat[2].y) = clipMove;
      v50 = vec3_origin.y;
      v51 = vec3_origin.z;
      v48.mat[1].z = v27;
      v48.mat[2].x = v28;
      if ( updateVelocityFromPhysics )
      {
        v30 = this->owner;
        LODWORD(v48.mat[2].z) = 1;
        PhysicsObj = idPlayer::GetPhysicsObj(this: v30);
        v32 = (float *)PhysicsObj->GetLinearVelocity(
                         this: (struct idPhysics_Player *)&v48,
                         result: (idVec3 *)PhysicsObj,
                         a3: 0);
        x = *v32;
        v50 = v32[1];
        v29 = v32[2];
      }
      else
      {
        LODWORD(v48.mat[2].z) = 1;
        if ( updateVelocityFromCamera )
        {
          x = springCamera->viewVelocity.x;
          v50 = springCamera->viewVelocity.y;
          v29 = springCamera->viewVelocity.z;
        }
        else
        {
          x = vec3_origin.x;
          v50 = vec3_origin.y;
        }
      }
      v33 = this->owner;
      v51 = v29;
      v34 = v33->presentable;
      if ( v34 != nullptr )
        v35 = v34->GetPlayerInterface_2(this: v34);
      else
        v35 = nullptr;
      idPresentablePlayer::SetExplicitMove(
        this: v35,
        move: (const playerExplicitMove_t *)&v48.mat[1].y,
        alsoAllowPhysicsMove: false,
        useExplicitMove2: false);
      idPlayer::SetViewAngles(this: this->owner, angles: &v55, force: false);
    }
    if ( updateOrientation )
    {
      v36 = &v53;
      p_z = (idSpringCamera *)&springCamera->viewOrigin.z;
      for ( i = 9; i != 0; --i )
      {
        p_z = (idSpringCamera *)((char *)p_z + 4);
        v36 += 4;
        *(_DWORD *)v36 = p_z->__vftable;
      }
      if ( idEntity::GetBindMaster(this: this->owner) != nullptr )
      {
        v39 = idPlayer::GetPhysicsObj(this: this->owner);
        v40 = (int)v39->GetGravityAxis(this: v39);
        v41 = &v56;
        v42 = (_DWORD *)(v40 - 4);
        for ( j = 9; j != 0; --j )
        {
          ++v42;
          v41 += 4;
          *(_DWORD *)v41 = *v42;
        }
        v44 = idMat3::Inverse(this: &v58, result: &v57);
        v45 = (float *)idMat3::operator*(this: &v59, result: &v54, a: v44);
        v54.mat[0].x = *v45;
        v54.mat[0].y = v45[1];
        v54.mat[0].z = v45[2];
        v54.mat[1].x = v45[3];
        v54.mat[1].y = v45[4];
        v54.mat[1].z = v45[5];
        v54.mat[2].x = v45[6];
        v54.mat[2].y = v45[7];
        v54.mat[2].z = v45[8];
      }
      idMat3::ToAngles(this: &v48, result: (idAngles *)&v54);
      v46 = this->owner;
      v48.mat[0].z = 0.0;
      idPlayer::SetViewAngles(this: v46, angles: (const idAngles *)&v48, force: true);
    }
    if ( updateVelocityFromCamera && !v13 )
    {
      v47 = idPlayer::GetPhysicsObj(this: this->owner);
      v47->SetLinearVelocity(this: v47, a2: &springCamera->viewVelocity, a3: 0);
    }
  }
}


// ========================================================================
// ?UpdateOwnerToDefaultViewAngles@idAlignedEntity@@QAAX_N00@Z
// EA  : 0x82BF26E0
// RVA : 0x00BF26E0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::UpdateOwnerToDefaultViewAngles(
        idAlignedEntity *this,
        bool updatePosition,
        bool updateVelocityFromPhysics,
        bool updateVelocityFromCamera)
{
  idSpringCamera *springCamera; // r31
  idVec3 *v6; // r10
  float *p_z; // r9
  int i; // ctr
  idPlayer *owner; // r3
  idMat3 v10; // [sp+50h] [-50h] BYREF

  springCamera = this->owner->springCamera;
  if ( springCamera != nullptr )
  {
    idAlignedEntity::UpdateOwnerFromCamera(
      this,
      updatePosition,
      updateOrientation: false,
      updateVelocityFromPhysics,
      updateVelocityFromCamera,
      clipMove: true);
    v6 = &v10.mat[1];
    p_z = &springCamera->viewOrigin.z;
    for ( i = 9; i != 0; --i )
    {
      ++p_z;
      v6 = (idVec3 *)((char *)v6 + 4);
      v6->x = *p_z;
    }
    idMat3::ToAngles(this: &v10, result: (idAngles *)&v10.mat[1].y);
    owner = this->owner;
    v10.mat[0].z = 0.0;
    v10.mat[0].x = 0.0;
    idPlayer::SetViewAngles(this: owner, angles: (const idAngles *)&v10, force: true);
  }
}


// ========================================================================
// ?DetachItems@idAlignedEntity@@QAAXXZ
// EA  : 0x82BF2780
// RVA : 0x00BF2780
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::DetachItems(idAlignedEntity *this)
{
  int v2; // r26
  idList<idAlignedEntity::addedAttachment_t,5> *p_attachmentInfos; // r27
  int v4; // r28
  idAlignedEntity::addedAttachment_t *v5; // r30
  idInventoryItem *attachItem; // r31
  idPresentable *presentable; // r11
  idPresentable *v8; // r31
  idInventoryItem *v9; // r30
  idInventoryCollection *v10; // r3
  int num; // r11
  idAlignedEntity::addedAttachment_t *v12; // r9
  idAlignedEntity::addedAttachment_t *v13; // r8

  v2 = 0;
  if ( this->attachmentInfos.num > 0 )
  {
    p_attachmentInfos = &this->attachmentInfos;
    v4 = 0;
    do
    {
      v5 = &p_attachmentInfos->list[v4];
      if ( v5->attachAutoDetach )
      {
        if ( v5->attachHandle.value != idAttachmentCollection::NULL_ATTACHMENT.value )
          idAttachmentCollection::RemoveAttachment(this: &this->attachmentCollection, handle: &v5->attachHandle);
        attachItem = v5->attachItem;
        if ( attachItem != nullptr )
        {
          idWeapon::CastTo(c: (idWeapon *)v5->attachItem);
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          attachItem->OnUnequip(this: attachItem, a2: presentable, a3: nullptr);
          if ( !v5->noClone )
          {
            v8 = this->presentable;
            if ( v8 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v8 = this->presentable;
            }
            v9 = v5->attachItem;
            v10 = this->GetInventory_2(this);
            idInventoryCollection::DeleteInventoryItem(this: v10, owner: v8, item: v9, count: 1);
          }
        }
        if ( v2 >= 0 )
        {
          num = p_attachmentInfos->num;
          if ( v2 < num )
          {
            p_attachmentInfos->num = num - 1;
            if ( v2 != num - 1 )
            {
              v12 = &p_attachmentInfos->list[num - 1];
              v13 = &p_attachmentInfos->list[v4];
              v13->attachItemDecl = v12->attachItemDecl;
              v13->attachItem = v12->attachItem;
              v13->attachHandle.value = v12->attachHandle.value;
              *(_DWORD *)&v13->attachAutoDetach = *(_DWORD *)&v12->attachAutoDetach;
            }
          }
        }
        --v2;
        --v4;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->attachmentInfos.num );
  }
}


// ========================================================================
// ?AnimEvent_DetachItem@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF28E8
// RVA : 0x00BF28E8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_DetachItem(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_DetachItem", str);
  }
  idAlignedEntity::DetachItems(this: result);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBodyLoopUntilAnimEnd@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF2978
// RVA : 0x00BF2978
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SoundBodyLoopUntilAnimEnd(
        idAlignedEntity *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        idAnimatedEntity_vtbl *shader)
{
  const char *str; // r30
  int v9; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const idMD6Alias *Alias; // r3
  idEntity *v12; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v9 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v9, "idAlignedEntity::AnimEvent_SoundBodyLoopUntilAnimEnd", str);
  }
  if ( *(_DWORD *)&result[1].animStack.leafMemory[86] != 0 )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    Alias = idDeclMD6::FindAlias(
              this: TreeAnimatorFromPresentable->decl,
              aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&result[1].animStack.branchMemory[10],
              includeInherited: true);
    if ( (Alias == nullptr || Alias->animRefs.list->str == animHandle->name.str) && shader != result[1].__vftable )
    {
      v12 = *(idEntity **)&result[1].animStack.leafMemory[86];
      result[1].__vftable = shader;
      if ( shader != nullptr )
      {
        idEntity::StartSoundShader(
          this: v12,
          channel: SND_CHANNEL_BODY,
          (const idSoundShader *)shader,
          soundShaderFlags: 0,
          peerMask: 0xFFu);
        HIWORD(result[1].listenerList) = *(_WORD *)&result[1].animStack.branchMemory[10];
        return this;
      }
      idEntity::StopSound(this: v12, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
      HIWORD(result[1].listenerList) = -1;
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_SetViewAnglesFromCamera@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF2AA0
// RVA : 0x00BF2AA0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SetViewAnglesFromCamera(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_SetViewAnglesFromCamera", str);
  }
  idAlignedEntity::UpdateOwnerFromCamera(
    this: result,
    updatePosition: true,
    updateOrientation: true,
    updateVelocityFromPhysics: true,
    updateVelocityFromCamera: false,
    clipMove: true);
  return this;
}


// ========================================================================
// ?AnimEvent_SetViewAnglesFromCameraExt@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@HHH@Z
// EA  : 0x82BF2B40
// RVA : 0x00BF2B40
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SetViewAnglesFromCameraExt(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle,
        int updateVelocityFromPhysics,
        int updateVelocityFromCamera,
        int clipMove)
{
  const char *str; // r28
  int v12; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v12 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v12, "idAlignedEntity::AnimEvent_SetViewAnglesFromCameraExt", str);
  }
  idAlignedEntity::UpdateOwnerFromCamera(
    this: result,
    updatePosition: true,
    updateOrientation: true,
    updateVelocityFromPhysics: updateVelocityFromPhysics != 0,
    updateVelocityFromCamera: updateVelocityFromCamera != 0,
    clipMove: clipMove != 0);
  return this;
}


// ========================================================================
// ?AnimEvent_SetViewAnglesToDefault@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF2BF8
// RVA : 0x00BF2BF8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_SetViewAnglesToDefault(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle)
{
  const char *str; // r31
  int v6; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v6, "idAlignedEntity::AnimEvent_SetViewAnglesToDefault", str);
  }
  idAlignedEntity::UpdateOwnerToDefaultViewAngles(
    this: result,
    updatePosition: true,
    updateVelocityFromPhysics: true,
    updateVelocityFromCamera: false);
  return this;
}


// ========================================================================
// ?Event_SetViewAnglesFromCamera@idAlignedEntity@@QAA?AVeventVoid@@XZ
// EA  : 0x82BF2C90
// RVA : 0x00BF2C90
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::Event_SetViewAnglesFromCamera(
        idAlignedEntity *this,
        idAlignedEntity *result)
{
  int v4; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    v4 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s\n", v4, "idAlignedEntity::Event_SetViewAnglesFromCamera");
  }
  idAlignedEntity::UpdateOwnerFromCamera(
    this: result,
    updatePosition: true,
    updateOrientation: true,
    updateVelocityFromPhysics: true,
    updateVelocityFromCamera: false,
    clipMove: true);
  return this;
}


// ========================================================================
// ?InternalBecomeInactive@idAlignedEntity@@QAAXXZ
// EA  : 0x82BF2D38
// RVA : 0x00BF2D38
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::InternalBecomeInactive(idAlignedEntity *this)
{
  idAnimator_Channel *p_baseAnimator; // r29
  int v3; // r28
  const idAnimStack *v4; // r3
  int v5; // r28
  const idAnimStack *v6; // r3
  int v7; // r28
  const idAnimStack *v8; // r3
  int v9; // r28
  const idAnimStack *v10; // r3
  int v11; // r28
  const idAnimStack *v12; // r3
  int v13; // r28
  const idAnimStack *v14; // r3
  int v15; // r28
  const idAnimStack *v16; // r3
  int v17; // r28
  const idAnimStack *v18; // r3
  int v19; // r28
  const idAnimStack *v20; // r3
  int v21; // r30
  const idAnimStack *v22; // r3

  p_baseAnimator = &this->baseAnimator;
  v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v4 = this->GetAnimStack_2(this);
  if ( !idAnimator_Channel::IsDone(this: p_baseAnimator, stack: v4, curTime: v3) )
  {
    v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v6 = this->GetAnimStack_2(this);
    idAnimator_Base::End(this: p_baseAnimator, stack: v6, curTime: v5, blendDurationMS: 0, reset: true);
  }
  v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v8 = this->GetAnimStack_2(this);
  if ( (unsigned __int8)idAnimator_Synced::IsDone(this: &this->syncedAnimator, stack: v8, curTime: v7) == 0 )
  {
    v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v10 = this->GetAnimStack_2(this);
    idAnimator_Base::End(this: &this->syncedAnimator, stack: v10, curTime: v9, blendDurationMS: 0, reset: true);
  }
  v11 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v12 = this->GetAnimStack_2(this);
  if ( (unsigned __int8)idAnimator_Synced::IsDone(this: &this->syncedAnimator2, stack: v12, curTime: v11) == 0 )
  {
    v13 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v14 = this->GetAnimStack_2(this);
    idAnimator_Base::End(this: &this->syncedAnimator2, stack: v14, curTime: v13, blendDurationMS: 0, reset: true);
  }
  v15 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v16 = this->GetAnimStack_2(this);
  if ( !idAnimator_Channel::IsDone(this: &this->additiveAnimator, stack: v16, curTime: v15) )
  {
    v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v18 = this->GetAnimStack_2(this);
    idAnimator_Base::End(this: &this->additiveAnimator, stack: v18, curTime: v17, blendDurationMS: 0, reset: true);
  }
  v19 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v20 = this->GetAnimStack_2(this);
  if ( (unsigned __int8)idAnimator_Synced::IsDone(this: &this->additiveSyncedAnimator, stack: v20, curTime: v19) == 0 )
  {
    v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v22 = this->GetAnimStack_2(this);
    idAnimator_Base::End(this: &this->additiveSyncedAnimator, stack: v22, curTime: v21, blendDurationMS: 0, reset: true);
  }
  idEntity::BecomeInactive(this, flags: 4);
  idEntity::BecomeInactive(this, flags: 1);
  idAlignedEntity::DetachItems(this);
}


// ========================================================================
// ?PlayAnim@idAlignedEntity@@QAA_NABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHPBVblendParms_t@@M@Z
// EA  : 0x82BF3070
// RVA : 0x00BF3070
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

int __fastcall idAlignedEntity::PlayAnim(
        idAlignedEntity *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        bool loop,
        int durationMS,
        const blendParms_t *_blendParms,
        double rateScale)
{
  char *data; // r26
  int v13; // r25
  const char *v14; // r3
  char *v15; // r10
  char *p_flags; // r11
  int i; // ctr
  int v18; // r30
  char v20; // [sp+4Ch] [-64h] BYREF
  blendParms_t v21; // [sp+50h] [-60h] BYREF

  if ( aliasHandle->value != 0xFFFF && alignedEnt_traceAnims.valueInteger != 0 )
  {
    data = this->name.data;
    v13 = idAccolade::Count(this: &clientGame->gameTimeManager);
    v14 = animation->FindAliasName(this: animation, a2: aliasHandle);
    idLib::Printf(fmt: "(%d)%s - playing anim <%s> on <%s>\n", v13, "idAlignedEntity::PlayAnim", v14, data);
  }
  blendParms_t::blendParms_t(this: &v21);
  if ( _blendParms != nullptr )
  {
    v15 = &v20;
    p_flags = &_blendParms[-1].parms.flags;
    for ( i = 5; i != 0; --i )
    {
      p_flags += 4;
      v15 += 4;
      *(_DWORD *)v15 = *(_DWORD *)p_flags;
    }
  }
  else
  {
    blendParms_t::SetDuration(this: &v21, frame: alignedEnt_defaultBlendDurationFrames.valueInteger);
  }
  v18 = idAlignedEntity::InternalPlayAnim(
          this,
          channelAnimator: &this->baseAnimator,
          animInfo: &this->baseAnimInfo,
          aliasHandle,
          loop,
          durationMS,
          blendParms: &v21,
          rateScale);
  this->baseAnimInfo.startBlendOut = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->baseAnimInfo.queuedAnims);
  idAlignedEntity::DetachItems(this);
  if ( (_BYTE)v18 != 0 )
  {
    idEntity::BecomeActive(this, flags: 4);
    idEntity::BecomeActive(this, flags: 1);
  }
  return v18;
}


// ========================================================================
// ?StopAnim@idAlignedEntity@@QAAXXZ
// EA  : 0x82BF31D0
// RVA : 0x00BF31D0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::StopAnim(idAlignedEntity *this)
{
  idAnimEventHandler *p_animEventHandler; // r3

  this->baseAnimInfo.startTime = 0;
  this->baseAnimInfo.curAliasHandle.value = -1;
  this->baseAnimInfo.animDurationMS = 0;
  p_animEventHandler = &this->animEventHandler;
  if ( p_animEventHandler != nullptr )
    idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)p_animEventHandler);
  idAlignedEntity::InternalBecomeInactive(this);
}


// ========================================================================
// ?SetExternalTime@idAlignedEntity@@QAAXM@Z
// EA  : 0x82BF3220
// RVA : 0x00BF3220
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::SetExternalTime(idAlignedEntity *this, double normalizedTime)
{
  __int64 v3; // r6
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idMD6LeafPlay *v5; // r31
  double v6; // fp31
  int v7; // r30
  int GameMs; // r3
  __int64 v9; // [sp+50h] [-30h]

  LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->baseAnimator);
  v5 = LastPlayedLeaf;
  if ( LastPlayedLeaf != nullptr )
  {
    v6 = 0.0;
    if ( normalizedTime >= 0.0 )
    {
      v6 = 0.99000001;
      if ( normalizedTime <= 0.99000001 )
        v6 = normalizedTime;
    }
    LODWORD(v3) = LastPlayedLeaf->anim->animData->numFrames - 1;
    v9 = v3;
    v7 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idMD6LeafPlay::SetFloatFrame(
      this: v5,
      gameTime: GameMs,
      ticksPerSec: v7,
      targetFrame: (float)((float)v9 * (float)v6));
  }
}


// ========================================================================
// ?PlayAdditiveAnim@idAlignedEntity@@QAA_NPBD_NHPBVblendParms_t@@@Z
// EA  : 0x82BF3300
// RVA : 0x00BF3300
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

int __fastcall idAlignedEntity::PlayAdditiveAnim(
        idAlignedEntity *this,
        const char *aliasName,
        bool loop,
        int durationMS,
        const blendParms_t *_blendParms)
{
  unsigned __int16 v5; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v13; // [sp+50h] [-40h] BYREF
  unsigned __int16 v14; // [sp+52h] [-3Eh] BYREF

  v5 = -1;
  v13.value = -1;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)&v14, result: TreeAnimatorFromPresentable->decl, aliasName);
    v5 = v14;
    v13.value = v14;
  }
  if ( v5 != 0xFFFF )
    return idAlignedEntity::PlayAdditiveAnim(this, aliasHandle: &v13, loop, durationMS, _blendParms);
  idLib::Warning(
    fmt: "%s - anim <%s> not found in entity <%s>",
    "idAlignedEntity::PlayAdditiveAnim",
    aliasName,
    this->name.data);
  return 0;
}


// ========================================================================
// ?AttachCamera@idAlignedEntity@@QAAXPBDW4duration_t@idSpringCamera@@W4lookMode_t@3@W4blendMode_t@3@HMM@Z
// EA  : 0x82BF33A0
// RVA : 0x00BF33A0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::AttachCamera(
        idAlignedEntity *this,
        const char *jointName,
        idSpringCamera::duration_t durationMode,
        idSpringCamera::lookMode_t lookMode,
        idSpringCamera::blendMode_t blendMode,
        int blendDurationMS,
        double viewConeDeg,
        double autoCenterK)
{
  idSpringCamera *springCamera; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v18; // r3

  springCamera = this->owner->springCamera;
  if ( springCamera != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idSpringCamera::SetFollowTarget(
      this: springCamera,
      entity: this,
      ta: TreeAnimatorFromPresentable,
      jointName,
      duration: durationMode);
    v18 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idSpringCamera::SetLookTarget(
      this: springCamera,
      entity: this,
      ta: v18,
      jointName,
      duration: durationMode,
      mode: lookMode);
    idSpringCamera::SetBlendMode(this: springCamera, mode: blendMode);
    idSpringCamera::SetBlendDurationMS(this: springCamera, blendDurationMS);
    springCamera->constraintConeDegs = viewConeDeg;
    idSpring<idVec3>::SetConstants(this: &springCamera->springAutoCenter, _k: autoCenterK, _c: -1.0);
    idCamera::Activate(this: springCamera, activator_: this->owner);
  }
}


// ========================================================================
// ?AnimEvent_AttachCamera@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@HHH@Z
// EA  : 0x82BF3470
// RVA : 0x00BF3470
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AttachCamera(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle,
        const idJointName *jointName,
        idSpringCamera::duration_t durationMode,
        idSpringCamera::lookMode_t lookMode,
        idSpringCamera::blendMode_t blendMode)
{
  const char *str; // r28
  int v14; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v14 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "^7(%d)%s (%d,%d,%d) - '^2%s^7'\n",
      v14,
      "idAlignedEntity::AnimEvent_AttachCamera",
      durationMode,
      lookMode,
      blendMode,
      str);
  }
  idAlignedEntity::AttachCamera(
    this: result,
    jointName: jointName->data,
    durationMode,
    lookMode,
    blendMode,
    blendDurationMS: -1,
    viewConeDeg: 0.0,
    autoCenterK: 1.0);
  return this;
}


// ========================================================================
// ?AnimEvent_AttachCameraExt@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@HHHH@Z
// EA  : 0x82BF3540
// RVA : 0x00BF3540
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AttachCameraExt(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle,
        const idJointName *jointName,
        idSpringCamera::duration_t durationMode,
        idSpringCamera::lookMode_t lookMode,
        idSpringCamera::blendMode_t blendMode,
        int blendDurationMS)
{
  const char *str; // r28
  int v16; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v16 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "^7(%d)%s (%d,%d,%d) - '^2%s^7'\n",
      v16,
      "idAlignedEntity::AnimEvent_AttachCameraExt",
      durationMode,
      lookMode,
      blendMode,
      str);
  }
  idAlignedEntity::AttachCamera(
    this: result,
    jointName: jointName->data,
    durationMode,
    lookMode,
    blendMode,
    blendDurationMS,
    viewConeDeg: 0.0,
    autoCenterK: 1.0);
  return this;
}


// ========================================================================
// ?AnimEvent_AttachLimitViewCamera@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@HMM@Z
// EA  : 0x82BF3610
// RVA : 0x00BF3610
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AttachLimitViewCamera(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle,
        const idJointName *jointName,
        idSpringCamera::blendMode_t blendMode,
        double viewConeDeg,
        double autoCenterK)
{
  int v13; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    v13 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "^7(%d)%s (%d,%d,%d,%4.3f) - '^2%s^7'\n",
      v13,
      "idAlignedEntity::AnimEvent_AttachLimitViewCamera",
      1,
      4,
      blendMode,
      viewConeDeg,
      (const char *)LODWORD(viewConeDeg));
  }
  if ( viewConeDeg <= 0.0 )
  {
    idLib::Warning(
      fmt: "%s - invalid View Cone Degrees defined in anim event - Defaulting to %4.3f",
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(alignedEnt_defaultCameraViewConeDeg.valueFloat)),
      (unsigned int)COERCE_UNSIGNED_INT64(alignedEnt_defaultCameraViewConeDeg.valueFloat));
    viewConeDeg = alignedEnt_defaultCameraViewConeDeg.valueFloat;
  }
  if ( autoCenterK <= 0.0 )
  {
    idLib::Warning(
      fmt: "%s - invalid Auto Center K defined in anim event - Defaulting to 1.0",
      "idAlignedEntity::AnimEvent_AttachLimitViewCamera");
    autoCenterK = 1.0;
  }
  idAlignedEntity::AttachCamera(
    this: result,
    jointName: jointName->data,
    durationMode: DURATION_ALWAYS,
    lookMode: LOOK_ADD_HEADING_AUTOCENTER,
    blendMode,
    blendDurationMS: -1,
    viewConeDeg,
    autoCenterK);
  return this;
}


// ========================================================================
// ?Event_AttachLimitViewCamera@idAlignedEntity@@QAA?AVeventVoid@@ABVidJointName@@HHMM@Z
// EA  : 0x82BF3750
// RVA : 0x00BF3750
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::Event_AttachLimitViewCamera(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idJointName *jointName,
        idSpringCamera::lookMode_t lookMode,
        idSpringCamera::blendMode_t blendMode,
        double viewConeDeg,
        double autoCenterK)
{
  int v14; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    v14 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "^7(%d)%s (%d,%d,%d,%4.3f)\n",
      v14,
      "idAlignedEntity::Event_AttachLimitViewCamera",
      1,
      4,
      blendMode,
      viewConeDeg);
  }
  if ( viewConeDeg <= 0.0 )
  {
    idLib::Warning(
      fmt: "%s - invalid View Cone Degrees defined in anim event - Defaulting to %4.3f",
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(alignedEnt_defaultCameraViewConeDeg.valueFloat)),
      (unsigned int)COERCE_UNSIGNED_INT64(alignedEnt_defaultCameraViewConeDeg.valueFloat));
    viewConeDeg = alignedEnt_defaultCameraViewConeDeg.valueFloat;
  }
  if ( autoCenterK <= 0.0 )
  {
    idLib::Warning(
      fmt: "%s - invalid Auto Center K defined in anim event - Defaulting to 1.0",
      "idAlignedEntity::Event_AttachLimitViewCamera");
    autoCenterK = 1.0;
  }
  idAlignedEntity::AttachCamera(
    this: result,
    jointName: jointName->data,
    durationMode: DURATION_ALWAYS,
    lookMode,
    blendMode,
    blendDurationMS: -1,
    viewConeDeg,
    autoCenterK);
  return this;
}


// ========================================================================
// ?Spawn@idAlignedEntity@@QAAXXZ
// EA  : 0x82BF3938
// RVA : 0x00BF3938
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::Spawn(idAlignedEntity *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r27
  int v3; // r29
  idAnimStack *v4; // r3
  const idStr *v5; // r27
  const idStr *v6; // r3
  char *data; // r27
  idGameTimeManager *v8; // r3
  const idStr *v9; // r26
  const idStr *v10; // r3
  char *v11; // r26
  idGameTimeManager *v12; // r3
  const idStr *v13; // r26
  const idStr *v14; // r3
  char *v15; // r26
  idGameTimeManager *v16; // r3
  const idStr *v17; // r27
  const idStr *v18; // r3
  char *v19; // r27
  idGameTimeManager *v20; // r3
  const idStr *v21; // r26
  const idStr *v22; // r3
  char *v23; // r26
  idGameTimeManager *v24; // r3
  idPhysics *Physics; // r3
  int v26; // r27
  idTreeAnimator *v27; // r3
  int i; // r26
  idEntityAttachmentDef *v29; // r28
  const idDeclEntityDef *entityDef; // r27
  const char *v31; // r25
  idHandle<int,enum invalidAttachment_t,-1> *v32; // r3
  idAttachmentCollection *v33; // r3
  idAttachmentCollection v34; // [sp+50h] [-380h] BYREF
  idStr v35; // [sp+64h] [-36Ch] BYREF
  int v36; // [sp+84h] [-34Ch]
  int v37; // [sp+88h] [-348h]
  int v38; // [sp+8Ch] [-344h]
  int v39; // [sp+90h] [-340h]
  float v40; // [sp+94h] [-33Ch]
  idAnimatorParms_Base v41; // [sp+A0h] [-330h] BYREF
  idAnimatorParms_Base v42; // [sp+E0h] [-2F0h] BYREF
  idAnimatorParms_Base v43; // [sp+120h] [-2B0h] BYREF
  idAnimatorParms_Base v44; // [sp+160h] [-270h] BYREF
  idStr v45; // [sp+1A0h] [-230h] BYREF
  idStr v46; // [sp+1C0h] [-210h] BYREF
  idStr v47; // [sp+1E0h] [-1F0h] BYREF
  idStr v48; // [sp+200h] [-1D0h] BYREF
  idStr v49; // [sp+220h] [-1B0h] BYREF
  idStr v50; // [sp+240h] [-190h] BYREF
  idStr v51; // [sp+260h] [-170h] BYREF
  idStr v52; // [sp+280h] [-150h] BYREF
  idStr v53; // [sp+2A0h] [-130h] BYREF
  idStr v54; // [sp+2C0h] [-110h] BYREF
  idStr v55; // [sp+2E0h] [-F0h] BYREF
  idStr v56; // [sp+300h] [-D0h] BYREF
  idStr v57; // [sp+320h] [-B0h] BYREF
  idStr v58; // [sp+340h] [-90h] BYREF
  idStr v59; // [sp+360h] [-70h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v3 = 0;
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    v4 = this->GetAnimStack_2(this);
    idAnimStack::Init(this: v4, treeAnimator: TreeAnimatorFromPresentable);
    v5 = idStr::idStr(this: &v53, text: "_base");
    v6 = idStr::idStr(this: &v51, text: this->name.data);
    data = operator+(result: &v50, a: v6, b: v5)->data;
    v43.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v43.name, text: data);
    memset(&v43.originBlend, 0, 12);
    v43.blendOp = BOP_LERP;
    v43.alpha = 0.5;
    idStr::FreeData(this: &v50);
    idStr::FreeData(this: &v51);
    idStr::FreeData(this: &v53);
    v8 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->baseAnimator, gametimeManager: v8, parms: &v43);
    v9 = idStr::idStr(this: &v59, text: "_synced");
    v10 = idStr::idStr(this: &v57, text: this->name.data);
    v11 = operator+(result: &v55, a: v10, b: v9)->data;
    v44.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v44.name, text: v11);
    v44.alpha = 0.5;
    v44.blendOp = BOP_LERP;
    memset(&v44.originBlend, 0, 12);
    idStr::FreeData(this: &v55);
    idStr::FreeData(this: &v57);
    idStr::FreeData(this: &v59);
    v12 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->syncedAnimator, gametimeManager: v12, parms: &v44);
    v13 = idStr::idStr(this: &v54, text: "_synced2");
    v14 = idStr::idStr(this: &v48, text: this->name.data);
    v15 = operator+(result: &v56, a: v14, b: v13)->data;
    v42.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v42.name, text: v15);
    v42.alpha = 0.5;
    v42.blendOp = BOP_LERP;
    memset(&v42.originBlend, 0, 12);
    idStr::FreeData(this: &v56);
    idStr::FreeData(this: &v48);
    idStr::FreeData(this: &v54);
    v16 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->syncedAnimator2, gametimeManager: v16, parms: &v42);
    v17 = idStr::idStr(this: &v52, text: "_additive");
    v18 = idStr::idStr(this: &v58, text: this->name.data);
    v19 = operator+(result: &v45, a: v18, b: v17)->data;
    v41.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v41.name, text: v19);
    v41.alpha = 0.5;
    memset(&v41.originBlend, 0, 12);
    v41.blendOp = BOP_ADD_RIGHT;
    idStr::FreeData(this: &v45);
    idStr::FreeData(this: &v58);
    idStr::FreeData(this: &v52);
    v20 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->additiveAnimator, gametimeManager: v20, parms: &v41);
    v21 = idStr::idStr(this: &v49, text: "_additive_synced");
    v22 = idStr::idStr(this: &v47, text: this->name.data);
    v23 = operator+(result: &v46, a: v22, b: v21)->data;
    v34.parent = (idAnimatedEntity *)this->GetAnimStack_2(this);
    idStr::idStr(this: &v35, text: v23);
    v40 = 0.5;
    v36 = 4;
    v37 = 0;
    v38 = 0;
    v39 = 0;
    idStr::FreeData(this: &v46);
    idStr::FreeData(this: &v47);
    idStr::FreeData(this: &v49);
    v24 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(
      this: &this->additiveSyncedAnimator,
      gametimeManager: v24,
      parms: (const idAnimatorParms_Base *)&v34.parent);
    idStr::FreeData(this: &v35);
    idStr::FreeData(this: &v41.name);
    idStr::FreeData(this: &v42.name);
    idStr::FreeData(this: &v44.name);
    idStr::FreeData(this: &v43.name);
  }
  this->clipModelInfo.type = CLIPMODEL_NONE;
  Physics = idEntity::GetPhysics(this);
  ((void (__fastcall *)(idPhysics *, _DWORD, double))Physics->SetClipModel)(a1: Physics, a2: 0, a3: 1.0);
  idEntity::BecomeActive(this, flags: 4);
  if ( gameLocal->GetGameFrame(this: gameLocal) != this->lastAnimBlendFrame )
  {
    v26 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v27 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::SyncJoints(this: v27, time: v26);
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    this->lastAnimBlendFrame = gameLocal->GetGameFrame(this: gameLocal);
  }
  idAlignedEntity::InternalBecomeInactive(this);
  for ( i = 0; i < this->animatedEntityAttachments.num; ++v3 )
  {
    v29 = &this->animatedEntityAttachments.list[v3];
    entityDef = v29->entityDef;
    if ( entityDef != nullptr )
    {
      v31 = v29->tag.data;
      v32 = (idHandle<int,enum invalidAttachment_t,-1> *)this->GetAttachments_2(this);
      idAttachmentCollection::AddAttachment(this: &v34, result: v32, entityDef, tag: v31, forceReplicationFlags: -1);
      if ( (*((_BYTE *)v29 + 36) & 0x80) != 0 )
      {
        v33 = this->GetAttachments_2(this);
        idAttachmentCollection::HideAttachment(
          this: v33,
          handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v34,
          ignoreShowAll: false);
      }
    }
    ++i;
  }
}


// ========================================================================
// __unwind$495309
// EA  : 0x82BF3E70
// RVA : 0x00BF3E70
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495309()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 672));
}


// ========================================================================
// __unwind$495310
// EA  : 0x82BF3E98
// RVA : 0x00BF3E98
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495310()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 608));
}


// ========================================================================
// __unwind$495311
// EA  : 0x82BF3EC0
// RVA : 0x00BF3EC0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495311()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 576));
}


// ========================================================================
// __unwind$495312
// EA  : 0x82BF3EE8
// RVA : 0x00BF3EE8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495312()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 976 + 288));
}


// ========================================================================
// __unwind$495313
// EA  : 0x82BF3F10
// RVA : 0x00BF3F10
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495313()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 864));
}


// ========================================================================
// __unwind$495314
// EA  : 0x82BF3F38
// RVA : 0x00BF3F38
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495314()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 800));
}


// ========================================================================
// __unwind$495315
// EA  : 0x82BF3F60
// RVA : 0x00BF3F60
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495315()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 736));
}


// ========================================================================
// __unwind$495316
// EA  : 0x82BF3F88
// RVA : 0x00BF3F88
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495316()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 976 + 352));
}


// ========================================================================
// __unwind$495317
// EA  : 0x82BF3FB0
// RVA : 0x00BF3FB0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495317()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 704));
}


// ========================================================================
// __unwind$495318
// EA  : 0x82BF3FD8
// RVA : 0x00BF3FD8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495318()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 512));
}


// ========================================================================
// __unwind$495319
// EA  : 0x82BF4000
// RVA : 0x00BF4000
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495319()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 768));
}


// ========================================================================
// __unwind$495320
// EA  : 0x82BF4028
// RVA : 0x00BF4028
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495320()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 976 + 224));
}


// ========================================================================
// __unwind$495321
// EA  : 0x82BF4050
// RVA : 0x00BF4050
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495321()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 640));
}


// ========================================================================
// __unwind$495322
// EA  : 0x82BF4078
// RVA : 0x00BF4078
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495322()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 832));
}


// ========================================================================
// __unwind$495323_0
// EA  : 0x82BF40A0
// RVA : 0x00BF40A0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495323_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 416));
}


// ========================================================================
// __unwind$495324
// EA  : 0x82BF40C8
// RVA : 0x00BF40C8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495324()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 976 + 160));
}


// ========================================================================
// __unwind$495325
// EA  : 0x82BF40F0
// RVA : 0x00BF40F0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495325()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 544));
}


// ========================================================================
// __unwind$495326
// EA  : 0x82BF4118
// RVA : 0x00BF4118
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495326()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 480));
}


// ========================================================================
// __unwind$495327
// EA  : 0x82BF4140
// RVA : 0x00BF4140
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495327()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 448));
}


// ========================================================================
// __unwind$495328
// EA  : 0x82BF4168
// RVA : 0x00BF4168
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495328()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 976 + 96));
}


// ========================================================================
// ?PlayAnim@idAlignedEntity@@QAA_NPBD_NHPBVblendParms_t@@M@Z
// EA  : 0x82BF4190
// RVA : 0x00BF4190
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

int __fastcall idAlignedEntity::PlayAnim(
        idAlignedEntity *this,
        const char *aliasName,
        bool loop,
        int durationMS,
        const blendParms_t *_blendParms,
        double rateScale)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v14; // [sp+50h] [-40h] BYREF
  unsigned __int16 v15; // [sp+52h] [-3Eh] BYREF

  v14.value = -1;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)&v15, result: TreeAnimatorFromPresentable->decl, aliasName);
    v14.value = v15;
  }
  if ( v14.value != 0xFFFF )
    return idAlignedEntity::PlayAnim(this, aliasHandle: &v14, loop, durationMS, _blendParms, rateScale);
  idLib::Warning(
    fmt: "%s - anim <%s> not found in entity <%s>",
    "idAlignedEntity::PlayAnim",
    aliasName,
    this->name.data);
  return 0;
}


// ========================================================================
// ??0idAlignedEntity@@QAA@XZ
// EA  : 0x82BF4628
// RVA : 0x00BF4628
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::idAlignedEntity(idAlignedEntity *this)
{
  int v2; // ctr
  float *p_z; // r9
  float *p_y; // r10

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idAlignedEntity_vtbl *)&idAlignedEntity::`vftable';
  this->loopingSound.aliasHandle.value = -1;
  idAnimator_Channel::idAnimator_Channel(this: &this->baseAnimator);
  idAnimator_Synced::idAnimator_Synced(this: &this->syncedAnimator);
  idAnimator_Synced::idAnimator_Synced(this: &this->syncedAnimator2);
  idAnimator_Channel::idAnimator_Channel(this: &this->additiveAnimator);
  idAnimator_Synced::idAnimator_Synced(this: &this->additiveSyncedAnimator);
  idAlignedEntity::animInfo_t::animInfo_t(this: &this->baseAnimInfo);
  idAlignedEntity::animInfo_t::animInfo_t(this: &this->additiveAnimInfo);
  idStr::idStr(this: &this->alignNodeName, text: &byte_8200D768);
  this->isAlive = true;
  this->soundTagName.len = 0;
  this->soundTagName.allocedAndFlag = 20;
  this->soundTagName.data = this->soundTagName.baseBuffer;
  this->soundTagName.baseBuffer[0] = 0;
  idMQBuffer::idMQBuffer(this: &this->attachmentCollection);
  this->attachmentInfos.list = nullptr;
  this->attachmentInfos.granularity = 0;
  this->attachmentInfos.memTag = 5;
  this->attachmentInfos.listStatic = 0;
  this->attachmentInfos.size = 0;
  this->attachmentInfos.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachmentInfos);
  this->manualUpdate = false;
  this->okToShow = true;
  this->lastAnimBlendFrame = -1;
  this->attachToOwnerStart = -1;
  this->updateCamera = false;
  this->owner = nullptr;
  this->attachToOwnerBlend = 0;
  this->deltaTransExternalWorld = vec3_origin;
  v2 = 9;
  this->deltaTransScale.x = 1.0;
  this->deltaTransScale.y = 1.0;
  this->deltaTransScale.z = 1.0;
  this->startBlendOrigin = vec3_origin;
  p_z = &this->attachedModelOrigin.z;
  p_y = &mat2_identity.mat[1].y;
  this->startBlendRot = quat_identity;
  this->endBlendOrigin = vec3_origin;
  this->endBlendRot = quat_identity;
  this->attachedModelOrigin = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  idInventoryCollection::idInventoryCollection(this: &this->inventory);
  this->animatedEntityAttachments.granularity = 0;
  this->animatedEntityAttachments.memTag = 5;
  this->animatedEntityAttachments.listStatic = 0;
  this->animatedEntityAttachments.list = nullptr;
  this->animatedEntityAttachments.size = 0;
  this->animatedEntityAttachments.num = 0;
  this->attachmentCollection.parent = this;
  this->loopingSound.shader = nullptr;
  this->loopingSound.aliasHandle.value = -1;
  return this;
}


// ========================================================================
// __unwind$495797
// EA  : 0x82BF4868
// RVA : 0x00BF4868
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495797()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$495798
// EA  : 0x82BF4890
// RVA : 0x00BF4890
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495798()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 160 + 180) + 5208));
}


// ========================================================================
// __unwind$495799
// EA  : 0x82BF48BC
// RVA : 0x00BF48BC
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495799()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 160 + 180) + 5304));
}


// ========================================================================
// __unwind$495800
// EA  : 0x82BF48E8
// RVA : 0x00BF48E8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495800()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 160 + 180) + 5592));
}


// ========================================================================
// __unwind$495801
// EA  : 0x82BF4914
// RVA : 0x00BF4914
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495801()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 160 + 180) + 5880));
}


// ========================================================================
// __unwind$495802_0
// EA  : 0x82BF4940
// RVA : 0x00BF4940
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495802_0()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 160 + 180) + 5976));
}


// ========================================================================
// __unwind$495803
// EA  : 0x82BF496C
// RVA : 0x00BF496C
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495803()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 160 + 180) + 6264));
}


// ========================================================================
// __unwind$495804
// EA  : 0x82BF4998
// RVA : 0x00BF4998
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495804()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 160 + 180) + 6296));
}


// ========================================================================
// __unwind$495805_0
// EA  : 0x82BF49C4
// RVA : 0x00BF49C4
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495805_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 6328));
}


// ========================================================================
// __unwind$495806_0
// EA  : 0x82BF49F0
// RVA : 0x00BF49F0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495806_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 6364));
}


// ========================================================================
// __unwind$495807
// EA  : 0x82BF4A1C
// RVA : 0x00BF4A1C
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495807()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 6396));
}


// ========================================================================
// __unwind$495808_0
// EA  : 0x82BF4A48
// RVA : 0x00BF4A48
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495808_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 6416));
}


// ========================================================================
// __unwind$495809_0
// EA  : 0x82BF4A74
// RVA : 0x00BF4A74
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_495809_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 6580));
}


// ========================================================================
// ??1idAlignedEntity@@UAA@XZ
// EA  : 0x82BF4AC8
// RVA : 0x00BF4AC8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::~idAlignedEntity(idAlignedEntity *this)
{
  idAttachmentCollection *p_attachmentCollection; // r29
  idEntityAttachmentDef *list; // r3

  this->__vftable = (idAlignedEntity_vtbl *)&idAlignedEntity::`vftable';
  p_attachmentCollection = &this->attachmentCollection;
  idAttachmentCollection::FreeAttachments(this: &this->attachmentCollection);
  if ( this->animatedEntityAttachments.listStatic == 0 || this->animatedEntityAttachments.listStatic == 2 )
  {
    list = this->animatedEntityAttachments.list;
    if ( list != nullptr )
      idListArrayDelete<subTimingWordData_t>(ptr: &list->tag, num: this->animatedEntityAttachments.size);
    this->animatedEntityAttachments.list = nullptr;
    this->animatedEntityAttachments.size = 0;
  }
  this->animatedEntityAttachments.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->inventory);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachmentInfos);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_attachmentCollection);
  idStr::FreeData(this: &this->soundTagName);
  idStr::FreeData(this: &this->alignNodeName);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->additiveAnimInfo.queuedAnims);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->baseAnimInfo.queuedAnims);
  idAnimator_Synced::~idAnimator_Synced(this: &this->additiveSyncedAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->additiveAnimator);
  idAnimator_Synced::~idAnimator_Synced(this: &this->syncedAnimator2);
  idAnimator_Synced::~idAnimator_Synced(this: &this->syncedAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->baseAnimator);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$496184
// EA  : 0x82BF4BAC
// RVA : 0x00BF4BAC
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496184()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$496185
// EA  : 0x82BF4BD4
// RVA : 0x00BF4BD4
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496185()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 5208));
}


// ========================================================================
// __unwind$496186
// EA  : 0x82BF4C00
// RVA : 0x00BF4C00
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496186()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 128 + 148) + 5304));
}


// ========================================================================
// __unwind$496187
// EA  : 0x82BF4C2C
// RVA : 0x00BF4C2C
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496187()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 128 + 148) + 5592));
}


// ========================================================================
// __unwind$496188
// EA  : 0x82BF4C58
// RVA : 0x00BF4C58
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496188()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 5880));
}


// ========================================================================
// __unwind$496189_0
// EA  : 0x82BF4C84
// RVA : 0x00BF4C84
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496189_0()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 128 + 148) + 5976));
}


// ========================================================================
// __unwind$496190
// EA  : 0x82BF4CB0
// RVA : 0x00BF4CB0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496190()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 128 + 148) + 6264));
}


// ========================================================================
// __unwind$496191
// EA  : 0x82BF4CDC
// RVA : 0x00BF4CDC
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496191()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 128 + 148) + 6296));
}


// ========================================================================
// __unwind$496192
// EA  : 0x82BF4D08
// RVA : 0x00BF4D08
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496192()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 6328));
}


// ========================================================================
// __unwind$496193
// EA  : 0x82BF4D34
// RVA : 0x00BF4D34
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496193()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 6364));
}


// ========================================================================
// __unwind$496194
// EA  : 0x82BF4D60
// RVA : 0x00BF4D60
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496194()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 6396));
}


// ========================================================================
// __unwind$496195
// EA  : 0x82BF4D8C
// RVA : 0x00BF4D8C
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496195()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 6416));
}


// ========================================================================
// __unwind$496196
// EA  : 0x82BF4DB8
// RVA : 0x00BF4DB8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496196()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 6580));
}


// ========================================================================
// __unwind$496197
// EA  : 0x82BF4DE4
// RVA : 0x00BF4DE4
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496197()
{
  int v0; // r12

  idList<idTarget_TestPlayerState::playerState_Job_t,5>::~idList<idTarget_TestPlayerState::playerState_Job_t,5>(this: (vaiAction_t::throwAttachedItem_t *)(*(_DWORD *)(v0 - 128 + 148) + 7380));
}


// ========================================================================
// ?UpdateAttachments@idAlignedEntity@@UAAXXZ
// EA  : 0x82BF4E18
// RVA : 0x00BF4E18
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::UpdateAttachments(idAlignedEntity *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v4; // r24
  int v5; // r25
  int v6; // r26
  int v7; // r28
  idEntity *Entity; // r3
  idEntity *v9; // r30
  idPhysics *Physics; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v12; // r30
  int v13; // r3
  __int64 totalTicks; // r11
  __int64 v15; // r9
  idPLogScope v16; // [sp+50h] [-60h] BYREF

  RD_EventBegin(name: "idAlignedEntity::UpdateAttachments");
  LODWORD(v2) = "idAlignedEntity::UpdateAttachments";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v16, pl: &::pLog, gMask: v2, label: v3);
  idAttachmentCollection::UpdateRenderModelAttachments(this: &this->attachmentCollection);
  v4 = gameLocal->GetPreviousGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  if ( v4 != v5 )
  {
    v6 = 0;
    if ( this->attachmentInfos.num > 0 )
    {
      v7 = 0;
      do
      {
        Entity = idAttachmentCollection::GetEntity(
                   this: &this->attachmentCollection,
                   handle: &this->attachmentInfos.list[v7].attachHandle);
        v9 = Entity;
        if ( Entity != nullptr )
        {
          Physics = idEntity::GetPhysics(this: Entity);
          Physics->Evaluate(this: Physics, a2: v5 - v4, a3: v5);
          if ( (v9->thinkFlags & 3) == 0 )
            idEntity::UpdateVisuals(this: v9);
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->attachmentInfos.num );
    }
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
// __unwind$496347
// EA  : 0x82BF4F64
// RVA : 0x00BF4F64
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496347()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$496348
// EA  : 0x82BF4F8C
// RVA : 0x00BF4F8C
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496348()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// ?QueueAnim@idAlignedEntity@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHPBVblendParms_t@@M@Z
// EA  : 0x82BF4FB8
// RVA : 0x00BF4FB8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::QueueAnim(
        idAlignedEntity *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        bool loop,
        int durationMS,
        const blendParms_t *_blendParms,
        double rateScale)
{
  char *data; // r26
  int v13; // r25
  const char *v14; // r3
  char *v15; // r10
  char *p_flags; // r11
  int i; // ctr
  char v18; // [sp+4Ch] [-94h] BYREF
  blendParms_t v19; // [sp+50h] [-90h] BYREF
  idAlignedEntity::queuedAnim_t v20; // [sp+70h] [-70h] BYREF

  if ( aliasHandle->value != 0xFFFF && alignedEnt_traceAnims.valueInteger != 0 )
  {
    data = this->name.data;
    v13 = idAccolade::Count(this: &clientGame->gameTimeManager);
    v14 = animation->FindAliasName(this: animation, a2: aliasHandle);
    idLib::Printf(fmt: "(%d)%s - queuing anim <%s> on <%s>\n", v13, "idAlignedEntity::QueueAnim", v14, data);
  }
  blendParms_t::blendParms_t(this: &v19);
  if ( _blendParms != nullptr )
  {
    v15 = &v18;
    p_flags = &_blendParms[-1].parms.flags;
    for ( i = 5; i != 0; --i )
    {
      p_flags += 4;
      v15 += 4;
      *(_DWORD *)v15 = *(_DWORD *)p_flags;
    }
  }
  else
  {
    blendParms_t::SetDuration(this: &v19, frame: alignedEnt_defaultBlendDurationFrames.valueInteger);
  }
  idAlignedEntity::queuedAnim_t::queuedAnim_t(
    this: &v20,
    _aliasHandle: aliasHandle,
    _loop: loop,
    _durationMS: durationMS,
    _blendParms: &v19,
    _rateScale: rateScale);
  idList<idAlignedEntity::queuedAnim_t,5>::Append(this: &this->baseAnimInfo.queuedAnims, obj: &v20);
}


// ========================================================================
// ?QueueAdditiveAnim@idAlignedEntity@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHPBVblendParms_t@@@Z
// EA  : 0x82BF50D8
// RVA : 0x00BF50D8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::QueueAdditiveAnim(
        idAlignedEntity *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        bool loop,
        int durationMS,
        const blendParms_t *_blendParms)
{
  char *v10; // r10
  char *p_flags; // r11
  int i; // ctr
  char v13; // [sp+4Ch] [-74h] BYREF
  blendParms_t v14; // [sp+50h] [-70h] BYREF
  idAlignedEntity::queuedAnim_t v15[2]; // [sp+70h] [-50h] BYREF

  blendParms_t::blendParms_t(this: &v14);
  if ( _blendParms != nullptr )
  {
    v10 = &v13;
    p_flags = &_blendParms[-1].parms.flags;
    for ( i = 5; i != 0; --i )
    {
      p_flags += 4;
      v10 += 4;
      *(_DWORD *)v10 = *(_DWORD *)p_flags;
    }
  }
  else
  {
    blendParms_t::SetDuration(this: &v14, frame: alignedEnt_defaultBlendDurationFrames.valueInteger);
  }
  idAlignedEntity::queuedAnim_t::queuedAnim_t(
    this: v15,
    _aliasHandle: aliasHandle,
    _loop: loop,
    _durationMS: durationMS,
    _blendParms: &v14,
    _rateScale: 1.0);
  idList<idAlignedEntity::queuedAnim_t,5>::Append(this: &this->additiveAnimInfo.queuedAnims, obj: v15);
}


// ========================================================================
// ?UpdateInventoryItems@idAlignedEntity@@QAAXXZ
// EA  : 0x82BF5178
// RVA : 0x00BF5178
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::UpdateInventoryItems(idAlignedEntity *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int i; // r28
  idWeapon *InventoryItem; // r3
  idWeapon *v6; // r3
  idWeapon *v7; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v8; // r3
  idAttachmentCollection *v9; // r3
  const idAttachment *v10; // r3
  const idTreeAnimator *v11; // r4
  __int64 v12; // r9
  idPlayer *owner; // r7
  idLaserCutter *v14; // r3
  idRenderModelBeam *beamModelFPView; // r11
  idRenderModelDecal *decalModelFPView; // r10
  idPLog *pLog; // r29
  idPLog::logEntry_t *v18; // r30
  int v19; // r3
  __int64 totalTicks; // r11
  __int64 v21; // r9
  idHandle<int,enum invalidAttachment_t,-1> v22[2]; // [sp+50h] [-B0h] BYREF
  idPLogScope v23[2]; // [sp+58h] [-A8h] BYREF
  idVec3 v24; // [sp+68h] [-98h] BYREF
  float v25[6]; // [sp+78h] [-88h] BYREF
  idMat3 v26; // [sp+90h] [-70h] BYREF

  RD_EventBegin(name: "idAlignedEntity::UpdateInventoryItems");
  LODWORD(v2) = "idAlignedEntity::UpdateInventoryItems";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v23, pl: &::pLog, gMask: v2, label: v3);
  for ( i = 0; i < (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)&this->inventory); ++i )
  {
    InventoryItem = (idWeapon *)idInventoryCollection::GetInventoryItem(this: &this->inventory, index: i);
    v6 = idWeapon::CastTo(c: InventoryItem);
    v7 = v6;
    if ( v6 != nullptr && this->owner != nullptr && (*((_BYTE *)v6 + 452) & 2) != 0 )
    {
      v8 = (idHandle<int,enum invalidAttachment_t,-1> *)this->GetAttachments_2(this);
      idAttachmentCollection::FindAttachment(this: (idAttachmentCollection *)v22, result: v8, item: v7);
      if ( v22[0].value != -1 )
      {
        v9 = this->GetAttachments_2(this);
        v10 = idAttachmentCollection::Get(this: v9, handle: v22);
        if ( v10->presentable != nullptr )
        {
          v11 = (const idTreeAnimator *)_RTDynamicCast(
                                          inptr: v10->presentable->model,
                                          VfDelta: 0,
                                          SrcType: &idRenderModel `RTTI Type Descriptor',
                                          TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                          isReference: 0);
          if ( v11 != nullptr && idWeapon::GetLaserSightWorldTransform(this: v7, ta: v11, origin: &v24, axis: &v26) )
          {
            LODWORD(v12) = idWeapon::MaxRange(this: v7, secondaryAmmo: (_cntlzw(v7->weaponState - 1) & 0x20) != 0);
            owner = this->owner;
            v23[1] = (idPLogScope)v12;
            v25[2] = v24.z + (float)(v26.mat[0].z * (float)v12);
            v25[1] = v24.y + (float)(v26.mat[0].y * (float)v12);
            v25[0] = v24.x + (float)(v26.mat[0].x * (float)v12);
            ((void (__fastcall *)(idWeapon *, idVec3 *, float *, int))v7->UpdateLaserSight)(
              a1: v7,
              a2: &v24,
              a3: v25,
              a4: owner->entityNumber);
            v14 = idLaserCutter::CastTo(c: (idLaserCutter *)v7);
            if ( v14 != nullptr )
            {
              beamModelFPView = v14->beamModelFPView;
              decalModelFPView = v14->decalModelFPView;
              if ( beamModelFPView != nullptr )
                beamModelFPView->g.fovScale = 1.0;
              if ( decalModelFPView != nullptr )
                decalModelFPView->g.fovScale = 1.0;
            }
          }
        }
      }
    }
  }
  if ( v23[0].logIndex >= 0 )
  {
    pLog = v23[0].pLog;
    v18 = &v23[0].pLog->logEntries.list[v23[0].logIndex];
    v19 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v18->totalTicks;
    HIDWORD(totalTicks) = v18->parent;
    LODWORD(v21) = v19 - totalTicks;
    v18->totalTicks = v21;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$496444
// EA  : 0x82BF53CC
// RVA : 0x00BF53CC
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496444()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 180));
}


// ========================================================================
// __unwind$496445
// EA  : 0x82BF53F4
// RVA : 0x00BF53F4
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void _unwind_496445()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 88));
}


// ========================================================================
// ?Update@idAlignedEntity@@QAAXXZ
// EA  : 0x82BF54F8
// RVA : 0x00BF54F8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAlignedEntity::Update(idAlignedEntity *this)
{
  char v2; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  idSpringCamera *springCamera; // r3
  int attachToOwnerBlend; // r11
  double v6; // fp31
  int GameMs; // r3
  __int64 v8; // r6 OVERLAPPED
  double v9; // fp0
  int v10; // r3 OVERLAPPED
  __int64 v11; // r5 OVERLAPPED
  double v12; // fp0
  idPresentable *v13; // r11
  idSpringCamera *ControlCamera; // r3
  float *v15; // r3
  double y; // fp13
  double z; // fp12
  float *v18; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v20; // r3
  float x; // r9
  float v22; // r11
  double v23; // fp12
  double v24; // fp3
  double v25; // fp5
  const idQuat *v26; // r3
  idMat3 *v27; // r3
  int v28; // r8
  int num; // r11
  int v30; // r11
  int v31; // r7
  int v32; // r8
  idAlignedEntity::queuedAnim_t *v33; // r11
  char *p_flags; // r10
  char *v35; // r11
  int i; // ctr
  idPlayer *owner; // r3
  int value; // r11
  char v39; // r30
  idGameLocal_vtbl *v40; // r11
  int v41; // r8
  int v42; // r29
  const idAnimStack *v43; // r3
  int v44; // r11
  int v45; // r11
  int v46; // r7
  int v47; // r8
  idAlignedEntity::queuedAnim_t *v48; // r11
  char *v49; // r10
  char *v50; // r11
  int j; // ctr
  int v52; // r30
  const idAnimStack *v53; // r3
  int v54; // r30
  const idAnimStack *v55; // r3
  int v56; // r30
  const idAnimStack *v57; // r3
  idMat3 v58; // [sp+50h] [-C0h] BYREF
  idMat3 v59; // [sp+80h] [-90h] BYREF
  idQuat v60[2]; // [sp+B0h] [-60h] BYREF

  if ( (this->thinkFlags & 1) != 0 )
  {
    v2 = 0;
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    if ( this->updateCamera )
    {
      springCamera = this->owner->springCamera;
      if ( springCamera != nullptr )
        idSpringCamera::Update(this: springCamera);
    }
    if ( (this->thinkFlags & 4) == 0 )
      goto LABEL_80;
    if ( TreeAnimatorFromPresentable == nullptr )
      goto LABEL_41;
    if ( this->attachToOwnerStart == -1 || this->owner == nullptr )
    {
LABEL_32:
      if ( gameLocal->GetGameFrame(this: gameLocal) != this->lastAnimBlendFrame )
      {
        idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
        this->lastAnimBlendFrame = gameLocal->GetGameFrame(this: gameLocal);
      }
      idAnimatedEntity::UpdateFrameCommands(this);
      if ( this->baseAnimInfo.startBlendOut )
      {
        this->baseAnimInfo.startBlendOut = false;
      }
      else if ( this->baseAnimInfo.animDurationMS <= 0 )
      {
        if ( !idAlignedEntity::IsCurAnimDone(
                this,
                numFramesAhead: alignedEnt_animIsDoneFrames.valueInteger,
                ignoreQueuedAnims: true) )
          goto LABEL_42;
      }
      else
      {
        v28 = this->baseAnimInfo.animDurationMS - gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
        this->baseAnimInfo.animDurationMS = v28;
        if ( v28 > 0 )
          goto LABEL_42;
      }
      this->baseAnimInfo.animDurationMS = 0;
LABEL_41:
      v2 = 1;
LABEL_42:
      if ( v2 != 0 )
      {
        idAlignedEntity::DetachItems(this);
        if ( this->baseAnimInfo.queuedAnims.num != 0 )
        {
          idAlignedEntity::InternalPlayAnim(
            this,
            channelAnimator: &this->baseAnimator,
            animInfo: &this->baseAnimInfo,
            aliasHandle: &this->baseAnimInfo.queuedAnims.list->aliasHandle,
            loop: this->baseAnimInfo.queuedAnims.list->loop,
            durationMS: this->baseAnimInfo.queuedAnims.list->durationMS,
            blendParms: &this->baseAnimInfo.queuedAnims.list->blendParms,
            rateScale: this->baseAnimInfo.queuedAnims.list->rateScale);
          num = this->baseAnimInfo.queuedAnims.num;
          if ( num > 0 )
          {
            v30 = num - 1;
            v31 = 0;
            this->baseAnimInfo.queuedAnims.num = v30;
            if ( v30 > 0 )
            {
              v32 = 0;
              do
              {
                v33 = &this->baseAnimInfo.queuedAnims.list[v32];
                p_flags = &v33->blendParms.parms.flags;
                v35 = &v33[-1].blendParms.parms.flags;
                for ( i = 8; i != 0; --i )
                {
                  p_flags += 4;
                  v35 += 4;
                  *(_DWORD *)v35 = *(_DWORD *)p_flags;
                }
                ++v31;
                ++v32;
              }
              while ( v31 < this->baseAnimInfo.queuedAnims.num );
            }
          }
        }
        else
        {
          this->baseAnimInfo.curAliasHandle.value = -1;
          this->baseAnimInfo.startTime = 0;
        }
      }
      owner = this->owner;
      if ( owner != nullptr && this->loopingSound.shader != nullptr )
      {
        value = this->loopingSound.aliasHandle.value;
        if ( value != 0xFFFF && value != this->baseAnimInfo.curAliasHandle.value )
        {
          idEntity::StopSound(this: owner, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
          this->loopingSound.shader = nullptr;
          this->loopingSound.aliasHandle.value = -1;
        }
      }
      v39 = 0;
      if ( this->additiveAnimInfo.startBlendOut )
      {
        this->additiveAnimInfo.startBlendOut = false;
      }
      else
      {
        v40 = gameLocal->__vftable;
        if ( this->additiveAnimInfo.animDurationMS <= 0 )
        {
          v42 = ((int (*)(void))v40->GetGameMs)();
          v43 = this->GetAnimStack_2(this);
          if ( !idAnimator_Channel::IsDone(this: &this->additiveAnimator, stack: v43, curTime: v42) )
            goto LABEL_64;
        }
        else
        {
          v41 = this->additiveAnimInfo.animDurationMS - ((int (*)(void))v40->GetGameMsPerFrame)();
          this->additiveAnimInfo.animDurationMS = v41;
          if ( v41 > 0 )
            goto LABEL_64;
        }
      }
      v39 = 1;
      this->additiveAnimInfo.animDurationMS = 0;
LABEL_64:
      if ( v39 != 0 && this->additiveAnimInfo.queuedAnims.num != 0 )
      {
        idAlignedEntity::InternalPlayAnim(
          this,
          channelAnimator: &this->additiveAnimator,
          animInfo: &this->additiveAnimInfo,
          aliasHandle: &this->additiveAnimInfo.queuedAnims.list->aliasHandle,
          loop: this->additiveAnimInfo.queuedAnims.list->loop,
          durationMS: this->additiveAnimInfo.queuedAnims.list->durationMS,
          blendParms: &this->additiveAnimInfo.queuedAnims.list->blendParms,
          rateScale: this->additiveAnimInfo.queuedAnims.list->rateScale);
        v44 = this->additiveAnimInfo.queuedAnims.num;
        if ( v44 > 0 )
        {
          v45 = v44 - 1;
          v46 = 0;
          this->additiveAnimInfo.queuedAnims.num = v45;
          if ( v45 > 0 )
          {
            v47 = 0;
            do
            {
              v48 = &this->additiveAnimInfo.queuedAnims.list[v47];
              v49 = &v48->blendParms.parms.flags;
              v50 = &v48[-1].blendParms.parms.flags;
              for ( j = 8; j != 0; --j )
              {
                v49 += 4;
                v50 += 4;
                *(_DWORD *)v50 = *(_DWORD *)v49;
              }
              ++v46;
              ++v47;
            }
            while ( v46 < this->additiveAnimInfo.queuedAnims.num );
          }
        }
      }
      if ( this->baseAnimInfo.curAliasHandle.value == 0xFFFF && this->additiveAnimInfo.curAliasHandle.value == 0xFFFF )
      {
        v52 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        v53 = this->GetAnimStack_2(this);
        if ( (unsigned __int8)idAnimator_Synced::IsDone(this: &this->syncedAnimator, stack: v53, curTime: v52) != 0 )
        {
          v54 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          v55 = this->GetAnimStack_2(this);
          if ( (unsigned __int8)idAnimator_Synced::IsDone(this: &this->syncedAnimator2, stack: v55, curTime: v54) != 0 )
          {
            v56 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            v57 = this->GetAnimStack_2(this);
            if ( (unsigned __int8)idAnimator_Synced::IsDone(
                                    this: &this->additiveSyncedAnimator,
                                    stack: v57,
                                    curTime: v56) != 0 )
            {
              if ( this != (idAlignedEntity *)-3468 )
                idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)&this->animEventHandler);
              idAlignedEntity::InternalBecomeInactive(this);
            }
          }
        }
      }
LABEL_80:
      idAlignedEntity::UpdateInventoryItems(this);
      return;
    }
    attachToOwnerBlend = this->attachToOwnerBlend;
    if ( attachToOwnerBlend >= 0 )
    {
      if ( attachToOwnerBlend != 0 )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v8) = this->attachToOwnerBlend;
        HIDWORD(v8) = GameMs - this->attachToOwnerStart;
        *(_QWORD *)&v58.mat[0].x = *(__int64 *)((char *)&v8 + 4);
        v6 = 0.0;
        v9 = (float)((float)*(__int64 *)((char *)&v8 + 4) / (float)v8);
        if ( v9 >= 0.0 )
        {
          v6 = 1.0;
          if ( v9 <= 1.0 )
            v6 = (float)((float)*(__int64 *)((char *)&v8 + 4) / (float)v8);
        }
      }
      else
      {
        v6 = 1.0;
      }
      goto LABEL_22;
    }
    v10 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v11) = v10 - this->attachToOwnerStart;
    HIDWORD(v11) = -this->attachToOwnerBlend;
    *(_QWORD *)&v58.mat[0].x = *(__int64 *)((char *)&v11 + 4);
    v6 = 1.0;
    v12 = (float)((float)1.0 - (float)((float)v11 / (float)*(__int64 *)((char *)&v11 + 4)));
    if ( v12 >= 0.0 )
    {
      if ( v12 > 1.0
        || (v6 = (float)((float)1.0 - (float)((float)v11 / (float)*(__int64 *)((char *)&v11 + 4))), v12 != 0.0) )
      {
LABEL_22:
        ControlCamera = (idSpringCamera *)idPlayer::GetControlCamera(this: this->owner);
        v15 = (float *)idSpringCamera::CastTo(c: ControlCamera);
        if ( v15 != nullptr && this->attachToOwnerBlend >= 0 )
        {
          v58.mat[1].y = v15[336];
          v58.mat[1].z = v15[337];
          v58.mat[2].x = v15[338];
          v59.mat[0].x = v15[339];
          v59.mat[0].y = v15[340];
          v59.mat[0].z = v15[341];
          v59.mat[1].x = v15[342];
          v59.mat[1].y = v15[343];
          v59.mat[1].z = v15[344];
          v59.mat[2].x = v15[345];
          v59.mat[2].y = v15[346];
          v59.mat[2].z = v15[347];
        }
        else if ( this->attachToOwnerBlend >= 0 )
        {
          presentable = this->owner->presentable;
          if ( presentable != nullptr )
            v20 = presentable->GetPlayerInterface_2(this: presentable);
          else
            v20 = nullptr;
          idPresentablePlayer::GetViewTransform(this: v20, origin: (idVec3 *)&v58.mat[1].y, axis: &v59);
        }
        else
        {
          y = this->endBlendOrigin.y;
          z = this->endBlendOrigin.z;
          v58.mat[1].y = this->endBlendOrigin.x;
          v58.mat[1].z = y;
          v58.mat[2].x = z;
          v18 = (float *)idQuat::ToMat3(this: v60, result: (idMat3 *)&this->endBlendRot);
          v59.mat[0].x = *v18;
          v59.mat[0].y = v18[1];
          v59.mat[0].z = v18[2];
          v59.mat[1].x = v18[3];
          v59.mat[1].y = v18[4];
          v59.mat[1].z = v18[5];
          v59.mat[2].x = v18[6];
          v59.mat[2].y = v18[7];
          v59.mat[2].z = v18[8];
        }
        x = this->startBlendOrigin.x;
        v22 = this->startBlendOrigin.y;
        v58.mat[0].z = this->startBlendOrigin.z;
        v23 = v58.mat[0].z;
        v58.mat[0].x = x;
        v58.mat[0].y = v22;
        v24 = (float)((float)(v58.mat[2].x - v58.mat[0].z) * (float)v6);
        v25 = (float)((float)(v58.mat[1].y - x) * (float)v6);
        this->attachedModelOrigin.y = (float)((float)(v58.mat[1].z - v22) * (float)v6) + v22;
        this->attachedModelOrigin.x = (float)v25 + x;
        this->attachedModelOrigin.z = (float)v24 + (float)v23;
        v26 = idMat3::ToQuat(this: &v58, result: (idQuat *)&v59);
        v27 = (idMat3 *)idQuat::Slerp(this: (idQuat *)&v58.mat[2].z, from: &this->startBlendRot, to: v26, t: v6);
        this->attachedModelAxis = *idQuat::ToMat3(this: v60, result: v27);
        goto LABEL_32;
      }
    }
    else
    {
      v6 = 0.0;
    }
    v13 = this->presentable;
    this->attachToOwnerStart = -1;
    if ( v13 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v13 = this->presentable;
    }
    v13->model->useDeferredPosition = true;
    goto LABEL_22;
  }
}


// ========================================================================
// ?QueueAnim@idAlignedEntity@@QAAXPBD_NHPBVblendParms_t@@M@Z
// EA  : 0x82BF5CE8
// RVA : 0x00BF5CE8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::QueueAnim(
        idAlignedEntity *this,
        const char *aliasName,
        bool loop,
        int durationMS,
        const blendParms_t *_blendParms,
        double rateScale)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v13; // [sp+50h] [-40h] BYREF
  unsigned __int16 v14; // [sp+52h] [-3Eh] BYREF

  v13.value = -1;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)&v14, result: TreeAnimatorFromPresentable->decl, aliasName);
    v13.value = v14;
  }
  if ( v13.value == 0xFFFF )
    idLib::Warning(
      fmt: "%s - anim <%s> not found in entity <%s>",
      "idAlignedEntity::QueueAnim",
      aliasName,
      this->name.data);
  else
    idAlignedEntity::QueueAnim(this, aliasHandle: &v13, loop, durationMS, _blendParms, rateScale);
}


// ========================================================================
// ?QueueAdditiveAnim@idAlignedEntity@@QAAXPBD_NHPBVblendParms_t@@@Z
// EA  : 0x82BF5D98
// RVA : 0x00BF5D98
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::QueueAdditiveAnim(
        idAlignedEntity *this,
        const char *aliasName,
        bool loop,
        int durationMS,
        const blendParms_t *_blendParms)
{
  unsigned __int16 v5; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v12; // [sp+50h] [-40h] BYREF
  unsigned __int16 v13; // [sp+52h] [-3Eh] BYREF

  v5 = -1;
  v12.value = -1;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)&v13, result: TreeAnimatorFromPresentable->decl, aliasName);
    v5 = v13;
    v12.value = v13;
  }
  if ( v5 == 0xFFFF )
    idLib::Warning(
      fmt: "%s - anim <%s> not found in entity <%s>",
      "idAlignedEntity::QueueAdditiveAnim",
      aliasName,
      this->name.data);
  else
    idAlignedEntity::QueueAdditiveAnim(this, aliasHandle: &v12, loop, durationMS, _blendParms);
}


// ========================================================================
// ?AttachItem@idAlignedEntity@@QAAXPBVidDeclInventory@@PBD_N22@Z
// EA  : 0x82BF5E38
// RVA : 0x00BF5E38
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::AttachItem(
        idAlignedEntity *this,
        const idDeclInventory *decl,
        const char *slotName,
        bool autoDetach,
        bool autoGive,
        bool noClone)
{
  idWeapon *v12; // r26
  int num; // r8
  int v14; // r10
  int v15; // r11
  idJobManager *v16; // r3
  idInventoryCollection *v17; // r28
  const idInventoryItem *JobByDecl; // r31
  idPlayer *owner; // r31
  idPresentable *v20; // r4
  idList<idAlignedEntity::addedAttachment_t,5> *p_attachmentInfos; // r30
  int v22; // r11
  int size; // r10
  int v24; // r31
  idPlayer *v25; // r30
  idPresentable *v26; // r4
  idPresentable *v27; // r30
  idPlayer *v28; // r31
  idPresentable *v29; // r4
  int value; // r10
  idPresentable *presentable; // r11
  const idDeclMD6 *handsModelMD6; // r11
  int v33; // r11
  idInventoryItem *v34; // [sp+50h] [-60h] BYREF
  idAttachmentCollection v35[4]; // [sp+54h] [-5Ch] BYREF

  v12 = nullptr;
  if ( decl == nullptr )
  {
    idLib::Warning(fmt: "%s - no attach item decl specified", "idAlignedEntity::AttachItem");
    return;
  }
  num = this->attachmentInfos.num;
  v14 = 0;
  if ( num <= 0 )
  {
LABEL_7:
    v16 = (idJobManager *)this->owner->GetInventory_2(this: this->owner);
    v17 = (idInventoryCollection *)v16;
    if ( v16 == nullptr )
    {
LABEL_15:
      p_attachmentInfos = &this->attachmentInfos;
      idList<idAlignedEntity::addedAttachment_t,5>::PreAllocateWithGranularity(
        this: &this->attachmentInfos,
        newSize: this->attachmentInfos.num + 1);
      v22 = this->attachmentInfos.num;
      size = this->attachmentInfos.size;
      if ( v22 >= size )
      {
        v24 = (int)&p_attachmentInfos->list[size - 1];
      }
      else
      {
        v24 = (int)&p_attachmentInfos->list[v22];
        this->attachmentInfos.num = v22 + 1;
      }
      if ( v12 != nullptr )
      {
        value = idAttachmentCollection::AddAttachment(
                  this: v35,
                  result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachmentCollection,
                  item: v12,
                  tagName: slotName,
                  fxAttachInfo: nullptr)->value;
        *(_DWORD *)(v24 + 4) = v12;
        *(_DWORD *)v24 = decl;
        *(_BYTE *)(v24 + 12) = autoDetach;
        *(_BYTE *)(v24 + 13) = noClone;
        *(_DWORD *)(v24 + 8) = value;
        idWeapon::CastTo(c: v12);
        presentable = this->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        v12->OnEquip(this: v12, a2: presentable, a3: nullptr);
      }
      else
      {
        handsModelMD6 = decl->handsModelMD6;
        if ( handsModelMD6 != nullptr )
        {
          v33 = idAttachmentCollection::AddAttachment(
                  this: v35,
                  result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachmentCollection,
                  modelName: handsModelMD6->name.str,
                  tag: slotName)->value;
          *(_DWORD *)v24 = decl;
          *(_BYTE *)(v24 + 12) = autoDetach;
          *(_DWORD *)(v24 + 4) = 0;
          *(_DWORD *)(v24 + 8) = v33;
        }
        else
        {
          idLib::Warning(
            fmt: "%s - no handsModelMD6 specified in item <%s>",
            "idAlignedEntity::AttachItem",
            decl->name.str);
        }
      }
      return;
    }
    JobByDecl = (const idInventoryItem *)idJobManager::FindJobByDecl(this: v16, jobDecl: (const idDeclJob *)decl);
    if ( JobByDecl == nullptr )
    {
      if ( !autoGive )
      {
LABEL_14:
        noClone = false;
        goto LABEL_15;
      }
      owner = this->owner;
      v20 = owner->presentable;
      if ( v20 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->owner);
        v20 = owner->presentable;
      }
      JobByDecl = idInventoryCollection::GiveItem(
                    this: v17,
                    owner: v20,
                    decl,
                    count: 1,
                    forceCount: false,
                    canIntro: false);
      if ( JobByDecl == nullptr )
      {
        idLib::Warning(fmt: " %s - AutoGive failed of item ", "idAlignedEntity::AttachItem");
        goto LABEL_14;
      }
    }
    if ( noClone )
    {
      v12 = (idWeapon *)JobByDecl;
    }
    else
    {
      v25 = this->owner;
      v26 = v25->presentable;
      if ( v26 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->owner);
        v26 = v25->presentable;
      }
      v34 = idInventoryCollection::CloneItem(this: v17, ownerEnt: v26, item: JobByDecl, canIntro: false);
      if ( v34 != nullptr )
      {
        if ( this->presentable == nullptr )
          idEntity::InitPresentableInternal(this);
        v27 = this->presentable;
        v28 = this->owner;
        v29 = v28->presentable;
        if ( v29 == nullptr )
        {
          idEntity::InitPresentableInternal(this: this->owner);
          v29 = v28->presentable;
        }
        v12 = (idWeapon *)idInventoryCollection::TransferItem(
                            this: v17,
                            owner: v29,
                            to: v27,
                            item: &v34,
                            deleteOwnerItem: true,
                            canIntro: false);
        if ( v12 == nullptr )
          idLib::Warning(
            fmt: "%s - unable to transfer item <%s> from <%s> inventory to <%s> inventory",
            "idAlignedEntity::AttachItem",
            decl->name.str,
            this->owner->name.data,
            this->name.data);
      }
      else
      {
        idLib::Warning(
          fmt: "%s - unable to clone item <%s> in <%s> inventory",
          "idAlignedEntity::AttachItem",
          decl->name.str,
          this->owner->name.data);
      }
    }
    goto LABEL_15;
  }
  v15 = 0;
  while ( decl != this->attachmentInfos.list[v15].attachItemDecl )
  {
    ++v14;
    ++v15;
    if ( v14 >= num )
      goto LABEL_7;
  }
  idLib::Warning(
    fmt: "%s - trying to attach <%s>, but it's already attached",
    "idAlignedEntity::AttachItem",
    decl->name.str);
}


// ========================================================================
// ?AttachEntity@idAlignedEntity@@QAAXPAVidEntity@@PBD@Z
// EA  : 0x82BF6190
// RVA : 0x00BF6190
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::AttachEntity(idAlignedEntity *this, idEntity *entity, const char *tag)
{
  idAlignedEntity::addedAttachment_t *v6; // r28
  int value; // r11
  idAttachmentCollection v8[2]; // [sp+50h] [-30h] BYREF

  v6 = idList<idAlignedEntity::addedAttachment_t,5>::Alloc(this: &this->attachmentInfos);
  value = idAttachmentCollection::AddAttachment(
            this: v8,
            result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachmentCollection,
            ent: entity,
            tag)->value;
  v6->attachAutoDetach = true;
  v6->attachHandle.value = value;
}


// ========================================================================
// ?AnimEvent_AttachItem@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclInventory@@PBD@Z
// EA  : 0x82BF61E0
// RVA : 0x00BF61E0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AttachItem(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle,
        const idDeclInventory *decl,
        const char *slotName)
{
  const char *str; // r31
  int v10; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v10 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v10, "idAlignedEntity::AnimEvent_AttachItem", str);
  }
  idAlignedEntity::AttachItem(this: result, decl, slotName, autoDetach: true, autoGive: false, noClone: false);
  return this;
}


// ========================================================================
// ?AnimEvent_AttachItemForManualDetach@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclInventory@@PBD@Z
// EA  : 0x82BF6288
// RVA : 0x00BF6288
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AttachItemForManualDetach(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle,
        const idDeclInventory *decl,
        const char *slotName)
{
  const char *str; // r31
  int v10; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v10 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v10, "idAlignedEntity::AnimEvent_AttachItemForManualDetach", str);
  }
  idAlignedEntity::AttachItem(this: result, decl, slotName, autoDetach: false, autoGive: false, noClone: false);
  return this;
}


// ========================================================================
// ?AnimEvent_AttachSpecialItemForManualDetach@idAlignedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclInventory@@PBD@Z
// EA  : 0x82BF6330
// RVA : 0x00BF6330
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

idAlignedEntity *__fastcall idAlignedEntity::AnimEvent_AttachSpecialItemForManualDetach(
        idAlignedEntity *this,
        idAlignedEntity *result,
        const idMD6Anim *animHandle,
        const idDeclInventory *decl,
        const char *slotName)
{
  const char *str; // r31
  int v10; // r3

  if ( alignedEnt_debugfc.valueInteger > 0 )
  {
    if ( animHandle != nullptr )
      str = animHandle->name.str;
    else
      str = "<NULL>";
    v10 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^7(%d)%s - '^2%s^7'\n", v10, "idAlignedEntity::AnimEvent_AttachSpecialItemForManualDetach", str);
  }
  idAlignedEntity::AttachItem(this: result, decl, slotName, autoDetach: false, autoGive: true, noClone: false);
  return this;
}


// ========================================================================
// ?Think@idAlignedEntity@@UAAXXZ
// EA  : 0x82BF63D8
// RVA : 0x00BF63D8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __fastcall idAlignedEntity::Think(idAlignedEntity *this)
{
  if ( !this->manualUpdate )
    idAlignedEntity::Update(this);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_debugfc''
// EA  : 0x833749D8
// RVA : 0x013749D8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_debugfc__()
{
  idCVar::idCVar(
    this: &alignedEnt_debugfc,
    name: "alignedEnt_debugfc",
    value: "0",
    flags: 2,
    description: "> 0 = show frame commands callbacks",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_debugfc__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_drawAlignJoint''
// EA  : 0x83374A30
// RVA : 0x01374A30
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_drawAlignJoint__()
{
  idCVar::idCVar(
    this: &alignedEnt_drawAlignJoint,
    name: "alignedEnt_drawAlignJoint",
    value: "false",
    flags: 1,
    description: "Draw the entity's align joint",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_drawAlignJoint__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_drawTargetJoint''
// EA  : 0x83374A88
// RVA : 0x01374A88
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_drawTargetJoint__()
{
  idCVar::idCVar(
    this: &alignedEnt_drawTargetJoint,
    name: "alignedEnt_drawTargetJoint",
    value: "false",
    flags: 1,
    description: "Draw the target joint to align to",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_drawTargetJoint__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_defaultBlendDurationFrames''
// EA  : 0x83374AE0
// RVA : 0x01374AE0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_defaultBlendDurationFrames__()
{
  idCVar::idCVar(
    this: &alignedEnt_defaultBlendDurationFrames,
    name: "alignedEnt_defaultBlendDurationFrames",
    value: "1",
    flags: 2,
    description: "Default blend duration, in frames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_defaultBlendDurationFrames__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_defaultAdditiveAlphaRate''
// EA  : 0x83374B38
// RVA : 0x01374B38
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_defaultAdditiveAlphaRate__()
{
  idCVar::idCVar(
    this: &alignedEnt_defaultAdditiveAlphaRate,
    name: "alignedEnt_defaultAdditiveAlphaRate",
    value: "10",
    flags: 4,
    description: "Default blend duration, in frames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_defaultAdditiveAlphaRate__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_defaultCameraViewConeDeg''
// EA  : 0x83374B90
// RVA : 0x01374B90
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_defaultCameraViewConeDeg__()
{
  idCVar::idCVar(
    this: &alignedEnt_defaultCameraViewConeDeg,
    name: "alignedEnt_defaultCameraViewConeDeg",
    value: "30",
    flags: 4,
    description: "Default View Cone Degrees if Camera Animation Events specify an invalid value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_defaultCameraViewConeDeg__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_traceOriginDeltas''
// EA  : 0x83374BE8
// RVA : 0x01374BE8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_traceOriginDeltas__()
{
  idCVar::idCVar(
    this: &alignedEnt_traceOriginDeltas,
    name: "alignedEnt_traceOriginDeltas",
    value: "0",
    flags: 2,
    description: "Outputs the origin deltas to the console (1 for trans, 2 for rot, 3 for both)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_traceOriginDeltas__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_traceAlign''
// EA  : 0x83374C40
// RVA : 0x01374C40
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_traceAlign__()
{
  idCVar::idCVar(
    this: &alignedEnt_traceAlign,
    name: "alignedEnt_traceAlign",
    value: "0",
    flags: 2,
    description: "Traces the data through the align process (1 for trans, 2 for rot, 3 for both)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_traceAlign__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_traceAnims''
// EA  : 0x83374C98
// RVA : 0x01374C98
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_traceAnims__()
{
  idCVar::idCVar(
    this: &alignedEnt_traceAnims,
    name: "alignedEnt_traceAnims",
    value: "0",
    flags: 1,
    description: "Traces the anims played on all aligned entities",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_traceAnims__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_animIsDoneFrames''
// EA  : 0x83374CF0
// RVA : 0x01374CF0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_animIsDoneFrames__()
{
  idCVar::idCVar(
    this: &alignedEnt_animIsDoneFrames,
    name: "alignedEnt_animIsDoneFrames",
    value: "3",
    flags: 2,
    description: "Default number of frames to look ahead to test whether an animation is 'done'",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_animIsDoneFrames__);
}


// ========================================================================
// `dynamic initializer for 'alignedEnt_useTAanimDeltaLogic''
// EA  : 0x83374D48
// RVA : 0x01374D48
// PDB : w:\tech5\tungsten\game\entities\alignedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__alignedEnt_useTAanimDeltaLogic__()
{
  idCVar::idCVar(
    this: &alignedEnt_useTAanimDeltaLogic,
    name: "alignedEnt_useTAanimDeltaLogic",
    value: "0",
    flags: 1,
    description: "Use the tree animator's anim delta translation and rotation logic",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__alignedEnt_useTAanimDeltaLogic__);
}

