
// ========================================================================
// ?UpdatePropellerVisuals@idDropShip@@AAAX_N@Z
// EA  : 0x82C357B8
// RVA : 0x00C357B8
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::UpdatePropellerVisuals(idDropShip *this, bool on)
{
  if ( on )
  {
    idAlarm::StartFX(this, condition: FX_VEH_START_BOOST);
    idAlarm::StartFX(this, condition: FX_VEH_START_BOOST2);
    idAlarm::StartFX(this, condition: FX_VEH_START_BOOST3);
  }
  else
  {
    idAnimatedEntity::StopFX(this, condition: 2);
    idAnimatedEntity::StopFX(this, condition: 4);
    idAnimatedEntity::StopFX(this, condition: 6);
  }
}


// ========================================================================
// ?State_Done@idDropShip@@AAAXXZ
// EA  : 0x82C35840
// RVA : 0x00C35840
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::State_Done(idDropShip *this)
{
  if ( this->stateTimer == -1 )
    this->stateTimer = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->stateStartTime
                                                                                                + 5000 )
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?ChangeState@idDropShip@@AAAXW4dropShipState_t@@@Z
// EA  : 0x82C358B8
// RVA : 0x00C358B8
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::ChangeState(idDropShip *this, dropShipState_t newState)
{
  this->dropShipState = newState;
  this->stateStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->stateTimer = -1;
}


