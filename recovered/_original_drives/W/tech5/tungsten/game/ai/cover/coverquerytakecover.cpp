
// ========================================================================
// ?InternalScoreCover@idCoverQueryTakeCover@@MAAMABUcoverCache_t@idCoverQuery@@@Z
// EA  : 0x82A8D580
// RVA : 0x00A8D580
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

float __fastcall idCoverQueryTakeCover::InternalScoreCover(
        idCoverQueryTakeCover *this,
        const idCoverQuery::coverCache_t *cached)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idAICover *v6; // r22
  idEntityPtr<idEntity const > *p_currentEnemy; // r9
  idEntity *v8; // r3
  double v9; // fp1
  const aas2Cover_t *Origin; // r3
  double v11; // fp31
  const aas2Cover_t *v12; // r3
  idAI2 *ai; // r11
  const idEntity *Enemy; // r3
  idAI2 *v15; // r11
  float *decl; // r23
  int entityNumber; // r29
  bool v18; // r21
  idEncounterGroup *EncounterGroup; // r24
  unsigned __int64 v20; // r6
  const char *v21; // r7
  int curCombatStage; // r11
  idCombatStage *v23; // r27
  bool v24; // r28
  idAI2 *Entity; // r3
  idAI2 *v26; // r3
  idAI2 *v27; // r11
  idAICombatHint::combatHintClass_t combatHintClass; // r28
  encounterGroupRole_t currentRole; // r29
  const aas2Cover_t *v30; // r3
  const aas2Cover_t *v31; // r3
  bool IsPartiallyExposed; // r16
  bool IsFullyExposed; // r29
  idPlayer *v34; // r19
  const idPlayerCoverScore_t *v35; // r20
  idPlayer *v36; // r3
  idPlayer *v37; // r3
  const idPlayerCoverScore_t *CoverScoreInfo; // r3
  const aas2Cover_t *v39; // r3
  double v40; // fp31
  bool v41; // r27
  int AreaNum; // r15
  int v43; // r14
  int v44; // r6
  bool v45; // r10
  const aas2Cover_t *v46; // r3
  idPLog *v47; // r15
  unsigned __int64 v48; // r6
  const char *v49; // r7
  const aas2Cover_t *v50; // r3
  double v51; // fp9
  double v52; // fp5
  double v53; // fp30
  idAI2 *v54; // r4
  const idAAS2 *aas; // r15
  int travelFlags; // r14
  idAAS2_vtbl *v57; // r27
  int v58; // r29
  int v59; // r3
  int v60; // r3
  double v61; // fp13
  const aas2Cover_t *v62; // r3
  unsigned __int64 v63; // r6
  const char *v64; // r7
  idAI2 *v65; // r11
  double v66; // fp0
  double v67; // fp22
  double v68; // fp23
  const aas2Cover_t *v69; // r3
  double v70; // fp24
  unsigned __int64 v71; // r6
  const char *v72; // r7
  int num; // r11
  int v74; // r28
  int v75; // r29
  idAI2 *v76; // r3
  idPhysics *Physics; // r3
  int v78; // r3
  double y; // fp13
  float v80; // r8
  double x; // fp11
  float v82; // r7
  double z; // fp10
  double v84; // fp12
  double v85; // fp13
  unsigned __int64 v86; // r6
  const char *v87; // r7
  double v88; // fp26
  const idAAS2 *v89; // r29
  int v90; // r3
  double v91; // fp27
  unsigned __int64 v92; // r6
  const char *v93; // r7
  double v94; // fp1
  double v95; // fp29
  double v96; // fp30
  const aas2Cover_t *v97; // r3
  int v98; // r10
  int v99; // r9
  int v100; // r8
  int v101; // r7
  int v102; // r6
  const idVec3 *v103; // r5
  const idVec3 *v104; // r4
  float v106; // [sp+8h] [-2D8h]
  float v107; // [sp+Ch] [-2D4h]
  float v108; // [sp+10h] [-2D0h]
  float v109; // [sp+14h] [-2CCh]
  float v110; // [sp+18h] [-2C8h]
  float v111; // [sp+1Ch] [-2C4h]
  float v112; // [sp+20h] [-2C0h]
  float v113; // [sp+24h] [-2BCh]
  float v114; // [sp+28h] [-2B8h]
  float v115; // [sp+2Ch] [-2B4h]
  float v116; // [sp+30h] [-2B0h]
  float v117; // [sp+34h] [-2ACh]
  float v118; // [sp+38h] [-2A8h]
  float v119; // [sp+3Ch] [-2A4h]
  float v120; // [sp+40h] [-2A0h]
  float v121; // [sp+44h] [-29Ch]
  float v122; // [sp+48h] [-298h]
  float v123; // [sp+4Ch] [-294h]
  float v124; // [sp+50h] [-290h]
  float v125; // [sp+54h] [-28Ch]
  float v126; // [sp+58h] [-288h]
  float v127; // [sp+5Ch] [-284h]
  float v128; // [sp+60h] [-280h]
  float v129; // [sp+68h] [-278h]
  float v130; // [sp+70h] [-270h]
  idPLogScope v131; // [sp+80h] [-260h] BYREF
  unsigned __int64 v132; // [sp+88h] [-258h] BYREF
  float v133; // [sp+90h] [-250h]
  idPLog *v134; // [sp+94h] [-24Ch]
  idPLogScope v135; // [sp+98h] [-248h] BYREF
  idPLogScope v136; // [sp+A0h] [-240h] BYREF
  idPLogScope v137; // [sp+A8h] [-238h] BYREF
  idPLogScope v138[2]; // [sp+B0h] [-230h] BYREF
  int v139; // [sp+C0h] [-220h] BYREF
  idStaticList<idAI2 *,64> v140; // [sp+D0h] [-210h] BYREF

  RD_EventBegin(name: "idCoverQueryTakeCover::InternalScoreCover");
  LODWORD(v4) = "idCoverQueryTakeCover::InternalScoreCover";
  HIDWORD(v4) = 2;
  v134 = &pLog;
  idPLogScope::idPLogScope(this: &v131, pl: &pLog, gMask: v4, label: v5);
  v6 = &this->ai->aiVolatile.coverManager.knownCover.list[cached->index];
  if ( (unsigned __int8)idAICover::IsValid(this: v6) != 0 )
  {
    p_currentEnemy = &this->ai->aiVolatile.memory.currentEnemy;
    HIDWORD(v132) = p_currentEnemy;
    if ( gameLocal->spawnIds.ptr[p_currentEnemy->spawnId.value & 0x1FFF] == p_currentEnemy->spawnId.value >> 13 )
    {
      v8 = gameLocal->entities.ptr[p_currentEnemy->spawnId.value & 0x1FFF];
      if ( v8 != nullptr && idEntity::CastTo(c: v8) != nullptr && (unsigned __int8)idAICover::ShouldAvoid(this: v6) == 0 )
      {
        if ( !idAICover::IsPointInFrontOf(this: v6, point: &this->target.origin) )
        {
          Origin = idAICover::GetOrigin(this: v6);
          v11 = idCoverQuery::DebugFailedTarget(
                  this,
                  message: "BEHIND",
                  origin: &Origin->origin,
                  targetOrigin: &this->target.origin,
                  minLevel: 1);
          idPLogScope::~idPLogScope(this: &v131);
LABEL_102:
          RD_EventEnd();
          v9 = v11;
          return *((float *)&v9 + 1);
        }
        if ( !idAICover::IsPointInArc(
                this: v6,
                point: &this->target.origin,
                arcAcos: idCoverQuery::MAX_COVER_ARC_ACOS_DEGREES) )
        {
          v12 = idAICover::GetOrigin(this: v6);
          v11 = idCoverQuery::DebugFailedTarget(
                  this,
                  message: "NOT_IN_ARC",
                  origin: &v12->origin,
                  targetOrigin: &this->target.origin,
                  minLevel: 1);
          idPLogScope::~idPLogScope(this: &v131);
          goto LABEL_102;
        }
        ai = this->ai;
        if ( (*((_BYTE *)&ai->aiEditable.cover + 8) & 0x80) != 0 )
        {
          Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
          if ( idGameLocal::GetSpawnId(this: (idGameLocal *)&v132, result: (idSpawnId *)gameLocal, ent: Enemy)->value != this->target.spawnId.value
            && this->target.confirmedTime >= 0
            && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
             - this->target.confirmedTime > 5000 )
          {
            idPLogScope::~idPLogScope(this: &v131);
            RD_EventEnd();
            v9 = 1.0;
            return *((float *)&v9 + 1);
          }
        }
        v15 = this->ai;
        decl = (float *)v15->aiEditable.behaviors.decl;
        entityNumber = idAIMemory::GetEnemy(this: &v15->aiVolatile.memory)->entityNumber;
        v18 = (_cntlzw(entityNumber - idSpawnId::GetEntityNumber(this: &this->target.spawnId)) & 0x20) != 0;
        EncounterGroup = idAI2::GetEncounterGroup(this: this->ai);
        RD_EventBegin(name: "idCoverQueryTakeCover::InternalScoreCover - encounter group");
        LODWORD(v20) = "idCoverQueryTakeCover::InternalScoreCover - encounter group";
        HIDWORD(v20) = 2;
        idPLogScope::idPLogScope(this: (idPLogScope *)&v132, pl: &pLog, gMask: v20, label: v21);
        if ( EncounterGroup != nullptr )
        {
          curCombatStage = EncounterGroup->curCombatStage;
          if ( curCombatStage >= 0 && curCombatStage < EncounterGroup->combatStages.num )
          {
            v23 = &EncounterGroup->combatStages.list[curCombatStage];
            if ( v23 != nullptr && this->ai->aiVolatile.groupStatus.currentRole != ROLE_NONE )
            {
              v24 = false;
              if ( v6->spawnId.value != 0x1FFF )
              {
                Entity = (idAI2 *)idEventArg::GetEntity(this: v6);
                v26 = idAI2::CastTo(c: Entity);
                if ( v26 != nullptr )
                  v24 = v26->aiVolatile.groupStatus.currentRole == this->ai->aiVolatile.groupStatus.currentRole;
              }
              if ( !v24 )
              {
                v27 = this->ai;
                combatHintClass = v27->aiEditable.movement.combatHintClass;
                currentRole = v27->aiVolatile.groupStatus.currentRole;
                v30 = idAICover::GetOrigin(this: v6);
                if ( idCombatStage::GetRolePositionWeight(
                       this: v23,
                       role: currentRole,
                       pos: &v30->origin,
                       hintClass: combatHintClass) == 0.0 )
                {
                  v31 = idAICover::GetOrigin(this: v6);
                  v11 = idCoverQuery::DebugFailed(this, message: "ROLE", origin: &v31->origin, minLevel: 2);
                  idPLogScope::~idPLogScope(this: (idPLogScope *)&v132);
                  RD_EventEnd();
                  idPLogScope::~idPLogScope(this: &v131);
                  goto LABEL_102;
                }
              }
            }
          }
        }
        idPLogScope::~idPLogScope(this: (idPLogScope *)&v132);
        RD_EventEnd();
        IsPartiallyExposed = idAICover::IsPartiallyExposed(this: v6);
        IsFullyExposed = idAICover::IsFullyExposed(this: v6);
        v34 = nullptr;
        v35 = nullptr;
        if ( g_usePlayerCoverCheck.valueInteger != 0 )
        {
          v36 = (idPlayer *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: this->target.spawnId.value);
          v37 = idPlayer::CastTo(c: v36);
          v34 = v37;
          if ( v37 != nullptr )
          {
            CoverScoreInfo = idPlayer::GetCoverScoreInfo(this: v37, coverIndex: v6->coverIndex);
            v35 = CoverScoreInfo;
            if ( CoverScoreInfo != nullptr
              && !IsFullyExposed
              && CoverScoreInfo->standingScore > (double)ai_deferredVisCheckThreshold.valueFloat )
            {
              v39 = idAICover::GetOrigin(this: v6);
              v11 = idCoverQuery::DebugFailedTarget(
                      this,
                      message: "TARGET_VISIBLE",
                      origin: &v39->origin,
                      targetOrigin: &this->target.origin,
                      minLevel: 1);
              idPLogScope::~idPLogScope(this: &v131);
              goto LABEL_102;
            }
          }
          else
          {
            v35 = nullptr;
          }
        }
        v40 = decl[130];
        v41 = this->debugLevel != 0;
        AreaNum = idAASPosition::GetAreaNum(this: &this->target.aiPos);
        v43 = idAASPosition::GetAreaNum(this: &cached->aiPos);
        v44 = idAASPosition::GetAreaNum(this: &this->aiaiPos);
        LOBYTE(v125) = v41;
        if ( (unsigned __int8)idAI2::PathPassesNear(
                                this: this->ai,
                                startPoint: &this->aiaiPos.origin,
                                goalPoint: &cached->aiPos.origin,
                                startAreaNum: v44,
                                goalAreaNum: v43,
                                testPoint: &this->target.aiPos.origin,
                                testAreaNum: AreaNum,
                                nearDist: v40,
                                debug: v45) != 0 )
        {
          v46 = idAICover::GetOrigin(this: v6);
          v11 = idCoverQuery::DebugFailedTarget(
                  this,
                  message: "PATH_NEAR",
                  origin: &v46->origin,
                  targetOrigin: &this->target.origin,
                  minLevel: 1);
          idPLogScope::~idPLogScope(this: &v131);
          goto LABEL_102;
        }
        RD_EventBegin(name: "idCoverQueryTakeCover::InternalScoreCover - travel time");
        v47 = v134;
        LODWORD(v48) = "idCoverQueryTakeCover::InternalScoreCover - travel time";
        HIDWORD(v48) = 2;
        idPLogScope::idPLogScope(this: &v135, pl: v134, gMask: v48, label: v49);
        v50 = idAICover::GetOrigin(this: v6);
        v51 = (float)(this->target.aiPos.origin.y - v50->origin.y);
        v52 = (float)(this->target.aiPos.origin.z - v50->origin.z);
        v53 = __fsqrts((float)((float)((float)v52 * (float)v52)
                             + (float)((float)((float)(this->target.aiPos.origin.x - v50->origin.x)
                                             * (float)(this->target.aiPos.origin.x - v50->origin.x))
                                     + (float)((float)v51 * (float)v51))));
        if ( v53 < decl[125] && idAASPosition::GetAreaNum(this: &cached->aiPos) > 0 )
        {
          v54 = this->ai;
          aas = this->target.aiPos.aas;
          travelFlags = v54->aiVolatile.aas.travelFlags;
          v57 = aas->__vftable;
          HIDWORD(v132) = idAI2::GetTravelSpeeds(this: (idAI2 *)&v139, result: (idAAS2TravelSpeeds *)v54);
          v58 = idAASPosition::GetAreaNum(this: &cached->aiPos);
          v59 = idAASPosition::GetAreaNum(this: &this->target.aiPos);
          v60 = v57->TravelTimeToGoalArea(
                  this: (idAAS2 *)aas,
                  a2: v59,
                  a3: &this->target.aiPos.origin,
                  a4: v58,
                  a5: &cached->aiPos.origin,
                  a6: travelFlags,
                  a7: (const idAAS2TravelSpeeds *)HIDWORD(v132));
          if ( v60 > 0 )
          {
            v61 = decl[128];
            v132 = __PAIR64__(byte_821B0000, v60);
            if ( (float)((float)__SPAIR64__(byte_821B0000, v60) * (float)0.0099999998) < v61 )
            {
              v62 = idAICover::GetOrigin(this: v6);
              v11 = idCoverQuery::DebugFailedTarget(
                      this,
                      message: "TARGET_CLOSE",
                      origin: &v62->origin,
                      targetOrigin: &this->target.origin,
                      minLevel: 1);
              idPLogScope::~idPLogScope(this: &v135);
              RD_EventEnd();
              idPLogScope::~idPLogScope(this: &v131);
              goto LABEL_102;
            }
          }
          v47 = v134;
        }
        idPLogScope::~idPLogScope(this: &v135);
        RD_EventEnd();
        RD_EventBegin(name: "idCoverQuertyTakeCover_InternalScoreCover_Misc");
        LODWORD(v63) = "idCoverQuertyTakeCover_InternalScoreCover_Misc";
        HIDWORD(v63) = 2;
        idPLogScope::idPLogScope(this: &v136, pl: v47, gMask: v63, label: v64);
        v65 = this->ai;
        if ( (v65->aiVolatile.groupStatus.condition & 8) != 0 )
          v66 = 1.0;
        else
          v66 = 0.25;
        v67 = 1.0;
        if ( v18 )
        {
          v67 = (float)((float)1.0 / (float)((float)(cached->travelTime * (float)v66) + (float)1.0));
          if ( v67 >= 0.0 )
          {
            if ( v67 > 1.0 )
              v67 = 1.0;
          }
          else
          {
            v67 = 0.0;
          }
        }
        v68 = 0.0;
        if ( v53 < decl[126] )
        {
          v69 = idAICover::GetOrigin(this: v6);
          v11 = idCoverQuery::DebugFailedTarget(
                  this,
                  message: "TARGET_NEAR",
                  origin: &v69->origin,
                  targetOrigin: &this->target.origin,
                  minLevel: 1);
          idPLogScope::~idPLogScope(this: &v136);
          RD_EventEnd();
          idPLogScope::~idPLogScope(this: &v131);
          goto LABEL_102;
        }
        if ( v53 >= decl[127] )
        {
          if ( v18 )
          {
            if ( v53 < v65->aiEditable.cover.maxEnemyCoverDistance )
              v68 = (float)((float)1.0
                          - (float)((float)((float)v53 - decl[127])
                                  / (float)(v65->aiEditable.cover.maxEnemyCoverDistance - decl[127])));
          }
          else
          {
            v68 = 1.0;
          }
        }
        else
        {
          v68 = (float)((float)v53 / decl[127]);
        }
        idPLogScope::End(this: &v136, totalTicks: nullptr);
        v70 = 1.0;
        if ( v18 )
        {
          RD_EventBegin(name: "idCoverQueryTakeCover::InternalScoreCover - group score");
          LODWORD(v71) = "idCoverQueryTakeCover::InternalScoreCover - group score";
          HIDWORD(v71) = 2;
          idPLogScope::idPLogScope(this: &v135, pl: v47, gMask: v71, label: v72);
          v140.granularity = 1;
          num = 0;
          v140.size = 64;
          v140.memTag = 5;
          v140.num = 0;
          v140.list = v140.staticList;
          v140.listStatic = 1;
          if ( EncounterGroup != nullptr )
          {
            idEncounterGroup::GetLivingMembers(this: EncounterGroup, list: &v140);
            num = v140.num;
          }
          if ( num > 0 )
          {
            v74 = num;
            v75 = 0;
            do
            {
              v76 = v140.list[v75];
              if ( v76 != this->ai
                && (v6->spawnId.value == 0x1FFF
                 || (*(_BYTE *)&v76->aiEditable.behaviors.decl->dynamicCoverCaps & 0x20) == 0) )
              {
                Physics = idEntity::GetPhysics(this: v76);
                v78 = (int)Physics->GetOrigin(this: Physics, a2: 0);
                y = cached->aiPos.origin.y;
                v80 = *(float *)(v78 + 8);
                x = cached->aiPos.origin.x;
                v82 = *(float *)(v78 + 4);
                z = cached->aiPos.origin.z;
                v84 = 1.0;
                HIDWORD(v132) = *(_DWORD *)v78;
                v133 = v80;
                *((float *)&v132 + 1) = v82;
                v85 = __fsqrts((float)((float)((float)(v80 - (float)z) * (float)(v80 - (float)z))
                                     + (float)((float)((float)(*(float *)&v132 - (float)x)
                                                     * (float)(*(float *)&v132 - (float)x))
                                             + (float)((float)(v82 - (float)y) * (float)(v82 - (float)y)))));
                if ( v85 < (float)((float)(UNITS_PER_INCH_5 * (float)20.0) * (float)12.0) )
                  v84 = (float)-(float)((float)((float)((float)1.0
                                                      - (float)((float)v85
                                                              / (float)((float)(UNITS_PER_INCH_5 * (float)20.0)
                                                                      * (float)12.0)))
                                              * (float)0.5)
                                      - (float)1.0);
                v70 = (float)((float)v84 * (float)v70);
              }
              --v74;
              ++v75;
            }
            while ( v74 != 0 );
          }
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v140);
          idPLogScope::~idPLogScope(this: &v135);
          RD_EventEnd();
        }
        RD_EventBegin(name: "idCoverQuertyTakeCover_InternalScoreCover_Misc2");
        LODWORD(v86) = "idCoverQuertyTakeCover_InternalScoreCover_Misc2";
        HIDWORD(v86) = 2;
        idPLogScope::idPLogScope(this: &v137, pl: v47, gMask: v86, label: v87);
        if ( IsPartiallyExposed )
          idAICover::IsExplicit(this: v6);
        if ( !v18 )
          goto LABEL_85;
        if ( v34 == nullptr )
        {
          v89 = this->target.vcPos.aas;
          v90 = idAASPosition::GetAreaNum(this: &this->target.vcPos);
          v88 = (float)((float)(idAICover::VisibilityRatioFromFirePoints(
                                  this: v6,
                                  user: this->ai,
                                  aas: v89,
                                  areaNum: v90)
                              * (float)0.60000002)
                      + (float)0.40000001);
          goto LABEL_81;
        }
        if ( v35 != nullptr )
        {
          v88 = (float)((float)(v35->firePointScore * (float)0.60000002) + (float)0.40000001);
          goto LABEL_86;
        }
        if ( v6->spawnId.value == 0x1FFF )
          v88 = 0.40000001;
        else
LABEL_85:
          v88 = 1.0;
LABEL_86:
        if ( v34 != nullptr )
        {
          if ( v35 != nullptr )
          {
            v91 = (float)((float)((float)((float)1.0 - v35->standingScore) * (float)0.89999998) + (float)0.1);
            goto LABEL_82;
          }
          if ( v6->spawnId.value == 0x1FFF )
          {
            v91 = 0.1;
LABEL_82:
            idPLogScope::End(this: &v137, totalTicks: nullptr);
            RD_EventBegin(name: "idCoverQuertyTakeCover_InternalScoreCover_Angle");
            LODWORD(v92) = "idCoverQuertyTakeCover_InternalScoreCover_Angle";
            HIDWORD(v92) = 2;
            idPLogScope::idPLogScope(this: v138, pl: v47, gMask: v92, label: v93);
            v94 = idAICover::AngleToPoint(this: v6, point: &this->target.aiPos.origin, considerFireOver: true);
            if ( v18 || v94 >= 0.0 )
            {
              if ( v94 < -15.0 || v94 > (float)((float)110.0 * (float)0.5) )
              {
                v95 = 0.0;
              }
              else if ( v94 <= 0.0 )
              {
                v95 = (float)((float)((float)((float)-15.0 - (float)v94) * (float)-0.06666667) * (float)0.25);
              }
              else
              {
                v95 = (float)((float)((float)((float)((float)((float)110.0 * (float)0.5) - (float)v94)
                                            / (float)((float)110.0 * (float)0.5))
                                    + (float)1.0)
                            * (float)0.5);
              }
            }
            else
            {
              v95 = 1.0;
            }
            idPLogScope::End(this: v138, totalTicks: nullptr);
            v96 = (float)((float)((float)((float)((float)((float)(idAIMemory::GetHistoryScore(
                                                                    this: &this->ai->aiVolatile.memory,
                                                                    _Cover: v6)
                                                                * (float)v95)
                                                        * (float)v91)
                                                * (float)v88)
                                        * (float)v70)
                                * (float)v68)
                        * (float)v67);
            if ( v96 >= 0.0 )
            {
              if ( v96 > 1.0 )
                v96 = 1.0;
            }
            else
            {
              v96 = 0.0;
            }
            v97 = idAICover::GetOrigin(this: v6);
            v11 = idCoverQuery::DebugSucceeded(
                    this,
                    score: v96,
                    targetScore: v68,
                    aiScore: v67,
                    angleScore: v95,
                    groupScore: v70,
                    enemyVisibilityScore: v88,
                    aiVisibilityScore: v91,
                    miscScore: 1.0,
                    coverOrigin: v104,
                    targetOrigin: v103,
                    minLevel: v102,
                    a13: v101,
                    a14: v100,
                    a15: v99,
                    a16: v98,
                    angle: v106,
                    a18: v107,
                    a19: v108,
                    a20: v109,
                    a21: v110,
                    a22: v111,
                    a23: v112,
                    a24: v113,
                    a25: v114,
                    a26: v115,
                    a27: v116,
                    a28: v117,
                    a29: v118,
                    a30: v119,
                    a31: v120,
                    a32: v121,
                    a33: v122,
                    a34: v123,
                    a35: v124,
                    a36: v125,
                    a37: v126,
                    a38: v127,
                    a39: v128,
                    a40: &v97->origin.x,
                    a41: v129,
                    a42: &this->target.aiPos.origin.x,
                    a43: v130,
                    a44: 1);
            idPLogScope::~idPLogScope(this: v138);
            RD_EventEnd();
            idPLogScope::~idPLogScope(this: &v137);
            RD_EventEnd();
            idPLogScope::~idPLogScope(this: &v136);
            RD_EventEnd();
            idPLogScope::~idPLogScope(this: &v131);
            goto LABEL_102;
          }
        }
LABEL_81:
        v91 = 1.0;
        goto LABEL_82;
      }
    }
  }
  idPLogScope::~idPLogScope(this: &v131);
  RD_EventEnd();
  v9 = 0.0;
  return *((float *)&v9 + 1);
}


