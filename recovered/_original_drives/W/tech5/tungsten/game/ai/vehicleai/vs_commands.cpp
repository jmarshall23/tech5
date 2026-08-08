
// ========================================================================
// ?InternalExitState@idVS_cs_Travel@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E198
// RVA : 0x00B1E198
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_Travel::InternalExitState(
        idVS_cs_Travel *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI::SetEnemy(this: this->ai, enemy: nullptr);
}


// ========================================================================
// ?InternalWork@idVS_cs_ChangeState@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E1A8
// RVA : 0x00B1E1A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_ChangeState::InternalWork(
        idVS_cs_ChangeState *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r3
  int decision; // r4
  vehicleAiSetup_t::commands_t *v6; // r30
  int attack; // r4

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  decision = CurrentCommand->changeState.decision;
  v6 = CurrentCommand;
  if ( decision != 2 )
    idVehicleAI::SetDecisionState(this: this->ai, num: decision, delayTime: 0, pushState: false);
  attack = v6->changeState.attack;
  if ( attack != 30 )
    idVehicleAI::SetAttackState(this: this->ai, num: attack, delayTime: 0, pushState: false);
}


// ========================================================================
// ?InternalEnterState@idVS_cs_NextCommand@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E220
// RVA : 0x00B1E220
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_NextCommand::InternalEnterState(
        idVS_cs_NextCommand *this,
        idVehicleFSM *baseFSM,
        const int curTime)
{
  idVehicleFSM *v4; // r30
  idVehicleAI *ai; // r3
  int v6; // r11
  vehicleAiSetup_t::commands_t *CurrentCommand; // r3
  vehicleAiSetup_t::cmdName_t type; // r11
  vehicleAiSetup_t::commands_t *v9; // r29
  idState *State; // r3
  idVehicleAI *v11; // r10

  v4 = idVehicleFSM::CastTo(c: baseFSM);
  ai = this->ai;
  v6 = this->mCurrentCommand + 1;
  this->mCurrentCommand = v6;
  if ( v6 >= ai->setup.commands.num )
  {
    this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_Idle::Type);
  }
  else
  {
    CurrentCommand = idVehicleAI::GetCurrentCommand(this: ai);
    type = CurrentCommand->type;
    v9 = CurrentCommand;
    if ( CurrentCommand->type == CMD_OCCUPANTS )
    {
      this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_Occupants::Type);
    }
    else
    {
      switch ( type )
      {
        case CMD_TRAVEL:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_Travel::Type);
          break;
        case CMD_WAIT_FOR_TRIGGER:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_WaitForTrigger::Type);
          break;
        case CMD_TO_TRIGGER:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_ToTrigger::Type);
          break;
        case CMD_PAUSE_STATE:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_PauseState::Type);
          break;
        case CMD_CHANGE_STATE:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_ChangeState::Type);
          break;
        case CMD_WAIT:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_WaitForTime::Type);
          break;
        case CMD_WAIT_FOR_SOUND:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_WaitForSound::Type);
          break;
        case CMD_WAIT_FOR_VOICEOVER:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_WaitForVoiceOver::Type);
          break;
        case CMD_ENTER_VEHICLE:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_EnterVehicle::Type);
          break;
        case CMD_EXIT_VEHICLE:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_ExitVehicle::Type);
          break;
        case CMD_UNLOCK_OCCUPANTS:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_UnlockOccupants::Type);
          break;
        case CMD_POWER_SLIDE:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_PowerSlide::Type);
          break;
        case CMD_WAIT_TIL_DEAD:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_WaitTilDead::Type);
          break;
        case CMD_WAIT_FOR_PLAYER:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_CS_WaitForPlayer::Type);
          break;
        case CMD_TRAVEL_TIL_DEAD:
          this->mNextState = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_TravelTilDead::Type);
          break;
        case CMD_TRIGGER_ACTION:
          State = idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_NextCommand::Type);
          v11 = this->ai;
          this->mNextState = State;
          v11->triggerAction = v9->triggerAction;
          break;
        default:
          break;
      }
    }
  }
}


// ========================================================================
// ?InternalWork@idVS_cs_NextCommand@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E4F0
// RVA : 0x00B1E4F0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_NextCommand::InternalWork(idVS_cs_NextCommand *this, idVehicleFSM *baseFSM, const int curTime)
{
  idVehicleFSM *v4; // r3

  v4 = idVehicleFSM::CastTo(c: baseFSM);
  if ( this->mNextState == idFiniteStateMachine::FindState(this: v4, stateType: &idVS_cs_NextCommand::Type) )
    this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
  this->ai->commandsFSM.SetState_2(this: &this->ai->commandsFSM, a2: this->mNextState, a3: 0, a4: false);
}


// ========================================================================
// ?InternalEnterState@idVS_cs_Occupants@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E588
// RVA : 0x00B1E588
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_Occupants::InternalEnterState(
        idVS_cs_Occupants *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r11
  idState *curState; // r29
  idNavPathPosTracker *SplineTracker; // r3
  vehicleAiSetup_t::commands_t *CurrentCommand; // r3
  double v8; // fp31

  ai = this->ai;
  curState = ai->movementFSM.curState;
  if ( curState == idFiniteStateMachine::FindState(this: &ai->movementFSM, stateType: &idVS_Idle::Type) )
  {
    this->ai->movementFSM.SetState_3(
      this: &this->ai->movementFSM,
      a2: &idVS_ms_MoveToGoalOnSpline::Type,
      a3: 0,
      a4: false);
    SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
    idVehicleAI::MoveToPosition(
      this: (idVehicleAI *)LODWORD(SplineTracker->pathPosition.distance),
      pathPos: (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.rightDistance),
      isStoppingGoal: __ROL4__(SplineTracker->pathPosition.navSpline, 32),
      passThroughGoal: 1u,
      a5: false);
  }
  idVehicleAI::SetSpeedLimit(this: this->ai, speed: 0.0);
  idVehicleBaseFSM::PushState(this: &this->ai->movementFSM, stateType: &idVS_Idle::Type, delayTime: 0);
  this->ai->desiredSteering = 0.0;
  this->ai->desiredBraking = 2;
  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  if ( CurrentCommand->occupants.num > 0 )
  {
    v8 = __fabs((float)(CurrentCommand->occupants.list->delayTime * (float)1000.0));
    this->nextVOTime = (int)(float)((float)(gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) | 0x6400000000uLL)
                                  + (float)v8);
  }
}


// ========================================================================
// ?InternalExitState@idVS_cs_Occupants@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E6C8
// RVA : 0x00B1E6C8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_Occupants::InternalExitState(
        idVS_cs_Occupants *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleBaseFSM::PopState(this: &this->ai->movementFSM, setPoppedState: true);
}


// ========================================================================
// ?InternalWork@idVS_cs_WaitForTrigger@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E6D8
// RVA : 0x00B1E6D8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_WaitForTrigger::InternalWork(
        idVS_cs_WaitForTrigger *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r3

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  if ( CurrentCommand->trigger.triggerTime > -1 )
  {
    CurrentCommand->trigger.triggerTime = -1;
    this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
  }
}


