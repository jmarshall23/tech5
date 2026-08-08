
// ========================================================================
// ?Job_DebugPrintf@idAI2@@SAXPBDZZ
// EA  : 0x82A384A8
// RVA : 0x00A384A8
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idAI2::Job_DebugPrintf(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  __int64 v8; // [sp+78h] [+18h] BYREF
  va_list va; // [sp+78h] [+18h]
  __int64 v10; // [sp+80h] [+20h]
  __int64 v11; // [sp+88h] [+28h]
  __int64 v12; // [sp+90h] [+30h]
  __int64 v13; // [sp+98h] [+38h]
  __int64 v14; // [sp+A0h] [+40h]
  __int64 v15; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v8 = fmt;
  v10 = *(__int64 *)((char *)&a2 + 4);
  v11 = a2;
  v12 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  if ( ai_debugInteraction.valueInteger != 0 )
    idLib::VPrintf(fmt: (const char *)HIDWORD(fmt), args: va);
}


// ========================================================================
// ?Job_Approach@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA  : 0x82A38510
// RVA : 0x00A38510
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_Approach(idAI2 *this, idPlayer *playerEnt, const bool playVO)
{
  idPlayer *v5; // r30
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r29
  idJobManager *p_jobManager; // r30
  const idDeclVoiceOver *v9; // r26
  const idDeclAIPlayerInteraction *decl; // r28
  int v11; // r27
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r4
  const idDeclVoiceOver *approachVO; // r11
  const idDeclJob *interactionJob; // r4
  char *data; // r24
  idStrId *JobName; // r3
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  const idDeclVoiceOver *secondaryApproachVO; // r11
  int v24; // [sp+8h] [-B8h]
  int v25; // [sp+8h] [-B8h]
  int v26; // [sp+Ch] [-B4h]
  int v27; // [sp+Ch] [-B4h]
  int v28; // [sp+10h] [-B0h]
  int v29; // [sp+10h] [-B0h]
  int v30; // [sp+14h] [-ACh]
  int v31; // [sp+14h] [-ACh]
  char v32; // [sp+70h] [-50h] BYREF

  v5 = idPlayer::CastTo(c: playerEnt);
  if ( v5 == nullptr )
    return nullptr;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  if ( CurrentPlayerInteraction == nullptr )
    return nullptr;
  p_jobManager = &v5->jobManager;
  v9 = nullptr;
  decl = this->aiVolatile.aiPlayerInteraction.decl;
  v11 = this->aiVolatile.memory.currentPlayerInteraction;
  HIDWORD(v13) = idJobManager::GetInteractionApproachPlayed(
                   this: p_jobManager,
                   interactionDecl: decl,
                   interactionNumber: v11);
  LODWORD(v15) = this->name.data;
  if ( HIDWORD(v13) != 0 )
  {
    secondaryApproachVO = CurrentPlayerInteraction->secondaryApproachVO;
    if ( secondaryApproachVO == nullptr )
    {
      HIDWORD(v15) = "'%s': no secondary approach VO.\n";
      idAI2::Job_DebugPrintf(fmt: v15, a2: v14, a3: v13, a4: v12, a5: v24, a6: v26, a7: v28, a8: v30);
      return nullptr;
    }
    LODWORD(v12) = "ound traces";
    v9 = CurrentPlayerInteraction->secondaryApproachVO;
    HIDWORD(v15) = "'%s': playing secondary approach VO: %s.\n";
    HIDWORD(v14) = secondaryApproachVO->name.str;
    idAI2::Job_DebugPrintf(fmt: v15, a2: v14, a3: v13, a4: v12, a5: v24, a6: v26, a7: v28, a8: v30);
  }
  else
  {
    approachVO = CurrentPlayerInteraction->approachVO;
    if ( approachVO != nullptr )
    {
      LODWORD(v12) = "ound traces";
      v9 = CurrentPlayerInteraction->approachVO;
      HIDWORD(v15) = "'%s': playing approach VO: %s.\n";
      HIDWORD(v14) = approachVO->name.str;
    }
    else
    {
      HIDWORD(v15) = "'%s': no approach VO.\n";
    }
    idAI2::Job_DebugPrintf(fmt: v15, a2: v14, a3: v13, a4: v12, a5: v24, a6: v26, a7: v28, a8: v30);
    interactionJob = CurrentPlayerInteraction->interactionJob;
    if ( interactionJob != nullptr && interactionJob->giveAndCompleteOnApproach )
    {
      data = this->name.data;
      JobName = idDeclJob::GetJobName(this: (idDeclJob *)&v32, result: (idStrId *)interactionJob);
      HIDWORD(v20) = idStrId::GetLocalizedString(this: JobName);
      idAI2::Job_DebugPrintf(
        fmt: __SPAIR64__(
          "'%s': completing Job because of giveAndCompleteOnApproach %s. (well after the vo...)\n",
          (unsigned int)data),
        a2: v20,
        a3: v22,
        a4: v21,
        a5: v25,
        a6: v27,
        a7: v29,
        a8: v31);
      this->aiVolatile.memory.completeJobDecl = CurrentPlayerInteraction->interactionJob;
    }
    idJobManager::SetInteractionApproachPlayed(
      this: p_jobManager,
      interactionDecl: decl,
      interactionNumber: v11,
      played: true);
  }
  if ( v9 != nullptr && playVO )
    idGameLocal::PlayInteractVoiceOver(
      this: gameLocal,
      ai: this,
      vo: CurrentPlayerInteraction->approachVO,
      priority: AIVOICEPRIORITY_MED);
  return v9;
}


