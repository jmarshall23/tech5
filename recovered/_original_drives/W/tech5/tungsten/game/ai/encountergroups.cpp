
// ========================================================================
// ?SetAnyMemberHasSeenDeadBody@idEncounterGroup@@QAAX_N@Z
// EA  : 0x82A926B8
// RVA : 0x00A926B8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::SetAnyMemberHasSeenDeadBody(idEncounterGroup *this, bool seen)
{
  this->anyMemberHasSeenDeadBody = seen;
}


// ========================================================================
// ?GetShouldAmbush@idEncounterGroup@@QBA_NXZ
// EA  : 0x82A926C0
// RVA : 0x00A926C0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

BOOL __fastcall idEncounterGroup::GetShouldAmbush(idEncounterGroup *this)
{
  return this->shouldAmbush;
}


// ========================================================================
// ?SetShouldAmbush@idEncounterGroup@@QAAX_N@Z
// EA  : 0x82A926C8
// RVA : 0x00A926C8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::SetShouldAmbush(idEncounterGroup *this, bool val)
{
  this->shouldAmbush = val;
}


// ========================================================================
// ?GetAnyMemberHasSeenDeadBody@idEncounterGroup@@QBA_NXZ
// EA  : 0x82A926D0
// RVA : 0x00A926D0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

BOOL __fastcall idEncounterGroup::GetAnyMemberHasSeenDeadBody(idEncounterGroup *this)
{
  return this->anyMemberHasSeenDeadBody;
}


// ========================================================================
// ?GetNodesListByHintType@idCombatStage@@QBAPBV?$idList@H$04@@W4combatHintType_t@idAICombatHint@@@Z
// EA  : 0x82A926D8
// RVA : 0x00A926D8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idList<int,5> *__fastcall idCombatStage::GetNodesListByHintType(idCombatStage *this, unsigned int hintType)
{
  if ( hintType > 7 )
    return nullptr;
  switch ( hintType )
  {
    case 1u:
      return &this->assaultNodes;
    case 2u:
      return &this->flankNodes;
    case 3u:
      return &this->flankTargetNodes;
    case 4u:
      return &this->flankPathNodes;
    case 5u:
      return &this->grenadeNodes;
    case 6u:
      return &this->rechargeNodes;
    default:
      break;
  }
  if ( hintType != 0 )
    return &this->suppressionFireNodes;
  return &this->defenseNodes;
}


// ========================================================================
// ?RoleToHintType@idCombatStage@@SA?AW4combatHintType_t@idAICombatHint@@W4encounterGroupRole_t@@@Z
// EA  : 0x82A92750
// RVA : 0x00A92750
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idCombatStage::RoleToHintType(const encounterGroupRole_t role)
{
  switch ( role )
  {
    case ROLE_DEFEND:
      return 0;
    case ROLE_ASSAULT:
      return 1;
    case ROLE_FLANK:
      return 2;
    default:
      break;
  }
  return 8;
}


// ========================================================================
// ?NumLivingMembers@idEncounterGroup@@QBAHXZ
// EA  : 0x82A92788
// RVA : 0x00A92788
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::NumLivingMembers(idEncounterGroup *this)
{
  int v2; // r28
  int v3; // r29
  int v4; // r31
  idEncounterGroup **list; // r11

  v2 = 0;
  v3 = 0;
  if ( this->childGroups.num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->childGroups.list;
      if ( list[v4] != nullptr )
        v2 += idEncounterGroup::NumLivingMembers(this: list[v4]);
      ++v3;
      ++v4;
    }
    while ( v3 < this->childGroups.num );
  }
  return this->numLivingMembers + v2;
}


// ========================================================================
// ?NumDeadMembers@idEncounterGroup@@QBAHXZ
// EA  : 0x82A927F0
// RVA : 0x00A927F0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::NumDeadMembers(idEncounterGroup *this)
{
  int v2; // r31
  idEncounterGroup **list; // r4
  int num; // r30
  idEncounterGroup *v5; // r5
  int v6; // r6
  idEncounterGroup **v7; // r8
  int v8; // r9
  int v9; // r7
  int v10; // r3
  int v11; // r6

  v2 = 0;
  if ( this->childGroups.num > 0 )
  {
    list = this->childGroups.list;
    num = this->childGroups.num;
    do
    {
      if ( *list != nullptr )
      {
        v5 = *list;
        v6 = 0;
        if ( (*list)->childGroups.num > 0 )
        {
          v7 = v5->childGroups.list;
          v8 = 0;
          v9 = (*list)->childGroups.num;
          do
          {
            if ( v7[v8] != nullptr )
            {
              v10 = idEncounterGroup::NumLivingMembers(this: v7[v8]);
              v6 = v10 + v11;
            }
            --v9;
            ++v8;
          }
          while ( v9 != 0 );
        }
        v2 += v5->numLivingMembers + v6;
      }
      --num;
      ++list;
    }
    while ( num != 0 );
  }
  return this->numDeadMembers + v2;
}


// ========================================================================
// ?GetConfidenceLevel@idEncounterGroup@@QBA?AW4aiConfidenceLevel_t@@XZ
// EA  : 0x82A92890
// RVA : 0x00A92890
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

aiConfidenceLevel_t __fastcall idEncounterGroup::GetConfidenceLevel(idEncounterGroup *this)
{
  aiConfidenceLevel_t confidenceLevel; // r29
  int v3; // r28
  int v4; // r31
  idEncounterGroup **list; // r11
  aiConfidenceLevel_t v6; // r3

  confidenceLevel = this->confidenceLevel;
  v3 = 0;
  if ( this->childGroups.num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->childGroups.list;
      if ( list[v4] != nullptr )
      {
        v6 = idEncounterGroup::GetConfidenceLevel(this: list[v4]);
        if ( v6 > confidenceLevel )
          confidenceLevel = v6;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->childGroups.num );
  }
  return confidenceLevel;
}


// ========================================================================
// ?GetNumTargets@idEncounterGroup@@QBAHXZ
// EA  : 0x82A92900
// RVA : 0x00A92900
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::GetNumTargets(idEncounterGroup *this)
{
  int num; // r28
  int v3; // r29
  int v4; // r31
  idEncounterGroup **list; // r11

  num = this->targetList.num;
  v3 = 0;
  if ( this->childGroups.num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->childGroups.list;
      if ( list[v4] != nullptr )
        num += idEncounterGroup::GetNumTargets(this: list[v4]);
      ++v3;
      ++v4;
    }
    while ( v3 < this->childGroups.num );
  }
  return num;
}


// ========================================================================
// ?LowestPlayerHealth@idEncounterGroup@@QBAMXZ
// EA  : 0x82A92968
// RVA : 0x00A92968
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

float __fastcall idEncounterGroup::LowestPlayerHealth(idEncounterGroup *this)
{
  int v1; // r30
  double v2; // fp31
  idPlayer *Player; // r3
  idTungstenHealth *p_playerHealth; // r31
  double v5; // fp1

  v1 = 0;
  v2 = 3.4028235e38;
  do
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: v1);
    if ( Player != nullptr )
    {
      p_playerHealth = &Player->playerHealth;
      if ( ((double (__fastcall *)(idTungstenHealth *))Player->playerHealth.GetCurBaseHealth_Impl)(a1: &Player->playerHealth) < v2 )
        v2 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetCurBaseHealth_Impl)(a1: p_playerHealth);
    }
    ++v1;
  }
  while ( v1 < 6 );
  v5 = v2;
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?HighestPlayerHealth@idEncounterGroup@@QBAMXZ
// EA  : 0x82A929F0
// RVA : 0x00A929F0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

float __fastcall idEncounterGroup::HighestPlayerHealth(idEncounterGroup *this)
{
  int v1; // r30
  double v2; // fp31
  idPlayer *Player; // r3
  idTungstenHealth *p_playerHealth; // r31
  double v5; // fp1

  v1 = 0;
  v2 = 3.4028235e38;
  do
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: v1);
    if ( Player != nullptr )
    {
      p_playerHealth = &Player->playerHealth;
      if ( ((double (__fastcall *)(idTungstenHealth *))Player->playerHealth.GetCurBaseHealth_Impl)(a1: &Player->playerHealth) > v2 )
        v2 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetCurBaseHealth_Impl)(a1: p_playerHealth);
    }
    ++v1;
  }
  while ( v1 < 6 );
  v5 = v2;
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?AnyMemberHighestAlertCycle@idEncounterGroup@@QBA?AW4alertCycle_t@@XZ
// EA  : 0x82A92A78
// RVA : 0x00A92A78
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

alertCycle_t __fastcall idEncounterGroup::AnyMemberHighestAlertCycle(idEncounterGroup *this)
{
  alertCycle_t highestMemberAlertCycle; // r29
  int v3; // r28
  int v4; // r31
  idEncounterGroup **list; // r11
  alertCycle_t v6; // r3

  highestMemberAlertCycle = this->highestMemberAlertCycle;
  v3 = 0;
  if ( this->childGroups.num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->childGroups.list;
      if ( list[v4] != nullptr )
      {
        v6 = idEncounterGroup::AnyMemberHighestAlertCycle(this: list[v4]);
        if ( v6 > highestMemberAlertCycle )
          highestMemberAlertCycle = v6;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->childGroups.num );
  }
  return highestMemberAlertCycle;
}


// ========================================================================
// ?GetPlayerWithLowestHealth@idEncounterGroup@@QBAPBVidPlayer@@XZ
// EA  : 0x82A92AE8
// RVA : 0x00A92AE8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idPlayer *__fastcall idEncounterGroup::GetPlayerWithLowestHealth(idEncounterGroup *this)
{
  idPlayer *v1; // r27
  int v2; // r29
  double v3; // fp31
  idPlayer *Player; // r3
  idPlayer *v5; // r31
  idTungstenHealth *p_playerHealth; // r30

  v1 = nullptr;
  v2 = 0;
  v3 = 3.4028235e38;
  do
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: v2);
    v5 = Player;
    if ( Player != nullptr )
    {
      p_playerHealth = &Player->playerHealth;
      if ( ((double (__fastcall *)(idTungstenHealth *))Player->playerHealth.GetCurBaseHealth_Impl)(a1: &Player->playerHealth) < v3 )
      {
        v3 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetCurBaseHealth_Impl)(a1: p_playerHealth);
        v1 = v5;
      }
    }
    ++v2;
  }
  while ( v2 < 6 );
  return v1;
}


// ========================================================================
// ?GetPlayerWithHighestHealth@idEncounterGroup@@QBAPBVidPlayer@@XZ
// EA  : 0x82A92B80
// RVA : 0x00A92B80
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idPlayer *__fastcall idEncounterGroup::GetPlayerWithHighestHealth(idEncounterGroup *this)
{
  idPlayer *v1; // r27
  int v2; // r29
  double v3; // fp31
  idPlayer *Player; // r3
  idPlayer *v5; // r31
  idTungstenHealth *p_playerHealth; // r30

  v1 = nullptr;
  v2 = 0;
  v3 = 0.0;
  do
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: v2);
    v5 = Player;
    if ( Player != nullptr )
    {
      p_playerHealth = &Player->playerHealth;
      if ( ((double (__fastcall *)(idTungstenHealth *))Player->playerHealth.GetCurBaseHealth_Impl)(a1: &Player->playerHealth) > v3 )
      {
        v3 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetCurBaseHealth_Impl)(a1: p_playerHealth);
        v1 = v5;
      }
    }
    ++v2;
  }
  while ( v2 < 6 );
  return v1;
}


// ========================================================================
// ?NumUnsearchedSearchPointsForGroup@idEncounterGroup@@QAAHPBVidAAS2@@H@Z
// EA  : 0x82A92C18
// RVA : 0x00A92C18
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::NumUnsearchedSearchPointsForGroup(
        idEncounterGroup *this,
        const idAAS2 *aas,
        const int grouping)
{
  int v6; // r26
  int v8; // r29
  int v9; // r31
  idEncounterGroup::searchPoint_t *v10; // r11

  v6 = 0;
  if ( aas == nullptr )
    return 0;
  v8 = 0;
  if ( this->searchPointList.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = &this->searchPointList.list[v9];
      if ( !v10->visited && aas->GetHintNode(this: aas, a2: v10->hintNodeIndex)->grouping == grouping )
        ++v6;
      ++v8;
      ++v9;
    }
    while ( v8 < this->searchPointList.num );
  }
  return v6;
}


// ========================================================================
// ?SetSearchPointGroupUnvisited@idEncounterGroup@@QAAXPBVidAAS2@@H@Z
// EA  : 0x82A92CB8
// RVA : 0x00A92CB8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::SetSearchPointGroupUnvisited(
        idEncounterGroup *this,
        const idAAS2 *aas,
        const int grouping)
{
  int v6; // r28
  int v7; // r31

  if ( aas != nullptr )
  {
    v6 = 0;
    if ( this->searchPointList.num > 0 )
    {
      v7 = 0;
      do
      {
        if ( aas->GetHintNode(this: aas, a2: this->searchPointList.list[v7].hintNodeIndex)->grouping == grouping )
          this->searchPointList.list[v7].visited = false;
        ++v6;
        ++v7;
      }
      while ( v6 < this->searchPointList.num );
    }
  }
}


// ========================================================================
// ?ConfidentEnoughToTaunt@idEncounterGroup@@QBA_NPBVidAI2@@@Z
// EA  : 0x82A92D40
// RVA : 0x00A92D40
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

BOOL __fastcall idEncounterGroup::ConfidentEnoughToTaunt(idEncounterGroup *this, const idAI2 *ai)
{
  aiConfidenceLevel_t ConfidenceLevel; // r3
  int v3; // r4

  ConfidenceLevel = idEncounterGroup::GetConfidenceLevel(this);
  return ConfidenceLevel >= *(_DWORD *)(*(_DWORD *)(v3 + 11400) + 724);
}


// ========================================================================
// ?BumpNextGrenadeTime@idEncounterGroup@@QAAXXZ
// EA  : 0x82A92D80
// RVA : 0x00A92D80
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::BumpNextGrenadeTime(idEncounterGroup *this)
{
  this->nextGrenadeTime = 1000 * this->minGrenadeRethrowTime
                        + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?GetPreventativeCondition@idAIGroupStatus@idAIVolatile@idAI2@@QBA?AW4aiCondition_t@3@H@Z
// EA  : 0x82A92DD0
// RVA : 0x00A92DD0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

idAI2::aiCondition_t __fastcall idAI2::idAIVolatile::idAIGroupStatus::GetPreventativeCondition(
        idAI2::idAIVolatile::idAIGroupStatus *this,
        char mask)
{
  idAI2::aiCondition_t result; // r3
  idAI2::aiCondition_t condition; // r11

  if ( (mask & 8) != 0 && (this->condition & 8) != 0 )
    return CONDITION_INJURED;
  if ( (mask & 0x10) != 0 && (this->condition & 0x10) != 0 )
    return CONDITION_INTIMIDATED;
  if ( (mask & 4) != 0 && (this->condition & 4) != 0 )
    return CONDITION_CANT_SEE;
  if ( (mask & 2) != 0 && (this->condition & 2) != 0 )
    return CONDITION_PINNED;
  if ( (mask & 1) == 0 )
    return CONDITION_NONE;
  condition = this->condition;
  result = CONDITION_UNAVAILABLE;
  if ( (condition & 1) == 0 )
    return CONDITION_NONE;
  return result;
}


// ========================================================================
// ?Spawn@idEncounterGroupMgr@@QAAXXZ
// EA  : 0x82A92E88
// RVA : 0x00A92E88
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroupMgr::Spawn(idEncounterGroupMgr *this)
{
  int v2; // r31
  idEncounterGroupManager *p_encounterGroupManager; // r28
  int v4; // r30
  char v5; // [sp+50h] [-30h] BYREF

  v2 = 0;
  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  if ( this->groups.num > 0 )
  {
    v4 = 0;
    do
    {
      idEncounterGroupManager::AddGroup(
        this: (idEncounterGroupManager *)&v5,
        result: p_encounterGroupManager,
        otherGroup: &this->groups.list[v4]);
      ++v2;
      ++v4;
    }
    while ( v2 < this->groups.num );
  }
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?GetNumHintNodes@idCombatStage@@QBAHW4combatHintType_t@idAICombatHint@@@Z
// EA  : 0x82A92F00
// RVA : 0x00A92F00
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idList<int,5> *__fastcall idCombatStage::GetNumHintNodes(idCombatStage *this, unsigned int hintType)
{
  const idList<int,5> *result; // r3

  result = idCombatStage::GetNodesListByHintType(this, hintType);
  if ( result != nullptr )
    return (const idList<int,5> *)result->num;
  return result;
}


// ========================================================================
// ?DrawPrimitive@@YAXPBVidAICombatHint@@VidColor@@PBDH@Z
// EA  : 0x82A92F40
// RVA : 0x00A92F40
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall DrawPrimitive(
        const idAICombatHint *hint,
        __int64 name,
        int duration,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  idPhysics *Physics; // r28
  idRenderWorld *v16; // r26
  idPhysics *v17; // r3
  idRenderWorld_vtbl *v18; // r28
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v20; // r3
  aiHintPrimitive_t type; // r11
  idPhysics *v22; // r3
  double v23; // fp31
  float *v24; // r3
  idRenderWorld *v25; // r3
  idPhysics *v26; // r28
  idRenderWorld *v27; // r3
  double radius; // fp29
  idRenderWorld *v29; // r27
  idPhysics *v30; // r3
  idRenderWorld_vtbl *v31; // r28
  const idVec3 *(__fastcall *v32)(idPhysics *, int); // ctr
  int v33; // r3
  idPhysics *v34; // r30
  idRenderWorld *v35; // r3
  idRenderWorld *v36; // r28
  double height; // fp31
  float *v38; // r3
  double v39; // fp13
  double v40; // fp12
  idPhysics *v41; // r30
  idRenderWorld *v42; // r28
  double v43; // fp31
  idRenderWorld_vtbl *v44; // r31
  int v45; // r3
  float v46[4]; // [sp+60h] [-90h] BYREF
  float v47[4]; // [sp+70h] [-80h] BYREF
  float v48[4]; // [sp+80h] [-70h] BYREF
  float v49[4]; // [sp+90h] [-60h] BYREF

  a11 = *(__int64 *)((char *)&name + 4);
  a12 = name;
  if ( hint != nullptr )
  {
    Physics = idEntity::GetPhysics(this: &hint->idAIHint);
    v16 = common->RW(this: common);
    v17 = Physics;
    GetOrigin = Physics->GetOrigin;
    v18 = v16->__vftable;
    v20 = (int)GetOrigin(this: v17, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, int, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), __int64 *, int, int, _DWORD, double))v18->DebugText)(
      a1: v16,
      a2: duration,
      a3: v20,
      a4: v18->DebugText,
      a5: &a11,
      a6: 1,
      a7: a4,
      a8: 0,
      a9: 0.2);
    type = hint->primitive.type;
    if ( type != AIHINT_PRIMITIVE_CIRCLE )
    {
      if ( type == AIHINT_PRIMITIVE_CYLINDER )
      {
        v26 = idEntity::GetPhysics(this: &hint->idAIHint);
        v27 = common->RW(this: common);
        radius = hint->primitive.radius;
        v29 = v27;
        v30 = v26;
        v46[1] = 0.0;
        v46[0] = 0.0;
        v46[2] = 1.0;
        v32 = v26->GetOrigin;
        v31 = v29->__vftable;
        v33 = (int)v32(this: v30, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, __int64 *, int, float *, double))v31->DebugCircle)(
          a1: v29,
          a2: &a11,
          a3: v33,
          a4: v46,
          a5: radius);
        v34 = idEntity::GetPhysics(this: &hint->idAIHint);
        v35 = common->RW(this: common);
        v47[0] = 0.0;
        v36 = v35;
        v47[1] = 0.0;
        v47[2] = 1.0;
        height = hint->primitive.height;
        v38 = (float *)v34->GetOrigin(this: v34, a2: 0);
        v39 = v38[1];
        v40 = (float)(v38[2] + (float)height);
        v48[0] = *v38;
        v48[1] = v39;
        v48[2] = v40;
        ((void (__fastcall *)(idRenderWorld *, __int64 *, float *, float *, double))v36->DebugCircle)(
          a1: v36,
          a2: &a11,
          a3: v48,
          a4: v47,
          a5: hint->primitive.radius);
      }
      else if ( (unsigned int)type < AIHINT_PRIMITIVE_PLANE )
      {
        v22 = idEntity::GetPhysics(this: &hint->idAIHint);
        v23 = hint->primitive.radius;
        v24 = (float *)v22->GetOrigin(this: v22, a2: 0);
        v49[0] = *v24;
        v49[1] = v24[1];
        v49[2] = v24[2];
        v49[3] = v23;
        v25 = common->RW(this: common);
        v25->DebugSphere(this: v25, a2: (const idVec4 *)&a11, a3: (const idSphere *)v49, a4: 12, a5: a4, a6: true);
      }
    }
    else
    {
      v41 = idEntity::GetPhysics(this: &hint->idAIHint);
      v42 = common->RW(this: common);
      v43 = hint->primitive.radius;
      v44 = v42->__vftable;
      v45 = (int)v41->GetOrigin(this: v41, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, __int64 *, int, idVec3 *, double))v44->DebugCircle)(
        a1: v42,
        a2: &a11,
        a3: v45,
        a4: &vec3_up,
        a5: v43);
    }
  }
}


// ========================================================================
// ??0idEncounterState@@QAA@XZ
// EA  : 0x82A93230
// RVA : 0x00A93230
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

idEncounterState *__fastcall idEncounterState::idEncounterState(idEncounterState *this)
{
  this->state = DEFAULT;
  this->target.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ?FindIndex@idEncounterGroup@@QBAHPAVidAI2@@@Z
// EA  : 0x82A93248
// RVA : 0x00A93248
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::FindIndex(idEncounterGroup *this, idAI2 *ai)
{
  int v4; // r29
  int v5; // r31
  idGameLocal *v6; // r10
  int value; // r9
  idAI2 *v8; // r3
  idAI2 *v9; // r3

  v4 = 0;
  if ( this->members.num <= 0 )
    return -1;
  v5 = 0;
  v6 = gameLocal;
  while ( 1 )
  {
    value = this->members.list[v5].spawnId.value;
    if ( v6->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v8 = (idAI2 *)v6->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idAI2::CastTo(c: v8);
      v6 = gameLocal;
    }
    else
    {
      v9 = nullptr;
    }
    if ( v9 == ai )
      break;
    ++v4;
    ++v5;
    if ( v4 >= this->members.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?Remove@idEncounterGroup@@QAAXPAVidAI2@@@Z
// EA  : 0x82A932F8
// RVA : 0x00A932F8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::Remove(idEncounterGroup *this, idAI2 *ai)
{
  int Index; // r3
  int num; // r11
  int v5; // r11

  Index = idEncounterGroup::FindIndex(this, ai);
  if ( Index >= 0 )
  {
    num = this->members.num;
    if ( Index < num )
    {
      v5 = num - 1;
      this->members.num = v5;
      if ( Index != v5 )
        this->members.list[Index].spawnId.value = this->members.list[v5].spawnId.value;
    }
    if ( this->members.num == 0 )
    {
      idFaction::SetDeclFaction(this: &this->faction, faction: nullptr, clearRelationships: true);
      this->confidenceLevel = AICONFIDENCE_FEARLESS;
    }
  }
}


// ========================================================================
// ?PercentMembersAlive@idEncounterGroup@@QBAMXZ
// EA  : 0x82A93388
// RVA : 0x00A93388
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

float __fastcall idEncounterGroup::PercentMembersAlive(idEncounterGroup *this)
{
  int v1; // r31
  __int64 v2; // r10
  unsigned int v3; // r4
  int v4; // r30
  int v5; // r29
  _DWORD *v6; // r8
  int v7; // r6
  int v8; // r7
  int v9; // r5
  int v10; // r3
  int v11; // r6
  double v12; // fp1

  v1 = idEncounterGroup::NumLivingMembers(this);
  v3 = *(_DWORD *)(HIDWORD(v2) + 140);
  if ( *(int *)(HIDWORD(v2) + 36) > 0 )
  {
    v4 = *(_DWORD *)(HIDWORD(v2) + 32);
    v5 = *(_DWORD *)(HIDWORD(v2) + 36);
    do
    {
      if ( *(_DWORD *)v4 != 0 )
      {
        v6 = *(_DWORD **)v4;
        v7 = 0;
        if ( *(int *)(*(_DWORD *)v4 + 36) > 0 )
        {
          v8 = v6[8];
          HIDWORD(v2) = 0;
          v9 = *(_DWORD *)(*(_DWORD *)v4 + 36);
          do
          {
            if ( *(_DWORD *)(HIDWORD(v2) + v8) != 0 )
            {
              v10 = idEncounterGroup::NumLivingMembers(this: *(idEncounterGroup **)(HIDWORD(v2) + v8));
              v7 = v10 + v11;
            }
            --v9;
            HIDWORD(v2) += 4;
          }
          while ( v9 != 0 );
        }
        v3 += v6[35];
        v1 += v6[38] + v7;
      }
      --v5;
      v4 += 4;
    }
    while ( v5 != 0 );
  }
  LODWORD(v2) = v1;
  v12 = (float)((float)v2 / (float)__SPAIR64__(v1, v3));
  return *((float *)&v12 + 1);
}


// ========================================================================
// ?AverageHealth@idEncounterGroup@@QBAMXZ
// EA  : 0x82A93460
// RVA : 0x00A93460
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

float __fastcall idEncounterGroup::AverageHealth(idEncounterGroup *this)
{
  int v2; // r28
  double v3; // fp31
  double v4; // fp30
  int v5; // r30
  int v6; // r31
  __int64 v7; // r11
  unsigned int v8; // r26
  int v9; // r27
  int v10; // r30
  int value; // r9
  idAI2 *v12; // r3
  idAI2 *v13; // r3
  idAI2 *v14; // r31
  double v15; // fp1

  v2 = 0;
  v3 = 0.0;
  v4 = 0.0;
  if ( this->childGroups.num > 0 )
  {
    v5 = 0;
    v6 = 0;
    do
    {
      LODWORD(v7) = this->childGroups.list;
      HIDWORD(v7) = *(_DWORD *)(v7 + v6);
      if ( HIDWORD(v7) != 0 )
      {
        ++v2;
        v4 = (float)(idEncounterGroup::AverageHealth(this: *(idEncounterGroup **)(v7 + v6)) + (float)v4);
      }
      ++v5;
      v6 += 4;
    }
    while ( v5 < this->childGroups.num );
    LODWORD(v7) = v2;
    v4 = (float)((float)v4 / (float)v7);
  }
  v8 = 0;
  v9 = 0;
  if ( this->members.num <= 0 )
    goto LABEL_16;
  v10 = 0;
  do
  {
    value = this->members.list[v10].spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v12 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v12 != nullptr )
      {
        v13 = idAI2::CastTo(c: v12);
        v14 = v13;
        if ( v13 != nullptr )
        {
          ++v8;
          if ( !v13->IsDead(this: v13) )
            v3 = (float)(v14->aiHealth.GetBaseHealthRatio_Impl(this: &v14->aiHealth) + (float)v3);
        }
      }
    }
    ++v9;
    ++v10;
  }
  while ( v9 < this->members.num );
  if ( v8 != 0 )
    v15 = (float)((float)((float)((float)v3 / (float)__SPAIR64__(0x82000000, v8)) + (float)v4) * (float)0.5);
  else
LABEL_16:
    v15 = v4;
  return *((float *)&v15 + 1);
}


// ========================================================================
// ?AverageEnemyHealthRatio@idEncounterGroup@@QBAMXZ
// EA  : 0x82A93600
// RVA : 0x00A93600
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

float __fastcall idEncounterGroup::AverageEnemyHealthRatio(idEncounterGroup *this)
{
  int v2; // r29
  int v3; // r30
  double v4; // fp31
  double v5; // fp30
  int v6; // r31
  __int64 v7; // r11
  double v8; // fp30
  unsigned int v9; // r26
  int v10; // r29
  int v11; // r30
  int value; // r9
  idEntity *v13; // r3
  idActor *v14; // r3
  idActor *v15; // r3
  idActor *v16; // r31
  int v17; // r3
  double v18; // fp1

  v2 = 0;
  v3 = 0;
  v4 = 0.0;
  v5 = 0.0;
  if ( this->childGroups.num <= 0 )
    goto LABEL_8;
  v6 = 0;
  do
  {
    LODWORD(v7) = this->childGroups.list;
    HIDWORD(v7) = *(_DWORD *)(v6 + v7);
    if ( HIDWORD(v7) != 0 )
    {
      v5 = (float)(idEncounterGroup::AverageEnemyHealthRatio(this: *(idEncounterGroup **)(v6 + v7)) + (float)v5);
      ++v2;
    }
    ++v3;
    v6 += 4;
  }
  while ( v3 < this->childGroups.num );
  if ( v2 <= 0 )
  {
LABEL_8:
    v8 = 1.0;
  }
  else
  {
    LODWORD(v7) = v2;
    v8 = (float)((float)v5 / (float)v7);
  }
  v9 = 0;
  v10 = 0;
  if ( this->targetList.num <= 0 )
    goto LABEL_21;
  v11 = 0;
  do
  {
    value = this->targetList.list[v11].target.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v14 = (idActor *)idEntity::CastTo(c: v13);
    }
    else
    {
      v14 = nullptr;
    }
    v15 = idActor::CastTo(c: v14);
    v16 = v15;
    if ( v15 != nullptr && !v15->IsDead(this: v15) )
    {
      v17 = (int)v16->GetHealthComponent(this: v16);
      if ( v17 != 0 )
      {
        v4 = (float)((float)((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v17 + 68))(a1: v17) + (float)v4);
        ++v9;
      }
    }
    ++v10;
    ++v11;
  }
  while ( v10 < this->targetList.num );
  if ( v9 != 0 )
    v18 = (float)((float)((float)((float)v4 / (float)__SPAIR64__(0x82000000, v9)) + (float)v8) * (float)0.5);
  else
LABEL_21:
    v18 = v8;
  return *((float *)&v18 + 1);
}


// ========================================================================
// ?LowestTargetPlayerHealth@idEncounterGroup@@QBAMXZ
// EA  : 0x82A937C8
// RVA : 0x00A937C8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

float __fastcall idEncounterGroup::LowestTargetPlayerHealth(idEncounterGroup *this)
{
  int v2; // r30
  double v3; // fp31
  int v4; // r31
  idEncounterGroup **list; // r11
  double v6; // fp1
  int v7; // r27
  int v8; // r30
  int value; // r9
  idEntity *v10; // r3
  idPlayer *v11; // r3
  idPlayer *v12; // r3
  idTungstenHealth *p_playerHealth; // r31
  double v14; // fp1

  v2 = 0;
  v3 = 3.4028235e38;
  if ( this->childGroups.num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->childGroups.list;
      if ( list[v4] != nullptr )
      {
        v6 = idEncounterGroup::LowestTargetPlayerHealth(this: list[v4]);
        if ( v6 < v3 )
          v3 = v6;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->childGroups.num );
  }
  v7 = 0;
  if ( this->targetList.num > 0 )
  {
    v8 = 0;
    do
    {
      value = this->targetList.list[v8].target.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v11 = (idPlayer *)idEntity::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      v12 = idPlayer::CastTo(c: v11);
      if ( v12 != nullptr )
      {
        p_playerHealth = &v12->playerHealth;
        if ( ((double (__fastcall *)(idTungstenHealth *))v12->playerHealth.GetCurBaseHealth_Impl)(a1: &v12->playerHealth) < v3 )
          v3 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetCurBaseHealth_Impl)(a1: p_playerHealth);
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->targetList.num );
  }
  v14 = v3;
  return *((float *)&v14 + 1);
}


// ========================================================================
// ?HighestTargetPlayerHealth@idEncounterGroup@@QBAMXZ
// EA  : 0x82A938F8
// RVA : 0x00A938F8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

float __fastcall idEncounterGroup::HighestTargetPlayerHealth(idEncounterGroup *this)
{
  int v2; // r30
  double v3; // fp31
  int v4; // r31
  idEncounterGroup **list; // r11
  double v6; // fp1
  int v7; // r27
  int v8; // r30
  int value; // r9
  idEntity *v10; // r3
  idPlayer *v11; // r3
  idPlayer *v12; // r3
  idTungstenHealth *p_playerHealth; // r31
  double v14; // fp1

  v2 = 0;
  v3 = 1.1754944e-38;
  if ( this->childGroups.num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->childGroups.list;
      if ( list[v4] != nullptr )
      {
        v6 = idEncounterGroup::LowestTargetPlayerHealth(this: list[v4]);
        if ( v6 > v3 )
          v3 = v6;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->childGroups.num );
  }
  v7 = 0;
  if ( this->targetList.num > 0 )
  {
    v8 = 0;
    do
    {
      value = this->targetList.list[v8].target.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v11 = (idPlayer *)idEntity::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      v12 = idPlayer::CastTo(c: v11);
      if ( v12 != nullptr )
      {
        p_playerHealth = &v12->playerHealth;
        if ( ((double (__fastcall *)(idTungstenHealth *))v12->playerHealth.GetCurBaseHealth_Impl)(a1: &v12->playerHealth) > v3 )
          v3 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetCurBaseHealth_Impl)(a1: p_playerHealth);
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->targetList.num );
  }
  v14 = v3;
  return *((float *)&v14 + 1);
}


// ========================================================================
// ?ActiveMemberHighestAlertCycle@idEncounterGroup@@QBA?AW4alertCycle_t@@XZ
// EA  : 0x82A93A28
// RVA : 0x00A93A28
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::ActiveMemberHighestAlertCycle(idEncounterGroup *this)
{
  int v2; // r27
  int v3; // r26
  int v4; // r30
  int value; // r9
  idAI2 *v6; // r3
  idAI2 *v7; // r3
  _DWORD *v8; // r31

  v2 = 1;
  v3 = 0;
  if ( this->members.num > 0 )
  {
    v4 = 0;
    do
    {
      value = this->members.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v6 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v6 != nullptr )
        {
          v7 = idAI2::CastTo(c: v6);
          v8 = &v7->__vftable;
          if ( v7 != nullptr
            && !v7->IsDead(this: v7)
            && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v8) == 0
            && v2 <= v8[14599] )
          {
            v2 = v8[14599];
          }
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->members.num );
  }
  return v2;
}


