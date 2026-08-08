
// ========================================================================
// ?Spawn@idFirstPersonEvent@@QAAXXZ
// EA  : 0x82C4B298
// RVA : 0x00C4B298
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonEvent::Spawn(idFirstPersonEvent *this)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  if ( this->cameraBlendOutTime == -1 )
    this->cameraBlendOutTime = this->blendOutTime;
  idEventReceiver::PostEventMS(this, ev: &EV_PostSpawn, time: 0);
}


// ========================================================================
// ?Event_PostSpawn@idFirstPersonEvent@@QAA?AVeventVoid@@XZ
// EA  : 0x82C4B448
// RVA : 0x00C4B448
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

idFirstPersonEvent *__fastcall idFirstPersonEvent::Event_PostSpawn(idFirstPersonEvent *this, eventVoid *result)
{
  idPlayer *Player; // r3
  idPlayer *v5; // r31
  idAnimatedEntity *thirdPersonLegs; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r26
  idAnimatedEntity *thirdPersonHands; // r3
  idTreeAnimator *v9; // r27
  int v10; // r28
  int v11; // r30
  int v12; // r31
  __int16 v14; // [sp+50h] [-50h] BYREF
  __int16 v15; // [sp+52h] [-4Eh] BYREF
  __int16 v16; // [sp+54h] [-4Ch] BYREF
  __int16 v17; // [sp+56h] [-4Ah] BYREF

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  v5 = Player;
  if ( Player != nullptr )
  {
    thirdPersonLegs = Player->thirdPersonLegs;
    if ( thirdPersonLegs != nullptr )
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonLegs);
    else
      TreeAnimatorFromPresentable = nullptr;
    thirdPersonHands = v5->thirdPersonHands;
    if ( thirdPersonHands != nullptr )
      v9 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonHands);
    else
      v9 = nullptr;
    v10 = 0;
    if ( *(int *)&result[884] > 0 )
    {
      v11 = 0;
      do
      {
        v12 = v11 + *(_DWORD *)&result[880];
        if ( *(_DWORD *)(v12 + 16) != 0 && TreeAnimatorFromPresentable != nullptr )
        {
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v14,
            result: TreeAnimatorFromPresentable->decl,
            aliasName: *(const char **)(v12 + 20));
          *(_WORD *)v12 = v14;
        }
        if ( *(_DWORD *)(v12 + 48) != 0 && v9 != nullptr )
        {
          idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v15, result: v9->decl, aliasName: *(const char **)(v12 + 52));
          *(_WORD *)(v12 + 2) = v15;
        }
        ++v10;
        v11 += 120;
      }
      while ( v10 < *(_DWORD *)&result[884] );
    }
    if ( *(_DWORD *)&result[896] != 0 && TreeAnimatorFromPresentable != nullptr )
    {
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v16,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: *(const char **)&result[900]);
      *(_WORD *)&result[1348] = v16;
    }
    if ( *(_DWORD *)&result[928] != 0 && v9 != nullptr )
    {
      idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v17, result: v9->decl, aliasName: *(const char **)&result[932]);
      *(_WORD *)&result[1350] = v17;
    }
  }
  return this;
}


// ========================================================================
// ??0idUseFirstPersonEvent@@QAA@XZ
// EA  : 0x82C4B5A0
// RVA : 0x00C4B5A0
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