// ========================================================================
// ?UpdateSounds@idDropShip@@AAAXXZ
// EA  : 0x82C35908
// RVA : 0x00C35908
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::UpdateSounds(idDropShip *this)
{
  int num; // r30
  double v3; // fp31
  int v4; // r9
  idDropShip::dropShipSound_t *list; // r8
  double v25; // fp13
  int v26; // r10
  int v27; // r9
  int v28; // ctr
  double v29; // fp0
  double minVolume; // fp11
  double v31; // fp7
  __int64 v32; // r8
  dropShipState_t v33; // r11
  dropShipState_t dropShipState; // r11
  __int64 v35; // r9
  double v36; // fp31
  __int64 v37; // r9
  int i; // r31
  int v39; // r31
  _BYTE v40[32]; // [sp+58h] [-68h] BYREF

  num = this->dropShipSound.num;
  v3 = (float)(this->soundFadeTime * (float)1000.0);
  if ( num >= 3 )
    num = 3;
  v4 = 0;
  if ( v4 < num )
  {
    list = this->dropShipSound.list;
    v25 = (float)(this->currentDt * (float)0.0625);
    v26 = 4 * v4;
    v28 = num - v4;
    v27 = v4;
    do
    {
      if ( v25 >= 0.0 )
      {
        if ( v25 <= 1.0 )
          v29 = v25;
        else
          v29 = 1.0;
      }
      else
      {
        v29 = 0.0;
      }
      minVolume = list[v27].minVolume;
      v31 = (float)(list[v27].maxVolume - list[v27].minVolume);
      *(float *)&v40[v26 + 16] = (float)((float)(list[v27].maxPitch - list[v27].minPitch) * (float)v29)
                               + list[v27].minPitch;
      ++v27;
      *(float *)&v40[v26] = (float)((float)v31 * (float)v29) + (float)minVolume;
      v26 += 4;
      --v28;
    }
    while ( v28 != 0 );
  }
  LODWORD(v32) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
               - this->soundStartTime;
  if ( (float)v32 <= v3 || (v33 = this->dropShipState) == DPSP_DONE || v33 == DPSP_POWERDOWN )
  {
    dropShipState = this->dropShipState;
    if ( dropShipState == DPSP_DONE || dropShipState == DPSP_POWERDOWN )
    {
      LODWORD(v37) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                   - this->stateStartTime;
      v36 = (float)((float)1.0 - (float)((float)v37 / (float)v3));
    }
    else
    {
      LODWORD(v35) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                   - this->soundStartTime;
      v36 = (float)((float)v35 / (float)v3);
    }
    if ( v36 >= 0.0 )
    {
      if ( v36 > 1.0 )
        v36 = 1.0;
    }
    else
    {
      v36 = 0.0;
    }
    for ( i = 0; i < 3; ++i )
    {
      if ( idEntity::GetCurrentSoundShader(this, channel: Sound_Channels[i]) != nullptr )
        *(float *)&v40[i * 4] = (float)((float)(*(float *)&v40[i * 4] + (float)60.0) * (float)v36) - (float)60.0;
    }
  }
  if ( num > 0 )
  {
    v39 = 0;
    do
    {
      idEntity::SetSoundPitch(this, channel: Sound_Channels[v39], pitch: *(float *)&v40[v39 * 4 + 16]);
      idEntity::SetSoundVolume(this, channel: Sound_Channels[v39], volume: *(float *)&v40[v39 * 4]);
      --num;
      ++v39;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?GetDropLocation@idDropShip@@AAA?AVidVec3@@H@Z
// EA  : 0x82C35D10
// RVA : 0x00C35D10
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

idDropShip *__fastcall idDropShip::GetDropLocation(idDropShip *this, idAnimatedEntity *result, int index)
{
  int v5; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v7; // r27
  idPhysics *v8; // r3
  int v9; // r3
  idList<idEventReceiver *,5> *v10; // r6
  idList<idEventReceiver *,5> *v11; // r5
  idPropsCollection *decl; // r11
  idPhysics *v14; // r3
  int v15; // r3
  idList<idEventReceiver *,5> *v16; // r6
  idList<idEventReceiver *,5> *v17; // r5
  const tagData_t *Tag; // r4
  idPhysics *Physics; // r29
  idPhysics *v20; // r3
  float *v21; // r30
  float *v22; // r3
  double v23; // fp10
  double v24; // fp31
  double v25; // fp12
  double v26; // fp9
  idVec3 v27; // [sp+50h] [-70h] BYREF
  idMat3 v28; // [sp+60h] [-60h] BYREF

  v5 = index % 3;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  v7 = TreeAnimatorFromPresentable;
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    decl = (idPropsCollection *)TreeAnimatorFromPresentable->decl;
    if ( decl != nullptr && decl != (idPropsCollection *)-352 )
    {
      Tag = idPropsCollection::GetTag(this: decl + 22, propName: "_info", tagName: dropLocationNames[v5].data);
      if ( Tag->parentJoint.value == 0xFFFF )
        idLib::Error(fmt: "Invalid tag '%s' found for '%s", dropLocationNames[v5].data, result->name.data);
      idTreeAnimator::GetModelSpaceTagTransform(this: v7, tagData: Tag, origin: &v27, axis: &v28);
      Physics = idEntity::GetPhysics(this: result);
      v20 = idEntity::GetPhysics(this: result);
      v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
      v22 = (float *)Physics->GetAxis(this: Physics, a2: 0);
      v23 = v21[1];
      v24 = v21[2];
      v25 = (float)((float)(v22[4] * v27.y) + (float)((float)(v22[1] * v27.x) + (float)(v22[7] * v27.z)));
      v26 = (float)((float)(v22[5] * v27.y) + (float)((float)(v22[2] * v27.x) + (float)(v22[8] * v27.z)));
      *(float *)&this->__vftable = *v21
                                 + (float)((float)(*v22 * v27.x)
                                         + (float)((float)(v22[6] * v27.z) + (float)(v22[3] * v27.y)));
      *(float *)&this->listenerList = (float)v23 + (float)v25;
      *(float *)&this->listeningToList = (float)v24 + (float)v26;
      return this;
    }
    else
    {
      idLib::Warning(fmt: "No props collection found for drop ship '%s'", result->name.data);
      v14 = idEntity::GetPhysics(this: result);
      v15 = (int)v14->GetOrigin(this: v14, a2: 0);
      v16 = *(idList<idEventReceiver *,5> **)(v15 + 4);
      v17 = *(idList<idEventReceiver *,5> **)(v15 + 8);
      this->__vftable = *(idDropShip_vtbl **)v15;
      this->listenerList = v16;
      this->listeningToList = v17;
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "No treeanimator for dropship '%s'", result->name.data);
    v8 = idEntity::GetPhysics(this: result);
    v9 = (int)v8->GetOrigin(this: v8, a2: 0);
    v10 = *(idList<idEventReceiver *,5> **)(v9 + 4);
    v11 = *(idList<idEventReceiver *,5> **)(v9 + 8);
    this->__vftable = *(idDropShip_vtbl **)v9;
    this->listenerList = v10;
    this->listeningToList = v11;
    return this;
  }
}


// ========================================================================
// ?ModifyAxisFromMovementSpring@idDropShip@@ABAXAAVidMat3@@@Z
// EA  : 0x82C35F48
// RVA : 0x00C35F48
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::ModifyAxisFromMovementSpring(idDropShip *this, idMat3 *axis)
{
  double v3; // fp31
  double v4; // fp30
  double v6; // fp29
  double valueFloat; // fp13
  double v8; // fp0
  double v9; // fp13
  double v10; // fp13
  double v11; // fp0
  double v12; // fp0

  v3 = (float)(this->movementSpring.p1.y - this->movementSpring.p0.y);
  v4 = (float)(this->movementSpring.p1.z - this->movementSpring.p0.z);
  v6 = (float)(this->movementSpring.p1.x - this->movementSpring.p0.x);
  valueFloat = dropShip_SpringPitchClamp.valueFloat;
  v8 = (float)((float)(this->currentAxis.mat[0].x * (float)(this->movementSpring.p1.x - this->movementSpring.p0.x))
             + (float)((float)(this->currentAxis.mat[0].z
                             * (float)(this->movementSpring.p1.z - this->movementSpring.p0.z))
                     + (float)(this->currentAxis.mat[0].y
                             * (float)(this->movementSpring.p1.y - this->movementSpring.p0.y))));
  if ( v8 >= -dropShip_SpringPitchClamp.valueFloat )
  {
    if ( v8 > valueFloat )
      v8 = dropShip_SpringPitchClamp.valueFloat;
  }
  else
  {
    v8 = -dropShip_SpringPitchClamp.valueFloat;
  }
  if ( valueFloat == 0.0 )
    v9 = 0.0;
  else
    v9 = (float)((float)v8 / dropShip_SpringPitchClamp.valueFloat);
  idMat3::RotateSelf(
    this: axis,
    axis: &axis->mat[1],
    angle: (float)((float)(dropShip_SpringMaxPitch.valueFloat * (float)v9) * idMath::M_DEG2RAD));
  v10 = dropShip_SpringRollClamp.valueFloat;
  v11 = (float)((float)(this->currentAxis.mat[1].x * (float)v6)
              + (float)((float)(this->currentAxis.mat[1].z * (float)v4) + (float)(this->currentAxis.mat[1].y * (float)v3)));
  if ( v11 >= -dropShip_SpringRollClamp.valueFloat )
  {
    if ( v11 > v10 )
      v11 = dropShip_SpringRollClamp.valueFloat;
  }
  else
  {
    v11 = -dropShip_SpringRollClamp.valueFloat;
  }
  if ( v10 == 0.0 )
    v12 = 0.0;
  else
    v12 = (float)((float)v11 / dropShip_SpringRollClamp.valueFloat);
  idMat3::RotateSelf(
    this: axis,
    axis: axis->mat,
    angle: (float)((float)(dropShip_SpringMaxRoll.valueFloat * (float)v12) * idMath::M_DEG2RAD));
}


// ========================================================================
// ?Show@idDropShip@@UAAXXZ
// EA  : 0x82C360E8
// RVA : 0x00C360E8
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::Show(idDropShip *this)
{
  int GameMs; // r3
  int num; // r10
  int v4; // r27
  int v5; // r28
  soundChannel_t *v6; // r29
  idPresentable *presentable; // r3
  idPresentable *v8; // r3
  idDropShip::dropShipSound_t *list; // r30
  unsigned __int8 v10; // r5
  idPresentable *v11; // r11
  soundShaderParms_t v12; // [sp+50h] [-E0h] BYREF

  idEntity::Show(this);
  idDropShip::UpdatePropellerVisuals(this, on: true);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  num = this->dropShipSound.num;
  this->soundStartTime = GameMs;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    v6 = (soundChannel_t *)Sound_Channels;
    do
    {
      if ( this->dropShipSound.list[v5].sound == nullptr )
      {
        idLib::Error(fmt: "DropShip '%s' has null sound for index %d", this->name.data, v4);
        JUMPOUT(0x82C36234);
      }
      if ( v4 < 3 )
      {
        presentable = this->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        if ( !idPresentable::IsPlayingSound(this: presentable, channel: *v6) )
        {
          soundShaderParms_t::Clear(this: &v12);
          v8 = this->presentable;
          list = this->dropShipSound.list;
          v12.soundShaderFlags = SSF_LOOPING;
          if ( v8 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v8 = this->presentable;
          }
          idPresentable::StartSoundShader(this: v8, channel: *v6, shader: list[v5].sound, parms: &v12, peerMask: 0);
          v11 = this->presentable;
          if ( v11 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v11 = this->presentable;
          }
          idPresentable::SetSoundVolume(this: v11, channel: *v6, volume: -60.0, peerMask: v10, a5: 0);
        }
      }
      ++v4;
      ++v5;
      ++v6;
    }
    while ( v4 < this->dropShipSound.num );
  }
}


// ========================================================================
// ?State_EnRoute@idDropShip@@AAAXXZ
// EA  : 0x82C36238
// RVA : 0x00C36238
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::State_EnRoute(idDropShip *this)
{
  if ( this->stateTimer == -1 )
    this->stateTimer = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( this->currentSpline->IsDone(this: this->currentSpline, a2: this->currentSplineTime) )
  {
    this->dropShipState = DPSP_DROPCARGO;
    this->stateStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->stateTimer = -1;
  }
}


// ========================================================================
// ?State_HeadingOut@idDropShip@@AAAXXZ
// EA  : 0x82C362C8
// RVA : 0x00C362C8
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::State_HeadingOut(idDropShip *this)
{
  dropShipState_t v2; // r11

  if ( this->stateTimer == -1 )
    this->stateTimer = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( this->currentSpline->IsDone(this: this->currentSpline, a2: this->currentSplineTime) )
  {
    v2 = DPSP_POWERDOWN;
    if ( !this->powerDownAtEndOfSpline )
      v2 = DPSP_DONE;
    this->dropShipState = v2;
    this->stateStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->stateTimer = -1;
  }
}


// ========================================================================
// ?State_PowerDown@idDropShip@@AAAXXZ
// EA  : 0x82C36368
// RVA : 0x00C36368
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::State_PowerDown(idDropShip *this)
{
  __int128 v2; // r9
  int GameMs; // r3
  const idSoundShader *powerDownSound; // r11
  idPresentable *presentable; // r3
  soundShaderParms_t v6; // [sp+60h] [-C0h] BYREF

  if ( this->stateTimer == -1 )
  {
    LODWORD(v2) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    DWORD2(v2) = this->stateStartTime;
    if ( (float)(__int64)v2 >= (double)(float)((float)(this->timeToPowerDown * (float)1000.0)
                                             + (float)*(__int64 *)((char *)&v2 + 4)) )
    {
      idDropShip::UpdatePropellerVisuals(this, on: false);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      powerDownSound = this->powerDownSound;
      this->stateTimer = GameMs;
      if ( powerDownSound != nullptr )
      {
        soundShaderParms_t::Clear(this: &v6);
        presentable = this->presentable;
        v6.soundShaderFlags = 0;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        idPresentable::StartSoundShader(
          this: presentable,
          channel: SND_CHANNEL_ANY,
          shader: this->powerDownSound,
          parms: &v6,
          peerMask: 0);
      }
      this->dropShipState = DPSP_LANDED;
      this->stateStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      this->stateTimer = -1;
      idEntity::BecomeInactive(this, flags: 1);
    }
  }
}


// ========================================================================
// ?RunPhysics@idDropShip@@AAAXXZ
// EA  : 0x82C36488
// RVA : 0x00C36488
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::RunPhysics(idDropShip *this)
{
  idCurve_Spline<idVec3> *currentSpline; // r3
  double v3; // fp28
  int num; // r30
  __int64 v5; // r8
  double v6; // fp30
  __int64 v7; // r4
  double v8; // fp1
  double v9; // fp12
  __int64 v10; // r9
  __int64 v11; // r7
  double v12; // fp13
  double v13; // fp0
  _DWORD *v14; // r11
  _DWORD *v15; // r11
  idCurve_Spline<idVec3> *v16; // r3
  double currentSplineTime; // fp1
  float *v18; // r3
  double v19; // fp1
  double x; // fp12
  double y; // fp11
  double v22; // fp13
  idPhysics *Physics; // r3
  double v24; // fp11
  double v25; // fp9
  double v26; // fp10
  idPhysics *v27; // r3
  float *v28; // r3
  char *v29; // r10
  double v30; // fp13
  float *p_restLength; // r11
  double v34; // fp2
  double v35; // fp2
  double v36; // fp4
  double v37; // fp3
  double v38; // fp1
  double v39; // fp11
  double v40; // fp10
  double v42; // fp5
  double v44; // fp3
  double v45; // fp3
  double v46; // fp6
  double v47; // fp5
  double v48; // fp4
  double v49; // fp2
  double v50; // fp1
  double v51; // fp9
  double v52; // fp6
  double v54; // fp4
  double v56; // fp11
  double v57; // fp6
  double v58; // fp11
  double v59; // fp10
  int i; // ctr
  double v67; // fp5
  double v68; // fp4
  double v69; // fp3
  double v70; // fp2
  double v71; // fp1
  double v72; // fp13
  double v73; // fp2
  double v74; // fp1
  double v75; // fp0
  double v76; // fp10
  double v77; // fp0
  double v78; // fp13
  double v79; // fp0
  double v80; // fp11
  double v81; // fp0
  double v82; // fp10
  double z; // fp9
  double v84; // fp8
  double v85; // fp7
  double v86; // fp6
  double v87; // fp5
  double v88; // fp4
  double v89; // fp0
  int GameMs; // r3
  __int64 v91; // r10
  __int64 v92; // r7
  double v93; // fp1
  double v94; // fp31
  double v95; // fp1
  double v96; // fp1
  double v97; // fp1
  idPhysics *v98; // r3
  __int64 v99; // [sp+58h] [-E8h] BYREF
  float v100; // [sp+68h] [-D8h] BYREF
  float v101; // [sp+6Ch] [-D4h]
  float v102; // [sp+70h] [-D0h]
  idVec3 v103; // [sp+78h] [-C8h] BYREF
  idMat3 v104; // [sp+90h] [-B0h] BYREF
  char v105; // [sp+BCh] [-84h] BYREF
  float v106; // [sp+C0h] [-80h]
  float v107; // [sp+C4h] [-7Ch]
  float v108; // [sp+CCh] [-74h]
  float v109; // [sp+D0h] [-70h]

  currentSpline = this->currentSpline;
  v3 = 0.0;
  if ( currentSpline == nullptr )
    return;
  num = this->speedTable.num;
  if ( this->dropShipState == DPSP_HOVER || currentSpline->IsDone(this: currentSpline, a2: this->currentSplineTime) )
    goto LABEL_20;
  LODWORD(v5) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  v3 = (float)v5;
  v6 = ((double (__fastcall *)(idCurve_Spline<idVec3> *, double))this->currentSpline->GetLengthForTime)(
         a1: this->currentSpline,
         a2: this->currentSplineTime);
  v8 = ((double (__fastcall *)(idCurve_Spline<idVec3> *, double))this->currentSpline->GetLengthForTime)(
         a1: this->currentSpline,
         a2: this->currentSpline->times.list[this->currentSpline->values.num - 1]);
  v9 = (float)((float)v8 - (float)v6);
  HIDWORD(v10) = 1;
  if ( num <= 1 )
    goto LABEL_19;
  HIDWORD(v11) = this->speedTable.list;
  LODWORD(v11) = 8;
  while ( 1 )
  {
    LODWORD(v10) = *(_DWORD *)(HIDWORD(v11) + v11);
    v12 = (float)v10;
    if ( v6 >= v12 && v9 >= v12 )
      goto LABEL_12;
    if ( this->splines.list[this->currentSplineIdx].speed < (double)*(float *)(HIDWORD(v11) + v11 + 4) )
      goto LABEL_19;
    v13 = 1.0;
    if ( this->dropShipState != DPSP_ENROUTE )
      break;
    if ( v9 < v12 )
    {
      v14 = (_DWORD *)(8 * HIDWORD(v10) + HIDWORD(v11));
      LODWORD(v11) = *v14;
      LODWORD(v7) = *v14 - *(v14 - 2);
      v13 = (float)((float)1.0 - (float)((float)((float)v11 - (float)((float)v8 - (float)v6)) / (float)v7));
      goto LABEL_18;
    }
    if ( SHIDWORD(v10) >= num - 1 )
      goto LABEL_18;
LABEL_12:
    ++HIDWORD(v10);
    LODWORD(v11) = v11 + 8;
    if ( SHIDWORD(v10) >= num )
      goto LABEL_19;
  }
  v15 = (_DWORD *)(8 * HIDWORD(v10) + HIDWORD(v11));
  LODWORD(v11) = *v15;
  LODWORD(v7) = *v15 - *(v15 - 2);
  if ( v9 >= v6 )
    v13 = (float)((float)1.0 - (float)((float)((float)v11 - (float)v6) / (float)v7));
  else
    v13 = (float)((float)1.0 - (float)((float)((float)v11 - (float)((float)v8 - (float)v6)) / (float)v7));
LABEL_18:
  v3 = (float)((float)((float)((float)((float)(*(float *)(8 * HIDWORD(v10) + HIDWORD(v11) + 4)
                                             - *(float *)(8 * HIDWORD(v10) + HIDWORD(v11) - 4))
                                     * (float)v13)
                             + *(float *)(8 * HIDWORD(v10) + HIDWORD(v11) - 4))
                     / this->splines.list[this->currentSplineIdx].speed)
             * (float)v3);
LABEL_19:
  this->currentSplineTime = this->currentDt + this->currentSplineTime;
LABEL_20:
  v16 = this->currentSpline;
  currentSplineTime = this->currentSplineTime;
  this->currentDt = (float)((float)((float)v3 - this->currentDt) * realToActualDT) + this->currentDt;
  if ( !v16->IsDone(this: v16, a2: currentSplineTime) )
  {
    v18 = (float *)((int (__fastcall *)(__int64 *, double))this->currentSpline->GetCurrentValue)(
                     a1: &v99,
                     a2: this->currentSplineTime);
    this->movementSpring.p0.x = *v18;
    this->movementSpring.p0.y = v18[1];
    this->movementSpring.p0.z = v18[2];
  }
  this->movementSpring.maxSpeed = dropShip_SpringMaxSpeed.valueFloat;
  v19 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetRealSecPerFrame)(a1: gameLocal, a2: 1);
  idSpring<idVec3>::Update(this: &this->movementSpring, dt: v19);
  x = this->movementSpring.p1.x;
  y = this->movementSpring.p1.y;
  v22 = (float)(dropShip_SpringGravity.valueFloat * (float)0.0);
  this->movementSpring.p1.z = this->movementSpring.p1.z - dropShip_SpringGravity.valueFloat;
  this->movementSpring.p1.x = (float)x - (float)v22;
  this->movementSpring.p1.y = (float)y - (float)v22;
  Physics = idEntity::GetPhysics(this);
  Physics->SetOrigin(this: Physics, a2: &this->movementSpring.p1, a3: -1);
  ((void (__fastcall *)(float *, double))this->currentSpline->GetCurrentFirstDerivative)(
    a1: &v100,
    a2: this->currentSplineTime);
  v24 = v102;
  v25 = v100;
  v26 = v101;
  if ( __fabs(v102) > __fabs(v100) && __fabs(v24) > __fabs(v26) )
  {
    v27 = idEntity::GetPhysics(this);
    v28 = (float *)v27->GetAxis(this: v27, a2: 0);
    v25 = *v28;
    v100 = *v28;
    v26 = v28[1];
    v101 = v28[1];
    v24 = v28[2];
  }
  v29 = &v105;
  v30 = idMath::FLT_SMALLEST_NON_DENORMAL;
  p_restLength = &this->movementSpring.restLength;
  _FP5 = (float)((float)((float)((float)v24 * (float)v24)
                       + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v34 = __frsqrte(_FP3);
  v35 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34
                                                                                      * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                                                                                              * (float)0.5))
                                                                              * (float)v34)
                                                                      - (float)1.5)
                                                      * (float)v34)
                                              * (float)((float)((float)((float)v24 * (float)v24)
                                                              + (float)((float)((float)v26 * (float)v26)
                                                                      + (float)((float)v25 * (float)v25)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v34
                                                                              * (float)((float)((float)((float)v24 * (float)v24)
                                                                                              + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                                                                                      * (float)0.5))
                                                                      * (float)v34)
                                                              - (float)1.5)
                                              * (float)v34))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v34
                                                      * (float)((float)((float)((float)v24 * (float)v24)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v34)
                                      - (float)1.5)
                      * (float)v34));
  v36 = (float)((float)((float)-(float)((float)((float)((float)v35
                                                      * (float)((float)((float)((float)v24 * (float)v24)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v35)
                                      - (float)1.5)
                      * (float)v35)
              * (float)v26);
  v37 = (float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                              * (float)((float)((float)((float)v24 * (float)v24)
                                                                              + (float)((float)((float)v26 * (float)v26)
                                                                                      + (float)((float)v25 * (float)v25)))
                                                                      * (float)0.5))
                                                      * (float)v35)
                                              - (float)1.5)
                              * (float)v35)
                      * (float)v24)
              * (float)0.0);
  v38 = (float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                              * (float)((float)((float)((float)v24 * (float)v24)
                                                                              + (float)((float)((float)v26 * (float)v26)
                                                                                      + (float)((float)v25 * (float)v25)))
                                                                      * (float)0.5))
                                                      * (float)v35)
                                              - (float)1.5)
                              * (float)v35)
                      * (float)v25)
              - (float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                      * (float)((float)((float)((float)v24 * (float)v24)
                                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                                              + (float)((float)v25 * (float)v25)))
                                                                              * (float)0.5))
                                                              * (float)v35)
                                                      - (float)1.5)
                                      * (float)v35)
                              * (float)v24)
                      * (float)0.0));
  v39 = (float)((float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                      * (float)((float)((float)((float)v24 * (float)v24)
                                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                                              + (float)((float)v25 * (float)v25)))
                                                                              * (float)0.5))
                                                              * (float)v35)
                                                      - (float)1.5)
                                      * (float)v35)
                              * (float)v26)
                      * (float)0.0)
              - (float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                      * (float)((float)((float)((float)v24 * (float)v24)
                                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                                              + (float)((float)v25 * (float)v25)))
                                                                              * (float)0.5))
                                                              * (float)v35)
                                                      - (float)1.5)
                                      * (float)v35)
                              * (float)v25)
                      * (float)0.0));
  v40 = (float)((float)v37 - (float)v36);
  _FP6 = (float)((float)((float)((float)((float)v37 - (float)v36) * (float)((float)v37 - (float)v36))
                       + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v42 = (float)((float)((float)((float)((float)v37 - (float)v36) * (float)((float)v37 - (float)v36))
                      + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
              * (float)0.5);
  __asm { fsel      f4, f6, f7, f13 }
  v44 = __frsqrte(_FP4);
  v45 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v42)
                                                                              * (float)v44)
                                                                      - (float)1.5)
                                                      * (float)v44)
                                              * (float)v42)
                                      * (float)((float)-(float)((float)((float)((float)v44 * (float)v42) * (float)v44)
                                                              - (float)1.5)
                                              * (float)v44))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v44 * (float)v42) * (float)v44) - (float)1.5) * (float)v44));
  v46 = (float)((float)v40
              * (float)((float)-(float)((float)((float)((float)v45 * (float)v42) * (float)v45) - (float)1.5) * (float)v45));
  v48 = (float)((float)((float)v39
                      * (float)((float)-(float)((float)((float)((float)v45 * (float)v42) * (float)v45) - (float)1.5)
                              * (float)v45))
              * (float)0.0);
  v49 = (float)((float)((float)((float)v39
                              * (float)((float)-(float)((float)((float)((float)v45 * (float)v42) * (float)v45)
                                                      - (float)1.5)
                                      * (float)v45))
                      * (float)0.0)
              - (float)((float)v40
                      * (float)((float)-(float)((float)((float)((float)v45 * (float)v42) * (float)v45) - (float)1.5)
                              * (float)v45)));
  v47 = (float)((float)v38
              * (float)((float)-(float)((float)((float)((float)v45 * (float)v42) * (float)v45) - (float)1.5) * (float)v45));
  v50 = (float)((float)v47 - (float)v48);
  v51 = (float)((float)((float)v46 * (float)0.0) - (float)((float)v47 * (float)0.0));
  v52 = (float)((float)((float)((float)v47 - (float)v48) * (float)((float)v47 - (float)v48))
              + (float)((float)((float)v51 * (float)v51)
                      + (float)((float)((float)v48 - (float)v46) * (float)((float)v48 - (float)v46))));
  _FP5 = (float)((float)v52 - idMath::FLT_SMALLEST_NON_DENORMAL);
  v54 = (float)((float)v52 * (float)0.5);
  __asm { fsel      f3, f5, f6, f13 }
  v56 = __frsqrte(_FP3);
  v57 = (float)((float)-(float)((float)((float)((float)v56 * (float)((float)v52 * (float)0.5)) * (float)v56) - (float)1.5)
              * (float)v56);
  v58 = (float)((float)v50
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)v54)
                                                                                      * (float)v57)
                                                                              - (float)1.5)
                                                              * (float)v57)
                                                      * (float)v54)
                                              * (float)((float)-(float)((float)((float)((float)v57 * (float)v54)
                                                                              * (float)v57)
                                                                      - (float)1.5)
                                                      * (float)v57))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57) - (float)1.5)
                              * (float)v57)));
  v100 = (float)v50
       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)v54)
                                                                               * (float)v57)
                                                                       - (float)1.5)
                                                       * (float)v57)
                                               * (float)v54)
                                       * (float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57)
                                                               - (float)1.5)
                                               * (float)v57))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57) - (float)1.5)
                       * (float)v57));
  v59 = (float)((float)v49
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)v54)
                                                                                      * (float)v57)
                                                                              - (float)1.5)
                                                              * (float)v57)
                                                      * (float)v54)
                                              * (float)((float)-(float)((float)((float)((float)v57 * (float)v54)
                                                                              * (float)v57)
                                                                      - (float)1.5)
                                                      * (float)v57))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57) - (float)1.5)
                              * (float)v57)));
  v101 = (float)v49
       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)v54)
                                                                               * (float)v57)
                                                                       - (float)1.5)
                                                       * (float)v57)
                                               * (float)v54)
                                       * (float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57)
                                                               - (float)1.5)
                                               * (float)v57))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57) - (float)1.5)
                       * (float)v57));
  v102 = (float)v51
       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)v54)
                                                                               * (float)v57)
                                                                       - (float)1.5)
                                                       * (float)v57)
                                               * (float)v54)
                                       * (float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57)
                                                               - (float)1.5)
                                               * (float)v57))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57) - (float)1.5)
                       * (float)v57));
  for ( i = 9; i != 0; --i )
  {
    ++p_restLength;
    v29 += 4;
    *(float *)v29 = *p_restLength;
  }
  _FP4 = (float)((float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)) - (float)v30);
  _FP3 = (float)((float)((float)(v106 * v106) + (float)(v107 * v107)) - (float)v30);
  _FP30 = (float)((float)((float)(v108 * v108) + (float)(v109 * v109)) - (float)v30);
  __asm
  {
    fsel      f2, f4, f2, f13
    fsel      f1, f3, f1, f13
    fsel      f13, f30, f5, f13
  }
  v67 = __frsqrte(_FP2);
  v68 = __frsqrte(_FP1);
  v69 = __frsqrte(_FP13);
  v70 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67
                                                                                      * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))
                                                                                              * (float)0.5))
                                                                              * (float)v67)
                                                                      - (float)1.5)
                                                      * (float)v67)
                                              * (float)((float)((float)((float)v59 * (float)v59)
                                                              + (float)((float)v58 * (float)v58))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v67
                                                                              * (float)((float)((float)((float)v59 * (float)v59)
                                                                                              + (float)((float)v58 * (float)v58))
                                                                                      * (float)0.5))
                                                                      * (float)v67)
                                                              - (float)1.5)
                                              * (float)v67))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v67
                                                      * (float)((float)((float)((float)v59 * (float)v59)
                                                                      + (float)((float)v58 * (float)v58))
                                                              * (float)0.5))
                                              * (float)v67)
                                      - (float)1.5)
                      * (float)v67));
  v71 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v68
                                                                                      * (float)((float)((float)(v106 * v106) + (float)(v107 * v107))
                                                                                              * (float)0.5))
                                                                              * (float)v68)
                                                                      - (float)1.5)
                                                      * (float)v68)
                                              * (float)((float)((float)(v106 * v106) + (float)(v107 * v107)) * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v68
                                                                              * (float)((float)((float)(v106 * v106)
                                                                                              + (float)(v107 * v107))
                                                                                      * (float)0.5))
                                                                      * (float)v68)
                                                              - (float)1.5)
                                              * (float)v68))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v68
                                                      * (float)((float)((float)(v106 * v106) + (float)(v107 * v107))
                                                              * (float)0.5))
                                              * (float)v68)
                                      - (float)1.5)
                      * (float)v68));
  v72 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69
                                                                                      * (float)((float)((float)(v108 * v108) + (float)(v109 * v109))
                                                                                              * (float)0.5))
                                                                              * (float)v69)
                                                                      - (float)1.5)
                                                      * (float)v69)
                                              * (float)((float)((float)(v108 * v108) + (float)(v109 * v109)) * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v69
                                                                              * (float)((float)((float)(v108 * v108)
                                                                                              + (float)(v109 * v109))
                                                                                      * (float)0.5))
                                                                      * (float)v69)
                                                              - (float)1.5)
                                              * (float)v69))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v69
                                                      * (float)((float)((float)(v108 * v108) + (float)(v109 * v109))
                                                              * (float)0.5))
                                              * (float)v69)
                                      - (float)1.5)
                      * (float)v69));
  v73 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)) * (float)0.5)) * (float)v67) - (float)1.5)
                                                                                              * (float)v67)
                                                                                      * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)) * (float)0.5)) * (float)v67) - (float)1.5)
                                                                                      * (float)v67))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v67
                                                                                              * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)) * (float)0.5))
                                                                                      * (float)v67)
                                                                              - (float)1.5)
                                                              * (float)v67))
                                              * (float)((float)((float)((float)v59 * (float)v59)
                                                              + (float)((float)v58 * (float)v58))
                                                      * (float)0.5))
                                      * (float)v70)
                              - (float)1.5)
              * (float)v70);
  v74 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v68 * (float)((float)((float)(v106 * v106) + (float)(v107 * v107)) * (float)0.5)) * (float)v68) - (float)1.5)
                                                                                              * (float)v68)
                                                                                      * (float)((float)((float)(v106 * v106) + (float)(v107 * v107))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v68 * (float)((float)((float)(v106 * v106) + (float)(v107 * v107)) * (float)0.5)) * (float)v68) - (float)1.5)
                                                                                      * (float)v68))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v68
                                                                                              * (float)((float)((float)(v106 * v106) + (float)(v107 * v107)) * (float)0.5))
                                                                                      * (float)v68)
                                                                              - (float)1.5)
                                                              * (float)v68))
                                              * (float)((float)((float)(v106 * v106) + (float)(v107 * v107)) * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v68 * (float)((float)((float)(v106 * v106) + (float)(v107 * v107)) * (float)0.5)) * (float)v68) - (float)1.5)
                                                                                      * (float)v68)
                                                                              * (float)((float)((float)(v106 * v106)
                                                                                              + (float)(v107 * v107))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v68 * (float)((float)((float)(v106 * v106) + (float)(v107 * v107)) * (float)0.5)) * (float)v68)
                                                                                              - (float)1.5)
                                                                              * (float)v68))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v68
                                                                                      * (float)((float)((float)(v106 * v106) + (float)(v107 * v107))
                                                                                              * (float)0.5))
                                                                              * (float)v68)
                                                                      - (float)1.5)
                                                      * (float)v68)))
                              - (float)1.5)
              * (float)v71);
  v75 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)(v108 * v108) + (float)(v109 * v109)) * (float)0.5)) * (float)v69) - (float)1.5)
                                                                                              * (float)v69)
                                                                                      * (float)((float)((float)(v108 * v108) + (float)(v109 * v109))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)(v108 * v108) + (float)(v109 * v109)) * (float)0.5)) * (float)v69) - (float)1.5)
                                                                                      * (float)v69))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v69
                                                                                              * (float)((float)((float)(v108 * v108) + (float)(v109 * v109)) * (float)0.5))
                                                                                      * (float)v69)
                                                                              - (float)1.5)
                                                              * (float)v69))
                                              * (float)((float)((float)(v108 * v108) + (float)(v109 * v109)) * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)(v108 * v108) + (float)(v109 * v109)) * (float)0.5)) * (float)v69) - (float)1.5)
                                                                                      * (float)v69)
                                                                              * (float)((float)((float)(v108 * v108)
                                                                                              + (float)(v109 * v109))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)(v108 * v108) + (float)(v109 * v109)) * (float)0.5)) * (float)v69)
                                                                                              - (float)1.5)
                                                                              * (float)v69))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v69
                                                                                      * (float)((float)((float)(v108 * v108) + (float)(v109 * v109))
                                                                                              * (float)0.5))
                                                                              * (float)v69)
                                                                      - (float)1.5)
                                                      * (float)v69)))
                              - (float)1.5)
              * (float)v72);
  v76 = (float)((float)v73 * (float)v59);
  v77 = (float)((float)((float)(v109 * (float)v75) * (float)v76)
              + (float)((float)(v108 * (float)v75) * (float)((float)v73 * (float)v58)));
  v78 = (float)((float)1.0
              - (float)((float)((float)((float)((float)(v107 * (float)v74) * (float)v76)
                                      + (float)((float)(v106 * (float)v74) * (float)((float)v73 * (float)v58)))
                              * (float)0.5)
                      + (float)0.5));
  if ( v77 > 0.0 )
  {
    v79 = -0.1;
    if ( v78 < -0.1 || (v79 = 0.1, v78 > 0.1) )
      v78 = v79;
    v80 = (float)((float)((float)v78 * (float)5.0) + this->angles.yaw);
    goto LABEL_37;
  }
  if ( v77 < 0.0 )
  {
    v81 = -0.1;
    if ( v78 < -0.1 || (v81 = 0.1, v78 > 0.1) )
      v78 = v81;
    v80 = (float)-(float)((float)((float)v78 * (float)5.0) - this->angles.yaw);
LABEL_37:
    this->angles.yaw = v80;
  }
  v104.mat[2].z = 1.0;
  v104.mat[1].y = 1.0;
  v104.mat[0].x = 1.0;
  v104.mat[1].z = 0.0;
  v104.mat[0].z = 0.0;
  v104.mat[0].y = 0.0;
  v104.mat[2].y = 0.0;
  v104.mat[2].x = 0.0;
  v104.mat[1].x = 0.0;
  v103.x = 0.0;
  v103.y = 0.0;
  v103.z = 1.0;
  idMat3::RotateSelf(this: &v104, axis: &v103, angle: (float)(this->angles.yaw * idMath::M_DEG2RAD));
  this->currentAxis.mat[0].x = v104.mat[0].x;
  v82 = v104.mat[0].y;
  z = v104.mat[0].z;
  this->currentAxis.mat[1].x = v104.mat[1].x;
  v84 = v104.mat[1].y;
  this->currentAxis.mat[0].y = v82;
  this->currentAxis.mat[0].z = z;
  v85 = v104.mat[1].z;
  this->currentAxis.mat[1].y = v84;
  v86 = v104.mat[2].x;
  this->currentAxis.mat[1].z = v85;
  v87 = v104.mat[2].y;
  this->currentAxis.mat[2].x = v86;
  v88 = v104.mat[2].z;
  this->currentAxis.mat[2].y = v87;
  this->currentAxis.mat[2].z = v88;
  idDropShip::ModifyAxisFromMovementSpring(this, axis: &v104);
  v89 = 1.0;
  if ( this->dropShipState == DPSP_POWERDOWN )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    HIDWORD(v91) = this->stateStartTime;
    LODWORD(v91) = GameMs;
    LODWORD(v92) = HIDWORD(v91);
    v89 = (float)((float)1.0 - (float)((float)((float)v91 - (float)v92) / (float)(this->timeToPowerDown * (float)1000.0)));
    v99 = v91;
    if ( v89 >= 0.0 )
    {
      if ( v89 > 1.0 )
        v89 = 1.0;
    }
    else
    {
      v89 = 0.0;
    }
  }
  v93 = (float)(this->engineShake.x - (float)0.02);
  this->engineShake.x = this->engineShake.x - (float)0.02;
  v94 = (float)((float)v89 * (float)0.025);
  v95 = idMath::Sin16(a: v93);
  idMat3::RotateSelf(this: &v104, axis: v104.mat, angle: (float)((float)v95 * (float)v94));
  v96 = (float)(this->engineShake.y - (float)0.0099999998);
  this->engineShake.y = this->engineShake.y - (float)0.0099999998;
  v97 = idMath::Sin16(a: v96);
  idMat3::RotateSelf(this: &v104, axis: &v104.mat[1], angle: (float)((float)v97 * (float)v94));
  v98 = idEntity::GetPhysics(this);
  v98->SetAxis(this: v98, a2: &v104, a3: -1);
}


