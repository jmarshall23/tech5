
// ========================================================================
// ?DebugFailed@idCoverQuery@@IBAMPBDABVidVec3@@H@Z
// EA  : 0x82A8AD90
// RVA : 0x00A8AD90
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

float __fastcall idCoverQuery::DebugFailed(idCoverQuery *this, const char *message, const idVec3 *origin, int minLevel)
{
  double z; // fp13
  double y; // fp11
  double v8; // fp1
  float v10[4]; // [sp+60h] [-50h] BYREF
  float v11[4]; // [sp+70h] [-40h] BYREF

  if ( ai_debugCover.valueInteger < minLevel )
  {
    v8 = 0.0;
  }
  else
  {
    v10[0] = 0.0;
    v10[1] = 0.0;
    v10[2] = -1.0;
    if ( ai_debugLevel.valueInteger > 0 && ai_debugCover.valueInteger >= 2 )
    {
      z = origin->z;
      y = origin->y;
      v11[0] = origin->x;
      v11[1] = y;
      v11[2] = (float)z + (float)4.0;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugCircle)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorRed,
        a3: v11,
        a4: v10,
        a5: 16.0);
      ((void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: message,
        a3: origin,
        a4: clientGame->renderWorld->DebugText,
        a5: &idColor::colorRed,
        a6: 1,
        a7: 2000,
        a8: 0,
        a9: 0.2);
    }
    v8 = 0.0;
  }
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?DebugFailedTarget@idCoverQuery@@IBAMPBDABVidVec3@@1H@Z
// EA  : 0x82A8AEC0
// RVA : 0x00A8AEC0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

float __fastcall idCoverQuery::DebugFailedTarget(
        idCoverQuery *this,
        const char *message,
        const idVec3 *origin,
        const idVec3 *targetOrigin,
        int minLevel)
{
  double z; // fp13
  double y; // fp11
  double v10; // fp11
  double v11; // fp10
  double v12; // fp1
  float v14[4]; // [sp+60h] [-70h] BYREF
  float v15[4]; // [sp+70h] [-60h] BYREF
  float v16[6]; // [sp+80h] [-50h] BYREF

  if ( ai_debugCover.valueInteger < minLevel )
  {
    v12 = 0.0;
  }
  else
  {
    v14[0] = 0.0;
    v14[1] = 0.0;
    v14[2] = -1.0;
    if ( ai_debugLevel.valueInteger > 0 && ai_debugCover.valueInteger >= 2 )
    {
      z = origin->z;
      y = origin->y;
      v15[0] = origin->x;
      v15[1] = y;
      v15[2] = (float)z + (float)4.0;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugCircle)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorRed,
        a3: v15,
        a4: v14,
        a5: 16.0);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, const idVec3 *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorRed,
        a3: origin,
        a4: targetOrigin,
        a5: 2.0);
      v10 = (float)(targetOrigin->y + (float)(origin->y * (float)3.0));
      v11 = (float)(targetOrigin->z + (float)(origin->z * (float)3.0));
      v16[0] = (float)(targetOrigin->x + (float)(origin->x * (float)3.0)) * (float)0.25;
      v16[1] = (float)v10 * (float)0.25;
      v16[2] = (float)v11 * (float)0.25;
      ((void (__fastcall *)(idRenderWorld *, const char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: message,
        a3: v16,
        a4: clientGame->renderWorld->DebugText,
        a5: &idColor::colorRed,
        a6: 1,
        a7: 2000,
        a8: 0,
        a9: 0.2);
    }
    v12 = 0.0;
  }
  return *((float *)&v12 + 1);
}


// ========================================================================
// ?DebugSucceeded@idCoverQuery@@IBAMMMMMMMMMMABVidVec3@@0H@Z
// EA  : 0x82A8B080
// RVA : 0x00A8B080
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

float __fastcall idCoverQuery::DebugSucceeded(
        idCoverQuery *this,
        double score,
        double targetScore,
        double aiScore,
        double angleScore,
        double groupScore,
        double enemyVisibilityScore,
        double aiVisibilityScore,
        double miscScore,
        const idVec3 *coverOrigin,
        const idVec3 *targetOrigin,
        const int minLevel,
        int a13,
        int a14,
        int a15,
        int a16,
        const float angle,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float *a40,
        float a41,
        float *a42,
        float a43,
        int a44)
{
  double v44; // fp9
  double v53; // fp19
  double v54; // fp5
  bool v55; // mr_fpscr50
  double v56; // fp2
  double v57; // fp1
  double v58; // fp13
  double v59; // fp30
  double v60; // fp29
  double v61; // fp28
  __int64 v62; // r10
  __int64 v63; // r8
  __int64 v64; // r6
  va *v65; // r3
  va *v66; // r3
  double v67; // fp1
  int v69; // [sp+8h] [-1118h]
  int v70; // [sp+Ch] [-1114h]
  int v71; // [sp+10h] [-1110h]
  int v72; // [sp+14h] [-110Ch]
  int v73; // [sp+18h] [-1108h]
  int v74; // [sp+1Ch] [-1104h]
  idColor v75; // [sp+70h] [-10B0h] BYREF
  float v76[4]; // [sp+80h] [-10A0h] BYREF
  float v77[4]; // [sp+90h] [-1090h] BYREF
  va v78; // [sp+A0h] [-1080h] BYREF

  v53 = v44;
  if ( ai_debugCover.valueInteger >= a44 )
  {
    v54 = (float)((float)score + (float)1.0);
    v55 = score == 0.0;
    v56 = (float)(*a42 + (float)(*a40 * (float)3.0));
    v57 = (float)(a42[1] + (float)(a40[1] * (float)3.0));
    v58 = (float)(a42[2] + (float)(a40[2] * (float)3.0));
    v75.a = 1.0;
    v75.r = (float)v54 * (float)0.5;
    v75.g = v75.r;
    v75.b = v75.r;
    v59 = (float)((float)v56 * (float)0.25);
    v60 = (float)((float)v57 * (float)0.25);
    v61 = (float)((float)v58 * (float)0.25);
    if ( v55 )
      v75 = idColor::colorBlack;
    ((void (__fastcall *)(idRenderWorld *, idColor *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &v75,
      a3: 0.2);
    if ( ai_debugCover.valueInteger < 2 )
    {
      HIDWORD(v64) = LODWORD(score);
      v76[0] = v59;
      LODWORD(v62) = "1 - formation cover, such as behind regime shield units";
      v76[2] = (float)v61 + (float)4.0;
      v76[1] = v60;
      v66 = va::va(
              this: &v78,
              fmt: "score:%.2f",
              a3: v64,
              a4: v63,
              a5: v62,
              a6: v69,
              a7: v70,
              a8: v71,
              a9: v72,
              a10: v73,
              a11: v74,
              score);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v66,
        a3: v76,
        a4: clientGame->renderWorld->__vftable,
        a5: &idColor::colorLtGrey,
        a6: 1,
        a7: 3000,
        a8: 0,
        a9: 0.2);
    }
    else
    {
      v77[0] = v59;
      v77[1] = v60;
      v77[2] = (float)v61 + (float)4.0;
      v65 = va::va(
              this: &v78,
              fmt: (const char *)HIDWORD(targetScore),
              a3: __SPAIR64__(LODWORD(targetScore), LODWORD(aiScore)),
              a4: __SPAIR64__(LODWORD(angleScore), LODWORD(v53)),
              a5: __SPAIR64__(LODWORD(enemyVisibilityScore), LODWORD(aiVisibilityScore)),
              a6: v69,
              a7: v70,
              a8: v71,
              a9: v72,
              a10: v73,
              a11: v74,
              targetScore,
              aiScore,
              angleScore,
              v53,
              enemyVisibilityScore,
              aiVisibilityScore,
              groupScore,
              miscScore);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v65,
        a3: v77,
        a4: clientGame->renderWorld->DebugText,
        a5: &v75,
        a6: 1,
        a7: 3000,
        a8: 0,
        a9: 0.2);
    }
  }
  v67 = score;
  return *((float *)&v67 + 1);
}


