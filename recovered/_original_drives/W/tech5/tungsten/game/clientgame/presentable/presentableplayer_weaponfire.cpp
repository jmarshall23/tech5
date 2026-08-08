
// ========================================================================
// ?RecordClientFire@idPresentablePlayer@@QAAXPBVidWeapon@@PBVidDeclProjectile@@ABVidFireParms@@ABVidTestFireResults@@ABVidFinishFireResults@@@Z
// EA  : 0x82B89CB8
// RVA : 0x00B89CB8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __fastcall idPresentablePlayer::RecordClientFire(
        idPresentablePlayer *this,
        const idWeapon *weapon,
        const idDeclProjectile *projDecl,
        const idFireParms *fp,
        const idTestFireResults *tfr,
        const idFinishFireResults *ffr)
{
  const idWeapon *v7; // r29
  const idTestFireResults *v9; // r27
  int v10; // r14
  float *p_y; // r28
  int v12; // r26
  int v13; // r29
  idPresentable *PresentableByEntityNum; // r3
  idPresentable *v15; // r30
  gameTeam_t team; // r10
  idPresentable *Parent; // r3
  idPresentableAnimatedEntity *v18; // r3
  idTreeAnimator *TreeAnimator; // r27
  idPresentable *v20; // r3
  double v21; // fp10
  double v22; // fp9
  double v23; // fp7
  double v24; // fp6
  int v25; // r11
  double y; // fp13
  double x; // fp12
  int v28; // fp6
  gameTeam_t v29; // [sp+50h] [-400h]
  float v30[4]; // [sp+60h] [-3F0h] BYREF
  idMat3 v31[17]; // [sp+70h] [-3E0h] BYREF
  int v32; // [sp+2D4h] [-17Ch]

  v7 = weapon;
  v9 = tfr;
  if ( !common->IsServer(this: common) )
  {
    if ( v7 != nullptr )
    {
      if ( fp->projDef->hitscan )
      {
        idClientGameMsg_HitScanHit::idClientGameMsg_HitScanHit(
          this: (idClientGameMsg_HitScanHit *)&v31[0].mat[1].y,
          attacker_: this,
          weaponDecl_: (const idDeclWeapon *)v7->decl,
          projDecl_: (const idDeclProjectile *)LODWORD(fp->start.x),
          startPos_: (idVec3 *)LODWORD(fp->start.y));
        v10 = 0;
        if ( v9->numTraces > 0 )
        {
          p_y = &v9->traces[0].endAxis.mat[1].y;
          do
          {
            if ( *((_DWORD *)p_y + 5) != 0 )
            {
              v12 = *((_DWORD *)p_y + 19);
              if ( v12 != 0x1FFF && v12 != 8190 )
              {
                v13 = -1;
                PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(
                                           this: clientGame,
                                           entityNum: *((_DWORD *)p_y + 19));
                v15 = PresentableByEntityNum;
                if ( PresentableByEntityNum != nullptr )
                {
                  team = this->team;
                  if ( team == TEAM_NONE
                    || (v29 = PresentableByEntityNum->team) == TEAM_NONE
                    || team != v29
                    || gc_friendlyFire.valueInteger != 0 )
                  {
                    if ( PresentableByEntityNum->ShouldTriggerClientHitScanHit(this: PresentableByEntityNum) )
                    {
                      if ( p_fire_clientFireDebug.valueInteger > 0 )
                      {
                        idLib::Printf(fmt: "HIT entity %d presentable: %d\n", v12, v15->index);
                        if ( idPresentable::GetParent(this: v15) != nullptr )
                        {
                          Parent = idPresentable::GetParent(this: v15);
                          idLib::Printf(fmt: "HIT entity %d has parent presentable: %d\n", v12, Parent->index);
                        }
                      }
                      if ( v15->GetAnimatedEntityInterface(this: v15) != nullptr )
                      {
                        v18 = v15->GetAnimatedEntityInterface(this: v15);
                        TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v18);
                        v20 = v15->GetAnimatedEntityInterface(this: v15);
                        idPresentable::UpdateModelTransform(this: v20);
                        if ( TreeAnimator != nullptr )
                        {
                          if ( p_fire_clientFireDebug.valueInteger > 0 )
                          {
                            v21 = (float)(*p_y * (float)64.0);
                            v22 = (float)(*(p_y - 1) * (float)64.0);
                            v23 = *(p_y - 6);
                            v24 = *(p_y - 7);
                            v30[2] = *(p_y - 5) + (float)(p_y[1] * (float)64.0);
                            v30[1] = (float)v23 + (float)v21;
                            v30[0] = (float)v24 + (float)v22;
                            clientGame->renderWorld->DebugLine(
                              this: clientGame->renderWorld,
                              a2: (const idVec4 *)&idColor::colorRed,
                              a3: (const idVec3 *)(p_y - 7),
                              a4: (const idVec3 *)v30,
                              a5: 10000,
                              a6: false);
                          }
                          if ( *((_DWORD *)p_y + 5) == 4 )
                            v25 = *((_DWORD *)p_y + 18);
                          else
                            LOWORD(v25) = -1;
                          v13 = (__int16)v25;
                          if ( (__int16)v25 == -1 )
                          {
                            idLib::Warning(
                              fmt: "ClientHitScan invalid joint contact on trace. TreeAnimator %s does not have sphere model collision?",
                              TreeAnimator->decl->name.str);
                            v13 = 0;
                          }
                        }
                        v9 = tfr;
                      }
                      idClientGameMsg_HitScanHit::AddHit(
                        this: (idClientGameMsg_HitScanHit *)&v31[0].mat[1].y,
                        entityNumber: v12,
                        jointNumber: v13,
                        bodyId: *((_DWORD *)p_y - 7),
                        hitPos: *((idVec3 **)p_y - 6));
                      if ( p_fire_clientHitscansNotify.valueInteger != 0 )
                        clientGame->renderWorld->DebugPoint(
                          this: clientGame->renderWorld,
                          a2: (const idVec4 *)&idColor::colorRed,
                          a3: (const idVec3 *)(p_y - 7),
                          a4: 1000,
                          a5: false);
                    }
                    else if ( p_fire_clientFireDebug.valueInteger > 0 )
                    {
                      idLib::Printf(fmt: "Hit presentable %d but not triggering HitScanHit event\n", v15->index);
                    }
                  }
                }
                else
                {
                  idLib::Warning(fmt: "Client hit entityNum %d with no presentable?", v12);
                }
              }
            }
            ++v10;
            p_y += 32;
          }
          while ( v10 < v9->numTraces );
          v7 = weapon;
        }
        if ( v32 > 0 )
          idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: (idClientGameMsg *)&v31[0].mat[1].y);
        LODWORD(v31[0].mat[1].y) = &idClientGameMsg::`vftable';
      }
      if ( this->GetEquippedWeapon(this, a2: 2) == v7 )
      {
        ++this->clientFire.fireCount;
        this->clientFire.firePos[0] = (int)fp->start.x;
        this->clientFire.firePos[1] = (int)fp->start.y;
        this->clientFire.firePos[2] = (int)fp->start.z;
        idMat3::ToAngles(this: v31, result: (idAngles *)&fp->fireAxis);
        y = v31[0].mat[0].y;
        x = v31[0].mat[0].x;
        v28 = (int)(float)(v31[0].mat[0].y * (float)182.04445);
        this->clientFire.fireAngles[0] = (int)(float)(v31[0].mat[0].x * (float)182.04445);
        this->clientFire.fireAngles[1] = v28;
        if ( p_fire_clientFireDebug.valueInteger > 0 )
        {
          idLib::Printf(
            fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fp->start.x)),
            (unsigned int)COERCE_UNSIGNED_INT64(fp->start.x),
            (unsigned int)COERCE_UNSIGNED_INT64(fp->start.y),
            (unsigned int)COERCE_UNSIGNED_INT64(fp->start.z),
            (int)x,
            (int)y);
          clientGame->renderWorld->DebugAxis_2(
            this: clientGame->renderWorld,
            a2: &fp->start,
            a3: &fp->fireAxis,
            a4: 5000,
            a5: false);
        }
      }
    }
    else
    {
      idLib::Warning(fmt: "idPresentablePlayer::RecordClientFire weapon is NULL. Not telling server about this one.");
    }
  }
}


// ========================================================================
// __unwind$487831
// EA  : 0x82B8A1AC
// RVA : 0x00B8A1AC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void _unwind_487831()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 1104 + 128));
}


// ========================================================================
// ?ClientHitScanHit@idPresentablePlayer@@UAAXHHHPBVidDeclWeapon@@PBVidDeclProjectile@@H@Z
// EA  : 0x82B8A1D8
// RVA : 0x00B8A1D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClientHitScanHit(
        idPresentablePlayer *this,
        int entityNumber,
        int jointNumber,
        int bodyId,
        const idDeclJob *weaponDecl,
        const idDeclProjectile *projDecl,
        int serverTimeOfHit)
{
  int v14; // r31
  int v15; // r25
  int ServerGameTime; // r3
  idJobManager *v17; // r3
  idWeapon *JobByDecl; // r3
  idWeapon *v19; // r31
  char v20; // r11
  idEntity *v21; // r3
  const idDeclDamage *damageDecl; // r25
  idEntity *v23; // r31
  idPhysics *Physics; // r3
  float *v25; // r3
  double v26; // fp9
  double v27; // fp7
  float *v28; // r11
  __int64 v29; // r9
  int i; // ctr
  idPhysics *v31; // r3
  float *v32; // r3
  idPresentable *presentable; // r28
  idPresentableAnimatedEntity *v34; // r3
  idTreeAnimator *TreeAnimator; // r27
  idPresentable *v36; // r3
  idPresentablePlayer_vtbl *v37; // r10
  idWeapon *v38; // r3
  float *v39; // r3
  weaponStatsTag_t **v40; // r3
  weaponStatsTag_t *v41; // r28
  double v42; // fp1
  idMat3 v43; // [sp+50h] [-1B0h] BYREF
  float v44; // [sp+74h] [-18Ch]
  float v45[3]; // [sp+78h] [-188h] BYREF
  float v46; // [sp+84h] [-17Ch]
  float v47; // [sp+88h] [-178h]
  float v48; // [sp+8Ch] [-174h]
  float x; // [sp+90h] [-170h]
  float y; // [sp+94h] [-16Ch]
  float z; // [sp+98h] [-168h]
  float v52; // [sp+9Ch] [-164h]
  float v53; // [sp+A0h] [-160h]
  float v54; // [sp+A4h] [-15Ch]
  float v55; // [sp+A8h] [-158h]
  float v56; // [sp+ACh] [-154h]
  float v57; // [sp+B0h] [-150h]
  int v58; // [sp+B4h] [-14Ch]
  float v59; // [sp+C4h] [-13Ch]
  float v60; // [sp+C8h] [-138h]
  float v61; // [sp+CCh] [-134h]
  int v62; // [sp+E8h] [-118h]
  int v63; // [sp+F4h] [-10Ch]
  char v64; // [sp+100h] [-100h] BYREF
  idMat3 v65; // [sp+110h] [-F0h] BYREF
  idMat3 v66; // [sp+140h] [-C0h] BYREF
  idVec3 v67[12]; // [sp+170h] [-90h] BYREF

  if ( p_fire_clientHitscans.valueInteger != 0 )
  {
    if ( p_fire_clientFireDebug.valueInteger > 0 )
    {
      v14 = this->entityNumber;
      v15 = idClientGame::GetServerGameTime(this: clientGame) - serverTimeOfHit;
      ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
      idLib::Printf(
        fmt: "Client %d hit entity %d joint %d. serverTime: %d serverTimeOfHit: %d difference: %d \n",
        v14,
        entityNumber,
        jointNumber,
        ServerGameTime,
        serverTimeOfHit,
        v15);
    }
    if ( projDecl != nullptr )
    {
      v17 = (idJobManager *)this->GetInventory(this);
      JobByDecl = (idWeapon *)idJobManager::FindJobByDecl(this: v17, jobDecl: weaponDecl);
      v19 = idWeapon::CastTo(c: JobByDecl);
      if ( this->IsDead(this) || (v20 = 0, v19 != nullptr) )
        v20 = 1;
      if ( v20 != 0 )
      {
        if ( entityNumber == this->entityNumber )
        {
          idLib::Warning(
            fmt: "idPresentablePlayer::ClientHitScanHit player %d hit self?! serverTimeOfHit: %d ",
            entityNumber,
            serverTimeOfHit);
        }
        else
        {
          v21 = gameLocal->GetEntity(this: gameLocal, a2: entityNumber);
          damageDecl = projDecl->damageDecl;
          v23 = v21;
          if ( damageDecl == nullptr )
            idLib::Warning(fmt: "idPresentablePlayer::ClientHitScanHit damageDef is NULL");
          if ( v23 != nullptr )
          {
            if ( idEntity::GetPhysics(this: v23) != nullptr )
            {
              if ( !v23->IsDead(this: v23) )
              {
                Physics = idEntity::GetPhysics(this: v23);
                v25 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
                v26 = (float)(v25[2] - this->firstPersonViewOrigin.z);
                v27 = (float)(v25[1] - this->firstPersonViewOrigin.y);
                v43.mat[0].x = *v25 - this->firstPersonViewOrigin.x;
                v43.mat[0].z = v26;
                v43.mat[0].y = v27;
                idVec3::NormalizeFast(this: v43.mat);
                v28 = v45;
                LODWORD(v29) = 0;
                for ( i = 16; i != 0; --i )
                {
                  v28 += 2;
                  *(_QWORD *)v28 = v29;
                }
                x = mat3_identity.mat[0].x;
                y = mat3_identity.mat[0].y;
                z = mat3_identity.mat[0].z;
                v52 = mat3_identity.mat[1].x;
                v53 = mat3_identity.mat[1].y;
                v54 = mat3_identity.mat[1].z;
                v55 = mat3_identity.mat[2].x;
                v56 = mat3_identity.mat[2].y;
                v57 = mat3_identity.mat[2].z;
                v31 = idEntity::GetPhysics(this: v23);
                v32 = (float *)v31->GetOrigin(this: v31, a2: 0);
                v46 = *v32;
                v47 = v32[1];
                v48 = v32[2];
                v58 = 1;
                v63 = bodyId;
                v45[2] = 0.89999998;
                presentable = v23->presentable;
                if ( presentable == nullptr )
                {
                  idEntity::InitPresentableInternal(this: v23);
                  presentable = v23->presentable;
                }
                if ( (__int16)jointNumber != -1 && presentable->GetAnimatedEntityInterface(this: presentable) != nullptr )
                {
                  v34 = presentable->GetAnimatedEntityInterface(this: presentable);
                  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v34);
                  v36 = presentable->GetAnimatedEntityInterface(this: presentable);
                  idPresentable::UpdateModelTransform(this: v36);
                  if ( TreeAnimator != nullptr && TreeAnimator->decl != nullptr )
                  {
                    idTreeAnimator::GetWorldSpaceJointTransform(
                      this: TreeAnimator,
                      pose: DRIVER_MODEL,
                      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(__int16)jointNumber,
                      origin: (idVec3 *)&v43.mat[1].y,
                      axis: &v65);
                    if ( p_fire_clientFireDebug.valueInteger > 0 )
                      clientGame->renderWorld->DebugAxis_2(
                        this: clientGame->renderWorld,
                        a2: (const idVec3 *)&v43.mat[1].y,
                        a3: &v65,
                        a4: 0,
                        a5: false);
                    v62 = jointNumber;
                    v58 = 4;
                    v46 = v43.mat[1].y;
                    v37 = this->__vftable;
                    v47 = v43.mat[1].z;
                    v48 = v43.mat[2].x;
                    v38 = v37->GetEquippedWeapon(this);
                    if ( idWeapon::GetMuzzleFlashWorldTransform(
                           this: v38,
                           ta: TreeAnimator,
                           attackType: ATTACK_DEFAULT,
                           origin: (idVec3 *)&v43.mat[2].z,
                           axis: &v66) )
                    {
                      v43.mat[0].x = v43.mat[1].y - v43.mat[2].z;
                      v43.mat[0].y = v43.mat[1].z - v44;
                      v43.mat[0].z = v43.mat[2].x - v45[0];
                      idVec3::NormalizeFast(this: v43.mat);
                      v59 = -v43.mat[0].x;
                      v60 = -v43.mat[0].y;
                      v61 = -v43.mat[0].z;
                      v39 = (float *)idVec3::ToMat3(this: v67, result: &v43);
                      x = *v39;
                      y = v39[1];
                      z = v39[2];
                      v52 = v39[3];
                      v53 = v39[4];
                      v54 = v39[5];
                      v55 = v39[6];
                      v56 = v39[7];
                      v57 = v39[8];
                    }
                  }
                  else
                  {
                    idLib::Warning(
                      fmt: "Null treeAnimator on HitScanHit'd PresentableSkeletalAnimator. Entity: %s ",
                      v23->name.data);
                  }
                }
                v43.mat[1].x = 0.0;
                v40 = (weaponStatsTag_t **)idGameLocal::WeaponFired(
                                             this: (idGameLocal *)&v64,
                                             result: (weaponStatsTag_t *)gameLocal,
                                             entity: this,
                                             decl: weaponDecl);
                v41 = *v40;
                idGameLocal::SetCurrentStatsDamage(this: gameLocal, tag: *v40, delayedCount: (int *)&v43.mat[1]);
                v42 = ((double (__fastcall *)(idEntity *, _DWORD, idEntity *, const idDeclDamage *, double))v23->Damage)(
                        a1: v23,
                        a2: 0,
                        a3: this->entity,
                        a4: damageDecl,
                        a5: 1.0);
                idGameLocal::WeaponFiredResult(this: gameLocal, tag: v41, target: v23, damage: v42);
                idGameLocal::ClearCurrentStatsDamage(this: gameLocal);
                idGameLocal::WeaponFiredDone(this: gameLocal, tag: v41, carryoverCount: SLODWORD(v43.mat[1].x));
              }
            }
            else
            {
              idLib::Warning(
                fmt: "idPresentablePlayer::ClientHitScanHit entity physics! is NULL. entityNumber: %d",
                entityNumber);
            }
          }
          else
          {
            idLib::Warning(fmt: "idPresentablePlayer::ClientHitScanHit entity is NULL. entityNumber: %d", entityNumber);
          }
        }
      }
      else if ( weaponDecl != nullptr )
      {
        idLib::Warning(
          fmt: "idPresentablePlayer::ClientHitScanHit unable to find weapon %s in player %d's inventory",
          weaponDecl->name.str,
          this->entityNumber);
      }
      else
      {
        idLib::Warning(
          fmt: "idPresentablePlayer::ClientHitScanHit unable to find weapon %s in player %d's inventory",
          "NULL",
          this->entityNumber);
      }
    }
    else
    {
      idLib::Warning(fmt: "idPresentablePlayer::ClientHitScanHit projDecl is NULL");
    }
  }
}


// ========================================================================
// ?PerformClientFire@idPresentablePlayer@@QAAXPAVidWeapon@@HABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82B8A790
// RVA : 0x00B8A790
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PerformClientFire(
        idPresentablePlayer *this,
        idWeapon *weapon,
        int serverTime,
        idVec3 *cmdFirePos,
        idAngles *cmdFireAxis)
{
  const char *str; // r7
  const char *v10; // r6
  idVec3 *v11; // r11
  int i; // ctr
  idVec3 *p_firstPersonViewOrigin; // r11
  float y; // r9
  float z; // r8
  idPresentablePlayer_vtbl *v16; // r7
  idMat3 *p_firstPersonViewAxis; // r11
  int *v18; // r10
  _DWORD *p_z; // r11
  int j; // ctr
  const idDeclProjectile *CurrentProjectileDecl; // r3
  int entityNumber; // r5
  const idDeclInventory *decl; // r30
  idJobManager *v24; // r3
  idJob *JobByDecl; // r3
  idInventoryItem *v26; // r30
  double pitch; // fp13
  double yaw; // fp12
  double roll; // fp11
  double v30; // fp10
  double v31; // fp9
  double v32; // fp8
  double v33; // fp7
  double v34; // fp6
  double v35; // fp5
  double v36; // fp4
  double v37; // fp3
  idFXManager *v38; // r7
  idEntity *entity; // [sp+60h] [-AB0h]
  idVec3 v40; // [sp+68h] [-AA8h] BYREF
  int v41; // [sp+7Ch] [-A94h] BYREF
  idMat3 v42; // [sp+80h] [-A90h] BYREF
  idFireParms v43; // [sp+B0h] [-A60h] BYREF
  idMat3 v44[2]; // [sp+148h] [-9C8h] BYREF
  idTestFireResults v45; // [sp+1B0h] [-960h] BYREF
  idVec3 v46; // 0:^50.12

  if ( p_fire_clientFireDebug.valueInteger > 0 )
  {
    if ( weapon != nullptr )
    {
      str = weapon->ammoClip->decl->name.str;
      v10 = weapon->decl->name.str;
    }
    else
    {
      str = "NULL";
      v10 = "NULL";
    }
    idLib::Printf(
      fmt: "Bang! player: %d fireCount: %d. Weapon: %s Ammo: %s \n",
      this->entityNumber,
      this->ucmdTracker1.usercmd.fireCount,
      v10,
      str);
  }
  if ( weapon != nullptr )
  {
    idFireParms::idFireParms(this: &v43);
    memset(&v45, 0, sizeof(v45));
    v11 = &v44[0].mat[2];
    v44[0].mat[2].x = 0.0;
    for ( i = 16; i != 0; --i )
    {
      v11 = (idVec3 *)((char *)v11 + 4);
      v11->x = 0.0;
    }
    if ( this->IsLocallyControlled(this) )
      p_firstPersonViewOrigin = &this->firstPersonViewOrigin;
    else
      p_firstPersonViewOrigin = cmdFirePos;
    y = p_firstPersonViewOrigin->y;
    z = p_firstPersonViewOrigin->z;
    v16 = this->__vftable;
    v40.x = p_firstPersonViewOrigin->x;
    v40.y = y;
    v40.z = z;
    if ( v16->IsLocallyControlled(this) )
      p_firstPersonViewAxis = &this->firstPersonViewAxis;
    else
      p_firstPersonViewAxis = (idMat3 *)cmdFireAxis;
    v18 = &v41;
    p_z = (_DWORD *)&p_firstPersonViewAxis[-1].mat[2].z;
    for ( j = 9; j != 0; --j )
      *++v18 = *++p_z;
    v46 = vec3_origin;
    CurrentProjectileDecl = idWeapon::GetCurrentProjectileDecl(this: weapon, secondaryAmmo: false);
    entityNumber = this->entityNumber;
    v43.projDef = CurrentProjectileDecl;
    *((_BYTE *)&v43 + 128) |= 0x30u;
    v43.ignoreEntityNum = entityNumber;
    v43.muzzleOffset.x = v46.x;
    v43.muzzleOffset.y = v46.y;
    v43.muzzleOffset.z = v46.z;
    v43.start.x = v40.x;
    v43.start.y = v40.y;
    v43.start.z = v40.z;
    v43.fireAxis.mat[0].x = v42.mat[0].x;
    v43.fireAxis.mat[0].y = v42.mat[0].y;
    v43.fireAxis.mat[0].z = v42.mat[0].z;
    v43.fireAxis.mat[1].x = v42.mat[1].x;
    v43.fireAxis.mat[1].y = v42.mat[1].y;
    v43.fireAxis.mat[1].z = v42.mat[1].z;
    v43.fireAxis.mat[2].x = v42.mat[2].x;
    v43.fireAxis.mat[2].y = v42.mat[2].y;
    v43.fireAxis.mat[2].z = v42.mat[2].z;
    v43.damageScale = 1.0;
    if ( CurrentProjectileDecl->hitscan )
      *((_BYTE *)&v43 + 129) |= 0x80u;
    else
      *((_BYTE *)&v43 + 129) &= ~0x80u;
    decl = weapon->ammoClip->decl;
    if ( decl != nullptr )
    {
      v24 = (idJobManager *)this->GetInventory(this);
      JobByDecl = idJobManager::FindJobByDecl(this: v24, jobDecl: (const idDeclJob *)decl);
      v26 = (idInventoryItem *)JobByDecl;
      if ( JobByDecl != nullptr && ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) > 1 )
        idInventoryItem::ModifyCount(this: v26, amount: -1);
    }
    if ( !idWeapon::TestFire(
            this: weapon,
            attacker: this,
            target: nullptr,
            start: &v40,
            fireAxis: &v42,
            fp: &v43,
            tfr: &v45,
            secondaryAmmo: false) )
      idLib::Warning(fmt: "idPresentablePlayer::ClientFire failed. How is this possible?");
    pitch = cmdFireAxis->pitch;
    yaw = cmdFireAxis->yaw;
    roll = cmdFireAxis->roll;
    v30 = cmdFireAxis[1].pitch;
    v31 = cmdFirePos->y;
    v32 = cmdFirePos->z;
    v33 = cmdFireAxis[1].yaw;
    v34 = cmdFireAxis[1].roll;
    v35 = cmdFireAxis[2].pitch;
    v36 = cmdFireAxis[2].yaw;
    v37 = cmdFireAxis[2].roll;
    v43.start.x = cmdFirePos->x;
    v43.fireAxis.mat[0].x = pitch;
    v43.fireAxis.mat[0].y = yaw;
    v43.fireAxis.mat[0].z = roll;
    v43.fireAxis.mat[1].x = v30;
    v43.start.y = v31;
    v43.start.z = v32;
    v43.fireAxis.mat[1].y = v33;
    v43.fireAxis.mat[1].z = v34;
    v43.fireAxis.mat[2].x = v35;
    v43.fireAxis.mat[2].y = v36;
    v43.fireAxis.mat[2].z = v37;
    if ( p_fire_clientFireDebug.valueInteger > 0 )
    {
      idMat3::ToAngles(this: v44, result: cmdFireAxis);
      idLib::Printf(
        fmt: "Client projectile <%.2f, %.2f, %.2f> angle <%d, %d>\n",
        cmdFirePos->x,
        cmdFirePos->y,
        cmdFirePos->z,
        (unsigned int)COERCE_UNSIGNED_INT64(cmdFirePos->x),
        (unsigned int)COERCE_UNSIGNED_INT64(cmdFirePos->y));
      clientGame->renderWorld->DebugAxis_2(
        this: clientGame->renderWorld,
        a2: &v43.start,
        a3: &v43.fireAxis,
        a4: 5000,
        a5: false);
    }
    entity = this->entity;
    if ( entity != nullptr )
      v38 = (idFXManager *)((int (__fastcall *)(idEntity *, idWeapon *))entity->__vftable[1].GetColor_3)(
                             a1: entity,
                             a2: weapon);
    else
      v38 = nullptr;
    weapon->FinishFire(this: weapon, a2: &v43, a3: &v45, a4: (idFinishFireResults *)&v44[0].mat[2], a5: v38, a6: false);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v43.targetList);
  }
}


// ========================================================================
// __unwind$488338
// EA  : 0x82B8AC04
// RVA : 0x00B8AC04
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void _unwind_488338()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2832 + 176));
}


// ========================================================================
// ?EvaluateClientFire@idPresentablePlayer@@QAAXABVusercmd_t@@HH@Z
// EA  : 0x82B8AC30
// RVA : 0x00B8AC30
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentablePlayer::EvaluateClientFire(
        idPresentablePlayer *this,
        const usercmd_t *usercmd,
        int startTime,
        int endTime)
{
  int fireCount; // r5
  int v7; // r6
  idWeapon *v8; // r3
  int v9; // r5
  __int128 v10; // r4 OVERLAPPED
  __int64 v11; // r11
  idWeapon *v12; // r29
  __int64 v13; // r6 OVERLAPPED
  int v14; // r7
  int v15; // r10
  int v16; // r4
  idMat3 v17; // [sp+78h] [-88h] BYREF
  idAngles v18[4]; // [sp+A0h] [-60h] BYREF

  if ( p_fire_clientFire.valueInteger != 0 )
  {
    if ( p_fire_clientFireDebug.valueInteger > 1 )
      idLib::Printf(
        fmt: "idPresentablePlayer::EvaluateClientFire player %d fireCount: %d usecmd.fireCount: %d. Difference: %d \n",
        this->entityNumber,
        this->clientFire.fireCount,
        usercmd->fireCount,
        usercmd->fireCount - this->clientFire.fireCount);
    fireCount = usercmd->fireCount;
    v7 = this->clientFire.fireCount;
    if ( fireCount - v7 > 3 )
    {
      idLib::Warning(fmt: "Suspiciously large clientFire delta from client %d...  %d - %d", this->index, fireCount, v7);
      this->clientFire.fireCount = usercmd->fireCount - 1;
    }
    if ( this->clientFire.fireCount == usercmd->fireCount )
    {
      v8 = this->GetEquippedWeapon(this, a2: 2);
      if ( v8 != nullptr )
        v8->ReleaseTrigger(this: v8, a2: nullptr);
    }
    v9 = usercmd->fireCount;
    if ( this->clientFire.fireCount < v9 )
    {
      do
      {
        *((_QWORD *)&v10 + 1) = ((__int64 (__fastcall *)(idPresentablePlayer *, int))this->GetEquippedWeapon)(
                                  a1: this,
                                  a2: 2);
        HIDWORD(v11) = (unsigned __int16)usercmd->fireAngles[0];
        v12 = (idWeapon *)DWORD2(v10);
        LOWORD(v13) = usercmd->firePos[1];
        v17.mat[0].z = 0.0;
        DWORD2(v10) = SWORD1(v11);
        LODWORD(v13) = (__int16)v13;
        HIDWORD(v13) = (unsigned __int16)usercmd->firePos[2];
        v14 = usercmd->firePos[0];
        LODWORD(v11) = usercmd->fireAngles[1];
        v17.mat[0].y = (float)v11 * (float)0.0054931641;
        v17.mat[1].z = (float)v13;
        HIDWORD(v13) = SWORD1(v13);
        v17.mat[1].y = (float)*(__int64 *)((char *)&v13 - 4);
        v17.mat[2].x = (float)*(__int64 *)((char *)&v10 - 4);
        v17.mat[0].x = (float)*(__int64 *)((char *)&v10 + 4) * (float)0.0054931641;
        idAngles::ToMat3(this: v18, result: &v17);
        idPresentablePlayer::PerformClientFire(
          this,
          weapon: v12,
          serverTime: usercmd->serverGameTime,
          cmdFirePos: (idVec3 *)&v17.mat[1].y,
          cmdFireAxis: v18);
        v15 = this->clientFire.fireCount + 1;
        this->clientFire.fireCount = v15;
        v9 = usercmd->fireCount;
      }
      while ( v15 < v9 );
    }
    v16 = this->clientFire.fireCount;
    if ( v16 > v9 && v9 != 0 )
    {
      idLib::Warning(fmt: "Server client fire got ahead of client! %d - %d", v16, v9);
      this->clientFire.fireCount = usercmd->fireCount;
    }
  }
}


// ========================================================================
// `dynamic initializer for 'p_fire_clientHitscans''
// EA  : 0x8336E640
// RVA : 0x0136E640
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_fire_clientHitscans__()
{
  idCVar::idCVar(
    this: &p_fire_clientHitscans,
    name: "p_fire_clientHitscans",
    value: "1",
    flags: 1,
    description: "Allow Client authoritative hitscans",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_fire_clientHitscans__);
}


// ========================================================================
// `dynamic initializer for 'p_fire_clientHitscansNotify''
// EA  : 0x8336E698
// RVA : 0x0136E698
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_fire_clientHitscansNotify__()
{
  idCVar::idCVar(
    this: &p_fire_clientHitscansNotify,
    name: "p_fire_clientHitscansNotify",
    value: "0",
    flags: 1,
    description: "Displays markers where local client hitscan hits",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_fire_clientHitscansNotify__);
}


// ========================================================================
// `dynamic initializer for 'p_fire_clientFire''
// EA  : 0x8336E6F0
// RVA : 0x0136E6F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_fire_clientFire__()
{
  idCVar::idCVar(
    this: &p_fire_clientFire,
    name: "p_fire_clientFire",
    value: "1",
    flags: 1,
    description: "Allow ClientFires",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_fire_clientFire__);
}


// ========================================================================
// `dynamic initializer for 'p_fire_clientFireDebug''
// EA  : 0x8336E748
// RVA : 0x0136E748
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_fire_clientFireDebug__()
{
  idCVar::idCVar(
    this: &p_fire_clientFireDebug,
    name: "p_fire_clientFireDebug",
    value: "0",
    flags: 2,
    description: "Debug ClientFires",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_fire_clientFireDebug__);
}


// ========================================================================
// `dynamic initializer for 'p_fire_clientAmmoDebug''
// EA  : 0x8336E7A0
// RVA : 0x0136E7A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_fire_clientAmmoDebug__()
{
  idCVar::idCVar(
    this: &p_fire_clientAmmoDebug,
    name: "p_fire_clientAmmoDebug",
    value: "0",
    flags: 1,
    description: "Debug Client Ammo",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_fire_clientAmmoDebug__);
}


// ========================================================================
// `dynamic initializer for 'cg_net_clientDeathMode''
// EA  : 0x8336E7F8
// RVA : 0x0136E7F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_net_clientDeathMode__()
{
  idCVar::idCVar(
    this: &cg_net_clientDeathMode,
    name: "cg_net_clientDeathMode",
    value: "1",
    flags: 2,
    description: "0=Always allow hit msgs. Fairest (but still unfair) for HPB but results in more double deaths. 1=Server interpolated"
    " time; favors LPBs, less double kills. 2=Server absolute time. Highly favors LPBs, no double kills",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_net_clientDeathMode__);
}


// ========================================================================
// `dynamic initializer for 'cg_net_clientDeathDebug''
// EA  : 0x8336E850
// RVA : 0x0136E850
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_weaponfire.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_net_clientDeathDebug__()
{
  idCVar::idCVar(
    this: &cg_net_clientDeathDebug,
    name: "cg_net_clientDeathDebug",
    value: "0",
    flags: 1,
    description: "Debug messages about dead clients doing damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_net_clientDeathDebug__);
}

