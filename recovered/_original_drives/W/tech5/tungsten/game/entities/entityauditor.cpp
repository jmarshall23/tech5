
// ========================================================================
// ??1idPlayerAuditor@@UAA@XZ
// EA  : 0x82C46FB0
// RVA : 0x00C46FB0
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void __fastcall idPlayerAuditor::~idPlayerAuditor(idPlayerAuditor *this)
{
  this->__vftable = (idPlayerAuditor_vtbl *)&idEntityAuditor::`vftable';
}


// ========================================================================
// ?Clear@idPlayerAuditor@@UAAXXZ
// EA  : 0x82C46FC0
// RVA : 0x00C46FC0
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void __fastcall idPlayerAuditor::Clear(idPlayerAuditor *this)
{
  this->positions.num = 0;
  this->positions.head = 0;
  this->viewdirs.num = 0;
  this->viewdirs.head = 0;
  this->waitTime = -1;
  this->nearCoverIndex = -1;
  this->nearCoverTime = -1;
  this->lastFireTime = -1;
  this->lastOutsideAssaultHint = -1;
  this->lastOutsideGrenadeHint = -1;
}


// ========================================================================
// ??0idAuditResults@@QAA@XZ
// EA  : 0x82C470A0
// RVA : 0x00C470A0
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

idAuditResults *__fastcall idAuditResults::idAuditResults(idAuditResults *this)
{
  this->movement = AUDITMOVEMENT_UNKNOWN;
  this->inCover = false;
  this->timeSinceSensed = -1;
  this->shouldGrenade = false;
  this->assaultPrimitiveBreached = false;
  this->recentPointSensed.z = 0.0;
  this->recentPointSensed.y = 0.0;
  this->recentPointSensed.x = 0.0;
  this->anyMemberMoved = false;
  return this;
}


// ========================================================================
// ??0idPlayerAuditor@@QAA@XZ
// EA  : 0x82C470D8
// RVA : 0x00C470D8
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

idPlayerAuditor *__fastcall idPlayerAuditor::idPlayerAuditor(idPlayerAuditor *this)
{
  this->nextSampleTime = -1;
  this->__vftable = (idPlayerAuditor_vtbl *)&idPlayerAuditor::`vftable';
  this->positions.num = 0;
  this->positions.head = 0;
  memset(Dst: &this->positions, Val: 0, Size: 0x3Cu);
  this->viewdirs.num = 0;
  this->viewdirs.head = 0;
  memset(Dst: &this->viewdirs, Val: 0, Size: 0x3Cu);
  this->waitPosition.x = 0.0;
  this->waitPosition.y = 0.0;
  this->waitPosition.z = 0.0;
  this->waitTime = -1;
  this->nearCoverIndex = -1;
  this->nearCoverTime = -1;
  this->lastFireTime = -1;
  this->lastOutsideGrenadeHint = -1;
  this->lastOutsideAssaultHint = -1;
  this->currentGrenadeHint = -1;
  return this;
}