// ========================================================================
// ?DebugSucceededAvoid@idCoverQuery@@IBAMMMMMMMMABVidVec3@@0H@Z
// EA  : 0x82A8B328
// RVA : 0x00A8B328
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

float __fastcall idCoverQuery::DebugSucceededAvoid(
        idCoverQuery *this,
        double score,
        double angleScore,
        double angle,
        double travelScore,
        double proximityScore,
        double awayScore,
        double velocityScore,
        const idVec3 *coverOrigin,
        const idVec3 *targetOrigin,
        const int minLevel,
        int a12,
        int a13,
        int a14,
        int a15,
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
        int a34,
        float *a35,
        int a36,
        float *a37,
        int a38,
        int a39)
{
  double v46; // fp5
  bool v47; // mr_fpscr50
  double v48; // fp2
  double v49; // fp1
  double v50; // fp13
  double v51; // fp30
  double v52; // fp29
  double v53; // fp28
  __int64 v54; // r10
  __int64 v55; // r8
  __int64 v56; // r6
  va *v57; // r3
  va *v58; // r3
  double v59; // fp1
  int v61; // [sp+8h] [-10F8h]
  int v62; // [sp+Ch] [-10F4h]
  int v63; // [sp+10h] [-10F0h]
  int v64; // [sp+14h] [-10ECh]
  int v65; // [sp+18h] [-10E8h]
  int v66; // [sp+1Ch] [-10E4h]
  idColor v67; // [sp+60h] [-10A0h] BYREF
  float v68[4]; // [sp+70h] [-1090h] BYREF
  float v69[4]; // [sp+80h] [-1080h] BYREF
  va v70; // [sp+90h] [-1070h] BYREF

  if ( ai_debugCover.valueInteger >= a39 )
  {
    v46 = (float)((float)score + (float)1.0);
    v47 = score == 0.0;
    v48 = (float)(*a37 + (float)(*a35 * (float)3.0));
    v49 = (float)(a37[1] + (float)(a35[1] * (float)3.0));
    v50 = (float)(a37[2] + (float)(a35[2] * (float)3.0));
    v67.a = 1.0;
    v67.r = (float)v46 * (float)0.5;
    v67.g = v67.r;
    v67.b = v67.r;
    v51 = (float)((float)v48 * (float)0.25);
    v52 = (float)((float)v49 * (float)0.25);
    v53 = (float)((float)v50 * (float)0.25);
    if ( v47 )
      v67 = idColor::colorBlack;
    ((void (__fastcall *)(idRenderWorld *, idColor *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &v67,
      a3: 0.2);
    if ( ai_debugCover.valueInteger < 2 )
    {
      HIDWORD(v56) = LODWORD(score);
      v68[0] = v51;
      LODWORD(v54) = "1 - formation cover, such as behind regime shield units";
      v68[2] = (float)v53 + (float)4.0;
      v68[1] = v52;
      v58 = va::va(
              this: &v70,
              fmt: "score:%.2f",
              a3: v56,
              a4: v55,
              a5: v54,
              a6: v61,
              a7: v62,
              a8: v63,
              a9: v64,
              a10: v65,
              a11: v66,
              score);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v58,
        a3: v68,
        a4: clientGame->renderWorld->__vftable,
        a5: &idColor::colorLtGrey,
        a6: 1,
        a7: 3000,
        a8: 0,
        a9: 0.2);
    }
    else
    {
      v69[0] = v51;
      v69[1] = v52;
      v69[2] = (float)v53 + (float)4.0;
      v57 = va::va(
              this: &v70,
              fmt: (const char *)HIDWORD(angleScore),
              a3: __SPAIR64__(LODWORD(angleScore), LODWORD(angle)),
              a4: __SPAIR64__(LODWORD(travelScore), LODWORD(proximityScore)),
              a5: __SPAIR64__(LODWORD(awayScore), LODWORD(velocityScore)),
              a6: v61,
              a7: v62,
              a8: v63,
              a9: v64,
              a10: v65,
              a11: v66,
              angleScore,
              angle,
              travelScore,
              proximityScore,
              awayScore,
              velocityScore,
              score);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v57,
        a3: v69,
        a4: clientGame->renderWorld->DebugText,
        a5: &v67,
        a6: 1,
        a7: 3000,
        a8: 0,
        a9: 0.2);
    }
  }
  v59 = score;
  return *((float *)&v59 + 1);
}


// ========================================================================
// ??0coverTarget_t@idCoverQuery@@QAA@XZ
// EA  : 0x82A8B5B8
// RVA : 0x00A8B5B8
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

