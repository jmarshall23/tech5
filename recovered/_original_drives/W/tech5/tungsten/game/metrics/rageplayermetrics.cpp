
// ========================================================================
// ?ResetSpecialKill@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE1020
// RVA : 0x00DE1020
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::ResetSpecialKill(idRagePlayerMetrics *this)
{
  this->allowSpecialKill = true;
}


// ========================================================================
// ?GetTotalAccuracyHits@idLevelStats@@QBAHXZ
// EA  : 0x82DE1200
// RVA : 0x00DE1200
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

int __fastcall idLevelStats::GetTotalAccuracyHits(idLevelStats *this)
{
  int num; // r31
  int v2; // r8
  int v3; // r7
  int v4; // r11
  weaponStats_t *list; // r5
  int v6; // r10
  int accHits; // r6
  int v8; // r9

  num = this->weaponStats.num;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  if ( num >= 2 )
  {
    list = this->weaponStats.list;
    v6 = 0;
    do
    {
      v4 += 2;
      accHits = list[v6].accHits;
      v8 = list[v6 + 1].accHits;
      v6 += 2;
      v2 += accHits;
      v3 += v8;
    }
    while ( v4 < num - 1 );
  }
  if ( v4 >= num )
    return v3 + v2;
  else
    return v3 + v2 + this->weaponStats.list[v4].accHits;
}


// ========================================================================
// ?GetTotalFired@idLevelStats@@QBAHXZ
// EA  : 0x82DE1298
// RVA : 0x00DE1298
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

int __fastcall idLevelStats::GetTotalFired(idLevelStats *this)
{
  int num; // r31
  int v2; // r8
  int v3; // r7
  int v4; // r11
  weaponStats_t *list; // r5
  int v6; // r10
  int fired; // r6
  int v8; // r9

  num = this->weaponStats.num;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  if ( num >= 2 )
  {
    list = this->weaponStats.list;
    v6 = 0;
    do
    {
      v4 += 2;
      fired = list[v6].fired;
      v8 = list[v6 + 1].fired;
      v6 += 2;
      v2 += fired;
      v3 += v8;
    }
    while ( v4 < num - 1 );
  }
  if ( v4 >= num )
    return v3 + v2;
  else
    return v3 + v2 + this->weaponStats.list[v4].fired;
}


// ========================================================================
// ?ResetStats@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE1330
// RVA : 0x00DE1330
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::ResetStats(idRagePlayerMetrics *this)
{
  int v1; // r10
  int v2; // r11
  idRageStat *v3; // r9

  v1 = 0;
  if ( this->stats.num > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = &this->stats.list[v2++];
      v3->sessionValue.i = 0;
      v3->aggregatedValue.i = 0;
    }
    while ( v1 < this->stats.num );
  }
  this->shotId = 0;
  this->timeBucket = 0;
}


// ========================================================================
// ?BeginGame@idRagePlayerMetrics@@AAAXABVidGameChallenge@@@Z
// EA  : 0x82DE1378
// RVA : 0x00DE1378
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::BeginGame(idRagePlayerMetrics *this, const idGameChallenge *challenge)
{
  int v2; // r3

  idRagePlayerMetrics::ResetStats(this);
  *(_BYTE *)(v2 + 3133) = 0;
}


// ========================================================================
// ?StatAddInt@idRagePlayerMetrics@@AAAXW4rageStat_t@@H@Z
// EA  : 0x82DE13A8
// RVA : 0x00DE13A8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::StatAddInt(idRagePlayerMetrics *this, rageStat_t stat, int value)
{
  rageStat_t v4; // r30
  idRageStat::statValue_t v5[2]; // [sp+50h] [-20h] BYREF

  v4 = stat;
  idRageStat::Add(this: &this->stats.list[stat], owner: this, value);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v5, this: &this->stats.list[v4], owner: this);
}


// ========================================================================
// ?StatAddFloat@idRagePlayerMetrics@@AAAXW4rageStat_t@@M@Z
// EA  : 0x82DE1418
// RVA : 0x00DE1418
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::StatAddFloat(idRagePlayerMetrics *this, const rageStat_t stat, double value)
{
  idRageStat::Add(this: &this->stats.list[stat], owner: this, (int)value);
}


// ========================================================================
// ?VehicleKill@idRagePlayerMetrics@@AAAXPBV1@PBVidDeclDamage@@@Z
// EA  : 0x82DE1460
// RVA : 0x00DE1460
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::VehicleKill(
        idRagePlayerMetrics *this,
        const idRagePlayerMetrics *victim,
        const idDeclDamage *damageDef)
{
  int v6; // r3
  int entityNumber; // r10
  int v8; // r8
  int v9; // r10 OVERLAPPED
  __int128 v10; // r9 OVERLAPPED
  __int64 v11; // [sp+8h] [-148h]
  __int64 v12; // [sp+10h] [-140h]
  __int64 v13; // [sp+18h] [-138h]
  __int64 v14; // [sp+20h] [-130h]
  __int64 v15; // [sp+28h] [-128h]
  __int64 v16; // [sp+30h] [-120h]
  __int64 v17; // [sp+38h] [-118h]
  __int64 v18; // [sp+40h] [-110h]
  __int64 v19; // [sp+48h] [-108h]
  __int64 v20; // [sp+50h] [-100h]
  int v21; // [sp+58h] [-F8h]
  int v22; // [sp+5Ch] [-F4h]
  int v23[8]; // [sp+60h] [-F0h] BYREF
  int v24[8]; // [sp+80h] [-D0h] BYREF
  idRageStat::statValue_t v25[4]; // [sp+A0h] [-B0h] BYREF
  _DWORD v26[5]; // [sp+B0h] [-A0h] BYREF
  _DWORD v27[5]; // [sp+D0h] [-80h] BYREF
  char v28; // [sp+F0h] [-60h]
  int v29; // [sp+F4h] [-5Ch]
  __int64 v30; // [sp+F8h] [-58h]
  int v31; // [sp+100h] [-50h]
  const idEventDef *v32; // [sp+110h] [-40h]
  int v33; // [sp+114h] [-3Ch]
  __int64 v34; // [sp+118h] [-38h]
  int v35; // [sp+120h] [-30h]

  v6 = idRageStat::Increment(this: this->stats.list, owner: this);
  if ( victim != nullptr )
  {
    v26[1] = v6;
    entityNumber = victim->entityNumber;
    HIBYTE(v26[0]) = 105;
    v8 = this->entityNumber;
    v27[1] = damageDef;
    HIBYTE(v27[0]) = 100;
    v29 = entityNumber;
    v28 = 105;
    v33 = v8;
    HIBYTE(v32) = 105;
    memcpy(Dst: v24, Src: v26, Size: 0x14u);
    memcpy(Dst: v23, Src: v27, Size: 0x14u);
    v9 = __ROL4__(v31, 32);
    *((_QWORD *)&v10 + 1) = v30;
    DWORD1(v10) = __ROL4__(v35, 32);
    idEventReceiver::BroadcastEvent(
      this: this->eventListener,
      ev: v32,
      arg2: v34,
      arg4: *(__int64 *)((char *)&v10 + 4),
      a5: *(__int64 *)&v9,
      a6: v11,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16,
      a12: v17,
      a13: v18,
      a14: v19,
      a15: v20,
      a16: v21,
      a17: v22,
      a18: v23[0],
      a19: v23[1],
      a20: v23[2],
      a21: v23[3],
      arg3: v23[4],
      arg3_4: v23[5],
      arg3_8: v23[6],
      arg3_12: v23[7],
      arg3_16: v24[0]);
  }
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v25, this: this->stats.list, owner: this);
}


// ========================================================================
// ?AIKill@idRagePlayerMetrics@@AAAXHPBVidDeclDamage@@@Z
// EA  : 0x82DE1540
// RVA : 0x00DE1540
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::AIKill(
        idRagePlayerMetrics *this,
        int victimEntityNum,
        const idDeclDamage *damageDef)
{
  int v6; // r3
  int entityNumber; // r10
  int v8; // r10 OVERLAPPED
  __int128 v9; // r9 OVERLAPPED
  __int64 v10; // [sp+8h] [-148h]
  __int64 v11; // [sp+10h] [-140h]
  __int64 v12; // [sp+18h] [-138h]
  __int64 v13; // [sp+20h] [-130h]
  __int64 v14; // [sp+28h] [-128h]
  __int64 v15; // [sp+30h] [-120h]
  __int64 v16; // [sp+38h] [-118h]
  __int64 v17; // [sp+40h] [-110h]
  __int64 v18; // [sp+48h] [-108h]
  __int64 v19; // [sp+50h] [-100h]
  int v20; // [sp+58h] [-F8h]
  int v21; // [sp+5Ch] [-F4h]
  int v22[8]; // [sp+60h] [-F0h] BYREF
  int v23[8]; // [sp+80h] [-D0h] BYREF
  idRageStat::statValue_t v24[4]; // [sp+A0h] [-B0h] BYREF
  _DWORD v25[5]; // [sp+B0h] [-A0h] BYREF
  _DWORD v26[5]; // [sp+D0h] [-80h] BYREF
  int v27; // [sp+F0h] [-60h]
  int v28; // [sp+F4h] [-5Ch]
  __int64 v29; // [sp+F8h] [-58h]
  int v30; // [sp+100h] [-50h]
  const idEventDef *v31; // [sp+110h] [-40h]
  int v32; // [sp+114h] [-3Ch]
  __int64 v33; // [sp+118h] [-38h]

  v6 = idRageStat::Increment(this: this->stats.list + 157, owner: this);
  if ( victimEntityNum != 0x1FFF )
  {
    v25[1] = v6;
    entityNumber = this->entityNumber;
    HIBYTE(v25[0]) = 105;
    v26[1] = damageDef;
    v28 = victimEntityNum;
    HIBYTE(v26[0]) = 100;
    HIBYTE(v27) = 105;
    v32 = entityNumber;
    HIBYTE(v31) = 105;
    memcpy(Dst: v23, Src: v25, Size: 0x14u);
    memcpy(Dst: v22, Src: v26, Size: 0x14u);
    v8 = __ROL4__(v30, 32);
    *((_QWORD *)&v9 + 1) = v29;
    DWORD1(v9) = __ROL4__(v27, 32);
    idEventReceiver::BroadcastEvent(
      this: this->eventListener,
      ev: v31,
      arg2: v33,
      arg4: *(__int64 *)((char *)&v9 + 4),
      a5: *(__int64 *)&v8,
      a6: v10,
      a7: v11,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15,
      a12: v16,
      a13: v17,
      a14: v18,
      a15: v19,
      a16: v20,
      a17: v21,
      a18: v22[0],
      a19: v22[1],
      a20: v22[2],
      a21: v22[3],
      arg3: v22[4],
      arg3_4: v22[5],
      arg3_8: v22[6],
      arg3_12: v22[7],
      arg3_16: v23[0]);
  }
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v24, this: this->stats.list + 157, owner: this);
}


// ========================================================================
// ?PlayerKill@idRagePlayerMetrics@@AAAXPBV1@PBVidDeclDamage@@@Z
// EA  : 0x82DE1620
// RVA : 0x00DE1620
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::PlayerKill(
        idRagePlayerMetrics *this,
        const idRagePlayerMetrics *victim,
        const idDeclDamage *damageDef)
{
  int v6; // r3
  int entityNumber; // r10
  int v8; // r8
  int v9; // r10 OVERLAPPED
  __int128 v10; // r9 OVERLAPPED
  __int64 v11; // [sp+8h] [-148h]
  __int64 v12; // [sp+10h] [-140h]
  __int64 v13; // [sp+18h] [-138h]
  __int64 v14; // [sp+20h] [-130h]
  __int64 v15; // [sp+28h] [-128h]
  __int64 v16; // [sp+30h] [-120h]
  __int64 v17; // [sp+38h] [-118h]
  __int64 v18; // [sp+40h] [-110h]
  __int64 v19; // [sp+48h] [-108h]
  __int64 v20; // [sp+50h] [-100h]
  int v21; // [sp+58h] [-F8h]
  int v22; // [sp+5Ch] [-F4h]
  int v23[8]; // [sp+60h] [-F0h] BYREF
  int v24[8]; // [sp+80h] [-D0h] BYREF
  idRageStat::statValue_t v25[4]; // [sp+A0h] [-B0h] BYREF
  _DWORD v26[5]; // [sp+B0h] [-A0h] BYREF
  _DWORD v27[5]; // [sp+D0h] [-80h] BYREF
  char v28; // [sp+F0h] [-60h]
  int v29; // [sp+F4h] [-5Ch]
  __int64 v30; // [sp+F8h] [-58h]
  int v31; // [sp+100h] [-50h]
  const idEventDef *v32; // [sp+110h] [-40h]
  int v33; // [sp+114h] [-3Ch]
  __int64 v34; // [sp+118h] [-38h]
  int v35; // [sp+120h] [-30h]

  v6 = idRageStat::Increment(this: this->stats.list + 158, owner: this);
  if ( victim != nullptr )
  {
    v26[1] = v6;
    entityNumber = victim->entityNumber;
    HIBYTE(v26[0]) = 105;
    v8 = this->entityNumber;
    v27[1] = damageDef;
    HIBYTE(v27[0]) = 100;
    v29 = entityNumber;
    v28 = 105;
    v33 = v8;
    HIBYTE(v32) = 105;
    memcpy(Dst: v24, Src: v26, Size: 0x14u);
    memcpy(Dst: v23, Src: v27, Size: 0x14u);
    v9 = __ROL4__(v31, 32);
    *((_QWORD *)&v10 + 1) = v30;
    DWORD1(v10) = __ROL4__(v35, 32);
    idEventReceiver::BroadcastEvent(
      this: this->eventListener,
      ev: v32,
      arg2: v34,
      arg4: *(__int64 *)((char *)&v10 + 4),
      a5: *(__int64 *)&v9,
      a6: v11,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16,
      a12: v17,
      a13: v18,
      a14: v19,
      a15: v20,
      a16: v21,
      a17: v22,
      a18: v23[0],
      a19: v23[1],
      a20: v23[2],
      a21: v23[3],
      arg3: v23[4],
      arg3_4: v23[5],
      arg3_8: v23[6],
      arg3_12: v23[7],
      arg3_16: v24[0]);
  }
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v25, this: this->stats.list + 158, owner: this);
}


// ========================================================================
// ?AIAssist@idRagePlayerMetrics@@AAAXHH@Z
// EA  : 0x82DE1708
// RVA : 0x00DE1708
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::AIAssist(idRagePlayerMetrics *this, int victimEntityNum, int killerEntityNum)
{
  int v6; // r3
  int entityNumber; // r10
  int v8; // r10 OVERLAPPED
  __int128 v9; // r9 OVERLAPPED
  __int64 v10; // [sp+8h] [-158h]
  __int64 v11; // [sp+10h] [-150h]
  __int64 v12; // [sp+18h] [-148h]
  __int64 v13; // [sp+20h] [-140h]
  __int64 v14; // [sp+28h] [-138h]
  __int64 v15; // [sp+30h] [-130h]
  __int64 v16; // [sp+38h] [-128h]
  __int64 v17; // [sp+40h] [-120h]
  __int64 v18; // [sp+48h] [-118h]
  __int64 v19; // [sp+50h] [-110h]
  int v20; // [sp+58h] [-108h]
  int v21; // [sp+5Ch] [-104h]
  int v22[8]; // [sp+60h] [-100h] BYREF
  int v23[8]; // [sp+80h] [-E0h] BYREF
  idRageStat::statValue_t v24[4]; // [sp+A0h] [-C0h] BYREF
  _DWORD v25[5]; // [sp+B0h] [-B0h] BYREF
  _DWORD v26[5]; // [sp+D0h] [-90h] BYREF
  int v27; // [sp+F0h] [-70h]
  int v28; // [sp+F4h] [-6Ch]
  __int64 v29; // [sp+F8h] [-68h]
  int v30; // [sp+100h] [-60h]
  const idEventDef *v31; // [sp+110h] [-50h]
  int v32; // [sp+114h] [-4Ch]
  __int64 v33; // [sp+118h] [-48h]

  v6 = idRageStat::Increment(this: this->stats.list + 143, owner: this);
  if ( victimEntityNum != 0x1FFF )
  {
    v25[1] = v6;
    entityNumber = this->entityNumber;
    HIBYTE(v25[0]) = 105;
    v26[1] = victimEntityNum;
    HIBYTE(v26[0]) = 105;
    HIBYTE(v27) = 105;
    v32 = entityNumber;
    v28 = killerEntityNum;
    HIBYTE(v31) = 105;
    memcpy(Dst: v23, Src: v25, Size: 0x14u);
    memcpy(Dst: v22, Src: v26, Size: 0x14u);
    v8 = __ROL4__(v30, 32);
    *((_QWORD *)&v9 + 1) = v29;
    DWORD1(v9) = __ROL4__(v27, 32);
    idEventReceiver::BroadcastEvent(
      this: this->eventListener,
      ev: v31,
      arg2: v33,
      arg4: *(__int64 *)((char *)&v9 + 4),
      a5: *(__int64 *)&v8,
      a6: v10,
      a7: v11,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15,
      a12: v16,
      a13: v17,
      a14: v18,
      a15: v19,
      a16: v20,
      a17: v21,
      a18: v22[0],
      a19: v22[1],
      a20: v22[2],
      a21: v22[3],
      arg3: v22[4],
      arg3_4: v22[5],
      arg3_8: v22[6],
      arg3_12: v22[7],
      arg3_16: v23[0]);
  }
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v24, this: this->stats.list + 143, owner: this);
}


