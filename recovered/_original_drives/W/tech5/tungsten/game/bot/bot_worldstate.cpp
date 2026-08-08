
// ========================================================================
// ?GetRecordForIndex@idBotWorldState@@QAAPAVidBotTargetRecord@@H@Z
// EA  : 0x82B44B38
// RVA : 0x00B44B38
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

idBotTargetRecord *__fastcall idBotWorldState::GetRecordForIndex(idBotWorldState *this, const int index)
{
  return &this->targetRecords.list[index];
}


// ========================================================================
// ??0idBotTargetRecord@@QAA@XZ
// EA  : 0x82B44D38
// RVA : 0x00B44D38
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

idBotTargetRecord *__fastcall idBotTargetRecord::idBotTargetRecord(idBotTargetRecord *this)
{
  int GameMs; // r3
  char v3; // r7
  char v4; // r5

  idBotTargetRecord::volatileData_t::volatileData_t(this: &this->volatileData);
  this->targetEntity.spawnId.value = 0x1FFF;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v3 = *((_BYTE *)&this->volatileData.visibleTracker + 12);
  this->volatileData.visibleTracker.lastUpdateMS = GameMs;
  *((_BYTE *)&this->volatileData.visibleTracker + 12) = v3 & 0x7F;
  this->volatileData.visibleTracker.value = 0.0;
  this->volatileData.visibleTracker.decayRate = -0.050000001;
  v4 = *((_BYTE *)&this->volatileData.audibleTracker + 12);
  this->volatileData.audibleTracker.lastUpdateMS = GameMs;
  this->volatileData.audibleTracker.value = 0.0;
  *((_BYTE *)&this->volatileData.audibleTracker + 12) = v4 & 0x7F;
  this->volatileData.audibleTracker.decayRate = -0.050000001;
  return this;
}


// ========================================================================
// ?GetRecordForEntity@idBotWorldState@@QAAPAVidBotTargetRecord@@PBVidEntity@@@Z
// EA  : 0x82B44DD0
// RVA : 0x00B44DD0
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

idBotTargetRecord *__fastcall idBotWorldState::GetRecordForEntity(idBotWorldState *this, const idEntity *entity)
{
  int v5; // r27
  int v6; // r29
  int v7; // r30
  idGameLocal *v8; // r9
  int value; // r10
  idEntity *v10; // r3
  idEntity *v11; // r3

  if ( entity == nullptr )
    return nullptr;
  v5 = 0;
  v6 = 0;
  if ( this->targetRecords.num > 0 )
  {
    v7 = 0;
    v8 = gameLocal;
    while ( 1 )
    {
      value = this->targetRecords.list[v7].targetEntity.spawnId.value;
      if ( v8->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v10 = v8->entities.ptr[this->targetRecords.list[v7].targetEntity.spawnId.value & 0x1FFF]) != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
        v8 = gameLocal;
      }
      else
      {
        v11 = nullptr;
      }
      if ( v11 == entity )
        break;
      ++v6;
      ++v7;
      if ( v6 >= this->targetRecords.num )
        return nullptr;
    }
    return &this->targetRecords.list[v6];
  }
  return (idBotTargetRecord *)v5;
}


// ========================================================================
// ?GetRecordIndexForEntity@idBotWorldState@@QBAHPBVidEntity@@@Z
// EA  : 0x82B44EA8
// RVA : 0x00B44EA8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

int __fastcall idBotWorldState::GetRecordIndexForEntity(idBotWorldState *this, const idEntity *entity)
{
  int v4; // r29
  int v5; // r31
  idGameLocal *v6; // r9
  int value; // r10
  idEntity *v8; // r3
  idEntity *v9; // r3

  if ( entity == nullptr )
    return -1;
  v4 = 0;
  if ( this->targetRecords.num <= 0 )
    return -1;
  v5 = 0;
  v6 = gameLocal;
  while ( 1 )
  {
    value = this->targetRecords.list[v5].targetEntity.spawnId.value;
    if ( v6->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = v6->entities.ptr[this->targetRecords.list[v5].targetEntity.spawnId.value & 0x1FFF]) != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
      v6 = gameLocal;
    }
    else
    {
      v9 = nullptr;
    }
    if ( v9 == entity )
      break;
    ++v4;
    ++v5;
    if ( v4 >= this->targetRecords.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?DrawDebugInfo@idBotWorldState@@QAAXXZ
// EA  : 0x82B44F70
// RVA : 0x00B44F70
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotWorldState::DrawDebugInfo(idBotWorldState *this)
{
  idBot *owner; // r11
  int value; // r10
  idEntity *v4; // r3
  idEntity *v5; // r30
  const char *data; // r4
  int num; // r26
  bool v8; // r30
  bool v9; // r29
  double health; // fp31
  idBotTargetRecord *RecordForEntity; // r3
  __int64 v12; // r10
  va *v13; // r3
  int v14; // [sp+8h] [-1108h]
  int v15; // [sp+Ch] [-1104h]
  int v16; // [sp+10h] [-1100h]
  int v17; // [sp+14h] [-10FCh]
  int v18; // [sp+18h] [-10F8h]
  int v19; // [sp+1Ch] [-10F4h]
  int v20; // [sp+30h] [-10E0h]
  idStr v21; // [sp+70h] [-10A0h] BYREF
  idStr v22; // [sp+90h] [-1080h] BYREF
  idStr v23; // [sp+B0h] [-1060h] BYREF
  va v24; // [sp+D0h] [-1040h] BYREF

  owner = this->owner;
  if ( bot_debugWorldState.valueInteger == owner->owner->entityNumber )
  {
    value = owner->goalTask.goalEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v5 = idEntity::CastTo(c: v4);
    }
    else
    {
      v5 = nullptr;
    }
    idStr::idStr(this: &v22, text: this->owner->owner->name.data);
    if ( v5 != nullptr )
      data = v5->name.data;
    else
      data = "None";
    idStr::idStr(this: &v21, text: data);
    num = this->targetRecords.num;
    health = 0.0;
    RecordForEntity = idBotWorldState::GetRecordForEntity(this, entity: v5);
    v8 = false;
    v9 = false;
    if ( RecordForEntity != nullptr )
    {
      health = RecordForEntity->volatileData.health;
      v8 = (RecordForEntity->volatileData.targetFlags.flags & 0x20) != 0;
      v9 = (RecordForEntity->volatileData.targetFlags.flags & 0x40) != 0;
    }
    LODWORD(v12) = v9;
    HIDWORD(v12) = v8;
    v13 = va::va(
            this: &v24,
            fmt: "Bot Name: %s\n"
            "Num Entities: %d\n"
            "Enemy Name: %s\n"
            "Enemy Health: %.1f\n"
            "Enemy CanSee: %d\n"
            "Enemy CanHear: %d\n"
            "Enemy Vis: %d\n"
            "Enemy Audible: %d\n",
            a3: __SPAIR64__((unsigned int)v22.data, num),
            a4: __SPAIR64__((unsigned int)v21.data, LODWORD(health)),
            a5: v12,
            a6: v14,
            a7: v15,
            a8: v16,
            a9: v17,
            a10: v18,
            a11: v19,
            health);
    idStr::idStr(this: &v23, text: v13);
    if ( (_S18_8 & 1) == 0 )
    {
      handle_6.time = 0;
      _S18_8 |= 1u;
      handle_6.index = -1;
    }
    ((void (__fastcall *)(idConsole *, idOverlayHandle *, _DWORD, int, _DWORD, char *, double, double))console->PrintOverlay)(
      a1: console,
      a2: &handle_6,
      a3: 1.0,
      a4: v20,
      a5: HIDWORD(health),
      a6: v23.data,
      a7: 1.0,
      a8: 1.0);
    idStr::FreeData(this: &v23);
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: &v22);
  }
}


// ========================================================================
// __unwind$490215
// EA  : 0x82B4515C
// RVA : 0x00B4515C
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void _unwind_490215()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 144));
}


// ========================================================================
// __unwind$490216
// EA  : 0x82B45184
// RVA : 0x00B45184
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void _unwind_490216()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 112));
}


// ========================================================================
// __unwind$490217
// EA  : 0x82B451AC
// RVA : 0x00B451AC
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void _unwind_490217()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 176));
}


// ========================================================================
// ?FindBestTarget@idBotWorldState@@QAAXXZ
// EA  : 0x82B451D8
// RVA : 0x00B451D8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotWorldState::FindBestTarget(idBotWorldState *this)
{
  int GameMs; // r3
  idBot *owner; // r11
  int num; // r28
  int v5; // r30
  int v6; // r29
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( this->lastEnemyUpdateTime + this->enemyCheckDebounce <= GameMs )
  {
    owner = this->owner;
    this->lastEnemyUpdateTime = GameMs;
    if ( !owner->goalTask.goalEnemyLocked )
    {
      this->targetFilter->Reset(this: this->targetFilter);
      num = this->targetRecords.num;
      this->targetFilter->PreCheckTargets(this: this->targetFilter, a2: num);
      v5 = 0;
      if ( num > 0 )
      {
        v6 = 0;
        do
          this->targetFilter->CheckTarget(this: this->targetFilter, a2: v5++, a3: &this->targetRecords.list[v6++]);
        while ( v5 < num );
      }
      this->targetFilter->SortTargets(this: this->targetFilter);
      value = this->targetFilter->bestTarget.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v9 = idEntity::CastTo(c: v8);
        idBotGoal::Bot_SetGoalEnemy(this: &this->owner->goalTask, newEnemy: v9);
      }
      else
      {
        idBotGoal::Bot_SetGoalEnemy(this: &this->owner->goalTask, newEnemy: nullptr);
      }
    }
  }
}


