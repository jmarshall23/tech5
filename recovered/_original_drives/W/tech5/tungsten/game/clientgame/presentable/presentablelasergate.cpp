
// ========================================================================
// ?PowerUp@idPresentableLaserGate@@QAAXXZ
// EA  : 0x82B6FC20
// RVA : 0x00B6FC20
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::PowerUp(idPresentableLaserGate *this)
{
  this->requestedGateState = LASERGATE_CLOSING;
  this->gateActivationTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?PowerDown@idPresentableLaserGate@@QAAXXZ
// EA  : 0x82B6FC70
// RVA : 0x00B6FC70
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::PowerDown(idPresentableLaserGate *this)
{
  int GameMs; // r3

  this->requestedGateState = LASERGATE_OPENING;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->gateActivationTime = GameMs;
  this->shutdownTime = GameMs;
}


// ========================================================================
// ?UpdateBeams@idPresentableLaserGate@@QAAXXZ
// EA  : 0x82B6FCC0
// RVA : 0x00B6FCC0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::UpdateBeams(idPresentableLaserGate *this, idFXManager *p_point2)
{
  int v2; // r5
  idVec3 *p_origin; // r10
  int v4; // r6
  int v5; // r7
  laserGateBeamInfo_t *v6; // r8
  idLaserGateBeam *v7; // r9
  double y; // fp12
  double z; // fp31
  double v10; // fp7
  double v11; // fp6
  laserGateBeamInfo_t *v12; // r9
  double x; // fp5
  double v14; // fp3
  idLaserGateBeam *v15; // r8
  double v16; // fp12
  double v17; // fp11

  v2 = 0;
  if ( this->laserBeams.num > 0 )
  {
    p_origin = &this->origin;
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = &this->laserEndPoints.list[v5];
      v7 = &this->laserBeams.list[v4];
      ++v2;
      y = this->origin.y;
      z = this->origin.z;
      v10 = (float)((float)(this->axis.mat[2].y * v6->point1.z)
                  + (float)((float)(v6->point1.y * this->axis.mat[1].y) + (float)(this->axis.mat[0].y * v6->point1.x)));
      v11 = (float)((float)(v6->point1.z * this->axis.mat[2].z)
                  + (float)((float)(this->axis.mat[1].z * v6->point1.y) + (float)(v6->point1.x * this->axis.mat[0].z)));
      v7->point1.x = p_origin->x
                   + (float)((float)(v6->point1.z * this->axis.mat[2].x)
                           + (float)((float)(v6->point1.x * this->axis.mat[0].x)
                                   + (float)(v6->point1.y * this->axis.mat[1].x)));
      v7->point1.y = (float)y + (float)v10;
      v7->point1.z = (float)z + (float)v11;
      v12 = &this->laserEndPoints.list[v5++];
      x = p_origin->x;
      v14 = this->origin.z;
      v15 = &this->laserBeams.list[v4++];
      p_point2 = (idFXManager *)&v15->point2;
      v16 = (float)((float)(v12->point2.z * this->axis.mat[2].x)
                  + (float)((float)(v12->point2.x * this->axis.mat[0].x) + (float)(v12->point2.y * this->axis.mat[1].x)));
      v17 = (float)((float)(v12->point2.z * this->axis.mat[2].z)
                  + (float)((float)(this->axis.mat[1].z * v12->point2.y) + (float)(v12->point2.x * this->axis.mat[0].z)));
      v15->point2.y = this->origin.y
                    + (float)((float)(this->axis.mat[2].y * v12->point2.z)
                            + (float)((float)(v12->point2.y * this->axis.mat[1].y)
                                    + (float)(this->axis.mat[0].y * v12->point2.x)));
      v15->point2.x = (float)x + (float)v16;
      v15->point2.z = (float)v14 + (float)v17;
    }
    while ( v2 < this->laserBeams.num );
  }
  idPresentable::UpdateFX(this, fovScale: 1.0, depthHack: 0.0, fxManager: p_point2, a5: v2, a6: &this->fxManager);
}


