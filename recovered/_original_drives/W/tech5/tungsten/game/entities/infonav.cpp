
// ========================================================================
// ?Hide@idInfoLinkSegment@@UAAXXZ
// EA  : 0x82C66480
// RVA : 0x00C66480
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoLinkSegment::Hide(idInfoLinkSegment *this)
{
  idNpLink *navLink; // r3

  navLink = this->navLink;
  if ( navLink != nullptr )
    idNpLink::SetLinkEnabled(this: navLink, enabled: false);
}


// ========================================================================
// ?Show@idInfoLinkSegment@@UAAXXZ
// EA  : 0x82C66498
// RVA : 0x00C66498
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoLinkSegment::Show(idInfoLinkSegment *this)
{
  idNpLink *navLink; // r3

  navLink = this->navLink;
  if ( navLink != nullptr )
    idNpLink::SetLinkEnabled(this: navLink, enabled: true);
}


// ========================================================================
// ?Spawn@idInfoLinkSegment@@QAAXXZ
// EA  : 0x82C664B0
// RVA : 0x00C664B0
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoLinkSegment::Spawn(idInfo_TraversalPoint *this)
{
  idEventReceiver::PostEventMS(this, ev: &EV_PostSpawn, time: 0);
}


// ========================================================================
// ?OnActivate@idInfoLinkSegment@@UAAXPAVidEntity@@@Z
// EA  : 0x82C664C0
// RVA : 0x00C664C0
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoLinkSegment::OnActivate(idInfoLinkSegment *this, idEntity *dummy)
{
  idNpLink *navLink; // r3
  bool IsLinkEnabled; // r3

  navLink = this->navLink;
  if ( navLink != nullptr )
  {
    IsLinkEnabled = idNpLink::IsLinkEnabled(this: navLink);
    idNpLink::SetLinkEnabled(this: this->navLink, enabled: (_cntlzw(IsLinkEnabled) & 0x20) != 0);
  }
}


// ========================================================================
// ?Think@idInfoLinkSegment@@UAAXXZ
// EA  : 0x82C66510
// RVA : 0x00C66510
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoLinkSegment::Think(idInfoLinkSegment *this)
{
  gameLocal->GetGameFlags(this: gameLocal);
}


// ========================================================================
// ?CheckForErrors@idInfoLinkSegment@@UAAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82C66528
// RVA : 0x00C66528
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoLinkSegment::CheckForErrors(idInfoLinkSegment *this, idList<idStr,5> *errorList)
{
  idNpLink *navLink; // r3

  idEntity::CheckForErrors(this, errorList);
  navLink = this->navLink;
  if ( navLink != nullptr )
    idNpLink::CheckForErrors(this: navLink, errorList);
}


// ========================================================================
// ?TryReserveLink@idInfoLinkSegment@@QAA_NAAVidNpLink@@_N@Z
// EA  : 0x82C66578
// RVA : 0x00C66578
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

BOOL __fastcall idInfoLinkSegment::TryReserveLink(idInfoLinkSegment *this, idNpLink *reservation, bool force)
{
  idNpLink *navLink; // r3

  navLink = this->navLink;
  return navLink != nullptr && idNpLink::TryReserveLink(this: navLink, reservation, force);
}


// ========================================================================
// ?Think@idInfoNavRepulsor@@UAAXXZ
// EA  : 0x82C66590
// RVA : 0x00C66590
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoNavRepulsor::Think(idInfoNavRepulsor *this)
{
  idNpRepulsor *navRepulsor; // r3

  navRepulsor = this->navRepulsor;
  if ( navRepulsor != nullptr )
    idNpRepulsor::Update(this: navRepulsor, ent: this, forceZeroVelocity: false);
}


// ========================================================================
// ??0idInfoLinkSegment@@QAA@XZ
// EA  : 0x82C665B8
// RVA : 0x00C665B8
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

