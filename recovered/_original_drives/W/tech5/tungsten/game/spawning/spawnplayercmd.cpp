
// ========================================================================
// ?GetActorSize@idSpawnPlayerCmd@@UBA?BVidVec3@@ABVCommand@idSpawnManager@@@Z
// EA  : 0x82EA9920
// RVA : 0x00EA9920
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

idSpawnPlayerCmd *__fastcall idSpawnPlayerCmd::GetActorSize(
        idSpawnPlayerCmd *this,
        const idVec3 *result,
        const idSpawnManager::Command *command)
{
  idPlayer *v4; // r3
  idEntity *v5; // r30
  idPhysics *Physics; // r3
  float *v7; // r3
  double v8; // fp8
  double v9; // fp6
  float y; // r8
  int z_low; // r7

  v4 = idPlayer::CastTo(c: (idPlayer *)gameLocal->entities.ptr[*(_DWORD *)(24 * command->dataIndex + LODWORD(result[1].z))]);
  v5 = v4;
  if ( v4 != nullptr && idEntity::GetPhysics(this: v4) != nullptr )
  {
    Physics = idEntity::GetPhysics(this: v5);
    v7 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
    v8 = (float)(v7[4] - v7[1]);
    v9 = (float)(v7[5] - v7[2]);
    *(float *)&this->__vftable = v7[3] - *v7;
    *(float *)&this->freeDataIndices.list = v8;
    *(float *)&this->freeDataIndices.num = v9;
  }
  else
  {
    y = vec3_origin.y;
    z_low = LODWORD(vec3_origin.z);
    this->__vftable = (idSpawnPlayerCmd_vtbl *)LODWORD(vec3_origin.x);
    *(float *)&this->freeDataIndices.list = y;
    this->freeDataIndices.num = z_low;
  }
  return this;
}


// ========================================================================
// ?IsNearHostileGrenade@idSpawnPlayerCmd@@ABA_NABVidVec3@@@Z
// EA  : 0x82EA9A10
// RVA : 0x00EA9A10
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

int __fastcall idSpawnPlayerCmd::IsNearHostileGrenade(idSpawnPlayerCmd *this, const idVec3 *position)
{
  int num; // r5
  int v3; // r7
  idVec3 *list; // r8
  int v5; // r10
  int i; // r11
  double v7; // fp10
  double v8; // fp7
  double v9; // fp5

  num = this->hostileGrenadeLocations.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  list = this->hostileGrenadeLocations.list;
  v5 = 0;
  for ( i = 0; ; ++i )
  {
    v7 = (float)(position->x - list[i].x);
    v8 = (float)(position->y - list[i].y);
    v9 = (float)(position->z - list[i].z);
    if ( (float)((float)((float)v9 * (float)v9)
               + (float)((float)((float)v7 * (float)v7) + (float)((float)v8 * (float)v8))) <= (double)this->hostileGrenadesDangerRadiusSq.list[v5] )
      break;
    ++v3;
    ++v5;
    if ( v3 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?Complete@idSpawnPlayerCmd@@UAAPAVidEntity@@ABVCommand@idSpawnManager@@ABVContext@4@ABVidSpawnLocation@@@Z
// EA  : 0x82EA9C18
// RVA : 0x00EA9C18
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

idPlayer *__fastcall idSpawnPlayerCmd::Complete(
        idSpawnPlayerCmd *this,
        const idSpawnManager::Command *command,
        const idSpawnManager::Context *context,
        const idSpawnLocation *location)
{
  idSpawnPlayerCmdData *v7; // r31
  idPlayer *v8; // r3
  BOOL teleport; // r6
  idPlayer *v10; // r31
  int dataIndex; // [sp+50h] [-30h] BYREF

  v7 = &this->dataArray.list[command->dataIndex];
  v8 = idPlayer::CastTo(c: (idPlayer *)gameLocal->entities.ptr[v7->playerIndex]);
  teleport = v7->teleport;
  v10 = v8;
  if ( teleport && !v8->IsDead(this: v8) )
  {
    v10->Teleport(this: v10, a2: &location->pos, a3: &location->facing);
    v10->Show(this: v10);
  }
  dataIndex = command->dataIndex;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->freeDataIndices,
    obj: (encounterGroupRole_t *)&dataIndex);
  return v10;
}


// ========================================================================
// ?Fail@idSpawnPlayerCmd@@UAAXABVCommand@idSpawnManager@@ABVContext@3@@Z
// EA  : 0x82EA9CE0
// RVA : 0x00EA9CE0
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __fastcall idSpawnPlayerCmd::Fail(
        idSpawnPlayerCmd *this,
        const idSpawnManager::Command *command,
        const idSpawnManager::Context *context)
{
  encounterGroupRole_t v5[2]; // [sp+50h] [-20h] BYREF

  idLib::Warning(fmt: "Player spawn failed!", command, context);
  v5[0] = (encounterGroupRole_t)command->dataIndex;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->freeDataIndices, obj: v5);
}


// ========================================================================
// ?UpdateGrenadeLocations@idSpawnPlayerCmd@@AAAXABW4gameTeam_t@@@Z
// EA  : 0x82EA9D38
// RVA : 0x00EA9D38
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __fastcall idSpawnPlayerCmd::UpdateGrenadeLocations(idSpawnPlayerCmd *this, const gameTeam_t *userTeam)
{
  idList<idVec3,5> *p_hostileGrenadeLocations; // r29
  idList<float,5> *p_hostileGrenadesDangerRadiusSq; // r28
  int i; // r30
  idProjectile_Grenade *v6; // r3
  idProjectile_Grenade *v7; // r3
  idProjectile_Grenade *v8; // r31
  idPhysics *Physics; // r3
  const idVec3 *v10; // r3
  float v11; // [sp+50h] [-40h] BYREF

  p_hostileGrenadeLocations = &this->hostileGrenadeLocations;
  p_hostileGrenadesDangerRadiusSq = &this->hostileGrenadesDangerRadiusSq;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hostileGrenadeLocations);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hostileGrenadesDangerRadiusSq);
  for ( i = 0; i < 0x2000; ++i )
  {
    v6 = (idProjectile_Grenade *)gameLocal->GetEntity(this: gameLocal, a2: i);
    v7 = idProjectile_Grenade::CastTo(c: v6);
    v8 = v7;
    if ( v7 != nullptr && v7->projectileDecl->splashDamageDecl != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v7);
      v10 = Physics->GetOrigin(this: Physics, a2: 0);
      idList<idAngles,5>::Append(this: p_hostileGrenadeLocations, obj: v10);
      v11 = v8->projectileDecl->splashDamageDecl->radius * v8->projectileDecl->splashDamageDecl->radius;
      idList<float,13>::Append(this: (idList<float,13> *)p_hostileGrenadesDangerRadiusSq, obj: &v11);
    }
  }
}


