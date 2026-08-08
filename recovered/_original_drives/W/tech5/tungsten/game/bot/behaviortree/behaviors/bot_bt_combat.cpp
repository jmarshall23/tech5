
// ========================================================================
// ??0idBotBehaviorCombat_TargetVis@@QAA@XZ
// EA  : 0x82B36448
// RVA : 0x00B36448
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

idBotBehaviorCombat_TargetVis *__fastcall idBotBehaviorCombat_TargetVis::idBotBehaviorCombat_TargetVis(
        idBotBehaviorCombat_TargetVis *this)
{
  idBehaviorSelectorLooping::idBehaviorSelectorLooping(this);
  this->__vftable = (idBotBehaviorCombat_TargetVis_vtbl *)&idBotBehaviorCombat_TargetVis::`vftable';
  return this;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_TargetVis@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B36488
// RVA : 0x00B36488
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorCombat_TargetVis::GetPriority(
        idBotBehaviorCombat_TargetVis *this,
        idBot *bot,
        unsigned int curTime)
{
  idBotTargetRecord *RecordForIndex; // r3
  __int64 v5; // r11

  RecordForIndex = idBotWorldState::GetRecordForIndex(
                     this: bot->worldState,
                     index: bot->goalTask.goalEnemyTargetRecordIndex);
  HIDWORD(v5) = curTime >> 31;
  LODWORD(v5) = RecordForIndex->volatileData.timeLastVisible + 2500;
  return ((__PAIR64__((unsigned int)v5 >> 31, curTime) - v5) >> 32) & 2;
}


// ========================================================================
// ??0idBotBehaviorCombat_TargetVis_CloseRange@@QAA@XZ
// EA  : 0x82B364E0
// RVA : 0x00B364E0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

idBotBehaviorCombat_TargetVis_CloseRange *__fastcall idBotBehaviorCombat_TargetVis_CloseRange::idBotBehaviorCombat_TargetVis_CloseRange(
        idBotBehaviorCombat_TargetVis_CloseRange *this)
{
  idBehaviorSelectorLooping::idBehaviorSelectorLooping(this);
  this->__vftable = (idBotBehaviorCombat_TargetVis_CloseRange_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange::`vftable';
  return this;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B36520
// RVA : 0x00B36520
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorCombat_TargetVis_CloseRange::GetPriority(
        idBotBehaviorCombat_TargetVis_CloseRange *this,
        idBot *bot,
        const int curTime)
{
  double distToTarget; // fp13
  behaviorPriority_t result; // r3

  distToTarget = idBotWorldState::GetRecordForIndex(
                   this: bot->worldState,
                   index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget;
  result = BEHAVIOR_PRIORITY_NULL;
  if ( distToTarget <= 512.0 )
    return BEHAVIOR_PRIORITY_NORMAL;
  return result;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_TargetVis_CloseRange@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B36568
// RVA : 0x00B36568
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange::Think(
        idBotBehaviorCombat_TargetVis_CloseRange *this,
        idBot *bot,
        const int curTime)
{
  idBotWeaponState::AddWeaponRequest(
    this: bot->weaponState,
    priority: WEAPON_PRIORITY_BEHAVIOR_DRIVEN,
    weapSlot: WEAPON_SLOT_PRIMARY,
    userName: "SHORT_RANGE_COMBAT",
    fireMode: WEAPON_FIRE_MODE_WHEN_READY);
  return 1;
}


// ========================================================================
// ??0idBotBehaviorCombat_TargetVis_CloseRange_Melee@@QAA@XZ
// EA  : 0x82B365A8
// RVA : 0x00B365A8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

idBotBehaviorCombat_TargetVis_CloseRange_Melee *__fastcall idBotBehaviorCombat_TargetVis_CloseRange_Melee::idBotBehaviorCombat_TargetVis_CloseRange_Melee(
        idBotBehaviorCombat_TargetVis_CloseRange_Melee *this)
{
  idBehaviorSelectorRandom::idBehaviorSelectorRandom(this);
  this->__vftable = (idBotBehaviorCombat_TargetVis_CloseRange_Melee_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_Melee::`vftable';
  return this;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange_Melee@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B365E8
// RVA : 0x00B365E8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Melee::GetPriority(
        idBotBehaviorCombat_TargetVis_CloseRange_Melee *this,
        idBot *bot,
        const int curTime)
{
  return bot->weaponState->currentWeaponCategory != WEAPON_CATEGORY_MELEE ? 0 : 2;
}


// ========================================================================
// ??0idBotBehaviorCombat_TargetVis_CloseRange_SMG@@QAA@XZ
// EA  : 0x82B36608
// RVA : 0x00B36608
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

idBotBehaviorCombat_TargetVis_CloseRange_SMG *__fastcall idBotBehaviorCombat_TargetVis_CloseRange_SMG::idBotBehaviorCombat_TargetVis_CloseRange_SMG(
        idBotBehaviorCombat_TargetVis_CloseRange_SMG *this)
{
  idBehaviorSelectorRandom::idBehaviorSelectorRandom(this);
  this->__vftable = (idBotBehaviorCombat_TargetVis_CloseRange_SMG_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_SMG::`vftable';
  return this;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange_SMG@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B36648
// RVA : 0x00B36648
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange_SMG::GetPriority(
        idBotBehaviorCombat_TargetVis_CloseRange_SMG *this,
        idBot *bot,
        const int curTime)
{
  return bot->weaponState->currentWeaponCategory != WEAPON_CATEGORY_SMG ? 0 : 2;
}


// ========================================================================
// ??0idBotBehaviorCombat_TargetVis_CloseRange_Shotgun@@QAA@XZ
// EA  : 0x82B36668
// RVA : 0x00B36668
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

idBotBehaviorCombat_TargetVis_CloseRange_Shotgun *__fastcall idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::idBotBehaviorCombat_TargetVis_CloseRange_Shotgun(
        idBotBehaviorCombat_TargetVis_CloseRange_Shotgun *this)
{
  idBehaviorSelectorRandom::idBehaviorSelectorRandom(this);
  this->__vftable = (idBotBehaviorCombat_TargetVis_CloseRange_Shotgun_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::`vftable';
  return this;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange_Shotgun@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B366A8
// RVA : 0x00B366A8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::GetPriority(
        idBotBehaviorCombat_TargetVis_CloseRange_Shotgun *this,
        idBot *bot,
        const int curTime)
{
  return bot->weaponState->currentWeaponCategory != WEAPON_CATEGORY_SHOTGUN ? 0 : 2;
}


// ========================================================================
// ??0idBotBehaviorCombat_TargetVis_CloseRange_Thrown@@QAA@XZ
// EA  : 0x82B366C8
// RVA : 0x00B366C8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

idBotBehaviorCombat_TargetVis_CloseRange_Thrown *__fastcall idBotBehaviorCombat_TargetVis_CloseRange_Thrown::idBotBehaviorCombat_TargetVis_CloseRange_Thrown(
        idBotBehaviorCombat_TargetVis_CloseRange_Thrown *this)
{
  idBehaviorSelectorRandom::idBehaviorSelectorRandom(this);
  this->__vftable = (idBotBehaviorCombat_TargetVis_CloseRange_Thrown_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_Thrown::`vftable';
  return this;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange_Sniper@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B36708
// RVA : 0x00B36708
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Sniper::GetPriority(
        idBotBehaviorCombat_TargetVis_CloseRange_Sniper *this,
        idBot *bot,
        const int curTime)
{
  return bot->weaponState->currentWeaponCategory != WEAPON_CATEGORY_THROWN ? 0 : 2;
}


// ========================================================================
// ??0idBotBehaviorCombat_TargetVis_CloseRange_Sniper@@QAA@XZ
// EA  : 0x82B36728
// RVA : 0x00B36728
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

idBotBehaviorCombat_TargetVis_CloseRange_Sniper *__fastcall idBotBehaviorCombat_TargetVis_CloseRange_Sniper::idBotBehaviorCombat_TargetVis_CloseRange_Sniper(
        idBotBehaviorCombat_TargetVis_CloseRange_Sniper *this)
{
  idBehaviorSelectorRandom::idBehaviorSelectorRandom(this);
  this->__vftable = (idBotBehaviorCombat_TargetVis_CloseRange_Sniper_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_Sniper::`vftable';
  return this;
}


// ========================================================================
// ??0idBotBehaviorCombat_TargetVis_LongRange@@QAA@XZ
// EA  : 0x82B36768
// RVA : 0x00B36768
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

idBotBehaviorCombat_TargetVis_LongRange *__fastcall idBotBehaviorCombat_TargetVis_LongRange::idBotBehaviorCombat_TargetVis_LongRange(
        idBotBehaviorCombat_TargetVis_LongRange *this)
{
  idBehaviorSelectorLooping::idBehaviorSelectorLooping(this);
  this->__vftable = (idBotBehaviorCombat_TargetVis_LongRange_vtbl *)&idBotBehaviorCombat_TargetVis_LongRange::`vftable';
  return this;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_TargetVis_LongRange@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B367A8
// RVA : 0x00B367A8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorCombat_TargetVis_LongRange::GetPriority(
        idBotBehaviorCombat_TargetVis_LongRange *this,
        idBot *bot,
        const int curTime)
{
  double distToTarget; // fp13
  behaviorPriority_t result; // r3

  distToTarget = idBotWorldState::GetRecordForIndex(
                   this: bot->worldState,
                   index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget;
  result = BEHAVIOR_PRIORITY_NULL;
  if ( distToTarget > 512.0 )
    return BEHAVIOR_PRIORITY_NORMAL;
  return result;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_TargetVis_LongRange@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B367F0
// RVA : 0x00B367F0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_LongRange::Think(
        idBotBehaviorCombat_TargetVis_LongRange *this,
        idBot *bot,
        const int curTime)
{
  idBotWeaponState::AddWeaponRequest(
    this: bot->weaponState,
    priority: WEAPON_PRIORITY_BEHAVIOR_DRIVEN,
    weapSlot: WEAPON_SLOT_PRIMARY,
    userName: "LONG_RANGE_VIS_COMBAT",
    fireMode: WEAPON_FIRE_MODE_WHEN_READY);
  return 1;
}


// ========================================================================
// ??0idBotBehaviorCombat_NonVisTarget@@QAA@XZ
// EA  : 0x82B36830
// RVA : 0x00B36830
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

idBotBehaviorCombat_NonVisTarget *__fastcall idBotBehaviorCombat_NonVisTarget::idBotBehaviorCombat_NonVisTarget(
        idBotBehaviorCombat_NonVisTarget *this)
{
  idBehaviorSelector::idBehaviorSelector(this);
  this->__vftable = (idBotBehaviorCombat_NonVisTarget_vtbl *)&idBotBehaviorCombat_NonVisTarget::`vftable';
  return this;
}


// ========================================================================
// ?Init@idBotBehaviorCombat_TargetVis@@UAAXPAVidBot@@H@Z
// EA  : 0x82B36C20
// RVA : 0x00B36C20
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_TargetVis::Init(idBotBehaviorCombat_TargetVis *this, idBot *bot, const int curTime)
{
  idBehaviorSelectorLooping *v5; // r3
  idBehaviorState *v6; // r30
  idBehaviorState *v7; // r5
  idBehaviorSelectorLooping *v8; // r3
  idBehaviorState *v9; // r30
  idBehaviorState *v10; // r5

  v5 = (idBehaviorSelectorLooping *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x4Cu,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  v6 = v5;
  if ( v5 != nullptr )
  {
    idBehaviorSelectorLooping::idBehaviorSelectorLooping(this: v5);
    v7 = v6;
    v6->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange::`vftable';
  }
  else
  {
    v7 = nullptr;
  }
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v7);
  v8 = (idBehaviorSelectorLooping *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x4Cu,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  v9 = v8;
  if ( v8 != nullptr )
  {
    idBehaviorSelectorLooping::idBehaviorSelectorLooping(this: v8);
    v10 = v9;
    v9->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorCombat_TargetVis_LongRange::`vftable';
  }
  else
  {
    v10 = nullptr;
  }
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v10);
}


// ========================================================================
// __unwind$489164
// EA  : 0x82B36D00
// RVA : 0x00B36D00
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489164(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489165
// EA  : 0x82B36D28
// RVA : 0x00B36D28
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489165(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorCombat_TargetVis_CloseRange@@UAAXPAVidBot@@H@Z
// EA  : 0x82B36D58
// RVA : 0x00B36D58
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_TargetVis_CloseRange::Init(
        idBotBehaviorCombat_TargetVis_CloseRange *this,
        idBot *bot,
        const int curTime)
{
  idBehaviorSelectorRandom *v5; // r3
  idBehaviorState *v6; // r28
  idBehaviorState *v7; // r5
  idBehaviorSelectorRandom *v8; // r3
  idBehaviorState *v9; // r28
  idBehaviorState *v10; // r5
  idBehaviorSelectorRandom *v11; // r3
  idBehaviorState *v12; // r28
  idBehaviorState *v13; // r5
  idBehaviorSelectorRandom *v14; // r3
  idBehaviorState *v15; // r28
  idBehaviorState *v16; // r5
  idBehaviorSelectorRandom *v17; // r3
  idBehaviorState *v18; // r30
  idBehaviorState *v19; // r5

  v5 = (idBehaviorSelectorRandom *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                     size: 0x4Cu,
                                     tag: TAG_NEW,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  v6 = v5;
  if ( v5 != nullptr )
  {
    idBehaviorSelectorRandom::idBehaviorSelectorRandom(this: v5);
    v7 = v6;
    v6->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_Melee::`vftable';
  }
  else
  {
    v7 = nullptr;
  }
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v7);
  v8 = (idBehaviorSelectorRandom *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                     size: 0x4Cu,
                                     tag: TAG_NEW,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  v9 = v8;
  if ( v8 != nullptr )
  {
    idBehaviorSelectorRandom::idBehaviorSelectorRandom(this: v8);
    v10 = v9;
    v9->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_SMG::`vftable';
  }
  else
  {
    v10 = nullptr;
  }
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v10);
  v11 = (idBehaviorSelectorRandom *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x4Cu,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  v12 = v11;
  if ( v11 != nullptr )
  {
    idBehaviorSelectorRandom::idBehaviorSelectorRandom(this: v11);
    v13 = v12;
    v12->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::`vftable';
  }
  else
  {
    v13 = nullptr;
  }
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v13);
  v14 = (idBehaviorSelectorRandom *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x4Cu,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  v15 = v14;
  if ( v14 != nullptr )
  {
    idBehaviorSelectorRandom::idBehaviorSelectorRandom(this: v14);
    v16 = v15;
    v15->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_Thrown::`vftable';
  }
  else
  {
    v16 = nullptr;
  }
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v16);
  v17 = (idBehaviorSelectorRandom *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x4Cu,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  v18 = v17;
  if ( v17 != nullptr )
  {
    idBehaviorSelectorRandom::idBehaviorSelectorRandom(this: v17);
    v19 = v18;
    v18->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorCombat_TargetVis_CloseRange_Sniper::`vftable';
  }
  else
  {
    v19 = nullptr;
  }
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v19);
}


// ========================================================================
// __unwind$489234_0
// EA  : 0x82B36F40
// RVA : 0x00B36F40
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489234_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489235
// EA  : 0x82B36F68
// RVA : 0x00B36F68
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489235(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489236
// EA  : 0x82B36F90
// RVA : 0x00B36F90
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489236(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489237
// EA  : 0x82B36FB8
// RVA : 0x00B36FB8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489237(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489238_0
// EA  : 0x82B36FE0
// RVA : 0x00B36FE0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489238_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorCombat_TargetVis_CloseRange_Melee@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37010
// RVA : 0x00B37010
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Melee::Init(
        idBotBehaviorCombat_TargetVis_CloseRange_Melee *this,
        idBot *bot,
        const int curTime)
{
  idBotBehaviorCombat_MeleeAttackEnemy *v5; // r3
  idBotBehaviorCombat_MeleeAttackEnemy *v6; // r5

  v5 = (idBotBehaviorCombat_MeleeAttackEnemy *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                 size: 0x3Cu,
                                                 tag: TAG_NEW,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idBotBehaviorCombat_MeleeAttackEnemy::idBotBehaviorCombat_MeleeAttackEnemy(this: v5);
  else
    v6 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v6);
}


// ========================================================================
// __unwind$489339
// EA  : 0x82B37080
// RVA : 0x00B37080
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489339(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorCombat_TargetVis_CloseRange_SMG@@UAAXPAVidBot@@H@Z
// EA  : 0x82B370B0
// RVA : 0x00B370B0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_TargetVis_CloseRange_SMG::Init(
        idBotBehaviorCombat_TargetVis_CloseRange_SMG *this,
        idBot *bot,
        const int curTime)
{
  idBotBehaviorCombat_CircleStafeEnemy *v5; // r3
  idBotBehaviorCombat_CircleStafeEnemy *v6; // r5
  idBotBehaviorCombat_SideStrafeEnemy *v7; // r3
  idBotBehaviorCombat_SideStrafeEnemy *v8; // r5
  idBotBehaviorCombat_QuickSideToSideStrafeEnemy *v9; // r3
  idBotBehaviorCombat_QuickSideToSideStrafeEnemy *v10; // r5
  idBotBehaviorCombat_RandomJumpAttackEnemy *v11; // r3
  idBotBehaviorCombat_RandomJumpAttackEnemy *v12; // r5
  idBotBehaviorCombat_RunAndAttackEnemy *v13; // r3
  idBotBehaviorCombat_RunAndAttackEnemy *v14; // r5

  v5 = (idBotBehaviorCombat_CircleStafeEnemy *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                 size: 0x40u,
                                                 tag: TAG_NEW,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idBotBehaviorCombat_CircleStafeEnemy::idBotBehaviorCombat_CircleStafeEnemy(this: v5);
  else
    v6 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v6);
  v7 = (idBotBehaviorCombat_SideStrafeEnemy *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                size: 0x40u,
                                                tag: TAG_NEW,
                                                zeroBuffer: false,
                                                align: ALIGN_16,
                                                heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idBotBehaviorCombat_SideStrafeEnemy::idBotBehaviorCombat_SideStrafeEnemy(this: v7);
  else
    v8 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v8);
  v9 = (idBotBehaviorCombat_QuickSideToSideStrafeEnemy *)idMem::AllocWithLocation(
                                                           this: &mem,
                                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                           size: 0x44u,
                                                           tag: TAG_NEW,
                                                           zeroBuffer: false,
                                                           align: ALIGN_16,
                                                           heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v10 = idBotBehaviorCombat_QuickSideToSideStrafeEnemy::idBotBehaviorCombat_QuickSideToSideStrafeEnemy(this: v9);
  else
    v10 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v10);
  v11 = (idBotBehaviorCombat_RandomJumpAttackEnemy *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                       size: 0x44u,
                                                       tag: TAG_NEW,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
  if ( v11 != nullptr )
    v12 = idBotBehaviorCombat_RandomJumpAttackEnemy::idBotBehaviorCombat_RandomJumpAttackEnemy(this: v11);
  else
    v12 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v12);
  v13 = (idBotBehaviorCombat_RunAndAttackEnemy *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                   size: 0x44u,
                                                   tag: TAG_NEW,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
  if ( v13 != nullptr )
    v14 = idBotBehaviorCombat_RunAndAttackEnemy::idBotBehaviorCombat_RunAndAttackEnemy(this: v13);
  else
    v14 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v14);
}


// ========================================================================
// __unwind$489386
// EA  : 0x82B37248
// RVA : 0x00B37248
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489386(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489387
// EA  : 0x82B37270
// RVA : 0x00B37270
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489387(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489388
// EA  : 0x82B37298
// RVA : 0x00B37298
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489388(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489389
// EA  : 0x82B372C0
// RVA : 0x00B372C0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489389(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489390
// EA  : 0x82B372E8
// RVA : 0x00B372E8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489390(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorCombat_TargetVis_CloseRange_Shotgun@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37318
// RVA : 0x00B37318
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::Init(
        idBotBehaviorCombat_TargetVis_CloseRange_Shotgun *this,
        idBot *bot,
        const int curTime)
{
  idBotBehaviorCombat_CircleStafeEnemy *v5; // r3
  idBotBehaviorCombat_CircleStafeEnemy *v6; // r5
  idBotBehaviorCombat_SideStrafeEnemy *v7; // r3
  idBotBehaviorCombat_SideStrafeEnemy *v8; // r5
  idBotBehaviorCombat_QuickSideToSideStrafeEnemy *v9; // r3
  idBotBehaviorCombat_QuickSideToSideStrafeEnemy *v10; // r5
  idBotBehaviorCombat_RunAndAttackEnemy *v11; // r3
  idBotBehaviorCombat_RunAndAttackEnemy *v12; // r5

  v5 = (idBotBehaviorCombat_CircleStafeEnemy *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                 size: 0x40u,
                                                 tag: TAG_NEW,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idBotBehaviorCombat_CircleStafeEnemy::idBotBehaviorCombat_CircleStafeEnemy(this: v5);
  else
    v6 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v6);
  v7 = (idBotBehaviorCombat_SideStrafeEnemy *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                size: 0x40u,
                                                tag: TAG_NEW,
                                                zeroBuffer: false,
                                                align: ALIGN_16,
                                                heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idBotBehaviorCombat_SideStrafeEnemy::idBotBehaviorCombat_SideStrafeEnemy(this: v7);
  else
    v8 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v8);
  v9 = (idBotBehaviorCombat_QuickSideToSideStrafeEnemy *)idMem::AllocWithLocation(
                                                           this: &mem,
                                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                           size: 0x44u,
                                                           tag: TAG_NEW,
                                                           zeroBuffer: false,
                                                           align: ALIGN_16,
                                                           heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v10 = idBotBehaviorCombat_QuickSideToSideStrafeEnemy::idBotBehaviorCombat_QuickSideToSideStrafeEnemy(this: v9);
  else
    v10 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v10);
  v11 = (idBotBehaviorCombat_RunAndAttackEnemy *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                   size: 0x44u,
                                                   tag: TAG_NEW,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
  if ( v11 != nullptr )
    v12 = idBotBehaviorCombat_RunAndAttackEnemy::idBotBehaviorCombat_RunAndAttackEnemy(this: v11);
  else
    v12 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v12);
}


// ========================================================================
// __unwind$489485_0
// EA  : 0x82B37468
// RVA : 0x00B37468
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489485_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489486_0
// EA  : 0x82B37490
// RVA : 0x00B37490
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489486_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489487_0
// EA  : 0x82B374B8
// RVA : 0x00B374B8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489487_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489488_0
// EA  : 0x82B374E0
// RVA : 0x00B374E0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489488_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorCombat_TargetVis_CloseRange_Thrown@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37510
// RVA : 0x00B37510
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Thrown::Init(
        idBotBehaviorCombat_TargetVis_CloseRange_Thrown *this,
        idBot *bot,
        const int curTime)
{
  idBotBehaviorCombat_CircleStafeEnemy *v5; // r3
  idBotBehaviorCombat_CircleStafeEnemy *v6; // r5
  idBotBehaviorCombat_SideStrafeEnemy *v7; // r3
  idBotBehaviorCombat_SideStrafeEnemy *v8; // r5
  idBotBehaviorCombat_RunAndAttackEnemy *v9; // r3
  idBotBehaviorCombat_RunAndAttackEnemy *v10; // r5

  v5 = (idBotBehaviorCombat_CircleStafeEnemy *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                 size: 0x40u,
                                                 tag: TAG_NEW,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idBotBehaviorCombat_CircleStafeEnemy::idBotBehaviorCombat_CircleStafeEnemy(this: v5);
  else
    v6 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v6);
  v7 = (idBotBehaviorCombat_SideStrafeEnemy *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                size: 0x40u,
                                                tag: TAG_NEW,
                                                zeroBuffer: false,
                                                align: ALIGN_16,
                                                heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idBotBehaviorCombat_SideStrafeEnemy::idBotBehaviorCombat_SideStrafeEnemy(this: v7);
  else
    v8 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v8);
  v9 = (idBotBehaviorCombat_RunAndAttackEnemy *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                  size: 0x44u,
                                                  tag: TAG_NEW,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v10 = idBotBehaviorCombat_RunAndAttackEnemy::idBotBehaviorCombat_RunAndAttackEnemy(this: v9);
  else
    v10 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v10);
}


// ========================================================================
// __unwind$489564
// EA  : 0x82B37618
// RVA : 0x00B37618
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489564(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489565
// EA  : 0x82B37640
// RVA : 0x00B37640
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489565(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489566
// EA  : 0x82B37668
// RVA : 0x00B37668
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489566(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorCombat_TargetVis_CloseRange_Sniper@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37698
// RVA : 0x00B37698
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Sniper::Init(
        idBotBehaviorCombat_TargetVis_CloseRange_Sniper *this,
        idBot *bot,
        const int curTime)
{
  idBotBehaviorCombat_StandGroundAttackEnemy *v5; // r3
  idBotBehaviorCombat_StandGroundAttackEnemy *v6; // r5
  idBotBehaviorCombat_SideStrafeEnemy *v7; // r3
  idBotBehaviorCombat_SideStrafeEnemy *v8; // r5
  idBotBehaviorCombat_CrouchAttackEnemy *v9; // r3
  idBotBehaviorCombat_CrouchAttackEnemy *v10; // r5

  v5 = (idBotBehaviorCombat_StandGroundAttackEnemy *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                       size: 0x40u,
                                                       tag: TAG_NEW,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idBotBehaviorCombat_StandGroundAttackEnemy::idBotBehaviorCombat_StandGroundAttackEnemy(this: v5);
  else
    v6 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v6);
  v7 = (idBotBehaviorCombat_SideStrafeEnemy *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                size: 0x40u,
                                                tag: TAG_NEW,
                                                zeroBuffer: false,
                                                align: ALIGN_16,
                                                heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idBotBehaviorCombat_SideStrafeEnemy::idBotBehaviorCombat_SideStrafeEnemy(this: v7);
  else
    v8 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v8);
  v9 = (idBotBehaviorCombat_CrouchAttackEnemy *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                  size: 0x40u,
                                                  tag: TAG_NEW,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v10 = idBotBehaviorCombat_CrouchAttackEnemy::idBotBehaviorCombat_CrouchAttackEnemy(this: v9);
  else
    v10 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v10);
}


// ========================================================================
// __unwind$489629
// EA  : 0x82B377A0
// RVA : 0x00B377A0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489629(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489630
// EA  : 0x82B377C8
// RVA : 0x00B377C8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489630(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$489631
// EA  : 0x82B377F0
// RVA : 0x00B377F0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489631(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorCombat_TargetVis_LongRange@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37820
// RVA : 0x00B37820
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_TargetVis_LongRange::Init(
        idBotBehaviorCombat_TargetVis_LongRange *this,
        idBot *bot,
        const int curTime)
{
  idBotBehaviorCombat_RunAndAttackEnemy *v5; // r3
  idBotBehaviorCombat_RunAndAttackEnemy *v6; // r5

  v5 = (idBotBehaviorCombat_RunAndAttackEnemy *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                  size: 0x44u,
                                                  tag: TAG_NEW,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idBotBehaviorCombat_RunAndAttackEnemy::idBotBehaviorCombat_RunAndAttackEnemy(this: v5);
  else
    v6 = nullptr;
  idBehaviorComposite::AppendState(this, rootTree: bot->behaviorTree, newState: v6);
}


// ========================================================================
// __unwind$489686
// EA  : 0x82B37890
// RVA : 0x00B37890
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

void __fastcall _unwind_489686(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?Think@idBotBehaviorCombat_TargetVis_CloseRange_Melee@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B378B8
// RVA : 0x00B378B8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Melee::Think(
        idBotBehaviorCombat_TargetVis_CloseRange_Melee *this,
        idBot *bot,
        const int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r4

  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  idBotAimState::AddAimRequestEntity(
    this: bot->aimState,
    entity: v6,
    priority: AIM_PRIORITY_BEHAVIOR_DRIVEN,
    userName: "CLOSE_RANGE_VIS_TARGET_MELEE",
    aimPoint: AIMPOINT_BEST,
    aimTimeInSeconds: -1.0);
  return 1;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_TargetVis_CloseRange_SMG@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B37950
// RVA : 0x00B37950
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange_SMG::Think(
        idBotBehaviorCombat_TargetVis_CloseRange_SMG *this,
        idBot *bot,
        const int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r4

  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  idBotAimState::AddAimRequestEntity(
    this: bot->aimState,
    entity: v6,
    priority: AIM_PRIORITY_BEHAVIOR_DRIVEN,
    userName: "CLOSE_RANGE_VIS_TARGET_SMG",
    aimPoint: AIMPOINT_BEST,
    aimTimeInSeconds: -1.0);
  return 1;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_TargetVis_CloseRange_Shotgun@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B379E8
// RVA : 0x00B379E8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::Think(
        idBotBehaviorCombat_TargetVis_CloseRange_Shotgun *this,
        idBot *bot,
        const int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r4

  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  idBotAimState::AddAimRequestEntity(
    this: bot->aimState,
    entity: v6,
    priority: AIM_PRIORITY_BEHAVIOR_DRIVEN,
    userName: "CLOSE_RANGE_VIS_TARGET_SHOTGUN",
    aimPoint: AIMPOINT_BEST,
    aimTimeInSeconds: -1.0);
  return 1;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_TargetVis_CloseRange_Thrown@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B37A80
// RVA : 0x00B37A80
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Thrown::Think(
        idBotBehaviorCombat_TargetVis_CloseRange_Thrown *this,
        idBot *bot,
        const int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r4

  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  idBotAimState::AddAimRequestEntity(
    this: bot->aimState,
    entity: v6,
    priority: AIM_PRIORITY_BEHAVIOR_DRIVEN,
    userName: "CLOSE_RANGE_VIS_TARGET_THROWN",
    aimPoint: AIMPOINT_TORSO,
    aimTimeInSeconds: -1.0);
  return 1;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_TargetVis_CloseRange_Sniper@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B37B18
// RVA : 0x00B37B18
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_TargetVis_CloseRange_Sniper::Think(
        idBotBehaviorCombat_TargetVis_CloseRange_Sniper *this,
        idBot *bot,
        const int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r4

  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  idBotAimState::AddAimRequestEntity(
    this: bot->aimState,
    entity: v6,
    priority: AIM_PRIORITY_BEHAVIOR_DRIVEN,
    userName: "CLOSE_RANGE_VIS_TARGET_SNIPER",
    aimPoint: AIMPOINT_HEAD,
    aimTimeInSeconds: -1.0);
  return 1;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_NonVisTarget@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B37BB0
// RVA : 0x00B37BB0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorCombat_NonVisTarget::GetPriority(
        idBotBehaviorCombat_NonVisTarget *this,
        idBot *bot,
        const int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r4

  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  idBotWorldState::GetRecordForEntity(this: bot->worldState, entity: v6);
  return BEHAVIOR_PRIORITY_NULL;
}