// ========================================================================
// ?InternalEnterState@idVS_cs_WaitForTime@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E748
// RVA : 0x00B1E748
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_WaitForTime::InternalEnterState(
        idVS_cs_WaitForTime *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  double v4; // fp31

  v4 = __fabs((float)(idVehicleAI::GetCurrentCommand(this: this->ai)->wait.time * (float)1000.0));
  this->endTime = (int)(float)((float)(gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) | 0x6400000000uLL)
                             + (float)v4);
}


// ========================================================================
// ?InternalWork@idVS_cs_WaitForTime@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E7D8
// RVA : 0x00B1E7D8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_WaitForTime::InternalWork(
        idVS_cs_WaitForTime *this,
        idFiniteStateMachine *baseFSM,
        int curTime)
{
  if ( ((int (__fastcall *)(idGameLocal *, int, int))gameLocal->GetGameMs)(a1: gameLocal, a2: 1, a3: curTime) >= this->endTime )
    this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalWork@idVS_cs_PauseState@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E850
// RVA : 0x00B1E850
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_PauseState::InternalWork(
        idVS_cs_PauseState *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  this->ai->runDecisionFSM = idVehicleAI::GetCurrentCommand(this: this->ai)->pauseState.decision;
}


// ========================================================================
// ?InternalWork@idVS_cs_PowerSlide@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E8A0
// RVA : 0x00B1E8A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_PowerSlide::InternalWork(
        idVS_cs_PowerSlide *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  __int64 v4; // r6
  idVehicleAI *ai; // r11

  LODWORD(v4) = 90 * idVehicleAI::GetCurrentCommand(this: this->ai)->powerSlide.wheelDir;
  this->ai->desiredSteering = (float)v4;
  this->ai->desiredSpeed = 0.0;
  this->ai->desiredBraking = 1;
  ai = this->ai;
  if ( ai->actualSpeed < 1.0 )
    ai->commandsFSM.SetState_3(this: &ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalWork@idVS_cs_WaitTilDead@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1E950
// RVA : 0x00B1E950
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_WaitTilDead::InternalWork(
        idVS_cs_WaitTilDead *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r30
  int v5; // r29
  int v6; // r31
  idGameLocal *v7; // r10
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  int v11; // r3

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  v5 = 0;
  if ( CurrentCommand->waitTilDead.deadList.num > 0 )
  {
    v6 = 0;
    v7 = gameLocal;
    do
    {
      value = CurrentCommand->waitTilDead.deadList.list[v6].spawnId.value;
      if ( v7->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v9 = v7->entities.ptr[value & 0x1FFF];
        if ( v9 != nullptr )
        {
          v10 = idEntity::CastTo(c: v9);
          if ( v10 != nullptr )
          {
            v11 = (int)v10->GetHealthComponent_2(this: v10);
            if ( v11 != 0 && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v11 + 88))(a1: v11) == 0 )
              break;
          }
          v7 = gameLocal;
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < CurrentCommand->waitTilDead.deadList.num );
  }
  if ( v5 == CurrentCommand->waitTilDead.deadList.num )
    this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalWork@idVS_cs_Occupants@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1EA58
// RVA : 0x00B1EA58
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_Occupants::InternalWork(
        idVS_cs_Occupants *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  idVehicle_Car *v6; // r24
  vehicleAiSetup_t::commands_t *CurrentCommand; // r3
  int num; // r11
  vehicleAiSetup_t::commands_t *v9; // r23
  int v10; // r29
  unsigned int v11; // r11
  idVehicle_Car *VehicleCar; // r3
  idVehicleOccupant *OccupantVisual; // r3
  idVehicleOccupant *v14; // r31
  double v15; // fp31
  __int64 v16; // r7
  idVehicleAI *ai; // r3
  idVehicle_Car *v18; // r3
  vehicleAiSetup_t::commands_t::occupants_t *list; // r9
  int v20; // r11
  int v21; // r25
  int v22; // r28
  int v23; // r30
  int v24; // r9
  idEntity *v25; // r3
  idEntity *v26; // r31
  int v27; // r26
  int v28; // r27
  int v29; // r31
  idEntity *OccupantAsEntity; // r3
  int v31; // r11
  char v32; // r11
  bool v33; // zf
  int v34; // r10
  int v35; // r7
  int v36; // r9
  int v37; // ctr
  int i; // r31
  __int64 v39; // [sp+50h] [-70h] BYREF

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return;
  v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v5 == nullptr )
    return;
  v6 = idVehicle_Car::CastTo(c: v5);
  if ( v6 == nullptr )
    return;
  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  num = CurrentCommand->occupants.num;
  v9 = CurrentCommand;
  v10 = 0;
  if ( num == 0 )
  {
    v11 = idVehicle::GetNumActiveOccupants(this: v6) - 1;
LABEL_52:
    if ( (_cntlzw(v11) & 0x20) != 0 )
    {
      for ( i = 0; i < v9->occupants.num; ++v10 )
      {
        if ( v9->occupants.list[v10].lockInSeat && i < v6->seatInfo.num )
        {
          idVehicle::AllowOccupantExitVehicle(this: v6, seat: i + 1, bl: false);
          idVehicle::AllowOccupantSwapSeats(this: v6, seat: i + 1, bl: false);
        }
        ++i;
      }
      this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
    }
    return;
  }
  if ( num > 0 && CurrentCommand->occupants.list->voiceOver != nullptr )
  {
    VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
    if ( VehicleCar != nullptr )
    {
      OccupantVisual = idVehicle::GetOccupantVisual(this: VehicleCar, index: 0);
      v14 = OccupantVisual;
      if ( OccupantVisual != nullptr && !idVehicleOccupant::IsVoiceOverPlaying(this: OccupantVisual) )
      {
        if ( this->nextVOTime >= 0 )
        {
          if ( this->nextVOTime < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
          {
            ai = this->ai;
            this->nextVOTime = -1;
            v18 = idVehicleAI::GetVehicleCar(this: ai);
            list = v9->occupants.list;
            HIDWORD(v39) = v18->voiceOverNameString.index;
            idVehicleOccupant::PlayVoiceOver(this: v14, vo: list->voiceOver, whoStartedMeTextId: (idStrId *)&v39);
          }
        }
        else
        {
          v15 = __fabs((float)(v9->occupants.list->repeatDelayTime * (float)1000.0));
          LODWORD(v16) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          v39 = v16;
          this->nextVOTime = (int)(float)((float)v16 + (float)v15);
        }
      }
    }
  }
  v20 = v9->occupants.num;
  v21 = 0;
  HIDWORD(v39) = 0x1000000;
  BYTE4(v39) = 0;
  if ( v20 <= 0 )
  {
LABEL_31:
    v27 = 0;
    if ( v20 <= 0 )
    {
LABEL_46:
      v34 = v6->seatInfo.num;
      v35 = 0;
      v36 = 1;
      if ( v34 > 1 )
      {
        v37 = v34 - 1;
        do
        {
          if ( *((_BYTE *)&v39 + v36) != 0 )
            ++v35;
          ++v36;
          --v37;
        }
        while ( v37 != 0 );
      }
      v11 = v20 - v35;
      goto LABEL_52;
    }
    v28 = 0;
    while ( 1 )
    {
      if ( v9->occupants.list[v28].waitForPlayer )
      {
        v29 = 1;
        if ( v6->seatInfo.num > 1 )
        {
          while ( 1 )
          {
            if ( *((_BYTE *)&v39 + v29) == 0 && idVehicle::GetOccupantAsEntity(this: v6, index: v29) != nullptr )
            {
              OccupantAsEntity = idVehicle::GetOccupantAsEntity(this: v6, index: v29);
              v31 = *(_DWORD *)(OccupantAsEntity->GetType(this: OccupantAsEntity) + 36);
              if ( v31 < idPlayer::Type.typeNum || (v33 = v31 <= idPlayer::Type.lastChild, v32 = 1, !v33) )
                v32 = 0;
              if ( v32 != 0 )
                break;
            }
            if ( ++v29 >= v6->seatInfo.num )
              goto LABEL_44;
          }
          *((_BYTE *)&v39 + v29) = 1;
        }
LABEL_44:
        if ( v29 == v6->seatInfo.num )
          break;
      }
      v20 = v9->occupants.num;
      ++v27;
      ++v28;
      if ( v27 >= v20 )
        goto LABEL_46;
    }
  }
  else
  {
    v22 = 0;
    while ( 1 )
    {
      if ( !v9->occupants.list[v22].waitForPlayer )
      {
        v23 = 1;
        if ( v6->seatInfo.num > 1 )
        {
          while ( 1 )
          {
            if ( *((_BYTE *)&v39 + v23) == 0 && idVehicle::GetOccupantAsEntity(this: v6, index: v23) != nullptr )
            {
              v24 = v9->occupants.list[v22].entity.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13
                && (v25 = gameLocal->entities.ptr[v24 & 0x1FFF]) != nullptr )
              {
                v26 = idEntity::CastTo(c: v25);
              }
              else
              {
                v26 = nullptr;
              }
              if ( idVehicle::GetOccupantAsEntity(this: v6, index: v23) == v26 )
                break;
            }
            if ( ++v23 >= v6->seatInfo.num )
              goto LABEL_29;
          }
          *((_BYTE *)&v39 + v23) = 1;
        }
LABEL_29:
        if ( v23 == v6->seatInfo.num )
          break;
      }
      v20 = v9->occupants.num;
      ++v21;
      ++v22;
      if ( v21 >= v20 )
        goto LABEL_31;
    }
  }
}


// ========================================================================
// ?InternalWork@idVS_cs_Travel@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1EEC0
// RVA : 0x00B1EEC0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_Travel::InternalWork(idVS_cs_Travel *this, idFiniteStateMachine *baseFSM, const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  idVehicle *Enemy; // r3
  int v7; // r27
  idGameLocal *v8; // r10
  int v9; // r29
  idEntityPtr<idEntity> *v10; // r11
  idEntity *v11; // r3
  idEntity *v12; // r3
  idEntity *v13; // r30
  int v14; // r9
  idVehicle_Car *v15; // r3
  idVehicle_Car *v16; // r3
  idVehicleAI *ai; // r3
  char *v18; // r30

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idVehicle_Car::CastTo(c: v5) != nullptr )
    {
      if ( idVehicleAI::GetCurrentCommand(this: this->ai)->travel.shootAtEnemy )
      {
        Enemy = idVehicleAI::FindEnemy(this: this->ai);
        idVehicleAI::SetEnemy(this: this->ai, enemy: Enemy);
        if ( idVehicleAI::GetEnemy(this: this->ai) != nullptr )
          idVehicleAI::FireWeapon(this: this->ai);
      }
      v7 = 0;
      if ( this->mOccupants.num > 0 )
      {
        v8 = gameLocal;
        v9 = 0;
        do
        {
          v10 = &this->mOccupants.list[v9];
          if ( v8->spawnIds.ptr[v10->spawnId.value & 0x1FFF] == v10->spawnId.value >> 13 )
          {
            v11 = v8->entities.ptr[v10->spawnId.value & 0x1FFF];
            if ( v11 != nullptr )
            {
              v12 = idEntity::CastTo(c: v11);
              v8 = gameLocal;
              v13 = v12;
            }
            else
            {
              v13 = nullptr;
            }
            v14 = this->ai->vehicleCar.spawnId.value;
            if ( v8->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
              && (v15 = (idVehicle_Car *)v8->entities.ptr[v14 & 0x1FFF]) != nullptr )
            {
              v16 = idVehicle_Car::CastTo(c: v15);
            }
            else
            {
              v16 = nullptr;
            }
            if ( !idVehicle::IsAnOccupant(this: v16, entity: v13) )
              break;
            v8 = gameLocal;
          }
          ++v7;
          ++v9;
        }
        while ( v7 < this->mOccupants.num );
      }
      ai = this->ai;
      v18 = (char *)ai + 80 * ai->currentPatrol;
      if ( this->mWasMissingOccupant )
      {
        idVehicleAI::PopControlParams(this: ai);
        idVehicleAI::MoveToPosition(
          this: *((idVehicleAI **)v18 + 1067),
          pathPos: *((idNavSplinePosition **)v18 + 1068),
          isStoppingGoal: __ROL4__(*((_DWORD *)v18 + 1069), 32),
          passThroughGoal: this->mIsStoppingGoal,
          a5: false);
        this->mWasMissingOccupant = false;
      }
      idVehicleAI::UpdatePatrolPath(this: this->ai);
      this->mTravelGoal = idVehicleAI::GetSplineTracker(this: this->ai)->goalPathPosition;
      if ( v18[4248] != 0 )
        this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
    }
  }
}


