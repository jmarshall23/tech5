
// ========================================================================
// ??1idAnimWebAI@@UAA@XZ
// EA  : 0x82A85C48
// RVA : 0x00A85C48
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::~idAnimWebAI(idAnimWebAI *this)
{
  this->__vftable = (idAnimWebAI_vtbl *)&idAnimWebAI::`vftable';
  idAnimator_AnimWeb::~idAnimator_AnimWeb(this);
}


// ========================================================================
// ??0idAnimWebAI@@QAA@XZ
// EA  : 0x82A85C58
// RVA : 0x00A85C58
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

idAnimWebAI *__fastcall idAnimWebAI::idAnimWebAI(idAnimWebAI *this)
{
  idAnimator_AnimWeb::idAnimator_AnimWeb(this);
  this->ai = nullptr;
  this->__vftable = (idAnimWebAI_vtbl *)&idAnimWebAI::`vftable';
  this->bodyTurnDot = 0.0;
  this->bodyTurnDir = TURN_NONE;
  this->movementTurnDot = 0.0;
  this->movementTurnDir = TURN_NONE;
  this->forwardRunIndex = 0.0;
  this->runIndexType = ANIMWEBAI_RUNINDEXTYPE_NORMAL;
  this->leftRunIndex = 1.0;
  this->nextRunIndexType = ANIMWEBAI_RUNINDEXTYPE_NORMAL;
  this->rightRunIndex = 2.0;
  this->runIndexChangeFrame = 0;
  this->backRunIndex = 3.0;
  this->debug = false;
  this->injuredRunOffset = 0.0;
  this->previousRunIndex = 0.0;
  this->forwardRunBlend = 1.0;
  this->forwardRunBlendLinear = 1.0;
  this->deathAnimIndex = 0.0;
  this->startTransitionIndex = 0.0;
  this->stopTransitionIndex = 0.0;
  this->aimAlpha = 0.0;
  this->nextRunIndex = 0.0;
  this->idleIndex = 0.0;
  this->nextIdleIndex = 0.0;
  this->previousIdleIndex = 0.0;
  this->blendBack = 0.0;
  this->blendRight = 0.0;
  this->blendAngle = 0.0;
  this->walkRate = 1.0;
  this->runRate = 1.0;
  this->deathScale = 1.0;
  this->desiredTurn = 0.0;
  this->sync8index1 = 0.0;
  this->sync8index2 = 0.0;
  this->sync8blendAngle = 0.0;
  this->select01 = 0.0;
  this->traversalAttack = 0.0;
  this->diveIndex = 0.0;
  this->transitionSelect = 0.0;
  this->toCombatTurn = 0.0;
  this->toSearchTurn = 0.0;
  this->turnLeanDirection = 0.0;
  this->turnLeanAmount = 0.0;
  this->gangstaAlpha = 0.0;
  return this;
}


// ========================================================================
// ?InternalStartPath@idAnimWebAI@@MAAXXZ
// EA  : 0x82A85DD0
// RVA : 0x00A85DD0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::InternalStartPath(idAnimWebAI *this)
{
  idAIOrientation *BodyOrientation; // r29
  idAIOrientation *v3; // r3
  turnDirection_t v4; // r11
  idAIOrientation *MoveOrientation; // r29
  idAIOrientation *v6; // r3
  turnDirection_t v7; // r11

  BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
  v3 = idAI2::GetBodyOrientation(this: this->ai);
  this->bodyTurnDot = (float)(v3->axis.mat[0].x * BodyOrientation->idealDir.x)
                    + (float)((float)(v3->axis.mat[0].z * BodyOrientation->idealDir.z)
                            + (float)(v3->axis.mat[0].y * BodyOrientation->idealDir.y));
  v4 = TURN_LEFT;
  if ( (float)((float)(VEC_LEFT.y * BodyOrientation->idealDir.y)
             + (float)((float)(BodyOrientation->idealDir.z * VEC_LEFT.z)
                     + (float)(BodyOrientation->idealDir.x * VEC_LEFT.x))) > 0.0 )
    v4 = TURN_RIGHT;
  this->bodyTurnDir = v4;
  MoveOrientation = idAI2::GetMoveOrientation(this: this->ai);
  v6 = idAI2::GetMoveOrientation(this: this->ai);
  v7 = TURN_LEFT;
  this->movementTurnDot = (float)(v6->axis.mat[0].x * MoveOrientation->idealDir.x)
                        + (float)((float)(v6->axis.mat[0].y * MoveOrientation->idealDir.y)
                                + (float)(v6->axis.mat[0].z * MoveOrientation->idealDir.z));
  if ( (float)((float)(MoveOrientation->idealDir.y * VEC_LEFT.y)
             + (float)((float)(MoveOrientation->idealDir.z * VEC_LEFT.z)
                     + (float)(MoveOrientation->idealDir.x * VEC_LEFT.x))) > 0.0 )
    v7 = TURN_RIGHT;
  this->movementTurnDir = v7;
}


// ========================================================================
// ?EaseInEaseOut@@YAMM@Z
// EA  : 0x82A85EF0
// RVA : 0x00A85EF0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

float __fastcall EaseInEaseOut(double linearInput)
{
  double v1; // fp1
  double v2; // fp9

  if ( linearInput >= 0.5 )
  {
    v2 = (float)((float)1.0 - (float)((float)((float)linearInput - (float)0.5) * 2.0));
    v1 = (float)((float)((float)1.0 - (float)((float)((float)v2 * (float)v2) - (float)1.0)) * (float)0.5);
  }
  else
  {
    v1 = (float)((float)((float)((float)linearInput * 2.0) * (float)((float)linearInput * 2.0)) * (float)0.5);
  }
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?SetForwardRunIndex@idAnimWebAI@@QAAXMMW4runIndexType_t@@_N@Z
// EA  : 0x82A85F40
// RVA : 0x00A85F40
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::SetForwardRunIndex(
        idAnimWebAI *this,
        double newRunIndex,
        double newIdleIndex,
        const runIndexType_t t,
        const bool blend,
        runIndexType_t a6,
        char a7)
{
  runIndexType_t runIndexType; // r11
  runIndexType_t nextRunIndexType; // r10
  bool v14; // cr58
  int v15; // r3
  double forwardRunIndex; // fp0
  double idleIndex; // fp13
  int v18; // r3

  runIndexType = this->runIndexType;
  if ( runIndexType == ANIMWEBAI_RUNINDEXTYPE_INJURED
    || (nextRunIndexType = this->nextRunIndexType) == ANIMWEBAI_RUNINDEXTYPE_INJURED )
  {
    if ( this->ai->aiEditable.behaviors.decl->damageBehaviors.injuredRunMode == AIINJUREDRUNMODE_RECENTLYDAMAGED )
      goto LABEL_22;
    v14 = a6 == ANIMWEBAI_RUNINDEXTYPE_INJURED;
    goto LABEL_21;
  }
  if ( runIndexType == ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE || nextRunIndexType == ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE )
  {
    if ( (unsigned int)a6 <= ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE || a6 == ANIMWEBAI_RUNINDEXTYPE_UP_STAIRS )
      goto LABEL_22;
    v14 = a6 == ANIMWEBAI_RUNINDEXTYPE_DOWN_STAIRS;
LABEL_21:
    if ( !v14 )
      return;
    goto LABEL_22;
  }
  if ( runIndexType == ANIMWEBAI_RUNINDEXTYPE_DUCK || nextRunIndexType == ANIMWEBAI_RUNINDEXTYPE_DUCK )
  {
    if ( a6 == ANIMWEBAI_RUNINDEXTYPE_INJURED
      && this->ai->aiEditable.behaviors.decl->damageBehaviors.injuredRunMode == AIINJUREDRUNMODE_RECENTLYDAMAGED )
    {
      return;
    }
  }
  else if ( (runIndexType == ANIMWEBAI_RUNINDEXTYPE_UP_STAIRS || nextRunIndexType == ANIMWEBAI_RUNINDEXTYPE_UP_STAIRS)
         && (a6 == ANIMWEBAI_RUNINDEXTYPE_FAR
          || a6 == ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE
          || a6 == ANIMWEBAI_RUNINDEXTYPE_GUNDOWN) )
  {
    return;
  }
LABEL_22:
  if ( this->forwardRunBlendLinear == 1.0 )
  {
    v15 = gameLocal->GetGameFrame(this: gameLocal);
    forwardRunIndex = this->forwardRunIndex;
    this->runIndexChangeFrame = v15;
    if ( forwardRunIndex != newRunIndex )
    {
      if ( a7 != 0 )
      {
        this->forwardRunBlendLinear = 0.0;
        this->forwardRunBlend = 0.0;
      }
      idleIndex = this->idleIndex;
      this->runIndexType = a6;
      this->forwardRunIndex = newRunIndex;
      this->nextRunIndexType = a6;
      this->nextRunIndex = newRunIndex;
      this->previousIdleIndex = idleIndex;
      this->idleIndex = newIdleIndex;
      this->previousRunIndex = forwardRunIndex;
      this->nextIdleIndex = newIdleIndex;
      if ( a6 == ANIMWEBAI_RUNINDEXTYPE_INJURED )
      {
        this->leftRunIndex = (float)newRunIndex + (float)1.0;
        this->injuredRunOffset = newRunIndex;
        this->rightRunIndex = (float)newRunIndex + (float)2.0;
        this->backRunIndex = (float)newRunIndex + (float)3.0;
      }
      if ( ai_debugLevel.valueInteger != 0 && ai_debugForwardRunIndex.valueInteger != 0 )
      {
        v18 = idAccolade::Count(this: &clientGame->gameTimeManager);
        idLib::Printf(fmt: "[ %d ] %.0f->%.0f\n", v18, this->previousRunIndex, this->forwardRunIndex);
      }
    }
  }
  else
  {
    this->nextRunIndex = newRunIndex;
    this->nextRunIndexType = a6;
    this->nextIdleIndex = newIdleIndex;
  }
}


// ========================================================================
// ?InternalInitWeb@idAnimWebAI@@MAAXXZ
// EA  : 0x82A86190
// RVA : 0x00A86190
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::InternalInitWeb(idAnimWebAI *this)
{
  idAnimator_AnimWeb::InternalInitWeb(this);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "blendBack", scalar: &this->blendBack, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "blendRight", scalar: &this->blendRight, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "blendAngle", scalar: &this->blendAngle, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "forwardRunIndex",
    scalar: &this->forwardRunIndex,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "leftRunIndex", scalar: &this->leftRunIndex, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "rightRunIndex", scalar: &this->rightRunIndex, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "backRunIndex", scalar: &this->backRunIndex, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "idleIndex", scalar: &this->idleIndex, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "previousIdleIndex",
    scalar: &this->previousIdleIndex,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "injuredRunOffset",
    scalar: &this->injuredRunOffset,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "deathAnimIndex",
    scalar: &this->deathAnimIndex,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "previousRunIndex",
    scalar: &this->previousRunIndex,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "forwardRunBlend",
    scalar: &this->forwardRunBlend,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "forwardRunBlendLinear",
    scalar: &this->forwardRunBlendLinear,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "startTransitionIndex",
    scalar: &this->startTransitionIndex,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "stopTransitionIndex",
    scalar: &this->stopTransitionIndex,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "aimAlpha", scalar: &this->aimAlpha, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "gangstaAlpha", scalar: &this->gangstaAlpha, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "walkRate", scalar: &this->walkRate, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "runRate", scalar: &this->runRate, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "deathScale", scalar: &this->deathScale, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "desiredTurn", scalar: &this->desiredTurn, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "sync8index1", scalar: &this->sync8index1, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "sync8index2", scalar: &this->sync8index2, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "sync8blendAngle",
    scalar: &this->sync8blendAngle,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "select01", scalar: &this->select01, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "traversalAttack",
    scalar: &this->traversalAttack,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "diveIndex", scalar: &this->diveIndex, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "transitionSelect",
    scalar: &this->transitionSelect,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "toCombatTurn", scalar: &this->toCombatTurn, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "toSearchTurn", scalar: &this->toSearchTurn, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "turnLeanDirection",
    scalar: &this->turnLeanDirection,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "turnLeanAmount",
    scalar: &this->turnLeanAmount,
    flags: FF_NO_OVERRIDE);
  this->ai->aiVolatile.animation.animFSM.RegisterBlendVariables(this: &this->ai->aiVolatile.animation.animFSM, a2: this);
}


