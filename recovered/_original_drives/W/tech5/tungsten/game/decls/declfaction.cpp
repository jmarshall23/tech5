
// ========================================================================
// ?AttitudeForFloat@idRelationship@@SA?AW4attitude_t@1@M@Z
// EA  : 0x82BBDD40
// RVA : 0x00BBDD40
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

idRelationship::attitude_t __fastcall idRelationship::AttitudeForFloat(double val)
{
  idRelationship::attitude_t result; // r3

  if ( val >= 6.0 )
    return ATTITUDE_IDOLIZE;
  if ( val >= 5.0 )
    return ATTITUDE_LOVE;
  if ( val >= 4.0 )
    return ATTITUDE_LIKE;
  if ( val >= 3.0 )
    return ATTITUDE_NEUTRAL;
  if ( val >= 2.0 )
    return ATTITUDE_DISLIKE;
  if ( val >= 1.0 )
    return ATTITUDE_HATE;
  result = ATTITUDE_DESPISE;
  if ( val < 0.0 )
    return ATTITUDE_NEUTRAL;
  return result;
}


// ========================================================================
// ?FloatForAttitude@idRelationship@@SAMW4attitude_t@1@@Z
// EA  : 0x82BBDDE8
// RVA : 0x00BBDDE8
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

float __fastcall idRelationship::FloatForAttitude(idRelationship::attitude_t attitude)
{
  __int64 v1; // r11
  double v2; // fp1

  LODWORD(v1) = attitude;
  v2 = (float)v1;
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?AdjustAttitude@idRelationship@@QAAXM@Z
// EA  : 0x82BBDE00
// RVA : 0x00BBDE00
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

void __fastcall idRelationship::AdjustAttitude(
        idRelationship *this,
        double val,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  double v8; // fp0
  double v9; // fp13

  if ( this->curAttitude == -1.0 )
  {
    LODWORD(a8) = this->attitude;
    this->curAttitude = (float)a8;
  }
  v8 = (float)((float)val + this->curAttitude);
  this->curAttitude = (float)val + this->curAttitude;
  v9 = 0.0;
  if ( v8 < 0.0 || (v9 = 6.0, v8 > 6.0) )
    this->curAttitude = v9;
}


// ========================================================================
// ?AttitudeToAttitudeStage@idRelationship@@SA?AW4attitudeStage_t@1@W4attitude_t@1@@Z
// EA  : 0x82BBDE68
// RVA : 0x00BBDE68
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

idRelationship::attitudeStage_t __fastcall idRelationship::AttitudeToAttitudeStage(int attitude)
{
  idRelationship::attitudeStage_t result; // r3
  bool v2; // zf

  if ( attitude <= 3 )
    return ATTITUDESTAGE_OUTSIDER;
  v2 = attitude > 4;
  result = ATTITUDESTAGE_ACCEPTED;
  if ( v2 )
    return ATTITUDESTAGE_HEROIC;
  return result;
}


// ========================================================================
// ?GetAttitudeTowards@idRelationshipList@@QBA_NPBVidDeclFaction@@AAM@Z
// EA  : 0x82BBDE90
// RVA : 0x00BBDE90
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

int __fastcall idRelationshipList::GetAttitudeTowards(
        idRelationshipList *this,
        const idDeclFaction *otherFaction,
        float *attitude)
{
  int num; // r7
  int v4; // r9
  __int64 v5; // r9
  int i; // r11
  int v7; // r10

  *attitude = 3.0;
  if ( otherFaction == nullptr )
    return 0;
  num = this->relationships.num;
  v4 = 0;
  if ( num <= 0 )
    return 0;
  HIDWORD(v5) = this->relationships.list;
  for ( i = 0; ; i += 16 )
  {
    v7 = i + HIDWORD(v5);
    if ( *(const idDeclFaction **)(i + HIDWORD(v5)) == otherFaction )
      break;
    if ( ++v4 >= num )
      return 0;
  }
  if ( *(float *)(v7 + 8) == -1.0 )
  {
    LODWORD(v5) = *(_DWORD *)(v7 + 4);
    *(float *)(v7 + 8) = (float)v5;
  }
  *attitude = *(float *)(v7 + 8);
  return 1;
}


// ========================================================================
// ?GetAttitudeTowards@idDeclFaction@@QBA_NPBV1@AAW4attitude_t@idRelationship@@@Z
// EA  : 0x82BBDF28
// RVA : 0x00BBDF28
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

int __fastcall idDeclFaction::GetAttitudeTowards(
        idDeclFaction *this,
        const idDeclFaction *otherFaction,
        idRelationship::attitude_t *attitude)
{
  idDeclFaction *parentFaction; // r3
  const idDeclFaction *v8; // r4
  float v9; // [sp+50h] [-30h] BYREF

  if ( otherFaction == nullptr )
  {
    *attitude = ATTITUDE_NEUTRAL;
    return 0;
  }
  if ( (unsigned __int8)idRelationshipList::GetAttitudeTowards(this: &this->relationships, otherFaction, attitude: &v9) != 0 )
  {
    *attitude = idRelationship::AttitudeForFloat(val: v9);
    return 1;
  }
  parentFaction = this->parentFaction;
  if ( parentFaction != nullptr && idDeclFaction::GetAttitudeTowards(this: parentFaction, otherFaction, attitude) )
    return 1;
  v8 = otherFaction->parentFaction;
  if ( v8 != nullptr && idDeclFaction::GetAttitudeTowards(this, otherFaction: v8, attitude) )
    return 1;
  *attitude = ((_cntlzw((char *)otherFaction - (char *)this) & 0x20) != 0) + 3;
  return 0;
}


// ========================================================================
// ?GetAttitudeTowards@idFaction@@QBA?AW4attitude_t@idRelationship@@PBV1@@Z
// EA  : 0x82BBDFF8
// RVA : 0x00BBDFF8
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

idRelationship::attitude_t __fastcall idFaction::GetAttitudeTowards(idFaction *this, const idFaction *otherFaction)
{
  idRelationship::attitude_t result; // r3
  float v5[2]; // [sp+50h] [-20h] BYREF

  if ( otherFaction == nullptr )
    return ATTITUDE_NEUTRAL;
  result = ai_otherFactionAttitude.valueInteger;
  if ( ai_otherFactionAttitude.valueInteger > -2 )
    return result;
  if ( (unsigned __int8)idRelationshipList::GetAttitudeTowards(
                          this: &this->relationships,
                          otherFaction: otherFaction->myFaction,
                          attitude: v5) != 0 )
    return idRelationship::AttitudeForFloat(val: v5[0]);
  if ( this->myFaction == nullptr )
    return ATTITUDE_NEUTRAL;
  idDeclFaction::GetAttitudeTowards(
    this: this->myFaction,
    otherFaction: otherFaction->myFaction,
    attitude: (idRelationship::attitude_t *)v5);
  return LODWORD(v5[0]);
}


// ========================================================================
// ?SetDeclFaction@idFaction@@QAAXPBVidDeclFaction@@_N@Z
// EA  : 0x82BBE098
// RVA : 0x00BBE098
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

void __fastcall idFaction::SetDeclFaction(idFaction *this, const idDeclFaction *faction, bool clearRelationships)
{
  this->myFaction = faction;
  if ( clearRelationships )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->relationships);
}


