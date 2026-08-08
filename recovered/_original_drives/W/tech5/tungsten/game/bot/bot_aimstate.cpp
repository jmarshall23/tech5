
// ========================================================================
// ??1idBotAimState@@QAA@XZ
// EA  : 0x82B3FE20
// RVA : 0x00B3FE20
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

void __fastcall idBotAimState::~idBotAimState(idBotAimState *this)
{
  `eh vector destructor iterator'(
    ptr: this->aimRequests,
    size: 0x44u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idBotAimState::BotAimRequest_t::~BotAimRequest_t);
}


// ========================================================================
// ?GetAimOffset@idBotAimState@@IAAMM@Z
// EA  : 0x82B3FE38
// RVA : 0x00B3FE38
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

float __fastcall idBotAimState::GetAimOffset(idBotAimState *this, double distToAimPointSqr)
{
  double v3; // fp1
  double v4; // fp0

  v3 = 0.0;
  switch ( bot_aimSkill.valueInteger )
  {
    case 0:
      if ( distToAimPointSqr <= 65536.0 )
        v4 = -0.40000001;
      else
        v4 = -0.55000001;
      break;
    case 1:
      if ( distToAimPointSqr > 262144.0 )
      {
        v4 = 0.34999999;
        break;
      }
LABEL_10:
      v4 = 0.2;
      break;
    case 2:
      if ( distToAimPointSqr <= 1048576.0 )
      {
        v4 = 0.15000001;
        break;
      }
      goto LABEL_10;
    case 3:
      if ( distToAimPointSqr <= 3211264.0 )
        v4 = 0.050000001;
      else
        v4 = 0.1;
      break;
    default:
      v4 = 0.0;
      break;
  }
  if ( distToAimPointSqr >= 16384.0 || bot_aimSkill.valueInteger <= 0 )
    v3 = v4;
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?CalcDesiredViewAngles@idBotAimState@@IAAXABVidVec3@@@Z
// EA  : 0x82B3FF28
// RVA : 0x00B3FF28
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

void __fastcall idBotAimState::CalcDesiredViewAngles(idBotAimState *this, idAngles *desiredAimVector)
{
  double v3; // fp1
  double y; // fp12
  double v5; // fp1
  idVec3 v6; // [sp+50h] [-30h] BYREF

  idVec3::ToAngles180(this: &v6, result: desiredAimVector, epsilon: idMath::FLT_SMALLEST_NON_DENORMAL);
  v3 = idMath::AngleNormalize360(angle: (float)(v6.x - this->desiredViewAngles.pitch));
  if ( v3 > 180.0 )
    v3 = (float)((float)v3 - (float)360.0);
  y = v6.y;
  this->desiredViewAngles.pitch = (float)((float)v3 * (float)0.082999997) + this->desiredViewAngles.pitch;
  v5 = idMath::AngleNormalize360(angle: (float)((float)y - this->desiredViewAngles.yaw));
  if ( v5 > 180.0 )
    v5 = (float)((float)v5 - (float)360.0);
  this->desiredViewAngles.yaw = (float)((float)v5 * (float)0.125) + this->desiredViewAngles.yaw;
  this->desiredViewAngles.roll = 0.0;
}


// ========================================================================
// ?FindIndexOfAimRequestUser@idBotAimState@@IAAHPBD@Z
// EA  : 0x82B3FFF0
// RVA : 0x00B3FFF0
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

int __fastcall idBotAimState::FindIndexOfAimRequestUser(idBotAimState *this, const char *userName)
{
  int v3; // r30
  char **i; // r31

  v3 = 0;
  for ( i = &this->aimRequests[0].aimUserName.data; *(i - 1) == nullptr || idStr::Icmp(s1: *i, s2: userName) != 0; i += 17 )
  {
    if ( ++v3 >= 4 )
      return -1;
  }
  return v3;
}


// ========================================================================
// ??0idBotAimState@@QAA@XZ
// EA  : 0x82B40280
// RVA : 0x00B40280
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

idBotAimState *__fastcall idBotAimState::idBotAimState(idBotAimState *this)
{
  idBotAimState::BotAimRequest_t *aimRequests; // r30

  aimRequests = this->aimRequests;
  this->currentAimPoint = vec3_origin;
  this->owner = nullptr;
  `eh vector constructor iterator'(
    ptr: this->aimRequests,
    size: 0x44u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idBotAimState::BotAimRequest_t::BotAimRequest_t,
    pDtor: (void (__fastcall *)(void *))idBotAimState::BotAimRequest_t::~BotAimRequest_t);
  this->desiredViewAngles.roll = 0.0;
  this->desiredViewAngles.yaw = 0.0;
  this->desiredViewAngles.pitch = 0.0;
  memset(Dst: aimRequests, Val: 0, Size: sizeof(idBotAimState::BotAimRequest_t));
  return this;
}