// ========================================================================
// ?UpdateFX@idDropShip@@EAAXXZ
// EA  : 0x82C36D10
// RVA : 0x00C36D10
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::UpdateFX(idDropShip *this)
{
  int i; // r27
  idPlayer *Player; // r31
  idPhysics *Physics; // r3
  float *v5; // r3
  double v6; // fp31
  double v7; // fp22
  double v8; // fp21
  idPhysics *v9; // r3
  float *v10; // r3
  double v11; // fp12
  double v12; // fp10
  idPhysics *v13; // r3
  float *v14; // r25
  idPhysics *v15; // r3
  float *v16; // r3
  double v17; // fp10
  double v18; // fp8
  long double v19; // fp4
  double v20; // fp0
  long double v21; // fp2
  long double v22; // fp2
  double v23; // fp31
  int v24; // r4
  int GameMs; // r3
  idPresentable *presentable; // r11
  __int64 v27; // r8
  double v28; // fp31
  int v29; // r3

  idEntity::UpdateFX(this);
  for ( i = 0; i < 6; ++i )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i);
    if ( Player != nullptr )
    {
      Physics = idEntity::GetPhysics(this);
      v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v6 = *v5;
      v7 = (float)(v5[2] - (float)2000.0);
      v8 = v5[1];
      v9 = idEntity::GetPhysics(this: Player);
      v10 = (float *)v9->GetOrigin(this: v9, a2: 0);
      v11 = (float)(v10[1] - (float)v8);
      v12 = (float)(v10[2] - (float)v7);
      if ( (float)((float)((float)(*v10 - (float)v6) * (float)(*v10 - (float)v6))
                 + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) <= 4000000.0 )
      {
        v13 = idEntity::GetPhysics(this: Player);
        v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
        v15 = idEntity::GetPhysics(this);
        v16 = (float *)v15->GetOrigin(this: v15, a2: 0);
        v17 = (float)(v14[1] - v16[1]);
        v18 = (float)(v14[2] - v16[2]);
        *((double *)&v19 + 1) = (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17));
        *(double *)&v19 = (float)((float)((float)(*v14 - *v16) * (float)(*v14 - *v16))
                                + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
        v20 = (float)-(float)((float)((float)__fsqrts(*(double *)&v19) * (float)0.00025000001) - (float)1.0);
        if ( v20 >= 0.0 )
        {
          if ( v20 > 1.0 )
            v20 = 1.0;
        }
        else
        {
          v20 = 0.0;
        }
        *((double *)&v21 + 1) = 5.0;
        *(double *)&v21 = v20;
        v22 = pow(x: v21, y: v19);
        v23 = (float)((float)*(double *)&v22 * (float)0.75);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        presentable = Player->presentable;
        LODWORD(v27) = GameMs - this->soundStartTime;
        v28 = (float)((float)((float)v27 / (float)(this->soundFadeTime * (float)1000.0)) * (float)v23);
        if ( presentable != nullptr )
          v29 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v29 = 0;
        idView::SetControllerShake(
          this: (idView *)(v29 + 16224),
          highMagnitude: v28,
          highDuration: v24,
          lowMagnitude: v28,
          lowDuration: 1);
      }
    }
  }
}