// ========================================================================
// ?Job_Offer@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA  : 0x82A386A8
// RVA : 0x00A386A8
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_Offer(idAI2 *this, idPlayer *playerEnt, const bool playVO)
{
  idPlayer *v5; // r29
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const idDeclJob *interactionJob; // r11
  const idDeclVoiceOver *jobOfferVO; // r30
  bool v13; // zf
  __int64 v14; // r4
  int v15; // [sp+8h] [-88h]
  int v16; // [sp+Ch] [-84h]
  int v17; // [sp+10h] [-80h]
  int v18; // [sp+14h] [-7Ch]

  v5 = idPlayer::CastTo(c: playerEnt);
  if ( v5 == nullptr )
    return nullptr;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  if ( CurrentPlayerInteraction == nullptr )
    return nullptr;
  interactionJob = CurrentPlayerInteraction->interactionJob;
  if ( interactionJob == nullptr )
    return nullptr;
  v13 = !playVO;
  jobOfferVO = CurrentPlayerInteraction->interactionJobVO.jobOfferVO;
  if ( !v13 )
  {
    if ( jobOfferVO != nullptr )
    {
      idGameLocal::PlayInteractVoiceOver(
        this: gameLocal,
        ai: this,
        vo: CurrentPlayerInteraction->interactionJobVO.jobOfferVO,
        priority: AIVOICEPRIORITY_MED);
      LODWORD(v7) = "ound traces";
      LODWORD(v14) = this->name.data;
      HIDWORD(v14) = "'%s': playing job offer VO.\n";
    }
    else
    {
      LODWORD(v7) = "ound traces";
      LODWORD(v14) = interactionJob->name.str;
      HIDWORD(v14) = "Job '%s' missing job offer VO.";
    }
    idAI2::Job_DebugPrintf(fmt: v14, a2: v9, a3: v8, a4: v7, a5: v15, a6: v16, a7: v17, a8: v18);
  }
  idJobManager::SetJobOfferPlayed(
    this: &v5->jobManager,
    interactionDecl: this->aiVolatile.aiPlayerInteraction.decl,
    interactionNumber: this->aiVolatile.memory.currentPlayerInteraction,
    played: true);
  return jobOfferVO;
}


