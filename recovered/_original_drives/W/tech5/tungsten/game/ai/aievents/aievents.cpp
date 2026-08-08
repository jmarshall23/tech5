
// ========================================================================
// ??0idAIEvent_Vehicle@@QAA@XZ
// EA  : 0x82A454F8
// RVA : 0x00A454F8
// PDB : w:\tech5\tungsten\game\ai\aievents\aievents.cpp
// ========================================================================

idAIEvent_Vehicle *__fastcall idAIEvent_Vehicle::idAIEvent_Vehicle(idAIEvent_Vehicle *this)
{
  idAIEventWedge::idAIEventWedge(this);
  this->__vftable = (idAIEvent_Vehicle_vtbl *)&idAIEvent_Vehicle::`vftable';
  return this;
}


// ========================================================================
// ??0idAIEvent_PlayerAim@@QAA@XZ
// EA  : 0x82A45538
// RVA : 0x00A45538
// PDB : w:\tech5\tungsten\game\ai\aievents\aievents.cpp
// ========================================================================

idAIEvent_PlayerAim *__fastcall idAIEvent_PlayerAim::idAIEvent_PlayerAim(idAIEvent_PlayerAim *this)
{
  idAIEventTrace::idAIEventTrace(this);
  this->__vftable = (idAIEvent_PlayerAim_vtbl *)&idAIEvent_PlayerAim::`vftable';
  return this;
}


// ========================================================================
// ?GetDistance@idAIEvent_PlayerAim@@UBAMXZ
// EA  : 0x82A45578
// RVA : 0x00A45578
// PDB : w:\tech5\tungsten\game\ai\aievents\aievents.cpp
// ========================================================================

float __fastcall idAIEvent_PlayerAim::GetDistance(idAIEvent_PlayerAim *this)
{
  int value; // r10
  idEntity *v2; // r3
  idPlayer *v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r31
  double playerAimDistance; // fp31

  value = this->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v3 = (idPlayer *)idEntity::CastTo(c: v2);
  }
  else
  {
    v3 = nullptr;
  }
  v4 = idPlayer::CastTo(c: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->GetEquippedWeapon(this: v4) != nullptr )
  {
    playerAimDistance = gameLocal->world->playerAimDistance;
    _FP13 = (float)(*(float *)v5->GetEquippedWeapon(this: v5)->decl[1].inventoryClass.baseBuffer
                  - (float)playerAimDistance);
    __asm { fsel      f1, f13, f31, f0 }
  }
  else
  {
    _FP1 = gameLocal->world->playerAimDistance;
  }
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ?InternalUpdateAttached@idAIEvent_PlayerAim@@UAA?AW4aiEventUpdateResult_t@idAIEvent@@H@Z
// EA  : 0x82A45670
// RVA : 0x00A45670
// PDB : w:\tech5\tungsten\game\ai\aievents\aievents.cpp
// ========================================================================

