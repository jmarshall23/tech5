
// ========================================================================
// ??0idAchievement@@QAA@XZ
// EA  : 0x82DEFD68
// RVA : 0x00DEFD68
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

idAchievement *__fastcall idAchievement::idAchievement(idAchievement *this)
{
  idAchievement::eventAchievementInfo_t *eventInfo; // r3
  idAchievement::eventAchievementInfo_t *v3; // r10
  int v4; // ctr
  idAchievement::eventAchievementInfo_t *v5; // r10
  int i; // ctr

  this->decl = nullptr;
  this->itemsFulfilled = false;
  eventInfo = this->eventInfo;
  v3 = eventInfo - 1;
  this->jobsFulfilled = false;
  v4 = 30;
  this->triggersFulfilled = false;
  this->eventsFulfilled = false;
  this->racesFulfilled = false;
  this->achievementsFulfilled = false;
  this->__vftable = (idAchievement_vtbl *)&idAchievement::`vftable';
  do
  {
    ++v3;
    v3->count = 0;
    --v4;
  }
  while ( v4 != 0 );
  v5 = &this->eventInfo[29];
  for ( i = 30; i != 0; --i )
  {
    ++v5;
    v5->count = 0;
  }
  *(_WORD *)this->triggersActivated = 0;
  *(_WORD *)&this->triggersActivated[2] = 0;
  *(_WORD *)&this->triggersActivated[4] = 0;
  memset(Dst: eventInfo, Val: 0, Size: 0x78u);
  memset(Dst: this->racesInfo, Val: 0, Size: sizeof(this->racesInfo));
  memset(Dst: this->achievementsGained, Val: 0, Size: sizeof(this->achievementsGained));
  return this;
}


// ========================================================================
// ?CheckJobRequirements@idAchievement@@QAA_NABVidPlayer@@@Z
// EA  : 0x82DEFE30
// RVA : 0x00DEFE30
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievement::CheckJobRequirements(idAchievement *this, const idPlayer *player)
{
  int num; // r11
  int v5; // r28
  idJobManager *p_jobManager; // r29
  int v7; // r31
  bool v8; // r11

  if ( this->jobsFulfilled )
    return 1;
  num = this->decl->jobDecl.num;
  if ( num != 0 )
  {
    v5 = 0;
    if ( num <= 0 )
      goto LABEL_12;
    p_jobManager = &player->jobManager;
    v7 = 0;
    do
    {
      if ( !idJobManager::IsJobReadyToTurnIn(this: p_jobManager, name: this->decl->jobDecl.list[v7].data)
        && !idJobManager::IsJobComplete(this: p_jobManager, name: this->decl->jobDecl.list[v7].data) )
      {
        break;
      }
      ++v5;
      ++v7;
    }
    while ( v5 < this->decl->jobDecl.num );
    if ( v5 <= 0 || (v8 = true, v5 != this->decl->jobDecl.num) )
LABEL_12:
      v8 = false;
    this->jobsFulfilled = v8;
    return v8;
  }
  else
  {
    this->jobsFulfilled = true;
    return 1;
  }
}


// ========================================================================
// ?GetJobCompletionRequirements@idAchievement@@QBAXABVidPlayer@@AAH1@Z
// EA  : 0x82DEFF20
// RVA : 0x00DEFF20
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievement::GetJobCompletionRequirements(
        idAchievement *this,
        const idPlayer *player,
        int *gained,
        int *required)
{
  int v4; // r28
  const idDeclAchievement *decl; // r11
  idJobManager *p_jobManager; // r29
  int v9; // r31

  v4 = 0;
  *required = this->decl->jobDecl.num;
  *gained = 0;
  decl = this->decl;
  if ( decl->jobDecl.num > 0 )
  {
    p_jobManager = &player->jobManager;
    v9 = 0;
    do
    {
      if ( idJobManager::IsJobReadyToTurnIn(this: p_jobManager, name: decl->jobDecl.list[v9].data)
        || idJobManager::IsJobComplete(this: p_jobManager, name: this->decl->jobDecl.list[v9].data) )
      {
        ++*gained;
      }
      decl = this->decl;
      ++v4;
      ++v9;
    }
    while ( v4 < decl->jobDecl.num );
  }
}


// ========================================================================
// ?CheckInventoryRequirements@idAchievement@@QAA_NABVidPlayer@@@Z
// EA  : 0x82DEFFD0
// RVA : 0x00DEFFD0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievement::CheckInventoryRequirements(idAchievement *this, const idPlayer *player)
{
  int num; // r11
  int v6; // r27
  int v7; // r26
  int v8; // r29
  char *data; // r31
  idJobManager *v10; // r3
  idJob *InventoryItemByDeclName; // r3
  idJob *v12; // r31
  idDeclAchievement::inventoryAchievement_t *v13; // r30
  const idDeclJob *decl; // r11
  int v15; // r10
  int v16; // r11
  bool v17; // r11

  if ( this->itemsFulfilled )
    return 1;
  num = this->decl->item.num;
  if ( num != 0 )
  {
    v6 = 0;
    v7 = 0;
    if ( num > 0 )
    {
      v8 = 0;
      do
      {
        data = this->decl->item.list[v8].itemDecl.data;
        v10 = (idJobManager *)player->GetInventory(this: player);
        InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(this: v10, jobName: data);
        v12 = InventoryItemByDeclName;
        if ( InventoryItemByDeclName != nullptr )
        {
          v13 = &this->decl->item.list[v8];
          if ( ((int (__fastcall *)(idJob *))InventoryItemByDeclName->__vftable[2].dtr_idClass)(a1: InventoryItemByDeclName) < v13->count )
            break;
          decl = v12->decl;
          if ( *(_DWORD *)&decl->jobLayerInfo.completeLayersRemove.granularity != 0 )
          {
            v15 = -1;
            if ( decl != nullptr )
            {
              while ( 1 )
              {
                ++v15;
                ++v6;
                if ( v15 > idDeclRecipe::resourceList.num )
                {
                  idLib::Warning(fmt: "CheckInventoryRequirements() - found a loop in the idDeclRecipe list");
                  return 0;
                }
                v16 = *(_DWORD *)&decl->jobLayerInfo.completeLayersRemove.granularity;
                if ( v16 == 0 )
                  break;
                decl = *(const idDeclJob **)(v16 + 68);
                if ( decl == nullptr )
                  goto LABEL_16;
              }
              idLib::Warning(fmt: "CheckInventoryRequirements() - recipe replaced an inventory item that does not specify a recipe");
              return 0;
            }
          }
          else
          {
            ++v6;
          }
        }
LABEL_16:
        ++v7;
        ++v8;
      }
      while ( v7 < this->decl->item.num );
      if ( v6 > 0 )
      {
        v17 = true;
        if ( v6 == this->decl->item.num )
          goto LABEL_20;
      }
    }
    v17 = false;
LABEL_20:
    this->itemsFulfilled = v17;
    return v17;
  }
  else
  {
    this->itemsFulfilled = true;
    return 1;
  }
}


// ========================================================================
// ?GetInventoryCompletionRequirements@idAchievement@@QBAXABVidPlayer@@AAH1@Z
// EA  : 0x82DF0168
// RVA : 0x00DF0168
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievement::GetInventoryCompletionRequirements(
        idAchievement *this,
        const idPlayer *player,
        int *gained,
        int *required)
{
  int v8; // r22
  int i; // r27
  char *data; // r31
  idJobManager *v11; // r3
  idJob *InventoryItemByDeclName; // r3
  idJob *v13; // r31
  idDeclAchievement::inventoryAchievement_t *v14; // r30
  int count; // r3
  int v16; // r11
  int v17; // r9
  int v18; // r11
  int v19; // r10

  *required = 0;
  *gained = 0;
  v8 = 0;
  if ( this->decl->item.num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      *required += this->decl->item.list[i].count;
      data = this->decl->item.list[i].itemDecl.data;
      v11 = (idJobManager *)player->GetInventory(this: player);
      InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(this: v11, jobName: data);
      v13 = InventoryItemByDeclName;
      if ( InventoryItemByDeclName != nullptr )
      {
        v14 = &this->decl->item.list[i];
        count = ((int (__fastcall *)(idJob *))InventoryItemByDeclName->__vftable[2].dtr_idClass)(a1: InventoryItemByDeclName);
        if ( count >= 0 )
        {
          if ( count > v14->count )
            count = v14->count;
        }
        else
        {
          count = 0;
        }
        *gained += count;
        v16 = *(_DWORD *)&v13->decl->jobLayerInfo.completeLayersRemove.granularity;
        if ( v16 != 0 )
        {
          v17 = *(_DWORD *)(v16 + 68);
          v18 = 0;
          if ( v17 != 0 )
            break;
        }
      }
LABEL_13:
      if ( ++v8 >= this->decl->item.num )
        return;
    }
    while ( 1 )
    {
      ++v18;
      ++*gained;
      if ( v18 > idDeclRecipe::resourceList.num )
        break;
      v19 = *(_DWORD *)(v17 + 376);
      if ( v19 == 0 )
        break;
      v17 = *(_DWORD *)(v19 + 68);
      if ( v17 == 0 )
        goto LABEL_13;
    }
    idLib::Warning(fmt: "GetInventoryCompletionRequirements() - bad data or a loop in the idDeclRecipe list");
    *gained = 0;
    *required = 0;
  }
}


// ========================================================================
// ?CheckTriggerRequirements@idAchievement@@QAA_NXZ
// EA  : 0x82DF02E0
// RVA : 0x00DF02E0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievement::CheckTriggerRequirements(idAchievement *this)
{
  int num; // r8
  int v3; // r11
  bool v4; // r11
  bool v5; // zf

  if ( this->triggersFulfilled )
    return 1;
  num = this->decl->trigger.num;
  if ( num != 0 )
  {
    v3 = 0;
    if ( num <= 0 )
      goto LABEL_10;
    do
    {
      if ( !this->triggersActivated[v3] )
        break;
      ++v3;
    }
    while ( v3 < this->decl->trigger.num );
    if ( v3 <= 0 || (v5 = v3 == num, v4 = true, !v5) )
LABEL_10:
      v4 = false;
    this->triggersFulfilled = v4;
    return v4;
  }
  else
  {
    this->triggersFulfilled = true;
    return 1;
  }
}


// ========================================================================
// ?SetTriggered@idAchievement@@QAAXW4triggerAchievementId_t@@@Z
// EA  : 0x82DF0370
// RVA : 0x00DF0370
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievement::SetTriggered(idAchievement *this, const triggerAchievementId_t taid)
{
  int triggersFulfilled; // r11
  const idDeclAchievement *decl; // r7
  int num; // r9
  int v5; // r10

  triggersFulfilled = this->triggersFulfilled;
  if ( !this->triggersFulfilled )
  {
    decl = this->decl;
    num = decl->trigger.num;
    if ( num != 0 )
    {
      v5 = 0;
      if ( num > 0 )
      {
        while ( this->triggersActivated[v5]
             || *(triggerAchievementId_t *)((char *)decl->trigger.list + triggersFulfilled) != taid )
        {
          ++v5;
          triggersFulfilled += 4;
          if ( v5 >= num )
            return;
        }
        this->triggersActivated[v5] = true;
      }
    }
  }
}


// ========================================================================
// ?GetTriggeredCompletionRequirements@idAchievement@@QBAXAAH0@Z
// EA  : 0x82DF03D8
// RVA : 0x00DF03D8
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievement::GetTriggeredCompletionRequirements(idAchievement *this, int *gained, int *required)
{
  int v3; // r11

  v3 = 0;
  *required = this->decl->trigger.num;
  for ( *gained = 0; v3 < this->decl->trigger.num; ++v3 )
  {
    if ( this->triggersActivated[v3] )
      ++*gained;
  }
}


// ========================================================================
// ?CheckAchievementRequirements@idAchievement@@QAA_NXZ
// EA  : 0x82DF0430
// RVA : 0x00DF0430
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievement::CheckAchievementRequirements(idAchievement *this)
{
  const idDeclAchievement *decl; // r7
  int num; // r6
  int v4; // r9
  int v5; // r10
  unsigned int v6; // r11
  bool v7; // r11

  if ( this->achievementsFulfilled )
    return 1;
  decl = this->decl;
  num = decl->achievements.num;
  if ( num != 0 )
  {
    v4 = 0;
    if ( num <= 0 )
      goto LABEL_12;
    v5 = 0;
    do
    {
      v6 = decl->achievements.list[v5];
      if ( v6 <= 0x30 && !this->achievementsGained[v6] )
        break;
      ++v4;
      ++v5;
    }
    while ( v4 < this->decl->achievements.num );
    if ( v4 <= 0 || (v7 = true, v4 != num) )
LABEL_12:
      v7 = false;
    this->achievementsFulfilled = v7;
    return v7;
  }
  else
  {
    this->achievementsFulfilled = true;
    return 1;
  }
}


// ========================================================================
// ?SetAchievementGained@idAchievement@@QAAXW4achievementId_t@@@Z
// EA  : 0x82DF04E0
// RVA : 0x00DF04E0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievement::SetAchievementGained(idAchievement *this, const achievementId_t achievementId)
{
  const idDeclAchievement *decl; // r11
  int num; // r6
  int v4; // r7
  achievementId_t *list; // r9
  int i; // r11
  achievementId_t v7; // r10

  if ( !this->achievementsFulfilled )
  {
    decl = this->decl;
    num = decl->achievements.num;
    if ( num != 0 )
    {
      v4 = 0;
      if ( num > 0 )
      {
        list = decl->achievements.list;
        for ( i = 0; ; ++i )
        {
          v7 = list[i];
          if ( !this->achievementsGained[v7] && v7 == achievementId )
            break;
          if ( ++v4 >= num )
            return;
        }
        this->achievementsGained[v7] = true;
      }
    }
  }
}


// ========================================================================
// ?GetAchievementCompletionRequirements@idAchievement@@QBAXABVidPlayer@@AAH1@Z
// EA  : 0x82DF0550
// RVA : 0x00DF0550
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievement::GetAchievementCompletionRequirements(
        idAchievement *this,
        const idPlayer *player,
        int *gained,
        int *required)
{
  int v4; // r31
  const idDeclAchievement *decl; // r11
  int v9; // r30
  idAchievementManager *p_achievementManager; // r26
  int v11; // r10
  int v12; // [sp+50h] [-40h] BYREF
  int v13; // [sp+54h] [-3Ch] BYREF

  v4 = 0;
  *required = 0;
  *gained = 0;
  decl = this->decl;
  v9 = 0;
  if ( decl->achievements.num > 0 )
  {
    p_achievementManager = &player->achievementManager;
    do
    {
      idAchievementManager::GetAchievementCompletionPercent(
        this: p_achievementManager,
        id: (const achievementId_t)decl->achievements.list[v4],
        gained: &v12,
        required: &v13,
        isFulfilled: nullptr);
      ++v9;
      ++v4;
      v11 = v13;
      *gained += v12;
      *required += v11;
      decl = this->decl;
    }
    while ( v9 < decl->achievements.num );
  }
}


// ========================================================================
// ?CheckRaceRequirements@idAchievement@@QAA_NXZ
// EA  : 0x82DF05E8
// RVA : 0x00DF05E8
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievement::CheckRaceRequirements(idAchievement *this)
{
  const idDeclAchievement *decl; // r8
  int num; // r4
  int v4; // r6
  int v5; // r7
  int v6; // r10
  idAchievement::raceAchievementInfo_t *racesInfo; // r11

  if ( this->racesFulfilled )
    return 1;
  decl = this->decl;
  num = decl->races.num;
  if ( num != 0 )
  {
    v4 = 0;
    v5 = 0;
    if ( num <= 0 )
      goto LABEL_16;
    v6 = 0;
    racesInfo = this->racesInfo;
    do
    {
      if ( racesInfo->place >= decl->races.list[v6].place )
      {
        ++v4;
        if ( !decl->allRacesRequired )
          break;
      }
      else if ( decl->allRacesRequired )
      {
        break;
      }
      ++v5;
      ++racesInfo;
      ++v6;
    }
    while ( v5 < this->decl->races.num );
    if ( v4 <= 0 || v4 != num && decl->allRacesRequired )
    {
LABEL_16:
      this->racesFulfilled = false;
      return 0;
    }
    else
    {
      this->racesFulfilled = true;
      return 1;
    }
  }
  else
  {
    this->racesFulfilled = true;
    return 1;
  }
}


// ========================================================================
// ?SetRacePlace@idAchievement@@QAAXABVidStr@@W4raceMemoryPlace_t@@@Z
// EA  : 0x82DF06C0
// RVA : 0x00DF06C0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievement::SetRacePlace(idAchievement *this, const idStr *raceName, raceMemoryPlace_t place)
{
  const idDeclAchievement *decl; // r11
  int num; // r10
  int v8; // r30
  int i; // r31

  if ( !this->racesFulfilled )
  {
    decl = this->decl;
    num = decl->races.num;
    if ( num != 0 )
    {
      v8 = 0;
      if ( num > 0 )
      {
        for ( i = 0; idStr::Cmp(s1: decl->races.list[i].raceName.data, s2: raceName->data) != 0; ++i )
        {
          decl = this->decl;
          if ( ++v8 >= decl->races.num )
            return;
        }
        this->racesInfo[v8].place = place;
      }
    }
  }
}


// ========================================================================
// ?GetRaceCompletionRequirements@idAchievement@@QBAXAAH0@Z
// EA  : 0x82DF0750
// RVA : 0x00DF0750
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievement::GetRaceCompletionRequirements(idAchievement *this, int *gained, int *required)
{
  int v3; // r8
  const idDeclAchievement *decl; // r11
  int v5; // r9
  idAchievement::raceAchievementInfo_t *racesInfo; // r10
  int v7; // r11
  int v8; // r11

  v3 = 0;
  *required = this->decl->races.num;
  *gained = 0;
  decl = this->decl;
  if ( decl->races.num > 0 )
  {
    v5 = 0;
    racesInfo = this->racesInfo;
    do
    {
      if ( racesInfo->place >= decl->races.list[v5].place )
        ++*gained;
      decl = this->decl;
      ++v3;
      ++racesInfo;
      ++v5;
    }
    while ( v3 < decl->races.num );
  }
  if ( !decl->allRacesRequired )
  {
    v7 = *required;
    if ( *required >= 0 )
    {
      if ( v7 > 1 )
        v7 = 1;
    }
    else
    {
      v7 = 0;
    }
    *required = v7;
    v8 = *gained;
    if ( *gained >= 0 )
    {
      if ( v8 > 1 )
        v8 = 1;
      *gained = v8;
    }
    else
    {
      *gained = 0;
    }
  }
}


// ========================================================================
// ?CheckEventRequirements@idAchievement@@QAA_NXZ
// EA  : 0x82DF0820
// RVA : 0x00DF0820
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievement::CheckEventRequirements(idAchievement *this)
{
  const idDeclAchievement *decl; // r11
  int num; // r10
  int v5; // r25
  int v6; // r29
  int v7; // r31
  idAchievement::eventAchievementInfo_t *eventInfo; // r28
  idDeclAchievement::statConstraint_t *v9; // r11

  if ( this->eventsFulfilled )
    return 1;
  decl = this->decl;
  num = decl->events.num;
  if ( num != 0 )
  {
    v5 = 0;
    v6 = 0;
    if ( num <= 0 )
      goto LABEL_16;
    v7 = 0;
    eventInfo = this->eventInfo;
    do
    {
      idLib::WarningIf(
        condition: (_cntlzw(decl->events.list[v7].stat + 1) & 0x20) != 0,
        fmt: "Invalid achievement (%s) event %d, stat Invalid",
        decl->name.str,
        v6);
      v9 = &this->decl->events.list[v7];
      idLib::WarningIf(condition: v9->count < 0, fmt: "Invalid achievement event %d, count < 0", v9->stat);
      decl = this->decl;
      if ( eventInfo->count >= decl->events.list[v7].count )
      {
        ++v5;
        if ( !decl->allEventsRequired )
          break;
      }
      else if ( decl->allEventsRequired )
      {
        break;
      }
      ++v6;
      ++eventInfo;
      ++v7;
    }
    while ( v6 < this->decl->events.num );
    if ( v5 <= 0 || v5 != decl->events.num && decl->allEventsRequired )
    {
LABEL_16:
      this->eventsFulfilled = false;
      return 0;
    }
    else
    {
      this->eventsFulfilled = true;
      return 1;
    }
  }
  else
  {
    this->eventsFulfilled = true;
    return 1;
  }
}


// ========================================================================
// ?GetEventCompletionRequirements@idAchievement@@QBAXAAH0@Z
// EA  : 0x82DF0970
// RVA : 0x00DF0970
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievement::GetEventCompletionRequirements(idAchievement *this, int *gained, int *required)
{
  int v3; // r30
  int v4; // r29
  int v5; // r28
  int v6; // r31
  int v7; // r8
  idAchievement::eventAchievementInfo_t *eventInfo; // r6
  int count; // r11
  idDeclAchievement::statConstraint_t *v10; // r9
  const idDeclAchievement *decl; // r10
  int v12; // r11
  int v13; // r9
  int num; // r11

  *required = 0;
  v3 = 0;
  *gained = 0;
  v4 = 0x7FFFFFFF;
  v5 = 0x7FFFFFFF;
  v6 = 0x7FFFFFFF;
  if ( this->decl->events.num > 0 )
  {
    v7 = 0;
    eventInfo = this->eventInfo;
    do
    {
      *required += this->decl->events.list[v7].count;
      count = eventInfo->count;
      v10 = &this->decl->events.list[v7];
      if ( eventInfo->count >= 0 )
      {
        if ( count > v10->count )
          count = v10->count;
      }
      else
      {
        count = 0;
      }
      *gained += count;
      decl = this->decl;
      v12 = eventInfo->count;
      v13 = decl->events.list[v7].count;
      if ( v13 - eventInfo->count < v6 && v6 >= 0 )
      {
        if ( v12 >= 0 )
        {
          v5 = decl->events.list[v7].count;
          if ( v12 <= v13 )
            v5 = eventInfo->count;
        }
        else
        {
          v5 = 0;
        }
        v4 = decl->events.list[v7].count;
        v6 = v13 - eventInfo->count;
      }
      num = decl->events.num;
      ++v3;
      ++eventInfo;
      ++v7;
    }
    while ( v3 < num );
    if ( num > 0 && !decl->allEventsRequired )
    {
      *required = v4;
      *gained = v5;
    }
  }
}


// ========================================================================
// ?ClearAllRequirements@idAchievementManager@@QAAXXZ
// EA  : 0x82DF0A98
// RVA : 0x00DF0A98
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievementManager::ClearAllRequirements(idAchievementManager *this)
{
  int v1; // r6
  int v2; // r7
  idAchievement *v3; // r11
  int v4; // ctr
  int v5; // r9
  bool *v6; // r9
  int i; // ctr
  int v8; // r9
  bool *achievementsGained; // r11
  int j; // ctr

  v1 = 0;
  if ( this->achievements.num > 0 )
  {
    v2 = 0;
    do
    {
      v3 = &this->achievements.list[v2];
      v4 = 6;
      v5 = 0;
      v3->itemsFulfilled = false;
      v3->jobsFulfilled = false;
      v3->triggersFulfilled = false;
      v3->eventsFulfilled = false;
      v3->achievementsFulfilled = false;
      do
      {
        v3->triggersActivated[v5++] = false;
        --v4;
      }
      while ( v4 != 0 );
      v6 = &v3->achievementsGained[48];
      for ( i = 30; i != 0; --i )
      {
        v6 += 4;
        *(_DWORD *)v6 = 0;
      }
      v8 = 0;
      achievementsGained = v3->achievementsGained;
      for ( j = 49; j != 0; --j )
        achievementsGained[v8++] = false;
      ++v1;
      ++v2;
    }
    while ( v1 < this->achievements.num );
  }
}


// ========================================================================
// ?CheckAllRequirements@idAchievement@@QAA_NABVidPlayer@@@Z
// EA  : 0x82DF0BA0
// RVA : 0x00DF0BA0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievement::CheckAllRequirements(idAchievement *this, const idPlayer *player)
{
  char v4; // r3
  unsigned __int8 v5; // r11

  if ( (unsigned __int8)idAchievement::CheckJobRequirements(this, player) == 0 )
    return 0;
  if ( (unsigned __int8)idAchievement::CheckInventoryRequirements(this, player) == 0 )
    return 0;
  if ( (unsigned __int8)idAchievement::CheckTriggerRequirements(this) == 0 )
    return 0;
  if ( (unsigned __int8)idAchievement::CheckAchievementRequirements(this) == 0 )
    return 0;
  if ( (unsigned __int8)idAchievement::CheckEventRequirements(this) == 0 )
    return 0;
  v4 = idAchievement::CheckRaceRequirements(this);
  v5 = 1;
  if ( v4 == 0 )
    return 0;
  return v5;
}


// ========================================================================
// ?GetCompletionPercent@idAchievement@@QBAMABVidPlayer@@AAH1@Z
// EA  : 0x82DF0C58
// RVA : 0x00DF0C58
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idAchievement::GetCompletionPercent(
        idAchievement *this,
        const idPlayer *player,
        int *gained,
        int *required)
{
  int v8; // r30
  int v9; // r29
  int v10; // r30
  int v11; // r29
  int v12; // r30
  int v13; // r29
  idAchievement *v14; // r3
  int v15; // r30
  int v16; // r29
  int v17; // r30
  int v18; // r31
  idAchievement *v19; // r3
  __int64 v20; // r11 OVERLAPPED
  bool v21; // cr33
  double v22; // fp1
  int v24[2]; // [sp+50h] [-50h] BYREF
  int v25[18]; // [sp+58h] [-48h] BYREF

  v24[0] = 0;
  v25[0] = 0;
  idAchievement::GetJobCompletionRequirements(this, player, gained: v24, required: v25);
  v8 = v24[0];
  v9 = v25[0];
  v24[0] = 0;
  v25[0] = 0;
  idAchievement::GetInventoryCompletionRequirements(this, player, gained: v24, required: v25);
  v10 = v24[0] + v8;
  v24[0] = 0;
  v11 = v25[0] + v9;
  v25[0] = 0;
  idAchievement::GetTriggeredCompletionRequirements(this, gained: v24, required: v25);
  v12 = v24[0] + v10;
  v24[0] = 0;
  v13 = v25[0] + v11;
  v25[0] = 0;
  idAchievement::GetAchievementCompletionRequirements(this: v14, player, gained: v24, required: v25);
  v15 = v24[0] + v12;
  v24[0] = 0;
  v16 = v25[0] + v13;
  v25[0] = 0;
  idAchievement::GetRaceCompletionRequirements(this, gained: v24, required: v25);
  v17 = v24[0] + v15;
  v24[0] = 0;
  v18 = v25[0] + v16;
  v25[0] = 0;
  idAchievement::GetEventCompletionRequirements(this: v19, gained: v24, required: v25);
  HIDWORD(v20) = v24[0] + v17;
  LODWORD(v20) = v25[0] + v18;
  v21 = v25[0] + v18 > 0;
  *gained = v24[0] + v17;
  *required = v20;
  if ( v21 )
  {
    *(_QWORD *)v25 = *(__int64 *)((char *)&v20 + 4);
    v22 = (float)((float)*(__int64 *)((char *)&v20 + 4) / (float)v20);
  }
  else
  {
    v22 = 0.0;
  }
  return *((float *)&v22 + 1);
}


// ========================================================================
// ?GetAchievementCompletionPercent@idAchievementManager@@QBAMW4achievementId_t@@AAH1PA_N@Z
// EA  : 0x82DF0DB0
// RVA : 0x00DF0DB0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

float __fastcall idAchievementManager::GetAchievementCompletionPercent(
        idAchievementManager *this,
        const achievementId_t id,
        int *gained,
        int *required,
        bool *isFulfilled)
{
  int num; // r31
  int v6; // r10
  idAchievement *list; // r8
  int v8; // r11
  idAchievement *v9; // r9
  double CompletionPercent; // fp1
  idAchievement *v11; // r11
  bool v12; // r11
  bool racesFulfilled; // zf

  num = this->achievements.num;
  v6 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    idLib::Warning(fmt: "[%s] Invalid achievement id!", "idAchievementManager::GetAchievementCompletionPercent");
    CompletionPercent = 0.0;
  }
  else
  {
    list = this->achievements.list;
    v8 = 0;
    v9 = list;
    while ( v9->decl->id != id )
    {
      ++v6;
      v9 = &list[++v8];
      if ( v6 >= num )
        goto LABEL_5;
    }
    if ( isFulfilled != nullptr )
    {
      v11 = &list[v6];
      if ( !v11->itemsFulfilled
        || !v11->jobsFulfilled
        || !v11->triggersFulfilled
        || !v11->achievementsFulfilled
        || !v11->eventsFulfilled
        || (racesFulfilled = v11->racesFulfilled, v12 = true, !racesFulfilled) )
      {
        v12 = false;
      }
      *isFulfilled = v12;
    }
    CompletionPercent = idAchievement::GetCompletionPercent(
                          this: &this->achievements.list[v6],
                          player: this->owner,
                          gained,
                          required);
  }
  return *((float *)&CompletionPercent + 1);
}


// ========================================================================
// ?CheckClientRequirements@idAchievementManager@@SA_NPAVidLocalUser@@@Z
// EA  : 0x82DF0EC0
// RVA : 0x00DF0EC0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievementManager::CheckClientRequirements(idLocalUser *user)
{
  int v3; // r17
  int num; // r15
  int v5; // r20
  int v6; // r19
  const idDecl *v7; // r3
  const char *str; // r4
  const idDecl *v9; // r31
  char v10; // r25
  char v11; // r26
  int v12; // r27
  int v13; // r28
  rageStat_t v14; // r30
  __int64 v15; // [sp+50h] [-A0h]

  if ( session == nullptr || user == nullptr )
    return 0;
  v3 = 0;
  if ( idLib::production < PROD_PRODUCTION )
    num = idDeclAchievement::resourceList.declSources.num;
  else
    num = idDeclAchievement::resourceList.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( idLib::production < PROD_PRODUCTION )
      {
        str = idDeclAchievement::resourceList.declSources.list[v6]->name.str;
        if ( str != nullptr )
          v7 = idDeclInfo::FindWithInheritance(this: &idDeclAchievement::resourceList, name: str, makeDefault: false);
        else
          v7 = nullptr;
      }
      else
      {
        v7 = (const idDecl *)idResourceList::Index(this: &idDeclAchievement::resourceList, index: v5);
      }
      v9 = v7;
      if ( v7 != nullptr && v7[2].textLength > 0 )
      {
        v10 = 0;
        v11 = 0;
        v12 = 0;
        v13 = 0;
        do
        {
          v15 = *(_QWORD *)&v9[2].textSource[v13];
          v14 = *(_DWORD *)&v9[2].textSource[v13];
          if ( (int)v15 < 0 )
            idLib::Warning(fmt: "Invalid achievement event %d, count < 0", HIDWORD(v15));
          if ( RageStatTypeIsInt(stat: v14) )
          {
            if ( user->GetStatInt(this: user, a2: v14) < (int)v15 )
              v10 = 1;
            else
              v11 = 1;
          }
          ++v12;
          v13 += 8;
        }
        while ( v12 < v9[2].textLength );
        if ( v11 != 0 && HIBYTE(v9[2].declSource) == 0 || v10 == 0 && HIBYTE(v9[2].declSource) != 0 )
        {
          idLib::PrintfIf(
            condition: achievements_Verbose.valueInteger != 0,
            fmt: "Unlocking achievement from CheckClientRequirements: %s\n",
            v9->name.str);
          session->achievementSystem->AchievementUnlock(
            this: session->achievementSystem,
            a2: user,
            a3: (const int)v9[1].resourceListPtr);
          v3 = 1;
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
  return v3;
}


// ========================================================================
// ??0idAchievementManager@@QAA@XZ
// EA  : 0x82DF1180
// RVA : 0x00DF1180
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

idAchievementManager *__fastcall idAchievementManager::idAchievementManager(idAchievementManager *this)
{
  idList<idBackgroundLoader::bgrEntry_t,101> *p_eventBasedAchievementStamps; // r29
  idList<idSpawnArea::GeneratedPosition *,5> *p_eventBasedAchievementIndexer; // r28
  idList<idSpawnArea::GeneratedPosition *,5> *p_eventBasedAchievementValues; // r27
  int size; // r11
  int v6; // r11
  int v7; // r11

  this->owner = nullptr;
  this->__vftable = (idAchievementManager_vtbl *)&idAchievementManager::`vftable';
  this->achievements.granularity = 0;
  this->achievements.memTag = 5;
  this->achievements.listStatic = 0;
  this->achievements.list = nullptr;
  this->achievements.size = 0;
  this->achievements.num = 0;
  p_eventBasedAchievementStamps = (idList<idBackgroundLoader::bgrEntry_t,101> *)&this->eventBasedAchievementStamps;
  this->needsUpdate = false;
  this->eventBasedAchievementStamps.num = 0;
  this->eventBasedAchievementStamps.size = 500;
  this->eventBasedAchievementStamps.granularity = 1;
  this->eventBasedAchievementStamps.list = this->eventBasedAchievementStamps.staticList;
  this->eventBasedAchievementStamps.memTag = 5;
  this->eventBasedAchievementStamps.listStatic = 1;
  p_eventBasedAchievementIndexer = (idList<idSpawnArea::GeneratedPosition *,5> *)&this->eventBasedAchievementIndexer;
  this->eventBasedAchievementIndexer.size = 500;
  this->eventBasedAchievementIndexer.num = 0;
  this->eventBasedAchievementIndexer.granularity = 1;
  this->eventBasedAchievementIndexer.list = this->eventBasedAchievementIndexer.staticList;
  this->eventBasedAchievementIndexer.memTag = 5;
  this->eventBasedAchievementIndexer.listStatic = 1;
  p_eventBasedAchievementValues = (idList<idSpawnArea::GeneratedPosition *,5> *)&this->eventBasedAchievementValues;
  this->eventBasedAchievementValues.size = 500;
  this->eventBasedAchievementValues.num = 0;
  this->eventBasedAchievementValues.granularity = 1;
  this->eventBasedAchievementValues.list = this->eventBasedAchievementValues.staticList;
  this->eventBasedAchievementValues.memTag = 5;
  this->eventBasedAchievementValues.listStatic = 1;
  if ( this->eventBasedAchievementStamps.size >= 256
    || idList<idBackgroundLoader::bgrEntry_t,101>::Resize(this: p_eventBasedAchievementStamps, newsize: 256) )
  {
    size = p_eventBasedAchievementStamps->size;
    if ( size > 256 )
      size = 256;
    p_eventBasedAchievementStamps->num = size;
  }
  if ( p_eventBasedAchievementValues->size >= 256
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_eventBasedAchievementValues, newsize: 256) != 0 )
  {
    v6 = p_eventBasedAchievementValues->size;
    if ( v6 > 256 )
      v6 = 256;
    p_eventBasedAchievementValues->num = v6;
  }
  if ( p_eventBasedAchievementIndexer->size >= 256
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_eventBasedAchievementIndexer, newsize: 256) != 0 )
  {
    v7 = p_eventBasedAchievementIndexer->size;
    if ( v7 > 256 )
      v7 = 256;
    p_eventBasedAchievementIndexer->num = v7;
  }
  memset(Dst: p_eventBasedAchievementStamps->list, Val: 0, Size: 8 * p_eventBasedAchievementStamps->size);
  memset(Dst: p_eventBasedAchievementValues->list, Val: 0, Size: 4 * p_eventBasedAchievementValues->size);
  memset(Dst: p_eventBasedAchievementIndexer->list, Val: 0, Size: 4 * p_eventBasedAchievementIndexer->size);
  return this;
}