// ========================================================================
// ?UpdateBotGUI@idBotWorldState@@QBAXAAVidGuiListBox@@@Z
// EA  : 0x82B45320
// RVA : 0x00B45320
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotWorldState::UpdateBotGUI(idBotWorldState *this, idGuiListBox *infoList)
{
  bool v4; // r29
  int value; // r8
  bool v6; // r27
  double health; // fp31
  bool v8; // r26
  bool v9; // r25
  idEntity *v10; // r3
  idEntity *v11; // r3
  idEntity *v12; // r23
  int RecordIndexForEntity; // r3
  idBotTargetRecord *v14; // r31
  idPhysics *Physics; // r24
  idRenderWorld *v16; // r3
  double z; // fp13
  double y; // fp12
  idRenderWorld *v19; // r23
  idRenderWorld_vtbl *v20; // r31
  int v21; // r3
  idGuiListBox *v22; // r3
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  idGuiListBox *v26; // r3
  __int64 v27; // r6
  __int64 v28; // r10
  __int64 v29; // r8
  idGuiListBox *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  idGuiListBox *v34; // r3
  __int64 v35; // r8
  __int64 v36; // r6
  __int64 v37; // r10
  idGuiListBox *v38; // r3
  __int64 v39; // r8
  __int64 v40; // r10
  __int64 v41; // r6
  idGuiListBox *v42; // r3
  __int64 v43; // r6
  __int64 v44; // r10
  __int64 v45; // r8
  idGuiListBox *v46; // r3
  __int64 v47; // r6
  __int64 v48; // r10
  __int64 v49; // r8
  idGuiListBox *v50; // r3
  __int64 v51; // r6
  __int64 v52; // r10
  __int64 v53; // r8
  idGuiListBox *v54; // r3
  __int64 v55; // r6
  __int64 v56; // r10
  __int64 v57; // r8
  idGuiListBox *v58; // r3
  __int64 v59; // r6
  __int64 v60; // r10
  __int64 v61; // r8
  idBotTargetFilter *targetFilter; // r4
  const char *v63; // r31
  idGuiListBox *v64; // r3
  __int64 v65; // r10
  __int64 v66; // r8
  __int64 v67; // r6
  idGuiListBox *v68; // r3
  __int64 v69; // r10
  __int64 v70; // r6
  __int64 v71; // r8
  float v72[6]; // [sp+50h] [-70h] BYREF

  v4 = false;
  value = this->owner->goalTask.goalEnemy.spawnId.value;
  v6 = false;
  health = 0.0;
  v8 = false;
  v9 = false;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v10 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v10 != nullptr )
    {
      v11 = idEntity::CastTo(c: v10);
      v12 = v11;
      if ( v11 != nullptr )
      {
        RecordIndexForEntity = idBotWorldState::GetRecordIndexForEntity(this, entity: v11);
        if ( RecordIndexForEntity != -1 )
        {
          v14 = &this->targetRecords.list[RecordIndexForEntity];
          health = v14->volatileData.health;
          v4 = (v14->volatileData.targetFlags.flags & 0x20) != 0;
          v6 = (v14->volatileData.targetFlags.flags & 0x40) != 0;
          v8 = (v14->volatileData.targetFlags.flags & 8) != 0;
          v9 = (v14->volatileData.targetFlags.flags & 0x10) != 0;
          if ( (v14->volatileData.targetFlags.flags & 0x20) == 0 )
          {
            Physics = idEntity::GetPhysics(this: v12);
            v16 = gameLocal->GetRenderWorld(this: gameLocal);
            z = v14->volatileData.lastSeenLocation.z;
            y = v14->volatileData.lastSeenLocation.y;
            v19 = v16;
            v72[0] = v14->volatileData.lastSeenLocation.x;
            v72[1] = y;
            v72[2] = (float)z - pm_normalviewheight.valueFloat;
            v20 = v16->__vftable;
            v21 = (int)Physics->GetBounds(this: Physics, a2: -1);
            v20->DebugFilledBounds(
              this: v19,
              a2: (const idVec4 *)&idColor::colorWhite,
              a3: (const idBounds *)v21,
              a4: (const idVec3 *)v72,
              a5: 0,
              a6: false);
          }
        }
      }
    }
  }
  v22 = idGuiListBox::Row(this: infoList);
  v26 = idGuiListBox::Printf(this: v22, fmt: "Enemy Health: ", a3: v25, a4: v24, a5: v23);
  HIDWORD(v27) = LODWORD(health);
  LODWORD(v28) = "ound traces";
  idGuiListBox::Printf(this: v26, fmt: "%.2f", a3: v27, a4: v29, a5: v28, health);
  v30 = idGuiListBox::Row(this: infoList);
  HIDWORD(v31) = &off_822B0000;
  v34 = idGuiListBox::Printf(this: v30, fmt: "Enemy Can See: ", a3: v33, a4: v32, a5: v31);
  LODWORD(v35) = 0x82000000;
  HIDWORD(v36) = v4;
  idGuiListBox::Printf(this: v34, fmt: "%d", a3: v36, a4: v35, a5: v37);
  v38 = idGuiListBox::Row(this: infoList);
  HIDWORD(v39) = &off_822B0000;
  v42 = idGuiListBox::Printf(this: v38, fmt: "Enemy Can Hear: ", a3: v41, a4: v39, a5: v40);
  HIDWORD(v43) = v6;
  idGuiListBox::Printf(this: v42, fmt: "%d", a3: v43, a4: v45, a5: v44);
  v46 = idGuiListBox::Row(this: infoList);
  LODWORD(v47) = &off_822B0000;
  v50 = idGuiListBox::Printf(this: v46, fmt: "Enemy Visible: ", a3: v47, a4: v49, a5: v48);
  HIDWORD(v51) = v8;
  idGuiListBox::Printf(this: v50, fmt: "%d", a3: v51, a4: v53, a5: v52);
  v54 = idGuiListBox::Row(this: infoList);
  HIDWORD(v55) = &off_822B0000;
  v58 = idGuiListBox::Printf(this: v54, fmt: "Enemy Audible: ", a3: v55, a4: v57, a5: v56);
  HIDWORD(v59) = v9;
  idGuiListBox::Printf(this: v58, fmt: "%d", a3: v59, a4: v61, a5: v60);
  targetFilter = this->targetFilter;
  if ( targetFilter != nullptr )
    v63 = (const char *)((int (*)(void))targetFilter->GetDebugName)();
  else
    v63 = "<NONE>";
  v64 = idGuiListBox::Row(this: infoList);
  v68 = idGuiListBox::Printf(this: v64, fmt: "Target Filter: ", a3: v67, a4: v66, a5: v65);
  LODWORD(v69) = byte_821B0000;
  HIDWORD(v70) = v63;
  idGuiListBox::Printf(this: v68, fmt: "%s", a3: v70, a4: v71, a5: v69);
}


