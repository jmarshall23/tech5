
// ========================================================================
// ??1idRibbon@@QAA@XZ
// EA  : 0x82ECD140
// RVA : 0x00ECD140
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void __fastcall idRibbon::~idRibbon(idRibbon *this)
{
  this->ribbonDecl = nullptr;
}


// ========================================================================
// ??1idMeleeTrace@@UAA@XZ
// EA  : 0x82ECD158
// RVA : 0x00ECD158
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void __fastcall idMeleeTrace::~idMeleeTrace(idMeleeTrace *this)
{
  idClipModel *clipModel; // r4

  this->__vftable = (idMeleeTrace_vtbl *)&idMeleeTrace::`vftable';
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClip::DeleteClipModel(this: &clientGame->clip, clipModel);
  this->clipModel = nullptr;
  this->__vftable = (idMeleeTrace_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$488109_0
// EA  : 0x82ECD1CC
// RVA : 0x00ECD1CC
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void _unwind_488109_0()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// ?Start@idMeleeTrace@@QAAXABVidVec3@@HMW4meleeDamage_t@1@W4meleeBounds_t@1@PBVidDeclDamage@@PBVidDeclProjectileImpactEffect@@@Z
// EA  : 0x82ECD1F8
// RVA : 0x00ECD1F8
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void __fastcall idMeleeTrace::Start(
        idMeleeTrace *this,
        const idVec3 *startPos,
        int numSamples_,
        double damageCap_,
        const idMeleeTrace::meleeDamage_t meleeType_,
        const idMeleeTrace::meleeBounds_t boundsType_,
        const idDeclDamage *damageDef_,
        const idDeclDamage *impactEffect_,
        const idDeclProjectileImpactEffect *a9)
{
  this->damageCap = damageCap_;
  this->damageDef = impactEffect_;
  this->impactEffect = a9;
  this->jointIndex.value = -1;
  this->jointIndex2.value = -1;
  this->useWeaponAnimator = false;
  this->numSamples = numSamples_;
  this->meleeType = boundsType_;
  this->boundsType = (unsigned __int8)damageDef_;
  this->prevPos = *startPos;
  this->useTagData = false;
  this->hasKilled = false;
  this->hasHit = false;
  this->hitEntity = nullptr;
}


// ========================================================================
// ?Start@idMeleeTrace@@QAAXABVidVec3@@ABUtagData_t@@_NHMW4meleeDamage_t@1@W4meleeBounds_t@1@PBVidDeclDamage@@PBVidDeclProjectileImpactEffect@@@Z
// EA  : 0x82ECD250
// RVA : 0x00ECD250
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void __fastcall idMeleeTrace::Start(
        idMeleeTrace *this,
        const idVec3 *startPos,
        const tagData_t *tagData_,
        bool useWeaponAnimator_,
        int numSamples_,
        double damageCap_,
        const idMeleeTrace::meleeDamage_t meleeType_,
        const idMeleeTrace::meleeBounds_t bounds_,
        const idDeclDamage *damageDef_,
        const idDeclProjectileImpactEffect *impactEffect_,
        int a11,
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
        const idDeclDamage *a29,
        int a30,
        const idDeclProjectileImpactEffect *a31)
{
  this->jointIndex.value = -1;
  this->damageCap = damageCap_;
  this->jointIndex2.value = -1;
  this->useWeaponAnimator = useWeaponAnimator_;
  this->damageDef = a29;
  this->impactEffect = a31;
  this->numSamples = numSamples_;
  this->meleeType = bounds_;
  this->boundsType = (unsigned __int8)damageDef_;
  this->prevPos = *startPos;
  this->tagData = *tagData_;
  this->useTagData = true;
  this->hasKilled = false;
  this->hasHit = false;
  this->hitEntity = nullptr;
}


// ========================================================================
// ?Start@idMeleeTrace@@QAAXPBVidTreeAnimator@@V?$idIndex@FW4invalidJointIndex_t@@@@HMW4meleeDamage_t@1@W4meleeBounds_t@1@PBVidDeclDamage@@PBVidDeclProjectileImpactEffect@@@Z
// EA  : 0x82ECD308
// RVA : 0x00ECD308
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void __fastcall idMeleeTrace::Start(
        idMeleeTrace *this,
        idTreeAnimator *ta,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex_,
        int numSamples_,
        double damageCap_,
        const idMeleeTrace::meleeDamage_t meleeType_,
        const idMeleeTrace::meleeBounds_t boundsType_,
        const idDeclDamage *damageDef_,
        const idDeclDamage *impactEffect_,
        int a10,
        int a11,
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
        const idDeclProjectileImpactEffect *a29)
{
  idMat3 v29; // [sp+50h] [-40h] BYREF

  if ( (__int16)jointIndex_ >= 0 )
  {
    this->jointIndex.value = (__int16)jointIndex_;
    this->numSamples = numSamples_;
    this->boundsType = (unsigned __int8)damageDef_;
    this->damageCap = damageCap_;
    this->damageDef = impactEffect_;
    this->impactEffect = a29;
    this->jointIndex2.value = -1;
    this->useWeaponAnimator = false;
    this->meleeType = boundsType_;
    this->useTagData = false;
    this->hasKilled = false;
    this->hasHit = false;
    this->hitEntity = nullptr;
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: ta,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointIndex.value,
      origin: &this->prevPos,
      axis: &v29);
  }
  else
  {
    this->numSamples = 0;
  }
}


// ========================================================================
// ?Start@idMeleeTrace@@QAAXPBVidTreeAnimator@@V?$idIndex@FW4invalidJointIndex_t@@@@1HMW4meleeDamage_t@1@W4meleeBounds_t@1@PBVidDeclDamage@@PBVidDeclProjectileImpactEffect@@@Z
// EA  : 0x82ECD3B8
// RVA : 0x00ECD3B8
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void __fastcall idMeleeTrace::Start(
        idMeleeTrace *this,
        idTreeAnimator *ta,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex_,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex2_,
        int numSamples_,
        double damageCap_,
        const idMeleeTrace::meleeDamage_t meleeType_,
        const idMeleeTrace::meleeBounds_t boundsType_,
        const idDeclDamage *damageDef_,
        const idDeclProjectileImpactEffect *impactEffect_,
        int a11,
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
        const idDeclDamage *a29,
        int a30,
        const idDeclProjectileImpactEffect *a31)
{
  idMat3 v31; // [sp+50h] [-40h] BYREF

  if ( (__int16)jointIndex_ >= 0 )
  {
    this->damageCap = damageCap_;
    this->jointIndex.value = (__int16)jointIndex_;
    this->jointIndex2.value = (__int16)jointIndex2_;
    this->numSamples = numSamples_;
    this->damageDef = a29;
    this->impactEffect = a31;
    this->useWeaponAnimator = false;
    this->meleeType = boundsType_;
    this->boundsType = (unsigned __int8)damageDef_;
    this->useTagData = false;
    this->hasKilled = false;
    this->hasHit = false;
    this->hitEntity = nullptr;
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: ta,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)jointIndex_,
      origin: &this->prevPos,
      axis: &v31);
  }
  else
  {
    this->numSamples = 0;
  }
}


// ========================================================================
// ?Start@idMeleeTrace@@QAAXABVidVec3@@ABUtagData_t@@_NV?$idIndex@FW4invalidJointIndex_t@@@@HMW4meleeDamage_t@1@W4meleeBounds_t@1@PBVidDeclDamage@@PBVidDeclProjectileImpactEffect@@@Z
// EA  : 0x82ECD460
// RVA : 0x00ECD460
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void __fastcall idMeleeTrace::Start(
        idMeleeTrace *this,
        const idVec3 *startPos,
        const tagData_t *tagData_,
        bool useWeaponAnimator_,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex2_,
        int numSamples_,
        double damageCap_,
        const idMeleeTrace::meleeDamage_t meleeType_,
        const idMeleeTrace::meleeBounds_t bounds_,
        const idDeclDamage *damageDef_,
        const idDeclProjectileImpactEffect *impactEffect_,
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
        unsigned __int8 a29,
        int a30,
        const idDeclDamage *a31,
        int a32,
        const idDeclProjectileImpactEffect *a33)
{
  this->damageCap = damageCap_;
  this->jointIndex.value = -1;
  this->jointIndex2.value = (__int16)jointIndex2_;
  this->damageDef = a31;
  this->useWeaponAnimator = useWeaponAnimator_;
  this->impactEffect = a33;
  this->numSamples = numSamples_;
  this->meleeType = bounds_;
  this->boundsType = a29;
  this->prevPos = *startPos;
  this->tagData = *tagData_;
  this->useTagData = true;
  this->hasKilled = false;
  this->hasHit = false;
  this->hitEntity = nullptr;
}


// ========================================================================
// ??0idMeleeTrace@@QAA@XZ
// EA  : 0x82ECD518
// RVA : 0x00ECD518
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

idMeleeTrace *__fastcall idMeleeTrace::idMeleeTrace(idMeleeTrace *this)
{
  this->damageDef = nullptr;
  this->__vftable = (idMeleeTrace_vtbl *)&idMeleeTrace::`vftable';
  this->impactEffect = nullptr;
  this->upgradDamageScale = 1;
  this->jointIndex.value = -1;
  this->jointIndex2.value = -1;
  this->tagData.trans.x = 0.0;
  this->tagData.trans.y = 0.0;
  this->tagData.trans.z = 0.0;
  this->tagData.rot.x = 0.0;
  this->tagData.rot.y = 0.0;
  this->tagData.rot.z = 0.0;
  this->tagData.rot.w = 0.0;
  this->tagData.parentJoint.value = -1;
  this->damageCap = 0.0;
  this->useTagData = false;
  this->hasKilled = false;
  this->hasHit = false;
  this->numSamples = 0;
  this->meleeType = 4;
  this->boundsType = 9;
  this->prevPos.x = 0.0;
  this->prevPos.y = 0.0;
  this->prevPos.z = 0.0;
  this->clipModel = nullptr;
  this->hitEntity = nullptr;
  this->weapon = nullptr;
  this->lastHitTime = 0;
  return this;
}