// ========================================================================
// ?GetRandomMember@idEncounterGroup@@QBAPAVidAI2@@XZ
// EA  : 0x82A93B10
// RVA : 0x00A93B10
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

idAI2 *__fastcall idEncounterGroup::GetRandomMember(idEncounterGroup *this)
{
  signed int num; // r11
  int v2; // r11
  unsigned int seed; // r8
  unsigned int v4; // r4
  int v5; // r9
  unsigned int v6; // r5
  int value; // r9
  idAI2 *v8; // r3

  num = this->members.num;
  if ( num != 0 )
  {
    seed = clientGame->random.seed;
    __twllei(num, 0);
    v4 = 1664525 * seed + 1013904223;
    clientGame->random.seed = v4;
    v5 = (v4 >> 10) & 0x7FFF;
    v6 = num & ~(__ROL4__(v5, 1) - 1);
    v2 = v5 % num;
    __twlgei(v6, 0xFFFFFFFF);
  }
  else
  {
    v2 = 0;
  }
  value = this->members.list[v2].spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idAI2 *)gameLocal->entities.ptr[this->members.list[v2].spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAI2::CastTo(c: v8);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetRandomDeadMember@idEncounterGroup@@QBAPAVidAI2@@XZ
// EA  : 0x82A93BC0
// RVA : 0x00A93BC0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

idAI2 *__fastcall idEncounterGroup::GetRandomDeadMember(idEncounterGroup *this)
{
  signed int num; // r11
  int v3; // r29
  unsigned int seed; // r8
  unsigned int v5; // r4
  int v6; // r3
  signed int v7; // r31
  int value; // r9
  idGameLocal *v9; // r10
  idAI2 *v10; // r3
  idAI2 *v11; // r3
  idAI2 *i; // r30
  signed int v13; // r11
  idEntityPtr<idAI2> *list; // r8
  int v15; // r9
  int v16; // r9

  num = this->members.num;
  if ( num != 0 )
  {
    seed = clientGame->random.seed;
    __twllei(num, 0);
    v5 = 1664525 * seed + 1013904223;
    clientGame->random.seed = v5;
    v6 = (v5 >> 10) & 0x7FFF;
    v3 = v6 % num;
    __twlgei(num & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
  }
  else
  {
    v3 = 0;
  }
  v7 = 0;
  value = this->members.list[v3].spawnId.value;
  v9 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_7;
  v10 = (idAI2 *)gameLocal->entities.ptr[this->members.list[v3].spawnId.value & 0x1FFF];
  if ( v10 == nullptr )
    goto LABEL_7;
LABEL_6:
  v11 = idAI2::CastTo(c: v10);
  v9 = gameLocal;
  for ( i = v11; ; i = nullptr )
  {
    if ( i != nullptr )
    {
      if ( i->IsDead(this: i) )
        return i;
      v9 = gameLocal;
    }
    v13 = this->members.num;
    if ( v7 >= v13 )
      break;
    ++v7;
    list = this->members.list;
    __twllei(v13, 0);
    v15 = __ROL4__(v7 + v3, 1);
    v3 = (v7 + v3) % v13;
    __twlgei(v13 & ~(v15 - 1), 0xFFFFFFFF);
    v16 = list[v3].spawnId.value;
    if ( v9->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13 )
    {
      v10 = (idAI2 *)v9->entities.ptr[v16 & 0x1FFF];
      if ( v10 != nullptr )
        goto LABEL_6;
    }
LABEL_7:
    ;
  }
  return i;
}


// ========================================================================
// ?GetRandomEnemy@idEncounterGroup@@QBAPBVidEntity@@XZ
// EA  : 0x82A93D38
// RVA : 0x00A93D38
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idEntity *__fastcall idEncounterGroup::GetRandomEnemy(idEncounterGroup *this)
{
  signed int num; // r11
  unsigned int v2; // r9
  idEncounterGroup::target_t *list; // r8
  idGameLocal *v4; // r10
  int v5; // r5
  int value; // r4
  idEntity *v7; // r3

  num = this->targetList.num;
  if ( num == 0 )
    return nullptr;
  __twllei(num, 0);
  v2 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v2;
  list = this->targetList.list;
  v4 = gameLocal;
  v5 = (v2 >> 10) & 0x7FFF;
  __twlgei(num & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
  value = list[v5 % num].target.spawnId.value;
  if ( v4->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return nullptr;
  v7 = v4->entities.ptr[value & 0x1FFF];
  if ( v7 != nullptr )
    return idEntity::CastTo(c: v7);
  else
    return nullptr;
}


// ========================================================================
// ?GetTargetedPlayerWithLowestHealth@idEncounterGroup@@QBAPBVidPlayer@@XZ
// EA  : 0x82A93E08
// RVA : 0x00A93E08
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idPlayer *__fastcall idEncounterGroup::GetTargetedPlayerWithLowestHealth(idEncounterGroup *this)
{
  idPlayer *v2; // r25
  int v3; // r27
  double v4; // fp31
  int v5; // r29
  int value; // r9
  idEntity *v7; // r3
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  idPlayer *v10; // r30
  idTungstenHealth *p_playerHealth; // r31

  v2 = nullptr;
  v3 = 0;
  v4 = 3.4028235e38;
  if ( this->targetList.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->targetList.list[v5].target.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idPlayer *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idPlayer::CastTo(c: v8);
      v10 = v9;
      if ( v9 != nullptr )
      {
        p_playerHealth = &v9->playerHealth;
        if ( ((double (__fastcall *)(idTungstenHealth *))v9->playerHealth.GetCurBaseHealth_Impl)(a1: &v9->playerHealth) < v4 )
        {
          v4 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetCurBaseHealth_Impl)(a1: p_playerHealth);
          v2 = v10;
        }
      }
      ++v3;
      ++v5;
    }
    while ( v3 < this->targetList.num );
  }
  return v2;
}


// ========================================================================
// ?GetTargetedPlayerWithHighestHealth@idEncounterGroup@@QBAPBVidPlayer@@XZ
// EA  : 0x82A93EF8
// RVA : 0x00A93EF8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idPlayer *__fastcall idEncounterGroup::GetTargetedPlayerWithHighestHealth(idEncounterGroup *this)
{
  idPlayer *v2; // r25
  int v3; // r27
  double v4; // fp31
  int v5; // r29
  int value; // r9
  idEntity *v7; // r3
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  idPlayer *v10; // r30
  idTungstenHealth *p_playerHealth; // r31

  v2 = nullptr;
  v3 = 0;
  v4 = 1.1754944e-38;
  if ( this->targetList.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->targetList.list[v5].target.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idPlayer *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idPlayer::CastTo(c: v8);
      v10 = v9;
      if ( v9 != nullptr )
      {
        p_playerHealth = &v9->playerHealth;
        if ( ((double (__fastcall *)(idTungstenHealth *))v9->playerHealth.GetCurBaseHealth_Impl)(a1: &v9->playerHealth) > v4 )
        {
          v4 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetCurBaseHealth_Impl)(a1: p_playerHealth);
          v2 = v10;
        }
      }
      ++v3;
      ++v5;
    }
    while ( v3 < this->targetList.num );
  }
  return v2;
}


// ========================================================================
// ?SetPendingCombatStage@idEncounterGroup@@QAA_NHH@Z
// EA  : 0x82A93FE8
// RVA : 0x00A93FE8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::SetPendingCombatStage(idEncounterGroup *this, int i, int delay)
{
  const char *data; // r27
  idCombatStage *v8; // r11
  char *v9; // r31
  int GameMs; // r3

  if ( (i != this->curCombatStage || this->pendingCombatStage != -1) && i != this->pendingCombatStage )
  {
    if ( i >= this->combatStages.num )
      return 0;
    this->pendingCombatStage = i;
    this->pendingCombatStageTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED)
                                 + delay;
    if ( ai_debugLevel.valueInteger != 0 && ai_debugEncounterGroupRoles.valueInteger > 0 )
    {
      data = &byte_8200D768;
      if ( i < this->combatStages.num )
      {
        v8 = &this->combatStages.list[i];
        if ( v8 != nullptr )
          data = v8->name.data;
      }
      v9 = this->groupName.data;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "[%6d] group: %-20s pending combat stage %d:%-10s with delay %d\n", GameMs, v9, i, data, delay);
    }
  }
  return 1;
}


// ========================================================================
// ?MemberKilled@idEncounterGroup@@QAAXPAVidAI2@@PBVidEntity@@1@Z
// EA  : 0x82A94368
// RVA : 0x00A94368
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::MemberKilled(
        idEncounterGroup *this,
        idAI2 *ai,
        const idEntity *attacker,
        const idEntity *inflictor)
{
  int v13; // r23
  int v14; // r27
  idGameLocal *v15; // r10
  int value; // r9
  idAI2 *v17; // r3
  idAI2 *v18; // r3
  idAI2 *v19; // r31
  idAIEntityState *v20; // r3
  idPhysics *Physics; // r30
  int GameMs; // r29
  idPhysics *v23; // r3
  const idDeclAIBehaviorEvents *declBehaviorEvents; // r28
  idAIEventManager *p_aiEventManager; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v27; // r3
  idAIEventManager v28; // [sp+50h] [-70h] BYREF

  ++this->numDeadMembers;
  if ( ai->aiVolatile.memory.killedHeavily )
  {
    _FP12 = (float)((float)2.0 - (float)(this->recentlyKilledMembers + (float)1.0));
    __asm { fsel      f11, f12, f13, f31 }
    this->recentHeavilyKilledMembers = _FP11;
  }
  _FP12 = (float)((float)2.0 - (float)(this->recentlyKilledMembers + (float)1.0));
  __asm { fsel      f11, f12, f13, f31 }
  this->recentlyKilledMembers = _FP11;
  if ( ((double (__fastcall *)(idAIHealth *))ai->aiHealth.GetMaxBaseHealth_Impl)(a1: &ai->aiHealth) > 200.0 )
  {
    _FP12 = (float)((float)2.0 - (float)(this->recentlyKilledHeavies + (float)1.0));
    __asm { fsel      f11, f12, f13, f31 }
    this->recentlyKilledHeavies = _FP11;
  }
  v13 = 0;
  if ( this->members.num > 0 )
  {
    v14 = 0;
    v15 = gameLocal;
    do
    {
      value = this->members.list[v14].spawnId.value;
      if ( v15->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v17 = (idAI2 *)v15->entities.ptr[value & 0x1FFF];
        if ( v17 != nullptr )
        {
          v18 = idAI2::CastTo(c: v17);
          v19 = v18;
          if ( v18 != nullptr
            && v18 != ai
            && !v18->IsDead(this: v18)
            && !idAI2::IsPlayerControlled(this: v19)
            && !idAI2::ActionScriptFlagIsSet(this: v19, flags: 8)
            && idAI2::GetAlertCycle(this: v19) == ALERTCYCLE_COMBAT )
          {
            v20 = idAIWorldState::StateForEntity(this: &v19->aiVolatile.world.worldState, ent: ai);
            if ( v20 != nullptr
              && v20->senses.ptr[1]->lastUnconfirmedStimTime >= 0
              && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
               - v20->senses.ptr[1]->lastConfirmedStimTime < 1000
              && ai->aiEditable.behaviors.declBehaviorEvents != nullptr )
            {
              Physics = idEntity::GetPhysics(this: v19);
              GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              v23 = Physics;
              declBehaviorEvents = ai->aiEditable.behaviors.declBehaviorEvents;
              GetOrigin = Physics->GetOrigin;
              p_aiEventManager = &gameLocal->aiEventManager;
              v27 = GetOrigin(this: v23, a2: 0);
              idAIEventManager::AddEvent(
                this: &v28,
                result: p_aiEventManager,
                eventDecl: declBehaviorEvents->memberKilledVoiceEventDecl,
                curTime: GameMs,
                originator: v19,
                instigator: attacker,
                origin: v27,
                delay: 700);
              return;
            }
          }
          v15 = gameLocal;
        }
      }
      ++v13;
      ++v14;
    }
    while ( v13 < this->members.num );
  }
}


// ========================================================================
// ?InitGroupAmbush@idEncounterGroup@@QAAXPBVidEntity@@0@Z
// EA  : 0x82A945E8
// RVA : 0x00A945E8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::InitGroupAmbush(idEncounterGroup *this, idEntity *enemy, idEntity *ambushTarget)
{
  int v6; // r28
  int v7; // r30
  int value; // r9
  idAI2 *v9; // r3
  idAI2 *v10; // r3
  idAI2 *v11; // r31
  bfx::BinaryReplayLogOut v12[2]; // [sp+50h] [-50h] BYREF

  v6 = 0;
  if ( this->members.num > 0 )
  {
    v7 = 0;
    do
    {
      value = this->members.list[v7].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v9 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v10 = idAI2::CastTo(c: v9);
      }
      else
      {
        v10 = nullptr;
      }
      v11 = idAI2::CastTo(c: v10);
      if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v11) == 0 && !v11->IsDead(this: v11) )
      {
        idAI2::PrepTakeCoverFromEntity(
          this: (idAI2 *)v12,
          result: v11,
          enemy,
          coverReference: nullptr,
          coverTarget: ambushTarget);
        idPhysics_StaticMulti::UpdateTime(this: v12);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->members.num );
  }
}


// ========================================================================
// ?UpdateGroupAmbush@idEncounterGroup@@QAAXPBVidEntity@@ABVidVec3@@@Z
// EA  : 0x82A946D8
// RVA : 0x00A946D8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::UpdateGroupAmbush(
        idEncounterGroup *this,
        idEntity *groupMember,
        const idVec3 *enemyPos)
{
  idGameLocal *v6; // r11
  idEntity *v7; // r3
  idEntity *v8; // r3
  int value; // r9
  idEntity *v10; // r3
  idPhysics *Physics; // r31
  idPhysics *v12; // r27
  float *v13; // r31
  float *v14; // r3
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  idPhysics *v18; // r3
  float *v19; // r3
  double v20; // fp1
  double v21; // fp13

  if ( this->shouldAmbush )
  {
    v6 = gameLocal;
    if ( gameLocal->spawnIds.ptr[this->ownGroupAlertState.target.spawnId.value & 0x1FFF] == this->ownGroupAlertState.target.spawnId.value >> 13
      && (v7 = gameLocal->entities.ptr[this->ownGroupAlertState.target.spawnId.value & 0x1FFF]) != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
      v6 = gameLocal;
    }
    else
    {
      v8 = nullptr;
    }
    if ( v8 != nullptr
      || ((value = this->otherGroupAlertState.target.spawnId.value, v6->spawnIds.ptr[value & 0x1FFF] != value >> 13)
       || (v10 = v6->entities.ptr[value & 0x1FFF]) == nullptr
        ? (v8 = nullptr)
        : (v8 = idEntity::CastTo(c: v10)),
          v8 != nullptr) )
    {
      Physics = idEntity::GetPhysics(this: v8);
      v12 = idEntity::GetPhysics(this: groupMember);
      v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v14 = (float *)v12->GetOrigin(this: v12, a2: 0);
      v15 = (float)(*v14 - *v13);
      v16 = (float)(v14[1] - v13[1]);
      v17 = (float)(v14[2] - v13[2]);
      v18 = idEntity::GetPhysics(this: groupMember);
      v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
      v20 = (float)(v19[2] - enemyPos->z);
      v21 = (float)(v19[1] - enemyPos->y);
      if ( (float)((float)((float)v21 * (float)v21)
                 + (float)((float)((float)v20 * (float)v20)
                         + (float)((float)(*v19 - enemyPos->x) * (float)(*v19 - enemyPos->x)))) < (double)(float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) )
        this->shouldAmbush = false;
    }
  }
}


// ========================================================================
// ?FindSpeaker@idEncounterGroup@@QBAPAVidAI2@@PBVidEntity@@_N1PBV2@@Z
// EA  : 0x82A94890
// RVA : 0x00A94890
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

