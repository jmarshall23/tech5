
// ========================================================================
// ?PrintLog@idAIVoiceController@@SAXXZ
// EA  : 0x82A61810
// RVA : 0x00A61810
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

static void __fastcall idAIVoiceController::PrintLog()
{
  int v0; // r11
  int v1; // r10
  int *p_entityNum; // r31
  const char *data; // r29
  char *v4; // r28
  idAI2 *v5; // r3
  idAI2 *v6; // r3
  idAI2 *v7; // r30
  int v8; // r30
  void (__fastcall **p_valueCompletion)(idAutoComplete *); // r31
  idAI2 *v10; // r3
  idAI2 *v11; // r3
  idAI2 *v12; // r27
  const char *v13; // r29
  char *v14; // r28
  void (__fastcall *v15)(idAutoComplete *); // r4
  void (__fastcall *v16)(idAutoComplete *); // r10

  v0 = idAIVoiceController::sNumLogEntries;
  if ( idAIVoiceController::sNumLogEntries >= 50 )
  {
    v1 = idAIVoiceController::sNumLogEntries % 50 + 1;
    if ( v1 < 50 )
    {
      p_entityNum = &idAIVoiceController::sLogEntries[v1].entityNum;
      do
      {
        data = "removed from map";
        v4 = "removed from map";
        v5 = (idAI2 *)gameLocal->GetEntity(this: gameLocal, a2: *p_entityNum);
        v6 = idAI2::CastTo(c: v5);
        v7 = v6;
        if ( v6 != nullptr && idAI2::GetEncounterGroup(this: v6) != nullptr )
        {
          data = v7->name.data;
          v4 = idAI2::GetEncounterGroup(this: v7)->groupName.data;
        }
        idLib::Printf(
          fmt: "[%6d] voice: %-20s ent: %4d %-50s group: %-20s\n",
          p_entityNum[1],
          voiceMsgNames[p_entityNum[2]],
          *p_entityNum,
          data,
          v4);
        p_entityNum += 3;
      }
      while ( (int)p_entityNum < (int)&idAIVoiceController::sNumLogEntries );
      v0 = idAIVoiceController::sNumLogEntries;
    }
  }
  v8 = 0;
  if ( v0 % 50 > 0 )
  {
    p_valueCompletion = &ai_showVisTrace.valueCompletion;
    do
    {
      v10 = (idAI2 *)gameLocal->GetEntity(this: gameLocal, a2: p_valueCompletion[3]);
      v11 = idAI2::CastTo(c: v10);
      v12 = v11;
      v13 = "removed from map";
      v14 = "removed from map";
      if ( v11 != nullptr && idAI2::GetEncounterGroup(this: v11) != nullptr )
      {
        v13 = v12->name.data;
        v14 = idAI2::GetEncounterGroup(this: v12)->groupName.data;
      }
      v15 = p_valueCompletion[4];
      v16 = (void (__fastcall *)(idAutoComplete *))(4 * (_DWORD)p_valueCompletion[5]);
      p_valueCompletion += 3;
      idLib::Printf(
        fmt: "[%6d] voice: %-20s ent: %4d %-50s group: %-20s\n",
        v15,
        *(const char **)((char *)voiceMsgNames + (_DWORD)v16),
        *p_valueCompletion,
        v13,
        v14);
      ++v8;
    }
    while ( v8 < idAIVoiceController::sNumLogEntries % 50 );
  }
}


// ========================================================================
// ??0idAIVoiceController@@QAA@W4voiceController_t@@@Z
// EA  : 0x82A619D8
// RVA : 0x00A619D8
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

idAIVoiceController *__fastcall idAIVoiceController::idAIVoiceController(
        idAIVoiceController *this,
        voiceController_t controllerType_)
{
  aiVoicePriority_t *p_lastVoicePriority; // r10
  int v3; // ctr

  p_lastVoicePriority = &this->lastVoicePriority;
  this->nextVoiceTime.value = 0;
  this->lastVoiceTime.value = 0;
  this->lastVoicePriority = AIVOICEPRIORITY_NONE;
  v3 = 10;
  this->controllerType = controllerType_;
  do
  {
    *++p_lastVoicePriority = AIVOICEPRIORITY_NONE;
    --v3;
  }
  while ( v3 != 0 );
  return this;
}