// ========================================================================
// ?DebugDropShip@idDropShip@@AAAXXZ
// EA  : 0x82C36F60
// RVA : 0x00C36F60
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::DebugDropShip(idDropShip *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  double v4; // fp0
  idPhysics *v5; // r3
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  va *v9; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  va *v13; // r3
  int v14; // [sp+8h] [-10B8h]
  int v15; // [sp+8h] [-10B8h]
  int v16; // [sp+Ch] [-10B4h]
  int v17; // [sp+Ch] [-10B4h]
  int v18; // [sp+10h] [-10B0h]
  int v19; // [sp+10h] [-10B0h]
  int v20; // [sp+14h] [-10ACh]
  int v21; // [sp+14h] [-10ACh]
  int v22; // [sp+18h] [-10A8h]
  int v23; // [sp+18h] [-10A8h]
  int v24; // [sp+1Ch] [-10A4h]
  int v25; // [sp+1Ch] [-10A4h]
  double v26; // [sp+20h] [-10A0h]
  double v27; // [sp+20h] [-10A0h]
  char v28; // [sp+60h] [-1060h] BYREF
  va v29; // [sp+70h] [-1050h] BYREF

  if ( (dropShip_SpringConstant.flags & 0x20000) != 0
    || (dropShip_SpringDampen.flags & 0x20000) != 0
    || (dropShip_SpringMass.flags & 0x20000) != 0 )
  {
    idSpring<idVec3>::SetConstants(
      this: &this->movementSpring,
      _k: dropShip_SpringConstant.valueFloat,
      _c: dropShip_SpringDampen.valueFloat);
    this->movementSpring.m = dropShip_SpringMass.valueFloat;
    Physics = idEntity::GetPhysics(this);
    v3 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v4 = *v3;
    this->movementSpring.p0.x = *v3;
    this->movementSpring.p0.y = v3[1];
    this->movementSpring.p0.z = v3[2];
    this->movementSpring.p1.x = v4;
    this->movementSpring.p1.y = this->movementSpring.p0.y;
    this->movementSpring.p1.z = this->movementSpring.p0.z;
    this->movementSpring.vel.z = 0.0;
    this->movementSpring.vel.y = 0.0;
    this->movementSpring.vel.x = 0.0;
    dropShip_SpringDampen.flags &= ~0x20000u;
    dropShip_SpringConstant.flags &= ~0x20000u;
    dropShip_SpringMass.flags &= ~0x20000u;
  }
  if ( dropShip_SpringDebug.valueInteger != 0 )
  {
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idVec3 *)&this->movementSpring,
      a4: &this->movementSpring.p1,
      a5: 0,
      a6: false);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)&this->movementSpring,
      a4: 0,
      a5: false);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: &this->movementSpring.p1,
      a4: 0,
      a5: false);
    v5 = idEntity::GetPhysics(this);
    LODWORD(v6) = v5->GetLinearVelocity(this: (idPhysics *)&v28, result: (idVec3 *)v5, a3: 0);
    v26 = __fsqrts((float)((float)(*(float *)(v6 + 8) * *(float *)(v6 + 8))
                         + (float)((float)(*(float *)v6 * *(float *)v6)
                                 + (float)(*(float *)(v6 + 4) * *(float *)(v6 + 4)))));
    HIDWORD(v6) = LODWORD(v26);
    v9 = va::va(
           this: &v29,
           fmt: (const char *)HIDWORD(v26),
           a3: v6,
           a4: v8,
           a5: v7,
           a6: v14,
           a7: v16,
           a8: v18,
           a9: v20,
           a10: v22,
           a11: v24);
    ((void (__fastcall *)(idRenderWorld *, va *, idSpring<idVec3> *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
      a1: clientGame->renderWorld,
      a2: v9,
      a3: &this->movementSpring,
      a4: clientGame->renderWorld->DebugText,
      a5: &idColor::colorGreen,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.2);
    v27 = __fsqrts((float)((float)(this->movementSpring.vel.z * this->movementSpring.vel.z)
                         + (float)((float)(this->movementSpring.vel.x * this->movementSpring.vel.x)
                                 + (float)(this->movementSpring.vel.y * this->movementSpring.vel.y))));
    HIDWORD(v10) = LODWORD(v27);
    v13 = va::va(
            this: &v29,
            fmt: (const char *)HIDWORD(v27),
            a3: v10,
            a4: v12,
            a5: v11,
            a6: v15,
            a7: v17,
            a8: v19,
            a9: v21,
            a10: v23,
            a11: v25);
    ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
      a1: clientGame->renderWorld,
      a2: v13,
      a3: &this->movementSpring.p1,
      a4: clientGame->renderWorld->DebugText,
      a5: &idColor::colorCyan,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.2);
  }
}