// ========================================================================
// ?CollectData@idPlayerAuditor@@UAAXPBVidEntity@@H@Z
// EA  : 0x82C47178
// RVA : 0x00C47178
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void __fastcall idPlayerAuditor::CollectData(idPlayerAuditor *this, idPlayer *subject, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idPlayer *v8; // r21
  idPhysics *Physics; // r3
  const idVec3 *v10; // r25
  idPresentable *presentable; // r3
  int v12; // r11
  double v13; // fp0
  double v14; // fp13
  double v15; // fp12
  idPhysics *v16; // r3
  const idBounds *v17; // r24
  idAAS2 *v18; // r27
  int v19; // r29
  double v20; // fp30
  idAAS2 *AAS; // r3
  idAAS2 *v22; // r30
  int v23; // r3
  idAAS2Settings *v24; // r28
  double Volume; // fp31
  unsigned __int64 v26; // r6
  const char *v27; // r7
  idAASPosition *AASPosition; // r3
  idAAS2 v29; // r30
  idVec3 *p_origin; // r29
  int AreaNum; // r3
  int buttons; // r11
  idPLogScope v33; // [sp+68h] [-C8h] BYREF
  idPLogScope v34[4]; // [sp+70h] [-C0h] BYREF
  int v35; // [sp+90h] [-A0h] BYREF

  RD_EventBegin(name: "idPlayerAuditor::CollectData");
  LODWORD(v6) = "idPlayerAuditor::CollectData";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v33, pl: &pLog, gMask: v6, label: v7);
  if ( gameLocal != nullptr && gameLocal->world != nullptr && this->nextSampleTime <= curTime )
  {
    this->nextSampleTime = curTime + 500;
    if ( gameLocal->world->mapType != MAPTYPE_TOWN )
    {
      v8 = idPlayer::CastTo(c: subject);
      if ( v8 != nullptr )
      {
        Physics = idEntity::GetPhysics(this: subject);
        v10 = Physics->GetOrigin(this: Physics, a2: 0);
        idCircularBuffer<idVec3,5>::Add(this: &this->positions, obj: v10);
        presentable = v8->presentable;
        if ( presentable != nullptr )
          v12 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v12 = 0;
        idCircularBuffer<idVec3,5>::Add(this: &this->viewdirs, obj: (const idVec3 *)(v12 + 46544));
        if ( this->waitTime < 0
          || (v13 = (float)(v10->z - this->waitPosition.z),
              v14 = (float)(v10->y - this->waitPosition.y),
              v15 = (float)(v10->x - this->waitPosition.x),
              __fsqrts((float)((float)((float)v13 * (float)v13)
                             + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))) > 256.0) )
        {
          this->waitPosition.x = v10->x;
          this->waitPosition.y = v10->y;
          this->waitPosition.z = v10->z;
          this->waitTime = curTime;
        }
        v16 = idEntity::GetPhysics(this: subject);
        v17 = v16->GetBounds(this: v16, a2: -1);
        v18 = nullptr;
        v19 = 0;
        v20 = 3.4028235e38;
        if ( idGameLocal::NumAAS(this: gameLocal) > 0 )
        {
          do
          {
            AAS = idGameLocal::GetAAS(this: gameLocal, idx: v19);
            v22 = AAS;
            if ( AAS != nullptr && !AAS->IsDefault(this: AAS) )
            {
              v23 = (int)v22->GetSettings(this: v22);
              v24 = (idAAS2Settings *)v23;
              if ( v23 != 0 )
              {
                Volume = idBounds::GetVolume(this: (idBounds *)(v23 + 100));
                if ( (unsigned __int8)idAAS2Settings::ValidForBounds(this: v24, bounds: v17) != 0 && Volume < v20 )
                {
                  v20 = Volume;
                  v18 = v22;
                }
              }
            }
            ++v19;
          }
          while ( v19 < idGameLocal::NumAAS(this: gameLocal) );
          if ( v18 != nullptr )
          {
            RD_EventBegin(name: "idPlayerAuditor::CollectData - aas");
            LODWORD(v26) = "idPlayerAuditor::CollectData - aas";
            HIDWORD(v26) = 2;
            idPLogScope::idPLogScope(this: v34, pl: &pLog, gMask: v26, label: v27);
            AASPosition = (idAASPosition *)idActor::GetAASPosition(this: v8, aas: v18);
            v29.__vftable = v18->__vftable;
            p_origin = &AASPosition->origin;
            AreaNum = idAASPosition::GetAreaNum(this: AASPosition);
            ((void (__fastcall *)(idAAS2 *, int, idVec3 *, int (__fastcall *)(idAAS2 *, const int, const idVec3 *, const float, const int, const int, const int, int *, const int, int *), _DWORD, _DWORD, int, int *, double))v29.FindCoverPoints)(
              a1: v18,
              a2: AreaNum,
              a3: p_origin,
              a4: v29.FindCoverPoints,
              a5: 0,
              a6: 0,
              a7: 32,
              a8: &v35,
              a9: 96.0);
            if ( this->nearCoverIndex == -1 )
            {
              this->nearCoverIndex = -1;
              this->nearCoverTime = -1;
            }
            else
            {
              this->nearCoverTime = curTime;
              this->nearCoverIndex = -1;
            }
            idPLogScope::~idPLogScope(this: v34);
            RD_EventEnd();
          }
        }
        buttons = idPlayer::GetUCmdTracker2(this: v8)->usercmd.buttons;
        if ( (buttons & 1) != 0 || (buttons & 2) != 0 )
          this->lastFireTime = curTime;
      }
    }
  }
  idPLogScope::~idPLogScope(this: &v33);
  RD_EventEnd();
}