// ========================================================================
// ?Update@idMeleeTrace@@QAA_NPAVidAnimatedEntity@@ABVidVec3@@1_N@Z
// EA  : 0x82ECD618
// RVA : 0x00ECD618
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

int __fastcall idMeleeTrace::Update(
        idMeleeTrace *this,
        idAI2 *owner,
        const idVec3 *curPos,
        const idVec3 *curPos2,
        bool pastUpdate)
{
  int v10; // r17
  int result; // r3
  int numSamples; // r11
  int boundsType; // r11
  idVec3 *p_prevPos; // r22
  int v15; // r10
  idClipModel *clip16x16; // r31
  idClientGame *v17; // r11
  int v18; // r28
  bool v19; // zf
  idRenderWorld *v20; // r3
  int GameMs; // r3
  idAI2 *v22; // r28
  idRenderWorld *v23; // r3
  idRenderWorld *v24; // r3
  idRenderWorld *v25; // r3
  idRenderWorld *v26; // r3
  idRenderWorld *v27; // r3
  double v28; // fp9
  double v29; // fp6
  idPlayer *v30; // r31
  bool v31; // r30
  idActor *v32; // r3
  double v33; // fp1
  idRenderWorld *v34; // r3
  idRenderWorld *v35; // r3
  idRenderWorld *v36; // r3
  idPlayer_vtbl *v37; // r10
  __int64 v38; // r7
  idDeclProjectileImpactEffect *impactEffect; // r3
  const idDeclProjectileImpactEffect::projectileImpactEffect_t *ImpactEffectForMaterial; // r27
  char IsType; // r28
  idPlayer_vtbl *v42; // r30
  idPresentable *presentable; // r30
  int v44; // r11
  __int128 v45; // r10
  __int64 v46; // r6
  idAI2 *v47; // r30
  idPlayer *v48; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *JointName; // r3
  int *p_hashSize; // r4
  idRenderWorld *v52; // r3
  double v53; // fp31
  idRenderWorld *v54; // r3
  idRenderWorld *v55; // r3
  idColor *v56; // r4
  idRenderWorld *v57; // r3
  const idPresentable *v58; // [sp+8h] [-1E8h]
  idPresentable *v59; // [sp+Ch] [-1E4h]
  char *v60; // [sp+10h] [-1E0h]
  int v61; // [sp+14h] [-1DCh]
  int v62; // [sp+18h] [-1D8h]
  int v63; // [sp+1Ch] [-1D4h]
  int v64; // [sp+20h] [-1D0h]
  int v65; // [sp+24h] [-1CCh]
  int v66; // [sp+28h] [-1C8h]
  int v67; // [sp+2Ch] [-1C4h]
  int v68; // [sp+30h] [-1C0h]
  int v69; // [sp+34h] [-1BCh]
  int v70; // [sp+38h] [-1B8h]
  int v71; // [sp+3Ch] [-1B4h]
  int v72; // [sp+40h] [-1B0h]
  int v73; // [sp+44h] [-1ACh]
  int v74; // [sp+48h] [-1A8h]
  int v75; // [sp+4Ch] [-1A4h]
  int v76[20]; // [sp+50h] [-1A0h] BYREF
  idAIEventManager v77; // [sp+A0h] [-150h] BYREF
  __int64 v78; // [sp+F0h] [-100h]
  __int64 v79; // [sp+F8h] [-F8h]
  __int64 v80; // [sp+100h] [-F0h]
  int v81; // [sp+108h] [-E8h]
  int v82; // [sp+10Ch] [-E4h]
  _QWORD v83[11]; // [sp+110h] [-E0h] BYREF

  v10 = 0;
  if ( owner == nullptr )
    return 0;
  numSamples = this->numSamples;
  if ( numSamples == 0 )
    return 0;
  if ( numSamples > 0 )
    this->numSamples = numSamples - 1;
  boundsType = this->boundsType;
  if ( this->boundsType == 0 )
  {
    p_prevPos = &this->prevPos;
    idClip::TracePoint(
      this: &clientGame->clip,
      result: (trace_t *)&v77.eventPools,
      start: &this->prevPos,
      end: curPos,
      clipMask: 8462469,
      passEntityNumber: owner->entityNumber);
    goto LABEL_29;
  }
  v15 = boundsType - 1;
  clip16x16 = nullptr;
  v18 = 8467589;
  v19 = (unsigned int)(boundsType - 1) > 7;
  v17 = clientGame;
  if ( !v19 )
  {
    switch ( v15 )
    {
      case 1:
        clip16x16 = clientGame->clip.clip16x16;
        break;
      case 2:
        clip16x16 = clientGame->clip.clip24x24;
        break;
      case 3:
        clip16x16 = clientGame->clip.clip32x32;
        break;
      case 4:
        clip16x16 = clientGame->clip.clip48x48;
        break;
      case 5:
        clip16x16 = clientGame->clip.clip96x96;
        break;
      case 6:
        clip16x16 = clientGame->clip.playerMeleeClipModel;
        v18 = 8462469;
        break;
      default:
        if ( v15 != 0 )
          clip16x16 = this->clipModel;
        else
          clip16x16 = clientGame->clip.clip8x8;
        break;
    }
  }
  if ( g_debugMeleeTraces.valueInteger == 2 )
  {
    v20 = gameLocal->GetRenderWorld(this: gameLocal);
    v20->DebugBounds(
      this: v20,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: &clip16x16->bounds,
      a4: curPos,
      a5: 16,
      a6: false);
    v17 = clientGame;
  }
  p_prevPos = &this->prevPos;
  idClip::Translation(
    this: (idClip *)&v77.eventHash,
    result: &v17->clip,
    a3: (trace_t *)&v77.eventPools,
    start: &this->prevPos,
    end: curPos,
    clipModel: clip16x16,
    startAxis: &mat3_identity,
    clipMask: v18,
    passEntityNumber: (int)v58,
    moveClipModel: (bool)v59,
    userName: v60,
    a12: v61,
    a13: v62,
    a14: v63,
    a15: v64,
    a16: v65,
    a17: v66,
    a18: v67,
    a19: v68,
    a20: v69,
    a21: v70,
    a22: v71,
    a23: v72,
    a24: v73,
    a25: v74,
    a26: v75,
    a27: v76[0],
    a28: owner->entityNumber,
    a29: v76[2],
    a30: false,
    a31: v76[4],
    a32: 0);
  if ( *(float *)&v77.eventPools.list == 1.0 )
  {
    if ( (unsigned __int16)this->jointIndex2.value < 0x8000u )
      idClip::Translation(
        this: (idClip *)&v77.eventHash,
        result: &clientGame->clip,
        a3: (trace_t *)&v77.eventPools,
        start: curPos2,
        end: curPos,
        clipModel: clip16x16,
        startAxis: &mat3_identity,
        clipMask: v18,
        passEntityNumber: (int)v58,
        moveClipModel: (bool)v59,
        userName: v60,
        a12: v61,
        a13: v62,
        a14: v63,
        a15: v64,
        a16: v65,
        a17: v66,
        a18: v67,
        a19: v68,
        a20: v69,
        a21: v70,
        a22: v71,
        a23: v72,
        a24: v73,
        a25: v74,
        a26: v75,
        a27: v76[0],
        a28: owner->entityNumber,
        a29: v76[2],
        a30: false,
        a31: v76[4],
        a32: 0);
LABEL_29:
    if ( *(float *)&v77.eventPools.list == 1.0 )
    {
      if ( g_debugMeleeTraces.valueInteger == 0 )
        goto LABEL_89;
      v57 = gameLocal->GetRenderWorld(this: gameLocal);
      v53 = 4.0;
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, const idVec3 *, double))v57->DebugArrow)(
        a1: v57,
        a2: &idColor::colorGreen,
        a3: p_prevPos,
        a4: curPos,
        a5: 4.0);
      if ( (unsigned __int16)this->jointIndex2.value >= 0x8000u )
        goto LABEL_89;
      v55 = gameLocal->GetRenderWorld(this: gameLocal);
      v56 = &idColor::colorGreen;
