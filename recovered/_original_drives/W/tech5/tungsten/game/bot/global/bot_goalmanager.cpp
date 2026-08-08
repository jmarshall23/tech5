
// ========================================================================
// ??0idBotGoalManager_DM@@QAA@XZ
// EA  : 0x82B492D8
// RVA : 0x00B492D8
// PDB : w:\tech5\tungsten\game\bot\global\bot_goalmanager.cpp
// ========================================================================

idBotGoalManager_DM *__fastcall idBotGoalManager_DM::idBotGoalManager_DM(idBotGoalManager_DM *this)
{
  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idBotGoalManager_DM_vtbl *)&idBotGoalManager_DM::`vftable';
  return this;
}


// ========================================================================
// ??0idBotGoalManager_TDM@@QAA@XZ
// EA  : 0x82B49318
// RVA : 0x00B49318
// PDB : w:\tech5\tungsten\game\bot\global\bot_goalmanager.cpp
// ========================================================================

idBotGoalManager_TDM *__fastcall idBotGoalManager_TDM::idBotGoalManager_TDM(idBotGoalManager_TDM *this)
{
  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idBotGoalManager_TDM_vtbl *)&idBotGoalManager_TDM::`vftable';
  return this;
}


// ========================================================================
// ??0idBotGoalManager_CTF@@QAA@XZ
// EA  : 0x82B49358
// RVA : 0x00B49358
// PDB : w:\tech5\tungsten\game\bot\global\bot_goalmanager.cpp
// ========================================================================

idBotGoalManager_CTF *__fastcall idBotGoalManager_CTF::idBotGoalManager_CTF(idBotGoalManager_CTF *this)
{
  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idBotGoalManager_CTF_vtbl *)&idBotGoalManager_CTF::`vftable';
  return this;
}


// ========================================================================
// ??0idBotGoalManager_HORDE@@QAA@XZ
// EA  : 0x82B49398
// RVA : 0x00B49398
// PDB : w:\tech5\tungsten\game\bot\global\bot_goalmanager.cpp
// ========================================================================

idBotGoalManager_HORDE *__fastcall idBotGoalManager_HORDE::idBotGoalManager_HORDE(idBotGoalManager_HORDE *this)
{
  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idBotGoalManager_HORDE_vtbl *)&idBotGoalManager_HORDE::`vftable';
  return this;
}


// ========================================================================
// ??0idBotGoalManager_DOM@@QAA@XZ
// EA  : 0x82B493D8
// RVA : 0x00B493D8
// PDB : w:\tech5\tungsten\game\bot\global\bot_goalmanager.cpp
// ========================================================================

