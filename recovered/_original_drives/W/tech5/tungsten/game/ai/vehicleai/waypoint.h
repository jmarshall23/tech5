
// ========================================================================
// ??1idWaypoint@@UAA@XZ
// EA  : 0x824FB4A8
// RVA : 0x004FB4A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

void __fastcall idWaypoint::~idWaypoint(idWaypoint *this)
{
  idLinkList<idWaypoint> *p_waypointNode; // r3
  idLinkList<idWaypoint> *next; // r7
  idLinkList<idWaypoint> *prev; // r6

  this->__vftable = (idWaypoint_vtbl *)&idWaypoint::`vftable';
  this->waypointNode.prev->next = this->waypointNode.next;
  next = this->waypointNode.next;
  prev = this->waypointNode.prev;
  p_waypointNode = &this->waypointNode;
  next->prev = prev;
  this->waypointNode.next = p_waypointNode;
  this->waypointNode.prev = p_waypointNode;
  this->waypointNode.head = p_waypointNode;
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)p_waypointNode);
  idEntity::~idEntity(this);
}


// ========================================================================
// ??0idSplineWaypoint@@QAA@XZ
// EA  : 0x824FE9C0
// RVA : 0x004FE9C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

idSplineWaypoint *__fastcall idSplineWaypoint::idSplineWaypoint(idSplineWaypoint *this)
{
  idEntity::idEntity(this);
  this->waypointNode.head = &this->waypointNode;
  this->waypointNode.owner = nullptr;
  this->waypointNode.next = &this->waypointNode;
  this->waypointNode.prev = &this->waypointNode;
  this->waypointNode.owner = this;
  this->__vftable = (idSplineWaypoint_vtbl *)&idSplineWaypoint::`vftable';
  this->splinePathPosition.navSpline = nullptr;
  this->splinePathPosition.distance = 0.0;
  this->splinePathPosition.rightDistance = 0.0;
  this->voiceOver = nullptr;
  this->voSeat = SEAT_DRIVER;
  this->delay = 0.0;
  this->voiceOver2 = nullptr;
  this->voSeat2 = SEAT_DRIVER;
  this->sound = nullptr;
  this->passThroughWaypoint = false;
  this->control.speedLimit = -1.0;
  this->control.stopDistance = -1.0;
  this->control.avoidanceType = OAT_INIT;
  this->control.moveDistance = -1.0;
  this->control.powerTurnTime = -1;
  this->control.decelDistance = -1.0;
  this->control.maxCurveSpeed = -1.0;
  this->control.maxCurveAngle = -1.0;
  this->control.maxStepAngle = -1.0;
  this->control.powerTurnSpeed = -1.0;
  this->control.stopPowerTurnSpeed = -1.0;
  this->control.traversalStepSize = -1.0;
  this->control.backupSpeed = -1.0;
  this->control.maxCurveCosine = -1.0;
  this->control.maxStepCosine = -1.0;
  vaiAction_t::vaiAction_t(this: &this->action);
  this->speedLimit = -1.0;
  this->adaptToTargetSpeed = 0.0;
  this->radius = -1.0;
  this->users.list = nullptr;
  this->users.granularity = 0;
  this->users.memTag = 5;
  this->users.listStatic = 0;
  this->users.size = 0;
  this->users.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->users);
  return this;
}


// ========================================================================
// __unwind$588499
// EA  : 0x824FEAE0
// RVA : 0x004FEAE0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

