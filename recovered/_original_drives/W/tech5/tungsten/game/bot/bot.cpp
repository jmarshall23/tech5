
// ========================================================================
// ?OnDeath@idBot@@QAAXPBVidEntity@@@Z
// EA  : 0x82B3DFD0
// RVA : 0x00B3DFD0
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::OnDeath(idBot *this, const idEntity *killer)
{
  idBotGoal::Bot_ResetGoal(this: &this->goalTask);
  idBotWorldState::ClearVolatileData(this: this->worldState);
}


// ========================================================================
// ?SetupUcmdsForNewFrame@idBot@@IAAXXZ
// EA  : 0x82B3E008
// RVA : 0x00B3E008
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::SetupUcmdsForNewFrame(idBot *this)
{
  int clientGameFrame; // r30
  int ServerGameTime; // r3
  char v4; // r9

  clientGameFrame = this->usercmd.clientGameFrame;
  memset(Dst: &this->usercmd, Val: 0, Size: sizeof(this->usercmd));
  this->usercmd.clientGameFrame = clientGameFrame + 1;
  ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
  v4 = *((_BYTE *)&this->usercmd + 9);
  this->usercmd.serverGameTime = ServerGameTime;
  *((_BYTE *)&this->usercmd + 9) = v4 | 0x40;
}


// ========================================================================
// ?OnTakeDamage@idBot@@QAAXPBVidEntity@@@Z
// EA  : 0x82B3E070
// RVA : 0x00B3E070
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::OnTakeDamage(idBot *this, idEntity *attacker)
{
  int GameMs; // r28
  idBotTargetRecord *RecordForEntity; // r3
  float *p_timeLastVisible; // r31
  idPhysics *Physics; // r3
  float *v8; // r3
  idPhysics *v9; // r3
  float *v10; // r3

  if ( attacker != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    RecordForEntity = idBotWorldState::GetRecordForEntity(this: this->worldState, entity: attacker);
    p_timeLastVisible = (float *)&RecordForEntity->volatileData.timeLastVisible;
    if ( RecordForEntity != nullptr )
    {
      RecordForEntity->volatileData.timeLastAttackedBy = GameMs;
      Physics = idEntity::GetPhysics(this: this->owner);
      v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      p_timeLastVisible[27] = *v8;
      p_timeLastVisible[28] = v8[1];
      p_timeLastVisible[29] = v8[2];
      v9 = idEntity::GetPhysics(this: attacker);
      v10 = (float *)v9->GetOrigin(this: v9, a2: 0);
      p_timeLastVisible[21] = *v10;
      p_timeLastVisible[22] = v10[1];
      p_timeLastVisible[23] = v10[2];
    }
    idBotWorldState::SetLastAttacker(this: this->worldState, attacker, time: GameMs);
  }
}


// ========================================================================
// ?HandleViewCmds@idBot@@IAAXXZ
// EA  : 0x82B3E148
// RVA : 0x00B3E148
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::HandleViewCmds(idBot *this)
{
  idBotAimState *aimState; // r30
  idPresentable *presentable; // r3
  int v4; // r3
  double yaw; // fp9
  double v6; // fp8

  aimState = this->aimState;
  presentable = this->owner->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  this->usercmd.angles[0] = (int)(float)((float)(aimState->desiredViewAngles.pitch - *(float *)(v4 + 36840))
                                       * (float)182.04445);
  yaw = aimState->desiredViewAngles.yaw;
  v6 = *(float *)(v4 + 36844);
  this->usercmd.angles[2] = 0;
  this->usercmd.angles[1] = (unsigned int)(int)(float)((float)((float)yaw - (float)v6) * (float)182.04445) >> 16;
}


