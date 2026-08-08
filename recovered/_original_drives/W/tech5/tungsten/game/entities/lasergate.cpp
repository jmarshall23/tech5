
// ========================================================================
// ?AllocPresentable@idLaserGate@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C67EA0
// RVA : 0x00C67EA0
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

idPresentableLaserGate *__fastcall idLaserGate::AllocPresentable(idLaserGate *this, idTreeAnimator *renderModel_)
{
  idPresentableLaserGate *v4; // r3

  v4 = (idPresentableLaserGate *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x4F0u,
                                   tag: TAG_PRESENTABLE,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentableLaserGate::idPresentableLaserGate(
             this: v4,
             e: this,
             renderModel_,
             entityNumber_: this->entityNumber,
             laserGateInfo: this->laserGateInfo,
             laserEndPoints_: &this->laserEndPoints,
             overrideFXDecl: this->overrideFXDecl);
  else
    return nullptr;
}


// ========================================================================
// __unwind$487983
// EA  : 0x82C67F18
// RVA : 0x00C67F18
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void _unwind_487983()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Spawn@idLaserGate@@QAAXXZ
// EA  : 0x82C67F48
// RVA : 0x00C67F48
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void __fastcall idLaserGate::Spawn(idLaserGate *this)
{
  const idDeclLaserGate *laserGateInfo; // r11
  idPhysics *Physics; // r3
  idPhysics *v4; // r3
  int v5; // r28
  int v6; // r29
  idPhysics *v7; // r3
  float *v8; // r3
  double y; // fp10
  double v10; // fp8
  double v11; // fp6
  double v12; // fp5
  double z; // fp4
  double v14; // fp3
  double v15; // fp2
  idPhysics *v16; // r3
  idPresentable *presentable; // r11
  int entityNumber; // r29
  idPhysics *v19; // r30
  idPresentable *v20; // r31
  const idVec3 *v21; // r3
  idVec3 v22; // [sp+50h] [-60h] BYREF
  char v23; // [sp+60h] [-50h] BYREF
  idBounds v24; // [sp+70h] [-40h] BYREF

  laserGateInfo = this->laserGateInfo;
  if ( laserGateInfo == nullptr
    || laserGateInfo->laserBeamMtr == nullptr
    || laserGateInfo->laserBeamHeight <= 0.0
    || laserGateInfo->timeBetweenPoweringUpBeams <= 0
    || laserGateInfo->beamPowerUpTime <= 0
    || this->laserEndPoints.num == 0 )
  {
    idLib::Error(fmt: "Bad data for idLaserGate '%s'", this->name.data);
    JUMPOUT(0x82C681B4);
  }
  idEntity::BecomeActive(this, flags: 1);
  Physics = idEntity::GetPhysics(this);
  Physics->SetClipMask(this: Physics, a2: 0, a3: -1);
  v4 = idEntity::GetPhysics(this);
  v4->SetContents(this: v4, a2: 0, a3: -1);
  v5 = 0;
  this->gateBounds.b[0].z = 1.0e30;
  this->gateBounds.b[0].y = 1.0e30;
  this->gateBounds.b[0].x = 1.0e30;
  this->gateBounds.b[1].z = -1.0e30;
  this->gateBounds.b[1].y = -1.0e30;
  this->gateBounds.b[1].x = -1.0e30;
  if ( this->laserEndPoints.num > 0 )
  {
    v6 = 0;
    do
    {
      idBounds::AddPoint(this: &this->gateBounds, v: &this->laserEndPoints.list[v6].point1);
      idBounds::AddPoint(this: &this->gateBounds, v: &this->laserEndPoints.list[v6].point2);
      ++v5;
      ++v6;
    }
    while ( v5 < this->laserEndPoints.num );
  }
  v7 = idEntity::GetPhysics(this);
  v8 = (float *)v7->GetOrigin(this: v7, a2: 0);
  y = this->gateBounds.b[0].y;
  v10 = v8[1];
  v11 = v8[2];
  v12 = (float)(this->gateBounds.b[1].y + v8[1]);
  z = this->gateBounds.b[0].z;
  v14 = (float)(this->gateBounds.b[1].z + v8[2]);
  v15 = (float)(this->gateBounds.b[0].x + *v8);
  v24.b[1].x = this->gateBounds.b[1].x + *v8;
  v24.b[1].y = v12;
  v24.b[1].z = v14;
  v24.b[0].x = v15;
  v24.b[0].y = (float)v10 + (float)y;
  v24.b[0].z = (float)z + (float)v11;
  idEntity::UpdatePVSAreas(this, bounds: &v24);
  v16 = idEntity::GetPhysics(this);
  presentable = this->presentable;
  entityNumber = this->entityNumber;
  v19 = v16;
  v22.x = (float)(v24.b[1].x + v24.b[0].x) * (float)0.5;
  v22.y = (float)(v24.b[1].y + v24.b[0].y) * (float)0.5;
  v22.z = (float)(v24.b[1].z + v24.b[0].z) * (float)0.5;
  if ( presentable != nullptr )
  {
    v20 = presentable;
  }
  else
  {
    idEntity::InitPresentableInternal(this);
    v20 = this->presentable;
  }
  v21 = v19->GetLinearVelocity(this: (idPhysics *)&v23, result: (idVec3 *)v19, a3: 0);
  idPresentable::UpdateSound(this: v20, origin: &v22, axis: &mat3_identity, velocity: v21, listenerId: entityNumber + 1);
}


// ========================================================================
// ?DormantBegin@idLaserGate@@UAAXXZ
// EA  : 0x82C681B8
// RVA : 0x00C681B8
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void __fastcall idLaserGate::DormantBegin(idLaserGate *this)
{
  idPresentableLaserGate *presentable; // r11

  presentable = (idPresentableLaserGate *)this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = (idPresentableLaserGate *)this->presentable;
  }
  idPresentableLaserGate::EnterDormancy(this: presentable);
}