// ========================================================================
// ?State_WaitTillEnemyCleared@idDropShip@@AAAXXZ
// EA  : 0x82C372F0
// RVA : 0x00C372F0
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::State_WaitTillEnemyCleared(idDropShip *this)
{
  int v2; // r28
  int v3; // r30
  idGameLocal *v4; // r10
  int value; // r9
  idAI2 *v6; // r3
  int v7; // r9
  idAI2 *v8; // r3
  idAI2 *v9; // r3
  int v10; // r9
  idAI2 *v11; // r3
  idAI2 *v12; // r3

  v2 = 0;
  if ( this->droppedCargo.num > 0 )
  {
    v3 = 0;
    v4 = gameLocal;
    do
    {
      value = this->droppedCargo.list[v3].spawnId.value;
      if ( v4->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v6 = (idAI2 *)v4->entities.ptr[value & 0x1FFF];
        if ( v6 != nullptr )
        {
          if ( idAI2::CastTo(c: v6) != nullptr )
          {
            v7 = this->droppedCargo.list[v3].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13
              && (v8 = (idAI2 *)gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
            {
              v9 = idAI2::CastTo(c: v8);
            }
            else
            {
              v9 = nullptr;
            }
            if ( !v9->IsDead(this: v9) )
            {
              v10 = this->droppedCargo.list[v3].spawnId.value;
              if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
                && (v11 = (idAI2 *)gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
              {
                v12 = idAI2::CastTo(c: v11);
              }
              else
              {
                v12 = nullptr;
              }
              if ( !v12->IsDying(this: v12) )
                return;
            }
          }
          v4 = gameLocal;
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->droppedCargo.num );
  }
  this->dropShipState = DPSP_DROPCARGO;
  this->stateStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->stateTimer = -1;
}


// ========================================================================
// ??0idDropShip@@QAA@XZ
// EA  : 0x82C375A0
// RVA : 0x00C375A0
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

idDropShip *__fastcall idDropShip::idDropShip(idDropShip *this)
{
  float *p_restLength; // r9
  float *p_y; // r11
  int v4; // ctr

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idDropShip_vtbl *)&idDropShip::`vftable';
  this->splines.list = nullptr;
  this->splines.granularity = 0;
  this->splines.memTag = 5;
  this->splines.listStatic = 0;
  this->splines.size = 0;
  this->splines.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splines);
  this->cargo.list = nullptr;
  this->cargo.granularity = 0;
  this->cargo.memTag = 5;
  this->cargo.listStatic = 0;
  this->cargo.size = 0;
  this->cargo.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cargo);
  this->timeBetweenDrops = 3.0;
  this->jetPack.startSlot = BACKPACK;
  this->jetPack.count = 1;
  this->jetPack.forSale = false;
  this->jetPack.lootable = false;
  this->jetPack.showHolstered = true;
  this->jetPack.inventoryDecl = nullptr;
  this->jetPack.entityDef = nullptr;
  this->speedTable.list = nullptr;
  this->speedTable.granularity = 0;
  this->speedTable.memTag = 5;
  this->speedTable.listStatic = 0;
  this->speedTable.size = 0;
  this->speedTable.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->speedTable);
  this->dropImmediately = false;
  this->startOffHovering = false;
  this->powerDownAtEndOfSpline = false;
  this->powerDownSound = nullptr;
  this->vehicleWeapon = nullptr;
  this->timeToPowerDown = 5.0;
  this->weaponAttachment = nullptr;
  this->fireDelayWhenMoving = 5.0;
  this->fireDelayWhenHovering = 5.0;
  idMQBuffer::idMQBuffer(this: &this->attachments);
  this->dropShipSound.list = nullptr;
  this->dropShipSound.granularity = 0;
  this->dropShipSound.memTag = 5;
  this->dropShipSound.listStatic = 0;
  this->dropShipSound.size = 0;
  this->dropShipSound.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dropShipSound);
  this->soundFadeTime = 5.0;
  this->droppedCargo.list = nullptr;
  this->droppedCargo.granularity = 0;
  this->droppedCargo.memTag = 5;
  this->droppedCargo.listStatic = 0;
  this->droppedCargo.size = 0;
  this->droppedCargo.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->droppedCargo);
  idInventoryCollection::idInventoryCollection(this: &this->inventory);
  this->weapon = nullptr;
  this->currentSpline = nullptr;
  this->currentSplineIdx = -1;
  this->movementSpring.restLength = 0.0;
  this->movementSpring.k = 1.0;
  this->movementSpring.m = 1.0;
  this->movementSpring.c = 2.0;
  this->movementSpring.p0.z = 0.0;
  this->movementSpring.p0.y = 0.0;
  this->movementSpring.p0.x = 0.0;
  this->movementSpring.p1.z = 0.0;
  this->movementSpring.p1.y = 0.0;
  this->movementSpring.p1.x = 0.0;
  p_restLength = &this->movementSpring.restLength;
  this->movementSpring.vel.z = 0.0;
  p_y = &mat2_identity.mat[1].y;
  this->movementSpring.vel.y = 0.0;
  v4 = 9;
  this->movementSpring.vel.x = 0.0;
  this->movementSpring.maxSpeed = 0.0;
  this->movementSpring.pMin.z = 0.0;
  this->movementSpring.pMin.y = 0.0;
  this->movementSpring.pMin.x = 0.0;
  this->movementSpring.hasPMin = false;
  this->movementSpring.pMax.z = 0.0;
  this->movementSpring.pMax.y = 0.0;
  this->movementSpring.pMax.x = 0.0;
  this->movementSpring.hasPMax = false;
  do
  {
    *++p_restLength = *++p_y;
    --v4;
  }
  while ( v4 != 0 );
  this->angles.pitch = 0.0;
  this->angles.yaw = 0.0;
  this->angles.roll = 0.0;
  this->dropShipState = DPSP_ENROUTE;
  this->currentDt = 0.0;
  this->stateTimer = -1;
  this->currentSplineTime = 0.0;
  this->stateStartTime = 0;
  this->soundStartTime = 0;
  this->fireTimer = 0;
  this->curNumDropped = 0;
  this->engineShake.x = 0.0;
  this->engineShake.y = 0.0;
  return this;
}


// ========================================================================
// __unwind$493180
// EA  : 0x82C37804
// RVA : 0x00C37804
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493180()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$493181
// EA  : 0x82C3782C
// RVA : 0x00C3782C
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493181()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5200));
}


// ========================================================================
// __unwind$493182
// EA  : 0x82C37858
// RVA : 0x00C37858
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493182()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5216));
}


// ========================================================================
// __unwind$493183
// EA  : 0x82C37884
// RVA : 0x00C37884
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493183()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5256));
}


// ========================================================================
// __unwind$493184
// EA  : 0x82C378B0
// RVA : 0x00C378B0
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493184()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5300));
}


// ========================================================================
// __unwind$493185
// EA  : 0x82C378DC
// RVA : 0x00C378DC
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493185()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5320));
}


// ========================================================================
// __unwind$493186
// EA  : 0x82C37908
// RVA : 0x00C37908
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493186()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5340));
}


// ========================================================================
// ??1idDropShip@@UAA@XZ
// EA  : 0x82C37948
// RVA : 0x00C37948
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::~idDropShip(idDropShip *this)
{
  idAttachmentCollection *p_attachments; // r29
  idWeapon *weapon; // r3
  idCurve_Spline<idVec3> *currentSpline; // r3

  this->__vftable = (idDropShip_vtbl *)&idDropShip::`vftable';
  p_attachments = &this->attachments;
  idAttachmentCollection::FreeAttachments(this: &this->attachments);
  weapon = this->weapon;
  if ( weapon != nullptr )
    ((void (__fastcall *)(idWeapon *, int))weapon->dtr_idClass)(a1: weapon, a2: 1);
  currentSpline = this->currentSpline;
  if ( currentSpline != nullptr )
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))currentSpline->dtr_idCurve<idVec3>)(a1: currentSpline, a2: 1);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->inventory);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->droppedCargo);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dropShipSound);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_attachments);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->speedTable);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cargo);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splines);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$493587
// EA  : 0x82C37A04
// RVA : 0x00C37A04
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493587()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$493588
// EA  : 0x82C37A2C
// RVA : 0x00C37A2C
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493588()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5200));
}


// ========================================================================
// __unwind$493589_0
// EA  : 0x82C37A58
// RVA : 0x00C37A58
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493589_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5216));
}


// ========================================================================
// __unwind$493590_0
// EA  : 0x82C37A84
// RVA : 0x00C37A84
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493590_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5256));
}


// ========================================================================
// __unwind$493591_0
// EA  : 0x82C37AB0
// RVA : 0x00C37AB0
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493591_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5300));
}


// ========================================================================
// __unwind$493592
// EA  : 0x82C37ADC
// RVA : 0x00C37ADC
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493592()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5320));
}


// ========================================================================
// __unwind$493593
// EA  : 0x82C37B08
// RVA : 0x00C37B08
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493593()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5340));
}


// ========================================================================
// __unwind$493594_0
// EA  : 0x82C37B34
// RVA : 0x00C37B34
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493594_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5356));
}