// ========================================================================
// ?InternalWork@idVS_cs_ToTrigger@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1F108
// RVA : 0x00B1F108
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_ToTrigger::InternalWork(
        idVS_cs_ToTrigger *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r3
  vehicleAiSetup_t::commands_t *v5; // r31
  idGameLocal *v6; // r11
  idVehicleAI *ai; // r29
  int value; // r9
  idVehicle_Car *v9; // r3
  idVehicle_Car *v10; // r3
  idEntity *OccupantAsEntity; // r3
  int v12; // r9
  idEntity *v13; // r3
  idEntity *v14; // r3

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  v5 = CurrentCommand;
  v6 = gameLocal;
  if ( gameLocal->spawnIds.ptr[CurrentCommand->toTrigger.toTriggerEntity.spawnId.value & 0x1FFF] == CurrentCommand->toTrigger.toTriggerEntity.spawnId.value >> 13 )
  {
    ai = this->ai;
    if ( CurrentCommand->toTrigger.occupantToActivate >= 0 )
    {
      value = ai->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v9 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
        && (v10 = idVehicle_Car::CastTo(c: v9)) != nullptr )
      {
        OccupantAsEntity = idVehicle::GetOccupantAsEntity(this: v10, index: v5->toTrigger.occupantToActivate);
        if ( OccupantAsEntity != nullptr )
          ai = (idVehicleAI *)OccupantAsEntity;
        else
          idLib::Warning(
            fmt: "idVS_cs_ToTrigger::InternalWork could not find occupant %d",
            v5->toTrigger.occupantToActivate);
      }
      else
      {
        idLib::Warning(fmt: "idVS_cs_ToTrigger::InternalWork could not find car");
      }
      v6 = gameLocal;
    }
    v12 = v5->toTrigger.toTriggerEntity.spawnId.value;
    if ( v6->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13 && (v13 = v6->entities.ptr[v12 & 0x1FFF]) != nullptr )
    {
      v14 = idEntity::CastTo(c: v13);
      idEntity::Activate(this: v14, activator: ai);
    }
    else
    {
      idEntity::Activate(this: nullptr, activator: ai);
    }
  }
  else
  {
    idLib::Warning(fmt: "idVS_cs_ToTrigger::InternalWork had no valid trigger entity");
  }
  this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalEnterState@idVS_cs_WaitForSound@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1F268
