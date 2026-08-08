
// ========================================================================
// ?ForIndex@idAttachmentCollection@@QAAPAVidAttachment@@H@Z
// EA  : 0x82C07F80
// RVA : 0x00C07F80
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachment *__fastcall idAttachmentCollection::ForIndex(idAttachmentCollection *this, int index)
{
  if ( index < 0 || index > this->attachments.num )
    return nullptr;
  else
    return &this->attachments.list[index];
}


// ========================================================================
// ?JobSync@idAttachmentCollection@@QAAXXZ
// EA  : 0x82C07FB0
// RVA : 0x00C07FB0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::JobSync(idAttachmentCollection *this)
{
  int v2; // r27
  int v3; // r30
  idAttachment *v4; // r11
  idPresentable *presentable; // r11
  idTreeAnimator *model; // r31
  int GameMs; // r3

  v2 = 0;
  if ( this->attachments.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->attachments.list[v3];
      if ( (*((_BYTE *)v4 + 104) & 0x80) != 0 )
      {
        presentable = v4->presentable;
        if ( presentable != nullptr )
        {
          model = (idTreeAnimator *)presentable->model;
          if ( model != nullptr )
          {
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            idTreeAnimator::SyncJoints(this: model, time: GameMs);
          }
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->attachments.num );
  }
}


// ========================================================================
// ?FindAttachmentIndex@idAttachmentCollection@@ABAHABV?$idHandle@HW4invalidAttachment_t@@$0?0@@@Z
// EA  : 0x82C08048
// RVA : 0x00C08048
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

int __fastcall idAttachmentCollection::FindAttachmentIndex(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle)
{
  int num; // r7
  int v3; // r10
  int v4; // r11
  idAttachment *list; // r9

  num = this->attachments.num;
  v3 = 0;
  if ( num <= 0 )
    return -1;
  v4 = 0;
  list = this->attachments.list;
  while ( list->handle.value != handle->value )
  {
    ++v3;
    list = &this->attachments.list[++v4];
    if ( v3 >= num )
      return -1;
  }
  return v3;
}


// ========================================================================
// ??0idAttachment@@QAA@XZ
// EA  : 0x82C08108
// RVA : 0x00C08108
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachment *__fastcall idAttachment::idAttachment(idAttachment *this)
{
  this->presentable = nullptr;
  this->item = nullptr;
  this->particleFx = nullptr;
  this->particleFxTagData.trans.x = 0.0;
  this->particleFxTagData.trans.y = 0.0;
  this->particleFxTagData.trans.z = 0.0;
  this->particleFxTagData.rot.x = 0.0;
  this->particleFxTagData.rot.y = 0.0;
  this->particleFxTagData.rot.z = 0.0;
  this->particleFxTagData.rot.w = 0.0;
  this->particleFxTagData.parentJoint.value = -1;
  this->originOffset.x = 0.0;
  this->originOffset.y = 0.0;
  this->originOffset.z = 0.0;
  this->savedRotOffset.x = 0.0;
  this->savedRotOffset.y = 0.0;
  this->savedRotOffset.z = 0.0;
  this->savedRotOffset.w = 0.0;
  this->rotOffset.x = 0.0;
  this->rotOffset.y = 0.0;
  this->rotOffset.z = 0.0;
  this->rotOffset.w = 0.0;
  this->entity.spawnId.value = 0x1FFF;
  this->jointIndex.value = -1;
  this->rotationAxis = -1;
  this->handle.value = -1;
  *((_BYTE *)this + 104) &= 3u;
  return this;
}


// ========================================================================
// ?Get@idAttachmentCollection@@QBAPBVidAttachment@@ABV?$idHandle@HW4invalidAttachment_t@@$0?0@@@Z
// EA  : 0x82C081A0
// RVA : 0x00C081A0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

const idAttachment *__fastcall idAttachmentCollection::Get(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle)
{
  _DWORD *v2; // r5
  int AttachmentIndex; // r3

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  if ( AttachmentIndex < 0 )
    return nullptr;
  else
    return (const idAttachment *)(108 * AttachmentIndex + *v2);
}


// ========================================================================
// ?GetEntity@idAttachmentCollection@@QAAPAVidEntity@@ABV?$idHandle@HW4invalidAttachment_t@@$0?0@@@Z
// EA  : 0x82C081F0
// RVA : 0x00C081F0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idEntity *__fastcall idAttachmentCollection::GetEntity(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle)
{
  _DWORD *v2; // r5
  int AttachmentIndex; // r3
  int v4; // r8
  idEntity *v5; // r3

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  if ( AttachmentIndex >= 0
    && (v4 = *(_DWORD *)(108 * AttachmentIndex + *v2 + 88), gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13)
    && (v5 = gameLocal->entities.ptr[*(_DWORD *)(108 * AttachmentIndex + *v2 + 88) & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v5);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?DetachAttachment@idAttachmentCollection@@QAAXABV?$idHandle@HW4invalidAttachment_t@@$0?0@@@Z
// EA  : 0x82C08280
// RVA : 0x00C08280
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::DetachAttachment(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle)
{
  int AttachmentIndex; // r3
  idAttachment *v4; // r31
  idAnimatedEntity *parent; // r30
  idPresentable *presentable; // r11
  idPresentable *v7; // r11
  float v8[4]; // [sp+50h] [-50h] BYREF
  float v9[10]; // [sp+60h] [-40h] BYREF

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  if ( AttachmentIndex >= 0 )
  {
    v4 = &this->attachments.list[AttachmentIndex];
    if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->parent) != nullptr )
    {
      parent = this->parent;
      presentable = parent->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: parent);
        presentable = parent->presentable;
      }
      idPresentable::UpdateModelTransform(this: presentable);
      if ( v4->presentable != nullptr )
      {
        idPresentable::UpdateModelTransform(this: v4->presentable);
        v4->presentable->GetWorldTransform(this: v4->presentable, a2: (idVec3 *)v8, a3: (idMat3 *)v9);
        idPresentable::SetParent(
          this: v4->presentable,
          p: nullptr,
          j: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value);
        v7 = v4->presentable;
        v7->origin.x = v8[0];
        v7->origin.y = v8[1];
        v7->origin.z = v8[2];
        qmemcpy(&v4->presentable->axis, v9, sizeof(v4->presentable->axis));
        *((_BYTE *)v4 + 104) |= 4u;
      }
    }
  }
}


// ========================================================================
// ?ReattachAttachment@idAttachmentCollection@@QAAXABV?$idHandle@HW4invalidAttachment_t@@$0?0@@@Z
// EA  : 0x82C083B0
// RVA : 0x00C083B0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::ReattachAttachment(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle)
{
  int AttachmentIndex; // r3
  idAttachment *v4; // r29
  idAnimatedEntity *parent; // r30
  idPresentable *presentable; // r11
  idAnimatedEntity *v7; // r31
  idPresentable *v8; // r11

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  if ( AttachmentIndex >= 0 )
  {
    v4 = &this->attachments.list[AttachmentIndex];
    if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->parent) != nullptr )
    {
      parent = this->parent;
      presentable = parent->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->parent);
        presentable = parent->presentable;
      }
      idPresentable::UpdateModelTransform(this: presentable);
      if ( v4->presentable != nullptr )
      {
        v7 = this->parent;
        v8 = v7->presentable;
        if ( v8 == nullptr )
        {
          idEntity::InitPresentableInternal(this: v7);
          v8 = v7->presentable;
        }
        idPresentable::SetParent(
          this: v4->presentable,
          p: v8,
          j: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v4->jointIndex.value);
        v4->presentable->Present(this: v4->presentable);
        *((_BYTE *)v4 + 104) &= ~4u;
      }
    }
  }
}


// ========================================================================
// ?RemoveAttachment@idAttachmentCollection@@QAAXPBVidInventoryItem@@@Z
// EA  : 0x82C08470
// RVA : 0x00C08470
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::RemoveAttachment(idAttachmentCollection *this, const idInventoryItem *item)
{
  int num; // r8
  int v4; // r31
  idAttachment *list; // r9
  int v6; // r11
  idAttachment *v7; // r10
  idPresentable *presentable; // r3

  num = this->attachments.num;
  v4 = 0;
  if ( num > 0 )
  {
    list = this->attachments.list;
    v6 = 0;
    v7 = this->attachments.list;
    while ( v7->item != item )
    {
      ++v4;
      v7 = &list[++v6];
      if ( v4 >= num )
        return;
    }
    if ( v4 >= 0 )
    {
      presentable = list[v4].presentable;
      if ( presentable != nullptr )
      {
        idPresentable::Delete(this: presentable);
        this->attachments.list[v4].presentable = nullptr;
      }
      idList<idAttachment,5>::RemoveIndexFast(this: &this->attachments, index: v4);
    }
  }
}


// ========================================================================
// ?RemoveAttachment@idAttachmentCollection@@QAAXABV?$idHandle@HW4invalidAttachment_t@@$0?0@@@Z
// EA  : 0x82C08500
// RVA : 0x00C08500
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::RemoveAttachment(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle)
{
  int AttachmentIndex; // r3
  int v4; // r29
  int v5; // r30
  idPresentable *presentable; // r3

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  v4 = AttachmentIndex;
  if ( AttachmentIndex >= 0 )
  {
    v5 = AttachmentIndex;
    presentable = this->attachments.list[AttachmentIndex].presentable;
    if ( presentable != nullptr )
    {
      idPresentable::Delete(this: presentable);
      this->attachments.list[v5].presentable = nullptr;
    }
    idList<idAttachment,5>::RemoveIndexFast(this: &this->attachments, index: v4);
  }
}


// ========================================================================
// ?FindAttachment@idAttachmentCollection@@QBA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PAVidInventoryItem@@@Z
// EA  : 0x82C08558
// RVA : 0x00C08558
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::FindAttachment(
        idAttachmentCollection *this,
        idHandle<int,enum invalidAttachment_t,-1> *result,
        idInventoryItem *item)
{
  int value; // r7
  int v4; // r10
  int v5; // r8
  int v6; // r11
  int v7; // r9

  value = result[1].value;
  v4 = 0;
  if ( value <= 0 )
    goto LABEL_5;
  v5 = result->value;
  v6 = 0;
  v7 = result->value;
  while ( *(idInventoryItem **)(v7 + 4) != item )
  {
    ++v4;
    v6 += 108;
    v7 = v6 + v5;
    if ( v4 >= value )
      goto LABEL_5;
  }
  if ( v4 < 0 )
LABEL_5:
    this->attachments.list = (idAttachment *)-1;
  else
    this->attachments.list = *(idAttachment **)(108 * v4 + v5 + 100);
  return this;
}


