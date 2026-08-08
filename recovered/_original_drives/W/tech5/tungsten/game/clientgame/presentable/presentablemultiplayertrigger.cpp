
// ========================================================================
// ?Think@idMultiplayerTriggerStrategy_BoostPad@@UAAXAAVidPresentableMultiplayerTrigger@@@Z
// EA  : 0x82B714D8
// RVA : 0x00B714D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idMultiplayerTriggerStrategy_BoostPad::Think(
        idMultiplayerTriggerStrategy_BoostPad *this,
        idPresentableMultiplayerTrigger *trigger)
{
  trigger->UpdateFX_2(this: trigger, a2: &this->fxOrigin, a3: &this->fxAxis);
}


// ========================================================================
// ?ServerThink@idPresentableMultiplayerTrigger@@UAAXH@Z
// EA  : 0x82B714F8
// RVA : 0x00B714F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idPresentableMultiplayerTrigger::ServerThink(idPresentableMultiplayerTrigger *this, int curTime)
{
  idMultiplayerTriggerStrategy *strategy; // r11

  strategy = this->strategy;
  if ( strategy != nullptr )
    ((void (*)(void))strategy->Think)();
}


// ========================================================================
// ?ClientThink@idPresentableMultiplayerTrigger@@UAAXHM_N@Z
// EA  : 0x82B71520
// RVA : 0x00B71520
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idPresentableMultiplayerTrigger::ClientThink(
        idPresentableMultiplayerTrigger *this,
        int curTime,
        double fraction,
        bool predict)
{
  ((void (__fastcall *)(idPresentableMultiplayerTrigger *, int, bool, double))this->Interpolate)(
    a1: this,
    a2: curTime,
    a3: predict,
    a4: fraction);
  this->ServerThink(this, a2: curTime);
  idPresentable::UpdateSound(this);
  this->Present(this);
}


// ========================================================================
// ?Boost@idMultiplayerTriggerStrategy_BoostPad@@QBAXAAVidPresentableVehicle@@ABVidVec3@@@Z
// EA  : 0x82B71598
// RVA : 0x00B71598
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idMultiplayerTriggerStrategy_BoostPad::Boost(
        idMultiplayerTriggerStrategy_BoostPad *this,
        idPresentableVehicle *car,
        const idVec3 *pushVelocity)
{
  idPhysics_AF *p_physicsObj; // r31

  p_physicsObj = &car->physicsObj;
  if ( car != (idPresentableVehicle *)-16512 )
  {
    p_physicsObj->SetAngularVelocity(this: p_physicsObj, a2: &vec3_origin, a3: 0);
    p_physicsObj->SetLinearVelocity(this: p_physicsObj, a2: pushVelocity, a3: 0);
    car->StartFX(this: (struct idPresentableAnimatedEntity *)car, a2: FX_VEH_MEGABOOST, a3: FX_EXTRA_COND_NONE);
    car->externalBoostDuration = this->boostTime;
  }
}


// ========================================================================
// ?BoostPadActivateFX@idMultiplayerTriggerStrategy_BoostPad@@QBAXAAVidPresentableMultiplayerTrigger@@@Z
// EA  : 0x82B71620
// RVA : 0x00B71620
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idMultiplayerTriggerStrategy_BoostPad::BoostPadActivateFX(
        idMultiplayerTriggerStrategy_BoostPad *this,
        idPresentableMultiplayerTrigger *trigger)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idFXManager::StartFX(
    this: &trigger->fxManager,
    org: &this->fxOrigin,
    axis: &this->fxAxis,
    time: GameMs,
    startCondition: 9);
}