idUseFirstPersonEvent *__fastcall idUseFirstPersonEvent::idUseFirstPersonEvent(idUseFirstPersonEvent *this)
{
  idUse::idUse(this);
  this->additionalPickup = false;
  this->__vftable = (idUseFirstPersonEvent_vtbl *)&idUseFirstPersonEvent::`vftable';
  this->additionalPickupState = 0;
  return this;
}


// ========================================================================
// ?Use@idUseFirstPersonEvent@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C4B5E8
// RVA : 0x00C4B5E8
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

int __fastcall idUseFirstPersonEvent::Use(idUseFirstPersonEvent *this, idEntity *user, const usableState_t usable)
{
  idEventReceiver v5[2]; // [sp+50h] [-30h] BYREF

  if ( (*(_BYTE *)&this->flags & 8) == 0 || usable != USABLE_PROP )
    return 0;
  idEntity::Use(this, activator: user, usable: USABLE_PROP);
  this->ActivateTargets(this, a2: this);
  idEventReceiver::ProcessEvent(this: v5, result: (idEventArg *)this, ev: &EV_NotifyProgressionOwner);
  return 1;
}


// ========================================================================
// ?StartEndEvent@idFirstPersonEvent@@IAAXXZ
// EA  : 0x82C4B678
// RVA : 0x00C4B678
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonEvent::StartEndEvent(idFirstPersonEvent *this)
{
  int value; // r9
  idGameLocal *v3; // r11
  idPlayer *v4; // r3
  idPlayer *v5; // r30
  double z; // fp5
  double v7; // fp1
  double v8; // fp13
  idPlayer_vtbl *v9; // r29
  idAngles *v10; // r3
  idPresentable *presentable; // r3
  int v12; // r3
  idPresentable *v13; // r3
  int v14; // r3
  idPresentable *v15; // r3
  int v16; // r3
  idSpringCamera *springCamera; // r3
  int v18; // r9
  idAlignedEntity *v19; // r3
  idAlignedEntity *v20; // r3
  idAlignedEntity *v21; // r30
  int v22; // r9
  idAlignedEntity *v23; // r3
  idAlignedEntity *v24; // r3
  float v25[4]; // [sp+50h] [-50h] BYREF
  idMat3 v26; // [sp+60h] [-40h] BYREF

  this->eventEndTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  value = this->playerActivator.spawnId.value;
  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr )
    {
      v5 = idPlayer::CastTo(c: v4);
      if ( v5 != nullptr )
      {
        z = this->playerEndPos.z;
        v7 = (float)((float)(this->playerEndRot.mat[2].z * this->playerEndOffset.z)
                   + (float)((float)(this->playerEndRot.mat[0].z * this->playerEndOffset.x)
                           + (float)(this->playerEndRot.mat[1].z * this->playerEndOffset.y)));
        v8 = (float)(this->playerEndPos.y
                   + (float)((float)(this->playerEndRot.mat[2].y * this->playerEndOffset.z)
                           + (float)((float)(this->playerEndRot.mat[0].y * this->playerEndOffset.x)
                                   + (float)(this->playerEndRot.mat[1].y * this->playerEndOffset.y))));
        v25[0] = (float)((float)(this->playerEndOffset.x * this->playerEndRot.mat[0].x)
                       + (float)((float)(this->playerEndRot.mat[1].x * this->playerEndOffset.y)
                               + (float)(this->playerEndRot.mat[2].x * this->playerEndOffset.z)))
               + this->playerEndPos.x;
        v25[1] = v8;
        v25[2] = (float)z + (float)v7;
        v9 = v5->__vftable;
        v10 = idMat3::ToAngles(this: &v26, result: (idAngles *)&this->playerEndRot);
        v9->Teleport(this: v5, a2: (const idVec3 *)v25, a3: v10);
        presentable = v5->presentable;
        v12 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
        idPhysics_Player::SetCrouch(
          this: (idPhysics_Player *)(v12 + 36264),
          crouch: (*((_BYTE *)this + 1092) & 0x10) != 0);
        v13 = v5->presentable;
        v14 = v13 != nullptr ? (int)v13->GetPlayerInterface_2(this: v13) : 0;
        idPhysics_Player::ForcePhysicsQuery(this: (idPhysics_Player *)(v14 + 36264));
        v15 = v5->presentable;
        v16 = v15 != nullptr ? (int)v15->GetPlayerInterface_2(this: v15) : 0;
        *(_BYTE *)(v16 + 45881) = *(_BYTE *)(v16 + 45880) != ((*((_BYTE *)this + 1092) & 0x10) != 0);
        springCamera = v5->springCamera;
        if ( springCamera != nullptr )
          idSpringCamera::SetBlendDurationMS(this: springCamera, blendDurationMS: this->cameraBlendOutTime);
      }
      v3 = gameLocal;
    }
  }
  v18 = this->legsEntity.spawnId.value;
  if ( v3->spawnIds.ptr[v18 & 0x1FFF] == v18 >> 13
    && (v19 = (idAlignedEntity *)v3->entities.ptr[v18 & 0x1FFF]) != nullptr )
  {
    v20 = idAlignedEntity::CastTo(c: v19);
    v3 = gameLocal;
    v21 = v20;
  }
  else
  {
    v21 = nullptr;
  }
  v22 = this->handsEntity.spawnId.value;
  if ( v3->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
    && (v23 = (idAlignedEntity *)v3->entities.ptr[v22 & 0x1FFF]) != nullptr )
  {
    v24 = idAlignedEntity::CastTo(c: v23);
  }
  else
  {
    v24 = nullptr;
  }
  if ( v21 != nullptr && this->attachMode == ATTACHMODE_LEGS )
  {
    v24 = v21;
LABEL_29:
    idAlignedEntity::DetachCamera(this: v24, instantBlend: (_cntlzw(this->cameraBlendOutTime) & 0x20) != 0);
    return;
  }
  if ( v24 != nullptr && this->attachMode == ATTACHMODE_HANDS )
    goto LABEL_29;
}


// ========================================================================
// ?GetAnimTotalMovement@idFirstPersonEvent@@ABAXPBVidTreeAnimator@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@AAVidVec3@@AAVidMat3@@23@Z
// EA  : 0x82C4B928
// RVA : 0x00C4B928
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonEvent::GetAnimTotalMovement(
        idFirstPersonEvent *this,
        const idTreeAnimator *ta,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *animHandle,
        idVec3 *startOrigin,
        idQuat *startAxis,
        idVec3 *origin,
        idMat3 *axis,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> a16)
{
  const idMD6Alias *Alias; // r3
  idResource *Existing; // r3
  idResource *v23; // r31
  int trackedMemory; // r10
  idVec3 *v25; // r11
  idVec3 *v26; // r9
  idQuat *v27; // r31
  double v28; // fp8
  idQuat *v29; // r4
  double v30; // fp6
  idQuat *v31; // r3
  double z; // fp12
  double x; // fp13
  double y; // fp11
  double v35; // fp10
  double v36; // fp4
  double v37; // fp3
  double v38; // fp2
  double v39; // fp1
  double v40; // fp1
  double v41; // fp0
  idQuat *v42; // r3
  double v43; // fp10
  double v44; // fp4
  double v45; // fp5
  double v46; // fp2
  double v47; // fp9
  idQuat v48; // [sp+50h] [-B0h] BYREF
  idQuat v49; // [sp+60h] [-A0h] BYREF
  idMat3 v50; // [sp+70h] [-90h] BYREF
  float v51; // [sp+94h] [-6Ch]
  float v52; // [sp+98h] [-68h]
  float v53; // [sp+9Ch] [-64h]
  idQuat v54[6]; // [sp+A0h] [-60h] BYREF

  a16.value = (unsigned __int16)animHandle;
  if ( ta != nullptr && (unsigned __int16)animHandle != 0xFFFF )
  {
    Alias = idDeclMD6::FindAlias(this: ta->decl, aliasHandle: &a16, includeInherited: true);
    if ( Alias != nullptr )
    {
      Existing = idResourceList::FindExisting(
                   this: &idMD6Anim::resourceList,
                   name: (char *)Alias->animRefs.list->str,
                   skipStaleCheck: false);
      v23 = Existing;
      if ( Existing != nullptr )
      {
        if ( (*((_BYTE *)this + 1092) & 0x80) != 0 )
        {
          startOrigin->x = *(float *)&Existing[2].resourceError;
          startOrigin->y = *(float *)&Existing[2].networkID;
          startOrigin->z = *(float *)&Existing[2].staleCount;
          *(idMat3 *)&startAxis->x = *idAngles::ToMat3(
                                        this: (idAngles *)v54,
                                        result: (idMat3 *)((char *)&Existing[2] + 32));
        }
        trackedMemory = v23[1].trackedMemory;
        v25 = &vec3_origin;
        v26 = &vec3_origin;
        if ( trackedMemory != 0 )
        {
          v26 = (idVec3 *)(trackedMemory + 64);
          v25 = (idVec3 *)(trackedMemory + 112);
        }
        v27 = &quat_identity;
        v28 = (float)(v25->y - v26->y);
        v29 = &quat_identity;
        v30 = (float)(v25->z - v26->z);
        v48.x = v25->x - v26->x;
        v48.y = v28;
        v48.z = v30;
        if ( trackedMemory != 0 )
        {
          v29 = (idQuat *)(trackedMemory + 32);
          v27 = (idQuat *)(trackedMemory + 80);
        }
        v31 = idQuat::Inverse(this: (idQuat *)&v50.mat[1].y, result: v29);
        z = v27->z;
        x = v27->x;
        y = v27->y;
        v35 = v31->x;
        v36 = v31->z;
        v37 = (float)((float)(v27->w * v31->z) + (float)((float)(v31->y * v27->x) + (float)(v27->z * v31->w)));
        v38 = (float)((float)(v31->w * v27->y) + (float)((float)(v27->z * v31->x) + (float)(v31->y * v27->w)));
        v39 = (float)-(float)((float)(v31->y * v27->y) - (float)((float)(v31->w * v27->w) - (float)(v27->x * v31->x)));
        v50.mat[1].y = -(float)((float)(v27->z * v31->y)
                              - (float)((float)(v27->y * v31->z)
                                      + (float)((float)(v27->x * v31->w) + (float)(v31->x * v27->w))));
        v50.mat[2].x = -(float)((float)((float)v35 * (float)y) - (float)v37);
        v50.mat[1].z = -(float)((float)((float)x * (float)v36) - (float)v38);
        v50.mat[2].y = -(float)((float)((float)z * (float)v36) - (float)v39);
        idMat3::ToQuat(this: &v50, result: startAxis);
        idQuat::operator*(this: &v49, result: v50.mat, a: (const idVec3 *)&v48);
        v40 = (float)(startOrigin->y + v49.y);
        v41 = (float)(startOrigin->z + v49.z);
        origin->x = startOrigin->x + v49.x;
        origin->y = v40;
        origin->z = v41;
        v42 = idQuat::Inverse(this: &v48, result: (idQuat *)&v50.mat[1].y);
        v43 = v42->x;
        v44 = v42->z;
        v45 = (float)-(float)((float)(v42->y * v50.mat[0].y)
                            - (float)((float)(v42->w * v50.mat[1].x) - (float)(v42->x * v50.mat[0].x)));
        v46 = (float)((float)(v42->w * v50.mat[0].y)
                    + (float)((float)(v42->z * v50.mat[0].x) + (float)(v42->y * v50.mat[1].x)));
        v47 = (float)-(float)((float)(v42->y * v50.mat[0].x)
                            - (float)((float)(v42->w * v50.mat[0].z)
                                    + (float)((float)(v42->z * v50.mat[1].x) + (float)(v42->x * v50.mat[0].y))));
        v50.mat[2].z = -(float)((float)(v42->z * v50.mat[0].y)
                              - (float)((float)(v42->x * v50.mat[1].x)
                                      + (float)((float)(v42->w * v50.mat[0].x) + (float)(v42->y * v50.mat[0].z))));
        v53 = -(float)((float)((float)v44 * v50.mat[0].z) - (float)v45);
        v52 = v47;
        v51 = -(float)((float)((float)v43 * v50.mat[0].z) - (float)v46);
        *axis = *idQuat::ToMat3(this: v54, result: (idMat3 *)&v50.mat[2].z);
      }
    }
  }
}


// ========================================================================
// ?Event_PostSpawn@idFirstPersonPickup@@QAA?AVeventVoid@@XZ
// EA  : 0x82C4BC28
// RVA : 0x00C4BC28
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

idFirstPersonPickup *__fastcall idFirstPersonPickup::Event_PostSpawn(idFirstPersonPickup *this, eventVoid *result)
{
  idPlayer *Player; // r3
  int v5; // r10
  char v6; // r19
  idAlignedEntity *thirdPersonLegs; // r9
  idAnimatedEntity *thirdPersonHands; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v10; // r22
  const idDeclMD6 *decl; // r24
  int v12; // r12
  idEntity *v13; // r29
  __int16 v14; // r10
  const idMD6Alias *Alias; // r3
  const idMD6Anim *Existing; // r5
  idPhysics *Physics; // r3
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // r8
  const idMat3 *v19; // r3
  idVec3 *v20; // r3
  double z; // fp2
  double v22; // fp31
  double v23; // fp30
  double v24; // fp29
  idPhysics *v25; // r3
  float *v26; // r3
  double v27; // fp13
  double v28; // fp12
  idEntity *v29; // r3
  int v30; // r10
  idEntity *v31; // r29
  _WORD *v32; // r11
  const idMD6Alias *v33; // r3
  const idMD6Anim *v34; // r3
  idPhysics *v35; // r3
  const idMat3 *(__fastcall *v36)(idPhysics *, int); // r7
  const idMat3 *v37; // r3
  idVec3 *v38; // r3
  double v39; // fp0
  double v40; // fp10
  double v41; // fp31
  double v42; // fp30
  double v43; // fp29
  idPhysics *v44; // r3
  float *v45; // r3
  double v46; // fp0
  double v47; // fp13
  int v48; // r23
  int v49; // r25
  int v50; // r29
  int v51; // r9
  idEntity *v52; // r3
  idEntity *v53; // r28
  _WORD *v54; // r11
  const idMD6Alias *v55; // r3
  const idMD6Anim *v56; // r5
  idPhysics *v57; // r3
  const idMat3 *(__fastcall *v58)(idPhysics *, int); // r8
  const idMat3 *v59; // r3
  idVec3 *v60; // r3
  double v61; // fp3
  double v62; // fp31
  double v63; // fp30
  double v64; // fp29
  idPhysics *v65; // r3
  float *v66; // r3
  double v67; // fp0
  double v68; // fp13
  _DWORD back_chain[20]; // [sp+0h] [-180h]
  idJointMat v71[3]; // [sp+50h] [-130h] BYREF
  float v72; // [sp+80h] [-100h]
  float v73[12]; // [sp+90h] [-F0h] BYREF
  idMat3 v74; // [sp+C0h] [-C0h] BYREF

  idFirstPersonEvent::Event_PostSpawn(this: (idFirstPersonEvent *)v71, result);
  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  if ( Player != nullptr )
  {
    v5 = *(_DWORD *)&result[1076];
    v6 = 1;
    thirdPersonLegs = Player->thirdPersonLegs;
    thirdPersonHands = Player->thirdPersonHands;
    if ( v5 != 0 || thirdPersonLegs == nullptr )
    {
      if ( v5 != 1 || thirdPersonHands == nullptr )
        return this;
    }
    else
    {
      thirdPersonHands = thirdPersonLegs;
      v6 = 0;
    }
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonHands);
    v10 = TreeAnimatorFromPresentable;
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      decl = TreeAnimatorFromPresentable->decl;
      idTreeAnimator::GetJointIndex(
        this: (idTreeAnimator *)((char *)v71[0].mat + 2),
        result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable,
        jointName: *(const char **)&result[1448]);
      if ( decl != nullptr && SLOWORD(v71[0].mat[0]) >= 0 )
      {
        idTreeAnimator::NumJoints(this: v10);
        ((void (*)(void))RtlCheckStack12)();
        *(_DWORD *)((char *)back_chain + v12) = back_chain[0];
        v13 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&result[1400]);
        if ( v13 != nullptr )
        {
          v14 = v6 != 0 ? *(_WORD *)&result[1350] : *(_WORD *)&result[1348];
          HIWORD(v71[0].mat[0]) = v14;
          LOWORD(v71[0].mat[1]) = v14;
          Alias = idDeclMD6::FindAlias(
                    this: v10->decl,
                    aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&v71[0].mat[1] + 1,
                    includeInherited: true);
          if ( Alias != nullptr )
          {
            Existing = (const idMD6Anim *)idResourceList::FindExisting(
                                            this: &idMD6Anim::resourceList,
                                            name: (char *)Alias->animRefs.list->str,
                                            skipStaleCheck: false);
            if ( Existing != nullptr )
            {
              idMD6Model::GetJointsForAnimFrame(
                this: decl->model,
                joints: v71,
                anim: Existing,
                frame: 0,
                offset: &vec3_origin,
                removeOriginOffset: false);
              memcpy(Dst: v73, Src: &v71[SLOWORD(v71[0].mat[0])], Size: sizeof(v73));
              Physics = idEntity::GetPhysics(this: v13);
              GetAxis = Physics->GetAxis;
              v71[0].mat[4] = v73[0];
              v71[0].mat[5] = v73[1];
              v71[0].mat[6] = v73[2];
              v71[0].mat[7] = v73[4];
              v71[0].mat[8] = v73[5];
              v71[0].mat[9] = v73[6];
              v71[0].mat[10] = v73[8];
              v71[0].mat[11] = v73[9];
              v72 = v73[10];
              v19 = GetAxis(this: Physics, a2: 0);
              v20 = (idVec3 *)idMat3::operator*(this: &v74, result: (idMat3 *)&v71[0].mat[4], a: v19);
              *(float *)&result[1500] = v20->x;
              *(float *)&result[1504] = v20->y;
              *(float *)&result[1508] = v20->z;
              *(idVec3 *)&result[1512] = v20[1];
              *(float *)&result[1524] = v20[2].x;
              *(float *)&result[1528] = v20[2].y;
              z = v20[2].z;
              *(float *)&result[1532] = v20[2].z;
              v22 = (float)((float)(v73[11] * *(float *)&result[1524])
                          + (float)((float)(v73[3] * *(float *)&result[1500]) + (float)(v73[7] * *(float *)&result[1512])));
              v23 = (float)((float)(v73[3] * *(float *)&result[1504])
                          + (float)((float)(*(float *)&result[1516] * v73[7])
                                  + (float)(*(float *)&result[1528] * v73[11])));
              v24 = (float)((float)(v73[3] * *(float *)&result[1508])
                          + (float)((float)(*(float *)&result[1520] * v73[7]) + (float)((float)z * v73[11])));
              v25 = idEntity::GetPhysics(this: v13);
              v26 = (float *)v25->GetOrigin(this: v25, a2: 0);
              v27 = (float)(v26[1] - (float)v23);
              v28 = (float)(v26[2] - (float)v24);
              *(float *)&result[1488] = *v26 - (float)v22;
              *(float *)&result[1492] = v27;
              *(float *)&result[1496] = v28;
            }
          }
        }
        v29 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&result[1404]);
        v30 = *(_DWORD *)&result[1476];
        v31 = v29;
        if ( v30 != -1 && v29 != nullptr )
        {
          v32 = (_WORD *)(120 * v30 + *(_DWORD *)&result[880]);
          if ( v6 != 0 )
            ++v32;
          HIWORD(v71[0].mat[1]) = *v32;
          v33 = idDeclMD6::FindAlias(
                  this: v10->decl,
                  aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&v71[0].mat[1],
                  includeInherited: true);
          if ( v33 != nullptr )
          {
            v34 = (const idMD6Anim *)idResourceList::FindExisting(
                                       this: &idMD6Anim::resourceList,
                                       name: (char *)v33->animRefs.list->str,
                                       skipStaleCheck: false);
            if ( v34 != nullptr )
            {
              idMD6Model::GetJointsForAnimFrame(
                this: decl->model,
                joints: v71,
                anim: v34,
                frame: v34->animData->numFrames - 1,
                offset: &vec3_origin,
                removeOriginOffset: false);
              memcpy(Dst: v73, Src: &v71[SLOWORD(v71[0].mat[0])], Size: sizeof(v73));
              v35 = idEntity::GetPhysics(this: v31);
              v36 = v35->GetAxis;
              v71[0].mat[4] = v73[0];
              v71[0].mat[5] = v73[1];
              v71[0].mat[6] = v73[2];
              v71[0].mat[7] = v73[4];
              v71[0].mat[8] = v73[5];
              v71[0].mat[9] = v73[6];
              v71[0].mat[10] = v73[8];
              v71[0].mat[11] = v73[9];
              v72 = v73[10];
              v37 = v36(this: v35, a2: 0);
              v38 = (idVec3 *)idMat3::operator*(this: &v74, result: (idMat3 *)&v71[0].mat[4], a: v37);
              *(float *)&result[1548] = v38->x;
              v39 = v73[7];
              *(float *)&result[1552] = v38->y;
              *(float *)&result[1556] = v38->z;
              *(idVec3 *)&result[1560] = v38[1];
              *(float *)&result[1572] = v38[2].x;
              *(float *)&result[1576] = v38[2].y;
              v40 = v38[2].z;
              *(float *)&result[1580] = v38[2].z;
              v41 = (float)((float)(v73[11] * *(float *)&result[1572])
                          + (float)((float)(*(float *)&result[1548] * v73[3])
                                  + (float)((float)v39 * *(float *)&result[1560])));
              v42 = (float)((float)(v73[3] * *(float *)&result[1552])
                          + (float)((float)(*(float *)&result[1564] * (float)v39)
                                  + (float)(*(float *)&result[1576] * v73[11])));
              v43 = (float)((float)(v73[3] * *(float *)&result[1556])
                          + (float)((float)(*(float *)&result[1568] * (float)v39) + (float)((float)v40 * v73[11])));
              v44 = idEntity::GetPhysics(this: v31);
              v45 = (float *)v44->GetOrigin(this: v44, a2: 0);
              v46 = (float)(v45[1] - (float)v42);
              v47 = (float)(v45[2] - (float)v43);
              *(float *)&result[1536] = *v45 - (float)v41;
              *(float *)&result[1540] = v46;
              *(float *)&result[1544] = v47;
            }
          }
        }
        v48 = 0;
        if ( *(int *)&result[1388] > 0 )
        {
          v49 = 0;
          do
          {
            v50 = v49 + *(_DWORD *)&result[1384];
            v51 = *(_DWORD *)(v50 + 32);
            if ( gameLocal->spawnIds.ptr[v51 & 0x1FFF] == v51 >> 13
              && (v52 = gameLocal->entities.ptr[v51 & 0x1FFF]) != nullptr )
            {
              v53 = idEntity::CastTo(c: v52);
            }
            else
            {
              v53 = nullptr;
            }
            v54 = (_WORD *)(120 * *(_DWORD *)(v50 + 36) + *(_DWORD *)&result[880]);
            if ( v53 != nullptr )
            {
              if ( v6 != 0 )
                ++v54;
              HIWORD(v71[0].mat[2]) = *v54;
              v55 = idDeclMD6::FindAlias(
                      this: v10->decl,
                      aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&v71[0].mat[2],
                      includeInherited: true);
              if ( v55 != nullptr )
              {
                v56 = (const idMD6Anim *)idResourceList::FindExisting(
                                           this: &idMD6Anim::resourceList,
                                           name: (char *)v55->animRefs.list->str,
                                           skipStaleCheck: false);
                if ( v56 != nullptr )
                {
                  idMD6Model::GetJointsForAnimFrame(
                    this: decl->model,
                    joints: v71,
                    anim: v56,
                    frame: 0,
                    offset: &vec3_origin,
                    removeOriginOffset: false);
                  memcpy(Dst: v73, Src: &v71[SLOWORD(v71[0].mat[0])], Size: sizeof(v73));
                  v57 = idEntity::GetPhysics(this: v53);
                  v58 = v57->GetAxis;
                  v71[0].mat[4] = v73[0];
                  v71[0].mat[5] = v73[1];
                  v71[0].mat[6] = v73[2];
                  v71[0].mat[7] = v73[4];
                  v71[0].mat[8] = v73[5];
                  v71[0].mat[9] = v73[6];
                  v71[0].mat[10] = v73[8];
                  v71[0].mat[11] = v73[9];
                  v72 = v73[10];
                  v59 = v58(this: v57, a2: 0);
                  v60 = (idVec3 *)idMat3::operator*(this: &v74, result: (idMat3 *)&v71[0].mat[4], a: v59);
                  *(float *)(v50 + 56) = v60->x;
                  *(float *)(v50 + 60) = v60->y;
                  *(float *)(v50 + 64) = v60->z;
                  *(idVec3 *)(v50 + 68) = v60[1];
                  *(float *)(v50 + 80) = v60[2].x;
                  *(float *)(v50 + 84) = v60[2].y;
                  v61 = v60[2].z;
                  *(float *)(v50 + 88) = v60[2].z;
                  v62 = (float)((float)(v73[11] * *(float *)(v50 + 80))
                              + (float)((float)(v73[3] * *(float *)(v50 + 56)) + (float)(v73[7] * *(float *)(v50 + 68))));
                  v63 = (float)((float)(*(float *)(v50 + 60) * v73[3])
                              + (float)((float)(*(float *)(v50 + 72) * v73[7]) + (float)(*(float *)(v50 + 84) * v73[11])));
                  v64 = (float)((float)(v73[3] * *(float *)(v50 + 64))
                              + (float)((float)(*(float *)(v50 + 76) * v73[7]) + (float)((float)v61 * v73[11])));
                  v65 = idEntity::GetPhysics(this: v53);
                  v66 = (float *)v65->GetOrigin(this: v65, a2: 0);
                  v67 = (float)(v66[1] - (float)v63);
                  v68 = (float)(v66[2] - (float)v64);
                  *(float *)(v50 + 44) = *v66 - (float)v62;
                  *(float *)(v50 + 48) = v67;
                  *(float *)(v50 + 52) = v68;
                }
              }
            }
            ++v48;
            v49 += 92;
          }
          while ( v48 < *(_DWORD *)&result[1388] );
        }
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_AttachEntity@idFirstPersonEvent@@QAA?AVeventVoid@@PAVidEntity@@PBD@Z
// EA  : 0x82C4C518
// RVA : 0x00C4C518
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

idFirstPersonEvent *__fastcall idFirstPersonEvent::Event_AttachEntity(
        idFirstPersonEvent *this,
        eventVoid *result,
        idEntity *entity,
        const char *tag)
{
  int v8; // r10
  idAlignedEntity *v9; // r3
  idAlignedEntity *v10; // r3

  if ( entity != nullptr )
  {
    v8 = *(_DWORD *)&result[1100];
    if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13
      && (v9 = (idAlignedEntity *)gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr
      && (v10 = idAlignedEntity::CastTo(c: v9)) != nullptr )
    {
      idAlignedEntity::AttachEntity(this: v10, entity, tag);
      return this;
    }
    else
    {
      idLib::Warning(fmt: "Event_AttachEntity: Hands not valid");
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "Event_AttachEntity: Tried to attach NULL to tag '%s'", tag);
    return this;
  }
}


// ========================================================================
// ?EndEvent@idFirstPersonEvent@@IAAXXZ
// EA  : 0x82C4C5D0
// RVA : 0x00C4C5D0
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonEvent::EndEvent(idFirstPersonEvent *this)
{
  idGameLocal *v2; // r11
  idPlayer *v3; // r3
  idPlayer *v4; // r3
  idPresentable *presentable; // r3
  int v6; // r3
  int value; // r9
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  idPresentable *v10; // r3
  idPresentablePlayer *v11; // r3
  int v12; // r9
  idPlayer *v13; // r3
  idPlayer *v14; // r3
  idSpringCamera *springCamera; // r10
  idAlignedEntity *v16; // r3
  idAlignedEntity *v17; // r3
  int v18; // r9
  idAlignedEntity *v19; // r3
  idAlignedEntity *v20; // r31
  idPresentable *v21; // r11
  int v22; // r9
  idAlignedEntity *v23; // r3
  idAlignedEntity *v24; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idAlignedEntity *v26; // r3
  idAlignedEntity *v27; // r3
  int v28; // r9
  idAlignedEntity *v29; // r3
  idAlignedEntity *v30; // r31
  idPresentable *v31; // r11
  int v32; // r9
  idAlignedEntity *v33; // r3
  idAlignedEntity *v34; // r3
  idTreeAnimator *v35; // r3
  int v36; // r29
  int v37; // r30
  int v38; // r9
  idEntity *v39; // r3
  idEntity *v40; // r31
  int v41; // r9
  idPlayer *v42; // r3
  idPlayer *v43; // r4

  idEntity::BecomeInactive(this, flags: 1);
  this->eventStartTime = -1;
  this->eventEndTime = -1;
  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->playerActivator.spawnId.value & 0x1FFF] == this->playerActivator.spawnId.value >> 13 )
  {
    v3 = (idPlayer *)gameLocal->entities.ptr[this->playerActivator.spawnId.value & 0x1FFF];
    v4 = v3 != nullptr ? idPlayer::CastTo(c: v3) : nullptr;
    presentable = v4->presentable;
    v6 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
    idHands::Show(this: (idHands *)(v6 + 37616), hideReason: this->playerShowFlags);
    value = this->playerActivator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idPlayer::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    v10 = v9->presentable;
    v11 = v10 != nullptr ? v10->GetPlayerInterface_2(this: v10) : nullptr;
    idPresentablePlayer::SetInhibitFlags(this: v11, flags: this->playerSavedInhibitFlags);
    v12 = this->playerActivator.spawnId.value;
    v2 = gameLocal;
    if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
      && (v13 = (idPlayer *)gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr )
    {
      v14 = idPlayer::CastTo(c: v13);
      v2 = gameLocal;
    }
    else
    {
      v14 = nullptr;
    }
    springCamera = v14->springCamera;
    if ( springCamera != nullptr )
    {
      springCamera->calculateViewInDraw = false;
      v2 = gameLocal;
    }
  }
  if ( v2->spawnIds.ptr[this->legsEntity.spawnId.value & 0x1FFF] == this->legsEntity.spawnId.value >> 13 )
  {
    v16 = (idAlignedEntity *)v2->entities.ptr[this->legsEntity.spawnId.value & 0x1FFF];
    if ( v16 != nullptr )
      v17 = idAlignedEntity::CastTo(c: v16);
    else
      v17 = nullptr;
    idEntity::Unbind(this: v17);
    v18 = this->legsEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v18 & 0x1FFF] == v18 >> 13
      && (v19 = (idAlignedEntity *)gameLocal->entities.ptr[v18 & 0x1FFF]) != nullptr )
    {
      v20 = idAlignedEntity::CastTo(c: v19);
    }
    else
    {
      v20 = nullptr;
    }
    v21 = v20->presentable;
    if ( v21 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v20);
      v21 = v20->presentable;
    }
    v21->model->useDeferredPosition = true;
    v22 = this->legsEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
      && (v23 = (idAlignedEntity *)gameLocal->entities.ptr[v22 & 0x1FFF]) != nullptr )
    {
      v24 = idAlignedEntity::CastTo(c: v23);
    }
    else
    {
      v24 = nullptr;
    }
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v24);
    if ( TreeAnimatorFromPresentable != nullptr )
      idTreeAnimator::SetRemoveOriginRotation(
        this: TreeAnimatorFromPresentable,
        removeRotation: this->removeOriginTransformLegs);
    v2 = gameLocal;
  }
  if ( v2->spawnIds.ptr[this->handsEntity.spawnId.value & 0x1FFF] == this->handsEntity.spawnId.value >> 13 )
  {
    v26 = (idAlignedEntity *)v2->entities.ptr[this->handsEntity.spawnId.value & 0x1FFF];
    if ( v26 != nullptr )
      v27 = idAlignedEntity::CastTo(c: v26);
    else
      v27 = nullptr;
    idEntity::Unbind(this: v27);
    v28 = this->handsEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v28 & 0x1FFF] == v28 >> 13
      && (v29 = (idAlignedEntity *)gameLocal->entities.ptr[v28 & 0x1FFF]) != nullptr )
    {
      v30 = idAlignedEntity::CastTo(c: v29);
    }
    else
    {
      v30 = nullptr;
    }
    v31 = v30->presentable;
    if ( v31 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v30);
      v31 = v30->presentable;
    }
    v31->model->useDeferredPosition = true;
    v32 = this->handsEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v32 & 0x1FFF] == v32 >> 13
      && (v33 = (idAlignedEntity *)gameLocal->entities.ptr[v32 & 0x1FFF]) != nullptr )
    {
      v34 = idAlignedEntity::CastTo(c: v33);
    }
    else
    {
      v34 = nullptr;
    }
    v35 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v34);
    if ( v35 != nullptr )
      idTreeAnimator::SetRemoveOriginRotation(this: v35, removeRotation: this->removeOriginTransformHands);
    v2 = gameLocal;
  }
  v36 = 0;
  if ( this->triggerLeave.num > 0 )
  {
    v37 = 0;
    do
    {
      v38 = this->triggerLeave.list[v37].spawnId.value;
      if ( v2->spawnIds.ptr[v38 & 0x1FFF] == v38 >> 13 )
      {
        v39 = v2->entities.ptr[v38 & 0x1FFF];
        if ( v39 != nullptr )
        {
          v40 = idEntity::CastTo(c: v39);
          if ( v40 != nullptr )
          {
            v41 = this->playerActivator.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v41 & 0x1FFF] == v41 >> 13
              && (v42 = (idPlayer *)gameLocal->entities.ptr[v41 & 0x1FFF]) != nullptr )
            {
              v43 = idPlayer::CastTo(c: v42);
            }
            else
            {
              v43 = nullptr;
            }
            idEntity::Activate(this: v40, activator: v43);
          }
          v2 = gameLocal;
        }
      }
      ++v36;
      ++v37;
    }
    while ( v36 < this->triggerLeave.num );
  }
}


// ========================================================================
// ?SetCurrentState@idFirstPersonEvent@@IAAXH@Z
// EA  : 0x82C4CA60
// RVA : 0x00C4CA60
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonEvent::SetCurrentState(idFirstPersonEvent *this, int nextState)
{
  int v3; // r29
  int curExtraAnimation; // r10
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r30
  int v8; // r9
  idPlayer *v9; // r3
  idPlayer *v10; // r4
  int num; // r11
  idFirstPersonEvent::animEntry_t *v12; // r27
  idEntity *v13; // r30
  idPlayer *v14; // r3
  int *v15; // r9
  int v16; // ctr
  float *p_z; // r10
  idAlignedEntity *Entity; // r3
  const idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int v20; // r10
  double timeScale; // fp31
  unsigned int v22; // r30
  idAlignedEntity *v23; // r3
  idAlignedEntity *v24; // r3
  idEntityPtr<idAlignedEntity> *p_legsEntity; // r3
  bool v26; // zf
  idAlignedEntity *v27; // r3
  idPhysics *v28; // r3
  idAlignedEntity *v29; // r3
  idPhysics *v30; // r3
  idAlignedEntity *v31; // r3
  idPhysics *Physics; // r3
  idAlignedEntity *v33; // r3
  idPhysics *v34; // r3
  int *v35; // r9
  float *v36; // r10
  int v37; // ctr
  idAlignedEntity *v38; // r3
  const idTreeAnimator *v39; // r3
  int v40; // r10
  double v41; // fp31
  unsigned int v42; // r30
  idAlignedEntity *v43; // r3
  idAlignedEntity *v44; // r3
  idEntityPtr<idAlignedEntity> *p_handsEntity; // r3
  idAlignedEntity *v46; // r3
  idPhysics *v47; // r3
  idAlignedEntity *v48; // r3
  idPhysics *v49; // r3
  idAlignedEntity *v50; // r3
  idPhysics *v51; // r3
  idAlignedEntity *v52; // r3
  idPhysics *v53; // r3
  idFirstPersonEvent::attachMode_t attachMode; // r11
  int v55; // [sp+8h] [-E8h]
  int v56; // [sp+Ch] [-E4h]
  int v57; // [sp+10h] [-E0h]
  int v58; // [sp+14h] [-DCh]
  int v59; // [sp+18h] [-D8h]
  int v60; // [sp+1Ch] [-D4h]
  int v61; // [sp+20h] [-D0h]
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v62; // [sp+24h] [-CCh]
  blendParms_t v63; // [sp+50h] [-A0h] BYREF
  int v64; // [sp+6Ch] [-84h] BYREF
  idMat3 v65; // [sp+70h] [-80h] BYREF

  v3 = nextState;
  if ( nextState == -1 )
    v3 = (this->curExtraAnimation == -1) - 1;
  curExtraAnimation = this->curExtraAnimation;
  if ( curExtraAnimation != -1 )
  {
    value = this->extraAnimations.list[curExtraAnimation].triggerLeave.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v6 = gameLocal->entities.ptr[this->extraAnimations.list[curExtraAnimation].triggerLeave.spawnId.value & 0x1FFF];
      if ( v6 != nullptr )
      {
        v7 = idEntity::CastTo(c: v6);
        if ( v7 != nullptr )
        {
          v8 = this->playerActivator.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13
            && (v9 = (idPlayer *)gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
          {
            v10 = idPlayer::CastTo(c: v9);
          }
          else
          {
            v10 = nullptr;
          }
          idEntity::Activate(this: v7, activator: v10);
        }
      }
    }
  }
  num = this->extraAnimations.num;
  if ( num != 0 && v3 >= 0 && v3 < num )
  {
    this->curExtraAnimation = v3;
    this->animStartFrame = gameLocal->GetGameFrame(this: gameLocal) + 1;
    v12 = &this->extraAnimations.list[this->curExtraAnimation];
    blendParms_t::blendParms_t(this: &v63);
    blendParms_t::SetDestStartFrame(this: &v63, frame: 0);
    blendParms_t::SetDurationMS(this: &v63, ms: v12->blendTime);
    v63.parms.originBlend = 1;
    v12->stateStarted = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v13 = idEntityPtr<idEntity const>::operator->(this: &v12->triggerEnter);
    if ( v13 != nullptr )
    {
      v14 = idEntityPtr<idPlayer>::operator->(this: &this->playerActivator);
      idEntity::Activate(this: v13, activator: v14);
    }
    if ( v12->legsAnimationHandle.value != 0xFFFF
      && gameLocal->spawnIds.ptr[this->legsEntity.spawnId.value & 0x1FFF] == this->legsEntity.spawnId.value >> 13 )
    {
      this->orgPosLegs.x = this->nextPosLegs.x;
      v15 = &v64;
      v16 = 9;
      p_z = &this->nextPosLegs.z;
      this->orgPosLegs.y = this->nextPosLegs.y;
      this->orgPosLegs.z = this->nextPosLegs.z;
      this->orgAxisLegs.mat[0].x = this->nextRotLegs.mat[0].x;
      this->orgAxisLegs.mat[0].y = this->nextRotLegs.mat[0].y;
      this->orgAxisLegs.mat[0].z = this->nextRotLegs.mat[0].z;
      this->orgAxisLegs.mat[1].x = this->nextRotLegs.mat[1].x;
      this->orgAxisLegs.mat[1].y = this->nextRotLegs.mat[1].y;
      this->orgAxisLegs.mat[1].z = this->nextRotLegs.mat[1].z;
      this->orgAxisLegs.mat[2].x = this->nextRotLegs.mat[2].x;
      this->orgAxisLegs.mat[2].y = this->nextRotLegs.mat[2].y;
      this->orgAxisLegs.mat[2].z = this->nextRotLegs.mat[2].z;
      do
      {
        *++v15 = *(_DWORD *)++p_z;
        --v16;
      }
      while ( v16 != 0 );
      Entity = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->legsEntity);
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: Entity);
      idFirstPersonEvent::GetAnimTotalMovement(
        this,
        ta: TreeAnimatorFromPresentable,
        animHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v12->legsAnimationHandle.value,
        startOrigin: &this->orgPosLegs,
        startAxis: (idQuat *)&this->orgAxisLegs,
        origin: &this->nextPosLegs,
        axis: &this->nextRotLegs,
        a8: v20,
        a9: v55,
        a10: v56,
        a11: v57,
        a12: v58,
        a13: v59,
        a14: v60,
        a15: v61,
        a16: v62);
      timeScale = v12->timeScale;
      v22 = *((unsigned __int8 *)v12 + 116);
      v23 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->legsEntity);
      idAlignedEntity::PlayAnim(
        this: v23,
        aliasHandle: &v12->legsAnimationHandle,
        loop: v22 >> 7,
        durationMS: -1,
        _blendParms: &v63,
        rateScale: timeScale);
      v24 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->legsEntity);
      v26 = !idEntity::IsBound(this: v24);
      p_legsEntity = &this->legsEntity;
      if ( v26 )
      {
        v31 = idEntityPtr<idAlignedEntity>::GetEntity(this: p_legsEntity);
        Physics = idEntity::GetPhysics(this: v31);
        Physics->SetOrigin(this: Physics, a2: &this->orgPosLegs, a3: -1);
        v33 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->legsEntity);
        v34 = idEntity::GetPhysics(this: v33);
        v34->SetAxis(this: v34, a2: &v65, a3: -1);
      }
      else
      {
        v27 = idEntityPtr<idAlignedEntity>::GetEntity(this: p_legsEntity);
        v28 = idEntity::GetPhysics(this: v27);
        v28->SetLocalOrigin(this: v28, a2: &this->orgPosLegs, a3: -1);
        v29 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->legsEntity);
        v30 = idEntity::GetPhysics(this: v29);
        v30->SetLocalAxis(this: v30, a2: &v65, a3: -1);
      }
    }
    if ( v12->handsAnimationHandle.value != 0xFFFF
      && gameLocal->spawnIds.ptr[this->handsEntity.spawnId.value & 0x1FFF] == this->handsEntity.spawnId.value >> 13 )
    {
      this->orgPosHands.x = this->nextPosHands.x;
      this->orgPosHands.y = this->nextPosHands.y;
      v35 = &v64;
      this->orgPosHands.z = this->nextPosHands.z;
      this->orgAxisHands.mat[0].x = this->nextRotHands.mat[0].x;
      v36 = &this->nextPosHands.z;
      v37 = 9;
      this->orgAxisHands.mat[0].y = this->nextRotHands.mat[0].y;
      this->orgAxisHands.mat[0].z = this->nextRotHands.mat[0].z;
      this->orgAxisHands.mat[1].x = this->nextRotHands.mat[1].x;
      this->orgAxisHands.mat[1].y = this->nextRotHands.mat[1].y;
      this->orgAxisHands.mat[1].z = this->nextRotHands.mat[1].z;
      this->orgAxisHands.mat[2].x = this->nextRotHands.mat[2].x;
      this->orgAxisHands.mat[2].y = this->nextRotHands.mat[2].y;
      this->orgAxisHands.mat[2].z = this->nextRotHands.mat[2].z;
      do
      {
        *++v35 = *(_DWORD *)++v36;
        --v37;
      }
      while ( v37 != 0 );
      v38 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->handsEntity);
      v39 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v38);
      idFirstPersonEvent::GetAnimTotalMovement(
        this,
        ta: v39,
        animHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v12->handsAnimationHandle.value,
        startOrigin: &this->orgPosHands,
        startAxis: (idQuat *)&this->orgAxisHands,
        origin: &this->nextPosHands,
        axis: &this->nextRotHands,
        a8: v40,
        a9: v55,
        a10: v56,
        a11: v57,
        a12: v58,
        a13: v59,
        a14: v60,
        a15: v61,
        a16: v62);
      v41 = v12->timeScale;
      v42 = *((unsigned __int8 *)v12 + 116);
      v43 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->handsEntity);
      idAlignedEntity::PlayAnim(
        this: v43,
        aliasHandle: &v12->handsAnimationHandle,
        loop: v42 >> 7,
        durationMS: -1,
        _blendParms: &v63,
        rateScale: v41);
      v44 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->handsEntity);
      v26 = !idEntity::IsBound(this: v44);
      p_handsEntity = &this->handsEntity;
      if ( v26 )
      {
        v50 = idEntityPtr<idAlignedEntity>::GetEntity(this: p_handsEntity);
        v51 = idEntity::GetPhysics(this: v50);
        v51->SetOrigin(this: v51, a2: &this->orgPosHands, a3: -1);
        v52 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->handsEntity);
        v53 = idEntity::GetPhysics(this: v52);
        v53->SetAxis(this: v53, a2: &v65, a3: -1);
      }
      else
      {
        v46 = idEntityPtr<idAlignedEntity>::GetEntity(this: p_handsEntity);
        v47 = idEntity::GetPhysics(this: v46);
        v47->SetLocalOrigin(this: v47, a2: &this->orgPosHands, a3: -1);
        v48 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->handsEntity);
        v49 = idEntity::GetPhysics(this: v48);
        v49->SetLocalAxis(this: v49, a2: &v65, a3: -1);
      }
    }
    if ( gameLocal->spawnIds.ptr[this->perfectDestinationRef.spawnId.value & 0x1FFF] != this->perfectDestinationRef.spawnId.value >> 13
      || (*((_BYTE *)this + 1092) & 0x40) != 0 )
    {
      attachMode = this->attachMode;
      if ( attachMode != ATTACHMODE_LEGS )
      {
        if ( attachMode == ATTACHMODE_HANDS )
        {
          this->playerEndPos.x = this->nextPosHands.x;
          this->playerEndPos.y = this->nextPosHands.y;
          this->playerEndPos.z = this->nextPosHands.z;
          this->playerEndRot.mat[0].x = this->nextRotHands.mat[0].x;
          this->playerEndRot.mat[0].y = this->nextRotHands.mat[0].y;
          this->playerEndRot.mat[0].z = this->nextRotHands.mat[0].z;
          this->playerEndRot.mat[1].x = this->nextRotHands.mat[1].x;
          this->playerEndRot.mat[1].y = this->nextRotHands.mat[1].y;
          this->playerEndRot.mat[1].z = this->nextRotHands.mat[1].z;
          this->playerEndRot.mat[2].x = this->nextRotHands.mat[2].x;
          this->playerEndRot.mat[2].y = this->nextRotHands.mat[2].y;
          this->playerEndRot.mat[2].z = this->nextRotHands.mat[2].z;
        }
      }
      else
      {
        this->playerEndPos.x = this->nextPosLegs.x;
        this->playerEndPos.y = this->nextPosLegs.y;
        this->playerEndPos.z = this->nextPosLegs.z;
        this->playerEndRot.mat[0].x = this->nextRotLegs.mat[0].x;
        this->playerEndRot.mat[0].y = this->nextRotLegs.mat[0].y;
        this->playerEndRot.mat[0].z = this->nextRotLegs.mat[0].z;
        this->playerEndRot.mat[1].x = this->nextRotLegs.mat[1].x;
        this->playerEndRot.mat[1].y = this->nextRotLegs.mat[1].y;
        this->playerEndRot.mat[1].z = this->nextRotLegs.mat[1].z;
        this->playerEndRot.mat[2].x = this->nextRotLegs.mat[2].x;
        this->playerEndRot.mat[2].y = this->nextRotLegs.mat[2].y;
        this->playerEndRot.mat[2].z = this->nextRotLegs.mat[2].z;
      }
    }
  }
  else
  {
    idFirstPersonEvent::StartEndEvent(this);
  }
}


// ========================================================================
// ?SetExternalTime@idFirstPersonEvent@@QAAXM@Z
// EA  : 0x82C4D0A8
// RVA : 0x00C4D0A8
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonEvent::SetExternalTime(idFirstPersonEvent *this, double normalizedTime)
{
  int curExtraAnimation; // r11
  idEntityPtr<idAlignedEntity> *p_legsEntity; // r3
  idGameLocal *v6; // r11
  bool v7; // zf
  idAlignedEntity *Entity; // r3
  idAlignedEntity *v9; // r3

  curExtraAnimation = this->curExtraAnimation;
  this->externalTime = normalizedTime;
  if ( curExtraAnimation != -1 && (*((_BYTE *)&this->extraAnimations.list[curExtraAnimation] + 116) & 0x40) != 0 )
  {
    v7 = gameLocal->spawnIds.ptr[this->legsEntity.spawnId.value & 0x1FFF] != this->legsEntity.spawnId.value >> 13;
    p_legsEntity = &this->legsEntity;
    v6 = gameLocal;
    if ( !v7 )
    {
      Entity = idEntityPtr<idAlignedEntity>::GetEntity(this: p_legsEntity);
      idAlignedEntity::SetExternalTime(this: Entity, normalizedTime);
      v6 = gameLocal;
    }
    if ( v6->spawnIds.ptr[this->handsEntity.spawnId.value & 0x1FFF] == this->handsEntity.spawnId.value >> 13 )
    {
      v9 = idEntityPtr<idAlignedEntity>::GetEntity(this: &this->handsEntity);
      idAlignedEntity::SetExternalTime(this: v9, normalizedTime);
    }
  }
}


// ========================================================================
// ?Event_ForceEndFirstPersonEvent@idFirstPersonEvent@@QAA?AVeventVoid@@XZ
// EA  : 0x82C4D180
// RVA : 0x00C4D180
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

idFirstPersonEvent *__fastcall idFirstPersonEvent::Event_ForceEndFirstPersonEvent(
        idFirstPersonEvent *this,
        idFirstPersonEvent *result)
{
  idPlayer *Player; // r3
  idPlayer *v5; // r31
  idAlignedEntity *thirdPersonLegs; // r3
  idAlignedEntity *thirdPersonHands; // r3

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  v5 = Player;
  if ( Player != nullptr )
  {
    thirdPersonLegs = Player->thirdPersonLegs;
    if ( thirdPersonLegs != nullptr )
      idAlignedEntity::StopAnim(this: thirdPersonLegs);
    thirdPersonHands = v5->thirdPersonHands;
    if ( thirdPersonHands != nullptr )
      idAlignedEntity::StopAnim(this: thirdPersonHands);
  }
  idFirstPersonEvent::StartEndEvent(this: result);
  if ( result->eventEndTime != -1 && result->blendOutTime == 0 )
    idFirstPersonEvent::EndEvent(this: result);
  return this;
}


// ========================================================================
// ?Event_SetFirstPersonEventAnimState@idFirstPersonEvent@@QAA?AVeventVoid@@H@Z
// EA  : 0x82C4D208
// RVA : 0x00C4D208
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

idFirstPersonEvent *__fastcall idFirstPersonEvent::Event_SetFirstPersonEventAnimState(
        idFirstPersonEvent *this,
        idFirstPersonEvent *result,
        int state)
{
  idFirstPersonEvent::SetCurrentState(this: result, nextState: state);
  return this;
}


// ========================================================================
// ?UpdateAnimation@idFirstPersonEvent@@IAA_NXZ
// EA  : 0x82C4D240
// RVA : 0x00C4D240
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

int __fastcall idFirstPersonEvent::UpdateAnimation(idFirstPersonEvent *this)
{
  int v2; // r11
  int v3; // r10
  idEntityPtr<idAlignedEntity> *p_legsEntity; // r24
  int v5; // r25
  idAlignedEntity *v6; // r3
  idAlignedEntity *v7; // r31
  idAlignedEntity *v8; // r3
  idAlignedEntity *v9; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idQuat *v11; // r3
  double x; // fp31
  double y; // fp30
  double z; // fp29
  double w; // fp28
  idPhysics *Physics; // r3
  double v17; // fp7
  double v18; // fp6
  idPhysics *v19; // r30
  idPhysics_vtbl *v20; // r31
  idMat3 *v21; // r3
  idPhysics *v22; // r3
  double v23; // fp7
  idPhysics *v24; // r30
  idPhysics_vtbl *v25; // r31
  idMat3 *v26; // r3
  int v27; // r11
  int v28; // r10
  idAlignedEntity *v29; // r3
  idAlignedEntity *v30; // r31
  idTreeAnimator *v31; // r3
  idQuat *v32; // r3
  double v33; // fp31
  double v34; // fp30
  double v35; // fp29
  double v36; // fp28
  idPhysics *v37; // r3
  double v38; // fp7
  double v39; // fp6
  idPhysics *v40; // r30
  idPhysics_vtbl *v41; // r31
  idMat3 *v42; // r3
  idPhysics *v43; // r3
  double v44; // fp7
  double v45; // fp6
  idPhysics *v46; // r30
  idPhysics_vtbl *v47; // r31
  idMat3 *v48; // r3
  int curExtraAnimation; // r11
  int exitStateFailed; // r28
  idFirstPersonEvent::animEntry_t *v51; // r31
  idFirstPersonEvent::exitCondition_t exitCondition; // r11
  int exitConditionButton; // r23
  idPlayer *v54; // r3
  idUCmdTracker *UCmdTracker2; // r3
  idPlayer *v56; // r3
  int v57; // r3
  idFirstPersonEvent::exitConditionMoveType_t exitConditionMoveType; // r9
  char v59; // r11
  idFirstPersonEvent::attachMode_t attachMode; // r11
  idEntityPtr<idAlignedEntity> *p_handsEntity; // r3
  idAlignedEntity *Entity; // r3
  idTreeAnimator *v64; // r3
  idPlayer *v65; // r3
  idPhysics_Player *PhysicsObj; // r3
  idPresentable *presentable; // r3
  int v68; // r3
  idVec3 v69; // [sp+50h] [-170h] BYREF
  idVec3 v70; // [sp+60h] [-160h] BYREF
  idMat3 v71; // [sp+70h] [-150h] BYREF
  float v72; // [sp+94h] [-12Ch]
  float v73; // [sp+98h] [-128h]
  idMat3 v74; // [sp+A0h] [-120h] BYREF
  float v75; // [sp+C4h] [-FCh]
  float v76; // [sp+C8h] [-F8h]
  float v77[4]; // [sp+D0h] [-F0h] BYREF
  float v78[4]; // [sp+E0h] [-E0h] BYREF
  float v79[4]; // [sp+F0h] [-D0h] BYREF
  idVec3 v80; // [sp+100h] [-C0h] BYREF
  idMat3 v81; // [sp+110h] [-B0h] BYREF
  idQuat v82[3]; // [sp+140h] [-80h] BYREF

  v2 = this->legsEntity.spawnId.value & 0x1FFF;
  v3 = this->legsEntity.spawnId.value >> 13;
  p_legsEntity = &this->legsEntity;
  v5 = 0;
  if ( gameLocal->spawnIds.ptr[v2] == v3 && this->eventEndTime == -1 )
  {
    if ( gameLocal->spawnIds.ptr[v2] == v3 && (v6 = (idAlignedEntity *)gameLocal->entities.ptr[v2]) != nullptr )
      v7 = idAlignedEntity::CastTo(c: v6);
    else
      v7 = nullptr;
    if ( gameLocal->spawnIds.ptr[p_legsEntity->spawnId.value & 0x1FFF] == p_legsEntity->spawnId.value >> 13
      && (v8 = (idAlignedEntity *)gameLocal->entities.ptr[p_legsEntity->spawnId.value & 0x1FFF]) != nullptr )
    {
      v9 = idAlignedEntity::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    if ( idAlignedEntity::IsCurAnimDone(this: v9, numFramesAhead: 4, ignoreQueuedAnims: false) )
    {
      if ( this->attachMode == ATTACHMODE_LEGS )
        v5 = 1;
    }
    else if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v7) != nullptr
           && this->applyMovement
           && v7->lastAnimBlendFrame > this->animStartFrame )
    {
      idMat3::ToQuat(this: (idMat3 *)&v74.mat[1].y, result: (idQuat *)&this->orgAxisLegs);
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v7);
      idTreeAnimator::GetTotalOriginTransform(
        this: TreeAnimatorFromPresentable,
        rot: (idQuat *)&v71.mat[1].y,
        trans: &v69);
      v11 = idQuat::Inverse(this: v82, result: (idQuat *)&v71.mat[1].y);
      x = v11->x;
      v71.mat[1].y = v11->x;
      y = v11->y;
      v71.mat[1].z = v11->y;
      z = v11->z;
      v71.mat[2].x = v11->z;
      w = v11->w;
      idQuat::operator*(this: (idQuat *)&v71.mat[2].z, result: (idVec3 *)&v74.mat[1].y, a: &v69);
      v69.x = v71.mat[2].z;
      v69.y = v72;
      v69.z = v73;
      v71.mat[1].y = -(float)((float)(v74.mat[2].x * (float)y)
                            - (float)((float)(v74.mat[1].z * (float)z)
                                    + (float)((float)((float)w * v74.mat[1].y) + (float)(v74.mat[2].y * (float)x))));
      v71.mat[1].z = -(float)((float)((float)z * v74.mat[1].y)
                            - (float)((float)(v74.mat[2].y * (float)y)
                                    + (float)((float)(v74.mat[2].x * (float)x) + (float)(v74.mat[1].z * (float)w))));
      v71.mat[2].x = -(float)((float)(v74.mat[1].z * (float)x)
                            - (float)((float)(v74.mat[2].y * (float)z)
                                    + (float)((float)((float)y * v74.mat[1].y) + (float)(v74.mat[2].x * (float)w))));
      v71.mat[2].y = -(float)((float)(v74.mat[2].x * (float)z)
                            - (float)-(float)((float)(v74.mat[1].z * (float)y)
                                            - (float)((float)(v74.mat[2].y * (float)w) - (float)(v74.mat[1].y * (float)x))));
      if ( idEntity::IsBound(this: v7) )
      {
        Physics = idEntity::GetPhysics(this: v7);
        v17 = (float)(this->orgPosLegs.y + v69.y);
        v18 = (float)(this->orgPosLegs.z + v69.z);
        v77[0] = v69.x + this->orgPosLegs.x;
        v77[1] = v17;
        v77[2] = v18;
        Physics->SetLocalOrigin(this: Physics, a2: (const idVec3 *)v77, a3: -1);
        v19 = idEntity::GetPhysics(this: v7);
        v20 = v19->__vftable;
        v21 = idQuat::ToMat3(this: (idQuat *)&v81, result: (idMat3 *)&v71.mat[1].y);
        v20->SetLocalAxis(this: v19, a2: v21, a3: -1);
      }
      else
      {
        v22 = idEntity::GetPhysics(this: v7);
        v23 = (float)(v69.x + this->orgPosLegs.x);
        v79[1] = this->orgPosLegs.y + v69.y;
        v79[0] = v23;
        v79[2] = this->orgPosLegs.z + v69.z;
        v22->SetOrigin(this: v22, a2: (const idVec3 *)v79, a3: -1);
        v24 = idEntity::GetPhysics(this: v7);
        v25 = v24->__vftable;
        v26 = idQuat::ToMat3(this: (idQuat *)&v81, result: (idMat3 *)&v71.mat[1].y);
        v25->SetAxis(this: v24, a2: v26, a3: -1);
      }
    }
  }
  v27 = this->handsEntity.spawnId.value & 0x1FFF;
  v28 = this->handsEntity.spawnId.value >> 13;
  if ( gameLocal->spawnIds.ptr[v27] == v28 && this->eventEndTime == -1 )
  {
    if ( gameLocal->spawnIds.ptr[v27] == v28 && (v29 = (idAlignedEntity *)gameLocal->entities.ptr[v27]) != nullptr )
      v30 = idAlignedEntity::CastTo(c: v29);
    else
      v30 = nullptr;
    if ( idAlignedEntity::IsCurAnimDone(this: v30, numFramesAhead: 4, ignoreQueuedAnims: false) )
    {
      if ( this->attachMode == ATTACHMODE_HANDS )
        v5 = 1;
    }
    else if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v30) != nullptr
           && this->applyMovement
           && v30->lastAnimBlendFrame > this->animStartFrame )
    {
      idMat3::ToQuat(this: &v74, result: (idQuat *)&this->orgAxisHands);
      v31 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v30);
      idTreeAnimator::GetTotalOriginTransform(this: v31, rot: (idQuat *)&v71, trans: &v70);
      v32 = idQuat::Inverse(this: v82, result: (idQuat *)&v71);
      v33 = v32->x;
      v71.mat[0].x = v32->x;
      v34 = v32->y;
      v71.mat[0].y = v32->y;
      v35 = v32->z;
      v71.mat[0].z = v32->z;
      v36 = v32->w;
      idQuat::operator*(this: (idQuat *)&v71.mat[2].z, result: v74.mat, a: &v70);
      v70.x = v71.mat[2].z;
      v70.y = v72;
      v70.z = v73;
      v71.mat[0].x = -(float)((float)(v74.mat[0].z * (float)v34)
                            - (float)((float)((float)v36 * v74.mat[0].x)
                                    + (float)((float)(v74.mat[0].y * (float)v35) + (float)(v74.mat[1].x * (float)v33))));
      v71.mat[0].y = -(float)((float)((float)v35 * v74.mat[0].x)
                            - (float)((float)(v74.mat[0].z * (float)v33)
                                    + (float)((float)(v74.mat[0].y * (float)v36) + (float)(v74.mat[1].x * (float)v34))));
      v71.mat[1].x = -(float)((float)(v74.mat[0].z * (float)v35)
                            - (float)-(float)((float)(v74.mat[0].y * (float)v34)
                                            - (float)((float)(v74.mat[1].x * (float)v36)
                                                    - (float)(v74.mat[0].x * (float)v33))));
      v71.mat[0].z = -(float)((float)(v74.mat[0].y * (float)v33)
                            - (float)((float)((float)v34 * v74.mat[0].x)
                                    + (float)((float)(v74.mat[1].x * (float)v35) + (float)(v74.mat[0].z * (float)v36))));
      if ( idEntity::IsBound(this: v30) )
      {
        v37 = idEntity::GetPhysics(this: v30);
        v38 = (float)(this->orgPosHands.z + v70.z);
        v39 = (float)(this->orgPosHands.y + v70.y);
        v78[0] = v70.x + this->orgPosHands.x;
        v78[2] = v38;
        v78[1] = v39;
        v37->SetLocalOrigin(this: v37, a2: (const idVec3 *)v78, a3: -1);
        v40 = idEntity::GetPhysics(this: v30);
        v41 = v40->__vftable;
        v42 = idQuat::ToMat3(this: (idQuat *)&v81, result: &v71);
        v41->SetLocalAxis(this: v40, a2: v42, a3: -1);
      }
      else
      {
        v43 = idEntity::GetPhysics(this: v30);
        v44 = (float)(v70.x + this->orgPosHands.x);
        v45 = (float)(this->orgPosHands.z + v70.z);
        v75 = this->orgPosHands.y + v70.y;
        v74.mat[2].z = v44;
        v76 = v45;
        v43->SetOrigin(this: v43, a2: (const idVec3 *)&v74.mat[2].z, a3: -1);
        v46 = idEntity::GetPhysics(this: v30);
        v47 = v46->__vftable;
        v48 = idQuat::ToMat3(this: (idQuat *)&v81, result: &v71);
        v47->SetAxis(this: v46, a2: v48, a3: -1);
      }
    }
  }
  curExtraAnimation = this->curExtraAnimation;
  exitStateFailed = -1;
  if ( curExtraAnimation >= 0 && curExtraAnimation < this->extraAnimations.num )
  {
    v51 = &this->extraAnimations.list[curExtraAnimation];
    if ( gameLocal->spawnIds.ptr[this->playerActivator.spawnId.value & 0x1FFF] == this->playerActivator.spawnId.value >> 13
      && (exitCondition = v51->exitCondition) != EXITCONDITION_NONE )
    {
      if ( (_BYTE)v5 != 0 )
      {
        exitStateFailed = v51->exitStateFailed;
        goto LABEL_62;
      }
      if ( (exitCondition & 1) != 0 )
      {
        exitConditionButton = v51->exitConditionButton;
        v54 = idEntityPtr<idPlayer>::operator->(this: &this->playerActivator);
        UCmdTracker2 = (idUCmdTracker *)idPlayer::GetUCmdTracker2(this: v54);
        if ( idUCmdTracker::IsPressedForPlayer(this: UCmdTracker2, mask: exitConditionButton) )
        {
          exitStateFailed = v51->exitStateSucceded;
          v5 = 1;
        }
      }
      if ( (v51->exitCondition & 2) != 0 )
      {
        v56 = idEntityPtr<idPlayer>::operator->(this: &this->playerActivator);
        v57 = idPlayer::GetUCmdTracker2(this: v56);
        exitConditionMoveType = v51->exitConditionMoveType;
        v59 = 0;
        if ( (exitConditionMoveType & 1) != 0 )
          v59 = (((*(char *)(v57 + 135) ^ v51->exitParameters) >= 0)
               + (v51->exitParameters >= (unsigned int)*(char *)(v57 + 135)))
              & 1;
        if ( (exitConditionMoveType & 2) != 0 )
          v59 |= (((-*(char *)(v57 + 135) ^ v51->exitParameters) >= 0)
                + (v51->exitParameters >= (unsigned int)-*(char *)(v57 + 135)))
               & 1;
        if ( (exitConditionMoveType & 4) != 0 )
          v59 |= (((*(char *)(v57 + 134) ^ v51->exitParameters) >= 0)
                + (v51->exitParameters >= (unsigned int)*(char *)(v57 + 134)))
               & 1;
        if ( (exitConditionMoveType & 8) != 0 )
          v59 |= (((-*(char *)(v57 + 134) ^ v51->exitParameters) >= 0)
                + (v51->exitParameters >= (unsigned int)-*(char *)(v57 + 134)))
               & 1;
        if ( v59 != 0 )
        {
          v5 = 1;
LABEL_61:
          exitStateFailed = v51->exitStateSucceded;
        }
      }
    }
    else if ( (*((_BYTE *)v51 + 116) & 0x80) != 0 )
    {
      if ( v51->maxLoopTime > 0
        && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - v51->stateStarted > v51->maxLoopTime )
      {
        exitStateFailed = v51->exitStateFailed;
        v5 = 1;
      }
    }
    else if ( (_BYTE)v5 != 0 && v51->exitCondition == EXITCONDITION_NONE )
    {
      goto LABEL_61;
    }
  }
LABEL_62:
  if ( (_BYTE)v5 != 0 )
  {
    idFirstPersonEvent::SetCurrentState(this, nextState: exitStateFailed);
    return v5;
  }
  if ( (*((_BYTE *)this + 1092) & 8) != 0
    && gameLocal->spawnIds.ptr[this->playerActivator.spawnId.value & 0x1FFF] == this->playerActivator.spawnId.value >> 13
    && this->eventEndTime == -1 )
  {
    attachMode = this->attachMode;
    if ( attachMode == ATTACHMODE_HANDS )
    {
      p_handsEntity = &this->handsEntity;
LABEL_71:
      Entity = idEntityPtr<idAlignedEntity>::GetEntity(this: p_handsEntity);
      if ( Entity != nullptr )
      {
        v64 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: Entity);
        if ( v64 != nullptr
          && (unsigned __int8)idTreeAnimator::GetWorldSpaceJointTransform(
                                this: v64,
                                pose: DRIVER_MODEL,
                                jointIndex: nullptr,
                                origin: &v80,
                                axis: &v81) != 0 )
        {
          v65 = idEntityPtr<idPlayer>::operator->(this: &this->playerActivator);
          PhysicsObj = idPlayer::GetPhysicsObj(this: v65);
          idPhysics_Player::StartPerfectOrigin(this: PhysicsObj, idealPos: &v80, lerpTimeMs: 0);
          presentable = idEntityPtr<idPlayer>::operator->(this: &this->playerActivator)->presentable;
          if ( presentable != nullptr )
            v68 = (int)presentable->GetPlayerInterface_2(this: presentable);
          else
            v68 = 0;
          *(_BYTE *)(v68 + 47033) |= 4u;
        }
      }
      return v5;
    }
    if ( attachMode == ATTACHMODE_LEGS )
    {
      p_handsEntity = p_legsEntity;
      goto LABEL_71;
    }
  }
  return v5;
}


// ========================================================================
// ?OnActivate@idFirstPersonEvent@@UAAXPAVidEntity@@@Z
// EA  : 0x82C4DB60
// RVA : 0x00C4DB60
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonEvent::OnActivate(idFirstPersonEvent *this, idPlayer *activator)
{
  idPlayer *Player; // r29
  int v4; // r3
  int num; // r8
  idAlignedEntity *thirdPersonLegs; // r15
  idAlignedEntity *thirdPersonHands; // r14
  idPhysics *Physics; // r3
  int v9; // r3
  float v10; // r7
  float v11; // r6
  idPhysics *v12; // r3
  int v13; // r3
  char *v14; // r10
  _DWORD *v15; // r11
  int i; // ctr
  int value; // r10
  idEntity *v18; // r3
  idEntity *v19; // r3
  idEntity *v20; // r30
  idPhysics *v21; // r3
  float *v22; // r3
  double v23; // fp31
  double v24; // fp29
  double v25; // fp30
  idPhysics *v26; // r3
  float *v27; // r3
  double v28; // fp20
  double v29; // fp21
  double v30; // fp22
  double v31; // fp23
  double v32; // fp24
  double v33; // fp25
  double x; // fp26
  double y; // fp27
  double z; // fp28
  idGameLocal *v37; // r10
  idMat3 *p_orgAxisLegs; // r28
  idMat3 *p_orgAxisHands; // r19
  idMat3 *p_playerEndRot; // r24
  idVec3 *v41; // r30
  idVec3 *v42; // r29
  idVec3 *v43; // r21
  idVec3 *v44; // r20
  idVec3 *v45; // r23
  idVec3 *v46; // r22
  idVec3 *p_orgPosLegs; // r25
  idVec3 *p_orgPosHands; // r17
  idVec3 *p_playerEndPos; // r18
  int v50; // r8
  idEntity *v51; // r3
  idEntity *v52; // r3
  idEntity *v53; // r27
  idPhysics *v54; // r3
  float *v55; // r3
  idPhysics *v56; // r3
  float *v57; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v59; // r27
  idTreeAnimator *v60; // r3
  idTreeAnimator *v61; // r27
  unsigned __int16 v62; // r10
  idFirstPersonEvent::animEntry_t *list; // r27
  idEntity *v64; // r27
  idPlayer *v65; // r3
  char *data; // r26
  idWorldspawn *v67; // r3
  char *v68; // r27
  idWorldspawn *v69; // r3
  char *v70; // r26
  idAnimatedEntity *v71; // r3
  char *v72; // r27
  idAnimatedEntity *v73; // r3
  idWorldspawn *v74; // r3
  idWorldspawn *v75; // r3
  idPhysics *v76; // r3
  float *v77; // r3
  idPhysics *v78; // r3
  float *v79; // r3
  idPresentable *presentable; // r11
  idPhysics *v81; // r3
  float *v82; // r3
  idPhysics *v83; // r3
  float *v84; // r3
  idPresentable *v85; // r11
  const idTreeAnimator *v86; // r16
  int v87; // r10
  idPhysics *v88; // r3
  double v89; // fp3
  double v90; // fp5
  double v91; // fp13
  double v92; // fp12
  double v93; // fp1
  double v94; // fp2
  double v95; // fp3
  double v96; // fp0
  float *v97; // r3
  const idTreeAnimator *v98; // r27
  int v99; // r10
  idPhysics *v100; // r3
  double v101; // fp3
  double v102; // fp5
  double v103; // fp10
  double v104; // fp9
  double v105; // fp1
  double v106; // fp7
  double v107; // fp6
  float *v108; // r3
  idFirstPersonEvent::attachMode_t attachMode; // r11
  double v110; // fp3
  idPhysics *v111; // r3
  idPhysics *v112; // r3
  idPhysics *v113; // r3
  idPhysics *v114; // r3
  idPhysics *v115; // r3
  idPhysics *v116; // r3
  idPhysics *v117; // r3
  idPhysics *v118; // r3
  idAlignedEntity *v119; // r3
  idEntity *v120; // r28
  idSpringCamera *springCamera; // r30
  idPresentable *v122; // r3
  int v123; // r3
  idPresentable *v124; // r3
  int v125; // r3
  idPresentable *v126; // r3
  int v127; // r3
  idPresentable *v128; // r3
  idPresentablePlayer *v129; // r3
  int v130; // r29
  int v131; // r30
  int v132; // r9
  idEntity *v133; // r3
  idEntity *v134; // r3
  int v135; // [sp+8h] [-248h]
  int v136; // [sp+Ch] [-244h]
  int v137; // [sp+10h] [-240h]
  int v138; // [sp+14h] [-23Ch]
  int v139; // [sp+18h] [-238h]
  int v140; // [sp+1Ch] [-234h]
  int v141; // [sp+20h] [-230h]
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v142; // [sp+24h] [-22Ch]
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v143; // [sp+50h] [-200h] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v144; // [sp+52h] [-1FEh] BYREF
  char v145; // [sp+54h] [-1FCh]
  char v146; // [sp+5Ch] [-1F4h] BYREF
  idMat3 v147; // [sp+60h] [-1F0h] BYREF
  idTreeAnimator *v148; // [sp+84h] [-1CCh]
  idPlayer *v149; // [sp+88h] [-1C8h]
  idTreeAnimator *v150; // [sp+8Ch] [-1C4h]
  idEntityPtr<idPlayer> *p_playerActivator; // [sp+90h] [-1C0h]
  float v152; // [sp+98h] [-1B8h]
  float v153; // [sp+9Ch] [-1B4h]
  float v154; // [sp+A0h] [-1B0h]
  float v155[4]; // [sp+A8h] [-1A8h] BYREF
  float v156[6]; // [sp+B8h] [-198h] BYREF
  float v157; // [sp+D0h] [-180h] BYREF
  float v158; // [sp+D4h] [-17Ch]
  float v159; // [sp+D8h] [-178h]
  float v160; // [sp+DCh] [-174h]
  float v161; // [sp+E0h] [-170h]
  float v162; // [sp+E4h] [-16Ch]
  float v163; // [sp+E8h] [-168h]
  float v164; // [sp+ECh] [-164h]
  float v165; // [sp+F0h] [-160h]
  float v166; // [sp+100h] [-150h] BYREF
  float v167; // [sp+104h] [-14Ch]
  float v168; // [sp+108h] [-148h]
  float v169; // [sp+10Ch] [-144h]
  float v170; // [sp+110h] [-140h]
  float v171; // [sp+114h] [-13Ch]
  float v172; // [sp+118h] [-138h]
  float v173; // [sp+11Ch] [-134h]
  float v174; // [sp+120h] [-130h]
  idMat3 v175[3]; // [sp+130h] [-120h] BYREF

  Player = idPlayer::CastTo(c: activator);
  v149 = Player;
  if ( Player == nullptr )
  {
    if ( (*((_BYTE *)this + 1092) & 0x20) == 0 )
      return;
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    v149 = Player;
    if ( Player == nullptr )
      return;
  }
  idPlayer::PlayerBehavior_EndAllBehaviors(this: Player);
  p_playerActivator = &this->playerActivator;
  this->playerActivator.spawnId.value = (gameLocal->spawnIds.ptr[Player->entityNumber] << 13) | Player->entityNumber;
  idEntity::BecomeActive(this, flags: 1);
  this->eventStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v4 = gameLocal->GetGameFrame(this: gameLocal);
  num = this->extraAnimations.num;
  this->animStartFrame = v4;
  this->eventEndTime = -1;
  this->curExtraAnimation = -1;
  this->applyMovement = (-num & ~num) < 0;
  thirdPersonLegs = Player->thirdPersonLegs;
  thirdPersonHands = Player->thirdPersonHands;
  if ( thirdPersonLegs != nullptr )
    this->legsEntity.spawnId.value = (gameLocal->spawnIds.ptr[thirdPersonLegs->entityNumber] << 13)
                                   | thirdPersonLegs->entityNumber;
  else
    this->legsEntity.spawnId.value = 0x1FFF;
  if ( thirdPersonHands != nullptr )
    this->handsEntity.spawnId.value = (gameLocal->spawnIds.ptr[thirdPersonHands->entityNumber] << 13)
                                    | thirdPersonHands->entityNumber;
  else
    this->handsEntity.spawnId.value = 0x1FFF;
  Physics = idEntity::GetPhysics(this);
  v9 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v10 = *(float *)(v9 + 4);
  v11 = *(float *)(v9 + 8);
  v152 = *(float *)v9;
  v153 = v10;
  v154 = v11;
  v12 = idEntity::GetPhysics(this);
  v13 = (int)v12->GetAxis(this: v12, a2: 0);
  v14 = &v146;
  v15 = (_DWORD *)(v13 - 4);
  for ( i = 9; i != 0; --i )
  {
    ++v15;
    v14 += 4;
    *(_DWORD *)v14 = *v15;
  }
  value = this->perfectOriginRef.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v18 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v19 = idEntity::CastTo(c: v18), v20 = v19, v19 != nullptr) )
  {
    v21 = idEntity::GetPhysics(this: v19);
    v22 = (float *)v21->GetOrigin(this: v21, a2: 0);
    v23 = *v22;
    v24 = v22[1];
    v25 = v22[2];
    v26 = idEntity::GetPhysics(this: v20);
    v27 = (float *)v26->GetAxis(this: v26, a2: 0);
    v28 = *v27;
    v29 = v27[1];
    v30 = v27[2];
    v31 = v27[3];
    v32 = v27[4];
    v33 = v27[5];
    x = v27[6];
    y = v27[7];
    z = v27[8];
  }
  else
  {
    v25 = v154;
    v24 = v153;
    v23 = v152;
    z = v147.mat[2].z;
    y = v147.mat[2].y;
    x = v147.mat[2].x;
    v33 = v147.mat[1].z;
    v32 = v147.mat[1].y;
    v31 = v147.mat[1].x;
    v30 = v147.mat[0].z;
    v29 = v147.mat[0].y;
    v28 = v147.mat[0].x;
  }
  this->orgPosLegs.y = v24;
  v37 = gameLocal;
  this->orgPosLegs.z = v25;
  p_orgAxisLegs = &this->orgAxisLegs;
  this->orgPosLegs.x = v23;
  p_orgAxisHands = &this->orgAxisHands;
  this->orgPosHands.x = v23;
  p_playerEndRot = &this->playerEndRot;
  this->orgPosHands.y = this->orgPosLegs.y;
  v41 = &this->orgAxisLegs.mat[1];
  v42 = &this->orgAxisLegs.mat[2];
  this->orgPosHands.z = this->orgPosLegs.z;
  v43 = &this->orgAxisHands.mat[1];
  this->orgAxisLegs.mat[0].x = v28;
  v44 = &this->orgAxisHands.mat[2];
  this->orgAxisLegs.mat[1].x = v31;
  v45 = &this->playerEndRot.mat[1];
  this->orgAxisLegs.mat[0].y = v29;
  v46 = &this->playerEndRot.mat[2];
  this->orgAxisLegs.mat[0].z = v30;
  p_orgPosLegs = &this->orgPosLegs;
  this->orgAxisLegs.mat[1].y = v32;
  p_orgPosHands = &this->orgPosHands;
  this->orgAxisLegs.mat[1].z = v33;
  p_playerEndPos = &this->playerEndPos;
  this->orgAxisLegs.mat[2].x = x;
  v145 = 0;
  this->orgAxisLegs.mat[2].y = y;
  this->orgAxisLegs.mat[2].z = z;
  this->orgAxisHands.mat[0].x = this->orgAxisLegs.mat[0].x;
  this->orgAxisHands.mat[0].y = this->orgAxisLegs.mat[0].y;
  this->orgAxisHands.mat[0].z = this->orgAxisLegs.mat[0].z;
  this->orgAxisHands.mat[1].x = this->orgAxisLegs.mat[1].x;
  this->orgAxisHands.mat[1].y = this->orgAxisLegs.mat[1].y;
  this->orgAxisHands.mat[1].z = this->orgAxisLegs.mat[1].z;
  this->orgAxisHands.mat[2].x = this->orgAxisLegs.mat[2].x;
  this->orgAxisHands.mat[2].y = this->orgAxisLegs.mat[2].y;
  this->orgAxisHands.mat[2].z = this->orgAxisLegs.mat[2].z;
  this->playerEndPos.x = v23;
  this->playerEndPos.y = v24;
  this->playerEndPos.z = v25;
  this->playerEndRot.mat[0].x = v28;
  this->playerEndRot.mat[1].x = v31;
  this->playerEndRot.mat[0].y = v29;
  this->playerEndRot.mat[0].z = v30;
  this->playerEndRot.mat[1].y = v32;
  this->playerEndRot.mat[1].z = v33;
  this->playerEndRot.mat[2].x = x;
  this->playerEndRot.mat[2].y = y;
  this->playerEndRot.mat[2].z = z;
  v50 = this->perfectDestinationRef.spawnId.value;
  if ( v37->spawnIds.ptr[v50 & 0x1FFF] == v50 >> 13 )
  {
    v51 = gameLocal->entities.ptr[v50 & 0x1FFF];
    if ( v51 != nullptr )
    {
      v52 = idEntity::CastTo(c: v51);
      v53 = v52;
      if ( v52 != nullptr )
      {
        v145 = 1;
        v54 = idEntity::GetPhysics(this: v52);
        v55 = (float *)v54->GetOrigin(this: v54, a2: 0);
        p_playerEndPos->x = *v55;
        this->playerEndPos.y = v55[1];
        this->playerEndPos.z = v55[2];
        v56 = idEntity::GetPhysics(this: v53);
        v57 = (float *)v56->GetAxis(this: v56, a2: 0);
        p_playerEndRot->mat[0].x = *v57;
        this->playerEndRot.mat[0].y = v57[1];
        this->playerEndRot.mat[0].z = v57[2];
        v45->x = v57[3];
        this->playerEndRot.mat[1].y = v57[4];
        this->playerEndRot.mat[1].z = v57[5];
        v46->x = v57[6];
        this->playerEndRot.mat[2].y = v57[7];
        this->playerEndRot.mat[2].z = v57[8];
      }
    }
  }
  v148 = nullptr;
  v150 = nullptr;
  if ( thirdPersonLegs != nullptr )
  {
    thirdPersonLegs->okToShow = false;
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonLegs);
    v59 = TreeAnimatorFromPresentable;
    v148 = TreeAnimatorFromPresentable;
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      this->removeOriginTransformLegs = idTreeAnimator::GetRemoveOriginTranslation(ptr: TreeAnimatorFromPresentable);
      idTreeAnimator::SetRemoveOriginRotation(this: v59, removeRotation: this->applyMovement);
    }
  }
  if ( thirdPersonHands != nullptr )
  {
    thirdPersonHands->okToShow = false;
    v60 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonHands);
    v61 = v60;
    v150 = v60;
    if ( v60 != nullptr )
    {
      this->removeOriginTransformHands = idTreeAnimator::GetRemoveOriginTranslation(ptr: v60);
      idTreeAnimator::SetRemoveOriginRotation(this: v61, removeRotation: this->applyMovement);
    }
  }
  v62 = this->handsAnimationHandle.value;
  v143.value = this->legsAnimationHandle.value;
  v144.value = v62;
  if ( v143.value == 0xFFFF && v62 == 0xFFFF && this->extraAnimations.num != 0 )
  {
    list = this->extraAnimations.list;
    this->curExtraAnimation = 0;
    v143.value = list->legsAnimationHandle.value;
    v144.value = list->handsAnimationHandle.value;
    list->stateStarted = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v64 = idEntityPtr<idEntity const>::operator->(this: &list->triggerEnter);
    if ( v64 != nullptr )
    {
      v65 = idEntityPtr<idPlayer>::operator->(this: p_playerActivator);
      idEntity::Activate(this: v64, activator: v65);
    }
  }
  if ( gameLocal->spawnIds.ptr[this->fpBindinfo.bindParent.spawnId.value & 0x1FFF] == this->fpBindinfo.bindParent.spawnId.value >> 13 )
  {
    if ( thirdPersonLegs != nullptr )
    {
      *((_BYTE *)&thirdPersonLegs->bindInfo + 112) |= 0x10u;
      thirdPersonLegs->bindInfo.bindOffset.pitch = this->fpBindinfo.bindOffset.pitch;
      thirdPersonLegs->bindInfo.bindOffset.yaw = this->fpBindinfo.bindOffset.yaw;
      thirdPersonLegs->bindInfo.bindOffset.roll = this->fpBindinfo.bindOffset.roll;
    }
    if ( thirdPersonHands != nullptr )
    {
      *((_BYTE *)&thirdPersonHands->bindInfo + 112) |= 0x10u;
      thirdPersonHands->bindInfo.bindOffset.pitch = this->fpBindinfo.bindOffset.pitch;
      thirdPersonHands->bindInfo.bindOffset.yaw = this->fpBindinfo.bindOffset.yaw;
      thirdPersonHands->bindInfo.bindOffset.roll = this->fpBindinfo.bindOffset.roll;
    }
    if ( this->fpBindinfo.bindToTag.len != 0 )
    {
      if ( thirdPersonLegs != nullptr )
      {
        data = this->fpBindinfo.bindToTag.data;
        v67 = (idWorldspawn *)idEntityPtr<idEntity const>::operator->(this: &this->fpBindinfo.bindParent);
        idEntity::BindToTag(this: thirdPersonLegs, master: v67, tagName: data, orientated: true);
      }
      if ( thirdPersonHands != nullptr )
      {
        v68 = this->fpBindinfo.bindToTag.data;
        v69 = (idWorldspawn *)idEntityPtr<idEntity const>::operator->(this: &this->fpBindinfo.bindParent);
        idEntity::BindToTag(this: thirdPersonHands, master: v69, tagName: v68, orientated: true);
      }
    }
    else if ( this->fpBindinfo.bindToJoint.len != 0 )
    {
      if ( thirdPersonLegs != nullptr )
      {
        v70 = this->fpBindinfo.bindToJoint.data;
        v71 = (idAnimatedEntity *)idEntityPtr<idEntity const>::operator->(this: &this->fpBindinfo.bindParent);
        idEntity::BindToJoint(this: thirdPersonLegs, master: v71, animName: nullptr, jointName: v70, orientated: true);
      }
      if ( thirdPersonHands != nullptr )
      {
        v72 = this->fpBindinfo.bindToJoint.data;
        v73 = (idAnimatedEntity *)idEntityPtr<idEntity const>::operator->(this: &this->fpBindinfo.bindParent);
        idEntity::BindToJoint(this: thirdPersonHands, master: v73, animName: nullptr, jointName: v72, orientated: true);
      }
    }
    else
    {
      if ( thirdPersonLegs != nullptr )
      {
        v74 = (idWorldspawn *)idEntityPtr<idEntity const>::operator->(this: &this->fpBindinfo.bindParent);
        idEntity::Bind(this: thirdPersonLegs, master: v74, orientated: true);
      }
      if ( thirdPersonHands != nullptr )
      {
        v75 = (idWorldspawn *)idEntityPtr<idEntity const>::operator->(this: &this->fpBindinfo.bindParent);
        idEntity::Bind(this: thirdPersonHands, master: v75, orientated: true);
      }
    }
    if ( thirdPersonLegs != nullptr )
    {
      v76 = idEntity::GetPhysics(this: thirdPersonLegs);
      v77 = (float *)v76->GetOrigin(this: v76, a2: 0);
      p_orgPosLegs->x = *v77;
      this->orgPosLegs.y = v77[1];
      this->orgPosLegs.z = v77[2];
      v78 = idEntity::GetPhysics(this: thirdPersonLegs);
      v79 = (float *)v78->GetAxis(this: v78, a2: 0);
      p_orgAxisLegs->mat[0].x = *v79;
      this->orgAxisLegs.mat[0].y = v79[1];
      this->orgAxisLegs.mat[0].z = v79[2];
      v41->x = v79[3];
      this->orgAxisLegs.mat[1].y = v79[4];
      this->orgAxisLegs.mat[1].z = v79[5];
      v42->x = v79[6];
      this->orgAxisLegs.mat[2].y = v79[7];
      this->orgAxisLegs.mat[2].z = v79[8];
      presentable = thirdPersonLegs->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: thirdPersonLegs);
        presentable = thirdPersonLegs->presentable;
      }
      presentable->model->useDeferredPosition = false;
    }
    if ( thirdPersonHands != nullptr )
    {
      v81 = idEntity::GetPhysics(this: thirdPersonHands);
      v82 = (float *)v81->GetOrigin(this: v81, a2: 0);
      p_orgPosHands->x = *v82;
      this->orgPosHands.y = v82[1];
      this->orgPosHands.z = v82[2];
      v83 = idEntity::GetPhysics(this: thirdPersonHands);
      v84 = (float *)v83->GetAxis(this: v83, a2: 0);
      p_orgAxisHands->mat[0].x = *v84;
      this->orgAxisHands.mat[0].y = v84[1];
      this->orgAxisHands.mat[0].z = v84[2];
      v43->x = v84[3];
      this->orgAxisHands.mat[1].y = v84[4];
      this->orgAxisHands.mat[1].z = v84[5];
      v44->x = v84[6];
      this->orgAxisHands.mat[2].y = v84[7];
      this->orgAxisHands.mat[2].z = v84[8];
      v85 = thirdPersonHands->presentable;
      if ( v85 == nullptr )
      {
        idEntity::InitPresentableInternal(this: thirdPersonHands);
        v85 = thirdPersonHands->presentable;
      }
      v85->model->useDeferredPosition = false;
    }
  }
  if ( v143.value != 0xFFFF )
  {
    v86 = v148;
    if ( v148 != nullptr )
    {
      this->nextPosLegs.x = v23;
      this->nextPosLegs.y = v24;
      this->nextPosLegs.z = v25;
      this->nextRotLegs.mat[0].x = v28;
      this->nextRotLegs.mat[1].x = v31;
      this->nextRotLegs.mat[0].y = v29;
      this->nextRotLegs.mat[0].z = v30;
      this->nextRotLegs.mat[1].y = v32;
      this->nextRotLegs.mat[1].z = v33;
      this->nextRotLegs.mat[2].x = x;
      this->nextRotLegs.mat[2].y = y;
      this->nextRotLegs.mat[2].z = z;
      if ( idEntity::IsBound(this: thirdPersonLegs) )
      {
        v88 = idEntity::GetPhysics(this: thirdPersonLegs);
        v88->callbacks->GetMasterPosition(this: v88->callbacks, a2: (idVec3 *)v156, a3: (idMat3 *)&v157);
        v89 = (float)(this->orgPosLegs.z - v156[2]);
        v90 = (float)(this->orgPosLegs.y - v156[1]);
        v147.mat[2].x = v159;
        v147.mat[2].y = v162;
        v147.mat[2].z = v165;
        v91 = v160;
        v92 = v163;
        v147.mat[0].x = v157;
        v147.mat[0].y = v160;
        v147.mat[0].z = v163;
        v93 = (float)(p_orgPosLegs->x - v156[0]);
        v147.mat[1].x = v158;
        v147.mat[1].y = v161;
        v94 = (float)((float)(v164 * (float)v90) + (float)(v165 * (float)v89));
        v147.mat[1].z = v164;
        v96 = (float)((float)(v157 * (float)v93) + (float)((float)(v158 * (float)v90) + (float)(v159 * (float)v89)));
        v95 = (float)((float)(v161 * (float)v90) + (float)(v162 * (float)v89));
        p_orgPosLegs->x = v96;
        this->orgPosLegs.z = (float)((float)v92 * (float)v93) + (float)v94;
        this->orgPosLegs.y = (float)((float)v91 * (float)v93) + (float)v95;
        v97 = (float *)idMat3::operator*(this: v175, result: &this->orgAxisLegs, a: &v147);
        p_orgAxisLegs->mat[0].x = *v97;
        this->orgAxisLegs.mat[0].y = v97[1];
        this->orgAxisLegs.mat[0].z = v97[2];
        v41->x = v97[3];
        this->orgAxisLegs.mat[1].y = v97[4];
        this->orgAxisLegs.mat[1].z = v97[5];
        v42->x = v97[6];
        this->orgAxisLegs.mat[2].y = v97[7];
        this->orgAxisLegs.mat[2].z = v97[8];
      }
      idFirstPersonEvent::GetAnimTotalMovement(
        this,
        ta: v86,
        animHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v143.value,
        startOrigin: &this->orgPosLegs,
        startAxis: (idQuat *)&this->orgAxisLegs,
        origin: &this->nextPosLegs,
        axis: &this->nextRotLegs,
        a8: v87,
        a9: v135,
        a10: v136,
        a11: v137,
        a12: v138,
        a13: v139,
        a14: v140,
        a15: v141,
        a16: v142);
    }
  }
  if ( v144.value != 0xFFFF )
  {
    v98 = v150;
    if ( v150 != nullptr )
    {
      this->nextPosHands.x = v23;
      this->nextPosHands.y = v24;
      this->nextPosHands.z = v25;
      this->nextRotHands.mat[0].x = v28;
      this->nextRotHands.mat[1].x = v31;
      this->nextRotHands.mat[0].y = v29;
      this->nextRotHands.mat[0].z = v30;
      this->nextRotHands.mat[1].y = v32;
      this->nextRotHands.mat[1].z = v33;
      this->nextRotHands.mat[2].x = x;
      this->nextRotHands.mat[2].y = y;
      this->nextRotHands.mat[2].z = z;
      if ( idEntity::IsBound(this: thirdPersonHands) )
      {
        v100 = idEntity::GetPhysics(this: thirdPersonHands);
        v100->callbacks->GetMasterPosition(this: v100->callbacks, a2: (idVec3 *)v155, a3: (idMat3 *)&v166);
        v101 = (float)(p_orgPosHands->x - v155[0]);
        v102 = (float)(this->orgPosHands.z - v155[2]);
        v147.mat[0].x = v166;
        v147.mat[0].y = v169;
        v147.mat[0].z = v172;
        v147.mat[2].x = v168;
        v147.mat[2].y = v171;
        v147.mat[2].z = v174;
        v103 = v170;
        v104 = v173;
        v105 = (float)(this->orgPosHands.y - v155[1]);
        v147.mat[1].x = v167;
        v147.mat[1].y = v170;
        v106 = (float)((float)(v171 * (float)v102) + (float)((float)v101 * v169));
        v147.mat[1].z = v173;
        v107 = (float)((float)(v174 * (float)v102) + (float)((float)v101 * v172));
        p_orgPosHands->x = (float)((float)v105 * v167)
                         + (float)((float)(v168 * (float)v102) + (float)((float)v101 * v166));
        this->orgPosHands.y = (float)((float)v105 * (float)v103) + (float)v106;
        this->orgPosHands.z = (float)((float)v105 * (float)v104) + (float)v107;
        v108 = (float *)idMat3::operator*(this: v175, result: &this->orgAxisHands, a: &v147);
        p_orgAxisHands->mat[0].x = *v108;
        this->orgAxisHands.mat[0].y = v108[1];
        this->orgAxisHands.mat[0].z = v108[2];
        v43->x = v108[3];
        this->orgAxisHands.mat[1].y = v108[4];
        this->orgAxisHands.mat[1].z = v108[5];
        v44->x = v108[6];
        this->orgAxisHands.mat[2].y = v108[7];
        this->orgAxisHands.mat[2].z = v108[8];
      }
      idFirstPersonEvent::GetAnimTotalMovement(
        this,
        ta: v98,
        animHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v144.value,
        startOrigin: &this->orgPosHands,
        startAxis: (idQuat *)&this->orgAxisHands,
        origin: &this->nextPosHands,
        axis: &this->nextRotHands,
        a8: v99,
        a9: v135,
        a10: v136,
        a11: v137,
        a12: v138,
        a13: v139,
        a14: v140,
        a15: v141,
        a16: v142);
    }
  }
  if ( v145 == 0 || (*((_BYTE *)this + 1092) & 0x40) != 0 )
  {
    attachMode = this->attachMode;
    if ( attachMode == ATTACHMODE_LEGS )
    {
      p_playerEndPos->x = this->nextPosLegs.x;
      this->playerEndPos.y = this->nextPosLegs.y;
      this->playerEndPos.z = this->nextPosLegs.z;
      p_playerEndRot->mat[0].x = this->nextRotLegs.mat[0].x;
      this->playerEndRot.mat[0].y = this->nextRotLegs.mat[0].y;
      this->playerEndRot.mat[0].z = this->nextRotLegs.mat[0].z;
      v45->x = this->nextRotLegs.mat[1].x;
      this->playerEndRot.mat[1].y = this->nextRotLegs.mat[1].y;
      this->playerEndRot.mat[1].z = this->nextRotLegs.mat[1].z;
      v46->x = this->nextRotLegs.mat[2].x;
      this->playerEndRot.mat[2].y = this->nextRotLegs.mat[2].y;
      v110 = this->nextRotLegs.mat[2].z;
LABEL_75:
      this->playerEndRot.mat[2].z = v110;
      goto LABEL_76;
    }
    if ( attachMode == ATTACHMODE_HANDS )
    {
      p_playerEndPos->x = this->nextPosHands.x;
      this->playerEndPos.y = this->nextPosHands.y;
      this->playerEndPos.z = this->nextPosHands.z;
      p_playerEndRot->mat[0].x = this->nextRotHands.mat[0].x;
      this->playerEndRot.mat[0].y = this->nextRotHands.mat[0].y;
      this->playerEndRot.mat[0].z = this->nextRotHands.mat[0].z;
      v45->x = this->nextRotHands.mat[1].x;
      this->playerEndRot.mat[1].y = this->nextRotHands.mat[1].y;
      this->playerEndRot.mat[1].z = this->nextRotHands.mat[1].z;
      v46->x = this->nextRotHands.mat[2].x;
      this->playerEndRot.mat[2].y = this->nextRotHands.mat[2].y;
      v110 = this->nextRotHands.mat[2].z;
      goto LABEL_75;
    }
  }
LABEL_76:
  if ( thirdPersonLegs != nullptr && v143.value != 0xFFFF )
  {
    idAlignedEntity::PlayAnim(
      this: thirdPersonLegs,
      aliasHandle: &v143,
      loop: false,
      durationMS: -1,
      _blendParms: nullptr,
      rateScale: 1.0);
    if ( idEntity::IsBound(this: thirdPersonLegs) )
    {
      v111 = idEntity::GetPhysics(this: thirdPersonLegs);
      v111->SetLocalOrigin(this: v111, a2: &this->orgPosLegs, a3: -1);
      v112 = idEntity::GetPhysics(this: thirdPersonLegs);
      v112->SetLocalAxis(this: v112, a2: &this->orgAxisLegs, a3: -1);
    }
    else
    {
      v113 = idEntity::GetPhysics(this: thirdPersonLegs);
      v113->SetOrigin(this: v113, a2: &this->orgPosLegs, a3: -1);
      v114 = idEntity::GetPhysics(this: thirdPersonLegs);
      v114->SetAxis(this: v114, a2: &this->orgAxisLegs, a3: -1);
    }
  }
  if ( thirdPersonHands != nullptr && v144.value != 0xFFFF )
  {
    idAlignedEntity::PlayAnim(
      this: thirdPersonHands,
      aliasHandle: &v144,
      loop: false,
      durationMS: -1,
      _blendParms: nullptr,
      rateScale: 1.0);
    if ( idEntity::IsBound(this: thirdPersonHands) )
    {
      v115 = idEntity::GetPhysics(this: thirdPersonHands);
      v115->SetLocalOrigin(this: v115, a2: &this->orgPosHands, a3: -1);
      v116 = idEntity::GetPhysics(this: thirdPersonHands);
      v116->SetLocalAxis(this: v116, a2: &this->orgAxisHands, a3: -1);
    }
    else
    {
      v117 = idEntity::GetPhysics(this: thirdPersonHands);
      v117->SetOrigin(this: v117, a2: &this->orgPosHands, a3: -1);
      v118 = idEntity::GetPhysics(this: thirdPersonHands);
      v118->SetAxis(this: v118, a2: &this->orgAxisHands, a3: -1);
    }
  }
  if ( thirdPersonLegs == nullptr || this->attachMode != ATTACHMODE_LEGS )
  {
    if ( thirdPersonHands == nullptr || this->attachMode != ATTACHMODE_HANDS )
      goto LABEL_93;
    idAlignedEntity::ForceNonDeferredAnimationUpdate(this: thirdPersonHands);
    v119 = thirdPersonHands;
  }
  else
  {
    idAlignedEntity::ForceNonDeferredAnimationUpdate(this: thirdPersonLegs);
    v119 = thirdPersonLegs;
  }
  idAlignedEntity::AttachCamera(
    this: v119,
    jointName: this->cameraJoint.data,
    durationMode: DURATION_ALWAYS,
    lookMode: LOOK_HEADING,
    blendMode: BLEND_SMOOTH_SNAP_SMOOTH,
    blendDurationMS: this->blendInTime,
    viewConeDeg: 0.0,
    autoCenterK: 1.0);
LABEL_93:
  v120 = v149;
  springCamera = v149->springCamera;
  if ( springCamera != nullptr )
  {
    if ( this->fovUserChannel.len != 0 )
      idSpringCamera::SetUserChannelFov(this: v149->springCamera, userChannelName: this->fovUserChannel.data);
    springCamera->calculateViewInDraw = true;
  }
  v122 = v120->presentable;
  if ( v122 != nullptr )
    v123 = (int)v122->GetPlayerInterface_2(this: v122);
  else
    v123 = 0;
  this->playerShowFlags = (*(_BYTE *)(v123 + 40606) != 0) | 0x40;
  v124 = v120->presentable;
  if ( v124 != nullptr )
    v125 = (int)v124->GetPlayerInterface_2(this: v124);
  else
    v125 = 0;
  idHands::Hide(this: (idHands *)(v125 + 37616), hideReason: HAND_HIDE_FIRSTPERSONEVENT);
  v126 = v120->presentable;
  if ( v126 != nullptr )
    v127 = (int)v126->GetPlayerInterface_2(this: v126);
  else
    v127 = 0;
  this->playerSavedInhibitFlags = *(_DWORD *)(v127 + 46528);
  v128 = v120->presentable;
  if ( v128 != nullptr )
    v129 = v128->GetPlayerInterface_2(this: v128);
  else
    v129 = nullptr;
  idPresentablePlayer::SetInhibitFlags(this: v129, flags: UCMD_INHIBIT_MOVEMENT);
  v130 = 0;
  if ( this->triggerEnter.num > 0 )
  {
    v131 = 0;
    do
    {
      v132 = this->triggerEnter.list[v131].spawnId.value;
      if ( gameLocal->spawnIds.ptr[v132 & 0x1FFF] == v132 >> 13 )
      {
        v133 = gameLocal->entities.ptr[v132 & 0x1FFF];
        if ( v133 != nullptr )
        {
          v134 = idEntity::CastTo(c: v133);
          if ( v134 != nullptr )
            idEntity::Activate(this: v134, activator: v120);
        }
      }
      ++v130;
      ++v131;
    }
    while ( v130 < this->triggerEnter.num );
  }
}


// ========================================================================
// ?SetCurrentState@idFirstPersonEvent@@QAAXW4changeType_t@idTarget_ChangeAnimState@@H@Z
// EA  : 0x82C4EBC8
// RVA : 0x00C4EBC8
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonEvent::SetCurrentState(idFirstPersonEvent *this, unsigned int changeType, int nextState)
{
  int curExtraAnimation; // r11
  int num; // r31
  int v7; // r3
  int v8; // r11

  if ( changeType <= 4 )
  {
    switch ( changeType )
    {
      case 1u:
        curExtraAnimation = this->curExtraAnimation;
        nextState = curExtraAnimation - 1;
        if ( curExtraAnimation <= 0 )
          nextState = 0;
        break;
      case 2u:
LABEL_18:
        break;
      case 3u:
        num = this->extraAnimations.num;
        v7 = idRandom2::RandomInt(this: &clientGame->random, max: num);
        v8 = this->curExtraAnimation;
        nextState = v7;
        if ( v8 != -1 && v8 == v7 )
        {
          __twllei(num, 0);
          nextState = (v7 + 1) % num;
          __twlgei(num & ~(__ROL4__(v7 + 1, 1) - 1), 0xFFFFFFFF);
        }
        break;
      default:
        if ( changeType != 0 )
          nextState = -1;
        else
          nextState = this->curExtraAnimation + 1;
        goto LABEL_18;
    }
    idFirstPersonEvent::SetCurrentState(this, nextState);
  }
}


// ========================================================================
// ?Think@idFirstPersonPickup@@UAAXXZ
// EA  : 0x82C4ECA8
// RVA : 0x00C4ECA8
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonPickup::Think(idFirstPersonPickup *this)
{
  idFirstPersonPickup::pickupState_t pickupState; // r11
  idGameLocal *v3; // r11
  int value; // r9
  idPlayer *v5; // r3
  idPlayer *v6; // r3
  idPlayer *v7; // r31
  idEntity *v8; // r3
  idPhysics *Physics; // r27
  idEntity *v10; // r3
  idPhysics *v11; // r3
  int v12; // r26
  idPlayer_vtbl *v13; // r30
  idAngles *v14; // r3
  idAngles *v15; // r3
  bool v16; // r30
  idPhysics_Player *PhysicsObj; // r3
  int v18; // r30
  int BobCycle; // r3
  idPresentable *presentable; // r3
  idUCmdInhibit::inhibitFlags_t playerSavedInhibitFlags; // r31
  idPresentablePlayer *v22; // r3
  int v23; // r9
  idAlignedEntity *v24; // r3
  idAlignedEntity *v25; // r3
  idAlignedEntity *v26; // r30
  int v27; // r9
  idAlignedEntity *v28; // r3
  idAlignedEntity *v29; // r31
  idEntity *v30; // r3
  idAlignedEntity *HandsEntity; // r3
  idAlignedEntity *v32; // r31
  idPresentable *v33; // r11
  int v34; // r9
  idAlignedEntity *v35; // r3
  idAlignedEntity *v36; // r3
  idMat3 v37[2]; // [sp+50h] [-50h] BYREF

  if ( (unsigned __int8)idFirstPersonEvent::UpdateAnimation(this) != 0 )
  {
    pickupState = this->pickupState;
    if ( pickupState == PICKUPSTATE_PICKUP )
    {
      this->pickupState = PICKUPSTATE_WALKING;
      v3 = gameLocal;
      value = this->playerActivator.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v5 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v5 != nullptr )
        {
          v6 = idPlayer::CastTo(c: v5);
          v3 = gameLocal;
          v7 = v6;
          if ( v6 != nullptr )
          {
            if ( gameLocal->spawnIds.ptr[this->pickupEndPosition.spawnId.value & 0x1FFF] == this->pickupEndPosition.spawnId.value >> 13 )
            {
              v8 = idEntityPtr<idEntity const>::operator->(this: &this->pickupEndPosition);
              Physics = idEntity::GetPhysics(this: v8);
              v10 = idEntityPtr<idEntity const>::operator->(this: &this->pickupEndPosition);
              v11 = idEntity::GetPhysics(this: v10);
              v12 = (int)v11->GetOrigin(this: v11, a2: 0);
              v13 = v7->__vftable;
              v14 = (idAngles *)Physics->GetAxis(this: Physics, a2: 0);
              v15 = idMat3::ToAngles(this: v37, result: v14);
              v13->Teleport(this: v7, a2: (const idVec3 *)v12, a3: v15);
            }
            v16 = (*((_BYTE *)&this->idFirstPersonEvent + 1092) & 0x10) != 0;
            PhysicsObj = idPlayer::GetPhysicsObj(this: v7);
            idPhysics_Player::SetCrouch(this: PhysicsObj, crouch: v16);
            v18 = (*((_BYTE *)&this->idFirstPersonEvent + 1092) & 0x10) != 0;
            BobCycle = idPlayer::GetBobCycle(this: v7);
            *(_BYTE *)(BobCycle + 217) = *(unsigned __int8 *)(BobCycle + 216) != v18;
            presentable = v7->presentable;
            playerSavedInhibitFlags = this->playerSavedInhibitFlags;
            if ( presentable != nullptr )
              v22 = presentable->GetPlayerInterface_2(this: presentable);
            else
              v22 = nullptr;
            idPresentablePlayer::SetInhibitFlags(this: v22, flags: playerSavedInhibitFlags);
            v3 = gameLocal;
          }
        }
      }
      v23 = this->legsEntity.spawnId.value;
      if ( v3->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13
        && (v24 = (idAlignedEntity *)v3->entities.ptr[v23 & 0x1FFF]) != nullptr )
      {
        v25 = idAlignedEntity::CastTo(c: v24);
        v3 = gameLocal;
        v26 = v25;
      }
      else
      {
        v26 = nullptr;
      }
      v27 = this->handsEntity.spawnId.value;
      if ( v3->spawnIds.ptr[v27 & 0x1FFF] == v27 >> 13
        && (v28 = (idAlignedEntity *)v3->entities.ptr[v27 & 0x1FFF]) != nullptr )
      {
        v29 = idAlignedEntity::CastTo(c: v28);
      }
      else
      {
        v29 = nullptr;
      }
      if ( v26 == nullptr || this->attachMode != ATTACHMODE_LEGS )
      {
        if ( v29 != nullptr && this->attachMode == ATTACHMODE_HANDS )
        {
          idAlignedEntity::AttachToOwner(this: v29, blendTime: 0);
          idAlignedEntity::UpdateOwnerFromCamera(
            this: v29,
            updatePosition: true,
            updateOrientation: true,
            updateVelocityFromPhysics: true,
            updateVelocityFromCamera: false,
            clipMove: true);
          idAlignedEntity::DetachCamera(this: v29, instantBlend: false);
        }
      }
      else
      {
        idAlignedEntity::AttachToOwner(this: v26, blendTime: 0);
        idAlignedEntity::UpdateOwnerFromCamera(
          this: v26,
          updatePosition: true,
          updateOrientation: true,
          updateVelocityFromPhysics: true,
          updateVelocityFromCamera: false,
          clipMove: true);
        idAlignedEntity::DetachCamera(this: v26, instantBlend: false);
      }
    }
    else if ( pickupState == PICKUPSTATE_PUTDOWN )
    {
      v30 = idEntityPtr<idEntity const>::operator->(this: &this->putdownItem);
      v30->Show(this: v30);
      HandsEntity = idFirstPersonEvent::GetHandsEntity(this);
      v32 = HandsEntity;
      if ( HandsEntity != nullptr )
      {
        v33 = HandsEntity->presentable;
        if ( v33 == nullptr )
        {
          idEntity::InitPresentableInternal(this: HandsEntity);
          v33 = v32->presentable;
        }
        *((_BYTE *)&v33->model->g + 105) &= ~0x80u;
      }
    }
  }
  if ( this->eventEndTime != -1
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->blendOutTime
                                                                                                + this->eventEndTime )
  {
    this->pickupState = PICKUPSTATE_NONE;
    v34 = this->handsEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v34 & 0x1FFF] == v34 >> 13 )
    {
      v35 = (idAlignedEntity *)gameLocal->entities.ptr[v34 & 0x1FFF];
      if ( v35 != nullptr )
      {
        v36 = idAlignedEntity::CastTo(c: v35);
        if ( v36 != nullptr )
          idAlignedEntity::SetManualUpdateCamera(this: v36, _updateCamera: false);
      }
    }
    idFirstPersonEvent::EndEvent(this);
  }
}


// ========================================================================
// ?OnActivate@idFirstPersonPickup@@UAAXPAVidEntity@@@Z
// EA  : 0x82C4F050
// RVA : 0x00C4F050
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonPickup::OnActivate(idFirstPersonPickup *this, idUseFirstPersonEvent *activator)
{
  idUseFirstPersonEvent *v4; // r3
  int additionalPickupState; // r11
  idFirstPersonEvent::animEntry_t *list; // r8
  idFirstPersonEvent::attachMode_t attachMode; // r11
  idFirstPersonPickup::additionalPickup_t *v8; // r29
  idAlignedEntity *v9; // r30
  int animState; // r9
  unsigned __int16 *p_value; // r10
  idAlignedEntity *LegsEntity; // r3
  idProp_Moveable *v13; // r26
  idPlayer *PlayerActivator; // r3
  idPlayer *v15; // r27
  idProp_Moveable *v16; // r3
  idProp_Moveable *v17; // r28
  idPresentable *presentable; // r3
  idPresentablePlayer *v19; // r3
  const idQuat *v20; // r3
  idFirstPersonPickup::pickupState_t pickupState; // r11
  int value; // r9
  idGameLocal *v23; // r11
  idPlayer *v24; // r3
  idPlayer *v25; // r3
  idPlayer *v26; // r29
  int v27; // r9
  idEntity *v28; // r3
  idEntity *v29; // r3
  int endAnimState; // r11
  idFirstPersonEvent::animEntry_t *v31; // r9
  idFirstPersonEvent::attachMode_t v32; // r10
  unsigned __int16 *v33; // r11
  idAlignedEntity *v34; // r30
  idAlignedEntity *HandsEntity; // r3
  idPresentable *v36; // r3
  idPresentablePlayer *v37; // r3
  idPresentable *v38; // r3
  idPresentablePlayer *v39; // r3
  const idQuat *v40; // r3
  int v41; // r9
  idGameLocal *v42; // r11
  idAlignedEntity *v43; // r3
  idAlignedEntity *v44; // r3
  idAlignedEntity *v45; // r29
  int v46; // r9
  idEntity *v47; // r3
  idEntity *v48; // r3
  idProp_Moveable *v49; // r27
  int v50; // r9
  idPlayer *v51; // r3
  idPlayer *v52; // r3
  idPlayer *v53; // r28
  idPresentable *v54; // r11
  idProp_Moveable *v55; // r3
  idProp_Moveable *v56; // r30
  int v57; // r9
  idAlignedEntity *v58; // r3
  idAlignedEntity *v59; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v60; // [sp+50h] [-D0h] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v61; // [sp+52h] [-CEh] BYREF
  idVec3 v62; // [sp+58h] [-C8h] BYREF
  idVec3 v63[2]; // [sp+68h] [-B8h] BYREF
  idMat3 v64; // [sp+80h] [-A0h] BYREF

  v4 = idUseFirstPersonEvent::CastTo(c: activator);
  if ( v4 == nullptr )
    goto LABEL_21;
  if ( !v4->additionalPickup )
    goto LABEL_21;
  additionalPickupState = v4->additionalPickupState;
  if ( additionalPickupState < 0 || this->additionalPickups.num <= additionalPickupState )
    goto LABEL_21;
  list = this->extraAnimations.list;
  v8 = &this->additionalPickups.list[additionalPickupState];
  attachMode = this->attachMode;
  v9 = nullptr;
  animState = v8->animState;
  v60.value = -1;
  this->pickupState = PICKUPSTATE_PICKUP;
  this->curExtraAnimation = animState;
  p_value = &list[animState].legsAnimationHandle.value;
  if ( attachMode == ATTACHMODE_LEGS )
  {
    v60.value = *p_value;
    LegsEntity = idFirstPersonEvent::GetLegsEntity(this);
LABEL_9:
    v9 = LegsEntity;
    goto LABEL_10;
  }
  if ( attachMode == ATTACHMODE_HANDS )
  {
    v60.value = p_value[1];
    LegsEntity = idFirstPersonEvent::GetHandsEntity(this);
    goto LABEL_9;
  }
LABEL_10:
  v13 = (idProp_Moveable *)idEntityPtr<idEntity const>::operator->(this: &v8->pickupItem);
  PlayerActivator = idFirstPersonEvent::GetPlayerActivator(this);
  v15 = PlayerActivator;
  if ( v9 != nullptr && v13 != nullptr && PlayerActivator != nullptr )
  {
    idAlignedEntity::PlayAnim(
      this: v9,
      aliasHandle: &v60,
      loop: false,
      durationMS: -1,
      _blendParms: nullptr,
      rateScale: 1.0);
    v9->SetOrigin(this: v9, a2: &v8->startOrigin);
    v9->SetAxis(this: v9, a2: &v8->startAxis);
    v16 = idProp_Moveable::CastTo(c: v13);
    v17 = v16;
    if ( v16 != nullptr )
    {
      idAlignedEntity::AttachItem(
        this: v9,
        decl: v16->inventoryDecl,
        slotName: v8->attachTag.data,
        autoDetach: false,
        autoGive: false,
        noClone: false);
      if ( v8->giveItemToPlayer )
        idPlayer::PickupItem(this: v15, prop: v17);
    }
    presentable = v15->presentable;
    if ( presentable != nullptr )
      v19 = presentable->GetPlayerInterface_2(this: presentable);
    else
      v19 = nullptr;
    idPresentablePlayer::GetViewTransform(this: v19, origin: &v62, axis: (idMat3 *)&v64.mat[1].y);
    v20 = idMat3::ToQuat(this: &v64, result: (idQuat *)&v64.mat[1].y);
    idAlignedEntity::DetachFromOwner(this: v9, blendTime: this->attachToPlayerBlend, fromPosition: &v62, fromQuat: v20);
    idAlignedEntity::SetManualUpdateCamera(this: v9, _updateCamera: true);
    idAlignedEntity::AttachCamera(
      this: v9,
      jointName: this->cameraJoint.data,
      durationMode: DURATION_ALWAYS,
      lookMode: LOOK_HEADING,
      blendMode: BLEND_SNAP,
      blendDurationMS: 0,
      viewConeDeg: 0.0,
      autoCenterK: 1.0);
    if ( v8->removePickupItem )
    {
      v13->Hide(this: v13, a2: true);
      idEventReceiver::PostEventMS(this: v13, ev: &EV_Remove, time: 0);
    }
  }
LABEL_21:
  pickupState = this->pickupState;
  if ( pickupState == PICKUPSTATE_WALKING )
  {
    this->pickupState = PICKUPSTATE_PUTDOWN;
    value = this->playerActivator.spawnId.value;
    v23 = gameLocal;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v24 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v25 = idPlayer::CastTo(c: v24);
      v23 = gameLocal;
      v26 = v25;
    }
    else
    {
      v26 = nullptr;
    }
    v27 = this->putdownItem.spawnId.value;
    if ( v23->spawnIds.ptr[v27 & 0x1FFF] == v27 >> 13 && (v28 = v23->entities.ptr[v27 & 0x1FFF]) != nullptr )
      v29 = idEntity::CastTo(c: v28);
    else
      v29 = nullptr;
    endAnimState = this->endAnimState;
    if ( endAnimState != -1 && v29 != nullptr && v26 != nullptr )
    {
      v31 = this->extraAnimations.list;
      v32 = this->attachMode;
      this->curExtraAnimation = endAnimState;
      v61.value = -1;
      v33 = &v31[endAnimState].legsAnimationHandle.value;
      v34 = nullptr;
      if ( v32 != ATTACHMODE_LEGS )
      {
        if ( v32 != ATTACHMODE_HANDS )
          goto LABEL_38;
        v61.value = v33[1];
        HandsEntity = idFirstPersonEvent::GetHandsEntity(this);
      }
      else
      {
        v61.value = *v33;
        HandsEntity = idFirstPersonEvent::GetLegsEntity(this);
      }
      v34 = HandsEntity;
LABEL_38:
      v36 = v26->presentable;
      if ( v36 != nullptr )
        v37 = v36->GetPlayerInterface_2(this: v36);
      else
        v37 = nullptr;
      idPresentablePlayer::SetInhibitFlags(this: v37, flags: UCMD_INHIBIT_MOVEMENT);
      if ( v34 != nullptr )
      {
        idAlignedEntity::PlayAnim(
          this: v34,
          aliasHandle: &v61,
          loop: false,
          durationMS: -1,
          _blendParms: nullptr,
          rateScale: 1.0);
        v34->SetOrigin(this: v34, a2: &this->endOrigin);
        v34->SetAxis(this: v34, a2: &this->endAxis);
        v38 = v26->presentable;
        if ( v38 != nullptr )
          v39 = v38->GetPlayerInterface_2(this: v38);
        else
          v39 = nullptr;
        idPresentablePlayer::GetViewTransform(this: v39, origin: v63, axis: (idMat3 *)&v64.mat[1].y);
        v40 = idMat3::ToQuat(this: &v64, result: (idQuat *)&v64.mat[1].y);
        idAlignedEntity::DetachFromOwner(
          this: v34,
          blendTime: this->attachToPlayerBlend,
          fromPosition: v63,
          fromQuat: v40);
        idAlignedEntity::SetManualUpdateCamera(this: v34, _updateCamera: true);
        idAlignedEntity::AttachCamera(
          this: v34,
          jointName: this->cameraJoint.data,
          durationMode: DURATION_ALWAYS,
          lookMode: LOOK_HEADING,
          blendMode: BLEND_SNAP,
          blendDurationMS: 0,
          viewConeDeg: 0.0,
          autoCenterK: 1.0);
      }
    }
  }
  else if ( pickupState == PICKUPSTATE_NONE )
  {
    idFirstPersonEvent::OnActivate(this, (idPlayer *)activator);
    this->pickupState = PICKUPSTATE_PICKUP;
    this->applyMovement = false;
    v41 = this->handsEntity.spawnId.value;
    v42 = gameLocal;
    if ( gameLocal->spawnIds.ptr[v41 & 0x1FFF] == v41 >> 13
      && (v43 = (idAlignedEntity *)gameLocal->entities.ptr[v41 & 0x1FFF]) != nullptr )
    {
      v44 = idAlignedEntity::CastTo(c: v43);
      v42 = gameLocal;
      v45 = v44;
    }
    else
    {
      v45 = nullptr;
    }
    v46 = this->pickupItem.spawnId.value;
    if ( v42->spawnIds.ptr[v46 & 0x1FFF] == v46 >> 13 && (v47 = v42->entities.ptr[v46 & 0x1FFF]) != nullptr )
    {
      v48 = idEntity::CastTo(c: v47);
      v42 = gameLocal;
      v49 = (idProp_Moveable *)v48;
    }
    else
    {
      v49 = nullptr;
    }
    v50 = this->playerActivator.spawnId.value;
    if ( v42->spawnIds.ptr[v50 & 0x1FFF] == v50 >> 13 && (v51 = (idPlayer *)v42->entities.ptr[v50 & 0x1FFF]) != nullptr )
    {
      v52 = idPlayer::CastTo(c: v51);
      v42 = gameLocal;
      v53 = v52;
    }
    else
    {
      v53 = nullptr;
    }
    if ( v45 != nullptr && v49 != nullptr && v53 != nullptr )
    {
      v45->SetOrigin(this: v45, a2: &this->startOrigin);
      v45->SetAxis(this: v45, a2: &this->startAxis);
      v54 = v45->presentable;
      if ( v54 == nullptr )
      {
        idEntity::InitPresentableInternal(this: v45);
        v54 = v45->presentable;
      }
      *((_BYTE *)&v54->model->g + 105) &= ~0x80u;
      v55 = idProp_Moveable::CastTo(c: v49);
      v56 = v55;
      if ( v55 != nullptr )
      {
        idAlignedEntity::AttachItem(
          this: v45,
          decl: v55->inventoryDecl,
          slotName: this->attachTag.data,
          autoDetach: false,
          autoGive: false,
          noClone: false);
        if ( this->giveItemToPlayer )
          idPlayer::PickupItem(this: v53, prop: v56);
      }
      v45->okToShow = true;
      if ( this->removePickupItem )
      {
        v49->Hide(this: v49, a2: true);
        idEventReceiver::PostEventMS(this: v49, ev: &EV_Remove, time: 0);
      }
      v42 = gameLocal;
    }
    v57 = this->legsEntity.spawnId.value;
    if ( v42->spawnIds.ptr[v57 & 0x1FFF] == v57 >> 13 )
    {
      v58 = (idAlignedEntity *)v42->entities.ptr[v57 & 0x1FFF];
      if ( v58 != nullptr )
      {
        v59 = idAlignedEntity::CastTo(c: v58);
        if ( v59 != nullptr )
          v59->okToShow = true;
      }
    }
  }
}


// ========================================================================
// ?Think@idFirstPersonEvent@@UAAXXZ
// EA  : 0x82C4F710
// RVA : 0x00C4F710
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void __fastcall idFirstPersonEvent::Think(idFirstPersonEvent *this)
{
  idGameLocal *v2; // r11

  if ( this->eventStartTime == -1 )
  {
    idEntity::BecomeInactive(this, flags: 1);
  }
  else
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->blendInTime + this->eventStartTime )
    {
      v2 = gameLocal;
      if ( gameLocal->spawnIds.ptr[this->legsEntity.spawnId.value & 0x1FFF] == this->legsEntity.spawnId.value >> 13 )
      {
        idEntityPtr<idAlignedEntity>::GetEntity(this: &this->legsEntity)->okToShow = true;
        v2 = gameLocal;
      }
      if ( v2->spawnIds.ptr[this->handsEntity.spawnId.value & 0x1FFF] == this->handsEntity.spawnId.value >> 13 )
        idEntityPtr<idAlignedEntity>::GetEntity(this: &this->handsEntity)->okToShow = true;
    }
    if ( this->eventEndTime != -1
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->blendOutTime + this->eventEndTime
      || (idFirstPersonEvent::UpdateAnimation(this), this->eventEndTime != -1) && this->blendOutTime == 0 )
    {
      idFirstPersonEvent::EndEvent(this);
    }
  }
}


// ========================================================================
// ??0idFirstPersonEvent@@QAA@XZ
// EA  : 0x82C4F908
// RVA : 0x00C4F908
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

idFirstPersonEvent *__fastcall idFirstPersonEvent::idFirstPersonEvent(idFirstPersonEvent *this)
{
  float *p_z; // r7
  float *p_y; // r8
  char v4; // r27
  float z; // r4
  int v6; // ctr
  float *v7; // r8
  float *v8; // r9
  int i; // ctr
  float *v10; // r8
  float *v11; // r9
  int j; // ctr
  float *v13; // r8
  float *v14; // r9
  int k; // ctr
  float *v16; // r11
  float *v17; // r9
  int v18; // ctr

  idEntity::idEntity(this);
  this->__vftable = (idFirstPersonEvent_vtbl *)&idFirstPersonEvent::`vftable';
  this->fpBindinfo.bindParent.spawnId.value = 0x1FFF;
  this->fpBindinfo.bindOffset = ang_zero;
  this->fpBindinfo.bindToJoint.allocedAndFlag = 20;
  this->fpBindinfo.bindToJoint.data = this->fpBindinfo.bindToJoint.baseBuffer;
  this->fpBindinfo.bindToJoint.len = 0;
  this->fpBindinfo.bindToJoint.baseBuffer[0] = 0;
  this->fpBindinfo.bindToTag.allocedAndFlag = 20;
  this->fpBindinfo.bindToTag.data = this->fpBindinfo.bindToTag.baseBuffer;
  this->fpBindinfo.bindToTag.len = 0;
  this->fpBindinfo.bindToTag.baseBuffer[0] = 0;
  this->extraAnimations.granularity = 0;
  this->extraAnimations.memTag = 5;
  this->extraAnimations.listStatic = 0;
  this->extraAnimations.list = nullptr;
  this->extraAnimations.size = 0;
  this->extraAnimations.num = 0;
  this->legsAnimation.allocedAndFlag = 20;
  this->legsAnimation.len = 0;
  this->legsAnimation.data = this->legsAnimation.baseBuffer;
  this->legsAnimation.baseBuffer[0] = 0;
  this->handsAnimation.allocedAndFlag = 20;
  this->handsAnimation.len = 0;
  this->handsAnimation.data = this->handsAnimation.baseBuffer;
  this->handsAnimation.baseBuffer[0] = 0;
  this->perfectOriginRef.spawnId.value = 0x1FFF;
  this->perfectDestinationRef.spawnId.value = 0x1FFF;
  this->triggerEnter.list = nullptr;
  this->triggerEnter.granularity = 0;
  this->triggerEnter.memTag = 5;
  this->triggerEnter.listStatic = 0;
  this->triggerEnter.size = 0;
  this->triggerEnter.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggerEnter);
  this->triggerLeave.list = nullptr;
  this->triggerLeave.granularity = 0;
  this->triggerLeave.memTag = 5;
  this->triggerLeave.listStatic = 0;
  this->triggerLeave.size = 0;
  this->triggerLeave.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggerLeave);
  idStr::idStr(this: &this->cameraJoint, text: "camera");
  this->fovUserChannel.allocedAndFlag = 20;
  this->fovUserChannel.len = 0;
  this->fovUserChannel.data = this->fovUserChannel.baseBuffer;
  this->fovUserChannel.baseBuffer[0] = 0;
  p_z = &this->orgPosLegs.z;
  p_y = &mat2_identity.mat[1].y;
  this->playerEndOffset.x = vec3_origin.x;
  v4 = *((_BYTE *)this + 1092);
  this->playerEndOffset.y = vec3_origin.y;
  z = vec3_origin.z;
  this->blendInTime = 500;
  this->blendOutTime = 500;
  this->playerEndOffset.z = z;
  this->attachMode = ATTACHMODE_LEGS;
  v6 = 9;
  this->cameraBlendOutTime = -1;
  *((_BYTE *)this + 1092) = v4 & 7 | 0x40;
  this->legsEntity.spawnId.value = 0x1FFF;
  this->handsEntity.spawnId.value = 0x1FFF;
  this->playerActivator.spawnId.value = 0x1FFF;
  this->orgPosLegs = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v6;
  }
  while ( v6 != 0 );
  v7 = &this->orgPosHands.z;
  v8 = &mat2_identity.mat[1].y;
  this->orgPosHands = vec3_origin;
  for ( i = 9; i != 0; --i )
    *++v7 = *++v8;
  v10 = &this->nextPosLegs.z;
  v11 = &mat2_identity.mat[1].y;
  this->nextPosLegs = vec3_origin;
  for ( j = 9; j != 0; --j )
    *++v10 = *++v11;
  v13 = &this->nextPosHands.z;
  v14 = &mat2_identity.mat[1].y;
  this->nextPosHands = vec3_origin;
  for ( k = 9; k != 0; --k )
    *++v13 = *++v14;
  v17 = &this->playerEndPos.z;
  v18 = 9;
  this->playerEndPos = vec3_origin;
  v16 = &mat2_identity.mat[1].y;
  do
  {
    *++v17 = *++v16;
    --v18;
  }
  while ( v18 != 0 );
  this->legsAnimationHandle.value = -1;
  this->handsAnimationHandle.value = -1;
  this->externalTime = 0.0;
  this->animStartFrame = -1;
  this->eventStartTime = -1;
  this->eventEndTime = -1;
  this->curExtraAnimation = -1;
  this->playerShowFlags = HAND_HIDE_FIRSTPERSONEVENT;
  this->playerSavedInhibitFlags = UCMD_INHIBIT_NONE;
  this->removeOriginTransformLegs = true;
  this->removeOriginTransformHands = true;
  this->applyMovement = false;
  return this;
}