idAI2 *__fastcall idEncounterGroup::FindSpeaker(
        idEncounterGroup *this,
        const idEntity *enemy,
        const bool mustBeNearLastVisPos,
        const bool mustBeVisible,
        const idAI2 *excludeAI)
{
  double v9; // fp31
  idAI2 *v11; // r27
  char v12; // r25
  int v13; // r23
  int v14; // r24
  int value; // r9
  idAI2 *v16; // r3
  idAI2 *v17; // r3
  idAI2 *v18; // r31
  int v19; // r30
  idAIEntityState *v20; // r3
  idAIEntityState *v21; // r30
  aiSenseState_t *v22; // r29
  idPhysics *v23; // r3
  float *v24; // r16
  float *v25; // r3
  double v26; // fp8
  double v27; // fp6
  double v28; // fp4
  double v29; // fp3
  idPhysics *Physics; // r3
  float *v31; // r30
  float *v32; // r3
  double v33; // fp10
  double v34; // fp8
  double v35; // fp6
  int v36; // r3

  v9 = 0.0;
  v11 = nullptr;
  v12 = 0;
  v13 = 0;
  if ( this->members.num > 0 )
  {
    v14 = 0;
    do
    {
      value = this->members.list[v14].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v16 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v16 != nullptr )
        {
          v17 = idAI2::CastTo(c: v16);
          v18 = v17;
          if ( v17 != nullptr
            && !v17->IsDead(this: v17)
            && !v18->IsDying(this: v18)
            && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v18) == 0
            && !idAI2::IsPlayerControlled(this: v18)
            && v18 != excludeAI )
          {
            v19 = v18->aiVolatile.voiceController.nextVoiceTime.value;
            if ( v19 <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
              && !idAI2::ActionScriptFlagIsSet(this: v18, flags: 8) )
            {
              v20 = idAIWorldState::StateForEntity(this: &v18->aiVolatile.world.worldState, ent: enemy);
              v21 = v20;
              if ( v20 != nullptr && (*((_BYTE *)v20 + 541) & 0x80) != 0 )
              {
                v22 = v20->senses.ptr[1];
                if ( v22->lastUnconfirmedStimTime >= 0 )
                {
                  if ( !mustBeNearLastVisPos
                    || (v23 = idEntity::GetPhysics(this: v18),
                        v24 = (float *)v21->senses.ptr[v21->lastSense],
                        v25 = (float *)v23->GetOrigin(this: v23, a2: 0),
                        v26 = (float)(v24[50] - v25[1]),
                        v27 = (float)(v24[51] - v25[2]),
                        v28 = (float)(v24[49] - *v25),
                        v29 = (float)((float)(UNITS_PER_INCH_6 * (float)5.0) * (float)12.0),
                        (float)((float)((float)v28 * (float)v28)
                              + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) <= (double)(float)((float)v29 * (float)v29)) )
                  {
                    if ( (!mustBeVisible
                       || gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v22->lastConfirmedStimTime < 5000)
                      && (v12 == 0
                       || gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v22->lastConfirmedStimTime < 1000) )
                    {
                      Physics = idEntity::GetPhysics(this: v18);
                      v31 = (float *)v21->senses.ptr[v21->lastSense];
                      v32 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
                      v33 = (float)(v32[1] - v31[50]);
                      v34 = (float)(v32[2] - v31[51]);
                      v35 = (float)(*v32 - v31[49]);
                      if ( v11 == nullptr
                        || (float)((float)((float)v35 * (float)v35)
                                 + (float)((float)((float)v34 * (float)v34) + (float)((float)v33 * (float)v33))) < v9 )
                      {
                        v9 = (float)((float)((float)v35 * (float)v35)
                                   + (float)((float)((float)v34 * (float)v34) + (float)((float)v33 * (float)v33)));
                        v11 = v18;
                        v36 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
                        v12 = ((v36 - v22->lastConfirmedStimTime >= 0)
                             + ((unsigned int)(v36 - v22->lastConfirmedStimTime) >= 0x3E8))
                            & 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      ++v13;
      ++v14;
    }
    while ( v13 < this->members.num );
  }
  return v11;
}


// ========================================================================
// ?SetPendingCombatStageByName@idEncounterGroup@@QAA_NABVidStr@@H@Z
// EA  : 0x82A94BF0
// RVA : 0x00A94BF0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::SetPendingCombatStageByName(idEncounterGroup *this, const idStr *name, int delay)
{
  int v6; // r29
  int i; // r30

  v6 = 0;
  if ( this->combatStages.num <= 0 )
    return 0;
  for ( i = 0; idStr::Cmp(s1: this->combatStages.list[i].name.data, s2: name->data) != 0; ++i )
  {
    if ( ++v6 >= this->combatStages.num )
      return 0;
  }
  return idEncounterGroup::SetPendingCombatStage(this, i: v6, delay);
}


// ========================================================================
// ?SuggestEncounterGroupRole@idEncounterGroup@@QAA_NPAVidAI2@@W4encounterGroupRole_t@@W4combatStage_t@idCombatStage@@_N3@Z
// EA  : 0x82A94C78
// RVA : 0x00A94C78
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::SuggestEncounterGroupRole(
        idEncounterGroup *this,
        idAI2 *ai,
        encounterGroupRole_t role,
        const idCombatStage::combatStage_t combatStageChange,
        int previouslyPlayedOrderVo,
        const bool alreadyInHintNode)
{
  idAI2::idAIVolatile::idAIGroupStatus *p_groupStatus; // r26
  encounterGroupRole_t *p_pendingRole; // r11
  voChainState_t voChainCategory; // r18
  voChainState_t voChainState; // r16
  encounterGroupRole_t currentRole; // r19
  encounterGroupRole_t pendingRole; // r15
  char v16; // r14
  int v17; // r20
  int v18; // r24
  int v19; // r25
  int value; // r8
  idEntity *v21; // r3
  idEntity *v22; // r4
  const idEntity *Enemy; // r3
  idAI2 *Speaker; // r30
  idEntity *v25; // r3
  encounterGroupRole_t v26; // r30
  idAICombatHint::combatHintType_t v27; // r3
  __int64 v28; // r6
  const idColor *v29; // r3
  __int64 v30; // r8
  __int64 v31; // r10
  va *v32; // r3
  __int64 v33; // r8
  __int64 v34; // r8
  __int64 v35; // r6
  __int64 v36; // r10
  __int64 v37; // r6
  va *v38; // r3
  char *data; // r26
  char *v40; // r22
  const char *v41; // r30
  int v42; // r3
  __int64 v43; // r10
  __int64 v44; // r6
  va *v45; // r3
  __int64 v46; // r8
  __int64 v47; // r10
  __int64 v48; // r6
  va *v49; // r3
  idPhysics *Physics; // r30
  idRenderWorld *v51; // r29
  idPhysics *v52; // r3
  char *v53; // r28
  idRenderWorld_vtbl *v54; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v56; // r3
  int v58; // [sp+8h] [-1128h]
  int v59; // [sp+8h] [-1128h]
  int v60; // [sp+8h] [-1128h]
  int v61; // [sp+Ch] [-1124h]
  int v62; // [sp+Ch] [-1124h]
  int v63; // [sp+Ch] [-1124h]
  int v64; // [sp+10h] [-1120h]
  int v65; // [sp+10h] [-1120h]
  int v66; // [sp+10h] [-1120h]
  int v67; // [sp+14h] [-111Ch]
  int v68; // [sp+14h] [-111Ch]
  int v69; // [sp+14h] [-111Ch]
  int v70; // [sp+18h] [-1118h]
  int v71; // [sp+18h] [-1118h]
  int v72; // [sp+18h] [-1118h]
  int v73; // [sp+1Ch] [-1114h]
  int v74; // [sp+1Ch] [-1114h]
  int v75; // [sp+1Ch] [-1114h]
  idStr v76; // [sp+60h] [-10D0h] BYREF
  _DWORD v77[4]; // [sp+80h] [-10B0h] BYREF
  va v78; // [sp+90h] [-10A0h] BYREF

  p_groupStatus = &ai->aiVolatile.groupStatus;
  p_pendingRole = &ai->aiVolatile.groupStatus.pendingRole;
  voChainCategory = ai->aiVolatile.groupStatus.voChainCategory;
  voChainState = ai->aiVolatile.groupStatus.voChainState;
  currentRole = ai->aiVolatile.groupStatus.currentRole;
  pendingRole = ai->aiVolatile.groupStatus.pendingRole;
  v16 = previouslyPlayedOrderVo;
  v17 = previouslyPlayedOrderVo;
  v18 = voChainCategory;
  v19 = voChainState;
  if ( combatStageChange != COMBAT_STAGE_MAX )
  {
    *p_pendingRole = ROLE_NONE;
    v18 = 0;
    v19 = 0;
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v21 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v22 = idEntity::CastTo(c: v21);
    }
    else
    {
      v22 = nullptr;
    }
    idEncounterGroup::FindSpeaker(this, enemy: v22, mustBeNearLastVisPos: false, mustBeVisible: false, excludeAI: ai);
    switch ( combatStageChange )
    {
      case COMBAT_STAGE_ADVANCE:
        v17 = 0;
        break;
      case COMBAT_STAGE_NO_GOODWILL:
      case COMBAT_STAGE_DEFAULT:
LABEL_82:
        break;
      case COMBAT_STAGE_FALLBACK:
        v17 = 0;
        break;
      case COMBAT_STAGE_RETREAT:
        v17 = 0;
        break;
      default:
        goto LABEL_82;
    }
LABEL_52:
    if ( role != ROLE_NONE )
      goto LABEL_56;
    goto LABEL_53;
  }
  if ( role != ROLE_NONE )
  {
    if ( role == currentRole || role == pendingRole )
    {
      Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
      Speaker = idEncounterGroup::FindSpeaker(
                  this,
                  enemy: Enemy,
                  mustBeNearLastVisPos: false,
                  mustBeVisible: false,
                  excludeAI: ai);
      if ( Speaker == nullptr )
        Speaker = ai;
      switch ( voChainCategory )
      {
        case VOCHAIN_ORDER_STAGE_ADVANCE:
          v17 = 0;
          break;
        case VOCHAIN_ORDER_STAGE_RETREAT:
          v17 = 0;
          break;
        case VOCHAIN_ORDER_STAGE_FALLBACK:
          v17 = 0;
          break;
        case VOCHAIN_ORDER_ASSAULT:
          v17 = 0;
          break;
        case VOCHAIN_ORDER_FLANK:
          v17 = 0;
          break;
        case VOCHAIN_ORDER_DEFEND:
          v17 = 0;
          break;
        case VOCHAIN_ORDER_CHARGE:
          v17 = 0;
          break;
        case VOCHAIN_ORDER_GRENADE:
          switch ( voChainState )
          {
            case VOCHAIN_DELAYED_VO:
              v19 = idAI2::idAIVolatile::idAIGroupStatus::GetPreventativeCondition(this: p_groupStatus, mask: 4) == CONDITION_NONE
                  ? 8
                  : 20;
              break;
            case VOCHAIN_RESPOND_CANT_SEE:
              v19 = 26;
              break;
            case VOCHAIN_RESPOND_ENEMY_LOCATION:
              if ( Speaker != ai )
              {
                v25 = (idEntity *)idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
                idAI2::LocationCallingHelper(this: Speaker, ent: v25);
              }
              v19 = 8;
              break;
            default:
              break;
          }
          break;
        default:
          break;
      }
    }
    else
    {
      switch ( role )
      {
        case ROLE_ASSAULT:
          v18 = 5;
          v19 = 28;
          *p_pendingRole = ROLE_ASSAULT;
          goto LABEL_56;
        case ROLE_FLANK:
          v18 = 7;
          v19 = 28;
          *p_pendingRole = ROLE_FLANK;
          goto LABEL_56;
        case ROLE_DEFEND:
          v18 = 6;
          *p_pendingRole = ROLE_DEFEND;
          v19 = 28;
          goto LABEL_56;
        case ROLE_CHARGE:
          v18 = 4;
          v19 = 28;
          *p_pendingRole = ROLE_CHARGE;
          goto LABEL_56;
        case ROLE_THROW:
          p_groupStatus->currentRole = ROLE_THROW;
LABEL_55:
          p_groupStatus->pendingRole = ROLE_NONE;
          p_groupStatus->roleChangeResponseRequired = true;
          goto LABEL_56;
        default:
          break;
      }
    }
    goto LABEL_52;
  }
LABEL_53:
  if ( currentRole != ROLE_NONE )
  {
    p_groupStatus->currentRole = role;
    goto LABEL_55;
  }
LABEL_56:
  p_groupStatus->voChainState = v19;
  p_groupStatus->voChainCategory = v18;
  if ( ai_debugEncounterGroupRoles.valueInteger > 0 && ai_debugLevel.valueInteger > 0 )
  {
    v26 = p_groupStatus->currentRole;
    v76.len = 0;
    v76.allocedAndFlag = 20;
    v76.data = v76.baseBuffer;
    v76.baseBuffer[0] = 0;
    switch ( v26 )
    {
      case ROLE_DEFEND:
        v27 = COMBAT_HINT_DEFENSE_POINT;
        break;
      case ROLE_ASSAULT:
        v27 = COMBAT_HINT_ASSAULT_POINT;
        break;
      case ROLE_FLANK:
        v27 = COMBAT_HINT_FLANK_POINT;
        break;
      default:
        v27 = COMBAT_HINT_MAX;
        break;
    }
    v29 = idAICombatHint::HintTypeColor(hintType: v27);
    v77[0] = LODWORD(v29->r);
    v77[1] = LODWORD(v29->g);
    LODWORD(v30) = LODWORD(v29->b);
    v77[2] = v30;
    *(float *)&v30 = v29->a;
    v77[3] = HIDWORD(v30);
    if ( currentRole == v26 )
    {
      HIDWORD(v31) = encounterGroupRoleNames;
      if ( pendingRole != ROLE_NONE )
      {
        LODWORD(v31) = 4 * pendingRole;
        LODWORD(v34) = 4 * v26;
        HIDWORD(v34) = "1 - formation cover, such as behind regime shield units";
        LODWORD(v35) = encounterGroupRoleNames[pendingRole];
        HIDWORD(v35) = encounterGroupRoleNames[v26];
        v32 = va::va(
                this: &v78,
                fmt: "%s->(%s)\n",
                a3: v35,
                a4: v34,
                a5: v31,
                a6: v58,
                a7: v61,
                a8: v64,
                a9: v67,
                a10: v70,
                a11: v73);
      }
      else
      {
        LODWORD(v31) = 4 * v26;
        LODWORD(v30) = &unk_821C0000;
        HIDWORD(v28) = encounterGroupRoleNames[v26];
        v32 = va::va(
                this: &v78,
                fmt: "%s\n",
                a3: v28,
                a4: v30,
                a5: v31,
                a6: v58,
                a7: v61,
                a8: v64,
                a9: v67,
                a10: v70,
                a11: v73);
      }
      idStr::Append(this: &v76, text: v32);
    }
    else
    {
      LODWORD(v36) = 4 * currentRole;
      HIDWORD(v36) = "1 - formation cover, such as behind regime shield units";
      LODWORD(v37) = encounterGroupRoleNames[v26];
      HIDWORD(v37) = encounterGroupRoleNames[currentRole];
      v38 = va::va(
              this: &v78,
              fmt: "%s->%s\n",
              a3: v37,
              a4: v30,
              a5: v36,
              a6: v58,
              a7: v61,
              a8: v64,
              a9: v67,
              a10: v70,
              a11: v73);
      idStr::Append(this: &v76, text: v38);
      data = ai->name.data;
      v40 = this->groupName.data;
      v41 = encounterGroupRoleNames[v26];
      v42 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idLib::Printf(fmt: "[%6d] role:  %-20s group: %-20s ai: %-40s\n", v42, v41, v40, data);
    }
    if ( ai_debugEncounterGroupRoles.valueInteger >= 2 )
    {
      LODWORD(v43) = 4 * voChainState;
      HIDWORD(v43) = 4 * voChainCategory;
      LODWORD(v33) = "1 - formation cover, such as behind regime shield units";
      LODWORD(v44) = voChainStateNames[voChainState];
      HIDWORD(v44) = voChainStateNames[voChainCategory];
      v45 = va::va(
              this: &v78,
              fmt: "%s:%s",
              a3: v44,
              a4: v33,
              a5: v43,
              a6: v59,
              a7: v62,
              a8: v65,
              a9: v68,
              a10: v71,
              a11: v74);
      idStr::Append(this: &v76, text: v45);
      if ( voChainCategory != v18 || voChainState != v19 )
      {
        LODWORD(v47) = 4 * v18;
        HIDWORD(v47) = "1 - formation cover, such as behind regime shield units";
        LODWORD(v48) = voChainStateNames[v19];
        HIDWORD(v48) = voChainStateNames[v18];
        v49 = va::va(
                this: &v78,
                fmt: "->%s:%s",
                a3: v48,
                a4: v46,
                a5: v47,
                a6: v60,
                a7: v63,
                a8: v66,
                a9: v69,
                a10: v72,
                a11: v75);
        idStr::Append(this: &v76, text: v49);
      }
      if ( v16 == 0 && (_BYTE)v17 != 0 )
        idStr::Append(this: &v76, text: " (*)");
    }
    Physics = idEntity::GetPhysics(this: ai);
    v51 = common->RW(this: common);
    v52 = Physics;
    v53 = v76.data;
    GetOrigin = Physics->GetOrigin;
    v54 = v51->__vftable;
    v56 = (int)GetOrigin(this: v52, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, char *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), _DWORD *, int, int, _DWORD, double))v54->DebugText)(
      a1: v51,
      a2: v53,
      a3: v56,
      a4: &off_82040000,
      a5: v77,
      a6: 1,
      a7: 2048,
      a8: 0,
      a9: 0.30000001);
    idStr::FreeData(this: &v76);
  }
  return v17;
}


// ========================================================================
// __unwind$496900
// EA  : 0x82A95218
// RVA : 0x00A95218
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_496900()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 96));
}


// ========================================================================
// ?GetHintWeight@idCombatStage@@QBAMW4combatHintType_t@idAICombatHint@@ABVidVec3@@W4combatHintClass_t@3@@Z
// EA  : 0x82A95240
// RVA : 0x00A95240
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

float __fastcall idCombatStage::GetHintWeight(
        idCombatStage *this,
        unsigned int hintType,
        const idVec3 *pos,
        const idAICombatHint::combatHintClass_t hintClass)
{
  int value; // r10
  idAIHintGroup *v9; // r3
  double v10; // fp1
  const idList<int,5> *NodesListByHintType; // r3
  const idList<int,5> *v12; // r30
  int v14; // r26
  int v15; // r28
  int v16; // r9
  idGameLocal *v17; // r11
  int *list; // r31
  idAIHintGroup *v19; // r3
  idAIHintGroup *v20; // r3
  int v21; // r10
  int v22; // r9
  idEntity *v23; // r3
  idAICombatHint *v24; // r3
  idAICombatHint *v25; // r3

  value = this->hintGroup.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idAIHintGroup *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idAIHintGroup::CastTo(c: v9) != nullptr
    && (NodesListByHintType = idCombatStage::GetNodesListByHintType(this, hintType),
        v12 = NodesListByHintType,
        NodesListByHintType != nullptr) )
  {
    _FP31 = 0.0;
    v14 = 0;
    if ( NodesListByHintType->num > 0 )
    {
      v15 = 0;
      do
      {
        v16 = this->hintGroup.spawnId.value;
        v17 = gameLocal;
        list = v12->list;
        if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
          && (v19 = (idAIHintGroup *)gameLocal->entities.ptr[v16 & 0x1FFF]) != nullptr )
        {
          v20 = idAIHintGroup::CastTo(c: v19);
          v17 = gameLocal;
        }
        else
        {
          v20 = nullptr;
        }
        v21 = list[v15];
        if ( v21 < v20->targets.num
          && (v22 = v20->targets.list[v21].spawnId.value, v17->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13)
          && (v23 = v17->entities.ptr[v20->targets.list[v21].spawnId.value & 0x1FFF]) != nullptr )
        {
          v24 = (idAICombatHint *)idEntity::CastTo(c: v23);
        }
        else
        {
          v24 = nullptr;
        }
        v25 = idAICombatHint::CastTo(c: v24);
        if ( v25 != nullptr && (v25->hintClass & hintClass) != 0 )
        {
          _FP0 = (float)((float)_FP31 - idAICombatHint::GetPointWeight(this: v25, point: pos));
          __asm { fsel      f31, f0, f31, f1 }
        }
        ++v14;
        ++v15;
      }
      while ( v14 < v12->num );
    }
    v10 = _FP31;
  }
  else
  {
    v10 = 0.0;
  }
  return *((float *)&v10 + 1);
}


// ========================================================================
// ?GetCombatHintEntity@idCombatStage@@QBAPBVidAICombatHint@@W4combatHintType_t@2@H@Z
// EA  : 0x82A953E8
// RVA : 0x00A953E8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idAICombatHint *__fastcall idCombatStage::GetCombatHintEntity(
        idCombatStage *this,
        unsigned int hintType,
        int index)
{
  int value; // r10
  idEntityPtr<idAIHintGroup> *p_hintGroup; // r30
  idAIHintGroup *v8; // r3
  const idList<int,5> *NodesListByHintType; // r3
  int v11; // r31
  idAIHintGroup *v12; // r3
  idAICombatHint *Target; // r3

  value = this->hintGroup.spawnId.value;
  p_hintGroup = &this->hintGroup;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return nullptr;
  v8 = (idAIHintGroup *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return nullptr;
  if ( idAIHintGroup::CastTo(c: v8) == nullptr )
    return nullptr;
  NodesListByHintType = idCombatStage::GetNodesListByHintType(this, hintType);
  if ( NodesListByHintType == nullptr || index >= NodesListByHintType->num )
    return nullptr;
  v11 = NodesListByHintType->list[index];
  v12 = idEntityPtr<idAIHintGroup>::operator->(this: p_hintGroup);
  Target = (idAICombatHint *)idEntity::GetTarget(this: v12, i: v11);
  return idAICombatHint::CastTo(c: Target);
}


// ========================================================================
// ?GetClosestHintNodePos@idCombatStage@@QBA_NW4combatHintType_t@idAICombatHint@@ABVidVec3@@AAV4@W4combatHintClass_t@3@@Z
// EA  : 0x82A954A0
// RVA : 0x00A954A0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idCombatStage::GetClosestHintNodePos(
        idCombatStage *this,
        unsigned int hintType,
        const idVec3 *currentPos,
        idVec3 *outPos,
        const idAICombatHint::combatHintClass_t hintClass)
{
  int value; // r10
  idAIHintGroup *v11; // r3
  const idList<int,5> *NodesListByHintType; // r3
  const idList<int,5> *v14; // r28
  int v15; // r24
  int v16; // r23
  double v17; // fp30
  int v18; // r25
  int v19; // r10
  int *list; // r31
  idAIHintGroup *v21; // r3
  idAIHintGroup *v22; // r3
  int v23; // r11
  int v24; // r8
  idEntity *v25; // r3
  idAICombatHint *v26; // r31
  idAICombatHint *v27; // r3
  idEntity *v28; // r30
  idPhysics *Physics; // r3
  float *v30; // r3
  double v31; // fp10
  double v32; // fp6
  double v33; // fp31
  idPhysics *v34; // r3
  float *v35; // r3

  value = this->hintGroup.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v11 = (idAIHintGroup *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v11 == nullptr )
    return 0;
  if ( idAIHintGroup::CastTo(c: v11) == nullptr )
    return 0;
  *outPos = vec3_origin;
  NodesListByHintType = idCombatStage::GetNodesListByHintType(this, hintType);
  v14 = NodesListByHintType;
  if ( NodesListByHintType == nullptr )
    return 0;
  v15 = 0;
  v16 = 0;
  v17 = 0.0;
  if ( NodesListByHintType->num > 0 )
  {
    v18 = 0;
    do
    {
      v19 = this->hintGroup.spawnId.value;
      list = v14->list;
      if ( gameLocal->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13
        && (v21 = (idAIHintGroup *)gameLocal->entities.ptr[v19 & 0x1FFF]) != nullptr )
      {
        v22 = idAIHintGroup::CastTo(c: v21);
      }
      else
      {
        v22 = nullptr;
      }
      v23 = list[v18];
      if ( v23 < v22->targets.num
        && (v24 = v22->targets.list[v23].spawnId.value, gameLocal->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13)
        && (v25 = gameLocal->entities.ptr[v22->targets.list[v23].spawnId.value & 0x1FFF]) != nullptr )
      {
        v26 = (idAICombatHint *)idEntity::CastTo(c: v25);
      }
      else
      {
        v26 = nullptr;
      }
      if ( v26 != nullptr )
      {
        v27 = idAICombatHint::CastTo(c: v26);
        v28 = v27;
        if ( v27 != nullptr )
        {
          if ( (v27->hintClass & hintClass) != 0 )
          {
            Physics = idEntity::GetPhysics(this: v27);
            v30 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v31 = (float)(currentPos->z - v30[2]);
            v32 = (float)(currentPos->y - v30[1]);
            v33 = (float)((float)((float)v32 * (float)v32)
                        + (float)((float)((float)(currentPos->x - *v30) * (float)(currentPos->x - *v30))
                                + (float)((float)v31 * (float)v31)));
            if ( (_BYTE)v15 == 0 || v33 < v17 )
            {
              v15 = 1;
              v34 = idEntity::GetPhysics(this: v28);
              v35 = (float *)v34->GetOrigin(this: v34, a2: 0);
              v17 = v33;
              outPos->x = *v35;
              outPos->y = v35[1];
              outPos->z = v35[2];
            }
          }
        }
        else
        {
          idLib::Warning(
            fmt: "Combat stage '%s' has an invalid entity '%s' in its combat hint list",
            this->name.data,
            v26->name.data);
        }
      }
      ++v16;
      ++v18;
    }
    while ( v16 < v14->num );
  }
  return v15;
}


// ========================================================================
// ?GetClosestHintNodePtr@idCombatStage@@QBAPBVidAICombatHint@@W4combatHintType_t@2@ABVidVec3@@W4combatHintClass_t@2@@Z
// EA  : 0x82A95738
// RVA : 0x00A95738
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idAICombatHint *__fastcall idCombatStage::GetClosestHintNodePtr(
        idCombatStage *this,
        unsigned int hintType,
        const idVec3 *currentPos,
        const idAICombatHint::combatHintClass_t hintClass)
{
  int value; // r10
  idAIHintGroup *v9; // r3
  const idList<int,5> *NodesListByHintType; // r3
  const idList<int,5> *v12; // r28
  idEntity *v13; // r22
  int v14; // r24
  double v15; // fp31
  int v16; // r26
  int v17; // r10
  int *list; // r31
  idAIHintGroup *v19; // r3
  idAIHintGroup *v20; // r3
  int v21; // r11
  int v22; // r8
  idEntity *v23; // r3
  idAICombatHint *v24; // r30
  idAICombatHint *v25; // r3
  idEntity *v26; // r31
  int dontUseUntil; // r30
  idPhysics *Physics; // r3
  float *v29; // r3
  double v30; // fp10
  double v31; // fp6

  value = this->hintGroup.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return nullptr;
  v9 = (idAIHintGroup *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v9 == nullptr )
    return nullptr;
  if ( idAIHintGroup::CastTo(c: v9) == nullptr )
    return nullptr;
  NodesListByHintType = idCombatStage::GetNodesListByHintType(this, hintType);
  v12 = NodesListByHintType;
  if ( NodesListByHintType == nullptr )
    return nullptr;
  v13 = nullptr;
  v14 = 0;
  v15 = 0.0;
  if ( NodesListByHintType->num > 0 )
  {
    v16 = 0;
    do
    {
      v17 = this->hintGroup.spawnId.value;
      list = v12->list;
      if ( gameLocal->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
        && (v19 = (idAIHintGroup *)gameLocal->entities.ptr[v17 & 0x1FFF]) != nullptr )
      {
        v20 = idAIHintGroup::CastTo(c: v19);
      }
      else
      {
        v20 = nullptr;
      }
      v21 = list[v16];
      if ( v21 < v20->targets.num
        && (v22 = v20->targets.list[v21].spawnId.value, gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13)
        && (v23 = gameLocal->entities.ptr[v20->targets.list[v21].spawnId.value & 0x1FFF]) != nullptr )
      {
        v24 = (idAICombatHint *)idEntity::CastTo(c: v23);
      }
      else
      {
        v24 = nullptr;
      }
      if ( v24 != nullptr )
      {
        v25 = idAICombatHint::CastTo(c: v24);
        v26 = v25;
        if ( v25 != nullptr )
        {
          if ( (v25->hintClass & hintClass) != 0 )
          {
            dontUseUntil = v25->dontUseUntil;
            if ( dontUseUntil <= idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
            {
              Physics = idEntity::GetPhysics(this: v26);
              v29 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              v30 = (float)(currentPos->z - v29[2]);
              v31 = (float)(currentPos->y - v29[1]);
              if ( v13 == nullptr
                || (float)((float)((float)v31 * (float)v31)
                         + (float)((float)((float)(currentPos->x - *v29) * (float)(currentPos->x - *v29))
                                 + (float)((float)v30 * (float)v30))) < v15 )
              {
                v13 = v26;
                v15 = (float)((float)((float)v31 * (float)v31)
                            + (float)((float)((float)(currentPos->x - *v29) * (float)(currentPos->x - *v29))
                                    + (float)((float)v30 * (float)v30)));
              }
            }
          }
        }
        else
        {
          idLib::Warning(
            fmt: "Combat stage '%s' has an invalid entity '%s' in its combat hint list",
            this->name.data,
            v24->name.data);
        }
      }
      ++v14;
      ++v16;
    }
    while ( v14 < v12->num );
  }
  return (const idAICombatHint *)v13;
}


// ========================================================================
// ?GetContainingHintNodePtr@idCombatStage@@QAAPAVidAICombatHint@@W4combatHintType_t@2@ABVidVec3@@W4combatHintClass_t@2@@Z
// EA  : 0x82A95990
// RVA : 0x00A95990
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

idAICombatHint *__fastcall idCombatStage::GetContainingHintNodePtr(
        idCombatStage *this,
        unsigned int hintType,
        const idVec3 *currentPos,
        const idAICombatHint::combatHintClass_t hintClass)
{
  int value; // r10
  idAIHintGroup *v9; // r3
  idAICombatHint *result; // r3
  const idList<int,5> *NodesListByHintType; // r3
  const idList<int,5> *v12; // r28
  idAICombatHint *v13; // r23
  int v14; // r24
  double v15; // fp31
  int v16; // r26
  int v17; // r10
  int *list; // r31
  idAIHintGroup *v19; // r3
  idAIHintGroup *v20; // r3
  int v21; // r11
  int v22; // r8
  idEntity *v23; // r3
  idAICombatHint *v24; // r30
  idAICombatHint *v25; // r3
  idEntity *v26; // r31
  int dontUseUntil; // r30
  idPhysics *Physics; // r3
  float *v29; // r3
  double v30; // fp10
  double v31; // fp6
  double PointWeight; // fp1

  value = this->hintGroup.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idAIHintGroup *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idAIHintGroup::CastTo(c: v9) != nullptr )
  {
    NodesListByHintType = idCombatStage::GetNodesListByHintType(this, hintType);
    v12 = NodesListByHintType;
    if ( NodesListByHintType == nullptr )
      return nullptr;
    v13 = nullptr;
    v14 = 0;
    v15 = 0.0;
    if ( NodesListByHintType->num <= 0 )
      return nullptr;
    v16 = 0;
    do
    {
      v17 = this->hintGroup.spawnId.value;
      list = v12->list;
      if ( gameLocal->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
        && (v19 = (idAIHintGroup *)gameLocal->entities.ptr[v17 & 0x1FFF]) != nullptr )
      {
        v20 = idAIHintGroup::CastTo(c: v19);
      }
      else
      {
        v20 = nullptr;
      }
      v21 = list[v16];
      if ( v21 < v20->targets.num
        && (v22 = v20->targets.list[v21].spawnId.value, gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13)
        && (v23 = gameLocal->entities.ptr[v20->targets.list[v21].spawnId.value & 0x1FFF]) != nullptr )
      {
        v24 = (idAICombatHint *)idEntity::CastTo(c: v23);
      }
      else
      {
        v24 = nullptr;
      }
      if ( v24 != nullptr )
      {
        v25 = idAICombatHint::CastTo(c: v24);
        v26 = v25;
        if ( v25 != nullptr )
        {
          if ( (v25->hintClass & hintClass) != 0 )
          {
            dontUseUntil = v25->dontUseUntil;
            if ( dontUseUntil <= idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
            {
              Physics = idEntity::GetPhysics(this: v26);
              v29 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              v30 = (float)(currentPos->z - v29[2]);
              v31 = (float)(currentPos->y - v29[1]);
              if ( v13 == nullptr
                || (float)((float)((float)v31 * (float)v31)
                         + (float)((float)((float)(currentPos->x - *v29) * (float)(currentPos->x - *v29))
                                 + (float)((float)v30 * (float)v30))) < v15 )
              {
                v13 = (idAICombatHint *)v26;
                v15 = (float)((float)((float)v31 * (float)v31)
                            + (float)((float)((float)(currentPos->x - *v29) * (float)(currentPos->x - *v29))
                                    + (float)((float)v30 * (float)v30)));
              }
            }
          }
        }
        else
        {
          idLib::Warning(
            fmt: "Combat stage '%s' has an invalid entity '%s' in its combat hint list",
            this->name.data,
            v24->name.data);
        }
      }
      ++v14;
      ++v16;
    }
    while ( v14 < v12->num );
    if ( v13 == nullptr )
      return nullptr;
    PointWeight = idAICombatHint::GetPointWeight(this: v13, point: currentPos);
    result = v13;
    if ( PointWeight <= 0.0 )
      return nullptr;
  }
  else
  {
    idLib::Warning(
      fmt: "idCombatStage::GetContainingHintNodePtr - hintGroup entity is NULL on stage type '%s'",
      idCombatStage::combatStageNames[this->stageType]);
    return nullptr;
  }
  return result;
}


// ========================================================================
// ?GetClosestHintNodePtrByDot@idCombatStage@@QBAPBVidAICombatHint@@W4combatHintType_t@2@ABVidVec3@@1@Z
// EA  : 0x82A95C38
// RVA : 0x00A95C38
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idAICombatHint *__fastcall idCombatStage::GetClosestHintNodePtrByDot(
        idCombatStage *this,
        unsigned int hintType,
        const idVec3 *startPos,
        const idVec3 *endPos)
{
  int value; // r10
  idAIHintGroup *v9; // r3
  const idList<int,5> *NodesListByHintType; // r28
  unsigned int v12; // r4
  double x; // fp0
  double v14; // fp13
  idEntity *v15; // r20
  double v16; // fp27
  int v17; // r25
  double z; // fp30
  double y; // fp29
  double v20; // fp28
  int i; // r26
  int v22; // r10
  int *list; // r31
  idAIHintGroup *v24; // r3
  idAIHintGroup *v25; // r3
  int v26; // r11
  int v27; // r8
  idEntity *v28; // r3
  idAICombatHint *v29; // r31
  idAICombatHint *v30; // r3
  idEntity *v31; // r30
  int dontUseUntil; // r31
  idPhysics *Physics; // r3
  float *v34; // r3
  double v35; // fp0
  double v36; // fp7
  idVec3 v37; // [sp+50h] [-A0h] BYREF

  value = this->hintGroup.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v9 = (idAIHintGroup *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idAIHintGroup::CastTo(c: v9) == nullptr )
  {
    idLib::Warning(
      fmt: "idCombatStage::GetClosestHintNodePtrByDot - hintGroup entity is NULL on stage type '%s'",
      idCombatStage::combatStageNames[this->stageType]);
    return nullptr;
  }
  NodesListByHintType = idCombatStage::GetNodesListByHintType(this, hintType);
  if ( NodesListByHintType == nullptr )
    return nullptr;
  x = startPos->x;
  v14 = endPos->x;
  if ( x == v14 && startPos->y == endPos->y )
    return idCombatStage::GetClosestHintNodePtr(this, hintType: v12, currentPos: endPos, hintClass: CLASS_ALL);
  v37.y = endPos->y - startPos->y;
  v37.x = (float)v14 - (float)x;
  v15 = nullptr;
  v37.z = 0.0;
  v16 = 0.0;
  idVec3::NormalizeFast(this: &v37);
  v17 = 0;
  if ( NodesListByHintType->num <= 0 )
    return (const idAICombatHint *)v15;
  z = v37.z;
  y = v37.y;
  v20 = v37.x;
  for ( i = 0; ; ++i )
  {
    v22 = this->hintGroup.spawnId.value;
    list = NodesListByHintType->list;
    if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
      && (v24 = (idAIHintGroup *)gameLocal->entities.ptr[v22 & 0x1FFF]) != nullptr )
    {
      v25 = idAIHintGroup::CastTo(c: v24);
    }
    else
    {
      v25 = nullptr;
    }
    v26 = list[i];
    if ( v26 < v25->targets.num
      && (v27 = v25->targets.list[v26].spawnId.value, gameLocal->spawnIds.ptr[v27 & 0x1FFF] == v27 >> 13)
      && (v28 = gameLocal->entities.ptr[v25->targets.list[v26].spawnId.value & 0x1FFF]) != nullptr )
    {
      v29 = (idAICombatHint *)idEntity::CastTo(c: v28);
    }
    else
    {
      v29 = nullptr;
    }
    if ( v29 != nullptr )
    {
      v30 = idAICombatHint::CastTo(c: v29);
      v31 = v30;
      if ( v30 != nullptr )
        break;
      idLib::Warning(
        fmt: "Combat stage '%s' has an invalid entity '%s' in its combat hint list",
        this->name.data,
        v29->name.data);
    }
LABEL_30:
    if ( ++v17 >= NodesListByHintType->num )
      return (const idAICombatHint *)v15;
  }
  dontUseUntil = v30->dontUseUntil;
  if ( dontUseUntil > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
    goto LABEL_30;
  Physics = idEntity::GetPhysics(this: v31);
  v34 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v35 = (float)(v34[1] - startPos->y);
  if ( (float)(*v34 - startPos->x) != 0.0 || v35 != 0.0 )
  {
    v36 = __fsqrts((float)((float)((float)v35 * (float)v35)
                         + (float)((float)(*v34 - startPos->x) * (float)(*v34 - startPos->x))));
    if ( v15 == nullptr
      || (float)((float)((float)((float)z * (float)0.0)
                       + (float)((float)((float)y * (float)(v34[1] - startPos->y))
                               + (float)((float)v20 * (float)(*v34 - startPos->x))))
               / (float)v36) > v16 )
    {
      v15 = v31;
      v16 = (float)((float)((float)((float)z * (float)0.0)
                          + (float)((float)((float)y * (float)(v34[1] - startPos->y))
                                  + (float)((float)v20 * (float)(*v34 - startPos->x))))
                  / (float)v36);
    }
    goto LABEL_30;
  }
  return (const idAICombatHint *)v31;
}


// ========================================================================
// ?CategorizeHintGroupCombatNodes@idCombatStage@@QBAXXZ
// EA  : 0x82A95F48
// RVA : 0x00A95F48
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idCombatStage::CategorizeHintGroupCombatNodes(idCombatStage *this)
{
  idList<enum encounterGroupRole_t,5> *p_defenseNodes; // r28
  int value; // r9
  idAIHintGroup *v4; // r3
  encounterGroupRole_t v5; // r29
  int v6; // r9
  idGameLocal *v7; // r11
  idAIHintGroup *v8; // r3
  idAIHintGroup *v9; // r3
  int v10; // r9
  idAIHintGroup *v11; // r3
  idAIHintGroup *v12; // r3
  int v13; // r9
  idEntity *v14; // r3
  idAICombatHint *v15; // r3
  idAICombatHint *v16; // r3
  unsigned int combatHintType; // r11
  encounterGroupRole_t v26[28]; // [sp+50h] [-70h] BYREF

  p_defenseNodes = (idList<enum encounterGroupRole_t,5> *)&this->defenseNodes;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->defenseNodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->assaultNodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->flankNodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->flankTargetNodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->flankPathNodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->grenadeNodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rechargeNodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->suppressionFireNodes);
  value = this->hintGroup.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idAIHintGroup *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr && idAIHintGroup::CastTo(c: v4) != nullptr )
    {
      v5 = ROLE_NONE;
      while ( 1 )
      {
        v6 = this->hintGroup.spawnId.value;
        v7 = gameLocal;
        v26[0] = v5;
        if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
          && (v8 = (idAIHintGroup *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
        {
          v9 = idAIHintGroup::CastTo(c: v8);
          v7 = gameLocal;
        }
        else
        {
          v9 = nullptr;
        }
        if ( v5 >= v9->targets.num )
          return;
        v10 = this->hintGroup.spawnId.value;
        if ( v7->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
          && (v11 = (idAIHintGroup *)v7->entities.ptr[v10 & 0x1FFF]) != nullptr )
        {
          v12 = idAIHintGroup::CastTo(c: v11);
          v7 = gameLocal;
        }
        else
        {
          v12 = nullptr;
        }
        if ( v5 < v12->targets.num
          && (v13 = v12->targets.list[v5].spawnId.value, v7->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13)
          && (v14 = v7->entities.ptr[v12->targets.list[v5].spawnId.value & 0x1FFF]) != nullptr )
        {
          v15 = (idAICombatHint *)idEntity::CastTo(c: v14);
        }
        else
        {
          v15 = nullptr;
        }
        v16 = idAICombatHint::CastTo(c: v15);
        if ( v16 == nullptr )
          goto LABEL_69;
        combatHintType = v16->combatHintType;
        if ( combatHintType > 7 )
          goto LABEL_69;
        if ( combatHintType != 0 )
        {
          switch ( combatHintType )
          {
            case 1u:
              if ( this->assaultNodes.listStatic != 0 && this->assaultNodes.num >= this->assaultNodes.size )
                goto LABEL_69;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&this->assaultNodes,
                obj: v26);
              ++v5;
              break;
            case 2u:
              if ( this->flankNodes.listStatic != 0 && this->flankNodes.num >= this->flankNodes.size )
                goto LABEL_69;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&this->flankNodes,
                obj: v26);
              ++v5;
              break;
            case 3u:
              if ( this->flankTargetNodes.listStatic != 0 && this->flankTargetNodes.num >= this->flankTargetNodes.size )
                goto LABEL_69;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&this->flankTargetNodes,
                obj: v26);
              ++v5;
              break;
            case 4u:
              if ( this->flankPathNodes.listStatic != 0 && this->flankPathNodes.num >= this->flankPathNodes.size )
                goto LABEL_69;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&this->flankPathNodes,
                obj: v26);
              ++v5;
              break;
            case 5u:
              if ( this->grenadeNodes.listStatic != 0 && this->grenadeNodes.num >= this->grenadeNodes.size )
                goto LABEL_69;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&this->grenadeNodes,
                obj: v26);
              ++v5;
              break;
            case 6u:
              if ( this->rechargeNodes.listStatic != 0 && this->rechargeNodes.num >= this->rechargeNodes.size )
              {
LABEL_69:
                ++v5;
              }
              else
              {
                idList<idAnimWebBlendTree *,5>::Append(
                  this: (idList<enum encounterGroupRole_t,5> *)&this->rechargeNodes,
                  obj: v26);
                ++v5;
              }
              break;
            default:
              if ( this->suppressionFireNodes.listStatic == 0
                || this->suppressionFireNodes.num < this->suppressionFireNodes.size )
              {
                idList<idAnimWebBlendTree *,5>::Append(
                  this: (idList<enum encounterGroupRole_t,5> *)&this->suppressionFireNodes,
                  obj: v26);
              }
              goto LABEL_69;
          }
        }
        else
        {
          if ( p_defenseNodes->listStatic != 0 && p_defenseNodes->num >= p_defenseNodes->size )
            goto LABEL_69;
          idList<idAnimWebBlendTree *,5>::Append(this: p_defenseNodes, obj: v26);
          ++v5;
        }
      }
    }
  }
}