// ========================================================================
// ?InternalAdvanceNextPlayTime@idAIVoiceController@@QAAXW4voiceMsg_t@@PBVidVoiceInfo@@@Z
// EA  : 0x82A61A08
// RVA : 0x00A61A08
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

void __fastcall idAIVoiceController::InternalAdvanceNextPlayTime(
        idAIVoiceController *this,
        const voiceMsg_t msg,
        const idVoiceInfo *vi)
{
  int GameMs; // r28
  int RandomInterval; // r3
  __int32 v8; // r11
  int v9; // r9

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  RandomInterval = GetRandomInterval(_min: vi->interval, _max: vi->intervalMax);
  v8 = 4 * (msg + 3);
  v9 = *(int *)((char *)&this->nextVoiceTime.value + v8);
  if ( v9 <= RandomInterval + GameMs )
    *(int *)((char *)&this->nextVoiceTime.value + v8) = RandomInterval + GameMs;
  else
    *(int *)((char *)&this->nextVoiceTime.value + v8) = v9;
}


// ========================================================================
// ?VoiceInfoForMessage@idAIVoiceController@@SAPBVidVoiceInfo@@PAVidAI2@@W4voiceMsg_t@@@Z
// EA  : 0x82A61A78
// RVA : 0x00A61A78
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