// ========================================================================
// ?InitBehaviorTree@idBot@@IAAXXZ
// EA  : 0x82B3E208
// RVA : 0x00B3E208
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::InitBehaviorTree(idBot *this)
{
  idBotBehaviorTree *v2; // r3
  idBotBehaviorTree *v3; // r3
  int GameMs; // r3

  v2 = (idBotBehaviorTree *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x4Cu,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idBotBehaviorTree::idBotBehaviorTree(this: v2);
  else
    v3 = nullptr;
  this->behaviorTree = v3;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idBehaviorTree::RootInit(this: this->behaviorTree, bot: this, curTime: GameMs);
}


// ========================================================================
// __unwind$489559
// EA  : 0x82B3E2A8
// RVA : 0x00B3E2A8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall _unwind_489559(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?InitWeaponState@idBot@@IAAXXZ
// EA  : 0x82B3E2D8
// RVA : 0x00B3E2D8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::InitWeaponState(idBot *this)
{
  idBotWeaponState *v2; // r3
  idBotWeaponState *v3; // r3

  v2 = (idBotWeaponState *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0xD8u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idBotWeaponState::idBotWeaponState(this: v2);
  else
    v3 = nullptr;
  this->weaponState = v3;
  v3->owner = this;
}


// ========================================================================
// __unwind$489589
// EA  : 0x82B3E354
// RVA : 0x00B3E354
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall _unwind_489589(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?InitWorldState@idBot@@IAAXXZ
// EA  : 0x82B3E388
// RVA : 0x00B3E388
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::InitWorldState(idBot *this)
{
  idBotWorldState *v2; // r3
  idBotWorldState *v3; // r3

  v2 = (idBotWorldState *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                            size: 0x30u,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idBotWorldState::idBotWorldState(this: v2);
  else
    v3 = nullptr;
  this->worldState = v3;
  v3->owner = this;
}


// ========================================================================
// __unwind$489616
// EA  : 0x82B3E404
// RVA : 0x00B3E404
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall _unwind_489616(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?InitMoveState@idBot@@IAAXXZ
// EA  : 0x82B3E438
// RVA : 0x00B3E438
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::InitMoveState(idBot *this)
{
  idBotMoveState *v2; // r3
  idBotMoveState *v3; // r3

  v2 = (idBotMoveState *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x4D4u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idBotMoveState::idBotMoveState(this: v2);
  else
    v3 = nullptr;
  this->moveState = v3;
  XAUDIO2::CX2SourceVoice::SetVoiceState(this: (XAUDIO2::CX2Voice *)v3, eNewState: (XAUDIO2::CX2Voice::EVoiceState)this);
}


// ========================================================================
// __unwind$489643
// EA  : 0x82B3E4B8
// RVA : 0x00B3E4B8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall _unwind_489643(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?InitAimState@idBot@@IAAXXZ
// EA  : 0x82B3E4E8
// RVA : 0x00B3E4E8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::InitAimState(idBot *this)
{
  idBotAimState *v2; // r3
  idBotAimState *v3; // r3

  v2 = (idBotAimState *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x12Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idBotAimState::idBotAimState(this: v2);
  else
    v3 = nullptr;
  this->aimState = v3;
  v3->owner = this;
}


// ========================================================================
// __unwind$489667
// EA  : 0x82B3E564
// RVA : 0x00B3E564
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall _unwind_489667(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?ProjectTopDown@idBot@@QBAXAAVidVec3@@@Z
// EA  : 0x82B3E590
// RVA : 0x00B3E590
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::ProjectTopDown(idBot *this, idVec3 *point)
{
  idPlayer *DebugPlayer; // r31
  idPhysics *Physics; // r3
  float *v6; // r29
  idPresentable *presentable; // r3
  const idAngles *v8; // r4
  const idAngles *ViewAngles; // r3
  idPresentable *v10; // r11
  double yaw; // fp31
  int v12; // r3
  idPresentable *v13; // r11
  float *v14; // r31
  int v15; // r11
  float *v16; // r28
  double v17; // fp1
  double v18; // fp2
  double v19; // fp6
  double v20; // fp13
  double v21; // fp4
  double v22; // fp12
  double v23; // fp11
  double v24; // fp2
  double v25; // fp1
  double v26; // fp8
  double v27; // fp7
  idMat3 v28; // [sp+50h] [-80h] BYREF
  float v29; // [sp+74h] [-5Ch]
  float v30; // [sp+78h] [-58h]
  float v31; // [sp+7Ch] [-54h]
  float v32; // [sp+80h] [-50h]
  float v33; // [sp+84h] [-4Ch]
  float v34; // [sp+88h] [-48h]
  float v35; // [sp+8Ch] [-44h]
  float v36; // [sp+90h] [-40h]

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    Physics = idEntity::GetPhysics(this: this->owner);
    v6 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    presentable = DebugPlayer->presentable;
    if ( presentable != nullptr )
      v8 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v8 = nullptr;
    ViewAngles = idPresentablePlayer::GetViewAngles(
                   this: (idPresentablePlayer *)&v28.mat[1].y,
                   result: v8,
                   includeWeaponKick: true);
    v10 = DebugPlayer->presentable;
    yaw = ViewAngles->yaw;
    if ( v10 != nullptr )
      v12 = (int)v10->GetPlayerInterface_2(this: DebugPlayer->presentable);
    else
      v12 = 0;
    v13 = DebugPlayer->presentable;
    v14 = (float *)(v12 + 46544);
    if ( v13 != nullptr )
      v15 = (int)v13->GetPlayerInterface_2(this: v13);
    else
      v15 = 0;
    v28.mat[0].y = -yaw;
    v16 = (float *)(v15 + 46532);
    v28.mat[0].x = 0.0;
    v28.mat[0].z = 0.0;
    idAngles::ToMat3(this: (idAngles *)&v28.mat[2].z, result: &v28);
    v17 = (float)(point->x - *v6);
    v18 = (float)((float)(v35 * (float)(point->z - v6[2])) + (float)(v32 * (float)(point->y - v6[1])));
    v19 = v29;
    v20 = (float)((float)(v36 * (float)(point->z - v6[2])) + (float)(v33 * (float)(point->y - v6[1])));
    v21 = v30;
    v22 = (float)((float)(v28.mat[2].z * (float)(point->x - *v6))
                + (float)((float)(v34 * (float)(point->z - v6[2])) + (float)(v31 * (float)(point->y - v6[1]))));
    point->x = (float)(v28.mat[2].z * (float)(point->x - *v6))
             + (float)((float)(v34 * (float)(point->z - v6[2])) + (float)(v31 * (float)(point->y - v6[1])));
    v23 = (float)((float)((float)v19 * (float)v17) + (float)v18);
    point->y = (float)((float)v19 * (float)v17) + (float)v18;
    point->z = (float)((float)v21 * (float)v17) + (float)v20;
    v24 = (float)(v14[6] * (float)v22);
    v25 = (float)(v14[7] * (float)v22);
    v26 = (float)((float)(v16[1] + (float)(v14[1] * (float)2048.0)) + (float)(v14[4] * (float)v23));
    v27 = (float)((float)((float)(*v14 * (float)2048.0) + *v16) + (float)(v14[3] * (float)v23));
    point->z = (float)((float)(v16[2] + (float)(v14[2] * (float)2048.0)) + (float)(v14[5] * (float)v23))
             + (float)(v14[8] * (float)v22);
    point->y = (float)v26 + (float)v25;
    point->x = (float)v27 + (float)v24;
  }
}


// ========================================================================
// ??0idBot@@QAA@PAVidPlayer@@PBVidDeclBot@@@Z
// EA  : 0x82B3E7B8
// RVA : 0x00B3E7B8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

idBot *__fastcall idBot::idBot(idBot *this, idPlayer *newOwner, const idDeclBot *botDef)
{
  char v5; // r8
  idLobbyBase *v6; // r28
  idPresentable *presentable; // r3
  lobbyUserID_t *v8; // r4
  idLobbyBase_vtbl *v9; // r29
  lobbyUserID_t *LobbyUserID; // r3
  int v12; // [sp+50h] [-30h] BYREF

  this->owner = newOwner;
  this->behaviorDef = botDef;
  this->behaviorTree = nullptr;
  this->__vftable = (idBot_vtbl *)&idBot::`vftable';
  this->aimState = nullptr;
  this->worldState = nullptr;
  this->isControllingAFKPlayer = false;
  this->debugName = nullptr;
  this->moveState = nullptr;
  this->weaponState = nullptr;
  idBotGoal::idBotGoal(this: &this->goalTask);
  v5 = *((_BYTE *)&this->usercmd + 9);
  this->usercmd.buttons = 0;
  this->usercmd.buttons2 = 0;
  this->usercmd.forwardmove = 0;
  this->usercmd.rightmove = 0;
  this->usercmd.pos[2] = 0.0;
  this->usercmd.upmove = 0;
  this->usercmd.pos[1] = 0.0;
  this->usercmd.angles[2] = 0;
  this->usercmd.pos[0] = 0.0;
  this->usercmd.angles[1] = 0;
  this->usercmd.angles[0] = 0;
  this->usercmd.clientGameFrame = 0;
  *((_BYTE *)&this->usercmd + 9) = v5 & 0x3F;
  this->usercmd.yaw = 0;
  this->usercmd.pitch = 0;
  this->usercmd.roll = 0;
  this->usercmd.predictionStateBits = 0;
  this->usercmd.vehicleThrottle = 0;
  this->usercmd.serverGameTime = 0;
  this->usercmd.fireCount = 0;
  this->usercmd.fireAngles[1] = 0;
  this->usercmd.fireAngles[0] = 0;
  this->usercmd.firePos[2] = 0;
  this->usercmd.firePos[1] = 0;
  this->usercmd.firePos[0] = 0;
  this->usercmd.speed = 0;
  if ( !idGameLocal::BotSystems_IsInit(this: gameLocal) )
    idLib::Error(
      fmt: "Trying to Add A Bot Without Bot Systems Setup - Make Sure Bots Are Supported In The GameType You're Trying To Run,"
      " Else Contact Mal!");
  idBot::SetupUcmdsForNewFrame(this);
  idBot::InitBehaviorTree(this);
  idBot::InitWorldState(this);
  idBot::InitMoveState(this);
  idBot::InitAimState(this);
  idBot::InitWeaponState(this);
  if ( botDef == nullptr )
    this->isControllingAFKPlayer = true;
  v6 = session->GetActingGameStateLobbyBase(this: session);
  presentable = this->owner->presentable;
  if ( presentable != nullptr )
    v8 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v8 = nullptr;
  v9 = v6->__vftable;
  LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v12, result: v8);
  this->debugName = v9->GetLobbyUserName(
                      this: (idLobbyBase *)LobbyUserID->localUserHandle.handle,
                      a2: *(lobbyUserID_t **)&LobbyUserID->lobbyType);
  return this;
}


// ========================================================================
// $LN17_5
// EA  : 0x82B3E96C
// RVA : 0x00B3E96C
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _LN17_5()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// ??1idBot@@UAA@XZ
// EA  : 0x82B3E9A0
// RVA : 0x00B3E9A0
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::~idBot(idBot *this)
{
  idBotBehaviorTree *behaviorTree; // r3
  idBotAimState *aimState; // r29
  idBotWorldState *worldState; // r29
  idBotMoveState *moveState; // r3
  idBotWeaponState *weaponState; // r29

  this->__vftable = (idBot_vtbl *)&idBot::`vftable';
  behaviorTree = this->behaviorTree;
  if ( behaviorTree != nullptr )
  {
    ((void (__fastcall *)(idBotBehaviorTree *, int))behaviorTree->dtr_idClass)(a1: behaviorTree, a2: 1);
    this->behaviorTree = nullptr;
  }
  aimState = this->aimState;
  if ( aimState != nullptr )
  {
    idBotAimState::~idBotAimState(this: this->aimState);
    idMem::Free(this: &mem, ptr: aimState, align: ALIGN_16);
    this->aimState = nullptr;
  }
  worldState = this->worldState;
  if ( worldState != nullptr )
  {
    idBotWorldState::~idBotWorldState(this: this->worldState);
    idMem::Free(this: &mem, ptr: worldState, align: ALIGN_16);
    this->worldState = nullptr;
  }
  moveState = this->moveState;
  if ( moveState != nullptr )
  {
    ((void (__fastcall *)(idBotMoveState *, int))moveState->dtr_idBotMoveState)(a1: moveState, a2: 1);
    this->moveState = nullptr;
  }
  weaponState = this->weaponState;
  if ( weaponState != nullptr )
  {
    idBotWeaponState::~idBotWeaponState(this: this->weaponState);
    idMem::Free(this: &mem, ptr: weaponState, align: ALIGN_16);
    this->weaponState = nullptr;
  }
  this->behaviorDef = nullptr;
  this->owner = nullptr;
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->goalTask);
}


// ========================================================================
// __unwind$490182_0
// EA  : 0x82B3EABC
// RVA : 0x00B3EABC
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_490182_0()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 144 + 164) + 40));
}


// ========================================================================
// ?HACK_CHECK_ATTACK_FUNC_NEEDS_REMOVED@idBot@@QAAXXZ
// EA  : 0x82B3EAE8
// RVA : 0x00B3EAE8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::HACK_CHECK_ATTACK_FUNC_NEEDS_REMOVED(idBot *this)
{
  int value; // r10
  idEntity *v3; // r3
  idEntity *v4; // r4
  idBotTargetRecord *RecordForEntity; // r3
  double health; // fp13
  unsigned int v7; // r3

  if ( bot_allowWeapons.valueInteger != 0 && !this->owner->IsDead(this: this->owner) )
  {
    value = this->goalTask.goalEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v3 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v3 != nullptr )
      {
        v4 = idEntity::CastTo(c: v3);
        if ( v4 != nullptr )
        {
          RecordForEntity = idBotWorldState::GetRecordForEntity(this: this->worldState, entity: v4);
          if ( RecordForEntity != nullptr )
          {
            health = RecordForEntity->volatileData.health;
            if ( (RecordForEntity->volatileData.targetFlags.flags & 8) != 0
              && RecordForEntity->volatileData.dotToTarget > 0.0 )
            {
              v7 = 1664525 * clientGame->random.seed + 1013904223;
              clientGame->random.seed = v7;
              if ( ((v7 >> 10) & 0x7FFF) % 0x64 < 0x50 && health > 0.0 )
                this->usercmd.buttons = 1;
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?RunDebugChecks@idBot@@IAAXXZ
// EA  : 0x82B3EC50
// RVA : 0x00B3EC50
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::RunDebugChecks(idBot *this)
{
  idPlayer *DebugPlayer; // r25
  bool v3; // r26
  idPhysics *Physics; // r24
  idRenderWorld *v5; // r23
  idPhysics *v6; // r3
  int v7; // r22
  idRenderWorld_vtbl *v8; // r30
  int v9; // r3
  idPhysics *v10; // r3
  float *v11; // r3
  double v12; // fp7
  double v13; // fp5
  double v14; // fp3
  idTungstenHealth *p_playerHealth; // r3
  double v18; // fp4
  double v19; // fp4
  double v20; // fp8
  double v21; // fp10
  double v22; // fp7
  double v23; // fp25
  double v24; // fp29
  double v25; // fp28
  double v26; // fp23
  double v27; // fp22
  double v28; // fp19
  float (__fastcall *GetTotalHealthRatio_Impl)(struct idTungstenHealth *); // r7
  double v30; // fp24
  double v31; // fp26
  double v32; // fp20
  double v33; // fp31
  double v34; // fp20
  idRenderWorld *v35; // r3
  idRenderWorld *v36; // r3
  float v37; // [sp+50h] [-150h]
  float v38[4]; // [sp+58h] [-148h] BYREF
  idVec3 v39; // [sp+68h] [-138h] BYREF
  idVec3 v40; // [sp+78h] [-128h] BYREF
  idVec3 v41; // [sp+88h] [-118h] BYREF
  idVec3 v42[2]; // [sp+98h] [-108h] BYREF
  idWinding v43; // [sp+B0h] [-F0h] BYREF
  idWinding v44[8]; // [sp+C0h] [-E0h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    v3 = (_cntlzw((char *)idGameLocal::BotSystems_GetBotDebugEntity(this: gameLocal) - (char *)this->owner) & 0x20) != 0;
    if ( bot_drawBounds.valueInteger != 0 )
    {
      Physics = idEntity::GetPhysics(this: this->owner);
      v5 = gameLocal->GetRenderWorld(this: gameLocal);
      v6 = idEntity::GetPhysics(this: this->owner);
      v7 = (int)v6->GetOrigin(this: v6, a2: 0);
      v8 = v5->__vftable;
      v9 = (int)Physics->GetBounds(this: Physics, a2: -1);
      v8->DebugBounds(
        this: v5,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idBounds *)v9,
        a4: (const idVec3 *)v7,
        a5: 0,
        a6: false);
    }
    if ( bot_drawHealth.valueInteger != 0 || v3 )
    {
      this->owner->GetEyePos(this: this->owner, a2: (idVec3 *)v38);
      v10 = idEntity::GetPhysics(this: DebugPlayer);
      v11 = (float *)v10->GetOrigin(this: v10, a2: 0);
      v12 = (float)(v11[1] - v38[1]);
      v13 = (float)(*v11 - v38[0]);
      v14 = (float)(v11[2] - v38[2]);
      _FP1 = (float)((float)((float)((float)(v11[2] - v38[2]) * (float)(v11[2] - v38[2]))
                           + (float)((float)((float)(*v11 - v38[0]) * (float)(*v11 - v38[0]))
                                   + (float)((float)(v11[1] - v38[1]) * (float)(v11[1] - v38[1]))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f1, f4, f10 }
      v18 = __frsqrte(_FP6);
      v19 = (float)((float)-(float)((float)((float)((float)v18
                                                  * (float)((float)((float)((float)(v11[2] - v38[2])
                                                                          * (float)(v11[2] - v38[2]))
                                                                  + (float)((float)((float)(*v11 - v38[0])
                                                                                  * (float)(*v11 - v38[0]))
                                                                          + (float)((float)(v11[1] - v38[1])
                                                                                  * (float)(v11[1] - v38[1]))))
                                                          * (float)0.5))
                                          * (float)v18)
                                  - (float)1.5)
                  * (float)v18);
      p_playerHealth = &this->owner->playerHealth;
      v20 = (float)((float)v14
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                                  * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5))
                                                                                          * (float)v19)
                                                                                  - (float)1.5)
                                                                  * (float)v19)
                                                          * (float)((float)((float)((float)v14 * (float)v14)
                                                                          + (float)((float)((float)v13 * (float)v13)
                                                                                  + (float)((float)v12 * (float)v12)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v19
                                                                                          * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v19)
                                                                          - (float)1.5)
                                                          * (float)v19))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v19
                                                                  * (float)((float)((float)((float)v14 * (float)v14)
                                                                                  + (float)((float)((float)v13
                                                                                                  * (float)v13)
                                                                                          + (float)((float)v12
                                                                                                  * (float)v12)))
                                                                          * (float)0.5))
                                                          * (float)v19)
                                                  - (float)1.5)
                                  * (float)v19)));
      v21 = (float)((float)v12
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                                  * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5))
                                                                                          * (float)v19)
                                                                                  - (float)1.5)
                                                                  * (float)v19)
                                                          * (float)((float)((float)((float)v14 * (float)v14)
                                                                          + (float)((float)((float)v13 * (float)v13)
                                                                                  + (float)((float)v12 * (float)v12)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v19
                                                                                          * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v19)
                                                                          - (float)1.5)
                                                          * (float)v19))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v19
                                                                  * (float)((float)((float)((float)v14 * (float)v14)
                                                                                  + (float)((float)((float)v13
                                                                                                  * (float)v13)
                                                                                          + (float)((float)v12
                                                                                                  * (float)v12)))
                                                                          * (float)0.5))
                                                          * (float)v19)
                                                  - (float)1.5)
                                  * (float)v19)));
      v23 = (float)(v38[0]
                  - (float)((float)((float)((float)v12
                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                          * (float)v19)
                                                                                  * (float)((float)((float)((float)v14 * (float)v14)
                                                                                                  + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                          * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v19)
                                                                                                  - (float)1.5)
                                                                                  * (float)v19))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v19
                                                                                          * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v19)
                                                                          - (float)1.5)
                                                          * (float)v19)))
                                  - (float)((float)v20 * (float)0.0))
                          * (float)35.0));
      v39.x = v38[0]
            - (float)((float)((float)((float)v12
                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                    * (float)v19)
                                                                            * (float)((float)((float)((float)v14 * (float)v14)
                                                                                            + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                    * (float)0.5))
                                                                    * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v19)
                                                                                            - (float)1.5)
                                                                            * (float)v19))
                                                            - (float)1.5)
                                            * (float)((float)-(float)((float)((float)((float)v19
                                                                                    * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                            * (float)0.5))
                                                                            * (float)v19)
                                                                    - (float)1.5)
                                                    * (float)v19)))
                            - (float)((float)v20 * (float)0.0))
                    * (float)35.0);
      v22 = (float)((float)v13
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                                  * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5))
                                                                                          * (float)v19)
                                                                                  - (float)1.5)
                                                                  * (float)v19)
                                                          * (float)((float)((float)((float)v14 * (float)v14)
                                                                          + (float)((float)((float)v13 * (float)v13)
                                                                                  + (float)((float)v12 * (float)v12)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v19
                                                                                          * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v19)
                                                                          - (float)1.5)
                                                          * (float)v19))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v19
                                                                  * (float)((float)((float)((float)v14 * (float)v14)
                                                                                  + (float)((float)((float)v13
                                                                                                  * (float)v13)
                                                                                          + (float)((float)v12
                                                                                                  * (float)v12)))
                                                                          * (float)0.5))
                                                          * (float)v19)
                                                  - (float)1.5)
                                  * (float)v19)));
      v24 = (float)((float)(v38[2] + (float)7.5)
                  - (float)((float)((float)((float)v22 * (float)0.0) - (float)((float)v21 * (float)0.0)) * (float)35.0));
      v25 = (float)(v38[1] - (float)((float)((float)((float)v20 * (float)0.0) - (float)v22) * (float)35.0));
      v26 = (float)((float)(v38[2] + (float)7.5)
                  + (float)((float)((float)((float)v22 * (float)0.0) - (float)((float)v21 * (float)0.0)) * (float)35.0));
      v27 = (float)(v38[1] + (float)((float)((float)((float)v20 * (float)0.0) - (float)v22) * (float)35.0));
      v28 = (float)(v38[0] + (float)((float)((float)v21 - (float)((float)v20 * (float)0.0)) * (float)35.0));
      GetTotalHealthRatio_Impl = p_playerHealth->GetTotalHealthRatio_Impl;
      v30 = (float)(v38[0] - (float)((float)((float)v21 - (float)((float)v20 * (float)0.0)) * (float)35.0));
      v39.y = v38[1] - (float)((float)((float)((float)v20 * (float)0.0) - (float)v22) * (float)35.0);
      v41.x = v38[0] + (float)((float)((float)v21 - (float)((float)v20 * (float)0.0)) * (float)35.0);
      v39.z = (float)(v38[2] + (float)7.5)
            - (float)((float)((float)((float)v22 * (float)0.0) - (float)((float)v21 * (float)0.0)) * (float)35.0);
      v41.y = v38[1] + (float)((float)((float)((float)v20 * (float)0.0) - (float)v22) * (float)35.0);
      v31 = (float)((float)(v38[2] + (float)10.0)
                  - (float)((float)((float)((float)v22 * (float)0.0) - (float)((float)v21 * (float)0.0)) * (float)35.0));
      v40.x = v38[0] - (float)((float)((float)v21 - (float)((float)v20 * (float)0.0)) * (float)35.0);
      v32 = (float)((float)(v38[2] + (float)10.0)
                  + (float)((float)((float)((float)v22 * (float)0.0) - (float)((float)v21 * (float)0.0)) * (float)35.0));
      v41.z = (float)(v38[2] + (float)7.5)
            + (float)((float)((float)((float)v22 * (float)0.0) - (float)((float)v21 * (float)0.0)) * (float)35.0);
      v42[0].x = v41.x;
      v37 = v38[2] + (float)10.0;
      v40.y = v39.y;
      v42[0].y = v41.y;
      v40.z = v37 - (float)((float)((float)((float)v22 * (float)0.0) - (float)((float)v21 * (float)0.0)) * (float)35.0);
      v42[0].z = v37
               + (float)((float)((float)((float)v22 * (float)0.0) - (float)((float)v21 * (float)0.0)) * (float)35.0);
      v33 = ((double (__fastcall *)(idTungstenHealth *))GetTotalHealthRatio_Impl)(a1: p_playerHealth);
      if ( v33 < 0.0 )
        v33 = 0.0;
      v44[0].allocedSize = 0;
      v44[0].__vftable = (idWinding_vtbl *)&idWinding::`vftable';
      v44[0].numPoints = 0;
      v44[0].p = nullptr;
      idWinding::AddPoint(this: v44, v: &v39);
      v39.z = (float)((float)((float)v26 - (float)v24) * (float)v33) + (float)v24;
      v39.y = (float)((float)((float)v27 - (float)v25) * (float)v33) + (float)v25;
      v39.x = (float)((float)((float)v28 - (float)v23) * (float)v33) + (float)v23;
      idWinding::AddPoint(this: v44, v: &v39);
      v34 = (float)((float)v32 - (float)v31);
      v39.z = (float)((float)v34 * (float)v33) + (float)v31;
      v39.y = (float)((float)((float)v27 - (float)v25) * (float)v33) + (float)v25;
      v39.x = (float)((float)((float)v28 - (float)v30) * (float)v33) + (float)v30;
      idWinding::AddPoint(this: v44, v: &v39);
      idWinding::AddPoint(this: v44, v: &v40);
      v35 = gameLocal->GetRenderWorld(this: gameLocal);
      v35->DebugFilledPolygon(this: v35, a2: (const idVec4 *)&idColor::colorGreen, a3: v44, a4: 0, a5: false);
      v43.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
      memset(&v43.numPoints, 0, 12);
      v40.z = (float)((float)((float)v26 - (float)v24) * (float)v33) + (float)v24;
      v40.y = (float)((float)((float)v27 - (float)v25) * (float)v33) + (float)v25;
      v40.x = (float)((float)((float)v28 - (float)v23) * (float)v33) + (float)v23;
      idWinding::AddPoint(this: &v43, v: &v40);
      idWinding::AddPoint(this: &v43, v: &v41);
      idWinding::AddPoint(this: &v43, v: v42);
      v42[0].z = (float)((float)v34 * (float)v33) + (float)v31;
      v42[0].y = (float)((float)((float)v27 - (float)v25) * (float)v33) + (float)v25;
      v42[0].x = (float)((float)((float)v28 - (float)v30) * (float)v33) + (float)v30;
      idWinding::AddPoint(this: &v43, v: v42);
      v36 = gameLocal->GetRenderWorld(this: gameLocal);
      v36->DebugFilledPolygon(this: v36, a2: (const idVec4 *)&idColor::colorRed, a3: &v43, a4: 0, a5: false);
      v43.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
      idMem::Free(this: &mem, ptr: v43.p, align: ALIGN_16);
      v43.p = nullptr;
      v44[0].__vftable = (idWinding_vtbl *)&idWinding::`vftable';
      idMem::Free(this: &mem, ptr: v44[0].p, align: ALIGN_16);
      v44[0].p = nullptr;
    }
    if ( bot_trackPlayer.valueInteger != 0 )
      idBotAimState::AddAimRequestEntity(
        this: this->aimState,
        entity: DebugPlayer,
        priority: AIM_PRIORITY_DEBUG_OVERRIDE,
        userName: "bot_trackPlayer",
        aimPoint: AIMPOINT_BEST,
        aimTimeInSeconds: -1.0);
  }
}