LABEL_88:
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, const idVec3 *, double))v55->DebugArrow)(
        a1: v55,
        a2: v56,
        a3: curPos,
        a4: curPos2,
        a5: v53);
LABEL_89:
      result = v10;
      goto LABEL_90;
    }
  }
  if ( hitEventDecl == nullptr )
    hitEventDecl = (const idDeclAiEvent *)idDeclInfo::FindWithInheritance(
                                            this: &idDeclAiEvent::resourceList,
                                            name: "base/explosion/small",
                                            makeDefault: true);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAIEventManager::AddEvent(
    this: &v77,
    result: &gameLocal->aiEventManager,
    eventDecl: hitEventDecl,
    curTime: GameMs,
    originator: owner,
    instigator: owner,
    origin: curPos,
    delay: 500);
  v22 = (idAI2 *)gameLocal->GetEntity(this: gameLocal, a2: v83[7]);
  if ( idAI2::CastTo(c: v22) != nullptr && !v22->TakesDamage(this: v22) )
  {
    if ( g_debugMeleeTraces.valueInteger != 0 )
    {
      v23 = gameLocal->GetRenderWorld(this: gameLocal);
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, const idVec3 *, double))v23->DebugArrow)(
        a1: v23,
        a2: &idColor::colorGreen,
        a3: p_prevPos,
        a4: curPos,
        a5: 4.0);
      if ( (unsigned __int16)this->jointIndex2.value < 0x8000u )
      {
        v24 = gameLocal->GetRenderWorld(this: gameLocal);
        ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, const idVec3 *, double))v24->DebugArrow)(
          a1: v24,
          a2: &idColor::colorGreen,
          a3: curPos,
          a4: curPos2,
          a5: 4.0);
      }
      idLib::Warning(fmt: "would have hit a friendly ai %s, so skipping", v22->name.data);
    }
    goto LABEL_89;
  }
  if ( this->meleeType != 2 )
    goto LABEL_48;
  if ( idActor::CastTo(c: v22) != nullptr )
  {
    if ( this->hasHit && !pastUpdate && idPlayer::CastTo(c: (idPlayer *)v22) == nullptr )
    {
      if ( g_debugMeleeTraces.valueInteger != 0 )
      {
        v25 = gameLocal->GetRenderWorld(this: gameLocal);
        ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, int *, double))v25->DebugArrow)(
          a1: v25,
          a2: &idColor::colorYellow,
          a3: p_prevPos,
          a4: &v77.eventPools.num,
          a5: 4.0);
        v26 = gameLocal->GetRenderWorld(this: gameLocal);
        v26->DebugPoint(
          this: v26,
          a2: (const idVec4 *)&idColor::colorYellow,
          a3: (const idVec3 *)&v83[1],
          a4: 4000,
          a5: true);
        if ( (unsigned __int16)this->jointIndex2.value < 0x8000u )
        {
          v27 = gameLocal->GetRenderWorld(this: gameLocal);
          ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, const idVec3 *, double))v27->DebugArrow)(
            a1: v27,
            a2: &idColor::colorYellow,
            a3: curPos,
            a4: curPos2,
            a5: 4.0);
        }
      }
      goto LABEL_46;
    }
    this->numSamples = 0;
    goto LABEL_48;
  }
  if ( !this->hasHit )
  {
LABEL_48:
    if ( idActor::CastTo(c: v22) != nullptr && this->meleeType == 1 || this->meleeType == 0 )
      this->numSamples = 0;
    this->hasHit = true;
    v28 = (float)(curPos->x - p_prevPos->x);
    v29 = (float)(curPos->y - p_prevPos->y);
    *(float *)&v77.eventHash.lookupMask = curPos->z - p_prevPos->z;
    *(float *)&v77.eventHash.granularity = v28;
    *(float *)&v77.eventHash.hashMask = v29;
    idVec3::NormalizeFast(this: (idVec3 *)&v77.eventHash.granularity);
    v30 = (idPlayer *)gameLocal->entities.ptr[LODWORD(v83[7])];
    if ( v30 == nullptr )
      goto LABEL_89;
    v10 = 1;
    this->lastHitTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v31 = (_cntlzw(v30->IsDead(this: v30)) & 0x20) != 0;
    v32 = idActor::CastTo(c: owner);
    if ( v32 != nullptr )
      v32->GetApplyDamageScale(this: v32);
    else
      v33 = 1.0;
    v37 = v30->__vftable;
    LODWORD(v38) = this->upgradDamageScale;
    HIDWORD(v38) = this->damageDef;
    *(_QWORD *)&v77.eventList.list = v38;
    ((void (__fastcall *)(idPlayer *, _DWORD, idAI2 *, _DWORD, double))v37->Damage)(
      a1: v30,
      a2: 0,
      a3: owner,
      a4: HIDWORD(v38),
      a5: (float)((float)v38 * (float)v33));
    this->hitEntity = v30;
    if ( v31 && v30->IsDead(this: v30) )
      this->hasKilled = true;
    impactEffect = this->impactEffect;
    if ( impactEffect != nullptr )
    {
      ImpactEffectForMaterial = idDeclProjectileImpactEffect::GetImpactEffectForMaterial(
                                  this: impactEffect,
                                  materialID: SHIDWORD(v83[6]));
      if ( ImpactEffectForMaterial != nullptr && idAnimatedEntity::CastTo(c: owner) != nullptr )
      {
        IsType = idClass::IsType(this: v30, superclass: &idPlayer::Type);
        v42 = v30->__vftable;
        memcpy(Dst: v76, Src: v83, Size: sizeof(v76));
        ((void (__fastcall *)(idAIEventManager *, idAIEventPool **, int, _DWORD, _DWORD, _DWORD, int, int))v42->GetJointIndexFromTrace)(
          a1: &v77,
          a2: v77.eventPools.list,
          a3: v77.eventPools.size,
          a4: HIDWORD(v78),
          a5: HIDWORD(v79),
          a6: HIDWORD(v80),
          a7: v81,
          a8: v82);
        if ( owner->presentable == nullptr )
          idEntity::InitPresentableInternal(this: owner);
        presentable = owner->presentable;
        v44 = (int)v30->presentable;
        if ( v44 == 0 )
        {
          idEntity::InitPresentableInternal(this: v30);
          v44 = (int)v30->presentable;
        }
        LODWORD(v45) = LOBYTE(v83[9]);
        *(float *)&v77.receivers.granularity = 1.0;
        DWORD2(v45) = BYTE5(v83[9]);
        DWORD1(v45) = byte_821B0000;
        LODWORD(v46) = BYTE6(v83[9]);
        HIDWORD(v46) = (char *)&v83[2] + 4;
        *(_QWORD *)&v77.eventHash.hash = *(_QWORD *)((char *)&v45 + 4);
        *(_QWORD *)&v77.eventList.size = v46;
        *(float *)&v77.receivers.num = (float)v46 * (float)0.0039215689;
        *(float *)&v77.receivers.list = (float)*(__int64 *)((char *)&v45 + 4) * (float)0.0039215689;
        *(float *)&v77.receivers.size = (float)(__int64)v45 * (float)0.0039215689;
        idClientGame::ImpactEffect(
          this: clientGame,
          point: (const idMat3 *)&v83[1],
          normal: (idMat3 *)((char *)&v83[2] + 4),
          color: (idColor *)&v77.receivers,
          effect: ImpactEffectForMaterial,
          skipParticle: false,
          noDecals: IsType,
          noSounds: false,
          owner: v58,
          entity: v59,
          jointId: (idIndex<short,enum invalidJointIndex_t> *)v60,
          a12: v61,
          a13: v62,
          a14: v63,
          a15: v64,
          a16: v65,
          a17: v66,
          a18: v67,
          a19: v68,
          a20: v69,
          a21: v70,
          a22: v71,
          a23: v72,
          a24: v73,
          a25: v74,
          a26: v75,
          a27: v76[0],
          a28: (int)presentable,
          a29: v76[2],
          a30: v44,
          a31: v76[4],
          a32: HIWORD(v77.eventList.list));
      }
    }
    v47 = idAI2::CastTo(c: owner);
    v48 = idPlayer::CastTo(c: v30);
    if ( (unsigned __int16)this->jointIndex.value < 0x8000u && v47 != nullptr && v48 != nullptr )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v47);
      JointName = idTreeAnimator::GetJointName(
                    this: TreeAnimatorFromPresentable,
                    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointIndex.value);
      if ( strstr(str1: JointName, str2: "left") != nullptr )
      {
        idAtomicString::Set(this: (idAtomicString *)&v77.eventHash.hashSize, str_: "lhand_splashback");
        p_hashSize = &v77.eventHash.hashSize;
      }
      else
      {
        idAtomicString::Set(this: (idAtomicString *)&v77.eventHash.indexSize, str_: "rhand_splashback");
        p_hashSize = &v77.eventHash.indexSize;
      }
      idAI2::CheckForGoreByName(this: v47, goreName: (const idAtomicString *)p_hashSize);
    }
    if ( v30->TakesDamage(this: v30) )
      this->damageCap = this->damageCap - this->damageDef->maxDamage;
    if ( this->damageCap <= 0.0 )
      this->numSamples = 0;
    if ( g_debugMeleeTraces.valueInteger == 0 )
      goto LABEL_89;
    v52 = gameLocal->GetRenderWorld(this: gameLocal);
    v53 = 4.0;
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, int *, double))v52->DebugArrow)(
      a1: v52,
      a2: &idColor::colorRed,
      a3: p_prevPos,
      a4: &v77.eventPools.num,
      a5: 4.0);
    v54 = gameLocal->GetRenderWorld(this: gameLocal);
    v54->DebugPoint(this: v54, a2: (const idVec4 *)&idColor::colorRed, a3: (const idVec3 *)&v83[1], a4: 4000, a5: true);
    if ( (unsigned __int16)this->jointIndex2.value >= 0x8000u )
      goto LABEL_89;
    v55 = gameLocal->GetRenderWorld(this: gameLocal);
    v56 = &idColor::colorRed;
    goto LABEL_88;
  }
  if ( g_debugMeleeTraces.valueInteger != 0 )
  {
    v34 = gameLocal->GetRenderWorld(this: gameLocal);
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, int *, double))v34->DebugArrow)(
      a1: v34,
      a2: &idColor::colorWhite,
      a3: p_prevPos,
      a4: &v77.eventPools.num,
      a5: 4.0);
    v35 = gameLocal->GetRenderWorld(this: gameLocal);
    v35->DebugPoint(
      this: v35,
      a2: (const idVec4 *)&idColor::colorWhite,
      a3: (const idVec3 *)&v83[1],
      a4: 4000,
      a5: true);
    if ( (unsigned __int16)this->jointIndex2.value < 0x8000u )
    {
      v36 = gameLocal->GetRenderWorld(this: gameLocal);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, const idVec3 *, double))v36->DebugArrow)(
        a1: v36,
        a2: &idColor::colorWhite,
        a3: curPos,
        a4: curPos2,
        a5: 4.0);
      result = 0;
      goto LABEL_90;
    }
  }