// ========================================================================
// ?CheckNextNode@idAnimWebAI@@UAA?AW4awCheckPathResult_t@@PBVidDeclAnimWebNode@@0@Z
// EA  : 0x82A864F8
// RVA : 0x00A864F8
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

awCheckPathResult_t __fastcall idAnimWebAI::CheckNextNode(
        idAnimWebAI *this,
        const idDeclAnimWebNode *curNode,
        const idDeclAnimWebNode *nextNode)
{
  if ( nextNode != nullptr && (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)this->ai) != 0 )
    return this->ai->aiVolatile.animation.animFSM.AnimCheckNextNode(
             this: &this->ai->aiVolatile.animation.animFSM,
             a2: this,
             a3: curNode,
             a4: nextNode);
  else
    return CHECKPATH_OK;
}


// ========================================================================
// ?InternalFinishBlend@idAnimWebAI@@MAAXPBVidDeclAnimWebNode@@0H@Z
// EA  : 0x82A86568
// RVA : 0x00A86568
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::InternalFinishBlend(
        idAnimWebAI *this,
        const idDeclAnimWebNode *prevNode,
        const idDeclAnimWebNode *curNode,
        const int curTime)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)this->ai) != 0 )
    this->ai->aiVolatile.animation.animFSM.AnimFinishBlend(
      this: &this->ai->aiVolatile.animation.animFSM,
      a2: prevNode,
      a3: curNode);
}


// ========================================================================
// ?InternalGetEdgeCost@idAnimWebAI@@MBAHV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidEdgeIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A865C0
// RVA : 0x00A865C0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

int __fastcall idAnimWebAI::InternalGetEdgeCost(
        idAnimWebAI *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *edgeIndex)
{
  const idDeclAnimWeb *decl; // r10
  int result; // r3
  unsigned int v5; // r4

  decl = this->decl;
  result = 100;
  if ( (decl->edgeCache.list[(__int16)edgeIndex].flags & 1) != 0 )
  {
    v5 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v5;
    return 100 - (int)((v5 >> 10) & 0x7FFF) % 10;
  }
  return result;
}


// ========================================================================
// ?UpdateDesiredTurnIndex@idAnimWebAI@@QAAXXZ
// EA  : 0x82A86648
// RVA : 0x00A86648
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::UpdateDesiredTurnIndex(idAnimWebAI *this)
{
  idAIOrientation *BodyOrientation; // r3
  idEntity *ai; // r11
  idPhysics *Physics; // r3
  double v5; // fp31
  idPhysics *v6; // r3
  float *v7; // r3
  double v8; // fp9
  double y; // fp22
  double v10; // fp18
  double v12; // fp2
  double v14; // fp13
  double v15; // fp3
  double v16; // fp2
  double v17; // fp30
  double v18; // fp28
  double v19; // fp29
  double v20; // fp13
  double v21; // fp0
  int v22; // r27
  double v23; // fp27
  idAIOrientation *MoveOrientation; // r3
  double v25; // fp23
  __int64 v26; // r11
  idAI2 *v27; // r3
  idPhysics *v28; // r30
  idPhysics *v29; // r29
  float *v30; // r3
  double v31; // fp10
  double v32; // fp9
  idPhysics *v33; // r3
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  idRenderWorld_vtbl *v35; // r29
  int v36; // r3
  idPhysics *v37; // r29
  idPhysics *v38; // r26
  float *v39; // r3
  double v40; // fp6
  double v41; // fp3
  idRenderWorld_vtbl *v42; // r29
  int v43; // r3
  idPhysics *v44; // r29
  idPhysics *v45; // r26
  float *v46; // r3
  double v47; // fp0
  double v48; // fp12
  idRenderWorld_vtbl *v49; // r29
  int v50; // r3
  char *v51; // r29
  idPhysics *v52; // r3
  idRenderWorld_vtbl *v53; // r28
  int v54; // r3
  float v56; // [sp+64h] [-11Ch]
  float v57; // [sp+68h] [-118h]
  float z; // [sp+70h] [-110h]
  float x; // [sp+74h] [-10Ch]
  float v60[4]; // [sp+80h] [-100h] BYREF
  float v61[4]; // [sp+90h] [-F0h] BYREF
  float v62[4]; // [sp+A0h] [-E0h] BYREF
  idColor v63; // [sp+B0h] [-D0h] BYREF
  idVec3 v64; // 0:^60.12

  idAI2::GetBodyOrientation(this: this->ai);
  BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
  ai = this->ai;
  z = ai[17].spawnPosition.z;
  v64 = BodyOrientation->axis.mat[0];
  x = ai[17].spawnOrientation.mat[0].x;
  Physics = idEntity::GetPhysics(this: ai);
  v5 = Physics->GetOrigin(this: Physics, a2: 0)->z;
  v6 = idEntity::GetPhysics(this: this->ai);
  v7 = (float *)v6->GetOrigin(this: v6, a2: 0);
  v8 = (float)((float)v5 - v7[2]);
  y = v64.y;
  v10 = v64.z;
  _FP3 = (float)((float)((float)((float)(z - *v7) * (float)(z - *v7))
                       + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1]))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v12 = (float)((float)((float)((float)(z - *v7) * (float)(z - *v7))
                      + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1]))))
              * (float)0.5);
  __asm { fsel      f1, f3, f4, f13 }
  v14 = __frsqrte(_FP1);
  v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14)
                                              * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7))
                                                              + (float)((float)((float)v8 * (float)v8)
                                                                      + (float)((float)(x - v7[1]) * (float)(x - v7[1]))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7))
                                                                                              + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1]))))
                                                                                      * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v14
                                                      * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7))
                                                                      + (float)((float)((float)v8 * (float)v8)
                                                                              + (float)((float)(x - v7[1])
                                                                                      * (float)(x - v7[1]))))
                                                              * (float)0.5))
                                              * (float)v14)
                                      - (float)1.5)
                      * (float)v14));
  v16 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                              * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5))
                                                                                      * (float)v14)
                                                                              - (float)1.5)
                                                              * (float)v14)
                                                      * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7))
                                                                      + (float)((float)((float)v8 * (float)v8)
                                                                              + (float)((float)(x - v7[1])
                                                                                      * (float)(x - v7[1]))))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v14
                                                              * (float)((float)((float)((float)(z - *v7)
                                                                                      * (float)(z - *v7))
                                                                              + (float)((float)((float)v8 * (float)v8)
                                                                                      + (float)((float)(x - v7[1])
                                                                                              * (float)(x - v7[1]))))
                                                                      * (float)0.5))
                                                      * (float)v14)
                                              - (float)1.5)
                              * (float)v14))
              * (float)v12);
  v17 = (float)((float)(x - v7[1])
              * (float)((float)-(float)((float)((float)v16
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                              * (float)v14)
                                                                                      * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                      * (float)v14))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                                              * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5))
                                                                                      * (float)v14)
                                                                              - (float)1.5)
                                                              * (float)v14)))
                                      - (float)1.5)
                      * (float)v15));
  v18 = (float)((float)v8
              * (float)((float)-(float)((float)((float)v16
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                              * (float)v14)
                                                                                      * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                      * (float)v14))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                                              * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5))
                                                                                      * (float)v14)
                                                                              - (float)1.5)
                                                              * (float)v14)))
                                      - (float)1.5)
                      * (float)v15));
  v19 = (float)((float)((float)-(float)((float)((float)v16
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                              * (float)v14)
                                                                                      * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                      * (float)v14))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                                              * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5))
                                                                                      * (float)v14)
                                                                              - (float)1.5)
                                                              * (float)v14)))
                                      - (float)1.5)
                      * (float)v15)
              * (float)(z - *v7));
  v20 = (float)(v64.y
              * (float)((float)(x - v7[1])
                      * (float)((float)-(float)((float)((float)v16
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14)
                                                                                              * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                              * (float)v14))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(z - *v7) * (float)(z - *v7)) + (float)((float)((float)v8 * (float)v8) + (float)((float)(x - v7[1]) * (float)(x - v7[1])))) * (float)0.5))
                                                                                              * (float)v14)
                                                                                      - (float)1.5)
                                                                      * (float)v14)))
                                              - (float)1.5)
                              * (float)v15)));
  v21 = (float)((float)(v64.x * (float)v19) + (float)((float)(v64.z * (float)v18) + (float)v20));
  if ( v21 <= 0.70710677 )
  {
    if ( v21 >= -0.70710677 )
    {
      if ( (float)((float)(v64.y * (float)v19) - (float)((float)v17 * v64.x)) >= 0.0 )
      {
        v22 = 2;
        v23 = 3.0;
      }
      else
      {
        v22 = 1;
        v23 = 2.0;
      }
    }
    else
    {
      v22 = 3;
      v23 = 4.0;
    }
  }
  else
  {
    v22 = 0;
    v23 = 1.0;
  }
  MoveOrientation = idAI2::GetMoveOrientation(this: this->ai);
  v57 = MoveOrientation->idealDir.z;
  v25 = MoveOrientation->idealDir.x;
  v56 = MoveOrientation->idealDir.y;
  if ( (float)((float)(MoveOrientation->idealDir.x * (float)v19)
             + (float)((float)(v57 * (float)v18) + (float)(v56 * (float)v17))) < 0.70710677 )
    v23 = 0.0;
  HIDWORD(v26) = &ai_debugtransitiondirs;
  if ( ai_debugtransitiondirs.valueInteger != 0 )
  {
    v27 = this->ai;
    v63 = idColor::colorYellow;
    v28 = idEntity::GetPhysics(this: v27);
    v29 = idEntity::GetPhysics(this: this->ai);
    v30 = (float *)v28->GetOrigin(this: v28, a2: 0);
    v31 = (float)(v30[1] + (float)(v56 * (float)100.0));
    v32 = (float)(*v30 + (float)((float)v25 * (float)100.0));
    v60[2] = v30[2] + (float)(v57 * (float)100.0);
    v60[0] = v32;
    v33 = v29;
    v60[1] = v31;
    GetOrigin = v29->GetOrigin;
    v35 = clientGame->renderWorld->__vftable;
    v36 = (int)GetOrigin(this: v33, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v35->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorBlue,
      a3: v36,
      a4: v60,
      a5: 4.0);
    v37 = idEntity::GetPhysics(this: this->ai);
    v38 = idEntity::GetPhysics(this: this->ai);
    v39 = (float *)v37->GetOrigin(this: v37, a2: 0);
    v40 = (float)(v39[1] + (float)((float)y * (float)100.0));
    v41 = (float)(*v39 + (float)(v64.x * (float)100.0));
    v61[2] = v39[2] + (float)((float)v10 * (float)100.0);
    v61[1] = v40;
    v61[0] = v41;
    v42 = clientGame->renderWorld->__vftable;
    v43 = (int)v38->GetOrigin(this: v38, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v42->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorWhite,
      a3: v43,
      a4: v61,
      a5: 3.0);
    v44 = idEntity::GetPhysics(this: this->ai);
    v45 = idEntity::GetPhysics(this: this->ai);
    v46 = (float *)v44->GetOrigin(this: v44, a2: 0);
    v47 = (float)(v46[2] + (float)((float)v18 * (float)100.0));
    v48 = (float)(v46[1] + (float)((float)v17 * (float)100.0));
    v62[0] = *v46 + (float)((float)v19 * (float)100.0);
    v62[2] = v47;
    v62[1] = v48;
    v49 = clientGame->renderWorld->__vftable;
    v50 = (int)v45->GetOrigin(this: v45, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v49->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorYellow,
      a3: v50,
      a4: v62,
      a5: 2.0);
    v51 = &byte_8200D768;
    if ( v23 == 0.0 )
    {
      v51 = "passthrough";
    }
    else if ( v23 == 1.0 )
    {
      v51 = "forward";
    }
    else if ( v23 == 2.0 )
    {
      v51 = "turn left";
    }
    else if ( v23 == 3.0 )
    {
      v51 = "turn right";
    }
    else if ( v23 == 4.0 )
    {
      v51 = "turn back";
    }
    v52 = idEntity::GetPhysics(this: this->ai);
    v53 = clientGame->renderWorld->__vftable;
    v54 = (int)v52->GetOrigin(this: v52, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, char *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, int, double))v53->DebugText)(
      a1: clientGame->renderWorld,
      a2: v51,
      a3: v54,
      a4: &off_82040000,
      a5: &v63,
      a6: 1,
      a7: 1000,
      a8: 0.2);
  }
  LODWORD(v26) = v22;
  this->transitionSelect = v23;
  this->desiredTurn = (float)v26;
}