// ========================================================================
// ?UpdateRenderModelAttachments@idAttachmentCollection@@QAAXXZ
// EA  : 0x82C085C0
// RVA : 0x00C085C0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::UpdateRenderModelAttachments(idAttachmentCollection *this)
{
  int v2; // r21
  int v3; // r22
  idAttachment *v4; // r31
  int value; // r9
  idEntity *v6; // r3
  int num; // r11
  int v8; // r11
  idTreeAnimator *model; // r19
  int GameMs; // r3
  float *presentable; // r11
  idRenderModel *v12; // r11
  float *p_x; // r11
  float v14; // r10
  float v15; // r9
  idRenderModel *v16; // r11
  idMat3 *p_deferredAxis; // r11
  char *v18; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  __int64 v21; // r5
  unsigned int v22; // r9
  double v23; // fp31
  int GameMsPerFrame; // r19
  int v25; // r18
  const idDeclParticle *particleFx; // r31
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v28; // r7
  __int64 v29; // r5
  unsigned int v30; // r9
  double v31; // fp31
  int v32; // r19
  int v33; // r18
  const idDeclParticle *v34; // r31
  idRenderModelEffects *v35; // r3
  const idVec3 *v36; // r7
  int v37; // [sp+8h] [-178h]
  int v38; // [sp+Ch] [-174h]
  int v39; // [sp+10h] [-170h]
  int v40; // [sp+14h] [-16Ch]
  int v41; // [sp+18h] [-168h]
  int v42; // [sp+1Ch] [-164h]
  int v43; // [sp+20h] [-160h]
  int v44; // [sp+24h] [-15Ch]
  int v45; // [sp+28h] [-158h]
  int v46; // [sp+2Ch] [-154h]
  int v47; // [sp+30h] [-150h]
  int v48; // [sp+34h] [-14Ch]
  int v49; // [sp+38h] [-148h]
  int v50; // [sp+3Ch] [-144h]
  int v51; // [sp+40h] [-140h]
  int v52; // [sp+44h] [-13Ch]
  int v53; // [sp+48h] [-138h]
  int v54; // [sp+4Ch] [-134h]
  int v55; // [sp+50h] [-130h]
  unsigned int v56[2]; // [sp+60h] [-120h] BYREF
  __int64 v57; // [sp+68h] [-118h]
  __int64 v58; // [sp+70h] [-110h]
  idMat3 v59; // [sp+78h] [-108h] BYREF
  char v60; // [sp+9Ch] [-E4h] BYREF
  idMat3 v61; // [sp+A0h] [-E0h] BYREF
  idMat3 v62; // [sp+D0h] [-B0h] BYREF

  v2 = 0;
  if ( this->attachments.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->attachments.list[v3];
      value = v4->entity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
        || (v6 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
        || idEntity::CastTo(c: v6) == nullptr )
      {
        if ( v4->presentable != nullptr )
        {
          if ( (*((_BYTE *)v4 + 104) & 0x40) == 0 && (unsigned __int16)v4->jointIndex.value != 0xFFFF )
          {
            if ( (*((_BYTE *)v4 + 104) & 0x80) != 0 )
            {
              model = (idTreeAnimator *)v4->presentable->model;
              GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              idTreeAnimator::UpdateTime(this: model, time: GameMs);
            }
            if ( (*((_BYTE *)v4 + 104) & 4) == 0 )
            {
              presentable = (float *)v4->presentable;
              presentable[30] = v4->originOffset.x;
              presentable[31] = v4->originOffset.y;
              presentable[32] = v4->originOffset.z;
              v4->presentable->axis = *idQuat::ToMat3(this: (idQuat *)&v62, result: (idMat3 *)&v4->rotOffset);
            }
            v4->presentable->Present(this: v4->presentable);
            v12 = v4->presentable->model;
            if ( v12->useDeferredPosition )
              p_x = &v12->deferredOrigin.x;
            else
              p_x = &v12->g.origin.x;
            v14 = p_x[1];
            v15 = p_x[2];
            v59.mat[0].x = *p_x;
            v59.mat[0].y = v14;
            v59.mat[0].z = v15;
            v16 = v4->presentable->model;
            if ( v16->useDeferredPosition )
              p_deferredAxis = &v16->deferredAxis;
            else
              p_deferredAxis = &v16->g.axis;
            v18 = &v60;
            p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
            for ( i = 9; i != 0; --i )
            {
              ++p_z;
              v18 += 4;
              *(_DWORD *)v18 = *p_z;
            }
            v4->presentable->UpdateFX_2(this: v4->presentable, a2: v59.mat, a3: &v61);
            if ( v4->particleFx != nullptr )
            {
              if ( (*((_BYTE *)v4 + 104) & 0x80) != 0 )
              {
                idTreeAnimator::GetWorldSpaceTagTransform(
                  this: (idTreeAnimator *)v4->presentable->model,
                  tagData: &v4->particleFxTagData,
                  origin: (idVec3 *)&v59.mat[1].y,
                  axis: &v62);
                v56[0] = -1;
                HIDWORD(v21) = 1;
                v22 = 1664525 * clientGame->random.seed;
                clientGame->random.seed = v22 + 1013904223;
                LODWORD(v21) = ((v22 + 1013904223) >> 10) & 0x7FFF;
                v57 = v21;
                v23 = (float)((float)v21 * (float)0.000030518509);
                GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                                   this: &clientGame->gameTimeManager,
                                   type: GAMETIME_SCALED);
                v25 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                particleFx = v4->particleFx;
                MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
                idRenderModelEffects::AddParticles(
                  this: MergeBranch,
                  particle: particleFx,
                  systemStartTime: v25,
                  gameMsPerFrame: GameMsPerFrame,
                  diversity: v23,
                  origin: v28,
                  axis: (idMat3 *)&v59.mat[1].y,
                  velocity: v62.mat,
                  color: &vec3_origin.x,
                  a10: v37,
                  a11: v38,
                  a12: v39,
                  a13: v40,
                  a14: v41,
                  a15: v42,
                  a16: v43,
                  a17: v44,
                  a18: v45,
                  a19: v46,
                  a20: v47,
                  a21: v48,
                  a22: v49,
                  a23: v50,
                  a24: v51,
                  a25: v52,
                  a26: v53,
                  a27: v54,
                  a28: v55,
                  a29: v56);
              }
              else if ( (*((_BYTE *)v4 + 104) & 0x10) != 0 )
              {
                v56[0] = -1;
                HIDWORD(v29) = 1;
                v30 = 1664525 * clientGame->random.seed;
                clientGame->random.seed = v30 + 1013904223;
                LODWORD(v29) = ((v30 + 1013904223) >> 10) & 0x7FFF;
                v58 = v29;
                v31 = (float)((float)v29 * (float)0.000030518509);
                v32 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                v33 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                v34 = v4->particleFx;
                v35 = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
                idRenderModelEffects::AddParticles(
                  this: v35,
                  particle: v34,
                  systemStartTime: v33,
                  gameMsPerFrame: v32,
                  diversity: v31,
                  origin: v36,
                  axis: &v59,
                  velocity: v61.mat,
                  color: &vec3_origin.x,
                  a10: v37,
                  a11: v38,
                  a12: v39,
                  a13: v40,
                  a14: v41,
                  a15: v42,
                  a16: v43,
                  a17: v44,
                  a18: v45,
                  a19: v46,
                  a20: v47,
                  a21: v48,
                  a22: v49,
                  a23: v50,
                  a24: v51,
                  a25: v52,
                  a26: v53,
                  a27: v54,
                  a28: v55,
                  a29: v56);
              }
            }
          }
        }
        else
        {
          if ( v2 >= 0 )
          {
            num = this->attachments.num;
            if ( v2 < num )
            {
              v8 = num - 1;
              this->attachments.num = v8;
              if ( v2 != v8 )
                idAttachment::operator=(this: &this->attachments.list[v3], __that: &this->attachments.list[v8]);
            }
          }
          --v2;
          --v3;
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->attachments.num );
  }
}


// ========================================================================
// ?GetWorldSpaceAttachmentTransform@idAttachmentCollection@@QBAXABV?$idHandle@HW4invalidAttachment_t@@$0?0@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C089C0
// RVA : 0x00C089C0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::GetWorldSpaceAttachmentTransform(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle,
        idVec3 *origin,
        idMat3 *axis)
{
  int AttachmentIndex; // r3
  idAttachment *v8; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r27
  idAnimatedEntity *parent; // r30
  idPresentable *presentable; // r3

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  if ( AttachmentIndex < 0 )
    goto LABEL_6;
  v8 = &this->attachments.list[AttachmentIndex];
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->parent);
  if ( TreeAnimatorFromPresentable == nullptr )
    goto LABEL_6;
  parent = this->parent;
  presentable = parent->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: parent);
    presentable = parent->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceAttachmentTransform(
                          this: TreeAnimatorFromPresentable,
                          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v8->jointIndex.value,
                          translationOffset: &v8->originOffset,
                          rotationOffset: (idMat3 *)&v8->rotOffset,
                          origin,
                          axis) == 0 )
  {
LABEL_6:
    origin->z = 0.0;
    origin->y = 0.0;
    origin->x = 0.0;
    axis->mat[2].z = 1.0;
    axis->mat[1].y = 1.0;
    axis->mat[0].x = 1.0;
    axis->mat[1].z = 0.0;
    axis->mat[0].z = 0.0;
    axis->mat[0].y = 0.0;
    axis->mat[2].y = 0.0;
    axis->mat[2].x = 0.0;
    axis->mat[1].x = 0.0;
  }
}


// ========================================================================
// ?GetAttachmentWorldFrameDelta@idAttachmentCollection@@QBAXABV?$idHandle@HW4invalidAttachment_t@@$0?0@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C08A98
// RVA : 0x00C08A98
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::GetAttachmentWorldFrameDelta(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle,
        idVec3 *tDelta,
        idMat3 *rDelta)
{
  int AttachmentIndex; // r3
  idAttachment *v8; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r27
  idAnimatedEntity *parent; // r30
  idPresentable *presentable; // r3

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  if ( AttachmentIndex < 0 )
    goto LABEL_6;
  v8 = &this->attachments.list[AttachmentIndex];
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->parent);
  if ( TreeAnimatorFromPresentable == nullptr )
    goto LABEL_6;
  parent = this->parent;
  presentable = parent->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: parent);
    presentable = parent->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceAttachmentFrameDeltas(
                          this: TreeAnimatorFromPresentable,
                          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v8->jointIndex.value,
                          tOffset: &v8->originOffset,
                          rOffset: (idMat3 *)&v8->rotOffset,
                          tDelta,
                          rDelta) == 0 )
  {
LABEL_6:
    tDelta->z = 0.0;
    tDelta->y = 0.0;
    tDelta->x = 0.0;
    rDelta->mat[2].z = 1.0;
    rDelta->mat[1].y = 1.0;
    rDelta->mat[0].x = 1.0;
    rDelta->mat[1].z = 0.0;
    rDelta->mat[0].z = 0.0;
    rDelta->mat[0].y = 0.0;
    rDelta->mat[2].y = 0.0;
    rDelta->mat[2].x = 0.0;
    rDelta->mat[1].x = 0.0;
  }
}