// ========================================================================
// __unwind$490336
// EA  : 0x82B3F174
// RVA : 0x00B3F174
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_490336()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$490337
// EA  : 0x82B3F19C
// RVA : 0x00B3F19C
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_490337()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 416 + 176));
}


// ========================================================================
// ?UpdateBotDebugHud@idBot@@IBAXAAVidGuiListBox@@@Z
// EA  : 0x82B3F1D0
// RVA : 0x00B3F1D0
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::UpdateBotDebugHud(idBot *this, idGuiListBox *infoList)
{
  int value; // r10
  idEntity *v5; // r3
  idPlayer *v6; // r30
  int v7; // r11
  char v8; // r11
  bool v9; // zf
  idLobbyBase *v10; // r29
  idPresentable *presentable; // r3
  lobbyUserID_t *v12; // r4
  idLobbyBase_vtbl *v13; // r28
  lobbyUserID_t *LobbyUserID; // r3
  const char *data; // r4
  idPhysics *Physics; // r29
  idPhysics *v17; // r28
  idRenderWorld *v18; // r27
  idPhysics *v19; // r3
  int v20; // r20
  idRenderWorld_vtbl *v21; // r30
  int v22; // r29
  int v23; // r3
  idGuiListBox *v24; // r3
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  idGuiListBox *v28; // r3
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  char *v32; // r30
  idGuiListBox *v33; // r3
  __int64 v34; // r10
  __int64 v35; // r8
  __int64 v36; // r6
  idGuiListBox *v37; // r3
  __int64 v38; // r6
  __int64 v39; // r10
  __int64 v40; // r8
  idGuiListBox *v41; // r3
  __int64 v42; // r10
  __int64 v43; // r8
  __int64 v44; // r6
  idGuiListBox *v45; // r3
  __int64 v46; // r10
  __int64 v47; // r8
  __int64 v48; // r6
  int v49; // r7
  idEntity *v50; // r3
  idPlayer *v51; // r30
  int v52; // r11
  char v53; // r11
  idLobbyBase *v54; // r29
  idPresentable *v55; // r3
  lobbyUserID_t *v56; // r4
  idLobbyBase_vtbl *v57; // r30
  lobbyUserID_t *v58; // r3
  const char *v59; // r4
  char *v60; // r30
  idGuiListBox *v61; // r3
  __int64 v62; // r10
  __int64 v63; // r8
  __int64 v64; // r6
  idGuiListBox *v65; // r3
  __int64 v66; // r6
  __int64 v67; // r10
  __int64 v68; // r8
  int flags; // r30
  idGuiListBox *v70; // r3
  __int64 v71; // r10
  __int64 v72; // r8
  __int64 v73; // r6
  idGuiListBox *v74; // r3
  __int64 v75; // r10
  __int64 v76; // r6
  __int64 v77; // r8
  double combatMaxRange; // fp31
  idGuiListBox *v79; // r3
  __int64 v80; // r8
  __int64 v81; // r10
  __int64 v82; // r6
  idGuiListBox *v83; // r3
  __int64 v84; // r6
  __int64 v85; // r8
  __int64 v86; // r10
  idGuiListBox *v87; // r3
  __int64 v88; // r6
  __int64 v89; // r10
  __int64 v90; // r8
  idGuiListBox *v91; // r3
  __int64 v92; // r10
  __int64 v93; // r8
  __int64 v94; // r6
  _DWORD v95[4]; // [sp+50h] [-C0h] BYREF
  idStr v96; // [sp+60h] [-B0h] BYREF
  idStr v97; // [sp+80h] [-90h] BYREF

  value = this->goalTask.goalEnemy.spawnId.value;
  v95[0] = &this->goalTask.goalEnemy;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = (idPlayer *)idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  idStr::idStr(this: &v97, text: "<NONE>");
  if ( v6 != nullptr )
  {
    v7 = *(_DWORD *)(v6->GetType(this: v6) + 36);
    if ( v7 < idPlayer::Type.typeNum || (v9 = v7 <= idPlayer::Type.lastChild, v8 = 1, !v9) )
      v8 = 0;
    if ( v8 != 0 )
    {
      v10 = session->GetActingGameStateLobbyBase(this: session);
      presentable = idPlayer::CastTo(c: v6)->presentable;
      if ( presentable != nullptr )
        v12 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
      else
        v12 = nullptr;
      v13 = v10->__vftable;
      LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v95, result: v12);
      data = v13->GetLobbyUserName(
               this: (idLobbyBase *)LobbyUserID->localUserHandle.handle,
               a2: *(lobbyUserID_t **)&LobbyUserID->lobbyType);
    }
    else
    {
      data = v6->name.data;
    }
    idStr::operator=(this: &v97, text: data);
    Physics = idEntity::GetPhysics(this: v6);
    v17 = idEntity::GetPhysics(this: v6);
    v18 = gameLocal->GetRenderWorld(this: gameLocal);
    v19 = idEntity::GetPhysics(this: v6);
    v20 = (int)v19->GetOrigin(this: v19, a2: 0);
    v21 = v18->__vftable;
    v22 = (int)Physics->GetAxis(this: Physics, a2: 0);
    v23 = (int)v17->GetBounds(this: v17, a2: -1);
    v21->DebugOrientedBounds(
      this: v18,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idBounds *)v23,
      a4: (const idVec3 *)v20,
      a5: (const idMat3 *)v22,
      a6: 0,
      a7: false);
  }
  v24 = idGuiListBox::Row(this: infoList);
  v28 = idGuiListBox::Printf(this: v24, fmt: "- ENEMY INFO -", a3: v27, a4: v26, a5: v25);
  idGuiListBox::Printf(this: v28, fmt: "--------------------------------", a3: v31, a4: v30, a5: v29);
  v32 = v97.data;
  v33 = idGuiListBox::Row(this: infoList);
  LODWORD(v34) = "ound traces";
  v37 = idGuiListBox::Printf(this: v33, fmt: "Enemy: ", a3: v36, a4: v35, a5: v34);
  HIDWORD(v38) = v32;
  idGuiListBox::Printf(this: v37, fmt: "%s", a3: v38, a4: v40, a5: v39);
  idBotWorldState::UpdateBotGUI(this: this->worldState, infoList);
  v41 = idGuiListBox::Row(this: infoList);
  HIDWORD(v42) = "Could not find AI state, idVS_ds_Car_Chase! ";
  v45 = idGuiListBox::Printf(this: v41, fmt: "- GOAL INFO -", a3: v44, a4: v43, a5: v42);
  idGuiListBox::Printf(this: v45, fmt: "--------------------------------", a3: v48, a4: v47, a5: v46);
  v49 = this->goalTask.goalEntity.spawnId.value;
  v95[0] = &this->goalTask.goalEntity;
  if ( gameLocal->spawnIds.ptr[v49 & 0x1FFF] == v49 >> 13 && (v50 = gameLocal->entities.ptr[v49 & 0x1FFF]) != nullptr )
    v51 = (idPlayer *)idEntity::CastTo(c: v50);
  else
    v51 = nullptr;
  idStr::idStr(this: &v96, text: "<NONE>");
  if ( v51 != nullptr )
  {
    v52 = *(_DWORD *)(v51->GetType(this: v51) + 36);
    if ( v52 < idPlayer::Type.typeNum || (v9 = v52 <= idPlayer::Type.lastChild, v53 = 1, !v9) )
      v53 = 0;
    if ( v53 != 0 )
    {
      v54 = session->GetActingGameStateLobbyBase(this: session);
      v55 = idPlayer::CastTo(c: v51)->presentable;
      if ( v55 != nullptr )
        v56 = (lobbyUserID_t *)v55->GetPlayerInterface_2(this: v55);
      else
        v56 = nullptr;
      v57 = v54->__vftable;
      v58 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v95, result: v56);
      v59 = v57->GetLobbyUserName(
              this: (idLobbyBase *)v58->localUserHandle.handle,
              a2: *(lobbyUserID_t **)&v58->lobbyType);
    }
    else
    {
      v59 = v51->name.data;
    }
    idStr::operator=(this: &v96, text: v59);
  }
  v60 = v96.data;
  v61 = idGuiListBox::Row(this: infoList);
  v65 = idGuiListBox::Printf(this: v61, fmt: "Goal Entity: ", a3: v64, a4: v63, a5: v62);
  HIDWORD(v66) = v60;
  idGuiListBox::Printf(this: v65, fmt: "%s", a3: v66, a4: v68, a5: v67);
  flags = this->goalTask.goalType.flags;
  v70 = idGuiListBox::Row(this: infoList);
  LODWORD(v71) = "Could not find AI state, idVS_ds_Car_Chase! ";
  v74 = idGuiListBox::Printf(this: v70, fmt: "Goal Type: ", a3: v73, a4: v72, a5: v71);
  HIDWORD(v75) = 0x82000000;
  HIDWORD(v76) = flags;
  idGuiListBox::Printf(this: v74, fmt: "%d", a3: v76, a4: v77, a5: v75);
  combatMaxRange = this->goalTask.goalCombatSettings.combatMaxRange;
  v79 = idGuiListBox::Row(this: infoList);
  LODWORD(v80) = "Could not find AI state, idVS_ds_Car_Chase! ";
  v83 = idGuiListBox::Printf(this: v79, fmt: "Goal Combat Range: ", a3: v82, a4: v80, a5: v81);
  HIDWORD(v84) = LODWORD(combatMaxRange);
  HIDWORD(v85) = &unk_821D0000;
  idGuiListBox::Printf(this: v83, fmt: "%.1f", a3: v84, a4: v85, a5: v86, combatMaxRange);
  v87 = idGuiListBox::Row(this: infoList);
  LODWORD(v88) = "Could not find AI state, idVS_ds_Car_Chase! ";
  v91 = idGuiListBox::Printf(this: v87, fmt: "- MOVE INFO -", a3: v88, a4: v90, a5: v89);
  idGuiListBox::Printf(this: v91, fmt: "--------------------------------", a3: v94, a4: v93, a5: v92);
  idBotMoveState::UpdateBotGUI(this: this->moveState, infoList);
  idStr::FreeData(this: &v96);
  idStr::FreeData(this: &v97);
}


