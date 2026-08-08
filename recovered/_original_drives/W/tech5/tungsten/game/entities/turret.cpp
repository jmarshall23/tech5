
// ========================================================================
// ?GetFaction@idTurret@@UAAPAVidFaction@@XZ
// EA  : 0x82CF5328
// RVA : 0x00CF5328
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

const idFaction *__fastcall idTurret::GetFaction(idTurret *this)
{
  return &this->faction;
}


// ========================================================================
// ?IsDying@idTurret@@UBA_NXZ
// EA  : 0x82CF5330
// RVA : 0x00CF5330
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::IsDying(idTurret *this)
{
  idTurret::turretStates currentState; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  currentState = this->currentState;
  if ( currentState == TS_DYING )
    return 1;
  v3 = currentState != TS_HAYWIRE;
  v2 = 0;
  if ( !v3 )
    return 1;
  return v2;
}


// ========================================================================
// ?StopTurnSound@idTurret@@AAAXXZ
// EA  : 0x82CF5358
// RVA : 0x00CF5358
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::StopTurnSound(idTurret *this)
{
  if ( this->turningSound )
  {
    this->turningSound = false;
    idEntity::StopSound(this, channel: SND_CHANNEL_STEERING, peerMask: 0xFFu);
    idEntity::StopSound(this, channel: SND_CHANNEL_ENGINE_IDLE, peerMask: 0xFFu);
  }
}


// ========================================================================
// ?GetUsableState@idTurret@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82CF53B0
// RVA : 0x00CF53B0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::GetUsableState(idTurret *this)
{
  return this->isStatic ? 0 : 0xC;
}


// ========================================================================
// ?RestartSuppressing@idTurret@@AAAXXZ
// EA  : 0x82CF53C8
// RVA : 0x00CF53C8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::RestartSuppressing(idTurret *this)
{
  __int64 v2; // [sp+50h] [-20h]

  v2 = __PAIR64__(0x82000000, gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED));
  this->timeSuppressed = 0.0;
  this->startSuppressingFire = (float)v2;
}


// ========================================================================
// ?AllocPresentable@idTurret@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82CF5600
// RVA : 0x00CF5600
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

idPresentableTurret *__fastcall idTurret::AllocPresentable(idTurret *this, idRenderModel *renderModel_)
{
  idPresentableTurret *v4; // r29
  int entityNumber; // r27
  bool hasSphereModel; // r26
  const idDeclFX *v7; // r25
  idAnimStack *v8; // r3
  idAnimStack *v10; // [sp+8h] [-B8h]
  int v11; // [sp+Ch] [-B4h]
  const idDeclFX *v12; // [sp+10h] [-B0h]
  bool v13; // [sp+17h] [-A9h]
  int v14; // [sp+18h] [-A8h]
  int v15; // [sp+1Ch] [-A4h]
  int v16; // [sp+20h] [-A0h]
  int v17; // [sp+24h] [-9Ch]
  int v18; // [sp+28h] [-98h]
  int v19; // [sp+2Ch] [-94h]
  int v20; // [sp+30h] [-90h]
  int v21; // [sp+34h] [-8Ch]
  int v22; // [sp+38h] [-88h]
  int v23; // [sp+3Ch] [-84h]
  int v24; // [sp+40h] [-80h]
  int v25; // [sp+44h] [-7Ch]
  int v26; // [sp+48h] [-78h]
  int v27; // [sp+4Ch] [-74h]
  int v28; // [sp+50h] [-70h]
  int v29; // [sp+58h] [-68h]
  int v30; // [sp+60h] [-60h]
  int v31; // [sp+68h] [-58h]

  v4 = (idPresentableTurret *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x5A0u,
                                tag: TAG_PRESENTABLE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    return nullptr;
  entityNumber = this->entityNumber;
  hasSphereModel = this->hasSphereModel;
  v7 = this->GetFXDecl(this);
  v8 = this->GetAnimStack_2(this);
  return idPresentableTurret::idPresentableTurret(
           this: v4,
           weaponDecl_: this->weaponDecl,
           ent: this,
           renderModel_,
           jointMod_: &this->jointModAnimator,
           jointRotaion_: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
           jointPitch_: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value,
           jointSpinwheel_: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointSpinwheel.value,
           animStack_: v10,
           entityNumber_: v11,
           fxDecl_: v12,
           useSphereModel_: v13,
           a13: v14,
           a14: v15,
           a15: v16,
           a16: v17,
           a17: v18,
           a18: v19,
           a19: v20,
           a20: v21,
           a21: v22,
           a22: v23,
           a23: v24,
           a24: v25,
           a25: v26,
           a26: v27,
           a27: v28,
           a28: v8,
           a29: v29,
           a30: entityNumber,
           a31: v30,
           a32: (int)v7,
           a33: v31,
           a34: hasSphereModel);
}


// ========================================================================
// __unwind$496828
// EA  : 0x82CF56C8
// RVA : 0x00CF56C8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_496828()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 112), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?GetFXDecl@idTurret@@UBAPBVidDeclFX@@XZ
// EA  : 0x82CF56F8
// RVA : 0x00CF56F8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

const idDeclFX *__fastcall idTurret::GetFXDecl(idTurret *this)
{
  idWeapon *turretWeapon; // r11
  const idDeclInventory *decl; // r11
  const idDeclFX *weaponFX; // r11

  turretWeapon = this->turretWeapon;
  if ( turretWeapon != nullptr && (decl = turretWeapon->decl) != nullptr && (weaponFX = decl->weaponFX) != nullptr )
    return weaponFX;
  else
    return this->fxDecl;
}


// ========================================================================
// ?SetState@idTurret@@AAAXW4turretStates@1@@Z
// EA  : 0x82CF5730
// RVA : 0x00CF5730
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::SetState(idTurret *this, idTurret::turretStates state)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *str; // r5
  idTurret::turretStates currentState; // r11
  int GameMs; // r28
  const idAnimStack *v8; // r3
  const blendParms_t *v9; // r7
  blendParms_t v10[3]; // [sp+50h] [-40h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    if ( state == TS_DISABLED )
    {
      str = this->disabledMeshKit.str;
    }
    else if ( state == TS_SEARCHING )
    {
      str = this->searchMeshKit.str;
    }
    else
    {
      str = this->nonSearchMeshKit.str;
    }
    if ( str != nullptr && *str != 0 )
      idTreeAnimator::HideKitsExcept(this: TreeAnimatorFromPresentable, kitType: MESH_KIT_HEADS, name: str);
    if ( state == TS_DISABLED )
    {
      currentState = this->currentState;
      if ( currentState != TS_DISABLED && currentState != TS_DYING && this->disabledAnimAlias.value != 0xFFFF )
      {
        blendParms_t::blendParms_t(this: v10);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v8 = this->GetAnimStack_2(this);
        if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                                this: &this->channelAnimator,
                                stack: v8,
                                ah: &this->disabledAnimAlias,
                                curTime: GameMs,
                                rateScale: 1.0,
                                blendParms: v9,
                                blendOutDurationMS_: v10,
                                leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                                a9: nullptr) != 0 )
          idAnimator_Channel::ClearAnimator(this: &this->movingHoldAnimator);
      }
    }
    this->currentState = state;
  }
}


// ========================================================================
// ?IsTargePosInFiringArc@idTurret@@ABA_NABVidVec3@@00AAM@Z
// EA  : 0x82CF5840
// RVA : 0x00CF5840
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::IsTargePosInFiringArc(
        idTurret *this,
        const idVec3 *mypos,
        const idVec3 *facing,
        const idVec3 *targetpos,
        float *angle)
{
  double v6; // fp8
  double v7; // fp5
  double y; // fp30
  double x; // fp31
  double z; // fp29
  double v11; // fp26
  double v12; // fp1
  double v13; // fp4
  double v17; // fp7
  double v19; // fp6
  double v20; // fp7
  double v21; // fp6
  double v22; // fp7
  double v23; // fp28
  double v24; // fp6
  double v25; // fp27
  double v26; // fp8
  double v27; // fp7
  double v28; // fp6
  double v29; // fp5
  double v30; // fp27
  double v31; // fp28
  double v32; // fp26
  double v33; // fp1
  double v34; // fp5
  double v35; // fp4
  double v36; // fp2
  double v38; // fp10
  double v39; // fp12
  double v40; // fp11
  double v42; // fp3
  double v45; // fp13
  double v46; // fp3
  double v47; // fp13
  double v48; // fp3
  double v49; // fp13
  double v50; // fp3
  int result; // r3
  idVec3 v52; // [sp+50h] [-80h] BYREF
  idVec3 v53; // [sp+60h] [-70h] BYREF

  if ( this->currentState == TS_SUPPRESSING_FIRE )
    return 1;
  v6 = (float)(targetpos->y - mypos->y);
  v7 = (float)(targetpos->z - mypos->z);
  y = facing->y;
  x = facing->x;
  z = facing->z;
  v11 = (float)((float)(facing->x * vec3_up.y) - (float)(facing->y * vec3_up.x));
  v12 = (float)((float)(facing->z * vec3_up.x) - (float)(facing->x * vec3_up.z));
  v13 = (float)((float)(facing->y * vec3_up.z) - (float)(facing->z * vec3_up.y));
  _FP28 = (float)((float)((float)((float)(targetpos->x - mypos->x) * (float)(targetpos->x - mypos->x))
                        + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f28, f7, f13 }
  _FP28 = (float)((float)((float)((float)v13 * (float)v13)
                        + (float)((float)((float)v11 * (float)v11) + (float)((float)v12 * (float)v12)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  v17 = __frsqrte(_FP7);
  __asm { fsel      f6, f28, f6, f13 }
  v19 = __frsqrte(_FP6);
  v20 = (float)((float)-(float)((float)((float)((float)v17
                                              * (float)((float)((float)((float)(targetpos->x - mypos->x)
                                                                      * (float)(targetpos->x - mypos->x))
                                                              + (float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)v6 * (float)v6)))
                                                      * (float)0.5))
                                      * (float)v17)
                              - (float)1.5)
              * (float)v17);
  v21 = (float)((float)-(float)((float)((float)((float)v19
                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                              + (float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)v12 * (float)v12)))
                                                      * (float)0.5))
                                      * (float)v19)
                              - (float)1.5)
              * (float)v19);
  v22 = (float)((float)-(float)((float)((float)((float)v20
                                              * (float)((float)((float)((float)(targetpos->x - mypos->x)
                                                                      * (float)(targetpos->x - mypos->x))
                                                              + (float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)v6 * (float)v6)))
                                                      * (float)0.5))
                                      * (float)v20)
                              - (float)1.5)
              * (float)v20);
  v23 = (float)((float)-(float)((float)((float)((float)v21
                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                              + (float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)v12 * (float)v12)))
                                                      * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v25 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                                                              + (float)((float)((float)v11 * (float)v11) + (float)((float)v12 * (float)v12)))
                                                                                      * (float)0.5))
                                                                      * (float)v21)
                                                              - (float)1.5)
                                              * (float)v21)
                                      * (float)((float)((float)((float)v13 * (float)v13)
                                                      + (float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)v12 * (float)v12)))
                                              * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)v21
                                                                      * (float)((float)((float)((float)v13 * (float)v13)
                                                                                      + (float)((float)((float)v11 * (float)v11)
                                                                                              + (float)((float)v12 * (float)v12)))
                                                                              * (float)0.5))
                                                              * (float)v21)
                                                      - (float)1.5)
                                      * (float)v21))
                      - (float)1.5);
  v24 = (float)((float)-(float)((float)((float)((float)v22
                                              * (float)((float)((float)((float)(targetpos->x - mypos->x)
                                                                      * (float)(targetpos->x - mypos->x))
                                                              + (float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)v6 * (float)v6)))
                                                      * (float)0.5))
                                      * (float)v22)
                              - (float)1.5)
              * (float)v22);
  v26 = (float)((float)v6
              * (float)((float)-(float)((float)((float)((float)v22
                                                      * (float)((float)((float)((float)(targetpos->x - mypos->x)
                                                                              * (float)(targetpos->x - mypos->x))
                                                                      + (float)((float)((float)v7 * (float)v7)
                                                                              + (float)((float)v6 * (float)v6)))
                                                              * (float)0.5))
                                              * (float)v22)
                                      - (float)1.5)
                      * (float)v22));
  v27 = (float)((float)(targetpos->z - mypos->z) * (float)v24);
  v29 = (float)((float)v25 * (float)v23);
  v30 = (float)((float)((float)(facing->z * vec3_up.x) - (float)(facing->x * vec3_up.z))
              * (float)((float)v25 * (float)v23));
  v31 = (float)((float)((float)(facing->y * vec3_up.z) - (float)(facing->z * vec3_up.y)) * (float)v29);
  v32 = (float)((float)((float)(facing->x * vec3_up.y) - (float)(facing->y * vec3_up.x)) * (float)v29);
  v33 = (float)((float)((float)((float)(targetpos->z - mypos->z) * (float)v24) * vec3_up.z)
              + (float)((float)v26 * vec3_up.y));
  v28 = (float)((float)(targetpos->x - mypos->x) * (float)v24);
  v34 = (float)((float)v26 - (float)((float)((float)(vec3_up.x * (float)v28) + (float)v33) * vec3_up.y));
  v35 = (float)((float)v27 - (float)((float)((float)(vec3_up.x * (float)v28) + (float)v33) * vec3_up.z));
  v36 = (float)((float)v28 - (float)((float)((float)(vec3_up.x * (float)v28) + (float)v33) * vec3_up.x));
  _FP3 = (float)((float)((float)((float)v36 * (float)v36)
                       + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v38 = (float)(facing->y
              - (float)((float)((float)(vec3_up.x * facing->x)
                              + (float)((float)(facing->z * vec3_up.z) + (float)(facing->y * vec3_up.y)))
                      * vec3_up.y));
  v39 = (float)(facing->z
              - (float)((float)((float)(vec3_up.x * facing->x)
                              + (float)((float)(facing->z * vec3_up.z) + (float)(facing->y * vec3_up.y)))
                      * vec3_up.z));
  v40 = (float)(facing->x
              - (float)((float)((float)(vec3_up.x * facing->x)
                              + (float)((float)(facing->z * vec3_up.z) + (float)(facing->y * vec3_up.y)))
                      * vec3_up.x));
  __asm { fsel      f3, f3, f1, f13 }
  v42 = __frsqrte(_FP3);
  _FP22 = (float)((float)((float)((float)v40 * (float)v40)
                        + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f22, f1, f13 }
  v45 = (float)((float)-(float)((float)((float)((float)v42
                                              * (float)((float)((float)((float)v36 * (float)v36)
                                                              + (float)((float)((float)v35 * (float)v35)
                                                                      + (float)((float)v34 * (float)v34)))
                                                      * (float)0.5))
                                      * (float)v42)
                              - (float)1.5)
              * (float)v42);
  v46 = (float)__frsqrte(_FP1);
  v47 = (float)((float)-(float)((float)((float)((float)v45
                                              * (float)((float)((float)((float)v36 * (float)v36)
                                                              + (float)((float)((float)v35 * (float)v35)
                                                                      + (float)((float)v34 * (float)v34)))
                                                      * (float)0.5))
                                      * (float)v45)
                              - (float)1.5)
              * (float)v45);
  v48 = (float)((float)-(float)((float)((float)((float)v46
                                              * (float)((float)((float)((float)v40 * (float)v40)
                                                              + (float)((float)((float)v39 * (float)v39)
                                                                      + (float)((float)v38 * (float)v38)))
                                                      * (float)0.5))
                                      * (float)v46)
                              - (float)1.5)
              * (float)v46);
  v49 = (float)((float)-(float)((float)((float)((float)v47
                                              * (float)((float)((float)((float)v36 * (float)v36)
                                                              + (float)((float)((float)v35 * (float)v35)
                                                                      + (float)((float)v34 * (float)v34)))
                                                      * (float)0.5))
                                      * (float)v47)
                              - (float)1.5)
              * (float)v47);
  v50 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v48
                                                                                      * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
                                                                                              * (float)0.5))
                                                                              * (float)v48)
                                                                      - (float)1.5)
                                                      * (float)v48)
                                              * (float)((float)((float)((float)v40 * (float)v40)
                                                              + (float)((float)((float)v39 * (float)v39)
                                                                      + (float)((float)v38 * (float)v38)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v48
                                                                              * (float)((float)((float)((float)v40 * (float)v40)
                                                                                              + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
                                                                                      * (float)0.5))
                                                                      * (float)v48)
                                                              - (float)1.5)
                                              * (float)v48))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v48
                                                      * (float)((float)((float)((float)v40 * (float)v40)
                                                                      + (float)((float)((float)v39 * (float)v39)
                                                                              + (float)((float)v38 * (float)v38)))
                                                              * (float)0.5))
                                              * (float)v48)
                                      - (float)1.5)
                      * (float)v48));
  if ( (float)((float)((float)((float)(facing->x
                                     - (float)((float)((float)(vec3_up.x * facing->x)
                                                     + (float)((float)(facing->z * vec3_up.z)
                                                             + (float)(facing->y * vec3_up.y)))
                                             * vec3_up.x))
                             * (float)v50)
                     * (float)((float)v36 * (float)v49))
             + (float)((float)((float)((float)(facing->z
                                             - (float)((float)((float)(vec3_up.x * facing->x)
                                                             + (float)((float)(facing->z * vec3_up.z)
                                                                     + (float)(facing->y * vec3_up.y)))
                                                     * vec3_up.z))
                                     * (float)v50)
                             * (float)((float)v35 * (float)v49))
                     + (float)((float)((float)(facing->y
                                             - (float)((float)((float)(vec3_up.x * facing->x)
                                                             + (float)((float)(facing->z * vec3_up.z)
                                                                     + (float)(facing->y * vec3_up.y)))
                                                     * vec3_up.y))
                                     * (float)v50)
                             * (float)((float)v34 * (float)v49)))) < (double)this->cosMaxFireAngle )
    return 0;
  v52.x = (float)v28
        - (float)((float)((float)((float)v31 * (float)v28)
                        + (float)((float)((float)v32 * (float)v27) + (float)((float)v30 * (float)v26)))
                * (float)v31);
  v52.y = (float)v26
        - (float)((float)v30
                * (float)((float)((float)v31 * (float)v28)
                        + (float)((float)((float)v32 * (float)v27) + (float)((float)v30 * (float)v26))));
  v52.z = (float)v27
        - (float)((float)v32
                * (float)((float)((float)v31 * (float)v28)
                        + (float)((float)((float)v32 * (float)v27) + (float)((float)v30 * (float)v26))));
  idVec3::NormalizeFast(this: &v52);
  v53.x = (float)x
        - (float)((float)((float)((float)v31 * (float)x)
                        + (float)((float)((float)v32 * (float)z) + (float)((float)v30 * (float)y)))
                * (float)v31);
  v53.y = (float)y
        - (float)((float)v30
                * (float)((float)((float)v31 * (float)x)
                        + (float)((float)((float)v32 * (float)z) + (float)((float)v30 * (float)y))));
  v53.z = (float)z
        - (float)((float)v32
                * (float)((float)((float)v31 * (float)x)
                        + (float)((float)((float)v32 * (float)z) + (float)((float)v30 * (float)y))));
  idVec3::NormalizeFast(this: &v53);
  result = 0;
  if ( (float)((float)(v53.x * v52.x) + (float)((float)(v53.z * v52.z) + (float)(v53.y * v52.y))) >= (double)this->cosMaxFirePitch )
    return 1;
  return result;
}


// ========================================================================
// ?OnMakeActivatable@idTurret@@EAAX_N@Z
// EA  : 0x82CF5B48
// RVA : 0x00CF5B48
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::OnMakeActivatable(idTurret *this, const bool activatable)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *str; // r5

  if ( activatable )
  {
    this->startOff = false;
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      str = this->nonSearchMeshKit.str;
      if ( str != nullptr && *str != 0 )
        idTreeAnimator::HideKitsExcept(this: TreeAnimatorFromPresentable, kitType: MESH_KIT_HEADS, name: str);
      this->currentState = TS_INACTIVE;
    }
  }
  else
  {
    this->startOff = true;
    idTurret::SetState(this, state: TS_DISABLED);
  }
}


// ========================================================================
// ?GetDamageGroup@idTurret@@AAAPAVidDamageGroup@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82CF5BE0
// RVA : 0x00CF5BE0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

idDamageGroup *__fastcall idTurret::GetDamageGroup(
        idTurret *this,
        const idIndex<short,enum invalidJointIndex_t> *joint)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r31
  int num; // r27
  const idDeclMD6 *decl; // r11
  idJointGroupCollection *p_jointGroupCollection; // r3
  const idJointGroup *JointGroupForJoint; // r28
  int v11; // r30
  int i; // r31

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  num = this->damageGroups.num;
  if ( v6 == nullptr || num <= 0 )
    return nullptr;
  decl = v6->decl;
  p_jointGroupCollection = &decl->jointGroupCollection;
  if ( decl == nullptr )
    p_jointGroupCollection = nullptr;
  JointGroupForJoint = idJointGroupCollection::GetJointGroupForJoint(
                         this: p_jointGroupCollection,
                         type: 0,
                         jointIndex: joint);
  if ( JointGroupForJoint == nullptr )
    return nullptr;
  v11 = 0;
  for ( i = 0; idStr::Icmp(s1: this->damageGroups.list[i].groupName.data, s2: JointGroupForJoint->groupName.str) != 0; ++i )
  {
    if ( ++v11 >= num )
      return nullptr;
  }
  return &this->damageGroups.list[v11];
}


// ========================================================================
// ?GetModelSpaceJointDir@idTurret@@ABAXV?$idIndex@FW4invalidJointIndex_t@@@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CF5CB8
// RVA : 0x00CF5CB8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::GetModelSpaceJointDir(
        idTurret *this,
        idIndex<short,enum invalidJointIndex_t> *joint,
        idVec3 *offset,
        idMat3 *axisModel)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  if ( (__int16)joint >= 0 && idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::GetModelSpaceJointTransform(
      this: TreeAnimatorFromPresentable,
      pose: DRIVER_MODEL,
      jointIndex: joint,
      origin: offset,
      axis: axisModel);
  }
}


// ========================================================================
// ?SetModelSpaceJointDir@idTurret@@AAAXV?$idIndex@FW4invalidJointIndex_t@@@@AAVidMat3@@@Z
// EA  : 0x82CF5D10
// RVA : 0x00CF5D10
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::SetModelSpaceJointDir(
        idTurret *this,
        idIndex<short,enum invalidJointIndex_t> *joint,
        idMat3 *axisModel)
{
  idPresentable *presentable; // r3
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  idPresentable *v12; // r3
  _DWORD *v13; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idPresentableTurret *v16; // r3
  __int64 v17; // r10
  int v18; // [sp+8h] [-98h]
  int v19; // [sp+Ch] [-94h]
  __int64 v20; // [sp+10h] [-90h]
  __int64 v21; // [sp+18h] [-88h]
  __int64 v22; // [sp+20h] [-80h]
  __int64 v23; // [sp+28h] [-78h]
  __int64 v24; // [sp+30h] [-70h]
  __int64 v25; // [sp+38h] [-68h]
  __int64 v26; // [sp+40h] [-60h]
  __int64 v27; // [sp+48h] [-58h] BYREF
  __int64 v28; // [sp+58h] [-48h]
  __int64 v29; // [sp+60h] [-40h]
  __int64 v30; // [sp+68h] [-38h]
  int v31; // [sp+70h] [-30h]

  if ( (__int16)joint >= 0
    && idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr
    && !this->turretHealth.IsDead_Impl(this: &this->turretHealth) )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    if ( presentable->GetTurretInterface(this: presentable) != nullptr )
    {
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      v12 = this->presentable;
      v13 = (_DWORD *)&v27 + 1;
      p_z = (_DWORD *)&axisModel[-1].mat[2].z;
      for ( i = 9; i != 0; --i )
        *++v13 = *++p_z;
      v16 = v12->GetTurretInterface(this: v12);
      HIDWORD(v17) = __ROL4__(v31, 32);
      idPresentableTurret::ApplyJointMod(
        this: v16,
        axis: __SPAIR64__(HIDWORD(v28), HIDWORD(v29)),
        a3: v30,
        a4: v17,
        a5: v18,
        a6: v20,
        a7: v21,
        a8: v22,
        a9: v23,
        a10: v24,
        a11: v25,
        a12: v26,
        a13: v27);
    }
    idAnimator_JointMod::SetJointMod(
      this: &this->jointModAnimator,
      index: joint,
      value: axisModel,
      a4: v11,
      a5: v10,
      a6: v9,
      a7: v8,
      a8: v7,
      a9: v18,
      a10: v19,
      a11: SHIDWORD(v20),
      a12: v20,
      a13: SHIDWORD(v21),
      a14: (idIndex<short,enum invalidUserChannelIndex_t> *)v21);
  }
}


// ========================================================================
// ?GetMuzzleDirection@idTurret@@QBAXAAVidVec3@@@Z
// EA  : 0x82CF5E18
// RVA : 0x00CF5E18
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::GetMuzzleDirection(idTurret *this, idVec3 *dir)
{
  double y; // fp13
  double z; // fp12
  idVec3 v5; // [sp+50h] [-50h] BYREF
  idMat3 v6; // [sp+60h] [-40h] BYREF

  idAnimatedEntity::GetTagPosition(
    this,
    propIndex: this->propinfoIndex,
    tagIndex: this->muzzleTagIndex,
    origin: &v5,
    axis: &v6);
  y = v6.mat[0].y;
  z = v6.mat[0].z;
  dir->x = v6.mat[0].x;
  dir->y = y;
  dir->z = z;
}


// ========================================================================
// ?IsDead@idTurret@@UBA_NXZ
// EA  : 0x82CF5E70
// RVA : 0x00CF5E70
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::IsDead(idTurret *this)
{
  idTurret::turretStates currentState; // r11
  unsigned __int8 v3; // r11
  bool v4; // zf

  if ( this->turretHealth.IsDead_Impl(this: &this->turretHealth) )
    return 1;
  currentState = this->currentState;
  if ( currentState == TS_DYING )
    return 1;
  v4 = currentState != TS_DISABLED;
  v3 = 0;
  if ( !v4 )
    return 1;
  return v3;
}


// ========================================================================
// ?GetAimPoint@idTurret@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82CF5ED8
// RVA : 0x00CF5ED8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::GetAimPoint(idTurret *this, const aimPoint_t type, idVec3 *pos)
{
  idPhysics *Physics; // r3
  float *v5; // r3

  Physics = idEntity::GetPhysics(this);
  v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  pos->x = *v5;
  pos->y = v5[1];
  pos->z = (float)((float)(UNITS_PER_INCH_15 * (float)5.0) * (float)12.0) + v5[2];
}


// ========================================================================
// ?GetViewStateFOV@idTurret@@EAAXAAVidVec3@@AAE1@Z
// EA  : 0x82CF5F50
// RVA : 0x00CF5F50
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::GetViewStateFOV(
        idTurret *this,
        idVec3 *viewfwd,
        unsigned __int8 *horzFOV,
        unsigned __int8 *vertFOV)
{
  double y; // fp13
  double z; // fp12
  unsigned __int8 y_low; // r11
  unsigned __int8 v11; // r11
  idVec3 v12; // [sp+50h] [-60h] BYREF
  idMat3 v13; // [sp+60h] [-50h] BYREF

  idAnimatedEntity::GetTagPosition(
    this,
    propIndex: this->propinfoIndex,
    tagIndex: this->muzzleTagIndex,
    origin: &v12,
    axis: &v13);
  y = v13.mat[0].y;
  z = v13.mat[0].z;
  viewfwd->x = v13.mat[0].x;
  viewfwd->y = y;
  viewfwd->z = z;
  LODWORD(v12.y) = (int)this->maxFireAngle;
  y_low = LOBYTE(v12.y);
  if ( v12.y >= 0.0 )
  {
    if ( SLODWORD(v12.y) > 255 )
      y_low = -1;
  }
  else
  {
    y_low = 0;
  }
  *horzFOV = y_low;
  LODWORD(v12.y) = (int)this->turretFOV;
  v11 = LOBYTE(v12.y);
  if ( v12.y >= 0.0 )
  {
    if ( SLODWORD(v12.y) > 255 )
      v11 = -1;
    *vertFOV = v11;
  }
  else
  {
    *vertFOV = 0;
  }
}


// ========================================================================
// ?GetViewStateFOV@idTurret@@EBAXAAVidVec3@@AAE1@Z
// EA  : 0x82CF6010
// RVA : 0x00CF6010
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::GetViewStateFOV(
        idTurret *this,
        idVec3 *viewfwd,
        unsigned __int8 *horzFOV,
        unsigned __int8 *vertFOV)
{
  double y; // fp13
  double z; // fp12
  idVec3 v10; // [sp+50h] [-60h] BYREF
  idMat3 v11; // [sp+60h] [-50h] BYREF

  idAnimatedEntity::GetTagPosition(
    this,
    propIndex: this->propinfoIndex,
    tagIndex: this->muzzleTagIndex,
    origin: &v10,
    axis: &v11);
  y = v11.mat[0].y;
  z = v11.mat[0].z;
  viewfwd->x = v11.mat[0].x;
  viewfwd->y = y;
  viewfwd->z = z;
  *(_QWORD *)&v10.x = (__int64)this->turretFOV;
  *horzFOV = LOBYTE(v10.y);
  *(_QWORD *)&v10.x = (__int64)this->turretFOV;
  *vertFOV = LOBYTE(v10.y);
}


// ========================================================================
// ?GetVisibilityPoint@idTurret@@UBAXW4visPoint_t@@AAVidVec3@@@Z
// EA  : 0x82CF6088
// RVA : 0x00CF6088
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::GetVisibilityPoint(idTurret *this, const visPoint_t type, idVec3 *pos)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  idMat3 v6; // [sp+50h] [-40h] BYREF

  if ( type != VISPOINT_EYES )
  {
    Physics = idEntity::GetPhysics(this);
    v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    pos->x = *v5;
    pos->y = v5[1];
    pos->z = (float)((float)(UNITS_PER_INCH_15 * (float)5.0) * (float)12.0) + v5[2];
  }
  else
  {
    idAnimatedEntity::GetTagPosition(
      this,
      propIndex: this->propinfoIndex,
      tagIndex: this->muzzleTagIndex,
      origin: pos,
      axis: &v6);
  }
}


// ========================================================================
// ?FireShotEffects@idTurret@@AAAXXZ
// EA  : 0x82CF6130
// RVA : 0x00CF6130
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::FireShotEffects(idTurret *this)
{
  int PreviousGameMs; // r30
  int v3; // r3
  idIndex<short,enum invalidJointIndex_t> *value; // r4
  double spinwheelSpeed; // fp0
  const idMat3 *v6; // r3
  idMat3 v7[2]; // [sp+50h] [-A0h] BYREF
  idAngles v8[4]; // [sp+A0h] [-50h] BYREF

  if ( (unsigned __int16)this->jointSpinwheel.value < 0x8000u && this->spinTimer > 0 && this->spinwheelSpeed > 0.0 )
  {
    PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    value = (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointSpinwheel.value;
    this->spinTimer -= v3 - PreviousGameMs;
    idTurret::GetModelSpaceJointDir(
      this,
      joint: value,
      offset: (idVec3 *)&v7[0].mat[1].y,
      axisModel: (idMat3 *)&v7[0].mat[2].z);
    spinwheelSpeed = this->spinwheelSpeed;
    v7[0].mat[0].y = 0.0;
    v7[0].mat[0].z = 0.0;
    v7[0].mat[0].x = spinwheelSpeed;
    v6 = idAngles::ToMat3(this: v8, result: v7);
    idMat3::operator*=(this: (idMat3 *)&v7[0].mat[2].z, a: v6);
    idTurret::SetModelSpaceJointDir(
      this,
      joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointSpinwheel.value,
      axisModel: (idMat3 *)&v7[0].mat[2].z);
  }
}


// ========================================================================
// ?RestartSearch@idTurret@@AAAXXZ
// EA  : 0x82CF6228
// RVA : 0x00CF6228
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::RestartSearch(idTurret *this)
{
  double y; // fp13
  double z; // fp12
  idGameLocal *v4; // r3
  int v5; // r3
  BOOL searchFromLastTarget; // r6
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  double v8; // fp12
  double x; // fp6
  double v10; // fp13
  double v11; // fp7
  double v12; // fp8
  double v13; // fp5
  double v14; // fp4
  double v17; // fp8
  double v18; // fp11
  double v19; // fp8
  idVec3 v20[2]; // [sp+58h] [-88h] BYREF
  idMat3 v21; // [sp+70h] [-70h] BYREF
  idMat3 v22; // [sp+A0h] [-40h] BYREF

  idAnimatedEntity::GetTagPosition(
    this,
    propIndex: this->propinfoIndex,
    tagIndex: this->muzzleTagIndex,
    origin: v20,
    axis: &v22);
  y = v22.mat[0].y;
  z = v22.mat[0].z;
  this->startSearchDir.x = v22.mat[0].x;
  this->startSearchDir.y = y;
  v4 = gameLocal;
  this->startSearchDir.z = z;
  v5 = v4->GetGameMs(this: v4, a2: GAMETIME_SCALED);
  searchFromLastTarget = this->searchFromLastTarget;
  this->timeSearched = 0.0;
  this->startSearchTime = (float)__SPAIR64__(0x82000000, v5);
  if ( !searchFromLastTarget )
    this->returnToCenter = true;
  if ( !this->setStartingInfo )
  {
    this->setStartingInfo = true;
    if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                            this,
                            propIndex: this->propinfoIndex,
                            tagIndex: this->muzzleTagIndex,
                            origin: &this->startPos,
                            axis: &v21) == 0
      && (unsigned __int16)this->jointRotation.value < 0x8000u )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: TreeAnimatorFromPresentable,
        pose: (animationPose_t)0,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
        origin: &this->startPos,
        axis: &v21);
    }
    v8 = v21.mat[0].z;
    x = v21.mat[0].x;
    v10 = v21.mat[0].y;
    v11 = (float)(this->startPos.z + v21.mat[0].z);
    v12 = (float)(this->startPos.y + v21.mat[0].y);
    this->goalPos.x = this->startPos.x + v21.mat[0].x;
    this->goalPos.y = v12;
    v13 = v8;
    this->goalPos.z = v11;
    this->startForwardDir.z = v8;
    this->startForwardDir.x = x;
    this->startForwardDir.y = v10;
    v14 = this->startForwardDir.y;
    _FP11 = (float)((float)((float)((float)v13 * (float)v13)
                          + (float)((float)((float)x * (float)x)
                                  + (float)(this->startForwardDir.y * this->startForwardDir.y)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f9, f11, f1, f13 }
    v17 = __frsqrte(_FP9);
    v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                        * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)x * (float)x) + (float)(this->startForwardDir.y * this->startForwardDir.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v17)
                                                                        - (float)1.5)
                                                        * (float)v17)
                                                * (float)((float)((float)((float)v13 * (float)v13)
                                                                + (float)((float)((float)x * (float)x)
                                                                        + (float)(this->startForwardDir.y
                                                                                * this->startForwardDir.y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v17
                                                                                * (float)((float)((float)((float)v13 * (float)v13)
                                                                                                + (float)((float)((float)x * (float)x) + (float)(this->startForwardDir.y * this->startForwardDir.y)))
                                                                                        * (float)0.5))
                                                                        * (float)v17)
                                                                - (float)1.5)
                                                * (float)v17))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v17
                                                        * (float)((float)((float)((float)v13 * (float)v13)
                                                                        + (float)((float)((float)x * (float)x)
                                                                                + (float)(this->startForwardDir.y
                                                                                        * this->startForwardDir.y)))
                                                                * (float)0.5))
                                                * (float)v17)
                                        - (float)1.5)
                        * (float)v17));
    v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)x * (float)x) + (float)(this->startForwardDir.y * this->startForwardDir.y))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                                * (float)v17)
                                                                                        * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)x * (float)x) + (float)(this->startForwardDir.y * this->startForwardDir.y)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)x * (float)x) + (float)(this->startForwardDir.y * this->startForwardDir.y))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                        * (float)v17))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v17
                                                                                                * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)x * (float)x) + (float)(this->startForwardDir.y * this->startForwardDir.y))) * (float)0.5))
                                                                                        * (float)v17)
                                                                                - (float)1.5)
                                                                * (float)v17))
                                                * (float)((float)((float)((float)v13 * (float)v13)
                                                                + (float)((float)((float)x * (float)x)
                                                                        + (float)(this->startForwardDir.y
                                                                                * this->startForwardDir.y)))
                                                        * (float)0.5))
                                        * (float)v18)
                                - (float)1.5)
                * (float)v18);
    this->startForwardDir.x = (float)x * (float)v19;
    this->startForwardDir.y = (float)v14 * (float)v19;
    this->startForwardDir.z = (float)v8 * (float)v19;
  }
}


