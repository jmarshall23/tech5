
// ========================================================================
// ?Parse@idDeclTwitchPain@@UAAXAAVidParser@@@Z
// EA  : 0x82BCB680
// RVA : 0x00BCB680
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.cpp
// ========================================================================

void __fastcall idDeclTwitchPain::Parse(idDeclTwitchPain *this, idParser *src)
{
  int v3; // r17
  int v4; // r18
  int v5; // r20
  idTwitchPain_WeaponGroup *v6; // r27
  int v7; // r24
  int v8; // r26
  _DWORD *v9; // r29
  int v10; // r28
  int v11; // r30
  int value; // r9
  int v13; // [sp+50h] [-B0h] BYREF
  idStr v14[5]; // [sp+60h] [-A0h] BYREF

  idDeclTypeInfo::Parse(this: &this->idDeclTypeInfo, src);
  v14[0].len = 0;
  v14[0].baseBuffer[0] = 0;
  v14[0].allocedAndFlag = 20;
  v14[0].data = v14[0].baseBuffer;
  v3 = 0;
  if ( this->weaponGroups.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = 0;
      v6 = &this->weaponGroups.list[v4];
      if ( v6->damageDirectionGroups.num > 0 )
      {
        v7 = 0;
        do
        {
          v8 = 0;
          v9 = &v6->damageDirectionGroups.list[v7].__vftable;
          if ( (int)v9[3] > 0 )
          {
            v10 = 0;
            do
            {
              v11 = v10 + v9[2];
              value = animation->RegisterAlias(this: &v13, result: animation, a3: 0, a4: *(_DWORD *)(v11 + 40))->value;
              *(_WORD *)(v11 + 68) = value;
              if ( value == 0xFFFF )
                idLib::Warning(
                  fmt: "idDeclTwitchPain '%s' specifies invalid alias '%s' for pain %s:%s:%s",
                  this->name.str,
                  *(const char **)(v11 + 40),
                  v6->weaponPrefix.data,
                  damageDirectionNames[v9[1]],
                  *(const char **)(v11 + 8));
              ++v8;
              v10 += 72;
            }
            while ( v8 < v9[3] );
          }
          ++v5;
          ++v7;
        }
        while ( v5 < v6->damageDirectionGroups.num );
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->weaponGroups.num );
  }
  idStr::FreeData(this: v14);
}


// ========================================================================
// __unwind$487584
// EA  : 0x82BCB7BC
// RVA : 0x00BCB7BC
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.cpp
// ========================================================================

void _unwind_487584()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// ?GetTwitchPainAliasHandle@idDeclTwitchPain@@QBA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBVidDeclMD6@@PBDW4damageDirection_t@@1@Z
// EA  : 0x82BCB7E8
// RVA : 0x00BCB7E8
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.cpp
// ========================================================================

idDeclTwitchPain *__fastcall idDeclTwitchPain::GetTwitchPainAliasHandle(
        idDeclTwitchPain *this,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result,
        const idDeclMD6 *forModelDef,
        const char *weaponPrefix,
        const damageDirection_t damageDir,
        const char *jointGroupName)
{
  int v11; // r20
  int v12; // r21
  int v13; // r27
  int v14; // r24
  int v15; // r26
  _DWORD *v16; // r31
  int v17; // r28
  int v18; // r30
  int v19; // r29

  v11 = 0;
  if ( *(int *)&result[34].value <= 0 )
  {
LABEL_13:
    HIWORD(this->__vftable) = -1;
    return this;
  }
  else
  {
    v12 = 0;
    while ( 1 )
    {
      v13 = v12 + *(_DWORD *)&result[32].value;
      if ( idStr::Icmp(s1: weaponPrefix, s2: *(const char **)(v13 + 8)) == 0 )
      {
        v14 = 0;
        if ( *(int *)(v13 + 40) > 0 )
          break;
      }
LABEL_12:
      ++v11;
      v12 += 52;
      if ( v11 >= *(_DWORD *)&result[34].value )
        goto LABEL_13;
    }
    v15 = 0;
    while ( 1 )
    {
      v16 = (_DWORD *)(*(_DWORD *)(v13 + 36) + v15);
      if ( v16[1] == damageDir )
      {
        v17 = 0;
        if ( (int)v16[3] > 0 )
          break;
      }
LABEL_11:
      ++v14;
      v15 += 24;
      if ( v14 >= *(_DWORD *)(v13 + 40) )
        goto LABEL_12;
    }
    v18 = 0;
    while ( 1 )
    {
      v19 = v16[2] + v18;
      if ( idStr::Icmp(s1: jointGroupName, s2: *(const char **)(v19 + 8)) == 0 )
        break;
      ++v17;
      v18 += 72;
      if ( v17 >= v16[3] )
        goto LABEL_11;
    }
    HIWORD(this->__vftable) = *(_WORD *)(v19 + 68);
    return this;
  }
}


// ========================================================================
// ?GetTwitchPainAliasHandle@idDeclTwitchPain@@QBA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBVidDeclMD6@@PBDW4damageDirection_t@@ABV?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82BCB8F8
// RVA : 0x00BCB8F8
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.cpp
// ========================================================================