// ========================================================================
// ?Touch@idPresentableMultiplayerTrigger@@SAXPAVidPresentableVehicle@@@Z
// EA  : 0x82B71688
// RVA : 0x00B71688
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idPresentableMultiplayerTrigger::Touch(
        idPresentableVehicle *car,
        int a2,
        int a3,
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
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        idClipModel *a27)
{
  int v27; // r3
  int v28; // r27
  int v29; // r25
  const idBounds *v30; // r3
  const char *ClipModelsTouchingBounds; // r3
  idClipModel **v32; // r29
  const char *i; // r26
  idClipModel *v34; // r31
  idPresentable *PresentableByEntityNum; // r3
  int v36; // r3
  int v37; // r30

  v27 = ((int (*)(void))RtlCheckStack12)();
  v28 = v27 + 16512;
  v29 = v27;
  v30 = (const idBounds *)(*(int (__fastcall **)(int, int))(*(_DWORD *)(v27 + 16512) + 44))(a1: v27 + 16512, a2: -1);
  ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                               this: &clientGame->clip,
                               bounds: v30,
                               clipMask: 0x4000,
                               clipModelList: &a27,
                               maxCount: (const char *)0x2000);
  if ( (int)ClipModelsTouchingBounds > 0 )
  {
    v32 = &a27;
    for ( i = ClipModelsTouchingBounds; i != nullptr; --i )
    {
      v34 = *v32;
      PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(
                                 this: clientGame,
                                 entityNum: (*v32)->entityNumber);
      if ( PresentableByEntityNum != nullptr )
      {
        v36 = (int)PresentableByEntityNum->GetMultiplayerTriggerInterface(this: PresentableByEntityNum);
        v37 = v36;
        if ( v36 != 0
          && *(_DWORD *)(v36 + 1232) != 0
          && (*(int (__fastcall **)(int, idClipModel *, int))(*(_DWORD *)v28 + 192))(a1: v28, a2: v34, a3: 0x4000) != 0 )
        {
          (*(void (__fastcall **)(_DWORD, int, int))(**(_DWORD **)(v37 + 1232) + 8))(
            a1: *(_DWORD *)(v37 + 1232),
            a2: v37,
            a3: v29);
        }
      }
      ++v32;
    }
  }
}


// ========================================================================
// ??0idMultiplayerTriggerStrategy_BoostPad@@QAA@XZ
// EA  : 0x82B71788
// RVA : 0x00B71788
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

