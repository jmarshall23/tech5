
// ========================================================================
// ?Init@idEncounterGroupManager@@QAAXXZ
// EA  : 0x82A91998
// RVA : 0x00A91998
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void __fastcall idEncounterGroupManager::Init(idEncounterGroupManager *this)
{
  this->nextThinkTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?Update@idEncounterGroupManager@@QAAXXZ
// EA  : 0x82A919E0
// RVA : 0x00A919E0
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void __fastcall idEncounterGroupManager::Update(idEncounterGroupManager *this)
{
  int v2; // r29
  int v3; // r30

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextThinkTime )
  {
    v2 = 0;
    if ( this->groups.num > 0 )
    {
      v3 = 0;
      do
      {
        idEncounterGroup::Think(this: &this->groups.list[v3]);
        ++v2;
        ++v3;
      }
      while ( v2 < this->groups.num );
    }
    this->nextThinkTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + 512;
  }
}


// ========================================================================
// ?GroupForHandle@idEncounterGroupManager@@QAAPAVidEncounterGroup@@ABV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@@Z
// EA  : 0x82A91A70
// RVA : 0x00A91A70
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

idEncounterGroup *__fastcall idEncounterGroupManager::GroupForHandle(
        idEncounterGroupManager *this,
        const idHandle<short,enum invalidEncounterGroup_t,-1> *handle)
{
  int lookupMask; // r7
  int value; // r9
  int v4; // r11
  idEncounterGroup *list; // r8

  lookupMask = this->hashIndex.lookupMask;
  value = handle->value;
  v4 = this->hashIndex.hash[this->hashIndex.hashMask & lookupMask & value];
  if ( v4 == -1 )
    return nullptr;
  while ( 1 )
  {
    list = this->groups.list;
    if ( list[v4].handle.value == value )
      break;
    v4 = this->hashIndex.indexChain[lookupMask & v4];
    if ( v4 == -1 )
      return nullptr;
  }
  return &list[v4];
}


// ========================================================================
// ?FindIndex@idEncounterGroupManager@@ABAHPBD@Z
// EA  : 0x82A91AE8
// RVA : 0x00A91AE8
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