// ========================================================================
// ?ShowAttachments@idAttachmentCollection@@QAAX_N@Z
// EA  : 0x82C08B70
// RVA : 0x00C08B70
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::ShowAttachments(idAttachmentCollection *this, bool hideVehicleAttachments)
{
  int v4; // r28
  int v5; // r30
  idAttachment *v6; // r31
  idInventoryItem *item; // r11

  v4 = 0;
  if ( this->attachments.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->attachments.list[v5];
      if ( gameLocal->spawnIds.ptr[v6->entity.spawnId.value & 0x1FFF] != v6->entity.spawnId.value >> 13
        && (*((_BYTE *)v6 + 104) & 8) == 0
        && (!hideVehicleAttachments || !v6->item->decl->vehicleAttachment) )
      {
        item = v6->item;
        if ( item == nullptr || !item->decl->initiallyHidden )
        {
          v6->presentable->Show(this: v6->presentable);
          *((_BYTE *)v6 + 104) &= ~0x40u;
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->attachments.num );
  }
}


// ========================================================================
// ?HideAttachments@idAttachmentCollection@@QAAXXZ
// EA  : 0x82C08C58
// RVA : 0x00C08C58
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::HideAttachments(idAttachmentCollection *this)
{
  int v2; // r27
  int v3; // r30
  idAttachment *v4; // r31

  v2 = 0;
  if ( this->attachments.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->attachments.list[v3];
      if ( gameLocal->spawnIds.ptr[v4->entity.spawnId.value & 0x1FFF] != v4->entity.spawnId.value >> 13 )
      {
        v4->presentable->Hide(this: v4->presentable, a2: true);
        *((_BYTE *)v4 + 104) |= 0x40u;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->attachments.num );
  }
}


// ========================================================================
// ?ShowAttachment@idAttachmentCollection@@QAAXABV?$idHandle@HW4invalidAttachment_t@@$0?0@@@Z
// EA  : 0x82C08CF0
// RVA : 0x00C08CF0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::ShowAttachment(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle)
{
  _DWORD *v2; // r5
  int AttachmentIndex; // r3
  _DWORD *v4; // r31
  idEntity *v5; // r3
  idEntity *v6; // r3

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  if ( AttachmentIndex >= 0 )
  {
    v4 = (_DWORD *)(108 * AttachmentIndex + *v2);
    if ( gameLocal->spawnIds.ptr[v4[22] & 0x1FFF] == (int)v4[22] >> 13 )
    {
      v5 = gameLocal->entities.ptr[v4[22] & 0x1FFF];
      if ( v5 != nullptr )
      {
        v6 = idEntity::CastTo(c: v5);
        v6->Show(this: v6);
      }
      else
      {
        (*(void (**)(void))(MEMORY[0] + 136))();
      }
    }
    else
    {
      (*(void (__fastcall **)(_DWORD))(*(_DWORD *)*v4 + 200))(a1: *v4);
      *((_BYTE *)v4 + 104) &= ~0x40u;
    }
  }
}


// ========================================================================
// ?HideAttachment@idAttachmentCollection@@QAAXABV?$idHandle@HW4invalidAttachment_t@@$0?0@@_N@Z
// EA  : 0x82C08DF8
// RVA : 0x00C08DF8
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::HideAttachment(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle,
        bool ignoreShowAll)
{
  int AttachmentIndex; // r3
  idAttachment *v6; // r31
  idEntity *v7; // r3
  idEntity *v8; // r3

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  if ( AttachmentIndex >= 0 )
  {
    v6 = &this->attachments.list[AttachmentIndex];
    if ( gameLocal->spawnIds.ptr[v6->entity.spawnId.value & 0x1FFF] == v6->entity.spawnId.value >> 13 )
    {
      v7 = gameLocal->entities.ptr[v6->entity.spawnId.value & 0x1FFF];
      if ( v7 != nullptr )
      {
        v8 = idEntity::CastTo(c: v7);
        v8->Hide_2(this: v8);
      }
      else
      {
        (*(void (**)(void))(MEMORY[0] + 132))();
      }
    }
    else
    {
      v6->presentable->Hide(this: v6->presentable, a2: true);
      *((_BYTE *)v6 + 104) = (8 * ignoreShowAll) & 8 | 0x40 | *((_BYTE *)v6 + 104) & 0xF7;
    }
  }
}


// ========================================================================
// ?FindAttachmentIndex@idAttachmentCollection@@ABAHPBVidEntity@@@Z
// EA  : 0x82C08EF8
// RVA : 0x00C08EF8
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

int __fastcall idAttachmentCollection::FindAttachmentIndex(idAttachmentCollection *this, const idEntity *ent)
{
  int v4; // r29
  int v5; // r31
  idGameLocal *v6; // r9
  int value; // r10
  idEntity *v8; // r3
  idEntity *v9; // r3

  v4 = 0;
  if ( this->attachments.num <= 0 )
    return -1;
  v5 = 0;
  v6 = gameLocal;
  while ( 1 )
  {
    value = this->attachments.list[v5].entity.spawnId.value;
    if ( v6->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v8 = v6->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
      v6 = gameLocal;
    }
    else
    {
      v9 = nullptr;
    }
    if ( v9 == ent )
      break;
    ++v4;
    ++v5;
    if ( v4 >= this->attachments.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?RebindAttachment@idAttachmentCollection@@QAA_NABV?$idHandle@HW4invalidAttachment_t@@$0?0@@ABUtagData_t@@@Z
// EA  : 0x82C08FB0
// RVA : 0x00C08FB0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

int __fastcall idAttachmentCollection::RebindAttachment(
        idAttachmentCollection *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle,
        const tagData_t *tagData)
{
  int AttachmentIndex; // r3
  idAttachment *v7; // r31
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r28
  idAnimatedEntity *parent; // r27
  idPresentable *presentable; // r3
  idAnimatedEntity *v11; // r30
  idPresentable *v12; // r4
  idAnimatedEntity *v13; // r30
  idPresentable *v14; // r11
  idEntity *v15; // r30
  char v16; // [sp+50h] [-80h] BYREF
  idVec3 v17[2]; // [sp+58h] [-78h] BYREF
  idMat3 v18[2]; // [sp+70h] [-60h] BYREF

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, handle);
  if ( AttachmentIndex < 0 )
    return 0;
  v7 = &this->attachments.list[AttachmentIndex];
  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->parent);
  if ( TreeAnimatorFromPresentable == nullptr )
    return 0;
  parent = this->parent;
  presentable = parent->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->parent);
    presentable = parent->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  v7->jointIndex.value = HIWORD(idTreeAnimator::GetJointIndex(
                                  this: (idTreeAnimator *)&v16,
                                  result: TreeAnimatorFromPresentable,
                                  jointHandle: &tagData->parentJoint)->__vftable);
  v7->originOffset.x = tagData->trans.x;
  v7->originOffset.y = tagData->trans.y;
  v7->originOffset.z = tagData->trans.z;
  v7->rotOffset.x = tagData->rot.x;
  v7->rotOffset.y = tagData->rot.y;
  v7->rotOffset.z = tagData->rot.z;
  v7->rotOffset.w = tagData->rot.w;
  if ( v7->presentable != nullptr )
  {
    v11 = this->parent;
    v12 = v11->presentable;
    if ( v12 == nullptr )
    {
      idEntity::InitPresentableInternal(this: this->parent);
      v12 = v11->presentable;
    }
    idPresentable::SetParent(
      this: v7->presentable,
      p: v12,
      j: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v7->jointIndex.value);
    v13 = this->parent;
    v14 = v13->presentable;
    if ( v14 == nullptr )
    {
      idEntity::InitPresentableInternal(this: this->parent);
      v14 = v13->presentable;
    }
    idPresentable::SetGroupMaster(this: v7->presentable, pres: v14);
    v7->presentable->Present(this: v7->presentable);
    return 1;
  }
  else
  {
    if ( idEntityPtr<idEntity const>::operator->(this: &v7->entity) != nullptr )
    {
      idTreeAnimator::GetWorldSpaceTagTransform(
        this: (idTreeAnimator *)TreeAnimatorFromPresentable,
        tagData,
        origin: v17,
        axis: v18);
      v15 = idEntityPtr<idEntity const>::operator->(this: &v7->entity);
      idEntity::Unbind(this: v15);
      idEntity::SetOrigin(this: v15, org: v17);
      v15->SetAxis(this: v15, a2: v18);
      idEntity::BindToJoint(
        this: v15,
        master: this->parent,
        jointnum: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v7->jointIndex.value,
        orientated: true);
    }
    return 1;
  }
}


// ========================================================================
// ?RemoveAttachment@idAttachmentCollection@@QAAXPBVidEntity@@@Z
// EA  : 0x82C09168
// RVA : 0x00C09168
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::RemoveAttachment(idAttachmentCollection *this, const idEntity *ent)
{
  int AttachmentIndex; // r3
  int v4; // r29
  idAttachment *v5; // r31
  int value; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  idEntity *v9; // r30
  idPhysics *Physics; // r3

  if ( ent != nullptr )
  {
    AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, ent);
    v4 = AttachmentIndex;
    if ( AttachmentIndex >= 0 )
    {
      v5 = &this->attachments.list[AttachmentIndex];
      value = v5->entity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v7 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v7 != nullptr )
        {
          v8 = idEntity::CastTo(c: v7);
          v9 = v8;
          if ( v8 != nullptr )
          {
            idEntity::Unbind(this: v8);
            if ( (*((_BYTE *)v5 + 104) & 0x20) != 0 && idEntity::GetPhysics(this: v9) != nullptr )
            {
              Physics = idEntity::GetPhysics(this: v9);
              Physics->LinkClip(this: Physics);
            }
          }
        }
      }
      idList<idAttachment,5>::RemoveIndexFast(this: &this->attachments, index: v4);
    }
    else
    {
      idLib::Warning(fmt: "idAttachmentCollection::RemoveAttachment - attempt to remove entity attachment that doesn't exist");
    }
  }
  else
  {
    idLib::Warning(fmt: "idAttachmentCollection::RemoveAttachment - attempt to remove a NULL entity");
  }
}