// ========================================================================
// __unwind$490297
// EA  : 0x82DF1344
// RVA : 0x00DF1344
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_490297()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$490298
// EA  : 0x82DF136C
// RVA : 0x00DF136C
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_490298()
{
  int v0; // r12

  idList<idAchievement,5>::Clear(this: (idList<idAchievement,5> *)(*(_DWORD *)(v0 - 144 + 164) + 8));
}


// ========================================================================
// __unwind$490299
// EA  : 0x82DF1398
// RVA : 0x00DF1398
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_490299()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 32));
}


// ========================================================================
// __unwind$490300
// EA  : 0x82DF13C4
// RVA : 0x00DF13C4
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_490300()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 4048));
}


// ========================================================================
// __unwind$490301
// EA  : 0x82DF13F0
// RVA : 0x00DF13F0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_490301()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 6064));
}


// ========================================================================
// ?Init@idAchievementManager@@QAAXPAVidPlayer@@@Z
// EA  : 0x82DF15B0
// RVA : 0x00DF15B0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievementManager::Init(idAchievementManager *this, idPlayer *player)
{
  __int64 v2; // r21
  idLocalUser *LocalUserFromPlayerIndex; // r22
  idList<idAchievement,5> *p_achievements; // r29
  int num; // r30
  int size; // r11
  int v9; // r19
  int v10; // r30
  idAchievement *v11; // r3
  bool v12; // r8
  idAchievement *v13; // r3
  bool v14; // r5
  idAchievement *v15; // r3
  bool v16; // r10
  idAchievement *v17; // r3
  bool v18; // r7
  idAchievement *v19; // r3
  bool v20; // r4
  idAchievement *v21; // r3
  int id; // r28
  idPlayerProfile *v23; // r3
  int v24; // r26
  int v25; // r27
  int v26; // r9
  int stat; // r28
  unsigned __int64 v28; // r7
  int StatInt; // r3
  idAchievement *v30; // r10
  const idDeclAchievement *decl; // r11
  int v32; // r8
  int v33; // r9
  idDeclAchievement::statConstraint_t *list; // r7
  int v35; // r11
  unsigned __int64 *v36; // r10

  this->owner = player;
  HIDWORD(v2) = &ai_useTurnTransitions.valueString.baseBuffer[12];
  LocalUserFromPlayerIndex = idClientGame::GetLocalUserFromPlayerIndex(this: clientGame, index: player->entityNumber);
  idDeclAchievement::LoadAllDecls();
  p_achievements = &this->achievements;
  num = idDeclAchievement::resourceList.num;
  if ( idDeclAchievement::resourceList.num <= this->achievements.size
    || (unsigned __int8)idList<idAchievement,5>::Resize(
                          this: &this->achievements,
                          newsize: idDeclAchievement::resourceList.num) != 0 )
  {
    size = this->achievements.size;
    if ( num < size )
      size = num;
    this->achievements.num = size;
  }
  v9 = 0;
  if ( idDeclAchievement::resourceList.num > 0 )
  {
    v10 = 0;
    LODWORD(v2) = 1;
    do
    {
      p_achievements->list[v10].decl = (const idDeclAchievement *)idResourceList::Index(
                                                                    this: &idDeclAchievement::resourceList,
                                                                    index: v9);
      v11 = &p_achievements->list[v10];
      if ( v11->decl != nullptr )
      {
        this->needsUpdate = true;
        v12 = idAchievement::CheckJobRequirements(this: v11, player) & this->needsUpdate;
        v13 = &p_achievements->list[v10];
        this->needsUpdate = v12;
        v14 = idAchievement::CheckInventoryRequirements(this: v13, player) & this->needsUpdate;
        v15 = &p_achievements->list[v10];
        this->needsUpdate = v14;
        v16 = idAchievement::CheckTriggerRequirements(this: v15) & this->needsUpdate;
        v17 = &p_achievements->list[v10];
        this->needsUpdate = v16;
        v18 = idAchievement::CheckAchievementRequirements(this: v17) & this->needsUpdate;
        v19 = &p_achievements->list[v10];
        this->needsUpdate = v18;
        v20 = idAchievement::CheckEventRequirements(this: v19) & this->needsUpdate;
        v21 = &p_achievements->list[v10];
        this->needsUpdate = v20;
        this->needsUpdate &= idAchievement::CheckRaceRequirements(this: v21);
        if ( LocalUserFromPlayerIndex != nullptr
          && LocalUserFromPlayerIndex->GetProfile(this: LocalUserFromPlayerIndex) != nullptr )
        {
          id = p_achievements->list[v10].decl->id;
          v23 = LocalUserFromPlayerIndex->GetProfile(this: LocalUserFromPlayerIndex);
          this->needsUpdate &= (_cntlzw((unsigned __int8)idPlayerProfile::GetAchievement(this: v23, id)) & 0x20) != 0;
        }
        v24 = 0;
        if ( p_achievements->list[v10].decl->events.num > 0 )
        {
          v25 = 0;
          v26 = (unsigned __int64)(v2 << v9) >> 32;
          do
          {
            stat = p_achievements->list[v10].decl->events.list[v25].stat;
            StatInt = idRageMetrics::GetStatInt(
                        this: *(idRageMetrics **)((char *)&clientGame->random.seed + v26),
                        player,
                        stat);
            v30 = &p_achievements->list[v10];
            if ( !v30->eventsFulfilled )
            {
              decl = v30->decl;
              v32 = decl->events.num;
              if ( v32 != 0 )
              {
                v33 = 0;
                if ( v32 > 0 )
                {
                  list = decl->events.list;
                  v35 = 0;
                  while ( 1 )
                  {
                    HIDWORD(v28) = list[v35].stat;
                    if ( HIDWORD(v28) == stat )
                      break;
                    ++v33;
                    ++v35;
                    if ( v33 >= v32 )
                      goto LABEL_22;
                  }
                  v30->eventInfo[v33].count += StatInt;
                }
              }
            }
LABEL_22:
            v36 = this->eventBasedAchievementStamps.list;
            ++v24;
            ++v25;
            v26 = (unsigned __int64)(v2 << v9) >> 32;
            LODWORD(v28) = (v2 << v9) | LODWORD(v36[stat]);
            v36[stat] = v28;
          }
          while ( v24 < p_achievements->list[v10].decl->events.num );
        }
      }
      ++v9;
      ++v10;
    }
    while ( v9 < idDeclAchievement::resourceList.num );
  }
}