// ========================================================================
// ?GenerateLocations@idSpawnPlayerCmd@@UAAXABVCommand@idSpawnManager@@ABVContext@3@AAV?$idList@VidSpawnLocation@@$04@@@Z
// EA  : 0x82EAA048
// RVA : 0x00EAA048
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __fastcall idSpawnPlayerCmd::GenerateLocations(
        idSpawnPlayerCmd *this,
        const idSpawnManager::Command *command,
        const idSpawnManager::Context *context,
        idList<idSpawnLocation,5> *locationsOut)
{
  int dataIndex; // r11
  __int64 v6; // r10
  __int64 v8; // r8
  int v9; // r31
  int v10; // r11
  bool v11; // r6
  idPlayerStart *SpawnSpot; // r3
  double z; // fp13
  double y; // fp11
  idGameplayFilterTarget v15[2]; // [sp+50h] [-80h] BYREF
  idVec3 v16; // [sp+58h] [-78h]
  idMat3 v17; // [sp+68h] [-68h] BYREF
  idVec3 v18; // [sp+8Ch] [-44h]
  float v19; // [sp+98h] [-38h]
  int v20; // [sp+9Ch] [-34h]
  int v21; // [sp+A0h] [-30h]
  float v22; // [sp+A4h] [-2Ch]

  dataIndex = command->dataIndex;
  LODWORD(v8) = 0x82000000;
  HIDWORD(v6) = this->dataArray.list;
  LODWORD(v6) = 2 * dataIndex;
  HIDWORD(v8) = 3 * dataIndex;
  v9 = 24 * dataIndex + HIDWORD(v6);
  v10 = *(_DWORD *)(v9 + 12);
  if ( v10 != 0 && *(int *)(v10 + 4) > 0 )
  {
    v15[0].bits = 0;
    idGameplayFilterTarget::SetFlag(this: v15, index: 0, flagValue: true);
    idSpawnNodeGroup::GetValidSpawnLocations(
      this: *(idSpawnNodeGroup **)(v9 + 12),
      userType: v15,
      team: (const gameTeam_t *)(v9 + 4),
      userHalfSize: 16.0,
      onlyInitial: v11,
      spawnLocations: (idList<idSpawnLocation,5> *)*(unsigned __int8 *)(v9 + 17),
      a7: (int)locationsOut);
  }
  else
  {
    SpawnSpot = idGameLocal::FindSpawnSpot(
                  this: gameLocal,
                  spawnspot: gameLocal->gameSpawnInfo.spawnSpot.data,
                  playerNum: *(_DWORD *)v9,
                  a4: (int)locationsOut,
                  a5: v8,
                  a6: v6);
    if ( SpawnSpot != nullptr )
    {
      z = SpawnSpot->spawnPosition.z;
      y = SpawnSpot->spawnPosition.y;
      v16.x = SpawnSpot->spawnPosition.x;
      v16.y = y;
      v16.z = (float)z + (float)5.0;
      idMat3::ToAngles(this: &v17, result: (idAngles *)&SpawnSpot->spawnOrientation);
      v20 = 0;
      v22 = 0.0;
      v21 = 0;
      v19 = 1.0;
      v17.mat[2] = v16;
      v18 = v17.mat[0];
      idList<idSpawnLocation,5>::Append(this: locationsOut, obj: (const idSpawnLocation *)&v17.mat[2]);
    }
  }
  idSpawnPlayerCmd::UpdateGrenadeLocations(this, userTeam: (const gameTeam_t *)(v9 + 4));
  this->raycastOffset.x = 0.0;
  this->raycastOffset.y = 0.0;
  this->raycastOffset.z = 90.0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deferredVisibilityQueries);
}


// ========================================================================
// ?EvaluateCurrentLocation@idSpawnPlayerCmd@@AAAMABVCommand@idSpawnManager@@AAVContext@3@@Z
// EA  : 0x82EAA1B0
// RVA : 0x00EAA1B0
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