// ========================================================================
// ?DebugDrawCombatStage@idEncounterGroup@@QAAXH_N0@Z
// EA  : 0x82A963A0
// RVA : 0x00A963A0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEncounterGroup::DebugDrawCombatStage(
        idEncounterGroup *this,
        int duration,
        const bool normalNodes,
        const bool grenadeHints)
{
  int curCombatStage; // r11
  idCombatStage *v9; // r30
  int v10; // r29
  int v11; // r31
  int value; // r9
  idEntity *v13; // r3
  idPlayer *v14; // r3
  idPlayer *v15; // r3
  int i; // r29
  idAICombatHint *CombatHintEntity; // r3
  idAICombatHint *v18; // r31
  char *data; // r24
  __int64 v20; // r23
  char *ClassName; // r3
  __int64 v22; // r10
  va *v23; // r24
  const idColor *DrawColor; // r11
  __int128 v25; // r6
  int v26; // r10
  int v27; // r9
  int v28; // r8
  int j; // r29
  idAICombatHint *v30; // r3
  idAICombatHint *v31; // r31
  char *v32; // r24
  __int64 v33; // r23
  char *v34; // r3
  __int64 v35; // r10
  va *v36; // r24
  const idColor *v37; // r11
  __int128 v38; // r6
  int v39; // r10
  int v40; // r9
  int v41; // r8
  int k; // r29
  idAICombatHint *v43; // r3
  idAICombatHint *v44; // r31
  char *v45; // r24
  __int64 v46; // r23
  char *v47; // r3
  __int64 v48; // r10
  va *v49; // r24
  const idColor *v50; // r11
  __int128 v51; // r6
  int v52; // r10
  int v53; // r9
  int v54; // r8
  int m; // r29
  idAICombatHint *v56; // r3
  idAICombatHint *v57; // r31
  char *v58; // r24
  __int64 v59; // r23
  char *v60; // r3
  __int64 v61; // r10
  va *v62; // r24
  const idColor *v63; // r11
  __int128 v64; // r6
  int v65; // r10
  int v66; // r9
  int v67; // r8
  int n; // r29
  idAICombatHint *v69; // r3
  idAICombatHint *v70; // r31
  char *v71; // r24
  __int64 v72; // r23
  char *v73; // r3
  __int64 v74; // r10
  va *v75; // r24
  const idColor *v76; // r11
  __int128 v77; // r6
  int v78; // r10
  int v79; // r9
  int v80; // r8
  int ii; // r29
  idAICombatHint *v82; // r3
  idAICombatHint *v83; // r31
  char *v84; // r24
  __int64 v85; // r23
  char *v86; // r3
  __int64 v87; // r10
  va *v88; // r24
  const idColor *v89; // r11
  __int128 v90; // r6
  int v91; // r10
  int v92; // r9
  int v93; // r8
  int jj; // r29
  idAICombatHint *v95; // r3
  idAICombatHint *v96; // r31
  char *v97; // r24
  __int64 v98; // r23
  char *v99; // r3
  __int64 v100; // r10
  va *v101; // r24
  const idColor *v102; // r11
  __int128 v103; // r6
  int v104; // r10
  int v105; // r9
  int v106; // r8
  int kk; // r23
  idAICombatHint *v108; // r31
  int delay; // r19
  int GameMs; // r18
  char *v111; // r17
  __int64 v112; // r16
  char *v113; // r3
  __int64 v114; // r10
  int v115; // r10
  int v116; // r9
  idColor *v117; // r8
  __int64 v118; // r6 OVERLAPPED
  int v119; // r28
  char *v120; // r20
  __int64 v121; // r19
  char *v122; // r3
  __int64 v123; // r10
  va *v124; // r28
  int v125; // [sp+8h] [-1108h]
  int v126; // [sp+8h] [-1108h]
  int v127; // [sp+8h] [-1108h]
  int v128; // [sp+8h] [-1108h]
  int v129; // [sp+8h] [-1108h]
  int v130; // [sp+8h] [-1108h]
  int v131; // [sp+8h] [-1108h]
  int v132; // [sp+8h] [-1108h]
  int v133; // [sp+8h] [-1108h]
  int v134; // [sp+Ch] [-1104h]
  int v135; // [sp+10h] [-1100h]
  __int64 v136; // [sp+10h] [-1100h]
  __int64 v137; // [sp+10h] [-1100h]
  __int64 v138; // [sp+10h] [-1100h]
  __int64 v139; // [sp+10h] [-1100h]
  __int64 v140; // [sp+10h] [-1100h]
  __int64 v141; // [sp+10h] [-1100h]
  __int64 v142; // [sp+10h] [-1100h]
  __int64 v143; // [sp+10h] [-1100h]
  int v144; // [sp+14h] [-10FCh]
  int v145; // [sp+18h] [-10F8h]
  __int64 v146; // [sp+18h] [-10F8h]
  __int64 v147; // [sp+18h] [-10F8h]
  __int64 v148; // [sp+18h] [-10F8h]
  __int64 v149; // [sp+18h] [-10F8h]
  __int64 v150; // [sp+18h] [-10F8h]
  __int64 v151; // [sp+18h] [-10F8h]
  __int64 v152; // [sp+18h] [-10F8h]
  __int64 v153; // [sp+18h] [-10F8h]
  int v154; // [sp+1Ch] [-10F4h]
  __int64 v155; // [sp+20h] [-10F0h]
  __int64 v156; // [sp+28h] [-10E8h]
  __int64 v157; // [sp+30h] [-10E0h]
  int lastOutsideGrenadeHint; // [sp+60h] [-10B0h]
  int currentGrenadeHint; // [sp+64h] [-10ACh]
  va v160; // [sp+70h] [-10A0h] BYREF

  curCombatStage = this->curCombatStage;
  if ( curCombatStage >= 0 && curCombatStage < this->combatStages.num )
  {
    v9 = &this->combatStages.list[curCombatStage];
    if ( v9 != nullptr )
    {
      v10 = 0;
      currentGrenadeHint = -1;
      lastOutsideGrenadeHint = -1;
      if ( this->targetList.num > 0 )
      {
        v11 = 0;
        while ( 1 )
        {
          value = this->targetList.list[v11].target.spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v14 = (idPlayer *)idEntity::CastTo(c: v13);
          }
          else
          {
            v14 = nullptr;
          }
          v15 = idPlayer::CastTo(c: v14);
          if ( v15 != nullptr && v15 != (idPlayer *)-12832 )
            break;
          ++v10;
          ++v11;
          if ( v10 >= this->targetList.num )
            goto LABEL_15;
        }
        currentGrenadeHint = v15->auditor.currentGrenadeHint;
        lastOutsideGrenadeHint = v15->auditor.lastOutsideGrenadeHint;
      }
LABEL_15:
      if ( normalNodes )
      {
        for ( i = 0; i < v9->defenseNodes.num; ++i )
        {
          CombatHintEntity = (idAICombatHint *)idCombatStage::GetCombatHintEntity(this: v9, hintType: 0, index: i);
          v18 = CombatHintEntity;
          if ( CombatHintEntity != nullptr )
          {
            data = CombatHintEntity->name.data;
            LODWORD(v20) = v9->name.data;
            HIDWORD(v20) = this->groupName.data;
            ClassName = idAICombatHint::GetClassName(this: CombatHintEntity);
            v23 = va::va(
                    this: &v160,
                    fmt: "%s\n%s\n%s%s",
                    a3: v20,
                    a4: __SPAIR64__((unsigned int)data, (unsigned int)ClassName),
                    a5: v22,
                    a6: v125,
                    a7: v134,
                    a8: v135,
                    a9: v144,
                    a10: v145,
                    a11: v154);
            DrawColor = idAICombatHint::GetDrawColor(this: v18);
            LODWORD(v25) = v23;
            *(_QWORD *)((char *)&v25 + 4) = *(_QWORD *)&DrawColor->b;
            DrawPrimitive(
              hint: (const idAICombatHint *)LODWORD(DrawColor->r),
              name: v25,
              duration,
              a4: v28,
              a5: v27,
              a6: v26,
              a7: v126,
              a8: v136,
              a9: v146,
              a10: v155,
              a11: v156,
              a12: v157);
          }
        }
        for ( j = 0; j < v9->assaultNodes.num; ++j )
        {
          v30 = (idAICombatHint *)idCombatStage::GetCombatHintEntity(this: v9, hintType: 1u, index: j);
          v31 = v30;
          if ( v30 != nullptr )
          {
            v32 = v30->name.data;
            LODWORD(v33) = v9->name.data;
            HIDWORD(v33) = this->groupName.data;
            v34 = idAICombatHint::GetClassName(this: v30);
            v36 = va::va(
                    this: &v160,
                    fmt: "%s\n%s\n%s%s",
                    a3: v33,
                    a4: __SPAIR64__((unsigned int)v32, (unsigned int)v34),
                    a5: v35,
                    a6: v125,
                    a7: v134,
                    a8: v135,
                    a9: v144,
                    a10: v145,
                    a11: v154);
            v37 = idAICombatHint::GetDrawColor(this: v31);
            LODWORD(v38) = v36;
            *(_QWORD *)((char *)&v38 + 4) = *(_QWORD *)&v37->b;
            DrawPrimitive(
              hint: (const idAICombatHint *)LODWORD(v37->r),
              name: v38,
              duration,
              a4: v41,
              a5: v40,
              a6: v39,
              a7: v127,
              a8: v137,
              a9: v147,
              a10: v155,
              a11: v156,
              a12: v157);
          }
        }
        for ( k = 0; k < v9->flankNodes.num; ++k )
        {
          v43 = (idAICombatHint *)idCombatStage::GetCombatHintEntity(this: v9, hintType: 2u, index: k);
          v44 = v43;
          if ( v43 != nullptr )
          {
            v45 = v43->name.data;
            LODWORD(v46) = v9->name.data;
            HIDWORD(v46) = this->groupName.data;
            v47 = idAICombatHint::GetClassName(this: v43);
            v49 = va::va(
                    this: &v160,
                    fmt: "%s\n%s\n%s%s",
                    a3: v46,
                    a4: __SPAIR64__((unsigned int)v45, (unsigned int)v47),
                    a5: v48,
                    a6: v125,
                    a7: v134,
                    a8: v135,
                    a9: v144,
                    a10: v145,
                    a11: v154);
            v50 = idAICombatHint::GetDrawColor(this: v44);
            LODWORD(v51) = v49;
            *(_QWORD *)((char *)&v51 + 4) = *(_QWORD *)&v50->b;
            DrawPrimitive(
              hint: (const idAICombatHint *)LODWORD(v50->r),
              name: v51,
              duration,
              a4: v54,
              a5: v53,
              a6: v52,
              a7: v128,
              a8: v138,
              a9: v148,
              a10: v155,
              a11: v156,
              a12: v157);
          }
        }
        for ( m = 0; m < v9->flankPathNodes.num; ++m )
        {
          v56 = (idAICombatHint *)idCombatStage::GetCombatHintEntity(this: v9, hintType: 4u, index: m);
          v57 = v56;
          if ( v56 != nullptr )
          {
            v58 = v56->name.data;
            LODWORD(v59) = v9->name.data;
            HIDWORD(v59) = this->groupName.data;
            v60 = idAICombatHint::GetClassName(this: v56);
            v62 = va::va(
                    this: &v160,
                    fmt: "%s\n%s\n%s%s",
                    a3: v59,
                    a4: __SPAIR64__((unsigned int)v58, (unsigned int)v60),
                    a5: v61,
                    a6: v125,
                    a7: v134,
                    a8: v135,
                    a9: v144,
                    a10: v145,
                    a11: v154);
            v63 = idAICombatHint::GetDrawColor(this: v57);
            LODWORD(v64) = v62;
            *(_QWORD *)((char *)&v64 + 4) = *(_QWORD *)&v63->b;
            DrawPrimitive(
              hint: (const idAICombatHint *)LODWORD(v63->r),
              name: v64,
              duration,
              a4: v67,
              a5: v66,
              a6: v65,
              a7: v129,
              a8: v139,
              a9: v149,
              a10: v155,
              a11: v156,
              a12: v157);
          }
        }
        for ( n = 0; n < v9->flankTargetNodes.num; ++n )
        {
          v69 = (idAICombatHint *)idCombatStage::GetCombatHintEntity(this: v9, hintType: 3u, index: n);
          v70 = v69;
          if ( v69 != nullptr )
          {
            v71 = v69->name.data;
            LODWORD(v72) = v9->name.data;
            HIDWORD(v72) = this->groupName.data;
            v73 = idAICombatHint::GetClassName(this: v69);
            v75 = va::va(
                    this: &v160,
                    fmt: "%s\n%s\n%s%s",
                    a3: v72,
                    a4: __SPAIR64__((unsigned int)v71, (unsigned int)v73),
                    a5: v74,
                    a6: v125,
                    a7: v134,
                    a8: v135,
                    a9: v144,
                    a10: v145,
                    a11: v154);
            v76 = idAICombatHint::GetDrawColor(this: v70);
            LODWORD(v77) = v75;
            *(_QWORD *)((char *)&v77 + 4) = *(_QWORD *)&v76->b;
            DrawPrimitive(
              hint: (const idAICombatHint *)LODWORD(v76->r),
              name: v77,
              duration,
              a4: v80,
              a5: v79,
              a6: v78,
              a7: v130,
              a8: v140,
              a9: v150,
              a10: v155,
              a11: v156,
              a12: v157);
          }
        }
        for ( ii = 0; ii < v9->rechargeNodes.num; ++ii )
        {
          v82 = (idAICombatHint *)idCombatStage::GetCombatHintEntity(this: v9, hintType: 6u, index: ii);
          v83 = v82;
          if ( v82 != nullptr )
          {
            v84 = v82->name.data;
            LODWORD(v85) = v9->name.data;
            HIDWORD(v85) = this->groupName.data;
            v86 = idAICombatHint::GetClassName(this: v82);
            v88 = va::va(
                    this: &v160,
                    fmt: "%s\n%s\n%s%s",
                    a3: v85,
                    a4: __SPAIR64__((unsigned int)v84, (unsigned int)v86),
                    a5: v87,
                    a6: v125,
                    a7: v134,
                    a8: v135,
                    a9: v144,
                    a10: v145,
                    a11: v154);
            v89 = idAICombatHint::GetDrawColor(this: v83);
            LODWORD(v90) = v88;
            *(_QWORD *)((char *)&v90 + 4) = *(_QWORD *)&v89->b;
            DrawPrimitive(
              hint: (const idAICombatHint *)LODWORD(v89->r),
              name: v90,
              duration,
              a4: v93,
              a5: v92,
              a6: v91,
              a7: v131,
              a8: v141,
              a9: v151,
              a10: v155,
              a11: v156,
              a12: v157);
          }
        }
        for ( jj = 0; jj < v9->suppressionFireNodes.num; ++jj )
        {
          v95 = (idAICombatHint *)idCombatStage::GetCombatHintEntity(this: v9, hintType: 7u, index: jj);
          v96 = v95;
          if ( v95 != nullptr )
          {
            v97 = v95->name.data;
            LODWORD(v98) = v9->name.data;
            HIDWORD(v98) = this->groupName.data;
            v99 = idAICombatHint::GetClassName(this: v95);
            v101 = va::va(
                     this: &v160,
                     fmt: "%s\n%s\n%s%s",
                     a3: v98,
                     a4: __SPAIR64__((unsigned int)v97, (unsigned int)v99),
                     a5: v100,
                     a6: v125,
                     a7: v134,
                     a8: v135,
                     a9: v144,
                     a10: v145,
                     a11: v154);
            v102 = idAICombatHint::GetDrawColor(this: v96);
            LODWORD(v103) = v101;
            *(_QWORD *)((char *)&v103 + 4) = *(_QWORD *)&v102->b;
            DrawPrimitive(
              hint: (const idAICombatHint *)LODWORD(v102->r),
              name: v103,
              duration,
              a4: v106,
              a5: v105,
              a6: v104,
              a7: v132,
              a8: v142,
              a9: v152,
              a10: v155,
              a11: v156,
              a12: v157);
          }
        }
      }
      if ( grenadeHints || normalNodes )
      {
        for ( kk = 0; kk < v9->grenadeNodes.num; ++kk )
        {
          v108 = (idAICombatHint *)idCombatStage::GetCombatHintEntity(this: v9, hintType: 5u, index: kk);
          if ( v108 != nullptr )
          {
            idAICombatHint::HintTypeColor(hintType: COMBAT_HINT_GRENADE_POINT);
            if ( kk == currentGrenadeHint )
            {
              idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              delay = v108->delay;
              GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              v111 = v108->name.data;
              LODWORD(v112) = v9->name.data;
              HIDWORD(v112) = this->groupName.data;
              v113 = idAICombatHint::GetClassName(this: v108);
              HIDWORD(v114) = GameMs - lastOutsideGrenadeHint;
              LODWORD(v114) = delay;
              va::va(
                this: &v160,
                fmt: "%s\n%s\n%s%s\ndelay: %d/%d\ngroup: %d/%d\n",
                a3: v112,
                a4: __SPAIR64__((unsigned int)v111, (unsigned int)v113),
                a5: v114,
                a6: v125,
                a7: v134,
                a8: v135,
                a9: v144,
                a10: v145,
                a11: v154);
              v117 = &idColor::colorPink;
              v118 = __PAIR64__(LODWORD(idColor::colorPink.a), LODWORD(idColor::colorPink.r));
            }
            else
            {
              v119 = v108->delay;
              v120 = v108->name.data;
              LODWORD(v121) = v9->name.data;
              HIDWORD(v121) = this->groupName.data;
              v122 = idAICombatHint::GetClassName(this: v108);
              HIDWORD(v123) = v119;
              v124 = va::va(
                       this: &v160,
                       fmt: "%s\n%s\n%s%s\ndelay: %d",
                       a3: v121,
                       a4: __SPAIR64__((unsigned int)v120, (unsigned int)v122),
                       a5: v123,
                       a6: v125,
                       a7: v134,
                       a8: v135,
                       a9: v144,
                       a10: v145,
                       a11: v154);
              *(__int64 *)((char *)&v118 + 4) = *(_QWORD *)(LODWORD(idAICombatHint::GetDrawColor(this: v108)->r) + 8);
              LODWORD(v118) = v124;
            }
            DrawPrimitive(
              hint: v108,
              name: v118,
              duration,
              a4: (int)v117,
              a5: v116,
              a6: v115,
              a7: v133,
              a8: v143,
              a9: v153,
              a10: v155,
              a11: v156,
              a12: v157);
          }
        }
      }
    }
  }
}


// ========================================================================
// ?GetCurrentCombatStageCoverIndices@idEncounterGroup@@QBAXAAV?$idList@H$04@@@Z
// EA  : 0x82A96AE8
// RVA : 0x00A96AE8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::GetCurrentCombatStageCoverIndices(
        idEncounterGroup *this,
        idList<idVehicleState *,5> *coverIndices)
{
  int curCombatStage; // r11
  encounterGroupRole_t *list; // r20
  idCombatStage *v6; // r24
  unsigned int *v7; // r22
  int i; // r21
  unsigned int v9; // r11
  idList<int,5> *p_suppressionFireNodes; // r11
  int num; // r23
  int j; // r25
  const idAICombatHint *CombatHintEntity; // r3
  idList<int,5> *p_coverIndices; // r29
  int v15; // r27
  int v16; // r30
  int v17; // r10
  int v18; // r9
  const encounterGroupRole_t *v19; // r4
  int v20; // r11
  encounterGroupRole_t v21[4]; // [sp+50h] [-90h] BYREF
  idList<enum encounterGroupRole_t,5> v22[8]; // [sp+60h] [-80h] BYREF

  idList<idThread *,58>::Clear(this: coverIndices);
  memset(v22, 0, 14);
  v22[0].memTag = 5;
  v22[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v22);
  v21[0] = ROLE_DEFEND;
  idList<idAnimWebBlendTree *,5>::Append(this: v22, obj: v21);
  v21[0] = ROLE_NONE;
  idList<idAnimWebBlendTree *,5>::Append(this: v22, obj: v21);
  v21[0] = ROLE_ASSAULT;
  idList<idAnimWebBlendTree *,5>::Append(this: v22, obj: v21);
  curCombatStage = this->curCombatStage;
  list = v22[0].list;
  if ( curCombatStage >= 0 && curCombatStage < this->combatStages.num )
  {
    v6 = &this->combatStages.list[curCombatStage];
    if ( v6 != nullptr && v22[0].num > 0 )
    {
      v7 = (unsigned int *)v22[0].list;
      for ( i = v22[0].num; i != 0; --i )
      {
        v9 = *v7;
        if ( *v7 <= 7
          && (v9 != 1
            ? (v9 != 2
             ? (v9 != 3
              ? (v9 != 4
               ? (v9 != 5
                ? (v9 != 6
                 ? (v9 != 0
                  ? (p_suppressionFireNodes = &v6->suppressionFireNodes)
                  : (p_suppressionFireNodes = &v6->defenseNodes))
                 : (p_suppressionFireNodes = &v6->rechargeNodes))
                : (p_suppressionFireNodes = &v6->grenadeNodes))
               : (p_suppressionFireNodes = &v6->flankPathNodes))
              : (p_suppressionFireNodes = &v6->flankTargetNodes))
             : (p_suppressionFireNodes = &v6->flankNodes))
            : (p_suppressionFireNodes = &v6->assaultNodes),
              p_suppressionFireNodes != nullptr) )
        {
          num = p_suppressionFireNodes->num;
        }
        else
        {
          num = 0;
        }
        for ( j = 0; j < num; ++j )
        {
          CombatHintEntity = idCombatStage::GetCombatHintEntity(this: v6, hintType: *v7, index: j);
          if ( CombatHintEntity != nullptr )
          {
            p_coverIndices = &CombatHintEntity->coverIndices;
            v15 = 0;
            if ( CombatHintEntity->coverIndices.num > 0 )
            {
              v16 = 0;
              do
              {
                v17 = 0;
                v18 = coverIndices->num;
                v19 = (const encounterGroupRole_t *)&p_coverIndices->list[v16];
                if ( v18 <= 0 )
                  goto LABEL_35;
                v20 = 0;
                while ( coverIndices->list[v20] != (idVehicleState *)*v19 )
                {
                  ++v17;
                  ++v20;
                  if ( v17 >= v18 )
                    goto LABEL_35;
                }
                if ( v17 < 0 )
LABEL_35:
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)coverIndices,
                    obj: v19);
                ++v15;
                ++v16;
              }
              while ( v15 < p_coverIndices->num );
            }
          }
        }
        ++v7;
      }
    }
  }
  if ( (v22[0].listStatic == 0 || v22[0].listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$499625
// EA  : 0x82A96D20
// RVA : 0x00A96D20
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_499625()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 96));
}


