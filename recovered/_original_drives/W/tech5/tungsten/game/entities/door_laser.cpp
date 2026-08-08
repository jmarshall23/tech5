
// ========================================================================
// ?Spawn@idDoor_Laser@@QAAXXZ
// EA  : 0x82C23570
// RVA : 0x00C23570
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void __fastcall idDoor_Laser::Spawn(idDoor_Laser *this)
{
  BOOL startDoorOpenFlag; // r11
  int num; // r30
  double v4; // fp30
  double v5; // fp31
  idPhysics *Physics; // r3
  float *v7; // r3
  idPhysics *v8; // r3
  float *v9; // r3
  const idMaterial *barMaterial; // r9
  int v11; // ctr
  int v12; // r8
  int v13; // r9
  idDoor_Laser::idDoor_LaserBar *v14; // r11
  double y; // fp27
  double v16; // fp26
  double v17; // fp11
  double v18; // fp3
  double v19; // fp2
  double v20; // fp5
  double v21; // fp4
  char v22; // r6
  float *p_z; // r10
  idPhysics *v24; // r3
  float v25; // [sp+50h] [-60h]
  float v26; // [sp+54h] [-5Ch]
  float v27; // [sp+58h] [-58h]

  startDoorOpenFlag = this->startDoorOpenFlag;
  num = this->bars.num;
  this->shouldBeOpenFlag = startDoorOpenFlag;
  if ( startDoorOpenFlag )
    v4 = 1.0;
  else
    v4 = 0.0;
  v5 = (float)(this->doorWidth * (float)0.5);
  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v25 = *v7;
  v26 = v7[1];
  v27 = v7[2];
  v8 = idEntity::GetPhysics(this);
  v9 = (float *)v8->GetAxis(this: v8, a2: 0);
  barMaterial = this->barMaterial;
  this->laserBeam.height = this->barSize;
  this->laserBeam.material = barMaterial;
  if ( num > 0 )
  {
    v11 = num;
    v12 = 0;
    do
    {
      v13 = 0;
      v14 = &this->bars.list[v12];
      y = v14->endRelativePosition.y;
      v16 = (float)(v14->endRelativePosition.x * (float)v5);
      v17 = (float)(v14->endRelativePosition.z * this->doorHeight);
      v18 = (float)((float)(v14->startRelativePosition.y * v9[1])
                  + (float)((float)(v9[4] * (float)(v14->startRelativePosition.x * (float)v5))
                          + (float)((float)(v14->startRelativePosition.z * this->doorHeight) * v9[7])));
      v19 = (float)((float)(v9[2] * v14->startRelativePosition.y)
                  + (float)((float)(v9[5] * (float)(v14->startRelativePosition.x * (float)v5))
                          + (float)(v9[8] * (float)(v14->startRelativePosition.z * this->doorHeight))));
      v14->startPosition.x = (float)((float)(v9[3] * (float)(v14->startRelativePosition.x * (float)v5))
                                   + (float)((float)(v9[6] * (float)(v14->startRelativePosition.z * this->doorHeight))
                                           + (float)(*v9 * v14->startRelativePosition.y)))
                           + v25;
      v14->startPosition.y = v26 + (float)v18;
      v14->startPosition.z = v27 + (float)v19;
      v20 = (float)((float)((float)y * v9[1]) + (float)((float)(v9[4] * (float)v16) + (float)((float)v17 * v9[7])));
      v21 = (float)((float)(*v9 * (float)y) + (float)((float)(v9[6] * (float)v17) + (float)(v9[3] * (float)v16)));
      v14->endPosition.z = (float)((float)(v9[2] * (float)y)
                                 + (float)((float)(v9[5] * (float)v16) + (float)(v9[8] * (float)v17)))
                         + v27;
      v14->endPosition.y = (float)v20 + v26;
      v14->endPosition.x = (float)v21 + v25;
      v22 = _cntlzw(v14->behavior - 1);
      v14->startOpenCloseTime = 0;
      v14->numParts = ((v22 & 0x20) != 0) + 1;
      if ( ((v22 & 0x20) != 0) != -1 )
      {
        p_z = &v14->endPosition.z;
        do
        {
          ++v13;
          *++p_z = v4;
        }
        while ( v13 < v14->numParts );
      }
      ++v12;
      --v11;
    }
    while ( v11 != 0 );
  }
  v24 = idEntity::GetPhysics(this);
  v24->SetAxis(this: v24, a2: &mat3_identity, a3: -1);
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Think@idDoor_Laser@@UAAXXZ
// EA  : 0x82C237D8
// RVA : 0x00C237D8
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDoor_Laser::Think(idDoor_Laser *this)
{
  char *v2; // r14
  int GameMs; // r3
  int num; // r7
  BOOL barsAnimatingFlag; // r10
  int v6; // r29
  int v7; // r8
  BOOL shouldBeOpenFlag; // r11
  double v9; // fp12
  idDoor_Laser::idDoor_LaserBar *v10; // r11
  int numParts; // r9
  float *openPercent; // r10
  double v13; // fp0
  double v14; // fp9
  double v15; // fp9
  double v16; // fp0
  double v17; // fp9
  double v18; // fp0
  double v19; // fp13
  double v20; // fp8
  double v21; // fp0
  int i; // ctr
  double v23; // fp0
  int v24; // r23
  idDoor_Laser::idDoor_LaserBar *v25; // r31
  float *p_x; // r27
  float *v27; // r25
  int v28; // r30
  int v29; // r28
  __int64 v30; // r11
  __int64 v31; // r9 OVERLAPPED
  unsigned int v32; // r11
  char v33; // r11
  bool v34; // zf
  __int64 v35; // r11
  double v36; // fp0
  double v37; // fp31
  int v38; // r11
  int v39; // r3
  int v40; // r3
  int v41; // r30
  float x; // r10
  float y; // r9
  float z; // r8
  double v45; // fp13
  double v46; // fp12
  double v47; // fp11
  double v48; // fp10
  double v49; // fp9
  double v50; // fp7
  idGameTimeManager *v51; // r3
  int GameMsPerFrame; // r3
  const idDeclParticle **list; // r29
  double v54; // fp1
  double v55; // fp31
  const idDeclParticle *v56; // r30
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v58; // r7
  double v59; // fp1
  __int64 v60; // r10
  const idSoundShader *passThroughSound; // r11
  char *v62; // r10
  float *p_y; // r11
  int j; // ctr
  int entityNumber; // r11
  idClip *v66; // r4
  __int64 v67; // r11
  char *v68; // r9
  int v69; // ctr
  double v70; // fp0
  int v71; // r24
  int v72; // r25
  idDoor_Laser::idDoor_LaserBar *v73; // r11
  idDoor_Laser::idDoor_LaserBar *v74; // r31
  int v75; // r10
  double v76; // fp0
  double v77; // fp13
  bool v78; // r11
  int v79; // r30
  float *v80; // r29
  float *v81; // r28
  int v82; // r10
  double v83; // fp0
  double v84; // fp11
  double v85; // fp9
  double v86; // fp8
  double v87; // fp0
  double v88; // fp13
  double v89; // fp9
  double v90; // fp8
  idAnimator_ChannelWeight *v91; // r3
  idRenderModelBeam *v92; // r3
  double v93; // fp13
  double v94; // fp12
  double v95; // fp11
  double v96; // fp10
  double v97; // fp9
  double v98; // fp8
  idRenderModelBeam *NumContacts; // r3
  int v100; // [sp+8h] [-2B8h]
  int v101; // [sp+Ch] [-2B4h]
  const char *v102; // [sp+10h] [-2B0h]
  int v103; // [sp+14h] [-2ACh]
  int v104; // [sp+18h] [-2A8h]
  int v105; // [sp+1Ch] [-2A4h]
  int v106; // [sp+20h] [-2A0h]
  int v107; // [sp+24h] [-29Ch]
  int v108; // [sp+28h] [-298h]
  int v109; // [sp+2Ch] [-294h]
  int v110; // [sp+30h] [-290h]
  int v111; // [sp+34h] [-28Ch]
  int v112; // [sp+38h] [-288h]
  int v113; // [sp+3Ch] [-284h]
  int v114; // [sp+40h] [-280h]
  int v115; // [sp+44h] [-27Ch]
  int v116; // [sp+48h] [-278h]
  int v117; // [sp+4Ch] [-274h]
  int v118; // [sp+50h] [-270h]
  int v119; // [sp+58h] [-268h]
  int v120; // [sp+60h] [-260h]
  char v121; // [sp+70h] [-250h]
  int v122; // [sp+74h] [-24Ch]
  int v123; // [sp+78h] [-248h]
  idVec3 v124; // [sp+80h] [-240h] BYREF
  __int64 v125; // [sp+90h] [-230h]
  int v126; // [sp+98h] [-228h]
  idMat3 v127; // [sp+A0h] [-220h] BYREF
  float v128; // [sp+C4h] [-1FCh]
  float v129; // [sp+C8h] [-1F8h]
  idVec3 v130; // [sp+D0h] [-1F0h] BYREF
  int v131; // [sp+DCh] [-1E4h]
  int v132; // [sp+E0h] [-1E0h]
  unsigned int v133; // [sp+E4h] [-1DCh] BYREF
  char *v134; // [sp+E8h] [-1D8h]
  idVec3 *v135; // [sp+ECh] [-1D4h]
  float v136[4]; // [sp+F0h] [-1D0h] BYREF
  idVec3 v137; // [sp+100h] [-1C0h] BYREF
  float v138; // [sp+10Ch] [-1B4h]
  float v139; // [sp+110h] [-1B0h]
  float v140; // [sp+114h] [-1ACh]
  float v141; // [sp+118h] [-1A8h]
  float v142; // [sp+11Ch] [-1A4h]
  float v143; // [sp+120h] [-1A0h]
  char v144; // [sp+128h] [-198h] BYREF
  char v145; // [sp+130h] [-190h] BYREF
  char v146; // [sp+13Ch] [-184h] BYREF
  idMat3 v147; // [sp+140h] [-180h] BYREF
  trace_t v148; // [sp+170h] [-150h] BYREF

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 )
  {
    v2 = &ai_useTurnTransitions.valueString.baseBuffer[12];
    v134 = &ai_useTurnTransitions.valueString.baseBuffer[12];
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    num = this->bars.num;
    barsAnimatingFlag = this->barsAnimatingFlag;
    v6 = GameMs;
    v122 = num;
    v132 = GameMs;
    v7 = 0;
    if ( barsAnimatingFlag )
    {
      shouldBeOpenFlag = this->shouldBeOpenFlag;
      this->barsAnimatingFlag = false;
      v9 = shouldBeOpenFlag ? 1.0 : 0.0;
      if ( num > 0 )
      {
        do
        {
          v10 = &this->bars.list[v7];
          numParts = v10->numParts;
          if ( v10->startOpenCloseTime <= GameMs )
          {
            openPercent = v10->openPercent;
            if ( v10->openPercent[0] != v9 || numParts == 2 && v10->openPercent[1] != v9 )
            {
              this->barsAnimatingFlag = true;
              if ( numParts == 1 )
              {
                v13 = *openPercent;
                if ( v13 >= v9 )
                {
                  if ( v13 > v9 )
                  {
                    v15 = (float)(*openPercent - v10->closeSpeed);
                    *openPercent = *openPercent - v10->closeSpeed;
                    if ( v15 <= 0.0 )
                      *openPercent = 0.0;
                  }
                }
                else
                {
                  v14 = (float)(v10->openSpeed + *openPercent);
                  *openPercent = v10->openSpeed + *openPercent;
                  if ( v14 >= 1.0 )
                    *openPercent = 1.0;
                }
              }
              else if ( numParts == 2 )
              {
                v16 = *openPercent;
                if ( v16 < v9 )
                {
                  v17 = (float)(v10->openSpeed + *openPercent);
                  goto LABEL_24;
                }
                if ( v16 > v9 )
                {
                  v17 = (float)(*openPercent - v10->closeSpeed);
LABEL_24:
                  *openPercent = v17;
                }
                v18 = v10->openPercent[1];
                v19 = *openPercent;
                if ( v18 < v9 )
                {
                  v20 = (float)(v10->openSpeed + v10->openPercent[1]);
                  goto LABEL_29;
                }
                if ( v18 > v9 )
                {
                  v20 = (float)(v10->openPercent[1] - v10->closeSpeed);
LABEL_29:
                  v10->openPercent[1] = v20;
                }
                v21 = (float)(v10->openPercent[1] + (float)v19);
                if ( v21 > 1.0 )
                {
                  if ( v21 < 2.0 )
                  {
                    for ( i = 2; i != 0; --i )
                    {
                      v23 = *openPercent;
                      if ( v23 >= 0.0 )
                      {
                        if ( v23 > 1.0 )
                          *openPercent = 1.0;
                      }
                      else
                      {
                        *openPercent = 0.0;
                      }
                      ++openPercent;
                    }
                  }
                  else
                  {
                    *openPercent = 1.0;
                    v10->openPercent[1] = 1.0;
                  }
                }
                else if ( v9 >= 0.5 )
                {
                  *openPercent = 0.50099999;
                  v10->openPercent[1] = 0.50099999;
                }
                else
                {
                  *openPercent = 0.0;
                  v10->openPercent[1] = 0.0;
                }
              }
            }
          }
          else
          {
            this->barsAnimatingFlag = true;
          }
          --num;
          ++v7;
        }
        while ( num != 0 );
      }
    }
    if ( this->touching.num != 0 && (!this->shouldBeOpenFlag || this->barsAnimatingFlag) )
    {
      v121 = 0;
      if ( v122 > 0 )
      {
        v126 = v122;
        v123 = 0;
        v135 = &vec3_origin;
        do
        {
          v24 = 0;
          v25 = &this->bars.list[v123];
          if ( v25->numParts > 0 )
          {
            p_x = &v25->startPosition.x;
            v27 = &v25->endPosition.x;
            do
            {
              v28 = *((_DWORD *)v2 + 4398);
              v29 = 8 * (v24 + 11);
              v30 = *(_QWORD *)((char *)&v25->behavior + v29);
              v31 = *(_QWORD *)(HIDWORD(v30) + 377208);
              if ( (unsigned int)v30 < (unsigned int)v31
                || (LODWORD(v31) = 327680, (unsigned int)v30 > *(_DWORD *)(HIDWORD(v30) + 377220)) )
              {
                v33 = 0;
              }
              else
              {
                LODWORD(v31) = idCollisionQuery::finalResultsFirstSubmittedOffset;
                v32 = *(_DWORD *)(8
                                * (HIDWORD(idCollisionQuery::finalResultsFirstSubmittedOffset) + ((2 * v30) & 0x1FFE))
                                + HIDWORD(v30)
                                + 278924);
                if ( v32 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
                  || (LODWORD(v31) = HIDWORD(idCollisionQuery::finalResultsLastSubmittedOffset),
                      v34 = v32 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset,
                      v33 = 1,
                      !v34) )
                {
                  v33 = 0;
                }
              }
              if ( v33 != 0 )
              {
                v35 = *(_QWORD *)((char *)&v25->behavior + v29);
                *(_QWORD *)((char *)&v25->behavior + v29) = *(__int64 *)((char *)&v31 - 4);
                idCollisionModelManager::GetContentsResult(
                  this: collisionModelManager,
                  result: &v148,
                  query: (idCollisionQuery *)(24 * ((v35 & 0xFFF) + 12067) + v28),
                  peek: false);
                if ( v148.fraction < 0.99900001 )
                {
                  v36 = (float)(this->barOpenExtraPercent + (float)((float)1.0 - v148.fraction));
                  if ( v36 >= 0.0 )
                  {
                    if ( v36 > 1.0 )
                      v36 = 1.0;
                  }
                  else
                  {
                    v36 = 0.0;
                  }
                  v37 = (float)(this->sparkBackExtraPercent + (float)((float)1.0 - v148.fraction));
                  if ( v37 >= 0.0 )
                  {
                    if ( v37 > 1.0 )
                      v37 = 1.0;
                  }
                  else
                  {
                    v37 = 0.0;
                  }
                  v38 = 4 * (v24 + 20);
                  if ( v36 > *(float *)((char *)&v25->behavior + v38) )
                  {
                    *(float *)((char *)&v25->behavior + v38) = v36;
                    if ( v6 >= v25->nextSparkTime )
                    {
                      v39 = this->sparkParticles.num;
                      if ( v39 != 0 )
                      {
                        v40 = RandomInt(max: v39);
                        v143 = 1.0;
                        v41 = v40;
                        v139 = 1.0;
                        v137.x = 1.0;
                        v140 = 0.0;
                        x = v135->x;
                        v137.z = 0.0;
                        y = v135->y;
                        v137.y = 0.0;
                        z = v135->z;
                        v142 = 0.0;
                        v141 = 0.0;
                        v138 = 0.0;
                        v136[0] = x;
                        v136[1] = y;
                        v136[2] = z;
                        if ( v24 != 0 )
                        {
                          v45 = *p_x;
                          v46 = v25->startPosition.y;
                          v47 = v25->startPosition.z;
                          v48 = *v27;
                          v49 = v25->endPosition.y;
                          v50 = v25->endPosition.z;
                        }
                        else
                        {
                          v45 = *v27;
                          v46 = v25->endPosition.y;
                          v47 = v25->endPosition.z;
                          v48 = *p_x;
                          v49 = v25->startPosition.y;
                          v50 = v25->startPosition.z;
                        }
                        v133 = -1;
                        v51 = (idGameTimeManager *)(*((_DWORD *)v2 + 4398) + 504064);
                        v127.mat[0].z = (float)((float)v50 * (float)v37)
                                      + (float)((float)v47 * (float)((float)1.0 - (float)v37));
                        v127.mat[0].y = (float)((float)v49 * (float)v37)
                                      + (float)((float)v46 * (float)((float)1.0 - (float)v37));
                        v127.mat[0].x = (float)((float)v37 * (float)v48)
                                      + (float)((float)((float)1.0 - (float)v37) * (float)v45);
                        GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: v51, type: GAMETIME_SCALED);
                        list = this->sparkParticles.list;
                        v131 = GameMsPerFrame;
                        v54 = RandomFloat();
                        v2 = v134;
                        v55 = v54;
                        v56 = list[v41];
                        MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: *((idAnimator_BlendEq **)v134 + 4398));
                        v6 = v132;
                        idRenderModelEffects::AddParticles(
                          this: MergeBranch,
                          particle: v56,
                          systemStartTime: v132,
                          gameMsPerFrame: v131,
                          diversity: v55,
                          origin: v58,
                          axis: &v127,
                          velocity: &v137,
                          color: v136,
                          a10: v100,
                          a11: v101,
                          a12: (int)v102,
                          a13: v103,
                          a14: v104,
                          a15: v105,
                          a16: v106,
                          a17: v107,
                          a18: v108,
                          a19: v109,
                          a20: v110,
                          a21: v111,
                          a22: v112,
                          a23: v113,
                          a24: v114,
                          a25: v115,
                          a26: v116,
                          a27: v117,
                          a28: v118,
                          a29: &v133);
                        v59 = RandomFloat(min: this->sparkDelayMin, max: this->sparkDelayMax);
                        LODWORD(v60) = v6;
                        v125 = v60;
                        v25->nextSparkTime = (int)(float)((float)((float)v59 * (float)1000.0) + (float)v60);
                      }
                    }
                  }
                  if ( !this->shouldBeOpenFlag )
                    v121 = 1;
                  if ( !this->barsAnimatingFlag )
                  {
                    passThroughSound = this->passThroughSound;
                    this->barsAnimatingFlag = true;
                    if ( passThroughSound != nullptr )
                    {
                      idEntity::StopSound(this, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
                      idEntity::StartSoundShader(
                        this,
                        channel: SND_CHANNEL_WEAPON,
                        shader: this->passThroughSound,
                        soundShaderFlags: 0,
                        peerMask: 0xFFu);
                    }
                  }
                }
                v28 = *((_DWORD *)v2 + 4398);
              }
              v62 = &v146;
              p_y = &mat2_identity.mat[1].y;
              for ( j = 9; j != 0; --j )
              {
                ++p_y;
                v62 += 4;
                *(float *)v62 = *p_y;
              }
              entityNumber = this->entityNumber;
              v66 = (idClip *)(v28 + 10688);
              if ( v24 != 0 )
                *(_QWORD *)((char *)&v25->behavior + v29) = *(_QWORD *)&idClip::Translation(
                                                                          this: (idClip *)&v145,
                                                                          result: v66,
                                                                          a3: nullptr,
                                                                          start: &v25->endPosition,
                                                                          end: &v25->startPosition,
                                                                          clipModel: nullptr,
                                                                          startAxis: &v147,
                                                                          clipMask: 103552,
                                                                          passEntityNumber: v100,
                                                                          moveClipModel: v101,
                                                                          userName: v102,
                                                                          a12: v103,
                                                                          a13: v104,
                                                                          a14: v105,
                                                                          a15: v106,
                                                                          a16: v107,
                                                                          a17: v108,
                                                                          a18: v109,
                                                                          a19: v110,
                                                                          a20: v111,
                                                                          a21: v112,
                                                                          a22: v113,
                                                                          a23: v114,
                                                                          a24: v115,
                                                                          a25: v116,
                                                                          a26: v117,
                                                                          a27: v118,
                                                                          a28: entityNumber,
                                                                          a29: v119,
                                                                          a30: false,
                                                                          a31: v120,
                                                                          a32: (int)"w:\\tech5\\tungsten\\game\\entities\\Door"
                                                                               "_Laser.cpp(275) : Translation")->world;
              else
                v25->clipQuery[0].index = *(_QWORD *)&idClip::Translation(
                                                        this: (idClip *)&v144,
                                                        result: v66,
                                                        a3: nullptr,
                                                        start: &v25->startPosition,
                                                        end: &v25->endPosition,
                                                        clipModel: nullptr,
                                                        startAxis: &v147,
                                                        clipMask: 103552,
                                                        passEntityNumber: v100,
                                                        moveClipModel: v101,
                                                        userName: v102,
                                                        a12: v103,
                                                        a13: v104,
                                                        a14: v105,
                                                        a15: v106,
                                                        a16: v107,
                                                        a17: v108,
                                                        a18: v109,
                                                        a19: v110,
                                                        a20: v111,
                                                        a21: v112,
                                                        a22: v113,
                                                        a23: v114,
                                                        a24: v115,
                                                        a25: v116,
                                                        a26: v117,
                                                        a27: v118,
                                                        a28: entityNumber,
                                                        a29: v119,
                                                        a30: false,
                                                        a31: v120,
                                                        a32: (int)"w:\\tech5\\tungsten\\game\\entities\\Door_Laser.cpp(268) : Translation")->world;
              ++v24;
            }
            while ( v24 < v25->numParts );
          }
          ++v123;
          v34 = v126-- != 1;
        }
        while ( v34 );
      }
      if ( v121 != 0 )
      {
        HIDWORD(v67) = 0;
        if ( v122 >= 4 )
        {
          v67 = (unsigned int)v6;
          v125 = (unsigned int)v6;
          LODWORD(v67) = 0;
          do
          {
            HIDWORD(v67) += 4;
            *(_DWORD *)((char *)&this->bars.list->clipQuery[2].index + v67) = (int)(float)((float)(*(float *)((char *)&this->bars.list->recloseDelay + v67)
                                                                                                 * (float)1000.0)
                                                                                         + (float)(unsigned int)v6);
            *(_DWORD *)((char *)&this->bars.list[1].clipQuery[2].index + v67) = (int)(float)((float)(*(float *)((char *)&this->bars.list[1].recloseDelay + v67) * (float)1000.0)
                                                                                           + (float)(unsigned int)v6);
            *(_DWORD *)((char *)&this->bars.list[2].clipQuery[2].index + v67) = (int)(float)((float)(*(float *)((char *)&this->bars.list[2].recloseDelay + v67) * (float)1000.0)
                                                                                           + (float)(unsigned int)v6);
            v68 = (char *)this->bars.list + v67;
            LODWORD(v67) = v67 + 448;
            *((_DWORD *)v68 + 110) = (int)(float)((float)(*((float *)v68 + 95) * (float)1000.0) + (float)(unsigned int)v6);
          }
          while ( SHIDWORD(v67) < v122 - 3 );
        }
        if ( SHIDWORD(v67) < v122 )
        {
          LODWORD(v67) = v6;
          v125 = v67;
          v69 = v122 - HIDWORD(v67);
          v70 = (float)v67;
          LODWORD(v67) = 112 * HIDWORD(v67);
          do
          {
            HIDWORD(v67) = (char *)this->bars.list + v67;
            LODWORD(v67) = v67 + 112;
            *(_DWORD *)(HIDWORD(v67) + 104) = (int)(float)((float)(*(float *)(HIDWORD(v67) + 44) * (float)1000.0)
                                                         + (float)v70);
            --v69;
          }
          while ( v69 != 0 );
        }
      }
    }
    if ( this->barsAnimatingFlag || !this->shouldBeOpenFlag )
    {
      v71 = v122;
      if ( v122 > 0 )
      {
        v72 = 0;
        do
        {
          v73 = this->bars.list;
          v74 = &v73[v72];
          v75 = v73[v72].numParts;
          v76 = v73[v72].openPercent[0];
          if ( v75 == 1 )
          {
            v77 = 1.0;
            v78 = true;
          }
          else
          {
            v77 = v74->openPercent[1];
            v78 = (float)((float)((float)2.0 - v73[v72].openPercent[0]) - v74->openPercent[1]) >= 1.0;
          }
          if ( v76 < 1.0 || v75 != 1 && v77 < 1.0 )
          {
            if ( v78 || v76 <= 0.0 || v76 >= 1.0 || v77 <= 0.0 || v77 >= 1.0 )
            {
              if ( v75 == 1 || v76 > 0.0 && v76 < 1.0 )
              {
                v93 = v74->startPosition.x;
                v127.mat[2].z = v74->startPosition.x;
                v94 = v74->startPosition.y;
                v128 = v74->startPosition.y;
                v95 = v74->startPosition.z;
                v129 = v74->startPosition.z;
                v96 = v74->endPosition.x;
                v124.x = v74->endPosition.x;
                v97 = v74->endPosition.y;
                v124.y = v74->endPosition.y;
                v98 = v74->endPosition.z;
              }
              else
              {
                v76 = v77;
                v93 = v74->endPosition.x;
                v127.mat[2].z = v74->endPosition.x;
                v94 = v74->endPosition.y;
                v128 = v74->endPosition.y;
                v95 = v74->endPosition.z;
                v129 = v74->endPosition.z;
                v96 = v74->startPosition.x;
                v124.x = v74->startPosition.x;
                v97 = v74->startPosition.y;
                v124.y = v74->startPosition.y;
                v98 = v74->startPosition.z;
              }
              v124.z = v98;
              if ( v76 > 0.0 )
              {
                v124.x = (float)((float)v93 * (float)v76) + (float)((float)((float)1.0 - (float)v76) * (float)v96);
                v124.y = (float)((float)v94 * (float)v76) + (float)((float)v97 * (float)((float)1.0 - (float)v76));
                v124.z = (float)((float)v95 * (float)v76) + (float)((float)v98 * (float)((float)1.0 - (float)v76));
              }
              NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: *((idAnimator_ChannelWeight **)v2
                                                                                             + 4398));
              idLaserBeam::Update(
                this: &this->laserBeam,
                beamEffects: NumContacts,
                startPos: (const idVec3 *)&v127.mat[2].z,
                endPos: &v124,
                fade: 1.0);
            }
            else
            {
              v79 = 0;
              if ( v75 > 0 )
              {
                v80 = &v74->endPosition.x;
                v81 = &v74->startPosition.x;
                do
                {
                  v82 = 4 * (v79 + 20);
                  v83 = *(float *)((char *)&v74->behavior + v82);
                  v84 = (float)((float)1.0 - *(float *)((char *)&v74->behavior + v82));
                  if ( v79 != 0 )
                  {
                    v127.mat[1].y = *v80;
                    v89 = (float)(v74->endPosition.y * (float)v83);
                    v127.mat[1].z = v74->endPosition.y;
                    v90 = (float)(v74->endPosition.z * (float)v83);
                    v127.mat[2].x = v74->endPosition.z;
                    v88 = (float)((float)v90 + (float)((float)v84 * v74->startPosition.z));
                    v87 = (float)((float)(v127.mat[1].y * (float)v83) + (float)((float)v84 * *v81));
                    v130.y = (float)v89 + (float)((float)v84 * v74->startPosition.y);
                  }
                  else
                  {
                    v127.mat[1].y = *v81;
                    v85 = (float)(v74->startPosition.y * (float)v83);
                    v127.mat[1].z = v74->startPosition.y;
                    v86 = (float)(v74->startPosition.z * (float)v83);
                    v127.mat[2].x = v74->startPosition.z;
                    v87 = (float)((float)(v127.mat[1].y * (float)v83) + (float)((float)v84 * *v80));
                    v88 = (float)((float)v86 + (float)((float)v84 * v74->endPosition.z));
                    v130.y = (float)v85 + (float)((float)v84 * v74->endPosition.y);
                  }
                  v130.z = v88;
                  v91 = *((idAnimator_ChannelWeight **)v2 + 4398);
                  v130.x = v87;
                  v92 = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: v91);
                  idLaserBeam::Update(
                    this: &this->laserBeam,
                    beamEffects: v92,
                    startPos: (const idVec3 *)&v127.mat[1].y,
                    endPos: &v130,
                    fade: 1.0);
                  ++v79;
                }
                while ( v79 < v74->numParts );
              }
            }
          }
          --v71;
          ++v72;
        }
        while ( v71 != 0 );
      }
    }
  }
}