// ========================================================================
// ?CalcToCombatTurn@idAnimWebAI@@QAAXABVidVec3@@@Z
// EA  : 0x82A86BB0
// RVA : 0x00A86BB0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::CalcToCombatTurn(idAnimWebAI *this, const idVec3 *desiredDir)
{
  idAI2 *ai; // r29
  float *presentable; // r11
  double x; // fp11
  double y; // fp9
  double v8; // fp6
  const char *v9; // r30
  double v10; // fp0
  double v11; // fp0
  idPhysics *Physics; // r31
  idRenderWorld *v13; // r29
  idPhysics *v14; // r3
  idRenderWorld_vtbl *v15; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v17; // r3
  float v18; // [sp+60h] [-30h]
  float v19; // [sp+64h] [-2Ch]

  ai = this->ai;
  presentable = (float *)ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    presentable = (float *)ai->presentable;
  }
  x = desiredDir->x;
  y = desiredDir->y;
  v19 = presentable[34];
  v18 = presentable[33];
  v8 = (float)((float)(desiredDir->z * presentable[35]) + (float)(desiredDir->x * v18));
  this->toCombatTurn = 0.0;
  v9 = "forward";
  v10 = (float)((float)((float)y * v19) + (float)v8);
  if ( v10 < 0.70710677 )
  {
    if ( v10 >= -0.70710677 )
    {
      if ( (float)((float)((float)y * v18) - (float)((float)x * v19)) <= 0.0 )
      {
        v9 = "right";
        v11 = 2.0;
      }
      else
      {
        v9 = "left";
        v11 = 1.0;
      }
    }
    else
    {
      v9 = "back";
      v11 = 3.0;
    }
    this->ai->aiVolatile.animation.animWebAnimator.ptr[0].toCombatTurn = v11;
  }
  if ( this->debug )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    v13 = gameLocal->GetRenderWorld(this: gameLocal);
    v14 = Physics;
    GetOrigin = Physics->GetOrigin;
    v15 = v13->__vftable;
    v17 = (int)GetOrigin(this: v14, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, const char *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, int, _DWORD, double))v15->DebugText)(
      a1: v13,
      a2: v9,
      a3: v17,
      a4: &off_82040000,
      a5: &idColor::colorYellow,
      a6: 1,
      a7: 1500,
      a8: 0,
      a9: 0.2);
  }
}


// ========================================================================
// ?CalcToSearchTurn@idAnimWebAI@@QAAXABVidVec3@@@Z
// EA  : 0x82A86D40
// RVA : 0x00A86D40
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::CalcToSearchTurn(idAnimWebAI *this, const idVec3 *desiredDir)
{
  idAI2 *ai; // r29
  float *presentable; // r11
  double x; // fp11
  double y; // fp9
  double v8; // fp6
  const char *v9; // r30
  double v10; // fp0
  double v11; // fp0
  idPhysics *Physics; // r31
  idRenderWorld *v13; // r29
  idPhysics *v14; // r3
  idRenderWorld_vtbl *v15; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v17; // r3
  float v18; // [sp+60h] [-30h]
  float v19; // [sp+64h] [-2Ch]

  ai = this->ai;
  presentable = (float *)ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    presentable = (float *)ai->presentable;
  }
  x = desiredDir->x;
  y = desiredDir->y;
  v19 = presentable[34];
  v18 = presentable[33];
  v8 = (float)((float)(desiredDir->z * presentable[35]) + (float)(desiredDir->x * v18));
  this->toSearchTurn = 0.0;
  v9 = "forward";
  v10 = (float)((float)((float)y * v19) + (float)v8);
  if ( v10 < 0.70710677 )
  {
    if ( v10 >= -0.70710677 )
    {
      if ( (float)((float)((float)y * v18) - (float)((float)x * v19)) <= 0.0 )
      {
        v9 = "right";
        v11 = 2.0;
      }
      else
      {
        v9 = "left";
        v11 = 1.0;
      }
    }
    else
    {
      v9 = "back";
      v11 = 3.0;
    }
    this->ai->aiVolatile.animation.animWebAnimator.ptr[0].toSearchTurn = v11;
  }
  if ( this->debug )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    v13 = gameLocal->GetRenderWorld(this: gameLocal);
    v14 = Physics;
    GetOrigin = Physics->GetOrigin;
    v15 = v13->__vftable;
    v17 = (int)GetOrigin(this: v14, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, const char *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, int, _DWORD, double))v15->DebugText)(
      a1: v13,
      a2: v9,
      a3: v17,
      a4: &off_82040000,
      a5: &idColor::colorYellow,
      a6: 1,
      a7: 1500,
      a8: 0,
      a9: 0.2);
  }
}