// ========================================================================
// ?FindSplineType@idDropShip@@AAAXW4dropShipSplineType_t@@@Z
// EA  : 0x82C37B60
// RVA : 0x00C37B60
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::FindSplineType(idDropShip *this, dropShipSplineType_t splineType)
{
  idCurve_Spline<idVec3> *currentSpline; // r3
  int num; // r8
  dropShipSpline *list; // r9
  int currentSplineIdx; // r11
  int v8; // r11
  int value; // r9
  idSplinePath *v10; // r3
  int v11; // r5
  dropShipSpline *v12; // r11
  int v13; // r11
  int v14; // r8
  idSplinePath *v15; // r3
  idSplinePath *v16; // r3
  idCurve_Spline<idVec3> *v17; // r3

  currentSpline = this->currentSpline;
  if ( currentSpline != nullptr )
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))currentSpline->dtr_idCurve<idVec3>)(a1: currentSpline, a2: 1);
  this->currentSpline = nullptr;
  if ( splineType != DPST_NONE )
  {
    num = this->splines.num;
    this->currentSplineIdx = 0;
    if ( num > 0 )
    {
      list = this->splines.list;
      do
      {
        currentSplineIdx = this->currentSplineIdx;
        if ( list[currentSplineIdx].type == splineType )
          break;
        this->currentSplineIdx = currentSplineIdx + 1;
      }
      while ( currentSplineIdx + 1 < this->splines.num );
    }
    v8 = this->currentSplineIdx;
    if ( v8 != num )
    {
      value = this->splines.list[v8].spline.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v10 = (idSplinePath *)gameLocal->entities.ptr[this->splines.list[v8].spline.spawnId.value & 0x1FFF];
        if ( v10 != nullptr && idSplinePath::CastTo(c: v10) != nullptr )
        {
          v11 = this->currentSplineIdx;
          v12 = &this->splines.list[v11];
          if ( v12->speed <= 0.001 )
            idLib::Error(fmt: "'%s' spline speed is too small for idx %d", this->name.data, v11);
          v14 = v12->spline.spawnId.value >> 13;
          v13 = v12->spline.spawnId.value & 0x1FFF;
          if ( gameLocal->spawnIds.ptr[v13] == v14 && (v15 = (idSplinePath *)gameLocal->entities.ptr[v13]) != nullptr )
            v16 = idSplinePath::CastTo(c: v15);
          else
            v16 = nullptr;
          v17 = idSplinePath::AllocSpline(this: v16);
          this->currentSpline = v17;
          if ( v17 == nullptr )
            idLib::Error(fmt: "Bad spline type set for '%s'", this->name.data);
          idCurve<idVec3>::MakeUniformMoveSpeed(this: v17, moveSpeed: this->splines.list[this->currentSplineIdx].speed);
          this->currentSplineTime = 0.0;
        }
      }
    }
  }
}


// ========================================================================
// ?UpdateWeapons@idDropShip@@AAAXXZ
// EA  : 0x82C37D30
// RVA : 0x00C37D30
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::UpdateWeapons(idDropShip *this)
{
  int v2; // r30
  idPlayer *Player; // r3
  idEntity *v4; // r25
  idWeapon *weapon; // r29
  unsigned int spawnId; // r11
  int v7; // r30
  idPresentableAnimatedEntity *PresentableByIndex; // r3
  idTreeAnimator *TreeAnimator; // r3
  idPropsCollection *decl; // r11
  idTreeAnimator *v11; // r29
  const tagData_t *Tag; // r4
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp9
  double v16; // fp7
  double v17; // fp0
  double v18; // fp13
  float *p_deferredAxis; // r11
  double v20; // fp2
  double v21; // fp1
  double v22; // fp10
  double v23; // fp9
  unsigned int v24; // r23
  int GameMsPerFrame; // r22
  int PreviousGameMs; // r21
  int GameMs; // r3
  int v28; // r3
  double v29; // fp1
  __int64 v30; // r7
  double v31; // fp9
  double v32; // fp8
  _DWORD *v33; // r11
  int i; // ctr
  const idPresentable *presentable; // r30
  idPresentable *v36; // r4
  float *v37; // [sp+8h] [-BA8h]
  float *v38; // [sp+Ch] [-BA4h]
  float *v39; // [sp+10h] [-BA0h]
  int v40; // [sp+14h] [-B9Ch]
  int v41; // [sp+18h] [-B98h]
  int v42; // [sp+1Ch] [-B94h]
  int v43; // [sp+20h] [-B90h]
  int v44; // [sp+24h] [-B8Ch]
  int v45; // [sp+28h] [-B88h]
  int v46; // [sp+2Ch] [-B84h]
  int v47; // [sp+30h] [-B80h]
  int v48; // [sp+34h] [-B7Ch]
  int v49; // [sp+38h] [-B78h]
  int v50; // [sp+3Ch] [-B74h]
  int v51; // [sp+40h] [-B70h]
  int v52; // [sp+44h] [-B6Ch]
  int v53; // [sp+48h] [-B68h]
  int v54; // [sp+4Ch] [-B64h]
  int v55; // [sp+50h] [-B60h]
  int v56; // [sp+58h] [-B58h]
  int v57; // [sp+60h] [-B50h]
  _WORD v58[1440]; // [sp+70h] [-B40h] BYREF

  if ( this->weapon != nullptr )
  {
    v2 = 0;
    while ( 1 )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: v2);
      v4 = Player;
      if ( Player != nullptr && !Player->IsDead(this: Player) && !v4->IsDying(this: v4) )
        break;
      if ( ++v2 >= 6 )
        return;
    }
    weapon = this->weapon;
    spawnId = weapon->presentableWeapon.spawnId;
    v7 = spawnId & 0x3FFF;
    if ( spawnId == 0
      || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
      || (PresentableByIndex = (idPresentableAnimatedEntity *)idClientGame::GetPresentableByIndex(
                                                                this: clientGame,
                                                                index: v7))->spawnId != weapon->presentableWeapon.spawnId )
    {
      PresentableByIndex = nullptr;
    }
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: PresentableByIndex);
    decl = (idPropsCollection *)TreeAnimator->decl;
    v11 = TreeAnimator;
    if ( decl != nullptr && decl != (idPropsCollection *)-352 )
    {
      Tag = idPropsCollection::GetTag(this: decl + 22, propName: "_info", tagName: "laser_pos");
      if ( Tag->parentJoint.value != 0xFFFF )
      {
        idTreeAnimator::GetWorldSpaceTagTransform(
          this: v11,
          tagData: Tag,
          origin: (idVec3 *)&v58[16],
          axis: (idMat3 *)&v58[128]);
        Physics = idEntity::GetPhysics(this: v4);
        v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v15 = (float)(v14[2] - *(float *)&v58[20]);
        v16 = (float)(v14[1] - *(float *)&v58[18]);
        *(float *)&v58[8] = *v14 - *(float *)&v58[16];
        *(float *)&v58[12] = v15;
        *(float *)&v58[10] = v16;
        idVec3::NormalizeFast(this: (idVec3 *)&v58[8]);
        idVec3::ToMat3(this: (idVec3 *)&v58[64], result: (idMat3 *)&v58[8]);
        idTreeAnimator::GetJointIndex(
          this: (idTreeAnimator *)v58,
          result: (idIndex<short,enum invalidJointIndex_t> *)v11,
          jointName: "hip");
        if ( v58[0] >= 0 )
        {
          v17 = -*(float *)&v58[10];
          v18 = -*(float *)&v58[8];
          p_deferredAxis = (float *)&v11->deferredAxis;
          if ( !v11->useDeferredPosition )
            p_deferredAxis = (float *)&v11->g.axis;
          v20 = p_deferredAxis[5];
          v21 = *p_deferredAxis;
          v22 = (float)((float)(p_deferredAxis[3] * (float)v18) + (float)(p_deferredAxis[4] * (float)v17));
          v23 = (float)((float)(p_deferredAxis[1] * (float)v17) + (float)(p_deferredAxis[2] * *(float *)&v58[12]));
          *(float *)&v58[36] = (float)(p_deferredAxis[8] * *(float *)&v58[12])
                             + (float)((float)(p_deferredAxis[6] * (float)v18) + (float)(p_deferredAxis[7] * (float)v17));
          *(float *)&v58[34] = (float)((float)v20 * *(float *)&v58[12]) + (float)v22;
          *(float *)&v58[32] = (float)((float)v18 * (float)v21) + (float)v23;
          idVec3::ToMat3(this: (idVec3 *)&v58[40], result: (idMat3 *)&v58[32]);
          *(float *)&v58[24] = 0.0;
          *(float *)&v58[26] = 0.0;
          *(float *)&v58[28] = 1.0;
          idMat3::RotateSelf(this: (idMat3 *)&v58[40], axis: (const idVec3 *)&v58[24], angle: 3.1415927);
          idTreeAnimator::SetJointAxis(
            this: v11,
            pose: (animationPose_t)0,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v58[0],
            type: JOINTMOD_MODEL_OVERRIDE,
            axis: (const idMat3 *)&v58[40]);
          v24 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
          GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                             this: &clientGame->gameTimeManager,
                             type: GAMETIME_SCALED);
          PreviousGameMs = idGameTimeManager::GetPreviousGameMs(
                             this: &clientGame->gameTimeManager,
                             type: GAMETIME_SCALED);
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idTreeAnimator::BlendTreeInternal(
            this: v11,
            currentTime: GameMs,
            previousTime: PreviousGameMs,
            gameMsPerFrame: GameMsPerFrame,
            ticksPerSec: v24,
            tree: nullptr,
            parallelJobList: gameLocal->parallelJobList,
            localR: nullptr,
            localS: v37,
            localT: v38,
            localU: v39,
            a12: v40,
            a13: v41,
            a14: v42,
            a15: v43,
            a16: v44,
            a17: v45,
            a18: v46,
            a19: v47,
            a20: v48,
            a21: v49,
            a22: v50,
            a23: v51,
            a24: v52,
            a25: v53,
            a26: v54,
            a27: v55,
            a28: nullptr,
            a29: v56,
            a30: nullptr,
            a31: v57,
            a32: nullptr);
          v28 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idTreeAnimator::UpdateTime(this: v11, time: v28);
        }
        v29 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetRealMsPerFrame)(a1: gameLocal, a2: 1);
        LODWORD(v30) = this->fireTimer;
        v31 = (float)(this->fireDelayWhenMoving * (float)1000.0);
        v32 = (float)((float)v29 + (float)v30);
        *(_DWORD *)&v58[6] = (int)v32;
        this->fireTimer = (int)v32;
        if ( (int)v32 > (int)v31 )
        {
          this->fireTimer = 0;
          idFireParms::idFireParms(this: (idFireParms *)&v58[152]);
          memset(&v58[232], 0, 2308);
          v33 = &v58[88];
          *(_DWORD *)&v58[88] = 0;
          for ( i = 16; i != 0; --i )
            *++v33 = 0;
          if ( this->presentable == nullptr )
            idEntity::InitPresentableInternal(this);
          if ( v4->presentable == nullptr )
            idEntity::InitPresentableInternal(this: v4);
          presentable = v4->presentable;
          v36 = this->presentable;
          if ( v36 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v36 = this->presentable;
          }
          idWeapon::Fire(
            this: this->weapon,
            attacker: v36,
            target: presentable,
            start: (const idVec3 *)&v58[16],
            fireAxis: (const idMat3 *)&v58[64],
            fp: (idFireParms *)&v58[152],
            tfr: (idTestFireResults *)&v58[232],
            ffr: (idFinishFireResults *)&v58[88],
            fxMgr: (idFXManager *)v37,
            secondaryAmmo: (bool)v38);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v58[160]);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$493821
// EA  : 0x82C381C0
// RVA : 0x00C381C0
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_493821()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2992 + 416));
}