int __fastcall idEncounterGroupManager::FindIndex(idEncounterGroupManager *this, const char *groupName)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->groups.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: this->groups.list[i].groupName.data, s2: groupName) != 0; ++i )
  {
    if ( ++v4 >= this->groups.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?FindIndex@idEncounterGroupManager@@ABAHABV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@@Z
// EA  : 0x82A91B58
// RVA : 0x00A91B58
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

int __fastcall idEncounterGroupManager::FindIndex(
        idEncounterGroupManager *this,
        const idHandle<short,enum invalidEncounterGroup_t,-1> *handle)
{
  int lookupMask; // r7
  int value; // r9
  int v4; // r11

  lookupMask = this->hashIndex.lookupMask;
  value = handle->value;
  v4 = this->hashIndex.hash[this->hashIndex.hashMask & lookupMask & value];
  if ( v4 == -1 )
    return -1;
  while ( this->groups.list[v4].handle.value != value )
  {
    v4 = this->hashIndex.indexChain[lookupMask & v4];
    if ( v4 == -1 )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?FindGroup@idEncounterGroupManager@@QAA?AV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@PBD@Z
// EA  : 0x82A91BD0
// RVA : 0x00A91BD0
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

idEncounterGroupManager *__fastcall idEncounterGroupManager::FindGroup(
        idEncounterGroupManager *this,
        idEncounterGroupManager *result,
        const char *groupName)
{
  int Index; // r3

  Index = idEncounterGroupManager::FindIndex(this: result, groupName);
  if ( Index >= 0 )
    HIWORD(this->__vftable) = result->groups.list[Index].handle.value;
  else
    HIWORD(this->__vftable) = NULL_ENCOUNTER_GROUP;
  return this;
}


// ========================================================================
// ?HandleForName@idEncounterGroupManager@@QBA?AV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@PBD@Z
// EA  : 0x82A91C40
// RVA : 0x00A91C40
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

idEncounterGroupManager *__fastcall idEncounterGroupManager::HandleForName(
        idEncounterGroupManager *this,
        idEncounterGroupManager *result,
        const char *groupName)
{
  int Index; // r3

  Index = idEncounterGroupManager::FindIndex(this: result, groupName);
  if ( Index >= 0 )
    HIWORD(this->__vftable) = result->groups.list[Index].handle.value;
  else
    HIWORD(this->__vftable) = -1;
  return this;
}


// ========================================================================
// ?SendGroupMessage@idEncounterGroupManager@@QAA_NABV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@W4aiGroupMessage_t@@PAVidEntity@@@Z
// EA  : 0x82A91CB0
// RVA : 0x00A91CB0
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

int __fastcall idEncounterGroupManager::SendGroupMessage(
        idEncounterGroupManager *this,
        const idHandle<short,enum invalidEncounterGroup_t,-1> *handle,
        aiGroupMessage_t msg,
        idEntity *ent)
{
  int Index; // r3

  Index = idEncounterGroupManager::FindIndex(this, handle);
  if ( Index < 0 )
    return 0;
  idEncounterGroup::OnGroupMessage(this: &this->groups.list[Index], msg, ent);
  return 1;
}


// ========================================================================
// ?Shutdown@idEncounterGroupManager@@QAAXXZ
// EA  : 0x82A91D70
// RVA : 0x00A91D70
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void __fastcall idEncounterGroupManager::Shutdown(idEncounterGroupManager *this)
{
  idEncounterGroup *list; // r3

  if ( this->groups.listStatic == 0 || this->groups.listStatic == 2 )
  {
    list = this->groups.list;
    if ( list != nullptr )
      idListArrayDelete<idEncounterGroup>(ptr: list, num: this->groups.size);
    this->groups.list = nullptr;
    this->groups.size = 0;
  }
  this->groups.num = 0;
  idHashIndex::Clear(this: &this->hashIndex);
}


// ========================================================================
// ?GetActiveHintNodeCoverIndices@idEncounterGroupManager@@QBAXAAV?$idList@H$04@@@Z
// EA  : 0x82A91DE8
// RVA : 0x00A91DE8
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void __fastcall idEncounterGroupManager::GetActiveHintNodeCoverIndices(
        idEncounterGroupManager *this,
        idList<idVehicleState *,5> *coverIndices)
{
  idList<idEncounterGroup,5> *p_groups; // r25
  int v5; // r23
  int v6; // r26
  int v7; // r27
  int v8; // r29
  int num; // r9
  int v10; // r10
  const encounterGroupRole_t *v11; // r4
  int v12; // r11
  idList<int,5> v13[7]; // [sp+50h] [-70h] BYREF

  p_groups = &this->groups;
  idList<idThread *,58>::Clear(this: coverIndices);
  v5 = 0;
  if ( this->groups.num > 0 )
  {
    v6 = 0;
    do
    {
      if ( idEncounterGroup::NumLivingMembers(this: &p_groups->list[v6]) > 0 )
      {
        *(_WORD *)&v13[0].memTag = 1280;
        memset(v13, 0, 14);
        idEncounterGroup::GetCurrentCombatStageCoverIndices(this: &p_groups->list[v6], coverIndices: v13);
        v7 = 0;
        if ( v13[0].num > 0 )
        {
          v8 = 0;
          do
          {
            num = coverIndices->num;
            v10 = 0;
            v11 = (const encounterGroupRole_t *)&v13[0].list[v8];
            if ( num <= 0 )
              goto LABEL_12;
            v12 = 0;
            while ( coverIndices->list[v12] != (idVehicleState *)*v11 )
            {
              ++v10;
              ++v12;
              if ( v10 >= num )
                goto LABEL_12;
            }
            if ( v10 < 0 )
LABEL_12:
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)coverIndices,
                obj: v11);
            ++v7;
            ++v8;
          }
          while ( v7 < v13[0].num );
        }
        if ( v13[0].listStatic == 0 || v13[0].listStatic == 2 )
        {
          if ( v13[0].list != nullptr )
            idMem::Free(this: &mem, ptr: v13[0].list, align: ALIGN_16);
          v13[0].list = nullptr;
          v13[0].size = 0;
        }
        v13[0].num = 0;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < p_groups->num );
  }
}


// ========================================================================
// __unwind$490154
// EA  : 0x82A91F3C
// RVA : 0x00A91F3C
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void _unwind_490154()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 80));
}


// ========================================================================
// ??0idEncounterGroupManager@@QAA@XZ
// EA  : 0x82A91F70
// RVA : 0x00A91F70
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