// ========================================================================
// __unwind$490868_0
// EA  : 0x82B3F644
// RVA : 0x00B3F644
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_490868_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$490869_0
// EA  : 0x82B3F66C
// RVA : 0x00B3F66C
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_490869_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// ?UpdateBotGUI@idBot@@QBAXAAVidGuiListBox@@W4botDebugGuiType_t@@@Z
// EA  : 0x82B3F6F8
// RVA : 0x00B3F6F8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::UpdateBotGUI(idBot *this, idGuiListBox *infoList, unsigned int debugType)
{
  if ( debugType != 0 )
  {
    if ( debugType == 1 )
    {
      idBotWorldState::RenderWorldInfo(this: this->worldState, infoList);
    }
    else if ( debugType < 3 )
    {
      this->behaviorTree->DebugRenderGui(this: this->behaviorTree, a2: this, a3: infoList, a4: 0);
    }
  }
  else
  {
    idBot::UpdateBotDebugHud(this, infoList);
  }
}


// ========================================================================
// ?UpdateUcmd@idBot@@IAAXXZ
// EA  : 0x82B3F748
// RVA : 0x00B3F748
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::UpdateUcmd(idBot *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "BotThink_UpdateUcmd");
  LODWORD(v2) = "BotThink_UpdateUcmd";
  HIDWORD(v2) = 1024;
  idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
  if ( !this->owner->IsDead(this: this->owner) )
  {
    idBot::HandleViewCmds(this);
    idBotMoveState::UpdateMoveCmds(this: this->moveState, cmd: &this->usercmd);
  }
  idPLogScope::~idPLogScope(this: v4);
  RD_EventEnd();
}