// ========================================================================
// __unwind$488109
// EA  : 0x82A8E198
// RVA : 0x00A8E198
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488109()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 480));
}


// ========================================================================
// __unwind$488110
// EA  : 0x82A8E1C0
// RVA : 0x00A8E1C0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488110()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 128));
}


// ========================================================================
// __unwind$488111
// EA  : 0x82A8E1E8
// RVA : 0x00A8E1E8
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488111()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 481));
}


// ========================================================================
// __unwind$488112
// EA  : 0x82A8E210
// RVA : 0x00A8E210
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488112()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 136));
}


// ========================================================================
// __unwind$488113
// EA  : 0x82A8E238
// RVA : 0x00A8E238
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488113()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 482));
}


// ========================================================================
// __unwind$488114
// EA  : 0x82A8E260
// RVA : 0x00A8E260
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488114()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 152));
}


// ========================================================================
// __unwind$488115
// EA  : 0x82A8E288
// RVA : 0x00A8E288
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488115()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 483));
}


// ========================================================================
// __unwind$488116
// EA  : 0x82A8E2B0
// RVA : 0x00A8E2B0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488116()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 160));
}


// ========================================================================
// __unwind$488117
// EA  : 0x82A8E2D8
// RVA : 0x00A8E2D8
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488117()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 484));
}