// ========================================================================
// ?EventCompletesAchievement@idAchievementManager@@QAAXW4rageStat_t@@H@Z
// EA  : 0x82DF18A0
// RVA : 0x00DF18A0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievementManager::EventCompletesAchievement(
        idAchievementManager *this,
        rageStat_t eventId,
        const int count)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r10
  rageStat_t v9; // [sp+50h] [-50h] BYREF
  idPLogScope v10[9]; // [sp+58h] [-48h] BYREF

  RD_EventBegin(name: "idAchievementManager::EventCompletesAchievement");
  LODWORD(v6) = "idAchievementManager::EventCompletesAchievement";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v6, label: v7);
  if ( achievements_awardEnabled.valueInteger != 0 )
  {
    v9 = eventId;
    v8 = this->eventBasedAchievementIndexer.list[idList<int,46>::AddUnique(
                                                   this: &this->eventBasedAchievementIndexer,
                                                   obj: (const encounterGroupRole_t *)&v9)];
    this->eventBasedAchievementValues.list[v8] += count;
  }
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
}


// ========================================================================
// __unwind$490774_0
// EA  : 0x82DF1948
// RVA : 0x00DF1948
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_490774_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$490775_0
// EA  : 0x82DF1970
// RVA : 0x00DF1970
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_490775_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?AchievementCompletesAchievement@idAchievementManager@@QAA_NW4achievementId_t@@@Z
// EA  : 0x82DF19A0
// RVA : 0x00DF19A0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievementManager::AchievementCompletesAchievement(
        idAchievementManager *this,
        achievementId_t achievementId)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int v7; // r25
  int v8; // r27
  int v9; // r29
  idAchievement *v10; // r3
  idAchievement *v11; // r28
  idPLog *pLog; // r29
  idPLog::logEntry_t *v13; // r30
  int v14; // r3
  __int64 totalTicks; // r11
  __int64 v16; // r9
  idPLogScope v17[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idAchievementManager::AchievementCompletesAchievement");
  LODWORD(v4) = "idAchievementManager::AchievementCompletesAchievement";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v17, pl: &::pLog, gMask: v4, label: v5);
  if ( achievements_awardEnabled.valueInteger != 0 )
  {
    v7 = 0;
    v8 = 0;
    if ( this->achievements.num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = &this->achievements.list[v9];
        if ( !v10->achievementsFulfilled && v10->decl->achievements.num > 0 )
        {
          idAchievement::SetAchievementGained(this: v10, achievementId);
          if ( (unsigned __int8)idAchievement::CheckAchievementRequirements(this: &this->achievements.list[v9]) != 0 )
          {
            v11 = &this->achievements.list[v9];
            if ( (unsigned __int8)idAchievement::IsFulfilled(this: v11) != 0 )
            {
              idAchievementManager::AwardAchievement(this, achievement: v11->decl);
              v7 = 1;
            }
          }
        }
        ++v8;
        ++v9;
      }
      while ( v8 < this->achievements.num );
    }
    if ( v17[0].logIndex >= 0 )
    {
      pLog = v17[0].pLog;
      v13 = &v17[0].pLog->logEntries.list[v17[0].logIndex];
      v14 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v13->totalTicks;
      HIDWORD(totalTicks) = v13->parent;
      LODWORD(v16) = v14 - totalTicks;
      v13->totalTicks = v16;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    return v7;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v17);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$490821