idInfoLinkSegment *__fastcall idInfoLinkSegment::idInfoLinkSegment(idInfoLinkSegment *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoLinkSegment_vtbl *)&idInfoLinkSegment::`vftable';
  this->anim.len = 0;
  this->anim.allocedAndFlag = 20;
  this->anim.data = this->anim.baseBuffer;
  this->anim.baseBuffer[0] = 0;
  this->animOptionalDest.allocedAndFlag = 20;
  this->animOptionalDest.len = 0;
  this->animOptionalDest.data = this->animOptionalDest.baseBuffer;
  this->animOptionalDest.baseBuffer[0] = 0;
  this->fallCycle.allocedAndFlag = 20;
  this->fallCycle.len = 0;
  this->fallCycle.data = this->fallCycle.baseBuffer;
  this->fallCycle.baseBuffer[0] = 0;
  this->disableExits = false;
  this->startWidth = 64.0;
  this->end0.y = -32.0;
  this->end0.x = 64.0;
  this->end0.z = 0.0;
  this->end1.x = 64.0;
  this->end1.y = 32.0;
  this->end1.z = 0.0;
  this->cooldown = 0.0;
  idNpLinkData::idNpLinkData(this: &this->linkParms);
  this->useExplicitEndPoints = false;
  this->navLink = nullptr;
  return this;
}


// ========================================================================
// __unwind$488500
// EA  : 0x82C666A0
// RVA : 0x00C666A0
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_488500()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488501
// EA  : 0x82C666C8
// RVA : 0x00C666C8
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_488501()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// __unwind$488502_0
// EA  : 0x82C666F4
// RVA : 0x00C666F4
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_488502_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 832));
}


// ========================================================================
// __unwind$488503_0
// EA  : 0x82C66720
// RVA : 0x00C66720
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_488503_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 864));
}


// ========================================================================
// ?Event_EnableLink@idInfoLinkSegment@@QAA?AVeventVoid@@_N@Z
// EA  : 0x82C66750
// RVA : 0x00C66750
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

idInfoLinkSegment *__fastcall idInfoLinkSegment::Event_EnableLink(
        idInfoLinkSegment *this,
        eventVoid *result,
        bool enable)
{
  idNpLink *v4; // r3

  v4 = *(idNpLink **)&result[964];
  if ( v4 != nullptr )
    idNpLink::SetLinkEnabled(this: v4, enabled: enable);
  return this;
}


// ========================================================================
// ?DebugDrawEntity@idInfoLinkSegment@@UAAXABVidColor@@H@Z
// EA  : 0x82C66790
// RVA : 0x00C66790
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoLinkSegment::DebugDrawEntity(idInfoLinkSegment *this, const idColor *color, int duration)
{
  idPhysics *Physics; // r3
  int v7; // r3
  float v8; // r7
  float v9; // r6
  idPhysics *v10; // r3
  int v11; // r3
  char *v12; // r10
  _DWORD *v13; // r11
  int i; // ctr
  idRenderWorld *v15; // r3
  double v16; // fp31
  idRenderWorld *v17; // r3
  float *v18; // r6
  idVec3 *p_end0; // r5
  double startWidth; // fp0
  double v21; // fp11
  double v22; // fp3
  idRenderWorld *v23; // r3
  idRenderWorld *v24; // r3
  idRenderWorld *v25; // r3
  idRenderWorld *v26; // r3
  idRenderWorld *v27; // r3
  float v28; // [sp+50h] [-A0h] BYREF
  float v29; // [sp+54h] [-9Ch]
  float v30; // [sp+58h] [-98h]
  float v31[4]; // [sp+60h] [-90h] BYREF
  float v32[3]; // [sp+70h] [-80h] BYREF
  char v33; // [sp+7Ch] [-74h] BYREF
  float v34; // [sp+8Ch] [-64h]
  float v35; // [sp+90h] [-60h]
  float v36; // [sp+94h] [-5Ch]

  Physics = idEntity::GetPhysics(this);
  v7 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = *(float *)(v7 + 4);
  v9 = *(float *)(v7 + 8);
  v28 = *(float *)v7;
  v29 = v8;
  v30 = v9;
  v10 = idEntity::GetPhysics(this);
  v11 = (int)v10->GetAxis(this: v10, a2: 0);
  v12 = &v33;
  v13 = (_DWORD *)(v11 - 4);
  for ( i = 9; i != 0; --i )
  {
    ++v13;
    v12 += 4;
    *(_DWORD *)v12 = *v13;
  }
  if ( this->startWidth == 0.0 )
  {
    v15 = gameLocal->GetRenderWorld(this: gameLocal);
    v16 = 4.0;
    ((void (__fastcall *)(idRenderWorld *, const idColor *, float *, idVec3 *, double))v15->DebugArrow)(
      a1: v15,
      a2: color,
      a3: &v28,
      a4: &this->end0,
      a5: 4.0);
    if ( !this->linkParms.linkBiDirectional )
      return;
    v17 = gameLocal->GetRenderWorld(this: gameLocal);
    v18 = &v28;
    p_end0 = &this->end0;
  }
  else
  {
    startWidth = this->startWidth;
    v21 = (float)((float)(v36 * this->startWidth) * (float)0.5);
    v22 = (float)((float)((float)(v35 * this->startWidth) * (float)0.5) + v29);
    v32[0] = (float)((float)(v34 * this->startWidth) * (float)0.5) + v28;
    v32[1] = v22;
    v32[2] = (float)v21 + v30;
    v31[0] = (float)((float)(v34 * (float)-startWidth) * (float)0.5) + v28;
    v31[1] = v29 + (float)((float)(v35 * (float)-startWidth) * (float)0.5);
    v31[2] = v30 + (float)((float)(v36 * (float)-startWidth) * (float)0.5);
    v23 = gameLocal->GetRenderWorld(this: gameLocal);
    v23->DebugLine(
      this: v23,
      a2: (const idVec4 *)color,
      a3: (const idVec3 *)v31,
      a4: (const idVec3 *)v32,
      a5: duration,
      a6: false);
    v24 = gameLocal->GetRenderWorld(this: gameLocal);
    v24->DebugLine(this: v24, a2: (const idVec4 *)color, a3: &this->end0, a4: &this->end1, a5: duration, a6: false);
    v25 = gameLocal->GetRenderWorld(this: gameLocal);
    v16 = 4.0;
    ((void (__fastcall *)(idRenderWorld *, const idColor *, float *, idVec3 *, double))v25->DebugArrow)(
      a1: v25,
      a2: color,
      a3: v31,
      a4: &this->end0,
      a5: 4.0);
    v26 = gameLocal->GetRenderWorld(this: gameLocal);
    ((void (__fastcall *)(idRenderWorld *, const idColor *, float *, idVec3 *, double))v26->DebugArrow)(
      a1: v26,
      a2: color,
      a3: v32,
      a4: &this->end1,
      a5: 4.0);
    if ( !this->linkParms.linkBiDirectional )
      return;
    v27 = gameLocal->GetRenderWorld(this: gameLocal);
    ((void (__fastcall *)(idRenderWorld *, const idColor *, idVec3 *, float *, double))v27->DebugArrow)(
      a1: v27,
      a2: color,
      a3: &this->end0,
      a4: v31,
      a5: 4.0);
    v17 = gameLocal->GetRenderWorld(this: gameLocal);
    v18 = v32;
    p_end0 = &this->end1;
  }
  ((void (__fastcall *)(idRenderWorld *, const idColor *, idVec3 *, float *, double))v17->DebugArrow)(
    a1: v17,
    a2: color,
    a3: p_end0,
    a4: v18,
    a5: v16);
}


// ========================================================================
// ??0idInfoNavObstacle@@QAA@XZ
// EA  : 0x82C66AC0
// RVA : 0x00C66AC0
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

idInfoNavObstacle *__fastcall idInfoNavObstacle::idInfoNavObstacle(idInfoNavObstacle *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoNavObstacle_vtbl *)&idInfoNavObstacle::`vftable';
  this->obstacleSize.x = 32.0;
  this->obstacleSize.y = 32.0;
  this->obstacleSize.z = 32.0;
  idNpObstacleData::idNpObstacleData(this: &this->obstacleParms);
  this->startOn = true;
  this->navObstacle = nullptr;
  this->obstacleLifetime = 0.0;
  return this;
}