// ========================================================================
// ?InventoryAdded@idTurret@@UAAXPAVidInventoryItem@@H@Z
// EA  : 0x82CF63F8
// RVA : 0x00CF63F8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::InventoryAdded(idTurret *this, idInventoryItem *item, int count)
{
  idTurret::SetState(this, state: TS_DISABLED);
  this->stateTimer = -1;
}


// ========================================================================
// ?StartRagdoll@idTurret@@EAA_NXZ
// EA  : 0x82CF6430
// RVA : 0x00CF6430
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::StartRagdoll(idTurret *this)
{
  char v3; // r11
  idAnimStack *v4; // r3
  idPhysics_AF_vtbl *v5; // r28
  idRotation *v6; // r3
  idPhysics *Physics; // r3
  idPhysics *v8; // r3
  const idVec3 *v9; // r28
  idPhysics *v10; // r3
  const idMat3 *v11; // r27
  idPhysics *v12; // r3
  idPhysics *v13; // r3
  int v14; // r5
  int v15; // r3
  idAnimStack *v16; // r3
  int GameMs; // r30
  const idAnimStack *v18; // r3
  idMat3 v19[3]; // [sp+50h] [-80h] BYREF

  if ( this->afProperties.articulatedFigure == nullptr )
    return 0;
  if ( this->afProperties.isActive || (v3 = 0, this->afProperties.isClientAuthoritativeActive) )
    v3 = 1;
  if ( v3 == 0 )
  {
    v4 = this->GetAnimStack_2(this);
    idAnimator_Base::SetEnabled(this: &this->afProperties, animStack: v4, enabled: false);
    v5 = this->afProperties.physicsObj.__vftable;
    v6 = idMat3::ToRotation(this: v19, result: (idRotation *)&this->spawnOrientation);
    v5->Rotate(this: &this->afProperties.physicsObj, a2: v6, a3: -1);
    this->afProperties.physicsObj.Translate(this: &this->afProperties.physicsObj, a2: &this->spawnPosition, a3: -1);
    Physics = idEntity::GetPhysics(this);
    Physics->DisableClip(this: Physics);
    v8 = idEntity::GetPhysics(this);
    v9 = v8->GetOrigin(this: v8, a2: 0);
    v10 = idEntity::GetPhysics(this);
    v11 = v10->GetAxis(this: v10, a2: 0);
    v12 = idEntity::GetPhysics(this);
    v12->SetOrigin(this: v12, a2: v9, a3: -1);
    v13 = idEntity::GetPhysics(this);
    v13->SetAxis(this: v13, a2: v11, a3: -1);
    this->afProperties.physicsObj.SetOrigin(this: &this->afProperties.physicsObj, a2: v9, a3: -1);
    this->afProperties.physicsObj.SetAxis(this: &this->afProperties.physicsObj, a2: v11, a3: -1);
    idEntity::SetPhysics(this, phys: &this->afProperties.physicsObj.idPhysics_DynamicBase, a3: v14);
    this->afProperties.physicsObj.PutToRest(this: &this->afProperties.physicsObj);
    this->afProperties.physicsObj.EnableClip(this: &this->afProperties.physicsObj);
    v15 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAnimator_AF::StartFromCurrentPose(
      this: &this->afProperties,
      time: v15,
      inheritAnimationVelocity_: true,
      inheritOverrideVelocity_: false,
      overrideVelocity_: &vec3_origin);
    idEntity::UpdateVisuals(this);
    v16 = this->GetAnimStack_2(this);
    idAnimator_Base::SetEnabled(this: &this->afProperties, animStack: v16, enabled: true);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v18 = this->GetAnimStack_2(this);
    idAnimator_Base::Start(this: &this->afProperties, stack: v18, curTime: GameMs, blendDurationMS: 100, reset: true);
  }
  return 1;
}


// ========================================================================
// ?Event_Kill@idTurret@@AAA?AVeventVoid@@XZ
// EA  : 0x82CF66B0
// RVA : 0x00CF66B0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

idTurret *__fastcall idTurret::Event_Kill(idTurret *this, eventVoid *result)
{
  eventVoid *v2; // r30

  v2 = result + 6928;
  if ( (*(unsigned __int8 (__fastcall **)(eventVoid *))(*(_DWORD *)&result[6928] + 88))(a1: result + 6928) == 0
    && gameLocal->damageSuicide != nullptr )
  {
    (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)v2 + 76))(a1: v2);
    (*(void (__fastcall **)(eventVoid *, eventVoid *, eventVoid *, const idDeclDamage *))(*(_DWORD *)result + 312))(
      a1: result,
      a2: result,
      a3: result,
      a4: gameLocal->damageSuicide);
  }
  return this;
}


// ========================================================================
// ?Event_Deactivate@idTurret@@AAA?AVeventVoid@@XZ
// EA  : 0x82CF6758
// RVA : 0x00CF6758
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

idTurret *__fastcall idTurret::Event_Deactivate(idTurret *this, idAnimatedEntity *result)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *v5; // r5

  BYTE1(result[1].animStack.rememberedNodes.staticList[34]) = 1;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    v5 = *(const char **)&result[1].name.baseBuffer[12];
    if ( v5 != nullptr && *v5 != 0 )
      idTreeAnimator::HideKitsExcept(this: TreeAnimatorFromPresentable, kitType: MESH_KIT_HEADS, name: v5);
    result[2].animEventHandler.triggeredEvents.staticList[3].eventId.value = 10;
  }
  return this;
}


// ========================================================================
// ?GetSoundTransform@idTurret@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CF67D0
// RVA : 0x00CF67D0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::GetSoundTransform(idTurret *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  idMat3 v5; // [sp+50h] [-40h] BYREF

  idEntity::GetSoundTransform(this, soundOrigin, soundAxis);
  *soundAxis = *idMat3::operator*(this: &v5, result: &this->soundTransform, a: soundAxis);
  idMat3::OrthoNormalizeSelf(this: soundAxis);
}


// ========================================================================
// ?Spawn@idTowerTurret@@QAAXXZ
// EA  : 0x82CF6868
// RVA : 0x00CF6868
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTowerTurret::Spawn(idTowerTurret *this)
{
  idPhysics *Physics; // r3
  const idVec3 *v3; // r3
  idPhysics *v4; // r3
  const idVec3 *v5; // r3
  idPhysics *v6; // r30
  idPhysics *v7; // r29
  idPhysics_vtbl *v8; // r31
  int v9; // r3

  if ( this->breakableBody != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = Physics->GetOrigin(this: Physics, a2: 0);
    idBreakableManager::AddBreakable(this: &gameLocal->breakableManager, decl: this->breakableBody, origin: v3);
  }
  if ( this->breakableHead != nullptr )
  {
    v4 = idEntity::GetPhysics(this);
    v5 = v4->GetOrigin(this: v4, a2: 0);
    idBreakableManager::AddBreakable(this: &gameLocal->breakableManager, decl: this->breakableHead, origin: v5);
  }
  v6 = idEntity::GetPhysics(this);
  v7 = idEntity::GetPhysics(this);
  v8 = v7->__vftable;
  v9 = v6->GetClipMask(this: v6, a2: -1);
  v8->SetClipMask(this: v7, a2: v9 | 0x1000, a3: -1);
}


// ========================================================================
// ?CheckState@idTurret@@AAA_NXZ
// EA  : 0x82CF6950
// RVA : 0x00CF6950
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::CheckState(idTurret *this)
{
  idTurret::turretStates currentState; // r11
  idPhysics *Physics; // r3
  float *v4; // r3
  char v5; // r11
  idTurret::turretStates v6; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *str; // r5

  currentState = this->currentState;
  if ( this->randomFire )
  {
    if ( (unsigned int)currentState < TS_NORMAL )
      return 0;
  }
  else
  {
    if ( currentState == TS_DYING
      || currentState == TS_SILENCED
      || currentState == TS_DISABLED
      || currentState == TS_INACTIVE
      || currentState == TS_WARMUP )
    {
      if ( this->turningSound )
      {
        this->turningSound = false;
        idEntity::StopSound(this, channel: SND_CHANNEL_STEERING, peerMask: 0xFFu);
        idEntity::StopSound(this, channel: SND_CHANNEL_ENGINE_IDLE, peerMask: 0xFFu);
      }
      return 0;
    }
    if ( (unsigned __int8)idTurret::IsUpright(this) == 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      if ( this->lastPos.x != *v4 || this->lastPos.y != v4[1] || (v5 = 1, this->lastPos.z != v4[2]) )
        v5 = 0;
      if ( v5 == 0 )
      {
        v6 = this->currentState;
        if ( v6 == TS_NORMAL || v6 == TS_SEARCHING )
        {
          TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
          if ( TreeAnimatorFromPresentable != nullptr )
          {
            str = this->nonSearchMeshKit.str;
            if ( str != nullptr && *str != 0 )
              idTreeAnimator::HideKitsExcept(this: TreeAnimatorFromPresentable, kitType: MESH_KIT_HEADS, name: str);
            this->currentState = TS_WOBBLY;
          }
          this->stateTimer = 1000;
        }
        return 0;
      }
    }
  }
  return 1;
}


// ========================================================================
// ?CheckProjectileFire@idTurret@@AAA_NXZ
// EA  : 0x82CF6AD8
// RVA : 0x00CF6AD8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::CheckProjectileFire(idTurret *this)
{
  int num; // r11
  int v3; // r30
  idList<idEntityPtr<idProjectile>,5> *p_activeProjectiles; // r31
  int v5; // r29
  int value; // r9
  idProjectile *v7; // r3
  int v8; // r11
  int v9; // r11

  num = this->activeProjectiles.num;
  v3 = 0;
  if ( num > 0 )
  {
    p_activeProjectiles = &this->activeProjectiles;
    v5 = 0;
    do
    {
      value = p_activeProjectiles->list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = (idProjectile *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
        && idProjectile::CastTo(c: v7) != nullptr )
      {
        ++v3;
        ++v5;
      }
      else if ( v3 >= 0 )
      {
        v8 = p_activeProjectiles->num;
        if ( v3 < v8 )
        {
          v9 = v8 - 1;
          p_activeProjectiles->num = v9;
          if ( v3 != v9 )
            p_activeProjectiles->list[v5].spawnId.value = p_activeProjectiles->list[v9].spawnId.value;
        }
      }
      num = this->activeProjectiles.num;
    }
    while ( v3 < num );
  }
  return (((this->maxProjectiles ^ num) >= 0) + ((unsigned int)num >= this->maxProjectiles)) & 1;
}


// ========================================================================
// ?IsEverUsable@idTurret@@UBA_NPBVidEntity@@@Z
// EA  : 0x82CF6BC0
// RVA : 0x00CF6BC0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::IsEverUsable(idTurret *this, const idEntity *activator)
{
  int result; // r3
  bool v3; // zf

  if ( this->disassembleLoot.lootBoxes.num > 0 )
    return 1;
  v3 = idScriptObject::GetTypeDef(this: (bfx::Planner3D *)&this->inventoryCollection) == nullptr;
  result = 0;
  if ( !v3 )
    return 1;
  return result;
}


// ========================================================================
// ?Dropped@idTurret@@UAAXPAVidEntity@@PBVidDeclInventory@@@Z
// EA  : 0x82CF6C48
// RVA : 0x00CF6C48
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::Dropped(idTurret *this, idEntity *user, const idDeclInventory *idecl)
{
  idFaction *v5; // r3
  int GameMs; // r27
  const idAnimStack *v7; // r3
  const blendParms_t *v8; // r7
  __int64 v9; // r8
  int v10; // r5
  idMD6LeafPlay *LastPlayedLeaf; // r3
  blendParms_t v12[4]; // [sp+50h] [-50h] BYREF

  this->inventoryDecl = idecl;
  v5 = user->GetFaction(this: user);
  idFaction::SetDeclFaction(this: &this->faction, faction: v5->myFaction, clearRelationships: false);
  if ( this->dropAnimAlias.value != 0xFFFF )
  {
    blendParms_t::blendParms_t(this: v12);
    blendParms_t::SetDurationMS(this: v12, ms: 0x3E8u);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v7 = this->GetAnimStack_2(this);
    if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                            this: &this->channelAnimator,
                            stack: v7,
                            ah: &this->dropAnimAlias,
                            curTime: GameMs,
                            rateScale: 1.0,
                            blendParms: v8,
                            blendOutDurationMS_: v12,
                            leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                            a9: nullptr) != 0 )
    {
      LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
      if ( LastPlayedLeaf != nullptr )
        this->stateTimer = idMD6Leaf::GetLength(
                             this: LastPlayedLeaf,
                             ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                             a3: v10,
                             a4: v9);
    }
  }
  this->turretOwner = user;
}


// ========================================================================
// ?Use@idTurret@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CF6D50
// RVA : 0x00CF6D50
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::Use(idTurret *this, idPlayer *activator, const usableState_t usable)
{
  idPlayer *v6; // r25
  bool HasMaxCurBaseHealth; // r28
  const idFaction *v8; // r3
  idPresentable *presentable; // r3
  const idAngles *v10; // r4
  idVec3 *ViewAngles; // r3
  idAngles v13; // [sp+50h] [-90h] BYREF
  char v14; // [sp+60h] [-80h] BYREF
  float v15; // [sp+78h] [-68h]
  float v16; // [sp+7Ch] [-64h]

  v6 = idPlayer::CastTo(c: activator);
  if ( v6 == nullptr )
    return 0;
  HasMaxCurBaseHealth = idBaseHealth::HasMaxCurBaseHealth(this: &this->turretHealth.idHealthT<enum simpleHealthComponent_t,1,0>);
  v8 = activator->GetFaction(this: activator);
  if ( idFaction::GetAttitudeTowards(this: &this->faction, otherFaction: v8) < ATTITUDE_NEUTRAL )
  {
    v15 = 0.0;
    v16 = 0.0;
    this->turretHealth.components[0].type = SIMPLE_HEALTH_HITPOINTS;
    this->turretHealth.components[0].cur = 0.0;
    HasMaxCurBaseHealth = false;
    this->turretHealth.components[0].max = 0.0;
    this->turretHealth.killThreshold = 0.0;
    this->turretHealth.killingBlowDamage = 0.0;
    this->turretHealth.accumulatedDamageFrame = -1;
    this->turretHealth.accumulatedFrameDamage = 0.0;
    this->turretHealth.isDead = false;
  }
  if ( usable == USABLE_DISASSEMBLE )
    idPlayer::Disassemble(this: v6, loot: &this->disassembleLoot, ent: this);
  v15 = 0.0;
  v16 = 0.0;
  this->turretHealth.components[0].type = SIMPLE_HEALTH_HITPOINTS;
  this->turretHealth.components[0].cur = 0.0;
  this->turretHealth.components[0].max = v15;
  this->turretHealth.killThreshold = 0.0;
  this->turretHealth.killingBlowDamage = 0.0;
  this->turretHealth.accumulatedDamageFrame = -1;
  this->turretHealth.accumulatedFrameDamage = 0.0;
  this->turretHealth.isDead = false;
  if ( HasMaxCurBaseHealth || !this->StartRagdoll(this) )
  {
    idAnimator_JointMod::ClearJointMods(this: &this->jointModAnimator);
    if ( !this->dontRemoveAfterDying )
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 5);
    return 1;
  }
  else
  {
    presentable = v6->presentable;
    if ( presentable != nullptr )
      v10 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v10 = nullptr;
    ViewAngles = (idVec3 *)idPresentablePlayer::GetViewAngles(
                             this: (idPresentablePlayer *)&v14,
                             result: v10,
                             includeWeaponKick: true);
    idAngles::ToForward(this: &v13, result: ViewAngles);
    idVec3::NormalizeFast(this: (idVec3 *)&v13);
    if ( this->afProperties.articulatedFigure != nullptr )
      idAnimator_AF::UnattachBones(this: &this->afProperties, dir: (const idVec3 *)&v13);
    if ( !this->dontRemoveAfterDying )
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 3000);
    idEntity::BecomeInactive(this, flags: 1);
    return 1;
  }
}


// ========================================================================
// ?DormantBegin@idTurret@@UAAXXZ
// EA  : 0x82CF6F60
// RVA : 0x00CF6F60
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::DormantBegin(idTurret *this)
{
  int v2; // r4
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r9
  int i; // r11

  idEntity::DormantBegin(this);
  this->enemy.spawnId.value = 0x1FFF;
  v2 = 0;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num > 0 )
  {
    for ( i = 0;
          p_aiWorldStateUsers->list[i].spawnId.value != ((gameLocal->spawnIds.ptr[this->entityNumber] << 13)
                                                       | this->entityNumber);
          ++i )
    {
      if ( ++v2 >= num )
        return;
    }
    if ( v2 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_aiWorldStateUsers, index: v2);
  }
}


// ========================================================================
// ?UpdateWeaponState@idTurret@@AAAX_N@Z
// EA  : 0x82CF7010
// RVA : 0x00CF7010
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::UpdateWeaponState(idTurret *this, bool shouldShowLaser)
{
  idWeapon *turretWeapon; // r3
  idPresentableWeapon *PresentableWeapon; // r3
  idTurret::turretStates currentState; // r11
  const idMaterial *laserBeamMtrHostile; // r11
  const idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idWeapon *v8; // r3
  double v9; // fp8
  int entityNumber; // r6
  double v11; // fp3
  idRenderWorld *v12; // r3
  idVec3 v13; // [sp+50h] [-90h] BYREF
  float v14; // [sp+60h] [-80h] BYREF
  float v15; // [sp+64h] [-7Ch]
  float v16; // [sp+68h] [-78h]
  float v17[4]; // [sp+70h] [-70h] BYREF
  float v18[4]; // [sp+80h] [-60h] BYREF
  idMat3 v19; // [sp+90h] [-50h] BYREF

  if ( this->turretWeapon != nullptr
    && shouldShowLaser
    && idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    turretWeapon = this->turretWeapon;
    if ( (*((_BYTE *)turretWeapon + 452) & 2) != 0 )
    {
      PresentableWeapon = idWeapon::GetPresentableWeapon(this: turretWeapon);
      currentState = this->currentState;
      if ( currentState == TS_SUPPRESSING_FIRE || currentState == TS_NORMAL )
        laserBeamMtrHostile = this->laserBeamMtrHostile;
      else
        laserBeamMtrHostile = this->laserBeamMtrSearch;
      if ( PresentableWeapon != nullptr && laserBeamMtrHostile != nullptr )
        PresentableWeapon->laserSight.laserBeam.material = laserBeamMtrHostile;
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      if ( idWeapon::GetLaserSightWorldTransform(
             this: this->turretWeapon,
             ta: TreeAnimatorFromPresentable,
             origin: &v13,
             axis: &v19) )
      {
        v8 = this->turretWeapon;
        v9 = (float)(v19.mat[0].z * this->maxRange);
        entityNumber = this->entityNumber;
        v11 = (float)(v13.y + (float)(v19.mat[0].y * this->maxRange));
        v14 = v13.x + (float)(v19.mat[0].x * this->maxRange);
        v15 = v11;
        v16 = v13.z + (float)v9;
        v8->UpdateLaserSight(this: v8, a2: &v13, a3: (const idVec3 *)&v14, a4: entityNumber, a5: nullptr);
        if ( g_debugLaserSight.valueInteger != 0 )
        {
          v17[0] = v14;
          v17[1] = v15;
          v17[2] = v16;
          v17[3] = 1.0;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idSphere *)v17,
            a4: 12,
            a5: 0,
            a6: false);
          v18[3] = 1.0;
          v18[0] = v13.x;
          v18[1] = v13.y;
          v18[2] = v13.z;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorCyan,
            a3: (const idSphere *)v18,
            a4: 12,
            a5: 0,
            a6: false);
          v12 = common->RW(this: common);
          v12->DebugLine(
            this: v12,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: &v13,
            a4: (const idVec3 *)&v14,
            a5: 0,
            a6: true);
        }
      }
    }
  }
}


// ========================================================================
// ?SetDying@idTurret@@AAAXPBVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PBUtrace_t@@@Z
// EA  : 0x82CF7240
// RVA : 0x00CF7240
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::SetDying(
        idTurret *this,
        const idEntity *inflictor,
        const idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        const trace_t *trace,
        int a8)
{
  unsigned int v14; // r4
  char v15; // r10
  const idSoundShader *soundHaywire; // r5
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *str; // r5
  idPresentable *presentable; // r11
  idPhysics *Physics; // r3
  idPhysics *v21; // r3
  idPhysics *v22; // r29
  idPresentable *v23; // r30
  int v24; // r3
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int v28; // r7
  int v29; // r6
  int v30; // r5
  int value; // r9
  idEntity *v32; // r3
  int v33; // r9
  idEntity *v34; // r3
  idEntity *v35; // r3
  int v36; // r9
  idEntity *v37; // r3
  idEntity *v38; // r3
  int GameMs; // r30
  const idAnimStack *v40; // r3
  const blendParms_t *v41; // r7
  int v42; // r20
  const idAnimStack *v43; // r3
  int v44; // r30
  const idAnimStack *v45; // r3
  __int64 v46; // r8
  idTurret::turretStates currentState; // r11
  int v48; // r30
  const idAnimStack *v49; // r3
  const blendParms_t *v50; // r7
  idTreeAnimator *v51; // r3
  const char *v52; // r5
  int v53; // r4
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r10
  int v56; // r11
  int v57; // r5
  int v58; // r28
  int v59; // r29
  int v60; // r9
  idEntity *v61; // r3
  idEntity *v62; // r30
  idEventArg *v63; // r3
  idPlayer *DebugPlayer; // r3
  _BYTE v65[16]; // [sp+60h] [-C0h] BYREF
  _BYTE v66[16]; // [sp+70h] [-B0h] BYREF
  blendParms_t v67; // [sp+80h] [-A0h] BYREF

  if ( this->randomFire )
  {
    presentable = this->presentable;
    this->randomFire = false;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->StopAllFX(this: presentable);
  }
  else if ( !this->turretHealth.IsDead_Impl(this: &this->turretHealth) )
  {
    v14 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v14;
    v15 = (((this->haywireOnKnockdownChance ^ (((v14 >> 10) & 0x7FFF) % 0x64)) & 0x80000000) == 0)
        + (((v14 >> 10) & 0x7FFF) % 0x64 >= this->haywireOnKnockdownChance);
    this->randomFire = v15 & 1;
    if ( (v15 & 1) != 0 )
    {
      soundHaywire = this->soundHaywire;
      this->stateTimer = this->haywireTime;
      if ( soundHaywire != nullptr )
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_ITEM,
          shader: soundHaywire,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0xFFu);
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        str = this->nonSearchMeshKit.str;
        if ( str != nullptr && *str != 0 )
          idTreeAnimator::HideKitsExcept(this: TreeAnimatorFromPresentable, kitType: MESH_KIT_HEADS, name: str);
        this->currentState = TS_HAYWIRE;
      }
      return;
    }
  }
  this->stateTimer = this->dyingTime;
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  v21 = idEntity::GetPhysics(this);
  v21->SetClipMask(this: v21, a2: 1, a3: -1);
  v22 = idEntity::GetPhysics(this);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v23 = this->presentable;
  v24 = v22->GetContents(this: v22, a2: -1);
  idPresentable::SetClipModelContents(this: v23, newContents: v24, a3: v30, a4: v29, a5: v28, a6: v27, a7: v26, a8: v25);
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_WEAPON_AMBIENT,
    shader: this->soundDying,
    soundShaderFlags: SSF_PLAY_ONCE,
    peerMask: 0xFFu);
  if ( this->idleSoundPlaying )
  {
    this->idleSoundPlaying = false;
    idEntity::StopSound(this, channel: SND_CHANNEL_AMBIENT, peerMask: 0xFFu);
  }
  if ( this->destroyedModel != nullptr )
  {
    value = this->flare.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v32 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v32 != nullptr && idEntity::CastTo(c: v32) != nullptr )
      {
        v33 = this->flare.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v33 & 0x1FFF] == v33 >> 13
          && (v34 = gameLocal->entities.ptr[v33 & 0x1FFF]) != nullptr )
        {
          v35 = idEntity::CastTo(c: v34);
        }
        else
        {
          v35 = nullptr;
        }
        idEntity::Unbind(this: v35);
        v36 = this->flare.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v36 & 0x1FFF] == v36 >> 13
          && (v37 = gameLocal->entities.ptr[v36 & 0x1FFF]) != nullptr )
        {
          v38 = idEntity::CastTo(c: v37);
        }
        else
        {
          v38 = nullptr;
        }
        idEventReceiver::PostEventMS(this: v38, ev: &EV_Remove, time: 0);
        this->flare.spawnId.value = 0x1FFF;
      }
    }
    this->SetModel(this, a2: this->destroyedModel);
  }
  else if ( !this->StartRagdoll(this) && idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    blendParms_t::blendParms_t(this: &v67);
    if ( this->afProperties.articulatedFigure != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v40 = this->GetAnimStack_2(this);
      idAnimator_Channel::PlayAnim(
        this: &this->channelAnimator,
        stack: v40,
        ah: &this->breakAnimAlias,
        curTime: GameMs,
        rateScale: 1.0,
        blendParms: v41,
        blendOutDurationMS_: &v67,
        leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
        a9: nullptr);
    }
    else if ( !this->invertedTurret )
    {
      if ( this->destroyedMhAnimAlias.value == 0xFFFF )
      {
        currentState = this->currentState;
        if ( currentState == TS_INACTIVE || currentState == TS_DISABLED )
        {
          this->stopThinkTime = 1;
        }
        else
        {
          v48 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v49 = this->GetAnimStack_2(this);
          idAnimator_Channel::PlayAnim(
            this: &this->channelAnimator,
            stack: v49,
            ah: &this->lostTargetAnimAlias,
            curTime: v48,
            rateScale: 1.0,
            blendParms: v50,
            blendOutDurationMS_: &v67,
            leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
            a9: nullptr);
          idAnimator_Channel::ClearAnimator(this: &this->movingHoldAnimator);
        }
      }
      else
      {
        v42 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v43 = this->GetAnimStack_2(this);
        idAnimator_Channel::PlayAnim(
          this: &this->channelAnimator,
          stack: v43,
          ah: &this->destroyedAnimAlias,
          curTime: v42,
          rateScale: 1.0,
          blendParms: (const blendParms_t *)0x82000000,
          blendOutDurationMS_: &v67,
          leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
          a9: nullptr);
        v44 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v45 = this->GetAnimStack_2(this);
        LODWORD(v46) = &v67;
        idAnimator_Channel::CycleAnim(
          this: &this->movingHoldAnimator,
          stack: v45,
          ah: &this->destroyedMhAnimAlias,
          curTime: v44,
          rateScale: 1.0,
          leafStarted: v46,
          a7: nullptr);
      }
    }
  }
  v51 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( v51 != nullptr )
  {
    v52 = this->nonSearchMeshKit.str;
    if ( v52 != nullptr && *v52 != 0 )
      idTreeAnimator::HideKitsExcept(this: v51, kitType: MESH_KIT_HEADS, name: v52);
    this->currentState = TS_DYING;
  }
  v53 = 0;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num > 0 )
  {
    v56 = 0;
    while ( p_aiWorldStateUsers->list[v56].spawnId.value != ((gameLocal->spawnIds.ptr[this->entityNumber] << 13)
                                                           | this->entityNumber) )
    {
      ++v53;
      ++v56;
      if ( v53 >= num )
        goto LABEL_55;
    }
    if ( v53 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_aiWorldStateUsers, index: v53);
  }
LABEL_55:
  if ( damageDef != nullptr
    && ((unsigned __int8 (__fastcall *)(idTurret *, const idEntity *, const idEntity *, const idDeclDamage *, double))this->CalcDamageImpulse)(
         a1: this,
         a2: inflictor,
         a3: attacker,
         a4: damageDef,
         a5: damageScale) != 0 )
  {
    if ( a8 != 0 )
      v57 = *(_DWORD *)(a8 + 116);
    else
      v57 = 0;
    this->ApplyImpulseFromEntity(this, a2: inflictor, a3: v57, a4: (const idVec3 *)v66, a5: (const idVec3 *)v65);
  }
  v58 = 0;
  if ( this->triggerOnDestroy.num > 0 )
  {
    v59 = 0;
    do
    {
      v60 = this->triggerOnDestroy.list[v59].spawnId.value;
      if ( gameLocal->spawnIds.ptr[v60 & 0x1FFF] == v60 >> 13 )
      {
        v61 = gameLocal->entities.ptr[v60 & 0x1FFF];
        if ( v61 != nullptr )
        {
          v62 = idEntity::CastTo(c: v61);
          if ( v62 != nullptr )
          {
            v63 = idEventArg::idEventArg(this: (idEventArg *)&v67, data: this);
            idEventReceiver::PostEventMS(
              this: v62,
              ev: &EV_Activate,
              time: *(_DWORD *)&v63->type,
              arg1: (const idEventArg *)LODWORD(v63->value.v[1]));
          }
        }
      }
      ++v58;
      ++v59;
    }
    while ( v58 < this->triggerOnDestroy.num );
  }
  if ( this->saveDestroyedState )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( DebugPlayer != nullptr )
      idGameLayerManager::AddItemMemory(this: &DebugPlayer->gameLayerManager, itemName: this->name.data);
  }
}


// ========================================================================
// ?AnimEvent_TurretFire@idTurret@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82CF7990
// RVA : 0x00CF7990
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

