
// ========================================================================
// ?SimulateProjectiles@idGameLocal@@QAA_NXZ
// EA  : 0x82EB5BD0
// RVA : 0x00EB5BD0
// PDB : w:\tech5\tungsten\game\weapons\game_weapon.cpp
// ========================================================================

int __fastcall idGameLocal::SimulateProjectiles(idGameLocal *this)
{
  int v2; // r26
  idProjectile::simulatedProjectile_t *v3; // r31
  int v4; // r29
  int GameMsPerFrame; // r3

  v2 = 0;
  v3 = idProjectile::projectilesToSimulate;
  do
  {
    if ( v3->projectile != nullptr && v3->startTime != 0 )
    {
      v4 = v3->startTime
         + idGameTimeManager::GetGameMsPerFrame(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                         this: &this->clientGame.gameTimeManager,
                         type: GAMETIME_SCALED);
      v3->projectile->SimulateProjectileFrame(this: v3->projectile, a2: GameMsPerFrame, a3: v4);
      if ( v3->projectile != nullptr )
      {
        if ( v4 < idGameTimeManager::GetPreviousGameMs(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED) )
        {
          v3->startTime = v4;
          v2 = 1;
        }
        else
        {
          v3->projectile->PostSimulate(this: v3->projectile, a2: v4);
          v3->startTime = 0;
          v3->projectile = nullptr;
        }
      }
    }
    ++v3;
  }
  while ( (int)v3 < (int)&g_projectileHomingGroundCheck );
  return v2;
}


// ========================================================================
// ?FinishLaunchProjectile@idGameLocal@@AAA_NABVidFireParms@@ABVidTestFireResults@@AAVidFinishFireResults@@@Z
// EA  : 0x82EB5CD0
// RVA : 0x00EB5CD0
// PDB : w:\tech5\tungsten\game\weapons\game_weapon.cpp
// ========================================================================