idCoverQuery::coverTarget_t *__fastcall idCoverQuery::coverTarget_t::coverTarget_t(idCoverQuery::coverTarget_t *this)
{
  this->spawnId.value = 0x1FFF;
  this->origin = idCoverQuery::INVALID_ORIGIN;
  this->eyePoint = idCoverQuery::INVALID_ORIGIN;
  this->aiPos.valid = false;
  this->aiPos.areaNum = 0;
  this->aiPos.origin.x = 0.0;
  this->aiPos.origin.y = 0.0;
  this->aiPos.origin.z = 0.0;
  this->aiPos.validOrigin.x = 0.0;
  this->aiPos.validOrigin.y = 0.0;
  this->aiPos.validOrigin.z = 0.0;
  this->aiPos.aas = nullptr;
  this->vcPos.valid = false;
  this->vcPos.areaNum = 0;
  this->vcPos.origin.x = 0.0;
  this->vcPos.origin.y = 0.0;
  this->vcPos.origin.z = 0.0;
  this->vcPos.validOrigin.x = 0.0;
  this->vcPos.validOrigin.y = 0.0;
  this->vcPos.validOrigin.z = 0.0;
  this->vcPos.aas = nullptr;
  this->confirmedTime = -1;
  return this;
}


// ========================================================================
// ?PreScore@idCoverQuery@@AAAXXZ
// EA  : 0x82A8B800
// RVA : 0x00A8B800
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void __fastcall idCoverQuery::PreScore(idCoverQuery *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idCoverQuery::PreScore()");
  LODWORD(v2) = "idCoverQuery::PreScore()";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
  this->InternalPreScore(this);
  idPLogScope::~idPLogScope(this: v4);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489210
// EA  : 0x82A8B864
// RVA : 0x00A8B864
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489210()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$489211
// EA  : 0x82A8B88C
// RVA : 0x00A8B88C
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489211()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetupTarget@idCoverQuery@@AAAXABUcoverTarget_t@1@@Z
// EA  : 0x82A8B8C0
// RVA : 0x00A8B8C0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void __fastcall idCoverQuery::SetupTarget(idCoverQuery *this, const idCoverQuery::coverTarget_t *newTarget)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idAIEntityState *v6; // r28
  aiSenseState_t *v7; // r24
  idProjectile *Entity; // r3
  idProjectile *v9; // r3
  idAIEvent *Event; // r3
  idAAS2 *v11; // r28
  unsigned __int64 v12; // r6
  const char *v13; // r7
  idHandle<int,enum invalidAIEvent_t,-1> v14; // [sp+50h] [-70h] BYREF
  idPLogScope v15; // [sp+58h] [-68h] BYREF
  idPLogScope v16[12]; // [sp+60h] [-60h] BYREF

  RD_EventBegin(name: "idCoverQuery::SetupTarget()");
  LODWORD(v4) = "idCoverQuery::SetupTarget()";
  HIDWORD(v4) = 6;
  idPLogScope::idPLogScope(this: v16, pl: &pLog, gMask: v4, label: v5);
  idCoverQuery::coverTarget_t::operator=(this: &this->target, __that: newTarget);
  if ( this->target.spawnId.value != 0x1FFF )
  {
    v6 = idAIWorldState::StateForSpawnId(this: &this->ai->aiVolatile.world.worldState, entId: &this->target.spawnId);
    v7 = v6->senses.ptr[v6->lastSense];
    this->target.origin = aiSenseState_t::GetConfirmedPhysicalSafe(this: v7)->origin;
    this->target.eyePoint = aiSenseState_t::GetConfirmedPhysicalSafe(this: v7)->eyePos;
    this->target.confirmedTime = v7->lastConfirmedStimTime;
    Entity = (idProjectile *)idAIEntityState::GetEntity(this: v6);
    v9 = idProjectile::CastTo(c: Entity);
    if ( v9 != nullptr )
    {
      v14.value = v9->aiEventHandle.value;
      Event = idAIEventManager::GetEvent(this: &gameLocal->aiEventManager, handle: &v14);
      if ( Event != nullptr )
      {
        this->target.origin.x = Event->origin.x;
        this->target.origin.y = Event->origin.y;
        this->target.origin.z = Event->origin.z;
        this->target.eyePoint.x = Event->origin.x;
        this->target.eyePoint.y = Event->origin.y;
        this->target.eyePoint.z = Event->origin.z;
      }
    }
  }
  v11 = (idAAS2 *)this->ai->GetAAS(this: this->ai);
  idAASPosition::Update(
    this: &this->target.vcPos,
    aas: (idAAS2 *)gameLocal->aasVisCache.aas,
    origin: &this->target.origin);
  idAASPosition::Update(this: &this->target.aiPos, aas: v11, origin: &this->target.origin);
  RD_EventBegin(name: "idCoverQuery::InternalSetupTarget()");
  LODWORD(v12) = "idCoverQuery::InternalSetupTarget()";
  HIDWORD(v12) = 6;
  idPLogScope::idPLogScope(this: &v15, pl: &pLog, gMask: v12, label: v13);
  this->InternalSetupTarget(this, a2: &this->target);
  idPLogScope::~idPLogScope(this: &v15);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: v16);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489245
// EA  : 0x82A8BAB0
// RVA : 0x00A8BAB0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489245()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 104));
}


// ========================================================================
// __unwind$489246
// EA  : 0x82A8BAD8
// RVA : 0x00A8BAD8
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489246()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$489247
// EA  : 0x82A8BB00
// RVA : 0x00A8BB00
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489247()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 105));
}


// ========================================================================
// __unwind$489248
// EA  : 0x82A8BB28
// RVA : 0x00A8BB28
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489248()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// ?ScoreCover@idCoverQuery@@AAAMABUcoverCache_t@1@@Z
// EA  : 0x82A8BB58
// RVA : 0x00A8BB58
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