// RVA : 0x00B1F268
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_WaitForSound::InternalEnterState(
        idVS_cs_WaitForSound *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r28
  int value; // r9
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r3
  idPlayer *v8; // r3
  idEntityPtr<idPlayer> *p_mPlayer; // r31
  idGameLocal *v10; // r3
  idPlayer *Player; // r3
  idEntityPtr<idPlayer> *v12; // r3
  const idSoundShader *sound; // r31
  idPlayer *v14; // r3

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr )
    {
      v7 = idVehicle_Car::CastTo(c: v6);
      if ( v7 != nullptr && CurrentCommand->waitForSound.sound != nullptr )
      {
        v8 = idVehicle::PlayerIsOccupant(this: v7);
        p_mPlayer = &this->mPlayer;
        if ( v8 != nullptr )
          p_mPlayer->spawnId.value = (gameLocal->spawnIds.ptr[v8->entityNumber] << 13) | v8->entityNumber;
        else
          p_mPlayer->spawnId.value = 0x1FFF;
        v10 = gameLocal;
        if ( gameLocal->spawnIds.ptr[p_mPlayer->spawnId.value & 0x1FFF] != p_mPlayer->spawnId.value >> 13 )
        {
          Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
          if ( Player != nullptr )
            p_mPlayer->spawnId.value = (gameLocal->spawnIds.ptr[Player->entityNumber] << 13) | Player->entityNumber;
          else
            p_mPlayer->spawnId.value = 0x1FFF;
          v10 = gameLocal;
        }
        if ( v10->spawnIds.ptr[p_mPlayer->spawnId.value & 0x1FFF] == p_mPlayer->spawnId.value >> 13 )
        {
          v12 = p_mPlayer;
          sound = CurrentCommand->waitForSound.sound;
          v14 = idEntityPtr<idPlayer>::operator->(this: v12);
          idEntity::StartSoundShader(
            this: v14,
            channel: SND_CHANNEL_VOICE2,
            shader: sound,
            soundShaderFlags: 8,
            peerMask: 0xFFu);
        }
      }
    }
  }
}


// ========================================================================
// ?InternalWork@idVS_cs_WaitForSound@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1F3C0
// RVA : 0x00B1F3C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_WaitForSound::InternalWork(
        idVS_cs_WaitForSound *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r3
  char v5; // r9
  bool IsPlayingSound; // r30
  int value; // r9
  idVehicle_Car *v8; // r3
  int v9; // r9
  idPlayer *v10; // r3
  idPlayer *v11; // r3

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  if ( gameLocal->spawnIds.ptr[this->mPlayer.spawnId.value & 0x1FFF] != this->mPlayer.spawnId.value >> 13
    || (v5 = 1, CurrentCommand->waitForSound.sound == nullptr) )
  {
    v5 = 0;
  }
  IsPlayingSound = v5;
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr && idVehicle_Car::CastTo(c: v8) != nullptr && IsPlayingSound )
    {
      v9 = this->mPlayer.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
        && (v10 = (idPlayer *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
      {
        v11 = idPlayer::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      IsPlayingSound = idEntity::IsPlayingSound(this: v11, channel: SND_CHANNEL_VOICE2);
    }
  }
  if ( !IsPlayingSound )
    this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalEnterState@idVS_cs_WaitForVoiceOver@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1F4F8
// RVA : 0x00B1F4F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_WaitForVoiceOver::InternalEnterState(
        idVS_cs_WaitForVoiceOver *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r29
  int value; // r9
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r3
  idVehicleOccupant *OccupantVisual; // r30
  idVehicle_Car *VehicleCar; // r3
  const idDeclVoiceOver *voiceOver; // r4
  idStrId v11; // [sp+50h] [-30h] BYREF

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr )
    {
      v7 = idVehicle_Car::CastTo(c: v6);
      if ( v7 != nullptr && CurrentCommand->waitForVoiceOver.voiceOver != nullptr )
      {
        OccupantVisual = idVehicle::GetOccupantVisual(this: v7, index: 0);
        if ( OccupantVisual != nullptr )
        {
          VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
          voiceOver = CurrentCommand->waitForVoiceOver.voiceOver;
          v11.index = VehicleCar->voiceOverNameString.index;
          idVehicleOccupant::PlayVoiceOver(this: OccupantVisual, vo: voiceOver, whoStartedMeTextId: &v11);
        }
      }
    }
  }
}


// ========================================================================
// ?InternalWork@idVS_cs_WaitForVoiceOver@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1F5B0
// RVA : 0x00B1F5B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_WaitForVoiceOver::InternalWork(
        idVS_cs_WaitForVoiceOver *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r30
  int value; // r9
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r11
  idVehicleOccupant *OccupantVisual; // r3
  bool IsVoiceOverPlaying; // r11

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idVehicle_Car::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  OccupantVisual = nullptr;
  if ( v7 == nullptr
    || (OccupantVisual = idVehicle::GetOccupantVisual(this: v7, index: 0)) == nullptr
    || !CurrentCommand->waitForVoiceOver.waitOnVoiceOver
    || (IsVoiceOverPlaying = true, CurrentCommand->waitForVoiceOver.voiceOver == nullptr) )
  {
    IsVoiceOverPlaying = false;
  }
  if ( IsVoiceOverPlaying )
    IsVoiceOverPlaying = idVehicleOccupant::IsVoiceOverPlaying(this: OccupantVisual);
  if ( !IsVoiceOverPlaying )
    this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalEnterState@idVS_cs_PowerSlide@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1F6C8
// RVA : 0x00B1F6C8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_PowerSlide::InternalEnterState(
        idVS_cs_PowerSlide *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r30
  int value; // r9
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r3
  idPhysics *Physics; // r31
  _BYTE v9[8]; // [sp+50h] [-30h] BYREF
  float v10; // [sp+58h] [-28h]

  this->ai->movementFSM.SetState_3(this: &this->ai->movementFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  if ( CurrentCommand->powerSlide.impulse != 0.0 )
  {
    value = this->ai->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v7 = idVehicle_Car::CastTo(c: v6);
    }
    else
    {
      v7 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: v7);
    Physics->GetAngularVelocity(this: (idPhysics *)v9, result: (idVec3 *)Physics, a3: 0);
    v10 = CurrentCommand->powerSlide.impulse + v10;
    Physics->SetAngularVelocity(this: Physics, a2: (const idVec3 *)v9, a3: 0);
  }
}


