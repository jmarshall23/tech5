
// ========================================================================
// ?IsScriptScenePointValid@@YA_NPBVidAI2@@PBVidScenePoint@@@Z
// EA  : 0x82AF5A30
// RVA : 0x00AF5A30
// PDB : w:\tech5\tungsten\game\ai\fsm\scenepoint_common.cpp
// ========================================================================

int __fastcall IsScriptScenePointValid(const idAI2 *ai, idScenePoint *scriptScenePoint)
{
  scenePointScriptFlags_t scriptFlags; // r28
  idPlayer *Player; // r3
  idPhysics *Physics; // r3
  const idVec3 *v7; // r3
  idPlayer *v8; // r3
  idPhysics *v9; // r3
  const idVec3 *v10; // r3
  int lastDamageTime; // r10
  int curScenePointTakeTime; // r9
  int v13; // r11
  int curScenePointActivateTime; // r10
  const idEntity *Enemy; // r3
  idAIEntityState *v16; // r3
  const idEntity *v17; // r3
  idAIEntityState *v18; // r3

  if ( ai == nullptr )
    return 0;
  if ( scriptScenePoint == nullptr )
    return 0;
  scriptFlags = scriptScenePoint->scriptFlags;
  if ( (scriptFlags & 1) == 0 )
    return 0;
  if ( (scriptFlags & 0x10) != 0 )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    if ( Player != nullptr )
    {
      Physics = idEntity::GetPhysics(this: Player);
      v7 = Physics->GetOrigin(this: Physics, a2: 0);
      if ( !scriptScenePoint->IsInArc_2(this: scriptScenePoint, a2: v7) )
        return 0;
    }
  }
  if ( (scriptFlags & 0x20) != 0 )
  {
    v8 = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    if ( v8 != nullptr )
    {
      v9 = idEntity::GetPhysics(this: v8);
      v10 = v9->GetOrigin(this: v9, a2: 0);
      if ( scriptScenePoint->IsInArc_2(this: scriptScenePoint, a2: v10) )
        return 0;
    }
  }
  if ( (scriptFlags & 0x40) != 0 )
  {
    lastDamageTime = ai->aiVolatile.memory.lastDamageTime;
    curScenePointTakeTime = ai->aiVolatile.memory.curScenePointTakeTime;
    if ( lastDamageTime > 0 && curScenePointTakeTime > 0 && lastDamageTime > curScenePointTakeTime )
      return 0;
  }
  if ( (scriptFlags & 0x80) != 0 )
  {
    v13 = ai->aiVolatile.memory.lastDamageTime;
    curScenePointActivateTime = ai->aiVolatile.memory.curScenePointActivateTime;
    if ( v13 > 0 && curScenePointActivateTime > 0 && v13 > curScenePointActivateTime )
      return 0;
  }
  if ( (scriptFlags & 0x100) != 0 )
  {
    Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
    v16 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: Enemy);
    if ( v16 != nullptr && v16->curAwareness > 1u )
      return 0;
  }
  if ( (scriptFlags & 0x200) != 0
    && (v17 = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory),
        (v18 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v17)) != nullptr)
    && idAIEntityState::IsVisible(this: v18) )
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


// ========================================================================
// ?SupportsCustomCoverSet@@YA_NPBVidAI2@@ABVidAnimWebPath@@@Z
// EA  : 0x82AF5C28
// RVA : 0x00AF5C28
// PDB : w:\tech5\tungsten\game\ai\fsm\scenepoint_common.cpp
// ========================================================================

