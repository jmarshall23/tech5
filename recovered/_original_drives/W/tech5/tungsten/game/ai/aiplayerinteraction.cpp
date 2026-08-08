
// ========================================================================
// ?Init@idAIPlayerInteraction@@QAA_NPBVidAnimatedEntity@@PBVidDeclAIPlayerInteraction@@@Z
// EA  : 0x82A5FBB8
// RVA : 0x00A5FBB8
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

int __fastcall idAIPlayerInteraction::Init(
        idAIPlayerInteraction *this,
        const idAnimatedEntity *_owner,
        const idDeclAIPlayerInteraction *_decl)
{
  this->owner = _owner;
  this->decl = _decl;
  return 1;
}


// ========================================================================
// ??0idAIPlayerInteraction@@QAA@XZ
// EA  : 0x82A5FBD0
// RVA : 0x00A5FBD0
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

idAIPlayerInteraction *__fastcall idAIPlayerInteraction::idAIPlayerInteraction(idAIPlayerInteraction *this)
{
  this->decl = nullptr;
  this->__vftable = (idAIPlayerInteraction_vtbl *)&idAIPlayerInteraction::`vftable';
  this->owner = nullptr;
  return this;
}


// ========================================================================
// ?GetInteraction@idAIPlayerInteraction@@QBAPBVaiPlayerInteraction_t@@H@Z
// EA  : 0x82A5FBF0
// RVA : 0x00A5FBF0
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

const aiPlayerInteraction_t *__fastcall idAIPlayerInteraction::GetInteraction(idAIPlayerInteraction *this, int index)
{
  return &this->decl->interactList.list[index];
}


// ========================================================================
// ?GetInteractionIndex@idAIPlayerInteraction@@QBAHPBVaiPlayerInteraction_t@@@Z
// EA  : 0x82A5FC08
// RVA : 0x00A5FC08
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

int __fastcall idAIPlayerInteraction::GetInteractionIndex(
        idAIPlayerInteraction *this,
        const aiPlayerInteraction_t *interaction)
{
  return interaction - this->decl->interactList.list;
}


// ========================================================================
// ?AnyInteractionConditionMet@idAIPlayerInteraction@@QBA_NABV?$idList@VinteractionTestCondition_t@aiPlayerInteraction_t@@$04@@PBVidPlayer@@_N@Z
// EA  : 0x82A5FC28
// RVA : 0x00A5FC28
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

int __fastcall idAIPlayerInteraction::AnyInteractionConditionMet(
        idAIPlayerInteraction *this,
        const idList<aiPlayerInteraction_t::interactionTestCondition_t,5> *condition,
        const idPlayer *player,
        int passOnEmpty)
{
  idJobManager *p_jobManager; // r24
  int v8; // r25
  int i; // r27
  aiPlayerInteraction_t::interactionTestCondition_t *v10; // r30
  const idDeclInventory *inventoryDecl; // r10
  const idDeclGameStateInt *gameStateIntDecl; // r4
  idJob *InventoryItemByDeclName; // r3
  const idDeclJob *v14; // r30
  idJobManager *v15; // r3
  idJob *JobByDecl; // r3
  int v17; // r3
  int GameStateIntValue; // r3
  int v20; // r3
  missionStatus_t status; // [sp+50h] [-A0h]
  missionStatus_t v22; // [sp+50h] [-A0h]
  aiPlayerInteraction_t::interactionTestConditionType_t v23; // [sp+60h] [-90h]
  idStr v24; // [sp+64h] [-8Ch] BYREF
  aiPlayerInteraction_t::interactionTestJobStatus_t jobStatus; // [sp+84h] [-6Ch]
  const idDeclInventory *v26; // [sp+88h] [-68h]
  const idDeclGameStateInt *v27; // [sp+8Ch] [-64h]
  int count; // [sp+90h] [-60h]

  p_jobManager = &player->jobManager;
  v8 = 0;
  if ( condition->num <= 0 )
    return passOnEmpty;
  for ( i = 0; ; ++i )
  {
    v10 = &condition->list[i];
    v23 = v10->condition;
    idStr::idStr(this: &v24, text: &v10->jobDecl);
    jobStatus = v10->jobStatus;
    inventoryDecl = v10->inventoryDecl;
    v26 = inventoryDecl;
    gameStateIntDecl = v10->gameStateIntDecl;
    v27 = gameStateIntDecl;
    count = v10->count;
    if ( v23 == INTERACTIONCONDITION_JOB )
    {
      InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                  this: p_jobManager,
                                  jobName: v24.data);
      if ( InventoryItemByDeclName != nullptr )
      {
        switch ( jobStatus )
        {
          case INTERACTIONTEST_JOBSTATUS_COMPLETED:
            if ( InventoryItemByDeclName->status == JOBSTATUS_COMPLETED )
              goto LABEL_43;
            break;
          case INTERACTIONTEST_JOBSTATUS_READYTOTURNIN:
            status = InventoryItemByDeclName->status;
            if ( status == JOBSTATUS_COMPLETED
              || status == JOBSTATUS_READYTOTURNIN
              || status == JOBSTATUS_READYTOTURNIN_UNKNOWN )
            {
              goto LABEL_43;
            }
            break;
          case INTERACTIONTEST_JOBSTATUS_ACCEPTED:
            v22 = InventoryItemByDeclName->status;
            if ( v22 == JOBSTATUS_COMPLETED
              || v22 == JOBSTATUS_READYTOTURNIN
              || v22 == JOBSTATUS_ACCEPTED
              || v22 == JOBSTATUS_READYTOTURNIN_UNKNOWN )
            {
              goto LABEL_43;
            }
            break;
          default:
            break;
        }
      }
      passOnEmpty = 0;
      goto LABEL_33;
    }
    if ( v23 == INTERACTIONCONDITION_ITEM )
      break;
    switch ( v23 )
    {
      case INTERACTIONCONDITION_GAMESTATEINT:
        if ( gameStateIntDecl != nullptr )
        {
          GameStateIntValue = idJobManager::GetGameStateIntValue(this: p_jobManager, gameState: gameStateIntDecl);
          if ( GameStateIntValue >= count )
            goto LABEL_43;
          passOnEmpty = 0;
        }
        else
        {
          idLib::Warning(fmt: "Interaction has gameStateInt based condition, no gameStateInt is defined on the interaction");
        }
        break;
      case INTERACTIONCONDITION_FORCEFALSE:
        goto LABEL_39;
      case INTERACTIONCONDITION_FORCETRUE:
        goto LABEL_43;
      default:
        break;
    }
LABEL_33:
    idStr::FreeData(this: &v24);
    if ( ++v8 >= condition->num )
      return passOnEmpty;
  }
  if ( inventoryDecl == nullptr )
  {
    idLib::Warning(fmt: "Interaction has item based condition, no item is defined on the interaction");
    goto LABEL_33;
  }
  v14 = (const idDeclJob *)inventoryDecl;
  v15 = (idJobManager *)player->GetInventory(this: player);
  JobByDecl = idJobManager::FindJobByDecl(this: v15, jobDecl: v14);
  if ( count >= 1 )
  {
    if ( JobByDecl != nullptr )
    {
      v17 = ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl);
      if ( v17 >= count )
        goto LABEL_43;
    }
    passOnEmpty = 0;
    goto LABEL_33;
  }
  if ( JobByDecl != nullptr )
  {
    v20 = ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl);
    if ( v20 >= count )
    {
LABEL_39:
      idStr::FreeData(this: &v24);
      return 0;
    }
  }
LABEL_43:
  idStr::FreeData(this: &v24);
  return 1;
}


// ========================================================================
// __unwind$487717
// EA  : 0x82A5FEEC
// RVA : 0x00A5FEEC
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

void _unwind_487717()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 240 + 96));
}


// ========================================================================
// ?InteractionConditionMet@idAIPlayerInteraction@@QBA_NABV?$idList@VinteractionTestCondition_t@aiPlayerInteraction_t@@$04@@PBVidPlayer@@_N@Z
// EA  : 0x82A5FF20
// RVA : 0x00A5FF20
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

int __fastcall idAIPlayerInteraction::InteractionConditionMet(
        idAIPlayerInteraction *this,
        const idList<aiPlayerInteraction_t::interactionTestCondition_t,5> *condition,
        const idPlayer *player,
        int passOnEmpty)
{
  idJobManager *p_jobManager; // r24
  int v8; // r25
  int i; // r27
  aiPlayerInteraction_t::interactionTestCondition_t *v10; // r30
  const idDeclInventory *inventoryDecl; // r10
  const idDeclGameStateInt *gameStateIntDecl; // r4
  idJob *InventoryItemByDeclName; // r3
  const idDeclJob *v14; // r30
  idJobManager *v15; // r3
  idJob *JobByDecl; // r3
  int v17; // r3
  int v18; // r3
  int GameStateIntValue; // r3
  missionStatus_t status; // [sp+50h] [-A0h]
  missionStatus_t v22; // [sp+50h] [-A0h]
  aiPlayerInteraction_t::interactionTestConditionType_t v23; // [sp+60h] [-90h]
  idStr v24; // [sp+64h] [-8Ch] BYREF
  aiPlayerInteraction_t::interactionTestJobStatus_t jobStatus; // [sp+84h] [-6Ch]
  const idDeclInventory *v26; // [sp+88h] [-68h]
  const idDeclGameStateInt *v27; // [sp+8Ch] [-64h]
  int count; // [sp+90h] [-60h]

  p_jobManager = &player->jobManager;
  v8 = 0;
  if ( condition->num <= 0 )
    return passOnEmpty;
  for ( i = 0; ; ++i )
  {
    v10 = &condition->list[i];
    v23 = v10->condition;
    idStr::idStr(this: &v24, text: &v10->jobDecl);
    jobStatus = v10->jobStatus;
    inventoryDecl = v10->inventoryDecl;
    v26 = inventoryDecl;
    gameStateIntDecl = v10->gameStateIntDecl;
    v27 = gameStateIntDecl;
    count = v10->count;
    switch ( v23 )
    {
      case INTERACTIONCONDITION_JOB:
        InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                    this: p_jobManager,
                                    jobName: v24.data);
        if ( InventoryItemByDeclName == nullptr )
          goto LABEL_38;
        switch ( jobStatus )
        {
          case INTERACTIONTEST_JOBSTATUS_COMPLETED:
            if ( InventoryItemByDeclName->status != JOBSTATUS_COMPLETED )
              goto LABEL_38;
            passOnEmpty = 1;
            break;
          case INTERACTIONTEST_JOBSTATUS_READYTOTURNIN:
            status = InventoryItemByDeclName->status;
            if ( status != JOBSTATUS_COMPLETED
              && status != JOBSTATUS_READYTOTURNIN
              && status != JOBSTATUS_READYTOTURNIN_UNKNOWN )
            {
              goto LABEL_38;
            }
            passOnEmpty = 1;
            break;
          case INTERACTIONTEST_JOBSTATUS_ACCEPTED:
            v22 = InventoryItemByDeclName->status;
            if ( v22 != JOBSTATUS_COMPLETED
              && v22 != JOBSTATUS_READYTOTURNIN
              && v22 != JOBSTATUS_ACCEPTED
              && v22 != JOBSTATUS_READYTOTURNIN_UNKNOWN )
            {
              goto LABEL_38;
            }
            passOnEmpty = 1;
            break;
          default:
            goto LABEL_38;
        }
        goto LABEL_36;
      case INTERACTIONCONDITION_ITEM:
        if ( inventoryDecl != nullptr )
        {
          v14 = (const idDeclJob *)inventoryDecl;
          v15 = (idJobManager *)player->GetInventory(this: player);
          JobByDecl = idJobManager::FindJobByDecl(this: v15, jobDecl: v14);
          if ( count < 1 )
          {
            if ( JobByDecl != nullptr )
            {
              v18 = ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl);
              if ( v18 >= count )
              {
LABEL_38:
                idStr::FreeData(this: &v24);
                return 0;
              }
            }
            passOnEmpty = 1;
          }
          else
          {
            if ( JobByDecl == nullptr )
              goto LABEL_38;
            v17 = ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl);
            if ( v17 < count )
              goto LABEL_38;
            passOnEmpty = 1;
          }
        }
        else
        {
          idLib::Warning(fmt: "Interaction has item based condition, no item is defined on the interaction");
        }
        goto LABEL_36;
      case INTERACTIONCONDITION_GAMESTATEINT:
        if ( gameStateIntDecl != nullptr )
        {
          GameStateIntValue = idJobManager::GetGameStateIntValue(this: p_jobManager, gameState: gameStateIntDecl);
          if ( GameStateIntValue < count )
            goto LABEL_38;
          passOnEmpty = 1;
        }
        else
        {
          idLib::Warning(fmt: "Interaction has gameStateInt based condition, no gameStateInt is defined on the interaction");
        }
        goto LABEL_36;
      case INTERACTIONCONDITION_FORCEFALSE:
        goto LABEL_38;
      default:
        break;
    }
    if ( v23 == INTERACTIONCONDITION_FORCETRUE )
      break;
LABEL_36:
    idStr::FreeData(this: &v24);
    if ( ++v8 >= condition->num )
      return passOnEmpty;
  }
  idStr::FreeData(this: &v24);
  return 1;
}


// ========================================================================
// __unwind$488008
// EA  : 0x82A601DC
// RVA : 0x00A601DC
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

void _unwind_488008()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 240 + 96));
}


// ========================================================================
// ?InteractionHasExpired@idAIPlayerInteraction@@QBA_NPBVaiPlayerInteraction_t@@PBVidPlayer@@PBVidDeclAIPlayerInteraction@@H@Z
// EA  : 0x82A60208
// RVA : 0x00A60208
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

int __fastcall idAIPlayerInteraction::InteractionHasExpired(
        idAIPlayerInteraction *this,
        const aiPlayerInteraction_t *interaction,
        const idPlayer *player,
        const idDeclAIPlayerInteraction *interactionDecl,
        int interactionNumber)
{
  idJob *JobByDecl; // r3
  idList<aiPlayerInteraction_t::interactionTestCondition_t,5> *p_hasExpiredCondition; // r4

  if ( interaction->interactionJob != nullptr )
  {
    JobByDecl = idJobManager::FindJobByDecl(this: &player->jobManager, jobDecl: interaction->interactionJob);
    if ( JobByDecl != nullptr && JobByDecl->status == JOBSTATUS_COMPLETED )
      return 1;
  }
  else if ( interaction->messageExpiresInteraction
         && idJobManager::GetJobOfferPlayed(this: &player->jobManager, interactionDecl, interactionNumber) )
  {
    return 1;
  }
  p_hasExpiredCondition = &interaction->hasExpiredCondition;
  if ( interaction->expiredOnAny )
    return idAIPlayerInteraction::AnyInteractionConditionMet(
             this,
             condition: p_hasExpiredCondition,
             player,
             passOnEmpty: 0);
  else
    return idAIPlayerInteraction::InteractionConditionMet(
             this,
             condition: p_hasExpiredCondition,
             player,
             passOnEmpty: 0);
}


// ========================================================================
// ?InteractionCanBeClosed@idAIPlayerInteraction@@QBA_NPBVaiPlayerInteraction_t@@PBVidPlayer@@@Z
// EA  : 0x82A602B8
// RVA : 0x00A602B8
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

int __fastcall idAIPlayerInteraction::InteractionCanBeClosed(
        idAIPlayerInteraction *this,
        const aiPlayerInteraction_t *interaction,
        const idPlayer *player)
{
  return idAIPlayerInteraction::InteractionConditionMet(
           this,
           condition: &interaction->canBeClosedCondition,
           player,
           passOnEmpty: 1);
}


// ========================================================================
// ?FindInteraction@idAIPlayerInteraction@@QAAPBVaiPlayerInteraction_t@@PBVidPlayer@@_NPAVidStr@@@Z
// EA  : 0x82A602C8
// RVA : 0x00A602C8
// PDB : w:\tech5\tungsten\game\ai\aiplayerinteraction.cpp
// ========================================================================

const aiPlayerInteraction_t *__fastcall idAIPlayerInteraction::FindInteraction(
        idAIPlayerInteraction *this,
        idPlayer *player,
        __int64 debugString,
        __int64 a4,
        __int64 a5)
{
  idStr *v6; // r28
  va *v7; // r3
  idVehicle *Control; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  va *v13; // r3
  __int64 v14; // r6
  int v15; // r27
  int v16; // r26
  unsigned __int8 v17; // r14
  __int64 v18; // r10
  __int64 v19; // r8
  int v20; // r11
  int v21; // r31
  const char *v22; // r4
  const idDeclJob *v23; // r4
  __int64 v24; // r10
  idJob *JobByDecl; // r3
  char v26; // r11
  char v27; // r11
  unsigned __int8 v28; // r11
  __int64 v29; // r6
  va *v30; // r3
  __int64 v31; // r6
  __int64 v32; // r6
  int v33; // [sp+8h] [-10F8h]
  int v34; // [sp+Ch] [-10F4h]
  int v35; // [sp+10h] [-10F0h]
  int v36; // [sp+14h] [-10ECh]
  int v37; // [sp+18h] [-10E8h]
  int v38; // [sp+1Ch] [-10E4h]
  int v39; // [sp+50h] [-10B0h]
  va v40; // [sp+60h] [-10A0h] BYREF

  v6 = (idStr *)debugString;
  if ( this->decl == nullptr )
  {
    if ( (_DWORD)debugString != 0 )
    {
      v7 = va::va(
             this: &v40,
             fmt: "no decl\n",
             a3: debugString,
             a4,
             a5,
             a6: v33,
             a7: v34,
             a8: v35,
             a9: v36,
             a10: v37,
             a11: v38);
      idStr::Append(this: v6, text: v7);
    }
    return nullptr;
  }
  if ( player == nullptr )
  {
    idLib::Warning(fmt: "No player passed into idAIPlayerInteraction::FindInteraction?");
    return nullptr;
  }
  Control = (idVehicle *)idPlayer::GetControl(this: player);
  if ( idVehicle::CastTo(c: Control) == nullptr )
  {
    LODWORD(v14) = this->decl;
    v15 = 0;
    v16 = 0;
    v17 = 0;
    if ( *(int *)(v14 + 80) <= 0 )
      return (const aiPlayerInteraction_t *)v16;
    v39 = 0;
    HIDWORD(v18) = "1 - formation cover, such as behind regime shield units";
    LODWORD(v19) = "1 - formation cover, such as behind regime shield units";
    HIDWORD(v19) = "1 - formation cover, such as behind regime shield units";
    while ( 1 )
    {
      v20 = *(_DWORD *)(v14 + 76);
      LODWORD(v18) = v39;
      v21 = v20 + v39;
      if ( v20 + v39 != 0 )
      {
        if ( (unsigned __int8)idAIPlayerInteraction::InteractionHasExpired(
                                this,
                                interaction: (const aiPlayerInteraction_t *)(v20 + v39),
                                player,
                                interactionDecl: (const idDeclAIPlayerInteraction *)v14,
                                interactionNumber: v15) != 0 )
        {
          if ( v6 != nullptr )
          {
            v22 = "%d expired\n";
            goto LABEL_55;
          }
        }
        else if ( (unsigned __int8)idAIPlayerInteraction::InteractionConditionMet(
                                     this,
                                     condition: (const idList<aiPlayerInteraction_t::interactionTestCondition_t,5> *)(v21 + 224),
                                     player,
                                     passOnEmpty: 1) != 0 )
        {
          v23 = *(const idDeclJob **)(v21 + 196);
          if ( v23 != nullptr )
          {
            JobByDecl = idJobManager::FindJobByDecl(this: &player->jobManager, jobDecl: v23);
            if ( JobByDecl == nullptr )
              goto LABEL_61;
            LODWORD(v24) = JobByDecl->status;
            if ( (_DWORD)v24 == 3 || (v26 = 0, (_DWORD)v24 == 2) )
              v26 = 1;
            if ( v26 != 0 )
            {
              if ( (_DWORD)v24 == 3 || (v27 = 0, (_DWORD)v24 == 4) )
                v27 = 1;
              if ( v27 == 0 || (v28 = 1, *(_DWORD *)(v21 + 216) == 0) )
                v28 = 0;
              if ( v16 != 0 )
              {
                LODWORD(v24) = v17;
                if ( v17 != 0 || v28 == 0 )
                {
                  if ( v6 != nullptr )
                  {
                    LODWORD(v32) = v28;
                    HIDWORD(v32) = v15;
                    v30 = va::va(
                            this: &v40,
                            fmt: "%d job, %d\n",
                            a3: v32,
                            a4: v19,
                            a5: v24,
                            a6: v33,
                            a7: v34,
                            a8: v35,
                            a9: v36,
                            a10: v37,
                            a11: v38);
                    goto LABEL_56;
                  }
                }
                else
                {
                  v16 = v21;
                  v17 = v28;
                  if ( v6 != nullptr )
                  {
                    HIDWORD(v31) = v15;
                    LODWORD(v31) = v28;
                    v30 = va::va(
                            this: &v40,
                            fmt: "%d JOB OVERRIDE, %d\n",
                            a3: v31,
                            a4: v19,
                            a5: v24,
                            a6: v33,
                            a7: v34,
                            a8: v35,
                            a9: v36,
                            a10: v37,
                            a11: v38);
                    goto LABEL_56;
                  }
                }
              }
              else
              {
                v16 = v21;
                v17 = v28;
                if ( v6 != nullptr )
                {
                  LODWORD(v29) = v28;
                  HIDWORD(v29) = v15;
                  v30 = va::va(
                          this: &v40,
                          fmt: "%d JOB, %d\n",
                          a3: v29,
                          a4: v19,
                          a5: v24,
                          a6: v33,
                          a7: v34,
                          a8: v35,
                          a9: v36,
                          a10: v37,
                          a11: v38);
                  goto LABEL_56;
                }
              }
            }
            else
            {
LABEL_61:
              if ( idJobManager::IsJobAvailable(this: &player->jobManager, jobDecl: *(const idDeclJob **)(v21 + 196)) )
              {
                if ( v16 != 0 )
                {
                  if ( v6 != nullptr )
                  {
                    v22 = "%d job\n";
                    goto LABEL_55;
                  }
                }
                else
                {
                  v16 = v21;
                  if ( v6 != nullptr )
                  {
                    v22 = "%d JOB\n";
                    goto LABEL_55;
                  }
                }
              }
              else if ( v6 != nullptr )
              {
                v22 = "%d job unavail\n";
LABEL_55:
                HIDWORD(v14) = v15;
                v30 = va::va(
                        this: &v40,
                        fmt: v22,
                        a3: v14,
                        a4: v19,
                        a5: v18,
                        a6: v33,
                        a7: v34,
                        a8: v35,
                        a9: v36,
                        a10: v37,
                        a11: v38);
LABEL_56:
                idStr::Append(this: v6, text: v30);
              }
            }
          }
          else if ( v16 != 0 )
          {
            if ( v6 != nullptr )
            {
              v22 = "%d valid, but late\n";
              goto LABEL_55;
            }
          }
          else
          {
            v16 = v21;
            if ( v6 != nullptr )
            {
              v22 = "%d CURRENT\n";
              goto LABEL_55;
            }
          }
        }
        else if ( v6 != nullptr )
        {
          v22 = "%d unavail\n";
          goto LABEL_55;
        }
      }
      else if ( v6 != nullptr )
      {
        v22 = "%d no interaction on decl?\n";
        goto LABEL_55;
      }
      LODWORD(v14) = this->decl;
      ++v15;
      HIDWORD(v18) = *(_DWORD *)(v14 + 80);
      v39 += 300;
      if ( v15 >= SHIDWORD(v18) )
        return (const aiPlayerInteraction_t *)v16;
    }
  }
  if ( v6 == nullptr )
    return nullptr;
  v13 = va::va(
          this: &v40,
          fmt: "player in car\n",
          a3: v12,
          a4: v11,
          a5: v10,
          a6: v33,
          a7: v34,
          a8: v35,
          a9: v36,
          a10: v37,
          a11: v38);
  idStr::Append(this: v6, text: v13);
  return nullptr;
}