// ========================================================================
// ?StartAnimatingIfNecessary@idDoor_Laser@@QAAXXZ
// EA  : 0x82C24230
// RVA : 0x00C24230
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void __fastcall idDoor_Laser::StartAnimatingIfNecessary(idDoor_Laser *this)
{
  __int64 v2; // r11
  int GameMs; // r3
  int num; // r5
  int v5; // r7
  int v6; // r10
  double v7; // fp13
  idDoor_Laser::idDoor_LaserBar *v8; // r11
  double openDelay; // fp12
  idDoor_Laser::idDoor_LaserBar *v10; // r11
  double closeDelay; // fp12
  idDoor_Laser::idDoor_LaserBar *v12; // r9
  double v13; // fp12
  idDoor_Laser::idDoor_LaserBar *v14; // r11
  double v15; // fp12
  __int64 v16; // r11
  int v17; // r11
  int v18; // ctr
  double v19; // fp12
  idDoor_Laser::idDoor_LaserBar *v20; // r10
  double v21; // fp13

  if ( !this->barsAnimatingFlag )
  {
    this->barsAnimatingFlag = true;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    num = this->bars.num;
    v5 = 0;
    if ( num >= 4 )
    {
      LODWORD(v2) = GameMs;
      v7 = (float)v2;
      v6 = 0;
      do
      {
        v8 = &this->bars.list[v6];
        if ( this->shouldBeOpenFlag )
          openDelay = v8->openDelay;
        else
          openDelay = v8->closeDelay;
        v8->startOpenCloseTime = (int)(float)((float)((float)openDelay * (float)1000.0) + (float)v7);
        v10 = &this->bars.list[v6];
        if ( this->shouldBeOpenFlag )
          closeDelay = v10[1].openDelay;
        else
          closeDelay = v10[1].closeDelay;
        v10[1].startOpenCloseTime = (int)(float)((float)((float)closeDelay * (float)1000.0) + (float)v7);
        v12 = &this->bars.list[v6 + 2];
        if ( this->shouldBeOpenFlag )
          v13 = v12->openDelay;
        else
          v13 = v12->closeDelay;
        v12->startOpenCloseTime = (int)(float)((float)((float)v13 * (float)1000.0) + (float)v7);
        v14 = &this->bars.list[v6 + 3];
        if ( this->shouldBeOpenFlag )
          v15 = v14->openDelay;
        else
          v15 = v14->closeDelay;
        v5 += 4;
        v6 += 4;
        v14->startOpenCloseTime = (int)(float)((float)((float)v15 * (float)1000.0) + (float)v7);
      }
      while ( v5 < num - 3 );
    }
    if ( v5 < num )
    {
      LODWORD(v16) = GameMs;
      HIDWORD(v16) = num - v5;
      v18 = num - v5;
      v19 = (float)v16;
      v17 = v5;
      do
      {
        v20 = &this->bars.list[v17];
        if ( this->shouldBeOpenFlag )
          v21 = v20->openDelay;
        else
          v21 = v20->closeDelay;
        ++v17;
        v20->startOpenCloseTime = (int)(float)((float)((float)v21 * (float)1000.0) + (float)v19);
        --v18;
      }
      while ( v18 != 0 );
    }
  }
}


