
// ========================================================================
// ?GetBounds@idAIEventTrace@@QBAABVidBounds@@XZ
// EA  : 0x82A465F8
// RVA : 0x00A465F8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventtrace.cpp
// ========================================================================

const idBounds *__fastcall idAIEventTrace::GetBounds(idAIEventTrace *this)
{
  const idDeclAiEvent *eventDecl; // r11

  eventDecl = this->eventDecl;
  if ( eventDecl != nullptr )
    return &eventDecl->bounds;
  if ( (_S18_2 & 1) == 0 )
    _S18_2 |= 1u;
  bounds_0.b[0].z = 1.0e30;
  bounds_0.b[0].y = 1.0e30;
  bounds_0.b[0].x = 1.0e30;
  bounds_0.b[1].z = -1.0e30;
  bounds_0.b[1].y = -1.0e30;
  bounds_0.b[1].x = -1.0e30;
  return &bounds_0;
}


// ========================================================================
// ?GetDistance@idAIEventTrace@@UBAMXZ
// EA  : 0x82A46660
// RVA : 0x00A46660
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventtrace.cpp
// ========================================================================

float __fastcall idAIEventTrace::GetDistance(idAIEventTrace *this)
{
  const idDeclAiEvent *eventDecl; // r11
  double distance; // fp1

  eventDecl = this->eventDecl;
  if ( eventDecl != nullptr )
    distance = eventDecl->distance;
  else
    distance = 0.0;
  return *((float *)&distance + 1);
}


// ========================================================================
// ??0idAIEventTrace@@QAA@XZ
// EA  : 0x82A46680
// RVA : 0x00A46680
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventtrace.cpp
// ========================================================================