// ========================================================================
// ?Job_MessageVO@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N1@Z
// EA  : 0x82A38778
// RVA : 0x00A38778
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_MessageVO(
        idAI2 *this,
        idPlayer *playerEnt,
        const bool playVO,
        const bool checkAIType)
{
  idPlayer *v7; // r27
  __int64 v9; // r8
  __int64 v10; // r6
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const aiPlayerInteraction_t *v12; // r29
  const idDeclVoiceOver *messageVO; // r26
  __int64 v14; // r10
  const idDeclAIPlayerInteraction *decl; // r28
  __int64 v16; // r4
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  idEntity *v20; // r3
  idEntity *v21; // r31
  __int64 v22; // r4
  int v23; // r31
  bool v24; // r11
  int v25; // [sp+8h] [-A8h]
  int v26; // [sp+Ch] [-A4h]
  int v27; // [sp+10h] [-A0h]
  int v28; // [sp+14h] [-9Ch]

  v7 = idPlayer::CastTo(c: playerEnt);
  if ( v7 == nullptr )
    return nullptr;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  v12 = CurrentPlayerInteraction;
  if ( CurrentPlayerInteraction == nullptr )
    return nullptr;
  messageVO = CurrentPlayerInteraction->messageVO;
  v14 = playVO | 0xEF1C00000000LL;
  decl = this->aiVolatile.aiPlayerInteraction.decl;
  if ( playVO )
  {
    if ( messageVO != nullptr )
    {
      idGameLocal::PlayInteractVoiceOver(this: gameLocal, ai: this, vo: messageVO, priority: AIVOICEPRIORITY_HIGH);
      LODWORD(v16) = this->name.data;
      HIDWORD(v16) = "'%s': playing message VO.\n";
    }
    else
    {
      LODWORD(v16) = decl->name.str;
      HIDWORD(v16) = "Interaction '%s' missing message VO.";
    }
    idAI2::Job_DebugPrintf(fmt: v16, a2: v10, a3: v9, a4: v14, a5: v25, a6: v26, a7: v27, a8: v28);
  }
  if ( v12->messageTriggerEnt.len != 0 && !v12->messageTriggerPostMessage )
  {
    v20 = gameLocal->FindEntity(this: gameLocal, a2: v12->messageTriggerEnt.data);
    v21 = v20;
    if ( v20 != nullptr )
    {
      idEntity::Activate(this: v20, activator: v7);
      HIDWORD(v19) = v21->name.data;
      HIDWORD(v22) = "Interaction '%s' triggering entity %s.";
    }
    else
    {
      HIDWORD(v19) = v12->messageTriggerEnt.data;
      HIDWORD(v22) = "Interaction '%s' could not find trigger entity %s.";
    }
    LODWORD(v22) = decl->name.str;
    idAI2::Job_DebugPrintf(fmt: v22, a2: v19, a3: v18, a4: v17, a5: v25, a6: v26, a7: v27, a8: v28);
  }
  v23 = this->aiVolatile.memory.currentPlayerInteraction;
  if ( decl->interactList.list[v23].messageExpiresInteraction )
  {
    v24 = true;
    if ( checkAIType )
      v24 = (_cntlzw((unsigned __int8)idAI2::IsMerchant(this, player: v7)) & 0x20) != 0;
    if ( v24 )
      idJobManager::SetJobOfferPlayed(
        this: &v7->jobManager,
        interactionDecl: decl,
        interactionNumber: v23,
        played: true);
  }
  return messageVO;
}