// ========================================================================
// ?LeaderKill@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE17E8
// RVA : 0x00DE17E8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::LeaderKill(idRagePlayerMetrics *this)
{
  idRageStat *v3; // r3
  int v4; // r3
  int entityNumber; // r11
  __int128 v6; // r9 OVERLAPPED
  int v7; // r10
  __int64 v8; // [sp+8h] [-C8h]
  __int64 v9; // [sp+10h] [-C0h]
  __int64 v10; // [sp+18h] [-B8h]
  __int64 v11; // [sp+20h] [-B0h]
  __int64 v12; // [sp+28h] [-A8h]
  __int64 v13; // [sp+30h] [-A0h]
  __int64 v14; // [sp+38h] [-98h]
  __int64 v15; // [sp+40h] [-90h]
  __int64 v16; // [sp+48h] [-88h]
  __int64 v17; // [sp+50h] [-80h]
  idRageStat::statValue_t v18[4]; // [sp+60h] [-70h] BYREF
  char v19; // [sp+70h] [-60h]
  int v20; // [sp+74h] [-5Ch]
  __int64 v21; // [sp+78h] [-58h]
  int v22; // [sp+80h] [-50h]
  const idEventDef *v23; // [sp+90h] [-40h]
  int v24; // [sp+94h] [-3Ch]
  __int64 v25; // [sp+98h] [-38h]
  int v26; // [sp+A0h] [-30h]

  v3 = this->stats.list + 38;
  v19 = 105;
  v4 = idRageStat::Increment(this: v3, owner: this);
  entityNumber = this->entityNumber;
  HIBYTE(v23) = 105;
  v20 = v4;
  *((_QWORD *)&v6 + 1) = v21;
  v24 = entityNumber;
  v7 = __ROL4__(v22, 32);
  DWORD1(v6) = __ROL4__(v26, 32);
  idEventReceiver::BroadcastEvent(
    this: this->eventListener,
    ev: v23,
    arg2: v25,
    a4: *(__int64 *)((char *)&v6 + 4),
    a5: *(__int64 *)((char *)&v6 - 4),
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: v17);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v18, this: this->stats.list + 38, owner: this);
}


// ========================================================================
// ?VehicleSuicide@idRagePlayerMetrics@@AAAXPBVidDeclDamage@@@Z
// EA  : 0x82DE1880
// RVA : 0x00DE1880
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::VehicleSuicide(idRagePlayerMetrics *this, const idDeclDamage *damageDef)
{
  idEventReceiver *eventListener; // r3
  __int128 v5; // r9 OVERLAPPED
  int v6; // r10
  __int64 v7; // [sp+8h] [-B8h]
  __int64 v8; // [sp+10h] [-B0h]
  __int64 v9; // [sp+18h] [-A8h]
  __int64 v10; // [sp+20h] [-A0h]
  __int64 v11; // [sp+28h] [-98h]
  __int64 v12; // [sp+30h] [-90h]
  __int64 v13; // [sp+38h] [-88h]
  __int64 v14; // [sp+40h] [-80h]
  __int64 v15; // [sp+48h] [-78h]
  __int64 v16; // [sp+50h] [-70h]
  idRageStat::statValue_t v17[4]; // [sp+60h] [-60h] BYREF
  int v18; // [sp+70h] [-50h]
  const idDeclDamage *v19; // [sp+74h] [-4Ch]
  __int64 v20; // [sp+78h] [-48h]
  int v21; // [sp+80h] [-40h]
  char v22; // [sp+90h] [-30h]
  int entityNumber; // [sp+94h] [-2Ch]

  idRageStat::Increment(this: this->stats.list + 2, owner: this);
  v19 = damageDef;
  eventListener = this->eventListener;
  HIBYTE(v18) = 100;
  *((_QWORD *)&v5 + 1) = v20;
  v6 = __ROL4__(v21, 32);
  entityNumber = this->entityNumber;
  v22 = 105;
  DWORD1(v5) = __ROL4__(*(_DWORD *)(v18 + 16), 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: *(const idEventDef **)v18,
    arg2: *(_QWORD *)(v18 + 8),
    a4: *(__int64 *)((char *)&v5 + 4),
    a5: *(__int64 *)((char *)&v5 - 4),
    a6: v7,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14,
    a14: v15,
    a15: v16);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v17, this: this->stats.list + 2, owner: this);
}


// ========================================================================
// ?TeamKill@idRagePlayerMetrics@@AAAXPBV1@PBVidDeclDamage@@@Z
// EA  : 0x82DE1938
// RVA : 0x00DE1938
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::TeamKill(
        idRagePlayerMetrics *this,
        const idRagePlayerMetrics *victim,
        const idDeclDamage *damageDef)
{
  int entityNumber; // r9
  int v7; // r8
  int v8; // r10 OVERLAPPED
  __int128 v9; // r9 OVERLAPPED
  __int64 v10; // [sp+8h] [-108h]
  __int64 v11; // [sp+10h] [-100h]
  __int64 v12; // [sp+18h] [-F8h]
  __int64 v13; // [sp+20h] [-F0h]
  __int64 v14; // [sp+28h] [-E8h]
  __int64 v15; // [sp+30h] [-E0h]
  __int64 v16; // [sp+38h] [-D8h]
  __int64 v17; // [sp+40h] [-D0h]
  __int64 v18; // [sp+48h] [-C8h]
  __int64 v19; // [sp+50h] [-C0h]
  int v20; // [sp+58h] [-B8h]
  int v21; // [sp+5Ch] [-B4h]
  int v22[8]; // [sp+60h] [-B0h] BYREF
  idRageStat::statValue_t v23[4]; // [sp+80h] [-90h] BYREF
  _DWORD v24[5]; // [sp+90h] [-80h] BYREF
  char v25; // [sp+B0h] [-60h]
  int v26; // [sp+B4h] [-5Ch]
  __int64 v27; // [sp+B8h] [-58h]
  int v28; // [sp+C0h] [-50h]
  const idEventDef *v29; // [sp+D0h] [-40h]
  int v30; // [sp+D4h] [-3Ch]
  __int64 v31; // [sp+D8h] [-38h]
  int v32; // [sp+E0h] [-30h]

  if ( victim != nullptr )
  {
    idRageStat::Increment(this: this->stats.list + 30, owner: this);
    v24[1] = damageDef;
    HIBYTE(v24[0]) = 100;
    entityNumber = victim->entityNumber;
    v7 = this->entityNumber;
    v25 = 105;
    HIBYTE(v29) = 105;
    v26 = entityNumber;
    v30 = v7;
    memcpy(Dst: v22, Src: v24, Size: 0x14u);
    v8 = __ROL4__(v28, 32);
    *((_QWORD *)&v9 + 1) = v27;
    DWORD1(v9) = __ROL4__(v32, 32);
    idEventReceiver::BroadcastEvent(
      this: this->eventListener,
      ev: v29,
      arg2: v31,
      arg3: *(__int64 *)((char *)&v9 + 4),
      a5: *(__int64 *)&v8,
      a6: v10,
      a7: v11,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15,
      a12: v16,
      a13: v17,
      a14: v18,
      a15: v19,
      a16: v20,
      a17: v21,
      a18: v22[0]);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v23, this: this->stats.list + 30, owner: this);
  }
  else
  {
    idLib::Warning(fmt: "[%s] must have victim for team kill", "idRagePlayerMetrics::TeamKill");
  }
}


// ========================================================================
// ?DoubleKill@idRagePlayerMetrics@@QAAXXZ
// EA  : 0x82DE1A20
// RVA : 0x00DE1A20
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::DoubleKill(idRagePlayerMetrics *this)
{
  idRageStat *v3; // r3
  int v4; // r3
  int entityNumber; // r11
  __int128 v6; // r9 OVERLAPPED
  int v7; // r10
  __int64 v8; // [sp+8h] [-C8h]
  __int64 v9; // [sp+10h] [-C0h]
  __int64 v10; // [sp+18h] [-B8h]
  __int64 v11; // [sp+20h] [-B0h]
  __int64 v12; // [sp+28h] [-A8h]
  __int64 v13; // [sp+30h] [-A0h]
  __int64 v14; // [sp+38h] [-98h]
  __int64 v15; // [sp+40h] [-90h]
  __int64 v16; // [sp+48h] [-88h]
  __int64 v17; // [sp+50h] [-80h]
  idRageStat::statValue_t v18[4]; // [sp+60h] [-70h] BYREF
  char v19; // [sp+70h] [-60h]
  int v20; // [sp+74h] [-5Ch]
  __int64 v21; // [sp+78h] [-58h]
  int v22; // [sp+80h] [-50h]
  const idEventDef *v23; // [sp+90h] [-40h]
  int v24; // [sp+94h] [-3Ch]
  __int64 v25; // [sp+98h] [-38h]
  int v26; // [sp+A0h] [-30h]

  v3 = this->stats.list + 3;
  v19 = 105;
  v4 = idRageStat::Increment(this: v3, owner: this);
  entityNumber = this->entityNumber;
  HIBYTE(v23) = 105;
  v20 = v4;
  *((_QWORD *)&v6 + 1) = v21;
  v24 = entityNumber;
  v7 = __ROL4__(v22, 32);
  DWORD1(v6) = __ROL4__(v26, 32);
  idEventReceiver::BroadcastEvent(
    this: this->eventListener,
    ev: v23,
    arg2: v25,
    a4: *(__int64 *)((char *)&v6 + 4),
    a5: *(__int64 *)((char *)&v6 - 4),
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: v17);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v18, this: this->stats.list + 3, owner: this);
  if ( this->allowSpecialKill )
  {
    idRageStat::Increment(this: this->stats.list + 216, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v18, this: this->stats.list + 216, owner: this);
    this->allowSpecialKill = false;
  }
}


// ========================================================================
// ?TripleKill@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE1B00
// RVA : 0x00DE1B00
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::TripleKill(idRagePlayerMetrics *this)
{
  idRageStat *v3; // r3
  int v4; // r3
  int entityNumber; // r11
  __int128 v6; // r9 OVERLAPPED
  int v7; // r10
  __int64 v8; // [sp+8h] [-C8h]
  __int64 v9; // [sp+10h] [-C0h]
  __int64 v10; // [sp+18h] [-B8h]
  __int64 v11; // [sp+20h] [-B0h]
  __int64 v12; // [sp+28h] [-A8h]
  __int64 v13; // [sp+30h] [-A0h]
  __int64 v14; // [sp+38h] [-98h]
  __int64 v15; // [sp+40h] [-90h]
  __int64 v16; // [sp+48h] [-88h]
  __int64 v17; // [sp+50h] [-80h]
  idRageStat::statValue_t v18[4]; // [sp+60h] [-70h] BYREF
  char v19; // [sp+70h] [-60h]
  int v20; // [sp+74h] [-5Ch]
  __int64 v21; // [sp+78h] [-58h]
  int v22; // [sp+80h] [-50h]
  const idEventDef *v23; // [sp+90h] [-40h]
  int v24; // [sp+94h] [-3Ch]
  __int64 v25; // [sp+98h] [-38h]
  int v26; // [sp+A0h] [-30h]

  v3 = this->stats.list + 4;
  v19 = 105;
  v4 = idRageStat::Increment(this: v3, owner: this);
  entityNumber = this->entityNumber;
  HIBYTE(v23) = 105;
  v20 = v4;
  *((_QWORD *)&v6 + 1) = v21;
  v24 = entityNumber;
  v7 = __ROL4__(v22, 32);
  DWORD1(v6) = __ROL4__(v26, 32);
  idEventReceiver::BroadcastEvent(
    this: this->eventListener,
    ev: v23,
    arg2: v25,
    a4: *(__int64 *)((char *)&v6 + 4),
    a5: *(__int64 *)((char *)&v6 - 4),
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: v17);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v18, this: this->stats.list + 4, owner: this);
  if ( this->allowSpecialKill )
  {
    idRageStat::Increment(this: this->stats.list + 216, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v18, this: this->stats.list + 216, owner: this);
    this->allowSpecialKill = false;
  }
}


// ========================================================================
// ?QuadKill@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE1BE0
// RVA : 0x00DE1BE0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::QuadKill(idRagePlayerMetrics *this)
{
  idRageStat *v3; // r3
  int v4; // r3
  int entityNumber; // r11
  __int128 v6; // r9 OVERLAPPED
  int v7; // r10
  __int64 v8; // [sp+8h] [-C8h]
  __int64 v9; // [sp+10h] [-C0h]
  __int64 v10; // [sp+18h] [-B8h]
  __int64 v11; // [sp+20h] [-B0h]
  __int64 v12; // [sp+28h] [-A8h]
  __int64 v13; // [sp+30h] [-A0h]
  __int64 v14; // [sp+38h] [-98h]
  __int64 v15; // [sp+40h] [-90h]
  __int64 v16; // [sp+48h] [-88h]
  __int64 v17; // [sp+50h] [-80h]
  idRageStat::statValue_t v18[4]; // [sp+60h] [-70h] BYREF
  char v19; // [sp+70h] [-60h]
  int v20; // [sp+74h] [-5Ch]
  __int64 v21; // [sp+78h] [-58h]
  int v22; // [sp+80h] [-50h]
  const idEventDef *v23; // [sp+90h] [-40h]
  int v24; // [sp+94h] [-3Ch]
  __int64 v25; // [sp+98h] [-38h]
  int v26; // [sp+A0h] [-30h]

  v3 = this->stats.list + 5;
  v19 = 105;
  v4 = idRageStat::Increment(this: v3, owner: this);
  entityNumber = this->entityNumber;
  HIBYTE(v23) = 105;
  v20 = v4;
  *((_QWORD *)&v6 + 1) = v21;
  v24 = entityNumber;
  v7 = __ROL4__(v22, 32);
  DWORD1(v6) = __ROL4__(v26, 32);
  idEventReceiver::BroadcastEvent(
    this: this->eventListener,
    ev: v23,
    arg2: v25,
    a4: *(__int64 *)((char *)&v6 + 4),
    a5: *(__int64 *)((char *)&v6 - 4),
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: v17);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v18, this: this->stats.list + 5, owner: this);
  if ( this->allowSpecialKill )
  {
    idRageStat::Increment(this: this->stats.list + 216, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v18, this: this->stats.list + 216, owner: this);
    this->allowSpecialKill = false;
  }
}


// ========================================================================
// ?KillingSpree@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE1CC0
// RVA : 0x00DE1CC0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::KillingSpree(idRagePlayerMetrics *this)
{
  idRageStat *v3; // r3
  int v4; // r3
  int entityNumber; // r11
  __int128 v6; // r9 OVERLAPPED
  int v7; // r10
  __int64 v8; // [sp+8h] [-C8h]
  __int64 v9; // [sp+10h] [-C0h]
  __int64 v10; // [sp+18h] [-B8h]
  __int64 v11; // [sp+20h] [-B0h]
  __int64 v12; // [sp+28h] [-A8h]
  __int64 v13; // [sp+30h] [-A0h]
  __int64 v14; // [sp+38h] [-98h]
  __int64 v15; // [sp+40h] [-90h]
  __int64 v16; // [sp+48h] [-88h]
  __int64 v17; // [sp+50h] [-80h]
  idRageStat::statValue_t v18[4]; // [sp+60h] [-70h] BYREF
  char v19; // [sp+70h] [-60h]
  int v20; // [sp+74h] [-5Ch]
  __int64 v21; // [sp+78h] [-58h]
  int v22; // [sp+80h] [-50h]
  const idEventDef *v23; // [sp+90h] [-40h]
  int v24; // [sp+94h] [-3Ch]
  __int64 v25; // [sp+98h] [-38h]
  int v26; // [sp+A0h] [-30h]

  v3 = this->stats.list + 6;
  v19 = 105;
  v4 = idRageStat::Increment(this: v3, owner: this);
  entityNumber = this->entityNumber;
  HIBYTE(v23) = 105;
  v20 = v4;
  *((_QWORD *)&v6 + 1) = v21;
  v24 = entityNumber;
  v7 = __ROL4__(v22, 32);
  DWORD1(v6) = __ROL4__(v26, 32);
  idEventReceiver::BroadcastEvent(
    this: this->eventListener,
    ev: v23,
    arg2: v25,
    a4: *(__int64 *)((char *)&v6 + 4),
    a5: *(__int64 *)((char *)&v6 - 4),
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: v17);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v18, this: this->stats.list + 6, owner: this);
  if ( this->allowSpecialKill )
  {
    idRageStat::Increment(this: this->stats.list + 216, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v18, this: this->stats.list + 216, owner: this);
    this->allowSpecialKill = false;
  }
}