idMultiplayerTriggerStrategy_BoostPad *__fastcall idMultiplayerTriggerStrategy_BoostPad::idMultiplayerTriggerStrategy_BoostPad(
        idMultiplayerTriggerStrategy_BoostPad *this)
{
  idMultiplayerTriggerStrategy_BoostPad *v1; // r10
  float *p_y; // r11
  int i; // ctr
  float z; // r11

  this->__vftable = (idMultiplayerTriggerStrategy_BoostPad_vtbl *)&idMultiplayerTriggerStrategy_BoostPad::`vftable';
  v1 = this;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
  {
    ++p_y;
    v1 = (idMultiplayerTriggerStrategy_BoostPad *)((char *)v1 + 4);
    v1->__vftable = *(idMultiplayerTriggerStrategy_BoostPad_vtbl **)p_y;
  }
  this->fxOrigin = vec3_origin;
  this->targetOrigin.x = vec3_origin.x;
  this->targetOrigin.y = vec3_origin.y;
  z = vec3_origin.z;
  this->acceleration = 0.0;
  this->targetOrigin.z = z;
  this->time = 1000;
  this->boostTime = 3000;
  this->hasTarget = false;
  return this;
}


// ========================================================================
// ?Serialize@idMultiplayerTriggerStrategy_BoostPad@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B71820
// RVA : 0x00B71820
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idMultiplayerTriggerStrategy_BoostPad::Serialize(
        idMultiplayerTriggerStrategy_BoostPad *this,
        idSerializer *ser)
{
  idMat3 *p_fxAxis; // r29
  idBitMsg *msg; // r3
  bool hasTarget; // r29

  p_fxAxis = &this->fxAxis;
  idSerializer::Serialize(this: ser, value: this->fxAxis.mat);
  idSerializer::Serialize(this: ser, value: &p_fxAxis->mat[1]);
  idSerializer::Serialize(this: ser, value: &p_fxAxis->mat[2]);
  idSerializer::Serialize(this: ser, value: &this->fxOrigin);
  msg = ser->msg;
  hasTarget = this->hasTarget;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->hasTarget, numBits: 1);
  else
    hasTarget = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->hasTarget = hasTarget;
  if ( hasTarget )
  {
    idSerializer::Serialize(this: ser, value: &this->targetOrigin);
  }
  else
  {
    idSerializer::Serialize(this: ser, value: &this->acceleration);
    idSerializer::Serialize(this: ser, value: &this->time);
  }
}


// ========================================================================
// ?BoostToTarget@idMultiplayerTriggerStrategy_BoostPad@@QBAXAAVidPresentableVehicle@@@Z
// EA  : 0x82B718E0
// RVA : 0x00B718E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idMultiplayerTriggerStrategy_BoostPad::BoostToTarget(
        idMultiplayerTriggerStrategy_BoostPad *this,
        idPresentableVehicle *car)
{
  idPhysics_AF *p_physicsObj; // r31
  float *v5; // r30
  float *v6; // r27
  double v7; // fp31
  float *v8; // r3
  double v9; // fp4
  double v10; // fp0
  double v12; // fp11
  double v13; // fp10
  double v14; // fp9
  double v16; // fp7
  double v17; // fp8
  double v18; // fp10
  double v19; // fp0
  double v20; // fp9
  idVec3 v21; // [sp+50h] [-50h] BYREF

  p_physicsObj = &car->physicsObj;
  if ( car != (idPresentableVehicle *)-16512 )
  {
    v5 = (float *)p_physicsObj->GetGravity(this: &car->physicsObj);
    v6 = (float *)p_physicsObj->GetGravityNormal(this: p_physicsObj);
    v7 = (float)((float)(v5[2] * v5[2]) + (float)((float)(*v5 * *v5) + (float)(v5[1] * v5[1])));
    v8 = (float *)p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
    v9 = (float)((float)__fsqrts(v7) * (float)0.5);
    v10 = (float)((float)((float)-1.0 / (float)v9)
                * (float)((float)(v6[2] * (float)(this->targetOrigin.z - v8[2]))
                        + (float)((float)(*v6 * (float)(this->targetOrigin.x - *v8))
                                + (float)(v6[1] * (float)(this->targetOrigin.y - v8[1])))));
    if ( v10 > 0.0 )
    {
      _FP1 = (float)((float)((float)((float)-1.0 / (float)v9)
                           * (float)((float)(v6[2] * (float)(this->targetOrigin.z - v8[2]))
                                   + (float)((float)(*v6 * (float)(this->targetOrigin.x - *v8))
                                           + (float)(v6[1] * (float)(this->targetOrigin.y - v8[1])))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v12 = (float)((float)(this->targetOrigin.y - v8[1])
                  - (float)(v6[1]
                          * (float)((float)(v6[2] * (float)(this->targetOrigin.z - v8[2]))
                                  + (float)((float)(*v6 * (float)(this->targetOrigin.x - *v8))
                                          + (float)(v6[1] * (float)(this->targetOrigin.y - v8[1]))))));
      v13 = (float)((float)(this->targetOrigin.x - *v8)
                  - (float)(*v6
                          * (float)((float)(v6[2] * (float)(this->targetOrigin.z - v8[2]))
                                  + (float)((float)(*v6 * (float)(this->targetOrigin.x - *v8))
                                          + (float)(v6[1] * (float)(this->targetOrigin.y - v8[1]))))));
      v14 = (float)((float)(this->targetOrigin.z - v8[2])
                  - (float)(v6[2]
                          * (float)((float)(v6[2] * (float)(this->targetOrigin.z - v8[2]))
                                  + (float)((float)(*v6 * (float)(this->targetOrigin.x - *v8))
                                          + (float)(v6[1] * (float)(this->targetOrigin.y - v8[1]))))));
      __asm { fsel      f8, f1, f0, f12 }
      v16 = __frsqrte(_FP8);
      v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                          * (float)((float)v10
                                                                                                  * (float)0.5))
                                                                                  * (float)v16)
                                                                          - (float)1.5)
                                                          * (float)v16)
                                                  * (float)((float)v10 * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v16
                                                                                  * (float)((float)v10 * (float)0.5))
                                                                          * (float)v16)
                                                                  - (float)1.5)
                                                  * (float)v16))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16)
                                          - (float)1.5)
                          * (float)v16));
      v21.y = (float)v12
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                            * (float)((float)v10 * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                            * (float)v16))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5))
                                                                                            * (float)v16)
                                                                                    - (float)1.5)
                                                                    * (float)v16))
                                                    * (float)((float)v10 * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                            * (float)v16)
                                                                                    * (float)((float)v10 * (float)0.5))
                                                                            * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                    * (float)v16))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v16
                                                                                            * (float)((float)v10 * (float)0.5))
                                                                                    * (float)v16)
                                                                            - (float)1.5)
                                                            * (float)v16)))
                                    - (float)1.5)
                    * (float)v17);
      v21.x = (float)v13
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                            * (float)((float)v10 * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                            * (float)v16))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5))
                                                                                            * (float)v16)
                                                                                    - (float)1.5)
                                                                    * (float)v16))
                                                    * (float)((float)v10 * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                            * (float)v16)
                                                                                    * (float)((float)v10 * (float)0.5))
                                                                            * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                    * (float)v16))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v16
                                                                                            * (float)((float)v10 * (float)0.5))
                                                                                    * (float)v16)
                                                                            - (float)1.5)
                                                            * (float)v16)))
                                    - (float)1.5)
                    * (float)v17);
      v21.z = (float)v14
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                            * (float)((float)v10 * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                            * (float)v16))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5))
                                                                                            * (float)v16)
                                                                                    - (float)1.5)
                                                                    * (float)v16))
                                                    * (float)((float)v10 * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                            * (float)v16)
                                                                                    * (float)((float)v10 * (float)0.5))
                                                                            * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                    * (float)v16))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v16
                                                                                            * (float)((float)v10 * (float)0.5))
                                                                                    * (float)v16)
                                                                            - (float)1.5)
                                                            * (float)v16)))
                                    - (float)1.5)
                    * (float)v17);
      v18 = (float)(v5[1]
                  * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16) * (float)((float)v10 * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16)
                                                                                                  - (float)1.5)
                                                                                  * (float)v16))
                                                                  * (float)((float)v10 * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                                  * (float)((float)v10 * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                                  * (float)v16))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5))
                                                                                                  * (float)v16)
                                                                                          - (float)1.5)
                                                                          * (float)v16)))
                                                  - (float)1.5)
                                  * (float)v17)
                          * (float)v10));
      v20 = (float)(v5[2]
                  * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16) * (float)((float)v10 * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16)
                                                                                                  - (float)1.5)
                                                                                  * (float)v16))
                                                                  * (float)((float)v10 * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                                  * (float)((float)v10 * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                                  * (float)v16))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5))
                                                                                                  * (float)v16)
                                                                                          - (float)1.5)
                                                                          * (float)v16)))
                                                  - (float)1.5)
                                  * (float)v17)
                          * (float)v10));
      v19 = (float)(*v5
                  * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16) * (float)((float)v10 * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16)
                                                                                                  - (float)1.5)
                                                                                  * (float)v16))
                                                                  * (float)((float)v10 * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                                  * (float)((float)v10 * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                                  * (float)v16))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)v10 * (float)0.5))
                                                                                                  * (float)v16)
                                                                                          - (float)1.5)
                                                                          * (float)v16)))
                                                  - (float)1.5)
                                  * (float)v17)
                          * (float)v10));
      v21.y = v21.y - (float)v18;
      v21.x = v21.x - (float)v19;
      v21.z = v21.z - (float)v20;
      idMultiplayerTriggerStrategy_BoostPad::Boost(this, car, pushVelocity: &v21);
    }
  }
}


// ========================================================================
// ?AllocStrategy@idPresentableMultiplayerTrigger@@AAAXW4mpTriggerType_t@@@Z
// EA  : 0x82B71A98
// RVA : 0x00B71A98
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idPresentableMultiplayerTrigger::AllocStrategy(
        idPresentableMultiplayerTrigger *this,
        mpTriggerType_t triggerType)
{
  idMultiplayerTriggerStrategy_BoostPad *v3; // r3
  idMultiplayerTriggerStrategy_BoostPad *v4; // r31
  idMultiplayerTriggerStrategy *strategy; // r3

  if ( triggerType == MP_TRIGGER_TYPE_BOOSTPAD )
  {
    v3 = (idMultiplayerTriggerStrategy_BoostPad *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                    size: 0x50u,
                                                    tag: TAG_NEW,
                                                    zeroBuffer: false,
                                                    align: ALIGN_16,
                                                    heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idMultiplayerTriggerStrategy_BoostPad::idMultiplayerTriggerStrategy_BoostPad(this: v3);
    else
      v4 = nullptr;
  }
  else
  {
    v4 = nullptr;
  }
  strategy = this->strategy;
  if ( strategy != nullptr )
    ((void (__fastcall *)(idMultiplayerTriggerStrategy *, int))strategy->dtr_idClass)(a1: strategy, a2: 1);
  this->strategy = v4;
}


// ========================================================================
// ?Touch@idMultiplayerTriggerStrategy_BoostPad@@UAAXAAVidPresentableMultiplayerTrigger@@AAVidPresentable@@@Z
// EA  : 0x82B71B48
// RVA : 0x00B71B48
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idMultiplayerTriggerStrategy_BoostPad::Touch(
        idMultiplayerTriggerStrategy_BoostPad *this,
        idPresentableMultiplayerTrigger *trigger,
        idPresentable *other)
{
  int v5; // r4
  idPresentableVehicle *v6; // r3

  v6 = other->GetVehicleInterface(this: other);
  if ( v6 != nullptr )
  {
    if ( this->hasTarget )
      idMultiplayerTriggerStrategy_BoostPad::BoostToTarget(this, car: v6);
    else
      idPresentableVehicle::Megaboost(this: v6, acceleration: this->acceleration, time: v5);
    idMultiplayerTriggerStrategy_BoostPad::BoostPadActivateFX(this, trigger);
  }
}


// ========================================================================
// ??0idPresentableMultiplayerTrigger@@QAA@PAVidMultiplayerTrigger@@PAVidRenderModel@@HPBVidDeclFX@@PAVidMultiplayerTriggerStrategy@@@Z
// EA  : 0x82B71BE0
// RVA : 0x00B71BE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

idPresentableMultiplayerTrigger *__fastcall idPresentableMultiplayerTrigger::idPresentableMultiplayerTrigger(
        idPresentableMultiplayerTrigger *this,
        idMultiplayerTrigger *ent,
        idTreeAnimator *renderModel_,
        int entityNumber_,
        const idDeclFX *fxDecl_,
        idMultiplayerTriggerStrategy *strategy_)
{
  idPresentable::idPresentable(this, e: ent, renderModel_, entityNumber_, fxDecl_);
  this->__vftable = (idPresentableMultiplayerTrigger_vtbl *)&idPresentableMultiplayerTrigger::`vftable';
  this->touching.list = nullptr;
  this->touching.granularity = 0;
  this->touching.memTag = 5;
  this->touching.listStatic = 0;
  this->touching.size = 0;
  this->touching.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  this->oldTouching.list = nullptr;
  this->oldTouching.granularity = 0;
  this->oldTouching.memTag = 5;
  this->oldTouching.listStatic = 0;
  this->oldTouching.size = 0;
  this->oldTouching.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->oldTouching);
  this->strategy = strategy_;
  this->triggerEntity = ent;
  return this;
}