// ========================================================================
// __unwind$491183
// EA  : 0x82B3F7CC
// RVA : 0x00B3F7CC
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491183()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$491184
// EA  : 0x82B3F7F4
// RVA : 0x00B3F7F4
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491184()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateBehaviorTree@idBot@@IAAXXZ
// EA  : 0x82B3F828
// RVA : 0x00B3F828
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::UpdateBehaviorTree(idBot *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int GameMs; // r3
  idPLogScope v5[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "BotThink_UpdateBehaviorTree");
  LODWORD(v2) = "BotThink_UpdateBehaviorTree";
  HIDWORD(v2) = 1024;
  idPLogScope::idPLogScope(this: v5, pl: &pLog, gMask: v2, label: v3);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idBehaviorTree::RootThink(this: this->behaviorTree, bot: this, curTime: GameMs);
  idPLogScope::~idPLogScope(this: v5);
  RD_EventEnd();
}


// ========================================================================
// __unwind$491226_0
// EA  : 0x82B3F8A0
// RVA : 0x00B3F8A0
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491226_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$491227_0
// EA  : 0x82B3F8C8
// RVA : 0x00B3F8C8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491227_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateWorldState@idBot@@IAAXXZ
// EA  : 0x82B3F8F8
// RVA : 0x00B3F8F8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::UpdateWorldState(idBot *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int value; // r9
  idEntity *v5; // r3
  int v6; // r9
  idEntity *v7; // r3
  idEntity *v8; // r4
  idPLogScope v9[6]; // [sp+50h] [-30h] BYREF

  if ( !this->owner->IsDead(this: this->owner) )
  {
    RD_EventBegin(name: "BotThink_UpdateWorldState");
    LODWORD(v2) = "BotThink_UpdateWorldState";
    HIDWORD(v2) = 1024;
    idPLogScope::idPLogScope(this: v9, pl: &pLog, gMask: v2, label: v3);
    idBotWorldState::Update(this: this->worldState);
    value = this->goalTask.goalEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idEntity::CastTo(c: v5) != nullptr )
    {
      v6 = this->goalTask.goalEnemy.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13 && (v7 = gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
        v8 = idEntity::CastTo(c: v7);
      else
        v8 = nullptr;
      this->goalTask.goalEnemyTargetRecordIndex = idBotWorldState::GetRecordIndexForEntity(
                                                    this: this->worldState,
                                                    entity: v8);
    }
    else
    {
      this->goalTask.goalEnemyTargetRecordIndex = -1;
    }
    idPLogScope::~idPLogScope(this: v9);
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$491262
// EA  : 0x82B3FA18
// RVA : 0x00B3FA18
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491262()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$491263
// EA  : 0x82B3FA40
// RVA : 0x00B3FA40
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491263()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateAimState@idBot@@IAAXXZ
// EA  : 0x82B3FA70
// RVA : 0x00B3FA70
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::UpdateAimState(idBot *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  if ( !this->owner->IsDead(this: this->owner) )
  {
    RD_EventBegin(name: "BotThink_UpdateAimState");
    LODWORD(v2) = "BotThink_UpdateAimState";
    HIDWORD(v2) = 1024;
    idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
    idBotAimState::Update(this: this->aimState);
    idPLogScope::~idPLogScope(this: v4);
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$491412
// EA  : 0x82B3FAE8
// RVA : 0x00B3FAE8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491412()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$491413
// EA  : 0x82B3FB10
// RVA : 0x00B3FB10
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491413()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateWeaponState@idBot@@IAAXXZ
// EA  : 0x82B3FB40
// RVA : 0x00B3FB40
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::UpdateWeaponState(idBot *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  if ( !this->owner->IsDead(this: this->owner) )
  {
    RD_EventBegin(name: "BotThink_UpdateWeaponState");
    LODWORD(v2) = "BotThink_UpdateWeaponState";
    HIDWORD(v2) = 1024;
    idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
    idBotWeaponState::Update(this: this->weaponState, currentAimPoint: &this->aimState->currentAimPoint);
    idBot::HACK_CHECK_ATTACK_FUNC_NEEDS_REMOVED(this);
    idPLogScope::~idPLogScope(this: v4);
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$491447_0
// EA  : 0x82B3FBC4
// RVA : 0x00B3FBC4
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491447_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$491448
// EA  : 0x82B3FBEC
// RVA : 0x00B3FBEC
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491448()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateMoveState@idBot@@IAAXXZ
// EA  : 0x82B3FC20
// RVA : 0x00B3FC20
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::UpdateMoveState(idBot *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  if ( !this->owner->IsDead(this: this->owner) )
  {
    RD_EventBegin(name: "BotThink_UpdateMoveState");
    LODWORD(v2) = "BotThink_UpdateMoveState";
    HIDWORD(v2) = 1024;
    idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
    idBotMoveState::Update(this: this->moveState);
    idPLogScope::~idPLogScope(this: v4);
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$491485
// EA  : 0x82B3FC98
// RVA : 0x00B3FC98
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491485()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$491486
// EA  : 0x82B3FCC0
// RVA : 0x00B3FCC0
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void _unwind_491486()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?Think@idBot@@QAAXXZ
// EA  : 0x82B3FCE8
// RVA : 0x00B3FCE8
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __fastcall idBot::Think(idBot *this)
{
  usercmd_t *p_usercmd; // r29
  int clientGameFrame; // r30
  int ServerGameTime; // r3
  char v5; // r9

  p_usercmd = &this->usercmd;
  clientGameFrame = this->usercmd.clientGameFrame;
  memset(Dst: &this->usercmd, Val: 0, Size: sizeof(this->usercmd));
  this->usercmd.clientGameFrame = clientGameFrame + 1;
  ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
  v5 = *((_BYTE *)&this->usercmd + 9);
  this->usercmd.serverGameTime = ServerGameTime;
  *((_BYTE *)&this->usercmd + 9) = v5 | 0x40;
  idBot::RunDebugChecks(this);
  if ( bot_pause.valueInteger == 0 && (g_stopTime.valueInteger == 0 || g_runFrames.valueInteger != 0) )
  {
    idBot::UpdateWorldState(this);
    idBot::UpdateBehaviorTree(this);
    idBot::UpdateMoveState(this);
    idBot::UpdateWeaponState(this);
    idBot::UpdateAimState(this);
    idBot::UpdateUcmd(this);
    if ( !this->owner->IsDead(this: this->owner) )
      idBotAimState::PostUpdate(this: this->aimState);
  }
  common->UpdateBotUserCmds(this: common, a2: this->owner->entityNumber, a3: p_usercmd);
}


// ========================================================================
// `dynamic initializer for 'bot_allowWeapons''
// EA  : 0x8336CA40
// RVA : 0x0136CA40
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_allowWeapons__()
{
  idCVar::idCVar(
    this: &bot_allowWeapons,
    name: "bot_allowWeapons",
    value: "1",
    flags: 1,
    description: "If false, bot won't use any weapons.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_allowWeapons__);
}


// ========================================================================
// `dynamic initializer for 'bot_pause''
// EA  : 0x8336CA98
// RVA : 0x0136CA98
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_pause__()
{
  idCVar::idCVar(
    this: &bot_pause,
    name: "bot_pause",
    value: "0",
    flags: 1,
    description: "Pause all bot thinking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_pause__);
}


// ========================================================================
// `dynamic initializer for 'bot_drawBounds''
// EA  : 0x8336CAF0
// RVA : 0x0136CAF0
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_drawBounds__()
{
  idCVar::idCVar(
    this: &bot_drawBounds,
    name: "bot_drawBounds",
    value: "0",
    flags: 1,
    description: "1 = draw bot's bounds.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_drawBounds__);
}


// ========================================================================
// `dynamic initializer for 'bot_drawHealth''
// EA  : 0x8336CB48
// RVA : 0x0136CB48
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_drawHealth__()
{
  idCVar::idCVar(
    this: &bot_drawHealth,
    name: "bot_drawHealth",
    value: "0",
    flags: 1,
    description: "1 = draw bots health as a bar over its head.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_drawHealth__);
}


// ========================================================================
// `dynamic initializer for 'bot_trackPlayer''
// EA  : 0x8336CBA0
// RVA : 0x0136CBA0
// PDB : w:\tech5\tungsten\game\bot\bot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_trackPlayer__()
{
  idCVar::idCVar(
    this: &bot_trackPlayer,
    name: "bot_trackPlayer",
    value: "0",
    flags: 1,
    description: "1 = force bot to always look at player 0.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_trackPlayer__);
}