// ========================================================================
// ?Update@idBotAimState@@QAAXXZ
// EA  : 0x82B40328
// RVA : 0x00B40328
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

void __fastcall idBotAimState::Update(idBotAimState *this)
{
  idPresentable *presentable; // r3
  const idAngles *v3; // r4
  int v4; // r31
  botAimPriority_t aimPriority; // r11
  idPresentable *v6; // r3
  int v7; // r3
  float *v8; // r28
  char v9; // r10
  char *v10; // r11
  char v11; // r26
  char *v12; // r31
  int v13; // r11
  double v14; // fp12
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  double v18; // fp7
  idRenderWorld *v19; // r3
  float *v20; // r31
  double v21; // fp7
  double v22; // fp6
  idRenderWorld *v23; // r3
  int *v24; // r30
  int v25; // r11
  int v26; // r9
  int v27; // r6
  idEntity *v28; // r3
  idEntity *v29; // r3
  idPhysics *Physics; // r3
  float *v31; // r3
  idEntityPtr<idEntity> *v32; // r3
  double v33; // fp9
  double v34; // fp7
  idEntity *v35; // r3
  int v36; // r4
  idEntity *v37; // r3
  double AimOffset; // fp31
  idEntity *v39; // r3
  idEntity *v40; // r3
  idPhysics *v41; // r3
  double v42; // fp12
  double v43; // fp13
  double v44; // fp0
  idRenderWorld *v45; // r3
  double v46; // fp9
  double v47; // fp7
  double v48; // fp6
  float v49; // [sp+50h] [-B0h] BYREF
  float v50; // [sp+54h] [-ACh]
  float v51; // [sp+58h] [-A8h]
  idAngles v52; // [sp+60h] [-A0h] BYREF
  float v53; // [sp+70h] [-90h] BYREF
  float v54; // [sp+74h] [-8Ch]
  float v55; // [sp+78h] [-88h]
  float v56[4]; // [sp+80h] [-80h] BYREF
  float v57[4]; // [sp+90h] [-70h] BYREF
  float v58[4]; // [sp+A0h] [-60h] BYREF

  presentable = this->owner->owner->presentable;
  if ( presentable != nullptr )
    v3 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = nullptr;
  this->desiredViewAngles = *idPresentablePlayer::GetViewAngles(
                               this: (idPresentablePlayer *)&v53,
                               result: v3,
                               includeWeaponKick: true);
  v4 = -1;
  aimPriority = AIM_PRIORITY_NULL;
  if ( this->aimRequests[0].aimUserName.len != 0 && this->aimRequests[0].aimPriority > AIM_PRIORITY_NULL )
  {
    v4 = 0;
    aimPriority = this->aimRequests[0].aimPriority;
  }
  if ( this->aimRequests[1].aimUserName.len != 0 && this->aimRequests[1].aimPriority > aimPriority )
  {
    v4 = 1;
    aimPriority = this->aimRequests[1].aimPriority;
  }
  if ( this->aimRequests[2].aimUserName.len != 0 && this->aimRequests[2].aimPriority > aimPriority )
  {
    v4 = 2;
    aimPriority = this->aimRequests[2].aimPriority;
  }
  if ( this->aimRequests[3].aimUserName.len != 0 && this->aimRequests[3].aimPriority > aimPriority )
  {
    v4 = 3;
  }
  else if ( v4 == -1 )
  {
    return;
  }
  v6 = this->owner->owner->presentable;
  if ( v6 != nullptr )
    v7 = (int)v6->GetPlayerInterface_2(this: v6);
  else
    v7 = 0;
  v8 = (float *)(v7 + 46532);
  if ( bot_showAimPoint.valueInteger == 1 || (v9 = 0, bot_showAimPoint.valueInteger == this->owner->owner->entityNumber) )
    v9 = 1;
  v10 = (char *)this + 68 * v4;
  v11 = v9;
  v12 = v10 + 28;
  v13 = *((_DWORD *)v10 + 8);
  switch ( v13 )
  {
    case 1:
      v24 = (int *)(v12 + 64);
      v25 = *((_DWORD *)v12 + 16) & 0x1FFF;
      v26 = *((int *)v12 + 16) >> 13;
      if ( gameLocal->spawnIds.ptr[v25] == v26 )
      {
        v27 = gameLocal->spawnIds.ptr[v25];
        if ( *((_DWORD *)v12 + 2) == 6 )
        {
          if ( v27 == v26 && (v28 = gameLocal->entities.ptr[v25]) != nullptr )
            v29 = idEntity::CastTo(c: v28);
          else
            v29 = nullptr;
          Physics = idEntity::GetPhysics(this: v29);
          v31 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v33 = (float)(v31[1] - v8[1]);
          v34 = (float)((float)((float)v33 * (float)v33) + (float)((float)(*v31 - *v8) * (float)(*v31 - *v8)));
          v32 = (idEntityPtr<idEntity> *)(v12 + 64);
          if ( v34 >= 36864.0 )
          {
            v35 = idEntityPtr<idEntity const>::operator->(this: v32);
            v36 = 2;
          }
          else
          {
            v35 = idEntityPtr<idEntity const>::operator->(this: v32);
            v36 = 1;
          }
        }
        else
        {
          if ( v27 == v26 && (v37 = gameLocal->entities.ptr[v25]) != nullptr )
            v35 = idEntity::CastTo(c: v37);
          else
            v35 = nullptr;
          v36 = *((_DWORD *)v12 + 2);
        }
        v35->GetAimPoint(this: v35, a2: (const aimPoint_t)v36, a3: (idVec3 *)&v49);
        if ( bot_aimSkill.valueInteger >= 4 )
        {
          v44 = v51;
          v43 = v50;
          v42 = v49;
        }
        else
        {
          AimOffset = idBotAimState::GetAimOffset(
                        this,
                        distToAimPointSqr: (float)((float)((float)(v50 - v8[1]) * (float)(v50 - v8[1]))
                              + (float)((float)(v49 - *v8) * (float)(v49 - *v8))));
          if ( gameLocal->spawnIds.ptr[*v24 & 0x1FFF] == *v24 >> 13
            && (v39 = gameLocal->entities.ptr[*v24 & 0x1FFF]) != nullptr )
          {
            v40 = idEntity::CastTo(c: v39);
          }
          else
          {
            v40 = nullptr;
          }
          v41 = idEntity::GetPhysics(this: v40);
          v41->GetLinearVelocity(this: (idPhysics *)&v53, result: (idVec3 *)v41, a3: 0);
          v42 = (float)((float)(v53 * (float)AimOffset) + v49);
          v49 = (float)(v53 * (float)AimOffset) + v49;
          v43 = (float)((float)(v54 * (float)AimOffset) + v50);
          v50 = (float)(v54 * (float)AimOffset) + v50;
          v44 = (float)((float)(v55 * (float)AimOffset) + v51);
          v51 = (float)(v55 * (float)AimOffset) + v51;
        }
        if ( v11 != 0 )
        {
          v58[2] = v44;
          v58[0] = v42;
          v58[1] = v43;
          v58[3] = 16.0;
          v45 = gameLocal->GetRenderWorld(this: gameLocal);
          v45->DebugSphere(
            this: v45,
            a2: (const idVec4 *)&idColor::colorBlue,
            a3: (const idSphere *)v58,
            a4: 12,
            a5: 0,
            a6: false);
          v44 = v51;
          v43 = v50;
          v42 = v49;
        }
        v46 = (float)((float)v42 - *v8);
        v47 = (float)((float)v43 - v8[1]);
        v48 = (float)((float)v44 - v8[2]);
        this->currentAimPoint.x = v42;
        this->currentAimPoint.y = v43;
        this->currentAimPoint.z = v44;
        v52.pitch = v46;
        v52.yaw = v47;
        v52.roll = v48;
      }
      break;
    case 2:
      v20 = (float *)(v12 + 20);
      v21 = (float)(v20[1] - *(float *)(v7 + 46536));
      v22 = (float)(v20[2] - *(float *)(v7 + 46540));
      v52.pitch = *v20 - *v8;
      v52.yaw = v21;
      v52.roll = v22;
      if ( v9 != 0 )
      {
        v57[0] = *v20;
        v57[1] = v20[1];
        v57[2] = v20[2];
        v57[3] = 16.0;
        v23 = gameLocal->GetRenderWorld(this: gameLocal);
        v23->DebugSphere(
          this: v23,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idSphere *)v57,
          a4: 12,
          a5: 0,
          a6: false);
      }
      this->currentAimPoint.x = *v20;
      this->currentAimPoint.y = v20[1];
      this->currentAimPoint.z = v20[2];
      break;
    case 3:
      v14 = *(float *)(v7 + 46540);
      v15 = (float)(*v8 + *((float *)v12 + 5));
      v16 = (float)(*((float *)v12 + 6) + *(float *)(v7 + 46536));
      v17 = (float)(*((float *)v12 + 7) + *(float *)(v7 + 46540));
      v18 = (float)((float)(*((float *)v12 + 6) + *(float *)(v7 + 46536)) - *(float *)(v7 + 46536));
      v52.pitch = (float)(*v8 + *((float *)v12 + 5)) - *v8;
      v52.yaw = v18;
      v52.roll = (float)v17 - (float)v14;
      if ( v9 != 0 )
      {
        v56[0] = v15;
        v56[1] = v16;
        v56[2] = v17;
        v56[3] = 16.0;
        v19 = gameLocal->GetRenderWorld(this: gameLocal);
        v19->DebugSphere(
          this: v19,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idSphere *)v56,
          a4: 12,
          a5: 0,
          a6: false);
      }
      this->currentAimPoint.x = v15;
      this->currentAimPoint.y = v16;
      this->currentAimPoint.z = v17;
      break;
    default:
      break;
  }
  if ( ((LODWORD(v52.yaw) | LODWORD(v52.roll) | LODWORD(v52.pitch)) & 0x7FFFFFFF) != 0 )
    idBotAimState::CalcDesiredViewAngles(this, desiredAimVector: &v52);
}