// ========================================================================
// ?RenderWorldInfo@idBotWorldState@@QBAXAAVidGuiListBox@@@Z
// EA  : 0x82B45590
// RVA : 0x00B45590
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotWorldState::RenderWorldInfo(idBotWorldState *this, idGuiListBox *infoList)
{
  idBot *owner; // r11
  const idAAS2 *aas; // r26
  idPhysics *Physics; // r3
  int v7; // r28
  idPresentable *presentable; // r3
  int v9; // r3
  float *v10; // r29
  int AreaNum; // r3
  int v12; // r3
  int v13; // r25
  int *v14; // r27
  char *v15; // r23
  int i; // r24
  int v17; // r10
  int *v18; // r24
  bool v19; // cr58
  int (*GetRenderWorld)(void); // ctr
  int v21; // r3
  idColor *v22; // r4
  float v23; // r9
  float v24; // r8
  idBot *v25; // r7
  double v26; // fp12
  double v27; // fp11
  double v28; // fp8
  double v29; // fp7
  idColor *v30; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  idBot *v34; // r3
  idRenderWorld *v35; // r3
  idBot *v36; // r3
  double v37; // fp7
  double v38; // fp6
  double v39; // fp10
  double v40; // fp9
  idRenderWorld *v41; // r3
  double v42; // fp9
  double v43; // fp8
  double v44; // fp12
  double v45; // fp10
  idRenderWorld *v46; // r3
  int v47; // r26
  int v48; // r25
  idBotTargetRecord *v49; // r28
  int value; // r9
  idEntity *v51; // r3
  idAI2 *v52; // r29
  int v53; // r11
  char v54; // r11
  bool v55; // zf
  idPresentable *v56; // r3
  float *v57; // r3
  double v58; // fp6
  int v59; // r11
  char v60; // r11
  idAI2 *v61; // r3
  idPhysics *v62; // r3
  float *v63; // r3
  idColor *v64; // r11
  float v65; // r8
  float v66; // r7
  float v67; // r6
  __int64 v68; // r11
  idPhysics *v69; // r3
  int v70; // r29
  idBot *v71; // r3
  float v72; // r7
  float v73; // r6
  double v74; // fp2
  double v75; // fp3
  idRenderWorld *v76; // r3
  double v77; // fp3
  double v78; // fp2
  idRenderWorld *v79; // r3
  double v80; // fp8
  idBot *v81; // r3
  double v82; // fp7
  idRenderWorld *v83; // r3
  idBotTargetFilter *targetFilter; // r10
  const char *v85; // r29
  idGuiListBox *v86; // r3
  __int64 v87; // r10
  __int64 v88; // r8
  __int64 v89; // r6
  idGuiListBox *v90; // r3
  __int64 v91; // r6
  __int64 v92; // r10
  __int64 v93; // r8
  int num; // r29
  idGuiListBox *v95; // r3
  __int64 v96; // r10
  __int64 v97; // r8
  __int64 v98; // r6
  idGuiListBox *v99; // r3
  __int64 v100; // r6
  __int64 v101; // r10
  __int64 v102; // r8
  idEntityPtr<idEntity> *p_goalEnemy; // r9
  idEntity *v104; // r3
  idPlayer *v105; // r25
  int v106; // r11
  char v107; // r11
  idLobbyBase *v108; // r29
  idPresentable *v109; // r3
  lobbyUserID_t *v110; // r4
  lobbyUserID_t *LobbyUserID; // r3
  const char *data; // r4
  bool v113; // r29
  bool v114; // r28
  bool v115; // r27
  bool v116; // r26
  double health; // fp31
  int RecordIndexForEntity; // r3
  idBotTargetRecord *v119; // r11
  char *v120; // r30
  idGuiListBox *v121; // r3
  __int64 v122; // r10
  __int64 v123; // r8
  __int64 v124; // r6
  idGuiListBox *v125; // r3
  __int64 v126; // r6
  __int64 v127; // r10
  __int64 v128; // r8
  idGuiListBox *v129; // r3
  __int64 v130; // r10
  __int64 v131; // r8
  __int64 v132; // r6
  idGuiListBox *v133; // r3
  __int64 v134; // r10
  __int64 v135; // r6
  __int64 v136; // r8
  idGuiListBox *v137; // r3
  __int64 v138; // r8
  __int64 v139; // r10
  __int64 v140; // r6
  idGuiListBox *v141; // r3
  __int64 v142; // r6
  __int64 v143; // r10
  __int64 v144; // r8
  idGuiListBox *v145; // r3
  __int64 v146; // r8
  __int64 v147; // r10
  __int64 v148; // r6
  idGuiListBox *v149; // r3
  __int64 v150; // r6
  __int64 v151; // r10
  __int64 v152; // r8
  idGuiListBox *v153; // r3
  __int64 v154; // r6
  __int64 v155; // r10
  __int64 v156; // r8
  idGuiListBox *v157; // r3
  __int64 v158; // r6
  __int64 v159; // r10
  __int64 v160; // r8
  idGuiListBox *v161; // r3
  __int64 v162; // r6
  __int64 v163; // r10
  __int64 v164; // r8
  idGuiListBox *v165; // r3
  __int64 v166; // r6
  __int64 v167; // r10
  __int64 v168; // r8
  idVec3 v169; // [sp+50h] [-1190h] BYREF
  idVec3 v170; // [sp+60h] [-1180h] BYREF
  idEntityPtr<idEntity> *p_targetEntity; // [sp+6Ch] [-1174h]
  float v172; // [sp+70h] [-1170h] BYREF
  float v173; // [sp+74h] [-116Ch]
  float v174; // [sp+78h] [-1168h]
  float v175; // [sp+7Ch] [-1164h]
  float v176; // [sp+80h] [-1160h]
  float v177; // [sp+84h] [-115Ch]
  float v178; // [sp+88h] [-1158h]
  float v179; // [sp+8Ch] [-1154h]
  float v180; // [sp+90h] [-1150h]
  idVec3 v181; // [sp+98h] [-1148h] BYREF
  idVec3 v182; // [sp+A8h] [-1138h] BYREF
  __int64 v183; // [sp+B8h] [-1128h] BYREF
  idColor v184; // [sp+C0h] [-1120h] BYREF
  idVec3 v185; // [sp+D0h] [-1110h] BYREF
  idVec3 v186; // [sp+E0h] [-1100h] BYREF
  _DWORD v187[4]; // [sp+F0h] [-10F0h] BYREF
  idStr v188; // [sp+100h] [-10E0h] BYREF
  _BYTE v189[192]; // [sp+120h] [-10C0h] BYREF

  owner = this->owner;
  aas = owner->moveState->pathInfo.aas;
  if ( aas != nullptr )
  {
    Physics = idEntity::GetPhysics(this: owner->owner);
    v7 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    presentable = this->owner->owner->presentable;
    if ( presentable != nullptr )
      v9 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v9 = 0;
    v10 = (float *)(v9 + 46544);
    AreaNum = idActor::GetAreaNum(this: this->owner->owner, aas);
    v12 = aas->GetObstaclePVSWallEdges(this: (idAAS2 *)aas, a2: AreaNum, a3: 3, a4: (int *)v189, a5: 1024);
    v13 = v12;
    if ( v12 > 0 )
    {
      v14 = (int *)v189;
      v15 = &v188.baseBuffer[16];
      for ( i = v12; i != 0; --i )
      {
        if ( (aas->GetEdgeFlags(this: (idAAS2 *)aas, a2: abs32(*v14)) & 1) != 0 )
        {
          v17 = *((_DWORD *)v15 + 1);
          v15 += 4;
          *(_DWORD *)v15 = *v14;
          *v14 = v17;
        }
        ++v14;
      }
    }
    if ( v13 > 0 )
    {
      v18 = (int *)v189;
      do
      {
        aas->GetEdge(this: (idAAS2 *)aas, a2: *v18, a3: &v186, a4: &v185);
        idBot::ProjectTopDown(this: this->owner, point: &v186);
        idBot::ProjectTopDown(this: this->owner, point: &v185);
        v19 = (aas->GetEdgeFlags(this: (idAAS2 *)aas, a2: abs32(*v18)) & 1) == 0;
        GetRenderWorld = (int (*)(void))gameLocal->GetRenderWorld;
        if ( v19 )
        {
          v21 = GetRenderWorld();
          v22 = &idColor::colorPurple;
        }
        else
        {
          v21 = GetRenderWorld();
          v22 = &idColor::colorCyan;
        }
        (*(void (__fastcall **)(int, idColor *, idVec3 *, idVec3 *, _DWORD, _DWORD))(*(_DWORD *)v21 + 176))(
          a1: v21,
          a2: v22,
          a3: &v186,
          a4: &v185,
          a5: 0,
          a6: 0);
        --v13;
        ++v18;
      }
      while ( v13 != 0 );
    }
    v23 = *(float *)(v7 + 4);
    v24 = *(float *)(v7 + 8);
    v25 = this->owner;
    v181.x = *(float *)v7;
    v181.y = v23;
    v181.z = v24;
    v26 = *(float *)(v7 + 8);
    v27 = *(float *)(v7 + 4);
    v28 = (float)(v10[1] * (float)32.0);
    v29 = (float)(v10[2] * (float)32.0);
    v170.x = *(float *)v7 + (float)(*v10 * (float)32.0);
    v170.y = (float)v28 + (float)v27;
    v170.z = (float)v29 + (float)v26;
    if ( v25->owner->IsDead(this: v25->owner) )
      v30 = &idColor::colorBlack;
    else
      v30 = &idColor::colorGreen;
    g = v30->g;
    b = v30->b;
    a = v30->a;
    v34 = this->owner;
    v187[0] = LODWORD(v30->r);
    *(float *)&v187[1] = g;
    *(float *)&v187[2] = b;
    *(float *)&v187[3] = a;
    idBot::ProjectTopDown(this: v34, point: &v181);
    idBot::ProjectTopDown(this: this->owner, point: &v170);
    v35 = gameLocal->GetRenderWorld(this: gameLocal);
    v35->DebugLine(this: v35, a2: (const idVec4 *)v187, a3: &v181, a4: &v170, a5: 0, a6: false);
    v36 = this->owner;
    v37 = *(float *)(v7 + 4);
    v38 = *(float *)v7;
    v39 = (float)(v10[4] * (float)16.0);
    v40 = (float)(v10[3] * (float)16.0);
    v170.z = (float)(v10[5] * (float)16.0) + *(float *)(v7 + 8);
    v170.y = (float)v39 + (float)v37;
    v170.x = (float)v38 + (float)v40;
    idBot::ProjectTopDown(this: v36, point: &v170);
    v41 = gameLocal->GetRenderWorld(this: gameLocal);
    v41->DebugLine(this: v41, a2: (const idVec4 *)v187, a3: &v181, a4: &v170, a5: 0, a6: false);
    v42 = *(float *)(v7 + 8);
    v43 = *(float *)v7;
    v44 = (float)(v10[3] * (float)-16.0);
    v45 = (float)(v10[5] * (float)-16.0);
    v170.y = (float)(v10[4] * (float)-16.0) + *(float *)(v7 + 4);
    v170.x = (float)v43 + (float)v44;
    v170.z = (float)v45 + (float)v42;
    idBot::ProjectTopDown(this: this->owner, point: &v170);
    v46 = gameLocal->GetRenderWorld(this: gameLocal);
    v46->DebugLine(this: v46, a2: (const idVec4 *)v187, a3: &v181, a4: &v170, a5: 0, a6: false);
    v47 = 0;
    if ( this->targetRecords.num > 0 )
    {
      v48 = 0;
      while ( 1 )
      {
        v49 = &this->targetRecords.list[v48];
        p_targetEntity = &v49->targetEntity;
        value = v49->targetEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v51 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v52 = (idAI2 *)idEntity::CastTo(c: v51);
        }
        else
        {
          v52 = nullptr;
        }
        v53 = *(_DWORD *)(v52->GetType(this: v52) + 36);
        if ( v53 < idPlayer::Type.typeNum || (v55 = v53 <= idPlayer::Type.lastChild, v54 = 1, !v55) )
          v54 = 0;
        if ( v54 != 0 )
          break;
        v59 = *(_DWORD *)(v52->GetType(this: v52) + 36);
        if ( v59 < idAI2::Type.typeNum || (v55 = v59 <= idAI2::Type.lastChild, v60 = 1, !v55) )
          v60 = 0;
        if ( v60 == 0 )
        {
          v62 = idEntity::GetPhysics(this: v52);
          v63 = (float *)v62->GetAxis(this: v62, a2: 0);
          v172 = *v63;
          v173 = v63[1];
          p_targetEntity = (idEntityPtr<idEntity> *)(v63 + 6);
          v174 = v63[2];
          v175 = v63[3];
          v176 = v63[4];
          v177 = v63[5];
          v178 = v63[6];
          v179 = v63[7];
          v58 = v63[8];
LABEL_39:
          v180 = v58;
          goto LABEL_40;
        }
        v61 = idAI2::CastTo(c: v52);
        v61->GetEyeAxis(this: v61, a2: (idMat3 *)&v172);
LABEL_40:
        v64 = &idColor::colorBlue;
        if ( (v49->volatileData.targetFlags.flags & 2) == 0 )
          v64 = &idColor::colorRed;
        v65 = v64->g;
        v66 = v64->b;
        v67 = v64->a;
        v184.r = v64->r;
        v184.g = v65;
        v184.b = v66;
        v184.a = v67;
        LODWORD(v68) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                     - v49->volatileData.timeLastVisible;
        v183 = v68;
        idColor::Lerp(this: &v184, from: &v184, to: &idColor::colorLtGrey, lerp: (float)((float)v68 * (float)0.001));
        v69 = idEntity::GetPhysics(this: v52);
        v70 = (int)v69->GetOrigin(this: v69, a2: 0);
        v72 = *(float *)(v70 + 4);
        v73 = *(float *)(v70 + 8);
        v71 = this->owner;
        v182.x = *(float *)v70;
        v182.y = v72;
        v182.z = v73;
        v74 = *(float *)(v70 + 8);
        v75 = (float)(*(float *)(v70 + 4) + (float)(v173 * (float)32.0));
        v169.x = *(float *)v70 + (float)(v172 * (float)32.0);
        v169.z = (float)v74 + (float)(v174 * (float)32.0);
        v169.y = v75;
        idBot::ProjectTopDown(this: v71, point: &v182);
        idBot::ProjectTopDown(this: this->owner, point: &v169);
        v76 = gameLocal->GetRenderWorld(this: gameLocal);
        v76->DebugLine(this: v76, a2: (const idVec4 *)&v184, a3: &v182, a4: &v169, a5: 0, a6: false);
        v77 = (float)(*(float *)(v70 + 4) + (float)(v176 * (float)16.0));
        v78 = (float)(*(float *)v70 + (float)(v175 * (float)16.0));
        v169.z = *(float *)(v70 + 8) + (float)(v177 * (float)16.0);
        v169.y = v77;
        v169.x = v78;
        idBot::ProjectTopDown(this: this->owner, point: &v169);
        v79 = gameLocal->GetRenderWorld(this: gameLocal);
        v79->DebugLine(this: v79, a2: (const idVec4 *)&v184, a3: &v182, a4: &v169, a5: 0, a6: false);
        v80 = *(float *)(v70 + 4);
        v81 = this->owner;
        v82 = *(float *)v70;
        v169.z = *(float *)(v70 + 8) + (float)(v177 * (float)-16.0);
        v169.y = (float)v80 + (float)(v176 * (float)-16.0);
        v169.x = (float)v82 + (float)(v175 * (float)-16.0);
        idBot::ProjectTopDown(this: v81, point: &v169);
        v83 = gameLocal->GetRenderWorld(this: gameLocal);
        v83->DebugLine(this: v83, a2: (const idVec4 *)&v184, a3: &v182, a4: &v169, a5: 0, a6: false);
        ++v47;
        ++v48;
        if ( v47 >= this->targetRecords.num )
          goto LABEL_43;
      }
      v56 = idPlayer::CastTo(c: (idPlayer *)v52)->presentable;
      if ( v56 != nullptr )
        v57 = (float *)v56->GetPlayerInterface_2(this: v56);
      else
        v57 = nullptr;
      v172 = v57[11636];
      v173 = v57[11637];
      v174 = v57[11638];
      v175 = v57[11639];
      v176 = v57[11640];
      v177 = v57[11641];
      v178 = v57[11642];
      v179 = v57[11643];
      v58 = v57[11644];
      goto LABEL_39;
    }
LABEL_43:
    targetFilter = this->targetFilter;
    if ( targetFilter != nullptr )
      v85 = (const char *)((int (*)(void))targetFilter->GetDebugName)();
    else
      v85 = "<NONE>";
    v86 = idGuiListBox::Row(this: infoList);
    v90 = idGuiListBox::Printf(this: v86, fmt: "Target Filter: ", a3: v89, a4: v88, a5: v87);
    HIDWORD(v91) = v85;
    idGuiListBox::Printf(this: v90, fmt: "%s", a3: v91, a4: v93, a5: v92);
    num = this->targetRecords.num;
    v95 = idGuiListBox::Row(this: infoList);
    LODWORD(v96) = &off_822B0000;
    v99 = idGuiListBox::Printf(this: v95, fmt: "# Tracked Ents: ", a3: v98, a4: v97, a5: v96);
    HIDWORD(v100) = num;
    idGuiListBox::Printf(this: v99, fmt: "%d", a3: v100, a4: v102, a5: v101);
    p_goalEnemy = &this->owner->goalTask.goalEnemy;
    p_targetEntity = p_goalEnemy;
    if ( gameLocal->spawnIds.ptr[p_goalEnemy->spawnId.value & 0x1FFF] == p_goalEnemy->spawnId.value >> 13
      && (v104 = gameLocal->entities.ptr[p_goalEnemy->spawnId.value & 0x1FFF]) != nullptr )
    {
      v105 = (idPlayer *)idEntity::CastTo(c: v104);
    }
    else
    {
      v105 = nullptr;
    }
    idStr::idStr(this: &v188, text: "<NONE>");
    if ( v105 != nullptr )
    {
      v106 = *(_DWORD *)(v105->GetType(this: v105) + 36);
      if ( v106 < idPlayer::Type.typeNum || (v55 = v106 <= idPlayer::Type.lastChild, v107 = 1, !v55) )
        v107 = 0;
      if ( v107 != 0 )
      {
        v108 = session->GetActingGameStateLobbyBase(this: session);
        v109 = idPlayer::CastTo(c: v105)->presentable;
        if ( v109 != nullptr )
          v110 = (lobbyUserID_t *)v109->GetPlayerInterface_2(this: v109);
        else
          v110 = nullptr;
        LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v183, result: v110);
        data = v108->GetLobbyUserName(this: LobbyUserID->localUserHandle.handle, a2: *(_DWORD *)&LobbyUserID->lobbyType);
      }
      else
      {
        data = v105->name.data;
      }
      idStr::operator=(this: &v188, text: data);
    }
    v113 = false;
    v114 = false;
    v115 = false;
    v116 = false;
    health = 0.0;
    if ( v105 != nullptr )
    {
      RecordIndexForEntity = idBotWorldState::GetRecordIndexForEntity(this, entity: v105);
      if ( RecordIndexForEntity != -1 )
      {
        v119 = &this->targetRecords.list[RecordIndexForEntity];
        health = v119->volatileData.health;
        v113 = (v119->volatileData.targetFlags.flags & 0x20) != 0;
        v114 = (v119->volatileData.targetFlags.flags & 0x40) != 0;
        v115 = (v119->volatileData.targetFlags.flags & 8) != 0;
        v116 = (v119->volatileData.targetFlags.flags & 0x10) != 0;
      }
    }
    v120 = v188.data;
    v121 = idGuiListBox::Row(this: infoList);
    v125 = idGuiListBox::Printf(this: v121, fmt: "Enemy Name: ", a3: v124, a4: v123, a5: v122);
    HIDWORD(v126) = v120;
    idGuiListBox::Printf(this: v125, fmt: "%s", a3: v126, a4: v128, a5: v127);
    v129 = idGuiListBox::Row(this: infoList);
    LODWORD(v130) = &off_822B0000;
    v133 = idGuiListBox::Printf(this: v129, fmt: "Enemy Health: ", a3: v132, a4: v131, a5: v130);
    HIDWORD(v134) = "ound traces";
    HIDWORD(v135) = LODWORD(health);
    idGuiListBox::Printf(this: v133, fmt: (const char *)HIDWORD(health), a3: v135, a4: v136, a5: v134, health);
    v137 = idGuiListBox::Row(this: infoList);
    LODWORD(v138) = &off_822B0000;
    v141 = idGuiListBox::Printf(this: v137, fmt: "Enemy Can See: ", a3: v140, a4: v138, a5: v139);
    HIDWORD(v142) = v113;
    idGuiListBox::Printf(this: v141, fmt: "%d", a3: v142, a4: v144, a5: v143);
    v145 = idGuiListBox::Row(this: infoList);
    HIDWORD(v146) = &off_822B0000;
    v149 = idGuiListBox::Printf(this: v145, fmt: "Enemy Can Hear: ", a3: v148, a4: v146, a5: v147);
    HIDWORD(v150) = v114;
    idGuiListBox::Printf(this: v149, fmt: "%d", a3: v150, a4: v152, a5: v151);
    v153 = idGuiListBox::Row(this: infoList);
    LODWORD(v154) = &off_822B0000;
    v157 = idGuiListBox::Printf(this: v153, fmt: "Enemy Visible: ", a3: v154, a4: v156, a5: v155);
    HIDWORD(v158) = v115;
    idGuiListBox::Printf(this: v157, fmt: "%d", a3: v158, a4: v160, a5: v159);
    v161 = idGuiListBox::Row(this: infoList);
    HIDWORD(v162) = &off_822B0000;
    v165 = idGuiListBox::Printf(this: v161, fmt: "Enemy Audible: ", a3: v162, a4: v164, a5: v163);
    HIDWORD(v166) = v116;
    idGuiListBox::Printf(this: v165, fmt: "%d", a3: v166, a4: v168, a5: v167);
    idStr::FreeData(this: &v188);
  }
}