// ========================================================================
// ?EnterDormancy@idPresentableLaserGate@@QAAXXZ
// EA  : 0x82B6FE50
// RVA : 0x00B6FE50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::EnterDormancy(idPresentableLaserGate *this)
{
  idFXManager *p_fxManager; // r27
  int v2; // r30
  int *v3; // r29
  int GameMs; // r3
  int v5; // r3
  _DWORD v7[54]; // [sp+58h] [-D8h] BYREF

  p_fxManager = &this->fxManager;
  v2 = 0;
  if ( this->laserBeams.num > 0 )
  {
    v3 = v7;
    do
    {
      if ( v2 >= 7 )
        break;
      v7[3] = 162;
      v7[2] = 161;
      v7[4] = 163;
      v7[5] = 164;
      v7[6] = 165;
      v7[7] = 166;
      v7[8] = 167;
      v7[9] = 168;
      v7[10] = 169;
      v7[11] = 170;
      v7[12] = 171;
      v7[13] = 172;
      v7[14] = 173;
      v7[15] = 174;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFXManager::LocalStopFX(this: p_fxManager, time: GameMs, stop: v3[3], immediateStop: false);
      v5 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v3 += 2;
      idFXManager::LocalStopFX(this: p_fxManager, time: v5, stop: *v3, immediateStop: false);
      ++v2;
    }
    while ( v2 < this->laserBeams.num );
  }
}


// ========================================================================
// ?LeaveDormancy@idPresentableLaserGate@@QAAXXZ
// EA  : 0x82B6FF68
// RVA : 0x00B6FF68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::LeaveDormancy(idPresentableLaserGate *this)
{
  laserGateState_t requestedGateState; // r11
  idFXManager *p_fxManager; // r25
  int v4; // r27
  int v5; // r31
  int *v6; // r28
  idLaserGateBeam *list; // r11
  float *v8; // r11
  double v9; // fp0
  double v10; // fp13
  double v11; // fp12
  double v12; // fp10
  unsigned int GameMs; // r3
  unsigned int v14; // r3
  idMat3 v15; // [sp+50h] [-110h] BYREF
  float v16; // [sp+74h] [-ECh]
  _DWORD v17[54]; // [sp+88h] [-D8h] BYREF

  requestedGateState = this->requestedGateState;
  p_fxManager = &this->fxManager;
  if ( requestedGateState == LASERGATE_CLOSED || requestedGateState == LASERGATE_CLOSING )
  {
    v4 = 0;
    if ( this->laserBeams.num > 0 )
    {
      v5 = 0;
      v6 = v17;
      do
      {
        if ( v5 >= 7 )
          break;
        list = this->laserBeams.list;
        v17[5] = 150;
        v8 = (float *)&list[v5];
        v17[2] = 147;
        v17[3] = 148;
        v17[6] = 151;
        v17[4] = 149;
        v17[7] = 152;
        v9 = v8[7];
        v17[8] = 153;
        v10 = v8[4];
        v17[9] = 154;
        v11 = v8[6];
        v12 = v8[3];
        v17[10] = 155;
        v15.mat[0].x = v8[5] - v8[2];
        v17[11] = 156;
        v15.mat[0].z = (float)v9 - (float)v10;
        v17[12] = 157;
        v15.mat[0].y = (float)v11 - (float)v12;
        v17[13] = 158;
        v17[14] = 159;
        v17[15] = 160;
        idVec3::ToMat3(this: (idVec3 *)&v15.mat[1].y, result: &v15);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idFXManager::LocalStartFX(
          this: p_fxManager,
          org: &this->laserBeams.list[v5].point2,
          axis: (idMat3 *)&v15.mat[1].y,
          time: GameMs,
          start: v6[3]);
        v15.mat[1].y = -v15.mat[1].y;
        v15.mat[1].z = -v15.mat[1].z;
        v15.mat[2].x = -v15.mat[2].x;
        v15.mat[2].y = -v15.mat[2].y;
        v15.mat[2].z = -v15.mat[2].z;
        v16 = -v16;
        v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v6 += 2;
        idFXManager::LocalStartFX(
          this: p_fxManager,
          org: &this->laserBeams.list[v5].point1,
          axis: (idMat3 *)&v15.mat[1].y,
          time: v14,
          start: *v6);
        ++v4;
        ++v5;
      }
      while ( v4 < this->laserBeams.num );
    }
  }
}