// ========================================================================
// ?AddAimRequestPosition@idBotAimState@@QAAXABVidVec3@@W4botAimPriority_t@@PBDM@Z
// EA  : 0x82B40908
// RVA : 0x00B40908
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

void __fastcall idBotAimState::AddAimRequestPosition(
        idBotAimState *this,
        const idVec3 *pos,
        const botAimPriority_t priority,
        const char *userName,
        double aimTimeInSeconds)
{
  int IndexOfAimRequestUser; // r3
  idStr *i; // r11
  char *v12; // r31

  IndexOfAimRequestUser = idBotAimState::FindIndexOfAimRequestUser(this, userName);
  if ( IndexOfAimRequestUser != -1 )
    goto LABEL_7;
  IndexOfAimRequestUser = 0;
  for ( i = &this->aimRequests[0].aimUserName; i->len != 0; i = (idStr *)((char *)i + 68) )
  {
    if ( ++IndexOfAimRequestUser >= 4 )
      return;
  }
  if ( IndexOfAimRequestUser != -1 )
  {
LABEL_7:
    v12 = (char *)this + 68 * IndexOfAimRequestUser;
    *((float *)v12 + 12) = pos->x;
    *((float *)v12 + 13) = pos->y;
    *((float *)v12 + 14) = pos->z;
    *((_DWORD *)v12 + 8) = 2;
    *((_DWORD *)v12 + 9) = 9;
    *((_DWORD *)v12 + 7) = priority;
    idStr::operator=(this: (idStr *)(v12 + 60), text: userName);
    *((_DWORD *)v12 + 23) = 0x1FFF;
    *((_DWORD *)v12 + 11) = (int)(float)((float)1000.0 * (float)aimTimeInSeconds);
    *((_DWORD *)v12 + 10) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  }
}