// ========================================================================
// __unwind$490587
// EA  : 0x82B46150
// RVA : 0x00B46150
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void _unwind_490587()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 256));
}


// ========================================================================
// ?Reset@idBotTargetFilter@@UAAXXZ
// EA  : 0x82B462E0
// RVA : 0x00B462E0
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotTargetFilter::Reset(idBotTargetFilter *this)
{
  this->bestTargetIndex = -1;
  this->bestTarget.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?ClearVolatileData@idBotWorldState@@QAAXXZ
// EA  : 0x82B462F8
// RVA : 0x00B462F8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotWorldState::ClearVolatileData(idBotWorldState *this)
{
  int num; // r31
  int v3; // r30
  idBotTargetFilter *targetFilter; // r3

  num = this->targetRecords.num;
  if ( num > 0 )
  {
    v3 = 0;
    do
    {
      idBotTargetRecord::volatileData_t::Clear(this: &this->targetRecords.list[v3].volatileData);
      --num;
      ++v3;
    }
    while ( num != 0 );
  }
  targetFilter = this->targetFilter;
  if ( targetFilter != nullptr )
    targetFilter->Reset(this: targetFilter);
  this->enemyCheckDebounce = 0;
  this->lastEnemyUpdateTime = 0;
  this->lastAttackerTime = 0;
  this->lastAttacker.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?SetLastAttacker@idBotWorldState@@QAAXPBVidEntity@@H@Z
// EA  : 0x82B46370
// RVA : 0x00B46370
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotWorldState::SetLastAttacker(idBotWorldState *this, const idEntity *attacker, int time)
{
  if ( attacker != nullptr )
    this->lastAttacker.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13) | attacker->entityNumber;
  else
    this->lastAttacker.spawnId.value = 0x1FFF;
  this->lastAttackerTime = time;
}


// ========================================================================
// ?CheckTarget@idBotClosestVisibleTargetFilter@@UAAXHAAVidBotTargetRecord@@@Z
// EA  : 0x82B463B8
// RVA : 0x00B463B8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotClosestVisibleTargetFilter::CheckTarget(
        idBotClosestVisibleTargetFilter *this,
        int index,
        idBotTargetRecord *targetRecord,
        int a4,
        int a5,
        __int64 a6)
{
  int flags; // r11
  idEntity *v10; // r3

  flags = targetRecord->volatileData.targetFlags.flags;
  if ( (flags & 2) == 0
    && (flags & 4) == 0
    && targetRecord->volatileData.health > 0.0
    && targetRecord->volatileData.timeLastVisible != 0 )
  {
    LODWORD(a6) = targetRecord->volatileData.timeLastVisible;
    if ( ((float)((float)a6 + (float)10000.0) >= (double)(float)__SPAIR64__(
                                                                  &off_822B0000,
                                                                  idGameTimeManager::GetGameMs(
                                                                    this: &clientGame->gameTimeManager,
                                                                    type: GAMETIME_SCALED))
       || (targetRecord->volatileData.targetFlags.flags & 0x40) != 0)
      && targetRecord->volatileData.distToTarget < (double)this->closestDistance )
    {
      this->bestTargetIndex = index;
      v10 = idEntityPtr<idEntity const>::operator->(this: &targetRecord->targetEntity);
      if ( v10 != nullptr )
        this->bestTarget.spawnId.value = (gameLocal->spawnIds.ptr[v10->entityNumber] << 13) | v10->entityNumber;
      else
        this->bestTarget.spawnId.value = 0x1FFF;
      this->closestDistance = targetRecord->volatileData.distToTarget;
    }
  }
}