float __fastcall idCoverQuery::ScoreCover(idCoverQuery *this, const idCoverQuery::coverCache_t *cached)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  double v6; // fp31
  double v7; // fp1
  idPLogScope v9[2]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idCoverQuery::ScoreCover");
  LODWORD(v4) = "idCoverQuery::ScoreCover";
  HIDWORD(v4) = 6;
  idPLogScope::idPLogScope(this: v9, pl: &pLog, gMask: v4, label: v5);
  v6 = ((double (__fastcall *)(idCoverQuery *, const idCoverQuery::coverCache_t *))this->InternalScoreCover)(
         a1: this,
         a2: cached);
  idPLogScope::~idPLogScope(this: v9);
  RD_EventEnd();
  v7 = v6;
  return *((float *)&v7 + 1);
}


// ========================================================================
// __unwind$489359
// EA  : 0x82A8BBD4
// RVA : 0x00A8BBD4
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489359()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$489360
// EA  : 0x82A8BBFC
// RVA : 0x00A8BBFC
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489360()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?FindRelevantCover@idCoverQuery@@AAAXXZ
// EA  : 0x82A8BCC0
// RVA : 0x00A8BCC0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void __fastcall idCoverQuery::FindRelevantCover(idCoverQuery *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idAI2 *ai; // r3
  idAICoverManager *p_coverManager; // r28
  idAI2_vtbl *v6; // r9
  int v7; // r23
  idAI2 *v8; // r3
  idPhysics *Physics; // r3
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  float *v13; // r3
  double v14; // fp8
  double v15; // fp6
  int v16; // r20
  idAICover *v17; // r28
  const aas2Cover_t *Origin; // r3
  const aas2Cover_t *v19; // r3
  const aas2Cover_t *v20; // r3
  idAI2 *Reserver; // r3
  idAI2 *v22; // r3
  const aas2Cover_t *v23; // r3
  const aas2Cover_t *v24; // r3
  int CoverPosture; // r3
  const aas2Cover_t *v26; // r3
  const aas2Cover_t *v27; // r3
  const aas2Cover_t *v28; // r3
  const aas2Cover_t *v29; // r3
  double v30; // fp10
  double v31; // fp8
  double v32; // fp6
  int (__fastcall *v33)(int); // ctr
  int v34; // r24
  int v35; // r3
  int *v36; // r10
  _DWORD *v37; // r9
  int i; // ctr
  const aas2Cover_t *v39; // r3
  char v40; // r25
  double x; // fp9
  double y; // fp8
  idLinkList<idActor> *next; // r11
  double z; // fp7
  double v45; // fp30
  double v46; // fp29
  double v47; // fp28
  double v48; // fp31
  double v49; // fp27
  double v50; // fp26
  idAI2 *owner; // r30
  int v52; // r3
  idPhysics *v53; // r3
  idBounds *v54; // r3
  idAI2 *v55; // r3
  idAICover *p_cachedCover; // r29
  int v57; // r3
  int *v58; // r10
  _DWORD *v59; // r11
  int j; // ctr
  const aas2Cover_t *v61; // r3
  double v62; // fp7
  double v63; // fp6
  double v64; // fp4
  double v65; // fp2
  double v66; // fp1
  idLinkList<idActor> *v67; // r11
  idAI2 *v68; // r11
  idPhysics *v69; // r3
  const idVec3 *v70; // r30
  const aas2Cover_t *v71; // r3
  const aas2Cover_t *v72; // r3
  idLinkList<idCoverBlocker> *v73; // r11
  idEntity *v74; // r30
  int v75; // r3
  int *v76; // r10
  _DWORD *v77; // r11
  int k; // ctr
  idPhysics *v79; // r3
  float *v80; // r3
  double v81; // fp0
  double v82; // fp11
  double v83; // fp7
  double v84; // fp13
  double v85; // fp12
  double v86; // fp10
  double v87; // fp9
  char v88; // r11
  idEntity_vtbl *listenerList; // r11
  idEntity *RespondsTo; // r11
  const aas2Cover_t *v91; // r3
  idCoverQuery::coverCache_t *v92; // r30
  const aas2Cover_t *v93; // r3
  const idAAS2 *v94; // r29
  const aas2Cover_t *v95; // r25
  unsigned __int16 AreaNum; // r3
  const aas2Cover_t *v97; // r3
  __int64 v98; // r10
  double v99; // fp5
  double v100; // fp0
  double v101; // fp10
  double v102; // fp6
  idPLog *pLog; // r29
  idPLog::logEntry_t *v106; // r30
  int v107; // r3
  __int64 totalTicks; // r11
  __int64 v109; // r9
  int v110; // [sp+50h] [-1A0h]
  int v111; // [sp+5Ch] [-194h] BYREF
  idBounds v112; // [sp+60h] [-190h] BYREF
  float v113; // [sp+78h] [-178h] BYREF
  float v114; // [sp+7Ch] [-174h]
  float v115; // [sp+80h] [-170h]
  int v116; // [sp+8Ch] [-164h] BYREF
  idBounds v117; // [sp+90h] [-160h] BYREF
  int v118; // [sp+ACh] [-144h] BYREF
  float v119; // [sp+B0h] [-140h]
  float v120; // [sp+B4h] [-13Ch]
  float v121; // [sp+B8h] [-138h]
  float v122; // [sp+BCh] [-134h]
  float v123; // [sp+C0h] [-130h]
  float v124; // [sp+C4h] [-12Ch]
  idAAS2 *aas; // [sp+C8h] [-128h]
  idList<idCoverQuery::coverCache_t,5> *p_relevantCover; // [sp+CCh] [-124h]
  const char *v127; // [sp+D0h] [-120h]
  const char *v128; // [sp+D4h] [-11Ch]
  idAICoverManager *v129; // [sp+D8h] [-118h]
  const char *v130; // [sp+DCh] [-114h]
  const char *v131; // [sp+E0h] [-110h]
  const char *v132; // [sp+E4h] [-10Ch]
  idPLogScope v133; // [sp+E8h] [-108h] BYREF
  float v134[7]; // [sp+F0h] [-100h] BYREF
  int v135; // [sp+10Ch] [-E4h]

  RD_EventBegin(name: "idCoverQuery::FindRelevantCover()");
  LODWORD(v2) = "idCoverQuery::FindRelevantCover()";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: &v133, pl: &::pLog, gMask: v2, label: v3);
  ai = this->ai;
  p_coverManager = &ai->aiVolatile.coverManager;
  v6 = ai->__vftable;
  v129 = &ai->aiVolatile.coverManager;
  v7 = ((int (*)(void))v6->GetAAS)();
  p_relevantCover = &this->relevantCover;
  aas = (idAAS2 *)gameLocal->aasVisCache.aas;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->relevantCover);
  this->minTravelTimeIndex = -1;
  this->maxTravelTimeIndex = -1;
  this->minTravelTime = 3.4028235e38;
  this->maxTravelTime = 1.1754944e-38;
  if ( ai_debugCover.valueInteger >= 2 )
  {
    v8 = this->ai;
    v113 = 0.0;
    v114 = 0.0;
    v115 = -1.0;
    Physics = idEntity::GetPhysics(this: v8);
    v10 = (float)(v115 * (float)-4.0);
    v11 = (float)(v114 * (float)-4.0);
    v12 = (float)(v113 * (float)-4.0);
    v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v14 = (float)(v13[2] + (float)v10);
    v15 = (float)(v13[1] + (float)v11);
    v134[0] = (float)v12 + *v13;
    v134[2] = v14;
    v134[1] = v15;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugCircle)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorOrange,
      a3: v134,
      a4: &v113,
      a5: 24.0);
  }
  v16 = 0;
  if ( p_coverManager->knownCover.num <= 0 )
    goto LABEL_80;
  v110 = 0;
  v127 = "Cover %d reserved but reserver does not have it as current cover";
  v130 = "RESERVED";
  v131 = "UNUSABLE";
  v128 = "INVALID";
  v132 = "EXCLUDE";
  do
  {
    v17 = &p_coverManager->knownCover.list[v110];
    if ( (unsigned __int8)idAICover::operator==(this: v17, other: &this->excludeCover) != 0 )
    {
      Origin = idAICover::GetOrigin(this: v17);
      idCoverQuery::DebugFailed(this, message: v132, origin: &Origin->origin, minLevel: 2);
      goto LABEL_79;
    }
    if ( (unsigned __int8)idAICover::IsValid(this: v17) == 0 )
    {
      v19 = idAICover::GetOrigin(this: v17);
      idCoverQuery::DebugFailed(this, message: v128, origin: &v19->origin, minLevel: 2);
      goto LABEL_79;
    }
    if ( (unsigned __int8)idAICover::IsUsable(this: v17) == 0 )
    {
      v20 = idAICover::GetOrigin(this: v17);
      idCoverQuery::DebugFailed(this, message: v131, origin: &v20->origin, minLevel: 2);
      goto LABEL_79;
    }
    if ( (unsigned __int8)idAICover::IsReserved(this: v17) != 0 && idAICover::GetReserver(this: v17) != this->ai )
    {
      Reserver = (idAI2 *)idAICover::GetReserver(this: v17);
      v22 = idAI2::CastTo(c: Reserver);
      if ( v22 != nullptr && v22->aiVolatile.memory.currentCover.coverIndex == v17->coverIndex )
      {
        v23 = idAICover::GetOrigin(this: v17);
        idCoverQuery::DebugFailed(this, message: v130, origin: &v23->origin, minLevel: 2);
        goto LABEL_79;
      }
      idLib::Warning(fmt: v127, v17->coverIndex);
      idAICover::Unreserve(this: v17);
    }
    if ( (this->queryFlags & 0x10) == 0 && idAICover::IsPartiallyExposed(this: v17) )
    {
      v24 = idAICover::GetOrigin(this: v17);
      idCoverQuery::DebugFailed(this, message: "PARTIAL", origin: &v24->origin, minLevel: 2);
      goto LABEL_79;
    }
    CoverPosture = idAICover::GetCoverPosture(this: v17);
    if ( CoverPosture == 2 )
    {
      if ( (this->queryFlags & 8) == 0 )
      {
        v26 = idAICover::GetOrigin(this: v17);
        idCoverQuery::DebugFailed(this, message: "CROUCHING", origin: &v26->origin, minLevel: 2);
        goto LABEL_79;
      }
    }
    else if ( CoverPosture == 1 && (this->queryFlags & 4) == 0 )
    {
      v27 = idAICover::GetOrigin(this: v17);
      idCoverQuery::DebugFailed(this, message: "STANDING", origin: &v27->origin, minLevel: 2);
      goto LABEL_79;
    }
    if ( idAIBehaviors::FindBestCoverOrientation(this: &this->ai->aiEditable.behaviors, ai: this->ai, cover: v17) == 0 )
    {
      v28 = idAICover::GetOrigin(this: v17);
      idCoverQuery::DebugFailed(this, message: "ORIENTATION", origin: &v28->origin, minLevel: 2);
      goto LABEL_79;
    }
    v29 = idAICover::GetOrigin(this: v17);
    v30 = (float)(v29->origin.y - this->aiaiPos.origin.y);
    v31 = (float)(v29->origin.x - this->aiaiPos.origin.x);
    v32 = (float)(v29->origin.z - this->aiaiPos.origin.z);
    v33 = *(int (__fastcall **)(int))(*(_DWORD *)v7 + 20);
    v135 = (int)(float)((float)__fsqrts((float)((float)((float)v32 * (float)v32)
                                              + (float)((float)((float)v31 * (float)v31)
                                                      + (float)((float)v30 * (float)v30))))
                      * (float)4.1666665);
    v34 = v135;
    v35 = v33(a1: v7);
    v36 = &v111;
    v37 = (_DWORD *)(v35 + 96);
    for ( i = 6; i != 0; --i )
      *++v36 = *++v37;
    v39 = idAICover::GetOrigin(this: v17);
    v40 = 0;
    x = v39->origin.x;
    y = v39->origin.y;
    next = gameLocal->actorEntities.next;
    z = v39->origin.z;
    v45 = (float)(v112.b[0].x + v39->origin.x);
    v46 = (float)(v112.b[0].y + v39->origin.y);
    v47 = (float)(v112.b[0].z + v39->origin.z);
    v48 = (float)(v112.b[1].x + v39->origin.x);
    v112.b[0].x = v112.b[0].x + v39->origin.x;
    v112.b[0].y = v46;
    v49 = (float)(v112.b[1].y + (float)y);
    v112.b[0].z = v47;
    v50 = (float)(v112.b[1].z + (float)z);
    v112.b[1].x = v112.b[1].x + (float)x;
    v112.b[1].y = v112.b[1].y + (float)y;
    v112.b[1].z = v112.b[1].z + (float)z;
    if ( next == nullptr )
      goto LABEL_50;
    if ( next == gameLocal->actorEntities.head )
      goto LABEL_50;
    owner = (idAI2 *)next->owner;
    if ( owner == nullptr )
      goto LABEL_50;
    while ( 1 )
    {
      if ( owner == this->ai )
        goto LABEL_42;
      v52 = (int)owner->GetHealthComponent(this: owner);
      if ( v52 == 0 || (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v52 + 88))(a1: v52) != 0 )
        goto LABEL_42;
      v53 = idEntity::GetPhysics(this: owner);
      v54 = (idBounds *)v53->GetAbsBounds(this: v53, a2: -1);
      if ( (unsigned __int8)idBounds::IntersectsBounds(this: v54, a: &v112) != 0 )
        break;
      v55 = idAI2::CastTo(c: owner);
      if ( v55 != nullptr )
      {
        p_cachedCover = &v55->aiVolatile.memory.cachedCover;
        if ( (unsigned __int8)idAICover::IsValid(this: &v55->aiVolatile.memory.cachedCover) != 0 )
        {
          v57 = (*(int (__fastcall **)(int))(*(_DWORD *)v7 + 20))(a1: v7);
          v58 = &v116;
          v59 = (_DWORD *)(v57 + 96);
          for ( j = 6; j != 0; --j )
            *++v58 = *++v59;
          v61 = idAICover::GetOrigin(this: p_cachedCover);
          v62 = v61->origin.z;
          v63 = (float)(v117.b[0].y + v61->origin.y);
          v64 = (float)(v117.b[0].z + v61->origin.z);
          v65 = (float)(v117.b[1].x + v61->origin.x);
          v66 = (float)(v117.b[1].y + v61->origin.y);
          v117.b[0].x = v117.b[0].x + v61->origin.x;
          v117.b[0].y = v63;
          v117.b[0].z = v64;
          v117.b[1].x = v65;
          v117.b[1].y = v66;
          v117.b[1].z = v117.b[1].z + (float)v62;
          if ( (unsigned __int8)idBounds::IntersectsBounds(this: &v117, a: &v112) != 0 )
            goto LABEL_49;
        }
      }
LABEL_42:
      v67 = owner->actorNode.next;
      if ( v67 == nullptr || v67 == owner->actorNode.head )
        v68 = nullptr;
      else
        v68 = (idAI2 *)v67->owner;
      owner = v68;
      if ( v68 == nullptr )
        goto LABEL_50;
    }
    v69 = idEntity::GetPhysics(this: owner);
    v70 = v69->GetOrigin(this: v69, a2: 0);
    v71 = idAICover::GetOrigin(this: v17);
    idCoverQuery::DebugFailedTarget(this, message: "BLOCKED", origin: &v71->origin, targetOrigin: v70, minLevel: 2);