unsigned int __fastcall idGameLocal::FinishLaunchProjectile(
        idGameLocal *this,
        const idFireParms *fp,
        const idTestFireResults *tfr,
        idFinishFireResults *ffr)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  unsigned int v9; // r20
  idCVar *v10; // r28
  char v11; // r11
  const idDeclProjectile *projDef; // r26
  idPresentable *v13; // r3
  const idDeclProjectile *v14; // r11
  const idDeclEntityDef *v15; // r27
  int spawnCount; // r11
  int v17; // r16
  int value; // r9
  idProjectile *v19; // r3
  idProjectile *v20; // r3
  idProjectile *v21; // r26
  unsigned __int64 v22; // r6
  const char *v23; // r7
  idPLog *pLog; // r28
  idPLog::logEntry_t *v25; // r30
  int v26; // r3
  int parent; // r9
  __int64 v28; // r8
  idPresentable *presentable; // r3
  int v30; // r3
  idPresentablePtr<idPresentable> *v31; // r27
  unsigned int v32; // r11
  __int64 v33; // r9
  __int64 v34; // r6
  long double v35; // fp2
  unsigned int v36; // r30
  unsigned int v37; // r30
  idPresentable *PresentableByIndex; // r3
  idPresentablePlayer *PlayerDriver; // r28
  unsigned int v40; // r30
  idPresentable *v41; // r3
  idPresentableVehicle *v42; // r3
  idPresentableVehicle *v43; // r30
  const idDeclFX *fxDeclQuad; // r30
  idPresentable *v45; // r3
  int *v46; // r10
  int *p_muzzleTagIndex; // r11
  int i; // ctr
  double spread; // fp13
  float *RandomSpreadTraceDir; // r3
  double v51; // fp0
  double v52; // fp13
  double v53; // fp12
  long double v54; // fp2
  long double v55; // fp2
  double x; // fp12
  double z; // fp9
  double v58; // fp4
  double v59; // fp3
  double v62; // fp8
  double v63; // fp12
  float y; // r6
  float v65; // r5
  int v66; // r9
  idEntity *v67; // r3
  idEntity *v68; // r3
  idEntity *v69; // r30
  unsigned int v70; // r11
  int num; // r11
  double v72; // fp13
  double v73; // fp12
  idPresentable *v74; // r3
  unsigned int spawnId; // r11
  double v76; // fp13
  double v77; // fp12
  idPresentable *v78; // r3
  idPresentablePlayer *Controller; // r28
  idPresentable *v80; // r3
  int valueInteger; // r30
  int serverGameTime; // r27
  int v83; // r3
  int v84; // r30
  idPresentable *v85; // r3
  int v86; // r8
  int v87; // r30
  idPresentable *v88; // r3
  idPresentable *Control; // r3
  idPresentableVehicle *v90; // r3
  idFinishFireResults *v91; // r27
  idWeapon *Weapon; // r3
  int PredictionKey; // r3
  idPresentable *v94; // r11
  int v95; // r30
  idEntity *entity; // r30
  unsigned int v97; // r30
  int v98; // r8
  unsigned int v99; // r28
  idPLog *v100; // r29
  idPLog::logEntry_t *v101; // r30
  int v102; // r3
  __int64 totalTicks; // r11
  __int64 v104; // r9
  bool v106; // [sp+50h] [-160h]
  bool v107; // [sp+51h] [-15Fh]
  int v108; // [sp+54h] [-15Ch]
  idProjectileTarget v109; // [sp+60h] [-150h] BYREF
  idGameLocal_vtbl *tag; // [sp+74h] [-13Ch]
  idVec3 *p_projectile; // [sp+78h] [-138h]
  const idDeclEntityDef *entityDef; // [sp+7Ch] [-134h] BYREF
  idCVar *v113; // [sp+80h] [-130h]
  const char *v114; // [sp+84h] [-12Ch]
  idPLogScope v115; // [sp+88h] [-128h] BYREF
  idPLog *v116; // [sp+90h] [-120h]
  idVec3 *v117; // [sp+94h] [-11Ch]
  idCVar *v118; // [sp+98h] [-118h]
  idPLogScope v119[3]; // [sp+A0h] [-110h] BYREF
  int v120; // [sp+BCh] [-F4h] BYREF
  idMat3 v121; // [sp+C0h] [-F0h] BYREF
  int v122; // [sp+E8h] [-C8h] BYREF

  RD_EventBegin(name: "idGameLocal::FinishLaunchProjectile");
  LODWORD(v7) = "idGameLocal::FinishLaunchProjectile";
  HIDWORD(v7) = 2;
  v116 = &::pLog;
  idPLogScope::idPLogScope(this: v119, pl: &::pLog, gMask: v7, label: v8);
  v9 = 0;
  v10 = &g_recordLaunchProjectileTrace;
  v106 = false;
  v113 = &g_recordLaunchProjectileTrace;
  if ( g_recordLaunchProjectileTrace.valueInteger == 1 )
    v106 = fp->projDef->spawnCount > 0;
  tag = (idGameLocal_vtbl *)fp->tag;
  if ( ((unsigned int)tag & 0xFC000000) != 0
    || ((unsigned int)tag & 0x3C00000) != 0
    || (v11 = 1, ((unsigned int)tag & 0x3FFFFF) != 0) )
  {
    v11 = 0;
  }
  if ( v11 != 0 )
  {
    projDef = fp->projDef;
    v13 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
    tag = idGameLocal::WeaponFired(
            this: (idGameLocal *)&entityDef,
            result: (weaponStatsTag_t *)gameLocal,
            entity: v13,
            decl: projDef)->__vftable;
  }
  ffr->numProjectiles = 0;
  v14 = fp->projDef;
  entityDef = v14->notHitscanInfo.entityDef;
  v15 = entityDef;
  if ( entityDef != nullptr )
  {
    spawnCount = v14->spawnCount;
    if ( spawnCount < 1 )
      spawnCount = 1;
    v17 = 0;
    v108 = spawnCount;
    v107 = (-fp->targetList.num & ~fp->targetList.num) < 0;
    v117 = &vec3_origin;
    v114 = "Spawning throw item projectile for player %d. PredictiveKey: %d \n";
    v118 = &cg_projectile_clientAuthoritative;
    while ( 1 )
    {
      if ( v9 != 0
        || ((value = fp->projectile.spawnId.value,
             p_projectile = (idVec3 *)&fp->projectile,
             gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13)
         || (v19 = (idProjectile *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
          ? (v20 = nullptr)
          : (v20 = idProjectile::CastTo(c: v19)),
            v21 = v20,
            v20 == nullptr) )
      {
        RD_EventBegin(name: "idGameLocal::FinishLaunchProjectile - spawn entity");
        LODWORD(v22) = "idGameLocal::FinishLaunchProjectile - spawn entity";
        HIDWORD(v22) = 2;
        idPLogScope::idPLogScope(this: &v115, pl: v116, gMask: v22, label: v23);
        v21 = (idProjectile *)this->SpawnEntityFromDef(this, a2: v15, a3: -1, a4: -1, a5: -1);
        if ( v115.logIndex >= 0 )
        {
          pLog = v115.pLog;
          v25 = &v115.pLog->logEntries.list[v115.logIndex];
          v26 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          parent = v25->parent;
          LODWORD(v28) = v26 - LODWORD(v25->totalTicks);
          v115.logIndex = -1;
          v25->totalTicks = v28;
          pLog->lastEntry = parent;
          v10 = v113;
        }
        RD_EventEnd();
        if ( v21 == nullptr )
          goto LABEL_103;
      }
      presentable = v21->presentable;
      if ( presentable != nullptr )
        v30 = (int)presentable->GetProjectileInterface(this: presentable);
      else
        v30 = 0;
      v31 = (idPresentablePtr<idPresentable> *)&ffr->projectiles[v9];
      v32 = 0;
      if ( v30 != 0 )
        v32 = *(_DWORD *)(v30 + 1100);
      v31->spawnId = v32;
      v21->launchWeapon = idFireParms::GetWeapon(this: fp);
      idProjectile::SetWeaponStatsTag(this: v21, (weaponStatsTag_t *)tag);
      v21->damageScale = fp->damageScale;
      v36 = fp->attacker.spawnId & 0x3FFF;
      if ( fp->attacker.spawnId != 0
        && idClientGame::IsPresentableIndexValid(this: clientGame, index: fp->attacker.spawnId & 0x3FFF)
        && idClientGame::GetPresentableByIndex(this: clientGame, index: v36)->spawnId == fp->attacker.spawnId )
      {
        v37 = fp->attacker.spawnId & 0x3FFF;
        if ( fp->attacker.spawnId == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: fp->attacker.spawnId & 0x3FFF)
          || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v37))->spawnId != fp->attacker.spawnId )
        {
          PresentableByIndex = nullptr;
        }
        PlayerDriver = PresentableByIndex->GetPlayerInterface_2(this: PresentableByIndex);
        v40 = fp->attacker.spawnId & 0x3FFF;
        if ( fp->attacker.spawnId == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: fp->attacker.spawnId & 0x3FFF)
          || (v41 = idClientGame::GetPresentableByIndex(this: clientGame, index: v40))->spawnId != fp->attacker.spawnId )
        {
          v41 = nullptr;
        }
        v42 = v41->GetVehicleInterface(this: v41);
        v43 = v42;
        if ( PlayerDriver != nullptr )
          goto LABEL_112;
        if ( v42 == nullptr )
          goto LABEL_47;
        PlayerDriver = idPresentableVehicle::GetPlayerDriver(this: v42);
        if ( PlayerDriver != nullptr )
        {
LABEL_112:
          HIDWORD(v33) = *((_BYTE *)PlayerDriver + 47032) & 2;
          if ( (*((_BYTE *)PlayerDriver + 47032) & 2) != 0 )
            goto LABEL_45;
        }
        if ( v43 != nullptr && v43->hasQuad )
        {
LABEL_45:
          fxDeclQuad = fp->projDef->fxDeclQuad;
          if ( fxDeclQuad != nullptr )
          {
            v45 = idPresentablePtr<idPresentableProjectile>::operator->(this: v31);
            idPresentable::ResetFXMgr(this: v45, fxDecl_: fxDeclQuad);
            *(&idPresentablePtr<idPresentableProjectile>::operator->(this: v31)[1].becameReplicated + 1) = true;
          }
        }
      }