// ========================================================================
// ?Open@idDoor_Laser@@QAAXXZ
// EA  : 0x82C243E8
// RVA : 0x00C243E8
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void __fastcall idDoor_Laser::Open(idDoor_Laser *this)
{
  const idSoundShader *openSound; // r11

  if ( !this->shouldBeOpenFlag )
  {
    openSound = this->openSound;
    this->shouldBeOpenFlag = true;
    if ( openSound != nullptr )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_WEAPON,
        shader: this->openSound,
        soundShaderFlags: 0,
        peerMask: 0xFFu);
    }
    idDoor_Laser::StartAnimatingIfNecessary(this);
  }
}


// ========================================================================
// ?Close@idDoor_Laser@@QAAXXZ
// EA  : 0x82C24460
// RVA : 0x00C24460
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void __fastcall idDoor_Laser::Close(idDoor_Laser *this)
{
  const idSoundShader *closeSound; // r11

  if ( this->shouldBeOpenFlag )
  {
    closeSound = this->closeSound;
    this->shouldBeOpenFlag = false;
    if ( closeSound != nullptr )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_WEAPON,
        shader: this->closeSound,
        soundShaderFlags: 0,
        peerMask: 0xFFu);
    }
    idDoor_Laser::StartAnimatingIfNecessary(this);
  }
}


