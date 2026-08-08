
// ========================================================================
// ??0idBotBehaviorCombat@@QAA@XZ
// EA  : 0x82B3CEE8
// RVA : 0x00B3CEE8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

idBotBehaviorCombat *__fastcall idBotBehaviorCombat::idBotBehaviorCombat(idBotBehaviorCombat *this)
{
  idBehaviorSelectorLooping::idBehaviorSelectorLooping(this);
  this->__vftable = (idBotBehaviorCombat_vtbl *)&idBotBehaviorCombat::`vftable';
  return this;
}


// ========================================================================
// ??0idBotBehaviorAlert@@QAA@XZ
// EA  : 0x82B3CF28
// RVA : 0x00B3CF28
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

idBotBehaviorAlert *__fastcall idBotBehaviorAlert::idBotBehaviorAlert(idBotBehaviorAlert *this)
{
  idBehaviorSelectorLooping::idBehaviorSelectorLooping(this);
  this->__vftable = (idBotBehaviorAlert_vtbl *)&idBotBehaviorAlert::`vftable';
  return this;
}


// ========================================================================
// ??0idBotBehaviorBehave@@QAA@XZ
// EA  : 0x82B3CF68
// RVA : 0x00B3CF68
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

idBotBehaviorBehave *__fastcall idBotBehaviorBehave::idBotBehaviorBehave(idBotBehaviorBehave *this)
{
  idBehaviorSelectorLooping::idBehaviorSelectorLooping(this);
  this->__vftable = (idBotBehaviorBehave_vtbl *)&idBotBehaviorBehave::`vftable';
  return this;
}


// ========================================================================
// ??0idBotBehaviorReact@@QAA@XZ
// EA  : 0x82B3CFA8
// RVA : 0x00B3CFA8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

idBotBehaviorReact *__fastcall idBotBehaviorReact::idBotBehaviorReact(idBotBehaviorReact *this)
{
  idBehaviorSelectorLooping::idBehaviorSelectorLooping(this);
  this->__vftable = (idBotBehaviorReact_vtbl *)&idBotBehaviorReact::`vftable';
  return this;
}


