
// ========================================================================
// ??0idBotBehaviorHighLevel@@QAA@XZ
// EA  : 0x82B3D658
// RVA : 0x00B3D658
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

idBotBehaviorHighLevel *__fastcall idBotBehaviorHighLevel::idBotBehaviorHighLevel(idBotBehaviorHighLevel *this)
{
  idBehaviorSelectorLooping::idBehaviorSelectorLooping(this);
  this->__vftable = (idBotBehaviorHighLevel_vtbl *)&idBotBehaviorHighLevel::`vftable';
  return this;
}


// ========================================================================
// ??0idBotBehaviorLowLevel@@QAA@XZ
// EA  : 0x82B3D698
// RVA : 0x00B3D698
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

idBotBehaviorLowLevel *__fastcall idBotBehaviorLowLevel::idBotBehaviorLowLevel(idBotBehaviorLowLevel *this)
{
  idBehaviorParallel::idBehaviorParallel(this);
  this->__vftable = (idBotBehaviorLowLevel_vtbl *)&idBotBehaviorLowLevel::`vftable';
  return this;
}


// ========================================================================
// ??0idBotBehaviorMain@@QAA@XZ
// EA  : 0x82B3D6D8
// RVA : 0x00B3D6D8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

idBotBehaviorMain *__fastcall idBotBehaviorMain::idBotBehaviorMain(idBotBehaviorMain *this)
{
  idBehaviorParallel::idBehaviorParallel(this);
  this->__vftable = (idBotBehaviorMain_vtbl *)&idBotBehaviorMain::`vftable';
  return this;
}


// ========================================================================
// ??0idBotBehaviorDead@@QAA@XZ
// EA  : 0x82B3D718
// RVA : 0x00B3D718
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

idBotBehaviorDead *__fastcall idBotBehaviorDead::idBotBehaviorDead(idBotBehaviorDead *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->__vftable = (idBotBehaviorDead_vtbl *)&idBotBehaviorDead::`vftable';
  this->tauntTime = 0.0;
  return this;
}


// ========================================================================
// ??0idBotBehaviorRoot@@QAA@XZ
// EA  : 0x82B3D760
// RVA : 0x00B3D760
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

idBotBehaviorRoot *__fastcall idBotBehaviorRoot::idBotBehaviorRoot(idBotBehaviorRoot *this)
{
  idBehaviorSelector::idBehaviorSelector(this);
  this->__vftable = (idBotBehaviorRoot_vtbl *)&idBotBehaviorRoot::`vftable';
  return this;
}


// ========================================================================
// ??0idBotBehaviorTree@@QAA@XZ
// EA  : 0x82B3D7A0
// RVA : 0x00B3D7A0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

idBotBehaviorTree *__fastcall idBotBehaviorTree::idBotBehaviorTree(idBotBehaviorTree *this)
{
  idBehaviorTree::idBehaviorTree(this);
  this->__vftable = (idBotBehaviorTree_vtbl *)&idBotBehaviorTree::`vftable';
  return this;
}