// EA  : 0x82DF1AE8
// RVA : 0x00DF1AE8
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_490821()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$490822
// EA  : 0x82DF1B10
// RVA : 0x00DF1B10
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_490822()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?AwardAchievement@idAchievementManager@@QAAXPBVidDeclAchievement@@@Z
// EA  : 0x82DF1B38
// RVA : 0x00DF1B38
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievementManager::AwardAchievement(
        idAchievementManager *this,
        const idDeclAchievement *achievement)
{
  idPlayer *owner; // r11
  idLocalUser *LocalUserFromPlayerIndex; // r3
  idLocalUser *v6; // r30
  idGame *v7; // r3
  const char *v8; // r4
  char v9; // r11
  achievementId_t id; // r31
  idPlayerProfile *v11; // r3

  if ( g_demoMode.valueInteger == 0 )
  {
    idLib::PrintfIf(
      condition: achievements_Verbose.valueInteger != 0,
      fmt: "AwardAchievement called: %s\n",
      achievement->name.str);
    if ( common != nullptr )
    {
      owner = this->owner;
      if ( owner != nullptr && session != nullptr )
      {
        LocalUserFromPlayerIndex = idClientGame::GetLocalUserFromPlayerIndex(
                                     this: clientGame,
                                     index: owner->entityNumber);
        v6 = LocalUserFromPlayerIndex;
        if ( LocalUserFromPlayerIndex != nullptr
          && LocalUserFromPlayerIndex->GetProfile(this: LocalUserFromPlayerIndex) != nullptr )
        {
          v7 = common->Game(this: common);
          v8 = v7->GetMapName(this: v7);
          if ( v8 != nullptr
            && idDeclInfo::FindWithInheritance(this: &idDeclMapInfo::resourceList, name: v8, makeDefault: false) != nullptr
            || (v9 = 0, profileSecurityCheck.valueInteger == 0) )
          {
            v9 = 1;
          }
          if ( v9 != 0 )
          {
            id = achievement->id;
            v11 = (idPlayerProfile *)((int (__fastcall *)(idLocalUser *, const char *))v6->GetProfile)(a1: v6, a2: v8);
            if ( (unsigned __int8)idPlayerProfile::GetAchievement(this: v11, id) == 0 )
            {
              idLib::PrintfIf(
                condition: achievements_Verbose.valueInteger != 0,
                fmt: "Unlocking achievement from AwardAchievement: %s\n",
                achievement->name.str);
              session->achievementSystem->AchievementUnlock(this: session->achievementSystem, a2: v6, a3: id);
              this->needsUpdate = true;
            }
            idAchievementManager::AchievementCompletesAchievement(this, achievementId: id);
          }
        }
      }
    }
  }
}