// ========================================================================
// __unwind$488827
// EA  : 0x82C475B4
// RVA : 0x00C475B4
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void _unwind_488827()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 304 + 176));
}


// ========================================================================
// __unwind$488828
// EA  : 0x82C475DC
// RVA : 0x00C475DC
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void _unwind_488828()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 304 + 104));
}


// ========================================================================
// __unwind$488829
// EA  : 0x82C47604
// RVA : 0x00C47604
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void _unwind_488829()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 304 + 177));
}


// ========================================================================
// __unwind$488830
// EA  : 0x82C4762C
// RVA : 0x00C4762C
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void _unwind_488830()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$488831
// EA  : 0x82C47654
// RVA : 0x00C47654
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void _unwind_488831()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 304 + 120));
}


// ========================================================================
// ?Audit@idPlayerAuditor@@UAAXPAVidEncounterGroup@@PBVidEntity@@HAAVidAuditResults@@@Z
// EA  : 0x82C47688
// RVA : 0x00C47688
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void __fastcall idPlayerAuditor::Audit(
        idPlayerAuditor *this,
        idEncounterGroup *group,
        const idEntity *subject,
        int curTime,
        idAuditResults *results)
{
  idPlayerAuditor *v5; // r14
  idEncounterGroup *v6; // r25
  const idEntity *v7; // r18
  idAuditResults *v9; // r21
  unsigned __int64 v10; // r6
  const char *v11; // r7
  int v12; // r15
  int v13; // r28
  int v14; // r3
  char v15; // r24
  int v16; // r27
  int v17; // r26
  idAI2 *v18; // r29
  idAIEntityState *v19; // r3
  aiSenseState_t *v20; // r30
  int lastConfirmedStimTime; // r11
  idPhysics *Physics; // r3
  float *v23; // r3
  double v24; // fp7
  double x; // fp10
  double v26; // fp6
  double v27; // fp3
  int waitTime; // r11
  int v29; // r26
  double v30; // fp13
  int v31; // r3
  int num; // r27
  int head; // r30
  float *v34; // r29
  float *v35; // r11
  idCircularBuffer<idVec3,5> *p_positions; // r4
  double v37; // fp11
  double z; // fp10
  double y; // fp9
  float *p_x; // r10
  float *v41; // r9
  double v42; // fp1
  double v43; // fp6
  double v44; // fp3
  char v45; // r10
  double v46; // fp4
  double v47; // fp5
  double v48; // fp3
  double v49; // fp0
  int v50; // r11
  int v51; // r16
  double v52; // fp29
  int v53; // r22
  int v54; // r21
  int v55; // r26
  idAI2 *v56; // r25
  float *v57; // r29
  idPhysics *v58; // r3
  float *v59; // r30
  float *v60; // r3
  double v61; // fp8
  double v62; // fp4
  double v65; // fp12
  double v66; // fp9
  double v67; // fp5
  double v68; // fp11
  double v69; // fp9
  double v70; // fp0
  unsigned int v71; // r7
  int GameMs; // r3
  __int64 v73; // r10
  double v74; // fp13
  double v75; // fp0
  int v76; // r11
  int curCombatStage; // r11
  char v78; // r19
  int delay; // r20
  char v80; // r23
  int v81; // r22
  idEncounterGroup *v82; // r16
  idCombatStage *v83; // r25
  int value; // r10
  idAIHintGroup *v85; // r3
  int v86; // r28
  int v87; // r29
  int v88; // r9
  idGameLocal *v89; // r11
  int *list; // r30
  idAIHintGroup *v91; // r3
  idAIHintGroup *v92; // r3
  int v93; // r26
  int v94; // r29
  int v95; // r30
  int v96; // r10
  int v97; // r9
  idEntity *v98; // r3
  idAIHint *v99; // r3
  idAICombatHint *v100; // r3
  idAICombatHint *v101; // r3
  idAICombatHint *v102; // r30
  int v103; // r28
  int v104; // r29
  int v105; // r9
  idGameLocal *v106; // r11
  int *v107; // r30
  idAIHintGroup *v108; // r3
  idAIHintGroup *v109; // r3
  int v110; // r10
  int v111; // r9
  idEntity *v112; // r3
  idAIHint *v113; // r3
  idAICombatHint *v114; // r3
  idAICombatHint *v115; // r3
  idAICombatHint *v116; // r27
  int lastOutsideGrenadeHint; // r11
  int nextGrenadeTime; // r30
  char v119; // r28
  int v120; // r29
  int v121; // r30
  idPhysics *v122; // r3
  float *v123; // r23
  idPhysics *v124; // r3
  float *v125; // r3
  double v126; // fp10
  double v127; // fp4
  idPLog *pLog; // r29
  idPLog::logEntry_t *v129; // r30
  int v130; // r3
  __int64 totalTicks; // r11
  __int64 v132; // r9
  char v133; // [sp+50h] [-350h]
  int v134; // [sp+58h] [-348h]
  int v135; // [sp+60h] [-340h]
  int v136; // [sp+68h] [-338h]
  int v137; // [sp+6Ch] [-334h] BYREF
  unsigned __int64 v138; // [sp+70h] [-330h]
  idPLogScope v139; // [sp+80h] [-320h] BYREF
  idStaticList<idAI2 *,64> v140; // [sp+90h] [-310h] BYREF
  idStaticList<idAI2 *,64> v141; // [sp+1A0h] [-200h] BYREF
  int v142; // [sp+2B4h] [-ECh] BYREF

  this->nextSampleTime = curTime + 450;
  v5 = this;
  v6 = group;
  v7 = subject;
  v9 = results;
  RD_EventBegin(name: "idPlayerAuditor::Audit");
  LODWORD(v10) = "idPlayerAuditor::Audit";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: &v139, pl: &::pLog, gMask: v10, label: v11);
  v12 = 0;
  v13 = -1;
  v9->movement = AUDITMOVEMENT_UNKNOWN;
  v9->inCover = false;
  v9->timeSinceSensed = -1;
  v9->shouldGrenade = false;
  v9->assaultPrimitiveBreached = false;
  v9->recentPointSensed.z = 0.0;
  v9->recentPointSensed.y = 0.0;
  v9->recentPointSensed.x = 0.0;
  v9->anyMemberMoved = false;
  v14 = idEncounterGroup::NumLivingMembers(this: v6);
  v9->anyMemberMoved = false;
  v140.num = 0;
  v140.granularity = 1;
  v15 = 0;
  v140.size = 64;
  v140.list = v140.staticList;
  v134 = v14;
  v140.memTag = 5;
  v133 = 0;
  v140.listStatic = 1;
  idEncounterGroup::GetLivingMembers(this: v6, list: &v140);
  v16 = 0;
  if ( v140.num <= 0 )
    goto LABEL_12;
  v17 = 0;
  do
  {
    v18 = v140.list[v17];
    v19 = idAIWorldState::StateForEntity(this: &v18->aiVolatile.world.worldState, ent: v7);
    if ( v19 != nullptr && (*((_BYTE *)v19 + 541) & 0x80) != 0 )
    {
      v20 = v19->senses.ptr[v19->lastSense];
      lastConfirmedStimTime = v20->lastConfirmedStimTime;
      if ( lastConfirmedStimTime >= 0 )
      {
        HIDWORD(v138) = v20->lastConfirmedStimTime;
        if ( lastConfirmedStimTime > v13 )
        {
          v13 = lastConfirmedStimTime;
          v15 = 1;
          v9->recentPointSensed = aiSenseState_t::GetConfirmedPhysicalSafe(this: v20)->origin;
          Physics = idEntity::GetPhysics(this: v18);
          v23 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v24 = (float)(v20->aiOrigin.y - v23[1]);
          x = v20->aiOrigin.x;
          v26 = *v23;
          HIDWORD(v138) = &v20->aiOrigin;
          v27 = (float)(v20->aiOrigin.z - v23[2]);
          if ( (float)((float)((float)v27 * (float)v27)
                     + (float)((float)((float)((float)x - (float)v26) * (float)((float)x - (float)v26))
                             + (float)((float)v24 * (float)v24))) > 16384.0 )
            v9->anyMemberMoved = true;
        }
      }
    }
    ++v16;
    ++v17;
  }
  while ( v16 < v140.num );
  v133 = v15;
  if ( v13 <= 0 )