// ========================================================================
// ?UpdateKillStreak@idRagePlayerMetrics@@AAAXHH@Z
// EA  : 0x82DE1DA0
// RVA : 0x00DE1DA0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::UpdateKillStreak(
        idRagePlayerMetrics *this,
        int currentTime,
        int killStreakTimeLimit)
{
  int v5; // r11
  unsigned int currentKillStreak; // r10
  idRageStat *list; // r10
  int v8; // r11
  int i; // r9

  if ( currentTime >= killStreakTimeLimit + this->lastKillTimestamp )
  {
    this->currentKillStreak = 1;
  }
  else
  {
    v5 = this->currentKillStreak + 1;
    currentKillStreak = this->currentKillStreak;
    this->currentKillStreak = v5;
    if ( currentKillStreak > 3 )
    {
      if ( v5 >= 5 )
        idRagePlayerMetrics::KillingSpree(this);
    }
    else if ( currentKillStreak != 0 )
    {
      if ( currentKillStreak == 1 )
      {
        idRagePlayerMetrics::DoubleKill(this);
      }
      else if ( currentKillStreak == 2 )
      {
        idRagePlayerMetrics::TripleKill(this);
      }
      else
      {
        idRagePlayerMetrics::QuadKill(this);
      }
    }
  }
  list = this->stats.list;
  v8 = this->killsThisLife + 1;
  this->lastKillTimestamp = currentTime;
  this->killsThisLife = v8;
  i = list[104].sessionValue.i;
  if ( i <= v8 )
    list[104].sessionValue.i = v8;
  else
    list[104].sessionValue.i = i;
}


// ========================================================================
// ?Travel@idRagePlayerMetrics@@AAAXMHH@Z
// EA  : 0x82DE1E80
// RVA : 0x00DE1E80
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::Travel(
        idRagePlayerMetrics *this,
        double distance,
        int timeMs,
        int wheelsOnGround,
        int a5)
{
  idRageStat *list; // r11
  idRageStat *v10; // r4
  idRageStat::statValue_t v11[2]; // [sp+50h] [-30h] BYREF

  idRageStat::Add(this: (idTungstenHealth *)&this->stats.list[12], h: distance);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v11, this: this->stats.list + 12, owner: this);
  list = this->stats.list;
  if ( a5 != 0 )
  {
    idRageStat::Add(this: (idTungstenHealth *)&list[13], h: distance);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v11, this: this->stats.list + 13, owner: this);
    if ( a5 == 2 )
    {
      idRageStat::Add(this: (idTungstenHealth *)&this->stats.list[14], h: distance);
      if ( this->isAchievementReady )
      {
        v10 = this->stats.list + 14;
LABEL_13:
        idRageStat::Aggregate(retstr: v11, this: v10, owner: this);
      }
    }
  }
  else
  {
    idRageStat::Add(this: (idTungstenHealth *)&list[15], h: distance);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v11, this: this->stats.list + 15, owner: this);
    idRageStat::Add(this: this->stats.list + 16, owner: this, value: wheelsOnGround);
    if ( this->isAchievementReady )
    {
      v10 = this->stats.list + 16;
      goto LABEL_13;
    }
  }
}


// ========================================================================
// ?Score_VDM@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE1FA0
// RVA : 0x00DE1FA0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::Score_VDM(idRagePlayerMetrics *this, int score)
{
  idRageStat::statValue_t v3[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Add(this: this->stats.list + 35, owner: this, value: score);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v3, this: this->stats.list + 35, owner: this);
}


// ========================================================================
// ?Score_COOP@idRagePlayerMetrics@@AAAXHH@Z
// EA  : 0x82DE2000
// RVA : 0x00DE2000
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::Score_COOP(idRagePlayerMetrics *this, int teamScore, int individualScore)
{
  idRageStat::statValue_t v4[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Add(this: this->stats.list + 34, owner: this, value: individualScore);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v4, this: this->stats.list + 34, owner: this);
}


// ========================================================================
// ?SetTime@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE2058
// RVA : 0x00DE2058
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::SetTime(idRagePlayerMetrics *this, idRageStat::statValue_t time)
{
  this->stats.list[36].sessionValue = time;
}


// ========================================================================
// ?ItemsTaken@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE2068
// RVA : 0x00DE2068
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::ItemsTaken(idRagePlayerMetrics *this, int items)
{
  idRageStat::statValue_t v4[2]; // [sp+50h] [-20h] BYREF

  idRageStat::Add(this: this->stats.list + 160, owner: this, value: items);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v4, this: this->stats.list + 160, owner: this);
  if ( gameLocal->enableStatTracking )
    this->levelStats.itemsTaken += items;
}


// ========================================================================
// ?ClientDamage@idRagePlayerMetrics@@AAAXHPBVidDeclDamage@@@Z
// EA  : 0x82DE20F8
// RVA : 0x00DE20F8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::ClientDamage(idRagePlayerMetrics *this, int damage, const idDeclDamage *damageDef)
{
  int entityNumber; // r9
  int v7; // r10 OVERLAPPED
  __int128 v8; // r9 OVERLAPPED
  __int64 v9; // [sp+8h] [-108h]
  __int64 v10; // [sp+10h] [-100h]
  __int64 v11; // [sp+18h] [-F8h]
  __int64 v12; // [sp+20h] [-F0h]
  __int64 v13; // [sp+28h] [-E8h]
  __int64 v14; // [sp+30h] [-E0h]
  __int64 v15; // [sp+38h] [-D8h]
  __int64 v16; // [sp+40h] [-D0h]
  __int64 v17; // [sp+48h] [-C8h]
  __int64 v18; // [sp+50h] [-C0h]
  int v19; // [sp+58h] [-B8h]
  int v20; // [sp+5Ch] [-B4h]
  int v21[8]; // [sp+60h] [-B0h] BYREF
  idRageStat::statValue_t v22[4]; // [sp+80h] [-90h] BYREF
  _DWORD v23[5]; // [sp+90h] [-80h] BYREF
  int v24; // [sp+B0h] [-60h]
  int v25; // [sp+B4h] [-5Ch]
  __int64 v26; // [sp+B8h] [-58h]
  int v27; // [sp+C0h] [-50h]
  const idEventDef *v28; // [sp+D0h] [-40h]
  int v29; // [sp+D4h] [-3Ch]
  __int64 v30; // [sp+D8h] [-38h]

  idRageStat::Add(this: this->stats.list + 161, owner: this, value: damage);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v22, this: this->stats.list + 161, owner: this);
  if ( gameLocal->enableStatTracking )
    this->levelStats.damageTaken += damage;
  v23[1] = damageDef;
  entityNumber = this->entityNumber;
  HIBYTE(v23[0]) = 100;
  v25 = damage;
  HIBYTE(v24) = 105;
  HIBYTE(v28) = 105;
  v29 = entityNumber;
  memcpy(Dst: v21, Src: v23, Size: 0x14u);
  v7 = __ROL4__(v27, 32);
  *((_QWORD *)&v8 + 1) = v26;
  DWORD1(v8) = __ROL4__(v24, 32);
  idEventReceiver::BroadcastEvent(
    this: this->eventListener,
    ev: v28,
    arg2: v30,
    arg3: *(__int64 *)((char *)&v8 + 4),
    a5: *(__int64 *)&v7,
    a6: v9,
    a7: v10,
    a8: v11,
    a9: v12,
    a10: v13,
    a11: v14,
    a12: v15,
    a13: v16,
    a14: v17,
    a15: v18,
    a16: v19,
    a17: v20,
    a18: v21[0]);
}


// ========================================================================
// ?Revived@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE21E0
// RVA : 0x00DE21E0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::Revived(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 206, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 206, owner: this);
}


// ========================================================================
// ?RevivedPartner@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE2238
// RVA : 0x00DE2238
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::RevivedPartner(idRagePlayerMetrics *this, int revivedPlayerEntityNumber)
{
  int entityNumber; // r10
  idEventReceiver *eventListener; // r3
  __int128 v6; // r9 OVERLAPPED
  int v7; // r10
  __int64 v8; // [sp+8h] [-B8h]
  __int64 v9; // [sp+10h] [-B0h]
  __int64 v10; // [sp+18h] [-A8h]
  __int64 v11; // [sp+20h] [-A0h]
  __int64 v12; // [sp+28h] [-98h]
  __int64 v13; // [sp+30h] [-90h]
  __int64 v14; // [sp+38h] [-88h]
  __int64 v15; // [sp+40h] [-80h]
  __int64 v16; // [sp+48h] [-78h]
  __int64 v17; // [sp+50h] [-70h]
  idRageStat::statValue_t v18[4]; // [sp+60h] [-60h] BYREF
  char v19; // [sp+70h] [-50h]
  int v20; // [sp+74h] [-4Ch]
  int v21; // [sp+90h] [-30h]
  int v22; // [sp+94h] [-2Ch]
  __int64 v23; // [sp+98h] [-28h]
  int v24; // [sp+A0h] [-20h]

  idRageStat::Increment(this: this->stats.list + 207, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v18, this: this->stats.list + 207, owner: this);
  entityNumber = this->entityNumber;
  v20 = revivedPlayerEntityNumber;
  eventListener = this->eventListener;
  v19 = 105;
  HIBYTE(v21) = 105;
  v22 = entityNumber;
  *((_QWORD *)&v6 + 1) = v23;
  DWORD1(v6) = __ROL4__(*(_DWORD *)(v21 + 16), 32);
  v7 = __ROL4__(v24, 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: *(const idEventDef **)v21,
    arg2: *(_QWORD *)(v21 + 8),
    a4: *(__int64 *)((char *)&v6 + 4),
    a5: *(__int64 *)((char *)&v6 - 4),
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: v17);
}


// ========================================================================
// ?Incapacitated@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE22F0
// RVA : 0x00DE22F0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::Incapacitated(idRagePlayerMetrics *this)
{
  __int64 v2; // r10
  idEventReceiver *eventListener; // r3
  __int64 v4; // r8
  __int64 v5; // [sp+8h] [-88h]
  __int64 v6; // [sp+10h] [-80h]
  __int64 v7; // [sp+18h] [-78h]
  __int64 v8; // [sp+20h] [-70h]
  __int64 v9; // [sp+28h] [-68h]
  __int64 v10; // [sp+30h] [-60h]
  idRageStat::statValue_t v11[4]; // [sp+50h] [-40h] BYREF
  const idEventDef *v12[2]; // [sp+60h] [-30h] BYREF
  __int64 v13; // [sp+68h] [-28h]
  int v14; // [sp+70h] [-20h]

  idRageStat::Increment(this: this->stats.list + 212, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v11, this: this->stats.list + 212, owner: this);
  LODWORD(v2) = v12;
  HIDWORD(v2) = 105;
  eventListener = this->eventListener;
  LODWORD(v4) = &s_memTag[218];
  v12[1] = (const idEventDef *)this->entityNumber;
  HIBYTE(v12[0]) = 105;
  HIDWORD(v4) = __ROL4__(v14, 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: v12[0],
    arg1: v13,
    a4: v4,
    a5: v2,
    a6: v5,
    a7: v6,
    a8: v7,
    a9: v8,
    a10: v9,
    a11: v10);
}


// ========================================================================
// ?TurretKill@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE2380
// RVA : 0x00DE2380
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::TurretKill(idRagePlayerMetrics *this, idRageStat::statValue_t totalKillsPerItem)
{
  idRageStat *list; // r11
  idLocalUser *LocalUserFromPlayerIndex; // r3
  idRageStat::statValue_t v6[2]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 245, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v6, this: this->stats.list + 245, owner: this);
  idRageStat::Increment(this: this->stats.list + 241, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v6, this: this->stats.list + 241, owner: this);
  list = this->stats.list;
  if ( totalKillsPerItem.i > list[246].sessionValue.i )
  {
    list[246].sessionValue = totalKillsPerItem;
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v6, this: this->stats.list + 246, owner: this);
    LocalUserFromPlayerIndex = idClientGame::GetLocalUserFromPlayerIndex(this: clientGame, index: this->entityNumber);
    if ( LocalUserFromPlayerIndex != nullptr
      && totalKillsPerItem.i > LocalUserFromPlayerIndex->GetStatInt(this: LocalUserFromPlayerIndex, a2: 246) )
    {
      this->stats.list[246].sessionValue = totalKillsPerItem;
      if ( this->isAchievementReady )
        idRageStat::Aggregate(retstr: v6, this: this->stats.list + 246, owner: this);
    }
  }
}


// ========================================================================
// ?SentryBotKill@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE24A8
// RVA : 0x00DE24A8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::SentryBotKill(
        idRagePlayerMetrics *this,
        idRageStat::statValue_t totalKillsPerItem)
{
  idLocalUser *LocalUserFromPlayerIndex; // r30
  idRageStat *list; // r11
  idRageStat::statValue_t v6[12]; // [sp+50h] [-30h] BYREF

  idRageStat::Increment(this: this->stats.list + 243, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v6, this: this->stats.list + 243, owner: this);
  idRageStat::Increment(this: this->stats.list + 241, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v6, this: this->stats.list + 241, owner: this);
  LocalUserFromPlayerIndex = idClientGame::GetLocalUserFromPlayerIndex(this: clientGame, index: this->entityNumber);
  if ( LocalUserFromPlayerIndex != nullptr )
  {
    list = this->stats.list;
    if ( totalKillsPerItem.i > list[244].sessionValue.i )
    {
      list[244].sessionValue = totalKillsPerItem;
      if ( this->isAchievementReady )
        idRageStat::Aggregate(retstr: v6, this: this->stats.list + 244, owner: this);
      if ( totalKillsPerItem.i > LocalUserFromPlayerIndex->GetStatInt(this: LocalUserFromPlayerIndex, a2: 244) )
      {
        this->stats.list[244].sessionValue = totalKillsPerItem;
        if ( this->isAchievementReady )
          idRageStat::Aggregate(retstr: v6, this: this->stats.list + 244, owner: this);
      }
    }
  }
}


// ========================================================================
// ?Award@idRagePlayerMetrics@@AAAXW4rageStat_t@@@Z
// EA  : 0x82DE25C0
// RVA : 0x00DE25C0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::Award(idRagePlayerMetrics *this, rageStat_t award)
{
  rageStat_t v3; // r30
  idRageStat::statValue_t v4[2]; // [sp+50h] [-20h] BYREF

  v3 = award;
  idRageStat::Increment(this: &this->stats.list[award], owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v4, this: &this->stats.list[v3], owner: this);
}


// ========================================================================
// ?BanditKill@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE2630
// RVA : 0x00DE2630
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::BanditKill(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 147, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 147, owner: this);
}


// ========================================================================
// ?VehicleKillByClass1@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE2688
// RVA : 0x00DE2688
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::VehicleKillByClass1(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 150, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 150, owner: this);
}


// ========================================================================
// ?VehicleKillByClass2@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE26E0
// RVA : 0x00DE26E0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::VehicleKillByClass2(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 151, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 151, owner: this);
}


// ========================================================================
// ?VehicleKillByClass3@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE2738
// RVA : 0x00DE2738
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::VehicleKillByClass3(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 152, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 152, owner: this);
}


// ========================================================================
// ?VehicleKillByClass4@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE2790
// RVA : 0x00DE2790
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::VehicleKillByClass4(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 153, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 153, owner: this);
}


// ========================================================================
// ?HeadShot@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE27E8
// RVA : 0x00DE27E8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::HeadShot(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 145, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 145, owner: this);
}