// ========================================================================
// ?GetLivingMembers@idEncounterGroup@@QBAXAAV?$idStaticList@PAVidAI2@@$0EA@@@@Z
// EA  : 0x82A96D48
// RVA : 0x00A96D48
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::GetLivingMembers(idEncounterGroup *this, idStaticList<idAI2 *,64> *list)
{
  int v4; // r30
  int v5; // r31
  idEncounterGroup **v6; // r11
  int v7; // r26
  int v8; // r28
  int value; // r9
  idAI2 *v10; // r3
  idAI2 *v11; // r31
  int v12; // r9
  idPlayer *v13; // r3
  idAI2 *v14; // [sp+50h] [-50h] BYREF

  v4 = 0;
  if ( this->childGroups.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this->childGroups.list;
      if ( v6[v5] != nullptr )
        idEncounterGroup::GetLivingMembers(this: v6[v5], list);
      ++v4;
      ++v5;
    }
    while ( v4 < this->childGroups.num );
  }
  v7 = 0;
  if ( this->members.num > 0 )
  {
    v8 = 0;
    do
    {
      if ( v8 >= 64 )
        break;
      value = this->members.list[v8].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v10 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v11 = idAI2::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      v14 = v11;
      if ( v11 != nullptr && !v11->IsDead(this: v11) )
      {
        v12 = v11->aiVolatile.playerControl.player.spawnId.value;
        if ( (gameLocal->spawnIds.ptr[v12 & 0x1FFF] != v12 >> 13
           || (v13 = (idPlayer *)gameLocal->entities.ptr[v12 & 0x1FFF]) == nullptr
           || idPlayer::CastTo(c: v13) == nullptr)
          && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v11) == 0 )
        {
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)list,
            obj: (const encounterGroupRole_t *)&v14);
        }
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->members.num );
  }
}


// ========================================================================
// ?GetRandomLiveMember@idEncounterGroup@@QBAPAVidAI2@@XZ
// EA  : 0x82A96ED0
// RVA : 0x00A96ED0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

idAI2 *__fastcall idEncounterGroup::GetRandomLiveMember(idEncounterGroup *this)
{
  int num; // r11
  int v3; // r9
  unsigned int v4; // r4
  idAI2 **list; // r3
  int v6; // r10
  idAI2 *v7; // r30
  idStaticList<idAI2 *,64> v8; // [sp+50h] [-130h] BYREF

  v8.granularity = 1;
  v8.size = 64;
  v8.num = 0;
  v8.list = v8.staticList;
  v8.memTag = 5;
  v8.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this, list: &v8);
  num = v8.num;
  if ( v8.num != 0 )
  {
    v3 = v8.num;
    __twllei(v8.num, 0);
    v4 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v4;
    list = v8.list;
    v6 = (v4 >> 10) & 0x7FFF;
    __twlgei(v3 & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
    v7 = list[v6 % num];
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v8);
    return v7;
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v8);
    return nullptr;
  }
}


// ========================================================================
// __unwind$499960
// EA  : 0x82A96FB8
// RVA : 0x00A96FB8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_499960()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 384 + 80));
}


// ========================================================================
// ?GetClosestActiveGroupMemberToPoint@idEncounterGroup@@QBAPBVidAI2@@ABVidVec3@@@Z
// EA  : 0x82A96FE8
// RVA : 0x00A96FE8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idAI2 *__fastcall idEncounterGroup::GetClosestActiveGroupMemberToPoint(
        idEncounterGroup *this,
        const idVec3 *point)
{
  idAI2 *v2; // r27
  int v5; // r26
  double v6; // fp31
  int v7; // r29
  idAI2 *v8; // r30
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp10
  double v12; // fp6
  idStaticList<idAI2 *,64> v13; // [sp+50h] [-150h] BYREF

  v2 = nullptr;
  v13.granularity = 1;
  v13.num = 0;
  v13.size = 64;
  v13.list = v13.staticList;
  v13.memTag = 5;
  v13.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this, list: &v13);
  if ( v13.num != 0 )
  {
    v5 = 0;
    v6 = 0.0;
    if ( v13.num > 0 )
    {
      v7 = 0;
      do
      {
        v8 = v13.list[v7];
        Physics = idEntity::GetPhysics(this: v8);
        v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v11 = (float)(v10[1] - point->y);
        v12 = (float)(v10[2] - point->z);
        if ( v2 == nullptr
          || (float)((float)((float)v12 * (float)v12)
                   + (float)((float)((float)(*v10 - point->x) * (float)(*v10 - point->x))
                           + (float)((float)v11 * (float)v11))) < v6 )
        {
          v2 = v8;
          v6 = (float)((float)((float)v12 * (float)v12)
                     + (float)((float)((float)(*v10 - point->x) * (float)(*v10 - point->x))
                             + (float)((float)v11 * (float)v11)));
        }
        ++v5;
        ++v7;
      }
      while ( v5 < v13.num );
    }
    if ( (v13.listStatic == 0 || v13.listStatic == 2) && v13.list != nullptr )
      idMem::Free(this: &mem, ptr: v13.list, align: ALIGN_16);
    return v2;
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v13);
    return nullptr;
  }
}


// ========================================================================
// __unwind$500030
// EA  : 0x82A97128
// RVA : 0x00A97128
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_500030()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 80));
}


// ========================================================================
// ?GetClosestActiveGroupMemberToEntity@idEncounterGroup@@QBAPBVidAI2@@PBVidEntity@@@Z
// EA  : 0x82A97150
// RVA : 0x00A97150
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const idAI2 *__fastcall idEncounterGroup::GetClosestActiveGroupMemberToEntity(idEncounterGroup *this, idEntity *ent)
{
  idPhysics *Physics; // r3
  const idVec3 *v4; // r3

  Physics = idEntity::GetPhysics(this: ent);
  v4 = Physics->GetOrigin(this: Physics, a2: 0);
  return idEncounterGroup::GetClosestActiveGroupMemberToPoint(this, point: v4);
}


// ========================================================================
// ?OnGroupMessage@idEncounterGroup@@QAAXW4aiGroupMessage_t@@PAVidEntity@@@Z
// EA  : 0x82A971A0
// RVA : 0x00A971A0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::OnGroupMessage(idEncounterGroup *this, aiGroupMessage_t msg, idEntity *ent)
{
  int v5; // r24
  int v6; // r26
  int value; // r9
  idAI2 *v8; // r3
  idAI2 *v9; // r3
  const idAI2 *v10; // r31
  idAIGameState *p_aiGameState; // r22
  const idSpawnId *v12; // r20
  const idAILogic *v13; // r3
  const idSpawnId *v14; // r8
  idEntityPtr<idEntity const > *p_currentEnemy; // r10
  idSpawnId v16; // [sp+50h] [-A0h] BYREF
  idSpawnId v17; // [sp+54h] [-9Ch] BYREF
  idAILogic v18; // [sp+60h] [-90h] BYREF

  if ( (unsigned int)msg > AIGROUPMSG_SET_ENEMY )
  {
    idLib::Warning(fmt: "Unhandled group message type %d", msg);
  }
  else if ( msg == AIGROUPMSG_DISABLE )
  {
    this->enabled = false;
  }
  else if ( msg != AIGROUPMSG_ENABLE )
  {
    v5 = 0;
    if ( this->members.num > 0 )
    {
      v6 = 0;
      do
      {
        value = this->members.list[v6].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v8 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF];
          if ( v8 != nullptr )
          {
            v9 = idAI2::CastTo(c: v8);
            v10 = v9;
            if ( v9 != nullptr )
            {
              p_aiGameState = &gameLocal->aiGameState;
              idSpawnId::idSpawnId(this: &v16, ent: v9);
              v12 = idSpawnId::idSpawnId(this: &v17, ent);
              v13 = idAILogic::idAILogic(this: &v18, ai: v10);
              idAIWorldState::AddEntityState(
                this: &v10->aiVolatile.world.worldState,
                gameState: p_aiGameState,
                owner: v13,
                entId: v12,
                stimulusType: AISTIMULUS_GROUP_CONFIRMED,
                stimulusAmount: 1.0,
                sourceId: v14);
              p_currentEnemy = &v10->aiVolatile.memory.currentEnemy;
              if ( ent != nullptr )
                p_currentEnemy->spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
              else
                p_currentEnemy->spawnId.value = 0x1FFF;
            }
          }
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->members.num );
    }
  }
  else
  {
    this->enabled = true;
  }
}


// ========================================================================
// ?AssignInitialSearchPoints@idEncounterGroup@@QAAXPBVidAAS2@@ABVidVec3@@11AAV?$idList@H$04@@2@Z
// EA  : 0x82A97348
// RVA : 0x00A97348
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::AssignInitialSearchPoints(
        idEncounterGroup *this,
        const idAAS2 *aas,
        const idVec3 *senseOrigin,
        const idVec3 *senseVelocity,
        const idVec3 *trueOrigin,
        idList<int,5> *searchHintGroupings,
        idList<int,5> *numPerGrouping)
{
  idList<int,5> *v7; // r23
  idList<int,5> *v10; // r21
  int v11; // r25
  int num; // r24
  signed int v13; // r26
  __int64 v14; // r7
  int v15; // r30
  int v16; // r10
  int v17; // r11
  idMem *v18; // r30
  encounterGroupRole_t *list; // r22
  unsigned __int8 listStatic; // r16
  encounterGroupRole_t *v21; // r17
  int v22; // r27
  int v23; // r29
  int v24; // r30
  int i; // r28
  int *v26; // r11
  __int64 v27; // r10
  int v28; // r11
  int v29; // r30
  int v30; // r29
  double v31; // fp30
  __int64 v32; // r9
  int grouping; // r21
  double v34; // fp31
  idAI2 *v35; // r24
  int v36; // r25
  int v37; // r22
  int v38; // r23
  idAI2 *v39; // r26
  int v40; // r28
  int v41; // r29
  const aas2HintNode_t *v42; // r3
  const aas2HintNode_t *v43; // r30
  int v44; // r11
  encounterGroupRole_t *v45; // r10
  idPhysics *Physics; // r3
  float *v47; // r3
  double v48; // fp10
  double v49; // fp6
  idMem *v50; // r3
  encounterGroupRole_t *v51; // r4
  idRenderWorld_vtbl *v52; // r29
  const aas2HintNode_t *v53; // r3
  idPhysics *v54; // r28
  idRenderWorld *v55; // r27
  idRenderWorld_vtbl *v56; // r29
  const aas2HintNode_t *v57; // r30
  int v58; // r3
  int v59; // r10
  int v60; // r9
  int v61; // r11
  idList<enum encounterGroupRole_t,5> v62; // [sp+50h] [-240h] BYREF
  int v63; // [sp+60h] [-230h] BYREF
  idMem *v64; // [sp+64h] [-22Ch]
  idList<enum encounterGroupRole_t,5> v65; // [sp+70h] [-220h] BYREF
  idList<idVehicleState *,5> v66; // [sp+80h] [-210h] BYREF
  int v67; // [sp+90h] [-200h]
  signed int v68; // [sp+94h] [-1FCh]
  int v69; // [sp+98h] [-1F8h]
  idCVar *v70; // [sp+9Ch] [-1F4h]
  __int64 v71; // [sp+A0h] [-1F0h]
  __int64 v72; // [sp+A8h] [-1E8h]
  __int64 v73; // [sp+B0h] [-1E0h]
  unsigned __int64 v74; // [sp+B8h] [-1D8h]
  idStaticList<idAI2 *,64> v75; // [sp+C0h] [-1D0h] BYREF

  v7 = numPerGrouping;
  v75.granularity = 1;
  v75.num = 0;
  v75.memTag = 5;
  v75.size = 64;
  v75.list = v75.staticList;
  v10 = searchHintGroupings;
  v75.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this, list: &v75);
  memset(&v65, 0, 14);
  *(_WORD *)&v65.memTag = 1280;
  num = v75.num;
  v13 = this->searchPointList.num;
  v67 = v7->num;
  v11 = v67;
  v69 = v75.num;
  v68 = v13;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v65);
  memset(&v66, 0, 14);
  *(_WORD *)&v66.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v66);
  if ( v11 > 0 )
  {
    v15 = v11;
    v63 = 0;
    do
    {
      idList<idAnimWebBlendTree *,5>::Append(this: &v65, obj: (const encounterGroupRole_t *)&v63);
      --v15;
    }
    while ( v15 != 0 );
  }
  v16 = 0;
  if ( v75.num > 0 )
  {
    v17 = 0;
    do
    {
      ++v16;
      LODWORD(v14) = v75.list[v17++];
      *(_DWORD *)(v14 + 58452) = 0;
      HIDWORD(v14) = v75.num;
    }
    while ( v16 < v75.num );
  }
  if ( v13 == 0 )
  {
    v18 = &mem;
    if ( (v66.listStatic == 0 || v66.listStatic == 2) && v66.list != nullptr )
      idMem::Free(this: &mem, ptr: v66.list, align: ALIGN_16);
    if ( (v65.listStatic == 0 || v65.listStatic == 2) && v65.list != nullptr )
      idMem::Free(this: &mem, ptr: v65.list, align: ALIGN_16);
    goto LABEL_83;
  }
  list = v65.list;
  v18 = &mem;
  v64 = &mem;
  if ( num <= 0 )
    goto LABEL_75;
  v63 = num;
  v70 = &ai_debugSearch;
  while ( 1 )
  {
    listStatic = 0;
    v21 = nullptr;
    v22 = 0;
    *(_WORD *)&v62.memTag = 1280;
    memset(&v62, 0, 14);
    v23 = 0;
    if ( v11 > 0 )
    {
      v24 = 0;
      for ( i = v11; i != 0; --i )
      {
        v26 = v7->list;
        __twllei(v13, 0);
        HIDWORD(v27) = v26[v24] * num;
        v28 = SHIDWORD(v27) / v13;
        __twlgei(v13 & ~(__ROL4__(HIDWORD(v27), 1) - 1), 0xFFFFFFFF);
        if ( SHIDWORD(v27) / v13 <= 1 )
          v28 = 1;
        if ( list[v24] < v28 )
        {
          idList<idAnimWebBlendTree *,5>::Append(this: &v62, obj: (const encounterGroupRole_t *)&v10->list[v24]);
          ++v23;
        }
        ++v24;
      }
      if ( v23 == 0 )
      {
        LODWORD(v27) = v13;
        v71 = v27;
        v74 = __PAIR64__(v13, num);
        v29 = 0;
        v30 = v11;
        v31 = (float)v27;
        do
        {
          SLODWORD(v32) = list[v29];
          HIDWORD(v32) = v7->list[v29];
          LODWORD(v14) = HIDWORD(v32);
          v72 = v32;
          v73 = v14;
          if ( (float)v32 < (double)(float)((float)((float)v14 * (float)__SPAIR64__(v13, num)) / (float)v31) )
            idList<idAnimWebBlendTree *,5>::Append(this: &v62, obj: (const encounterGroupRole_t *)&v10->list[v29]);
          --v30;
          ++v29;
        }
        while ( v30 != 0 );
      }
      v21 = v62.list;
      v22 = v62.num;
      listStatic = v62.listStatic;
    }
    grouping = 0;
    v34 = 0.0;
    v35 = nullptr;
    v36 = 0;
    v37 = 0;
    if ( v75.num <= 0 )
      goto LABEL_89;
    v38 = 0;
    do
    {
      v39 = v75.list[v38];
      if ( v39->aiVolatile.memory.currentSearchHintIndex == 0 )
      {
        v40 = 0;
        if ( this->searchPointList.num > 0 )
        {
          v41 = 0;
          do
          {
            v42 = aas->GetHintNode(this: aas, a2: this->searchPointList.list[v41].hintNodeIndex);
            v43 = v42;
            v44 = 0;
            if ( v22 > 0 )
            {
              v45 = v21;
              while ( *v45 != v42->grouping )
              {
                ++v44;
                ++v45;
                if ( v44 >= v22 )
                  goto LABEL_47;
              }
              if ( v44 != -1 )
              {
                Physics = idEntity::GetPhysics(this: v39);
                v47 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
                v48 = (float)(v43->origin.y - v47[1]);
                v49 = (float)(v43->origin.z - v47[2]);
                if ( v35 == nullptr
                  || (float)((float)((float)v49 * (float)v49)
                           + (float)((float)((float)(v43->origin.x - *v47) * (float)(v43->origin.x - *v47))
                                   + (float)((float)v48 * (float)v48))) < v34 )
                {
                  grouping = v43->grouping;
                  v34 = (float)((float)((float)v49 * (float)v49)
                              + (float)((float)((float)(v43->origin.x - *v47) * (float)(v43->origin.x - *v47))
                                      + (float)((float)v48 * (float)v48)));
                  v35 = v39;
                  v36 = v40;
                }
              }
            }
LABEL_47:
            ++v40;
            ++v41;
          }
          while ( v40 < this->searchPointList.num );
        }
      }
      ++v37;
      ++v38;
    }
    while ( v37 < v75.num );
    if ( v35 != nullptr )
    {
      if ( v70->valueInteger > 0 && idAI2::GetDebugLevel() > 0 )
      {
        v52 = clientGame->renderWorld->__vftable;
        v53 = aas->GetHintNode(this: aas, a2: this->searchPointList.list[v36].hintNodeIndex);
        v52->DebugPoint(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: &v53->origin,
          a4: 3000,
          a5: false);
        v54 = idEntity::GetPhysics(this: v35);
        v55 = common->RW(this: common);
        v56 = v55->__vftable;
        v57 = aas->GetHintNode(this: aas, a2: this->searchPointList.list[v36].hintNodeIndex);
        v58 = (int)v54->GetOrigin(this: v54, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, const aas2HintNode_t *, double))v56->DebugArrow)(
          a1: v55,
          a2: &idColor::colorBlue,
          a3: v58,
          a4: v57,
          a5: 2.0);
      }
      v59 = 0;
      HIDWORD(v14) = this->searchPointList.list[v36].hintNodeIndex;
      v35->aiVolatile.memory.currentSearchHintIndex = HIDWORD(v14);
      this->searchPointList.list[v36].visited = true;
      v60 = searchHintGroupings->num;
      if ( v60 <= 0 )
        goto LABEL_63;
      v61 = 0;
      while ( searchHintGroupings->list[v61] != grouping )
      {
        ++v59;
        ++v61;
        if ( v59 >= v60 )
          goto LABEL_63;
      }
      if ( v59 >= 0 )
      {
        ++v65.list[v59];
        if ( listStatic == 0 || listStatic == 2 )
        {
          if ( v21 != nullptr )
          {
            v50 = v64;
            v51 = v21;
LABEL_71:
            idMem::Free(this: v50, ptr: v51, align: ALIGN_16);
          }
LABEL_72:
          v62.list = nullptr;
          v62.size = 0;
        }
      }
      else
      {
LABEL_63:
        if ( listStatic == 0 || listStatic == 2 )
        {
          if ( v21 != nullptr )
          {
            v50 = v64;
            v51 = v21;
            goto LABEL_71;
          }
          goto LABEL_72;
        }
      }
    }
    else
    {
LABEL_89:
      if ( listStatic == 0 || listStatic == 2 )
      {
        if ( v21 != nullptr )
        {
          v50 = v64;
          v51 = v21;
          goto LABEL_71;
        }
        goto LABEL_72;
      }
    }
    v62.num = 0;
    if ( --v63 == 0 )
      break;
    list = v65.list;
    v13 = v68;
    num = v69;
    v11 = v67;
    v10 = searchHintGroupings;
    v7 = numPerGrouping;
  }
  list = v65.list;
  v18 = v64;
LABEL_75:
  if ( (v66.listStatic == 0 || v66.listStatic == 2) && v66.list != nullptr )
    idMem::Free(this: v18, ptr: v66.list, align: ALIGN_16);
  if ( (v65.listStatic == 0 || v65.listStatic == 2) && list != nullptr )
    idMem::Free(this: v18, ptr: list, align: ALIGN_16);
LABEL_83:
  if ( (v75.listStatic == 0 || v75.listStatic == 2) && v75.list != nullptr )
    idMem::Free(this: v18, ptr: v75.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$500312
// EA  : 0x82A97A7C
// RVA : 0x00A97A7C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_500312()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 656 + 192));
}


// ========================================================================
// __unwind$500313
// EA  : 0x82A97AA4
// RVA : 0x00A97AA4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_500313()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 656 + 112));
}


// ========================================================================
// __unwind$500314
// EA  : 0x82A97ACC
// RVA : 0x00A97ACC
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_500314()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 656 + 128));
}


// ========================================================================
// __unwind$500315
// EA  : 0x82A97AF4
// RVA : 0x00A97AF4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_500315()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 656 + 80));
}


// ========================================================================
// ?ResolveChildReferences@idEncounterGroup@@AAAXXZ
// EA  : 0x82A97B20
// RVA : 0x00A97B20
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::ResolveChildReferences(idEncounterGroup *this)
{
  int v2; // r30
  idEncounterGroupManager *p_encounterGroupManager; // r28
  idList<idStr,5> *p_childGroupNames; // r29
  int v5; // r31
  idEncounterGroupManager v6; // [sp+50h] [-40h] BYREF

  if ( this->childGroupNames.num > 0 )
  {
    v2 = 0;
    p_encounterGroupManager = &gameLocal->encounterGroupManager;
    p_childGroupNames = &this->childGroupNames;
    v5 = 0;
    do
    {
      idEncounterGroupManager::HandleForName(
        this: &v6,
        result: p_encounterGroupManager,
        groupName: p_childGroupNames->list[v5].data);
      if ( HIWORD(v6.__vftable) != 0xFFFF )
      {
        v6.groups.list = idEncounterGroupManager::GroupForHandle(
                           this: p_encounterGroupManager,
                           handle: (const idHandle<short,enum invalidEncounterGroup_t,-1> *)&v6);
        if ( v6.groups.list != nullptr )
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->childGroups,
            obj: (const encounterGroupRole_t *)&v6.groups);
        idList<idStr,5>::RemoveIndex(this: p_childGroupNames, index: v2--);
        --v5;
      }
      ++v2;
      ++v5;
    }
    while ( v2 < this->childGroupNames.num );
  }
}


// ========================================================================
// ?LastLivingMemberSeenEnemytime@idEncounterGroup@@QBAHXZ
// EA  : 0x82A97BE0
// RVA : 0x00A97BE0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::LastLivingMemberSeenEnemytime(idEncounterGroup *this)
{
  int lastActuallySeenEnemyTime; // r30
  int num; // ctr
  idAI2 **list; // r11
  idStaticList<idAI2 *,64> v5; // [sp+50h] [-130h] BYREF

  v5.granularity = 1;
  v5.size = 64;
  v5.num = 0;
  v5.list = v5.staticList;
  v5.memTag = 5;
  v5.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this, list: &v5);
  lastActuallySeenEnemyTime = -1;
  if ( v5.num > 0 )
  {
    num = v5.num;
    list = v5.list;
    do
    {
      if ( lastActuallySeenEnemyTime <= (*list)->aiVolatile.memory.lastActuallySeenEnemyTime )
        lastActuallySeenEnemyTime = (*list)->aiVolatile.memory.lastActuallySeenEnemyTime;
      ++list;
      --num;
    }
    while ( num != 0 );
  }
  if ( (v5.listStatic == 0 || v5.listStatic == 2) && v5.list != nullptr )
    idMem::Free(this: &mem, ptr: v5.list, align: ALIGN_16);
  return lastActuallySeenEnemyTime;
}


// ========================================================================
// __unwind$500975
// EA  : 0x82A97CBC
// RVA : 0x00A97CBC
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_500975()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 384 + 80));
}


// ========================================================================
// ?UpdateGroupGoodWill@idEncounterGroup@@QAAXXZ
// EA  : 0x82A97CF0
// RVA : 0x00A97CF0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::UpdateGroupGoodWill(idEncounterGroup *this)
{
  int v2; // r29
  int v3; // r30
  idRenderWorld *v4; // r25
  idPhysics *Physics; // r3
  int v6; // r3
  idGame *v7; // r3
  int v8; // r28
  int v9; // r19
  idEntityPtr<idEntity const > *p_currentEnemy; // r7
  idEntity *v11; // r3
  idPlayer *v12; // r3
  const aiSenseState_t *EnemySenseState; // r29
  idPhysics *v14; // r3
  float *v15; // r29
  idEntity *Enemy; // r3
  idPhysics *v17; // r3
  float *v18; // r3
  double v19; // fp10
  double v20; // fp0
  double v21; // fp7
  bool v22; // r25
  int v23; // r26
  double z; // fp31
  int v25; // r29
  double y; // fp30
  double x; // fp29
  idAIMemory *p_memory; // r27
  const idEntity *v29; // r14
  const aiSenseState_t *v30; // r27
  idPhysics *v31; // r3
  float *v32; // r27
  idEntity *v33; // r3
  idPhysics *v34; // r3
  float *v35; // r3
  double v36; // fp10
  double v37; // fp0
  double v38; // fp7
  double v39; // fp1
  int v40; // r29
  idEntity *v41; // r3
  idPhysics *v42; // r3
  int v43; // r27
  idPhysics *v44; // r3
  int v45; // r3
  int v46; // r29
  idRenderWorld *v47; // r27
  idEntity *v48; // r3
  idPhysics *v49; // r3
  int v50; // r26
  idPhysics *v51; // r3
  int v52; // r3
  const idEntity *v53; // r3
  idVec3 v54; // [sp+68h] [-208h] BYREF
  idVec3 v55; // [sp+78h] [-1F8h] BYREF
  idStaticList<idAI2 *,64> v56; // [sp+90h] [-1E0h] BYREF

  v56.granularity = 1;
  v56.num = 0;
  v56.size = 64;
  v56.list = v56.staticList;
  v56.memTag = 5;
  v56.listStatic = 1;
  if ( !this->groupGoodWill )
  {
    if ( ai_debugLevel.valueInteger != 0 && ai_debugGoodWill.valueInteger != 0 )
    {
      idEncounterGroup::GetLivingMembers(this, list: &v56);
      v2 = 0;
      if ( v56.num > 0 )
      {
        v3 = 0;
        do
        {
          v4 = gameLocal->GetRenderWorld(this: gameLocal);
          Physics = idEntity::GetPhysics(this: v56.list[v3]);
          v6 = (int)Physics->GetOrigin(this: Physics, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, const char *, int, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v4->DebugText)(
            a1: v4,
            a2: "GW",
            a3: v6,
            a4: v4->__vftable,
            a5: &idColor::colorRed,
            a6: 500,
            a7: 0,
            a8: 0,
            a9: 0.2);
          ++v2;
          ++v3;
        }
        while ( v2 < v56.num );
      }
    }
    goto LABEL_38;
  }
  if ( (*(_BYTE *)&this->goodWillSettings & 0x80) == 0 )
    goto LABEL_38;
  v7 = common->Game(this: common);
  if ( v7->GetGameDifficulty(this: v7) == 0 )
    goto LABEL_38;
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&v56, newNum: 0);
  idEncounterGroup::GetLivingMembers(this, list: &v56);
  if ( v56.num <= 0 )
    goto LABEL_38;
  v8 = 0;
  v9 = 1;
  do
  {
    p_currentEnemy = &v56.list[v8]->aiVolatile.memory.currentEnemy;
    if ( gameLocal->spawnIds.ptr[p_currentEnemy->spawnId.value & 0x1FFF] == p_currentEnemy->spawnId.value >> 13
      && (v11 = gameLocal->entities.ptr[p_currentEnemy->spawnId.value & 0x1FFF]) != nullptr )
    {
      v12 = (idPlayer *)idEntity::CastTo(c: v11);
    }
    else
    {
      v12 = nullptr;
    }
    if ( idPlayer::CastTo(c: v12) == nullptr )
      goto LABEL_37;
    if ( !idAI2::IsEnemySenseStateValid(this: v56.list[v8], senseType: AISENSE_SIGHT) )
      goto LABEL_37;
    EnemySenseState = idAI2::GetEnemySenseState(this: v56.list[v8], senseType: AISENSE_SIGHT);
    if ( EnemySenseState == nullptr )
      goto LABEL_37;
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
       - EnemySenseState->lastConfirmedStimTime >= 300 )
      goto LABEL_37;
    v14 = idEntity::GetPhysics(this: v56.list[v8]);
    v15 = (float *)v14->GetOrigin(this: v14, a2: 0);
    Enemy = (idEntity *)idAIMemory::GetEnemy(this: &v56.list[v8]->aiVolatile.memory);
    v17 = idEntity::GetPhysics(this: Enemy);
    v18 = (float *)v17->GetOrigin(this: v17, a2: 0);
    v19 = (float)(v18[1] - v15[1]);
    v20 = (float)(*v18 - *v15);
    v21 = (float)(v18[2] - v15[2]);
    v54.x = *v18 - *v15;
    v54.y = v19;
    v54.z = v21;
    v22 = (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)) < 65536.0;
    idVec3::NormalizeFast(this: &v54);
    v23 = v9;
    if ( v9 >= v56.num )
      goto LABEL_37;
    z = v54.z;
    v25 = v8 * 4 + 4;
    y = v54.y;
    x = v54.x;
    while ( 1 )
    {
      p_memory = &(*(idAI2 **)((char *)v56.list + v25))->aiVolatile.memory;
      v29 = idAIMemory::GetEnemy(this: &v56.list[v8]->aiVolatile.memory);
      if ( idAIMemory::GetEnemy(this: p_memory) != v29 )
        goto LABEL_31;
      if ( !idAI2::IsEnemySenseStateValid(this: *(idAI2 **)((char *)v56.list + v25), senseType: AISENSE_SIGHT) )
        goto LABEL_31;
      v30 = idAI2::GetEnemySenseState(this: *(idAI2 **)((char *)v56.list + v25), senseType: AISENSE_SIGHT);
      if ( v30 == nullptr
        || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
         - v30->lastConfirmedStimTime >= 300 )
      {
        goto LABEL_31;
      }
      v31 = idEntity::GetPhysics(this: *(idEntity **)((char *)v56.list + v25));
      v32 = (float *)v31->GetOrigin(this: v31, a2: 0);
      v33 = (idEntity *)idAIMemory::GetEnemy(this: &(*(idAI2 **)((char *)v56.list + v25))->aiVolatile.memory);
      v34 = idEntity::GetPhysics(this: v33);
      v35 = (float *)v34->GetOrigin(this: v34, a2: 0);
      v36 = (float)(v35[1] - v32[1]);
      v37 = (float)(*v35 - *v32);
      v38 = (float)(v35[2] - v32[2]);
      v55.x = *v35 - *v32;
      v55.y = v36;
      v55.z = v38;
      if ( (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)) >= 65536.0 )
        break;
      if ( v22 )
        goto LABEL_30;
