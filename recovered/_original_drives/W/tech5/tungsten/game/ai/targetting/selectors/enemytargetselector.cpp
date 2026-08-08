
// ========================================================================
// ?GetWeight@idEnemyTargetSelector@@UBAMPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B02350
// RVA : 0x00B02350
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\enemytargetselector.cpp
// ========================================================================

float __fastcall idEnemyTargetSelector::GetWeight(idEnemyTargetSelector *this, idAI2 *owner, const idTargetInfo *ti)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idAI2 *v8; // r30
  idActor *Entity; // r25
  idActor *v10; // r28
  double v11; // fp1
  unsigned __int64 v12; // r6
  const char *v13; // r7
  char v14; // r23
  double v15; // fp27
  double v16; // fp20
  char v17; // r22
  double v18; // fp19
  double v19; // fp21
  double v20; // fp25
  double v21; // fp23
  double v22; // fp24
  double FakeEnemyWeight; // fp22
  double v24; // fp26
  double ScriptedAggro; // fp18
  const idEntity *FakeEnemy; // r3
  idEncounterGroup *EncounterGroup; // r3
  int v28; // r28
  int v29; // r29
  idAI2 *v30; // r10
  idEntity *Enemy; // r18
  const idEntity *Originator; // r3
  idSpawnId *SpawnId; // r27
  int GameMs; // r3
  __int64 v35; // r9
  const idAIEntityState *es; // r11
  int lastSense; // r10
  int v38; // r29
  aiSenseState_t *v39; // r28
  bool v40; // cr56
  const idAIEntityState *v41; // r11
  int v42; // r10
  aiSenseState_t *v43; // r29
  int attitude; // r11
  double v45; // fp6
  double v48; // fp29
  double v49; // fp30
  idPhysics *Physics; // r3
  const idVec3 *v51; // r3
  float y; // r8
  float z; // r7
  const idAIEntityState *v54; // r11
  aiSenseState_t *v55; // r6
  _DWORD *v56; // r11
  int v57; // r4
  int v58; // r3
  idPhysics *v59; // r29
  idPhysics *v60; // r28
  idRenderWorld *v61; // r27
  float *v62; // r29
  float *v63; // r3
  double v64; // fp9
  double v65; // fp6
  va *v66; // r3
  int v67; // r6
  idPhysics *v68; // r29
  idPhysics *v69; // r28
  idRenderWorld *v70; // r27
  float *v71; // r29
  float *v72; // r3
  double v73; // fp9
  double v74; // fp6
  va *v75; // r3
  int v76; // r6
  __int64 v77; // r10
  double v78; // fp9
  double v79; // fp6
  va *v80; // r3
  idPhysics *v81; // r30
  idPhysics *v82; // r29
  idRenderWorld *v83; // r28
  float *v84; // r30
  float *v85; // r3
  __int64 v86; // r6
  __int64 v87; // r10
  double v88; // fp7
  double v89; // fp6
  __int64 v90; // r8
  va *v91; // r3
  int v93; // [sp+8h] [-12E8h]
  int v94; // [sp+Ch] [-12E4h]
  int v95; // [sp+10h] [-12E0h]
  int v96; // [sp+14h] [-12DCh]
  int v97; // [sp+18h] [-12D8h]
  int v98; // [sp+1Ch] [-12D4h]
  double v99; // [sp+28h] [-12C8h]
  double v100; // [sp+40h] [-12B0h]
  double v101; // [sp+40h] [-12B0h]
  idPLogScope v102; // [sp+60h] [-1290h] BYREF
  idPLogScope v103; // [sp+68h] [-1288h] BYREF
  __int64 v104; // [sp+70h] [-1280h] BYREF
  float v105; // [sp+78h] [-1278h]
  idColor v106; // [sp+80h] [-1270h] BYREF
  idAI2 **v107; // [sp+90h] [-1260h] BYREF
  float v108[4]; // [sp+98h] [-1258h] BYREF
  float v109[4]; // [sp+A8h] [-1248h] BYREF
  _DWORD v110[4]; // [sp+B8h] [-1238h] BYREF
  float v111[4]; // [sp+C8h] [-1228h] BYREF
  float v112[6]; // [sp+D8h] [-1218h] BYREF
  idStaticList<idAI2 *,64> v113; // [sp+F0h] [-1200h] BYREF
  va v114; // [sp+200h] [-10F0h] BYREF

  RD_EventBegin(name: "idEnemyTargetSelector::GetWeight()");
  LODWORD(v6) = "idEnemyTargetSelector::GetWeight()";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v102, pl: &pLog, gMask: v6, label: v7);
  if ( ti->es == nullptr )
    goto LABEL_8;
  v8 = idAI2::CastTo(c: owner);
  Entity = (idActor *)idAIEntityState::GetEntity(this: (idAIEntityState *)ti->es);
  v10 = idActor::CastTo(c: Entity);
  if ( v8 != nullptr && idAI2::GetAlertCycle(this: v8) == ALERTCYCLE_COMBAT )
  {
    if ( Entity != nullptr && Entity->IsDead(this: Entity) )
      goto LABEL_8;
  }
  else if ( idAIEntityState::IsDead(this: (idAIEntityState *)ti->es) )
  {
LABEL_8:
    idPLogScope::~idPLogScope(this: &v102);
    RD_EventEnd();
    v11 = 0.0;
    return *((float *)&v11 + 1);
  }
  RD_EventBegin(name: "idEnemyTargetSelector::GetWeight() - setup");
  LODWORD(v12) = "idEnemyTargetSelector::GetWeight() - setup";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: &v103, pl: &pLog, gMask: v12, label: v13);
  v14 = 0;
  v15 = 0.0;
  v16 = 0.0;
  v17 = 0;
  v18 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  v21 = 0.0;
  v22 = 0.0;
  FakeEnemyWeight = 0.0;
  v24 = 0.0;
  ScriptedAggro = 0.0;
  if ( v8 != nullptr && idAIMemory::GetEnemy(this: &v8->aiVolatile.memory) == Entity )
    v18 = 1.0;
  if ( v10 != nullptr )
  {
    if ( (unsigned __int8)idPlayer::IsTypeOf(c: v10) != 0 )
    {
      v14 = 1;
      v21 = 1.0;
      v17 = 0;
      if ( v8 != nullptr && v8->aiEditable.targeting.playerWeight < 0.0 )
        goto LABEL_57;
    }
    else if ( (unsigned __int8)idAI2::IsTypeOf(c: v10) != 0 )
    {
      v14 = 0;
      v22 = 1.0;
      v17 = 1;
      if ( v8 != nullptr && v8->aiEditable.targeting.aiWeight < 0.0 )
        goto LABEL_57;
    }
    if ( (unsigned __int8)idVehicle::IsTypeOf(c: v10) != 0 || (unsigned __int8)idRobot::IsTypeOf(c: v10) != 0 )
    {
      v24 = 1.0;
      if ( v8 == nullptr )
        goto LABEL_49;
      if ( v8->aiEditable.targeting.vehicleWeight < 0.0 )
        goto LABEL_57;
    }
  }
  if ( v8 != nullptr )
  {
    FakeEnemy = idAI2::GetFakeEnemy(this: v8);
    if ( FakeEnemy != nullptr )
    {
      if ( Entity == FakeEnemy && (*(_BYTE *)&FakeEnemy->flags & 8) != 0 )
      {
        v17 = 0;
        v14 = 0;
        FakeEnemyWeight = idAI2::GetFakeEnemyWeight(this: v8);
        if ( v8->aiEditable.targeting.fakeWeight < 0.0 )
          goto LABEL_57;
      }
    }
    else if ( idTarget_FakeEnemy::CastTo(c: (idTarget_FakeEnemy *)Entity) != nullptr )
    {
      goto LABEL_57;
    }
    if ( idAI2::GetEncounterGroup(this: v8) != nullptr )
    {
      v113.num = 0;
      v113.granularity = 1;
      v113.size = 64;
      v113.list = v113.staticList;
      v113.memTag = 5;
      v113.listStatic = 1;
      EncounterGroup = idAI2::GetEncounterGroup(this: v8);
      idEncounterGroup::GetLivingMembers(this: EncounterGroup, list: &v113);
      v28 = 0;
      if ( v113.num > 0 )
      {
        v29 = 0;
        while ( 1 )
        {
          v30 = v113.list[v29];
          if ( v30 != v8 )
          {
            v107 = &v113.list[v29];
            Enemy = (idEntity *)idAIMemory::GetEnemy(this: &v30->aiVolatile.memory);
            if ( Enemy == idAIEntityState::GetEntity(this: (idAIEntityState *)ti->es) )
              break;
          }
          ++v28;
          ++v29;
          if ( v28 >= v113.num )
            goto LABEL_39;
        }
        v16 = 1.0;
      }
LABEL_39:
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v113);
    }
    if ( ti->distTo > (double)v8->aiEditable.targeting.rangeMax )
      goto LABEL_57;
    v15 = (float)((float)1.0 - (float)(ti->distTo / v8->aiEditable.targeting.rangeMax));
    if ( idAIDamageInfo::GetRecentDamage(this: &v8->aiVolatile.pain.damageInfo, ent: Entity) != 0.0 )
      v19 = 1.0;
    Originator = idAIEvent::GetOriginator(this: (idAIEvent *)&v8->aiVolatile.memory);
    SpawnId = idGameLocal::GetSpawnId(this: (idGameLocal *)&v107, result: (idSpawnId *)gameLocal, ent: Originator);
    if ( idGameLocal::GetSpawnId(this: (idGameLocal *)&v104, result: (idSpawnId *)gameLocal, ent: Entity)->value == SpawnId->value )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      ScriptedAggro = idAIMemory::GetScriptedAggro(this: &v8->aiVolatile.memory, curTime: GameMs);
    }
    if ( (unsigned __int8)idAIEntityState::IsVisible(this: (idAIEntityState *)ti->es) != 0 )
      goto LABEL_55;
    es = ti->es;
    HIDWORD(v35) = ti->es->senses.ptr[ti->es->lastSense];
    if ( *(int *)(HIDWORD(v35) + 88) < 0 )
      goto LABEL_53;
    lastSense = es->lastSense;
    LODWORD(v104) = (int)v8->aiEditable.targeting.spottedMax;
    HIDWORD(v104) = es;
    v38 = 1000 * v104;
    v39 = es->senses.ptr[lastSense];
    v40 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v39->lastConfirmedStimTime < v38;
    goto LABEL_52;
  }