// ========================================================================
// __unwind$488813_0
// EA  : 0x82C66B4C
// RVA : 0x00C66B4C
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_488813_0()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// ?Init@idInfoNavObstacle@@QAAXABUidNpObstacleData@@ABVidVec3@@M@Z
// EA  : 0x82C66B78
// RVA : 0x00C66B78
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoNavObstacle::Init(
        idInfoNavObstacle *this,
        const idNpObstacleData *parms,
        const idVec3 *size,
        double lifeTime)
{
  idNpObstacle *navObstacle; // r30

  this->obstacleParms = *parms;
  this->obstacleSize = *size;
  navObstacle = this->navObstacle;
  this->obstacleLifetime = lifeTime;
  if ( navObstacle != nullptr )
  {
    idNpObstacle::~idNpObstacle(this: navObstacle);
    idMem::Free(this: &mem, ptr: navObstacle, align: ALIGN_16);
    this->navObstacle = nullptr;
  }
  else
  {
    this->navObstacle = nullptr;
  }
}


// ========================================================================
// ?CreateNavObstacle@idInfoNavObstacle@@AAAXXZ
// EA  : 0x82C66C20
// RVA : 0x00C66C20
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoNavObstacle::CreateNavObstacle(idInfoNavObstacle *this)
{
  idNpObstacle *v2; // r3
  idNpObstacle *v3; // r3
  double obstacleLifetime; // fp1

  v2 = (idNpObstacle *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 4u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idNpObstacle::idNpObstacle(
           this: v2,
           ent: this,
           size: &this->obstacleSize,
           parms: &this->obstacleParms,
           shouldCreateAsync: true);
  else
    v3 = nullptr;
  obstacleLifetime = this->obstacleLifetime;
  this->navObstacle = v3;
  if ( obstacleLifetime != 0.0 )
    idEventReceiver::PostEventSec(this, ev: &EV_Remove, time: obstacleLifetime);
}


// ========================================================================
// __unwind$488875
// EA  : 0x82C66CCC
// RVA : 0x00C66CCC
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall _unwind_488875(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ??0idInfoNavInclusionVolume@@QAA@XZ
// EA  : 0x82C66CF8
// RVA : 0x00C66CF8
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

idInfoNavInclusionVolume *__fastcall idInfoNavInclusionVolume::idInfoNavInclusionVolume(idInfoNavInclusionVolume *this)
{
  idEntity::idEntity(this);
  this->layersAffected = NavMask_AllLayers;
  this->__vftable = (idInfoNavInclusionVolume_vtbl *)&idInfoNavInclusionVolume::`vftable';
  return this;
}


// ========================================================================
// ??0idInfoNavExclusionVolume@@QAA@XZ
// EA  : 0x82C66D48
// RVA : 0x00C66D48
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

idInfoNavExclusionVolume *__fastcall idInfoNavExclusionVolume::idInfoNavExclusionVolume(idInfoNavExclusionVolume *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoNavExclusionVolume_vtbl *)&idInfoNavExclusionVolume::`vftable';
  idNpObstacleData::idNpObstacleData(this: &this->obstacleParms);
  this->obstacleParms.obstacleBlockageFlags = Obstacle_None;
  return this;
}


// ========================================================================
// __unwind$488913_0
// EA  : 0x82C66DA4
// RVA : 0x00C66DA4
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_488913_0()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idInfoNavFlightVolume@@QAA@XZ
// EA  : 0x82C66DD8
// RVA : 0x00C66DD8
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

idInfoNavFlightVolume *__fastcall idInfoNavFlightVolume::idInfoNavFlightVolume(idInfoNavFlightVolume *this)
{
  idEntity::idEntity(this);
  this->volumeFlags = NavVolumeDefault;
  this->__vftable = (idInfoNavFlightVolume_vtbl *)&idInfoNavFlightVolume::`vftable';
  idNpObstacleData::idNpObstacleData(this: &this->obstacleParms);
  this->obstacleParms.obstacleAffects = NavMask_MonsterFlight|NavMask_Monster96;
  this->obstacleParms.obstacleBlockageFlags = Obstacle_Flight;
  this->obstacleParms.obstaclePenalty = 0.0;
  return this;
}


// ========================================================================
// __unwind$488940
// EA  : 0x82C66E50
// RVA : 0x00C66E50
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_488940()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idInfoNavRepulsor@@QAA@XZ
// EA  : 0x82C66E80
// RVA : 0x00C66E80
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

idInfoNavRepulsor *__fastcall idInfoNavRepulsor::idInfoNavRepulsor(idInfoNavRepulsor *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoNavRepulsor_vtbl *)&idInfoNavRepulsor::`vftable';
  idNpRepulsorData::idNpRepulsorData(this: &this->repulsorParms);
  this->navRepulsor = nullptr;
  this->repulsorLifetime = 0.0;
  return this;
}


// ========================================================================
// __unwind$488967
// EA  : 0x82C66EE8
// RVA : 0x00C66EE8
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_488967()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// ?CreateNavRepulsor@idInfoNavRepulsor@@AAAXXZ
// EA  : 0x82C66F18
// RVA : 0x00C66F18
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoNavRepulsor::CreateNavRepulsor(idInfoNavRepulsor *this)
{
  idNpRepulsor *v2; // r3
  idNpRepulsor *v3; // r3

  if ( this->repulsorLifetime != 0.0 )
  {
    v2 = (idNpRepulsor *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 4u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v2 != nullptr )
      v3 = idNpRepulsor::idNpRepulsor(this: v2, ent: this, parms: &this->repulsorParms);
    else
      v3 = nullptr;
    this->navRepulsor = v3;
    idEventReceiver::PostEventSec(this, ev: &EV_Remove, time: this->repulsorLifetime);
  }
}


// ========================================================================
// __unwind$489022_0
// EA  : 0x82C66FC0
// RVA : 0x00C66FC0
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall _unwind_489022_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ??0idInfoNavIslandMarker@@QAA@XZ
// EA  : 0x82C66FE8
// RVA : 0x00C66FE8
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

idInfoNavIslandMarker *__fastcall idInfoNavIslandMarker::idInfoNavIslandMarker(idInfoNavIslandMarker *this)
{
  idEntity::idEntity(this);
  this->navLayerAffected = NAVLAYER_NONE;
  this->__vftable = (idInfoNavIslandMarker_vtbl *)&idInfoNavIslandMarker::`vftable';
  return this;
}


// ========================================================================
// ??1idInfoLinkSegment@@UAA@XZ
// EA  : 0x82C67038
// RVA : 0x00C67038
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoLinkSegment::~idInfoLinkSegment(idInfoLinkSegment *this)
{
  idNpLink *navLink; // r29

  this->__vftable = (idInfoLinkSegment_vtbl *)&idInfoLinkSegment::`vftable';
  navLink = this->navLink;
  if ( navLink != nullptr )
  {
    idNpLink::~idNpLink(this: this->navLink);
    idMem::Free(this: &mem, ptr: navLink, align: ALIGN_16);
  }
  idStr::FreeData(this: &this->fallCycle);
  idStr::FreeData(this: &this->animOptionalDest);
  idStr::FreeData(this: &this->anim);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$489127
// EA  : 0x82C670AC
// RVA : 0x00C670AC
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_489127()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489128
// EA  : 0x82C670D4
// RVA : 0x00C670D4
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_489128()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}


// ========================================================================
// __unwind$489129
// EA  : 0x82C67100
// RVA : 0x00C67100
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_489129()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 832));
}