// ========================================================================
// ?InternalWork@idVS_CS_WaitForPlayer@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1F7E0
// RVA : 0x00B1F7E0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_CS_WaitForPlayer::InternalWork(
        idVS_CS_WaitForPlayer *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r27
  int value; // r9
  idGameLocal *v6; // r11
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r3
  idEntity *v9; // r31
  bool v10; // r28
  idPlayer *DebugPlayer; // r30
  idPhysics *Physics; // r31
  idPhysics *v13; // r30
  float *v14; // r31
  float *v15; // r3
  double v16; // fp8
  double v17; // fp4

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  value = this->ai->vehicleCar.spawnId.value;
  v6 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idVehicle_Car::CastTo(c: v7);
    v6 = gameLocal;
    v9 = v8;
  }
  else
  {
    v9 = nullptr;
  }
  v10 = true;
  if ( v9 != nullptr )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: v6);
    if ( DebugPlayer != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v9);
      v13 = idEntity::GetPhysics(this: DebugPlayer);
      v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v15 = (float *)v13->GetOrigin(this: v13, a2: 0);
      v16 = (float)(v14[1] - v15[1]);
      v17 = (float)(v14[2] - v15[2]);
      v10 = (float)((float)((float)v17 * (float)v17)
                  + (float)((float)((float)(*v14 - *v15) * (float)(*v14 - *v15)) + (float)((float)v16 * (float)v16))) <= (double)(float)(CurrentCommand->waitForPlayer.distance * CurrentCommand->waitForPlayer.distance);
    }
  }
  if ( v10 )
    this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalWork@idVS_cs_TravelTilDead@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1F940
// RVA : 0x00B1F940
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_TravelTilDead::InternalWork(
        idVS_cs_TravelTilDead *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r26
  int value; // r9
  idVehicle_Car *v6; // r3
  int v7; // r28
  idGameLocal *v8; // r10
  int v9; // r29
  idEntityPtr<idEntity> *v10; // r11
  idEntity *v11; // r3
  idEntity *v12; // r3
  idEntity *v13; // r31
  int v14; // r9
  idVehicle_Car *v15; // r3
  idVehicle_Car *v16; // r3
  idVehicleAI *ai; // r3
  char *v18; // r31
  int v19; // r29
  idGameLocal *v20; // r10
  int v21; // r31
  int v22; // r9
  idEntity *v23; // r3
  idEntity *v24; // r3
  int v25; // r3

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr && idVehicle_Car::CastTo(c: v6) != nullptr )
    {
      v7 = 0;
      if ( this->mOccupants.num > 0 )
      {
        v8 = gameLocal;
        v9 = 0;
        do
        {
          v10 = &this->mOccupants.list[v9];
          if ( v8->spawnIds.ptr[v10->spawnId.value & 0x1FFF] == v10->spawnId.value >> 13 )
          {
            v11 = v8->entities.ptr[v10->spawnId.value & 0x1FFF];
            if ( v11 != nullptr )
            {
              v12 = idEntity::CastTo(c: v11);
              v8 = gameLocal;
              v13 = v12;
            }
            else
            {
              v13 = nullptr;
            }
            v14 = this->ai->vehicleCar.spawnId.value;
            if ( v8->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
              && (v15 = (idVehicle_Car *)v8->entities.ptr[v14 & 0x1FFF]) != nullptr )
            {
              v16 = idVehicle_Car::CastTo(c: v15);
            }
            else
            {
              v16 = nullptr;
            }
            if ( !idVehicle::IsAnOccupant(this: v16, entity: v13) )
              break;
            v8 = gameLocal;
          }
          ++v7;
          ++v9;
        }
        while ( v7 < this->mOccupants.num );
      }
      ai = this->ai;
      v18 = (char *)ai + 80 * ai->currentPatrol;
      if ( this->mWasMissingOccupant )
      {
        idVehicleAI::PopControlParams(this: ai);
        idVehicleAI::MoveToPosition(
          this: *((idVehicleAI **)v18 + 1067),
          pathPos: *((idNavSplinePosition **)v18 + 1068),
          isStoppingGoal: __ROL4__(*((_DWORD *)v18 + 1069), 32),
          passThroughGoal: this->mIsStoppingGoal,
          a5: false);
        this->mWasMissingOccupant = false;
      }
      idVehicleAI::UpdatePatrolPath(this: this->ai);
      v19 = 0;
      this->mTravelGoal = idVehicleAI::GetSplineTracker(this: this->ai)->goalPathPosition;
      if ( CurrentCommand->travelTilDead.deadList.num > 0 )
      {
        v20 = gameLocal;
        v21 = 0;
        do
        {
          v22 = CurrentCommand->travelTilDead.deadList.list[v21].spawnId.value;
          if ( v20->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13 )
          {
            v23 = v20->entities.ptr[v22 & 0x1FFF];
            if ( v23 != nullptr )
            {
              v24 = idEntity::CastTo(c: v23);
              if ( v24 != nullptr )
              {
                v25 = (int)v24->GetHealthComponent_2(this: v24);
                if ( v25 != 0 && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v25 + 88))(a1: v25) == 0 )
                  break;
              }
              v20 = gameLocal;
            }
          }
          ++v19;
          ++v21;
        }
        while ( v19 < CurrentCommand->travelTilDead.deadList.num );
      }
      if ( v19 == CurrentCommand->travelTilDead.deadList.num )
        this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
    }
  }
}


// ========================================================================
// ?InternalWork@idVS_cs_EnterVehicle@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1FBF8
// RVA : 0x00B1FBF8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_EnterVehicle::InternalWork(
        idVS_cs_EnterVehicle *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  int v6; // r9
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r4
  vehicleAiSetup_t::commands_t *CurrentCommand; // r3
  vehicleAiSetup_t::commands_t *v10; // r31
  idEntity *v11; // r3
  idEntity *v12; // r3
  int v13; // r11
  char v14; // r11
  bool v15; // zf
  int v16; // r9
  idEntity *v17; // r3
  idVehicle_Car *v18; // r4
  idVehicleAI *ai; // r3
  idNavSplinePath *Entity; // r3
  idEntity *v21; // r3
  idEntity *v22; // r3

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idVehicle_Car::CastTo(c: v5) != nullptr )
    {
      v6 = this->ai->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
        && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
      {
        v8 = idVehicle_Car::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      idVehicleAI::UseVehicle(this: this->ai, entity: v8, seat: SEAT_MAX);
    }
  }
  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  v10 = CurrentCommand;
  if ( gameLocal->spawnIds.ptr[CurrentCommand->enterVehicle.vehicle.spawnId.value & 0x1FFF] == CurrentCommand->enterVehicle.vehicle.spawnId.value >> 13 )
  {
    v11 = gameLocal->entities.ptr[CurrentCommand->enterVehicle.vehicle.spawnId.value & 0x1FFF];
    if ( v11 != nullptr )
      v12 = idEntity::CastTo(c: v11);
    else
      v12 = nullptr;
    v13 = *(_DWORD *)(v12->GetType(this: v12) + 36);
    if ( v13 < idVehicle::Type.typeNum || (v15 = v13 <= idVehicle::Type.lastChild, v14 = 1, !v15) )
      v14 = 0;
    if ( v14 != 0 )
    {
      v16 = v10->enterVehicle.vehicle.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13 )
      {
        v17 = gameLocal->entities.ptr[v16 & 0x1FFF];
        if ( v17 != nullptr )
        {
          v18 = (idVehicle_Car *)idEntity::CastTo(c: v17);
          if ( v18 != nullptr )
          {
            idVehicleAI::UseVehicle(this: this->ai, entity: v18, seat: v10->enterVehicle.seat);
            ai = this->ai;
            if ( gameLocal->spawnIds.ptr[ai->setup.initialPath.spawnId.value & 0x1FFF] == ai->setup.initialPath.spawnId.value >> 13
              && idVehicleAI::GetSplineTracker(this: ai) != nullptr )
            {
              Entity = idEntityPtr<idNavSplinePath>::GetEntity(this: &this->ai->setup.initialPath);
              idVehicleAI::UseSplinePath(this: this->ai, pathName: Entity->name.data);
            }
          }
        }
      }
    }
  }
  else if ( gameLocal->spawnIds.ptr[CurrentCommand->enterVehicle.entitysVehicle.spawnId.value & 0x1FFF] == CurrentCommand->enterVehicle.entitysVehicle.spawnId.value >> 13 )
  {
    v21 = gameLocal->entities.ptr[CurrentCommand->enterVehicle.entitysVehicle.spawnId.value & 0x1FFF];
    if ( v21 != nullptr )
    {
      v22 = idEntity::CastTo(c: v21);
      idClass::IsType(this: v22, superclass: &idPlayerStart::Type);
    }
    else
    {
      idClass::IsType(this: nullptr, superclass: &idPlayerStart::Type);
    }
  }
  this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalWork@idVS_cs_ExitVehicle@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1FEA0