LABEL_46:
  result = 0;
LABEL_90:
  p_prevPos->x = curPos->x;
  p_prevPos->y = curPos->y;
  p_prevPos->z = curPos->z;
  return result;
}


// ========================================================================
// ?Update@idMeleeTrace@@QAA_NPAVidAnimatedEntity@@PBVidTreeAnimator@@ABVidVec3@@@Z
// EA  : 0x82ECE128
// RVA : 0x00ECE128
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

int __fastcall idMeleeTrace::Update(idMeleeTrace *this, idAI2 *owner, idTreeAnimator *ta, const idVec3 *offset)
{
  unsigned int value; // r11
  double v10; // fp6
  double v11; // fp7
  double v12; // fp6
  idVec3 v13; // [sp+50h] [-70h] BYREF
  idVec3 v14; // [sp+60h] [-60h] BYREF
  idMat3 v15[2]; // [sp+70h] [-50h] BYREF

  if ( (unsigned __int16)this->jointIndex.value < 0x8000u )
  {
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: ta,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointIndex.value,
      origin: &v14,
      axis: v15);
    value = (unsigned __int16)this->jointIndex2.value;
    v10 = (float)(offset->y + v14.y);
    v14.x = offset->x + v14.x;
    v14.y = v10;
    v14.z = offset->z + v14.z;
    v13 = v14;
    if ( value < 0x8000 )
    {
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: ta,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)value,
        origin: &v13,
        axis: v15);
      v11 = (float)(offset->y + v13.y);
      v12 = (float)(offset->z + v13.z);
      v13.x = offset->x + v13.x;
      v13.y = v11;
      v13.z = v12;
    }
    return idMeleeTrace::Update(this, owner, curPos: &v14, curPos2: &v13, pastUpdate: false);
  }
  else
  {
    this->numSamples = 0;
    return 0;
  }
}