// ========================================================================
// ?AddAimRequestEntity@idBotAimState@@QAAXPBVidEntity@@W4botAimPriority_t@@PBDW4aimPoint_t@@M@Z
// EA  : 0x82B40A00
// RVA : 0x00B40A00
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

void __fastcall idBotAimState::AddAimRequestEntity(
        idBotAimState *this,
        const idEntity *entity,
        const botAimPriority_t priority,
        const char *userName,
        const aimPoint_t aimPoint,
        double aimTimeInSeconds)
{
  int IndexOfAimRequestUser; // r3
  idStr *i; // r11
  char *v14; // r11
  _DWORD *v15; // r31

  IndexOfAimRequestUser = idBotAimState::FindIndexOfAimRequestUser(this, userName);
  if ( IndexOfAimRequestUser != -1 )
    goto LABEL_7;
  IndexOfAimRequestUser = 0;
  for ( i = &this->aimRequests[0].aimUserName; i->len != 0; i = (idStr *)((char *)i + 68) )
  {
    if ( ++IndexOfAimRequestUser >= 4 )
      return;
  }
  if ( IndexOfAimRequestUser != -1 )
  {
LABEL_7:
    v14 = (char *)this + 68 * IndexOfAimRequestUser;
    v15 = v14 + 28;
    *((idVec3 *)v14 + 4) = vec3_origin;
    *((_DWORD *)v14 + 8) = 1;
    *((_DWORD *)v14 + 7) = priority;
    *((_DWORD *)v14 + 9) = aimPoint;
    idStr::operator=(this: (idStr *)(v14 + 60), text: userName);
    if ( entity != nullptr )
      v15[16] = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
    else
      v15[16] = 0x1FFF;
    v15[4] = (int)(float)((float)1000.0 * (float)aimTimeInSeconds);
    v15[3] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  }
}