// ========================================================================
// ?Event_Close@idDoor_Laser@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C244D8
// RVA : 0x00C244D8
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

idDoor_Laser *__fastcall idDoor_Laser::Event_Close(idDoor_Laser *this, idDoor_Laser *result)
{
  idDoor_Laser::Close(this: result);
  return this;
}


// ========================================================================
// ?Event_Disable@idDoor_Laser@@QAA?AVeventVoid@@XZ
// EA  : 0x82C24510
// RVA : 0x00C24510
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

idDoor_Laser *__fastcall idDoor_Laser::Event_Disable(idDoor_Laser *this, idDoor_Laser *result)
{
  idDoor_Laser::Open(this: result);
  return this;
}


// ========================================================================
// ?Event_Activate@idDoor_Laser@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C24548
// RVA : 0x00C24548
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

idDoor_Laser *__fastcall idDoor_Laser::Event_Activate(idDoor_Laser *this, idDoor_Laser *result, idEntity *dummy)
{
  if ( result->shouldBeOpenFlag )
    idDoor_Laser::Close(this: result);
  else
    idDoor_Laser::Open(this: result);
  return this;
}


// ========================================================================
// ?OnActivate@idDoor_Laser@@UAAXPAVidEntity@@@Z
// EA  : 0x82C24590
// RVA : 0x00C24590
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void __fastcall idDoor_Laser::OnActivate(idDoor_Laser *this, idEntity *dummy)
{
  if ( this->shouldBeOpenFlag )
    idDoor_Laser::Close(this);
  else
    idDoor_Laser::Open(this);
}