// ========================================================================
// ?CheckAllAchievements@idAchievementManager@@QAAXXZ
// EA  : 0x82DF1CD8
// RVA : 0x00DF1CD8
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievementManager::CheckAllAchievements(idAchievementManager *this)
{
  int v2; // r29
  int v3; // r30
  idAchievement *v4; // r11
  char v5; // r10

  v2 = 0;
  if ( this->achievements.num > 0 )
  {
    v3 = 0;
    do
    {
      if ( (unsigned __int8)idAchievement::CheckAllRequirements(this: &this->achievements.list[v3], player: this->owner) != 0 )
      {
        v4 = &this->achievements.list[v3];
        if ( !v4->itemsFulfilled
          || !v4->jobsFulfilled
          || !v4->triggersFulfilled
          || !v4->achievementsFulfilled
          || !v4->eventsFulfilled
          || (v5 = 1, !v4->racesFulfilled) )
        {
          v5 = 0;
        }
        if ( v5 != 0 )
        {
          idAchievementManager::AwardAchievement(this, achievement: v4->decl);
          this->needsUpdate = true;
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->achievements.num );
  }
}


// ========================================================================
// ?ItemCompletesAchievement@idAchievementManager@@QAA_NXZ
// EA  : 0x82DF1DB8
// RVA : 0x00DF1DB8
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievementManager::ItemCompletesAchievement(idAchievementManager *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v5; // r26
  int v6; // r27
  int v7; // r28
  idAchievement *v8; // r3
  idAchievement *v9; // r29
  idPLog *pLog; // r29
  idPLog::logEntry_t *v11; // r30
  int v12; // r3
  __int64 totalTicks; // r11
  __int64 v14; // r9
  idPLogScope v15[9]; // [sp+58h] [-48h] BYREF

  RD_EventBegin(name: "idAchievementManager::ItemCompletesAchievement");
  LODWORD(v2) = "idAchievementManager::ItemCompletesAchievement";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v15, pl: &::pLog, gMask: v2, label: v3);
  if ( achievements_awardEnabled.valueInteger != 0 )
  {
    v5 = 0;
    v6 = 0;
    if ( this->achievements.num > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &this->achievements.list[v7];
        if ( !v8->itemsFulfilled
          && v8->decl->item.num > 0
          && (unsigned __int8)idAchievement::CheckInventoryRequirements(this: v8, player: this->owner) != 0 )
        {
          v9 = &this->achievements.list[v7];
          if ( (unsigned __int8)idAchievement::IsFulfilled(this: v9) != 0 )
          {
            idAchievementManager::AwardAchievement(this, achievement: v9->decl);
            v5 = 1;
          }
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->achievements.num );
    }
    if ( v15[0].logIndex >= 0 )
    {
      pLog = v15[0].pLog;
      v11 = &v15[0].pLog->logEntries.list[v15[0].logIndex];
      v12 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v11->totalTicks;
      HIDWORD(totalTicks) = v11->parent;
      LODWORD(v14) = v12 - totalTicks;
      v11->totalTicks = v14;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    return v5;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v15);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$491044
// EA  : 0x82DF1EF4
// RVA : 0x00DF1EF4
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491044()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$491045
// EA  : 0x82DF1F1C
// RVA : 0x00DF1F1C
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491045()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?JobCompletesAchievement@idAchievementManager@@QAA_NXZ
// EA  : 0x82DF1F50
// RVA : 0x00DF1F50
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievementManager::JobCompletesAchievement(idAchievementManager *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v5; // r26
  int v6; // r27
  int v7; // r28
  idAchievement *v8; // r3
  idAchievement *v9; // r29
  idPLog *pLog; // r29
  idPLog::logEntry_t *v11; // r30
  int v12; // r3
  __int64 totalTicks; // r11
  __int64 v14; // r9
  idPLogScope v15[9]; // [sp+58h] [-48h] BYREF

  RD_EventBegin(name: "idAchievementManager::JobCompletesAchievement");
  LODWORD(v2) = "idAchievementManager::JobCompletesAchievement";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v15, pl: &::pLog, gMask: v2, label: v3);
  if ( achievements_awardEnabled.valueInteger != 0 )
  {
    v5 = 0;
    v6 = 0;
    if ( this->achievements.num > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &this->achievements.list[v7];
        if ( !v8->jobsFulfilled
          && v8->decl->jobDecl.num > 0
          && (unsigned __int8)idAchievement::CheckJobRequirements(this: v8, player: this->owner) != 0 )
        {
          v9 = &this->achievements.list[v7];
          if ( (unsigned __int8)idAchievement::IsFulfilled(this: v9) != 0 )
          {
            idAchievementManager::AwardAchievement(this, achievement: v9->decl);
            v5 = 1;
          }
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->achievements.num );
    }
    if ( v15[0].logIndex >= 0 )
    {
      pLog = v15[0].pLog;
      v11 = &v15[0].pLog->logEntries.list[v15[0].logIndex];
      v12 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v11->totalTicks;
      HIDWORD(totalTicks) = v11->parent;
      LODWORD(v14) = v12 - totalTicks;
      v11->totalTicks = v14;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    return v5;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v15);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$491120_1
// EA  : 0x82DF208C
// RVA : 0x00DF208C
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491120_1()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$491121_1
// EA  : 0x82DF20B4
// RVA : 0x00DF20B4
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491121_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?TriggerCompletesAchievement@idAchievementManager@@QAA_NW4triggerAchievementId_t@@@Z
// EA  : 0x82DF20E8
// RVA : 0x00DF20E8
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievementManager::TriggerCompletesAchievement(
        idAchievementManager *this,
        triggerAchievementId_t taid)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int v7; // r25
  int v8; // r27
  int v9; // r29
  idAchievement *v10; // r3
  idAchievement *v11; // r28
  idPLog *pLog; // r29
  idPLog::logEntry_t *v13; // r30
  int v14; // r3
  __int64 totalTicks; // r11
  __int64 v16; // r9
  idPLogScope v17[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idAchievementManager::TriggerCompletesAchievement");
  LODWORD(v4) = "idAchievementManager::TriggerCompletesAchievement";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v17, pl: &::pLog, gMask: v4, label: v5);
  if ( achievements_awardEnabled.valueInteger != 0 )
  {
    v7 = 0;
    v8 = 0;
    if ( this->achievements.num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = &this->achievements.list[v9];
        if ( !v10->triggersFulfilled && v10->decl->trigger.num > 0 )
        {
          idAchievement::SetTriggered(this: v10, taid);
          if ( (unsigned __int8)idAchievement::CheckTriggerRequirements(this: &this->achievements.list[v9]) != 0 )
          {
            v11 = &this->achievements.list[v9];
            if ( (unsigned __int8)idAchievement::IsFulfilled(this: v11) != 0 )
            {
              idAchievementManager::AwardAchievement(this, achievement: v11->decl);
              v7 = 1;
            }
          }
        }
        ++v8;
        ++v9;
      }
      while ( v8 < this->achievements.num );
    }
    if ( v17[0].logIndex >= 0 )
    {
      pLog = v17[0].pLog;
      v13 = &v17[0].pLog->logEntries.list[v17[0].logIndex];
      v14 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v13->totalTicks;
      HIDWORD(totalTicks) = v13->parent;
      LODWORD(v16) = v14 - totalTicks;
      v13->totalTicks = v16;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    return v7;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v17);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$491196_0
// EA  : 0x82DF2230
// RVA : 0x00DF2230
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491196_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$491197_0
// EA  : 0x82DF2258
// RVA : 0x00DF2258
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491197_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?CheckAllEventsCompletesAchievement@idAchievementManager@@AAAXXZ
// EA  : 0x82DF2288
// RVA : 0x00DF2288
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievementManager::CheckAllEventsCompletesAchievement(idAchievementManager *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v4; // r24
  int v5; // r25
  int v6; // r28
  unsigned __int64 v7; // r27
  int v8; // r29
  idAchievement *v9; // r8
  int v10; // r11
  const idDeclAchievement *decl; // r7
  int v12; // r10
  idAchievement *v13; // r11
  char v14; // r10
  idPLog *pLog; // r29
  idPLog::logEntry_t *v16; // r30
  int v17; // r3
  __int64 totalTicks; // r11
  __int64 v19; // r9
  int num; // [sp+50h] [-60h]
  idPLogScope v21[11]; // [sp+58h] [-58h] BYREF

  RD_EventBegin(name: "idAchievementManager::CheckAllEventsCompletesAchievement");
  LODWORD(v2) = "idAchievementManager::CheckAllEventsCompletesAchievement";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v21, pl: &::pLog, gMask: v2, label: v3);
  if ( achievements_awardEnabled.valueInteger != 0 )
  {
    v4 = 0;
    if ( this->eventBasedAchievementIndexer.num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = this->eventBasedAchievementIndexer.list[v5];
        v7 = this->eventBasedAchievementStamps.list[v6];
        HIDWORD(v7) = this->eventBasedAchievementValues.list[v6];
        if ( (_DWORD)v7 != 0 )
        {
          v8 = 0;
          do
          {
            if ( (v7 & 1) != 0 )
            {
              v9 = &this->achievements.list[v8];
              if ( !v9->eventsFulfilled )
              {
                v10 = 0;
                decl = v9->decl;
                num = decl->events.num;
                if ( num != 0 )
                {
                  v12 = 0;
                  if ( num > 0 )
                  {
                    while ( decl->events.list[v10].stat != v6 )
                    {
                      ++v12;
                      ++v10;
                      if ( v12 >= num )
                        goto LABEL_15;
                    }
                    v9->eventInfo[v12].count += HIDWORD(v7);
                  }
                }
LABEL_15:
                if ( (unsigned __int8)idAchievement::CheckEventRequirements(this: &this->achievements.list[v8]) != 0 )
                {
                  v13 = &this->achievements.list[v8];
                  if ( !v13->itemsFulfilled
                    || !v13->jobsFulfilled
                    || !v13->triggersFulfilled
                    || !v13->achievementsFulfilled
                    || !v13->eventsFulfilled
                    || (v14 = 1, !v13->racesFulfilled) )
                  {
                    v14 = 0;
                  }
                  if ( v14 != 0 )
                    idAchievementManager::AwardAchievement(this, achievement: v13->decl);
                }
              }
            }
            v7 >>= 1;
            ++v8;
          }
          while ( (_DWORD)v7 != 0 );
        }
        ++v4;
        ++v5;
      }
      while ( v4 < this->eventBasedAchievementIndexer.num );
    }
    if ( v21[0].logIndex >= 0 )
    {
      pLog = v21[0].pLog;
      v16 = &v21[0].pLog->logEntries.list[v21[0].logIndex];
      v17 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v16->totalTicks;
      HIDWORD(totalTicks) = v16->parent;
      LODWORD(v19) = v17 - totalTicks;
      v16->totalTicks = v19;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: v21);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$491273
// EA  : 0x82DF2494
// RVA : 0x00DF2494
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491273()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$491274_0
// EA  : 0x82DF24BC
// RVA : 0x00DF24BC
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491274_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?RaceCompletesAchievement@idAchievementManager@@QAA_NPBDW4raceMemoryPlace_t@@@Z
// EA  : 0x82DF24F0
// RVA : 0x00DF24F0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

int __fastcall idAchievementManager::RaceCompletesAchievement(
        idAchievementManager *this,
        const char *raceName,
        raceMemoryPlace_t place)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v9; // r24
  int v10; // r27
  int v11; // r29
  idAchievement *v12; // r11
  idAchievement *v13; // r28
  idPLog *pLog; // r29
  idPLog::logEntry_t *v15; // r30
  int v16; // r3
  __int64 totalTicks; // r11
  __int64 v18; // r9
  idPLogScope v19[2]; // [sp+50h] [-80h] BYREF
  idStr v20[3]; // [sp+60h] [-70h] BYREF

  RD_EventBegin(name: "idAchievementManager::RaceCompletesAchievement");
  LODWORD(v6) = "idAchievementManager::RaceCompletesAchievement";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v19, pl: &::pLog, gMask: v6, label: v7);
  if ( achievements_awardEnabled.valueInteger != 0 )
  {
    v9 = 0;
    v10 = 0;
    if ( this->achievements.num > 0 )
    {
      v11 = 0;
      do
      {
        v12 = &this->achievements.list[v11];
        if ( !v12->racesFulfilled && v12->decl->races.num > 0 )
        {
          idStr::idStr(this: v20, text: raceName);
          idAchievement::SetRacePlace(this: &this->achievements.list[v11], raceName: v20, place);
          idStr::FreeData(this: v20);
          if ( (unsigned __int8)idAchievement::CheckRaceRequirements(this: &this->achievements.list[v11]) != 0 )
          {
            v13 = &this->achievements.list[v11];
            if ( (unsigned __int8)idAchievement::IsFulfilled(this: v13) != 0 )
            {
              idAchievementManager::AwardAchievement(this, achievement: v13->decl);
              v9 = 1;
            }
          }
        }
        ++v10;
        ++v11;
      }
      while ( v10 < this->achievements.num );
    }
    if ( v19[0].logIndex >= 0 )
    {
      pLog = v19[0].pLog;
      v15 = &v19[0].pLog->logEntries.list[v19[0].logIndex];
      v16 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v15->totalTicks;
      HIDWORD(totalTicks) = v15->parent;
      LODWORD(v18) = v16 - totalTicks;
      v15->totalTicks = v18;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    return v9;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v19);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$491397
// EA  : 0x82DF265C
// RVA : 0x00DF265C
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491397()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 128));
}


// ========================================================================
// __unwind$491398
// EA  : 0x82DF2684
// RVA : 0x00DF2684
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491398()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$491399_0
// EA  : 0x82DF26AC
// RVA : 0x00DF26AC
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491399_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?Update@idAchievementManager@@QAAXXZ
// EA  : 0x82DF26D8
// RVA : 0x00DF26D8
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievementManager::Update(idAchievementManager *this)
{
  int v2; // r10
  int v3; // r11
  int v4; // r7
  int *list; // r4

  idAchievementManager::CheckAllEventsCompletesAchievement(this);
  v2 = 0;
  if ( this->eventBasedAchievementIndexer.num > 0 )
  {
    v3 = 0;
    do
    {
      ++v2;
      v4 = this->eventBasedAchievementIndexer.list[v3++];
      this->eventBasedAchievementValues.list[v4] = 0;
    }
    while ( v2 < this->eventBasedAchievementIndexer.num );
  }
  if ( this->eventBasedAchievementIndexer.listStatic == 0 || this->eventBasedAchievementIndexer.listStatic == 2 )
  {
    list = this->eventBasedAchievementIndexer.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->eventBasedAchievementIndexer.list = nullptr;
    this->eventBasedAchievementIndexer.size = 0;
  }
  this->eventBasedAchievementIndexer.num = 0;
  if ( this->needsUpdate )
    this->needsUpdate = false;
}


// ========================================================================
// ?ResetLifetimeStats@idAchievementManager@@QAAXXZ
// EA  : 0x82DF27A0
// RVA : 0x00DF27A0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __fastcall idAchievementManager::ResetLifetimeStats(idAchievementManager *this)
{
  idLocalUser *LocalUser; // r26
  int v3; // r24
  int v4; // r25
  int v5; // r29
  idAchievement *v6; // r11
  const idDeclAchievement *decl; // r28
  int v8; // r30
  bool *v9; // r27
  int v10; // r22
  idPLog::logEntry_t *v11; // r28
  __int64 v12; // r3
  idPLog::logEntry_t *v13; // r30
  int v14; // r3
  int v15; // r11
  __int64 v16; // r9
  int v17; // r24
  int v18; // r25
  int v19; // r29
  unsigned __int64 v20; // r28
  int v21; // r30
  idAchievement *v22; // r8
  int v23; // r11
  const idDeclAchievement *v24; // r7
  int v25; // r10
  idAchievement *v26; // r11
  char v27; // r10
  idPLog::logEntry_t *v28; // r30
  int v29; // r3
  int parent; // r11
  __int64 v31; // r9
  int num; // [sp+50h] [-70h]

  LocalUser = idPlayer::GetLocalUser(this: this->owner);
  if ( LocalUser != nullptr )
  {
    v3 = 0;
    if ( this->achievements.num > 0 )
    {
      v4 = 0;
      do
      {
        v5 = 0;
        v6 = &this->achievements.list[v4];
        decl = v6->decl;
        if ( decl->events.num > 0 )
        {
          v8 = 0;
          v9 = &v6->achievementsGained[48];
          do
          {
            ++v5;
            v9 += 4;
            *(_DWORD *)v9 = LocalUser->GetStatInt(this: LocalUser, a2: decl->events.list[v8++].stat);
          }
          while ( v5 < decl->events.num );
        }
        ++v3;
        ++v4;
      }
      while ( v3 < this->achievements.num );
    }
    RD_EventBegin(name: "idAchievementManager::CheckAllEventsCompletesAchievement");
    v10 = -1;
    if ( (pLog.groupMask & 2) != 0 )
    {
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      v11 = idList<idPLog::logEntry_t,44>::Alloc(this: &pLog.logEntries);
      idMem::PopHeap(this: &mem);
      v11->label = "idAchievementManager::CheckAllEventsCompletesAchievement";
      v11->parent = pLog.lastEntry;
      v10 = pLog.logEntries.num - 1;
      pLog.lastEntry = pLog.logEntries.num - 1;
      LODWORD(v12) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v11->totalTicks = v12;
    }
    if ( achievements_awardEnabled.valueInteger != 0 )
    {
      v17 = 0;
      if ( this->eventBasedAchievementIndexer.num > 0 )
      {
        v18 = 0;
        do
        {
          v19 = this->eventBasedAchievementIndexer.list[v18];
          v20 = this->eventBasedAchievementStamps.list[v19];
          HIDWORD(v20) = this->eventBasedAchievementValues.list[v19];
          if ( (_DWORD)v20 != 0 )
          {
            v21 = 0;
            do
            {
              if ( (v20 & 1) != 0 )
              {
                v22 = &this->achievements.list[v21];
                if ( !v22->eventsFulfilled )
                {
                  v23 = 0;
                  v24 = v22->decl;
                  num = v24->events.num;
                  if ( num != 0 )
                  {
                    v25 = 0;
                    if ( num > 0 )
                    {
                      while ( v24->events.list[v23].stat != v19 )
                      {
                        ++v25;
                        ++v23;
                        if ( v25 >= num )
                          goto LABEL_26;
                      }
                      v22->eventInfo[v25].count += HIDWORD(v20);
                    }
                  }
LABEL_26:
                  if ( (unsigned __int8)idAchievement::CheckEventRequirements(this: &this->achievements.list[v21]) != 0 )
                  {
                    v26 = &this->achievements.list[v21];
                    if ( !v26->itemsFulfilled
                      || !v26->jobsFulfilled
                      || !v26->triggersFulfilled
                      || !v26->achievementsFulfilled
                      || !v26->eventsFulfilled
                      || (v27 = 1, !v26->racesFulfilled) )
                    {
                      v27 = 0;
                    }
                    if ( v27 != 0 )
                      idAchievementManager::AwardAchievement(this, achievement: v26->decl);
                  }
                }
              }
              v20 >>= 1;
              ++v21;
            }
            while ( (_DWORD)v20 != 0 );
          }
          ++v17;
          ++v18;
        }
        while ( v17 < this->eventBasedAchievementIndexer.num );
      }
      if ( v10 >= 0 )
      {
        v28 = &pLog.logEntries.list[v10];
        v29 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        parent = v28->parent;
        LODWORD(v31) = v29 - LODWORD(v28->totalTicks);
        v28->totalTicks = v31;
        pLog.lastEntry = parent;
      }
    }
    else if ( v10 >= 0 )
    {
      v13 = &pLog.logEntries.list[v10];
      v14 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v15 = v13->parent;
      LODWORD(v16) = v14 - LODWORD(v13->totalTicks);
      v13->totalTicks = v16;
      pLog.lastEntry = v15;
    }
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$491542_0
// EA  : 0x82DF2AB4
// RVA : 0x00DF2AB4
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491542_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$491543_0
// EA  : 0x82DF2ADC
// RVA : 0x00DF2ADC
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void _unwind_491543_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// `dynamic initializer for 'achievements_awardEnabled''
// EA  : 0x833860C0
// RVA : 0x013860C0
// PDB : w:\tech5\tungsten\game\player\achievements.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__achievements_awardEnabled__()
{
  idCVar::idCVar(
    this: &achievements_awardEnabled,
    name: "achievements_awardEnabled",
    value: "1",
    flags: 1,
    description: "should achievements be awarded",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__achievements_awardEnabled__);
}