// ========================================================================
// ?SetAnimIndicesForRunType@idAnimWebAI@@QAAXW4runIndexType_t@@_N@Z
// EA  : 0x82A86ED0
// RVA : 0x00A86ED0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::SetAnimIndicesForRunType(idAnimWebAI *this, unsigned __int32 t, char blend)
{
  __int64 v6; // r11
  double v7; // fp31
  bool v8; // r5
  runIndexType_t v9; // r4
  double v10; // fp2

  LODWORD(v6) = idAI2::GetRunCycleIndexForType(this: this->ai, t);
  v7 = (float)v6;
  v10 = (float)__SPAIR64__(0x82000000, idAI2::GetIdleIndexForType(this: this->ai, t));
  if ( v7 >= 0.0 )
    idAnimWebAI::SetForwardRunIndex(
      this,
      newRunIndex: v7,
      newIdleIndex: v10,
      t: v9,
      blend: v8,
      a6: (runIndexType_t)t,
      a7: blend);
}


// ========================================================================
// ?GetLeafForMD6Internal@idAnimWebAI@@IAAPBVidMD6LeafPlay@@PBVidMD6Branch@@PBVidMD6Anim@@@Z
// EA  : 0x82A86F58
// RVA : 0x00A86F58
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

const idMD6LeafPlay *__fastcall idAnimWebAI::GetLeafForMD6Internal(
        idAnimWebAI *this,
        const idMD6Branch *node,
        const idMD6Anim *_anim)
{
  idMD6Node *right; // r4
  const idMD6LeafPlay *result; // r3
  idMD6Node *left; // r30
  int type; // r11
  char v9; // r11
  bool v10; // zf
  int v11; // r11
  char v12; // r11

  result = nullptr;
  left = node->left;
  right = node->right;
  if ( right == nullptr )
    goto LABEL_12;
  type = right->type;
  if ( type == 2 )
  {
    if ( *(const idMD6Anim **)&right[4].type == _anim )
      return (const idMD6LeafPlay *)right;
    goto LABEL_12;
  }
  if ( right->type == 0 || type == 3 || type == 4 || (v10 = type != 5, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 == 0
    || (result = idAnimWebAI::GetLeafForMD6Internal(this, node: (const idMD6Branch *)right, _anim)) == nullptr )
  {
LABEL_12:
    if ( left != nullptr )
    {
      v11 = left->type;
      if ( v11 == 2 )
      {
        if ( *(const idMD6Anim **)&left[4].type == _anim )
          return (const idMD6LeafPlay *)left;
      }
      else
      {
        if ( left->type == 0 || v11 == 3 || v11 == 4 || (v10 = v11 != 5, v12 = 0, !v10) )
          v12 = 1;
        if ( v12 != 0 )
          return idAnimWebAI::GetLeafForMD6Internal(this, node: (const idMD6Branch *)left, _anim);
      }
    }
  }
  return result;
}


// ========================================================================
// ?GetLeafForAnimPropsInternal@idAnimWebAI@@IAAPBVidMD6LeafPlay@@PBVidMD6Branch@@ABV?$idList@VidMD6AnimProps@@$04@@@Z
// EA  : 0x82A87068
// RVA : 0x00A87068
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

const idMD6LeafPlay *__fastcall idAnimWebAI::GetLeafForAnimPropsInternal(
        idAnimWebAI *this,
        const idMD6Branch *node,
        const idList<idMD6AnimProps,5> *props)
{
  idMD6Node *right; // r4
  const idMD6LeafPlay *result; // r3
  idMD6Node *left; // r29
  int type; // r11
  int num; // r7
  int v10; // r10
  int v11; // r11
  char v12; // r11
  bool v13; // zf
  int v14; // r11
  int v15; // r7
  int v16; // r10
  int i; // r11
  char v18; // r11

  result = nullptr;
  left = node->left;
  right = node->right;
  if ( right == nullptr )
    goto LABEL_16;
  type = right->type;
  if ( type != 2 )
  {
    if ( right->type == 0 || type == 3 || type == 4 || (v13 = type != 5, v12 = 0, !v13) )
      v12 = 1;
    if ( v12 != 0 )
    {
      result = idAnimWebAI::GetLeafForAnimPropsInternal(this, node: (const idMD6Branch *)right, props);
      if ( result != nullptr )
        return result;
    }
    goto LABEL_16;
  }
  num = props->num;
  v10 = 0;
  if ( num <= 0 )
  {
LABEL_16:
    if ( left != nullptr )
    {
      v14 = left->type;
      if ( v14 == 2 )
      {
        v15 = props->num;
        v16 = 0;
        if ( v15 > 0 )
        {
          for ( i = 0; *(const idMD6Anim **)&left[4].type != props->list[i].anim; ++i )
          {
            if ( ++v16 >= v15 )
              return result;
          }
          return (const idMD6LeafPlay *)left;
        }
      }
      else
      {
        if ( left->type == 0 || v14 == 3 || v14 == 4 || (v13 = v14 != 5, v18 = 0, !v13) )
          v18 = 1;
        if ( v18 != 0 )
          return idAnimWebAI::GetLeafForAnimPropsInternal(this, node: (const idMD6Branch *)left, props);
      }
    }
    return result;
  }
  v11 = 0;
  while ( *(const idMD6Anim **)&right[4].type != props->list[v11].anim )
  {
    ++v10;
    ++v11;
    if ( v10 >= num )
      goto LABEL_16;
  }
  return (const idMD6LeafPlay *)right;
}


// ========================================================================
// ?SerializeSnapshot@idAnimWebAI@@MAAXAAVidSerializer@@@Z
// EA  : 0x82A871E0
// RVA : 0x00A871E0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::SerializeSnapshot(idAnimWebAI *this, idSerializer *ser)
{
  if ( this->GetSerializeType(this) != STYPE_GENERIC )
  {
    idSerializer::Serialize(this: ser, value: &this->blendBack);
    idSerializer::Serialize(this: ser, value: &this->blendRight);
    idSerializer::Serialize(this: ser, value: &this->blendAngle);
    idSerializer::Serialize(this: ser, value: &this->forwardRunIndex);
    idSerializer::Serialize(this: ser, value: &this->forwardRunIndex);
    idSerializer::Serialize(this: ser, value: &this->leftRunIndex);
    idSerializer::Serialize(this: ser, value: &this->rightRunIndex);
    idSerializer::Serialize(this: ser, value: &this->backRunIndex);
    idSerializer::Serialize(this: ser, value: &this->injuredRunOffset);
    idSerializer::Serialize(this: ser, value: &this->previousRunIndex);
    idSerializer::Serialize(this: ser, value: &this->forwardRunBlend);
    idSerializer::Serialize(this: ser, value: &this->forwardRunBlendLinear);
    idSerializer::Serialize(this: ser, value: &this->idleIndex);
    idSerializer::Serialize(this: ser, value: &this->previousIdleIndex);
    idSerializer::Serialize(this: ser, value: &this->nextIdleIndex);
    idSerializer::Serialize(this: ser, value: &this->deathAnimIndex);
    idSerializer::Serialize(this: ser, value: &this->startTransitionIndex);
    idSerializer::Serialize(this: ser, value: &this->walkRate);
    idSerializer::Serialize(this: ser, value: &this->runRate);
    idSerializer::Serialize(this: ser, value: &this->deathScale);
    idSerializer::Serialize(this: ser, value: &this->desiredTurn);
    idSerializer::Serialize(this: ser, value: &this->sync8index1);
    idSerializer::Serialize(this: ser, value: &this->sync8index2);
    idSerializer::Serialize(this: ser, value: &this->sync8blendAngle);
    idSerializer::Serialize(this: ser, value: &this->select01);
    idSerializer::Serialize(this: ser, value: &this->traversalAttack);
    idSerializer::Serialize(this: ser, value: &this->diveIndex);
    idSerializer::Serialize(this: ser, value: &this->transitionSelect);
    idSerializer::Serialize(this: ser, value: &this->toCombatTurn);
    idSerializer::Serialize(this: ser, value: &this->toSearchTurn);
    idSerializer::Serialize(this: ser, value: &this->turnLeanDirection);
    idSerializer::Serialize(this: ser, value: &this->turnLeanAmount);
  }
}


// ========================================================================
// ?GetWebOriginBlendOp@idAnimWebAI@@QAA?AW4originBlend_t@idMD6Blend@@XZ
// EA  : 0x82A87398
// RVA : 0x00A87398
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

idMD6Blend::originBlend_t __fastcall idAnimWebAI::GetWebOriginBlendOp(idAnimWebAI *this)
{
  return this->modelAnimStates.list->tree[22].type;
}


// ========================================================================
// ?ForceWebOriginBlendOp@idAnimWebAI@@QAAXW4originBlend_t@idMD6Blend@@@Z
// EA  : 0x82A873A8
// RVA : 0x00A873A8
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::ForceWebOriginBlendOp(idAnimWebAI *this, idMD6Blend::originBlend_t newOp)
{
  this->modelAnimStates.list->tree[22].type = newOp;
}


// ========================================================================
// ?DebugDrawNode@idAnimWebAI@@IAAHPAVidRenderModelGui@@PAVidMD6Node@@MM@Z
// EA  : 0x82A873B8
// RVA : 0x00A873B8
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

int __fastcall idAnimWebAI::DebugDrawNode(
        idAnimWebAI *this,
        idRenderModelGui *gui,
        idMD6LeafPlay *node,
        double nodeAlpha,
        double offset)
{
  int type; // r11
  double v11; // fp3
  double v12; // fp2
  idColor *v13; // r4
  int numFrames; // r29
  idMD6AnimData *animData; // r11
  unsigned int v16; // r28
  int v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  int v20; // r6
  long double v21; // fp4
  double v22; // fp2
  double v23; // fp1
  double FloatFrame; // fp1
  __int64 v25; // r5
  char v27; // r11
  bool v28; // zf
  double v29; // fp31
  double v30; // fp1
  __int64 v31; // r10

  if ( node != nullptr )
  {
    type = node->type;
    if ( type == 2 )
    {
      idRenderModelGui::DrawString(
        this: gui,
        x: 0.0,
        y: (float)((float)offset + (float)5.0),
        string: (const char *)gui,
        defaultColor: (const idVec4 *)&aAvSsobjectVCom[20],
        forceColor: (unsigned __int8 *)node->anim->name.str,
        scale: 1.0,
        a8: (const idVec4 *)&idColor::colorOrange,
        a9: 0);
      v11 = (float)((float)nodeAlpha * (float)200.0);
      v12 = (float)((float)offset + (float)25.0);
      if ( (node->anim->animData->flags & 1) != 0 )
      {
        idRenderModelGui::DrawFilled(
          this: gui,
          color: (const idVec4 *)&idColor::colorBrown,
          x: 0.0,
          y: v12,
          w: v11,
          h: 20.0);
        v13 = &idColor::colorBlue;
      }
      else
      {
        idRenderModelGui::DrawFilled(
          this: gui,
          color: (const idVec4 *)&idColor::colorRed,
          x: 0.0,
          y: v12,
          w: v11,
          h: 20.0);
        v13 = &idColor::colorWhite;
      }
      idRenderModelGui::DrawFilled(
        this: gui,
        color: (const idVec4 *)v13,
        x: 200.0,
        y: (float)((float)offset + (float)25.0),
        w: 5.0,
        h: 20.0);
      numFrames = 0;
      animData = node->anim->animData;
      if ( animData != nullptr )
        numFrames = animData->numFrames;
      v16 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
      v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      FloatFrame = idMD6LeafPlay::GetFloatFrame(
                     this: node,
                     gameTime: v17,
                     ticksPerSec: v16,
                     a4: v23,
                     a5: v22,
                     a6: v21,
                     a7: v20,
                     a8: v19,
                     a9: v18);
      LODWORD(v25) = numFrames - 1;
      idRenderModelGui::DrawFilled(
        this: gui,
        color: (const idVec4 *)&idColor::colorGreen,
        x: (float)((float)((float)FloatFrame / (float)v25) * (float)200.0),
        y: (float)((float)offset + (float)27.0),
        w: 3.0,
        h: 10.0);
      return 1;
    }
    if ( node->type == 0 || type == 3 || type == 4 || (v28 = type != 5, v27 = 0, !v28) )
      v27 = 1;
    if ( v27 != 0 )
    {
      v29 = 0.0;
      v30 = 0.0;
      if ( (unsigned int)node->syncEnabled - 1 <= 7 )
      {
        if ( node->syncEnabled == 2 )
        {
          v29 = nodeAlpha;
          v30 = nodeAlpha;
        }
        else if ( node->syncEnabled != 3 && node->syncEnabled != 4 && node->syncEnabled != 5 && node->syncEnabled != 6 )
        {
          v29 = (float)(*(float *)&node[1].type * (float)nodeAlpha);
          v30 = (float)((float)((float)1.0 - *(float *)&node[1].type) * (float)nodeAlpha);
        }
      }
      LODWORD(v31) = idAnimWebAI::DebugDrawNode(this, gui, node: (idMD6Node *)node->anim, nodeAlpha: v30, offset);
      return idAnimWebAI::DebugDrawNode(
               this,
               gui,
               node: *(idMD6Node **)&node->weightGroup,
               nodeAlpha: v29,
               offset: (float)((float)((float)v31 * (float)50.0) + (float)offset))
           + v31;
    }
  }
  return 0;
}


// ========================================================================
// ?InternalUpdateScalars@idAnimWebAI@@MAAXH@Z
// EA  : 0x82A87690
// RVA : 0x00A87690
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAnimWebAI::InternalUpdateScalars(idAnimWebAI *this, const int curTime)
{
  idAI2 *ai; // r3
  float *decl; // r26
  idPhysics *Physics; // r3
  _exception *v6; // r3
  const idMat3 *p_retval; // r30
  float *v8; // r5
  double turnLeanAmount; // fp31
  idAIOrientation *BodyOrientation; // r3
  __int64 v11; // r11
  double v12; // fp1
  double v13; // fp28
  idAI2 *v14; // r11
  double gangstaPoseFraction; // fp2
  bool v16; // r11
  idAI2 *v17; // r3
  double valueFloat; // fp0
  double v19; // fp0
  double v20; // fp0
  double v21; // fp31
  double v22; // fp30
  aiSenseState_t *EnemySenseState; // r29
  idPhysics *v24; // r3
  float *v25; // r25
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v27; // fp10
  double v28; // fp8
  bool v29; // r5
  runIndexType_t v30; // r4
  char v31; // r11
  idAI2 *v32; // r10
  char v33; // r9
  runIndexType_t runIndexType; // r11
  idAnimWebAI *ptr; // r3
  int GameMs; // r3
  idAI2 *v37; // r11
  unsigned __int32 v38; // r4
  idPhysics *v39; // r3
  float *v40; // r30
  const aiPhysicalState_t *v41; // r3
  double v42; // fp0
  double v43; // fp13
  double v44; // fp12
  double v45; // fp30
  idRenderModel *RenderModelFromPresentable; // r3
  float *p_deferredAxis; // r11
  idAI2 *v48; // r3
  int entityNumber; // r8
  __int64 v50; // r8
  double v51; // fp31
  bool v52; // cr58
  double nextRunIndex; // fp1
  idAI2 *v56; // r3
  idPhysics *v57; // r29
  idRenderWorld *v58; // r3
  __int64 v59; // r8
  __int64 v60; // r6
  __int64 v61; // r10
  idRenderWorld *v62; // r27
  va *v63; // r26
  idRenderWorld_vtbl *v64; // r30
  int v65; // r3
  idPhysics *v66; // r29
  idRenderWorld *v67; // r3
  __int64 v68; // r10
  idRenderWorld *v69; // r27
  __int64 v70; // r8
  __int64 v71; // r6
  va *v72; // r26
  idRenderWorld_vtbl *v73; // r30
  int v74; // r3
  idPhysics *v75; // r29
  idRenderWorld *v76; // r3
  __int64 v77; // r10
  int v78; // r8 OVERLAPPED
  idRenderWorld *v79; // r27
  __int128 v80; // r7 OVERLAPPED
  va *v81; // r26
  idRenderWorld_vtbl *v82; // r30
  int v83; // r3
  char HasFocus; // r3
  double aimAlpha; // fp0
  double v86; // fp0
  double v87; // fp13
  int v88; // [sp+8h] [-10D8h]
  int v89; // [sp+Ch] [-10D4h]
  int v90; // [sp+10h] [-10D0h]
  int v91; // [sp+14h] [-10CCh]
  int v92; // [sp+18h] [-10C8h]
  int v93; // [sp+1Ch] [-10C4h]
  int v94; // [sp+20h] [-10C0h]
  double forwardRunIndex; // [sp+20h] [-10C0h]
  double previousRunIndex; // [sp+20h] [-10C0h]
  double v97; // [sp+20h] [-10C0h]
  int v98; // [sp+24h] [-10BCh]
  int v99; // [sp+28h] [-10B8h]
  double v100; // [sp+28h] [-10B8h]
  double v101; // [sp+28h] [-10B8h]
  int v102; // [sp+2Ch] [-10B4h]
  int v103; // [sp+30h] [-10B0h]
  double forwardRunBlend; // [sp+30h] [-10B0h]
  int v105; // [sp+34h] [-10ACh]
  int v106; // [sp+38h] [-10A8h]
  double forwardRunBlendLinear; // [sp+38h] [-10A8h]
  double v108; // [sp+38h] [-10A8h]
  int v109; // [sp+3Ch] [-10A4h]
  int v110; // [sp+40h] [-10A0h]
  double v111; // [sp+40h] [-10A0h]
  int v112; // [sp+44h] [-109Ch]
  int v113; // [sp+48h] [-1098h]
  int v114; // [sp+4Ch] [-1094h]
  int v115; // [sp+50h] [-1090h]
  idVec3 v116; // [sp+60h] [-1080h] BYREF
  idVec3 v117; // [sp+70h] [-1070h] BYREF
  va v118; // [sp+80h] [-1060h] BYREF

  ai = this->ai;
  decl = (float *)ai->aiEditable.behaviors.decl;
  Physics = idEntity::GetPhysics(this: ai);
  Physics->GetLinearVelocity(this: (idPhysics *)&v117, result: (idVec3 *)Physics, a3: 0);
  v6 = (_exception *)this->ai;
  p_retval = (const idMat3 *)&v6[116].retval;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: v6) != 0 )
    UpdateWalkBlendFromAngle(
      angle: this->ai->aiVolatile.animation.animFSM.animBlendVars.bodyMoveAngle.value,
      lerpScale: 1.0,
      blendBack: (float *)0x96C0,
      blendRight: (float *)this->ai,
      blendAngle: &this->blendBack,
      sync8index1: &this->blendRight,
      sync8index2: &this->blendAngle,
      sync8blendAngle: &this->sync8index1,
      a9: &this->sync8index2,
      a10: &this->sync8blendAngle);
  else
    UpdateWalkBlend(
      velocity: &v117,
      axis: p_retval,
      lerpScale: ai_walkLerpScale.valueFloat,
      blendBack: v8,
      blendRight: &this->blendBack,
      blendAngle: &this->blendRight,
      sync8index1: &this->blendAngle,
      sync8index2: &this->sync8index1,
      sync8blendAngle: &this->sync8index2,
      a10: v88,
      a11: v89,
      a12: v90,
      a13: v91,
      a14: v92,
      a15: v93,
      a16: v94,
      a17: v98,
      a18: v99,
      a19: v102,
      a20: v103,
      a21: v105,
      a22: v106,
      a23: v109,
      a24: v110,
      a25: v112,
      a26: v113,
      a27: v114,
      a28: v115,
      a29: &this->sync8blendAngle);
  if ( idAI2::GetBodyOrientation(this: this->ai)->currentTurnDir != 0 )
  {
    if ( this->turnLeanDirection >= 0.5 )
      turnLeanAmount = this->turnLeanAmount;
    else
      turnLeanAmount = -this->turnLeanAmount;
    BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
    LODWORD(v11) = -1;
    if ( BodyOrientation->currentTurnDir != 1 )
      LODWORD(v11) = 1;
    HIDWORD(v11) = &ai_useTurnTransitions.valueString.baseBuffer[12];
    *(_QWORD *)&v116.x = v11;
    v12 = LerpToWithScale(cur: turnLeanAmount, dest: (float)v11, scale: ai_turnLeanLerpScaleUp.valueFloat);
    v13 = 0.0;
    if ( v12 < 0.0 )
    {
      this->turnLeanAmount = -v12;
      this->turnLeanDirection = 0.0;
      goto LABEL_15;
    }
    this->turnLeanDirection = 1.0;
  }
  else
  {
    v13 = 0.0;
    v12 = LerpToWithScale(cur: this->turnLeanAmount, dest: 0.0, scale: ai_turnLeanLerpScaleDown.valueFloat);
  }
  this->turnLeanAmount = v12;