idAIEventTrace *__fastcall idAIEventTrace::idAIEventTrace(idAIEventTrace *this)
{
  idAIEvent::idAIEvent(this);
  this->__vftable = (idAIEventTrace_vtbl *)&idAIEventTrace::`vftable';
  this->dir = vec3_origin;
  this->traceQuery.index = 0xFFFFFFFF00000000uLL;
  this->lastTraceFrame = -1;
  memset(Dst: &this->lastTraceResult, Val: 0, Size: sizeof(this->lastTraceResult));
  this->lastTraceResult.fraction = 1.0;
  return this;
}


// ========================================================================
// ?InternalDrawDebug@idAIEventTrace@@MBAXHHH@Z
// EA  : 0x82A46708
// RVA : 0x00A46708
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventtrace.cpp
// ========================================================================

void __fastcall idAIEventTrace::InternalDrawDebug(idAIEventTrace *this, int level, const int curTime, int duration)
{
  int v6; // r26
  double v7; // fp1
  double v8; // fp30
  idVec3 *p_dir; // r30
  double z; // fp8
  double v11; // fp5
  double v12; // fp3
  int GameMsPerFrame; // r3
  double x; // fp9
  double y; // fp8
  double v16; // fp7
  idVec3 *p_gravity; // r9
  double v18; // fp10
  double v19; // fp2
  double v20; // fp12
  double v21; // fp10
  double v22; // fp4
  double v24; // fp10
  double v26; // fp2
  double v27; // fp2
  double v28; // fp11
  double v29; // fp10
  double v30; // fp12
  double v31; // fp3
  double v32; // fp2
  double v33; // fp1
  double v34; // fp12
  double v37; // fp4
  double v38; // fp5
  double v39; // fp4
  const idBounds *Bounds; // r3
  double v41; // fp6
  float *v42; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  float v45[4]; // [sp+50h] [-100h] BYREF
  float v46[6]; // [sp+60h] [-F0h] BYREF
  float v47; // [sp+78h] [-D8h]
  float v48; // [sp+7Ch] [-D4h]
  float v49; // [sp+80h] [-D0h]
  float v50[6]; // [sp+88h] [-C8h] BYREF
  float v51[4]; // [sp+A0h] [-B0h] BYREF
  float v52[4]; // [sp+B0h] [-A0h] BYREF
  float v53[3]; // [sp+C0h] [-90h] BYREF
  float v54; // [sp+CCh] [-84h] BYREF
  float v55[16]; // [sp+D0h] [-80h] BYREF

  if ( duration <= 0 )
    v6 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  else
    v6 = duration;
  v7 = ((double (__fastcall *)(idAIEventTrace *))this->GetDistance)(a1: this);
  v8 = (float)((float)v7 * this->lastTraceResult.fraction);
  p_dir = &this->dir;
  z = this->origin.z;
  v11 = (float)(this->dir.z * (float)((float)v7 * this->lastTraceResult.fraction));
  v12 = (float)((float)(this->dir.y * (float)((float)v7 * this->lastTraceResult.fraction)) + this->origin.y);
  v45[0] = this->origin.x + (float)(this->dir.x * (float)((float)v7 * this->lastTraceResult.fraction));
  v45[1] = v12;
  v45[2] = (float)v11 + (float)z;
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v52[0] = 1.0;
  v52[1] = 0.5;
  v52[2] = 0.0;
  v52[3] = 1.0;
  clientGame->renderWorld->DebugPoint(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)v52,
    a3: (const idVec3 *)v45,
    a4: GameMsPerFrame,
    a5: true);
  v51[0] = 1.0;
  v51[1] = 0.0;
  v51[2] = 0.0;
  v51[3] = 1.0;
  clientGame->renderWorld->DebugLine(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)v51,
    a3: &this->origin,
    a4: (const idVec3 *)v45,
    a5: v6,
    a6: true);
  if ( level > 1 )
  {
    x = p_dir->x;
    y = this->dir.y;
    v16 = this->dir.z;
    p_gravity = &gameLocal->clientGame.gravity;
    v18 = this->origin.z;
    v19 = (float)(this->dir.z * (float)((float)v8 * (float)0.5));
    v20 = (float)((float)(this->dir.y * (float)((float)v8 * (float)0.5)) + this->origin.y);
    v50[0] = this->origin.x + (float)(p_dir->x * (float)((float)v8 * (float)0.5));
    v50[1] = v20;
    v50[2] = (float)v19 + (float)v18;
    v21 = (float)(p_gravity->x * p_gravity->x);
    v47 = p_gravity->x;
    v22 = (float)((float)(p_gravity->y * p_gravity->y) + (float)v21);
    v48 = p_gravity->y;
    _FP1 = (float)((float)((float)(p_gravity->z * p_gravity->z) + (float)v22) - idMath::FLT_SMALLEST_NON_DENORMAL);
    v24 = (float)((float)((float)(p_gravity->z * p_gravity->z) + (float)v22) * (float)0.5);
    __asm { fsel      f4, f1, f2, f13 }
    v26 = __frsqrte(_FP4);
    v27 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)v24) * (float)v26) - (float)1.5)
                                                                                                * (float)v26)
                                                                                        * (float)v24)
                                                                                * (float)((float)-(float)((float)((float)((float)v26 * (float)v24) * (float)v26) - (float)1.5)
                                                                                        * (float)v26))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v26 * (float)v24)
                                                                                        * (float)v26)
                                                                                - (float)1.5)
                                                                * (float)v26))
                                                * (float)v24)
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)v24) * (float)v26) - (float)1.5)
                                                                                        * (float)v26)
                                                                                * (float)v24)
                                                                        * (float)((float)-(float)((float)((float)((float)v26 * (float)v24) * (float)v26)
                                                                                                - (float)1.5)
                                                                                * (float)v26))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v26 * (float)v24)
                                                                                * (float)v26)
                                                                        - (float)1.5)
                                                        * (float)v26)))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)v24)
                                                                                        * (float)v26)
                                                                                - (float)1.5)
                                                                * (float)v26)
                                                        * (float)v24)
                                                * (float)((float)-(float)((float)((float)((float)v26 * (float)v24)
                                                                                * (float)v26)
                                                                        - (float)1.5)
                                                        * (float)v26))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v26 * (float)v24) * (float)v26) - (float)1.5)
                                * (float)v26)));
    v28 = (float)(v48 * (float)v27);
    v29 = (float)(p_gravity->z * (float)v27);
    v30 = (float)(v47 * (float)v27);
    v31 = (float)((float)((float)x * (float)(v47 * (float)v27))
                + (float)((float)((float)v16 * (float)(p_gravity->z * (float)v27))
                        + (float)((float)y * (float)(v48 * (float)v27))));
    v49 = p_gravity->z * (float)v27;
    v47 = v47 * (float)v27;
    v48 = v48 * (float)v27;
    if ( v31 > 0.99989998 )
    {
      v47 = 1.0;
      v30 = 1.0;
      v48 = 0.0;
      v28 = 0.0;
      v49 = 0.0;
      v29 = 0.0;
    }
    v46[0] = x;
    v46[1] = y;
    v46[2] = v16;
    v32 = (float)((float)((float)x * (float)v29) - (float)((float)v16 * (float)v30));
    v33 = (float)((float)((float)y * (float)v30) - (float)((float)x * (float)v28));
    v34 = (float)((float)((float)v16 * (float)v28) - (float)((float)y * (float)v29));
    _FP8 = (float)((float)((float)((float)v34 * (float)v34)
                         + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f8, f9, f13 }
    v37 = __frsqrte(_FP5);
    v38 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37
                                                                                        * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                                * (float)0.5))
                                                                                * (float)v37)
                                                                        - (float)1.5)
                                                        * (float)v37)
                                                * (float)((float)((float)((float)v34 * (float)v34)
                                                                + (float)((float)((float)v33 * (float)v33)
                                                                        + (float)((float)v32 * (float)v32)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v37
                                                                                * (float)((float)((float)((float)v34 * (float)v34)
                                                                                                + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                        * (float)0.5))
                                                                        * (float)v37)
                                                                - (float)1.5)
                                                * (float)v37))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v37
                                                        * (float)((float)((float)((float)v34 * (float)v34)
                                                                        + (float)((float)((float)v33 * (float)v33)
                                                                                + (float)((float)v32 * (float)v32)))
                                                                * (float)0.5))
                                                * (float)v37)
                                        - (float)1.5)
                        * (float)v37));
    v39 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37
                                                                                                * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                        * (float)v37)
                                                                                - (float)1.5)
                                                                * (float)v37)
                                                        * (float)((float)((float)((float)v34 * (float)v34)
                                                                        + (float)((float)((float)v33 * (float)v33)
                                                                                + (float)((float)v32 * (float)v32)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v37
                                                                                        * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                                * (float)0.5))
                                                                                * (float)v37)
                                                                        - (float)1.5)
                                                        * (float)v37))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v37
                                                                * (float)((float)((float)((float)v34 * (float)v34)
                                                                                + (float)((float)((float)v33 * (float)v33)
                                                                                        + (float)((float)v32 * (float)v32)))
                                                                        * (float)0.5))
                                                        * (float)v37)
                                                - (float)1.5)
                                * (float)v37))
                * (float)((float)((float)((float)v34 * (float)v34)
                                + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                        * (float)0.5));
    v46[3] = (float)((float)-(float)((float)((float)v39 * (float)v38) - (float)1.5) * (float)v38) * (float)v34;
    v46[4] = (float)v32 * (float)((float)-(float)((float)((float)v39 * (float)v38) - (float)1.5) * (float)v38);
    v46[5] = (float)v33 * (float)((float)-(float)((float)((float)v39 * (float)v38) - (float)1.5) * (float)v38);
    Bounds = idAIEventTrace::GetBounds(this);
    v42 = &v54;
    p_z = (_DWORD *)&Bounds[-1].b[1].z;
    for ( i = 6; i != 0; --i )
      *++v42 = *(float *)++p_z;
    v55[0] = -v41;
    v55[3] = v41;
    v53[0] = 0.0;
    v53[1] = 1.0;
    v53[2] = 1.0;
    v54 = 1.0;
    clientGame->renderWorld->DebugOrientedBounds(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v53,
      a3: (const idBounds *)v55,
      a4: (const idVec3 *)v50,
      a5: (const idMat3 *)v46,
      a6: v6,
      a7: true);
  }
}


// ========================================================================
// ?InternalIsTouching@idAIEventTrace@@MBA_NPBVidEntity@@H@Z
// EA  : 0x82A46A60
// RVA : 0x00A46A60
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventtrace.cpp
// ========================================================================

BOOL __fastcall idAIEventTrace::InternalIsTouching(idAIEventTrace *this, const idEntity *ent, const int curTime)
{
  idClipQuery *p_traceQuery; // r29
  idClientGame *v5; // r30
  unsigned __int64 v6; // r24
  unsigned __int64 index; // r11
  int value; // r10
  idEntity *v9; // r3
  idEntity *v10; // r3
  const idDeclAiEvent *eventDecl; // r11
  int entityNumber; // r26
  int v13; // r27
  double v14; // fp1
  double v15; // fp7
  double v16; // fp6
  double y; // fp10
  double z; // fp9
  int v20; // [sp+8h] [-D8h]
  bool v21; // [sp+Fh] [-D1h]
  const char *v22; // [sp+10h] [-D0h]
  int v23; // [sp+14h] [-CCh]
  int v24; // [sp+18h] [-C8h]
  int v25; // [sp+1Ch] [-C4h]
  int v26; // [sp+20h] [-C0h]
  int v27; // [sp+24h] [-BCh]
  int v28; // [sp+28h] [-B8h]
  int v29; // [sp+2Ch] [-B4h]
  int v30; // [sp+30h] [-B0h]
  int v31; // [sp+34h] [-ACh]
  int v32; // [sp+38h] [-A8h]
  int v33; // [sp+3Ch] [-A4h]
  int v34; // [sp+40h] [-A0h]
  int v35; // [sp+44h] [-9Ch]
  int v36; // [sp+48h] [-98h]
  int v37; // [sp+4Ch] [-94h]
  int v38; // [sp+50h] [-90h]
  int v39; // [sp+58h] [-88h]
  int v40; // [sp+60h] [-80h]
  char v41; // [sp+70h] [-70h] BYREF
  idVec3 v42; // [sp+78h] [-68h] BYREF

  p_traceQuery = &this->traceQuery;
  HIDWORD(v6) = ent;
  v5 = clientGame;
  LODWORD(v6) = 0;
  if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->traceQuery) != 0 )
  {
    index = p_traceQuery->index;
    p_traceQuery->index = v6;
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: &this->lastTraceResult,
      query: &v5->clip.collisionQueries[index & 0xFFF].query,
      peek: false);
    v5 = clientGame;
  }
  if ( this->lastTraceFrame != idAccolade::Count(this: &v5->gameTimeManager)
    && ((LODWORD(this->dir.y) | LODWORD(this->dir.x) | LODWORD(this->dir.z)) & 0x7FFFFFFF) != 0 )
  {
    value = this->originator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
    }
    else
    {
      v10 = nullptr;
    }
    eventDecl = this->eventDecl;
    entityNumber = v10->entityNumber;
    if ( eventDecl != nullptr )
      v13 = idContents::ToFlags(this: &eventDecl->clipMask);
    else
      v13 = 0;
    v14 = ((double (__fastcall *)(idAIEventTrace *))this->GetDistance)(a1: this);
    v15 = (float)(this->dir.y * (float)v14);
    v16 = (float)((float)v14 * this->dir.z);
    y = this->origin.y;
    z = this->origin.z;
    v42.x = this->origin.x + (float)(this->dir.x * (float)v14);
    v42.y = (float)y + (float)v15;
    v42.z = (float)z + (float)v16;
    p_traceQuery->index = *(unsigned __int64 *)&idClip::Translation(
                                                  this: (idClip *)&v41,
                                                  result: &clientGame->clip,
                                                  a3: nullptr,
                                                  start: &this->origin,
                                                  end: &v42,
                                                  clipModel: nullptr,
                                                  startAxis: &mat3_identity,
                                                  clipMask: v13,
                                                  passEntityNumber: v20,
                                                  moveClipModel: v21,
                                                  userName: v22,
                                                  a12: v23,
                                                  a13: v24,
                                                  a14: v25,
                                                  a15: v26,
                                                  a16: v27,
                                                  a17: v28,
                                                  a18: v29,
                                                  a19: v30,
                                                  a20: v31,
                                                  a21: v32,
                                                  a22: v33,
                                                  a23: v34,
                                                  a24: v35,
                                                  a25: v36,
                                                  a26: v37,
                                                  a27: v38,
                                                  a28: entityNumber,
                                                  a29: v39,
                                                  a30: false,
                                                  a31: v40,
                                                  a32: (int)"w:\\tech5\\tungsten\\game\\ai\\aievents\\AIEventTrace.cpp(36) : AIEventTrace")->world;
    this->lastTraceFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
  }
  return this->lastTraceResult.fraction != 1.0
      && (_cntlzw(*(_DWORD *)(HIDWORD(v6) + 492) - this->lastTraceResult.c.entityNum) & 0x20) != 0;
}