// RVA : 0x00B1FEA0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_ExitVehicle::InternalWork(
        idVS_cs_ExitVehicle *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::commands_t *CurrentCommand; // r27
  int value; // r9
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r28
  int i; // r31
  int v9; // r9
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r3
  int OccupantNum; // r3
  idAI2 *OccupantNPC; // r3
  idAI2 *v14; // r31
  int v15; // r11
  int v16; // r9
  idInfoPath *v17; // r3
  idInfoPath *v18; // r4
  idEntity *v19; // r3
  idEntity *v20; // r3

  CurrentCommand = idVehicleAI::GetCurrentCommand(this: this->ai);
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr )
    {
      v7 = idVehicle_Car::CastTo(c: v6);
      if ( v7 != nullptr )
      {
        if ( CurrentCommand->exitVehicle.unlockOccupants )
        {
          for ( i = 0; ; ++i )
          {
            v9 = this->ai->vehicleCar.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
              && (v10 = (idVehicle_Car *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
            {
              v11 = idVehicle_Car::CastTo(c: v10);
            }
            else
            {
              v11 = nullptr;
            }
            if ( i >= idVehicle::GetNumActiveOccupants(this: v11) )
              break;
            idVehicle::AllowOccupantExitVehicle(this: v7, seat: i, bl: true);
            idVehicle::AllowOccupantSwapSeats(this: v7, seat: i, bl: true);
          }
        }
        OccupantNum = idVehicle::GetOccupantNum(this: v7, entity: this->ai);
        OccupantNPC = idVehicle::GetOccupantNPC(this: v7, index: OccupantNum);
        v14 = OccupantNPC;
        v15 = CurrentCommand->exitVehicle.infoPath.spawnId.value & 0x1FFF;
        v16 = CurrentCommand->exitVehicle.infoPath.spawnId.value >> 13;
        if ( gameLocal->spawnIds.ptr[v15] == v16 && OccupantNPC != nullptr )
        {
          if ( gameLocal->spawnIds.ptr[v15] == v16 && (v17 = (idInfoPath *)gameLocal->entities.ptr[v15]) != nullptr )
            v18 = idInfoPath::CastTo(c: v17);
          else
            v18 = nullptr;
          idAIMemory::SetCurrentPath(this: &v14->aiVolatile.memory, path: v18);
          idEntity::ForceDormancy(this: v14, dormant: false, durationMS: 60000);
        }
        idVehicleAI::UseVehicle(this: this->ai, entity: v7, seat: SEAT_MAX);
        if ( gameLocal->spawnIds.ptr[CurrentCommand->exitVehicle.triggerEntityExit.spawnId.value & 0x1FFF] == CurrentCommand->exitVehicle.triggerEntityExit.spawnId.value >> 13 )
        {
          v19 = gameLocal->entities.ptr[CurrentCommand->exitVehicle.triggerEntityExit.spawnId.value & 0x1FFF];
          if ( v19 != nullptr )
            v20 = idEntity::CastTo(c: v19);
          else
            v20 = nullptr;
          idEntity::Activate(this: v20, activator: this->ai);
        }
        if ( CurrentCommand->exitVehicle.removeVehicleWhenEmpty )
        {
          idEventReceiver::PostEventMS(this: v7, ev: &EV_Remove, time: 0);
          idEventReceiver::PostEventMS(this: this->ai, ev: &EV_Remove, time: 0);
        }
      }
    }
  }
  this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalWork@idVS_cs_UnlockOccupants@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20110
// RVA : 0x00B20110
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_UnlockOccupants::InternalWork(
        idVS_cs_UnlockOccupants *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  idVehicle_Car *v6; // r28
  int i; // r31
  int v8; // r9
  idVehicle_Car *v9; // r3
  idVehicle_Car *v10; // r3

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr )
    {
      v6 = idVehicle_Car::CastTo(c: v5);
      if ( v6 != nullptr )
      {
        for ( i = 0; ; ++i )
        {
          v8 = this->ai->vehicleCar.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13
            && (v9 = (idVehicle_Car *)gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
          {
            v10 = idVehicle_Car::CastTo(c: v9);
          }
          else
          {
            v10 = nullptr;
          }
          if ( i >= idVehicle::GetNumActiveOccupants(this: v10) )
            break;
          idVehicle::AllowOccupantExitVehicle(this: v6, seat: i, bl: true);
        }
      }
    }
  }
  this->ai->commandsFSM.SetState_3(this: &this->ai->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
}


// ========================================================================
// ?InternalEnterState@idVS_cs_Travel@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20210
// RVA : 0x00B20210
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_Travel::InternalEnterState(
        idVS_cs_Travel *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  idVehicleAI *ai; // r3
  vehicleAiSetup_t::patrol_t *patrolPaths; // r20
  idList<idSplineWaypoint *,5> *p_waypoints; // r26
  vehicleAiSetup_t::commands_t *CurrentCommand; // r24
  int v10; // r9
  idSplineWaypoint *v11; // r3
  idSplineWaypoint *v12; // r3
  idSplineWaypoint *v13; // r28
  idSplineWaypoint *i; // r25
  char v15; // r27
  int v16; // r29
  int v17; // r30
  int v18; // r9
  idEntity *v19; // r3
  idEntity *v20; // r31
  int v21; // r9
  idSplineWaypoint *v22; // r3
  idSplineWaypoint *v23; // r3
  int num; // r10
  idSplineWaypoint **list; // r11
  double normalSpeed; // fp0
  idVehicleAI *v27; // r11
  idState *curState; // r31
  idList<idEntityPtr<idEntity>,5> *p_mOccupants; // r30
  int v30; // r28
  int v31; // r9
  idVehicle_Car *v32; // r3
  idVehicle_Car *v33; // r3
  int v34; // r9
  idVehicle_Car *v35; // r3
  idVehicle_Car *v36; // r29
  int v37; // r11
  int size; // r10
  idEntityPtr<idEntity> *v39; // r31
  idEntity *OccupantAsEntity; // r3
  idSplineWaypoint *v41; // [sp+50h] [-80h] BYREF

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idVehicle_Car::CastTo(c: v5) != nullptr )
    {
      ai = this->ai;
      patrolPaths = ai->patrolPaths;
      p_waypoints = &ai->patrolPaths[0].waypoints;
      CurrentCommand = idVehicleAI::GetCurrentCommand(this: ai);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&patrolPaths->waypoints);
      v10 = CurrentCommand->travel.waypoint.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
        && (v11 = (idSplineWaypoint *)gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
      {
        v12 = idSplineWaypoint::CastTo(c: v11);
      }
      else
      {
        v12 = nullptr;
      }
      v13 = v12;
      v41 = v12;
      for ( i = nullptr; v13 != nullptr; i = v13 )
      {
        v15 = 0;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&patrolPaths->waypoints,
          obj: (const encounterGroupRole_t *)&v41);
        v16 = 0;
        if ( v13->targets.num > 0 )
        {
          v17 = 0;
          while ( 1 )
          {
            v18 = v13->targets.list[v17].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v18 & 0x1FFF] == v18 >> 13
              && (v19 = gameLocal->entities.ptr[v18 & 0x1FFF]) != nullptr )
            {
              v20 = idEntity::CastTo(c: v19);
            }
            else
            {
              v20 = nullptr;
            }
            if ( (unsigned __int8)idSplineWaypoint::IsTypeOf(c: v20) != 0 )
              break;
            ++v16;
            ++v17;
            if ( v16 >= v13->targets.num )
              goto LABEL_19;
          }
          v13 = (idSplineWaypoint *)v20;
          v41 = (idSplineWaypoint *)v20;
          v15 = 1;
        }
