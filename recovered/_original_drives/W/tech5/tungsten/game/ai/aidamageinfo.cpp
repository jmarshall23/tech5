
// ========================================================================
// ?Stunned@idAIDamageInfo@@QBA_NXZ
// EA  : 0x82A41308
// RVA : 0x00A41308
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

int __fastcall idAIDamageInfo::Stunned(idAIDamageInfo *this)
{
  int num; // r7
  int v2; // r9
  int i; // r11
  const idDeclDamage *damageDecl; // r10

  num = this->impulses.num;
  v2 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    damageDecl = this->impulses.list[i].damageDecl;
    if ( damageDecl != nullptr && damageDecl->stuns )
      break;
    if ( ++v2 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetAverageImpactPoint@idAIDamageInfo@@QBA?AVidVec3@@XZ
// EA  : 0x82A41358
// RVA : 0x00A41358
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

idAIDamageInfo *__fastcall idAIDamageInfo::GetAverageImpactPoint(idAIDamageInfo *this, idVec3 *result)
{
  float y; // r6
  int v3; // r10
  float x; // r8
  int v5; // r9
  double v6; // fp9
  double v7; // fp8
  double v8; // fp0
  double v9; // fp5
  double v10; // fp4
  double v11; // fp13
  double v12; // fp3
  double v13; // fp2
  double v14; // fp9
  double v15; // fp6
  double v16; // fp12
  double v17; // fp2
  double v18; // fp10
  float v19; // r9
  int v20; // r10
  int v21; // ctr
  double v22; // fp7
  double v23; // fp6
  double v24; // fp12
  double v25; // fp9

  y = result->y;
  v3 = 0;
  *(float *)&this->impulses.list = 0.0;
  *(float *)&this->impulses.num = 0.0;
  *(float *)&this->impulses.size = 0.0;
  if ( SLODWORD(y) >= 4 )
  {
    x = result->x;
    v5 = 0;
    do
    {
      v3 += 4;
      v6 = (float)(*(float *)(v5 + LODWORD(x) + 16) + *(float *)&this->impulses.list);
      v7 = (float)(*(float *)(v5 + LODWORD(x) + 20) + *(float *)&this->impulses.num);
      v8 = (float)(*(float *)(v5 + LODWORD(x) + 24) + *(float *)&this->impulses.size);
      v9 = *(float *)(v5 + LODWORD(x) + 56);
      v10 = *(float *)(v5 + LODWORD(x) + 60);
      v11 = *(float *)(v5 + LODWORD(x) + 64);
      *(float *)&this->impulses.list = *(float *)(v5 + LODWORD(x) + 16) + *(float *)&this->impulses.list;
      v12 = *(float *)(v5 + LODWORD(x) + 96);
      v13 = *(float *)(v5 + LODWORD(x) + 100);
      *(float *)&this->impulses.num = v7;
      *(float *)&this->impulses.size = v8;
      *(float *)&this->impulses.num = (float)v10 + (float)v7;
      *(float *)&this->impulses.size = (float)v11 + (float)v8;
      v14 = (float)((float)v9 + (float)v6);
      *(float *)&this->impulses.list = v14;
      v15 = *(float *)(v5 + LODWORD(x) + 104);
      v16 = *(float *)(v5 + LODWORD(x) + 136);
      v17 = (float)((float)v13 + (float)((float)v10 + (float)v7));
      *(float *)&this->impulses.num = v17;
      *(float *)&this->impulses.size = (float)v15 + (float)((float)v11 + (float)v8);
      *(float *)&this->impulses.list = (float)v12 + (float)v14;
      v18 = *(float *)(v5 + LODWORD(x) + 144);
      *(float *)&this->impulses.num = *(float *)(v5 + LODWORD(x) + 140) + (float)v17;
      v5 += 160;
      *(float *)&this->impulses.size = (float)v18 + (float)((float)v15 + (float)((float)v11 + (float)v8));
      *(float *)&this->impulses.list = (float)v16 + (float)((float)v12 + (float)v14);
    }
    while ( v3 < LODWORD(y) - 3 );
  }
  if ( v3 < SLODWORD(y) )
  {
    v19 = result->x;
    v21 = LODWORD(y) - v3;
    v20 = 40 * v3;
    do
    {
      v22 = (float)(*(float *)(v20 + LODWORD(v19) + 20) + *(float *)&this->impulses.num);
      v23 = (float)(*(float *)(v20 + LODWORD(v19) + 24) + *(float *)&this->impulses.size);
      *(float *)&this->impulses.list = *(float *)(v20 + LODWORD(v19) + 16) + *(float *)&this->impulses.list;
      v20 += 40;
      *(float *)&this->impulses.num = v22;
      *(float *)&this->impulses.size = v23;
      --v21;
    }
    while ( v21 != 0 );
  }
  v24 = *(float *)&this->impulses.num;
  v25 = *(float *)&this->impulses.size;
  *(float *)&this->impulses.list = *(float *)&this->impulses.list
                                 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y)));
  *(float *)&this->impulses.num = (float)v24 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y)));
  *(float *)&this->impulses.size = (float)v25 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y)));
  return this;
}