// ========================================================================
// ??0idDoor_Laser@@QAA@XZ
// EA  : 0x82C245B0
// RVA : 0x00C245B0
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

idDoor_Laser *__fastcall idDoor_Laser::idDoor_Laser(idDoor_Laser *this)
{
  idVolume::idVolume(this);
  this->__vftable = (idDoor_Laser_vtbl *)&idDoor_Laser::`vftable';
  this->doorWidth = 100.0;
  this->startDoorOpenFlag = false;
  this->doorHeight = 100.0;
  this->openSound = nullptr;
  this->barSize = 1.0;
  this->closeSound = nullptr;
  this->passThroughSound = nullptr;
  this->barMaterial = nullptr;
  this->sparkParticles.list = nullptr;
  this->sparkParticles.granularity = 0;
  this->sparkParticles.memTag = 5;
  this->sparkParticles.listStatic = 0;
  this->sparkParticles.size = 0;
  this->sparkParticles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sparkParticles);
  this->sparkDelayMin = 0.25;
  this->sparkDelayMax = 0.5;
  this->barOpenExtraPercent = 0.0;
  this->sparkBackExtraPercent = 0.0;
  this->bars.list = nullptr;
  this->bars.granularity = 0;
  this->bars.memTag = 5;
  this->bars.listStatic = 0;
  this->bars.size = 0;
  this->bars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bars);
  this->shouldBeOpenFlag = false;
  idLaserBeam::idLaserBeam(this: &this->laserBeam);
  this->barsAnimatingFlag = false;
  return this;
}


// ========================================================================
// __unwind$489103_0
// EA  : 0x82C24694
// RVA : 0x00C24694
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void _unwind_489103_0()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489104
// EA  : 0x82C246BC
// RVA : 0x00C246BC
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void _unwind_489104()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 856));
}


// ========================================================================
// __unwind$489105
// EA  : 0x82C246E8
// RVA : 0x00C246E8
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void _unwind_489105()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 888));
}


// ========================================================================
// ??1idDoor_Laser@@UAA@XZ
// EA  : 0x82C24720
// RVA : 0x00C24720
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void __fastcall idDoor_Laser::~idDoor_Laser(idDoor_Laser *this)
{
  this->__vftable = (idDoor_Laser_vtbl *)&idDoor_Laser::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bars);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sparkParticles);
  idVolume::~idVolume(this);
}


// ========================================================================
// __unwind$489345
// EA  : 0x82C2477C
// RVA : 0x00C2477C
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void _unwind_489345()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489346_0
// EA  : 0x82C247A4
// RVA : 0x00C247A4
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void _unwind_489346_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 856));
}


// ========================================================================
// ?Hide@idDoor_Laser@@UAAXXZ
// EA  : 0x82C247D0
// RVA : 0x00C247D0
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

// attributes: thunk
void __fastcall idDoor_Laser::Hide(idDoor_Laser *this)
{
  idDoor_Laser::Open(this);
}


// ========================================================================
// ?Show@idDoor_Laser@@UAAXXZ
// EA  : 0x82C247D8
// RVA : 0x00C247D8
// PDB : w:\tech5\tungsten\game\entities\door_laser.cpp
// ========================================================================

void __fastcall idDoor_Laser::Show(idDoor_Laser *this)
{
  idDoor_Laser::Close(this);
  idEntity::Show(this);
}