// ========================================================================
// ?FindAttachment@idAttachmentCollection@@QBA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PBDV?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82C09268
// RVA : 0x00C09268
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::FindAttachment(
        idAttachmentCollection *this,
        idHandle<int,enum invalidAttachment_t,-1> *result,
        const char *modelName,
        idIndex<short,enum invalidJointIndex_t> *jointIndex)
{
  int v7; // r27
  int v8; // r26
  int v9; // r28
  int v10; // r31
  idPresentable *presentable; // r11
  int v12; // r10
  idEntity *v13; // r3
  int v14; // r10
  idEntity *v15; // r3
  idEntity *v16; // r31

  v7 = 0;
  if ( result[1].value <= 0 )
  {
LABEL_16:
    this->attachments.list = (idAttachment *)-1;
    return this;
  }
  else
  {
    v8 = (__int16)jointIndex;
    v9 = 0;
    while ( 1 )
    {
      v10 = v9 + result->value;
      if ( *(__int16 *)(v10 + 92) == v8 )
      {
        presentable = *(idPresentable **)v10;
        if ( *(_DWORD *)v10 != 0 )
          goto LABEL_14;
        v12 = *(_DWORD *)(v10 + 88);
        if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13 )
        {
          v13 = gameLocal->entities.ptr[v12 & 0x1FFF];
          if ( v13 != nullptr && idEntity::CastTo(c: v13) != nullptr )
          {
            v14 = *(_DWORD *)(v10 + 88);
            if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
              && (v15 = gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
            {
              v16 = idEntity::CastTo(c: v15);
            }
            else
            {
              v16 = nullptr;
            }
            presentable = v16->presentable;
            if ( presentable != nullptr
              || (idEntity::InitPresentableInternal(this: v16), (presentable = v16->presentable) != nullptr) )
            {
LABEL_14:
              if ( idStr::Icmp(s1: presentable->model->name.str, s2: modelName) == 0 )
                break;
            }
          }
        }
      }
      ++v7;
      v9 += 108;
      if ( v7 >= result[1].value )
        goto LABEL_16;
    }
    this->attachments.list = *(idAttachment **)(108 * v7 + result->value + 100);
    return this;
  }
}


// ========================================================================
// ?FreeAttachments@idAttachmentCollection@@QAAXXZ
// EA  : 0x82C093D8
// RVA : 0x00C093D8
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::FreeAttachments(idAttachmentCollection *this)
{
  int v2; // r27
  int v3; // r28
  idAttachment *v4; // r31
  int value; // r9
  idEntity *v6; // r3
  int v7; // r9
  idEntity *v8; // r3
  idEntity *v9; // r3

  v2 = 0;
  if ( this->attachments.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->attachments.list[v3];
      value = v4->entity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
        && idEntity::CastTo(c: v6) != nullptr )
      {
        v7 = v4->entity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
        {
          v9 = idEntity::CastTo(c: v8);
          idEventReceiver::PostEventMS(this: v9, ev: &EV_Remove, time: 0);
          v4->entity.spawnId.value = 0x1FFF;
        }
        else
        {
          idEventReceiver::PostEventMS(this: nullptr, ev: &EV_Remove, time: 0);
          v4->entity.spawnId.value = 0x1FFF;
        }
      }
      else if ( v4->presentable != nullptr )
      {
        idPresentable::Delete(this: v4->presentable);
        v4->presentable = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->attachments.num );
  }
  if ( this->attachments.listStatic == 0 || this->attachments.listStatic == 2 )
  {
    if ( this->attachments.list != nullptr )
      idMem::Free(this: &mem, ptr: this->attachments.list, align: ALIGN_16);
    this->attachments.list = nullptr;
    this->attachments.size = 0;
  }
  this->attachments.num = 0;
}


// ========================================================================
// ?FindAttachmentIndex@idAttachmentCollection@@ABAHPBD@Z
// EA  : 0x82C09538
// RVA : 0x00C09538
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

int __fastcall idAttachmentCollection::FindAttachmentIndex(idAttachmentCollection *this, const char *modelName)
{
  int v4; // r26
  int i; // r29
  idPresentable *presentable; // r30
  idAttachment *v7; // r31
  int value; // r9
  idEntity *v9; // r3
  int v10; // r9
  idEntity *v11; // r3
  idEntity *v12; // r31

  v4 = 0;
  if ( this->attachments.num <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    presentable = nullptr;
    v7 = &this->attachments.list[i];
    if ( v7->presentable != nullptr )
    {
      presentable = v7->presentable;
    }
    else
    {
      value = v7->entity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v9 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v9 != nullptr && idEntity::CastTo(c: v9) != nullptr )
        {
          v10 = v7->entity.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
            && (v11 = gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
          {
            v12 = idEntity::CastTo(c: v11);
          }
          else
          {
            v12 = nullptr;
          }
          presentable = v12->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: v12);
            presentable = v12->presentable;
          }
        }
      }
    }
    if ( idStr::Icmp(s1: presentable->model->name.str, s2: modelName) == 0 )
      break;
    if ( ++v4 >= this->attachments.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?RemoveAttachment@idAttachmentCollection@@QAAXPBD@Z
// EA  : 0x82C09670
// RVA : 0x00C09670
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void __fastcall idAttachmentCollection::RemoveAttachment(idAttachmentCollection *this, const char *modelName)
{
  int AttachmentIndex; // r3
  int v4; // r30
  int v5; // r29

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this, modelName);
  v4 = AttachmentIndex;
  if ( AttachmentIndex >= 0 )
  {
    v5 = AttachmentIndex;
    idPresentable::Delete(this: this->attachments.list[AttachmentIndex].presentable);
    this->attachments.list[v5].presentable = nullptr;
    idList<idAttachment,5>::RemoveIndexFast(this: &this->attachments, index: v4);
  }
}


// ========================================================================
// ?FindAttachment@idAttachmentCollection@@QBA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PBD@Z
// EA  : 0x82C096C0
// RVA : 0x00C096C0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::FindAttachment(
        idAttachmentCollection *this,
        idAttachmentCollection *result,
        const char *modelName)
{
  int AttachmentIndex; // r3

  AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this: result, modelName);
  if ( AttachmentIndex < 0 )
    this->attachments.list = (idAttachment *)-1;
  else
    this->attachments.list = (idAttachment *)result->attachments.list[AttachmentIndex].handle.value;
  return this;
}


// ========================================================================
// ?AddAttachment@idAttachmentCollection@@QAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PAVidEntity@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82C09968
// RVA : 0x00C09968
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::AddAttachment(
        idAttachmentCollection *this,
        idList<idAttachment,5> *result,
        idEntity *ent,
        idIndex<short,enum invalidJointIndex_t> *jointIndex)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r29
  int list; // r31
  idPresentable *v11; // r3
  char v12; // r29
  idPhysics *Physics; // r31
  float *v14; // r3
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // r6
  double v16; // fp7
  double v17; // fp6
  const idMat3 *v18; // r3
  idQuat *v19; // r3
  idQuat *v20; // r3
  idClipModel *(__fastcall *GetClipModel)(idPhysics *, int); // r10
  double x; // fp31
  double y; // fp30
  double z; // fp29
  double w; // fp28
  int v26; // r3
  bool v27; // r11
  idPresentable *presentable; // r11
  char v29; // r29
  int v30; // r9
  idVec3 v31; // [sp+50h] [-150h] BYREF
  idAttachment v32; // [sp+60h] [-140h] BYREF
  idMat3 v33; // [sp+D0h] [-D0h] BYREF
  idMat3 v34[2]; // [sp+110h] [-90h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: (idAnimatedEntity *)result[1].list);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    list = (int)result[1].list;
    v11 = *(idPresentable **)(list + 488);
    if ( v11 == nullptr )
    {
      idEntity::InitPresentableInternal(this: (idEntity *)result[1].list);
      v11 = *(idPresentable **)(list + 488);
    }
    idPresentable::UpdateModelTransform(this: v11);
    idAttachment::idAttachment(this: &v32);
    v32.jointIndex.value = (__int16)jointIndex;
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: TreeAnimatorFromPresentable,
      pose: DRIVER_MODEL,
      jointIndex,
      origin: &v31,
      axis: (idMat3 *)&v33.mat[1].y);
    if ( ent != nullptr )
      v32.entity.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
    else
      v32.entity.spawnId.value = 0x1FFF;
    v32.presentable = nullptr;
    v12 = *((_BYTE *)&v32 + 104) & 0x6F;
    Physics = idEntity::GetPhysics(this: ent);
    v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    GetAxis = Physics->GetAxis;
    v16 = (float)(v14[1] - v31.y);
    v17 = (float)(v14[2] - v31.z);
    v32.originOffset.x = *v14 - v31.x;
    v32.originOffset.y = v16;
    v32.originOffset.z = v17;
    v18 = GetAxis(this: Physics, a2: 0);
    v19 = (idQuat *)idMat3::TransposeMultiply(this: v34, result: (idMat3 *)&v33.mat[1].y, b: v18);
    v20 = idMat3::ToQuat(this: &v33, result: v19);
    GetClipModel = Physics->GetClipModel;
    x = v20->x;
    y = v20->y;
    z = v20->z;
    w = v20->w;
    v32.rotOffset.x = v20->x;
    v32.rotOffset.y = y;
    v32.rotOffset.z = z;
    v32.rotOffset.w = w;
    v26 = (int)GetClipModel(this: Physics, a2: 0);
    v27 = v26 != 0 && *(_DWORD *)(v26 + 160) != 0;
    v29 = (32 * v27) & 0x20 | v12 & 0xDF;
    presentable = ent->presentable;
    *((_BYTE *)&v32 + 104) = v29;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: ent);
      presentable = ent->presentable;
    }
    presentable->model->useDeferredPosition = false;
    idEntity::BindToJoint(this: ent, master: (idEntity *)result[1].list, jointnum: jointIndex, orientated: true);
    if ( (v29 & 0x20) != 0 )
      Physics->UnlinkClip(this: Physics);
    v32.savedRotOffset.x = x;
    v32.savedRotOffset.y = y;
    v32.savedRotOffset.z = z;
    v32.savedRotOffset.w = w;
    v30 = idAttachmentCollection::handleCounter++;
    if ( idAttachmentCollection::handleCounter < 0 )
      idAttachmentCollection::handleCounter = 0;
    v32.handle.value = v30;
    idList<idAttachment,5>::Append(this: result, obj: &v32);
    this->attachments.list = (idAttachment *)v32.handle.value;
    return this;
  }
  else
  {
    idLib::Warning(fmt: "idAttachmentCollection::AddAttachment - actor has no animator");
    this->attachments.list = (idAttachment *)-1;
    return this;
  }
}