// ========================================================================
// ?GetAverageImpactDir@idAIDamageInfo@@QBA?AVidVec3@@XZ
// EA  : 0x82A41500
// RVA : 0x00A41500
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

idAIDamageInfo *__fastcall idAIDamageInfo::GetAverageImpactDir(idAIDamageInfo *this, idVec3 *result)
{
  float y; // r6
  int v3; // r10
  float x; // r8
  int v5; // r9
  double v6; // fp9
  double v7; // fp8
  double v8; // fp0
  double v9; // fp5
  double v10; // fp4
  double v11; // fp13
  double v12; // fp3
  double v13; // fp2
  double v14; // fp9
  double v15; // fp6
  double v16; // fp12
  double v17; // fp2
  double v18; // fp10
  float v19; // r9
  int v20; // r10
  int v21; // ctr
  double v22; // fp7
  double v23; // fp6
  double v24; // fp3
  double v25; // fp2
  double v26; // fp1
  double v29; // fp5
  double v30; // fp8
  double v31; // fp5

  y = result->y;
  v3 = 0;
  *(float *)&this->impulses.list = 0.0;
  *(float *)&this->impulses.num = 0.0;
  *(float *)&this->impulses.size = 0.0;
  if ( SLODWORD(y) >= 4 )
  {
    x = result->x;
    v5 = 0;
    do
    {
      v3 += 4;
      v6 = (float)(*(float *)(v5 + LODWORD(x) + 4) + *(float *)&this->impulses.list);
      v7 = (float)(*(float *)(v5 + LODWORD(x) + 8) + *(float *)&this->impulses.num);
      v8 = (float)(*(float *)(v5 + LODWORD(x) + 12) + *(float *)&this->impulses.size);
      v9 = *(float *)(v5 + LODWORD(x) + 44);
      v10 = *(float *)(v5 + LODWORD(x) + 48);
      v11 = *(float *)(v5 + LODWORD(x) + 52);
      *(float *)&this->impulses.list = *(float *)(v5 + LODWORD(x) + 4) + *(float *)&this->impulses.list;
      v12 = *(float *)(v5 + LODWORD(x) + 84);
      v13 = *(float *)(v5 + LODWORD(x) + 88);
      *(float *)&this->impulses.num = v7;
      *(float *)&this->impulses.size = v8;
      *(float *)&this->impulses.num = (float)v10 + (float)v7;
      *(float *)&this->impulses.size = (float)v11 + (float)v8;
      v14 = (float)((float)v9 + (float)v6);
      *(float *)&this->impulses.list = v14;
      v15 = *(float *)(v5 + LODWORD(x) + 92);
      v16 = *(float *)(v5 + LODWORD(x) + 124);
      v17 = (float)((float)v13 + (float)((float)v10 + (float)v7));
      *(float *)&this->impulses.num = v17;
      *(float *)&this->impulses.size = (float)v15 + (float)((float)v11 + (float)v8);
      *(float *)&this->impulses.list = (float)v12 + (float)v14;
      v18 = *(float *)(v5 + LODWORD(x) + 132);
      *(float *)&this->impulses.num = *(float *)(v5 + LODWORD(x) + 128) + (float)v17;
      v5 += 160;
      *(float *)&this->impulses.size = (float)v18 + (float)((float)v15 + (float)((float)v11 + (float)v8));
      *(float *)&this->impulses.list = (float)v16 + (float)((float)v12 + (float)v14);
    }
    while ( v3 < LODWORD(y) - 3 );
  }
  if ( v3 < SLODWORD(y) )
  {
    v19 = result->x;
    v21 = LODWORD(y) - v3;
    v20 = 40 * v3;
    do
    {
      v22 = (float)(*(float *)(v20 + LODWORD(v19) + 8) + *(float *)&this->impulses.num);
      v23 = (float)(*(float *)(v20 + LODWORD(v19) + 12) + *(float *)&this->impulses.size);
      *(float *)&this->impulses.list = *(float *)(v20 + LODWORD(v19) + 4) + *(float *)&this->impulses.list;
      v20 += 40;
      *(float *)&this->impulses.num = v22;
      *(float *)&this->impulses.size = v23;
      --v21;
    }
    while ( v21 != 0 );
  }
  v24 = (float)(*(float *)&this->impulses.num * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y))));
  v25 = (float)(*(float *)&this->impulses.size * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y))));
  v26 = (float)(*(float *)&this->impulses.list * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y))));
  _FP8 = (float)((float)((float)((float)v26 * (float)v26)
                       + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f6, f8, f9, f13 }
  v29 = __frsqrte(_FP6);
  v30 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                                      * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                              * (float)0.5))
                                                                              * (float)v29)
                                                                      - (float)1.5)
                                                      * (float)v29)
                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                              + (float)((float)((float)v25 * (float)v25)
                                                                      + (float)((float)v24 * (float)v24)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v29
                                                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                                                              + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                      * (float)0.5))
                                                                      * (float)v29)
                                                              - (float)1.5)
                                              * (float)v29))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v29
                                                      * (float)((float)((float)((float)v26 * (float)v26)
                                                                      + (float)((float)((float)v25 * (float)v25)
                                                                              + (float)((float)v24 * (float)v24)))
                                                              * (float)0.5))
                                              * (float)v29)
                                      - (float)1.5)
                      * (float)v29));
  v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5)
                                                                                              * (float)v29)
                                                                                      * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5)
                                                                                      * (float)v29))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v29
                                                                                              * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                      * (float)v29)
                                                                              - (float)1.5)
                                                              * (float)v29))
                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                              + (float)((float)((float)v25 * (float)v25)
                                                                      + (float)((float)v24 * (float)v24)))
                                                      * (float)0.5))
                                      * (float)v30)
                              - (float)1.5)
              * (float)v30);
  *(float *)&this->impulses.list = (float)(*(float *)&this->impulses.list
                                         * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y))))
                                 * (float)v31;
  *(float *)&this->impulses.num = (float)v24 * (float)v31;
  *(float *)&this->impulses.size = (float)v25 * (float)v31;
  return this;
}