// ========================================================================
// ?UpdateTag@idMeleeTrace@@QAA_NPAVidAnimatedEntity@@PBVidTreeAnimator@@1ABVidVec3@@@Z
// EA  : 0x82ECE238
// RVA : 0x00ECE238
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

int __fastcall idMeleeTrace::UpdateTag(
        idMeleeTrace *this,
        idAI2 *owner,
        idTreeAnimator *ta,
        idTreeAnimator *ta2,
        const idVec3 *offset)
{
  const idDeclMD6 *decl; // r11
  BOOL useDeferredPosition; // r10
  idRenderModelParms *p_deferredOrigin; // r11
  float y; // r8
  float z; // r7
  idMat3 *p_deferredAxis; // r11
  char *v16; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  unsigned int value; // r11
  double v20; // fp6
  double v21; // fp7
  double v22; // fp6
  idVec3 v23; // [sp+50h] [-70h] BYREF
  idVec3 v24; // [sp+60h] [-60h] BYREF
  char v25; // [sp+6Ch] [-54h] BYREF
  idMat3 v26[2]; // [sp+70h] [-50h] BYREF

  if ( ta != nullptr && (decl = ta->decl) != nullptr && decl != (const idDeclMD6 *)-352 )
  {
    useDeferredPosition = ta->useDeferredPosition;
    p_deferredOrigin = (idRenderModelParms *)&ta->deferredOrigin;
    if ( !ta->useDeferredPosition )
      p_deferredOrigin = &ta->g;
    y = p_deferredOrigin->origin.y;
    z = p_deferredOrigin->origin.z;
    v23.x = p_deferredOrigin->origin.x;
    p_deferredAxis = &ta->deferredAxis;
    v23.y = y;
    v23.z = z;
    if ( !useDeferredPosition )
      p_deferredAxis = &ta->g.axis;
    v16 = &v25;
    p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
    {
      ++p_z;
      v16 += 4;
      *(_DWORD *)v16 = *p_z;
    }
    if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(
                            this: ta,
                            tagData: &this->tagData,
                            origin: &v23,
                            axis: v26) != 0 )
    {
      value = (unsigned __int16)this->jointIndex2.value;
      v20 = (float)(offset->x + v23.x);
      v23.y = offset->y + v23.y;
      v23.x = v20;
      v23.z = offset->z + v23.z;
      v24 = v23;
      if ( value < 0x8000 && ta2 != nullptr )
      {
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: ta2,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)value,
          origin: &v24,
          axis: v26);
        v21 = (float)(offset->y + v24.y);
        v22 = (float)(offset->z + v24.z);
        v24.x = offset->x + v24.x;
        v24.y = v21;
        v24.z = v22;
      }
      return idMeleeTrace::Update(this, owner, curPos: &v23, curPos2: &v24, pastUpdate: false);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    this->numSamples = 0;
    return 0;
  }
}