float __fastcall idSpawnPlayerCmd::EvaluateCurrentLocation(
        idSpawnPlayerCmd *this,
        const idSpawnManager::Command *command,
        idSpawnManager::Context *context)
{
  idSpawnLocation *list; // r7
  idSpawnPlayerCmdData *v6; // r15
  int currentLocationIndex; // r11
  const idVec3 *p_pos; // r16
  int v9; // r8
  idPlayer *v10; // r3
  idPlayer *v11; // r14
  int value; // r10
  idEntity *v13; // r3
  idEntity *v14; // r3
  double v15; // fp27
  idPhysics *Physics; // r3
  float *v17; // r3
  double v18; // fp9
  double v19; // fp5
  double v20; // fp0
  double v21; // fp2
  double v23; // fp13
  double v25; // fp10
  double v26; // fp6
  double v27; // fp5
  double v28; // fp13
  idVec3 *p_lastSpawnPos; // r11
  double v32; // fp11
  double v33; // fp8
  double v34; // fp2
  double v36; // fp12
  double v38; // fp10
  double v39; // fp12
  double v40; // fp0
  idLinkList<idActor> *next; // r11
  idActor *owner; // r30
  idPlayer *v47; // r3
  idPhysics *v48; // r3
  float *v49; // r3
  double v50; // fp9
  double v51; // fp7
  double v52; // fp2
  double v54; // fp13
  double v56; // fp11
  double v57; // fp9
  double v58; // fp30
  idGameChallenge *ChallengeEntity; // r3
  const idDeclFaction *FactionFromTeam; // r31
  idDeclFaction **v61; // r3
  char v62; // r23
  int v63; // r3
  double v65; // fp27
  double v66; // fp14
  double x; // fp13
  float v68; // r6
  double y; // fp12
  float z; // r5
  double v71; // fp29
  double v72; // fp28
  double v73; // fp5
  double v74; // fp26
  double v75; // fp4
  double v77; // fp13
  double v79; // fp11
  double v80; // fp30
  double v81; // fp25
  double v82; // fp0
  double v83; // fp27
  idPlayer *v84; // r3
  idPlayer *v85; // r31
  double v87; // fp30
  int v88; // r31
  idPhysics *v89; // r3
  double valueFloat; // fp14
  float *v91; // r3
  double v92; // fp7
  double v93; // fp5
  double v94; // fp4
  double v95; // fp30
  double v98; // fp0
  double v99; // fp9
  double v100; // fp5
  double v101; // fp10
  double v102; // fp0
  double v103; // fp6
  double v104; // fp5
  double v105; // fp25
  double v106; // fp27
  double v107; // fp14
  int v108; // r11
  idLinkList<idActor> *v109; // r11
  double v110; // fp13
  double v111; // fp13
  double v112; // fp0
  double v113; // fp0
  double v114; // fp0
  double v115; // fp1
  int v117; // [sp+8h] [-288h]
  int v118; // [sp+8h] [-288h]
  int v119; // [sp+8h] [-288h]
  int v120; // [sp+8h] [-288h]
  bool v121; // [sp+Fh] [-281h]
  bool v122; // [sp+Fh] [-281h]
  bool v123; // [sp+Fh] [-281h]
  bool v124; // [sp+Fh] [-281h]
  const char *v125; // [sp+10h] [-280h]
  const char *v126; // [sp+10h] [-280h]
  const char *v127; // [sp+10h] [-280h]
  const char *v128; // [sp+10h] [-280h]
  int v129; // [sp+14h] [-27Ch]
  int v130; // [sp+14h] [-27Ch]
  int v131; // [sp+14h] [-27Ch]
  int v132; // [sp+14h] [-27Ch]
  int v133; // [sp+18h] [-278h]
  int v134; // [sp+18h] [-278h]
  int v135; // [sp+18h] [-278h]
  int v136; // [sp+18h] [-278h]
  int v137; // [sp+1Ch] [-274h]
  int v138; // [sp+1Ch] [-274h]
  int v139; // [sp+1Ch] [-274h]
  int v140; // [sp+1Ch] [-274h]
  int v141; // [sp+20h] [-270h]
  int v142; // [sp+20h] [-270h]
  int v143; // [sp+20h] [-270h]
  int v144; // [sp+20h] [-270h]
  int v145; // [sp+24h] [-26Ch]
  int v146; // [sp+24h] [-26Ch]
  int v147; // [sp+24h] [-26Ch]
  int v148; // [sp+24h] [-26Ch]
  int v149; // [sp+28h] [-268h]
  int v150; // [sp+28h] [-268h]
  int v151; // [sp+28h] [-268h]
  int v152; // [sp+28h] [-268h]
  int v153; // [sp+2Ch] [-264h]
  int v154; // [sp+2Ch] [-264h]
  int v155; // [sp+2Ch] [-264h]
  int v156; // [sp+2Ch] [-264h]
  int v157; // [sp+30h] [-260h]
  int v158; // [sp+30h] [-260h]
  int v159; // [sp+30h] [-260h]
  int v160; // [sp+30h] [-260h]
  int v161; // [sp+34h] [-25Ch]
  int v162; // [sp+34h] [-25Ch]
  int v163; // [sp+34h] [-25Ch]
  int v164; // [sp+34h] [-25Ch]
  int v165; // [sp+38h] [-258h]
  int v166; // [sp+38h] [-258h]
  int v167; // [sp+38h] [-258h]
  int v168; // [sp+38h] [-258h]
  int v169; // [sp+3Ch] [-254h]
  int v170; // [sp+3Ch] [-254h]
  int v171; // [sp+3Ch] [-254h]
  int v172; // [sp+3Ch] [-254h]
  int v173; // [sp+40h] [-250h]
  int v174; // [sp+40h] [-250h]
  int v175; // [sp+40h] [-250h]
  int v176; // [sp+40h] [-250h]
  int v177; // [sp+44h] [-24Ch]
  int v178; // [sp+44h] [-24Ch]
  int v179; // [sp+44h] [-24Ch]
  int v180; // [sp+44h] [-24Ch]
  int v181; // [sp+48h] [-248h]
  int v182; // [sp+48h] [-248h]
  int v183; // [sp+48h] [-248h]
  int v184; // [sp+48h] [-248h]
  int v185; // [sp+4Ch] [-244h]
  int v186; // [sp+4Ch] [-244h]
  int v187; // [sp+4Ch] [-244h]
  int v188; // [sp+4Ch] [-244h]
  int v189; // [sp+50h] [-240h]
  int v190; // [sp+50h] [-240h]
  int v191; // [sp+50h] [-240h]
  int v192; // [sp+50h] [-240h]
  int v193; // [sp+58h] [-238h]
  int v194; // [sp+58h] [-238h]
  int v195; // [sp+58h] [-238h]
  int v196; // [sp+58h] [-238h]
  int v197; // [sp+60h] [-230h]
  int v198; // [sp+60h] [-230h]
  int v199; // [sp+60h] [-230h]
  int v200; // [sp+60h] [-230h]
  idVec3 v201; // [sp+70h] [-220h] BYREF
  idVec3 v202; // [sp+80h] [-210h] BYREF
  idVec3 v203; // [sp+90h] [-200h] BYREF
  idVec3 v204; // [sp+A0h] [-1F0h]
  float v205; // [sp+ACh] [-1E4h]
  float v206; // [sp+B0h] [-1E0h]
  idSpawnPlayerCmd::deferredVisibilityQuery_t v207; // [sp+C0h] [-1D0h] BYREF
  float v208; // [sp+D0h] [-1C0h]
  float v209; // [sp+D4h] [-1BCh]
  int v210; // [sp+D8h] [-1B8h] BYREF
  float v211; // [sp+DCh] [-1B4h]
  idSpawnLocation *v212; // [sp+E0h] [-1B0h]
  idSpawnPlayerCmdData *v213; // [sp+E4h] [-1ACh]
  const char *v214; // [sp+E8h] [-1A8h]
  float v215; // [sp+ECh] [-1A4h]
  idPlayer *v216; // [sp+F0h] [-1A0h]
  idAngles v217; // [sp+F8h] [-198h] BYREF
  char v218; // [sp+108h] [-188h] BYREF
  char v219; // [sp+110h] [-180h] BYREF
  char v220; // [sp+118h] [-178h] BYREF
  char v221; // [sp+120h] [-170h] BYREF
  char v222; // [sp+128h] [-168h] BYREF
  float v223[46]; // [sp+140h] [-150h] BYREF

  list = context->spawnLocations.list;
  v6 = &this->dataArray.list[command->dataIndex];
  currentLocationIndex = context->currentLocationIndex;
  p_pos = &context->spawnLocations.list[currentLocationIndex].pos;
  v213 = v6;
  v9 = v6->playerIndex + 21563;
  v212 = &list[currentLocationIndex];
  v10 = idPlayer::CastTo(c: *((idPlayer **)&gameLocal->__vftable + v9));
  v11 = v10;
  v216 = v10;
  if ( v10 != nullptr
    && (value = v10->killer.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v14 = idEntity::CastTo(c: v13);
  }
  else
  {
    v14 = nullptr;
  }
  v15 = 0.1;
  v208 = 1.0;
  v215 = 0.1;
  if ( v14 != nullptr )
  {
    Physics = idEntity::GetPhysics(this: v14);
    v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v18 = (float)(v17[2] - p_pos->z);
    v19 = (float)(v17[1] - p_pos->y);
    v20 = idMath::FLT_SMALLEST_NON_DENORMAL;
    v21 = (float)((float)((float)v19 * (float)v19)
                + (float)((float)((float)(*v17 - p_pos->x) * (float)(*v17 - p_pos->x)) + (float)((float)v18 * (float)v18)));
    _FP1 = (float)((float)((float)((float)v19 * (float)v19)
                         + (float)((float)((float)(*v17 - p_pos->x) * (float)(*v17 - p_pos->x))
                                 + (float)((float)v18 * (float)v18)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v23 = (float)((float)((float)((float)v19 * (float)v19)
                        + (float)((float)((float)(*v17 - p_pos->x) * (float)(*v17 - p_pos->x))
                                + (float)((float)v18 * (float)v18)))
                * (float)0.5);
    __asm { fsel      f11, f1, f2, f0 }
    v25 = __frsqrte(_FP11);
    v26 = (float)((float)-(float)((float)((float)((float)v25
                                                * (float)((float)((float)((float)v19 * (float)v19)
                                                                + (float)((float)((float)(*v17 - p_pos->x)
                                                                                * (float)(*v17 - p_pos->x))
                                                                        + (float)((float)v18 * (float)v18)))
                                                        * (float)0.5))
                                        * (float)v25)
                                - (float)1.5)
                * (float)v25);
    v27 = (float)((float)((float)-(float)((float)((float)((float)v25
                                                        * (float)((float)((float)((float)v19 * (float)v19)
                                                                        + (float)((float)((float)(*v17 - p_pos->x)
                                                                                        * (float)(*v17 - p_pos->x))
                                                                                + (float)((float)v18 * (float)v18)))
                                                                * (float)0.5))
                                                * (float)v25)
                                        - (float)1.5)
                        * (float)v25)
                * (float)((float)((float)((float)v19 * (float)v19)
                                + (float)((float)((float)(*v17 - p_pos->x) * (float)(*v17 - p_pos->x))
                                        + (float)((float)v18 * (float)v18)))
                        * (float)0.5));
    v28 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v27 * (float)v26)
                                                                                - (float)1.5)
                                                                * (float)v26)
                                                        * (float)v23)
                                                * (float)((float)-(float)((float)((float)v27 * (float)v26) - (float)1.5)
                                                        * (float)v26))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v27 * (float)v26) - (float)1.5) * (float)v26))
                * (float)v21);
    if ( v28 >= mp_minPlayerSpawnKillerDistance.valueFloat )
    {
      if ( v28 < mp_maxPlayerSpawnKillerDistance.valueFloat )
      {
        _FP12 = (float)((float)((float)v28 / mp_maxPlayerSpawnKillerDistance.valueFloat) - (float)0.1);
        __asm { fsel      f11, f12, f13, f27 }
        v208 = _FP11;
      }
    }
    else
    {
      v208 = 0.1;
    }
  }
  else
  {
    v20 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( v11 != nullptr )
    p_lastSpawnPos = &v11->lastSpawnPos;
  else
    p_lastSpawnPos = &vec3_origin;
  v32 = (float)(p_lastSpawnPos->y - p_pos->y);
  v33 = (float)(p_lastSpawnPos->z - p_pos->z);
  v34 = (float)((float)((float)(p_lastSpawnPos->x - p_pos->x) * (float)(p_lastSpawnPos->x - p_pos->x))
              + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)));
  _FP1 = (float)((float)((float)((float)(p_lastSpawnPos->x - p_pos->x) * (float)(p_lastSpawnPos->x - p_pos->x))
                       + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
               - (float)v20);
  v36 = (float)((float)((float)((float)(p_lastSpawnPos->x - p_pos->x) * (float)(p_lastSpawnPos->x - p_pos->x))
                      + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
              * (float)0.5);
  v206 = 1.0;
  __asm { fsel      f11, f1, f2, f0 }
  v38 = __frsqrte(_FP11);
  v39 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                              * (float)v38)
                                                                                      * (float)v36)
                                                                              * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                      * (float)v38))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                      * (float)v38)
                                                                              - (float)1.5)
                                                              * (float)v38))
                                              * (float)v36)
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                      * (float)v38)
                                                                              * (float)v36)
                                                                      * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                                                              - (float)1.5)
                                                                              * (float)v38))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                              * (float)v38)
                                                                      - (float)1.5)
                                                      * (float)v38)))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                      * (float)v38)
                                                                              - (float)1.5)
                                                              * (float)v38)
                                                      * (float)v36)
                                              * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                              * (float)v38)
                                                                      - (float)1.5)
                                                      * (float)v38))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                              * (float)v38)));
  v40 = (float)((float)v39 * (float)v34);
  if ( v40 >= mp_minPlayerSpawnLastDistance.valueFloat )
  {
    if ( v40 < mp_maxPlayerSpawnLastDistance.valueFloat )
    {
      _FP13 = (float)((float)((float)((float)v39 * (float)v34) / mp_maxPlayerSpawnLastDistance.valueFloat) - (float)0.25);
      __asm { fsel      f12, f13, f0, f18 }
      v206 = _FP12;
    }
  }
  else
  {
    v206 = 0.25;
  }
  v209 = 1.0;
  if ( (unsigned __int8)idSpawnPlayerCmd::IsNearHostileGrenade(this, position: p_pos) != 0 )
    v209 = 0.0099999998;
  v205 = 999999.0;
  _FP29 = 999999.0;
  v211 = 999999.0;
  _FP28 = 999999.0;
  next = gameLocal->actorEntities.next;
  if ( next != nullptr && next != gameLocal->actorEntities.head )
  {
    owner = next->owner;
    if ( owner != nullptr )
    {
      v214 = "w:\\tech5\\tungsten\\game\\spawning\\SpawnPlayerCmd.cpp(229) : SpawnSystem_Current";
      while ( 1 )
      {
        v47 = idPlayer::CastTo(c: (idPlayer *)owner);
        if ( (*((_BYTE *)&owner->flags + 1) & 0x80) == 0 && v47 != v11 )
          break;
LABEL_48:
        v109 = owner->actorNode.next;
        if ( v109 == nullptr || v109 == owner->actorNode.head )
          owner = nullptr;
        else
          owner = v109->owner;
        if ( owner == nullptr )
          goto LABEL_53;
      }
      v48 = idEntity::GetPhysics(this: owner);
      v49 = (float *)v48->GetOrigin(this: v48, a2: 0);
      v50 = (float)(v49[1] - p_pos->y);
      v51 = (float)(v49[2] - p_pos->z);
      v52 = (float)((float)((float)(*v49 - p_pos->x) * (float)(*v49 - p_pos->x))
                  + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)));
      _FP1 = (float)((float)((float)((float)(*v49 - p_pos->x) * (float)(*v49 - p_pos->x))
                           + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v54 = (float)((float)((float)((float)(*v49 - p_pos->x) * (float)(*v49 - p_pos->x))
                          + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                  * (float)0.5);
      __asm { fsel      f12, f1, f2, f0 }
      v56 = __frsqrte(_FP12);
      v57 = (float)((float)v56
                  * (float)((float)((float)((float)(*v49 - p_pos->x) * (float)(*v49 - p_pos->x))
                                  + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                          * (float)0.5));
      v58 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5) * (float)v56)
                                                                                                  * (float)v54)
                                                                                          * (float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5)
                                                                                                  * (float)v56))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)v57
                                                                                                  * (float)v56)
                                                                                          - (float)1.5)
                                                                          * (float)v56))
                                                          * (float)v54)
                                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5)
                                                                                                  * (float)v56)
                                                                                          * (float)v54)
                                                                                  * (float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5)
                                                                                          * (float)v56))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)v57 * (float)v56)
                                                                                  - (float)1.5)
                                                                  * (float)v56)))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v57
                                                                                                  * (float)v56)
                                                                                          - (float)1.5)
                                                                          * (float)v56)
                                                                  * (float)v54)
                                                          * (float)((float)-(float)((float)((float)v57 * (float)v56)
                                                                                  - (float)1.5)
                                                                  * (float)v56))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5) * (float)v56)))
                  * (float)v52);
      ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
      FactionFromTeam = idGameChallenge::GetFactionFromTeam(this: ChallengeEntity, team: &v6->allowedTeams);
      v61 = (idDeclFaction **)owner->GetFaction(this: owner);
      idDeclFaction::GetAttitudeTowards(
        this: *v61,
        otherFaction: FactionFromTeam,
        attitude: (idRelationship::attitude_t *)&v210);
      v62 = 0;
      if ( v210 >= 3 )
        goto LABEL_36;
      if ( owner->GetHealthComponent_2(this: owner) != nullptr )
      {
        v63 = (int)owner->GetHealthComponent_2(this: owner);
        if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v63 + 88))(a1: v63) == 0 )
        {
          v62 = 1;
LABEL_31:
          _FP0 = (float)((float)v58 - (float)_FP29);
          __asm { fsel      f29, f0, f29, f30 }
          v205 = _FP29;
          goto LABEL_32;
        }
      }
      if ( v210 >= 3 )
      {
LABEL_36:
        v84 = idPlayer::CastTo(c: (idPlayer *)owner);
        v85 = v84;
        if ( v84 != nullptr )
        {
          if ( ((double (__fastcall *)(idTungstenHealth *))v84->playerHealth.GetBaseHealthRatio_Impl)(a1: &v84->playerHealth) < 1.0
            || v85->engagementTracker.isEngaged )
          {
            goto LABEL_31;
          }
          _FP0 = (float)((float)v58 - (float)_FP28);
          __asm { fsel      f28, f0, f28, f30 }
          v211 = _FP28;
        }
      }
