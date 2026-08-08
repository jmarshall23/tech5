
// ========================================================================
// ??0idAIEventSphere@@QAA@XZ
// EA  : 0x82A45DD8
// RVA : 0x00A45DD8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsphere.cpp
// ========================================================================

idAIEventSphere *__fastcall idAIEventSphere::idAIEventSphere(idAIEventSphere *this)
{
  idAIEvent::idAIEvent(this);
  this->__vftable = (idAIEventSphere_vtbl *)&idAIEventSphere::`vftable';
  return this;
}


// ========================================================================
// ?GetRadius@idAIEventSphere@@QBAMXZ
// EA  : 0x82A45E18
// RVA : 0x00A45E18
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsphere.cpp
// ========================================================================

float __fastcall idAIEventSphere::GetRadius(idAIEventSphere *this)
{
  const idDeclAiEvent *eventDecl; // r11
  double radius; // fp1

  eventDecl = this->eventDecl;
  if ( eventDecl != nullptr )
    radius = eventDecl->radius;
  else
    radius = 0.0;
  return *((float *)&radius + 1);
}


// ========================================================================
// ?InternalIsTouching@idAIEventProjectedSphere@@MBA_NPBVidEntity@@H@Z
// EA  : 0x82A45E38
// RVA : 0x00A45E38
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsphere.cpp
// ========================================================================

BOOL __fastcall idAIEventProjectedSphere::InternalIsTouching(
        idAIEventProjectedSphere *this,
        idEntity *ent,
        const int curTime)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  const idDeclAiEvent *eventDecl; // r11
  double v7; // fp13
  double v8; // fp12
  double v9; // fp0
  double v10; // fp11
  double radius; // fp10

  Physics = idEntity::GetPhysics(this: ent);
  v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  eventDecl = this->eventDecl;
  v9 = 0.0;
  if ( eventDecl != nullptr )
    radius = eventDecl->radius;
  else
    radius = 0.0;
  if ( eventDecl != nullptr )
    v9 = eventDecl->radius;
  v8 = (float)(v5[1] - this->origin.y);
  v7 = (float)(*v5 - this->origin.x);
  v10 = (float)(v5[2] - this->origin.z);
  return (float)((float)((float)v7 * (float)v7)
               + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8))) <= (double)(float)((float)v9 * (float)radius);
}


// ========================================================================
// ?InternalDrawDebug@idAIEventSphere@@MBAXHHH@Z
// EA  : 0x82A45EF0
// RVA : 0x00A45EF0
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsphere.cpp
// ========================================================================

void __fastcall idAIEventSphere::InternalDrawDebug(idAIEventSphere *this, int level, const int curTime, int duration)
{
  int GameMsPerFrame; // r29
  const idVec4 *v7; // r3
  const idDeclAiEvent *eventDecl; // r11
  double radius; // fp0
  idAIEventSphere_vtbl *v10; // r11
  double y; // fp12
  double z; // fp11
  const idColor *(__fastcall *GetColor)(idAIEventSphere *); // ctr
  const idVec4 *v14; // r3
  float v15[16]; // [sp+50h] [-40h] BYREF

  if ( duration <= 0 )
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  else
    GameMsPerFrame = duration;
  v7 = (const idVec4 *)this->GetColor(this);
  clientGame->renderWorld->DebugPoint(
    this: clientGame->renderWorld,
    a2: v7,
    a3: &this->origin,
    a4: GameMsPerFrame,
    a5: true);
  if ( level > 1 )
  {
    eventDecl = this->eventDecl;
    if ( eventDecl != nullptr )
      radius = eventDecl->radius;
    else
      radius = 0.0;
    v10 = this->__vftable;
    y = this->origin.y;
    z = this->origin.z;
    v15[0] = this->origin.x;
    v15[3] = radius;
    v15[1] = y;
    GetColor = v10->GetColor;
    v15[2] = z;
    v14 = (const idVec4 *)GetColor(this);
    clientGame->renderWorld->DebugSphere(
      this: clientGame->renderWorld,
      a2: v14,
      a3: (const idSphere *)v15,
      a4: 12,
      a5: GameMsPerFrame,
      a6: true);
  }
}


// ========================================================================
// ?InternalUpdateAttached@idAIEventProjectedSphere@@MAA?AW4aiEventUpdateResult_t@idAIEvent@@H@Z
// EA  : 0x82A45FF8
// RVA : 0x00A45FF8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsphere.cpp
// ========================================================================

idAIEvent::aiEventUpdateResult_t __fastcall idAIEventProjectedSphere::InternalUpdateAttached(
        idAIEventProjectedSphere *this,
        const int curTime)
{
  int value; // r10
  idEntity *v4; // r3
  idPlayer *v5; // r3
  int v6; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  idPhysics *v9; // r3
  float *v10; // r3
  double z; // fp12
  idEntity *Originator; // r3
  idPhysics *v13; // r3
  idVec3 *v14; // r3
  float y; // r10
  float v16; // r9
  idVec3 *p_curSimPos; // r31
  idVec3 *p_curSimVel; // r28
  int v19; // r23
  double v20; // fp12
  double v21; // fp10
  double v22; // fp9
  double v23; // fp8
  double v24; // fp7
  double v25; // fp6
  int valueInteger; // r11
  idVec3 *p_traceFrom; // r29
  __int64 v29; // r8
  __int64 v30; // r6
  __int64 v31; // r10
  va *v32; // r3
  double v33; // fp10
  double v34; // fp11
  double v35; // fp9
  double v36; // fp3
  double v37; // fp6
  double v38; // fp12
  double v39; // fp13
  bool v40; // mr_fpscr49
  double v41; // fp7
  double v42; // fp6
  double v43; // fp8
  double v44; // fp7
  double v45; // fp1
  double v46; // fp0
  double v47; // fp3
  double v48; // fp2
  int v49; // r9
  idEntity *v50; // r3
  idEntity *v51; // r3
  idPhysics *Physics; // r3
  float *v53; // r3
  int v54; // [sp+8h] [-1168h]
  int v55; // [sp+Ch] [-1164h]
  int v56; // [sp+10h] [-1160h]
  int v57; // [sp+14h] [-115Ch]
  int v58; // [sp+18h] [-1158h]
  int v59; // [sp+1Ch] [-1154h]
  float x; // [sp+60h] [-1110h] BYREF
  float v61; // [sp+64h] [-110Ch]
  float v62; // [sp+68h] [-1108h]
  _BYTE v63[16]; // [sp+70h] [-1100h] BYREF
  trace_t v64; // [sp+80h] [-10F0h] BYREF
  va v65; // [sp+100h] [-1070h] BYREF

  value = this->instigator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = (idPlayer *)idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  if ( idPlayer::CastTo(c: v5) == nullptr
    || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->startTime < 100
    || ((v6 = this->originator.spawnId.value, gameLocal->spawnIds.ptr[v6 & 0x1FFF] != v6 >> 13)
     || (v7 = gameLocal->entities.ptr[v6 & 0x1FFF]) == nullptr
      ? (v8 = nullptr)
      : (v8 = idEntity::CastTo(c: v7)),
        v9 = idEntity::GetPhysics(this: v8),
        (float)((float)((v10 = (float *)v9->GetLinearVelocity(this: (idPhysics *)v63, result: (idVec3 *)v9, a3: 0))[2]
                      * v10[2])
              + (float)((float)(*v10 * *v10) + (float)(v10[1] * v10[1]))) < 100.0) )
  {
    v49 = this->originator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v49 & 0x1FFF] == v49 >> 13 && (v50 = gameLocal->entities.ptr[v49 & 0x1FFF]) != nullptr )
      v51 = idEntity::CastTo(c: v50);
    else
      v51 = nullptr;
    Physics = idEntity::GetPhysics(this: v51);
    v53 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    this->origin.x = *v53;
    this->origin.y = v53[1];
    z = v53[2];
    goto LABEL_42;
  }
  if ( this->hasProjection )
  {
    this->origin.x = this->projectedOrigin.x;
    this->origin.y = this->projectedOrigin.y;
    z = this->projectedOrigin.z;
LABEL_42:
    this->origin.z = z;
    return AIUPDATE_OK;
  }
  if ( this->bounces == -1 )
  {
    this->curSimPos.x = this->origin.x;
    this->curSimPos.y = this->origin.y;
    this->curSimPos.z = this->origin.z;
    if ( idAIEvent::GetOriginator(this) != nullptr )
    {
      Originator = (idEntity *)idAIEvent::GetOriginator(this);
      v13 = idEntity::GetPhysics(this: Originator);
      v14 = v13->GetLinearVelocity(this: (idPhysics *)v63, result: (idVec3 *)v13, a3: 0);
    }
    else
    {
      v14 = &vec3_origin;
    }
    this->curSimVel.x = v14->x;
    this->curSimVel.y = v14->y;
    this->curSimVel.z = v14->z;
    this->traceFrom.x = this->curSimPos.x;
    this->traceFrom.y = this->curSimPos.y;
    this->traceFrom.z = this->curSimPos.z;
    this->bounces = 0;
    this->horizontalBounces = 0;
  }
  y = this->curSimPos.y;
  v16 = this->curSimPos.z;
  p_curSimPos = &this->curSimPos;
  p_curSimVel = &this->curSimVel;
  v19 = 0;
  x = this->curSimPos.x;
  v61 = y;
  v62 = v16;
  while ( 1 )
  {
    v20 = (float)(p_curSimVel->x * (float)0.016666668);
    v21 = (float)(this->curSimVel.y * (float)0.016666668);
    v22 = (float)(this->curSimVel.z * (float)0.016666668);
    v23 = p_curSimPos->x;
    v24 = this->curSimPos.y;
    v25 = this->curSimPos.z;
    v61 = this->curSimPos.y;
    x = v23;
    v62 = v25;
    p_curSimPos->x = (float)v23 + (float)v20;
    this->curSimPos.y = (float)v21 + (float)v24;
    this->curSimPos.z = (float)v25 + (float)v22;
    this->curSimVel.z = this->curSimVel.z - (float)16.666668;
    valueInteger = g_showTrajectories.valueInteger;
    if ( g_showTrajectories.valueInteger != 0 )
    {
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorWhite,
        a3: (const idVec3 *)&x,
        a4: &this->curSimPos,
        a5: 2000,
        a6: true);
      valueInteger = g_showTrajectories.valueInteger;
    }
    if ( v19 == 9 )
    {
      if ( valueInteger != 0 )
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorYellow,
          a3: &this->traceFrom,
          a4: &this->curSimPos,
          a5: 2000,
          a6: true);
      p_traceFrom = &this->traceFrom;
      if ( idClip::TracePoint(
             this: &clientGame->clip,
             result: &v64,
             start: &this->traceFrom,
             end: &this->curSimPos,
             clipMask: 1,
             passEntityNumber: -1) )
      {
        break;
      }
      p_traceFrom->x = p_curSimPos->x;
      this->traceFrom.y = this->curSimPos.y;
      this->traceFrom.z = this->curSimPos.z;
    }
    if ( ++v19 >= 10 )
      return AIUPDATE_OK;
  }
  if ( g_showTrajectories.valueInteger != 0 )
  {
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorOrange,
      a3: &v64.endpos,
      a4: 2000,
      a5: false);
    HIDWORD(v29) = 0x82000000;
    HIDWORD(v30) = this->bounces;
    v32 = va::va(
            this: &v65,
            fmt: "%d",
            a3: v30,
            a4: v29,
            a5: v31,
            a6: v54,
            a7: v55,
            a8: v56,
            a9: v57,
            a10: v58,
            a11: v59);
    ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
      a1: clientGame->renderWorld,
      a2: v32,
      a3: &v64.endpos,
      a4: clientGame->renderWorld->DebugText,
      a5: &idColor::colorOrange,
      a6: 1,
      a7: 2000,
      a8: 0,
      a9: 0.2);
  }
  v33 = v64.endpos.z;
  this->curSimPos.z = v64.endpos.z;
  v34 = v64.endpos.y;
  v35 = v64.endpos.x;
  this->curSimPos.y = v64.endpos.y;
  p_curSimPos->x = v35;
  v36 = (float)((float)v34 - (float)(this->curSimVel.y * (float)0.016666668));
  v37 = (float)(this->curSimVel.z * (float)0.016666668);
  v38 = v64.c.normal.z;
  v39 = 0.5;
  v40 = v64.c.normal.z > 0.1;
  p_traceFrom->x = (float)v35 - (float)(p_curSimVel->x * (float)0.016666668);
  this->traceFrom.y = v36;
  this->traceFrom.z = (float)v33 - (float)v37;
  if ( v40 )
  {
    v39 = 0.1;
    ++this->horizontalBounces;
  }
  else
  {
    v41 = this->curSimVel.y;
    v42 = this->curSimVel.z;
    p_curSimVel->x = p_curSimVel->x * (float)0.80000001;
    this->curSimVel.y = (float)v41 * (float)0.80000001;
    this->curSimVel.z = (float)v42 * (float)0.80000001;
  }
  v43 = v64.c.normal.y;
  v44 = v64.c.normal.x;
  ++this->bounces;
  v45 = p_curSimVel->x;
  v46 = this->curSimVel.y;
  v47 = (float)((float)((float)((float)(this->curSimVel.x * (float)v44)
                              + (float)((float)((float)v43 * this->curSimVel.y) + (float)(this->curSimVel.z * (float)v38)))
                      * (float)((float)v39 + (float)1.0))
              * (float)v44);
  v48 = (float)((float)v43
              * (float)((float)((float)(this->curSimVel.x * (float)v44)
                              + (float)((float)((float)v43 * this->curSimVel.y) + (float)(this->curSimVel.z * (float)v38)))
                      * (float)((float)v39 + (float)1.0)));
  this->curSimVel.z = this->curSimVel.z
                    - (float)((float)((float)((float)(this->curSimVel.x * (float)v44)
                                            + (float)((float)((float)v43 * this->curSimVel.y)
                                                    + (float)(this->curSimVel.z * (float)v38)))
                                    * (float)((float)v39 + (float)1.0))
                            * (float)v38);
  p_curSimVel->x = (float)v45 - (float)v47;
  this->curSimVel.y = (float)v46 - (float)v48;
  if ( this->bounces >= 4 || this->horizontalBounces >= 2 )
  {
    this->projectedOrigin.x = v35;
    this->projectedOrigin.y = v34;
    this->projectedOrigin.z = v33;
    this->origin.x = v35;
    this->origin.y = this->projectedOrigin.y;
    this->origin.z = this->projectedOrigin.z;
    this->hasProjection = true;
    return AIUPDATE_OK;
  }
  return AIUPDATE_OK;
}