// ========================================================================
// ?UpdateTime@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE2840
// RVA : 0x00DE2840
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::UpdateTime(idRagePlayerMetrics *this, int ms)
{
  int v3; // r11
  idRageStat::statValue_t v4[4]; // [sp+50h] [-20h] BYREF

  v3 = ms + this->timeBucket;
  this->timeBucket = v3;
  if ( v3 > achievements_timeUpdateInterval.valueInteger )
  {
    this->timeBucket = v3 - achievements_timeUpdateInterval.valueInteger;
    idRageStat::Add(
      this: this->stats.list + 156,
      owner: this,
      value: achievements_timeUpdateInterval.valueInteger / 1000);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v4, this: this->stats.list + 156, owner: this);
  }
}


// ========================================================================
// ?LostRallyChain@idRagePlayerMetrics@@QAAXXZ
// EA  : 0x82DE28D0
// RVA : 0x00DE28D0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::LostRallyChain(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2; // r30
  idRageStat::statValue_t v3; // r11

  if ( this->maxChainTimestamp == 0x80000000 )
  {
    this->currentRallyStreak = 0;
  }
  else
  {
    v2.i = (int)this->stats.list[108].sessionValue;
    v3.i = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->maxChainTimestamp;
    if ( v2.i > v3.i )
      v3.i = v2.i;
    this->stats.list[108].sessionValue = v3;
    this->maxChainTimestamp = 0x80000000;
    this->currentRallyStreak = 0;
  }
}


// ========================================================================
// ?CoopChallengeWithoutDeath@idRagePlayerMetrics@@AAAX_N@Z
// EA  : 0x82DE2958
// RVA : 0x00DE2958
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::CoopChallengeWithoutDeath(idRagePlayerMetrics *this, bool nightmare)
{
  idRageStat::statValue_t v4[2]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 208, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v4, this: this->stats.list + 208, owner: this);
  if ( nightmare )
  {
    idRageStat::Increment(this: this->stats.list + 209, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v4, this: this->stats.list + 209, owner: this);
  }
}


// ========================================================================
// ?CoopChallengeWithoutDefib@idRagePlayerMetrics@@AAAX_N@Z
// EA  : 0x82DE29F8
// RVA : 0x00DE29F8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::CoopChallengeWithoutDefib(idRagePlayerMetrics *this, bool nightmare)
{
  idRageStat::statValue_t v4[2]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 210, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v4, this: this->stats.list + 210, owner: this);
  if ( nightmare )
  {
    idRageStat::Increment(this: this->stats.list + 211, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v4, this: this->stats.list + 211, owner: this);
  }
}


// ========================================================================
// ?CoopChallengeHighestScoreRank@idRagePlayerMetrics@@AAAX_N@Z
// EA  : 0x82DE2A98
// RVA : 0x00DE2A98
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::CoopChallengeHighestScoreRank(idRagePlayerMetrics *this, bool nightmare)
{
  idRageStat::statValue_t v4[2]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 225, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v4, this: this->stats.list + 225, owner: this);
  if ( nightmare )
  {
    idRageStat::Increment(this: this->stats.list + 226, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v4, this: this->stats.list + 226, owner: this);
  }
}


// ========================================================================
// ?SkillJump@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE2B38
// RVA : 0x00DE2B38
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::SkillJump(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 234, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 234, owner: this);
}


// ========================================================================
// ?CompleteGame@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE2B90
// RVA : 0x00DE2B90
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::CompleteGame(idRagePlayerMetrics *this, const int difficulty)
{
  int v3; // r30
  idRageStat::statValue_t v4[2]; // [sp+50h] [-20h] BYREF

  v3 = difficulty + 236;
  idRageStat::Increment(this: &this->stats.list[v3], owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v4, this: &this->stats.list[v3], owner: this);
  idRageStat::Increment(this: this->stats.list + 235, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v4, this: this->stats.list + 235, owner: this);
}


// ========================================================================
// ?EngineeredItem@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE2C30
// RVA : 0x00DE2C30
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::EngineeredItem(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 240, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 240, owner: this);
}


// ========================================================================
// ?StealthCrossbowKill@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE2C88
// RVA : 0x00DE2C88
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::StealthCrossbowKill(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 242, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 242, owner: this);
}


// ========================================================================
// ?StealthKill@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE2CE0
// RVA : 0x00DE2CE0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::StealthKill(idRagePlayerMetrics *this, int victimEntityNumber)
{
  int entityNumber; // r10
  idEventReceiver *eventListener; // r3
  __int128 v6; // r9 OVERLAPPED
  int v7; // r10
  __int64 v8; // [sp+8h] [-B8h]
  __int64 v9; // [sp+10h] [-B0h]
  __int64 v10; // [sp+18h] [-A8h]
  __int64 v11; // [sp+20h] [-A0h]
  __int64 v12; // [sp+28h] [-98h]
  __int64 v13; // [sp+30h] [-90h]
  __int64 v14; // [sp+38h] [-88h]
  __int64 v15; // [sp+40h] [-80h]
  __int64 v16; // [sp+48h] [-78h]
  __int64 v17; // [sp+50h] [-70h]
  idRageStat::statValue_t v18[4]; // [sp+60h] [-60h] BYREF
  char v19; // [sp+70h] [-50h]
  int v20; // [sp+74h] [-4Ch]
  __int64 v21; // [sp+78h] [-48h]
  int v22; // [sp+80h] [-40h]
  const idEventDef *v23; // [sp+90h] [-30h]
  int v24; // [sp+94h] [-2Ch]
  __int64 v25; // [sp+98h] [-28h]
  int v26; // [sp+A0h] [-20h]

  idRageStat::Increment(this: this->stats.list + 213, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v18, this: this->stats.list + 213, owner: this);
  entityNumber = this->entityNumber;
  v20 = victimEntityNumber;
  eventListener = this->eventListener;
  v19 = 105;
  HIBYTE(v23) = 105;
  v24 = entityNumber;
  *((_QWORD *)&v6 + 1) = v21;
  v7 = __ROL4__(v22, 32);
  DWORD1(v6) = __ROL4__(v26, 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: v23,
    arg2: v25,
    a4: *(__int64 *)((char *)&v6 + 4),
    a5: *(__int64 *)((char *)&v6 - 4),
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: v17);
}


// ========================================================================
// ?ComboKill@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE2D98
// RVA : 0x00DE2D98
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::ComboKill(idRagePlayerMetrics *this, int victimEntityNumber)
{
  int entityNumber; // r10
  idEventReceiver *eventListener; // r3
  __int128 v6; // r9 OVERLAPPED
  int v7; // r10
  __int64 v8; // [sp+8h] [-B8h]
  __int64 v9; // [sp+10h] [-B0h]
  __int64 v10; // [sp+18h] [-A8h]
  __int64 v11; // [sp+20h] [-A0h]
  __int64 v12; // [sp+28h] [-98h]
  __int64 v13; // [sp+30h] [-90h]
  __int64 v14; // [sp+38h] [-88h]
  __int64 v15; // [sp+40h] [-80h]
  __int64 v16; // [sp+48h] [-78h]
  __int64 v17; // [sp+50h] [-70h]
  idRageStat::statValue_t v18[4]; // [sp+60h] [-60h] BYREF
  char v19; // [sp+70h] [-50h]
  int v20; // [sp+74h] [-4Ch]
  __int64 v21; // [sp+78h] [-48h]
  int v22; // [sp+80h] [-40h]
  const idEventDef *v23; // [sp+90h] [-30h]
  int v24; // [sp+94h] [-2Ch]
  __int64 v25; // [sp+98h] [-28h]
  int v26; // [sp+A0h] [-20h]

  idRageStat::Increment(this: this->stats.list + 214, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v18, this: this->stats.list + 214, owner: this);
  entityNumber = this->entityNumber;
  v20 = victimEntityNumber;
  eventListener = this->eventListener;
  v19 = 105;
  HIBYTE(v23) = 105;
  v24 = entityNumber;
  *((_QWORD *)&v6 + 1) = v21;
  v7 = __ROL4__(v22, 32);
  DWORD1(v6) = __ROL4__(v26, 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: v23,
    arg2: v25,
    a4: *(__int64 *)((char *)&v6 + 4),
    a5: *(__int64 *)((char *)&v6 - 4),
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: v17);
}


// ========================================================================
// ?DefendKill@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE2E50
// RVA : 0x00DE2E50
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::DefendKill(idRagePlayerMetrics *this, int victimEntityNumber)
{
  int entityNumber; // r10
  idEventReceiver *eventListener; // r3
  __int128 v6; // r9 OVERLAPPED
  int v7; // r10
  __int64 v8; // [sp+8h] [-B8h]
  __int64 v9; // [sp+10h] [-B0h]
  __int64 v10; // [sp+18h] [-A8h]
  __int64 v11; // [sp+20h] [-A0h]
  __int64 v12; // [sp+28h] [-98h]
  __int64 v13; // [sp+30h] [-90h]
  __int64 v14; // [sp+38h] [-88h]
  __int64 v15; // [sp+40h] [-80h]
  __int64 v16; // [sp+48h] [-78h]
  __int64 v17; // [sp+50h] [-70h]
  idRageStat::statValue_t v18[4]; // [sp+60h] [-60h] BYREF
  char v19; // [sp+70h] [-50h]
  int v20; // [sp+74h] [-4Ch]
  __int64 v21; // [sp+78h] [-48h]
  int v22; // [sp+80h] [-40h]
  const idEventDef *v23; // [sp+90h] [-30h]
  int v24; // [sp+94h] [-2Ch]
  __int64 v25; // [sp+98h] [-28h]
  int v26; // [sp+A0h] [-20h]

  idRageStat::Increment(this: this->stats.list + 215, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v18, this: this->stats.list + 215, owner: this);
  entityNumber = this->entityNumber;
  v20 = victimEntityNumber;
  eventListener = this->eventListener;
  v19 = 105;
  HIBYTE(v23) = 105;
  v24 = entityNumber;
  *((_QWORD *)&v6 + 1) = v21;
  v7 = __ROL4__(v22, 32);
  DWORD1(v6) = __ROL4__(v26, 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: v23,
    arg2: v25,
    a4: *(__int64 *)((char *)&v6 + 4),
    a5: *(__int64 *)((char *)&v6 - 4),
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: v17);
}


// ========================================================================
// ?Suicide@idRagePlayerMetrics@@AAAXPBVidDeclDamage@@@Z
// EA  : 0x82DE2F08
// RVA : 0x00DE2F08
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::Suicide(idRagePlayerMetrics *this, const idDeclDamage *damageDef)
{
  idEventReceiver *eventListener; // r3
  __int128 v5; // r9 OVERLAPPED
  int v6; // r10
  __int64 v7; // [sp+8h] [-B8h]
  __int64 v8; // [sp+10h] [-B0h]
  __int64 v9; // [sp+18h] [-A8h]
  __int64 v10; // [sp+20h] [-A0h]
  __int64 v11; // [sp+28h] [-98h]
  __int64 v12; // [sp+30h] [-90h]
  __int64 v13; // [sp+38h] [-88h]
  __int64 v14; // [sp+40h] [-80h]
  __int64 v15; // [sp+48h] [-78h]
  __int64 v16; // [sp+50h] [-70h]
  idRageStat::statValue_t v17[4]; // [sp+60h] [-60h] BYREF
  int v18; // [sp+70h] [-50h]
  const idDeclDamage *v19; // [sp+74h] [-4Ch]
  __int64 v20; // [sp+78h] [-48h]
  int v21; // [sp+80h] [-40h]
  char v22; // [sp+90h] [-30h]
  int entityNumber; // [sp+94h] [-2Ch]

  idRageStat::Increment(this: this->stats.list + 250, owner: this);
  v19 = damageDef;
  eventListener = this->eventListener;
  HIBYTE(v18) = 100;
  *((_QWORD *)&v5 + 1) = v20;
  v6 = __ROL4__(v21, 32);
  entityNumber = this->entityNumber;
  v22 = 105;
  DWORD1(v5) = __ROL4__(*(_DWORD *)(v18 + 16), 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: *(const idEventDef **)v18,
    arg2: *(_QWORD *)(v18 + 8),
    a4: *(__int64 *)((char *)&v5 + 4),
    a5: *(__int64 *)((char *)&v5 - 4),
    a6: v7,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14,
    a14: v15,
    a15: v16);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v17, this: this->stats.list + 250, owner: this);
}


// ========================================================================
// ?ShotAuthorityJetpackerInAir@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE2FC0
// RVA : 0x00DE2FC0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::ShotAuthorityJetpackerInAir(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 253, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 253, owner: this);
}


// ========================================================================
// ?AddBoostUpSP@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE3018
// RVA : 0x00DE3018
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AddBoostUpSP(idRagePlayerMetrics *this, int time)
{
  idRageStat::statValue_t v3[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Add(this: this->stats.list + 18, owner: this, value: time);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v3, this: this->stats.list + 18, owner: this);
}


// ========================================================================
// ?AddJumpUpSP@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE3078
// RVA : 0x00DE3078
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AddJumpUpSP(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 19, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 19, owner: this);
}


// ========================================================================
// ?AddDuraBumpSP@idRagePlayerMetrics@@AAAXM@Z
// EA  : 0x82DE30D0
// RVA : 0x00DE30D0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AddDuraBumpSP(idRagePlayerMetrics *this, double damage)
{
  idRageStat::Add(this: this->stats.list + 20, owner: this, value: (int)damage);
}


// ========================================================================
// ?AddOverAmmoSP@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE3108
// RVA : 0x00DE3108
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AddOverAmmoSP(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 25, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 25, owner: this);
}


// ========================================================================
// ?AddFasterFasterSP@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE3160
// RVA : 0x00DE3160
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AddFasterFasterSP(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 27, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 27, owner: this);
}


// ========================================================================
// ?AddOverLoadSP@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE31B8
// RVA : 0x00DE31B8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AddOverLoadSP(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 29, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v2, this: this->stats.list + 29, owner: this);
}


// ========================================================================
// ?IsConsecutiveWithLastHit@idRagePlayerMetrics@@ABA_NPAUweaponQueueEntry_t@@@Z
// EA  : 0x82DE3210
// RVA : 0x00DE3210
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

int __fastcall idRagePlayerMetrics::IsConsecutiveWithLastHit(idRagePlayerMetrics *this, weaponQueueEntry_t *entry)
{
  weaponQueueEntry_t *p_lastHit; // r31
  char v4; // r10
  char v5; // r11
  unsigned __int8 v6; // r11
  bool v7; // zf
  _DWORD v9[25]; // [sp+50h] [-80h] BYREF

  p_lastHit = &this->lastHit;
  memcpy(Dst: v9, Src: &this->lastHit, Size: sizeof(v9));
  if ( p_lastHit->decl != (const idDecl *)v9[0] || (v4 = 1, p_lastHit->shotId != v9[24] - 1) )
    v4 = 0;
  if ( v4 != 0 )
    return 1;
  if ( entry->decl != p_lastHit->decl || (v5 = 1, entry->shotId != p_lastHit->shotId) )
    v5 = 0;
  v7 = v5 == 0;
  v6 = 0;
  if ( !v7 )
    return 1;
  return v6;
}


// ========================================================================
// ?WriteSessionData@idRagePlayerMetrics@@AAAXAAVidBitMsg@@@Z
// EA  : 0x82DE32C8
// RVA : 0x00DE32C8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::WriteSessionData(idRagePlayerMetrics *this, idBitMsg *msg)
{
  rageStat_t v4; // r28
  int i; // r31

  v4 = RAGE_STAT_VEHICLE_KILLS;
  for ( i = 0; i < 256; ++i )
  {
    RageStatTypeIsInt(stat: v4);
    idBitMsg::WriteBits(this: msg, value: this->stats.list[i].sessionValue.i, numBits: 32);
    ++v4;
  }
}


// ========================================================================
// ?ReadSessionData@idRagePlayerMetrics@@AAAXAAVidBitMsg@@@Z
// EA  : 0x82DE3338
// RVA : 0x00DE3338
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::ReadSessionData(idRagePlayerMetrics *this, idBitMsg *msg)
{
  rageStat_t v4; // r28
  int i; // r31

  v4 = RAGE_STAT_VEHICLE_KILLS;
  for ( i = 0; i < 256; ++i )
  {
    RageStatTypeIsInt(stat: v4);
    this->stats.list[i].sessionValue.i = idBitMsg::ReadBits(this: msg, numBits: 32);
    ++v4;
  }
}