LABEL_12:
    v9->timeSinceSensed = 0;
  else
    v9->timeSinceSensed = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - v13;
  v9->inCover = v5->nearCoverIndex >= 0 && curTime - v5->nearCoverTime > 3000;
  waitTime = v5->waitTime;
  if ( curTime - waitTime > 7500 && waitTime > 0 )
    v9->movement = AUDITMOVEMENT_WAITING;
  if ( !v9->inCover && v9->movement == AUDITMOVEMENT_UNKNOWN )
  {
    v29 = 0;
    v30 = 0.0;
    v135 = 0;
    v31 = 1;
    if ( v5->positions.num > 1 )
    {
      num = v5->positions.num;
      head = v5->positions.head;
      v34 = (float *)&v137;
      v35 = (float *)&v141.staticList[63];
      p_positions = &v5->positions;
      v37 = vec3_origin.x;
      z = vec3_origin.z;
      y = vec3_origin.y;
      do
      {
        p_x = &p_positions->buffer[(head + v31 - 1) % 5].x;
        v41 = &p_positions->buffer[(head + v31) % 5].x;
        v42 = (float)(*v41 - *p_x);
        v43 = (float)(v41[2] - p_x[2]);
        v44 = (float)(v41[1] - p_x[1]);
        v35[1] = *v41 - *p_x;
        v35[2] = v44;
        v35[3] = v43;
        if ( v42 != v37 || v44 != y || (v45 = 1, v43 != z) )
          v45 = 0;
        if ( v45 == 0 )
        {
          ++v29;
          v46 = v35[2];
          v47 = v35[1];
          v48 = v35[3];
          v49 = __fsqrts((float)((float)(v35[3] * v35[3])
                               + (float)((float)((float)v42 * (float)v42) + (float)(v35[2] * v35[2]))));
          *++v34 = v49;
          v30 = (float)((float)v49 + (float)v30);
          v35[1] = (float)v47 * (float)((float)1.0 / (float)v49);
          v35[2] = (float)v46 * (float)((float)1.0 / (float)v49);
          v35 += 3;
          *v35 = (float)v48 * (float)((float)1.0 / (float)v49);
        }
        ++v31;
      }
      while ( v31 < num );
      v135 = v29;
    }
    HIDWORD(v138) = 0;
    v137 = v29;
    v50 = 0;
    v136 = 0;
    v51 = 0;
    v52 = (float)((float)v30 / (float)__SPAIR64__(v140.num, v29));
    if ( v140.num > 0 )
    {
      do
      {
        v53 = 0;
        v54 = 0;
        v55 = 0;
        v56 = v140.list[v12];
        if ( v135 > 0 )
        {
          v57 = (float *)&v142;
          do
          {
            v58 = idEntity::GetPhysics(this: v56);
            v59 = &this->positions.buffer[(this->positions.head + v55) % 5].x;
            v60 = (float *)v58->GetOrigin(this: v58, a2: 0);
            v61 = (float)(v60[1] - v59[1]);
            v62 = (float)(v60[2] - v59[2]);
            _FP7 = (float)((float)((float)((float)v62 * (float)v62)
                                 + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59))
                                         + (float)((float)v61 * (float)v61)))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f0, f7, f9, f0 }
            v65 = __frsqrte(_FP0);
            v66 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65
                                                                                                * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5))
                                                                                        * (float)v65)
                                                                                - (float)1.5)
                                                                * (float)v65)
                                                        * (float)((float)((float)((float)v62 * (float)v62)
                                                                        + (float)((float)((float)(*v60 - *v59)
                                                                                        * (float)(*v60 - *v59))
                                                                                + (float)((float)v61 * (float)v61)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v65
                                                                                        * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61)))
                                                                                                * (float)0.5))
                                                                                * (float)v65)
                                                                        - (float)1.5)
                                                        * (float)v65))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v65
                                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                                + (float)((float)((float)(*v60 - *v59)
                                                                                                * (float)(*v60 - *v59))
                                                                                        + (float)((float)v61 * (float)v61)))
                                                                        * (float)0.5))
                                                        * (float)v65)
                                                - (float)1.5)
                                * (float)v65));
            v67 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5)) * (float)v65) - (float)1.5)
                                                                                                * (float)v65)
                                                                                        * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5)) * (float)v65) - (float)1.5)
                                                                                        * (float)v65))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v65
                                                                                                * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5))
                                                                                        * (float)v65)
                                                                                - (float)1.5)
                                                                * (float)v65))
                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                + (float)((float)((float)(*v60 - *v59)
                                                                                * (float)(*v60 - *v59))
                                                                        + (float)((float)v61 * (float)v61)))
                                                        * (float)0.5))
                                        * (float)v66)
                                - (float)1.5);
            v68 = (float)((float)((float)v67
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5)) * (float)v65)
                                                                                                - (float)1.5)
                                                                                * (float)v65)
                                                                        * (float)((float)((float)((float)v62 * (float)v62)
                                                                                        + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59))
                                                                                                + (float)((float)v61 * (float)v61)))
                                                                                * (float)0.5))
                                                                * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5))
                                                                                                * (float)v65)
                                                                                        - (float)1.5)
                                                                        * (float)v65))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v65
                                                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                                                + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61)))
                                                                                        * (float)0.5))
                                                                        * (float)v65)
                                                                - (float)1.5)
                                                * (float)v65)))
                        * (float)v61);
            v69 = (float)((float)((float)v67
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5)) * (float)v65)
                                                                                                - (float)1.5)
                                                                                * (float)v65)
                                                                        * (float)((float)((float)((float)v62 * (float)v62)
                                                                                        + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59))
                                                                                                + (float)((float)v61 * (float)v61)))
                                                                                * (float)0.5))
                                                                * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5))
                                                                                                * (float)v65)
                                                                                        - (float)1.5)
                                                                        * (float)v65))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v65
                                                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                                                + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61)))
                                                                                        * (float)0.5))
                                                                        * (float)v65)
                                                                - (float)1.5)
                                                * (float)v65)))
                        * (float)(*v60 - *v59));
            v70 = (float)((float)(*(v57 - 1) * (float)v69)
                        + (float)((float)(*v57 * (float)v68)
                                + (float)(v57[1]
                                        * (float)((float)((float)v67
                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5)) * (float)v65) - (float)1.5) * (float)v65)
                                                                                                * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5)) * (float)v65) - (float)1.5)
                                                                                                * (float)v65))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)(*v60 - *v59) * (float)(*v60 - *v59)) + (float)((float)v61 * (float)v61))) * (float)0.5))
                                                                                                * (float)v65)
                                                                                        - (float)1.5)
                                                                        * (float)v65)))
                                                * (float)v62))));
            if ( v70 >= -0.70710677 )
            {
              if ( v70 > 0.70710677 )
                ++v53;
            }
            else
            {
              ++v54;
            }
            ++v55;
            v57 += 3;
          }
          while ( v55 < v135 );
          if ( v53 < 4 )
          {
            if ( v54 >= 4 )
            {
              ++v51;
              v71 = 1664525 * clientGame->random.seed + 1013904223;
              clientGame->random.seed = v71;
              if ( (signed int)(((v71 >> 10) & 0x7FFF) % 0x64) < v56->aiEditable.behaviors.decl->rageBehaviors.tauntRageFleeingEnemyChance )
              {
                GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                idAIMemory::SetWantTauntRageTime(this: &v56->aiVolatile.memory, t: GameMs, debugReason: "enemy fleeing");
              }
            }
          }
          else
          {
            ++v136;
          }
        }
        ++v12;
        ++HIDWORD(v138);
      }
      while ( SHIDWORD(v138) < v140.num );
      v50 = v136;
      v15 = v133;
      v7 = subject;
      v5 = this;
      v9 = results;
      v6 = group;
    }
    HIDWORD(v73) = &idEventDef::eventDefList[3154];
    v138 = __PAIR64__(&pm_walkspeed, v134);
    v74 = (float)(pm_walkspeed.valueFloat * (float)0.75);
    v75 = (float)((float)__SPAIR64__(&pm_walkspeed, v134) * (float)0.5);
    if ( v52 > (float)((float)(pm_walkspeed.valueFloat * (float)0.75) * (float)0.5) )
    {
      LODWORD(v73) = v50;
      if ( (float)v73 > v75 )
      {
        if ( v52 <= v74 )
          v76 = 4;
        else
          v76 = 5;
        goto LABEL_57;
      }
      LODWORD(v73) = v51;
      if ( (float)v73 > v75 && v50 == 0 )
      {
        if ( v52 <= v74 )
        {
          v76 = 2;
LABEL_57:
          v9->movement = v76;
          goto LABEL_58;
        }
        v9->movement = AUDITMOVEMENT_RETREATING;
      }
    }
  }