// ========================================================================
// ??1idPresentableLaserGate@@UAA@XZ
// EA  : 0x82B70438
// RVA : 0x00B70438
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::~idPresentableLaserGate(idPresentableLaserGate *this)
{
  this->__vftable = (idPresentableLaserGate_vtbl *)&idPresentableLaserGate::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->laserEndPoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->laserBeams);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$489527
// EA  : 0x82B70494
// RVA : 0x00B70494
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void _unwind_489527()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489528
// EA  : 0x82B704BC
// RVA : 0x00B704BC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void _unwind_489528()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1220));
}


// ========================================================================
// ?BuildBeams@idPresentableLaserGate@@IAAXXZ
// EA  : 0x82B70678
// RVA : 0x00B70678
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::BuildBeams(idPresentableLaserGate *this)
{
  int num; // r29
  idList<idLaserGateBeam,5> *p_laserBeams; // r30
  int size; // r11
  int v5; // r5
  idVec3 *p_origin; // r9
  int v7; // r10
  int v8; // r6
  laserGateBeamInfo_t *v9; // r7
  float *v10; // r8
  double y; // fp1
  double z; // fp0
  double v13; // fp8
  double v14; // fp7
  laserGateBeamInfo_t *v15; // r8
  float *v16; // r7
  double v17; // fp8
  double v18; // fp4
  double v19; // fp7
  double v20; // fp11

  num = this->laserEndPoints.num;
  p_laserBeams = &this->laserBeams;
  if ( num <= this->laserBeams.size
    || (unsigned __int8)idList<idLaserGateBeam,5>::Resize(this: &this->laserBeams, newsize: this->laserEndPoints.num) != 0 )
  {
    size = p_laserBeams->size;
    if ( num < size )
      size = num;
    p_laserBeams->num = size;
  }
  v5 = 0;
  if ( this->laserBeams.num > 0 )
  {
    p_origin = &this->origin;
    v7 = 0;
    v8 = 0;
    do
    {
      ++v5;
      p_laserBeams->list[v7].beam.material = this->laserGateDecl->laserBeamMtr;
      p_laserBeams->list[v7].beam.height = this->laserGateDecl->laserBeamHeight;
      v9 = &this->laserEndPoints.list[v8];
      v10 = (float *)&p_laserBeams->list[v7];
      y = this->origin.y;
      z = this->origin.z;
      v13 = (float)((float)(this->axis.mat[1].y * v9->point1.y)
                  + (float)((float)(this->axis.mat[0].y * v9->point1.x) + (float)(this->axis.mat[2].y * v9->point1.z)));
      v14 = (float)((float)(v9->point1.y * this->axis.mat[1].z)
                  + (float)((float)(v9->point1.x * this->axis.mat[0].z) + (float)(v9->point1.z * this->axis.mat[2].z)));
      v10[2] = (float)((float)(this->axis.mat[1].x * v9->point1.y)
                     + (float)((float)(v9->point1.z * this->axis.mat[2].x) + (float)(this->axis.mat[0].x * v9->point1.x)))
             + p_origin->x;
      v10[3] = (float)y + (float)v13;
      v10[4] = (float)z + (float)v14;
      v15 = &this->laserEndPoints.list[v8];
      v16 = (float *)&p_laserBeams->list[v7];
      v17 = this->origin.y;
      v18 = this->origin.z;
      v19 = (float)((float)(v15->point2.y * this->axis.mat[1].z)
                  + (float)((float)(v15->point2.x * this->axis.mat[0].z) + (float)(v15->point2.z * this->axis.mat[2].z)));
      v20 = (float)((float)(this->axis.mat[1].y * v15->point2.y)
                  + (float)((float)(this->axis.mat[0].y * v15->point2.x) + (float)(this->axis.mat[2].y * v15->point2.z)));
      v16[5] = (float)((float)(this->axis.mat[1].x * v15->point2.y)
                     + (float)((float)(v15->point2.z * this->axis.mat[2].x)
                             + (float)(this->axis.mat[0].x * v15->point2.x)))
             + p_origin->x;
      v16[7] = (float)v18 + (float)v19;
      v16[6] = (float)v17 + (float)v20;
      ++v8;
      ++v7;
    }
    while ( v5 < this->laserBeams.num );
  }
}