// ========================================================================
// ?Init@idBotBehaviorHighLevel@@UAAXPAVidBot@@H@Z
// EA  : 0x82B3DA58
// RVA : 0x00B3DA58
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall idBotBehaviorHighLevel::Init(idBotBehaviorHighLevel *this, idBot *bot, const int curTime)
{
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  idBotBehaviorReact *v10; // r3
  idBotBehaviorReact *v11; // r5
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r7
  int v16; // r6
  idBotBehaviorBehave *v17; // r3
  idBotBehaviorBehave *v18; // r5
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

  v10 = (idBotBehaviorReact *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x4Cu,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
    v11 = idBotBehaviorReact::idBotBehaviorReact(this: v10);
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
  v17 = (idBotBehaviorBehave *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                 size: 0x4Cu,
                                 tag: TAG_NEW,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v17 != nullptr )
    v18 = idBotBehaviorBehave::idBotBehaviorBehave(this: v17);
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
// __unwind$488642
// EA  : 0x82B3DB18
// RVA : 0x00B3DB18
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall _unwind_488642(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$488643_0
// EA  : 0x82B3DB40
// RVA : 0x00B3DB40
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall _unwind_488643_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorMain@@UAAXPAVidBot@@H@Z
// EA  : 0x82B3DB70
// RVA : 0x00B3DB70
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall idBotBehaviorMain::Init(idBotBehaviorMain *this, idBot *bot, const int curTime)
{
  void **v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  idBehaviorSelectorLooping *v10; // r3
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
    v5 = &idBotBehaviorHighLevel::`vftable';
    v11->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorHighLevel::`vftable';
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
// __unwind$488688
// EA  : 0x82B3DBF0
// RVA : 0x00B3DBF0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall _unwind_488688(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?GetPriority@idBotBehaviorMain@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3DC18
// RVA : 0x00B3DC18
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorMain::GetPriority(idBotBehaviorMain *this, idBot *bot, const int curTime)
{
  double v3; // fp1
  behaviorPriority_t result; // r3

  v3 = ((double (__fastcall *)(idTungstenHealth *))bot->owner->playerHealth.GetCurBaseHealth_Impl)(a1: &bot->owner->playerHealth);
  result = BEHAVIOR_PRIORITY_NORMAL;
  if ( v3 <= 0.0 )
    return BEHAVIOR_PRIORITY_NULL;
  return result;
}


// ========================================================================
// ?GetPriority@idBotBehaviorDead@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3DC68
// RVA : 0x00B3DC68
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorDead::GetPriority(idBotBehaviorDead *this, idBot *bot, const int curTime)
{
  double v3; // fp1
  behaviorPriority_t result; // r3

  v3 = ((double (__fastcall *)(idTungstenHealth *))bot->owner->playerHealth.GetCurBaseHealth_Impl)(a1: &bot->owner->playerHealth);
  result = BEHAVIOR_PRIORITY_NORMAL;
  if ( v3 > 0.0 )
    return BEHAVIOR_PRIORITY_NULL;
  return result;
}


// ========================================================================
// ?Enter@idBotBehaviorDead@@UAAXPAVidBot@@H@Z
// EA  : 0x82B3DCB8
// RVA : 0x00B3DCB8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall idBotBehaviorDead::Enter(idBotBehaviorDead *this, idBot *bot, const int curTime)
{
  __int64 v3; // r10

  HIDWORD(v3) = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = HIDWORD(v3);
  if ( ((HIDWORD(v3) >> 10) & 0x7FFF) % 0x64 >= 0x50 )
  {
    this->tauntTime = 0.0;
  }
  else
  {
    LODWORD(v3) = curTime + 150;
    this->tauntTime = (float)v3;
  }
}


// ========================================================================
// ?Think@idBotBehaviorDead@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3DD40
// RVA : 0x00B3DD40
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

behaviorStatus_t __fastcall idBotBehaviorDead::Think(idBotBehaviorDead *this, idBot *bot, const int curTime)
{
  __int64 v3; // r11
  double tauntTime; // fp0
  unsigned int v5; // r3
  behaviorStatus_t result; // r3
  unsigned int v7; // r9

  tauntTime = this->tauntTime;
  if ( tauntTime > 0.0 )
  {
    LODWORD(v3) = curTime;
    if ( tauntTime < (float)v3 )
      this->tauntTime = 0.0;
  }
  v5 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v5;
  v7 = (v5 >> 10) & 0x7FFF;
  result = BEHAVIOR_STATUS_RUNNING;
  if ( v7 % 0x64 > 0x62 )
    bot->usercmd.buttons = 4;
  return result;
}


// ========================================================================
// ?Init@idBotBehaviorRoot@@UAAXPAVidBot@@H@Z
// EA  : 0x82B3DDE0
// RVA : 0x00B3DDE0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall idBotBehaviorRoot::Init(idBotBehaviorRoot *this, idBot *bot, const int curTime)
{
  char *v5; // r10
  void **v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  idBehaviorAction *v10; // r3
  idBehaviorAction *v11; // r30
  idBehaviorState *v12; // r5
  void **v13; // r10
  int v14; // r9
  int v15; // r8
  int v16; // r7
  int v17; // r6
  idBehaviorParallel *v18; // r3
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

  v10 = (idBehaviorAction *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x3Cu,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v11 = v10;
  if ( v10 != nullptr )
  {
    idBehaviorAction::idBehaviorAction(this: v10);
    v5 = "Could not find AI state, idVS_ds_Car_Chase! ";
    v12 = v11;
    v6 = &idBotBehaviorDead::`vftable';
    v11->__vftable = (idBehaviorAction_vtbl *)&idBotBehaviorDead::`vftable';
    *(float *)&v11[1].__vftable = 0.0;
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
    a7: (int)v6,
    a8: (int)v5,
    a9: v21,
    a10: v23,
    a11: v25,
    a12: v27,
    a13: v29,
    a14: v31,
    a15: v33,
    a16: v35);
  v18 = (idBehaviorParallel *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x48u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v19 = v18;
  if ( v18 != nullptr )
  {
    idBehaviorParallel::idBehaviorParallel(this: v18);
    v20 = v19;
    v13 = &idBotBehaviorMain::`vftable';
    v19->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorMain::`vftable';
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
// __unwind$488792_0
// EA  : 0x82B3DECC
// RVA : 0x00B3DECC
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall _unwind_488792_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$488793_0
// EA  : 0x82B3DEF4
// RVA : 0x00B3DEF4
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall _unwind_488793_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Init@idBotBehaviorTree@@UAAXPAVidBot@@H@Z
// EA  : 0x82B3DF28
// RVA : 0x00B3DF28
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall idBotBehaviorTree::Init(idBotBehaviorTree *this, idBot *bot, const int curTime)
{
  void **v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  idBehaviorSelector *v10; // r3
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

  v10 = (idBehaviorSelector *)idMem::AllocWithLocation(
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
    idBehaviorSelector::idBehaviorSelector(this: v10);
    v12 = v11;
    v5 = &idBotBehaviorRoot::`vftable';
    v11->__vftable = (idBehaviorState_vtbl *)&idBotBehaviorRoot::`vftable';
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
// __unwind$488845_0
// EA  : 0x82B3DFA8
// RVA : 0x00B3DFA8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\bot_bt_root.cpp
// ========================================================================

void __fastcall _unwind_488845_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}