// ========================================================================
// ?DormantEnd@idLaserGate@@UAAXH@Z
// EA  : 0x82C68200
// RVA : 0x00C68200
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void __fastcall idLaserGate::DormantEnd(idLaserGate *this, const int timeDormant)
{
  idPresentableLaserGate *presentable; // r11

  presentable = (idPresentableLaserGate *)this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = (idPresentableLaserGate *)this->presentable;
  }
  idPresentableLaserGate::LeaveDormancy(this: presentable);
}


// ========================================================================
// ?UpdateModelTransform@idLaserGate@@UAAXXZ
// EA  : 0x82C68248
// RVA : 0x00C68248
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void __fastcall idLaserGate::UpdateModelTransform(idLaserGate *this, idFXManager *a2)
{
  idPresentableLaserGate *presentable; // r11

  if ( this->moveable )
  {
    presentable = (idPresentableLaserGate *)this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = (idPresentableLaserGate *)this->presentable;
    }
    idPresentableLaserGate::UpdateBeams(this: presentable, p_point2: a2);
  }
  idEntity::UpdateModelTransform(this);
}


// ========================================================================
// ?Event_PowerUpLasers@idLaserGate@@QAA?AVeventVoid@@XZ
// EA  : 0x82C682A0
// RVA : 0x00C682A0
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