// ========================================================================
// ?UpdateLaserBeams@idLaserGateBeam@@QAAXW4laserGateState_t@@HHM@Z
// EA  : 0x82B70858
// RVA : 0x00B70858
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idLaserGateBeam::UpdateLaserBeams(
        idLaserGateBeam *this,
        laserGateState_t parentState,
        unsigned int beamPowerUpTime,
        int startTime,
        double maxBeamHeight)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  char v12; // r25
  int GameMs; // r3
  __int128 v14; // r10
  __int64 v15; // fp13
  double v16; // fp0
  laserGateState_t state; // r11
  laserGateState_t v18; // r11
  idRenderModelBeam *NumContacts; // r3
  idPLogScope v20[2]; // [sp+58h] [-68h] BYREF

  RD_EventBegin(name: "idLaserGateBeam::UpdateLaserBeams");
  LODWORD(v10) = "idLaserGateBeam::UpdateLaserBeams";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: v20, pl: &pLog, gMask: v10, label: v11);
  v12 = 1;
  if ( parentState <= LASERGATE_OPENED && this->state == LASERGATE_OPENED
    || parentState >= LASERGATE_CLOSING && this->state == LASERGATE_CLOSED )
  {
    v12 = 0;
    goto LABEL_14;
  }
  if ( parentState == LASERGATE_OPENING )
  {
    if ( this->state <= LASERGATE_OPENED )
      goto LABEL_14;
    goto LABEL_11;
  }
  if ( parentState == LASERGATE_CLOSING && this->state < LASERGATE_CLOSING )
  {
LABEL_11:
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) <= startTime )
      v12 = 0;
    else
      this->state = parentState;
  }
LABEL_14:
  if ( v12 == 0 )
    goto LABEL_27;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  LODWORD(v14) = beamPowerUpTime;
  v15 = v14;
  DWORD2(v14) = startTime;
  v16 = (float)((float)((float)__SPAIR64__(beamPowerUpTime, GameMs) - (float)*(__int64 *)((char *)&v14 + 4)) / (float)v15);
  if ( v16 >= 0.0 )
  {
    if ( v16 > 1.0 )
      v16 = 1.0;
  }
  else
  {
    v16 = 0.0;
  }
  state = this->state;
  if ( state != LASERGATE_CLOSING )
  {
    if ( state != LASERGATE_OPENING )
      goto LABEL_26;
    v16 = (float)((float)1.0 - (float)v16);
    if ( v16 >= 0.000099999997 )
      goto LABEL_26;
    v18 = LASERGATE_OPENED;
    v16 = 0.0;
    goto LABEL_25;
  }
  if ( v16 > 0.99900001 )
  {
    v18 = LASERGATE_CLOSED;
    v16 = 1.0;
LABEL_25:
    this->state = v18;
  }
LABEL_26:
  this->beam.height = (float)v16 * (float)maxBeamHeight;
LABEL_27:
  if ( this->state != LASERGATE_OPENED )
  {
    NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
    idLaserBeam::Update(
      this: &this->beam,
      beamEffects: NumContacts,
      startPos: &this->point1,
      endPos: &this->point2,
      fade: 1.0);
  }
  idPLogScope::~idPLogScope(this: v20);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489824
// EA  : 0x82B70A70
// RVA : 0x00B70A70
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void _unwind_489824()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$489825
// EA  : 0x82B70A98
// RVA : 0x00B70A98
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void _unwind_489825()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// ??0idPresentableLaserGate@@QAA@PAVidEntity@@PAVidRenderModel@@HPBVidDeclLaserGate@@ABV?$idList@UlaserGateBeamInfo_t@@$04@@PBVidDeclFX@@@Z
// EA  : 0x82B70AC8
// RVA : 0x00B70AC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