idBotGoalManager_DOM *__fastcall idBotGoalManager_DOM::idBotGoalManager_DOM(idBotGoalManager_DOM *this)
{
  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idBotGoalManager_DOM_vtbl *)&idBotGoalManager_DOM::`vftable';
  return this;
}


// ========================================================================
// ?Think@idBotGoalManager_DM@@UAAXH@Z
// EA  : 0x82B49480
// RVA : 0x00B49480
// PDB : w:\tech5\tungsten\game\bot\global\bot_goalmanager.cpp
// ========================================================================

void __fastcall idBotGoalManager_DM::Think(idBotGoalManager_DM *this, const int curTime)
{
  int v2; // r21
  idGameLocal *v3; // r11
  int num; // r17
  int v5; // r22
  int value; // r9
  idPlayer *v7; // r3
  idPlayer *v8; // r3
  idPlayer *v9; // r27
  idBotGoal *BotGoalTask; // r25
  int v11; // r7
  bool v12; // r6
  idPlayer *DebugPlayer; // r5
  int v14; // r9
  idGameLocal *v15; // r11
  idEntity *v16; // r3
  idEntity *v17; // r3
  idAI2 *v18; // r31
  int v19; // r28
  int v20; // r29
  int v21; // r30
  int v22; // r9
  idPlayer *v23; // r3
  idPlayer *v24; // r3
  idPresentable *presentable; // r3
  int v26; // r3
  int v27; // r28
  int v28; // r29
  int i; // r30
  int v30; // r9
  idAI2 *v31; // r3
  idPhysics *Physics; // r3
  const idVec3 *v33; // r3
  int v34; // r7
  bool v35; // r6

  v2 = 0;
  v3 = gameLocal;
  num = gameLocal->botEntities.num;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      value = v3->botEntities.list[v5].spawnId.value;
      if ( v3->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v7 = (idPlayer *)v3->entities.ptr[value & 0x1FFF];
        if ( v7 != nullptr )
        {
          v8 = idPlayer::CastTo(c: v7);
          v9 = v8;
          if ( v8 != nullptr )
          {
            BotGoalTask = idPlayer::GetBotGoalTask(this: v8);
            if ( BotGoalTask != nullptr )
            {
              if ( bot_followPlayer.valueInteger != 0
                && (DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
              {
                idBotGoal::GoalManager_InitEntityGoal(
                  this: BotGoalTask,
                  goalFlags: 4,
                  newGoalEntity: DebugPlayer,
                  newGoalRadius: 128.0,
                  combatMaxRange: 768.0,
                  clearEnemy: v12,
                  a7: v11,
                  a8: 1);
              }
              else
              {
                v14 = BotGoalTask->goalEnemy.spawnId.value;
                v15 = gameLocal;
                if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
                  && (v16 = gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
                {
                  v17 = idEntity::CastTo(c: v16);
                  v15 = gameLocal;
                }
                else
                {
                  v17 = nullptr;
                }
                v18 = (idAI2 *)v17;
                if ( v17 == nullptr )
                {
                  v19 = v15->playerEntities.num;
                  v20 = 0;
                  if ( v19 > 0 )
                  {
                    v21 = 0;
                    do
                    {
                      v22 = v15->playerEntities.list[v21].spawnId.value;
                      if ( v15->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
                        && (v23 = (idPlayer *)v15->entities.ptr[v22 & 0x1FFF]) != nullptr )
                      {
                        v24 = idPlayer::CastTo(c: v23);
                        v15 = gameLocal;
                        v18 = (idAI2 *)v24;
                      }
                      else
                      {
                        v18 = nullptr;
                      }
                      if ( v18 != (idAI2 *)v9 )
                      {
                        if ( !v18->IsDead(this: v18) )
                        {
                          presentable = v18->presentable;
                          v26 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
                          if ( (*(_BYTE *)(v26 + 47032) & 0x20) == 0
                            && (HIBYTE(v18->aiVolatile.physics.moveState.lastPath.obstacleRoute.areas[5].start.x) & 8) == 0 )
                          {
                            goto LABEL_39;
                          }
                        }
                        v15 = gameLocal;
                      }
                      ++v20;
                      ++v21;
                    }
                    while ( v20 < v19 );
                  }
                  v27 = v15->activeAI.num;
                  v28 = 0;
                  if ( v27 <= 0 )
                    return;
                  for ( i = 0; ; ++i )
                  {
                    v30 = v15->activeAI.list[i].spawnId.value;
                    if ( v15->spawnIds.ptr[v30 & 0x1FFF] == v30 >> 13
                      && (v31 = (idAI2 *)v15->entities.ptr[v30 & 0x1FFF]) != nullptr )
                    {
                      v18 = idAI2::CastTo(c: v31);
                    }
                    else
                    {
                      v18 = nullptr;
                    }
                    if ( !v18->IsDead(this: v18) )
                      break;
                    if ( ++v28 >= v27 )
                      return;
                    v15 = gameLocal;
                  }
                }
LABEL_39:
                Physics = idEntity::GetPhysics(this: v18);
                v33 = Physics->GetOrigin(this: Physics, a2: 0);
                idBotGoal::GoalManager_InitPosGoal(
                  this: BotGoalTask,
                  goalFlags: 128,
                  newGoalPos: v33,
                  newGoalRadius: 256.0,
                  combatMaxRange: 2048.0,
                  clearEnemy: v35,
                  a7: v34,
                  a8: 0);
              }
            }
          }
          v3 = gameLocal;
        }
      }
      ++v2;
      ++v5;
    }
    while ( v2 < num );
  }
}


// ========================================================================
// ?Think@idBotGoalManager_TDM@@UAAXH@Z
// EA  : 0x82B497E8
// RVA : 0x00B497E8
// PDB : w:\tech5\tungsten\game\bot\global\bot_goalmanager.cpp
// ========================================================================

void __fastcall idBotGoalManager_TDM::Think(idBotGoalManager_TDM *this, int curTime)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v4; // r25
  bool Noclip; // r3
  char v6; // r11
  char v7; // r26
  idGameLocal *v8; // r11
  bool v9; // zf
  int num; // r27
  int v11; // r28
  int v12; // r29
  int value; // r9
  idPlayer *v14; // r3
  idPlayer *v15; // r3
  idPlayer *v16; // r30
  gameTeam_t Team; // r20
  gameTeam_t v18; // r19
  idGameChallenge *ChallengeEntity; // r3
  idBotGoal *BotGoalTask; // r3
  idPhysics *Physics; // r3
  int v22; // r3
  float *v23; // r26
  idPlayer *v24; // r27
  double v25; // fp31
  int v26; // r28
  int v27; // r29
  int v28; // r9
  idPlayer *v29; // r3
  idPlayer *v30; // r3
  idEntity *v31; // r30
  gameTeam_t v32; // r20
  gameTeam_t v33; // r19
  idGameChallenge *v34; // r3
  idPhysics *v35; // r3
  float *v36; // r3
  double v37; // fp10
  double v38; // fp6
  idBotGoal *v39; // r3
  int v40; // r7
  bool v41; // r6
  int v42; // r17
  int v43; // r9
  idPlayer *v44; // r3
  idPlayer *v45; // r3
  idEntity *v46; // r27
  idBotGoal *v47; // r21
  int v48; // r7
  bool v49; // r6
  idPlayer *v50; // r5
  int v51; // r9
  idEntity *v52; // r3
  idEntity *v53; // r3
  idEntity *v54; // r26
  idEntityPtr<idAI2> *list; // r30
  int v56; // r28
  int v57; // r29
  int v58; // r9
  idPlayer *v59; // r3
  idEntity *v60; // r30
  idPlayer *v61; // r3
  idPresentable *presentable; // r3
  int v63; // r3
  gameTeam_t v64; // r15
  gameTeam_t v65; // r14
  idGameChallenge *v66; // r3
  unsigned int v67; // r7
  int v68; // r10
  idClientGame *v69; // r11
  unsigned int v70; // r7
  int v71; // r5
  int v72; // r5
  idEntity *v73; // r3
  idEntity *v74; // r3
  idPhysics *v75; // r3
  const idVec3 *v76; // r3
  int v77; // r7
  bool v78; // r6
  int v79; // [sp+50h] [-E0h]
  idEntityPtr<idAI2> v80; // [sp+58h] [-D8h] BYREF
  idList<idEntityPtr<idAI2>,5> v81; // [sp+60h] [-D0h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v4 = DebugPlayer;
  if ( DebugPlayer == nullptr )
    goto LABEL_33;
  if ( DebugPlayer->IsDead(this: DebugPlayer) || (Noclip = idPlayer::GetNoclip(this: v4), v6 = 1, Noclip) )
    v6 = 0;
  v7 = v6;
  v9 = v6 == 0;
  v8 = gameLocal;
  if ( !v9 )
  {
    num = gameLocal->botEntities.num;
    v11 = 0;
    if ( num > 0 )
    {
      v12 = 0;
      do
      {
        value = v8->botEntities.list[v12].spawnId.value;
        if ( v8->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v14 = (idPlayer *)v8->entities.ptr[value & 0x1FFF];
          if ( v14 != nullptr )
          {
            v15 = idPlayer::CastTo(c: v14);
            v16 = v15;
            if ( v15 != nullptr )
            {
              Team = idEntity::GetTeam(this: v15);
              v18 = idEntity::GetTeam(this: v4);
              ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
              if ( !idGameChallenge::IsHostile(this: ChallengeEntity, team1: v18, team2: Team) )
              {
                BotGoalTask = idPlayer::GetBotGoalTask(this: v16);
                if ( BotGoalTask != nullptr && (BotGoalTask->goalType.flags & 4) != 0 )
                {
                  v8 = gameLocal;
                  v7 = 0;
                  break;
                }
              }
            }
            v8 = gameLocal;
          }
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  if ( v7 != 0 )
  {
    Physics = idEntity::GetPhysics(this: v4);
    v22 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v8 = gameLocal;
    v23 = (float *)v22;
    v24 = nullptr;
    v25 = 1.0e30;
    if ( gameLocal->botEntities.num > 0 )
    {
      v26 = gameLocal->botEntities.num;
      v27 = 0;
      do
      {
        v28 = v8->botEntities.list[v27].spawnId.value;
        if ( v8->spawnIds.ptr[v28 & 0x1FFF] == v28 >> 13 )
        {
          v29 = (idPlayer *)v8->entities.ptr[v28 & 0x1FFF];
          if ( v29 != nullptr )
          {
            v30 = idPlayer::CastTo(c: v29);
            v31 = v30;
            if ( v30 != nullptr && !v30->IsDead(this: v30) )
            {
              v32 = idEntity::GetTeam(this: v31);
              v33 = idEntity::GetTeam(this: v4);
              v34 = idGameLocal::GetChallengeEntity(this: gameLocal);
              if ( !idGameChallenge::IsHostile(this: v34, team1: v33, team2: v32)
                && (int)&v31[15].__vftable[7].ClientThink >= curTime )
              {
                v35 = idEntity::GetPhysics(this: v31);
                v36 = (float *)v35->GetOrigin(this: v35, a2: 0);
                v37 = (float)(v36[1] - v23[1]);
                v38 = (float)(v36[2] - v23[2]);
                if ( (float)((float)((float)v38 * (float)v38)
                           + (float)((float)((float)(*v36 - *v23) * (float)(*v36 - *v23))
                                   + (float)((float)v37 * (float)v37))) < v25 )
                {
                  v25 = (float)((float)((float)v38 * (float)v38)
                              + (float)((float)((float)(*v36 - *v23) * (float)(*v36 - *v23))
                                      + (float)((float)v37 * (float)v37)));
                  v24 = (idPlayer *)v31;
                }
              }
            }
            v8 = gameLocal;
          }
        }
        --v26;
        ++v27;
      }
      while ( v26 != 0 );
      if ( v24 != nullptr )
      {
        v39 = idPlayer::GetBotGoalTask(this: v24);
        idBotGoal::GoalManager_InitEntityGoal(
          this: v39,
          goalFlags: 4,
          newGoalEntity: v4,
          newGoalRadius: 128.0,
          combatMaxRange: 768.0,
          clearEnemy: v41,
          a7: v40,
          a8: 1);
LABEL_33:
        v8 = gameLocal;
      }
    }
  }
  if ( v8->botEntities.num > 0 )
  {
    v79 = v8->botEntities.num;
    v42 = 0;
    do
    {
      v43 = v8->botEntities.list[v42].spawnId.value;
      if ( v8->spawnIds.ptr[v43 & 0x1FFF] == v43 >> 13 )
      {
        v44 = (idPlayer *)v8->entities.ptr[v43 & 0x1FFF];
        if ( v44 != nullptr )
        {
          v45 = idPlayer::CastTo(c: v44);
          v46 = v45;
          if ( v45 != nullptr )
          {
            v47 = idPlayer::GetBotGoalTask(this: v45);
            if ( v47 != nullptr )
            {
              if ( bot_followPlayer.valueInteger != 0 && (v50 = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
              {
                idBotGoal::GoalManager_InitEntityGoal(
                  this: v47,
                  goalFlags: 4,
                  newGoalEntity: v50,
                  newGoalRadius: 128.0,
                  combatMaxRange: 768.0,
                  clearEnemy: v49,
                  a7: v48,
                  a8: 1);
              }
              else if ( v47->goalType.flags == 0x80000000 )
              {
                v51 = v47->goalEnemy.spawnId.value;
                v8 = gameLocal;
                v80.spawnId.value = (int)&v47->goalEnemy;
                if ( gameLocal->spawnIds.ptr[v51 & 0x1FFF] == v51 >> 13
                  && (v52 = gameLocal->entities.ptr[v51 & 0x1FFF]) != nullptr )
                {
                  v53 = idEntity::CastTo(c: v52);
                  v8 = gameLocal;
                }
                else
                {
                  v53 = nullptr;
                }
                v54 = v53;
                if ( v53 == nullptr )
                {
                  list = nullptr;
                  *(_WORD *)&v81.memTag = 1280;
                  memset(&v81, 0, 14);
                  if ( v8->playerEntities.num > 0 )
                  {
                    v56 = v8->playerEntities.num;
                    v57 = 0;
                    do
                    {
                      v58 = v8->playerEntities.list[v57].spawnId.value;
                      if ( v8->spawnIds.ptr[v58 & 0x1FFF] == v58 >> 13 )
                      {
                        v59 = (idPlayer *)v8->entities.ptr[v58 & 0x1FFF];
                        if ( v59 != nullptr )
                        {
                          v61 = idPlayer::CastTo(c: v59);
                          v8 = gameLocal;
                          v60 = v61;
                        }
                        else
                        {
                          v60 = nullptr;
                        }
                      }
                      else
                      {
                        v60 = nullptr;
                      }
                      if ( v60 != v46 )
                      {
                        if ( !v60->IsDead(this: v60) )
                        {
                          presentable = v60->presentable;
                          v63 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
                          if ( (*(_BYTE *)(v63 + 47032) & 0x20) == 0 && (v60[16].name.baseBuffer[0] & 8) == 0 )
                          {
                            v64 = idEntity::GetTeam(this: v46);
                            v65 = idEntity::GetTeam(this: v60);
                            v66 = idGameLocal::GetChallengeEntity(this: gameLocal);
                            if ( idGameChallenge::IsHostile(this: v66, team1: v65, team2: v64)
                              || (v67 = 1664525 * clientGame->random.seed + 1013904223,
                                  clientGame->random.seed = v67,
                                  ((v67 >> 10) & 0x7FFF) % 0x64 <= 0xA) )
                            {
                              v80.spawnId.value = v60->entityNumber;
                              v80.spawnId.value |= gameLocal->spawnIds.ptr[v80.spawnId.value] << 13;
                              idList<idEntityPtr<idEntity>,5>::AddUnique(this: &v81, obj: &v80);
                            }
                          }
                        }
                        v8 = gameLocal;
                      }
                      --v56;
                      ++v57;
                    }
                    while ( v56 != 0 );
                    list = v81.list;
                    v68 = v81.num;
                    if ( v81.num > 0 )
                    {
                      v69 = clientGame;
                      __twllei(v81.num, 0);
                      v70 = 1664525 * v69->random.seed + 1013904223;
                      v69->random.seed = v70;
                      v8 = gameLocal;
                      v71 = (v70 >> 10) & 0x7FFF;
                      __twlgei(v68 & ~(__ROL4__(v71, 1) - 1), 0xFFFFFFFF);
                      v72 = list[v71 % v68].spawnId.value;
                      if ( v8->spawnIds.ptr[v72 & 0x1FFF] == v72 >> 13
                        && (v73 = v8->entities.ptr[v72 & 0x1FFF]) != nullptr )
                      {
                        v74 = idEntity::CastTo(c: v73);
                        v8 = gameLocal;
                      }
                      else
                      {
                        v74 = nullptr;
                      }
                      v54 = v74;
                    }
                  }
                  if ( v81.listStatic == 0 || v81.listStatic == 2 )
                  {
                    if ( list != nullptr )
                    {
                      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
                      v8 = gameLocal;
                    }
                    v81.list = nullptr;
                    v81.size = 0;
                  }
                  v81.num = 0;
                  if ( v54 == nullptr )
                    goto LABEL_82;
                }
                v75 = idEntity::GetPhysics(this: v54);
                v76 = v75->GetOrigin(this: v75, a2: 0);
                idBotGoal::GoalManager_InitPosGoal(
                  this: v47,
                  goalFlags: 128,
                  newGoalPos: v76,
                  newGoalRadius: 256.0,
                  combatMaxRange: 2048.0,
                  clearEnemy: v78,
                  a7: v77,
                  a8: 0);
              }
            }
          }
          v8 = gameLocal;
        }
      }
LABEL_82:
      ++v42;
      --v79;
    }
    while ( v79 != 0 );
  }
}


// ========================================================================
// __unwind$488858_0
// EA  : 0x82B49F80
// RVA : 0x00B49F80
// PDB : w:\tech5\tungsten\game\bot\global\bot_goalmanager.cpp
// ========================================================================

void _unwind_488858_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 304 + 96));
}


// ========================================================================
// `dynamic initializer for 'bot_followPlayer''
// EA  : 0x8336CF30
// RVA : 0x0136CF30
// PDB : w:\tech5\tungsten\game\bot\global\bot_goalmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_followPlayer__()
{
  idCVar::idCVar(
    this: &bot_followPlayer,
    name: "bot_followPlayer",
    value: "0",
    flags: 1,
    description: "1 = all bots follow Player 0 - useful for testing.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_followPlayer__);
}

