
// ========================================================================
// ?Spawn@idWaypoint@@QAAXXZ
// EA  : 0x82B2B448
// RVA : 0x00B2B448
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.cpp
// ========================================================================

void __fastcall idWaypoint::Spawn(idWaypoint *this)
{
  idLinkList<idWaypoint> *head; // r5

  head = gameLocal->waypointEntities.head;
  this->waypointNode.prev->next = this->waypointNode.next;
  this->waypointNode.next->prev = this->waypointNode.prev;
  this->waypointNode.prev = &this->waypointNode;
  this->waypointNode.head = &this->waypointNode;
  this->waypointNode.next = head;
  this->waypointNode.prev = head->prev;
  head->prev = &this->waypointNode;
  this->waypointNode.prev->next = &this->waypointNode;
  this->waypointNode.head = head->head;
}


// ========================================================================
// ?AiReachedWaypoint@idSplineWaypoint@@QAAXPAVidVehicleAI@@@Z
// EA  : 0x82B2B4A8
// RVA : 0x00B2B4A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.cpp
// ========================================================================

void __fastcall idSplineWaypoint::AiReachedWaypoint(
        idSplineWaypoint *this,
        idVehicleAI *ai,
        long double a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  int value; // r9
  idVehicle_Car *v11; // r3
  idVehicle_Car *v12; // r3
  idVehicleOccupant *OccupantVisual; // r31
  int v14; // r9
  idVehicle_Car *v15; // r3
  idVehicle_Car *v16; // r3
  const idDeclVoiceOver *voiceOver; // r4
  int v18; // r9
  idVehicle_Car *v19; // r3
  idVehicle_Car *v20; // r3
  idVehicleOccupant *v21; // r31
  int v22; // r9
  idVehicle_Car *v23; // r3
  idVehicle_Car *v24; // r3
  const idDeclVoiceOver *voiceOver2; // r4
  int v26; // r9
  idVehicle_Car *v27; // r3
  idVehicle_Car *v28; // r3
  idPlayer *v29; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v31; // r3
  idStrId v32[12]; // [sp+50h] [-30h] BYREF

  idVehicleAI::UpdateControlParams(this: ai, params: &this->control, initialize: false, a4: a3, a5, a6, a7, a8);
  idVehicleAI::HandleActions(this: ai, actions: &this->action);
  if ( this->voiceOver != nullptr )
  {
    value = ai->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v11 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v12 = idVehicle_Car::CastTo(c: v11);
    }
    else
    {
      v12 = nullptr;
    }
    OccupantVisual = idVehicle::GetOccupantVisual(this: v12, index: this->voSeat);
    if ( OccupantVisual != nullptr )
    {
      v14 = ai->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
        && (v15 = (idVehicle_Car *)gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
      {
        v16 = idVehicle_Car::CastTo(c: v15);
      }
      else
      {
        v16 = nullptr;
      }
      voiceOver = this->voiceOver;
      v32[0] = v16->voiceOverNameString;
      idVehicleOccupant::PlayVoiceOver(this: OccupantVisual, vo: voiceOver, whoStartedMeTextId: v32);
    }
  }
  if ( this->voiceOver2 != nullptr )
  {
    v18 = ai->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v18 & 0x1FFF] == v18 >> 13
      && (v19 = (idVehicle_Car *)gameLocal->entities.ptr[v18 & 0x1FFF]) != nullptr )
    {
      v20 = idVehicle_Car::CastTo(c: v19);
    }
    else
    {
      v20 = nullptr;
    }
    v21 = idVehicle::GetOccupantVisual(this: v20, index: this->voSeat2);
    if ( v21 != nullptr )
    {
      v22 = ai->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
        && (v23 = (idVehicle_Car *)gameLocal->entities.ptr[v22 & 0x1FFF]) != nullptr )
      {
        v24 = idVehicle_Car::CastTo(c: v23);
      }
      else
      {
        v24 = nullptr;
      }
      voiceOver2 = this->voiceOver2;
      v32[0] = v24->voiceOverNameString;
      idVehicleOccupant::PlayVoiceOver(this: v21, vo: voiceOver2, whoStartedMeTextId: v32);
    }
  }
  if ( this->sound != nullptr )
  {
    v26 = ai->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
      && (v27 = (idVehicle_Car *)gameLocal->entities.ptr[v26 & 0x1FFF]) != nullptr )
    {
      v28 = idVehicle_Car::CastTo(c: v27);
    }
    else
    {
      v28 = nullptr;
    }
    v29 = idVehicle::PlayerIsOccupant(this: v28);
    if ( v29 != nullptr )
    {
      presentable = v29->presentable;
      if ( presentable != nullptr )
        v31 = presentable->GetPlayerInterface_2(this: presentable);
      else
        v31 = nullptr;
      idPresentableVehicle::StartSoundShader(
        this: v31,
        channel: SND_CHANNEL_VOICE,
        shader: this->sound,
        soundShaderFlags: 8,
        peerMask: 0xFFu);
    }
  }
}