LABEL_15:
  v14 = this->ai;
  if ( v14->aiVolatile.memory.enableGangstaPose )
    gangstaPoseFraction = v14->aiEditable.actionSettings.fire.gangstaPoseFraction;
  else
    gangstaPoseFraction = v13;
  this->gangstaAlpha = LerpToWithScale(
                         cur: this->gangstaAlpha,
                         dest: gangstaPoseFraction,
                         scale: ai_gangstaLerpScale.valueFloat);
  if ( ai_animWebDebug.valueInteger != 0 && ai_debugLevel.valueInteger > 0
    || (v16 = false, ai_debugWeb.valueInteger == this->ai->entityNumber) )
  {
    v16 = true;
  }
  this->debug = v16;
  v17 = this->ai;
  this->deathScale = ai_deathAnimScale.valueFloat;
  if ( v17->actorVolatile.onStairs )
    valueFloat = ai_stairWalkRate.valueFloat;
  else
    valueFloat = 1.0;
  this->walkRate = valueFloat;
  if ( v17->actorVolatile.onStairs )
    v19 = ai_stairRunRate.valueFloat;
  else
    v19 = 1.0;
  this->runRate = v19;
  if ( v17->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE )
    v20 = 192.0;
  else
    v20 = 256.0;
  v21 = (float)((float)v20 * (float)v20);
  v22 = v21;
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: v17, senseType: AISENSE_MAX);
  if ( EnemySenseState != nullptr )
  {
    v24 = idEntity::GetPhysics(this: this->ai);
    v25 = (float *)v24->GetOrigin(this: v24, a2: 0);
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
    v27 = (float)(v25[2] - ConfirmedPhysicalSafe->origin.z);
    v28 = (float)(v25[1] - ConfirmedPhysicalSafe->origin.y);
    v22 = (float)((float)((float)(*v25 - ConfirmedPhysicalSafe->origin.x)
                        * (float)(*v25 - ConfirmedPhysicalSafe->origin.x))
                + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)));
  }
  if ( !idAI2::ShouldScramble(this: this->ai) || (v31 = 1, v22 < v21) )
    v31 = 0;
  v32 = this->ai;
  v33 = v31;
  runIndexType = v32->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType;
  if ( runIndexType == ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE )
  {
    if ( v33 != 0 )
      goto LABEL_64;
    ptr = v32->aiVolatile.animation.animWebAnimator.ptr;
    goto LABEL_62;
  }
  if ( runIndexType != ANIMWEBAI_RUNINDEXTYPE_INJURED )
  {
    if ( v33 != 0 )
    {
      v38 = 2;
      ptr = this;
LABEL_63:
      idAnimWebAI::SetAnimIndicesForRunType(this: ptr, t: v38, blend: 1);
      goto LABEL_64;
    }
    if ( idAIMemory::GetEnemy(this: &v32->aiVolatile.memory) == nullptr
      || EnemySenseState == nullptr
      || gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - EnemySenseState->lastConfirmedStimTime >= 5000 )
    {
      goto LABEL_64;
    }
    v39 = idEntity::GetPhysics(this: this->ai);
    v40 = (float *)v39->GetOrigin(this: v39, a2: 0);
    v41 = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
    v42 = (float)(v41->origin.y - v40[1]);
    v43 = (float)(v41->origin.z - v40[2]);
    v44 = (float)(v41->origin.x - *v40);
    v116.y = v41->origin.y - v40[1];
    v116.z = v43;
    v116.x = v44;
    v45 = (float)((float)((float)v44 * (float)v44)
                + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42)));
    idVec3::NormalizeFast(this: &v116);
    RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: this->ai);
    p_deferredAxis = (float *)&RenderModelFromPresentable->deferredAxis;
    if ( !RenderModelFromPresentable->useDeferredPosition )
      p_deferredAxis = (float *)&RenderModelFromPresentable->g.axis;
    if ( (float)((float)(*p_deferredAxis * v116.x)
               + (float)((float)(p_deferredAxis[2] * v116.z) + (float)(p_deferredAxis[1] * v116.y))) < 0.89999998
      && idAI2::GetRunCycleIndexForType(this: this->ai, t: 4u) != -1 )
    {
      if ( this->runIndexType == ANIMWEBAI_RUNINDEXTYPE_GUNDOWN )
        goto LABEL_64;
      v38 = 4;
      ptr = this;
      goto LABEL_63;
    }
    v48 = this->ai;
    entityNumber = v48->entityNumber;
    HIDWORD(v50) = 8 * entityNumber;
    LODWORD(v50) = 7 * entityNumber % 10;
    v51 = (float)((float)((float)((float)(decl[119] - decl[118]) * (float)v50) * (float)0.1) + decl[118]);
    *(_QWORD *)&v116.x = v50;
    if ( idAI2::GetRunCycleIndexForType(this: v48, t: 3u) == -1 )
    {
      v52 = this->runIndexType == ANIMWEBAI_RUNINDEXTYPE_GUNDOWN;
    }
    else
    {
      if ( v45 > (float)((float)v51 * (float)v51) )
      {
        v38 = 3;
        ptr = this;
        goto LABEL_63;
      }
      v52 = this->runIndexType == ANIMWEBAI_RUNINDEXTYPE_FAR;
    }
    if ( !v52 )
      goto LABEL_64;
    ptr = this;
    goto LABEL_62;
  }
  if ( v32->aiEditable.behaviors.decl->damageBehaviors.injuredRunMode == AIINJUREDRUNMODE_RECENTLYDAMAGED
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - this->ai->aiVolatile.memory.lastFiredAtTime >= 2500 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v37 = this->ai;
    if ( GameMs - v37->aiVolatile.memory.lastDamageTime > 2500 )
    {
      ptr = v37->aiVolatile.animation.animWebAnimator.ptr;
LABEL_62:
      v38 = 0;
      goto LABEL_63;
    }
  }