idTurret *__fastcall idTurret::AnimEvent_TurretFire(
        idTurret *this,
        idTurret *result,
        const idMD6Anim *animHandle,
        const char *tagName)
{
  idFinishFireResults *v6; // r11
  int i; // ctr
  idTurret::turretStates currentState; // r9
  double x; // fp0
  double y; // fp13
  double z; // fp12
  int value; // r9
  idEntity *v13; // r3
  idEntity *v14; // r4
  idAIEntityState *v15; // r3
  int v16; // r9
  idAIEntityState *v17; // r28
  idEntity *v18; // r3
  idEntity *v19; // r4
  idEntity *Entity; // r3
  idEntity *v21; // r3
  idPresentablePtr<idPresentable> *presentable; // r11
  idEntity *v23; // r29
  idPlayer *Player; // r3
  const idFaction *v25; // r3
  int v26; // r4
  bool (__fastcall *Damage_Impl)(struct idSimpleHealth *, const float, const bool, float *); // r8
  idPresentable *v28; // r29
  const idMat3 *v29; // r28
  const idPresentable *v30; // r3
  idEntity *v31; // r3
  idEntity *v32; // r29
  const idPresentable *v33; // r29
  idPresentable *v34; // r4
  idPresentable *v35; // r29
  const idMat3 *v36; // r28
  const idPresentable *v37; // r3
  idEntity *v38; // r3
  idEntity *v39; // r29
  idFXManager *v41; // [sp+8h] [-B58h]
  bool v42; // [sp+Fh] [-B51h]
  idPresentablePtr<idPresentable> v43[2]; // [sp+60h] [-B00h] BYREF
  idVec3 v44; // [sp+68h] [-AF8h] BYREF
  idVec3 v45; // [sp+78h] [-AE8h] BYREF
  idVec3 *p_suppressionFirePoint; // [sp+84h] [-ADCh]
  float v47; // [sp+88h] [-AD8h] BYREF
  idMat3 v48; // [sp+90h] [-AD0h] BYREF
  float v49; // [sp+B4h] [-AACh]
  float v50; // [sp+B8h] [-AA8h]
  idMat3 v51; // [sp+C0h] [-AA0h] BYREF
  idFireParms v52; // [sp+F0h] [-A70h] BYREF
  idFinishFireResults v53; // [sp+190h] [-9D0h] BYREF
  idVec3 v54[4]; // [sp+1E0h] [-980h] BYREF
  idTestFireResults v55; // [sp+210h] [-950h] BYREF

  if ( result->turretWeapon != nullptr )
  {
    idAnimatedEntity::GetTagPosition(
      this: result,
      propName: idPropInfo::INFO_PROP_NAME,
      tagName,
      origin: &v44,
      axis: &v51);
    idFireParms::idFireParms(this: &v52);
    memset(&v55, 0, sizeof(v55));
    v6 = &v53;
    v53.numProjectiles = 0;
    for ( i = 16; i != 0; --i )
    {
      v6 = (idFinishFireResults *)((char *)v6 + 4);
      v6->numProjectiles = 0;
    }
    currentState = result->currentState;
    *((_BYTE *)&v52 + 128) |= 0x20u;
    v52.addSpread = 1.0;
    if ( currentState == TS_SUPPRESSING_FIRE )
    {
      x = result->suppressionFirePoint.x;
      y = result->suppressionFirePoint.y;
      v43[0].spawnId = 0;
      z = result->suppressionFirePoint.z;
      p_suppressionFirePoint = &result->suppressionFirePoint;
      v45.x = x;
      v45.y = y;
      v45.z = z;
    }
    else
    {
      value = result->enemy.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v14 = idEntity::CastTo(c: v13);
      }
      else
      {
        v14 = nullptr;
      }
      v15 = idAIWorldState::StateForEntity(this: &result->worldState, ent: v14);
      v16 = result->enemy.spawnId.value;
      v17 = v15;
      if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
        && (v18 = gameLocal->entities.ptr[v16 & 0x1FFF]) != nullptr )
      {
        v19 = idEntity::CastTo(c: v18);
      }
      else
      {
        v19 = nullptr;
      }
      idAIWorldState::StateForEntity(this: &result->worldState, ent: v19);
      if ( v17 == nullptr )
        goto LABEL_52;
      idAIEntityState::GetAimPoint(this: v17, sense: AISENSE_SIGHT, aimPoint: AIMPOINT_BEST, point: &v45);
      Entity = idAIEntityState::GetEntity(this: v17);
      if ( Entity != nullptr )
      {
        p_suppressionFirePoint = (idVec3 *)Entity->entityNumber;
        result->lastTarget.spawnId.value = (*((_DWORD *)&gameLocal->__vftable + (_DWORD)p_suppressionFirePoint + 29755) << 13)
                                         | (unsigned int)p_suppressionFirePoint;
      }
      else
      {
        result->lastTarget.spawnId.value = 0x1FFF;
      }
      v21 = idAIEntityState::GetEntity(this: v17);
      presentable = (idPresentablePtr<idPresentable> *)v21->presentable;
      v23 = v21;
      if ( presentable != nullptr
        || (idEntity::InitPresentableInternal(this: v21),
            (presentable = (idPresentablePtr<idPresentable> *)v23->presentable) != nullptr) )
      {
        v43[0] = presentable[275];
      }
      else
      {
        v43[0].spawnId = 0;
      }
    }
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    v25 = Player->GetFaction(this: Player);
    if ( idFaction::GetAttitudeTowards(this: &result->faction, otherFaction: v25) > ATTITUDE_NEUTRAL )
    {
      Damage_Impl = result->turretHealth.Damage_Impl;
      v47 = -0.0;
      ((void (__fastcall *)(idSimpleHealth *, int, int, float *, double))Damage_Impl)(
        a1: &result->turretHealth,
        a2: v26,
        a3: 1,
        a4: &v47,
        a5: 0.050000001);
      if ( result->turretHealth.IsDead_Impl(this: &result->turretHealth) && result->currentState != TS_DYING )
      {
        v50 = v51.mat[0].z * (float)-1.0;
        v49 = v51.mat[0].y * (float)-1.0;
        v48.mat[2].z = v51.mat[0].x * (float)-1.0;
        idTurret::SetDying(
          this: result,
          inflictor: result,
          attacker: result,
          damageDef: gameLocal->damageDecl,
          damageScale: 1.0,
          dir: (const idVec3 *)0x1AAB50,
          trace: (const trace_t *)&v48.mat[2].z,
          a8: 0);
      }
    }
    if ( idWeapon::GetCurrentProjectileDecl(this: result->turretWeapon, secondaryAmmo: false)->hitscan )
    {
      v48.mat[1].y = v45.x - v44.x;
      v48.mat[2].x = v45.z - v44.z;
      v48.mat[1].z = v45.y - v44.y;
      idVec3::NormalizeFast(this: (idVec3 *)&v48.mat[1].y);
      if ( turret_useDeferredFiring.valueInteger != 0 )
      {
        v28 = result->presentable;
        if ( v28 == nullptr )
        {
          idEntity::InitPresentableInternal(this: result);
          v28 = result->presentable;
        }
        v29 = idVec3::ToMat3(this: v54, result: (idMat3 *)&v48.mat[1].y);
        v30 = idPresentablePtr<idPresentableProjectile>::operator->(this: v43);
        idWeapon::DeferredFire(
          this: result->turretWeapon,
          attacker: v28,
          target: v30,
          start: &v44,
          fireAxis: v29,
          fp: &v52,
          secondaryAmmo: false);
        goto LABEL_52;
      }
      if ( result->presentable == nullptr )
        idEntity::InitPresentableInternal(this: result);
      v31 = idEntityPtr<idEntity const>::operator->(this: &result->lastTarget);
      v32 = v31;
      if ( v31->presentable != nullptr )
      {
        v33 = v31->presentable;
      }
      else
      {
        idEntity::InitPresentableInternal(this: v31);
        v33 = v32->presentable;
      }
      v34 = result->presentable;
      if ( v34 == nullptr )
      {
        idEntity::InitPresentableInternal(this: result);
        v34 = result->presentable;
      }
    }
    else
    {
      if ( (unsigned __int8)idTurret::CheckProjectileFire(this: result) == 0 )
      {
LABEL_52:
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v52.targetList);
        return this;
      }
      v48.mat[0].x = v45.x - v44.x;
      v48.mat[0].z = v45.z - v44.z;
      v48.mat[0].y = v45.y - v44.y;
      idVec3::NormalizeFast(this: v48.mat);
      if ( turret_useDeferredFiring.valueInteger != 0 )
      {
        v35 = result->presentable;
        if ( v35 == nullptr )
        {
          idEntity::InitPresentableInternal(this: result);
          v35 = result->presentable;
        }
        v36 = idVec3::ToMat3(this: v54, result: &v48);
        v37 = idPresentablePtr<idPresentableProjectile>::operator->(this: v43);
        idWeapon::DeferredFire(
          this: result->turretWeapon,
          attacker: v35,
          target: v37,
          start: &v44,
          fireAxis: v36,
          fp: &v52,
          secondaryAmmo: false);
        goto LABEL_52;
      }
      if ( result->presentable == nullptr )
        idEntity::InitPresentableInternal(this: result);
      v38 = idEntityPtr<idEntity const>::operator->(this: &result->lastTarget);
      v39 = v38;
      if ( v38->presentable != nullptr )
      {
        v33 = v38->presentable;
      }
      else
      {
        idEntity::InitPresentableInternal(this: v38);
        v33 = v39->presentable;
      }
      v34 = result->presentable;
      if ( v34 == nullptr )
      {
        idEntity::InitPresentableInternal(this: result);
        v34 = result->presentable;
      }
    }
    idWeapon::Fire(
      this: result->turretWeapon,
      attacker: v34,
      target: v33,
      start: &v44,
      fireAxis: &v51,
      fp: &v52,
      tfr: &v55,
      ffr: &v53,
      fxMgr: v41,
      secondaryAmmo: v42);
    goto LABEL_52;
  }
  return this;
}


// ========================================================================
// __unwind$501441
// EA  : 0x82CF7F54
// RVA : 0x00CF7F54
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_501441()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2912 + 240));
}


// ========================================================================
// ?SetPath@idRailTurret@@QAAXPAVidSplinePath@@@Z
// EA  : 0x82CF7F80
// RVA : 0x00CF7F80
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idRailTurret::SetPath(idRailTurret *this, idSplinePath *path)
{
  idCurve_Spline<idVec3> *v4; // r3
  __int64 v5; // r8
  int GameMs; // r3
  idCurve_Spline<idVec3> *currentSpline; // r9
  int v8; // r11
  int v9; // r10
  double v10; // fp0
  float *v11; // r8

  if ( path != nullptr )
  {
    v4 = idSplinePath::AllocSpline(this: path);
    this->currentSpline = v4;
    idCurve<idVec3>::MakeUniformMoveSpeed(this: v4, moveSpeed: this->trackSpeed);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    currentSpline = this->currentSpline;
    v8 = 0;
    if ( currentSpline->times.num > 0 )
    {
      LODWORD(v5) = GameMs;
      v9 = 0;
      v10 = (float)v5;
      do
      {
        ++v8;
        v11 = &currentSpline->times.list[v9++];
        *v11 = *v11 + (float)v10;
      }
      while ( v8 < currentSpline->times.num );
    }
    currentSpline->changed = true;
  }
  else
  {
    this->currentSpline = nullptr;
  }
  if ( path != nullptr )
    this->currentSplinePath.spawnId.value = (gameLocal->spawnIds.ptr[path->entityNumber] << 13) | path->entityNumber;
  else
    this->currentSplinePath.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?OnActivate@idRailTurret@@EAAXPAVidEntity@@@Z
// EA  : 0x82CF8088
// RVA : 0x00CF8088
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idRailTurret::OnActivate(idRailTurret *this, idEntity *activator)
{
  int v3; // r9
  idSplinePath *v4; // r3
  idSplinePath *v5; // r4
  int value; // r10

  if ( this->plannedPath.num <= 0 )
  {
    value = this->startTrack.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v4 = (idSplinePath *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v4 != nullptr )
        goto LABEL_4;
    }
LABEL_7:
    v5 = nullptr;
    goto LABEL_8;
  }
  v3 = this->plannedPath.list->spawnId.value;
  if ( gameLocal->spawnIds.ptr[v3 & 0x1FFF] != v3 >> 13 )
    goto LABEL_7;
  v4 = (idSplinePath *)gameLocal->entities.ptr[v3 & 0x1FFF];
  if ( v4 == nullptr )
    goto LABEL_7;
LABEL_4:
  v5 = idSplinePath::CastTo(c: v4);
LABEL_8:
  idRailTurret::SetPath(this, path: v5);
  this->Show(this);
}


// ========================================================================
// ?OnActivate@idTurret@@EAAXPAVidEntity@@@Z
// EA  : 0x82CF8170
// RVA : 0x00CF8170
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::OnActivate(idTurret *this, idPlayer *activator)
{
  const idVec3 *v4; // r7
  idPhysics *Physics; // r3
  __int64 v6; // r9
  unsigned int v7; // r28
  unsigned int v8; // r6
  double v9; // fp8
  idTurret_vtbl *v10; // r29
  int v11; // r3
  idTurret_vtbl *v12; // r9
  idAnimStack *v13; // r3
  idTurret::turretStates currentState; // r11
  int i; // r29
  idEntity *Target; // r30
  idEventArg *v17; // r3
  int regimeGridTime; // r11
  int GameMs; // r29
  const idAnimStack *v20; // r3
  const blendParms_t *v21; // r7
  __int64 v22; // r8
  int v23; // r5
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idTurret::turretStates v25; // r10
  int v26; // r29
  const idAnimStack *v27; // r3
  const blendParms_t *v28; // r7
  __int64 v29; // r8
  int v30; // r5
  idMD6LeafPlay *v31; // r3
  int stateTimer; // r30
  int Length; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *str; // r5
  float v36[6]; // [sp+58h] [-58h] BYREF
  idEventArg v37[3]; // [sp+70h] [-40h] BYREF

  if ( (unsigned __int8)idRegimeTile::IsTypeOf(c: activator) == 0
    && (unsigned __int8)idTurret::IsTypeOf(c: activator) == 0 )
  {
    if ( (unsigned __int8)idBreakable::IsTypeOf(c: activator) != 0
      || (unsigned __int8)idDamageableEntity::IsTypeOf(c: activator) != 0 )
    {
      idTurret::SetDying(
        this,
        inflictor: nullptr,
        attacker: nullptr,
        damageDef: nullptr,
        damageScale: 0.0,
        dir: v4,
        trace: (const trace_t *)&vec3_origin,
        a8: 0);
      Physics = idEntity::GetPhysics(this);
      HIDWORD(v6) = &ai_useTurnTransitions.valueString.baseBuffer[12];
      v7 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v7 + 1013904223;
      LODWORD(v6) = ((v7 + 1013904223) >> 10) & 0x7FFF;
      v8 = 1664525 * clientGame->random.seed;
      v9 = (float)v6;
      HIDWORD(v6) = v6;
      clientGame->random.seed = v8 + 1013904223;
      v36[2] = 100.0;
      v10 = this->__vftable;
      LODWORD(v6) = ((v8 + 1013904223) >> 10) & 0x7FFF;
      v36[1] = (float)((float)((float)v9 * (float)0.000061037019) - (float)1.0) * (float)10.0;
      v36[0] = (float)((float)((float)v6 * (float)0.000061037019) - (float)1.0) * (float)10.0;
      v11 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v10->ApplyImpulseFromEntity(this, a2: activator, a3: 0, a4: (const idVec3 *)v11, a5: (const idVec3 *)v36);
      idEntity::BecomeActive(this, flags: 2);
      return;
    }
    if ( (unsigned __int8)idPlayer::IsTypeOf(c: activator) != 0
      && idFaction::GetAttitudeTowards(this: &this->faction, otherEnt: activator) < ATTITUDE_NEUTRAL )
    {
      if ( this->startOff )
        this->startOff = false;
      return;
    }
LABEL_26:
    idTurret::SetState(this, state: TS_DISABLED);
    return;
  }
  if ( this->startOff )
  {
    this->startOff = false;
    idTurret::SetState(this, state: TS_DISABLED);
    v12 = this->__vftable;
    this->stopThinkTime = 1;
    v13 = v12->GetAnimStack_2(this);
    idAnimator_Base::Shutdown(this: &this->channelAnimator, stack: v13);
    return;
  }
  if ( this->regimeGridTime != 0 )
  {
    currentState = this->currentState;
    if ( currentState != TS_SILENCED && currentState != TS_DISABLED )
    {
      for ( i = 0; i < this->targets.num; ++i )
      {
        Target = idEntity::GetTarget(this, i);
        if ( Target != nullptr )
        {
          v17 = idEventArg::idEventArg(this: v37, data: this);
          idEventReceiver::PostEventMS(
            this: Target,
            ev: &EV_Activate,
            time: *(_DWORD *)&v17->type,
            arg1: (const idEventArg *)LODWORD(v17->value.v[1]));
        }
      }
      regimeGridTime = this->regimeGridTime;
      if ( regimeGridTime == -1 )
      {
        if ( this->currentState == TS_NORMAL
          && idEntityPtr<idEntity const>::operator->(this: &this->lastTarget) != nullptr )
        {
          blendParms_t::blendParms_t(this: (blendParms_t *)v37);
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v20 = this->GetAnimStack_2(this);
          if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                                  this: &this->channelAnimator,
                                  stack: v20,
                                  ah: &this->lostTargetAnimAlias,
                                  curTime: GameMs,
                                  rateScale: 1.0,
                                  blendParms: v21,
                                  blendOutDurationMS_: (blendParms_t *)v37,
                                  leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                                  a9: nullptr) != 0 )
          {
            LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
            if ( LastPlayedLeaf != nullptr )
              this->stopThinkTime = idMD6Leaf::GetLength(
                                      this: LastPlayedLeaf,
                                      ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                                      a3: v23,
                                      a4: v22);
            idAnimator_Channel::ClearAnimator(this: &this->movingHoldAnimator);
          }
        }
        goto LABEL_26;
      }
      v25 = this->currentState;
      this->stateTimer = regimeGridTime;
      if ( v25 == TS_NORMAL && idEntityPtr<idEntity const>::operator->(this: &this->lastTarget) != nullptr )
      {
        blendParms_t::blendParms_t(this: (blendParms_t *)v37);
        v26 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v27 = this->GetAnimStack_2(this);
        if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                                this: &this->channelAnimator,
                                stack: v27,
                                ah: &this->lostTargetAnimAlias,
                                curTime: v26,
                                rateScale: 1.0,
                                blendParms: v28,
                                blendOutDurationMS_: (blendParms_t *)v37,
                                leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                                a9: nullptr) != 0 )
        {
          v31 = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
          if ( v31 != nullptr )
          {
            stateTimer = this->stateTimer;
            Length = idMD6Leaf::GetLength(
                       this: v31,
                       ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                       a3: v30,
                       a4: v29);
            if ( Length <= stateTimer )
              Length = stateTimer;
            this->stateTimer = Length;
          }
          idAnimator_Channel::ClearAnimator(this: &this->movingHoldAnimator);
        }
      }
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        str = this->nonSearchMeshKit.str;
        if ( str != nullptr && *str != 0 )
          idTreeAnimator::HideKitsExcept(this: TreeAnimatorFromPresentable, kitType: MESH_KIT_HEADS, name: str);
        this->currentState = TS_SILENCED;
      }
    }
  }
}


// ========================================================================
// ?Damage@idTurret@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CF8628
// RVA : 0x00CF8628
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

float __fastcall idTurret::Damage(
        idTurret *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        int a8)
{
  double v15; // fp30
  int v16; // r11
  idDamageGroup *DamageGroup; // r30
  char v18; // r28
  idTurret::turretStates currentState; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *str; // r5
  BOOL canGoInactive; // r11
  int GameMs; // r30
  const idAnimStack *v24; // r3
  __int64 v25; // r8
  int v26; // r29
  const idAnimStack *v27; // r3
  const blendParms_t *v28; // r7
  __int64 v29; // r8
  int v30; // r5
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idPhysics *Physics; // r3
  float *v33; // r3
  idTreeAnimator *v34; // r3
  const char *v35; // r5
  int value; // r9
  idGameLocal *v37; // r11
  idEntity *v38; // r3
  char v39; // r10
  idTurret::turretStates v40; // r11
  idTreeAnimator *v41; // r3
  const char *v42; // r5
  int v43; // r10
  int v44; // r28
  const idAnimStack *v45; // r3
  const blendParms_t *v46; // r7
  __int64 v47; // r8
  int v48; // r5
  idMD6LeafPlay *v49; // r3
  int Length; // r3
  int stateTimer; // r11
  int timeToBeSilenced; // r11
  int v53; // r5
  int v54; // r4
  int knockBack; // r30
  double v56; // fp13
  double v57; // fp12
  idPhysics *v58; // r3
  float *v59; // r3
  __int64 v60; // r11
  idAnimator_AF *v61; // r3
  char v62; // r11
  double v63; // fp9
  double v64; // fp8
  double v65; // fp13
  double fraction; // fp12
  idPhysics *v67; // r3
  double v68; // fp1
  int v69; // r5
  const idVec3 *v70; // r7
  idPhysics *v71; // r3
  idPhysics *v72; // r3
  int v73; // r3
  float v74; // r7
  float v75; // r6
  idPhysics *v76; // r3
  int v77; // r3
  char *v78; // r10
  _DWORD *v79; // r11
  int i; // ctr
  __int64 v81; // r9
  unsigned int v82; // r5
  double v83; // fp31
  int GameMsPerFrame; // r30
  int v85; // r29
  const idDeclParticle *ondestroyedParticle; // r28
  idRenderModelEffects *MergeBranch; // r3
  double v88; // fp1
  int v90; // [sp+8h] [-198h]
  int v91; // [sp+Ch] [-194h]
  int v92; // [sp+10h] [-190h]
  int v93; // [sp+14h] [-18Ch]
  int v94; // [sp+18h] [-188h]
  int v95; // [sp+1Ch] [-184h]
  int v96; // [sp+20h] [-180h]
  int v97; // [sp+24h] [-17Ch]
  int v98; // [sp+28h] [-178h]
  int v99; // [sp+2Ch] [-174h]
  int v100; // [sp+30h] [-170h]
  int v101; // [sp+34h] [-16Ch]
  int v102; // [sp+38h] [-168h]
  int v103; // [sp+3Ch] [-164h]
  int v104; // [sp+40h] [-160h]
  int v105; // [sp+44h] [-15Ch]
  int v106; // [sp+48h] [-158h]
  int v107; // [sp+4Ch] [-154h]
  int v108; // [sp+50h] [-150h]
  float v109; // [sp+60h] [-140h] BYREF
  float v110; // [sp+64h] [-13Ch] BYREF
  _QWORD v111[2]; // [sp+68h] [-138h] BYREF
  float v112; // [sp+78h] [-128h] BYREF
  float v113; // [sp+7Ch] [-124h]
  float v114; // [sp+80h] [-120h]
  float v115; // [sp+88h] [-118h] BYREF
  float v116; // [sp+8Ch] [-114h]
  float v117; // [sp+90h] [-110h]
  idMat3 v118; // [sp+A0h] [-100h] BYREF
  _BYTE v119[20]; // [sp+C8h] [-D8h] BYREF
  char v120; // [sp+DCh] [-C4h] BYREF
  idVec3 v121[6]; // [sp+E0h] [-C0h] BYREF

  v109 = 0.0;
  if ( damageDef == nullptr )
    goto LABEL_81;
  v15 = 1.0;
  if ( a8 != 0 )
  {
    if ( *(_DWORD *)(a8 + 52) == 4 )
      v16 = *(_DWORD *)(a8 + 104);
    else
      LOWORD(v16) = -1;
    DamageGroup = idTurret::GetDamageGroup(this, joint: (const idIndex<short,enum invalidJointIndex_t> *)(__int16)v16);
    if ( DamageGroup != nullptr )
    {
      DamageGroup->lastHitAxis = *idVec3::ToMat3(this: v121, result: (idMat3 *)(a8 + 68));
      v15 = DamageGroup->damageScale;
    }
  }
  v18 = 0;
  currentState = this->currentState;
  if ( currentState != TS_SUPPRESSING_FIRE && currentState != TS_SEARCHING && currentState != TS_NORMAL )
  {
    if ( currentState == TS_INACTIVE )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        str = this->nonSearchMeshKit.str;
        if ( str != nullptr && *str != 0 )
          idTreeAnimator::HideKitsExcept(this: TreeAnimatorFromPresentable, kitType: MESH_KIT_HEADS, name: str);
        this->currentState = TS_WARMUP;
      }
      canGoInactive = this->canGoInactive;
      this->stateTimer = 500;
      if ( canGoInactive )
      {
        blendParms_t::blendParms_t(this: (blendParms_t *)&v118);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v24 = this->GetAnimStack_2(this);
        LODWORD(v25) = &v118;
        idAnimator_Channel::CycleAnim(
          this: &this->movingHoldAnimator,
          stack: v24,
          ah: &this->aquiredMhAnimAlias,
          curTime: GameMs,
          rateScale: 1.0,
          leafStarted: v25,
          a7: nullptr);
        v26 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v27 = this->GetAnimStack_2(this);
        if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                                this: &this->channelAnimator,
                                stack: v27,
                                ah: &this->acquiredTargetAnimAlias,
                                curTime: v26,
                                rateScale: 1.0,
                                blendParms: v28,
                                blendOutDurationMS_: (blendParms_t *)&v118,
                                leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                                a9: nullptr) != 0 )
        {
          LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
          if ( LastPlayedLeaf != nullptr )
            this->stateTimer = idMD6Leaf::GetLength(
                                 this: LastPlayedLeaf,
                                 ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                                 a3: v30,
                                 a4: v29);
        }
      }
      this->turretFOV = 0.0;
      if ( attacker != nullptr )
      {
        Physics = idEntity::GetPhysics(this: attacker);
        v33 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        this->goalPos.x = *v33;
        this->goalPos.y = v33[1];
        this->goalPos.z = v33[2];
      }
    }
    goto LABEL_39;
  }
  v18 = 1;
  v34 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( v34 != nullptr )
  {
    v35 = this->nonSearchMeshKit.str;
    if ( v35 != nullptr && *v35 != 0 )
      idTreeAnimator::HideKitsExcept(this: v34, kitType: MESH_KIT_HEADS, name: v35);
    this->currentState = TS_NORMAL;
  }
  if ( attacker != nullptr )
    this->attackedByTarget.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13)
                                         | attacker->entityNumber;
  else
    this->attackedByTarget.spawnId.value = 0x1FFF;
  value = this->lastTarget.spawnId.value;
  v37 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_35;
  v38 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v38 == nullptr )
    goto LABEL_35;
  if ( idEntity::CastTo(c: v38) == nullptr )
  {
    v37 = gameLocal;
LABEL_35:
    if ( attacker != nullptr )
      this->lastTarget.spawnId.value = (v37->spawnIds.ptr[attacker->entityNumber] << 13) | attacker->entityNumber;
    else
      this->lastTarget.spawnId.value = 0x1FFF;
  }
  this->turretFOV = 0.0;
LABEL_39:
  if ( v18 == 0 || (v39 = 1, !this->silenceWhenDamaged) )
    v39 = 0;
  v40 = this->currentState;
  if ( v40 == TS_DYING || v39 == 0 )
  {
    if ( v40 == TS_SILENCED && this->silenceWhenDamaged )
    {
      timeToBeSilenced = this->timeToBeSilenced;
      if ( timeToBeSilenced <= this->stateTimer )
        timeToBeSilenced = this->stateTimer;
      this->stateTimer = timeToBeSilenced;
    }
  }
  else
  {
    v41 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    if ( v41 != nullptr )
    {
      v42 = this->nonSearchMeshKit.str;
      if ( v42 != nullptr && *v42 != 0 )
        idTreeAnimator::HideKitsExcept(this: v41, kitType: MESH_KIT_HEADS, name: v42);
      this->currentState = TS_SILENCED;
    }
    v43 = this->SilencedAnimAlias.value;
    this->stateTimer = this->timeToBeSilenced;
    if ( v43 != 0xFFFF )
    {
      blendParms_t::blendParms_t(this: (blendParms_t *)&v118);
      v44 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v45 = this->GetAnimStack_2(this);
      if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                              this: &this->channelAnimator,
                              stack: v45,
                              ah: &this->SilencedAnimAlias,
                              curTime: v44,
                              rateScale: 1.0,
                              blendParms: v46,
                              blendOutDurationMS_: (blendParms_t *)&v118,
                              leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                              a9: nullptr) != 0 )
      {
        v49 = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
        if ( v49 != nullptr )
        {
          Length = idMD6Leaf::GetLength(
                     this: v49,
                     ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                     a3: v48,
                     a4: v47);
          stateTimer = this->stateTimer;
          this->slinecedIntoTime = Length;
          this->stateTimer = Length + stateTimer;
        }
        idAnimator_Channel::ClearAnimator(this: &this->movingHoldAnimator);
      }
    }
  }
  v109 = (float)(idDeclDamage::DamageAmount(this: damageDef) * (float)v15) * (float)damageScale;
  if ( attacker != nullptr )
    attacker->DamageFeedback(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: &v109);
  ((void (__fastcall *)(idTurret *, idEntity *, idEntity *, const idDeclDamage *, double))this->CalcDamageImpulse)(
    a1: this,
    a2: inflictor,
    a3: attacker,
    a4: damageDef,
    a5: damageScale);
  if ( a8 != 0 )
    v53 = *(_DWORD *)(a8 + 116);
  else
    v53 = 0;
  this->ApplyImpulseFromEntity(this, a2: inflictor, a3: v53, a4: (const idVec3 *)v119, a5: &v118.mat[2]);
  knockBack = damageDef->knockBack;
  if ( knockBack != 0 && (*(_BYTE *)&this->flags & 4) == 0 )
  {
    if ( a8 != 0 )
    {
      v56 = *(float *)(a8 + 8);
      v57 = *(float *)(a8 + 12);
      v115 = *(float *)(a8 + 4);
      v116 = v56;
    }
    else
    {
      v58 = idEntity::GetPhysics(this);
      v59 = (float *)v58->GetOrigin(this: v58, a2: 0);
      v115 = *v59;
      v116 = v59[1];
      v57 = v59[2];
    }
    v117 = v57;
    v61 = this->GetAF_2(this);
    if ( v61 == nullptr )
      goto LABEL_75;
    if ( v61->isActive || (v62 = 0, v61->isClientAuthoritativeActive) )
      v62 = 1;
    if ( v62 != 0 )
    {
      v63 = (float)(trace->endpos.x * damageDef->ragdollImpulseMag);
      v64 = (float)(trace->endpos.y * damageDef->ragdollImpulseMag);
      v112 = trace->fraction * damageDef->ragdollImpulseMag;
      v113 = v63;
      v114 = v64;
    }
    else
    {
LABEL_75:
      LODWORD(v60) = knockBack;
      v65 = (float)(trace->endpos.y + (float)1.0);
      fraction = trace->fraction;
      v111[0] = v60;
      v113 = trace->endpos.x * (float)v60;
      v112 = (float)fraction * (float)v60;
      v114 = (float)v60 * (float)v65;
      v67 = idEntity::GetPhysics(this);
      v68 = (float)(v67->GetMass(this: v67, a2: -1) * (float)0.15000001);
      v112 = (float)v68 * v112;
      v113 = v113 * (float)v68;
      v114 = (float)v68 * v114;
    }
    if ( a8 != 0 )
      v69 = *(_DWORD *)(a8 + 116);
    else
      v69 = 0;
    this->ApplyImpulseFromEntity(this, a2: inflictor, a3: v69, a4: (const idVec3 *)&v115, a5: (const idVec3 *)&v112);
  }
  v110 = 0.0;
  ((void (__fastcall *)(idSimpleHealth *, int, int, float *, double))this->turretHealth.Damage_Impl)(
    a1: &this->turretHealth,
    a2: v54,
    a3: 1,
    a4: &v110,
    a5: v109);
LABEL_81:
  if ( this->turretHealth.IsDead_Impl(this: &this->turretHealth) && this->currentState != TS_DYING )
  {
    if ( a8 == 0 )
    {
      v71 = idEntity::GetPhysics(this);
      v71->GetOrigin(this: v71, a2: 0);
    }
    if ( this->ondestroyedParticle != nullptr )
    {
      v72 = idEntity::GetPhysics(this);
      v73 = (int)v72->GetOrigin(this: v72, a2: 0);
      v74 = *(float *)(v73 + 4);
      v75 = *(float *)(v73 + 8);
      v118.mat[0].x = *(float *)v73;
      v118.mat[0].y = v74;
      v118.mat[0].z = v75;
      v76 = idEntity::GetPhysics(this);
      v77 = (int)v76->GetAxis(this: v76, a2: 0);
      v78 = &v120;
      v79 = (_DWORD *)(v77 - 4);
      for ( i = 9; i != 0; --i )
      {
        ++v79;
        v78 += 4;
        *(_DWORD *)v78 = *v79;
      }
      HIDWORD(v111[0]) = -1;
      HIDWORD(v81) = "DistToTarget: %f dist: %f \n";
      v82 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v82 + 1013904223;
      LODWORD(v81) = ((v82 + 1013904223) >> 10) & 0x7FFF;
      v111[1] = v81;
      v83 = (float)((float)v81 * (float)0.000030518509);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v85 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      ondestroyedParticle = this->ondestroyedParticle;
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: ondestroyedParticle,
        systemStartTime: v85,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v83,
        origin: (const idVec3 *)v111,
        axis: &v118,
        velocity: v121,
        color: &vec3_origin.x,
        a10: v90,
        a11: v91,
        a12: v92,
        a13: v93,
        a14: v94,
        a15: v95,
        a16: v96,
        a17: v97,
        a18: v98,
        a19: v99,
        a20: v100,
        a21: v101,
        a22: v102,
        a23: v103,
        a24: v104,
        a25: v105,
        a26: v106,
        a27: v107,
        a28: v108,
        a29: (unsigned int *)v111);
    }
    idTurret::SetDying(this, inflictor, attacker, damageDef, damageScale, dir: v70, trace, a8);
    if ( !this->dontRemoveAfterDying && common->IsMultiplayer(this: common) )
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 1000);
  }
  v88 = v109;
  return *((float *)&v88 + 1);
}


// ========================================================================
// ?Spawn@idRailTurret@@QAAXXZ
// EA  : 0x82CF8F58
// RVA : 0x00CF8F58
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idRailTurret::Spawn(idRailTurret *this)
{
  int v2; // r9
  idSplinePath *v3; // r3
  idSplinePath *v4; // r4
  int value; // r10

  if ( this->plannedPath.num <= 0 )
  {
    value = this->startTrack.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v3 = (idSplinePath *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v3 != nullptr )
        goto LABEL_4;
    }
LABEL_7:
    v4 = nullptr;
    goto LABEL_8;
  }
  v2 = this->plannedPath.list->spawnId.value;
  if ( gameLocal->spawnIds.ptr[v2 & 0x1FFF] != v2 >> 13 )
    goto LABEL_7;
  v3 = (idSplinePath *)gameLocal->entities.ptr[v2 & 0x1FFF];
  if ( v3 == nullptr )
    goto LABEL_7;
LABEL_4:
  v4 = idSplinePath::CastTo(c: v3);
LABEL_8:
  idRailTurret::SetPath(this, path: v4);
}


// ========================================================================
// ?Damage@idTowerTurret@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CF9030
// RVA : 0x00CF9030
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

float __fastcall idTowerTurret::Damage(
        idTowerTurret *this,
        idAFEntity_Dummy *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        float *a8)
{
  double v15; // fp1
  double v16; // fp30
  idSimpleHealth *v17; // r3
  bool v18; // r24
  const idVec3 *v19; // r7
  int v20; // r23
  idSimpleHealth *v21; // r3
  __int64 v22; // r11
  idAFEntity_Dummy *v23; // r3
  idAFEntity_Dummy *v24; // r3
  const idVec3 *v25; // r6
  double v26; // fp11
  double v27; // fp3
  double v28; // fp13
  idPhysics *Physics; // r28
  idPhysics *v30; // r3
  const idVec3 *v31; // r27
  idPhysics *v32; // r3
  idBreakableManager *p_breakableManager; // r28
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  const idMat3 *v35; // r3
  idPhysics *v36; // r28
  idPhysics *v37; // r3
  const idVec3 *v38; // r27
  idBreakableManager *v39; // r30
  const idMat3 *v40; // r3
  idVec3 v42[2]; // [sp+58h] [-78h] BYREF

  if ( damageDef == nullptr || (damageDef->damageTypes & 0x40) == 0 )
    goto LABEL_2;
  v16 = damageScale;
  if ( (unsigned __int8)idProjectile_Rocket::IsTypeOf(c: inflictor) == 0 )
  {
    v17 = this->GetTurretHealthComponent_2(this);
    if ( damageScale >= ((double (__fastcall *)(idSimpleHealth *))v17->GetMaxBaseHealth_Impl)(a1: v17) )
      goto LABEL_7;
LABEL_2:
    v15 = 0.0;
    return *((float *)&v15 + 1);
  }
  v16 = (float)((float)damageScale * (float)4.0);
LABEL_7:
  v18 = this->IsDead(this);
  v20 = (int)idTurret::Damage(this, inflictor, attacker, damageDef, damageScale: v16, dir: v19, trace, (int)a8);
  v21 = this->GetTurretHealthComponent_2(this);
  if ( v21->IsDead_Impl(this: v21) )
  {
    this->ActivateTargets(this, a2: attacker);
    if ( idEntityPtr<idAFEntity_Dummy>::operator idAFEntity_Dummy *(this: &this->towerGunner) != nullptr )
    {
      v23 = idEntityPtr<idAFEntity_Dummy>::operator idAFEntity_Dummy *(this: &this->towerGunner);
      ((void (__fastcall *)(idAFEntity_Dummy *, idAFEntity_Dummy *, idEntity *, const idDeclDamage *, double))v23->Damage)(
        a1: v23,
        a2: inflictor,
        a3: attacker,
        a4: damageDef,
        a5: damageScale);
      v24 = idEntityPtr<idAFEntity_Dummy>::operator idAFEntity_Dummy *(this: &this->towerGunner);
      idAFEntity_Dummy::ForceStartRagdoll(this: v24, inflictor, damageDef, damageScale, dir: v25, trace, a7: (int)a8);
    }
    v26 = a8[4];
    v27 = (float)(a8[5] * (float)((float)__SPAIR64__(0x82000000, v20) + (float)10.0));
    v28 = (float)((float)(a8[6] * (float)((float)__SPAIR64__(0x82000000, v20) + (float)10.0)) * (float)0.25);
    v42[0].z = (float)(a8[6] * (float)((float)__SPAIR64__(0x82000000, v20) + (float)10.0)) * (float)0.25;
    v42[0].x = (float)((float)v26 * (float)((float)__SPAIR64__(0x82000000, v20) + (float)10.0)) * (float)0.25;
    v42[0].y = (float)v27 * (float)0.25;
    if ( v28 < 0.0 )
      v42[0].z = 0.0;
    if ( !v18 )
    {
      if ( this->breakableBody != nullptr )
      {
        Physics = idEntity::GetPhysics(this);
        v30 = idEntity::GetPhysics(this);
        v31 = v30->GetOrigin(this: v30, a2: 0);
        v32 = Physics;
        GetAxis = Physics->GetAxis;
        p_breakableManager = &gameLocal->breakableManager;
        v35 = GetAxis(this: v32, a2: 0);
        idBreakableManager::UseBreakable(
          this: p_breakableManager,
          decl: this->breakableBody,
          origin: v31,
          axis: v35,
          dir: v42,
          pos: nullptr,
          impulse: 0.0,
          fadeTime: 0.0);
      }
      if ( this->breakableHead != nullptr )
      {
        v36 = idEntity::GetPhysics(this);
        v37 = idEntity::GetPhysics(this);
        v38 = v37->GetOrigin(this: v37, a2: 0);
        v39 = &gameLocal->breakableManager;
        v40 = v36->GetAxis(this: v36, a2: 0);
        idBreakableManager::UseBreakable(
          this: v39,
          decl: this->breakableHead,
          origin: v38,
          axis: v40,
          dir: v42,
          pos: nullptr,
          impulse: 0.0,
          fadeTime: 0.0);
      }
    }
    this->Hide_2(this);
  }
  LODWORD(v22) = v20;
  v15 = (float)v22;
  return *((float *)&v15 + 1);
}