LABEL_47:
      v46 = &v120;
      p_muzzleTagIndex = &fp->muzzleTagIndex;
      for ( i = 9; i != 0; --i )
        *++v46 = *++p_muzzleTagIndex;
      spread = fp->projDef->spread;
      if ( spread > 0.0 )
      {
        if ( v108 != 1 || (*((_BYTE *)fp + 128) & 2) != 0 )
        {
          v119[1] = (idPLogScope)__PAIR64__(v108, v9);
          LODWORD(v33) = v108;
          v119[2] = (idPLogScope)v33;
          *((double *)&v54 + 1) = (float)((float)spread
                                        * (float)((float)((float)((float)((float)__SPAIR64__(v108, v9) + (float)0.5)
                                                                / (float)v33)
                                                        - (float)0.5)
                                                * (float)2.0));
          *(double *)&v54 = (float)((float)((float)spread
                                          * (float)((float)((float)((float)((float)__SPAIR64__(v108, v9) + (float)0.5)
                                                                  / (float)v33)
                                                          - (float)0.5)
                                                  * (float)2.0))
                                  * idMath::M_DEG2RAD);
          v55 = sin(x: v54);
          *(double *)&v55 = (float)*(double *)&v55;
          x = fp->fireAxis.mat[1].x;
          z = fp->fireAxis.mat[1].z;
          v58 = (float)(fp->fireAxis.mat[0].y - (float)(fp->fireAxis.mat[1].y * (float)*(double *)&v55));
          p_projectile = &fp->fireAxis.mat[1];
          v59 = (float)(fp->fireAxis.mat[0].x - (float)((float)x * (float)*(double *)&v55));
          *((double *)&v55 + 1) = (float)(fp->fireAxis.mat[0].z - (float)((float)z * (float)*(double *)&v55));
          _FP11 = (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1))
                                + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)))
                        - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f9, f11, f12, f0 }
          v62 = __frsqrte(_FP9);
          v63 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62
                                                                                              * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5))
                                                                                      * (float)v62)
                                                                              - (float)1.5)
                                                              * (float)v62)
                                                      * (float)((float)((float)((float)*((double *)&v55 + 1)
                                                                              * (float)*((double *)&v55 + 1))
                                                                      + (float)((float)((float)v59 * (float)v59)
                                                                              + (float)((float)v58 * (float)v58)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v62
                                                                                      * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)))
                                                                                              * (float)0.5))
                                                                              * (float)v62)
                                                                      - (float)1.5)
                                                      * (float)v62))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v62
                                                              * (float)((float)((float)((float)*((double *)&v55 + 1)
                                                                                      * (float)*((double *)&v55 + 1))
                                                                              + (float)((float)((float)v59 * (float)v59)
                                                                                      + (float)((float)v58 * (float)v58)))
                                                                      * (float)0.5))
                                                      * (float)v62)
                                              - (float)1.5)
                              * (float)v62));
          v51 = (float)((float)v59
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5)) * (float)v62) - (float)1.5) * (float)v62) * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5)) * (float)v62) - (float)1.5) * (float)v62))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5)) * (float)v62)
                                                                                              - (float)1.5)
                                                                              * (float)v62))
                                                              * (float)((float)((float)((float)*((double *)&v55 + 1)
                                                                                      * (float)*((double *)&v55 + 1))
                                                                              + (float)((float)((float)v59 * (float)v59)
                                                                                      + (float)((float)v58 * (float)v58)))
                                                                      * (float)0.5))
                                                      * (float)v63)
                                              - (float)1.5)
                              * (float)v63));
          v52 = (float)((float)v58
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5)) * (float)v62) - (float)1.5) * (float)v62) * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5)) * (float)v62) - (float)1.5) * (float)v62))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5)) * (float)v62)
                                                                                              - (float)1.5)
                                                                              * (float)v62))
                                                              * (float)((float)((float)((float)*((double *)&v55 + 1)
                                                                                      * (float)*((double *)&v55 + 1))
                                                                              + (float)((float)((float)v59 * (float)v59)
                                                                                      + (float)((float)v58 * (float)v58)))
                                                                      * (float)0.5))
                                                      * (float)v63)
                                              - (float)1.5)
                              * (float)v63));
          v53 = (float)((float)*((double *)&v55 + 1)
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5)) * (float)v62) - (float)1.5) * (float)v62) * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5)) * (float)v62) - (float)1.5) * (float)v62))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)((float)*((double *)&v55 + 1) * (float)*((double *)&v55 + 1)) + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) * (float)0.5)) * (float)v62)
                                                                                              - (float)1.5)
                                                                              * (float)v62))
                                                              * (float)((float)((float)((float)*((double *)&v55 + 1)
                                                                                      * (float)*((double *)&v55 + 1))
                                                                              + (float)((float)((float)v59 * (float)v59)
                                                                                      + (float)((float)v58 * (float)v58)))
                                                                      * (float)0.5))
                                                      * (float)v63)
                                              - (float)1.5)
                              * (float)v63));
        }
        else
        {
          HIDWORD(v34) = fp;
          RandomSpreadTraceDir = (float *)idClientGame::GetRandomSpreadTraceDir(
                                            this: (idClientGame *)&v122,
                                            fp: v34,
                                            a3: v35);
          v51 = *RandomSpreadTraceDir;
          v52 = RandomSpreadTraceDir[1];
          v53 = RandomSpreadTraceDir[2];
        }
        v121.mat[0].x = v51;
        v121.mat[0].y = v52;
        v121.mat[0].z = v53;
        idMat3::OrthoNormalizeSelf(this: &v121);
      }
      v109.type = TARGET_NONE;
      v109.presentable.spawnId = 0;
      y = v117->y;
      v65 = v117->z;
      v109.pos.x = v117->x;
      v109.pos.y = y;
      v109.pos.z = v65;
      if ( v107 )
      {
        v66 = fp->targetList.list[v17].spawnId.value;
        if ( gameLocal->spawnIds.ptr[v66 & 0x1FFF] == v66 >> 13 )
        {
          v67 = gameLocal->entities.ptr[fp->targetList.list[v17].spawnId.value & 0x1FFF];
          if ( v67 != nullptr )
          {
            v68 = idEntity::CastTo(c: v67);
            v69 = v68;
            if ( v68 != nullptr )
            {
              v70 = (unsigned int)v68->presentable;
              if ( v70 == 0 )
              {
                idEntity::InitPresentableInternal(this: v68);
                v70 = (unsigned int)v69->presentable;
                goto LABEL_62;
              }
              goto LABEL_63;
            }
          }
        }
        v70 = 0;
LABEL_62:
        if ( v70 != 0 )
LABEL_63:
          v70 = *(_DWORD *)(v70 + 1100);
        v109.presentable.spawnId = v70;
        ++v17;
        num = fp->targetList.num;
        v109.type = TARGET_PRESENTABLE;
        if ( v17 == num )
          v17 = 0;
        goto LABEL_75;
      }
      if ( (*((_BYTE *)fp + 128) & 4) != 0 )
      {
        v72 = fp->targetPos.y;
        v73 = fp->targetPos.z;
        v109.pos.x = fp->targetPos.x;
        p_projectile = &fp->targetPos;
        v109.type = TARGET_POINT;
        v109.pos.y = v72;
        v109.pos.z = v73;
      }
      else if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->target) != nullptr )
      {
        v74 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->target);
        spawnId = 0;
        if ( v74 != nullptr )
          spawnId = v74->spawnId;
        v109.presentable.spawnId = spawnId;
        v109.type = TARGET_PRESENTABLE;
      }
      if ( fp->projDef->notHitscanInfo.fireAtPoint && tfr->numTraces > 0 )
      {
        v76 = tfr->traces[0].endpos.y;
        v77 = tfr->traces[0].endpos.z;
        v109.pos.x = tfr->traces[0].endpos.x;
        p_projectile = &tfr->traces[0].endpos;
        v109.type = TARGET_POINT;
        v109.pos.y = v76;
        v109.pos.z = v77;
      }