LABEL_64:
  if ( this->forwardRunBlendLinear != 1.0 )
  {
    _FP11 = (float)((float)1.0 - (float)(decl[120] + this->forwardRunBlendLinear));
    __asm { fsel      f6, f11, f12, f29 }
    this->forwardRunBlendLinear = _FP6;
    if ( ai_runCycleBlendMode.valueInteger != 0 )
    {
      switch ( ai_runCycleBlendMode.valueInteger )
      {
        case 1:
          this->forwardRunBlend = (float)_FP6 * (float)_FP6;
          break;
        case 2:
          this->forwardRunBlend = -(float)((float)((float)((float)1.0 - (float)_FP6) * (float)((float)1.0 - (float)_FP6))
                                         - (float)1.0);
          break;
        case 3:
          this->forwardRunBlend = EaseInEaseOut(linearInput: _FP6);
          break;
        default:
          break;
      }
    }
    else
    {
      this->forwardRunBlend = _FP6;
    }
    if ( _FP6 == 1.0 )
    {
      nextRunIndex = this->nextRunIndex;
      if ( this->forwardRunIndex != nextRunIndex )
        idAnimWebAI::SetForwardRunIndex(
          this,
          newRunIndex: nextRunIndex,
          newIdleIndex: this->nextIdleIndex,
          t: v30,
          blend: v29,
          a6: this->nextRunIndexType,
          a7: 1);
    }
  }
  if ( ai_debugLevel.valueInteger != 0 && ai_debugForwardRunIndex.valueInteger != 0 )
  {
    v56 = this->ai;
    if ( this->forwardRunBlendLinear == 1.0 )
    {
      v57 = idEntity::GetPhysics(this: v56);
      v58 = common->RW(this: common);
      LODWORD(v59) = this->runIndexType;
      forwardRunIndex = this->forwardRunIndex;
      HIDWORD(v60) = LODWORD(forwardRunIndex);
      HIDWORD(v59) = &joystick.joyAxis[0][2];
      LODWORD(v61) = "1 - formation cover, such as behind regime shield units";
      v62 = v58;
      LODWORD(v60) = runIndexTypeNames[(_DWORD)v59];
      v63 = va::va(
              this: &v118,
              fmt: "run: %.0f %s",
              a3: v60,
              a4: v59,
              a5: v61,
              a6: v88,
              a7: v89,
              a8: v90,
              a9: v91,
              a10: v92,
              a11: v93);
      v64 = v62->__vftable;
      v65 = (int)v57->GetOrigin(this: v57, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, va *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, _DWORD, _DWORD, double))v64->DebugText)(
        a1: v62,
        a2: v63,
        a3: v65,
        a4: &off_82040000,
        a5: &idColor::colorYellow,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.2);
    }
    else if ( this->nextRunIndex == this->forwardRunIndex )
    {
      v66 = idEntity::GetPhysics(this: v56);
      v67 = common->RW(this: common);
      LODWORD(v68) = "1 - formation cover, such as behind regime shield units";
      v69 = v67;
      forwardRunBlendLinear = this->forwardRunBlendLinear;
      LODWORD(v70) = LODWORD(forwardRunBlendLinear);
      forwardRunBlend = this->forwardRunBlend;
      HIDWORD(v70) = LODWORD(forwardRunBlend);
      v100 = this->forwardRunIndex;
      LODWORD(v71) = LODWORD(v100);
      previousRunIndex = this->previousRunIndex;
      HIDWORD(v71) = LODWORD(previousRunIndex);
      HIDWORD(v68) = *(const char **)((char *)runIndexTypeNames + HIDWORD(previousRunIndex));
      v72 = va::va(
              this: &v118,
              fmt: "run: %.0f->%.0f (%.2f,%.2f) %s",
              a3: v71,
              a4: v70,
              a5: v68,
              a6: v88,
              a7: v89,
              a8: v90,
              a9: v91,
              a10: v92,
              a11: v93);
      v73 = v69->__vftable;
      v74 = (int)v66->GetOrigin(this: v66, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, va *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, _DWORD, _DWORD, double))v73->DebugText)(
        a1: v69,
        a2: v72,
        a3: v74,
        a4: &off_82040000,
        a5: &idColor::colorOrange,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.2);
    }
    else
    {
      v75 = idEntity::GetPhysics(this: v56);
      v76 = common->RW(this: common);
      v111 = this->forwardRunBlendLinear;
      HIDWORD(v77) = LODWORD(v111);
      v108 = this->forwardRunBlend;
      v78 = LODWORD(v108);
      v97 = this->previousRunIndex;
      v101 = this->forwardRunIndex;
      v79 = v76;
      LODWORD(v77) = *(_DWORD *)(HIDWORD(v97) + HIDWORD(v108) + 26480);
      DWORD1(v80) = HIDWORD(v101);
      *((double *)&v80 + 1) = this->nextRunIndex;
      v81 = va::va(
              this: &v118,
              fmt: "run: %.0f->%.0f->%.0f (%.2f,%.2f) %s",
              a3: *(__int64 *)((char *)&v80 + 4),
              a4: *(__int64 *)&v78,
              a5: v77,
              a6: v88,
              a7: v89,
              a8: v90,
              a9: v91,
              a10: v92,
              a11: v93);
      v82 = v79->__vftable;
      v83 = (int)v75->GetOrigin(this: v75, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, va *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v82->DebugText)(
        a1: v79,
        a2: v81,
        a3: v83,
        a4: v82->DebugText,
        a5: &idColor::colorRed,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.2);
    }
  }
  HasFocus = idFocusInfo::HasFocus(this: this->ai->aiVolatile.focus.foci.ptr);
  aimAlpha = this->aimAlpha;
  if ( HasFocus != 0 )
  {
    if ( aimAlpha > v13 )
    {
      if ( aimAlpha < 1.0 )
      {
        v86 = (float)(this->aimAlpha * (float)1.1);
        this->aimAlpha = this->aimAlpha * (float)1.1;
        if ( v86 >= 1.0 )
          this->aimAlpha = 1.0;
      }
    }
    else
    {
      this->aimAlpha = 0.050000001;
    }
  }
  else if ( aimAlpha > v13 )
  {
    v87 = (float)(this->aimAlpha * (float)0.99000001);
    this->aimAlpha = this->aimAlpha * (float)0.99000001;
    if ( v87 < 0.0099999998 )
      this->aimAlpha = v13;
  }
}