// ========================================================================
// ?Init@idBotBehaviorCombat@@UAAXPAVidBot@@H@Z
// EA  : 0x82B3D190
// RVA : 0x00B3D190
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat::Init(idBotBehaviorCombat *this, idBot *bot, const int curTime)
{
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  idBotBehaviorCombat_TargetVis *v10; // r3
  idBotBehaviorCombat_TargetVis *v11; // r5
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r7
  int v16; // r6
  idBotBehaviorCombat_NonVisTarget *v17; // r3
  idBotBehaviorCombat_NonVisTarget *v18; // r5
  int v19; // [sp+8h] [-88h]
  int v20; // [sp+8h] [-88h]
  int v21; // [sp+Ch] [-84h]
  int v22; // [sp+Ch] [-84h]
  int v23; // [sp+10h] [-80h]
  int v24; // [sp+10h] [-80h]
  int v25; // [sp+14h] [-7Ch]
  int v26; // [sp+14h] [-7Ch]
  int v27; // [sp+18h] [-78h]
  int v28; // [sp+18h] [-78h]
  int v29; // [sp+1Ch] [-74h]
  int v30; // [sp+1Ch] [-74h]
  int v31; // [sp+20h] [-70h]
  int v32; // [sp+20h] [-70h]
  idBehaviorState *v33; // [sp+24h] [-6Ch]
  idBehaviorState *v34; // [sp+24h] [-6Ch]

  v10 = (idBotBehaviorCombat_TargetVis *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                           size: 0x4Cu,
                                           tag: TAG_NEW,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
    v11 = idBotBehaviorCombat_TargetVis::idBotBehaviorCombat_TargetVis(this: v10);
  else
    v11 = nullptr;
  idBehaviorComposite::AppendState(
    this,
    rootTree: bot->behaviorTree,
    newState: v11,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: v5,
    a9: v19,
    a10: v21,
    a11: v23,
    a12: v25,
    a13: v27,
    a14: v29,
    a15: v31,
    a16: v33);
  v17 = (idBotBehaviorCombat_NonVisTarget *)idMem::AllocWithLocation(
                                              this: &mem,
                                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                              size: 0x4Cu,
                                              tag: TAG_NEW,
                                              zeroBuffer: false,
                                              align: ALIGN_16,
                                              heap: HEAP_DEFAULTHEAP);
  if ( v17 != nullptr )
    v18 = idBotBehaviorCombat_NonVisTarget::idBotBehaviorCombat_NonVisTarget(this: v17);
  else
    v18 = nullptr;
  idBehaviorComposite::AppendState(
    this,
    rootTree: bot->behaviorTree,
    newState: v18,
    a4: v16,
    a5: v15,
    a6: v14,
    a7: v13,
    a8: v12,
    a9: v20,
    a10: v22,
    a11: v24,
    a12: v26,
    a13: v28,
    a14: v30,
    a15: v32,
    a16: v34);
}


// ========================================================================
// __unwind$488563
// EA  : 0x82B3D250
// RVA : 0x00B3D250
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall _unwind_488563(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$488564_0
// EA  : 0x82B3D278
// RVA : 0x00B3D278
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall _unwind_488564_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorAlert@@UAAXPAVidBot@@H@Z
// EA  : 0x82B3D2A8
// RVA : 0x00B3D2A8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall idBotBehaviorAlert::Init(idBotBehaviorAlert *this, idBot *bot, const int curTime)
{
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  idBotBehaviorEscort *v10; // r3
  idBotBehaviorEscort *v11; // r5
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r7
  int v16; // r6
  idBotBehaviorRoam *v17; // r3
  idBotBehaviorRoam *v18; // r5
  int v19; // [sp+8h] [-88h]
  int v20; // [sp+8h] [-88h]
  int v21; // [sp+Ch] [-84h]
  int v22; // [sp+Ch] [-84h]
  int v23; // [sp+10h] [-80h]
  int v24; // [sp+10h] [-80h]
  int v25; // [sp+14h] [-7Ch]
  int v26; // [sp+14h] [-7Ch]
  int v27; // [sp+18h] [-78h]
  int v28; // [sp+18h] [-78h]
  int v29; // [sp+1Ch] [-74h]
  int v30; // [sp+1Ch] [-74h]
  int v31; // [sp+20h] [-70h]
  int v32; // [sp+20h] [-70h]
  idBehaviorState *v33; // [sp+24h] [-6Ch]
  idBehaviorState *v34; // [sp+24h] [-6Ch]

  v10 = (idBotBehaviorEscort *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                 size: 0x4Cu,
                                 tag: TAG_NEW,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
    v11 = idBotBehaviorEscort::idBotBehaviorEscort(this: v10);
  else
    v11 = nullptr;
  idBehaviorComposite::AppendState(
    this,
    rootTree: bot->behaviorTree,
    newState: v11,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: v5,
    a9: v19,
    a10: v21,
    a11: v23,
    a12: v25,
    a13: v27,
    a14: v29,
    a15: v31,
    a16: v33);
  v17 = (idBotBehaviorRoam *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                               size: 0x3Cu,
                               tag: TAG_NEW,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v17 != nullptr )
    v18 = idBotBehaviorRoam::idBotBehaviorRoam(this: v17);
  else
    v18 = nullptr;
  idBehaviorComposite::AppendState(
    this,
    rootTree: bot->behaviorTree,
    newState: v18,
    a4: v16,
    a5: v15,
    a6: v14,
    a7: v13,
    a8: v12,
    a9: v20,
    a10: v22,
    a11: v24,
    a12: v26,
    a13: v28,
    a14: v30,
    a15: v32,
    a16: v34);
}


// ========================================================================
// __unwind$488613
// EA  : 0x82B3D368
// RVA : 0x00B3D368
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall _unwind_488613(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$488614
// EA  : 0x82B3D390
// RVA : 0x00B3D390
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall _unwind_488614(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorBehave@@UAAXPAVidBot@@H@Z
// EA  : 0x82B3D3C0
// RVA : 0x00B3D3C0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall idBotBehaviorBehave::Init(idBotBehaviorBehave *this, idBot *bot, const int curTime)
{
  void **v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  idBehaviorSelectorLooping *v10; // r3
  idBehaviorState *v11; // r30
  idBehaviorState *v12; // r5
  void **v13; // r10
  int v14; // r9
  int v15; // r8
  int v16; // r7
  int v17; // r6
  idBehaviorSelectorLooping *v18; // r3
  idBehaviorState *v19; // r30
  idBehaviorState *v20; // r5
  int v21; // [sp+8h] [-88h]
  int v22; // [sp+8h] [-88h]
  int v23; // [sp+Ch] [-84h]
  int v24; // [sp+Ch] [-84h]
  int v25; // [sp+10h] [-80h]
  int v26; // [sp+10h] [-80h]
  int v27; // [sp+14h] [-7Ch]
  int v28; // [sp+14h] [-7Ch]
  int v29; // [sp+18h] [-78h]
  int v30; // [sp+18h] [-78h]
  int v31; // [sp+1Ch] [-74h]
  int v32; // [sp+1Ch] [-74h]
  int v33; // [sp+20h] [-70h]
  int v34; // [sp+20h] [-70h]
  idBehaviorState *v35; // [sp+24h] [-6Ch]
  idBehaviorState *v36; // [sp+24h] [-6Ch]

  v10 = (idBehaviorSelectorLooping *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0x4Cu,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  v11 = v10;
  if ( v10 != nullptr )
  {
    idBehaviorSelectorLooping::idBehaviorSelectorLooping(this: v10);
    v12 = v11;
    v5 = &idBotBehaviorCombat::`vftable';
    v11->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorCombat::`vftable';
  }
  else
  {
    v12 = nullptr;
  }
  idBehaviorComposite::AppendState(
    this,
    rootTree: bot->behaviorTree,
    newState: v12,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: (int)v5,
    a9: v21,
    a10: v23,
    a11: v25,
    a12: v27,
    a13: v29,
    a14: v31,
    a15: v33,
    a16: v35);
  v18 = (idBehaviorSelectorLooping *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0x4Cu,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  v19 = v18;
  if ( v18 != nullptr )
  {
    idBehaviorSelectorLooping::idBehaviorSelectorLooping(this: v18);
    v20 = v19;
    v13 = &idBotBehaviorAlert::`vftable';
    v19->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorAlert::`vftable';
  }
  else
  {
    v20 = nullptr;
  }
  idBehaviorComposite::AppendState(
    this,
    rootTree: bot->behaviorTree,
    newState: v20,
    a4: v17,
    a5: v16,
    a6: v15,
    a7: v14,
    a8: (int)v13,
    a9: v22,
    a10: v24,
    a11: v26,
    a12: v28,
    a13: v30,
    a14: v32,
    a15: v34,
    a16: v36);
}


// ========================================================================
// __unwind$488660
// EA  : 0x82B3D4A0
// RVA : 0x00B3D4A0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall _unwind_488660(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$488661
// EA  : 0x82B3D4C8
// RVA : 0x00B3D4C8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall _unwind_488661(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorReact@@UAAXPAVidBot@@H@Z
// EA  : 0x82B3D4F8
// RVA : 0x00B3D4F8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall idBotBehaviorReact::Init(idBotBehaviorCombat_NonVisTarget *this, idBot *bot, const int curTime)
{
  void **v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  idBehaviorAction *v10; // r3
  idBehaviorState *v11; // r30
  idBehaviorState *v12; // r5
  int v13; // [sp+8h] [-78h]
  int v14; // [sp+Ch] [-74h]
  int v15; // [sp+10h] [-70h]
  int v16; // [sp+14h] [-6Ch]
  int v17; // [sp+18h] [-68h]
  int v18; // [sp+1Ch] [-64h]
  int v19; // [sp+20h] [-60h]
  idBehaviorState *v20; // [sp+24h] [-5Ch]

  v10 = (idBehaviorAction *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x38u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v11 = v10;
  if ( v10 != nullptr )
  {
    idBehaviorAction::idBehaviorAction(this: v10);
    v12 = v11;
    v5 = &idBehaviorTemp::`vftable';
    v11->__vftable = (idBehaviorState_vtbl *)&idBehaviorTemp::`vftable';
  }
  else
  {
    v12 = nullptr;
  }
  idBehaviorComposite::AppendState(
    this,
    rootTree: bot->behaviorTree,
    newState: v12,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: (int)v5,
    a9: v13,
    a10: v14,
    a11: v15,
    a12: v16,
    a13: v17,
    a14: v18,
    a15: v19,
    a16: v20);
}


// ========================================================================
// __unwind$489715_0
// EA  : 0x82B3D578
// RVA : 0x00B3D578
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

void __fastcall _unwind_489715_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3D5A0
// RVA : 0x00B3D5A0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_highlevel.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorCombat::GetPriority(
        idBotBehaviorCombat *this,
        idBot *bot,
        const int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  behaviorPriority_t result; // r3
  idBotTargetRecord *RecordForIndex; // r3
  double distToTarget; // fp0

  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return BEHAVIOR_PRIORITY_NULL;
  v5 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v5 == nullptr )
    return BEHAVIOR_PRIORITY_NULL;
  if ( idEntity::CastTo(c: v5) == nullptr )
    return BEHAVIOR_PRIORITY_NULL;
  RecordForIndex = idBotWorldState::GetRecordForIndex(
                     this: bot->worldState,
                     index: bot->goalTask.goalEnemyTargetRecordIndex);
  if ( RecordForIndex == nullptr )
    return BEHAVIOR_PRIORITY_NULL;
  distToTarget = RecordForIndex->volatileData.distToTarget;
  result = BEHAVIOR_PRIORITY_NULL;
  if ( distToTarget <= bot->goalTask.goalCombatSettings.combatMaxRange )
    return BEHAVIOR_PRIORITY_HIGH;
  return result;
}