int __fastcall idAIEvent_PlayerAim::InternalUpdateAttached(idAIEvent_PlayerAim *this, const int curTime)
{
  int value; // r10
  idEntity *v4; // r3
  idPlayer *v5; // r3
  idPlayer *v6; // r3
  idPlayer *v7; // r30
  idPresentable *presentable; // r3
  float *v10; // r3
  idPresentable *v11; // r3
  int v12; // r11
  float *v13; // r11

  value = this->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = (idPlayer *)idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  v6 = idPlayer::CastTo(c: v5);
  v7 = v6;
  if ( v6 == nullptr )
    return 1;
  presentable = v6->presentable;
  if ( presentable != nullptr )
    v10 = (float *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v10 = nullptr;
  this->origin.x = v10[11633];
  this->origin.y = v10[11634];
  this->origin.z = v10[11635];
  v11 = v7->presentable;
  if ( v11 != nullptr )
    v12 = (int)v11->GetPlayerInterface_2(this: v11);
  else
    v12 = 0;
  v13 = (float *)(v12 + 46544);
  this->dir.x = *v13;
  this->dir.y = v13[1];
  this->dir.z = v13[2];
  return 0;
}


// ========================================================================
// ?InternalUpdateAttached@idAIEvent_Vehicle@@UAA?AW4aiEventUpdateResult_t@idAIEvent@@H@Z
// EA  : 0x82A45790
// RVA : 0x00A45790
// PDB : w:\tech5\tungsten\game\ai\aievents\aievents.cpp
// ========================================================================

idAIEvent::aiEventUpdateResult_t __fastcall idAIEvent_Vehicle::InternalUpdateAttached(
        idAIEvent_Vehicle *this,
        int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  idVehicle *v6; // r3
  idVehicle *v7; // r3
  idPlayer *v8; // r29
  idPlayer *Driver; // r31
  int v11; // r9
  idEntity *v12; // r3
  idEntity *v13; // r3
  idPhysics *Physics; // r3
  double v15; // fp13
  double v16; // fp11
  double v17; // fp5
  double v20; // fp1
  double v21; // fp1
  double v22; // fp7
  double v23; // fp0
  double v24; // fp13
  const idDeclAiEvent *eventDecl; // r11
  double v26; // fp30
  double lookAheadTime; // fp0
  double v28; // fp0
  double v29; // fp31
  float v30; // [sp+50h] [-50h] BYREF
  float v31; // [sp+54h] [-4Ch]
  float v32; // [sp+58h] [-48h]

  value = this->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = (idVehicle *)idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  v7 = idVehicle::CastTo(c: v6);
  v8 = (idPlayer *)v7;
  if ( v7 == nullptr )
    return AIUPDATE_REMOVE;
  Driver = (idPlayer *)idVehicle::GetDriver(this: v7);
  if ( idPlayer::CastTo(c: Driver) == nullptr && idAI2::CastTo(c: (idAI2 *)Driver) == nullptr )
    Driver = v8;
  if ( Driver != nullptr )
    this->instigator.spawnId.value = (gameLocal->spawnIds.ptr[Driver->entityNumber] << 13) | Driver->entityNumber;
  else
    this->instigator.spawnId.value = 0x1FFF;
  v11 = this->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13 && (v12 = gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
    v13 = idEntity::CastTo(c: v12);
  else
    v13 = nullptr;
  Physics = idEntity::GetPhysics(this: v13);
  Physics->GetLinearVelocity(this: (idPhysics *)&v30, result: (idVec3 *)Physics, a3: 0);
  v15 = v32;
  v16 = v31;
  v17 = (float)((float)(v30 * v30) + (float)((float)(v31 * v31) + (float)(v32 * v32)));
  _FP4 = (float)((float)((float)(v30 * v30) + (float)((float)(v31 * v31) + (float)(v32 * v32)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f12 }
  v20 = __frsqrte(_FP2);
  v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)(v30 * v30) + (float)((float)(v31 * v31) + (float)(v32 * v32)))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20)
                                              * (float)((float)((float)(v30 * v30)
                                                              + (float)((float)(v31 * v31) + (float)(v32 * v32)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                              * (float)((float)((float)(v30 * v30)
                                                                                              + (float)((float)(v31 * v31) + (float)(v32 * v32)))
                                                                                      * (float)0.5))
                                                                      * (float)v20)
                                                              - (float)1.5)
                                              * (float)v20))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v20
                                                      * (float)((float)((float)(v30 * v30)
                                                                      + (float)((float)(v31 * v31) + (float)(v32 * v32)))
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20));
  v22 = (float)((float)-(float)((float)((float)((float)v21
                                              * (float)((float)((float)(v30 * v30)
                                                              + (float)((float)(v31 * v31) + (float)(v32 * v32)))
                                                      * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v23 = (float)(v30
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)(v30 * v30)
                                                                      + (float)((float)(v31 * v31) + (float)(v32 * v32)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  this->dir.x = v30
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)(v30 * v30)
                                                                      + (float)((float)(v31 * v31) + (float)(v32 * v32)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21);
  this->dir.y = (float)v16 * (float)v22;
  v24 = (float)((float)v15 * (float)v22);
  this->dir.z = v24;
  eventDecl = this->eventDecl;
  v30 = v23;
  v31 = (float)v16 * (float)v22;
  v26 = (float)((float)v17 * (float)v22);
  v32 = v24;
  if ( eventDecl != nullptr )
    lookAheadTime = eventDecl->lookAheadTime;
  else
    lookAheadTime = 0.0;
  v28 = (float)((float)lookAheadTime * (float)((float)v17 * (float)v22));
  if ( v28 >= 0.0 )
  {
    v29 = 4096.0;
    if ( v28 <= 4096.0 )
      v29 = v28;
  }
  else
  {
    v29 = 0.0;
  }
  this->radius = v29;
  if ( vai_showSpeedRadius.valueInteger != 0 )
  {
    debugHUD->Clear(this: debugHUD, a2: false);
    debugHUD->SetTextPosition(this: debugHUD, a2: 320, a3: 240);
    debugHUD->Printf(this: debugHUD, a2: "^2SPEED: ^7%.1f\n", LODWORD(v26), v26);
    debugHUD->Printf(this: debugHUD, a2: "^2RADIUS: ^7%.1f\n", LODWORD(v29), v29);
  }
  return idAIEventWedge::InternalUpdateAttached(this, curTime);
}


// ========================================================================
// `dynamic initializer for 'vai_showSpeedRadius''
// EA  : 0x83366EC8
// RVA : 0x01366EC8
// PDB : w:\tech5\tungsten\game\ai\aievents\aievents.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_showSpeedRadius__()
{
  idCVar::idCVar(
    this: &vai_showSpeedRadius,
    name: "vai_showSpeedRadius",
    value: "0",
    flags: 1,
    description: "Show the speed and radius of vehicle ai",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_showSpeedRadius__);
}