// ========================================================================
// ?GetDeathImpulse@idAIDamageInfo@@QBAPBVidDamageImpulse@@XZ
// EA  : 0x82A41710
// RVA : 0x00A41710
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

const idDamageImpulse *__fastcall idAIDamageInfo::GetDeathImpulse(idAIDamageInfo *this)
{
  int deathImpulseIdx; // r11

  deathImpulseIdx = this->deathImpulseIdx;
  if ( deathImpulseIdx >= 0 )
    return &this->impulses.list[deathImpulseIdx];
  else
    return nullptr;
}


// ========================================================================
// ?DecayRecentDamagers@idAIDamageInfo@@QAAXXZ
// EA  : 0x82A41740
// RVA : 0x00A41740
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

void __fastcall idAIDamageInfo::DecayRecentDamagers(idAIDamageInfo *this)
{
  int v1; // r7
  idStaticList<idAIDamageInfo::recentDamager_t,4> *p_recentDamagers; // r8
  int v3; // r10
  idAIDamageInfo::recentDamager_t *v4; // r11
  int num; // r11
  idAIDamageInfo::recentDamager_t *v6; // r6
  idAIDamageInfo::recentDamager_t *v7; // r5

  v1 = 0;
  if ( this->recentDamagers.num > 0 )
  {
    p_recentDamagers = &this->recentDamagers;
    v3 = 0;
    do
    {
      v4 = &p_recentDamagers->list[v3];
      if ( v4->recentDamage >= 0.0099999998 )
      {
        v4->recentDamage = v4->recentDamage * (float)0.99000001;
      }
      else
      {
        if ( v1 >= 0 )
        {
          num = this->recentDamagers.num;
          if ( v1 < num )
          {
            this->recentDamagers.num = num - 1;
            if ( v1 != num - 1 )
            {
              v6 = &p_recentDamagers->list[num - 1];
              v7 = &p_recentDamagers->list[v3];
              v7->spawnId.value = v6->spawnId.value;
              v7->recentDamage = v6->recentDamage;
            }
          }
        }
        --v1;
        --v3;
      }
      ++v1;
      ++v3;
    }
    while ( v1 < this->recentDamagers.num );
  }
}