// ========================================================================
// ?OnActivate@idDropShip@@EAAXPAVidEntity@@@Z
// EA  : 0x82C381E8
// RVA : 0x00C381E8
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::OnActivate(idDropShip *this, idEntity *activator)
{
  int v3; // r27
  int v4; // r28
  soundChannel_t *v5; // r29
  idPresentable *presentable; // r3
  idPresentable *v7; // r3
  idDropShip::dropShipSound_t *list; // r30
  unsigned __int8 v9; // r5
  idPresentable *v10; // r11
  dropShipState_t v11; // r11
  soundShaderParms_t v12; // [sp+50h] [-E0h] BYREF

  v3 = 0;
  if ( this->dropShipSound.num <= 0 )
  {
LABEL_14:
    if ( this->dropShipState != DPSP_HOVER )
      return;
    idDropShip::FindSplineType(this, splineType: DPST_STARTSPLINE);
    if ( this->currentSpline != nullptr )
    {
      v11 = DPSP_ENROUTE;
      goto LABEL_20;
    }
  }
  else
  {
    v4 = 0;
    v5 = (soundChannel_t *)Sound_Channels;
    while ( this->dropShipSound.list[v4].sound != nullptr )
    {
      if ( v3 < 3 )
      {
        presentable = this->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        if ( !idPresentable::IsPlayingSound(this: presentable, channel: *v5) )
        {
          soundShaderParms_t::Clear(this: &v12);
          v7 = this->presentable;
          list = this->dropShipSound.list;
          v12.soundShaderFlags = SSF_LOOPING;
          if ( v7 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v7 = this->presentable;
          }
          idPresentable::StartSoundShader(this: v7, channel: *v5, shader: list[v4].sound, parms: &v12, peerMask: 0);
          v10 = this->presentable;
          if ( v10 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v10 = this->presentable;
          }
          idPresentable::SetSoundVolume(this: v10, channel: *v5, volume: -60.0, peerMask: v9, a5: 0);
        }
      }
      ++v3;
      ++v4;
      ++v5;
      if ( v3 >= this->dropShipSound.num )
        goto LABEL_14;
    }
    idLib::Error(fmt: "DropShip '%s' has null sound for index %d", this->name.data, v3);
  }
  idDropShip::FindSplineType(this, splineType: DPST_ENDSPLINE);
  if ( this->currentSpline == nullptr )
    return;
  v11 = DPSP_HEADINGOUT;
LABEL_20:
  this->dropShipState = v11;
  this->stateStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->stateTimer = -1;
}


// ========================================================================
// ?Spawn@idDropShip@@QAAXXZ
// EA  : 0x82C383D8
// RVA : 0x00C383D8
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDropShip::Spawn(idDropShip *this)
{
  dropShipState_t v2; // r30
  int GameMs; // r3
  idCurve_Spline<idVec3> *currentSpline; // r4
  int v5; // r3
  idPhysics *Physics; // r3
  float v7; // r10
  float v8; // r9
  BOOL dropImmediately; // r8
  idCurve_Spline<idVec3> *v10; // r4
  float *v11; // r3
  double x; // fp12
  double y; // fp13
  double z; // fp0
  double v15; // fp11
  double v16; // fp9
  double v17; // fp8
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  idAngles *v20; // r3
  __int64 v21; // r8 OVERLAPPED
  int v22; // r3
  int num; // r11
  dropShipSpeedTable_t *list; // r9
  double speed; // fp0
  double v26; // fp12
  double v27; // fp13
  int v28; // r5
  int v29; // r11
  int v30; // r28
  int v31; // r30
  int value; // r9
  idSplinePath *v33; // r3
  const idDeclVehicleWeapon *vehicleWeapon; // r3
  idWeapon *v35; // r3
  idWeapon *v36; // r5
  idMat3 v37[2]; // [sp+50h] [-50h] BYREF

  idEntity::BecomeActive(this, flags: 5);
  v2 = DPSP_ENROUTE;
  idDropShip::FindSplineType(this, splineType: DPST_STARTSPLINE);
  if ( this->currentSpline == nullptr )
  {
    idDropShip::FindSplineType(this, splineType: DPST_ENDSPLINE);
    v2 = this->currentSpline == nullptr ? DPSP_HOVER : DPSP_HEADINGOUT;
  }
  if ( this->startOffHovering )
    this->dropShipState = DPSP_HOVER;
  else
    this->dropShipState = v2;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->stateTimer = -1;
  this->stateStartTime = GameMs;
  idDropShip::UpdatePropellerVisuals(this, on: true);
  idSpring<idVec3>::SetConstants(
    this: &this->movementSpring,
    _k: dropShip_SpringConstant.valueFloat,
    _c: dropShip_SpringDampen.valueFloat);
  currentSpline = this->currentSpline;
  this->movementSpring.m = dropShip_SpringMass.valueFloat;
  if ( currentSpline != nullptr )
  {
    v5 = ((int (__fastcall *)(idMat3 *, double))currentSpline->GetCurrentValue)(a1: v37, a2: 0.0);
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    v5 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  }
  v7 = *(float *)(v5 + 4);
  v8 = *(float *)(v5 + 8);
  dropImmediately = this->dropImmediately;
  v37[0].mat[0].x = *(float *)v5;
  v37[0].mat[0].y = v7;
  v37[0].mat[0].z = v8;
  if ( dropImmediately && (v10 = this->currentSpline) != nullptr )
  {
    this->currentSplineTime = v10->times.list[v10->values.num - 1];
    v11 = (float *)((int (__fastcall *)(idMat3 *))v10->GetCurrentValue)(a1: v37);
    x = *v11;
    y = v11[1];
    z = v11[2];
  }
  else
  {
    z = v37[0].mat[0].z;
    y = v37[0].mat[0].y;
    x = v37[0].mat[0].x;
  }
  this->movementSpring.p0.z = z;
  this->movementSpring.p0.x = x;
  this->movementSpring.p0.y = y;
  this->movementSpring.p1.x = x;
  this->movementSpring.p1.y = this->movementSpring.p0.y;
  this->movementSpring.p1.z = this->movementSpring.p0.z;
  this->movementSpring.vel.z = 0.0;
  this->movementSpring.vel.y = 0.0;
  this->movementSpring.vel.x = 0.0;
  v15 = this->movementSpring.p1.y;
  v16 = this->movementSpring.p1.x;
  v17 = (float)(dropShip_SpringGravity.valueFloat * (float)0.0);
  this->movementSpring.p1.z = this->movementSpring.p1.z - dropShip_SpringGravity.valueFloat;
  this->movementSpring.p1.x = (float)v16 - (float)v17;
  this->movementSpring.p1.y = (float)v15 - (float)v17;
  v18 = idEntity::GetPhysics(this);
  v18->SetOrigin(this: v18, a2: &this->movementSpring.p1, a3: -1);
  v19 = idEntity::GetPhysics(this);
  v20 = (idAngles *)v19->GetAxis(this: v19, a2: 0);
  this->angles = *idMat3::ToAngles(this: v37, result: v20);
  this->currentDt = 0.0;
  v22 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  num = this->speedTable.num;
  this->soundStartTime = v22;
  if ( num != 0 )
  {
    list = this->speedTable.list;
    speed = list->speed;
    v26 = 0.001;
    HIDWORD(v21) = list->distance;
    *(_QWORD *)&v37[0].mat[0].x = *(__int64 *)((char *)&v21 + 4);
    v27 = (float)*(__int64 *)((char *)&v21 + 4);
    if ( speed <= 0.001 )
      idLib::Error(fmt: "'%s' has a speed table speed that is too small at idx 0", this->name.data);
    v28 = 1;
    if ( num > 1 )
    {
      v29 = 1;
      while ( list[v29].speed > v26 )
      {
        LODWORD(v21) = list[v29].distance;
        *(_QWORD *)&v37[0].mat[0].x = v21;
        if ( (float)v21 <= v27 )
          goto _LN135;
        ++v28;
        v27 = (float)v21;
        ++v29;
        if ( v28 >= this->speedTable.num )
          goto LABEL_21;
      }
      idLib::Error(fmt: "'%s' has a speed table speed that is too small at idx %d", this->name.data, v28);
_LN135:
      idLib::Error(fmt: "'%s' has bad distance values in its speed table", this->name.data);
_LN136:
      idLib::Error(fmt: "'%s' has bad spline info", this->name.data);
      JUMPOUT(0x82C3880C);
    }
  }
LABEL_21:
  v30 = 0;
  if ( this->splines.num > 0 )
  {
    v31 = 0;
    do
    {
      value = this->splines.list[v31].spline.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
        goto _LN136;
      v33 = (idSplinePath *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v33 == nullptr || idSplinePath::CastTo(c: v33) == nullptr )
        goto _LN136;
      ++v30;
      ++v31;
    }
    while ( v30 < this->splines.num );
  }
  vehicleWeapon = this->vehicleWeapon;
  this->attachments.parent = this;
  if ( vehicleWeapon != nullptr )
  {
    v35 = (idWeapon *)idInventoryItem::Create(decl: vehicleWeapon);
    v36 = idWeapon::CastTo(c: v35);
    this->weapon = v36;
    if ( v36 != nullptr )
      idAttachmentCollection::AddAttachment(
        this: (idAttachmentCollection *)v37,
        result: &this->attachments,
        item: v36,
        tagName: "weapon",
        fxAttachInfo: nullptr);
  }
}


