
// ========================================================================
// ?Think@idSpawnArea@@UAAXXZ
// EA  : 0x82EA7648
// RVA : 0x00EA7648
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSpawnArea::Think(idSpawnArea *this)
{
  int v2; // r30
  __int64 v3; // r4 OVERLAPPED
  int v4; // r5
  int v5; // r9
  idList<idSpawnArea::GeneratedPosition *,5> *p_obstructedPositions; // r10
  int v7; // r8
  int num; // r11
  int v9; // r11
  int v10; // r11

  idEntity::Think(this);
  v2 = gameLocal->GetPreviousGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v3 = ((__int64 (__fastcall *)(idGameLocal *, int))gameLocal->GetGameMs)(a1: gameLocal, a2: 1);
  v5 = 0;
  if ( this->obstructedPositions.num <= 0 )
    goto LABEL_11;
  p_obstructedPositions = &this->obstructedPositions;
  v7 = 0;
  do
  {
    v4 = HIDWORD(v3) - v2;
    p_obstructedPositions->list[v7]->obstructionTimer = p_obstructedPositions->list[v7]->obstructionTimer
                                                      - (float)((float)*(__int64 *)((char *)&v3 - 4) * (float)0.001);
    if ( p_obstructedPositions->list[v7]->obstructionTimer > 0.0 )
    {
      ++v5;
      ++v7;
    }
    else if ( v5 >= 0 )
    {
      num = this->obstructedPositions.num;
      if ( v5 < num )
      {
        v9 = num - 1;
        this->obstructedPositions.num = v9;
        if ( v5 != v9 )
          p_obstructedPositions->list[v7] = p_obstructedPositions->list[v9];
      }
    }
    v10 = this->obstructedPositions.num;
  }
  while ( v5 < v10 );
  if ( v10 <= 0 )
LABEL_11:
    idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?RandomizeGeneratedPositions@idSpawnArea@@AAAXXZ
// EA  : 0x82EA7788
// RVA : 0x00EA7788
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idSpawnArea::RandomizeGeneratedPositions(idSpawnArea *this)
{
  signed int num; // r9
  signed int v2; // r31
  int v3; // r4
  unsigned int seed; // r10
  unsigned int v5; // r6
  int v6; // r5
  char *p_back_chain; // r7
  float *p_distanceFromEdge; // r10
  int i; // ctr
  idSpawnArea::GeneratedPosition *list; // r10
  double v11; // fp0
  idClientGame *v12; // r7
  double v13; // fp13
  float *p_x; // r11
  double v15; // fp12
  int v16; // r8
  double v17; // fp11
  double v18; // fp10
  float *v19; // r10
  idSpawnArea::GeneratedPosition *v20; // r11
  unsigned int v21; // r11
  signed int v22; // r6
  char *v23; // r7
  float *v24; // r10
  int j; // ctr
  idSpawnArea::GeneratedPosition *v26; // r10
  double v27; // fp0
  idClientGame *v28; // r7
  double v29; // fp13
  float *v30; // r11
  double v31; // fp12
  int v32; // r8
  double v33; // fp11
  double v34; // fp10
  float *v35; // r10
  idSpawnArea::GeneratedPosition *v36; // r11
  unsigned int v37; // r11
  signed int v38; // r6
  unsigned int v39; // r8
  int v40; // r6
  int v41; // r5
  char *v42; // r7
  float *v43; // r8
  int k; // ctr
  idSpawnArea::GeneratedPosition *v45; // r10
  double v46; // fp0
  idClientGame *v47; // r7
  double v48; // fp13
  float *v49; // r11
  double v50; // fp12
  double v51; // fp11
  double v52; // fp10
  float *v53; // r10
  idSpawnArea::GeneratedPosition *v54; // r11
  unsigned int v55; // r11
  signed int v56; // r6
  char *v57; // r7
  _DWORD *v58; // r10
  int m; // ctr
  idSpawnArea::GeneratedPosition *v60; // r10
  double v61; // fp0
  double v62; // fp13
  float *v63; // r11
  double v64; // fp12
  int v65; // r8
  double v66; // fp11
  double v67; // fp10
  float *v68; // r10
  idSpawnArea::GeneratedPosition *v69; // r11
  int v70; // r5
  signed int v71; // r7
  int v72; // r6
  unsigned int v73; // r10
  unsigned int v74; // r4
  int v75; // r10
  char *v76; // r8
  float *v77; // r10
  int n; // ctr
  idSpawnArea::GeneratedPosition *v79; // r10
  double v80; // fp0
  double v81; // fp13
  float *v82; // r11
  double v83; // fp12
  double v84; // fp11
  double v85; // fp10
  float *v86; // r10
  idSpawnArea::GeneratedPosition *v87; // r11
  char back_chain; // [sp+0h] [-54h] BYREF
  float v89; // [sp+4h] [-50h]
  float v90; // [sp+8h] [-4Ch]
  float v91; // [sp+Ch] [-48h]
  float v92; // [sp+10h] [-44h]
  float v93; // [sp+14h] [-40h]

  num = this->generatedPositions.num;
  v2 = 0;
  if ( num >= 4 )
  {
    v3 = 0;
    do
    {
      seed = clientGame->random.seed;
      __twllei(num, 0);
      v5 = 1664525 * seed + 1013904223;
      clientGame->random.seed = v5;
      v6 = (v5 >> 10) & 0x7FFF;
      __twlgei(num & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
      p_back_chain = &back_chain;
      p_distanceFromEdge = &this->generatedPositions.list[v3 - 1].distanceFromEdge;
      for ( i = 5; i != 0; --i )
      {
        ++p_distanceFromEdge;
        p_back_chain += 4;
        *(float *)p_back_chain = *p_distanceFromEdge;
      }
      list = this->generatedPositions.list;
      v11 = v89;
      v12 = clientGame;
      v13 = v90;
      p_x = &list[v3].position.x;
      v15 = v91;
      v16 = v6 % num;
      v17 = v92;
      v18 = v93;
      v19 = &list[v16].position.x;
      *p_x = *v19;
      p_x[1] = v19[1];
      p_x[2] = v19[2];
      p_x[3] = v19[3];
      p_x[4] = v19[4];
      v20 = &this->generatedPositions.list[v16];
      v20->position.x = v11;
      v20->position.y = v13;
      v20->position.z = v15;
      v20->obstructionTimer = v17;
      v20->distanceFromEdge = v18;
      v21 = v12->random.seed;
      __twllei(num, 0);
      v12->random.seed = 1664525 * v21 + 1013904223;
      v22 = ((1664525 * v21 + 1013904223) >> 10) & 0x7FFF;
      __twlgei(num & ~(__ROL4__(v22, 1) - 1), 0xFFFFFFFF);
      v23 = &back_chain;
      v24 = &this->generatedPositions.list[v3].distanceFromEdge;
      for ( j = 5; j != 0; --j )
      {
        ++v24;
        v23 += 4;
        *(float *)v23 = *v24;
      }
      v26 = this->generatedPositions.list;
      v27 = v89;
      v28 = clientGame;
      v29 = v90;
      v30 = &v26[v3].position.x;
      v31 = v91;
      v32 = v22 % num;
      v33 = v92;
      v34 = v93;
      v35 = &v26[v32].position.x;
      v30[5] = *v35;
      v30[6] = v35[1];
      v30[7] = v35[2];
      v30[8] = v35[3];
      v30[9] = v35[4];
      v36 = &this->generatedPositions.list[v32];
      v36->position.x = v27;
      v36->position.y = v29;
      v36->position.z = v31;
      v36->obstructionTimer = v33;
      v36->distanceFromEdge = v34;
      v37 = v28->random.seed;
      __twllei(num, 0);
      v28->random.seed = 1664525 * v37 + 1013904223;
      v38 = ((1664525 * v37 + 1013904223) >> 10) & 0x7FFF;
      v39 = num & ~(__ROL4__(v38, 1) - 1);
      v40 = v38 % num;
      __twlgei(v39, 0xFFFFFFFF);
      v41 = v3 * 20 + 60;
      v42 = &back_chain;
      v43 = &this->generatedPositions.list[v3 + 1].distanceFromEdge;
      for ( k = 5; k != 0; --k )
      {
        ++v43;
        v42 += 4;
        *(float *)v42 = *v43;
      }
      v45 = this->generatedPositions.list;
      v46 = v89;
      v47 = clientGame;
      v48 = v90;
      v49 = &v45[v3 + 2].position.x;
      v50 = v91;
      v51 = v92;
      v52 = v93;
      v53 = &v45[v40].position.x;
      *v49 = *v53;
      v49[1] = v53[1];
      v49[2] = v53[2];
      v49[3] = v53[3];
      v49[4] = v53[4];
      v54 = &this->generatedPositions.list[v40];
      v54->position.x = v46;
      v54->position.y = v48;
      v54->position.z = v50;
      v54->obstructionTimer = v51;
      v54->distanceFromEdge = v52;
      v55 = v47->random.seed;
      __twllei(num, 0);
      v47->random.seed = 1664525 * v55 + 1013904223;
      v56 = ((1664525 * v55 + 1013904223) >> 10) & 0x7FFF;
      __twlgei(num & ~(__ROL4__(v56, 1) - 1), 0xFFFFFFFF);
      v57 = &back_chain;
      v58 = (_DWORD *)((char *)this->generatedPositions.list + v41 - 4);
      for ( m = 5; m != 0; --m )
      {
        ++v58;
        v57 += 4;
        *(_DWORD *)v57 = *v58;
      }
      v60 = this->generatedPositions.list;
      v61 = v89;
      v2 += 4;
      v62 = v90;
      v63 = (float *)((char *)&v60->position.x + v41);
      v64 = v91;
      v65 = v56 % num;
      v66 = v92;
      v67 = v93;
      v3 += 4;
      v68 = &v60[v65].position.x;
      *v63 = *v68;
      v63[1] = v68[1];
      v63[2] = v68[2];
      v63[3] = v68[3];
      v63[4] = v68[4];
      v69 = &this->generatedPositions.list[v65];
      v69->position.x = v61;
      v69->position.y = v62;
      v69->position.z = v64;
      v69->obstructionTimer = v66;
      v69->distanceFromEdge = v67;
    }
    while ( v2 < num - 3 );
  }
  if ( v2 < num )
  {
    v70 = num - v2;
    v71 = v2;
    do
    {
      if ( num != 0 )
      {
        v73 = clientGame->random.seed;
        __twllei(num, 0);
        v74 = 1664525 * v73 + 1013904223;
        clientGame->random.seed = v74;
        v75 = (v74 >> 10) & 0x7FFF;
        v72 = v75 % num;
        __twlgei(num & ~(__ROL4__(v75, 1) - 1), 0xFFFFFFFF);
      }
      else
      {
        v72 = 0;
      }
      v76 = &back_chain;
      v77 = &this->generatedPositions.list[v71 - 1].distanceFromEdge;
      for ( n = 5; n != 0; --n )
      {
        ++v77;
        v76 += 4;
        *(float *)v76 = *v77;
      }
      v79 = this->generatedPositions.list;
      v80 = v89;
      --v70;
      v81 = v90;
      v82 = &v79[v71].position.x;
      v83 = v91;
      v84 = v92;
      v85 = v93;
      ++v71;
      v86 = &v79[v72].position.x;
      *v82 = *v86;
      v82[1] = v86[1];
      v82[2] = v86[2];
      v82[3] = v86[3];
      v82[4] = v86[4];
      v87 = &this->generatedPositions.list[v72];
      v87->position.x = v80;
      v87->position.y = v81;
      v87->position.z = v83;
      v87->obstructionTimer = v84;
      v87->distanceFromEdge = v85;
    }
    while ( v70 != 0 );
  }
}


// ========================================================================
// ?Debug_Draw@idSpawnArea@@UBAXW4debugDrawLevel_t@idSpawnNode@@@Z
// EA  : 0x82EA7C60
// RVA : 0x00EA7C60
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idSpawnArea::Debug_Draw(idSpawnArea *this, idSpawnNode::debugDrawLevel_t drawLevel)
{
  idPhysics *Physics; // r3
  idClipModel *v4; // r3
  idCollisionModel *collisionModel; // r3
  idPhysics *v6; // r3
  float *v7; // r3
  idSpawnArea_vtbl *v8; // r6
  bool (__fastcall *Debug_IsValid)(struct idSpawnArea *); // r5
  idColor *v10; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  idRenderWorld *v14; // r3
  idRenderWorld *v15; // r3
  int v16; // r25
  int v17; // r30
  int (*GetRenderWorld)(void); // ctr
  int v19; // r3
  int v20; // r3
  idRenderWorld *v21; // r3
  idRenderWorld *v22; // r3
  int v23; // r28
  int v24; // r30
  idRenderWorld *v25; // r3
  int v26; // r28
  int v27; // r30
  idSpawnArea::GeneratedPosition *v28; // r11
  double obstructionTimer; // fp0
  double v30; // fp11
  idRenderWorld *v31; // r3
  float x; // [sp+60h] [-110h] BYREF
  float y; // [sp+64h] [-10Ch]
  float v34; // [sp+68h] [-108h]
  float v35; // [sp+6Ch] [-104h]
  float v36; // [sp+70h] [-100h]
  float v37; // [sp+74h] [-FCh]
  float v38; // [sp+78h] [-F8h]
  float v39; // [sp+7Ch] [-F4h]
  float v40; // [sp+80h] [-F0h]
  float v41; // [sp+84h] [-ECh]
  float v42; // [sp+88h] [-E8h]
  float v43; // [sp+8Ch] [-E4h]
  float v44; // [sp+90h] [-E0h]
  float v45; // [sp+94h] [-DCh]
  float v46; // [sp+98h] [-D8h]
  float v47[4]; // [sp+A0h] [-D0h] BYREF
  float v48; // [sp+B0h] [-C0h] BYREF
  float v49; // [sp+B4h] [-BCh]
  float v50; // [sp+B8h] [-B8h]
  idVec4 v51; // [sp+F0h] [-80h] BYREF

  if ( drawLevel == DL_HIGH || !this->Debug_IsValid(this) )
  {
    Physics = idEntity::GetPhysics(this);
    v4 = Physics->GetClipModel(this: Physics, a2: 0);
    if ( v4->collisionModel != nullptr )
    {
      collisionModel = v4->collisionModel;
    }
    else if ( v4->traceModels.num <= 0 )
    {
      collisionModel = idClipModel::NoTraceModelWarning(this: v4);
    }
    else
    {
      collisionModel = v4->clip->traceModelCache->cache.list[*v4->traceModels.list]->collisionModel;
    }
    collisionModel->GetBox(this: collisionModel, a2: (idBox *)&v48);
    v6 = idEntity::GetPhysics(this);
    v7 = (float *)v6->GetOrigin(this: v6, a2: 0);
    v8 = this->__vftable;
    v48 = *v7 + v48;
    v49 = v7[1] + v49;
    Debug_IsValid = v8->Debug_IsValid;
    v50 = v7[2] + v50;
    if ( Debug_IsValid(this) )
      v10 = &idColor::colorBlue;
    else
      v10 = &idColor::colorRed;
    g = v10->g;
    b = v10->b;
    a = v10->a;
    v51.x = v10->r;
    v51.y = g;
    v51.z = b;
    v51.w = a;
    v14 = gameLocal->GetRenderWorld(this: gameLocal);
    v14->DebugBox(this: v14, a2: &v51, a3: (const idBox *)&v48, a4: 0, a5: false);
    v15 = gameLocal->GetRenderWorld(this: gameLocal);
    ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v15->DebugText)(
      a1: v15,
      a2: this->name.data,
      a3: &v48,
      a4: v15->DebugText,
      a5: &idColor::colorWhite,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.30000001);
    v16 = 0;
    if ( this->debug_positions.num > 0 )
    {
      v17 = 0;
      do
      {
        GetRenderWorld = (int (*)(void))gameLocal->GetRenderWorld;
        if ( this->debug_positions.list[v17].obstructed )
        {
          v19 = GetRenderWorld();
          (*(void (__fastcall **)(int, idColor *, idSpawnArea::debugGenPos_t *, _DWORD, _DWORD))(*(_DWORD *)v19 + 256))(
            a1: v19,
            a2: &idColor::colorOrange,
            a3: &this->debug_positions.list[v17],
            a4: 0,
            a5: 0);
        }
        else
        {
          v20 = GetRenderWorld();
          (*(void (__fastcall **)(int, idColor *, idSpawnArea::debugGenPos_t *, _DWORD, _DWORD))(*(_DWORD *)v20 + 256))(
            a1: v20,
            a2: &idColor::colorWhite,
            a3: &this->debug_positions.list[v17],
            a4: 0,
            a5: 0);
          v21 = gameLocal->GetRenderWorld(this: gameLocal);
          v21->DebugPoint(
            this: v21,
            a2: (const idVec4 *)&idColor::colorCyan,
            a3: &this->debug_positions.list[v17].end,
            a4: 0,
            a5: false);
          v22 = gameLocal->GetRenderWorld(this: gameLocal);
          v22->DebugLine(
            this: v22,
            a2: (const idVec4 *)&idColor::colorCyan,
            a3: &this->debug_positions.list[v17].start,
            a4: &this->debug_positions.list[v17].end,
            a5: 0,
            a6: false);
        }
        ++v16;
        ++v17;
      }
      while ( v16 < this->debug_positions.num );
    }
    v23 = 0;
    if ( this->generatedPositions.num > 0 )
    {
      v24 = 0;
      do
      {
        v25 = gameLocal->GetRenderWorld(this: gameLocal);
        v25->DebugPoint(
          this: v25,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: &this->generatedPositions.list[v24].position,
          a4: 0,
          a5: false);
        ++v23;
        ++v24;
      }
      while ( v23 < this->generatedPositions.num );
    }
  }
  v26 = 0;
  if ( this->generatedPositions.num > 0 )
  {
    v27 = 0;
    do
    {
      v28 = &this->generatedPositions.list[v27];
      obstructionTimer = v28->obstructionTimer;
      if ( obstructionTimer > 0.0 )
      {
        v35 = 0.0;
        v38 = 1.0;
        v43 = 0.0;
        v40 = 0.0;
        v41 = 0.0;
        x = 0.0;
        v37 = 0.0;
        y = 0.0;
        v34 = 0.0;
        v36 = 0.0;
        v47[3] = 1.0;
        v45 = 0.0;
        v44 = 0.0;
        v47[2] = 1.0;
        v46 = 1.0;
        v47[0] = (float)obstructionTimer * (float)0.33333334;
        v47[1] = v47[0];
        v42 = 1.0;
        v39 = 0.0;
        x = v28->position.x;
        y = v28->position.y;
        v30 = (float)(v28->position.z + (float)16.0);
        v35 = 16.0;
        v36 = 16.0;
        v37 = 16.0;
        v34 = v30;
        v31 = gameLocal->GetRenderWorld(this: gameLocal);
        v31->DebugBox(this: v31, a2: (const idVec4 *)v47, a3: (const idBox *)&x, a4: 0, a5: false);
      }
      ++v26;
      ++v27;
    }
    while ( v26 < this->generatedPositions.num );
  }
}


// ========================================================================
// ?GetFacingTarget@idSpawnArea@@ABAPBVidEntity@@XZ
// EA  : 0x82EA8100
// RVA : 0x00EA8100
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

const idEntity *__fastcall idSpawnArea::GetFacingTarget(idSpawnArea *this)
{
  idGameLocal *v2; // r9
  idEntity *v3; // r3
  const idEntity *result; // r3
  int num; // r27
  int v6; // r29
  int i; // r31
  int value; // r10
  idEntity *v9; // r3

  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->facingTargetObj.spawnId.value & 0x1FFF] == this->facingTargetObj.spawnId.value >> 13 )
  {
    v3 = gameLocal->entities.ptr[this->facingTargetObj.spawnId.value & 0x1FFF];
    if ( v3 != nullptr )
      return idEntity::CastTo(c: v3);
    return nullptr;
  }
  num = this->targets.num;
  if ( num <= 0 )
    return nullptr;
  v6 = 0;
  for ( i = 0; ; ++i )
  {
    if ( v6 < this->targets.num
      && (value = this->targets.list[i].spawnId.value, v2->spawnIds.ptr[value & 0x1FFF] == value >> 13)
      && (v9 = v2->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      result = idEntity::CastTo(c: v9);
      v2 = gameLocal;
    }
    else
    {
      result = nullptr;
    }
    if ( result != nullptr )
      break;
    if ( ++v6 >= num )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ??1idSpawnNodeSplines@@UAA@XZ
// EA  : 0x82EA8200
// RVA : 0x00EA8200
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idSpawnNodeSplines::~idSpawnNodeSplines(idSpawnNodeSplines *this)
{
  int v2; // r28
  int v3; // r29
  idCurve_Spline<idVec3> *v4; // r3
  idCurve_Spline<idVec3> **list; // r4
  idCurve_Spline<idVec3> **v6; // r4
  idEntityPtr<idSplinePath> *v7; // r4

  this->__vftable = (idSpawnNodeSplines_vtbl *)&idSpawnNodeSplines::`vftable';
  v2 = 0;
  if ( this->splineCurves.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->splineCurves.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))v4->dtr_idCurve<idVec3>)(a1: v4, a2: 1);
      ++v2;
      ++v3;
    }
    while ( v2 < this->splineCurves.num );
  }
  if ( this->splineCurves.listStatic == 0 || this->splineCurves.listStatic == 2 )
  {
    list = this->splineCurves.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->splineCurves.list = nullptr;
    this->splineCurves.size = 0;
  }
  this->splineCurves.num = 0;
  if ( this->splineCurves.listStatic == 0 || this->splineCurves.listStatic == 2 )
  {
    v6 = this->splineCurves.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->splineCurves.list = nullptr;
    this->splineCurves.size = 0;
  }
  this->splineCurves.num = 0;
  if ( this->splinePaths.listStatic == 0 || this->splinePaths.listStatic == 2 )
  {
    v7 = this->splinePaths.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->splinePaths.list = nullptr;
    this->splinePaths.size = 0;
  }
  this->splinePaths.num = 0;
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$490839_1
// EA  : 0x82EA8340
// RVA : 0x00EA8340
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void _unwind_490839_1()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$490840_1
// EA  : 0x82EA8368
// RVA : 0x00EA8368
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void _unwind_490840_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 816));
}


// ========================================================================
// __unwind$490841_1
// EA  : 0x82EA8394
// RVA : 0x00EA8394
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void _unwind_490841_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 832));
}


// ========================================================================
// ?ReportBlockedLocation@idSpawnArea@@UAAXH@Z
// EA  : 0x82EA8540
// RVA : 0x00EA8540
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idSpawnArea::ReportBlockedLocation(idSpawnArea *this, int locationID)
{
  char v3; // r11
  idSpawnArea::GeneratedPosition *v4; // [sp+50h] [-20h] BYREF

  if ( locationID < 0 || (v3 = 1, locationID >= this->generatedPositions.num) )
    v3 = 0;
  if ( v3 != 0 )
  {
    this->generatedPositions.list[locationID].obstructionTimer = 3.0;
    v4 = &this->generatedPositions.list[locationID];
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->obstructedPositions,
      obj: (encounterGroupRole_t *)&v4);
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// ?Spawn@idSpawnNodeSplines@@QAAXXZ
// EA  : 0x82EA85D8
// RVA : 0x00EA85D8
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idSpawnNodeSplines::Spawn(idSpawnNodeSplines *this)
{
  int v2; // r28
  int v3; // r30
  idEntityPtr<idSplinePath> *v4; // r11
  int v5; // r11
  int v6; // r8
  idSplinePath *v7; // r3
  idSplinePath *v8; // r3
  idCurve_Spline<idVec3> *v9; // [sp+50h] [-40h] BYREF

  v2 = 0;
  if ( this->splinePaths.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->splinePaths.list[v3];
      if ( gameLocal->spawnIds.ptr[v4->spawnId.value & 0x1FFF] == v4->spawnId.value >> 13 )
      {
        v6 = v4->spawnId.value >> 13;
        v5 = v4->spawnId.value & 0x1FFF;
        if ( gameLocal->spawnIds.ptr[v5] == v6 && (v7 = (idSplinePath *)gameLocal->entities.ptr[v5]) != nullptr )
          v8 = idSplinePath::CastTo(c: v7);
        else
          v8 = nullptr;
        v9 = idSplinePath::AllocSpline(this: v8);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->splineCurves,
          obj: (encounterGroupRole_t *)&v9);
        this->totalLocationCount += this->splineCurves.list[v3]->values.num;
      }
      else
      {
        idLib::Warning(fmt: "Spawn Node Spline: %s has a NULL spline in its splinePaths list!", this->name.data);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->splinePaths.num );
  }
}


// ========================================================================
// ?GetValidSpawnLocations@idPlayerStart@@UAAXABVidGameplayFilterTarget@@ABW4gameTeam_t@@M_NAAV?$idList@VidSpawnLocation@@$04@@H@Z
// EA  : 0x82EA8A18
// RVA : 0x00EA8A18
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idPlayerStart::GetValidSpawnLocations(
        idPlayerStart *this,
        const idGameplayFilterTarget *userFilterTarget,
        const gameTeam_t *team,
        double userHalfSize,
        bool onlyInitial,
        idList<idSpawnLocation,5> *locations,
        idList<idSpawnLocation,5> *MAX_POSITIONS_RETURNED)
{
  gameTeam_t v7; // r11
  char v10; // r11
  bool v11; // zf
  idAngles *v12; // r10
  float pitch; // r31
  idList<idSpawnLocation,5> *v14; // r3
  float yaw; // r30
  float roll; // r10
  float x; // [sp+50h] [-60h]
  float y; // [sp+54h] [-5Ch]
  float v19; // [sp+58h] [-58h]
  idMat3 v20; // [sp+60h] [-50h] BYREF
  float v21; // [sp+84h] [-2Ch]
  float v22; // [sp+88h] [-28h]
  idPlayerStart *v23; // [sp+8Ch] [-24h]
  int v24; // [sp+90h] [-20h]
  float v25; // [sp+94h] [-1Ch]

  v7 = this->team;
  if ( v7 == *team || (v11 = v7 != TEAM_NONE, v10 = 0, !v11) )
    v10 = 1;
  if ( v10 != 0 && this->isActive && (_BYTE)locations != 0 && this->initial || (_BYTE)locations == 0 )
  {
    x = this->spawnPosition.x;
    y = this->spawnPosition.y;
    v19 = this->spawnPosition.z + (float)5.0;
    v12 = idMat3::ToAngles(this: &v20, result: (idAngles *)&this->spawnOrientation);
    v23 = this;
    pitch = v12->pitch;
    v14 = MAX_POSITIONS_RETURNED;
    yaw = v12->yaw;
    roll = v12->roll;
    v22 = 1.0;
    v20.mat[1].y = x;
    v25 = 0.0;
    v20.mat[1].z = y;
    v20.mat[2].y = pitch;
    v20.mat[2].x = v19;
    v24 = 0;
    v20.mat[2].z = yaw;
    v21 = roll;
    idList<idSpawnLocation,5>::Append(this: v14, obj: (const idSpawnLocation *)&v20.mat[1].y);
  }
}


// ========================================================================
// ?GetValidSpawnLocations@idSpawnPoint@@UAAXABVidGameplayFilterTarget@@ABW4gameTeam_t@@M_NAAV?$idList@VidSpawnLocation@@$04@@H@Z
// EA  : 0x82EA8B40
// RVA : 0x00EA8B40
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idSpawnPoint::GetValidSpawnLocations(
        idSpawnPoint *this,
        const idGameplayFilterTarget *userFilterTarget,
        const gameTeam_t *team,
        double userHalfSize,
        bool onlyInitial,
        idList<idSpawnLocation,5> *locations,
        idList<idSpawnLocation,5> *MAX_POSITIONS_RETURNED)
{
  gameTeam_t v7; // r11
  char v10; // r11
  bool v11; // zf
  idAngles *v12; // r10
  float pitch; // r31
  idList<idSpawnLocation,5> *v14; // r3
  float yaw; // r30
  float roll; // r10
  float x; // [sp+50h] [-60h]
  float y; // [sp+54h] [-5Ch]
  float v19; // [sp+58h] [-58h]
  idMat3 v20; // [sp+60h] [-50h] BYREF
  float v21; // [sp+84h] [-2Ch]
  float v22; // [sp+88h] [-28h]
  idSpawnPoint *v23; // [sp+8Ch] [-24h]
  int v24; // [sp+90h] [-20h]
  float v25; // [sp+94h] [-1Ch]

  v7 = this->team;
  if ( v7 == *team || (v11 = v7 != TEAM_NONE, v10 = 0, !v11) )
    v10 = 1;
  if ( v10 != 0 )
  {
    x = this->spawnPosition.x;
    y = this->spawnPosition.y;
    v19 = this->spawnPosition.z + (float)5.0;
    v12 = idMat3::ToAngles(this: &v20, result: (idAngles *)&this->spawnOrientation);
    v23 = this;
    pitch = v12->pitch;
    v14 = MAX_POSITIONS_RETURNED;
    yaw = v12->yaw;
    roll = v12->roll;
    v22 = 1.0;
    v20.mat[1].y = x;
    v25 = 0.0;
    v20.mat[1].z = y;
    v20.mat[2].y = pitch;
    v20.mat[2].x = v19;
    v24 = 0;
    v20.mat[2].z = yaw;
    v21 = roll;
    idList<idSpawnLocation,5>::Append(this: v14, obj: (const idSpawnLocation *)&v20.mat[1].y);
  }
}


// ========================================================================
// ?Spawn@idSpawnArea@@QAAXXZ
// EA  : 0x82EA8C38
// RVA : 0x00EA8C38
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idSpawnArea::Spawn(idSpawnArea *this)
{
  idPhysics *Physics; // r3
  idClipModel *v3; // r3
  idCollisionModel *collisionModel; // r3
  idPhysics *v5; // r3
  float *v6; // r3
  __int64 v7; // r5
  int v8; // r3
  double v9; // fp13
  double v10; // fp0
  double v11; // fp12
  double v12; // fp13
  double v13; // fp12
  double v14; // fp13
  int v15; // ctr
  int v16; // r30
  unsigned int v17; // r11
  double z; // fp11
  int v19; // r6
  double y; // fp12
  double x; // fp13
  int v22; // r7
  float *v23; // r10
  float *p_x; // r9
  double v25; // fp4
  double v26; // fp0
  double v27; // fp6
  double v28; // fp1
  int v29; // r10
  double v30; // fp0
  double v31; // fp6
  double v32; // fp5
  double v33; // fp7
  double v34; // fp2
  double v35; // fp1
  double v36; // fp0
  float *v37; // r11
  double v38; // fp0
  double v39; // fp10
  double v40; // fp9
  double v41; // fp28
  double distanceFromEdge; // fp27
  double v43; // fp26
  double obstructionTimer; // fp25
  double v45; // fp24
  int listStatic; // r11
  double v47; // fp23
  idList<idSpawnArea::GeneratedPosition,5> *p_generatedPositions; // r21
  double v49; // fp21
  double v50; // fp20
  double v51; // fp19
  double v52; // fp18
  idList<idSpawnArea::debugGenPos_t,5> *p_debug_positions; // r22
  int v54; // r17
  int v55; // r20
  int v56; // r18
  int v57; // r23
  _BYTE v58[12]; // r11
  int v59; // r28
  double v60; // fp31
  double v61; // fp30
  idClipModel *clip32x32; // r7
  double v65; // fp29
  float v66; // r30
  float v67; // r29
  double v68; // fp17
  BOOL v69; // r31
  double v70; // fp17
  const char *v71; // [sp+8h] [-308h]
  int v72; // [sp+Ch] [-304h]
  const char *v73; // [sp+10h] [-300h]
  int v74; // [sp+14h] [-2FCh]
  double v75; // [sp+18h] [-2F8h]
  double v76; // [sp+20h] [-2F0h]
  double v77; // [sp+28h] [-2E8h]
  int v78; // [sp+30h] [-2E0h]
  int v79; // [sp+34h] [-2DCh]
  int v80; // [sp+38h] [-2D8h]
  int v81; // [sp+3Ch] [-2D4h]
  int v82; // [sp+40h] [-2D0h]
  int v83; // [sp+44h] [-2CCh]
  int v84; // [sp+48h] [-2C8h]
  int v85; // [sp+4Ch] [-2C4h]
  int v86; // [sp+50h] [-2C0h]
  int v87; // [sp+58h] [-2B8h]
  int v88; // [sp+60h] [-2B0h]
  idVec3 center; // [sp+70h] [-2A0h] BYREF
  float v90; // [sp+80h] [-290h] BYREF
  int v91; // [sp+84h] [-28Ch]
  idSpawnArea::GeneratedPosition v92; // [sp+90h] [-280h] BYREF
  float v93; // [sp+A4h] [-26Ch]
  __int64 v94; // [sp+A8h] [-268h]
  double v95; // [sp+B0h] [-260h]
  _DWORD v96[2]; // [sp+B8h] [-258h] BYREF
  idBox v97; // [sp+C0h] [-250h] BYREF
  idVec3 v98; // [sp+100h] [-210h] BYREF
  float v99; // [sp+110h] [-200h] BYREF
  float v100; // [sp+114h] [-1FCh] BYREF
  float v101[4]; // [sp+118h] [-1F8h] BYREF
  idVec3 v102; // [sp+128h] [-1E8h] BYREF
  idSpawnArea::debugGenPos_t v103; // [sp+140h] [-1D0h] BYREF
  char v104; // [sp+160h] [-1B0h] BYREF
  trace_t v105[2]; // [sp+170h] [-1A0h] BYREF

  Physics = idEntity::GetPhysics(this);
  v3 = Physics->GetClipModel(this: Physics, a2: 0);
  if ( v3->collisionModel != nullptr )
  {
    collisionModel = v3->collisionModel;
  }
  else if ( v3->traceModels.num <= 0 )
  {
    collisionModel = idClipModel::NoTraceModelWarning(this: v3);
  }
  else
  {
    collisionModel = v3->clip->traceModelCache->cache.list[*v3->traceModels.list]->collisionModel;
  }
  collisionModel->GetBox(this: collisionModel, a2: &v97);
  v5 = idEntity::GetPhysics(this);
  v6 = (float *)v5->GetOrigin(this: v5, a2: 0);
  HIDWORD(v7) = 0;
  v97.center.x = *v6 + v97.center.x;
  v9 = (float)((float)((float)(v97.axis.mat[0].x + v97.axis.mat[0].y) * (float)0.0) + v97.axis.mat[0].z);
  v97.center.y = v6[1] + v97.center.y;
  v10 = 0.0;
  v11 = __fabs(v9);
  v97.center.z = v6[2] + v97.center.z;
  v8 = 0;
  if ( v11 > 0.0 )
  {
    v10 = v11;
    HIDWORD(v7) = v9 < 0.0;
  }
  v12 = (float)((float)((float)(v97.axis.mat[1].x + v97.axis.mat[1].y) * (float)0.0) + v97.axis.mat[1].z);
  v13 = __fabs(v12);
  if ( v13 > v10 )
  {
    v8 = 1;
    v10 = v13;
    HIDWORD(v7) = v12 < 0.0;
  }
  v14 = (float)((float)((float)(v97.axis.mat[2].x + v97.axis.mat[2].y) * (float)0.0) + v97.axis.mat[2].z);
  if ( __fabs(v14) > v10 )
  {
    v8 = 2;
    HIDWORD(v7) = v14 < 0.0;
  }
  if ( v8 == 0 )
  {
    LODWORD(v90) = 1;
    goto LABEL_17;
  }
  if ( v8 == 1 )
  {
    v90 = 0.0;
LABEL_17:
    v91 = 2;
    goto LABEL_18;
  }
  v90 = 0.0;
  v91 = 1;
LABEL_18:
  v15 = 2;
  v16 = 1;
  v17 = 0;
  center = v97.center;
  z = v97.center.z;
  v19 = 0;
  y = v97.center.y;
  x = v97.center.x;
  do
  {
    v22 = *(_DWORD *)((char *)&v90 + v19 * 4);
    v23 = &v101[v17 / 4 - 1];
    p_x = &v97.axis.mat[v22].x;
    v25 = *p_x;
    *(float *)((char *)&v99 + v17) = *p_x;
    v26 = *(&v97.extents.x + v22);
    v27 = p_x[2];
    v28 = (float)(p_x[1] * *(&v97.extents.x + v22));
    *v23 = p_x[1];
    v23[1] = v27;
    v23[1] = (float)v27 * (float)v26;
    *v23 = v28;
    *(float *)((char *)&v99 + v17) = (float)v25 * (float)v26;
    v101[v17 / 4] = 0.0;
    x = (float)((float)x - (float)((float)((float)v26 - (float)16.0) * *p_x));
    y = (float)((float)y - (float)(p_x[1] * (float)((float)v26 - (float)16.0)));
    z = (float)((float)z - (float)(p_x[2] * (float)((float)v26 - (float)16.0)));
    LODWORD(v28) = (int)(float)((float)((float)__fsqrts((float)((float)(v23[1] * v23[1])
                                                              + (float)((float)(*(float *)((char *)&v99 + v17)
                                                                              * *(float *)((char *)&v99 + v17))
                                                                      + (float)(*v23 * *v23))))
                                      * (float)2.0)
                              * (float)0.03125);
    LODWORD(v95) = LODWORD(v28);
    v29 = LODWORD(v28);
    v96[v19] = LODWORD(v28);
    if ( SLODWORD(v28) < 1 )
      v29 = 1;
    v96[v19] = v29;
    if ( v29 <= 1 )
    {
      *(float *)((char *)&v92.position.z + v17) = 0.0;
      *(float *)((char *)&v92.position.x + v17) = 0.0;
      *(float *)((char *)&v92.position.y + v17) = 0.0;
    }
    else
    {
      LODWORD(v7) = v29 - 1;
      v30 = (float)((float)((float)v26 * (float)2.0) - (float)32.0);
      v31 = p_x[2];
      v32 = p_x[1];
      v33 = *p_x;
      v34 = (float)(p_x[2] * (float)v30);
      v94 = v7;
      *(float *)((char *)&v92.position.z + v17) = (float)v31 * (float)v30;
      v35 = (float)((float)v32 * (float)v30);
      *(float *)((char *)&v92.position.y + v17) = (float)v32 * (float)v30;
      v36 = (float)((float)v33 * (float)v30);
      *(float *)((char *)&v92.position.x + v17) = v36;
      *(float *)((char *)&v92.position.x + v17) = (float)v36 * (float)((float)1.0 / (float)v7);
      *(float *)((char *)&v92.position.y + v17) = (float)v35 * (float)((float)1.0 / (float)v7);
      *(float *)((char *)&v92.position.z + v17) = (float)((float)1.0 / (float)v7) * (float)v34;
    }
    v16 *= v29;
    v17 += 12;
    ++v19;
    --v15;
  }
  while ( v15 != 0 );
  v37 = &v97.axis.mat[v8].x;
  v38 = (float)((float)(*(&v97.extents.x + v8) - (float)16.0) * *v37);
  v39 = (float)(v37[1] * (float)(*(&v97.extents.x + v8) - (float)16.0));
  v40 = (float)(v37[2] * (float)(*(&v97.extents.x + v8) - (float)16.0));
  if ( BYTE3(v7) != 0 )
  {
    v38 = (float)((float)((float)(*(&v97.extents.x + v8) - (float)16.0) * *v37) * (float)-1.0);
    v39 = (float)((float)(v37[1] * (float)(*(&v97.extents.x + v8) - (float)16.0)) * (float)-1.0);
    v40 = (float)((float)(v37[2] * (float)(*(&v97.extents.x + v8) - (float)16.0)) * (float)-1.0);
  }
  v41 = v92.position.y;
  distanceFromEdge = v92.distanceFromEdge;
  v43 = v92.position.x;
  obstructionTimer = v92.obstructionTimer;
  v45 = v92.position.z;
  listStatic = this->generatedPositions.listStatic;
  v47 = v93;
  p_generatedPositions = &this->generatedPositions;
  v49 = (float)((float)v38 + (float)x);
  v50 = (float)((float)v39 + (float)y);
  v51 = (float)((float)v40 + (float)z);
  v90 = __fsqrts((float)((float)(v92.position.z * v92.position.z)
                       + (float)((float)(v92.position.x * v92.position.x) + (float)(v92.position.y * v92.position.y))));
  v52 = __fsqrts((float)((float)(v93 * v93)
                       + (float)((float)(v92.obstructionTimer * v92.obstructionTimer)
                               + (float)(v92.distanceFromEdge * v92.distanceFromEdge))));
  if ( listStatic == 0 || listStatic == 2 )
  {
    if ( p_generatedPositions->list != nullptr )
      idMem::Free(this: &mem, ptr: p_generatedPositions->list, align: ALIGN_16);
    p_generatedPositions->list = nullptr;
    this->generatedPositions.size = 0;
  }
  this->generatedPositions.num = 0;
  if ( v16 > this->generatedPositions.size )
    idList<idSpawnArea::GeneratedPosition,5>::Resize(this: &this->generatedPositions, newsize: v16);
  p_debug_positions = &this->debug_positions;
  if ( this->debug_positions.listStatic == 0 || this->debug_positions.listStatic == 2 )
  {
    if ( p_debug_positions->list != nullptr )
      idMem::Free(this: &mem, ptr: p_debug_positions->list, align: ALIGN_16);
    p_debug_positions->list = nullptr;
    this->debug_positions.size = 0;
  }
  v54 = v96[0];
  v55 = 0;
  this->debug_positions.num = 0;
  v56 = 0;
  if ( v54 > 0 )
  {
    *(_DWORD *)v58 = &unk_82150000;
    v57 = v96[1];
    *(_DWORD *)&v58[4] = &si_vector_decode_cat_0[184];
    do
    {
      v59 = 0;
      if ( v57 > 0 )
      {
        *(_DWORD *)&v58[8] = v56;
        v94 = *(_QWORD *)&v58[4];
        v60 = (float)*(__int64 *)&v58[4];
        v61 = (float)((float)*(__int64 *)&v58[4] * v90);
        do
        {
          *(_DWORD *)&v58[4] = v59;
          v95 = *(double *)v58;
          v103.obstructed = true;
          _FP1 = (float)((float)v61 - (float)((float)*(__int64 *)v58 * (float)v52));
          v100 = (float)((float)((float)v41 * (float)v60) + (float)((float)distanceFromEdge * (float)*(__int64 *)v58))
               + (float)v50;
          v101[0] = (float)((float)((float)v45 * (float)v60) + (float)((float)v47 * (float)*(__int64 *)v58))
                  + (float)v51;
          v99 = (float)((float)((float)v43 * (float)v60) + (float)((float)obstructionTimer * (float)*(__int64 *)v58))
              + (float)v49;
          v102.y = v100;
          v98.x = v99;
          v102.x = v99;
          v102.z = v101[0] - (float)1000.0;
          v98.y = v100;
          __asm { fsel      f11, f1, f5, f30 }
          v98.z = v101[0];
          v103.start.x = v99;
          clip32x32 = clientGame->clip.clip32x32;
          v103.start.y = v100;
          v103.start.z = v101[0];
          v65 = (float)((float)_FP11 + (float)16.0);
          idClip::Contents(
            this: (idClip *)v96,
            result: &clientGame->clip,
            a3: v105,
            start: &v98,
            clipModel: clip32x32,
            startAxis: &mat3_identity,
            clipMask: 1,
            passEntityNumber: -1,
            userName: v71,
            a10: v72,
            a11: (int)v73,
            a12: v74,
            a13: SHIDWORD(v75),
            a14: SLODWORD(v75),
            a15: SHIDWORD(v76),
            a16: SLODWORD(v76),
            a17: SHIDWORD(v77),
            a18: SLODWORD(v77),
            a19: v78,
            a20: v79,
            a21: v80,
            a22: v81,
            a23: v82,
            a24: v83,
            a25: v84,
            a26: v85,
            a27: v86,
            a28: 0);
          if ( v105[0].c.type == CONTACT_NONE )
          {
            idClip::Translation(
              this: (idClip *)&v104,
              result: &clientGame->clip,
              a3: v105,
              start: &v98,
              end: &v102,
              clipModel: clientGame->clip.clip32x32,
              startAxis: &mat3_identity,
              clipMask: 1,
              passEntityNumber: (int)v71,
              moveClipModel: v72,
              userName: v73,
              a12: v74,
              a13: SHIDWORD(v75),
              a14: SLODWORD(v75),
              a15: SHIDWORD(v76),
              a16: SLODWORD(v76),
              a17: SHIDWORD(v77),
              a18: SLODWORD(v77),
              a19: v78,
              a20: v79,
              a21: v80,
              a22: v81,
              a23: v82,
              a24: v83,
              a25: v84,
              a26: v85,
              a27: v86,
              a28: -1,
              a29: v87,
              a30: false,
              a31: v88,
              a32: 0);
            v66 = v105[0].endpos.x;
            v67 = v105[0].endpos.y;
            v68 = (float)((float)(v105[0].endpos.z - (float)16.0) - (float)1.0);
            center.z = (float)(v105[0].endpos.z - (float)16.0) - (float)1.0;
            center.x = v105[0].endpos.x;
            center.y = v105[0].endpos.y;
            v69 = v105[0].fraction < 1.0;
            if ( v105[0].fraction >= 1.0 || (unsigned __int8)idBox::ContainsPoint(this: &v97, p: &center) != 0 )
            {
              if ( v69 )
              {
                v75 = v97.center.x;
                v76 = v97.center.y;
                v77 = v97.center.z;
                idLib::Warning(
                  fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v97.center.x)),
                  (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v97.center.y)),
                  v97.center.z);
                ++v55;
              }
            }
            else
            {
              v70 = (float)((float)v68 + (float)1.0);
              center.z = v70;
              v92.obstructionTimer = 0.0;
              v92.distanceFromEdge = v65;
              v92.position.x = v66;
              v92.position.y = v67;
              v92.position.z = center.z;
              idList<idSpawnArea::GeneratedPosition,5>::Append(this: &this->generatedPositions, obj: &v92);
              v103.obstructed = false;
              v103.end.x = center.x;
              v103.end.y = center.y;
              v103.end.z = v70;
            }
          }
          idList<idSpawnArea::debugGenPos_t,5>::Append(this: &this->debug_positions, obj: &v103);
          ++v59;
        }
        while ( v59 < v57 );
      }
      ++v56;
    }
    while ( v56 < v54 );
    if ( v55 > 0 )
      idLib::Warning(fmt: "Total invalid generated positions: %d", v55);
  }
  if ( this->generatedPositions.num <= 0 )
    idLib::Warning(
      fmt: "Spawn Node (%s) did not generate any locations.  Is it entirely colliding with static geometry?",
      this->name.data);
  idSpawnArea::RandomizeGeneratedPositions(this);
}


// ========================================================================
// ?GetValidSpawnLocations@idSpawnArea@@UAAXABVidGameplayFilterTarget@@ABW4gameTeam_t@@M_NAAV?$idList@VidSpawnLocation@@$04@@H@Z
// EA  : 0x82EA93F8
// RVA : 0x00EA93F8
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idSpawnArea::GetValidSpawnLocations(
        idSpawnArea *this,
        const idGameplayFilterTarget *userFilterTarget,
        const gameTeam_t *team,
        double userHalfSize,
        bool onlyInitial,
        idList<idSpawnLocation,5> *locations,
        idList<idSpawnLocation,5> *MAX_POSITIONS_RETURNED,
        int a8)
{
  gameTeam_t v8; // r11
  char v13; // r11
  bool v14; // zf
  int v15; // r30
  int i; // r29
  signed int num; // r9
  int v18; // r8
  idSpawnArea::GeneratedPosition *list; // r10
  float *p_x; // r11
  idSpawnNode::nodeType_t nodeType; // r10
  double v22; // fp30
  double v23; // fp29
  double v24; // fp28
  double v25; // fp0
  idEntity *FacingTarget; // r3
  idPhysics *Physics; // r3
  float *v28; // r3
  double v29; // fp12
  double v30; // fp10
  idVec3 v31; // [sp+50h] [-B0h] BYREF
  idVec3 v32; // [sp+60h] [-A0h] BYREF
  idSpawnLocation v33; // [sp+70h] [-90h] BYREF

  v8 = this->team;
  if ( v8 == *team || (v14 = v8 != TEAM_NONE, v13 = 0, !v14) )
    v13 = 1;
  if ( v13 != 0 )
  {
    v15 = 0;
    for ( i = 0; i < this->generatedPositions.num; ++i )
    {
      if ( i >= a8 )
        break;
      num = this->generatedPositions.num;
      v18 = this->lastPositionUsed + i;
      list = this->generatedPositions.list;
      __twllei(num, 0);
      v15 = v18 % num;
      __twlgei(num & ~(__ROL4__(v18, 1) - 1), 0xFFFFFFFF);
      p_x = &list[v18 % num].position.x;
      if ( p_x[3] <= 0.0 && p_x[4] >= userHalfSize )
      {
        nodeType = this->nodeType;
        v22 = *p_x;
        v23 = p_x[1];
        v24 = p_x[2];
        v33.pos.x = *p_x;
        v33.pos.y = v23;
        v33.pos.z = v24;
        v33.sortValue = 0.0;
        if ( nodeType != TYPE_STANDARD )
          v25 = 0.0099999998;
        else
          v25 = 1.0;
        v33.valueModifier = v25;
        FacingTarget = (idEntity *)idSpawnArea::GetFacingTarget(this);
        if ( FacingTarget != nullptr )
        {
          Physics = idEntity::GetPhysics(this: FacingTarget);
          v28 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v29 = (float)(v28[2] - (float)v24);
          v30 = (float)(v28[1] - (float)v23);
          v31.x = *v28 - (float)v22;
          v31.z = v29;
          v31.y = v30;
          idVec3::NormalizeFast(this: &v31);
          idVec3::ToAngles(this: &v32, result: (idAngles *)&v31);
          v32.x = 0.0;
          v32.z = 0.0;
          v33.facing.yaw = v32.y;
        }
        else
        {
          v33.facing.yaw = this->yaw;
        }
        v33.facing.roll = 0.0;
        v33.locationID = v15;
        v33.facing.pitch = 0.0;
        v33.sourceNode = this;
        idList<idSpawnLocation,5>::Append(this: MAX_POSITIONS_RETURNED, obj: &v33);
      }
    }
    this->lastPositionUsed = v15;
  }
}


// ========================================================================
// ?GetValidSpawnLocations@idSpawnNodeSplines@@UAAXABVidGameplayFilterTarget@@ABW4gameTeam_t@@M_NAAV?$idList@VidSpawnLocation@@$04@@H@Z
// EA  : 0x82EA95D0
// RVA : 0x00EA95D0
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.cpp
// ========================================================================

void __fastcall idSpawnNodeSplines::GetValidSpawnLocations(
        idSpawnNodeSplines *this,
        const idGameplayFilterTarget *userFilterTarget,
        const gameTeam_t *team,
        double userHalfSize,
        bool onlyInitial,
        idList<idSpawnLocation,5> *locations,
        idList<idSpawnLocation,5> *MAX_POSITIONS_RETURNED)
{
  gameTeam_t v7; // r11
  char v10; // r11
  bool v11; // zf
  int v12; // r27
  int v13; // r24
  int v14; // r28
  int num; // r31
  int v16; // r30
  idCurve_Spline<idVec3> *v17; // r4
  double v18; // fp27
  idCurve_Spline<idVec3> **list; // r7
  double v22; // fp6
  double v23; // fp11
  double v24; // fp8
  idCurve_Spline<idVec3> *v25; // r23
  idAngles *v26; // r22
  int v27; // r3
  float pitch; // r10
  float yaw; // r9
  float roll; // r8
  float v31; // r7
  float v32; // r6
  float v33; // r5
  idAngles v34; // [sp+50h] [-E0h] BYREF
  idVec3 v35; // [sp+60h] [-D0h] BYREF
  char v36; // [sp+70h] [-C0h] BYREF
  idSpawnLocation v37; // [sp+80h] [-B0h] BYREF

  v7 = this->team;
  if ( v7 == *team || (v11 = v7 != TEAM_NONE, v10 = 0, !v11) )
    v10 = 1;
  if ( v10 != 0 )
  {
    v12 = 0;
    v13 = 0;
    if ( this->splinePaths.num > 0 )
    {
      v14 = 0;
      do
      {
        num = this->splineCurves.list[v14]->values.num;
        if ( num > 0 )
        {
          v16 = 0;
          do
          {
            v17 = this->splineCurves.list[v14];
            v18 = v17->times.list[v16];
            ((void (__fastcall *)(idAngles *, double))v17->GetCurrentFirstDerivative)(a1: &v34, a2: v18);
            list = this->splineCurves.list;
            _FP9 = (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f7, f9, f10, f13 }
            v22 = __frsqrte(_FP7);
            v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                                * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5))
                                                                                        * (float)v22)
                                                                                - (float)1.5)
                                                                * (float)v22)
                                                        * (float)((float)((float)(v34.pitch * v34.pitch)
                                                                        + (float)(v34.yaw * v34.yaw))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v22
                                                                * (float)((float)((float)(v34.pitch * v34.pitch)
                                                                                + (float)(v34.yaw * v34.yaw))
                                                                        * (float)0.5))
                                                        * (float)v22)
                                                - (float)1.5)
                                * (float)v22));
            v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                                * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                * (float)v22))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5))
                                                                                                * (float)v22)
                                                                                        - (float)1.5)
                                                                        * (float)v22))
                                                        * (float)((float)((float)(v34.pitch * v34.pitch)
                                                                        + (float)(v34.yaw * v34.yaw))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                * (float)v22)
                                                                                        * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                        * (float)v22))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                                * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5))
                                                                                        * (float)v22)
                                                                                - (float)1.5)
                                                                * (float)v22)))
                                        - (float)1.5)
                        * (float)v23);
            v34.pitch = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22) * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5)) * (float)v22)
                                                                                              - (float)1.5)
                                                                              * (float)v22))
                                                              * (float)((float)((float)(v34.pitch * v34.pitch)
                                                                              + (float)(v34.yaw * v34.yaw))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                              * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                              * (float)v22))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v34.pitch * v34.pitch) + (float)(v34.yaw * v34.yaw)) * (float)0.5))
                                                                                              * (float)v22)
                                                                                      - (float)1.5)
                                                                      * (float)v22)))
                                              - (float)1.5)
                              * (float)v23)
                      * v34.pitch;
            v34.yaw = (float)v24 * v34.yaw;
            v34.roll = (float)v24 * (float)0.0;
            v25 = list[v14];
            v26 = idVec3::ToAngles(this: &v35, result: &v34);
            v27 = (int)v25->GetCurrentValue(this: (struct idCurve_Spline<idVec3> *)&v36, result: (idVec3 *)v25, a3: v18);
            pitch = v26->pitch;
            yaw = v26->yaw;
            v37.valueModifier = 1.0;
            roll = v26->roll;
            v37.sortValue = 0.0;
            v37.sourceNode = this;
            v37.locationID = v12;
            v31 = *(float *)v27;
            v32 = *(float *)(v27 + 4);
            v33 = *(float *)(v27 + 8);
            v37.facing.pitch = pitch;
            v37.facing.yaw = yaw;
            v37.facing.roll = roll;
            v37.pos.x = v31;
            v37.pos.y = v32;
            v37.pos.z = v33;
            idList<idSpawnLocation,5>::Append(this: MAX_POSITIONS_RETURNED, obj: &v37);
            --num;
            ++v12;
            ++v16;
          }
          while ( num != 0 );
        }
        ++v13;
        ++v14;
      }
      while ( v13 < this->splinePaths.num );
    }
  }
}