idLaserGate *__fastcall idLaserGate::Event_PowerUpLasers(idLaserGate *this, idEntity *result)
{
  idPresentableLaserGate *presentable; // r30
  char *data; // r10
  int v6; // r29
  int listenerList; // r11
  fxCondition_t *v8; // r30
  idPresentable *v9; // r3
  idPresentable *v10; // r3
  _DWORD v12[17]; // [sp+4Ch] [-104h] BYREF
  soundShaderParms_t v13; // [sp+90h] [-C0h] BYREF

  presentable = (idPresentableLaserGate *)result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = (idPresentableLaserGate *)result->presentable;
  }
  idPresentableLaserGate::PowerUp(this: presentable);
  data = result[1].name.data;
  v6 = 0;
  *(_DWORD *)result[1].name.baseBuffer = 2;
  if ( *((_DWORD *)data + 20) != 0 )
  {
    idPresentable::StopSound(this: presentable, channel: SND_CHANNEL_ANY, peerMask: 0);
    soundShaderParms_t::Clear(this: &v13);
    v13.soundShaderFlags = 0;
    idPresentable::StartSoundShader(
      this: presentable,
      channel: SND_CHANNEL_ANY,
      shader: *((const idSoundShader **)result[1].name.data + 20),
      parms: &v13,
      peerMask: 0);
  }
  if ( BYTE1(result[1].spawnPosition.z) != 0 )
  {
    listenerList = (int)result[1].listenerList;
    v12[1] = 147;
    v12[2] = 148;
    v12[3] = 149;
    v12[4] = 150;
    v12[5] = 151;
    v12[6] = 152;
    v12[7] = 153;
    v12[8] = 154;
    v12[9] = 155;
    v12[10] = 156;
    v12[11] = 157;
    v12[12] = 158;
    v12[13] = 159;
    v12[14] = 160;
    if ( listenerList > 0 )
    {
      v8 = (fxCondition_t *)v12;
      do
      {
        v9 = result->presentable;
        if ( v9 == nullptr )
        {
          idEntity::InitPresentableInternal(this: result);
          v9 = result->presentable;
        }
        v9->StartFX(this: v9, a2: v8[1], a3: FX_EXTRA_COND_NONE);
        v10 = result->presentable;
        if ( v10 == nullptr )
        {
          idEntity::InitPresentableInternal(this: result);
          v10 = result->presentable;
        }
        v8 += 2;
        v10->StartFX(this: v10, a2: *v8, a3: FX_EXTRA_COND_NONE);
        ++v6;
      }
      while ( v6 < (int)result[1].listenerList );
    }
  }
  return this;
}


// ========================================================================
// ?Event_ShutDownLasers@idLaserGate@@QAA?AVeventVoid@@XZ
// EA  : 0x82C68438
// RVA : 0x00C68438
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

idLaserGate *__fastcall idLaserGate::Event_ShutDownLasers(idLaserGate *this, idEntity *result)
{
  idPresentableLaserGate *presentable; // r30
  char *data; // r11
  int v6; // r29
  int listenerList; // r11
  int *v8; // r30
  idPresentable *v9; // r3
  idPresentable *v10; // r11
  _DWORD v12[17]; // [sp+4Ch] [-104h] BYREF
  soundShaderParms_t v13; // [sp+90h] [-C0h] BYREF

  presentable = (idPresentableLaserGate *)result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = (idPresentableLaserGate *)result->presentable;
  }
  idPresentableLaserGate::PowerDown(this: presentable);
  data = result[1].name.data;
  v6 = 0;
  *(_DWORD *)result[1].name.baseBuffer = 0;
  if ( *((_DWORD *)data + 21) != 0 )
  {
    idPresentable::StopSound(this: presentable, channel: SND_CHANNEL_ANY, peerMask: 0);
    soundShaderParms_t::Clear(this: &v13);
    v13.soundShaderFlags = 0;
    idPresentable::StartSoundShader(
      this: presentable,
      channel: SND_CHANNEL_ANY,
      shader: *((const idSoundShader **)result[1].name.data + 21),
      parms: &v13,
      peerMask: 0);
  }
  if ( BYTE1(result[1].spawnPosition.z) != 0 )
  {
    listenerList = (int)result[1].listenerList;
    v12[1] = 161;
    v12[2] = 162;
    v12[3] = 163;
    v12[4] = 164;
    v12[5] = 165;
    v12[6] = 166;
    v12[7] = 167;
    v12[8] = 168;
    v12[9] = 169;
    v12[10] = 170;
    v12[11] = 171;
    v12[12] = 172;
    v12[13] = 173;
    v12[14] = 174;
    if ( listenerList > 0 )
    {
      v8 = v12;
      do
      {
        v9 = result->presentable;
        if ( v9 == nullptr )
        {
          idEntity::InitPresentableInternal(this: result);
          v9 = result->presentable;
        }
        idPresentable::StopFX(this: v9, condition: v8[1], extraCondition: FX_EXTRA_COND_NONE);
        v10 = result->presentable;
        if ( v10 == nullptr )
        {
          idEntity::InitPresentableInternal(this: result);
          v10 = result->presentable;
        }
        v8 += 2;
        idPresentable::StopFX(this: v10, condition: *v8, extraCondition: FX_EXTRA_COND_NONE);
        ++v6;
      }
      while ( v6 < (int)result[1].listenerList );
    }
  }
  return this;
}