// ========================================================================
// ?AddAttachment@idAttachmentCollection@@QAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PAVidEntity@@ABUtagData_t@@@Z
// EA  : 0x82C09C10
// RVA : 0x00C09C10
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::AddAttachment(
        idAttachmentCollection *this,
        idAttachmentCollection *result,
        idEntity *ent,
        const tagData_t *tagData)
{
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r29
  int value; // r11
  int parent; // r28
  idPresentable *v11; // r3
  __int16 *JointIndex; // r3
  idIndex<short,enum invalidJointIndex_t> *v13; // r26
  int v14; // r29
  int v15; // r11
  float *v16; // r11
  double v17; // fp12
  double v18; // fp13
  double v19; // fp0
  double v20; // fp31
  double v21; // fp30
  double v22; // fp29
  double w; // fp28
  char v24; // r31
  idPhysics *Physics; // r29
  int v26; // r3
  bool v27; // r11
  idPresentable *presentable; // r11
  char v29; // r31
  int v30; // r9
  int AttachmentIndex; // r3
  float x; // [sp+50h] [-120h]
  float y; // [sp+54h] [-11Ch]
  float z; // [sp+58h] [-118h]
  char v36; // [sp+5Ch] [-114h] BYREF
  idAttachment v37; // [sp+60h] [-110h] BYREF
  idVec3 v38; // [sp+D0h] [-A0h] BYREF
  idMat3 v39[2]; // [sp+E0h] [-90h] BYREF

  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result->parent);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    parent = (int)result->parent;
    v11 = *(idPresentable **)(parent + 488);
    if ( v11 == nullptr )
    {
      idEntity::InitPresentableInternal(this: result->parent);
      v11 = *(idPresentable **)(parent + 488);
    }
    idPresentable::UpdateModelTransform(this: v11);
    idAttachment::idAttachment(this: &v37);
    JointIndex = (__int16 *)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)&v36,
                              result: TreeAnimatorFromPresentable,
                              jointHandle: &tagData->parentJoint);
    v13 = (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)*JointIndex;
    v37.jointIndex.value = *JointIndex;
    idTreeAnimator::GetWorldSpaceTagTransform(
      this: (idTreeAnimator *)TreeAnimatorFromPresentable,
      tagData,
      origin: &v38,
      axis: v39);
    x = tagData->trans.x;
    y = tagData->trans.y;
    z = tagData->trans.z;
    v14 = (int)result->parent;
    v15 = *(_DWORD *)(v14 + 488);
    if ( v15 == 0 )
    {
      idEntity::InitPresentableInternal(this: result->parent);
      v15 = *(_DWORD *)(v14 + 488);
    }
    v16 = *(float **)(v15 + 168);
    v17 = (float)(z * v16[43]);
    v18 = (float)(y * v16[42]);
    v19 = (float)(x * v16[41]);
    if ( ent != nullptr )
      v37.entity.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
    else
      v37.entity.spawnId.value = 0x1FFF;
    v20 = tagData->rot.x;
    v21 = tagData->rot.y;
    v22 = tagData->rot.z;
    w = tagData->rot.w;
    v37.rotOffset.x = tagData->rot.x;
    v37.presentable = nullptr;
    v37.rotOffset.y = v21;
    v24 = *((_BYTE *)&v37 + 104) & 0x6F;
    v37.rotOffset.z = v22;
    v37.rotOffset.w = w;
    v37.originOffset.x = v19;
    v37.originOffset.y = v18;
    v37.originOffset.z = v17;
    Physics = idEntity::GetPhysics(this: ent);
    v26 = (int)Physics->GetClipModel(this: Physics, a2: 0);
    v27 = v26 != 0 && *(_DWORD *)(v26 + 160) != 0;
    v29 = (32 * v27) & 0x20 | v24 & 0xDF;
    presentable = ent->presentable;
    *((_BYTE *)&v37 + 104) = v29;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: ent);
      presentable = ent->presentable;
    }
    presentable->model->useDeferredPosition = false;
    idEntity::Unbind(this: ent);
    idEntity::SetOrigin(this: ent, org: &v38);
    ent->SetAxis(this: ent, a2: v39);
    idEntity::BindToJoint(this: ent, master: result->parent, jointnum: v13, orientated: true);
    if ( (v29 & 0x20) != 0 )
      Physics->UnlinkClip(this: Physics);
    v37.savedRotOffset.x = v20;
    v37.savedRotOffset.y = v21;
    v37.savedRotOffset.z = v22;
    v37.savedRotOffset.w = w;
    v30 = idAttachmentCollection::handleCounter++;
    if ( idAttachmentCollection::handleCounter < 0 )
      idAttachmentCollection::handleCounter = 0;
    v37.handle.value = v30;
    AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(this: result, ent);
    if ( AttachmentIndex < 0 )
      idList<idAttachment,5>::Append(this: &result->attachments, obj: &v37);
    else
      idAttachment::operator=(this: &result->attachments.list[AttachmentIndex], __that: &v37);
    value = v37.handle.value;
  }
  else
  {
    value = -1;
  }
  this->attachments.list = (idAttachment *)value;
  return this;
}


// ========================================================================
// ?AddAttachment@idAttachmentCollection@@QAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PAVidEntity@@PBD@Z
// EA  : 0x82C09EF8
// RVA : 0x00C09EF8
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::AddAttachment(
        idAttachmentCollection *this,
        idAttachmentCollection *result,
        idEntity *ent,
        const char *tag)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  int parent; // r31
  idPresentable *v11; // r11
  idRenderModel *RenderModelFromPresentable; // r3
  const idDeclMD6 *decl; // r11
  idRenderModel *v14; // r31
  const char *v15; // r5
  const char *str; // r4
  idPropsCollection *p_props; // r3
  const tagData_t *v18; // r6
  const idDeclMD6 *v19; // r11
  const char *v20; // r5

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result->parent);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    parent = (int)result->parent;
    v11 = *(idPresentable **)(parent + 488);
    if ( v11 == nullptr )
    {
      idEntity::InitPresentableInternal(this: result->parent);
      v11 = *(idPresentable **)(parent + 488);
    }
    idPresentable::UpdateModelTransform(this: v11);
    RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: ent);
    decl = TreeAnimatorFromPresentable->decl;
    v14 = RenderModelFromPresentable;
    if ( RenderModelFromPresentable != nullptr )
    {
      str = RenderModelFromPresentable->name.str;
      p_props = &decl->props;
      if ( decl == nullptr )
        p_props = nullptr;
      v18 = idPropsCollection::GetTag(this: p_props, propName: str, tagName: tag);
      if ( v18->parentJoint.value == 0xFFFF )
      {
        v19 = TreeAnimatorFromPresentable->decl;
        if ( v19 != nullptr )
          v20 = v19->name.str;
        else
          v20 = &byte_8200D768;
        idLib::Warning(
          fmt: "idAttachmentCollection::AddAttachment - prop '%s' for model '%s' has no tag info '%s'",
          v14->name.str,
          v20,
          tag);
        this->attachments.list = (idAttachment *)-1;
        return this;
      }
      else
      {
        idAttachmentCollection::AddAttachment(this, result, ent, tagData: v18);
        return this;
      }
    }
    else
    {
      if ( decl != nullptr )
        v15 = decl->name.str;
      else
        v15 = &byte_8200D768;
      idLib::Warning(
        fmt: "idAttachmentCollection::AddAttachment - entity '%s' attaching to '%s', missing render model",
        ent->name.data,
        v15);
      this->attachments.list = (idAttachment *)-1;
      return this;
    }
  }
  else
  {
    this->attachments.list = (idAttachment *)-1;
    return this;
  }
}


// ========================================================================
// ?AddAttachment@idAttachmentCollection@@QAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PBVidDeclEntityDef@@PBDH@Z
// EA  : 0x82C0A040
// RVA : 0x00C0A040
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::AddAttachment(
        idAttachmentCollection *this,
        idAttachmentCollection *result,
        const idDeclEntityDef *entityDef,
        const char *tag,
        int forceReplicationFlags)
{
  idAttachmentCollection *v5; // r30
  idEntity *v9; // r5

  v5 = this;
  if ( entityDef != nullptr )
  {
    v9 = (idEntity *)((int (__fastcall *)(idGameLocal *, const idDeclEntityDef *, int, int))gameLocal->SpawnEntityFromDef)(
                       a1: gameLocal,
                       a2: entityDef,
                       a3: -1,
                       a4: -1);
    if ( v9 != nullptr )
    {
      idAttachmentCollection::AddAttachment(this: v5, result, ent: v9, tag);
    }
    else
    {
      idLib::Warning(
        fmt: "idAttachmentCollection::AddAttachment - Failed to spawn entity from entityDef '%s'",
        entityDef->name.str);
      v5->attachments.list = (idAttachment *)-1;
    }
    return v5;
  }
  else
  {
    this->attachments.list = (idAttachment *)-1;
  }
  return this;
}