LABEL_32:
      if ( v62 != 0 )
      {
        owner->GetViewTransform(this: owner, a2: &v202, a3: (idMat3 *)v223);
        v65 = v223[0];
        v66 = v223[1];
        owner->GetEyePos(this: owner, a2: &v202);
        x = this->raycastOffset.x;
        v68 = p_pos->x;
        y = this->raycastOffset.y;
        z = p_pos->z;
        v204.y = p_pos->y;
        v204.x = v68;
        v71 = (float)(v68 + (float)x);
        v72 = (float)((float)y + v204.y);
        v73 = (float)((float)(v68 + (float)x) - v202.x);
        v74 = (float)(this->raycastOffset.z + z);
        v75 = (float)((float)((float)y + v204.y) - v202.y);
        v204.z = this->raycastOffset.z + z;
        v204.x = v68 + (float)x;
        _FP1 = (float)((float)((float)((float)((float)((float)y + v204.y) - v202.y)
                                     * (float)((float)((float)y + v204.y) - v202.y))
                             + (float)((float)(v204.x - v202.x) * (float)(v204.x - v202.x)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v77 = (float)((float)((float)((float)((float)((float)y + v204.y) - v202.y)
                                    * (float)((float)((float)y + v204.y) - v202.y))
                            + (float)((float)(v204.x - v202.x) * (float)(v204.x - v202.x)))
                    * (float)0.5);
        v204.y = (float)y + v204.y;
        __asm { fsel      f12, f1, f2, f0 }
        v79 = __frsqrte(_FP12);
        v80 = (float)((float)v73
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)v77)
                                                                                            * (float)v79)
                                                                                    - (float)1.5)
                                                                    * (float)v79)
                                                            * (float)v77)
                                                    * (float)((float)-(float)((float)((float)((float)v79 * (float)v77)
                                                                                    * (float)v79)
                                                                            - (float)1.5)
                                                            * (float)v79))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                    * (float)v79)));
        v81 = (float)((float)v75
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)v77)
                                                                                            * (float)v79)
                                                                                    - (float)1.5)
                                                                    * (float)v79)
                                                            * (float)v77)
                                                    * (float)((float)-(float)((float)((float)((float)v79 * (float)v77)
                                                                                    * (float)v79)
                                                                            - (float)1.5)
                                                            * (float)v79))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                    * (float)v79)));
        v82 = (float)((float)1.0
                    - (float)((float)((float)((float)v75
                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                                                                            * (float)v79)
                                                                                    * (float)v77)
                                                                            * (float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                                                                    * (float)v79))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v79 * (float)v77)
                                                                                    * (float)v79)
                                                                            - (float)1.5)
                                                            * (float)v79)))
                                    * (float)v66)
                            + (float)((float)((float)v73
                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                                                                            * (float)v79)
                                                                                    * (float)v77)
                                                                            * (float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                                                                    * (float)v79))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v79 * (float)v77)
                                                                                    * (float)v79)
                                                                            - (float)1.5)
                                                            * (float)v79)))
                                    * (float)v65)));
        if ( v82 >= 0.0099999998 )
        {
          if ( v82 <= 1.0 )
            v83 = (float)((float)1.0
                        - (float)((float)((float)((float)v75
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                                                                                * (float)v79)
                                                                                        * (float)v77)
                                                                                * (float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                                                                        * (float)v79))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v79 * (float)v77)
                                                                                        * (float)v79)
                                                                                - (float)1.5)
                                                                * (float)v79)))
                                        * (float)v66)
                                + (float)((float)((float)v73
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                                                                                * (float)v79)
                                                                                        * (float)v77)
                                                                                * (float)((float)-(float)((float)((float)((float)v79 * (float)v77) * (float)v79) - (float)1.5)
                                                                                        * (float)v79))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v79 * (float)v77)
                                                                                        * (float)v79)
                                                                                - (float)1.5)
                                                                * (float)v79)))
                                        * (float)v65)));
          else
            v83 = 1.0;
        }
        else
        {
          v83 = 0.0099999998;
        }
        idAngles::ToForward(this: &v217, result: (idVec3 *)&p_pos[1]);
        v87 = (float)-(float)((float)((float)((float)(v217.yaw * (float)-v81) + (float)((float)-v80 * v217.pitch))
                                    * (float)0.98000002)
                            - (float)1.0);
        if ( v87 >= 0.02 )
        {
          if ( v87 > 1.0 )
            v87 = 1.0;
        }
        else
        {
          v87 = 0.02;
        }
        v88 = context->currentLocationIndex;
        v201 = v202;
        v207.valueModifier = (float)((float)v87 * (float)v83) * (float)0.15000001;
        v207.locationIndex = v88;
        v203 = v204;
        v207.visibilityQuery.index = *(_QWORD *)&idClip::Translation(
                                                   this: (idClip *)&v218,
                                                   result: &clientGame->clip,
                                                   a3: nullptr,
                                                   start: &v201,
                                                   end: &v203,
                                                   clipModel: nullptr,
                                                   startAxis: &mat3_identity,
                                                   clipMask: 3,
                                                   passEntityNumber: v117,
                                                   moveClipModel: v121,
                                                   userName: v125,
                                                   a12: v129,
                                                   a13: v133,
                                                   a14: v137,
                                                   a15: v141,
                                                   a16: v145,
                                                   a17: v149,
                                                   a18: v153,
                                                   a19: v157,
                                                   a20: v161,
                                                   a21: v165,
                                                   a22: v169,
                                                   a23: v173,
                                                   a24: v177,
                                                   a25: v181,
                                                   a26: v185,
                                                   a27: v189,
                                                   a28: 0x2000,
                                                   a29: v193,
                                                   a30: false,
                                                   a31: v197,
                                                   a32: (int)v214)->world;
        idList<idSpawnPlayerCmd::deferredVisibilityQuery_t,5>::Append(
          this: &this->deferredVisibilityQueries,
          obj: &v207);
        v89 = idEntity::GetPhysics(this: owner);
        valueFloat = mp_playerSpawnLookAheadTime.valueFloat;
        v91 = (float *)v89->GetLinearVelocity(this: (idPhysics *)&v222, result: (idVec3 *)v89, a3: 0);
        v92 = (float)(*v91 * (float)valueFloat);
        v93 = (float)(v91[1] * (float)valueFloat);
        v94 = (float)(v91[2] * (float)valueFloat);
        v207.locationIndex = context->currentLocationIndex;
        v207.valueModifier = (float)((float)v87 * (float)v83) * (float)0.25;
        v201.x = (float)v92 + v202.x;
        v201.y = (float)v93 + v202.y;
        v201.z = v202.z + (float)v94;
        v207.visibilityQuery.index = *(_QWORD *)&idClip::Translation(
                                                   this: (idClip *)&v221,
                                                   result: &clientGame->clip,
                                                   a3: nullptr,
                                                   start: &v201,
                                                   end: &v203,
                                                   clipModel: nullptr,
                                                   startAxis: &mat3_identity,
                                                   clipMask: 3,
                                                   passEntityNumber: v118,
                                                   moveClipModel: v122,
                                                   userName: v126,
                                                   a12: v130,
                                                   a13: v134,
                                                   a14: v138,
                                                   a15: v142,
                                                   a16: v146,
                                                   a17: v150,
                                                   a18: v154,
                                                   a19: v158,
                                                   a20: v162,
                                                   a21: v166,
                                                   a22: v170,
                                                   a23: v174,
                                                   a24: v178,
                                                   a25: v182,
                                                   a26: v186,
                                                   a27: v190,
                                                   a28: 0x2000,
                                                   a29: v194,
                                                   a30: false,
                                                   a31: v198,
                                                   a32: (int)"w:\\tech5\\tungsten\\game\\spawning\\SpawnPlayerCmd.cpp(237) : S"
                                                        "pawnSystem_Future")->world;
        idList<idSpawnPlayerCmd::deferredVisibilityQuery_t,5>::Append(
          this: &this->deferredVisibilityQueries,
          obj: &v207);
        v95 = (float)((float)((float)v87 * (float)v83) * (float)0.30000001);
        v207.valueModifier = v95;
        v207.locationIndex = context->currentLocationIndex;
        _FP8 = (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y))
                             + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f5, f8, f9, f0 }
        v98 = __frsqrte(_FP5);
        v99 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v98
                                                                                            * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5))
                                                                                    * (float)v98)
                                                                            - (float)1.5)
                                                            * (float)v98)
                                                    * (float)((float)((float)((float)(v203.y - v201.y)
                                                                            * (float)(v203.y - v201.y))
                                                                    + (float)((float)(v203.x - v201.x)
                                                                            * (float)(v203.x - v201.x)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v98
                                                                                    * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x)))
                                                                                            * (float)0.5))
                                                                            * (float)v98)
                                                                    - (float)1.5)
                                                    * (float)v98))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v98
                                                            * (float)((float)((float)((float)(v203.y - v201.y)
                                                                                    * (float)(v203.y - v201.y))
                                                                            + (float)((float)(v203.x - v201.x)
                                                                                    * (float)(v203.x - v201.x)))
                                                                    * (float)0.5))
                                                    * (float)v98)
                                            - (float)1.5)
                            * (float)v98));
        v100 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98) - (float)1.5) * (float)v98)
                                                                                             * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98) - (float)1.5)
                                                                                             * (float)v98))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5))
                                                                                             * (float)v98)
                                                                                     - (float)1.5)
                                                                     * (float)v98))
                                                     * (float)((float)((float)((float)(v203.y - v201.y)
                                                                             * (float)(v203.y - v201.y))
                                                                     + (float)((float)(v203.x - v201.x)
                                                                             * (float)(v203.x - v201.x)))
                                                             * (float)0.5))
                                             * (float)v99)
                                     - (float)1.5)
                     * (float)v99);
        v101 = (float)((float)(v203.y - v201.y)
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98) - (float)1.5) * (float)v98) * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98) - (float)1.5) * (float)v98))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98)
                                                                                             - (float)1.5)
                                                                             * (float)v98))
                                                             * (float)((float)((float)((float)(v203.y - v201.y)
                                                                                     * (float)(v203.y - v201.y))
                                                                             + (float)((float)(v203.x - v201.x)
                                                                                     * (float)(v203.x - v201.x)))
                                                                     * (float)0.5))
                                                     * (float)v99)
                                             - (float)1.5)
                             * (float)v99));
        v103 = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98) - (float)1.5) * (float)v98) * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98) - (float)1.5) * (float)v98))
                                                                                             - (float)1.5)
                                                                             * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98) - (float)1.5)
                                                                                     * (float)v98))
                                                                     * (float)((float)((float)((float)(v203.y - v201.y)
                                                                                             * (float)(v203.y - v201.y))
                                                                                     + (float)((float)(v203.x - v201.x)
                                                                                             * (float)(v203.x - v201.x)))
                                                                             * (float)0.5))
                                                             * (float)v99)
                                                     - (float)1.5)
                                     * (float)v99)
                             * (float)0.0)
                     * vec3_up.y);
        v102 = (float)((float)(v203.x - v201.x)
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98) - (float)1.5) * (float)v98) * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98) - (float)1.5) * (float)v98))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)(v203.y - v201.y) * (float)(v203.y - v201.y)) + (float)((float)(v203.x - v201.x) * (float)(v203.x - v201.x))) * (float)0.5)) * (float)v98)
                                                                                             - (float)1.5)
                                                                             * (float)v98))
                                                             * (float)((float)((float)((float)(v203.y - v201.y)
                                                                                     * (float)(v203.y - v201.y))
                                                                             + (float)((float)(v203.x - v201.x)
                                                                                     * (float)(v203.x - v201.x)))
                                                                     * (float)0.5))
                                                     * (float)v99)
                                             - (float)1.5)
                             * (float)v99));
        v104 = (float)((float)((float)((float)v100 * (float)0.0) * vec3_up.x) - (float)((float)v102 * vec3_up.z));
        v105 = (float)((float)((float)((float)v102 * vec3_up.y) - (float)((float)v101 * vec3_up.x)) * (float)40.0);
        v106 = (float)((float)v104 * (float)40.0);
        v107 = (float)((float)((float)((float)v101 * vec3_up.z) - (float)v103) * (float)40.0);
        v201.z = (float)((float)((float)((float)v102 * vec3_up.y) - (float)((float)v101 * vec3_up.x)) * (float)40.0)
               + v202.z;
        v201.y = (float)((float)v104 * (float)40.0) + v202.y;
        v201.x = (float)((float)((float)((float)v101 * vec3_up.z) - (float)v103) * (float)40.0) + v202.x;
        v203.x = (float)((float)((float)((float)v101 * vec3_up.z) - (float)v103) * (float)40.0) + (float)v71;
        v203.y = (float)((float)v104 * (float)40.0) + (float)v72;
        v203.z = (float)((float)((float)((float)v102 * vec3_up.y) - (float)((float)v101 * vec3_up.x)) * (float)40.0)
               + (float)v74;
        v207.visibilityQuery.index = *(_QWORD *)&idClip::Translation(
                                                   this: (idClip *)&v219,
                                                   result: &clientGame->clip,
                                                   a3: nullptr,
                                                   start: &v201,
                                                   end: &v203,
                                                   clipModel: nullptr,
                                                   startAxis: &mat3_identity,
                                                   clipMask: 3,
                                                   passEntityNumber: v119,
                                                   moveClipModel: v123,
                                                   userName: v127,
                                                   a12: v131,
                                                   a13: v135,
                                                   a14: v139,
                                                   a15: v143,
                                                   a16: v147,
                                                   a17: v151,
                                                   a18: v155,
                                                   a19: v159,
                                                   a20: v163,
                                                   a21: v167,
                                                   a22: v171,
                                                   a23: v175,
                                                   a24: v179,
                                                   a25: v183,
                                                   a26: v187,
                                                   a27: v191,
                                                   a28: 0x2000,
                                                   a29: v195,
                                                   a30: false,
                                                   a31: v199,
                                                   a32: (int)"w:\\tech5\\tungsten\\game\\spawning\\SpawnPlayerCmd.cpp(254) : S"
                                                        "pawnSystem_Side1")->world;
        idList<idSpawnPlayerCmd::deferredVisibilityQuery_t,5>::Append(
          this: &this->deferredVisibilityQueries,
          obj: &v207);
        v203.x = (float)v71 - (float)v107;
        v203.y = (float)v72 - (float)v106;
        v203.z = (float)v74 - (float)v105;
        v201.x = v202.x - (float)v107;
        v108 = context->currentLocationIndex;
        v207.valueModifier = v95;
        v201.y = v202.y - (float)v106;
        v201.z = v202.z - (float)v105;
        v207.locationIndex = v108;
        v207.visibilityQuery.index = *(_QWORD *)&idClip::Translation(
                                                   this: (idClip *)&v220,
                                                   result: &clientGame->clip,
                                                   a3: nullptr,
                                                   start: &v201,
                                                   end: &v203,
                                                   clipModel: nullptr,
                                                   startAxis: &mat3_identity,
                                                   clipMask: 3,
                                                   passEntityNumber: v120,
                                                   moveClipModel: v124,
                                                   userName: v128,
                                                   a12: v132,
                                                   a13: v136,
                                                   a14: v140,
                                                   a15: v144,
                                                   a16: v148,
                                                   a17: v152,
                                                   a18: v156,
                                                   a19: v160,
                                                   a20: v164,
                                                   a21: v168,
                                                   a22: v172,
                                                   a23: v176,
                                                   a24: v180,
                                                   a25: v184,
                                                   a26: v188,
                                                   a27: v192,
                                                   a28: 0x2000,
                                                   a29: v196,
                                                   a30: false,
                                                   a31: v200,
                                                   a32: (int)"w:\\tech5\\tungsten\\game\\spawning\\SpawnPlayerCmd.cpp(262) : S"
                                                        "pawnSystem_Side2")->world;
        idList<idSpawnPlayerCmd::deferredVisibilityQuery_t,5>::Append(
          this: &this->deferredVisibilityQueries,
          obj: &v207);
        v15 = v215;
        _FP28 = v211;
        p_pos = &v212->pos;
        _FP29 = v205;
        v11 = v216;
        v6 = v213;
      }
      goto LABEL_48;
    }
  }