// ========================================================================
// ??0idLaserGate@@QAA@XZ
// EA  : 0x82C685C0
// RVA : 0x00C685C0
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

idLaserGate *__fastcall idLaserGate::idLaserGate(idLaserGate *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idLaserGate_vtbl *)&idLaserGate::`vftable';
  this->laserEndPoints.list = nullptr;
  this->laserEndPoints.granularity = 0;
  this->laserEndPoints.memTag = 5;
  this->laserEndPoints.listStatic = 0;
  this->laserEndPoints.size = 0;
  this->laserEndPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->laserEndPoints);
  this->laserGateInfo = nullptr;
  this->overrideFXDecl = nullptr;
  this->gateState = LASERGATE_OPENED;
  this->gateBounds.b[0].x = 0.0;
  this->gateBounds.b[0].y = 0.0;
  this->gateBounds.b[0].z = 0.0;
  this->gateBounds.b[1].x = 0.0;
  this->gateBounds.b[1].y = 0.0;
  this->gateBounds.b[1].z = 0.0;
  this->startsOn = true;
  this->moveable = false;
  this->firstThink = true;
  return this;
}


// ========================================================================
// __unwind$488520
// EA  : 0x82C68664
// RVA : 0x00C68664
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void _unwind_488520()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idLaserGate@@UAA@XZ
// EA  : 0x82C68698
// RVA : 0x00C68698
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void __fastcall idLaserGate::~idLaserGate(idLaserGate *this)
{
  this->__vftable = (idLaserGate_vtbl *)&idLaserGate::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->laserEndPoints);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$488781_0
// EA  : 0x82C686EC
// RVA : 0x00C686EC
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void _unwind_488781_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?OnActivate@idLaserGate@@UAAXPAVidEntity@@@Z
// EA  : 0x82C68718
// RVA : 0x00C68718
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void __fastcall idLaserGate::OnActivate(idLaserGate *this, idEntity *activator)
{
  laserGateState_t gateState; // r11
  _BYTE v3[8]; // [sp+50h] [-10h] BYREF

  gateState = this->gateState;
  if ( gateState == LASERGATE_CLOSING || gateState == LASERGATE_CLOSED )
    idLaserGate::Event_ShutDownLasers(this: (idLaserGate *)v3, result: this);
  else
    idLaserGate::Event_PowerUpLasers(this: (idLaserGate *)v3, result: this);
}


// ========================================================================
// ?Think@idLaserGate@@UAAXXZ
// EA  : 0x82C687D8
// RVA : 0x00C687D8
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void __fastcall idLaserGate::Think(idLaserGate *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPhysics *Physics; // r3
  float *v5; // r3
  BOOL moveable; // r7
  double v7; // fp7
  double v8; // fp5
  double v9; // fp2
  double v10; // fp1
  double v11; // fp0
  BOOL startsOn; // r11
  idPhysics *v13; // r3
  idPresentable *presentable; // r11
  int entityNumber; // r27
  idPhysics *v16; // r28
  idPresentable *v17; // r29
  const idVec3 *v18; // r3
  idEntity *BindMaster; // r3
  idPhysics *v20; // r3
  idVec3 *v21; // r3
  int v22; // r4
  idPresentableLaserGate *v23; // r11
  idPresentableLaserGate *v24; // r11
  _DWORD v25[2]; // [sp+50h] [-80h] BYREF
  idPLogScope v26; // [sp+58h] [-78h] BYREF
  idVec3 v27; // [sp+60h] [-70h] BYREF
  _BYTE v28[16]; // [sp+70h] [-60h] BYREF
  idBounds v29; // [sp+80h] [-50h] BYREF

  RD_EventBegin(name: "idLaserGate::Think");
  LODWORD(v2) = "idLaserGate::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v26, pl: &pLog, gMask: v2, label: v3);
  if ( (unsigned __int8)idEntity::UpdateDormant(this) != 0 )
  {
    idPLogScope::~idPLogScope(this: &v26);
  }
  else
  {
    idEntity::RunPhysics(this);
    this->UpdateFX(this);
    Physics = idEntity::GetPhysics(this);
    v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    moveable = this->moveable;
    v7 = (float)(*v5 + this->gateBounds.b[1].x);
    v8 = (float)(this->gateBounds.b[0].x + *v5);
    v9 = (float)(this->gateBounds.b[1].y + v5[1]);
    v10 = (float)(this->gateBounds.b[0].z + v5[2]);
    v11 = (float)(this->gateBounds.b[0].y + v5[1]);
    v29.b[1].z = this->gateBounds.b[1].z + v5[2];
    v29.b[1].y = v9;
    v25[1] = &this->gateBounds.b[1];
    v29.b[0].z = v10;
    v29.b[0].y = v11;
    v29.b[1].x = v7;
    v29.b[0].x = v8;
    if ( moveable )
      idEntity::UpdatePVSAreas(this, bounds: &v29);
    if ( this->firstThink )
    {
      startsOn = this->startsOn;
      this->firstThink = false;
      if ( startsOn )
        idLaserGate::Event_PowerUpLasers(this: (idLaserGate *)v25, result: this);
      else
        idLaserGate::Event_ShutDownLasers(this: (idLaserGate *)v25, result: this);
    }
    if ( this->moveable )
    {
      v13 = idEntity::GetPhysics(this);
      presentable = this->presentable;
      entityNumber = this->entityNumber;
      v16 = v13;
      v27.x = (float)(v29.b[1].x + v29.b[0].x) * (float)0.5;
      v27.y = (float)(v29.b[1].y + v29.b[0].y) * (float)0.5;
      v27.z = (float)(v29.b[1].z + v29.b[0].z) * (float)0.5;
      if ( presentable != nullptr )
      {
        v17 = presentable;
      }
      else
      {
        idEntity::InitPresentableInternal(this);
        v17 = this->presentable;
      }
      v18 = v16->GetLinearVelocity(this: (idPhysics *)v28, result: (idVec3 *)v16, a3: 0);
      idPresentable::UpdateSound(
        this: v17,
        origin: &v27,
        axis: &mat3_identity,
        velocity: v18,
        listenerId: entityNumber + 1);
      if ( idEntity::GetBindMaster(this) != nullptr )
      {
        BindMaster = idEntity::GetBindMaster(this);
        v20 = idEntity::GetPhysics(this: BindMaster);
        v21 = v20->GetLinearVelocity(this: (idPhysics *)v28, result: (idVec3 *)v20, a3: 0);
        v22 = LODWORD(v21->z) | LODWORD(v21->y) | LODWORD(v21->x);
        if ( (v22 & 0x7FFFFFFF) == 0 )
        {
          v23 = (idPresentableLaserGate *)this->presentable;
          if ( v23 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v23 = (idPresentableLaserGate *)this->presentable;
          }
          idPresentableLaserGate::UpdateBeams(this: v23, p_point2: (idFXManager *)v22);
        }
      }
    }
    v24 = (idPresentableLaserGate *)this->presentable;
    if ( v24 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v24 = (idPresentableLaserGate *)this->presentable;
    }
    idPresentableLaserGate::UpdateGateLogic(this: v24);
    idPLogScope::~idPLogScope(this: &v26);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$488851
// EA  : 0x82C68A80
// RVA : 0x00C68A80
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void _unwind_488851()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 152));
}


// ========================================================================
// __unwind$488852
// EA  : 0x82C68AA8
// RVA : 0x00C68AA8
// PDB : w:\tech5\tungsten\game\entities\lasergate.cpp
// ========================================================================

void _unwind_488852()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 88));
}