// ========================================================================
// ?GetRecentDamage@idAIDamageInfo@@QBAMPBVidEntity@@@Z
// EA  : 0x82A417F0
// RVA : 0x00A417F0
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

float __fastcall idAIDamageInfo::GetRecentDamage(idAIDamageInfo *this, const idEntity *ent)
{
  int num; // r8
  int v4; // r10
  idAIDamageInfo::recentDamager_t *list; // r9
  int v6; // r11
  double recentDamage; // fp1
  int v9; // [sp+50h] [-20h] BYREF

  idGameLocal::GetSpawnId(this: (idGameLocal *)&v9, result: (idSpawnId *)gameLocal, ent);
  num = this->recentDamagers.num;
  v4 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    recentDamage = 0.0;
  }
  else
  {
    list = this->recentDamagers.list;
    v6 = 0;
    while ( v9 != list[v6].spawnId.value )
    {
      ++v4;
      ++v6;
      if ( v4 >= num )
        goto LABEL_5;
    }
    recentDamage = list[v4].recentDamage;
  }
  return *((float *)&recentDamage + 1);
}


// ========================================================================
// ?EndFrame@idAIDamageInfo@@QAAXXZ
// EA  : 0x82A41890
// RVA : 0x00A41890
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

void __fastcall idAIDamageInfo::EndFrame(idAIDamageInfo *this)
{
  double v2; // fp10
  double v3; // fp10

  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->inflictor.spawnId.value = 0x1FFF;
  this->attacker.spawnId.value = 0x1FFF;
  v2 = (float)(this->recentUnscaledDamage * (float)0.94999999);
  this->recentUnscaledDamage = this->recentUnscaledDamage * (float)0.94999999;
  this->jointIndex.value = -1;
  this->deathImpulseIdx = -1;
  this->frameDamage = 0.0;
  this->frameArmorDamage = 0.0;
  if ( v2 < 0.0099999998 )
    this->recentUnscaledDamage = 0.0;
  v3 = (float)(this->recentBodyDamage * (float)0.94999999);
  this->recentBodyDamage = this->recentBodyDamage * (float)0.94999999;
  if ( v3 < 0.0099999998 )
    this->recentBodyDamage = 0.0;
  idAIDamageInfo::DecayRecentDamagers(this);
  this->shouldPain = false;
}


// ========================================================================
// ??0idAIDamageInfo@@QAA@XZ
// EA  : 0x82A41AD8
// RVA : 0x00A41AD8
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

idAIDamageInfo *__fastcall idAIDamageInfo::idAIDamageInfo(idAIDamageInfo *this)
{
  idStaticList<idDamageImpulse,8>::idStaticList<idDamageImpulse,8>(this: &this->impulses);
  this->inflictor.spawnId.value = 0x1FFF;
  this->attacker.spawnId.value = 0x1FFF;
  this->recentDamagers.num = 0;
  this->recentDamagers.list = this->recentDamagers.staticList;
  this->recentDamagers.size = 4;
  this->recentDamagers.granularity = 1;
  this->recentDamagers.memTag = 5;
  this->recentDamagers.listStatic = 1;
  this->recentDamagers.staticList[0].recentDamage = 0.0;
  this->recentDamagers.staticList[1].recentDamage = 0.0;
  this->recentDamagers.staticList[0].spawnId.value = 0x1FFF;
  this->recentDamagers.staticList[2].recentDamage = 0.0;
  this->recentDamagers.staticList[1].spawnId.value = 0x1FFF;
  this->recentDamagers.staticList[3].recentDamage = 0.0;
  this->recentDamagers.staticList[2].spawnId.value = 0x1FFF;
  this->recentDamagers.staticList[3].spawnId.value = 0x1FFF;
  this->jointIndex.value = -1;
  this->frameDamage = 0.0;
  this->frameArmorDamage = 0.0;
  this->deathImpulseIdx = -1;
  this->recentUnscaledDamage = 0.0;
  this->lastBloodSprayTime = -1;
  this->recentBodyDamage = 0.0;
  this->mostDamagedIndex = -1;
  this->shouldPain = false;
  this->injuryDamageGroup.str = &byte_8200D768;
  this->injuryGoreLevelIndex = 0;
  return this;
}


// ========================================================================
// ?AddRecentDamage@idAIDamageInfo@@QAAXPBVidEntity@@M@Z
// EA  : 0x82A41F78
// RVA : 0x00A41F78
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