LABEL_58:
  curCombatStage = v6->curCombatStage;
  v78 = 0;
  delay = 0;
  v80 = 0;
  v81 = 0;
  if ( curCombatStage < 0 || curCombatStage >= v6->combatStages.num )
  {
    v82 = group;
    v83 = nullptr;
LABEL_71:
    v93 = curTime;
    v5->currentGrenadeHint = -1;
    v5->lastOutsideGrenadeHint = curTime;
    goto LABEL_72;
  }
  v82 = group;
  v83 = &group->combatStages.list[curCombatStage];
  if ( v83 == nullptr )
    goto LABEL_71;
  value = v83->hintGroup.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_71;
  v85 = (idAIHintGroup *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v85 == nullptr || idAIHintGroup::CastTo(c: v85) == nullptr || v15 == 0 )
    goto LABEL_71;
  v86 = 0;
  if ( v83->assaultNodes.num > 0 )
  {
    v87 = 0;
    while ( 1 )
    {
      v88 = v83->hintGroup.spawnId.value;
      v89 = gameLocal;
      list = v83->assaultNodes.list;
      if ( gameLocal->spawnIds.ptr[v88 & 0x1FFF] == v88 >> 13
        && (v91 = (idAIHintGroup *)gameLocal->entities.ptr[v88 & 0x1FFF]) != nullptr )
      {
        v92 = idAIHintGroup::CastTo(c: v91);
        v89 = gameLocal;
      }
      else
      {
        v92 = nullptr;
      }
      v96 = list[v87];
      if ( v96 < v92->targets.num
        && (v97 = v92->targets.list[v96].spawnId.value, v89->spawnIds.ptr[v97 & 0x1FFF] == v97 >> 13)
        && (v98 = v89->entities.ptr[v92->targets.list[v96].spawnId.value & 0x1FFF]) != nullptr )
      {
        v99 = (idAIHint *)idEntity::CastTo(c: v98);
      }
      else
      {
        v99 = nullptr;
      }
      v100 = (idAICombatHint *)idAIHint::CastTo(c: v99);
      v101 = idAICombatHint::CastTo(c: v100);
      v102 = v101;
      if ( v101 != nullptr && idAICombatHint::GetEntityWeight(this: v101, ent: v7) > 0.0 )
        break;
      ++v86;
      ++v87;
      if ( v86 >= v83->assaultNodes.num )
        goto LABEL_92;
    }
    delay = v102->delay;
    v78 = 1;
  }