// ========================================================================
// ?PastUpdate@idMeleeTrace@@QAA_NPAVidActor@@ABVidVec3@@@Z
// EA  : 0x82ECE3D0
// RVA : 0x00ECE3D0
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

int __fastcall idMeleeTrace::PastUpdate(idMeleeTrace *this, idAI2 *owner, const idVec3 *pastPos)
{
  float x; // r10
  float y; // r9
  float z; // r8
  double v6; // fp12
  idVec3 v8[2]; // [sp+50h] [-20h] BYREF

  x = this->prevPos.x;
  y = this->prevPos.y;
  z = this->prevPos.z;
  this->prevPos.x = pastPos->x;
  this->prevPos.y = pastPos->y;
  v6 = pastPos->z;
  v8[0].x = x;
  this->prevPos.z = v6;
  v8[0].y = y;
  v8[0].z = z;
  return idMeleeTrace::Update(this, owner, curPos: v8, curPos2: v8, pastUpdate: true);
}


// ========================================================================
// ?Update@idMeleeTrace@@QAA_NPAVidPresentable@@ABVidVec3@@1_N@Z
// EA  : 0x82ECE438
// RVA : 0x00ECE438
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

int __fastcall idMeleeTrace::Update(
        idMeleeTrace *this,
        idPresentable *owner,
        const idVec3 *curPos,
        const idVec3 *curPos2,
        bool pastUpdate)
{
  int v10; // r19
  int result; // r3
  int numSamples; // r11
  int boundsType; // r10
  idVec3 *p_prevPos; // r28
  unsigned int v15; // r10
  idClipModel *clip16x16; // r30
  int v17; // r26
  int meleeType; // r11
  int entityNum; // r10
  idRenderWorld *v20; // r3
  idRenderWorld *v21; // r3
  int GameMs; // r3
  idDeclProjectileImpactEffect *impactEffect; // r11
  const idDeclProjectileImpactEffect::projectileImpactEffect_t *ImpactEffectForMaterial; // r7
  __int64 v25; // r4
  __int64 v26; // r6
  idRenderWorld *v27; // r3
  idRenderWorld *v28; // r3
  const idDeclDamage *damageDef; // r30
  int v30; // r29
  idPresentablePlayer *v31; // r3
  idRenderWorld *v32; // r3
  idRenderWorld *v33; // r3
  idRenderWorld *v34; // r3
  const idPresentable *v35; // [sp+8h] [-218h]
  idPresentable *v36; // [sp+Ch] [-214h]
  char *v37; // [sp+10h] [-210h]
  int v38; // [sp+14h] [-20Ch]
  int v39; // [sp+18h] [-208h]
  int v40; // [sp+1Ch] [-204h]
  int v41; // [sp+20h] [-200h]
  int v42; // [sp+24h] [-1FCh]
  int v43; // [sp+28h] [-1F8h]
  int v44; // [sp+2Ch] [-1F4h]
  int v45; // [sp+30h] [-1F0h]
  int v46; // [sp+34h] [-1ECh]
  int v47; // [sp+38h] [-1E8h]
  int v48; // [sp+3Ch] [-1E4h]
  int v49; // [sp+40h] [-1E0h]
  int v50; // [sp+44h] [-1DCh]
  int v51; // [sp+48h] [-1D8h]
  int v52; // [sp+4Ch] [-1D4h]
  int v53; // [sp+50h] [-1D0h]
  int v54; // [sp+58h] [-1C8h]
  int v55; // [sp+60h] [-1C0h]
  __int64 v56; // [sp+78h] [-1A8h] BYREF
  idColor v57; // [sp+80h] [-1A0h] BYREF
  trace_t v58; // [sp+90h] [-190h] BYREF
  idClientGameMsg_MeleeHit v59; // [sp+110h] [-110h] BYREF

  v10 = 0;
  if ( owner == nullptr )
    return 0;
  numSamples = this->numSamples;
  if ( numSamples <= 0 )
    return 0;
  boundsType = this->boundsType;
  this->numSamples = numSamples - 1;
  if ( boundsType != 0 )
  {
    v15 = boundsType - 1;
    clip16x16 = nullptr;
    v17 = 8467589;
    if ( v15 <= 7 )
    {
      switch ( v15 )
      {
        case 1u:
          clip16x16 = clientGame->clip.clip16x16;
          break;
        case 2u:
          clip16x16 = clientGame->clip.clip24x24;
          break;
        case 3u:
          clip16x16 = clientGame->clip.clip32x32;
          break;
        case 4u:
          clip16x16 = clientGame->clip.clip48x48;
          break;
        case 5u:
          clip16x16 = clientGame->clip.clip96x96;
          break;
        case 6u:
          clip16x16 = clientGame->clip.playerMeleeClipModel;
          v17 = 8462469;
          break;
        default:
          if ( v15 != 0 )
            clip16x16 = this->clipModel;
          else
            clip16x16 = clientGame->clip.clip8x8;
          break;
      }
    }
    p_prevPos = &this->prevPos;
    idClip::Translation(
      this: (idClip *)&v56,
      result: &clientGame->clip,
      a3: &v58,
      start: &this->prevPos,
      end: curPos,
      clipModel: clip16x16,
      startAxis: &mat3_identity,
      clipMask: v17,
      passEntityNumber: (int)v35,
      moveClipModel: (bool)v36,
      userName: v37,
      a12: v38,
      a13: v39,
      a14: v40,
      a15: v41,
      a16: v42,
      a17: v43,
      a18: v44,
      a19: v45,
      a20: v46,
      a21: v47,
      a22: v48,
      a23: v49,
      a24: v50,
      a25: v51,
      a26: v52,
      a27: v53,
      a28: owner->entityNumber,
      a29: v54,
      a30: false,
      a31: v55,
      a32: 0);
    if ( v58.fraction != 1.0 )
      goto LABEL_26;
    if ( (unsigned __int16)this->jointIndex2.value < 0x8000u )
      idClip::Translation(
        this: (idClip *)&v56,
        result: &clientGame->clip,
        a3: &v58,
        start: curPos2,
        end: curPos,
        clipModel: clip16x16,
        startAxis: &mat3_identity,
        clipMask: v17,
        passEntityNumber: (int)v35,
        moveClipModel: (bool)v36,
        userName: v37,
        a12: v38,
        a13: v39,
        a14: v40,
        a15: v41,
        a16: v42,
        a17: v43,
        a18: v44,
        a19: v45,
        a20: v46,
        a21: v47,
        a22: v48,
        a23: v49,
        a24: v50,
        a25: v51,
        a26: v52,
        a27: v53,
        a28: owner->entityNumber,
        a29: v54,
        a30: false,
        a31: v55,
        a32: 0);
  }
  else
  {
    p_prevPos = &this->prevPos;
    idClip::TracePoint(
      this: &clientGame->clip,
      result: &v58,
      start: &this->prevPos,
      end: curPos,
      clipMask: 8462469,
      passEntityNumber: owner->entityNumber);
  }
  if ( v58.fraction == 1.0 )
  {
    if ( g_debugMeleeTraces.valueInteger != 0 )
    {
      v34 = gameLocal->GetRenderWorld(this: gameLocal);
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, const idVec3 *, double))v34->DebugArrow)(
        a1: v34,
        a2: &idColor::colorGreen,
        a3: p_prevPos,
        a4: curPos,
        a5: 4.0);
    }
    goto LABEL_52;
  }