// ========================================================================
// ?Spawn@idTurret@@QAAXXZ
// EA  : 0x82CF9390
// RVA : 0x00CF9390
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::Spawn(idTurret *this, long double a2)
{
  int entityNumber; // r11
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int v5; // r6
  int v6; // r10
  int num; // r9
  int v8; // r8
  int v9; // r11
  long double v10; // fp2
  long double v11; // fp2
  idWeapon *v12; // r29
  idWeapon *v13; // r3
  idPresentable *presentable; // r3
  idPresentableWeapon *v15; // r3
  const idDeclProjectile *CurrentProjectileDecl; // r3
  idPhysics_RigidBody_vtbl *v17; // r28
  double v18; // fp29
  idClipModel *v19; // r3
  idPhysics *v20; // r3
  idPhysics_RigidBody_vtbl *v21; // r28
  int v22; // r3
  idPhysics *v23; // r3
  idPhysics_RigidBody_vtbl *v24; // r28
  int v25; // r3
  int v26; // r5
  idPhysics *Physics; // r28
  double density; // fp29
  idPhysics_vtbl *v29; // r29
  idClipModel *MoveableClipModel; // r3
  idPhysics *v31; // r3
  idPhysics *v32; // r3
  int v33; // r4
  idPhysics *v34; // r3
  int v35; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *v37; // r11
  idTreeAnimator *v38; // r29
  idPresentable *v39; // r11
  idPresentableTurret *v40; // r25
  int v41; // r11
  int v42; // r11
  int v43; // r11
  idGameTimeManager *v44; // r3
  idGameTimeManager *v45; // r3
  idGameTimeManager *v46; // r3
  idGameTimeManager *v47; // r3
  idVec3 *p_gravity; // r25
  int v49; // r23
  idSoundEmitter *SoundEmitter; // r17
  idClip *p_clip; // r15
  idAnimStack *v52; // r3
  idAnimStack *v53; // r3
  int GameMs; // r27
  const idAnimStack *v55; // r3
  const blendParms_t *v56; // r7
  __int64 v57; // r8
  int v58; // r5
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idPresentable *v60; // r3
  char flags; // r11
  idTreeAnimator *v62; // r3
  const char *str; // r5
  int v64; // r27
  const idAnimStack *v65; // r3
  const blendParms_t *v66; // r7
  __int64 v67; // r8
  int v68; // r5
  idMD6LeafPlay *v69; // r3
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r29
  int PropIndex; // r3
  int TagIndex; // r3
  unsigned int value; // r8
  idTreeAnimator *v75; // r3
  idVec3 *p_startPos; // r29
  idTreeAnimator *v77; // r3
  int v78; // r4
  double z; // fp12
  double x; // fp6
  double y; // fp13
  double v82; // fp7
  double v83; // fp8
  double v84; // fp5
  double v85; // fp4
  double v86; // fp12
  double v89; // fp10
  double v90; // fp8
  double v91; // fp13
  double v92; // fp12
  const idDeclSkins *skinPreload; // r6
  idPresentable *v94; // r11
  idDeclSkins *v95; // r3
  int v96; // r3
  idGameLocal_vtbl *v97; // r29
  idTypeInfoSettings *v98; // r3
  idEntity *v99; // r29
  idTreeAnimator *v100; // r3
  const idDeclMD6 *v101; // r11
  idPropsCollection *v102; // r3
  const tagData_t *Tag; // r3
  idAIGameState *p_aiGameState; // r28
  const idEntityPtr<idAI2> *SpawnId; // r3
  idPhysicsCallbacks *v106; // [sp+8h] [-238h]
  int v107; // [sp+Ch] [-234h]
  int v108; // [sp+10h] [-230h]
  int v109; // [sp+14h] [-22Ch]
  int v110; // [sp+18h] [-228h]
  int v111; // [sp+1Ch] [-224h]
  int v112; // [sp+20h] [-220h]
  int v113; // [sp+24h] [-21Ch]
  int v114; // [sp+28h] [-218h]
  int v115; // [sp+2Ch] [-214h]
  int v116; // [sp+30h] [-210h]
  int v117; // [sp+34h] [-20Ch]
  int v118; // [sp+38h] [-208h]
  int v119; // [sp+3Ch] [-204h]
  int v120; // [sp+40h] [-200h]
  int v121; // [sp+44h] [-1FCh]
  int v122; // [sp+48h] [-1F8h]
  int v123; // [sp+4Ch] [-1F4h]
  int v124; // [sp+50h] [-1F0h]
  idEntityPtr<idEntity> v125[2]; // [sp+60h] [-1E0h] BYREF
  idVec3 v126; // [sp+68h] [-1D8h] BYREF
  blendParms_t v127; // [sp+80h] [-1C0h] BYREF
  idAnimatorParms_Base v128; // [sp+A0h] [-1A0h] BYREF
  idAnimatorParms_Base v129; // [sp+E0h] [-160h] BYREF
  idTreeAnimator *v130; // [sp+118h] [-128h]
  int v131; // [sp+11Ch] [-124h]
  idMat3 v132; // [sp+120h] [-120h] BYREF
  idAnimatorParms_Base v133; // [sp+150h] [-F0h] BYREF
  idVec3 v134; // [sp+188h] [-B8h] BYREF

  entityNumber = this->entityNumber;
  *(_BYTE *)&this->flags |= 0x40u;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  v5 = gameLocal->spawnIds.ptr[entityNumber] << 13;
  v125[0].spawnId.value = entityNumber;
  v6 = v5 | entityNumber;
  num = gameLocal->aiWorldStateUsers.num;
  v8 = 0;
  v125[0].spawnId.value = v5 | entityNumber;
  if ( num <= 0 )
    goto LABEL_7;
  v9 = 0;
  while ( p_aiWorldStateUsers->list[v9].spawnId.value != v6 )
  {
    ++v8;
    ++v9;
    if ( v8 >= num )
      goto LABEL_7;
  }
  if ( v8 < 0 )
LABEL_7:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_aiWorldStateUsers, obj: v125);
  *(double *)&a2 = (float)(this->maxFireAngle * idMath::M_DEG2RAD);
  v10 = cos(x: a2);
  this->cosMaxFireAngle = *(double *)&v10;
  *(double *)&v10 = (float)(this->maxFirePitch * idMath::M_DEG2RAD);
  v11 = cos(x: v10);
  this->cosMaxFirePitch = *(double *)&v11;
  v12 = (idWeapon *)idInventoryItem::Create(decl: this->weaponDecl);
  v13 = idWeapon::CastTo(c: v12);
  this->turretWeapon = v13;
  if ( v13 != nullptr )
  {
    v13->Show(this: v13);
    idWeapon::ShowLaserSight(this: this->turretWeapon);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v15 = presentable->GetWeaponInterface(this: presentable);
    idWeapon::SetPresentableWeapon(this: this->turretWeapon, presentableWeapon_: v15);
    CurrentProjectileDecl = idWeapon::GetCurrentProjectileDecl(this: this->turretWeapon, secondaryAmmo: false);
    if ( CurrentProjectileDecl != nullptr && !CurrentProjectileDecl->hitscan )
      this->interceptSpeed = CurrentProjectileDecl->notHitscanInfo.speed;
  }
  else if ( v12 != nullptr )
  {
    ((void (__fastcall *)(idWeapon *, int))v12->dtr_idClass)(a1: v12, a2: 1);
  }
  if ( this->isStatic )
  {
    Physics = idEntity::GetPhysics(this);
    density = this->density;
    v29 = Physics->__vftable;
    MoveableClipModel = idEntity::CreateMoveableClipModel(this, barrelCollision: true, overrideRadius: -1.0);
    ((void (__fastcall *)(idPhysics *, idClipModel *, double))v29->SetClipModel)(
      a1: Physics,
      a2: MoveableClipModel,
      a3: density);
    if ( this->hasSphereModel )
    {
      v34 = idEntity::GetPhysics(this);
      v34->SetContents(this: v34, a2: 148008, a3: -1);
      v32 = idEntity::GetPhysics(this);
      v33 = 41033;
    }
    else
    {
      v31 = idEntity::GetPhysics(this);
      v31->SetContents(this: v31, a2: 148001, a3: -1);
      v32 = idEntity::GetPhysics(this);
      v33 = 8265;
    }
    v32->SetClipMask(this: v32, a2: v33, a3: -1);
  }
  else
  {
    v126.x = 1.0;
    v126.y = 1.0;
    v126.z = 1.0;
    idPhysics::InitPhysics(
      this: &this->physicsObj,
      clip_: &clientGame->clip,
      callbacks_: &this->physicsCallbacks,
      entityNumber_: this->entityNumber);
    idPhysics_RigidBody::SetBouncyness(this: &this->physicsObj, b: 0.0);
    idPhysics_RigidBody::SetFriction(
      this: &this->physicsObj,
      linear: 0.60000002,
      angular: 0.60000002,
      contact: 0.60000002);
    this->physicsObj.SetGravity(this: &this->physicsObj, a2: &gameLocal->clientGame.gravity);
    idPhysics_RigidBody::SetInertiaScale(this: &this->physicsObj, v: &v126);
    v17 = this->physicsObj.__vftable;
    v18 = this->density;
    v19 = idEntity::CreateMoveableClipModel(this, barrelCollision: true, overrideRadius: -1.0);
    ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))v17->SetClipModel)(
      a1: &this->physicsObj,
      a2: v19,
      a3: v18);
    v20 = idEntity::GetPhysics(this);
    v21 = this->physicsObj.__vftable;
    v22 = (int)v20->GetOrigin(this: v20, a2: 0);
    v21->SetOrigin(this: &this->physicsObj, a2: (const idVec3 *)v22, a3: -1);
    v23 = idEntity::GetPhysics(this);
    v24 = this->physicsObj.__vftable;
    v25 = (int)v23->GetAxis(this: v23, a2: 0);
    v24->SetAxis(this: &this->physicsObj, a2: (const idMat3 *)v25, a3: -1);
    this->physicsObj.SetContents(this: &this->physicsObj, a2: 148128, a3: -1);
    this->physicsObj.SetClipMask(this: &this->physicsObj, a2: 8393, a3: -1);
    idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v26);
    *((_BYTE *)&this->physicsObj.fl + 4) |= 0xC0u;
  }
  v35 = this->entityNumber;
  v125[0].spawnId.value = (int)&this->defaultPhysicsCallbacks.ent;
  this->defaultPhysicsCallbacks.ent.spawnId.value = (gameLocal->spawnIds.ptr[v35] << 13) | v35;
  this->defaultPhysicsCallbacks.af = &this->afProperties;
  idEntity::BecomeActive(this, flags: 7);
  this->stateTimer = this->initTime;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v37 = this->presentable;
  v38 = TreeAnimatorFromPresentable;
  if ( v37 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v37 = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: v37);
  if ( v38 != nullptr )
  {
    gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v38, a3: &this->dropAnimAlias, a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(
      this: gameAnimTools,
      a2: v38,
      a3: &this->acquiredTargetAnimAlias,
      a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(
      this: gameAnimTools,
      a2: v38,
      a3: &this->lostTargetAnimAlias,
      a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v38, a3: &this->breakAnimAlias, a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v38, a3: &this->shootAnimAlias, a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(
      this: gameAnimTools,
      a2: v38,
      a3: &this->SilencedAnimAlias,
      a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(
      this: gameAnimTools,
      a2: v38,
      a3: &this->UnSilencedAnimAlias,
      a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(
      this: gameAnimTools,
      a2: v38,
      a3: &this->disabledAnimAlias,
      a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(
      this: gameAnimTools,
      a2: v38,
      a3: &this->SilencedIdleAnimAlias,
      a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(
      this: gameAnimTools,
      a2: v38,
      a3: &this->aquiredMhAnimAlias,
      a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(
      this: gameAnimTools,
      a2: v38,
      a3: &this->destroyedAnimAlias,
      a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(
      this: gameAnimTools,
      a2: v38,
      a3: &this->destroyedMhAnimAlias,
      a4: this->name.data);
    v39 = this->presentable;
    if ( v39 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v39 = this->presentable;
    }
    v40 = v39->GetTurretInterface(this: v39);
    if ( v40 != nullptr )
    {
      v41 = HIWORD(idTreeAnimator::GetJointIndex(
                     this: (idTreeAnimator *)v125,
                     result: (idIndex<short,enum invalidJointIndex_t> *)v38,
                     jointName: this->nameRotation.data)->__vftable);
      this->jointRotation.value = v41;
      if ( v41 == 0xFFFF )
      {
        HIWORD(v125[0].spawnId.value) = -1;
        v40->jointRotation.value = -1;
      }
      v42 = HIWORD(idTreeAnimator::GetJointIndex(
                     this: (idTreeAnimator *)v125,
                     result: (idIndex<short,enum invalidJointIndex_t> *)v38,
                     jointName: this->namePitch.data)->__vftable);
      this->jointPitch.value = v42;
      if ( v42 == 0xFFFF )
      {
        HIWORD(v125[0].spawnId.value) = -1;
        v40->jointPitch.value = -1;
      }
      v43 = HIWORD(idTreeAnimator::GetJointIndex(
                     this: (idTreeAnimator *)v125,
                     result: (idIndex<short,enum invalidJointIndex_t> *)v38,
                     jointName: this->nameSpinwheel.data)->__vftable);
      this->jointSpinwheel.value = v43;
      if ( v43 == 0xFFFF )
      {
        HIWORD(v125[0].spawnId.value) = -1;
        v40->jointSpinwheel.value = -1;
      }
    }
    v129.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v129.name, text: "jointmod");
    v129.alpha = 1.0;
    v129.blendOp = BOP_LERP;
    v129.originBlend = ORIGINBLEND_BRANCH;
    v129.weightGroup = MD6_WEIGHTGROUP_HEAD;
    v129.filterGroup = MD6_WEIGHTGROUP_HEAD;
    v130 = v38;
    v131 = 0;
    v44 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->jointModAnimator, gametimeManager: v44, parms: &v129);
    v128.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v128.name, text: "all");
    v128.alpha = 1.0;
    v128.blendOp = BOP_LERP;
    memset(&v128.originBlend, 0, 12);
    v45 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->movingHoldAnimator, gametimeManager: v45, parms: &v128);
    v46 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->channelAnimator, gametimeManager: v46, parms: &v128);
    v133.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v133.name, text: "af");
    v133.alpha = 0.0;
    v133.blendOp = BOP_LERP;
    memset(&v133.originBlend, 0, 12);
    v47 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->afProperties, gametimeManager: v47, parms: &v133);
    p_gravity = &gameLocal->clientGame.gravity;
    v49 = this->entityNumber;
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
    p_clip = &clientGame->clip;
    v52 = this->GetAnimStack_2(this);
    idAnimator_AF::InitAF(
      this: &this->afProperties,
      animStack: v52,
      clip: p_clip,
      impactManager: &this->impactManager,
      soundEmitter: SoundEmitter,
      soundChannel: SND_CHANNEL_BODY3,
      gravityVector: p_gravity,
      entityNumber: v49,
      callback: v106,
      a10: v107,
      a11: v108,
      a12: v109,
      a13: v110,
      a14: v111,
      a15: v112,
      a16: v113,
      a17: v114,
      a18: v115,
      a19: v116,
      a20: v117,
      a21: v118,
      a22: v119,
      a23: v120,
      a24: v121,
      a25: v122,
      a26: v123,
      a27: v124,
      a28: &this->defaultPhysicsCallbacks);
    v53 = this->GetAnimStack_2(this);
    idAnimator_Base::SetEnabled(this: &this->afProperties, animStack: v53, enabled: false);
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    blendParms_t::blendParms_t(this: &v127);
    if ( this->dropAnimAlias.value != 0xFFFF )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v55 = this->GetAnimStack_2(this);
      if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                              this: &this->channelAnimator,
                              stack: v55,
                              ah: &this->dropAnimAlias,
                              curTime: GameMs + 500,
                              rateScale: 1.0,
                              blendParms: v56,
                              blendOutDurationMS_: &v127,
                              leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                              a9: nullptr) != 0 )
      {
        LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
        if ( LastPlayedLeaf != nullptr )
          this->stateTimer = idMD6Leaf::GetLength(
                               this: LastPlayedLeaf,
                               ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                               a3: v58,
                               a4: v57);
      }
    }
    idStr::FreeData(this: &v133.name);
    idStr::FreeData(this: &v128.name);
    idStr::FreeData(this: &v129.name);
  }
  v60 = this->presentable;
  if ( v60 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v60 = this->presentable;
  }
  v60->Present(this: v60);
  if ( this->noKnockback )
  {
    flags = (char)this->flags;
    this->physicsObj.fl.noPushMask = 46080;
    *(_BYTE *)&this->flags = flags | 4;
  }
  if ( this->acquiredTargetAnimAlias.value == 0xFFFF )
  {
    if ( this->dropAnimAlias.value != 0xFFFF )
    {
      blendParms_t::blendParms_t(this: &v127);
      blendParms_t::SetDurationMS(this: &v127, ms: 0x3E8u);
      v64 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v65 = this->GetAnimStack_2(this);
      if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                              this: &this->channelAnimator,
                              stack: v65,
                              ah: &this->dropAnimAlias,
                              curTime: v64,
                              rateScale: 1.0,
                              blendParms: v66,
                              blendOutDurationMS_: &v127,
                              leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                              a9: nullptr) != 0 )
      {
        v69 = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
        if ( v69 != nullptr )
          this->stateTimer = idMD6Leaf::GetLength(
                               this: v69,
                               ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                               a3: v68,
                               a4: v67);
      }
    }
  }
  else
  {
    this->canGoInactive = true;
    v62 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    if ( v62 != nullptr )
    {
      str = this->nonSearchMeshKit.str;
      if ( str != nullptr && *str != 0 )
        idTreeAnimator::HideKitsExcept(this: v62, kitType: MESH_KIT_HEADS, name: str);
      this->currentState = TS_INACTIVE;
    }
  }
  decl = idAnimatedEntity::GetTreeAnimatorFromPresentable(this)->decl;
  p_props = &decl->props;
  if ( decl == nullptr )
    p_props = nullptr;
  PropIndex = idPropsCollection::FindPropIndex(this: p_props, propName: idPropInfo::INFO_PROP_NAME);
  this->propinfoIndex = PropIndex;
  TagIndex = idPropsCollection::FindTagIndex(this: p_props, propIdx: PropIndex, tagName: "muzzle");
  value = (unsigned __int16)this->jointRotation.value;
  this->muzzleTagIndex = TagIndex;
  if ( value < 0x8000 && idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    v75 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    p_startPos = &this->startPos;
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: v75,
      pose: (animationPose_t)0,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
      origin: &this->startPos,
      axis: &v132);
    v77 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: v77,
      pose: (animationPose_t)0,
      jointIndex: nullptr,
      origin: &v134,
      axis: &v132);
  }
  else
  {
    p_startPos = &this->startPos;
    idAnimatedEntity::GetTagPosition(
      this,
      propIndex: this->propinfoIndex,
      tagIndex: this->muzzleTagIndex,
      origin: &this->startPos,
      axis: &v132);
  }
  z = v132.mat[0].z;
  x = v132.mat[0].x;
  y = v132.mat[0].y;
  v82 = (float)(p_startPos->z + v132.mat[0].z);
  v83 = (float)(p_startPos->y + v132.mat[0].y);
  this->goalPos.x = v132.mat[0].x + p_startPos->x;
  this->goalPos.y = v83;
  v84 = z;
  this->goalPos.z = v82;
  this->startForwardDir.x = x;
  this->startForwardDir.y = y;
  this->startForwardDir.z = z;
  v85 = this->startForwardDir.y;
  v86 = (float)((float)((float)z * (float)z)
              + (float)((float)((float)x * (float)x) + (float)(this->startForwardDir.y * this->startForwardDir.y)));
  v125[0].spawnId.value = (int)&this->goalPos;
  _FP11 = (float)((float)v86 - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f9, f11, f12, f13 }
  v89 = (float)((float)v86 * (float)0.5);
  v90 = __frsqrte(_FP9);
  v91 = (float)((float)-(float)((float)((float)((float)v90 * (float)((float)v86 * (float)0.5)) * (float)v90) - (float)1.5)
              * (float)v90);
  v92 = (float)((float)((float)-(float)((float)((float)((float)v90 * (float)((float)v86 * (float)0.5)) * (float)v90)
                                      - (float)1.5)
                      * (float)v90)
              * (float)((float)v86 * (float)0.5));
  this->startForwardDir.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v92
                                                                                                  * (float)v91)
                                                                                          - (float)1.5)
                                                                          * (float)v91)
                                                                  * (float)v89)
                                                          * (float)((float)-(float)((float)((float)v92 * (float)v91)
                                                                                  - (float)1.5)
                                                                  * (float)v91))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)v92 * (float)v91) - (float)1.5) * (float)v91))
                          * (float)x;
  this->startForwardDir.y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v92
                                                                                                  * (float)v91)
                                                                                          - (float)1.5)
                                                                          * (float)v91)
                                                                  * (float)v89)
                                                          * (float)((float)-(float)((float)((float)v92 * (float)v91)
                                                                                  - (float)1.5)
                                                                  * (float)v91))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)v92 * (float)v91) - (float)1.5) * (float)v91))
                          * (float)v85;
  this->startForwardDir.z = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v92
                                                                                                  * (float)v91)
                                                                                          - (float)1.5)
                                                                          * (float)v91)
                                                                  * (float)v89)
                                                          * (float)((float)-(float)((float)((float)v92 * (float)v91)
                                                                                  - (float)1.5)
                                                                  * (float)v91))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)v92 * (float)v91) - (float)1.5) * (float)v91))
                          * (float)v84;
  idAIWorldState::Init(
    this: &this->worldState,
    visibleSightTime_: 0.5,
    friendlyVisibilityEffectsMask_: v78,
    enemyVisibilityEffectsMask_: -65,
    a5: -65);
  skinPreload = this->skinPreload;
  this->startFOV = this->turretFOV;
  if ( skinPreload == nullptr )
  {
    v94 = this->presentable;
    if ( v94 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v94 = this->presentable;
    }
    this->skinPreload = v94->model->GetSkins(this: v94->model);
  }
  v95 = this->skinPreload;
  if ( v95 != nullptr )
  {
    v125[0] = (idEntityPtr<idEntity>)this->skinPreload;
    this->idleSkin = idDeclSkins::IndexForSkin(this: v95, name: "idle");
    v96 = idDeclSkins::IndexForSkin(this: this->skinPreload, name: "alarm");
    this->alarmSkin = v96;
    if ( v96 == -1 )
      this->alarmSkin = this->idleSkin;
  }
  if ( this->flareDecl != nullptr )
  {
    v97 = gameLocal->__vftable;
    v98 = idTypeInfoSettings::idTypeInfoSettings(this: (idTypeInfoSettings *)&v127);
    v99 = v97->CreateEntityFromDef(this: gameLocal, a2: this->flareDecl, a3: v98);
    if ( v99 == nullptr )
      idLib::Error(fmt: "'%s' failed to spawn it's flare", this->name.data);
    gameLocal->SpawnEntity(this: gameLocal, a2: v99, a3: -1, a4: -1, a5: -1);
    v100 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    if ( v100 != nullptr )
    {
      v101 = v100->decl;
      v102 = &v101->props;
      if ( v101 == nullptr )
        v102 = nullptr;
      Tag = idPropsCollection::GetTag(this: v102, propName: "_info", tagName: "flare");
      idEntity::BindToTag(this: v99, master: (idWorldspawn *)this, tag: Tag, orientated: true);
      this->flare.spawnId.value = (gameLocal->spawnIds.ptr[v99->entityNumber] << 13) | v99->entityNumber;
    }
    if ( gameLocal->spawnIds.ptr[this->flare.spawnId.value & 0x1FFF] == this->flare.spawnId.value >> 13 )
    {
      idEntity::UpdateVisuals(this: v99);
      v99->Hide_2(this: v99);
    }
    else
    {
      gameLocal->DeleteEntity(this: gameLocal, a2: v99);
    }
  }
  p_aiGameState = &gameLocal->aiGameState;
  SpawnId = (const idEntityPtr<idAI2> *)idGameLocal::GetSpawnId(
                                          this: (idGameLocal *)v125,
                                          result: (idSpawnId *)gameLocal,
                                          ent: this);
  idAIGameState::ForceLatch(this: p_aiGameState, spawnId: SpawnId);
  idAIGameState::UpdateForcedLatches(this: &gameLocal->aiGameState, game: gameLocal);
  idGameLocal::BotSystems_RegisterEntity(this: gameLocal, entity: this, entityType: 64, entityFlags: 608);
}


// ========================================================================
// $LN399
// EA  : 0x82CFA1E8
// RVA : 0x00CFA1E8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _LN399()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 576 + 224));
}


// ========================================================================
// __unwind$503320
// EA  : 0x82CFA210
// RVA : 0x00CFA210
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_503320()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 576 + 160));
}


// ========================================================================
// __unwind$503321
// EA  : 0x82CFA238
// RVA : 0x00CFA238
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_503321()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 576 + 336));
}


// ========================================================================
// ?TurretFire@idTurret@@AAA_NXZ
// EA  : 0x82CFA268
// RVA : 0x00CFA268
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::TurretFire(idTurret *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idWeapon *turretWeapon; // r3
  idFinishFireResults *v5; // r11
  int i; // ctr
  idTurret::turretStates currentState; // r9
  double x; // fp0
  double y; // fp13
  double z; // fp12
  const idEntity *v11; // r3
  idAIEntityState *v12; // r27
  const idEntity *v13; // r3
  idEntity *Entity; // r3
  idEntity *v15; // r3
  idPresentable *presentable; // r11
  idEntity *v17; // r29
  double v18; // fp13
  double v19; // fp12
  idPlayer *Player; // r3
  const idFaction *v21; // r3
  int v22; // r4
  bool (__fastcall *Damage_Impl)(struct idSimpleHealth *, const float, const bool, float *); // r8
  int GameMs; // r25
  const idAnimStack *v25; // r3
  const blendParms_t *v26; // r7
  idMD6LeafPlay *LastPlayedLeaf; // r27
  int v28; // r29
  __int64 v29; // r8
  int v30; // r5
  idPresentable *v32; // r29
  const idMat3 *v33; // r28
  const idPresentable *v34; // r3
  idEntity *v35; // r3
  idEntity *v36; // r29
  const idPresentable *v37; // r29
  idPresentable *v38; // r4
  BOOL v39; // r30
  idPresentable *v40; // r29
  const idMat3 *v41; // r28
  const idPresentable *v42; // r3
  idEntity *v43; // r3
  idEntity *v44; // r29
  idFXManager *v45; // [sp+8h] [-B58h]
  bool v46; // [sp+Fh] [-B51h]
  idPLogScope v47; // [sp+60h] [-B00h] BYREF
  idVec3 *p_suppressionFirePoint; // [sp+68h] [-AF8h] BYREF
  idPresentablePtr<idPresentable> v49; // [sp+6Ch] [-AF4h] BYREF
  idVec3 v50; // [sp+70h] [-AF0h] BYREF
  idVec3 v51; // [sp+80h] [-AE0h] BYREF
  float v52; // [sp+8Ch] [-AD4h] BYREF
  idMat3 v53; // [sp+90h] [-AD0h] BYREF
  float v54; // [sp+B4h] [-AACh]
  float v55; // [sp+B8h] [-AA8h]
  idMat3 v56; // [sp+C0h] [-AA0h] BYREF
  blendParms_t v57[2]; // [sp+F0h] [-A70h] BYREF
  idFireParms v58; // [sp+120h] [-A40h] BYREF
  idFinishFireResults v59; // [sp+1C0h] [-9A0h] BYREF
  idTestFireResults v60; // [sp+210h] [-950h] BYREF

  RD_EventBegin(name: "idTurret::TurretFire");
  LODWORD(v2) = "idTurret::TurretFire";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v47, pl: &pLog, gMask: v2, label: v3);
  turretWeapon = this->turretWeapon;
  if ( turretWeapon == nullptr || !idWeapon::IsReadyToFire(this: turretWeapon) || this->currentState == TS_SILENCED )
  {
    idPLogScope::~idPLogScope(this: &v47);
LABEL_62:
    RD_EventEnd();
    return 0;
  }
  idAnimatedEntity::GetTagPosition(
    this,
    propIndex: this->propinfoIndex,
    tagIndex: this->muzzleTagIndex,
    origin: &v51,
    axis: &v56);
  idFireParms::idFireParms(this: &v58);
  memset(&v60, 0, sizeof(v60));
  v5 = &v59;
  v59.numProjectiles = 0;
  for ( i = 16; i != 0; --i )
  {
    v5 = (idFinishFireResults *)((char *)v5 + 4);
    v5->numProjectiles = 0;
  }
  currentState = this->currentState;
  *((_BYTE *)&v58 + 128) |= 0x20u;
  v58.addSpread = 3.0;
  if ( currentState == TS_SUPPRESSING_FIRE )
  {
    x = this->suppressionFirePoint.x;
    y = this->suppressionFirePoint.y;
    v49.spawnId = 0;
    z = this->suppressionFirePoint.z;
    p_suppressionFirePoint = &this->suppressionFirePoint;
    v50.x = x;
    v50.y = y;
    v50.z = z;
  }
  else
  {
    v11 = idEntityPtr<idEntity const>::operator->(this: &this->enemy);
    v12 = idAIWorldState::StateForEntity(this: &this->worldState, ent: v11);
    v13 = idEntityPtr<idEntity const>::operator->(this: &this->enemy);
    idAIWorldState::StateForEntity(this: &this->worldState, ent: v13);
    if ( v12 == nullptr )
      goto _M504968;
    idAIEntityState::GetAimPoint(this: v12, sense: AISENSE_SIGHT, aimPoint: AIMPOINT_BEST, point: &v50);
    Entity = idAIEntityState::GetEntity(this: v12);
    if ( Entity != nullptr )
    {
      p_suppressionFirePoint = (idVec3 *)Entity->entityNumber;
      this->lastTarget.spawnId.value = (*((_DWORD *)&gameLocal->__vftable + (_DWORD)p_suppressionFirePoint + 29755) << 13)
                                     | (unsigned int)p_suppressionFirePoint;
    }
    else
    {
      this->lastTarget.spawnId.value = 0x1FFF;
    }
    v15 = idAIEntityState::GetEntity(this: v12);
    presentable = v15->presentable;
    v17 = v15;
    if ( presentable != nullptr
      || (idEntity::InitPresentableInternal(this: v15), (presentable = v17->presentable) != nullptr) )
    {
      v49.spawnId = presentable->spawnId;
    }
    else
    {
      v49.spawnId = 0;
    }
  }
  v18 = v50.y;
  v19 = v50.z;
  p_suppressionFirePoint = &this->goalPos;
  this->goalPos.x = v50.x;
  this->goalPos.y = v18;
  this->goalPos.z = v19;
  if ( this->trackOnlyPlayer || this->usingFiringControl && !this->allowedToFire )
    goto _M504968;
  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  v21 = Player->GetFaction(this: Player);
  if ( idFaction::GetAttitudeTowards(this: &this->faction, otherFaction: v21) > ATTITUDE_NEUTRAL )
  {
    Damage_Impl = this->turretHealth.Damage_Impl;
    v52 = 0.0;
    ((void (__fastcall *)(idSimpleHealth *, int, int, float *, double))Damage_Impl)(
      a1: &this->turretHealth,
      a2: v22,
      a3: 1,
      a4: &v52,
      a5: 0.5);
    if ( this->turretHealth.IsDead_Impl(this: &this->turretHealth) && this->currentState != TS_DYING )
    {
      v53.mat[2].z = v56.mat[0].x * (float)-1.0;
      v55 = v56.mat[0].z * (float)-1.0;
      v54 = v56.mat[0].y * (float)-1.0;
      idTurret::SetDying(
        this,
        inflictor: this,
        attacker: this,
        damageDef: gameLocal->damageDecl,
        damageScale: 1.0,
        dir: (const idVec3 *)0x1AAB50,
        trace: (const trace_t *)&v53.mat[2].z,
        a8: 0);
    }
  }
  *(float *)&p_suppressionFirePoint = 360.0;
  if ( (unsigned __int8)idTurret::IsTargePosInFiringArc(
                          this,
                          mypos: &v51,
                          facing: v56.mat,
                          targetpos: &v50,
                          angle: (float *)&p_suppressionFirePoint) == 0
    || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->foundTargetTime
                                                                                               + this->foundTargetToFireTime
                                                                                               + this->foundTargetToActivateTime )
  {
    goto _M504968;
  }
  if ( this->shootAnimAlias.value != 0xFFFF )
  {
    if ( this->nextShotTimer < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
    {
      blendParms_t::blendParms_t(this: v57);
      blendParms_t::SetDurationMS(this: v57, ms: 0x50u);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v25 = this->GetAnimStack_2(this);
      if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                              this: &this->channelAnimator,
                              stack: v25,
                              ah: &this->shootAnimAlias,
                              curTime: GameMs,
                              rateScale: 1.0,
                              blendParms: v26,
                              blendOutDurationMS_: v57,
                              leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                              a9: nullptr) != 0 )
      {
        LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
        if ( LastPlayedLeaf != nullptr )
        {
          LastPlayedLeaf->initCounter = idGameTimeManager::GetGameMs(
                                          this: &clientGame->gameTimeManager,
                                          type: GAMETIME_SCALED)
                                      % 255;
          v28 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          this->nextShotTimer = idMD6Leaf::GetLength(
                                  this: LastPlayedLeaf,
                                  ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                                  a3: v30,
                                  a4: v29)
                              + v28;
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v58.targetList);
        idPLogScope::~idPLogScope(this: &v47);
        RD_EventEnd();
        return 1;
      }
    }