LABEL_92:
  v103 = 0;
  if ( v83->grenadeNodes.num <= 0 )
    goto LABEL_71;
  v104 = 0;
  while ( 1 )
  {
    v105 = v83->hintGroup.spawnId.value;
    v106 = gameLocal;
    v107 = v83->grenadeNodes.list;
    if ( gameLocal->spawnIds.ptr[v105 & 0x1FFF] == v105 >> 13
      && (v108 = (idAIHintGroup *)gameLocal->entities.ptr[v105 & 0x1FFF]) != nullptr )
    {
      v109 = idAIHintGroup::CastTo(c: v108);
      v106 = gameLocal;
    }
    else
    {
      v109 = nullptr;
    }
    v110 = v107[v104];
    if ( v110 < v109->targets.num
      && (v111 = v109->targets.list[v110].spawnId.value, v106->spawnIds.ptr[v111 & 0x1FFF] == v111 >> 13)
      && (v112 = v106->entities.ptr[v109->targets.list[v110].spawnId.value & 0x1FFF]) != nullptr )
    {
      v113 = (idAIHint *)idEntity::CastTo(c: v112);
    }
    else
    {
      v113 = nullptr;
    }
    v114 = (idAICombatHint *)idAIHint::CastTo(c: v113);
    v115 = idAICombatHint::CastTo(c: v114);
    v116 = v115;
    if ( v115 != nullptr && idAICombatHint::GetPointWeight(this: v115, point: &v9->recentPointSensed) > 0.0 )
      break;
    ++v103;
    ++v104;
    if ( v103 >= v83->grenadeNodes.num )
      goto LABEL_110;
  }
  if ( v5->currentGrenadeHint != v103 )
    v5->lastOutsideGrenadeHint = curTime;
  v5->currentGrenadeHint = v103;
  v81 = v116->delay;
  v80 = 1;