const idVoiceInfo *__fastcall idAIVoiceController::VoiceInfoForMessage(idAI2 *ai, const voiceMsg_t msg)
{
  const idDeclAIBehaviorVO *declBehaviorVo; // r11
  const idVoiceInfo *result; // r3

  declBehaviorVo = ai->aiEditable.behaviors.declBehaviorVo;
  if ( declBehaviorVo == nullptr )
    return nullptr;
  switch ( msg )
  {
    case AIVOICE_SEARCH_START_FROM_COMBAT:
      result = &declBehaviorVo->search.startFromCombat;
      break;
    case AIVOICE_COMBAT_CHANGE_POSITION:
      result = &declBehaviorVo->combat.changePosition;
      break;
    case AIVOICE_COMBAT_FIRST_SPOT:
      result = &declBehaviorVo->combat.firstSpot;
      break;
    case AIVOICE_COMBAT_RESPOT:
      result = &declBehaviorVo->combat.reSpot;
      break;
    case AIVOICE_COMBAT_FLANK_SPOT:
      result = &declBehaviorVo->combat.flankSpot;
      break;
    case AIVOICE_COMBAT_DOWNED:
      result = &declBehaviorVo->combat.downed;
      break;
    case AIVOICE_COMBAT_LOSING_BATTLE:
      result = &declBehaviorVo->combat.losingBattle;
      break;
    case AIVOICE_COMBAT_RELOAD:
      result = &declBehaviorVo->combat.reload;
      break;
    case AIVOICE_COMBAT_FIGHT_MOTIVATION:
      result = &declBehaviorVo->combat.fightMotivation;
      break;
    case AIVOICE_COMBAT_FIGHT_MOTIVATION_RESPONSE:
      result = &declBehaviorVo->combat.fightMotivationResponse;
      break;
    default:
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?GetControllerForVoice@idAIVoiceController@@QAAPAV1@PAVidAI2@@W4voiceMsg_t@@@Z
// EA  : 0x82A61B28
// RVA : 0x00A61B28
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

idAIVoiceController *__fastcall idAIVoiceController::GetControllerForVoice(
        idAIVoiceController *this,
        idAI2 *ai,
        voiceMsg_t msg)
{
  idAIVoiceController *v4; // r10
  const idVoiceInfo *v5; // r3
  const idVoiceInfo *v6; // r31
  voiceController_t controller; // r11
  idAIVoiceController *result; // r3
  idEncounterGroup *EncounterGroup; // r3
  const idDeclVoiceOver *voiceOver; // r11

  v5 = idAIVoiceController::VoiceInfoForMessage(ai, msg);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  controller = v5->controller;
  result = v4;
  if ( controller == VC_GROUP )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    if ( EncounterGroup == nullptr )
    {
      voiceOver = v6->voiceOver;
      if ( voiceOver != nullptr )
      {
        idLib::Warning(
          fmt: "AI '%s' tried to play voice over '%s' marked as VC_GROUP, but the AI has no group! ALL AI must be grouped to work correctly!",
          ai->name.data,
          voiceOver->name.str);
        return nullptr;
      }
      if ( v6->shader != nullptr )
        idLib::Warning(
          fmt: "AI '%s' tried to play sound shader '%s' marked as VC_GROUP, but the AI has no group! ALL AI must be groupd to work correctly!",
          ai->name.data,
          v6->shader->name.str);
      return nullptr;
    }
    return &EncounterGroup->voiceController;
  }
  else if ( controller == VC_GLOBAL )
  {
    return &gameLocal->globalVoiceController;
  }
  return result;
}


// ========================================================================
// ?AdvanceNextPlayTime@idAIVoiceController@@QAAXPAVidAI2@@W4voiceMsg_t@@@Z
// EA  : 0x82A61C08
// RVA : 0x00A61C08
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

void __fastcall idAIVoiceController::AdvanceNextPlayTime(idAIVoiceController *this, idAI2 *ai, voiceMsg_t msg)
{
  const idVoiceInfo *v4; // r30
  idAI2 *v5; // r10
  idAIVoiceController *v6; // r9
  voiceMsg_t v7; // r5
  idAIVoiceController *ControllerForVoice; // r3

  v4 = idAIVoiceController::VoiceInfoForMessage(ai, msg);
  if ( v4 != nullptr )
  {
    ControllerForVoice = idAIVoiceController::GetControllerForVoice(this: v6, ai: v5, msg: v7);
    if ( ControllerForVoice != nullptr )
      idAIVoiceController::InternalAdvanceNextPlayTime(this: ControllerForVoice, msg, vi: v4);
  }
}


// ========================================================================
// ?StartVoice@idAIVoiceController@@AAA?AW4voiceController_t@@PAVidAI2@@W4voiceMsg_t@@PBVidVoiceInfo@@@Z
// EA  : 0x82A61C78
// RVA : 0x00A61C78
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

voiceController_t __fastcall idAIVoiceController::StartVoice(
        idAIVoiceController *this,
        idAI2 *ai,
        voiceMsg_t msg,
        const idVoiceInfo *vi)
{
  int GameMs; // r3
  int v9; // r11
  char *data; // r30
  int v11; // r3
  unsigned int v13; // r4
  voiceController_t controllerType; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idDeclVoiceOver_vtbl *value; // r27
  int v17; // r27
  idWeapon *v18; // r3
  idAIFireControl *fireControl; // r31
  const idWeapon *v20; // r3
  int MaxLength; // [sp+50h] [-40h] BYREF

  if ( vi->shader == nullptr && vi->voiceOver == nullptr )
    return VC_MAX;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v9 = this->nextPlayTime[msg];
  if ( GameMs < v9 || (*((_BYTE *)vi + 25) & 0x40) != 0 && v9 != 0 )
    return VC_MAX;
  if ( ai->IsDead(this: ai) && vi->priority < AIVOICEPRIORITY_PAIN )
  {
    if ( ai_debugVoice.valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
    {
      data = ai->name.data;
      v11 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "(%d) %s - AI is dead. VO '%s' not played.", v11, data, voiceMsgNames[msg]);
    }
    return VC_MAX;
  }
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->nextVoiceTime.value
    && vi->priority <= this->lastVoicePriority )
  {
    return VC_MAX;
  }
  idAIVoiceController::AdvanceNextPlayTime(this, ai, msg);
  v13 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v13;
  if ( (int)(((v13 >> 10) & 0x7FFF) % 0x64) >= vi->playChance )
    return VC_MAX;
  this->lastVoicePriority = vi->priority;
  controllerType = this->controllerType;
  if ( vi->voiceOver != nullptr )
  {
    if ( controllerType == VC_GROUP
      || (TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai),
          idFaceMgr::StartVoiceOver(
            this: &ai->aiVolatile.faceMgr,
            owner: ai,
            ta: TreeAnimatorFromPresentable,
            vo: vi->voiceOver)) )
    {
      if ( this->controllerType == VC_GROUP )
        value = idDeclVoiceOver::GetMaxLength(
                  this: (idDeclVoiceOver *)&MaxLength,
                  result: (idTypesafeNumber<int,enum millisecondUnique_t> *)vi->voiceOver)->__vftable;
      else
        value = (idDeclVoiceOver_vtbl *)ai->aiVolatile.faceMgr.vtrackDuration.value;
      v17 = gameLocal->GetGameMsPerRealSec(this: gameLocal) * (int)value / 1000;
      this->nextVoiceTime.value = idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED)
                                + v17;
      this->lastVoiceTime.value = idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED);
      v18 = ai->GetEquippedWeapon(this: ai);
      goto LABEL_27;
    }
  }
  else if ( controllerType == VC_GROUP
         || idEntity::StartSoundShader(
              this: ai,
              channel: SND_CHANNEL_VOICE,
              shader: vi->shader,
              soundShaderFlags: 0,
              peerMask: 0xFFu) != 0 )
  {
    MaxLength = idSoundShader::GetMaxLength(this: vi->shader);
    v17 = gameLocal->GetGameMsPerRealSec(this: gameLocal) * MaxLength / 1000;
    this->nextVoiceTime.value = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                              + v17;
    this->lastVoiceTime.value = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v18 = ai->GetEquippedWeapon(this: ai);
LABEL_27:
    if ( v18 != nullptr )
    {
      if ( v17 > 500 )
        v17 = 500;
      fireControl = ai->aiVolatile.fireControl;
      v20 = ai->GetEquippedWeapon(this: ai);
      idAIFireControl::InhibitFire(this: fireControl, weapon: v20, inhibitLength: v17);
    }
    return this->controllerType;
  }
  if ( this->controllerType != VC_GROUP )
    return VC_MAX;
  return VC_GROUP;
}