// ========================================================================
// ?ScheduleDrone@idDroneSplineWaypoint@@QAAMPAVidDrone@@M@Z
// EA  : 0x82B2B6F8
// RVA : 0x00B2B6F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\waypoint.cpp
// ========================================================================

float __fastcall idDroneSplineWaypoint::ScheduleDrone(
        idDroneSplineWaypoint *this,
        idDrone *drone,
        double eta,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        idDrone *a15)
{
  int GameMs; // r3
  int num; // r9
  idList<idDrone const *,5> *p_imminentArrivals; // r30
  int v21; // r28
  __int64 v22; // r11
  idList<int,5> *p_imminentEta; // r31
  int *list; // r9
  int v25; // r7
  const idDrone **v26; // r11
  const idDrone *v27; // r9
  int *v28; // r8
  int v29; // r6
  char v30; // r9
  int v31; // r10
  int v32; // ctr
  const idDrone **v33; // r11
  const idDrone *v34; // r6
  int *v35; // r11
  int v36; // r5
  int v37; // r11
  int v38; // r11
  bool v39; // zf
  int v40; // r10
  const idDrone **v41; // r9
  int v42; // r11
  int v43; // r11
  int v44; // r10
  int *v45; // r9
  int v46; // r8
  __int64 v47; // r11
  __int64 v48; // r11
  double v49; // fp1
  int *v50; // r11
  __int64 v51; // r11
  unsigned __int64 v53; // [sp+50h] [-40h] BYREF

  a15 = drone;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  num = this->imminentArrivals.num;
  p_imminentArrivals = &this->imminentArrivals;
  v21 = GameMs;
  HIDWORD(v22) = 0;
  if ( num <= 0 )
    goto LABEL_7;
  LODWORD(v22) = 0;
  while ( *(idDrone **)((char *)p_imminentArrivals->list + v22) != drone )
  {
    ++HIDWORD(v22);
    LODWORD(v22) = v22 + 4;
    if ( SHIDWORD(v22) >= num )
      goto LABEL_7;
  }
  if ( HIDWORD(v22) == -1 )
  {
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->imminentArrivals,
      obj: (const encounterGroupRole_t *)&a15);
    p_imminentEta = &this->imminentEta;
    LODWORD(v53) = (int)(float)((float)((float)eta * (float)1000.0) + (float)__SPAIR64__(&unk_82150000, v21));
    HIDWORD(v53) = v53;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->imminentEta,
      obj: (const encounterGroupRole_t *)&v53);
  }
  else
  {
    LODWORD(v22) = GameMs;
    list = this->imminentEta.list;
    v53 = v22;
    p_imminentEta = &this->imminentEta;
    list[HIDWORD(v22)] = (int)(float)((float)((float)eta * (float)1000.0) + (float)v22);
  }
  v25 = this->imminentArrivals.num;
  if ( v25 <= 1 )
    goto LABEL_49;
  if ( v25 == 2 )
  {
    if ( *p_imminentEta->list > p_imminentEta->list[1] )
    {
      v26 = p_imminentArrivals->list;
      v27 = *p_imminentArrivals->list;
      *v26 = p_imminentArrivals->list[1];
      v26[1] = v27;
      v28 = p_imminentEta->list;
      v29 = *p_imminentEta->list;
      *v28 = p_imminentEta->list[1];
      v28[1] = v29;
    }
  }
  else
  {
    do
    {
      v30 = 1;
      v31 = 1;
      v32 = v25 - 1;
      do
      {
        if ( p_imminentEta->list[v31 - 1] > p_imminentEta->list[v31] )
        {
          v30 = 0;
          v33 = &p_imminentArrivals->list[v31];
          v34 = *(v33 - 1);
          *(v33 - 1) = *v33;
          *v33 = v34;
          v35 = &p_imminentEta->list[v31];
          v36 = *(v35 - 1);
          *(v35 - 1) = *v35;
          *v35 = v36;
        }
        ++v31;
        --v32;
      }
      while ( v32 != 0 );
    }
    while ( v30 == 0 );
  }
  if ( *p_imminentEta->list < v21 - 100 )
  {
    v37 = this->imminentArrivals.num;
    if ( v37 > 0 )
    {
      this->imminentArrivals.num = v37 - 1;
      v39 = v37 - 1 <= 0;
      v38 = 0;
      if ( !v39 )
      {
        v40 = 0;
        do
        {
          ++v38;
          v41 = &p_imminentArrivals->list[v40++];
          *v41 = v41[1];
        }
        while ( v38 < this->imminentArrivals.num );
      }
    }
    v42 = p_imminentEta->num;
    if ( v42 > 0 )
    {
      p_imminentEta->num = v42 - 1;
      v39 = v42 - 1 <= 0;
      v43 = 0;
      if ( !v39 )
      {
        v44 = 0;
        do
        {
          ++v43;
          v45 = &p_imminentEta->list[v44++];
          *v45 = v45[1];
        }
        while ( v43 < p_imminentEta->num );
      }
    }
    if ( --v25 <= 1 )
      goto LABEL_49;
  }
  v46 = this->imminentArrivals.num;
  HIDWORD(v47) = 0;
  if ( v46 <= 0 )
  {
LABEL_32:
    HIDWORD(v47) = -1;
LABEL_35:
    LOBYTE(v47) = 0;
    goto LABEL_36;
  }
  LODWORD(v47) = 0;
  while ( *(idDrone **)((char *)p_imminentArrivals->list + v47) != drone )
  {
    ++HIDWORD(v47);
    LODWORD(v47) = v47 + 4;
    if ( SHIDWORD(v47) >= v46 )
      goto LABEL_32;
  }
  if ( v47 < 0 )
    goto LABEL_35;
  LOBYTE(v47) = 1;
  if ( SHIDWORD(v47) >= v25 )
    goto LABEL_35;