LABEL_26:
  meleeType = this->meleeType;
  entityNum = v58.c.entityNum;
  if ( meleeType != 2 )
    goto LABEL_34;
  if ( v58.c.entityNum != 0x1FFF )
  {
    if ( this->hasHit && !pastUpdate )
    {
      if ( g_debugMeleeTraces.valueInteger != 0 )
      {
        v20 = gameLocal->GetRenderWorld(this: gameLocal);
        ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))v20->DebugArrow)(
          a1: v20,
          a2: &idColor::colorYellow,
          a3: p_prevPos,
          a4: &v58.endpos,
          a5: 4.0);
        v21 = gameLocal->GetRenderWorld(this: gameLocal);
        v21->DebugPoint(this: v21, a2: (const idVec4 *)&idColor::colorYellow, a3: &v58.c.point, a4: 4000, a5: true);
      }
      goto LABEL_32;
    }
    this->numSamples = 0;
LABEL_34:
    if ( entityNum != 0x1FFF && meleeType == 1 )
    {
LABEL_37:
      this->numSamples = 0;
LABEL_38:
      this->hasHit = true;
      if ( entityNum != 0x1FFF )
      {
        v10 = 1;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        impactEffect = this->impactEffect;
        this->lastHitTime = GameMs;
        if ( impactEffect != nullptr )
        {
          ImpactEffectForMaterial = idDeclProjectileImpactEffect::GetImpactEffectForMaterial(
                                      this: impactEffect,
                                      materialID: v58.c.surfaceType);
          if ( ImpactEffectForMaterial != nullptr )
          {
            LODWORD(v25) = v58.c.surfaceColor[1];
            v57.a = 1.0;
            LODWORD(v26) = v58.c.surfaceColor[2];
            HIDWORD(v25) = clientGame;
            HIDWORD(v26) = &v58.c.normal;
            v56 = v58.c.surfaceColor[0];
            v57.g = (float)v25 * (float)0.0039215689;
            v57.b = (float)v26 * (float)0.0039215689;
            v57.r = (float)v58.c.surfaceColor[0] * (float)0.0039215689;
            idClientGame::ImpactEffect(
              this: clientGame,
              point: (const idMat3 *)&v58.c.point,
              normal: (idMat3 *)&v58.c.normal,
              color: &v57,
              effect: ImpactEffectForMaterial,
              skipParticle: false,
              noDecals: false,
              noSounds: false,
              owner: v35,
              entity: v36,
              jointId: (idIndex<short,enum invalidJointIndex_t> *)v37,
              a12: v38,
              a13: v39,
              a14: v40,
              a15: v41,
              a16: v42,
              a17: v43,
              a18: v44,
              a19: v45,
              a20: v46,
              a21: v47,
              a22: v48,
              a23: v49,
              a24: v50,
              a25: v51,
              a26: v52,
              a27: v53,
              a28: 0,
              a29: v54,
              a30: 0,
              a31: v55,
              a32: NULL_JOINT_INDEX.value);
          }
        }
        if ( g_debugMeleeTraces.valueInteger != 0 )
        {
          v27 = gameLocal->GetRenderWorld(this: gameLocal);
          ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))v27->DebugArrow)(
            a1: v27,
            a2: &idColor::colorRed,
            a3: p_prevPos,
            a4: &v58.endpos,
            a5: 4.0);
          v28 = gameLocal->GetRenderWorld(this: gameLocal);
          v28->DebugPoint(this: v28, a2: (const idVec4 *)&idColor::colorRed, a3: &v58.c.point, a4: 4000, a5: true);
        }
        if ( v58.c.entityNum != 8190 && owner->GetPlayerInterface_2(this: owner) != nullptr )
        {
          damageDef = this->damageDef;
          v30 = v58.c.entityNum;
          v31 = owner->GetPlayerInterface_2(this: owner);
          idClientGameMsg_MeleeHit::idClientGameMsg_MeleeHit(
            this: &v59,
            instigator_: v31,
            hitEntityNum_: v30,
            damageDecl_: damageDef,
            trace_: &v58);
          idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v59);
        }
      }
LABEL_52:
      result = v10;
      goto LABEL_53;
    }
LABEL_36:
    if ( meleeType != 0 )
      goto LABEL_38;
    goto LABEL_37;
  }
  if ( !this->hasHit )
    goto LABEL_36;
  if ( g_debugMeleeTraces.valueInteger != 0 )
  {
    v32 = gameLocal->GetRenderWorld(this: gameLocal);
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))v32->DebugArrow)(
      a1: v32,
      a2: &idColor::colorWhite,
      a3: p_prevPos,
      a4: &v58.endpos,
      a5: 4.0);
    v33 = gameLocal->GetRenderWorld(this: gameLocal);
    v33->DebugPoint(this: v33, a2: (const idVec4 *)&idColor::colorWhite, a3: &v58.c.point, a4: 4000, a5: true);
    result = 0;
    goto LABEL_53;
  }
LABEL_32:
  result = 0;
LABEL_53:
  p_prevPos->x = curPos->x;
  p_prevPos->y = curPos->y;
  p_prevPos->z = curPos->z;
  return result;
}


// ========================================================================
// __unwind$488695_0
// EA  : 0x82ECE9E8
// RVA : 0x00ECE9E8
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void _unwind_488695_0()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 544 + 272));
}


// ========================================================================
// ?Update@idMeleeTrace@@QAAXPAVidAnimatedEntity@@@Z
// EA  : 0x82ECEA10
// RVA : 0x00ECEA10
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void __fastcall idMeleeTrace::Update(idMeleeTrace *this, idAI2 *owner)
{
  idActor *v4; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  idTreeAnimator *v6; // r3
  idTreeAnimator *v7; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v9; // r30
  unsigned int value; // r8
  idVec3 v11; // [sp+50h] [-70h] BYREF
  idVec3 v12; // [sp+60h] [-60h] BYREF
  idMat3 v13[2]; // [sp+70h] [-50h] BYREF

  if ( this->useTagData )
  {
    v4 = idActor::CastTo(c: owner);
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: owner);
    if ( v4 != nullptr && this->useWeaponAnimator )
      TreeAnimatorFromPresentable = idActor::GetEquippedWeaponAnimator(this: v4);
    v6 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: owner);
    idMeleeTrace::UpdateTag(this, owner, ta: TreeAnimatorFromPresentable, ta2: v6, offset: &vec3_origin);
  }
  else
  {
    if ( owner == nullptr )
      goto LABEL_7;
    v7 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: owner);
    presentable = owner->presentable;
    v9 = v7;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: owner);
      presentable = owner->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( (unsigned __int16)this->jointIndex.value < 0x8000u )
    {
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: v9,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointIndex.value,
        origin: &v12,
        axis: v13);
      value = (unsigned __int16)this->jointIndex2.value;
      v11 = v12;
      if ( value < 0x8000 )
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v9,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)value,
          origin: &v11,
          axis: v13);
      idMeleeTrace::Update(this, owner, curPos: &v12, curPos2: &v11, pastUpdate: false);
    }
    else
    {
LABEL_7:
      this->numSamples = 0;
    }
  }
}