// ========================================================================
// ?Job_Complete@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA  : 0x82A38900
// RVA : 0x00A38900
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_Complete(idAI2 *this, idPlayer *playerEnt, const bool playVO)
{
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const aiPlayerInteraction_t *v10; // r31
  const idDeclVoiceOver *jobCompleteVO; // r30
  __int64 v12; // r4
  const idDeclJob *interactionJob; // r11
  int v14; // [sp+8h] [-88h]
  int v15; // [sp+Ch] [-84h]
  int v16; // [sp+10h] [-80h]
  int v17; // [sp+14h] [-7Ch]

  if ( idPlayer::CastTo(c: playerEnt) == nullptr )
    return nullptr;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  v10 = CurrentPlayerInteraction;
  if ( CurrentPlayerInteraction == nullptr )
    return nullptr;
  jobCompleteVO = CurrentPlayerInteraction->interactionJobVO.jobCompleteVO;
  if ( jobCompleteVO != nullptr )
  {
    LODWORD(v12) = this->name.data;
    HIDWORD(v12) = "'%s': playing job complete VO.\n";
  }
  else
  {
    interactionJob = CurrentPlayerInteraction->interactionJob;
    LODWORD(v6) = "ound traces";
    HIDWORD(v12) = "Job '%s' missing job complete VO.";
    LODWORD(v12) = interactionJob->name.str;
  }
  idAI2::Job_DebugPrintf(fmt: v12, a2: v8, a3: v7, a4: v6, a5: v14, a6: v15, a7: v16, a8: v17);
  this->aiVolatile.memory.completeJobDecl = v10->interactionJob;
  if ( jobCompleteVO != nullptr && playVO )
    idGameLocal::PlayInteractVoiceOver(this: gameLocal, ai: this, vo: jobCompleteVO, priority: AIVOICEPRIORITY_MED);
  return jobCompleteVO;
}


// ========================================================================
// ?Job_Failed@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA  : 0x82A389C0
// RVA : 0x00A389C0
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_Failed(idAI2 *this, idPlayer *playerEnt, const bool playVO)
{
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const idDeclVoiceOver *jobFailVO; // r30
  __int64 v11; // r4
  const idDeclJob *interactionJob; // r11
  int v13; // [sp+8h] [-88h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+10h] [-80h]
  int v16; // [sp+14h] [-7Ch]

  if ( idPlayer::CastTo(c: playerEnt) == nullptr )
    return nullptr;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  if ( CurrentPlayerInteraction == nullptr )
    return nullptr;
  jobFailVO = CurrentPlayerInteraction->interactionJobVO.jobFailVO;
  if ( jobFailVO == nullptr )
  {
    interactionJob = CurrentPlayerInteraction->interactionJob;
    LODWORD(v6) = "ound traces";
    HIDWORD(v11) = "Job '%s' missing job failed VO.";
    LODWORD(v11) = interactionJob->name.str;
    goto LABEL_8;
  }
  if ( playVO )
  {
    idGameLocal::PlayInteractVoiceOver(
      this: gameLocal,
      ai: this,
      vo: CurrentPlayerInteraction->interactionJobVO.jobFailVO,
      priority: AIVOICEPRIORITY_MED);
    LODWORD(v6) = "ound traces";
    LODWORD(v11) = this->name.data;
    HIDWORD(v11) = "'%s': playing job failed VO.\n";
LABEL_8:
    idAI2::Job_DebugPrintf(fmt: v11, a2: v8, a3: v7, a4: v6, a5: v13, a6: v14, a7: v15, a8: v16);
  }
  idAI2::PlayerInteractionDone(this, playerLeft: false);
  return jobFailVO;
}