int __fastcall SupportsCustomCoverSet(idAI2 *ai, const idAnimWebPath *animPath)
{
  __int16 v4; // r30
  __int16 v5; // r11
  int v7; // [sp+50h] [-A0h] BYREF
  idStr v8; // [sp+60h] [-90h] BYREF
  idStr v9; // [sp+80h] [-70h] BYREF
  idStr v10[2]; // [sp+A0h] [-50h] BYREF

  if ( ai != nullptr && animPath->len != 0 )
  {
    v9.len = 0;
    v9.allocedAndFlag = 20;
    v9.data = v9.baseBuffer;
    v9.baseBuffer[0] = 0;
    idAI2::GetWeaponPrefix(this: ai, subWebPrefix: &v9);
    idStr::Append(this: &v9, text: "fcover_custom");
    v8.allocedAndFlag = 20;
    v8.data = v8.baseBuffer;
    v8.len = 0;
    v8.baseBuffer[0] = 0;
    v10[0].allocedAndFlag = 20;
    v10[0].data = v10[0].baseBuffer;
    v10[0].len = 0;
    v10[0].baseBuffer[0] = 0;
    idAI2::GetSubWebAndStateFromAnimWebPath(this: ai, animWebPath: animPath->data, subWebName: &v8, stateName: v10);
    if ( idStr::Cmp(s1: v8.data, s2: v9.data) == 0 )
    {
      v4 = HIWORD(idDeclAnimWeb::GetSubWebIndexForName(
                    this: (idDeclAnimWeb *)&v7,
                    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                    subWebName: v8.data)->__vftable);
      v5 = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                    this: (idDeclAnimWeb *)((char *)&v7 + 2),
                    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                    name: v10[0].data)->__vftable);
      if ( v4 >= 0 && v5 >= 0 )
      {
        idStr::FreeData(this: v10);
        idStr::FreeData(this: &v8);
        idStr::FreeData(this: &v9);
        return 1;
      }
    }
    idStr::FreeData(this: v10);
    idStr::FreeData(this: &v8);
    idStr::FreeData(this: &v9);
  }
  return 0;
}


// ========================================================================
// __unwind$488217
// EA  : 0x82AF5D7C
// RVA : 0x00AF5D7C
// PDB : w:\tech5\tungsten\game\ai\fsm\scenepoint_common.cpp
// ========================================================================

void _unwind_488217()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$488218
// EA  : 0x82AF5DA4
// RVA : 0x00AF5DA4
// PDB : w:\tech5\tungsten\game\ai\fsm\scenepoint_common.cpp
// ========================================================================

void _unwind_488218()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$488219
// EA  : 0x82AF5DCC
// RVA : 0x00AF5DCC
// PDB : w:\tech5\tungsten\game\ai\fsm\scenepoint_common.cpp
// ========================================================================

void _unwind_488219()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 160));
}


// ========================================================================
// ?GetBestScenePoint@@YAPAVidScenePoint@@PAVidAI2@@MMABVidAIPos@@W4scenePointType_t@@W4scenePointLookFlags_t@@@Z
// EA  : 0x82AF5E00
// RVA : 0x00AF5E00
// PDB : w:\tech5\tungsten\game\ai\fsm\scenepoint_common.cpp
// ========================================================================