idPresentableLaserGate *__fastcall idPresentableLaserGate::idPresentableLaserGate(
        idPresentableLaserGate *this,
        idEntity *e,
        idTreeAnimator *renderModel_,
        int entityNumber_,
        const idDeclLaserGate *laserGateInfo,
        const idList<laserGateBeamInfo_t,5> *laserEndPoints_,
        const idDeclFX *overrideFXDecl)
{
  const idDeclFX *fxDecl; // r7
  unsigned __int64 v12; // r28

  fxDecl = overrideFXDecl;
  if ( overrideFXDecl == nullptr )
    fxDecl = laserGateInfo->fxDecl;
  idPresentable::idPresentable(this, e, renderModel_, entityNumber_, fxDecl_: fxDecl);
  LODWORD(v12) = 0;
  this->__vftable = (idPresentableLaserGate_vtbl *)&idPresentableLaserGate::`vftable';
  this->laserBeams.list = nullptr;
  this->laserBeams.granularity = 0;
  this->laserBeams.memTag = 5;
  this->laserBeams.listStatic = 0;
  this->laserBeams.size = 0;
  this->laserBeams.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->laserBeams);
  this->laserEndPoints.memTag = 5;
  this->laserEndPoints.list = nullptr;
  HIDWORD(v12) = &this->laserEndPoints;
  this->laserEndPoints.granularity = 0;
  this->laserEndPoints.listStatic = 0;
  this->laserEndPoints.size = 0;
  this->laserEndPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->laserEndPoints);
  this->gatherQuery.index = v12;
  this->origin.x = e->spawnPosition.x;
  this->origin.y = e->spawnPosition.y;
  this->origin.z = e->spawnPosition.z;
  this->axis.mat[0].x = e->spawnOrientation.mat[0].x;
  this->axis.mat[0].y = e->spawnOrientation.mat[0].y;
  this->axis.mat[0].z = e->spawnOrientation.mat[0].z;
  this->axis.mat[1].x = e->spawnOrientation.mat[1].x;
  this->axis.mat[1].y = e->spawnOrientation.mat[1].y;
  this->axis.mat[1].z = e->spawnOrientation.mat[1].z;
  this->axis.mat[2].x = e->spawnOrientation.mat[2].x;
  this->axis.mat[2].y = e->spawnOrientation.mat[2].y;
  this->axis.mat[2].z = e->spawnOrientation.mat[2].z;
  this->laserGateDecl = laserGateInfo;
  idList<laserGateBeamInfo_t,5>::operator=(this: &this->laserEndPoints, other: laserEndPoints_);
  this->gateActivationTime = 0;
  this->currentGateState = LASERGATE_OPENED;
  this->requestedGateState = LASERGATE_OPENED;
  idPresentableLaserGate::BuildBeams(this);
  return this;
}


// ========================================================================
// __unwind$489881
// EA  : 0x82B70C40
// RVA : 0x00B70C40
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void _unwind_489881()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$489882
// EA  : 0x82B70C68
// RVA : 0x00B70C68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void _unwind_489882()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1220));
}


// ========================================================================
// __unwind$489883
// EA  : 0x82B70C94
// RVA : 0x00B70C94
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void _unwind_489883()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1236));
}


// ========================================================================
// ?SerializeBeams@idPresentableLaserGate@@IAAXAAVidSerializer@@_N@Z
// EA  : 0x82B70CC0
// RVA : 0x00B70CC0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::SerializeBeams(
        idPresentableLaserGate *this,
        idSerializer *ser,
        bool firstTimeIn)
{
  int num; // r29
  idBitMsg *msg; // r3
  int v8; // r30
  idBitMsg *v9; // r3
  laserGateBeamInfo_t *v10; // r4
  idBitMsg *v11; // r3
  idVec3 *p_point2; // r4

  num = this->laserEndPoints.num;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: num, numBits: 32);
  else
    num = idBitMsg::ReadBits(this: msg, numBits: 32);
  if ( !ser->writing )
    idList<laserGateBeamInfo_t,5>::SetNum(this: &this->laserEndPoints, newNum: num);
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = ser->msg;
      v10 = &this->laserEndPoints.list[v8];
      if ( ser->writing )
        idBitMsg::WriteQuantizedVector<idVec3,32768,17>(this: v9, v: &v10->point1);
      else
        idBitMsg::ReadQuantizedVector<idVec3,32768,17>(this: v9, v: &v10->point1);
      v11 = ser->msg;
      p_point2 = &this->laserEndPoints.list[v8].point2;
      if ( ser->writing )
        idBitMsg::WriteQuantizedVector<idVec3,32768,17>(this: v11, v: p_point2);
      else
        idBitMsg::ReadQuantizedVector<idVec3,32768,17>(this: v11, v: p_point2);
      --num;
      ++v8;
    }
    while ( num != 0 );
  }
  if ( firstTimeIn )
    idPresentableLaserGate::BuildBeams(this);
}


// ========================================================================
// ?UpdateGateLogic@idPresentableLaserGate@@QAAXXZ
// EA  : 0x82B70DA0
// RVA : 0x00B70DA0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::UpdateGateLogic(idPresentableLaserGate *this)
{
  laserGateState_t requestedGateState; // r11
  int num; // r10
  int v4; // r25
  int v5; // r26
  idLaserGateBeam *v6; // r3
  laserGateState_t state; // r27
  idLaserGateBeam *v8; // r11
  laserGateState_t v9; // r10
  double v10; // fp11
  double v11; // fp8
  unsigned int GameMs; // r3
  unsigned int v13; // r3
  int v14; // r3
  int v15; // r3
  idLaserGateBeam *v16; // r11
  int v17; // r8
  laserGateState_t currentGateState; // r11
  unsigned __int64 index; // r11
  bool v44; // r26
  char v45; // r11
  bool v46; // zf
  unsigned __int64 v47; // r9
  const idSoundShader *v48; // r5
  int v49; // r11
  int v50; // r27
  int *v51; // r26
  int v52; // r3
  int v53; // r3
  idBounds v54; // [sp+50h] [-130h] BYREF
  int v55[2]; // [sp+68h] [-118h] BYREF
  int v56; // [sp+70h] [-110h] BYREF
  int v57; // [sp+74h] [-10Ch] BYREF
  int v58; // [sp+78h] [-108h]
  int v59; // [sp+7Ch] [-104h]
  int v60; // [sp+80h] [-100h]
  int v61; // [sp+84h] [-FCh]
  int v62; // [sp+88h] [-F8h]
  int v63; // [sp+8Ch] [-F4h]
  int v64; // [sp+90h] [-F0h]
  int v65; // [sp+94h] [-ECh]
  int v66; // [sp+98h] [-E8h]
  int v67; // [sp+9Ch] [-E4h]
  int v68; // [sp+A0h] [-E0h]
  int v69; // [sp+A4h] [-DCh]
  idMat3 v70; // [sp+B0h] [-D0h] BYREF
  idMat3 v71; // [sp+D8h] [-A8h] BYREF

  requestedGateState = this->requestedGateState;
  if ( requestedGateState != this->currentGateState )
  {
    this->currentGateState = requestedGateState;
    this->gateActivationTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  }
  num = this->laserBeams.num;
  v4 = 0;
  v55[0] = 0;
  v54.b[0].z = 1.0e30;
  v54.b[0].y = 1.0e30;
  v54.b[0].x = 1.0e30;
  v54.b[1].z = -1.0e30;
  v54.b[1].y = v54.b[1].z;
  v54.b[1].x = v54.b[1].z;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->laserBeams.list[v5];
      state = v6->state;
      idLaserGateBeam::UpdateLaserBeams(
        this: v6,
        parentState: this->currentGateState,
        beamPowerUpTime: this->laserGateDecl->beamPowerUpTime,
        startTime: this->laserGateDecl->timeBetweenPoweringUpBeams * v55[0] + this->gateActivationTime,
        maxBeamHeight: this->laserGateDecl->laserBeamHeight);
      if ( ((unsigned __int8)idLaserGate::IsTypeOf(c: this->entity) == 0 || BYTE1(this->entity[1].spawnPosition.z) == 0)
        && v55[0] < 7 )
      {
        v8 = &this->laserBeams.list[v5];
        v9 = v8->state;
        if ( state == LASERGATE_OPENED )
        {
          if ( v9 != LASERGATE_OPENED )
          {
            v10 = (float)(v8->point2.z - v8->point1.z);
            v11 = (float)(v8->point2.y - v8->point1.y);
            v71.mat[0].x = v8->point2.x - v8->point1.x;
            v71.mat[0].z = v10;
            v71.mat[0].y = v11;
            v56 = 147;
            v57 = 148;
            v58 = 149;
            v59 = 150;
            v60 = 151;
            v61 = 152;
            v62 = 153;
            v63 = 154;
            v64 = 155;
            v65 = 156;
            v66 = 157;
            v67 = 158;
            v68 = 159;
            v69 = 160;
            idVec3::ToMat3(this: v70.mat, result: &v71);
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            idFXManager::LocalStartFX(
              this: &this->fxManager,
              org: &this->laserBeams.list[v5].point2,
              axis: &v70,
              time: GameMs,
              start: *(int *)((char *)&v56 + v4 + 4));
            v70.mat[0].x = -v70.mat[0].x;
            v70.mat[0].y = -v70.mat[0].y;
            v70.mat[0].z = -v70.mat[0].z;
            v70.mat[1].x = -v70.mat[1].x;
            v70.mat[1].y = -v70.mat[1].y;
            v70.mat[1].z = -v70.mat[1].z;
            v13 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            idFXManager::LocalStartFX(
              this: &this->fxManager,
              org: &this->laserBeams.list[v5].point1,
              axis: &v70,
              time: v13,
              start: *(int *)((char *)&v56 + v4));
          }
        }
        else if ( v9 == LASERGATE_OPENED )
        {
          v56 = 161;
          v57 = 162;
          v58 = 163;
          v59 = 164;
          v60 = 165;
          v61 = 166;
          v62 = 167;
          v63 = 168;
          v64 = 169;
          v65 = 170;
          v66 = 171;
          v67 = 172;
          v68 = 173;
          v69 = 174;
          v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idFXManager::LocalStopFX(
            this: &this->fxManager,
            time: v14,
            stop: *(int *)((char *)&v57 + v4),
            immediateStop: false);
          v15 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idFXManager::LocalStopFX(
            this: &this->fxManager,
            time: v15,
            stop: *(int *)((char *)&v56 + v4),
            immediateStop: false);
        }
      }
      v16 = &this->laserBeams.list[v5];
      v17 = this->laserBeams.num;
      ++v55[0];
      v4 += 8;
      _FP7 = (float)(v54.b[0].x - v16->point1.x);
      ++v5;
      __asm { fsel      f0, f7, f8, f0 }
      v54.b[0].x = _FP0;
      _FP5 = (float)(v54.b[0].y - v16->point1.y);
      __asm { fsel      f13, f5, f6, f13 }
      v54.b[0].y = _FP13;
      _FP3 = (float)(v54.b[0].z - v16->point1.z);
      __asm { fsel      f12, f3, f4, f12 }
      v54.b[0].z = _FP12;
      _FP1 = (float)(v16->point1.x - v54.b[1].x);
      __asm { fsel      f11, f1, f2, f11 }
      v54.b[1].x = _FP11;
      _FP7 = (float)(v16->point1.y - v54.b[1].y);
      __asm { fsel      f10, f7, f8, f10 }
      v54.b[1].y = _FP10;
      _FP5 = (float)(v16->point1.z - v54.b[1].z);
      __asm { fsel      f9, f5, f6, f9 }
      v54.b[1].z = _FP9;
      _FP3 = (float)((float)_FP0 - v16->point2.x);
      __asm { fsel      f2, f3, f4, f0 }
      v54.b[0].x = _FP2;
      _FP0 = (float)((float)_FP13 - v16->point2.y);
      __asm { fsel      f13, f0, f1, f13 }
      v54.b[0].y = _FP13;
      _FP7 = (float)((float)_FP12 - v16->point2.z);
      __asm { fsel      f6, f7, f8, f12 }
      v54.b[0].z = _FP6;
      _FP4 = (float)(v16->point2.x - (float)_FP11);
      __asm { fsel      f3, f4, f5, f11 }
      v54.b[1].x = _FP3;
      _FP1 = (float)(v16->point2.y - (float)_FP10);
      __asm { fsel      f0, f1, f2, f10 }
      v54.b[1].y = _FP0;
      _FP12 = (float)(v16->point2.z - (float)_FP9);
      __asm { fsel      f11, f12, f13, f9 }
      v54.b[1].z = _FP11;
    }
    while ( v55[0] < v17 );
  }
  currentGateState = this->currentGateState;
  if ( currentGateState == LASERGATE_CLOSED || currentGateState == LASERGATE_CLOSING )
  {
    index = this->gatherQuery.index;
    v44 = false;
    if ( (idClipModel *)index < *(idClipModel **)((char *)&clientGame->clip.temporaryClipModel + (HIDWORD(index) | 0x5A0))
      || (v46 = (unsigned int)index <= LODWORD(clientGame->clip.gatherQueryLastSubmittedIndex), v45 = 1, !v46) )
    {
      v45 = 0;
    }
    if ( v45 != 0
      && idClip::GetGatheredEntities(this: &clientGame->clip, query: &this->gatherQuery, entityList: v55, maxCount: 2) > 0 )
    {
      v44 = true;
    }
    v47 = *(_QWORD *)&idClip::GatherTouchingBounds(
                        this: (idClip *)v55,
                        result: (idGatherQuery *)&clientGame->clip,
                        bounds: &v54,
                        clipMask: 1024,
                        passEntityNumber: this->entityNumber,
                        userName: "w:\\tech5\\tungsten\\game\\clientgame\\presentable\\PresentableLaserGate.cpp(222) : GatherTouchingBounds")->world;
    HIDWORD(v47) = this->laserGateDecl;
    this->gatherQuery.index = v47;
    v48 = *(const idSoundShader **)(HIDWORD(v47) + 88);
    if ( v48 != nullptr && !this->collisionLastFrame && v44 )
      idPresentable::StartSoundShader(
        this,
        channel: SND_CHANNEL_WEAPON,
        shader: v48,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0);
    this->collisionLastFrame = v44;
  }
  else
  {
    this->collisionLastFrame = false;
  }
  if ( this->shutdownTime != -1
    && this->currentGateState <= (unsigned int)LASERGATE_OPENED
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > 7
                                                                                               * this->laserGateDecl->timeBetweenPoweringUpBeams
                                                                                               + this->shutdownTime
                                                                                               + 500 )
  {
    v49 = this->laserBeams.num;
    v50 = 0;
    this->shutdownTime = -1;
    if ( v49 > 0 )
    {
      v51 = v55;
      do
      {
        if ( v50 >= 7 )
          break;
        v56 = 161;
        v57 = 162;
        v58 = 163;
        v59 = 164;
        v60 = 165;
        v61 = 166;
        v62 = 167;
        v63 = 168;
        v64 = 169;
        v65 = 170;
        v66 = 171;
        v67 = 172;
        v68 = 173;
        v69 = 174;
        v52 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idFXManager::LocalStopFX(this: &this->fxManager, time: v52, stop: v51[3], immediateStop: false);
        v53 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v51 += 2;
        idFXManager::LocalStopFX(this: &this->fxManager, time: v53, stop: *v51, immediateStop: false);
        ++v50;
      }
      while ( v50 < this->laserBeams.num );
    }
  }
}


// ========================================================================
// ?Serialize@idPresentableLaserGate@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B71418
// RVA : 0x00B71418
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::Serialize(idPresentableLaserGate *this, idSerializer *ser)
{
  bool v4; // r28
  idBitMsg *msg; // r3
  unsigned int v6; // r10
  laserGateState_t requestedGateState; // r29

  idPresentable::Serialize(this, ser);
  v4 = (_cntlzw((unsigned int)this->laserGateDecl) & 0x20) != 0;
  idSerializer::Serialize<idDeclLaserGate>(this: ser, decl: &this->laserGateDecl);
  msg = ser->msg;
  v6 = _cntlzw(4u);
  requestedGateState = this->requestedGateState;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->requestedGateState, numBits: 32 - v6);
  else
    requestedGateState = idBitMsg::ReadBits(this: msg, numBits: 32 - v6);
  this->requestedGateState = requestedGateState;
  idPresentableLaserGate::SerializeBeams(this, ser, firstTimeIn: v4);
}


// ========================================================================
// ?ClientThink@idPresentableLaserGate@@UAAXHM_N@Z
// EA  : 0x82B714A0
// RVA : 0x00B714A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.cpp
// ========================================================================

void __fastcall idPresentableLaserGate::ClientThink(
        idPresentableLaserGate *this,
        int curTime,
        double fraction,
        bool predict,
        char a5)
{
  idPresentable::ClientThink(this, curTime, fraction, predict, a5);
  idPresentableLaserGate::UpdateGateLogic(this);
}