idDeclTwitchPain *__fastcall idDeclTwitchPain::GetTwitchPainAliasHandle(
        idDeclTwitchPain *this,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result,
        const idDeclMD6 *forModelDef,
        const char *weaponPrefix,
        damageDirection_t damageDir,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex)
{
  idDeclTwitchPain *v6; // r31
  idJointGroupCollection *p_jointGroupCollection; // r29
  const idJointGroup *JointGroup; // r3
  idDeclMD6 *v14; // r3
  const char *str; // r30
  const char *JointName; // r3
  idHandle<int,enum invalidJointGroupHandle,0> v18[20]; // [sp+50h] [-50h] BYREF

  v6 = this;
  p_jointGroupCollection = &forModelDef->jointGroupCollection;
  if ( forModelDef == (const idDeclMD6 *)-144 )
  {
    HIWORD(this->__vftable) = -1;
  }
  else
  {
    idJointGroupCollection::GetJointGroupHandle(
      this: (idJointGroupCollection *)v18,
      result: p_jointGroupCollection,
      type: 2,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)jointIndex->value);
    JointGroup = idJointGroupCollection::GetJointGroup(this: p_jointGroupCollection, handle: v18);
    if ( JointGroup != nullptr )
    {
      idDeclTwitchPain::GetTwitchPainAliasHandle(
        this: v6,
        result,
        forModelDef,
        weaponPrefix,
        damageDir,
        jointGroupName: JointGroup->groupName.str);
    }
    else
    {
      v14 = forModelDef;
      str = forModelDef->name.str;
      JointName = idDeclMD6::GetJointName(
                    this: v14,
                    idx: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)jointIndex->value);
      idLib::Warning(fmt: "%s: missing twitch pain joint group for joint '%s'", str, JointName);
      HIWORD(v6->__vftable) = -1;
    }
    return v6;
  }
  return this;
}


// ========================================================================
// ??0idDeclTwitchPain@@QAA@XZ
// EA  : 0x82BCB9C8
// RVA : 0x00BCB9C8
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.cpp
// ========================================================================

idDeclTwitchPain *__fastcall idDeclTwitchPain::idDeclTwitchPain(idDeclTwitchPain *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclTwitchPain_vtbl *)&idDeclTwitchPain::`vftable';
  this->weaponGroups.granularity = 0;
  this->weaponGroups.memTag = 5;
  this->weaponGroups.listStatic = 0;
  this->weaponGroups.list = nullptr;
  this->weaponGroups.size = 0;
  this->weaponGroups.num = 0;
  return this;
}


// ========================================================================
// __unwind$487894
// EA  : 0x82BCBA38
// RVA : 0x00BCBA38
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.cpp
// ========================================================================

void _unwind_487894()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?StrongLoadAliasesForModelDef@idDeclTwitchPain@@QBAXPBVidDeclMD6@@@Z
// EA  : 0x82BCBB68
// RVA : 0x00BCBB68
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.cpp
// ========================================================================

void __fastcall idDeclTwitchPain::StrongLoadAliasesForModelDef(idDeclTwitchPain *this, const idDeclMD6 *decl)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int v6; // r20
  int v7; // r22
  int v8; // r25
  idTwitchPain_WeaponGroup *v9; // r27
  int v10; // r26
  int v11; // r28
  idTwitchPain_DamageDirectionGroup *v12; // r30
  int v13; // r29
  idTwitchPain_JointGroup *v14; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v16; // r30
  int v17; // r3
  __int64 totalTicks; // r11
  __int64 v19; // r9
  idPLogScope v20; // [sp+50h] [-80h] BYREF

  RD_EventBegin(name: "idDeclTwitchPain::StrongLoadAliasesForModelDef");
  LODWORD(v4) = "idDeclTwitchPain::StrongLoadAliasesForModelDef";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v20, pl: &::pLog, gMask: v4, label: v5);
  v6 = 0;
  if ( this->weaponGroups.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = 0;
      v9 = &this->weaponGroups.list[v7];
      if ( v9->damageDirectionGroups.num > 0 )
      {
        v10 = 0;
        do
        {
          v11 = 0;
          v12 = &v9->damageDirectionGroups.list[v10];
          if ( v12->jointGroups.num > 0 )
          {
            v13 = 0;
            do
            {
              v14 = &v12->jointGroups.list[v13];
              if ( v14->aliasName.len != 0 )
                animation->StrongLoadAlias_2(this: animation, a2: decl, a3: &v14->aliasHandle);
              ++v11;
              ++v13;
            }
            while ( v11 < v12->jointGroups.num );
          }
          ++v8;
          ++v10;
        }
        while ( v8 < v9->damageDirectionGroups.num );
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->weaponGroups.num );
  }
  if ( v20.logIndex >= 0 )
  {
    pLog = v20.pLog;
    v16 = &v20.pLog->logEntries.list[v20.logIndex];
    v17 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v16->totalTicks;
    HIDWORD(totalTicks) = v16->parent;
    LODWORD(v19) = v17 - totalTicks;
    v16->totalTicks = v19;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$487998
// EA  : 0x82BCBCA4
// RVA : 0x00BCBCA4
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.cpp
// ========================================================================

void _unwind_487998()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 88));
}


// ========================================================================
// __unwind$487999
// EA  : 0x82BCBCCC
// RVA : 0x00BCBCCC
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.cpp
// ========================================================================

void _unwind_487999()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 80));
}