// ========================================================================
// ?AddAttachment@idAttachmentCollection@@QAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PBVidDeclInventory@@PBDPBVidAttachmentInfo@3@@Z
// EA  : 0x82C0A0F0
// RVA : 0x00C0A0F0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::AddAttachment(
        idAttachmentCollection *this,
        idList<idAttachment,5> *result,
        idDeclInventory *decl,
        const char *tagName,
        const idDeclInventory::idAttachmentInfo *fxAttachInfo)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r25
  int list; // r30
  idPresentable *v12; // r3
  const idDeclMD6 *thirdPersonMD6; // r11
  double attachmentOverrideScale; // fp31
  const idDeclMD6 *v15; // r11
  idStaticModel *thirdPersonStatic; // r11
  const idDeclMD6 *handsModelMD6; // r11
  const idDeclMD6 *v18; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *Tag; // r29
  const idDeclMD6 *v21; // r11
  const char *str; // r5
  const idHandle<unsigned short,enum invalidJointHandle_t,65535> *v23; // r4
  float y; // r7
  float z; // r6
  float x; // r5
  float v27; // r4
  float v28; // r3
  double v29; // fp29
  double v30; // fp30
  idTreeAnimator *v31; // r30
  void *v32; // r22
  idPresentableAnimatedEntity *v33; // r3
  idPresentableWeapon *presentable; // r11
  idPresentable *v35; // r3
  const idDeclWeapon *v36; // r27
  idVehicle *v37; // r3
  int entityNumber; // r28
  idVehicle *v39; // r3
  idEntity *Driver; // r3
  idPresentableWeapon *v41; // r3
  int v42; // r30
  idPresentable *v43; // r11
  int v44; // r10
  int v45; // r9
  int v46; // r8
  int v47; // r7
  const idMaterial *customMaterial; // r11
  void *v49; // r3
  double v50; // fp10
  double v51; // fp9
  double v52; // fp8
  idRenderModel *model; // r11
  idMat3 *v54; // r3
  idPresentable *v55; // r10
  double v56; // fp0
  int v57; // r30
  idPresentable *v58; // r11
  int suppressSurfaceInViewID; // r8
  idMat3 *p_axis; // r30
  idVec3 *p_origin; // r29
  idFXManager *p_fxManager; // r28
  int v63; // r3
  idEntity *v64; // r3
  idPresentable *v65; // r11
  idRenderModel *v66; // r10
  char v67; // r11
  idRenderModel *RenderModelFromPresentable; // r3
  int v69; // r9
  const idDeclParticle *particleFx; // r11
  idRenderModel *v71; // r30
  idRenderModel_vtbl *v72; // r11
  idPropsCollection *p_AddDecalFromPoint; // r3
  const tagData_t *v74; // r3
  int v76; // [sp+8h] [-228h]
  int v77; // [sp+Ch] [-224h]
  int v78; // [sp+10h] [-220h]
  int v79; // [sp+14h] [-21Ch]
  int v80; // [sp+18h] [-218h]
  idPresentable *v81; // [sp+1Ch] [-214h]
  idVec3 *p_rot; // [sp+50h] [-1E0h] BYREF
  idAttachment v83; // [sp+60h] [-1D0h] BYREF
  float v84; // [sp+D0h] [-160h]
  float v85; // [sp+D4h] [-15Ch]
  float v86; // [sp+D8h] [-158h]
  float v87; // [sp+E0h] [-150h]
  float v88; // [sp+E4h] [-14Ch]
  float v89; // [sp+E8h] [-148h]
  idStr v90; // [sp+F0h] [-140h] BYREF
  idStr v91; // [sp+110h] [-120h] BYREF
  idVec3 v92; // [sp+130h] [-100h] BYREF
  idMat3 v93; // [sp+140h] [-F0h] BYREF
  idQuat v94; // [sp+170h] [-C0h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: (idAnimatedEntity *)result[1].list);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    list = (int)result[1].list;
    v12 = *(idPresentable **)(list + 488);
    if ( v12 == nullptr )
    {
      idEntity::InitPresentableInternal(this: (idEntity *)result[1].list);
      v12 = *(idPresentable **)(list + 488);
    }
    idPresentable::UpdateModelTransform(this: v12);
    v90.len = 0;
    v90.allocedAndFlag = 20;
    v90.data = v90.baseBuffer;
    v90.baseBuffer[0] = 0;
    thirdPersonMD6 = decl->thirdPersonMD6;
    attachmentOverrideScale = -1.0;
    if ( thirdPersonMD6 != nullptr )
    {
      idStr::operator=(this: &v90, text: thirdPersonMD6->name.str);
      v15 = decl->thirdPersonMD6;
    }
    else
    {
      thirdPersonStatic = decl->thirdPersonStatic;
      if ( thirdPersonStatic != nullptr )
      {
        idStr::operator=(this: &v90, text: thirdPersonStatic->name.str);
LABEL_12:
        v18 = TreeAnimatorFromPresentable->decl;
        p_props = &v18->props;
        if ( v18 == nullptr )
          p_props = nullptr;
        Tag = idPropsCollection::GetTag(this: p_props, propName: v90.data, tagName);
        if ( Tag->parentJoint.value == 0xFFFF )
        {
          v21 = TreeAnimatorFromPresentable->decl;
          if ( v21 != nullptr )
            str = v21->name.str;
          else
            str = &byte_8200D768;
          idLib::Warning(
            fmt: "idAttachmentCollection::AddAttachment - prop '%s' for model '%s' has no tag info '%s'",
            v90.data,
            str,
            tagName);
          this->attachments.list = (idAttachment *)-1;
        }
        else
        {
          idAttachment::idAttachment(this: &v83);
          v83.jointIndex.value = HIWORD(idTreeAnimator::GetJointIndex(
                                          this: (idTreeAnimator *)&p_rot,
                                          result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable,
                                          jointHandle: v23)->__vftable);
          idTreeAnimator::GetWorldSpaceTagTransform(
            this: TreeAnimatorFromPresentable,
            tagData: Tag,
            origin: &v92,
            axis: &v93);
          y = TreeAnimatorFromPresentable->g.scale.y;
          z = TreeAnimatorFromPresentable->g.scale.z;
          x = Tag->trans.x;
          v27 = Tag->trans.y;
          v28 = Tag->trans.z;
          v84 = TreeAnimatorFromPresentable->g.scale.x;
          v85 = y;
          v86 = z;
          v87 = x;
          v88 = v27;
          v89 = v28;
          if ( attachmentOverrideScale <= 0.0 )
          {
            attachmentOverrideScale = v86;
            v30 = v85;
            v29 = v84;
          }
          else
          {
            v29 = attachmentOverrideScale;
            v30 = attachmentOverrideScale;
          }
          v83.item = nullptr;
          v83.entity.spawnId.value = 0x1FFF;
          v31 = (idTreeAnimator *)clientGame->renderWorld->AllocRenderModel(
                                    this: clientGame->renderWorld,
                                    a2: v90.data,
                                    a3: 1,
                                    a4: -1);
          v32 = _RTDynamicCast(
                  inptr: v31,
                  VfDelta: 0,
                  SrcType: &idRenderModel `RTTI Type Descriptor',
                  TargetType: &idTreeAnimator `RTTI Type Descriptor',
                  isReference: 0);
          if ( decl->GetDeclInfo(this: decl) == &idDeclWeapon::resourceList
            || decl->GetDeclInfo(this: decl) == &idDeclVehicleWeapon::resourceList )
          {
            v36 = (const idDeclWeapon *)_RTDynamicCast(
                                          inptr: decl,
                                          VfDelta: 0,
                                          SrcType: &idDeclInventory `RTTI Type Descriptor',
                                          TargetType: (void *)&idDeclWeapon `RTTI Type Descriptor',
                                          isReference: 0);
            if ( v36 != nullptr )
            {
              v37 = (idVehicle *)result[1].list;
              entityNumber = v37->entityNumber;
              if ( idVehicle::CastTo(c: v37) != nullptr )
              {
                v39 = idVehicle::CastTo(c: (idVehicle *)result[1].list);
                Driver = idVehicle::GetDriver(this: v39);
                if ( Driver != nullptr )
                  entityNumber = Driver->entityNumber;
              }
              v41 = (idPresentableWeapon *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                             size: 0x588u,
                                             tag: TAG_PRESENTABLE,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
              p_rot = (idVec3 *)v41;
              if ( v41 != nullptr )
                presentable = idPresentableWeapon::idPresentableWeapon(
                                this: v41,
                                renderModel_: v31,
                                weaponDecl_: v36,
                                ownerEntityNum_: entityNumber,
                                animStack_: nullptr,
                                ent_: nullptr,
                                useSphereModel_: false);
              else
                presentable = nullptr;
              v83.presentable = presentable;
            }
            else
            {
              presentable = (idPresentableWeapon *)v83.presentable;
            }
          }
          else if ( v32 != nullptr )
          {
            v33 = (idPresentableAnimatedEntity *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                   size: 0x4E0u,
                                                   tag: TAG_PRESENTABLE,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
            p_rot = (idVec3 *)v33;
            if ( v33 != nullptr )
              presentable = (idPresentableWeapon *)idPresentableAnimatedEntity::idPresentableAnimatedEntity(
                                                     this: v33,
                                                     ent: nullptr,
                                                     renderModel_: v31,
                                                     animStack_: nullptr,
                                                     entityNumber_: 0x1FFF,
                                                     fxDecl_: decl->weaponFX,
                                                     useSphereModel_: false);
            else
              presentable = nullptr;
            v83.presentable = presentable;
          }
          else
          {
            v35 = (idPresentable *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x4B0u,
                                     tag: TAG_PRESENTABLE,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
            p_rot = (idVec3 *)v35;
            if ( v35 != nullptr )
              presentable = (idPresentableWeapon *)idPresentable::idPresentable(
                                                     this: v35,
                                                     e: nullptr,
                                                     renderModel_: v31,
                                                     entityNumber_: 0x1FFF,
                                                     fxDecl_: nullptr);
            else
              presentable = nullptr;
            v83.presentable = presentable;
          }
          presentable->debugName = STATIC_ATTACHMENT_STRING;
          v42 = (int)result[1].list;
          v43 = *(idPresentable **)(v42 + 488);
          if ( v43 == nullptr )
          {
            idEntity::InitPresentableInternal(this: (idEntity *)result[1].list);
            v43 = *(idPresentable **)(v42 + 488);
          }
          idPresentable::SetParent(
            this: v83.presentable,
            p: v43,
            j: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v83.jointIndex.value);
          idClientGame::AddPresentable(
            this: clientGame,
            presentable: v83.presentable,
            index: -1,
            skipReplication: true,
            a5: v47,
            a6: v46,
            a7: v45,
            a8: v44,
            a9: v76,
            a10: v77,
            a11: v78,
            a12: v79,
            a13: v80,
            a14: v81);
          customMaterial = decl->customMaterial;
          if ( customMaterial != nullptr )
          {
            p_rot = (idVec3 *)decl->customMaterial;
            v83.presentable->model->g.customMaterial = customMaterial;
          }
          *((_BYTE *)&v83 + 104) = ((v32 != nullptr) << 7) | *((_BYTE *)&v83 + 104) & 0x7F;
          if ( (v32 != nullptr) << 7 == 0 )
          {
            v49 = _RTDynamicCast(
                    inptr: v83.presentable->model,
                    VfDelta: 0,
                    SrcType: &idRenderModel `RTTI Type Descriptor',
                    TargetType: &idRenderModelParticle `RTTI Type Descriptor',
                    isReference: 0);
            if ( v49 != nullptr )
            {
              *((_BYTE *)&v83 + 104) |= 0x10u;
              v83.particleFx = *((const idDeclParticle **)v49 + 526);
            }
          }
          v83.originOffset.x = v87;
          p_rot = (idVec3 *)&Tag->rot;
          v83.originOffset.y = v88;
          v83.originOffset.z = v89;
          v50 = (float)((float)v29 * decl->thirdPersonScale);
          v51 = (float)((float)v30 * decl->thirdPersonScale);
          v52 = (float)((float)attachmentOverrideScale * decl->thirdPersonScale);
          v83.rotOffset = Tag->rot;
          model = v83.presentable->model;
          model->g.scale.x = v50;
          model->g.scale.y = v51;
          model->g.scale.z = v52;
          p_rot = &model->g.scale;
          v83.presentable->origin = v83.originOffset;
          v54 = idQuat::ToMat3(this: &v94, result: (idMat3 *)&v83.rotOffset);
          v55 = v83.presentable;
          v56 = v54->mat[0].x;
          p_rot = &v54->mat[1];
          v83.presentable->axis.mat[0].x = v56;
          v55->axis.mat[0].y = v54->mat[0].y;
          p_rot = &v55->axis.mat[1];
          v55->axis.mat[0].z = v54->mat[0].z;
          p_rot = &v55->axis.mat[2];
          v55->axis.mat[1] = v54->mat[1];
          v55->axis.mat[2] = v54->mat[2];
          v83.presentable->model->g.suppressSurfaceInViewID = TreeAnimatorFromPresentable->g.suppressSurfaceInViewID;
          v83.presentable->model->g.suppressShadowInViewID = TreeAnimatorFromPresentable->g.suppressShadowInViewID;
          *((_BYTE *)&v83.presentable->model->g + 106) = *((_BYTE *)&v83.presentable->model->g + 106) & 0xFE
                                                       | *((_BYTE *)&TreeAnimatorFromPresentable->g + 106) & 1;
          v57 = (int)result[1].list;
          v58 = *(idPresentable **)(v57 + 488);
          if ( v58 == nullptr )
          {
            idEntity::InitPresentableInternal(this: (idEntity *)result[1].list);
            v58 = *(idPresentable **)(v57 + 488);
          }
          idPresentable::SetGroupMaster(this: v83.presentable, pres: v58);
          suppressSurfaceInViewID = TreeAnimatorFromPresentable->g.suppressSurfaceInViewID;
          p_rot = (idVec3 *)&v83.presentable->fxManager;
          v83.presentable->fxManager.suppressSurfaceInViewID = suppressSurfaceInViewID;
          p_axis = &v83.presentable->axis;
          p_origin = &v83.presentable->origin;
          p_fxManager = &v83.presentable->fxManager;
          v63 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          idFXManager::StartFX(this: p_fxManager, org: p_origin, axis: p_axis, time: v63, startCondition: 0);
          v64 = (idEntity *)result[1].list;
          v65 = v64->presentable;
          p_rot = (idVec3 *)v64;
          if ( v65 == nullptr || (v66 = v65->model, p_rot = (idVec3 *)v65, v67 = 1, v66 == nullptr) )
            v67 = 0;
          if ( v67 != 0 )
          {
            RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v64);
            v83.presentable->model->g.castDimShadows = RenderModelFromPresentable->g.castDimShadows;
          }
          v83.presentable->model->useDeferredPosition = false;
          v83.presentable->Present(this: v83.presentable);
          v83.savedRotOffset.x = v83.rotOffset.x;
          v83.savedRotOffset.y = v83.rotOffset.y;
          v83.savedRotOffset.z = v83.rotOffset.z;
          v69 = idAttachmentCollection::handleCounter;
          v83.savedRotOffset.w = v83.rotOffset.w;
          if ( ++idAttachmentCollection::handleCounter < 0 )
            idAttachmentCollection::handleCounter = 0;
          v83.handle.value = v69;
          if ( (*((_BYTE *)&v83 + 104) & 0x80) != 0 && fxAttachInfo != nullptr )
          {
            particleFx = fxAttachInfo->particleFx;
            if ( particleFx != nullptr )
            {
              v71 = v83.presentable->model;
              v83.particleFx = fxAttachInfo->particleFx;
              idStr::idStr(this: &v91, text: particleFx->name.str);
              idStr::SetFileExtension(this: &v91, extension: "prt");
              v72 = v71[1].__vftable;
              p_AddDecalFromPoint = (idPropsCollection *)&v72[7].AddDecalFromPoint;
              if ( v72 == nullptr )
                p_AddDecalFromPoint = nullptr;
              v74 = idPropsCollection::GetTag(
                      this: p_AddDecalFromPoint,
                      propName: v91.data,
                      tagName: fxAttachInfo->tagName.data);
              v83.particleFxTagData.trans.x = v74->trans.x;
              v83.particleFxTagData.trans.y = v74->trans.y;
              p_rot = (idVec3 *)&v74->rot;
              v83.particleFxTagData.trans.z = v74->trans.z;
              v83.particleFxTagData.rot = v74->rot;
              v83.particleFxTagData.parentJoint.value = v74->parentJoint.value;
              idStr::FreeData(this: &v91);
            }
          }
          idList<idAttachment,5>::Append(this: result, obj: &v83);
          this->attachments.list = (idAttachment *)v83.handle.value;
        }
LABEL_68:
        idStr::FreeData(this: &v90);
        return this;
      }
      handsModelMD6 = decl->handsModelMD6;
      if ( handsModelMD6 == nullptr )
      {
        if ( !decl->noAttachment )
          idLib::Warning(
            fmt: "idAttachmentCollection::AddAttachment - item '%s' has no third person model",
            decl->name.str);
        this->attachments.list = (idAttachment *)-1;
        goto LABEL_68;
      }
      idStr::operator=(this: &v90, text: handsModelMD6->name.str);
      v15 = decl->handsModelMD6;
    }
    attachmentOverrideScale = v15->attachmentOverrideScale;
    goto LABEL_12;
  }
  this->attachments.list = (idAttachment *)-1;
  return this;
}