// ========================================================================
// __unwind$488118
// EA  : 0x82A8E300
// RVA : 0x00A8E300
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488118()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 152));
}


// ========================================================================
// __unwind$488119
// EA  : 0x82A8E328
// RVA : 0x00A8E328
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488119()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 736 + 208));
}


// ========================================================================
// __unwind$488120
// EA  : 0x82A8E350
// RVA : 0x00A8E350
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488120()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 485));
}


// ========================================================================
// __unwind$488121
// EA  : 0x82A8E378
// RVA : 0x00A8E378
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488121()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 168));
}


// ========================================================================
// __unwind$488122
// EA  : 0x82A8E3A0
// RVA : 0x00A8E3A0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488122()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 486));
}


// ========================================================================
// __unwind$488123
// EA  : 0x82A8E3C8
// RVA : 0x00A8E3C8
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void _unwind_488123()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 176));
}


// ========================================================================
// `dynamic initializer for 'ai_deferredVisCheckThreshold''
// EA  : 0x83369030
// RVA : 0x01369030
// PDB : w:\tech5\tungsten\game\ai\cover\coverquerytakecover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_deferredVisCheckThreshold__()
{
  idCVar::idCVar(
    this: &ai_deferredVisCheckThreshold,
    name: "ai_deferredVisCheckThreshold",
    value: "1.0",
    flags: 4,
    description: "deferred vis check threshold",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_deferredVisCheckThreshold__);
}