LABEL_36:
  if ( (_BYTE)v47 == 0 )
    goto LABEL_49;
  if ( HIDWORD(v47) != 0 )
  {
    if ( HIDWORD(v47) == v25 - 1 )
    {
      if ( (-HIDWORD(v47) & ~HIDWORD(v47)) < 0 )
      {
        LODWORD(v47) = p_imminentEta->list[HIDWORD(v47)] - p_imminentEta->list[HIDWORD(v47) - 1] + 1;
        if ( (int)v47 < 15000 )
        {
          HIDWORD(v47) = &joystick.joyAxis[0][2];
          v53 = v47;
          v49 = (float)((float)((float)15000.0 - (float)v47) / (float)-COLLISION_TIME_FLOAT);
          return *((float *)&v49 + 1);
        }
      }
    }
    else
    {
      v50 = &p_imminentEta->list[HIDWORD(v47)];
      HIDWORD(v51) = *v50 - *(v50 - 1) + 1;
      LODWORD(v51) = v50[1] - *v50 + 1;
      if ( (int)v51 >= SHIDWORD(v51) )
      {
        if ( SHIDWORD(v51) < 15000 )
        {
          v53 = __PAIR64__((idJoystickXenon *)&joystick.joyAxis[0][2], HIDWORD(v51));
          v49 = (float)((float)((float)15000.0
                              - (float)__SPAIR64__((idJoystickXenon *)&joystick.joyAxis[0][2], HIDWORD(v51)))
                      / (float)-COLLISION_TIME_FLOAT);
          return *((float *)&v49 + 1);
        }
      }
      else if ( (int)v51 < 15000 )
      {
        HIDWORD(v51) = &unk_821C0000;
        v53 = v51;
        v49 = (float)((float)((float)15000.0 - (float)v51) / COLLISION_TIME_FLOAT);
        return *((float *)&v49 + 1);
      }
    }
LABEL_49:
    v49 = 0.0;
    return *((float *)&v49 + 1);
  }
  LODWORD(v48) = p_imminentEta->list[1] - *p_imminentEta->list + 1;
  if ( (int)v48 >= 15000 )
    goto LABEL_49;
  HIDWORD(v48) = &unk_821C0000;
  v53 = v48;
  v49 = (float)((float)((float)15000.0 - (float)v48) / COLLISION_TIME_FLOAT);
  return *((float *)&v49 + 1);
}