// ========================================================================
// __unwind$489130
// EA  : 0x82C6712C
// RVA : 0x00C6712C
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_489130()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 864));
}


// ========================================================================
// ?Event_PostSpawn@idInfoLinkSegment@@AAA?AVeventVoid@@XZ
// EA  : 0x82C67160
// RVA : 0x00C67160
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

idInfoLinkSegment *__fastcall idInfoLinkSegment::Event_PostSpawn(idInfoLinkSegment *this, idEntity *result)
{
  idPhysics *Physics; // r3
  int v5; // r3
  float v6; // r7
  float v7; // r6
  idPhysics *v8; // r3
  int v9; // r3
  float *v10; // r10
  _DWORD *v11; // r11
  int i; // ctr
  idNpLink *v13; // r3
  idNpLink *v14; // r3
  idEntity_vtbl *v15; // r10
  int b_high; // r11
  double v17; // fp31
  double v18; // fp30
  double v19; // fp29
  double x; // fp13
  double y; // fp11
  double z; // fp12
  float *p_z; // r10
  int v24; // ctr
  float *p_y; // r11
  double v26; // fp28
  double v27; // fp27
  double v28; // fp26
  char v29; // r8
  bool v30; // r29
  int entityNumber; // r8
  idClientGame *v32; // r11
  idClipModel *clip32x32; // r7
  double v34; // fp12
  double v35; // fp28
  const char *data; // r11
  const char *v37; // r11
  double v38; // fp0
  double v39; // fp10
  double v40; // fp9
  double v41; // fp8
  double v42; // fp2
  double v43; // fp4
  double v44; // fp8
  double v45; // fp7
  double v46; // fp31
  double v47; // fp30
  double v48; // fp27
  double v49; // fp1
  double v50; // fp28
  double v51; // fp5
  double v52; // fp4
  double v53; // fp2
  idNpLink *a_low; // r3
  double v55; // fp0
  double v56; // fp7
  double v57; // fp1
  double v58; // fp30
  double maxTexelDensity; // fp2
  double v60; // fp28
  double v61; // fp23
  double v62; // fp7
  double v63; // fp31
  double v64; // fp17
  double v65; // fp24
  double v66; // fp26
  double v67; // fp5
  unsigned __int8 idCombatStage_useRelaxedChatterVO; // r3
  const idNpLinkData *v70; // [sp+8h] [-3398h]
  bool v71; // [sp+Fh] [-3391h]
  idNavigationSpace v72; // [sp+64h] [-333Ch] BYREF
  idVec3 v73; // [sp+68h] [-3338h] BYREF
  idVec3 v74; // [sp+78h] [-3328h] BYREF
  idVec3 v75; // [sp+88h] [-3318h] BYREF
  float v76[11]; // [sp+9Ch] [-3304h] BYREF
  idVec3 v77; // [sp+C8h] [-32D8h] BYREF
  idVec3 v78; // [sp+D8h] [-32C8h] BYREF
  idVec3 v79; // [sp+E8h] [-32B8h] BYREF
  idVec3 v80; // [sp+F8h] [-32A8h] BYREF
  idVec3 v81; // [sp+108h] [-3298h] BYREF
  idVec3 v82; // [sp+118h] [-3288h] BYREF
  idVec3 v83; // [sp+128h] [-3278h] BYREF
  idVec3 v84; // [sp+138h] [-3268h] BYREF
  idVec3 v85; // [sp+148h] [-3258h] BYREF
  idStr v86; // [sp+160h] [-3240h] BYREF
  idStr v87; // [sp+180h] [-3220h] BYREF
  idMD6Util::animDelta_t v88; // [sp+1A0h] [-3200h] BYREF
  trace_t v89; // [sp+1D0h] [-31D0h] BYREF
  trace_t v90; // [sp+250h] [-3150h] BYREF
  idMD6Util::idJointCache v91; // [sp+2D0h] [-30D0h] BYREF

  if ( (gameLocal->GetGameFlags(this: gameLocal) & 2) == 0 )
  {
    idNavigationSpace::idNavigationSpace(this: &v72);
    Physics = idEntity::GetPhysics(this: result);
    v5 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = *(float *)(v5 + 4);
    v7 = *(float *)(v5 + 8);
    v73.x = *(float *)v5;
    v73.y = v6;
    v73.z = v7;
    v8 = idEntity::GetPhysics(this: result);
    v9 = (int)v8->GetAxis(this: v8, a2: 0);
    v10 = v76;
    v11 = (_DWORD *)(v9 - 4);
    for ( i = 9; i != 0; --i )
      *++v10 = *(float *)++v11;
    v13 = (idNpLink *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 8u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
    if ( v13 != nullptr )
      v14 = idNpLink::idNpLink(this: v13);
    else
      v14 = nullptr;
    LODWORD(result[1].renderModelInfo.color.a) = v14;
    v15 = result[1].__vftable;
    v75 = vec3_origin;
    if ( v15 != nullptr )
    {
      b_high = HIBYTE(result[1].renderModelInfo.color.b);
      v17 = v76[6];
      v18 = v76[5];
      LOBYTE(result[1].renderModelInfo.color.g) = 0;
      v19 = v76[4];
      if ( b_high != 0 )
      {
        x = *(float *)&result[1].targets.size;
        y = *(float *)&result[1].targets.granularity;
        z = *(float *)&result[1].renderModelInfo.model;
        v75.x = *(float *)&result[1].targets.size;
        v75.y = y;
        v75.z = z;
      }
      else
      {
        idMD6Util::idJointCache::idJointCache(this: &v91, webPath: (idAnimWebPath *)&result[1], frameNum: -1);
        p_z = &v88.deltaTranslation.z;
        v24 = 9;
        p_y = &mat2_identity.mat[1].y;
        v88.deltaTranslation = vec3_origin;
        do
        {
          *++p_z = *++p_y;
          --v24;
        }
        while ( v24 != 0 );
        idMD6Util::idJointCache::GetDelta(this: &v91, delta: &v88, jointName: "origin", refJointName: "origin");
        v26 = (float)(v73.z
                    + (float)((float)(v76[3] * v88.deltaTranslation.x)
                            + (float)((float)((float)v17 * v88.deltaTranslation.y)
                                    + (float)(v76[9] * v88.deltaTranslation.z))));
        v74.z = v73.z
              + (float)((float)(v76[3] * v88.deltaTranslation.x)
                      + (float)((float)((float)v17 * v88.deltaTranslation.y) + (float)(v76[9] * v88.deltaTranslation.z)));
        v27 = (float)(v73.y
                    + (float)((float)(v76[2] * v88.deltaTranslation.x)
                            + (float)((float)((float)v18 * v88.deltaTranslation.y)
                                    + (float)(v76[8] * v88.deltaTranslation.z))));
        v74.y = v73.y
              + (float)((float)(v76[2] * v88.deltaTranslation.x)
                      + (float)((float)((float)v18 * v88.deltaTranslation.y) + (float)(v76[8] * v88.deltaTranslation.z)));
        v28 = (float)((float)((float)(v76[7] * v88.deltaTranslation.z)
                            + (float)((float)(v76[1] * v88.deltaTranslation.x)
                                    + (float)((float)v19 * v88.deltaTranslation.y)))
                    + v73.x);
        v74.x = (float)((float)(v76[7] * v88.deltaTranslation.z)
                      + (float)((float)(v76[1] * v88.deltaTranslation.x) + (float)((float)v19 * v88.deltaTranslation.y)))
              + v73.x;
        idStr::idStr(this: &v87, text: &byte_8200D768);
        idAnimWebPath::GetSubWebName(this: (idAnimWebPath *)&result[1], subWebName: &v87);
        v29 = _cntlzw(idStr::Cmp(s1: v87.data, s2: "fall_traversal"));
        v30 = (v29 & 0x20) != 0;
        if ( (v29 & 0x20) == 0 )
        {
          idAnimWebPath::GetSubWebName(this: (idAnimWebPath *)&result[1].spawnOrientation.mat[0].z, subWebName: &v87);
          v86.len = 0;
          v86.allocedAndFlag = 20;
          v86.data = v86.baseBuffer;
          v86.baseBuffer[0] = 0;
          v30 = idStr::Cmp(s1: v87.data, s2: v86.baseBuffer) != 0;
          idStr::FreeData(this: &v86);
        }
        if ( v30 )
        {
          entityNumber = result->entityNumber;
          v77.x = (float)v28 - (float)(vec3_up.x * (float)4096.0);
          v77.z = (float)v26 - (float)(vec3_up.z * (float)4096.0);
          v77.y = (float)v27 - (float)(vec3_up.y * (float)4096.0);
          if ( idClip::TracePoint(
                 this: &clientGame->clip,
                 result: &v89,
                 start: &v74,
                 end: &v77,
                 clipMask: 106513,
                 passEntityNumber: entityNumber) )
          {
            if ( (unsigned int)(LODWORD(result[1].renderModelInfo.dimShadowClipZ) - 1) <= 4 )
            {
              if ( LODWORD(result[1].renderModelInfo.dimShadowClipZ) == 2 )
              {
                v32 = clientGame;
                clip32x32 = clientGame->clip.clip32x32;
              }
              else if ( LODWORD(result[1].renderModelInfo.dimShadowClipZ) == 3 )
              {
                v32 = clientGame;
                clip32x32 = clientGame->clip.clip48x48;
              }
              else
              {
                v32 = clientGame;
                clip32x32 = LODWORD(result[1].renderModelInfo.dimShadowClipZ) == 1
                          ? clientGame->clip.clip16x16
                          : clientGame->clip.clip96x96;
              }
              if ( clip32x32 != nullptr )
              {
                v34 = (float)((float)16.0 - clip32x32->bounds.b[0].z);
                v35 = (float)((float)v34 * (float)v34);
                idClip::TraceBounds(
                  this: &v32->clip,
                  result: &v90,
                  start: &v74,
                  end: &v77,
                  trm: clip32x32,
                  clipMask: 106513,
                  passEntityNumber: result->entityNumber);
                if ( (float)((float)((float)(v90.endpos.x - v89.endpos.x) * (float)(v90.endpos.x - v89.endpos.x))
                           + (float)((float)((float)(v90.endpos.y - v89.endpos.y) * (float)(v90.endpos.y - v89.endpos.y))
                                   + (float)((float)(v90.endpos.z - v89.endpos.z) * (float)(v90.endpos.z - v89.endpos.z)))) > v35 )
                {
                  data = result->name.data;
                  if ( data == nullptr )
                    data = "<NULL>";
                  idLib::Warning(
                    fmt: "The fall trajectory is obstructed by collision on layer %s for %s. This may result in problems when "
                    "a character uses this fall traversal.",
                    navLayerNames[LODWORD(result[1].renderModelInfo.dimShadowClipZ)],
                    data);
                }
              }
            }
          }
          else
          {
            v37 = result->name.data;
            if ( v37 == nullptr )
              v37 = "<NULL>";
            idLib::Warning(fmt: "No navigation surface under fall traversal for %s.", v37);
          }
        }
        idStr::FreeData(this: &v87);
        z = v75.z;
        y = v75.y;
        x = v75.x;
      }
      v38 = *(float *)&result[1].targets.num;
      if ( v38 == 0.0 )
      {
        result[1].renderModelInfo.maxTexelDensity = y;
        result[1].renderModelInfo.maxVisibleRange = z;
        *((float *)&result[1].renderModelInfo + 1) = x;
        *(float *)&result[1].targets.size = x;
        *(float *)&result[1].targets.granularity = result[1].renderModelInfo.maxTexelDensity;
        *(float *)&result[1].renderModelInfo.model = result[1].renderModelInfo.maxVisibleRange;
        idNpLink::CreateLink(
          this: (idNpLink *)LODWORD(result[1].renderModelInfo.color.a),
          space: &v72,
          ent: result,
          start: &v73,
          end: &v75,
          linkType: LinkType_Custom,
          parms: (const idNpLinkData *)&result[1].renderModelInfo.dimShadowClipZ,
          autoDelete: true);
      }
      else
      {
        v39 = v73.z;
        v40 = v73.y;
        *(float *)&result[1].targets.granularity = (float)y + (float)((float)((float)v18 * (float)-v38) * (float)0.5);
        *(float *)&result[1].renderModelInfo.model = (float)z + (float)((float)((float)v17 * (float)-v38) * (float)0.5);
        *(float *)&result[1].targets.size = (float)((float)((float)v19 * (float)-v38) * (float)0.5) + (float)x;
        v41 = (float)((float)((float)v18 * *(float *)&result[1].targets.num) * (float)0.5);
        v42 = (float)((float)((float)v19 * *(float *)&result[1].targets.num) * (float)0.5);
        result[1].renderModelInfo.maxVisibleRange = (float)z
                                                  + (float)((float)((float)v17 * *(float *)&result[1].targets.num)
                                                          * (float)0.5);
        result[1].renderModelInfo.maxTexelDensity = (float)y + (float)v41;
        *((float *)&result[1].renderModelInfo + 1) = (float)v42 + (float)x;
        v43 = *(float *)&result[1].targets.num;
        v44 = (float)((float)v18 * *(float *)&result[1].targets.num);
        v45 = (float)((float)v17 * *(float *)&result[1].targets.num);
        v48 = (float)((float)v19 * (float)-v43);
        v49 = (float)((float)((float)v17 * *(float *)&result[1].targets.num) * (float)0.5);
        v50 = (float)((float)((float)v18 * (float)-v43) * (float)0.5);
        v47 = (float)((float)v18 * (float)-v43);
        v51 = (float)((float)((float)v17 * (float)-v43) * (float)0.5);
        v46 = (float)((float)v17 * (float)-v43);
        v53 = (float)((float)((float)v19 * *(float *)&result[1].targets.num) * (float)0.5);
        v52 = (float)((float)v19 * *(float *)&result[1].targets.num);
        v82.y = (float)y + (float)((float)v44 * (float)0.5);
        v82.z = (float)z + (float)v49;
        v80.y = (float)y + (float)v50;
        v80.z = (float)z + (float)v51;
        v85.z = (float)v39 + (float)((float)v45 * (float)0.5);
        v85.y = (float)v40 + (float)((float)v44 * (float)0.5);
        v82.x = (float)v53 + (float)x;
        v80.x = (float)((float)v48 * (float)0.5) + (float)x;
        v84.x = (float)((float)v48 * (float)0.5) + v73.x;
        v85.x = (float)((float)v52 * (float)0.5) + v73.x;
        v84.y = (float)v40 + (float)((float)v47 * (float)0.5);
        a_low = (idNpLink *)LODWORD(result[1].renderModelInfo.color.a);
        v84.z = (float)v39 + (float)((float)v46 * (float)0.5);
        idNpLink::CreateLink(
          this: a_low,
          space: &v72,
          ent: result,
          p0a: &v84,
          p0b: &v85,
          p1a: &v80,
          p1b: &v82,
          linkType: LinkType_Custom,
          parms: v70,
          autoDelete: v71);
      }
    }
    else
    {
      v55 = v76[9];
      v56 = v76[8];
      LOBYTE(result[1].renderModelInfo.color.g) = 1;
      v57 = *((float *)&result[1].renderModelInfo + 1);
      v58 = *(float *)&result[1].targets.num;
      maxTexelDensity = result[1].renderModelInfo.maxTexelDensity;
      v60 = *(float *)&result[1].targets.granularity;
      v61 = (float)((float)v55 * *(float *)&result[1].renderModelInfo.model);
      v63 = *(float *)&result[1].targets.size;
      v64 = (float)((float)(v76[7] * result[1].renderModelInfo.maxVisibleRange)
                  + (float)(v76[4] * result[1].renderModelInfo.maxTexelDensity));
      v65 = (float)((float)(v76[2] * *((float *)&result[1].renderModelInfo + 1))
                  + (float)((float)v56 * result[1].renderModelInfo.maxVisibleRange));
      v62 = (float)((float)v56 * *(float *)&result[1].renderModelInfo.model);
      v66 = (float)((float)(v76[6] * result[1].renderModelInfo.maxTexelDensity)
                  + (float)((float)(v76[3] * *((float *)&result[1].renderModelInfo + 1))
                          + (float)((float)v55 * result[1].renderModelInfo.maxVisibleRange)));
      v67 = (float)((float)(*(float *)&result[1].targets.size * v76[1])
                  + (float)((float)(v76[7] * *(float *)&result[1].renderModelInfo.model)
                          + (float)(v76[4] * *(float *)&result[1].targets.granularity)));
      v78.z = v73.z + (float)((float)(v76[6] * *(float *)&result[1].targets.num) * (float)0.5);
      v78.y = v73.y + (float)((float)(v76[5] * (float)v58) * (float)0.5);
      v81.y = v73.y + (float)((float)(v76[5] * (float)maxTexelDensity) + (float)v65);
      v81.z = v73.z + (float)v66;
      v79.z = v73.z + (float)((float)(v76[6] * (float)v60) + (float)((float)((float)v63 * v76[3]) + (float)v61));
      v79.y = v73.y + (float)((float)(v76[5] * (float)v60) + (float)((float)((float)v63 * v76[2]) + (float)v62));
      v81.x = (float)((float)(v76[1] * (float)v57) + (float)v64) + v73.x;
      v83.x = (float)((float)(v76[4] * (float)-v58) * (float)0.5) + v73.x;
      v83.z = v73.z + (float)((float)(v76[6] * (float)-v58) * (float)0.5);
      v78.x = (float)((float)(v76[4] * (float)v58) * (float)0.5) + v73.x;
      v79.x = (float)v67 + v73.x;
      v83.y = v73.y + (float)((float)(v76[5] * (float)-v58) * (float)0.5);
      idNpLink::CreateLink(
        this: v14,
        space: &v72,
        ent: result,
        p0a: &v83,
        p0b: &v78,
        p1a: &v79,
        p1b: &v81,
        linkType: LinkType_Jump,
        parms: v70,
        autoDelete: v71);
    }
    idCombatStage_useRelaxedChatterVO = Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)result);
    idNpLink::SetLinkEnabled(
      this: (idNpLink *)LODWORD(result[1].renderModelInfo.color.a),
      enabled: (_cntlzw(idCombatStage_useRelaxedChatterVO) & 0x20) != 0);
    idNavigationSpace::~idNavigationSpace(this: &v72);
  }
  return this;
}