void __fastcall idAIDamageInfo::AddRecentDamage(idAIDamageInfo *this, const idEntity *ent, double damage)
{
  int num; // r7
  int v6; // r5
  int v7; // r11
  idAIDamageInfo::recentDamager_t *list; // r8
  int v9; // r10
  int v10; // [sp+50h] [-30h] BYREF
  idAIDamageInfo::recentDamager_t v11; // [sp+58h] [-28h] BYREF

  idGameLocal::GetSpawnId(this: (idGameLocal *)&v10, result: (idSpawnId *)gameLocal, ent);
  num = this->recentDamagers.num;
  v6 = 0;
  v7 = 0;
  if ( num <= 0 )
  {
LABEL_7:
    v11.recentDamage = damage;
    v11.spawnId.value = v10;
    if ( num >= 4 )
      this->recentDamagers.list[v6] = v11;
    else
      idList<idAIDamageInfo::recentDamager_t,5>::Append(this: &this->recentDamagers, obj: &v11);
  }
  else
  {
    list = this->recentDamagers.list;
    v9 = 0;
    while ( v10 != list[v9].spawnId.value )
    {
      if ( list[v9].recentDamage > -1.0 )
        v6 = v7;
      ++v7;
      ++v9;
      if ( v7 >= num )
        goto LABEL_7;
    }
    list[v7].recentDamage = (float)damage + list[v7].recentDamage;
  }
}


// ========================================================================
// ?Update@idAIDamageInfo@@QAAXPAVidAI2@@PAVidEntity@@1PBVidDeclDamage@@MMMMABVidVec3@@3V?$idIndex@FW4invalidJointIndex_t@@@@_N55@Z
// EA  : 0x82A420F8
// RVA : 0x00A420F8
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.cpp
// ========================================================================

void __fastcall idAIDamageInfo::Update(
        idAIDamageInfo *this,
        idAI2 *ai,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDecl,
        double damage,
        double unscaledDamage,
        double damageScale,
        double armorDamage,
        const idVec3 *impactPoint,
        const idVec3 *impactDir,
        const idIndex<short,enum invalidJointIndex_t> *impactJoint,
        const bool killed,
        const bool armorPoppedOff,
        const bool forceInjured,
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
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        float *a34,
        int a35,
        float *a36,
        int a37,
        __int16 a38,
        int a39,
        char a40,
        int a41,
        bool impactPoint_0_3,
        int a43,
        bool impactDir_0_3)
{
  int num; // r11
  idDamageImpulse *v52; // r3
  double v53; // fp10
  double v54; // fp8
  double v55; // fp7

  num = this->impulses.num;
  if ( num >= this->impulses.size )
    v52 = &this->impulses.list[num - 1];
  else
    v52 = idList<idDamageImpulse,5>::Alloc(this: &this->impulses);
  v53 = (float)((float)armorDamage + this->frameArmorDamage);
  v54 = (float)((float)unscaledDamage + this->recentUnscaledDamage);
  v55 = (float)((float)damage + this->recentBodyDamage);
  this->frameDamage = (float)damage + this->frameDamage;
  this->frameArmorDamage = v53;
  this->recentUnscaledDamage = v54;
  this->recentBodyDamage = v55;
  v52->damageDecl = damageDecl;
  v52->impactDir.x = *a36;
  v52->impactDir.y = a36[1];
  v52->impactDir.z = a36[2];
  v52->impactPoint.x = *a34;
  v52->impactPoint.y = a34[1];
  v52->impactPoint.z = a34[2];
  v52->jointIndex.value = a38;
  v52->damage = damage;
  v52->armorPoppedOff = impactPoint_0_3;
  v52->forceInjured = impactDir_0_3;
  if ( attacker != nullptr )
    idAIDamageInfo::AddRecentDamage(this, ent: attacker, damage);
  if ( this->deathImpulseIdx >= 0 )
  {
    this->jointIndex.value = a38;
  }
  else
  {
    if ( inflictor != nullptr )
      this->inflictor.spawnId.value = (gameLocal->spawnIds.ptr[inflictor->entityNumber] << 13) | inflictor->entityNumber;
    else
      this->inflictor.spawnId.value = 0x1FFF;
    if ( attacker != nullptr )
      this->attacker.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13) | attacker->entityNumber;
    else
      this->attacker.spawnId.value = 0x1FFF;
    this->jointIndex.value = a38;
    if ( a40 != 0 )
      this->deathImpulseIdx = this->impulses.num - 1;
  }
}

