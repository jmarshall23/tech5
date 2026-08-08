
// ========================================================================
// ?GetCoverModifiedScale@idEnvironmentAnalyzer@@QBAMABVidVec3@@_N@Z
// EA  : 0x82DF9998
// RVA : 0x00DF9998
// PDB : w:\tech5\tungsten\game\player\environmentanalyzer.cpp
// ========================================================================

float __fastcall idEnvironmentAnalyzer::GetCoverModifiedScale(
        idEnvironmentAnalyzer *this,
        const idVec3 *viewDir,
        bool getMovementScale)
{
  double v4; // fp30
  double v5; // fp0
  double v6; // fp28
  double v7; // fp1
  float y; // r8
  double v9; // fp12
  double v10; // fp0
  idVec3 v12; // [sp+50h] [-40h] BYREF

  if ( getMovementScale )
    v4 = 0.81999999;
  else
    v4 = 1.0;
  if ( getMovementScale )
    v5 = 0.6899999976158142;
  else
    v5 = 0.5;
  v6 = (float)v5;
  if ( !this->freeLean )
  {
    if ( this->forwardCollision )
    {
      y = viewDir->y;
      v12.x = viewDir->x;
      v12.z = 0.0;
      v12.y = y;
      idVec3::NormalizeFast(this: &v12);
      v9 = (float)(this->envTR[4].fraction - (float)0.25);
      if ( v9 >= 0.0 )
      {
        if ( v9 > 1.0 )
          v9 = 1.0;
      }
      else
      {
        v9 = 0.0;
      }
      v10 = (float)((float)v4
                  - (float)((float)(this->envTR[4].c.normal.x * (float)-v12.x)
                          + (float)((float)(this->envTR[4].c.normal.z * (float)-v12.z)
                                  + (float)(this->envTR[4].c.normal.y * (float)-v12.y))));
      if ( v10 >= 0.0 )
      {
        if ( v10 > 1.0 )
          v10 = 1.0;
      }
      else
      {
        v10 = 0.0;
      }
      v7 = (float)((float)((float)v10 / (float)((float)v4 - (float)v6)) + (float)((float)v9 * (float)0.5));
      if ( v7 < 0.0 )
      {
        v7 = 0.0;
        return *((float *)&v7 + 1);
      }
      if ( v7 <= 1.0 )
        return *((float *)&v7 + 1);
    }
    v7 = 1.0;
    return *((float *)&v7 + 1);
  }
  v7 = 0.0;
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?GetWallNormal@idEnvironmentAnalyzer@@QAA_NAAVidVec3@@@Z
// EA  : 0x82DF9B18
// RVA : 0x00DF9B18
// PDB : w:\tech5\tungsten\game\player\environmentanalyzer.cpp
// ========================================================================

int __fastcall idEnvironmentAnalyzer::GetWallNormal(idEnvironmentAnalyzer *this, idVec3 *res)
{
  if ( !this->forwardCollision || this->freeLean )
    return 0;
  *res = this->envTR[4].c.normal;
  return 1;
}


// ========================================================================
// ??0idEnvironmentAnalyzer@@QAA@XZ
// EA  : 0x82DF9B60
// RVA : 0x00DF9B60
// PDB : w:\tech5\tungsten\game\player\environmentanalyzer.cpp
// ========================================================================

idEnvironmentAnalyzer *__fastcall idEnvironmentAnalyzer::idEnvironmentAnalyzer(idEnvironmentAnalyzer *this)
{
  this->envCQ[0].index = 0x100000000LL;
  this->envCQ[1].index = 0x100000000LL;
  this->envCQ[2].index = 0x100000000LL;
  this->envCQ[3].index = 0x100000000LL;
  this->envCQ[4].index = 0x100000000LL;
  *(_WORD *)&this->forceLeanMode = 0;
  this->freeLean = false;
  this->resetFreeLean = true;
  return this;
}


// ========================================================================
// ?HasValidResult@idEnvironmentAnalyzer@@AAA_NH@Z
// EA  : 0x82DF9B90
// RVA : 0x00DF9B90
// PDB : w:\tech5\tungsten\game\player\environmentanalyzer.cpp
// ========================================================================

int __fastcall idEnvironmentAnalyzer::HasValidResult(idEnvironmentAnalyzer *this, int tt)
{
  idClipQuery *v3; // r31
  idClientGame *v5; // r28
  unsigned __int8 IsValid; // r3
  __int128 v7; // r11

  v3 = &this->envCQ[tt];
  v5 = clientGame;
  IsValid = idClip::QueryIsValid(this: &clientGame->clip, clipQuery: v3);
  if ( IsValid == 0 )
    return 0;
  *((idClipQuery *)&v7 + 1) = (idClipQuery)v3->index;
  DWORD1(v7) = IsValid;
  v3->index = *(unsigned __int64 *)((char *)&v7 + 4);
  idCollisionModelManager::GetContentsResult(
    this: collisionModelManager,
    result: &this->envTR[tt],
    query: &v5->clip.collisionQueries[v7 & 0xFFF].query,
    peek: false);
  return 1;
}


// ========================================================================
// ?PrioritizeLeanDir@idEnvironmentAnalyzer@@AAAXAAUtraceInfo_t@1@ABW4traceTypeIDs_t@1@AA_N2@Z
// EA  : 0x82DF9C28
// RVA : 0x00DF9C28
// PDB : w:\tech5\tungsten\game\player\environmentanalyzer.cpp
// ========================================================================

void __fastcall idEnvironmentAnalyzer::PrioritizeLeanDir(
        idEnvironmentAnalyzer *this,
        idEnvironmentAnalyzer::traceInfo_t *traceInfo,
        const idEnvironmentAnalyzer::traceTypeIDs_t *traceTypeID,
        bool *greateDir,
        bool *lesserDir)
{
  char HasValidResult; // r3

  HasValidResult = idEnvironmentAnalyzer::HasValidResult(this, tt: *traceTypeID);
  traceInfo->hasValidResult = HasValidResult;
  if ( HasValidResult != 0 )
  {
    if ( this->envTR[*traceTypeID].c.type != CONTACT_NONE )
      *greateDir = false;
    else
      *lesserDir = false;
  }
}


// ========================================================================
// ?Update@idEnvironmentAnalyzer@@QAAXPAVidActor@@ABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82DF9C98
// RVA : 0x00DF9C98
// PDB : w:\tech5\tungsten\game\player\environmentanalyzer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEnvironmentAnalyzer::Update(
        idEnvironmentAnalyzer *this,
        idPlayer *owner,
        const idVec3 *viewPos,
        const idMat3 *viewAxis)
{
  idPlayer *v8; // r3
  unsigned __int64 v9; // r21
  char *v10; // r10
  idPlayer *v11; // r22
  int v12; // ctr
  _DWORD *p_z; // r11
  float y; // r8
  float z; // r7
  idPlayer::idPlayerBehaviorLeanState_t state; // r6
  double x; // fp10
  float v18; // r10
  double v19; // fp9
  double v20; // fp8
  float v21; // r9
  double v22; // fp15
  double v23; // fp16
  double v24; // fp17
  float v25; // r9
  float v26; // r7
  idFreeCamera *FreeCamera; // r3
  double v28; // fp25
  double v29; // fp24
  double v30; // fp23
  int v31; // r6
  double v32; // fp21
  double v33; // fp20
  double v34; // fp19
  double v35; // fp31
  double v36; // fp30
  double v37; // fp29
  char v38; // r27
  float *clip8x16; // r30
  idPresentable *presentable; // r3
  double v41; // fp26
  double v42; // fp27
  double v43; // fp28
  int v44; // r3
  int v45; // r31
  double v46; // fp1
  double v47; // fp6
  double v48; // fp4
  double v49; // fp2
  double v50; // fp13
  char v55; // r3
  double v56; // fp9
  double v57; // fp6
  double v58; // fp4
  idClipQuery *v59; // r31
  unsigned __int64 index; // r11
  idClientGame *v61; // r9
  double v62; // fp9
  double v63; // fp6
  double v64; // fp4
  int contentFlags; // r11
  idAI2 *v66; // r31
  idAI2 *v67; // r3
  idAnimatedSimple *v68; // r3
  idPresentable *v69; // r3
  int v70; // r3
  int v71; // r30
  int v72; // r11
  __int64 v73; // r4 OVERLAPPED
  bool v74; // r31
  bool v75; // r28
  idPresentable *v76; // r3
  idPresentablePlayer *v77; // r3
  BOOL v78; // r10
  unsigned int forwardCollision; // r11
  int v80; // r5
  double v81; // fp0
  double v82; // fp13
  bool v83; // r25
  char v84; // r11
  char v85; // r9
  char v86; // r11
  char v87; // r31
  char v88; // r11
  unsigned __int8 v89; // r27
  bool v90; // r11
  BOOL v91; // r10
  bool v92; // r8
  unsigned __int8 v93; // r11
  int v94; // r26
  unsigned __int8 v95; // r11
  bool *v96; // r6
  idEnvironmentAnalyzer::traceInfo_t *v97; // r4
  int v98; // r30
  BOOL v99; // r7
  char v100; // r6
  unsigned __int8 v101; // r11
  char v102; // r5
  idPhysics_Player *PhysicsObj; // r3
  unsigned __int8 v104; // r11
  idPhysics_Player *v105; // r3
  double v106; // fp0
  char HasValidResult; // r3
  idClipModel *clip8x8; // r11
  idPhysics *Physics; // r3
  double v110; // fp28
  double v111; // fp27
  double v112; // fp26
  float *v113; // r3
  double v114; // fp12
  double v115; // fp10
  double v116; // fp9
  char v117; // r11
  unsigned __int8 forceLeanMode; // r11
  BOOL v119; // r11
  unsigned __int8 v120; // r8
  BOOL v121; // r28
  int v122; // r31
  double v123; // fp0
  float *v124; // r11
  float *v125; // r10
  float *v126; // r3
  float *v127; // r9
  double v128; // fp9
  double v129; // fp13
  double v130; // fp11
  double v131; // fp6
  double v132; // fp5
  double v133; // fp12
  double v134; // fp8
  double v135; // fp10
  double v136; // fp4
  double v137; // fp10
  double v138; // fp5
  double v139; // fp1
  double v140; // fp12
  double v141; // fp7
  double v142; // fp30
  idEnvironmentAnalyzer *v143; // r27
  _BYTE *v144; // r31
  float *v145; // r30
  int v146; // r25
  float *v147; // r29
  float *v148; // r28
  float *v149; // r11
  double v150; // fp9
  double v151; // fp3
  double v154; // fp4
  double v155; // fp2
  double v156; // fp0
  double v157; // fp10
  double v158; // fp0
  double v159; // fp7
  double v160; // fp6
  double v161; // fp13
  double v162; // fp12
  double v163; // fp11
  double v164; // fp9
  double v165; // fp7
  double v166; // fp5
  double v167; // fp3
  double v168; // fp2
  double v169; // fp8
  double v170; // fp6
  double v172; // fp4
  double v173; // fp29
  double v175; // fp28
  double v176; // fp26
  int v179; // [sp+8h] [-3D8h]
  bool v180; // [sp+Fh] [-3D1h]
  const char *v181; // [sp+10h] [-3D0h]
  int v182; // [sp+14h] [-3CCh]
  int v183; // [sp+18h] [-3C8h]
  int v184; // [sp+1Ch] [-3C4h]
  int v185; // [sp+20h] [-3C0h]
  int v186; // [sp+24h] [-3BCh]
  int v187; // [sp+28h] [-3B8h]
  int v188; // [sp+2Ch] [-3B4h]
  int v189; // [sp+30h] [-3B0h]
  int v190; // [sp+34h] [-3ACh]
  int v191; // [sp+38h] [-3A8h]
  int v192; // [sp+3Ch] [-3A4h]
  int v193; // [sp+40h] [-3A0h]
  int v194; // [sp+44h] [-39Ch]
  int v195; // [sp+48h] [-398h]
  int v196; // [sp+4Ch] [-394h]
  int v197; // [sp+50h] [-390h]
  int v198; // [sp+58h] [-388h]
  int v199; // [sp+60h] [-380h]
  unsigned __int8 v200; // [sp+70h] [-370h] BYREF
  char v201; // [sp+71h] [-36Fh] BYREF
  bool v202[6]; // [sp+72h] [-36Eh] BYREF
  idVec3 v203; // [sp+78h] [-368h] BYREF
  float v204; // [sp+84h] [-35Ch]
  double v205; // [sp+88h] [-358h] BYREF
  double v206; // [sp+90h] [-350h]
  float v207; // [sp+98h] [-348h]
  float v208; // [sp+A0h] [-340h]
  float v209; // [sp+A4h] [-33Ch]
  float v210; // [sp+A8h] [-338h]
  char v211; // [sp+ACh] [-334h] BYREF
  idBox v212; // [sp+B0h] [-330h] BYREF
  float v213[4]; // [sp+F0h] [-2F0h] BYREF
  float v214[4]; // [sp+100h] [-2E0h] BYREF
  _BYTE v215[4]; // [sp+110h] [-2D0h] BYREF
  int v216; // [sp+114h] [-2CCh]
  _BYTE v217[8]; // [sp+118h] [-2C8h] BYREF
  _BYTE v218[32]; // [sp+120h] [-2C0h] BYREF
  _BYTE v219[20]; // [sp+140h] [-2A0h] BYREF
  _BYTE v220[4]; // [sp+154h] [-28Ch] BYREF
  idEnvironmentAnalyzer::traceInfo_t v221; // [sp+158h] [-288h] BYREF
  char v222; // [sp+1A0h] [-240h] BYREF
  int v223; // [sp+1A4h] [-23Ch]
  float v224; // [sp+1A8h] [-238h]
  float v225; // [sp+1ACh] [-234h]
  float v226; // [sp+1B0h] [-230h]
  float v227; // [sp+1B4h] [-22Ch]
  float v228; // [sp+1B8h] [-228h]
  float v229; // [sp+1BCh] [-224h]
  float v230; // [sp+1C0h] [-220h]
  float v231; // [sp+1C4h] [-21Ch]
  float v232; // [sp+1C8h] [-218h]
  float v233; // [sp+1CCh] [-214h]
  float v234; // [sp+1D0h] [-210h]
  float v235; // [sp+1D4h] [-20Ch]
  float v236; // [sp+1D8h] [-208h]
  float v237; // [sp+1DCh] [-204h]
  float v238; // [sp+1E0h] [-200h]
  char v239; // [sp+1E4h] [-1FCh]
  char v240; // [sp+1E8h] [-1F8h]
  idClipModel *v241; // [sp+1ECh] [-1F4h]
  float v242; // [sp+1F0h] [-1F0h]
  float v243; // [sp+1F4h] [-1ECh]
  float v244; // [sp+1F8h] [-1E8h]
  float v245; // [sp+1FCh] [-1E4h]
  float v246; // [sp+200h] [-1E0h]
  float v247; // [sp+204h] [-1DCh]
  float v248; // [sp+208h] [-1D8h]
  float v249; // [sp+20Ch] [-1D4h]
  float v250; // [sp+210h] [-1D0h]
  float v251; // [sp+214h] [-1CCh]
  float v252; // [sp+218h] [-1C8h]
  float v253; // [sp+21Ch] [-1C4h]
  float v254; // [sp+220h] [-1C0h]
  float v255; // [sp+224h] [-1BCh]
  float v256; // [sp+228h] [-1B8h]
  char v257; // [sp+22Ch] [-1B4h]
  char v258; // [sp+230h] [-1B0h]
  float *v259; // [sp+234h] [-1ACh]
  float v260; // [sp+238h] [-1A8h]
  float v261; // [sp+23Ch] [-1A4h]
  float v262; // [sp+240h] [-1A0h]
  float v263; // [sp+244h] [-19Ch]
  float v264; // [sp+248h] [-198h]
  float v265; // [sp+24Ch] [-194h]
  float v266; // [sp+250h] [-190h]
  float v267; // [sp+254h] [-18Ch]
  float v268; // [sp+258h] [-188h]
  float v269; // [sp+25Ch] [-184h]
  float v270; // [sp+260h] [-180h]
  float v271; // [sp+264h] [-17Ch]
  float v272; // [sp+268h] [-178h]
  float v273; // [sp+26Ch] [-174h]
  float v274; // [sp+270h] [-170h]
  char v275; // [sp+274h] [-16Ch]
  float v276[16]; // [sp+280h] [-160h] BYREF
  double v277; // [sp+2C0h] [-120h]
  double v278; // [sp+2C8h] [-118h]

  v8 = idPlayer::CastTo(c: owner);
  LODWORD(v9) = 0;
  v10 = &v211;
  v215[0] = 0;
  v11 = v8;
  v216 = 0;
  v12 = 9;
  v220[0] = 0;
  v221.doTheTrace = false;
  p_z = (_DWORD *)&viewAxis[-1].mat[2].z;
  v221.clipModel = nullptr;
  v221.hasValidResult = false;
  v222 = 0;
  v223 = 0;
  v239 = 0;
  v240 = 0;
  v241 = nullptr;
  v257 = 0;
  v258 = 0;
  v259 = nullptr;
  v275 = 0;
  do
  {
    ++p_z;
    v10 += 4;
    *(_DWORD *)v10 = *p_z;
    --v12;
  }
  while ( v12 != 0 );
  v212.center.z = 0.0;
  v212.axis.mat[0].x = vec3_up.x;
  v212.axis.mat[0].y = vec3_up.y;
  v212.axis.mat[0].z = vec3_up.z;
  idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v212, prio1: 0, prio2: 2);
  y = viewPos->y;
  z = viewPos->z;
  state = v11->behaviors.lean.state;
  v203.x = viewPos->x;
  v203.y = y;
  v203.z = z;
  if ( state != LEAN_STATE_NONE )
  {
    x = viewAxis->mat[1].x;
    v18 = v11->behaviors.lean.leanOffset.p1.x;
    v19 = viewAxis->mat[1].y;
    v20 = viewAxis->mat[1].z;
    v21 = v11->behaviors.lean.leanOffset.p1.z;
    LODWORD(v206) = LODWORD(v11->behaviors.lean.leanOffset.p1.y);
    *(float *)&v206 = v18;
    v22 = (float)((float)((float)(v203.x - (float)(v18 * (float)x)) - (float)(vec3_up.x * *((float *)&v206 + 1)))
                - (float)(viewAxis->mat[0].x * v21));
    v23 = (float)((float)((float)(v203.y - (float)((float)v19 * v18)) - (float)(vec3_up.y * *((float *)&v206 + 1)))
                - (float)(viewAxis->mat[0].y * v21));
    v207 = v21;
    v24 = (float)((float)((float)(v203.z - (float)((float)v20 * v18)) - (float)(vec3_up.z * *((float *)&v206 + 1)))
                - (float)(viewAxis->mat[0].z * v21));
  }
  else
  {
    v24 = v203.z;
    v23 = v203.y;
    v22 = v203.x;
  }
  v25 = viewPos->y;
  v26 = viewPos->z;
  v208 = viewPos->x;
  v209 = v25;
  v210 = v26;
  if ( g_freeCam.valueInteger != 0 )
  {
    FreeCamera = idGameLocal::GetFreeCamera(this: gameLocal);
    if ( FreeCamera != nullptr )
    {
      v208 = FreeCamera->curPos.x;
      v209 = FreeCamera->curPos.y;
      v210 = FreeCamera->curPos.z;
    }
  }
  v28 = v212.axis.mat[0].z;
  v29 = v212.axis.mat[0].y;
  v30 = v212.axis.mat[0].x;
  v31 = this->forceLeanMode & 3;
  v32 = v212.extents.z;
  HIDWORD(v9) = &ai_useTurnTransitions.valueString.baseBuffer[12];
  v33 = v212.extents.y;
  v34 = v212.extents.x;
  v35 = v212.center.z;
  v36 = v212.center.y;
  v37 = v212.center.x;
  v204 = 1.0;
  if ( v31 != 0 )
  {
    this->forwardCollision = true;
  }
  else
  {
    v38 = 0;
    clip8x16 = (float *)clientGame->clip.clip8x16;
    v260 = v212.center.x;
    v261 = v212.center.y;
    v262 = v212.center.z;
    v263 = v212.extents.x;
    v264 = v212.extents.y;
    v259 = clip8x16;
    v265 = v212.extents.z;
    v266 = v212.axis.mat[0].x;
    v267 = v212.axis.mat[0].y;
    v268 = v212.axis.mat[0].z;
    v270 = (float)v23 - (float)(v212.axis.mat[0].y * (float)7.0);
    v271 = (float)v24 - (float)(v212.axis.mat[0].z * (float)7.0);
    v269 = (float)v22 - (float)(v212.axis.mat[0].x * (float)7.0);
    v273 = (float)(v212.center.y * 48.0) + v270;
    v274 = (float)(v212.center.z * 48.0) + v271;
    v272 = (float)(v212.center.x * 48.0) + v269;
    presentable = v11->presentable;
    v41 = v269;
    v42 = v270;
    v43 = v271;
    if ( presentable != nullptr )
    {
      v44 = (int)presentable->GetPlayerInterface_2(this: presentable);
      v43 = v271;
      clip8x16 = v259;
      v42 = v270;
      v41 = v269;
    }
    else
    {
      v44 = 0;
    }
    v45 = *(_BYTE *)(v44 + 47837) == 0 ? 0 : v44 + 47708;
    if ( v45 != 0 && clip8x16 != nullptr )
    {
      v203.x = v272 - (float)v41;
      v203.y = v273 - (float)v42;
      v203.z = v274 - (float)v43;
      v46 = idVec3::NormalizeFast(this: &v203);
      v47 = __fabs(clip8x16[25]);
      v48 = __fabs(clip8x16[22]);
      v49 = __fabs(clip8x16[24]);
      v50 = __fabs(clip8x16[21]);
      v212.axis.mat[0].x = v260;
      v212.axis.mat[0].y = v261;
      v277 = v37;
      _FP11 = (float)((float)v48 - (float)v47);
      v212.axis.mat[0].z = v262;
      v212.axis.mat[1].x = v263;
      _FP29 = (float)((float)v50 - (float)v49);
      v205 = v35;
      v278 = v36;
      v206 = v28;
      __asm { fsel      f7, f11, f4, f6 }
      v212.axis.mat[1].y = v264;
      __asm { fsel      f6, f29, f13, f2 }
      v212.axis.mat[1].z = v265;
      v212.axis.mat[2].x = v266;
      v212.axis.mat[2].y = v267;
      v212.axis.mat[2].z = v268;
      v212.extents.x = (float)v46 * (float)0.5;
      v212.extents.z = _FP7;
      v212.extents.y = _FP6;
      v212.center.x = (float)((float)(v203.x * (float)v46) * (float)0.5) + (float)v41;
      v212.center.y = (float)v42 + (float)((float)(v203.y * (float)v46) * (float)0.5);
      *(double *)&v203.x = v29;
      v212.center.z = (float)v43 + (float)((float)(v203.z * (float)v46) * (float)0.5);
      v55 = idBox::ContainsPoint(this: &v212, p: (const idVec3 *)(v45 + 56));
      v35 = v205;
      v36 = v278;
      v37 = v277;
      v28 = v206;
      v29 = *(double *)&v203.x;
      if ( v55 != 0
        && (float)((float)((float)-v205 * *(float *)(v45 + 76))
                 + (float)((float)(*(float *)(v45 + 72) * (float)-v278) + (float)(*(float *)(v45 + 68) * (float)-v277))) > 0.69 )
      {
        this->forwardCollision = true;
        v38 = 1;
        contactInfo_t::operator=(this: &this->envTR[4].c, __that: (const contactInfo_t *)(v45 + 52));
        if ( player_analyzeenvdebug.valueInteger == owner->entityNumber )
        {
          v56 = (float)(*(float *)(v45 + 68) * (float)4.0);
          v57 = *(float *)(v45 + 56);
          v58 = (float)(*(float *)(v45 + 64) + (float)(*(float *)(v45 + 76) * (float)4.0));
          v213[1] = *(float *)(v45 + 60) + (float)(*(float *)(v45 + 72) * (float)4.0);
          v213[2] = v58;
          v213[0] = (float)v56 + (float)v57;
          ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))clientGame->renderWorld->DebugArrow2)(
            a1: clientGame->renderWorld,
            a2: &idColor::colorGreen,
            a3: v45 + 56,
            a4: v213,
            a5: v204);
        }
      }
    }
    if ( v38 == 0 )
    {
      v258 = 1;
      v59 = &this->envCQ[4];
      if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->envCQ[4]) != 0 )
      {
        index = v59->index;
        v61 = clientGame;
        v59->index = v9;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &this->envTR[4],
          query: &v61->clip.collisionQueries[index & 0xFFF].query,
          peek: false);
        if ( player_analyzeenvdebug.valueInteger == owner->entityNumber )
        {
          v62 = (float)(this->envTR[4].c.normal.z * (float)4.0);
          v63 = this->envTR[4].c.point.z;
          v64 = (float)(this->envTR[4].c.point.y + (float)(this->envTR[4].c.normal.y * (float)4.0));
          v214[0] = (float)(this->envTR[4].c.normal.x * (float)4.0) + this->envTR[4].c.point.x;
          v214[1] = v64;
          v214[2] = (float)v63 + (float)v62;
          ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))clientGame->renderWorld->DebugArrow2)(
            a1: clientGame->renderWorld,
            a2: &idColor::colorGreen,
            a3: &this->envTR[4].c.point,
            a4: v214,
            a5: v204);
        }
        this->forwardCollision = (float)((float)((float)-v37 * this->envTR[4].c.normal.x)
                                       + (float)((float)(this->envTR[4].c.normal.z * (float)-v35)
                                               + (float)(this->envTR[4].c.normal.y * (float)-v36))) > 0.69;
      }
    }
    if ( this->forwardCollision )
    {
      contentFlags = this->envTR[4].c.contentFlags;
      if ( (contentFlags & 2) != 0 || (contentFlags & 0x200000) != 0 )
        goto LABEL_40;
      v66 = (idAI2 *)gameLocal->entities.ptr[this->envTR[4].c.entityNum];
      if ( v66 != nullptr )
      {
        if ( (unsigned __int8)idClass::IsType(this: v66, superclass: &idCuttable::Type) != 0
          || (unsigned __int8)idClass::IsType(this: v66, superclass: &idFuncChain::Type) != 0 )
        {
          goto LABEL_40;
        }
        if ( (this->envTR[4].c.surfaceFlags & 0x8000) != 0 )
          this->forwardCollision = false;
        v67 = idAI2::CastTo(c: v66);
        if ( v67 != nullptr && !v67->aiEditable.interactions.playerShouldLowerWeapon )
          this->forwardCollision = false;
        v68 = idAnimatedSimple::CastTo(c: (idAnimatedSimple *)v66);
        if ( v68 != nullptr && (*((_BYTE *)v68 + 5292) & 0x20) != 0 )
LABEL_40:
          this->forwardCollision = false;
      }
    }
  }
  v69 = v11->presentable;
  if ( v69 != nullptr )
    v70 = (int)v69->GetPlayerInterface_2(this: v69);
  else
    v70 = 0;
  v71 = v70 + 46028;
  v72 = 0;
  if ( (*(_BYTE *)(v70 + 46037) & 0x80) == 0 )
    v72 = *(_DWORD *)v71;
  HIDWORD(v73) = v11->presentable;
  v74 = (v72 & 0x800000) != 0;
  v75 = false;
  if ( HIDWORD(v73) != 0 )
  {
    HIDWORD(v73) = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)HIDWORD(v73) + 104))(a1: HIDWORD(v73));
    if ( HIDWORD(v73) != 0 )
    {
      v76 = v11->presentable;
      v77 = v76 != nullptr ? v76->GetPlayerInterface_2(this: v76) : nullptr;
      HIDWORD(v73) = idPresentablePlayer::GetControlWeapon(this: v77);
      if ( HIDWORD(v73) != 0 )
        v75 = (*(_BYTE *)(HIDWORD(v73) + 452) & 8) != 0;
    }
  }
  v78 = v74;
  if ( !v74 && !v75 )
  {
    this->forceLeanMode = 0;
    *(_WORD *)&this->freeLean = 1;
    goto LABEL_141;
  }
  if ( this->resetFreeLean )
  {
    forwardCollision = this->forwardCollision;
    this->resetFreeLean = false;
    this->freeLean = (_cntlzw(forwardCollision) & 0x20) != 0;
  }
  v80 = *(char *)(v71 + 7);
  LODWORD(v73) = *(char *)(v71 + 6);
  v206 = *(double *)((char *)&v73 - 4);
  *(_QWORD *)&v203.x = v73;
  v81 = (float)v73;
  v82 = (float)*(__int64 *)((char *)&v73 - 4);
  v83 = __fabs(v82) >= __fabs((float)((float)v73 * (float)0.94999999));
  if ( !v74 || (v84 = 1, v81 <= 0.0) )
    v84 = 0;
  v85 = v84;
  if ( !v74 || (v86 = 1, v81 >= -15.0) )
    v86 = 0;
  v87 = v86;
  if ( !v78 || (v88 = 1, v82 >= 0.0) )
    v88 = 0;
  v89 = v88;
  v201 = v88;
  if ( !v78 || v88 != 0 || (v90 = true, v82 <= 0.0) )
    v90 = false;
  v91 = this->forwardCollision;
  v92 = v90;
  v202[0] = v90;
  if ( !v91 || v85 != 0 || (v93 = 1, !v75) )
    v93 = 0;
  v94 = v93;
  v95 = v85 | v93;
  v200 = v95;
  if ( v89 != 0 && v95 != 0 && v83 )
  {
    if ( (this->forceLeanMode & 1) != 0 )
      goto LABEL_95;
    HIDWORD(v205) = 0;
    v96 = (bool *)&v201;
    v97 = (idEnvironmentAnalyzer::traceInfo_t *)v215;
    goto LABEL_93;
  }
  if ( !v92 || v95 == 0 || !v83 )
  {
    if ( v95 == 0 || v89 == 0 && !v92 || v83 || (this->forceLeanMode & 4) != 0 )
      goto LABEL_95;
    v96 = v202;
    if ( !v92 )
      v96 = (bool *)&v201;
    v97 = (idEnvironmentAnalyzer::traceInfo_t *)&v222;
    HIDWORD(v205) = 2;
LABEL_93:
    idEnvironmentAnalyzer::PrioritizeLeanDir(
      this,
      traceInfo: v97,
      traceTypeID: (const idEnvironmentAnalyzer::traceTypeIDs_t *)&v205,
      greateDir: v96,
      lesserDir: (bool *)&v200);
    v89 = v201;
    goto LABEL_94;
  }
  if ( (this->forceLeanMode & 2) == 0 )
  {
    HIDWORD(v205) = 1;
    idEnvironmentAnalyzer::PrioritizeLeanDir(
      this,
      traceInfo: &v221,
      traceTypeID: (const idEnvironmentAnalyzer::traceTypeIDs_t *)&v205,
      greateDir: v202,
      lesserDir: (bool *)&v200);
LABEL_94:
    v95 = v200;
  }