// ========================================================================
// __unwind$492150
// EA  : 0x82C0A974
// RVA : 0x00C0A974
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void _unwind_492150()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 240));
}


// ========================================================================
// __unwind$492152
// EA  : 0x82C0A99C
// RVA : 0x00C0A99C
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void _unwind_492152()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 560 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// __unwind$492153
// EA  : 0x82C0A9C8
// RVA : 0x00C0A9C8
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void _unwind_492153()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 560 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// __unwind$492151
// EA  : 0x82C0A9F4
// RVA : 0x00C0A9F4
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void _unwind_492151()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 560 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// __unwind$492154
// EA  : 0x82C0AA20
// RVA : 0x00C0AA20
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void _unwind_492154()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 272));
}


// ========================================================================
// ?AddAttachment@idAttachmentCollection@@QAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PAVidInventoryItem@@PBDPBVidAttachmentInfo@idDeclInventory@@@Z
// EA  : 0x82C0AA48
// RVA : 0x00C0AA48
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::AddAttachment(
        idAttachmentCollection *this,
        idAttachmentCollection *result,
        idWeapon *item,
        const char *tagName,
        const idDeclInventory::idAttachmentInfo *fxAttachInfo)
{
  int parent; // r30
  idPresentable *v12; // r3
  int AttachmentIndex; // r30
  idWeapon *v14; // r29
  idStrId *DisplayName; // r3
  const char *LocalizedString; // r3
  idPresentableWeapon *v17; // r3
  idPresentableWeapon *v18; // r3
  idInventoryItem v19; // [sp+50h] [-40h] BYREF

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result->parent) == nullptr )
    goto LABEL_2;
  parent = (int)result->parent;
  v12 = *(idPresentable **)(parent + 488);
  if ( v12 == nullptr )
  {
    idEntity::InitPresentableInternal(this: result->parent);
    v12 = *(idPresentable **)(parent + 488);
  }
  idPresentable::UpdateModelTransform(this: v12);
  idAttachmentCollection::AddAttachment(
    this: (idAttachmentCollection *)&v19,
    result: &result->attachments,
    decl: (idDeclInventory *)item->decl,
    tagName,
    fxAttachInfo);
  if ( v19.__vftable == (idInventoryItem_vtbl *)-1 )
  {
LABEL_2:
    this->attachments.list = (idAttachment *)-1;
    return this;
  }
  else
  {
    AttachmentIndex = idAttachmentCollection::FindAttachmentIndex(
                        this: result,
                        handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v19);
    result->attachments.list[AttachmentIndex].item = item;
    v14 = idWeapon::CastTo(c: item);
    if ( v14 != nullptr )
    {
      if ( result->attachments.list[AttachmentIndex].presentable->GetWeaponInterface(this: result->attachments.list[AttachmentIndex].presentable) != nullptr )
      {
        v17 = result->attachments.list[AttachmentIndex].presentable->GetWeaponInterface(this: result->attachments.list[AttachmentIndex].presentable);
        idWeapon::SetPresentableWeapon(this: v14, presentableWeapon_: v17);
        v18 = result->attachments.list[AttachmentIndex].presentable->GetWeaponInterface(this: result->attachments.list[AttachmentIndex].presentable);
        idPresentableWeapon::SetClientWeapon(this: v18, weapon: v14);
      }
      else
      {
        DisplayName = idInventoryItem::GetDisplayName(this: &v19, result: (idStrId *)item);
        LocalizedString = idStrId::GetLocalizedString(this: DisplayName);
        idLib::Warning(fmt: "GetWeaponInterface is null on weapon %s", LocalizedString);
      }
    }
    this->attachments.list = (idAttachment *)result->attachments.list[AttachmentIndex].handle.value;
    return this;
  }
}