// ========================================================================
// ?PlayVoiceOver@idAIVoiceController@@QAA?AW4voiceController_t@@PAVidAI2@@PBVidDeclVoiceOver@@W4aiVoicePriority_t@@_N@Z
// EA  : 0x82A61FF0
// RVA : 0x00A61FF0
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

voiceController_t __fastcall idAIVoiceController::PlayVoiceOver(
        idAIVoiceController *this,
        idAI2 *ai,
        const idDeclVoiceOver *vo,
        aiVoicePriority_t priority,
        const bool samePriorityInterupts)
{
  aiVoicePriority_t lastVoicePriority; // r11
  const char *str; // r30
  char *data; // r31
  int GameMs; // r4
  const char *v15; // r30
  char *v16; // r31
  int v17; // r4
  const char *v18; // r30
  char *v19; // r31
  int v20; // r4
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *v22; // r30
  char *v23; // r31
  int v24; // r4
  int voiceTrackIndex; // r11
  const idVoiceTrack *v26; // r10
  int value; // r27
  int v28; // r29
  int v29; // r3
  int v30; // r31
  int RandomInterval; // r3

  idEventReceiver::CancelEvents(this: ai, ev: &EV_StopSound);
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->nextVoiceTime.value )
  {
    lastVoicePriority = this->lastVoicePriority;
    if ( samePriorityInterupts )
    {
      if ( priority < lastVoicePriority )
      {
        if ( ai_debugVoice.valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
        {
          str = vo->name.str;
          data = ai->name.data;
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idLib::Printf(fmt: "(%d) %s - Same priority voice already playing. VO '%s' not played.", GameMs, data, str);
        }
        return VC_MAX;
      }
    }
    else if ( priority <= lastVoicePriority )
    {
      if ( ai_debugVoice.valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
      {
        v15 = vo->name.str;
        v16 = ai->name.data;
        v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idLib::Printf(fmt: "(%d) %s - Higher priority voice already playing. VO '%s' not played.", v17, v16, v15);
      }
      return VC_MAX;
    }
  }
  if ( ai->IsDead(this: ai) && priority < AIVOICEPRIORITY_PAIN )
  {
    if ( ai_debugVoice.valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
    {
      v18 = vo->name.str;
      v19 = ai->name.data;
      v20 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "(%d) %s - AI is dead. VO '%s' not played.", v20, v19, v18);
    }
    return VC_MAX;
  }
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai);
  if ( !idFaceMgr::StartVoiceOver(this: &ai->aiVolatile.faceMgr, owner: ai, ta: TreeAnimatorFromPresentable, vo) )
  {
    if ( ai_debugVoice.valueInteger != 0 && idAI2::GetDebugLevel() > 0 && vo != nullptr )
    {
      v22 = vo->name.str;
      v23 = ai->name.data;
      v24 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "(%d) %s - Face manager failed to start voice '%s'.", v24, v23, v22);
    }
    return VC_MAX;
  }
  idAI2::SetSpeakingVO(this: ai);
  if ( vo == nullptr )
    return VC_MAX;
  voiceTrackIndex = ai->aiVolatile.faceMgr.voiceTrackIndex;
  if ( voiceTrackIndex < 0 )
    return VC_MAX;
  if ( voiceTrackIndex >= vo->tracks.num )
    return VC_MAX;
  v26 = vo->tracks.list[voiceTrackIndex];
  if ( v26 == nullptr )
    return VC_MAX;
  value = v26->approximateDuration.value;
  v28 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v29 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
  this->lastVoicePriority = priority;
  this->nextVoiceTime.value = v29 * value / 1000 + v28;
  this->lastVoiceTime.value = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v30 = this->nextVoiceTime.value;
  RandomInterval = GetRandomInterval(_min: 2500, _max: 7500);
  gameLocal->nextPlayerGreetingTime = RandomInterval + v30;
  gameLocal->nextAIGreetingTime = RandomInterval + v30 + 5000;
  return this->controllerType;
}