_M504968:
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v58.targetList);
    idPLogScope::~idPLogScope(this: &v47);
    goto LABEL_62;
  }
  if ( idWeapon::GetCurrentProjectileDecl(this: this->turretWeapon, secondaryAmmo: false)->hitscan )
  {
    v53.mat[0].x = v50.x - v51.x;
    v53.mat[0].z = v50.z - v51.z;
    v53.mat[0].y = v50.y - v51.y;
    idVec3::NormalizeFast(this: v53.mat);
    if ( turret_useDeferredFiring.valueInteger != 0 )
    {
      v32 = this->presentable;
      if ( v32 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v32 = this->presentable;
      }
      v33 = idVec3::ToMat3(this: (idVec3 *)v57, result: &v53);
      v34 = idPresentablePtr<idPresentableProjectile>::operator->(this: &v49);
      idWeapon::DeferredFire(
        this: this->turretWeapon,
        attacker: v32,
        target: v34,
        start: &v51,
        fireAxis: v33,
        fp: &v58,
        secondaryAmmo: false);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v58.targetList);
      idPLogScope::~idPLogScope(this: &v47);
      RD_EventEnd();
      return 1;
    }
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    v35 = idEntityPtr<idEntity const>::operator->(this: &this->lastTarget);
    v36 = v35;
    if ( v35->presentable != nullptr )
    {
      v37 = v35->presentable;
    }
    else
    {
      idEntity::InitPresentableInternal(this: v35);
      v37 = v36->presentable;
    }
    v38 = this->presentable;
    if ( v38 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v38 = this->presentable;
    }
LABEL_47:
    v39 = idWeapon::Fire(
            this: this->turretWeapon,
            attacker: v38,
            target: v37,
            start: &v51,
            fireAxis: &v56,
            fp: &v58,
            tfr: &v60,
            ffr: &v59,
            fxMgr: v45,
            secondaryAmmo: v46);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v58.targetList);
    idPLogScope::~idPLogScope(this: &v47);
    RD_EventEnd();
    return v39;
  }
  if ( (unsigned __int8)idTurret::CheckProjectileFire(this) == 0 )
    goto _M504968;
  v53.mat[1].y = v50.x - v51.x;
  v53.mat[2].x = v50.z - v51.z;
  v53.mat[1].z = v50.y - v51.y;
  idVec3::NormalizeFast(this: (idVec3 *)&v53.mat[1].y);
  if ( turret_useDeferredFiring.valueInteger == 0 )
  {
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    v43 = idEntityPtr<idEntity const>::operator->(this: &this->lastTarget);
    v44 = v43;
    if ( v43->presentable != nullptr )
    {
      v37 = v43->presentable;
    }
    else
    {
      idEntity::InitPresentableInternal(this: v43);
      v37 = v44->presentable;
    }
    v38 = this->presentable;
    if ( v38 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v38 = this->presentable;
    }
    goto LABEL_47;
  }
  v40 = this->presentable;
  if ( v40 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v40 = this->presentable;
  }
  v41 = idVec3::ToMat3(this: (idVec3 *)v57, result: (idMat3 *)&v53.mat[1].y);
  v42 = idPresentablePtr<idPresentableProjectile>::operator->(this: &v49);
  idWeapon::DeferredFire(
    this: this->turretWeapon,
    attacker: v40,
    target: v42,
    start: &v51,
    fireAxis: v41,
    fp: &v58,
    secondaryAmmo: false);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v58.targetList);
  idPLogScope::~idPLogScope(this: &v47);
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$504397
// EA  : 0x82CFAAD0
// RVA : 0x00CFAAD0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_504397()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2912 + 2836));
}


// ========================================================================
// __unwind$504398
// EA  : 0x82CFAAF8
// RVA : 0x00CFAAF8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_504398()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2912 + 96));
}


// ========================================================================
// __unwind$504399
// EA  : 0x82CFAB20
// RVA : 0x00CFAB20
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_504399()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2912 + 288));
}


// ========================================================================
// ?HandleState@idTurret@@AAAXAA_N@Z
// EA  : 0x82CFAB50
// RVA : 0x00CFAB50
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::HandleState(idTurret *this, bool *shouldShowLaser)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int value; // r9
  idEntityPtr<idEntity> *p_enemy; // r25
  idEntity *v8; // r3
  idEntity *v9; // r4
  idAIEntityState *v10; // r3
  int v11; // r9
  idAIEntityState *v12; // r23
  int v13; // r11
  idEntity *v14; // r3
  idEntity *v15; // r4
  int PreviousGameMs; // r29
  int v17; // r27
  idTurret::turretStates currentState; // r11
  idTurret::turretStates v19; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const char *str; // r5
  int GameMs; // r29
  const idAnimStack *v23; // r3
  __int64 v24; // r8
  int v25; // r28
  const idAnimStack *v26; // r3
  const blendParms_t *v27; // r7
  __int64 v28; // r8
  int v29; // r5
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idPhysics *Physics; // r3
  idRenderWorld *renderWorld; // r29
  idRenderWorld_vtbl *v33; // r28
  int v34; // r3
  int v35; // r11
  idTreeAnimator *v36; // r3
  idTreeAnimator *v37; // r3
  double x; // fp0
  double v39; // fp9
  double z; // fp11
  double v41; // fp13
  double y; // fp12
  idTreeAnimator *v43; // r3
  const char *v44; // r5
  idPhysics *v45; // r3
  idRenderWorld *v46; // r29
  idRenderWorld_vtbl *v47; // r27
  int v48; // r3
  idPhysics *v49; // r3
  const idDeclDamage *explodeDamage; // r29
  const idVec3 *v51; // r3
  idEntity *v52; // r3
  idEntity *v53; // r3
  char v54; // r29
  idBaseHealth *v55; // r3
  int v56; // r3
  float v57; // r11
  int v58; // r10
  bool v59; // cr34
  int v60; // r29
  idBaseHealth *v61; // r3
  double v62; // fp1
  bool v63; // r4
  double v64; // fp1
  __int64 v65; // r5
  unsigned int v66; // r5
  char v67; // r11
  idPhysics *v68; // r3
  idPhysics *v69; // r3
  int v70; // r3
  __int64 v71; // r9
  unsigned int v72; // r5
  double v73; // fp31
  int GameMsPerFrame; // r29
  int v75; // r28
  const idDeclParticle *destroyedParticle; // r30
  idRenderModelEffects *MergeBranch; // r3
  idPhysics *v78; // r3
  idRenderWorld *v79; // r29
  idRenderWorld_vtbl *v80; // r28
  int v81; // r3
  idPhysics *v82; // r3
  const idVec3 *v83; // r7
  double v84; // fp0
  idPhysics *v85; // r3
  float *v86; // r3
  char v87; // r11
  idTreeAnimator *v88; // r3
  const char *v89; // r5
  idPhysics *v90; // r3
  idRenderWorld *v91; // r29
  idRenderWorld_vtbl *v92; // r28
  int v93; // r3
  unsigned int v94; // r3
  __int64 v95; // r9
  double currentSearchAngle; // fp0
  double searchSpeed; // fp13
  double v98; // fp8
  double v99; // fp6
  double v100; // fp5
  double v101; // fp2
  idTreeAnimator *v102; // r3
  double v103; // fp10
  double v104; // fp9
  double v105; // fp8
  double v106; // fp7
  int v107; // r29
  int v108; // r3
  int muzzleTagIndex; // r5
  idPhysics *v110; // r3
  float *v111; // r3
  idPhysics *v112; // r3
  int v113; // r3
  idFinishFireResults *v114; // r11
  int i; // ctr
  idWeapon *turretWeapon; // r9
  idPresentable *presentable; // r11
  idPhysics *v118; // r3
  idRenderWorld *v119; // r29
  idRenderWorld_vtbl *v120; // r25
  int v121; // r3
  int v122; // r11
  int v123; // r29
  const idAnimStack *v124; // r3
  __int64 v125; // r8
  int v126; // r28
  const idAnimStack *v127; // r3
  const blendParms_t *v128; // r7
  __int64 v129; // r8
  int v130; // r5
  idMD6LeafPlay *v131; // r3
  idTreeAnimator *v132; // r3
  const char *v133; // r5
  int v134; // r10
  int v135; // r11
  int v136; // r28
  const idAnimStack *v137; // r3
  const blendParms_t *v138; // r7
  __int64 v139; // r11
  idPhysics *v140; // r3
  idRenderWorld *v141; // r29
  idRenderWorld_vtbl *v142; // r24
  int v143; // r3
  idTreeAnimator *v144; // r3
  const char *v145; // r5
  idVec3 *p_startPos; // r29
  __int64 v147; // r10
  idTreeAnimator *v148; // r3
  int searchDirScale; // r11
  double v150; // fp0
  double v151; // fp13
  double searchAngle; // fp12
  double v153; // fp8
  double v154; // fp31
  idPhysics *v155; // r3
  float *v156; // r3
  long double v157; // fp4
  double v158; // fp12
  double v159; // fp10
  double v160; // fp9
  long double v161; // fp2
  long double v162; // fp2
  double v163; // fp0
  long double v164; // fp2
  double v165; // fp31
  long double v166; // fp2
  double v167; // fp30
  long double v168; // fp2
  double v169; // fp7
  double v170; // fp12
  double v171; // fp5
  double v172; // fp3
  double heightOffFloor; // fp11
  double v174; // fp10
  double v175; // fp9
  double v176; // fp13
  idTreeAnimator *v177; // r3
  const char *v178; // r5
  int v179; // r29
  const idAnimStack *v180; // r3
  const blendParms_t *v181; // r7
  idPhysics *v182; // r3
  idRenderWorld *v183; // r29
  idRenderWorld_vtbl *v184; // r28
  int v185; // r3
  idTreeAnimator *v186; // r3
  const char *v187; // r5
  double startSuppressingFire; // fp0
  double timeSuppressed; // fp12
  idTreeAnimator *v190; // r3
  const char *v191; // r5
  idPhysics *v192; // r3
  idRenderWorld *v193; // r29
  idRenderWorld_vtbl *v194; // r27
  int v195; // r3
  idTreeAnimator *v196; // r3
  const char *v197; // r5
  idPhysics *v198; // r3
  idRenderWorld *v199; // r29
  idRenderWorld_vtbl *v200; // r28
  int v201; // r3
  idTreeAnimator *v202; // r3
  const char *v203; // r5
  int v204; // r25
  const idAnimStack *v205; // r3
  int v206; // r28
  const idAnimStack *v207; // r3
  const blendParms_t *v208; // r7
  __int64 v209; // r8
  int v210; // r5
  idMD6LeafPlay *v211; // r3
  idPhysics *v212; // r3
  idFXManager *v213; // [sp+8h] [-C48h]
  int v214; // [sp+Ch] [-C44h]
  int v215; // [sp+10h] [-C40h]
  int v216; // [sp+14h] [-C3Ch]
  int v217; // [sp+18h] [-C38h]
  int v218; // [sp+1Ch] [-C34h]
  int v219; // [sp+20h] [-C30h]
  int v220; // [sp+24h] [-C2Ch]
  int v221; // [sp+28h] [-C28h]
  int v222; // [sp+2Ch] [-C24h]
  int v223; // [sp+30h] [-C20h]
  int v224; // [sp+34h] [-C1Ch]
  int v225; // [sp+38h] [-C18h]
  int v226; // [sp+3Ch] [-C14h]
  int v227; // [sp+40h] [-C10h]
  int v228; // [sp+44h] [-C0Ch]
  int v229; // [sp+48h] [-C08h]
  int v230; // [sp+4Ch] [-C04h]
  int v231; // [sp+50h] [-C00h]
  idVec3 v232; // [sp+60h] [-BF0h] BYREF
  blendParms_t v233[2]; // [sp+70h] [-BE0h] BYREF
  idMat3 v234; // [sp+98h] [-BB8h] BYREF
  float v235; // [sp+BCh] [-B94h]
  float v236; // [sp+C0h] [-B90h]
  float v237[4]; // [sp+D0h] [-B80h] BYREF
  idMat3 v238; // [sp+E0h] [-B70h] BYREF
  idMat3 v239; // [sp+110h] [-B40h] BYREF
  idPLogScope v240; // [sp+138h] [-B18h] BYREF
  idMat3 v241; // [sp+140h] [-B10h] BYREF
  idMat3 v242; // [sp+170h] [-AE0h] BYREF
  idVec3 v243[2]; // [sp+198h] [-AB8h] BYREF
  idMat3 v244; // [sp+1B0h] [-AA0h] BYREF
  idFinishFireResults v245; // [sp+1E0h] [-A70h] BYREF
  idFireParms v246; // [sp+230h] [-A20h] BYREF
  idTestFireResults v247; // [sp+2D0h] [-980h] BYREF

  RD_EventBegin(name: "idTurret::HandleState");
  LODWORD(v4) = "idTurret::HandleState";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v240, pl: &pLog, gMask: v4, label: v5);
  value = this->enemy.spawnId.value;
  p_enemy = &this->enemy;
  LODWORD(v232.x) = &this->enemy;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr )
      v9 = idEntity::CastTo(c: v8);
    else
      v9 = nullptr;
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idAIWorldState::StateForEntity(this: &this->worldState, ent: v9);
  v11 = p_enemy->spawnId.value;
  v12 = v10;
  v13 = p_enemy->spawnId.value & 0x1FFF;
  LODWORD(v232.x) = &this->enemy;
  if ( gameLocal->spawnIds.ptr[v13] == v11 >> 13 && (v14 = gameLocal->entities.ptr[v13]) != nullptr )
    v15 = idEntity::CastTo(c: v14);
  else
    v15 = nullptr;
  idAIWorldState::StateForEntity(this: &this->worldState, ent: v15);
  PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - PreviousGameMs;
  currentState = this->currentState;
  this->stateTimer -= v17;
  if ( currentState == TS_WARMUP
    || currentState == TS_NORMAL
    || currentState == TS_SUPPRESSING_FIRE
    || currentState == TS_SEARCHING
    || currentState == TS_WOBBLY
    || currentState == TS_HAYWIRE )
  {
    if ( !this->isClipModelEnabled )
    {
      this->clipModel.EnableClip(this: &this->clipModel);
      this->isClipModelEnabled = true;
    }
  }
  else if ( this->isClipModelEnabled )
  {
    this->clipModel.DisableClip(this: &this->clipModel);
    this->isClipModelEnabled = false;
  }
  *shouldShowLaser = false;
  v19 = this->currentState;
  switch ( v19 )
  {
    case TS_WARNING:
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
         - this->foundTargetTime > this->foundTargetToActivateTime )
      {
        TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( TreeAnimatorFromPresentable != nullptr )
        {
          str = this->nonSearchMeshKit.str;
          if ( str != nullptr && *str != 0 )
            idTreeAnimator::HideKitsExcept(this: TreeAnimatorFromPresentable, kitType: MESH_KIT_HEADS, name: str);
          this->currentState = TS_WARMUP;
        }
        if ( this->canGoInactive )
        {
          blendParms_t::blendParms_t(this: v233);
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v23 = this->GetAnimStack_2(this);
          LODWORD(v24) = v233;
          idAnimator_Channel::CycleAnim(
            this: &this->movingHoldAnimator,
            stack: v23,
            ah: &this->aquiredMhAnimAlias,
            curTime: GameMs,
            rateScale: 1.0,
            leafStarted: v24,
            a7: nullptr);
          v25 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v26 = this->GetAnimStack_2(this);
          if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                                  this: &this->channelAnimator,
                                  stack: v26,
                                  ah: &this->acquiredTargetAnimAlias,
                                  curTime: v25,
                                  rateScale: 1.0,
                                  blendParms: v27,
                                  blendOutDurationMS_: v233,
                                  leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                                  a9: nullptr) != 0 )
          {
            LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
            if ( LastPlayedLeaf != nullptr )
            {
              this->stateTimer = idMD6Leaf::GetLength(
                                   this: LastPlayedLeaf,
                                   ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                                   a3: v29,
                                   a4: v28);
              this->slinecedJointRot.mat[0].x = mat3_identity.mat[0].x;
              this->slinecedJointRot.mat[0].y = mat3_identity.mat[0].y;
              this->slinecedJointRot.mat[0].z = mat3_identity.mat[0].z;
              LODWORD(v232.x) = &this->slinecedJointPitch.mat[2];
              this->slinecedJointRot.mat[1] = mat3_identity.mat[1];
              this->slinecedJointRot.mat[2] = mat3_identity.mat[2];
              this->slinecedJointPitch = mat3_identity;
            }
          }
        }
      }
      break;
    case TS_WARMUP:
      if ( turret_debug.valueInteger != 0 )
      {
        Physics = idEntity::GetPhysics(this);
        renderWorld = clientGame->renderWorld;
        v33 = renderWorld->__vftable;
        v34 = (int)Physics->GetOrigin(this: Physics, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v33->DebugText)(
          a1: renderWorld,
          a2: "TS_WARMUP",
          a3: v34,
          a4: v33->DebugText,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
      if ( this->SilencedIdleAnimAlias.value != 0xFFFF && this->UnSilencedAnimAlias.value != 0xFFFF )
      {
        idTurret::SetModelSpaceJointDir(
          this,
          joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
          axisModel: &this->slinecedJointRot);
        v35 = this->jointPitch.value;
        if ( v35 != this->jointRotation.value && v35 != -1 )
          idTurret::SetModelSpaceJointDir(
            this,
            joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value,
            axisModel: &this->slinecedJointPitch);
      }
      if ( this->stateTimer <= 0 )
      {
        if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                                this,
                                propIndex: this->propinfoIndex,
                                tagIndex: this->muzzleTagIndex,
                                origin: &this->startPos,
                                axis: &v241) == 0
          && (unsigned __int16)this->jointRotation.value < 0x8000u )
        {
          v36 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
          idTreeAnimator::GetWorldSpaceJointTransform(
            this: v36,
            pose: (animationPose_t)0,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
            origin: &this->startPos,
            axis: &v241);
          v37 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
          idTreeAnimator::GetWorldSpaceJointTransform(
            this: v37,
            pose: (animationPose_t)0,
            jointIndex: nullptr,
            origin: v243,
            axis: &v241);
        }
        x = v241.mat[0].x;
        v39 = (float)(this->startPos.x + v241.mat[0].x);
        z = this->startPos.z;
        v41 = v241.mat[0].z;
        y = v241.mat[0].y;
        this->goalPos.y = this->startPos.y + v241.mat[0].y;
        this->goalPos.z = (float)z + (float)v41;
        LODWORD(v232.x) = &this->goalPos;
        this->goalPos.x = v39;
        this->startForwardDir.x = x;
        this->startForwardDir.y = y;
        this->startForwardDir.z = v41;
        idVec3::NormalizeFast(this: &this->startForwardDir);
        v43 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( v43 != nullptr )
        {
          v44 = this->nonSearchMeshKit.str;
          if ( v44 != nullptr && *v44 != 0 )
            idTreeAnimator::HideKitsExcept(this: v43, kitType: MESH_KIT_HEADS, name: v44);
          this->currentState = TS_NORMAL;
        }
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_WEAPON_AMBIENT,
          shader: this->soundDoneInit,
          soundShaderFlags: SSF_PLAY_ONCE,
          peerMask: 0xFFu);
      }
      break;
    case TS_DYING:
      if ( turret_debug.valueInteger != 0 )
      {
        v45 = idEntity::GetPhysics(this);
        v46 = clientGame->renderWorld;
        v47 = v46->__vftable;
        v48 = (int)v45->GetOrigin(this: v45, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v47->DebugText)(
          a1: v46,
          a2: "TS_DYING",
          a3: v48,
          a4: v47->DebugText,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
      if ( this->stateTimer <= 0 )
      {
        if ( this->randomFire )
        {
          this->turretHealth.components[0].type = SIMPLE_HEALTH_HITPOINTS;
          *(float *)&v233[0].parms.destStartFrame = 0.0;
          *(float *)&v233[0].parms.sourceStartFrame = 0.0;
          this->turretHealth.components[0].max = 0.0;
          this->turretHealth.components[0].cur = 0.0;
          this->turretHealth.killThreshold = 0.0;
          this->turretHealth.killingBlowDamage = 0.0;
          this->turretHealth.accumulatedDamageFrame = -1;
          this->turretHealth.accumulatedFrameDamage = 0.0;
          this->turretHealth.isDead = false;
          idTurret::SetDying(
            this,
            inflictor: nullptr,
            attacker: nullptr,
            damageDef: nullptr,
            damageScale: 0.0,
            dir: (const idVec3 *)0xFFFFFFFF,
            trace: (const trace_t *)&vec3_origin,
            a8: 0);
        }
        else if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
        {
          if ( this->explodeParticle != nullptr && this->explodeDamage != nullptr )
          {
            v49 = idEntity::GetPhysics(this);
            explodeDamage = this->explodeDamage;
            v51 = v49->GetOrigin(this: v49, a2: 0);
            idGameLocal::RadiusDamage(
              this: gameLocal,
              origin: v51,
              inflictor: this,
              attacker: this,
              damageDef: explodeDamage,
              dmgPower: 1.0);
          }
          if ( !this->dontRemoveAfterDying )
            idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 3000);
        }
        if ( idEntityPtr<idEntity const>::operator->(this: &this->flare) != nullptr )
        {
          v52 = idEntityPtr<idEntity const>::operator->(this: &this->flare);
          idEntity::Unbind(this: v52);
          v53 = idEntityPtr<idEntity const>::operator->(this: &this->flare);
          idEventReceiver::PostEventMS(this: v53, ev: &EV_Remove, time: 0);
          LODWORD(v232.x) = &this->flare;
          this->flare.spawnId.value = 0x1FFF;
        }
        idEntity::BecomeInactive(this, flags: 7);
        idTurret::StopTurnSound(this);
        break;
      }
      if ( this->randomFire || this->destroyedParticle == nullptr )
        break;
      v54 = 0;
      if ( this->destroyedParticleRateCurve != nullptr )
      {
        v60 = idAccolade::Count(this: &clientGame->gameTimeManager);
        v61 = this->GetHealthComponent_2(this);
        v62 = ((double (__fastcall *)(idBaseHealth *))v61->GetBaseHealthRatio_Impl)(a1: v61);
        v64 = idLookupTable::TableLookup(this: this->destroyedParticleRateCurve->table, time: v62, fastSearch: v63);
        LODWORD(v65) = this->destroyedParticleRate;
        LODWORD(v232.y) = (int)(float)((float)v65 * (float)v64);
        v57 = v232.y;
        if ( LODWORD(v232.y) == 0 )
          goto LABEL_73;
        v58 = __ROL4__(v60, 1);
        v59 = v60 % SLODWORD(v232.y) == 0;
      }
      else
      {
        v55 = this->GetHealthComponent_2(this);
        if ( ((double (__fastcall *)(idBaseHealth *))v55->GetBaseHealthRatio_Impl)(a1: v55) > this->destroyedParticleRateStart )
          goto LABEL_75;
        v56 = idAccolade::Count(this: &clientGame->gameTimeManager);
        v57 = *(float *)&this->destroyedParticleRate;
        if ( v57 == 0.0 )
          goto LABEL_73;
        v58 = __ROL4__(v56, 1);
        v59 = v56 % SLODWORD(v57) == 0;
      }
      __twllei(LODWORD(v57), 0);
      v66 = LODWORD(v57) & ~(v58 - 1);
      v67 = 0;
      __twlgei(v66, 0xFFFFFFFF);
      if ( !v59 )
      {
LABEL_74:
        v54 = v67;
LABEL_75:
        if ( v54 != 0 )
        {
          if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                                  this,
                                  propIndex: this->propinfoIndex,
                                  tagIndex: this->muzzleTagIndex,
                                  origin: v234.mat,
                                  axis: &v238) == 0 )
          {
            v68 = idEntity::GetPhysics(this);
            v234.mat[0] = *v68->GetOrigin(this: v68, a2: 0);
            v69 = idEntity::GetPhysics(this);
            v70 = (int)v69->GetAxis(this: v69, a2: 0);
            v238.mat[0].x = *(float *)v70;
            v238.mat[0].y = *(float *)(v70 + 4);
            LODWORD(v232.x) = v70 + 24;
            v238.mat[0].z = *(float *)(v70 + 8);
            v238.mat[1] = *(idVec3 *)(v70 + 12);
            v238.mat[2] = *(idVec3 *)(v70 + 24);
          }
          v232.x = NAN;
          HIDWORD(v71) = "DistToTarget: %f dist: %f \n";
          v72 = 1664525 * clientGame->random.seed;
          clientGame->random.seed = v72 + 1013904223;
          LODWORD(v71) = ((v72 + 1013904223) >> 10) & 0x7FFF;
          *(_QWORD *)&v233[0].parms.srcAnim = v71;
          v73 = (float)((float)v71 * (float)0.000030518509);
          GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                             this: &clientGame->gameTimeManager,
                             type: GAMETIME_SCALED);
          v75 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          destroyedParticle = this->destroyedParticle;
          MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
          idRenderModelEffects::AddParticles(
            this: MergeBranch,
            particle: destroyedParticle,
            systemStartTime: v75,
            gameMsPerFrame: GameMsPerFrame,
            diversity: v73,
            origin: &v232,
            axis: &v234,
            velocity: v238.mat,
            color: &vec3_origin.x,
            a10: (int)v213,
            a11: v214,
            a12: v215,
            a13: v216,
            a14: v217,
            a15: v218,
            a16: v219,
            a17: v220,
            a18: v221,
            a19: v222,
            a20: v223,
            a21: v224,
            a22: v225,
            a23: v226,
            a24: v227,
            a25: v228,
            a26: v229,
            a27: v230,
            a28: v231,
            a29: (unsigned int *)&v232);
        }
        break;
      }