LABEL_19:
        if ( v15 == 0 )
          break;
        v21 = CurrentCommand->travel.waypoint.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v21 & 0x1FFF] == v21 >> 13
          && (v22 = (idSplineWaypoint *)gameLocal->entities.ptr[v21 & 0x1FFF]) != nullptr )
        {
          v23 = idSplineWaypoint::CastTo(c: v22);
        }
        else
        {
          v23 = nullptr;
        }
        if ( v13 == v23 )
          break;
      }
      num = patrolPaths->waypoints.num;
      if ( num != 0 )
      {
        list = p_waypoints->list;
        if ( i == p_waypoints->list[num - 1] )
        {
          patrolPaths->pathType = PATROL_CYCLICAL;
          patrolPaths->iterations = 1;
        }
        else if ( i == *list )
        {
          patrolPaths->pathType = PATROL_CYCLICAL;
          patrolPaths->iterations = -1;
        }
        else if ( num > 1 && i == list[num - 2] )
        {
          patrolPaths->pathType = PATROL_REBOUND;
        }
        patrolPaths->iterations = CurrentCommand->travel.iterations;
        normalSpeed = CurrentCommand->travel.normalSpeed;
        this->mTravelSpeed = CurrentCommand->travel.normalSpeed;
        CurrentCommand->travel.goalSpeed = normalSpeed;
        patrolPaths->pathComplete = false;
        patrolPaths->speed = normalSpeed;
        patrolPaths->iterationCount = 0;
        patrolPaths->nextWaypointDist = CurrentCommand->travel.nextWaypointDist;
        this->ai->currentPatrol = 0;
        if ( patrolPaths->pathType == PATROL_REBOUND )
        {
          patrolPaths->curPatrolPoint = 1;
          patrolPaths->curPatrolDir = -1;
        }
        else
        {
          patrolPaths->curPatrolPoint = -1;
          patrolPaths->curPatrolDir = 1;
        }
        patrolPaths->delayTime = 1;
        patrolPaths->iterationCount = 0;
        patrolPaths->maxRightDistance = CurrentCommand->travel.maxRightFrac;
        v27 = this->ai;
        curState = v27->movementFSM.curState;
        if ( curState == idFiniteStateMachine::FindState(this: &v27->movementFSM, stateType: &idVS_Idle::Type) )
          this->ai->movementFSM.SetState_3(
            this: &this->ai->movementFSM,
            a2: &idVS_ms_MoveToGoalOnSpline::Type,
            a3: 0,
            a4: false);
        p_mOccupants = &this->mOccupants;
        if ( this->mOccupants.listStatic == 0 || this->mOccupants.listStatic == 2 )
        {
          if ( p_mOccupants->list != nullptr )
            idMem::Free(this: &mem, ptr: p_mOccupants->list, align: ALIGN_16);
          p_mOccupants->list = nullptr;
          this->mOccupants.size = 0;
        }
        v30 = 0;
        this->mOccupants.num = 0;
        while ( 1 )
        {
          v31 = this->ai->vehicleCar.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v31 & 0x1FFF] == v31 >> 13
            && (v32 = (idVehicle_Car *)gameLocal->entities.ptr[v31 & 0x1FFF]) != nullptr )
          {
            v33 = idVehicle_Car::CastTo(c: v32);
          }
          else
          {
            v33 = nullptr;
          }
          if ( v30 >= idVehicle::GetNumActiveOccupants(this: v33) )
            break;
          v34 = this->ai->vehicleCar.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v34 & 0x1FFF] == v34 >> 13
            && (v35 = (idVehicle_Car *)gameLocal->entities.ptr[v34 & 0x1FFF]) != nullptr )
          {
            v36 = idVehicle_Car::CastTo(c: v35);
          }
          else
          {
            v36 = nullptr;
          }
          idList<idEntityPtr<idInfoGarageBay>,5>::PreAllocateWithGranularity(
            this: (idList<idEntityPtr<idAI2>,5> *)&this->mOccupants,
            newSize: this->mOccupants.num + 1);
          v37 = this->mOccupants.num;
          size = this->mOccupants.size;
          if ( v37 >= size )
          {
            v39 = &p_mOccupants->list[size - 1];
          }
          else
          {
            v39 = &p_mOccupants->list[v37];
            this->mOccupants.num = v37 + 1;
          }
          OccupantAsEntity = idVehicle::GetOccupantAsEntity(this: v36, index: v30);
          if ( OccupantAsEntity != nullptr )
          {
            ++v30;
            v39->spawnId.value = (gameLocal->spawnIds.ptr[OccupantAsEntity->entityNumber] << 13)
                               | OccupantAsEntity->entityNumber;
          }
          else
          {
            v39->spawnId.value = 0x1FFF;
            ++v30;
          }
        }
        idVehicleAI::SetSpeedLimit(this: this->ai, speed: patrolPaths->speed);
      }
    }
  }
}


// ========================================================================
// ?InternalEnterState@idVS_cs_TravelTilDead@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B206A0
// RVA : 0x00B206A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.cpp
// ========================================================================