LABEL_49:
  if ( (unsigned __int8)idAIEntityState::IsVisible(this: (idAIEntityState *)ti->es) != 0 )
  {
LABEL_55:
    v20 = 1.0;
    goto LABEL_56;
  }
  v41 = ti->es;
  HIDWORD(v35) = ti->es->senses.ptr[ti->es->lastSense];
  if ( *(int *)(HIDWORD(v35) + 88) >= 0 )
  {
    v42 = v41->lastSense;
    HIDWORD(v104) = ti->es;
    v43 = v41->senses.ptr[v42];
    v40 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v43->lastConfirmedStimTime < 5000;
LABEL_52:
    if ( v40 )
      goto LABEL_55;
  }
LABEL_53:
  if ( ti->es->curAwareness == 0 )
    v20 = 0.1;
LABEL_56:
  attitude = ti->attitude;
  v45 = (float)((float)(this->ownerDir.x * ti->dirTo.x)
              + (float)((float)(ti->dirTo.z * this->ownerDir.z) + (float)(ti->dirTo.y * this->ownerDir.y)));
  HIDWORD(v104) = &ti->dirTo;
  _FP5 = -v45;
  __asm { fsel      f28, f5, f31, f6 }
  if ( attitude >= 3 )
  {
LABEL_57:
    idPLogScope::~idPLogScope(this: &v103);
    RD_EventEnd();
    idPLogScope::~idPLogScope(this: &v102);
    RD_EventEnd();
    v11 = 0.0;
    return *((float *)&v11 + 1);
  }
  LODWORD(v35) = 3 - attitude;
  v104 = v35;
  v48 = (float)((float)v35 * (float)0.33333334);
  if ( v8 != nullptr )
    v49 = (float)((float)(v8->aiEditable.targeting.rangeWeight * (float)v15)
                + (float)((float)(v8->aiEditable.targeting.angleWeight * (float)_FP28)
                        + (float)((float)(v8->aiEditable.targeting.relationWeight
                                        * (float)((float)v35 * (float)0.33333334))
                                + (float)((float)(v8->aiEditable.targeting.groupWeight * (float)v16)
                                        + (float)((float)(v8->aiEditable.targeting.currentWeight * (float)v18)
                                                + (float)((float)(v8->aiEditable.targeting.damagerWeight * (float)v19)
                                                        + (float)((float)(v8->aiEditable.targeting.spottedWeight
                                                                        * (float)v20)
                                                                + (float)((float)(v8->aiEditable.targeting.fakeWeight
                                                                                * (float)FakeEnemyWeight)
                                                                        + (float)((float)(v8->aiEditable.targeting.vehicleWeight
                                                                                        * (float)v24)
                                                                                + (float)((float)((float)((float)v22 + (float)v21)
                                                                                                * v8->aiEditable.targeting.playerWeight)
                                                                                        + (float)(v8->aiEditable.targeting.aggroWeight
                                                                                                * (float)ScriptedAggro)))))))))));
  else
    v49 = (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)ScriptedAggro
                                                                                                + (float)v24)
                                                                                        + (float)FakeEnemyWeight)
                                                                                + (float)v22)
                                                                        + (float)v21)
                                                                + (float)v20)
                                                        + (float)v19)
                                                + (float)v18)
                                        + (float)v16)
                                + (float)((float)v35 * (float)0.33333334))
                        + (float)_FP28)
                + (float)v15);
  if ( v49 > 0.0 && ai_debugTargetList.valueInteger > 0 )
  {
    v106 = idColor::colorMdGrey;
    Physics = idEntity::GetPhysics(this: owner);
    v51 = Physics->GetOrigin(this: Physics, a2: 0);
    y = v51->y;
    z = v51->z;
    v54 = ti->es;
    *(float *)&v104 = v51->x;
    *((float *)&v104 + 1) = y;
    v105 = z;
    v55 = v54->senses.ptr[1];
    if ( v55->lastUnconfirmedStimTime >= 0 )
    {
      v56 = &v54->senses.ptr[1]->__vftable;
      if ( v55->lastConfirmedStimTime >= 0 )
        v106 = idColor::colorWhite;
      if ( v18 > 0.0 )
        v106 = idColor::colorRed;
      v57 = v56[2];
      v58 = v56[3];
      v110[0] = v56[1];
      v110[1] = v57;
      v110[2] = v58;
      ((void (__fastcall *)(idRenderWorld *, idColor *, __int64 *, _DWORD *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &v106,
        a3: &v104,
        a4: v110,
        a5: 10.0);
    }
    if ( ai_debugTargetList.valueInteger == 1 || v8 == nullptr )
    {
      v81 = idEntity::GetPhysics(this: Entity);
      v82 = idEntity::GetPhysics(this: owner);
      v83 = common->RW(this: common);
      v84 = (float *)v81->GetOrigin(this: v81, a2: 0);
      v85 = (float *)v82->GetOrigin(this: v82, a2: 0);
      HIDWORD(v86) = LODWORD(v49);
      LODWORD(v87) = 0x82000000;
      HIDWORD(v87) = "Could not find AI state, idVS_ds_Car_Chase! ";
      v88 = (float)(v84[1] + v85[1]);
      v89 = (float)(*v84 + *v85);
      v109[2] = (float)(v84[2] + v85[2]) * (float)0.5;
      v109[1] = (float)v88 * (float)0.5;
      v109[0] = (float)v89 * (float)0.5;
      v91 = va::va(
              this: &v114,
              fmt: "Weight: %4.1f",
              a3: v86,
              a4: v90,
              a5: v87,
              a6: v93,
              a7: v94,
              a8: v95,
              a9: v96,
              a10: v97,
              a11: v98,
              v49);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, _DWORD, _DWORD, double))v83->DebugText)(
        a1: v83,
        a2: v91,
        a3: v109,
        a4: &off_82040000,
        a5: &v106,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.2);
    }
    else if ( ai_debugTargetList.valueInteger >= 2 )
    {
      if ( v14 != 0 )
      {
        v59 = idEntity::GetPhysics(this: Entity);
        v60 = idEntity::GetPhysics(this: owner);
        v61 = common->RW(this: common);
        v62 = (float *)v59->GetOrigin(this: v59, a2: 0);
        v63 = (float *)v60->GetOrigin(this: v60, a2: 0);
        v64 = (float)(v62[2] + v63[2]);
        v65 = (float)(*v62 + *v63);
        v108[1] = (float)(v62[1] + v63[1]) * (float)0.5;
        v108[2] = (float)v64 * (float)0.5;
        v108[0] = (float)v65 * (float)0.5;
        v100 = (float)(v8->aiEditable.targeting.playerWeight * (float)v21);
        v66 = va::va(
                this: &v114,
                fmt: (const char *)HIDWORD(v49),
                a3: __SPAIR64__(
                  LODWORD(v49),
                  COERCE_UNSIGNED_INT64((float)(v8->aiEditable.targeting.rangeWeight * (float)v15))),
                a4: __SPAIR64__(
                  COERCE_UNSIGNED_INT64((float)(v8->aiEditable.targeting.angleWeight * (float)_FP28)),
                  COERCE_UNSIGNED_INT64((float)(v8->aiEditable.targeting.relationWeight * (float)v48))),
                a5: __SPAIR64__(
                  LODWORD(v100),
                  COERCE_UNSIGNED_INT64((float)(v8->aiEditable.targeting.vehicleWeight * (float)v24))),
                a6: v93,
                a7: v94,
                a8: v95,
                a9: v96,
                a10: v97,
                a11: v98,
                v49);
        ((void (__fastcall *)(idRenderWorld *, va *, float *, int, idColor *, int, _DWORD, _DWORD, double))v61->DebugText)(
          a1: v61,
          a2: v66,
          a3: v108,
          a4: v67,
          a5: &v106,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.2);
      }
      else
      {
        v68 = idEntity::GetPhysics(this: Entity);
        v69 = idEntity::GetPhysics(this: owner);
        v70 = common->RW(this: common);
        v71 = (float *)v68->GetOrigin(this: v68, a2: 0);
        v72 = (float *)v69->GetOrigin(this: v69, a2: 0);
        if ( v17 != 0 )
        {
          v73 = (float)(*v71 + *v72);
          v74 = (float)(v71[1] + v72[1]);
          v112[2] = (float)(v71[2] + v72[2]) * (float)0.5;
          v112[0] = (float)v73 * (float)0.5;
          v112[1] = (float)v74 * (float)0.5;
          v75 = va::va(
                  this: &v114,
                  fmt: (const char *)HIDWORD(v49),
                  a3: COERCE__INT64((float)(v8->aiEditable.targeting.rangeWeight * (float)v15)),
                  a4: __SPAIR64__(
                    COERCE_UNSIGNED_INT64((float)(v8->aiEditable.targeting.angleWeight * (float)_FP28)),
                    COERCE_UNSIGNED_INT64((float)(v8->aiEditable.targeting.relationWeight * (float)v48))),
                  a5: __SPAIR64__(
                    COERCE_UNSIGNED_INT64((float)(v8->aiEditable.targeting.aiWeight * (float)v22)),
                    COERCE_UNSIGNED_INT64((float)(v8->aiEditable.targeting.vehicleWeight * (float)v24))),
                  a6: v93,
                  a7: v94,
                  a8: v95,
                  a9: v96,
                  a10: v97,
                  a11: v98,
                  v49);
          ((void (__fastcall *)(idRenderWorld *, va *, float *, int, idColor *, int, _DWORD, _DWORD, double))v70->DebugText)(
            a1: v70,
            a2: v75,
            a3: v112,
            a4: v76,
            a5: &v106,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 0.2);
        }
        else
        {
          LODWORD(v77) = "Could not find AI state, idVS_ds_Car_Chase! ";
          v78 = (float)(v71[2] + v72[2]);
          v79 = (float)(*v72 + *v71);
          v111[1] = (float)(v71[1] + v72[1]) * (float)0.5;
          v111[2] = (float)v78 * (float)0.5;
          v111[0] = (float)v79 * (float)0.5;
          v101 = (float)(v8->aiEditable.targeting.fakeWeight * (float)FakeEnemyWeight);
          v99 = (float)(v8->aiEditable.targeting.rangeWeight * (float)v15);
          HIDWORD(v77) = LODWORD(v101);
          v80 = va::va(
                  this: &v114,
                  fmt: (const char *)HIDWORD(v49),
                  a3: __SPAIR64__(
                    HIDWORD(v99),
                    HIDWORD(COERCE_UNSIGNED_INT64((float)(v8->aiEditable.targeting.angleWeight * (float)_FP28)))),
                  a4: COERCE__INT64((float)(v8->aiEditable.targeting.relationWeight * (float)v48)),
                  a5: v77,
                  a6: v93,
                  a7: v94,
                  a8: v95,
                  a9: v96,
                  a10: v97,
                  a11: v98,
                  v49);
          ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v70->DebugText)(
            a1: v70,
            a2: v80,
            a3: v111,
            a4: v70->DebugText,
            a5: &v106,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 0.2);
        }
      }
    }
  }
  idPLogScope::~idPLogScope(this: &v103);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: &v102);
  RD_EventEnd();
  v11 = v49;
  return *((float *)&v11 + 1);
}


// ========================================================================
// __unwind$488075_0
// EA  : 0x82B030F8
// RVA : 0x00B030F8
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\enemytargetselector.cpp
// ========================================================================

void _unwind_488075_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4848 + 4608));
}


// ========================================================================
// __unwind$488076_0
// EA  : 0x82B03120
// RVA : 0x00B03120
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\enemytargetselector.cpp
// ========================================================================

void _unwind_488076_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4848 + 96));
}


// ========================================================================
// __unwind$488077_0
// EA  : 0x82B03148
// RVA : 0x00B03148
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\enemytargetselector.cpp
// ========================================================================

void _unwind_488077_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4848 + 4609));
}


// ========================================================================
// __unwind$488078
// EA  : 0x82B03170
// RVA : 0x00B03170
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\enemytargetselector.cpp
// ========================================================================

void _unwind_488078()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4848 + 104));
}


// ========================================================================
// __unwind$488079
// EA  : 0x82B03198
// RVA : 0x00B03198
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\enemytargetselector.cpp
// ========================================================================

void _unwind_488079()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4848 + 240));
}