LABEL_110:
  if ( v116 == nullptr )
    goto LABEL_71;
  if ( v80 == 0 )
    goto LABEL_71;
  lastOutsideGrenadeHint = v5->lastOutsideGrenadeHint;
  if ( lastOutsideGrenadeHint == -1 )
    goto LABEL_71;
  v93 = curTime;
  if ( curTime - lastOutsideGrenadeHint > v81 )
  {
    nextGrenadeTime = group->nextGrenadeTime;
    if ( nextGrenadeTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
    {
      v141.num = 0;
      v141.granularity = 1;
      v141.size = 64;
      v141.list = v141.staticList;
      v119 = 0;
      v141.memTag = 5;
      v141.listStatic = 1;
      idEncounterGroup::GetLivingMembers(this: group, list: &v141);
      v120 = 0;
      if ( v141.num > 0 )
      {
        v121 = 0;
        while ( 1 )
        {
          v122 = idEntity::GetPhysics(this: v141.list[v121]);
          v123 = (float *)v122->GetOrigin(this: v122, a2: 0);
          v124 = idEntity::GetPhysics(this: v116);
          v125 = (float *)v124->GetOrigin(this: v124, a2: 0);
          v126 = (float)(v125[1] - v123[1]);
          v127 = (float)((float)(v125[2] - v123[2]) * (float)2.0);
          if ( (float)((float)((float)v127 * (float)v127)
                     + (float)((float)((float)(*v125 - *v123) * (float)(*v125 - *v123))
                             + (float)((float)v126 * (float)v126))) < 65536.0 )
            break;
          ++v120;
          ++v121;
          if ( v120 >= v141.num )
            goto LABEL_121;
        }
        v119 = 1;
      }
LABEL_121:
      if ( v119 == 0 )
      {
        v9->shouldGrenade = true;
        v5->lastOutsideGrenadeHint = curTime;
      }
      if ( v141.listStatic == 0 || v141.listStatic == 2 )
      {
        if ( v141.list != nullptr )
          idMem::Free(this: &mem, ptr: v141.list, align: ALIGN_16);
        v141.list = nullptr;
        v141.size = 0;
      }
      v141.num = 0;
    }
  }
LABEL_72:
  if ( v78 != 0 )
  {
    if ( v93 - v5->lastOutsideAssaultHint > delay && v83 != nullptr )
    {
      v94 = 0;
      if ( v83->assaultBreachRules.num > 0 )
      {
        v95 = 0;
        do
        {
          if ( (unsigned __int8)idEncounterGroupExpr::Eval(this: &v83->assaultBreachRules.list[v95], owner: v82) != 0 )
            v9->assaultPrimitiveBreached = true;
          ++v94;
          ++v95;
        }
        while ( v94 < v83->assaultBreachRules.num );
      }
    }
  }
  else
  {
    v5->lastOutsideAssaultHint = v93;
  }
  if ( v140.listStatic == 0 || v140.listStatic == 2 )
  {
    if ( v140.list != nullptr )
      idMem::Free(this: &mem, ptr: v140.list, align: ALIGN_16);
    v140.list = nullptr;
    v140.size = 0;
  }
  v140.num = 0;
  if ( v139.logIndex >= 0 )
  {
    pLog = v139.pLog;
    v129 = &v139.pLog->logEntries.list[v139.logIndex];
    v130 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v129->totalTicks;
    HIDWORD(totalTicks) = v129->parent;
    LODWORD(v132) = v130 - totalTicks;
    v129->totalTicks = v132;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$489017_0
// EA  : 0x82C48340
// RVA : 0x00C48340
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void _unwind_489017_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 736));
}


// ========================================================================
// __unwind$489018
// EA  : 0x82C48368
// RVA : 0x00C48368
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void _unwind_489018()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 128));
}


// ========================================================================
// __unwind$489019
// EA  : 0x82C48390
// RVA : 0x00C48390
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void _unwind_489019()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 928 + 144));
}


// ========================================================================
// __unwind$489020
// EA  : 0x82C483B8
// RVA : 0x00C483B8
// PDB : w:\tech5\tungsten\game\entities\entityauditor.cpp
// ========================================================================

void _unwind_489020()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 928 + 416));
}