// ========================================================================
// ?AddAttachment@idAttachmentCollection@@QAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PBD00PBUtagData_t@@_N@Z
// EA  : 0x82C0ABB0
// RVA : 0x00C0ABB0
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::AddAttachment(
        idAttachmentCollection *this,
        idList<idAttachment,5> *result,
        const char *modelName,
        const char *propName,
        const char *tag,
        const tagData_t *tagInfo,
        bool allowDuplicate)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r24
  int list; // r30
  idPresentable *v16; // r11
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *v19; // r3
  const idDeclMD6 *v20; // r11
  const char *str; // r5
  const char *v22; // r4
  const tagData_t *v23; // r3
  int v24; // r25
  int v25; // r26
  idAttachment *v26; // r28
  idPresentable *v27; // r30
  idEntity *v28; // r3
  idEntity *v29; // r29
  int v30; // r30
  int v31; // r11
  float *v32; // r11
  float x; // r10
  float y; // r9
  float z; // r8
  float v36; // r7
  float v37; // r30
  float v38; // r25
  idRenderWorld *renderWorld; // r3
  idRenderModel *(__fastcall *AllocRenderModel)(idRenderWorld *, const char *, bool, int); // r10
  idTreeAnimator *v41; // r3
  idTreeAnimator *v42; // r29
  _DWORD *v43; // r28
  idPresentableAnimatedEntity *v44; // r3
  idPresentableAnimatedEntity *v45; // r10
  int v46; // r11
  double v47; // fp0
  idPresentable *v48; // r3
  int v49; // r30
  idPresentable *v50; // r11
  int v51; // r10
  int v52; // r9
  int v53; // r8
  int v54; // r7
  void *v55; // r3
  double v56; // fp6
  double v57; // fp5
  idRenderModel *model; // r11
  idMat3 *v59; // r3
  idPresentable *presentable; // r10
  int v61; // r30
  idPresentable *v62; // r11
  int v63; // r9
  const idDeclMD6 *v64; // r11
  int v66; // [sp+8h] [-1C8h]
  int v67; // [sp+Ch] [-1C4h]
  int v68; // [sp+10h] [-1C0h]
  int v69; // [sp+14h] [-1BCh]
  int v70; // [sp+18h] [-1B8h]
  idPresentable *v71; // [sp+1Ch] [-1B4h]
  __int16 v72; // [sp+54h] [-17Ch] BYREF
  float v73; // [sp+58h] [-178h]
  float v74; // [sp+5Ch] [-174h]
  float v75; // [sp+60h] [-170h]
  idAttachment v76; // [sp+70h] [-160h] BYREF
  float v77; // [sp+E0h] [-F0h]
  float v78; // [sp+E4h] [-ECh]
  float v79; // [sp+E8h] [-E8h]
  idVec3 v80; // [sp+F0h] [-E0h] BYREF
  idQuat v81; // [sp+100h] [-D0h] BYREF
  idMat3 v82; // [sp+130h] [-A0h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: (idAnimatedEntity *)result[1].list);
  if ( TreeAnimatorFromPresentable == nullptr )
  {
    this->attachments.list = (idAttachment *)-1;
    return this;
  }
  list = (int)result[1].list;
  v16 = *(idPresentable **)(list + 488);
  if ( v16 == nullptr )
  {
    idEntity::InitPresentableInternal(this: (idEntity *)result[1].list);
    v16 = *(idPresentable **)(list + 488);
  }
  idPresentable::UpdateModelTransform(this: v16);
  if ( tagInfo == nullptr )
  {
    decl = TreeAnimatorFromPresentable->decl;
    p_props = &decl->props;
    if ( propName != nullptr )
    {
      if ( decl == nullptr )
        p_props = nullptr;
      v19 = idPropsCollection::GetTag(this: p_props, propName, tagName: tag);
      tagInfo = v19;
      if ( v19 == nullptr || v19->parentJoint.value == 0xFFFF )
      {
        v20 = TreeAnimatorFromPresentable->decl;
        if ( v20 != nullptr )
        {
          str = v20->name.str;
          v22 = propName;
        }
        else
        {
          v22 = propName;
          str = &byte_8200D768;
        }
LABEL_59:
        idLib::Warning(
          fmt: "idAttachmentCollection::AddAttachment - prop '%s' for model '%s' has no tag info for tag '%s'",
          v22,
          str,
          tag);
        this->attachments.list = (idAttachment *)-1;
        return this;
      }
    }
    else
    {
      if ( decl == nullptr )
        p_props = nullptr;
      v23 = idPropsCollection::GetTag(this: p_props, propName: modelName, tagName: tag);
      tagInfo = v23;
      if ( v23 == nullptr || v23->parentJoint.value == 0xFFFF )
      {
        v64 = TreeAnimatorFromPresentable->decl;
        if ( v64 != nullptr )
          str = v64->name.str;
        else
          str = &byte_8200D768;
        v22 = modelName;
        goto LABEL_59;
      }
    }
  }
  idTreeAnimator::GetJointIndex(
    this: (idTreeAnimator *)&v72,
    result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable,
    jointHandle: &tagInfo->parentJoint);
  if ( allowDuplicate || (v24 = 0, result->num <= 0) )
  {
LABEL_29:
    memset(&v76, 0, 12);
    *((_BYTE *)&v76 + 104) &= 3u;
    v76.particleFxTagData.trans.x = 0.0;
    v76.jointIndex.value = v72;
    v76.particleFxTagData.trans.y = 0.0;
    v76.particleFxTagData.parentJoint.value = -1;
    v76.particleFxTagData.trans.z = 0.0;
    v76.entity.spawnId.value = 0x1FFF;
    v76.particleFxTagData.rot.x = 0.0;
    v76.rotationAxis = -1;
    v76.particleFxTagData.rot.y = 0.0;
    v76.handle.value = -1;
    v76.particleFxTagData.rot.z = 0.0;
    v76.particleFxTagData.rot.w = 0.0;
    v76.originOffset.x = 0.0;
    v76.originOffset.y = 0.0;
    v76.originOffset.z = 0.0;
    v76.savedRotOffset.x = 0.0;
    v76.savedRotOffset.y = 0.0;
    v76.savedRotOffset.z = 0.0;
    v76.savedRotOffset.w = 0.0;
    v76.rotOffset.x = 0.0;
    v76.rotOffset.y = 0.0;
    v76.rotOffset.z = 0.0;
    v76.rotOffset.w = 0.0;
    idTreeAnimator::GetWorldSpaceTagTransform(
      this: TreeAnimatorFromPresentable,
      tagData: tagInfo,
      origin: &v80,
      axis: &v82);
    v30 = (int)result[1].list;
    v31 = *(_DWORD *)(v30 + 488);
    if ( v31 == 0 )
    {
      idEntity::InitPresentableInternal(this: (idEntity *)result[1].list);
      v31 = *(_DWORD *)(v30 + 488);
    }
    v32 = *(float **)(v31 + 168);
    x = tagInfo->trans.x;
    y = tagInfo->trans.y;
    z = tagInfo->trans.z;
    v36 = v32[41];
    v37 = v32[42];
    v38 = v32[43];
    v76.item = nullptr;
    v76.entity.spawnId.value = 0x1FFF;
    v77 = x;
    v78 = y;
    v79 = z;
    v73 = v36;
    renderWorld = clientGame->renderWorld;
    AllocRenderModel = renderWorld->AllocRenderModel;
    v74 = v37;
    v75 = v38;
    v41 = (idTreeAnimator *)AllocRenderModel(this: renderWorld, a2: modelName, a3: true, a4: -1);
    v42 = v41;
    if ( v41 != nullptr )
    {
      v43 = _RTDynamicCast(
              inptr: v41,
              VfDelta: 0,
              SrcType: &idRenderModel `RTTI Type Descriptor',
              TargetType: &idTreeAnimator `RTTI Type Descriptor',
              isReference: 0);
      if ( v43 != nullptr )
      {
        v44 = (idPresentableAnimatedEntity *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                               size: 0x4E0u,
                                               tag: TAG_PRESENTABLE,
                                               zeroBuffer: false,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
        if ( v44 != nullptr )
          v45 = idPresentableAnimatedEntity::idPresentableAnimatedEntity(
                  this: v44,
                  ent: nullptr,
                  renderModel_: v42,
                  animStack_: nullptr,
                  entityNumber_: 0x1FFF,
                  fxDecl_: nullptr,
                  useSphereModel_: false);
        else
          v45 = nullptr;
        v76.presentable = v45;
        v46 = v43[508];
        if ( v46 != 0 )
        {
          v47 = *(float *)(v46 + 708);
          if ( v47 > 0.0 )
          {
            v73 = *(float *)(v46 + 708);
            v74 = v47;
            v75 = v47;
          }
        }
      }
      else
      {
        v48 = (idPresentable *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x4B0u,
                                 tag: TAG_PRESENTABLE,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        if ( v48 != nullptr )
          v45 = (idPresentableAnimatedEntity *)idPresentable::idPresentable(
                                                 this: v48,
                                                 e: nullptr,
                                                 renderModel_: v42,
                                                 entityNumber_: 0x1FFF,
                                                 fxDecl_: nullptr);
        else
          v45 = nullptr;
        v76.presentable = v45;
      }
      v45->debugName = STATIC_ATTACHMENT_STRING;
      v49 = (int)result[1].list;
      v50 = *(idPresentable **)(v49 + 488);
      if ( v50 == nullptr )
      {
        idEntity::InitPresentableInternal(this: (idEntity *)result[1].list);
        v50 = *(idPresentable **)(v49 + 488);
      }
      idPresentable::SetParent(
        this: v76.presentable,
        p: v50,
        j: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v76.jointIndex.value);
      idClientGame::AddPresentable(
        this: clientGame,
        presentable: v76.presentable,
        index: -1,
        skipReplication: true,
        a5: v54,
        a6: v53,
        a7: v52,
        a8: v51,
        a9: v66,
        a10: v67,
        a11: v68,
        a12: v69,
        a13: v70,
        a14: v71);
      *((_BYTE *)&v76 + 104) = ((v43 != nullptr) << 7) | *((_BYTE *)&v76 + 104) & 0x7F;
      if ( (v43 != nullptr) << 7 == 0 )
      {
        v55 = _RTDynamicCast(
                inptr: v42,
                VfDelta: 0,
                SrcType: &idRenderModel `RTTI Type Descriptor',
                TargetType: &idRenderModelParticle `RTTI Type Descriptor',
                isReference: 0);
        if ( v55 != nullptr )
        {
          *((_BYTE *)&v76 + 104) |= 0x10u;
          v76.particleFx = *((const idDeclParticle **)v55 + 526);
        }
      }
      v76.originOffset.z = v79;
      v76.originOffset.x = v77;
      v76.originOffset.y = v78;
      v56 = v74;
      v57 = v75;
      v76.rotOffset = tagInfo->rot;
      model = v76.presentable->model;
      model->g.scale.x = v73;
      model->g.scale.y = v56;
      model->g.scale.z = v57;
      v76.presentable->origin = v76.originOffset;
      v59 = idQuat::ToMat3(this: &v81, result: (idMat3 *)&v76.rotOffset);
      presentable = v76.presentable;
      v76.presentable->axis.mat[0] = v59->mat[0];
      presentable->axis.mat[1] = v59->mat[1];
      presentable->axis.mat[2] = v59->mat[2];
      v76.presentable->model->g.suppressSurfaceInViewID = TreeAnimatorFromPresentable->g.suppressSurfaceInViewID;
      v76.presentable->model->g.suppressShadowInViewID = TreeAnimatorFromPresentable->g.suppressShadowInViewID;
      *((_BYTE *)&v76.presentable->model->g + 106) = *((_BYTE *)&v76.presentable->model->g + 106) & 0xFE
                                                   | *((_BYTE *)&TreeAnimatorFromPresentable->g + 106) & 1;
      v61 = (int)result[1].list;
      v62 = *(idPresentable **)(v61 + 488);
      if ( v62 == nullptr )
      {
        idEntity::InitPresentableInternal(this: (idEntity *)result[1].list);
        v62 = *(idPresentable **)(v61 + 488);
      }
      idPresentable::SetGroupMaster(this: v76.presentable, pres: v62);
      v76.presentable->fxManager.suppressSurfaceInViewID = TreeAnimatorFromPresentable->g.suppressSurfaceInViewID;
      v76.presentable->model->useDeferredPosition = false;
      v76.presentable->Present(this: v76.presentable);
      v76.savedRotOffset.x = v76.rotOffset.x;
      v76.savedRotOffset.y = v76.rotOffset.y;
      v76.savedRotOffset.z = v76.rotOffset.z;
      v63 = idAttachmentCollection::handleCounter;
      v76.savedRotOffset.w = v76.rotOffset.w;
      if ( ++idAttachmentCollection::handleCounter < 0 )
        idAttachmentCollection::handleCounter = 0;
      v76.handle.value = v63;
      idList<idAttachment,5>::Append(this: result, obj: &v76);
      this->attachments.list = (idAttachment *)v76.handle.value;
    }
    else
    {
      idLib::Warning(
        fmt: "idAttachmentCollection::AddAttachment - Failed to allocate rendermodel for model '%s'",
        modelName);
      this->attachments.list = (idAttachment *)-1;
    }
  }
  else
  {
    v25 = 0;
    while ( 1 )
    {
      v26 = &result->list[v25];
      if ( v26->jointIndex.value == v72 )
      {
        v27 = nullptr;
        if ( v26->presentable != nullptr )
        {
          v27 = v26->presentable;
        }
        else if ( idEntityPtr<idEntity const>::operator->(this: &v26->entity) != nullptr )
        {
          v28 = idEntityPtr<idEntity const>::operator->(this: &v26->entity);
          v27 = v28->presentable;
          v29 = v28;
          if ( v27 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v28);
            v27 = v29->presentable;
          }
        }
        if ( idStr::Icmp(s1: v27->model->name.str, s2: modelName) == 0 )
          break;
      }
      ++v24;
      ++v25;
      if ( v24 >= result->num )
        goto LABEL_29;
    }
    this->attachments.list = (idAttachment *)v26->handle.value;
  }
  return this;
}


// ========================================================================
// __unwind$493199
// EA  : 0x82C0B2D8
// RVA : 0x00C0B2D8
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void _unwind_493199()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// __unwind$493200
// EA  : 0x82C0B304
// RVA : 0x00C0B304
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

void _unwind_493200()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?AddAttachment@idAttachmentCollection@@QAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PBD0@Z
// EA  : 0x82C0B330
// RVA : 0x00C0B330
// PDB : w:\tech5\tungsten\game\entities\attachments.cpp
// ========================================================================

idAttachmentCollection *__fastcall idAttachmentCollection::AddAttachment(
        idAttachmentCollection *this,
        idList<idAttachment,5> *result,
        const char *modelName,
        const char *tag)
{
  idAttachmentCollection::AddAttachment(
    this,
    result,
    modelName,
    propName: nullptr,
    tag,
    tagInfo: nullptr,
    allowDuplicate: true);
  return this;
}