LABEL_73:
      v67 = 1;
      goto LABEL_74;
    case TS_WOBBLY:
      if ( turret_debug.valueInteger != 0 )
      {
        v78 = idEntity::GetPhysics(this);
        v79 = clientGame->renderWorld;
        v80 = v79->__vftable;
        v81 = (int)v78->GetOrigin(this: v78, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, char *, idColor *, int, _DWORD, _DWORD, double))v80->DebugText)(
          a1: v79,
          a2: "TS_WOBBLY",
          a3: v81,
          a4: &aAvSsobjectVCom[20],
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
      *shouldShowLaser = true;
      v82 = idEntity::GetPhysics(this);
      v84 = v82->GetAxis(this: v82, a2: 0)->mat[2].z;
      if ( this->stateTimer > 0 || v84 > 0.69999999 )
      {
        if ( v84 > 0.69999999 )
        {
          v85 = idEntity::GetPhysics(this);
          v86 = (float *)v85->GetOrigin(this: v85, a2: 0);
          if ( this->lastPos.x != *v86 || this->lastPos.y != v86[1] || (v87 = 1, this->lastPos.z != v86[2]) )
            v87 = 0;
          if ( v87 != 0 )
          {
            v88 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
            if ( v88 != nullptr )
            {
              v89 = this->nonSearchMeshKit.str;
              if ( v89 != nullptr && *v89 != 0 )
                idTreeAnimator::HideKitsExcept(this: v88, kitType: MESH_KIT_HEADS, name: v89);
              this->currentState = TS_NORMAL;
            }
            this->stateTimer = 0;
          }
        }
        break;
      }
LABEL_117:
      idTurret::SetDying(
        this,
        inflictor: nullptr,
        attacker: nullptr,
        damageDef: nullptr,
        damageScale: 0.0,
        dir: v83,
        trace: (const trace_t *)&vec3_origin,
        a8: 0);
      break;
    case TS_HAYWIRE:
      if ( turret_debug.valueInteger != 0 )
      {
        v90 = idEntity::GetPhysics(this);
        v91 = clientGame->renderWorld;
        v92 = v91->__vftable;
        v93 = (int)v90->GetOrigin(this: v90, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v92->DebugText)(
          a1: v91,
          a2: "TS_HAYWIRE",
          a3: v93,
          a4: v92->DebugText,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
      v94 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v94;
      LODWORD(v95) = (v94 >> 10) & 0x7FFF;
      HIDWORD(v95) = (unsigned __int64)(1374389535LL * (int)v95) >> 32;
      if ( (unsigned int)v95 % 0x64 < 0x19 )
        this->searchDirScale = -this->searchDirScale;
      currentSearchAngle = this->currentSearchAngle;
      searchSpeed = this->searchSpeed;
      LODWORD(v95) = this->searchDirScale;
      *(_QWORD *)&v233[0].parms.srcAnim = v95;
      LODWORD(v232.x) = &this->startPos;
      this->currentSearchAngle = (float)((float)v95 * (float)searchSpeed) + (float)currentSearchAngle;
      v98 = this->startForwardDir.y;
      v99 = this->startPos.y;
      v100 = this->startPos.x;
      v101 = (float)(this->startForwardDir.x * (float)10.0);
      this->goalPos.z = this->startPos.z + (float)(this->startForwardDir.z * (float)10.0);
      this->goalPos.x = (float)v100 + (float)v101;
      this->goalPos.y = (float)v99 + (float)((float)v98 * (float)10.0);
      if ( (unsigned __int16)this->jointRotation.value < 0x8000u )
      {
        v102 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v102,
          pose: (animationPose_t)0,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
          origin: (idVec3 *)&v234.mat[2].z,
          axis: &v242);
        v103 = (float)(v242.mat[0].z * (float)10.0);
        v104 = (float)(v242.mat[0].y * (float)10.0);
        v105 = v236;
        v106 = v235;
        LODWORD(v232.x) = &this->goalPos;
        this->goalPos.x = v234.mat[2].z + (float)(v242.mat[0].x * (float)10.0);
        this->goalPos.z = (float)v105 + (float)v103;
        this->goalPos.y = (float)v106 + (float)v104;
      }
      if ( this->randomFireTime < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
      {
        v107 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        v108 = idRandom2::RandomInt(this: &clientGame->random, min: 100, max: 300);
        muzzleTagIndex = this->muzzleTagIndex;
        this->randomFireTime = v107 + v108;
        if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                                this,
                                propIndex: this->propinfoIndex,
                                tagIndex: muzzleTagIndex,
                                origin: (idVec3 *)&v234.mat[1].y,
                                axis: &v239) == 0 )
        {
          v110 = idEntity::GetPhysics(this);
          v111 = (float *)v110->GetOrigin(this: v110, a2: 0);
          v234.mat[1].y = *v111;
          v234.mat[1].z = v111[1];
          v234.mat[2].x = v111[2];
          v112 = idEntity::GetPhysics(this);
          v113 = (int)v112->GetAxis(this: v112, a2: 0);
          v239.mat[0].x = *(float *)v113;
          LODWORD(v232.x) = v113 + 24;
          v239.mat[0].y = *(float *)(v113 + 4);
          v239.mat[0].z = *(float *)(v113 + 8);
          v239.mat[1] = *(idVec3 *)(v113 + 12);
          v239.mat[2] = *(idVec3 *)(v113 + 24);
        }
        idFireParms::idFireParms(this: &v246);
        memset(&v247, 0, sizeof(v247));
        v114 = &v245;
        v245.numProjectiles = 0;
        for ( i = 16; i != 0; --i )
        {
          v114 = (idFinishFireResults *)((char *)v114 + 4);
          v114->numProjectiles = 0;
        }
        turretWeapon = this->turretWeapon;
        *((_BYTE *)&v246 + 128) |= 0x20u;
        v246.addSpread = 1.0;
        if ( turretWeapon != nullptr )
        {
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          idWeapon::Fire(
            this: this->turretWeapon,
            attacker: presentable,
            target: nullptr,
            start: (const idVec3 *)&v234.mat[1].y,
            fireAxis: &v239,
            fp: &v246,
            tfr: &v247,
            ffr: &v245,
            fxMgr: v213,
            secondaryAmmo: v214);
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v246.targetList);
      }
      if ( this->stateTimer <= 0 )
      {
        this->haywireOnKnockdownChance = 0;
        goto LABEL_117;
      }
      break;
    case TS_SILENCED:
      if ( turret_debug.valueInteger != 0 )
      {
        v118 = idEntity::GetPhysics(this);
        v119 = clientGame->renderWorld;
        v120 = v119->__vftable;
        v121 = (int)v118->GetOrigin(this: v118, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v120->DebugText)(
          a1: v119,
          a2: "TS_SILENCED",
          a3: v121,
          a4: v120->DebugText,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
      idTurret::SetModelSpaceJointDir(
        this,
        joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
        axisModel: &this->slinecedJointRot);
      v122 = this->jointPitch.value;
      if ( v122 != this->jointRotation.value && v122 != -1 )
        idTurret::SetModelSpaceJointDir(
          this,
          joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value,
          axisModel: &this->slinecedJointPitch);
      if ( this->stateTimer > 0 )
      {
        v134 = this->SilencedIdleAnimAlias.value;
        v135 = this->slinecedIntoTime - v17;
        this->slinecedIntoTime = v135;
        if ( v134 != 0xFFFF && v135 <= 0 )
        {
          blendParms_t::blendParms_t(this: v233);
          v136 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v137 = this->GetAnimStack_2(this);
          idAnimator_Channel::PlayAnim(
            this: &this->channelAnimator,
            stack: v137,
            ah: &this->SilencedIdleAnimAlias,
            curTime: v136,
            rateScale: 1.0,
            blendParms: v138,
            blendOutDurationMS_: v233,
            leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
            a9: nullptr);
        }
      }
      else
      {
        if ( this->UnSilencedAnimAlias.value != 0xFFFF )
        {
          blendParms_t::blendParms_t(this: v233);
          v123 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v124 = this->GetAnimStack_2(this);
          LODWORD(v125) = v233;
          idAnimator_Channel::CycleAnim(
            this: &this->movingHoldAnimator,
            stack: v124,
            ah: &this->aquiredMhAnimAlias,
            curTime: v123,
            rateScale: 1.0,
            leafStarted: v125,
            a7: nullptr);
          v126 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v127 = this->GetAnimStack_2(this);
          if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                                  this: &this->channelAnimator,
                                  stack: v127,
                                  ah: &this->UnSilencedAnimAlias,
                                  curTime: v126,
                                  rateScale: 1.0,
                                  blendParms: v128,
                                  blendOutDurationMS_: v233,
                                  leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                                  a9: nullptr) != 0 )
          {
            v131 = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
            if ( v131 != nullptr )
              this->stateTimer = idMD6Leaf::GetLength(
                                   this: v131,
                                   ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                                   a3: v130,
                                   a4: v129);
          }
        }
        v132 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( v132 != nullptr )
        {
          v133 = this->nonSearchMeshKit.str;
          if ( v133 != nullptr && *v133 != 0 )
            idTreeAnimator::HideKitsExcept(this: v132, kitType: MESH_KIT_HEADS, name: v133);
          this->currentState = TS_WARMUP;
        }
      }
      break;
    case TS_SEARCHING:
      HIDWORD(v139) = &turret_debug;
      if ( turret_debug.valueInteger != 0 )
      {
        v140 = idEntity::GetPhysics(this);
        v141 = clientGame->renderWorld;
        v142 = v141->__vftable;
        v143 = (int)v140->GetOrigin(this: v140, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v142->DebugText)(
          a1: v141,
          a2: "TS_SEARCHING",
          a3: v143,
          a4: v142->DebugText,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
      LODWORD(v139) = v17;
      *shouldShowLaser = true;
      *(_QWORD *)&v233[0].parms.srcAnim = v139;
      this->timeSearched = (float)v139 + this->timeSearched;
      if ( idEntityPtr<idEntity const>::operator->(this: &this->enemy) != nullptr
        && v12 != nullptr
        && (unsigned __int8)idAIEntityState::IsVisible(this: v12) != 0 )
      {
        v144 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( v144 != nullptr )
        {
          v145 = this->nonSearchMeshKit.str;
          if ( v145 != nullptr && *v145 != 0 )
            idTreeAnimator::HideKitsExcept(this: v144, kitType: MESH_KIT_HEADS, name: v145);
          this->currentState = TS_NORMAL;
        }
        this->foundTargetTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_WEAPON_AMBIENT,
          shader: this->soundTargetAquired,
          soundShaderFlags: SSF_PLAY_ONCE,
          peerMask: 0xFFu);
      }
      p_startPos = &this->startPos;
      if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                              this,
                              propIndex: this->propinfoIndex,
                              tagIndex: this->muzzleTagIndex,
                              origin: &this->startPos,
                              axis: &v244) == 0
        && (unsigned __int16)this->jointRotation.value < 0x8000u )
      {
        v148 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v148,
          pose: (animationPose_t)0,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
          origin: &this->startPos,
          axis: &v244);
      }
      searchDirScale = this->searchDirScale;
      v150 = this->currentSearchAngle;
      v151 = this->searchSpeed;
      LODWORD(v147) = searchDirScale;
      searchAngle = this->searchAngle;
      v153 = (float)((float)(this->searchSpeed * (float)v147) + this->currentSearchAngle);
      *(_QWORD *)&v233[0].parms.srcAnim = v147;
      this->currentSearchAngle = (float)((float)v151 * (float)v147) + (float)v150;
      v232.x = (float)((float)v151 * (float)v147) + (float)v150;
      if ( __fabs(v153) > searchAngle )
        this->searchDirScale = -searchDirScale;
      v154 = (float)(this->currentSearchAngle * idMath::M_DEG2RAD);
      v155 = idEntity::GetPhysics(this);
      v156 = (float *)v155->GetAxis(this: v155, a2: 0);
      v158 = *v156;
      v159 = v156[1];
      v160 = (float)((float)(v156[1] * v156[1]) + (float)(*v156 * *v156));
      v232.x = v156[1];
      if ( __fsqrts(v160) <= 0.00000011920929 )
      {
        *((double *)&v164 + 1) = v156[4];
        *(double *)&v164 = v156[3];
        v162 = atan2(v: v164, u: v157);
        v163 = (float)((float)v154 - (float)*(double *)&v162);
      }
      else
      {
        *((double *)&v161 + 1) = v158;
        *(double *)&v161 = v159;
        v162 = atan2(v: v161, u: v157);
        v163 = (float)((float)*(double *)&v162 + (float)v154);
      }
      v165 = v163;
      *(double *)&v162 = v163;
      v166 = sin(x: v162);
      v167 = (float)*(double *)&v166;
      *(double *)&v166 = v165;
      v168 = cos(x: v166);
      *(float *)&v233[0].parms.srcAnim = *(double *)&v168;
      *(float *)&v233[0].parms.destAnim = v167;
      *(float *)&v233[0].parms.sourceStartFrame = 0.0;
      idVec3::NormalizeFast(this: (idVec3 *)v233);
      v169 = (float)(*(float *)&v233[0].parms.sourceStartFrame * this->maxRange);
      v170 = this->startPos.z;
      v171 = (float)(*(float *)&v233[0].parms.destAnim * this->maxRange);
      v172 = (float)(*(float *)&v233[0].parms.srcAnim * this->maxRange);
      heightOffFloor = this->heightOffFloor;
      v174 = this->startPos.y;
      v175 = p_startPos->x;
      LODWORD(v232.x) = &this->goalPos;
      this->goalPos.y = (float)v174 + (float)v171;
      this->goalPos.x = (float)v175 + (float)v172;
      this->goalPos.z = (float)((float)v170 + (float)v169) - (float)heightOffFloor;
      if ( turret_debugTurning.valueInteger != 0 )
      {
        v176 = this->startPos.z;
        v237[1] = this->startPos.y;
        v237[0] = p_startPos->x;
        v237[2] = v176;
        v237[3] = 0.5;
        LODWORD(v232.x) = &this->startPos;
        clientGame->renderWorld->DebugSphere(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorWhite,
          a3: (const idSphere *)v237,
          a4: 12,
          a5: 0,
          a6: false);
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorWhite,
          a3: &this->startPos,
          a4: &this->goalPos,
          a5: 0,
          a6: false);
      }
      if ( this->canGoInactive
        && this->startSearchTime > 0.0
        && (float)(this->timeSearched + this->startSearchTime) > (double)(float)((float)(this->searchTime * (float)1000.0)
                                                                               + this->startSearchTime) )
      {
        v177 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( v177 != nullptr )
        {
          v178 = this->nonSearchMeshKit.str;
          if ( v178 != nullptr && *v178 != 0 )
            idTreeAnimator::HideKitsExcept(this: v177, kitType: MESH_KIT_HEADS, name: v178);
          this->currentState = TS_INACTIVE;
        }
        blendParms_t::blendParms_t(this: v233);
        v179 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v180 = this->GetAnimStack_2(this);
        idAnimator_Channel::PlayAnim(
          this: &this->channelAnimator,
          stack: v180,
          ah: &this->lostTargetAnimAlias,
          curTime: v179,
          rateScale: 1.0,
          blendParms: v181,
          blendOutDurationMS_: v233,
          leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
          a9: nullptr);
        idAnimator_Channel::ClearAnimator(this: &this->movingHoldAnimator);
      }
      if ( this->currentState != TS_SEARCHING )
        this->startSearchTime = -1.0;
      break;
    case TS_SUPPRESSING_FIRE:
      if ( turret_debug.valueInteger != 0 )
      {
        v182 = idEntity::GetPhysics(this);
        v183 = clientGame->renderWorld;
        v184 = v183->__vftable;
        v185 = (int)v182->GetOrigin(this: v182, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v184->DebugText)(
          a1: v183,
          a2: "TS_SUPRESSING_FIRE",
          a3: v185,
          a4: v184->DebugText,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
      if ( !this->isStatic )
        *shouldShowLaser = true;
      if ( v12 != nullptr && (unsigned __int8)idAIEntityState::IsVisible(this: v12) != 0 )
      {
        v186 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( v186 != nullptr )
        {
          v187 = this->nonSearchMeshKit.str;
          if ( v187 != nullptr && *v187 != 0 )
            idTreeAnimator::HideKitsExcept(this: v186, kitType: MESH_KIT_HEADS, name: v187);
          this->currentState = TS_NORMAL;
        }
      }
      else
      {
        startSuppressingFire = this->startSuppressingFire;
        timeSuppressed = this->timeSuppressed;
        *(_QWORD *)&v233[0].parms.srcAnim = __PAIR64__(0x82000000, v17);
        this->timeSuppressed = (float)__SPAIR64__(0x82000000, v17) + (float)timeSuppressed;
        if ( (startSuppressingFire <= 0.0
           || (float)((float)startSuppressingFire + (float)((float)__SPAIR64__(0x82000000, v17) + (float)timeSuppressed)) <= (double)(float)((float)(this->suppresingFireTime * (float)1000.0) + (float)startSuppressingFire))
          && idEntityPtr<idEntity const>::operator->(this: &this->lastTarget) != nullptr )
        {
          this->isFiring = idTurret::TurretFire(this);
        }
        else
        {
          v190 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
          if ( v190 != nullptr )
          {
            v191 = this->searchMeshKit.str;
            if ( v191 != nullptr && *v191 != 0 )
              idTreeAnimator::HideKitsExcept(this: v190, kitType: MESH_KIT_HEADS, name: v191);
            this->currentState = TS_SEARCHING;
          }
          idTurret::RestartSearch(this);
        }
      }
      if ( this->currentState != TS_SUPPRESSING_FIRE )
        this->startSuppressingFire = -1.0;
      break;
    case TS_INACTIVE:
      if ( turret_debug.valueInteger != 0 )
      {
        v192 = idEntity::GetPhysics(this);
        v193 = clientGame->renderWorld;
        v194 = v193->__vftable;
        v195 = (int)v192->GetOrigin(this: v192, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v194->DebugText)(
          a1: v193,
          a2: "TS_INACTIVE",
          a3: v195,
          a4: v194->DebugText,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
      this->turretFOV = this->startFOV;
      if ( idEntityPtr<idEntity const>::operator->(this: &this->enemy) != nullptr
        && v12 != nullptr
        && (unsigned __int8)idAIEntityState::IsVisible(this: v12) != 0 )
      {
        v196 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( v196 != nullptr )
        {
          v197 = this->nonSearchMeshKit.str;
          if ( v197 != nullptr && *v197 != 0 )
            idTreeAnimator::HideKitsExcept(this: v196, kitType: MESH_KIT_HEADS, name: v197);
          this->currentState = TS_WARNING;
        }
        this->foundTargetTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_WEAPON_AMBIENT,
          shader: this->soundTargetAquired,
          soundShaderFlags: SSF_PLAY_ONCE,
          peerMask: 0xFFu);
      }
      break;
    case TS_DISABLED:
      if ( this->stopThinkTime > 0 )
      {
        if ( this->stopThinkTime < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
        {
          idEntity::BecomeInactive(this, flags: 1);
          idEntity::BecomeInactive(this, flags: 2);
          v212 = idEntity::GetPhysics(this);
          v212->DisableClip(this: v212);
        }
      }
      else
      {
        v204 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v205 = this->GetAnimStack_2(this);
        if ( (unsigned __int8)idAnimator_Channel::IsAnimPlaying(
                                this: &this->channelAnimator,
                                stack: v205,
                                ah: &this->lostTargetAnimAlias,
                                curTime: v204) == 0 )
        {
          blendParms_t::blendParms_t(this: v233);
          v206 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v207 = this->GetAnimStack_2(this);
          if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                                  this: &this->channelAnimator,
                                  stack: v207,
                                  ah: &this->lostTargetAnimAlias,
                                  curTime: v206,
                                  rateScale: 1.0,
                                  blendParms: v208,
                                  blendOutDurationMS_: v233,
                                  leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                                  a9: nullptr) != 0 )
          {
            v211 = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
            if ( v211 != nullptr )
              this->stopThinkTime = idMD6Leaf::GetLength(
                                      this: v211,
                                      ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                                      a3: v210,
                                      a4: v209);
            idAnimator_Channel::ClearAnimator(this: &this->movingHoldAnimator);
          }
        }
      }
      break;
    default:
      if ( turret_debug.valueInteger != 0 )
      {
        v198 = idEntity::GetPhysics(this);
        v199 = clientGame->renderWorld;
        v200 = v199->__vftable;
        v201 = (int)v198->GetOrigin(this: v198, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v200->DebugText)(
          a1: v199,
          a2: "TS_NORMAL",
          a3: v201,
          a4: v200->DebugText,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
      *shouldShowLaser = this->showLaserDuringAttack;
      if ( idEntityPtr<idEntity const>::operator->(this: &this->enemy) == nullptr )
      {
        v202 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        if ( v202 != nullptr )
        {
          v203 = this->searchMeshKit.str;
          if ( v203 != nullptr && *v203 != 0 )
            idTreeAnimator::HideKitsExcept(this: v202, kitType: MESH_KIT_HEADS, name: v203);
          this->currentState = TS_SEARCHING;
        }
        idTurret::RestartSearch(this);
      }
      break;
  }
  idPLogScope::~idPLogScope(this: &v240);
  RD_EventEnd();
}


// ========================================================================
// __unwind$505009
// EA  : 0x82CFC74C
// RVA : 0x00CFC74C
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_505009()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 3152 + 3028));
}


// ========================================================================
// __unwind$505010
// EA  : 0x82CFC774
// RVA : 0x00CFC774
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_505010()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 3152 + 312));
}


// ========================================================================
// __unwind$505012
// EA  : 0x82CFC79C
// RVA : 0x00CFC79C
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_505012()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3152 + 560));
}


// ========================================================================
// ?HandleRotation@idTurret@@AAA_NABVidVec3@@00_N@Z
// EA  : 0x82CFC7D0
// RVA : 0x00CFC7D0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

int __fastcall idTurret::HandleRotation(
        idTurret *this,
        const idVec3 *TargetPos,
        const idVec3 *firing,
        const idVec3 *muzzleDir,
        bool blendOut)
{
  unsigned __int64 v9; // r6
  const char *v10; // r7
  double y; // fp13
  double z; // fp12
  double v13; // fp10
  double v14; // fp9
  idTreeAnimator *TreeAnimatorFromPresentable; // r26
  idPresentable *presentable; // r3
  int v17; // r28
  int value; // r11
  int v19; // r10
  double v20; // fp0
  float *v21; // r11
  double v22; // fp13
  double v23; // fp11
  double v24; // fp9
  double v25; // fp8
  idQuat *v26; // r3
  const idIndex<short,enum invalidJointIndex_t> *v27; // r5
  double v28; // fp0
  float *v29; // r11
  double v30; // fp13
  double v31; // fp11
  double v32; // fp9
  double v33; // fp8
  long double v34; // fp2
  int *v35; // r10
  float *v36; // r11
  int j; // ctr
  long double v38; // fp2
  idRenderWorld *v39; // r3
  idRenderWorld *v40; // r3
  idRenderWorld *v41; // r3
  idRenderWorld *v42; // r3
  idRenderWorld *v43; // r3
  double v44; // fp13
  double v45; // fp12
  double v46; // fp11
  idPresentable *v47; // r11
  idPresentable *v48; // r3
  float *v49; // r10
  int *v50; // r11
  int k; // ctr
  idPresentableTurret *v52; // r3
  __int64 v53; // r10
  BOOL v54; // r28
  idMat3 *v55; // r3
  const idIndex<short,enum invalidJointIndex_t> *v56; // r5
  double v57; // fp4
  double v58; // fp3
  double v59; // fp2
  idPresentable *v60; // r11
  idPresentable *v61; // r3
  float *v62; // r10
  int *v63; // r11
  int m; // ctr
  idPresentableTurret *v65; // r3
  __int64 v66; // r10
  double v67; // fp0
  float *p_deferredAxis; // r11
  double v69; // fp13
  double v70; // fp11
  double v71; // fp9
  double v72; // fp8
  idTurret::turretStates currentState; // r11
  double x; // fp12
  double v75; // fp13
  double v76; // fp0
  double v77; // fp9
  double v78; // fp10
  double v79; // fp11
  const idIndex<short,enum invalidJointIndex_t> *v80; // r5
  double v81; // fp30
  double v82; // fp29
  double v83; // fp31
  float *p_axis; // r11
  double v85; // fp5
  double v86; // fp3
  double v87; // fp0
  double v88; // fp13
  long double v89; // fp2
  long double v90; // fp2
  idRenderWorld *v91; // r3
  idRenderWorld *v92; // r3
  idRenderWorld *v93; // r3
  idQuat *p_lastYawRot; // r29
  idPresentable *v95; // r11
  idPresentable *v96; // r3
  float *p_w; // r10
  int *v98; // r11
  int i; // ctr
  idPresentableTurret *v100; // r3
  __int64 v101; // r10
  bool v102; // r3
  double v103; // fp13
  double v104; // fp12
  double v105; // fp11
  int v107; // [sp+8h] [-348h]
  __int64 v108; // [sp+10h] [-340h]
  __int64 v109; // [sp+18h] [-338h]
  __int64 v110; // [sp+20h] [-330h]
  __int64 v111; // [sp+28h] [-328h]
  __int64 v112; // [sp+30h] [-320h]
  __int64 v113; // [sp+38h] [-318h]
  __int64 v114; // [sp+40h] [-310h]
  __int64 v115; // [sp+48h] [-308h]
  idMat3 v116; // [sp+50h] [-300h] BYREF
  float v117; // [sp+74h] [-2DCh]
  float v118; // [sp+78h] [-2D8h]
  idVec3 v119; // [sp+7Ch] [-2D4h] BYREF
  idVec3 v120; // [sp+88h] [-2C8h] BYREF
  idQuat v121; // [sp+A0h] [-2B0h] BYREF
  idQuat v122; // [sp+B0h] [-2A0h] BYREF
  idQuat v123; // [sp+C0h] [-290h] BYREF
  idMat3 v124; // [sp+D0h] [-280h] BYREF
  idVec3 v125; // [sp+F8h] [-258h] BYREF
  idVec3 v126[2]; // [sp+108h] [-248h] BYREF
  idMat3 v127; // [sp+120h] [-230h] BYREF
  float v128; // [sp+144h] [-20Ch]
  float v129; // [sp+148h] [-208h]
  float v130; // [sp+14Ch] [-204h] BYREF
  idQuat v131; // [sp+150h] [-200h] BYREF
  float v132; // [sp+160h] [-1F0h]
  float v133; // [sp+164h] [-1ECh]
  float v134; // [sp+168h] [-1E8h]
  float v135; // [sp+16Ch] [-1E4h]
  float v136; // [sp+170h] [-1E0h]
  int v137; // [sp+17Ch] [-1D4h] BYREF
  idMat3 v138; // [sp+180h] [-1D0h] BYREF
  idVec3 v139; // [sp+1A8h] [-1A8h] BYREF
  idVec3 v140; // [sp+1B8h] [-198h] BYREF
  idVec3 v141; // [sp+1C8h] [-188h] BYREF
  float v142[4]; // [sp+1E0h] [-170h] BYREF
  float v143[4]; // [sp+1F0h] [-160h] BYREF
  idVec3 v144; // [sp+200h] [-150h] BYREF
  idPLogScope v145; // [sp+210h] [-140h] BYREF
  int v146; // [sp+21Ch] [-134h] BYREF
  idMat3 v147; // [sp+220h] [-130h] BYREF
  int v148; // [sp+24Ch] [-104h] BYREF
  idMat3 v149; // [sp+250h] [-100h] BYREF
  idMat3 v150; // [sp+280h] [-D0h] BYREF
  idMat3 v151[2]; // [sp+2B0h] [-A0h] BYREF

  RD_EventBegin(name: "idTurret::HandleRotation");
  LODWORD(v9) = "idTurret::HandleRotation";
  HIDWORD(v9) = 2;
  idPLogScope::idPLogScope(this: &v145, pl: &pLog, gMask: v9, label: v10);
  if ( turret_debugTurning.valueInteger != 0 )
  {
    y = TargetPos->y;
    z = TargetPos->z;
    v143[0] = TargetPos->x;
    v143[1] = y;
    v143[3] = 0.5;
    v143[2] = z;
    clientGame->renderWorld->DebugSphere(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idSphere *)v143,
      a4: 12,
      a5: 0,
      a6: false);
    v13 = firing->y;
    v14 = firing->z;
    v142[0] = firing->x;
    v142[3] = 0.5;
    v142[1] = v13;
    v142[2] = v14;
    clientGame->renderWorld->DebugSphere(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idSphere *)v142,
      a4: 12,
      a5: 0,
      a6: false);
  }
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  v17 = 0;
  value = this->jointPitch.value;
  if ( value < 0 || (v19 = this->jointRotation.value) < 0 || value == v19 )
  {
    if ( (unsigned __int16)this->jointRotation.value < 0x8000u )
    {
      v122.x = 0.0;
      v122.y = 0.0;
      v122.z = 0.0;
      v122.w = 1.0;
      if ( !blendOut )
      {
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: TreeAnimatorFromPresentable,
          pose: (animationPose_t)0,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
          origin: v126,
          axis: &v124);
        v67 = (float)(TargetPos->z - v126[0].z);
        p_deferredAxis = (float *)&TreeAnimatorFromPresentable->deferredAxis;
        if ( !TreeAnimatorFromPresentable->useDeferredPosition )
          p_deferredAxis = (float *)&TreeAnimatorFromPresentable->g.axis;
        v70 = p_deferredAxis[2];
        v71 = (float)((float)(p_deferredAxis[3] * (float)(TargetPos->x - v126[0].x))
                    + (float)(p_deferredAxis[4] * (float)(TargetPos->y - v126[0].y)));
        v72 = (float)((float)(*p_deferredAxis * (float)(TargetPos->x - v126[0].x))
                    + (float)(p_deferredAxis[1] * (float)(TargetPos->y - v126[0].y)));
        v69 = p_deferredAxis[5];
        v116.mat[0].z = (float)(p_deferredAxis[8] * (float)(TargetPos->z - v126[0].z))
                      + (float)((float)(p_deferredAxis[6] * (float)(TargetPos->x - v126[0].x))
                              + (float)(p_deferredAxis[7] * (float)(TargetPos->y - v126[0].y)));
        v116.mat[0].y = (float)((float)v69 * (float)v67) + (float)v71;
        v116.mat[0].x = (float)((float)v70 * (float)v67) + (float)v72;
        idVec3::ProjectOntoPlane(this: v116.mat, normal: &vec3_up, overBounce: 1.0);
        idVec3::NormalizeFast(this: v116.mat);
        currentState = this->currentState;
        x = vec3_up.x;
        v75 = vec3_up.y;
        v76 = vec3_up.z;
        v77 = v116.mat[0].x;
        v78 = v116.mat[0].y;
        v79 = v116.mat[0].z;
        v120.x = vec3_up.x;
        v120.y = vec3_up.y;
        v120.z = vec3_up.z;
        v116.mat[2].z = v116.mat[0].x;
        v117 = v116.mat[0].y;
        v118 = v116.mat[0].z;
        if ( currentState == TS_SEARCHING )
        {
          v116.mat[1].y = this->currentSearchAngle * idMath::M_DEG2RAD;
          idVec3::RotateSelf(
            this: (idVec3 *)&v116.mat[2].z,
            axis: &v120,
            angle: (idTypesafeNumber<float,enum RadiansUnique_t> *)&v116.mat[1].y);
          v76 = v120.z;
          v75 = v120.y;
          x = v120.x;
          v79 = v118;
          v78 = v117;
          v77 = v116.mat[2].z;
        }
        v80 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value;
        v119.z = (float)((float)x * (float)v78) - (float)((float)v75 * (float)v77);
        v119.y = (float)((float)v76 * (float)v77) - (float)((float)x * (float)v79);
        v119.x = (float)((float)v75 * (float)v79) - (float)((float)v76 * (float)v78);
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: TreeAnimatorFromPresentable,
          pose: (animationPose_t)0,
          jointIndex: v80,
          origin: &v139,
          axis: &v150);
        idAnimatedEntity::GetTagPosition(
          this,
          propIndex: this->propinfoIndex,
          tagIndex: this->muzzleTagIndex,
          origin: &v140,
          axis: v151);
        v81 = (float)(TargetPos->z - v139.z);
        v82 = (float)(TargetPos->y - v139.y);
        v83 = (float)(TargetPos->x - v139.x);
        if ( this->currentState == TS_NORMAL && idEntityPtr<idEntity const>::operator->(this: &this->enemy) != nullptr )
        {
          v81 = (float)(TargetPos->z - v140.z);
          v82 = (float)(TargetPos->y - v140.y);
          v83 = (float)(TargetPos->x - v140.x);
        }
        p_axis = (float *)&TreeAnimatorFromPresentable->deferredAxis;
        if ( !TreeAnimatorFromPresentable->useDeferredPosition )
          p_axis = (float *)&TreeAnimatorFromPresentable->g.axis;
        v85 = p_axis[8];
        v86 = *p_axis;
        v87 = (float)((float)(p_axis[6] * (float)v83) + (float)((float)v82 * p_axis[7]));
        v88 = (float)((float)((float)v82 * p_axis[1]) + (float)((float)v81 * p_axis[2]));
        v116.mat[0].y = (float)(p_axis[3] * (float)v83)
                      + (float)((float)((float)v82 * p_axis[4]) + (float)((float)v81 * p_axis[5]));
        v116.mat[0].z = (float)((float)v81 * (float)v85) + (float)v87;
        v116.mat[0].x = (float)((float)v86 * (float)v83) + (float)v88;
        idVec3::ProjectOntoPlane(this: v116.mat, normal: &v119, overBounce: 1.0);
        idVec3::NormalizeFast(this: v116.mat);
        *((double *)&v89 + 1) = (float)((float)(v116.mat[0].z * v120.z) + (float)(v116.mat[0].y * v120.y));
        *(double *)&v89 = (float)((float)(v116.mat[0].x * v120.x)
                                + (float)((float)(v116.mat[0].z * v120.z) + (float)(v116.mat[0].y * v120.y)));
        v90 = acos(x: v89);
        idMat3::RotateSelf(
          this: (idMat3 *)&v116.mat[2].z,
          axis: &v119,
          angle: (float)-(float)((float)((float)3.1415927 * (float)0.5) - (float)*(double *)&v90));
        v122 = *idMat3::ToQuat(this: &v116, result: (idQuat *)&v116.mat[2].z);
        if ( turret_debugTurning.valueInteger != 0 )
        {
          v91 = gameLocal->GetRenderWorld(this: gameLocal);
          v91->DebugAxis_2(this: v91, a2: v126, a3: &v124, a4: 0, a5: false);
          v92 = gameLocal->GetRenderWorld(this: gameLocal);
          v92->DebugPoint(this: v92, a2: (const idVec4 *)&idColor::colorRed, a3: TargetPos, a4: 0, a5: true);
          v93 = gameLocal->GetRenderWorld(this: gameLocal);
          v93->DebugLine(this: v93, a2: (const idVec4 *)&idColor::colorRed, a3: v126, a4: TargetPos, a5: 0, a6: true);
        }
      }
      p_lastYawRot = &this->lastYawRot;
      idQuat::Slerp(this: (idQuat *)&v127.mat[1].y, from: &this->lastYawRot, to: &v122, t: this->turnSpeed);
      idQuat::FixDenormals(this: (idQuat *)&v127.mat[1].y);
      idQuat::ToMat3(this: (idQuat *)&v147, result: (idMat3 *)&v127.mat[1].y);
      idTreeAnimator::SetJointAxis(
        this: TreeAnimatorFromPresentable,
        pose: (animationPose_t)0,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
        type: JOINTMOD_MODEL_OVERRIDE,
        axis: &v147);
      v95 = this->presentable;
      if ( v95 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v95 = this->presentable;
      }
      if ( v95->GetTurretInterface(this: v95) != nullptr )
      {
        if ( this->presentable == nullptr )
          idEntity::InitPresentableInternal(this);
        v96 = this->presentable;
        p_w = &v123.w;
        v98 = &v146;
        for ( i = 9; i != 0; --i )
          *(_DWORD *)++p_w = *++v98;
        v100 = v96->GetTurretInterface(this: v96);
        HIDWORD(v101) = __ROL4__(LODWORD(v124.mat[2].z), 32);
        idPresentableTurret::ApplyJointMod(
          this: v100,
          axis: __SPAIR64__(LODWORD(v124.mat[0].z), LODWORD(v124.mat[1].y)),
          a3: *(__int64 *)&v124.mat[2].x,
          a4: v101,
          a5: v107,
          a6: v108,
          a7: v109,
          a8: v110,
          a9: v111,
          a10: v112,
          a11: v113,
          a12: v114,
          a13: v115);
      }
      v102 = idQuat::Compare(this: p_lastYawRot, a: &v122, epsilon: 0.0099999998);
      v103 = v127.mat[1].z;
      v104 = v127.mat[2].x;
      v105 = v127.mat[2].y;
      p_lastYawRot->x = v127.mat[1].y;
      v17 = (_cntlzw(v102) & 0x20) != 0;
      this->lastYawRot.y = v103;
      this->lastYawRot.z = v104;
      this->lastYawRot.w = v105;
    }
  }
  else
  {
    v121.x = 0.0;
    v121.y = 0.0;
    v121.z = 0.0;
    v121.w = 1.0;
    v123.x = 0.0;
    v123.y = 0.0;
    v123.z = 0.0;
    v123.w = 1.0;
    if ( !blendOut )
    {
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: TreeAnimatorFromPresentable,
        pose: (animationPose_t)0,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
        origin: &v125,
        axis: &v147);
      v20 = (float)(TargetPos->z - v125.z);
      v21 = (float *)&TreeAnimatorFromPresentable->deferredAxis;
      if ( !TreeAnimatorFromPresentable->useDeferredPosition )
        v21 = (float *)&TreeAnimatorFromPresentable->g.axis;
      v23 = v21[2];
      v24 = (float)((float)(v21[3] * (float)(TargetPos->x - v125.x)) + (float)(v21[4] * (float)(TargetPos->y - v125.y)));
      v25 = (float)((float)(*v21 * (float)(TargetPos->x - v125.x)) + (float)(v21[1] * (float)(TargetPos->y - v125.y)));
      v22 = v21[5];
      v116.mat[0].z = (float)(v21[8] * (float)(TargetPos->z - v125.z))
                    + (float)((float)(v21[6] * (float)(TargetPos->x - v125.x))
                            + (float)(v21[7] * (float)(TargetPos->y - v125.y)));
      v116.mat[0].y = (float)((float)v22 * (float)v20) + (float)v24;
      v116.mat[0].x = (float)((float)v23 * (float)v20) + (float)v25;
      idVec3::ProjectOntoPlane(this: v116.mat, normal: &vec3_up, overBounce: 1.0);
      idVec3::NormalizeFast(this: v116.mat);
      v134 = vec3_up.x;
      v135 = vec3_up.y;
      v136 = vec3_up.z;
      v131.x = v116.mat[0].x;
      v131.y = v116.mat[0].y;
      v131.z = v116.mat[0].z;
      v132 = (float)(vec3_up.z * v116.mat[0].x) - (float)(vec3_up.x * v116.mat[0].z);
      v133 = (float)(vec3_up.x * v116.mat[0].y) - (float)(vec3_up.y * v116.mat[0].x);
      v131.w = (float)(vec3_up.y * v116.mat[0].z) - (float)(vec3_up.z * v116.mat[0].y);
      v26 = idMat3::ToQuat(this: &v116, result: &v131);
      v27 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value;
      v121 = *v26;
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: TreeAnimatorFromPresentable,
        pose: (animationPose_t)0,
        jointIndex: v27,
        origin: &v144,
        axis: &v124);
      idAnimatedEntity::GetTagPosition(
        this,
        propIndex: this->propinfoIndex,
        tagIndex: this->muzzleTagIndex,
        origin: &v141,
        axis: &v150);
      v28 = (float)(TargetPos->z - v141.z);
      v29 = (float *)&TreeAnimatorFromPresentable->deferredAxis;
      if ( !TreeAnimatorFromPresentable->useDeferredPosition )
        v29 = (float *)&TreeAnimatorFromPresentable->g.axis;
      v31 = v29[2];
      v32 = (float)((float)(v29[3] * (float)(TargetPos->x - v141.x)) + (float)(v29[4] * (float)(TargetPos->y - v141.y)));
      v33 = (float)((float)(*v29 * (float)(TargetPos->x - v141.x)) + (float)(v29[1] * (float)(TargetPos->y - v141.y)));
      v30 = v29[5];
      v116.mat[0].z = (float)(v29[8] * (float)(TargetPos->z - v141.z))
                    + (float)((float)(v29[6] * (float)(TargetPos->x - v141.x))
                            + (float)(v29[7] * (float)(TargetPos->y - v141.y)));
      v116.mat[0].y = (float)((float)v30 * (float)v28) + (float)v32;
      v116.mat[0].x = (float)((float)v31 * (float)v28) + (float)v33;
      idVec3::ProjectOntoPlane(this: v116.mat, normal: (const idVec3 *)&v131.w, overBounce: 1.0);
      idVec3::NormalizeFast(this: v116.mat);
      v35 = &v148;
      v36 = &v130;
      for ( j = 9; j != 0; --j )
        *++v35 = *(_DWORD *)++v36;
      *(double *)&v34 = (float)((float)(v135 * v116.mat[0].y)
                              + (float)((float)(v134 * v116.mat[0].x) + (float)(v136 * v116.mat[0].z)));
      v38 = acos(x: v34);
      idMat3::RotateSelf(
        this: &v149,
        axis: &v149.mat[1],
        angle: (float)-(float)((float)((float)3.1415927 * (float)0.5) - (float)*(double *)&v38));
      v123 = *idMat3::ToQuat(this: &v116, result: (idQuat *)&v149);
      if ( turret_debugTurning.valueInteger != 0 )
      {
        v39 = gameLocal->GetRenderWorld(this: gameLocal);
        v39->DebugAxis_2(this: v39, a2: &v125, a3: &v147, a4: 0, a5: false);
        v40 = gameLocal->GetRenderWorld(this: gameLocal);
        v40->DebugAxis_2(this: v40, a2: &v144, a3: &v124, a4: 0, a5: false);
        v41 = gameLocal->GetRenderWorld(this: gameLocal);
        v41->DebugPoint(this: v41, a2: (const idVec4 *)&idColor::colorRed, a3: TargetPos, a4: 0, a5: true);
        v42 = gameLocal->GetRenderWorld(this: gameLocal);
        v42->DebugLine(this: v42, a2: (const idVec4 *)&idColor::colorRed, a3: &v125, a4: TargetPos, a5: 0, a6: true);
        v43 = gameLocal->GetRenderWorld(this: gameLocal);
        v43->DebugLine(this: v43, a2: (const idVec4 *)&idColor::colorRed, a3: &v144, a4: TargetPos, a5: 0, a6: true);
      }
    }
    idQuat::Slerp(this: (idQuat *)&v127, from: &this->lastYawRot, to: &v121, t: this->turnSpeed);
    idQuat::FixDenormals(this: (idQuat *)&v127);
    idQuat::ToMat3(this: (idQuat *)&v138, result: &v127);
    idTreeAnimator::SetJointAxis(
      this: TreeAnimatorFromPresentable,
      pose: (animationPose_t)0,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
      type: JOINTMOD_MODEL_OVERRIDE,
      axis: &v138);
    v44 = v127.mat[0].y;
    v45 = v127.mat[0].z;
    v46 = v127.mat[1].x;
    this->lastYawRot.x = v127.mat[0].x;
    this->lastYawRot.y = v44;
    this->lastYawRot.z = v45;
    this->lastYawRot.w = v46;
    v47 = this->presentable;
    if ( v47 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v47 = this->presentable;
    }
    if ( v47->GetTurretInterface(this: v47) != nullptr )
    {
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      v48 = this->presentable;
      v49 = &v123.w;
      v50 = &v137;
      for ( k = 9; k != 0; --k )
        *(_DWORD *)++v49 = *++v50;
      v52 = v48->GetTurretInterface(this: v48);
      HIDWORD(v53) = __ROL4__(LODWORD(v124.mat[2].z), 32);
      idPresentableTurret::ApplyJointMod(
        this: v52,
        axis: __SPAIR64__(LODWORD(v124.mat[0].z), LODWORD(v124.mat[1].y)),
        a3: *(__int64 *)&v124.mat[2].x,
        a4: v53,
        a5: v107,
        a6: v108,
        a7: v109,
        a8: v110,
        a9: v111,
        a10: v112,
        a11: v113,
        a12: v114,
        a13: v115);
    }
    v54 = (_cntlzw(idQuat::Compare(this: &this->lastYawRot, a: &v121, epsilon: 0.0099999998)) & 0x20) != 0;
    idQuat::Slerp(this: (idQuat *)&v127.mat[2].z, from: &this->lastPitchRot, to: &v123, t: this->turnSpeed);
    idQuat::FixDenormals(this: (idQuat *)&v127.mat[2].z);
    v55 = idQuat::ToMat3(this: (idQuat *)&v150, result: (idMat3 *)&v127.mat[2].z);
    v138.mat[0].x = v55->mat[0].x;
    LODWORD(v116.mat[1].y) = &v55->mat[1];
    v56 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value;
    v138.mat[0].y = v55->mat[0].y;
    v138.mat[0].z = v55->mat[0].z;
    LODWORD(v116.mat[1].y) = &v55->mat[2];
    v138.mat[1] = v55->mat[1];
    v138.mat[2] = v55->mat[2];
    idTreeAnimator::SetJointAxis(
      this: TreeAnimatorFromPresentable,
      pose: (animationPose_t)0,
      jointIndex: v56,
      type: JOINTMOD_MODEL_OVERRIDE,
      axis: &v138);
    v57 = v128;
    v58 = v129;
    v59 = v130;
    this->lastPitchRot.x = v127.mat[2].z;
    this->lastPitchRot.y = v57;
    this->lastPitchRot.z = v58;
    this->lastPitchRot.w = v59;
    v60 = this->presentable;
    if ( v60 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v60 = this->presentable;
    }
    if ( v60->GetTurretInterface(this: v60) != nullptr )
    {
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      v61 = this->presentable;
      v62 = &v123.w;
      v63 = &v137;
      for ( m = 9; m != 0; --m )
        *(_DWORD *)++v62 = *++v63;
      v65 = v61->GetTurretInterface(this: v61);
      HIDWORD(v66) = __ROL4__(LODWORD(v124.mat[2].z), 32);
      idPresentableTurret::ApplyJointMod(
        this: v65,
        axis: __SPAIR64__(LODWORD(v124.mat[0].z), LODWORD(v124.mat[1].y)),
        a3: *(__int64 *)&v124.mat[2].x,
        a4: v66,
        a5: v107,
        a6: v108,
        a7: v109,
        a8: v110,
        a9: v111,
        a10: v112,
        a11: v113,
        a12: v114,
        a13: v115);
    }
    v17 = (_cntlzw(idQuat::Compare(this: &this->lastPitchRot, a: &v123, epsilon: 0.0099999998)) & 0x20) != 0 || v54;
  }
  idPLogScope::~idPLogScope(this: &v145);
  RD_EventEnd();
  return v17;
}