LABEL_75:
      if ( common->IsMultiplayer(this: common) && v118->valueInteger != 0 )
      {
        if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) != nullptr )
        {
          v78 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
          Controller = v78->GetPlayerInterface_2(this: v78);
          if ( Controller != nullptr
            || (v80 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker),
                (Controller = idPresentable::GetController(this: v80)) != nullptr) )
          {
            if ( !Controller->IsLocallyControlled(this: Controller) )
            {
              valueInteger = cg_projectile_clientAuthoritative_maxCatchup.valueInteger;
              serverGameTime = Controller->ucmdTracker1.usercmd.serverGameTime;
              v83 = this->GetGameMs(this, a2: GAMETIME_SCALED);
              if ( v83 - serverGameTime >= 0 )
              {
                if ( v83 - serverGameTime <= valueInteger )
                  valueInteger = v83 - serverGameTime;
              }
              else
              {
                valueInteger = 0;
              }
              v84 = this->GetGameMs(this, a2: GAMETIME_SCALED) - valueInteger;
              v85 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
              idProjectile::Launch(
                this: v21,
                attacker_: v85->entity,
                start: &fp->start,
                fireAxis: &v121,
                target: &v109,
                initialSpeed: fp->startSpeed,
                startTime: v86,
                launchTimeOverride: fp->startTime);
              if ( v21->projectileDecl->clientType != PROJCLIENT_NONE )
                idProjectile::QueueToSimulate(this: v21, startTime: v84);
              v87 = -1;
              if ( idPresentablePlayer::GetControl(this: Controller) != nullptr
                && (v88 = idPresentablePlayer::GetControl(this: Controller),
                    v88->GetVehicleInterface(this: v88) != nullptr) )
              {
                Control = idPresentablePlayer::GetControl(this: Controller);
                v90 = Control->GetVehicleInterface(this: Control);
                v91 = ffr;
                v87 = (ffr->numProjectiles << 24) | idPresentableVehicle::GetFireCount(this: v90);
              }
              else
              {
                v91 = ffr;
              }
              Weapon = idFireParms::GetWeapon(this: fp);
              PredictionKey = idClientGame::GeneratePredictionKey(
                                this: &this->clientGame,
                                weapon: Weapon,
                                playerAttacker: (lobbyUserID_t *)Controller,
                                overrideKey: v87);
              v94 = v21->presentable;
              v95 = PredictionKey;
              if ( v94 == nullptr )
              {
                idEntity::InitPresentableInternal(this: v21);
                v94 = v21->presentable;
              }
              v94->predictedKey = v95;
              if ( cg_predictedSpawn_debug.valueInteger != 0 )
                idLib::Printf(fmt: v114, Controller->index, v95);
              goto LABEL_102;
            }
          }
        }
        if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) == nullptr )
        {
LABEL_100:
          entity = nullptr;
          goto LABEL_101;
        }
      }
      else
      {
        v97 = fp->attacker.spawnId & 0x3FFF;
        if ( fp->attacker.spawnId == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: fp->attacker.spawnId & 0x3FFF)
          || idClientGame::GetPresentableByIndex(this: clientGame, index: v97)->spawnId != fp->attacker.spawnId )
        {
          goto LABEL_100;
        }
      }
      entity = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker)->entity;