LABEL_49:
    v40 = 1;
LABEL_50:
    if ( v40 != 0 )
    {
      v72 = idAICover::GetOrigin(this: v17);
      idCoverQuery::DebugFailed(this, message: "BLOCKED", origin: &v72->origin, minLevel: 2);
    }
    else
    {
      v73 = gameLocal->coverBlockerEntities.next;
      if ( v73 != nullptr && v73 != gameLocal->coverBlockerEntities.head )
      {
        v74 = v73->owner;
        if ( v74 != nullptr )
        {
          while ( 1 )
          {
            if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v74) == 0 )
            {
              v75 = (*(int (__fastcall **)(int))(*(_DWORD *)v7 + 20))(a1: v7);
              v76 = &v118;
              v77 = (_DWORD *)(v75 + 96);
              for ( k = 6; k != 0; --k )
                *++v76 = *++v77;
              v79 = idEntity::GetPhysics(this: v74);
              v80 = (float *)v79->GetOrigin(this: v79, a2: 0);
              v81 = (float)(v119 + *v80);
              v82 = (float)(v122 + *v80);
              v83 = v80[2];
              v84 = (float)(v120 + v80[1]);
              v85 = (float)(v121 + v80[2]);
              v86 = (float)(v123 + v80[1]);
              v87 = (float)(v124 + v80[2]);
              v119 = v119 + *v80;
              v120 = v84;
              v121 = v85;
              v122 = v82;
              v123 = v86;
              v124 = v124 + (float)v83;
              if ( v48 < v81 || v49 < v84 || v50 < v85 || v45 > v82 || v46 > v86 || (v88 = 1, v47 > v87) )
                v88 = 0;
              if ( v88 != 0 )
                break;
            }
            listenerList = (idEntity_vtbl *)v74[1].listenerList;
            if ( listenerList == nullptr || listenerList == v74[1].__vftable )
              RespondsTo = nullptr;
            else
              RespondsTo = (idEntity *)listenerList->RespondsTo;
            v74 = RespondsTo;
            if ( RespondsTo == nullptr )
              goto LABEL_73;
          }
          v40 = 1;
        }
      }