// ========================================================================
// ?ClearOldAimRequests@idBotAimState@@IAAXXZ
// EA  : 0x82B40B30
// RVA : 0x00B40B30
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

void __fastcall idBotAimState::ClearOldAimRequests(idBotAimState *this)
{
  float *p_z; // r31
  int i; // r23

  p_z = &this->aimRequests[0].aimVector.z;
  for ( i = 4; i != 0; --i )
  {
    if ( *((_DWORD *)p_z + 1) != 0
      && *((_DWORD *)p_z - 4) + *((_DWORD *)p_z - 3) < idGameTimeManager::GetGameMs(
                                                         this: &clientGame->gameTimeManager,
                                                         type: GAMETIME_SCALED) )
    {
      idStr::Clear(this: (idStr *)(p_z + 1));
      *(p_z - 7) = 0.0;
      *(p_z - 6) = 0.0;
      *(p_z - 4) = 0.0;
      *(p_z - 3) = 0.0;
      *(p_z - 2) = vec3_origin.x;
      *(p_z - 1) = vec3_origin.y;
      *p_z = vec3_origin.z;
      *((_DWORD *)p_z + 9) = 0x1FFF;
      *((_DWORD *)p_z - 5) = 9;
    }
    p_z += 17;
  }
}


// ========================================================================
// ?PostUpdate@idBotAimState@@QAAXXZ
// EA  : 0x82B40BE8
// RVA : 0x00B40BE8
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

// attributes: thunk
void __fastcall idBotAimState::PostUpdate(idBotAimState *this)
{
  idBotAimState::ClearOldAimRequests(this);
}


// ========================================================================
// `dynamic initializer for 'bot_showAimPoint''
// EA  : 0x8336CBF8
// RVA : 0x0136CBF8
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_showAimPoint__()
{
  idCVar::idCVar(
    this: &bot_showAimPoint,
    name: "bot_showAimPoint",
    value: "0",
    flags: 2,
    description: "Set to 1 to show all bot aim points, or the bot number for a specific bot's aim point.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_showAimPoint__);
}


// ========================================================================
// `dynamic initializer for 'bot_aimSkill''
// EA  : 0x8336CC50
// RVA : 0x0136CC50
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_aimSkill__()
{
  idCVar::idCVar(
    this: &bot_aimSkill,
    name: "bot_aimSkill",
    value: "1",
    flags: 2,
    description: "Sets the bots default aiming skill. 0 = EASY, 1 = MEDIUM, 2 = EXPERT, 3 = MASTER, 4 = AIMBOT",
    valueMin: 0.0,
    valueMax: 4.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Could not find AI state, idVS_ds_Car_Chase! ",
    a9: (int)&loc_82B40000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,4>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_aimSkill__);
}