LABEL_95:
  v98 = v95;
  v99 = this->forwardCollision;
  v100 = (v95 == 0) - 1;
  v101 = this->forceLeanMode & 0xFB;
  v102 = v100 & v239;
  this->forceLeanMode = v101;
  v239 = v102;
  if ( !v99 && (v101 & 0x10) != 0 )
  {
    PhysicsObj = idPlayer::GetPhysicsObj(this: v11);
    idPhysics_Player::SetCrouch(this: PhysicsObj, crouch: false);
  }
  v104 = this->forceLeanMode & 0xEF;
  this->forceLeanMode = v104;
  if ( v87 == 0 )
  {
    v257 = 0;
    this->forceLeanMode = v104 & 0xF7;
  }
  if ( v98 != 0 )
  {
    v224 = v37;
    v222 = 1;
    v225 = v36;
    v226 = v35;
    v227 = v34;
    v228 = v33;
    v229 = v32;
    v230 = v30;
    v231 = v29;
    v232 = v28;
    v105 = idPlayer::GetPhysicsObj(this: v11);
    if ( (unsigned __int8)idPhysics_Player::IsCrouching(this: v105) != 0 )
      v106 = 40.0;
    else
      v106 = 16.0;
    HasValidResult = v239;
    v234 = (float)((float)v106 * vec3_up.y) + (float)v23;
    v233 = (float)((float)v106 * vec3_up.x) + (float)v22;
    v235 = (float)v24 + (float)((float)v106 * vec3_up.z);
    v236 = (float)((float)v37 * LEAN_UP_FORWARD_TRACE_DISTANCE) + v233;
    v237 = (float)((float)v36 * LEAN_UP_FORWARD_TRACE_DISTANCE) + v234;
    v238 = (float)((float)v35 * LEAN_UP_FORWARD_TRACE_DISTANCE) + v235;
    if ( v239 == 0 )
    {
      HasValidResult = idEnvironmentAnalyzer::HasValidResult(this, tt: 2);
      v239 = HasValidResult;
    }
    if ( HasValidResult != 0 && this->envTR[2].c.type == CONTACT_NONE )
      this->forceLeanMode |= 4u;
  }
  if ( v87 != 0 && (this->forceLeanMode & 8) == 0 )
  {
    v240 = 1;
    clip8x8 = clientGame->clip.clip8x8;
    v242 = v37;
    v243 = v36;
    v244 = v35;
    v245 = v34;
    v246 = v33;
    v247 = v32;
    v241 = clip8x8;
    v248 = v30;
    v249 = v29;
    v250 = v28;
    Physics = idEntity::GetPhysics(this: owner);
    v110 = (float)(vec3_up.x * 5.0);
    v111 = (float)(vec3_up.y * 5.0);
    v112 = (float)(vec3_up.z * 5.0);
    v113 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v114 = (float)((float)v110 + *v113);
    v115 = (float)(v113[1] + (float)v111);
    v116 = (float)(v113[2] + (float)v112);
    v117 = v257;
    v252 = v113[1] + (float)v111;
    v251 = v114;
    v253 = v116;
    v254 = (float)((float)v37 * LEAN_DOWN_FORWARD_TRACE_DISTANCE) + (float)v114;
    v255 = (float)((float)v36 * LEAN_DOWN_FORWARD_TRACE_DISTANCE) + (float)v115;
    v256 = (float)((float)v35 * LEAN_DOWN_FORWARD_TRACE_DISTANCE) + (float)v116;
    if ( v257 == 0 )
    {
      v117 = idEnvironmentAnalyzer::HasValidResult(this, tt: 3);
      v257 = v117;
    }
    if ( v117 != 0 && this->envTR[3].c.type == CONTACT_NONE )
      this->forceLeanMode |= 8u;
  }
  if ( v89 == 0 )
  {
    forceLeanMode = this->forceLeanMode;
    v220[0] = 0;
    this->forceLeanMode = forceLeanMode & 0xFE;
  }
  v119 = v202[0];
  if ( !v202[0] )
  {
    v120 = this->forceLeanMode;
    v221.hasValidResult = false;
    this->forceLeanMode = v120 & 0xFD;
  }
  if ( v89 != 0 && (v83 && v98 != 0 || (this->forceLeanMode & 1) == 0)
    || v119 && (v83 && v98 != 0 || (this->forceLeanMode & 2) == 0) )
  {
    v121 = (_cntlzw(v89) & 0x20) != 0;
    v122 = 72 * v121;
    v215[72 * v121] = 1;
    if ( v89 != 0 )
      v123 = -1.0;
    else
      v123 = v204;
    v124 = (float *)&v218[v122 + 28];
    v125 = (float *)&v219[v122 + 8];
    v126 = (float *)&v217[v122];
    v127 = (float *)&v218[v122 + 16];
    v128 = vec3_up.z;
    v129 = vec3_up.x;
    v130 = vec3_up.y;
    v131 = (float)((float)v23 - (float)(vec3_up.y * (float)8.0));
    v132 = (float)((float)v24 - (float)(vec3_up.z * (float)8.0));
    v133 = (float)((float)v37 * LEAN_SIDE_FRONT_TRACE_DISTANCE);
    v134 = (float)((float)v35 * LEAN_SIDE_FRONT_TRACE_DISTANCE);
    v135 = (float)((float)v36 * LEAN_SIDE_FRONT_TRACE_DISTANCE);
    v136 = (float)((float)((float)v22 - (float)(vec3_up.x * (float)8.0))
                 + (float)((float)((float)v123 * (float)v34) * 24.0));
    *v124 = (float)((float)v22 - (float)(vec3_up.x * (float)8.0)) + (float)((float)((float)v123 * (float)v34) * 24.0);
    v124[1] = (float)v131 + (float)((float)((float)v123 * (float)v33) * 24.0);
    v124[2] = (float)v132 + (float)((float)((float)v123 * (float)v32) * 24.0);
    *v125 = (float)v133 + (float)v136;
    v137 = (float)((float)((float)v131 + (float)((float)((float)v123 * (float)v33) * 24.0)) + (float)v135);
    v125[1] = v137;
    v138 = (float)((float)((float)v132 + (float)((float)((float)v123 * (float)v32) * 24.0)) + (float)v134);
    v125[2] = v138;
    v139 = *(float *)&v218[v122 + 32];
    v141 = (float)((float)((float)v133 + (float)v136) - *(float *)&v218[v122 + 28]);
    v140 = *(float *)&v218[v122 + 36];
    *v126 = v141;
    v126[2] = (float)v138 - (float)v140;
    v126[1] = (float)v137 - (float)v139;
    *v127 = v129;
    v127[1] = v130;
    v127[2] = v128;
    idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v217[v122], prio1: 0, prio2: 2);
    if ( v220[v122] == 0 )
      v220[v122] = idEnvironmentAnalyzer::HasValidResult(this, tt: v121);
    if ( v220[v122] != 0 && this->envTR[v121].c.type == CONTACT_NONE )
      this->forceLeanMode |= ((_cntlzw(v121) & 0x20) == 0) + 1;
  }
  if ( v94 != 0 && !this->freeLean && (this->forceLeanMode & 4) != 0 && (this->forceLeanMode & 0xB) == 0 )
    this->forceLeanMode |= 0x10u;
