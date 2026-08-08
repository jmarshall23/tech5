
// ========================================================================
// ?Activate@idPhysics_Parametric@@UAAXXZ
// EA  : 0x82E0F938
// RVA : 0x00E0F938
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::Activate(idPhysics_Parametric *this)
{
  this->current.atRest = -1;
}


// ========================================================================
// ?AskForGameSave@idJobManager@@QAAXXZ
// EA  : 0x82E0F948
// RVA : 0x00E0F948
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::AskForGameSave(idJobManager *this)
{
  if ( !this->inDebug )
    this->saveRequested = true;
}


// ========================================================================
// ?GetJobNote@idJob@@QBAPAVidJobNoteTracker@@H@Z
// EA  : 0x82E0F960
// RVA : 0x00E0F960
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idMapPrimitive *__fastcall idJob::GetJobNote(idMapModel *this, int i)
{
  return this->primitives.list[i];
}


// ========================================================================
// ?MarkJobNotesSeenInInv@idJob@@QAAXXZ
// EA  : 0x82E0F970
// RVA : 0x00E0F970
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJob::MarkJobNotesSeenInInv(idJob *this)
{
  int v1; // r9
  int v2; // r10
  idJobNoteTracker *v3; // r11

  v1 = 0;
  if ( this->jobNotes.num > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->jobNotes.list[v2];
      if ( v3->jobNoteStatus < JOBNOTE_STATUS_INV )
        v3->jobNoteStatus = JOBNOTE_STATUS_INV;
      ++v1;
      ++v2;
    }
    while ( v1 < this->jobNotes.num );
  }
}


// ========================================================================
// ?FailsDLCCriteria@idJob@@QBA_NXZ
// EA  : 0x82E0F9B8
// RVA : 0x00E0F9B8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJob::FailsDLCCriteria(idJob *this)
{
  gameDLCState_t requiredDLC; // r4

  return com_production.valueInteger <= 0
      && (requiredDLC = this->decl->requiredDLC) != GAME_DLC_STATE_DEFAULT
      && (_cntlzw((unsigned __int8)idGameLocal::IsDLCStateActive(this: gameLocal, dlcState: requiredDLC)) & 0x20) != 0;
}


// ========================================================================
// ?StartTimer@idJobTimerPhase@@QAAXPAVidPlayer@@VidStrId@@HHH_NABV?$idEntityPtr@VidEntity@@@@H@Z
// EA  : 0x82E0FA28
// RVA : 0x00E0FA28
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerPhase::StartTimer(
        idJobTimerPhase *this,
        idPlayer *player,
        idStrId *name,
        int cashPerScore,
        int parTime,
        int parPrize,
        bool actuallyTime,
        const idEntityPtr<idEntity> *nextTarget,
        int numPhases,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  idStrId *p_phaseName; // r24
  const char *LocalizedString; // r31
  const char *v37; // r3

  if ( this->starttime < 0 || (p_phaseName = &this->phaseName, name->index == this->phaseName.index) )
  {
    if ( actuallyTime && player != nullptr )
      idRageMetrics::ClearLevelStats(this: clientGame->rageMetrics, player);
    this->actuallyRunning = actuallyTime;
    this->starttime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    this->phaseName = (idStrId)name->index;
    this->moneyPerScore = cashPerScore;
    this->partime = parTime;
    this->partimeBonus = parPrize;
    this->continueTarget = (idEntityPtr<idEntity>)nextTarget->spawnId.value;
    this->phaseCount = a28;
  }
  else
  {
    idLib::Warning(fmt: "idJobTimerPhase got a call to StartTimer with a different phase when already running.");
    LocalizedString = idStrId::GetLocalizedString(this: name);
    v37 = idStrId::GetLocalizedString(this: p_phaseName);
    idLib::Warning(fmt: "current phase: %s, new phase: %s,\tWE ARE IGNORING", v37, LocalizedString);
  }
}


// ========================================================================
// ?StopTimer@idJobTimerPhase@@QAAXPAVidPlayer@@@Z
// EA  : 0x82E0FB38
// RVA : 0x00E0FB38
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idJobTimerPhase::StopTimer(idJobTimerPhase *this, idPlayer *player)
{
  idLevelStats *v4; // r3
  idLevelStats *v5; // r30
  int TotalFired; // r3
  __int64 v7; // r9 OVERLAPPED
  double v8; // fp13
  double v9; // fp0
  int v10; // r10
  int v11; // r3
  BOOL arenaBonusGiven; // r9
  int partime; // r11
  int v14; // r10
  int v15; // r11
  int v16; // r7
  int moneyGiven; // r11
  int accuracyBonus; // r10

  if ( this->starttime < 0 )
  {
    idLib::Warning(fmt: "idJobTimerPhase got call to StopTimer before startTimer!");
    this->starttime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  }
  if ( this->stoptime >= 0 )
    idLib::Warning(fmt: "idJobTimerPhase got call to StopTimer when it already had a stoptime");
  if ( player != nullptr )
  {
    idRageMetrics::GetLevelStats(this: clientGame->rageMetrics, player);
    v5 = v4;
    this->totalHits = idLevelStats::GetTotalAccuracyHits(this: v4);
    TotalFired = idLevelStats::GetTotalFired(this: v5);
    HIDWORD(v7) = 0x82000000;
    this->totalFires = TotalFired;
    v8 = 0.0;
    v9 = 0.0;
    if ( TotalFired > 0 )
    {
      v10 = TotalFired;
      LODWORD(v7) = this->totalHits;
      v9 = (float)((float)v7 / (float)*(__int64 *)((char *)&v7 - 4));
      if ( v9 < 0.0 || (v8 = 1.0, v9 > 1.0) )
        v9 = v8;
    }
    this->accuracyBonus = (int)(float)((float)v9 * (float)100.0);
  }
  v11 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  arenaBonusGiven = this->arenaBonusGiven;
  this->stoptime = v11;
  if ( !arenaBonusGiven )
  {
    partime = this->partime;
    v14 = v11 - this->starttime;
    if ( v14 < partime )
    {
      v15 = 2 * ((partime - v14) / 1000);
      v16 = v15 + this->moneyGiven;
      this->givenPartimeBonus = v15;
      this->moneyGiven = v16;
    }
    moneyGiven = this->moneyGiven;
    accuracyBonus = this->accuracyBonus;
    this->arenaBonusGiven = true;
    this->moneyGiven = accuracyBonus + moneyGiven;
  }
}


// ========================================================================
// ?GetTime@idJobTimerPhase@@QBAHXZ
// EA  : 0x82E0FCE8
// RVA : 0x00E0FCE8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobTimerPhase::GetTime(idJobTimerPhase *this)
{
  int starttime; // r10

  starttime = this->starttime;
  if ( starttime < 0 || !this->actuallyRunning )
    return 0;
  if ( this->stoptime >= 0 )
    return this->stoptime - starttime;
  return gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->starttime;
}


// ========================================================================
// ?UpdatePlayerHud@idJobManager@@QAAXPAVidJob@@H_N1@Z
// EA  : 0x82E0FDD0
// RVA : 0x00E0FDD0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::UpdatePlayerHud(
        idJobManager *this,
        idJob *job,
        int requirementNum,
        bool playSound,
        bool treatAsSameStatusUpdate)
{
  const idDeclJob *decl; // r31
  idPlayerHud *PlayerHud; // r3

  if ( this->owner != nullptr
    && job != nullptr
    && (job->status != JOBSTATUS_NONE || (unsigned __int8)idDeclJob::UseDynamicJobHud(this: job->decl) != 0) )
  {
    decl = job->decl;
    PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: this->owner);
    idPlayerHud::UpdateJob(this: PlayerHud, jobDecl: decl, requirementNum, playSound, treatAsSameStatusUpdate);
  }
}


// ========================================================================
// ?PlaySpecialEventJumpSound@idJobManager@@QAAXXZ
// EA  : 0x82E0FE50
// RVA : 0x00E0FE50
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::PlaySpecialEventJumpSound(idJobManager *this)
{
  idPlayer *owner; // r11
  idPresentable *presentable; // r3
  int v4; // r3
  idPlayer *v5; // r31
  const idDeclPlayerProps::playerSounds_t *PlayerSounds; // r3
  char v7; // [sp+50h] [-E0h] BYREF

  owner = this->owner;
  if ( owner != nullptr )
  {
    presentable = owner->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    if ( *(_BYTE *)(v4 + 35105) == 0 )
    {
      v5 = this->owner;
      PlayerSounds = idPlayer::GetPlayerSounds(
                       this: (idPlayer *)&v7,
                       result: (const idDeclPlayerProps::playerSounds_t *)v5);
      idPlayer::PlayLocalSound(
        this: v5,
        channel: SND_CHANNEL_ALERT,
        shader: PlayerSounds->sndSpecialEventJump,
        soundShaderFlags: 0);
    }
  }
}


// ========================================================================
// ?GetOwnerInventoryItemByDecl@idJobManager@@QBAPAVidInventoryItem@@PBVidDeclInventory@@@Z
// EA  : 0x82E0FEE0
// RVA : 0x00E0FEE0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJob *__fastcall idJobManager::GetOwnerInventoryItemByDecl(idJobManager *this, const idDeclJob *decl)
{
  idPlayer *owner; // r3
  idJobManager *v5; // r3

  owner = this->owner;
  if ( owner == nullptr || owner->GetInventory_2(this: owner) == nullptr )
    return nullptr;
  v5 = (idJobManager *)this->owner->GetInventory_2(this: this->owner);
  return idJobManager::FindJobByDecl(this: v5, jobDecl: decl);
}


// ========================================================================
// ?GiveOwnerInventoryItem@idJobManager@@QAAPAVidInventoryItem@@PBVidDeclInventory@@H_N@Z
// EA  : 0x82E0FF60
// RVA : 0x00E0FF60
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idInventoryItem *__fastcall idJobManager::GiveOwnerInventoryItem(
        idJobManager *this,
        const idDeclInventory *decl,
        int count,
        bool canPlayIntroAnim)
{
  idPlayer *owner; // r3
  idPlayer *v9; // r31
  idPresentable *presentable; // r30
  idInventoryCollection *v11; // r3

  owner = this->owner;
  if ( owner == nullptr || owner->GetInventory_2(this: owner) == nullptr )
    return nullptr;
  v9 = this->owner;
  presentable = v9->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v9);
    presentable = v9->presentable;
  }
  v11 = v9->GetInventory_2(this: v9);
  return idInventoryCollection::GiveItem(
           this: v11,
           owner: presentable,
           decl,
           count,
           forceCount: false,
           canIntro: canPlayIntroAnim);
}


// ========================================================================
// ?DeleteOwnerInventoryItem@idJobManager@@QAA_NPBVidDeclInventory@@H@Z
// EA  : 0x82E10000
// RVA : 0x00E10000
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobManager::DeleteOwnerInventoryItem(idJobManager *this, const idDeclInventory *decl, int count)
{
  idPlayer *owner; // r3
  idPlayer *v7; // r31
  idPresentable *presentable; // r30
  idInventoryCollection *v9; // r3

  owner = this->owner;
  if ( owner == nullptr || owner->GetInventory_2(this: owner) == nullptr )
    return false;
  v7 = this->owner;
  presentable = v7->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v7);
    presentable = v7->presentable;
  }
  v9 = v7->GetInventory_2(this: v7);
  return idInventoryCollection::DeleteInventoryItem(this: v9, owner: presentable, decl, count);
}


// ========================================================================
// ?MarkJobNotesSeenOnHUD@idJobManager@@QAAXXZ
// EA  : 0x82E10090
// RVA : 0x00E10090
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::MarkJobNotesSeenOnHUD(idJobManager *this)
{
  int v1; // r6
  int v2; // r7
  int v3; // r8
  idJob *v4; // r10
  int v5; // r11
  idJobNoteTracker *v6; // r9

  v1 = 0;
  if ( this->jobs.num > 0 )
  {
    v2 = 0;
    do
    {
      v3 = 0;
      v4 = this->jobs.list[v2];
      if ( v4->jobNotes.num > 0 )
      {
        v5 = 0;
        do
        {
          v6 = v4->jobNotes.list[v5];
          if ( v6->jobNoteStatus < JOBNOTE_STATUS_HUD )
            v6->jobNoteStatus = JOBNOTE_STATUS_HUD;
          ++v3;
          ++v5;
        }
        while ( v3 < v4->jobNotes.num );
      }
      ++v1;
      ++v2;
    }
    while ( v1 < this->jobs.num );
  }
}


// ========================================================================
// ?FindInventoryItemByDeclName@idInventoryCollection@@QBAPAVidInventoryItem@@PBD@Z
// EA  : 0x82E10108
// RVA : 0x00E10108
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJob *__fastcall idInventoryCollection::FindInventoryItemByDeclName(idJobManager *this, const char *jobName)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->jobs.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->jobs.list[i]->decl->name.str, s2: jobName) != 0; ++i )
  {
    if ( ++v4 >= this->jobs.num )
      return nullptr;
  }
  return this->jobs.list[v4];
}


// ========================================================================
// ?CanItemCompleteAJob@idJobManager@@QAAPBVidDeclJob@@PBVidInventoryItem@@AAH@Z
// EA  : 0x82E10188
// RVA : 0x00E10188
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

const idDeclJob *__fastcall idJobManager::CanItemCompleteAJob(
        idJobManager *this,
        const idInventoryItem *item,
        int *requirementNum)
{
  int v6; // r27
  int i; // r29
  idJob *v8; // r11
  const idDeclJob *decl; // r30
  missionStatus_t status; // r11
  char v11; // r11
  bool v12; // zf
  bool v13; // cr58
  int v14; // r31
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3

  v6 = 0;
  if ( this->jobs.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v8 = this->jobs.list[i];
    decl = v8->decl;
    status = v8->status;
    if ( decl->jobType == JOBTYPE_REPEATING )
    {
      if ( status == JOBSTATUS_READYTOTURNIN || (v12 = status != JOBSTATUS_ACCEPTED, v11 = 0, !v12) )
        v11 = 1;
      v13 = v11 == 0;
    }
    else
    {
      v13 = (_cntlzw(status - 2) & 0x20) == 0;
    }
    if ( !v13 )
    {
      v14 = 0;
      if ( idDeclJob::GetNumCompletionRequirements(this: decl) > 0 )
        break;
    }
LABEL_14:
    if ( ++v6 >= this->jobs.num )
      return nullptr;
  }
  while ( 1 )
  {
    CompletionRequirement = idDeclJob::GetCompletionRequirement(this: decl, idx: v14);
    if ( CompletionRequirement->completion == JOBCOMPLETE_ITEM && CompletionRequirement->inventoryDecl == item->decl )
      break;
    if ( ++v14 >= idDeclJob::GetNumCompletionRequirements(this: decl) )
      goto LABEL_14;
  }
  *requirementNum = v14;
  return decl;
}


// ========================================================================
// ?CanJobCompletionCompleteAJob@idJobManager@@QAAPBVidDeclJob@@PBV2@AAH@Z
// EA  : 0x82E10288
// RVA : 0x00E10288
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

const idDeclJob *__fastcall idJobManager::CanJobCompletionCompleteAJob(
        idJobManager *this,
        const idDeclJob *job,
        int *requirementNum)
{
  int v6; // r27
  int i; // r29
  idJob *v8; // r11
  missionStatus_t status; // r10
  char v10; // r10
  bool v11; // zf
  idDeclJob *decl; // r30
  int v13; // r31
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3

  v6 = 0;
  if ( this->jobs.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v8 = this->jobs.list[i];
    status = v8->status;
    if ( status == JOBSTATUS_READYTOTURNIN || (v11 = status != JOBSTATUS_ACCEPTED, v10 = 0, !v11) )
      v10 = 1;
    if ( v10 != 0 )
    {
      decl = v8->decl;
      v13 = 0;
      if ( idDeclJob::GetNumCompletionRequirements(this: decl) > 0 )
        break;
    }
LABEL_11:
    if ( ++v6 >= this->jobs.num )
      return nullptr;
  }
  while ( 1 )
  {
    CompletionRequirement = idDeclJob::GetCompletionRequirement(this: decl, idx: v13);
    if ( CompletionRequirement->completion == JOBCOMPLETE_JOB
      && idStr::Cmp(s1: CompletionRequirement->jobDecl.data, s2: job->name.str) == 0 )
    {
      break;
    }
    if ( ++v13 >= idDeclJob::GetNumCompletionRequirements(this: decl) )
      goto LABEL_11;
  }
  *requirementNum = v13;
  return decl;
}


// ========================================================================
// ?CanJobAcceptanceCompleteAJob@idJobManager@@QAAPBVidDeclJob@@PBV2@AAH@Z
// EA  : 0x82E10370
// RVA : 0x00E10370
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

const idDeclJob *__fastcall idJobManager::CanJobAcceptanceCompleteAJob(
        idJobManager *this,
        const idDeclJob *job,
        int *requirementNum)
{
  int v6; // r27
  int i; // r29
  idJob *v8; // r11
  missionStatus_t status; // r10
  char v10; // r10
  bool v11; // zf
  idDeclJob *decl; // r30
  int v13; // r31
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3

  v6 = 0;
  if ( this->jobs.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v8 = this->jobs.list[i];
    status = v8->status;
    if ( status == JOBSTATUS_READYTOTURNIN || (v11 = status != JOBSTATUS_ACCEPTED, v10 = 0, !v11) )
      v10 = 1;
    if ( v10 != 0 )
    {
      decl = v8->decl;
      v13 = 0;
      if ( idDeclJob::GetNumCompletionRequirements(this: decl) > 0 )
        break;
    }
LABEL_11:
    if ( ++v6 >= this->jobs.num )
      return nullptr;
  }
  while ( 1 )
  {
    CompletionRequirement = idDeclJob::GetCompletionRequirement(this: decl, idx: v13);
    if ( CompletionRequirement->completion == JOBCOMPLETE_JOB_ACCEPTED
      && idStr::Cmp(s1: CompletionRequirement->jobDecl.data, s2: job->name.str) == 0 )
    {
      break;
    }
    if ( ++v13 >= idDeclJob::GetNumCompletionRequirements(this: decl) )
      goto LABEL_11;
  }
  *requirementNum = v13;
  return decl;
}


// ========================================================================
// ?CanGameStateIntCompleteAJob@idJobManager@@QAAPBVidDeclJob@@PBVidDeclGameStateInt@@HHAAH@Z
// EA  : 0x82E10458
// RVA : 0x00E10458
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

const idDeclJob *__fastcall idJobManager::CanGameStateIntCompleteAJob(
        idJobManager *this,
        const idDeclGameStateInt *decl,
        int previousValue,
        int currentValue,
        int *requirementNum)
{
  int v10; // r27
  int i; // r28
  idJob *v12; // r11
  missionStatus_t status; // r10
  char v14; // r10
  bool v15; // zf
  idDeclJob *v16; // r30
  int v17; // r31
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3
  int count; // r11

  v10 = 0;
  if ( this->jobs.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v12 = this->jobs.list[i];
    status = v12->status;
    if ( status == JOBSTATUS_READYTOTURNIN || (v15 = status != JOBSTATUS_ACCEPTED, v14 = 0, !v15) )
      v14 = 1;
    if ( v14 != 0 )
    {
      v16 = v12->decl;
      v17 = 0;
      if ( idDeclJob::GetNumCompletionRequirements(this: v16) > 0 )
        break;
    }
LABEL_13:
    if ( ++v10 >= this->jobs.num )
      return nullptr;
  }
  while ( 1 )
  {
    CompletionRequirement = idDeclJob::GetCompletionRequirement(this: v16, idx: v17);
    if ( CompletionRequirement->completion == JOBCOMPLETE_GAMESTATEINT
      && CompletionRequirement->gameStateIntDecl == decl )
    {
      count = CompletionRequirement->count;
      if ( previousValue < count && currentValue >= count )
        break;
    }
    if ( ++v17 >= idDeclJob::GetNumCompletionRequirements(this: v16) )
      goto LABEL_13;
  }
  *requirementNum = v17;
  return v16;
}


// ========================================================================
// ?IsJobComplete@idJobManager@@QBA_NPBD@Z
// EA  : 0x82E10550
// RVA : 0x00E10550
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobManager::IsJobComplete(idJobManager *this, const char *name)
{
  idJob *InventoryItemByDeclName; // r3

  InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(this, jobName: name);
  return InventoryItemByDeclName != nullptr && (_cntlzw(InventoryItemByDeclName->status - 5) & 0x20) != 0;
}


// ========================================================================
// ?IsJobComplete@idJobManager@@QBA_NPBVidDeclJob@@@Z
// EA  : 0x82E105A0
// RVA : 0x00E105A0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobManager::IsJobComplete(idJobManager *this, const idDeclJob *jobDecl)
{
  int num; // r8
  int v3; // r10
  idJob **list; // r9
  int i; // r11
  idJob *v7; // r11

  num = this->jobs.num;
  v3 = 0;
  if ( num <= 0 )
    return false;
  list = this->jobs.list;
  for ( i = 0; list[i]->decl != jobDecl; ++i )
  {
    if ( ++v3 >= num )
      return false;
  }
  v7 = list[v3];
  return v7 != nullptr && (_cntlzw(v7->status - 5) & 0x20) != 0;
}


// ========================================================================
// ?IsJobInProgress@idJobManager@@QBA_NPBVidDeclJob@@@Z
// EA  : 0x82E10608
// RVA : 0x00E10608
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobManager::IsJobInProgress(idJobManager *this, const idDeclJob *jobDecl)
{
  int num; // r8
  int v3; // r10
  idJob **list; // r9
  int i; // r11
  idJob *v7; // r11
  missionStatus_t status; // r11

  num = this->jobs.num;
  v3 = 0;
  if ( num <= 0 )
    return false;
  list = this->jobs.list;
  for ( i = 0; list[i]->decl != jobDecl; ++i )
  {
    if ( ++v3 >= num )
      return false;
  }
  v7 = list[v3];
  return v7 != nullptr && ((status = v7->status) == JOBSTATUS_READYTOTURNIN || status == JOBSTATUS_ACCEPTED);
}


// ========================================================================
// ?IsJobAccepted@idJobManager@@QBA_NPBVidDeclJob@@@Z
// EA  : 0x82E10678
// RVA : 0x00E10678
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobManager::IsJobAccepted(idJobManager *this, const idDeclJob *jobDecl)
{
  int num; // r8
  int v3; // r10
  idJob **list; // r9
  int i; // r11
  idJob *v7; // r11

  num = this->jobs.num;
  v3 = 0;
  if ( num <= 0 )
    return false;
  list = this->jobs.list;
  for ( i = 0; list[i]->decl != jobDecl; ++i )
  {
    if ( ++v3 >= num )
      return false;
  }
  v7 = list[v3];
  return v7 != nullptr && (_cntlzw(v7->status - 2) & 0x20) != 0;
}


// ========================================================================
// ?RemoveRewards@idJobManager@@QAAXPBVidDeclJob@@ABV?$idList@VjobReward_t@idDeclJob@@$04@@@Z
// EA  : 0x82E106E0
// RVA : 0x00E106E0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::RemoveRewards(
        idJobManager *this,
        const idDeclJob *jobDecl,
        const idList<idDeclJob::jobReward_t,5> *rewards)
{
  int num; // r4
  int v7; // r29
  int v8; // r23
  char *v9; // r9
  int *p_statAmount; // r10
  int i; // ctr
  int v12; // r31
  const idDeclInventory *v13; // r30
  const idDeclJob *v14; // r31
  const idDeclGameStateInt *v15; // r30
  int v16; // r31
  char v17; // [sp+4Ch] [-C4h] BYREF
  int v18; // [sp+50h] [-C0h]
  const idDeclInventory *v19; // [sp+54h] [-BCh]
  int v20; // [sp+58h] [-B8h]
  int v21; // [sp+5Ch] [-B4h]
  const idDeclJob *v22; // [sp+60h] [-B0h]
  const idDeclGameStateInt *v23; // [sp+64h] [-ACh]

  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    num = rewards->num;
    if ( num > 0 )
      idLib::Printf(fmt: "\tRemove Rewards: %d\n", num);
  }
  if ( jobDecl == nullptr )
  {
    idLib::Warning(fmt: "NULL jobDecl in RemoveRewards");
    return;
  }
  v7 = 0;
  if ( rewards->num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &v17;
      p_statAmount = &rewards->list[v8 - 1].statAmount;
      for ( i = 9; i != 0; --i )
      {
        ++p_statAmount;
        v9 += 4;
        *(_DWORD *)v9 = *p_statAmount;
      }
      switch ( v18 )
      {
        case 1:
          v12 = v20;
          v13 = v19;
          if ( jobDebug_PrintChanges.valueInteger != 0 )
            idLib::Printf(fmt: "\t\t%d Item: %d: %s\n", v7, v20, v19->name.str);
          idJobManager::DeleteOwnerInventoryItem(this, decl: v13, count: v12);
          break;
        case 2:
          idJobManager::GiveOwnerInventoryItem(this, decl: v19, count: v20, canPlayIntroAnim: false);
          break;
        case 3:
          if ( jobDebug_PrintChanges.valueInteger != 0 )
            idLib::Printf(fmt: "\t\t%d Faction: %s\n", v7, *(const char **)(v21 + 8));
          idLib::Warning(fmt: "Not known currently how to revert a faction award in a job");
          break;
        case 4:
          v14 = v22;
          if ( jobDecl != v22 )
          {
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\t%d Job Complete, Uncompleteing: %s\n", v7, v22->name.str);
LABEL_24:
            idJobManager::UnCompleteJob(this, jobDecl: v14);
          }
          break;
        case 5:
          v14 = v22;
          if ( v22 != nullptr )
          {
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\t%d Job Accept, Uncompleteing: %s\n", v7, v22->name.str);
            goto LABEL_24;
          }
          break;
        default:
          switch ( v18 )
          {
            case 9:
              v15 = v23;
              if ( v23 != nullptr )
              {
                v16 = v20;
                if ( jobDebug_PrintChanges.valueInteger != 0 )
                  idLib::Printf(fmt: "\t\t%d Game State Int: %s, %d\n", v7, v23->name.str, v20);
                if ( v16 == 1 )
                  idJobManager::SetGameStateIntValue(this, gameState: v15, stateValue: 0);
                else
                  idLib::Warning(fmt: "reward count for %s is %d,   not sure how to revert that", v15->name.str, v16);
              }
              break;
            case 6:
              if ( jobDebug_PrintChanges.valueInteger != 0 )
                idLib::Printf(fmt: "\t\t%d Job Remove: %s\n", v7, v22->name.str);
              idLib::Warning(fmt: "Not known currently how to revert a remove job award in a job");
              break;
            case 7:
              if ( jobDebug_PrintChanges.valueInteger != 0 )
                idLib::Printf(fmt: "\t\t%d Job Remove In Progress: %s\n", v7, v22->name.str);
              break;
            case 8:
              this->useAlternateHands = false;
              break;
            default:
              idLib::Warning(fmt: "Unknown reward type to revert in revert job rewards");
              break;
          }
          break;
      }
      ++v7;
      ++v8;
    }
    while ( v7 < rewards->num );
  }
}


// ========================================================================
// ?GetJobByIndex@idJobManager@@QBAPAVidJob@@H@Z
// EA  : 0x82E109F0
// RVA : 0x00E109F0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJob *__fastcall idJobManager::GetJobByIndex(idJobManager *this, int index)
{
  char v2; // r11

  if ( index < 0 || (v2 = 1, index >= this->jobs.num) )
    v2 = 0;
  if ( v2 != 0 )
    return this->jobs.list[index];
  else
    return nullptr;
}


// ========================================================================
// ?GetNextDelayTime@idJobManager@@QBAHPAVidJob@@@Z
// EA  : 0x82E10A30
// RVA : 0x00E10A30
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::GetNextDelayTime(idJobManager *this, idJob *job)
{
  int result; // r3
  missionStatus_t status; // r11

  result = 1500;
  if ( job != nullptr )
  {
    status = job->status;
    switch ( status )
    {
      case JOBSTATUS_COMPLETED:
        return job->decl->jobAutoTransitionInfo.completeSpawnInfo.delayTime;
      case JOBSTATUS_READYTOTURNIN:
        return job->decl->jobAutoTransitionInfo.readySpawnInfo.delayTime;
      case JOBSTATUS_ACCEPTED:
        return job->decl->jobAutoTransitionInfo.acceptSpawnInfo.delayTime;
      case JOBSTATUS_FAILED:
        return job->decl->jobAutoTransitionInfo.failSpawnInfo.delayTime;
      default:
        break;
    }
  }
  return result;
}


// ========================================================================
// ?GetHideVehicles@idJobManager@@QBA_NPAVidJob@@@Z
// EA  : 0x82E10A90
// RVA : 0x00E10A90
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobManager::GetHideVehicles(idJobManager *this, idJob *job)
{
  BOOL result; // r3
  missionStatus_t status; // r11

  result = false;
  if ( job != nullptr )
  {
    status = job->status;
    switch ( status )
    {
      case JOBSTATUS_COMPLETED:
        return job->decl->jobAutoTransitionInfo.completeSpawnInfo.hideVehicles;
      case JOBSTATUS_READYTOTURNIN:
        return job->decl->jobAutoTransitionInfo.readySpawnInfo.hideVehicles;
      case JOBSTATUS_ACCEPTED:
        return job->decl->jobAutoTransitionInfo.acceptSpawnInfo.hideVehicles;
      case JOBSTATUS_FAILED:
        return job->decl->jobAutoTransitionInfo.failSpawnInfo.hideVehicles;
      default:
        break;
    }
  }
  return result;
}


// ========================================================================
// ?HasSpecialEvent@idJobManager@@QBA_NPBVidDeclSpecialEvent@@@Z
// EA  : 0x82E10AF0
// RVA : 0x00E10AF0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::HasSpecialEvent(idJobManager *this, const idDeclSpecialEvent *specialEventDecl)
{
  idDeclSpecialEvent::specialEventType_t specialEventType; // r11
  int num; // r8
  int v4; // r10
  int v5; // r7

  if ( specialEventDecl == nullptr )
    return 0;
  specialEventType = specialEventDecl->specialEventType;
  if ( specialEventType != SPECIAL_EVENT_JUMP )
    return 0;
  num = this->specialEvent_Jumps.num;
  v4 = 0;
  if ( num <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = *(int *)((char *)this->specialEvent_Jumps.list + specialEventType);
    if ( v5 != 0 && specialEventDecl == *(const idDeclSpecialEvent **)(v5 + 4) )
      break;
    ++v4;
    specialEventType += 4;
    if ( v4 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?FindGameStateInt@idJobManager@@ABAPAVidGameStateInt@@PBD@Z
// EA  : 0x82E10B58
// RVA : 0x00E10B58
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idGameStateInt *__fastcall idJobManager::FindGameStateInt(idJobManager *this, const char *name)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->gameStateInts.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->gameStateInts.list[i]->decl->name.str, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->gameStateInts.num )
      return nullptr;
  }
  return this->gameStateInts.list[v4];
}


// ========================================================================
// ?PrintGameStateInfo@idJobManager@@QAAXXZ
// EA  : 0x82E10BD8
// RVA : 0x00E10BD8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::PrintGameStateInfo(idJobManager *this)
{
  int v2; // r30
  int v3; // r31

  if ( idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr )
  {
    v2 = 0;
    if ( this->gameStateInts.num > 0 )
    {
      v3 = 0;
      do
      {
        idLib::Printf(
          fmt: "\t%s: %d\n",
          this->gameStateInts.list[v3]->decl->name.str,
          this->gameStateInts.list[v3]->gameStateValue);
        ++v2;
        ++v3;
      }
      while ( v2 < this->gameStateInts.num );
    }
  }
}


// ========================================================================
// ?FindPlayerInteractionMemory@idJobManager@@QBAPAVidAIPlayerInteractionMemory@@PBVidDeclAIPlayerInteraction@@@Z
// EA  : 0x82E10C50
// RVA : 0x00E10C50
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idAIPlayerInteractionMemory *__fastcall idJobManager::FindPlayerInteractionMemory(
        idJobManager *this,
        const idDeclAIPlayerInteraction *interactionDecl)
{
  int v4; // r29
  int i; // r31

  if ( interactionDecl == nullptr )
    return nullptr;
  v4 = 0;
  if ( this->playerInteractionMemories.num <= 0 )
    return nullptr;
  for ( i = 0;
        idStr::Icmp(s1: interactionDecl->name.str, s2: this->playerInteractionMemories.list[i]->declName.data) != 0;
        ++i )
  {
    if ( ++v4 >= this->playerInteractionMemories.num )
      return nullptr;
  }
  return this->playerInteractionMemories.list[v4];
}


// ========================================================================
// ??0idRaceStatusMemory@@QAA@XZ
// EA  : 0x82E10CD0
// RVA : 0x00E10CD0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idRaceStatusMemory *__fastcall idRaceStatusMemory::idRaceStatusMemory(idRaceStatusMemory *this)
{
  this->__vftable = (idRaceStatusMemory_vtbl *)&idRaceStatusMemory::`vftable';
  this->declName.len = 0;
  this->declName.allocedAndFlag = 20;
  this->declName.data = this->declName.baseBuffer;
  this->declName.baseBuffer[0] = 0;
  this->difficulyDelta = 0.0;
  this->bestPlace = RACEMEMORY_UNRACED;
  return this;
}


// ========================================================================
// ??0idRaceStatusMemory@@QAA@PBD@Z
// EA  : 0x82E10D98
// RVA : 0x00E10D98
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idRaceStatusMemory *__fastcall idRaceStatusMemory::idRaceStatusMemory(
        idRaceStatusMemory *this,
        const char *raceDeclName)
{
  this->__vftable = (idRaceStatusMemory_vtbl *)&idRaceStatusMemory::`vftable';
  this->declName.len = 0;
  this->declName.data = this->declName.baseBuffer;
  this->declName.allocedAndFlag = 20;
  this->declName.baseBuffer[0] = 0;
  idStr::operator=(this: &this->declName, text: raceDeclName);
  this->bestPlace = RACEMEMORY_UNRACED;
  this->difficulyDelta = 0.0;
  return this;
}


// ========================================================================
// __unwind$499041
// EA  : 0x82E10E00
// RVA : 0x00E10E00
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_499041()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$499042
// EA  : 0x82E10E28
// RVA : 0x00E10E28
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_499042()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// ?Create@idRaceStatusMemory@@SAPAV1@PBD@Z
// EA  : 0x82E10E60
// RVA : 0x00E10E60
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idRaceStatusMemory *__fastcall idRaceStatusMemory::Create(const char *raceDeclName)
{
  idRaceStatusMemory *v2; // r3

  v2 = (idRaceStatusMemory *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                               size: 0x2Cu,
                               tag: TAG_NEW,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    return idRaceStatusMemory::idRaceStatusMemory(this: v2, raceDeclName);
  else
    return nullptr;
}


// ========================================================================
// __unwind$499093
// EA  : 0x82E10ED8
// RVA : 0x00E10ED8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall _unwind_499093(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?JobTestArea_f@idJobManager@@SAXABVidCmdArgs@@@Z
// EA  : 0x82E10F00
// RVA : 0x00E10F00
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::JobTestArea_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r31
  const idDeclSpecialEvent_Area *specialEventAreaDecl; // r11
  const char *LocalizedString; // r3
  idStrId v4; // [sp+50h] [-20h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  idLib::Warning(fmt: "Job Area test:");
  if ( DebugPlayer != nullptr )
  {
    specialEventAreaDecl = DebugPlayer->jobManager.specialEventAreaDecl;
    if ( specialEventAreaDecl != nullptr )
    {
      idLib::Printf(fmt: " Area Decl:\t%s\n", specialEventAreaDecl->name.str);
      v4.index = DebugPlayer->jobManager.specialEventAreaDecl->areaHudText.index;
      LocalizedString = idStrId::GetLocalizedString(this: &v4);
      idLib::Printf(fmt: " Area Text:\t%s\n\n", LocalizedString);
    }
    else
    {
      idLib::Warning(fmt: " No area decl found");
    }
  }
  else
  {
    idLib::Warning(fmt: " TEST FAILED, NO PLAYER");
  }
}


// ========================================================================
// ?JobActiveGameState_f@idJobManager@@SAXABVidCmdArgs@@@Z
// EA  : 0x82E10FC8
// RVA : 0x00E10FC8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::JobActiveGameState_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r31

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  idLib::Warning(fmt: "Active Game State Variables on the job manager:");
  if ( DebugPlayer != nullptr )
    idJobManager::PrintGameStateInfo(this: &DebugPlayer->jobManager);
}


// ========================================================================
// ?ShowOnInventory@idJobNoteTracker@@QBA_NXZ
// EA  : 0x82E11018
// RVA : 0x00E11018
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobNoteTracker::ShowOnInventory(idJobNoteTracker *this)
{
  const idDeclJobNote *jobNote; // r11

  jobNote = this->jobNote;
  return jobNote != nullptr && jobNote->hudInformation.index >= 0;
}


// ========================================================================
// ?JobCaresAboutCurrentMap@idJob@@QBA_NXZ
// EA  : 0x82E11398
// RVA : 0x00E11398
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJob::JobCaresAboutCurrentMap(idJob *this)
{
  const char *v2; // r3
  const idDeclJob *decl; // r11
  int v4; // r29
  int v5; // r30
  idStr v7; // [sp+50h] [-70h] BYREF
  idStr v8[2]; // [sp+70h] [-50h] BYREF

  if ( gameLocal == nullptr )
    return 0;
  v2 = gameLocal->GetMapName(this: gameLocal);
  idStr::idStr(this: v8, text: v2);
  decl = this->decl;
  v4 = 0;
  if ( decl->relevantMaps.num <= 0 )
  {
LABEL_6:
    idStr::FreeData(this: v8);
    return 0;
  }
  v5 = 0;
  while ( 1 )
  {
    idStr::idStr(this: &v7, text: &decl->relevantMaps.list[v5]);
    idStr::StripFileExtension(this: &v7);
    idStr::StripLeading(this: &v7, string: "maps/");
    if ( idStr::Icmp(s1: v8[0].data, s2: v7.data) == 0 )
      break;
    idStr::FreeData(this: &v7);
    decl = this->decl;
    ++v4;
    ++v5;
    if ( v4 >= decl->relevantMaps.num )
      goto LABEL_6;
  }
  idStr::FreeData(this: &v7);
  idStr::FreeData(this: v8);
  return 1;
}


// ========================================================================
// __unwind$501228
// EA  : 0x82E1147C
// RVA : 0x00E1147C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_501228()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$501229
// EA  : 0x82E114A4
// RVA : 0x00E114A4
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_501229()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ??0idJobTimerPhase@@QAA@XZ
// EA  : 0x82E114D0
// RVA : 0x00E114D0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJobTimerPhase *__fastcall idJobTimerPhase::idJobTimerPhase(idJobTimerPhase *this)
{
  this->score = 0;
  this->moneyGiven = 0;
  this->moneyGivenDirectly = 0;
  this->starttime = -1;
  this->stoptime = -1;
  this->moneyPerScore = 0;
  this->partimeBonus = 0;
  this->givenPartimeBonus = 0;
  this->partime = 0;
  this->phaseName.index = -1;
  *(_WORD *)&this->arenaBonusGiven = 1;
  this->parBonus = 0;
  this->accuracyBonus = 0;
  this->totalHits = 0;
  this->totalFires = 0;
  this->continueTarget.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ?WriteToFile@idJobTimerPhase@@QBAXPAVidFile@@@Z
// EA  : 0x82E11528
// RVA : 0x00E11528
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerPhase::WriteToFile(idJobTimerPhase *this, idFile *file)
{
  int v4; // r3
  idFile_vtbl *v5; // r9
  int v6; // r3
  idFile_vtbl *v7; // r10
  const char *Key; // r3
  int v9; // [sp+50h] [-30h] BYREF
  int v10; // [sp+54h] [-2Ch] BYREF

  file->Write(this: file, a2: this, a3: 4u);
  file->Write(this: file, a2: &this->moneyGiven, a3: 4u);
  file->Write(this: file, a2: &this->moneyGivenDirectly, a3: 4u);
  v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v5 = file->__vftable;
  v9 = this->starttime - v4;
  v5->Write(this: file, a2: &v9, a3: 4u);
  v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v7 = file->__vftable;
  v10 = this->stoptime - v6;
  v7->Write(this: file, a2: &v10, a3: 4u);
  file->Write(this: file, a2: &this->moneyPerScore, a3: 4u);
  file->Write(this: file, a2: &this->partimeBonus, a3: 4u);
  file->Write(this: file, a2: &this->givenPartimeBonus, a3: 4u);
  file->Write(this: file, a2: &this->partime, a3: 4u);
  Key = idStrId::GetKey(this: &this->phaseName);
  idFile::WriteString(this: file, string: Key);
  file->Write(this: file, a2: &this->arenaBonusGiven, a3: 1u);
  file->Write(this: file, a2: &this->actuallyRunning, a3: 1u);
  file->Write(this: file, a2: &this->parBonus, a3: 4u);
  file->Write(this: file, a2: &this->accuracyBonus, a3: 4u);
}


// ========================================================================
// ?ReadFromFile@idJobTimerPhase@@QAAXPAVidFile@@@Z
// EA  : 0x82E11718
// RVA : 0x00E11718
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerPhase::ReadFromFile(idJobTimerPhase *this, idFile *file)
{
  idFile_vtbl *v4; // r11
  int v5; // r3
  int v6; // r3
  int v7; // [sp+50h] [-60h] BYREF
  int v8; // [sp+54h] [-5Ch] BYREF
  idStr v9[2]; // [sp+60h] [-50h] BYREF

  file->Read(this: file, a2: this, a3: 4u);
  file->Read(this: file, a2: &this->moneyGiven, a3: 4u);
  file->Read(this: file, a2: &this->moneyGivenDirectly, a3: 4u);
  v4 = file->__vftable;
  v7 = 0;
  v4->Read(this: file, a2: &v7, a3: 4u);
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v8 = 0;
  this->starttime = v5 + v7;
  file->Read(this: file, a2: &v8, a3: 4u);
  v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  this->stoptime = v6 + v8;
  file->Read(this: file, a2: &this->moneyPerScore, a3: 4u);
  file->Read(this: file, a2: &this->partimeBonus, a3: 4u);
  file->Read(this: file, a2: &this->givenPartimeBonus, a3: 4u);
  file->Read(this: file, a2: &this->partime, a3: 4u);
  v9[0].len = 0;
  v9[0].baseBuffer[0] = 0;
  v9[0].allocedAndFlag = 20;
  v9[0].data = v9[0].baseBuffer;
  idFile::ReadString(this: file, string: v9);
  idStrId::Set(this: &this->phaseName, key: v9[0].data);
  file->Read(this: file, a2: &this->arenaBonusGiven, a3: 1u);
  file->Read(this: file, a2: &this->actuallyRunning, a3: 1u);
  file->Read(this: file, a2: &this->parBonus, a3: 4u);
  file->Read(this: file, a2: &this->accuracyBonus, a3: 4u);
  idStr::FreeData(this: v9);
}


// ========================================================================
// __unwind$501419_0
// EA  : 0x82E11934
// RVA : 0x00E11934
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_501419_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?IsRunning@idJobTimerIteration@@QBA_NXZ
// EA  : 0x82E11960
// RVA : 0x00E11960
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobTimerIteration::IsRunning(idJobTimerIteration *this)
{
  int num; // r10
  int v2; // r10
  idJobTimerPhase *v3; // r11
  int result; // r3

  num = this->phases.num;
  if ( num <= 0 )
    return 0;
  v2 = num;
  v3 = &this->phases.list[v2 - 1];
  if ( &this->phases.list[v2] == (idJobTimerPhase *)68 )
    return 0;
  if ( v3->starttime < 0 )
    return 0;
  result = 1;
  if ( v3->stoptime >= 0 )
    return 0;
  return result;
}


// ========================================================================
// ?WriteToFile@idJobTimerIteration@@QBAXPAVidFile@@@Z
// EA  : 0x82E119C0
// RVA : 0x00E119C0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerIteration::WriteToFile(idJobTimerIteration *this, idFile *file)
{
  const idDeclJobTimerEvent *eventDecl; // r11
  const char *str; // r4
  const idDeclJob *jobDecl; // r11
  const char *v8; // r4
  idFile_vtbl *v9; // r10
  int v10; // r31
  int v11; // r30
  int num; // [sp+50h] [-30h] BYREF

  eventDecl = this->eventDecl;
  if ( eventDecl != nullptr )
    str = eventDecl->name.str;
  else
    str = "BAD EVENT DECL";
  idFile::WriteString(this: file, string: str);
  jobDecl = this->jobDecl;
  if ( jobDecl != nullptr )
    v8 = jobDecl->name.str;
  else
    v8 = "BAD JOB DECL";
  idFile::WriteString(this: file, string: v8);
  v9 = file->__vftable;
  num = this->phases.num;
  v9->Write(this: file, a2: &num, a3: 4u);
  v10 = 0;
  if ( num > 0 )
  {
    v11 = 0;
    do
    {
      idJobTimerPhase::WriteToFile(this: &this->phases.list[v11], file);
      ++v10;
      ++v11;
    }
    while ( v10 < num );
  }
  file->Write(this: file, a2: &this->stoppedTime, a3: 4u);
}


// ========================================================================
// ?WriteToFile@idJobTimerManager@@QBAXPAVidFile@@@Z
// EA  : 0x82E11AA0
// RVA : 0x00E11AA0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::WriteToFile(idJobTimerManager *this, idFile *file)
{
  int v4; // r3
  idFile_vtbl *v5; // r8
  idFile_vtbl *v6; // r11
  int v7; // r30
  int v8; // r29
  int v9; // r3
  idFile_vtbl *v10; // r7
  int num; // [sp+50h] [-30h] BYREF
  int v12; // [sp+54h] [-2Ch] BYREF

  v4 = file->Tell(this: file);
  v5 = file->__vftable;
  v12 = v4;
  v5->Write(this: file, a2: this, a3: 1u);
  v6 = file->__vftable;
  num = this->iterations.num;
  v6->Write(this: file, a2: &num, a3: 4u);
  v7 = 0;
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      idJobTimerIteration::WriteToFile(this: &this->iterations.list[v8], file);
      ++v7;
      ++v8;
    }
    while ( v7 < num );
  }
  v9 = file->Tell(this: file);
  v10 = file->__vftable;
  v12 = v9 - v12;
  v10->Write(this: file, a2: &v12, a3: 4u);
}


// ========================================================================
// ?WriteToFile@idJobManager@@QBAXPAVidFile@@@Z
// EA  : 0x82E11B90
// RVA : 0x00E11B90
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::WriteToFile(idJobManager *this, idFile *file)
{
  int v4; // r3
  int num; // r9
  idFile_vtbl *v6; // r7
  int v7; // r26
  int v8; // r28
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v10; // r11
  unsigned int (__fastcall *v11)(idFile *, const void *, unsigned int); // ctr
  unsigned int (__fastcall *v12)(idFile *, const void *, unsigned int); // ctr
  int v13; // r27
  idJob *v14; // r11
  int v15; // r29
  unsigned int (__fastcall *v16)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v17; // r8
  int v18; // r27
  int v19; // r28
  unsigned int (__fastcall *v20)(idFile *, const void *, unsigned int); // ctr
  int i; // r29
  idAIPlayerInteractionMemory *v22; // r11
  bool v23; // r11
  unsigned int (__fastcall *v24)(idFile *, const void *, unsigned int); // ctr
  int j; // r29
  idAIPlayerInteractionMemory *v26; // r11
  bool v27; // r11
  idFile_vtbl *v28; // r10
  int v29; // r28
  int v30; // r29
  unsigned int (__fastcall *v31)(idFile *, const void *, unsigned int); // ctr
  unsigned int (__fastcall *v32)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v33; // r10
  int v34; // r28
  int v35; // r29
  unsigned int (__fastcall *v36)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v37; // r10
  int v38; // r29
  int v39; // r28
  idFile_vtbl *v40; // r10
  int v41; // r26
  int v42; // r27
  idSpecialEvent_Area_Tracker *v43; // r29
  unsigned int (__fastcall *v44)(idFile *, const void *, unsigned int); // ctr
  char v45; // r11
  char v46; // r7
  unsigned int (__fastcall *v47)(idFile *, const void *, unsigned int); // ctr
  int v48; // r29
  int v49; // r28
  idFile_vtbl *v50; // r6
  int v51; // r28
  int v52; // r27
  idStr *v53; // r29
  unsigned int (__fastcall *v54)(idFile *, const void *, unsigned int); // r8
  char v55; // r11
  char v56; // r10
  int v57; // r3
  idFile_vtbl *v58; // r7
  bool v59; // [sp+50h] [-A0h] BYREF
  bool v60[3]; // [sp+51h] [-9Fh] BYREF
  int len; // [sp+54h] [-9Ch] BYREF
  unsigned int v62; // [sp+58h] [-98h] BYREF
  int v63; // [sp+5Ch] [-94h] BYREF
  int v64; // [sp+60h] [-90h] BYREF
  int v65; // [sp+64h] [-8Ch] BYREF
  int v66; // [sp+68h] [-88h] BYREF
  int v67; // [sp+6Ch] [-84h] BYREF
  int v68; // [sp+70h] [-80h] BYREF
  int v69; // [sp+74h] [-7Ch] BYREF
  int v70; // [sp+78h] [-78h] BYREF
  int v71; // [sp+7Ch] [-74h] BYREF
  int v72; // [sp+80h] [-70h] BYREF
  missionStatus_t status; // [sp+84h] [-6Ch] BYREF
  int v74; // [sp+88h] [-68h] BYREF
  int triggeredCount; // [sp+8Ch] [-64h] BYREF
  int v76; // [sp+90h] [-60h] BYREF
  idJobNoteTracker::jobNoteStatus_t jobNoteStatus; // [sp+94h] [-5Ch] BYREF
  raceMemoryPlace_t bestPlace; // [sp+98h] [-58h] BYREF
  float difficulyDelta; // [sp+9Ch] [-54h] BYREF
  int gameStateValue; // [sp+A0h] [-50h] BYREF

  v4 = file->Tell(this: file);
  num = this->jobs.num;
  v72 = v4;
  v6 = file->__vftable;
  v64 = num;
  v6->Write(this: file, a2: &v64, a3: 4u);
  v7 = 0;
  if ( v64 > 0 )
  {
    v8 = 0;
    do
    {
      Write = file->Write;
      status = this->jobs.list[v8]->status;
      Write(this: file, a2: &status, a3: 4u);
      idFile::WriteString(this: file, string: this->jobs.list[v8]->decl->name.str);
      if ( !idDeclJob::DontSaveProgressToFile(this: this->jobs.list[v8]->decl)
        || this->jobs.list[v8]->status == JOBSTATUS_COMPLETED )
      {
        v11 = file->Write;
        triggeredCount = this->jobs.list[v8]->triggeredCount;
        v11(this: file, a2: &triggeredCount, a3: 4u);
      }
      else
      {
        v10 = file->__vftable;
        v74 = 0;
        v10->Write(this: file, a2: &v74, a3: 4u);
      }
      v12 = file->Write;
      v76 = this->jobs.list[v8]->jobNotes.num;
      v12(this: file, a2: &v76, a3: 4u);
      v13 = 0;
      v14 = this->jobs.list[v8];
      if ( v14->jobNotes.num > 0 )
      {
        v15 = 0;
        do
        {
          idFile::WriteString(this: file, string: v14->jobNotes.list[v15]->jobNote->name.str);
          v16 = file->Write;
          jobNoteStatus = this->jobs.list[v8]->jobNotes.list[v15]->jobNoteStatus;
          v16(this: file, a2: &jobNoteStatus, a3: 4u);
          ++v13;
          ++v15;
          v14 = this->jobs.list[v8];
        }
        while ( v13 < v14->jobNotes.num );
      }
      ++v7;
      ++v8;
    }
    while ( v7 < v64 );
  }
  file->Write(this: file, a2: &this->activeJobIndex, a3: 4u);
  v17 = file->__vftable;
  v65 = this->playerInteractionMemories.num;
  v17->Write(this: file, a2: &v65, a3: 4u);
  v18 = 0;
  if ( v65 > 0 )
  {
    v19 = 0;
    do
    {
      idFile::WriteString(this: file, string: this->playerInteractionMemories.list[v19]->declName.data);
      v20 = file->Write;
      v63 = this->playerInteractionMemories.list[v19]->approachPlayedList.num;
      v20(this: file, a2: &v63, a3: 4u);
      for ( i = 0; i < v63; ++i )
      {
        v22 = this->playerInteractionMemories.list[v19];
        v23 = i < v22->approachPlayedList.num && v22->approachPlayedList.list[i];
        v59 = v23;
        file->Write(this: file, a2: &v59, a3: 1u);
      }
      v24 = file->Write;
      v63 = this->playerInteractionMemories.list[v19]->jobOfferPlayedList.num;
      v24(this: file, a2: &v63, a3: 4u);
      for ( j = 0; j < v63; ++j )
      {
        v26 = this->playerInteractionMemories.list[v19];
        v27 = j < v26->jobOfferPlayedList.num && v26->jobOfferPlayedList.list[j];
        v60[0] = v27;
        file->Write(this: file, a2: v60, a3: 1u);
      }
      ++v18;
      ++v19;
    }
    while ( v18 < v65 );
  }
  v28 = file->__vftable;
  v66 = this->raceStatusMemories.num;
  v28->Write(this: file, a2: &v66, a3: 4u);
  v29 = 0;
  if ( v66 > 0 )
  {
    v30 = 0;
    do
    {
      idFile::WriteString(this: file, string: this->raceStatusMemories.list[v30]->declName.data);
      v31 = file->Write;
      bestPlace = this->raceStatusMemories.list[v30]->bestPlace;
      v31(this: file, a2: &bestPlace, a3: 4u);
      v32 = file->Write;
      difficulyDelta = this->raceStatusMemories.list[v30]->difficulyDelta;
      v32(this: file, a2: &difficulyDelta, a3: 4u);
      ++v29;
      ++v30;
    }
    while ( v29 < v66 );
  }
  v33 = file->__vftable;
  v67 = this->gameStateInts.num;
  v33->Write(this: file, a2: &v67, a3: 4u);
  v34 = 0;
  if ( v67 > 0 )
  {
    v35 = 0;
    do
    {
      idFile::WriteString(this: file, string: this->gameStateInts.list[v35]->decl->name.str);
      v36 = file->Write;
      gameStateValue = this->gameStateInts.list[v35]->gameStateValue;
      v36(this: file, a2: &gameStateValue, a3: 4u);
      ++v34;
      ++v35;
    }
    while ( v34 < v67 );
  }
  v37 = file->__vftable;
  v68 = this->specialEvent_Jumps.num;
  v37->Write(this: file, a2: &v68, a3: 4u);
  v38 = 0;
  if ( v68 > 0 )
  {
    v39 = 0;
    do
    {
      idFile::WriteString(this: file, string: this->specialEvent_Jumps.list[v39]->decl->name.str);
      ++v38;
      ++v39;
    }
    while ( v38 < v68 );
  }
  v40 = file->__vftable;
  v70 = this->specialEventAreaTrackers.num;
  v40->Write(this: file, a2: &v70, a3: 4u);
  v41 = 0;
  if ( v70 > 0 )
  {
    v42 = 0;
    do
    {
      v43 = this->specialEventAreaTrackers.list[v42];
      v44 = file->Write;
      len = v43->areaDecl.len;
      v45 = BYTE1(len);
      v46 = HIBYTE(len);
      BYTE1(len) = BYTE2(len);
      HIBYTE(len) = len;
      LOBYTE(len) = v46;
      BYTE2(len) = v45;
      v44(this: file, a2: &len, a3: 4u);
      file->Write(this: file, a2: v43->areaDecl.data, a3: v43->areaDecl.len);
      v47 = file->Write;
      v69 = this->specialEventAreaTrackers.list[v42]->jobStingersPlayed.num;
      v47(this: file, a2: &v69, a3: 4u);
      v48 = 0;
      if ( v69 > 0 )
      {
        v49 = 0;
        do
        {
          file->Write(this: file, a2: &this->specialEventAreaTrackers.list[v42]->jobStingersPlayed.list[v49], a3: 4u);
          ++v48;
          ++v49;
        }
        while ( v48 < v69 );
      }
      ++v41;
      ++v42;
    }
    while ( v41 < v70 );
  }
  file->Write(this: file, a2: &this->useAlternateHands, a3: 1u);
  file->Write(this: file, a2: &this->newVehicleGarage, a3: 4u);
  v50 = file->__vftable;
  v71 = this->dlcRewardsRecieved.num;
  v50->Write(this: file, a2: &v71, a3: 4u);
  v51 = 0;
  if ( v71 > 0 )
  {
    v52 = 0;
    do
    {
      v53 = &this->dlcRewardsRecieved.list[v52];
      v54 = file->Write;
      v62 = v53->len;
      v55 = BYTE1(v62);
      v56 = v62;
      LOBYTE(v62) = HIBYTE(v62);
      BYTE1(v62) = BYTE2(v62);
      HIBYTE(v62) = v56;
      BYTE2(v62) = v55;
      v54(this: file, a2: &v62, a3: 4u);
      file->Write(this: file, a2: v53->data, a3: v53->len);
      ++v51;
      ++v52;
    }
    while ( v51 < v71 );
  }
  v57 = file->Tell(this: file);
  v58 = file->__vftable;
  v72 = v57 - v72;
  v58->Write(this: file, a2: &v72, a3: 4u);
}


// ========================================================================
// ?RunJobInitializer@idJobManager@@QAAXXZ
// EA  : 0x82E12320
// RVA : 0x00E12320
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::RunJobInitializer(idJobManager *this)
{
  int v2; // r26
  idGameLocal *v3; // r11
  int v4; // r27
  int value; // r9
  idTarget_JobTriggered *v6; // r3
  idTarget_JobTriggered *v7; // r29
  int v8; // r30
  int v9; // r31

  if ( this->owner != nullptr )
  {
    v2 = 0;
    v3 = gameLocal;
    if ( gameLocal->jobTriggeredTargets.num > 0 )
    {
      v4 = 0;
      do
      {
        value = v3->jobTriggeredTargets.list[v4].spawnId.value;
        if ( v3->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v6 = (idTarget_JobTriggered *)v3->entities.ptr[value & 0x1FFF];
          if ( v6 != nullptr )
          {
            v7 = idTarget_JobTriggered::CastTo(c: v6);
            if ( v7 != nullptr )
            {
              v8 = 0;
              if ( this->jobs.num > 0 )
              {
                v9 = 0;
                do
                {
                  idTarget_JobTriggered::HandleJob(
                    this: v7,
                    job: this->jobs.list[v9],
                    player: this->owner,
                    mapLoad: true,
                    debug: false);
                  ++v8;
                  ++v9;
                }
                while ( v8 < this->jobs.num );
              }
            }
            v3 = gameLocal;
          }
        }
        ++v2;
        ++v4;
      }
      while ( v2 < v3->jobTriggeredTargets.num );
    }
  }
}


// ========================================================================
// ?FireOffJobTargets@idJobManager@@QAAXPAVidJob@@_N@Z
// EA  : 0x82E12420
// RVA : 0x00E12420
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::FireOffJobTargets(idJobManager *this, idJob *job, bool debug)
{
  idGameLocal *v6; // r11
  int num; // r30
  int v8; // r31
  int value; // r9
  idTarget_JobTriggered *v10; // r3
  idTarget_JobTriggered *v11; // r3

  if ( this->owner != nullptr && !this->inInitState )
  {
    v6 = gameLocal;
    if ( gameLocal->jobTriggeredTargets.num > 0 )
    {
      num = gameLocal->jobTriggeredTargets.num;
      v8 = 0;
      do
      {
        value = v6->jobTriggeredTargets.list[v8].spawnId.value;
        if ( v6->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v10 = (idTarget_JobTriggered *)v6->entities.ptr[value & 0x1FFF];
          if ( v10 != nullptr )
          {
            v11 = idTarget_JobTriggered::CastTo(c: v10);
            if ( v11 != nullptr )
              idTarget_JobTriggered::HandleJob(this: v11, job, player: this->owner, mapLoad: false, debug);
            v6 = gameLocal;
          }
        }
        --num;
        ++v8;
      }
      while ( num != 0 );
    }
  }
}


// ========================================================================
// ?ClearPlayerInteractionMemories@idJobManager@@QAAXXZ
// EA  : 0x82E124F8
// RVA : 0x00E124F8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::ClearPlayerInteractionMemories(idJobManager *this)
{
  int v2; // r29
  int v3; // r30
  idAIPlayerInteractionMemory *v4; // r3
  idAIPlayerInteractionMemory **list; // r4

  v2 = 0;
  if ( this->playerInteractionMemories.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->playerInteractionMemories.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idAIPlayerInteractionMemory *, int))v4->dtr_idClass)(a1: v4, a2: 1);
      ++v2;
      this->playerInteractionMemories.list[v3++] = nullptr;
    }
    while ( v2 < this->playerInteractionMemories.num );
  }
  if ( this->playerInteractionMemories.listStatic == 0 || this->playerInteractionMemories.listStatic == 2 )
  {
    list = this->playerInteractionMemories.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->playerInteractionMemories.list = nullptr;
    this->playerInteractionMemories.size = 0;
  }
  this->playerInteractionMemories.num = 0;
}


// ========================================================================
// ?ClearRaceStatusMemories@idJobManager@@QAAXXZ
// EA  : 0x82E125A8
// RVA : 0x00E125A8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::ClearRaceStatusMemories(idJobManager *this)
{
  int v2; // r29
  int v3; // r30
  idRaceStatusMemory *v4; // r3
  idRaceStatusMemory **list; // r4

  v2 = 0;
  if ( this->raceStatusMemories.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->raceStatusMemories.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idRaceStatusMemory *, int))v4->dtr_idClass)(a1: v4, a2: 1);
      ++v2;
      this->raceStatusMemories.list[v3++] = nullptr;
    }
    while ( v2 < this->raceStatusMemories.num );
  }
  if ( this->raceStatusMemories.listStatic == 0 || this->raceStatusMemories.listStatic == 2 )
  {
    list = this->raceStatusMemories.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->raceStatusMemories.list = nullptr;
    this->raceStatusMemories.size = 0;
  }
  this->raceStatusMemories.num = 0;
}


// ========================================================================
// ?ClearGameStateInts@idJobManager@@QAAXXZ
// EA  : 0x82E12658
// RVA : 0x00E12658
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::ClearGameStateInts(idJobManager *this)
{
  int v2; // r29
  int v3; // r30
  idGameStateInt *v4; // r3
  idGameStateInt **list; // r4

  v2 = 0;
  if ( this->gameStateInts.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->gameStateInts.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idGameStateInt *, int))v4->dtr_idClass)(a1: v4, a2: 1);
      ++v2;
      this->gameStateInts.list[v3++] = nullptr;
    }
    while ( v2 < this->gameStateInts.num );
  }
  if ( this->gameStateInts.listStatic == 0 || this->gameStateInts.listStatic == 2 )
  {
    list = this->gameStateInts.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->gameStateInts.list = nullptr;
    this->gameStateInts.size = 0;
  }
  this->gameStateInts.num = 0;
}


// ========================================================================
// ?GetActiveJob@idJobManager@@QBAPAVidJob@@XZ
// EA  : 0x82E12708
// RVA : 0x00E12708
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJob *__fastcall idJobManager::GetActiveJob(idJobManager *this)
{
  int activeJobIndex; // r11
  char v3; // r10
  idJob *v4; // r3
  missionStatus_t status; // r11
  int v6; // r10
  char v7; // r11

  activeJobIndex = this->activeJobIndex;
  if ( activeJobIndex == -1 )
    return nullptr;
  if ( activeJobIndex < 0 || (v3 = 1, activeJobIndex >= this->jobs.num) )
    v3 = 0;
  if ( v3 == 0
    || (v4 = this->jobs.list[activeJobIndex]) == nullptr
    || (status = v4->status) == JOBSTATUS_FAILED
    || status == JOBSTATUS_COMPLETED )
  {
    idLib::Warning(fmt: "Error finding active job");
    return nullptr;
  }
  if ( idJob::FailsDLCCriteria(this: v4) )
  {
    idLib::Warning(fmt: "active job no longer meets DLC criteria");
    return nullptr;
  }
  v6 = this->activeJobIndex;
  if ( v6 < 0 || (v7 = 1, v6 >= this->jobs.num) )
    v7 = 0;
  if ( v7 != 0 )
    return this->jobs.list[v6];
  else
    return nullptr;
}


// ========================================================================
// ?SetActiveJobIndex@idJobManager@@QAAXH_N@Z
// EA  : 0x82E12820
// RVA : 0x00E12820
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::SetActiveJobIndex(idJobManager *this, int jobIndex, bool checkImportance)
{
  char v5; // r11
  idJob *v6; // r30
  char v7; // r11
  const char *LocalizedString; // r3
  missionStatus_t status; // r11
  const char *v10; // r3
  const char *v11; // r3
  idStrId v12; // [sp+50h] [-30h] BYREF
  idStrId v13; // [sp+54h] [-2Ch] BYREF
  idStrId v14[10]; // [sp+58h] [-28h] BYREF

  if ( jobIndex < 0 || (v5 = 1, jobIndex >= this->jobs.num) )
    v5 = 0;
  if ( v5 != 0 )
  {
    v6 = this->jobs.list[jobIndex];
    if ( !checkImportance
      || idJobManager::GetActiveJob(this) == nullptr
      || (unsigned __int8)idDeclJob::IsJobImportantForActiveJob(this: v6->decl) != 0 )
    {
      if ( !idDeclJob::IsJobHidden(this: v6->decl) || (v7 = 1, jobDebug_ShowHidden.valueInteger != 0) )
        v7 = 0;
      if ( v7 != 0 )
      {
        idDeclJob::GetJobName(this: (idDeclJob *)&v12, result: (idStrId *)v6->decl);
        LocalizedString = idStrId::GetLocalizedString(this: &v12);
        idLib::Warning(fmt: "Hidden job idJobManager::SetActiveJobIndex %d, %s", jobIndex, LocalizedString);
      }
      else
      {
        status = v6->status;
        if ( status == JOBSTATUS_NONE || status == JOBSTATUS_COMPLETED )
        {
          idDeclJob::GetJobName(this: (idDeclJob *)v14, result: (idStrId *)v6->decl);
          v11 = idStrId::GetLocalizedString(this: v14);
          idLib::Warning(
            fmt: "Job referenced should not be set on hud in idJobManager::SetActiveJobIndex %d, %s",
            jobIndex,
            v11);
        }
        else if ( status == JOBSTATUS_READYTOTURNIN_UNKNOWN )
        {
          idDeclJob::GetJobName(this: (idDeclJob *)&v13, result: (idStrId *)v6->decl);
          v10 = idStrId::GetLocalizedString(this: &v13);
          idLib::Warning(
            fmt: "idJobManager::SetActiveJobIndex wants being set to a job that should be unknown.  %d, %s",
            jobIndex,
            v10);
        }
        else
        {
          this->activeJobIndex = jobIndex;
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "Bad jobIndex passed into idJobManager::SetActiveJobIndex %d", jobIndex);
  }
}


// ========================================================================
// ?SetActiveJobIndexForNextActiveJob@idJobManager@@QAAHXZ
// EA  : 0x82E129A8
// RVA : 0x00E129A8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::SetActiveJobIndexForNextActiveJob(idJobManager *this)
{
  int v2; // r28
  int v3; // r27
  int v4; // r29
  int v5; // r31
  idJob *v6; // r10
  missionStatus_t status; // r11
  char v8; // r11
  bool v9; // zf
  char v10; // r11

  v2 = -1;
  v3 = -1;
  v4 = this->jobs.num - 1;
  if ( v4 < 0 )
    goto LABEL_25;
  v5 = v4;
  do
  {
    v6 = this->jobs.list[v5];
    status = v6->status;
    if ( status == JOBSTATUS_READYTOTURNIN || (v9 = status != JOBSTATUS_ACCEPTED, v8 = 0, !v9) )
      v8 = 1;
    if ( v8 != 0 )
    {
      if ( !idDeclJob::IsJobHidden(this: v6->decl) || (v10 = 1, jobDebug_ShowHidden.valueInteger != 0) )
        v10 = 0;
      if ( v10 == 0
        && (unsigned __int8)idDeclJob::UseDynamicJobHud(this: this->jobs.list[v5]->decl) == 0
        && !idJob::FailsDLCCriteria(this: this->jobs.list[v5]) )
      {
        if ( (unsigned __int8)idDeclJob::IsJobImportant(this: this->jobs.list[v5]->decl) != 0 )
        {
          idJobManager::SetActiveJobIndex(this, jobIndex: v4, checkImportance: false);
          return v4;
        }
        if ( v2 < 0 && (unsigned __int8)idDeclJob::IsJobImportantForActiveJob(this: this->jobs.list[v5]->decl) != 0 )
        {
          v2 = v4;
        }
        else if ( v3 < 0 )
        {
          v3 = v4;
        }
      }
    }
    --v4;
    --v5;
  }
  while ( v4 >= 0 );
  if ( v2 >= 0 )
  {
    idJobManager::SetActiveJobIndex(this, jobIndex: v2, checkImportance: false);
    return v2;
  }
  if ( v3 < 0 )
  {
LABEL_25:
    this->activeJobIndex = -1;
    return -1;
  }
  else
  {
    idJobManager::SetActiveJobIndex(this, jobIndex: v3, checkImportance: false);
    return v3;
  }
}


// ========================================================================
// ?SetJobReadyToTurnIn@idJobManager@@QAA_NPBD_N111@Z
// EA  : 0x82E12B48
// RVA : 0x00E12B48
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobManager::SetJobReadyToTurnIn(
        idJobManager *this,
        const char *jobName,
        bool completeTree,
        bool giveJobIfNeeded,
        bool hideIfGiven,
        bool force)
{
  const idDeclJob *v12; // r4

  if ( jobName != nullptr )
  {
    v12 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                               this: &idDeclJob::resourceList,
                               name: jobName,
                               makeDefault: false);
    if ( v12 != nullptr )
      return idJobManager::SetJobReadyToTurnIn(this, jobDecl: v12, completeTree, giveJobIfNeeded, hideIfGiven, force);
  }
  idLib::Warning(fmt: "Unknown job '%s' in SetJobReadyToTurnIn", jobName);
  return false;
}


// ========================================================================
// ?RemovePreconditions@idJobManager@@QAAXABV?$idList@VjobPreCondition_t@idDeclJob@@$04@@@Z
// EA  : 0x82E12BD8
// RVA : 0x00E12BD8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::RemovePreconditions(
        idJobManager *this,
        const idList<idDeclJob::jobPreCondition_t,5> *preconditions)
{
  int num; // r4
  int v5; // r27
  int i; // r29
  idDeclJob::jobPreCondition_t *v7; // r30
  const idDeclInventory *inventoryDecl; // r11
  int count; // r5
  bool removeInventory; // r10
  const idDeclGameStateInt *gameStateIntDecl; // r4
  idDeclJob::jobPreConditionType_t precondition; // [sp+60h] [-90h]
  idStr v13; // [sp+64h] [-8Ch] BYREF
  idDeclJob::jobPreConditionStatus_t jobStatus; // [sp+84h] [-6Ch]
  const idDeclInventory *v15; // [sp+88h] [-68h]
  int v16; // [sp+8Ch] [-64h]
  bool v17; // [sp+90h] [-60h]
  const idDeclGameStateInt *v18; // [sp+94h] [-5Ch]

  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    num = preconditions->num;
    if ( num > 0 )
      idLib::Printf(fmt: "\tRemove Preconditions: %d\n", num);
  }
  v5 = 0;
  if ( preconditions->num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v7 = &preconditions->list[i];
      precondition = v7->precondition;
      idStr::idStr(this: &v13, text: &v7->jobDecl);
      jobStatus = v7->jobStatus;
      inventoryDecl = v7->inventoryDecl;
      v15 = inventoryDecl;
      count = v7->count;
      v16 = count;
      removeInventory = v7->removeInventory;
      v17 = removeInventory;
      gameStateIntDecl = v7->gameStateIntDecl;
      v18 = gameStateIntDecl;
      if ( precondition != JOBPRECONDITION_ITEM )
        goto LABEL_11;
      if ( removeInventory )
        break;
LABEL_17:
      idStr::FreeData(this: &v13);
      if ( ++v5 >= preconditions->num )
        return;
    }
    if ( jobDebug_PrintChanges.valueInteger != 0 )
    {
      idLib::Printf(fmt: "\t\t%d Item: %d: %s\n", v5, count, inventoryDecl->name.str);
      count = v16;
      inventoryDecl = v15;
    }
    idJobManager::DeleteOwnerInventoryItem(this, decl: inventoryDecl, count);
    gameStateIntDecl = v18;
    count = v16;
LABEL_11:
    if ( precondition == JOBPRECONDITION_GAMESTATEINT && count == 1 && gameStateIntDecl != nullptr )
    {
      if ( jobDebug_PrintChanges.valueInteger != 0 )
      {
        idLib::Printf(fmt: "\t\t%d Game State Int: %s, %d  setting to zero\n", v5, gameStateIntDecl->name.str, 1);
        gameStateIntDecl = v18;
      }
      idJobManager::SetGameStateIntValue(this, gameState: gameStateIntDecl, stateValue: 0);
    }
    goto LABEL_17;
  }
}


// ========================================================================
// __unwind$503825_0
// EA  : 0x82E12D4C
// RVA : 0x00E12D4C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_503825_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 240 + 96));
}


// ========================================================================
// ?GivePreconditions@idJobManager@@QAAXABV?$idList@VjobPreCondition_t@idDeclJob@@$04@@@Z
// EA  : 0x82E12D80
// RVA : 0x00E12D80
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::GivePreconditions(
        idJobManager *this,
        const idList<idDeclJob::jobPreCondition_t,5> *preconditions)
{
  int num; // r4
  int v5; // r29
  int i; // r28
  idDeclJob::jobPreCondition_t *v7; // r30
  const idDeclInventory *inventoryDecl; // r11
  int count; // r5
  bool removeInventory; // r10
  const idDeclJob *v11; // r30
  idJobManager *v12; // r3
  idJob *JobByDecl; // r3
  int v14; // r3
  idPlayer *owner; // [sp+50h] [-A0h]
  idDeclJob::jobPreConditionType_t precondition; // [sp+60h] [-90h]
  idStr v17; // [sp+64h] [-8Ch] BYREF
  idDeclJob::jobPreConditionStatus_t jobStatus; // [sp+84h] [-6Ch]
  const idDeclInventory *v19; // [sp+88h] [-68h]
  int v20; // [sp+8Ch] [-64h]
  bool v21; // [sp+90h] [-60h]
  const idDeclGameStateInt *gameStateIntDecl; // [sp+94h] [-5Ch]

  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    num = preconditions->num;
    if ( num > 0 )
      idLib::Printf(fmt: "\tGive Preconditions: %d\n", num);
  }
  v5 = 0;
  if ( preconditions->num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v7 = &preconditions->list[i];
      precondition = v7->precondition;
      idStr::idStr(this: &v17, text: &v7->jobDecl);
      jobStatus = v7->jobStatus;
      inventoryDecl = v7->inventoryDecl;
      v19 = inventoryDecl;
      count = v7->count;
      v20 = count;
      removeInventory = v7->removeInventory;
      v21 = removeInventory;
      gameStateIntDecl = v7->gameStateIntDecl;
      if ( precondition != JOBPRECONDITION_ITEM )
        goto LABEL_17;
      if ( !removeInventory )
        break;
LABEL_22:
      idStr::FreeData(this: &v17);
      if ( ++v5 >= preconditions->num )
        return;
    }
    if ( jobDebug_PrintChanges.valueInteger != 0 )
      idLib::Printf(fmt: "\t\t%d Item: %d: %s\n", v5, count, inventoryDecl->name.str);
    owner = this->owner;
    if ( owner != nullptr && owner->GetInventory_2(this: owner) != nullptr )
    {
      v11 = (const idDeclJob *)v19;
      v12 = (idJobManager *)this->owner->GetInventory_2(this: this->owner);
      JobByDecl = idJobManager::FindJobByDecl(this: v12, jobDecl: v11);
      if ( JobByDecl != nullptr
        && (v14 = ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl)) >= v20 )
      {
        if ( jobDebug_PrintChanges.valueInteger != 0 )
          idLib::Printf(fmt: "\t\tplayer already had item\n");
      }
      else
      {
        idJobManager::GiveOwnerInventoryItem(this, decl: v19, count: v20, canPlayIntroAnim: false);
      }
    }
LABEL_17:
    if ( precondition == JOBPRECONDITION_GAMESTATEINT && gameStateIntDecl != nullptr )
    {
      if ( jobDebug_PrintChanges.valueInteger != 0 )
        idLib::Printf(fmt: "\t\t%d Game State Int: %s, %d\n", v5, gameStateIntDecl->name.str, v20);
      idJobManager::SetGameStateIntValue(this, gameState: gameStateIntDecl, stateValue: v20);
    }
    goto LABEL_22;
  }
}


// ========================================================================
// __unwind$504013
// EA  : 0x82E12F74
// RVA : 0x00E12F74
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_504013()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 240 + 96));
}


// ========================================================================
// ?GiveCompletionConditions@idJobManager@@QAAXABV?$idList@VjobComplete_t@idDeclJob@@$04@@PAVidJob@@@Z
// EA  : 0x82E12FA8
// RVA : 0x00E12FA8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::GiveCompletionConditions(
        idJobManager *this,
        const idList<idDeclJob::jobComplete_t,5> *completion,
        idJob *job)
{
  int num; // r4
  int v7; // r29
  int i; // r28
  idDeclJob::jobComplete_t *v9; // r30
  idJobManager *v10; // r3
  idJob *JobByDecl; // r3
  idPlayer *owner; // [sp+50h] [-B0h]
  idDeclJob::jobCompleteType_t v13; // [sp+60h] [-A0h]
  const idDeclJob *inventoryDecl; // [sp+64h] [-9Ch]
  int count; // [sp+68h] [-98h]
  idStr v16; // [sp+74h] [-8Ch] BYREF
  const idDeclGameStateInt *gameStateIntDecl; // [sp+94h] [-6Ch]

  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    num = completion->num;
    if ( num > 0 )
      idLib::Printf(fmt: "\tGive Complete Conditions: %d\n", num);
  }
  v7 = 0;
  if ( completion->num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v9 = &completion->list[i];
      v13 = v9->completion;
      inventoryDecl = (const idDeclJob *)v9->inventoryDecl;
      count = v9->count;
      idStr::idStr(this: &v16, text: &v9->jobDecl);
      gameStateIntDecl = v9->gameStateIntDecl;
      if ( v13 == JOBCOMPLETE_ITEM )
      {
        if ( jobDebug_PrintChanges.valueInteger != 0 )
          idLib::Printf(fmt: "\t\t%d Item: %d: %s\n", v7, count, inventoryDecl->name.str);
        owner = this->owner;
        if ( owner != nullptr && owner->GetInventory_2(this: owner) != nullptr )
        {
          v10 = (idJobManager *)this->owner->GetInventory_2(this: this->owner);
          JobByDecl = idJobManager::FindJobByDecl(this: v10, jobDecl: inventoryDecl);
          if ( JobByDecl != nullptr
            && ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) >= count )
          {
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\tplayer already had item\n");
          }
          else
          {
            idJobManager::GiveOwnerInventoryItem(
              this,
              decl: (const idDeclInventory *)inventoryDecl,
              count,
              canPlayIntroAnim: false);
          }
        }
      }
      if ( v13 != JOBCOMPLETE_TRIGGER )
        goto LABEL_21;
      if ( job->triggeredCount < count )
        break;
LABEL_26:
      idStr::FreeData(this: &v16);
      if ( ++v7 >= completion->num )
        return;
    }
    if ( jobDebug_PrintChanges.valueInteger != 0 )
      idLib::Printf(fmt: "\t\t%d TRIGGER, count %d\n", v7, count);
    job->triggeredCount = count;
LABEL_21:
    if ( v13 == JOBCOMPLETE_GAMESTATEINT && gameStateIntDecl != nullptr )
    {
      if ( jobDebug_PrintChanges.valueInteger != 0 )
        idLib::Printf(fmt: "\t\t%d Game State Int: %s, %d\n", v7, gameStateIntDecl->name.str, count);
      idJobManager::SetGameStateIntValue(this, gameState: gameStateIntDecl, stateValue: count);
    }
    goto LABEL_26;
  }
}


// ========================================================================
// __unwind$504236
// EA  : 0x82E131F0
// RVA : 0x00E131F0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_504236()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(v0 - 256 + 96));
}


// ========================================================================
// ?GetNextSpawnSpot@idJobManager@@QBA?AVidStr@@PAVidJob@@@Z
// EA  : 0x82E13220
// RVA : 0x00E13220
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJobManager *__fastcall idJobManager::GetNextSpawnSpot(idJobManager *this, idStr *result, idJob *job)
{
  idJobManager *v5; // r3
  const idDeclJob *decl; // r28
  idJob **len; // r29
  idDeclJob::jobAutoTransitionInfo_t *p_readySpawnInfo; // r4
  missionStatus_t status; // [sp+54h] [-3Ch]

  idStr::idStr((idStr *)this, text: &byte_8200D768);
  if ( job != nullptr )
  {
    v5 = this;
    status = job->status;
    if ( status == JOBSTATUS_COMPLETED )
    {
      decl = job->decl;
      len = (idJob **)decl->jobAutoTransitionInfo.completeSpawnInfo.spawnSpot.len;
      idStr::EnsureAlloced((idStr *)this, amount: (int)len + 1, keepold: false, geometricGrowth: false);
      memcpy(
        Dst: (void *)this->jobs.num,
        Src: decl->jobAutoTransitionInfo.completeSpawnInfo.spawnSpot.data,
        Size: (size_t)len);
      *((_BYTE *)len + this->jobs.num) = 0;
      this->jobs.list = len;
    }
    else
    {
      switch ( status )
      {
        case JOBSTATUS_READYTOTURNIN:
          p_readySpawnInfo = (idDeclJob::jobAutoTransitionInfo_t *)&job->decl->jobAutoTransitionInfo.readySpawnInfo;
          break;
        case JOBSTATUS_ACCEPTED:
          p_readySpawnInfo = &job->decl->jobAutoTransitionInfo;
          break;
        case JOBSTATUS_FAILED:
          p_readySpawnInfo = (idDeclJob::jobAutoTransitionInfo_t *)&job->decl->jobAutoTransitionInfo.failSpawnInfo;
          break;
        default:
          return v5;
      }
      idStr::operator=((idStr *)this, text: &p_readySpawnInfo->acceptSpawnInfo.spawnSpot);
    }
  }
  return this;
}


// ========================================================================
// __unwind$504500
// EA  : 0x82E13308
// RVA : 0x00E13308
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_504500()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 164));
  }
}


// ========================================================================
// ?GetNextMap@idJobManager@@QBA?AVidStr@@PAVidJob@@@Z
// EA  : 0x82E13358
// RVA : 0x00E13358
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJobManager *__fastcall idJobManager::GetNextMap(idJobManager *this, idStr *result, idJob *job)
{
  idJobManager *v5; // r3
  const idDeclJob *decl; // r28
  idJob **len; // r29
  idStr *p_mapName; // r4
  missionStatus_t status; // [sp+54h] [-3Ch]

  idStr::idStr((idStr *)this, text: &byte_8200D768);
  if ( job != nullptr )
  {
    v5 = this;
    status = job->status;
    if ( status == JOBSTATUS_COMPLETED )
    {
      decl = job->decl;
      len = (idJob **)decl->jobAutoTransitionInfo.completeSpawnInfo.mapName.len;
      idStr::EnsureAlloced((idStr *)this, amount: (int)len + 1, keepold: false, geometricGrowth: false);
      memcpy(
        Dst: (void *)this->jobs.num,
        Src: decl->jobAutoTransitionInfo.completeSpawnInfo.mapName.data,
        Size: (size_t)len);
      *((_BYTE *)len + this->jobs.num) = 0;
      this->jobs.list = len;
    }
    else
    {
      switch ( status )
      {
        case JOBSTATUS_READYTOTURNIN:
          p_mapName = &job->decl->jobAutoTransitionInfo.readySpawnInfo.mapName;
          break;
        case JOBSTATUS_ACCEPTED:
          p_mapName = &job->decl->jobAutoTransitionInfo.acceptSpawnInfo.mapName;
          break;
        case JOBSTATUS_FAILED:
          p_mapName = &job->decl->jobAutoTransitionInfo.failSpawnInfo.mapName;
          break;
        default:
          return v5;
      }
      idStr::operator=((idStr *)this, text: p_mapName);
    }
  }
  return this;
}


// ========================================================================
// __unwind$504575
// EA  : 0x82E13440
// RVA : 0x00E13440
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_504575()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 164));
  }
}


// ========================================================================
// ?GetNextLayers@idJobManager@@QBAXPAVidJob@@AAVidStr@@1@Z
// EA  : 0x82E13488
// RVA : 0x00E13488
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::GetNextLayers(
        idJobManager *this,
        idJob *job,
        idStr *activeLayerList,
        idStr *deactiveLayerList)
{
  missionStatus_t status; // r11
  const idDeclJob *decl; // r31
  int v9; // r28
  int v10; // r29
  int v11; // r28
  int v12; // r29
  char *data; // r7
  int v14; // r11
  int v15; // r28
  int v16; // r29
  int v17; // r28
  int v18; // r29
  char *v19; // r7
  int v20; // r11
  int v21; // r28
  int v22; // r29
  int v23; // r28
  int v24; // r29
  int v25; // r28
  int v26; // r29
  int v27; // r28
  int v28; // r29

  idStr::Clear(this: activeLayerList);
  idStr::Clear(this: deactiveLayerList);
  if ( job != nullptr )
  {
    status = job->status;
    decl = job->decl;
    switch ( status )
    {
      case JOBSTATUS_COMPLETED:
        v9 = 0;
        if ( decl->jobAutoTransitionInfo.completeSpawnInfo.layerList.num > 0 )
        {
          v10 = 0;
          do
          {
            if ( decl->jobAutoTransitionInfo.completeSpawnInfo.layerList.list[v10] != nullptr )
            {
              if ( v9 != 0 )
                idStr::Append(this: activeLayerList, a: 44);
              idStr::Append(
                this: activeLayerList,
                text: (char *)decl->jobAutoTransitionInfo.completeSpawnInfo.layerList.list[v10]->name.str);
            }
            ++v9;
            ++v10;
          }
          while ( v9 < decl->jobAutoTransitionInfo.completeSpawnInfo.layerList.num );
        }
        v11 = 0;
        if ( decl->jobAutoTransitionInfo.completeSpawnInfo.layerListDeactive.num > 0 )
        {
          v12 = 0;
          do
          {
            if ( decl->jobAutoTransitionInfo.completeSpawnInfo.layerListDeactive.list[v12] != nullptr )
            {
              if ( v11 != 0 )
              {
                idStr::EnsureAlloced(
                  this: deactiveLayerList,
                  amount: deactiveLayerList->len + 2,
                  keepold: true,
                  geometricGrowth: true);
                deactiveLayerList->data[deactiveLayerList->len] = 44;
                data = deactiveLayerList->data;
                v14 = deactiveLayerList->len + 1;
                deactiveLayerList->len = v14;
                data[v14] = 0;
              }
              idStr::Append(
                this: deactiveLayerList,
                text: (char *)decl->jobAutoTransitionInfo.completeSpawnInfo.layerListDeactive.list[v12]->name.str);
            }
            ++v11;
            ++v12;
          }
          while ( v11 < decl->jobAutoTransitionInfo.completeSpawnInfo.layerListDeactive.num );
        }
        break;
      case JOBSTATUS_READYTOTURNIN:
        v15 = 0;
        if ( decl->jobAutoTransitionInfo.readySpawnInfo.layerList.num > 0 )
        {
          v16 = 0;
          do
          {
            if ( decl->jobAutoTransitionInfo.readySpawnInfo.layerList.list[v16] != nullptr )
            {
              if ( v15 != 0 )
                idStr::Append(this: activeLayerList, a: 44);
              idStr::Append(
                this: activeLayerList,
                text: (char *)decl->jobAutoTransitionInfo.readySpawnInfo.layerList.list[v16]->name.str);
            }
            ++v15;
            ++v16;
          }
          while ( v15 < decl->jobAutoTransitionInfo.readySpawnInfo.layerList.num );
        }
        v17 = 0;
        if ( decl->jobAutoTransitionInfo.readySpawnInfo.layerListDeactive.num > 0 )
        {
          v18 = 0;
          do
          {
            if ( decl->jobAutoTransitionInfo.readySpawnInfo.layerListDeactive.list[v18] != nullptr )
            {
              if ( v17 != 0 )
              {
                idStr::EnsureAlloced(
                  this: deactiveLayerList,
                  amount: deactiveLayerList->len + 2,
                  keepold: true,
                  geometricGrowth: true);
                deactiveLayerList->data[deactiveLayerList->len] = 44;
                v19 = deactiveLayerList->data;
                v20 = deactiveLayerList->len + 1;
                deactiveLayerList->len = v20;
                v19[v20] = 0;
              }
              idStr::Append(
                this: deactiveLayerList,
                text: (char *)decl->jobAutoTransitionInfo.readySpawnInfo.layerListDeactive.list[v18]->name.str);
            }
            ++v17;
            ++v18;
          }
          while ( v17 < decl->jobAutoTransitionInfo.readySpawnInfo.layerListDeactive.num );
        }
        break;
      case JOBSTATUS_ACCEPTED:
        v21 = 0;
        if ( decl->jobAutoTransitionInfo.acceptSpawnInfo.layerList.num > 0 )
        {
          v22 = 0;
          do
          {
            if ( decl->jobAutoTransitionInfo.acceptSpawnInfo.layerList.list[v22] != nullptr )
            {
              if ( v21 != 0 )
                idStr::Append(this: activeLayerList, a: 44);
              idStr::Append(
                this: activeLayerList,
                text: (char *)decl->jobAutoTransitionInfo.acceptSpawnInfo.layerList.list[v22]->name.str);
            }
            ++v21;
            ++v22;
          }
          while ( v21 < decl->jobAutoTransitionInfo.acceptSpawnInfo.layerList.num );
        }
        v23 = 0;
        if ( decl->jobAutoTransitionInfo.acceptSpawnInfo.layerListDeactive.num > 0 )
        {
          v24 = 0;
          do
          {
            if ( decl->jobAutoTransitionInfo.acceptSpawnInfo.layerListDeactive.list[v24] != nullptr )
            {
              if ( v23 != 0 )
                idStr::Append(this: deactiveLayerList, a: 44);
              idStr::Append(
                this: deactiveLayerList,
                text: (char *)decl->jobAutoTransitionInfo.acceptSpawnInfo.layerListDeactive.list[v24]->name.str);
            }
            ++v23;
            ++v24;
          }
          while ( v23 < decl->jobAutoTransitionInfo.acceptSpawnInfo.layerListDeactive.num );
        }
        break;
      case JOBSTATUS_FAILED:
        v25 = 0;
        if ( decl->jobAutoTransitionInfo.failSpawnInfo.layerList.num > 0 )
        {
          v26 = 0;
          do
          {
            if ( decl->jobAutoTransitionInfo.failSpawnInfo.layerList.list[v26] != nullptr )
            {
              if ( v25 != 0 )
                idStr::Append(this: activeLayerList, a: 44);
              idStr::Append(
                this: activeLayerList,
                text: (char *)decl->jobAutoTransitionInfo.failSpawnInfo.layerList.list[v26]->name.str);
            }
            ++v25;
            ++v26;
          }
          while ( v25 < decl->jobAutoTransitionInfo.failSpawnInfo.layerList.num );
        }
        v27 = 0;
        if ( decl->jobAutoTransitionInfo.failSpawnInfo.layerListDeactive.num > 0 )
        {
          v28 = 0;
          do
          {
            if ( decl->jobAutoTransitionInfo.failSpawnInfo.layerListDeactive.list[v28] != nullptr )
            {
              if ( v27 != 0 )
                idStr::Append(this: deactiveLayerList, a: 44);
              idStr::Append(
                this: deactiveLayerList,
                text: (char *)decl->jobAutoTransitionInfo.failSpawnInfo.layerListDeactive.list[v28]->name.str);
            }
            ++v27;
            ++v28;
          }
          while ( v27 < decl->jobAutoTransitionInfo.failSpawnInfo.layerListDeactive.num );
        }
        break;
      default:
        break;
    }
  }
}


// ========================================================================
// ?TransitionToNextPosition@idJobManager@@QAAXPAVidJob@@@Z
// EA  : 0x82E13870
// RVA : 0x00E13870
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idJobManager::TransitionToNextPosition(idJobManager *this, idJob *job)
{
  idPlayer *owner; // r27
  idJob *v5; // r4
  bool HideVehicles; // r30
  int v7; // r8 OVERLAPPED
  __int128 v8; // r7 OVERLAPPED
  int v9; // r8 OVERLAPPED
  __int128 v10; // r7 OVERLAPPED
  __int64 v11; // [sp+8h] [-1E8h]
  __int64 v12; // [sp+8h] [-1E8h]
  __int64 v13; // [sp+10h] [-1E0h]
  __int64 v14; // [sp+10h] [-1E0h]
  __int64 v15; // [sp+18h] [-1D8h]
  __int64 v16; // [sp+18h] [-1D8h]
  __int64 v17; // [sp+20h] [-1D0h]
  __int64 v18; // [sp+20h] [-1D0h]
  __int64 v19; // [sp+28h] [-1C8h]
  __int64 v20; // [sp+28h] [-1C8h]
  __int64 v21; // [sp+30h] [-1C0h]
  __int64 v22; // [sp+30h] [-1C0h]
  __int64 v23; // [sp+38h] [-1B8h]
  __int64 v24; // [sp+38h] [-1B8h]
  __int64 v25; // [sp+40h] [-1B0h]
  __int64 v26; // [sp+40h] [-1B0h]
  __int64 v27; // [sp+48h] [-1A8h]
  __int64 v28; // [sp+48h] [-1A8h]
  __int64 v29; // [sp+50h] [-1A0h]
  __int64 v30; // [sp+50h] [-1A0h]
  __int64 v31; // [sp+58h] [-198h]
  __int64 v32; // [sp+58h] [-198h]
  int v33; // [sp+64h] [-18Ch]
  int v34; // [sp+64h] [-18Ch]
  int v35; // [sp+68h] [-188h]
  int v36; // [sp+68h] [-188h]
  int v37; // [sp+6Ch] [-184h]
  int v38; // [sp+6Ch] [-184h]
  int v39[8]; // [sp+70h] [-180h] BYREF
  int v40[8]; // [sp+90h] [-160h] BYREF
  int v41; // [sp+B0h] [-140h]
  float r; // [sp+B4h] [-13Ch]
  __int64 v43; // [sp+B8h] [-138h]
  int v44; // [sp+C0h] [-130h]
  __int64 v45[4]; // [sp+D0h] [-120h] BYREF
  _DWORD v46[5]; // [sp+F0h] [-100h] BYREF
  idStr v47; // [sp+110h] [-E0h] BYREF
  idStr v48; // [sp+130h] [-C0h] BYREF
  int v49; // [sp+150h] [-A0h]
  char *data; // [sp+154h] [-9Ch]
  __int64 v51; // [sp+158h] [-98h]
  idStr v52; // [sp+170h] [-80h] BYREF
  idStr v53[3]; // [sp+190h] [-60h] BYREF

  if ( !this->inDebug )
  {
    idJobManager::GetNextMap(this: (idJobManager *)&v52, result: (idStr *)this, job);
    if ( v52.len != 0 )
    {
      owner = this->owner;
      v47.len = 0;
      v47.allocedAndFlag = 20;
      v47.data = v47.baseBuffer;
      v47.baseBuffer[0] = 0;
      v48.allocedAndFlag = 20;
      v48.data = v48.baseBuffer;
      v48.len = 0;
      v48.baseBuffer[0] = 0;
      idJobManager::GetNextLayers(this, job, activeLayerList: &v47, deactiveLayerList: &v48);
      idJobManager::GetNextSpawnSpot(this: (idJobManager *)v53, result: (idStr *)this, job);
      idJobManager::GetNextDelayTime(this, job);
      HideVehicles = idJobManager::GetHideVehicles(this, job: v5);
      idPlayer::SetForceInhibitControl(this: owner, inhibit: true);
      owner->shouldHideVehicles = HideVehicles;
      HIBYTE(v46[0]) = 105;
      v46[1] = 750;
      *((float *)v45 + 1) = 1.0;
      HIBYTE(v45[0]) = 102;
      *((float *)&v43 + 1) = idColor::colorBlack.b;
      HIBYTE(v41) = 118;
      *(float *)&v43 = idColor::colorBlack.g;
      r = idColor::colorBlack.r;
      memcpy(Dst: v39, Src: v46, Size: 0x14u);
      v7 = __ROL4__(HIDWORD(v45[0]), 32);
      DWORD1(v8) = v41;
      *((_QWORD *)&v8 + 1) = v43;
      idEventReceiver::PostEventMS(
        this: owner,
        ev: &EV_FadeView,
        arg1: *(__int64 *)((char *)&v8 + 4),
        arg3: *(__int64 *)&v7,
        a5: v45[1],
        a6: v11,
        a7: v13,
        a8: v15,
        a9: v17,
        a10: v19,
        a11: v21,
        a12: v23,
        a13: v25,
        a14: v27,
        a15: v29,
        a16: v31,
        a17: SHIDWORD(v45[2]),
        a18: v33,
        a19: v35,
        a20: v37,
        a21: v39[0]);
      HIBYTE(v45[0]) = 115;
      LODWORD(v45[0]) = v48.data;
      HIBYTE(v46[0]) = 115;
      HIBYTE(v41) = 115;
      HIBYTE(v49) = 115;
      v46[1] = v47.data;
      r = *(float *)&v53[0].data;
      data = v52.data;
      memcpy(Dst: v40, Src: v45, Size: 0x14u);
      memcpy(Dst: v39, Src: v46, Size: 0x14u);
      v9 = __ROL4__(v41, 32);
      DWORD1(v10) = v49;
      *((_QWORD *)&v10 + 1) = v51;
      idEventReceiver::PostEventMS(
        this: owner,
        ev: &EV_NextMap,
        arg1: *(__int64 *)((char *)&v10 + 4),
        arg3: *(__int64 *)&v9,
        arg4: v43,
        a6: v12,
        a7: v14,
        a8: v16,
        a9: v18,
        a10: v20,
        a11: v22,
        a12: v24,
        a13: v26,
        a14: v28,
        a15: v30,
        a16: v32,
        a17: v44,
        a18: v34,
        a19: v36,
        a20: v38,
        a21: v39[0],
        a22: v39[1],
        arg3a: v39[2],
        arg3_4: v39[3],
        arg3_8: v39[4],
        arg3_12: v39[5],
        arg3_16: v39[6],
        a28: v39[7],
        arg4a: v40[0]);
      idStr::FreeData(this: v53);
      idStr::FreeData(this: &v48);
      idStr::FreeData(this: &v47);
    }
    idStr::FreeData(this: &v52);
  }
}


// ========================================================================
// __unwind$504936
// EA  : 0x82E13A88
// RVA : 0x00E13A88
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_504936()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 368));
}


// ========================================================================
// __unwind$504937
// EA  : 0x82E13AB0
// RVA : 0x00E13AB0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_504937()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 272));
}


// ========================================================================
// __unwind$504938
// EA  : 0x82E13AD8
// RVA : 0x00E13AD8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_504938()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 304));
}


// ========================================================================
// __unwind$504939
// EA  : 0x82E13B00
// RVA : 0x00E13B00
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_504939()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 400));
}


// ========================================================================
// ?TransitionToNextPositionForJustGUIJob@idJobManager@@QAAXPBVidDeclJob@@@Z
// EA  : 0x82E13B30
// RVA : 0x00E13B30
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idJobManager::TransitionToNextPositionForJustGUIJob(idJobManager *this, const idDeclJob *jobDecl)
{
  idPlayer *owner; // r25
  int v5; // r28
  int v6; // r29
  int v7; // r28
  int v8; // r29
  bool hideVehicles; // r30
  int v10; // r8 OVERLAPPED
  __int128 v11; // r7 OVERLAPPED
  int v12; // r8 OVERLAPPED
  __int128 v13; // r7 OVERLAPPED
  __int64 v14; // [sp+8h] [-1E8h]
  __int64 v15; // [sp+8h] [-1E8h]
  __int64 v16; // [sp+10h] [-1E0h]
  __int64 v17; // [sp+10h] [-1E0h]
  __int64 v18; // [sp+18h] [-1D8h]
  __int64 v19; // [sp+18h] [-1D8h]
  __int64 v20; // [sp+20h] [-1D0h]
  __int64 v21; // [sp+20h] [-1D0h]
  __int64 v22; // [sp+28h] [-1C8h]
  __int64 v23; // [sp+28h] [-1C8h]
  __int64 v24; // [sp+30h] [-1C0h]
  __int64 v25; // [sp+30h] [-1C0h]
  __int64 v26; // [sp+38h] [-1B8h]
  __int64 v27; // [sp+38h] [-1B8h]
  __int64 v28; // [sp+40h] [-1B0h]
  __int64 v29; // [sp+40h] [-1B0h]
  __int64 v30; // [sp+48h] [-1A8h]
  __int64 v31; // [sp+48h] [-1A8h]
  __int64 v32; // [sp+50h] [-1A0h]
  __int64 v33; // [sp+50h] [-1A0h]
  __int64 v34; // [sp+58h] [-198h]
  __int64 v35; // [sp+58h] [-198h]
  int v36; // [sp+64h] [-18Ch]
  int v37; // [sp+64h] [-18Ch]
  int v38; // [sp+68h] [-188h]
  int v39; // [sp+68h] [-188h]
  int v40; // [sp+6Ch] [-184h]
  int v41; // [sp+6Ch] [-184h]
  int v42[8]; // [sp+70h] [-180h] BYREF
  int v43[8]; // [sp+90h] [-160h] BYREF
  idStr v44; // [sp+B0h] [-140h] BYREF
  int v45; // [sp+D0h] [-120h]
  float r; // [sp+D4h] [-11Ch]
  __int64 v47; // [sp+D8h] [-118h]
  int v48; // [sp+E0h] [-110h]
  __int64 v49[4]; // [sp+F0h] [-100h] BYREF
  _DWORD v50[5]; // [sp+110h] [-E0h] BYREF
  idStr v51; // [sp+130h] [-C0h] BYREF
  int v52; // [sp+150h] [-A0h]
  char *data; // [sp+154h] [-9Ch]
  __int64 v54; // [sp+158h] [-98h]
  idStr v55; // [sp+170h] [-80h] BYREF
  idStr v56[3]; // [sp+190h] [-60h] BYREF

  if ( !this->inDebug && jobDecl != nullptr )
  {
    idStr::idStr(this: &v55, text: &jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.mapName);
    if ( v55.len != 0 )
    {
      owner = this->owner;
      v51.len = 0;
      v51.baseBuffer[0] = 0;
      v51.allocedAndFlag = 20;
      v51.data = v51.baseBuffer;
      v44.len = 0;
      v44.baseBuffer[0] = 0;
      v44.allocedAndFlag = 20;
      v44.data = v44.baseBuffer;
      v5 = 0;
      if ( jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.layerList.num > 0 )
      {
        v6 = 0;
        do
        {
          if ( jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.layerList.list[v6] != nullptr )
          {
            if ( v5 != 0 )
              idStr::Append(this: &v51, a: 44);
            idStr::Append(
              this: &v51,
              text: (char *)jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.layerList.list[v6]->name.str);
          }
          ++v5;
          ++v6;
        }
        while ( v5 < jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.layerList.num );
      }
      v7 = 0;
      if ( jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.layerListDeactive.num > 0 )
      {
        v8 = 0;
        do
        {
          if ( jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.layerListDeactive.list[v8] != nullptr )
          {
            if ( v7 != 0 )
            {
              idStr::EnsureAlloced(this: &v44, amount: v44.len + 2, keepold: true, geometricGrowth: true);
              v44.data[v44.len++] = 44;
              v44.data[v44.len] = 0;
            }
            idStr::Append(
              this: &v44,
              text: (char *)jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.layerListDeactive.list[v8]->name.str);
          }
          ++v7;
          ++v8;
        }
        while ( v7 < jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.layerListDeactive.num );
      }
      idStr::idStr(this: v56, text: &jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.spawnSpot);
      hideVehicles = jobDecl->jobAutoTransitionInfo.acceptSpawnInfo.hideVehicles;
      idPlayer::SetForceInhibitControl(this: owner, inhibit: true);
      owner->shouldHideVehicles = hideVehicles;
      HIBYTE(v50[0]) = 105;
      v50[1] = 750;
      *((float *)v49 + 1) = 1.0;
      HIBYTE(v49[0]) = 102;
      *((float *)&v47 + 1) = idColor::colorBlack.b;
      HIBYTE(v45) = 118;
      *(float *)&v47 = idColor::colorBlack.g;
      r = idColor::colorBlack.r;
      memcpy(Dst: v42, Src: v50, Size: 0x14u);
      v10 = __ROL4__(HIDWORD(v49[0]), 32);
      DWORD1(v11) = v45;
      *((_QWORD *)&v11 + 1) = v47;
      idEventReceiver::PostEventMS(
        this: owner,
        ev: &EV_FadeView,
        arg1: *(__int64 *)((char *)&v11 + 4),
        arg3: *(__int64 *)&v10,
        a5: v49[1],
        a6: v14,
        a7: v16,
        a8: v18,
        a9: v20,
        a10: v22,
        a11: v24,
        a12: v26,
        a13: v28,
        a14: v30,
        a15: v32,
        a16: v34,
        a17: SHIDWORD(v49[2]),
        a18: v36,
        a19: v38,
        a20: v40,
        a21: v42[0]);
      HIBYTE(v49[0]) = 115;
      HIBYTE(v50[0]) = 115;
      HIBYTE(v45) = 115;
      LODWORD(v49[0]) = v44.data;
      HIBYTE(v52) = 115;
      v50[1] = v51.data;
      data = v55.data;
      r = *(float *)&v56[0].data;
      memcpy(Dst: v43, Src: v49, Size: 0x14u);
      memcpy(Dst: v42, Src: v50, Size: 0x14u);
      v12 = __ROL4__(v45, 32);
      DWORD1(v13) = v52;
      *((_QWORD *)&v13 + 1) = v54;
      idEventReceiver::PostEventMS(
        this: owner,
        ev: &EV_NextMap,
        arg1: *(__int64 *)((char *)&v13 + 4),
        arg3: *(__int64 *)&v12,
        arg4: v47,
        a6: v15,
        a7: v17,
        a8: v19,
        a9: v21,
        a10: v23,
        a11: v25,
        a12: v27,
        a13: v29,
        a14: v31,
        a15: v33,
        a16: v35,
        a17: v48,
        a18: v37,
        a19: v39,
        a20: v41,
        a21: v42[0],
        a22: v42[1],
        arg3a: v42[2],
        arg3_4: v42[3],
        arg3_8: v42[4],
        arg3_12: v42[5],
        arg3_16: v42[6],
        a28: v42[7],
        arg4a: v43[0]);
      idStr::FreeData(this: v56);
      idStr::FreeData(this: &v44);
      idStr::FreeData(this: &v51);
    }
    idStr::FreeData(this: &v55);
  }
}


// ========================================================================
// __unwind$505105
// EA  : 0x82E13E10
// RVA : 0x00E13E10
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_505105()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 368));
}


// ========================================================================
// __unwind$505106
// EA  : 0x82E13E38
// RVA : 0x00E13E38
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_505106()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 304));
}


// ========================================================================
// __unwind$505107
// EA  : 0x82E13E60
// RVA : 0x00E13E60
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_505107()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 176));
}


// ========================================================================
// __unwind$505108
// EA  : 0x82E13E88
// RVA : 0x00E13E88
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_505108()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 400));
}


// ========================================================================
// ?GetGameStateIntValue@idJobManager@@QBAHPBD@Z
// EA  : 0x82E13EB0
// RVA : 0x00E13EB0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idGameStateInt *__fastcall idJobManager::GetGameStateIntValue(idJobManager *this, const char *name)
{
  idGameStateInt *result; // r3

  result = idJobManager::FindGameStateInt(this, name);
  if ( result != nullptr )
    return (idGameStateInt *)result->gameStateValue;
  return result;
}


// ========================================================================
// ?GetGameStateIntValue@idJobManager@@QBAHPBVidDeclGameStateInt@@@Z
// EA  : 0x82E13EF0
// RVA : 0x00E13EF0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::GetGameStateIntValue(idJobManager *this, const idDeclGameStateInt *gameState)
{
  int num; // r8
  int v3; // r10
  idGameStateInt **list; // r9
  int i; // r11
  idGameStateInt *v7; // r11

  num = this->gameStateInts.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  list = this->gameStateInts.list;
  for ( i = 0; list[i]->decl != gameState; ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  v7 = list[v3];
  if ( v7 != nullptr )
    return v7->gameStateValue;
  else
    return 0;
}


// ========================================================================
// ?FindRaceStatusMemory@idJobManager@@QBAPAVidRaceStatusMemory@@PBD@Z
// EA  : 0x82E13F50
// RVA : 0x00E13F50
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idRaceStatusMemory *__fastcall idJobManager::FindRaceStatusMemory(idJobManager *this, const char *raceDeclName)
{
  int v4; // r29
  int i; // r31

  if ( raceDeclName == nullptr )
    return nullptr;
  v4 = 0;
  if ( this->raceStatusMemories.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: raceDeclName, s2: this->raceStatusMemories.list[i]->declName.data) != 0; ++i )
  {
    if ( ++v4 >= this->raceStatusMemories.num )
      return nullptr;
  }
  return this->raceStatusMemories.list[v4];
}


// ========================================================================
// ?GetInteractionApproachPlayed@idJobManager@@QBA_NPBVidDeclAIPlayerInteraction@@H@Z
// EA  : 0x82E13FD0
// RVA : 0x00E13FD0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobManager::GetInteractionApproachPlayed(
        idJobManager *this,
        const idDeclAIPlayerInteraction *interactionDecl,
        int interactionNumber)
{
  idAIPlayerInteractionMemory *PlayerInteractionMemory; // r3

  PlayerInteractionMemory = idJobManager::FindPlayerInteractionMemory(this, interactionDecl);
  return PlayerInteractionMemory != nullptr
      && interactionNumber < PlayerInteractionMemory->approachPlayedList.num
      && PlayerInteractionMemory->approachPlayedList.list[interactionNumber];
}


// ========================================================================
// ?GetJobOfferPlayed@idJobManager@@QBA_NPBVidDeclAIPlayerInteraction@@H@Z
// EA  : 0x82E14030
// RVA : 0x00E14030
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

BOOL __fastcall idJobManager::GetJobOfferPlayed(
        idJobManager *this,
        const idDeclAIPlayerInteraction *interactionDecl,
        int interactionNumber)
{
  idAIPlayerInteractionMemory *PlayerInteractionMemory; // r3

  PlayerInteractionMemory = idJobManager::FindPlayerInteractionMemory(this, interactionDecl);
  return PlayerInteractionMemory != nullptr
      && interactionNumber < PlayerInteractionMemory->jobOfferPlayedList.num
      && PlayerInteractionMemory->jobOfferPlayedList.list[interactionNumber];
}


// ========================================================================
// ?ParseText@@YAXAAVidLexer@@AAVidStrId@@AAVidStr@@@Z
// EA  : 0x82E140F8
// RVA : 0x00E140F8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall ParseText(idLexer *src, idStrId *id, idStr *text)
{
  int len; // r28
  idToken v7; // [sp+50h] [-80h] BYREF

  v7.len = 0;
  v7.allocedAndFlag = 20;
  v7.floatvalue = -3.4028235e38;
  v7.data = v7.baseBuffer;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
  idStrId::Set(this: id, key: v7.data);
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v7);
  idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
  len = v7.len;
  idStr::EnsureAlloced(this: text, amount: v7.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: text->data, Src: v7.data, Size: len);
  text->data[len] = 0;
  text->len = len;
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v7);
  idStr::FreeData(this: &v7);
}


// ========================================================================
// __unwind$505544
// EA  : 0x82E141EC
// RVA : 0x00E141EC
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_505544()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ??0idJob@@QAA@XZ
// EA  : 0x82E14640
// RVA : 0x00E14640
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJob *__fastcall idJob::idJob(idJob *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->__vftable = (idJob_vtbl *)&idJob::`vftable';
  this->status = JOBSTATUS_NONE;
  this->displayAlreadyCompleted = false;
  this->triggeredCount = 0;
  this->seen = false;
  this->jobNotes.list = nullptr;
  this->jobNotes.granularity = 0;
  this->jobNotes.memTag = 5;
  this->jobNotes.listStatic = 0;
  this->jobNotes.size = 0;
  this->jobNotes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobNotes);
  return this;
}


// ========================================================================
// __unwind$506606
// EA  : 0x82E146C8
// RVA : 0x00E146C8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_506606()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idJob@@QAA@PBVidDeclJob@@@Z
// EA  : 0x82E146F8
// RVA : 0x00E146F8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJob *__fastcall idJob::idJob(idJob *this, const idDeclJob *jobDecl)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = jobDecl;
  this->status = JOBSTATUS_NONE;
  this->__vftable = (idJob_vtbl *)&idJob::`vftable';
  this->displayAlreadyCompleted = false;
  this->triggeredCount = 0;
  this->seen = false;
  this->jobNotes.list = nullptr;
  this->jobNotes.granularity = 0;
  this->jobNotes.memTag = 5;
  this->jobNotes.listStatic = 0;
  this->jobNotes.size = 0;
  this->jobNotes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobNotes);
  return this;
}


// ========================================================================
// __unwind$506636
// EA  : 0x82E1476C
// RVA : 0x00E1476C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_506636()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idJob@@UAA@XZ
// EA  : 0x82E147A0
// RVA : 0x00E147A0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJob::~idJob(idJob *this)
{
  this->__vftable = (idJob_vtbl *)&idJob::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobNotes);
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$506657
// EA  : 0x82E147F4
// RVA : 0x00E147F4
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_506657()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// ?Create@idJob@@SAPAV1@PBVidDeclJob@@@Z
// EA  : 0x82E14828
// RVA : 0x00E14828
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJob *__fastcall idJob::Create(const idDeclJob *jobDecl)
{
  idJob *v2; // r3

  v2 = (idJob *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                  size: 0x30u,
                  tag: TAG_NEW,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    return idJob::idJob(this: v2, jobDecl);
  else
    return nullptr;
}


// ========================================================================
// __unwind$506682
// EA  : 0x82E148A0
// RVA : 0x00E148A0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall _unwind_506682(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?SetJobStatus@idJob@@QAAXW4missionStatus_t@@PAVidJobManager@@_N2@Z
// EA  : 0x82E148C8
// RVA : 0x00E148C8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJob::SetJobStatus(
        idJob *this,
        missionStatus_t newStatus,
        idJobManager *manager,
        bool fireOffJobTargets,
        bool debug)
{
  missionStatus_t status; // r26
  const char *LocalizedString; // r3
  const char *str; // r31
  idGameTimeManager *v13; // r3
  int GameMs; // r3
  idStrId v15[16]; // [sp+50h] [-40h] BYREF

  if ( jobDebug_PrintStatus.valueInteger != 0 )
  {
    status = this->status;
    idDeclJob::GetJobName(this: (idDeclJob *)v15, result: (idStrId *)this->decl);
    LocalizedString = idStrId::GetLocalizedString(this: v15);
    idLib::Printf(fmt: "SetJobStatus on %s, from %d - to - %d\n", LocalizedString, status, newStatus);
  }
  this->status = newStatus;
  if ( manager != nullptr )
  {
    idJobManager::UpdatePlayerHud(
      this: manager,
      job: this,
      requirementNum: -1,
      playSound: true,
      treatAsSameStatusUpdate: false);
    if ( fireOffJobTargets )
      idJobManager::FireOffJobTargets(this: manager, job: this, debug);
    if ( newStatus >= JOBSTATUS_ACCEPTED && !idDeclJob::IsJobHidden(this: this->decl) && !manager->inDebug )
    {
      str = this->decl->name.str;
      v13 = gameLocal->GetGameTimeManager(this: gameLocal);
      GameMs = idGameTimeManager::GetGameMs(this: v13, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "%d Job: %s asking for save due to state changed to %d\n", GameMs, str, newStatus);
      if ( !manager->inDebug )
        manager->saveRequested = true;
    }
  }
}


// ========================================================================
// ?Event_DoRepeat@idJob@@QAA?AVeventVoid@@XZ
// EA  : 0x82E149F0
// RVA : 0x00E149F0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJob *__fastcall idJob::Event_DoRepeat(idJob *this, eventVoid *result)
{
  idStrId *v3; // r4
  int v5; // r29
  const char *LocalizedString; // r3
  const char *v8; // r3
  idStrId v9; // [sp+50h] [-30h] BYREF
  idStrId v10[11]; // [sp+54h] [-2Ch] BYREF

  v3 = *(idStrId **)&result[12];
  if ( v3[25].index == 5 )
  {
    if ( jobDebug_PrintStatus.valueInteger != 0 )
    {
      v5 = *(_DWORD *)&result[16];
      idDeclJob::GetJobName(this: (idDeclJob *)&v9, result: v3);
      LocalizedString = idStrId::GetLocalizedString(this: &v9);
      idLib::Printf(fmt: "SetJobStatus on %s, from %d - to - %d\n", LocalizedString, v5, 2);
    }
    *(_DWORD *)&result[16] = 2;
    return this;
  }
  else
  {
    idDeclJob::GetJobName(this: (idDeclJob *)v10, result: v3);
    v8 = idStrId::GetLocalizedString(this: v10);
    idLib::Warning(fmt: "got call to event_doRepeat in non repeating job %s", v8);
    return this;
  }
}


// ========================================================================
// ??0idJobTimerIteration@@QAA@XZ
// EA  : 0x82E14A98
// RVA : 0x00E14A98
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJobTimerIteration *__fastcall idJobTimerIteration::idJobTimerIteration(idJobTimerIteration *this)
{
  this->phases.list = nullptr;
  this->phases.granularity = 0;
  this->phases.memTag = 5;
  this->phases.listStatic = 0;
  this->phases.size = 0;
  this->phases.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->eventDecl = nullptr;
  this->stoppedTime = -1;
  return this;
}


// ========================================================================
// ??1idJobTimerIteration@@QAA@XZ
// EA  : 0x82E14B08
// RVA : 0x00E14B08
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerIteration::~idJobTimerIteration(idJobTimerIteration *this)
{
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$506821
// EA  : 0x82E14B4C
// RVA : 0x00E14B4C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_506821()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ?StopTimer@idJobTimerIteration@@QAAXPAVidPlayer@@@Z
// EA  : 0x82E14B78
// RVA : 0x00E14B78
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerIteration::StopTimer(idJobTimerIteration *this, idPlayer *player)
{
  int num; // r9
  idJobTimerPhase *v4; // r11
  char v5; // r11
  bool v6; // zf
  idJobTimerPhase *v7; // r3

  num = this->phases.num;
  if ( num <= 0
    || (v4 = &this->phases.list[num - 1], &this->phases.list[num] == (idJobTimerPhase *)68)
    || v4->starttime < 0
    || (v6 = v4->stoptime < 0, v5 = 1, !v6) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
  {
    if ( num <= 0 )
      v7 = nullptr;
    else
      v7 = &this->phases.list[num - 1];
    idJobTimerPhase::StopTimer(this: v7, player);
    this->stoppedTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  }
  else
  {
    idLib::Warning(fmt: "idJobTimerIteration got call to stop timer when not actually timing.  IGNORING.", player);
  }
}


// ========================================================================
// ?IncrementScore@idJobTimerIteration@@QAAXXZ
// EA  : 0x82E14C70
// RVA : 0x00E14C70
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerIteration::IncrementScore(idJobTimerIteration *this)
{
  int num; // r10
  int v3; // r10
  idJobTimerPhase *v4; // r11
  char v5; // r11
  bool v6; // zf
  int v7; // r10
  int v8; // r10
  idJobTimerPhase *v9; // r11
  int v10; // r7

  num = this->phases.num;
  if ( num <= 0
    || (v3 = num, v4 = &this->phases.list[v3 - 1], &this->phases.list[v3] == (idJobTimerPhase *)68)
    || v4->starttime < 0
    || (v6 = v4->stoptime < 0, v5 = 1, !v6) )
  {
    v5 = 0;
  }
  if ( v5 == 0 )
    idLib::Warning(fmt: "idJobTimerIteration got call to IncrementScore while not runnig");
  v7 = this->phases.num;
  if ( v7 <= 0 || (v8 = v7, v9 = &this->phases.list[v8 - 1], &this->phases.list[v8] == (idJobTimerPhase *)68) )
  {
    idLib::Warning(fmt: "idJobTimerIteration got call to IncrementScore before it has begun. IGNORING.");
  }
  else
  {
    v10 = v9->moneyPerScore + v9->moneyGiven;
    ++v9->score;
    v9->moneyGiven = v10;
  }
}


// ========================================================================
// ?GiveMoney@idJobTimerIteration@@QAAXH@Z
// EA  : 0x82E14D70
// RVA : 0x00E14D70
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerIteration::GiveMoney(idJobTimerIteration *this, int cash)
{
  int num; // r11
  idJobTimerPhase *v5; // r11
  char v6; // r11
  bool v7; // zf
  int v8; // r10
  int v9; // r10
  idJobTimerPhase *v10; // r11
  int v11; // r8

  num = this->phases.num;
  if ( num <= 0
    || (v5 = &this->phases.list[num - 1]) == nullptr
    || v5->starttime < 0
    || (v7 = v5->stoptime < 0, v6 = 1, !v7) )
  {
    v6 = 0;
  }
  if ( v6 == 0 )
    idLib::Warning(fmt: "idJobTimerIteration got call to GiveMoney while not runnig");
  v8 = this->phases.num;
  if ( v8 <= 0 || (v9 = v8, v10 = &this->phases.list[v9 - 1], &this->phases.list[v9] == (idJobTimerPhase *)68) )
  {
    idLib::Warning(fmt: "idJobTimerIteration got call to GiveMoney before it has begun. IGNORING.");
  }
  else
  {
    v11 = v10->moneyGivenDirectly + cash;
    v10->moneyGiven += cash;
    v10->moneyGivenDirectly = v11;
  }
}


// ========================================================================
// ?CompleteIteration@idJobTimerManager@@QAAXPBVidDeclJobTimerEvent@@PBVidDeclJob@@PAVidPlayer@@@Z
// EA  : 0x82E14E68
// RVA : 0x00E14E68
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::CompleteIteration(
        idJobTimerManager *this,
        const idDeclJobTimerEvent *inEventDecl,
        const idDeclJob *inJobDecl,
        idPlayer *player)
{
  int num; // r11
  idJobTimerIteration *v6; // r5
  idPlayer *v7; // r6
  idJobTimerIteration *v8; // r5

  if ( this->active )
  {
    num = this->iterations.num;
    if ( num <= 0 )
      v6 = nullptr;
    else
      v6 = &this->iterations.list[num - 1];
    if ( (unsigned __int8)idJobTimerIteration::IsRunning(this: v6) != 0 )
      idJobTimerIteration::StopTimer(this: v8, player: v7);
    this->active = false;
  }
  else if ( player != nullptr && !player->jobManager.inDebug )
  {
    idLib::Warning(
      fmt: "idJobTimerManager got call to completeIteration when not actually running.  IGNORING",
      inEventDecl,
      inJobDecl);
  }
}


// ========================================================================
// ?StopTimer@idJobTimerManager@@QAAXPAVidPlayer@@@Z
// EA  : 0x82E14F20
// RVA : 0x00E14F20
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::StopTimer(idJobTimerManager *this, idPlayer *player)
{
  int num; // r11
  idJobTimerIteration *v3; // r3

  if ( this->active )
  {
    num = this->iterations.num;
    if ( num <= 0 )
      v3 = nullptr;
    else
      v3 = &this->iterations.list[num - 1];
    idJobTimerIteration::StopTimer(this: v3, player);
  }
  else
  {
    idLib::Warning(fmt: "idJobTimerManager got call to StopTimer when not actually running.  IGNORING", player);
  }
}


// ========================================================================
// ?IncrementScore@idJobTimerManager@@QAAXXZ
// EA  : 0x82E14F60
// RVA : 0x00E14F60
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::IncrementScore(idJobTimerManager *this)
{
  int num; // r11

  if ( this->active )
  {
    num = this->iterations.num;
    if ( num <= 0 )
      idJobTimerIteration::IncrementScore(this: nullptr);
    else
      idJobTimerIteration::IncrementScore(this: &this->iterations.list[num - 1]);
  }
  else
  {
    idLib::Warning(fmt: "idJobTimerManager got call to IncrementScore when not actually running.  IGNORING");
  }
}


// ========================================================================
// ?GiveMoney@idJobTimerManager@@QAAXHPAVidPlayer@@@Z
// EA  : 0x82E14FA0
// RVA : 0x00E14FA0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::GiveMoney(idJobTimerManager *this, int cash, idPlayer *player)
{
  int num; // r11
  idJobTimerIteration *v4; // r3

  if ( this->active )
  {
    num = this->iterations.num;
    if ( num <= 0 )
      v4 = nullptr;
    else
      v4 = &this->iterations.list[num - 1];
    idJobTimerIteration::GiveMoney(this: v4, cash);
  }
  else
  {
    idLib::Warning(fmt: "idJobTimerManager got call to GiveMoney when not actually running.  IGNORING", cash, player);
  }
}


// ========================================================================
// ?ClearJobNotes@idJobManager@@QAAXXZ
// EA  : 0x82E14FE0
// RVA : 0x00E14FE0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::ClearJobNotes(idJobManager *this)
{
  int v2; // r29
  int v3; // r30
  idJob *v4; // r31
  idJobNoteTracker **list; // r4

  v2 = 0;
  if ( this->jobs.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->jobs.list[v3];
      if ( v4->jobNotes.listStatic == 0 || v4->jobNotes.listStatic == 2 )
      {
        list = v4->jobNotes.list;
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        v4->jobNotes.list = nullptr;
        v4->jobNotes.size = 0;
      }
      ++v2;
      v4->jobNotes.num = 0;
      ++v3;
    }
    while ( v2 < this->jobs.num );
  }
}


// ========================================================================
// ?NotifyInventorySold@idJobManager@@QAAXPBVidDeclInventory@@@Z
// EA  : 0x82E15070
// RVA : 0x00E15070
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::NotifyInventorySold(idJobManager *this, const idDeclJob *itemdecl)
{
  int v4; // r25
  int v5; // r27
  idJob *v6; // r11
  const idDeclJob *decl; // r29
  missionStatus_t status; // r11
  char v9; // r11
  bool v10; // zf
  int i; // r30
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3
  const idDeclJob::jobComplete_t *v13; // r31
  idJob *OwnerInventoryItemByDecl; // r3

  if ( itemdecl != nullptr && this->owner != nullptr )
  {
    v4 = 0;
    if ( this->jobs.num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = this->jobs.list[v5];
        decl = v6->decl;
        if ( decl->jobType == JOBTYPE_REPEATING )
          goto LABEL_10;
        status = v6->status;
        if ( status == JOBSTATUS_READYTOTURNIN || (v10 = status != JOBSTATUS_READYTOTURNIN_UNKNOWN, v9 = 0, !v10) )
          v9 = 1;
        if ( v9 != 0 )
        {
LABEL_10:
          for ( i = 0; i < idDeclJob::GetNumCompletionRequirements(this: decl); ++i )
          {
            CompletionRequirement = idDeclJob::GetCompletionRequirement(this: decl, idx: i);
            v13 = CompletionRequirement;
            if ( CompletionRequirement->completion == JOBCOMPLETE_ITEM
              && (const idDeclJob *)CompletionRequirement->inventoryDecl == itemdecl )
            {
              OwnerInventoryItemByDecl = idJobManager::GetOwnerInventoryItemByDecl(this, decl: itemdecl);
              if ( OwnerInventoryItemByDecl == nullptr
                || ((int (__fastcall *)(idJob *))OwnerInventoryItemByDecl->__vftable[2].dtr_idClass)(a1: OwnerInventoryItemByDecl) < v13->count )
              {
                idJob::SetJobStatus(
                  this: this->jobs.list[v5],
                  newStatus: JOBSTATUS_ACCEPTED,
                  manager: this,
                  fireOffJobTargets: false,
                  debug: false);
              }
            }
          }
        }
        ++v4;
        ++v5;
      }
      while ( v4 < this->jobs.num );
    }
  }
}


// ========================================================================
// ?IsJobAvailable@idJobManager@@QBA_NPBVidDeclJob@@@Z
// EA  : 0x82E151A8
// RVA : 0x00E151A8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::IsJobAvailable(idJobManager *this, const idDeclJob *jobDecl)
{
  int i; // r29
  const idDeclJob::jobPreCondition_t *JobPrecondition; // r3
  idDeclJob::jobPreConditionType_t precondition; // r11
  const idDeclJob::jobPreCondition_t *v8; // r31
  idJob *InventoryItemByDeclName; // r3
  idDeclJob::jobPreConditionStatus_t jobStatus; // r11
  missionStatus_t status; // r11
  missionStatus_t v12; // r11
  const idDeclJob *inventoryDecl; // r4
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  idJob *OwnerInventoryItemByDecl; // r3
  bool v17; // cr56
  const idDeclGameStateInt *gameStateIntDecl; // r4
  idStrId *v19; // r3
  const char *v20; // r3
  char v21; // [sp+50h] [-40h] BYREF
  char v22; // [sp+54h] [-3Ch] BYREF

  if ( jobDecl == nullptr
    || (unsigned __int8)idGameLocal::IsDLCStateActive(this: gameLocal, dlcState: jobDecl->requiredDLC) == 0 )
  {
    return 0;
  }
  for ( i = 0; i < (int)idMapPatch::GetMaterial(hSSMDev: jobDecl); ++i )
  {
    JobPrecondition = idDeclJob::GetJobPrecondition(this: jobDecl, idx: i);
    precondition = JobPrecondition->precondition;
    v8 = JobPrecondition;
    if ( JobPrecondition->precondition == JOBPRECONDITION_JOB )
    {
      InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                  this,
                                  jobName: JobPrecondition->jobDecl.data);
      if ( InventoryItemByDeclName == nullptr )
        return 0;
      jobStatus = v8->jobStatus;
      switch ( jobStatus )
      {
        case JOBPRECONDITIONSTATUS_COMPLETED:
          if ( InventoryItemByDeclName->status != JOBSTATUS_COMPLETED )
            return 0;
          break;
        case JOBPRECONDITIONSTATUS_READYTOTURNIN:
          status = InventoryItemByDeclName->status;
          if ( status != JOBSTATUS_COMPLETED
            && status != JOBSTATUS_READYTOTURNIN
            && status != JOBSTATUS_READYTOTURNIN_UNKNOWN )
          {
            return 0;
          }
          break;
        case JOBPRECONDITIONSTATUS_ACCEPTED:
          v12 = InventoryItemByDeclName->status;
          if ( v12 != JOBSTATUS_COMPLETED
            && v12 != JOBSTATUS_READYTOTURNIN
            && v12 != JOBSTATUS_ACCEPTED
            && v12 != JOBSTATUS_READYTOTURNIN_UNKNOWN )
          {
            return 0;
          }
          break;
        default:
          return 0;
      }
    }
    else if ( precondition == JOBPRECONDITION_ITEM )
    {
      inventoryDecl = (const idDeclJob *)JobPrecondition->inventoryDecl;
      if ( inventoryDecl != nullptr )
      {
        OwnerInventoryItemByDecl = idJobManager::GetOwnerInventoryItemByDecl(this, decl: inventoryDecl);
        if ( OwnerInventoryItemByDecl == nullptr )
          return 0;
        v17 = ((int (__fastcall *)(idJob *))OwnerInventoryItemByDecl->__vftable[2].dtr_idClass)(a1: OwnerInventoryItemByDecl) < v8->count;
LABEL_30:
        if ( v17 )
          return 0;
        continue;
      }
      JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v21, result: (idStrId *)jobDecl);
      LocalizedString = idStrId::GetLocalizedString(this: JobName);
      idLib::Warning(fmt: "Job %s has item based precondition no item is defined on the job", LocalizedString);
    }
    else if ( precondition == JOBPRECONDITION_GAMESTATEINT )
    {
      gameStateIntDecl = JobPrecondition->gameStateIntDecl;
      if ( gameStateIntDecl != nullptr )
      {
        v17 = idJobManager::GetGameStateIntValue(this, gameState: gameStateIntDecl) < JobPrecondition->count;
        goto LABEL_30;
      }
      v19 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v22, result: (idStrId *)jobDecl);
      v20 = idStrId::GetLocalizedString(this: v19);
      idLib::Warning(fmt: "Job %s has gamestateint based precondition no decl is defined on the job", v20);
    }
  }
  return 1;
}


// ========================================================================
// ?JobMeetsCompletionCriteria@idJobManager@@QBA_NPBVidDeclJob@@@Z
// EA  : 0x82E15380
// RVA : 0x00E15380
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::JobMeetsCompletionCriteria(idJobManager *this, const idDeclJob *jobDecl)
{
  int v4; // r28
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3
  idDeclJob::jobCompleteType_t completion; // r11
  const idDeclJob::jobComplete_t *v7; // r31
  const idDeclJob *inventoryDecl; // r4
  idStrId *v9; // r3
  const char *v10; // r3
  idJob *OwnerInventoryItemByDecl; // r3
  bool v12; // cr56
  idJob *JobByDecl; // r3
  missionStatus_t status; // r11
  idJob *v16; // r3
  idJob *InventoryItemByDeclName; // r3
  const idDeclGameStateInt *gameStateIntDecl; // r4
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  char v21; // [sp+50h] [-40h] BYREF
  char v22; // [sp+54h] [-3Ch] BYREF

  v4 = 0;
  if ( idDeclJob::GetNumCompletionRequirements(this: jobDecl) > 0 )
  {
    while ( 1 )
    {
      CompletionRequirement = idDeclJob::GetCompletionRequirement(this: jobDecl, idx: v4);
      completion = CompletionRequirement->completion;
      v7 = CompletionRequirement;
      if ( CompletionRequirement->completion == JOBCOMPLETE_ITEM )
        break;
      if ( completion == JOBCOMPLETE_TRIGGER )
      {
        JobByDecl = idJobManager::FindJobByDecl(this, jobDecl);
        if ( JobByDecl == nullptr )
          return 0;
        status = JobByDecl->status;
        if ( status != JOBSTATUS_READYTOTURNIN && status != JOBSTATUS_READYTOTURNIN_UNKNOWN )
          return 0;
      }
      else
      {
        if ( completion != JOBCOMPLETE_JOB )
        {
          if ( completion == JOBCOMPLETE_JOB_ACCEPTED )
          {
            InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                        this,
                                        jobName: CompletionRequirement->jobDecl.data);
            if ( InventoryItemByDeclName == nullptr )
              return 0;
            v12 = InventoryItemByDeclName->status < JOBSTATUS_ACCEPTED;
          }
          else
          {
            if ( completion != JOBCOMPLETE_GAMESTATEINT )
              goto LABEL_24;
            gameStateIntDecl = CompletionRequirement->gameStateIntDecl;
            if ( gameStateIntDecl == nullptr )
            {
              JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v22, result: (idStrId *)jobDecl);
              LocalizedString = idStrId::GetLocalizedString(this: JobName);
              idLib::Warning(
                fmt: "Job %s has gamestateint based completion but no gamestate is defined on the job",
                LocalizedString);
              goto LABEL_24;
            }
            v12 = idJobManager::GetGameStateIntValue(this, gameState: gameStateIntDecl) < CompletionRequirement->count;
          }
LABEL_23:
          if ( v12 )
            return 0;
          goto LABEL_24;
        }
        v16 = idInventoryCollection::FindInventoryItemByDeclName(this, jobName: CompletionRequirement->jobDecl.data);
        if ( v16 == nullptr || v16->status != JOBSTATUS_COMPLETED )
          return 0;
      }
LABEL_24:
      if ( ++v4 >= idDeclJob::GetNumCompletionRequirements(this: jobDecl) )
        return 1;
    }
    inventoryDecl = (const idDeclJob *)CompletionRequirement->inventoryDecl;
    if ( inventoryDecl == nullptr )
    {
      v9 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v21, result: (idStrId *)jobDecl);
      v10 = idStrId::GetLocalizedString(this: v9);
      idLib::Warning(fmt: "Job %s has item based completion but no item is defined on the job", v10);
      goto LABEL_24;
    }
    OwnerInventoryItemByDecl = idJobManager::GetOwnerInventoryItemByDecl(this, decl: inventoryDecl);
    if ( OwnerInventoryItemByDecl == nullptr )
      return 0;
    v12 = ((int (__fastcall *)(idJob *))OwnerInventoryItemByDecl->__vftable[2].dtr_idClass)(a1: OwnerInventoryItemByDecl) < v7->count;
    goto LABEL_23;
  }
  return 1;
}


// ========================================================================
// ?IsJobReadyToComplete@idJobManager@@QBA_NPBVidDeclJob@@PBVidAI2@@@Z
// EA  : 0x82E15528
// RVA : 0x00E15528
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::IsJobReadyToComplete(idJobManager *this, const idDeclJob *jobDecl, const idAI2 *npc)
{
  int i; // r28
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3
  idDeclJob::jobCompleteType_t completion; // r11
  const idDeclJob::jobComplete_t *v9; // r31
  const idDeclJob *inventoryDecl; // r4
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  idJob *OwnerInventoryItemByDecl; // r3
  bool v14; // cr56
  idJob *JobByDecl; // r3
  missionStatus_t status; // r11
  idJob *InventoryItemByDeclName; // r3
  idJob *v18; // r3
  const idDeclGameStateInt *gameStateIntDecl; // r4
  idStrId *v20; // r3
  const char *v21; // r3
  char v22; // [sp+50h] [-40h] BYREF
  char v23; // [sp+54h] [-3Ch] BYREF

  if ( npc != nullptr && (unsigned __int8)idDeclJob::AIMatchesJobCompleteNPC(this: jobDecl, inAI2: npc) == 0 )
    return 0;
  for ( i = 0; i < idDeclJob::GetNumCompletionRequirements(this: jobDecl); ++i )
  {
    CompletionRequirement = idDeclJob::GetCompletionRequirement(this: jobDecl, idx: i);
    completion = CompletionRequirement->completion;
    v9 = CompletionRequirement;
    if ( CompletionRequirement->completion == JOBCOMPLETE_ITEM )
    {
      inventoryDecl = (const idDeclJob *)CompletionRequirement->inventoryDecl;
      if ( inventoryDecl != nullptr )
      {
        OwnerInventoryItemByDecl = idJobManager::GetOwnerInventoryItemByDecl(this, decl: inventoryDecl);
        if ( OwnerInventoryItemByDecl == nullptr )
          return 0;
        v14 = ((int (__fastcall *)(idJob *))OwnerInventoryItemByDecl->__vftable[2].dtr_idClass)(a1: OwnerInventoryItemByDecl) < v9->count;
        goto LABEL_26;
      }
      JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v22, result: (idStrId *)jobDecl);
      LocalizedString = idStrId::GetLocalizedString(this: JobName);
      idLib::Warning(fmt: "Job %s has item based completion but no item is defined on the job", LocalizedString);
    }
    else
    {
      switch ( completion )
      {
        case JOBCOMPLETE_TRIGGER:
          JobByDecl = idJobManager::FindJobByDecl(this, jobDecl);
          if ( JobByDecl == nullptr )
            return 0;
          status = JobByDecl->status;
          if ( status != JOBSTATUS_READYTOTURNIN && status != JOBSTATUS_READYTOTURNIN_UNKNOWN )
            return 0;
          break;
        case JOBCOMPLETE_JOB:
          InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                      this,
                                      jobName: CompletionRequirement->jobDecl.data);
          if ( InventoryItemByDeclName == nullptr || InventoryItemByDeclName->status != JOBSTATUS_COMPLETED )
            return 0;
          break;
        case JOBCOMPLETE_JOB_ACCEPTED:
          v18 = idInventoryCollection::FindInventoryItemByDeclName(this, jobName: CompletionRequirement->jobDecl.data);
          if ( v18 == nullptr )
            return 0;
          v14 = v18->status < JOBSTATUS_ACCEPTED;
LABEL_26:
          if ( v14 )
            return 0;
          break;
        case JOBCOMPLETE_GAMESTATEINT:
          gameStateIntDecl = CompletionRequirement->gameStateIntDecl;
          if ( gameStateIntDecl != nullptr )
          {
            v14 = idJobManager::GetGameStateIntValue(this, gameState: gameStateIntDecl) < CompletionRequirement->count;
            goto LABEL_26;
          }
          v20 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v23, result: (idStrId *)jobDecl);
          v21 = idStrId::GetLocalizedString(this: v20);
          idLib::Warning(fmt: "Job %s has gamestateint based completion but no gamestate is defined on the job", v21);
          break;
        default:
          break;
      }
    }
  }
  return 1;
}


// ========================================================================
// ?SetActiveJob@idJobManager@@QAAXPBVidDeclJob@@_N@Z
// EA  : 0x82E156F0
// RVA : 0x00E156F0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::SetActiveJob(idJobManager *this, const idDeclJob *decl, bool checkImportance)
{
  int num; // r8
  int v7; // r10
  int v8; // r11

  if ( decl != nullptr && (unsigned __int8)idDeclJob::IsQuestJob(this: decl) != 0 )
  {
    num = this->jobs.num;
    v7 = 0;
    if ( num <= 0 )
    {
LABEL_7:
      v7 = -1;
    }
    else
    {
      v8 = 0;
      while ( this->jobs.list[v8]->decl != decl )
      {
        ++v7;
        ++v8;
        if ( v7 >= num )
          goto LABEL_7;
      }
    }
    idJobManager::SetActiveJobIndex(this, jobIndex: v7, checkImportance);
  }
}


// ========================================================================
// ?CheckActiveJobVersusRelevantJobs@idJobManager@@QAAXABV?$idList@VidDeclJobRef@@$04@@@Z
// EA  : 0x82E15778
// RVA : 0x00E15778
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::CheckActiveJobVersusRelevantJobs(
        idJobManager *this,
        const idList<idDeclJobRef,5> *relevantJobs)
{
  idJob *ActiveJob; // r28
  int v5; // r29
  int v6; // r31
  int v7; // r28
  int i; // r29
  idJob *InventoryItemByDeclName; // r3
  idJob *v10; // r31
  missionStatus_t status; // r11
  char v12; // r11
  bool v13; // zf
  const idDeclJob *decl; // r31
  idPlayerHud *PlayerHud; // r3

  if ( relevantJobs->num > 0 )
  {
    ActiveJob = idJobManager::GetActiveJob(this);
    if ( ActiveJob != nullptr && (v5 = 0, relevantJobs->num > 0) )
    {
      v6 = 0;
      while ( idStr::Icmp(s1: ActiveJob->decl->name.str, s2: relevantJobs->list[v6].data) != 0 )
      {
        ++v5;
        ++v6;
        if ( v5 >= relevantJobs->num )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      v7 = 0;
      if ( relevantJobs->num > 0 )
      {
        for ( i = 0; ; ++i )
        {
          InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                      this,
                                      jobName: relevantJobs->list[i].data);
          v10 = InventoryItemByDeclName;
          if ( InventoryItemByDeclName != nullptr )
          {
            status = InventoryItemByDeclName->status;
            if ( status == JOBSTATUS_READYTOTURNIN || (v13 = status != JOBSTATUS_ACCEPTED, v12 = 0, !v13) )
              v12 = 1;
            if ( v12 != 0 )
              break;
          }
          if ( ++v7 >= relevantJobs->num )
            return;
        }
        idJobManager::SetActiveJob(this, decl: InventoryItemByDeclName->decl, checkImportance: false);
        if ( !this->inDebug
          && this->owner != nullptr
          && (v10->status != JOBSTATUS_NONE || (unsigned __int8)idDeclJob::UseDynamicJobHud(this: v10->decl) != 0) )
        {
          decl = v10->decl;
          PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: this->owner);
          idPlayerHud::UpdateJob(
            this: PlayerHud,
            jobDecl: decl,
            requirementNum: -1,
            playSound: true,
            treatAsSameStatusUpdate: false);
        }
      }
    }
  }
}


// ========================================================================
// ?CheckActiveJobVersusMap@idJobManager@@QAAXXZ
// EA  : 0x82E158E0
// RVA : 0x00E158E0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::CheckActiveJobVersusMap(idJobManager *this)
{
  const char *v2; // r3
  idJob *ActiveJob; // r3
  int v4; // r28
  int v5; // r29
  idJob **v6; // r11
  missionStatus_t status; // r10
  char v8; // r10
  bool v9; // zf
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  v2 = gameLocal->GetMapName(this: gameLocal);
  idStr::idStr(this: v10, text: v2);
  ActiveJob = idJobManager::GetActiveJob(this);
  if ( ActiveJob == nullptr || (unsigned __int8)idJob::JobCaresAboutCurrentMap(this: ActiveJob) == 0 )
  {
    v4 = 0;
    if ( this->jobs.num > 0 )
    {
      v5 = 0;
      while ( 1 )
      {
        v6 = &this->jobs.list[v5];
        if ( *v6 != nullptr )
        {
          status = (*v6)->status;
          if ( status == JOBSTATUS_READYTOTURNIN || (v9 = status != JOBSTATUS_ACCEPTED, v8 = 0, !v9) )
            v8 = 1;
          if ( v8 != 0 && (unsigned __int8)idJob::JobCaresAboutCurrentMap(this: *v6) != 0 )
            break;
        }
        ++v4;
        ++v5;
        if ( v4 >= this->jobs.num )
          goto LABEL_12;
      }
      idJobManager::SetActiveJob(this, decl: this->jobs.list[v4]->decl, checkImportance: false);
      if ( !this->inDebug )
        idJobManager::UpdatePlayerHud(
          this,
          job: this->jobs.list[v4],
          requirementNum: -1,
          playSound: true,
          treatAsSameStatusUpdate: false);
    }
  }
LABEL_12:
  idStr::FreeData(this: v10);
}


// ========================================================================
// __unwind$508196
// EA  : 0x82E15A1C
// RVA : 0x00E15A1C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_508196()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?RemoveJob@idJobManager@@QAA_NPBVidDeclJob@@_N@Z
// EA  : 0x82E15A48
// RVA : 0x00E15A48
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::RemoveJob(idJobManager *this, const idDeclJob *jobDecl, bool resetTriggeredCount)
{
  idJob *JobByDecl; // r31
  idStrId *v8; // r4
  BOOL inDebug; // r28
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  int v12; // r26
  int v13; // r10
  int v14; // r11
  idPlayer *owner; // r3
  int v16; // r31
  char *v17; // r9
  int *p_statAmount; // r10
  int i; // ctr
  idStrId *v20; // r3
  const char *v21; // r4
  idStrId *v22; // r3
  const char *v23; // r4
  char v24; // [sp+50h] [-90h] BYREF
  char v25; // [sp+54h] [-8Ch] BYREF
  char v26; // [sp+5Ch] [-84h] BYREF
  int v27; // [sp+60h] [-80h]
  int v28; // [sp+78h] [-68h]

  if ( jobDecl == nullptr )
  {
    idLib::Warning(fmt: "NULL jobDecl in RemoveJob");
    return 0;
  }
  JobByDecl = idJobManager::FindJobByDecl(this, jobDecl);
  if ( JobByDecl == nullptr )
    return 0;
  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    inDebug = this->inDebug;
    JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v24, result: v8);
    LocalizedString = idStrId::GetLocalizedString(this: JobName);
    idLib::Printf(fmt: "RemoveJob %s, debug: %d\n", LocalizedString, inDebug);
  }
  v12 = 0;
  if ( resetTriggeredCount )
    JobByDecl->triggeredCount = 0;
  idJob::SetJobStatus(
    this: JobByDecl,
    newStatus: JOBSTATUS_NONE,
    manager: this,
    fireOffJobTargets: true,
    debug: this->inDebug);
  v13 = 0;
  if ( this->jobs.num <= 0 )
  {
LABEL_13:
    v13 = -1;
  }
  else
  {
    v14 = 0;
    while ( this->jobs.list[v14]->decl != jobDecl )
    {
      ++v13;
      ++v14;
      if ( v13 >= this->jobs.num )
        goto LABEL_13;
    }
  }
  if ( this->activeJobIndex == v13 )
    idJobManager::SetActiveJobIndexForNextActiveJob(this);
  owner = this->owner;
  if ( owner != nullptr && owner->GetInventory_2(this: owner) != nullptr && jobDecl->acceptRewards.num > 0 )
  {
    v16 = 0;
    do
    {
      v17 = &v26;
      p_statAmount = &jobDecl->acceptRewards.list[v16 - 1].statAmount;
      for ( i = 9; i != 0; --i )
      {
        ++p_statAmount;
        v17 += 4;
        *(_DWORD *)v17 = *p_statAmount;
      }
      if ( v27 == 10 )
      {
        if ( v28 == 2 )
        {
          idPlayer::SetKeysGarage(this: this->owner, garage: GARAGE_SUBWAYTOWN);
          this->newVehicleGarage = GARAGE_SUBWAYTOWN;
          v20 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v24, result: (idStrId *)jobDecl);
          v21 = idStrId::GetLocalizedString(this: v20);
          idLib::Warning(fmt: "Set to Subway from %s:", v21);
        }
        else if ( v28 == 3 )
        {
          idPlayer::SetKeysGarage(this: this->owner, garage: GARAGE_WELLSPRING);
          this->newVehicleGarage = GARAGE_WELLSPRING;
          v22 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v25, result: (idStrId *)jobDecl);
          v23 = idStrId::GetLocalizedString(this: v22);
          idLib::Warning(fmt: "Set to Wellspring from %s:", v23);
        }
      }
      ++v12;
      ++v16;
    }
    while ( v12 < jobDecl->acceptRewards.num );
  }
  return 1;
}


// ========================================================================
// ?RemoveDynamicJobs@idJobManager@@QAA_NXZ
// EA  : 0x82E15C60
// RVA : 0x00E15C60
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::RemoveDynamicJobs(idJobManager *this)
{
  idPlayer *owner; // r11
  int v3; // r28
  char v4; // r27
  idPresentable *presentable; // r3
  int v6; // r3
  idPresentable *v7; // r11
  int v8; // r3
  int v9; // r29
  int v10; // r30
  idJob *v11; // r11
  idPlayer *v12; // r11
  idPresentable *v13; // r3
  int v14; // r3

  owner = this->owner;
  v3 = 0;
  v4 = 0;
  if ( owner != nullptr )
  {
    presentable = owner->presentable;
    if ( presentable != nullptr )
      v6 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v6 = 0;
    v7 = this->owner->presentable;
    v4 = *(_BYTE *)(v6 + 35105);
    if ( v7 != nullptr )
      v8 = (int)v7->GetPlayerInterface_2(this: this->owner->presentable);
    else
      v8 = 0;
    idPlayerHud::SetIgnoreJobUpdates(this: (idPlayerHud *)(v8 + 35096), ignore: true);
  }
  v9 = 0;
  if ( this->jobs.num > 0 )
  {
    v10 = 0;
    do
    {
      if ( (unsigned __int8)idDeclJob::UseDynamicJobHud(this: this->jobs.list[v10]->decl) != 0 )
      {
        v11 = this->jobs.list[v10];
        if ( v11->status != JOBSTATUS_COMPLETED )
          v3 = (unsigned __int8)idJobManager::RemoveJob(this, jobDecl: v11->decl, resetTriggeredCount: false)
             | (unsigned __int8)v3;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < this->jobs.num );
  }
  v12 = this->owner;
  if ( v12 != nullptr )
  {
    v13 = v12->presentable;
    if ( v13 != nullptr )
      v14 = (int)v13->GetPlayerInterface_2(this: v13);
    else
      v14 = 0;
    idPlayerHud::SetIgnoreJobUpdates(this: (idPlayerHud *)(v14 + 35096), ignore: v4);
  }
  return v3;
}


// ========================================================================
// ?RemoveDiscSwappingJobs@idJobManager@@QAAXXZ
// EA  : 0x82E15DB0
// RVA : 0x00E15DB0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::RemoveDiscSwappingJobs(idJobManager *this)
{
  int v2; // r29
  int v3; // r31
  idJob *v4; // r10
  missionStatus_t status; // r11
  char v6; // r11
  bool v7; // zf
  const idDeclJob *decl; // r4

  v2 = this->jobs.num - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      v4 = this->jobs.list[v3];
      status = v4->status;
      if ( status == JOBSTATUS_READYTOTURNIN || (v7 = status != JOBSTATUS_ACCEPTED, v6 = 0, !v7) )
        v6 = 1;
      if ( v6 != 0 )
      {
        decl = v4->decl;
        if ( decl->discSwappingJob || decl->jobAutoTransitionInfo.acceptSpawnInfo.mapName.len != 0 )
          idJobManager::RemoveJob(this, jobDecl: decl, resetTriggeredCount: true);
      }
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
}


// ========================================================================
// ?StartRemovalOfDynamicJob@idJobManager@@QAA_NPBVidDeclJob@@@Z
// EA  : 0x82E15E40
// RVA : 0x00E15E40
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::StartRemovalOfDynamicJob(idJobManager *this, const idDeclJob *jobDecl)
{
  int num; // r8
  int v3; // r10
  idJob **list; // r9
  int i; // r11
  idJob *v7; // r11
  missionStatus_t status; // r11
  char v9; // r11
  bool v10; // zf

  num = this->jobs.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  list = this->jobs.list;
  for ( i = 0; list[i]->decl != jobDecl; ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  v7 = list[v3];
  if ( v7 == nullptr )
    return 0;
  status = v7->status;
  if ( status == JOBSTATUS_READYTOTURNIN || (v10 = status != JOBSTATUS_ACCEPTED, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 != 0 )
    return idJobManager::RemoveJob(this, jobDecl, resetTriggeredCount: false);
  else
    return 0;
}


// ========================================================================
// ?GiveRewards@idJobManager@@QAAXABV?$idList@VjobReward_t@idDeclJob@@$04@@@Z
// EA  : 0x82E15EC0
// RVA : 0x00E15EC0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::GiveRewards(idJobManager *this, const idList<idDeclJob::jobReward_t,5> *rewards)
{
  int num; // r4
  int v5; // r28
  int v6; // r27
  char *v7; // r9
  int *p_statAmount; // r10
  int i; // ctr
  idPlayer *owner; // r4
  const idDeclInventory *v11; // r30
  int v12; // r31
  const idDeclFaction *v13; // r31
  const idDeclJob *v14; // r31
  const idDeclJob *v15; // r31
  const idDeclGameStateInt *v16; // r30
  int v17; // r31
  idPlayer *v18; // r3
  garageList_t v19; // r31
  const idDeclJob *v20; // r31
  idJob *v21; // r3
  missionStatus_t status; // r11
  char v23; // r11
  bool v24; // zf
  const idDeclJob *v25; // r4
  idJob *JobByDecl; // r3
  idJob *v27; // r31
  char v28; // [sp+4Ch] [-C4h] BYREF
  int v29; // [sp+50h] [-C0h]
  const idDeclInventory *v30; // [sp+54h] [-BCh]
  int v31; // [sp+58h] [-B8h]
  const idDeclFaction *v32; // [sp+5Ch] [-B4h]
  const idDeclJob *v33; // [sp+60h] [-B0h]
  const idDeclGameStateInt *v34; // [sp+64h] [-ACh]
  garageList_t v35; // [sp+68h] [-A8h]
  rageStat_t v36; // [sp+6Ch] [-A4h]
  int v37; // [sp+70h] [-A0h]

  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    num = rewards->num;
    if ( num > 0 )
      idLib::Printf(fmt: "\tGive Rewards: %d\n", num);
  }
  v5 = 0;
  if ( rewards->num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &v28;
      p_statAmount = &rewards->list[v6 - 1].statAmount;
      for ( i = 9; i != 0; --i )
      {
        ++p_statAmount;
        v7 += 4;
        *(_DWORD *)v7 = *p_statAmount;
      }
      if ( v36 != RAGE_STAT_INVALID )
      {
        owner = this->owner;
        if ( owner != nullptr )
          idRageMetrics::StatAddInt(this: clientGame->rageMetrics, player: owner, stat: v36, value: v37);
      }
      if ( v29 == 1 )
      {
        if ( !this->hackNoItemRewards )
        {
          v11 = v30;
          if ( v30 != nullptr )
          {
            v12 = v31;
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\t%d Item: %d: %s\n", v5, v31, v30->name.str);
            idJobManager::GiveOwnerInventoryItem(this, decl: v11, count: v12, canPlayIntroAnim: true);
          }
        }
        goto LABEL_67;
      }
      if ( v29 == 2 )
      {
        idJobManager::DeleteOwnerInventoryItem(this, decl: v30, count: v31);
      }
      else
      {
        if ( v29 == 3 )
        {
          v13 = v32;
          if ( v32 != nullptr && this->owner != nullptr )
          {
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\t%d Faction: %s\n", v5, v32->name.str);
            idActor::SetFaction(this: this->owner, faction: v13);
          }
          goto LABEL_67;
        }
        if ( v29 == 4 )
        {
          v14 = v33;
          if ( v33 != nullptr )
          {
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\t%d Job Complete: %s\n", v5, v33->name.str);
            idJobManager::CompleteJob(this, jobDecl: v14, completeTree: true, giveJob: true, force: false);
          }
          goto LABEL_67;
        }
        if ( v29 == 5 )
        {
          v15 = v33;
          if ( v33 != nullptr )
          {
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\t%d Job Accept: %s\n", v5, v33->name.str);
            idJobManager::AcceptJob(this, jobDecl: v15, completeTree: true, force: false);
          }
          goto LABEL_67;
        }
        if ( v29 == 9 )
        {
          v16 = v34;
          if ( v34 != nullptr )
          {
            v17 = v31;
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\t%d Game State Int: %s, %d\n", v5, v34->name.str, v31);
            idJobManager::SetGameStateIntValue(this, gameState: v16, stateValue: v17);
          }
          goto LABEL_67;
        }
        if ( v29 == 10 )
        {
          v18 = this->owner;
          v19 = v35;
          if ( v18 != nullptr && v18->GetInventory_2(this: v18) != nullptr )
            idPlayer::SetKeysGarage(this: this->owner, garage: v19);
          this->newVehicleGarage = v19;
          goto LABEL_67;
        }
        if ( v29 == 6 )
        {
          v20 = v33;
          if ( v33 != nullptr )
          {
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\t%d Job Remove: %s\n", v5, v33->name.str);
LABEL_59:
            idJobManager::RemoveJob(this, jobDecl: v20, resetTriggeredCount: true);
          }
        }
        else
        {
          if ( v29 != 7 )
          {
            if ( v29 == 8 )
            {
              this->useAlternateHands = true;
            }
            else if ( v29 == 11 && v33 != nullptr )
            {
              JobByDecl = idJobManager::FindJobByDecl(this, jobDecl: v33);
              v27 = JobByDecl;
              if ( JobByDecl != nullptr && (_cntlzw(JobByDecl->status - 2) & 0x20) != 0 )
              {
                idJobManager::SetActiveJob(this, decl: v25, checkImportance: false);
                idJobManager::UpdatePlayerHud(
                  this,
                  job: v27,
                  requirementNum: -1,
                  playSound: true,
                  treatAsSameStatusUpdate: true);
              }
            }
            goto LABEL_67;
          }
          v20 = v33;
          if ( v33 != nullptr )
          {
            if ( jobDebug_PrintChanges.valueInteger != 0 )
              idLib::Printf(fmt: "\t\t%d Job Remove In Progress: %s\n", v5, v33->name.str);
            v21 = idJobManager::FindJobByDecl(this, jobDecl: v20);
            if ( v21 != nullptr )
            {
              status = v21->status;
              if ( status == JOBSTATUS_READYTOTURNIN || (v24 = status != JOBSTATUS_ACCEPTED, v23 = 0, !v24) )
                v23 = 1;
              if ( v23 != 0 )
                goto LABEL_59;
            }
          }
        }
      }
LABEL_67:
      ++v5;
      ++v6;
    }
    while ( v5 < rewards->num );
  }
}


// ========================================================================
// ?RemoveCompletionConditions@idJobManager@@QAAXABV?$idList@VjobComplete_t@idDeclJob@@$04@@@Z
// EA  : 0x82E162F0
// RVA : 0x00E162F0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::RemoveCompletionConditions(
        idJobManager *this,
        const idList<idDeclJob::jobComplete_t,5> *completion)
{
  int num; // r4
  int v5; // r29
  int i; // r28
  idDeclJob::jobComplete_t *v7; // r30
  const idDeclGameStateInt *gameStateIntDecl; // r4
  idDeclJob::jobCompleteType_t v9; // [sp+60h] [-90h]
  const idDeclInventory *inventoryDecl; // [sp+64h] [-8Ch]
  int count; // [sp+68h] [-88h]
  bool removeInventory; // [sp+6Ch] [-84h]
  idStr v13; // [sp+74h] [-7Ch] BYREF
  const idDeclGameStateInt *v14; // [sp+94h] [-5Ch]

  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    num = completion->num;
    if ( num > 0 )
      idLib::Printf(fmt: "\tRemove Complete Conditions: %d\n", num);
  }
  v5 = 0;
  if ( completion->num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v7 = &completion->list[i];
      v9 = v7->completion;
      inventoryDecl = v7->inventoryDecl;
      count = v7->count;
      removeInventory = v7->removeInventory;
      idStr::idStr(this: &v13, text: &v7->jobDecl);
      gameStateIntDecl = v7->gameStateIntDecl;
      v14 = gameStateIntDecl;
      if ( v9 != JOBCOMPLETE_ITEM )
        goto LABEL_11;
      if ( removeInventory )
        break;
LABEL_17:
      idStr::FreeData(this: &v13);
      if ( ++v5 >= completion->num )
        return;
    }
    if ( jobDebug_PrintChanges.valueInteger != 0 )
      idLib::Printf(fmt: "\t\t%d Item: %d: %s\n", v5, count, inventoryDecl->name.str);
    idJobManager::DeleteOwnerInventoryItem(this, decl: inventoryDecl, count);
    gameStateIntDecl = v14;
LABEL_11:
    if ( v9 == JOBCOMPLETE_GAMESTATEINT && count == 1 && gameStateIntDecl != nullptr )
    {
      if ( jobDebug_PrintChanges.valueInteger != 0 )
      {
        idLib::Printf(fmt: "\t\t%d Game State Int: %s, %d  setting to zero\n", v5, gameStateIntDecl->name.str, 1);
        gameStateIntDecl = v14;
      }
      idJobManager::SetGameStateIntValue(this, gameState: gameStateIntDecl, stateValue: 0);
    }
    goto LABEL_17;
  }
}


// ========================================================================
// __unwind$509157
// EA  : 0x82E16478
// RVA : 0x00E16478
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509157()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(v0 - 240 + 96));
}


// ========================================================================
// ?FailJob@idJobManager@@QAA_NPBVidDeclJob@@@Z
// EA  : 0x82E164A0
// RVA : 0x00E164A0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::FailJob(idJobManager *this, const idDeclJob *jobDecl)
{
  int num; // r8
  int v5; // r10
  idJob **list; // r9
  int i; // r11
  idJob *v9; // r30
  int v10; // r9
  int v11; // r10
  int v12; // r11

  num = this->jobs.num;
  v5 = 0;
  if ( num <= 0 )
    return 0;
  list = this->jobs.list;
  for ( i = 0; list[i]->decl != jobDecl; ++i )
  {
    if ( ++v5 >= num )
      return 0;
  }
  v9 = list[v5];
  if ( v9 == nullptr || v9->status == JOBSTATUS_COMPLETED )
    return 0;
  idJob::SetJobStatus(this: list[v5], newStatus: JOBSTATUS_FAILED, manager: this, fireOffJobTargets: true, debug: false);
  v10 = this->jobs.num;
  v11 = 0;
  if ( v10 <= 0 )
  {
LABEL_13:
    v11 = -1;
  }
  else
  {
    v12 = 0;
    while ( this->jobs.list[v12]->decl != jobDecl )
    {
      ++v11;
      ++v12;
      if ( v11 >= v10 )
        goto LABEL_13;
    }
  }
  if ( this->activeJobIndex == v11 )
    idJobManager::SetActiveJobIndexForNextActiveJob(this);
  idJobManager::TransitionToNextPosition(this, job: v9);
  return 1;
}


// ========================================================================
// ??0idAIPlayerInteractionMemory@@QAA@XZ
// EA  : 0x82E165A8
// RVA : 0x00E165A8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idAIPlayerInteractionMemory *__fastcall idAIPlayerInteractionMemory::idAIPlayerInteractionMemory(
        idAIPlayerInteractionMemory *this)
{
  this->__vftable = (idAIPlayerInteractionMemory_vtbl *)&idAIPlayerInteractionMemory::`vftable';
  this->declName.len = 0;
  this->declName.allocedAndFlag = 20;
  this->declName.data = this->declName.baseBuffer;
  this->declName.baseBuffer[0] = 0;
  this->approachPlayedList.list = nullptr;
  this->approachPlayedList.granularity = 0;
  this->approachPlayedList.memTag = 5;
  this->approachPlayedList.listStatic = 0;
  this->approachPlayedList.size = 0;
  this->approachPlayedList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->approachPlayedList);
  this->jobOfferPlayedList.list = nullptr;
  this->jobOfferPlayedList.granularity = 0;
  this->jobOfferPlayedList.memTag = 5;
  this->jobOfferPlayedList.listStatic = 0;
  this->jobOfferPlayedList.size = 0;
  this->jobOfferPlayedList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobOfferPlayedList);
  return this;
}


// ========================================================================
// __unwind$509426
// EA  : 0x82E1663C
// RVA : 0x00E1663C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509426()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$509427
// EA  : 0x82E16664
// RVA : 0x00E16664
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509427()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$509428
// EA  : 0x82E16690
// RVA : 0x00E16690
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509428()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// ??0idAIPlayerInteractionMemory@@QAA@PBD@Z
// EA  : 0x82E166C8
// RVA : 0x00E166C8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idAIPlayerInteractionMemory *__fastcall idAIPlayerInteractionMemory::idAIPlayerInteractionMemory(
        idAIPlayerInteractionMemory *this,
        const char *interactionDeclName)
{
  idStr *p_declName; // r28

  p_declName = &this->declName;
  this->__vftable = (idAIPlayerInteractionMemory_vtbl *)&idAIPlayerInteractionMemory::`vftable';
  this->declName.len = 0;
  this->declName.data = this->declName.baseBuffer;
  this->declName.allocedAndFlag = 20;
  this->declName.baseBuffer[0] = 0;
  this->approachPlayedList.list = nullptr;
  this->approachPlayedList.granularity = 0;
  this->approachPlayedList.memTag = 5;
  this->approachPlayedList.listStatic = 0;
  this->approachPlayedList.size = 0;
  this->approachPlayedList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->approachPlayedList);
  this->jobOfferPlayedList.list = nullptr;
  this->jobOfferPlayedList.granularity = 0;
  this->jobOfferPlayedList.memTag = 5;
  this->jobOfferPlayedList.listStatic = 0;
  this->jobOfferPlayedList.size = 0;
  this->jobOfferPlayedList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobOfferPlayedList);
  idStr::operator=(this: p_declName, text: interactionDeclName);
  return this;
}


// ========================================================================
// __unwind$509489
// EA  : 0x82E16770
// RVA : 0x00E16770
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509489()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$509490
// EA  : 0x82E16798
// RVA : 0x00E16798
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509490()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// __unwind$509491
// EA  : 0x82E167C4
// RVA : 0x00E167C4
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509491()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 36));
}


// ========================================================================
// __unwind$509492
// EA  : 0x82E167F0
// RVA : 0x00E167F0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509492()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 52));
}


// ========================================================================
// ??1idAIPlayerInteractionMemory@@UAA@XZ
// EA  : 0x82E16828
// RVA : 0x00E16828
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idAIPlayerInteractionMemory::~idAIPlayerInteractionMemory(idAIPlayerInteractionMemory *this)
{
  this->__vftable = (idAIPlayerInteractionMemory_vtbl *)&idAIPlayerInteractionMemory::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobOfferPlayedList);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->approachPlayedList);
  idStr::FreeData(this: &this->declName);
  this->__vftable = (idAIPlayerInteractionMemory_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$509557
// EA  : 0x82E16890
// RVA : 0x00E16890
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509557()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$509558
// EA  : 0x82E168B8
// RVA : 0x00E168B8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509558()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$509559_0
// EA  : 0x82E168E4
// RVA : 0x00E168E4
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_509559_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// ?Create@idAIPlayerInteractionMemory@@SAPAV1@PBD@Z
// EA  : 0x82E16918
// RVA : 0x00E16918
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idAIPlayerInteractionMemory *__fastcall idAIPlayerInteractionMemory::Create(const char *interactionDeclName)
{
  idAIPlayerInteractionMemory *v2; // r3

  v2 = (idAIPlayerInteractionMemory *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                        size: 0x44u,
                                        tag: TAG_NEW,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    return idAIPlayerInteractionMemory::idAIPlayerInteractionMemory(this: v2, interactionDeclName);
  else
    return nullptr;
}


// ========================================================================
// __unwind$509602
// EA  : 0x82E16990
// RVA : 0x00E16990
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall _unwind_509602(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?ShouldDeliverJobCompleteVO@idJobManager@@QAA_NPAVidAI2@@@Z
// EA  : 0x82E169B8
// RVA : 0x00E169B8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::ShouldDeliverJobCompleteVO(idJobManager *this, idAI2 *ai)
{
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const idDeclJob *interactionJob; // r4
  const idDeclJob *v6; // r4
  idJob *JobByDecl; // r3
  missionStatus_t status; // r11
  char v9; // r11
  bool v10; // zf
  int result; // r3

  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  if ( CurrentPlayerInteraction == nullptr )
    return 0;
  interactionJob = CurrentPlayerInteraction->interactionJob;
  if ( interactionJob == nullptr )
    return 0;
  JobByDecl = idJobManager::FindJobByDecl(this, jobDecl: interactionJob);
  if ( JobByDecl == nullptr )
    return 0;
  status = JobByDecl->status;
  if ( status == JOBSTATUS_READYTOTURNIN || (v10 = status != JOBSTATUS_ACCEPTED, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 == 0 )
    return 0;
  v10 = (unsigned __int8)idJobManager::IsJobReadyToComplete(this, jobDecl: v6, npc: ai) != 0;
  result = 1;
  if ( !v10 )
    return 0;
  return result;
}


// ========================================================================
// ?UpdateJobTimers@idJobTimerManager@@QAAXPAVidPlayer@@@Z
// EA  : 0x82E16E90
// RVA : 0x00E16E90
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::UpdateJobTimers(idJobTimerManager *this, idPlayer *player)
{
  int num; // r6
  idJobTimerIteration *v5; // r11
  char IsRunning; // r3
  idJobTimerIteration *v7; // r11
  idJobTimerIteration *v8; // r31
  int v9; // r11
  int v10; // r11
  const idDeclJobTimerEvent *eventDecl; // r30

  if ( player == nullptr )
    idLib::Error(fmt: "invalid player");
  num = player->jobTimerManager.iterations.num;
  if ( num <= 0 || (v5 = &player->jobTimerManager.iterations.list[num]) == (idJobTimerIteration *)28 )
    IsRunning = 0;
  else
    IsRunning = idJobTimerIteration::IsRunning(this: v5 - 1);
  if ( IsRunning != 0 && num > 0 )
  {
    v7 = &player->jobTimerManager.iterations.list[num];
    v8 = v7 - 1;
    if ( v7 != (idJobTimerIteration *)28 )
    {
      v9 = v8->phases.num;
      if ( v9 > 0 )
      {
        v10 = (int)&v8->phases.list[v9];
        if ( v10 != 68 )
        {
          eventDecl = v8->eventDecl;
          if ( eventDecl != nullptr
            && eventDecl->countDownTimer
            && eventDecl->countDownTime - idJobTimerPhase::GetTime(this: (idJobTimerPhase *)(v10 - 68)) < 0 )
          {
            idJobManager::FailJob(this: &player->jobManager, jobDecl: v8->jobDecl);
            idJobTimerManager::CompleteIteration(this, inEventDecl: v8->eventDecl, inJobDecl: v8->jobDecl, player);
          }
        }
      }
    }
  }
}


// ========================================================================
// ??0idJobManager@@QAA@XZ
// EA  : 0x82E16F90
// RVA : 0x00E16F90
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJobManager *__fastcall idJobManager::idJobManager(idJobManager *this)
{
  this->jobs.list = nullptr;
  this->jobs.granularity = 0;
  this->jobs.memTag = 5;
  this->jobs.listStatic = 0;
  this->jobs.size = 0;
  this->jobs.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->specialEvent_Jumps.list = nullptr;
  this->specialEvent_Jumps.granularity = 0;
  this->specialEvent_Jumps.memTag = 5;
  this->specialEvent_Jumps.listStatic = 0;
  this->specialEvent_Jumps.size = 0;
  this->specialEvent_Jumps.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->specialEvent_Jumps);
  this->specialEventAreaDecl = nullptr;
  this->specialEventAreaTrackers.list = nullptr;
  this->specialEventAreaTrackers.granularity = 0;
  this->specialEventAreaTrackers.memTag = 5;
  this->specialEventAreaTrackers.listStatic = 0;
  this->specialEventAreaTrackers.size = 0;
  this->specialEventAreaTrackers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->specialEventAreaTrackers);
  this->playerInteractionMemories.list = nullptr;
  this->playerInteractionMemories.granularity = 0;
  this->playerInteractionMemories.memTag = 5;
  this->playerInteractionMemories.listStatic = 0;
  this->playerInteractionMemories.size = 0;
  this->playerInteractionMemories.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerInteractionMemories);
  this->gameStateInts.list = nullptr;
  this->gameStateInts.granularity = 0;
  this->gameStateInts.memTag = 5;
  this->gameStateInts.listStatic = 0;
  this->gameStateInts.size = 0;
  this->gameStateInts.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->gameStateInts);
  this->raceStatusMemories.list = nullptr;
  this->raceStatusMemories.granularity = 0;
  this->raceStatusMemories.memTag = 5;
  this->raceStatusMemories.listStatic = 0;
  this->raceStatusMemories.size = 0;
  this->raceStatusMemories.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->raceStatusMemories);
  this->dlcRewardsRecieved.granularity = 0;
  this->dlcRewardsRecieved.memTag = 5;
  this->dlcRewardsRecieved.listStatic = 0;
  this->dlcRewardsRecieved.list = nullptr;
  this->dlcRewardsRecieved.size = 0;
  this->dlcRewardsRecieved.num = 0;
  this->owner = nullptr;
  this->useAlternateHands = false;
  this->saveRequested = false;
  this->activeJobIndex = -1;
  this->inDebug = false;
  this->inInitState = false;
  this->hackNoItemRewards = false;
  this->hackIgnoreDebugRewards = false;
  this->hackIgnoreLayerChanges = false;
  this->newVehicleGarage = GARAGE_WELLSPRING;
  return this;
}


// ========================================================================
// __unwind$510350
// EA  : 0x82E170CC
// RVA : 0x00E170CC
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_510350()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$510351
// EA  : 0x82E170F4
// RVA : 0x00E170F4
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_510351()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$510352
// EA  : 0x82E17120
// RVA : 0x00E17120
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_510352()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// __unwind$510353
// EA  : 0x82E1714C
// RVA : 0x00E1714C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_510353()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// __unwind$510354
// EA  : 0x82E17178
// RVA : 0x00E17178
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_510354()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 68));
}


// ========================================================================
// __unwind$510355
// EA  : 0x82E171A4
// RVA : 0x00E171A4
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_510355()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 84));
}


// ========================================================================
// ?Clear@idJobManager@@QAAXXZ
// EA  : 0x82E171D0
// RVA : 0x00E171D0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::Clear(idJobManager *this)
{
  int v2; // r29
  int v3; // r30
  idJob *v4; // r3

  v2 = 0;
  if ( this->jobs.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->jobs.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idJob *, int))v4->dtr_idClass)(a1: v4, a2: 1);
      ++v2;
      this->jobs.list[v3++] = nullptr;
    }
    while ( v2 < this->jobs.num );
  }
  if ( this->jobs.listStatic == 0 || this->jobs.listStatic == 2 )
  {
    if ( this->jobs.list != nullptr )
      idMem::Free(this: &mem, ptr: this->jobs.list, align: ALIGN_16);
    this->jobs.list = nullptr;
    this->jobs.size = 0;
  }
  this->jobs.num = 0;
  idJobManager::ClearPlayerInteractionMemories(this);
  idJobManager::ClearGameStateInts(this);
  idJobManager::ClearJobNotes(this);
  idJobManager::ClearRaceStatusMemories(this);
}


// ========================================================================
// ?PlaySpecialEventNewAreaSound@idJobManager@@QAAXPBVidDeclSpecialEvent_Area@@@Z
// EA  : 0x82E172A8
// RVA : 0x00E172A8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::PlaySpecialEventNewAreaSound(
        idJobManager *this,
        idDeclSpecialEvent_Area::jobStinger_t *specialEventArea)
{
  int v2; // r25
  idSpecialEvent_Area_Tracker *v5; // r28
  int v6; // r29
  int v7; // r30
  int v8; // r30
  char v9; // r7
  int v10; // r10
  int v11; // r11
  idJob *InventoryItemByDeclName; // r3
  missionStatus_t status; // r11
  const idSoundShader *jobStinger; // r29
  idSpecialEvent_Area_Tracker *v15; // r3
  idSpecialEvent_Area_Tracker *v16; // r30
  const char *allocedAndFlag; // r4
  idPlayer *owner; // r11
  idPresentable *presentable; // r3
  int v20; // r3
  int v21; // [sp+50h] [-80h] BYREF
  idPlayer *num; // [sp+54h] [-7Ch] BYREF
  idStr v23; // [sp+60h] [-70h] BYREF
  missionStatus_t v24; // [sp+80h] [-50h]
  int v25; // [sp+84h] [-4Ch]
  const idSoundShader *v26; // [sp+88h] [-48h]

  v2 = *(_DWORD *)&specialEventArea[1].job.baseBuffer[16];
  if ( v2 <= 0 )
    goto LABEL_33;
  v5 = nullptr;
  v6 = 0;
  if ( this->specialEventAreaTrackers.num > 0 )
  {
    v7 = 0;
    while ( idStr::Icmp(
              s1: this->specialEventAreaTrackers.list[v7]->areaDecl.data,
              s2: (const char *)specialEventArea->job.allocedAndFlag) != 0 )
    {
      ++v6;
      ++v7;
      if ( v6 >= this->specialEventAreaTrackers.num )
        goto LABEL_8;
    }
    v5 = this->specialEventAreaTrackers.list[v6];
  }
LABEL_8:
  v8 = 0;
  v21 = 0;
  while ( 1 )
  {
    v9 = 1;
    if ( v5 != nullptr )
    {
      v10 = 0;
      num = (idPlayer *)v5->jobStingersPlayed.num;
      if ( (int)num > 0 )
      {
        v11 = 0;
        while ( v5->jobStingersPlayed.list[v11] != v8 )
        {
          ++v10;
          ++v11;
          if ( v10 >= (int)num )
            goto LABEL_16;
        }
        v9 = 0;
      }
    }
LABEL_16:
    if ( v9 != 0 )
    {
      idDeclSpecialEvent_Area::GetJobStinger(this: (idDeclSpecialEvent_Area *)&v23, result: specialEventArea, i: v8);
      if ( v23.len == 0 )
        break;
      InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(this, jobName: v23.data);
      status = JOBSTATUS_NONE;
      if ( InventoryItemByDeclName != nullptr )
        status = InventoryItemByDeclName->status;
      if ( status >= v24 && (v25 <= 0 || status <= v25) )
        break;
      idStr::FreeData(this: &v23);
    }
    if ( ++v8 >= v2 )
    {
      v21 = v8;
      goto LABEL_33;
    }
  }
  jobStinger = v26;
  v21 = v8;
  if ( v5 != nullptr )
  {
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&v5->jobStingersPlayed,
      obj: (encounterGroupRole_t *)&v21);
  }
  else
  {
    v15 = (idSpecialEvent_Area_Tracker *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                           size: 0x34u,
                                           tag: TAG_NEW,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
    num = (idPlayer *)v15;
    if ( v15 != nullptr )
      v16 = idSpecialEvent_Area_Tracker::idSpecialEvent_Area_Tracker(this: v15);
    else
      v16 = nullptr;
    allocedAndFlag = (const char *)specialEventArea->job.allocedAndFlag;
    num = (idPlayer *)v16;
    idStr::operator=(this: &v16->areaDecl, text: allocedAndFlag);
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&v16->jobStingersPlayed,
      obj: (encounterGroupRole_t *)&v21);
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->specialEventAreaTrackers,
      obj: (encounterGroupRole_t *)&num);
  }
  idStr::FreeData(this: &v23);
  if ( jobStinger == nullptr )
LABEL_33:
    jobStinger = specialEventArea[1].jobStinger;
  owner = this->owner;
  if ( owner != nullptr )
  {
    presentable = owner->presentable;
    num = this->owner;
    if ( presentable != nullptr )
      v20 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v20 = 0;
    if ( *(_BYTE *)(v20 + 35105) == 0 )
      idPlayer::PlayLocalSound(this: this->owner, channel: SND_CHANNEL_ALERT, shader: jobStinger, soundShaderFlags: 0);
  }
}


// ========================================================================
// __unwind$510484_0
// EA  : 0x82E1750C
// RVA : 0x00E1750C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_510484_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$510485_0
// EA  : 0x82E17534
// RVA : 0x00E17534
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall _unwind_510485_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 208 + 84), tag: a2);
}


// ========================================================================
// ?FindCompletedJob@idJobManager@@QBAPAVidJob@@PBVidAI2@@@Z
// EA  : 0x82E17560
// RVA : 0x00E17560
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJob *__fastcall idJobManager::FindCompletedJob(idJobManager *this, const idAI2 *completionNPC)
{
  int v4; // r29
  int i; // r30
  idJob *v6; // r11
  missionStatus_t status; // r10
  char v8; // r10
  bool v9; // zf

  v4 = 0;
  if ( this->jobs.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v6 = this->jobs.list[i];
    status = v6->status;
    if ( status == JOBSTATUS_READYTOTURNIN || (v9 = status != JOBSTATUS_ACCEPTED, v8 = 0, !v9) )
      v8 = 1;
    if ( v8 != 0
      && (unsigned __int8)idJobManager::IsJobReadyToComplete(this, jobDecl: v6->decl, npc: completionNPC) != 0 )
    {
      break;
    }
    if ( ++v4 >= this->jobs.num )
      return nullptr;
  }
  return this->jobs.list[v4];
}


// ========================================================================
// ?IsJobReadyToTurnIn@idJobManager@@QBA_NPBVidDeclJob@@@Z
// EA  : 0x82E17608
// RVA : 0x00E17608
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::IsJobReadyToTurnIn(idJobManager *this, const idDeclJob *jobDecl)
{
  int num; // r8
  int v3; // r10
  idJob **list; // r9
  int i; // r11
  idJob *v7; // r11
  missionStatus_t status; // r11

  num = this->jobs.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  list = this->jobs.list;
  for ( i = 0; list[i]->decl != jobDecl; ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  v7 = list[v3];
  if ( v7 != nullptr
    && ((status = v7->status) == JOBSTATUS_READYTOTURNIN
     || status == JOBSTATUS_ACCEPTED
     || status == JOBSTATUS_READYTOTURNIN_UNKNOWN) )
  {
    return idJobManager::JobMeetsCompletionCriteria(this, jobDecl);
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?FailJob@idJobManager@@QAA_NPBD@Z
// EA  : 0x82E17680
// RVA : 0x00E17680
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::FailJob(idJobManager *this, const char *jobName)
{
  const idDeclJob *v4; // r4

  if ( jobName != nullptr )
  {
    v4 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                              this: &idDeclJob::resourceList,
                              name: jobName,
                              makeDefault: false);
    if ( v4 != nullptr )
      return idJobManager::FailJob(this, jobDecl: v4);
  }
  idLib::Warning(fmt: "Unknown job '%s'", jobName);
  return 0;
}


// ========================================================================
// ?CheckAndGiveDLCRewards@idJobManager@@QAAX_N@Z
// EA  : 0x82E176F8
// RVA : 0x00E176F8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::CheckAndGiveDLCRewards(idJobManager *this, bool mapLoad)
{
  int v3; // r31
  int v4; // r30
  idPlayer *owner; // r11
  idPresentable *presentable; // r3
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  int v11; // r26
  int v12; // r23
  int v13; // r28
  char v14; // r29
  int v15; // r30
  int v16; // r31
  unsigned __int8 v17; // r31
  int v18; // r11
  idJob *InventoryItemByDeclName; // r3
  int v20; // r11
  int v21; // r24
  int v22; // r11
  int v23; // r27
  int v24; // r10
  int v25; // r30
  int v26; // r11
  int v27; // r29
  idPresentable *v28; // r3
  idPresentable *v29; // r31
  const idDeclInventory *v30; // r29
  idInventoryCollection *v31; // r3
  idVehicleKey *v32; // r3
  idVehicleKey *v33; // r3

  if ( g_debugDLCRewards.valueInteger != 0 )
  {
    idLib::Printf(fmt: "CheckAndGiveDLCRwards Called\n");
    idLib::Printf(fmt: "---\n");
    v3 = 0;
    if ( this->dlcRewardsRecieved.num > 0 )
    {
      v4 = 0;
      do
        idLib::Printf(fmt: "%d: %s\n", v3++, this->dlcRewardsRecieved.list[v4++].data);
      while ( v3 < this->dlcRewardsRecieved.num );
    }
    idLib::Printf(fmt: "---\n");
  }
  if ( gameLocal != nullptr )
  {
    owner = this->owner;
    if ( owner != nullptr )
    {
      presentable = owner->presentable;
      if ( presentable != nullptr && presentable->GetPlayerInterface_2(this: presentable) != nullptr )
      {
        v7 = this->owner->presentable;
        v8 = v7 != nullptr ? (int)v7->GetPlayerInterface_2(this: v7) : 0;
        if ( *(_DWORD *)(v8 + 16208) != 0 )
        {
          v9 = this->owner->presentable;
          v10 = v9 != nullptr ? (int)v9->GetPlayerInterface_2(this: v9) : 0;
          v11 = *(_DWORD *)(v10 + 16208);
          v12 = 0;
          if ( *(int *)(v11 + 424) > 0 )
          {
            v13 = 0;
            do
            {
              if ( g_debugDLCRewards.valueInteger != 0 )
                idLib::Printf(fmt: "%d: %s\n", v12, *(_DWORD *)(*(_DWORD *)(v11 + 420) + v13 + 8));
              v14 = 0;
              v15 = 0;
              if ( this->dlcRewardsRecieved.num > 0 )
              {
                v16 = 0;
                while ( idStr::Icmp(
                          s1: this->dlcRewardsRecieved.list[v16].data,
                          s2: *(const char **)(v13 + *(_DWORD *)(v11 + 420) + 8)) != 0 )
                {
                  ++v15;
                  ++v16;
                  if ( v15 >= this->dlcRewardsRecieved.num )
                    goto LABEL_27;
                }
                v14 = 1;
              }
LABEL_27:
              if ( g_debugDLCRewards.valueInteger != 0 && v14 != 0 )
                idLib::Printf(fmt: "     already given\n");
              if ( v14 == 0
                && (unsigned __int8)idGameLocal::IsDLCStateActive(
                                      this: gameLocal,
                                      dlcState: *(gameDLCState_t *)(v13 + *(_DWORD *)(v11 + 420))) != 0 )
              {
                if ( g_debugDLCRewards.valueInteger != 0 )
                  idLib::Printf(fmt: "     passed DLC test\n");
                v17 = 1;
                v18 = v13 + *(_DWORD *)(v11 + 420);
                if ( *(_DWORD *)(v18 + 36) != 0 )
                {
                  v17 = 0;
                  InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                              this,
                                              jobName: *(const char **)(v18 + 40));
                  if ( InventoryItemByDeclName != nullptr
                    && ((v20 = *(_DWORD *)(v13 + *(_DWORD *)(v11 + 420) + 68)) == 0
                     && InventoryItemByDeclName->status >= JOBSTATUS_ACCEPTED
                     || v20 == 1 && InventoryItemByDeclName->status >= JOBSTATUS_READYTOTURNIN
                     || v20 == 2 && InventoryItemByDeclName->status >= JOBSTATUS_COMPLETED) )
                  {
                    v17 = 1;
                  }
                }
                v21 = v17;
                if ( v17 != 0 )
                {
                  if ( g_debugDLCRewards.valueInteger != 0 )
                    idLib::Printf(fmt: "     passed Job test\n");
                  v22 = *(_DWORD *)(v11 + 420);
                  v23 = 0;
                  v24 = v13 + v22;
                  if ( *(int *)(v13 + v22 + 80) > 0 )
                  {
                    v25 = 0;
                    v26 = v13 + v22;
                    do
                    {
                      v27 = *(_DWORD *)(v26 + 76);
                      v28 = this->owner->presentable;
                      if ( v28 != nullptr )
                        v29 = v28->GetPlayerInterface_2(this: v28);
                      else
                        v29 = nullptr;
                      v30 = *(const idDeclInventory **)(v27 + v25);
                      v31 = this->owner->GetInventory_2(this: this->owner);
                      v32 = (idVehicleKey *)idInventoryCollection::GiveItem(
                                              this: v31,
                                              owner: v29,
                                              decl: v30,
                                              count: 1,
                                              forceCount: false,
                                              canIntro: false);
                      if ( *(_BYTE *)(v13 + *(_DWORD *)(v11 + 420) + 73) != 0 && v32 != nullptr )
                      {
                        v33 = idVehicleKey::CastTo(c: v32);
                        if ( v33 != nullptr )
                          v33->vehicleGarage = this->newVehicleGarage;
                      }
                      ++v23;
                      v25 += 4;
                      v24 = v13 + *(_DWORD *)(v11 + 420);
                      v26 = v24;
                    }
                    while ( v23 < *(_DWORD *)(v24 + 80) );
                  }
                  if ( *(_BYTE *)(v24 + 73) != 0 )
                  {
                    if ( g_debugDLCRewards.valueInteger != 0 )
                      idLib::Printf(fmt: "     vehicle reward, should we respawn vehicles?\n");
                    if ( gameLocal->world->mapType == MAPTYPE_TOWN )
                    {
                      if ( g_debugDLCRewards.valueInteger != 0 )
                        idLib::Printf(fmt: "     YES\n");
                      idPlayer::SpawnVehicles(this: this->owner);
                    }
                    else if ( g_debugDLCRewards.valueInteger != 0 )
                    {
                      idLib::Printf(fmt: "     NO\n");
                    }
                  }
                  if ( v21 != 0 )
                    goto LABEL_67;
                }
                if ( *(_BYTE *)(v13 + *(_DWORD *)(v11 + 420) + 72) != 0 )
                {
LABEL_67:
                  if ( g_debugDLCRewards.valueInteger != 0 )
                    idLib::Printf(fmt: "     marking as given\n");
                  idList<idStr,5>::Append(
                    this: &this->dlcRewardsRecieved,
                    obj: (const idStr *)(v13 + *(_DWORD *)(v11 + 420) + 4));
                }
              }
              ++v12;
              v13 += 92;
            }
            while ( v12 < *(_DWORD *)(v11 + 424) );
          }
        }
      }
    }
  }
}


// ========================================================================
// ?GiveSpecialEvent@idJobManager@@QAAXPBVidDeclSpecialEvent@@PAVidEntity@@@Z
// EA  : 0x82E17BA0
// RVA : 0x00E17BA0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::GiveSpecialEvent(
        idJobManager *this,
        const idDeclSpecialEvent *specialEventDecl,
        idEntity *fromEntity)
{
  int v6; // r4
  _DWORD *v7; // r3
  _DWORD *v8; // r11
  int num; // r4
  int cameraIndex; // r3
  int v11; // r30
  int v12; // r31
  _DWORD *v13; // [sp+50h] [-30h] BYREF

  if ( specialEventDecl != nullptr && (unsigned __int8)idJobManager::HasSpecialEvent(this, specialEventDecl) == 0 )
  {
    if ( *(_DWORD *)(v6 + 64) == 0 )
    {
      v7 = idMem::AllocWithLocation(
             this: &mem,
             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
             size: 8u,
             tag: TAG_NEW,
             zeroBuffer: false,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
      {
        v7[1] = specialEventDecl;
        v8 = v7;
        *v7 = &idSpecialEvent::`vftable';
      }
      else
      {
        v8 = nullptr;
      }
      v13 = v8;
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->specialEvent_Jumps,
        obj: (encounterGroupRole_t *)&v13);
      if ( !this->inDebug )
        idJobManager::PlaySpecialEventJumpSound(this);
    }
    num = specialEventDecl->cameras.num;
    if ( num > 0 && fromEntity != nullptr )
    {
      cameraIndex = specialEventDecl->cameraIndex;
      if ( cameraIndex == -1 )
        cameraIndex = idRandom2::RandomInt(this: &clientGame->random, max: num);
      idPlayer::ActivateCinematicCamera(
        this: this->owner,
        cameraTriggerDecl: specialEventDecl->cameras.list[cameraIndex],
        activator: fromEntity);
    }
    v11 = 0;
    if ( specialEventDecl->rewards.num > 0 )
    {
      v12 = 0;
      do
      {
        idJobManager::GiveOwnerInventoryItem(
          this,
          decl: specialEventDecl->rewards.list[v12].inventoryDecl,
          count: specialEventDecl->rewards.list[v12].count,
          canPlayIntroAnim: false);
        ++v11;
        ++v12;
      }
      while ( v11 < specialEventDecl->rewards.num );
    }
  }
}


// ========================================================================
// ?SetInteractionApproachPlayed@idAIPlayerInteractionMemory@@QAAXH_N@Z
// EA  : 0x82E17D40
// RVA : 0x00E17D40
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idAIPlayerInteractionMemory::SetInteractionApproachPlayed(
        idAIPlayerInteractionMemory *this,
        int interactionNumber,
        bool played,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        bool a16)
{
  int num; // r11
  bool v20; // cr58
  idList<unsigned char,37> *p_approachPlayedList; // r31
  int v22; // r30
  int granularity; // r4
  int size; // r11
  bool v25; // cr58
  signed int v26; // r10
  int v27; // r4
  int v28; // r11
  int v29; // r11
  int v30; // ctr
  unsigned __int8 *v31; // r10
  int v32; // r11

  num = this->approachPlayedList.num;
  a16 = played;
  v20 = interactionNumber == num;
  if ( interactionNumber > num )
  {
    p_approachPlayedList = (idList<unsigned char,37> *)&this->approachPlayedList;
    do
    {
      v22 = interactionNumber;
      if ( p_approachPlayedList->list != nullptr )
        goto LABEL_7;
      granularity = p_approachPlayedList->granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( (unsigned __int8)idList<unsigned char,25>::Resize(this: p_approachPlayedList, newsize: granularity) != 0 )
      {
LABEL_7:
        size = p_approachPlayedList->size;
        if ( p_approachPlayedList->num != size )
          goto LABEL_16;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v25 = (unsigned __int8)idList<unsigned char,25>::Resize(this: p_approachPlayedList, newsize: size + 1) == 0;
        }
        else
        {
          v26 = p_approachPlayedList->granularity;
          if ( p_approachPlayedList->granularity != 0 )
          {
            v28 = size + v26;
            __twllei(v26, 0);
            __twlgei(v26 & ~(__ROL4__(v28, 1) - 1), 0xFFFFFFFF);
            v25 = (unsigned __int8)idList<unsigned char,25>::Resize(
                                     this: p_approachPlayedList,
                                     newsize: v28 - v28 % v26) == 0;
          }
          else
          {
            v27 = 2 * size;
            if ( 2 * size == 0 )
              v27 = 1;
            v25 = (unsigned __int8)idList<unsigned char,25>::Resize(this: p_approachPlayedList, newsize: v27) == 0;
          }
        }
        if ( !v25 )
        {
LABEL_16:
          if ( interactionNumber >= 0 )
          {
            if ( interactionNumber > p_approachPlayedList->num )
              v22 = p_approachPlayedList->num;
          }
          else
          {
            v22 = 0;
          }
          v29 = p_approachPlayedList->num;
          if ( v29 < p_approachPlayedList->size )
          {
            if ( v29 > v22 )
            {
              v30 = v29 - v22;
              do
              {
                v31 = &p_approachPlayedList->list[v29--];
                *v31 = *(v31 - 1);
                --v30;
              }
              while ( v30 != 0 );
            }
            ++p_approachPlayedList->num;
          }
          p_approachPlayedList->list[v22] = 0;
        }
      }
      v32 = this->approachPlayedList.num;
    }
    while ( interactionNumber > v32 );
    v20 = interactionNumber == v32;
  }
  if ( v20 )
    idList<bool,5>::Insert(
      this: (idList<unsigned char,25> *)&this->approachPlayedList,
      obj: (unsigned __int8 *)&a16,
      index: interactionNumber);
  this->approachPlayedList.list[interactionNumber] = played;
}


// ========================================================================
// ?SetJobOfferPlayed@idAIPlayerInteractionMemory@@QAAXH_N@Z
// EA  : 0x82E17EF0
// RVA : 0x00E17EF0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idAIPlayerInteractionMemory::SetJobOfferPlayed(
        idAIPlayerInteractionMemory *this,
        int interactionNumber,
        bool played,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        bool a16)
{
  int num; // r11
  bool v20; // cr58
  idList<bool,5> *p_jobOfferPlayedList; // r31
  int v22; // r30
  int granularity; // r4
  int size; // r11
  bool v25; // cr58
  signed int v26; // r10
  int v27; // r4
  int v28; // r11
  int v29; // r11
  int v30; // ctr
  bool *v31; // r10
  int v32; // r11

  a16 = played;
  if ( interactionNumber < 0 )
    idLib::Error(fmt: "interactionNumber is %d in SetJobOfferPlayed", interactionNumber);
  num = this->jobOfferPlayedList.num;
  v20 = interactionNumber == num;
  if ( interactionNumber > num )
  {
    p_jobOfferPlayedList = &this->jobOfferPlayedList;
    do
    {
      v22 = interactionNumber;
      if ( p_jobOfferPlayedList->list != nullptr )
        goto LABEL_9;
      granularity = this->jobOfferPlayedList.granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( (unsigned __int8)idList<unsigned char,25>::Resize(
                              this: (idList<unsigned char,37> *)&this->jobOfferPlayedList,
                              newsize: granularity) != 0 )
      {
LABEL_9:
        size = this->jobOfferPlayedList.size;
        if ( this->jobOfferPlayedList.num != size )
          goto LABEL_18;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v25 = (unsigned __int8)idList<unsigned char,25>::Resize(
                                   this: (idList<unsigned char,37> *)&this->jobOfferPlayedList,
                                   newsize: size + 1) == 0;
        }
        else
        {
          v26 = this->jobOfferPlayedList.granularity;
          if ( this->jobOfferPlayedList.granularity != 0 )
          {
            v28 = size + v26;
            __twllei(v26, 0);
            __twlgei(v26 & ~(__ROL4__(v28, 1) - 1), 0xFFFFFFFF);
            v25 = (unsigned __int8)idList<unsigned char,25>::Resize(
                                     this: (idList<unsigned char,37> *)&this->jobOfferPlayedList,
                                     newsize: v28 - v28 % v26) == 0;
          }
          else
          {
            v27 = 2 * size;
            if ( 2 * size == 0 )
              v27 = 1;
            v25 = (unsigned __int8)idList<unsigned char,25>::Resize(
                                     this: (idList<unsigned char,37> *)&this->jobOfferPlayedList,
                                     newsize: v27) == 0;
          }
        }
        if ( !v25 )
        {
LABEL_18:
          v29 = this->jobOfferPlayedList.num;
          if ( interactionNumber > v29 )
            v22 = this->jobOfferPlayedList.num;
          if ( v29 < this->jobOfferPlayedList.size )
          {
            if ( v29 > v22 )
            {
              v30 = v29 - v22;
              do
              {
                v31 = &p_jobOfferPlayedList->list[v29--];
                *v31 = *(v31 - 1);
                --v30;
              }
              while ( v30 != 0 );
            }
            ++this->jobOfferPlayedList.num;
          }
          p_jobOfferPlayedList->list[v22] = false;
        }
      }
      v32 = this->jobOfferPlayedList.num;
    }
    while ( interactionNumber > v32 );
    v20 = interactionNumber == v32;
  }
  if ( v20 )
    idList<bool,5>::Insert(
      this: (idList<unsigned char,25> *)&this->jobOfferPlayedList,
      obj: (unsigned __int8 *)&a16,
      index: interactionNumber);
  this->jobOfferPlayedList.list[interactionNumber] = played;
}


// ========================================================================
// ?AddJobNote@idJob@@QAA_NPBVidDeclJobNote@@_N@Z
// EA  : 0x82E18400
// RVA : 0x00E18400
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJob::AddJobNote(idJob *this, const idDeclJobNote *jobNoteDecl, bool force)
{
  int num; // r9
  int v6; // r10
  idJobNoteTracker **list; // r8
  int v8; // r11
  _DWORD *v9; // r3
  encounterGroupRole_t v10; // r7
  int v12; // r9
  idList<idJobNoteTracker *,5> *p_jobNotes; // r3
  int v14; // r10
  int i; // r11
  encounterGroupRole_t v16[12]; // [sp+50h] [-30h] BYREF

  num = this->jobNotes.num;
  v6 = 0;
  if ( num > 0 )
  {
    list = this->jobNotes.list;
    v8 = 0;
    while ( list[v8]->jobNote != jobNoteDecl )
    {
      ++v6;
      ++v8;
      if ( v6 >= num )
        goto LABEL_5;
    }
    if ( force )
    {
      list[v6]->jobNoteStatus = JOBNOTE_STATUS_NEW;
      return 1;
    }
    return 0;
  }
LABEL_5:
  v9 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
         size: 0xCu,
         tag: TAG_NEW,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
  {
    v9[1] = jobNoteDecl;
    v9[2] = 0;
    v10 = (encounterGroupRole_t)v9;
    *v9 = &idJobNoteTracker::`vftable';
  }
  else
  {
    v10 = ROLE_NONE;
  }
  v16[0] = v10;
  if ( v10 == ROLE_NONE )
    return 0;
  if ( jobNoteDecl->hudInformation.index < 0 && *(int *)(v10 + 8) < 1 )
    *(_DWORD *)(v10 + 8) = 1;
  v12 = this->jobNotes.num;
  p_jobNotes = &this->jobNotes;
  v14 = 0;
  if ( v12 <= 0 )
    goto LABEL_21;
  for ( i = 0; p_jobNotes->list[i] != (idJobNoteTracker *)v10; ++i )
  {
    if ( ++v14 >= v12 )
    {
      idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)p_jobNotes, obj: v16);
      return 1;
    }
  }
  if ( v14 < 0 )
LABEL_21:
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)p_jobNotes, obj: v16);
  return 1;
}


// ========================================================================
// ?RemoveJobNote@idJob@@QAAXPBVidDeclJobNote@@@Z
// EA  : 0x82E18568
// RVA : 0x00E18568
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJob::RemoveJobNote(idJob *this, const idDeclJobNote *jobNoteDecl)
{
  int num; // r8
  int v5; // r10
  idJobNoteTracker **list; // r9
  int v7; // r11
  _DWORD *v8; // r3
  _DWORD *v9; // r9
  idList<enum encounterGroupRole_t,5> *p_jobNotes; // r3
  int v11; // r10
  int v12; // r8
  int v13; // r11
  encounterGroupRole_t v14[2]; // [sp+50h] [-20h] BYREF

  num = this->jobNotes.num;
  v5 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    v8 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
           size: 0xCu,
           tag: TAG_NEW,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
    {
      v8[1] = jobNoteDecl;
      v8[2] = 0;
      v9 = v8;
      *v8 = &idJobNoteTracker::`vftable';
    }
    else
    {
      v9 = nullptr;
    }
    v14[0] = (encounterGroupRole_t)v9;
    p_jobNotes = (idList<enum encounterGroupRole_t,5> *)&this->jobNotes;
    v9[2] = 3;
    v11 = 0;
    v12 = this->jobNotes.num;
    if ( v12 <= 0 )
      goto LABEL_15;
    v13 = 0;
    while ( (_DWORD *)p_jobNotes->list[v13] != v9 )
    {
      ++v11;
      ++v13;
      if ( v11 >= v12 )
        goto LABEL_15;
    }
    if ( v11 < 0 )
LABEL_15:
      idList<idAnimWebBlendTree *,5>::Append(this: p_jobNotes, obj: v14);
  }
  else
  {
    list = this->jobNotes.list;
    v7 = 0;
    while ( list[v7]->jobNote != jobNoteDecl )
    {
      ++v5;
      ++v7;
      if ( v5 >= num )
        goto LABEL_5;
    }
    list[v5]->jobNoteStatus = JOBNOTE_STATUS_COMPLETE;
  }
}


// ========================================================================
// ?StartTimer@idJobTimerIteration@@QAAXPAVidPlayer@@VidStrId@@HHH_NABV?$idEntityPtr@VidEntity@@@@H@Z
// EA  : 0x82E18698
// RVA : 0x00E18698
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerIteration::StartTimer(
        idJobTimerIteration *this,
        idPlayer *player,
        idStrId *name,
        int cashPerScore,
        int parTime,
        int parPrize,
        bool actuallyTime,
        const idEntityPtr<idEntity> *continueTarget,
        int numPhases,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  int num; // r3
  idJobTimerPhase *v30; // r11
  idJobTimerPhase *v31; // r31
  idJobTimerPhase *v32; // r11
  char v33; // r31
  int v34; // [sp+8h] [-D8h]
  int v35; // [sp+Ch] [-D4h]
  int v36; // [sp+10h] [-D0h]
  int v37; // [sp+14h] [-CCh]
  int v38; // [sp+18h] [-C8h]
  int v39; // [sp+1Ch] [-C4h]
  int v40; // [sp+20h] [-C0h]
  int v41; // [sp+24h] [-BCh]
  int v42; // [sp+28h] [-B8h]
  int v43; // [sp+2Ch] [-B4h]
  int v44; // [sp+30h] [-B0h]
  int v45; // [sp+34h] [-ACh]
  int v46; // [sp+38h] [-A8h]
  int v47; // [sp+3Ch] [-A4h]
  int v48; // [sp+40h] [-A0h]
  int v49; // [sp+44h] [-9Ch]
  int v50; // [sp+48h] [-98h]
  int v51; // [sp+4Ch] [-94h]
  int v52; // [sp+50h] [-90h]
  idStrId v53[4]; // [sp+60h] [-80h] BYREF
  idJobTimerPhase v54; // [sp+70h] [-70h] BYREF

  num = this->phases.num;
  if ( num <= 0 || (v30 = &this->phases.list[num], v31 = v30 - 1, v30 == (idJobTimerPhase *)68) )
  {
    v32 = nullptr;
  }
  else
  {
    v32 = nullptr;
    if ( v31->starttime >= 0 && v31->stoptime < 0 )
    {
      v33 = 1;
      goto LABEL_8;
    }
  }
  v33 = 0;
LABEL_8:
  v53[0] = (idStrId)name->index;
  if ( v33 != 0 )
  {
    if ( num > 0 )
      v32 = &this->phases.list[num - 1];
    idJobTimerPhase::StartTimer(
      this: v32,
      player,
      name: v53,
      cashPerScore,
      parTime,
      parPrize,
      actuallyTime,
      nextTarget: continueTarget,
      numPhases: v34,
      a10: v35,
      a11: v36,
      a12: v37,
      a13: v38,
      a14: v39,
      a15: v40,
      a16: v41,
      a17: v42,
      a18: v43,
      a19: v44,
      a20: v45,
      a21: v46,
      a22: v47,
      a23: v48,
      a24: v49,
      a25: v50,
      a26: v51,
      a27: v52,
      a28);
    idLib::Warning(fmt: "idJobTimerIteration got call to start timer while already timing.  IGNORING.");
  }
  else
  {
    memset(&v54, 0, 12);
    v54.starttime = -1;
    v54.stoptime = -1;
    memset(&v54.moneyPerScore, 0, 16);
    v54.phaseName.index = -1;
    v54.arenaBonusGiven = false;
    v54.actuallyRunning = true;
    memset(&v54.parBonus, 0, 16);
    v54.continueTarget.spawnId.value = 0x1FFF;
    idJobTimerPhase::StartTimer(
      this: &v54,
      player,
      name: v53,
      cashPerScore,
      parTime,
      parPrize,
      actuallyTime,
      nextTarget: continueTarget,
      numPhases: v34,
      a10: v35,
      a11: v36,
      a12: v37,
      a13: v38,
      a14: v39,
      a15: v40,
      a16: v41,
      a17: v42,
      a18: v43,
      a19: v44,
      a20: v45,
      a21: v46,
      a22: v47,
      a23: v48,
      a24: v49,
      a25: v50,
      a26: v51,
      a27: v52,
      a28);
    idList<idJobTimerPhase,5>::Append(this: &this->phases, obj: &v54);
    this->stoppedTime = -1;
  }
}


// ========================================================================
// ?ReadFromFile@idJobTimerIteration@@QAAXPAVidFile@@@Z
// EA  : 0x82E187E8
// RVA : 0x00E187E8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerIteration::ReadFromFile(idJobTimerIteration *this, idFile *file)
{
  const idDeclJobTimerEvent *v4; // r3
  const idDeclJob *v5; // r3
  idFile_vtbl *v6; // r11
  int i; // r29
  _DWORD v8[4]; // [sp+50h] [-F0h] BYREF
  idJobTimerPhase v9; // [sp+60h] [-E0h] BYREF
  idStr v10; // [sp+B0h] [-90h] BYREF
  idStr v11[3]; // [sp+D0h] [-70h] BYREF

  v11[0].len = 0;
  v11[0].allocedAndFlag = 20;
  v11[0].data = v11[0].baseBuffer;
  v11[0].baseBuffer[0] = 0;
  idFile::ReadString(this: file, string: v11);
  if ( v11[0].data != nullptr )
    v4 = (const idDeclJobTimerEvent *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclJobTimerEvent::resourceList,
                                        name: v11[0].data,
                                        makeDefault: false);
  else
    v4 = nullptr;
  this->eventDecl = v4;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.len = 0;
  v10.baseBuffer[0] = 0;
  idFile::ReadString(this: file, string: &v10);
  if ( v10.data != nullptr )
    v5 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                              this: &idDeclJob::resourceList,
                              name: v10.data,
                              makeDefault: false);
  else
    v5 = nullptr;
  this->jobDecl = v5;
  v6 = file->__vftable;
  v8[0] = 0;
  v6->Read(this: file, a2: v8, a3: 4u);
  for ( i = 0; i < v8[0]; ++i )
  {
    memset(&v9, 0, 12);
    v9.starttime = -1;
    v9.stoptime = -1;
    memset(&v9.moneyPerScore, 0, 16);
    v9.phaseName.index = -1;
    v9.arenaBonusGiven = false;
    v9.actuallyRunning = true;
    memset(&v9.parBonus, 0, 16);
    v9.continueTarget.spawnId.value = 0x1FFF;
    idJobTimerPhase::ReadFromFile(this: &v9, file);
    idList<idJobTimerPhase,5>::Append(this: &this->phases, obj: &v9);
  }
  file->Read(this: file, a2: &this->stoppedTime, a3: 4u);
  idStr::FreeData(this: &v10);
  idStr::FreeData(this: v11);
}


// ========================================================================
// __unwind$512161
// EA  : 0x82E18974
// RVA : 0x00E18974
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512161()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 208));
}


// ========================================================================
// __unwind$512162
// EA  : 0x82E1899C
// RVA : 0x00E1899C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512162()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 176));
}


// ========================================================================
// ?StartTimer@idJobTimerManager@@QAAXPAVidPlayer@@VidStrId@@HHH_NABV?$idEntityPtr@VidEntity@@@@H@Z
// EA  : 0x82E189C8
// RVA : 0x00E189C8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::StartTimer(
        idJobTimerManager *this,
        idPlayer *player,
        idStrId *name,
        int cashPerScore,
        int parTime,
        int parPrize,
        BOOL actuallyTime,
        const idEntityPtr<idEntity> *continueTarget,
        int numPhases,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  int num; // r11
  idJobTimerIteration *v29; // r3
  int v30; // [sp+8h] [-68h]
  int v31; // [sp+Ch] [-64h]
  int v32; // [sp+10h] [-60h]
  int v33; // [sp+14h] [-5Ch]
  int v34; // [sp+18h] [-58h]
  int v35; // [sp+1Ch] [-54h]
  int v36; // [sp+20h] [-50h]
  int v37; // [sp+24h] [-4Ch]
  int v38; // [sp+28h] [-48h]
  int v39; // [sp+2Ch] [-44h]
  int v40; // [sp+30h] [-40h]
  int v41; // [sp+34h] [-3Ch]
  int v42; // [sp+38h] [-38h]
  int v43; // [sp+3Ch] [-34h]
  int v44; // [sp+40h] [-30h]
  int v45; // [sp+44h] [-2Ch]
  int v46; // [sp+48h] [-28h]
  int v47; // [sp+4Ch] [-24h]
  int v48; // [sp+50h] [-20h]
  idStrId v49; // [sp+60h] [-10h] BYREF

  if ( this->active )
  {
    num = this->iterations.num;
    v49.index = name->index;
    if ( num <= 0 )
      v29 = nullptr;
    else
      v29 = &this->iterations.list[num - 1];
    idJobTimerIteration::StartTimer(
      this: v29,
      player,
      name: &v49,
      cashPerScore,
      parTime,
      parPrize,
      actuallyTime,
      continueTarget,
      numPhases: v30,
      a10: v31,
      a11: v32,
      a12: v33,
      a13: v34,
      a14: v35,
      a15: v36,
      a16: v37,
      a17: v38,
      a18: v39,
      a19: v40,
      a20: v41,
      a21: v42,
      a22: v43,
      a23: v44,
      a24: v45,
      a25: v46,
      a26: v47,
      a27: v48,
      a28);
  }
  else
  {
    idLib::Warning(
      fmt: "idJobTimerManager got call to StartTimer when not actually running.  IGNORING",
      player,
      name,
      cashPerScore,
      parTime,
      parPrize,
      actuallyTime,
      continueTarget);
  }
}


// ========================================================================
// ??1idJobManager@@QAA@XZ
// EA  : 0x82E18A50
// RVA : 0x00E18A50
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::~idJobManager(idJobManager *this)
{
  idStr *list; // r3

  idJobManager::Clear(this);
  if ( this->dlcRewardsRecieved.listStatic == 0 || this->dlcRewardsRecieved.listStatic == 2 )
  {
    list = this->dlcRewardsRecieved.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->dlcRewardsRecieved.size);
    this->dlcRewardsRecieved.list = nullptr;
    this->dlcRewardsRecieved.size = 0;
  }
  this->dlcRewardsRecieved.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->raceStatusMemories);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->gameStateInts);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerInteractionMemories);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->specialEventAreaTrackers);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->specialEvent_Jumps);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$512412
// EA  : 0x82E18ADC
// RVA : 0x00E18ADC
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512412()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$512413
// EA  : 0x82E18B04
// RVA : 0x00E18B04
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512413()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// __unwind$512414
// EA  : 0x82E18B30
// RVA : 0x00E18B30
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512414()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$512415
// EA  : 0x82E18B5C
// RVA : 0x00E18B5C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512415()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// __unwind$512416
// EA  : 0x82E18B88
// RVA : 0x00E18B88
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512416()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// __unwind$512417
// EA  : 0x82E18BB4
// RVA : 0x00E18BB4
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512417()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 84));
}


// ========================================================================
// __unwind$512418
// EA  : 0x82E18BE0
// RVA : 0x00E18BE0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512418()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// ?RemoveJobNote@idJobManager@@QAAXPBVidDeclJobNote@@_N@Z
// EA  : 0x82E18C10
// RVA : 0x00E18C10
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::RemoveJobNote(
        idJobManager *this,
        const idDeclJobNote *jobNoteDecl,
        bool checkForActiveJob)
{
  const idDeclJobNote *removeNote; // r4
  idJob *InventoryItemByDeclName; // r3
  missionStatus_t status; // r11
  char v9; // r11
  bool v10; // zf

  if ( jobNoteDecl != nullptr )
  {
    if ( jobNoteDecl->jobDeclReference.len != 0 )
    {
      removeNote = jobNoteDecl->removeNote;
      if ( removeNote != nullptr )
        idJobManager::RemoveJobNote(this, jobNoteDecl: removeNote, checkForActiveJob: false);
      InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                  this,
                                  jobName: jobNoteDecl->jobDeclReference.data);
      if ( InventoryItemByDeclName != nullptr )
      {
        if ( !checkForActiveJob )
          goto LABEL_15;
        status = InventoryItemByDeclName->status;
        if ( status == JOBSTATUS_READYTOTURNIN || (v10 = status != JOBSTATUS_ACCEPTED, v9 = 0, !v10) )
          v9 = 1;
        if ( v9 != 0 )
LABEL_15:
          idJob::RemoveJobNote(this: InventoryItemByDeclName, jobNoteDecl);
      }
      else if ( jobDebug_JobNoteWarnings.valueInteger != 0 )
      {
        idLib::Warning(
          fmt: "job not found in idJobManager::RemoveJobNote %s, %s",
          jobNoteDecl->jobDeclReference.data,
          jobNoteDecl->name.str);
      }
    }
    else if ( jobDebug_JobNoteWarnings.valueInteger != 0 )
    {
      idLib::Warning(fmt: "jobnote has no job Reference in RemoveJobNote");
    }
  }
  else if ( jobDebug_JobNoteWarnings.valueInteger != 0 )
  {
    idLib::Warning(fmt: "NULL jobNoteDecl in idJobManager::RemoveJobNote");
  }
}


// ========================================================================
// ?AddJob@idJobManager@@AAAXPAVidJob@@@Z
// EA  : 0x82E18D30
// RVA : 0x00E18D30
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::AddJob(
        idJobManager *this,
        idJob *job,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idJob *a14)
{
  int num; // r9
  int v15; // r10
  int v16; // r11

  num = this->jobs.num;
  v15 = 0;
  a14 = job;
  if ( num <= 0 )
    goto LABEL_7;
  v16 = 0;
  while ( this->jobs.list[v16] != job )
  {
    ++v15;
    ++v16;
    if ( v15 >= num )
      goto LABEL_7;
  }
  if ( v15 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(
      (idList<enum encounterGroupRole_t,5> *)this,
      obj: (encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?IsJobReadyToTurnIn@idJobManager@@QBA_NPBD@Z
// EA  : 0x82E18D98
// RVA : 0x00E18D98
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::IsJobReadyToTurnIn(idJobManager *this, const char *name)
{
  const idDeclJob *v4; // r4

  if ( name != nullptr )
  {
    v4 = (const idDeclJob *)idDeclInfo::FindWithInheritance(this: &idDeclJob::resourceList, name, makeDefault: false);
    if ( v4 != nullptr )
      return idJobManager::IsJobReadyToTurnIn(this, jobDecl: v4);
  }
  idLib::Warning(fmt: "Unknown job '%s' in IsJobReadyToTurnIn", name);
  return 0;
}


// ========================================================================
// ?AddGameStateInt@idJobManager@@AAAXPAVidGameStateInt@@@Z
// EA  : 0x82E18E10
// RVA : 0x00E18E10
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::AddGameStateInt(
        idJobManager *this,
        idGameStateInt *gameStateInt,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idGameStateInt *a14)
{
  idList<enum encounterGroupRole_t,5> *p_gameStateInts; // r3
  int v15; // r10
  int num; // r9
  int v17; // r11

  p_gameStateInts = (idList<enum encounterGroupRole_t,5> *)&this->gameStateInts;
  a14 = gameStateInt;
  v15 = 0;
  num = p_gameStateInts->num;
  if ( num <= 0 )
    goto LABEL_7;
  v17 = 0;
  while ( (idGameStateInt *)p_gameStateInts->list[v17] != gameStateInt )
  {
    ++v15;
    ++v17;
    if ( v15 >= num )
      goto LABEL_7;
  }
  if ( v15 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_gameStateInts, obj: (encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?AddPlayerInteractionMemory@idJobManager@@AAAXPAVidAIPlayerInteractionMemory@@@Z
// EA  : 0x82E18E80
// RVA : 0x00E18E80
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::AddPlayerInteractionMemory(
        idJobManager *this,
        idAIPlayerInteractionMemory *memory,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idAIPlayerInteractionMemory *a14)
{
  idList<enum encounterGroupRole_t,5> *p_playerInteractionMemories; // r3
  int v15; // r10
  int num; // r9
  int v17; // r11

  p_playerInteractionMemories = (idList<enum encounterGroupRole_t,5> *)&this->playerInteractionMemories;
  a14 = memory;
  v15 = 0;
  num = p_playerInteractionMemories->num;
  if ( num <= 0 )
    goto LABEL_7;
  v17 = 0;
  while ( (idAIPlayerInteractionMemory *)p_playerInteractionMemories->list[v17] != memory )
  {
    ++v15;
    ++v17;
    if ( v15 >= num )
      goto LABEL_7;
  }
  if ( v15 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_playerInteractionMemories, obj: (encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?SetBestRacePlace@idJobManager@@QAAXPBDW4raceMemoryPlace_t@@@Z
// EA  : 0x82E18EF0
// RVA : 0x00E18EF0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::SetBestRacePlace(idJobManager *this, const char *raceDeclName, idVoiceEvent_vtbl *place)
{
  idRaceStatusMemory *RaceStatusMemory; // r3
  idPlayer *owner; // r11
  idRaceStatusMemory *v8; // [sp+50h] [-30h] BYREF

  RaceStatusMemory = idJobManager::FindRaceStatusMemory(this, raceDeclName);
  if ( RaceStatusMemory != nullptr )
  {
    RaceStatusMemory->bestPlace = (raceMemoryPlace_t)place;
  }
  else
  {
    v8 = idRaceStatusMemory::Create(raceDeclName);
    v8->bestPlace = (raceMemoryPlace_t)place;
    idList<idDeclMD6 const *,5>::AddUnique(
      this: (idList<idVoiceEvent const *,5> *)&this->raceStatusMemories,
      obj: (const idVoiceEvent *const *)&v8);
  }
  owner = this->owner;
  if ( owner != nullptr )
    idAchievementManager::RaceCompletesAchievement(
      this: &owner->achievementManager,
      raceName: raceDeclName,
      (raceMemoryPlace_t)place);
}


// ========================================================================
// ?SetInteractionApproachPlayed@idJobManager@@QAAXPBVidDeclAIPlayerInteraction@@H_N@Z
// EA  : 0x82E18F60
// RVA : 0x00E18F60
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::SetInteractionApproachPlayed(
        idJobManager *this,
        const idDeclAIPlayerInteraction *interactionDecl,
        int interactionNumber,
        bool played)
{
  idAIPlayerInteractionMemory *PlayerInteractionMemory; // r31
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  int v13; // r6
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  int v20; // [sp+8h] [-78h]
  int v21; // [sp+Ch] [-74h]
  int v22; // [sp+10h] [-70h]
  int v23; // [sp+14h] [-6Ch]
  int v24; // [sp+18h] [-68h]
  idAIPlayerInteractionMemory *v25; // [sp+1Ch] [-64h]
  int v26; // [sp+20h] [-60h]
  bool v27; // [sp+27h] [-59h]

  PlayerInteractionMemory = idJobManager::FindPlayerInteractionMemory(this, interactionDecl);
  if ( PlayerInteractionMemory == nullptr )
  {
    PlayerInteractionMemory = idAIPlayerInteractionMemory::Create(interactionDeclName: interactionDecl->name.str);
    idJobManager::AddPlayerInteractionMemory(
      this,
      memory: PlayerInteractionMemory,
      a3: v19,
      a4: v18,
      a5: v17,
      a6: v16,
      a7: v15,
      a8: v14,
      a9: v20,
      a10: v21,
      a11: v22,
      a12: v23,
      a13: v24,
      a14: v25);
  }
  idAIPlayerInteractionMemory::SetInteractionApproachPlayed(
    this: PlayerInteractionMemory,
    interactionNumber,
    played,
    a4: v13,
    a5: v12,
    a6: v11,
    a7: v10,
    a8: v9,
    a9: v20,
    a10: v21,
    a11: v22,
    a12: v23,
    a13: v24,
    a14: (int)v25,
    a15: v26,
    a16: v27);
}


// ========================================================================
// ?SetJobOfferPlayed@idJobManager@@QAAXPBVidDeclAIPlayerInteraction@@H_N@Z
// EA  : 0x82E18FC0
// RVA : 0x00E18FC0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::SetJobOfferPlayed(
        idJobManager *this,
        const idDeclAIPlayerInteraction *interactionDecl,
        int interactionNumber,
        bool played)
{
  idAIPlayerInteractionMemory *PlayerInteractionMemory; // r31
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  int v13; // r6
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  int v20; // [sp+8h] [-78h]
  int v21; // [sp+Ch] [-74h]
  int v22; // [sp+10h] [-70h]
  int v23; // [sp+14h] [-6Ch]
  int v24; // [sp+18h] [-68h]
  idAIPlayerInteractionMemory *v25; // [sp+1Ch] [-64h]
  int v26; // [sp+20h] [-60h]
  bool v27; // [sp+27h] [-59h]

  PlayerInteractionMemory = idJobManager::FindPlayerInteractionMemory(this, interactionDecl);
  if ( PlayerInteractionMemory == nullptr )
  {
    PlayerInteractionMemory = idAIPlayerInteractionMemory::Create(interactionDeclName: interactionDecl->name.str);
    idJobManager::AddPlayerInteractionMemory(
      this,
      memory: PlayerInteractionMemory,
      a3: v19,
      a4: v18,
      a5: v17,
      a6: v16,
      a7: v15,
      a8: v14,
      a9: v20,
      a10: v21,
      a11: v22,
      a12: v23,
      a13: v24,
      a14: v25);
  }
  idAIPlayerInteractionMemory::SetJobOfferPlayed(
    this: PlayerInteractionMemory,
    interactionNumber,
    played,
    a4: v13,
    a5: v12,
    a6: v11,
    a7: v10,
    a8: v9,
    a9: v20,
    a10: v21,
    a11: v22,
    a12: v23,
    a13: v24,
    a14: (int)v25,
    a15: v26,
    a16: v27);
}


// ========================================================================
// ?Clear@idJobTimerManager@@QAAXXZ
// EA  : 0x82E19250
// RVA : 0x00E19250
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::Clear(idJobTimerManager *this)
{
  idJobTimerIteration *list; // r3

  this->active = false;
  if ( this->iterations.listStatic == 0 || this->iterations.listStatic == 2 )
  {
    list = this->iterations.list;
    if ( list != nullptr )
      idListArrayDelete<idJobTimerIteration>(ptr: list, num: this->iterations.size);
    this->iterations.list = nullptr;
    this->iterations.size = 0;
  }
  this->iterations.num = 0;
}


// ========================================================================
// ?ReadFromFile@idJobManager@@QAAXPAVidFile@@@Z
// EA  : 0x82E192C8
// RVA : 0x00E192C8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::ReadFromFile(idJobManager *this, idFile *file)
{
  char *k; // r30
  char *v3; // r29
  int m; // r27
  idDeclInfoTemplate<idDeclSpecialEvent> *p_specialEventAreaTrackers; // r26
  int v8; // r3
  idFile_vtbl *v9; // r9
  int v10; // r14
  int i; // r19
  char *data; // r4
  const idDecl *v13; // r3
  const idDeclJob *v14; // r25
  idJob *v15; // r3
  const idDeclJobNote *v16; // r4
  char v17; // r3
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  int num; // r9
  int v21; // r10
  int v22; // r11
  idAIPlayerInteractionMemory *v23; // r3
  int j; // r30
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int v28; // r7
  int v29; // r6
  int v30; // r10
  int v31; // r9
  int v32; // r8
  int v33; // r7
  int v34; // r6
  int v35; // r9
  idList<enum encounterGroupRole_t,5> *p_playerInteractionMemories; // r3
  int v37; // r10
  int v38; // r11
  idRaceStatusMemory *RaceStatusMemory; // r3
  idRaceStatusMemory *v40; // r9
  idList<enum encounterGroupRole_t,5> *p_raceStatusMemories; // r3
  int v42; // r10
  int v43; // r8
  int v44; // r11
  idPlayer *owner; // r11
  double v46; // fp31
  char *v47; // r30
  idRaceStatusMemory *v48; // r3
  idRaceStatusMemory *v49; // r10
  idList<enum encounterGroupRole_t,5> *v50; // r3
  int v51; // r9
  int v52; // r8
  int v53; // r11
  char *v54; // r4
  const idDeclGameStateInt *v55; // r30
  idGameStateInt *v56; // r3
  idGameStateInt *v57; // r9
  idList<enum encounterGroupRole_t,5> *p_gameStateInts; // r3
  int v59; // r10
  int v60; // r8
  int v61; // r11
  char *v62; // r4
  const idDecl *v63; // r30
  int *v64; // r3
  int *v65; // r11
  idSpecialEvent_Area_Tracker *v66; // r3
  idSpecialEvent_Area_Tracker *v67; // r29
  int v68; // r30
  idList<enum encounterGroupRole_t,5> *p_jobStingersPlayed; // r29
  int n; // r30
  int v71; // r30
  int v72; // [sp+8h] [-228h]
  int v73; // [sp+Ch] [-224h]
  int v74; // [sp+10h] [-220h]
  int v75; // [sp+14h] [-21Ch]
  int v76; // [sp+18h] [-218h]
  int v77; // [sp+1Ch] [-214h]
  int v78; // [sp+20h] [-210h]
  bool v79; // [sp+27h] [-209h]
  void *v80; // [sp+50h] [-1E0h] BYREF
  bool v81; // [sp+54h] [-1DCh] BYREF
  bool v82[3]; // [sp+55h] [-1DBh] BYREF
  int v83; // [sp+58h] [-1D8h] BYREF
  int v84; // [sp+5Ch] [-1D4h] BYREF
  int v85; // [sp+60h] [-1D0h] BYREF
  int v86; // [sp+64h] [-1CCh] BYREF
  int v87; // [sp+68h] [-1C8h] BYREF
  int v88; // [sp+6Ch] [-1C4h] BYREF
  int v89; // [sp+70h] [-1C0h] BYREF
  void *v90; // [sp+74h] [-1BCh] BYREF
  int v91; // [sp+78h] [-1B8h] BYREF
  int v92; // [sp+7Ch] [-1B4h] BYREF
  int v93; // [sp+80h] [-1B0h] BYREF
  int v94; // [sp+84h] [-1ACh] BYREF
  int v95; // [sp+88h] [-1A8h] BYREF
  int v96; // [sp+8Ch] [-1A4h] BYREF
  int v97; // [sp+90h] [-1A0h] BYREF
  int v98; // [sp+94h] [-19Ch] BYREF
  char *v99; // [sp+98h] [-198h] BYREF
  int v100; // [sp+9Ch] [-194h] BYREF
  float v101; // [sp+A0h] [-190h] BYREF
  idStr v102; // [sp+B0h] [-180h] BYREF
  idStr v103; // [sp+D0h] [-160h] BYREF
  idStr v104; // [sp+F0h] [-140h] BYREF
  idStr v105; // [sp+110h] [-120h] BYREF
  idStr v106; // [sp+130h] [-100h] BYREF
  idStr v107; // [sp+150h] [-E0h] BYREF
  idStr v108; // [sp+170h] [-C0h] BYREF

  idJobManager::Clear(this);
  v8 = file->Tell(this: file);
  v9 = file->__vftable;
  v10 = v8;
  v93 = 0;
  v9->Read(this: file, a2: &v93, a3: 4u);
  for ( i = 0; i < v93; ++i )
  {
    v102.allocedAndFlag = 20;
    v102.len = 0;
    v102.data = v102.baseBuffer;
    v102.baseBuffer[0] = 0;
    v96 = 0;
    v95 = 0;
    v91 = 0;
    file->Read(this: file, a2: &v96, a3: 4u);
    idFile::ReadString(this: file, string: &v102);
    file->Read(this: file, a2: &v95, a3: 4u);
    file->Read(this: file, a2: &v91, a3: 4u);
    data = v102.data;
    if ( v102.data != nullptr )
    {
      v13 = idDeclInfo::FindWithInheritance(this: &idDeclJob::resourceList, name: v102.data, makeDefault: false);
      data = v102.data;
    }
    else
    {
      v13 = nullptr;
    }
    v14 = (const idDeclJob *)v13;
    if ( v13 == nullptr )
    {
      v14 = (const idDeclJob *)idResourceList::Load(
                                 this: &idDeclJob::resourceList,
                                 name: data,
                                 makeDefault: false,
                                 skipStaleCheck: false);
      if ( v14 == nullptr )
      {
        idLib::Error(fmt: "idJobManager::ReadFromSnapshot, unknown job %s", v102.data);
        v3 = nullptr;
        goto _M513788_0;
      }
    }
    v15 = (idJob *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                     size: 0x30u,
                     tag: TAG_NEW,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
    v80 = v15;
    if ( v15 != nullptr )
      v3 = (char *)idJob::idJob(this: v15, jobDecl: v14);
    else
      v3 = nullptr;
    p_specialEventAreaTrackers = nullptr;
    *((_DWORD *)v3 + 6) = v95;
    *((_DWORD *)v3 + 4) = v96;
    if ( v91 > 0 )
    {
      m = -4;
      do
      {
        v94 = 0;
        v107.allocedAndFlag = 20;
        v107.data = v107.baseBuffer;
        v107.len = 0;
        v107.baseBuffer[0] = 0;
        idFile::ReadString(this: file, string: &v107);
        file->Read(this: file, a2: &v94, a3: 4u);
        k = v107.data;
        if ( v107.data != nullptr
          && (v16 = (const idDeclJobNote *)idDeclInfo::FindWithInheritance(
                                             this: &idDeclJobNote::resourceList,
                                             name: v107.data,
                                             makeDefault: false)) != nullptr )
        {
          v17 = idJob::AddJobNote(this: (idJob *)v3, jobNoteDecl: v16, force: false);
        }
        else
        {
          idLib::Warning(fmt: "Unknown job note '%s'", k);
          v17 = 0;
        }
        if ( v17 != 0 )
        {
          m += 4;
          *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 8) + m) + 8) = v94;
        }
        else
        {
          k = v107.data;
          JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v90, result: (idStrId *)v14);
          LocalizedString = idStrId::GetLocalizedString(this: JobName);
          idLib::Warning(fmt: "Unable to add job note %s, for job %s", k, LocalizedString);
        }
        idStr::FreeData(this: &v107);
        p_specialEventAreaTrackers = (idDeclInfoTemplate<idDeclSpecialEvent> *)((char *)p_specialEventAreaTrackers + 1);
      }
      while ( (int)p_specialEventAreaTrackers < v91 );
    }
    num = this->jobs.num;
    v21 = 0;
    v80 = v3;
    if ( num <= 0 )
      goto LABEL_26;
    v22 = 0;
    while ( (char *)this->jobs.list[v22] != v3 )
    {
      ++v21;
      ++v22;
      if ( v21 >= num )
        goto LABEL_26;
    }
    if ( v21 < 0 )
LABEL_26:
      idList<idAnimWebBlendTree *,5>::Append(
        (idList<enum encounterGroupRole_t,5> *)this,
        obj: (encounterGroupRole_t *)&v80);
    idStr::FreeData(this: &v102);
  }
  file->Read(this: file, a2: &this->activeJobIndex, a3: 4u);
  v86 = 0;
  file->Read(this: file, a2: &v86, a3: 4u);
  m = 0;
  if ( v86 > 0 )
  {
    while ( 1 )
    {
      v104.allocedAndFlag = 20;
      v104.len = 0;
      v104.data = v104.baseBuffer;
      v104.baseBuffer[0] = 0;
      idFile::ReadString(this: file, string: &v104);
      if ( v104.len == 0 )
        break;
      v23 = (idAIPlayerInteractionMemory *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                             size: 0x44u,
                                             tag: TAG_NEW,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
      v90 = v23;
      if ( v23 != nullptr )
        v3 = (char *)idAIPlayerInteractionMemory::idAIPlayerInteractionMemory(this: v23, interactionDeclName: v104.data);
      else
        v3 = nullptr;
_M513788_0:
      if ( v3 == nullptr )
        goto _LN534;
      v83 = 0;
      file->Read(this: file, a2: &v83, a3: 4u);
      for ( j = 0; j < v83; ++j )
      {
        v82[0] = false;
        file->Read(this: file, a2: v82, a3: 1u);
        idAIPlayerInteractionMemory::SetInteractionApproachPlayed(
          this: (idAIPlayerInteractionMemory *)v3,
          interactionNumber: j,
          played: v82[0],
          a4: v29,
          a5: v28,
          a6: v27,
          a7: v26,
          a8: v25,
          a9: v72,
          a10: v73,
          a11: v74,
          a12: v75,
          a13: v76,
          a14: v77,
          a15: v78,
          a16: v79);
      }
      file->Read(this: file, a2: &v83, a3: 4u);
      for ( k = nullptr; (int)k < v83; ++k )
      {
        v81 = false;
        file->Read(this: file, a2: &v81, a3: 1u);
        idAIPlayerInteractionMemory::SetJobOfferPlayed(
          this: (idAIPlayerInteractionMemory *)v3,
          interactionNumber: (int)k,
          played: v81,
          a4: v34,
          a5: v33,
          a6: v32,
          a7: v31,
          a8: v30,
          a9: v72,
          a10: v73,
          a11: v74,
          a12: v75,
          a13: v76,
          a14: v77,
          a15: v78,
          a16: v79);
      }
      v35 = this->playerInteractionMemories.num;
      p_playerInteractionMemories = (idList<enum encounterGroupRole_t,5> *)&this->playerInteractionMemories;
      v80 = v3;
      v37 = 0;
      if ( v35 <= 0 )
        goto LABEL_44;
      v38 = 0;
      while ( (char *)p_playerInteractionMemories->list[v38] != v3 )
      {
        ++v37;
        ++v38;
        if ( v37 >= v35 )
          goto LABEL_44;
      }
      if ( v37 < 0 )
LABEL_44:
        idList<idAnimWebBlendTree *,5>::Append(this: p_playerInteractionMemories, obj: (encounterGroupRole_t *)&v80);
      idStr::FreeData(this: &v104);
      if ( ++m >= v86 )
        goto LABEL_46;
    }
    idLib::Error(fmt: "idJobManager::ReadFromSnapshot Empty Interaction Name");
_LN534:
    idLib::Error(fmt: "idJobManager::ReadFromSnapshot NULL interaction Memory");
    goto _LN535;
  }
LABEL_46:
  v84 = 0;
  file->Read(this: file, a2: &v84, a3: 4u);
  for ( m = 0; m < v84; ++m )
  {
    v103.allocedAndFlag = 20;
    v103.len = 0;
    v103.data = v103.baseBuffer;
    v103.baseBuffer[0] = 0;
    idFile::ReadString(this: file, string: &v103);
    if ( v103.len == 0 )
    {
      idLib::Error(fmt: "idJobManager::ReadFromSnapshot Empty Race Name");
      goto _LN536;
    }
    file->Read(this: file, a2: &v99, a3: 4u);
    file->Read(this: file, a2: &v101, a3: 4u);
    v3 = v103.data;
    k = v99;
    RaceStatusMemory = idJobManager::FindRaceStatusMemory(this, raceDeclName: v103.data);
    if ( RaceStatusMemory != nullptr )
    {
      RaceStatusMemory->bestPlace = (raceMemoryPlace_t)k;
    }
    else
    {
_LN535:
      v40 = idRaceStatusMemory::Create(raceDeclName: v3);
      v80 = v40;
      v42 = 0;
      v40->bestPlace = (raceMemoryPlace_t)k;
      p_raceStatusMemories = (idList<enum encounterGroupRole_t,5> *)&this->raceStatusMemories;
      v43 = this->raceStatusMemories.num;
      if ( v43 <= 0 )
        goto LABEL_58;
      v44 = 0;
      while ( (idRaceStatusMemory *)p_raceStatusMemories->list[v44] != v40 )
      {
        ++v42;
        ++v44;
        if ( v42 >= v43 )
          goto LABEL_58;
      }
      if ( v42 < 0 )
LABEL_58:
        idList<idAnimWebBlendTree *,5>::Append(this: p_raceStatusMemories, obj: (encounterGroupRole_t *)&v80);
    }
    owner = this->owner;
    if ( owner != nullptr )
      idAchievementManager::RaceCompletesAchievement(
        this: &owner->achievementManager,
        raceName: v3,
        place: (raceMemoryPlace_t)k);
    v46 = v101;
    v47 = v103.data;
    v48 = idJobManager::FindRaceStatusMemory(this, raceDeclName: v103.data);
    if ( v48 != nullptr )
    {
      v48->difficulyDelta = v46;
    }
    else
    {
      v49 = idRaceStatusMemory::Create(raceDeclName: v47);
      v80 = v49;
      v51 = 0;
      v49->bestPlace = RACEMEMORY_UNRACED;
      v49->difficulyDelta = v46;
      v50 = (idList<enum encounterGroupRole_t,5> *)&this->raceStatusMemories;
      v52 = this->raceStatusMemories.num;
      if ( v52 <= 0 )
        goto LABEL_69;
      v53 = 0;
      while ( (idRaceStatusMemory *)v50->list[v53] != v49 )
      {
        ++v51;
        ++v53;
        if ( v51 >= v52 )
          goto LABEL_69;
      }
      if ( v51 < 0 )
LABEL_69:
        idList<idAnimWebBlendTree *,5>::Append(this: v50, obj: (encounterGroupRole_t *)&v80);
    }
    idStr::FreeData(this: &v103);
  }
  v88 = 0;
  file->Read(this: file, a2: &v88, a3: 4u);
  m = 0;
  if ( v88 > 0 )
  {
    v3 = (char *)&idDeclGameStateInt::resourceList;
    while ( 1 )
    {
      v105.allocedAndFlag = 20;
      v105.len = 0;
      v105.data = v105.baseBuffer;
      v105.baseBuffer[0] = 0;
      idFile::ReadString(this: file, string: &v105);
      v97 = 0;
      file->Read(this: file, a2: &v97, a3: 4u);
      v54 = v105.data;
      if ( v105.data == nullptr )
        goto LABEL_94;
      v55 = (const idDeclGameStateInt *)idDeclInfo::FindWithInheritance(
                                          this: (idDeclInfo *)v3,
                                          name: v105.data,
                                          makeDefault: false);
      if ( v55 == nullptr )
        break;
      v56 = (idGameStateInt *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0xCu,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      v90 = v56;
      if ( v56 != nullptr )
        v57 = idGameStateInt::idGameStateInt(this: v56, gameStateDecl: v55);
      else
_LN536:
        v57 = nullptr;
      p_gameStateInts = (idList<enum encounterGroupRole_t,5> *)&this->gameStateInts;
      v80 = v57;
      v59 = 0;
      v57->gameStateValue = v97;
      v60 = this->gameStateInts.num;
      if ( v60 <= 0 )
        goto LABEL_85;
      v61 = 0;
      while ( (idGameStateInt *)p_gameStateInts->list[v61] != v57 )
      {
        ++v59;
        ++v61;
        if ( v59 >= v60 )
          goto LABEL_85;
      }
      if ( v59 < 0 )
LABEL_85:
        idList<idAnimWebBlendTree *,5>::Append(this: p_gameStateInts, obj: (encounterGroupRole_t *)&v80);
      idStr::FreeData(this: &v105);
      if ( ++m >= v88 )
        goto LABEL_87;
    }
    v54 = v105.data;
LABEL_94:
    idLib::Error(fmt: "idJobManager::ReadFromSnapshot, unknown gameStateInt %s", v54);
    goto _LN537;
  }
LABEL_87:
  v92 = 0;
  file->Read(this: file, a2: &v92, a3: 4u);
  v3 = nullptr;
  if ( v92 > 0 )
  {
    m = (int)&idSpecialEvent::`vftable';
    p_specialEventAreaTrackers = &idDeclSpecialEvent::resourceList;
    while ( 1 )
    {
      v106.allocedAndFlag = 20;
      v106.len = 0;
      v106.data = v106.baseBuffer;
      v106.baseBuffer[0] = 0;
      idFile::ReadString(this: file, string: &v106);
      v62 = v106.data;
      if ( v106.data == nullptr )
        goto LABEL_102;
      v63 = idDeclInfo::FindWithInheritance(this: p_specialEventAreaTrackers, name: v106.data, makeDefault: false);
      if ( v63 == nullptr )
        break;
      v64 = (int *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                     size: 8u,
                     tag: TAG_NEW,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
      if ( v64 != nullptr )
      {
        v64[1] = (int)v63;
        v65 = v64;
        *v64 = m;
      }
      else
      {
_LN537:
        v65 = nullptr;
      }
      v80 = v65;
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->specialEvent_Jumps,
        obj: (encounterGroupRole_t *)&v80);
      idStr::FreeData(this: &v106);
      if ( (int)++v3 >= v92 )
        goto LABEL_97;
    }
    v62 = v106.data;
LABEL_102:
    idLib::Error(fmt: "idJobManager::ReadFromSnapshot, unknown specialEventDecl %s", v62);
    goto _LN538;
  }
LABEL_97:
  v87 = 0;
  file->Read(this: file, a2: &v87, a3: 4u);
  m = 0;
  if ( v87 > 0 )
  {
    p_specialEventAreaTrackers = (idDeclInfoTemplate<idDeclSpecialEvent> *)&this->specialEventAreaTrackers;
    do
    {
      v66 = (idSpecialEvent_Area_Tracker *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                             size: 0x34u,
                                             tag: TAG_NEW,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
      v90 = v66;
      if ( v66 != nullptr )
        v67 = idSpecialEvent_Area_Tracker::idSpecialEvent_Area_Tracker(this: v66);
      else
_LN538:
        v67 = nullptr;
      v80 = v67;
      idFile::ReadString(this: file, string: &v67->areaDecl);
      v85 = 0;
      file->Read(this: file, a2: &v85, a3: 4u);
      v68 = 0;
      if ( v85 > 0 )
      {
        p_jobStingersPlayed = (idList<enum encounterGroupRole_t,5> *)&v67->jobStingersPlayed;
        do
        {
          v98 = 0;
          file->Read(this: file, a2: &v98, a3: 4u);
          idList<idAnimWebBlendTree *,5>::Append(this: p_jobStingersPlayed, obj: (encounterGroupRole_t *)&v98);
          ++v68;
        }
        while ( v68 < v85 );
      }
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)p_specialEventAreaTrackers,
        obj: (encounterGroupRole_t *)&v80);
      ++m;
    }
    while ( m < v87 );
  }
  file->Read(this: file, a2: &this->useAlternateHands, a3: 1u);
  file->Read(this: file, a2: &this->newVehicleGarage, a3: 4u);
  v89 = 0;
  file->Read(this: file, a2: &v89, a3: 4u);
  for ( n = 0; n < v89; ++n )
  {
    v108.allocedAndFlag = 20;
    v108.len = 0;
    v108.data = v108.baseBuffer;
    v108.baseBuffer[0] = 0;
    idFile::ReadString(this: file, string: &v108);
    idList<idStr,5>::Append(this: &this->dlcRewardsRecieved, obj: &v108);
    idStr::FreeData(this: &v108);
  }
  v71 = file->Tell(this: file) - v10;
  file->Read(this: file, a2: &v100, a3: 4u);
  if ( v71 != v100 )
    idLib::Error(fmt: "idJobManager save is corrupt, Read %d bytes.. stored claims %d available", v71, v100);
  if ( gameLocal != nullptr && gameLocal->world != nullptr )
    idJobManager::CheckActiveJobVersusMap(this);
}


// ========================================================================
// $LN461
// EA  : 0x82E19E90
// RVA : 0x00E19E90
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _LN461()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 176));
}


// ========================================================================
// __unwind$512860_0
// EA  : 0x82E19EB8
// RVA : 0x00E19EB8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall _unwind_512860_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 560 + 80), tag: a2);
}


// ========================================================================
// __unwind$512861
// EA  : 0x82E19EE0
// RVA : 0x00E19EE0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512861()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 336));
}


// ========================================================================
// __unwind$512862
// EA  : 0x82E19F08
// RVA : 0x00E19F08
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512862()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 240));
}


// ========================================================================
// __unwind$512863
// EA  : 0x82E19F30
// RVA : 0x00E19F30
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall _unwind_512863(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 560 + 116), tag: a2);
}


// ========================================================================
// __unwind$512864_0
// EA  : 0x82E19F58
// RVA : 0x00E19F58
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512864_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 208));
}


// ========================================================================
// __unwind$512865_0
// EA  : 0x82E19F80
// RVA : 0x00E19F80
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512865_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 272));
}


// ========================================================================
// __unwind$512866
// EA  : 0x82E19FA8
// RVA : 0x00E19FA8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall _unwind_512866(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 560 + 116), tag: a2);
}


// ========================================================================
// __unwind$512867
// EA  : 0x82E19FD0
// RVA : 0x00E19FD0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512867()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 304));
}


// ========================================================================
// __unwind$512869
// EA  : 0x82E19FF8
// RVA : 0x00E19FF8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall _unwind_512869(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 560 + 116), tag: a2);
}


// ========================================================================
// __unwind$512870
// EA  : 0x82E1A020
// RVA : 0x00E1A020
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_512870()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 368));
}


// ========================================================================
// ?AddJobNote@idJobManager@@QAAXPBVidDeclJobNote@@_N11@Z
// EA  : 0x82E1A048
// RVA : 0x00E1A048
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::AddJobNote(
        idJobManager *this,
        const idDeclJobNote *jobNote,
        bool force,
        bool updateHUD,
        bool checkForActiveJob)
{
  const idDeclJobNote *removeNote; // r4
  idJob *InventoryItemByDeclName; // r3
  idJob *v12; // r30
  missionStatus_t status; // r11
  char v14; // r11
  bool v15; // zf

  if ( jobNote != nullptr )
  {
    if ( jobNote->jobDeclReference.len != 0 )
    {
      removeNote = jobNote->removeNote;
      if ( removeNote != nullptr )
        idJobManager::RemoveJobNote(this, jobNoteDecl: removeNote, checkForActiveJob: false);
      InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                  this,
                                  jobName: jobNote->jobDeclReference.data);
      v12 = InventoryItemByDeclName;
      if ( InventoryItemByDeclName != nullptr )
      {
        if ( !checkForActiveJob )
          goto LABEL_16;
        status = InventoryItemByDeclName->status;
        if ( status == JOBSTATUS_READYTOTURNIN || (v15 = status != JOBSTATUS_ACCEPTED, v14 = 0, !v15) )
          v14 = 1;
        if ( v14 != 0 )
        {
LABEL_16:
          if ( (unsigned __int8)idJob::AddJobNote(this: InventoryItemByDeclName, jobNoteDecl: jobNote, force) != 0
            && updateHUD )
          {
            idJobManager::UpdatePlayerHud(
              this,
              job: v12,
              requirementNum: -1,
              playSound: true,
              treatAsSameStatusUpdate: true);
          }
        }
      }
      else if ( jobDebug_JobNoteWarnings.valueInteger != 0 )
      {
        idLib::Warning(
          fmt: "job %s note currently held in AddJobNote for %s: ",
          jobNote->jobDeclReference.data,
          jobNote->name.str);
      }
    }
    else if ( jobDebug_JobNoteWarnings.valueInteger != 0 )
    {
      idLib::Warning(fmt: "jobnote has no job Reference in AddJobNote");
    }
  }
  else if ( jobDebug_JobNoteWarnings.valueInteger != 0 )
  {
    idLib::Warning(fmt: "NULL jobnote in AddJobNote");
  }
}


// ========================================================================
// ?Think@idJobManager@@QAAXXZ
// EA  : 0x82E1A1B0
// RVA : 0x00E1A1B0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::Think(idJobManager *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idJobManager::Think");
  LODWORD(v2) = "idJobManager::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
  this->saveRequested = false;
  idPLogScope::~idPLogScope(this: v4);
  RD_EventEnd();
}


// ========================================================================
// __unwind$513930
// EA  : 0x82E1A208
// RVA : 0x00E1A208
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_513930()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$513931
// EA  : 0x82E1A230
// RVA : 0x00E1A230
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_513931()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateRelevantJobNotesForMap@idJobManager@@QAAXXZ
// EA  : 0x82E1A258
// RVA : 0x00E1A258
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::UpdateRelevantJobNotesForMap(idJobManager *this)
{
  int v2; // r27
  int v3; // r28
  idJob *v4; // r11
  missionStatus_t status; // r11
  char v6; // r11
  bool v7; // zf
  int v8; // r30
  const idDeclJob *decl; // r11
  int v10; // r31
  int v11; // r30
  int v12; // r31

  v2 = 0;
  if ( this->jobs.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->jobs.list[v3];
      if ( v4 != nullptr )
      {
        status = v4->status;
        if ( status == JOBSTATUS_READYTOTURNIN || (v7 = status != JOBSTATUS_ACCEPTED, v6 = 0, !v7) )
          v6 = 1;
        if ( v6 != 0 && (unsigned __int8)idJob::JobCaresAboutCurrentMap(this: this->jobs.list[v3]) != 0 )
        {
          v8 = 0;
          decl = this->jobs.list[v3]->decl;
          if ( decl->jobNoteInfo.relevantMapNotesRemove.num > 0 )
          {
            v10 = 0;
            do
            {
              idJobManager::RemoveJobNote(
                this,
                jobNoteDecl: decl->jobNoteInfo.relevantMapNotesRemove.list[v10],
                checkForActiveJob: false);
              ++v8;
              ++v10;
              decl = this->jobs.list[v3]->decl;
            }
            while ( v8 < decl->jobNoteInfo.relevantMapNotesRemove.num );
          }
          v11 = 0;
          if ( decl->jobNoteInfo.relevantMapNotes.num > 0 )
          {
            v12 = 0;
            do
            {
              idJobManager::AddJobNote(
                this,
                jobNote: decl->jobNoteInfo.relevantMapNotes.list[v12],
                force: false,
                updateHUD: true,
                checkForActiveJob: false);
              ++v11;
              ++v12;
              decl = this->jobs.list[v3]->decl;
            }
            while ( v11 < decl->jobNoteInfo.relevantMapNotes.num );
          }
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->jobs.num );
  }
}


// ========================================================================
// ?CompleteJob@idJobManager@@QAA_NPBVidDeclJob@@_N11@Z
// EA  : 0x82E1A398
// RVA : 0x00E1A398
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::CompleteJob(
        idJobManager *this,
        idStrId *jobDecl,
        bool completeTree,
        bool giveJob,
        bool force)
{
  BOOL inDebug; // r27
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  idJob *JobByDecl; // r3
  BOOL v14; // r23
  idJob *v15; // r25
  missionStatus_t status; // r10
  char v17; // r11
  BOOL v18; // r30
  idStrId *v19; // r3
  const char *v20; // r3
  int v22; // r10
  int v23; // r11
  idJobManager *v24; // r3
  int v25; // r28
  idDeclJob *DebugInfo; // r3
  const idDeclJobTimerEvent *index; // r4
  idPlayer *owner; // r11
  __int64 v29; // r10
  __int64 v30; // r8
  int v31; // r6
  const idDeclJob *v32; // r3
  const idDeclJob *v33; // r28
  int v34; // r27
  int v35; // r28
  int v36; // r27
  int v37; // r28
  BOOL v38; // r30
  idStrId *v39; // r3
  const char *v40; // r3
  BOOL v41; // r30
  idStrId *v42; // r3
  const char *v43; // r3
  int v44[4]; // [sp+50h] [-A0h] BYREF
  idDeclCloth::ropeInfo v45[3]; // [sp+60h] [-90h] BYREF

  if ( jobDecl == nullptr )
  {
    idLib::Warning(fmt: "NULL jobDecl in CompleteJob");
    return 0;
  }
  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    inDebug = this->inDebug;
    JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v44, result: jobDecl);
    LocalizedString = idStrId::GetLocalizedString(this: JobName);
    idLib::Printf(
      fmt: "CompleteJob %s, complete: %d, give: %d, debug: %d, force: %d\n",
      LocalizedString,
      completeTree,
      giveJob,
      inDebug,
      force);
  }
  JobByDecl = idJobManager::FindJobByDecl(this, (const idDeclJob *)jobDecl);
  v14 = force;
  v15 = JobByDecl;
  if ( force || giveJob && (JobByDecl == nullptr || JobByDecl->status < JOBSTATUS_ACCEPTED) )
  {
    idJobManager::AcceptJob(this, (const idDeclJob *)jobDecl, completeTree, force);
    if ( v15 != nullptr )
      goto LABEL_12;
    v15 = idJobManager::FindJobByDecl(this, (const idDeclJob *)jobDecl);
  }
  if ( v15 == nullptr )
  {
LABEL_60:
    if ( jobDebug_PrintChanges.valueInteger != 0 )
    {
      v41 = this->inDebug;
      v42 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v44, result: jobDecl);
      v43 = idStrId::GetLocalizedString(this: v42);
      idLib::Printf(
        fmt: "FAILED:\tCompleteJob %s, complete: %d, give: %d, debug: %d, force: %d\n",
        v43,
        completeTree,
        giveJob,
        v41,
        force);
    }
    return 0;
  }
LABEL_12:
  if ( !force )
  {
    status = v15->status;
    if ( status == JOBSTATUS_READYTOTURNIN || (v17 = 0, status == JOBSTATUS_ACCEPTED) )
      v17 = 1;
    if ( v17 == 0 && status != JOBSTATUS_READYTOTURNIN_UNKNOWN )
      goto LABEL_60;
  }
  if ( (_cntlzw(v15->status - 2) & 0x20) != 0 )
  {
    idJobManager::SetJobReadyToTurnIn(
      this,
      (const idDeclJob *)jobDecl,
      completeTree,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    if ( v15->status == JOBSTATUS_COMPLETED )
    {
      if ( jobDebug_PrintChanges.valueInteger != 0 )
      {
        v18 = this->inDebug;
        v19 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v44, result: jobDecl);
        v20 = idStrId::GetLocalizedString(this: v19);
        idLib::Printf(
          fmt: "COMPLETE:\tJob completed by being set ready to turn in. %s, complete: %d, give: %d, debug: %d, force: %d\n",
          v20,
          completeTree,
          giveJob,
          v18,
          force);
      }
      return 1;
    }
  }
  idJob::SetJobStatus(
    this: v15,
    newStatus: JOBSTATUS_COMPLETED,
    manager: this,
    fireOffJobTargets: false,
    debug: this->inDebug);
  v22 = 0;
  v44[0] = this->jobs.num;
  if ( v44[0] <= 0 )
  {
LABEL_27:
    v22 = -1;
  }
  else
  {
    v23 = 0;
    while ( (idStrId *)this->jobs.list[v23]->decl != jobDecl )
    {
      ++v22;
      ++v23;
      if ( v22 >= v44[0] )
        goto LABEL_27;
    }
  }
  if ( this->activeJobIndex == v22 && jobDecl[25].index != 5 )
    idJobManager::SetActiveJobIndexForNextActiveJob(this);
  v24 = this;
  if ( jobDecl[25].index == 5 )
  {
    v25 = 0;
    if ( (unsigned __int8)idJobManager::JobMeetsCompletionCriteria(this, (const idDeclJob *)jobDecl) == 0 )
      goto LABEL_38;
    while ( 1 )
    {
      idJobManager::GiveRewards(this, rewards: (const idList<idDeclJob::jobReward_t,5> *)&jobDecl[46]);
      idJobManager::RemoveCompletionConditions(
        this,
        completion: (const idList<idDeclJob::jobComplete_t,5> *)&jobDecl[42]);
      if ( ++v25 > 10000 )
        break;
      if ( (unsigned __int8)idJobManager::JobMeetsCompletionCriteria(this, (const idDeclJob *)jobDecl) == 0 )
        goto LABEL_38;
    }
    idLib::Error(fmt: "Infinitely Repeating Job completion:  %s", (const char *)jobDecl[2].index);
  }
  idJobManager::GiveRewards(this: v24, rewards: (const idList<idDeclJob::jobReward_t,5> *)&jobDecl[46]);
  idJobManager::RemoveCompletionConditions(this, completion: (const idList<idDeclJob::jobComplete_t,5> *)&jobDecl[42]);
LABEL_38:
  if ( this->inDebug && !this->hackIgnoreDebugRewards )
  {
    DebugInfo = idDeclJob::GetDebugInfo(this: (idDeclJob *)v45, result: (idDeclJob::jobDebugMasterInfo_t *)jobDecl);
    idJobManager::GiveRewards(this, rewards: (const idList<idDeclJob::jobReward_t,5> *)&DebugInfo->idResource + 2);
    idDeclCloth::ropeInfo::~ropeInfo(this: v45);
  }
  idJobManager::FireOffJobTargets(this, job: v15, debug: this->inDebug);
  index = (const idDeclJobTimerEvent *)jobDecl[29].index;
  if ( index != nullptr )
  {
    owner = this->owner;
    if ( owner != nullptr )
      idJobTimerManager::CompleteIteration(
        this: &owner->jobTimerManager,
        inEventDecl: index,
        inJobDecl: (const idDeclJob *)jobDecl,
        player: this->owner);
  }
  v44[0] = -1;
  v32 = idJobManager::CanJobCompletionCompleteAJob(this, job: (const idDeclJob *)jobDecl, requirementNum: v44);
  v33 = v32;
  if ( v32 != nullptr && (unsigned __int8)idJobManager::IsJobReadyToTurnIn(this, jobDecl: v32) != 0 )
    idJobManager::SetJobReadyToTurnIn(
      this,
      jobDecl: v33,
      completeTree: false,
      giveJobIfNeeded: false,
      hideIfGiven: false,
      force: false);
  if ( jobDecl[25].index == 5 )
    idEventReceiver::PostEventMS(this: v15, ev: &EV_DoRepeat, time: 500, a4: v31, a5: v30, a6: v29);
  if ( g_debugLayers.valueInteger != 0 )
    idLib::Printf(fmt: "idJobManager::CompleteJob: adding layers for job '%s'\n", (const char *)jobDecl[2].index);
  v34 = 0;
  if ( jobDecl[112].index > 0 )
  {
    v35 = 0;
    do
    {
      idJobManager::AddJobNote(
        this,
        jobNote: *(const idDeclJobNote **)(v35 + jobDecl[111].index),
        force: false,
        updateHUD: true,
        checkForActiveJob: false);
      ++v34;
      v35 += 4;
    }
    while ( v34 < jobDecl[112].index );
  }
  v36 = 0;
  if ( jobDecl[116].index > 0 )
  {
    v37 = 0;
    do
    {
      idJobManager::RemoveJobNote(
        this,
        jobNoteDecl: *(const idDeclJobNote **)(v37 + jobDecl[115].index),
        checkForActiveJob: false);
      ++v36;
      v37 += 4;
    }
    while ( v36 < jobDecl[116].index );
  }
  idJobManager::TransitionToNextPosition(this, job: v15);
  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    v38 = this->inDebug;
    v39 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v44, result: jobDecl);
    v40 = idStrId::GetLocalizedString(this: v39);
    idLib::Printf(
      fmt: "COMPLETE:\tCompleteJob %s, complete: %d, give: %d, debug: %d, force: %d\n",
      v40,
      completeTree,
      giveJob,
      v38,
      v14);
  }
  return 1;
}


// ========================================================================
// $LN366
// EA  : 0x82E1A884
// RVA : 0x00E1A884
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _LN366()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(v0 - 240 + 96));
}


// ========================================================================
// ?UnCompleteJob@idJobManager@@QAA_NPBVidDeclJob@@@Z
// EA  : 0x82E1A8B8
// RVA : 0x00E1A8B8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::UnCompleteJob(idJobManager *this, const idDeclJob *jobDecl)
{
  idJob *JobByDecl; // r29
  idStrId *v6; // r4
  BOOL inDebug; // r28
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  int status; // r27
  idDeclJob *DebugInfo; // r3
  idDeclJob *v12; // r3
  idDeclJob *v13; // r3
  int v14; // r10
  int num; // r9
  int v16; // r11
  const idDeclJob *decl; // [sp+50h] [-80h] BYREF
  idDeclCloth::ropeInfo v18[2]; // [sp+60h] [-70h] BYREF

  if ( jobDecl == nullptr )
  {
    idLib::Warning(fmt: "NULL jobDecl in UnCompleteJob");
    return 0;
  }
  JobByDecl = idJobManager::FindJobByDecl(this, jobDecl);
  if ( JobByDecl == nullptr )
    return 0;
  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    inDebug = this->inDebug;
    JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&decl, result: v6);
    LocalizedString = idStrId::GetLocalizedString(this: JobName);
    idLib::Printf(fmt: "UnCompleteJob %s, debug: %d\n", LocalizedString, inDebug);
  }
  status = JobByDecl->status;
  idJob::SetJobStatus(
    this: JobByDecl,
    newStatus: JOBSTATUS_NONE,
    manager: this,
    fireOffJobTargets: true,
    debug: this->inDebug);
  if ( status >= 5 )
  {
    if ( g_debugLayers.valueInteger != 0 )
      idLib::Printf(fmt: "idJobManager::UnCompleteJob: reverting 'complete' layers for job '%s'\n", jobDecl->name.str);
    decl = JobByDecl->decl;
    idJobManager::RemoveRewards(this, jobDecl: decl, rewards: &decl->rewards);
    if ( this->inDebug )
    {
      DebugInfo = idDeclJob::GetDebugInfo(this: (idDeclJob *)v18, result: (idDeclJob::jobDebugMasterInfo_t *)jobDecl);
      idJobManager::RemoveRewards(
        this,
        jobDecl: JobByDecl->decl,
        rewards: (const idList<idDeclJob::jobReward_t,5> *)&DebugInfo->idResource + 2);
      idDeclCloth::ropeInfo::~ropeInfo(this: v18);
    }
  }
  if ( status >= 3 )
  {
    if ( g_debugLayers.valueInteger != 0 )
      idLib::Printf(
        fmt: "idJobManager::UnCompleteJob: reverting 'readyToTurnIn' layers for job '%s'\n",
        jobDecl->name.str);
    decl = JobByDecl->decl;
    idJobManager::RemoveRewards(this, jobDecl: decl, rewards: &decl->readyRewards);
    if ( this->inDebug )
    {
      v12 = idDeclJob::GetDebugInfo(this: (idDeclJob *)v18, result: (idDeclJob::jobDebugMasterInfo_t *)jobDecl);
      idJobManager::RemoveRewards(
        this,
        jobDecl: JobByDecl->decl,
        rewards: (const idList<idDeclJob::jobReward_t,5> *)&v12->resourceListPtr);
      idDeclCloth::ropeInfo::~ropeInfo(this: v18);
    }
  }
  if ( status >= 2 )
  {
    if ( g_debugLayers.valueInteger != 0 )
      idLib::Printf(fmt: "idJobManager::UnCompleteJob: reverting 'accept' layers for job '%s'\n", jobDecl->name.str);
    decl = JobByDecl->decl;
    idJobManager::RemoveRewards(this, jobDecl: decl, rewards: &decl->acceptRewards);
    if ( this->inDebug )
    {
      v13 = idDeclJob::GetDebugInfo(this: (idDeclJob *)v18, result: (idDeclJob::jobDebugMasterInfo_t *)jobDecl);
      idJobManager::RemoveRewards(
        this,
        jobDecl: JobByDecl->decl,
        rewards: (const idList<idDeclJob::jobReward_t,5> *)v13);
      idDeclCloth::ropeInfo::~ropeInfo(this: v18);
    }
  }
  v14 = 0;
  JobByDecl->triggeredCount = 0;
  num = this->jobs.num;
  if ( num <= 0 )
  {
LABEL_26:
    v14 = -1;
  }
  else
  {
    v16 = 0;
    while ( this->jobs.list[v16]->decl != jobDecl )
    {
      ++v14;
      ++v16;
      if ( v14 >= num )
        goto LABEL_26;
    }
  }
  if ( this->activeJobIndex == v14 )
    idJobManager::SetActiveJobIndexForNextActiveJob(this);
  return 1;
}


// ========================================================================
// __unwind$514546
// EA  : 0x82E1AB04
// RVA : 0x00E1AB04
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_514546()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$514547
// EA  : 0x82E1AB2C
// RVA : 0x00E1AB2C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_514547()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$514548
// EA  : 0x82E1AB54
// RVA : 0x00E1AB54
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_514548()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(v0 - 208 + 96));
}


// ========================================================================
// ?GiveSpecialEventArea@idJobManager@@QAA_NPBVidDeclSpecialEvent_Area@@@Z
// EA  : 0x82E1AB80
// RVA : 0x00E1AB80
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::GiveSpecialEventArea(idJobManager *this, const idDeclSpecialEvent_Area *specialEventArea)
{
  int v5; // r29
  int v6; // r30
  int v7; // r29
  int v8; // r30

  if ( this->owner == nullptr )
  {
    idLib::Warning(fmt: "no owner in idJobManager::GiveSpecialEventArea");
    return 0;
  }
  if ( specialEventArea == nullptr || this->specialEventAreaDecl == specialEventArea )
    return 0;
  this->specialEventAreaDecl = specialEventArea;
  idJobManager::CheckActiveJobVersusRelevantJobs(this, relevantJobs: &specialEventArea->relevantJobs);
  if ( g_showAreaText.valueInteger != 0 )
    idJobManager::PlaySpecialEventNewAreaSound(this, (idDeclSpecialEvent_Area::jobStinger_t *)specialEventArea);
  v5 = 0;
  if ( specialEventArea->removeJobNotes.num > 0 )
  {
    v6 = 0;
    do
    {
      idJobManager::RemoveJobNote(this, jobNoteDecl: specialEventArea->removeJobNotes.list[v6], checkForActiveJob: true);
      ++v5;
      ++v6;
    }
    while ( v5 < specialEventArea->removeJobNotes.num );
  }
  v7 = 0;
  if ( specialEventArea->addJobNotes.num > 0 )
  {
    v8 = 0;
    do
    {
      idJobManager::AddJobNote(
        this,
        jobNote: specialEventArea->addJobNotes.list[v8],
        force: false,
        updateHUD: true,
        checkForActiveJob: true);
      ++v7;
      ++v8;
    }
    while ( v7 < specialEventArea->addJobNotes.num );
  }
  return 1;
}


// ========================================================================
// ??0idJobTimerManager@@QAA@XZ
// EA  : 0x82E1AE10
// RVA : 0x00E1AE10
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

idJobTimerManager *__fastcall idJobTimerManager::idJobTimerManager(idJobTimerManager *this)
{
  this->active = false;
  this->iterations.granularity = 0;
  this->iterations.memTag = 5;
  this->iterations.listStatic = 0;
  this->iterations.list = nullptr;
  this->iterations.size = 0;
  this->iterations.num = 0;
  return this;
}


// ========================================================================
// ??1idJobTimerManager@@QAA@XZ
// EA  : 0x82E1AE40
// RVA : 0x00E1AE40
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::~idJobTimerManager(idJobTimerManager *this)
{
  idJobTimerIteration *list; // r3
  idJobTimerIteration *v3; // r3

  if ( this->iterations.listStatic == 0 || this->iterations.listStatic == 2 )
  {
    list = this->iterations.list;
    if ( list != nullptr )
      idListArrayDelete<idJobTimerIteration>(ptr: list, num: this->iterations.size);
    this->iterations.list = nullptr;
    this->iterations.size = 0;
  }
  this->iterations.num = 0;
  if ( this->iterations.listStatic == 0 || this->iterations.listStatic == 2 )
  {
    v3 = this->iterations.list;
    if ( v3 != nullptr )
      idListArrayDelete<idJobTimerIteration>(ptr: v3, num: this->iterations.size);
    this->iterations.list = nullptr;
    this->iterations.size = 0;
  }
  this->iterations.num = 0;
}


// ========================================================================
// __unwind$514822
// EA  : 0x82E1AECC
// RVA : 0x00E1AECC
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_514822()
{
  int v0; // r12

  idList<idJobTimerIteration,5>::Clear(this: (idList<idJobTimerIteration,5> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?StartIteration@idJobTimerManager@@QAAXPBVidDeclJobTimerEvent@@PBVidDeclJob@@@Z
// EA  : 0x82E1AF00
// RVA : 0x00E1AF00
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::StartIteration(
        idJobTimerManager *this,
        const idDeclJobTimerEvent *inEventDecl,
        const idDeclJob *inJobDecl)
{
  idJobTimerIteration *v6; // r6
  idJobTimerIteration *v7; // r6
  int num; // [sp+50h] [-60h]
  idJobTimerIteration v9[2]; // [sp+60h] [-50h] BYREF

  if ( this->active )
  {
    idLib::Warning(fmt: "idJobTimerManager got call to start iteration while already running, completing that iteration now.");
    if ( this->active )
    {
      num = this->iterations.num;
      if ( num <= 0 )
        v6 = nullptr;
      else
        v6 = &this->iterations.list[num - 1];
      if ( (unsigned __int8)idJobTimerIteration::IsRunning(this: v6) != 0 )
        idJobTimerIteration::StopTimer(this: v7, player: nullptr);
      this->active = false;
    }
  }
  memset(v9, 0, 14);
  v9[0].phases.memTag = 5;
  v9[0].phases.listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v9);
  v9[0].stoppedTime = -1;
  v9[0].eventDecl = inEventDecl;
  v9[0].jobDecl = inJobDecl;
  idList<idJobTimerIteration,5>::Append(this: &this->iterations, obj: v9);
  this->active = true;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v9);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v9);
}


// ========================================================================
// __unwind$514863
// EA  : 0x82E1AFF4
// RVA : 0x00E1AFF4
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_514863()
{
  int v0; // r12

  idJobTimerIteration::~idJobTimerIteration(this: (idJobTimerIteration *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$514938
// EA  : 0x82E1B01C
// RVA : 0x00E1B01C
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_514938()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// ?ReadFromFile@idJobTimerManager@@QAAXPAVidFile@@@Z
// EA  : 0x82E1B050
// RVA : 0x00E1B050
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobTimerManager::ReadFromFile(idJobTimerManager *this, idFile *file)
{
  int v4; // r23
  idFile_vtbl *v5; // r7
  int i; // r24
  idJobTimerPhase *list; // r4
  int v8; // r30
  int v9; // [sp+50h] [-80h] BYREF
  int v10; // [sp+54h] [-7Ch] BYREF
  idJobTimerIteration v11[4]; // [sp+60h] [-70h] BYREF

  v4 = file->Tell(this: file);
  file->Read(this: file, a2: this, a3: 1u);
  v5 = file->__vftable;
  v9 = 0;
  v5->Read(this: file, a2: &v9, a3: 4u);
  for ( i = 0; i < v9; v11[0].phases.num = 0 )
  {
    v11[0].phases.memTag = 5;
    v11[0].phases.listStatic = 0;
    memset(v11, 0, 14);
    v11[0].eventDecl = nullptr;
    v11[0].stoppedTime = -1;
    idJobTimerIteration::ReadFromFile(this: v11, file);
    idList<idJobTimerIteration,5>::Append(this: &this->iterations, obj: v11);
    if ( v11[0].phases.listStatic != 0 && v11[0].phases.listStatic != 2 )
    {
      list = v11[0].phases.list;
    }
    else
    {
      if ( v11[0].phases.list != nullptr )
        idMem::Free(this: &mem, ptr: v11[0].phases.list, align: ALIGN_16);
      list = nullptr;
      v11[0].phases.size = 0;
      v11[0].phases.list = nullptr;
    }
    v11[0].phases.num = 0;
    if ( v11[0].phases.listStatic == 0 || v11[0].phases.listStatic == 2 )
    {
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      v11[0].phases.list = nullptr;
      v11[0].phases.size = 0;
    }
    ++i;
  }
  v8 = file->Tell(this: file) - v4;
  file->Read(this: file, a2: &v10, a3: 4u);
  if ( v8 != v10 )
    idLib::Error(fmt: "idJobTimerManager save is corrupt, Read %d bytes.. stored claims %d available", v8, v10);
}


// ========================================================================
// $LN69_3
// EA  : 0x82E1B200
// RVA : 0x00E1B200
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _LN69_3()
{
  int v0; // r12

  idJobTimerIteration::~idJobTimerIteration(this: (idJobTimerIteration *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$515044
// EA  : 0x82E1B228
// RVA : 0x00E1B228
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_515044()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?ClearAllJobStatus@idJobManager@@QAAXXZ
// EA  : 0x82E1B258
// RVA : 0x00E1B258
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::ClearAllJobStatus(idJobManager *this)
{
  int num; // r4
  int v3; // r18
  int v4; // r25
  idJob **list; // r9
  idJob *v6; // r11
  const idDeclJob *decl; // r28
  int v8; // r10
  int v9; // r11
  idJob *v10; // r30
  BOOL inDebug; // r27
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  int status; // r27
  idDeclJob *DebugInfo; // r3
  idDeclJob *v16; // r3
  idDeclJob *v17; // r3
  int v18; // r10
  int v19; // r9
  int v20; // r11
  int v21; // [sp+54h] [-BCh] BYREF
  idDeclCloth::ropeInfo v22[3]; // [sp+60h] [-B0h] BYREF

  v3 = 0;
  num = this->jobs.num;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->jobs.list;
      v6 = this->jobs.list[v4];
      if ( v6 != nullptr )
      {
        decl = v6->decl;
        if ( decl != nullptr )
        {
          v8 = 0;
          if ( num > 0 )
          {
            v9 = 0;
            while ( list[v9]->decl != decl )
            {
              ++v8;
              ++v9;
              if ( v8 >= num )
                goto LABEL_36;
            }
            v10 = list[v8];
            if ( v10 != nullptr )
            {
              if ( jobDebug_PrintChanges.valueInteger != 0 )
              {
                inDebug = this->inDebug;
                JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)&v21, result: (idStrId *)decl);
                LocalizedString = idStrId::GetLocalizedString(this: JobName);
                idLib::Printf(fmt: "UnCompleteJob %s, debug: %d\n", LocalizedString, inDebug);
              }
              status = v10->status;
              idJob::SetJobStatus(
                this: v10,
                newStatus: JOBSTATUS_NONE,
                manager: this,
                fireOffJobTargets: true,
                debug: this->inDebug);
              if ( status >= 5 )
              {
                if ( g_debugLayers.valueInteger != 0 )
                  idLib::Printf(
                    fmt: "idJobManager::UnCompleteJob: reverting 'complete' layers for job '%s'\n",
                    decl->name.str);
                idJobManager::RemoveRewards(this, jobDecl: v10->decl, rewards: &v10->decl->rewards);
                if ( this->inDebug )
                {
                  DebugInfo = idDeclJob::GetDebugInfo(
                                this: (idDeclJob *)v22,
                                result: (idDeclJob::jobDebugMasterInfo_t *)decl);
                  idJobManager::RemoveRewards(
                    this,
                    jobDecl: v10->decl,
                    rewards: (const idList<idDeclJob::jobReward_t,5> *)&DebugInfo->idResource + 2);
                  idDeclCloth::ropeInfo::~ropeInfo(this: v22);
                }
              }
              if ( status >= 3 )
              {
                if ( g_debugLayers.valueInteger != 0 )
                  idLib::Printf(
                    fmt: "idJobManager::UnCompleteJob: reverting 'readyToTurnIn' layers for job '%s'\n",
                    decl->name.str);
                idJobManager::RemoveRewards(this, jobDecl: v10->decl, rewards: &v10->decl->readyRewards);
                if ( this->inDebug )
                {
                  v16 = idDeclJob::GetDebugInfo(this: (idDeclJob *)v22, result: (idDeclJob::jobDebugMasterInfo_t *)decl);
                  idJobManager::RemoveRewards(
                    this,
                    jobDecl: v10->decl,
                    rewards: (const idList<idDeclJob::jobReward_t,5> *)&v16->resourceListPtr);
                  idDeclCloth::ropeInfo::~ropeInfo(this: v22);
                }
              }
              if ( status >= 2 )
              {
                if ( g_debugLayers.valueInteger != 0 )
                  idLib::Printf(
                    fmt: "idJobManager::UnCompleteJob: reverting 'accept' layers for job '%s'\n",
                    decl->name.str);
                idJobManager::RemoveRewards(this, jobDecl: v10->decl, rewards: &v10->decl->acceptRewards);
                if ( this->inDebug )
                {
                  v17 = idDeclJob::GetDebugInfo(this: (idDeclJob *)v22, result: (idDeclJob::jobDebugMasterInfo_t *)decl);
                  idJobManager::RemoveRewards(
                    this,
                    jobDecl: v10->decl,
                    rewards: (const idList<idDeclJob::jobReward_t,5> *)v17);
                  idDeclCloth::ropeInfo::~ropeInfo(this: v22);
                }
              }
              v10->triggeredCount = 0;
              v18 = 0;
              v19 = this->jobs.num;
              if ( v19 <= 0 )
              {
LABEL_33:
                v18 = -1;
              }
              else
              {
                v20 = 0;
                while ( this->jobs.list[v20]->decl != decl )
                {
                  ++v18;
                  ++v20;
                  if ( v18 >= v19 )
                    goto LABEL_33;
                }
              }
              if ( this->activeJobIndex == v18 )
                idJobManager::SetActiveJobIndexForNextActiveJob(this);
            }
          }
        }
        else
        {
          idLib::Warning(fmt: "NULL jobDecl in UnCompleteJob");
        }
      }
LABEL_36:
      num = this->jobs.num;
      ++v3;
      ++v4;
    }
    while ( v3 < num );
  }
}


// ========================================================================
// __unwind$515270
// EA  : 0x82E1B528
// RVA : 0x00E1B528
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_515270()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$515271
// EA  : 0x82E1B550
// RVA : 0x00E1B550
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_515271()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$515272
// EA  : 0x82E1B578
// RVA : 0x00E1B578
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_515272()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(v0 - 272 + 96));
}


// ========================================================================
// ?CompleteJob@idJobManager@@QAA_NPBD_N11@Z
// EA  : 0x82E1B5A0
// RVA : 0x00E1B5A0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::CompleteJob(
        idJobManager *this,
        const char *jobName,
        bool completeTree,
        bool giveJob,
        bool force)
{
  idStrId *v10; // r4

  if ( jobName != nullptr )
  {
    v10 = (idStrId *)idDeclInfo::FindWithInheritance(this: &idDeclJob::resourceList, name: jobName, makeDefault: false);
    if ( v10 != nullptr )
      return idJobManager::CompleteJob(this, jobDecl: v10, completeTree, giveJob, force);
  }
  idLib::Warning(fmt: "Unknown job '%s'", jobName);
  return 0;
}


// ========================================================================
// ?ImportJobStrings_f@idJobManager@@SAXABVidCmdArgs@@@Z
// EA  : 0x82E1B628
// RVA : 0x00E1B628
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::ImportJobStrings_f(const idCmdArgs *args)
{
  char v2; // r15
  const char *v3; // r4
  idJobDef *list; // r18
  int size; // r16
  int num; // r20
  int v7; // r27
  int i; // r30
  int len; // r30
  char *data; // r11
  char *v11; // r10
  char v12; // r9
  idJobDef *v13; // r30
  int j; // r28
  unsigned int allocedAndFlag; // r11
  size_t v16; // r29
  int v17; // r4
  int v18; // r11
  bool v19; // zf
  size_t v20; // r29
  idStr *p_jobByeVO; // r30
  idDeclJob *v22; // r22
  __int64 v23; // r8
  __int64 v24; // r6
  char **p_data; // r30
  const idDecl *v26; // r3
  idDeclTypeInfo *v27; // r29
  const char *v28; // r4
  const char *v29; // r14
  const char *Key; // r3
  const char *v31; // r14
  const char *v32; // r3
  const char *v33; // r14
  const char *v34; // r3
  const char *v35; // r14
  const char *v36; // r3
  __int64 v37; // r10
  va *v38; // r3
  idJobDef *v39; // r29
  int k; // r30
  const char *v41; // r4
  int v42; // [sp+8h] [-1238h]
  int v43; // [sp+Ch] [-1234h]
  int v44; // [sp+10h] [-1230h]
  int v45; // [sp+14h] [-122Ch]
  int v46; // [sp+18h] [-1228h]
  int v47; // [sp+1Ch] [-1224h]
  idList<idJobDef,5> v48; // [sp+60h] [-11E0h] BYREF
  int argc; // [sp+70h] [-11D0h]
  idToken v50; // [sp+80h] [-11C0h] BYREF
  idStr v51; // [sp+D0h] [-1170h] BYREF
  idLexer v52; // [sp+F0h] [-1150h] BYREF
  idStr v53; // [sp+180h] [-10C0h] BYREF
  va v54; // [sp+1A0h] [-10A0h] BYREF

  v2 = 0;
  argc = args->argc;
  if ( argc != 2 )
  {
    if ( argc != 3 || idStr::Icmp(s1: args->argv[2], s2: "addjobs") != 0 )
    {
      idLib::Printf(fmt: "USAGE: importJobStrings <.csv file> [addjobs]\n");
      idLib::Printf(fmt: "If 'addjobs' is specified, jobs that don't already exists will be added.\n");
      return;
    }
    v2 = 1;
  }
  idLexer::idLexer(this: &v52, flags_: 0);
  if ( args->argc <= 1 )
    v3 = &byte_8200D768;
  else
    v3 = args->argv[1];
  if ( idLexer::LoadFile(this: &v52, filename_: v3, OSPath: false) )
  {
    *(_WORD *)&v48.memTag = 1280;
    list = nullptr;
    size = 0;
    num = 0;
    memset(&v48, 0, 14);
    v50.len = 0;
    v50.baseBuffer[0] = 0;
    v50.intvalue = 0;
    v50.allocedAndFlag = 20;
    v50.data = v50.baseBuffer;
    memset(&v50.whiteSpaceStart_p, 0, 12);
    v50.floatvalue = -3.4028235e38;
    while ( idLexer::ReadToken(this: &v52, token: &v50) )
    {
      if ( v50.type != 1 )
        idLexer::Error(this: &v52, str: "Expected job stage string.");
      v7 = 7;
      for ( i = 0; i < 7; ++i )
      {
        if ( idStr::Icmp(s1: v50.data, s2: jobStageStr[i]) == 0 )
        {
          v7 = i;
          break;
        }
      }
      if ( v7 == 7 )
        idLexer::Error(this: &v52, str: "Unknown job stage '%s'", v50.data);
      idLexer::ExpectTokenType(this: &v52, type: 5, subtype: 40, token: &v50);
      idLexer::ExpectTokenType(this: &v52, type: 1, subtype: 0, token: &v50);
      v51.allocedAndFlag = 20;
      v51.data = v51.baseBuffer;
      v51.len = 0;
      len = v50.len;
      v51.baseBuffer[0] = 0;
      if ( v50.len + 1 > 20 )
        idStr::ReAllocate(this: &v51, amount: v50.len + 1, keepold: true);
      data = v50.data;
      v11 = v51.data;
      do
      {
        v12 = *data;
        *v11++ = *data++;
      }
      while ( v12 != 0 );
      v51.len = len;
      idLexer::ExpectTokenType(this: &v52, type: 5, subtype: 40, token: &v50);
      v13 = nullptr;
      for ( j = 0; j < num; ++j )
      {
        argc = (int)&list[j];
        if ( idStr::Icmp(s1: *(const char **)(argc + 4), s2: v51.data) == 0 )
          v13 = &list[j];
      }
      if ( v13 == nullptr )
      {
        idList<idJobDef,5>::PreAllocateWithGranularity(this: &v48, newSize: num + 1);
        num = v48.num;
        size = v48.size;
        list = v48.list;
        if ( v48.num >= v48.size )
        {
          v13 = &v48.list[v48.size - 1];
        }
        else
        {
          v13 = &v48.list[v48.num];
          num = ++v48.num;
        }
        allocedAndFlag = v13->jobDeclName.allocedAndFlag;
        v16 = v51.len;
        v17 = v51.len + 1;
        v19 = allocedAndFlag >> 31 == 0;
        v18 = allocedAndFlag & 0x7FFFFFFF;
        if ( v19 )
        {
          if ( v17 > v18 )
            idStr::ReAllocate(this: &v13->jobDeclName, amount: v17, keepold: false);
        }
        else if ( v17 > v18
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: "amount <= GetAlloced()",
                    inlineBreak: true) )
        {
          __trap();
        }
        memcpy(Dst: v13->jobDeclName.data, Src: v51.data, Size: v16);
        v13->jobDeclName.data[v16] = 0;
        v13->jobDeclName.len = v16;
      }
      if ( v7 != 0 )
      {
        idLexer::ExpectTokenType(this: &v52, type: 1, subtype: 0, token: &v50);
        if ( (unsigned int)(v7 - 1) <= 5 )
        {
          switch ( v7 )
          {
            case 2:
              v20 = v50.len;
              p_jobByeVO = &v13->jobByeVO;
              idStr::EnsureAlloced(this: p_jobByeVO, amount: v50.len + 1, keepold: false, geometricGrowth: false);
              break;
            case 3:
              v20 = v50.len;
              p_jobByeVO = &v13->jobCompleteVO;
              idStr::EnsureAlloced(this: p_jobByeVO, amount: v50.len + 1, keepold: false, geometricGrowth: false);
              break;
            case 4:
              v20 = v50.len;
              p_jobByeVO = &v13->jobEndVO;
              idStr::EnsureAlloced(this: p_jobByeVO, amount: v50.len + 1, keepold: false, geometricGrowth: false);
              break;
            case 5:
              v20 = v50.len;
              p_jobByeVO = &v13->jobFailVO;
              idStr::EnsureAlloced(this: p_jobByeVO, amount: v50.len + 1, keepold: false, geometricGrowth: false);
              break;
            default:
              v20 = v50.len;
              if ( v7 == 1 )
                p_jobByeVO = &v13->jobOfferVO;
              else
                p_jobByeVO = &v13->jobInProgressVO;
              idStr::EnsureAlloced(this: p_jobByeVO, amount: v50.len + 1, keepold: false, geometricGrowth: false);
              break;
          }
          memcpy(Dst: p_jobByeVO->data, Src: v50.data, Size: v20);
          p_jobByeVO->data[v20] = 0;
          p_jobByeVO->len = v20;
        }
        idLexer::ExpectTokenType(this: &v52, type: 5, subtype: 40, token: &v50);
      }
      else
      {
        ParseText(src: &v52, id: &v13->jobSummaryId, text: &v13->jobSummary);
        ParseText(src: &v52, id: &v13->jobNameId, text: &v13->jobName);
        ParseText(src: &v52, id: &v13->jobRewardsId, text: &v13->jobRewards);
        ParseText(src: &v52, id: &v13->jobRequirementsId, text: &v13->jobRequirements);
      }
      idStr::FreeData(this: &v51);
    }
    idStr::FreeData(this: &v50);
    common->SetRefreshOnPrint(this: common, a2: true);
    idLib::Printf(fmt: "Parse in %d job defs.\n", num);
    idLib::Printf(fmt: "Updating job decls...\n");
    v22 = idDeclInfoTemplate<idDeclJob>::AllocDecl(this: &idDeclJob::resourceList);
    if ( num > 0 )
    {
      p_data = &list->jobDeclName.data;
      do
      {
        if ( *p_data != nullptr )
          v26 = idDeclInfo::FindWithInheritance(this: &idDeclJob::resourceList, name: *p_data, makeDefault: false);
        else
          v26 = nullptr;
        v27 = (idDeclTypeInfo *)v26;
        if ( v26 == nullptr )
        {
          v28 = *p_data;
          if ( v2 == 0 )
          {
            idLib::Printf(fmt: "skipping job '%s'...\n", v28);
            goto LABEL_68;
          }
          idLib::Printf(fmt: "Adding job '%s'...\n", v28);
          v27 = (idDeclTypeInfo *)declManager->CreateNewDecl(
                                    this: declManager,
                                    a2: &idDeclJob::resourceList,
                                    a3: *p_data,
                                    a4: "decls/typeinfo/jobs.tdef",
                                    a5: &byte_8200D768);
        }
        idLib::Printf(fmt: "Updating job '%s'...\n", v27->name.str);
        v29 = p_data[18];
        Key = idStrId::GetKey(this: (idStrId *)p_data + 16);
        idLangDict::SetString(this: &idLocalization::languageDict, key: Key, val: v29);
        v27[1].__vftable = (idDeclTypeInfo_vtbl *)p_data[16];
        v31 = p_data[9];
        v32 = idStrId::GetKey(this: (idStrId *)p_data + 7);
        idLangDict::SetString(this: &idLocalization::languageDict, key: v32, val: v31);
        v27[1].trackedMemory = (int)p_data[7];
        v33 = p_data[36];
        v34 = idStrId::GetKey(this: (idStrId *)p_data + 34);
        idLangDict::SetString(this: &idLocalization::languageDict, key: v34, val: v33);
        v27[1].name.str = p_data[34];
        v35 = p_data[27];
        v36 = idStrId::GetKey(this: (idStrId *)p_data + 25);
        idLangDict::SetString(this: &idLocalization::languageDict, key: v36, val: v35);
        v27[1].nextOnHashChain = (idResource *)p_data[25];
        idDeclTypeInfo::SetState(this: v27, empty: &v22->idDeclTypeInfo);
        idDecl::ReplaceSourceFileText(this: v27, useSourceControl: true);
LABEL_68:
        --num;
        p_data += 92;
      }
      while ( num != 0 );
    }
    if ( v22 != nullptr )
      ((void (__fastcall *)(idDeclJob *, int))v22->dtr_idResource)(a1: v22, a2: 1);
    LODWORD(v37) = &unk_821C0000;
    HIDWORD(v37) = &sys_lang;
    HIDWORD(v24) = sys_lang.valueString.data;
    v38 = va::va(
            this: &v54,
            fmt: "strings/%s.lang",
            a3: v24,
            a4: v23,
            a5: v37,
            a6: v42,
            a7: v43,
            a8: v44,
            a9: v45,
            a10: v46,
            a11: v47);
    idStr::idStr(this: &v53, text: v38);
    idLangDict::Save(this: &idLocalization::languageDict, fileName: v53.data);
    idStr::FreeData(this: &v53);
    if ( (v48.listStatic == 0 || v48.listStatic == 2) && list != nullptr )
    {
      if ( size > 0 )
      {
        v39 = list;
        for ( k = size; k != 0; --k )
          idJobDef::~idJobDef(this: v39++);
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
  }
  else
  {
    if ( args->argc <= 1 )
      v41 = &byte_8200D768;
    else
      v41 = args->argv[1];
    idLib::Warning(fmt: "Failed to load jobs file '%s'.", v41);
  }
  idLexer::~idLexer(this: &v52);
}


// ========================================================================
// $M516258
// EA  : 0x82E1BE60
// RVA : 0x00E1BE60
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void *_M516258()
{
  idLib::Warning(fmt: idException::error);
  return &_M516240_0;
}


// ========================================================================
// __unwind$515646
// EA  : 0x82E1BE90
// RVA : 0x00E1BE90
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_515646()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 4672 + 240));
}


// ========================================================================
// __unwind$515647
// EA  : 0x82E1BEB8
// RVA : 0x00E1BEB8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_515647()
{
  int v0; // r12

  idList<idJobDef,5>::Clear(this: (idList<idJobDef,5> *)(v0 - 4672 + 96));
}


// ========================================================================
// __unwind$515648
// EA  : 0x82E1BEE0
// RVA : 0x00E1BEE0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_515648()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4672 + 128));
}


// ========================================================================
// __unwind$515649
// EA  : 0x82E1BF08
// RVA : 0x00E1BF08
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_515649()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4672 + 208));
}


// ========================================================================
// __unwind$515650
// EA  : 0x82E1BF30
// RVA : 0x00E1BF30
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_515650()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4672 + 384));
}


// ========================================================================
// ?SetupJobTreeForAcceptance@idJobManager@@QAAXPBVidDeclJob@@@Z
// EA  : 0x82E1BF58
// RVA : 0x00E1BF58
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::SetupJobTreeForAcceptance(idJobManager *this, const idDeclJob *job)
{
  int i; // r30
  const idDeclJob::jobPreCondition_t *JobPrecondition; // r3
  unsigned int jobStatus; // r11
  const char *data; // r31
  const idDeclJob *v8; // r4

  if ( job != nullptr )
  {
    for ( i = 0; i < (int)idMapPatch::GetMaterial(hSSMDev: job); ++i )
    {
      JobPrecondition = idDeclJob::GetJobPrecondition(this: job, idx: i);
      if ( JobPrecondition->precondition == JOBPRECONDITION_JOB )
      {
        jobStatus = JobPrecondition->jobStatus;
        if ( jobStatus != 0 )
        {
          if ( jobStatus == 1 )
          {
            idJobManager::SetJobReadyToTurnIn(
              this,
              jobName: JobPrecondition->jobDecl.data,
              completeTree: true,
              giveJobIfNeeded: true,
              hideIfGiven: false,
              force: false);
          }
          else if ( jobStatus < 3 )
          {
            idJobManager::CompleteJob(
              this,
              jobName: JobPrecondition->jobDecl.data,
              completeTree: true,
              giveJob: true,
              force: false);
          }
        }
        else
        {
          data = JobPrecondition->jobDecl.data;
          if ( data != nullptr
            && (v8 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                                          this: &idDeclJob::resourceList,
                                          name: data,
                                          makeDefault: false)) != nullptr )
          {
            idJobManager::AcceptJob(this, jobDecl: v8, completeTree: true, force: false);
          }
          else
          {
            idLib::Warning(fmt: "Unknown job '%s'", data);
          }
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "Job decl is NULL in SetupJobTreeForAcceptance! ");
  }
}


// ========================================================================
// ?AcceptJob@idJobManager@@QAA_NPBVidDeclJob@@_N1@Z
// EA  : 0x82E1C088
// RVA : 0x00E1C088
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::AcceptJob(idJobManager *this, idStrId *jobDecl, bool completeTree, bool force)
{
  int valueInteger; // r11
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  BOOL inDebug; // r26
  idStrId *v13; // r3
  const char *v14; // r3
  BOOL v15; // r24
  BOOL v16; // r25
  idJob *JobByDecl; // r26
  int v18; // r10
  int v19; // r9
  int v20; // r8
  int v21; // r7
  int v22; // r6
  int v23; // r5
  char v24; // r10
  idDeclJob *DebugInfo; // r3
  const idDeclJobTimerEvent *index; // r4
  idPlayer *owner; // r11
  const idDeclJob *v28; // r3
  const idDeclJob *v29; // r28
  int v30; // r27
  int v31; // r28
  int v32; // r27
  int v33; // r28
  idStrId *v34; // r4
  BOOL v35; // r30
  idStrId *v36; // r3
  const char *v37; // r3
  idStrId *v38; // r4
  BOOL v39; // r30
  idStrId *v40; // r3
  const char *v41; // r3
  int v42; // [sp+8h] [-D8h]
  int v43; // [sp+Ch] [-D4h]
  int v44; // [sp+10h] [-D0h]
  int v45; // [sp+14h] [-CCh]
  int v46; // [sp+18h] [-C8h]
  idJob *v47; // [sp+1Ch] [-C4h]
  int v48[4]; // [sp+50h] [-90h] BYREF
  idDeclCloth::ropeInfo v49[2]; // [sp+60h] [-80h] BYREF

  if ( jobDecl == nullptr )
  {
    idLib::Warning(fmt: "NULL jobDecl in AcceptJob");
    return 0;
  }
  if ( jobDecl[25].index == 11 )
  {
    valueInteger = jobDebug_PrintChanges.valueInteger;
    if ( jobDebug_PrintChanges.valueInteger != 0 )
    {
      JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v48, result: jobDecl);
      LocalizedString = idStrId::GetLocalizedString(this: JobName);
      idLib::Printf(fmt: "AcceptJob %s, just gui job.\n", LocalizedString);
      valueInteger = jobDebug_PrintChanges.valueInteger;
    }
    if ( this->inDebug )
    {
      if ( valueInteger != 0 )
        idLib::Printf(fmt: "   in debug, returning false\n");
      return 0;
    }
    if ( valueInteger != 0 )
      idLib::Printf(fmt: "   transitioning\n");
    idJobManager::TransitionToNextPositionForJustGUIJob(this, (const idDeclJob *)jobDecl);
    idJobManager::GiveRewards(this, rewards: (const idList<idDeclJob::jobReward_t,5> *)&jobDecl[34]);
    return 1;
  }
  else
  {
    if ( jobDebug_PrintChanges.valueInteger != 0 )
    {
      inDebug = this->inDebug;
      v13 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v48, result: jobDecl);
      v14 = idStrId::GetLocalizedString(this: v13);
      idLib::Printf(fmt: "AcceptJob %s, complete: %d, debug: %d, force: %d\n", v14, completeTree, inDebug, force);
    }
    v15 = completeTree;
    if ( completeTree )
      idJobManager::SetupJobTreeForAcceptance(this, job: (const idDeclJob *)jobDecl);
    v16 = force;
    if ( force )
      idJobManager::UnCompleteJob(this, (const idDeclJob *)jobDecl);
    JobByDecl = idJobManager::FindJobByDecl(this, (const idDeclJob *)jobDecl);
    if ( JobByDecl == nullptr )
    {
      JobByDecl = idJob::Create((const idDeclJob *)jobDecl);
      idJobManager::AddJob(
        this,
        job: JobByDecl,
        a3: v23,
        a4: v22,
        a5: v21,
        a6: v20,
        a7: v19,
        a8: v18,
        a9: v42,
        a10: v43,
        a11: v44,
        a12: v45,
        a13: v46,
        a14: v47);
    }
    v24 = 0;
    if ( force || (v48[0] = JobByDecl->status, v48[0] <= 1u) )
      v24 = 1;
    if ( v24 == 0 )
    {
      if ( jobDebug_PrintChanges.valueInteger != 0 )
      {
        v38 = jobDecl;
        v39 = this->inDebug;
        v40 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v48, result: v38);
        v41 = idStrId::GetLocalizedString(this: v40);
        idLib::Printf(fmt: "FAILED:\tAcceptJob %s, complete: %d, debug: %d, force: %d\n", v41, completeTree, v39, force);
      }
      return 0;
    }
    if ( (unsigned __int8)idDeclJob::UseDynamicJobHud(this: JobByDecl->decl) != 0 )
      idJobManager::RemoveDynamicJobs(this);
    idJob::SetJobStatus(
      this: JobByDecl,
      newStatus: JOBSTATUS_ACCEPTED,
      manager: this,
      fireOffJobTargets: false,
      debug: this->inDebug);
    idJobManager::SetActiveJob(this, decl: (const idDeclJob *)jobDecl, checkImportance: true);
    idJobManager::GiveRewards(this, rewards: (const idList<idDeclJob::jobReward_t,5> *)&jobDecl[34]);
    idJobManager::RemovePreconditions(this, preconditions: (const idList<idDeclJob::jobPreCondition_t,5> *)&jobDecl[30]);
    if ( this->inDebug )
    {
      if ( !this->hackIgnoreDebugRewards )
      {
        DebugInfo = idDeclJob::GetDebugInfo(this: (idDeclJob *)v49, result: (idDeclJob::jobDebugMasterInfo_t *)jobDecl);
        idJobManager::GiveRewards(this, rewards: (const idList<idDeclJob::jobReward_t,5> *)DebugInfo);
        idDeclCloth::ropeInfo::~ropeInfo(this: v49);
      }
      idJobManager::GivePreconditions(this, preconditions: (const idList<idDeclJob::jobPreCondition_t,5> *)&jobDecl[30]);
    }
    idJobManager::FireOffJobTargets(this, job: JobByDecl, debug: this->inDebug);
    index = (const idDeclJobTimerEvent *)jobDecl[29].index;
    if ( index != nullptr )
    {
      owner = this->owner;
      if ( owner != nullptr )
        idJobTimerManager::StartIteration(
          this: &owner->jobTimerManager,
          inEventDecl: index,
          inJobDecl: (const idDeclJob *)jobDecl);
    }
    v48[0] = -1;
    v28 = idJobManager::CanJobAcceptanceCompleteAJob(this, job: (const idDeclJob *)jobDecl, requirementNum: v48);
    v29 = v28;
    if ( v28 != nullptr && (unsigned __int8)idJobManager::IsJobReadyToTurnIn(this, jobDecl: v28) != 0 )
      idJobManager::SetJobReadyToTurnIn(
        this,
        jobDecl: v29,
        completeTree: false,
        giveJobIfNeeded: false,
        hideIfGiven: false,
        force: false);
    if ( g_debugLayers.valueInteger != 0 )
      idLib::Printf(fmt: "idJobManager::AcceptJob: adding layers for job '%s'\n", (const char *)jobDecl[2].index);
    v30 = 0;
    if ( jobDecl[96].index > 0 )
    {
      v31 = 0;
      do
      {
        idJobManager::AddJobNote(
          this,
          jobNote: *(const idDeclJobNote **)(v31 + jobDecl[95].index),
          force: false,
          updateHUD: true,
          checkForActiveJob: false);
        ++v30;
        v31 += 4;
      }
      while ( v30 < jobDecl[96].index );
    }
    v32 = 0;
    if ( jobDecl[100].index > 0 )
    {
      v33 = 0;
      do
      {
        idJobManager::RemoveJobNote(
          this,
          jobNoteDecl: *(const idDeclJobNote **)(v33 + jobDecl[99].index),
          checkForActiveJob: false);
        ++v32;
        v33 += 4;
      }
      while ( v32 < jobDecl[100].index );
    }
    idJobManager::TransitionToNextPosition(this, job: JobByDecl);
    if ( jobDebug_PrintChanges.valueInteger != 0 )
    {
      v34 = jobDecl;
      v35 = this->inDebug;
      v36 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v48, result: v34);
      v37 = idStrId::GetLocalizedString(this: v36);
      idLib::Printf(fmt: "ACCEPTED:\tAcceptJob %s, complete: %d, debug: %d, force: %d\n", v37, v15, v35, v16);
    }
    return 1;
  }
}


// ========================================================================
// __unwind$516350
// EA  : 0x82E1C4A0
// RVA : 0x00E1C4A0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_516350()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(v0 - 224 + 96));
}


// ========================================================================
// ?OfferDynamicJob@idJobManager@@QAA_NPBVidDeclJob@@@Z
// EA  : 0x82E1C4C8
// RVA : 0x00E1C4C8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::OfferDynamicJob(idJobManager *this, idStrId *jobDecl)
{
  int num; // r8
  int v5; // r10
  idJob **list; // r9
  int v7; // r11
  idJob *v8; // r11

  num = this->jobs.num;
  v5 = 0;
  if ( num <= 0 )
    goto LABEL_8;
  list = this->jobs.list;
  v7 = 0;
  while ( (idStrId *)list[v7]->decl != jobDecl )
  {
    ++v5;
    ++v7;
    if ( v5 >= num )
      goto LABEL_8;
  }
  v8 = list[v5];
  if ( v8 == nullptr || v8->status == JOBSTATUS_NONE )
  {
LABEL_8:
    if ( (unsigned __int8)idJobManager::IsJobAvailable(this, (const idDeclJob *)jobDecl) != 0 )
      return idJobManager::AcceptJob(this, jobDecl, completeTree: false, force: false);
  }
  return 0;
}


// ========================================================================
// ?AcceptJob@idJobManager@@QAA_NPBD_N1@Z
// EA  : 0x82E1C588
// RVA : 0x00E1C588
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::AcceptJob(idJobManager *this, const char *name, bool completeTree, bool force)
{
  idStrId *v8; // r4

  if ( name != nullptr )
  {
    v8 = (idStrId *)idDeclInfo::FindWithInheritance(this: &idDeclJob::resourceList, name, makeDefault: false);
    if ( v8 != nullptr )
      return idJobManager::AcceptJob(this, jobDecl: v8, completeTree, force);
  }
  idLib::Warning(fmt: "Unknown job '%s'", name);
  return 0;
}


// ========================================================================
// ?CompleteJobsRequiredForJobCompletion@idJobManager@@QAAXPBVidDeclJob@@@Z
// EA  : 0x82E1C600
// RVA : 0x00E1C600
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::CompleteJobsRequiredForJobCompletion(idJobManager *this, const idDeclJob *job)
{
  int i; // r30
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3
  const char *data; // r31
  idStrId *v7; // r4

  if ( job != nullptr )
  {
    for ( i = 0; i < idDeclJob::GetNumCompletionRequirements(this: job); ++i )
    {
      CompletionRequirement = idDeclJob::GetCompletionRequirement(this: job, idx: i);
      if ( CompletionRequirement->completion == JOBCOMPLETE_JOB )
      {
        data = CompletionRequirement->jobDecl.data;
        if ( data != nullptr
          && (v7 = (idStrId *)idDeclInfo::FindWithInheritance(
                                this: &idDeclJob::resourceList,
                                name: data,
                                makeDefault: false)) != nullptr )
        {
          idJobManager::CompleteJob(this, jobDecl: v7, completeTree: true, giveJob: true, force: false);
        }
        else
        {
          idLib::Warning(fmt: "Unknown job '%s'", data);
        }
      }
      else if ( CompletionRequirement->completion == JOBCOMPLETE_JOB_ACCEPTED )
      {
        idJobManager::AcceptJob(this, name: CompletionRequirement->jobDecl.data, completeTree: true, force: false);
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "Job decl is NULL in CompleteJobsRequiredForJobCompletion! ");
  }
}


// ========================================================================
// ?SetJobReadyToTurnIn@idJobManager@@QAA_NPBVidDeclJob@@_N111@Z
// EA  : 0x82E1C700
// RVA : 0x00E1C700
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::SetJobReadyToTurnIn(
        idJobManager *this,
        idStrId *jobDecl,
        bool completeTree,
        bool giveJobIfNeeded,
        bool hideIfGiven,
        bool force)
{
  BOOL inDebug; // r26
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  idJob *JobByDecl; // r3
  BOOL v16; // r23
  idJob *v17; // r25
  bool v18; // r26
  BOOL v19; // r24
  missionStatus_t status; // r11
  const idDeclJobTimerEvent *v21; // r4
  missionStatus_t v22; // r4
  idDeclJob *DebugInfo; // r3
  int v24; // r27
  int v25; // r28
  int v26; // r27
  int v27; // r28
  idPlayer *owner; // r11
  idStrId *v29; // r4
  BOOL v30; // r30
  idStrId *v31; // r3
  const char *v32; // r3
  idStrId *v34; // r4
  BOOL v35; // r30
  idStrId *v36; // r3
  const char *v37; // r3
  idPlayer *v38[4]; // [sp+50h] [-B0h] BYREF
  idDeclCloth::ropeInfo v39[3]; // [sp+60h] [-A0h] BYREF

  if ( jobDecl == nullptr )
  {
    idLib::Warning(fmt: "NULL jobDecl in SetJobReadyToTurnIn");
    return 0;
  }
  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    inDebug = this->inDebug;
    JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v38, result: jobDecl);
    LocalizedString = idStrId::GetLocalizedString(this: JobName);
    idLib::Printf(
      fmt: "SetJobReadyToTurnIn %s, complete: %d, give: %d, hide: %d, debug: %d, force: %d\n",
      LocalizedString,
      completeTree,
      giveJobIfNeeded,
      hideIfGiven,
      inDebug,
      force);
  }
  JobByDecl = idJobManager::FindJobByDecl(this, (const idDeclJob *)jobDecl);
  v16 = force;
  v17 = JobByDecl;
  v18 = false;
  if ( force || giveJobIfNeeded && (JobByDecl == nullptr || JobByDecl->status < JOBSTATUS_ACCEPTED) )
    idJobManager::AcceptJob(this, jobDecl, completeTree, force);
  if ( v17 != nullptr
    || (v18 = hideIfGiven, (v17 = idJobManager::FindJobByDecl(this, (const idDeclJob *)jobDecl)) != nullptr) )
  {
    v19 = completeTree;
    if ( completeTree )
      idJobManager::CompleteJobsRequiredForJobCompletion(this, job: (const idDeclJob *)jobDecl);
    status = v17->status;
    if ( (_cntlzw(status - 2) & 0x20) != 0 || (v38[0] = (idPlayer *)v17->status, status == JOBSTATUS_FAILED) )
    {
      if ( this->owner != nullptr )
      {
        v38[0] = (idPlayer *)jobDecl[29].index;
        v21 = (const idDeclJobTimerEvent *)v38[0];
        if ( v38[0] != nullptr && LODWORD(v38[0]->renderModelInfo.dimShadowClipZ) != 0 )
        {
          v38[0] = this->owner;
          idJobTimerManager::CompleteIteration(
            this: &v38[0]->jobTimerManager,
            inEventDecl: v21,
            inJobDecl: (const idDeclJob *)jobDecl,
            player: v38[0]);
        }
      }
      if ( v18 )
      {
        v22 = JOBSTATUS_READYTOTURNIN_UNKNOWN;
      }
      else
      {
        if ( v17->status != JOBSTATUS_READYTOTURNIN )
          idJobManager::SetActiveJob(this, decl: (const idDeclJob *)jobDecl, checkImportance: true);
        v22 = JOBSTATUS_READYTOTURNIN;
      }
      idJob::SetJobStatus(this: v17, newStatus: v22, manager: this, fireOffJobTargets: false, debug: this->inDebug);
      if ( this->inDebug )
      {
        if ( !this->hackIgnoreDebugRewards )
        {
          DebugInfo = idDeclJob::GetDebugInfo(
                        this: (idDeclJob *)v39,
                        result: (idDeclJob::jobDebugMasterInfo_t *)jobDecl);
          idJobManager::GiveRewards(
            this,
            rewards: (const idList<idDeclJob::jobReward_t,5> *)&DebugInfo->resourceListPtr);
          idDeclCloth::ropeInfo::~ropeInfo(this: v39);
        }
        idJobManager::GiveCompletionConditions(
          this,
          completion: (const idList<idDeclJob::jobComplete_t,5> *)&jobDecl[42],
          job: v17);
      }
      idJobManager::GiveRewards(this, rewards: (const idList<idDeclJob::jobReward_t,5> *)&jobDecl[38]);
      idJobManager::FireOffJobTargets(this, job: v17, debug: this->inDebug);
      if ( g_debugLayers.valueInteger != 0 )
        idLib::Printf(
          fmt: "idJobManager::SetJobReadyToTurnIn: adding layers for job '%s'\n",
          (const char *)jobDecl[2].index);
      v24 = 0;
      if ( jobDecl[104].index > 0 )
      {
        v25 = 0;
        do
        {
          idJobManager::AddJobNote(
            this,
            jobNote: *(const idDeclJobNote **)(jobDecl[103].index + v25),
            force: false,
            updateHUD: true,
            checkForActiveJob: false);
          ++v24;
          v25 += 4;
        }
        while ( v24 < jobDecl[104].index );
      }
      v26 = 0;
      if ( jobDecl[108].index > 0 )
      {
        v27 = 0;
        do
        {
          idJobManager::RemoveJobNote(
            this,
            jobNoteDecl: *(const idDeclJobNote **)(v27 + jobDecl[107].index),
            checkForActiveJob: false);
          ++v26;
          v27 += 4;
        }
        while ( v26 < jobDecl[108].index );
      }
      owner = this->owner;
      if ( owner != nullptr )
        idAchievementManager::JobCompletesAchievement(this: &owner->achievementManager);
      idJobManager::TransitionToNextPosition(this, job: v17);
      if ( jobDebug_PrintChanges.valueInteger != 0 )
      {
        v29 = jobDecl;
        v30 = this->inDebug;
        v31 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v38, result: v29);
        v32 = idStrId::GetLocalizedString(this: v31);
        idLib::Printf(
          fmt: "SETJOBREADYTOTURNIN:\tSetJobReadyToTurnIn %s, complete: %d, give: %d, hide: %d, debug: %d, force: %d\n",
          v32,
          v19,
          giveJobIfNeeded,
          hideIfGiven,
          v30,
          v16);
      }
      return 1;
    }
  }
  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    v34 = jobDecl;
    v35 = this->inDebug;
    v36 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v38, result: v34);
    v37 = idStrId::GetLocalizedString(this: v36);
    idLib::Printf(
      fmt: "FAILED:\tSetJobReadyToTurnIn %s, complete: %d, give: %d, hide: %d, debug: %d, force: %d\n",
      v37,
      completeTree,
      giveJobIfNeeded,
      hideIfGiven,
      v35,
      force);
  }
  return 0;
}


// ========================================================================
// __unwind$516766
// EA  : 0x82E1CA94
// RVA : 0x00E1CA94
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_516766()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(v0 - 256 + 96));
}


// ========================================================================
// ?SetGameStateIntValue@idJobManager@@QAAXPBVidDeclGameStateInt@@H@Z
// EA  : 0x82E1CAC8
// RVA : 0x00E1CAC8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::SetGameStateIntValue(
        idJobManager *this,
        const idDeclGameStateInt *gameState,
        int stateValue)
{
  int v6; // r10
  idGameStateInt **list; // r8
  int v8; // r11
  idGameStateInt *v9; // r30
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  idGameStateInt *v16; // r3
  idGameStateInt *v17; // r4
  int gameStateValue; // r5
  const idDeclJob *v19; // r3
  idStrId *v20; // r30
  int v21; // r28
  idJob *JobByDecl; // r3
  int v23; // r5
  int v24; // [sp+8h] [-88h]
  int v25; // [sp+Ch] [-84h]
  int v26; // [sp+10h] [-80h]
  int v27; // [sp+14h] [-7Ch]
  int v28; // [sp+18h] [-78h]
  idGameStateInt *v29; // [sp+1Ch] [-74h]
  int num; // [sp+50h] [-40h] BYREF

  v6 = 0;
  num = this->gameStateInts.num;
  if ( num <= 0 )
    goto LABEL_7;
  list = this->gameStateInts.list;
  v8 = 0;
  while ( list[v8]->decl != gameState )
  {
    ++v6;
    ++v8;
    if ( v6 >= num )
      goto LABEL_7;
  }
  v9 = list[v6];
  if ( v9 == nullptr )
  {
LABEL_7:
    if ( gameState == nullptr )
    {
      idLib::Warning(fmt: "idJobManager::SetGameStateIntValue, NULL gameState");
      return;
    }
    v16 = (idGameStateInt *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0xCu,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    num = (int)v16;
    if ( v16 != nullptr )
      v17 = idGameStateInt::idGameStateInt(this: v16, gameStateDecl: gameState);
    else
      v17 = nullptr;
    v9 = v17;
    idJobManager::AddGameStateInt(
      this,
      gameStateInt: v17,
      a3: v15,
      a4: v14,
      a5: v13,
      a6: v12,
      a7: v11,
      a8: v10,
      a9: v24,
      a10: v25,
      a11: v26,
      a12: v27,
      a13: v28,
      a14: v29);
  }
  gameStateValue = v9->gameStateValue;
  v9->gameStateValue = stateValue;
  num = -1;
  v19 = idJobManager::CanGameStateIntCompleteAJob(
          this,
          decl: gameState,
          previousValue: gameStateValue,
          currentValue: stateValue,
          requirementNum: &num);
  v20 = (idStrId *)v19;
  if ( v19 != nullptr )
  {
    if ( (unsigned __int8)idJobManager::IsJobReadyToTurnIn(this, jobDecl: v19) != 0 )
    {
      idJobManager::SetJobReadyToTurnIn(
        this,
        jobDecl: v20,
        completeTree: false,
        giveJobIfNeeded: false,
        hideIfGiven: false,
        force: false);
    }
    else
    {
      v21 = num;
      if ( idDeclJob::GetCompletionRequirement(this: (idDeclJob *)v20, idx: num)->showTrackerMessage
        && idDeclJob::GetCompletionRequirement(this: (idDeclJob *)v20, idx: v21)->triggerMessage.index >= 0 )
      {
        JobByDecl = idJobManager::FindJobByDecl(this, jobDecl: (const idDeclJob *)v20);
        idJobManager::UpdatePlayerHud(
          this,
          job: JobByDecl,
          requirementNum: v23,
          playSound: false,
          treatAsSameStatusUpdate: false);
      }
    }
  }
}


// ========================================================================
// __unwind$516934
// EA  : 0x82E1CC68
// RVA : 0x00E1CC68
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall _unwind_516934(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?GetLayerInfoForMainMenuDebugJob@idJobManager@@QAA_NABVidStr@@HAAV?$idList@VidStr@@$04@@1@Z
// EA  : 0x82E1CC90
// RVA : 0x00E1CC90
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::GetLayerInfoForMainMenuDebugJob(
        idJobManager *this,
        const idStr *jobDebugName,
        int state,
        idList<idStr,5> *layerListActive,
        idList<idStr,5> *layerListDeactive)
{
  idResource *v10; // r3
  char *data; // r4
  const char *v12; // r3

  if ( layerListActive->listStatic == 0 || layerListActive->listStatic == 2 )
  {
    if ( layerListActive->list != nullptr )
      idListArrayDelete<idStr>(ptr: layerListActive->list, num: layerListActive->size);
    layerListActive->list = nullptr;
    layerListActive->size = 0;
  }
  layerListActive->num = 0;
  if ( layerListDeactive->listStatic == 0 || layerListDeactive->listStatic == 2 )
  {
    if ( layerListDeactive->list != nullptr )
      idListArrayDelete<idStr>(ptr: layerListDeactive->list, num: layerListDeactive->size);
    layerListDeactive->list = nullptr;
    layerListDeactive->size = 0;
  }
  layerListDeactive->num = 0;
  v10 = idResourceList::Load(
          this: &idDeclJob::resourceList,
          name: jobDebugName->data,
          makeDefault: false,
          skipStaleCheck: false);
  if ( v10 != nullptr )
  {
    this->inDebug = true;
    if ( state != 0 )
    {
      if ( state == 1 )
      {
        if ( *((int *)&v10[18] + 8) <= 0 )
        {
          idJobManager::SetJobReadyToTurnIn(
            this,
            jobDecl: (idStrId *)v10,
            completeTree: true,
            giveJobIfNeeded: true,
            hideIfGiven: false,
            force: false);
          return 1;
        }
      }
      else
      {
        if ( state != 2 )
        {
          idLib::Error(fmt: "GetLayerInfoForMainMenuDebugJob unknown state for %s %d", v10->name.str, state);
          JUMPOUT(0x82E1CE2C);
        }
        if ( v10[21].staleCount <= 0 )
          idJobManager::CompleteJob(this, jobDecl: (idStrId *)v10, completeTree: true, giveJob: true, force: false);
      }
    }
    else if ( (int)v10[16].__vftable <= 0 )
    {
      idJobManager::AcceptJob(this, jobDecl: (idStrId *)v10, completeTree: true, force: false);
      return 1;
    }
    return 1;
  }
  else
  {
    data = jobDebugName->data;
    v12 = "si_jobDebugName was set, but could not match to job:  %s";
    if ( si_jobDebugName_Error.valueInteger != 0 )
      idLib::Error(fmt: "si_jobDebugName was set, but could not match to job:  %s", data);
    idLib::Warning(fmt: v12, data);
    return 0;
  }
}


// ========================================================================
// ?Init@idJobManager@@QAAXPAVidPlayer@@_N@Z
// EA  : 0x82E1CE38
// RVA : 0x00E1CE38
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::Init(idJobManager *this, idPlayer *player, bool firstLoad)
{
  int v6; // r30
  int num; // r29
  const char *str; // r4
  idStrId *v9; // r4
  int v10; // r29
  int v11; // r30
  const char *v12; // r4
  const idDeclSpecialEvent *v13; // r4
  int v14; // r29
  int v15; // r30
  const char *v16; // r4
  const idDeclSpecialEvent_Area *v17; // r4
  int v18; // r29
  int v19; // r30
  const char *v20; // r4
  const idDeclGameStateInt *v21; // r4
  int v22; // r29
  int v23; // r30
  const char *v24; // r4
  const idDeclJobNote *v25; // r4
  const idDeclInventory *v26; // r29
  idPresentable *presentable; // r30
  idInventoryCollection *v28; // r3
  idWorldspawn::mapType_t mapType; // r11
  idInventoryCollection *v30; // r3
  int v31; // r29
  int v32; // r30
  const idGameSpawnInfo *v33; // r3
  idStrStatic<1024> *p_debugJobName; // r30
  int len; // r29
  char *v36; // r10
  char *v37; // r9
  char v38; // r11
  int debugJobState; // r29
  char *data; // r4
  idDecl *v41; // r3
  idDeclJob *v42; // r30
  const char *v43; // r3
  const idDeclSpecialEvent_Area *areaDecl; // [sp+50h] [-B0h]
  idList<idVehicleKey *,5> v45; // [sp+60h] [-A0h] BYREF
  idStr v46[4]; // [sp+70h] [-90h] BYREF

  this->owner = player;
  this->useAlternateHands = false;
  if ( (com_production.valueInteger != 0 || (gameLocal->GetGameFlags(this: gameLocal) & 0x80) != 0) && player != nullptr )
  {
    this->inDebug = true;
    if ( si_loadAllJobsOnBuild.valueInteger != 0 )
    {
      this->inInitState = true;
      if ( idDeclJob::resourceList.declSources.num > 0 )
      {
        v6 = 0;
        num = idDeclJob::resourceList.declSources.num;
        do
        {
          str = idDeclJob::resourceList.declSources.list[v6]->name.str;
          if ( str != nullptr )
            v9 = (idStrId *)idDeclInfo::FindWithInheritance(
                              this: &idDeclJob::resourceList,
                              name: str,
                              makeDefault: false);
          else
            v9 = nullptr;
          idJobManager::CompleteJob(this, jobDecl: v9, completeTree: true, giveJob: true, force: false);
          --num;
          ++v6;
        }
        while ( num != 0 );
      }
      v10 = idDeclSpecialEvent::resourceList.declSources.num;
      if ( idDeclSpecialEvent::resourceList.declSources.num > 0 )
      {
        v11 = 0;
        do
        {
          v12 = idDeclSpecialEvent::resourceList.declSources.list[v11]->name.str;
          if ( v12 != nullptr )
            v13 = (const idDeclSpecialEvent *)idDeclInfo::FindWithInheritance(
                                                this: &idDeclSpecialEvent::resourceList,
                                                name: v12,
                                                makeDefault: false);
          else
            v13 = nullptr;
          idJobManager::GiveSpecialEvent(this, specialEventDecl: v13, fromEntity: nullptr);
          --v10;
          ++v11;
        }
        while ( v10 != 0 );
      }
      v14 = idDeclSpecialEvent_Area::resourceList.declSources.num;
      if ( idDeclSpecialEvent_Area::resourceList.declSources.num > 0 )
      {
        v15 = 0;
        do
        {
          v16 = idDeclSpecialEvent_Area::resourceList.declSources.list[v15]->name.str;
          if ( v16 != nullptr )
            v17 = (const idDeclSpecialEvent_Area *)idDeclInfo::FindWithInheritance(
                                                     this: &idDeclSpecialEvent_Area::resourceList,
                                                     name: v16,
                                                     makeDefault: false);
          else
            v17 = nullptr;
          idJobManager::GiveSpecialEventArea(this, specialEventArea: v17);
          --v14;
          ++v15;
        }
        while ( v14 != 0 );
      }
      v18 = idDeclGameStateInt::resourceList.declSources.num;
      if ( idDeclGameStateInt::resourceList.declSources.num > 0 )
      {
        v19 = 0;
        do
        {
          v20 = idDeclGameStateInt::resourceList.declSources.list[v19]->name.str;
          if ( v20 != nullptr )
            v21 = (const idDeclGameStateInt *)idDeclInfo::FindWithInheritance(
                                                this: &idDeclGameStateInt::resourceList,
                                                name: v20,
                                                makeDefault: false);
          else
            v21 = nullptr;
          idJobManager::SetGameStateIntValue(this, gameState: v21, stateValue: 1);
          --v18;
          ++v19;
        }
        while ( v18 != 0 );
      }
      v22 = idDeclJobNote::resourceList.declSources.num;
      if ( idDeclJobNote::resourceList.declSources.num > 0 )
      {
        v23 = 0;
        do
        {
          v24 = idDeclJobNote::resourceList.declSources.list[v23]->name.str;
          if ( v24 != nullptr )
            v25 = (const idDeclJobNote *)idDeclInfo::FindWithInheritance(
                                           this: &idDeclJobNote::resourceList,
                                           name: v24,
                                           makeDefault: false);
          else
            v25 = nullptr;
          idJobManager::AddJobNote(this, jobNote: v25, force: false, updateHUD: true, checkForActiveJob: false);
          --v22;
          ++v23;
        }
        while ( v22 != 0 );
      }
    }
    if ( si_giveSPInventoryOnBuild.valueInteger != 0 )
    {
      v26 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                       this: &idDeclInventory::resourceList,
                                       name: "inventory/spdatacollection/spdatacollection",
                                       makeDefault: true);
      if ( v26 == nullptr )
        idLib::Error(fmt: "FAILED TO GIVE SP INVENTORY");
      presentable = player->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: player);
        presentable = player->presentable;
      }
      v28 = player->GetInventory_2(this: player);
      idInventoryCollection::GiveItem(
        this: v28,
        owner: presentable,
        decl: v26,
        count: 1,
        forceCount: false,
        canIntro: false);
      mapType = gameLocal->world->mapType;
      if ( mapType == MAPTYPE_TOWN || mapType == MAPTYPE_OUTDOOR || mapType == MAPTYPE_RACETRACK )
      {
        *(_WORD *)&v45.memTag = 1280;
        memset(&v45, 0, 14);
        v30 = player->GetInventory_2(this: player);
        idInventoryCollection::GetVehicleKeys(this: v30, vehicleList: &v45);
        v31 = 0;
        if ( v45.num > 0 )
        {
          v32 = 0;
          do
          {
            idGameLocal::SpawnPlayerVehicle(this: gameLocal, key: v45.list[v32]);
            ++v31;
            ++v32;
          }
          while ( v31 < v45.num );
        }
        if ( v45.listStatic == 0 || v45.listStatic == 2 )
        {
          if ( v45.list != nullptr )
            idMem::Free(this: &mem, ptr: v45.list, align: ALIGN_16);
          v45.list = nullptr;
          v45.size = 0;
        }
        v45.num = 0;
      }
    }
    this->inDebug = false;
    if ( si_loadAllJobsOnBuild.valueInteger != 0 )
    {
      this->inInitState = false;
      return;
    }
  }
  v33 = gameLocal->GetGameSpawnInfo(this: gameLocal);
  v46[0].len = 0;
  v46[0].baseBuffer[0] = 0;
  p_debugJobName = &v33->debugJobName;
  v46[0].data = v46[0].baseBuffer;
  v46[0].allocedAndFlag = 20;
  len = v33->debugJobName.len;
  if ( len + 1 > 20 )
    idStr::ReAllocate(this: v46, amount: len + 1, keepold: true);
  v36 = p_debugJobName->data - 1;
  v37 = v46[0].data - 1;
  do
  {
    v38 = *++v36;
    *++v37 = *v36;
  }
  while ( v38 != 0 );
  v46[0].len = len;
  debugJobState = gameLocal->GetGameSpawnInfo(this: gameLocal)->debugJobState;
  if ( v46[0].len == 0 )
    goto _LN291;
  if ( debugJobState != 3 )
  {
    data = v46[0].data;
    if ( v46[0].data == nullptr )
    {
LABEL_63:
      v43 = "si_jobDebugName was set, but could not match to job:  %s";
      if ( si_jobDebugName_Error.valueInteger != 0 )
        idLib::Error(fmt: "si_jobDebugName was set, but could not match to job:  %s", data);
      idLib::Warning(fmt: v43);
      goto LABEL_84;
    }
    v41 = (idDecl *)idDeclInfo::FindWithInheritance(
                      this: &idDeclJob::resourceList,
                      name: v46[0].data,
                      makeDefault: false);
    v42 = (idDeclJob *)v41;
    if ( v41 == nullptr )
    {
      data = v46[0].data;
      goto LABEL_63;
    }
    this->inDebug = true;
    this->inInitState = true;
    switch ( debugJobState )
    {
      case 0:
        idJobManager::AcceptJob(this, jobDecl: (idStrId *)v41, completeTree: true, force: false);
        goto LABEL_72;
      case 1:
        idJobManager::SetJobReadyToTurnIn(
          this,
          jobDecl: (idStrId *)v41,
          completeTree: true,
          giveJobIfNeeded: true,
          hideIfGiven: false,
          force: false);
        goto LABEL_72;
      case 2:
        idJobManager::CompleteJob(this, jobDecl: (idStrId *)v41, completeTree: true, giveJob: true, force: false);
LABEL_72:
        if ( !idDeclJob::IsJobHidden(this: v42)
          && (unsigned __int8)idDeclJob::UseDynamicJobHud(this: v42) == 0
          && debugJobState != 2 )
        {
          idJobManager::SetActiveJob(this, decl: v42, checkImportance: false);
        }
        if ( gameLocal->world != nullptr )
          idJobManager::CheckActiveJobVersusMap(this);
        this->inDebug = false;
        this->inInitState = false;
        idJobManager::RunJobInitializer(this);
        if ( gameLocal->world != nullptr )
          idJobManager::UpdateRelevantJobNotesForMap(this);
        goto LABEL_84;
      default:
        break;
    }
    idLib::Error(fmt: "idJobManager::Init unknown status for %s %d", v41->name.str, debugJobState);
_LN291:
    if ( firstLoad && g_debugLayers.valueInteger != 0 )
      idLib::Printf(fmt: "idJobManager::Init: adding layers\n");
  }
LABEL_84:
  areaDecl = gameLocal->world->areaDecl;
  if ( areaDecl != nullptr )
    idJobManager::GiveSpecialEventArea(this, specialEventArea: areaDecl);
  idStr::FreeData(this: v46);
}


// ========================================================================
// $LN275
// EA  : 0x82E1D4AC
// RVA : 0x00E1D4AC
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _LN275()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$517077
// EA  : 0x82E1D4D4
// RVA : 0x00E1D4D4
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void _unwind_517077()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 112));
}


// ========================================================================
// ?NotifyInventoryAdded@idJobManager@@QAAXPBVidInventoryItem@@@Z
// EA  : 0x82E1D500
// RVA : 0x00E1D500
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::NotifyInventoryAdded(idJobManager *this, const idInventoryItem *item)
{
  const idDeclJob *v3; // r3
  idStrId *v4; // r30
  idJob *JobByDecl; // r3
  int v6; // r5
  int v7; // [sp+50h] [-20h] BYREF

  v7 = -1;
  v3 = idJobManager::CanItemCompleteAJob(this, item, requirementNum: &v7);
  v4 = (idStrId *)v3;
  if ( v3 != nullptr )
  {
    if ( (unsigned __int8)idJobManager::IsJobReadyToTurnIn(this, jobDecl: v3) != 0 )
    {
      idJobManager::SetJobReadyToTurnIn(
        this,
        jobDecl: v4,
        completeTree: false,
        giveJobIfNeeded: false,
        hideIfGiven: false,
        force: false);
    }
    else
    {
      JobByDecl = idJobManager::FindJobByDecl(this, jobDecl: (const idDeclJob *)v4);
      idJobManager::UpdatePlayerHud(
        this,
        job: JobByDecl,
        requirementNum: v6,
        playSound: true,
        treatAsSameStatusUpdate: true);
    }
  }
}


// ========================================================================
// ?TriggerJobReadyToTurnInFromTarget@idJobManager@@QAA_NPBVidDeclJob@@_N111PAVidEntity@@PBVidDeclCameraTrigger@@@Z
// EA  : 0x82E1D5A0
// RVA : 0x00E1D5A0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

int __fastcall idJobManager::TriggerJobReadyToTurnInFromTarget(
        idJobManager *this,
        idStrId *jobDecl,
        bool completeTree,
        bool giveJobIfNeeded,
        bool hideIfGiven,
        bool force,
        idEntity *activator,
        const idDeclCameraTrigger *cameraTriggerDecl)
{
  BOOL inDebug; // r31
  idStrId *JobName; // r3
  const char *LocalizedString; // r3
  int count; // r29
  int v21; // r27
  int i; // r31
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3
  char v24; // r26
  idJob *JobByDecl; // r31
  idStrId *v26; // r4
  int v27; // r11
  missionStatus_t status; // r11
  char v29; // r11
  bool v30; // zf
  BOOL v31; // r31
  idStrId *v32; // r3
  const char *v33; // r3
  idPlayer *owner; // r3
  _BYTE v35[128]; // [sp+50h] [-80h] BYREF

  if ( jobDecl == nullptr )
  {
    idLib::Warning(fmt: "NULL jobDecl in TriggerJobReadyToTurnInFromTarget");
    return 0;
  }
  if ( jobDebug_PrintChanges.valueInteger != 0 )
  {
    inDebug = this->inDebug;
    JobName = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v35, result: jobDecl);
    LocalizedString = idStrId::GetLocalizedString(this: JobName);
    idLib::Printf(
      fmt: "TriggerJobReadyToTurnInFromTarget %s, complete: %d, give: %d, hide: %d, debug: %d, force: %d\n",
      LocalizedString,
      completeTree,
      giveJobIfNeeded,
      hideIfGiven,
      inDebug,
      force);
  }
  count = -1;
  v21 = -1;
  for ( i = 0; i < idDeclJob::GetNumCompletionRequirements(this: (idDeclJob *)jobDecl); ++i )
  {
    CompletionRequirement = idDeclJob::GetCompletionRequirement(this: (idDeclJob *)jobDecl, idx: i);
    if ( CompletionRequirement->completion == JOBCOMPLETE_TRIGGER && CompletionRequirement->count > count )
    {
      count = CompletionRequirement->count;
      v21 = i;
    }
  }
  v24 = 0;
  if ( count >= 0 )
  {
    if ( count != 0 )
    {
      JobByDecl = idJobManager::FindJobByDecl(this, (const idDeclJob *)jobDecl);
      if ( JobByDecl == nullptr )
      {
        if ( !giveJobIfNeeded )
          return 0;
        idJobManager::AcceptJob(this, jobDecl: v26, completeTree, force);
        if ( !hideIfGiven
          || (JobByDecl = idJobManager::FindJobByDecl(this, (const idDeclJob *)jobDecl),
              idJob::SetJobStatus(
                this: JobByDecl,
                newStatus: JOBSTATUS_NONE,
                manager: this,
                fireOffJobTargets: true,
                debug: this->inDebug),
              JobByDecl == nullptr) )
        {
          JobByDecl = idJobManager::FindJobByDecl(this, (const idDeclJob *)jobDecl);
          if ( JobByDecl == nullptr )
          {
            idLib::Warning(fmt: "ERROR IN TriggerJobReadyToTurnInFromTarget %s", (const char *)jobDecl[2].index);
            return 0;
          }
        }
      }
      v27 = JobByDecl->triggeredCount + 1;
      JobByDecl->triggeredCount = v27;
      if ( v27 < count )
      {
        status = JobByDecl->status;
        if ( status == JOBSTATUS_READYTOTURNIN || (v30 = status != JOBSTATUS_ACCEPTED, v29 = 0, !v30) )
          v29 = 1;
        if ( v29 != 0 )
          idJobManager::UpdatePlayerHud(
            this,
            job: JobByDecl,
            requirementNum: v21,
            playSound: true,
            treatAsSameStatusUpdate: true);
        if ( jobDebug_PrintChanges.valueInteger != 0 )
        {
          v31 = this->inDebug;
          v32 = (idStrId *)idDeclJob::GetJobName(this: (idDeclJob *)v35, result: jobDecl);
          v33 = idStrId::GetLocalizedString(this: v32);
          idLib::Printf(
            fmt: "FAILED:\tTriggerJobReadyToTurnInFromTarget %s, complete: %d, give: %d, hide: %d, debug: %d, force: %d\n",
            v33,
            completeTree,
            giveJobIfNeeded,
            hideIfGiven,
            v31,
            force);
        }
      }
      else
      {
        v24 = 1;
      }
    }
    else
    {
      v24 = 1;
    }
  }
  else
  {
    idLib::Warning(
      fmt: "Got a trigger to set job ready to turn in that does not have a completion requirement of JOBCOMPLETE_TRIGGER ,%s, FYI",
      (const char *)jobDecl[2].index);
    v24 = 1;
  }
  if ( v24 == 0
    || (unsigned __int8)idJobManager::SetJobReadyToTurnIn(
                          this,
                          jobDecl,
                          completeTree,
                          giveJobIfNeeded,
                          hideIfGiven,
                          force) == 0 )
  {
    return 0;
  }
  if ( (unsigned __int8)idDeclJob::UseDynamicJobHud(this: (idDeclJob *)jobDecl) != 0 && !this->inDebug )
  {
    owner = this->owner;
    if ( owner != nullptr && *(_BYTE *)(idPlayer::GetPlayerHud(this: owner) + 9) == 0 && cameraTriggerDecl != nullptr )
      idPlayer::ActivateCinematicCamera(this: this->owner, cameraTriggerDecl, activator);
  }
  return 1;
}


// ========================================================================
// ?SetGameStateIntValue@idJobManager@@QAAXPBDH@Z
// EA  : 0x82E1D898
// RVA : 0x00E1D898
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __fastcall idJobManager::SetGameStateIntValue(idJobManager *this, const char *name, int stateValue)
{
  const idDeclGameStateInt *v6; // r4

  if ( name != nullptr
    && (v6 = (const idDeclGameStateInt *)idDeclInfo::FindWithInheritance(
                                           this: &idDeclGameStateInt::resourceList,
                                           name,
                                           makeDefault: false)) != nullptr )
  {
    idJobManager::SetGameStateIntValue(this, gameState: v6, stateValue);
  }
  else
  {
    idLib::Warning(fmt: "idJobManager::SetGameStateIntValue, unknown gameStateInt %s", name);
  }
}


// ========================================================================
// `dynamic initializer for 'jobDebug_PrintChanges''
// EA  : 0x83388678
// RVA : 0x01388678
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobDebug_PrintChanges__()
{
  idCVar::idCVar(
    this: &jobDebug_PrintChanges,
    name: "jobDebug_PrintChanges",
    value: "0",
    flags: 1,
    description: "print out messages when jobs are told to change state",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobDebug_PrintChanges__);
}


// ========================================================================
// `dynamic initializer for 'jobDebug_PrintStatus''
// EA  : 0x833886D0
// RVA : 0x013886D0
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobDebug_PrintStatus__()
{
  idCVar::idCVar(
    this: &jobDebug_PrintStatus,
    name: "jobDebug_PrintStatus",
    value: "0",
    flags: 1,
    description: "print out messages when jobs actually change state",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobDebug_PrintStatus__);
}


// ========================================================================
// `dynamic initializer for 'jobDebug_JobNoteWarnings''
// EA  : 0x83388728
// RVA : 0x01388728
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobDebug_JobNoteWarnings__()
{
  idCVar::idCVar(
    this: &jobDebug_JobNoteWarnings,
    name: "jobDebug_JobNoteWarnings",
    value: "0",
    flags: 1,
    description: "print out messages for job note warnings",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobDebug_JobNoteWarnings__);
}


// ========================================================================
// `dynamic initializer for 'g_debugDLCRewards''
// EA  : 0x83388780
// RVA : 0x01388780
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugDLCRewards__()
{
  idCVar::idCVar(
    this: &g_debugDLCRewards,
    name: "g_debugDLCRewards",
    value: "0",
    flags: 1,
    description: "print out messages for debuging DLC reward info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugDLCRewards__);
}


// ========================================================================
// `dynamic initializer for 'job_timeToShowBashInfoGui''
// EA  : 0x833887D8
// RVA : 0x013887D8
// PDB : w:\tech5\tungsten\game\player\jobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__job_timeToShowBashInfoGui__()
{
  idCVar::idCVar(
    this: &job_timeToShowBashInfoGui,
    name: "job_timeToShowBashInfoGui",
    value: "10",
    flags: 2,
    description: "how long in seconds to show the gui info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__job_timeToShowBashInfoGui__);
}