// ========================================================================
// ?WriteSessionUnlockData@idRagePlayerMetrics@@AAAXAAVidBitMsg@@@Z
// EA  : 0x82DE33B8
// RVA : 0x00DE33B8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::WriteSessionUnlockData(idRagePlayerMetrics *this, idBitMsg *msg)
{
  int v4; // r28
  int i; // r31

  v4 = 0;
  for ( i = 50; i <= 58; ++i )
  {
    RageStatTypeIsInt(stat: (rageStat_t)(v4 + 50));
    idBitMsg::WriteBits(this: msg, value: this->stats.list[i].sessionValue.i, numBits: 32);
    ++v4;
  }
}


// ========================================================================
// ?ReadSessionUnlockData@idRagePlayerMetrics@@AAAXAAVidBitMsg@@@Z
// EA  : 0x82DE3428
// RVA : 0x00DE3428
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::ReadSessionUnlockData(idRagePlayerMetrics *this, idBitMsg *msg)
{
  int v4; // r28
  int i; // r31

  v4 = 0;
  for ( i = 50; i <= 58; ++i )
  {
    RageStatTypeIsInt(stat: (rageStat_t)(v4 + 50));
    this->stats.list[i].sessionValue.i = idBitMsg::ReadBits(this: msg, numBits: 32);
    ++v4;
  }
}


// ========================================================================
// ?AggregateUnlockStats@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE34A8
// RVA : 0x00DE34A8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AggregateUnlockStats(idRagePlayerMetrics *this)
{
  int i; // r31
  idRageStat::statValue_t v3[2]; // [sp+50h] [-20h] BYREF

  for ( i = 50; i <= 58; ++i )
    idRageStat::Aggregate(retstr: v3, this: &this->stats.list[i], owner: this);
}


// ========================================================================
// ?ClampSessionXp@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE3500
// RVA : 0x00DE3500
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::ClampSessionXp(idRagePlayerMetrics *this)
{
  idLocalUser *LocalUserFromPlayerIndex; // r30
  __int64 v3; // r9
  idResource *v4; // r3
  double v5; // fp0
  idLocalUser_vtbl *v6; // r10
  int (__fastcall *GetStatInt)(idLocalUser *, const int); // ctr
  int v8; // r3
  idRageStat *list; // r7
  idRageStat::statValue_t v10; // r11
  int v11; // r10
  __int64 v12; // [sp+50h] [-20h] BYREF

  LocalUserFromPlayerIndex = idClientGame::GetLocalUserFromPlayerIndex(this: clientGame, index: this->entityNumber);
  v4 = idResourceList::Index(this: &idDeclOnlineLevel::resourceList, index: 0);
  if ( LocalUserFromPlayerIndex != nullptr && v4 != nullptr )
  {
    v5 = *(float *)&v4[2].name.str;
    v6 = LocalUserFromPlayerIndex->__vftable;
    LODWORD(v3) = v4[2].nextOnHashChain;
    v12 = v3;
    GetStatInt = v6->GetStatInt;
    LODWORD(v12) = (int)(float)((float)v3 * (float)v5);
    v8 = GetStatInt(this: LocalUserFromPlayerIndex, a2: 23);
    list = this->stats.list;
    v10.i = (int)list[23].aggregatedValue;
    v11 = list[23].sessionValue.i - v10.i + v8;
    if ( v11 <= (int)v12 )
    {
      if ( v11 < 0 )
        this->stats.list[23].sessionValue.i = 0;
    }
    else
    {
      list[23].sessionValue.i = v10.i - v8 + v12;
    }
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)&v12, this: this->stats.list + 23, owner: this);
  }
}


// ========================================================================
// ?UpdateLongestLife@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE3610
// RVA : 0x00DE3610
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::UpdateLongestLife(idRagePlayerMetrics *this)
{
  idRageStat::statValue_t v2; // r30
  idRageStat::statValue_t v3; // r11

  if ( this->spawnTimestamp != 0x80000000 )
  {
    v2.i = (int)this->stats.list[105].sessionValue;
    v3.i = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->spawnTimestamp;
    if ( v2.i > v3.i )
      v3.i = v2.i;
    this->stats.list[105].sessionValue = v3;
    this->spawnTimestamp = 0x80000000;
  }
}


// ========================================================================
// ?GetQueueEntry@idRagePlayerMetrics@@AAAPAUweaponQueueEntry_t@@UweaponStatsTag_t@@@Z
// EA  : 0x82DE3680
// RVA : 0x00DE3680
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

weaponQueueEntry_t *__fastcall idRagePlayerMetrics::GetQueueEntry(idRagePlayerMetrics *this, unsigned int tag)
{
  int num; // r5
  int v3; // r6
  weaponQueueEntry_t *list; // r8
  int i; // r9
  weaponStatsTag_t v6; // r11
  unsigned int v7; // r10
  char v8; // r11

  num = this->weaponQueue.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->weaponQueue.list;
  for ( i = 0; ; ++i )
  {
    v6 = list[i].tag;
    if ( tag >> 26 != *(unsigned int *)&v6 >> 26
      || ((*(_DWORD *)&v6 ^ tag) & 0x3C00000) != 0
      || (v7 = (*(_DWORD *)&v6 ^ tag) & 0x3FFFFF, v8 = 1, v7 != 0) )
    {
      v8 = 0;
    }
    if ( v8 != 0 )
      break;
    if ( ++v3 >= num )
      return nullptr;
  }
  return &list[v3];
}


// ========================================================================
// ?Clear@idLevelStats@@QAAXXZ
// EA  : 0x82DE3838
// RVA : 0x00DE3838
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idLevelStats::Clear(idLevelStats *this)
{
  int num; // r9
  int v3; // r10
  int v4; // r9
  weaponStats_t *v5; // r11
  weaponStats_t *list; // r4

  num = this->weaponStats.num;
  this->damageTaken = 0;
  v3 = 0;
  this->startTime = -1;
  this->endTime = -1;
  this->itemsTaken = 0;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      ++v3;
      v5 = &this->weaponStats.list[v4];
      v5->damageEnemy = 0.0;
      ++v4;
      v5->damageFriendly = 0.0;
      v5->decl = nullptr;
      v5->fired = 0;
      v5->accHits = 0;
      v5->hitEnemy = 0;
      v5->killedEnemy = 0;
      v5->headshotEnemy = 0;
      v5->headshotEnemyKills = 0;
      v5->hitFriendly = 0;
      v5->killedFriendly = 0;
      v5->headshotFriendly = 0;
      v5->headshotFriendlyKills = 0;
      v5->actorsKilled = 0;
      v5->vehiclesKilled = 0;
      v5->breakablesDestroyed = 0;
      v5->directHit = 0;
      v5->hitObject = 0;
      v5->damageGeneral = 0;
      v5->hitVehicle = 0;
      v5->hitVehicleInAir = 0;
    }
    while ( v3 < this->weaponStats.num );
  }
  if ( this->weaponStats.listStatic == 0 || this->weaponStats.listStatic == 2 )
  {
    list = this->weaponStats.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->weaponStats.list = nullptr;
    this->weaponStats.size = 0;
  }
  this->weaponStats.num = 0;
}


// ========================================================================
// ?EndGame@idRagePlayerMetrics@@AAAXABVidGameChallenge@@_N@Z
// EA  : 0x82DE3948
// RVA : 0x00DE3948
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::EndGame(
        idRagePlayerMetrics *this,
        idGameChallenge_Coop *challenge,
        bool postStats)
{
  BOOL inGame; // r11
  idGameChallenge_Coop *v7; // r25
  unsigned __int64 v8; // r30
  idLobbyBase *v9; // r3
  const idMatchParameters *v10; // r28
  int v11; // r26
  int v12; // r29
  int v13; // r4
  int collectionStat; // r11
  idRageStat *v15; // r29
  int NumCollectiblesFound; // r3
  int specialCollectionStat; // r11
  idRageStat::statValue_t v18; // r29
  idRageStat::statValue_t v19; // r11
  int entityNumber; // r28
  int v21; // r11
  int v22; // r31
  idClientGame *LobbyUserIdFromPlayerIndex; // r3
  idBitMsg *v24; // r6
  int v25; // r11
  idBitMsg v26; // [sp+50h] [-4F0h] BYREF
  idBitMsg v27; // [sp+80h] [-4C0h] BYREF
  _BYTE v28[8]; // [sp+A8h] [-498h] BYREF
  _BYTE v29[48]; // [sp+B0h] [-490h] BYREF
  _BYTE v30[1120]; // [sp+E0h] [-460h] BYREF

  inGame = this->inGame;
  this->isAchievementReady = postStats;
  if ( inGame )
  {
    v7 = idGameChallenge_Coop::CastTo(c: challenge);
    LODWORD(v8) = 0;
    if ( v7 != nullptr )
    {
      v9 = session->GetActingGameStateLobbyBase(this: session);
      v10 = v9->GetMatchParms(this: v9);
      if ( !challenge->bGameFailed )
      {
        idLib::Printf(fmt: "Endgame stats for %s:\n", v7->name.data);
        idLib::Printf(fmt: "nightmare: %d\n", v10->nightmareCompletionStat);
        if ( v10->nightmareCompletionStat == -1 )
        {
          idLib::Warning(fmt: "Nightmare completion stat not set for %s", v7->name.data);
        }
        else if ( idGameLocal::GetGameCoopDifficulty(this: gameLocal) == 3 )
        {
          idRageStat::Increment(this: &this->stats.list[v10->nightmareCompletionStat], owner: this);
        }
        v11 = 0;
        if ( v10->completionStats.num > 0 )
        {
          v12 = 0;
          do
          {
            v13 = v10->completionStats.list[v12];
            if ( v13 != -1 )
            {
              idLib::Printf(fmt: "completed: %d\n", v13);
              idRageStat::Increment(this: &this->stats.list[v10->completionStats.list[v12]], owner: this);
            }
            ++v11;
            ++v12;
          }
          while ( v11 < v10->completionStats.num );
        }
        if ( (unsigned __int8)idGameChallenge_Coop::HasAllCollectibles(this: v7) != 0 )
        {
          collectionStat = v10->collectionStat;
          if ( collectionStat != -1 )
            idRageStat::Increment(this: &this->stats.list[collectionStat], owner: this);
        }
        idRageStat::Increment(this: this->stats.list + 219, owner: this);
        v15 = this->stats.list + 224;
        NumCollectiblesFound = idGameChallenge_Coop::GetNumCollectiblesFound(this: v7);
        idRageStat::Add(this: v15, owner: this, value: NumCollectiblesFound);
      }
      if ( idGameChallenge_Coop::HasSpecialCollectible(this: v7) )
      {
        specialCollectionStat = v10->specialCollectionStat;
        if ( specialCollectionStat != -1 )
          idRageStat::Increment(this: &this->stats.list[specialCollectionStat], owner: this);
      }
    }
    idRagePlayerMetrics::LostRallyChain(this);
    if ( this->bullyTimestamp != 0x80000000 )
    {
      v18.i = (int)this->stats.list[105].sessionValue;
      v19.i = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->bullyTimestamp;
      if ( v18.i > v19.i )
        v19.i = v18.i;
      this->stats.list[106].sessionValue = v19;
      this->bullyTimestamp = 0x80000000;
    }
    HIDWORD(v8) = postStats;
    if ( postStats )
    {
      memset(&v27.curSize, 0, 18);
      v27.writeData = v30;
      v27.readData = v30;
      v27.maxSize = 1029;
      v27.tempValue = v8;
      entityNumber = this->entityNumber;
      idBitMsg::WriteBits(this: &v27, value: entityNumber, numBits: 8);
      idBitMsg::WriteBits(this: &v27, value: postStats, numBits: 1);
      idRagePlayerMetrics::WriteSessionData(this, msg: &v27);
      v27.tempValue = v8;
      v21 = v27.writeBit != 0;
      v27.writeBit = 0;
      v27.curSize += v21;
      LODWORD(v8) = session->GetActingGameStateLobbyBase(this: session);
      v22 = *(_DWORD *)v8;
      LobbyUserIdFromPlayerIndex = idClientGame::GetLobbyUserIdFromPlayerIndex(
                                     this: (idClientGame *)v28,
                                     result: (lobbyUserID_t *)clientGame,
                                     playerIndex: entityNumber);
      v24 = &v27;
    }
    else
    {
      memset(&v26.curSize, 0, 18);
      v26.writeData = v29;
      v26.readData = v29;
      v26.maxSize = 41;
      v26.tempValue = 0;
      HIDWORD(v8) = this->entityNumber;
      idBitMsg::WriteBits(this: &v26, value: SHIDWORD(v8), numBits: 8);
      idBitMsg::WriteBits(this: &v26, value: 0, numBits: 1);
      idRagePlayerMetrics::WriteSessionUnlockData(this, msg: &v26);
      v26.tempValue = v8;
      v25 = v26.writeBit != 0;
      v26.writeBit = 0;
      v26.curSize += v25;
      LODWORD(v8) = session->GetActingGameStateLobbyBase(this: session);
      v22 = *(_DWORD *)v8;
      LobbyUserIdFromPlayerIndex = idClientGame::GetLobbyUserIdFromPlayerIndex(
                                     this: (idClientGame *)v28,
                                     result: (lobbyUserID_t *)clientGame,
                                     playerIndex: SHIDWORD(v8));
      v24 = &v26;
    }
    (*(void (__fastcall **)(_DWORD, idRenderWorld *, int, idBitMsg *))(v22 + 32))(
      a1: v8,
      a2: LobbyUserIdFromPlayerIndex->renderWorld,
      a3: 30,
      a4: v24);
  }
}


// ========================================================================
// ?AirKill@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE3D40
// RVA : 0x00DE3D40
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AirKill(idRagePlayerMetrics *this)
{
  __int64 v2; // r10
  idEventReceiver *eventListener; // r3
  __int64 v4; // r8
  __int64 v5; // [sp+8h] [-88h]
  __int64 v6; // [sp+10h] [-80h]
  __int64 v7; // [sp+18h] [-78h]
  __int64 v8; // [sp+20h] [-70h]
  __int64 v9; // [sp+28h] [-68h]
  __int64 v10; // [sp+30h] [-60h]
  idRageStat::statValue_t v11[4]; // [sp+50h] [-40h] BYREF
  const idEventDef *v12[2]; // [sp+60h] [-30h] BYREF
  __int64 v13; // [sp+68h] [-28h]
  int v14; // [sp+70h] [-20h]

  idRageStat::Increment(this: this->stats.list + 98, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v11, this: this->stats.list + 98, owner: this);
  LODWORD(v2) = v12;
  HIDWORD(v2) = 105;
  eventListener = this->eventListener;
  LODWORD(v4) = &s_memTag[218];
  v12[1] = (const idEventDef *)this->entityNumber;
  HIBYTE(v12[0]) = 105;
  HIDWORD(v4) = __ROL4__(v14, 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: v12[0],
    arg1: v13,
    a4: v4,
    a5: v2,
    a6: v5,
    a7: v6,
    a8: v7,
    a9: v8,
    a10: v9,
    a11: v10);
  if ( this->allowSpecialKill )
  {
    idRageStat::Increment(this: this->stats.list + 216, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v11, this: this->stats.list + 216, owner: this);
    this->allowSpecialKill = false;
  }
}


// ========================================================================
// ?AerialKill@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE3E10
// RVA : 0x00DE3E10
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AerialKill(idRagePlayerMetrics *this)
{
  __int64 v2; // r10
  idEventReceiver *eventListener; // r3
  __int64 v4; // r8
  __int64 v5; // [sp+8h] [-88h]
  __int64 v6; // [sp+10h] [-80h]
  __int64 v7; // [sp+18h] [-78h]
  __int64 v8; // [sp+20h] [-70h]
  __int64 v9; // [sp+28h] [-68h]
  __int64 v10; // [sp+30h] [-60h]
  idRageStat::statValue_t v11[4]; // [sp+50h] [-40h] BYREF
  const idEventDef *v12[2]; // [sp+60h] [-30h] BYREF
  __int64 v13; // [sp+68h] [-28h]
  int v14; // [sp+70h] [-20h]

  idRageStat::Increment(this: this->stats.list + 99, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v11, this: this->stats.list + 99, owner: this);
  LODWORD(v2) = v12;
  HIDWORD(v2) = 105;
  eventListener = this->eventListener;
  LODWORD(v4) = &s_memTag[218];
  v12[1] = (const idEventDef *)this->entityNumber;
  HIBYTE(v12[0]) = 105;
  HIDWORD(v4) = __ROL4__(v14, 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: v12[0],
    arg1: v13,
    a4: v4,
    a5: v2,
    a6: v5,
    a7: v6,
    a8: v7,
    a9: v8,
    a10: v9,
    a11: v10);
  if ( this->allowSpecialKill )
  {
    idRageStat::Increment(this: this->stats.list + 216, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v11, this: this->stats.list + 216, owner: this);
    this->allowSpecialKill = false;
  }
}