LABEL_141:
  v142 = v204;
  v143 = this;
  v144 = v219;
  v145 = (float *)v218;
  v146 = 5;
  do
  {
    if ( *(v144 - 48) != 0 )
    {
      v147 = (float *)(v144 + 8);
      v148 = (float *)(v144 - 4);
      v143->envCQ[0].index = *(_QWORD *)&idClip::Translation(
                                           this: (idClip *)&v203,
                                           result: &clientGame->clip,
                                           a3: nullptr,
                                           start: (const idVec3 *)(v144 - 4),
                                           end: (const idVec3 *)(v144 + 8),
                                           clipModel: *((idClipModel **)v144 - 11),
                                           startAxis: (idMat3 *)(v144 - 40),
                                           clipMask: 8193,
                                           passEntityNumber: v179,
                                           moveClipModel: v180,
                                           userName: v181,
                                           a12: v182,
                                           a13: v183,
                                           a14: v184,
                                           a15: v185,
                                           a16: v186,
                                           a17: v187,
                                           a18: v188,
                                           a19: v189,
                                           a20: v190,
                                           a21: v191,
                                           a22: v192,
                                           a23: v193,
                                           a24: v194,
                                           a25: v195,
                                           a26: v196,
                                           a27: v197,
                                           a28: owner->entityNumber,
                                           a29: v198,
                                           a30: false,
                                           a31: v199,
                                           a32: (int)"w:\\tech5\\tungsten\\game\\player\\EnvironmentAnalyzer.cpp(405) : Translation")->world;
      if ( player_analyzeenvdebug.valueInteger == owner->entityNumber )
      {
        v149 = *((float **)v144 - 11);
        v150 = (float)(*((float *)v144 + 4) - *((float *)v144 + 1));
        v151 = (float)(*((float *)v144 + 3) - *(float *)v144);
        _FP12 = (float)((float)((float)((float)v151 * (float)v151)
                              + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148))
                                      + (float)((float)v150 * (float)v150)))
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f7, f12, f13, f0 }
        v154 = __frsqrte(_FP7);
        v155 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v154
                                                                                             * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5))
                                                                                     * (float)v154)
                                                                             - (float)1.5)
                                                             * (float)v154)
                                                     * (float)((float)((float)((float)v151 * (float)v151)
                                                                     + (float)((float)((float)(*v147 - *v148)
                                                                                     * (float)(*v147 - *v148))
                                                                             + (float)((float)v150 * (float)v150)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v154
                                                                                     * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150)))
                                                                                             * (float)0.5))
                                                                             * (float)v154)
                                                                     - (float)1.5)
                                                     * (float)v154))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v154
                                                             * (float)((float)((float)((float)v151 * (float)v151)
                                                                             + (float)((float)((float)(*v147 - *v148)
                                                                                             * (float)(*v147 - *v148))
                                                                                     + (float)((float)v150 * (float)v150)))
                                                                     * (float)0.5))
                                                     * (float)v154)
                                             - (float)1.5)
                             * (float)v154));
        v156 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5)) * (float)v154) - (float)1.5)
                                                                                             * (float)v154)
                                                                                     * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150)))
                                                                                             * (float)0.5))
                                                                             * (float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5)) * (float)v154) - (float)1.5)
                                                                                     * (float)v154))
                                                                     - (float)1.5)
                                                     * (float)((float)-(float)((float)((float)((float)v154
                                                                                             * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5))
                                                                                     * (float)v154)
                                                                             - (float)1.5)
                                                             * (float)v154))
                                             * (float)((float)((float)((float)v151 * (float)v151)
                                                             + (float)((float)((float)(*v147 - *v148)
                                                                             * (float)(*v147 - *v148))
                                                                     + (float)((float)v150 * (float)v150)))
                                                     * (float)0.5))
                                     * (float)v155)
                             - (float)1.5);
        v157 = (float)((float)((float)v156
                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5)) * (float)v154)
                                                                                             - (float)1.5)
                                                                             * (float)v154)
                                                                     * (float)((float)((float)((float)v151 * (float)v151)
                                                                                     + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148))
                                                                                             + (float)((float)v150 * (float)v150)))
                                                                             * (float)0.5))
                                                             * (float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5))
                                                                                             * (float)v154)
                                                                                     - (float)1.5)
                                                                     * (float)v154))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)v154
                                                                             * (float)((float)((float)((float)v151 * (float)v151)
                                                                                             + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150)))
                                                                                     * (float)0.5))
                                                                     * (float)v154)
                                                             - (float)1.5)
                                             * (float)v154)))
                     * (float)(*v147 - *v148));
        v159 = (float)((float)((float)v156
                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5)) * (float)v154)
                                                                                             - (float)1.5)
                                                                             * (float)v154)
                                                                     * (float)((float)((float)((float)v151 * (float)v151)
                                                                                     + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148))
                                                                                             + (float)((float)v150 * (float)v150)))
                                                                             * (float)0.5))
                                                             * (float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5))
                                                                                             * (float)v154)
                                                                                     - (float)1.5)
                                                                     * (float)v154))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)v154
                                                                             * (float)((float)((float)((float)v151 * (float)v151)
                                                                                             + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150)))
                                                                                     * (float)0.5))
                                                                     * (float)v154)
                                                             - (float)1.5)
                                             * (float)v154)))
                     * (float)v151);
        v160 = (float)((float)((float)v156
                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5)) * (float)v154)
                                                                                             - (float)1.5)
                                                                             * (float)v154)
                                                                     * (float)((float)((float)((float)v151 * (float)v151)
                                                                                     + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148))
                                                                                             + (float)((float)v150 * (float)v150)))
                                                                             * (float)0.5))
                                                             * (float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5))
                                                                                             * (float)v154)
                                                                                     - (float)1.5)
                                                                     * (float)v154))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)v154
                                                                             * (float)((float)((float)((float)v151 * (float)v151)
                                                                                             + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150)))
                                                                                     * (float)0.5))
                                                                     * (float)v154)
                                                             - (float)1.5)
                                             * (float)v154)))
                     * (float)v150);
        v158 = (float)((float)((float)v156
                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5)) * (float)v154)
                                                                                             - (float)1.5)
                                                                             * (float)v154)
                                                                     * (float)((float)((float)((float)v151 * (float)v151)
                                                                                     + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148))
                                                                                             + (float)((float)v150 * (float)v150)))
                                                                             * (float)0.5))
                                                             * (float)((float)-(float)((float)((float)((float)v154 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150))) * (float)0.5))
                                                                                             * (float)v154)
                                                                                     - (float)1.5)
                                                                     * (float)v154))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)v154
                                                                             * (float)((float)((float)((float)v151 * (float)v151)
                                                                                             + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148)) + (float)((float)v150 * (float)v150)))
                                                                                     * (float)0.5))
                                                                     * (float)v154)
                                                             - (float)1.5)
                                             * (float)v154)))
                     * (float)((float)((float)v151 * (float)v151)
                             + (float)((float)((float)(*v147 - *v148) * (float)(*v147 - *v148))
                                     + (float)((float)v150 * (float)v150))));
        v161 = (float)((float)((float)((float)v157 * (float)v158) * (float)0.5) + *v148);
        v162 = (float)(*(float *)v144 + (float)((float)((float)v158 * (float)v159) * (float)0.5));
        v163 = (float)(*((float *)v144 + 1) + (float)((float)((float)v158 * (float)v160) * (float)0.5));
        if ( v149 != nullptr )
        {
          v164 = (float)((float)v158 * (float)0.5);
          v165 = __fabs(v149[25]);
          v166 = __fabs(v149[22]);
          v167 = __fabs(v149[24]);
          v168 = __fabs(v149[21]);
          v276[6] = *(v145 - 2);
          v276[7] = *(v145 - 1);
          v276[0] = v161;
          v169 = v145[2];
          v170 = v145[3];
          _FP27 = (float)((float)v166 - (float)v165);
          v172 = v145[4];
          v173 = v145[5];
          _FP1 = (float)((float)v168 - (float)v167);
          v175 = v145[1];
          v176 = v145[6];
          v276[8] = *v145;
          v276[1] = v162;
          v276[10] = v169;
          v276[11] = v170;
          v276[12] = v172;
          v276[13] = v173;
          __asm { fsel      f0, f27, f5, f7 }
          v276[3] = v164;
          v276[5] = _FP0;
          __asm { fsel      f13, f1, f2, f3 }
          v276[4] = _FP13;
          v276[2] = v163;
          v276[9] = v175;
          v276[14] = v176;
          clientGame->renderWorld->DebugBox(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorYellow,
            a3: (const idBox *)v276,
            a4: 0,
            a5: false);
        }
        ((void (__fastcall *)(idRenderWorld *, idColor *, _BYTE *, _BYTE *, double))clientGame->renderWorld->DebugArrow2)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorBlue,
          a3: v144 - 4,
          a4: v144 + 8,
          a5: v142);
      }
    }
    --v146;
    v143 = (idEnvironmentAnalyzer *)((char *)v143 + 8);
    v145 += 18;
    v144 += 72;
  }
  while ( v146 != 0 );
}


// ========================================================================
// `dynamic initializer for 'player_analyzeenvdebug''
// EA  : 0x83387448
// RVA : 0x01387448
// PDB : w:\tech5\tungsten\game\player\environmentanalyzer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_analyzeenvdebug__()
{
  idCVar::idCVar(
    this: &player_analyzeenvdebug,
    name: "player_analyzeenvdebug",
    value: "-1",
    flags: 2,
    description: "Debug player environment analyzer (0 for local player!)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_analyzeenvdebug__);
}