LABEL_73:
      if ( v40 != 0 )
      {
        v91 = idAICover::GetOrigin(this: v17);
        idCoverQuery::DebugFailed(this, message: "COVER_BLOCKER", origin: &v91->origin, minLevel: 2);
      }
      else
      {
        v92 = idList<idCoverQuery::coverCache_t,5>::Alloc(this: p_relevantCover);
        v92->index = v16;
        v93 = idAICover::GetOrigin(this: v17);
        idAASPosition::Update(this: &v92->vcPos, aas, origin: &v93->origin);
        v94 = v17->aas;
        v95 = idAICover::GetOrigin(this: v17);
        AreaNum = (unsigned __int16)idAICover::GetAreaNum(this: v17);
        idAASPosition::Initialize(this: &v92->aiPos, _aas: v94, _areaNum: AreaNum, _origin: &v95->origin);
        v97 = idAICover::GetOrigin(this: v17);
        LODWORD(v98) = v34;
        v99 = (float)(v97->origin.y - this->aiaiPos.origin.y);
        v100 = this->aiaiPos.origin.x;
        v101 = v97->origin.x;
        *(_QWORD *)&v134[4] = v98;
        v102 = (float)(v97->origin.z - this->aiaiPos.origin.z);
        v92->delta.y = v99;
        v92->delta.z = v102;
        v92->delta.x = (float)v101 - (float)v100;
        v92->linearDistance = __fsqrts((float)((float)((float)v102 * (float)v102)
                                             + (float)((float)((float)((float)v101 - (float)v100)
                                                             * (float)((float)v101 - (float)v100))
                                                     + (float)((float)v99 * (float)v99))));
        v92->score = 1.0;
        v92->travelTime = (float)v98 * (float)0.001;
        if ( (float)((float)v98 * (float)0.001) < (double)this->minTravelTime )
        {
          this->minTravelTime = (float)v98 * (float)0.001;
          this->minTravelTimeIndex = v16;
        }
        if ( v92->travelTime > (double)this->maxTravelTime )
        {
          this->maxTravelTime = v92->travelTime;
          this->maxTravelTimeIndex = v16;
        }
      }
    }