// ========================================================================
// ?Job_InProgress@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA  : 0x82A38A70
// RVA : 0x00A38A70
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_InProgress(idAI2 *this, idPlayer *playerEnt, const bool playVO)
{
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r4
  int v10; // r31
  int v11; // r11
  __int64 v12; // r10
  __int64 v13; // r4
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r4
  int v17; // [sp+8h] [-88h]
  int v18; // [sp+Ch] [-84h]
  int v19; // [sp+10h] [-80h]
  int v20; // [sp+14h] [-7Ch]

  if ( idPlayer::CastTo(c: playerEnt) == nullptr )
    return nullptr;
  HIDWORD(v9) = idAI2::GetCurrentPlayerInteraction(this);
  if ( HIDWORD(v9) == 0 )
    return nullptr;
  v10 = *(_DWORD *)(HIDWORD(v9) + 212);
  v11 = *(_DWORD *)(HIDWORD(v9) + 196);
  if ( v10 != 0 )
  {
    if ( playVO )
    {
      idGameLocal::PlayInteractVoiceOver(
        this: gameLocal,
        ai: this,
        vo: *(const idDeclVoiceOver **)(HIDWORD(v9) + 212),
        priority: AIVOICEPRIORITY_MED);
      LODWORD(v12) = "ound traces";
      LODWORD(v13) = this->name.data;
      HIDWORD(v13) = "'%s': playing job in progress VO.\n";
      idAI2::Job_DebugPrintf(fmt: v13, a2: v15, a3: v14, a4: v12, a5: v17, a6: v18, a7: v19, a8: v20);
      return (const idDeclVoiceOver *)v10;
    }
  }
  else
  {
    if ( v11 != 0 )
    {
      LODWORD(v6) = "ound traces";
      LODWORD(v16) = *(_DWORD *)(v11 + 8);
      HIDWORD(v16) = "Job '%s' missing job in progress VO.";
      idAI2::Job_DebugPrintf(fmt: v16, a2: v8, a3: v7, a4: v6, a5: v17, a6: v18, a7: v19, a8: v20);
      return nullptr;
    }
    HIDWORD(v9) = "No Job on DeliverJobInProgressVO!";
    idAI2::Job_DebugPrintf(fmt: v9, a2: v8, a3: v7, a4: v6, a5: v17, a6: v18, a7: v19, a8: v20);
  }
  return (const idDeclVoiceOver *)v10;
}