// ========================================================================
// ?Reset@idBotClosestVisibleTargetFilter@@UAAXXZ
// EA  : 0x82B464E0
// RVA : 0x00B464E0
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotClosestVisibleTargetFilter::Reset(idBotClosestVisibleTargetFilter *this)
{
  this->bestTargetIndex = -1;
  this->bestTarget.spawnId.value = 0x1FFF;
  this->closestDistance = 3.4028235e38;
}


// ========================================================================
// ??1idBotTargetRecord@@QAA@XZ
// EA  : 0x82B46500
// RVA : 0x00B46500
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotTargetRecord::~idBotTargetRecord(idBotTargetRecord *this)
{
  idBotTargetRecord::volatileData_t::Clear(this: &this->volatileData);
  this->targetEntity.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?UpdateTargetsInfo@idBotWorldState@@QAAXXZ
// EA  : 0x82B46538
// RVA : 0x00B46538
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBotWorldState::UpdateTargetsInfo(idBotWorldState *this)
{
  idPresentable *presentable; // r3
  const idAngles *v3; // r4
  idAngles *ViewAngles; // r3
  idPresentable *v5; // r3
  int v6; // r3
  float *v7; // r20
  int GameMs; // r19
  gameTeam_t Team; // r17
  int v10; // r31
  int v11; // r15
  idBotTargetRecord *v12; // r28
  int value; // r9
  idEntity *v14; // r3
  __int64 v15; // r9 OVERLAPPED
  idEntity *v16; // r3
  idPlayer *v17; // r30
  int v18; // r10
  bool v19; // r23
  double v20; // fp31
  double v23; // fp6
  double v24; // fp1
  double v25; // fp28
  double v26; // fp30
  bool v27; // r24
  int v28; // r3
  double v29; // fp25
  gameTeam_t v30; // r31
  idGameChallenge *ChallengeEntity; // r3
  bool v32; // r27
  bool v33; // r25
  char v34; // r26
  bool v35; // r29
  idPlayer *v36; // r31
  bool v37; // r29
  idPresentable *v38; // r3
  int v39; // r3
  bool IsCrouching; // r3
  idPresentable *v41; // r11
  const idAngles *v42; // r4
  idAngles *v43; // r3
  double v46; // fp0
  double v47; // fp9
  double v48; // fp0
  double v49; // fp9
  int v50; // r11
  char v51; // r11
  bool v52; // zf
  bool v53; // r31
  idPlayer *owner; // r14
  idBotTraceManager *BotTraceManager; // r3
  int v56; // r6
  int v57; // r5
  bool IsVisible; // r3
  int flags; // r11
  __int64 v60; // r8
  unsigned int v61; // r10
  unsigned int v62; // r11
  unsigned int v63; // r10
  unsigned int v64; // r11
  unsigned int v65; // r10
  int v66; // r11
  unsigned int v67; // r9
  unsigned int v68; // r11
  unsigned int v69; // r9
  int v70; // r9
  unsigned int v71; // r8
  unsigned int v72; // r9
  double v73; // fp0
  int v74; // r3
  double v75; // fp0
  char v76; // r10
  int v77; // r10
  unsigned int v78; // r9
  idLeakyIntegrator<0,1> *p_audibleTracker; // r3
  char IsStillTriggered; // r3
  int v81; // r10
  unsigned int v82; // r9
  bool v83; // [sp+50h] [-150h]
  int v84; // [sp+54h] [-14Ch]
  idPlayer *DebugPlayer; // [sp+58h] [-148h]
  __int64 v86; // [sp+68h] [-138h] BYREF
  float v87; // [sp+78h] [-128h] BYREF
  float v88; // [sp+7Ch] [-124h]
  float v89; // [sp+80h] [-120h]
  idVec3 v90; // [sp+88h] [-118h] BYREF
  idVec3 v91; // [sp+98h] [-108h] BYREF
  char v92; // [sp+A8h] [-F8h] BYREF

  presentable = this->owner->owner->presentable;
  if ( presentable != nullptr )
    v3 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = nullptr;
  ViewAngles = (idAngles *)idPresentablePlayer::GetViewAngles(
                             this: (idPresentablePlayer *)&v86,
                             result: v3,
                             includeWeaponKick: true);
  idAngles::ToVectors(this: ViewAngles, forward: &v90, right: nullptr, up: nullptr);
  v5 = this->owner->owner->presentable;
  if ( v5 != nullptr )
    v6 = (int)v5->GetPlayerInterface_2(this: v5);
  else
    v6 = 0;
  v7 = (float *)(v6 + 46532);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  Team = idEntity::GetTeam(this: this->owner->owner);
  v83 = bot_followPlayer.valueInteger != 0;
  v10 = 0;
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v84 = 0;
  if ( this->targetRecords.num > 0 )
  {
    v11 = 0;
    do
    {
      v12 = &this->targetRecords.list[v11];
      value = v12->targetEntity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v14 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v14 != nullptr )
        {
          v16 = idEntity::CastTo(c: v14);
          v17 = (idPlayer *)v16;
          if ( v16 != nullptr )
          {
            v18 = GameMs;
            LODWORD(v15) = v12->volatileData.timeLastAttackedBy;
            v86 = v15;
            v19 = (float)((float)v15 + (float)5000.0) > (double)(float)*(__int64 *)((char *)&v15 - 4);
            v16->GetEyePos(this: v16, a2: (idVec3 *)&v87);
            v20 = (float)(v89 - v7[2]);
            _FP10 = (float)((float)((float)((float)(v89 - v7[2]) * (float)(v89 - v7[2]))
                                  + (float)((float)((float)(v88 - v7[1]) * (float)(v88 - v7[1]))
                                          + (float)((float)(v87 - *v7) * (float)(v87 - *v7))))
                          - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f7, f10, f12, f0 }
            v23 = __frsqrte(_FP7);
            v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23
                                                                                                * (float)((float)((float)((float)(v89 - v7[2]) * (float)(v89 - v7[2])) + (float)((float)((float)(v88 - v7[1]) * (float)(v88 - v7[1])) + (float)((float)(v87 - *v7) * (float)(v87 - *v7)))) * (float)0.5))
                                                                                        * (float)v23)
                                                                                - (float)1.5)
                                                                * (float)v23)
                                                        * (float)((float)((float)((float)(v89 - v7[2])
                                                                                * (float)(v89 - v7[2]))
                                                                        + (float)((float)((float)(v88 - v7[1])
                                                                                        * (float)(v88 - v7[1]))
                                                                                + (float)((float)(v87 - *v7)
                                                                                        * (float)(v87 - *v7))))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v23
                                                                                        * (float)((float)((float)((float)(v89 - v7[2]) * (float)(v89 - v7[2])) + (float)((float)((float)(v88 - v7[1]) * (float)(v88 - v7[1])) + (float)((float)(v87 - *v7) * (float)(v87 - *v7))))
                                                                                                * (float)0.5))
                                                                                * (float)v23)
                                                                        - (float)1.5)
                                                        * (float)v23))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v23
                                                                * (float)((float)((float)((float)(v89 - v7[2])
                                                                                        * (float)(v89 - v7[2]))
                                                                                + (float)((float)((float)(v88 - v7[1])
                                                                                                * (float)(v88 - v7[1]))
                                                                                        + (float)((float)(v87 - *v7)
                                                                                                * (float)(v87 - *v7))))
                                                                        * (float)0.5))
                                                        * (float)v23)
                                                - (float)1.5)
                                * (float)v23));
            v25 = (float)((float)((float)-(float)((float)((float)((float)v24
                                                                * (float)((float)((float)((float)(v89 - v7[2])
                                                                                        * (float)(v89 - v7[2]))
                                                                                + (float)((float)((float)(v88 - v7[1])
                                                                                                * (float)(v88 - v7[1]))
                                                                                        + (float)((float)(v87 - *v7)
                                                                                                * (float)(v87 - *v7))))
                                                                        * (float)0.5))
                                                        * (float)v24)
                                                - (float)1.5)
                                * (float)v24)
                        * (float)((float)((float)(v89 - v7[2]) * (float)(v89 - v7[2]))
                                + (float)((float)((float)(v88 - v7[1]) * (float)(v88 - v7[1]))
                                        + (float)((float)(v87 - *v7) * (float)(v87 - *v7)))));
            v26 = (float)((float)(v90.z
                                * (float)((float)((float)-(float)((float)((float)((float)v24
                                                                                * (float)((float)((float)((float)(v89 - v7[2]) * (float)(v89 - v7[2]))
                                                                                                + (float)((float)((float)(v88 - v7[1]) * (float)(v88 - v7[1])) + (float)((float)(v87 - *v7) * (float)(v87 - *v7))))
                                                                                        * (float)0.5))
                                                                        * (float)v24)
                                                                - (float)1.5)
                                                * (float)v24)
                                        * (float)(v89 - v7[2])))
                        + (float)((float)(v90.y
                                        * (float)((float)(v88 - v7[1])
                                                * (float)((float)-(float)((float)((float)((float)v24
                                                                                        * (float)((float)((float)((float)(v89 - v7[2]) * (float)(v89 - v7[2])) + (float)((float)((float)(v88 - v7[1]) * (float)(v88 - v7[1])) + (float)((float)(v87 - *v7) * (float)(v87 - *v7))))
                                                                                                * (float)0.5))
                                                                                * (float)v24)
                                                                        - (float)1.5)
                                                        * (float)v24)))
                                + (float)(v90.x
                                        * (float)((float)(v87 - *v7)
                                                * (float)((float)-(float)((float)((float)((float)v24
                                                                                        * (float)((float)((float)((float)(v89 - v7[2]) * (float)(v89 - v7[2])) + (float)((float)((float)(v88 - v7[1]) * (float)(v88 - v7[1])) + (float)((float)(v87 - *v7) * (float)(v87 - *v7))))
                                                                                                * (float)0.5))
                                                                                * (float)v24)
                                                                        - (float)1.5)
                                                        * (float)v24)))));
            v27 = v26 > this->fov;
            v28 = (int)v17->GetHealthComponent_2(this: v17);
            if ( v28 != 0 )
              v29 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v28 + 76))(a1: v28);
            else
              v29 = 0.0;
            v30 = idEntity::GetTeam(this: v17);
            ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
            v32 = false;
            v33 = (_cntlzw(idGameChallenge::IsHostile(this: ChallengeEntity, team1: v30, team2: Team)) & 0x20) != 0;
            v34 = 0;
            v35 = false;
            v36 = idPlayer::CastTo(c: v17);
            idAI2::CastTo(c: (idAI2 *)v17);
            if ( v36 != nullptr )
            {
              v37 = (_cntlzw((char *)DebugPlayer - (char *)v36) & 0x20) != 0;
              if ( (*((_BYTE *)v36 + 12824) & 8) != 0
                || ((v38 = v36->presentable) == nullptr ? (v39 = 0) : (v39 = (int)v38->GetPlayerInterface_2(this: v38)),
                    (*(_BYTE *)(v39 + 47032) & 0x20) != 0 || v83 && v37) )
              {
                v34 = 1;
              }
              IsCrouching = idActor::IsCrouching(this: v36);
              v41 = v36->presentable;
              v32 = IsCrouching;
              if ( v41 != nullptr )
                v42 = (const idAngles *)v41->GetPlayerInterface_2(this: v36->presentable);
              else
                v42 = nullptr;
              v43 = (idAngles *)idPresentablePlayer::GetViewAngles(
                                  this: (idPresentablePlayer *)&v92,
                                  result: v42,
                                  includeWeaponKick: true);
              idAngles::ToVectors(this: v43, forward: &v91, right: nullptr, up: nullptr);
              _FP9 = (float)((float)((float)((float)(v7[1] - v88) * (float)(v7[1] - v88))
                                   + (float)((float)((float)(*v7 - v87) * (float)(*v7 - v87))
                                           + (float)((float)(v7[2] - v89) * (float)(v7[2] - v89))))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f6, f9, f10, f0 }
              v46 = __frsqrte(_FP6);
              v47 = (float)((float)-(float)((float)((float)((float)v46
                                                          * (float)((float)((float)((float)(v7[1] - v88)
                                                                                  * (float)(v7[1] - v88))
                                                                          + (float)((float)((float)(*v7 - v87)
                                                                                          * (float)(*v7 - v87))
                                                                                  + (float)((float)(v7[2] - v89)
                                                                                          * (float)(v7[2] - v89))))
                                                                  * (float)0.5))
                                                  * (float)v46)
                                          - (float)1.5)
                          * (float)v46);
              v48 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46
                                                                                          * (float)((float)((float)((float)(v7[1] - v88) * (float)(v7[1] - v88)) + (float)((float)((float)(*v7 - v87) * (float)(*v7 - v87)) + (float)((float)(v7[2] - v89) * (float)(v7[2] - v89))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v46)
                                                                          - (float)1.5)
                                                          * (float)v46)
                                                  * (float)((float)((float)((float)(v7[1] - v88) * (float)(v7[1] - v88))
                                                                  + (float)((float)((float)(*v7 - v87)
                                                                                  * (float)(*v7 - v87))
                                                                          + (float)((float)(v7[2] - v89)
                                                                                  * (float)(v7[2] - v89))))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v46
                                                                                  * (float)((float)((float)((float)(v7[1] - v88) * (float)(v7[1] - v88))
                                                                                                  + (float)((float)((float)(*v7 - v87) * (float)(*v7 - v87)) + (float)((float)(v7[2] - v89) * (float)(v7[2] - v89))))
                                                                                          * (float)0.5))
                                                                          * (float)v46)
                                                                  - (float)1.5)
                                                  * (float)v46))
                                  - (float)1.5);
              v49 = (float)((float)-(float)((float)((float)((float)((float)v48 * (float)v47)
                                                          * (float)((float)((float)((float)(v7[1] - v88)
                                                                                  * (float)(v7[1] - v88))
                                                                          + (float)((float)((float)(*v7 - v87)
                                                                                          * (float)(*v7 - v87))
                                                                                  + (float)((float)(v7[2] - v89)
                                                                                          * (float)(v7[2] - v89))))
                                                                  * (float)0.5))
                                                  * (float)((float)v48 * (float)v47))
                                          - (float)1.5)
                          * (float)((float)v48 * (float)v47));
              v35 = (float)((float)(v91.y * (float)((float)(v7[1] - v88) * (float)v49))
                          + (float)((float)(v91.x * (float)((float)(*v7 - v87) * (float)v49))
                                  + (float)(v91.z * (float)((float)(v7[2] - v89) * (float)v49)))) > (double)this->fov;
            }
            v50 = *(_DWORD *)(v17->GetType(this: v17) + 36);
            if ( v50 < idAI2::Type.typeNum || (v52 = v50 <= idAI2::Type.lastChild, v51 = 1, !v52) )
              v51 = 0;
            v53 = v51 != 0;
            owner = this->owner->owner;
            BotTraceManager = idGameLocal::BotSystems_GetBotTraceManager(this: gameLocal);
            IsVisible = idBotTraceManager::IsVisible(this: BotTraceManager, ent: owner, otherEnt: v17, timeDelta: 0);
            flags = v12->volatileData.targetFlags.flags;
            HIDWORD(v60) = v35;
            v61 = flags | 0x100;
            if ( !v35 )
              v61 = flags & 0xFFFFFEFF;
            v12->volatileData.targetFlags.flags = v61;
            v62 = v61;
            v63 = v61 | 0x80;
            if ( !v32 )
              v63 = v62 & 0xFFFFFF7F;
            v12->volatileData.targetFlags.flags = v63;
            v64 = v63;
            v65 = v63 | 4;
            if ( v34 == 0 )
              v65 = v64 & 0xFFFFFFFB;
            v12->volatileData.targetFlags.flags = v65;
            v12->volatileData.distToTarget = v25;
            v66 = v12->volatileData.targetFlags.flags;
            v67 = v66 | 1;
            if ( !v27 )
              v67 = v66 & 0xFFFFFFFE;
            v12->volatileData.targetFlags.flags = v67;
            v68 = v67;
            v69 = v67 | 2;
            if ( !v33 )
              v69 = v68 & 0xFFFFFFFD;
            v12->volatileData.targetFlags.flags = v69;
            v12->volatileData.dotToTarget = v26;
            v12->volatileData.heightOfTarget = v20;
            v70 = v12->volatileData.targetFlags.flags;
            v71 = v70 | 8;
            if ( !IsVisible )
              v71 = v70 & 0xFFFFFFF7;
            v12->volatileData.targetFlags.flags = v71;
            v72 = v71;
            LODWORD(v60) = v71 | 0x10;
            if ( !v53 )
              LODWORD(v60) = v72 & 0xFFFFFFEF;
            v12->volatileData.targetFlags.flags = v60;
            if ( IsVisible && (v27 || v19 || v53) )
            {
              if ( v19 )
                v73 = 2.0;
              else
                v73 = 1.0;
              LOBYTE(v74) = idLeakyIntegrator<0,1>::AddStimulus(
                              this: &v12->volatileData.visibleTracker,
                              curTimeMS: GameMs,
                              stimulus: (float)((float)v73 * 0.30000001),
                              a4: v57,
                              a5: v56,
                              a6: v60);
            }
            else
            {
              v75 = (float)(v12->volatileData.visibleTracker.decayRate + v12->volatileData.visibleTracker.value);
              v12->volatileData.visibleTracker.value = v12->volatileData.visibleTracker.decayRate
                                                     + v12->volatileData.visibleTracker.value;
              if ( v75 >= 0.0 )
              {
                if ( v75 > 1.0 )
                  v75 = 1.0;
              }
              else
              {
                v75 = 0.0;
              }
              v76 = *((_BYTE *)&v12->volatileData.visibleTracker + 12);
              v12->volatileData.visibleTracker.value = v75;
              if ( v76 < 0 && v75 <= 0.0 )
                *((_BYTE *)&v12->volatileData.visibleTracker + 12) = v76 & 0x7F;
              v74 = *((unsigned __int8 *)&v12->volatileData.visibleTracker + 12) >> 7;
            }
            v77 = v12->volatileData.targetFlags.flags;
            v78 = v77 | 0x20;
            if ( (_BYTE)v74 == 0 )
              v78 = v77 & 0xFFFFFFDF;
            v12->volatileData.targetFlags.flags = v78;
            if ( (_BYTE)v74 != 0 )
            {
              v12->volatileData.timeLastVisible = GameMs;
              v12->volatileData.lastSeenLocation.x = v87;
              v12->volatileData.lastSeenLocation.y = v88;
              v12->volatileData.lastSeenLocation.z = v89;
              v12->volatileData.positionLastSawTarget.x = *v7;
              v12->volatileData.positionLastSawTarget.y = v7[1];
              v12->volatileData.positionLastSawTarget.z = v7[2];
            }
            p_audibleTracker = &v12->volatileData.audibleTracker;
            if ( v53 )
              IsStillTriggered = idLeakyIntegrator<0,1>::AddStimulus(
                                   this: p_audibleTracker,
                                   curTimeMS: GameMs,
                                   stimulus: 0.2,
                                   a4: v57,
                                   a5: v56,
                                   a6: v60);
            else
              IsStillTriggered = idLeakyIntegrator<0,1>::IsStillTriggered(this: p_audibleTracker);
            v81 = v12->volatileData.targetFlags.flags;
            v82 = v81 | 0x40;
            if ( IsStillTriggered == 0 )
              v82 = v81 & 0xFFFFFFBF;
            v12->volatileData.targetFlags.flags = v82;
            if ( IsStillTriggered != 0 )
            {
              v12->volatileData.lastHeardLocation.x = v87;
              v12->volatileData.lastHeardLocation.y = v88;
              v12->volatileData.lastHeardLocation.z = v89;
            }
            v12->volatileData.health = v29;
            v10 = v84;
          }
        }
      }
      ++v10;
      ++v11;
      v84 = v10;
    }
    while ( v10 < this->targetRecords.num );
  }
}