// ========================================================================
// ?AfterlifeKill@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE3EE0
// RVA : 0x00DE3EE0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AfterlifeKill(idRagePlayerMetrics *this)
{
  __int64 v2; // r10
  idEventReceiver *eventListener; // r3
  __int64 v4; // r8
  __int64 v5; // [sp+8h] [-88h]
  __int64 v6; // [sp+10h] [-80h]
  __int64 v7; // [sp+18h] [-78h]
  __int64 v8; // [sp+20h] [-70h]
  __int64 v9; // [sp+28h] [-68h]
  __int64 v10; // [sp+30h] [-60h]
  idRageStat::statValue_t v11[4]; // [sp+50h] [-40h] BYREF
  const idEventDef *v12[2]; // [sp+60h] [-30h] BYREF
  __int64 v13; // [sp+68h] [-28h]
  int v14; // [sp+70h] [-20h]

  idRageStat::Increment(this: this->stats.list + 101, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v11, this: this->stats.list + 101, owner: this);
  LODWORD(v2) = v12;
  HIDWORD(v2) = 105;
  eventListener = this->eventListener;
  LODWORD(v4) = &s_memTag[218];
  v12[1] = (const idEventDef *)this->entityNumber;
  HIBYTE(v12[0]) = 105;
  HIDWORD(v4) = __ROL4__(v14, 32);
  idEventReceiver::BroadcastEvent(
    this: eventListener,
    ev: v12[0],
    arg1: v13,
    a4: v4,
    a5: v2,
    a6: v5,
    a7: v6,
    a8: v7,
    a9: v8,
    a10: v9,
    a11: v10);
  if ( this->allowSpecialKill )
  {
    idRageStat::Increment(this: this->stats.list + 216, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v11, this: this->stats.list + 216, owner: this);
    this->allowSpecialKill = false;
  }
}


// ========================================================================
// ?VehicleDeath@idRagePlayerMetrics@@AAAXHPBVidDeclDamage@@@Z
// EA  : 0x82DE3FB0
// RVA : 0x00DE3FB0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::VehicleDeath(
        idRagePlayerMetrics *this,
        int killerEntityNum,
        const idDeclDamage *damageDef)
{
  int entityNumber; // r8
  int v7; // r10 OVERLAPPED
  __int128 v8; // r9 OVERLAPPED
  idRageStat::statValue_t v9; // r30
  idRageStat::statValue_t v10; // r11
  idRageStat::statValue_t v11; // r30
  idRageStat::statValue_t v12; // r11
  __int64 v13; // [sp+8h] [-108h]
  __int64 v14; // [sp+10h] [-100h]
  __int64 v15; // [sp+18h] [-F8h]
  __int64 v16; // [sp+20h] [-F0h]
  __int64 v17; // [sp+28h] [-E8h]
  __int64 v18; // [sp+30h] [-E0h]
  __int64 v19; // [sp+38h] [-D8h]
  __int64 v20; // [sp+40h] [-D0h]
  __int64 v21; // [sp+48h] [-C8h]
  __int64 v22; // [sp+50h] [-C0h]
  int v23; // [sp+58h] [-B8h]
  int v24; // [sp+5Ch] [-B4h]
  int v25[8]; // [sp+60h] [-B0h] BYREF
  idRageStat::statValue_t v26[4]; // [sp+80h] [-90h] BYREF
  _DWORD v27[5]; // [sp+90h] [-80h] BYREF
  char v28; // [sp+B0h] [-60h]
  int v29; // [sp+B4h] [-5Ch]
  __int64 v30; // [sp+B8h] [-58h]
  int v31; // [sp+C0h] [-50h]
  const idEventDef *v32; // [sp+D0h] [-40h]
  int v33; // [sp+D4h] [-3Ch]
  __int64 v34; // [sp+D8h] [-38h]
  int v35; // [sp+E0h] [-30h]

  idRageStat::Increment(this: this->stats.list + 1, owner: this);
  v27[1] = damageDef;
  HIBYTE(v27[0]) = 100;
  entityNumber = this->entityNumber;
  v29 = killerEntityNum;
  v28 = 105;
  this->lastKillTimestamp = 0x80000000;
  this->killsThisLife = 0;
  HIBYTE(v32) = 105;
  v33 = entityNumber;
  memcpy(Dst: v25, Src: v27, Size: 0x14u);
  v7 = __ROL4__(v31, 32);
  *((_QWORD *)&v8 + 1) = v30;
  DWORD1(v8) = __ROL4__(v35, 32);
  idEventReceiver::BroadcastEvent(
    this: this->eventListener,
    ev: v32,
    arg2: v34,
    arg3: *(__int64 *)((char *)&v8 + 4),
    a5: *(__int64 *)&v7,
    a6: v13,
    a7: v14,
    a8: v15,
    a9: v16,
    a10: v17,
    a11: v18,
    a12: v19,
    a13: v20,
    a14: v21,
    a15: v22,
    a16: v23,
    a17: v24,
    a18: v25[0]);
  if ( this->spawnTimestamp != 0x80000000 )
  {
    v9.i = (int)this->stats.list[105].sessionValue;
    v10.i = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->spawnTimestamp;
    if ( v9.i > v10.i )
      v10.i = v9.i;
    this->stats.list[105].sessionValue = v10;
    this->spawnTimestamp = 0x80000000;
  }
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v26, this: this->stats.list + 1, owner: this);
  idRagePlayerMetrics::LostRallyChain(this);
  if ( this->bullyTimestamp != 0x80000000 )
  {
    v11.i = (int)this->stats.list[105].sessionValue;
    v12.i = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->bullyTimestamp;
    if ( v11.i > v12.i )
      v12.i = v11.i;
    this->stats.list[106].sessionValue = v12;
    this->bullyTimestamp = 0x80000000;
  }
}


// ========================================================================
// ?Revenge@idRagePlayerMetrics@@AAAXH@Z
// EA  : 0x82DE4120
// RVA : 0x00DE4120
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::Revenge(idRagePlayerMetrics *this, int victimEntityNum)
{
  idRageStat::statValue_t v3[4]; // [sp+50h] [-20h] BYREF

  idRageStat::Increment(this: this->stats.list + 102, owner: this);
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v3, this: this->stats.list + 102, owner: this);
  if ( this->allowSpecialKill )
  {
    idRageStat::Increment(this: this->stats.list + 216, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v3, this: this->stats.list + 216, owner: this);
    this->allowSpecialKill = false;
  }
}


// ========================================================================
// ?GainXP@idRagePlayerMetrics@@AAAXHPBVidDeclMetric@@@Z
// EA  : 0x82DE41C0
// RVA : 0x00DE41C0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::GainXP(idRagePlayerMetrics *this, int xp, const idDeclMetric *xpSource)
{
  bool v6; // r3
  idRageStat *list; // r11
  idRageStat *v8; // r3
  bool v9; // zf
  unsigned __int64 v10; // r11
  int entityNumber; // r31
  int NetworkID; // r3
  idLobbyBase *v13; // r30
  int v14; // r5
  idLobbyBase_vtbl *v15; // r31
  idClientGame *LobbyUserIdFromPlayerIndex; // r3
  char v17; // [sp+50h] [-70h] BYREF
  _BYTE v18[24]; // [sp+58h] [-68h] BYREF
  idBitMsg v19[2]; // [sp+70h] [-50h] BYREF

  if ( playerMetrics_Verbose.valueInteger != 0 )
    idLib::Printf(fmt: "Player %d gainingXP: xp %d \n", this->entityNumber, xp);
  v6 = common->IsMultiplayer(this: common);
  list = this->stats.list;
  v9 = v6;
  v8 = list + 23;
  if ( !v9 )
    v8 = list + 22;
  idRageStat::Add(this: v8, owner: this, value: xp);
  if ( xpSource != nullptr )
  {
    LODWORD(v10) = 0;
    entityNumber = this->entityNumber;
    HIDWORD(v10) = v18;
    v19[0].curSize = 0;
    v19[0].writeData = v18;
    v19[0].readData = v18;
    v19[0].maxSize = 12;
    v19[0].writeBit = 0;
    v19[0].readCount = 0;
    v19[0].readBit = 0;
    v19[0].allowOverflow = false;
    v19[0].overflowed = false;
    v19[0].tempValue = v10;
    idBitMsg::WriteBits(this: v19, value: entityNumber, numBits: 8);
    idBitMsg::WriteBits(this: v19, value: xp, numBits: 32);
    NetworkID = idResource::GetNetworkID(this: &xpSource->idDeclTypeInfo, alloc: true);
    idBitMsg::WriteBits(this: v19, value: NetworkID + 1, numBits: 32);
    v13 = session->GetActingGameStateLobbyBase(this: session);
    v14 = entityNumber;
    v15 = v13->__vftable;
    LobbyUserIdFromPlayerIndex = idClientGame::GetLobbyUserIdFromPlayerIndex(
                                   this: (idClientGame *)&v17,
                                   result: (lobbyUserID_t *)clientGame,
                                   playerIndex: v14);
    v15->SendReliableToLobbyUser(
      this: (idLobbyBase *)LobbyUserIdFromPlayerIndex->random.seed,
      a2: (lobbyUserID_t *)LobbyUserIdFromPlayerIndex->renderWorld,
      a3: 31,
      a4: v19);
  }
}


// ========================================================================
// ?UpdateLevel@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE4318
// RVA : 0x00DE4318
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::UpdateLevel(idRagePlayerMetrics *this)
{
  idLocalUser *LocalUserFromPlayerIndex; // r30
  idLocalUser *v3; // r3
  idRageStat::statValue_t v4; // r30
  int (__fastcall *GetStatInt)(idLocalUser *, const int); // ctr
  int v6; // r30
  int i; // r29
  idDeclOnlineLevel *v8; // r3
  __int64 v9; // r10
  int v10; // r7
  int v11; // r6
  int v12; // r5
  idRageStat::statValue_t v13[12]; // [sp+50h] [-30h] BYREF

  idRagePlayerMetrics::ClampSessionXp(this);
  LocalUserFromPlayerIndex = idClientGame::GetLocalUserFromPlayerIndex(this: clientGame, index: this->entityNumber);
  if ( LocalUserFromPlayerIndex != nullptr && common->IsMultiplayer(this: common) )
  {
    v3 = LocalUserFromPlayerIndex;
    GetStatInt = LocalUserFromPlayerIndex->GetStatInt;
    v4.i = (int)this->stats.list[32].aggregatedValue;
    v6 = GetStatInt(this: v3, a2: 32) - v4.i;
    i = idRageStat::Aggregate(retstr: v13, this: this->stats.list + 23, owner: this)->i;
    v8 = (idDeclOnlineLevel *)idResourceList::Index(this: &idDeclOnlineLevel::resourceList, index: 0);
    this->stats.list[32].sessionValue.i = idDeclOnlineLevel::GetLevelForXp(
                                            this: v8,
                                            xp: i,
                                            a3: v12,
                                            a4: v11,
                                            a5: v10,
                                            a6: v9)
                                        - v6;
    idRageStat::Aggregate(retstr: v13, this: this->stats.list + 32, owner: this);
    if ( this->isAchievementReady )
      idRageStat::Aggregate(retstr: v13, this: this->stats.list + 32, owner: this);
    session->SendLocalSessionUsersToPeers(this: session);
  }
}


// ========================================================================
// ?Death@idRagePlayerMetrics@@AAAXHPBVidDeclDamage@@@Z
// EA  : 0x82DE4428
// RVA : 0x00DE4428
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::Death(
        idRagePlayerMetrics *this,
        int killerEntityNum,
        const idDeclDamage *damageDef)
{
  int entityNumber; // r8
  int v7; // r10 OVERLAPPED
  __int128 v8; // r9 OVERLAPPED
  idRageStat::statValue_t v9; // r30
  idRageStat::statValue_t v10; // r11
  __int64 v11; // [sp+8h] [-108h]
  __int64 v12; // [sp+10h] [-100h]
  __int64 v13; // [sp+18h] [-F8h]
  __int64 v14; // [sp+20h] [-F0h]
  __int64 v15; // [sp+28h] [-E8h]
  __int64 v16; // [sp+30h] [-E0h]
  __int64 v17; // [sp+38h] [-D8h]
  __int64 v18; // [sp+40h] [-D0h]
  __int64 v19; // [sp+48h] [-C8h]
  __int64 v20; // [sp+50h] [-C0h]
  int v21; // [sp+58h] [-B8h]
  int v22; // [sp+5Ch] [-B4h]
  int v23[8]; // [sp+60h] [-B0h] BYREF
  idRageStat::statValue_t v24[4]; // [sp+80h] [-90h] BYREF
  _DWORD v25[5]; // [sp+90h] [-80h] BYREF
  char v26; // [sp+B0h] [-60h]
  int v27; // [sp+B4h] [-5Ch]
  __int64 v28; // [sp+B8h] [-58h]
  int v29; // [sp+C0h] [-50h]
  const idEventDef *v30; // [sp+D0h] [-40h]
  int v31; // [sp+D4h] [-3Ch]
  __int64 v32; // [sp+D8h] [-38h]
  int v33; // [sp+E0h] [-30h]

  idRageStat::Increment(this: this->stats.list + 249, owner: this);
  v25[1] = damageDef;
  HIBYTE(v25[0]) = 100;
  entityNumber = this->entityNumber;
  v27 = killerEntityNum;
  v26 = 105;
  this->lastKillTimestamp = 0x80000000;
  this->killsThisLife = 0;
  HIBYTE(v30) = 105;
  v31 = entityNumber;
  memcpy(Dst: v23, Src: v25, Size: 0x14u);
  v7 = __ROL4__(v29, 32);
  *((_QWORD *)&v8 + 1) = v28;
  DWORD1(v8) = __ROL4__(v33, 32);
  idEventReceiver::BroadcastEvent(
    this: this->eventListener,
    ev: v30,
    arg2: v32,
    arg3: *(__int64 *)((char *)&v8 + 4),
    a5: *(__int64 *)&v7,
    a6: v11,
    a7: v12,
    a8: v13,
    a9: v14,
    a10: v15,
    a11: v16,
    a12: v17,
    a13: v18,
    a14: v19,
    a15: v20,
    a16: v21,
    a17: v22,
    a18: v23[0]);
  if ( this->spawnTimestamp != 0x80000000 )
  {
    v9.i = (int)this->stats.list[105].sessionValue;
    v10.i = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->spawnTimestamp;
    if ( v9.i > v10.i )
      v10.i = v9.i;
    this->stats.list[105].sessionValue = v10;
    this->spawnTimestamp = 0x80000000;
  }
  if ( this->isAchievementReady )
    idRageStat::Aggregate(retstr: v24, this: this->stats.list + 249, owner: this);
}


// ========================================================================
// ?UpdateImpressive@idRagePlayerMetrics@@AAAXPAUweaponQueueEntry_t@@@Z
// EA  : 0x82DE4548
// RVA : 0x00DE4548
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::UpdateImpressive(idRagePlayerMetrics *this, weaponQueueEntry_t *entry)
{
  idDecl *decl; // r29
  const idDeclWeapon *v5; // r4
  idRageStat *v6; // r30
  __int64 v7; // r10
  idEventReceiver *eventListener; // r3
  __int64 v9; // r8
  __int64 v10; // [sp+8h] [-98h]
  __int64 v11; // [sp+10h] [-90h]
  __int64 v12; // [sp+18h] [-88h]
  __int64 v13; // [sp+20h] [-80h]
  __int64 v14; // [sp+28h] [-78h]
  __int64 v15; // [sp+30h] [-70h]
  idRageStat::statValue_t v16[4]; // [sp+50h] [-50h] BYREF
  const idEventDef *v17[2]; // [sp+60h] [-40h] BYREF
  __int64 v18; // [sp+68h] [-38h]
  int v19; // [sp+70h] [-30h]

  if ( entry != nullptr )
  {
    decl = (idDecl *)entry->decl;
    if ( entry->decl != nullptr
      && (unsigned __int8)idRagePlayerMetrics::IsConsecutiveWithLastHit(this, entry) != 0
      && (unsigned __int8)idDecl::IsType<idDeclWeapon>(this: decl) != 0 )
    {
      v5 = (const idDeclWeapon *)entry->decl;
      if ( entry->decl != nullptr )
      {
        v6 = this->stats.list + 10;
        if ( v6->decl != nullptr && idDeclMetric::IsWeaponListed(this: v6->decl, decl: v5) )
        {
          idRageStat::Increment(this: v6, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: v16, this: this->stats.list + 10, owner: this);
          LODWORD(v7) = v17;
          HIDWORD(v7) = 105;
          eventListener = this->eventListener;
          LODWORD(v9) = &s_memTag[218];
          v17[1] = (const idEventDef *)this->entityNumber;
          HIBYTE(v17[0]) = 105;
          HIDWORD(v9) = __ROL4__(v19, 32);
          idEventReceiver::BroadcastEvent(
            this: eventListener,
            ev: v17[0],
            arg1: v18,
            a4: v9,
            a5: v7,
            a6: v10,
            a7: v11,
            a8: v12,
            a9: v13,
            a10: v14,
            a11: v15);
        }
      }
    }
  }
}