// ========================================================================
// __unwind$488559
// EA  : 0x82B71C6C
// RVA : 0x00B71C6C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void _unwind_488559()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$488560
// EA  : 0x82B71C94
// RVA : 0x00B71C94
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void _unwind_488560()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 1200));
}


// ========================================================================
// ??1idPresentableMultiplayerTrigger@@UAA@XZ
// EA  : 0x82B71CC8
// RVA : 0x00B71CC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idPresentableMultiplayerTrigger::~idPresentableMultiplayerTrigger(
        idPresentableMultiplayerTrigger *this)
{
  idMultiplayerTriggerStrategy *strategy; // r3

  this->__vftable = (idPresentableMultiplayerTrigger_vtbl *)&idPresentableMultiplayerTrigger::`vftable';
  strategy = this->strategy;
  if ( strategy != nullptr )
    ((void (__fastcall *)(idMultiplayerTriggerStrategy *, int))strategy->dtr_idClass)(a1: strategy, a2: 1);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->oldTouching);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$488597
// EA  : 0x82B71D44
// RVA : 0x00B71D44
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void _unwind_488597()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488598
// EA  : 0x82B71D6C
// RVA : 0x00B71D6C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void _unwind_488598()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1200));
}


// ========================================================================
// __unwind$488599
// EA  : 0x82B71D98
// RVA : 0x00B71D98
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void _unwind_488599()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1216));
}


// ========================================================================
// ?Serialize@idPresentableMultiplayerTrigger@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B71DC8
// RVA : 0x00B71DC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablemultiplayertrigger.cpp
// ========================================================================

void __fastcall idPresentableMultiplayerTrigger::Serialize(idPresentableMultiplayerTrigger *this, idSerializer *ser)
{
  idMultiplayerTriggerStrategy *strategy; // r11
  int v5; // r4
  mpTriggerType_t Bits; // r30
  idBitMsg *msg; // r3
  unsigned int v8; // r10
  idMultiplayerTriggerStrategy *v9; // r11
  int v10; // r3
  idMultiplayerTriggerStrategy *v11; // r11

  idPresentable::Serialize(this, ser);
  strategy = this->strategy;
  if ( strategy != nullptr )
    v5 = ((int (*)(void))strategy->GetTriggerType)();
  else
    v5 = 0;
  Bits = v5;
  msg = ser->msg;
  v8 = _cntlzw(2u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: v5, numBits: 32 - v8);
  else
    Bits = idBitMsg::ReadBits(this: msg, numBits: 32 - v8);
  v9 = this->strategy;
  if ( v9 != nullptr )
    v10 = ((int (*)(void))v9->GetTriggerType)();
  else
    v10 = 0;
  if ( Bits != v10 )
    idPresentableMultiplayerTrigger::AllocStrategy(this, triggerType: Bits);
  v11 = this->strategy;
  if ( v11 != nullptr )
    ((void (*)(void))v11->Serialize)();
}

