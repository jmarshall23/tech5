
// ========================================================================
// ?OnActivate@idDrone@@UAAXPAVidEntity@@@Z
// EA  : 0x82C27900
// RVA : 0x00C27900
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::OnActivate(idDrone *this, idEntity *activator)
{
  double activateCuriosityOverride; // fp0

  activateCuriosityOverride = this->activateCuriosityOverride;
  ++this->numActivates;
  if ( activateCuriosityOverride >= 0.0 && activateCuriosityOverride < this->currentScanEntityCuriosity )
    this->currentScanEntityCuriosity = activateCuriosityOverride;
}


// ========================================================================
// ?DeployWeaponNow@idDrone@@QAAXH@Z
// EA  : 0x82C27938
// RVA : 0x00C27938
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::DeployWeaponNow(idDrone *this, int gunId)
{
  int v2; // r28
  double v5; // fp0
  double v6; // fp13
  double v7; // fp12

  v2 = 4 * (gunId + 1433);
  v5 = 0.0;
  v6 = *(float *)((char *)&this->__vftable + v2);
  if ( v6 <= 0.0 && (v6 < 0.0 || this->weaponStatus[gunId] <= 0.0) && this->deployWeaponSound != nullptr )
  {
    idEntity::StopSound(this, channel: SND_CHANNEL_WEAPON2, peerMask: 0xFFu);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_WEAPON,
      shader: this->deployWeaponSound,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
    idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WEAPON, volume: 0.0);
    v5 = 0.0;
  }
  v7 = this->weaponStatus[gunId];
  this->weaponArmTime[gunId] = 0;
  if ( v7 < 1.0 )
    v5 = 0.02;
  *(float *)((char *)&this->__vftable + v2) = v5;
}


// ========================================================================
// ?StowWeaponNow@idDrone@@QAAXH@Z
// EA  : 0x82C27A10
// RVA : 0x00C27A10
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::StowWeaponNow(idDrone *this, int gunId)
{
  int v2; // r28
  double v5; // fp0
  double v6; // fp13
  double v7; // fp13

  v2 = 4 * (gunId + 1433);
  v5 = 0.0;
  v6 = *(float *)((char *)&this->__vftable + v2);
  if ( v6 >= 0.0 && (v6 > 0.0 || this->weaponStatus[gunId] >= 1.0) && this->stowWeaponSound != nullptr )
  {
    idEntity::StopSound(this, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_WEAPON2,
      shader: this->stowWeaponSound,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
    idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WEAPON2, volume: 0.0);
    v5 = 0.0;
  }
  v7 = this->weaponStatus[gunId];
  this->weaponDisarmTime[gunId] = 0;
  if ( v7 > v5 )
    v5 = -0.0099999998;
  *(float *)((char *)&this->__vftable + v2) = v5;
}


// ========================================================================
// ?UpdateMoveStateMemberships@idDrone@@QAAXXZ
// EA  : 0x82C27C10
// RVA : 0x00C27C10
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::UpdateMoveStateMemberships(idDrone *this)
{
  float *v1; // r11
  int v2; // ctr
  double v3; // fp12
  double v4; // fp0

  v1 = &this->moveStateMemberships[1];
  v2 = 3;
  v3 = 1.0;
  do
  {
    if ( *v1 != 0.0 )
    {
      v4 = (float)(v1[4] + *v1);
      *v1 = v1[4] + *v1;
      if ( v4 <= 0.0 )
      {
        *v1 = 0.0;
        v1[4] = 0.0;
      }
      else
      {
        v3 = (float)((float)v3 - (float)v4);
      }
    }
    ++v1;
    --v2;
  }
  while ( v2 != 0 );
  if ( v3 >= 0.0 )
  {
    if ( v3 <= 1.0 )
      this->moveStateMemberships[0] = v3;
    else
      this->moveStateMemberships[0] = 1.0;
  }
  else
  {
    this->moveStateMemberships[0] = 0.0;
  }
}


// ========================================================================
// ?GetDesiredSpeedForMoving@idDrone@@QAAMXZ
// EA  : 0x82C27C90
// RVA : 0x00C27C90
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

float __fastcall idDrone::GetDesiredSpeedForMoving(idDrone *this)
{
  double v1; // fp0
  idDrone::droneMoveState_t val; // r7
  idDrone::droneMoveState_t v3; // r5
  idDrone::droneMoveState_t v4; // r9
  idDrone::droneMoveState_t v5; // r4
  double v6; // fp0
  double v7; // fp1

  if ( (float)(this->dot1to2to3 + this->dot0to1to2) < 1.8 )
    v1 = (float)-(float)((float)((float)((float)1.8 - (float)(this->dot1to2to3 + this->dot0to1to2)) * 17.5)
                       - this->desiredSpeed);
  else
    v1 = (float)((float)((float)((float)(this->dot1to2to3 + this->dot0to1to2) - (float)1.8) * 0.15000001)
               + this->desiredSpeed);
  val = this->moveStates[1].val;
  v3 = this->moveStates[0].val;
  v4 = this->moveStates[2].val;
  v5 = this->moveStates[3].val;
  v6 = (float)-(float)((float)(this->toAhead[0].z * (float)0.050000001) - (float)v1);
  v7 = (float)((float)((float)moveStateScalers[3][v5] * this->moveStateMemberships[3])
             + (float)((float)((float)moveStateScalers[3][v4] * this->moveStateMemberships[2])
                     + (float)((float)((float)moveStateScalers[3][v3] * this->moveStateMemberships[0])
                             + (float)((float)moveStateScalers[3][val] * this->moveStateMemberships[1]))));
  if ( v6 >= (float)((float)((float)moveStateScalers[0][v5] * this->moveStateMemberships[3])
                   + (float)((float)((float)moveStateScalers[0][v4] * this->moveStateMemberships[2])
                           + (float)((float)((float)moveStateScalers[0][v3] * this->moveStateMemberships[0])
                                   + (float)((float)moveStateScalers[0][val] * this->moveStateMemberships[1])))) )
  {
    if ( v6 <= v7 )
      v7 = v6;
  }
  else
  {
    v7 = (float)((float)((float)moveStateScalers[0][v5] * this->moveStateMemberships[3])
               + (float)((float)((float)moveStateScalers[0][v4] * this->moveStateMemberships[2])
                       + (float)((float)((float)moveStateScalers[0][v3] * this->moveStateMemberships[0])
                               + (float)((float)moveStateScalers[0][val] * this->moveStateMemberships[1]))));
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?GetDesiredRollForMoving@idDrone@@QAAMXZ
// EA  : 0x82C27D88
// RVA : 0x00C27D88
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

float __fastcall idDrone::GetDesiredRollForMoving(idDrone *this)
{
  double currentRoll; // fp1
  double v2; // fp10
  double v3; // fp7
  double v4; // fp6
  double v7; // fp9
  double v8; // fp13
  double v9; // fp9
  double v10; // fp11
  double v11; // fp13
  double v12; // fp0
  double v13; // fp12
  double v14; // fp9
  double currentSpeed; // fp0
  double v16; // fp0

  currentRoll = this->currentRoll;
  v2 = (float)((float)(this->toAhead[0].x * vec3_up.y) - (float)(this->toAhead[0].y * vec3_up.x));
  v3 = (float)((float)(this->toAhead[0].z * vec3_up.x) - (float)(this->toAhead[0].x * vec3_up.z));
  v4 = (float)((float)(this->toAhead[0].y * vec3_up.z) - (float)(this->toAhead[0].z * vec3_up.y));
  _FP2 = (float)((float)((float)((float)v4 * (float)v4)
                       + (float)((float)((float)v2 * (float)v2) + (float)((float)v3 * (float)v3)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f11, f2, f3, f13 }
  v7 = __frsqrte(_FP11);
  v8 = (float)((float)-(float)((float)((float)((float)v7
                                             * (float)((float)((float)((float)v4 * (float)v4)
                                                             + (float)((float)((float)v2 * (float)v2)
                                                                     + (float)((float)v3 * (float)v3)))
                                                     * (float)0.5))
                                     * (float)v7)
                             - (float)1.5)
             * (float)v7);
  v9 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7
                                                                             * (float)((float)((float)((float)v4 * (float)v4)
                                                                                             + (float)((float)((float)v2 * (float)v2) + (float)((float)v3 * (float)v3)))
                                                                                     * (float)0.5))
                                                                     * (float)v7)
                                                             - (float)1.5)
                                             * (float)v7)
                                     * (float)((float)((float)((float)v4 * (float)v4)
                                                     + (float)((float)((float)v2 * (float)v2)
                                                             + (float)((float)v3 * (float)v3)))
                                             * (float)0.5))
                             * (float)((float)-(float)((float)((float)((float)v7
                                                                     * (float)((float)((float)((float)v4 * (float)v4)
                                                                                     + (float)((float)((float)v2 * (float)v2)
                                                                                             + (float)((float)v3 * (float)v3)))
                                                                             * (float)0.5))
                                                             * (float)v7)
                                                     - (float)1.5)
                                     * (float)v7))
                     - (float)1.5);
  v10 = (float)((float)((float)-(float)((float)((float)((float)((float)v9 * (float)v8)
                                                      * (float)((float)((float)((float)v4 * (float)v4)
                                                                      + (float)((float)((float)v2 * (float)v2)
                                                                              + (float)((float)v3 * (float)v3)))
                                                              * (float)0.5))
                                              * (float)((float)v9 * (float)v8))
                                      - (float)1.5)
                      * (float)((float)v9 * (float)v8))
              * (float)((float)((float)v4 * (float)v4)
                      + (float)((float)((float)v2 * (float)v2) + (float)((float)v3 * (float)v3))));
  v12 = (float)((float)v3
              * (float)((float)-(float)((float)((float)((float)((float)v9 * (float)v8)
                                                      * (float)((float)((float)((float)v4 * (float)v4)
                                                                      + (float)((float)((float)v2 * (float)v2)
                                                                              + (float)((float)v3 * (float)v3)))
                                                              * (float)0.5))
                                              * (float)((float)v9 * (float)v8))
                                      - (float)1.5)
                      * (float)((float)v9 * (float)v8)));
  v13 = (float)((float)v2
              * (float)((float)-(float)((float)((float)((float)((float)v9 * (float)v8)
                                                      * (float)((float)((float)((float)v4 * (float)v4)
                                                                      + (float)((float)((float)v2 * (float)v2)
                                                                              + (float)((float)v3 * (float)v3)))
                                                              * (float)0.5))
                                              * (float)((float)v9 * (float)v8))
                                      - (float)1.5)
                      * (float)((float)v9 * (float)v8)));
  v11 = (float)((float)v4
              * (float)((float)-(float)((float)((float)((float)((float)v9 * (float)v8)
                                                      * (float)((float)((float)((float)v4 * (float)v4)
                                                                      + (float)((float)((float)v2 * (float)v2)
                                                                              + (float)((float)v3 * (float)v3)))
                                                              * (float)0.5))
                                              * (float)((float)v9 * (float)v8))
                                      - (float)1.5)
                      * (float)((float)v9 * (float)v8)));
  if ( v10 >= 0.0099999998 )
  {
    v14 = __fabs(this->toAhead[0].z);
    currentRoll = (float)((float)((float)((float)((float)v11 * this->toAhead[2].x)
                                        + (float)((float)(this->toAhead[2].z * (float)v13)
                                                + (float)(this->toAhead[2].y * (float)v12)))
                                * (float)300.0)
                        * (float)((float)((float)((float)((float)1.0 - (float)v14) * (float)((float)1.0 - (float)v14))
                                        * (float)((float)1.0 - (float)v14))
                                * (float)((float)1.0 - (float)v14)));
    currentSpeed = this->currentSpeed;
    if ( currentSpeed >= 6.0 )
    {
      v16 = 70.0;
    }
    else if ( currentSpeed >= 0.0 )
    {
      v16 = (float)(this->currentSpeed * (float)11.666667);
    }
    else
    {
      v16 = 0.0;
    }
    if ( currentRoll >= -v16 )
    {
      if ( currentRoll > v16 )
        currentRoll = v16;
    }
    else
    {
      currentRoll = -v16;
    }
  }
  return *((float *)&currentRoll + 1);
}


// ========================================================================
// ?GetModelTransform@idDrone@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C27EF0
// RVA : 0x00C27EF0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::GetModelTransform(idDrone *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this);
  *modelOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
  *modelAxis = this->currentAxis;
}


// ========================================================================
// ?DeployAndStowWeapon@idDrone@@QAAXHHH@Z
// EA  : 0x82C27F88
// RVA : 0x00C27F88
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::DeployAndStowWeapon(idDrone *this, int gunId, int armDelay, int disarmDelay)
{
  int v7; // r28

  if ( armDelay > 0 )
  {
    if ( this->weaponStatus[gunId] == 0.0 && this->weaponArmSpeed[gunId] == 0.0 )
    {
      v7 = 4 * (gunId + 1437);
      if ( *(idDrone_vtbl **)((char *)&this->__vftable + v7) == nullptr )
        *(idDrone_vtbl **)((char *)&this->__vftable + v7) = (idDrone_vtbl *)(idGameTimeManager::GetGameMs(
                                                                               this: &clientGame->gameTimeManager,
                                                                               type: GAMETIME_SCALED)
                                                                           + armDelay);
    }
  }
  else
  {
    idDrone::DeployWeaponNow(this, gunId);
  }
  if ( (-disarmDelay & ~disarmDelay) < 0 )
    this->weaponDisarmTime[gunId] = idGameTimeManager::GetGameMs(
                                      this: &clientGame->gameTimeManager,
                                      type: GAMETIME_SCALED)
                                  + disarmDelay;
}


// ========================================================================
// ?UpdateEngineSound@idDrone@@QAAXW4soundChannel_t@@AAUblendedSounds_t@1@MMMMM@Z
// EA  : 0x82C28058
// RVA : 0x00C28058
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::UpdateEngineSound(
        idDrone *this,
        soundChannel_t channel,
        idDrone::blendedSounds_t *engineSound,
        double speed,
        double closure,
        double thrust,
        double minThrust,
        double maxThrust)
{
  double minThrustVolume; // fp0
  double currentSpeed; // fp13
  double maxSpeedPitch; // fp29
  double maxThrustPitch; // fp30
  double maxPitchByClosing; // fp31

  minThrustVolume = engineSound->minThrustVolume;
  if ( thrust > minThrust )
  {
    if ( thrust < maxThrust )
      minThrustVolume = (float)((float)((float)((float)(engineSound->maxThrustVolume - engineSound->minThrustVolume)
                                              * (float)((float)thrust - (float)minThrust))
                                      / (float)((float)maxThrust - (float)minThrust))
                              + engineSound->minThrustVolume);
    else
      minThrustVolume = engineSound->maxThrustVolume;
  }
  currentSpeed = this->currentSpeed;
  if ( currentSpeed > 4.0 )
  {
    if ( currentSpeed < 12.0 )
      maxSpeedPitch = (float)((float)((float)((float)(engineSound->maxSpeedPitch - engineSound->minSpeedPitch)
                                            * (float)(this->currentSpeed - (float)4.0))
                                    * (float)0.125)
                            + engineSound->minSpeedPitch);
    else
      maxSpeedPitch = engineSound->maxSpeedPitch;
  }
  else
  {
    maxSpeedPitch = engineSound->minSpeedPitch;
  }
  if ( thrust > minThrust )
  {
    if ( thrust < maxThrust )
      maxThrustPitch = (float)((float)((float)((float)(engineSound->maxThrustPitch - engineSound->minThrustPitch)
                                             * (float)((float)thrust - (float)minThrust))
                                     / (float)((float)maxThrust - (float)minThrust))
                             + engineSound->minThrustPitch);
    else
      maxThrustPitch = engineSound->maxThrustPitch;
  }
  else
  {
    maxThrustPitch = engineSound->minThrustPitch;
  }
  maxPitchByClosing = this->maxPitchByClosing;
  if ( closure > -1.0 )
  {
    if ( closure < 1.0 )
      maxPitchByClosing = (float)((float)((float)((float)(this->maxPitchByClosing - this->minPitchByClosing)
                                                * (float)((float)closure - (float)-1.0))
                                        * (float)0.5)
                                + this->minPitchByClosing);
  }
  else
  {
    maxPitchByClosing = this->minPitchByClosing;
  }
  idEntity::SetSoundVolume(this, channel, volume: minThrustVolume);
  idEntity::SetSoundPitch(
    this,
    channel,
    pitch: (float)((float)((float)maxPitchByClosing + (float)maxThrustPitch) + (float)maxSpeedPitch));
}


// ========================================================================
// ?SetEngineSoundVolume@idDrone@@QAAXW4soundChannel_t@@AAUblendedSounds_t@1@MMM@Z
// EA  : 0x82C281E0
// RVA : 0x00C281E0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::SetEngineSoundVolume(
        idDrone *this,
        soundChannel_t channel,
        idDrone::blendedSounds_t *engineSound,
        double thrust,
        double minThrust,
        double maxThrust)
{
  double minThrustVolume; // fp0

  if ( idEntity::IsPlayingSound(this, channel) )
  {
    minThrustVolume = engineSound->minThrustVolume;
    if ( thrust > minThrust )
    {
      if ( thrust < maxThrust )
        minThrustVolume = (float)((float)((float)((float)(engineSound->maxThrustVolume - engineSound->minThrustVolume)
                                                * (float)((float)thrust - (float)minThrust))
                                        / (float)((float)maxThrust - (float)minThrust))
                                + engineSound->minThrustVolume);
      else
        minThrustVolume = engineSound->maxThrustVolume;
    }
    idEntity::SetSoundVolume(
      this,
      channel,
      volume: (float)-(float)((float)(this->engineSoundsFade * (float)100.0) - (float)minThrustVolume));
  }
}


// ========================================================================
// ?ChangeMoveState@idDrone@@QAAXV?$idEnum@W4droneMoveState_t@idDrone@@$04@@M@Z
// EA  : 0x82C28288
// RVA : 0x00C28288
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::ChangeMoveState(idDrone *this, int newState, double time)
{
  double v4; // fp31
  idDrone::droneMoveState_t v5; // r27
  idDrone::droneMoveState_t val; // r26
  double v7; // fp12
  double v8; // fp31
  __int64 v9; // r9
  double v10; // fp0
  int v11; // r9
  int v12; // r11
  float *v13; // r10
  double v14; // fp12
  double v15; // fp9
  double v16; // fp0
  double allowFacingChanges; // fp13
  double allowSpeedChanges; // fp12
  double allowRollChanges; // fp11
  __int32 v20; // r6
  double v21; // fp9
  double v22; // fp0
  double v23; // fp0

  v4 = time;
  v5 = newState;
  if ( newState >= 0 )
  {
    if ( newState >= 5 )
      v5 = DMS_FAST;
  }
  else
  {
    v5 = DMS_STOPPED;
  }
  val = this->moveStates[0].val;
  if ( val >= DMS_STOPPED )
  {
    if ( val >= DMS_NUM_DRONE_MOVE_STATES )
      val = DMS_FAST;
  }
  else
  {
    val = DMS_STOPPED;
  }
  if ( val != v5 )
  {
    if ( time >= 0.0099999998 )
    {
      if ( time > 1.0 )
        v4 = 1.0;
    }
    else
    {
      v4 = 0.0099999998;
    }
    v7 = (float)((float)((float)-1.0
                       / (float)__SPAIR64__(
                                  0x82000000,
                                  idGameTimeManager::GetGameMsPerFrame(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED)))
               * (float)v4);
    if ( v7 >= 0.0 || v7 < -0.5 )
    {
      v8 = DEFAULT_CHANGE_MOVE_STATE_TIME[this->moveStates[0].val][v5];
      LODWORD(v9) = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v7 = (float)((float)((float)-1.0 / (float)v9) * (float)v8);
    }
    v10 = this->moveStateMemberships[1];
    v11 = 1;
    v12 = 2;
    if ( v10 > 0.0 )
    {
      v13 = &this->moveStateMemberships[2];
      do
      {
        if ( v12 >= 4 )
          break;
        if ( *v13 < v10 )
        {
          v10 = *v13;
          v11 = v12;
        }
        ++v12;
        ++v13;
      }
      while ( v10 > 0.0 );
    }
    this->moveStates[v11].val = this->moveStates[0].val;
    this->moveStateMemberships[v11] = this->moveStateMemberships[0];
    this->moveStateMembershipDeltas[v11] = v7;
    v14 = this->moveStateMemberships[3];
    v15 = (float)((float)((float)1.0 - this->moveStateMemberships[1]) - this->moveStateMemberships[2]);
    this->moveStates[0].val = v5;
    v16 = (float)((float)v15 - (float)v14);
    if ( v16 >= 0.0 )
    {
      if ( v16 > 1.0 )
        v16 = 1.0;
    }
    else
    {
      v16 = 0.0;
    }
    allowFacingChanges = this->allowFacingChanges;
    this->moveStateMemberships[0] = v16;
    allowSpeedChanges = this->allowSpeedChanges;
    allowRollChanges = this->allowRollChanges;
    v20 = 5 * val + v5;
    v21 = (float)((float)allowFacingChanges - (float)ALLOW_FACING_CHANGES_FOR_MOVE_STATE_CHANGE[0][v20]);
    this->allowFacingChanges = (float)allowFacingChanges - (float)ALLOW_FACING_CHANGES_FOR_MOVE_STATE_CHANGE[0][v20];
    this->allowSpeedChanges = (float)allowSpeedChanges - (float)ALLOW_SPEED_CHANGES_FOR_MOVE_STATE_CHANGE[0][v20];
    this->allowRollChanges = (float)allowRollChanges - (float)ALLOW_ROLL_CHANGES_FOR_MOVE_STATE_CHANGE[0][v20];
    if ( v21 >= 0.0 )
    {
      if ( v21 > 1.0 )
        this->allowFacingChanges = 1.0;
    }
    else
    {
      this->allowFacingChanges = 0.0;
    }
    v22 = this->allowSpeedChanges;
    if ( v22 >= 0.0 )
    {
      if ( v22 > 1.0 )
        this->allowSpeedChanges = 1.0;
    }
    else
    {
      this->allowSpeedChanges = 0.0;
    }
    v23 = this->allowRollChanges;
    if ( v23 >= 0.0 )
    {
      if ( v23 > 1.0 )
        this->allowRollChanges = 1.0;
    }
    else
    {
      this->allowRollChanges = 0.0;
    }
  }
}


// ========================================================================
// ?NearestSplinePositionFastGuess@idDrone@@QBAMAAVidVec3@@0@Z
// EA  : 0x82C28538
// RVA : 0x00C28538
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idDrone::NearestSplinePositionFastGuess(idDrone *this, idVec3 *goalPos, idVec3 *returnPos)
{
  idVec3 *p_currentPosition; // r30
  char v7; // r20
  double z; // fp3
  float x; // r11
  double v10; // fp5
  double v11; // fp0
  float v12; // r9
  double v13; // fp6
  double v14; // fp2
  double y; // fp12
  double v16; // fp11
  double v17; // fp1
  double v18; // fp13
  double v19; // fp1
  float *p_z; // r11
  int i; // r30
  double v22; // fp9
  double v23; // fp8
  double v24; // fp7
  double v25; // fp11
  double v26; // fp13
  double v27; // fp12
  double v30; // fp28
  double v31; // fp28
  double v32; // fp28
  double v33; // fp28
  double v34; // fp31
  double v37; // fp13
  double v38; // fp13
  double v39; // fp13
  double v40; // fp28
  int v41; // r11
  double v42; // fp0
  double v43; // fp19
  double v44; // fp13
  double v45; // fp18
  double v46; // fp12
  double v47; // fp17
  double v48; // fp20
  float *v49; // r10
  int v50; // r8
  double v51; // fp21
  float *v52; // r11
  double v53; // fp13
  float v54; // r9
  float v55; // r8
  float v56; // r5
  float v57; // r4
  float v58; // r3
  double v59; // fp22
  double v60; // fp23
  double v61; // fp24
  float v62; // r30
  float v63; // r29
  float v64; // r28
  idPhysics *v65; // r3
  const idVec3 *v66; // r3
  float v67; // r15
  float v68; // r14
  float v69; // r3
  float *v70; // r3
  idVec3 *v71; // r6
  _DWORD *v72; // r5
  _BYTE *v73; // r4
  float v74; // r30
  float v75; // r29
  float v76; // r28
  idPhysics *v77; // r3
  const idVec3 *v78; // r3
  float v79; // r16
  float v80; // r10
  float v81; // r7
  float g; // r30
  float b; // r29
  idClientGame *v84; // r11
  float a; // r7
  double v86; // fp0
  double v87; // fp13
  double v88; // fp11
  double v89; // fp10
  double v90; // fp9
  double v91; // fp25
  double v92; // fp26
  double v93; // fp27
  double v94; // fp28
  double v95; // fp30
  double v96; // fp31
  double v97; // fp12
  double v98; // fp13
  double v99; // fp0
  double v100; // fp1
  double v101; // fp0
  double v102; // fp13
  double v103; // fp12
  double v104; // fp12
  double v105; // fp30
  double v106; // fp31
  idPhysics *v107; // r3
  int v108; // r3
  __int64 v109; // r5 OVERLAPPED
  int v110; // r8 OVERLAPPED
  __int64 v111; // r7 OVERLAPPED
  int v112; // r9
  int v113; // r8 OVERLAPPED
  __int128 v114; // r7 OVERLAPPED
  float *v115; // r11
  idPhysics *Physics; // r3
  int v117; // r3
  __int64 v118; // r5 OVERLAPPED
  __int64 v119; // r7 OVERLAPPED
  int v120; // r8
  double v121; // fp31
  int z_low; // r9
  int v123; // r8 OVERLAPPED
  __int128 v124; // r7 OVERLAPPED
  double v125; // fp12
  double v126; // fp6
  __int64 v128; // [sp+8h] [-2B8h]
  __int64 v129; // [sp+8h] [-2B8h]
  __int64 v130; // [sp+8h] [-2B8h]
  __int64 v131; // [sp+10h] [-2B0h]
  __int64 v132; // [sp+10h] [-2B0h]
  __int64 v133; // [sp+10h] [-2B0h]
  __int64 v134; // [sp+18h] [-2A8h]
  __int64 v135; // [sp+18h] [-2A8h]
  __int64 v136; // [sp+18h] [-2A8h]
  __int64 v137; // [sp+20h] [-2A0h]
  __int64 v138; // [sp+20h] [-2A0h]
  __int64 v139; // [sp+20h] [-2A0h]
  __int64 v140; // [sp+28h] [-298h]
  __int64 v141; // [sp+28h] [-298h]
  __int64 v142; // [sp+28h] [-298h]
  __int64 v143; // [sp+30h] [-290h]
  __int64 v144; // [sp+30h] [-290h]
  __int64 v145; // [sp+30h] [-290h]
  __int64 v146; // [sp+38h] [-288h]
  __int64 v147; // [sp+38h] [-288h]
  __int64 v148; // [sp+38h] [-288h]
  idVec3 v149; // [sp+60h] [-260h] BYREF
  idVec3 v150; // [sp+70h] [-250h] BYREF
  idVec3 v151; // [sp+80h] [-240h] BYREF
  idVec3 v152; // [sp+90h] [-230h] BYREF
  _DWORD v153[4]; // [sp+A0h] [-220h] BYREF
  idVec3 v154; // [sp+B0h] [-210h] BYREF
  _DWORD v155[4]; // [sp+C0h] [-200h] BYREF
  _DWORD v156[4]; // [sp+D0h] [-1F0h] BYREF
  idVec3 v157; // [sp+E0h] [-1E0h] BYREF
  _DWORD v158[4]; // [sp+F0h] [-1D0h] BYREF
  _DWORD v159[4]; // [sp+100h] [-1C0h] BYREF
  _DWORD v160[4]; // [sp+110h] [-1B0h] BYREF
  float v161; // [sp+120h] [-1A0h] BYREF
  float v162; // [sp+124h] [-19Ch]
  float v163; // [sp+128h] [-198h]
  idColor v164; // [sp+130h] [-190h] BYREF
  idColor v165; // [sp+140h] [-180h] BYREF
  _BYTE v166[16]; // [sp+150h] [-170h] BYREF
  _BYTE v167[16]; // [sp+160h] [-160h] BYREF
  idStr v168[5]; // [sp+170h] [-150h] BYREF

  *returnPos = this->currentPosition;
  p_currentPosition = &this->currentPosition;
  v7 = g_droneDebugAiCollisions.valueInteger != 0;
  if ( g_droneDebugAiCollisions.valueInteger != 0 && g_droneDebugOnlyUpdateOne.valueInteger > 0 )
  {
    idStr::idStr(this: v168, text: this->name.data);
    v7 = g_droneDebugOnlyUpdateOne.valueInteger + 48 != v168[0].data[v168[0].len - 1] ? 0 : v7;
    idStr::FreeData(this: v168);
  }
  z = p_currentPosition->z;
  x = this->toAhead[0].x;
  v10 = goalPos->z;
  v11 = (float)(goalPos->z - p_currentPosition->z);
  v12 = this->toAhead[0].z;
  v13 = goalPos->x;
  v14 = p_currentPosition->x;
  v149.y = this->toAhead[0].y;
  y = v149.y;
  v149.x = x;
  v149.z = v12;
  v16 = v12;
  v17 = p_currentPosition->y;
  v18 = x;
  if ( (float)((float)(v149.y * (float)(goalPos->y - p_currentPosition->y))
             + (float)((float)((float)((float)v13 - (float)v14) * x) + (float)(v12 * (float)v11))) <= 0.0 )
  {
    v19 = MAX_SPLINE_AHEAD_DISTANCE;
    return *((float *)&v19 + 1);
  }
  p_z = &this->aheadToAhead[0].z;
  for ( i = 0; ; ++i )
  {
    v25 = (float)((float)((float)v16 + *p_z) * (float)0.5);
    v26 = (float)((float)((float)v18 + *(p_z - 2)) * (float)0.5);
    v27 = (float)((float)((float)y + *(p_z - 1)) * (float)0.5);
    _FP28 = (float)((float)((float)((float)v27 * (float)v27)
                          + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f28, f28, f31, f10 }
    v30 = __frsqrte(_FP28);
    v31 = (float)((float)-(float)((float)((float)((float)v30
                                                * (float)((float)((float)((float)v27 * (float)v27)
                                                                + (float)((float)((float)v26 * (float)v26)
                                                                        + (float)((float)v25 * (float)v25)))
                                                        * (float)0.5))
                                        * (float)v30)
                                - (float)1.5)
                * (float)v30);
    v32 = (float)((float)-(float)((float)((float)((float)v31
                                                * (float)((float)((float)((float)v27 * (float)v27)
                                                                + (float)((float)((float)v26 * (float)v26)
                                                                        + (float)((float)v25 * (float)v25)))
                                                        * (float)0.5))
                                        * (float)v31)
                                - (float)1.5)
                * (float)v31);
    v33 = (float)((float)-(float)((float)((float)((float)v32
                                                * (float)((float)((float)((float)v27 * (float)v27)
                                                                + (float)((float)((float)v26 * (float)v26)
                                                                        + (float)((float)v25 * (float)v25)))
                                                        * (float)0.5))
                                        * (float)v32)
                                - (float)1.5)
                * (float)v32);
    v34 = (float)((float)v33
                * (float)((float)((float)v27 * (float)v27)
                        + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))));
    v18 = (float)((float)v26 * (float)v33);
    y = (float)((float)v27 * (float)v33);
    v16 = (float)((float)v25 * (float)v33);
    if ( v34 < 0.000099999997 )
    {
      _FP13 = (float)((float)((float)(*p_z * *p_z)
                            + (float)((float)(*(p_z - 2) * *(p_z - 2)) + (float)(*(p_z - 1) * *(p_z - 1))))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f13, f13, f11, f10 }
      v37 = __frsqrte(_FP13);
      v38 = (float)((float)-(float)((float)((float)((float)v37
                                                  * (float)((float)((float)(*p_z * *p_z)
                                                                  + (float)((float)(*(p_z - 2) * *(p_z - 2))
                                                                          + (float)(*(p_z - 1) * *(p_z - 1))))
                                                          * (float)0.5))
                                          * (float)v37)
                                  - (float)1.5)
                  * (float)v37);
      v39 = (float)((float)-(float)((float)((float)((float)v38
                                                  * (float)((float)((float)(*p_z * *p_z)
                                                                  + (float)((float)(*(p_z - 2) * *(p_z - 2))
                                                                          + (float)(*(p_z - 1) * *(p_z - 1))))
                                                          * (float)0.5))
                                          * (float)v38)
                                  - (float)1.5)
                  * (float)v38);
      v22 = *p_z;
      v23 = *(p_z - 2);
      v24 = *(p_z - 1);
      v40 = (float)((float)((float)-(float)((float)((float)((float)v39
                                                          * (float)((float)((float)((float)v22 * (float)v22)
                                                                          + (float)((float)((float)v23 * (float)v23)
                                                                                  + (float)((float)v24 * (float)v24)))
                                                                  * (float)0.5))
                                                  * (float)v39)
                                          - (float)1.5)
                          * (float)v39)
                  * (float)((float)((float)v22 * (float)v22)
                          + (float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24))));
      y = (float)(*(p_z - 1)
                * (float)((float)-(float)((float)((float)((float)v39
                                                        * (float)((float)((float)(*p_z * *p_z)
                                                                        + (float)((float)(*(p_z - 2) * *(p_z - 2))
                                                                                + (float)(*(p_z - 1) * *(p_z - 1))))
                                                                * (float)0.5))
                                                * (float)v39)
                                        - (float)1.5)
                        * (float)v39));
      v16 = (float)(*p_z
                  * (float)((float)-(float)((float)((float)((float)v39
                                                          * (float)((float)((float)(*p_z * *p_z)
                                                                          + (float)((float)(*(p_z - 2) * *(p_z - 2))
                                                                                  + (float)(*(p_z - 1) * *(p_z - 1))))
                                                                  * (float)0.5))
                                                  * (float)v39)
                                          - (float)1.5)
                          * (float)v39));
      v18 = (float)((float)((float)-(float)((float)((float)((float)v39
                                                          * (float)((float)((float)(*p_z * *p_z)
                                                                          + (float)((float)(*(p_z - 2) * *(p_z - 2))
                                                                                  + (float)(*(p_z - 1) * *(p_z - 1))))
                                                                  * (float)0.5))
                                                  * (float)v39)
                                          - (float)1.5)
                          * (float)v39)
                  * *(p_z - 2));
      if ( v40 < 0.000099999997 )
      {
        v18 = 1.0;
        y = 0.0;
        v16 = 0.0;
      }
    }
    if ( (float)((float)((float)((float)v10 - *(p_z - 28)) * (float)v16)
               + (float)((float)((float)((float)v13 - *(p_z - 30)) * (float)v18)
                       + (float)((float)(goalPos->y - *(p_z - 29)) * (float)y))) <= 0.0 )
      break;
    if ( i >= 3 )
    {
      v115 = (float *)(&this->idEventReceiver + i);
      returnPos->x = v115[3040];
      returnPos->y = v115[3041];
      returnPos->z = v115[3042];
      if ( v7 != 0 )
      {
        Physics = idEntity::GetPhysics(this);
        v117 = (int)Physics->GetOrigin(this: Physics, a2: 0);
        v118 = *(_QWORD *)v117;
        v119 = *(_QWORD *)&returnPos->x;
        v120 = __ROL4__(LODWORD(returnPos->z), 32);
        v121 = *(float *)(LODWORD(returnPos->x) - 7688);
        HIDWORD(v119) = __ROL4__(*(_DWORD *)(v117 + 8), 32);
        idDrone::DebugArrow(
          start: *(__int64 *)&idColor::colorRed.b,
          lifetime: *(__int64 *)((char *)&v118 - 4),
          size: v121,
          depthTest: *(__int64 *)((char *)&v119 - 4),
          a5: (int)&aAvSsobjectVCom[20],
          a6: 5,
          a7: v128,
          a8: v131,
          a9: v134,
          a10: v137,
          a11: v140,
          a12: v143,
          a13: v146);
        z_low = LODWORD(returnPos->z);
        v123 = __ROL4__(z_low, 32);
        *((_QWORD *)&v124 + 1) = *(_QWORD *)&returnPos->x;
        DWORD2(v124) = __ROL4__(LODWORD(returnPos->x), 32);
        *(_QWORD *)&v124 = *(_QWORD *)&goalPos->x;
        idDrone::DebugArrow(
          start: *(__int64 *)&idColor::colorRed.b,
          lifetime: *(__int64 *)((char *)&v124 + 4),
          size: v121,
          depthTest: *(__int64 *)&v123,
          a5: z_low,
          a6: 5,
          a7: v130,
          a8: v133,
          a9: v136,
          a10: v139,
          a11: v142,
          a12: v145,
          a13: v148);
      }
      v125 = (float)(goalPos->z - returnPos->z);
      v126 = (float)(goalPos->y - returnPos->y);
      v19 = (float)((float)__fsqrts((float)((float)((float)v126 * (float)v126)
                                          + (float)((float)((float)(goalPos->x - returnPos->x)
                                                          * (float)(goalPos->x - returnPos->x))
                                                  + (float)((float)v125 * (float)v125))))
                  + this->aheadDistance[i]);
      return *((float *)&v19 + 1);
    }
    p_z += 3;
  }
  v41 = i - 1;
  if ( i != 0 )
  {
    v49 = (float *)(&this->idEventReceiver + v41);
    v48 = this->aheadDistance[v41];
    v42 = v49[3068];
    v44 = v49[3069];
    v43 = v49[3040];
    v45 = v49[3041];
    v47 = v49[3042];
    v46 = v49[3070];
  }
  else
  {
    v42 = this->toAhead[0].x;
    v43 = v14;
    v44 = this->toAhead[0].y;
    v45 = v17;
    v46 = this->toAhead[0].z;
    v47 = z;
    v48 = 0.0;
  }
  v152.y = v44;
  v152.x = v42;
  v50 = 4 * (v41 + 3053);
  v152.z = v46;
  v149.z = v47;
  v149.y = v45;
  v149.x = v43;
  v51 = *(float *)((char *)&this->__vftable + v50);
  v52 = (float *)(&this->idEventReceiver + v41);
  v53 = (float)(*(float *)((char *)&this->__vftable + v50) - (float)v48);
  v54 = v52[3044];
  v55 = v52[3045];
  v56 = v52[3071];
  v57 = v52[3072];
  v58 = v52[3073];
  v150.x = v52[3043];
  v59 = v150.x;
  v150.y = v54;
  v60 = v54;
  v150.z = v55;
  v61 = v55;
  v151.x = v56;
  v151.y = v57;
  v151.z = v58;
  if ( v53 > MAX_POSITION_DISTANCE_FOR_SPLINE_ERROR )
  {
    do
    {
      idNavSplinePathMgr::GetWorldPosAlongPath(
        this: (idNavSplinePathMgr *)&v161,
        result: (idVec3 *)this->splinePathMgr,
        splinePath: &this->splinePathToGoal,
        distance: (float)((float)((float)v51 + (float)v48) * (float)0.5));
      if ( (float)((float)((float)((float)v59 - v161) * (float)(goalPos->x - v161))
                 + (float)((float)((float)((float)v61 - v163) * (float)(goalPos->z - v163))
                         + (float)((float)((float)v60 - v162) * (float)(goalPos->y - v162)))) >= 0.0 )
      {
        v74 = v149.x;
        v75 = v149.y;
        v76 = v149.z;
        v149.x = v161;
        v152.x = v161 - (float)v43;
        v43 = v161;
        v149.y = v162;
        v152.y = v162 - (float)v45;
        v45 = v162;
        v149.z = v163;
        v48 = (float)((float)((float)v51 + (float)v48) * (float)0.5);
        v152.z = v163 - (float)v47;
        v47 = v163;
        if ( v7 != 0 )
        {
          v77 = idEntity::GetPhysics(this);
          v78 = v77->GetOrigin(this: v77, a2: 0);
          v79 = v78->x;
          *(float *)v160 = v74;
          v165 = idColor::colorYellow;
          *(float *)&v160[1] = v75;
          v80 = v78->y;
          v81 = v78->z;
          *(float *)&v160[2] = v76;
          *(float *)v158 = v79;
          *(float *)&v158[1] = v80;
          *(float *)&v158[2] = v81;
          ((void (__fastcall *)(idRenderWorld *, idColor *, _DWORD *, _DWORD *, double))clientGame->renderWorld->DebugArrow)(
            a1: clientGame->renderWorld,
            a2: &v165,
            a3: v158,
            a4: v160,
            a5: 5.0);
          v70 = (float *)v166;
          v71 = &v154;
          v73 = v166;
          *(float *)v156 = v74;
          *(float *)&v156[1] = v75;
          v154 = v149;
          v72 = v156;
          *(float *)&v156[2] = v76;
          goto LABEL_22;
        }
      }
      else
      {
        v62 = v150.x;
        v150.x = v161;
        v63 = v150.y;
        v150.y = v162;
        v64 = v150.z;
        v150.z = v163;
        v151.x = (float)v59 - v161;
        v59 = v161;
        v151.y = (float)v60 - v162;
        v60 = v162;
        v151.z = (float)v61 - v163;
        v61 = v163;
        v51 = (float)((float)((float)v51 + (float)v48) * (float)0.5);
        if ( v7 != 0 )
        {
          v65 = idEntity::GetPhysics(this);
          v66 = v65->GetOrigin(this: v65, a2: 0);
          v67 = v66->x;
          v68 = v66->y;
          v69 = v66->z;
          v164 = idColor::colorYellow;
          *(float *)v155 = v62;
          *(float *)&v155[1] = v63;
          *(float *)&v155[2] = v64;
          *(float *)v159 = v67;
          *(float *)&v159[1] = v68;
          *(float *)&v159[2] = v69;
          ((void (__fastcall *)(idRenderWorld *, idColor *, _DWORD *, _DWORD *, double))clientGame->renderWorld->DebugArrow)(
            a1: clientGame->renderWorld,
            a2: &v164,
            a3: v159,
            a4: v155,
            a5: 5.0);
          v70 = (float *)v167;
          v71 = &v157;
          v157 = v150;
          v72 = v153;
          *(float *)v153 = v62;
          v73 = v167;
          *(float *)&v153[1] = v63;
          *(float *)&v153[2] = v64;
LABEL_22:
          g = idColor::colorYellow.g;
          b = idColor::colorYellow.b;
          v84 = clientGame;
          *v70 = idColor::colorYellow.r;
          v70[1] = g;
          a = idColor::colorYellow.a;
          v70[2] = b;
          v70[3] = a;
          ((void (__fastcall *)(idRenderWorld *, _BYTE *, _DWORD *, idVec3 *, double))v84->renderWorld->DebugArrow)(
            a1: v84->renderWorld,
            a2: v73,
            a3: v72,
            a4: v71,
            a5: 5.0);
        }
      }
    }
    while ( (float)((float)v51 - (float)v48) > (double)MAX_POSITION_DISTANCE_FOR_SPLINE_ERROR );
  }
  v86 = goalPos->x;
  v87 = goalPos->y;
  v88 = goalPos->z;
  v89 = (float)(goalPos->y - (float)v45);
  v90 = (float)(goalPos->z - (float)v47);
  v149.x = goalPos->x - (float)v43;
  v149.y = v89;
  v149.z = v90;
  v150.x = (float)v86 - (float)v59;
  v150.y = (float)v87 - (float)v60;
  v150.z = (float)v88 - (float)v61;
  if ( idVec3::NormalizeFast(this: &v149) >= 0.000099999997 )
  {
    v93 = v149.z;
    v92 = v149.y;
    v91 = v149.x;
  }
  else
  {
    v91 = 1.0;
    v92 = 0.0;
    v93 = 0.0;
  }
  if ( idVec3::NormalizeFast(this: &v150) >= 0.000099999997 )
  {
    v96 = v150.z;
    v95 = v150.y;
    v94 = v150.x;
  }
  else
  {
    v94 = 1.0;
    v95 = 0.0;
    v96 = 0.0;
  }
  if ( idVec3::NormalizeFast(this: &v152) >= 0.000099999997 )
  {
    v100 = idVec3::NormalizeFast(this: &v151);
    v97 = v152.x;
    v98 = v152.y;
    v99 = v152.z;
    if ( v100 < 0.000099999997 )
    {
      v151.x = v152.x;
      v151.y = v152.y;
      v151.z = v152.z;
    }
  }
  else if ( idVec3::NormalizeFast(this: &v151) >= 0.000099999997 )
  {
    v97 = v151.x;
    v98 = v151.y;
    v99 = v151.z;
  }
  else
  {
    v97 = 0.0;
    v98 = 0.0;
    v99 = 1.0;
  }
  v101 = __fabs((float)((float)((float)v92 * (float)v98)
                      + (float)((float)((float)v91 * (float)v97) + (float)((float)v93 * (float)v99))));
  v102 = __fabs((float)((float)((float)v94 * v151.x)
                      + (float)((float)((float)v96 * v151.z) + (float)((float)v95 * v151.y))));
  v103 = (float)((float)v102 + (float)v101);
  if ( v103 < 0.000099999997 )
  {
    v101 = 0.000099999997;
    v102 = 0.000099999997;
    v103 = 0.00019999999;
  }
  v104 = (float)((float)1.0 / (float)v103);
  v105 = (float)((float)v104 * (float)v101);
  v106 = (float)((float)v104 * (float)v102);
  returnPos->x = (float)((float)((float)v104 * (float)v102) * (float)v43)
               + (float)((float)((float)v104 * (float)v101) * (float)v59);
  returnPos->y = (float)((float)v45 * (float)((float)v104 * (float)v102))
               + (float)((float)v60 * (float)((float)v104 * (float)v101));
  returnPos->z = (float)((float)v47 * (float)((float)v104 * (float)v102))
               + (float)((float)v61 * (float)((float)v104 * (float)v101));
  if ( v7 != 0 )
  {
    v107 = idEntity::GetPhysics(this);
    v108 = (int)v107->GetOrigin(this: v107, a2: 0);
    v109 = *(_QWORD *)v108;
    v110 = __ROL4__(LODWORD(returnPos->z), 32);
    v111 = *(_QWORD *)&returnPos->x;
    HIDWORD(v111) = __ROL4__(*(_DWORD *)(v108 + 8), 32);
    idDrone::DebugArrow(
      start: *(__int64 *)&idColor::colorGreen.b,
      lifetime: *(__int64 *)((char *)&v109 - 4),
      size: 5.0,
      depthTest: *(__int64 *)&v110,
      a5: (int)&aAvSsobjectVCom[20],
      a6: 5,
      a7: v128,
      a8: v131,
      a9: v134,
      a10: v137,
      a11: v140,
      a12: v143,
      a13: v146);
    v112 = LODWORD(returnPos->z);
    v113 = __ROL4__(v112, 32);
    *((_QWORD *)&v114 + 1) = *(_QWORD *)&returnPos->x;
    DWORD2(v114) = __ROL4__(LODWORD(returnPos->x), 32);
    *(_QWORD *)&v114 = *(_QWORD *)&goalPos->x;
    idDrone::DebugArrow(
      start: *(__int64 *)&idColor::colorGreen.b,
      lifetime: *(__int64 *)((char *)&v114 + 4),
      size: 5.0,
      depthTest: *(__int64 *)&v113,
      a5: v112,
      a6: 5,
      a7: v129,
      a8: v132,
      a9: v135,
      a10: v138,
      a11: v141,
      a12: v144,
      a13: v147);
  }
  v19 = (float)((float)((float)v106 * (float)v48) + (float)((float)v105 * (float)v51));
  return *((float *)&v19 + 1);
}


// ========================================================================
// ?GetDesiredFacingForMoving@idDrone@@QAA?AVidVec3@@XZ
// EA  : 0x82C28ED8
// RVA : 0x00C28ED8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idDrone *__fastcall idDrone::GetDesiredFacingForMoving(idDrone *this, idVec3 *result)
{
  double v2; // fp11
  double z; // fp29
  double v6; // fp6
  double v7; // fp31
  double v8; // fp5
  double v9; // fp9
  double v10; // fp8
  double v13; // fp4
  double v14; // fp0
  double v15; // fp4
  double v16; // fp0
  double v17; // fp0
  double v18; // fp0
  double v19; // fp0
  unsigned int v20; // r7
  double v21; // fp10
  double y; // fp13
  double x; // fp0
  double v24; // fp9
  double v25; // fp5
  double v26; // fp2
  float v27; // r7
  __int128 v28; // r6
  __int64 v29; // r6
  bool v30; // r7
  __int64 v31; // r6
  double v32; // fp0
  double v33; // fp5
  double v34; // fp2
  float v35; // r7
  __int128 v36; // r6
  __int128 v37; // r5 OVERLAPPED
  int v38; // r6
  bool v39; // r7
  __int128 v40; // r6
  bool v41; // r7
  double v42; // fp0
  double v43; // fp5
  double v44; // fp8
  double v45; // fp2
  float v46; // r7
  __int128 v47; // r6
  int v48; // r6 OVERLAPPED
  __int128 v49; // r5 OVERLAPPED
  bool v50; // r7
  __int128 v51; // r6
  bool v52; // r7
  double v53; // fp0
  double v54; // fp5
  double v55; // fp8
  double v56; // fp2
  __int128 v57; // r6
  float v58; // r7
  __int128 v59; // r6
  __int128 v60; // r6
  bool v61; // r7
  __int64 v63; // [sp+8h] [-C8h]
  __int64 v64; // [sp+8h] [-C8h]
  __int64 v65; // [sp+8h] [-C8h]
  __int64 v66; // [sp+8h] [-C8h]
  __int64 v67; // [sp+8h] [-C8h]
  __int64 v68; // [sp+8h] [-C8h]
  __int64 v69; // [sp+8h] [-C8h]
  __int64 v70; // [sp+8h] [-C8h]
  __int64 v71; // [sp+8h] [-C8h]
  __int64 v72; // [sp+10h] [-C0h]
  __int64 v73; // [sp+10h] [-C0h]
  __int64 v74; // [sp+10h] [-C0h]
  __int64 v75; // [sp+10h] [-C0h]
  __int64 v76; // [sp+10h] [-C0h]
  __int64 v77; // [sp+10h] [-C0h]
  __int64 v78; // [sp+10h] [-C0h]
  __int64 v79; // [sp+10h] [-C0h]
  __int64 v80; // [sp+10h] [-C0h]
  __int64 v81; // [sp+18h] [-B8h]
  __int64 v82; // [sp+18h] [-B8h]
  __int64 v83; // [sp+18h] [-B8h]
  __int64 v84; // [sp+18h] [-B8h]
  __int64 v85; // [sp+18h] [-B8h]
  __int64 v86; // [sp+18h] [-B8h]
  __int64 v87; // [sp+18h] [-B8h]
  __int64 v88; // [sp+18h] [-B8h]
  __int64 v89; // [sp+18h] [-B8h]
  __int64 v90; // [sp+20h] [-B0h]
  __int64 v91; // [sp+20h] [-B0h]
  __int64 v92; // [sp+20h] [-B0h]
  __int64 v93; // [sp+20h] [-B0h]
  __int64 v94; // [sp+20h] [-B0h]
  __int64 v95; // [sp+20h] [-B0h]
  __int64 v96; // [sp+20h] [-B0h]
  __int64 v97; // [sp+20h] [-B0h]
  __int64 v98; // [sp+20h] [-B0h]
  __int64 v99; // [sp+28h] [-A8h]
  __int64 v100; // [sp+28h] [-A8h]
  __int64 v101; // [sp+28h] [-A8h]
  __int64 v102; // [sp+28h] [-A8h]
  __int64 v103; // [sp+28h] [-A8h]
  __int64 v104; // [sp+28h] [-A8h]
  __int64 v105; // [sp+28h] [-A8h]
  __int64 v106; // [sp+28h] [-A8h]
  __int64 v107; // [sp+28h] [-A8h]
  __int64 v108; // [sp+50h] [-80h]
  __int64 v109; // [sp+50h] [-80h]

  v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  z = result[966].z;
  v6 = (float)((float)(result[1023].z * (float)0.75) + (float)(result[1024].z * (float)0.25));
  v7 = 0.0;
  v8 = (float)((float)(result[1024].x * (float)0.75) + (float)(result[1025].x * (float)0.25));
  v9 = (float)((float)(result[457].z * result[458].z)
             + (float)((float)(result[459].y * result[458].y) + (float)(result[459].x * result[458].x)));
  v10 = (float)((float)((float)(result[1024].y * (float)0.75) + (float)(result[1025].y * (float)0.25)) * (float)0.5);
  *(float *)&this->listeningToList = (float)((float)(result[1024].y * (float)0.75)
                                           + (float)(result[1025].y * (float)0.25))
                                   * (float)0.5;
  _FP0 = (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v6 * (float)v6)) - (float)v2);
  __asm { fsel      f11, f0, f1, f11 }
  v13 = __frsqrte(_FP11);
  v14 = (float)((float)-(float)((float)((float)((float)v13
                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                              + (float)((float)v6 * (float)v6))
                                                      * (float)0.5))
                                      * (float)v13)
                              - (float)1.5)
              * (float)v13);
  v15 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                                                              + (float)((float)v6 * (float)v6))
                                                                                      * (float)0.5))
                                                                      * (float)v13)
                                                              - (float)1.5)
                                              * (float)v13)
                                      * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v6 * (float)v6))
                                              * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)v13
                                                                      * (float)((float)((float)((float)v8 * (float)v8)
                                                                                      + (float)((float)v6 * (float)v6))
                                                                              * (float)0.5))
                                                              * (float)v13)
                                                      - (float)1.5)
                                      * (float)v13))
                      - (float)1.5);
  v16 = (float)((float)-(float)((float)((float)((float)((float)v15 * (float)v14)
                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                              + (float)((float)v6 * (float)v6))
                                                      * (float)0.5))
                                      * (float)((float)v15 * (float)v14))
                              - (float)1.5)
              * (float)((float)v15 * (float)v14));
  *(float *)&this->__vftable = (float)v6 * (float)v16;
  *(float *)&this->listenerList = (float)v8 * (float)v16;
  if ( z == 0.0 )
  {
    if ( v9 >= 0.0 )
    {
      if ( result[466].x >= (double)result[467].y )
      {
        v17 = (float)((float)((float)((float)(result[466].x - result[467].y) * result[470].x) * (float)v9) * (float)-1.0);
      }
      else
      {
        v19 = result[1026].z;
        if ( v19 > 0.94999999 )
        {
          if ( v19 < 0.99000001 )
            v17 = (float)((float)((float)(result[1026].z - 0.94999999)
                                * (float)((float)(result[467].y - result[466].x) * 0.375))
                        * (float)24.999987);
          else
            v17 = (float)((float)(result[467].y - result[466].x) * 0.375);
        }
        else
        {
          v17 = 0.0;
        }
      }
      goto LABEL_16;
    }
    v18 = (float)(result[466].x - result[467].y);
    if ( v18 > 0.0 )
    {
      if ( v18 < 5.0 )
      {
        v17 = (float)((float)(result[466].x - result[467].y) * (float)0.5);
LABEL_16:
        if ( v17 < -0.66600001 )
        {
          v17 = -0.66600001;
          goto LABEL_20;
        }
        if ( v17 <= 0.66600001 )
          goto LABEL_20;
      }
      v17 = 0.66600001;
      goto LABEL_20;
    }
    v17 = 0.0;
  }
  else
  {
    v17 = 0.34999999;
    if ( result[459].y < 0.34999999 )
    {
      v17 = (float)((float)(0.34999999 - result[459].y) + 0.34999999);
      goto LABEL_16;
    }
  }
LABEL_20:
  v20 = 0x82000000;
  v21 = (float)((float)v17 * (float)0.024999976);
  y = result[456].y;
  v24 = (float)((float)(result[469].y * 0.97500002) + (float)((float)v17 * (float)0.024999976));
  x = result[1014].x;
  result[469].y = (float)(result[469].y * 0.97500002) + (float)v21;
  *(float *)&this->listeningToList = (float)v24 + (float)v10;
  if ( y > x && x < result[1015].x )
  {
    v25 = (float)(result[1014].y - result[455].z);
    v26 = (float)(result[1014].z - result[456].x);
    v7 = (float)((float)((float)((float)((float)y - (float)x) + result[1015].x) - (float)x)
               / (float)__fsqrts((float)((float)((float)v26 * (float)v26)
                                       + (float)((float)((float)v25 * (float)v25)
                                               + (float)((float)(result[1015].x - (float)y)
                                                       * (float)(result[1015].x - (float)y))))));
    if ( g_droneDebugTurnUpBeforeGoingUp.valueInteger != 0 )
    {
      v27 = result[456].y;
      *(_QWORD *)((char *)&v28 + 4) = *(_QWORD *)&result[455].z;
      LODWORD(v28) = __ROL4__(LODWORD(v27), 32);
      idDrone::DebugSphere(
        pos: *(__int64 *)&idColor::colorRed.b,
        radius: 15.0,
        lifetime: v28,
        depthTest: SLOBYTE(v27),
        a5: 12,
        a6: 10,
        a7: false,
        a8: v63,
        a9: v72,
        a10: v81,
        a11: v90,
        a12: v99);
      *(float *)&v29 = result[1013].z + (float)1.0;
      LODWORD(v29) = __ROL4__(result[1014].x + (float)1.0, 32);
      idDrone::DebugSphere(
        pos: *(__int64 *)&idColor::colorYellow.b,
        radius: 15.0,
        lifetime: v29,
        depthTest: v30,
        a5: 12,
        a6: 10,
        a7: false,
        a8: v64,
        a9: v73,
        a10: v82,
        a11: v91,
        a12: v100);
      *(float *)&v31 = result[1014].z + (float)1.0;
      LODWORD(v31) = __ROL4__(result[1015].x + (float)1.0, 32);
      idDrone::DebugSphere(
        pos: *(__int64 *)&idColor::colorGreen.b,
        radius: 15.0,
        lifetime: v31,
        depthTest: (bool)&idColor::colorGreen,
        a5: 12,
        a6: 10,
        a7: false,
        a8: v65,
        a9: v74,
        a10: v83,
        a11: v92,
        a12: v101);
    }
  }
  v32 = result[1014].x;
  if ( result[456].y > v32 && v32 < result[1016].x )
  {
    v33 = (float)(result[1015].y - result[455].z);
    v34 = (float)(result[1015].z - result[456].x);
    v7 = (float)((float)((float)((float)((float)(result[456].y - result[1014].x) + result[1016].x) - result[1014].x)
                       / (float)__fsqrts((float)((float)((float)v34 * (float)v34)
                                               + (float)((float)((float)v33 * (float)v33)
                                                       + (float)((float)(result[1016].x - result[456].y)
                                                               * (float)(result[1016].x - result[456].y))))))
               + (float)v7);
    if ( g_droneDebugTurnUpBeforeGoingUp.valueInteger != 0 )
    {
      v35 = result[456].y;
      *(_QWORD *)((char *)&v36 + 4) = *(_QWORD *)&result[455].z;
      LODWORD(v36) = __ROL4__(LODWORD(v35), 32);
      idDrone::DebugSphere(
        pos: *(__int64 *)&idColor::colorRed.b,
        radius: 15.0,
        lifetime: v36,
        depthTest: SLOBYTE(v35),
        a5: 12,
        a6: 10,
        a7: false,
        a8: v63,
        a9: v72,
        a10: v81,
        a11: v90,
        a12: v99);
      *((float *)&v108 + 1) = result[1013].z - (float)1.0;
      *(float *)&v108 = result[1013].y - (float)1.0;
      DWORD1(v37) = LODWORD(idColor::colorYellow.b);
      v38 = __ROL4__(result[1014].x - (float)1.0, 32);
      *((_QWORD *)&v37 + 1) = v108;
      idDrone::DebugSphere(
        pos: *(__int64 *)((char *)&v37 + 4),
        radius: 15.0,
        lifetime: *(__int64 *)((char *)&v37 - 4),
        depthTest: v39,
        a5: 12,
        a6: 10,
        a7: false,
        a8: v66,
        a9: v75,
        a10: v84,
        a11: v93,
        a12: v102);
      *(_QWORD *)((char *)&v40 + 4) = *(_QWORD *)&result[1015].y;
      LODWORD(v40) = __ROL4__(LODWORD(result[1016].x), 32);
      idDrone::DebugSphere(
        pos: *(_QWORD *)(LODWORD(result[1015].y) + offsetof(idColor, b)),
        radius: 15.0,
        lifetime: v40,
        depthTest: v41,
        a5: 12,
        a6: 10,
        a7: false,
        a8: v67,
        a9: v76,
        a10: v85,
        a11: v94,
        a12: v103);
    }
  }
  v42 = result[1015].x;
  if ( result[456].y > v42 && v42 < result[1016].x )
  {
    v43 = (float)(result[1016].x - result[456].y);
    v44 = (float)(result[1015].z - result[456].x);
    v45 = (float)(result[1015].y - result[455].z);
    v7 = (float)((float)((float)((float)((float)(result[456].y - result[1015].x) + result[1016].x) - result[1015].x)
                       / (float)__fsqrts((float)((float)((float)v45 * (float)v45)
                                               + (float)((float)((float)v43 * (float)v43)
                                                       + (float)((float)v44 * (float)v44)))))
               + (float)v7);
    if ( g_droneDebugTurnUpBeforeGoingUp.valueInteger != 0 )
    {
      v46 = result[456].y;
      *(_QWORD *)((char *)&v47 + 4) = *(_QWORD *)&result[455].z;
      LODWORD(v47) = __ROL4__(LODWORD(v46), 32);
      idDrone::DebugSphere(
        pos: *(__int64 *)&idColor::colorRed.b,
        radius: 15.0,
        lifetime: v47,
        depthTest: SLOBYTE(v46),
        a5: 12,
        a6: 10,
        a7: false,
        a8: v63,
        a9: v72,
        a10: v81,
        a11: v90,
        a12: v99);
      v48 = __ROL4__(result[1015].x - (float)1.0, 32);
      *(float *)&v109 = result[1014].y - (float)1.0;
      *((float *)&v109 + 1) = result[1014].z - (float)1.0;
      DWORD1(v49) = LODWORD(idColor::colorYellow.b);
      *((_QWORD *)&v49 + 1) = v109;
      idDrone::DebugSphere(
        pos: *(__int64 *)((char *)&v49 + 4),
        radius: 15.0,
        lifetime: *(__int64 *)&v48,
        depthTest: v50,
        a5: 12,
        a6: 10,
        a7: false,
        a8: v68,
        a9: v77,
        a10: v86,
        a11: v95,
        a12: v104);
      *(_QWORD *)((char *)&v51 + 4) = *(_QWORD *)&result[1015].y;
      LODWORD(v51) = __ROL4__(LODWORD(result[1016].x), 32);
      idDrone::DebugSphere(
        pos: *(_QWORD *)(LODWORD(result[1015].y) + offsetof(idColor, b)),
        radius: 15.0,
        lifetime: v51,
        depthTest: v52,
        a5: 12,
        a6: 10,
        a7: false,
        a8: v69,
        a9: v78,
        a10: v87,
        a11: v96,
        a12: v105);
    }
  }
  v53 = result[1015].x;
  if ( result[1014].x > v53 && v53 < result[1016].x )
  {
    v54 = (float)(result[1016].x - result[1014].x);
    v55 = (float)(result[1015].z - result[1013].z);
    v56 = (float)(result[1015].y - result[1013].y);
    v7 = (float)((float)((float)((float)((float)(result[1014].x - result[1015].x) + result[1016].x) - result[1015].x)
                       / (float)__fsqrts((float)((float)((float)v56 * (float)v56)
                                               + (float)((float)((float)v54 * (float)v54)
                                                       + (float)((float)v55 * (float)v55)))))
               + (float)v7);
    if ( g_droneDebugTurnUpBeforeGoingUp.valueInteger != 0 )
    {
      *(_QWORD *)((char *)&v57 + 4) = *(_QWORD *)&result[1013].y;
      LODWORD(v57) = __ROL4__(LODWORD(result[1014].x), 32);
      idDrone::DebugSphere(
        pos: *(__int64 *)&idColor::colorRed.b,
        radius: 15.0,
        lifetime: v57,
        depthTest: v20,
        a5: 12,
        a6: 10,
        a7: false,
        a8: v63,
        a9: v72,
        a10: v81,
        a11: v90,
        a12: v99);
      v58 = result[1015].x;
      *(_QWORD *)((char *)&v59 + 4) = *(_QWORD *)&result[1014].y;
      LODWORD(v59) = __ROL4__(LODWORD(v58), 32);
      idDrone::DebugSphere(
        pos: *(__int64 *)&idColor::colorYellow.b,
        radius: 15.0,
        lifetime: v59,
        depthTest: SLOBYTE(v58),
        a5: 12,
        a6: 10,
        a7: false,
        a8: v70,
        a9: v79,
        a10: v88,
        a11: v97,
        a12: v106);
      *(_QWORD *)((char *)&v60 + 4) = *(_QWORD *)&result[1015].y;
      LODWORD(v60) = __ROL4__(LODWORD(result[1016].x), 32);
      idDrone::DebugSphere(
        pos: *(__int64 *)&idColor::colorGreen.b,
        radius: 15.0,
        lifetime: v60,
        depthTest: v61,
        a5: 12,
        a6: 10,
        a7: false,
        a8: v71,
        a9: v80,
        a10: v89,
        a11: v98,
        a12: v107);
    }
  }
  if ( v7 < result[469].z )
    result[469].z = (float)(result[469].z * 0.99000001) + (float)((float)v7 * (float)0.0099999905);
  else
    result[469].z = (float)(result[469].z * 0.96499997) + (float)((float)v7 * (float)0.035000026);
  *(float *)&this->listeningToList = (float)(result[469].z * 5.0) + *(float *)&this->listeningToList;
  return this;
}


// ========================================================================
// ?UpdateFX@idDrone@@UAAXXZ
// EA  : 0x82C29600
// RVA : 0x00C29600
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::UpdateFX(idDrone *this)
{
  idPropsCollection *p_props; // r25
  unsigned __int64 v2; // r20
  const idDeclParticle *groundParticlesFromFan; // r8
  idCVar *v5; // r15
  idTreeAnimator *TreeAnimatorFromPresentable; // r16
  const idDeclMD6 *decl; // r11
  int GameMs; // r3
  double v9; // fp9
  const tagData_t *Tag; // r4
  idClipQuery *fanToGroundQuery; // r23
  unsigned __int64 index; // r11
  idClientGame *v13; // r9
  double particlesMultiplier; // fp0
  double v15; // fp13
  double v16; // fp31
  double v17; // fp31
  idClientGame *v18; // r27
  idClipQuery *v19; // r29
  double v20; // fp0
  double v21; // fp13
  double v22; // fp12
  unsigned __int64 v23; // r11
  int v24; // r29
  double v25; // fp30
  double addedParticleMovement; // fp1
  double v27; // fp2
  double v28; // fp24
  double v29; // fp1
  double v30; // fp12
  double v31; // fp11
  double v32; // fp10
  __int64 v33; // r5
  unsigned int v34; // r9
  double v35; // fp24
  int GameMsPerFrame; // r16
  int v37; // r15
  const idDeclParticle *v38; // r14
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v40; // r7
  int entityNumber; // r29
  const tagData_t *v42; // r4
  int v43; // r10
  idClipQuery *v44; // r29
  unsigned __int64 v45; // r11
  idClientGame *v46; // r9
  int v47; // r3
  idPresentable *presentable; // r11
  int v49; // r28
  long double v50; // fp2
  long double v51; // fp2
  idPresentable *v52; // r11
  double v53; // fp31
  int v54; // r28
  idPhysics *Physics; // r3
  float *v56; // r3
  double v57; // fp13
  double v58; // fp12
  idPhysics *v59; // r3
  const idVec3 *v60; // r3
  idPhysics *v61; // r3
  float *v62; // r3
  double outerRadius; // fp31
  const idDeclDamage *value; // r28
  idWeaponTraceManager *WeaponTraceMgr; // r3
  const idSpawnId *v66; // r5
  double v67; // fp13
  double v68; // fp13
  double v69; // fp13
  double v70; // fp13
  double v71; // fp0
  double v72; // fp0
  int v73; // [sp+8h] [-3E8h]
  int v74; // [sp+8h] [-3E8h]
  int v75; // [sp+Ch] [-3E4h]
  bool v76; // [sp+Fh] [-3E1h]
  const char *v77; // [sp+10h] [-3E0h]
  const char *v78; // [sp+10h] [-3E0h]
  int v79; // [sp+14h] [-3DCh]
  int v80; // [sp+14h] [-3DCh]
  int v81; // [sp+18h] [-3D8h]
  int v82; // [sp+18h] [-3D8h]
  int v83; // [sp+1Ch] [-3D4h]
  int v84; // [sp+1Ch] [-3D4h]
  int v85; // [sp+20h] [-3D0h]
  int v86; // [sp+20h] [-3D0h]
  int v87; // [sp+24h] [-3CCh]
  int v88; // [sp+24h] [-3CCh]
  int v89; // [sp+28h] [-3C8h]
  int v90; // [sp+28h] [-3C8h]
  int v91; // [sp+2Ch] [-3C4h]
  int v92; // [sp+2Ch] [-3C4h]
  int v93; // [sp+30h] [-3C0h]
  int v94; // [sp+30h] [-3C0h]
  int v95; // [sp+34h] [-3BCh]
  int v96; // [sp+34h] [-3BCh]
  int v97; // [sp+38h] [-3B8h]
  int v98; // [sp+38h] [-3B8h]
  int v99; // [sp+3Ch] [-3B4h]
  int v100; // [sp+3Ch] [-3B4h]
  int v101; // [sp+40h] [-3B0h]
  int v102; // [sp+40h] [-3B0h]
  int v103; // [sp+44h] [-3ACh]
  int v104; // [sp+44h] [-3ACh]
  int v105; // [sp+48h] [-3A8h]
  int v106; // [sp+48h] [-3A8h]
  int v107; // [sp+4Ch] [-3A4h]
  int v108; // [sp+4Ch] [-3A4h]
  int v109; // [sp+50h] [-3A0h]
  int v110; // [sp+50h] [-3A0h]
  int v111; // [sp+58h] [-398h]
  int v112; // [sp+58h] [-398h]
  int v113; // [sp+60h] [-390h]
  int v114; // [sp+60h] [-390h]
  char v115; // [sp+70h] [-380h]
  idVec3 v116; // [sp+78h] [-378h] BYREF
  __int64 v117; // [sp+88h] [-368h] BYREF
  float x; // [sp+90h] [-360h] BYREF
  float y; // [sp+94h] [-35Ch]
  float z; // [sp+98h] [-358h]
  float v121; // [sp+9Ch] [-354h]
  float v122; // [sp+A0h] [-350h]
  float v123; // [sp+A4h] [-34Ch]
  idTreeAnimator *v124; // [sp+A8h] [-348h] BYREF
  idVec3 v125; // [sp+B0h] [-340h] BYREF
  idCVar *v126; // [sp+BCh] [-334h]
  unsigned __int64 v127; // [sp+C0h] [-330h] BYREF
  idPropsCollection *v128; // [sp+C8h] [-328h]
  idVec3 v129; // [sp+D0h] [-320h] BYREF
  float v130; // [sp+DCh] [-314h]
  idVec3 v131; // [sp+E0h] [-310h] BYREF
  float v132[4]; // [sp+F0h] [-300h] BYREF
  idVec3 v133; // [sp+100h] [-2F0h] BYREF
  idVec3 v134; // [sp+110h] [-2E0h] BYREF
  float v135[4]; // [sp+120h] [-2D0h] BYREF
  trace_t v136; // [sp+130h] [-2C0h] BYREF
  trace_t v137; // [sp+1B0h] [-240h] BYREF
  idMat3 v138; // [sp+230h] [-1C0h] BYREF
  idMat3 v139; // [sp+260h] [-190h] BYREF
  trace_t v140; // [sp+290h] [-160h] BYREF

  idEntity::UpdateFX(this);
  if ( this->health <= 0.0 )
    return;
  groundParticlesFromFan = this->groundParticlesFromFan;
  v5 = &g_droneDebugGroundFX;
  LODWORD(v2) = 0;
  v126 = &g_droneDebugGroundFX;
  if ( groundParticlesFromFan != nullptr
    && idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame) != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    v124 = TreeAnimatorFromPresentable;
    if ( TreeAnimatorFromPresentable == nullptr )
      idLib::Error(fmt: "No tree animator found for '%s'", this->name.data);
    decl = TreeAnimatorFromPresentable->decl;
    if ( decl == nullptr || (p_props = &decl->props, v128 = &decl->props, decl == (const idDeclMD6 *)-352) )
      idLib::Error(fmt: "No props collection found for '%s", this->name.data);
    v115 = 0;
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->nextGroundFXTime )
    {
      v115 = 1;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v9 = (float)((float)(this->secBetweenAdd * (float)1000.0) + (float)__SPAIR64__(&unk_82150000, GameMs));
      v127 = __PAIR64__(&unk_82150000, GameMs);
      this->nextGroundFXTime = (int)v9;
    }
    HIDWORD(v2) = "_info";
    Tag = idPropsCollection::GetTag(this: p_props, propName: "_info", tagName: thrusterName[1]);
    if ( Tag->parentJoint.value != 0xFFFF )
    {
      idTreeAnimator::GetWorldSpaceTagTransform(
        this: TreeAnimatorFromPresentable,
        tagData: Tag,
        origin: &v116,
        axis: &v138);
      fanToGroundQuery = this->fanToGroundQuery;
      if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: this->fanToGroundQuery) != 0 )
      {
        index = fanToGroundQuery->index;
        v13 = clientGame;
        fanToGroundQuery->index = v2;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v137,
          query: &v13->clip.collisionQueries[index & 0xFFF].query,
          peek: false);
        if ( v137.fraction < 1.0 )
        {
          if ( g_droneDebugGroundFX.valueInteger != 0 )
            clientGame->renderWorld->DebugPoint(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&idColor::colorGreen,
              a3: &v137.endpos,
              a4: 0,
              a5: false);
          if ( this->afterburnerAmount != 0.0 )
          {
            this->particlesMultiplier = 0x40000000;
            this->addedParticleMovement = -50.0;
          }
          y = v137.endpos.y;
          particlesMultiplier = this->particlesMultiplier;
          v15 = (float)(this->maxAltitude * this->particlesMultiplier);
          z = v137.endpos.z;
          x = v137.endpos.x;
          v16 = __fsqrts((float)((float)((float)(v137.endpos.x - v116.x) * (float)(v137.endpos.x - v116.x))
                               + (float)((float)((float)(v137.endpos.z - v116.z) * (float)(v137.endpos.z - v116.z))
                                       + (float)((float)(v137.endpos.y - v116.y) * (float)(v137.endpos.y - v116.y)))));
          if ( v16 < v15 && RandomFloat(max: (float)((float)particlesMultiplier * (float)v15)) > v16 )
          {
            v17 = this->particlesMultiplier > 1.0
                ? RandomFloat(min: 2.0, max: (float)((float)(this->particlesMultiplier * 2.0) + (float)0.5))
                : 2.0;
            v18 = clientGame;
            v19 = &this->fanToGroundQuery[1];
            if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->fanToGroundQuery[1]) != 0 )
            {
              v23 = v19->index;
              v19->index = v2;
              idCollisionModelManager::GetContentsResult(
                this: collisionModelManager,
                result: &v136,
                query: &v18->clip.collisionQueries[v23 & 0xFFF].query,
                peek: false);
              if ( v136.fraction < 1.0 )
              {
                if ( g_droneDebugGroundFX.valueInteger != 0 )
                  clientGame->renderWorld->DebugPoint(
                    this: clientGame->renderWorld,
                    a2: (const idVec4 *)&idColor::colorGreen,
                    a3: &v136.endpos,
                    a4: 0,
                    a5: false);
                v20 = v136.endpos.x;
                v21 = v136.endpos.y;
                v22 = v136.endpos.z;
              }
              else
              {
                v20 = x;
                v21 = y;
                v22 = z;
              }
            }
            else
            {
              v20 = x;
              v21 = y;
              v22 = z;
            }
            v121 = v20;
            v122 = v21;
            v123 = v22;
            v24 = RandomInt(max: 2);
            v25 = 0.0;
            if ( v17 > 0.0 )
            {
              while ( 1 )
              {
                addedParticleMovement = this->addedParticleMovement;
                if ( addedParticleMovement != 0.0 )
                {
                  if ( addedParticleMovement > 0.5 )
                  {
                    v27 = this->addedParticleMovement;
                    addedParticleMovement = (float)(this->addedParticleMovement * (float)0.5);
LABEL_36:
                    v25 = RandomFloat(min: addedParticleMovement, max: v27);
                    goto LABEL_37;
                  }
                  if ( addedParticleMovement < -0.5 )
                  {
                    v27 = (float)(this->addedParticleMovement * (float)0.5);
                    goto LABEL_36;
                  }
                }
LABEL_37:
                v28 = RandomFloat(min: -25.0, max: 25.0);
                v29 = RandomFloat(min: -25.0, max: 25.0);
                v30 = (float)((float)(this->currentSpeed * 3.0) + (float)v25);
                v31 = this->lastMovement.x;
                v32 = this->lastMovement.y;
                HIDWORD(v127) = -1;
                v132[2] = 0.0;
                HIDWORD(v33) = 1;
                v132[1] = (float)((float)v32 * (float)v30) + (float)v28;
                v132[0] = (float)((float)v31 * (float)v30) + (float)v29;
                v34 = 1664525 * clientGame->random.seed;
                clientGame->random.seed = v34 + 1013904223;
                LODWORD(v33) = ((v34 + 1013904223) >> 10) & 0x7FFF;
                v117 = v33;
                v35 = (float)((float)v33 * (float)0.000030518509);
                GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                                   this: &clientGame->gameTimeManager,
                                   type: GAMETIME_SCALED);
                v37 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                v38 = this->groundParticlesFromFan;
                MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
                idRenderModelEffects::AddParticles(
                  this: MergeBranch,
                  particle: v38,
                  systemStartTime: v37,
                  gameMsPerFrame: GameMsPerFrame,
                  diversity: v35,
                  origin: v40,
                  axis: (const idMat3 *)(&x + 3 * v24),
                  velocity: mat3_identity.mat,
                  color: v132,
                  a10: v73,
                  a11: v75,
                  a12: (int)v77,
                  a13: v79,
                  a14: v81,
                  a15: v83,
                  a16: v85,
                  a17: v87,
                  a18: v89,
                  a19: v91,
                  a20: v93,
                  a21: v95,
                  a22: v97,
                  a23: v99,
                  a24: v101,
                  a25: v103,
                  a26: v105,
                  a27: v107,
                  a28: v109,
                  a29: (unsigned int *)&v127);
                v17 = (float)((float)v17 - 1.0);
                v24 = 1 - v24;
                if ( v17 <= 0.0 )
                {
                  v5 = v126;
                  p_props = v128;
                  TreeAnimatorFromPresentable = v124;
                  break;
                }
              }
            }
          }
        }
      }
      if ( v115 != 0 )
      {
        entityNumber = this->entityNumber;
        v131.x = v116.x;
        v131.y = v116.y;
        v131.z = v116.z - (float)5000.0;
        fanToGroundQuery->index = *(unsigned __int64 *)&idClip::Translation(
                                                          this: (idClip *)&v117,
                                                          result: &clientGame->clip,
                                                          a3: nullptr,
                                                          start: &v116,
                                                          end: &v131,
                                                          clipModel: nullptr,
                                                          startAxis: &mat3_identity,
                                                          clipMask: 1,
                                                          passEntityNumber: v73,
                                                          moveClipModel: v75,
                                                          userName: v77,
                                                          a12: v79,
                                                          a13: v81,
                                                          a14: v83,
                                                          a15: v85,
                                                          a16: v87,
                                                          a17: v89,
                                                          a18: v91,
                                                          a19: v93,
                                                          a20: v95,
                                                          a21: v97,
                                                          a22: v99,
                                                          a23: v101,
                                                          a24: v103,
                                                          a25: v105,
                                                          a26: v107,
                                                          a27: v109,
                                                          a28: entityNumber,
                                                          a29: v111,
                                                          a30: false,
                                                          a31: v113,
                                                          a32: (int)"w:\\tech5\\tungsten\\game\\entities\\Drone.cpp(4506) : Drone")->world;
        v42 = idPropsCollection::GetTag(this: p_props, propName: "_info", tagName: thrusterName[2]);
        if ( v42->parentJoint.value == 0xFFFF )
        {
          v125.x = v116.x;
          v125.y = v116.y;
          v125.z = v116.z;
        }
        else
        {
          idTreeAnimator::GetWorldSpaceTagTransform(
            this: TreeAnimatorFromPresentable,
            tagData: v42,
            origin: &v125,
            axis: &v139);
        }
        v43 = this->entityNumber;
        v134.x = v125.x;
        v134.y = v125.y;
        v134.z = v125.z - (float)5000.0;
        this->fanToGroundQuery[1].index = *(_QWORD *)&idClip::Translation(
                                                        this: (idClip *)&v117,
                                                        result: &clientGame->clip,
                                                        a3: nullptr,
                                                        start: &v125,
                                                        end: &v134,
                                                        clipModel: nullptr,
                                                        startAxis: &mat3_identity,
                                                        clipMask: 1,
                                                        passEntityNumber: v74,
                                                        moveClipModel: v76,
                                                        userName: v78,
                                                        a12: v80,
                                                        a13: v82,
                                                        a14: v84,
                                                        a15: v86,
                                                        a16: v88,
                                                        a17: v90,
                                                        a18: v92,
                                                        a19: v94,
                                                        a20: v96,
                                                        a21: v98,
                                                        a22: v100,
                                                        a23: v102,
                                                        a24: v104,
                                                        a25: v106,
                                                        a26: v108,
                                                        a27: v110,
                                                        a28: v43,
                                                        a29: v112,
                                                        a30: false,
                                                        a31: v114,
                                                        a32: (int)"w:\\tech5\\tungsten\\game\\entities\\Drone.cpp(4521) : Drone")->world;
      }
    }
  }
  v44 = &this->fanToGroundQuery[2];
  if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->fanToGroundQuery[2]) != 0 )
  {
    v45 = v44->index;
    v46 = clientGame;
    v44->index = v2;
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: &v140,
      query: &v46->clip.collisionQueries[v45 & 0xFFF].query,
      peek: false);
    if ( v140.fraction < 1.0 )
    {
      v47 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      presentable = this->presentable;
      v49 = v47;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      idInfluenceTrailManager::UpdatePosition(
        this: &clientGame->influenceTrailManager,
        trail: &presentable->influenceHandle,
        position: &v140.endpos,
        time: v49);
    }
    v117 = __PAIR64__(
             (idDeclInfoTemplate<idDeclAiEvent> *)&idDeclAiEvent::resourceList.staticID,
             idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
    *(double *)&v50 = (float)((float)v117 * g_droneFoliageSinRate.valueFloat);
    v51 = sin(x: v50);
    v52 = this->presentable;
    v53 = (float)((float)((float)(g_droneFoliageHighAngle.valueFloat - g_droneFoliageLowAngle.valueFloat)
                        * (float)((float)((float)*(double *)&v51 * (float)0.5) + (float)0.5))
                + g_droneFoliageLowAngle.valueFloat);
    if ( v52 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v52 = this->presentable;
    }
    idInfluenceTrailManager::ModifyAngle(
      this: &clientGame->influenceTrailManager,
      trail: &v52->influenceHandle,
      angle: v53);
  }
  v54 = this->entityNumber;
  Physics = idEntity::GetPhysics(this);
  v56 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v57 = v56[1];
  v58 = (float)(v56[2] - (float)5000.0);
  v133.x = *v56;
  v133.y = v57;
  v133.z = v58;
  v59 = idEntity::GetPhysics(this);
  v60 = v59->GetOrigin(this: v59, a2: 0);
  v44->index = *(unsigned __int64 *)&idClip::Translation(
                                       this: (idClip *)&v117,
                                       result: &clientGame->clip,
                                       a3: nullptr,
                                       start: v60,
                                       end: &v133,
                                       clipModel: nullptr,
                                       startAxis: &mat3_identity,
                                       clipMask: 1,
                                       passEntityNumber: v73,
                                       moveClipModel: v75,
                                       userName: v77,
                                       a12: v79,
                                       a13: v81,
                                       a14: v83,
                                       a15: v85,
                                       a16: v87,
                                       a17: v89,
                                       a18: v91,
                                       a19: v93,
                                       a20: v95,
                                       a21: v97,
                                       a22: v99,
                                       a23: v101,
                                       a24: v103,
                                       a25: v105,
                                       a26: v107,
                                       a27: v109,
                                       a28: v54,
                                       a29: v111,
                                       a30: false,
                                       a31: v113,
                                       a32: (int)"w:\\tech5\\tungsten\\game\\entities\\Drone.cpp(4543) : Drone")->world;
  v61 = idEntity::GetPhysics(this);
  v62 = (float *)v61->GetOrigin(this: v61, a2: 0);
  outerRadius = this->influence.outerRadius;
  v129.x = *v62;
  v129.y = v62[1];
  v129.z = v62[2];
  v130 = outerRadius;
  value = (const idDeclDamage *)idGameLocal::GetSpawnId(
                                  this: (idGameLocal *)&v124,
                                  result: (idSpawnId *)gameLocal,
                                  ent: this)->value;
  WeaponTraceMgr = idClientGame::GetWeaponTraceMgr(this: clientGame);
  idWeaponTraceManager::AddExplosion(
    this: WeaponTraceMgr,
    origin: &v129,
    radius: outerRadius,
    attacker: v66,
    damage: value,
    a6: nullptr);
  if ( v5->valueInteger != 0 )
  {
    v135[0] = 0.0;
    v135[1] = 1.0;
    v135[3] = 1.0;
    v135[2] = 0.0;
    clientGame->renderWorld->DebugSphere(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v135,
      a3: (const idSphere *)&v129,
      a4: 12,
      a5: 0,
      a6: false);
  }
  v67 = this->particlesMultiplier;
  if ( v67 != 1.0 )
  {
    if ( v67 <= 1.0 )
    {
      v69 = (float)(this->particlesMultiplier + (float)0.25);
      this->particlesMultiplier = this->particlesMultiplier + (float)0.25;
      if ( v69 <= 1.0 )
        goto LABEL_60;
    }
    else
    {
      v68 = (float)(this->particlesMultiplier - (float)0.25);
      this->particlesMultiplier = this->particlesMultiplier - (float)0.25;
      if ( v68 >= 1.0 )
        goto LABEL_60;
    }
    this->particlesMultiplier = 1.0;
  }
LABEL_60:
  v70 = this->addedParticleMovement;
  if ( v70 != 0.0 )
  {
    if ( v70 <= 0.0 )
    {
      v72 = (float)(this->addedParticleMovement + (float)1.0);
      this->addedParticleMovement = this->addedParticleMovement + (float)1.0;
      if ( v72 > 0.0 )
        this->addedParticleMovement = 0.0;
    }
    else
    {
      v71 = (float)(this->addedParticleMovement - (float)1.0);
      this->addedParticleMovement = this->addedParticleMovement - (float)1.0;
      if ( v71 < 0.0 )
        this->addedParticleMovement = 0.0;
    }
  }
}


// ========================================================================
// ?Bump@idDrone@@QAA?AVidVec3@@V2@0MMM@Z
// EA  : 0x82C29F90
// RVA : 0x00C29F90
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

idVec3 *__fastcall idDrone::Bump(
        idVec3 *a1,
        int a2,
        int a3,
        int a4,
        long double rotationalForce,
        double reduceZScaler,
        int a7)
{
  double v7; // fp26
  double v9; // fp7
  double v10; // fp28
  double v11; // fp6
  double v12; // fp8
  double v13; // fp4
  double v14; // fp1
  double v16; // fp3
  double v18; // fp29
  double v21; // fp5
  double v25; // fp9
  double v26; // fp31
  double v27; // fp5
  double v28; // fp9
  double v29; // fp31
  double v30; // fp5
  double v31; // fp9
  double v32; // fp5
  double v33; // fp30
  double v34; // fp29
  double v35; // fp28
  double v36; // fp11
  double v37; // fp10
  double v38; // fp9
  double v39; // fp5
  double v40; // fp3
  double v41; // fp10
  double v42; // fp7
  double v43; // fp8
  double v44; // fp6
  double v47; // fp8
  double v48; // fp6
  double v49; // fp31
  double v50; // fp12
  double v51; // fp8
  double v52; // fp0
  double v53; // fp27
  double v54; // fp8
  double y; // fp0
  double v56; // fp7
  double z; // fp13
  double x; // fp11
  double v59; // fp9
  double v60; // fp6
  double v61; // fp5
  double v62; // fp4
  double v63; // fp8
  double v64; // fp11
  double v65; // fp10
  double v66; // fp8
  double v67; // fp11
  double v68; // fp8
  double v69; // fp1
  double v70; // fp12
  double v71; // fp11
  idVec3 *result; // r3
  double v73; // fp11
  idTypesafeNumber<float,enum RadiansUnique_t> v74; // [sp+50h] [-A0h] BYREF
  idVec3 v75; // [sp+58h] [-98h] BYREF
  idQuat v76; // [sp+70h] [-80h] BYREF

  v7 = *(double *)&rotationalForce;
  v9 = (float)(*(float *)&a2 - (float)(*(float *)(a2 + 5892) + *(float *)(a2 + 5468)));
  v10 = (float)(*(float *)&a7 * (float)reduceZScaler);
  v11 = (float)(*(float *)(a2 + 5852) - *(float *)(a2 + 5472));
  v12 = (float)(*(float *)&a3 - (float)(*(float *)(a2 + 5896) + *(float *)(a2 + 5472)));
  v13 = (float)(*(float *)(a2 + 5856) - *(float *)(a2 + 5476));
  v14 = (float)(*(float *)(a2 + 5848) - *(float *)(a2 + 5468));
  _FP30 = (float)((float)((float)((float)(*(float *)&a7 * (float)reduceZScaler)
                                * (float)(*(float *)&a7 * (float)reduceZScaler))
                        + (float)((float)(*(float *)&a7 * *(float *)&a7) + (float)(*(float *)&a4 * *(float *)&a4)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  v18 = (float)((float)((float)((float)(*(float *)&a7 * (float)reduceZScaler)
                              * (float)(*(float *)&a7 * (float)reduceZScaler))
                      + (float)((float)(*(float *)&a7 * *(float *)&a7) + (float)(*(float *)&a4 * *(float *)&a4)))
              * (float)0.5);
  v16 = (float)((float)(*(float *)&a3 - (float)(*(float *)(a2 + 5900) + *(float *)(a2 + 5476))) * (float)reduceZScaler);
  __asm { fsel      f5, f30, f5, f13 }
  _FP30 = (float)((float)((float)((float)v16 * (float)v16)
                        + (float)((float)((float)v12 * (float)v12) + (float)((float)v9 * (float)v9)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  v21 = __frsqrte(_FP5);
  _FP25 = (float)((float)((float)((float)v14 * (float)v14)
                        + (float)((float)((float)v13 * (float)v13) + (float)((float)v11 * (float)v11)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f9, f30, f9, f13 }
  __asm { fsel      f31, f25, f31, f13 }
  v25 = __frsqrte(_FP9);
  v26 = __frsqrte(_FP31);
  v27 = (float)((float)-(float)((float)((float)((float)v21 * (float)v18) * (float)v21) - (float)1.5) * (float)v21);
  v28 = (float)((float)-(float)((float)((float)((float)v25
                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                              + (float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)v25)
                              - (float)1.5)
              * (float)v25);
  v29 = (float)((float)-(float)((float)((float)((float)v26
                                              * (float)((float)((float)((float)v14 * (float)v14)
                                                              + (float)((float)((float)v13 * (float)v13)
                                                                      + (float)((float)v11 * (float)v11)))
                                                      * (float)0.5))
                                      * (float)v26)
                              - (float)1.5)
              * (float)v26);
  v30 = (float)((float)-(float)((float)((float)((float)v27 * (float)v18) * (float)v27) - (float)1.5) * (float)v27);
  v31 = (float)((float)-(float)((float)((float)((float)v28
                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                              + (float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)v28)
                              - (float)1.5)
              * (float)v28);
  v32 = (float)((float)-(float)((float)((float)((float)v30 * (float)v18) * (float)v30) - (float)1.5) * (float)v30);
  v33 = (float)(*(float *)&a4 * (float)v32);
  v34 = (float)(*(float *)&a7 * (float)v32);
  v35 = (float)((float)v32 * (float)v10);
  v36 = (float)((float)-(float)((float)((float)((float)v31
                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                              + (float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)v31)
                              - (float)1.5)
              * (float)v31);
  v37 = (float)((float)((float)-(float)((float)((float)((float)v31
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31)
              * (float)v16);
  v38 = (float)((float)v9
              * (float)((float)-(float)((float)((float)((float)v31
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31));
  v40 = (float)((float)((float)((float)(*(float *)&a3 - (float)(*(float *)(a2 + 5896) + *(float *)(a2 + 5472)))
                              * (float)v36)
                      * (float)(*(float *)&a4 * (float)v32))
              - (float)((float)(*(float *)&a7 * (float)v32) * (float)v38));
  v39 = (float)((float)((float)v38 * (float)v35) - (float)((float)(*(float *)&a4 * (float)v32) * (float)v37));
  v41 = (float)((float)((float)v34 * (float)v37)
              - (float)((float)((float)(*(float *)&a3 - (float)(*(float *)(a2 + 5896) + *(float *)(a2 + 5472)))
                              * (float)v36)
                      * (float)v35));
  v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                                      * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v11 * (float)v11)))
                                                                                              * (float)0.5))
                                                                              * (float)v29)
                                                                      - (float)1.5)
                                                      * (float)v29)
                                              * (float)((float)((float)((float)v14 * (float)v14)
                                                              + (float)((float)((float)v13 * (float)v13)
                                                                      + (float)((float)v11 * (float)v11)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v29
                                                                              * (float)((float)((float)((float)v14 * (float)v14)
                                                                                              + (float)((float)((float)v13 * (float)v13) + (float)((float)v11 * (float)v11)))
                                                                                      * (float)0.5))
                                                                      * (float)v29)
                                                              - (float)1.5)
                                              * (float)v29))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v29
                                                      * (float)((float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)v11 * (float)v11)))
                                                              * (float)0.5))
                                              * (float)v29)
                                      - (float)1.5)
                      * (float)v29));
  v43 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                                              * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                      * (float)v29)
                                                                              - (float)1.5)
                                                              * (float)v29)
                                                      * (float)((float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)v11 * (float)v11)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v29
                                                                                      * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v11 * (float)v11)))
                                                                                              * (float)0.5))
                                                                              * (float)v29)
                                                                      - (float)1.5)
                                                      * (float)v29))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v29
                                                              * (float)((float)((float)((float)v14 * (float)v14)
                                                                              + (float)((float)((float)v13 * (float)v13)
                                                                                      + (float)((float)v11 * (float)v11)))
                                                                      * (float)0.5))
                                                      * (float)v29)
                                              - (float)1.5)
                              * (float)v29))
              * (float)v14);
  v44 = (float)((float)v11
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                                              * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                      * (float)v29)
                                                                              - (float)1.5)
                                                              * (float)v29)
                                                      * (float)((float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)v11 * (float)v11)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v29
                                                                                      * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v11 * (float)v11)))
                                                                                              * (float)0.5))
                                                                              * (float)v29)
                                                                      - (float)1.5)
                                                      * (float)v29))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v29
                                                              * (float)((float)((float)((float)v14 * (float)v14)
                                                                              + (float)((float)((float)v13 * (float)v13)
                                                                                      + (float)((float)v11 * (float)v11)))
                                                                      * (float)0.5))
                                                      * (float)v29)
                                              - (float)1.5)
                              * (float)v29)));
  _FP1 = (float)((float)((float)((float)v41 * (float)v41)
                       + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f1, f9, f13 }
  v48 = (float)((float)((float)((float)(*(float *)(a2 + 5856) - *(float *)(a2 + 5476)) * (float)v42) * (float)v35)
              + (float)((float)((float)v44 * (float)v34) + (float)((float)v43 * (float)v33)));
  v47 = __frsqrte(_FP1);
  v49 = (float)-(float)((float)((float)v48 * (float)0.5) - (float)0.5);
  v50 = (float)((float)-(float)((float)((float)((float)v47
                                              * (float)((float)((float)((float)v41 * (float)v41)
                                                              + (float)((float)((float)v40 * (float)v40)
                                                                      + (float)((float)v39 * (float)v39)))
                                                      * (float)0.5))
                                      * (float)v47)
                              - (float)1.5)
              * (float)v47);
  v51 = (float)((float)((float)-(float)((float)((float)((float)v47
                                                      * (float)((float)((float)((float)v41 * (float)v41)
                                                                      + (float)((float)((float)v40 * (float)v40)
                                                                              + (float)((float)v39 * (float)v39)))
                                                              * (float)0.5))
                                              * (float)v47)
                                      - (float)1.5)
                      * (float)v47)
              * (float)((float)((float)((float)v41 * (float)v41)
                              + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                      * (float)0.5));
  *(double *)&rotationalForce = (float)((float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5)
                                              * (float)v50)
                                      * (float)((float)((float)((float)v41 * (float)v41)
                                                      + (float)((float)((float)v40 * (float)v40)
                                                              + (float)((float)v39 * (float)v39)))
                                              * (float)0.5));
  v52 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v51 * (float)v50)
                                                                              - (float)1.5)
                                                              * (float)v50)
                                                      * (float)((float)((float)((float)v41 * (float)v41)
                                                                      + (float)((float)((float)v40 * (float)v40)
                                                                              + (float)((float)v39 * (float)v39)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5)
                                                      * (float)v50))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5) * (float)v50))
              * (float)((float)((float)v41 * (float)v41)
                      + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))));
  v75.x = (float)v41
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5)
                                                        * (float)v50)
                                                * (float)((float)((float)((float)v41 * (float)v41)
                                                                + (float)((float)((float)v40 * (float)v40)
                                                                        + (float)((float)v39 * (float)v39)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5)
                                                * (float)v50))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5) * (float)v50));
  v75.y = (float)v39
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5)
                                                        * (float)v50)
                                                * (float)((float)((float)((float)v41 * (float)v41)
                                                                + (float)((float)((float)v40 * (float)v40)
                                                                        + (float)((float)v39 * (float)v39)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5)
                                                * (float)v50))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5) * (float)v50));
  v75.z = (float)v40
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5)
                                                        * (float)v50)
                                                * (float)((float)((float)((float)v41 * (float)v41)
                                                                + (float)((float)((float)v40 * (float)v40)
                                                                        + (float)((float)v39 * (float)v39)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5)
                                                * (float)v50))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)v51 * (float)v50) - (float)1.5) * (float)v50));
  if ( v52 >= 0.2 )
    v53 = (float)-(float)((float)((float)((float)v52 - (float)0.2) * 0.75) - (float)v52);
  else
    v53 = (float)((float)((float)((float)0.2 - (float)v52) * 0.33329999) + (float)v52);
  v74.value = (float)((float)v53 * (float)*((double *)&rotationalForce + 1)) * 0.055;
  idQuat::idQuat(this: &v76, axis: &v75, angle: &v74, a4: rotationalForce);
  v54 = *(float *)(a2 + 5940);
  y = v76.y;
  v56 = *(float *)(a2 + 5932);
  z = v76.z;
  x = v76.x;
  v59 = 1.0;
  v60 = (float)((float)(v76.y * *(float *)(a2 + 5944))
              + (float)((float)(v76.w * *(float *)(a2 + 5936)) + (float)(v76.z * *(float *)(a2 + 5932))));
  v61 = (float)((float)(*(float *)(a2 + 5936) * v76.x)
              + (float)((float)(v76.z * *(float *)(a2 + 5944)) + (float)(v76.w * *(float *)(a2 + 5940))));
  v62 = (float)-(float)((float)(v76.y * *(float *)(a2 + 5936))
                      - (float)((float)(v76.w * *(float *)(a2 + 5944)) - (float)(*(float *)(a2 + 5932) * v76.x)));
  *(float *)(a2 + 5932) = -(float)((float)(v76.z * *(float *)(a2 + 5936))
                                 - (float)((float)(*(float *)(a2 + 5944) * v76.x)
                                         + (float)((float)(v76.w * *(float *)(a2 + 5932))
                                                 + (float)(v76.y * *(float *)(a2 + 5940)))));
  *(float *)(a2 + 5936) = -(float)((float)((float)v54 * (float)x) - (float)v60);
  *(float *)(a2 + 5940) = -(float)((float)((float)y * (float)v56) - (float)v61);
  *(float *)(a2 + 5944) = -(float)((float)((float)z * (float)v54) - (float)v62);
  if ( v49 > 0.1 )
  {
    v63 = (float)((float)((float)((float)((float)v49 - (float)0.1) * (float)v53) * 0.34999999) + *(float *)(a2 + 5888));
    *(float *)(a2 + 5888) = (float)((float)((float)((float)v49 - (float)0.1) * (float)v53) * 0.34999999)
                          + *(float *)(a2 + 5888);
    if ( v63 >= 0.0 )
    {
      if ( v63 > 1.0 )
        *(float *)(a2 + 5888) = 1.0;
    }
    else
    {
      *(float *)(a2 + 5888) = 0.0;
    }
  }
  v64 = *(float *)(a2 + 5904);
  v65 = *(float *)(a2 + 5908);
  v66 = *(float *)(a2 + 5912);
  a1->y = (float)v34 * (float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0);
  a1->z = (float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0) * (float)v35;
  a1->x = (float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0) * (float)v33;
  *(float *)(a2 + 5908) = (float)((float)v34 * (float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0))
                        + (float)v65;
  *(float *)(a2 + 5912) = (float)((float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0) * (float)v35)
                        + (float)v66;
  *(float *)(a2 + 5904) = (float)((float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0) * (float)v33)
                        + (float)v64;
  v67 = *(float *)(a2 + 12992);
  v68 = (float)((float)((float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0) * (float)v35)
              + *(float *)(a2 + 12996));
  *(float *)(a2 + 12988) = (float)((float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0) * (float)v33)
                         + *(float *)(a2 + 12988);
  *(float *)(a2 + 12992) = (float)((float)v34 * (float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0))
                         + (float)v67;
  *(float *)(a2 + 12996) = v68;
  v69 = *(float *)(a2 + 11588);
  v70 = (float)((float)((float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0) * (float)v35)
              + *(float *)(a2 + 11592));
  *(float *)(a2 + 11584) = (float)((float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0) * (float)v33)
                         + *(float *)(a2 + 11584);
  *(float *)(a2 + 11588) = (float)((float)v34 * (float)((float)((float)((float)1.0 - (float)v53) * (float)v7) * 6.0))
                         + (float)v69;
  *(float *)(a2 + 11592) = v70;
  if ( v49 >= 0.2 )
  {
    if ( v49 > 0.2 )
    {
      if ( v49 < 1.0 )
        v59 = (float)-(float)((float)((float)((float)v49 - (float)0.2) * (float)0.3125) - (float)1.0);
      else
        v59 = 0.75;
    }
    v71 = (float)((float)((float)(*(float *)(a2 + 5608) + 3.0) * (float)v59) - 3.0);
  }
  else
  {
    if ( *(float *)(a2 + 5608) >= (double)(float)((float)((float)((float)moveStateScalers[3][*(_DWORD *)(a2 + 5304)]
                                                                * *(float *)(a2 + 5320))
                                                        + (float)((float)((float)moveStateScalers[3][*(_DWORD *)(a2 + 5300)]
                                                                        * *(float *)(a2 + 5316))
                                                                + (float)((float)((float)moveStateScalers[3][*(_DWORD *)(a2 + 5292)]
                                                                                * *(float *)(a2 + 5308))
                                                                        + (float)((float)moveStateScalers[3][*(_DWORD *)(a2 + 5296)]
                                                                                * *(float *)(a2 + 5312)))))
                                                * 0.75) )
      goto LABEL_18;
    v71 = (float)((float)((float)((float)0.2 - (float)v49) * 2.5) + *(float *)(a2 + 5608));
  }
  *(float *)(a2 + 5608) = v71;
LABEL_18:
  result = a1;
  v73 = (float)(*(float *)(a2 + 5640) - (float)0.25);
  *(float *)(a2 + 5640) = *(float *)(a2 + 5640) - (float)0.25;
  if ( v73 < -0.1 )
    *(float *)(a2 + 5640) = -0.1;
  return result;
}


// ========================================================================
// ?KillDrone@idDrone@@QAAXXZ
// EA  : 0x82C2A488
// RVA : 0x00C2A488
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::KillDrone(idDrone *this)
{
  int value; // r9
  idEntity *v3; // r3
  int v4; // r9
  idEntity *v5; // r3
  idEntity *v6; // r30
  idEventArg *v7; // r3
  idDrone::droneDeath_t deathVarietyDesired; // r11
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  idPhysics *v14; // r3
  idMat3 *v15; // r3
  idPhysics *v16; // r3
  const idVec3 *v17; // r3
  idPhysics *v18; // r3
  const idMat3 *v19; // r3
  idPhysics_RigidBody_vtbl *v20; // r11
  idPhysics_RigidBody_vtbl *v21; // r9
  idClientGame *v22; // r11
  int GameMs; // r30
  double v24; // fp1
  int v25; // r28
  idPhysics *v26; // r3
  int v27; // r3
  idPresentable *presentable; // r11
  const idVec3 *v29; // r27
  BOOL rigidPhysicsEnabled; // r8
  idPhysics *v31; // r3
  __int64 v32; // [sp+50h] [-C0h]
  idMat3 v33; // [sp+58h] [-B8h] BYREF
  float v34; // [sp+7Ch] [-94h]
  float v35; // [sp+80h] [-90h]
  idMat3 v36; // [sp+90h] [-80h] BYREF

  this->health = 0.0;
  value = this->deathTrigger.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr && idEntity::CastTo(c: v3) != nullptr )
    {
      v4 = this->deathTrigger.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13 && (v5 = gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
        v6 = idEntity::CastTo(c: v5);
      else
        v6 = nullptr;
      v7 = idEventArg::idEventArg(this: (idEventArg *)&v36, data: this);
      idEventReceiver::PostEventMS(
        this: v6,
        ev: &EV_Activate,
        time: *(_DWORD *)&v7->type,
        arg1: (const idEventArg *)LODWORD(v7->value.v[1]));
    }
  }
  if ( this->deathVarietyDesired >= (unsigned int)DD_RANDOM_DRONE_DEATH )
    this->deathVarietyDesired = RandomInt(max: 2);
  if ( this->deathVarietyDesired == DD_EXPLOSION && this->GetFXDecl(this) == nullptr )
    this->deathVarietyDesired = DD_SPINNING_OUT_OF_CONTROL;
  deathVarietyDesired = this->deathVarietyDesired;
  if ( deathVarietyDesired != DD_EXPLOSION )
  {
    if ( deathVarietyDesired == DD_SPINNING_OUT_OF_CONTROL )
    {
      this->nextEngineSmokeTime = idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED);
      this->engineSmokeAmount = RandomFloat(min: 0.80000001, max: 1.0);
      this->rigidPhysics.SetContents(this: &this->rigidPhysics, a2: 141632, a3: -1);
      idPhysics_RigidBody::SetBouncyness(this: &this->rigidPhysics, b: 0.30000001);
      idPhysics_RigidBody::SetFriction(this: &this->rigidPhysics, linear: 0.60000002, angular: 0.60000002, contact: 0.5);
      Physics = idEntity::GetPhysics(this);
      v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v11 = (float)(*v10 - this->previousOrigin.x);
      v12 = (float)(v10[1] - this->previousOrigin.y);
      v13 = (float)(v10[2] - this->previousOrigin.z);
      v14 = idEntity::GetPhysics(this);
      v15 = (idMat3 *)v14->GetAxis(this: v14, a2: 0);
      idMat3::operator-(this: &v36, result: v15, a: &this->previousAxis);
      idMat3::ToAngularVelocity(this: &v33, result: v36.mat);
      v33.mat[0].x = v33.mat[0].x * 0.2;
      v33.mat[0].y = v33.mat[0].y * 0.2;
      v16 = idEntity::GetPhysics(this);
      v17 = v16->GetOrigin(this: v16, a2: 0);
      this->rigidPhysics.SetOrigin(this: &this->rigidPhysics, a2: v17, a3: -1);
      v18 = idEntity::GetPhysics(this);
      v19 = v18->GetAxis(this: v18, a2: 0);
      this->rigidPhysics.SetAxis(this: &this->rigidPhysics, a2: v19, a3: -1);
      v20 = this->rigidPhysics.__vftable;
      v33.mat[1].y = (float)v11 * 25.0;
      v33.mat[1].z = (float)v12 * 25.0;
      v33.mat[2].x = (float)v13 * (float)25.0;
      v20->SetLinearVelocity(this: &this->rigidPhysics, a2: (const idVec3 *)&v33.mat[1].y, a3: 0);
      v21 = this->rigidPhysics.__vftable;
      v33.mat[2].z = v33.mat[0].x * -8.0;
      v34 = v33.mat[0].y * -8.0;
      v35 = v33.mat[0].z * -8.0;
      v21->SetAngularVelocity(this: &this->rigidPhysics, a2: (const idVec3 *)&v33.mat[2].z, a3: 0);
      idEntity::SetPhysics(this, phys: &this->rigidPhysics);
      this->rigidPhysics.Activate(this: &this->rigidPhysics);
      v22 = clientGame;
      this->deathThrust = INITIAL_DEATH_THRUST;
      GameMs = idGameTimeManager::GetGameMs(this: &v22->gameTimeManager, type: GAMETIME_SCALED);
      v24 = RandomFloat(min: this->minDeathThrustDuration, max: this->maxDeathThrustDuration);
      this->weaponArmTime[0] = 0;
      this->deathDoneTime = (int)(float)((float)((float)v24 * (float)1000.0) + (float)__SPAIR64__(&unk_82150000, GameMs));
      this->weaponDisarmTime[0] = idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED)
                                + 500;
      idEntity::BecomeActive(this, flags: 2);
    }
  }
  else
  {
    v25 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v26 = idEntity::GetPhysics(this);
    v27 = (int)v26->GetOrigin(this: v26, a2: 0);
    presentable = this->presentable;
    v29 = (const idVec3 *)v27;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idFXManager::StartFX(this: &presentable->fxManager, org: v29, axis: &mat3_identity, time: v25, startCondition: 90);
    if ( this->explosionSound != nullptr )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_COLLIDE, peerMask: 0xFFu);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_COLLIDE,
        shader: this->explosionSound,
        soundShaderFlags: 0,
        peerMask: 0xFFu);
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_COLLIDE, volume: 0.0);
    }
    v32 = __PAIR64__(
            &unk_82150000,
            idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
    rigidPhysicsEnabled = this->rigidPhysicsEnabled;
    this->deathDoneTime = (int)(float)((float)(this->delayToHideDrone * (float)1000.0) + (float)v32);
    if ( rigidPhysicsEnabled )
    {
      v31 = idEntity::GetPhysics(this);
      v31->DisableClip(this: v31);
      this->rigidPhysics.DisableClip(this: &this->rigidPhysics);
      this->rigidPhysicsEnabled = false;
    }
  }
}


// ========================================================================
// ?Hide@idDrone@@UAAXXZ
// EA  : 0x82C2A9F8
// RVA : 0x00C2A9F8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::Hide(idDrone *this)
{
  char idCombatStage_useRelaxedChatterVO; // r30
  idPhysics *Physics; // r3
  idEntityPtr<idAI2> v4; // [sp+50h] [-20h] BYREF

  idCombatStage_useRelaxedChatterVO = Get_idCombatStage_useRelaxedChatterVO(ptr: this);
  idAttachmentCollection::HideAttachments(this: &this->attachments);
  if ( this->rigidPhysicsEnabled )
  {
    this->rigidPhysics.DisableClip(this: &this->rigidPhysics);
    Physics = idEntity::GetPhysics(this);
    Physics->DisableClip(this: Physics);
    this->rigidPhysicsEnabled = false;
  }
  idEntity::Hide(this);
  if ( idCombatStage_useRelaxedChatterVO == 0 )
  {
    v4.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
    idList<idEntityPtr<idPlayer>,5>::Remove(
      this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->aiWorldStateUsers,
      obj: &v4);
  }
}


// ========================================================================
// ?DormantBegin@idDrone@@UAAXXZ
// EA  : 0x82C2AAC0
// RVA : 0x00C2AAC0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::DormantBegin(idDrone *this)
{
  int v2; // r8
  int v3; // r4
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r10
  int i; // r11

  idEntity::DormantBegin(this);
  if ( this != nullptr )
    v2 = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v2 = 0x1FFF;
  v3 = 0;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num > 0 )
  {
    for ( i = 0; p_aiWorldStateUsers->list[i].spawnId.value != v2; ++i )
    {
      if ( ++v3 >= num )
        return;
    }
    if ( v3 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_aiWorldStateUsers, index: v3);
  }
}


// ========================================================================
// ?GetDesiredFacingForScanning@idDrone@@QAA?AVidVec3@@XZ
// EA  : 0x82C2AB78
// RVA : 0x00C2AB78
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

idDrone *__fastcall idDrone::GetDesiredFacingForScanning(idDrone *this, idVec3 *result)
{
  float y; // r10
  idEntity *v5; // r3
  double v7; // fp9
  float v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  idPhysics *Physics; // r3
  const idVec3 *v12; // r3
  float v13; // r9
  float x; // r6
  float v15; // r5
  float z; // r3
  idEntity *v17; // r3
  idAI2 *v18; // r3
  void *v19; // r3
  float v20; // r9
  idEntity *v21; // r3
  idPlayer *v22; // r3
  idPhysics *v23; // r3
  float *v24; // r3
  double v27; // fp12
  double v28; // fp12
  double v29; // fp0
  double v30; // fp1
  double v31; // fp2
  float v32; // [sp+50h] [-50h]
  float v33; // [sp+54h] [-4Ch]
  float v34; // [sp+58h] [-48h]
  float v35; // [sp+60h] [-40h] BYREF
  float v36; // [sp+64h] [-3Ch]
  float v37; // [sp+68h] [-38h]

  y = result[947].y;
  if ( gameLocal->spawnIds.ptr[LOWORD(y) & 0x1FFF] != SLODWORD(y) >> 13
    || (v5 = gameLocal->entities.ptr[LOWORD(y) & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v5) == nullptr )
  {
    idDrone::GetDesiredFacingForMoving(this, result);
    return this;
  }
  v7 = (float)(result[469].y * (float)0.97500002);
  result[469].z = result[469].z * (float)0.96499997;
  result[469].y = v7;
  v8 = result[947].y;
  if ( gameLocal->spawnIds.ptr[LOWORD(v8) & 0x1FFF] == SLODWORD(v8) >> 13
    && (v9 = gameLocal->entities.ptr[LOWORD(v8) & 0x1FFF]) != nullptr )
  {
    v10 = idEntity::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v10);
  v12 = Physics->GetOrigin(this: Physics, a2: 0);
  v13 = result[947].y;
  x = v12->x;
  v15 = v12->y;
  z = v12->z;
  v35 = x;
  v36 = v15;
  v37 = z;
  if ( gameLocal->spawnIds.ptr[LOWORD(v13) & 0x1FFF] == SLODWORD(v13) >> 13
    && (v17 = gameLocal->entities.ptr[LOWORD(v13) & 0x1FFF]) != nullptr )
  {
    v18 = (idAI2 *)idEntity::CastTo(c: v17);
  }
  else
  {
    v18 = nullptr;
  }
  v19 = idAI2::CastTo(c: v18);
  if ( v19 != nullptr
    || ((v20 = result[947].y, gameLocal->spawnIds.ptr[LOWORD(v20) & 0x1FFF] != SLODWORD(v20) >> 13)
     || (v21 = gameLocal->entities.ptr[LOWORD(v20) & 0x1FFF]) == nullptr
      ? (v22 = nullptr)
      : (v22 = (idPlayer *)idEntity::CastTo(c: v21)),
        (v19 = idPlayer::CastTo(c: v22)) != nullptr) )
  {
    (*(void (__fastcall **)(void *, int, float *))(*(_DWORD *)v19 + 532))(a1: v19, a2: 1, a3: &v35);
  }
  v23 = idEntity::GetPhysics(this: (idEntity *)result);
  v24 = (float *)v23->GetOrigin(this: v23, a2: 0);
  _FP2 = (float)((float)((float)((float)(v37 - v24[2]) * (float)(v37 - v24[2]))
                       + (float)((float)((float)(v36 - v24[1]) * (float)(v36 - v24[1]))
                               + (float)((float)(v35 - *v24) * (float)(v35 - *v24))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v27 = __frsqrte(_FP13);
  v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                      * (float)((float)((float)((float)(v37 - v24[2]) * (float)(v37 - v24[2])) + (float)((float)((float)(v36 - v24[1]) * (float)(v36 - v24[1])) + (float)((float)(v35 - *v24) * (float)(v35 - *v24))))
                                                                                              * (float)0.5))
                                                                              * (float)v27)
                                                                      - (float)1.5)
                                                      * (float)v27)
                                              * (float)((float)((float)((float)(v37 - v24[2]) * (float)(v37 - v24[2]))
                                                              + (float)((float)((float)(v36 - v24[1])
                                                                              * (float)(v36 - v24[1]))
                                                                      + (float)((float)(v35 - *v24) * (float)(v35 - *v24))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v27
                                                                              * (float)((float)((float)((float)(v37 - v24[2]) * (float)(v37 - v24[2]))
                                                                                              + (float)((float)((float)(v36 - v24[1]) * (float)(v36 - v24[1])) + (float)((float)(v35 - *v24) * (float)(v35 - *v24))))
                                                                                      * (float)0.5))
                                                                      * (float)v27)
                                                              - (float)1.5)
                                              * (float)v27))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v27
                                                      * (float)((float)((float)((float)(v37 - v24[2])
                                                                              * (float)(v37 - v24[2]))
                                                                      + (float)((float)((float)(v36 - v24[1])
                                                                                      * (float)(v36 - v24[1]))
                                                                              + (float)((float)(v35 - *v24)
                                                                                      * (float)(v35 - *v24))))
                                                              * (float)0.5))
                                              * (float)v27)
                                      - (float)1.5)
                      * (float)v27));
  v32 = (float)(v35 - *v24)
      * (float)((float)-(float)((float)((float)((float)v28
                                              * (float)((float)((float)((float)(v37 - v24[2]) * (float)(v37 - v24[2]))
                                                              + (float)((float)((float)(v36 - v24[1])
                                                                              * (float)(v36 - v24[1]))
                                                                      + (float)((float)(v35 - *v24) * (float)(v35 - *v24))))
                                                      * (float)0.5))
                                      * (float)v28)
                              - (float)1.5)
              * (float)v28);
  v33 = (float)(v36 - v24[1])
      * (float)((float)-(float)((float)((float)((float)v28
                                              * (float)((float)((float)((float)(v37 - v24[2]) * (float)(v37 - v24[2]))
                                                              + (float)((float)((float)(v36 - v24[1])
                                                                              * (float)(v36 - v24[1]))
                                                                      + (float)((float)(v35 - *v24) * (float)(v35 - *v24))))
                                                      * (float)0.5))
                                      * (float)v28)
                              - (float)1.5)
              * (float)v28);
  if ( (float)((float)((float)-(float)((float)((float)((float)v28
                                                     * (float)((float)((float)((float)(v37 - v24[2])
                                                                             * (float)(v37 - v24[2]))
                                                                     + (float)((float)((float)(v36 - v24[1])
                                                                                     * (float)(v36 - v24[1]))
                                                                             + (float)((float)(v35 - *v24)
                                                                                     * (float)(v35 - *v24))))
                                                             * (float)0.5))
                                             * (float)v28)
                                     - (float)1.5)
                     * (float)v28)
             * (float)((float)((float)(v37 - v24[2]) * (float)(v37 - v24[2]))
                     + (float)((float)((float)(v36 - v24[1]) * (float)(v36 - v24[1]))
                             + (float)((float)(v35 - *v24) * (float)(v35 - *v24))))) >= 0.000099999997 )
  {
    v29 = (float)(result[951].x + result[951].y);
    v34 = result[951].x
        + (float)((float)((float)-(float)((float)((float)((float)v28
                                                        * (float)((float)((float)((float)(v37 - v24[2])
                                                                                * (float)(v37 - v24[2]))
                                                                        + (float)((float)((float)(v36 - v24[1])
                                                                                        * (float)(v36 - v24[1]))
                                                                                + (float)((float)(v35 - *v24)
                                                                                        * (float)(v35 - *v24))))
                                                                * (float)0.5))
                                                * (float)v28)
                                        - (float)1.5)
                        * (float)v28)
                * (float)(v37 - v24[2]));
    result[951].x = result[951].x + result[951].y;
    if ( v29 >= -0.15000001 )
    {
      if ( v29 <= 0.15000001 )
        goto LABEL_27;
      v30 = -0.0099999998;
      v31 = -0.0060000001;
    }
    else
    {
      v30 = 0.0060000001;
      v31 = 0.0099999998;
    }
    result[951].y = RandomFloat(min: v30, max: v31);
    goto LABEL_27;
  }
  v32 = result[458].z;
  v33 = result[459].x;
  v34 = result[459].y;
LABEL_27:
  *(float *)&this->__vftable = v32;
  *(float *)&this->listenerList = v33;
  *(float *)&this->listeningToList = v34;
  return this;
}


// ========================================================================
// ?FindAutoFocusEntity@idDrone@@QAAMAAPBVidEntity@@@Z
// EA  : 0x82C2AEA0
// RVA : 0x00C2AEA0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

float __fastcall idDrone::FindAutoFocusEntity(idDrone *this, idAI2 **bestEntity)
{
  int v2; // r19
  double v5; // fp22
  int v6; // r10
  idAIEntityState *es; // r3
  idTargetInfo *v8; // r25
  idDrone *Entity; // r3
  idAI2 *v10; // r26
  idAIEntityState *v11; // r3
  idPhysics *Physics; // r3
  int v13; // r3
  float v14; // r7
  float v15; // r6
  idAI2 *v16; // r3
  idAI2 *v17; // r24
  idAI2_vtbl *v18; // r11
  idPhysics *v19; // r3
  float *v20; // r3
  double v21; // fp9
  double v22; // fp7
  double v23; // fp1
  idPresentable *presentable; // r11
  double v25; // fp30
  double z; // fp0
  double v27; // fp31
  char v28; // r27
  int v29; // r29
  int v30; // r30
  idPlayerStart *v31; // r3
  double v34; // fp26
  double v35; // fp27
  double v36; // fp1
  double v37; // fp28
  double v38; // fp30
  int visChangeTime; // r30
  __int64 v40; // r10
  double v41; // fp0
  double v42; // fp31
  int v43; // r7
  int v44; // r30
  int num; // r8
  __int64 v46; // r11
  int GameMs; // r3
  double v48; // fp0
  double v49; // fp0
  double v50; // fp0
  double v51; // fp1
  int v53; // [sp+50h] [-1A0h]
  idTargetFilter v54[3]; // [sp+58h] [-198h] BYREF
  float v55; // [sp+70h] [-180h] BYREF
  float v56; // [sp+74h] [-17Ch]
  float v57; // [sp+78h] [-178h]
  idVec3 v58; // [sp+80h] [-170h] BYREF
  idTargetList v59[3]; // [sp+90h] [-160h] BYREF

  v2 = 0;
  *bestEntity = nullptr;
  v5 = -1.0;
  idNonEnemyTargetFilter::idNonEnemyTargetFilter(this: (idNonEnemyTargetFilter *)v54, minAwareness_: AIAWARE_CONFIRMED);
  idTargetList::idTargetList(this: v59, targetCache_: &this->worldState.targetCache);
  idTargetList::Filter(this: v59, owner: (idTurret *)this, filter: v54);
  v53 = 0;
  if ( v59[0].viableTargets.num > 0 )
  {
    while ( 1 )
    {
      v6 = v59[0].viableTargets.list[v2];
      es = (idAIEntityState *)v59[0].targetCache->targets.list[v6].es;
      v8 = &v59[0].targetCache->targets.list[v6];
      if ( es != nullptr )
      {
        Entity = (idDrone *)idAIEntityState::GetEntity(this: es);
        v10 = (idAI2 *)Entity;
        if ( Entity != nullptr
          && Entity != this
          && (idPlayer::CastTo(c: (idPlayer *)Entity) != nullptr || idAI2::CastTo(c: v10) != nullptr)
          && (unsigned __int8)idAIEntityState::IsVisible(this: (idAIEntityState *)v8->es) != 0 )
        {
          v11 = idAIWorldState::StateForEntity(this: &this->worldState, ent: v10);
          if ( v11 != nullptr
            && v11->senses.ptr[1]->lastUnconfirmedStimTime >= 0
            && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
             - v11->senses.ptr[1]->lastConfirmedStimTime < 5000 )
          {
            break;
          }
        }
      }
LABEL_65:
      ++v2;
      if ( ++v53 >= v59[0].viableTargets.num )
        goto LABEL_66;
    }
    Physics = idEntity::GetPhysics(this: v10);
    v13 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v14 = *(float *)(v13 + 4);
    v15 = *(float *)(v13 + 8);
    v55 = *(float *)v13;
    v56 = v14;
    v57 = v15;
    v16 = idAI2::CastTo(c: v10);
    v17 = v16;
    if ( v16 != nullptr )
    {
      v18 = v16->__vftable;
    }
    else
    {
      v16 = (idAI2 *)idPlayer::CastTo(c: (idPlayer *)v10);
      if ( v16 == nullptr )
        goto LABEL_16;
      v18 = v16->__vftable;
    }
    v18->GetAimPoint(this: v16, a2: AIMPOINT_HEAD, a3: (idVec3 *)&v55);
LABEL_16:
    v19 = idEntity::GetPhysics(this);
    v20 = (float *)v19->GetOrigin(this: v19, a2: 0);
    v21 = (float)(v57 - v20[2]);
    v22 = (float)(v56 - v20[1]);
    v58.x = v55 - *v20;
    v58.z = v21;
    v58.y = v22;
    v23 = idVec3::NormalizeFast(this: &v58);
    presentable = this->presentable;
    v25 = v23;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    z = v58.z;
    v27 = (float)((float)(presentable->axis.mat[0].x * v58.x)
                + (float)((float)(presentable->axis.mat[0].y * v58.y) + (float)(presentable->axis.mat[0].z * v58.z)));
    if ( v27 >= 0.75 && z >= -0.5 && z <= 0.5 )
    {
      v28 = 1;
      v29 = 0;
      if ( this->behaviorPoints.num > 0 )
      {
        v30 = 0;
        while ( idEntityPtr<idEntity const>::operator->(this: &this->behaviorPoints.list[v30].entityToScan) != v10 )
        {
          if ( idPlayer::CastTo(c: (idPlayer *)v10) != nullptr )
          {
            v31 = (idPlayerStart *)idEntityPtr<idEntity const>::operator->(this: &this->behaviorPoints.list[v30].entityToScan);
            if ( idPlayerStart::CastTo(c: v31) != nullptr )
              break;
          }
          ++v29;
          ++v30;
          if ( v29 >= this->behaviorPoints.num )
            goto LABEL_29;
        }
        v28 = 0;
      }
LABEL_29:
      if ( v28 != 0 )
      {
        _FP12 = (float)((float)((float)v25 / this->optimalFocusEntityDistance) - (float)1.0);
        __asm { fsel      f11, f12, f29, f13 }
        v34 = (float)((float)1.0 - (float)_FP11);
        if ( v27 > 0.0 )
        {
          if ( v27 < 1.0 )
            v35 = (float)((float)((float)v27 * (float)0.89999998) + (float)0.1);
          else
            v35 = 1.0;
        }
        else
        {
          v35 = 0.1;
        }
        v36 = idRelationship::FloatForAttitude(attitude: (idRelationship::attitude_t)v8->attitude);
        v37 = 0.5;
        if ( v36 < 3.0 || v36 >= 5.0 )
          v37 = 1.0;
        if ( idPlayer::CastTo(c: (idPlayer *)v10) != nullptr )
          v37 = (float)((float)v37 + 0.75);
        v38 = 0.30000001;
        if ( v8->es->senses.ptr[1]->lastUnconfirmedStimTime >= 0 )
        {
          visChangeTime = v8->es->visChangeTime;
          if ( visChangeTime >= 0 )
          {
            LODWORD(v40) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         - visChangeTime;
            v54[1] = (idTargetFilter)v40;
            v41 = (float)v40;
            if ( v41 < 2000.0 )
            {
              if ( v41 > 0.0 )
                v38 = (float)-(float)((float)((float)v40 * (float)0.00025000001) - (float)1.0);
              else
                v38 = 1.0;
            }
          }
          else
          {
            v38 = 1.0;
          }
        }
        v42 = 0.40000001;
        if ( v17 != nullptr && idAI2::GetLookFocusEntity(this: v17) == this )
          v42 = 1.0;
        v43 = 30000;
        v44 = 0;
        num = this->previousFocusEntities.num;
        HIDWORD(v46) = (gameLocal->spawnIds.ptr[v10->entityNumber] << 13) | v10->entityNumber;
        if ( num > 0 )
        {
          LODWORD(v46) = 0;
          while ( *(int *)((char *)&this->previousFocusEntities.list->spawnId.value + v46) != HIDWORD(v46) )
          {
            ++v44;
            LODWORD(v46) = v46 + 4;
            if ( v44 >= num )
              goto LABEL_57;
          }
          if ( v44 >= 0 )
          {
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            HIDWORD(v46) = 4 * v44;
            v43 = GameMs - this->previousFocusEntityTimes.list[v44];
          }
        }
LABEL_57:
        v48 = 0.0099999998;
        if ( v43 >= 10000 )
        {
          LODWORD(v46) = v43;
          v54[2] = (idTargetFilter)v46;
          v49 = (float)v46;
          if ( v49 > 10000.0 )
          {
            if ( v49 < 30000.0 )
              v48 = (float)((float)((float)((float)v46 - (float)10000.0) * (float)0.000045000001) + (float)0.1);
            else
              v48 = 1.0;
          }
          else
          {
            v48 = 0.1;
          }
        }
        v50 = (float)((float)((float)((float)((float)((float)((float)v48 * (float)v42) * (float)v38) * (float)v37)
                                    * (float)v35)
                            * (float)v34)
                    * 5.0);
        if ( v50 > v5 )
        {
          v5 = v50;
          *bestEntity = v10;
        }
      }
    }
    goto LABEL_65;
  }
LABEL_66:
  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)v59);
  v51 = v5;
  return *((float *)&v51 + 1);
}


// ========================================================================
// __unwind$497891
// EA  : 0x82C2B440
// RVA : 0x00C2B440
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_497891()
{
  int v0; // r12

  idAvoidTargetFilter::~idAvoidTargetFilter(this: (idFriendlyDeadTargetFilter *)(v0 - 496 + 88));
}


// ========================================================================
// __unwind$497892
// EA  : 0x82C2B468
// RVA : 0x00C2B468
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_497892()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 496 + 144));
}


// ========================================================================
// ?TurnOnScanner@idDrone@@QAAXXZ
// EA  : 0x82C2B490
// RVA : 0x00C2B490
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::TurnOnScanner(idDrone *this)
{
  int value; // r10
  idEntityPtr<idEntity> *p_currentScanEntity; // r31
  idEntity *v4; // r3
  double v5; // fp31
  idPlayer *v6; // r3
  idEntity *v7; // r3
  idPlayer *v8; // r3
  double v9; // fp1
  double optimalFocusPlayerCuriosity; // fp13
  const idSoundShader *scannerSound; // r5

  if ( !this->isScannerOn )
  {
    value = this->currentScanEntity.spawnId.value;
    p_currentScanEntity = &this->currentScanEntity;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v4 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v4 != nullptr && idEntity::CastTo(c: v4) != nullptr )
      {
        if ( g_droneAllowWeaponsDeployWhenScanning.valueInteger != 0 )
        {
          v5 = 0.2;
          v6 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: p_currentScanEntity);
          if ( idPlayer::CastTo(c: v6) != nullptr )
            v5 = 0.333;
          if ( RandomFloat(max: 1.0) < v5 )
            idDrone::DeployAndStowWeapon(this, gunId: 0, armDelay: 200, disarmDelay: 3000);
        }
        if ( gameLocal->spawnIds.ptr[p_currentScanEntity->spawnId.value & 0x1FFF] == p_currentScanEntity->spawnId.value >> 13
          && (v7 = gameLocal->entities.ptr[p_currentScanEntity->spawnId.value & 0x1FFF]) != nullptr )
        {
          v8 = (idPlayer *)idEntity::CastTo(c: v7);
        }
        else
        {
          v8 = nullptr;
        }
        if ( idPlayer::CastTo(c: v8) != nullptr )
        {
          v9 = RandomFloat(max: this->optimalFocusPlayerCuriosity);
          optimalFocusPlayerCuriosity = this->optimalFocusPlayerCuriosity;
        }
        else
        {
          v9 = RandomFloat(max: this->optimalFocusAICuriosity);
          optimalFocusPlayerCuriosity = this->optimalFocusAICuriosity;
        }
        scannerSound = this->scannerSound;
        this->currentScanEntityCuriosity = (float)((float)optimalFocusPlayerCuriosity * (float)0.5) + (float)v9;
        if ( scannerSound != nullptr )
        {
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_VOICE,
            shader: scannerSound,
            soundShaderFlags: 0,
            peerMask: 0xFFu);
          idEntity::SetSoundVolume(this, channel: SND_CHANNEL_VOICE, volume: -10.0);
        }
        idAlarm::StartFX(this, condition: FX_DRONE_START_SCANNER);
        this->isScannerOn = true;
      }
    }
  }
}


// ========================================================================
// ?TurnOffScanner@idDrone@@QAAXXZ
// EA  : 0x82C2B628
// RVA : 0x00C2B628
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::TurnOffScanner(idDrone *this)
{
  const idSoundShader *stopScannerSound; // r5

  if ( this->isScannerOn )
  {
    stopScannerSound = this->stopScannerSound;
    if ( stopScannerSound != nullptr )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_VOICE,
        shader: stopScannerSound,
        soundShaderFlags: 0,
        peerMask: 0xFFu);
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_VOICE, volume: -10.0);
    }
    else
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_VOICE, peerMask: 0xFFu);
    }
    idAnimatedEntity::StopFX(this, condition: 34);
    idAlarm::StartFX(this, condition: FX_DRONE_STOP_SCANNER);
    this->currentScanEntity.spawnId.value = 0x1FFF;
    this->isScannerOn = false;
  }
}


// ========================================================================
// ??0idDrone@@QAA@XZ
// EA  : 0x82C2B740
// RVA : 0x00C2B740
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

idDrone *__fastcall idDrone::idDrone(idDrone *this)
{
  unsigned __int64 v2; // r29
  int v3; // ctr
  float *p_allowFacingChanges; // r8
  float *p_y; // r9
  float *p_z; // r10
  float *v7; // r11
  int i; // ctr
  float z; // r7
  float v10; // r4
  int v11; // ctr
  float *v12; // r9
  int v13; // ctr
  int *v14; // r11
  float *v15; // r11
  int v16; // ctr
  float *v17; // r10
  float *v18; // r11
  int j; // ctr

  idAnimatedEntity::idAnimatedEntity(this);
  this->slowForPlayer = true;
  this->__vftable = (idDrone_vtbl *)&idDrone::`vftable';
  LODWORD(v2) = 0;
  this->initialPath.spawnId.value = 0x1FFF;
  this->initialWaypoint.spawnId.value = 0x1FFF;
  this->initialState = DS_MOVING;
  this->startingHealth = 333.0;
  this->fleeNearEnemyFlag = true;
  this->declWallSpark = nullptr;
  this->declBreakable = nullptr;
  this->currentState.val = DS_MOVING;
  this->nextState.val = DS_MOVING;
  this->changeStateTime = 0;
  this->lastNonScanState.val = DS_MOVING;
  this->moveStates[0].val = DMS_STOPPED;
  this->moveStates[1].val = DMS_STOPPED;
  this->moveStates[2].val = DMS_STOPPED;
  this->moveStates[3].val = DMS_STOPPED;
  this->currentPathType = DPT_PATROL;
  this->currentPathTypeParm = 0;
  this->patrolWaypointOn = 0;
  this->patrolDirection = 1;
  this->patrolWaypoints.list = nullptr;
  this->patrolWaypoints.granularity = 0;
  this->patrolWaypoints.memTag = 5;
  this->patrolWaypoints.listStatic = 0;
  this->patrolWaypoints.size = 0;
  this->patrolWaypoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->patrolWaypoints);
  this->searchNextUpdateTime = 0;
  this->searchDirection = 1.0;
  this->goals.list = nullptr;
  this->goals.granularity = 0;
  this->goals.memTag = 5;
  this->goals.listStatic = 0;
  this->goals.size = 0;
  this->goals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->goals);
  this->goalSearchDirections.list = nullptr;
  this->goalSearchDirections.granularity = 0;
  this->goalSearchDirections.memTag = 5;
  this->goalSearchDirections.listStatic = 0;
  this->goalSearchDirections.size = 0;
  this->goalSearchDirections.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->goalSearchDirections);
  this->firstThinkFlag = true;
  HIDWORD(v2) = &vec3_origin;
  this->health = 333.0;
  this->currentPosition = vec3_origin;
  v3 = 9;
  p_allowFacingChanges = &this->allowFacingChanges;
  this->previousOrigin = vec3_origin;
  p_y = &mat2_identity.mat[1].y;
  this->desiredFacing.x = 1.0;
  this->desiredFacing.y = 0.0;
  this->desiredFacing.z = 0.0;
  this->currentFacing.x = 1.0;
  this->currentFacing.y = 0.0;
  this->currentFacing.z = 0.0;
  this->allowFacingChanges = 1.0;
  do
  {
    *++p_allowFacingChanges = *++p_y;
    --v3;
  }
  while ( v3 != 0 );
  p_z = &this->currentAxis.mat[2].z;
  v7 = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_z = *++v7;
  this->desiredSpeed = 0.0;
  this->desiredSpeedMultiplier = 1.0;
  this->resetSpeedOverrideCounter = 0;
  this->overrideMaxDesiredSpeed = 0.0;
  this->currentSpeed = 0.0;
  this->allowSpeedChanges = 1.0;
  this->lastFrameOverMove = 0.0;
  this->desiredRoll = 0.0;
  this->currentRoll = 0.0;
  this->allowRollChanges = 1.0;
  this->pitchToAlterSpeed = 0.0;
  this->lookUpToGoUpAount = 0.0;
  this->lowerNoseWhenAccelerating = 1.0;
  this->emergencyBrakeScaler = 1.0;
  this->obstacleAvoidanceMaxSpeed = 15.0;
  this->goalAvoidanceOffset.x = 0.0;
  this->goalAvoidanceOffset.y = 0.0;
  this->goalAvoidanceOffset.z = 0.0;
  this->averageAvoidanceOffset.x = 0.0;
  this->averageAvoidanceOffset.y = 0.0;
  this->averageAvoidanceOffset.z = 0.0;
  this->numActivates = 0;
  idMQBuffer::idMQBuffer(this: &this->attachments);
  this->attachmentHandles[0].value = -1;
  this->attachmentHandles[1].value = -1;
  this->attachmentHandles[2].value = -1;
  this->attachmentHandles[3].value = -1;
  this->navSplinePosition.distance = 0.0;
  this->navSplinePosition.rightDistance = 0.0;
  this->navSplinePosition.navSpline = nullptr;
  navSplinePath_t::navSplinePath_t(this: &this->splinePathToGoal);
  this->deltaToFinalGoal = 0.0;
  this->distanceToFinalGoal = 0.0;
  this->splinePathMgr = nullptr;
  this->immediateGoalSplinePosition.distance = 0.0;
  this->immediateGoalSplinePosition.navSpline = nullptr;
  this->immediateGoalSplinePosition.rightDistance = 0.0;
  this->immediateGoalPosition = vec3_origin;
  this->finalGoalPosition.x = vec3_origin.x;
  this->finalGoalPosition.y = vec3_origin.y;
  z = vec3_origin.z;
  this->goalRightDistance = 0.0;
  this->finalGoalPosition.z = z;
  this->splineDistanceToFinalGoal = 0.0;
  this->rightDistanceToFinalGoal = 0.0;
  this->nearestPlayerDistance = 3000.0;
  this->outOfControl = 0.0;
  this->additivePosition = vec3_origin;
  this->additiveMomentum = vec3_origin;
  this->additiveFacing = quat_identity;
  this->additiveAngularMomentum = quat_identity;
  this->clipQuery.index = v2;
  this->secBetweenAdd = 0.02;
  this->maxAltitude = 150.0;
  this->groundParticlesFromFan = nullptr;
  this->particlesMultiplier = 1.0;
  this->addedParticleMovement = 0.0;
  this->influence.innerRadius = 32.0;
  this->influence.trailDist = 32.0;
  this->influence.outerRadius = 64.0;
  this->influence.angle = 0.0;
  this->influence.trailFadeInTime = 0.25;
  this->influence.trailFadeOutTime = 2.0;
  this->nextGroundFXTime = 0;
  this->controllerShakeLowMag = 1133903872;
  this->controllerShakeHighMag = 500.0;
  this->fanToGroundQuery[0].index = v2;
  this->fanToGroundQuery[1].index = v2;
  this->fanToGroundQuery[2].index = v2;
  this->smallEngineSounds.list = nullptr;
  this->smallEngineSounds.granularity = 0;
  this->smallEngineSounds.memTag = 5;
  this->smallEngineSounds.listStatic = 0;
  this->smallEngineSounds.size = 0;
  this->smallEngineSounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->smallEngineSounds);
  this->largeEngineSounds.list = nullptr;
  this->largeEngineSounds.granularity = 0;
  this->largeEngineSounds.memTag = 5;
  this->largeEngineSounds.listStatic = 0;
  this->largeEngineSounds.size = 0;
  this->largeEngineSounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->largeEngineSounds);
  this->afterburnerSounds.list = nullptr;
  this->afterburnerSounds.granularity = 0;
  this->afterburnerSounds.memTag = 5;
  this->afterburnerSounds.listStatic = 0;
  this->afterburnerSounds.size = 0;
  this->afterburnerSounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->afterburnerSounds);
  this->scannerSound = nullptr;
  this->maxPitchByClosing = 3.0;
  this->stopScannerSound = nullptr;
  this->largeEngineThrustLevel = 0.0;
  this->deployWeaponSound = nullptr;
  this->smallEngineThrustLevel = 0.0;
  this->stowWeaponSound = nullptr;
  this->scanPlayerSound = nullptr;
  this->minPitchByClosing = -3.0;
  this->explosionSound = nullptr;
  this->afterburnerThrustLevel = 0.0;
  this->declTrackingParms = nullptr;
  this->engineSoundsFade = 0.0;
  idFaction::idFaction(this: &this->faction);
  this->optimalFocusPlayerCuriosity = 0x40000000;
  this->focusEntityWidth = 1.0;
  this->focusEntityLength = 1.0;
  this->focusEntityMaterial = nullptr;
  this->visibleSightTime = 0.5;
  this->visibleSightRadius = 5000.0;
  this->disengageEnemyDistance = 4000.0;
  this->optimalFocusEntityDistance = 1000.0;
  this->optimalFocusAICuriosity = 1.5;
  idLaserBeam::idLaserBeam(this: &this->focusEntityEffect);
  idAIWorldState::idAIWorldState(this: &this->worldState);
  this->currentEnemy.spawnId.value = 0x1FFF;
  this->isScannerOn = false;
  this->currentScanEntity.spawnId.value = 0x1FFF;
  this->currentScanEntityCuriosity = 0.0;
  this->currentScanEntityEffectOn = 0.0;
  this->previousFocusEntities.list = nullptr;
  this->previousFocusEntities.granularity = 0;
  this->previousFocusEntities.memTag = 5;
  this->previousFocusEntities.listStatic = 0;
  this->previousFocusEntities.size = 0;
  this->previousFocusEntities.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->previousFocusEntities);
  this->previousFocusEntityTimes.list = nullptr;
  this->previousFocusEntityTimes.granularity = 0;
  this->previousFocusEntityTimes.memTag = 5;
  this->previousFocusEntityTimes.listStatic = 0;
  this->previousFocusEntityTimes.size = 0;
  this->previousFocusEntityTimes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->previousFocusEntityTimes);
  this->focusEntityScanBob = 0.0;
  this->focusEntityScanBobDelta = 0.0;
  this->nearestForwardAi.spawnId.value = 0x1FFF;
  this->nearestForwardAiTime = 0;
  this->thrusterLength = 25.0;
  this->thrusterMaterial = nullptr;
  this->thrusterWidth = 5.0;
  idLaserBeam::idLaserBeam(this: &this->thrusterEffect);
  this->wasAfterburnerFxStarted = false;
  this->lastMovement = vec3_origin;
  this->previousNonThrustMovement.x = vec3_origin.x;
  this->previousNonThrustMovement.y = vec3_origin.y;
  v10 = vec3_origin.z;
  this->thrusterPerceivedFriction = 2.0;
  this->afterburnerAmount = 0.0;
  this->previousNonThrustMovement.z = v10;
  this->nextAfterburnerSmokeTime = 0;
  this->bobGoal = INITIAL_BOB;
  this->engineSmokeAmount = 0.0;
  this->nextEngineSmokeTime = 0;
  this->nextSputterTime = 0;
  idEffectPhysicsDebrisEmitter::idEffectPhysicsDebrisEmitter(this: &this->debrisEmitter);
  this->touching.list = nullptr;
  this->touching.granularity = 0;
  this->touching.memTag = 5;
  this->touching.listStatic = 0;
  this->touching.size = 0;
  this->touching.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  this->enemyTracker = nullptr;
  this->behaviorPoints.list = nullptr;
  this->behaviorPoints.granularity = 0;
  this->behaviorPoints.memTag = 5;
  this->behaviorPoints.listStatic = 0;
  this->behaviorPoints.size = 0;
  this->behaviorPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->behaviorPoints);
  this->nextBehaviorPointToTest = 0;
  this->damageBehaviors.list = nullptr;
  this->damageBehaviors.granularity = 0;
  this->damageBehaviors.memTag = 5;
  this->damageBehaviors.listStatic = 0;
  this->damageBehaviors.size = 0;
  this->damageBehaviors.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->damageBehaviors);
  this->activateCuriosityOverride = -1.0;
  this->currentBehaviorPoint = -1;
  this->dot0to1to2 = 0.0;
  this->dot1to2to3 = 0.0;
  this->rigidPhysicsEnabled = false;
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->rigidPhysics);
  this->wasRemoveEventPosted = false;
  this->deathVarietyDesired = DD_EXPLOSION;
  this->deathDoneTime = 0;
  this->deathTrigger.spawnId.value = 0x1FFF;
  this->delayToHideDrone = 0.2;
  this->minDeathThrustDuration = 1061158912;
  this->maxDeathThrustDuration = 1075838976;
  v11 = 4;
  v12 = &this->moveStateMemberships[3];
  this->recentForceApplied = vec3_origin;
  this->deathThrust = vec3_origin;
  this->droneNode.head = &this->droneNode;
  this->droneNode.next = &this->droneNode;
  this->droneNode.prev = &this->droneNode;
  this->droneNode.owner = nullptr;
  do
  {
    *(v12 - 3) = 0.0;
    *((_DWORD *)v12++ - 7) = 3;
    *v12 = 0.0;
    --v11;
  }
  while ( v11 != 0 );
  this->splinePathMgr = (idAISplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num;
  this->smokeParticle[0] = nullptr;
  this->smokeParticle[1] = nullptr;
  v13 = 4;
  this->smokeParticle[2] = nullptr;
  this->sparkParticle[0] = nullptr;
  v14 = &this->weaponArmTime[3];
  this->sparkParticle[1] = nullptr;
  this->sputterParticle[0] = nullptr;
  this->sputterParticle[1] = nullptr;
  this->sputterParticle[2] = nullptr;
  this->deathParticle[0] = nullptr;
  this->deathParticle[1] = nullptr;
  this->deathParticle[2] = nullptr;
  do
  {
    *((float *)v14 - 11) = 0.0;
    *(v14 - 15) = -1;
    *((float *)v14 - 7) = 0.0;
    *(v14 - 3) = 0;
    *++v14 = 0;
    --v13;
  }
  while ( v13 != 0 );
  this->splineAheadPositions[0] = vec3_origin;
  this->splineAheadPositions[1] = vec3_origin;
  v15 = &this->thrusterShown[9];
  v16 = 10;
  this->splineAheadPositions[2] = vec3_origin;
  this->splineAheadPositions[3] = vec3_origin;
  do
  {
    *(v15 - 19) = 0.0;
    *(v15 - 9) = 0.0;
    *++v15 = 0.0;
    --v16;
  }
  while ( v16 != 0 );
  v17 = &this->ahead[3].z;
  v18 = &this->toAhead[3].z;
  for ( j = 4; j != 0; --j )
  {
    *(v18 - 27) = 0.0;
    *(v18 - 26) = 0.0;
    *(v18 - 25) = 0.0;
    *++v17 = 0.0;
    *(v18 - 11) = 0.0;
    *(v18 - 10) = 0.0;
    *(v18 - 9) = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    v18 += 3;
    *v18 = 0.0;
  }
  this->attachments.parent = this;
  return this;
}


// ========================================================================
// __unwind$498521
// EA  : 0x82C2C030
// RVA : 0x00C2C030
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498521()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$498522
// EA  : 0x82C2C058
// RVA : 0x00C2C058
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498522()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 5356));
}


// ========================================================================
// __unwind$498523
// EA  : 0x82C2C084
// RVA : 0x00C2C084
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498523()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 5380));
}


// ========================================================================
// __unwind$498524
// EA  : 0x82C2C0B0
// RVA : 0x00C2C0B0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498524()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 5396));
}


// ========================================================================
// __unwind$498525
// EA  : 0x82C2C0DC
// RVA : 0x00C2C0DC
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498525()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 5680));
}


// ========================================================================
// __unwind$498526
// EA  : 0x82C2C108
// RVA : 0x00C2C108
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498526()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(*(_DWORD *)(v0 - 192 + 212) + 5792));
}


// ========================================================================
// __unwind$498527
// EA  : 0x82C2C134
// RVA : 0x00C2C134
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498527()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 6040));
}


// ========================================================================
// __unwind$498528
// EA  : 0x82C2C160
// RVA : 0x00C2C160
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498528()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 6056));
}


// ========================================================================
// __unwind$498529
// EA  : 0x82C2C18C
// RVA : 0x00C2C18C
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498529()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 6072));
}


// ========================================================================
// __unwind$498530
// EA  : 0x82C2C1B8
// RVA : 0x00C2C1B8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498530()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 192 + 212) + 6140));
}


// ========================================================================
// __unwind$498531
// EA  : 0x82C2C1E4
// RVA : 0x00C2C1E4
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498531()
{
  int v0; // r12

  idAIWorldState::~idAIWorldState(this: (idAIWorldState *)(*(_DWORD *)(v0 - 192 + 212) + 6208));
}


// ========================================================================
// __unwind$498532
// EA  : 0x82C2C210
// RVA : 0x00C2C210
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498532()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 11380));
}


// ========================================================================
// __unwind$498533
// EA  : 0x82C2C23C
// RVA : 0x00C2C23C
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498533()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 11396));
}


// ========================================================================
// __unwind$498534
// EA  : 0x82C2C268
// RVA : 0x00C2C268
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498534()
{
  int v0; // r12

  idEffectPhysicsDebrisEmitter::~idEffectPhysicsDebrisEmitter(this: (idEffectPhysicsDebrisEmitter *)(*(_DWORD *)(v0 - 192 + 212) + 11632));
}


// ========================================================================
// __unwind$498535
// EA  : 0x82C2C294
// RVA : 0x00C2C294
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498535()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 12096));
}


// ========================================================================
// __unwind$498536
// EA  : 0x82C2C2C0
// RVA : 0x00C2C2C0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498536()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 12116));
}


// ========================================================================
// __unwind$498537
// EA  : 0x82C2C2EC
// RVA : 0x00C2C2EC
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_498537()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 12136));
}


// ========================================================================
// ??1idDrone@@UAA@XZ
// EA  : 0x82C2C340
// RVA : 0x00C2C340
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::~idDrone(idDrone *this)
{
  int entityNumber; // r11
  int v3; // r4
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r10
  int v6; // r9
  int v7; // r11

  this->__vftable = (idDrone_vtbl *)&idDrone::`vftable';
  entityNumber = this->entityNumber;
  v3 = 0;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  v6 = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
  if ( num > 0 )
  {
    v7 = 0;
    while ( p_aiWorldStateUsers->list[v7].spawnId.value != v6 )
    {
      ++v3;
      ++v7;
      if ( v3 >= num )
        goto LABEL_8;
    }
    if ( v3 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_aiWorldStateUsers, index: v3);
  }
LABEL_8:
  this->droneNode.prev->next = this->droneNode.next;
  this->droneNode.next->prev = this->droneNode.prev;
  this->droneNode.next = &this->droneNode;
  this->droneNode.prev = &this->droneNode;
  this->droneNode.head = &this->droneNode;
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->droneNode);
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->rigidPhysics);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->damageBehaviors);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->behaviorPoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  idEffectPhysicsPieceEmitter::~idEffectPhysicsPieceEmitter(this: &this->debrisEmitter.piecePhysics);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->previousFocusEntityTimes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->previousFocusEntities);
  idAIWorldState::~idAIWorldState(this: &this->worldState);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->faction.relationships);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->afterburnerSounds);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->largeEngineSounds);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->smallEngineSounds);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splinePathToGoal.path);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachments);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->goalSearchDirections);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->goals);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->patrolWaypoints);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$499607
// EA  : 0x82C2C4C0
// RVA : 0x00C2C4C0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499607()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$499608
// EA  : 0x82C2C4E8
// RVA : 0x00C2C4E8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499608()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5356));
}


// ========================================================================
// __unwind$499609
// EA  : 0x82C2C514
// RVA : 0x00C2C514
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499609()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5380));
}


// ========================================================================
// __unwind$499610
// EA  : 0x82C2C540
// RVA : 0x00C2C540
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499610()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5396));
}


// ========================================================================
// __unwind$499611
// EA  : 0x82C2C56C
// RVA : 0x00C2C56C
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499611()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5680));
}


// ========================================================================
// __unwind$499612
// EA  : 0x82C2C598
// RVA : 0x00C2C598
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499612()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(*(_DWORD *)(v0 - 112 + 132) + 5792));
}


// ========================================================================
// __unwind$499613
// EA  : 0x82C2C5C4
// RVA : 0x00C2C5C4
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499613()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 6040));
}


// ========================================================================
// __unwind$499614
// EA  : 0x82C2C5F0
// RVA : 0x00C2C5F0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499614()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 6056));
}


// ========================================================================
// __unwind$499615
// EA  : 0x82C2C61C
// RVA : 0x00C2C61C
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499615()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 6072));
}


// ========================================================================
// __unwind$499616
// EA  : 0x82C2C648
// RVA : 0x00C2C648
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499616()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 112 + 132) + 6140));
}


// ========================================================================
// __unwind$499617
// EA  : 0x82C2C674
// RVA : 0x00C2C674
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499617()
{
  int v0; // r12

  idAIWorldState::~idAIWorldState(this: (idAIWorldState *)(*(_DWORD *)(v0 - 112 + 132) + 6208));
}


// ========================================================================
// __unwind$499618
// EA  : 0x82C2C6A0
// RVA : 0x00C2C6A0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499618()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 11380));
}


// ========================================================================
// __unwind$499619
// EA  : 0x82C2C6CC
// RVA : 0x00C2C6CC
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499619()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 11396));
}


// ========================================================================
// __unwind$499620
// EA  : 0x82C2C6F8
// RVA : 0x00C2C6F8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499620()
{
  int v0; // r12

  idEffectPhysicsDebrisEmitter::~idEffectPhysicsDebrisEmitter(this: (idEffectPhysicsDebrisEmitter *)(*(_DWORD *)(v0 - 112 + 132) + 11632));
}


// ========================================================================
// __unwind$499621
// EA  : 0x82C2C724
// RVA : 0x00C2C724
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499621()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 12096));
}


// ========================================================================
// __unwind$499622
// EA  : 0x82C2C750
// RVA : 0x00C2C750
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499622()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 12116));
}


// ========================================================================
// __unwind$499623
// EA  : 0x82C2C77C
// RVA : 0x00C2C77C
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499623()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 12136));
}


// ========================================================================
// ?FirstThink@idDrone@@QAA_NXZ
// EA  : 0x82C2C7B0
// RVA : 0x00C2C7B0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

int __fastcall idDrone::FirstThink(idDrone *this)
{
  idPhysics *Physics; // r3
  int v3; // r3
  float *v4; // r10
  _DWORD *v5; // r11
  int i; // ctr
  idPhysics *v7; // r3
  float *v8; // r3
  double v9; // fp9
  double v10; // fp13
  double v11; // fp3
  double v12; // fp12
  double desiredSpeedMultiplier; // fp0
  int value; // r10
  idSplineWaypoint *v15; // r3
  int v16; // r9
  idSplineWaypoint *v17; // r3
  idSplineWaypoint *v18; // r3
  idList<idSplineWaypoint const *,5> *p_patrolWaypoints; // r25
  idSplineWaypoint *v20; // r28
  int num; // r11
  char v22; // r22
  int v23; // r26
  int v24; // r27
  int v25; // r9
  idEntity *v26; // r3
  idEntity *v27; // r29
  int v28; // r9
  int v29; // r10
  const idSplineWaypoint **list; // r8
  int v31; // r11
  idNavSplinePath *v32; // r3
  idNavSplinePath *v33; // r3
  idNavSpline *NavSpline; // r29
  idPhysics *v35; // r3
  int v36; // r3
  idPhysics *v37; // r3
  int v38; // r3
  int patrolWaypointOn; // r11
  idList<idSplineWaypoint const *,5> *p_goals; // r28
  idList<float,5> *p_goalSearchDirections; // r29
  navSplinePath_t *ShortestPathByList; // r3
  idPhysics_RigidBody *p_rigidPhysics; // r29
  idPhysics_RigidBody_vtbl *v45; // r28
  idClipModel *MoveableClipModel; // r3
  idDrone::droneState_t initialState; // r11
  idDrone::droneMoveState_t v48; // r9
  idTreeAnimator *TreeAnimatorFromPresentable; // r28
  idClipModel *v50; // r3
  idClipModel *v51; // r4
  int v52; // r6
  soundChannel_t v53; // r28
  int v54; // r27
  int v55; // r29
  idDrone::blendedSounds_t *v56; // r11
  idDrone::blendedSounds_t *v57; // r11
  int v58; // r27
  int v59; // r29
  idDrone::blendedSounds_t *v60; // r11
  idDrone::blendedSounds_t *v61; // r11
  int v62; // r27
  int v63; // r29
  idDrone::blendedSounds_t *v64; // r11
  encounterGroupRole_t v65[2]; // [sp+74h] [-6DCh] BYREF
  float v66[11]; // [sp+7Ch] [-6D4h] BYREF
  _BYTE v67[24]; // [sp+A8h] [-6A8h] BYREF
  idTraceModel v68; // [sp+C0h] [-690h] BYREF

  Physics = idEntity::GetPhysics(this);
  v3 = (int)Physics->GetAxis(this: Physics, a2: 0);
  v4 = v66;
  v5 = (_DWORD *)(v3 - 4);
  for ( i = 9; i != 0; --i )
    *++v4 = *(float *)++v5;
  this->health = this->startingHealth;
  v7 = idEntity::GetPhysics(this);
  v8 = (float *)v7->GetOrigin(this: v7, a2: 0);
  v9 = *v8;
  this->currentPosition.x = *v8;
  this->currentPosition.y = v8[1];
  this->currentPosition.z = v8[2];
  this->previousOrigin.x = v9;
  this->previousOrigin.y = this->currentPosition.y;
  this->previousOrigin.z = this->currentPosition.z;
  v10 = v66[2];
  v11 = v66[1];
  v12 = v66[3];
  this->desiredFacing.x = v66[1];
  this->desiredFacing.y = v10;
  this->desiredFacing.z = v12;
  this->currentFacing.x = v11;
  this->currentFacing.y = this->desiredFacing.y;
  v65[0] = (encounterGroupRole_t)&this->previousAxis.mat[1];
  this->currentFacing.z = this->desiredFacing.z;
  this->previousAxis.mat[0].x = v11;
  v65[0] = (encounterGroupRole_t)&this->previousAxis.mat[2];
  this->previousAxis.mat[1].x = v66[4];
  this->previousAxis.mat[0].y = v10;
  this->previousAxis.mat[0].z = v12;
  this->previousAxis.mat[1].y = v66[5];
  this->previousAxis.mat[1].z = v66[6];
  this->previousAxis.mat[2].x = v66[7];
  this->previousAxis.mat[2].y = v66[8];
  this->previousAxis.mat[2].z = v66[9];
  this->desiredRoll = 0.0;
  this->currentRoll = 0.0;
  this->pitchToAlterSpeed = 0.0;
  this->lookUpToGoUpAount = 0.0;
  this->lowerNoseWhenAccelerating = 1.0;
  this->immediateGoalPosition.x = this->currentPosition.x;
  this->immediateGoalPosition.y = this->currentPosition.y;
  this->immediateGoalPosition.z = this->currentPosition.z;
  this->finalGoalPosition.x = this->currentPosition.x;
  this->finalGoalPosition.y = this->currentPosition.y;
  this->finalGoalPosition.z = this->currentPosition.z;
  this->outOfControl = 0.0;
  this->additivePosition = vec3_origin;
  this->additiveMomentum = vec3_origin;
  this->additiveFacing = quat_identity;
  this->additiveAngularMomentum = quat_identity;
  this->bobGoal = INITIAL_BOB;
  this->nextEngineSmokeTime = 0;
  this->engineSmokeAmount = 0.0;
  this->nextSputterTime = 0;
  this->recentForceApplied = vec3_origin;
  desiredSpeedMultiplier = this->desiredSpeedMultiplier;
  if ( desiredSpeedMultiplier >= 0.25 )
  {
    if ( desiredSpeedMultiplier > 2.0 )
      this->desiredSpeedMultiplier = 2.0;
  }
  else
  {
    this->desiredSpeedMultiplier = 0.25;
  }
  value = this->initialWaypoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v15 = (idSplineWaypoint *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v15 == nullptr || idSplineWaypoint::CastTo(c: v15) == nullptr )
    return 0;
  v16 = this->initialWaypoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
    && (v17 = (idSplineWaypoint *)gameLocal->entities.ptr[v16 & 0x1FFF]) != nullptr )
  {
    v18 = idSplineWaypoint::CastTo(c: v17);
  }
  else
  {
    v18 = nullptr;
  }
  p_patrolWaypoints = &this->patrolWaypoints;
  v20 = v18;
  v65[0] = (encounterGroupRole_t)v18;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->patrolWaypoints);
  do
  {
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->patrolWaypoints,
      obj: v65);
    v22 = 0;
    v23 = 0;
    num = v20->targets.num;
    if ( num > 0 )
    {
      v24 = 0;
      while ( 1 )
      {
        if ( v23 < num
          && (v25 = v20->targets.list[v24].spawnId.value, gameLocal->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13)
          && (v26 = gameLocal->entities.ptr[v25 & 0x1FFF]) != nullptr )
        {
          v27 = idEntity::CastTo(c: v26);
        }
        else
        {
          v27 = nullptr;
        }
        if ( (unsigned __int8)idSplineWaypoint::IsTypeOf(c: v27) != 0 )
        {
          v28 = this->patrolWaypoints.num;
          v20 = (idSplineWaypoint *)v27;
          v29 = 0;
          v65[0] = (encounterGroupRole_t)v27;
          if ( v28 <= 0 )
            break;
          list = p_patrolWaypoints->list;
          v31 = 0;
          while ( list[v31] != v27 )
          {
            ++v29;
            ++v31;
            if ( v29 >= v28 )
              goto LABEL_27;
          }
          if ( v29 < 0 || &list[v29] == nullptr )
            break;
        }
        ++v23;
        ++v24;
        num = v20->targets.num;
        if ( v23 >= num )
          goto LABEL_28;
      }
LABEL_27:
      v22 = 1;
    }
LABEL_28:
    ;
  }
  while ( v22 != 0 );
  if ( this->patrolWaypoints.num < 2 )
    return 0;
  if ( gameLocal->spawnIds.ptr[this->initialPath.spawnId.value & 0x1FFF] == this->initialPath.spawnId.value >> 13 )
  {
    v32 = (idNavSplinePath *)gameLocal->entities.ptr[this->initialPath.spawnId.value & 0x1FFF];
    v33 = v32 != nullptr ? idNavSplinePath::CastTo(c: v32) : nullptr;
    NavSpline = idNavSplinePathMgr::GetNavSpline(this: this->splinePathMgr, splineName: v33->name.data);
    v35 = idEntity::GetPhysics(this);
    v35->GetOrigin(this: v35, a2: 0);
    v36 = ((int (__fastcall *)(_BYTE *, _DWORD, _DWORD, _DWORD, idNavSpline *, double, double))this->splinePathMgr->GetClosestPathPosition)(
            a1: v67,
            a2: *(_DWORD *)LODWORD(vec3_origin.x),
            a3: *(_DWORD *)(LODWORD(vec3_origin.x) + 4),
            a4: __ROL4__(*(_DWORD *)(LODWORD(vec3_origin.x) + 8), 32),
            a5: NavSpline,
            a6: 3000.0,
            a7: 0.1);
    this->navSplinePosition.distance = *(float *)v36;
    this->navSplinePosition.rightDistance = *(float *)(v36 + 4);
    this->navSplinePosition.navSpline = *(idNavSpline **)(v36 + 8);
  }
  else
  {
    v37 = idEntity::GetPhysics(this);
    v37->GetOrigin(this: v37, a2: 0);
    v38 = ((int (__fastcall *)(_BYTE *, _DWORD, _DWORD, _DWORD, _DWORD, char *, _DWORD, _DWORD, double, double))this->splinePathMgr->GetClosestPathPosition)(
            a1: v67,
            a2: *(_DWORD *)LODWORD(vec3_origin.x),
            a3: *(_DWORD *)(LODWORD(vec3_origin.x) + 4),
            a4: __ROL4__(*(_DWORD *)(LODWORD(vec3_origin.x) + 8), 32),
            a5: 0,
            a6: byte_821B0000,
            a7: LODWORD(vec3_origin.x),
            a8: LODWORD(vec3_origin.y),
            a9: 3000.0,
            a10: 0.1);
    this->navSplinePosition.distance = *(float *)v38;
    this->navSplinePosition.rightDistance = *(float *)(v38 + 4);
    this->navSplinePosition.navSpline = *(idNavSpline **)(v38 + 8);
  }
  patrolWaypointOn = this->patrolWaypointOn;
  this->splinePathToGoal.distance = 0.0;
  v65[0] = (encounterGroupRole_t)p_patrolWaypoints->list[patrolWaypointOn];
  if ( v65[0] == ROLE_NONE )
    return 0;
  p_goals = &this->goals;
  if ( this->goals.listStatic == 0 || this->goals.listStatic == 2 )
  {
    if ( p_goals->list != nullptr )
      idMem::Free(this: &mem, ptr: p_goals->list, align: ALIGN_16);
    p_goals->list = nullptr;
    this->goals.size = 0;
  }
  this->goals.num = 0;
  p_goalSearchDirections = &this->goalSearchDirections;
  if ( this->goalSearchDirections.listStatic == 0 || this->goalSearchDirections.listStatic == 2 )
  {
    if ( p_goalSearchDirections->list != nullptr )
      idMem::Free(this: &mem, ptr: p_goalSearchDirections->list, align: ALIGN_16);
    p_goalSearchDirections->list = nullptr;
    this->goalSearchDirections.size = 0;
  }
  this->goalSearchDirections.num = 0;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->goals, obj: v65);
  idList<float,13>::Append(this: (idList<float,13> *)&this->goalSearchDirections, obj: &this->searchDirection);
  if ( this->splinePathMgr == nullptr )
    return 0;
  ShortestPathByList = idNavSplinePathMgr::GetShortestPathByList(
                         this: (idNavSplinePathMgr *)LODWORD(this->navSplinePosition.distance),
                         start: (idNavSplinePosition *)LODWORD(this->navSplinePosition.rightDistance),
                         waypoints: (idList<idSplineWaypoint const *,5> *)__ROL4__(this->navSplinePosition.navSpline, 32),
                         path: (navSplinePath_t *)&this->goals);
  if ( ShortestPathByList == nullptr )
  {
    idLib::Warning(fmt: "Drone '%s' could not find a path.", this->name.data);
    return 0;
  }
  if ( ShortestPathByList->path.num < 1 )
    return 0;
  p_rigidPhysics = &this->rigidPhysics;
  idPhysics::InitPhysics(
    this: &this->rigidPhysics,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  v45 = this->rigidPhysics.__vftable;
  MoveableClipModel = idEntity::CreateMoveableClipModel(this, barrelCollision: true, overrideRadius: -1.0);
  ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))v45->SetClipModel)(
    a1: &this->rigidPhysics,
    a2: MoveableClipModel,
    a3: 1.0);
  this->rigidPhysics.SetContents(this: &this->rigidPhysics, a2: 0, a3: -1);
  this->rigidPhysics.SetClipMask(this: &this->rigidPhysics, a2: 37953, a3: -1);
  if ( this->initialState > (unsigned int)DS_ADJUST_SPEED )
    this->initialState = DS_WAITING;
  initialState = this->initialState;
  this->currentState.val = initialState;
  this->nextState.val = initialState;
  if ( initialState != DS_SCANNING )
    this->lastNonScanState.val = initialState;
  this->changeStateTime = 0;
  v48 = MOVE_STATE_BY_DRONE_STATE[initialState];
  this->moveStateMemberships[0] = 1065353216;
  this->moveStates[0].val = v48;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idTraceModel::InitBox(this: &v68);
  idTraceModel::SetupBox(this: &v68, boxBounds: &TreeAnimatorFromPresentable->referenceBounds);
  v50 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v50 != nullptr )
    v51 = idClipModel::idClipModel(this: v50, clip: &clientGame->clip, trm: &v68, numTraceModels: 1, material: nullptr);
  else
    v51 = nullptr;
  ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))p_rigidPhysics->SetClipModel)(
    a1: &this->rigidPhysics,
    a2: v51,
    a3: 1.0);
  p_rigidPhysics->SetContents(this: &this->rigidPhysics, a2: 0, a3: -1);
  v52 = this->smallEngineSounds.num;
  this->rigidPhysicsEnabled = true;
  v53 = SND_CHANNEL_ENGINE_IDLE;
  v54 = 0;
  if ( v52 > 0 )
  {
    v55 = 0;
    do
    {
      if ( v53 >= SND_CHANNEL_WEAPON_1 )
        break;
      v56 = &this->smallEngineSounds.list[v55];
      if ( v56->sound != nullptr )
      {
        if ( v56->minSpeedPitch > (double)(float)(v56->maxSpeedPitch - (float)2.0) )
          v56->minSpeedPitch = v56->maxSpeedPitch - (float)2.0;
        v57 = &this->smallEngineSounds.list[v55];
        if ( v57->minThrustVolume > (double)(float)(v57->maxThrustVolume - (float)15.0) )
          v57->minThrustVolume = v57->maxThrustVolume - (float)15.0;
        idEntity::StartSoundShader(
          this,
          channel: v53,
          shader: this->smallEngineSounds.list[v55].sound,
          soundShaderFlags: 0,
          peerMask: 0xFFu);
        idEntity::SetSoundVolume(this, channel: v53++, volume: 0.0);
      }
      ++v54;
      ++v55;
    }
    while ( v54 < this->smallEngineSounds.num );
  }
  v58 = 0;
  if ( this->largeEngineSounds.num > 0 )
  {
    v59 = 0;
    do
    {
      if ( v53 >= SND_CHANNEL_WEAPON_1 )
        break;
      v60 = &this->largeEngineSounds.list[v59];
      if ( v60->sound != nullptr )
      {
        if ( v60->minSpeedPitch > (double)(float)(v60->maxSpeedPitch - (float)2.0) )
          v60->minSpeedPitch = v60->maxSpeedPitch - (float)2.0;
        v61 = &this->largeEngineSounds.list[v59];
        if ( v61->minThrustVolume > (double)(float)(v61->maxThrustVolume - (float)15.0) )
          v61->minThrustVolume = v61->maxThrustVolume - (float)15.0;
        idEntity::StartSoundShader(
          this,
          channel: v53,
          shader: this->largeEngineSounds.list[v59].sound,
          soundShaderFlags: 0,
          peerMask: 0xFFu);
        idEntity::SetSoundVolume(this, channel: v53++, volume: 0.0);
      }
      ++v58;
      ++v59;
    }
    while ( v58 < this->largeEngineSounds.num );
  }
  v62 = 0;
  if ( this->afterburnerSounds.num > 0 )
  {
    v63 = 0;
    do
    {
      if ( v53 >= SND_CHANNEL_WEAPON_1 )
        break;
      v64 = &this->afterburnerSounds.list[v63];
      if ( v64->sound != nullptr )
      {
        if ( v64->minSpeedPitch > (double)(float)(v64->maxSpeedPitch - (float)2.0) )
          v64->minSpeedPitch = v64->maxSpeedPitch - (float)2.0;
        this->afterburnerSounds.list[v63].minThrustVolume = -1027080192;
        idEntity::StartSoundShader(
          this,
          channel: v53,
          shader: this->afterburnerSounds.list[v63].sound,
          soundShaderFlags: 0,
          peerMask: 0xFFu);
        idEntity::SetSoundVolume(this, channel: v53++, volume: 0.0);
      }
      ++v62;
      ++v63;
    }
    while ( v62 < this->afterburnerSounds.num );
  }
  this->firstThinkFlag = false;
  return 1;
}


// ========================================================================
// __unwind$499942
// EA  : 0x82C2D2A4
// RVA : 0x00C2D2A4
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_499942()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1872 + 112), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?SetNewStateInternal@idDrone@@QAAXV?$idEnum@W4droneState_t@idDrone@@$08@@@Z
// EA  : 0x82C2D2D0
// RVA : 0x00C2D2D0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::SetNewStateInternal(idDrone *this, idEnum<enum idDrone::droneState_t,9> *newState)
{
  idEnum<enum idDrone::droneState_t,9> *val; // r11
  char *v5; // r6
  double v6; // fp12

  val = (idEnum<enum idDrone::droneState_t,9> *)this->currentState.val;
  if ( val != newState )
  {
    if ( newState == (idEnum<enum idDrone::droneState_t,9> *)3 )
    {
      this->lastNonScanState.val = (idDrone::droneState_t)val;
    }
    else
    {
      this->lastNonScanState.val = (idDrone::droneState_t)newState;
      this->currentScanEntity.spawnId.value = 0x1FFF;
    }
    if ( this->currentState.val == DS_SCANNING )
      idDrone::TurnOffScanner(this);
    if ( newState == (idEnum<enum idDrone::droneState_t,9> *)3 )
      idDrone::TurnOnScanner(this);
    v5 = (char *)(4 * ((_DWORD)newState + 9 * this->currentState.val));
    this->allowFacingChanges = *(float *)((char *)ALLOW_FACING_CHANGES_FOR_STATE_CHANGE[0] + (_DWORD)v5);
    this->allowSpeedChanges = *(float *)((char *)ALLOW_SPEED_CHANGES_FOR_STATE_CHANGE[0] + (_DWORD)v5);
    v6 = *(float *)((char *)ALLOW_ROLL_CHANGES_FOR_STATE_CHANGE[0] + (_DWORD)v5);
    this->currentState.val = (idDrone::droneState_t)newState;
    this->allowRollChanges = v6;
    this->nextState.val = (idDrone::droneState_t)newState;
  }
}


// ========================================================================
// ?GetDesiredFacing@idDrone@@QAA?AVidVec3@@XZ
// EA  : 0x82C2D398
// RVA : 0x00C2D398
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

idDrone *__fastcall idDrone::GetDesiredFacing(idDrone *this, idVec3 *result)
{
  float z; // r11

  z = result[439].z;
  if ( LODWORD(z) > 4 )
  {
    result[439].z = 0.0;
  }
  else if ( LODWORD(z) == 3 )
  {
    idDrone::GetDesiredFacingForScanning(this, result);
    return this;
  }
  idDrone::GetDesiredFacingForMoving(this, result);
  return this;
}


// ========================================================================
// ?Spawn@idDrone@@QAAXXZ
// EA  : 0x82C2D470
// RVA : 0x00C2D470
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::Spawn(idDrone *this)
{
  int v2; // r7
  int v3; // r10
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r9
  int v6; // r11
  idAttachment *list; // r9
  double z; // fp12
  double v9; // fp8
  double v10; // fp10
  double v11; // fp9
  idAttachment *v12; // r3
  idClipModel *v13; // r29
  idPhysics *Physics; // r3
  idPhysics *v15; // r3
  int v16; // r4
  const idMaterial *thrusterMaterial; // r10
  const idMaterial *focusEntityMaterial; // r11
  double focusEntityWidth; // fp0
  double visibleSightTime; // fp0
  double v21; // fp13
  idLinkList<idDrone> *head; // r5
  idAttachmentCollection v23; // [sp+50h] [-660h] BYREF
  float v24; // [sp+64h] [-64Ch]
  float v25; // [sp+68h] [-648h]
  float v26; // [sp+6Ch] [-644h]
  float v27; // [sp+70h] [-640h]
  float v28; // [sp+74h] [-63Ch]
  idTraceModel v29; // [sp+80h] [-630h] BYREF

  if ( this != nullptr )
    v2 = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v2 = 0x1FFF;
  v23.attachments.list = (idAttachment *)v2;
  v3 = 0;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num <= 0 )
    goto LABEL_10;
  v6 = 0;
  while ( p_aiWorldStateUsers->list[v6].spawnId.value != v2 )
  {
    ++v3;
    ++v6;
    if ( v3 >= num )
      goto LABEL_10;
  }
  if ( v3 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_aiWorldStateUsers, obj: (const idEntityPtr<idEntity> *)&v23);
  if ( this->GetFaction(this) == nullptr )
    idLib::Error(fmt: "%s - drone has no faction set", this->name.data);
  list = idAttachmentCollection::AddAttachment(
           this: &v23,
           result: &this->attachments.attachments,
           modelName: "models/vehicles/weapons/class3turret/class3turret.lwo",
           tag: "ba")->attachments.list;
  v23.attachments.list = (idAttachment *)&this->clipModelInfo.size;
  this->attachmentHandles[0].value = (int)list;
  z = this->clipModelInfo.size.z;
  v9 = (float)(this->clipModelInfo.size.x * (float)0.5);
  v10 = (float)(this->clipModelInfo.size.y * (float)0.5);
  v11 = (float)(this->clipModelInfo.size.z * (float)0.5);
  v27 = this->clipModelInfo.size.y * (float)0.5;
  v26 = v9;
  v28 = (float)z * (float)0.5;
  *(float *)&v23.parent = -v9;
  v24 = -v10;
  v25 = -v11;
  idTraceModel::SetupCylinder(this: &v29, cylBounds: (const idBounds *)&v23.parent, numSides: 8);
  v12 = (idAttachment *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0xD8u,
                          tag: TAG_CLIPMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v23.attachments.list = v12;
  if ( v12 != nullptr )
    v13 = idClipModel::idClipModel(
            this: (idClipModel *)v12,
            clip: &clientGame->clip,
            trm: &v29,
            numTraceModels: 1,
            material: nullptr);
  else
    v13 = nullptr;
  Physics = idEntity::GetPhysics(this);
  ((void (__fastcall *)(idPhysics *, idClipModel *, double))Physics->SetClipModel)(a1: Physics, a2: v13, a3: 1.0);
  v15 = idEntity::GetPhysics(this);
  v15->SetContents(this: v15, a2: 197120, a3: -1);
  this->SetAxis(this, a2: &mat3_identity);
  idAttachmentCollection::HideAttachments(this: &this->attachments);
  thrusterMaterial = this->thrusterMaterial;
  focusEntityMaterial = this->focusEntityMaterial;
  this->thrusterEffect.height = this->thrusterWidth;
  this->thrusterEffect.material = thrusterMaterial;
  if ( focusEntityMaterial != nullptr )
  {
    focusEntityWidth = this->focusEntityWidth;
    this->focusEntityEffect.material = focusEntityMaterial;
    this->focusEntityEffect.height = focusEntityWidth;
  }
  visibleSightTime = this->visibleSightTime;
  v21 = 0.30000001;
  if ( visibleSightTime < 0.30000001 || (v21 = 1.5, visibleSightTime > 1.5) )
    this->visibleSightTime = v21;
  idAIWorldState::Init(
    this: &this->worldState,
    visibleSightTime_: this->visibleSightTime,
    friendlyVisibilityEffectsMask_: v16,
    enemyVisibilityEffectsMask_: -1,
    a5: -1);
  this->worldState.radius = 1000.0;
  idEntity::BecomeActive(this, flags: 5);
  head = gameLocal->regimeDrones.head;
  this->droneNode.prev->next = this->droneNode.next;
  this->droneNode.next->prev = this->droneNode.prev;
  this->droneNode.prev = &this->droneNode;
  this->droneNode.head = &this->droneNode;
  this->droneNode.next = head;
  this->droneNode.prev = head->prev;
  head->prev = &this->droneNode;
  this->droneNode.prev->next = &this->droneNode;
  this->droneNode.head = head->head;
  this->droneNode.owner = this;
}


// ========================================================================
// $LN104_2
// EA  : 0x82C2D76C
// RVA : 0x00C2D76C
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _LN104_2()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1712 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Show@idDrone@@UAAXXZ
// EA  : 0x82C2D798
// RVA : 0x00C2D798
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::Show(idDrone *this)
{
  char idCombatStage_useRelaxedChatterVO; // r30
  idEntityPtr<idAI2> v3; // [sp+50h] [-20h] BYREF

  idCombatStage_useRelaxedChatterVO = Get_idCombatStage_useRelaxedChatterVO(ptr: this);
  idEntity::Show(this);
  if ( idCombatStage_useRelaxedChatterVO == 0 )
  {
    if ( this != nullptr )
      v3.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
    else
      v3.spawnId.value = 0x1FFF;
    idList<idEntityPtr<idEntity>,5>::AddUnique(
      this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->aiWorldStateUsers,
      obj: &v3);
    idAttachmentCollection::ShowAttachments(this: &this->attachments, hideVehicleAttachments: false);
  }
}


// ========================================================================
// ?DormantEnd@idDrone@@UAAXH@Z
// EA  : 0x82C2D838
// RVA : 0x00C2D838
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::DormantEnd(idDrone *this, int timeDormant)
{
  int v3; // r7
  int v4; // r10
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r9
  int v7; // r11
  idEntityPtr<idEntity> v8; // [sp+50h] [-20h] BYREF

  idEntity::DormantEnd(this, timeDormant);
  if ( this != nullptr )
    v3 = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v3 = 0x1FFF;
  v8.spawnId.value = v3;
  v4 = 0;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num <= 0 )
    goto LABEL_10;
  v7 = 0;
  while ( p_aiWorldStateUsers->list[v7].spawnId.value != v3 )
  {
    ++v4;
    ++v7;
    if ( v4 >= num )
      goto LABEL_10;
  }
  if ( v4 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_aiWorldStateUsers, obj: &v8);
}


// ========================================================================
// ?SetStateSetMoveState@idDrone@@QAAXV?$idEnum@W4droneState_t@idDrone@@$08@@V?$idEnum@W4droneMoveState_t@idDrone@@$04@@@Z
// EA  : 0x82C2D8E8
// RVA : 0x00C2D8E8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::SetStateSetMoveState(idDrone *this, int newState, idDrone::droneMoveState_t newMoveState)
{
  int v4; // r30
  char v6; // r11

  v4 = newState;
  if ( newState >= 0 )
  {
    if ( newState >= 9 )
      v4 = 8;
  }
  else
  {
    v4 = 0;
  }
  if ( v4 != this->currentState.val )
  {
    idDrone::SetNewStateInternal(this, newState: (idEnum<enum idDrone::droneState_t,9> *)v4);
    if ( newMoveState < DMS_STOPPED || (v6 = 0, newMoveState >= DMS_NUM_DRONE_MOVE_STATES) )
      v6 = 1;
    if ( v6 != 0 )
    {
      newMoveState = MOVE_STATE_BY_DRONE_STATE[v4];
      if ( newMoveState >= DMS_STOPPED )
      {
        if ( newMoveState >= DMS_NUM_DRONE_MOVE_STATES )
          newMoveState = DMS_FAST;
      }
      else
      {
        newMoveState = DMS_STOPPED;
      }
    }
    idDrone::ChangeMoveState(
      this,
      newState: newMoveState,
      time: DEFAULT_CHANGE_MOVE_STATE_TIME[this->moveStates[0].val][newMoveState]);
  }
}


// ========================================================================
// ?SetState@idDrone@@QAAXV?$idEnum@W4droneState_t@idDrone@@$08@@@Z
// EA  : 0x82C2D9B8
// RVA : 0x00C2D9B8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __fastcall idDrone::SetState(idDrone *this, int newState)
{
  idDrone::droneMoveState_t v2; // r5

  if ( newState >= 0 )
  {
    if ( newState >= 9 )
      newState = 8;
  }
  else
  {
    newState = 0;
  }
  v2 = MOVE_STATE_BY_DRONE_STATE[newState];
  if ( v2 >= DMS_STOPPED )
  {
    if ( v2 >= DMS_NUM_DRONE_MOVE_STATES )
      v2 = DMS_FAST;
  }
  else
  {
    v2 = DMS_STOPPED;
  }
  idDrone::SetStateSetMoveState(this, newState, newMoveState: v2);
}


// ========================================================================
// ?HandleObstacleAvoidance@idDrone@@QAA_NPBVidAI2@@AAVidBounds@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C2DA10
// RVA : 0x00C2DA10
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

int __fastcall idDrone::HandleObstacleAvoidance(
        idDrone *this,
        const idAI2 *ai,
        idBounds *bounds,
        idVec3 *origin,
        idMat3 *otherAxis)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  idPhysics *Physics; // r3
  int v13; // r3
  float v14; // r7
  float v15; // r6
  idPhysics *v16; // r3
  float *v17; // r3
  double x; // fp30
  double z; // fp29
  double y; // fp28
  double v21; // fp12
  double v22; // fp10
  double v23; // fp1
  double v24; // fp31
  idEntityPtr<idEntity> *p_nearestForwardAi; // r26
  idEntity *v26; // r3
  idEntity *v27; // r25
  idPhysics *v28; // r3
  float *v29; // r22
  idPhysics *v30; // r3
  float *v31; // r3
  double v32; // fp10
  double v33; // fp6
  idPhysics *v34; // r3
  float *v35; // r25
  idPhysics *v36; // r3
  float *v37; // r3
  idPhysics *v38; // r3
  float *v39; // r22
  idPhysics *v40; // r3
  float *v41; // r3
  double v42; // fp1
  double v43; // fp26
  double v44; // fp0
  double v45; // fp31
  double v46; // fp13
  double v47; // fp12
  double v48; // fp7
  double v49; // fp6
  double v50; // fp1
  double v51; // fp13
  double v52; // fp7
  double v53; // fp8
  double v54; // fp6
  double v55; // fp9
  double v56; // fp0
  double v57; // fp11
  double valueFloat; // fp0
  double currentSpeed; // fp0
  double v60; // fp12
  double v61; // fp0
  double v62; // fp31
  double v63; // fp9
  idPLogScope v65; // [sp+58h] [-108h] BYREF
  idMat3 v66; // [sp+60h] [-100h] BYREF
  float v67; // [sp+84h] [-DCh]
  float v68; // [sp+88h] [-D8h]
  idVec3 v69; // [sp+90h] [-D0h] BYREF
  idVec3 v70[8]; // [sp+A0h] [-C0h] BYREF

  RD_EventBegin(name: "HandleObstacleAvoidance");
  LODWORD(v10) = "HandleObstacleAvoidance";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: &v65, pl: &pLog, gMask: v10, label: v11);
  if ( this->health <= 0.0 || this->aheadDistance[0] <= 0.0 )
    goto LABEL_51;
  Physics = idEntity::GetPhysics(this: &ai->idActor);
  v13 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v14 = *(float *)(v13 + 4);
  v15 = *(float *)(v13 + 8);
  v66.mat[1].y = *(float *)v13;
  v66.mat[1].z = v14;
  v66.mat[2].x = v15;
  v16 = idEntity::GetPhysics(this);
  v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
  x = v66.mat[2].x;
  z = v66.mat[1].z;
  y = v66.mat[1].y;
  v21 = (float)(v66.mat[2].x - v17[2]);
  v22 = (float)(v66.mat[1].z - v17[1]);
  v69.x = v66.mat[1].y - *v17;
  v69.z = v21;
  v69.y = v22;
  v23 = idVec3::NormalizeFast(this: &v69);
  v24 = v23;
  if ( v23 <= 0.0099999998 )
  {
    this->obstacleAvoidanceMaxSpeed = 0.0;
    goto LABEL_51;
  }
  if ( v23 >= MAX_COLLISION_DISTANCE )
    goto LABEL_51;
  p_nearestForwardAi = &this->nearestForwardAi;
  v26 = idEntityPtr<idEntity const>::operator->(this: &this->nearestForwardAi);
  v27 = v26;
  if ( v26 == nullptr )
  {
    if ( ai == nullptr )
    {
      p_nearestForwardAi->spawnId.value = 0x1FFF;
LABEL_17:
      this->nearestForwardAiTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED)
                                 + 100;
      goto LABEL_18;
    }
    goto LABEL_16;
  }
  v28 = idEntity::GetPhysics(this: v26);
  v29 = (float *)v28->GetOrigin(this: v28, a2: 0);
  v30 = idEntity::GetPhysics(this);
  v31 = (float *)v30->GetOrigin(this: v30, a2: 0);
  v32 = (float)(v29[1] - v31[1]);
  v33 = (float)(v29[2] - v31[2]);
  if ( __fsqrts((float)((float)((float)v33 * (float)v33)
                      + (float)((float)((float)(*v29 - *v31) * (float)(*v29 - *v31)) + (float)((float)v32 * (float)v32)))) <= v24 )
  {
    v38 = idEntity::GetPhysics(this);
    v39 = (float *)v38->GetOrigin(this: v38, a2: 0);
    v40 = idEntity::GetPhysics(this: v27);
    v41 = (float *)v40->GetOrigin(this: v40, a2: 0);
    if ( (float)((float)(this->lastMovement.x * (float)(*v41 - *v39))
               + (float)((float)(this->lastMovement.y * (float)(v41[1] - v39[1]))
                       + (float)(this->lastMovement.z * (float)(v41[2] - v39[2])))) < 0.0 )
    {
      if ( ai == nullptr )
      {
        p_nearestForwardAi->spawnId.value = 0x1FFF;
        goto LABEL_17;
      }
      goto LABEL_16;
    }
  }
  else
  {
    v34 = idEntity::GetPhysics(this);
    v35 = (float *)v34->GetOrigin(this: v34, a2: 0);
    v36 = idEntity::GetPhysics(this: &ai->idActor);
    v37 = (float *)v36->GetOrigin(this: v36, a2: 0);
    if ( (float)((float)(this->lastMovement.x * (float)(*v37 - *v35))
               + (float)((float)(this->lastMovement.y * (float)(v37[1] - v35[1]))
                       + (float)(this->lastMovement.z * (float)(v37[2] - v35[2])))) >= 0.0 )
    {
      if ( ai == nullptr )
      {
        p_nearestForwardAi->spawnId.value = 0x1FFF;
        goto LABEL_17;
      }
LABEL_16:
      p_nearestForwardAi->spawnId.value = (gameLocal->spawnIds.ptr[ai->entityNumber] << 13) | ai->entityNumber;
      goto LABEL_17;
    }
  }
LABEL_18:
  v42 = idDrone::NearestSplinePositionFastGuess(this, goalPos: (idVec3 *)&v66.mat[1].y, returnPos: &v69);
  v43 = v42;
  if ( v42 > 100.0 )
  {
    if ( v42 < 500.0 )
      v44 = (float)((float)((float)v42 - (float)100.0) * (float)0.079999998);
    else
      v44 = 32.0;
  }
  else
  {
    v44 = 0.0;
  }
  v45 = (float)((float)v44 + (float)v42);
  idNavSplinePathMgr::GetWorldPosAlongPath(
    this: (idNavSplinePathMgr *)&v66.mat[2].z,
    result: (idVec3 *)this->splinePathMgr,
    splinePath: &this->splinePathToGoal,
    distance: v45);
  if ( g_droneStopForAI.valueInteger == 0 )
  {
    v46 = v67;
    v47 = v68;
    origin->x = v66.mat[2].z;
    origin->y = v46;
    origin->z = v47;
    idNavSplinePathMgr::GetWorldPosAlongPath(
      this: (idNavSplinePathMgr *)&v66,
      result: (idVec3 *)this->splinePathMgr,
      splinePath: &this->splinePathToGoal,
      distance: (float)((float)v45 + (float)1.0));
    v66.mat[0].x = v66.mat[0].x - v66.mat[2].z;
    v66.mat[0].y = v66.mat[0].y - v67;
    v66.mat[0].z = v66.mat[0].z - v68;
    *otherAxis = *idVec3::ToMat3(this: v70, result: &v66);
    v48 = bounds->b[0].y;
    v49 = bounds->b[0].z;
    bounds->b[0].x = bounds->b[0].x - BOUNDS_EXPAND.x;
    bounds->b[0].y = (float)v48 - BOUNDS_EXPAND.y;
    bounds->b[0].z = (float)v49 - BOUNDS_EXPAND.z;
    v50 = bounds->b[1].y;
    v51 = bounds->b[1].z;
    bounds->b[1].x = bounds->b[1].x + BOUNDS_EXPAND.x;
    bounds->b[1].y = BOUNDS_EXPAND.y + (float)v50;
    bounds->b[1].z = BOUNDS_EXPAND.z + (float)v51;
  }
  v52 = this->aheadDistance[3];
  if ( v43 < (float)(this->aheadDistance[3] * (float)0.89999998) )
  {
    v53 = (float)(v69.y - (float)z);
    v54 = (float)(v69.x - (float)y);
    v55 = __fsqrts((float)((float)((float)(v69.z - (float)x) * (float)(v69.z - (float)x))
                         + (float)((float)((float)(v69.x - (float)y) * (float)(v69.x - (float)y))
                                 + (float)((float)(v69.y - (float)z) * (float)(v69.y - (float)z)))));
    if ( v55 < 333.0 )
    {
      if ( v55 > 40.0 )
        v56 = (float)((float)((float)((float)v55 - 40.0) * (float)((float)v55 * 4.0)) * (float)0.0034129692);
      else
        v56 = 0.0;
      v57 = (float)((float)v56 + (float)v43);
      valueFloat = g_droneMinObstacleAvoidanceSpeed.valueFloat;
      if ( g_droneMinObstacleAvoidanceSpeed.valueFloat >= 0.5 )
      {
        if ( valueFloat > MAX_OBSTACLE_AVOIDANCE_SPEED )
          valueFloat = MAX_OBSTACLE_AVOIDANCE_SPEED;
      }
      else
      {
        valueFloat = 0.5;
      }
      if ( v57 > 400.0 )
      {
        if ( v57 < MAX_COLLISION_DISTANCE )
          valueFloat = (float)((float)((float)((float)(MAX_OBSTACLE_AVOIDANCE_SPEED - (float)valueFloat)
                                             * (float)((float)v57 - 400.0))
                                     / (float)(MAX_COLLISION_DISTANCE - 400.0))
                             + (float)valueFloat);
        else
          valueFloat = MAX_OBSTACLE_AVOIDANCE_SPEED;
      }
      if ( valueFloat < this->obstacleAvoidanceMaxSpeed )
        this->obstacleAvoidanceMaxSpeed = valueFloat;
      if ( v55 < 350.0 )
      {
        currentSpeed = this->currentSpeed;
        v60 = __fabs((float)((float)v43 - (float)v52));
        if ( currentSpeed > 1.0 )
          v61 = currentSpeed < 10.5
              ? (float)((float)((float)((float)(MAX_AVOID_AI_DISTANCE_BY_SPEED - MIN_AVOID_AI_DISTANCE_BY_SPEED)
                                      * (float)(this->currentSpeed - (float)1.0))
                              * (float)0.10526316)
                      + MIN_AVOID_AI_DISTANCE_BY_SPEED)
              : MAX_AVOID_AI_DISTANCE_BY_SPEED;
        else
          v61 = MIN_AVOID_AI_DISTANCE_BY_SPEED;
        if ( v60 < v61 )
        {
          v62 = (float)((float)1.0
                      - (float)__fsqrts((float)((float)((float)((float)v60 / (float)v61)
                                                      * (float)((float)v60 / (float)v61))
                                              + (float)((float)((float)v55 * (float)0.0028571428)
                                                      * (float)((float)v55 * (float)0.0028571428)))));
          if ( v62 > 0.0 )
          {
            v66.mat[1].y = v54;
            v66.mat[1].z = v53;
            v66.mat[2].x = 0.0;
            if ( idVec3::NormalizeFast(this: (idVec3 *)&v66.mat[1].y) >= 0.001 )
            {
              v63 = (float)((float)(v66.mat[1].z * (float)v62) + this->goalAvoidanceOffset.y);
              this->goalAvoidanceOffset.x = (float)(v66.mat[1].y * (float)v62) + this->goalAvoidanceOffset.x;
              this->goalAvoidanceOffset.y = v63;
            }
            this->goalAvoidanceOffset.z = (float)((float)v62 * (float)1.5) + this->goalAvoidanceOffset.z;
          }
        }
      }
    }
  }
LABEL_51:
  idPLogScope::~idPLogScope(this: &v65);
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$501521
// EA  : 0x82C2E148
// RVA : 0x00C2E148
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_501521()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 196));
}


// ========================================================================
// __unwind$501522
// EA  : 0x82C2E170
// RVA : 0x00C2E170
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_501522()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 88));
}


// ========================================================================
// ?GetPlayerAvoidanceDistance@idDrone@@QAAMPBVidPlayer@@@Z
// EA  : 0x82C2E1A0
// RVA : 0x00C2E1A0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

float __fastcall idDrone::GetPlayerAvoidanceDistance(idDrone *this, const idPlayer *player)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idPhysics *Physics; // r3
  int v7; // r3
  float v8; // r5
  idPhysics *v9; // r3
  float *v10; // r3
  double y; // fp30
  double v12; // fp10
  double x; // fp29
  double v14; // fp8
  double z; // fp28
  double v16; // fp6
  __int64 v17; // r27
  double v20; // fp12
  double v21; // fp12
  double v22; // fp31
  double v23; // fp0
  double v24; // fp13
  double v25; // fp12
  double v26; // fp1
  double v27; // fp31
  idPhysics *v28; // r3
  float v29; // r30
  float v30; // r29
  __int128 v31; // r6
  __int64 v33; // [sp+8h] [-E8h]
  __int64 v34; // [sp+8h] [-E8h]
  __int64 v35; // [sp+10h] [-E0h]
  __int64 v36; // [sp+10h] [-E0h]
  __int64 v37; // [sp+18h] [-D8h]
  __int64 v38; // [sp+18h] [-D8h]
  __int64 v39; // [sp+20h] [-D0h]
  __int64 v40; // [sp+20h] [-D0h]
  __int64 v41; // [sp+28h] [-C8h]
  __int64 v42; // [sp+28h] [-C8h]
  __int64 v43; // [sp+30h] [-C0h]
  __int64 v44; // [sp+30h] [-C0h]
  __int64 v45; // [sp+38h] [-B8h]
  __int64 v46; // [sp+38h] [-B8h]
  idPLogScope v47; // [sp+68h] [-88h] BYREF
  idVec3 v48; // [sp+70h] [-80h] BYREF
  idVec3 v49; // [sp+80h] [-70h] BYREF

  RD_EventBegin(name: "GetPlayerAvoidanceDistance");
  LODWORD(v4) = "GetPlayerAvoidanceDistance";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v47, pl: &pLog, gMask: v4, label: v5);
  Physics = idEntity::GetPhysics(this: &player->idActor);
  v7 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = *(float *)(v7 + 4);
  LODWORD(v17) = *(_DWORD *)(v7 + 8);
  v48.x = *(float *)v7;
  v48.y = v8;
  LODWORD(v48.z) = v17;
  v9 = idEntity::GetPhysics(this);
  v10 = (float *)v9->GetOrigin(this: v9, a2: 0);
  y = v48.y;
  v12 = (float)(v48.y - v10[1]);
  x = v48.x;
  v14 = (float)(v48.x - *v10);
  z = v48.z;
  v16 = (float)(v48.z - v10[2]);
  HIDWORD(v17) = &PLAYER_AWAY_FROM_SPLINE_SCALER;
  _FP2 = (float)((float)((float)((float)(v48.z - v10[2]) * (float)(v48.z - v10[2]))
                       + (float)((float)((float)(v48.x - *v10) * (float)(v48.x - *v10))
                               + (float)((float)(v48.y - v10[1]) * (float)(v48.y - v10[1]))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v20 = __frsqrte(_FP13);
  v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v14 * (float)v14) + (float)((float)v12 * (float)v12)))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20)
                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                              + (float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)v12 * (float)v12)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                                                              + (float)((float)((float)v14 * (float)v14) + (float)((float)v12 * (float)v12)))
                                                                                      * (float)0.5))
                                                                      * (float)v20)
                                                              - (float)1.5)
                                              * (float)v20))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v20
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)((float)v14 * (float)v14)
                                                                              + (float)((float)v12 * (float)v12)))
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20));
  v22 = (float)((float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)((float)v14 * (float)v14)
                                                                              + (float)((float)v12 * (float)v12)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21)
              * (float)((float)((float)v16 * (float)v16)
                      + (float)((float)((float)v14 * (float)v14) + (float)((float)v12 * (float)v12))));
  v23 = (float)((float)(v48.x - *v10)
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)((float)(v48.z - v10[2])
                                                                              * (float)(v48.z - v10[2]))
                                                                      + (float)((float)((float)(v48.x - *v10)
                                                                                      * (float)(v48.x - *v10))
                                                                              + (float)((float)(v48.y - v10[1])
                                                                                      * (float)(v48.y - v10[1]))))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v24 = (float)((float)v12
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)((float)(v48.z - v10[2])
                                                                              * (float)(v48.z - v10[2]))
                                                                      + (float)((float)((float)(v48.x - *v10)
                                                                                      * (float)(v48.x - *v10))
                                                                              + (float)((float)v12 * (float)v12)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v25 = (float)((float)(v48.z - v10[2])
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)((float)(v48.z - v10[2])
                                                                              * (float)(v48.z - v10[2]))
                                                                      + (float)((float)((float)(v48.x - *v10)
                                                                                      * (float)(v48.x - *v10))
                                                                              + (float)((float)(v48.y - v10[1])
                                                                                      * (float)(v48.y - v10[1]))))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  if ( v22 >= 3000.0 )
    goto LABEL_2;
  if ( (float)((float)(this->toAhead[0].x * (float)v23)
             + (float)((float)(this->toAhead[0].z * (float)v25) + (float)(this->toAhead[0].y * (float)v24))) >= 0.0 )
  {
    if ( v22 > 100.0 )
    {
      v27 = idDrone::NearestSplinePositionFastGuess(this, goalPos: &v48, returnPos: &v49);
      if ( g_droneDebugPlayerCollisions.valueInteger != 0 )
      {
        v28 = idEntity::GetPhysics(this);
        HIDWORD(v31) = v28->GetOrigin(this: v28, a2: 0);
        v29 = v49.y;
        v30 = v49.z;
        *(_QWORD *)((char *)&v31 + 4) = *(_QWORD *)HIDWORD(v31);
        LODWORD(v31) = __ROL4__(*(_DWORD *)(HIDWORD(v31) + 8), 32);
        idDrone::DebugArrow(
          start: *(_QWORD *)(*(_DWORD *)HIDWORD(v31) + offsetof(idColor, b)),
          lifetime: v31,
          size: 5.0,
          depthTest: __SPAIR64__(LODWORD(v49.y), __ROL4__(LODWORD(v49.z), 32)),
          a5: (int)&aAvSsobjectVCom[20],
          a6: 5,
          a7: v33,
          a8: v35,
          a9: v37,
          a10: v39,
          a11: v41,
          a12: v43,
          a13: v45);
        idDrone::DebugArrow(
          start: *(__int64 *)&idColor::colorRed.b,
          lifetime: __SPAIR64__(LODWORD(v29), __ROL4__(LODWORD(v30), 32)),
          size: 5.0,
          depthTest: v17 << 32,
          a5: (int)&aAvSsobjectVCom[20],
          a6: 5,
          a7: v34,
          a8: v36,
          a9: v38,
          a10: v40,
          a11: v42,
          a12: v44,
          a13: v46);
      }
      v22 = (float)((float)((float)__fsqrts((float)((float)((float)(v49.z - (float)z) * (float)(v49.z - (float)z))
                                                  + (float)((float)((float)(v49.x - (float)x) * (float)(v49.x - (float)x))
                                                          + (float)((float)(v49.y - (float)y) * (float)(v49.y - (float)y)))))
                          * 10.0)
                  + (float)v27);
      idPLogScope::~idPLogScope(this: &v47);
      goto LABEL_9;
    }
LABEL_2:
    idPLogScope::~idPLogScope(this: &v47);
LABEL_9:
    RD_EventEnd();
    v26 = v22;
    return *((float *)&v26 + 1);
  }
  idPLogScope::~idPLogScope(this: &v47);
  RD_EventEnd();
  v26 = 3000.0;
  return *((float *)&v26 + 1);
}


// ========================================================================
// __unwind$502079
// EA  : 0x82C2E458
// RVA : 0x00C2E458
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_502079()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 140));
}


// ========================================================================
// __unwind$502080
// EA  : 0x82C2E480
// RVA : 0x00C2E480
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_502080()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 104));
}


// ========================================================================
// ?StateThinkForScanning@idDrone@@QAA_NXZ
// EA  : 0x82C2E4A8
// RVA : 0x00C2E4A8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

int __fastcall idDrone::StateThinkForScanning(idDrone *this)
{
  int value; // r10
  idEntityPtr<idEntity> *p_currentScanEntity; // r28
  idEntity *v4; // r3
  idEntity *v6; // r3
  idEntity *v7; // r3
  idPhysics *Physics; // r3
  const idVec3 *v9; // r3
  float x; // r6
  int v11; // r11
  int y_low; // r5
  float z; // r3
  int v14; // r8
  idEntity *v15; // r3
  idAI2 *v16; // r3
  void *v17; // r3
  idPlayer *v18; // r3
  idPhysics *v19; // r3
  __int128 v20; // r6
  float v21; // r9
  float v22; // r5
  float v23; // r3
  int v24; // r11
  double v25; // fp31
  double v28; // fp5
  double v29; // fp8
  double v30; // fp5
  double v31; // fp29
  double v32; // fp28
  double v33; // fp27
  double v34; // fp0
  double v35; // fp12
  double v36; // fp0
  double v37; // fp11
  idPlayer *v38; // r3
  int currentBehaviorPoint; // r11
  idDrone::behaviorPoint_t *v40; // r27
  double endScanDesiredSpeedMultiplier; // fp0
  idDrone *v42; // r4
  idEventArg *v43; // r3
  char *v44; // r10
  _DWORD *v45; // r11
  int i; // ctr
  idEntity *v47; // r3
  int GameMs; // r3
  encounterGroupRole_t exitScanState; // r10
  idDrone::droneState_t val; // r11
  char v51; // r11
  bool v52; // zf
  __int64 v53; // [sp+8h] [-108h]
  __int64 v54; // [sp+10h] [-100h]
  __int64 v55; // [sp+18h] [-F8h]
  __int64 v56; // [sp+20h] [-F0h]
  __int64 v57; // [sp+28h] [-E8h]
  __int64 v58; // [sp+30h] [-E0h]
  __int64 v59; // [sp+38h] [-D8h]
  encounterGroupRole_t v60[4]; // [sp+60h] [-B0h] BYREF
  idEventArg v61; // [sp+70h] [-A0h] BYREF
  char v62; // [sp+8Ch] [-84h] BYREF
  float v63; // [sp+90h] [-80h]
  float y; // [sp+94h] [-7Ch]
  __int64 v65; // [sp+98h] [-78h]

  value = this->currentScanEntity.spawnId.value;
  p_currentScanEntity = &this->currentScanEntity;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v4 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v4) == nullptr )
  {
    if ( this->currentState.val == DS_SCANNING )
    {
      idDrone::SetStateSetMoveState(this, newState: 4, newMoveState: DMS_FAST);
      return 1;
    }
    return 1;
  }
  if ( g_droneDebugFocusEntities.valueInteger != 0 )
  {
    if ( gameLocal->spawnIds.ptr[p_currentScanEntity->spawnId.value & 0x1FFF] == p_currentScanEntity->spawnId.value >> 13
      && (v6 = gameLocal->entities.ptr[p_currentScanEntity->spawnId.value & 0x1FFF]) != nullptr )
    {
      v7 = idEntity::CastTo(c: v6);
    }
    else
    {
      v7 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: v7);
    v9 = Physics->GetOrigin(this: Physics, a2: 0);
    x = v9->x;
    v11 = p_currentScanEntity->spawnId.value & 0x1FFF;
    y_low = LODWORD(v9->y);
    z = v9->z;
    v14 = p_currentScanEntity->spawnId.value >> 13;
    *(float *)&v61.type = x;
    v61.value.i = y_low;
    v61.value.v[1] = z;
    if ( gameLocal->spawnIds.ptr[v11] == v14 && (v15 = gameLocal->entities.ptr[v11]) != nullptr )
      v16 = (idAI2 *)idEntity::CastTo(c: v15);
    else
      v16 = nullptr;
    v17 = idAI2::CastTo(c: v16);
    if ( v17 != nullptr
      || (v18 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: p_currentScanEntity),
          (v17 = idPlayer::CastTo(c: v18)) != nullptr) )
    {
      (*(void (__fastcall **)(void *, int, idEventArg *))(*(_DWORD *)v17 + 532))(a1: v17, a2: 1, a3: &v61);
    }
    v19 = idEntity::GetPhysics(this);
    *(_QWORD *)((char *)&v20 + 4) = *(_QWORD *)&v19->GetOrigin(this: v19, a2: 0)->x;
    LODWORD(v20) = __ROL4__(*(_DWORD *)&v61.type, 32);
    idDrone::DebugArrow(
      start: *(__int64 *)&idColor::colorWhite.b,
      lifetime: v20,
      size: 4.0,
      depthTest: __SPAIR64__(v61.value.h, __ROL4__(LODWORD(v61.value.v[1]), 32)),
      a5: (int)&idColor::colorWhite,
      a6: 1,
      a7: v53,
      a8: v54,
      a9: v55,
      a10: v56,
      a11: v57,
      a12: v58,
      a13: v59);
  }
  v21 = this->currentFacing.x;
  v22 = this->currentFacing.z;
  v23 = this->desiredFacing.x;
  y = this->currentFacing.y;
  v63 = v21;
  v24 = LODWORD(this->desiredFacing.y);
  v25 = 0.0;
  *(float *)&v65 = v22;
  v61.value.v[1] = 0.0;
  *(float *)&v61.type = v23;
  v61.value.i = v24;
  _FP8 = (float)((float)((float)(y * y) + (float)(v21 * v21)) - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f6, f8, f9, f13 }
  v28 = __frsqrte(_FP6);
  v29 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28
                                                                                      * (float)((float)((float)(y * y) + (float)(v21 * v21))
                                                                                              * (float)0.5))
                                                                              * (float)v28)
                                                                      - (float)1.5)
                                                      * (float)v28)
                                              * (float)((float)((float)(y * y) + (float)(v21 * v21)) * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v28
                                                                              * (float)((float)((float)(y * y)
                                                                                              + (float)(v21 * v21))
                                                                                      * (float)0.5))
                                                                      * (float)v28)
                                                              - (float)1.5)
                                              * (float)v28))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v28
                                                      * (float)((float)((float)(y * y) + (float)(v21 * v21)) * (float)0.5))
                                              * (float)v28)
                                      - (float)1.5)
                      * (float)v28));
  v30 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)(y * y) + (float)(v21 * v21)) * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                              * (float)v28)
                                                                                      * (float)((float)((float)(y * y) + (float)(v21 * v21))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)(y * y) + (float)(v21 * v21)) * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                      * (float)v28))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v28
                                                                                              * (float)((float)((float)(y * y) + (float)(v21 * v21)) * (float)0.5))
                                                                                      * (float)v28)
                                                                              - (float)1.5)
                                                              * (float)v28))
                                              * (float)((float)((float)(y * y) + (float)(v21 * v21)) * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)(y * y) + (float)(v21 * v21)) * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                      * (float)v28)
                                                                              * (float)((float)((float)(y * y)
                                                                                              + (float)(v21 * v21))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)(y * y) + (float)(v21 * v21)) * (float)0.5)) * (float)v28)
                                                                                              - (float)1.5)
                                                                              * (float)v28))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v28
                                                                                      * (float)((float)((float)(y * y) + (float)(v21 * v21))
                                                                                              * (float)0.5))
                                                                              * (float)v28)
                                                                      - (float)1.5)
                                                      * (float)v28)))
                              - (float)1.5)
              * (float)v29);
  v31 = (float)(v21 * (float)v30);
  v32 = (float)(y * (float)v30);
  v33 = (float)((float)v30 * (float)0.0);
  if ( (float)((float)v30 * (float)((float)(y * y) + (float)(v21 * v21))) < 0.001
    || idVec3::NormalizeFast(this: (idVec3 *)&v61) < 0.001 )
  {
    this->currentScanEntityCuriosity = this->currentScanEntityCuriosity - (float)0.0099999998;
    return 1;
  }
  v34 = (float)((float)(v61.value.v[1] * (float)v33)
              + (float)((float)(v61.value.f * (float)v32) + (float)(*(float *)&v61.type * (float)v31)));
  if ( v34 <= 0.89999998 )
    return 1;
  v35 = 2.0;
  if ( this->currentSpeed >= 2.0 )
    return 1;
  v36 = v34 < 1.0
      ? (float)((float)((float)((float)(v61.value.v[1] * (float)v33)
                              + (float)((float)(v61.value.f * (float)v32) + (float)(*(float *)&v61.type * (float)v31)))
                      - (float)0.89999998)
              * (float)0.099999972)
      : 0.0099999998;
  v37 = (float)(this->currentScanEntityCuriosity - (float)v36);
  this->currentScanEntityCuriosity = this->currentScanEntityCuriosity - (float)v36;
  if ( v37 > 0.0 )
    return 1;
  if ( this->scanPlayerSound != nullptr )
  {
    v38 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: p_currentScanEntity);
    if ( idPlayer::CastTo(c: v38) != nullptr )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_WEAPON3,
        shader: this->scanPlayerSound,
        soundShaderFlags: 0,
        peerMask: 0xFFu);
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WEAPON3, volume: 0.0);
    }
    v25 = 0.0;
    v35 = 2.0;
  }
  currentBehaviorPoint = this->currentBehaviorPoint;
  if ( currentBehaviorPoint < 0 || currentBehaviorPoint >= this->behaviorPoints.num )
  {
    val = this->lastNonScanState.val;
    if ( val < DS_WAITING || (v52 = val < DS_NUM_DRONE_STATES, v51 = 1, !v52) )
      v51 = 0;
    if ( v51 == 0 || this->lastNonScanState.val == DS_SCANNING )
      this->lastNonScanState.val = DS_MOVING;
    idDrone::SetState(this, newState: this->lastNonScanState.val);
    return 1;
  }
  else
  {
    v40 = &this->behaviorPoints.list[currentBehaviorPoint];
    endScanDesiredSpeedMultiplier = v40->endScanDesiredSpeedMultiplier;
    if ( endScanDesiredSpeedMultiplier > v25 )
    {
      this->desiredSpeedMultiplier = v40->endScanDesiredSpeedMultiplier;
      if ( endScanDesiredSpeedMultiplier >= 0.25 )
      {
        if ( endScanDesiredSpeedMultiplier > v35 )
          this->desiredSpeedMultiplier = v35;
      }
      else
      {
        this->desiredSpeedMultiplier = 0.25;
      }
    }
    if ( idEntityPtr<idEntity const>::operator->(this: &v40->endScanTrigger) != nullptr )
    {
      v42 = (idDrone *)idEntityPtr<idEntity const>::operator->(this: &v40->entityToScan);
      if ( v42 == nullptr )
        v42 = this;
      v43 = idEventArg::idEventArg(this: &v61, data: v42);
      v44 = &v62;
      v45 = (_DWORD *)&v43[-1].value.q[3];
      for ( i = 5; i != 0; --i )
      {
        ++v45;
        v44 += 4;
        *(_DWORD *)v44 = *v45;
      }
      v47 = idEntityPtr<idEntity const>::operator->(this: &v40->endScanTrigger);
      idEventReceiver::PostEventMS(this: v47, ev: &EV_Activate, time: 0, arg1: (const idEventArg *)HIDWORD(v65));
    }
    if ( idEntityPtr<idSplineWaypoint>::GetEntity(this: &v40->endScanWaypoint) != nullptr )
    {
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->goals);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->goalSearchDirections);
      v60[0] = (encounterGroupRole_t)idEntityPtr<idSplineWaypoint>::GetEntity(this: &v40->endScanWaypoint);
      idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->goals, obj: v60);
      *(float *)v60 = 1.0;
      idList<float,13>::Append(this: (idList<float,13> *)&this->goalSearchDirections, obj: (float *)v60);
      this->searchNextUpdateTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED)
                                 + 500;
      this->splinePathToGoal.distance = 999.0;
    }
    ++v40->numScansDone;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    exitScanState = v40->exitScanState;
    v40->nextScanTime = GameMs + 5000;
    v60[0] = exitScanState;
    idDrone::SetState(this, newState: exitScanState);
    this->currentBehaviorPoint = -1;
    return 1;
  }
}


// ========================================================================
// ?Damage@idDrone@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C2EA68
// RVA : 0x00C2EA68
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

float __fastcall idDrone::Damage(
        idDrone *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDecl,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        float *a8)
{
  double v11; // fp1
  double v12; // fp28
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp7
  double v16; // fp6
  double v17; // fp9
  double v18; // fp8
  double y; // fp6
  double z; // fp5
  int GameMs; // r3
  double engineSmokeAmount; // fp13
  int nextSputterTime; // r9
  int v24; // r30
  idPhysics *v25; // r3
  float *v26; // r3
  double v27; // fp12
  __int64 v28; // r5
  long double v29; // fp2
  double v30; // fp8
  double HealthPercent; // fp31
  int v32; // r25
  int v33; // r28
  int numActivates; // r11
  idDrone::damageBehavior_t *v35; // r30
  idEntity *v36; // r3
  int entityNumber; // r11
  idEntityPtr<idEntity> *p_trigger; // r30
  idEventArg *v39; // r3
  char *v40; // r10
  _DWORD *v41; // r11
  int i; // ctr
  idEntity *v43; // r3
  double v44; // fp30
  double v45; // fp31
  double v46; // fp1
  double v47; // fp13
  double x; // fp0
  double v49; // fp1
  double v50; // fp13
  double v51; // fp1
  double v52; // fp13
  double v53; // fp0
  double v54; // fp1
  double v55; // fp13
  double v56; // fp1
  double v57; // fp1
  double v58; // fp13
  double v59; // fp0
  double v60; // fp1
  double v61; // fp13
  double v62; // fp0
  char v63; // r11
  double v64; // fp8
  void (__fastcall *SetLinearVelocity)(struct idPhysics_RigidBody *, const idVec3 *, int); // ctr
  double v66; // fp3
  idEventArg v68; // [sp+60h] [-E0h] BYREF
  float v69; // [sp+78h] [-C8h] BYREF
  float v70; // [sp+7Ch] [-C4h]
  float v71; // [sp+80h] [-C0h]
  char v72; // [sp+8Ch] [-B4h] BYREF
  __int64 v73; // [sp+98h] [-A8h]

  if ( damageDecl == nullptr )
  {
    v11 = 0.0;
    return *((float *)&v11 + 1);
  }
  v12 = (float)(idDeclDamage::DamageAmount(this: damageDecl) * (float)damageScale);
  if ( this->health <= 0.0 )
  {
    if ( a8 != nullptr )
    {
      Physics = idEntity::GetPhysics(this: attacker);
      v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v15 = (float)(a8[15] - v14[1]);
      v16 = (float)(a8[16] - v14[2]);
      *(float *)&v68.type = a8[14] - *v14;
      v68.value.f = v15;
      v68.value.v[1] = v16;
      if ( idVec3::NormalizeFast(this: (idVec3 *)&v68) >= 0.0099999998 )
      {
        v17 = (float)(v68.value.f * 0.333);
        v18 = (float)(v68.value.v[1] * 0.333);
        y = this->recentForceApplied.y;
        z = this->recentForceApplied.z;
        this->recentForceApplied.x = this->recentForceApplied.x + (float)(*(float *)&v68.type * 0.333);
        this->recentForceApplied.y = (float)y + (float)v17;
        this->recentForceApplied.z = (float)z + (float)v18;
      }
    }
    goto LABEL_59;
  }
  if ( g_droneAllowWeaponsDeployWhenHit.valueInteger != 0 )
    idDrone::DeployAndStowWeapon(this, gunId: 0, armDelay: 500, disarmDelay: 10000);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  engineSmokeAmount = this->engineSmokeAmount;
  nextSputterTime = this->nextSputterTime;
  this->nextEngineSmokeTime = GameMs;
  this->engineSmokeAmount = (float)((float)((float)1.0 - (float)engineSmokeAmount) * (float)0.333)
                          + (float)engineSmokeAmount;
  if ( nextSputterTime == 0
    || this->nextSputterTime > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                             + 1000 )
  {
    v24 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v68.value.i = (int)(float)(idDrone::GetHealthPercent(this) * 1500.0);
    this->nextSputterTime = RandomInt(max: v68.value.i) + v24;
  }
  if ( attacker != nullptr && a8 != nullptr )
  {
    v25 = idEntity::GetPhysics(this: attacker);
    v26 = (float *)v25->GetOrigin(this: v25, a2: 0);
    v27 = a8[16];
    v28 = *((_QWORD *)a8 + 7);
    *((double *)&v29 + 1) = 1.0;
    v30 = (float)(a8[15] - v26[1]);
    *(float *)&v68.type = a8[14] - *v26;
    v68.value.f = v30;
    *(double *)&v29 = 1.0;
    v68.value.v[1] = (float)v27 - v26[2];
    idDrone::Bump(
      a1: (idVec3 *)&v68,
      a2: SHIDWORD(v28),
      a3: v28,
      a4: *(int *)&v68.type,
      rotationalForce: v29,
      reduceZScaler: 0.5,
      a7: v68.value.i);
  }
  if ( g_droneDebugNoDamage.valueInteger != 0 )
    goto LABEL_59;
  this->health = this->health - (float)v12;
  HealthPercent = idDrone::GetHealthPercent(this);
  v32 = 0;
  if ( this->damageBehaviors.num > 0 )
  {
    v33 = 0;
    while ( 1 )
    {
      numActivates = this->numActivates;
      v35 = &this->damageBehaviors.list[v33];
      if ( numActivates >= v35->minTriggerCount
        && numActivates <= v35->maxTriggerCount
        && HealthPercent < v35->healthPercent
        && !v35->hasBehaviorTriggered )
      {
        break;
      }
LABEL_37:
      ++v32;
      ++v33;
      if ( v32 >= this->damageBehaviors.num )
        goto LABEL_38;
    }
    v35->hasBehaviorTriggered = true;
    if ( HealthPercent <= 0.0 )
    {
LABEL_33:
      p_trigger = &v35->trigger;
      if ( idEntityPtr<idEntity const>::operator->(this: p_trigger) != nullptr )
      {
        v39 = idEventArg::idEventArg(this: &v68, data: this);
        v40 = &v72;
        v41 = (_DWORD *)&v39[-1].value.q[3];
        for ( i = 5; i != 0; --i )
        {
          ++v41;
          v40 += 4;
          *(_DWORD *)v40 = *v41;
        }
        v43 = idEntityPtr<idEntity const>::operator->(this: p_trigger);
        idEventReceiver::PostEventMS(this: v43, ev: &EV_Activate, time: 0, arg1: (const idEventArg *)HIDWORD(v73));
      }
      goto LABEL_37;
    }
    if ( v35->scanAttackerFlag )
    {
      v36 = attacker;
    }
    else
    {
      if ( idEntityPtr<idEntity const>::operator->(this: &v35->scanEntity) == nullptr )
      {
LABEL_29:
        if ( v35->forcedCuriosity > 0.0 )
          this->currentScanEntityCuriosity = v35->forcedCuriosity * 2.0;
        if ( v35->desiredSpeedMultiplier > 0.0 )
          this->desiredSpeedMultiplier = v35->desiredSpeedMultiplier;
        goto LABEL_33;
      }
      v36 = idEntityPtr<idEntity const>::operator->(this: &v35->scanEntity);
    }
    if ( v36 != nullptr )
    {
      entityNumber = v36->entityNumber;
      *(_DWORD *)&v68.type = 3;
      this->currentScanEntity.spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
      idDrone::SetState(this, newState: 3);
    }
    goto LABEL_29;
  }
LABEL_38:
  if ( this->health <= 0.0 )
  {
    idDrone::KillDrone(this);
    goto LABEL_59;
  }
  if ( v12 <= 0.0 || this->startingHealth <= 0.0 )
    goto LABEL_59;
  v44 = (float)((float)v12 / this->startingHealth);
  v45 = (float)((float)((float)v12 / this->startingHealth) * 0.5);
  if ( v45 <= 0.0 )
    goto LABEL_53;
  if ( this->bobGoal.x < 0.0 )
  {
    v49 = RandomFloat(max: v45);
    v50 = (float)(this->bobGoal.x - (float)v49);
    this->bobGoal.x = this->bobGoal.x - (float)v49;
    x = -MAX_BOB.x;
    if ( v50 < x )
LABEL_47:
      this->bobGoal.x = x;
  }
  else
  {
    v46 = RandomFloat(max: v45);
    v47 = (float)((float)v46 + this->bobGoal.x);
    this->bobGoal.x = (float)v46 + this->bobGoal.x;
    x = MAX_BOB.x;
    if ( v47 > MAX_BOB.x )
      goto LABEL_47;
  }
  if ( this->bobGoal.y < 0.0 )
  {
    v54 = RandomFloat(max: v45);
    v55 = (float)(this->bobGoal.y - (float)v54);
    this->bobGoal.y = this->bobGoal.y - (float)v54;
    v53 = -MAX_BOB.y;
    if ( v55 >= v53 )
      goto LABEL_53;
  }
  else
  {
    v51 = RandomFloat(max: v45);
    v52 = (float)((float)v51 + this->bobGoal.y);
    this->bobGoal.y = (float)v51 + this->bobGoal.y;
    v53 = MAX_BOB.y;
    if ( v52 <= MAX_BOB.y )
      goto LABEL_53;
  }
  this->bobGoal.y = v53;
LABEL_53:
  v56 = (float)((float)v44 * (float)1.5);
  if ( v56 > 0.0 )
  {
    if ( this->bobGoal.z < 0.0 )
    {
      v60 = RandomFloat(max: v56);
      v61 = (float)(this->bobGoal.z - (float)v60);
      this->bobGoal.z = this->bobGoal.z - (float)v60;
      v59 = -MAX_BOB.z;
      if ( v61 >= v59 )
        goto LABEL_59;
    }
    else
    {
      v57 = RandomFloat(max: v56);
      v58 = (float)((float)v57 + this->bobGoal.z);
      this->bobGoal.z = (float)v57 + this->bobGoal.z;
      v59 = MAX_BOB.z;
      if ( v58 <= MAX_BOB.z )
        goto LABEL_59;
    }
    this->bobGoal.z = v59;
  }
LABEL_59:
  if ( this->health <= 0.0 )
  {
    v62 = vec3_origin.x;
    if ( this->recentForceApplied.x != vec3_origin.x
      || this->recentForceApplied.y != vec3_origin.y
      || (v63 = 1, this->recentForceApplied.z != vec3_origin.z) )
    {
      v63 = 0;
    }
    if ( v63 == 0 )
    {
      if ( this->rigidPhysics.callbacks != nullptr )
      {
        this->rigidPhysics.GetLinearVelocity(
          this: (struct idPhysics_RigidBody *)&v69,
          result: (idVec3 *)&this->rigidPhysics,
          a3: 0);
        v64 = (float)(this->recentForceApplied.z * 25.0);
        SetLinearVelocity = this->rigidPhysics.SetLinearVelocity;
        v66 = (float)(v70 + (float)(this->recentForceApplied.y * 25.0));
        v69 = (float)(this->recentForceApplied.x * 25.0) + v69;
        v70 = v66;
        v71 = v71 + (float)v64;
        SetLinearVelocity(this: &this->rigidPhysics, a2: (const idVec3 *)&v69, a3: 0);
        v62 = vec3_origin.x;
      }
      this->recentForceApplied.x = v62;
      this->recentForceApplied.y = vec3_origin.y;
      this->recentForceApplied.z = vec3_origin.z;
    }
  }
  v11 = v12;
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?StateThink@idDrone@@QAA_NXZ
// EA  : 0x82C2F0F8
// RVA : 0x00C2F0F8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

int __fastcall idDrone::StateThink(idDrone *this)
{
  idDrone::droneState_t val; // r10
  double v2; // fp12
  double v3; // fp0
  double v4; // fp13

  val = this->currentState.val;
  if ( val == DS_SCANNING )
  {
    v2 = (float)(this->currentScanEntityEffectOn + (float)0.029999999);
    v3 = 1.0;
    this->currentScanEntityEffectOn = this->currentScanEntityEffectOn + (float)0.029999999;
    if ( v2 <= 1.0 )
      goto LABEL_7;
    goto LABEL_6;
  }
  v3 = 0.0;
  if ( this->currentScanEntityEffectOn != 0.0 )
  {
    v4 = (float)(this->currentScanEntityEffectOn - (float)0.0049999999);
    this->currentScanEntityEffectOn = this->currentScanEntityEffectOn - (float)0.0049999999;
    if ( v4 <= 0.0 )
LABEL_6:
      this->currentScanEntityEffectOn = v3;
  }
LABEL_7:
  if ( (unsigned int)val > DS_RETREATING )
  {
    this->currentState.val = DS_WAITING;
  }
  else if ( val == DS_SCANNING )
  {
    return idDrone::StateThinkForScanning(this);
  }
  return 1;
}


// ========================================================================
// ?Think@idDrone@@UAAXXZ
// EA  : 0x82C2F1A0
// RVA : 0x00C2F1A0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDrone::Think(idDrone *this)
{
  double v1; // fp27
  double v2; // fp26
  bool v4; // r29
  char *v5; // r19
  double v6; // fp17
  bool v7; // r11
  const float *v8; // r20
  double v9; // fp12
  double v10; // fp2
  soundChannel_t v11; // r29
  int v12; // r27
  int v13; // r28
  int v14; // r27
  int v15; // r28
  int v16; // r26
  int v17; // r27
  double afterburnerThrustLevel; // fp31
  idDrone::blendedSounds_t *v19; // r28
  double minThrustVolume; // fp0
  int valueInteger; // r4
  idDrone::droneMoveState_t v22; // r5
  idDrone::droneMoveState_t val; // r11
  double v24; // fp9
  double v25; // fp8
  int v26; // r27
  float *weaponArmSpeed; // r26
  __int64 v28; // r4
  double v29; // fp6
  idDrone::droneMoveState_t v30; // r23
  idDrone::droneMoveState_t v31; // r21
  double v32; // fp5
  idDrone::droneMoveState_t v33; // r17
  float v34; // r16
  double v35; // fp4
  unsigned __int64 v36; // r15
  double v37; // fp1
  double v38; // fp0
  double v39; // fp9
  double v40; // fp13
  double v41; // fp8
  double v42; // fp12
  double v43; // fp2
  double v44; // fp11
  double v45; // fp7
  double v46; // fp3
  double v47; // fp10
  double v48; // fp9
  double v49; // fp31
  double v50; // fp11
  double v51; // fp30
  double v52; // fp2
  double v53; // fp8
  double v54; // fp7
  double v55; // fp6
  double v56; // fp5
  double v57; // fp24
  _DWORD *v58; // r29
  double v59; // fp0
  char v60; // r10
  char v61; // r11
  idPropsCollection *v62; // r11
  idPropsCollection *v63; // r3
  float g; // r27
  int resetSpeedOverrideCounter; // r11
  int v66; // r11
  idDrone::behaviorPoint_t *v67; // r29
  idEntity *v68; // r3
  idPlayerStart *v69; // r3
  idPlayer *Player; // r28
  int numActivates; // r11
  idPhysics *Physics; // r3
  float *v73; // r21
  idPhysics *v74; // r3
  float *v75; // r3
  double v76; // fp9
  double v77; // fp5
  double slowDistance; // fp0
  double v79; // fp13
  double v80; // fp0
  double v81; // fp0
  int maxNumScans; // r11
  double scanChance; // fp0
  bool v84; // r10
  char v85; // r11
  idDrone::droneState_t exitScanState; // r11
  double desiredSpeedMultiplier; // fp0
  double v88; // fp13
  idDrone *v89; // r4
  idEventArg *v90; // r3
  int *v91; // r10
  _DWORD *v92; // r11
  int i; // ctr
  idEntity *v94; // r3
  idDrone *v95; // r4
  idEventArg *v96; // r3
  int *v97; // r10
  _DWORD *v98; // r11
  int j; // ctr
  idEntity *v100; // r3
  int nextBehaviorPointToTest; // r11
  int v102; // r11
  int v103; // r11
  double v104; // fp16
  int nextAfterburnerSmokeTime; // r11
  int GameMs; // r3
  char v107; // r10
  double engineSmokeAmount; // fp13
  char value_high; // r23
  double v110; // fp12
  double v111; // fp0
  int v112; // r3
  int nextEngineSmokeTime; // r11
  char v114; // r29
  int v115; // r3
  unsigned __int8 v116; // r11
  idPhysics *v117; // r3
  int v118; // r3
  int *v119; // r10
  _DWORD *v120; // r11
  int k; // ctr
  double v122; // fp31
  double v123; // fp1
  double v126; // fp5
  double v127; // fp8
  double v128; // fp5
  double v129; // fp4
  double v130; // fp26
  double v131; // fp30
  double v132; // fp31
  double v133; // fp29
  double v134; // fp1
  double v135; // fp10
  double v138; // fp3
  double v139; // fp4
  double v140; // fp3
  double v141; // fp29
  double v142; // fp28
  double v143; // fp27
  double z; // fp25
  double y; // fp24
  double x; // fp23
  double v147; // fp22
  double v148; // fp21
  double v149; // fp20
  double v150; // fp19
  double v151; // fp18
  double v152; // fp31
  double v153; // fp10
  double v154; // fp9
  double v155; // fp30
  double v156; // fp15
  double v157; // fp26
  double v158; // fp14
  long double v159; // fp2
  long double v160; // fp2
  long double v161; // fp2
  double v162; // fp4
  double v163; // fp0
  double v164; // fp5
  double v165; // fp6
  double v166; // fp13
  double v167; // fp23
  double v168; // fp11
  double v169; // fp27
  double v170; // fp30
  double v171; // fp29
  double v172; // fp31
  double v173; // fp12
  double v174; // fp10
  double v175; // fp9
  double v176; // fp11
  double v177; // fp28
  double v178; // fp1
  double v179; // fp3
  double v180; // fp2
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const idDeclMD6 *decl; // r11
  double v183; // fp12
  int v184; // r17
  int v185; // r29
  int v186; // r29
  __int64 v187; // r9
  int v188; // r16
  int v189; // r24
  double v190; // fp30
  const idDeclParticle **sputterParticle; // r21
  double v192; // fp31
  double v193; // fp0
  double v194; // fp12
  unsigned __int8 v195; // r29
  bool v196; // r28
  bool v197; // r26
  int v198; // r3
  _BYTE *v199; // r29
  const float *v200; // r29
  double v201; // fp11
  __int64 v202; // r11
  double v203; // fp8
  double v204; // fp6
  double v205; // fp3
  double v206; // fp5
  double v207; // fp4
  double v208; // fp2
  double v209; // fp1
  double v210; // fp31
  double v211; // fp23
  const idDeclParticle *v212; // r29
  int v213; // r3
  double v214; // fp2
  double v215; // fp31
  double v216; // fp23
  double v217; // fp1
  double v218; // fp31
  int v219; // r11
  char *v220; // r14
  int GameMsPerFrame; // r3
  int v222; // r11
  int v223; // r14
  int v224; // r28
  double v225; // fp31
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v227; // r7
  double v228; // fp0
  double v229; // fp2
  double v230; // fp1
  idGameTimeManager *v231; // r3
  float v232; // r29
  int v233; // r3
  idDrone::droneDeath_t deathVarietyDesired; // r11
  float *v235; // r3
  double v236; // fp0
  double v237; // fp12
  double v238; // fp7
  double v239; // fp6
  double v240; // fp4
  idVec3 *(__fastcall *GetLinearVelocity)(struct idPhysics_RigidBody *, idVec3 *, int); // r6
  double v242; // fp3
  double v243; // fp31
  double v244; // fp30
  double v245; // fp29
  float *v246; // r3
  void (__fastcall *SetLinearVelocity)(struct idPhysics_RigidBody *, const idVec3 *, int); // r9
  double v248; // fp5
  double v249; // fp3
  idPhysics_RigidBody_vtbl *v250; // r6
  int patrolWaypointOn; // r11
  idDroneSplineWaypoint ***p_goals; // r21
  idPhysics *v253; // r3
  float *v254; // r3
  double v255; // fp9
  double v256; // fp7
  float a; // r28
  double v258; // fp5
  double v259; // fp0
  int num; // r11
  int v261; // r11
  bool v262; // zf
  int v263; // r10
  idDroneSplineWaypoint **v264; // r9
  int v265; // r11
  int v266; // r11
  int v267; // r10
  float *v268; // r9
  idDroneSplineWaypoint *v269; // r29
  idPhysics *v270; // r3
  int v271; // r3
  float v272; // r25
  float v273; // r24
  float v274; // r3
  double v275; // fp1
  int v276; // r11
  int v277; // r3
  int v278; // r3
  int v279; // r11
  int v280; // r8
  int v281; // r6
  int v282; // ctr
  int v283; // r11
  int v284; // r11
  int v285; // r10
  _DWORD *v286; // r9
  int v287; // r11
  int v288; // r11
  int v289; // r10
  float *v290; // r9
  navSplinePath_t *ShortestPathByList; // r3
  idDrone::dronePathType_t currentPathType; // r9
  float v293; // r26
  int v294; // r25
  char *v295; // r24
  idColor *v296; // r22
  int v297; // r29
  idEntity *v298; // r3
  idPhysics *v299; // r3
  const idVec3 *v300; // r3
  idColor *v301; // r10
  idColor *v302; // r7
  idVec3 *v303; // r6
  float v304; // r19
  idNavSplinePosition *v305; // r5
  float v306; // r18
  idColor *v307; // r4
  float v308; // r3
  idPhysics *v309; // r3
  int v310; // r3
  float v311; // r26
  float v312; // r18
  float b; // r19
  float v314; // r3
  int v315; // r11
  idPhysics *v316; // r3
  float *v317; // r3
  int v318; // r9
  double v319; // fp13
  double v320; // fp12
  double distance; // fp13
  double v322; // fp18
  char *v323; // r16
  int v324; // r9
  idDrone::dronePathType_t v325; // r10
  float *v326; // r8
  double v327; // fp29
  idDroneSplineWaypoint *v328; // r3
  float v329; // r11
  char v330; // r23
  idEntity *v331; // r25
  double v332; // fp30
  int lastVisitTime; // r24
  int v334; // r29
  int v335; // r26
  bool v336; // r10
  int v337; // r9
  int v338; // r9
  idEntity *v339; // r3
  idDroneSplineWaypoint *v340; // r3
  idDroneSplineWaypoint *v341; // r3
  const idSplineWaypoint *v342; // r29
  idPhysics *v343; // r3
  const idVec3 *v344; // r3
  float v345; // r18
  float v346; // r3
  float v347; // r26
  int v348; // r11
  navSplinePath_t *v349; // r3
  idDroneSplineWaypoint *v350; // r3
  idDroneSplineWaypoint *v351; // r29
  idPhysics *v352; // r3
  int v353; // r6
  int v354; // r5
  float *v355; // r3
  double v356; // fp0
  float v357; // r9
  double v358; // fp12
  float v359; // r7
  double v360; // fp11
  double v361; // fp3
  double v362; // fp1
  double v365; // fp6
  double v366; // fp2
  double v367; // fp2
  double v368; // fp4
  double v369; // fp7
  double v370; // fp6
  double v371; // fp5
  float v372; // r10
  float v373; // r9
  float v374; // r8
  double v376; // fp2
  double v378; // fp9
  double v379; // fp3
  double v380; // fp2
  double v381; // fp0
  double v382; // fp13
  double v383; // fp12
  double v384; // fp7
  double v385; // fp1
  double v386; // fp1
  idPhysics *v387; // r3
  int v388; // r3
  idVec3 *splinePathMgr; // r4
  float v390; // r7
  float v391; // r6
  int v392; // r11
  float r; // r10
  float v394; // r26
  float v395; // r9
  int v396; // r11
  int v397; // r11
  float v398; // r9
  float v399; // r29
  float v400; // r28
  float v401; // r3
  idVec3 *WorldPosAlongPath; // r3
  bool v403; // cr58
  int value; // r9
  idGameLocal *v405; // r11
  idEntityPtr<idEntity> *p_currentEnemy; // r27
  idEntity *v407; // r3
  idEntity *v408; // r3
  unsigned int v409; // r28
  int v410; // r9
  int v411; // r7
  idEntity *v412; // r3
  idEntity *v413; // r29
  idFaction *v414; // r24
  const idSpawnId *v415; // r29
  const idSpawnId *v416; // r3
  char v417; // r9
  bool v418; // r8
  idAIGameState *p_aiGameState; // r4
  const idDeclTrackingParms *declTrackingParms; // r11
  idTargetInfo *v421; // r11
  idEntity *Entity; // r3
  int v423; // r9
  idEntityPtr<idEntity> *p_currentScanEntity; // r27
  idEntity *v425; // r3
  int v426; // r10
  idGameLocal *v427; // r7
  int v428; // r11
  idEntity *v429; // r3
  idEntity *v430; // r3
  float v431; // r28
  int v432; // r8
  int v433; // r10
  idList<idEntityPtr<idEntity>,58> *p_previousFocusEntities; // r3
  int v435; // r29
  int v436; // r11
  double v439; // fp31
  int v440; // r26
  double v441; // fp30
  int v442; // r27
  float *v443; // r6
  double v444; // fp0
  idVec3 *v445; // r3
  int v446; // r28
  float *v447; // r10
  float *v448; // r11
  float *v449; // r29
  double v450; // fp10
  double v451; // fp8
  double v452; // fp4
  double v453; // fp9
  double v454; // fp1
  double v455; // fp11
  double v458; // fp4
  double v459; // fp2
  double v460; // fp3
  double v461; // fp2
  double v462; // fp10
  double v463; // fp13
  double v464; // fp11
  float *v465; // r10
  double v466; // fp6
  double v467; // fp7
  double v468; // fp5
  double v469; // fp1
  double v470; // fp3
  double v471; // fp10
  double v474; // fp6
  double v475; // fp13
  double v476; // fp12
  float v477; // r7
  float v478; // r5
  float v479; // r4
  float v480; // r21
  int v481; // r3
  int v482; // r6 OVERLAPPED
  __int128 v483; // r5 OVERLAPPED
  double v484; // fp0
  double v485; // fp29
  double v486; // fp28
  double v487; // fp25
  idPhysics *v488; // r3
  float *v489; // r3
  double v490; // fp8
  double v491; // fp6
  idPhysics *v492; // r3
  const idVec3 *v493; // r3
  float v494; // r19
  float v495; // r11
  float v496; // r10
  double v497; // fp0
  int v498; // r7
  float *v499; // r11
  float v500; // r27
  float v501; // r10
  double v502; // fp11
  double v503; // fp10
  double v504; // fp6
  double v505; // fp9
  float v506; // r21
  double v507; // fp5
  float v508; // r11
  double v509; // fp11
  double v510; // fp8
  double v511; // fp7
  double v512; // fp5
  double v513; // fp9
  double v514; // fp6
  float v515; // r27
  float v516; // r26
  float v517; // r25
  double v518; // fp12
  double v519; // fp11
  double v520; // fp10
  BOOL slowForPlayer; // r10
  double v522; // fp9
  double v523; // fp8
  double v524; // fp30
  int m; // r28
  const idPlayer *v526; // r3
  idEntity *v527; // r29
  double PlayerAvoidanceDistance; // fp1
  double v529; // fp31
  idPhysics *v530; // r3
  float *v531; // r27
  idPhysics *v532; // r3
  float *v533; // r3
  double v534; // fp0
  double v535; // fp13
  double v536; // fp10
  double v537; // fp11
  double v538; // fp7
  float *DesiredFacing; // r3
  double v540; // fp9
  idVec3 *p_desiredFacing; // r19
  double v542; // fp8
  double v545; // fp12
  double v546; // fp1
  double v547; // fp12
  double v548; // fp13
  double v549; // fp0
  double allowFacingChanges; // fp11
  double v551; // fp31
  double v552; // fp0
  idVec3 *p_currentFacing; // r22
  double v555; // fp12
  double v556; // fp6
  double v557; // fp5
  double v558; // fp1
  double v559; // fp10
  double v560; // fp8
  double v561; // fp9
  double v562; // fp11
  double v563; // fp12
  double v564; // fp12
  double v567; // fp5
  double v568; // fp1
  double v569; // fp13
  double v570; // fp7
  idDrone::droneState_t v571; // r11
  double DesiredSpeedForMoving; // fp1
  double overrideMaxDesiredSpeed; // fp0
  double v574; // fp10
  double v575; // fp0
  double v576; // fp13
  double v577; // fp30
  float v578; // r9
  float v579; // r7
  float v580; // r6
  double v581; // fp12
  double allowSpeedChanges; // fp0
  double v583; // fp29
  double v584; // fp13
  double v585; // fp12
  double v586; // fp0
  double v587; // fp13
  double v588; // fp0
  double startDistance; // fp0
  double endDistance; // fp13
  double v591; // fp12
  double rightDelta; // fp11
  double SplineWidth; // fp1
  double v594; // fp31
  double v595; // fp8
  double v596; // fp0
  double nearestPlayerDistance; // fp12
  double v598; // fp28
  double v599; // fp0
  double emergencyBrakeScaler; // fp13
  int v601; // r9
  idEntity *v602; // r3
  idEntity *v603; // r3
  idEntity *v604; // r29
  idPhysics *v605; // r3
  float *v606; // r28
  idPhysics *v607; // r3
  float *v608; // r3
  double v609; // fp10
  double v610; // fp6
  double v611; // fp31
  idPhysics *v612; // r3
  float *v613; // r28
  idPhysics *v614; // r3
  float *v615; // r3
  double v616; // fp8
  double v617; // fp13
  double v618; // fp12
  double v619; // fp0
  double currentSpeed; // fp10
  double desiredSpeed; // fp11
  double v622; // fp0
  double v623; // fp13
  double v624; // fp0
  double v625; // fp13
  double v626; // fp12
  double v627; // fp12
  double v628; // fp0
  double v629; // fp13
  double v632; // fp0
  double v633; // fp13
  double v634; // fp10
  idDrone::droneState_t v635; // r11
  double DesiredRollForMoving; // fp1
  double v637; // fp0
  double v638; // fp0
  double allowRollChanges; // fp13
  double v640; // fp12
  double v641; // fp9
  double v642; // fp7
  double outOfControl; // fp6
  double v644; // fp13
  double v645; // fp12
  double v646; // fp13
  double v647; // fp10
  idNavSplinePosition *p_navSplinePosition; // r25
  double v649; // fp6
  double v650; // fp5
  double v651; // fp13
  double v652; // fp0
  double v653; // fp12
  double v654; // fp11
  double v655; // fp10
  double v656; // fp8
  double v657; // fp4
  double v658; // fp9
  double v659; // fp7
  double v660; // fp0
  double v661; // fp12
  double v662; // fp2
  double v663; // fp3
  double v664; // fp1
  double v665; // fp0
  double v666; // fp10
  double v667; // fp11
  double v668; // fp12
  double v669; // fp9
  double v670; // fp0
  double v671; // fp11
  double v672; // fp9
  double v673; // fp13
  double v674; // fp12
  double v675; // fp0
  double v676; // fp10
  double v677; // fp10
  double v678; // fp10
  double v679; // fp9
  double v680; // fp8
  idVec3 *p_additivePosition; // r28
  double v682; // fp3
  double v683; // fp2
  float v684; // r10
  float v685; // r9
  double v686; // fp3
  double v687; // fp4
  double v688; // fp2
  double v689; // fp13
  float v690; // r8
  float v691; // r7
  idVec3 *p_additiveMomentum; // r27
  float v693; // r6
  float v694; // r5
  double v695; // fp0
  double v696; // fp7
  double v697; // fp1
  double v698; // fp3
  double v699; // fp4
  double v700; // fp2
  double v701; // fp13
  double v702; // fp1
  double v703; // fp0
  double v704; // fp13
  double v705; // fp2
  double v706; // fp4
  double v707; // fp1
  double v708; // fp0
  double v709; // fp13
  double v710; // fp0
  double v711; // fp9
  double v712; // fp8
  double v713; // fp7
  double v714; // fp13
  double v715; // fp11
  idQuat *p_additiveFacing; // r26
  double w; // fp11
  double v718; // fp12
  double v719; // fp13
  char v720; // r11
  char v721; // r11
  double v722; // fp13
  double v723; // fp12
  double v724; // fp11
  double v725; // fp8
  double v726; // fp9
  double v727; // fp6
  double v728; // fp4
  double v729; // fp3
  double v730; // fp7
  double v731; // fp1
  double v732; // fp2
  double v733; // fp0
  double v734; // fp0
  double v735; // fp11
  double v736; // fp13
  double v737; // fp12
  double v738; // fp10
  double v739; // fp7
  double v740; // fp9
  double v741; // fp6
  double v742; // fp4
  double v743; // fp12
  double v744; // fp10
  double v745; // fp8
  double v746; // fp5
  double v747; // fp1
  idNavSplinePosition *v748; // r3
  idVec3 *v749; // r3
  double v750; // fp31
  double v751; // fp1
  idNavSplinePosition *StartPathPos; // r3
  float v753; // r9
  float v754; // r8
  float v755; // r7
  idVec3 *WorldPos; // r3
  double v757; // fp10
  double rightDistance; // fp13
  double v759; // fp4
  double v760; // fp11
  double v761; // fp9
  double v762; // fp2
  double v763; // fp12
  double v764; // fp11
  double v765; // fp10
  double currentRoll; // fp31
  double v767; // fp30
  idMat3 *v768; // r3
  idMat3 *v769; // r3
  idPhysics *v770; // r3
  float *v771; // r3
  idVec3 *p_previousOrigin; // r26
  idPhysics *v773; // r3
  float *v774; // r3
  idPhysics *v775; // r3
  int entityNumber; // r24
  idClipModel *v777; // r3
  double v778; // fp13
  double v779; // fp12
  double v780; // fp11
  double v781; // fp10
  double v782; // fp9
  double v783; // fp7
  double v784; // fp6
  idClipModel *v785; // r23
  idClipQuery *p_clipQuery; // r27
  idClip *v787; // r28
  unsigned __int64 index; // r11
  int surfaceType; // r4
  const idDeclProjectileImpactEffect::projectileImpactEffect_t *ImpactEffectForMaterial; // r24
  idEntity *v791; // r28
  unsigned __int16 v792; // r25
  idEntity_vtbl *v793; // r25
  unsigned __int16 *v794; // r3
  int presentable; // r11
  unsigned __int64 v796; // r4
  float v797; // r3
  float v798; // r29
  float v799; // r23
  float v800; // r24
  float v801; // r11
  float v802; // r10
  double v803; // fp13
  float v804; // r10
  double v805; // fp8
  double v806; // fp11
  float v807; // r9
  double v808; // fp6
  double v809; // fp12
  float v810; // r8
  double v811; // fp7
  double v812; // fp14
  double v813; // fp2
  double v814; // fp1
  double v815; // fp0
  double v816; // fp8
  double v817; // fp6
  double v818; // fp5
  float v819; // r29
  float v820; // r28
  float v821; // r11
  double v822; // fp1
  int v823; // r11
  double v824; // fp19
  double v825; // fp23
  double v826; // fp22
  double v827; // fp20
  double v828; // fp13
  double v829; // fp10
  double v830; // fp12
  double v831; // fp11
  double v832; // fp4
  double v833; // fp2
  double v834; // fp9
  double v835; // fp0
  double v836; // fp6
  double v837; // fp3
  int v838; // ctr
  double v839; // fp5
  float *p_a; // r11
  double v841; // fp8
  double v842; // fp10
  double v843; // fp13
  double v844; // fp7
  double v845; // fp12
  double v846; // fp31
  double v847; // fp11
  double v848; // fp9
  double v849; // fp9
  double v850; // fp7
  double v851; // fp8
  double v852; // fp26
  double v853; // fp27
  double v854; // fp31
  double v855; // fp12
  double v856; // fp10
  double v857; // fp28
  double v858; // fp29
  double v859; // fp12
  double v860; // fp11
  double v861; // fp24
  double v862; // fp0
  double v863; // fp21
  double v864; // fp0
  double v865; // fp0
  double v866; // fp18
  double v867; // fp30
  double v868; // fp13
  double v869; // fp16
  double v870; // fp1
  double v871; // fp12
  double v872; // fp10
  double v873; // fp0
  double v874; // fp13
  double v875; // fp12
  double v876; // fp11
  float v877; // r24
  float v878; // r23
  float v879; // r11
  int v880; // r11
  double v881; // fp7
  double v882; // fp6
  double v883; // fp5
  float v884; // r10
  double v885; // fp1
  float v886; // r26
  float v887; // r7
  int v888; // r11
  double v889; // fp9
  double v890; // fp11
  double v891; // fp10
  int v892; // r11
  double v893; // fp1
  float v894; // r25
  float v895; // r7
  double lookUpToGoUpAount; // fp13
  double v897; // fp10
  double v898; // fp11
  double v899; // fp0
  double v900; // fp26
  double v901; // fp12
  double v902; // fp7
  double v903; // fp8
  double v904; // fp12
  double v905; // fp0
  double v906; // fp5
  double v907; // fp6
  double v908; // fp9
  double v913; // fp13
  double v914; // fp9
  double v915; // fp4
  double v916; // fp4
  double v917; // fp13
  double v918; // fp0
  double v919; // fp9
  double v920; // fp4
  double v921; // fp10
  double v922; // fp11
  double v923; // fp3
  double v924; // fp0
  double v925; // fp0
  double v926; // fp0
  double v927; // fp13
  double v928; // fp0
  double v929; // fp4
  double v930; // fp3
  double v931; // fp1
  int v932; // r9
  double v933; // fp10
  double v934; // fp13
  double v935; // fp12
  BOOL wasAfterburnerFxStarted; // r11
  double v937; // fp27
  double v938; // fp28
  double v939; // fp29
  const char *v940; // r24
  int v941; // r26
  idVec3 *v942; // r27
  const char **v943; // r29
  idMat3 *v944; // r28
  double v945; // fp13
  double v946; // fp12
  double v947; // fp11
  int v948; // r9
  float *v949; // r10
  double v950; // fp30
  int v951; // r11
  int n; // ctr
  double v953; // fp0
  double v954; // fp0
  char *v955; // r26
  int ii; // r28
  int v957; // r29
  double v958; // fp0
  int v959; // r21
  double v960; // fp31
  double v961; // fp1
  double v962; // fp0
  double v963; // fp12
  double v964; // fp11
  double v965; // fp10
  float *v966; // r11
  double v967; // fp7
  double v968; // fp3
  double v969; // fp6
  double v970; // fp4
  double v971; // fp13
  double v972; // fp1
  double v973; // fp0
  double v974; // fp3
  idAnimator_ChannelWeight *v975; // r3
  double v976; // fp13
  double v977; // fp8
  double v978; // fp2
  double v979; // fp1
  idRenderModelBeam *NumContacts; // r3
  double v981; // fp0
  int v982; // r11
  __int32 v983; // r24
  double v984; // fp13
  double v985; // fp13
  float *v986; // r11
  double v987; // fp9
  double v988; // fp8
  double v989; // fp6
  double v990; // fp5
  double v991; // fp4
  double v992; // fp3
  double v993; // fp2
  double v994; // fp1
  double v995; // fp0
  double v996; // fp12
  double v997; // fp11
  double v998; // fp9
  double v999; // fp8
  double v1000; // fp7
  idAnimator_ChannelWeight *v1001; // r3
  idRenderModelBeam *v1002; // r3
  int v1003; // r22
  unsigned int v1004; // r29
  idPhysics *v1005; // r3
  const idMat3 *v1006; // r27
  idPhysics *v1007; // r3
  int v1008; // r3
  idPresentable *v1009; // r11
  const idVec3 *v1010; // r26
  double v1011; // fp31
  idPlayer *v1012; // r3
  idPhysics *v1013; // r3
  idPhysics_vtbl *v1014; // r11
  float *v1015; // r3
  double v1016; // fp9
  double v1017; // fp7
  float v1018; // r10
  float v1019; // r9
  double v1020; // fp4
  double v1021; // fp10
  double v1022; // fp0
  double v1023; // fp11
  double v1024; // fp5
  double v1025; // fp12
  double v1026; // fp0
  double v1027; // fp13
  double v1028; // fp13
  double v1029; // fp0
  double v1030; // fp8
  double v1031; // fp13
  double v1032; // fp0
  double v1033; // fp30
  double v1034; // fp31
  soundChannel_t v1035; // r29
  int v1036; // r27
  const float *v1037; // r26
  int v1038; // r28
  int v1039; // r27
  const float *v1040; // r26
  int v1041; // r28
  int v1042; // r27
  int v1043; // r28
  char *v1044; // r10
  double v1045; // fp11
  double v1046; // fp10
  double v1047; // fp9
  double v1048; // fp7
  double v1049; // fp6
  double v1050; // fp8
  double v1051; // fp2
  double v1052; // fp1
  double v1053; // fp0
  double v1054; // fp3
  idAnimator_ChannelWeight *v1055; // r3
  idRenderModelBeam *v1056; // r3
  int v1057; // [sp+8h] [-848h]
  __int64 v1058; // [sp+8h] [-848h]
  __int64 v1059; // [sp+8h] [-848h]
  int v1060; // [sp+Ch] [-844h]
  int v1061; // [sp+10h] [-840h]
  __int64 v1062; // [sp+10h] [-840h]
  __int64 v1063; // [sp+10h] [-840h]
  int v1064; // [sp+14h] [-83Ch]
  int v1065; // [sp+18h] [-838h]
  __int64 v1066; // [sp+18h] [-838h]
  __int64 v1067; // [sp+18h] [-838h]
  idDrone *v1068; // [sp+1Ch] [-834h]
  int v1069; // [sp+20h] [-830h]
  __int64 v1070; // [sp+20h] [-830h]
  __int64 v1071; // [sp+20h] [-830h]
  int v1072; // [sp+24h] [-82Ch]
  int v1073; // [sp+28h] [-828h]
  __int64 v1074; // [sp+28h] [-828h]
  __int64 v1075; // [sp+28h] [-828h]
  int v1076; // [sp+2Ch] [-824h]
  int v1077; // [sp+30h] [-820h]
  int v1078; // [sp+30h] [-820h]
  int v1079; // [sp+30h] [-820h]
  int v1080; // [sp+34h] [-81Ch]
  int v1081; // [sp+34h] [-81Ch]
  int v1082; // [sp+34h] [-81Ch]
  int v1083; // [sp+38h] [-818h]
  int v1084; // [sp+38h] [-818h]
  int v1085; // [sp+38h] [-818h]
  int v1086; // [sp+3Ch] [-814h]
  int v1087; // [sp+3Ch] [-814h]
  int v1088; // [sp+3Ch] [-814h]
  int v1089; // [sp+40h] [-810h]
  int v1090; // [sp+40h] [-810h]
  int v1091; // [sp+40h] [-810h]
  int v1092; // [sp+44h] [-80Ch]
  int v1093; // [sp+44h] [-80Ch]
  int v1094; // [sp+44h] [-80Ch]
  int v1095; // [sp+48h] [-808h]
  int v1096; // [sp+48h] [-808h]
  int v1097; // [sp+48h] [-808h]
  int v1098; // [sp+4Ch] [-804h]
  int v1099; // [sp+4Ch] [-804h]
  int v1100; // [sp+4Ch] [-804h]
  int v1101[20]; // [sp+50h] [-800h] BYREF
  idVec3 v1102; // [sp+A0h] [-7B0h] BYREF
  idVec3 v1103; // [sp+B0h] [-7A0h] BYREF
  const float *v1104; // [sp+BCh] [-794h]
  idNavSplinePosition v1105; // [sp+C0h] [-790h] BYREF
  float v1106; // [sp+CCh] [-784h]
  char *v1107; // [sp+D0h] [-780h]
  float v1108; // [sp+D4h] [-77Ch]
  idNavSplinePosition v1109; // [sp+D8h] [-778h] BYREF
  idNavSplinePosition v1110; // [sp+E8h] [-768h] BYREF
  idNavSplinePosition v1111; // [sp+F8h] [-758h] BYREF
  float v1112; // [sp+108h] [-748h] BYREF
  float v1113; // [sp+10Ch] [-744h]
  float v1114; // [sp+110h] [-740h]
  idNavSplinePosition v1115; // [sp+118h] [-738h] BYREF
  idVec3 v1116; // [sp+128h] [-728h] BYREF
  idSpawnId v1117; // [sp+134h] [-71Ch] BYREF
  idVec3 v1118; // [sp+138h] [-718h] BYREF
  float v1119; // [sp+148h] [-708h] BYREF
  float v1120; // [sp+14Ch] [-704h]
  float v1121; // [sp+150h] [-700h]
  idColor *v1122; // [sp+154h] [-6FCh]
  float v1123; // [sp+158h] [-6F8h]
  idColor *v1124; // [sp+15Ch] [-6F4h]
  float v1125; // [sp+160h] [-6F0h]
  idColor v1126; // [sp+170h] [-6E0h] BYREF
  idEventArg v1127; // [sp+180h] [-6D0h] BYREF
  float v1128; // [sp+194h] [-6BCh]
  float v1129; // [sp+198h] [-6B8h]
  float v1130; // [sp+19Ch] [-6B4h]
  float v1131; // [sp+1A0h] [-6B0h]
  float v1132; // [sp+1A4h] [-6ACh]
  int v1133; // [sp+1ACh] [-6A4h] BYREF
  idMat3 v1134; // [sp+1B0h] [-6A0h] BYREF
  const char *v1135; // [sp+1D8h] [-678h]
  float v1136; // [sp+1DCh] [-674h]
  float v1137; // [sp+1E0h] [-670h]
  navSplinePath_t v1138; // [sp+1F0h] [-660h] BYREF
  idVec3 v1139; // [sp+220h] [-630h] BYREF
  navSplinePath_t v1140; // [sp+230h] [-620h] BYREF
  idMat3 v1141; // [sp+250h] [-600h] BYREF
  float v1142; // [sp+274h] [-5DCh]
  float v1143; // [sp+278h] [-5D8h]
  idVec3 v1144; // [sp+280h] [-5D0h] BYREF
  idVec3 v1145; // [sp+290h] [-5C0h] BYREF
  float v1146[4]; // [sp+2A0h] [-5B0h] BYREF
  float v1147[4]; // [sp+2B0h] [-5A0h] BYREF
  float v1148[4]; // [sp+2C0h] [-590h] BYREF
  float v1149[4]; // [sp+2D0h] [-580h] BYREF
  float v1150[4]; // [sp+2E0h] [-570h] BYREF
  float v1151[4]; // [sp+2F0h] [-560h] BYREF
  idMat3 v1152; // [sp+300h] [-550h] BYREF
  idMat3 v1153; // [sp+330h] [-520h] BYREF
  idTargetFilter v1154; // [sp+358h] [-4F8h] BYREF
  idStr v1155; // [sp+360h] [-4F0h] BYREF
  navSplinePath_t v1156; // [sp+380h] [-4D0h] BYREF
  idTargetList v1157; // [sp+3A0h] [-4B0h] BYREF
  idTargetSelector v1158; // [sp+3E0h] [-470h] BYREF
  trace_t v1159; // [sp+3F0h] [-460h] BYREF
  idAILogic v1160; // [sp+470h] [-3E0h] BYREF
  idMat3 v1161; // [sp+490h] [-3C0h] BYREF
  _DWORD v1162[32]; // [sp+4C0h] [-390h] BYREF
  trace_t v1163; // [sp+540h] [-310h] BYREF
  _DWORD v1164[2]; // [sp+5C0h] [-290h] BYREF
  int v1165; // [sp+5C8h] [-288h] BYREF

  v4 = false;
  v5 = &ai_useTurnTransitions.valueString.baseBuffer[12];
  v6 = 0.0;
  v1106 = 0.0;
  v1107 = &ai_useTurnTransitions.valueString.baseBuffer[12];
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) != 0 )
  {
    v7 = true;
    if ( this->engineSoundsFade >= 2.0 )
    {
      v4 = false;
      goto LABEL_9;
    }
LABEL_7:
    v4 = v7;
    goto LABEL_9;
  }
  if ( this->health <= 0.0 )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->deathDoneTime )
      goto LABEL_9;
    v7 = this->engineSoundsFade < 2.0;
    goto LABEL_7;
  }
  this->engineSoundsFade = 0.0;
LABEL_9:
  v8 = &NOSE_LIFT_WHEN_TURNING_AROUND;
  v1104 = &NOSE_LIFT_WHEN_TURNING_AROUND;
  if ( v4 )
  {
    if ( this->isScannerOn )
      idDrone::TurnOffScanner(this);
    v9 = (float)(this->engineSoundsFade + 0.0099999998);
    v10 = 1.0;
    this->engineSoundsFade = this->engineSoundsFade + 0.0099999998;
    if ( v9 <= 1.0 )
    {
      v11 = SND_CHANNEL_ENGINE_IDLE;
      v12 = 0;
      if ( this->smallEngineSounds.num > 0 )
      {
        v13 = 0;
        while ( v11 < SND_CHANNEL_WEAPON_1 )
        {
          idDrone::SetEngineSoundVolume(
            this,
            channel: v11++,
            engineSound: &this->smallEngineSounds.list[v13],
            thrust: this->smallEngineThrustLevel,
            minThrust: v10,
            maxThrust: v1104[219]);
          ++v12;
          ++v13;
          if ( v12 >= this->smallEngineSounds.num )
            break;
          v10 = 1.0;
        }
      }
      v8 = v1104;
      v14 = 0;
      if ( this->largeEngineSounds.num > 0 )
      {
        v15 = 0;
        do
        {
          if ( v11 >= SND_CHANNEL_WEAPON_1 )
            break;
          idDrone::SetEngineSoundVolume(
            this,
            channel: v11++,
            engineSound: &this->largeEngineSounds.list[v15],
            thrust: this->largeEngineThrustLevel,
            minThrust: v1104[182],
            maxThrust: v1104[193]);
          ++v14;
          ++v15;
        }
        while ( v14 < this->largeEngineSounds.num );
      }
      v16 = 0;
      if ( this->afterburnerSounds.num > 0 )
      {
        v17 = 0;
        do
        {
          if ( v11 >= SND_CHANNEL_WEAPON_1 )
            break;
          afterburnerThrustLevel = this->afterburnerThrustLevel;
          v19 = &this->afterburnerSounds.list[v17];
          if ( idEntity::IsPlayingSound(this, channel: v11) )
          {
            minThrustVolume = v19->minThrustVolume;
            if ( afterburnerThrustLevel > 0.1 )
            {
              if ( afterburnerThrustLevel < 0.89999998 )
                minThrustVolume = (float)((float)((float)((float)(v19->maxThrustVolume - v19->minThrustVolume)
                                                        * (float)((float)afterburnerThrustLevel - (float)0.1))
                                                * (float)1.25)
                                        + v19->minThrustVolume);
              else
                minThrustVolume = v19->maxThrustVolume;
            }
            idEntity::SetSoundVolume(
              this,
              channel: v11,
              volume: (float)-(float)((float)(this->engineSoundsFade * (float)100.0) - (float)minThrustVolume));
          }
          ++v11;
          ++v16;
          ++v17;
        }
        while ( v16 < this->afterburnerSounds.num );
      }
      v6 = v1106;
      v5 = v1107;
    }
    else
    {
      this->engineSoundsFade = 1077936128;
      if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) != 0 && this->health <= 0.0 )
      {
        if ( !this->wasRemoveEventPosted )
        {
          idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 10000);
          this->wasRemoveEventPosted = true;
        }
      }
      else
      {
        idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
      }
    }
    idEntity::UpdateSound(this);
  }
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) != 0
    || this->firstThinkFlag && (unsigned __int8)idDrone::FirstThink(this) == 0 )
  {
    return;
  }
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  this->UpdateFX(this);
  idEntity::TouchTriggers(this);
  if ( idAccolade::Count(this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064)) <= 0 )
    return;
  if ( g_droneDebugForceDroneState.valueInteger >= 0 )
  {
    valueInteger = g_droneDebugForceDroneState.valueInteger;
    if ( g_droneDebugForceDroneState.valueInteger >= 9 )
      valueInteger = 8;
    v22 = LODWORD(v8[valueInteger + 280]);
    if ( v22 >= DMS_STOPPED )
    {
      if ( v22 >= DMS_NUM_DRONE_MOVE_STATES )
        v22 = DMS_FAST;
    }
    else
    {
      v22 = DMS_STOPPED;
    }
    idDrone::SetStateSetMoveState(this, newState: valueInteger, newMoveState: v22);
  }
  if ( g_droneDebugForceMoveState.valueInteger >= 0 )
  {
    val = this->moveStates[0].val;
    LODWORD(v1103.x) = g_droneDebugForceMoveState.valueInteger;
    idDrone::ChangeMoveState(
      this,
      newState: g_droneDebugForceMoveState.valueInteger,
      time: v8[5 * val + 255 + g_droneDebugForceMoveState.valueInteger]);
  }
  v24 = (float)(this->recentForceApplied.y * *(v8 - 3));
  v25 = (float)(this->recentForceApplied.z * *(v8 - 3));
  this->recentForceApplied.x = this->recentForceApplied.x * *(v8 - 3);
  this->recentForceApplied.y = v24;
  this->recentForceApplied.z = v25;
  idDrone::UpdateMoveStateMemberships(this);
  v26 = 0;
  weaponArmSpeed = this->weaponArmSpeed;
  HIDWORD(v28) = moveStateScalers[1];
  v29 = this->moveStateMemberships[1];
  v30 = this->moveStates[0].val;
  v31 = this->moveStates[1].val;
  v32 = this->moveStateMemberships[2];
  v33 = this->moveStates[2].val;
  v34 = *(float *)&this->moveStates[3].val;
  v35 = this->moveStateMemberships[3];
  HIDWORD(v36) = 4 * LODWORD(v34);
  v37 = (float)((float)moveStateScalers[0][v30] * this->moveStateMemberships[0]);
  v38 = (float)((float)moveStateScalers[1][v30] * this->moveStateMemberships[0]);
  v39 = (float)((float)moveStateScalers[2][v30] * this->moveStateMemberships[0]);
  v40 = moveStateScalers[0][v31];
  v41 = (float)((float)moveStateScalers[3][v30] * this->moveStateMemberships[0]);
  v42 = moveStateScalers[1][v31];
  v43 = moveStateScalers[2][v31];
  v44 = moveStateScalers[3][v31];
  v1103.x = v34;
  v45 = moveStateScalers[0][v33];
  v1103.x = v34;
  v46 = moveStateScalers[1][v33];
  v1103.x = v34;
  v47 = moveStateScalers[0][LODWORD(v34)];
  v1103.x = v34;
  v48 = (float)((float)((float)v43 * (float)v29) + (float)v39);
  v49 = moveStateScalers[3][v33];
  v50 = (float)((float)((float)v44 * (float)v29) + (float)v41);
  v51 = moveStateScalers[2][LODWORD(v34)];
  v52 = moveStateScalers[3][LODWORD(v34)];
  v53 = (float)((float)((float)v45 * (float)v32) + (float)((float)((float)v40 * (float)v29) + (float)v37));
  v54 = (float)((float)((float)v46 * (float)v32) + (float)((float)((float)v42 * (float)v29) + (float)v38));
  v55 = (float)((float)((float)moveStateScalers[2][v33] * (float)v32) + (float)v48);
  v56 = (float)((float)((float)moveStateScalers[3][v33] * (float)v32) + (float)v50);
  v1137 = (float)((float)moveStateScalers[1][LODWORD(v34)] * (float)v35) + (float)v54;
  v1136 = (float)((float)v47 * (float)v35) + (float)v53;
  v57 = (float)((float)((float)v52 * (float)v35) + (float)v56);
  v1123 = (float)((float)v51 * (float)v35) + (float)v55;
  v1108 = (float)((float)v52 * (float)v35) + (float)v56;
  do
  {
    v58 = weaponArmSpeed + 8;
    if ( *((_DWORD *)weaponArmSpeed + 4) != 0 )
    {
      HIDWORD(v28) = idGameTimeManager::GetGameMs(
                       this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                       type: GAMETIME_SCALED);
      if ( *((_DWORD *)weaponArmSpeed + 4) <= SHIDWORD(v28) )
        idDrone::DeployWeaponNow(this, gunId: v26);
    }
    if ( *v58 != 0 )
    {
      HIDWORD(v28) = idGameTimeManager::GetGameMs(
                       this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                       type: GAMETIME_SCALED);
      if ( *v58 <= SHIDWORD(v28) )
        idDrone::StowWeaponNow(this, gunId: v26);
    }
    if ( *weaponArmSpeed != v6 )
    {
      v59 = (float)(*(weaponArmSpeed - 4) + *weaponArmSpeed);
      *(weaponArmSpeed - 4) = *(weaponArmSpeed - 4) + *weaponArmSpeed;
      if ( v59 >= v6 )
      {
        v60 = *((_BYTE *)v8 + v26 + 224);
        LODWORD(v28) = *((char *)v8 + v26 + 232) - v60 + 1;
        *(_QWORD *)&v1116.x = v28;
        if ( v59 <= 1.0 )
        {
          LODWORD(v1118.y) = (int)(float)((float)v59 * (float)*(__int64 *)&v1116.x);
          v61 = LOBYTE(v1118.y) + v60;
        }
        else
        {
          *(weaponArmSpeed - 4) = 1.0;
          *weaponArmSpeed = v6;
          v61 = *((_BYTE *)v8 + v26 + 232);
        }
        BYTE1(v1103.x) = v61;
        BYTE2(v1103.x) = 0;
        HIBYTE(v1103.x) = *((_BYTE *)v8 + v26 + 216);
        idAttachmentCollection::ShowAttachment(
          this: &this->attachments,
          handle: (const idHandle<int,enum invalidAttachment_t,-1> *)weaponArmSpeed - 8);
        HIDWORD(v28) = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( HIDWORD(v28) != 0 )
        {
          v62 = *(idPropsCollection **)(HIDWORD(v28) + 2032);
          v63 = v62 + 22;
          if ( v62 == nullptr )
            v63 = nullptr;
          HIDWORD(v28) = idPropsCollection::GetTag(
                           this: v63,
                           propName: "models/vehicles/weapons/class3turret/class3turret.lwo",
                           tagName: (const char *)&v1103);
          if ( *(unsigned __int16 *)(HIDWORD(v28) + 28) != 0xFFFF )
            HIDWORD(v28) = idAttachmentCollection::RebindAttachment(
                             this: &this->attachments,
                             handle: (const idHandle<int,enum invalidAttachment_t,-1> *)weaponArmSpeed - 8,
                             tagData: (const tagData_t *)HIDWORD(v28));
        }
      }
      else
      {
        *(weaponArmSpeed - 4) = v6;
        *weaponArmSpeed = v6;
        idAttachmentCollection::HideAttachment(
          this: &this->attachments,
          handle: (const idHandle<int,enum invalidAttachment_t,-1> *)weaponArmSpeed - 8,
          ignoreShowAll: false);
      }
    }
    ++v26;
    ++weaponArmSpeed;
  }
  while ( v26 < 4 );
  g = -9.4039548e-38;
  if ( this->currentBehaviorPoint < 0 )
  {
    LODWORD(v1103.x) = this->behaviorPoints.num;
    if ( SLODWORD(v1103.x) > 0 )
    {
      if ( this->nextBehaviorPointToTest >= SLODWORD(v1103.x) )
      {
        resetSpeedOverrideCounter = this->resetSpeedOverrideCounter;
        this->nextBehaviorPointToTest = 0;
        if ( resetSpeedOverrideCounter != 0 )
        {
          v66 = resetSpeedOverrideCounter - 1;
          this->resetSpeedOverrideCounter = v66;
          if ( v66 == 0 )
            this->overrideMaxDesiredSpeed = v6;
        }
      }
      v67 = &this->behaviorPoints.list[this->nextBehaviorPointToTest];
      if ( gameLocal->spawnIds.ptr[v67->entityToScan.spawnId.value & 0x1FFF] == v67->entityToScan.spawnId.value >> 13
        && (v68 = gameLocal->entities.ptr[v67->entityToScan.spawnId.value & 0x1FFF]) != nullptr )
      {
        v69 = (idPlayerStart *)idEntity::CastTo(c: v68);
      }
      else
      {
        v69 = nullptr;
      }
      Player = (idPlayer *)v69;
      if ( v69 != nullptr )
      {
        if ( idPlayerStart::CastTo(c: v69) != nullptr )
          Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
        if ( Player != nullptr )
        {
          numActivates = this->numActivates;
          if ( numActivates >= v67->minTriggerCount && numActivates <= v67->maxTriggerCount )
          {
            Physics = idEntity::GetPhysics(this: Player);
            v73 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v74 = idEntity::GetPhysics(this);
            v75 = (float *)v74->GetOrigin(this: v74, a2: 0);
            v76 = (float)(v73[1] - v75[1]);
            v77 = (float)(v73[2] - v75[2]);
            slowDistance = v67->slowDistance;
            v79 = __fsqrts((float)((float)((float)v77 * (float)v77)
                                 + (float)((float)((float)(*v73 - *v75) * (float)(*v73 - *v75))
                                         + (float)((float)v76 * (float)v76))));
            if ( slowDistance > v6 && v79 < slowDistance )
            {
              this->resetSpeedOverrideCounter = 2;
              v80 = (float)(v67->slowDistance * (float)0.5);
              if ( v79 > v80 )
              {
                if ( v79 < v67->slowDistance )
                  v81 = (float)((float)((float)((float)v79 - (float)v80) * *(v8 - 11))
                              / (float)(v67->slowDistance - (float)v80));
                else
                  v81 = *(v8 - 11);
              }
              else
              {
                v81 = 0.000099999997;
              }
              this->overrideMaxDesiredSpeed = v81;
            }
            if ( v79 <= v67->distanceToScan )
            {
              if ( !v67->wasDroneWithinRange )
              {
                maxNumScans = v67->maxNumScans;
                v67->wasDroneWithinRange = true;
                if ( (maxNumScans == 0 || v67->numScansDone < maxNumScans)
                  && (v67->nextScanTime == 0
                   || v67->nextScanTime <= idGameTimeManager::GetGameMs(
                                             this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                                             type: GAMETIME_SCALED)) )
                {
                  scanChance = v67->scanChance;
                  v84 = true;
                  if ( scanChance != v6 )
                  {
                    if ( scanChance <= v6 || (v85 = 1, scanChance >= 1.0) )
                      v85 = 0;
                    if ( v85 != 0 )
                      v84 = RandomFloat(max: 1.0) < (double)v67->scanChance;
                  }
                  if ( v84 )
                  {
                    exitScanState = v67->exitScanState;
                    switch ( exitScanState )
                    {
                      case DS_HIDE:
                        this->Hide_2(this);
                        this->health = v6;
                        return;
                      case DS_DEATH:
                        idDrone::KillDrone(this);
                        break;
                      case DS_SET_SPEED:
                      case DS_ADJUST_SPEED:
                        if ( v67->endScanDesiredSpeedMultiplier != -1.0 )
                        {
                          this->desiredSpeedMultiplier = exitScanState == DS_SET_SPEED
                                                       ? v67->endScanDesiredSpeedMultiplier
                                                       : v67->endScanDesiredSpeedMultiplier
                                                       + this->desiredSpeedMultiplier;
                          desiredSpeedMultiplier = this->desiredSpeedMultiplier;
                          v88 = 0.25;
                          if ( desiredSpeedMultiplier < 0.25 || (v88 = 2.0, desiredSpeedMultiplier > 2.0) )
                            this->desiredSpeedMultiplier = v88;
                        }
                        break;
                      default:
                        LODWORD(v1103.x) = Player->entityNumber;
                        LODWORD(v1118.x) = 3;
                        this->currentScanEntity.spawnId.value = (gameLocal->spawnIds.ptr[LODWORD(v1103.x)] << 13)
                                                              | LODWORD(v1103.x);
                        idDrone::SetState(this, newState: 3);
                        if ( v67->forcedCuriosity > v6 )
                          this->currentScanEntityCuriosity = v67->forcedCuriosity * (float)2.0;
                        this->currentBehaviorPoint = this->nextBehaviorPointToTest;
                        break;
                    }
                    g = COERCE_FLOAT(&EV_Activate);
                    if ( idEntityPtr<idEntity const>::operator->(this: &v67->startScanTrigger) != nullptr )
                    {
                      v89 = (idDrone *)idEntityPtr<idEntity const>::operator->(this: &v67->entityToScan);
                      if ( v89 == nullptr )
                        v89 = this;
                      v90 = idEventArg::idEventArg(this: &v1127, data: v89);
                      v91 = &v1133;
                      v92 = (_DWORD *)&v90[-1].value.q[3];
                      for ( i = 5; i != 0; --i )
                        *++v91 = *++v92;
                      v94 = idEntityPtr<idEntity const>::operator->(this: &v67->startScanTrigger);
                      idEventReceiver::PostEventMS(
                        this: v94,
                        ev: &EV_Activate,
                        time: 0,
                        arg1: (const idEventArg *)LODWORD(v1134.mat[0].z));
                    }
                    if ( idEntityPtr<idEntity const>::operator->(this: &v67->endScanTrigger) != nullptr
                      && this->currentBehaviorPoint == -1 )
                    {
                      v95 = (idDrone *)idEntityPtr<idEntity const>::operator->(this: &v67->entityToScan);
                      if ( v95 == nullptr )
                        v95 = this;
                      v96 = idEventArg::idEventArg(this: &v1127, data: v95);
                      v97 = &v1133;
                      v98 = (_DWORD *)&v96[-1].value.q[3];
                      for ( j = 5; j != 0; --j )
                        *++v97 = *++v98;
                      v100 = idEntityPtr<idEntity const>::operator->(this: &v67->endScanTrigger);
                      idEventReceiver::PostEventMS(
                        this: v100,
                        ev: &EV_Activate,
                        time: 0,
                        arg1: (const idEventArg *)LODWORD(v1134.mat[0].z));
                    }
                  }
                }
              }
            }
            else
            {
              v67->wasDroneWithinRange = false;
            }
          }
        }
      }
      nextBehaviorPointToTest = this->nextBehaviorPointToTest;
      if ( nextBehaviorPointToTest >= this->behaviorPoints.num - 1 )
      {
        v102 = this->resetSpeedOverrideCounter;
        this->nextBehaviorPointToTest = 0;
        if ( v102 != 0 )
        {
          v103 = v102 - 1;
          this->resetSpeedOverrideCounter = v103;
          if ( v103 == 0 )
            this->overrideMaxDesiredSpeed = v6;
        }
      }
      else
      {
        this->nextBehaviorPointToTest = nextBehaviorPointToTest + 1;
      }
    }
  }
  if ( this->health > v6 )
  {
    if ( this->startingHealth <= v6 )
      v104 = 0.5;
    else
      v104 = (float)(this->health / this->startingHealth);
  }
  else
  {
    v104 = v6;
  }
  nextAfterburnerSmokeTime = this->nextAfterburnerSmokeTime;
  v1125 = v104;
  if ( nextAfterburnerSmokeTime == 0
    || (GameMs = idGameTimeManager::GetGameMs(
                   this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                   type: GAMETIME_SCALED),
        v107 = 1,
        this->nextAfterburnerSmokeTime > GameMs) )
  {
    v107 = 0;
  }
  engineSmokeAmount = this->engineSmokeAmount;
  value_high = v107;
  v1135 = "_info";
  if ( engineSmokeAmount > v6 || v107 != 0 )
  {
    v110 = v6;
    if ( v104 < 0.5 && this->health > v6 )
      v110 = (float)-(float)((float)((float)(this->health / this->startingHealth) * (float)0.1) - (float)0.1);
    if ( this->health <= v6 )
    {
      if ( engineSmokeAmount <= v8[203] )
        v111 = DEATH_SLOW_SMOKE_FALLOFF;
      else
        v111 = DEATH_FAST_SMOKE_FALLOFF;
      this->engineSmokeAmount = (float)engineSmokeAmount - (float)v111;
    }
    else
    {
      this->engineSmokeAmount = -(float)((float)((float)((float)v104 + (float)1.0) * SMOKE_FALLOFF)
                                       - (float)engineSmokeAmount);
    }
    if ( this->engineSmokeAmount < v110 )
    {
      this->engineSmokeAmount = v110;
      if ( v110 <= v6 )
      {
        this->nextEngineSmokeTime = 0;
        this->nextSputterTime = 0;
      }
    }
    if ( (v112 = idGameTimeManager::GetGameMs(
                   this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                   type: GAMETIME_SCALED),
          nextEngineSmokeTime = this->nextEngineSmokeTime,
          v112 >= nextEngineSmokeTime)
      && nextEngineSmokeTime != 0
      || value_high != 0 )
    {
      v114 = 1;
      if ( this->nextSputterTime == 0
        || (v115 = idGameTimeManager::GetGameMs(
                     this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                     type: GAMETIME_SCALED),
            v116 = 1,
            v115 < this->nextSputterTime) )
      {
        v116 = 0;
      }
      HIDWORD(v36) = v116;
      LODWORD(v1102.x) = v116;
      v1103 = vec3_origin;
      if ( v116 != 0 )
      {
        v117 = idEntity::GetPhysics(this);
        v118 = (int)v117->GetAxis(this: v117, a2: 0);
        v119 = &v1133;
        v120 = (_DWORD *)(v118 - 4);
        for ( k = 9; k != 0; --k )
          *++v119 = *++v120;
        v122 = RandomFloat(min: v8[104], max: 2.0);
        v123 = RandomFloat(min: -1.0, max: v8[174]);
        g = COERCE_FLOAT(&si_vector_decode_cat_0[184]);
        _FP8 = (float)((float)((float)((float)v123 * (float)v123) + (float)((float)v122 * (float)v122))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f6, f8, f9, f13 }
        v126 = __frsqrte(_FP6);
        v127 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v126
                                                                                             * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)v122 * (float)v122)) * (float)0.5))
                                                                                     * (float)v126)
                                                                             - (float)1.5)
                                                             * (float)v126)
                                                     * (float)((float)((float)((float)v123 * (float)v123)
                                                                     + (float)((float)v122 * (float)v122))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v126
                                                                                     * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)v122 * (float)v122))
                                                                                             * (float)0.5))
                                                                             * (float)v126)
                                                                     - (float)1.5)
                                                     * (float)v126))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v126
                                                             * (float)((float)((float)((float)v123 * (float)v123)
                                                                             + (float)((float)v122 * (float)v122))
                                                                     * (float)0.5))
                                                     * (float)v126)
                                             - (float)1.5)
                             * (float)v126));
        v128 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v126 * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)v122 * (float)v122)) * (float)0.5)) * (float)v126) - (float)1.5) * (float)v126)
                                                                                             * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)v122 * (float)v122)) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v126 * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)v122 * (float)v122)) * (float)0.5)) * (float)v126) - (float)1.5)
                                                                                             * (float)v126))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v126 * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)v122 * (float)v122)) * (float)0.5))
                                                                                             * (float)v126)
                                                                                     - (float)1.5)
                                                                     * (float)v126))
                                                     * (float)((float)((float)((float)v123 * (float)v123)
                                                                     + (float)((float)v122 * (float)v122))
                                                             * (float)0.5))
                                             * (float)v127)
                                     - (float)1.5)
                     * (float)v127);
        v129 = (float)((float)v128 * (float)((float)((float)v123 * (float)v123) + (float)((float)v122 * (float)v122)));
        v130 = (float)((float)v128 * (float)v6);
        v131 = (float)((float)v128 * (float)v123);
        v132 = (float)((float)v128 * (float)v122);
        if ( v129 < 0.001 )
        {
          v131 = -1.0;
          v130 = v6;
          v132 = v6;
        }
        v133 = (float)((float)v131 * v8[222]);
        v134 = RandomFloat(min: *(v8 - 12), max: v8[63]);
        v135 = -v133;
        _FP6 = (float)((float)((float)((float)v135 * (float)v135)
                             + (float)((float)((float)v132 * (float)v132) + (float)((float)v134 * (float)v134)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f4, f6, f7, f13 }
        v138 = __frsqrte(_FP4);
        v139 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v138
                                                                                             * (float)((float)((float)((float)v135 * (float)v135) + (float)((float)((float)v132 * (float)v132) + (float)((float)v134 * (float)v134))) * 0.5))
                                                                                     * (float)v138)
                                                                             - 1.5)
                                                             * (float)v138)
                                                     * (float)((float)((float)((float)v135 * (float)v135)
                                                                     + (float)((float)((float)v132 * (float)v132)
                                                                             + (float)((float)v134 * (float)v134)))
                                                             * 0.5))
                                             * (float)((float)-(float)((float)((float)((float)v138
                                                                                     * (float)((float)((float)((float)v135 * (float)v135) + (float)((float)((float)v132 * (float)v132) + (float)((float)v134 * (float)v134)))
                                                                                             * 0.5))
                                                                             * (float)v138)
                                                                     - 1.5)
                                                     * (float)v138))
                                     - 1.5)
                     * (float)((float)-(float)((float)((float)((float)v138
                                                             * (float)((float)((float)((float)v135 * (float)v135)
                                                                             + (float)((float)((float)v132 * (float)v132)
                                                                                     + (float)((float)v134 * (float)v134)))
                                                                     * 0.5))
                                                     * (float)v138)
                                             - 1.5)
                             * (float)v138));
        v140 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v138 * (float)((float)((float)((float)v135 * (float)v135) + (float)((float)((float)v132 * (float)v132) + (float)((float)v134 * (float)v134))) * 0.5))
                                                                                             * (float)v138)
                                                                                     - 1.5)
                                                                     * (float)v138)
                                                             * (float)((float)((float)((float)v135 * (float)v135)
                                                                             + (float)((float)((float)v132 * (float)v132)
                                                                                     + (float)((float)v134 * (float)v134)))
                                                                     * 0.5))
                                                     * (float)((float)-(float)((float)((float)((float)v138
                                                                                             * (float)((float)((float)((float)v135 * (float)v135) + (float)((float)((float)v132 * (float)v132) + (float)((float)v134 * (float)v134))) * 0.5))
                                                                                     * (float)v138)
                                                                             - 1.5)
                                                             * (float)v138))
                                             - 1.5)
                             * (float)((float)-(float)((float)((float)((float)v138
                                                                     * (float)((float)((float)((float)v135 * (float)v135)
                                                                                     + (float)((float)((float)v132 * (float)v132)
                                                                                             + (float)((float)v134 * (float)v134)))
                                                                             * 0.5))
                                                             * (float)v138)
                                                     - 1.5)
                                     * (float)v138))
                     * (float)((float)((float)((float)v135 * (float)v135)
                                     + (float)((float)((float)v132 * (float)v132) + (float)((float)v134 * (float)v134)))
                             * 0.5));
        v142 = (float)((float)((float)-(float)((float)((float)v140 * (float)v139) - 1.5) * (float)v139) * (float)v132);
        v143 = (float)((float)((float)-(float)((float)((float)v140 * (float)v139) - 1.5) * (float)v139) * (float)-v133);
        v141 = (float)((float)v134 * (float)((float)-(float)((float)((float)v140 * (float)v139) - 1.5) * (float)v139));
        if ( (float)((float)((float)((float)v135 * (float)v135)
                           + (float)((float)((float)v132 * (float)v132) + (float)((float)v134 * (float)v134)))
                   * (float)((float)-(float)((float)((float)v140 * (float)v139) - 1.5) * (float)v139)) < 0.0099999998 )
        {
          v142 = v6;
          v143 = v6;
          v141 = 1.0;
        }
        z = v1134.mat[2].z;
        y = v1134.mat[2].y;
        x = v1134.mat[2].x;
        v147 = v1134.mat[1].z;
        v148 = v1134.mat[1].y;
        v149 = v1134.mat[1].x;
        v150 = v1134.mat[0].z;
        v151 = v1134.mat[0].y;
        v153 = (float)((float)((float)v131 * v1134.mat[1].y) + (float)((float)v132 * v1134.mat[2].y));
        v154 = (float)((float)((float)v131 * v1134.mat[1].x) + (float)((float)v132 * v1134.mat[2].x));
        v155 = (float)((float)((float)v130 * v1134.mat[0].z)
                     + (float)((float)((float)v131 * v1134.mat[1].z) + (float)((float)v132 * v1134.mat[2].z)));
        v152 = v1134.mat[0].x;
        v156 = (float)((float)((float)v130 * v1134.mat[0].y) + (float)v153);
        v157 = (float)((float)(v1134.mat[0].x * (float)v130) + (float)v154);
        v158 = (float)(RandomFloat(min: v8[60], max: 0.050000001) * 0.5);
        *(double *)&v159 = v158;
        v160 = sin(x: v159);
        v1118.x = *(double *)&v160;
        *(double *)&v160 = v158;
        v161 = cos(x: v160);
        v162 = (float)((float)v156 * v1118.x);
        v163 = (float)((float)v155 * v1118.x);
        v164 = this->additiveAngularMomentum.y;
        v165 = (float)((float)v157 * v1118.x);
        v166 = this->additiveAngularMomentum.z;
        v168 = (float)((float)((float)v152 * (float)v141) + (float)((float)x * (float)v143));
        v167 = (float)((float)((float)v155 * v1118.x) * this->additiveAngularMomentum.y);
        v170 = (float)((float)((float)v141 * (float)v150)
                     + (float)((float)((float)z * (float)v143) + (float)((float)v147 * (float)v142)));
        v171 = (float)((float)((float)v141 * (float)v151)
                     + (float)((float)((float)y * (float)v143) + (float)((float)v148 * (float)v142)));
        v169 = (float)((float)((float)*(double *)&v161 * this->additiveAngularMomentum.w)
                     - (float)((float)((float)v157 * v1118.x) * this->additiveAngularMomentum.x));
        v172 = (float)((float)((float)v149 * (float)v142) + (float)v168);
        v173 = (float)((float)((float)((float)v156 * v1118.x) * this->additiveAngularMomentum.w)
                     + (float)((float)((float)((float)v157 * v1118.x) * this->additiveAngularMomentum.z)
                             + (float)((float)*(double *)&v161 * this->additiveAngularMomentum.y)));
        v174 = (float)((float)((float)v163 * this->additiveAngularMomentum.w)
                     + (float)((float)((float)*(double *)&v161 * this->additiveAngularMomentum.z)
                             + (float)((float)((float)v156 * v1118.x) * this->additiveAngularMomentum.x)));
        v175 = (float)((float)((float)*(double *)&v161 * this->additiveAngularMomentum.x)
                     + (float)((float)((float)((float)v157 * v1118.x) * this->additiveAngularMomentum.w) + (float)v167));
        v2 = (float)((float)((float)*(double *)&v161 * this->additiveAngularMomentum.z)
                   + (float)((float)((float)v156 * v1118.x) * this->additiveAngularMomentum.x));
        *(double *)&v161 = v8[193];
        v176 = (float)-(float)((float)((float)((float)v156 * v1118.x) * this->additiveAngularMomentum.y) - (float)v169);
        v177 = v170;
        v1 = v172;
        this->additiveAngularMomentum.y = -(float)((float)((float)v163 * this->additiveAngularMomentum.x) - (float)v173);
        this->additiveAngularMomentum.z = -(float)((float)((float)v165 * (float)v164) - (float)v174);
        this->additiveAngularMomentum.x = -(float)((float)((float)v162 * (float)v166) - (float)v175);
        this->additiveAngularMomentum.w = -(float)((float)((float)v163 * (float)v166) - (float)v176);
        v178 = RandomFloat(min: *(double *)&v161, max: 5.0);
        v179 = this->additiveMomentum.y;
        v180 = this->additiveMomentum.z;
        v57 = v1108;
        this->additiveMomentum.x = (float)((float)v172 * (float)v178) + this->additiveMomentum.x;
        this->additiveMomentum.y = (float)((float)v171 * (float)v178) + (float)v179;
        this->additiveMomentum.z = (float)((float)v170 * (float)v178) + (float)v180;
      }
      else
      {
        if ( idGameTimeManager::GetGameMs(
               this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
               type: GAMETIME_SCALED) > this->nextSputterTime - 200
          && this->health > v6 )
        {
          v114 = 0;
        }
        v1 = v1103.x;
        v171 = v1103.y;
        v177 = v1103.z;
      }
      if ( v114 != 0 || value_high != 0 )
      {
        value_high = v114 != 0 ? 0 : value_high;
        HIBYTE(v1117.value) = value_high;
        TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( TreeAnimatorFromPresentable != nullptr )
        {
          decl = TreeAnimatorFromPresentable->decl;
          if ( decl != nullptr && decl != (const idDeclMD6 *)-352 )
          {
            v183 = 1.0;
            if ( this->health <= v6 && this->engineSmokeAmount > 0.40000001 )
              v183 = (float)(RandomFloat(max: (float)((float)((float)(this->engineSmokeAmount - (float)0.40000001)
                                                            * v8[222])
                                                    + (float)1.9))
                           + 1.0);
            LOBYTE(v36) = 0;
            v184 = 0;
            if ( HIDWORD(v36) != 0 )
            {
              LOBYTE(v36) = RandomInt(max: 5) + 49;
              v185 = RandomInt(min: 2, max: 5);
              v186 = v185 + RandomInt(max: 3);
              v184 = RandomInt(max: 3) + v186;
              LODWORD(v187) = RandomInt(max: 3) + v184;
              *(_QWORD *)&v1103.x = v187;
              v183 = (float)v187;
            }
            LODWORD(v1103.y) = (int)v183;
            v188 = (int)v183;
            v189 = 0;
            if ( (int)v183 > 0 )
            {
              v190 = v1104[629];
              v2 = -55.0;
              sputterParticle = this->sputterParticle;
              do
              {
                if ( this->health > v6 )
                {
                  if ( v104 >= v1104[203] )
                  {
                    if ( v104 >= 0.66600001 )
                    {
                      v194 = (float)(this->engineSmokeAmount - *(v1104 - 36));
                      v193 = 0.5;
                    }
                    else
                    {
                      v193 = 0.5;
                      v194 = (float)(this->engineSmokeAmount - (float)0.5);
                    }
                    v192 = (float)((float)v194 * (float)v193);
                  }
                  else
                  {
                    v192 = (float)((float)(this->engineSmokeAmount * v1104[164]) + (float)0.1);
                  }
                }
                else
                {
                  v192 = (float)(v1104[68] / (float)(this->engineSmokeAmount + (float)0.050000001));
                }
                v195 = 1;
                v196 = true;
                if ( HIDWORD(v36) != 0 )
                {
                  HIBYTE(v1117.value) = 0;
                }
                else if ( v192 > v6 && RandomFloat() < v192 )
                {
                  v195 = 0;
                  v196 = RandomFloat() >= 0.66600001;
                }
                LODWORD(g) = v195;
                v1138.path.list = nullptr;
                HIBYTE(v1138.path.granularity) = 0;
                v1138.path.num = (int)&v1138.path.granularity;
                v197 = (_cntlzw(v195) & 0x20) != 0;
                v1138.path.size = 20;
                if ( HIBYTE(v1117.value) != 0 )
                {
                  idStr::operator=(this: (idStr *)&v1138.path, text: "thrust_forward");
                }
                else if ( (_BYTE)v36 != 0 )
                {
                  idStr::operator=(this: (idStr *)&v1138.path, text: "smoke#");
                  *(_BYTE *)(v1138.path.num + 5) = v36;
                }
                else
                {
                  if ( v196 )
                  {
                    if ( this->health > v6 || RandomFloat() < (double)v1104[33] )
                    {
                      idStr::operator=(this: (idStr *)&v1138.path, text: "smoke#");
                      v198 = 7;
                    }
                    else
                    {
                      idStr::operator=(this: (idStr *)&v1138.path, text: "death#");
                      v198 = 4;
                    }
                  }
                  else
                  {
                    idStr::operator=(this: (idStr *)&v1138.path, text: "spark#");
                    v198 = 5;
                  }
                  v199 = (_BYTE *)(v1138.path.num + 5);
                  *v199 = RandomInt(max: v198) + 49;
                }
                if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                                        this,
                                        propName: v1135,
                                        tagName: (const char *)v1138.path.num,
                                        origin: (idVec3 *)&v1156.path,
                                        axis: &v1134) != 0 )
                {
                  while ( 1 )
                  {
                    if ( this->health <= v6 )
                    {
                      v209 = RandomFloat(min: -33.0, max: v6);
                      v200 = v1104;
                      v210 = v209;
                      v211 = RandomFloat(min: -55.0, max: v1104[51]);
                      v1119 = RandomFloat(min: -55.0, max: v200[51]);
                      v1120 = v211;
                      v1121 = v210;
                    }
                    else
                    {
                      v200 = v1104;
                      v201 = (float)(this->currentPosition.x + this->additivePosition.x);
                      HIDWORD(v202) = &this->currentPosition;
                      v203 = (float)(this->additivePosition.z + this->currentPosition.z);
                      v204 = (float)(this->additivePosition.y + this->currentPosition.y);
                      v205 = this->previousOrigin.x;
                      v206 = this->previousOrigin.z;
                      LODWORD(v1103.x) = &this->additivePosition;
                      v207 = this->previousOrigin.y;
                      LODWORD(v1103.x) = &this->currentPosition;
                      v208 = v1104[30];
                      v1119 = (float)((float)v201 - (float)v205) * v1104[30];
                      LODWORD(v1103.x) = &this->previousOrigin;
                      v1121 = (float)((float)v203 - (float)v206) * (float)v208;
                      v1120 = (float)((float)v204 - (float)v207) * (float)v208;
                    }
                    if ( HIDWORD(v36) == 0 )
                      break;
                    if ( v189 < v184 )
                    {
                      LODWORD(v202) = v189;
                      *(_QWORD *)&v1116.x = v202;
                      if ( (float)v202 == v6 )
                      {
                        v212 = *sputterParticle;
                      }
                      else
                      {
                        v213 = RandomInt(min: 1, max: 2);
                        v214 = v200[32];
                        v212 = this->sputterParticle[v213];
                        v215 = RandomFloat(min: v190, max: v214);
                        v216 = RandomFloat(min: v190, max: v1104[32]);
                        v217 = RandomFloat(min: v190, max: v1104[32]);
                        v1119 = v1119 - (float)((float)((float)v1 * (float)100.0) + (float)v217);
                        v1121 = v1121 - (float)((float)((float)v177 * (float)100.0) + (float)v215);
                        v1120 = v1120 - (float)((float)((float)v171 * (float)100.0) + (float)v216);
                      }
                      goto LABEL_239;
                    }
                    if ( RandomFloat() < 0.5 )
                      goto LABEL_237;
                    v212 = this->smokeParticle[RandomInt(max: 3)];
                    v1119 = v1119 - (float)((float)v1 * (float)100.0);
                    v1121 = v1121 - (float)((float)v177 * (float)100.0);
                    v1120 = v1120 - (float)((float)v171 * (float)100.0);
LABEL_239:
                    if ( v212 != nullptr )
                    {
                      v1118.x = NAN;
                      v220 = v1107;
                      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                                         this: (idGameTimeManager *)(*((_DWORD *)v1107 + 4398) + 504064),
                                         type: GAMETIME_SCALED);
                      v222 = *((_DWORD *)v220 + 4398);
                      v223 = GameMsPerFrame;
                      v224 = idGameTimeManager::GetGameMs(
                               this: (idGameTimeManager *)(v222 + 504064),
                               type: GAMETIME_SCALED);
                      v225 = RandomFloat();
                      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: *((idAnimator_BlendEq **)v1107 + 4398));
                      idRenderModelEffects::AddParticles(
                        this: MergeBranch,
                        particle: v212,
                        systemStartTime: v224,
                        gameMsPerFrame: v223,
                        diversity: v225,
                        origin: v227,
                        axis: (const idMat3 *)&v1156.path,
                        velocity: v1134.mat,
                        color: &v1119,
                        a10: v1057,
                        a11: v1060,
                        a12: v1061,
                        a13: v1064,
                        a14: v1065,
                        a15: (int)v1068,
                        a16: v1069,
                        a17: v1072,
                        a18: v1073,
                        a19: v1076,
                        a20: v1077,
                        a21: v1080,
                        a22: v1083,
                        a23: v1086,
                        a24: v1089,
                        a25: v1092,
                        a26: v1095,
                        a27: v1098,
                        a28: v1101[0],
                        a29: (unsigned int *)&v1118);
                      *(float *)&v36 = v1102.x;
                    }
                    LODWORD(g) = (_cntlzw(LODWORD(g)) & 0x20) != 0;
                    if ( g == 0.0 )
                      goto LABEL_242;
                  }
                  if ( g == 0.0 )
                  {
LABEL_237:
                    v219 = RandomInt(max: 2) + 1309;
                  }
                  else if ( this->health > v6 || v197 || (v218 = this->engineSmokeAmount, RandomFloat(max: 1.0) > v218) )
                  {
                    v219 = RandomInt(max: 3) + 1306;
                  }
                  else
                  {
                    v219 = RandomInt(max: 3) + 1314;
                  }
                  v212 = *((const idDeclParticle **)&this->__vftable + v219);
                  goto LABEL_239;
                }
LABEL_242:
                idStr::FreeData(this: (idStr *)&v1138.path);
                ++v189;
                ++sputterParticle;
              }
              while ( v189 < v188 );
              v8 = v1104;
              v5 = v1107;
              value_high = HIBYTE(v1117.value);
            }
          }
        }
      }
      v228 = this->engineSmokeAmount;
      v229 = 0.5;
      if ( v228 >= 0.5 )
      {
        if ( v228 > 0.5 )
        {
          if ( v228 < 1.0 )
            v229 = (float)-(float)((float)((float)(this->engineSmokeAmount - (float)0.5) * (float)0.099799998)
                                 - (float)0.050000001);
          else
            v229 = 0.000099999997;
        }
        else
        {
          v229 = 0.050000001;
        }
      }
      else if ( v228 > v6 )
      {
        v229 = (float)-(float)((float)(this->engineSmokeAmount * (float)0.89999998) - (float)0.5);
      }
      v230 = RandomFloat(min: 0.000099999997, max: v229);
      v49 = v230;
      if ( this->health <= v6 )
        v49 = (float)((float)v230 * (float)0.25);
      v231 = (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064);
      LODWORD(v1103.y) = (int)(float)((float)v49 * (float)1000.0);
      this->nextEngineSmokeTime = idGameTimeManager::GetGameMs(this: v231, type: GAMETIME_SCALED) + LODWORD(v1103.y);
      if ( HIDWORD(v36) != 0 )
      {
        LODWORD(v1103.y) = (int)(float)((float)v49 * (float)4000.0);
        v232 = v1103.y;
        if ( SLODWORD(v1103.y) < 4000 )
        {
          *(float *)&v233 = COERCE_FLOAT(RandomInt(min: 500, max: 4000));
          if ( SLODWORD(v232) <= v233 )
            v232 = *(float *)&v233;
        }
        this->nextSputterTime = idGameTimeManager::GetGameMs(
                                  this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                                  type: GAMETIME_SCALED)
                              + LODWORD(v232);
      }
      if ( value_high != 0 )
        this->nextAfterburnerSmokeTime = idGameTimeManager::GetGameMs(
                                           this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                                           type: GAMETIME_SCALED)
                                       + 1;
    }
  }
  if ( this->health <= v6 )
  {
    deathVarietyDesired = this->deathVarietyDesired;
    if ( deathVarietyDesired != DD_EXPLOSION )
    {
      if ( deathVarietyDesired == DD_SPINNING_OUT_OF_CONTROL )
      {
        if ( idGameTimeManager::GetGameMs(
               this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
               type: GAMETIME_SCALED) < this->deathDoneTime )
        {
          v235 = (float *)this->rigidPhysics.GetAxis(this: &this->rigidPhysics, a2: 0);
          v236 = this->deathThrust.z;
          v237 = this->deathThrust.x;
          v238 = (float)(v235[4] * this->deathThrust.y);
          v239 = (float)(v235[5] * this->deathThrust.y);
          v240 = v235[1];
          GetLinearVelocity = this->rigidPhysics.GetLinearVelocity;
          v242 = v235[2];
          v243 = (float)((float)(*v235 * this->deathThrust.x)
                       + (float)((float)(v235[3] * this->deathThrust.y) + (float)(v235[6] * this->deathThrust.z)));
          LODWORD(v1103.x) = &this->deathThrust;
          v244 = (float)((float)(v235[7] * (float)v236) + (float)((float)((float)v240 * (float)v237) + (float)v238));
          v245 = (float)((float)(v235[8] * (float)v236) + (float)((float)((float)v242 * (float)v237) + (float)v239));
          v246 = (float *)GetLinearVelocity(
                            this: (struct idPhysics_RigidBody *)&v1111,
                            result: (idVec3 *)&this->rigidPhysics,
                            a3: 0);
          SetLinearVelocity = this->rigidPhysics.SetLinearVelocity;
          v248 = (float)(v246[2] + (float)v245);
          v249 = (float)(v246[1] + (float)v244);
          v1146[0] = (float)v243 + *v246;
          v1146[2] = v248;
          v1146[1] = v249;
          SetLinearVelocity(this: &this->rigidPhysics, a2: (const idVec3 *)v1146, a3: 0);
          this->rigidPhysics.GetAngularVelocity(
            this: (struct idPhysics_RigidBody *)&v1105,
            result: (idVec3 *)&this->rigidPhysics,
            a3: 0);
          v250 = this->rigidPhysics.__vftable;
          *(float *)&v1105.navSpline = *(float *)&v1105.navSpline * v8[53];
          v250->SetAngularVelocity(this: &this->rigidPhysics, a2: (const idVec3 *)&v1105, a3: 0);
        }
        idEntity::RunPhysics(this);
      }
    }
    else if ( idGameTimeManager::GetGameMs(
                this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                type: GAMETIME_SCALED) >= this->deathDoneTime )
    {
      this->Hide_2(this);
    }
    return;
  }
  patrolWaypointOn = this->patrolWaypointOn;
  if ( patrolWaypointOn < 0 || patrolWaypointOn >= this->patrolWaypoints.num )
  {
    if ( this->patrolWaypoints.num <= 0 )
      return;
    this->patrolWaypointOn = 0;
    this->patrolDirection = 1;
  }
  p_goals = (idDroneSplineWaypoint ***)&this->goals;
  v253 = idEntity::GetPhysics(this: *(idEntity **)this->goals.list);
  v254 = (float *)v253->GetOrigin(this: v253, a2: 0);
  v255 = (float)(v254[1] - this->currentPosition.y);
  v256 = (float)(*v254 - this->currentPosition.x);
  a = COERCE_FLOAT(&idColor::colorWhite);
  v258 = (float)(v254[2] - this->currentPosition.z);
  v259 = v8[32];
  LODWORD(v1103.x) = &this->currentPosition;
  v1108 = COERCE_FLOAT(&idColor::colorWhite);
  if ( __fsqrts((float)((float)((float)v258 * (float)v258)
                      + (float)((float)((float)v256 * (float)v256) + (float)((float)v255 * (float)v255)))) <= v259
    && (((this->goals.num >= 0) + (this->goals.num <= 1u)) & 1) != 0 )
  {
    this->searchDirection = *this->goalSearchDirections.list;
    num = this->goals.num;
    if ( num > 0 )
    {
      this->goals.num = num - 1;
      v262 = num - 1 <= 0;
      v261 = 0;
      if ( !v262 )
      {
        v263 = 0;
        do
        {
          ++v261;
          v264 = &(*p_goals)[v263++];
          *v264 = v264[1];
        }
        while ( v261 < this->goals.num );
      }
    }
    v265 = this->goalSearchDirections.num;
    if ( v265 > 0 )
    {
      this->goalSearchDirections.num = v265 - 1;
      v262 = v265 - 1 <= 0;
      v266 = 0;
      if ( !v262 )
      {
        v267 = 0;
        do
        {
          ++v266;
          v268 = &this->goalSearchDirections.list[v267++];
          *v268 = v268[1];
        }
        while ( v266 < this->goalSearchDirections.num );
      }
    }
    v269 = idDroneSplineWaypoint::CastTo(c: **p_goals);
    if ( v269 != nullptr )
    {
      v269->lastVisitTime = idGameTimeManager::GetGameMs(
                              this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
                              type: GAMETIME_SCALED);
      if ( g_droneDebugSearching.valueInteger != 0 )
      {
        v1155.len = 0;
        v1155.baseBuffer[0] = 0;
        v1155.data = v1155.baseBuffer;
        v1155.allocedAndFlag = 20;
        idStr::Format(this: &v1155, fmt: "%d", v269->lastVisitTime);
        v270 = idEntity::GetPhysics(this: v269);
        v271 = (int)v270->GetOrigin(this: v270, a2: 0);
        g = idColor::colorWhite.g;
        v272 = *(float *)v271;
        v273 = *(float *)(v271 + 4);
        v274 = *(float *)(v271 + 8);
        a = idColor::colorWhite.a;
        v275 = *v8;
        v276 = *((_DWORD *)v5 + 4398);
        v1126 = idColor::colorWhite;
        v1105.distance = v272;
        v1105.rightDistance = v273;
        *(float *)&v1105.navSpline = v274;
        v277 = *(_DWORD *)(v276 + 4);
        LOBYTE(v1101[1]) = 0;
        (*(void (__fastcall **)(int, char *, idNavSplinePosition *, _DWORD, idColor *, int, int, _DWORD, double))(*(_DWORD *)v277 + 268))(
          a1: v277,
          a2: v1155.data,
          a3: &v1105,
          a4: *(_DWORD *)(*(_DWORD *)v277 + 268),
          a5: &v1126,
          a6: 1,
          a7: 500,
          a8: 0,
          a9: v275);
        idStr::FreeData(this: &v1155);
      }
    }
  }
  if ( this->currentPathType == DPT_SEARCH
    && idGameTimeManager::GetGameMs(this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064), type: GAMETIME_SCALED) >= this->searchNextUpdateTime )
  {
    v278 = idGameTimeManager::GetGameMs(
             this: (idGameTimeManager *)(*((_DWORD *)v5 + 4398) + 504064),
             type: GAMETIME_SCALED);
    v279 = this->goals.num;
    this->searchNextUpdateTime = v278 + 500;
    if ( v279 > 1 )
    {
      v280 = v279 - 1;
      v281 = 4 * v279 - 4;
      v282 = v279 - 1;
      do
      {
        if ( v280 >= 0 )
        {
          v283 = this->goals.num;
          if ( v280 < v283 )
          {
            this->goals.num = v283 - 1;
            v262 = v280 >= v283 - 1;
            v284 = v280;
            if ( !v262 )
            {
              v285 = v281;
              do
              {
                ++v284;
                v286 = (idDroneSplineWaypoint **)((char *)*p_goals + v285);
                v285 += 4;
                *v286 = v286[1];
              }
              while ( v284 < this->goals.num );
            }
          }
          v287 = this->goalSearchDirections.num;
          if ( v280 < v287 )
          {
            this->goalSearchDirections.num = v287 - 1;
            v262 = v280 >= v287 - 1;
            v288 = v280;
            if ( !v262 )
            {
              v289 = v281;
              do
              {
                ++v288;
                v290 = (float *)((char *)this->goalSearchDirections.list + v289);
                v289 += 4;
                *v290 = v290[1];
              }
              while ( v288 < this->goalSearchDirections.num );
            }
          }
        }
        --v280;
        v281 -= 4;
        --v282;
      }
      while ( v282 != 0 );
      ShortestPathByList = idNavSplinePathMgr::GetShortestPathByList(
                             this: (idNavSplinePathMgr *)LODWORD(this->navSplinePosition.distance),
                             start: (idNavSplinePosition *)LODWORD(this->navSplinePosition.rightDistance),
                             waypoints: (idList<idSplineWaypoint const *,5> *)__ROL4__(this->navSplinePosition.navSpline, 32),
                             path: (navSplinePath_t *)&this->goals);
      if ( ShortestPathByList == nullptr || ShortestPathByList->path.num < 1 )
        idLib::Error(fmt: "Drone '%s' could not find a path.", this->name.data);
    }
  }
  currentPathType = this->currentPathType;
  v1122 = &idColor::colorRed;
  v1124 = &idColor::colorGreen;
  if ( currentPathType == DPT_SEARCH && g_droneDebugSearching.valueInteger != 0 )
  {
    LODWORD(v1103.x) = this->goals.num;
    if ( (-LODWORD(v1103.x) & ~LODWORD(v1103.x)) < 0 )
    {
      v293 = this->currentPosition.x;
      g = this->currentPosition.y;
      v294 = 0;
      a = this->currentPosition.z;
      if ( SLODWORD(v1103.x) > 0 )
      {
        v49 = v1106;
        v295 = v1107;
        v296 = v1122;
        v297 = 0;
        while ( 1 )
        {
          v298 = (*p_goals)[v297];
          if ( this->goalSearchDirections.list[v297] <= v49 )
          {
            v309 = idEntity::GetPhysics(this: v298);
            v310 = (int)v309->GetOrigin(this: v309, a2: 0);
            *(float *)&v1110.navSpline = a;
            v301 = (idColor *)&v1138;
            a = v296->r;
            v302 = v296;
            v1110.distance = v293;
            v303 = &v1116;
            v1110.rightDistance = g;
            v305 = &v1110;
            v311 = *(float *)v310;
            v307 = (idColor *)&v1138;
            v312 = *(float *)(v310 + 4);
            g = v296->g;
            b = v296->b;
            v314 = *(float *)(v310 + 8);
            v1138.startDistance = a;
            v1116.x = v311;
            v1138.endDistance = g;
            v1138.distance = b;
            v1116.y = v312;
            v1116.z = v314;
          }
          else
          {
            v299 = idEntity::GetPhysics(this: v298);
            v300 = v299->GetOrigin(this: v299, a2: 0);
            *(float *)&v1105.navSpline = a;
            v301 = &v1126;
            a = idColor::colorGreen.r;
            v302 = &idColor::colorGreen;
            v1105.rightDistance = g;
            v303 = (idVec3 *)&v1112;
            v304 = v300->x;
            v305 = &v1105;
            v306 = v300->y;
            v307 = &v1126;
            g = idColor::colorGreen.g;
            v1105.distance = v293;
            v308 = v300->z;
            v1126.r = idColor::colorGreen.r;
            v1112 = v304;
            *(_QWORD *)&v1126.g = *(_QWORD *)&idColor::colorGreen.g;
            v1113 = v306;
            v1114 = v308;
          }
          v315 = *((_DWORD *)v295 + 4398);
          v301->a = v302->a;
          (*(void (__fastcall **)(_DWORD, idColor *, idNavSplinePosition *, idVec3 *, double))(**(_DWORD **)(v315 + 4)
                                                                                             + 180))(
            a1: *(_DWORD *)(v315 + 4),
            a2: v307,
            a3: v305,
            a4: v303,
            a5: 15.0);
          v316 = idEntity::GetPhysics(this: (*p_goals)[v297]);
          v317 = (float *)v316->GetOrigin(this: v316, a2: 0);
          v318 = this->goals.num;
          ++v294;
          ++v297;
          v319 = v317[1];
          v320 = v317[2];
          v1103.x = *v317;
          v1103.y = v319;
          v1103.z = v320;
          if ( v294 >= v318 )
            break;
          a = v1103.z;
          g = v1103.y;
          v293 = v1103.x;
        }
      }
    }
  }
  distance = this->splinePathToGoal.distance;
  v322 = v1106;
  v323 = v1107;
  LODWORD(v1116.x) = &idColor::colorBlue;
  if ( distance > 1000.0 )
  {
LABEL_348:
    v1 = v322;
    if ( this->currentPathType == DPT_SEARCH && (g = 0.0, this->goals.num > 0) )
    {
      v2 = v1123;
      HIDWORD(v36) = v1104;
      a = 0.0;
      v49 = 60.0;
      do
      {
        v350 = idDroneSplineWaypoint::CastTo(c: *(idDroneSplineWaypoint **)((char *)*p_goals + LODWORD(a)));
        v351 = v350;
        if ( v350 != nullptr )
        {
          v352 = idEntity::GetPhysics(this: v350);
          v355 = (float *)v352->GetOrigin(this: v352, a2: 0);
          v356 = this->currentPosition.y;
          v357 = v355[2];
          v358 = this->currentPosition.x;
          v359 = v355[1];
          v360 = this->currentPosition.z;
          v1118.x = *v355;
          v1118.z = v357;
          v1118.y = v359;
          LODWORD(v1103.x) = &this->currentPosition;
          v361 = (float)(v357 - (float)v360);
          v362 = (float)((float)((float)(v357 - (float)v360) * (float)(v357 - (float)v360))
                       + (float)((float)((float)(v1118.x - (float)v358) * (float)(v1118.x - (float)v358))
                               + (float)((float)(v359 - (float)v356) * (float)(v359 - (float)v356))));
          _FP11 = (float)((float)((float)((float)(v357 - (float)v360) * (float)(v357 - (float)v360))
                                + (float)((float)((float)(v1118.x - (float)v358) * (float)(v1118.x - (float)v358))
                                        + (float)((float)(v359 - (float)v356) * (float)(v359 - (float)v356))))
                        - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f7, f11, f1, f13 }
          v365 = __frsqrte(_FP7);
          v366 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v365
                                                                                               * (float)((float)v362 * (float)0.5))
                                                                                       * (float)v365)
                                                                               - (float)1.5)
                                                               * (float)v365)
                                                       * (float)((float)v362 * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v365
                                                                                       * (float)((float)v362 * (float)0.5))
                                                                               * (float)v365)
                                                                       - (float)1.5)
                                                       * (float)v365))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v365 * (float)((float)v362 * (float)0.5))
                                                       * (float)v365)
                                               - (float)1.5)
                               * (float)v365));
          v367 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v365 * (float)((float)v362 * (float)0.5)) * (float)v365) - (float)1.5) * (float)v365)
                                                                                               * (float)((float)v362 * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v365 * (float)((float)v362 * (float)0.5)) * (float)v365) - (float)1.5)
                                                                                               * (float)v365))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v365 * (float)((float)v362 * (float)0.5))
                                                                                               * (float)v365)
                                                                                       - (float)1.5)
                                                                       * (float)v365))
                                                       * (float)((float)v362 * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v365 * (float)((float)v362 * (float)0.5)) * (float)v365) - (float)1.5)
                                                                                               * (float)v365)
                                                                                       * (float)((float)v362 * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v365 * (float)((float)v362 * (float)0.5)) * (float)v365) - (float)1.5)
                                                                                       * (float)v365))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v365
                                                                                               * (float)((float)v362 * (float)0.5))
                                                                                       * (float)v365)
                                                                               - (float)1.5)
                                                               * (float)v365)))
                                       - (float)1.5)
                       * (float)v366);
          v368 = (float)((float)v367 * (float)v362);
          v369 = (float)((float)(v1118.x - (float)v358) * (float)v367);
          v370 = (float)((float)(v359 - (float)v356) * (float)v367);
          v371 = (float)((float)v361 * (float)v367);
          if ( v368 > 0.001 )
          {
            v372 = this->lastMovement.z;
            v374 = this->lastMovement.x;
            v1102.y = this->lastMovement.y;
            v373 = v1102.y;
            v1102.z = v372;
            v1102.x = v374;
            _FP3 = (float)((float)((float)(v373 * v373)
                                 + (float)((float)(v1102.x * v1102.x) + (float)(v1102.z * v1102.z)))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            v376 = (float)((float)((float)(v373 * v373)
                                 + (float)((float)(v1102.x * v1102.x) + (float)(v1102.z * v1102.z)))
                         * (float)0.5);
            __asm { fsel      f13, f3, f1, f13 }
            v378 = __frsqrte(_FP13);
            v379 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v378
                                                                                                 * (float)v376)
                                                                                         * (float)v378)
                                                                                 - (float)1.5)
                                                                 * (float)v378)
                                                         * (float)v376)
                                                 * (float)((float)-(float)((float)((float)((float)v378 * (float)v376)
                                                                                 * (float)v378)
                                                                         - (float)1.5)
                                                         * (float)v378))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v378 * (float)v376) * (float)v378) - (float)1.5)
                                 * (float)v378));
            v380 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v378 * (float)v376)
                                                                                                 * (float)v378)
                                                                                         - (float)1.5)
                                                                         * (float)v378)
                                                                 * (float)v376)
                                                         * (float)((float)-(float)((float)((float)((float)v378
                                                                                                 * (float)v376)
                                                                                         * (float)v378)
                                                                                 - (float)1.5)
                                                                 * (float)v378))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v378 * (float)v376) * (float)v378)
                                                         - (float)1.5)
                                         * (float)v378))
                         * (float)v376);
            v381 = (float)(v374 * (float)((float)-(float)((float)((float)v380 * (float)v379) - (float)1.5) * (float)v379));
            v382 = (float)((float)((float)-(float)((float)((float)v380 * (float)v379) - (float)1.5) * (float)v379)
                         * v1102.y);
            v383 = (float)((float)((float)-(float)((float)((float)v380 * (float)v379) - (float)1.5) * (float)v379) * v372);
            if ( (float)((float)((float)-(float)((float)((float)v380 * (float)v379) - (float)1.5) * (float)v379)
                       * (float)((float)(v373 * v373) + (float)((float)(v1102.x * v1102.x) + (float)(v1102.z * v1102.z)))) < 0.0099999998 )
            {
              v381 = v369;
              v382 = v370;
              v383 = v371;
            }
            v384 = (float)((float)((float)v382 * (float)v370)
                         + (float)((float)((float)v381 * (float)v369) + (float)((float)v383 * (float)v371)));
            v385 = (float)((float)((float)((float)((float)((float)((float)((float)2.0 - (float)v384) - (float)1.0)
                                                         * *(float *)(HIDWORD(v36) - 216))
                                                 + (float)((float)2.0 - (float)v384))
                                         / (float)v2)
                                 * (float)v368)
                         * *(float *)(HIDWORD(v36) - 212));
            if ( v385 > v322 && v385 < v49 )
            {
              v386 = idDroneSplineWaypoint::ScheduleDrone(
                       this: v351,
                       drone: this,
                       eta: v385,
                       a4: v354,
                       a5: v353,
                       a6: SLODWORD(v359),
                       a7: SLODWORD(v374),
                       a8: SLODWORD(v1102.y),
                       a9: SLODWORD(v372),
                       a10: v1057,
                       a11: v1060,
                       a12: v1061,
                       a13: v1064,
                       a14: v1065,
                       a15: v1068);
              if ( v386 != v322 )
              {
                if ( v1 == v322 )
                  v1 = v386;
                else
_LN2584:
                  v1 = (float)((float)((float)v386 * *(float *)(HIDWORD(v36) - 144)) + (float)v1);
              }
            }
          }
        }
        ++LODWORD(g);
        LODWORD(a) += 4;
      }
      while ( SLODWORD(g) < this->goals.num );
    }
    else
    {
      v2 = v1123;
      HIDWORD(v36) = v1104;
    }
    LODWORD(v1118.x) = &idColor::colorYellow;
    if ( g_droneDebugWaypoints.valueInteger != 0 )
    {
      v387 = idEntity::GetPhysics(this);
      v388 = (int)v387->GetOrigin(this: v387, a2: 0);
      splinePathMgr = (idVec3 *)this->splinePathMgr;
      v390 = *(float *)(v388 + 4);
      v391 = *(float *)(v388 + 8);
      v1103.x = *(float *)v388;
      v1103.y = v390;
      v1103.z = v391;
      idNavSplinePathMgr::GetWorldPosAlongPath(
        this: (idNavSplinePathMgr *)&v1105,
        result: splinePathMgr,
        splinePath: &this->splinePathToGoal,
        distance: v322);
      idNavSplinePathMgr::GetWorldPosAlongPath(
        this: (idNavSplinePathMgr *)&v1112,
        result: (idVec3 *)this->splinePathMgr,
        splinePath: &this->splinePathToGoal,
        distance: 125.0);
      idNavSplinePathMgr::GetWorldPosAlongPath(
        this: (idNavSplinePathMgr *)&v1110,
        result: (idVec3 *)this->splinePathMgr,
        splinePath: &this->splinePathToGoal,
        distance: 999.5);
      idNavSplinePathMgr::GetWorldPosAlongPath(
        this: (idNavSplinePathMgr *)&v1102,
        result: (idVec3 *)this->splinePathMgr,
        splinePath: &this->splinePathToGoal,
        distance: (float)(this->splinePathToGoal.distance - (float)0.5));
      v392 = *((_DWORD *)v323 + 4398);
      v1148[0] = v1103.x;
      r = v1124->r;
      v1148[1] = v1103.y;
      v1148[2] = v1103.z;
      v1148[3] = 15.0;
      v1126.r = r;
      v394 = v1124->b;
      v395 = v1124->a;
      v1126.g = v1124->g;
      v1126.b = v394;
      v1126.a = v395;
      (*(void (__fastcall **)(_DWORD, idColor *, float *, int, int, _DWORD))(**(_DWORD **)(v392 + 4) + 216))(
        a1: *(_DWORD *)(v392 + 4),
        a2: &v1126,
        a3: v1148,
        a4: 12,
        a5: 10,
        a6: 0);
      v1151[2] = *(float *)&v1105.navSpline;
      v1151[3] = 15.0;
      v1126 = idColor::colorYellow;
      v1151[0] = v1105.distance;
      v1151[1] = v1105.rightDistance;
      (*(void (__fastcall **)(_DWORD, idColor *, float *, int, int, _DWORD))(**(_DWORD **)(*((_DWORD *)v323 + 4398) + 4)
                                                                           + 216))(
        a1: *(_DWORD *)(*((_DWORD *)v323 + 4398) + 4),
        a2: &v1126,
        a3: v1151,
        a4: 12,
        a5: 10,
        a6: 0);
      v396 = *((_DWORD *)v323 + 4398);
      v1150[0] = v1112;
      v1126 = idColor::colorOrange;
      v1150[1] = v1113;
      v1150[2] = v1114;
      v1150[3] = 15.0;
      (*(void (__fastcall **)(_DWORD, idColor *, float *, int, int, _DWORD))(**(_DWORD **)(v396 + 4) + 216))(
        a1: *(_DWORD *)(v396 + 4),
        a2: &v1126,
        a3: v1150,
        a4: 12,
        a5: 10,
        a6: 0);
      v1149[3] = 15.0;
      v1149[0] = v1110.distance;
      v1149[1] = v1110.rightDistance;
      v1149[2] = *(float *)&v1110.navSpline;
      v1126 = idColor::colorMagenta;
      (*(void (__fastcall **)(_DWORD, idColor *, float *, int, int, _DWORD))(**(_DWORD **)(*((_DWORD *)v323 + 4398) + 4)
                                                                           + 216))(
        a1: *(_DWORD *)(*((_DWORD *)v323 + 4398) + 4),
        a2: &v1126,
        a3: v1149,
        a4: 12,
        a5: 10,
        a6: 0);
      v1147[3] = 15.0;
      v397 = *((_DWORD *)v323 + 4398);
      v398 = v1122->r;
      v399 = v1122->g;
      v1147[2] = v1102.z;
      v400 = v1122->b;
      v401 = v1122->a;
      v1147[1] = v1102.y;
      v1126.r = v398;
      v1147[0] = v1102.x;
      v1126.g = v399;
      v1126.b = v400;
      v1126.a = v401;
      (*(void (__fastcall **)(_DWORD, idColor *, float *, int, int, _DWORD))(**(_DWORD **)(v397 + 4) + 216))(
        a1: *(_DWORD *)(v397 + 4),
        a2: &v1126,
        a3: v1147,
        a4: 12,
        a5: 10,
        a6: 0);
    }
    WorldPosAlongPath = idNavSplinePathMgr::GetWorldPosAlongPath(
                          this: (idNavSplinePathMgr *)&v1111,
                          result: (idVec3 *)this->splinePathMgr,
                          splinePath: &this->splinePathToGoal,
                          distance: *(float *)(HIDWORD(v36) + 120));
    this->immediateGoalPosition.x = WorldPosAlongPath->x;
    LODWORD(v1103.x) = &this->immediateGoalPosition;
    v403 = gameLocal == nullptr;
    this->immediateGoalPosition.y = WorldPosAlongPath->y;
    this->immediateGoalPosition.z = WorldPosAlongPath->z;
    if ( v403 )
      idLib::Error(fmt: "gameLocal is NULL for drone '%s'.", this->name.data);
    idTargetCache::Clear(this: &this->worldState.targetCache);
    value = this->currentEnemy.spawnId.value;
    v405 = gameLocal;
    p_currentEnemy = &this->currentEnemy;
    LODWORD(v1103.x) = &this->currentEnemy;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v407 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v408 = idEntity::CastTo(c: v407);
      v405 = gameLocal;
      v409 = (unsigned int)v408;
    }
    else
    {
      v409 = 0;
    }
    v410 = p_currentEnemy->spawnId.value;
    v411 = (p_currentEnemy->spawnId.value & 0x1FFF) + 29755;
    LODWORD(v1103.x) = &this->currentEnemy;
    if ( *((_DWORD *)&v405->__vftable + v411) == v410 >> 13 && (v412 = v405->entities.ptr[v410 & 0x1FFF]) != nullptr )
      v413 = idEntity::CastTo(c: v412);
    else
      v413 = nullptr;
    v414 = this->GetFaction(this);
    v415 = idSpawnId::idSpawnId(this: (idSpawnId *)&v1102, ent: v413);
    v416 = idSpawnId::idSpawnId(this: &v1117, ent: this);
    v417 = _cntlzw(v409);
    idAILogic::idAILogic(
      this: &v1160,
      spawnId_: v416,
      curEnemyId_: v415,
      encounterGroup_: nullptr,
      faction_: v414,
      combatTimeoutInterval_: -1.0,
      searchTimeoutInterval_: -1.0,
      isRelaxed_: v418,
      isSearching_: v417,
      a10: (v417 & 0x20) != 0,
      a11: v1057,
      a12: v1060,
      a13: v1061,
      a14: v1064,
      a15: v1065,
      a16: (int)v1068,
      a17: v1069,
      a18: v1072,
      a19: v1073,
      a20: v1076,
      a21: v1077,
      a22: v1080,
      a23: v1083,
      a24: v1086,
      a25: v1089,
      a26: v1092,
      a27: v1095,
      a28: v1098,
      a29: v1101[0],
      a30: false);
    idAIWorldState::ResolveDeferredQueries(this: &this->worldState, gameState: &gameLocal->aiGameState, aiOwner: &v1160);
    p_aiGameState = &gameLocal->aiGameState;
    if ( gameLocal == (idGameLocal *)-1396000 )
      idLib::Error(fmt: "gameLocal->GetAIGameState() is NULL for drone '%s'.", this->name.data);
    declTrackingParms = this->declTrackingParms;
    if ( declTrackingParms == nullptr )
      idLib::Error(fmt: "drone '%s' has declTrackingParms NULL.", this->name.data);
    idAIWorldState::Update(
      this: &this->worldState,
      gameState: p_aiGameState,
      aiOwner: &v1160,
      trackingParms: declTrackingParms->parms.list);
    idEnemyTargetFilter::idEnemyTargetFilter(this: (idEnemyTargetFilter *)&v1154, minAwareness_: AIAWARE_LOST);
    v1158.__vftable = (idTargetSelector_vtbl *)&idEnemyTargetSelector::`vftable';
    idTargetList::idTargetList(this: &v1157, targetCache_: &this->worldState.targetCache);
    if ( idTargetList::FindBestTarget(this: &v1157, owner: (idAI2 *)this, filter: &v1154, selector: &v1158) >= 0
      && v1157.bestTargetIndex >= 0 )
    {
      v421 = &v1157.targetCache->targets.list[v1157.viableTargets.list[v1157.bestTargetIndex]];
      if ( v421 != nullptr )
      {
        Entity = idAIEntityState::GetEntity(this: (idAIEntityState *)v421->es);
        if ( Entity != nullptr )
        {
          LODWORD(v1103.x) = Entity->entityNumber;
          p_currentEnemy->spawnId.value = (gameLocal->spawnIds.ptr[LODWORD(v1103.x)] << 13) | LODWORD(v1103.x);
        }
        else
        {
          p_currentEnemy->spawnId.value = 0x1FFF;
        }
      }
    }
    v423 = this->currentScanEntity.spawnId.value;
    p_currentScanEntity = &this->currentScanEntity;
    LODWORD(v1103.x) = &this->currentScanEntity;
    v1102.x = 0.0;
    if ( (gameLocal->spawnIds.ptr[v423 & 0x1FFF] != v423 >> 13
       || (v425 = gameLocal->entities.ptr[v423 & 0x1FFF]) == nullptr
       || idEntity::CastTo(c: v425) == nullptr)
      && idDrone::FindAutoFocusEntity(this, bestEntity: (idAI2 **)&v1102) > 0.1 )
    {
      v426 = p_currentScanEntity->spawnId.value;
      v427 = gameLocal;
      v428 = p_currentScanEntity->spawnId.value & 0x1FFF;
      LODWORD(v1103.x) = &this->currentScanEntity;
      if ( gameLocal->spawnIds.ptr[v428] == v426 >> 13 && (v429 = gameLocal->entities.ptr[v428]) != nullptr )
      {
        v430 = idEntity::CastTo(c: v429);
        v427 = gameLocal;
      }
      else
      {
        v430 = nullptr;
      }
      v431 = v1102.x;
      if ( (idEntity *)LODWORD(v1102.x) != v430 && g_droneDisableScanning.valueInteger == 0 )
      {
        if ( LODWORD(v1102.x) != 0 )
        {
          v1103.x = *(float *)(LODWORD(v1102.x) + 492);
          v432 = (v427->spawnIds.ptr[LODWORD(v1103.x)] << 13) | LODWORD(v1103.x);
        }
        else
        {
          v432 = 0x1FFF;
        }
        v433 = this->previousFocusEntities.num;
        p_previousFocusEntities = (idList<idEntityPtr<idEntity>,58> *)&this->previousFocusEntities;
        v435 = 0;
        if ( v433 <= 0 )
          goto LABEL_406;
        v436 = 0;
        while ( p_previousFocusEntities->list[v436].spawnId.value != v432 )
        {
          ++v435;
          ++v436;
          if ( v435 >= v433 )
            goto LABEL_406;
        }
        if ( v435 < 0 )
        {
LABEL_406:
          if ( LODWORD(v1102.x) != 0 )
          {
            v1103.x = *(float *)(LODWORD(v1102.x) + 492);
            LODWORD(v1102.x) = (v427->spawnIds.ptr[LODWORD(v1103.x)] << 13) | LODWORD(v1103.x);
          }
          else
          {
            LODWORD(v1102.x) = 0x1FFF;
          }
          idList<idEntityPtr<idEntity>,58>::Append(
            this: p_previousFocusEntities,
            obj: (const idEntityPtr<idEntity> *)&v1102);
          LODWORD(v1102.x) = idGameTimeManager::GetGameMs(
                               this: (idGameTimeManager *)(*((_DWORD *)v323 + 4398) + 504064),
                               type: GAMETIME_SCALED);
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->previousFocusEntityTimes,
            obj: (encounterGroupRole_t *)&v1102);
        }
        else
        {
          this->previousFocusEntityTimes.list[v435] = idGameTimeManager::GetGameMs(
                                                        this: (idGameTimeManager *)(*((_DWORD *)v323 + 4398) + 504064),
                                                        type: GAMETIME_SCALED);
        }
        if ( v431 == 0.0 )
        {
          p_currentScanEntity->spawnId.value = 0x1FFF;
        }
        else
        {
          v1103.x = *(float *)(LODWORD(v431) + 492);
          p_currentScanEntity->spawnId.value = (gameLocal->spawnIds.ptr[LODWORD(v1103.x)] << 13) | LODWORD(v1103.x);
        }
        idDrone::SetStateSetMoveState(this, newState: 3, newMoveState: DMS_STOPPED);
      }
    }
    if ( (unsigned __int8)idDrone::StateThink(this) == 0 )
      idDrone::SetStateSetMoveState(this, newState: 0, newMoveState: DMS_STOPPED);
    _FP0 = this->currentSpeed;
    __asm { fsel      f13, f0, f0, f18 }
    v439 = v322;
    v440 = 0;
    v441 = (float)((float)_FP13 + (float)1.0);
    do
    {
      v442 = 4 * (v440 + 3052);
      *(float *)((char *)&this->__vftable + v442) = *(float *)(4 * v440 + HIDWORD(v36) - 180) * (float)v441;
      v443 = (float *)(HIDWORD(v36) - 180 + 12 - 4 * v440);
      v444 = *(float *)((char *)&this->__vftable + v442);
      if ( v444 >= v439 )
      {
        if ( v444 > (float)((float)1000.0 - *v443) )
          *(float *)((char *)&this->__vftable + v442) = (float)1000.0 - *v443;
      }
      else
      {
        *(float *)((char *)&this->__vftable + v442) = v439;
      }
      v445 = idNavSplinePathMgr::GetWorldPosAlongPath(
               this: (idNavSplinePathMgr *)&v1138,
               result: (idVec3 *)this->splinePathMgr,
               splinePath: &this->splinePathToGoal,
               distance: *(float *)((char *)&this->__vftable + v442));
      v446 = v440 - 1;
      v447 = (float *)(&this->idEventReceiver + v440);
      v448 = v447 + 3040;
      v449 = v447 + 3056;
      v447[3040] = v445->x;
      LODWORD(v1103.x) = v447 + 3056;
      v447[3041] = v445->y;
      v450 = v445->z;
      v447[3042] = v445->z;
      v451 = v447[3040];
      v452 = this->currentPosition.x;
      v453 = this->currentPosition.z;
      v454 = (float)(v447[3041] - this->currentPosition.y);
      v439 = *(float *)((char *)&this->__vftable + v442);
      v447[3057] = v447[3041] - this->currentPosition.y;
      v447[3056] = (float)v451 - (float)v452;
      v447[3058] = (float)v450 - (float)v453;
      v455 = (float)((float)v451 - (float)v452);
      _FP5 = (float)((float)((float)((float)((float)v450 - (float)v453) * (float)((float)v450 - (float)v453))
                           + (float)((float)((float)((float)v451 - (float)v452) * (float)((float)v451 - (float)v452))
                                   + (float)((float)v454 * (float)v454)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f3, f5, f6, f13 }
      v458 = (float)((float)((float)((float)((float)v450 - (float)v453) * (float)((float)v450 - (float)v453))
                           + (float)((float)((float)((float)v451 - (float)v452) * (float)((float)v451 - (float)v452))
                                   + (float)((float)v454 * (float)v454)))
                   * (float)0.5);
      v459 = __frsqrte(_FP3);
      v460 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v459 * (float)v458)
                                                                                   * (float)v459)
                                                                           - (float)1.5)
                                                           * (float)v459)
                                                   * (float)v458)
                                           * (float)((float)-(float)((float)((float)((float)v459 * (float)v458)
                                                                           * (float)v459)
                                                                   - (float)1.5)
                                                   * (float)v459))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v459 * (float)v458) * (float)v459) - (float)1.5)
                           * (float)v459));
      v461 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v459 * (float)v458)
                                                                                           * (float)v459)
                                                                                   - (float)1.5)
                                                                   * (float)v459)
                                                           * (float)v458)
                                                   * (float)((float)-(float)((float)((float)((float)v459 * (float)v458)
                                                                                   * (float)v459)
                                                                           - (float)1.5)
                                                           * (float)v459))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v459 * (float)v458) * (float)v459)
                                                   - (float)1.5)
                                   * (float)v459))
                   * (float)v458);
      v447[3056] = (float)((float)-(float)((float)((float)v461 * (float)v460) - (float)1.5) * (float)v460) * (float)v455;
      v447[3057] = (float)((float)-(float)((float)((float)v461 * (float)v460) - (float)1.5) * (float)v460) * (float)v454;
      v447[3058] = (float)((float)-(float)((float)((float)v461 * (float)v460) - (float)1.5) * (float)v460)
                 * (float)((float)v450 - (float)v453);
      if ( v440 - 1 >= 0 )
      {
        v462 = v447[3041];
        v463 = *v448;
        LODWORD(v1103.x) = v447 + 3040;
        v464 = v447[3042];
        v465 = (float *)(&this->idEventReceiver + v446);
        LODWORD(v1103.x) = v465 + 3068;
        v466 = v465[3041];
        LODWORD(v1103.x) = v465 + 3040;
        v467 = (float)((float)v463 - v465[3040]);
        v468 = (float)((float)v464 - v465[3042]);
        v465[3068] = (float)v463 - v465[3040];
        v465[3069] = (float)v462 - (float)v466;
        LODWORD(v1103.x) = v465 + 3068;
        v465[3070] = v468;
        v469 = v467;
        v470 = (float)((float)v462 - (float)v466);
        v471 = (float)((float)((float)v468 * (float)v468)
                     + (float)((float)((float)v467 * (float)v467)
                             + (float)((float)((float)v462 - (float)v466) * (float)((float)v462 - (float)v466))));
        _FP9 = (float)((float)v471 - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f7, f9, f10, f13 }
        v474 = __frsqrte(_FP7);
        v475 = (float)((float)-(float)((float)((float)((float)v474 * (float)((float)v471 * (float)0.5)) * (float)v474)
                                     - (float)1.5)
                     * (float)v474);
        v476 = (float)((float)((float)-(float)((float)((float)((float)v474 * (float)((float)v471 * (float)0.5))
                                                     * (float)v474)
                                             - (float)1.5)
                             * (float)v474)
                     * (float)((float)v471 * (float)0.5));
        v465[3069] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v474 * (float)((float)v471 * (float)0.5)) * (float)v474) - (float)1.5) * (float)v474) * (float)((float)v471 * (float)0.5))
                                                                                           * (float)v475)
                                                                                   - (float)1.5)
                                                                   * (float)v475)
                                                           * (float)((float)v471 * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)v476 * (float)v475)
                                                                           - (float)1.5)
                                                           * (float)v475))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)v476 * (float)v475) - (float)1.5) * (float)v475))
                   * (float)v470;
        v465[3068] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v474 * (float)((float)v471 * (float)0.5)) * (float)v474) - (float)1.5) * (float)v474) * (float)((float)v471 * (float)0.5))
                                                                                           * (float)v475)
                                                                                   - (float)1.5)
                                                                   * (float)v475)
                                                           * (float)((float)v471 * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)v476 * (float)v475)
                                                                           - (float)1.5)
                                                           * (float)v475))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)v476 * (float)v475) - (float)1.5) * (float)v475))
                   * (float)v469;
        v465[3070] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v474 * (float)((float)v471 * (float)0.5)) * (float)v474) - (float)1.5) * (float)v474) * (float)((float)v471 * (float)0.5))
                                                                                           * (float)v475)
                                                                                   - (float)1.5)
                                                                   * (float)v475)
                                                           * (float)((float)v471 * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)v476 * (float)v475)
                                                                           - (float)1.5)
                                                           * (float)v475))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)v476 * (float)v475) - (float)1.5) * (float)v475))
                   * (float)v468;
      }
      if ( g_droneDebugMovement.valueInteger != 0 )
      {
        if ( v440 != 0 )
        {
          if ( v440 == 1 )
          {
            v477 = v1118.x;
          }
          else if ( v440 == 2 )
          {
            v477 = *(float *)&v1124;
          }
          else
          {
            v477 = COERCE_FLOAT(&idColor::colorCyan);
            if ( v440 != 3 )
              v477 = COERCE_FLOAT(&idColor::colorLtGrey);
          }
        }
        else
        {
          v477 = *(float *)&v1122;
        }
        v478 = *(float *)(LODWORD(v477) + 4);
        v479 = *(float *)(LODWORD(v477) + 8);
        v480 = *(float *)(LODWORD(v477) + 12);
        v481 = *((_DWORD *)v448 + 2);
        v1126.r = *(float *)LODWORD(v477);
        v482 = __ROL4__(v481, 32);
        *(_QWORD *)&v1126.g = __PAIR64__(LODWORD(v478), LODWORD(v479));
        *((_QWORD *)&v483 + 1) = *(_QWORD *)v448;
        *(_QWORD *)((char *)&v483 + 4) = *(_QWORD *)(LODWORD(v477) + 8);
        v1126.a = v480;
        idDrone::DebugSphere(
          pos: *(__int64 *)((char *)&v483 + 4),
          radius: 15.0,
          lifetime: *(__int64 *)&v482,
          depthTest: SLOBYTE(v477),
          a5: 12,
          a6: 10,
          a7: false,
          a8: v1058,
          a9: v1062,
          a10: v1066,
          a11: v1070,
          a12: v1074);
        v484 = *(float *)(HIDWORD(v36) + 952);
        v485 = (float)(v449[2] * *(float *)(HIDWORD(v36) + 952));
        LODWORD(v1103.x) = v449;
        v486 = (float)(v449[1] * (float)v484);
        v487 = (float)(*v449 * (float)v484);
        v488 = idEntity::GetPhysics(this);
        v489 = (float *)v488->GetOrigin(this: v488, a2: 0);
        v490 = (float)(v489[2] + (float)v485);
        v491 = (float)(v489[1] + (float)v486);
        v1102.x = *v489 + (float)v487;
        v1102.z = v490;
        v1102.y = v491;
        v492 = idEntity::GetPhysics(this);
        v493 = v492->GetOrigin(this: v492, a2: 0);
        v494 = v493->x;
        v1105.distance = v1102.x;
        v1105.rightDistance = v1102.y;
        v495 = v493->y;
        v496 = v493->z;
        *(idColor *)&v1127.type = v1126;
        v1105.navSpline = (idNavSpline *)LODWORD(v1102.z);
        v1112 = v494;
        v1113 = v495;
        v1114 = v496;
        v323 = v1107;
        (*(void (__fastcall **)(_DWORD, idEventArg *, float *, idNavSplinePosition *, double))(**(_DWORD **)(*((_DWORD *)v1107 + 4398) + 4)
                                                                                             + 180))(
          a1: *(_DWORD *)(*((_DWORD *)v1107 + 4398) + 4),
          a2: &v1127,
          a3: &v1112,
          a4: &v1105,
          a5: 5.0);
        if ( v446 >= 0 )
        {
          v497 = *(float *)(HIDWORD(v36) + 952);
          v498 = *((_DWORD *)v323 + 4398);
          v499 = (float *)(&this->idEventReceiver + v446);
          LODWORD(v500) = v499 + 3068;
          LODWORD(v1103.x) = v499 + 3040;
          v501 = v499[3041];
          v502 = (float)(v499[3070] * (float)v497);
          v503 = (float)(v499[3069] * (float)v497);
          v504 = (float)(v499[3068] * (float)v497);
          v505 = v499[3042];
          v506 = v499[3042];
          v507 = v499[3040];
          v508 = v499[3040];
          v1134.mat[0] = *(idVec3 *)&v1126.r;
          v1134.mat[1].x = v1126.a;
          v1115.distance = v508;
          *(float *)&v1110.navSpline = (float)v505 + (float)v502;
          v1110.rightDistance = v501 + (float)v503;
          v1110.distance = (float)v504 + (float)v507;
          v1115.rightDistance = v501;
          *(float *)&v1115.navSpline = v506;
          v1103.x = v500;
          v1111 = v1110;
          (*(void (__fastcall **)(_DWORD, idMat3 *, idNavSplinePosition *, idNavSplinePosition *, double))(**(_DWORD **)(v498 + 4) + 180))(
            a1: *(_DWORD *)(v498 + 4),
            a2: &v1134,
            a3: &v1115,
            a4: &v1111,
            a5: 5.0);
        }
      }
      ++v440;
    }
    while ( v440 < 4 );
    this->aheadToAhead[3].x = this->aheadToAhead[2].x;
    this->aheadToAhead[3].y = this->aheadToAhead[2].y;
    LODWORD(v1103.x) = &this->aheadToAhead[3];
    this->aheadToAhead[3].z = this->aheadToAhead[2].z;
    if ( g_droneDebugMovement.valueInteger != 0 )
    {
      v509 = (float)(this->aheadToAhead[3].z * *(float *)(HIDWORD(v36) + 952));
      v510 = (float)(this->aheadToAhead[3].x * *(float *)(HIDWORD(v36) + 952));
      v511 = this->ahead[3].z;
      v512 = this->ahead[3].x;
      v513 = (float)(this->aheadToAhead[3].y * *(float *)(HIDWORD(v36) + 952));
      v1134.mat[0].x = idColor::colorOrange.r;
      LODWORD(v1103.x) = &this->aheadToAhead[3];
      v514 = this->ahead[3].y;
      v515 = this->ahead[3].x;
      v516 = this->ahead[3].y;
      v517 = this->ahead[3].z;
      *(float *)&v1110.navSpline = (float)v511 + (float)v509;
      v1110.distance = (float)v510 + (float)v512;
      LODWORD(v1103.x) = &this->ahead[3];
      v1110.rightDistance = (float)v514 + (float)v513;
      *(_QWORD *)&v1134.mat[0].y = *(_QWORD *)&idColor::colorOrange.g;
      v1134.mat[1].x = idColor::colorOrange.a;
      v1115 = v1110;
      v1111.distance = v515;
      v1111.rightDistance = v516;
      *(float *)&v1111.navSpline = v517;
      (*(void (__fastcall **)(_DWORD, idMat3 *, idNavSplinePosition *, idNavSplinePosition *, _DWORD, int, _DWORD, double))(**(_DWORD **)(*((_DWORD *)v323 + 4398) + 4) + 180))(
        a1: *(_DWORD *)(*((_DWORD *)v323 + 4398) + 4),
        a2: &v1134,
        a3: &v1111,
        a4: &v1115,
        a5: *((_DWORD *)v323 + 4398),
        a6: 10,
        a7: 0,
        a8: 5.0);
    }
    v518 = (float)(this->aheadToAhead[1].y * this->aheadToAhead[0].y);
    v519 = this->aheadToAhead[1].z;
    v520 = this->aheadToAhead[0].z;
    slowForPlayer = this->slowForPlayer;
    v522 = this->aheadToAhead[1].x;
    LODWORD(v1103.x) = &this->aheadToAhead[1];
    v523 = this->aheadToAhead[0].x;
    LODWORD(v1103.x) = &this->aheadToAhead[2];
    v524 = *(float *)(HIDWORD(v36) + 980);
    LODWORD(v1103.x) = &this->aheadToAhead[1];
    LODWORD(v36) = 0;
    this->dot0to1to2 = (float)((float)v522 * (float)v523) + (float)((float)((float)v519 * (float)v520) + (float)v518);
    this->dot1to2to3 = (float)(this->aheadToAhead[1].x * this->aheadToAhead[2].x)
                     + (float)((float)(this->aheadToAhead[2].z * this->aheadToAhead[1].z)
                             + (float)(this->aheadToAhead[2].y * this->aheadToAhead[1].y));
    if ( slowForPlayer )
    {
      for ( m = 0; m < 6; ++m )
      {
        v526 = idGameLocal::GetPlayer(this: gameLocal, i: m);
        v527 = &v526->idActor;
        if ( v526 != nullptr )
        {
          PlayerAvoidanceDistance = idDrone::GetPlayerAvoidanceDistance(this, player: v526);
          if ( PlayerAvoidanceDistance < v524 )
          {
            v524 = PlayerAvoidanceDistance;
            if ( PlayerAvoidanceDistance > 1000.0 )
              v529 = PlayerAvoidanceDistance < *(float *)(HIDWORD(v36) + 980)
                   ? (float)-(float)((float)((float)((float)PlayerAvoidanceDistance - (float)1000.0)
                                           * (float)0.00049499999)
                                   - (float)1.0)
                   : 0.0099999998;
            else
              v529 = 1.0;
            v530 = idEntity::GetPhysics(this);
            v531 = (float *)v530->GetOrigin(this: v530, a2: 0);
            v532 = idEntity::GetPhysics(this: v527);
            v533 = (float *)v532->GetOrigin(this: v532, a2: 0);
            v534 = v531[1];
            v535 = *v531;
            *(float *)&v1110.navSpline = v322;
            v536 = (float)(v533[1] - (float)v534);
            v1110.distance = *v533 - (float)v535;
            v1110.rightDistance = v536;
            if ( idVec3::NormalizeFast(this: (idVec3 *)&v1110) > 0.001 )
            {
              v537 = (float)(this->goalAvoidanceOffset.z + (float)v529);
              v538 = (float)-(float)((float)(v1110.distance * (float)v529) - this->goalAvoidanceOffset.x);
              this->goalAvoidanceOffset.y = -(float)((float)(v1110.rightDistance * (float)v529)
                                                   - this->goalAvoidanceOffset.y);
              this->goalAvoidanceOffset.z = v537;
              this->goalAvoidanceOffset.x = v538;
            }
          }
        }
      }
    }
    this->nearestPlayerDistance = (float)(this->nearestPlayerDistance * *(float *)(HIDWORD(v36) - 12))
                                + (float)((float)v524 * (float)0.050000012);
    DesiredFacing = (float *)idDrone::GetDesiredFacing(this: (idDrone *)&v1138, result: (idVec3 *)this);
    v540 = *DesiredFacing;
    this->desiredFacing.x = *DesiredFacing;
    p_desiredFacing = &this->desiredFacing;
    LODWORD(v1103.x) = &this->desiredFacing;
    v542 = DesiredFacing[1];
    this->desiredFacing.y = DesiredFacing[1];
    this->desiredFacing.z = DesiredFacing[2];
    _FP2 = (float)((float)((float)((float)v540 * (float)v540) + (float)((float)v542 * (float)v542))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f1, f2, f3, f13 }
    v545 = __frsqrte(_FP1);
    v546 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v545
                                                                                         * (float)((float)((float)((float)v540 * (float)v540) + (float)((float)v542 * (float)v542))
                                                                                                 * (float)0.5))
                                                                                 * (float)v545)
                                                                         - (float)1.5)
                                                         * (float)v545)
                                                 * (float)((float)((float)((float)v540 * (float)v540)
                                                                 + (float)((float)v542 * (float)v542))
                                                         * (float)0.5))
                                         * (float)((float)-(float)((float)((float)((float)v545
                                                                                 * (float)((float)((float)((float)v540 * (float)v540)
                                                                                                 + (float)((float)v542 * (float)v542))
                                                                                         * (float)0.5))
                                                                         * (float)v545)
                                                                 - (float)1.5)
                                                 * (float)v545))
                                 - (float)1.5)
                 * (float)((float)-(float)((float)((float)((float)v545
                                                         * (float)((float)((float)((float)v540 * (float)v540)
                                                                         + (float)((float)v542 * (float)v542))
                                                                 * (float)0.5))
                                                 * (float)v545)
                                         - (float)1.5)
                         * (float)v545));
    v547 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v545 * (float)((float)((float)((float)v540 * (float)v540) + (float)((float)v542 * (float)v542)) * (float)0.5)) * (float)v545) - (float)1.5)
                                                                                         * (float)v545)
                                                                                 * (float)((float)((float)((float)v540 * (float)v540)
                                                                                                 + (float)((float)v542 * (float)v542))
                                                                                         * (float)0.5))
                                                                         * (float)((float)-(float)((float)((float)((float)v545 * (float)((float)((float)((float)v540 * (float)v540) + (float)((float)v542 * (float)v542)) * (float)0.5)) * (float)v545)
                                                                                                 - (float)1.5)
                                                                                 * (float)v545))
                                                                 - (float)1.5)
                                                 * (float)((float)-(float)((float)((float)((float)v545
                                                                                         * (float)((float)((float)((float)v540 * (float)v540) + (float)((float)v542 * (float)v542))
                                                                                                 * (float)0.5))
                                                                                 * (float)v545)
                                                                         - (float)1.5)
                                                         * (float)v545))
                                         * (float)((float)((float)((float)v540 * (float)v540)
                                                         + (float)((float)v542 * (float)v542))
                                                 * (float)0.5))
                                 * (float)v546)
                         - (float)1.5);
    this->desiredFacing.x = (float)v540 * (float)((float)v547 * (float)v546);
    this->desiredFacing.y = (float)v542 * (float)((float)v547 * (float)v546);
    if ( (float)((float)((float)v547 * (float)v546)
               * (float)((float)((float)v540 * (float)v540) + (float)((float)v542 * (float)v542))) < 0.000099999997 )
    {
      v548 = this->currentFacing.y;
      p_desiredFacing->x = this->currentFacing.x;
      this->desiredFacing.y = v548;
    }
    v549 = this->desiredFacing.z;
    if ( v549 >= -1.0 )
    {
      if ( v549 > 1.0 )
        this->desiredFacing.z = 1.0;
    }
    else
    {
      this->desiredFacing.z = -1.0;
    }
    allowFacingChanges = this->allowFacingChanges;
    v551 = *(float *)(HIDWORD(v36) - 76);
    if ( allowFacingChanges < 1.0 )
    {
      v552 = this->allowFacingChanges;
      if ( allowFacingChanges >= v322 )
      {
        if ( allowFacingChanges > 1.0 )
          v552 = 1.0;
      }
      else
      {
        v552 = v322;
      }
      this->allowFacingChanges = this->allowFacingChanges + *(float *)(HIDWORD(v36) + 272);
      v551 = (float)((float)1.0 - (float)((float)v552 * (float)0.040000021));
      if ( this->allowFacingChanges > 1.0 )
        this->allowFacingChanges = 1.0;
    }
    p_currentFacing = &this->currentFacing;
    _FP0 = (float)((float)(p_desiredFacing->x * this->currentFacing.y)
                 - (float)(this->desiredFacing.y * this->currentFacing.x));
    if ( _FP0 > -0.2
      && _FP0 < *(float *)(HIDWORD(v36) + 656)
      && (float)((float)(this->desiredFacing.y * this->currentFacing.y)
               + (float)(p_desiredFacing->x * this->currentFacing.x)) < v322 )
    {
      __asm { fsel      f0, f0, f7, f8 }
    }
    v1144.x = v322;
    v1144.y = v322;
    v1144.z = 1.0;
    v1102.x = (float)((float)1.0 - (float)v551) * (float)_FP0;
    idMat3::idMat3(this: &v1153, axis: &v1144, angle: (const idTypesafeNumber<float,enum RadiansUnique_t> *)&v1102);
    v555 = this->currentFacing.y;
    v556 = (float)(this->currentFacing.y * v1153.mat[1].z);
    LODWORD(v1103.x) = &this->currentFacing;
    v557 = p_currentFacing->x;
    LODWORD(v1103.x) = &this->currentFacing;
    v558 = this->currentFacing.z;
    v559 = (float)((float)((float)v557 * v1153.mat[0].x) + (float)((float)v555 * v1153.mat[1].x));
    v560 = (float)((float)((float)v557 * v1153.mat[0].z) + (float)v556);
    v561 = (float)((float)((float)v557 * v1153.mat[0].y) + (float)((float)v555 * v1153.mat[1].y));
    v562 = v1153.mat[2].z;
    v563 = v1153.mat[2].y;
    this->currentFacing.x = (float)(this->currentFacing.z * v1153.mat[2].x) + (float)v559;
    this->currentFacing.z = (float)((float)v558 * (float)v562) + (float)v560;
    this->currentFacing.y = (float)((float)v558 * (float)v563) + (float)v561;
    this->currentFacing.z = (float)(this->currentFacing.z * (float)v551)
                          + (float)((float)((float)1.0 - (float)v551) * this->desiredFacing.z);
    v564 = p_currentFacing->x;
    _FP8 = (float)((float)((float)(this->currentFacing.x * this->currentFacing.x)
                         + (float)(this->currentFacing.y * this->currentFacing.y))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f6, f8, f9, f0 }
    v567 = __frsqrte(_FP6);
    v568 = (float)((float)-(float)((float)((float)((float)v567
                                                 * (float)((float)((float)(this->currentFacing.x * this->currentFacing.x)
                                                                 + (float)(this->currentFacing.y * this->currentFacing.y))
                                                         * (float)0.5))
                                         * (float)v567)
                                 - (float)1.5)
                 * (float)v567);
    v569 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v567
                                                                                 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x)
                                                                                                 + (float)(p_currentFacing->y * p_currentFacing->y))
                                                                                         * (float)0.5))
                                                                         * (float)v567)
                                                                 - (float)1.5)
                                                 * (float)v567)
                                         * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x)
                                                         + (float)(p_currentFacing->y * p_currentFacing->y))
                                                 * (float)0.5))
                                 * (float)((float)-(float)((float)((float)((float)v567
                                                                         * (float)((float)((float)(p_currentFacing->x
                                                                                                 * p_currentFacing->x)
                                                                                         + (float)(p_currentFacing->y
                                                                                                 * p_currentFacing->y))
                                                                                 * (float)0.5))
                                                                 * (float)v567)
                                                         - (float)1.5)
                                         * (float)v567))
                         - (float)1.5);
    v570 = (float)((float)-(float)((float)((float)((float)((float)v569 * (float)v568)
                                                 * (float)((float)((float)(this->currentFacing.x * this->currentFacing.x)
                                                                 + (float)(this->currentFacing.y * this->currentFacing.y))
                                                         * (float)0.5))
                                         * (float)((float)v569 * (float)v568))
                                 - (float)1.5)
                 * (float)((float)v569 * (float)v568));
    this->currentFacing.y = this->currentFacing.y
                          * (float)((float)-(float)((float)((float)((float)((float)v569 * (float)v568)
                                                                  * (float)((float)((float)(this->currentFacing.x
                                                                                          * this->currentFacing.x)
                                                                                  + (float)(this->currentFacing.y
                                                                                          * this->currentFacing.y))
                                                                          * (float)0.5))
                                                          * (float)((float)v569 * (float)v568))
                                                  - (float)1.5)
                                  * (float)((float)v569 * (float)v568));
    p_currentFacing->x = (float)v564 * (float)v570;
    v571 = this->currentState.val;
    if ( (unsigned int)v571 > DS_RETREATING )
    {
      this->currentState.val = DS_WAITING;
    }
    else if ( v571 == DS_SCANNING )
    {
      if ( this->emergencyBrakeScaler > (double)*(float *)(HIDWORD(v36) - 120) )
        this->emergencyBrakeScaler = *(float *)(HIDWORD(v36) - 120);
      DesiredSpeedForMoving = 0.1;
LABEL_475:
      overrideMaxDesiredSpeed = this->overrideMaxDesiredSpeed;
      this->desiredSpeed = DesiredSpeedForMoving;
      if ( overrideMaxDesiredSpeed != v322 && DesiredSpeedForMoving > overrideMaxDesiredSpeed )
        this->desiredSpeed = overrideMaxDesiredSpeed;
      if ( v1125 < 0.89999998
        && this->desiredSpeed > v2
        && this->desiredSpeed > (double)(float)((float)((float)((float)v57 - (float)v2) * v1125) + (float)v2) )
      {
        this->desiredSpeed = (float)((float)((float)v57 - (float)v2) * v1125) + (float)v2;
      }
      v574 = (float)((float)(1.0 - this->outOfControl) * this->desiredSpeed);
      this->desiredSpeed = (float)(1.0 - this->outOfControl) * this->desiredSpeed;
      if ( v574 >= 0.0099999998 )
      {
        if ( v574 > v57 )
          this->desiredSpeed = v57;
      }
      else
      {
        this->desiredSpeed = 0.0099999998;
      }
      v575 = this->desiredSpeedMultiplier;
      v576 = 0.25;
      if ( v575 < 0.25 || (v576 = 2.0, v575 > 2.0) )
        this->desiredSpeedMultiplier = v576;
      v577 = this->desiredSpeedMultiplier;
      if ( v577 != 1.0 )
      {
        if ( v577 >= 1.0 )
        {
          v578 = this->currentFacing.y;
          v579 = this->toAhead[0].x;
          v1103.x = p_currentFacing->x;
          v1103.z = v322;
          v1103.y = v578;
          v580 = this->toAhead[0].y;
          v1102.z = v322;
          v1102.x = v579;
          v1102.y = v580;
          idVec3::NormalizeFast(this: &v1103);
          idVec3::NormalizeFast(this: &v1102);
          if ( (float)((float)(v1102.x * v1103.x) + (float)((float)(v1102.z * v1103.z) + (float)(v1103.y * v1102.y))) > v322 )
            this->desiredSpeed = (float)((float)((float)((float)v577 - (float)1.0)
                                               * (float)((float)(v1102.x * v1103.x)
                                                       + (float)((float)(v1102.z * v1103.z) + (float)(v1103.y * v1102.y))))
                                       + (float)1.0)
                               * this->desiredSpeed;
        }
        else
        {
          this->desiredSpeed = this->desiredSpeedMultiplier * this->desiredSpeed;
        }
      }
      if ( this->currentSpeed > (double)v1137
        && this->desiredSpeed > (double)v1136
        && this->dot1to2to3 < (double)*(float *)(HIDWORD(v36) + 512) )
      {
        this->desiredSpeed = -(float)((float)((float)(this->desiredSpeed - v1136) * (float)1.5) - this->desiredSpeed);
      }
      v581 = (float)(this->lowerNoseWhenAccelerating + *(float *)(HIDWORD(v36) + 272));
      this->lowerNoseWhenAccelerating = this->lowerNoseWhenAccelerating + *(float *)(HIDWORD(v36) + 272);
      if ( v581 > 1.0 )
        this->lowerNoseWhenAccelerating = 1.0;
      allowSpeedChanges = this->allowSpeedChanges;
      v583 = *(float *)(HIDWORD(v36) - 8);
      v1103.x = 0.0099999905;
      if ( allowSpeedChanges < 1.0 )
      {
        v584 = allowSpeedChanges;
        if ( allowSpeedChanges >= v322 )
        {
          if ( allowSpeedChanges > 1.0 )
            v584 = 1.0;
        }
        else
        {
          v584 = v322;
        }
        v585 = (float)((float)allowSpeedChanges + *(float *)(HIDWORD(v36) + 804));
        this->allowSpeedChanges = (float)allowSpeedChanges + *(float *)(HIDWORD(v36) + 804);
        v583 = (float)((float)1.0 - (float)((float)v584 * (float)0.0099999905));
        if ( v585 > 1.0 )
          this->allowSpeedChanges = 1.0;
      }
      if ( this->desiredSpeed > (double)this->currentSpeed )
      {
        v586 = this->currentFacing.y;
        LODWORD(v1102.x) = &this->currentFacing;
        v587 = this->desiredFacing.y;
        LODWORD(v1102.x) = &this->desiredFacing;
        v588 = (float)((float)(this->currentFacing.x * this->desiredFacing.x)
                     + (float)((float)(this->currentFacing.z * this->desiredFacing.z)
                             + (float)((float)v586 * (float)v587)));
        if ( v588 > v322 )
        {
          if ( v588 < *(float *)(HIDWORD(v36) - 12) )
          {
            if ( v588 > v322 )
              v583 = (float)((float)((float)((float)((float)v583 - (float)1.0) * (float)v588) * (float)1.0526316)
                           + (float)1.0);
            else
              v583 = 1.0;
          }
        }
        else if ( v588 > -0.94999999 )
        {
          if ( v588 < -0.25 )
            v583 = (float)((float)((float)((float)((float)1.0 - (float)v583) * (float)((float)v588 - (float)-0.94999999))
                                 * (float)1.4285715)
                         + (float)v583);
          else
            v583 = 1.0;
        }
      }
      startDistance = this->splinePathToGoal.startDistance;
      v1140.path.list = nullptr;
      endDistance = this->splinePathToGoal.endDistance;
      v1140.path.listStatic = 0;
      v591 = this->splinePathToGoal.distance;
      rightDelta = this->splinePathToGoal.rightDelta;
      v1140.startDistance = startDistance;
      LODWORD(v1102.x) = &this->splinePathToGoal;
      v1140.endDistance = endDistance;
      v1140.distance = v591;
      v1140.rightDelta = rightDelta;
      idList<navSplinePath_t::path_t,5>::operator=(this: &v1140.path, other: &this->splinePathToGoal.path);
      navSplinePath_t::Step(this: &v1140, stepdist: this->aheadDistance[3]);
      navSplinePath_t::GetStartPathPos(this: &v1156, result: (idNavSplinePosition *)&v1140);
      SplineWidth = idNavSplinePosition::GetSplineWidth(this: (idNavSplinePosition *)&v1156, dist: -1.0);
      v594 = 1.0;
      v595 = 0.5;
      if ( SplineWidth < *(float *)(HIDWORD(v36) - 156) )
      {
        if ( SplineWidth > 1.0 )
          v596 = (float)((float)((float)((float)SplineWidth - 1.0) * (float)0.030303031) + 0.5);
        else
          v596 = 0.5;
        this->desiredSpeed = (float)v596 * this->desiredSpeed;
      }
      nearestPlayerDistance = this->nearestPlayerDistance;
      v598 = *(float *)(HIDWORD(v36) + 512);
      if ( nearestPlayerDistance < *(float *)(HIDWORD(v36) + 980) )
      {
        v599 = 0.0099999998;
        if ( this->desiredSpeed > 0.0099999998 )
        {
          if ( nearestPlayerDistance > 1000.0 )
            v599 = (float)((float)((float)((float)(this->desiredSpeed - 0.0099999998)
                                         * (float)(this->nearestPlayerDistance - (float)1000.0))
                                 * *(float *)(HIDWORD(v36) + 116))
                         + 0.0099999998);
          emergencyBrakeScaler = this->emergencyBrakeScaler;
          this->desiredSpeed = v599;
          if ( emergencyBrakeScaler > v598 )
            this->emergencyBrakeScaler = v598;
        }
      }
      if ( g_droneStopForAI.valueInteger != 0 )
      {
        if ( idGameTimeManager::GetGameMs(
               this: (idGameTimeManager *)(*((_DWORD *)v323 + 4398) + 504064),
               type: GAMETIME_SCALED) <= this->nearestForwardAiTime )
        {
          v601 = this->nearestForwardAi.spawnId.value;
          LODWORD(v1102.x) = &this->nearestForwardAi;
          if ( gameLocal->spawnIds.ptr[v601 & 0x1FFF] == v601 >> 13 )
          {
            v602 = gameLocal->entities.ptr[v601 & 0x1FFF];
            if ( v602 != nullptr )
            {
              v603 = idEntity::CastTo(c: v602);
              v604 = v603;
              if ( v603 != nullptr )
              {
                v605 = idEntity::GetPhysics(this: v603);
                v606 = (float *)v605->GetOrigin(this: v605, a2: 0);
                v607 = idEntity::GetPhysics(this);
                v608 = (float *)v607->GetOrigin(this: v607, a2: 0);
                v609 = (float)(v606[1] - v608[1]);
                v610 = (float)(v606[2] - v608[2]);
                v611 = __fsqrts((float)((float)((float)v610 * (float)v610)
                                      + (float)((float)((float)(*v606 - *v608) * (float)(*v606 - *v608))
                                              + (float)((float)v609 * (float)v609))));
                if ( v611 < 500.0 )
                {
                  v612 = idEntity::GetPhysics(this);
                  v613 = (float *)v612->GetOrigin(this: v612, a2: 0);
                  v614 = idEntity::GetPhysics(this: v604);
                  v615 = (float *)v614->GetOrigin(this: v614, a2: 0);
                  v616 = (float)(v615[2] - v613[2]);
                  v617 = v613[1];
                  v618 = this->lastMovement.z;
                  LODWORD(v1102.x) = &this->lastMovement;
                  if ( (float)((float)((float)(*v615 - *v613) * this->lastMovement.x)
                             + (float)((float)(this->lastMovement.y * (float)(v615[1] - (float)v617))
                                     + (float)((float)v618 * (float)v616))) >= v322 )
                  {
                    if ( v611 > *(float *)(HIDWORD(v36) + 972) )
                      v619 = (float)((float)((float)((float)v611 - *(float *)(HIDWORD(v36) + 972)) * (float)0.0039996002)
                                   + 0.000099999997);
                    else
                      v619 = 0.000099999997;
                    this->desiredSpeed = (float)v619 * this->desiredSpeed;
                  }
                }
              }
            }
          }
        }
        else
        {
          this->nearestForwardAi.spawnId.value = 0x1FFF;
          LODWORD(v1102.x) = &this->nearestForwardAi;
        }
        v598 = *(float *)(HIDWORD(v36) + 512);
        v594 = 1.0;
        v595 = 0.5;
      }
      currentSpeed = this->currentSpeed;
      desiredSpeed = this->desiredSpeed;
      v622 = (float)(this->currentSpeed - this->desiredSpeed);
      v623 = *(float *)(HIDWORD(v36) - 112);
      if ( v622 > v623 || desiredSpeed < 0.1 && currentSpeed > v595 )
      {
        if ( v622 > v623 )
          v624 = v622 < 15.0
               ? (float)-(float)((float)((float)((float)(this->currentSpeed - this->desiredSpeed)
                                               - *(float *)(HIDWORD(v36) - 112))
                                       * (float)0.001333332)
                               - *(float *)(HIDWORD(v36) - 8))
               : v598;
        else
          v624 = *(float *)(HIDWORD(v36) - 8);
        if ( v624 < this->emergencyBrakeScaler )
          this->emergencyBrakeScaler = v624;
      }
      if ( this->obstacleAvoidanceMaxSpeed < desiredSpeed )
      {
        v625 = *(float *)(HIDWORD(v36) - 116);
        v626 = this->emergencyBrakeScaler;
        this->desiredSpeed = this->obstacleAvoidanceMaxSpeed;
        if ( v626 > v625 )
          this->emergencyBrakeScaler = v625;
      }
      v627 = this->emergencyBrakeScaler;
      if ( v627 < v594 )
      {
        if ( this->desiredSpeed < currentSpeed )
          v583 = (float)(this->emergencyBrakeScaler * (float)v583);
        v628 = (float)((float)currentSpeed - this->desiredSpeed);
        if ( v628 > 0.1 )
        {
          if ( v628 < v594 )
            v629 = (float)((float)((float)((float)((float)currentSpeed - this->desiredSpeed) - (float)0.1)
                                 * (float)1.1111112)
                         + (float)v594);
          else
            v629 = 2.0;
        }
        else
        {
          v629 = v594;
        }
        _FP10 = (float)(this->particlesMultiplier - (float)v629);
        __asm { fsel      f7, f10, f11, f13 }
        this->particlesMultiplier = _FP7;
        if ( v628 > 0.1 )
        {
          if ( v628 < v594 )
            v632 = (float)((float)((float)v628 - (float)0.1) * (float)33.333332);
          else
            v632 = *(float *)(HIDWORD(v36) - 88);
        }
        else
        {
          v632 = v322;
        }
        this->addedParticleMovement = v632;
        this->emergencyBrakeScaler = (float)v627 + (float)0.00019999999;
        if ( (float)((float)v627 + (float)0.00019999999) > v594 )
          this->emergencyBrakeScaler = v594;
        if ( this->lowerNoseWhenAccelerating > v595 )
          this->lowerNoseWhenAccelerating = v595;
      }
      v633 = this->desiredSpeed;
      this->obstacleAvoidanceMaxSpeed = this->obstacleAvoidanceMaxSpeed + (float)0.1;
      if ( v1 != v322 )
      {
        if ( v1 >= -1.0 )
        {
          if ( v1 > v594 )
            v1 = v594;
        }
        else
        {
          v1 = -1.0;
        }
        v633 = (float)((float)((float)((float)v1 * *(float *)(HIDWORD(v36) - 144)) + (float)v594) * (float)v633);
      }
      if ( v633 <= (float)(this->currentSpeed + *(float *)(HIDWORD(v36) + 996)) )
        v634 = (float)((float)((float)((float)v594 - (float)v583) * (float)v633)
                     + (float)((float)v583 * this->currentSpeed));
      else
        v634 = (float)((float)((float)((float)v594 - (float)v583)
                             * (float)(this->currentSpeed + *(float *)(HIDWORD(v36) + 996)))
                     + (float)((float)v583 * this->currentSpeed));
      v635 = this->currentState.val;
      this->currentSpeed = v634;
      if ( (unsigned int)v635 > DS_RETREATING )
      {
        this->currentState.val = DS_WAITING;
      }
      else if ( v635 == DS_SCANNING )
      {
        DesiredRollForMoving = v322;
        goto LABEL_585;
      }
      DesiredRollForMoving = idDrone::GetDesiredRollForMoving(this);
LABEL_585:
      v637 = this->currentSpeed;
      this->desiredRoll = DesiredRollForMoving;
      if ( v637 >= v2 )
      {
        v638 = (float)-(float)((float)((float)((float)v637 / (float)v2) * (float)0.019999981) - (float)v594);
        if ( v638 < *(float *)(HIDWORD(v36) - 12) )
        {
          v638 = *(float *)(HIDWORD(v36) - 12);
LABEL_590:
          allowRollChanges = this->allowRollChanges;
          if ( allowRollChanges < v594 )
          {
            v640 = (float)(this->allowRollChanges + (float)0.050000001);
            this->allowRollChanges = this->allowRollChanges + (float)0.050000001;
            v638 = (float)((float)v594 - (float)((float)((float)v594 - (float)v638) * (float)allowRollChanges));
            if ( v640 > v594 )
              this->allowRollChanges = v594;
          }
          v641 = __fabs(this->additiveFacing.w);
          v642 = __fabs(this->additiveAngularMomentum.w);
          outOfControl = this->outOfControl;
          v644 = *(float *)(HIDWORD(v36) + 88);
          v645 = *(float *)(HIDWORD(v36) + 96);
          this->currentRoll = (float)((float)((float)v594 - (float)v638) * this->desiredRoll)
                            + (float)(this->currentRoll * (float)v638);
          v646 = (float)((float)((float)((float)v594 - (float)v641) * (float)v644) + (float)outOfControl);
          this->outOfControl = v646;
          v647 = (float)((float)((float)((float)((float)v594 - (float)v642) * (float)0.050000001) + (float)v646)
                       - (float)v645);
          this->outOfControl = (float)((float)((float)((float)v594 - (float)v642) * (float)0.050000001) + (float)v646)
                             - (float)v645;
          if ( v647 >= v322 )
          {
            if ( v647 > v594 )
              this->outOfControl = v594;
          }
          else
          {
            this->outOfControl = v322;
          }
          p_navSplinePosition = &this->navSplinePosition;
          v649 = (float)(idNavSplinePosition::GetSplineWidth(this: &this->navSplinePosition, dist: -1.0)
                       - *(float *)(HIDWORD(v36) + 768));
          v650 = 1.0;
          if ( v649 >= 1.0 )
          {
            v651 = *(float *)(HIDWORD(v36) + 952);
            if ( v649 >= v651 )
              goto LABEL_601;
          }
          else
          {
            v649 = 1.0;
          }
          v651 = v649;
LABEL_601:
          v652 = this->averageAvoidanceOffset.z;
          v653 = this->goalAvoidanceOffset.z;
          LODWORD(v1102.x) = &this->averageAvoidanceOffset;
          v654 = this->averageAvoidanceOffset.x;
          LODWORD(v1102.x) = &this->goalAvoidanceOffset;
          v655 = this->goalAvoidanceOffset.x;
          v656 = this->goalAvoidanceOffset.y;
          v657 = this->averageAvoidanceOffset.y;
          v658 = v653;
          v659 = v652;
          LODWORD(v1102.x) = &this->averageAvoidanceOffset;
          if ( v652 > v653 )
          {
            v660 = *(float *)(HIDWORD(v36) + 68);
            v661 = 0.0049999952;
          }
          else
          {
            v660 = *(float *)(HIDWORD(v36) - 120);
            v661 = 0.014999986;
          }
          v662 = (float)((float)v659 * (float)v660);
          v663 = (float)((float)v654 * (float)v660);
          v664 = (float)((float)v657 * (float)v660);
          v665 = (float)((float)v655 * (float)v661);
          v666 = (float)((float)v656 * (float)v661);
          LODWORD(v1102.x) = &this->averageAvoidanceOffset;
          v667 = (float)((float)v658 * (float)v661);
          v668 = *(float *)(HIDWORD(v36) + 812);
          LODWORD(v1102.x) = &this->bobGoal;
          v669 = (float)((float)v663 + (float)v665);
          v670 = *(float *)(HIDWORD(v36) + 128);
          this->averageAvoidanceOffset.y = (float)v664 + (float)v666;
          this->averageAvoidanceOffset.z = (float)v662 + (float)v667;
          this->averageAvoidanceOffset.x = v669;
          v671 = (float)((float)v649 * (float)v668);
          this->goalAvoidanceOffset = DEFAULT_GOAL_AVOIDANCE_OFFSET;
          v672 = (float)(this->bobGoal.x * (float)v651);
          v674 = (float)((float)(this->bobGoal.z * (float)v651) + (float)(this->averageAvoidanceOffset.z * (float)v670));
          v673 = (float)((float)(this->bobGoal.y * (float)v651) + (float)(this->averageAvoidanceOffset.y * (float)v670));
          v675 = (float)((float)v672 + (float)(this->averageAvoidanceOffset.x * (float)v670));
          v676 = __fsqrts((float)((float)((float)v674 * (float)v674)
                                + (float)((float)((float)v675 * (float)v675) + (float)((float)v673 * (float)v673))));
          if ( v676 > v671 )
          {
            v677 = (float)((float)v671 / (float)v676);
            v675 = (float)((float)v675 * (float)v677);
            v673 = (float)((float)v673 * (float)v677);
            v674 = (float)((float)v674 * (float)v677);
          }
          v678 = (float)(this->additivePosition.y - (float)v673);
          v679 = (float)(this->additivePosition.x - (float)v675);
          v680 = (float)(this->additivePosition.z - (float)v674);
          p_additivePosition = &this->additivePosition;
          LODWORD(v1102.x) = &this->additivePosition;
          if ( (float)((float)((float)v680 * (float)v680)
                     + (float)((float)((float)v679 * (float)v679) + (float)((float)v678 * (float)v678))) < 15.0 )
          {
            LODWORD(v1102.x) = &this->bobGoal;
            v682 = (float)(this->bobGoal.y * (float)-1.0);
            v683 = (float)(this->bobGoal.z * (float)-1.0);
            this->bobGoal.x = this->bobGoal.x * (float)-1.0;
            this->bobGoal.y = v682;
            this->bobGoal.z = v683;
          }
          v684 = p_additivePosition->x;
          v685 = this->additivePosition.y;
          v686 = (float)(this->additiveMomentum.y * *(float *)(HIDWORD(v36) - 8));
          v687 = (float)(this->additiveMomentum.x * *(float *)(HIDWORD(v36) - 8));
          v688 = (float)(this->additiveMomentum.z * *(float *)(HIDWORD(v36) - 8));
          v689 = *(float *)(HIDWORD(v36) + 36);
          v690 = this->additivePosition.z;
          v691 = this->additiveMomentum.x;
          p_additiveMomentum = &this->additiveMomentum;
          v693 = this->additiveMomentum.y;
          v694 = this->additiveMomentum.z;
          this->additiveMomentum.x = v691 * *(float *)(HIDWORD(v36) - 8);
          this->additiveMomentum.y = v686;
          this->additiveMomentum.z = v688;
          v695 = v686;
          v696 = (float)((float)v687 * (float)v689);
          v697 = v687;
          v1105.distance = v684;
          v698 = (float)((float)v688 * (float)v689);
          v1105.rightDistance = v685;
          v699 = v688;
          *(float *)&v1105.navSpline = v690;
          v1112 = v691;
          v1113 = v693;
          v1114 = v694;
          LODWORD(v1102.x) = &this->additivePosition;
          v700 = (float)((float)v695 * (float)v689);
          v701 = this->additiveMomentum.y;
          v702 = (float)((float)v697 - (float)((float)((float)v696 + (float)v679) * (float)0.001));
          this->additiveMomentum.x = v702;
          v703 = (float)((float)v699 - (float)((float)((float)v698 + (float)v680) * (float)0.001));
          this->additiveMomentum.z = (float)v699 - (float)((float)((float)v698 + (float)v680) * (float)0.001);
          v704 = (float)((float)v701 - (float)((float)((float)v700 + (float)v678) * (float)0.001));
          this->additiveMomentum.y = v704;
          v705 = (float)((float)v704 + this->additivePosition.y);
          this->additivePosition.y = (float)v704 + this->additivePosition.y;
          v706 = (float)((float)v702 + p_additivePosition->x);
          v707 = (float)((float)v703 + this->additivePosition.z);
          p_additivePosition->x = v706;
          this->additivePosition.z = v707;
          v708 = __fsqrts((float)((float)((float)v707 * (float)v707)
                                + (float)((float)((float)v706 * (float)v706) + (float)((float)v705 * (float)v705))));
          if ( v708 > v671 )
          {
            LODWORD(v1102.x) = &this->additivePosition;
            if ( v708 < v649 )
            {
              v714 = (float)((float)v708 - (float)v671);
              v715 = (float)((float)v649 - (float)v671);
              v711 = (float)(p_additiveMomentum->x
                           - (float)((float)((float)((float)((float)v714 / (float)v715)
                                                   * (float)((float)v714 / (float)v715))
                                           * (float)v706)
                                   * *(float *)(HIDWORD(v36) + 116)));
              v712 = (float)(this->additiveMomentum.z
                           - (float)((float)(this->additivePosition.z
                                           * (float)((float)((float)v714 / (float)v715)
                                                   * (float)((float)v714 / (float)v715)))
                                   * *(float *)(HIDWORD(v36) + 116)));
              v713 = (float)(this->additiveMomentum.y
                           - (float)((float)(this->additivePosition.y
                                           * (float)((float)((float)v714 / (float)v715)
                                                   * (float)((float)v714 / (float)v715)))
                                   * *(float *)(HIDWORD(v36) + 116)));
            }
            else
            {
              v709 = (float)((float)v649 / (float)v708);
              v710 = *(float *)(HIDWORD(v36) + 116);
              LODWORD(v1102.x) = &this->additivePosition;
              this->additivePosition.y = (float)v705 * (float)v709;
              p_additivePosition->x = (float)v709 * (float)v706;
              this->additivePosition.z = (float)v707 * (float)v709;
              v711 = (float)(p_additiveMomentum->x - (float)((float)((float)v709 * (float)v706) * (float)v710));
              v712 = (float)(this->additiveMomentum.z - (float)((float)((float)v707 * (float)v709) * (float)v710));
              v713 = (float)(this->additiveMomentum.y - (float)((float)((float)v705 * (float)v709) * (float)v710));
            }
            this->additiveMomentum.y = v713;
            LODWORD(v1102.x) = &this->additiveMomentum;
            this->additiveMomentum.z = v712;
            p_additiveMomentum->x = v711;
          }
          p_additiveFacing = &this->additiveFacing;
          w = quat_identity.w;
          v718 = quat_identity.z;
          v719 = quat_identity.y;
          if ( this->additiveFacing.x != quat_identity.x
            || this->additiveFacing.y != v719
            || this->additiveFacing.z != v718
            || (v720 = 1, this->additiveFacing.w != w) )
          {
            v720 = 0;
          }
          if ( v720 == 0 )
            goto LABEL_625;
          if ( this->additiveAngularMomentum.x != quat_identity.x
            || this->additiveAngularMomentum.y != v719
            || this->additiveAngularMomentum.z != v718
            || (v721 = 1, this->additiveAngularMomentum.w != w) )
          {
            v721 = 0;
          }
          if ( v721 == 0 )
          {
LABEL_625:
            v722 = this->additiveFacing.y;
            v723 = this->additiveAngularMomentum.w;
            LODWORD(v1102.x) = &this->additiveFacing;
            v724 = this->additiveAngularMomentum.x;
            v725 = p_additiveFacing->x;
            v726 = (float)((float)v722 * this->additiveAngularMomentum.x);
            v727 = (float)(p_additiveFacing->x * (float)v723);
            v728 = this->additiveAngularMomentum.z;
            v729 = (float)(p_additiveFacing->x * this->additiveAngularMomentum.x);
            v730 = this->additiveFacing.z;
            v731 = this->additiveAngularMomentum.y;
            LODWORD(v1102.x) = &this->additiveAngularMomentum;
            v732 = this->additiveFacing.w;
            LODWORD(v1102.x) = &this->additiveFacing;
            v733 = *(float *)(HIDWORD(v36) - 216);
            this->additiveFacing.y = -(float)((float)((float)v730 * (float)v724)
                                            - (float)((float)((float)v731 * (float)v732)
                                                    + (float)((float)((float)v728 * (float)v725)
                                                            + (float)((float)v722 * (float)v723))));
            this->additiveFacing.z = -(float)((float)((float)v731 * (float)v725)
                                            - (float)((float)((float)v728 * (float)v732)
                                                    + (float)((float)((float)v730 * (float)v723) + (float)v726)));
            p_additiveFacing->x = -(float)((float)((float)v728 * (float)v722)
                                         - (float)((float)((float)v724 * (float)v732)
                                                 + (float)((float)((float)v730 * (float)v731) + (float)v727)));
            this->additiveFacing.w = -(float)((float)((float)v728 * (float)v730)
                                            - (float)-(float)((float)((float)v731 * (float)v722)
                                                            - (float)((float)((float)v723 * (float)v732) - (float)v729)));
            v734 = (float)(this->additiveAngularMomentum.w * (float)v733);
            this->additiveAngularMomentum.w = v734;
            if ( v734 < v322 )
              v735 = (float)-(float)((float)((float)((float)1.0 - (float)v734) * (float)0.050000001) - (float)v734);
            else
              v735 = (float)((float)((float)((float)1.0 - (float)v734) * (float)0.050000001) + (float)v734);
            this->additiveAngularMomentum.w = v735;
            idQuat::Normalize(this: &this->additiveAngularMomentum);
            v736 = this->additiveAngularMomentum.x;
            v737 = this->additiveAngularMomentum.z;
            LODWORD(v1102.x) = &this->additiveAngularMomentum;
            v738 = this->additiveAngularMomentum.w;
            LODWORD(v1102.x) = &this->additiveFacing;
            v739 = p_additiveFacing->x;
            v740 = (float)((float)v737 * (float)100.0);
            v741 = this->additiveFacing.y;
            v742 = (float)(this->additiveAngularMomentum.y * (float)100.0);
            v745 = (float)((float)((float)((float)v737 * (float)100.0) * this->additiveFacing.w)
                         + (float)((float)((float)((float)v738 * (float)100.0) * this->additiveFacing.z)
                                 + (float)((float)((float)v736 * (float)100.0) * this->additiveFacing.y)));
            v746 = (float)-(float)((float)((float)((float)v737 * (float)100.0) * this->additiveFacing.z)
                                 - (float)-(float)((float)((float)(this->additiveAngularMomentum.y * (float)100.0)
                                                         * this->additiveFacing.y)
                                                 - (float)((float)((float)((float)v738 * (float)100.0)
                                                                 * this->additiveFacing.w)
                                                         - (float)((float)((float)v736 * (float)100.0)
                                                                 * p_additiveFacing->x))));
            v743 = (float)((float)((float)(this->additiveAngularMomentum.y * (float)100.0) * this->additiveFacing.w)
                         + (float)((float)((float)((float)v738 * (float)100.0) * this->additiveFacing.y)
                                 + (float)((float)((float)v737 * (float)100.0) * p_additiveFacing->x)));
            v744 = (float)((float)((float)((float)v736 * (float)100.0) * this->additiveFacing.w)
                         + (float)((float)((float)(this->additiveAngularMomentum.y * (float)100.0)
                                         * this->additiveFacing.z)
                                 + (float)((float)((float)v738 * (float)100.0) * p_additiveFacing->x)));
            v1138.endDistance = -(float)((float)((float)((float)v736 * (float)100.0) * this->additiveFacing.z)
                                       - (float)v743);
            v1138.rightDelta = v746;
            v1138.startDistance = -(float)((float)((float)v740 * (float)v741) - (float)v744);
            v1138.distance = -(float)((float)((float)v742 * (float)v739) - (float)v745);
            idQuat::Normalize(this: (idQuat *)&v1138);
            idQuat::Inverse(this: (idQuat *)&v1134, result: (idQuat *)&v1138);
            idQuat::Slerp(
              this: &this->additiveAngularMomentum,
              from: &this->additiveAngularMomentum,
              to: (const idQuat *)&v1134,
              t: *(float *)(HIDWORD(v36) + 808));
            idQuat::Normalize(this: &this->additiveFacing);
            idQuat::Normalize(this: &this->additiveAngularMomentum);
            v650 = 1.0;
          }
          v747 = this->currentSpeed;
          if ( v747 >= v322 )
          {
            v750 = (float)(this->currentSpeed - this->lastFrameOverMove);
            if ( v750 > 0.1 )
            {
              while ( 1 )
              {
                if ( v750 <= v650 )
                  v751 = v750 <= 0.30000001
                       ? (float)((float)v750 - (float)0.050000001)
                       : (float)((float)v750 * (float)0.5);
                else
                  v751 = 0.5;
                navSplinePath_t::Step(this: &this->splinePathToGoal, stepdist: v751);
                StartPathPos = navSplinePath_t::GetStartPathPos(
                                 this: &v1138,
                                 result: (idNavSplinePosition *)&this->splinePathToGoal);
                v753 = this->currentPosition.y;
                v754 = this->currentPosition.z;
                v755 = StartPathPos->distance;
                v1110.distance = this->currentPosition.x;
                v1110.rightDistance = v753;
                *(float *)&v1110.navSpline = v754;
                p_navSplinePosition->distance = v755;
                this->navSplinePosition.rightDistance = StartPathPos->rightDistance;
                this->navSplinePosition.navSpline = StartPathPos->navSpline;
                WorldPos = idNavSplinePosition::GetWorldPos(this: &v1111, result: (idVec3 *)&this->navSplinePosition);
                v757 = WorldPos->x;
                this->currentPosition.x = WorldPos->x;
                LODWORD(v1102.x) = &this->currentPosition;
                rightDistance = v1110.rightDistance;
                v759 = (float)(v1110.distance - (float)v757);
                v760 = *(float *)&v1110.navSpline;
                v761 = WorldPos->y;
                this->currentPosition.y = WorldPos->y;
                v762 = (float)((float)v760 - WorldPos->z);
                this->currentPosition.z = WorldPos->z;
                v750 = (float)((float)v750
                             - (float)__fsqrts((float)((float)((float)v762 * (float)v762)
                                                     + (float)((float)((float)v759 * (float)v759)
                                                             + (float)((float)((float)rightDistance - (float)v761)
                                                                     * (float)((float)rightDistance - (float)v761))))));
                if ( v750 <= 0.1 )
                  break;
                v650 = 1.0;
              }
            }
            v322 = v1106;
            HIDWORD(v36) = v1104;
            this->lastFrameOverMove = -v750;
            v323 = v1107;
            LODWORD(v36) = 0;
          }
          else
          {
            navSplinePath_t::Step(this: &this->splinePathToGoal, stepdist: v747);
            v748 = navSplinePath_t::GetStartPathPos(
                     this: &v1138,
                     result: (idNavSplinePosition *)&this->splinePathToGoal);
            p_navSplinePosition->distance = v748->distance;
            this->navSplinePosition.rightDistance = v748->rightDistance;
            this->navSplinePosition.navSpline = v748->navSpline;
            v749 = idNavSplinePosition::GetWorldPos(this: &v1111, result: (idVec3 *)&this->navSplinePosition);
            this->currentPosition.x = v749->x;
            LODWORD(v1102.x) = &this->currentPosition;
            this->currentPosition.y = v749->y;
            this->currentPosition.z = v749->z;
            this->lastFrameOverMove = v322;
          }
          v763 = this->additivePosition.y;
          v764 = (float)(this->additivePosition.z + this->currentPosition.z);
          v765 = this->currentPosition.y;
          LODWORD(v1102.x) = &this->additivePosition;
          v1109.distance = this->currentPosition.x + p_additivePosition->x;
          LODWORD(v1102.x) = &this->currentPosition;
          *(float *)&v1109.navSpline = v764;
          v1109.rightDistance = (float)v763 + (float)v765;
          currentRoll = this->currentRoll;
          v767 = idVec3::ToYaw(this: &this->currentFacing);
          v1141.mat[0].x = idVec3::ToPitch(this: &this->currentFacing);
          v1141.mat[0].y = v767;
          v1141.mat[0].z = currentRoll;
          v768 = idAngles::ToMat3(this: (idAngles *)&v1134, result: &v1141);
          this->currentAxis.mat[0].x = v768->mat[0].x;
          LODWORD(v1102.x) = &this->currentAxis.mat[2];
          this->currentAxis.mat[0].y = v768->mat[0].y;
          this->currentAxis.mat[0].z = v768->mat[0].z;
          this->currentAxis.mat[1] = v768->mat[1];
          this->currentAxis.mat[2] = v768->mat[2];
          idQuat::ToMat3(this: (idQuat *)&v1161, result: (idMat3 *)&this->additiveFacing);
          v769 = idMat3::operator*(this: &v1134, result: &this->currentAxis, a: &v1161);
          LODWORD(v1102.x) = &v769->mat[1];
          this->currentAxis.mat[0].x = v769->mat[0].x;
          LODWORD(v1102.x) = &this->currentAxis.mat[2];
          this->currentAxis.mat[0].y = v769->mat[0].y;
          this->currentAxis.mat[0].z = v769->mat[0].z;
          this->currentAxis.mat[1] = v769->mat[1];
          this->currentAxis.mat[2] = v769->mat[2];
          v770 = idEntity::GetPhysics(this);
          v771 = (float *)v770->GetOrigin(this: v770, a2: 0);
          p_previousOrigin = &this->previousOrigin;
          LODWORD(v1102.x) = &this->previousOrigin;
          this->previousOrigin.x = *v771;
          this->previousOrigin.y = v771[1];
          this->previousOrigin.z = v771[2];
          v773 = idEntity::GetPhysics(this);
          v774 = (float *)v773->GetAxis(this: v773, a2: 0);
          this->previousAxis.mat[0].x = *v774;
          LODWORD(v1102.x) = v774 + 6;
          this->previousAxis.mat[0].y = v774[1];
          this->previousAxis.mat[0].z = v774[2];
          this->previousAxis.mat[1].x = v774[3];
          this->previousAxis.mat[1].y = v774[4];
          this->previousAxis.mat[1].z = v774[5];
          this->previousAxis.mat[2].x = v774[6];
          this->previousAxis.mat[2].y = v774[7];
          this->previousAxis.mat[2].z = v774[8];
          v775 = idEntity::GetPhysics(this);
          entityNumber = this->entityNumber;
          v777 = v775->GetClipModel(this: v775, a2: 0);
          idClip::Translation(
            this: (idClip *)&v1102,
            result: (idClip *)(*((_DWORD *)v323 + 4398) + 10688),
            a3: &v1163,
            start: &this->previousOrigin,
            end: (const idVec3 *)&v1109,
            clipModel: v777,
            startAxis: &this->previousAxis,
            clipMask: 0x8000,
            passEntityNumber: SHIDWORD(v1058),
            moveClipModel: v1058,
            userName: (const char *)HIDWORD(v1062),
            a12: v1062,
            a13: SHIDWORD(v1066),
            a14: v1066,
            a15: SHIDWORD(v1070),
            a16: v1070,
            a17: SHIDWORD(v1074),
            a18: v1074,
            a19: v1078,
            a20: v1081,
            a21: v1084,
            a22: v1087,
            a23: v1090,
            a24: v1093,
            a25: v1096,
            a26: v1099,
            a27: v1101[0],
            a28: entityNumber,
            a29: v1101[2],
            a30: false,
            a31: v1101[4],
            a32: 0);
          if ( v1163.fraction < 1.0 )
          {
            this->outOfControl = 1065353216;
            this->currentSpeed = v322;
            this->desiredSpeed = v322;
            LODWORD(v1102.x) = &this->additivePosition;
            v778 = v1113;
            v779 = v1114;
            v780 = v1105.distance;
            v781 = v1105.rightDistance;
            v782 = *(float *)&v1105.navSpline;
            v1109.rightDistance = this->previousOrigin.y;
            v783 = p_previousOrigin->x;
            v784 = this->previousOrigin.z;
            p_additiveMomentum->x = v1112;
            this->additiveMomentum.y = v778;
            this->additiveMomentum.z = v779;
            v1109.distance = v783;
            *(float *)&v1109.navSpline = v784;
            p_additivePosition->x = v780;
            this->additivePosition.y = v781;
            this->additivePosition.z = v782;
          }
          idEntity::SetOrigin(this, org: (const idVec3 *)&v1109);
          v785 = this->rigidPhysics.GetClipModel(this: &this->rigidPhysics, a2: 0);
          if ( v785 != nullptr && this->declWallSpark != nullptr )
          {
            p_clipQuery = &this->clipQuery;
            v787 = (idClip *)(*((_DWORD *)v323 + 4398) + 10688);
            if ( (unsigned __int8)idClip::QueryIsValid(this: v787, clipQuery: &this->clipQuery) != 0 )
            {
              index = p_clipQuery->index;
              p_clipQuery->index = v36;
              LODWORD(v1102.x) = v787;
              idCollisionModelManager::GetContentsResult(
                this: collisionModelManager,
                result: &v1159,
                query: &v787->collisionQueries[index & 0xFFF].query,
                peek: false);
              if ( v1159.fraction < (double)*(float *)(HIDWORD(v36) + 540) )
              {
                surfaceType = v1159.c.surfaceType;
                if ( v1159.c.surfaceType == 0 )
                  surfaceType = 1;
                ImpactEffectForMaterial = idDeclProjectileImpactEffect::GetImpactEffectForMaterial(
                                            this: this->declWallSpark,
                                            materialID: surfaceType);
                if ( ImpactEffectForMaterial != nullptr )
                {
                  v791 = gameLocal->GetEntity(this: gameLocal, a2: v1159.c.entityNum);
                  v792 = -1;
                  if ( v791 != nullptr )
                  {
                    v793 = v791->__vftable;
                    memcpy(Dst: v1101, Src: &v1159.endAxis.mat[2].z, Size: sizeof(v1101));
                    v794 = (unsigned __int16 *)((int (__fastcall *)(idSpawnId *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v793->GetJointIndexFromTrace)(
                                                 a1: &v1117,
                                                 a2: LODWORD(v1159.fraction),
                                                 a3: LODWORD(v1159.endpos.y),
                                                 a4: LODWORD(v1159.endAxis.mat[0].x),
                                                 a5: LODWORD(v1159.endAxis.mat[0].z),
                                                 a6: LODWORD(v1159.endAxis.mat[1].y),
                                                 a7: LODWORD(v1159.endAxis.mat[2].x),
                                                 a8: LODWORD(v1159.endAxis.mat[2].y));
                    presentable = (int)v791->presentable;
                    v792 = *v794;
                    if ( presentable == 0 )
                    {
                      idEntity::InitPresentableInternal(this: v791);
                      presentable = (int)v791->presentable;
                    }
                  }
                  else
                  {
                    presentable = 0;
                  }
                  idClientGame::ImpactEffect(
                    this: *((idClientGame **)v323 + 4398),
                    point: (const idMat3 *)&v1159.c.point,
                    normal: (idMat3 *)&v1159.c.normal,
                    color: (idColor *)LODWORD(v1108),
                    effect: ImpactEffectForMaterial,
                    skipParticle: false,
                    noDecals: false,
                    noSounds: false,
                    owner: (const idPresentable *)HIDWORD(v1059),
                    entity: (idPresentable *)v1059,
                    jointId: (idIndex<short,enum invalidJointIndex_t> *)HIDWORD(v1063),
                    a12: v1063,
                    a13: SHIDWORD(v1067),
                    a14: v1067,
                    a15: SHIDWORD(v1071),
                    a16: v1071,
                    a17: SHIDWORD(v1075),
                    a18: v1075,
                    a19: v1079,
                    a20: v1082,
                    a21: v1085,
                    a22: v1088,
                    a23: v1091,
                    a24: v1094,
                    a25: v1097,
                    a26: v1100,
                    a27: v1101[0],
                    a28: 0,
                    a29: v1101[2],
                    a30: presentable,
                    a31: v1101[4],
                    a32: v792);
                }
                if ( g_droneDebugShowWallCollisions.valueInteger != 0 )
                  idDrone::DebugSphere(
                    pos: *(_QWORD *)&v1122->b,
                    radius: 5.0,
                    lifetime: __SPAIR64__(LODWORD(v1159.c.point.y), __ROL4__(LODWORD(v1159.c.point.z), 32)),
                    depthTest: (bool)v1122,
                    a5: 12,
                    a6: 15,
                    a7: false,
                    a8: v1059,
                    a9: v1063,
                    a10: v1067,
                    a11: v1071,
                    a12: v1075);
              }
            }
            v796 = *(_QWORD *)&idClip::Translation(
                                 this: (idClip *)&v1102,
                                 result: (idClip *)(*((_DWORD *)v323 + 4398) + 10688),
                                 a3: nullptr,
                                 start: &this->currentPosition,
                                 end: (const idVec3 *)&v1109,
                                 clipModel: v785,
                                 startAxis: &this->currentAxis,
                                 clipMask: 25,
                                 passEntityNumber: SHIDWORD(v1059),
                                 moveClipModel: v1059,
                                 userName: (const char *)HIDWORD(v1063),
                                 a12: v1063,
                                 a13: SHIDWORD(v1067),
                                 a14: v1067,
                                 a15: SHIDWORD(v1071),
                                 a16: v1071,
                                 a17: SHIDWORD(v1075),
                                 a18: v1075,
                                 a19: v1079,
                                 a20: v1082,
                                 a21: v1085,
                                 a22: v1088,
                                 a23: v1091,
                                 a24: v1094,
                                 a25: v1097,
                                 a26: v1100,
                                 a27: v1101[0],
                                 a28: this->entityNumber,
                                 a29: v1101[2],
                                 a30: false,
                                 a31: v1101[4],
                                 a32: (int)"w:\\tech5\\tungsten\\game\\entities\\Drone.cpp(2371) : Translation")->world;
            HIDWORD(v796) = &idDeclAiEvent::resourceList.staticID;
            p_clipQuery->index = v796;
            if ( g_droneDebugClipTranslations.valueInteger != 0 )
            {
              v797 = this->currentPosition.x;
              v798 = this->currentPosition.z;
              v799 = this->currentPosition.y;
              v800 = *(float *)(LODWORD(v1116.x) + 4);
              v801 = *(float *)(LODWORD(v1116.x) + 8);
              v802 = *(float *)(LODWORD(v1116.x) + 12);
              v1134.mat[0].x = *(float *)LODWORD(v1116.x);
              v1134.mat[0].y = v800;
              v1134.mat[0].z = v801;
              v1111.distance = v797;
              *(float *)&v1111.navSpline = v798;
              v1115 = v1109;
              v1134.mat[1].x = v802;
              v1111.rightDistance = v799;
              (*(void (__fastcall **)(_DWORD, idMat3 *, idNavSplinePosition *, idNavSplinePosition *, double))(**(_DWORD **)(*((_DWORD *)v323 + 4398) + 4) + 180))(
                a1: *(_DWORD *)(*((_DWORD *)v323 + 4398) + 4),
                a2: &v1134,
                a3: &v1111,
                a4: &v1115,
                a5: 5.0);
            }
          }
          v803 = v1109.distance;
          v804 = this->lastMovement.x;
          v805 = (float)(v1109.distance - p_previousOrigin->x);
          v806 = v1109.rightDistance;
          v807 = this->lastMovement.y;
          v808 = (float)(v1109.rightDistance - this->previousOrigin.y);
          v809 = *(float *)&v1109.navSpline;
          v810 = this->lastMovement.z;
          v811 = (float)(*(float *)&v1109.navSpline - this->previousOrigin.z);
          v812 = 0.19999999;
          LODWORD(v36) = &this->lastMovement;
          v813 = (float)(v804 * *(float *)(HIDWORD(v36) + 728));
          v814 = (float)(v810 * *(float *)(HIDWORD(v36) + 728));
          v815 = (float)(v807 * *(float *)(HIDWORD(v36) + 728));
          v1116.x = 0.19999999;
          LODWORD(v1102.x) = &this->lastMovement;
          v1112 = v804;
          v1113 = v807;
          v1114 = v810;
          this->lastMovement.x = (float)v813 + (float)((float)v805 * (float)0.19999999);
          this->lastMovement.y = (float)v815 + (float)((float)v808 * (float)0.19999999);
          this->lastMovement.z = (float)v814 + (float)((float)v811 * (float)0.19999999);
          if ( g_droneDebugShowThrusterHistory.valueInteger != 0 )
          {
            v816 = (float)(this->lastMovement.z * *(float *)(HIDWORD(v36) + 768));
            v817 = (float)(this->lastMovement.y * *(float *)(HIDWORD(v36) + 768));
            v818 = (float)(*(float *)v36 * *(float *)(HIDWORD(v36) + 768));
            v819 = *(float *)(LODWORD(v1108) + 4);
            v820 = *(float *)(LODWORD(v1108) + 8);
            v821 = *(float *)(LODWORD(v1108) + 12);
            v1134.mat[0].x = *(float *)LODWORD(v1108);
            v1134.mat[0].y = v819;
            v822 = *(float *)(HIDWORD(v36) + 888);
            v1111.distance = v1109.distance;
            *(float *)&v1105.navSpline = (float)v816 + (float)v809;
            v1105.rightDistance = (float)v817 + (float)v806;
            v1105.distance = (float)v818 + (float)v803;
            v1134.mat[0].z = v820;
            v1134.mat[1].x = v821;
            v823 = *((_DWORD *)v323 + 4398);
            LODWORD(v1108) = &this->lastMovement;
            v1111.rightDistance = v1109.rightDistance;
            v1111.navSpline = v1109.navSpline;
            v1115 = v1105;
            (*(void (__fastcall **)(_DWORD, idMat3 *, idNavSplinePosition *, idNavSplinePosition *, double))(**(_DWORD **)(v823 + 4) + 180))(
              a1: *(_DWORD *)(v823 + 4),
              a2: &v1134,
              a3: &v1111,
              a4: &v1115,
              a5: v822);
          }
          if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
          {
            v824 = (float)(this->desiredSpeed - this->currentSpeed);
            v825 = *(float *)(HIDWORD(v36) + 416);
            v826 = 1.0;
            v827 = 2.0;
            if ( v824 > v825 )
            {
              if ( v824 < 1.0 )
                v828 = (float)((float)((float)((float)(this->desiredSpeed - this->currentSpeed)
                                             - *(float *)(HIDWORD(v36) + 416))
                                     * (float)1.3333334)
                             - (float)2.0);
              else
                v828 = 2.0;
            }
            else
            {
              v828 = *(float *)(HIDWORD(v36) + 416);
            }
            v829 = v1114;
            v830 = v1112;
            v831 = v1113;
            v832 = *(float *)(HIDWORD(v36) + 772);
            v833 = 0.89999998;
            v834 = (float)(this->thrusterPerceivedFriction * (float)0.89999998);
            v835 = *(float *)(HIDWORD(v36) + 768);
            v836 = v1109.distance;
            v837 = v1109.rightDistance;
            v838 = 10;
            v839 = *(float *)&v1109.navSpline;
            p_a = &v1126.a;
            LODWORD(v1108) = &this->previousOrigin;
            this->thrusterPerceivedFriction = (float)((float)v828 * (float)0.10000002) + (float)v834;
            v841 = (float)(this->previousNonThrustMovement.y * (float)0.89999998);
            v842 = (float)(this->lastMovement.z - (float)v829);
            v843 = (float)(this->previousNonThrustMovement.x * (float)0.89999998);
            v844 = (float)(*(float *)v36 - (float)v830);
            v845 = (float)(this->lastMovement.y - (float)v831);
            v846 = this->previousNonThrustMovement.x;
            v847 = this->previousNonThrustMovement.y;
            v848 = (float)(this->previousNonThrustMovement.z * (float)v832);
            this->previousNonThrustMovement.z = this->previousNonThrustMovement.z * (float)0.89999998;
            this->previousNonThrustMovement.x = v843;
            this->previousNonThrustMovement.y = v841;
            v849 = (float)((float)((float)v842 * (float)v835) - (float)v848);
            v850 = (float)((float)((float)v844 * (float)v835) - (float)((float)v846 * (float)v832));
            v851 = (float)((float)((float)v845 * (float)v835) - (float)((float)v847 * (float)v832));
            v852 = (float)((float)v837 - this->previousOrigin.y);
            v853 = (float)((float)v836 - p_previousOrigin->x);
            v854 = (float)((float)v839 - this->previousOrigin.z);
            v855 = (float)((float)((float)v836 - p_previousOrigin->x) * this->thrusterPerceivedFriction);
            v856 = (float)((float)((float)v839 - this->previousOrigin.z) * this->thrusterPerceivedFriction);
            v857 = (float)((float)-v851
                         - (float)((float)((float)v837 - this->previousOrigin.y) * this->thrusterPerceivedFriction));
            v858 = (float)((float)-v850
                         - (float)((float)((float)v836 - p_previousOrigin->x) * this->thrusterPerceivedFriction));
            v1102.y = (float)-v851
                    - (float)((float)((float)v837 - this->previousOrigin.y) * this->thrusterPerceivedFriction);
            v1102.x = (float)-v850 - (float)v855;
            v859 = (float)((float)-v849 - (float)v856);
            do
            {
              *++p_a = 0.0;
              --v838;
            }
            while ( v838 != 0 );
            v860 = this->currentSpeed;
            v861 = *(float *)(HIDWORD(v36) + 576);
            v862 = (float)((float)v854 * this->currentSpeed);
            v863 = 0.5;
            if ( v854 <= v322 )
            {
              if ( v862 > *(float *)(HIDWORD(v36) + 432) )
              {
                if ( v862 < v322 )
                  v865 = (float)((float)((float)((float)((float)v854 * this->currentSpeed)
                                               - *(float *)(HIDWORD(v36) + 432))
                                       * (float)0.075000003)
                               - (float)0.5);
                else
                  v865 = 1.0;
              }
              else
              {
                v865 = -0.5;
              }
              v858 = (float)((float)v865 * (float)v858);
              v1102.x = v858;
              v857 = (float)((float)v865 * (float)v857);
              v1102.y = v857;
              v859 = (float)((float)v865 * (float)((float)-v849 - (float)v856));
              if ( v854 > v322 )
              {
                if ( v854 < *(float *)(HIDWORD(v36) + 996) )
                  v864 = (float)((float)((float)v854 * (float)v861) - *(float *)(HIDWORD(v36) - 48));
                else
                  v864 = 1.0;
              }
              else
              {
                v864 = *(float *)(HIDWORD(v36) + 448);
              }
            }
            else if ( v862 > v322 )
            {
              if ( v862 < *(float *)(HIDWORD(v36) + 996) )
                v864 = (float)-(float)((float)((float)((float)v854 * this->currentSpeed) * (float)0.89999998)
                                     - *(float *)(HIDWORD(v36) + 448));
              else
                v864 = *(float *)(HIDWORD(v36) + 452);
            }
            else
            {
              v864 = *(float *)(HIDWORD(v36) + 448);
            }
            if ( this->currentState.val == DS_SCANNING )
              v864 = (float)((float)v864 * (float)2.0);
            v866 = v1106;
            v867 = (float)((float)v859 + (float)v864);
            v868 = this->desiredSpeed;
            v869 = v1106;
            v870 = *(float *)(HIDWORD(v36) + 888);
            v1102.z = (float)v859 + (float)v864;
            v871 = 0.25;
            if ( v868 < (float)((float)v860 + (float)2.0) )
            {
              v872 = this->currentFacing.z;
              if ( v872 < v866 && v860 < v1123 )
              {
                v873 = (float)((float)((float)v860 - (float)v868) + (float)2.0);
                if ( v873 > v866 )
                {
                  if ( v873 < v870 )
                    v866 = (float)((float)((float)((float)((float)v860 - (float)v868) + (float)2.0) * (float)0.1875)
                                 + (float)0.25);
                  else
                    v866 = 1.0;
                }
                else
                {
                  v866 = 0.25;
                }
                if ( v860 > v1136 )
                {
                  v1108 = v1123;
                  v812 = v1116.x;
                  *(_QWORD *)&v1116.x = 0.25;
                  v871 = 0.25;
                  v866 = (float)((float)((float)((float)((float)v860 - v1136) * (float)-v866) / (float)(v1123 - v1136))
                               + (float)v866);
                }
                if ( v872 > -0.5 )
                  v866 = (float)((float)((float)((float)((float)v872 - (float)-0.5) * (float)-v866) * (float)2.0)
                               + (float)v866);
              }
            }
            if ( g_droneDebugShowThrust.valueInteger != 0 )
            {
              v874 = (float)((float)v849 * *(float *)(HIDWORD(v36) + 128));
              v875 = (float)((float)v851 * *(float *)(HIDWORD(v36) + 128));
              v876 = (float)((float)v850 * *(float *)(HIDWORD(v36) + 128));
              v877 = v1124->g;
              v878 = v1124->b;
              v879 = v1124->a;
              v1134.mat[0].x = v1124->r;
              v1111 = v1109;
              *(float *)&v1105.navSpline = (float)v874 + (float)v839;
              v1105.rightDistance = (float)v875 + (float)v837;
              v1105.distance = (float)v876 + (float)v836;
              v1134.mat[0].y = v877;
              v1134.mat[0].z = v878;
              v1134.mat[1].x = v879;
              v880 = *((_DWORD *)v323 + 4398);
              v1115 = v1105;
              (*(void (__fastcall **)(_DWORD, idMat3 *, idNavSplinePosition *, idNavSplinePosition *, double))(**(_DWORD **)(v880 + 4) + 180))(
                a1: *(_DWORD *)(v880 + 4),
                a2: &v1134,
                a3: &v1111,
                a4: &v1115,
                a5: v870);
              v881 = (float)((float)v853 * *(float *)(HIDWORD(v36) + 128));
              v882 = (float)((float)v854 * *(float *)(HIDWORD(v36) + 128));
              v883 = (float)((float)v852 * *(float *)(HIDWORD(v36) + 128));
              v884 = *(float *)(LODWORD(v1118.x) + 4);
              v885 = *(float *)(HIDWORD(v36) + 888);
              v886 = *(float *)(LODWORD(v1118.x) + 8);
              v887 = *(float *)(LODWORD(v1118.x) + 12);
              v1134.mat[0].x = *(float *)LODWORD(v1118.x);
              v1105.distance = (float)v881 + v1109.distance;
              v1134.mat[0].y = v884;
              v1134.mat[0].z = v886;
              v888 = *((_DWORD *)v323 + 4398);
              *(float *)&v1105.navSpline = (float)v882 + *(float *)&v1109.navSpline;
              v1105.rightDistance = (float)v883 + v1109.rightDistance;
              v1111 = v1109;
              v1134.mat[1].x = v887;
              v1115 = v1105;
              (*(void (__fastcall **)(_DWORD, idMat3 *, idNavSplinePosition *, idNavSplinePosition *, double))(**(_DWORD **)(v888 + 4) + 180))(
                a1: *(_DWORD *)(v888 + 4),
                a2: &v1134,
                a3: &v1111,
                a4: &v1115,
                a5: v885);
              v889 = (float)((float)v858 * *(float *)(HIDWORD(v36) + 128));
              v890 = (float)((float)v867 * *(float *)(HIDWORD(v36) + 128));
              v891 = (float)((float)v857 * *(float *)(HIDWORD(v36) + 128));
              v892 = *((_DWORD *)v323 + 4398);
              v893 = *(float *)(HIDWORD(v36) + 888);
              v1134.mat[0].x = v1122->r;
              v1105.distance = (float)v889 + v1109.distance;
              *(float *)&v1105.navSpline = (float)v890 + *(float *)&v1109.navSpline;
              v1105.rightDistance = (float)v891 + v1109.rightDistance;
              v894 = v1122->b;
              v895 = v1122->a;
              v1134.mat[0].y = v1122->g;
              v1134.mat[0].z = v894;
              v1134.mat[1].x = v895;
              v1111 = v1109;
              v1115 = v1105;
              (*(void (__fastcall **)(_DWORD, idMat3 *, idNavSplinePosition *, idNavSplinePosition *, double))(**(_DWORD **)(v892 + 4) + 180))(
                a1: *(_DWORD *)(v892 + 4),
                a2: &v1134,
                a3: &v1111,
                a4: &v1115,
                a5: v893);
              v825 = *(float *)(HIDWORD(v36) + 416);
              v861 = *(float *)(HIDWORD(v36) + 576);
              v870 = *(float *)(HIDWORD(v36) + 888);
              v832 = *(float *)(HIDWORD(v36) + 772);
              v863 = 0.5;
              v826 = 1.0;
              v871 = 0.25;
              v833 = 0.89999998;
              v827 = 2.0;
            }
            lookUpToGoUpAount = this->lookUpToGoUpAount;
            if ( lookUpToGoUpAount <= v1106
              || v824 <= -1.0
              || (v897 = (float)(v1123 + (float)v826), (v898 = this->currentSpeed) >= v897) )
            {
              v902 = v1132;
              v903 = v1130;
              v900 = v1106;
            }
            else
            {
              if ( lookUpToGoUpAount < *(float *)(HIDWORD(v36) + 564) )
                v899 = (float)(this->lookUpToGoUpAount * (float)12.109091);
              else
                v899 = *(float *)(HIDWORD(v36) + 568);
              v900 = v1106;
              if ( v824 > v825 )
              {
                if ( v824 < v827 )
                  v899 = (float)((float)((float)((float)v824 - (float)v825) * (float)v899) * (float)v871);
              }
              else
              {
                v899 = v1106;
              }
              if ( v898 > (float)(v1136 - (float)v826) )
              {
                if ( v898 < v897 )
                  v899 = (float)((float)((float)((float)(this->currentSpeed - (float)(v1136 - (float)v826))
                                               * (float)-v899)
                                       / (float)((float)(v1123 + (float)v826) - (float)(v1136 - (float)v826)))
                               + (float)v899);
                else
                  v899 = v1106;
              }
              v901 = (float)((float)v899 * this->allowSpeedChanges);
              *(float *)&v1127.type = (float)((float)((float)v899 * this->allowSpeedChanges)
                                            * *(float *)(HIDWORD(v36) + 728))
                                    + *(float *)&v1127.type;
              v1127.value.f = (float)((float)v901 * (float)v861) + v1127.value.f;
              v902 = (float)((float)v901 + v1132);
              v1132 = (float)v901 + v1132;
              v903 = (float)((float)v901 + v1130);
              v1130 = (float)v901 + v1130;
            }
            v904 = this->allowFacingChanges;
            if ( (float)(this->desiredFacing.z - this->currentFacing.z) <= v900 )
            {
              v906 = v1131;
              v907 = v1129;
              v908 = (float)((float)((float)(this->desiredFacing.z - this->currentFacing.z) * this->allowFacingChanges)
                           * *(float *)(HIDWORD(v36) - 144));
              v866 = (float)((float)v866
                           / (float)-(float)((float)((float)(this->desiredFacing.z - this->currentFacing.z) * (float)v870)
                                           - (float)v826));
              v902 = (float)((float)v902
                           - (float)((float)((float)(this->desiredFacing.z - this->currentFacing.z)
                                           * this->allowFacingChanges)
                                   * *(float *)(HIDWORD(v36) - 144)));
              v1127.value.f = -(float)((float)((float)((float)(this->desiredFacing.z - this->currentFacing.z)
                                                     * this->allowFacingChanges)
                                             * (float)v832)
                                     - v1127.value.f);
              v1132 = v902;
              v903 = (float)((float)v903 - (float)v908);
              v1130 = v903;
            }
            else
            {
              v905 = (float)((float)(this->desiredFacing.z - this->currentFacing.z) * this->allowFacingChanges);
              v906 = (float)(v1131
                           + (float)((float)(this->desiredFacing.z - this->currentFacing.z) * this->allowFacingChanges));
              v1127.value.v[1] = (float)((float)((float)(this->desiredFacing.z - this->currentFacing.z)
                                               * this->allowFacingChanges)
                                       * (float)v827)
                               + v1127.value.v[1];
              v1131 = v1131 + (float)v905;
              v907 = (float)(v1129 + (float)v905);
              v1129 = v1129 + (float)v905;
            }
            if ( (float)(this->desiredRoll - this->currentRoll) <= v900 )
            {
              v906 = (float)-(float)((float)((float)((float)(this->desiredRoll - this->currentRoll)
                                                   * this->allowRollChanges)
                                           * (float)0.050000001)
                                   - (float)v906);
              v1131 = v906;
            }
            else
            {
              v907 = (float)((float)((float)((float)(this->desiredRoll - this->currentRoll) * this->allowRollChanges)
                                   * (float)0.050000001)
                           + (float)v907);
              v1129 = v907;
            }
            _FP31 = (float)((float)((float)(p_desiredFacing->x * p_desiredFacing->x)
                                  + (float)(this->desiredFacing.y * this->desiredFacing.y))
                          - idMath::FLT_SMALLEST_NON_DENORMAL);
            _FP30 = (float)((float)((float)(p_currentFacing->x * p_currentFacing->x)
                                  + (float)(this->currentFacing.y * this->currentFacing.y))
                          - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm
            {
              fsel      f9, f31, f9, f13
              fsel      f4, f30, f4, f13
            }
            v913 = __frsqrte(_FP9);
            v914 = __frsqrte(_FP4);
            v915 = (float)((float)-(float)((float)((float)((float)v913
                                                         * (float)((float)((float)(p_desiredFacing->x
                                                                                 * p_desiredFacing->x)
                                                                         + (float)(this->desiredFacing.y
                                                                                 * this->desiredFacing.y))
                                                                 * (float)v863))
                                                 * (float)v913)
                                         - (float)1.5)
                         * (float)v913);
            v916 = (float)((float)-(float)((float)((float)((float)v915
                                                         * (float)((float)((float)(p_desiredFacing->x
                                                                                 * p_desiredFacing->x)
                                                                         + (float)(this->desiredFacing.y
                                                                                 * this->desiredFacing.y))
                                                                 * (float)v863))
                                                 * (float)v915)
                                         - (float)1.5)
                         * (float)v915);
            v917 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v914
                                                                                                 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863))
                                                                                         * (float)v914)
                                                                                 - (float)1.5)
                                                                 * (float)v914)
                                                         * (float)((float)((float)(p_currentFacing->x
                                                                                 * p_currentFacing->x)
                                                                         + (float)(this->currentFacing.y
                                                                                 * this->currentFacing.y))
                                                                 * (float)v863))
                                                 * (float)((float)-(float)((float)((float)((float)v914
                                                                                         * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y))
                                                                                                 * (float)v863))
                                                                                 * (float)v914)
                                                                         - (float)1.5)
                                                         * (float)v914))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v914
                                                                 * (float)((float)((float)(p_currentFacing->x
                                                                                         * p_currentFacing->x)
                                                                                 + (float)(this->currentFacing.y
                                                                                         * this->currentFacing.y))
                                                                         * (float)v863))
                                                         * (float)v914)
                                                 - (float)1.5)
                                 * (float)v914));
            v918 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v914 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863)) * (float)v914) - (float)1.5)
                                                                                                 * (float)v914)
                                                                                         * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y))
                                                                                                 * (float)v863))
                                                                                 * (float)((float)-(float)((float)((float)((float)v914 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863)) * (float)v914) - (float)1.5)
                                                                                         * (float)v914))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v914
                                                                                                 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863))
                                                                                         * (float)v914)
                                                                                 - (float)1.5)
                                                                 * (float)v914))
                                                 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x)
                                                                 + (float)(this->currentFacing.y * this->currentFacing.y))
                                                         * (float)v863))
                                         * (float)v917)
                                 - (float)1.5);
            v921 = (float)(this->currentFacing.y
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v914 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863)) * (float)v914) - (float)1.5) * (float)v914) * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863))
                                                                                                 * (float)((float)-(float)((float)((float)((float)v914 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863)) * (float)v914) - (float)1.5) * (float)v914))
                                                                                         - (float)1.5)
                                                                         * (float)((float)-(float)((float)((float)((float)v914 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863)) * (float)v914)
                                                                                                 - (float)1.5)
                                                                                 * (float)v914))
                                                                 * (float)((float)((float)(p_currentFacing->x
                                                                                         * p_currentFacing->x)
                                                                                 + (float)(this->currentFacing.y
                                                                                         * this->currentFacing.y))
                                                                         * (float)v863))
                                                         * (float)v917)
                                                 - (float)1.5)
                                 * (float)v917));
            v922 = (float)(p_desiredFacing->x
                         * (float)((float)-(float)((float)((float)((float)v916
                                                                 * (float)((float)((float)(p_desiredFacing->x
                                                                                         * p_desiredFacing->x)
                                                                                 + (float)(this->desiredFacing.y
                                                                                         * this->desiredFacing.y))
                                                                         * (float)v863))
                                                         * (float)v916)
                                                 - (float)1.5)
                                 * (float)v916));
            v923 = (float)((float)(this->desiredFacing.y
                                 * (float)((float)-(float)((float)((float)((float)v916
                                                                         * (float)((float)((float)(p_desiredFacing->x
                                                                                                 * p_desiredFacing->x)
                                                                                         + (float)(this->desiredFacing.y
                                                                                                 * this->desiredFacing.y))
                                                                                 * (float)v863))
                                                                 * (float)v916)
                                                         - (float)1.5)
                                         * (float)v916))
                         * (float)(this->currentFacing.y
                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v914 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863)) * (float)v914) - (float)1.5) * (float)v914) * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863)) * (float)((float)-(float)((float)((float)((float)v914 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863)) * (float)v914) - (float)1.5) * (float)v914))
                                                                                                 - (float)1.5)
                                                                                 * (float)((float)-(float)((float)((float)((float)v914 * (float)((float)((float)(p_currentFacing->x * p_currentFacing->x) + (float)(this->currentFacing.y * this->currentFacing.y)) * (float)v863)) * (float)v914) - (float)1.5)
                                                                                         * (float)v914))
                                                                         * (float)((float)((float)(p_currentFacing->x
                                                                                                 * p_currentFacing->x)
                                                                                         + (float)(this->currentFacing.y
                                                                                                 * this->currentFacing.y))
                                                                                 * (float)v863))
                                                                 * (float)v917)
                                                         - (float)1.5)
                                         * (float)v917)));
            v919 = (float)((float)-(float)((float)((float)((float)v916
                                                         * (float)((float)((float)(p_desiredFacing->x
                                                                                 * p_desiredFacing->x)
                                                                         + (float)(this->desiredFacing.y
                                                                                 * this->desiredFacing.y))
                                                                 * (float)v863))
                                                 * (float)v916)
                                         - (float)1.5)
                         * (float)v916);
            v920 = (float)((float)v918 * (float)v917);
            v924 = (float)((float)((float)(p_currentFacing->x * (float)((float)v918 * (float)v917))
                                 * (float)(p_desiredFacing->x * (float)v919))
                         + (float)v923);
            if ( v924 > v833 )
            {
              if ( v924 < v826 )
                v925 = (float)-(float)((float)((float)((float)v924 - (float)v833) * (float)9.9999981) - (float)v826);
              else
                v925 = v900;
            }
            else
            {
              v925 = v826;
            }
            v926 = (float)((float)v925 * (float)v904);
            if ( (float)((float)((float)(p_currentFacing->x * (float)v920) * (float)(this->desiredFacing.y * (float)v919))
                       + (float)((float)-v922 * (float)v921)) <= v900 )
            {
              v907 = (float)((float)v907 + (float)v926);
              v903 = (float)((float)v903 + (float)v926);
              v1129 = v907;
              v1130 = v903;
              v1128 = (float)((float)v926 * (float)v863) + v1128;
            }
            else
            {
              v906 = (float)((float)v906 + (float)v926);
              v902 = (float)((float)v902 + (float)v926);
              v1131 = v906;
              v1132 = v902;
              v1127.value.q[3] = (float)((float)v926 * (float)v863) + v1127.value.q[3];
            }
            v927 = v1137;
            if ( v1125 < v833 )
            {
              if ( v1125 >= 0.30000001 )
                v927 = (float)((float)((float)v827 - v1125) * v1137);
              else
                v927 = 999.0;
            }
            v928 = this->currentSpeed;
            if ( v928 < v927 || this->desiredSpeed < v928 )
            {
              wasAfterburnerFxStarted = this->wasAfterburnerFxStarted;
              this->afterburnerAmount = v900;
              this->nextAfterburnerSmokeTime = 0;
              if ( wasAfterburnerFxStarted )
              {
                idAnimatedEntity::StopFX(this, condition: 32);
                idAlarm::StartFX(this, condition: FX_DRONE_STOP_AFTERBURNER);
                this->wasAfterburnerFxStarted = false;
              }
            }
            else
            {
              v929 = this->allowSpeedChanges;
              v930 = (float)(this->allowSpeedChanges * v1125);
              v931 = v1127.value.v[1];
              v932 = this->nextAfterburnerSmokeTime;
              v933 = *(float *)(HIDWORD(v36) + 540);
              v866 = v900;
              v935 = (float)((float)(this->desiredSpeed - this->currentSpeed) + (float)5.0);
              v934 = (float)(this->desiredSpeed * (float)0.00099998713);
              v1129 = (float)v907 + (float)(this->allowSpeedChanges * v1125);
              *(float *)&v1127.type = (float)((float)v930 * (float)v827) + *(float *)&v1127.type;
              v1130 = (float)v903 + (float)v930;
              v1131 = (float)v906 + (float)v930;
              v1132 = (float)v902 + (float)v930;
              this->currentSpeed = (float)((float)v928 * (float)v933) + (float)v934;
              this->afterburnerAmount = (float)((float)v935 * (float)v929) * (float)0.1;
              v1127.value.v[1] = (float)v931 - (float)((float)((float)v935 * (float)v929) * (float)0.1);
              if ( v932 == 0 )
                this->nextAfterburnerSmokeTime = idGameTimeManager::GetGameMs(
                                                   this: (idGameTimeManager *)(*((_DWORD *)v323 + 4398) + 504064),
                                                   type: GAMETIME_SCALED);
              if ( !this->wasAfterburnerFxStarted )
              {
                idAlarm::StartFX(this, condition: FX_DRONE_START_AFTERBURNER);
                this->wasAfterburnerFxStarted = true;
              }
            }
            v937 = v900;
            v938 = v900;
            v939 = (float)(idVec3::NormalizeFast(this: &v1102) * (float)0.1);
            if ( v939 > 0.0099999998 )
            {
              v940 = v1135;
              v941 = 0;
              v942 = (idVec3 *)v1162;
              v943 = thrusterName;
              v944 = (idMat3 *)v1164;
              while ( v941 == 3
                   || (unsigned __int8)idAnimatedEntity::GetTagPosition(
                                         this,
                                         propName: v940,
                                         tagName: *v943,
                                         origin: v942,
                                         axis: v944) != 0 )
              {
                ++v943;
                ++v941;
                ++v944;
                ++v942;
                if ( (int)v943 >= (int)&MAX_SPLINE_AHEAD_DISTANCE )
                {
                  v945 = v1102.z;
                  v946 = v1102.y;
                  v947 = v1102.x;
                  v948 = 0;
                  v949 = (float *)&v1165;
                  v950 = -1.0;
                  v951 = 0;
                  for ( n = 10; n != 0; --n )
                  {
                    if ( v948 != 3 )
                    {
                      if ( v948 == -1 )
                      {
                        *(float *)((char *)&v1134.mat[0].x + v951) = v900;
                      }
                      else
                      {
                        v953 = (float)((float)(*v949 * (float)v945)
                                     + (float)((float)(*(v949 - 2) * (float)v947) + (float)(*(v949 - 1) * (float)v946)));
                        *(float *)((char *)&v1134.mat[0].x + v951) = (float)(*v949 * (float)v945)
                                                                   + (float)((float)(*(v949 - 2) * (float)v947)
                                                                           + (float)(*(v949 - 1) * (float)v946));
                        if ( v953 > v900 )
                        {
                          v954 = (float)((float)(*(float *)(v951 + HIDWORD(v36) + 2456) * (float)v953) * (float)v953);
                          if ( v954 > v950 )
                            v950 = v954;
                        }
                      }
                    }
                    ++v948;
                    v949 += 9;
                    v951 += 4;
                  }
                  if ( (_S18_13 & 1) == 0 )
                  {
                    randomThrusterVec.y = v900;
                    randomThrusterVec.z = v900;
                    _S18_13 |= 1u;
                    randomThrusterVec.x = 1.0;
                  }
                  v955 = v1107;
                  for ( ii = 0; ii < 10; ++ii )
                  {
                    if ( ii != 3 )
                    {
                      v957 = 4 * ii;
                      v958 = *((float *)&v1127.type + ii);
                      if ( *(&v1134.mat[0].x + ii) > v900 && v950 > 0.050000001 )
                        v958 = (float)((float)((float)((float)(*(float *)(v957 + HIDWORD(v36) + 2456) / (float)v950)
                                                     * *(&v1134.mat[0].x + ii))
                                             * (float)v939)
                                     + *((float *)&v1127.type + ii));
                      if ( v958 < v900 )
                        v958 = v900;
                      if ( v866 != v900 )
                      {
                        if ( ii == 1 )
                        {
                          v869 = (float)((float)v958 * (float)v866);
                          v958 = (float)((float)v958 - (float)((float)v958 * (float)v866));
                        }
                        else if ( ii == 2 )
                        {
                          v958 = (float)((float)v958 + (float)v869);
                        }
                      }
                      v959 = 4 * (ii + 2862);
                      v960 = (float)((float)((float)v958 * (float)0.10000002)
                                   + (float)(*(float *)((char *)&this->__vftable + v959) * (float)0.89999998));
                      if ( randomThrusterVec.x <= (double)*(float *)(HIDWORD(v36) - 216) )
                      {
                        randomThrusterVec.x = pseudoRandomDeltaX + randomThrusterVec.x;
                      }
                      else
                      {
                        randomThrusterVec.x = RandomFloat(
                                                min: *(float *)(HIDWORD(v36) + 600),
                                                max: *(float *)(HIDWORD(v36) - 12));
                        pseudoRandomDeltaX = RandomFloat(
                                               min: *(float *)(HIDWORD(v36) + 272),
                                               max: *(float *)(HIDWORD(v36) + 240));
                      }
                      if ( randomThrusterVec.y <= 0.050000001 )
                      {
                        randomThrusterVec.y = pseudoRandomDeltaY + randomThrusterVec.y;
                      }
                      else
                      {
                        randomThrusterVec.y = RandomFloat(
                                                min: *(float *)(HIDWORD(v36) + 696),
                                                max: *(float *)(HIDWORD(v36) + 276));
                        pseudoRandomDeltaY = RandomFloat(min: 0.0099999998, max: *(float *)(HIDWORD(v36) + 804));
                      }
                      if ( randomThrusterVec.z <= 0.050000001 )
                      {
                        v962 = (float)(pseudoRandomDeltaZ + randomThrusterVec.z);
                        randomThrusterVec.z = pseudoRandomDeltaZ + randomThrusterVec.z;
                      }
                      else
                      {
                        randomThrusterVec.z = RandomFloat(
                                                min: *(float *)(HIDWORD(v36) + 696),
                                                max: *(float *)(HIDWORD(v36) + 276));
                        v961 = RandomFloat(min: 0.0099999998, max: *(float *)(HIDWORD(v36) + 804));
                        v962 = randomThrusterVec.z;
                        pseudoRandomDeltaZ = v961;
                      }
                      if ( g_droneDebugThrusterLevels.valueInteger != 0 )
                      {
                        v963 = (float)(this->thrusterLength * (float)v960);
                        v964 = randomThrusterVec.y;
                        v965 = randomThrusterVec.x;
                        this->thrusterEffect.height = this->thrusterWidth * (float)v960;
                        v966 = (float *)&v1164[9 * ii];
                        v967 = (float)((float)v962 * (float)v963);
                        v968 = v966[6];
                        v969 = v966[5];
                        v970 = v966[4];
                        v971 = v966[3];
                        v972 = v966[2];
                        v973 = v966[1];
                        LODWORD(v1116.x) = &v1162[3 * ii];
                        v975 = *((idAnimator_ChannelWeight **)v955 + 4398);
                        v976 = (float)((float)((float)v971 * (float)((float)v963 * (float)v964))
                                     + (float)((float)v968 * (float)v967));
                        v974 = *(float *)(LODWORD(v1116.x) + 4);
                        v977 = (float)((float)((float)v972 * (float)((float)v963 * (float)v965))
                                     + (float)((float)v969 * (float)((float)v963 * (float)v964)));
                        v979 = (float)(*(float *)LODWORD(v1116.x)
                                     + (float)((float)(*v966 * (float)((float)v963 * (float)v965)) + (float)v976));
                        v978 = (float)((float)(v966[7] * (float)v967)
                                     + (float)((float)((float)v973 * (float)((float)v963 * (float)v965))
                                             + (float)((float)v970 * (float)((float)v963 * (float)v964))));
                        v1141.mat[2].x = *(float *)(LODWORD(v1116.x) + 8)
                                       + (float)((float)(v966[8] * (float)v967) + (float)v977);
                        v1141.mat[1].y = v979;
                        v1141.mat[1].z = (float)v974 + (float)v978;
                        NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: v975);
                        idLaserBeam::Update(
                          this: &this->thrusterEffect,
                          beamEffects: NumContacts,
                          startPos: (const idVec3 *)&v1162[3 * ii],
                          endPos: (const idVec3 *)&v1141.mat[1].y,
                          fade: 1.0);
                      }
                      else
                      {
                        v981 = v900;
                        v982 = 4 * (ii + 2872);
                        v983 = 0;
                        v984 = (float)((float)v960 + *(float *)((char *)&this->__vftable + v982));
                        if ( v984 >= *(float *)(v957 + HIDWORD(v36) + 292) )
                        {
                          v981 = *(float *)(v957 + HIDWORD(v36) + 332);
                          if ( v984 >= v981 )
                          {
                            v983 = 0x2000;
                            if ( v984 > *(float *)(v957 + HIDWORD(v36) + 372) )
                              v984 = *(float *)(v957 + HIDWORD(v36) + 372);
                          }
                          else
                          {
                            v981 = *(float *)(v957 + HIDWORD(v36) + 292);
                            v983 = 2048;
                          }
                        }
                        *(float *)((char *)&this->__vftable + v982) = (float)v984 - (float)v981;
                        if ( v981 > v900 && g_droneDebugThrusterFx.valueInteger != 0 )
                        {
                          v985 = (float)(this->thrusterLength * (float)v981);
                          this->thrusterEffect.height = this->thrusterWidth * (float)v981;
                          v986 = (float *)&v1164[9 * ii];
                          v987 = v986[5];
                          v988 = v986[4];
                          LODWORD(v1116.x) = &v1162[3 * ii];
                          v989 = v986[2];
                          v990 = v986[1];
                          v991 = v986[3];
                          v992 = v986[8];
                          v993 = v986[7];
                          v994 = *v986;
                          v995 = *(float *)(LODWORD(v1116.x) + 8);
                          v996 = (float)((float)v987 * (float)((float)v985 * (float)v900));
                          v997 = *(float *)(LODWORD(v1116.x) + 4);
                          v998 = (float)((float)v988 * (float)((float)v985 * (float)v900));
                          v999 = *(float *)LODWORD(v1116.x);
                          v1000 = (float)(v986[6] * (float)((float)v985 * (float)v900));
                          v1116.x = (float)v985 * (float)v900;
                          v1001 = *((idAnimator_ChannelWeight **)v955 + 4398);
                          v1143 = (float)v995
                                + (float)((float)((float)v992 * v1116.x)
                                        + (float)((float)((float)v989 * (float)v985) + (float)v996));
                          v1142 = (float)v997
                                + (float)((float)((float)v993 * v1116.x)
                                        + (float)((float)((float)v990 * (float)v985) + (float)v998));
                          v1141.mat[2].z = (float)v999
                                         + (float)((float)((float)v994 * (float)v985)
                                                 + (float)((float)((float)v991 * v1116.x) + (float)v1000));
                          v1002 = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: v1001);
                          idLaserBeam::Update(
                            this: &this->thrusterEffect,
                            beamEffects: v1002,
                            startPos: (const idVec3 *)&v1162[3 * ii],
                            endPos: (const idVec3 *)&v1141.mat[2].z,
                            fade: 1.0);
                        }
                        v1003 = 4 * (ii + 2882);
                        if ( (idDrone_vtbl *)v983 != *(idDrone_vtbl **)((char *)&this->__vftable + v1003) )
                        {
                          idAnimatedEntity::StopFX(this, condition: ii + 31);
                          if ( v983 != 0 )
                          {
                            v1004 = idGameTimeManager::GetGameMs(
                                      this: (idGameTimeManager *)(*((_DWORD *)v1107 + 4398) + 504064),
                                      type: GAMETIME_SCALED);
                            v1005 = idEntity::GetPhysics(this);
                            v1006 = v1005->GetAxis(this: v1005, a2: 0);
                            v1007 = idEntity::GetPhysics(this);
                            v1008 = (int)v1007->GetOrigin(this: v1007, a2: 0);
                            v1009 = this->presentable;
                            v1010 = (const idVec3 *)v1008;
                            if ( v1009 == nullptr )
                            {
                              idEntity::InitPresentableInternal(this);
                              v1009 = this->presentable;
                            }
                            idFXManager::StartFX(
                              this: &v1009->fxManager,
                              org: v1010,
                              axis: v1006,
                              time: v1004,
                              startCondition: ii + 31,
                              extraCond: v983);
                            v955 = v1107;
                          }
                          *(idDrone_vtbl **)((char *)&this->__vftable + v1003) = (idDrone_vtbl *)v983;
                        }
                      }
                      *(float *)((char *)&this->__vftable + v959) = v960;
                      if ( ii >= 2 )
                        v938 = (float)((float)v960 + (float)v938);
                      else
                        v937 = (float)((float)v960 + (float)v937);
                    }
                  }
                  goto LABEL_800;
                }
              }
              goto LABEL_859;
            }
LABEL_800:
            v1011 = v900;
            v1012 = idGameLocal::GetPlayer(this: gameLocal, i: 0);
            if ( v1012 != nullptr )
            {
              v1013 = idEntity::GetPhysics(this: v1012);
              v1014 = v1013->__vftable;
              LODWORD(v1116.x) = &this->currentPosition;
              v1015 = (float *)v1014->GetOrigin(this: v1013, a2: 0);
              v1016 = (float)(v1015[2] - this->currentPosition.z);
              v1017 = (float)(v1015[1] - this->currentPosition.y);
              v1116.x = *v1015 - this->currentPosition.x;
              v1116.z = v1016;
              v1116.y = v1017;
              if ( idVec3::NormalizeFast(this: &v1116) > 0.001 )
              {
                v1018 = this->lastMovement.y;
                v1019 = this->lastMovement.z;
                v1118.x = *(float *)v36;
                v1118.y = v1018;
                v1118.z = v1019;
                if ( idVec3::NormalizeFast(this: &v1118) > 0.000099999997 )
                  v1011 = (float)((float)(v1118.y * v1116.y)
                                + (float)((float)(v1118.x * v1116.x) + (float)(v1118.z * v1116.z)));
              }
            }
            v1020 = 1.0;
            if ( this->afterburnerAmount == v900 )
              v1021 = v900;
            else
              v1021 = 1.0;
            if ( v1011 <= v900 )
            {
              v1024 = 0.89999998;
              if ( v1011 > -1.0 )
              {
                if ( v1011 < v900 )
                  v1027 = (float)((float)((float)((float)v1011 - (float)-1.0) * (float)0.10000002) + (float)0.89999998);
                else
                  v1027 = 1.0;
              }
              else
              {
                v1027 = 0.89999998;
              }
              v1023 = (float)((float)v938 * (float)v1027);
              if ( v1011 > -1.0 )
              {
                if ( v1011 < v900 )
                  v1028 = (float)((float)((float)((float)v1011 - (float)-1.0) * (float)v900) + (float)1.0);
                else
                  v1028 = 1.0;
              }
              else
              {
                v1028 = 1.0;
              }
              v1025 = (float)((float)v937 * (float)v1028);
              if ( v1011 > -1.0 )
              {
                if ( v1011 < v900 )
                  v1029 = (float)-(float)((float)((float)((float)v1011 - (float)-1.0) * (float)v812) - (float)1.0);
                else
                  v1029 = *(float *)(HIDWORD(v36) + 728);
              }
              else
              {
                v1029 = 1.0;
              }
              v1026 = (float)((float)v1021 * (float)v1029);
            }
            else
            {
              if ( v1011 < 1.0 )
                v1022 = (float)((float)((float)v1011 * (float)v900) + (float)1.0);
              else
                v1022 = 1.0;
              v1023 = (float)((float)v938 * (float)v1022);
              v1024 = 0.89999998;
              if ( v1011 < 1.0 )
                v1025 = (float)((float)v937 * (float)-(float)((float)((float)v1011 * (float)0.10000002) - (float)1.0));
              else
                v1025 = (float)((float)v937 * (float)0.89999998);
              v1026 = (float)((float)v1021 * *(float *)(HIDWORD(v36) + 728));
            }
            v1030 = (float)(this->smallEngineThrustLevel * (float)v1024);
            v1031 = this->afterburnerThrustLevel;
            this->largeEngineThrustLevel = (float)((float)v1025 * (float)0.10000002)
                                         + (float)(this->largeEngineThrustLevel * (float)v1024);
            this->smallEngineThrustLevel = (float)((float)v1023 * (float)0.10000002) + (float)v1030;
            if ( v1026 <= v1031 )
              this->afterburnerThrustLevel = (float)((float)v1031 * *(float *)(HIDWORD(v36) - 8))
                                           + (float)((float)v1026 * v1103.x);
            else
              this->afterburnerThrustLevel = (float)((float)v1031 * (float)v1024)
                                           + (float)((float)v1026 * (float)0.10000002);
            v1032 = this->currentSpeed;
            v1033 = (float)((float)((float)v1011 * this->currentSpeed) * (float)0.125);
            if ( v1032 > *(float *)(HIDWORD(v36) + 888) )
            {
              if ( v1032 < *(float *)(HIDWORD(v36) + 896) )
                v1034 = (float)((float)(this->currentSpeed - *(float *)(HIDWORD(v36) + 888)) * (float)0.125);
              else
                v1034 = 1.0;
            }
            else
            {
              v1034 = v900;
            }
            v1035 = SND_CHANNEL_ENGINE_IDLE;
            v1036 = 0;
            if ( this->smallEngineSounds.num > 0 )
            {
              v1037 = v1104;
              v1038 = 0;
              while ( v1035 < SND_CHANNEL_WEAPON_1 )
              {
                idDrone::UpdateEngineSound(
                  this,
                  channel: v1035++,
                  engineSound: &this->smallEngineSounds.list[v1038],
                  speed: v1034,
                  closure: v1033,
                  thrust: this->smallEngineThrustLevel,
                  minThrust: v1020,
                  maxThrust: v1037[219]);
                ++v1036;
                ++v1038;
                if ( v1036 >= this->smallEngineSounds.num )
                  break;
                v1020 = 1.0;
              }
              v1024 = 0.89999998;
            }
            v1039 = 0;
            if ( this->largeEngineSounds.num > 0 )
            {
              v1040 = v1104;
              v1041 = 0;
              do
              {
                if ( v1035 >= SND_CHANNEL_WEAPON_1 )
                  break;
                idDrone::UpdateEngineSound(
                  this,
                  channel: v1035++,
                  engineSound: &this->largeEngineSounds.list[v1041],
                  speed: v1034,
                  closure: v1033,
                  thrust: this->largeEngineThrustLevel,
                  minThrust: v1040[182],
                  maxThrust: v1040[193]);
                ++v1039;
                ++v1041;
              }
              while ( v1039 < this->largeEngineSounds.num );
              v1024 = 0.89999998;
            }
            v1042 = 0;
            if ( this->afterburnerSounds.num > 0 )
            {
              v1043 = 0;
              while ( v1035 < SND_CHANNEL_WEAPON_1 )
              {
                idDrone::UpdateEngineSound(
                  this,
                  channel: v1035++,
                  engineSound: &this->afterburnerSounds.list[v1043],
                  speed: v1034,
                  closure: v1033,
                  thrust: this->afterburnerThrustLevel,
                  minThrust: 0.1,
                  maxThrust: v1024);
                ++v1042;
                ++v1043;
                if ( v1042 >= this->afterburnerSounds.num )
                  break;
                v1024 = 0.89999998;
              }
            }
            idEntity::UpdateSound(this);
            if ( this->currentScanEntityEffectOn != v1106
              && this->focusEntityMaterial != nullptr
              && g_droneDebugFakeScanner.valueInteger != 0 )
            {
              if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                                      this,
                                      propName: v1135,
                                      tagName: "scanner_effect",
                                      origin: &v1139,
                                      axis: &v1152) == 0 )
              {
LABEL_859:
                idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v1140.path);
                idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v1157);
                return;
              }
              v1044 = v1107;
              v1045 = v1152.mat[1].z;
              v1046 = v1152.mat[1].y;
              v1047 = v1152.mat[2].x;
              v1048 = v1152.mat[0].z;
              v1049 = v1152.mat[0].y;
              v1050 = v1152.mat[1].x;
              v1051 = v1152.mat[2].z;
              v1052 = v1152.mat[2].y;
              v1053 = (float)((float)(this->focusEntityLength * this->currentScanEntityEffectOn) * v1104[192]);
              v1054 = v1152.mat[0].x;
              this->focusEntityEffect.height = (float)(this->focusEntityWidth * this->currentScanEntityEffectOn)
                                             * v1104[192];
              v1103.x = v1053;
              v1055 = *((idAnimator_ChannelWeight **)v1044 + 4398);
              v1145.z = v1139.z
                      + (float)((float)((float)v1051 * (float)v1053)
                              + (float)((float)((float)v1048 * (float)v1053) + (float)((float)v1045 * (float)v1053)));
              v1145.y = v1139.y
                      + (float)((float)((float)v1052 * (float)v1053)
                              + (float)((float)((float)v1049 * (float)v1053) + (float)((float)v1046 * (float)v1053)));
              v1145.x = (float)((float)((float)v1054 * (float)v1053)
                              + (float)((float)((float)v1050 * (float)v1053) + (float)((float)v1047 * (float)v1053)))
                      + v1139.x;
              v1056 = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: v1055);
              idLaserBeam::Update(
                this: &this->focusEntityEffect,
                beamEffects: v1056,
                startPos: &v1139,
                endPos: &v1145,
                fade: 1.0);
            }
          }
          idEntity::Think(this);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v1140.path);
          idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v1157);
          return;
        }
        if ( v638 <= v598 )
          goto LABEL_590;
      }
      v638 = v598;
      goto LABEL_590;
    }
    DesiredSpeedForMoving = idDrone::GetDesiredSpeedForMoving(this);
    goto LABEL_475;
  }
  while ( 1 )
  {
    v324 = this->goals.num;
    v325 = this->currentPathType;
    v326 = &this->goalSearchDirections.list[v324];
    v327 = *(v326 - 1);
    v1102.x = *(v326 - 1);
    if ( v325 != DPT_PATROL )
      break;
    v348 = this->patrolDirection + this->patrolWaypointOn;
    this->patrolWaypointOn = v348;
    if ( v348 >= 0 )
    {
      if ( v348 >= this->patrolWaypoints.num )
        this->patrolWaypointOn = 0;
    }
    else
    {
      this->patrolWaypointOn = this->patrolWaypoints.num - 1;
    }
    v342 = this->patrolWaypoints.list[this->patrolWaypointOn];
    v1117.value = (int)v342;
LABEL_344:
    if ( v342 == nullptr )
      goto LABEL_361;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->goals,
      obj: (encounterGroupRole_t *)&v1117);
    idList<float,13>::Append(this: (idList<float,13> *)&this->goalSearchDirections, obj: &v1102.x);
    v349 = idNavSplinePathMgr::GetShortestPathByList(
             this: (idNavSplinePathMgr *)LODWORD(this->navSplinePosition.distance),
             start: (idNavSplinePosition *)LODWORD(this->navSplinePosition.rightDistance),
             waypoints: (idList<idSplineWaypoint const *,5> *)__ROL4__(this->navSplinePosition.navSpline, 32),
             path: (navSplinePath_t *)&this->goals);
    if ( v349 == nullptr || v349->path.num < 1 )
    {
      idLib::Error(fmt: "Drone '%s' could not find a path.", this->name.data);
      goto _LN2584;
    }
    if ( this->splinePathToGoal.distance > 1000.0 )
      goto LABEL_348;
  }
  if ( v325 != DPT_SEARCH )
    goto LABEL_361;
  if ( v324 > 0 )
  {
    *(float *)&v328 = COERCE_FLOAT(idDroneSplineWaypoint::CastTo(c: (*p_goals)[v324 - 1]));
    a = *(float *)&v328;
    if ( *(float *)&v328 == 0.0 )
      goto LABEL_361;
    v330 = 1;
    g = *(float *)&v328->targetWeights.num;
    v49 = v322;
    v331 = nullptr;
    v332 = v322;
    lastVisitTime = -1;
    v334 = 0;
    LODWORD(v1118.x) = v328->targets.num;
    v329 = v1118.x;
    if ( SLODWORD(v1118.x) > 0 )
    {
      v335 = 0;
      do
      {
        v336 = true;
        if ( v334 < SLODWORD(g) )
        {
          v337 = *(_DWORD *)(LODWORD(a) + 1184);
          v49 = *(float *)(v337 + v335);
          v336 = (float)(*(float *)(v337 + v335) * (float)v327) >= v322;
        }
        if ( v336 )
        {
          v1103.x = v329;
          if ( v334 < SLODWORD(v329)
            && (v338 = *(_DWORD *)(*(_DWORD *)(LODWORD(a) + 96) + v335),
                gameLocal->spawnIds.ptr[v338 & 0x1FFF] == v338 >> 13)
            && (v339 = gameLocal->entities.ptr[v338 & 0x1FFF]) != nullptr )
          {
            v340 = (idDroneSplineWaypoint *)idEntity::CastTo(c: v339);
          }
          else
          {
            v340 = nullptr;
          }
          v341 = idDroneSplineWaypoint::CastTo(c: v340);
          if ( v341 != nullptr && (v331 == nullptr || v341->lastVisitTime < lastVisitTime) )
          {
            lastVisitTime = v341->lastVisitTime;
            v332 = v49;
            v331 = v341;
            v330 = (((LODWORD(g) ^ v334) >= 0) + ((unsigned int)v334 >= LODWORD(g))) & 1;
          }
        }
        ++v334;
        v335 += 4;
        v1118.x = *(float *)(LODWORD(a) + 100);
        v329 = v1118.x;
      }
      while ( v334 < SLODWORD(v1118.x) );
      if ( v331 != nullptr )
      {
        v1117.value = (int)v331;
        v342 = (const idSplineWaypoint *)v331;
        if ( v330 != 0 && v332 == v322 )
          v1102.x = -v327;
        if ( g_droneDebugSearching.valueInteger != 0 )
        {
          v343 = idEntity::GetPhysics(this: v331);
          v344 = v343->GetOrigin(this: v343, a2: 0);
          g = COERCE_FLOAT(&v1126);
          a = this->currentPosition.y;
          v1105.distance = this->currentPosition.x;
          v1126.r = idColor::colorBlue.r;
          v1105.rightDistance = a;
          *(_QWORD *)&v1126.g = *(_QWORD *)&idColor::colorBlue.g;
          v345 = v344->x;
          *(float *)&v36 = v344->y;
          v346 = v344->z;
          v347 = this->currentPosition.z;
          v1112 = v345;
          v1113 = *(float *)&v36;
          v1114 = v346;
          *(float *)&v1105.navSpline = v347;
          v1126.a = idColor::colorBlue.a;
          (*(void (__fastcall **)(_DWORD, idColor *, idNavSplinePosition *, float *, double))(**(_DWORD **)(*((_DWORD *)v323 + 4398) + 4)
                                                                                            + 180))(
            a1: *(_DWORD *)(*((_DWORD *)v323 + 4398) + 4),
            a2: &v1126,
            a3: &v1105,
            a4: &v1112,
            a5: 150.0);
        }
        goto LABEL_344;
      }
    }
  }
  this->currentPathType = DPT_PATROL;
LABEL_361:
  this->currentPathType = DPT_PATROL;
}


// ========================================================================
// $LN2520
// EA  : 0x82C356C8
// RVA : 0x00C356C8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _LN2520()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 512));
}


// ========================================================================
// __unwind$503094
// EA  : 0x82C356F0
// RVA : 0x00C356F0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_503094()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 864));
}


// ========================================================================
// __unwind$503095
// EA  : 0x82C35718
// RVA : 0x00C35718
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_503095()
{
  int v0; // r12

  idAvoidTargetFilter::~idAvoidTargetFilter(this: (idFriendlyDeadTargetFilter *)(v0 - 2128 + 856));
}


// ========================================================================
// __unwind$503096
// EA  : 0x82C35740
// RVA : 0x00C35740
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_503096()
{
  int v0; // r12

  idEnemyTargetSelector::~idEnemyTargetSelector(this: (idNeutralTargetSelector *)(v0 - 2128 + 992));
}


// ========================================================================
// __unwind$503097
// EA  : 0x82C35768
// RVA : 0x00C35768
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_503097()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 2128 + 928));
}


// ========================================================================
// __unwind$503098
// EA  : 0x82C35790
// RVA : 0x00C35790
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void _unwind_503098()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2128 + 560));
}


// ========================================================================
// `dynamic initializer for 'g_droneStopForAI''
// EA  : 0x83375D10
// RVA : 0x01375D10
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneStopForAI__()
{
  idCVar::idCVar(
    this: &g_droneStopForAI,
    name: "g_droneStopForAI",
    value: "1",
    flags: 1,
    description: "1 = have drone stop, otherwise ai's try to avoid drones.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneStopForAI__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDisableScanning''
// EA  : 0x83375D68
// RVA : 0x01375D68
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDisableScanning__()
{
  idCVar::idCVar(
    this: &g_droneDisableScanning,
    name: "g_droneDisableScanning",
    value: "0",
    flags: 1,
    description: "1 = disable scanning so drones will not stop to scan players/ais.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDisableScanning__);
}


// ========================================================================
// `dynamic initializer for 'g_droneAllowWeaponsDeployWhenHit''
// EA  : 0x83375DC0
// RVA : 0x01375DC0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneAllowWeaponsDeployWhenHit__()
{
  idCVar::idCVar(
    this: &g_droneAllowWeaponsDeployWhenHit,
    name: "g_droneAllowWeaponsDeployWhenHit",
    value: "0",
    flags: 1,
    description: "1 = allow drone to drop it's weapons when it gets hit.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneAllowWeaponsDeployWhenHit__);
}


// ========================================================================
// `dynamic initializer for 'g_droneAllowWeaponsDeployWhenScanning''
// EA  : 0x83375E18
// RVA : 0x01375E18
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneAllowWeaponsDeployWhenScanning__()
{
  idCVar::idCVar(
    this: &g_droneAllowWeaponsDeployWhenScanning,
    name: "g_droneAllowWeaponsDeployWhenScanning",
    value: "0",
    flags: 1,
    description: "1 = allow drone to drop it's weapons when it gets hit (sometimes).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneAllowWeaponsDeployWhenScanning__);
}


// ========================================================================
// `dynamic initializer for 'g_droneMinObstacleAvoidanceSpeed''
// EA  : 0x83375E70
// RVA : 0x01375E70
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneMinObstacleAvoidanceSpeed__()
{
  idCVar::idCVar(
    this: &g_droneMinObstacleAvoidanceSpeed,
    name: "g_droneMinObstacleAvoidanceSpeed",
    value: "3",
    flags: 4,
    description: "Limit drone's speed for obstacle avoidance (range 1-15)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneMinObstacleAvoidanceSpeed__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugMovement''
// EA  : 0x83375EC8
// RVA : 0x01375EC8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugMovement__()
{
  idCVar::idCVar(
    this: &g_droneDebugMovement,
    name: "g_droneDebugMovement",
    value: "0",
    flags: 1,
    description: "1 = show movement info for the drone.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugMovement__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugWaypoints''
// EA  : 0x83375F20
// RVA : 0x01375F20
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugWaypoints__()
{
  idCVar::idCVar(
    this: &g_droneDebugWaypoints,
    name: "g_droneDebugWaypoints",
    value: "0",
    flags: 1,
    description: "1 = show drone waypoints.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugWaypoints__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugTurnUpBeforeGoingUp''
// EA  : 0x83375F78
// RVA : 0x01375F78
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugTurnUpBeforeGoingUp__()
{
  idCVar::idCVar(
    this: &g_droneDebugTurnUpBeforeGoingUp,
    name: "g_droneDebugTurnUpBeforeGoingUp",
    value: "0",
    flags: 1,
    description: "1 = show drone's decision to look up when approaching a hill.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugTurnUpBeforeGoingUp__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugOnlyUpdateOne''
// EA  : 0x83375FD0
// RVA : 0x01375FD0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugOnlyUpdateOne__()
{
  idCVar::idCVar(
    this: &g_droneDebugOnlyUpdateOne,
    name: "g_droneDebugOnlyUpdateOne",
    value: "0",
    flags: 2,
    description: "# = only run update on 'ai_vehicle_drone_###'.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugOnlyUpdateOne__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugNoDamage''
// EA  : 0x83376028
// RVA : 0x01376028
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugNoDamage__()
{
  idCVar::idCVar(
    this: &g_droneDebugNoDamage,
    name: "g_droneDebugNoDamage",
    value: "0",
    flags: 1,
    description: "1 = drones never die.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugNoDamage__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugShowWallCollisions''
// EA  : 0x83376080
// RVA : 0x01376080
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugShowWallCollisions__()
{
  idCVar::idCVar(
    this: &g_droneDebugShowWallCollisions,
    name: "g_droneDebugShowWallCollisions",
    value: "0",
    flags: 1,
    description: "1 = draw debug spheres to show drone wall collisions.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugShowWallCollisions__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugAiCollisions''
// EA  : 0x833760D8
// RVA : 0x013760D8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugAiCollisions__()
{
  idCVar::idCVar(
    this: &g_droneDebugAiCollisions,
    name: "g_droneDebugAiCollisions",
    value: "0",
    flags: 1,
    description: "1 = draw debugging info for drone-to-ai collision avoidance.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugAiCollisions__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugPlayerCollisions''
// EA  : 0x83376130
// RVA : 0x01376130
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugPlayerCollisions__()
{
  idCVar::idCVar(
    this: &g_droneDebugPlayerCollisions,
    name: "g_droneDebugPlayerCollisions",
    value: "0",
    flags: 1,
    description: " 1 = draw debugging info for drone-to-player collision avoidance.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugPlayerCollisions__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugShowThrust''
// EA  : 0x83376188
// RVA : 0x01376188
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugShowThrust__()
{
  idCVar::idCVar(
    this: &g_droneDebugShowThrust,
    name: "g_droneDebugShowThrust",
    value: "0",
    flags: 1,
    description: "1 = draw debug details for thrust.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugShowThrust__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugShowThrusterHistory''
// EA  : 0x833761E0
// RVA : 0x013761E0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugShowThrusterHistory__()
{
  idCVar::idCVar(
    this: &g_droneDebugShowThrusterHistory,
    name: "g_droneDebugShowThrusterHistory",
    value: "0",
    flags: 1,
    description: "1 = draw debug details for thrust so changes can be seen.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugShowThrusterHistory__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugForceDroneState''
// EA  : 0x83376238
// RVA : 0x01376238
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugForceDroneState__()
{
  idCVar::idCVar(
    this: &g_droneDebugForceDroneState,
    name: "g_droneDebugForceDroneState",
    value: "-1",
    flags: 2,
    description: ">=0 = force drones into specified state.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugForceDroneState__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugForceMoveState''
// EA  : 0x83376290
// RVA : 0x01376290
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugForceMoveState__()
{
  idCVar::idCVar(
    this: &g_droneDebugForceMoveState,
    name: "g_droneDebugForceMoveState",
    value: "-1",
    flags: 2,
    description: ">=0 = force drones into specified move state.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugForceMoveState__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugFocusEntities''
// EA  : 0x833762E8
// RVA : 0x013762E8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugFocusEntities__()
{
  idCVar::idCVar(
    this: &g_droneDebugFocusEntities,
    name: "g_droneDebugFocusEntities",
    value: "0",
    flags: 1,
    description: "1 = draw debug arrows to show who drones are scanning.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugFocusEntities__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugClipTranslations''
// EA  : 0x83376340
// RVA : 0x01376340
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugClipTranslations__()
{
  idCVar::idCVar(
    this: &g_droneDebugClipTranslations,
    name: "g_droneDebugClipTranslations",
    value: "0",
    flags: 1,
    description: "1 = draw debug arrows to show deferred, spark-checking clip translations.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugClipTranslations__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugGroundFX''
// EA  : 0x83376398
// RVA : 0x01376398
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugGroundFX__()
{
  idCVar::idCVar(
    this: &g_droneDebugGroundFX,
    name: "g_droneDebugGroundFX",
    value: "0",
    flags: 1,
    description: "Debug ground fx",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugGroundFX__);
}


// ========================================================================
// `dynamic initializer for 'g_droneFoliageSinRate''
// EA  : 0x833763F0
// RVA : 0x013763F0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneFoliageSinRate__()
{
  idCVar::idCVar(
    this: &g_droneFoliageSinRate,
    name: "g_droneFoliageSinRate",
    value: "0.04",
    flags: 4,
    description: "Rate at which foliage oscillates when drone is hovering over it",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneFoliageSinRate__);
}


// ========================================================================
// `dynamic initializer for 'g_droneFoliageHighAngle''
// EA  : 0x83376448
// RVA : 0x01376448
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneFoliageHighAngle__()
{
  idCVar::idCVar(
    this: &g_droneFoliageHighAngle,
    name: "g_droneFoliageHighAngle",
    value: "45",
    flags: 4,
    description: "The max angle in degrees that foliage will lean over",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneFoliageHighAngle__);
}


// ========================================================================
// `dynamic initializer for 'g_droneFoliageLowAngle''
// EA  : 0x833764A0
// RVA : 0x013764A0
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneFoliageLowAngle__()
{
  idCVar::idCVar(
    this: &g_droneFoliageLowAngle,
    name: "g_droneFoliageLowAngle",
    value: "35",
    flags: 4,
    description: "The low angle in degrees that foliage will lean over",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneFoliageLowAngle__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugFakeScanner''
// EA  : 0x833764F8
// RVA : 0x013764F8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugFakeScanner__()
{
  idCVar::idCVar(
    this: &g_droneDebugFakeScanner,
    name: "g_droneDebugFakeScanner",
    value: "0",
    flags: 1,
    description: "1 = show the fake scanner to demonstrate the drone is in that mode.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugFakeScanner__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugSearching''
// EA  : 0x83376550
// RVA : 0x01376550
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugSearching__()
{
  idCVar::idCVar(
    this: &g_droneDebugSearching,
    name: "g_droneDebugSearching",
    value: "0",
    flags: 1,
    description: "1 = desired paths and search times for searching waypoints.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugSearching__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugThrusterLevels''
// EA  : 0x833765A8
// RVA : 0x013765A8
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugThrusterLevels__()
{
  idCVar::idCVar(
    this: &g_droneDebugThrusterLevels,
    name: "g_droneDebugThrusterLevels",
    value: "1",
    flags: 1,
    description: "1 = show variable length thrusters to help visualize drone physics.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugThrusterLevels__);
}


// ========================================================================
// `dynamic initializer for 'g_droneDebugThrusterFx''
// EA  : 0x83376600
// RVA : 0x01376600
// PDB : w:\tech5\tungsten\game\entities\drone.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droneDebugThrusterFx__()
{
  idCVar::idCVar(
    this: &g_droneDebugThrusterFx,
    name: "g_droneDebugThrusterFx",
    value: "0",
    flags: 1,
    description: "1 = show debug thrusters at set lengths for on / max",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droneDebugThrusterFx__);
}