void __fastcall idVS_cs_TravelTilDead::InternalEnterState(
        idVS_cs_TravelTilDead *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  idVehicleAI *ai; // r3
  vehicleAiSetup_t::patrol_t *patrolPaths; // r20
  idList<idSplineWaypoint *,5> *p_waypoints; // r26
  vehicleAiSetup_t::commands_t *CurrentCommand; // r24
  int v10; // r9
  idSplineWaypoint *v11; // r3
  idSplineWaypoint *v12; // r3
  idSplineWaypoint *v13; // r28
  idSplineWaypoint *i; // r25
  char v15; // r27
  int v16; // r29
  int v17; // r30
  int v18; // r9
  idEntity *v19; // r3
  idEntity *v20; // r31
  int v21; // r9
  idSplineWaypoint *v22; // r3
  idSplineWaypoint *v23; // r3
  int num; // r10
  idSplineWaypoint **list; // r11
  double normalSpeed; // fp0
  idVehicleAI *v27; // r11
  idState *curState; // r31
  idList<idEntityPtr<idEntity>,5> *p_mOccupants; // r30
  int v30; // r28
  int v31; // r9
  idVehicle_Car *v32; // r3
  idVehicle_Car *v33; // r3
  int v34; // r9
  idVehicle_Car *v35; // r3
  idVehicle_Car *v36; // r29
  int v37; // r11
  int size; // r10
  idEntityPtr<idEntity> *v39; // r31
  idEntity *OccupantAsEntity; // r3
  idSplineWaypoint *v41; // [sp+50h] [-80h] BYREF

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idVehicle_Car::CastTo(c: v5) != nullptr )
    {
      ai = this->ai;
      patrolPaths = ai->patrolPaths;
      p_waypoints = &ai->patrolPaths[0].waypoints;
      CurrentCommand = idVehicleAI::GetCurrentCommand(this: ai);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&patrolPaths->waypoints);
      v10 = CurrentCommand->travelTilDead.waypoint.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
        && (v11 = (idSplineWaypoint *)gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
      {
        v12 = idSplineWaypoint::CastTo(c: v11);
      }
      else
      {
        v12 = nullptr;
      }
      v13 = v12;
      v41 = v12;
      for ( i = nullptr; v13 != nullptr; i = v13 )
      {
        v15 = 0;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&patrolPaths->waypoints,
          obj: (const encounterGroupRole_t *)&v41);
        v16 = 0;
        if ( v13->targets.num > 0 )
        {
          v17 = 0;
          while ( 1 )
          {
            v18 = v13->targets.list[v17].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v18 & 0x1FFF] == v18 >> 13
              && (v19 = gameLocal->entities.ptr[v18 & 0x1FFF]) != nullptr )
            {
              v20 = idEntity::CastTo(c: v19);
            }
            else
            {
              v20 = nullptr;
            }
            if ( (unsigned __int8)idSplineWaypoint::IsTypeOf(c: v20) != 0 )
              break;
            ++v16;
            ++v17;
            if ( v16 >= v13->targets.num )
              goto LABEL_19;
          }
          v13 = (idSplineWaypoint *)v20;
          v41 = (idSplineWaypoint *)v20;
          v15 = 1;
        }
LABEL_19:
        if ( v15 == 0 )
          break;
        v21 = CurrentCommand->travelTilDead.waypoint.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v21 & 0x1FFF] == v21 >> 13
          && (v22 = (idSplineWaypoint *)gameLocal->entities.ptr[v21 & 0x1FFF]) != nullptr )
        {
          v23 = idSplineWaypoint::CastTo(c: v22);
        }
        else
        {
          v23 = nullptr;
        }
        if ( v13 == v23 )
          break;
      }
      num = patrolPaths->waypoints.num;
      if ( num != 0 )
      {
        list = p_waypoints->list;
        if ( i == p_waypoints->list[num - 1] )
        {
          patrolPaths->pathType = PATROL_CYCLICAL;
          patrolPaths->iterations = 1;
        }
        else if ( i == *list )
        {
          patrolPaths->pathType = PATROL_CYCLICAL;
          patrolPaths->iterations = -1;
        }
        else if ( num > 1 && i == list[num - 2] )
        {
          patrolPaths->pathType = PATROL_REBOUND;
        }
        patrolPaths->iterations = -1;
        normalSpeed = CurrentCommand->travelTilDead.normalSpeed;
        this->mTravelSpeed = CurrentCommand->travelTilDead.normalSpeed;
        CurrentCommand->travelTilDead.goalSpeed = normalSpeed;
        patrolPaths->pathComplete = false;
        patrolPaths->speed = normalSpeed;
        patrolPaths->iterationCount = 0;
        this->ai->currentPatrol = 0;
        if ( patrolPaths->pathType == PATROL_REBOUND )
        {
          patrolPaths->curPatrolPoint = 1;
          patrolPaths->curPatrolDir = -1;
        }
        else
        {
          patrolPaths->curPatrolPoint = -1;
          patrolPaths->curPatrolDir = 1;
        }
        patrolPaths->delayTime = 1;
        patrolPaths->iterationCount = 0;
        patrolPaths->maxRightDistance = CurrentCommand->travel.maxRightFrac;
        v27 = this->ai;
        curState = v27->movementFSM.curState;
        if ( curState == idFiniteStateMachine::FindState(this: &v27->movementFSM, stateType: &idVS_Idle::Type) )
          this->ai->movementFSM.SetState_3(
            this: &this->ai->movementFSM,
            a2: &idVS_ms_MoveToGoalOnSpline::Type,
            a3: 0,
            a4: false);
        p_mOccupants = &this->mOccupants;
        if ( this->mOccupants.listStatic == 0 || this->mOccupants.listStatic == 2 )
        {
          if ( p_mOccupants->list != nullptr )
            idMem::Free(this: &mem, ptr: p_mOccupants->list, align: ALIGN_16);
          p_mOccupants->list = nullptr;
          this->mOccupants.size = 0;
        }
        v30 = 0;
        this->mOccupants.num = 0;
        while ( 1 )
        {
          v31 = this->ai->vehicleCar.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v31 & 0x1FFF] == v31 >> 13
            && (v32 = (idVehicle_Car *)gameLocal->entities.ptr[v31 & 0x1FFF]) != nullptr )
          {
            v33 = idVehicle_Car::CastTo(c: v32);
          }
          else
          {
            v33 = nullptr;
          }
          if ( v30 >= idVehicle::GetNumActiveOccupants(this: v33) )
            break;
          v34 = this->ai->vehicleCar.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v34 & 0x1FFF] == v34 >> 13
            && (v35 = (idVehicle_Car *)gameLocal->entities.ptr[v34 & 0x1FFF]) != nullptr )
          {
            v36 = idVehicle_Car::CastTo(c: v35);
          }
          else
          {
            v36 = nullptr;
          }
          idList<idEntityPtr<idInfoGarageBay>,5>::PreAllocateWithGranularity(
            this: (idList<idEntityPtr<idAI2>,5> *)&this->mOccupants,
            newSize: this->mOccupants.num + 1);
          v37 = this->mOccupants.num;
          size = this->mOccupants.size;
          if ( v37 >= size )
          {
            v39 = &p_mOccupants->list[size - 1];
          }
          else
          {
            v39 = &p_mOccupants->list[v37];
            this->mOccupants.num = v37 + 1;
          }
          OccupantAsEntity = idVehicle::GetOccupantAsEntity(this: v36, index: v30);
          if ( OccupantAsEntity != nullptr )
          {
            ++v30;
            v39->spawnId.value = (gameLocal->spawnIds.ptr[OccupantAsEntity->entityNumber] << 13)
                               | OccupantAsEntity->entityNumber;
          }
          else
          {
            v39->spawnId.value = 0x1FFF;
            ++v30;
          }
        }
        idVehicleAI::SetSpeedLimit(this: this->ai, speed: patrolPaths->speed);
      }
    }
  }
}