// ========================================================================
// __unwind$496326
// EA  : 0x82C4FC58
// RVA : 0x00C4FC58
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void _unwind_496326()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$496327
// EA  : 0x82C4FC80
// RVA : 0x00C4FC80
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void _unwind_496327()
{
  int v0; // r12

  idFirstPersonEvent::bindInfo_t::~bindInfo_t(this: (idFirstPersonEvent::bindInfo_t *)(*(_DWORD *)(v0 - 144 + 164) + 800));
}


// ========================================================================
// __unwind$496328
// EA  : 0x82C4FCAC
// RVA : 0x00C4FCAC
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void _unwind_496328()
{
  int v0; // r12

  idList<idFirstPersonEvent::animEntry_t,5>::~idList<idFirstPersonEvent::animEntry_t,5>(this: (idList<idFirstPersonEvent::animEntry_t,5> *)(*(_DWORD *)(v0 - 144 + 164) + 880));
}


// ========================================================================
// __unwind$496329
// EA  : 0x82C4FCD8
// RVA : 0x00C4FCD8
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void _unwind_496329()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 896));
}


// ========================================================================
// __unwind$496330
// EA  : 0x82C4FD04
// RVA : 0x00C4FD04
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void _unwind_496330()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 928));
}


// ========================================================================
// __unwind$496331
// EA  : 0x82C4FD30
// RVA : 0x00C4FD30
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void _unwind_496331()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 968));
}