LABEL_79:
    p_coverManager = v129;
    ++v16;
    ++v110;
  }
  while ( v16 < v129->knownCover.num );
LABEL_80:
  _FP11 = (float)((float)(this->maxTravelTime - this->minTravelTime) - (float)0.001);
  __asm { fsel      f10, f11, f12, f0 }
  this->travelTimeRange = _FP10;
  if ( v133.logIndex >= 0 )
  {
    pLog = v133.pLog;
    v106 = &v133.pLog->logEntries.list[v133.logIndex];
    v107 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v106->totalTicks;
    HIDWORD(totalTicks) = v106->parent;
    LODWORD(v109) = v107 - totalTicks;
    v106->totalTicks = v109;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$489399
// EA  : 0x82A8C71C
// RVA : 0x00A8C71C
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489399()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 496 + 272));
}


// ========================================================================
// __unwind$489400
// EA  : 0x82A8C744
// RVA : 0x00A8C744
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489400()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 496 + 232));
}


// ========================================================================
// ?Execute@idCoverQuery@@QAA_NABV?$idList@UcoverTarget_t@idCoverQuery@@$04@@ABVidVec3@@AAVidAICover@@_N@Z
// EA  : 0x82A8C778
// RVA : 0x00A8C778
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

int __fastcall idCoverQuery::Execute(
        idCoverQuery *this,
        const idList<idCoverQuery::coverTarget_t,5> *targets,
        const idVec3 *referencePoint,
        idAICover *bestCover,
        bool inAvoid)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  idAI2 *v12; // r3
  unsigned int DebugLevel; // r3
  int GameMs; // r3
  idAAS2 *v15; // r28
  double v16; // fp23
  double v17; // fp26
  int v18; // r19
  int v19; // r24
  int v20; // r20
  int v21; // r27
  int v22; // r28
  idCoverQuery::coverCache_t *v23; // r29
  double v24; // fp1
  double v25; // fp0
  idAI2 *ai; // r10
  idCoverQuery::coverCache_t *list; // r11
  double v28; // fp22
  double v29; // fp21
  double v30; // fp20
  const aas2Cover_t *Origin; // r3
  double v32; // fp9
  double v33; // fp7
  double v34; // fp6
  double score; // fp5
  double v36; // fp3
  __int64 v37; // r6
  __int64 v38; // r10
  __int64 v39; // r8
  va *v40; // r3
  const aas2Cover_t *v41; // r3
  double z; // fp13
  double y; // fp12
  __int64 v44; // r6
  __int64 v45; // r10
  __int64 v46; // r8
  va *v47; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v49; // r30
  int v50; // r3
  __int64 totalTicks; // r11
  __int64 v52; // r9
  idPLog *v54; // r29
  idPLog::logEntry_t *v55; // r30
  int v56; // r3
  __int64 v57; // r11
  __int64 v58; // r9
  int v59; // [sp+8h] [-11B8h]
  int v60; // [sp+Ch] [-11B4h]
  int v61; // [sp+10h] [-11B0h]
  int v62; // [sp+14h] [-11ACh]
  int v63; // [sp+18h] [-11A8h]
  int v64; // [sp+1Ch] [-11A4h]
  double v65; // [sp+20h] [-11A0h]
  idPLogScope v66[2]; // [sp+60h] [-1160h] BYREF
  idColor v67; // [sp+70h] [-1150h] BYREF
  float v68; // [sp+80h] [-1140h] BYREF
  float v69; // [sp+84h] [-113Ch]
  float v70; // [sp+88h] [-1138h]
  float v71[4]; // [sp+90h] [-1130h] BYREF
  float v72[4]; // [sp+A0h] [-1120h] BYREF
  float v73[4]; // [sp+B0h] [-1110h] BYREF
  bfx::BinaryReplayLogOut v74[9]; // [sp+C0h] [-1100h] BYREF

  RD_EventBegin(name: "idCoverQuery::Execute");
  LODWORD(v10) = "idCoverQuery::Execute";
  HIDWORD(v10) = 6;
  idPLogScope::idPLogScope(this: v66, pl: &::pLog, gMask: v10, label: v11);
  if ( ai_debugCoverEntityId.valueInteger == 0
    || (v12 = (idAI2 *)((int (__fastcall *)(idGameLocal *))gameLocal->GetEntity)(a1: gameLocal),
        idAI2::CastTo(c: v12) == this->ai) )
  {
    DebugLevel = idAI2::GetDebugLevel();
    this->debugLevel = ((DebugLevel == 0) + (DebugLevel >> 31) - 1) & ai_debugCover.valueInteger;
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( (unsigned __int8)idAICoverManager::HasCover(
                          this: &this->ai->aiVolatile.coverManager,
                          ai: this->ai,
                          referencePoint,
                          curTime: GameMs,
                          inAvoid) == 0 )
  {
    idPLogScope::~idPLogScope(this: v66);
LABEL_31:
    RD_EventEnd();
    return 0;
  }
  v15 = (idAAS2 *)this->ai->GetAAS(this: this->ai);
  idAASPosition::Update(this: &this->aivcPos, aas: (idAAS2 *)gameLocal->aasVisCache.aas, ent: this->ai);
  idAASPosition::Update(this: &this->aiaiPos, aas: v15, ent: this->ai);
  idCoverQuery::FindRelevantCover(this);
  idCoverQuery::PreScore(this);
  if ( inAvoid )
    v16 = 0.1;
  else
    v16 = 0.0;
  v17 = 0.0;
  v18 = -1;
  v19 = 0;
  if ( targets->num > 0 )
  {
    v20 = 0;
    do
    {
      idCoverQuery::SetupTarget(this, newTarget: &targets->list[v20]);
      v21 = 0;
      if ( this->relevantCover.num > 0 )
      {
        v22 = 0;
        do
        {
          v23 = &this->relevantCover.list[v22];
          v24 = idCoverQuery::ScoreCover(this, cached: v23);
          v25 = (float)((float)v24 * v23->score);
          v23->score = (float)v24 * v23->score;
          if ( v19 == targets->num - 1 )
          {
            if ( v25 > v17 && v25 > v16 )
            {
              v17 = v25;
              v18 = v21;
            }
            if ( ai_debugCover.valueInteger >= 1 )
            {
              v68 = 0.0;
              ai = this->ai;
              v69 = 0.0;
              list = this->relevantCover.list;
              v70 = -1.0;
              idAICover::idAICover(
                this: (idAICover *)v74,
                other: &ai->aiVolatile.coverManager.knownCover.list[list[v22].index]);
              v28 = (float)(v70 * (float)-3.0);
              v29 = (float)(v69 * (float)-3.0);
              v30 = (float)(v68 * (float)-3.0);
              Origin = idAICover::GetOrigin(this: (idAICover *)v74);
              v32 = (float)(Origin->origin.z + (float)v28);
              v33 = (float)(Origin->origin.y + (float)v29);
              v34 = (float)(Origin->origin.x + (float)v30);
              v67.a = -1.0;
              v67.b = -1.0;
              v67.g = -1.0;
              v67.r = -1.0;
              v72[0] = v34;
              v72[2] = v32;
              v72[1] = v33;
              score = v23->score;
              v36 = (float)((float)(v23->score + (float)1.0) * (float)0.5);
              v67.r = (float)(v23->score + (float)1.0) * (float)0.5;
              v67.a = 1.0;
              v67.g = v36;
              v67.b = v36;
              if ( score == 0.0 )
                v67 = idColor::colorBlack;
              ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugCircle)(
                a1: clientGame->renderWorld,
                a2: &v67,
                a3: v72,
                a4: &v68,
                a5: 16.0);
              v65 = v23->score;
              HIDWORD(v37) = LODWORD(v65);
              v40 = va::va(
                      this: (va *)&v74[0].m_buf.m_size,
                      fmt: (const char *)HIDWORD(v65),
                      a3: v37,
                      a4: v39,
                      a5: v38,
                      a6: v59,
                      a7: v60,
                      a8: v61,
                      a9: v62,
                      a10: v63,
                      a11: v64);
              ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
                a1: clientGame->renderWorld,
                a2: v40,
                a3: v72,
                a4: clientGame->renderWorld->__vftable,
                a5: &v67,
                a6: 1,
                a7: 3000,
                a8: 0,
                a9: 0.07);
              idPhysics_StaticMulti::UpdateTime(this: v74);
            }
          }
          ++v21;
          ++v22;
        }
        while ( v21 < this->relevantCover.num );
      }
      ++v19;
      ++v20;
    }
    while ( v19 < targets->num );
    if ( v18 >= 0 )
    {
      idAICover::operator=(
        this: bestCover,
        other: &this->ai->aiVolatile.coverManager.knownCover.list[this->relevantCover.list[v18].index]);
      if ( ai_debugCover.valueInteger >= 1 )
      {
        v73[0] = 0.0;
        v73[1] = 0.0;
        v73[2] = -1.0;
        v41 = idAICover::GetOrigin(this: bestCover);
        z = v41->origin.z;
        y = v41->origin.y;
        v71[0] = v41->origin.x;
        v71[1] = y;
        v71[2] = (float)z + (float)4.0;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugCircle)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorGreen,
          a3: v71,
          a4: v73,
          a5: 16.0);
        HIDWORD(v44) = LODWORD(v17);
        v47 = va::va(
                this: (va *)&v74[0].m_buf.m_size,
                fmt: "score: %5.3f",
                a3: v44,
                a4: v46,
                a5: v45,
                a6: v59,
                a7: v60,
                a8: v61,
                a9: v62,
                a10: v63,
                a11: v64,
                v17);
        ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
          a1: clientGame->renderWorld,
          a2: v47,
          a3: v71,
          a4: clientGame->renderWorld->__vftable,
          a5: &idColor::colorGreen,
          a6: 1,
          a7: 3000,
          a8: 0,
          a9: 0.07);
      }
      if ( v66[0].logIndex >= 0 )
      {
        pLog = v66[0].pLog;
        v49 = &v66[0].pLog->logEntries.list[v66[0].logIndex];
        v50 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v49->totalTicks;
        HIDWORD(totalTicks) = v49->parent;
        LODWORD(v52) = v50 - totalTicks;
        v49->totalTicks = v52;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
      RD_EventEnd();
      return 1;
    }
  }
  if ( v66[0].logIndex >= 0 )
  {
    v54 = v66[0].pLog;
    v55 = &v66[0].pLog->logEntries.list[v66[0].logIndex];
    v56 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v57 = v55->totalTicks;
    HIDWORD(v57) = v55->parent;
    LODWORD(v58) = v56 - v57;
    v55->totalTicks = v58;
    v54->lastEntry = HIDWORD(v57);
  }
  goto LABEL_31;
}


// ========================================================================
// __unwind$489932
// EA  : 0x82A8CCF0
// RVA : 0x00A8CCF0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489932()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4544 + 4304));
}


// ========================================================================
// __unwind$489933
// EA  : 0x82A8CD18
// RVA : 0x00A8CD18
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489933()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4544 + 96));
}


// ========================================================================
// __unwind$489934
// EA  : 0x82A8CD40
// RVA : 0x00A8CD40
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void _unwind_489934()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 4544 + 192));
}


// ========================================================================
// `dynamic initializer for 'idCoverQuery::MAX_COVER_ARC_ACOS_DEGREES''
// EA  : 0x83368FF0
// RVA : 0x01368FF0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__idCoverQuery::MAX_COVER_ARC_ACOS_DEGREES__(long double a1)
{
  *(double *)&a1 = (float)(idMath::M_DEG2RAD * (float)55.0);
  idCoverQuery::MAX_COVER_ARC_ACOS_DEGREES = cos(x: a1);
}