LABEL_31:
      ++v23;
      v25 += 4;
      if ( v23 >= v56.num )
        goto LABEL_37;
    }
    if ( v22 )
      goto LABEL_31;
LABEL_30:
    v39 = idVec3::NormalizeFast(this: &v55);
    if ( (float)((float)(v55.y * (float)y) + (float)((float)(v55.x * (float)x) + (float)(v55.z * (float)z))) >= -0.70700002 )
      goto LABEL_31;
    if ( ai_debugLevel.valueInteger != 0 && ai_debugGoodWill.valueInteger != 0 )
    {
      v40 = ((int (__fastcall *)(idGameLocal *, double))gameLocal->GetRenderWorld)(a1: gameLocal, a2: v39);
      v41 = (idEntity *)idAIMemory::GetEnemy(this: &v56.list[v8]->aiVolatile.memory);
      v42 = idEntity::GetPhysics(this: v41);
      v43 = (int)v42->GetOrigin(this: v42, a2: 0);
      v44 = idEntity::GetPhysics(this: v56.list[v8]);
      v45 = (int)v44->GetOrigin(this: v44, a2: 0);
      (*(void (__fastcall **)(int, idColor *, int, int, double))(*(_DWORD *)v40 + 180))(
        a1: v40,
        a2: &idColor::colorRed,
        a3: v45,
        a4: v43,
        a5: 0.2);
      v46 = v23;
      v47 = gameLocal->GetRenderWorld(this: gameLocal);
      v48 = (idEntity *)idAIMemory::GetEnemy(this: &v56.list[v23]->aiVolatile.memory);
      v49 = idEntity::GetPhysics(this: v48);
      v50 = (int)v49->GetOrigin(this: v49, a2: 0);
      v51 = idEntity::GetPhysics(this: v56.list[v46]);
      v52 = (int)v51->GetOrigin(this: v51, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, idColor *, int, int, double))v47->DebugArrow)(
        a1: v47,
        a2: &idColor::colorRed,
        a3: v52,
        a4: v50,
        a5: 0.2);
    }
    this->groupGoodWill = false;
    v53 = idAIMemory::GetEnemy(this: &v56.list[v8]->aiVolatile.memory);
    idEncounterGroup::FindSpeaker(
      this,
      enemy: v53,
      mustBeNearLastVisPos: false,
      mustBeVisible: true,
      excludeAI: nullptr);
LABEL_37:
    ++v9;
    ++v8;
  }
  while ( v9 - 1 < v56.num );
LABEL_38:
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v56);
}


// ========================================================================
// __unwind$501079
// EA  : 0x82A983E8
// RVA : 0x00A983E8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_501079()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 624 + 144));
}


// ========================================================================
// ?UpdateFiringConditions@idEncounterGroup@@QAAXXZ
// EA  : 0x82A98418
// RVA : 0x00A98418
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::UpdateFiringConditions(idEncounterGroup *this)
{
  int num; // r7
  int v3; // r22
  int v4; // r24
  int v5; // r30
  int GameMs; // r3
  idAI2 **v7; // r10
  idAI2 *v8; // r11
  idAI2 **list; // r4
  idAI2 *v10; // r10
  idAI2::aiCondition_t condition; // r11
  int v12; // r8
  int v13; // r10
  idAI2 *v14; // r11
  idAI2::aiCondition_t v15; // r9
  idStaticList<idAI2 *,64> v16; // [sp+50h] [-170h] BYREF

  v16.granularity = 1;
  v16.size = 64;
  v16.list = v16.staticList;
  v16.num = 0;
  v16.memTag = 5;
  v16.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this, list: &v16);
  num = v16.num;
  v3 = 0;
  v4 = 0;
  if ( v16.num <= 0 )
  {
    list = v16.list;
  }
  else
  {
    v5 = 0;
    do
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v7 = v16.list;
      v8 = v16.list[v5];
      if ( GameMs > v8->aiVolatile.memory.coveringFireTime )
      {
        v8->aiVolatile.groupStatus.condition &= ~0x200u;
        v7 = v16.list;
      }
      v7[v5]->aiVolatile.groupStatus.condition &= ~0x100u;
      list = v16.list;
      v10 = v16.list[v5];
      condition = v10->aiVolatile.groupStatus.condition;
      if ( (condition & 0x20) != 0 || (condition & 0x200) != 0 )
        ++v3;
      if ( !this->groupGoodWill )
      {
        if ( this->goodWillSettings.damageScale != 0.0 )
        {
          v10->aiVolatile.groupStatus.condition |= 0x20000u;
          list = v16.list;
        }
        if ( (*(_BYTE *)&this->goodWillSettings & 0x20) != 0 )
        {
          list[v5]->aiVolatile.groupStatus.condition |= 0x10000u;
          list = v16.list;
        }
        if ( (*(_BYTE *)&this->goodWillSettings & 8) != 0 )
        {
          list[v5]->aiVolatile.groupStatus.condition |= 0x8000u;
          list = v16.list;
        }
        if ( (*(_BYTE *)&this->goodWillSettings & 0x40) != 0 )
        {
          list[v5]->aiVolatile.groupStatus.condition |= 0x2000u;
          list = v16.list;
        }
        if ( (*(_BYTE *)&this->goodWillSettings & 0x10) != 0 )
        {
          list[v5]->aiVolatile.groupStatus.condition |= 0x4000u;
          list = v16.list;
        }
      }
      num = v16.num;
      ++v4;
      ++v5;
    }
    while ( v4 < v16.num );
  }
  if ( (this->groupGoodWill || (*(_BYTE *)&this->goodWillSettings & 0x10) == 0) && v3 >= this->maxSimultaneousFirers )
  {
    v12 = 0;
    if ( num > 0 )
    {
      v13 = 0;
      do
      {
        v14 = list[v13];
        v15 = v14->aiVolatile.groupStatus.condition;
        if ( (v15 & 0x20) == 0 && (v15 & 0x200) == 0 )
        {
          v14->aiVolatile.groupStatus.condition |= 0x100u;
          list = v16.list;
          num = v16.num;
        }
        ++v12;
        ++v13;
      }
      while ( v12 < num );
    }
  }
  if ( (v16.listStatic == 0 || v16.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$501447
// EA  : 0x82A986C4
// RVA : 0x00A986C4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_501447()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 80));
}


// ========================================================================
// ?SetLivingMemberCondition@idEncounterGroup@@QAAXH_N@Z
// EA  : 0x82A986F8
// RVA : 0x00A986F8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::SetLivingMemberCondition(
        idEncounterGroup *this,
        const int condition,
        const bool value)
{
  int v5; // r7
  int v6; // r10
  idAI2::aiCondition_t v7; // r6
  idAI2::aiCondition_t v8; // r5
  idStaticList<idAI2 *,64> v9; // [sp+50h] [-130h] BYREF

  v9.granularity = 1;
  v9.size = 64;
  v9.list = v9.staticList;
  v9.num = 0;
  v9.memTag = 5;
  v9.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this, list: &v9);
  v5 = 0;
  if ( v9.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = v9.list[v6]->aiVolatile.groupStatus.condition;
      v8 = condition | v7;
      if ( !value )
        v8 = v7 & ~condition;
      ++v5;
      v9.list[v6++]->aiVolatile.groupStatus.condition = v8;
    }
    while ( v5 < v9.num );
  }
  if ( (v9.listStatic == 0 || v9.listStatic == 2) && v9.list != nullptr )
    idMem::Free(this: &mem, ptr: v9.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$501695
// EA  : 0x82A987D4
// RVA : 0x00A987D4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_501695()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 384 + 80));
}


// ========================================================================
// ?GetRolePositionWeight@idCombatStage@@QBAMW4encounterGroupRole_t@@ABVidVec3@@W4combatHintClass_t@idAICombatHint@@@Z
// EA  : 0x82A98800
// RVA : 0x00A98800
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

double __fastcall idCombatStage::GetRolePositionWeight(
        idCombatStage *this,
        const encounterGroupRole_t role,
        const idVec3 *pos,
        idAICombatHint::combatHintClass_t hintClass)
{
  unsigned int v4; // r4

  switch ( role )
  {
    case ROLE_DEFEND:
      v4 = 0;
      return idCombatStage::GetHintWeight(this, hintType: v4, pos, hintClass);
    case ROLE_ASSAULT:
      v4 = 1;
      return idCombatStage::GetHintWeight(this, hintType: v4, pos, hintClass);
    case ROLE_FLANK:
      v4 = 2;
      return idCombatStage::GetHintWeight(this, hintType: v4, pos, hintClass);
    default:
      break;
  }
  return 0.0;
}


// ========================================================================
// ?GetFreshestSenseOfEntity@idEncounterGroup@@QBAPBVaiSenseState_t@@PBVidEntity@@@Z
// EA  : 0x82A98848
// RVA : 0x00A98848
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

const aiSenseState_t *__fastcall idEncounterGroup::GetFreshestSenseOfEntity(
        idEncounterGroup *this,
        const idEntity *ent)
{
  int v2; // r30
  aiSenseState_t *v4; // r27
  int lastConfirmedStimTime; // r29
  int i; // r26
  idAIEntityState *v7; // r3
  aiSenseState_t *v8; // r10
  idStaticList<idAI2 *,64> v10; // [sp+60h] [-150h] BYREF

  v2 = 0;
  v10.granularity = 1;
  v10.num = 0;
  v10.size = 64;
  v10.list = v10.staticList;
  v10.memTag = 5;
  v10.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this, list: &v10);
  v4 = nullptr;
  lastConfirmedStimTime = -1;
  for ( i = 0; i < v10.num; ++v2 )
  {
    v7 = idAIWorldState::StateForEntity(this: &v10.list[v2]->aiVolatile.world.worldState, ent);
    if ( v7 != nullptr && (*((_BYTE *)v7 + 541) & 0x80) != 0 )
    {
      v8 = v7->senses.ptr[v7->lastSense];
      if ( v8->lastUnconfirmedStimTime >= 0 && v8->lastConfirmedStimTime > lastConfirmedStimTime )
      {
        lastConfirmedStimTime = v8->lastConfirmedStimTime;
        v4 = v7->senses.ptr[v7->lastSense];
      }
    }
    ++i;
  }
  if ( (v10.listStatic == 0 || v10.listStatic == 2) && v10.list != nullptr )
    idMem::Free(this: &mem, ptr: v10.list, align: ALIGN_16);
  return v4;
}


// ========================================================================
// __unwind$501819
// EA  : 0x82A98960
// RVA : 0x00A98960
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_501819()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 96));
}


// ========================================================================
// ?Value@idEncounterGroupExpr@@QBAMPBVidEncounterGroup@@@Z
// EA  : 0x82A98B20
// RVA : 0x00A98B20
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

float __fastcall idEncounterGroupExpr::Value(idEncounterGroupExpr *this, idEncounterGroup *group)
{
  double v3; // fp1
  __int64 v4; // r11
  __int64 v5; // r11
  idEncounterGroup *v6; // r9
  __int64 v7; // r11
  __int64 v8; // r11
  idEncounterGroup *v9; // r9
  int v10; // r3
  __int64 v11; // r11
  idEncounterGroup *v12; // r9
  int v13; // r3
  int v14; // r8
  __int64 v15; // r6
  idAI2 *Leader; // r3
  int v17; // r29
  int v18; // r28
  int v19; // r27
  idAI2 *v20; // r30
  int v21; // r29
  double v22; // fp31
  int v23; // r30
  idAI2 *v24; // r11
  int v25; // r29
  double v26; // fp31
  int v27; // r30
  idAI2 *v28; // r11
  idPlayer *Enemy; // r3
  int v30; // r29
  double v31; // fp31
  int v32; // r30
  idAI2 *v33; // r3
  int v34; // r29
  double v35; // fp31
  int v36; // r30
  idAI2 *v37; // r3
  int v38; // r29
  double v39; // fp31
  int v40; // r30
  idAI2 *v41; // r3
  idStaticList<idAI2 *,64> v43; // [sp+60h] [-6B0h] BYREF
  idStaticList<idAI2 *,64> v44; // [sp+170h] [-5A0h] BYREF
  idStaticList<idAI2 *,64> v45; // [sp+280h] [-490h] BYREF
  idStaticList<idAI2 *,64> v46; // [sp+390h] [-380h] BYREF
  idStaticList<idAI2 *,64> v47; // [sp+4A0h] [-270h] BYREF
  idStaticList<idAI2 *,64> v48; // [sp+5B0h] [-160h] BYREF

  if ( group != nullptr )
  {
    switch ( this->type )
    {
      case GROUP_AVERAGE_HEALTH:
        v3 = idEncounterGroup::AverageHealth(this: group);
        return *((float *)&v3 + 1);
      case GROUP_MEMBERS_DEAD:
        LODWORD(v4) = idEncounterGroup::NumDeadMembers(this: group);
        v3 = (float)v4;
        return *((float *)&v3 + 1);
      case GROUP_MEMBERS_DEAD_UNALERTED:
        if ( idEncounterGroup::AnyMemberHighestAlertCycle(this: group) > ALERTCYCLE_RELAXED )
          goto _M502221;
        LODWORD(v7) = idEncounterGroup::NumDeadMembers(this: v6);
        v3 = (float)v7;
        return *((float *)&v3 + 1);
      case GROUP_MEMBERS_ALIVE:
        LODWORD(v5) = idEncounterGroup::NumLivingMembers(this: group);
        v3 = (float)v5;
        return *((float *)&v3 + 1);
      case GROUP_MEMBERS_ALIVE_UNALERTED:
        if ( idEncounterGroup::AnyMemberHighestAlertCycle(this: group) <= ALERTCYCLE_RELAXED )
          v10 = idEncounterGroup::NumLivingMembers(this: v9);
        else
          v10 = 64;
        LODWORD(v8) = v10;
        v3 = (float)v8;
        return *((float *)&v3 + 1);
      case GROUP_PERCENT_ALIVE:
        v3 = idEncounterGroup::PercentMembersAlive(this: group);
        return *((float *)&v3 + 1);
      case GROUP_CONFIDENCE:
        LODWORD(v11) = idEncounterGroup::GetConfidenceLevel(this: group);
        v3 = (float)v11;
        return *((float *)&v3 + 1);
      case GROUP_NUMBERS_ADVANTAGE:
        idEncounterGroup::GetNumTargets(this: group);
        v13 = idEncounterGroup::NumLivingMembers(this: v12);
        LODWORD(v15) = v13 - v14;
        v3 = (float)v15;
        return *((float *)&v3 + 1);
      case AVERAGE_ENEMY_HEALTH:
        v3 = idEncounterGroup::AverageEnemyHealthRatio(this: group);
        return *((float *)&v3 + 1);
      case LOWEST_PLAYER_HEALTH:
        v3 = idEncounterGroup::LowestPlayerHealth(this: group);
        return *((float *)&v3 + 1);
      case LOWEST_TARGET_PLAYER_HEALTH:
        v3 = idEncounterGroup::LowestTargetPlayerHealth(this: group);
        return *((float *)&v3 + 1);
      case HIGHEST_PLAYER_HEALTH:
        v3 = idEncounterGroup::HighestPlayerHealth(this: group);
        return *((float *)&v3 + 1);
      case HIGHEST_TARGET_PLAYER_HEALTH:
        v3 = idEncounterGroup::HighestTargetPlayerHealth(this: group);
        return *((float *)&v3 + 1);
      case GROUP_LEADER_HEALTH:
        Leader = idEncounterGroup::GetLeader(this: group);
        if ( Leader == nullptr )
          goto _M502221;
        Leader->aiHealth.GetCurBaseHealth_Impl(this: &Leader->aiHealth);
        return *((float *)&v3 + 1);
      case HAS_ENEMY:
        v17 = 0;
        v43.granularity = 1;
        v43.num = 0;
        v43.size = 64;
        v43.list = v43.staticList;
        v43.memTag = 5;
        v43.listStatic = 1;
        idEncounterGroup::GetLivingMembers(this: group, list: &v43);
        v18 = 0;
        if ( v43.num <= 0 )
          goto LABEL_31;
        v19 = 0;
        break;
      case NUM_IN_COMBAT:
        v30 = 0;
        v45.granularity = 1;
        v45.num = 0;
        v45.size = 64;
        v45.list = v45.staticList;
        v45.memTag = 5;
        v45.listStatic = 1;
        idEncounterGroup::GetLivingMembers(this: group, list: &v45);
        v31 = 0.0;
        if ( v45.num > 0 )
        {
          v32 = 0;
          do
          {
            v33 = v45.list[v32];
            if ( v33 != nullptr && idAI2::GetAlertCycle(this: v33) == ALERTCYCLE_COMBAT )
              v31 = (float)((float)v31 + (float)1.0);
            ++v30;
            ++v32;
          }
          while ( v30 < v45.num );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v45);
        v3 = v31;
        return *((float *)&v3 + 1);
      case NUM_IN_SEARCH:
        v34 = 0;
        v46.granularity = 1;
        v46.num = 0;
        v46.size = 64;
        v46.list = v46.staticList;
        v46.memTag = 5;
        v46.listStatic = 1;
        idEncounterGroup::GetLivingMembers(this: group, list: &v46);
        v35 = 0.0;
        if ( v46.num > 0 )
        {
          v36 = 0;
          do
          {
            v37 = v46.list[v36];
            if ( v37 != nullptr && idAI2::GetAlertCycle(this: v37) == ALERTCYCLE_SEARCH )
              v35 = (float)((float)v35 + (float)1.0);
            ++v34;
            ++v36;
          }
          while ( v34 < v46.num );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v46);
        v3 = v35;
        return *((float *)&v3 + 1);
      case NUM_IN_RELAXED:
        v38 = 0;
        v48.granularity = 1;
        v48.num = 0;
        v48.size = 64;
        v48.list = v48.staticList;
        v48.memTag = 5;
        v48.listStatic = 1;
        idEncounterGroup::GetLivingMembers(this: group, list: &v48);
        v39 = 0.0;
        if ( v48.num > 0 )
        {
          v40 = 0;
          do
          {
            v41 = v48.list[v40];
            if ( v41 != nullptr && idAI2::GetAlertCycle(this: v41) == ALERTCYCLE_RELAXED )
              v39 = (float)((float)v39 + (float)1.0);
            ++v38;
            ++v40;
          }
          while ( v38 < v48.num );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v48);
        v3 = v39;
        return *((float *)&v3 + 1);
      case NUM_WITH_ENEMY:
        v21 = 0;
        v47.granularity = 1;
        v47.num = 0;
        v47.size = 64;
        v47.list = v47.staticList;
        v47.memTag = 5;
        v47.listStatic = 1;
        idEncounterGroup::GetLivingMembers(this: group, list: &v47);
        v22 = 0.0;
        if ( v47.num > 0 )
        {
          v23 = 0;
          do
          {
            v24 = v47.list[v23];
            if ( v24 != nullptr && idAIMemory::GetEnemy(this: &v24->aiVolatile.memory) != nullptr )
              v22 = (float)((float)v22 + (float)1.0);
            ++v21;
            ++v23;
          }
          while ( v21 < v47.num );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v47);
        v3 = v22;
        return *((float *)&v3 + 1);
      case NUM_WITH_PLAYER_ENEMY:
        v25 = 0;
        v44.granularity = 1;
        v44.num = 0;
        v44.size = 64;
        v44.list = v44.staticList;
        v44.memTag = 5;
        v44.listStatic = 1;
        idEncounterGroup::GetLivingMembers(this: group, list: &v44);
        v26 = 0.0;
        if ( v44.num > 0 )
        {
          v27 = 0;
          do
          {
            v28 = v44.list[v27];
            if ( v28 != nullptr )
            {
              Enemy = (idPlayer *)idAIMemory::GetEnemy(this: &v28->aiVolatile.memory);
              if ( idPlayer::CastTo(c: Enemy) != nullptr )
                v26 = (float)((float)v26 + (float)1.0);
            }
            ++v25;
            ++v27;
          }
          while ( v25 < v44.num );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v44);
        v3 = v26;
        return *((float *)&v3 + 1);
      default:
        goto _M502221;
    }
    while ( 1 )
    {
      v20 = v43.list[v17];
      if ( v20 != nullptr && idAIMemory::GetEnemy(this: &v20->aiVolatile.memory) != nullptr )
      {
        if ( this->type == HAS_ENEMY || idAI2::GetAlertCycle(this: v20) == ALERTCYCLE_COMBAT )
          v19 += 2;
        if ( v19 > v43.num )
          break;
      }
      ++v18;
      ++v17;
      if ( v18 >= v43.num )
      {
LABEL_31:
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v43);
        goto _M502221;
      }
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v43);
    v3 = 1.0;
  }
  else
  {
_M502221:
    v3 = 0.0;
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// __unwind$502013
// EA  : 0x82A99144
// RVA : 0x00A99144
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502013()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1808 + 96));
}


// ========================================================================
// __unwind$502014
// EA  : 0x82A9916C
// RVA : 0x00A9916C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502014()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1808 + 1184));
}


// ========================================================================
// __unwind$502015
// EA  : 0x82A99194
// RVA : 0x00A99194
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502015()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1808 + 368));
}


// ========================================================================
// __unwind$502016
// EA  : 0x82A991BC
// RVA : 0x00A991BC
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502016()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1808 + 640));
}


// ========================================================================
// __unwind$502017
// EA  : 0x82A991E4
// RVA : 0x00A991E4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502017()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1808 + 912));
}


// ========================================================================
// __unwind$502018
// EA  : 0x82A9920C
// RVA : 0x00A9920C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502018()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1808 + 1456));
}


// ========================================================================
// ?TriggerTarget@idEncounterGroupExpr@@AAAXPAVidEncounterGroup@@PAVidEntity@@@Z
// EA  : 0x82A99238
// RVA : 0x00A99238
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroupExpr::TriggerTarget(
        idEncounterGroupExpr *this,
        idEncounterGroup *group,
        idAI2 *targetEnt)
{
  idEncounterGroupExpr::activator_t activator; // r11
  idAI2 *Leader; // r3
  idEventArg *v6; // r3
  idEventArg v7; // [sp+50h] [-30h] BYREF

  activator = this->activator;
  this->triggered = true;
  switch ( activator )
  {
    case ACTIVATOR_GROUP_LEADER:
      Leader = idEncounterGroup::GetLeader(this: group);
      goto LABEL_11;
    case ACTIVATOR_RANDOM_GROUP_MEMBER:
      Leader = idEncounterGroup::GetRandomMember(this: group);
      goto LABEL_11;
    case ACTIVATOR_RANDOM_LIVE_GROUP_MEMBER:
      Leader = idEncounterGroup::GetRandomLiveMember(this: group);
      goto LABEL_11;
    case ACTIVATOR_RANDOM_DEAD_GROUP_MEMBER:
      Leader = idEncounterGroup::GetRandomDeadMember(this: group);
      goto LABEL_11;
    case ACTIVATOR_RANDOM_ENEMY:
      Leader = (idAI2 *)idEncounterGroup::GetRandomEnemy(this: group);
      goto LABEL_11;
    case ACTIVATOR_TARGET_PLAYER_LOWEST_HEALTH:
      Leader = (idAI2 *)idEncounterGroup::GetTargetedPlayerWithLowestHealth(this: group);
      goto LABEL_11;
    case ACTIVATOR_TARGET_PLAYER_HIGHEST_HEALTH:
      Leader = (idAI2 *)idEncounterGroup::GetTargetedPlayerWithHighestHealth(this: group);
      goto LABEL_11;
    case ACTIVATOR_PLAYER_LOWEST_HEALTH:
      Leader = (idAI2 *)idEncounterGroup::GetPlayerWithLowestHealth(this: group);
      goto LABEL_11;
    case ACTIVATOR_PLAYER_HIGHEST_HEALTH:
      Leader = (idAI2 *)idEncounterGroup::GetPlayerWithHighestHealth(this: group);
LABEL_11:
      if ( Leader == nullptr )
        goto LABEL_12;
      goto LABEL_13;
    default:
LABEL_12:
      Leader = targetEnt;
LABEL_13:
      v6 = idEventArg::idEventArg(this: &v7, data: Leader);
      idEventReceiver::PostEventMS(
        this: targetEnt,
        ev: &EV_Activate,
        time: *(_DWORD *)&v6->type,
        arg1: (const idEventArg *)LODWORD(v6->value.v[1]));
      return;
  }
}