void _unwind_588499()
{
  int v0; // r12

  idWaypoint::~idWaypoint(this: *(idWaypoint **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$588500
// EA  : 0x824FEB08
// RVA : 0x004FEB08
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

void _unwind_588500()
{
  int v0; // r12

  vaiAction_t::~vaiAction_t(this: (vaiAction_t *)(*(_DWORD *)(v0 - 144 + 164) + 916));
}


// ========================================================================
// ??0idDroneSplineWaypoint@@QAA@XZ
// EA  : 0x8251A850
// RVA : 0x0051A850
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

idDroneSplineWaypoint *__fastcall idDroneSplineWaypoint::idDroneSplineWaypoint(idDroneSplineWaypoint *this)
{
  idSplineWaypoint::idSplineWaypoint(this);
  this->__vftable = (idDroneSplineWaypoint_vtbl *)&idDroneSplineWaypoint::`vftable';
  this->targetWeights.list = nullptr;
  this->targetWeights.granularity = 0;
  this->targetWeights.memTag = 5;
  this->targetWeights.listStatic = 0;
  this->targetWeights.size = 0;
  this->targetWeights.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targetWeights);
  this->toggleDirection = false;
  this->numVisits = 0;
  this->lastVisitTime = 0;
  this->imminentArrivals.list = nullptr;
  this->imminentArrivals.granularity = 0;
  this->imminentArrivals.memTag = 5;
  this->imminentArrivals.listStatic = 0;
  this->imminentArrivals.size = 0;
  this->imminentArrivals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->imminentArrivals);
  this->imminentEta.list = nullptr;
  this->imminentEta.granularity = 0;
  this->imminentEta.memTag = 5;
  this->imminentEta.listStatic = 0;
  this->imminentEta.size = 0;
  this->imminentEta.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->imminentEta);
  return this;
}


// ========================================================================
// __unwind$574626
// EA  : 0x8251A8F8
// RVA : 0x0051A8F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

void _unwind_574626()
{
  int v0; // r12

  idSplineWaypoint::~idSplineWaypoint(this: *(idSplineWaypoint **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$574627
// EA  : 0x8251A920
// RVA : 0x0051A920
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

void _unwind_574627()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1184));
}


// ========================================================================
// __unwind$574628
// EA  : 0x8251A94C
// RVA : 0x0051A94C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

void _unwind_574628()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1212));
}


// ========================================================================
// ?RemoveWayPointUser@idSplineWaypoint@@QAAXPBVidVehicleAI@@@Z
// EA  : 0x82B290A0
// RVA : 0x00B290A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

void __fastcall idSplineWaypoint::RemoveWayPointUser(idSplineWaypoint *this, const idVehicleAI *vAI)
{
  int v2; // r8
  idList<idEntityPtr<idEntity>,58> *p_users; // r3
  int v4; // r4
  int num; // r10
  int i; // r11

  if ( vAI != nullptr )
    v2 = (gameLocal->spawnIds.ptr[vAI->entityNumber] << 13) | vAI->entityNumber;
  else
    v2 = 0x1FFF;
  p_users = (idList<idEntityPtr<idEntity>,58> *)&this->users;
  v4 = 0;
  num = p_users->num;
  if ( num > 0 )
  {
    for ( i = 0; p_users->list[i].spawnId.value != v2; ++i )
    {
      if ( ++v4 >= num )
        return;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_users, index: v4);
  }
}


// ========================================================================
// ?AddWayPointUser@idSplineWaypoint@@QAAXPBVidVehicleAI@@@Z
// EA  : 0x82B2A918
// RVA : 0x00B2A918
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.h
// ========================================================================

void __fastcall idSplineWaypoint::AddWayPointUser(idSplineWaypoint *this, const idVehicleAI *vAI)
{
  int v2; // r7
  idList<idEntityPtr<idEntity>,58> *p_users; // r3
  int v4; // r10
  int num; // r9
  int v6; // r11
  idEntityPtr<idEntity> v7; // [sp+50h] [-10h] BYREF

  if ( vAI != nullptr )
    v2 = (gameLocal->spawnIds.ptr[vAI->entityNumber] << 13) | vAI->entityNumber;
  else
    v2 = 0x1FFF;
  p_users = (idList<idEntityPtr<idEntity>,58> *)&this->users;
  v7.spawnId.value = v2;
  v4 = 0;
  num = p_users->num;
  if ( num <= 0 )
    goto LABEL_10;
  v6 = 0;
  while ( p_users->list[v6].spawnId.value != v2 )
  {
    ++v4;
    ++v6;
    if ( v4 >= num )
      goto LABEL_10;
  }
  if ( v4 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_users, obj: &v7);
}