// ========================================================================
// __unwind$496332
// EA  : 0x82C4FD5C
// RVA : 0x00C4FD5C
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void _unwind_496332()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 984));
}


// ========================================================================
// ??0idFirstPersonPickup@@QAA@XZ
// EA  : 0x82C4FF90
// RVA : 0x00C4FF90
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

idFirstPersonPickup *__fastcall idFirstPersonPickup::idFirstPersonPickup(idFirstPersonPickup *this)
{
  int v2; // ctr
  float *p_z; // r7
  float *p_y; // r8
  float *v5; // r9
  float *v6; // r10
  int v7; // ctr

  idFirstPersonEvent::idFirstPersonEvent(this);
  this->__vftable = (idFirstPersonPickup_vtbl *)&idFirstPersonPickup::`vftable';
  this->additionalPickups.memTag = 5;
  this->additionalPickups.granularity = 0;
  this->additionalPickups.listStatic = 0;
  this->additionalPickups.list = nullptr;
  this->additionalPickups.size = 0;
  this->additionalPickups.num = 0;
  this->pickupItem.spawnId.value = 0x1FFF;
  this->putdownItem.spawnId.value = 0x1FFF;
  this->pickupEndPosition.spawnId.value = 0x1FFF;
  this->attachTag.data = this->attachTag.baseBuffer;
  this->attachTag.allocedAndFlag = 20;
  this->attachTag.len = 0;
  this->attachTag.baseBuffer[0] = 0;
  this->alignedJoint.data = this->alignedJoint.baseBuffer;
  this->alignedJoint.allocedAndFlag = 20;
  this->alignedJoint.len = 0;
  this->alignedJoint.baseBuffer[0] = 0;
  this->endAnimState = -1;
  this->removePickupItem = true;
  v2 = 9;
  this->attachToPlayerBlend = 500;
  p_z = &this->startOrigin.z;
  this->giveItemToPlayer = false;
  p_y = &mat2_identity.mat[1].y;
  this->startOrigin = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  v6 = &mat2_identity.mat[1].y;
  v7 = 9;
  this->endOrigin = vec3_origin;
  v5 = &this->endOrigin.z;
  do
  {
    *++v5 = *++v6;
    --v7;
  }
  while ( v7 != 0 );
  this->pickupState = PICKUPSTATE_NONE;
  return this;
}


// ========================================================================
// __unwind$496813
// EA  : 0x82C500E4
// RVA : 0x00C500E4
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.cpp
// ========================================================================

void _unwind_496813()
{
  int v0; // r12

  idFirstPersonEvent::~idFirstPersonEvent(this: *(idFirstPersonEvent **)(v0 - 128 + 148));
}