// ========================================================================
// ?Update@idMeleeTrace@@QAA_NPAVidPresentable@@PBVidTreeAnimator@@ABVidVec3@@@Z
// EA  : 0x82ECEB58
// RVA : 0x00ECEB58
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

int __fastcall idMeleeTrace::Update(idMeleeTrace *this, idPresentable *owner, idTreeAnimator *ta, const idVec3 *offset)
{
  unsigned int value; // r11
  double v10; // fp6
  double v11; // fp7
  double v12; // fp6
  idVec3 v13; // [sp+50h] [-70h] BYREF
  idVec3 v14; // [sp+60h] [-60h] BYREF
  idMat3 v15[2]; // [sp+70h] [-50h] BYREF

  if ( (unsigned __int16)this->jointIndex.value < 0x8000u )
  {
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: ta,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointIndex.value,
      origin: &v14,
      axis: v15);
    value = (unsigned __int16)this->jointIndex2.value;
    v10 = (float)(offset->y + v14.y);
    v14.x = offset->x + v14.x;
    v14.y = v10;
    v14.z = offset->z + v14.z;
    v13 = v14;
    if ( value < 0x8000 )
    {
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: ta,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)value,
        origin: &v13,
        axis: v15);
      v11 = (float)(offset->y + v13.y);
      v12 = (float)(offset->z + v13.z);
      v13.x = offset->x + v13.x;
      v13.y = v11;
      v13.z = v12;
    }
    return idMeleeTrace::Update(this, owner, curPos: &v14, curPos2: &v13, pastUpdate: false);
  }
  else
  {
    this->numSamples = 0;
    return 0;
  }
}


// ========================================================================
// ?UpdateTag@idMeleeTrace@@QAA_NPAVidPresentable@@PBVidTreeAnimator@@1ABVidVec3@@@Z
// EA  : 0x82ECEC68
// RVA : 0x00ECEC68
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

int __fastcall idMeleeTrace::UpdateTag(
        idMeleeTrace *this,
        idPresentable *owner,
        idTreeAnimator *ta,
        idTreeAnimator *ta2,
        const idVec3 *offset)
{
  const idDeclMD6 *decl; // r11
  BOOL useDeferredPosition; // r10
  idRenderModelParms *p_deferredOrigin; // r11
  float y; // r8
  float z; // r7
  idMat3 *p_deferredAxis; // r11
  char *v16; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  unsigned int value; // r11
  double v20; // fp6
  double v21; // fp7
  double v22; // fp6
  idVec3 v23; // [sp+50h] [-70h] BYREF
  idVec3 v24; // [sp+60h] [-60h] BYREF
  char v25; // [sp+6Ch] [-54h] BYREF
  idMat3 v26[2]; // [sp+70h] [-50h] BYREF

  if ( ta != nullptr && (decl = ta->decl) != nullptr && decl != (const idDeclMD6 *)-352 )
  {
    useDeferredPosition = ta->useDeferredPosition;
    p_deferredOrigin = (idRenderModelParms *)&ta->deferredOrigin;
    if ( !ta->useDeferredPosition )
      p_deferredOrigin = &ta->g;
    y = p_deferredOrigin->origin.y;
    z = p_deferredOrigin->origin.z;
    v23.x = p_deferredOrigin->origin.x;
    p_deferredAxis = &ta->deferredAxis;
    v23.y = y;
    v23.z = z;
    if ( !useDeferredPosition )
      p_deferredAxis = &ta->g.axis;
    v16 = &v25;
    p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
    {
      ++p_z;
      v16 += 4;
      *(_DWORD *)v16 = *p_z;
    }
    if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(
                            this: ta,
                            tagData: &this->tagData,
                            origin: &v23,
                            axis: v26) != 0 )
    {
      value = (unsigned __int16)this->jointIndex2.value;
      v20 = (float)(offset->x + v23.x);
      v23.y = offset->y + v23.y;
      v23.x = v20;
      v23.z = offset->z + v23.z;
      v24 = v23;
      if ( value < 0x8000 && ta2 != nullptr )
      {
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: ta2,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)value,
          origin: &v24,
          axis: v26);
        v21 = (float)(offset->y + v24.y);
        v22 = (float)(offset->z + v24.z);
        v24.x = offset->x + v24.x;
        v24.y = v21;
        v24.z = v22;
      }
      return idMeleeTrace::Update(this, owner, curPos: &v23, curPos2: &v24, pastUpdate: false);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    this->numSamples = 0;
    return 0;
  }
}


// ========================================================================
// ?PastUpdate@idMeleeTrace@@QAA_NPAVidPresentable@@ABVidVec3@@@Z
// EA  : 0x82ECEE00
// RVA : 0x00ECEE00
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

int __fastcall idMeleeTrace::PastUpdate(idMeleeTrace *this, idPresentable *owner, const idVec3 *pastPos)
{
  float x; // r10
  float y; // r9
  float z; // r8
  double v6; // fp12
  idVec3 v8[2]; // [sp+50h] [-20h] BYREF

  x = this->prevPos.x;
  y = this->prevPos.y;
  z = this->prevPos.z;
  this->prevPos.x = pastPos->x;
  this->prevPos.y = pastPos->y;
  v6 = pastPos->z;
  v8[0].x = x;
  this->prevPos.z = v6;
  v8[0].y = y;
  v8[0].z = z;
  return idMeleeTrace::Update(this, owner, curPos: v8, curPos2: v8, pastUpdate: true);
}


// ========================================================================
// `dynamic initializer for 'g_debugMeleeTraces''
// EA  : 0x83393820
// RVA : 0x01393820
// PDB : w:\tech5\tungsten\game\weapons\meleetrace.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugMeleeTraces__()
{
  idCVar::idCVar(
    this: &g_debugMeleeTraces,
    name: "g_debugMeleeTraces",
    value: "0",
    flags: 2,
    description: "1 = show melee traces. 2 = show melee traces and bounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugMeleeTraces__);
}