LABEL_53:
  v110 = mp_maxPlayerSpawnFriendlyDistance.valueFloat;
  if ( _FP28 >= mp_minPlayerSpawnFriendlyDistance.valueFloat )
  {
    if ( _FP28 <= v110 )
      v110 = _FP28;
  }
  else
  {
    v110 = mp_minPlayerSpawnFriendlyDistance.valueFloat;
  }
  v111 = (float)((float)((float)v110 - mp_minPlayerSpawnFriendlyDistance.valueFloat)
               / (float)(mp_maxPlayerSpawnFriendlyDistance.valueFloat - mp_minPlayerSpawnFriendlyDistance.valueFloat));
  if ( _FP29 >= mp_minPlayerSpawnHostileDistance.valueFloat )
  {
    if ( _FP29 <= mp_maxPlayerSpawnHostileDistance.valueFloat )
      v112 = _FP29;
    else
      v112 = mp_maxPlayerSpawnHostileDistance.valueFloat;
  }
  else
  {
    v112 = mp_minPlayerSpawnHostileDistance.valueFloat;
  }
  v113 = (float)((float)((float)v112 - mp_minPlayerSpawnHostileDistance.valueFloat)
               / (float)(mp_maxPlayerSpawnHostileDistance.valueFloat - mp_minPlayerSpawnHostileDistance.valueFloat));
  if ( v113 >= 1.0 )
    v114 = (float)((float)((float)v111 * (float)-0.19999999) + (float)1.0);
  else
    v114 = (float)((float)((float)v113 * (float)0.69999999) + (float)v15);
  v115 = (float)((float)((float)((float)(p_pos[2].x * (float)v114) * v208) * v206) * v209);
  return *((float *)&v115 + 1);
}