idScenePoint_Look *__fastcall GetBestScenePoint(
        idAI2 *ai,
        double minRange,
        double maxRange,
        const idAIPos *_focus,
        scenePointType_t spType,
        scenePointLookFlags_t lookFlags,
        scenePointType_t a7,
        int a8)
{
  double scenePointRange; // fp15
  idAIEditable::idAIActionSettings *p_actionSettings; // r28
  idAI2_vtbl *v15; // r20
  idScenePoint *LastHeldScenePoint; // r3
  idScenePoint *v17; // r30
  idScenePoint *NextScenePoint; // r3
  idScenePoint *overrideScenePoint; // r30
  idScenePoint *v21; // r3
  double v22; // fp13
  double v23; // fp12
  int num; // r30
  int v25; // r10
  idPhysics *Physics; // r3
  int v27; // r3
  float v28; // r7
  double v29; // fp0
  float v30; // r6
  idScenePoint_Look *v31; // r21
  idActor *SquadLeader; // r3
  idPhysics *v33; // r3
  float *v34; // r3
  double x; // fp20
  double y; // fp21
  double z; // fp19
  scenePointSelectionFlags_t scenePointSelectionFlags; // r27
  int v39; // r28
  int i; // r23
  idScenePoint *v41; // r3
  idScenePoint_Look *v42; // r29
  char v43; // r11
  double v44; // fp25
  double v45; // fp29
  double v46; // fp26
  double v47; // fp24
  double v48; // fp23
  double v49; // fp28
  double v52; // fp7
  double v53; // fp0
  double v54; // fp31
  double v55; // fp27
  double v56; // fp0
  double v57; // fp31
  double coverVerticalWeight; // fp27
  double v59; // fp15
  double coverRandomWeight; // fp14
  double v61; // fp27
  idScenePoint_Combat *v62; // r3
  idScenePoint_Combat *v63; // r30
  double v64; // fp0
  double v65; // fp13
  double v66; // fp31
  double v69; // fp2
  double v70; // fp1
  double v73; // fp10
  double v74; // fp9
  double v75; // fp10
  double v76; // fp9
  double v77; // fp12
  double v78; // fp11
  idScenePoint_Look *v79; // r3
  double v80; // fp1
  double v83; // fp12
  double v84; // fp5
  idEntity *Enemy; // r3
  idEntity *v86; // r30
  float *presentable; // r11
  float v88; // r10
  float v89; // r9
  float v90; // r8
  double v91; // fp0
  idAIMemory *p_memory; // r3
  double LookScenePointHistoryScore; // fp1
  double v94; // fp0
  double ScenePointHistoryScore; // fp1
  double coverHistoryWeight; // fp0
  int v97; // r10
  float v98; // [sp+50h] [-1A0h]
  float v99; // [sp+54h] [-19Ch]
  float v100; // [sp+68h] [-188h] BYREF
  float v101; // [sp+6Ch] [-184h]
  float v102; // [sp+70h] [-180h]
  idVec3 v103; // [sp+78h] [-178h] BYREF
  idVec3 v104; // [sp+88h] [-168h] BYREF
  idVec3 v105; // [sp+98h] [-158h] BYREF
  float v106; // [sp+A8h] [-148h]
  float v107; // [sp+ACh] [-144h]
  float v108; // [sp+B0h] [-140h]
  idVec3 v109; // [sp+B8h] [-138h] BYREF
  float v110[6]; // [sp+C8h] [-128h] BYREF
  idList<idEntityPtr<idAISearchHintGroup>,5> v111[10]; // [sp+E0h] [-110h] BYREF
  float v112; // [sp+214h] [+24h]

  v112 = maxRange;
  scenePointRange = maxRange;
  if ( ai == nullptr )
    return nullptr;
  p_actionSettings = &ai->aiEditable.actionSettings;
  if ( (unsigned __int8)idAIEditable::idAIActionSettings::UsesScenePointType(
                          this: &ai->aiEditable.actionSettings,
                          type: a7) == 0 )
    return nullptr;
  v15 = (idAI2_vtbl *)gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  LastHeldScenePoint = idAIMemory::GetLastHeldScenePoint(this: &ai->aiVolatile.memory);
  v17 = LastHeldScenePoint;
  if ( LastHeldScenePoint != nullptr && a7 != LOOK )
  {
    NextScenePoint = idScenePoint::GetNextScenePoint(this: LastHeldScenePoint, spTypeRequired: a7);
    if ( NextScenePoint != nullptr )
    {
      if ( (*(_BYTE *)&NextScenePoint->flags & 8) != 0 )
        idAIMemory::SetOverrideScenePoint(this: &ai->aiVolatile.memory, scenePoint: NextScenePoint);
    }
    else
    {
      v21 = idScenePoint::GetNextScenePoint(this: v17, spTypeRequired: (scenePointType_t)0);
      if ( v21 != nullptr && (*(_BYTE *)&v21->flags & 8) != 0 )
      {
        idAIMemory::SetOverrideScenePoint(this: &ai->aiVolatile.memory, scenePoint: v21);
        return nullptr;
      }
    }
  }
  overrideScenePoint = ai->aiVolatile.memory.overrideScenePoint;
  if ( overrideScenePoint != nullptr )
  {
    if ( (*(_BYTE *)&overrideScenePoint->flags & 8) != 0 && overrideScenePoint->type == a7 )
    {
      if ( (overrideScenePoint->scriptFlags & 1) != 0
        && (unsigned __int8)IsScriptScenePointValid(ai, scriptScenePoint: ai->aiVolatile.memory.overrideScenePoint) != 0 )
      {
        goto LABEL_13;
      }
    }
    else
    {
      overrideScenePoint = nullptr;
    }
  }
  if ( *(_BYTE *)(lookFlags + 12) == 0 )
    return nullptr;
  v22 = *(float *)(lookFlags + 4);
  v23 = *(float *)(lookFlags + 8);
  v100 = *(float *)lookFlags;
  v101 = v22;
  v102 = v23;
  if ( overrideScenePoint != nullptr )
  {
    if ( a7 == ROAM )
      goto LABEL_13;
    if ( a7 <= ROAM || a7 > 4 )
      return nullptr;
    if ( overrideScenePoint->IsInArc_2(this: overrideScenePoint, a2: (const idVec3 *)&v100) )
    {
LABEL_13:
      idAIMemory::SetOverrideScenePoint(this: &ai->aiVolatile.memory, scenePoint: nullptr);
      return (idScenePoint_Look *)overrideScenePoint;
    }
  }
  if ( ai->aiVolatile.memory.scenePointVolumes.num <= 0 )
    return nullptr;
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)v111);
  idAIMemory::GetScenePoints(this: &ai->aiVolatile.memory, spList: v111, spType: a7);
  num = v111[0].num;
  if ( v111[0].num <= 0 )
  {
    v25 = 59076;
    if ( a7 != LOOK )
      v25 = 59072;
    *(idAI2_vtbl **)((char *)&ai->__vftable + v25) = v15;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v111);
    return nullptr;
  }
  Physics = idEntity::GetPhysics(this: ai);
  v27 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v28 = *(float *)(v27 + 4);
  v29 = (float)((float)scenePointRange - (float)minRange);
  v30 = *(float *)(v27 + 8);
  v31 = nullptr;
  v105.x = *(float *)v27;
  v98 = 0.0;
  v105.y = v28;
  v105.z = v30;
  if ( scenePointRange < minRange )
    v29 = (float)((float)minRange + (float)1000.0);
  v99 = (float)1.0 / (float)v29;
  if ( (unsigned __int8)idAIEditable::idAIActionSettings::HasSquadLeader(this: p_actionSettings) != 0 )
  {
    SquadLeader = (idActor *)idAIEditable::idAIActionSettings::GetSquadLeader(this: p_actionSettings);
    v33 = idEntity::GetPhysics(this: SquadLeader);
    v34 = (float *)v33->GetOrigin(this: v33, a2: 0);
    scenePointRange = ai->aiEditable.actionSettings.squad.scenePointRange;
    minRange = 0.0;
    x = *v34;
    y = v34[1];
    z = v34[2];
    v112 = ai->aiEditable.actionSettings.squad.scenePointRange;
  }
  else
  {
    z = v105.z;
    y = v105.y;
    x = v105.x;
  }
  scenePointSelectionFlags = ai->aiEditable.actionSettings.cover.scenePointSelectionFlags;
  if ( num <= 0 )
  {
LABEL_109:
    v97 = 59076;
    if ( a7 != LOOK )
      v97 = 59072;
    *(idAI2_vtbl **)((char *)&ai->__vftable + v97) = v15;
    goto LABEL_112;
  }
  v39 = 0;
  for ( i = num; i != 0; --i )
  {
    v41 = idEntityPtr<idScenePoint>::operator idScenePoint *(this: (idEntityPtr<idScenePoint> *)&v111[0].list[v39]);
    v42 = (idScenePoint_Look *)v41;
    if ( v41 != nullptr && (*(_BYTE *)&v41->flags & 8) != 0 && v41->type == a7 )
    {
      if ( v41->currentUser == nullptr || (v43 = 1, (int)v15 >= v41->requestTime) )
        v43 = 0;
      if ( v43 == 0 )
      {
        idScenePoint::GetScenePointPos(this: (idScenePoint *)v110, result: v41);
        v44 = v110[1];
        v45 = (float)(v110[1] - (float)y);
        v46 = v110[0];
        v47 = (float)(v110[0] - (float)x);
        v48 = v110[2];
        v49 = (float)(v110[2] - (float)z);
        v109.y = v45;
        v109.z = v110[2] - (float)z;
        v109.x = v47;
        _FP10 = (float)((float)((float)((float)(v110[0] - (float)x) * (float)(v110[0] - (float)x))
                              + (float)((float)(v110[1] - (float)y) * (float)(v110[1] - (float)y)))
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f8, f10, f11, f0 }
        v52 = __frsqrte(_FP8);
        v53 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v52
                                                                                            * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45)) * (float)0.5))
                                                                                    * (float)v52)
                                                                            - (float)1.5)
                                                            * (float)v52)
                                                    * (float)((float)((float)((float)v47 * (float)v47)
                                                                    + (float)((float)v45 * (float)v45))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v52
                                                                                    * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45))
                                                                                            * (float)0.5))
                                                                            * (float)v52)
                                                                    - (float)1.5)
                                                    * (float)v52))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v52
                                                            * (float)((float)((float)((float)v47 * (float)v47)
                                                                            + (float)((float)v45 * (float)v45))
                                                                    * (float)0.5))
                                                    * (float)v52)
                                            - (float)1.5)
                            * (float)v52));
        v54 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v52 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45)) * (float)0.5)) * (float)v52) - (float)1.5) * (float)v52) * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45)) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v52 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45)) * (float)0.5)) * (float)v52) - (float)1.5) * (float)v52))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v52 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45)) * (float)0.5)) * (float)v52)
                                                                                            - (float)1.5)
                                                                            * (float)v52))
                                                            * (float)((float)((float)((float)v47 * (float)v47)
                                                                            + (float)((float)v45 * (float)v45))
                                                                    * (float)0.5))
                                                    * (float)v53)
                                            - (float)1.5)
                            * (float)v53)
                    * (float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45)));
        if ( v54 >= minRange && (scenePointRange <= 0.0 || v54 <= scenePointRange) )
        {
          v55 = __fabs(v49);
          idVec3::NormalizeFast(this: &v109);
          if ( scenePointRange <= 0.0 || v55 <= scenePointRange )
          {
            if ( (scenePointSelectionFlags & 2) != 0 )
            {
              v56 = (float)((float)((float)v54 - (float)minRange) * v99);
              if ( v56 >= 0.0 )
              {
                if ( v56 > 1.0 )
                  v56 = 1.0;
                v57 = (float)((float)1.0 - (float)v56);
              }
              else
              {
                v57 = (float)((float)1.0 - (float)0.0);
              }
            }
            else
            {
              v57 = 0.5;
            }
            coverVerticalWeight = ai->aiEditable.actionSettings.cover.coverVerticalWeight;
            v59 = __fabs(v109.z);
            coverRandomWeight = ai->aiEditable.actionSettings.cover.coverRandomWeight;
            v61 = (float)((float)(RandomFloat() * (float)coverRandomWeight)
                        + (float)((float)v57 - (float)((float)((float)coverVerticalWeight * (float)v59) - (float)1.0)));
            if ( (a7 == 4 || a7 == (ROAM|LOOK)) && !v42->IsInArc_2(this: v42, a2: (const idVec3 *)&v100) )
              goto LABEL_106;
            switch ( a7 )
            {
              case 2:
                v79 = idScenePoint_Look::CastTo(c: v42);
                if ( v79 == nullptr
                  || (v79->lookFlags & a8) == 0
                  || !v79->IsInArc_2(this: v79, a2: (const idVec3 *)&v100) )
                {
                  goto LABEL_106;
                }
                break;
              case 3:
                if ( !v42->IsInArc_2(this: v42, a2: (const idVec3 *)&v100) )
                  goto LABEL_106;
                v64 = v101;
                v65 = v100;
                v66 = idMath::FLT_SMALLEST_NON_DENORMAL;
                _FP4 = (float)((float)((float)((float)(v100 - (float)x) * (float)(v100 - (float)x))
                                     + (float)((float)(v101 - (float)y) * (float)(v101 - (float)y)))
                             - idMath::FLT_SMALLEST_NON_DENORMAL);
                _FP3 = (float)((float)((float)((float)(v100 - (float)v46) * (float)(v100 - (float)v46))
                                     + (float)((float)(v101 - (float)v44) * (float)(v101 - (float)v44)))
                             - idMath::FLT_SMALLEST_NON_DENORMAL);
                v69 = (float)((float)((float)((float)(v100 - (float)x) * (float)(v100 - (float)x))
                                    + (float)((float)(v101 - (float)y) * (float)(v101 - (float)y)))
                            * (float)0.5);
                v70 = (float)((float)((float)((float)(v100 - (float)v46) * (float)(v100 - (float)v46))
                                    + (float)((float)(v101 - (float)v44) * (float)(v101 - (float)v44)))
                            * (float)0.5);
                __asm
                {
                  fsel      f12, f4, f6, f31
                  fsel      f11, f3, f5, f31
                }
                v73 = __frsqrte(_FP12);
                v74 = __frsqrte(_FP11);
                v75 = (float)((float)-(float)((float)((float)((float)v73
                                                            * (float)((float)((float)((float)(v100 - (float)x)
                                                                                    * (float)(v100 - (float)x))
                                                                            + (float)((float)(v101 - (float)y)
                                                                                    * (float)(v101 - (float)y)))
                                                                    * (float)0.5))
                                                    * (float)v73)
                                            - (float)1.5)
                            * (float)v73);
                v76 = (float)((float)-(float)((float)((float)((float)v74
                                                            * (float)((float)((float)((float)(v100 - (float)v46)
                                                                                    * (float)(v100 - (float)v46))
                                                                            + (float)((float)(v101 - (float)v44)
                                                                                    * (float)(v101 - (float)v44)))
                                                                    * (float)0.5))
                                                    * (float)v74)
                                            - (float)1.5)
                            * (float)v74);
                v77 = (float)((float)-(float)((float)((float)((float)v75
                                                            * (float)((float)((float)((float)(v100 - (float)x)
                                                                                    * (float)(v100 - (float)x))
                                                                            + (float)((float)(v101 - (float)y)
                                                                                    * (float)(v101 - (float)y)))
                                                                    * (float)0.5))
                                                    * (float)v75)
                                            - (float)1.5)
                            * (float)v75);
                v78 = (float)((float)-(float)((float)((float)((float)v76
                                                            * (float)((float)((float)((float)(v100 - (float)v46)
                                                                                    * (float)(v100 - (float)v46))
                                                                            + (float)((float)(v101 - (float)v44)
                                                                                    * (float)(v101 - (float)v44)))
                                                                    * (float)0.5))
                                                    * (float)v76)
                                            - (float)1.5)
                            * (float)v76);
                if ( (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76 * (float)v70) * (float)v76)
                                                                                           - (float)1.5)
                                                                           * (float)v76)
                                                                   * (float)v70)
                                                           * (float)v78)
                                                   - (float)1.5)
                                   * (float)v78)
                           * (float)((float)((float)(v100 - (float)v46) * (float)(v100 - (float)v46))
                                   + (float)((float)(v101 - (float)v44) * (float)(v101 - (float)v44)))) < (double)(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v75 * (float)v69) * (float)v75) - (float)1.5) * (float)v75) * (float)v69) * (float)v77) - (float)1.5) * (float)v77) * (float)((float)((float)(v100 - (float)x) * (float)(v100 - (float)x)) + (float)((float)(v101 - (float)y) * (float)(v101 - (float)y)))) )
                  v61 = (float)((float)v61 + (float)1.0);
                goto LABEL_83;
              case 4:
                if ( !v42->IsInArc_2(this: v42, a2: (const idVec3 *)&v100) )
                  goto LABEL_106;
                v62 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)v42);
                v63 = v62;
                if ( v62 == nullptr )
                  goto LABEL_106;
                if ( v62->scenePointTurret != nullptr )
                {
                  if ( (scenePointSelectionFlags & 0x20) != 0 )
                    v61 = (float)((float)v61 + (float)3.0);
                }
                else if ( idScenePoint_Combat::IsTactical(this: v62) )
                {
                  if ( (scenePointSelectionFlags & 1) == 0 )
                    goto LABEL_106;
                  v61 = (float)(ai->aiEditable.actionSettings.cover.coverTacticalWeight + (float)v61);
                }
                if ( v63->customSet.deathAnim.len != 0 )
                  v61 = (float)((float)v61 + (float)0.5);
                if ( v63->customSet.customCoverSet.len != 0 )
                {
                  if ( (unsigned __int8)SupportsCustomCoverSet(ai, animPath: &v63->customSet.customCoverSet) == 0 )
                    goto LABEL_106;
                  v61 = (float)((float)v61 + (float)1.5);
                }
                break;
              default:
                break;
            }
            v66 = idMath::FLT_SMALLEST_NON_DENORMAL;
            v65 = v100;
            v64 = v101;