// ========================================================================
// ?GetLeafForMD6@idAnimWebAI@@QAAPBVidMD6LeafPlay@@PBVidMD6Anim@@@Z
// EA  : 0x82A880B0
// RVA : 0x00A880B0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

const idMD6LeafPlay *__fastcall idAnimWebAI::GetLeafForMD6(idAnimWebAI *this, const idMD6Anim *_anim)
{
  const idMD6Branch *v4; // r3

  v4 = this->InternalGetMergeBranch_2(this);
  return idAnimWebAI::GetLeafForMD6Internal(this, node: v4, _anim);
}


// ========================================================================
// ?GetLeafForAnimProps@idAnimWebAI@@QAAPBVidMD6LeafPlay@@ABV?$idList@VidMD6AnimProps@@$04@@@Z
// EA  : 0x82A88108
// RVA : 0x00A88108
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

const idMD6LeafPlay *__fastcall idAnimWebAI::GetLeafForAnimProps(
        idAnimWebAI *this,
        const idList<idMD6AnimProps,5> *props)
{
  const idMD6Branch *v4; // r3

  v4 = this->InternalGetMergeBranch_2(this);
  return idAnimWebAI::GetLeafForAnimPropsInternal(this, node: v4, props);
}


// ========================================================================
// ?DebugDrawNodes@idAnimWebAI@@QAAXPAVidRenderModelGui@@@Z
// EA  : 0x82A88160
// RVA : 0x00A88160
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::DebugDrawNodes(idAnimWebAI *this, idRenderModelGui *gui)
{
  idMD6LeafPlay *v4; // r3

  v4 = (idMD6LeafPlay *)this->InternalGetMergeBranch_2(this);
  idAnimWebAI::DebugDrawNode(this, gui, node: v4, nodeAlpha: 1.0, offset: 0.0);
}


// ========================================================================
// ?InternalStartBlend@idAnimWebAI@@MAAXPBVidDeclAnimWebNode@@0H@Z
// EA  : 0x82A881D0
// RVA : 0x00A881D0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::InternalStartBlend(
        idAnimWebAI *this,
        const idDeclAnimWebNode *curNode,
        const idDeclAnimWebNode *nextNode,
        int curTime)
{
  idAIMoveState *MoveInterface; // r3
  idDeclAnimWebNode::idModelInfo *list; // r30
  double v9; // fp0
  int v10; // r11
  idMD6AnimProps *v11; // r30
  char v12; // r29
  const idMD6Alias *Alias; // r3
  const idMD6Anim *v14; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idMD6AnimData *animData; // r11
  idDeclMD6 *decl; // r3
  int numFrames; // r6
  idMD6AnimData *v19; // r11
  idAngles *endDelta; // r28
  int v21; // r29
  signed int frameRate; // r30
  int v23; // r3
  _BYTE v24[20]; // [sp+70h] [-1A0h] BYREF
  _BYTE v25[20]; // [sp+90h] [-180h] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v26; // [sp+B0h] [-160h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> v27; // [sp+B2h] [-15Eh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v28; // [sp+B4h] [-15Ch] BYREF
  idTypesafeNumber<int,enum gameTimeUnique_t> v29[4]; // [sp+B8h] [-158h] BYREF
  float v30[22]; // [sp+C8h] [-148h] BYREF
  _DWORD v31[5]; // [sp+120h] [-F0h] BYREF
  int v32; // [sp+140h] [-D0h]
  const idMD6Anim *v33; // [sp+144h] [-CCh]
  const idEventArg *v34; // [sp+148h] [-C8h]
  const idEventArg *v35; // [sp+14Ch] [-C4h]
  int v36; // [sp+150h] [-C0h]
  blendParms_t v37; // [sp+160h] [-B0h] BYREF
  idList<idVehicleState *,5> v38; // [sp+180h] [-90h] BYREF
  int v39; // [sp+190h] [-80h] BYREF

  idAnimator_AnimWeb::InternalStartBlend(this, curNode, nextNode, curTime);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)this->ai) != 0 )
    this->ai->aiVolatile.animation.animFSM.AnimStartBlend(
      this: &this->ai->aiVolatile.animation.animFSM,
      a2: curNode,
      a3: nextNode);
  if ( nextNode != nullptr
    && *(int *)((char *)g_moveModePriorities + __ROL4__(nextNode->animDelta, 2)) > g_moveModePriorities[this->ai->aiVolatile.physics.moveState.movementMode] )
  {
    this->InternalSetAnimDelta(this, a2: nullptr, a3: nextNode);
  }
  idAnimWebAI::UpdateDesiredTurnIndex(this);
  MoveInterface = idAI2::GetMoveInterface(this: this->ai);
  v30[0] = 1.0;
  v30[1] = 1.0;
  v30[2] = 1.0;
  MoveInterface->SetTranslationDeltaScale(this: MoveInterface, a2: (const idVec3 *)v30);
  blendParms_t::blendParms_t(this: &v37);
  v28.value = -1;
  v27.value = -1;
  if ( (unsigned __int8)idAnimator_AnimWeb::GetCurEdgeInfo(this, swi: &v28, ni: &v27, bp: &v37) != 0
    && v37.parms.originBlend == 2 )
  {
    idAIMoveState::EndTurn(this: &this->ai->aiVolatile.physics.moveState);
  }
  if ( nextNode != nullptr && nextNode->animDelta == 4 && nextNode->modelInfo.num > 0 )
  {
    list = nextNode->modelInfo.list;
    if ( list != nullptr )
    {
      v9 = (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)this->ai) != 0
         ? this->ai->aiVolatile.animation.animFSM.animBlendVars.animDepartureSelect.value
         : this->startTransitionIndex;
      v29[3].value = (int)v9;
      v10 = (int)v9;
      if ( (int)v9 >= 0 && v10 < list->animProps.num )
      {
        v11 = &list->animProps.list[v10];
        if ( v11 != nullptr )
        {
          v12 = 1;
          v26.value = v11->aliasHandle.value;
          if ( v26.value != 0xFFFF )
          {
            Alias = idDeclMD6::FindAlias(this: *this->modelDecls.list, aliasHandle: &v26, includeInherited: true);
            if ( Alias != nullptr && Alias->animRefs.num > 1 )
            {
              idLib::Warning(fmt: "Nodes set as ANIMDELTA_TURN cannot use aliases with multiple animations.");
              v12 = 0;
            }
          }
          if ( v12 != 0 )
          {
            v14 = idMD6AnimProps::SelectAnim(this: v11, declMD6: *this->modelDecls.list, index: 0);
            if ( v14 != nullptr )
            {
              if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)this->ai) != 0 )
              {
                v38.num = 0;
                v38.granularity = 1;
                v38.size = 16;
                v38.list = (idVehicleState **)&v39;
                v38.memTag = 5;
                v38.listStatic = 1;
                TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
                animData = v14->animData;
                decl = TreeAnimatorFromPresentable->decl;
                numFrames = 0;
                if ( animData != nullptr )
                  numFrames = animData->numFrames;
                idDeclMD6::FindAnimEvents(
                  this: decl,
                  anim: v14,
                  startFrame: 0,
                  endFrame: numFrames,
                  eventNum: AE_AnimDeltaCorrection.eventnum,
                  events: &v38);
                if ( v38.num == 0 )
                {
                  idLib::Warning(
                    fmt: "Node with anim %s set as ANIMDELTA_TURN without delta correction events, this should be fixed",
                    v14->name.str);
                  v31[1] = 0;
                  HIBYTE(v31[0]) = 105;
                  v33 = v14;
                  LODWORD(v30[7]) = 1;
                  v30[15] = 0.0;
                  HIBYTE(v30[6]) = 105;
                  HIBYTE(v30[14]) = 105;
                  HIBYTE(v32) = 52;
                  memcpy(Dst: v25, Src: v31, Size: sizeof(v25));
                  memcpy(Dst: v24, Src: &v30[6], Size: sizeof(v24));
                  idEventReceiver::PostEventMS(
                    this: this->ai,
                    ev: &AE_AnimDeltaCorrection,
                    time: v32,
                    arg1: v34,
                    arg2: v35,
                    arg3: (const idEventArg *)__ROL4__(v36, 32),
                    arg4: (const idEventArg *)LODWORD(v30[16]));
                }
                idList<idThread *,58>::Clear(this: &v38);
              }
              else
              {
                v19 = v14->animData;
                endDelta = nullptr;
                if ( v19 != nullptr )
                {
                  endDelta = (idAngles *)v19->endDelta;
                  v21 = v19->numFrames;
                }
                else
                {
                  v21 = 0;
                }
                frameRate = 30;
                if ( v19 != nullptr )
                  frameRate = v19->frameRate;
                v23 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
                v29[0].value = v23 * v21 / frameRate;
                __twllei(frameRate, 0);
                __twlgei(frameRate & ~(__ROL4__(v23 * v21, 1) - 1), 0xFFFFFFFF);
                if ( idQuat::operator!=(this: (idColor *)endDelta, rhs: (const idColor *)&quat_identity) )
                  idAIMoveState::BeginTurn(
                    this: &this->ai->aiVolatile.physics.moveState,
                    rotDelta: endDelta,
                    totalTurnTime: v29);
              }
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// __unwind$490964
// EA  : 0x82A885E0
// RVA : 0x00A885E0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void _unwind_490964()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 384));
}


// ========================================================================
// ?InternalSetAnimDelta@idAnimWebAI@@MAAXV?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@PBVidDeclAnimWebNode@@@Z
// EA  : 0x82A88608
// RVA : 0x00A88608
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __fastcall idAnimWebAI::InternalSetAnimDelta(
        idAnimWebAI *this,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        const idDeclAnimWebNode *node)
{
  idAI2 *ai; // r3
  idAIMoveState *p_moveState; // r30
  unsigned int animDelta; // r11
  aiMovementMode_t DefaultMovementMode; // r3
  idAnimBaseFSM::deltaMode_t v9; // r10
  aiMovementMode_t v10; // r4
  int v11; // r11

  ai = this->ai;
  p_moveState = &ai->aiVolatile.physics.moveState;
  if ( (_WORD)modelIndex == 0 )
  {
    animDelta = node->animDelta;
    if ( animDelta > 6 )
      goto LABEL_19;
    if ( animDelta == 1 || animDelta == 2 )
    {
      idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: AIMOVEMODE_ANIM);
      v9 = ANIMDELTAMODE_DRIVEN;
    }
    else
    {
      if ( animDelta == 3 && node->animDelta != 0 )
      {
        v10 = AIMOVEMODE_ANIM_GRAVITY;
      }
      else
      {
        if ( animDelta != 4 || node->animDelta == 0 )
        {
          if ( animDelta == 5 && node->animDelta != 0 )
            goto LABEL_19;
          if ( node->animDelta != 0 )
          {
            idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: AIMOVEMODE_ANIM_DRIVEN);
            v9 = ANIMDELTAMODE_FULL_DRIVE_AI;
          }
          else
          {
            DefaultMovementMode = idAI2::GetDefaultMovementMode(this: ai);
            idAIMoveState::SetMovementModeForReal(this: p_moveState, mode: DefaultMovementMode);
            v9 = ANIMDELTAMODE_DEFAULT;
          }
          goto LABEL_18;
        }
        v10 = AIMOVEMODE_ANIM_TURN;
      }
      idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: v10);
      v9 = ANIMDELTAMODE_DRIVEN_GRAVITY;
    }