// ========================================================================
// ??0idBotWorldState@@QAA@XZ
// EA  : 0x82B47388
// RVA : 0x00B47388
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

idBotWorldState *__fastcall idBotWorldState::idBotWorldState(idBotWorldState *this, long double a2)
{
  long double v3; // fp2
  idBotTargetFilter *v4; // r3
  idBotTargetFilter *v5; // r28
  idBotTargetFilter *targetFilter; // r3

  this->lastAttackerTime = 0;
  this->lastUpdatedEntityListHandle = -1;
  this->fov = 0.0;
  this->enemyCheckDebounce = 1;
  this->lastEnemyUpdateTime = 0x80000000;
  this->targetFilter = nullptr;
  this->owner = nullptr;
  this->lastAttacker.spawnId.value = 0x1FFF;
  this->targetRecords.granularity = 0;
  this->targetRecords.memTag = 5;
  this->targetRecords.listStatic = 0;
  this->targetRecords.list = nullptr;
  this->targetRecords.size = 0;
  this->targetRecords.num = 0;
  *(double *)&a2 = g_fov.valueFloat;
  v3 = cos(x: a2);
  this->fov = *(double *)&v3;
  v4 = (idBotTargetFilter *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x10u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
  {
    v4->bestTarget.spawnId.value = 0x1FFF;
    v4->bestTarget.spawnId.value = 0x1FFF;
    v4->bestTargetIndex = -1;
    v4->__vftable = (idBotTargetFilter_vtbl *)&idBotClosestVisibleTargetFilter::`vftable';
    v4->bestTarget.spawnId.value = 0x1FFF;
    v5 = v4;
    *(float *)&v4[1].__vftable = 3.4028235e38;
  }
  else
  {
    v5 = nullptr;
  }
  targetFilter = this->targetFilter;
  if ( targetFilter != v5 )
  {
    if ( targetFilter != nullptr )
    {
      ((void (__fastcall *)(idBotTargetFilter *, int))targetFilter->dtr_idBotTargetFilter)(a1: targetFilter, a2: 1);
      this->targetFilter = nullptr;
    }
    this->targetFilter = v5;
  }
  return this;
}


// ========================================================================
// __unwind$494362
// EA  : 0x82B474C8
// RVA : 0x00B474C8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void _unwind_494362()
{
  int v0; // r12

  idList<idBotTargetRecord,5>::~idList<idBotTargetRecord,5>(this: (idList<idBotTargetRecord,5> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                                + 32));
}


// ========================================================================
// ??1idBotWorldState@@QAA@XZ
// EA  : 0x82B47500
// RVA : 0x00B47500
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotWorldState::~idBotWorldState(idBotWorldState *this)
{
  idBotTargetRecord *list; // r3
  idBotTargetFilter *targetFilter; // r3
  idBotTargetRecord *v4; // r3

  this->owner = nullptr;
  if ( this->targetRecords.listStatic == 0 || this->targetRecords.listStatic == 2 )
  {
    list = this->targetRecords.list;
    if ( list != nullptr )
      idListArrayDelete<idBotTargetRecord>(ptr: &list->volatileData, num: this->targetRecords.size);
    this->targetRecords.list = nullptr;
    this->targetRecords.size = 0;
  }
  this->targetRecords.num = 0;
  targetFilter = this->targetFilter;
  if ( targetFilter != nullptr )
  {
    ((void (__fastcall *)(idBotTargetFilter *, int))targetFilter->dtr_idBotTargetFilter)(a1: targetFilter, a2: 1);
    this->targetFilter = nullptr;
  }
  if ( this->targetRecords.listStatic == 0 || this->targetRecords.listStatic == 2 )
  {
    v4 = this->targetRecords.list;
    if ( v4 != nullptr )
      idListArrayDelete<idBotTargetRecord>(ptr: &v4->volatileData, num: this->targetRecords.size);
    this->targetRecords.list = nullptr;
    this->targetRecords.size = 0;
  }
  this->targetRecords.num = 0;
}


// ========================================================================
// __unwind$494805
// EA  : 0x82B475B8
// RVA : 0x00B475B8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void _unwind_494805()
{
  int v0; // r12

  idList<idBotTargetRecord,5>::~idList<idBotTargetRecord,5>(this: (idList<idBotTargetRecord,5> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                                + 32));
}


// ========================================================================
// ?UpdateTargets@idBotWorldState@@QAAXXZ
// EA  : 0x82B475F0
// RVA : 0x00B475F0
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotWorldState::UpdateTargets(idBotWorldState *this)
{
  idBotEntityManager *BotEntityManager; // r3
  int num; // r22
  int i; // r23
  char v5; // r24
  const idEntity *EntityForIndex; // r27
  int v7; // r28
  int v8; // r30
  idEntityPtr<idEntity> *p_targetEntity; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  idBotEntityListFilter v12; // [sp+60h] [-120h] BYREF
  idBotTargetRecord v13; // [sp+90h] [-F0h] BYREF

  if ( this->lastUpdatedEntityListHandle != idGameLocal::BotSystems_GetBotEntityManager(this: gameLocal)->currentEntityListHandle )
  {
    idList<idBotTargetRecord,5>::SetNum(this: &this->targetRecords, newNum: 0);
    idBotEntityListFilter::idBotEntityListFilter(this: &v12);
    v12.__vftable = (idBotEntityListFilter_vtbl *)&idBotTargetableEntityListFilter::`vftable';
    idBotEntityFilter::Init(this: &v12, desiredEntType: 97, desiredEntFlags: 32, ignoreEntFlags: 0);
    BotEntityManager = idGameLocal::BotSystems_GetBotEntityManager(this: gameLocal);
    idBotEntityManager::CheckEntitiesBasedOnFilter(this: BotEntityManager, filter: &v12);
    num = v12.entitiesList.num;
    if ( v12.entitiesList.num > this->targetRecords.size )
      idList<idBotTargetRecord,5>::Resize(this: &this->targetRecords, newsize: v12.entitiesList.num);
    for ( i = 0; i < num; ++i )
    {
      v5 = 0;
      EntityForIndex = idBotEntityListFilter::GetEntityForIndex(this: &v12, index: i);
      if ( EntityForIndex != idEntity::CastTo(c: this->owner->owner) )
      {
        v7 = 0;
        if ( this->targetRecords.num > 0 )
        {
          v8 = 0;
          while ( 1 )
          {
            p_targetEntity = &this->targetRecords.list[v8].targetEntity;
            if ( gameLocal->spawnIds.ptr[p_targetEntity->spawnId.value & 0x1FFF] == p_targetEntity->spawnId.value >> 13
              && (v10 = gameLocal->entities.ptr[p_targetEntity->spawnId.value & 0x1FFF]) != nullptr )
            {
              v11 = idEntity::CastTo(c: v10);
            }
            else
            {
              v11 = nullptr;
            }
            if ( v11 == EntityForIndex )
              break;
            ++v7;
            ++v8;
            if ( v7 >= this->targetRecords.num )
              goto LABEL_16;
          }
          v5 = 1;
        }
LABEL_16:
        if ( v5 == 0 )
        {
          idBotTargetRecord::idBotTargetRecord(this: &v13);
          if ( EntityForIndex != nullptr )
            v13.targetEntity.spawnId.value = (gameLocal->spawnIds.ptr[EntityForIndex->entityNumber] << 13)
                                           | EntityForIndex->entityNumber;
          else
            v13.targetEntity.spawnId.value = 0x1FFF;
          idList<idBotTargetRecord,5>::Append(this: &this->targetRecords, obj: &v13);
          idBotTargetRecord::volatileData_t::Clear(this: &v13.volatileData);
          v13.targetEntity.spawnId.value = 0x1FFF;
        }
      }
    }
    this->lastUpdatedEntityListHandle = idGameLocal::BotSystems_GetBotEntityManager(this: gameLocal)->currentEntityListHandle;
    v12.__vftable = (idBotEntityListFilter_vtbl *)&idBotTargetableEntityListFilter::`vftable';
    idBotEntityListFilter::~idBotEntityListFilter(this: &v12);
  }
}


// ========================================================================
// __unwind$494846
// EA  : 0x82B477E0
// RVA : 0x00B477E0
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void _unwind_494846()
{
  int v0; // r12

  idBotTargetableEntityListFilter::~idBotTargetableEntityListFilter(this: (idBotTargetableEntityListFilter *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$494847
// EA  : 0x82B47808
// RVA : 0x00B47808
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void _unwind_494847()
{
  int v0; // r12

  idBotTargetRecord::~idBotTargetRecord(this: (idBotTargetRecord *)(v0 - 384 + 144));
}


// ========================================================================
// ?PreCheckEntities@idBotTargetableEntityListFilter@@UAAXH@Z
// EA  : 0x82B47830
// RVA : 0x00B47830
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotTargetableEntityListFilter::PreCheckEntities(
        idBotTargetableEntityListFilter *this,
        int numEntitiesInMasterList)
{
  idList<entInfo_t,5> *p_entitiesList; // r3

  p_entitiesList = &this->entitiesList;
  if ( numEntitiesInMasterList > p_entitiesList->size )
    idList<entInfo_t,5>::Resize(this: p_entitiesList, newsize: numEntitiesInMasterList);
}


// ========================================================================
// ?CheckEntity@idBotTargetableEntityListFilter@@UAAXHABUentInfo_t@@@Z
// EA  : 0x82B47848
// RVA : 0x00B47848
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotTargetableEntityListFilter::CheckEntity(
        idBotTargetableEntityListFilter *this,
        const int index,
        const entInfo_t *entityInfo)
{
  if ( entityInfo->active )
    idList<entInfo_t,5>::Append(this: &this->entitiesList, obj: entityInfo);
}


// ========================================================================
// ?Update@idBotWorldState@@QAAXXZ
// EA  : 0x82B47868
// RVA : 0x00B47868
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __fastcall idBotWorldState::Update(idBotWorldState *this)
{
  idBotWorldState::UpdateTargets(this);
  idBotWorldState::UpdateTargetsInfo(this);
  idBotWorldState::FindBestTarget(this);
  idBotWorldState::DrawDebugInfo(this);
}


// ========================================================================
// `dynamic initializer for 'bot_debugWorldState''
// EA  : 0x8336CE70
// RVA : 0x0136CE70
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_debugWorldState__()
{
  idCVar::idCVar(
    this: &bot_debugWorldState,
    name: "bot_debugWorldState",
    value: "0",
    flags: 2,
    description: "draws world state debug information",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_debugWorldState__);
}