// ========================================================================
// ?DropCargo@idDropShip@@AAAXXZ
// EA  : 0x82C38810
// RVA : 0x00C38810
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::DropCargo(idDropShip *this)
{
  int i; // r31
  idPlayer *Player; // r27
  int value; // r9
  idTarget_Spawn *v5; // r3
  idTarget_Spawn *v6; // r31
  idEntity *v7; // r3
  idAI2 *v8; // r31
  idAI2 *v9; // r30
  idList<idEntityPtr<idAI2>,5> *p_droppedCargo; // r31
  int size; // r10
  int num; // r11
  idEntityPtr<idAI2> *v13; // r10
  const idDeclInventory *inventoryDecl; // r31
  idJobManager *v15; // r3
  idInventoryItem *JobByDecl; // r3
  idPresentable *presentable; // r31
  const idDeclInventory *v18; // r28
  idInventoryCollection *v19; // r3
  idPhysics *Physics; // r3
  float *v21; // r31
  idPhysics *v22; // r3
  float *v23; // r3
  double v24; // fp9
  double v25; // fp7
  double v28; // fp1
  double v29; // fp4
  double v30; // fp1
  idVec3 v31; // [sp+50h] [-70h] BYREF
  float v32; // [sp+60h] [-60h] BYREF
  float v33; // [sp+64h] [-5Ch]
  float v34; // [sp+68h] [-58h]
  float v35; // [sp+6Ch] [-54h]
  float v36; // [sp+70h] [-50h]
  float v37; // [sp+74h] [-4Ch]
  float v38; // [sp+78h] [-48h]
  float v39; // [sp+7Ch] [-44h]
  float v40; // [sp+80h] [-40h]

  if ( this->cargo.num == 0 )
    return;
  for ( i = 0; i < 6; ++i )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i);
    if ( Player != nullptr )
      break;
  }
  value = this->cargo.list->targetSpawn.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v5 = (idTarget_Spawn *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr )
  {
    v6 = nullptr;
    goto LABEL_9;
  }
  v6 = idTarget_Spawn::CastTo(c: v5);
  if ( v6 == nullptr )
  {
LABEL_9:
    if ( this->cargo.list->cargoDef == nullptr )
      idLib::Error(fmt: "No cargo entry for '%s' in index %d", this->name.data, this->curNumDropped);
  }
  idDropShip::GetDropLocation(this: (idDropShip *)&v31, result: this, index: this->curNumDropped % 3);
  if ( v6 != nullptr )
    v7 = idTarget_Spawn::SpawnSingleEntity(this: v6, origin: &v31, axis: &mat3_identity, checkSafeSpawn: false);
  else
    v7 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: this->cargo.list->cargoDef, a3: -1, a4: -1, a5: -1);
  v8 = (idAI2 *)v7;
  idEntity::SetOrigin(this: v7, org: &v31);
  v8->SetAxis(this: v8, a2: &mat3_identity);
  v8->spawnPosition = v31;
  v9 = idAI2::CastTo(c: v8);
  if ( v9 != nullptr )
  {
    p_droppedCargo = &this->droppedCargo;
    idList<idEntityPtr<idInfoGarageBay>,5>::PreAllocateWithGranularity(
      this: &this->droppedCargo,
      newSize: this->droppedCargo.num + 1);
    size = this->droppedCargo.size;
    num = this->droppedCargo.num;
    if ( num >= size )
    {
      v13 = &p_droppedCargo->list[size - 1];
    }
    else
    {
      v13 = &p_droppedCargo->list[num];
      this->droppedCargo.num = num + 1;
    }
    v13->spawnId.value = (gameLocal->spawnIds.ptr[v9->entityNumber] << 13) | v9->entityNumber;
    v9->aiVolatile.dropState = 0;
    if ( this->jetPack.inventoryDecl != nullptr && v9->GetInventory_2(this: v9) != nullptr )
    {
      inventoryDecl = this->jetPack.inventoryDecl;
      v15 = (idJobManager *)v9->GetInventory_2(this: v9);
      JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v15, jobDecl: (const idDeclJob *)inventoryDecl);
      if ( JobByDecl == nullptr )
      {
        presentable = v9->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: v9);
          presentable = v9->presentable;
        }
        v18 = this->jetPack.inventoryDecl;
        v19 = v9->GetInventory_2(this: v9);
        JobByDecl = idInventoryCollection::GiveItem(
                      this: v19,
                      owner: presentable,
                      decl: v18,
                      count: 1,
                      forceCount: false,
                      canIntro: false);
      }
      v9->EquipItem(this: v9, a2: JobByDecl, a3: EQUIP_NONE);
    }
    if ( Player != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v9);
      v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v22 = idEntity::GetPhysics(this: Player);
      v23 = (float *)v22->GetOrigin(this: v22, a2: 0);
      v24 = (float)(v23[1] - v21[1]);
      v25 = (float)(*v23 - *v21);
      v40 = 1.0;
      v38 = 0.0;
      v39 = 0.0;
      _FP4 = (float)((float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f2, f4, f5, f12 }
      v28 = __frsqrte(_FP2);
      v29 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28
                                                                                          * (float)((float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))
                                                                                                  * (float)0.5))
                                                                                  * (float)v28)
                                                                          - (float)1.5)
                                                          * (float)v28)
                                                  * (float)((float)((float)((float)v25 * (float)v25)
                                                                  + (float)((float)v24 * (float)v24))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v28
                                                                                  * (float)((float)((float)((float)v25 * (float)v25)
                                                                                                  + (float)((float)v24 * (float)v24))
                                                                                          * (float)0.5))
                                                                          * (float)v28)
                                                                  - (float)1.5)
                                                  * (float)v28))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v28
                                                          * (float)((float)((float)((float)v25 * (float)v25)
                                                                          + (float)((float)v24 * (float)v24))
                                                                  * (float)0.5))
                                                  * (float)v28)
                                          - (float)1.5)
                          * (float)v28));
      v30 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)) * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                                  * (float)v28)
                                                                                          * (float)((float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)) * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                          * (float)v28))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v28
                                                                                                  * (float)((float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)) * (float)0.5))
                                                                                          * (float)v28)
                                                                                  - (float)1.5)
                                                                  * (float)v28))
                                                  * (float)((float)((float)((float)v25 * (float)v25)
                                                                  + (float)((float)v24 * (float)v24))
                                                          * (float)0.5))
                                          * (float)v29)
                                  - (float)1.5)
                  * (float)v29);
      v32 = (float)v25 * (float)v30;
      v34 = (float)v30 * (float)0.0;
      v33 = (float)v30 * (float)v24;
      v37 = (float)(v33 * (float)0.0) - (float)(v32 * (float)0.0);
      v35 = (float)(v34 * (float)0.0) - v33;
      v36 = v32 - (float)(v34 * (float)0.0);
      v9->SetAxis(this: v9, a2: (const idMat3 *)&v32);
    }
  }
  --this->cargo.list->count;
  ++this->curNumDropped;
}


// ========================================================================
// ?State_DropCargo@idDropShip@@AAAXXZ
// EA  : 0x82C38C18
// RVA : 0x00C38C18
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::State_DropCargo(idDropShip *this)
{
  int stateTimer; // r11
  idGameTimeManager *p_gameTimeManager; // r3

  stateTimer = this->stateTimer;
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( stateTimer == -1 )
  {
    this->stateTimer = (int)(float)((float)(this->timeBetweenDrops * (float)1000.0)
                                  + (float)__SPAIR64__(
                                             &unk_82150000,
                                             idGameTimeManager::GetGameMs(
                                               this: p_gameTimeManager,
                                               type: GAMETIME_SCALED)));
  }
  else if ( idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED) > this->stateTimer )
  {
    this->stateTimer = (int)(float)((float)(this->timeBetweenDrops * (float)1000.0)
                                  + (float)__SPAIR64__(
                                             &unk_82150000,
                                             idGameTimeManager::GetGameMs(
                                               this: &clientGame->gameTimeManager,
                                               type: GAMETIME_SCALED)));
    idDropShip::DropCargo(this);
  }
  if ( this->cargo.num > 0 && this->cargo.list->count == 0 )
  {
    idList<dropShipCargo_t,5>::RemoveIndex(this: &this->cargo, index: 0);
    if ( this->cargo.num > 0 && this->cargo.list->waitTillClear )
      idDropShip::ChangeState(this, newState: DPSP_WAITTILLCLEAR);
  }
  if ( this->cargo.num == 0 )
  {
    idDropShip::FindSplineType(this, splineType: DPST_ENDSPLINE);
    if ( this->currentSpline == nullptr )
      idLib::Error(fmt: "'%s' could not find a heading out spline", this->name.data);
    this->dropShipState = DPSP_HEADINGOUT;
    this->stateStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->stateTimer = -1;
  }
}


// ========================================================================
// ?Think@idDropShip@@UAAXXZ
// EA  : 0x82C38D98
// RVA : 0x00C38D98
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __fastcall idDropShip::Think(idDropShip *this)
{
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 )
  {
    if ( (unsigned int)(this->dropShipState - 1) <= 6 )
    {
      switch ( this->dropShipState )
      {
        case DPSP_DROPCARGO:
          idDropShip::State_DropCargo(this);
          break;
        case DPSP_WAITTILLCLEAR:
          idDropShip::State_WaitTillEnemyCleared(this);
          break;
        case DPSP_HEADINGOUT:
          idDropShip::State_HeadingOut(this);
          break;
        case DPSP_POWERDOWN:
          idDropShip::State_PowerDown(this);
          break;
        case DPSP_LANDED:
LABEL_18:
          break;
        case DPSP_ENROUTE:
          idDropShip::State_EnRoute(this);
          break;
        default:
          idDropShip::State_Done(this);
          goto LABEL_18;
      }
    }
    idDropShip::UpdateWeapons(this);
    idAnimatedEntity::UpdateFrameCommands(this);
    idDropShip::RunPhysics(this);
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    this->UpdateFX(this);
    idDropShip::UpdateSounds(this);
    idDropShip::DebugDropShip(this);
  }
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringConstant''
// EA  : 0x83376658
// RVA : 0x01376658
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringConstant__()
{
  idCVar::idCVar(
    this: &dropShip_SpringConstant,
    name: "dropShip_SpringConstant",
    value: "1.0",
    flags: 4,
    description: "spring constant for drop ship spring",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringConstant__);
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringDampen''
// EA  : 0x833766B0
// RVA : 0x013766B0
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringDampen__()
{
  idCVar::idCVar(
    this: &dropShip_SpringDampen,
    name: "dropShip_SpringDampen",
    value: "0.85",
    flags: 4,
    description: "spring dampening factor for drop ship spring",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringDampen__);
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringMass''
// EA  : 0x83376708
// RVA : 0x01376708
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringMass__()
{
  idCVar::idCVar(
    this: &dropShip_SpringMass,
    name: "dropShip_SpringMass",
    value: "1.0",
    flags: 4,
    description: "mass of weight at end of drop ship bump spring",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringMass__);
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringMaxSpeed''
// EA  : 0x83376760
// RVA : 0x01376760
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringMaxSpeed__()
{
  idCVar::idCVar(
    this: &dropShip_SpringMaxSpeed,
    name: "dropShip_SpringMaxSpeed",
    value: "150000.0",
    flags: 4,
    description: "maximum magnitude of drops ship spring velocity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringMaxSpeed__);
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringGravity''
// EA  : 0x833767B8
// RVA : 0x013767B8
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringGravity__()
{
  idCVar::idCVar(
    this: &dropShip_SpringGravity,
    name: "dropShip_SpringGravity",
    value: "0.5",
    flags: 4,
    description: "spring gravity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringGravity__);
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringDebug''
// EA  : 0x83376810
// RVA : 0x01376810
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringDebug__()
{
  idCVar::idCVar(
    this: &dropShip_SpringDebug,
    name: "dropShip_SpringDebug",
    value: "0",
    flags: 1,
    description: "1 = show debugging info for the ATV bump spring",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringDebug__);
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringRollClamp''
// EA  : 0x83376868
// RVA : 0x01376868
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringRollClamp__()
{
  idCVar::idCVar(
    this: &dropShip_SpringRollClamp,
    name: "dropShip_SpringRollClamp",
    value: "1000.0",
    flags: 4,
    description: "distance along roll axis where spring roll contribution reaches max",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringRollClamp__);
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringMaxRoll''
// EA  : 0x833768C0
// RVA : 0x013768C0
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringMaxRoll__()
{
  idCVar::idCVar(
    this: &dropShip_SpringMaxRoll,
    name: "dropShip_SpringMaxRoll",
    value: "60.0",
    flags: 4,
    description: "spring's max roll contribution and the roll axis clamp point",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringMaxRoll__);
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringPitchClamp''
// EA  : 0x83376918
// RVA : 0x01376918
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringPitchClamp__()
{
  idCVar::idCVar(
    this: &dropShip_SpringPitchClamp,
    name: "dropShip_SpringPitchClamp",
    value: "750.0",
    flags: 4,
    description: "distance along pitch axis where spring pitch contribution reaches max",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringPitchClamp__);
}


// ========================================================================
// `dynamic initializer for 'dropShip_SpringMaxPitch''
// EA  : 0x83376970
// RVA : 0x01376970
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropShip_SpringMaxPitch__()
{
  idCVar::idCVar(
    this: &dropShip_SpringMaxPitch,
    name: "dropShip_SpringMaxPitch",
    value: "-30.0",
    flags: 4,
    description: "spring's max pitch contribution at the pitch axis clamp point",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropShip_SpringMaxPitch__);
}


// ========================================================================
// `dynamic initializer for 'dropLocationNames''
// EA  : 0x833769D0
// RVA : 0x013769D0
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dropLocationNames__()
{
  idStr::idStr(this: (idStr *)dropLocationNames, text: "drop_left");
  idStr::idStr(this: (idStr *)&dropLocationNames[1], text: "drop_right");
  idStr::idStr(this: (idStr *)&dropLocationNames[2], text: "drop_back");
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dropLocationNames__);
}


// ========================================================================
// __unwind$494856
// EA  : 0x83376A44
// RVA : 0x01376A44
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_494856()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)dropLocationNames);
}


// ========================================================================
// __unwind$494857
// EA  : 0x83376A6C
// RVA : 0x01376A6C
// PDB : w:\tech5\tungsten\game\entities\dropship.cpp
// ========================================================================

void _unwind_494857()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&dropLocationNames[1]);
}