idEncounterGroupManager *__fastcall idEncounterGroupManager::idEncounterGroupManager(idEncounterGroupManager *this)
{
  this->__vftable = (idEncounterGroupManager_vtbl *)&idEncounterGroupManager::`vftable';
  this->groups.granularity = 0;
  this->groups.memTag = 5;
  this->groups.listStatic = 0;
  this->groups.list = nullptr;
  this->groups.size = 0;
  this->groups.num = 0;
  this->nextThinkTime = 0;
  this->hashIndex.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->hashIndex, initialHashSize: 128, initialIndexSize: 128);
  this->curHandle = 0;
  return this;
}


// ========================================================================
// __unwind$490657
// EA  : 0x82A91FE8
// RVA : 0x00A91FE8
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void _unwind_490657()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490658
// EA  : 0x82A92010
// RVA : 0x00A92010
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void _unwind_490658()
{
  int v0; // r12

  idList<idEncounterGroup,5>::Clear(this: (idList<idEncounterGroup,5> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// ??1idEncounterGroupManager@@UAA@XZ
// EA  : 0x82A92048
// RVA : 0x00A92048
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void __fastcall idEncounterGroupManager::~idEncounterGroupManager(idEncounterGroupManager *this)
{
  idEncounterGroup *list; // r3
  idEncounterGroup *v3; // r3

  this->__vftable = (idEncounterGroupManager_vtbl *)&idEncounterGroupManager::`vftable';
  if ( this->groups.listStatic == 0 || this->groups.listStatic == 2 )
  {
    list = this->groups.list;
    if ( list != nullptr )
      idListArrayDelete<idEncounterGroup>(ptr: list, num: this->groups.size);
    this->groups.list = nullptr;
    this->groups.size = 0;
  }
  this->groups.num = 0;
  idHashIndex::Free(this: &this->hashIndex);
  if ( this->groups.listStatic == 0 || this->groups.listStatic == 2 )
  {
    v3 = this->groups.list;
    if ( v3 != nullptr )
      idListArrayDelete<idEncounterGroup>(ptr: v3, num: this->groups.size);
    this->groups.list = nullptr;
    this->groups.size = 0;
  }
  this->groups.num = 0;
  this->__vftable = (idEncounterGroupManager_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$490702
// EA  : 0x82A920F4
// RVA : 0x00A920F4
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void _unwind_490702()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490703
// EA  : 0x82A9211C
// RVA : 0x00A9211C
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void _unwind_490703()
{
  int v0; // r12

  idList<idEncounterGroup,5>::Clear(this: (idList<idEncounterGroup,5> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$490704
// EA  : 0x82A92148
// RVA : 0x00A92148
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

void _unwind_490704()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// ?AddGroup@idEncounterGroupManager@@QAA?AV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@ABVidEncounterGroup@@@Z
// EA  : 0x82A924E0
// RVA : 0x00A924E0
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

idEncounterGroupManager *__fastcall idEncounterGroupManager::AddGroup(
        idEncounterGroupManager *this,
        idEncounterGroupManager *result,
        const idEncounterGroup *otherGroup)
{
  int v6; // r3
  __int16 curHandle; // r9
  idEncounterGroup *list; // r11
  idEncounterGroup *v9; // r3
  int v10; // r7

  if ( idEncounterGroupManager::FindIndex(this: result, groupName: otherGroup->groupName.data) >= 0 )
    idLib::Warning(
      fmt: "Encounter group '%s' is defined more than once. Check for mutliple ai/groupmanager entities with the same group.",
      otherGroup->groupName.data);
  v6 = idList<idEncounterGroup,5>::Append(this: &result->groups, obj: otherGroup);
  curHandle = result->curHandle;
  list = result->groups.list;
  HIWORD(this->__vftable) = curHandle;
  v9 = &list[v6];
  v10 = (__int16)(curHandle + 1);
  result->curHandle = v10;
  if ( v10 == -1 )
    result->curHandle = 0;
  idEncounterGroup::Init(
    this: v9,
    groupName_: otherGroup->groupName.data,
    handle_: (const idHandle<short,enum invalidEncounterGroup_t,-1> *)HIWORD(this->__vftable));
  idHashIndex::InsertIndex(
    this: &result->hashIndex,
    key: result->hashIndex.hashMask & SHIWORD(this->__vftable),
    index: result->groups.num - 1);
  return this;
}


// ========================================================================
// ?AddGroup@idEncounterGroupManager@@QAA?AV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@PBD@Z
// EA  : 0x82A92608
// RVA : 0x00A92608
// PDB : w:\tech5\tungsten\game\ai\encountergroupmanager.cpp
// ========================================================================

idEncounterGroupManager *__fastcall idEncounterGroupManager::AddGroup(
        idEncounterGroupManager *this,
        idEncounterGroupManager *result,
        const char *groupName)
{
  int Index; // r3
  int v7; // r11
  idEncounterGroup *v9; // r3
  const idHandle<short,enum invalidEncounterGroup_t,-1> *curHandle; // r29

  Index = idEncounterGroupManager::FindIndex(this: result, groupName);
  if ( Index < 0 )
  {
    v9 = idList<idEncounterGroup,5>::Alloc(this: &result->groups);
    curHandle = (const idHandle<short,enum invalidEncounterGroup_t,-1> *)(unsigned __int16)result->curHandle;
    result->curHandle = (_WORD)curHandle + 1;
    if ( (__int16)((_WORD)curHandle + 1) == -1 )
      result->curHandle = 0;
    idEncounterGroup::Init(this: v9, groupName_: groupName, handle_: curHandle);
    idHashIndex::InsertIndex(
      this: &result->hashIndex,
      key: result->hashIndex.hashMask & (__int16)curHandle,
      index: result->groups.num - 1);
    HIWORD(this->__vftable) = (_WORD)curHandle;
    return this;
  }
  else
  {
    v7 = (int)&result->groups.list[Index];
    HIWORD(this->__vftable) = *(_WORD *)(v7 + 220);
    return this;
  }
}