LABEL_101:
      idGameTimeManager::GetGameMs(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED);
      idProjectile::Launch(
        this: v21,
        attacker_: entity,
        start: &fp->start,
        fireAxis: &v121,
        target: &v109,
        initialSpeed: fp->startSpeed,
        startTime: v98,
        launchTimeOverride: fp->startTime);
      v91 = ffr;
LABEL_102:
      v10 = v113;
      ++v91->numProjectiles;
      v15 = entityDef;
LABEL_103:
      if ( (int)++v9 >= v108 )
        goto LABEL_104;
    }
  }
  idLib::Warning(
    fmt: "idGameLocal::FinishLaunchProjectile: entityDef not found on idDeclProjectile '%s'",
    v14->name.str);
LABEL_104:
  idGameLocal::WeaponFiredDone(this: gameLocal, (weaponStatsTag_t *)tag, carryoverCount: ffr->numProjectiles);
  if ( v106 && v10->valueInteger == 1 )
    idCVar::SetInteger(this: v10, newValue: 0, force: true);
  v99 = (-ffr->numProjectiles & (unsigned int)~ffr->numProjectiles) >> 31;
  if ( v119[0].logIndex >= 0 )
  {
    v100 = v119[0].pLog;
    v101 = &v119[0].pLog->logEntries.list[v119[0].logIndex];
    v102 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v101->totalTicks;
    HIDWORD(totalTicks) = v101->parent;
    LODWORD(v104) = v102 - totalTicks;
    v101->totalTicks = v104;
    v100->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  return v99;
}