LABEL_83:
            if ( (scenePointSelectionFlags & 0x10) != 0 )
              goto LABEL_115;
            v104.z = (float)v48 - v102;
            v104.y = (float)v44 - (float)v64;
            v104.x = (float)v46 - (float)v65;
            v103.z = v102 - (float)z;
            v103.y = (float)v64 - (float)y;
            v103.x = (float)v65 - (float)x;
            idVec3::NormalizeFast(this: &v104);
            v80 = idVec3::NormalizeFast(this: &v103);
            _FP2 = (float)((float)((float)((float)v49 * (float)v49)
                                 + (float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45)))
                         - (float)v66);
            __asm { fsel      f13, f2, f3, f31 }
            v83 = __frsqrte(_FP13);
            v84 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v83
                                                                                                * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45))) * (float)0.5))
                                                                                        * (float)v83)
                                                                                - (float)1.5)
                                                                * (float)v83)
                                                        * (float)((float)((float)((float)v49 * (float)v49)
                                                                        + (float)((float)((float)v47 * (float)v47)
                                                                                + (float)((float)v45 * (float)v45)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v83
                                                                                        * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45)))
                                                                                                * (float)0.5))
                                                                                * (float)v83)
                                                                        - (float)1.5)
                                                        * (float)v83))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v83
                                                                * (float)((float)((float)((float)v49 * (float)v49)
                                                                                + (float)((float)((float)v47 * (float)v47)
                                                                                        + (float)((float)v45 * (float)v45)))
                                                                        * (float)0.5))
                                                        * (float)v83)
                                                - (float)1.5)
                                * (float)v83));
            if ( (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v83 * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45))) * (float)0.5)) * (float)v83) - (float)1.5) * (float)v83) * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45))) * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v83 * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45))) * (float)0.5)) * (float)v83) - (float)1.5) * (float)v83))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v83 * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45))) * (float)0.5)) * (float)v83)
                                                                                               - (float)1.5)
                                                                               * (float)v83))
                                                               * (float)((float)((float)((float)v49 * (float)v49)
                                                                               + (float)((float)((float)v47 * (float)v47)
                                                                                       + (float)((float)v45 * (float)v45)))
                                                                       * (float)0.5))
                                                       * (float)v84)
                                               - (float)1.5)
                               * (float)v84)
                       * (float)((float)((float)v49 * (float)v49)
                               + (float)((float)((float)v47 * (float)v47) + (float)((float)v45 * (float)v45)))) <= v80
              || (float)((float)(v104.x * v103.x) + (float)((float)(v104.z * v103.z) + (float)(v104.y * v103.y))) <= (double)(float)0.70700002 )
            {
LABEL_115:
              if ( (scenePointSelectionFlags & 4) != 0 )
              {
                Enemy = (idEntity *)idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
                v86 = Enemy;
                if ( Enemy != nullptr )
                {
                  presentable = (float *)Enemy->presentable;
                  if ( presentable == nullptr )
                  {
                    idEntity::InitPresentableInternal(this: Enemy);
                    presentable = (float *)v86->presentable;
                  }
                  v88 = presentable[33];
                  v105.x = (float)v46 - v100;
                  v105.z = (float)v48 - v102;
                  v89 = presentable[34];
                  v105.y = (float)v44 - v101;
                  v90 = presentable[35];
                  v106 = v88;
                  v107 = v89;
                  v108 = v90;
                  idVec3::NormalizeFast(this: &v105);
                  v91 = (float)((float)(v105.x * v106) + (float)((float)(v108 * v105.z) + (float)(v107 * v105.y)));
                  if ( v91 >= 0.0 )
                  {
                    if ( v91 > 1.0 )
                      v91 = 1.0;
                  }
                  else
                  {
                    v91 = 0.0;
                  }
                  v61 = (float)((float)((float)1.0 - (float)v91) + (float)v61);
                }
              }
              p_memory = &ai->aiVolatile.memory;
              if ( a7 == LOOK )
              {
                LookScenePointHistoryScore = idAIMemory::GetLookScenePointHistoryScore(this: p_memory, scenePoint: v42);
                if ( LookScenePointHistoryScore > 0.0 )
                {
                  v94 = (float)((float)LookScenePointHistoryScore + (float)v61);
                  goto LABEL_104;
                }
              }
              else
              {
                ScenePointHistoryScore = idAIMemory::GetScenePointHistoryScore(this: p_memory, scenePoint: v42);
                if ( (scenePointSelectionFlags & 8) != 0 || ScenePointHistoryScore > 0.0 )
                {
                  if ( a7 == 4 )
                    coverHistoryWeight = ai->aiEditable.actionSettings.cover.coverHistoryWeight;
                  else
                    coverHistoryWeight = 1.0;
                  v94 = (float)((float)((float)coverHistoryWeight * (float)ScenePointHistoryScore) + (float)v61);
LABEL_104:
                  if ( v94 > v98 )
                  {
                    v98 = v94;
                    v31 = v42;
                  }
                }
              }
            }
LABEL_106:
            scenePointRange = v112;
          }
        }
      }
    }
    ++v39;
  }
  if ( v31 == nullptr )
    goto LABEL_109;
LABEL_112:
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v111);
  return v31;
}


// ========================================================================
// __unwind$488583
// EA  : 0x82AF6730
// RVA : 0x00AF6730
// PDB : w:\tech5\tungsten\game\ai\fsm\scenepoint_common.cpp
// ========================================================================

void _unwind_488583()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 224));
}