// ========================================================================
// ?EvaluateContext@idSpawnPlayerCmd@@UAA_NABVCommand@idSpawnManager@@AAVContext@3@@Z
// EA  : 0x82EAACF8
// RVA : 0x00EAACF8
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

BOOL __fastcall idSpawnPlayerCmd::EvaluateContext(
        idSpawnPlayerCmd *this,
        const idSpawnManager::Command *command,
        idSpawnManager::Context *context)
{
  unsigned __int64 v3; // r22
  int v7; // r25
  int v8; // r23
  int v9; // r31
  idSpawnPlayerCmd::deferredVisibilityQuery_t *v10; // r9
  unsigned __int64 index; // r11
  unsigned int v12; // r11
  char v13; // r11
  bool v14; // zf
  unsigned __int64 v15; // r11
  idSpawnPlayerCmd::deferredVisibilityQuery_t *v16; // r11
  int locationIndex; // r10
  idSpawnPlayerCmd::deferredVisibilityQuery_t *list; // r4
  int v19; // r31
  trace_t v21; // [sp+50h] [-100h] BYREF

  LODWORD(v3) = 0;
  v7 = -1;
  v8 = 0;
  if ( this->deferredVisibilityQueries.num > 0 )
  {
    v9 = 0;
    HIDWORD(v3) = 377216;
    do
    {
      v10 = &this->deferredVisibilityQueries.list[v9];
      index = v10->visibilityQuery.index;
      if ( LODWORD(v10->visibilityQuery.index) < *(_DWORD *)(HIDWORD(v10->visibilityQuery.index) + 377212)
        || (unsigned int)index > *(_DWORD *)(HIDWORD(index) + 377220) )
      {
        v13 = 0;
      }
      else
      {
        v12 = *(_DWORD *)(8 * ((index & 0xFFF) + ((2 * index) & 0x1FFE)) + HIDWORD(index) + 278924);
        if ( v12 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
          || (v10 = (idSpawnPlayerCmd::deferredVisibilityQuery_t *)HIDWORD(idCollisionQuery::finalResultsLastSubmittedOffset),
              v14 = v12 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset,
              v13 = 1,
              !v14) )
        {
          v13 = 0;
        }
      }
      if ( v13 != 0 )
      {
        v15 = v10->visibilityQuery.index;
        HIDWORD(v15) = clientGame;
        v10->visibilityQuery.index = v3;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v21,
          query: (idCollisionQuery *)(24 * ((v15 & 0xFFF) + 12067) + HIDWORD(v15)),
          peek: false);
        if ( v21.fraction >= 1.0 )
        {
          v16 = &this->deferredVisibilityQueries.list[v9];
          locationIndex = v16->locationIndex;
          if ( v7 != locationIndex )
            context->spawnLocations.list[locationIndex].sortValue = v16->valueModifier
                                                                  * context->spawnLocations.list[locationIndex].sortValue;
          v7 = locationIndex;
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->deferredVisibilityQueries.num );
  }
  if ( this->deferredVisibilityQueries.listStatic == 0 || this->deferredVisibilityQueries.listStatic == 2 )
  {
    list = this->deferredVisibilityQueries.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->deferredVisibilityQueries.list = nullptr;
    this->deferredVisibilityQueries.size = 0;
  }
  v19 = 0;
  this->deferredVisibilityQueries.num = 0;
  do
  {
    if ( context->currentLocationIndex >= context->spawnLocations.num )
      break;
    ++v19;
    context->spawnLocations.list[context->currentLocationIndex++].sortValue = idSpawnPlayerCmd::EvaluateCurrentLocation(
                                                                                this,
                                                                                command,
                                                                                context);
  }
  while ( v19 < 5 );
  return context->currentLocationIndex >= context->spawnLocations.num && this->deferredVisibilityQueries.num == 0;
}


// ========================================================================
// ?SpawnPlayer@idSpawnPlayerCmd@@QAAHHABW4gameTeam_t@@HABVidSpawnNodeGroup@@_N@Z
// EA  : 0x82EAAFE8
// RVA : 0x00EAAFE8
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

int __fastcall idSpawnPlayerCmd::SpawnPlayer(
        idSpawnPlayerCmd *this,
        int playerIndex,
        gameTeam_t *allowedTeams,
        int loadoutIndex,
        const idSpawnNodeGroup *spawnNodeGroup,
        bool useInitialNodes)
{
  int result; // r3
  idSpawnPlayerCmdData *v13; // r11

  result = idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>::GetFreeDataIndex(this);
  v13 = &this->dataArray.list[result];
  v13->playerIndex = playerIndex;
  v13->allowedTeams = *allowedTeams;
  v13->loadoutIndex = loadoutIndex;
  v13->spawnNodeGroup = spawnNodeGroup;
  v13->onlyInitialNodes = useInitialNodes;
  v13->teleport = false;
  return result;
}


// ========================================================================
// `dynamic initializer for 'mp_minPlayerSpawnHostileDistance''
// EA  : 0x833929B0
// RVA : 0x013929B0
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_minPlayerSpawnHostileDistance__()
{
  idCVar::idCVar(
    this: &mp_minPlayerSpawnHostileDistance,
    name: "mp_minPlayerSpawnHostileDistance",
    value: "400.0",
    flags: 4,
    description: "Min danger distance.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_minPlayerSpawnHostileDistance__);
}


// ========================================================================
// `dynamic initializer for 'mp_maxPlayerSpawnHostileDistance''
// EA  : 0x83392A08
// RVA : 0x01392A08
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_maxPlayerSpawnHostileDistance__()
{
  idCVar::idCVar(
    this: &mp_maxPlayerSpawnHostileDistance,
    name: "mp_maxPlayerSpawnHostileDistance",
    value: "2000.0",
    flags: 4,
    description: "Max danger distance.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_maxPlayerSpawnHostileDistance__);
}


// ========================================================================
// `dynamic initializer for 'mp_minPlayerSpawnFriendlyDistance''
// EA  : 0x83392A60
// RVA : 0x01392A60
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_minPlayerSpawnFriendlyDistance__()
{
  idCVar::idCVar(
    this: &mp_minPlayerSpawnFriendlyDistance,
    name: "mp_minPlayerSpawnFriendlyDistance",
    value: "500.0",
    flags: 4,
    description: "Min friendly distance.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_minPlayerSpawnFriendlyDistance__);
}


// ========================================================================
// `dynamic initializer for 'mp_maxPlayerSpawnFriendlyDistance''
// EA  : 0x83392AB8
// RVA : 0x01392AB8
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_maxPlayerSpawnFriendlyDistance__()
{
  idCVar::idCVar(
    this: &mp_maxPlayerSpawnFriendlyDistance,
    name: "mp_maxPlayerSpawnFriendlyDistance",
    value: "4000.0",
    flags: 4,
    description: "Max friendly distance.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_maxPlayerSpawnFriendlyDistance__);
}


// ========================================================================
// `dynamic initializer for 'mp_playerSpawnLookAheadTime''
// EA  : 0x83392B10
// RVA : 0x01392B10
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_playerSpawnLookAheadTime__()
{
  idCVar::idCVar(
    this: &mp_playerSpawnLookAheadTime,
    name: "mp_playerSpawnLookAheadTime",
    value: "1.5",
    flags: 4,
    description: "Number of seconds that is used to predict future enemies locations for a LOS check",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_playerSpawnLookAheadTime__);
}


// ========================================================================
// `dynamic initializer for 'mp_minPlayerSpawnKillerDistance''
// EA  : 0x83392B68
// RVA : 0x01392B68
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_minPlayerSpawnKillerDistance__()
{
  idCVar::idCVar(
    this: &mp_minPlayerSpawnKillerDistance,
    name: "mp_minPlayerSpawnKillerDistance",
    value: "1500.0",
    flags: 4,
    description: "Any spawn location closer than this to the killer won't be considered.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_minPlayerSpawnKillerDistance__);
}


// ========================================================================
// `dynamic initializer for 'mp_maxPlayerSpawnKillerDistance''
// EA  : 0x83392BC0
// RVA : 0x01392BC0
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_maxPlayerSpawnKillerDistance__()
{
  idCVar::idCVar(
    this: &mp_maxPlayerSpawnKillerDistance,
    name: "mp_maxPlayerSpawnKillerDistance",
    value: "3000.0",
    flags: 4,
    description: "Any spawn location closer than this to the killer will be devalued.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_maxPlayerSpawnKillerDistance__);
}


// ========================================================================
// `dynamic initializer for 'mp_minPlayerSpawnLastDistance''
// EA  : 0x83392C18
// RVA : 0x01392C18
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_minPlayerSpawnLastDistance__()
{
  idCVar::idCVar(
    this: &mp_minPlayerSpawnLastDistance,
    name: "mp_minPlayerSpawnLastDistance",
    value: "500.0",
    flags: 4,
    description: "Any spawn location closer than this to the last spawn won't be considered.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_minPlayerSpawnLastDistance__);
}


// ========================================================================
// `dynamic initializer for 'mp_maxPlayerSpawnLastDistance''
// EA  : 0x83392C70
// RVA : 0x01392C70
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_maxPlayerSpawnLastDistance__()
{
  idCVar::idCVar(
    this: &mp_maxPlayerSpawnLastDistance,
    name: "mp_maxPlayerSpawnLastDistance",
    value: "1500.0",
    flags: 4,
    description: "Any spawn location closer than this to the last spawn will be devalued.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_maxPlayerSpawnLastDistance__);
}