// ========================================================================
// __unwind$488265
// EA  : 0x82EB67DC
// RVA : 0x00EB67DC
// PDB : w:\tech5\tungsten\game\weapons\game_weapon.cpp
// ========================================================================

void _unwind_488265()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 432 + 244));
}


// ========================================================================
// __unwind$488266_0
// EA  : 0x82EB6804
// RVA : 0x00EB6804
// PDB : w:\tech5\tungsten\game\weapons\game_weapon.cpp
// ========================================================================

void _unwind_488266_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 432 + 160));
}


// ========================================================================
// __unwind$488267
// EA  : 0x82EB682C
// RVA : 0x00EB682C
// PDB : w:\tech5\tungsten\game\weapons\game_weapon.cpp
// ========================================================================

void _unwind_488267()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 432 + 245));
}


// ========================================================================
// __unwind$488268_0
// EA  : 0x82EB6854
// RVA : 0x00EB6854
// PDB : w:\tech5\tungsten\game\weapons\game_weapon.cpp
// ========================================================================

void _unwind_488268_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 432 + 136));
}


// ========================================================================
// ?FinishFire@idGameLocal@@QAA_NABVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@@Z
// EA  : 0x82EB6880
// RVA : 0x00EB6880
// PDB : w:\tech5\tungsten\game\weapons\game_weapon.cpp
// ========================================================================

unsigned int __fastcall idGameLocal::FinishFire(
        idGameLocal *this,
        const idFireParms *fp,
        idTestFireResults *tfr,
        idFinishFireResults *ffr)
{
  if ( fp->projDef->hitscan )
    return idClientGame::FinishHitScan(this: &this->clientGame, fp, tfr, ffr);
  else
    return idGameLocal::FinishLaunchProjectile(this, fp, tfr, ffr);
}


// ========================================================================
// `dynamic initializer for 'g_testEffects''
// EA  : 0x83392F30
// RVA : 0x01392F30
// PDB : w:\tech5\tungsten\game\weapons\game_weapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_testEffects__()
{
  idCVar::idCVar(
    this: &g_testEffects,
    name: "g_testEffects",
    value: "0",
    flags: 1,
    description: "testing effect for jeremy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_testEffects__);
}