// ========================================================================
// ??0idRelationship@@QAA@XZ
// EA  : 0x82BBE0B8
// RVA : 0x00BBE0B8
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

idRelationship *__fastcall idRelationship::idRelationship(idRelationship *this)
{
  this->otherFaction = nullptr;
  this->attitude = ATTITUDE_UNKNOWN;
  this->curAttitude = -1.0;
  this->otherEntity.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ?GetRelationship@idRelationshipList@@ABAPBVidRelationship@@PBVidEntity@@@Z
// EA  : 0x82BBE0E0
// RVA : 0x00BBE0E0
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

const idRelationship *__fastcall idRelationshipList::GetRelationship(
        idRelationshipList *this,
        const idEntity *otherEnt)
{
  int v4; // r27
  int v5; // r30
  idGameLocal *v6; // r10
  idRelationship *v7; // r31
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3

  if ( otherEnt == nullptr )
    return nullptr;
  v4 = this->relationships.num - 1;
  if ( v4 < 0 )
    return nullptr;
  v5 = v4;
  v6 = gameLocal;
  while ( 1 )
  {
    v7 = &this->relationships.list[v5];
    value = v7->otherEntity.spawnId.value;
    if ( v6->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v9 = v6->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
      v6 = gameLocal;
    }
    else
    {
      v10 = nullptr;
    }
    if ( v10 == otherEnt )
      break;
    --v4;
    --v5;
    if ( v4 < 0 )
      return nullptr;
  }
  return v7;
}


// ========================================================================
// ?GetAttitudeTowards@idRelationshipList@@QBA_NPBVidEntity@@AAM@Z
// EA  : 0x82BBE190
// RVA : 0x00BBE190
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

const idRelationship *__fastcall idRelationshipList::GetAttitudeTowards(
        idRelationshipList *this,
        const idEntity *otherEnt,
        float *attitude)
{
  __int64 v4; // r10
  const idRelationship *result; // r3

  *attitude = 3.0;
  result = idRelationshipList::GetRelationship(this, otherEnt);
  if ( result != nullptr )
  {
    if ( result->curAttitude == -1.0 )
    {
      LODWORD(v4) = result->attitude;
      result->curAttitude = (float)v4;
    }
    *attitude = result->curAttitude;
    return (const idRelationship *)1;
  }
  return result;
}


// ========================================================================
// ?CullEntityRelationships@idRelationshipList@@QAAXXZ
// EA  : 0x82BBE220
// RVA : 0x00BBE220
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

void __fastcall idRelationshipList::CullEntityRelationships(idRelationshipList *this)
{
  int v2; // r29
  int v3; // r30
  idRelationship *v4; // r11
  int value; // r10
  idEntity *v6; // r3
  idEntity *v7; // r3
  int num; // r11
  int v9; // r11
  idRelationship *v10; // r11
  idRelationship *v11; // r10

  v2 = this->relationships.num - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      v4 = &this->relationships.list[v3];
      if ( v4->otherFaction == nullptr )
      {
        value = v4->otherEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
          || (v6 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
          || (v7 = idEntity::CastTo(c: v6)) == nullptr
          || v7->IsDead(this: v7) )
        {
          num = this->relationships.num;
          if ( v2 < num )
          {
            v9 = num - 1;
            this->relationships.num = v9;
            if ( v2 != v9 )
            {
              v10 = &this->relationships.list[v9];
              v11 = &this->relationships.list[v3];
              v11->otherFaction = v10->otherFaction;
              v11->attitude = v10->attitude;
              v11->curAttitude = v10->curAttitude;
              v11->otherEntity.spawnId.value = v10->otherEntity.spawnId.value;
            }
          }
        }
      }
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
}


// ========================================================================
// ?GetAttitudeTowards@idFaction@@QBA?AW4attitude_t@idRelationship@@PBVidEntity@@@Z
// EA  : 0x82BBE328
// RVA : 0x00BBE328
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

idRelationship::attitude_t __fastcall idFaction::GetAttitudeTowards(idFaction *this, idPlayer *otherEnt)
{
  const idFaction *v5; // r3
  float v6; // [sp+50h] [-30h] BYREF

  if ( otherEnt == nullptr )
    return ATTITUDE_NEUTRAL;
  if ( ai_attitude.valueInteger > -2 && idPlayer::CastTo(c: otherEnt) != nullptr )
    return ai_attitude.valueInteger;
  if ( (unsigned __int8)idRelationshipList::GetAttitudeTowards(this: &this->relationships, otherEnt, attitude: &v6) != 0 )
    return idRelationship::AttitudeForFloat(val: v6);
  v5 = otherEnt->GetFaction_2(this: otherEnt);
  return idFaction::GetAttitudeTowards(this, otherFaction: v5);
}


// ========================================================================
// ?GetAttitudeTowards@idFaction@@QBA?AW4attitude_t@idRelationship@@PBVidPresentable@@@Z
// EA  : 0x82BBE3D8
// RVA : 0x00BBE3D8
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

idRelationship::attitude_t __fastcall idFaction::GetAttitudeTowards(idFaction *this, const idPresentable *otherPres)
{
  if ( otherPres != nullptr )
    return idFaction::GetAttitudeTowards(this, otherEnt: (idPlayer *)otherPres->entity);
  else
    return ATTITUDE_NEUTRAL;
}


// ========================================================================
// ?GetAttitudeTowards@idFaction@@QBA?AW4attitude_t@idRelationship@@VidSpawnId@@@Z
// EA  : 0x82BBE3F0
// RVA : 0x00BBE3F0
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

idRelationship::attitude_t __fastcall idFaction::GetAttitudeTowards(idFaction *this, const idSpawnId *id)
{
  idPlayer *v3; // r3

  v3 = (idPlayer *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: id);
  return idFaction::GetAttitudeTowards(this, otherEnt: v3);
}


// ========================================================================
// ?CullEntityRelationships@idFaction@@QAAXXZ
// EA  : 0x82BBE440
// RVA : 0x00BBE440
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

void __fastcall idFaction::CullEntityRelationships(idFaction *this)
{
  idRelationshipList::CullEntityRelationships(this: &this->relationships);
}


// ========================================================================
// ??0idFaction@@QAA@XZ
// EA  : 0x82BBE448
// RVA : 0x00BBE448
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

idFaction *__fastcall idFaction::idFaction(idFaction *this)
{
  this->myFaction = nullptr;
  this->relationships.relationships.list = nullptr;
  this->relationships.relationships.granularity = 0;
  this->relationships.relationships.memTag = 5;
  this->relationships.relationships.listStatic = 0;
  this->relationships.relationships.size = 0;
  this->relationships.relationships.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->relationships);
  return this;
}