// ========================================================================
// __unwind$506666_0
// EA  : 0x82CFD518
// RVA : 0x00CFD518
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_506666_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 848 + 724));
}


// ========================================================================
// __unwind$506667
// EA  : 0x82CFD540
// RVA : 0x00CFD540
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_506667()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 848 + 528));
}


// ========================================================================
// ?Think@idTurret@@UAAXXZ
// EA  : 0x82CFD570
// RVA : 0x00CFD570
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::Think(idTurret *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idWeapon *turretWeapon; // r3
  idFinishFireResults *v5; // r11
  int i; // ctr
  idPresentable *presentable; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPhysics *Physics; // r3
  double maxRange; // fp29
  idRenderWorld_vtbl *v11; // r29
  int v12; // r3
  idPhysics *v13; // r3
  double v14; // fp29
  idRenderWorld_vtbl *v15; // r29
  int v16; // r3
  idPhysics *v17; // r3
  double v18; // fp29
  idRenderWorld_vtbl *v19; // r29
  int v20; // r3
  idPlayer *DebugPlayer; // r3
  idPhysics *v22; // r3
  idPhysics *v23; // r3
  idPhysics *v24; // r3
  idPresentable *v25; // r28
  idPhysics *v26; // r29
  int v27; // r3
  int v28; // r10
  int v29; // r9
  int v30; // r8
  int v31; // r7
  int v32; // r6
  int v33; // r5
  idEntity *v34; // r3
  idEntity *v35; // r3
  int GameMs; // r28
  const idAnimStack *v37; // r3
  __int64 v38; // r8
  int v39; // r27
  int v40; // r28
  idEntity *v41; // r29
  idEventArg *v42; // r3
  BOOL startOff; // r11
  idEntityPtr<idEntity> *p_enemy; // r29
  idTurret::turretStates currentState; // r28
  char v46; // r26
  idFaction *v47; // r21
  const idEntity *v48; // r3
  const idSpawnId *v49; // r20
  const idSpawnId *v50; // r3
  idTurret::turretStates v51; // r11
  const idDeclTrackingParms *declTrackingParms; // r10
  int value; // r9
  int v54; // r8
  BOOL useOrgHeadingAsSearchDir; // r7
  double minRange; // fp13
  idMat3 *p_spawnOrientation; // r11
  float x; // r9
  float y; // r8
  float z; // r10
  bool trackOnlyPlayer; // r7
  idTargetInfo *v62; // r11
  idEntity *Entity; // r3
  idPlayer *v64; // r3
  idPlayer *v65; // r3
  idVehicle_Car *v66; // r3
  idVehicle_Car *v67; // r3
  const idEntity *v68; // r3
  idAIEntityState *v69; // r29
  char v70; // r3
  idTurret::turretStates v71; // r11
  idTreeAnimator *v72; // r3
  const char *str; // r5
  idTreeAnimator *v74; // r3
  const char *v75; // r5
  idPhysics *v76; // r3
  float *v77; // r3
  double v78; // fp13
  idTurret::turretStates v79; // r11
  unsigned __int8 v80; // r11
  bool v81; // zf
  int v82; // r28
  char v83; // r29
  int v84; // r3
  const idSoundShader *v85; // r5
  idTurret::turretStates v86; // r11
  idTurret::turretStates v87; // r11
  unsigned __int8 v88; // r11
  int v89; // r27
  int alarmSkin; // r28
  idPresentable *v91; // r11
  unsigned __int8 *v92; // r3
  void (*Show)(void); // r10
  const idSoundShader *soundIdle; // r5
  idPhysics *v95; // r3
  idBounds *v96; // r3
  idAngles *v97; // r3
  double maxFireAngle; // fp13
  double v99; // fp31
  double v100; // fp11
  idVec3 *v101; // r3
  double v102; // fp2
  double v103; // fp1
  double v104; // fp30
  idVec3 *v105; // r3
  double v106; // fp0
  double v107; // fp2
  idAngles *v108; // r3
  double v109; // fp10
  double v110; // fp30
  double yaw; // fp0
  idVec3 *v112; // r3
  double v113; // fp0
  double v114; // fp12
  double v115; // fp5
  double v116; // fp4
  double v117; // fp31
  idVec3 *v118; // r3
  double v119; // fp12
  double v120; // fp11
  double v121; // fp4
  double v122; // fp3
  int v123; // [sp+8h] [-CA8h]
  int v124; // [sp+Ch] [-CA4h]
  int v125; // [sp+10h] [-CA0h]
  int v126; // [sp+14h] [-C9Ch]
  int v127; // [sp+18h] [-C98h]
  int v128; // [sp+1Ch] [-C94h]
  int v129; // [sp+20h] [-C90h]
  int v130; // [sp+24h] [-C8Ch]
  int v131; // [sp+28h] [-C88h]
  int v132; // [sp+2Ch] [-C84h]
  int v133; // [sp+30h] [-C80h]
  int v134; // [sp+34h] [-C7Ch]
  int v135; // [sp+38h] [-C78h]
  int v136; // [sp+3Ch] [-C74h]
  int v137; // [sp+40h] [-C70h]
  int v138; // [sp+44h] [-C6Ch]
  int v139; // [sp+48h] [-C68h]
  int v140; // [sp+4Ch] [-C64h]
  int v141; // [sp+50h] [-C60h]
  bool v142; // [sp+60h] [-C50h] BYREF
  idSpawnId v143; // [sp+64h] [-C4Ch] BYREF
  idSpawnId v144; // [sp+68h] [-C48h] BYREF
  idVec3 v145; // [sp+70h] [-C40h] BYREF
  idVec3 v146; // [sp+80h] [-C30h] BYREF
  idVec3 v147; // [sp+90h] [-C20h] BYREF
  idVec3 v148; // [sp+A0h] [-C10h] BYREF
  idPLogScope v149; // [sp+B0h] [-C00h] BYREF
  idTargetFilter v150; // [sp+B8h] [-BF8h] BYREF
  float v151[4]; // [sp+C0h] [-BF0h] BYREF
  float v152[4]; // [sp+D0h] [-BE0h] BYREF
  float v153[4]; // [sp+E0h] [-BD0h] BYREF
  float v154[4]; // [sp+F0h] [-BC0h] BYREF
  float v155[4]; // [sp+100h] [-BB0h] BYREF
  float v156[4]; // [sp+110h] [-BA0h] BYREF
  idAILogic v157; // [sp+120h] [-B90h] BYREF
  idTargetSelector v158; // [sp+140h] [-B70h] BYREF
  int v159; // [sp+150h] [-B60h]
  int v160; // [sp+154h] [-B5Ch]
  float v161; // [sp+158h] [-B58h]
  float v162; // [sp+15Ch] [-B54h]
  float v163; // [sp+160h] [-B50h]
  float v164; // [sp+164h] [-B4Ch]
  float v165; // [sp+168h] [-B48h]
  float maxTurnAngle; // [sp+16Ch] [-B44h]
  bool v167; // [sp+170h] [-B40h]
  idVec3 v168[2]; // [sp+178h] [-B38h] BYREF
  idTargetList v169; // [sp+190h] [-B20h] BYREF
  idMat3 v170; // [sp+1D0h] [-AE0h] BYREF
  idMat3 v171; // [sp+200h] [-AB0h] BYREF
  idFinishFireResults v172; // [sp+230h] [-A80h] BYREF
  idFireParms v173; // [sp+280h] [-A30h] BYREF
  idTestFireResults v174; // [sp+320h] [-990h] BYREF

  RD_EventBegin(name: "idTurret::Think");
  LODWORD(v2) = "idTurret::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v149, pl: &pLog, gMask: v2, label: v3);
  if ( (unsigned __int8)idEntity::UpdateDormant(this) != 0 )
    goto LABEL_126;
  turretWeapon = this->turretWeapon;
  if ( turretWeapon != nullptr && idWeapon::CheckFireHandle(this: turretWeapon) )
  {
    idFireParms::idFireParms(this: &v173);
    memset(&v174, 0, sizeof(v174));
    v5 = &v172;
    v172.numProjectiles = 0;
    for ( i = 16; i != 0; --i )
    {
      v5 = (idFinishFireResults *)((char *)v5 + 4);
      v5->numProjectiles = 0;
    }
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idWeapon::ResolveFire(this: this->turretWeapon, fp: &v173, tfr: &v174, ffr: &v172, fxMgr: &presentable->fxManager);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v173.targetList);
  }
  this->isFiring = false;
  idAnimator_JointMod::ClearJointMods(this: &this->jointModAnimator);
  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::ClearJointMods(this: TreeAnimatorFromPresentable);
  }
  if ( turret_debug.valueInteger != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    maxRange = this->maxRange;
    v11 = clientGame->renderWorld->__vftable;
    v12 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, int, idVec3 *, double))v11->DebugCircle)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorYellow,
      a3: v12,
      a4: &vec3_up,
      a5: maxRange);
    v13 = idEntity::GetPhysics(this);
    v155[0] = 0.0;
    v155[1] = 1.0;
    v155[2] = 0.0;
    v14 = this->maxRange;
    v15 = clientGame->renderWorld->__vftable;
    v16 = (int)v13->GetOrigin(this: v13, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v15->DebugCircle)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorYellow,
      a3: v16,
      a4: v155,
      a5: v14);
    v17 = idEntity::GetPhysics(this);
    v153[0] = 1.0;
    v153[1] = 0.0;
    v153[2] = 0.0;
    v18 = this->maxRange;
    v19 = clientGame->renderWorld->__vftable;
    v20 = (int)v17->GetOrigin(this: v17, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v19->DebugCircle)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorYellow,
      a3: v20,
      a4: v153,
      a5: v18);
  }
  if ( this->saveDestroyedState && !this->hasCheckedDestroyedState )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( DebugPlayer != nullptr
      && (unsigned __int8)idGameLayerManager::ContainsItemMemory(
                            this: &DebugPlayer->gameLayerManager,
                            itemName: this->name.data) != 0 )
    {
      v22 = idEntity::GetPhysics(this);
      v22->SetContents(this: v22, a2: 0, a3: -1);
      v23 = idEntity::GetPhysics(this);
      v23->SetClipMask(this: v23, a2: 1, a3: -1);
      v24 = idEntity::GetPhysics(this);
      v25 = this->presentable;
      v26 = v24;
      if ( v25 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v25 = this->presentable;
      }
      v27 = v26->GetContents(this: v26, a2: -1);
      idPresentable::SetClipModelContents(
        this: v25,
        newContents: v27,
        a3: v33,
        a4: v32,
        a5: v31,
        a6: v30,
        a7: v29,
        a8: v28);
      idTurret::SetState(this, state: TS_DISABLED);
      v143.value = this->entityNumber;
      v143.value |= gameLocal->spawnIds.ptr[v143.value] << 13;
      idList<idEntityPtr<idPlayer>,5>::Remove(
        this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->aiWorldStateUsers,
        obj: (const idEntityPtr<idAI2> *)&v143);
      if ( idEntityPtr<idEntity const>::operator->(this: &this->flare) != nullptr )
      {
        v34 = idEntityPtr<idEntity const>::operator->(this: &this->flare);
        idEntity::Unbind(this: v34);
        v35 = idEntityPtr<idEntity const>::operator->(this: &this->flare);
        idEventReceiver::PostEventMS(this: v35, ev: &EV_Remove, time: 0);
        this->flare.spawnId.value = 0x1FFF;
      }
      if ( this->destroyedModel != nullptr )
      {
        ((void (__fastcall *)(idTurret *))this->SetModel)(a1: this);
      }
      else if ( this->destroyedMhAnimAlias.value != 0xFFFF )
      {
        blendParms_t::blendParms_t(this: (blendParms_t *)&v157);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v37 = this->GetAnimStack_2(this);
        LODWORD(v38) = &v157;
        idAnimator_Channel::CycleAnim(
          this: &this->movingHoldAnimator,
          stack: v37,
          ah: &this->destroyedMhAnimAlias,
          curTime: GameMs,
          rateScale: 1.0,
          leafStarted: v38,
          a7: nullptr);
        idAnimator_Channel::ClearAnimator(this: &this->channelAnimator);
      }
      idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: true);
      idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: true);
      idEntity::BecomeInactive(this, flags: 7);
      idTurret::StopTurnSound(this);
      if ( this->idleSoundPlaying )
      {
        this->idleSoundPlaying = false;
        idEntity::StopSound(this, channel: SND_CHANNEL_AMBIENT, peerMask: 0xFFu);
      }
      v39 = 0;
      if ( this->triggerOnDestroy.num > 0 )
      {
        v40 = 0;
        do
        {
          v41 = idEntityPtr<idEntity const>::operator->(this: &this->triggerOnDestroy.list[v40]);
          if ( v41 != nullptr )
          {
            v42 = idEventArg::idEventArg(this: (idEventArg *)&v157, data: this);
            idEventReceiver::PostEventMS(
              this: v41,
              ev: &EV_Activate,
              time: *(_DWORD *)&v42->type,
              arg1: (const idEventArg *)LODWORD(v42->value.v[1]));
          }
          ++v39;
          ++v40;
        }
        while ( v39 < this->triggerOnDestroy.num );
      }
      goto LABEL_126;
    }
    this->hasCheckedDestroyedState = true;
  }
  startOff = this->startOff;
  v142 = false;
  if ( startOff || (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
  {
    idTurret::StopTurnSound(this);
    idTurret::UpdateWeaponState(this, shouldShowLaser: false);
    idTurret::FireShotEffects(this);
    if ( !this->idleSoundPlaying )
    {
      soundIdle = this->soundIdle;
      if ( soundIdle != nullptr && !this->startOff )
      {
        this->idleSoundPlaying = true;
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_AMBIENT,
          shader: soundIdle,
          soundShaderFlags: SSF_LOOPING,
          peerMask: 0xFFu);
      }
    }
    goto LABEL_122;
  }
  idTargetCache::Clear(this: &this->worldState.targetCache);
  p_enemy = &this->enemy;
  currentState = this->currentState;
  v46 = _cntlzw((unsigned int)idEntityPtr<idEntity const>::operator->(this: &this->enemy));
  v47 = this->GetFaction(this);
  v48 = idEntityPtr<idEntity const>::operator->(this: &this->enemy);
  v49 = idSpawnId::idSpawnId(this: &v143, ent: v48);
  v50 = idSpawnId::idSpawnId(this: &v144, ent: this);
  idAILogic::idAILogic(
    this: &v157,
    spawnId_: v50,
    curEnemyId_: v49,
    encounterGroup_: nullptr,
    faction_: v47,
    combatTimeoutInterval_: -1.0,
    searchTimeoutInterval_: -1.0,
    isRelaxed_: 0x82000000,
    isSearching_: currentState - 3,
    a10: (v46 & 0x20) != 0,
    a11: v123,
    a12: v124,
    a13: v125,
    a14: v126,
    a15: v127,
    a16: v128,
    a17: v129,
    a18: v130,
    a19: v131,
    a20: v132,
    a21: v133,
    a22: v134,
    a23: v135,
    a24: v136,
    a25: v137,
    a26: v138,
    a27: v139,
    a28: v140,
    a29: v141,
    a30: (_cntlzw(currentState - 3) & 0x20) != 0);
  idAIWorldState::ResolveDeferredQueries(this: &this->worldState, gameState: &gameLocal->aiGameState, aiOwner: &v157);
  v51 = this->currentState;
  if ( v51 == TS_HAYWIRE
    || v51 == TS_DYING
    || v51 == TS_DISABLED
    || (declTrackingParms = this->declTrackingParms) == nullptr )
  {
    p_enemy->spawnId.value = 0x1FFF;
  }
  else
  {
    idAIWorldState::Update(
      this: &this->worldState,
      gameState: &gameLocal->aiGameState,
      aiOwner: &v157,
      trackingParms: declTrackingParms->parms.list);
    idTurretTargetFilter::idTurretTargetFilter(this: (idTurretTargetFilter *)&v150, minAwareness_: AIAWARE_CONFIRMED);
    v158.__vftable = (idTargetSelector_vtbl *)&idTurretTargetSelector::`vftable';
    value = this->lastTarget.spawnId.value;
    v54 = this->attackedByTarget.spawnId.value;
    useOrgHeadingAsSearchDir = this->useOrgHeadingAsSearchDir;
    minRange = this->minRange;
    v161 = this->maxRange;
    p_spawnOrientation = &this->spawnOrientation;
    v162 = minRange;
    v159 = value;
    v160 = v54;
    if ( !useOrgHeadingAsSearchDir )
      p_spawnOrientation = (idMat3 *)&this->startForwardDir;
    x = p_spawnOrientation->mat[0].x;
    y = p_spawnOrientation->mat[0].y;
    maxTurnAngle = this->maxTurnAngle;
    z = p_spawnOrientation->mat[0].z;
    trackOnlyPlayer = this->trackOnlyPlayer;
    v146.x = x;
    v146.y = y;
    v146.z = z;
    v165 = z;
    v167 = trackOnlyPlayer;
    v164 = y;
    v163 = x;
    idTargetList::idTargetList(this: &v169, targetCache_: &this->worldState.targetCache);
    p_enemy->spawnId.value = 0x1FFF;
    if ( idTargetList::FindBestTarget(this: &v169, owner: (idAI2 *)this, filter: &v150, selector: &v158) >= 0
      && v169.bestTargetIndex >= 0 )
    {
      v62 = &v169.targetCache->targets.list[v169.viableTargets.list[v169.bestTargetIndex]];
      if ( v62 != nullptr )
      {
        Entity = idAIEntityState::GetEntity(this: (idAIEntityState *)v62->es);
        if ( Entity != nullptr )
        {
          v144.value = Entity->entityNumber;
          p_enemy->spawnId.value = (gameLocal->spawnIds.ptr[v144.value] << 13) | v144.value;
        }
        else
        {
          p_enemy->spawnId.value = 0x1FFF;
        }
      }
    }
    idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v169);
    v158.__vftable = (idTargetSelector_vtbl *)&idTargetSelector::`vftable';
    v150.__vftable = (idTargetFilter_vtbl *)&idTargetFilter::`vftable';
  }
  v64 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: &this->enemy);
  v65 = idPlayer::CastTo(c: v64);
  if ( v65 != nullptr
    || (v66 = (idVehicle_Car *)idEntityPtr<idEntity const>::operator->(this: &this->enemy),
        (v67 = idVehicle_Car::CastTo(c: v66)) != nullptr)
    && (v65 = idVehicle::PlayerIsOccupant(this: v67)) != nullptr )
  {
    if ( (*((_BYTE *)v65 + 12824) & 8) != 0 )
      p_enemy->spawnId.value = 0x1FFF;
  }
  if ( idEntityPtr<idEntity const>::operator->(this: &this->enemy) != nullptr )
  {
    v68 = idEntityPtr<idEntity const>::operator->(this: &this->enemy);
    v69 = idAIWorldState::StateForEntity(this: &this->worldState, ent: v68);
    idTurret::HandleState(this, shouldShowLaser: &v142);
    v70 = idTurret::CheckState(this);
    if ( v69 != nullptr && v70 != 0 )
    {
      if ( (unsigned __int8)idAIEntityState::IsVisible(this: v69) != 0 )
      {
        this->isFiring = idTurret::TurretFire(this);
      }
      else
      {
        v71 = this->currentState;
        if ( v71 != TS_SEARCHING )
        {
          if ( this->trackOnlyPlayer )
          {
            v72 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
            if ( v72 != nullptr )
            {
              str = this->searchMeshKit.str;
              if ( str != nullptr && *str != 0 )
                idTreeAnimator::HideKitsExcept(this: v72, kitType: MESH_KIT_HEADS, name: str);
              this->currentState = TS_SEARCHING;
            }
            idTurret::RestartSearch(this);
          }
          else if ( v71 != TS_SUPPRESSING_FIRE )
          {
            this->turretFOV = this->startFOV;
            v74 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
            if ( v74 != nullptr )
            {
              v75 = this->nonSearchMeshKit.str;
              if ( v75 != nullptr && *v75 != 0 )
                idTreeAnimator::HideKitsExcept(this: v74, kitType: MESH_KIT_HEADS, name: v75);
              this->currentState = TS_SUPPRESSING_FIRE;
            }
            idAIEntityState::GetAimPoint(
              this: v69,
              sense: AISENSE_SIGHT,
              aimPoint: AIMPOINT_BEST,
              point: &this->suppressionFirePoint);
            idTurret::RestartSuppressing(this);
          }
        }
      }
    }
  }
  else
  {
    idTurret::CheckState(this);
    idTurret::HandleState(this, shouldShowLaser: &v142);
  }
  v76 = idEntity::GetPhysics(this);
  v77 = (float *)v76->GetOrigin(this: v76, a2: 0);
  this->lastPos.x = *v77;
  v78 = v77[1];
  v144.value = (int)&this->lastPos;
  this->lastPos.y = v78;
  this->lastPos.z = v77[2];
  if ( this->turnSpeed <= 0.0 )
    goto LABEL_100;
  v79 = this->currentState;
  if ( v79 == TS_DYING )
    goto LABEL_100;
  if ( v79 == TS_SEARCHING || v79 == TS_NORMAL || v79 == TS_SUPPRESSING_FIRE || (v81 = v79 != TS_HAYWIRE, v80 = 1, !v81) )
    v80 = 0;
  v82 = v80;
  idAnimatedEntity::GetTagPosition(
    this,
    propIndex: this->propinfoIndex,
    tagIndex: this->muzzleTagIndex,
    origin: v168,
    axis: &v171);
  v83 = idTurret::HandleRotation(this, TargetPos: &this->goalPos, firing: v168, muzzleDir: v171.mat, blendOut: v82);
  if ( v82 == 0 )
  {
    if ( this->idleSoundPlaying )
    {
      this->idleSoundPlaying = false;
      idEntity::StopSound(this, channel: SND_CHANNEL_AMBIENT, peerMask: 0xFFu);
    }
    if ( !this->turningSound )
    {
      if ( v83 != 0 )
      {
        this->turningSound = true;
        v84 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        if ( v84 - this->lastStartTurnSound > 500 )
        {
          this->lastStartTurnSound = v84;
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_STEERING,
            shader: this->soundTurnstart,
            soundShaderFlags: (soundShaderFlags_t)0,
            peerMask: 0xFFu);
        }
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_ENGINE_IDLE,
          shader: this->soundTurning,
          soundShaderFlags: SSF_LOOPING,
          peerMask: 0xFFu);
        goto LABEL_101;
      }
      if ( !this->turningSound )
        goto LABEL_101;
    }
    if ( v83 != 0 )
      goto LABEL_101;
LABEL_100:
    idTurret::StopTurnSound(this);
    goto LABEL_101;
  }
  if ( !this->idleSoundPlaying )
  {
    v85 = this->soundIdle;
    if ( v85 != nullptr )
    {
      v86 = this->currentState;
      if ( v86 != TS_DISABLED && v86 != TS_DYING )
      {
        this->idleSoundPlaying = true;
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_AMBIENT,
          shader: v85,
          soundShaderFlags: SSF_LOOPING,
          peerMask: 0xFFu);
      }
    }
  }
  if ( this->turningSound )
    goto LABEL_100;
LABEL_101:
  v87 = this->currentState;
  if ( v87 == TS_NORMAL || (v81 = v87 != TS_SUPPRESSING_FIRE, v88 = 0, !v81) )
    v88 = 1;
  v89 = v88;
  if ( v88 != 0 )
    alarmSkin = this->alarmSkin;
  else
    alarmSkin = this->idleSkin;
  v91 = this->presentable;
  if ( v91 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v91 = this->presentable;
  }
  v91->model->g.customSkin = alarmSkin;
  if ( gameLocal->spawnIds.ptr[this->flare.spawnId.value & 0x1FFF] == this->flare.spawnId.value >> 13 )
  {
    v92 = (unsigned __int8 *)idEntityPtr<idEntity const>::operator->(this: &this->flare);
    if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v92) != 0 )
    {
      if ( v89 == 0 )
        goto LABEL_117;
      Show = (void (*)(void))idEntityPtr<idEntity const>::operator->(this: &this->flare)->Show;
      goto LABEL_116;
    }
    if ( v89 == 0 )
    {
      Show = (void (*)(void))idEntityPtr<idEntity const>::operator->(this: &this->flare)->Hide_2;
LABEL_116:
      Show();
    }
  }
LABEL_117:
  idTurret::UpdateWeaponState(this, shouldShowLaser: v142);
  idTurret::FireShotEffects(this);
LABEL_122:
  idAnimatedEntity::UpdateFrameCommands(this);
  if ( (this->thinkFlags & 2) != 0 )
    idEntity::RunPhysics(this);
  idEntity::TouchTriggers(this);
  this->UpdateFX(this);
  idAnimatedEntity::UpdateImpacts(this);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  idEntity::UpdateVisuals(this);
  v95 = idEntity::GetPhysics(this);
  v96 = (idBounds *)v95->GetAbsBounds(this: v95, a2: -1);
  idEntity::UpdatePVSAreas(this, bounds: v96);
  if ( turret_ShowAngles.valueInteger != 0 )
  {
    idAnimatedEntity::GetTagPosition(
      this,
      propIndex: this->propinfoIndex,
      tagIndex: this->muzzleTagIndex,
      origin: &v145,
      axis: &v170);
    v97 = idVec3::ToAngles(this: &v146, result: (idAngles *)&v170);
    maxFireAngle = this->maxFireAngle;
    v99 = this->maxRange;
    v148.x = v97->pitch;
    v100 = (float)((float)maxFireAngle + v97->yaw);
    v148.y = v97->yaw;
    v148.z = v97->roll;
    v148.y = v100;
    v101 = idAngles::ToForward(this: (idAngles *)&v157, result: &v148);
    v102 = (float)(v101->y * (float)v99);
    v103 = (float)((float)v99 * v101->x);
    v151[2] = v145.z + (float)(v101->z * (float)v99);
    v151[1] = v145.y + (float)v102;
    v151[0] = v145.x + (float)v103;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: &v145,
      a4: (const idVec3 *)v151,
      a5: 0,
      a6: false);
    v148.y = -(float)((float)(this->maxFireAngle * (float)2.0) - v148.y);
    v104 = this->maxRange;
    v105 = idAngles::ToForward(this: (idAngles *)&v157, result: &v148);
    v106 = (float)((float)v104 * v105->x);
    v107 = (float)(v105->y * (float)v104);
    v152[2] = v145.z + (float)(v105->z * (float)v104);
    v152[0] = (float)v106 + v145.x;
    v152[1] = v145.y + (float)v107;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: &v145,
      a4: (const idVec3 *)v152,
      a5: 0,
      a6: false);
    v108 = idVec3::ToAngles(this: (idVec3 *)&v157, result: (idAngles *)&this->startForwardDir);
    v109 = this->maxTurnAngle;
    v110 = this->maxRange;
    v147.x = v108->pitch;
    yaw = v108->yaw;
    v147.y = v108->yaw;
    v147.z = v108->roll;
    v147.y = (float)v109 + (float)yaw;
    v112 = idAngles::ToForward(this: (idAngles *)&v146, result: &v147);
    v113 = (float)(v112->y * (float)v110);
    v114 = (float)((float)v110 * v112->x);
    v115 = this->startPos.y;
    v116 = this->startPos.x;
    v154[2] = (float)(v112->z * (float)v110) + this->startPos.z;
    v154[1] = (float)v113 + (float)v115;
    v154[0] = (float)v114 + (float)v116;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorBlack,
      a3: &this->startPos,
      a4: (const idVec3 *)v154,
      a5: 0,
      a6: false);
    v147.y = -(float)((float)(this->maxTurnAngle * (float)2.0) - v147.y);
    v117 = this->maxRange;
    v118 = idAngles::ToForward(this: (idAngles *)&v157, result: &v147);
    v119 = (float)(v118->y * (float)v117);
    v120 = (float)((float)v117 * v118->x);
    v121 = this->startPos.y;
    v122 = this->startPos.x;
    v156[2] = (float)(v118->z * (float)v117) + this->startPos.z;
    v156[1] = (float)v119 + (float)v121;
    v156[0] = (float)v120 + (float)v122;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorBlack,
      a3: &this->startPos,
      a4: (const idVec3 *)v156,
      a5: 0,
      a6: false);
  }
LABEL_126:
  idPLogScope::~idPLogScope(this: &v149);
  RD_EventEnd();
}


// ========================================================================
// __unwind$507865
// EA  : 0x82CFE528
// RVA : 0x00CFE528
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_507865()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 3248 + 3108));
}


// ========================================================================
// __unwind$507866
// EA  : 0x82CFE550
// RVA : 0x00CFE550
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_507866()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 3248 + 176));
}


// ========================================================================
// __unwind$507867
// EA  : 0x82CFE578
// RVA : 0x00CFE578
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_507867()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3248 + 640));
}


// ========================================================================
// __unwind$507868_0
// EA  : 0x82CFE5A0
// RVA : 0x00CFE5A0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_507868_0()
{
  int v0; // r12

  idAvoidTargetFilter::~idAvoidTargetFilter(this: (idFriendlyDeadTargetFilter *)(v0 - 3248 + 184));
}


// ========================================================================
// __unwind$507869
// EA  : 0x82CFE5C8
// RVA : 0x00CFE5C8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_507869()
{
  int v0; // r12

  idEnemyTargetSelector::~idEnemyTargetSelector(this: (idNeutralTargetSelector *)(v0 - 3248 + 320));
}


// ========================================================================
// __unwind$507870
// EA  : 0x82CFE5F0
// RVA : 0x00CFE5F0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_507870()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 3248 + 400));
}


// ========================================================================
// ?Think@idRailTurret@@UAAXXZ
// EA  : 0x82CFE618
// RVA : 0x00CFE618
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idRailTurret::Think(idRailTurret *this)
{
  int value; // r10
  idSplinePath *v3; // r3
  __int64 v4; // r9
  int num; // r11
  int plannedPathIndex; // r10
  idSplinePath *v7; // r3
  int v8; // r10
  idSplinePath *Target; // r29
  int v10; // r11
  idRailTurret_vtbl *v11; // r10
  idSplinePath *v12; // r3
  int v13; // r28
  idSplinePath *v14; // r3
  idSplinePath *v15; // r29
  idPhysics *Physics; // r28
  __int64 v17; // r10
  idPhysics_vtbl *v18; // r29
  int v19; // r3
  int v20; // r29
  int v21; // r28
  idVec3 *v22; // r9
  float x; // r3
  float y; // r10
  float z; // r9
  __int64 v26; // r10
  __int64 v27; // r6
  __int64 v28; // r8
  int v29; // r11
  va *v30; // r3
  __int64 v31; // r10
  float *v32; // r3
  int GameMs; // r29
  int v34; // r3
  __int64 v35; // r10
  __int64 v36; // r6
  __int64 v37; // r8
  va *v38; // r3
  __int64 v39; // r8
  va *v40; // r28
  idRenderWorld_vtbl *v41; // r29
  int v42; // r3
  int v43; // r6
  int v44; // [sp+8h] [-1108h]
  int v45; // [sp+Ch] [-1104h]
  int v46; // [sp+10h] [-1100h]
  int v47; // [sp+14h] [-10FCh]
  int v48; // [sp+18h] [-10F8h]
  int v49; // [sp+1Ch] [-10F4h]
  _DWORD v50[4]; // [sp+70h] [-10A0h] BYREF
  float v51[4]; // [sp+80h] [-1090h] BYREF
  float v52[4]; // [sp+90h] [-1080h] BYREF
  _BYTE v53[16]; // [sp+A0h] [-1070h] BYREF
  va v54; // [sp+B0h] [-1060h] BYREF

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
    goto LABEL_23;
  if ( this->currentSpline == nullptr )
    goto LABEL_23;
  value = this->currentSplinePath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_23;
  v3 = (idSplinePath *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr || idSplinePath::CastTo(c: v3) == nullptr )
    goto LABEL_23;
  LODWORD(v4) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( this->currentSpline->IsDone(this: this->currentSpline, a2: (float)v4) )
  {
    num = this->plannedPath.num;
    if ( num <= 0 )
    {
      if ( idEntityPtr<idSplinePath>::operator idSplinePath *(this: &this->currentSplinePath)->targets.num >= 1 )
      {
        v12 = idEntityPtr<idSplinePath>::operator idSplinePath *(this: &this->currentSplinePath);
        v13 = idRandom2::RandomInt(this: &clientGame->random, min: 0, max: v12->targets.num - 1);
        v14 = idEntityPtr<idSplinePath>::operator idSplinePath *(this: &this->currentSplinePath);
        Target = (idSplinePath *)idEntity::GetTarget(this: v14, i: v13);
        goto LABEL_14;
      }
    }
    else
    {
      plannedPathIndex = this->plannedPathIndex;
      if ( plannedPathIndex > -1 && plannedPathIndex < num )
      {
        v7 = idEntityPtr<idSplinePath>::operator idSplinePath *(this: &this->plannedPath.list[plannedPathIndex]);
        v8 = this->plannedPath.num;
        Target = v7;
        v10 = this->plannedPathIndex + 1;
        this->plannedPathIndex = v10;
        if ( v8 < v10 )
        {
          v11 = this->__vftable;
          this->plannedPathIndex = -1;
          v11->Hide_2(this);
        }
LABEL_14:
        if ( Target != nullptr && (unsigned __int8)idSplinePath::IsTypeOf(c: Target) != 0 )
        {
          v15 = idSplinePath::CastTo(c: Target);
          this->currentSpline->Clear(this: this->currentSpline);
          idRailTurret::SetPath(this, path: v15);
          goto LABEL_18;
        }
      }
    }
    this->Hide_2(this);
  }
LABEL_18:
  Physics = idEntity::GetPhysics(this);
  LODWORD(v17) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v18 = Physics->__vftable;
  v19 = ((int (__fastcall *)(_BYTE *, double))this->currentSpline->GetCurrentValue)(a1: v53, a2: (float)v17);
  v18->SetOrigin(this: Physics, a2: (const idVec3 *)v19, a3: -1);
  if ( turret_debug.valueInteger != 0 )
  {
    v20 = 0;
    if ( this->currentSpline->values.num > 0 )
    {
      v21 = 0;
      do
      {
        v22 = &this->currentSpline->values.list[v21];
        x = v22->x;
        y = v22->y;
        z = v22->z;
        v52[3] = 0.5;
        v52[0] = x;
        v52[1] = y;
        v52[2] = z;
        clientGame->renderWorld->DebugSphere(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idSphere *)v52,
          a4: 12,
          a5: 0,
          a6: false);
        HIDWORD(v26) = this->currentSpline;
        HIDWORD(v27) = v20;
        LODWORD(v28) = *(_DWORD *)(HIDWORD(v26) + 20) + v21 * 12;
        LODWORD(v27) = *(_DWORD *)(v28 + 4);
        v29 = *(_DWORD *)(v28 + 8);
        v50[0] = *(_DWORD *)v28;
        HIDWORD(v28) = v50[0];
        v50[1] = v27;
        v50[2] = v29;
        v30 = va::va(
                this: &v54,
                fmt: "%i",
                a3: v27,
                a4: v28,
                a5: v26,
                a6: v44,
                a7: v45,
                a8: v46,
                a9: v47,
                a10: v48,
                a11: v49);
        ((void (__fastcall *)(idRenderWorld *, va *, _DWORD *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
          a1: clientGame->renderWorld,
          a2: v30,
          a3: v50,
          a4: clientGame->renderWorld->__vftable,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.5);
        ++v20;
        ++v21;
      }
      while ( v20 < this->currentSpline->values.num );
    }
    LODWORD(v31) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v32 = (float *)((int (__fastcall *)(_BYTE *, double))this->currentSpline->GetCurrentValue)(a1: v53, a2: (float)v31);
    v51[0] = *v32;
    v51[1] = v32[1];
    v51[2] = v32[2];
    v51[3] = 0.5;
    clientGame->renderWorld->DebugSphere(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idSphere *)v51,
      a4: 12,
      a5: 0,
      a6: false);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v34 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    HIDWORD(v35) = 0x82000000;
    HIDWORD(v36) = v34;
    v38 = va::va(
            this: &v54,
            fmt: "%d",
            a3: v36,
            a4: v37,
            a5: v35,
            a6: v44,
            a7: v45,
            a8: v46,
            a9: v47,
            a10: v48,
            a11: v49);
    LODWORD(v39) = GameMs;
    v40 = v38;
    v41 = clientGame->renderWorld->__vftable;
    v42 = ((int (__fastcall *)(_BYTE *, double))this->currentSpline->GetCurrentValue)(a1: v53, a2: (float)v39);
    ((void (__fastcall *)(idRenderWorld *, va *, int, int, idColor *, int, _DWORD, _DWORD, double))v41->DebugText)(
      a1: clientGame->renderWorld,
      a2: v40,
      a3: v42,
      a4: v43,
      a5: &idColor::colorYellow,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.5);
  }
LABEL_23:
  idTurret::Think(this);
}


// ========================================================================
// ?Think@idTowerTurret@@UAAXXZ
// EA  : 0x82CFEAF8
// RVA : 0x00CFEAF8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTowerTurret::Think(idTowerTurret *this)
{
  idSimpleHealth *v2; // r3
  int value; // r10
  idEntityPtr<idAFEntity_Dummy> *p_towerGunner; // r30
  idAFEntity_Dummy *v5; // r3
  idAFEntity_Dummy *v6; // r3
  idAFEntity_Dummy *v7; // r3
  int v8; // r3
  char v9; // r11
  idPhysics *Physics; // r3
  idRenderWorld_vtbl *v11; // r31
  int v12; // r3

  v2 = this->GetTurretHealthComponent_2(this);
  if ( v2->IsDead_Impl(this: v2) )
  {
    idEntity::StopSound(this, channel: SND_CHANNEL_STEERING, peerMask: 0xFFu);
  }
  else
  {
    value = this->towerGunner.spawnId.value;
    p_towerGunner = &this->towerGunner;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
      goto LABEL_16;
    v5 = (idAFEntity_Dummy *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 == nullptr || idAFEntity_Dummy::CastTo(c: v5) == nullptr )
      goto LABEL_16;
    if ( gameLocal->spawnIds.ptr[p_towerGunner->spawnId.value & 0x1FFF] == p_towerGunner->spawnId.value >> 13
      && (v6 = (idAFEntity_Dummy *)gameLocal->entities.ptr[p_towerGunner->spawnId.value & 0x1FFF]) != nullptr )
    {
      v7 = idAFEntity_Dummy::CastTo(c: v6);
    }
    else
    {
      v7 = nullptr;
    }
    v8 = (int)v7->GetAF_2(this: v7);
    if ( *(_BYTE *)(v8 + 267) != 0 || (v9 = 0, *(_BYTE *)(v8 + 268) != 0) )
      v9 = 1;
    if ( v9 == 0
      && !idEntityPtr<idAFEntity_Dummy>::operator idAFEntity_Dummy *(this: &this->towerGunner)->playedDeathAnim )
    {
      idTurret::Think(this);
    }
    else
    {
LABEL_16:
      idEntity::StopSound(this, channel: SND_CHANNEL_STEERING, peerMask: 0xFFu);
      if ( turret_debug.valueInteger != 0 )
      {
        Physics = idEntity::GetPhysics(this);
        v11 = clientGame->renderWorld->__vftable;
        v12 = (int)Physics->GetOrigin(this: Physics, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v11->DebugText)(
          a1: clientGame->renderWorld,
          a2: "Turret Gunner Dead",
          a3: v12,
          a4: v11->DebugText,
          a5: &idColor::colorYellow,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.69999999);
      }
    }
  }
}


// ========================================================================
// ??0idTurret@@QAA@XZ
// EA  : 0x82CFECE0
// RVA : 0x00CFECE0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

idTurret *__fastcall idTurret::idTurret(idTurret *this)
{
  int v2; // ctr
  int *p_slinecedIntoTime; // r10
  float *p_y; // r11
  float *p_z; // r10
  float *v6; // r11
  int i; // ctr
  float z; // r6
  float v9; // r8
  idEntityPtr<idEntity> *p_flare; // r9
  float *v11; // r10
  int j; // ctr

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idTurret_vtbl *)&idTurret::`vftable';
  this->triggerOnDestroy.list = nullptr;
  this->triggerOnDestroy.granularity = 0;
  this->triggerOnDestroy.memTag = 5;
  this->triggerOnDestroy.listStatic = 0;
  this->triggerOnDestroy.size = 0;
  this->triggerOnDestroy.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggerOnDestroy);
  this->damageGroups.granularity = 0;
  this->damageGroups.memTag = 5;
  this->damageGroups.listStatic = 0;
  this->damageGroups.list = nullptr;
  this->damageGroups.size = 0;
  this->damageGroups.num = 0;
  this->searchMeshKit.str = &byte_8200D768;
  this->nonSearchMeshKit.str = &byte_8200D768;
  this->disabledMeshKit.str = &byte_8200D768;
  idAnimator_AF::idAnimator_AF(this: &this->afProperties);
  this->explodeDamage = nullptr;
  this->destroyedParticle = nullptr;
  this->ondestroyedParticle = nullptr;
  this->explodeParticle = nullptr;
  this->soundHaywire = nullptr;
  this->density = 0.00019999999;
  this->soundDoneInit = nullptr;
  this->soundDying = nullptr;
  this->destroyedParticleRateStart = 0.0;
  this->soundTargetAquired = nullptr;
  this->soundTurnstart = nullptr;
  this->soundTurning = nullptr;
  this->soundIdle = nullptr;
  this->laserBeamMtrSearch = nullptr;
  this->laserBeamMtrHostile = nullptr;
  this->declTrackingParms = nullptr;
  this->destroyedParticleRate = 1;
  this->destroyedParticleRateCurve = nullptr;
  this->turretHealth.components[0].max = 100.0;
  this->turretHealth.components[0].cur = 100.0;
  this->turretHealth.components[0].type = SIMPLE_HEALTH_MAX;
  this->turretHealth.killThreshold = 0.0;
  this->turretHealth.killingBlowDamage = 0.0;
  this->turretHealth.accumulatedDamageFrame = -1;
  this->turretHealth.accumulatedFrameDamage = 0.0;
  this->turretHealth.isDead = false;
  this->turretHealth.components[0].type = SIMPLE_HEALTH_HITPOINTS;
  this->turretHealth.__vftable = (idSimpleHealth_vtbl *)&idSimpleHealth::`vftable';
  this->minRange = 0.0;
  this->pitchSpeed = 0.0;
  this->spinwheelSpeed = 0.0;
  this->turnSpeed = 0.0;
  this->destroyedModel = nullptr;
  this->maxRange = 3000.0;
  this->maxFireRange = 3000.0;
  this->maxFireAngle = 360.0;
  this->maxFirePitch = 45.0;
  this->maxTurnAngle = 360.0;
  this->heightOffFloor = 90.0;
  this->windupTime = 0.0;
  this->nameRotation.allocedAndFlag = 20;
  this->nameRotation.data = this->nameRotation.baseBuffer;
  this->nameRotation.len = 0;
  this->nameRotation.baseBuffer[0] = 0;
  this->namePitch.allocedAndFlag = 20;
  this->namePitch.len = 0;
  this->namePitch.data = this->namePitch.baseBuffer;
  this->namePitch.baseBuffer[0] = 0;
  this->nameSpinwheel.allocedAndFlag = 20;
  this->nameSpinwheel.len = 0;
  this->nameSpinwheel.data = this->nameSpinwheel.baseBuffer;
  this->nameSpinwheel.baseBuffer[0] = 0;
  this->weaponDecl = nullptr;
  this->haywireOnKnockdownChance = 0;
  this->haywireTime = 5000;
  this->dyingTime = 50000;
  this->initTime = 0;
  this->maxProjectiles = 5;
  this->regimeGridTime = 0;
  this->foundTargetToActivateTime = 960;
  this->foundTargetToFireTime = 0;
  this->disassembleLoot.__vftable = (idDisassembleLoot_vtbl *)&idDisassembleLoot::`vftable';
  this->disassembleLoot.lootBoxes.granularity = 0;
  this->disassembleLoot.lootBoxes.memTag = 5;
  this->disassembleLoot.lootBoxes.listStatic = 0;
  this->disassembleLoot.lootBoxes.list = nullptr;
  this->disassembleLoot.lootBoxes.size = 0;
  this->disassembleLoot.lootBoxes.num = 0;
  this->disassembleLoot.disassembleParticle = nullptr;
  this->disassembleLoot.soundShader = nullptr;
  idFaction::idFaction(this: &this->faction);
  this->isStatic = true;
  this->noKnockback = false;
  this->targetable = true;
  this->useStartFacing = false;
  this->dontRemoveAfterDying = true;
  this->startOff = false;
  this->invertedTurret = false;
  this->trackOnlyPlayer = false;
  this->EMPSilenced = false;
  this->hasSphereModel = false;
  *(_WORD *)&this->searchFromLastTarget = 1;
  this->useOrgHeadingAsSearchDir = false;
  this->silenceWhenDamaged = false;
  this->saveDestroyedState = false;
  this->usingFiringControl = false;
  this->timeToBeSilenced = 0;
  v2 = 9;
  this->dropAnimAlias.value = -1;
  p_slinecedIntoTime = &this->slinecedIntoTime;
  this->acquiredTargetAnimAlias.value = -1;
  this->lostTargetAnimAlias.value = -1;
  this->breakAnimAlias.value = -1;
  this->shootAnimAlias.value = -1;
  this->SilencedAnimAlias.value = -1;
  this->SilencedIdleAnimAlias.value = -1;
  this->disabledAnimAlias.value = -1;
  this->UnSilencedAnimAlias.value = -1;
  this->aquiredMhAnimAlias.value = -1;
  this->destroyedAnimAlias.value = -1;
  this->destroyedMhAnimAlias.value = -1;
  p_y = &mat2_identity.mat[1].y;
  this->turretWeapon = nullptr;
  this->slinecedIntoTime = 0;
  do
  {
    *++p_slinecedIntoTime = *(_DWORD *)++p_y;
    --v2;
  }
  while ( v2 != 0 );
  p_z = &this->slinecedJointRot.mat[2].z;
  v6 = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_z = *++v6;
  this->startForwardDir = vec3_origin;
  this->startPos = vec3_origin;
  this->lastPos = vec3_origin;
  this->isFiring = false;
  this->nextShotTimer = 0;
  this->turretOwner = nullptr;
  this->propinfoIndex = -1;
  this->muzzleTagIndex = -1;
  idAIWorldState::idAIWorldState(this: &this->worldState);
  this->enemy.spawnId.value = 0x1FFF;
  this->lastTarget.spawnId.value = 0x1FFF;
  this->attackedByTarget.spawnId.value = 0x1FFF;
  this->goalPos.x = vec3_origin.x;
  this->goalPos.y = vec3_origin.y;
  z = vec3_origin.z;
  this->searchAngle = 30.0;
  this->searchTime = 5.0;
  this->goalPos.z = z;
  this->searchSpeed = 1.0;
  this->returnToCenter = false;
  this->turretFOV = 0.0;
  this->startFOV = 0.0;
  this->startSearchDir.x = vec3_origin.x;
  this->startSearchDir.y = vec3_origin.y;
  v9 = vec3_origin.z;
  this->currentSearchAngle = 0.0;
  this->cosMaxFireAngle = 0.0;
  this->timeSuppressed = 0.0;
  this->startSearchTime = -1.0;
  this->stopThinkTime = 0;
  this->timeSearched = 0.0;
  this->lastStartTurnSound = 0;
  this->cosMaxFirePitch = 0.0;
  this->randomFireTime = -1;
  this->suppresingFireTime = 5.0;
  this->startSearchDir.z = v9;
  this->startSuppressingFire = -1.0;
  this->searchDirScale = 1;
  this->suppressionFirePoint = vec3_origin;
  this->canGoInactive = false;
  this->setStartingInfo = false;
  this->randomFire = false;
  this->turningSound = false;
  this->idleSoundPlaying = false;
  this->hasCheckedDestroyedState = false;
  this->allowedToFire = false;
  this->idleSkin = -1;
  this->alarmSkin = -1;
  this->isClipModelEnabled = false;
  idPhysics_Static::idPhysics_Static(this: &this->clipModel);
  this->jointRotation.value = -1;
  this->jointPitch.value = -1;
  this->jointSpinwheel.value = -1;
  this->lastYawRot.x = 0.0;
  this->lastYawRot.y = 0.0;
  this->lastYawRot.z = 0.0;
  this->lastYawRot.w = 1.0;
  this->lastPitchRot.x = 0.0;
  this->lastPitchRot.y = 0.0;
  this->lastPitchRot.z = 0.0;
  this->lastPitchRot.w = 1.0;
  idAnimator_Channel::idAnimator_Channel(this: &this->movingHoldAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->channelAnimator);
  idAnimator_JointMod::idAnimator_JointMod(this: &this->jointModAnimator);
  this->inventoryDecl = nullptr;
  this->interceptSpeed = 0.0;
  idInventoryCollection::idInventoryCollection(this: &this->inventoryCollection);
  this->activeProjectiles.list = nullptr;
  this->activeProjectiles.granularity = 0;
  this->activeProjectiles.memTag = 5;
  this->activeProjectiles.listStatic = 0;
  this->activeProjectiles.size = 0;
  this->activeProjectiles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeProjectiles);
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->spinTimer = 0;
  this->stateTimer = -10000;
  this->foundTargetTime = 0;
  this->currentState = TS_WARMUP;
  this->flareDecl = nullptr;
  this->flareBindToTag.allocedAndFlag = 20;
  this->flareBindToTag.data = this->flareBindToTag.baseBuffer;
  this->flareBindToTag.len = 0;
  this->flareBindToTag.baseBuffer[0] = 0;
  this->flare.spawnId.value = 0x1FFF;
  p_flare = &this->flare;
  v11 = &mat2_identity.mat[1].y;
  for ( j = 9; j != 0; --j )
  {
    ++v11;
    ++p_flare;
    p_flare->spawnId.value = *(int *)v11;
  }
  idStr::operator=(this: &this->nameRotation, text: "joint1");
  idStr::operator=(this: &this->namePitch, text: "head");
  idStr::operator=(this: &this->nameSpinwheel, text: "gear");
  idEntity::SetClipReplicationFlags(this, dynamicClipReplication: true, dynamicClipReplicationAxis: true);
  return this;
}