// ========================================================================
// __unwind$489245_0
// EA  : 0x82C67984
// RVA : 0x00C67984
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_489245_0()
{
  int v0; // r12

  idNavigationSpace::~idNavigationSpace(this: (idNavigationSpace *)(v0 - 13216 + 100));
}


// ========================================================================
// __unwind$489246_1
// EA  : 0x82C679AC
// RVA : 0x00C679AC
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall _unwind_489246_1(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 13216 + 96), tag: a2);
}


// ========================================================================
// __unwind$489247_1
// EA  : 0x82C679D4
// RVA : 0x00C679D4
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_489247_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13216 + 384));
}


// ========================================================================
// __unwind$489248_0
// EA  : 0x82C679FC
// RVA : 0x00C679FC
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_489248_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13216 + 352));
}


// ========================================================================
// ??1idInfoNavObstacle@@UAA@XZ
// EA  : 0x82C67A30
// RVA : 0x00C67A30
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoNavObstacle::~idInfoNavObstacle(idInfoNavObstacle *this)
{
  idNpObstacle *navObstacle; // r29

  this->__vftable = (idInfoNavObstacle_vtbl *)&idInfoNavObstacle::`vftable';
  navObstacle = this->navObstacle;
  if ( navObstacle != nullptr )
  {
    idNpObstacle::~idNpObstacle(this: this->navObstacle);
    idMem::Free(this: &mem, ptr: navObstacle, align: ALIGN_16);
  }
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$489880
// EA  : 0x82C67A8C
// RVA : 0x00C67A8C
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_489880()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// ?Spawn@idInfoNavObstacle@@QAAXXZ
// EA  : 0x82C67AB8
// RVA : 0x00C67AB8
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoNavObstacle::Spawn(idInfoNavObstacle *this)
{
  if ( this->startOn )
    idInfoNavObstacle::CreateNavObstacle(this);
}


// ========================================================================
// ?OnActivate@idInfoNavObstacle@@UAAXPAVidEntity@@@Z
// EA  : 0x82C67AD0
// RVA : 0x00C67AD0
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoNavObstacle::OnActivate(idInfoNavObstacle *this, idEntity *activator)
{
  idNpObstacle *navObstacle; // r31

  navObstacle = this->navObstacle;
  if ( navObstacle != nullptr )
  {
    idNpObstacle::~idNpObstacle(this: this->navObstacle);
    idMem::Free(this: &mem, ptr: navObstacle, align: ALIGN_16);
    this->navObstacle = nullptr;
  }
  else
  {
    idInfoNavObstacle::CreateNavObstacle(this);
  }
}


// ========================================================================
// ??1idInfoNavRepulsor@@UAA@XZ
// EA  : 0x82C67C80
// RVA : 0x00C67C80
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void __fastcall idInfoNavRepulsor::~idInfoNavRepulsor(idInfoNavRepulsor *this)
{
  idNpRepulsor *navRepulsor; // r29

  this->__vftable = (idInfoNavRepulsor_vtbl *)&idInfoNavRepulsor::`vftable';
  navRepulsor = this->navRepulsor;
  if ( navRepulsor != nullptr )
  {
    idNpRepulsor::~idNpRepulsor(this: this->navRepulsor);
    idMem::Free(this: &mem, ptr: navRepulsor, align: ALIGN_16);
  }
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$489996
// EA  : 0x82C67CDC
// RVA : 0x00C67CDC
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

void _unwind_489996()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// ?Spawn@idInfoNavRepulsor@@QAAXXZ
// EA  : 0x82C67D08
// RVA : 0x00C67D08
// PDB : w:\tech5\tungsten\game\entities\infonav.cpp
// ========================================================================

// attributes: thunk
void __fastcall idInfoNavRepulsor::Spawn(idInfoNavRepulsor *this)
{
  idInfoNavRepulsor::CreateNavRepulsor(this);
}