// ========================================================================
// ?AggregateStats@idRagePlayerMetrics@@AAAXXZ
// EA  : 0x82DE4630
// RVA : 0x00DE4630
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::AggregateStats(idRagePlayerMetrics *this)
{
  int i; // r31
  idRageStat::statValue_t v3[2]; // [sp+50h] [-20h] BYREF

  for ( i = 0; i < 256; ++i )
    idRageStat::Aggregate(retstr: v3, this: &this->stats.list[i], owner: this);
}


// ========================================================================
// ?WeaponFiredResult@idRagePlayerMetrics@@AAAXUweaponStatsTag_t@@PAVidEntity@@M@Z
// EA  : 0x82DE4688
// RVA : 0x00DE4688
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRagePlayerMetrics::WeaponFiredResult(
        idRagePlayerMetrics *this,
        unsigned int tag,
        idActor *target,
        double damage)
{
  int v4; // r22
  weaponQueueEntry_t *QueueEntry; // r3
  weaponQueueEntry_t *v10; // r25
  weaponStats_t *p_wstats; // r30
  unsigned int v12; // r28
  idPlayer *Player; // r23
  idActor *v14; // r3
  idPlayer *v15; // r26
  const idFaction *v16; // r29
  int v17; // r3
  int v18; // r25
  double v19; // fp30
  idPlayer *v20; // r3
  idFaction *v21; // r3
  char v22; // r11
  char v23; // r29
  int v24; // r11
  int v25; // r11
  unsigned __int8 *v26; // r11
  const char *v27; // r10
  int v28; // r9
  int v29; // r9
  bool v30; // zf
  int headshotEnemy; // r10
  int entityNumber; // r9
  int v33; // r7
  int v36; // r10 OVERLAPPED
  __int128 v37; // r9 OVERLAPPED
  double v38; // fp1
  char v39; // r11
  int damageGroup; // r10
  int v41; // r11
  unsigned __int8 *v42; // r11
  const char *v43; // r10
  int v44; // r9
  int v45; // r9
  idVehicle *v46; // r3
  idVehicle *v47; // r29
  const idFaction *v48; // r26
  double v49; // fp30
  idPlayer *v50; // r3
  idFaction *v51; // r3
  idRelationship::attitude_t AttitudeTowards; // r3
  __int64 v53; // r11
  idVehicle *PlayerFromEntity; // r3
  idRageStat *v55; // r4
  idVehicle_Car *v56; // r3
  idProp_Breakable *v57; // r3
  int v58; // r10
  __int64 v59; // [sp+8h] [-198h]
  __int64 v60; // [sp+10h] [-190h]
  __int64 v61; // [sp+18h] [-188h]
  __int64 v62; // [sp+20h] [-180h]
  __int64 v63; // [sp+28h] [-178h]
  __int64 v64; // [sp+30h] [-170h]
  __int64 v65; // [sp+38h] [-168h]
  __int64 v66; // [sp+40h] [-160h]
  __int64 v67; // [sp+48h] [-158h]
  __int64 v68; // [sp+50h] [-150h]
  int v69; // [sp+58h] [-148h]
  int v70; // [sp+5Ch] [-144h]
  int v71[8]; // [sp+60h] [-140h] BYREF
  int v72[8]; // [sp+80h] [-120h] BYREF
  idRageStat::statValue_t v73[4]; // [sp+A0h] [-100h] BYREF
  _DWORD v74[5]; // [sp+B0h] [-F0h] BYREF
  int v75; // [sp+D0h] [-D0h]
  int v76; // [sp+D4h] [-CCh]
  __int64 v77; // [sp+D8h] [-C8h]
  int v78; // [sp+E0h] [-C0h]
  const idEventDef *v79; // [sp+F0h] [-B0h]
  int v80; // [sp+F4h] [-ACh]
  __int64 v81; // [sp+F8h] [-A8h]
  float v82[5]; // [sp+110h] [-90h] BYREF

  v73[1].i = (int)damage;
  v4 = (int)damage;
  QueueEntry = idRagePlayerMetrics::GetQueueEntry(this, tag);
  v10 = QueueEntry;
  if ( QueueEntry == nullptr )
  {
    idLib::Warning(fmt: "WeaponFiredResult with no queue entry");
    return;
  }
  p_wstats = &QueueEntry->wstats;
  if ( target != nullptr && damage > 0.0 && target->TakesDamage(this: target) )
  {
    v12 = tag >> 26;
    Player = idGameLocal::GetPlayer(this: gameLocal, i: tag >> 26);
    idRagePlayerMetrics::UpdateImpressive(this, entry: v10);
    memcpy(Dst: &this->lastHit, Src: v10, Size: sizeof(this->lastHit));
    v14 = idActor::CastTo(c: target);
    v15 = (idPlayer *)v14;
    if ( v14 != nullptr )
    {
      v16 = v14->GetFaction(this: v14);
      v17 = (int)v15->GetHealthComponent_2(this: v15);
      v18 = v17;
      if ( v17 != 0 )
        v19 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v17 + 60))(a1: v17);
      else
        v19 = 0.0;
      v20 = idGameLocal::GetPlayer(this: gameLocal, i: v12);
      v21 = v20->GetFaction(this: v20);
      if ( v16 != nullptr && v21 != nullptr )
      {
        if ( v15 == Player || idFaction::GetAttitudeTowards(this: v21, otherFaction: v16) >= ATTITUDE_NEUTRAL )
        {
          ++p_wstats->hitFriendly;
          if ( v19 <= 0.0 )
          {
            ++p_wstats->killedFriendly;
            idRageStat::Increment(this: this->stats.list + 171, owner: this);
            if ( this->isAchievementReady )
              idRageStat::Aggregate(retstr: v73, this: this->stats.list + 170, owner: this);
            ++p_wstats->actorsKilled;
            idRageStat::Increment(this: this->stats.list + 176, owner: this);
            if ( this->isAchievementReady )
              idRageStat::Aggregate(retstr: v73, this: this->stats.list + 176, owner: this);
          }
          p_wstats->damageFriendly = p_wstats->damageFriendly + (float)damage;
          idRageStat::Add(this: this->stats.list + 172, owner: this, value: v4);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: v73, this: this->stats.list + 172, owner: this);
          damageGroup = v15->damageGroup;
          if ( damageGroup >= 0 )
          {
            v41 = (int)&v15->actorEditable.damageGroups.list[damageGroup];
            if ( v41 != 0 )
            {
              v42 = *(unsigned __int8 **)(v41 + 4);
              v43 = "head";
              do
              {
                v44 = *v42;
                v30 = v44 == 0;
                v45 = v44 - *(unsigned __int8 *)v43;
                if ( v30 )
                  break;
                ++v42;
                ++v43;
              }
              while ( v45 == 0 );
              if ( v45 == 0 )
              {
                ++p_wstats->headshotFriendly;
                if ( v18 == 0
                  && (*(unsigned __int8 (__fastcall **)(_DWORD))(MEMORY[0] + 88))(a1: 0) != 0
                  && damage > 0.0 )
                {
                  ++p_wstats->headshotFriendlyKills;
                }
              }
            }
          }
        }
        else
        {
          if ( v19 <= -damage || (v22 = 1, v19 > 0.0) )
            v22 = 0;
          v23 = v22;
          if ( v19 > 0.0 || v22 != 0 )
          {
            ++p_wstats->hitEnemy;
            v24 = v15->damageGroup;
            if ( v24 >= 0 )
            {
              v25 = (int)&v15->actorEditable.damageGroups.list[v24];
              if ( v25 != 0 )
              {
                v26 = *(unsigned __int8 **)(v25 + 4);
                v27 = "head";
                do
                {
                  v28 = *v26;
                  v30 = v28 == 0;
                  v29 = v28 - *(unsigned __int8 *)v27;
                  if ( v30 )
                    break;
                  ++v26;
                  ++v27;
                }
                while ( v29 == 0 );
                if ( v29 == 0 )
                {
                  ++p_wstats->headshotEnemy;
                  if ( v23 != 0 )
                    ++p_wstats->headshotEnemyKills;
                }
              }
            }
            p_wstats->damageEnemy = p_wstats->damageEnemy + (float)damage;
            idRageStat::Add(this: this->stats.list + 172, owner: this, value: v4);
            if ( this->isAchievementReady )
              idRageStat::Aggregate(retstr: v73, this: this->stats.list + 172, owner: this);
            headshotEnemy = p_wstats->headshotEnemy;
            entityNumber = v15->entityNumber;
            HIBYTE(v74[0]) = 105;
            v33 = Player->entityNumber;
            HIBYTE(v75) = 105;
            HIBYTE(v82[0]) = 102;
            v76 = entityNumber;
            HIBYTE(v79) = 105;
            v74[1] = (-headshotEnemy & (unsigned int)~headshotEnemy) >> 31;
            v80 = v33;
            _FP13 = (float)((float)damage - (float)((float)v19 + (float)damage));
            __asm { fsel      f12, f13, f0, f29 }
            v82[1] = _FP12;
            memcpy(Dst: v72, Src: v74, Size: 0x14u);
            memcpy(Dst: v71, Src: v82, Size: 0x14u);
            v36 = __ROL4__(v78, 32);
            *((_QWORD *)&v37 + 1) = v77;
            DWORD1(v37) = __ROL4__(v75, 32);
            idEventReceiver::BroadcastEvent(
              this: this->eventListener,
              ev: v79,
              arg2: v81,
              arg4: *(__int64 *)((char *)&v37 + 4),
              a5: *(__int64 *)&v36,
              a6: v59,
              a7: v60,
              a8: v61,
              a9: v62,
              a10: v63,
              a11: v64,
              a12: v65,
              a13: v66,
              a14: v67,
              a15: v68,
              a16: v69,
              a17: v70,
              a18: v71[0],
              a19: v71[1],
              a20: v71[2],
              a21: v71[3],
              arg3: v71[4],
              arg3_4: v71[5],
              arg3_8: v71[6],
              arg3_12: v71[7],
              arg3_16: v72[0]);
          }
          if ( v23 != 0 )
          {
            ++p_wstats->killedEnemy;
            idRageStat::Increment(this: this->stats.list + 170, owner: this);
            if ( this->isAchievementReady )
              idRageStat::Aggregate(retstr: v73, this: this->stats.list + 170, owner: this);
            ++p_wstats->actorsKilled;
            idRageStat::Increment(this: this->stats.list + 176, owner: this);
            if ( this->isAchievementReady )
              idRageStat::Aggregate(retstr: v73, this: this->stats.list + 176, owner: this);
            if ( v18 == 0
              || (v38 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v18 + 64))(a1: v18),
                  v39 = 0,
                  (float)((float)v19 + (float)damage) >= v38) )
            {
              v39 = 1;
            }
            if ( v39 != 0 )
            {
              idRageStat::Increment(this: this->stats.list + 200, owner: this);
              if ( this->isAchievementReady )
                idRageStat::Aggregate(retstr: v73, this: this->stats.list + 200, owner: this);
            }
          }
        }
      }
      return;
    }
    v46 = idVehicle::CastTo(c: (idVehicle *)target);
    v47 = v46;
    if ( v46 != nullptr )
    {
      v48 = v46->GetFaction(this: v46);
      v49 = ((double (__fastcall *)(idVehicle *))v47->GetHealth)(a1: v47);
      v50 = idGameLocal::GetPlayer(this: gameLocal, i: v12);
      LOBYTE(v12) = 1;
      v51 = v50->GetFaction(this: v50);
      if ( v48 != nullptr && v51 != nullptr )
      {
        AttitudeTowards = idFaction::GetAttitudeTowards(this: v51, otherFaction: v48);
        LODWORD(v53) = 3;
        HIDWORD(v53) = (unsigned int)AttitudeTowards >> 31;
        v12 = (((unsigned __int64)(unsigned int)AttitudeTowards - v53) >> 32) & 1;
      }
      PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: v47);
      if ( (_BYTE)v12 != 0 )
        LOBYTE(v12) = PlayerFromEntity == (idVehicle *)Player ? 0 : v12;
      if ( (_BYTE)v12 != 0 )
      {
        ++v10->wstats.hitEnemy;
        if ( damage > 0.0 && v49 <= 0.0 )
        {
          ++v10->wstats.killedEnemy;
          idRageStat::Increment(this: this->stats.list + 170, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: v73, this: this->stats.list + 170, owner: this);
          ++v10->wstats.vehiclesKilled;
          idRageStat::Increment(this: this->stats.list + 177, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: v73, this: this->stats.list + 177, owner: this);
        }
        v10->wstats.damageEnemy = v10->wstats.damageEnemy + (float)damage;
        idRageStat::Add(this: this->stats.list + 172, owner: this, value: v4);
        if ( !this->isAchievementReady )
          goto LABEL_81;
        v55 = this->stats.list + 172;
      }
      else
      {
        ++v10->wstats.hitFriendly;
        if ( v49 <= 0.0 )
        {
          ++v10->wstats.killedFriendly;
          idRageStat::Increment(this: this->stats.list + 171, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: v73, this: this->stats.list + 171, owner: this);
          ++v10->wstats.vehiclesKilled;
          idRageStat::Increment(this: this->stats.list + 171, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: v73, this: this->stats.list + 171, owner: this);
        }
        v10->wstats.damageFriendly = v10->wstats.damageFriendly + (float)damage;
        idRageStat::Add(this: this->stats.list + 173, owner: this, value: v4);
        if ( !this->isAchievementReady )
          goto LABEL_81;
        v55 = this->stats.list + 173;
      }
      idRageStat::Aggregate(retstr: v73, this: v55, owner: this);
LABEL_81:
      if ( (unsigned __int8)idDecl::IsType<idDeclVehicleWeapon>(this: (idDecl *)v10->decl) != 0 )
      {
        v56 = idVehicle_Car::CastTo(c: (idVehicle_Car *)target);
        if ( v56 != nullptr && idVehicle_Car::GetNumWheelsOnGround(this: v56) == 0 )
          ++v10->wstats.hitVehicleInAir;
        ++v10->wstats.hitVehicle;
        idRageStat::Add(this: this->stats.list + 9, owner: this, value: v4);
        if ( this->isAchievementReady )
          idRageStat::Aggregate(retstr: v73, this: this->stats.list + 9, owner: this);
      }
      return;
    }
    v57 = idProp_Breakable::CastTo(c: (idProp_Breakable *)target);
    if ( v57 != nullptr )
    {
      if ( ((double (__fastcall *)(idProp_Breakable *))v57->GetHealth)(a1: v57) <= 0.0 )
      {
        ++v10->wstats.breakablesDestroyed;
        idRageStat::Increment(this: this->stats.list + 168, owner: this);
        if ( this->isAchievementReady )
          idRageStat::Aggregate(retstr: v73, this: this->stats.list + 168, owner: this);
      }
      goto LABEL_91;
    }
    if ( idBreakable::CastTo(c: (idBreakable *)target) != nullptr )
    {
LABEL_91:
      v58 = v10->wstats.hitObject + 1;
      v10->wstats.damageGeneral += v4;
      v10->wstats.hitObject = v58;
      idRageStat::Add(this: this->stats.list + 169, owner: this, value: v4);
      if ( this->isAchievementReady )
        idRageStat::Aggregate(retstr: v73, this: this->stats.list + 169, owner: this);
      return;
    }
    if ( idTurretGunner::CastTo(c: (idTurretGunner *)target) != nullptr )
      ++v10->wstats.hitEnemy;
  }
}


// ========================================================================
// ?Init@idRagePlayerMetrics@@AAAXPAVidEventReceiver@@H@Z
// EA  : 0x82DE5390
// RVA : 0x00DE5390
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::Init(idRagePlayerMetrics *this, idEventReceiver *listener, int entityNumber)
{
  int size; // r31
  idStaticList<idRageStat,256> *p_stats; // r28
  int v6; // r11
  int v7; // r30
  int v8; // r31

  size = this->stats.size;
  p_stats = &this->stats;
  this->entityNumber = entityNumber;
  this->eventListener = listener;
  v6 = this->stats.size;
  if ( size < v6 )
    v6 = size;
  this->stats.num = v6;
  v7 = 0;
  if ( this->stats.num > 0 )
  {
    v8 = 0;
    do
    {
      idRageStat::Init(this: &p_stats->list[v8], owner: this);
      ++v7;
      ++v8;
    }
    while ( v7 < this->stats.num );
  }
}