// ========================================================================
// __unwind$509378
// EA  : 0x82CFF350
// RVA : 0x00CFF350
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509378()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 240 + 260));
}


// ========================================================================
// __unwind$509379
// EA  : 0x82CFF378
// RVA : 0x00CFF378
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509379()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 5200));
}


// ========================================================================
// __unwind$509380
// EA  : 0x82CFF3A4
// RVA : 0x00CFF3A4
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509380()
{
  int v0; // r12

  idList<idDamageGroup,5>::~idList<idDamageGroup,5>(this: (idList<idDamageGroup,5> *)(*(_DWORD *)(v0 - 240 + 260) + 5216));
}


// ========================================================================
// __unwind$509381
// EA  : 0x82CFF3D0
// RVA : 0x00CFF3D0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509381()
{
  int v0; // r12

  idAnimator_AF::~idAnimator_AF(this: (idAnimator_AF *)(*(_DWORD *)(v0 - 240 + 260) + 5248));
}


// ========================================================================
// __unwind$509382
// EA  : 0x82CFF3FC
// RVA : 0x00CFF3FC
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509382()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(*(_DWORD *)(v0 - 240 + 260) + 6928));
}


// ========================================================================
// __unwind$509383
// EA  : 0x82CFF428
// RVA : 0x00CFF428
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509383()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 240 + 260) + 7012));
}


// ========================================================================
// __unwind$509384
// EA  : 0x82CFF454
// RVA : 0x00CFF454
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509384()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 240 + 260) + 7044));
}


// ========================================================================
// __unwind$509385
// EA  : 0x82CFF480
// RVA : 0x00CFF480
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509385()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 240 + 260) + 7076));
}


// ========================================================================
// __unwind$509546
// EA  : 0x82CFF4AC
// RVA : 0x00CFF4AC
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509546()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 240 + 84));
}


// ========================================================================
// __unwind$509386
// EA  : 0x82CFF4D4
// RVA : 0x00CFF4D4
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509386()
{
  int v0; // r12

  idDisassembleLoot::~idDisassembleLoot(this: (idDisassembleLoot *)(*(_DWORD *)(v0 - 240 + 260) + 7144));
}


// ========================================================================
// __unwind$509387
// EA  : 0x82CFF500
// RVA : 0x00CFF500
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509387()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 240 + 260) + 7172));
}


// ========================================================================
// __unwind$509388
// EA  : 0x82CFF52C
// RVA : 0x00CFF52C
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509388()
{
  int v0; // r12

  idAIWorldState::~idAIWorldState(this: (idAIWorldState *)(*(_DWORD *)(v0 - 240 + 260) + 7376));
}


// ========================================================================
// __unwind$509389
// EA  : 0x82CFF558
// RVA : 0x00CFF558
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509389()
{
  int v0; // r12

  idPhysics_Static::~idPhysics_Static(this: (idPhysics_Static *)(*(_DWORD *)(v0 - 240 + 260) + 12672));
}


// ========================================================================
// __unwind$509390
// EA  : 0x82CFF584
// RVA : 0x00CFF584
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509390()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 240 + 260) + 12880));
}


// ========================================================================
// __unwind$509391
// EA  : 0x82CFF5B0
// RVA : 0x00CFF5B0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509391()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 240 + 260) + 12976));
}


// ========================================================================
// __unwind$509392
// EA  : 0x82CFF5DC
// RVA : 0x00CFF5DC
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509392()
{
  int v0; // r12

  idAnimator_JointMod::~idAnimator_JointMod(this: (idAnimator_JointMod *)(*(_DWORD *)(v0 - 240 + 260) + 13072));
}


// ========================================================================
// __unwind$509393
// EA  : 0x82CFF608
// RVA : 0x00CFF608
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509393()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 13164));
}


// ========================================================================
// __unwind$509394
// EA  : 0x82CFF634
// RVA : 0x00CFF634
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509394()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 13964));
}


// ========================================================================
// __unwind$509395
// EA  : 0x82CFF660
// RVA : 0x00CFF660
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509395()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 240 + 260) + 13984));
}


// ========================================================================
// __unwind$509396
// EA  : 0x82CFF68C
// RVA : 0x00CFF68C
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_509396()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 240 + 260) + 14628));
}


// ========================================================================
// ??1idTurret@@UAA@XZ
// EA  : 0x82CFF728
// RVA : 0x00CFF728
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idTurret::~idTurret(idTurret *this)
{
  int v2; // r4
  idGameLocal *v3; // r10
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r9
  int v6; // r11
  idWeapon *turretWeapon; // r3
  idDamageGroup *list; // r3
  int entityNumber; // [sp+50h] [-30h]

  this->__vftable = (idTurret_vtbl *)&idTurret::`vftable';
  v2 = 0;
  v3 = gameLocal;
  entityNumber = this->entityNumber;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num > 0 )
  {
    v6 = 0;
    while ( p_aiWorldStateUsers->list[v6].spawnId.value != ((gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber) )
    {
      ++v2;
      ++v6;
      if ( v2 >= num )
        goto LABEL_8;
    }
    if ( v2 >= 0 )
    {
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_aiWorldStateUsers, index: v2);
      v3 = gameLocal;
    }
  }
LABEL_8:
  if ( this->turningSound )
  {
    this->turningSound = false;
    idEntity::StopSound(this, channel: SND_CHANNEL_STEERING, peerMask: 0xFFu);
    idEntity::StopSound(this, channel: SND_CHANNEL_ENGINE_IDLE, peerMask: 0xFFu);
    v3 = gameLocal;
  }
  idGameLocal::BotSystems_UnRegisterEntity(this: v3, entity: this);
  turretWeapon = this->turretWeapon;
  if ( turretWeapon != nullptr )
    ((void (__fastcall *)(idWeapon *, int))turretWeapon->dtr_idClass)(a1: turretWeapon, a2: 1);
  idStr::FreeData(this: &this->flareBindToTag);
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->physicsObj);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeProjectiles);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->inventoryCollection);
  idAnimator_JointMod::~idAnimator_JointMod(this: &this->jointModAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->channelAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->movingHoldAnimator);
  idPhysics_Static::~idPhysics_Static(this: &this->clipModel);
  idAIWorldState::~idAIWorldState(this: &this->worldState);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->faction.relationships);
  idDisassembleLoot::~idDisassembleLoot(this: &this->disassembleLoot);
  idStr::FreeData(this: &this->nameSpinwheel);
  idStr::FreeData(this: &this->namePitch);
  idStr::FreeData(this: &this->nameRotation);
  this->turretHealth.__vftable = (idSimpleHealth_vtbl *)&idBaseHealth::`vftable';
  idAnimator_AF::~idAnimator_AF(this: &this->afProperties);
  if ( this->damageGroups.listStatic == 0 || this->damageGroups.listStatic == 2 )
  {
    list = this->damageGroups.list;
    if ( list != nullptr )
      idListArrayDelete<idDamageGroup>(ptr: list, num: this->damageGroups.size);
    this->damageGroups.list = nullptr;
    this->damageGroups.size = 0;
  }
  this->damageGroups.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggerOnDestroy);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$510154
// EA  : 0x82CFF900
// RVA : 0x00CFF900
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510154()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$510155
// EA  : 0x82CFF928
// RVA : 0x00CFF928
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510155()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5200));
}


// ========================================================================
// __unwind$510156
// EA  : 0x82CFF954
// RVA : 0x00CFF954
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510156()
{
  int v0; // r12

  idList<idDamageGroup,5>::~idList<idDamageGroup,5>(this: (idList<idDamageGroup,5> *)(*(_DWORD *)(v0 - 128 + 148) + 5216));
}


// ========================================================================
// __unwind$510157
// EA  : 0x82CFF980
// RVA : 0x00CFF980
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510157()
{
  int v0; // r12

  idAnimator_AF::~idAnimator_AF(this: (idAnimator_AF *)(*(_DWORD *)(v0 - 128 + 148) + 5248));
}


// ========================================================================
// __unwind$510158
// EA  : 0x82CFF9AC
// RVA : 0x00CFF9AC
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510158()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(*(_DWORD *)(v0 - 128 + 148) + 6928));
}


// ========================================================================
// __unwind$510159
// EA  : 0x82CFF9D8
// RVA : 0x00CFF9D8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510159()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 7012));
}


// ========================================================================
// __unwind$510160
// EA  : 0x82CFFA04
// RVA : 0x00CFFA04
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510160()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 7044));
}


// ========================================================================
// __unwind$510161
// EA  : 0x82CFFA30
// RVA : 0x00CFFA30
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510161()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 7076));
}


// ========================================================================
// __unwind$510162
// EA  : 0x82CFFA5C
// RVA : 0x00CFFA5C
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510162()
{
  int v0; // r12

  idDisassembleLoot::~idDisassembleLoot(this: (idDisassembleLoot *)(*(_DWORD *)(v0 - 128 + 148) + 7144));
}


// ========================================================================
// __unwind$510163
// EA  : 0x82CFFA88
// RVA : 0x00CFFA88
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510163()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 128 + 148) + 7172));
}


// ========================================================================
// __unwind$510164
// EA  : 0x82CFFAB4
// RVA : 0x00CFFAB4
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510164()
{
  int v0; // r12

  idAIWorldState::~idAIWorldState(this: (idAIWorldState *)(*(_DWORD *)(v0 - 128 + 148) + 7376));
}


// ========================================================================
// __unwind$510165
// EA  : 0x82CFFAE0
// RVA : 0x00CFFAE0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510165()
{
  int v0; // r12

  idPhysics_Static::~idPhysics_Static(this: (idPhysics_Static *)(*(_DWORD *)(v0 - 128 + 148) + 12672));
}


// ========================================================================
// __unwind$510166
// EA  : 0x82CFFB0C
// RVA : 0x00CFFB0C
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510166()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 12880));
}


// ========================================================================
// __unwind$510167
// EA  : 0x82CFFB38
// RVA : 0x00CFFB38
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510167()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 12976));
}


// ========================================================================
// __unwind$510168
// EA  : 0x82CFFB64
// RVA : 0x00CFFB64
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510168()
{
  int v0; // r12

  idAnimator_JointMod::~idAnimator_JointMod(this: (idAnimator_JointMod *)(*(_DWORD *)(v0 - 128 + 148) + 13072));
}


// ========================================================================
// __unwind$510169
// EA  : 0x82CFFB90
// RVA : 0x00CFFB90
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510169()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 13164));
}


// ========================================================================
// __unwind$510170
// EA  : 0x82CFFBBC
// RVA : 0x00CFFBBC
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510170()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 13964));
}


// ========================================================================
// __unwind$510171
// EA  : 0x82CFFBE8
// RVA : 0x00CFFBE8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510171()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 128 + 148) + 13984));
}


// ========================================================================
// __unwind$510172
// EA  : 0x82CFFC14
// RVA : 0x00CFFC14
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510172()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 14628));
}


// ========================================================================
// ??0idRailTurret@@QAA@XZ
// EA  : 0x82CFFC48
// RVA : 0x00CFFC48
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

idRailTurret *__fastcall idRailTurret::idRailTurret(idRailTurret *this)
{
  idTurret::idTurret(this);
  this->trackSpeed = 1.0;
  this->__vftable = (idRailTurret_vtbl *)&idRailTurret::`vftable';
  this->startTrack.spawnId.value = 0x1FFF;
  this->plannedPath.list = nullptr;
  this->plannedPath.granularity = 0;
  this->plannedPath.memTag = 5;
  this->plannedPath.listStatic = 0;
  this->plannedPath.size = 0;
  this->plannedPath.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->plannedPath);
  this->plannedPathIndex = 0;
  this->startSpline = nullptr;
  this->currentSpline = nullptr;
  this->currentSplinePath.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// __unwind$510477
// EA  : 0x82CFFCD8
// RVA : 0x00CFFCD8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510477()
{
  int v0; // r12

  idTurret::~idTurret(this: *(idTurret **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idRailTurret@@UAA@XZ
// EA  : 0x82CFFD08
// RVA : 0x00CFFD08
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __fastcall idRailTurret::~idRailTurret(idRailTurret *this)
{
  this->__vftable = (idRailTurret_vtbl *)&idRailTurret::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->plannedPath);
  idTurret::~idTurret(this);
}


// ========================================================================
// __unwind$510540
// EA  : 0x82CFFD5C
// RVA : 0x00CFFD5C
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void _unwind_510540()
{
  int v0; // r12

  idTurret::~idTurret(this: *(idTurret **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTowerTurret@@QAA@XZ
// EA  : 0x82CFFD88
// RVA : 0x00CFFD88
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

idTowerTurret *__fastcall idTowerTurret::idTowerTurret(idTowerTurret *this)
{
  idTurret::idTurret(this);
  this->breakableBody = nullptr;
  this->__vftable = (idTowerTurret_vtbl *)&idTowerTurret::`vftable';
  this->breakableHead = nullptr;
  this->towerGunner.spawnId.value = 0x1FFF;
  this->debrisScale.x = 1.0;
  this->debrisScale.y = 1.0;
  this->debrisScale.z = 1.0;
  return this;
}


// ========================================================================
// `dynamic initializer for 'turret_ShowAngles''
// EA  : 0x8337A1C0
// RVA : 0x0137A1C0
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__turret_ShowAngles__()
{
  idCVar::idCVar(
    this: &turret_ShowAngles,
    name: "turret_ShowAngles",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__turret_ShowAngles__);
}


// ========================================================================
// `dynamic initializer for 'turret_debug''
// EA  : 0x8337A218
// RVA : 0x0137A218
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__turret_debug__()
{
  idCVar::idCVar(
    this: &turret_debug,
    name: "turret_debug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__turret_debug__);
}


// ========================================================================
// `dynamic initializer for 'turret_debugTurning''
// EA  : 0x8337A270
// RVA : 0x0137A270
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__turret_debugTurning__()
{
  idCVar::idCVar(
    this: &turret_debugTurning,
    name: "turret_debugTurning",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__turret_debugTurning__);
}


// ========================================================================
// `dynamic initializer for 'turret_useDeferredFiring''
// EA  : 0x8337A2C8
// RVA : 0x0137A2C8
// PDB : w:\tech5\tungsten\game\entities\turret.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__turret_useDeferredFiring__()
{
  idCVar::idCVar(
    this: &turret_useDeferredFiring,
    name: "turret_useDeferredFiring",
    value: "1",
    flags: 1,
    description: "set to use deferred firing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__turret_useDeferredFiring__);
}