// ========================================================================
// ?ScoreSearchPoints@idEncounterGroup@@QAAXPBVidAAS2@@ABVidVec3@@11AAV?$idList@H$04@@2@Z
// EA  : 0x82A99348
// RVA : 0x00A99348
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::ScoreSearchPoints(
        idEncounterGroup *this,
        idAAS2 *aas,
        const idVec3 *senseOrigin,
        const idVec3 *senseVelocity,
        const idVec3 *trueOrigin,
        idList<enum encounterGroupRole_t,5> *searchHintGroupings,
        idList<idVehicleState *,5> *numPerGroup)
{
  int x_low; // r9
  float y; // r7
  double v17; // fp3
  double v18; // fp6
  double v19; // fp3
  double v20; // fp29
  double v21; // fp30
  double v22; // fp28
  double v23; // fp11
  double x; // fp10
  int v25; // r28
  int v26; // r29
  int value; // r9
  idAISearchHintGroup *v28; // r3
  idAISearchHintGroup *v29; // r30
  int i; // r29
  const aas2HintNode_t *v31; // r3
  int num; // r10
  int v33; // r30
  int v34; // r11
  double v35; // fp0
  double v36; // fp13
  double v37; // fp0
  encounterGroupRole_t v38[2]; // [sp+50h] [-160h] BYREF
  idEncounterGroup::searchPoint_t v39; // [sp+58h] [-158h] BYREF
  int v40; // [sp+64h] [-14Ch] BYREF
  float v41[6]; // [sp+68h] [-148h] BYREF
  idStr v42; // [sp+80h] [-130h] BYREF
  idStr v43; // [sp+A0h] [-110h] BYREF
  idStr v44; // [sp+C0h] [-F0h] BYREF
  idStr v45[2]; // [sp+E0h] [-D0h] BYREF

  if ( this->searchPointList.num != 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchPointList);
  x_low = SLODWORD(senseVelocity->x);
  y = senseVelocity->y;
  *(float *)&v39.visited = senseVelocity->z;
  v39.hintNodeIndex = x_low;
  v39.searchDist = y;
  _FP6 = (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                       + (float)((float)(*(float *)&v39.visited * *(float *)&v39.visited)
                               + (float)(v39.searchDist * v39.searchDist)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f13 }
  v17 = __frsqrte(_FP4);
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(*(float *)&v39.visited * *(float *)&v39.visited) + (float)(v39.searchDist * v39.searchDist)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                                                              + (float)((float)(*(float *)&v39.visited
                                                                              * *(float *)&v39.visited)
                                                                      + (float)(v39.searchDist * v39.searchDist)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                                                                                              + (float)((float)(*(float *)&v39.visited * *(float *)&v39.visited) + (float)(v39.searchDist * v39.searchDist)))
                                                                                      * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17
                                                      * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                                                                      + (float)((float)(*(float *)&v39.visited
                                                                                      * *(float *)&v39.visited)
                                                                              + (float)(v39.searchDist * v39.searchDist)))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(*(float *)&v39.visited * *(float *)&v39.visited) + (float)(v39.searchDist * v39.searchDist))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                              * (float)v17)
                                                                                      * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(*(float *)&v39.visited * *(float *)&v39.visited) + (float)(v39.searchDist * v39.searchDist)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(*(float *)&v39.visited * *(float *)&v39.visited) + (float)(v39.searchDist * v39.searchDist))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                      * (float)v17))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                                              * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(*(float *)&v39.visited * *(float *)&v39.visited) + (float)(v39.searchDist * v39.searchDist))) * (float)0.5))
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17))
                                              * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                                                              + (float)((float)(*(float *)&v39.visited
                                                                              * *(float *)&v39.visited)
                                                                      + (float)(v39.searchDist * v39.searchDist)))
                                                      * (float)0.5))
                                      * (float)v18)
                              - (float)1.5)
              * (float)v18);
  v20 = (float)((float)(y * (float)v19) * (float)0.0);
  v21 = (float)((float)(*(float *)&x_low * (float)v19) * (float)0.0);
  v22 = (float)((float)(*(float *)&v39.visited * (float)v19) * (float)0.0);
  if ( ai_debugSearch.valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
  {
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorOrange,
      a3: senseOrigin,
      a4: 30000,
      a5: false);
    v23 = senseOrigin->y;
    x = senseOrigin->x;
    v41[2] = senseOrigin->z + (float)((float)((float)(UNITS_PER_INCH_6 * (float)30.0) * (float)12.0) * (float)v22);
    v41[1] = (float)v23 + (float)((float)((float)(UNITS_PER_INCH_6 * (float)30.0) * (float)12.0) * (float)v20);
    v41[0] = (float)x + (float)((float)((float)(UNITS_PER_INCH_6 * (float)30.0) * (float)12.0) * (float)v21);
    ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorOrange,
      a3: senseOrigin,
      a4: v41,
      a5: 1.0);
  }
  idList<idThread *,58>::Clear(this: numPerGroup);
  v25 = 0;
  if ( this->searchHintGroups.num > 0 )
  {
    v40 = 0;
    v26 = 0;
    do
    {
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)numPerGroup,
        obj: (const encounterGroupRole_t *)&v40);
      value = this->searchHintGroups.list[v26].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v28 = (idAISearchHintGroup *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
        && (v29 = idAISearchHintGroup::CastTo(c: v28)) != nullptr )
      {
        idStr::idStr(this: &v42, text: v29->name.data);
        if ( v42.len >= 3 )
        {
          v38[0] = ROLE_NONE;
          idStr::Right(this: v45, result: &v42, len: 3);
          if ( idStr::IsNumeric(s: v45[0].data) )
          {
            v38[0] = atol(nptr: v45[0].data);
          }
          else
          {
            idStr::Right(this: &v44, result: &v42, len: 2);
            if ( idStr::IsNumeric(s: v44.data) )
            {
              v38[0] = atol(nptr: v44.data);
            }
            else
            {
              idStr::Right(this: &v43, result: &v42, len: 1);
              if ( idStr::IsNumeric(s: v43.data) )
                v38[0] = atol(nptr: v43.data);
              else
                idLib::Warning(
                  fmt: "Search hint group names must end in a number. '%s' is an invalid name.",
                  v29->name.data);
              idStr::FreeData(this: &v43);
            }
            idStr::FreeData(this: &v44);
          }
          idList<idAnimWebBlendTree *,5>::Append(this: searchHintGroupings, obj: v38);
          idStr::FreeData(this: v45);
        }
        idStr::FreeData(this: &v42);
      }
      else
      {
        idLib::Warning(
          fmt: "Encounter group %s search hint group list entry %d is not a valid search hint group",
          this->groupName.data,
          v25);
        idLib::Warning(fmt: "Note that search hint group entities should not be renamed due to some code trickery");
      }
      ++v25;
      ++v26;
    }
    while ( v25 < this->searchHintGroups.num );
  }
  for ( i = 1; i < aas->GetNumHintNodes(this: aas); ++i )
  {
    v31 = aas->GetHintNode(this: aas, a2: i);
    if ( v31->hintType == 1 || v31->hintType == 0 )
    {
      num = searchHintGroupings->num;
      v33 = 0;
      if ( num > 0 )
      {
        v34 = 0;
        while ( searchHintGroupings->list[v34] != v31->grouping )
        {
          ++v33;
          ++v34;
          if ( v33 >= num )
            goto LABEL_37;
        }
        if ( v33 != -1 )
        {
          v35 = v31->origin.x;
          v39.hintNodeIndex = i;
          v36 = (float)((float)v35 - senseOrigin->x);
          v39.visited = false;
          v37 = (float)((float)((float)((float)(v31->origin.y - senseOrigin->y) * (float)v20)
                              + (float)((float)v36 * (float)v21))
                      + (float)((float)(v31->origin.z - senseOrigin->z) * (float)v22));
          if ( v37 < 0.0 )
            v37 = (float)((float)((float)((float)((float)(v31->origin.y - senseOrigin->y) * (float)v20)
                                        + (float)((float)v36 * (float)v21))
                                + (float)((float)(v31->origin.z - senseOrigin->z) * (float)v22))
                        * (float)-5.0);
          v39.searchDist = (float)((float)((float)__fabs((float)((float)((float)((float)v36 * (float)-v20)
                                                                       + (float)((float)(v31->origin.y - senseOrigin->y)
                                                                               * (float)v21))
                                                               + (float)((float)(v31->origin.z - senseOrigin->z)
                                                                       * (float)v22)))
                                         * (float)5.0)
                                 + (float)v37)
                         * (float)0.0;
          idList<idEncounterGroup::searchPoint_t,5>::Append(this: &this->searchPointList, obj: &v39);
          ++numPerGroup->list[v33];
        }
      }
    }
LABEL_37:
    ;
  }
}


// ========================================================================
// __unwind$502280
// EA  : 0x82A99814
// RVA : 0x00A99814
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502280()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 128));
}


// ========================================================================
// __unwind$502281
// EA  : 0x82A9983C
// RVA : 0x00A9983C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502281()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 224));
}


// ========================================================================
// __unwind$502282
// EA  : 0x82A99864
// RVA : 0x00A99864
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502282()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 192));
}


// ========================================================================
// __unwind$502283
// EA  : 0x82A9988C
// RVA : 0x00A9988C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502283()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 160));
}


// ========================================================================
// ?UpdateGroupMemberRoles@idEncounterGroup@@QAA_NW4combatStage_t@idCombatStage@@@Z
// EA  : 0x82A998C0
// RVA : 0x00A998C0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::UpdateGroupMemberRoles(
        idEncounterGroup *this,
        idCombatStage::combatStage_t combatStageChange)
{
  int curCombatStage; // r11
  idEncounterGroup *v3; // r27
  idCombatStage::combatStage_t v4; // r26
  idCombatStage *v5; // r17
  idAICombatHint::combatHintType_t v6; // r19
  int num; // r6
  int v8; // r30
  int v9; // r14
  idVec3 *v10; // r10
  encounterGroupRole_t v11; // r28
  int v12; // r11
  char v13; // r11
  float y; // r8
  double v15; // fp29
  float z; // r7
  int v17; // r23
  int v18; // r22
  int v19; // r24
  int v20; // r25
  idAI2 *v21; // r29
  const idDeclAIBehavior *decl; // r20
  int v23; // r26
  int v24; // r21
  double v25; // fp31
  unsigned __int8 v26; // r27
  const aiSenseState_t *EnemySenseState; // r3
  aiSenseState_t *v28; // r30
  idPhysics *Physics; // r14
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idPhysics_vtbl *v31; // r11
  float *v32; // r3
  double v33; // fp10
  double v34; // fp6
  const aiPhysicalState_t *v35; // r3
  double v36; // fp1
  double v37; // fp0
  idPhysics *v38; // r3
  idAICombatHint::combatHintClass_t combatHintClass; // r30
  const idVec3 *v40; // r5
  unsigned int v41; // r4
  idPhysics *v42; // r3
  float *v43; // r3
  double v44; // fp13
  double v45; // fp12
  idPhysics *v46; // r3
  idAICombatHint::combatHintClass_t v47; // r30
  const idVec3 *v48; // r3
  idPhysics *v49; // r3
  float *v50; // r3
  idPhysics *v51; // r28
  idRenderWorld *v52; // r27
  const idColor *v53; // r26
  idRenderWorld_vtbl *v54; // r29
  int v55; // r3
  idPhysics *v56; // r29
  idRenderWorld *v57; // r28
  const idColor *v58; // r27
  __int64 v59; // r6
  __int64 v60; // r10
  __int64 v61; // r8
  va *v62; // r26
  idRenderWorld_vtbl *v63; // r30
  int v64; // r3
  int v65; // r6
  unsigned __int8 v66; // r11
  int v67; // r28
  int v68; // r29
  int v69; // r30
  unsigned __int8 v70; // r8
  encounterGroupRole_t v71; // r5
  int v73; // [sp+8h] [-13E8h]
  int v74; // [sp+Ch] [-13E4h]
  int v75; // [sp+10h] [-13E0h]
  int v76; // [sp+14h] [-13DCh]
  int v77; // [sp+18h] [-13D8h]
  int v78; // [sp+1Ch] [-13D4h]
  unsigned __int8 v79[8]; // [sp+60h] [-1390h] BYREF
  idVec3 v80; // [sp+68h] [-1388h] BYREF
  int v81; // [sp+74h] [-137Ch] BYREF
  const char *v82; // [sp+78h] [-1378h]
  idAI2 **v83; // [sp+7Ch] [-1374h]
  float v84[3]; // [sp+80h] [-1370h] BYREF
  idCVar *v85; // [sp+8Ch] [-1364h]
  idCVar *v86; // [sp+90h] [-1360h]
  idVec3 *v87; // [sp+94h] [-135Ch]
  const char *v88; // [sp+98h] [-1358h]
  idList<unsigned char,37> v89; // [sp+A0h] [-1350h] BYREF
  int v90; // [sp+B0h] [-1340h] BYREF
  idStaticList<idAI2 *,64> v91; // [sp+F0h] [-1300h] BYREF
  idList<enum encounterGroupRole_t,5> v92; // [sp+200h] [-11F0h] BYREF
  int v93; // [sp+210h] [-11E0h] BYREF
  va v94; // [sp+310h] [-10E0h] BYREF

  curCombatStage = this->curCombatStage;
  v3 = this;
  v4 = combatStageChange;
  if ( curCombatStage < 0 )
    return 0;
  if ( curCombatStage >= this->combatStages.num )
    return 0;
  v5 = &this->combatStages.list[curCombatStage];
  if ( v5 == nullptr || v5->rolePriorityList.num == 0 || this->pendingCombatStage != -1 )
    return 0;
  v6 = COMBAT_HINT_ASSAULT_POINT;
  v91.granularity = 1;
  v91.size = 64;
  v91.num = 0;
  v91.memTag = 5;
  v91.list = v91.staticList;
  v91.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this, list: &v91);
  v89.num = 0;
  v89.size = 64;
  v89.granularity = 1;
  v89.list = (unsigned __int8 *)&v90;
  v89.memTag = 5;
  v89.listStatic = 1;
  v92.num = 0;
  v92.size = 64;
  v92.granularity = 1;
  v92.list = (encounterGroupRole_t *)&v93;
  v92.memTag = 5;
  v92.listStatic = 1;
  num = v91.num;
  v8 = 0;
  if ( v91.num > 0 )
  {
    v79[0] = 0;
    v81 = 0;
    do
    {
      idList<unsigned char,25>::Append(this: &v89, obj: v79);
      idList<idAnimWebBlendTree *,5>::Append(this: &v92, obj: (const encounterGroupRole_t *)&v81);
      num = v91.num;
      ++v8;
    }
    while ( v8 < v91.num );
  }
  v9 = 0;
  v81 = 0;
  if ( num > 0 )
  {
    v85 = &ai_debugLevel;
    v82 = "%d";
    v10 = &vec3_origin;
    v86 = &ai_debugEncounterGroupRoles;
    v87 = &vec3_origin;
    v88 = "dEncounterGroup::UpdateGroupMemberRoles - group:%s stage:%s unable to fill bad role %d";
    while ( 1 )
    {
      if ( v3->shouldGroupRush && v9 >= v3->nonGroupRushUnits )
      {
        v11 = ROLE_CHARGE;
        v6 = COMBAT_HINT_MAX;
      }
      else
      {
        v12 = v5->rolePriorityList.num - 1;
        if ( v9 < v12 )
          v12 = v9;
        v11 = v5->rolePriorityList.list[v12];
        if ( v11 <= ROLE_NONE || (v13 = 1, v11 >= ROLE_MAX) )
          v13 = 0;
        if ( v13 == 0 )
        {
          idLib::Warning(fmt: v88, v3->groupName.data, v5->name.data, v11);
LABEL_73:
          num = v91.num;
          goto LABEL_74;
        }
        switch ( v11 )
        {
          case ROLE_DEFEND:
            v6 = COMBAT_HINT_DEFENSE_POINT;
            break;
          case ROLE_ASSAULT:
LABEL_100:
            break;
          case ROLE_FLANK:
            v6 = COMBAT_HINT_FLANK_POINT;
            break;
          default:
            v6 = COMBAT_HINT_MAX;
            goto LABEL_100;
        }
      }
      y = v10->y;
      v15 = 0.0;
      z = v10->z;
      v17 = 999;
      v18 = -1;
      v19 = 0;
      v80.x = v10->x;
      v80.y = y;
      v80.z = z;
      v84[0] = v80.x;
      v84[1] = y;
      v84[2] = z;
      if ( num > 0 )
      {
        v20 = 0;
        while ( 1 )
        {
          if ( v92.list[v20] == ROLE_NONE )
          {
            v21 = v91.list[v20];
            if ( (v21->aiVolatile.groupStatus.condition & 1) == 0 )
            {
              decl = v21->aiEditable.behaviors.decl;
              v23 = 0;
              if ( decl->rolePreferenceOrder.num > 0 )
                break;
            }
          }
LABEL_68:
          ++v19;
          ++v20;
          if ( v19 >= num )
            goto LABEL_69;
        }
        v24 = 0;
        while ( 2 )
        {
          if ( v23 > v17 )
          {
LABEL_67:
            num = v91.num;
            goto LABEL_68;
          }
          if ( decl->rolePreferenceOrder.list[v24] == v11 )
          {
            v25 = 0.0;
            v26 = 0;
            EnemySenseState = idAI2::GetEnemySenseState(this: v21, senseType: AISENSE_MAX);
            v28 = (aiSenseState_t *)EnemySenseState;
            if ( (v11 == ROLE_CHARGE || v11 == ROLE_FLANK_CHARGE || v11 == ROLE_THROW) && EnemySenseState != nullptr )
            {
              Physics = idEntity::GetPhysics(this: v21);
              ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v28);
              v31 = Physics->__vftable;
              v83 = (idAI2 **)ConfirmedPhysicalSafe;
              v32 = (float *)v31->GetOrigin(this: Physics, a2: 0);
              v33 = (float)(v32[1] - *((float *)v83 + 1));
              v34 = (float)(v32[2] - *((float *)v83 + 2));
              v25 = __fsqrts((float)((float)((float)v34 * (float)v34)
                                   + (float)((float)((float)(*v32 - *(float *)v83) * (float)(*v32 - *(float *)v83))
                                           + (float)((float)v33 * (float)v33))));
              v35 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v28);
              v9 = v81;
              v36 = v35->origin.y;
              v37 = v35->origin.z;
              v80.x = v35->origin.x;
              v80.y = v36;
              v80.z = v37;
              goto LABEL_60;
            }
            if ( v6 == COMBAT_HINT_MAX )
              goto LABEL_62;
            v25 = -10.0;
            v38 = idEntity::GetPhysics(this: v21);
            combatHintClass = v21->aiEditable.movement.combatHintClass;
            v40 = v38->GetOrigin(this: v38, a2: 0);
            switch ( v11 )
            {
              case ROLE_DEFEND:
                v41 = 0;
                break;
              case ROLE_ASSAULT:
                v41 = 1;
                break;
              case ROLE_FLANK:
                v41 = 2;
                break;
              default:
LABEL_50:
                v46 = idEntity::GetPhysics(this: v21);
                v47 = v21->aiEditable.movement.combatHintClass;
                v48 = v46->GetOrigin(this: v46, a2: 0);
                if ( (unsigned __int8)idCombatStage::GetClosestHintNodePos(
                                        this: v5,
                                        hintType: v6,
                                        currentPos: v48,
                                        outPos: &v80,
                                        hintClass: v47) != 0 )
                {
                  v49 = idEntity::GetPhysics(this: v21);
                  v50 = (float *)v49->GetOrigin(this: v49, a2: 0);
                  v25 = __fsqrts((float)((float)((float)(v80.z - v50[2]) * (float)(v80.z - v50[2]))
                                       + (float)((float)((float)(v80.x - *v50) * (float)(v80.x - *v50))
                                               + (float)((float)(v80.y - v50[1]) * (float)(v80.y - v50[1])))));
                }
                goto LABEL_52;
            }
            if ( idCombatStage::GetHintWeight(this: v5, hintType: v41, pos: v40, hintClass: combatHintClass) <= 0.0 )
              goto LABEL_50;
            v25 = 1.0;
            v42 = idEntity::GetPhysics(this: v21);
            v43 = (float *)v42->GetOrigin(this: v42, a2: 0);
            v26 = 1;
            v44 = v43[1];
            v45 = v43[2];
            v80.x = *v43;
            v80.y = v44;
            v80.z = v45;
LABEL_52:
            if ( v21->aiVolatile.groupStatus.currentRole == v11 )
              v25 = (float)((float)v25 * (float)0.5);
            if ( (v91.list[v20]->aiVolatile.groupStatus.condition & 8) != 0 )
            {
              if ( v11 == ROLE_DEFEND )
              {
                v25 = (float)((float)v25 * (float)0.5);
              }
              else if ( v11 == ROLE_ASSAULT || v11 == ROLE_FLANK )
              {
                v25 = (float)((float)((float)v25 * (float)2.0) + (float)1.0);
              }
            }
LABEL_60:
            if ( v25 >= 0.0 )
            {
LABEL_62:
              if ( v23 != v17 || v25 < v15 )
              {
                if ( v18 >= 0 )
                  v92.list[v18] = ROLE_NONE;
                v18 = v19;
                v17 = v23;
                v84[0] = v80.x;
                v15 = v25;
                v84[1] = v80.y;
                v84[2] = v80.z;
                v92.list[v20] = v11;
                v89.list[v19] = v26;
              }
            }
          }
          ++v23;
          ++v24;
          if ( v23 >= decl->rolePreferenceOrder.num )
            goto LABEL_67;
          continue;
        }
      }
LABEL_69:
      if ( v86->valueInteger >= 2 && v85->valueInteger > 0 && v18 != -1 )
      {
        v83 = &v91.list[v18];
        v51 = idEntity::GetPhysics(this: *v83);
        v52 = common->RW(this: common);
        v53 = idAICombatHint::HintTypeColor(hintType: v6);
        v54 = v52->__vftable;
        v55 = (int)v51->GetOrigin(this: v51, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const idColor *, int, float *, double))v54->DebugArrow)(
          a1: v52,
          a2: v53,
          a3: v55,
          a4: v84,
          a5: 4.0);
        v83 = &v91.list[v18];
        v56 = idEntity::GetPhysics(this: *v83);
        v57 = common->RW(this: common);
        v58 = idAICombatHint::HintTypeColor(hintType: v6);
        HIDWORD(v59) = v9;
        v62 = va::va(
                this: &v94,
                fmt: v82,
                a3: v59,
                a4: v61,
                a5: v60,
                a6: v73,
                a7: v74,
                a8: v75,
                a9: v76,
                a10: v77,
                a11: v78);
        v63 = v57->__vftable;
        v64 = (int)v56->GetOrigin(this: v56, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, va *, int, int, const idColor *, int, int, _DWORD, double))v63->DebugText)(
          a1: v57,
          a2: v62,
          a3: v64,
          a4: v65,
          a5: v58,
          a6: 1,
          a7: 2048,
          a8: 0,
          a9: 1.0);
        goto LABEL_73;
      }
LABEL_74:
      ++v9;
      v3 = this;
      v6 = COMBAT_HINT_ASSAULT_POINT;
      v81 = v9;
      if ( v9 >= num )
      {
        v4 = combatStageChange;
        break;
      }
      v10 = v87;
    }
  }
  if ( idEncounterGroup::ActiveMemberHighestAlertCycle(this: v3) < 3 || (v66 = 0, (*((_BYTE *)v5 + 92) & 0x10) == 0) )
    v66 = 1;
  v67 = v66;
  v68 = 0;
  if ( v91.num > 0 )
  {
    v69 = 0;
    do
    {
      v82 = (const char *)&v89.list[v68];
      v70 = v89.list[v68];
      v71 = v92.list[v69];
      v82 = (const char *)&v91.list[v69];
      ++v68;
      v67 = (unsigned __int8)idEncounterGroup::SuggestEncounterGroupRole(
                               this: v3,
                               ai: v91.list[v69++],
                               role: v71,
                               combatStageChange: v4,
                               previouslyPlayedOrderVo: v67,
                               alreadyInHintNode: v70)
          | (unsigned __int8)v67;
    }
    while ( v68 < v91.num );
  }
  v3->nextGroupMemberRoleUpdateTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 2048;
  if ( v92.listStatic == 0 || v92.listStatic == 2 )
  {
    if ( v92.list != nullptr )
      idMem::Free(this: &mem, ptr: v92.list, align: ALIGN_16);
    v92.list = nullptr;
    v92.size = 0;
  }
  v92.num = 0;
  if ( v89.listStatic == 0 || v89.listStatic == 2 )
  {
    if ( v89.list != nullptr )
      idMem::Free(this: &mem, ptr: v89.list, align: ALIGN_16);
    v89.list = nullptr;
    v89.size = 0;
  }
  v89.num = 0;
  if ( (v91.listStatic == 0 || v91.listStatic == 2) && v91.list != nullptr )
    idMem::Free(this: &mem, ptr: v91.list, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$502586
// EA  : 0x82A9A1AC
// RVA : 0x00A9A1AC
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502586()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5104 + 240));
}


// ========================================================================
// __unwind$502587
// EA  : 0x82A9A1D4
// RVA : 0x00A9A1D4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502587()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5104 + 160));
}


// ========================================================================
// __unwind$502588
// EA  : 0x82A9A1FC
// RVA : 0x00A9A1FC
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_502588()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5104 + 512));
}


// ========================================================================
// ?CheckTrigger@idEncounterGroupExpr@@QAAXPAVidEncounterGroup@@@Z
// EA  : 0x82A9A440
// RVA : 0x00A9A440
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroupExpr::CheckTrigger(idEncounterGroupExpr *this, idEncounterGroup *group)
{
  int value; // r10
  idEntity *v5; // r3
  idAI2 *v6; // r29

  value = this->target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr )
    {
      v6 = (idAI2 *)idEntity::CastTo(c: v5);
      if ( v6 != nullptr && group != nullptr && (unsigned __int8)idEncounterGroupExpr::Eval(this, owner: group) != 0 )
        idEncounterGroupExpr::TriggerTarget(this, group, targetEnt: v6);
    }
  }
}


// ========================================================================
// ?UpdateLivingMemberCount@idEncounterGroup@@QAAXXZ
// EA  : 0x82A9A4E0
// RVA : 0x00A9A4E0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::UpdateLivingMemberCount(idEncounterGroup *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v10[2]; // [sp+50h] [-150h] BYREF
  idStaticList<idAI2 *,64> v11; // [sp+60h] [-140h] BYREF

  RD_EventBegin(name: "idEncounterGroup::UpdateLivingMemberCount");
  LODWORD(v2) = "idEncounterGroup::UpdateLivingMemberCount";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v2, label: v3);
  v11.granularity = 1;
  v11.size = 64;
  v11.num = 0;
  v11.list = v11.staticList;
  v11.memTag = 5;
  v11.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this, list: &v11);
  this->numLivingMembers = v11.num;
  idEncounterGroup::ActiveMemberHighestAlertCycle(this);
  _FP6 = -(float)(this->recentHeavilyKilledMembers - (float)0.051199999);
  _FP5 = -(float)(this->recentlyKilledMembers - (float)0.051199999);
  _FP4 = -(float)(this->recentlyKilledHeavies - (float)0.051199999);
  __asm { fsel      f3, f6, f13, f10 }
  this->recentHeavilyKilledMembers = _FP3;
  __asm { fsel      f2, f5, f13, f8 }
  this->recentlyKilledMembers = _FP2;
  __asm { fsel      f1, f4, f13, f7 }
  this->recentlyKilledHeavies = _FP1;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v11);
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
}


// ========================================================================
// __unwind$503240
// EA  : 0x82A9A5CC
// RVA : 0x00A9A5CC
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_503240()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 416 + 368));
}


// ========================================================================
// __unwind$503241
// EA  : 0x82A9A5F4
// RVA : 0x00A9A5F4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_503241()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 416 + 80));
}


// ========================================================================
// __unwind$503242
// EA  : 0x82A9A61C
// RVA : 0x00A9A61C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_503242()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 96));
}


// ========================================================================
// ?CheckGroupTriggers@idEncounterGroup@@QAAXXZ
// EA  : 0x82A9A648
// RVA : 0x00A9A648
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::CheckGroupTriggers(idEncounterGroup *this)
{
  int v2; // r30
  int v3; // r31
  int curCombatStage; // r11
  idCombatStage *v5; // r28
  int v6; // r25
  int v7; // r27
  idEncounterGroupExpr *v8; // r31
  int value; // r9
  idEntity *v10; // r3
  idEncounterGroupExpr *v12; // r31
  int v13; // r9
  idEntity *v14; // r3
  idAI2 *v15; // r30

  v2 = 0;
  if ( this->triggers.num > 0 )
  {
    v3 = 0;
    do
    {
      if ( (unsigned __int8)idEncounterGroupExpr::Triggerable(this: &this->triggers.list[v3]) != 0 )
        idEncounterGroupExpr::CheckTrigger(this: &this->triggers.list[v3], group: this);
      ++v2;
      ++v3;
    }
    while ( v2 < this->triggers.num );
  }
  curCombatStage = this->curCombatStage;
  if ( curCombatStage >= 0 && curCombatStage < this->combatStages.num )
  {
    v5 = &this->combatStages.list[curCombatStage];
    if ( v5 != nullptr )
    {
      v6 = 0;
      if ( v5->stageTriggers.num > 0 )
      {
        v7 = 0;
        do
        {
          v8 = &v5->stageTriggers.list[v7];
          value = v8->target.spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
          {
            v10 = gameLocal->entities.ptr[value & 0x1FFF];
            if ( v10 != nullptr && idEntity::CastTo(c: v10) != nullptr && (!v8->triggered || !v8->triggerOnce) )
            {
              v12 = &v5->stageTriggers.list[v7];
              v13 = v12->target.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13 )
              {
                v14 = gameLocal->entities.ptr[v13 & 0x1FFF];
                if ( v14 != nullptr )
                {
                  v15 = (idAI2 *)idEntity::CastTo(c: v14);
                  if ( v15 != nullptr && (unsigned __int8)idEncounterGroupExpr::Eval(this: v12, owner: this) != 0 )
                    idEncounterGroupExpr::TriggerTarget(this: v12, group: this, targetEnt: v15);
                }
              }
            }
          }
          ++v6;
          ++v7;
        }
        while ( v6 < v5->stageTriggers.num );
      }
    }
  }
}


// ========================================================================
// ?SetCurrentCombatStage@idEncounterGroup@@QAA_NH@Z
// EA  : 0x82A9A808
// RVA : 0x00A9A808
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

int __fastcall idEncounterGroup::SetCurrentCombatStage(idEncounterGroup *this, int i)
{
  int GameMs; // r3
  int curCombatStage; // r11
  idCombatStage *v6; // r11
  const char *data; // r29
  char *v8; // r30
  int v9; // r3
  int v10; // r11
  idCombatStage *v11; // r10
  idCombatStage *v12; // r3
  int v13; // r11
  idCombatStage *v14; // r11
  idPlayer *Player; // r3

  if ( this->curCombatStage != i )
  {
    this->curCombatStage = i;
    this->pendingCombatStage = -1;
    this->pendingCombatStageTime = -1;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    curCombatStage = this->curCombatStage;
    this->stageChangeTime = GameMs;
    if ( curCombatStage >= 0 && curCombatStage < this->combatStages.num )
    {
      v6 = &this->combatStages.list[curCombatStage];
      if ( v6 != nullptr )
      {
        if ( ai_debugLevel.valueInteger != 0 && ai_debugEncounterGroupRoles.valueInteger > 0 )
        {
          data = v6->name.data;
          v8 = this->groupName.data;
          v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idLib::Printf(fmt: "[%6d] group: %-20s changing to combat stage %d:%s\n", v9, v8, i, data);
        }
        v10 = this->curCombatStage;
        if ( v10 < 0 || v10 >= this->combatStages.num )
          v11 = nullptr;
        else
          v11 = &this->combatStages.list[v10];
        if ( v11->stageType == COMBAT_STAGE_NO_GOODWILL )
          this->groupGoodWill = false;
        if ( v10 < 0 || v10 >= this->combatStages.num )
          v12 = nullptr;
        else
          v12 = &this->combatStages.list[v10];
        idCombatStage::CategorizeHintGroupCombatNodes(this: v12);
        v13 = this->curCombatStage;
        if ( v13 < 0 || v13 >= this->combatStages.num )
          v14 = nullptr;
        else
          v14 = &this->combatStages.list[v13];
        idEncounterGroup::UpdateGroupMemberRoles(this, combatStageChange: v14->stageType);
        if ( idGameLocal::GetPlayer(this: gameLocal, i: 0) != nullptr )
        {
          Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
          Player->previousCoverCheckPos.x = Player->previousCoverCheckPos.x + (float)10000.0;
        }
      }
    }
  }
  return 1;
}