// ========================================================================
// ??0idRagePlayerMetrics@@QAA@XZ
// EA  : 0x82DE56F8
// RVA : 0x00DE56F8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

idRagePlayerMetrics *__fastcall idRagePlayerMetrics::idRagePlayerMetrics(idRagePlayerMetrics *this)
{
  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idRagePlayerMetrics_vtbl *)&idRagePlayerMetrics::`vftable';
  idStaticList<idRageStat,256>::idStaticList<idRageStat,256>(this: &this->stats);
  this->eventListener = nullptr;
  this->kdr = 0.0;
  this->entityNumber = -1;
  this->lastKillTimestamp = 0x80000000;
  this->currentKillStreak = 0;
  this->killsThisLife = 0;
  this->currentRallyStreak = 0;
  this->shieldActivationTime = -1;
  *(_WORD *)&this->inGame = 1;
  this->spawnTimestamp = 0x80000000;
  this->bullyTimestamp = 0x80000000;
  this->maxChainTimestamp = 0x80000000;
  this->origin = vec3_origin;
  this->allowSpecialKill = true;
  this->weaponQueue.list = nullptr;
  this->weaponQueue.granularity = 0;
  this->weaponQueue.memTag = 5;
  this->weaponQueue.listStatic = 0;
  this->weaponQueue.size = 0;
  this->weaponQueue.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weaponQueue);
  this->lastHit.decl = nullptr;
  this->lastHit.tag = 0;
  this->lastHit.wstats.damageEnemy = 0.0;
  this->lastHit.wstats.decl = nullptr;
  this->lastHit.wstats.damageFriendly = 0.0;
  this->lastHit.wstats.fired = 0;
  this->lastHit.wstats.accHits = 0;
  this->lastHit.wstats.hitEnemy = 0;
  this->lastHit.wstats.killedEnemy = 0;
  this->lastHit.wstats.headshotEnemy = 0;
  this->lastHit.wstats.headshotEnemyKills = 0;
  this->lastHit.wstats.hitFriendly = 0;
  this->lastHit.wstats.killedFriendly = 0;
  this->lastHit.wstats.headshotFriendly = 0;
  this->lastHit.wstats.headshotFriendlyKills = 0;
  this->lastHit.wstats.actorsKilled = 0;
  this->lastHit.wstats.vehiclesKilled = 0;
  this->lastHit.wstats.breakablesDestroyed = 0;
  this->lastHit.wstats.directHit = 0;
  this->lastHit.wstats.hitObject = 0;
  this->lastHit.wstats.damageGeneral = 0;
  this->lastHit.wstats.hitVehicle = 0;
  this->lastHit.wstats.hitVehicleInAir = 0;
  this->lastHit.carryover = 0;
  this->lastHit.shotId = 0;
  this->shotId = 0;
  this->timeBucket = 0;
  idLevelStats::idLevelStats(this: &this->levelStats);
  return this;
}


// ========================================================================
// __unwind$494801
// EA  : 0x82DE5858
// RVA : 0x00DE5858
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void _unwind_494801()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$494802
// EA  : 0x82DE5880
// RVA : 0x00DE5880
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void _unwind_494802()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 12));
}


// ========================================================================
// __unwind$494803
// EA  : 0x82DE58AC
// RVA : 0x00DE58AC
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void _unwind_494803()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 3164));
}


// ========================================================================
// ?WeaponFired@idRagePlayerMetrics@@AAA?AUweaponStatsTag_t@@PBVidDecl@@@Z
// EA  : 0x82DE5938
// RVA : 0x00DE5938
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

idRagePlayerMetrics *__fastcall idRagePlayerMetrics::WeaponFired(
        idRagePlayerMetrics *this,
        idRagePlayerMetrics *result,
        idDecl *decl)
{
  int GameMs; // r3
  weaponStatsTag_t shotId; // r9
  unsigned int v8; // r7
  idRagePlayerMetrics_vtbl *v9; // r7
  idRageStat::statValue_t v11[4]; // [sp+50h] [-A0h] BYREF
  weaponQueueEntry_t v12; // [sp+60h] [-90h] BYREF

  this->__vftable = (idRagePlayerMetrics_vtbl *)(result->entityNumber << 26);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  shotId = (weaponStatsTag_t)result->shotId;
  v8 = (*(_DWORD *)&shotId << 22) & 0x3C00000 | (int)this->__vftable & 0xFC3FFFFF;
  v12.decl = decl;
  v12.wstats.decl = nullptr;
  v9 = (idRagePlayerMetrics_vtbl *)(GameMs & 0x3FFFFF | v8 & 0xFFC00000);
  v12.wstats.accHits = 0;
  v12.wstats.damageEnemy = 0.0;
  v12.wstats.damageFriendly = 0.0;
  result->shotId = *(_DWORD *)&shotId + 1;
  this->__vftable = v9;
  v12.shotId = *(_DWORD *)&shotId + 1;
  v12.wstats.hitEnemy = 0;
  v12.wstats.killedEnemy = 0;
  memset(&v12.wstats.headshotEnemy, 0, 16);
  memset(&v12.wstats.headshotFriendly, 0, 40);
  v12.carryover = 1;
  v12.wstats.fired = 1;
  v12.tag = (weaponStatsTag_t)v9;
  idList<weaponQueueEntry_t,5>::Append(this: &result->weaponQueue, obj: &v12);
  if ( (unsigned __int8)idDecl::IsType<idDeclVehicleWeapon>(this: decl) != 0 )
  {
    idRageStat::Add(this: result->stats.list + 7, owner: result, value: 1);
    if ( result->isAchievementReady )
      idRageStat::Aggregate(retstr: v11, this: result->stats.list + 7, owner: result);
  }
  else if ( (unsigned __int8)idDecl::IsType<idDeclWeapon>(this: decl) == 0
         && (unsigned __int8)idDecl::IsType<idDeclProjectile>(this: decl) == 0 )
  {
    return this;
  }
  idRageStat::Add(this: result->stats.list + 159, owner: result, value: 1);
  if ( result->isAchievementReady )
    idRageStat::Aggregate(retstr: v11, this: result->stats.list + 159, owner: result);
  return this;
}


// ========================================================================
// ?GetWeaponStats@idLevelStats@@AAAPAUweaponStats_t@@PBVidDecl@@@Z
// EA  : 0x82DE5AC8
// RVA : 0x00DE5AC8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

weaponStats_t *__fastcall idLevelStats::GetWeaponStats(idLevelStats *this, const idDecl *decl)
{
  int num; // r9
  int v4; // r10
  weaponStats_t *v5; // r8
  int v6; // r11
  weaponStats_t *result; // r3
  idStaticList<weaponStats_t,20> *p_weaponStats; // r31
  int v9; // r11
  int size; // r10
  weaponStats_t *list; // r9

  num = this->weaponStats.num;
  v4 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    if ( num == this->weaponStats.size )
    {
      if ( decl != nullptr )
        idLib::Warning(fmt: "Too many weapon stats! Cannot add %s", decl->name.str);
      else
        idLib::Warning(fmt: "Too many weapon stats! Cannot add %s", "<null>");
      return nullptr;
    }
    else
    {
      p_weaponStats = &this->weaponStats;
      idList<weaponStats_t,5>::PreAllocateWithGranularity(this: &this->weaponStats, newSize: this->weaponStats.num + 1);
      v9 = p_weaponStats->num;
      size = p_weaponStats->size;
      list = p_weaponStats->list;
      if ( v9 >= size )
      {
        result = &list[size - 1];
      }
      else
      {
        result = &list[v9];
        p_weaponStats->num = v9 + 1;
      }
      result->decl = decl;
    }
  }
  else
  {
    v5 = this->weaponStats.list;
    v6 = 0;
    while ( v5[v6].decl != decl )
    {
      ++v4;
      ++v6;
      if ( v4 >= num )
        goto LABEL_5;
    }
    return &v5[v4];
  }
  return result;
}


// ========================================================================
// ?WeaponFiredDone@idRagePlayerMetrics@@AAAXUweaponStatsTag_t@@H@Z
// EA  : 0x82DE5BD0
// RVA : 0x00DE5BD0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::WeaponFiredDone(
        idRagePlayerMetrics *this,
        weaponStatsTag_t *tag,
        int carryoverCount)
{
  weaponQueueEntry_t *QueueEntry; // r3
  weaponQueueEntry_t *v6; // r30
  int v7; // r11
  weaponStats_t *WeaponStats; // r26
  __int64 v9; // r8
  __int64 v10; // r11
  double v11; // fp31
  __int64 v12; // fp0
  idRageStat *list; // r11
  __int64 v14; // r11
  __int64 v15; // fp0
  idRageStat *v16; // r11
  bool v17; // r11
  BOOL v18; // r28
  const idDeclAmmo *v19; // r3
  const idDeclAmmo *v20; // r29
  int allocedAndFlag; // r7
  char v22; // r6
  int v23; // r10
  int v24; // r11
  char *data; // r8
  idStr *v26; // r11
  _QWORD v27[2]; // [sp+50h] [-50h] BYREF

  QueueEntry = idRagePlayerMetrics::GetQueueEntry(this, (unsigned int)tag);
  v6 = QueueEntry;
  if ( QueueEntry != nullptr )
  {
    v7 = QueueEntry->carryover + carryoverCount - 1;
    QueueEntry->carryover = v7;
    if ( v7 == 0 )
    {
      WeaponStats = idLevelStats::GetWeaponStats(this: &this->levelStats, decl: QueueEntry->decl);
      if ( WeaponStats != nullptr )
      {
        LODWORD(v10) = v6->wstats.headshotEnemy;
        v11 = 0.0;
        if ( (int)v10 > 0 )
        {
          HIDWORD(v10) = v6->wstats.hitEnemy;
          LODWORD(v9) = HIDWORD(v10);
          v6->wstats.headshotEnemy = 1;
          v27[0] = v10;
          v12 = v10;
          list = this->stats.list;
          v27[0] = v9;
          v11 = (float)((float)v12 / (float)v9);
          idRageStat::Increment(this: list + 174, owner: this);
          HIDWORD(v9) = this->isAchievementReady;
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)v27, this: this->stats.list + 174, owner: this);
        }
        LODWORD(v14) = v6->wstats.hitFriendly;
        if ( (int)v14 > 0 )
        {
          HIDWORD(v14) = v6->wstats.headshotFriendly;
          LODWORD(v9) = HIDWORD(v14);
          v6->wstats.hitFriendly = 1;
          v27[0] = v14;
          v15 = v14;
          v16 = this->stats.list;
          v27[1] = v9;
          v11 = (float)((float)v9 / (float)v15);
          idRageStat::Increment(this: v16 + 163, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)v27, this: this->stats.list + 163, owner: this);
        }
        if ( v6->wstats.hitEnemy > 0 )
        {
          v6->wstats.hitEnemy = 1;
          idRageStat::Increment(this: this->stats.list + 162, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)v27, this: this->stats.list + 162, owner: this);
        }
        if ( v6->wstats.hitObject > 0 )
        {
          v6->wstats.hitObject = 1;
          idRageStat::Increment(this: this->stats.list + 164, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)v27, this: this->stats.list + 164, owner: this);
        }
        if ( v6->wstats.headshotFriendly > 0 )
        {
          v6->wstats.headshotFriendly = 1;
          idRageStat::Increment(this: this->stats.list + 175, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)v27, this: this->stats.list + 175, owner: this);
        }
        if ( v6->wstats.hitVehicle > 0 )
        {
          v6->wstats.hitVehicle = 1;
          idRageStat::Increment(this: this->stats.list + 8, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)v27, this: this->stats.list + 8, owner: this);
        }
        if ( v6->wstats.hitVehicleInAir > 0 )
        {
          v6->wstats.hitVehicleInAir = 1;
          idRageStat::Increment(this: this->stats.list + 11, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)v27, this: this->stats.list + 11, owner: this);
        }
        v17 = v11 > 0.5 && (v6->wstats.headshotEnemyKills > 0 || v6->wstats.headshotFriendlyKills > 0);
        v18 = v17;
        if ( v17 )
          idRagePlayerMetrics::HeadShot(this);
        v19 = idDeclInfoTemplate<idDeclWeapon>::CastTo(
                this: (idDeclInfoTemplate<idDeclAmmo> *)&idDeclWeapon::resourceList,
                decl: v6->decl);
        v20 = v19;
        if ( v19 != nullptr )
        {
          allocedAndFlag = v19->weapon.allocedAndFlag;
          v22 = 0;
          v23 = 0;
          if ( allocedAndFlag > 0 )
          {
            v24 = 0;
            data = v19->weapon.data;
            while ( *((_DWORD *)data + 1) != 8 )
            {
              ++v23;
              v24 += 28;
              data = &v19->weapon.data[v24];
              if ( v23 >= allocedAndFlag )
                goto LABEL_40;
            }
            v22 = 1;
          }
LABEL_40:
          if ( v22 != 0 && v18 )
          {
            idRageStat::Increment(this: this->stats.list + 146, owner: this);
            if ( this->isAchievementReady )
              idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)v27, this: this->stats.list + 146, owner: this);
          }
          if ( v6->wstats.killedEnemy > 0 )
          {
            v26 = v20[1].engineerableItems.list;
            if ( v26 != (idStr *)-1 )
            {
              idRageStat::Increment(this: &this->stats.list[(_DWORD)v26], owner: this);
              if ( this->isAchievementReady )
                idRageStat::Aggregate(
                  retstr: (idRageStat::statValue_t *)v27,
                  this: &this->stats.list[(int)v20[1].engineerableItems.list],
                  owner: this);
            }
          }
        }
        weaponStats_t::operator+=(this: WeaponStats, stats: &v6->wstats);
        if ( v6->wstats.hitEnemy != 0
          || v6->wstats.hitFriendly != 0
          || v6->wstats.hitObject != 0
          || v6->wstats.directHit != 0
          || v6->wstats.breakablesDestroyed != 0 )
        {
          ++WeaponStats->accHits;
          idRageStat::Increment(this: this->stats.list + 167, owner: this);
          if ( this->isAchievementReady )
            idRageStat::Aggregate(retstr: (idRageStat::statValue_t *)v27, this: this->stats.list + 167, owner: this);
        }
      }
      idList<weaponQueueEntry_t,5>::RemoveIndexFast(this: &this->weaponQueue, index: v6 - this->weaponQueue.list);
    }
  }
  else
  {
    idLib::Warning(fmt: "WeaponFiredDone with no queue entry");
  }
}


// ========================================================================
// ?WeaponFiredResult_DirectHit@idRagePlayerMetrics@@AAAXPBVidDecl@@@Z
// EA  : 0x82DE6068
// RVA : 0x00DE6068
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __fastcall idRagePlayerMetrics::WeaponFiredResult_DirectHit(idRagePlayerMetrics *this, const idDecl *decl)
{
  weaponStats_t *WeaponStats; // r3
  idRageStat::statValue_t v4[4]; // [sp+50h] [-20h] BYREF

  if ( gameLocal->enableStatTracking )
  {
    WeaponStats = idLevelStats::GetWeaponStats(this: &this->levelStats, decl);
    if ( WeaponStats != nullptr )
    {
      ++WeaponStats->directHit;
      idRageStat::Increment(this: this->stats.list + 165, owner: this);
      if ( this->isAchievementReady )
        idRageStat::Aggregate(retstr: v4, this: this->stats.list + 165, owner: this);
    }
  }
}


// ========================================================================
// `dynamic initializer for 'playerMetrics_Verbose''
// EA  : 0x833859C0
// RVA : 0x013859C0
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__playerMetrics_Verbose__()
{
  idCVar::idCVar(
    this: &playerMetrics_Verbose,
    name: "playerMetrics_Verbose",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__playerMetrics_Verbose__);
}


// ========================================================================
// `dynamic initializer for 'achievements_timeUpdateInterval''
// EA  : 0x83385A18
// RVA : 0x01385A18
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__achievements_timeUpdateInterval__()
{
  idCVar::idCVar(
    this: &achievements_timeUpdateInterval,
    name: "achievements_timeUpdateInterval",
    value: "1000",
    flags: 2,
    description: "(ms) default value for how long we wait before updating the in game stat achievement",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__achievements_timeUpdateInterval__);
}