// ========================================================================
// ?Job_Accepted@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA  : 0x82A38B40
// RVA : 0x00A38B40
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_Accepted(idAI2 *this, idPlayer *playerEnt, const bool playVO)
{
  idPlayer *v5; // r31
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const aiPlayerInteraction_t *v11; // r27
  idJobManager *p_jobManager; // r30
  const idDeclVoiceOver *jobByeVO; // r28
  const idDeclJob *interactionJob; // r31
  char v15; // r29
  idJob *JobByDecl; // r3
  __int64 v17; // r10
  __int64 v18; // r4
  __int64 v19; // r8
  __int64 v20; // r6
  __int64 v21; // r4
  int v22; // [sp+8h] [-A8h]
  int v23; // [sp+Ch] [-A4h]
  int v24; // [sp+10h] [-A0h]
  int v25; // [sp+14h] [-9Ch]

  v5 = idPlayer::CastTo(c: playerEnt);
  if ( v5 == nullptr )
    return nullptr;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  v11 = CurrentPlayerInteraction;
  if ( CurrentPlayerInteraction == nullptr )
    return nullptr;
  p_jobManager = &v5->jobManager;
  v5->lastOfferChoice = OFFERCHOICE_UNKNOWN;
  jobByeVO = nullptr;
  interactionJob = CurrentPlayerInteraction->interactionJob;
  v15 = 0;
  if ( interactionJob != nullptr
    && idJobManager::IsJobReadyToComplete(
         this: p_jobManager,
         jobDecl: CurrentPlayerInteraction->interactionJob,
         npc: this) )
  {
    idJobManager::SetJobReadyToTurnIn(
      this: p_jobManager,
      jobDecl: interactionJob,
      completeTree: false,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    JobByDecl = idJobManager::FindJobByDecl(this: p_jobManager, jobDecl: interactionJob);
    v15 = 1;
    if ( JobByDecl != nullptr )
      JobByDecl->displayAlreadyCompleted = true;
  }
  if ( v15 == 0 )
  {
    if ( interactionJob != nullptr )
    {
      if ( interactionJob->aiAcceptImmediatly )
      {
        idJobManager::AcceptJob(this: p_jobManager, jobDecl: interactionJob, completeTree: false, force: false);
      }
      else
      {
        LODWORD(v7) = 58860;
        this->aiVolatile.memory.acceptJobDecl = interactionJob;
      }
    }
    jobByeVO = v11->interactionJobVO.jobByeVO;
    if ( jobByeVO != nullptr )
    {
      if ( playVO )
      {
        idGameLocal::PlayInteractVoiceOver(
          this: gameLocal,
          ai: this,
          vo: v11->interactionJobVO.jobByeVO,
          priority: AIVOICEPRIORITY_HIGH);
        LODWORD(v17) = "ound traces";
        LODWORD(v18) = this->name.data;
        HIDWORD(v18) = "'%s': playing job bye(accepted) VO.\n";
        idAI2::Job_DebugPrintf(fmt: v18, a2: v20, a3: v19, a4: v17, a5: v22, a6: v23, a7: v24, a8: v25);
        return jobByeVO;
      }
    }
    else if ( interactionJob != nullptr )
    {
      LODWORD(v21) = interactionJob->name.str;
      HIDWORD(v21) = "Job '%s' missing job bye(accepted) VO.";
      idAI2::Job_DebugPrintf(fmt: v21, a2: v9, a3: v8, a4: v7, a5: v22, a6: v23, a7: v24, a8: v25);
    }
  }
  return jobByeVO;
}


// ========================================================================
// ?Job_Declined@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA  : 0x82A38CB0
// RVA : 0x00A38CB0
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_Declined(idAI2 *this, idPlayer *playerEnt, const bool playVO)
{
  idPlayer *v5; // r11
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const idDeclVoiceOver *abortedVO; // r30
  __int64 v9; // r10
  __int64 v10; // r4
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r4
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  int v17; // [sp+8h] [-88h]
  int v18; // [sp+Ch] [-84h]
  int v19; // [sp+10h] [-80h]
  int v20; // [sp+14h] [-7Ch]

  v5 = idPlayer::CastTo(c: playerEnt);
  if ( v5 == nullptr )
    return nullptr;
  v5->lastOfferChoice = OFFERCHOICE_UNKNOWN;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  if ( CurrentPlayerInteraction == nullptr )
    return nullptr;
  abortedVO = CurrentPlayerInteraction->abortedVO;
  if ( abortedVO != nullptr )
  {
    if ( playVO )
    {
      idGameLocal::PlayInteractVoiceOver(this: gameLocal, ai: this, vo: abortedVO, priority: AIVOICEPRIORITY_MED);
      LODWORD(v9) = "ound traces";
      LODWORD(v10) = this->name.data;
      HIDWORD(v10) = "'%s': playing job aborted VO.\n";
      idAI2::Job_DebugPrintf(fmt: v10, a2: v12, a3: v11, a4: v9, a5: v17, a6: v18, a7: v19, a8: v20);
      return abortedVO;
    }
  }
  else
  {
    idAIVoiceController::FadeVoiceOver(this: &this->aiVolatile.voiceController, ai: this);
    LODWORD(v13) = this->name.data;
    HIDWORD(v13) = "AI: '%s' no job abort vo";
    idAI2::Job_DebugPrintf(fmt: v13, a2: v16, a3: v15, a4: v14, a5: v17, a6: v18, a7: v19, a8: v20);
  }
  return abortedVO;
}


// ========================================================================
// ?Job_CompleteSavedJob@idAI2@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82A38D78
// RVA : 0x00A38D78
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

int __fastcall idAI2::Job_CompleteSavedJob(idAI2 *this, idPlayer *player)
{
  const idDeclJob **p_completeJobDecl; // r31
  const idDeclJob *completeJobDecl; // r4

  p_completeJobDecl = &this->aiVolatile.memory.completeJobDecl;
  completeJobDecl = this->aiVolatile.memory.completeJobDecl;
  if ( completeJobDecl == nullptr || player == nullptr )
    return 0;
  idJobManager::CompleteJob(
    this: &player->jobManager,
    jobDecl: completeJobDecl,
    completeTree: false,
    giveJob: true,
    force: false);
  *p_completeJobDecl = nullptr;
  return 1;
}


// ========================================================================
// ?Job_AcceptSavedJob@idAI2@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82A38DF8
// RVA : 0x00A38DF8
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

int __fastcall idAI2::Job_AcceptSavedJob(idAI2 *this, idPlayer *player)
{
  const idDeclJob **p_acceptJobDecl; // r31
  const idDeclJob *acceptJobDecl; // r4

  p_acceptJobDecl = &this->aiVolatile.memory.acceptJobDecl;
  acceptJobDecl = this->aiVolatile.memory.acceptJobDecl;
  if ( acceptJobDecl == nullptr || player == nullptr )
    return 0;
  idJobManager::AcceptJob(this: &player->jobManager, jobDecl: acceptJobDecl, completeTree: false, force: false);
  *p_acceptJobDecl = nullptr;
  return 1;
}


// ========================================================================
// ?Job_GetPlayerInteractionState@idAI2@@QBA?AW4playerInteractionState_t@@PBVidPlayer@@@Z
// EA  : 0x82A38E70
// RVA : 0x00A38E70
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

int __fastcall idAI2::Job_GetPlayerInteractionState(idAI2 *this, const idPlayer *player)
{
  idJobManager *p_jobManager; // r30
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const idDeclAIPlayerInteraction *decl; // r29
  const idDeclJob *interactionJob; // r4
  int v8; // r31

  p_jobManager = &player->jobManager;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  if ( CurrentPlayerInteraction == nullptr )
    return 0;
  decl = this->aiVolatile.aiPlayerInteraction.decl;
  if ( decl == nullptr )
    return 0;
  interactionJob = CurrentPlayerInteraction->interactionJob;
  v8 = this->aiVolatile.memory.currentPlayerInteraction;
  if ( interactionJob != nullptr && idJobManager::IsJobInProgress(this: p_jobManager, jobDecl: interactionJob) )
    return 4;
  if ( idJobManager::GetJobOfferPlayed(this: p_jobManager, interactionDecl: decl, interactionNumber: v8) )
    return 2;
  return idJobManager::GetInteractionApproachPlayed(this: p_jobManager, interactionDecl: decl, interactionNumber: v8);
}


// ========================================================================
// ?Job_PlayerLeft@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA  : 0x82A38F38
// RVA : 0x00A38F38
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_PlayerLeft(idAI2 *this, idPlayer *playerEnt, const bool playVO)
{
  idPlayer *v5; // r3
  idPlayer *v6; // r30
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const idDeclVoiceOver *abortedVO; // r30
  int value; // r27

  v5 = idPlayer::CastTo(c: playerEnt);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  idAI2::Job_CompleteSavedJob(this, player: v5);
  idAI2::Job_AcceptSavedJob(this, player: v6);
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  if ( CurrentPlayerInteraction == nullptr )
    return nullptr;
  idAIVoiceController::FadeVoiceOver(this: &this->aiVolatile.voiceController, ai: this);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idFaceMgr::Reset(this: &this->aiVolatile.faceMgr, owner: this, ta: TreeAnimatorFromPresentable);
  abortedVO = nullptr;
  value = this->aiVolatile.voiceController.nextVoiceTime.value;
  if ( value > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    abortedVO = CurrentPlayerInteraction->abortedVO;
    if ( abortedVO != nullptr && playVO )
      idGameLocal::PlayInteractVoiceOver(
        this: gameLocal,
        ai: this,
        vo: CurrentPlayerInteraction->abortedVO,
        priority: AIVOICEPRIORITY_MED);
  }
  idAI2::PlayerInteractionDone(this, playerLeft: true);
  return abortedVO;
}


// ========================================================================
// ?Job_End@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA  : 0x82A39038
// RVA : 0x00A39038
// PDB : w:\tech5\tungsten\game\ai\ai2_jobs.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idAI2::Job_End(idAI2 *this, idPlayer *playerEnt, const bool playVO)
{
  idPlayer *v5; // r29
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r28
  idEntity *Control; // r3
  idDeclJob *interactionJob; // r3
  idJob *CompletedJob; // r3
  idDeclJob *v11; // r3
  __int64 v12; // r8
  __int64 v13; // r6
  bool v14; // r3
  __int64 v15; // r10
  int entityNumber; // r11
  const idDeclVoiceOver *jobEndVO; // r30
  bool v18; // zf
  __int64 v19; // r4
  int v20; // [sp+8h] [-98h]
  int v21; // [sp+Ch] [-94h]
  int v22; // [sp+10h] [-90h]
  int v23; // [sp+14h] [-8Ch]

  v5 = idPlayer::CastTo(c: playerEnt);
  if ( v5 == nullptr )
    return nullptr;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this);
  if ( CurrentPlayerInteraction == nullptr )
    return nullptr;
  if ( idPlayer::GetControl(this: v5) != nullptr )
  {
    Control = idPlayer::GetControl(this: v5);
    idLib::Warning(
      fmt: "early out of Job_End because player is already controled by something.  %s",
      Control->name.data);
    interactionJob = CurrentPlayerInteraction->interactionJob;
    if ( interactionJob != nullptr && idDeclJob::ShowsGUI(this: interactionJob) )
      v5->lastOfferChoice = OFFERCHOICE_DECLINED;
    return nullptr;
  }
  CompletedJob = idJobManager::FindCompletedJob(this: &v5->jobManager, completionNPC: this);
  if ( CompletedJob != nullptr )
    this->aiVolatile.memory.completeJobDecl = CompletedJob->decl;
  v11 = CurrentPlayerInteraction->interactionJob;
  if ( v11 == nullptr )
    return nullptr;
  v14 = idDeclJob::ShowsGUI(this: v11);
  HIDWORD(v15) = &idEventDef::eventDefList[3154];
  if ( v14 )
  {
    if ( this != nullptr )
    {
      entityNumber = this->entityNumber;
      LODWORD(v12) = entityNumber + 29755;
      HIDWORD(v12) = 4 * (entityNumber + 29755);
      LODWORD(v13) = *(idGameLocal_vtbl **)((char *)&gameLocal->__vftable + HIDWORD(v12));
      HIDWORD(v13) = (_DWORD)v13 << 13;
      v5->guiInteractionEntity.spawnId.value = ((_DWORD)v13 << 13) | entityNumber;
    }
    else
    {
      v5->guiInteractionEntity.spawnId.value = 0x1FFF;
    }
  }
  v18 = !playVO;
  jobEndVO = CurrentPlayerInteraction->interactionJobVO.jobEndVO;
  if ( !v18 )
  {
    if ( jobEndVO != nullptr )
    {
      idGameLocal::PlayInteractVoiceOver(
        this: gameLocal,
        ai: this,
        vo: CurrentPlayerInteraction->interactionJobVO.jobEndVO,
        priority: AIVOICEPRIORITY_MED);
      LODWORD(v19) = this->name.data;
      HIDWORD(v19) = "'%s': playing job end VO.\n";
    }
    else
    {
      LODWORD(v15) = "ound traces";
      HIDWORD(v19) = "Job '%s' missing job end VO.";
      LODWORD(v19) = CurrentPlayerInteraction->interactionJob->name.str;
    }
    idAI2::Job_DebugPrintf(fmt: v19, a2: v13, a3: v12, a4: v15, a5: v20, a6: v21, a7: v22, a8: v23);
  }
  idJobManager::SetJobOfferPlayed(
    this: &v5->jobManager,
    interactionDecl: this->aiVolatile.aiPlayerInteraction.decl,
    interactionNumber: this->aiVolatile.memory.currentPlayerInteraction,
    played: true);
  this->aiVolatile.memory.triggeredInteraction.spawnId.value = 0x1FFF;
  this->aiVolatile.memory.interactionIsUsable = false;
  idPlayer::OfferInteraction(
    this: v5,
    offerType: OFFERTYPE_JOB,
    interaction: CurrentPlayerInteraction,
    offeringEntity: this);
  return jobEndVO;
}