// ========================================================================
// ?PlayVoice@idAIVoiceController@@QAA?AW4voiceController_t@@PAVidAI2@@W4voiceMsg_t@@@Z
// EA  : 0x82A622D8
// RVA : 0x00A622D8
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

voiceController_t __fastcall idAIVoiceController::PlayVoice(idAIVoiceController *this, idAI2 *ai, voiceMsg_t msg)
{
  const idVoiceInfo *v6; // r28
  idAIVoiceController *ControllerForVoice; // r3
  idAIVoiceController *v8; // r29
  idEncounterGroup *EncounterGroup; // r3

  if ( ai == nullptr )
    return VC_MAX;
  if ( idAI2::ActionScriptFlagIsSet(this: ai, flags: 8) )
    return VC_MAX;
  v6 = idAIVoiceController::VoiceInfoForMessage(ai, msg);
  if ( v6 == nullptr )
    return VC_MAX;
  ControllerForVoice = idAIVoiceController::GetControllerForVoice(this, ai, msg);
  v8 = ControllerForVoice;
  if ( ControllerForVoice == nullptr )
  {
    idLib::Warning(fmt: "AI '%s' has no voice control for voice msg %d.", ai->name.data, msg);
    return VC_MAX;
  }
  if ( ControllerForVoice->controllerType == VC_GROUP )
  {
    if ( (*((_BYTE *)v6 + 25) & 0x80) != 0 )
    {
      EncounterGroup = idAI2::GetEncounterGroup(this: ai);
      if ( EncounterGroup == nullptr || idEncounterGroup::NumLivingMembers(this: EncounterGroup) < 2 )
        return VC_MAX;
    }
    if ( idAIVoiceController::StartVoice(this: v8, ai, msg, vi: v6) == VC_MAX )
      return VC_MAX;
  }
  return idAIVoiceController::StartVoice(this: &ai->aiVolatile.voiceController, ai, msg, vi: v6);
}


