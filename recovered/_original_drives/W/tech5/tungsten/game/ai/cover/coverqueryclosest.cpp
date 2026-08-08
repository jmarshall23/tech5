
// ========================================================================
// ?InternalScoreCover@idCoverQueryClosest@@MAAMABUcoverCache_t@idCoverQuery@@@Z
// EA  : 0x82A8D220
// RVA : 0x00A8D220
// PDB : w:\tech5\tungsten\game\ai\cover\coverqueryclosest.cpp
// ========================================================================

float __fastcall idCoverQueryClosest::InternalScoreCover(
        idCoverQueryClosest *this,
        const idCoverQuery::coverCache_t *cached)
{
  idAICover *v4; // r30
  double v5; // fp1
  const aas2Cover_t *Origin; // r3
  bool IsPartiallyExposed; // r28
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  const idPlayerCoverScore_t *CoverScoreInfo; // r3
  const aas2Cover_t *v11; // r3
  const idAAS2 *aas; // r29
  idAASVisCache *p_aasVisCache; // r28
  int AreaNum; // r3
  const aas2Cover_t *v15; // r3
  double coverPathNearDistance; // fp31
  int v17; // r26
  int v18; // r25
  int v19; // r3
  bool v20; // r10
  const aas2Cover_t *v21; // r3
  const aas2Cover_t *v22; // r3
  double v23; // fp10
  double v24; // fp8
  double v25; // fp6
  idVec3 v27[2]; // [sp+60h] [-60h] BYREF

  v4 = &this->ai->aiVolatile.coverManager.knownCover.list[cached->index];
  if ( (unsigned __int8)idAICover::IsValid(this: v4) != 0 )
  {
    if ( !idAICover::IsPointInFrontOf(this: v4, point: &this->target.origin) )
    {
      Origin = idAICover::GetOrigin(this: v4);
      v5 = idCoverQuery::DebugFailedTarget(
             this,
             message: "BEHIND",
             origin: &Origin->origin,
             targetOrigin: &this->target.origin,
             minLevel: 1);
      return *((float *)&v5 + 1);
    }
    idAICover::GetEyePoint(this: v4, user: this->ai, eyePoint: v27);
    IsPartiallyExposed = idAICover::IsPartiallyExposed(this: v4);
    if ( g_usePlayerCoverCheck.valueInteger != 0
      && (v8 = (idPlayer *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: this->target.spawnId.value),
          (v9 = idPlayer::CastTo(c: v8)) != nullptr) )
    {
      CoverScoreInfo = idPlayer::GetCoverScoreInfo(this: v9, coverIndex: v4->coverIndex);
      if ( CoverScoreInfo != nullptr && !IsPartiallyExposed && CoverScoreInfo->standingScore > 0.5 )
      {
        v11 = idAICover::GetOrigin(this: v4);
        v5 = idCoverQuery::DebugFailedTarget(
               this,
               message: "TARGET_VISIBLE (PCS)",
               origin: &v11->origin,
               targetOrigin: &this->target.origin,
               minLevel: 1);
        return *((float *)&v5 + 1);
      }
    }
    else if ( !IsPartiallyExposed )
    {
      aas = this->target.vcPos.aas;
      p_aasVisCache = &gameLocal->aasVisCache;
      AreaNum = idAASPosition::GetAreaNum(this: &this->target.vcPos);
      if ( (unsigned __int8)idAASVisCache::IsPointVisible(
                              this: p_aasVisCache,
                              eyePoint: v27,
                              destPoint: &this->target.eyePoint,
                              aas,
                              destAreaNum: AreaNum) != 0 )
      {
        v15 = idAICover::GetOrigin(this: v4);
        v5 = idCoverQuery::DebugFailedTarget(
               this,
               message: "TARGET_VISIBLE(AASVIS)",
               origin: &v15->origin,
               targetOrigin: &this->target.origin,
               minLevel: 1);
        return *((float *)&v5 + 1);
      }
    }
    coverPathNearDistance = this->ai->aiEditable.behaviors.decl->coverPathNearDistance;
    v17 = idAASPosition::GetAreaNum(this: &this->target.aiPos);
    v18 = idAASPosition::GetAreaNum(this: &cached->aiPos);
    v19 = idAASPosition::GetAreaNum(this: &this->aiaiPos);
    if ( (unsigned __int8)idAI2::PathPassesNear(
                            this: this->ai,
                            startPoint: &this->aiaiPos.origin,
                            goalPoint: &cached->aiPos.origin,
                            startAreaNum: v19,
                            goalAreaNum: v18,
                            testPoint: &this->target.aiPos.origin,
                            testAreaNum: v17,
                            nearDist: coverPathNearDistance,
                            debug: v20) != 0 )
    {
      v21 = idAICover::GetOrigin(this: v4);
      v5 = idCoverQuery::DebugFailedTarget(
             this,
             message: "PATH_NEAR",
             origin: &v21->origin,
             targetOrigin: &this->target.aiPos.origin,
             minLevel: 1);
      return *((float *)&v5 + 1);
    }
    v22 = idAICover::GetOrigin(this: v4);
    v23 = (float)(v22->origin.z - this->desiredCoverPosition.z);
    v24 = (float)(v22->origin.x - this->desiredCoverPosition.x);
    v25 = (float)(v22->origin.y - this->desiredCoverPosition.y);
    if ( (float)((float)((float)v25 * (float)v25)
               + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23))) <= 262144.0 )
    {
      v5 = (float)((float)0.001
                 - (float)((float)((float)((float)((float)v25 * (float)v25)
                                         + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)))
                                 * (float)0.0000038146973)
                         - (float)0.99900001));
      return *((float *)&v5 + 1);
    }
  }
  v5 = 0.0;
  return *((float *)&v5 + 1);
}


// ========================================================================
// ??0idCoverQueryClosest@@QAA@PAVidAI2@@ABVidAICover@@ABVidVec3@@@Z
// EA  : 0x82A8D510
// RVA : 0x00A8D510
// PDB : w:\tech5\tungsten\game\ai\cover\coverqueryclosest.cpp
// ========================================================================

idCoverQueryClosest *__fastcall idCoverQueryClosest::idCoverQueryClosest(
        idCoverQueryClosest *this,
        idAI2 *ai,
        const idAICover *exclude,
        const idVec3 *_desiredCoverPosition)
{
  idCoverQuery::idCoverQuery(this, ai, exclude, flags: 31);
  this->__vftable = (idCoverQueryClosest_vtbl *)&idCoverQueryClosest::`vftable';
  this->desiredCoverPosition = *_desiredCoverPosition;
  return this;
}