LABEL_18:
    this->ai->aiVolatile.animation.animFSM.animDeltaMode = v9;
LABEL_19:
    idAnimBaseFSM::SetPuppetMode(
      this: &this->ai->aiVolatile.animation.animFSM,
      enable: (node->customFlags & 8) != 0,
      reason: PUPPET_ANIMATION);
    v11 = node->animDelta;
    if ( v11 != 7 )
      idAI2::SetWorldCollision(this: this->ai, collideWithWorld: v11 != 2);
  }
}


// ========================================================================
// `dynamic initializer for 'ai_walkLerpScale''
// EA  : 0x83368A70
// RVA : 0x01368A70
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_walkLerpScale__()
{
  idCVar::idCVar(
    this: &ai_walkLerpScale,
    name: "ai_walkLerpScale",
    value: "0.1",
    flags: 4,
    description: "sets the rate at which the AI's blends between directional walk animations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_walkLerpScale__);
}


// ========================================================================
// `dynamic initializer for 'ai_gangstaLerpScale''
// EA  : 0x83368AC8
// RVA : 0x01368AC8
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_gangstaLerpScale__()
{
  idCVar::idCVar(
    this: &ai_gangstaLerpScale,
    name: "ai_gangstaLerpScale",
    value: "0.1",
    flags: 4,
    description: "sets the rate at which the AI's blends in the additive \"gangsta\" pose",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_gangstaLerpScale__);
}


// ========================================================================
// `dynamic initializer for 'ai_animWebDebug''
// EA  : 0x83368B20
// RVA : 0x01368B20
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_animWebDebug__()
{
  idCVar::idCVar(
    this: &ai_animWebDebug,
    name: "ai_animWebDebug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_animWebDebug__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugWeb''
// EA  : 0x83368B78
// RVA : 0x01368B78
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugWeb__()
{
  idCVar::idCVar(
    this: &ai_debugWeb,
    name: "ai_debugWeb",
    value: "-1",
    flags: 2,
    description: "output debug info for the AI with matching entity number",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugWeb__);
}


// ========================================================================
// `dynamic initializer for 'ai_deathAnimScale''
// EA  : 0x83368BD0
// RVA : 0x01368BD0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_deathAnimScale__()
{
  idCVar::idCVar(
    this: &ai_deathAnimScale,
    name: "ai_deathAnimScale",
    value: "1.0",
    flags: 4,
    description: "scale death animation rate by this factor",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_deathAnimScale__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugtransitiondirs''
// EA  : 0x83368C28
// RVA : 0x01368C28
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugtransitiondirs__()
{
  idCVar::idCVar(
    this: &ai_debugtransitiondirs,
    name: "ai_debugtransitiondirs",
    value: "0",
    flags: 1,
    description: "if true, show desired transition direciton",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugtransitiondirs__);
}


// ========================================================================
// `dynamic initializer for 'ai_stairWalkRate''
// EA  : 0x83368C80
// RVA : 0x01368C80
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_stairWalkRate__()
{
  idCVar::idCVar(
    this: &ai_stairWalkRate,
    name: "ai_stairWalkRate",
    value: "0.5",
    flags: 4,
    description: "sets the rate to scale walk animations when on stairs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_stairWalkRate__);
}


// ========================================================================
// `dynamic initializer for 'ai_stairRunRate''
// EA  : 0x83368CD8
// RVA : 0x01368CD8
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_stairRunRate__()
{
  idCVar::idCVar(
    this: &ai_stairRunRate,
    name: "ai_stairRunRate",
    value: "0.5",
    flags: 4,
    description: "sets the rate to scale run animations when on stairs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_stairRunRate__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugForwardRunIndex''
// EA  : 0x83368D30
// RVA : 0x01368D30
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugForwardRunIndex__()
{
  idCVar::idCVar(
    this: &ai_debugForwardRunIndex,
    name: "ai_debugForwardRunIndex",
    value: "0",
    flags: 2,
    description: "show the forward run index and blend",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugForwardRunIndex__);
}


// ========================================================================
// `dynamic initializer for 'ai_runCycleBlendMode''
// EA  : 0x83368D88
// RVA : 0x01368D88
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_runCycleBlendMode__()
{
  idCVar::idCVar(
    this: &ai_runCycleBlendMode,
    name: "ai_runCycleBlendMode",
    value: "2",
    flags: 2,
    description: "set the blend mode for ai run cycles: 0: linear, 1: easein, 2: easeout, 3: easeinout",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_runCycleBlendMode__);
}


// ========================================================================
// `dynamic initializer for 'ai_turnLeanLerpScaleUp''
// EA  : 0x83368DE0
// RVA : 0x01368DE0
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_turnLeanLerpScaleUp__()
{
  idCVar::idCVar(
    this: &ai_turnLeanLerpScaleUp,
    name: "ai_turnLeanLerpScaleUp",
    value: "0.075",
    flags: 4,
    description: "sets the rate at which the AI's blends towards leaning when turning",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_turnLeanLerpScaleUp__);
}


// ========================================================================
// `dynamic initializer for 'ai_turnLeanLerpScaleDown''
// EA  : 0x83368E38
// RVA : 0x01368E38
// PDB : w:\tech5\tungsten\game\ai\animwebai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_turnLeanLerpScaleDown__()
{
  idCVar::idCVar(
    this: &ai_turnLeanLerpScaleDown,
    name: "ai_turnLeanLerpScaleDown",
    value: "0.04",
    flags: 4,
    description: "sets the rate at which the AI's blends when straightning out from a turn",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_turnLeanLerpScaleDown__);
}