// ========================================================================
// ?UpdateConfidenceLevel@idEncounterGroup@@AAAXXZ
// EA  : 0x82A9A9D0
// RVA : 0x00A9A9D0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::UpdateConfidenceLevel(idEncounterGroup *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v4; // r25
  int v5; // r26
  double v6; // fp31
  int v7; // r29
  __int64 v8; // r11
  int value; // r9
  idAI2 *v10; // r3
  idAI2 *v11; // r3
  idAI2 *v12; // r30
  idPLog *pLog; // r29
  idPLog::logEntry_t *v14; // r30
  int v15; // r3
  __int64 totalTicks; // r11
  __int64 v17; // r9
  idPLogScope v18[4]; // [sp+50h] [-80h] BYREF

  RD_EventBegin(name: "idEncounterGroup::UpdateConfidenceLevel");
  LODWORD(v2) = "idEncounterGroup::UpdateConfidenceLevel";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v18, pl: &::pLog, gMask: v2, label: v3);
  v4 = 0;
  v5 = 0;
  v6 = 0.0;
  if ( this->members.num > 0 )
  {
    v7 = 0;
    do
    {
      HIDWORD(v8) = gameLocal;
      value = this->members.list[v7].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v10 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v10 != nullptr )
        {
          v11 = idAI2::CastTo(c: v10);
          v12 = v11;
          if ( v11 != nullptr )
          {
            ++v4;
            if ( !v11->IsDead(this: v11) )
              v6 = (float)((float)(v12->aiHealth.GetBaseHealthRatio_Impl(this: &v12->aiHealth) * (float)4.0) + (float)v6);
          }
        }
      }
      ++v5;
      ++v7;
    }
    while ( v5 < this->members.num );
    if ( v4 > 0 )
    {
      LODWORD(v8) = v4;
      v18[1] = (idPLogScope)v8;
      v6 = (float)((float)v6 / (float)v8);
    }
    if ( v6 >= 0.0 )
    {
      if ( v6 > 4.0 )
        v6 = 4.0;
    }
    else
    {
      v6 = 0.0;
    }
  }
  this->confidenceLevel = (int)v6;
  if ( v18[0].logIndex >= 0 )
  {
    pLog = v18[0].pLog;
    v14 = &v18[0].pLog->logEntries.list[v18[0].logIndex];
    v15 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v14->totalTicks;
    HIDWORD(totalTicks) = v14->parent;
    LODWORD(v17) = v15 - totalTicks;
    v14->totalTicks = v17;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$503663
// EA  : 0x82A9AB80
// RVA : 0x00A9AB80
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_503663()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$503664
// EA  : 0x82A9ABA8
// RVA : 0x00A9ABA8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_503664()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 80));
}


// ========================================================================
// ?UpdateAnyMemberHighestAlertCycle@idEncounterGroup@@AAAXXZ
// EA  : 0x82A9ABD8
// RVA : 0x00A9ABD8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::UpdateAnyMemberHighestAlertCycle(idEncounterGroup *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v4; // r25
  int v5; // r28
  int value; // r9
  idAI2 *v7; // r3
  idAI2 *v8; // r3
  _DWORD *v9; // r30
  alertCycle_t highestMemberAlertCycle; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v12; // r30
  int v13; // r3
  __int64 totalTicks; // r11
  __int64 v15; // r9
  idPLogScope v16; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idEncounterGroup::UpdateAnyMemberHighestAlertCycle");
  LODWORD(v2) = "idEncounterGroup::UpdateAnyMemberHighestAlertCycle";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v16, pl: &::pLog, gMask: v2, label: v3);
  v4 = 0;
  if ( this->members.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->members.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v7 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v7 != nullptr )
        {
          v8 = idAI2::CastTo(c: v7);
          v9 = &v8->__vftable;
          if ( v8 != nullptr
            && !v8->IsDead(this: v8)
            && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v9) == 0 )
          {
            highestMemberAlertCycle = v9[14599];
            if ( this->highestMemberAlertCycle > highestMemberAlertCycle )
              highestMemberAlertCycle = this->highestMemberAlertCycle;
            this->highestMemberAlertCycle = highestMemberAlertCycle;
          }
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->members.num );
  }
  if ( v16.logIndex >= 0 )
  {
    pLog = v16.pLog;
    v12 = &v16.pLog->logEntries.list[v16.logIndex];
    v13 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v12->totalTicks;
    HIDWORD(totalTicks) = v12->parent;
    LODWORD(v15) = v13 - totalTicks;
    v12->totalTicks = v15;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$503763
// EA  : 0x82A9AD20
// RVA : 0x00A9AD20
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_503763()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$503764
// EA  : 0x82A9AD48
// RVA : 0x00A9AD48
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_503764()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?Init@idEncounterGroup@@QAAXPBDV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@@Z
// EA  : 0x82A9AE40
// RVA : 0x00A9AE40
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::Init(
        idEncounterGroup *this,
        const char *groupName_,
        const idHandle<short,enum invalidEncounterGroup_t,-1> *handle_)
{
  __int16 v4; // r30

  v4 = (__int16)handle_;
  idStr::operator=(this: &this->groupName, text: groupName_);
  this->handle.value = v4;
  idEncounterGroup::SetCurrentCombatStage(this, i: this->initialCombatStage);
}


// ========================================================================
// ?Add@idEncounterGroup@@QAAXPAVidAI2@@@Z
// EA  : 0x82A9AE88
// RVA : 0x00A9AE88
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::Add(idEncounterGroup *this, idAI2 *ai)
{
  idFaction *p_faction; // r31
  idFaction *(__fastcall *GetFaction)(struct idAI2 *); // ctr
  const idDeclFaction **v6; // r3
  const idFaction *v7; // r3
  const char *String; // r29
  idFaction *v9; // r3
  const char *v10; // r6

  if ( idEncounterGroup::FindIndex(this, ai) < 0 )
  {
    p_faction = &this->faction;
    GetFaction = ai->GetFaction;
    if ( this->faction.myFaction != nullptr )
    {
      v7 = GetFaction(this: ai);
      if ( idFaction::GetAttitudeTowards(this: &this->faction, otherFaction: v7) < ATTITUDE_NEUTRAL )
      {
        if ( p_faction->myFaction != nullptr )
          String = idLocalization::GetString(inString: p_faction->myFaction->factionNameId.data);
        else
          String = &byte_8200D768;
        v9 = ai->GetFaction(this: ai);
        if ( v9->myFaction != nullptr )
          v10 = idLocalization::GetString(inString: v9->myFaction->factionNameId.data);
        else
          v10 = &byte_8200D768;
        idLib::Warning(
          fmt: "AI '%s' in group '%s', but ai has faction '%s' and isn't liked by faction '%s'",
          ai->name.data,
          this->groupName.data,
          v10,
          String);
      }
    }
    else
    {
      v6 = (const idDeclFaction **)GetFaction(this: ai);
      idFaction::SetDeclFaction(this: &this->faction, faction: *v6, clearRelationships: true);
    }
    if ( this->members.num >= 63 )
      idLib::Error(fmt: "Group '%s' has too many members. The max is %d.", this->groupName.data, 64);
    idList<idEntityPtr<idAI2>,5>::Alloc(this: &this->members)->spawnId.value = (gameLocal->spawnIds.ptr[ai->entityNumber] << 13)
                                                                             | ai->entityNumber;
  }
}


// ========================================================================
// ?Think@idEncounterGroup@@QAAXXZ
// EA  : 0x82A9AFD0
// RVA : 0x00A9AFD0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::Think(idEncounterGroup *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v4; // r5
  int v5; // r6
  idStaticList<idEncounterGroup::target_t,16> *p_targetList; // r9
  int v7; // r8
  int num; // ctr
  int v9; // r11
  idEncounterGroup::target_t *v10; // r10
  idEncounterGroup::target_t *v11; // r7
  int initialCombatStage; // r4
  idPLog *v13; // r29
  idPLog::logEntry_t *v14; // r30
  int v15; // r3
  __int64 v16; // r11
  __int64 v17; // r9
  int v18; // r23
  int v19; // r25
  int value; // r9
  idEntity *v21; // r3
  idEntity *v22; // r3
  idEntity *v23; // r27
  int v24; // r29
  int GameMs; // r3
  int curCombatStage; // r10
  idAI2 *Speaker; // r26
  int v28; // r29
  int v29; // r28
  int groupRushTime; // r11
  int v31; // r14
  idPhysics *Physics; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v34; // r30
  int v35; // r3
  __int64 totalTicks; // r11
  __int64 v37; // r9
  signed int v38; // [sp+50h] [-D0h]
  idPLogScope v39; // [sp+58h] [-C8h] BYREF
  idAuditResults v40[6]; // [sp+60h] [-C0h] BYREF

  RD_EventBegin(name: "idEncounterGroup::Think");
  LODWORD(v2) = "idEncounterGroup::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v39, pl: &::pLog, gMask: v2, label: v3);
  idEncounterGroup::ResolveChildReferences(this);
  v4 = idAccolade::Count(this: &clientGame->gameTimeManager) - 2;
  v5 = this->targetList.num - 1;
  if ( v5 >= 0 )
  {
    p_targetList = &this->targetList;
    v7 = v5;
    num = this->targetList.num;
    do
    {
      if ( p_targetList->list[v7].frame < v4 && v5 >= 0 )
      {
        v9 = this->targetList.num;
        if ( v5 < v9 )
        {
          this->targetList.num = v9 - 1;
          if ( v5 != v9 - 1 )
          {
            v10 = &p_targetList->list[v9 - 1];
            v11 = &p_targetList->list[v7];
            v11->target.spawnId.value = v10->target.spawnId.value;
            v11->frame = v10->frame;
          }
        }
      }
      --v5;
      --v7;
      --num;
    }
    while ( num != 0 );
  }
  idEncounterGroup::UpdateLivingMemberCount(this);
  idEncounterGroup::UpdateConfidenceLevel(this);
  idEncounterGroup::UpdateAnyMemberHighestAlertCycle(this);
  if ( this->curCombatStage == -1 )
  {
    initialCombatStage = this->initialCombatStage;
LABEL_14:
    idEncounterGroup::SetCurrentCombatStage(this, i: initialCombatStage);
    goto LABEL_15;
  }
  if ( this->pendingCombatStage != -1
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->pendingCombatStageTime )
  {
    initialCombatStage = this->pendingCombatStage;
    goto LABEL_14;
  }
LABEL_15:
  idEncounterGroup::UpdateGroupGoodWill(this);
  idEncounterGroup::UpdateFiringConditions(this);
  idEncounterGroup::CheckGroupTriggers(this);
  if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= this->nextGroupMemberRoleUpdateTime )
    idEncounterGroup::UpdateGroupMemberRoles(this, combatStageChange: COMBAT_STAGE_MAX);
  if ( ai_debugLevel.valueInteger > 0 && idEncounterGroup::NumLivingMembers(this) > 0 )
    idEncounterGroup::DebugDrawCombatStage(
      this,
      duration: 512,
      normalNodes: ai_debugEncounterGroupRoles.valueInteger >= 2,
      grenadeHints: ai_debugGrenadeHints.valueInteger != 0);
  if ( idEncounterGroup::NumLivingMembers(this) != 0 )
  {
    v18 = 0;
    if ( this->targetList.num > 0 )
    {
      v19 = 0;
      do
      {
        value = this->targetList.list[v19].target.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v21 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v21 != nullptr )
          {
            v22 = idEntity::CastTo(c: v21);
            v23 = v22;
            if ( v22 != nullptr )
            {
              v24 = (int)v22->GetAuditor(this: v22);
              if ( v24 != 0 )
              {
                idAuditResults::idAuditResults(this: v40);
                GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                (*(void (__fastcall **)(int, idEncounterGroup *, idEntity *, int, idAuditResults *))(*(_DWORD *)v24 + 8))(
                  a1: v24,
                  a2: this,
                  a3: v23,
                  a4: GameMs,
                  a5: v40);
                if ( v40[0].assaultPrimitiveBreached )
                {
                  v38 = this->combatStages.num;
                  if ( v38 > 0 )
                  {
                    curCombatStage = this->curCombatStage;
                    __twllei(v38, 0);
                    __twlgei(v38 & ~(__ROL4__(curCombatStage + 1, 1) - 1), 0xFFFFFFFF);
                    idEncounterGroup::SetCurrentCombatStage(this, i: (curCombatStage + 1) % v38);
                  }
                }
                Speaker = idEncounterGroup::FindSpeaker(
                            this,
                            enemy: v23,
                            mustBeNearLastVisPos: false,
                            mustBeVisible: false,
                            excludeAI: nullptr);
                if ( v40[0].shouldGrenade )
                  idEncounterGroup::SetLivingMemberCondition(this, condition: 1024, value: true);
                if ( Speaker != nullptr )
                {
                  v28 = ai_keepShootingNoSight.valueInteger + 2000;
                  v29 = ai_keepShootingNoSight.valueInteger + 10000;
                  if ( v40[0].movement <= (unsigned int)AUDITMOVEMENT_CHARGING
                    && v40[0].movement != AUDITMOVEMENT_RETREATING
                    && v40[0].movement != AUDITMOVEMENT_FALLINGBACK
                    && (v40[0].movement == AUDITMOVEMENT_WAITING || v40[0].movement == AUDITMOVEMENT_UNKNOWN)
                    && this->highestMemberAlertCycle > ALERTCYCLE_SEARCH
                    && (idEncounterGroup::GetCurrentCombatStage(this) == nullptr
                     || idEncounterGroup::GetCurrentCombatStage(this)->stageType >= COMBAT_STAGE_DEFAULT) )
                  {
                    if ( idEncounterGroup::NumLivingMembers(this) <= this->nonGroupRushUnits )
                    {
                      this->shouldGroupRush = false;
                    }
                    else if ( !this->shouldGroupRush )
                    {
                      groupRushTime = this->groupRushTime;
                      if ( groupRushTime >= 0 && v40[0].timeSinceSensed > 1000 * groupRushTime )
                      {
                        this->shouldGroupRush = true;
                        if ( ai_debugLevel.valueInteger > 0 && ai_debugEncounterGroupRoles.valueInteger > 0 )
                          idLib::Printf(fmt: "%s group rushing idle player\n", this->groupName.data);
                      }
                    }
                    v31 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                    if ( v31 - idEncounterGroup::LastLivingMemberSeenEnemytime(this) > v28 )
                    {
                      if ( this->shouldGroupRush || v40[0].timeSinceSensed <= v29 )
                      {
                        if ( v40[0].timeSinceSensed > v28 )
                        {
                          Physics = idEntity::GetPhysics(this: v23);
                          Physics->GetOrigin(this: Physics, a2: 0);
                        }
                      }
                      else
                      {
                        idAI2::UseTauntChatterVO(this: Speaker);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        ++v18;
        ++v19;
      }
      while ( v18 < this->targetList.num );
    }
    if ( v39.logIndex >= 0 )
    {
      pLog = v39.pLog;
      v34 = &v39.pLog->logEntries.list[v39.logIndex];
      v35 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v34->totalTicks;
      HIDWORD(totalTicks) = v34->parent;
      LODWORD(v37) = v35 - totalTicks;
      v34->totalTicks = v37;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else if ( v39.logIndex >= 0 )
  {
    v13 = v39.pLog;
    v14 = &v39.pLog->logEntries.list[v39.logIndex];
    v15 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v16 = v14->totalTicks;
    HIDWORD(v16) = v14->parent;
    LODWORD(v17) = v15 - v16;
    v14->totalTicks = v17;
    v13->lastEntry = HIDWORD(v16);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$504065
// EA  : 0x82A9B500
// RVA : 0x00A9B500
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504065()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 288 + 124));
}


// ========================================================================
// __unwind$504066
// EA  : 0x82A9B528
// RVA : 0x00A9B528
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504066()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 288 + 88));
}


// ========================================================================
// ??0idEncounterGroup@@QAA@XZ
// EA  : 0x82A9B5C0
// RVA : 0x00A9B5C0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

idEncounterGroup *__fastcall idEncounterGroup::idEncounterGroup(idEncounterGroup *this)
{
  __int16 *p_granularity; // r11
  int i; // ctr

  this->groupName.len = 0;
  this->groupName.allocedAndFlag = 20;
  this->groupName.data = this->groupName.baseBuffer;
  this->groupName.baseBuffer[0] = 0;
  this->childGroups.list = nullptr;
  this->childGroups.granularity = 0;
  this->childGroups.memTag = 5;
  this->childGroups.listStatic = 0;
  this->childGroups.size = 0;
  this->childGroups.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->childGroups);
  this->childGroupNames.granularity = 0;
  this->childGroupNames.memTag = 5;
  this->childGroupNames.listStatic = 0;
  this->childGroupNames.list = nullptr;
  this->childGroupNames.size = 0;
  this->childGroupNames.num = 0;
  this->spawnState.state = DEFAULT;
  this->spawnState.target.spawnId.value = 0x1FFF;
  this->ownGroupAlertState.state = DEFAULT;
  this->ownGroupAlertState.target.spawnId.value = 0x1FFF;
  this->otherGroupAlertState.state = DEFAULT;
  this->otherGroupAlertState.target.spawnId.value = 0x1FFF;
  this->enabled = true;
  this->leader.spawnId.value = 0x1FFF;
  this->maxSimultaneousFirers = 2;
  this->noRageMemberCount = 2;
  this->nonGroupRushUnits = 99;
  this->groupRushTime = 15;
  this->minGrenadeRethrowTime = 10;
  this->triggers.list = nullptr;
  this->triggers.granularity = 0;
  this->triggers.memTag = 5;
  this->triggers.listStatic = 0;
  this->triggers.size = 0;
  this->triggers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggers);
  this->maxMembers = 0;
  this->members.list = nullptr;
  this->members.granularity = 0;
  this->members.memTag = 5;
  this->members.listStatic = 0;
  this->members.size = 0;
  this->members.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->members);
  this->numLivingMembers = 0;
  this->numDeadMembers = 0;
  this->recentHeavilyKilledMembers = 0.0;
  this->recentlyKilledMembers = 0.0;
  this->recentlyKilledHeavies = 0.0;
  idFaction::idFaction(this: &this->faction);
  this->highestMemberAlertCycle = ALERTCYCLE_RELAXED;
  this->anyMemberHasSeenDeadBody = false;
  this->confidenceLevel = AICONFIDENCE_FEARLESS;
  this->shouldAmbush = false;
  *(_WORD *)&this->shouldGroupRush = 1;
  this->nextGroupMemberRoleUpdateTime = -1;
  this->nextGrenadeTime = 0;
  this->handle.value = -1;
  this->active = false;
  idAIVoiceController::idAIVoiceController(this: &this->voiceController, controllerType_: VC_GROUP);
  this->searchPointList.list = nullptr;
  this->searchPointList.granularity = 0;
  this->searchPointList.memTag = 5;
  this->searchPointList.listStatic = 0;
  this->searchPointList.size = 0;
  this->searchPointList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchPointList);
  this->curCombatStage = -1;
  this->pendingCombatStage = -1;
  this->pendingCombatStageTime = -1;
  this->stageChangeTime = -1;
  this->combatStages.granularity = 0;
  this->combatStages.memTag = 5;
  this->combatStages.listStatic = 0;
  this->combatStages.list = nullptr;
  this->combatStages.size = 0;
  this->combatStages.num = 0;
  this->initialCombatStage = 0;
  this->searchHintGroups.list = nullptr;
  this->searchHintGroups.granularity = 0;
  this->searchHintGroups.memTag = 5;
  this->searchHintGroups.listStatic = 0;
  this->searchHintGroups.size = 0;
  this->searchHintGroups.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchHintGroups);
  this->targetList.num = 0;
  this->targetList.granularity = 1;
  this->targetList.size = 16;
  this->targetList.list = this->targetList.staticList;
  p_granularity = &this->targetList.granularity;
  this->targetList.memTag = 5;
  this->targetList.listStatic = 1;
  for ( i = 16; i != 0; --i )
  {
    *((_DWORD *)p_granularity + 1) = 0x1FFF;
    p_granularity += 4;
    *(_DWORD *)p_granularity = -1;
  }
  this->ownGroupAlertState.state = DEFAULT;
  this->otherGroupAlertState.state = NOTHING;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchPointList);
  idFaction::SetDeclFaction(this: &this->faction, faction: nullptr, clearRelationships: true);
  *(_BYTE *)&this->goodWillSettings = *(_BYTE *)&this->goodWillSettings & 7 | 0xD8;
  this->goodWillSettings.damageScale = 1.0;
  return this;
}


// ========================================================================
// __unwind$504358
// EA  : 0x82A9B864
// RVA : 0x00A9B864
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504358()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$504359
// EA  : 0x82A9B88C
// RVA : 0x00A9B88C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504359()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 32));
}


// ========================================================================
// __unwind$504360
// EA  : 0x82A9B8B8
// RVA : 0x00A9B8B8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504360()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 192 + 212) + 48));
}


// ========================================================================
// __unwind$504361
// EA  : 0x82A9B8E4
// RVA : 0x00A9B8E4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504361()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 116));
}


// ========================================================================
// __unwind$504362
// EA  : 0x82A9B910
// RVA : 0x00A9B910
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504362()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 136));
}


// ========================================================================
// __unwind$504363
// EA  : 0x82A9B93C
// RVA : 0x00A9B93C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504363()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 192 + 212) + 172));
}


// ========================================================================
// __unwind$504364_0
// EA  : 0x82A9B968
// RVA : 0x00A9B968
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504364_0()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 192 + 212) + 224));
}


// ========================================================================
// __unwind$504365_0
// EA  : 0x82A9B994
// RVA : 0x00A9B994
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504365_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 280));
}


// ========================================================================
// __unwind$504366_0
// EA  : 0x82A9B9C0
// RVA : 0x00A9B9C0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504366_0()
{
  int v0; // r12

  idList<idCombatStage,5>::Clear(this: (idList<idCombatStage,5> *)(*(_DWORD *)(v0 - 192 + 212) + 312));
}


// ========================================================================
// __unwind$504367_0
// EA  : 0x82A9B9EC
// RVA : 0x00A9B9EC
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504367_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 332));
}


// ========================================================================
// __unwind$504368_0
// EA  : 0x82A9BA18
// RVA : 0x00A9BA18
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504368_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 348));
}


// ========================================================================
// ??1idEncounterGroup@@QAA@XZ
// EA  : 0x82A9BA50
// RVA : 0x00A9BA50
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::~idEncounterGroup(idEncounterGroup *this)
{
  idCombatStage *list; // r3
  idStr *v3; // r3

  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targetList);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchHintGroups);
  if ( this->combatStages.listStatic == 0 || this->combatStages.listStatic == 2 )
  {
    list = this->combatStages.list;
    if ( list != nullptr )
      idListArrayDelete<idCombatStage>(ptr: list, num: this->combatStages.size);
    this->combatStages.list = nullptr;
    this->combatStages.size = 0;
  }
  this->combatStages.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchPointList);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->voiceController);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->faction.relationships);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->members);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggers);
  if ( this->childGroupNames.listStatic == 0 || this->childGroupNames.listStatic == 2 )
  {
    v3 = this->childGroupNames.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->childGroupNames.size);
    this->childGroupNames.list = nullptr;
    this->childGroupNames.size = 0;
  }
  this->childGroupNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->childGroups);
  idStr::FreeData(this: &this->groupName);
}


// ========================================================================
// __unwind$504707
// EA  : 0x82A9BB28
// RVA : 0x00A9BB28
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504707()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$504708
// EA  : 0x82A9BB50
// RVA : 0x00A9BB50
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504708()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// __unwind$504709
// EA  : 0x82A9BB7C
// RVA : 0x00A9BB7C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504709()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$504710
// EA  : 0x82A9BBA8
// RVA : 0x00A9BBA8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504710()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 116));
}


// ========================================================================
// __unwind$504711
// EA  : 0x82A9BBD4
// RVA : 0x00A9BBD4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504711()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$504712
// EA  : 0x82A9BC00
// RVA : 0x00A9BC00
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504712()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 112 + 132) + 172));
}


// ========================================================================
// __unwind$504713
// EA  : 0x82A9BC2C
// RVA : 0x00A9BC2C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504713()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 112 + 132) + 224));
}


// ========================================================================
// __unwind$504714
// EA  : 0x82A9BC58
// RVA : 0x00A9BC58
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504714()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 280));
}


// ========================================================================
// __unwind$504715
// EA  : 0x82A9BC84
// RVA : 0x00A9BC84
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504715()
{
  int v0; // r12

  idList<idCombatStage,5>::Clear(this: (idList<idCombatStage,5> *)(*(_DWORD *)(v0 - 112 + 132) + 312));
}


// ========================================================================
// __unwind$504716
// EA  : 0x82A9BCB0
// RVA : 0x00A9BCB0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_504716()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 332));
}


// ========================================================================
// ?UpdateTargetList@idEncounterGroup@@QAAXABVidTargetList@@@Z
// EA  : 0x82A9BCE0
// RVA : 0x00A9BCE0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroup::UpdateTargetList(idEncounterGroup *this, const idTargetList *targets)
{
  int v4; // r22
  int v5; // r24
  idAIEntityState *es; // r28
  int num; // r8
  int v8; // r31
  int v9; // r11
  int v10; // r11
  int size; // r10
  idEncounterGroup::target_t *list; // r9
  idEncounterGroup::target_t *v13; // r30
  idEntity *Entity; // r3

  v4 = 0;
  if ( targets->viableTargets.num > 0 )
  {
    v5 = 0;
    do
    {
      es = (idAIEntityState *)targets->targetCache->targets.list[targets->viableTargets.list[v5]].es;
      if ( es != nullptr )
      {
        num = this->targetList.num;
        v8 = 0;
        if ( num <= 0 )
          goto LABEL_8;
        v9 = 0;
        while ( this->targetList.list[v9].target.spawnId.value != es->spawnId.value )
        {
          ++v8;
          ++v9;
          if ( v8 >= num )
            goto LABEL_8;
        }
        if ( v8 < 0 )
        {
LABEL_8:
          if ( num == this->targetList.size )
            return;
          idList<idEncounterGroup::target_t,5>::PreAllocateWithGranularity(
            this: &this->targetList,
            newSize: this->targetList.num + 1);
          v10 = this->targetList.num;
          size = this->targetList.size;
          list = this->targetList.list;
          if ( v10 >= size )
          {
            v13 = &list[size - 1];
          }
          else
          {
            v13 = &list[v10];
            this->targetList.num = v10 + 1;
          }
          Entity = idAIEntityState::GetEntity(this: es);
          if ( Entity != nullptr )
            v13->target.spawnId.value = (gameLocal->spawnIds.ptr[Entity->entityNumber] << 13) | Entity->entityNumber;
          else
            v13->target.spawnId.value = 0x1FFF;
          v13->frame = idAccolade::Count(this: &clientGame->gameTimeManager);
        }
        else
        {
          this->targetList.list[v8].frame = idAccolade::Count(this: &clientGame->gameTimeManager);
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < targets->viableTargets.num );
  }
}


// ========================================================================
// ??0idEncounterGroupMgr@@QAA@XZ
// EA  : 0x82A9BE60
// RVA : 0x00A9BE60
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

idEncounterGroupMgr *__fastcall idEncounterGroupMgr::idEncounterGroupMgr(idEncounterGroupMgr *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idEncounterGroupMgr_vtbl *)&idEncounterGroupMgr::`vftable';
  this->groups.granularity = 0;
  this->groups.memTag = 5;
  this->groups.listStatic = 0;
  this->groups.list = nullptr;
  this->groups.size = 0;
  this->groups.num = 0;
  return this;
}


// ========================================================================
// __unwind$505076
// EA  : 0x82A9BED0
// RVA : 0x00A9BED0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_505076()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idEncounterGroupMgr@@UAA@XZ
// EA  : 0x82A9BF00
// RVA : 0x00A9BF00
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __fastcall idEncounterGroupMgr::~idEncounterGroupMgr(idEncounterGroupMgr *this)
{
  idEncounterGroup *list; // r3
  idEncounterGroup *v3; // r3

  this->__vftable = (idEncounterGroupMgr_vtbl *)&idEncounterGroupMgr::`vftable';
  if ( this->groups.listStatic == 0 || this->groups.listStatic == 2 )
  {
    list = this->groups.list;
    if ( list != nullptr )
      idListArrayDelete<idEncounterGroup>(ptr: list, num: this->groups.size);
    this->groups.list = nullptr;
    this->groups.size = 0;
  }
  this->groups.num = 0;
  if ( this->groups.listStatic == 0 || this->groups.listStatic == 2 )
  {
    v3 = this->groups.list;
    if ( v3 != nullptr )
      idListArrayDelete<idEncounterGroup>(ptr: v3, num: this->groups.size);
    this->groups.list = nullptr;
    this->groups.size = 0;
  }
  this->groups.num = 0;
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$505308
// EA  : 0x82A9BFA0
// RVA : 0x00A9BFA0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_505308()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$505309
// EA  : 0x82A9BFC8
// RVA : 0x00A9BFC8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void _unwind_505309()
{
  int v0; // r12

  idList<idEncounterGroup,5>::Clear(this: (idList<idEncounterGroup,5> *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}


// ========================================================================
// `dynamic initializer for 'ai_debugGrenadeHints''
// EA  : 0x83369138
// RVA : 0x01369138
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugGrenadeHints__()
{
  idCVar::idCVar(
    this: &ai_debugGrenadeHints,
    name: "ai_debugGrenadeHints",
    value: "0",
    flags: 2,
    description: "1: show encounter group grenade hint timimgsf",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugGrenadeHints__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugGoodWill''
// EA  : 0x83369190
// RVA : 0x01369190
// PDB : w:\tech5\tungsten\game\ai\encountergroups.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugGoodWill__()
{
  idCVar::idCVar(
    this: &ai_debugGoodWill,
    name: "ai_debugGoodWill",
    value: "0",
    flags: 1,
    description: "1: show good will settings",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugGoodWill__);
}