// ========================================================================
// ?AdjustAttitudeTowards@idRelationshipList@@QAAXPBVidDeclFaction@@PBVidEntity@@M@Z
// EA  : 0x82BBE6A8
// RVA : 0x00BBE6A8
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

void __fastcall idRelationshipList::AdjustAttitudeTowards(
        idRelationshipList *this,
        const idDeclFaction *myFaction,
        const idEntity *otherEnt,
        double adjust)
{
  idRelationship *Relationship; // r31
  __int64 v9; // r10
  int v10; // r8
  __int64 v11; // r7
  int v12; // r5
  int v13; // r4
  const idFaction *v14; // r3
  idRelationship::attitude_t v15[2]; // [sp+50h] [-40h] BYREF
  __int64 v16; // [sp+58h] [-38h]

  if ( otherEnt != nullptr )
  {
    Relationship = (idRelationship *)idRelationshipList::GetRelationship(this, otherEnt);
    if ( Relationship == nullptr )
    {
      Relationship = idList<idRelationship,5>::Alloc(this: &this->relationships);
      Relationship->otherEntity.spawnId.value = (gameLocal->spawnIds.ptr[otherEnt->entityNumber] << 13)
                                              | otherEnt->entityNumber;
      Relationship->otherFaction = nullptr;
      v14 = otherEnt->GetFaction_2(this: otherEnt);
      idDeclFaction::GetAttitudeTowards(this: myFaction, otherFaction: v14->myFaction, attitude: v15);
      v10 = v15[0];
      SLODWORD(v11) = v15[0];
      v16 = v11;
      Relationship->curAttitude = (float)v11;
    }
    idRelationship::AdjustAttitude(
      this: Relationship,
      val: adjust,
      a3: v13,
      a4: v12,
      a5: SHIDWORD(v11),
      a6: v11,
      a7: v10,
      a8: v9);
  }
}


// ========================================================================
// ?AdjustAttitudeTowards@idFaction@@QAAXPBVidEntity@@M@Z
// EA  : 0x82BBE778
// RVA : 0x00BBE778
// PDB : w:\tech5\tungsten\game\decls\declfaction.cpp
// ========================================================================

void __fastcall idFaction::AdjustAttitudeTowards(idFaction *this, const idEntity *otherEnt, double adjust)
{
  idRelationshipList::AdjustAttitudeTowards(this: &this->relationships, myFaction: this->myFaction, otherEnt, adjust);
}