// ========================================================================
// ?FadeVoiceOver@idAIVoiceController@@QAAXPAVidAI2@@@Z
// EA  : 0x82A623D8
// RVA : 0x00A623D8
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

void __fastcall idAIVoiceController::FadeVoiceOver(idAIVoiceController *this, idAI2 *ai)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int value; // r8
  idPlayer *v6; // r3
  idPlayer *v7; // r3
  _BYTE v8[20]; // [sp+70h] [-C0h] BYREF
  int v9; // [sp+90h] [-A0h]
  float v10; // [sp+94h] [-9Ch]
  int v11; // [sp+B0h] [-80h]
  int v12; // [sp+B4h] [-7Ch]
  const idEventArg *v13; // [sp+B8h] [-78h]
  const idEventArg *v14; // [sp+BCh] [-74h]
  int v15[5]; // [sp+D0h] [-60h] BYREF

  idGameLocal::ResetSpecifiedInteractAi(this: gameLocal, ai);
  HIBYTE(v15[0]) = 102;
  v10 = -60.0;
  HIBYTE(v9) = 102;
  HIBYTE(v11) = 105;
  v12 = 1;
  v15[1] = SLODWORD(ai_voFadeTime.valueFloat);
  memcpy(Dst: v8, Src: v15, Size: sizeof(v8));
  idEventReceiver::PostEventMS(
    this: ai,
    ev: &EV_FadeSound,
    time: v11,
    arg1: v13,
    arg2: v14,
    arg3: (const idEventArg *)__ROL4__(v9, 32));
  HIBYTE(v11) = 105;
  HIBYTE(v15[0]) = 105;
  v15[1] = 1;
  v12 = 0;
  idEventReceiver::PostEventMS(
    this: ai,
    ev: &EV_StopSound,
    time: v15[0],
    arg1: (const idEventArg *)v15[2],
    arg2: (const idEventArg *)v15[3]);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai);
  idFaceMgr::Reset(this: &ai->aiVolatile.faceMgr, owner: ai, ta: TreeAnimatorFromPresentable);
  this->nextVoiceTime.value = 0;
  this->lastVoiceTime.value = 0;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
    idGameLocal::StoppedVoiceOver(this: gameLocal, whoStartedMe: ai, target: v7);
  }
  else
  {
    idGameLocal::StoppedVoiceOver(this: gameLocal, whoStartedMe: ai, target: nullptr);
  }
}


// ========================================================================
// ?StopVoiceOver@idAIVoiceController@@QAAXPAVidAI2@@@Z
// EA  : 0x82A62568
// RVA : 0x00A62568
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

void __fastcall idAIVoiceController::StopVoiceOver(idAIVoiceController *this, idAI2 *ai)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idEntity *v5; // r5
  int value; // r9
  idGameLocal *v7; // r11
  idPlayer *v8; // r3
  idPlayer *v9; // r3

  idEntity::StopSound(this: ai, channel: SND_CHANNEL_VOICE, peerMask: 0xFFu);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai);
  idFaceMgr::Reset(this: &ai->aiVolatile.faceMgr, owner: ai, ta: TreeAnimatorFromPresentable);
  v5 = nullptr;
  this->nextVoiceTime.value = 0;
  this->lastVoiceTime.value = 0;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  v7 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr )
    {
      v9 = idPlayer::CastTo(c: v8);
      v7 = gameLocal;
      v5 = v9;
    }
  }
  idGameLocal::StoppedVoiceOver(this: v7, whoStartedMe: ai, target: v5);
}


// ========================================================================
// `dynamic initializer for 'ai_voFadeTime''
// EA  : 0x83367CA8
// RVA : 0x01367CA8
// PDB : w:\tech5\tungsten\game\ai\aivoicecontroller.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_voFadeTime__()
{
  idCVar::idCVar(
    this: &ai_voFadeTime,
    name: "ai_voFadeTime",
    value: "1.5",
    flags: 4,
    description: "time in seconds VO will fade when walking away from a conversation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_voFadeTime__);
}

