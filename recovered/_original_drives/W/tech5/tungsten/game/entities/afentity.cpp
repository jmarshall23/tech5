
// ========================================================================
// ??1idAFEntity_Generic@@UAA@XZ
// EA  : 0x82BECF68
// RVA : 0x00BECF68
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Generic::~idAFEntity_Generic(idAFEntity_Generic *this)
{
  this->__vftable = (idAFEntity_Generic_vtbl *)&idAFEntity_Generic::`vftable';
  idAnimator_AF::~idAnimator_AF(this: &this->afProperties);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$488190
// EA  : 0x82BECFBC
// RVA : 0x00BECFBC
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_488190()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?ShowEditingDialog@idAFEntity_Generic@@UAAXXZ
// EA  : 0x82BECFE8
// RVA : 0x00BECFE8
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Generic::ShowEditingDialog(idAFEntity_Generic *this)
{
  common->InitTool(this: common, a2: EDITOR_AF);
}


// ========================================================================
// ?UpdateEditingDialog@idAFEntity_Generic@@UAAXXZ
// EA  : 0x82BED008
// RVA : 0x00BED008
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Generic::UpdateEditingDialog(idAFEntity_Generic *this)
{
  common->UpdateTool(this: common, a2: EDITOR_AF);
}


// ========================================================================
// ??0idAFEntity_Generic@@QAA@XZ
// EA  : 0x82BED030
// RVA : 0x00BED030
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

idAFEntity_Generic *__fastcall idAFEntity_Generic::idAFEntity_Generic(idAFEntity_Generic *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idAFEntity_Generic_vtbl *)&idAFEntity_Generic::`vftable';
  idAnimator_AF::idAnimator_AF(this: &this->afProperties);
  this->keepRunningPhysics = false;
  this->noDrop = false;
  this->initVelocity.z = 0.0;
  this->initVelocity.y = 0.0;
  this->initVelocity.x = 0.0;
  this->initAVelocity.z = 0.0;
  this->initAVelocity.y = 0.0;
  this->initAVelocity.x = 0.0;
  this->initVelocityDelay = 0.0;
  this->initAVelocityDelay = 0.0;
  return this;
}


// ========================================================================
// __unwind$488840_1
// EA  : 0x82BED0C8
// RVA : 0x00BED0C8
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_488840_1()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?InitTestAF@idAFEntity_Generic@@QAAXXZ
// EA  : 0x82BED150
// RVA : 0x00BED150
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Generic::InitTestAF(idAFEntity_Generic *this)
{
  char flags; // r11

  flags = (char)this->flags;
  this->keepRunningPhysics = true;
  *(_BYTE *)&this->flags = flags | 0x22;
}


// ========================================================================
// ?Think@idAFEntity_Generic@@UAAXXZ
// EA  : 0x82BED168
// RVA : 0x00BED168
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Generic::Think(idAFEntity_Generic *this)
{
  idAnimator_AF *p_afProperties; // r30
  struct idPhysics_AF *p_physicsObj; // r29
  bool v4; // r28
  int v5; // r3

  p_afProperties = &this->afProperties;
  p_physicsObj = &this->afProperties.physicsObj;
  v4 = idEntity::GetPhysics(this) != (idPhysics *)&this->afProperties.physicsObj;
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idAnimator_AF::Sync(this: p_afProperties, time: v5, runPhysics: v4);
  idEntity::RunPhysics(this);
  if ( this->afProperties.physicsObj.IsAtRest(this: p_physicsObj) )
    idEntity::BecomeInactive(this, flags: 4);
  else
    idEntity::BecomeActive(this, flags: 4);
  idAnimatedEntity::UpdateImpacts(this);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  if ( this->keepRunningPhysics )
    idEntity::BecomeActive(this, flags: 2);
}


// ========================================================================
// ?OnActivate@idAFEntity_Generic@@EAAXPAVidEntity@@@Z
// EA  : 0x82BED230
// RVA : 0x00BED230
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Generic::OnActivate(idAFEntity_Generic *this, idEntity *activator)
{
  idPhysics_AF *p_physicsObj; // r30
  double initVelocityDelay; // fp1
  double initAVelocityDelay; // fp1
  const idEventArg *v6; // [sp+50h] [-40h]

  p_physicsObj = &this->afProperties.physicsObj;
  this->Show(this);
  this->afProperties.physicsObj.noImpact = false;
  p_physicsObj->Activate(this: p_physicsObj);
  initVelocityDelay = this->initVelocityDelay;
  if ( initVelocityDelay == 0.0 )
  {
    p_physicsObj->SetLinearVelocity(this: p_physicsObj, a2: &this->initVelocity, a3: 0);
  }
  else
  {
    HIBYTE(v6) = 118;
    idEventReceiver::PostEventSec(this, ev: &EV_SetLinearVelocity, time: initVelocityDelay, arg1: v6);
  }
  initAVelocityDelay = this->initAVelocityDelay;
  if ( initAVelocityDelay == 0.0 )
  {
    p_physicsObj->SetAngularVelocity(this: p_physicsObj, a2: &this->initAVelocity, a3: 0);
  }
  else
  {
    HIBYTE(v6) = 118;
    idEventReceiver::PostEventSec(this, ev: &EV_SetAngularVelocity, time: initAVelocityDelay, arg1: v6);
  }
}


// ========================================================================
// ?StartRagdoll@idAFEntity_Dummy@@AAAXXZ
// EA  : 0x82BED370
// RVA : 0x00BED370
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Dummy::StartRagdoll(idAFEntity_Dummy *this)
{
  idAnimator_AF *p_afProperties; // r30
  char v3; // r11
  int v4; // r3
  idPhysics *Physics; // r3
  idPhysics *v6; // r3
  idPhysics *v7; // r3
  idPhysics *v8; // r3

  p_afProperties = &this->afProperties;
  if ( this->afProperties.isActive || (v3 = 0, this->afProperties.isClientAuthoritativeActive) )
    v3 = 1;
  if ( v3 == 0 )
  {
    this->afProperties.physicsObj.PutToRest(this: &this->afProperties.physicsObj);
    this->phys.DisableClip(this: &this->phys);
    p_afProperties->physicsObj.EnableClip(this: &p_afProperties->physicsObj);
    v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAnimator_AF::StartFromCurrentPose(
      this: p_afProperties,
      time: v4,
      inheritAnimationVelocity_: false,
      inheritOverrideVelocity_: false,
      overrideVelocity_: &vec3_origin);
    idEntity::UpdateVisuals(this);
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 4096, a3: -1);
    v6 = idEntity::GetPhysics(this);
    v6->SetClipMask(this: v6, a2: 106513, a3: -1);
  }
  v7 = idEntity::GetPhysics(this);
  if ( v7->IsAtRest(this: v7) )
  {
    v8 = idEntity::GetPhysics(this);
    this->ActivatePhysics(this, a2: v8->physicsId);
  }
}


// ========================================================================
// ?OnActivate@idAFEntity_Dummy@@EAAXPAVidEntity@@@Z
// EA  : 0x82BED8F8
// RVA : 0x00BED8F8
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Dummy::OnActivate(idAFEntity_Dummy *this, idEntity *activator)
{
  char v2; // r11

  if ( this->afProperties.isActive || (v2 = 0, this->afProperties.isClientAuthoritativeActive) )
    v2 = 1;
  if ( v2 == 0 )
    idAFEntity_Dummy::StartRagdoll(this);
}


// ========================================================================
// ?LoadAF@idAFEntity_Generic@@QAA_NPBVidDeclAF@@@Z
// EA  : 0x82BEDAF8
// RVA : 0x00BEDAF8
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

int __fastcall idAFEntity_Generic::LoadAF(idAFEntity_Generic *this, const idDeclAF *decl)
{
  idAnimator_AF *p_afProperties; // r29
  int v4; // r11
  int entityNumber; // r28
  idVec3 *p_gravity; // r27
  idSoundEmitter *SoundEmitter; // r26
  idClip *p_clip; // r24
  idAnimStack *v9; // r3
  idPhysics_AF_vtbl *v11; // r28
  idRotation *v12; // r3
  idPhysicsCallbacks *v13; // [sp+8h] [-E8h]
  int v14; // [sp+Ch] [-E4h]
  int v15; // [sp+10h] [-E0h]
  int v16; // [sp+14h] [-DCh]
  int v17; // [sp+18h] [-D8h]
  int v18; // [sp+1Ch] [-D4h]
  int v19; // [sp+20h] [-D0h]
  int v20; // [sp+24h] [-CCh]
  int v21; // [sp+28h] [-C8h]
  int v22; // [sp+2Ch] [-C4h]
  int v23; // [sp+30h] [-C0h]
  int v24; // [sp+34h] [-BCh]
  int v25; // [sp+38h] [-B8h]
  int v26; // [sp+3Ch] [-B4h]
  int v27; // [sp+40h] [-B0h]
  int v28; // [sp+44h] [-ACh]
  int v29; // [sp+48h] [-A8h]
  int v30; // [sp+4Ch] [-A4h]
  int v31; // [sp+50h] [-A0h]
  idMat3 v32[4]; // [sp+60h] [-90h] BYREF

  this->afProperties.articulatedFigure = decl;
  p_afProperties = &this->afProperties;
  if ( this != nullptr )
    v4 = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v4 = 0x1FFF;
  this->defaultPhysicsCallbacks.ent.spawnId.value = v4;
  this->defaultPhysicsCallbacks.af = p_afProperties;
  entityNumber = this->entityNumber;
  p_gravity = &gameLocal->clientGame.gravity;
  SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
  p_clip = &clientGame->clip;
  v9 = this->GetAnimStack_2(this);
  if ( (unsigned __int8)idAnimator_AF::InitAF(
                          this: p_afProperties,
                          animStack: v9,
                          clip: p_clip,
                          impactManager: &this->impactManager,
                          soundEmitter: SoundEmitter,
                          soundChannel: SND_CHANNEL_BODY3,
                          gravityVector: p_gravity,
                          entityNumber,
                          callback: v13,
                          a10: v14,
                          a11: v15,
                          a12: v16,
                          a13: v17,
                          a14: v18,
                          a15: v19,
                          a16: v20,
                          a17: v21,
                          a18: v22,
                          a19: v23,
                          a20: v24,
                          a21: v25,
                          a22: v26,
                          a23: v27,
                          a24: v28,
                          a25: v29,
                          a26: v30,
                          a27: v31,
                          a28: &this->defaultPhysicsCallbacks) != 0 )
  {
    v11 = p_afProperties->physicsObj.__vftable;
    v12 = idMat3::ToRotation(this: v32, result: (idRotation *)&this->spawnOrientation);
    v11->Rotate(this: &p_afProperties->physicsObj, a2: v12, a3: -1);
    p_afProperties->physicsObj.Translate(this: &p_afProperties->physicsObj, a2: &this->spawnPosition, a3: -1);
    p_afProperties->physicsObj.PutToRest(this: &p_afProperties->physicsObj);
    if ( !this->noDrop )
      p_afProperties->physicsObj.Activate(this: &p_afProperties->physicsObj);
    idEntity::SetPhysics(this, phys: &p_afProperties->physicsObj.idPhysics_DynamicBase);
    idAnimator_AF::Start(this: p_afProperties);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "idAFEntity_Generic::Spawn: Couldn't load articulated figure on entity '%s'", this->name.data);
    return 0;
  }
}


// ========================================================================
// ?Spawn@idAFEntity_Dummy@@QAAXXZ
// EA  : 0x82BEDC88
// RVA : 0x00BEDC88
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Dummy::Spawn(idAFEntity_Dummy *this)
{
  idAnimator_AF *p_afProperties; // r29
  idGameTimeManager *v3; // r3
  int entityNumber; // r23
  idVec3 *p_gravity; // r24
  idSoundEmitter *SoundEmitter; // r22
  idClip *p_clip; // r20
  idAnimStack *v8; // r3
  idGameTimeManager *v9; // r3
  idPresentable *presentable; // r3
  idPresentableAnimatedEntity *v11; // r4
  idPhysics *Physics; // r3
  const idBounds *v13; // r3
  idPhysicsCallbacks *v14; // [sp+8h] [-158h]
  int v15; // [sp+Ch] [-154h]
  int v16; // [sp+10h] [-150h]
  int v17; // [sp+14h] [-14Ch]
  int v18; // [sp+18h] [-148h]
  int v19; // [sp+1Ch] [-144h]
  int v20; // [sp+20h] [-140h]
  int v21; // [sp+24h] [-13Ch]
  int v22; // [sp+28h] [-138h]
  int v23; // [sp+2Ch] [-134h]
  int v24; // [sp+30h] [-130h]
  int v25; // [sp+34h] [-12Ch]
  int v26; // [sp+38h] [-128h]
  int v27; // [sp+3Ch] [-124h]
  int v28; // [sp+40h] [-120h]
  int v29; // [sp+44h] [-11Ch]
  int v30; // [sp+48h] [-118h]
  int v31; // [sp+4Ch] [-114h]
  int v32; // [sp+50h] [-110h]
  idAnimatorParms_Base v33; // [sp+70h] [-F0h] BYREF
  idAnimatorParms_Base v34; // [sp+B0h] [-B0h] BYREF

  p_afProperties = &this->afProperties;
  v33.animStack = (idAnimStack *)((int (*)(void))this->GetAnimStack_2)();
  idStr::idStr(this: &v33.name, text: "af");
  memset(&v33.originBlend, 0, 12);
  v33.blendOp = BOP_LERP;
  v33.alpha = 1.0;
  v3 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: p_afProperties, gametimeManager: v3, parms: &v33);
  this->defaultPhysicsCallbacks.ent.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13)
                                                  | this->entityNumber;
  this->defaultPhysicsCallbacks.af = p_afProperties;
  entityNumber = this->entityNumber;
  p_gravity = &gameLocal->clientGame.gravity;
  SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
  p_clip = &clientGame->clip;
  v8 = this->GetAnimStack_2(this);
  if ( (unsigned __int8)idAnimator_AF::InitAF(
                          this: p_afProperties,
                          animStack: v8,
                          clip: p_clip,
                          impactManager: &this->impactManager,
                          soundEmitter: SoundEmitter,
                          soundChannel: SND_CHANNEL_BODY3,
                          gravityVector: p_gravity,
                          entityNumber,
                          callback: v14,
                          a10: v15,
                          a11: v16,
                          a12: v17,
                          a13: v18,
                          a14: v19,
                          a15: v20,
                          a16: v21,
                          a17: v22,
                          a18: v23,
                          a19: v24,
                          a20: v25,
                          a21: v26,
                          a22: v27,
                          a23: v28,
                          a24: v29,
                          a25: v30,
                          a26: v31,
                          a27: v32,
                          a28: &this->defaultPhysicsCallbacks) != 0 )
  {
    v34.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v34.name, text: "all");
    v34.alpha = 1.0;
    v34.blendOp = BOP_LERP;
    memset(&v34.originBlend, 0, 12);
    v9 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->channelAnimator, gametimeManager: v9, parms: &v34);
    idAnimatedEntity::SetRadiusDamageJointIndices(this, jointNames: &this->radiusDamageJointNames);
    this->Reset(this);
    if ( this->goreDef != nullptr )
    {
      presentable = this->presentable;
      if ( presentable != nullptr )
        v11 = presentable->GetAnimatedEntityInterface(this: presentable);
      else
        v11 = nullptr;
      idGoreComponent::Init(this: &this->goreComponent, inPresentable: v11, inGoreDecl: this->goreDef);
    }
    Physics = idEntity::GetPhysics(this);
    v13 = Physics->GetAbsBounds(this: Physics, a2: -1);
    idEntity::UpdatePVSAreas(this, bounds: v13);
    idStr::FreeData(this: &v34.name);
  }
  else
  {
    idLib::Warning(fmt: "idAFEntity_Dummy::Spawn: Couldn't load articulated figure on entity '%s'", this->name.data);
  }
  idStr::FreeData(this: &v33.name);
}


// ========================================================================
// __unwind$490002_0
// EA  : 0x82BEDEE0
// RVA : 0x00BEDEE0
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490002_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$490003_0
// EA  : 0x82BEDF08
// RVA : 0x00BEDF08
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490003_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 352 + 176));
}


// ========================================================================
// ?Reset@idAFEntity_Dummy@@UAAXXZ
// EA  : 0x82BEDF30
// RVA : 0x00BEDF30
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Dummy::Reset(idAFEntity_Dummy *this)
{
  idMat3 *p_spawnOrientation; // r28
  idPhysics_AF_vtbl *v2; // r27
  idAnimator_AF *p_afProperties; // r30
  struct idPhysics_AF *p_physicsObj; // r29
  idRotation *v6; // r3
  int entityNumber; // r6
  idPhysics_Static *p_phys; // r30
  idPhysics_Static_vtbl *v9; // r29
  idClipModel *MoveableClipModel; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  idPresentable *presentable; // r3
  idAnimStack *v13; // r28
  idGameTimeManager *v14; // r3
  int GameMs; // r27
  const idAnimStack *v16; // r3
  __int64 v17; // r8
  int v18; // r29
  const idAnimStack *v19; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v20; // [sp+50h] [-D0h] BYREF
  char v21; // [sp+52h] [-CEh] BYREF
  char v22; // [sp+54h] [-CCh] BYREF
  char v23; // [sp+56h] [-CAh] BYREF
  char v24; // [sp+58h] [-C8h] BYREF
  char v25; // [sp+5Ah] [-C6h] BYREF
  char v26; // [sp+5Ch] [-C4h] BYREF
  char v27; // [sp+5Eh] [-C2h] BYREF
  char v28; // [sp+60h] [-C0h] BYREF
  blendParms_t v29; // [sp+70h] [-B0h] BYREF
  idMat3 v30[4]; // [sp+90h] [-90h] BYREF

  p_spawnOrientation = &this->spawnOrientation;
  v2 = this->afProperties.physicsObj.__vftable;
  p_afProperties = &this->afProperties;
  p_physicsObj = &this->afProperties.physicsObj;
  v6 = idMat3::ToRotation(this: v30, result: (idRotation *)&this->spawnOrientation);
  v2->Rotate(this: p_physicsObj, a2: v6, a3: -1);
  this->afProperties.physicsObj.Translate(this: p_physicsObj, a2: &this->spawnPosition, a3: -1);
  idAnimator_AF::Stop(this: p_afProperties);
  entityNumber = this->entityNumber;
  p_phys = &this->phys;
  *(_BYTE *)&this->flags |= 2u;
  idPhysics::InitPhysics(
    this: &this->phys,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: entityNumber);
  this->phys.SetGravity(this: &this->phys, a2: &gameLocal->clientGame.gravity);
  if ( !this->useSphereModels )
  {
    v9 = p_phys->__vftable;
    MoveableClipModel = idEntity::CreateMoveableClipModel(this, barrelCollision: false, overrideRadius: -1.0);
    ((void (__fastcall *)(idPhysics_Static *, idClipModel *, double))v9->SetClipModel)(
      a1: &this->phys,
      a2: MoveableClipModel,
      a3: 0.0020000001);
  }
  p_phys->SetContents(this: &this->phys, a2: 131073, a3: -1);
  p_phys->PutToRest(this: &this->phys);
  p_phys->SetOrigin(this: &this->phys, a2: &this->spawnPosition, a3: -1);
  p_phys->SetAxis(this: &this->phys, a2: p_spawnOrientation, a3: -1);
  idEntity::SetPhysics(this, phys: &this->phys);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  gameAnimTools->VerifyStrongAliasRefs(
    this: gameAnimTools,
    a2: TreeAnimatorFromPresentable,
    a3: &this->idleAnimHandle,
    a4: this->name.data);
  gameAnimTools->VerifyStrongAliasRefs(
    this: gameAnimTools,
    a2: TreeAnimatorFromPresentable,
    a3: &this->deathAnimHandle,
    a4: this->name.data);
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v20, result: TreeAnimatorFromPresentable->decl, aliasName: "turret_nw");
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v21, result: TreeAnimatorFromPresentable->decl, aliasName: "turret_n");
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v22, result: TreeAnimatorFromPresentable->decl, aliasName: "turret_ne");
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v23, result: TreeAnimatorFromPresentable->decl, aliasName: "turret_w");
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v24, result: TreeAnimatorFromPresentable->decl, aliasName: "turret_c");
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v25, result: TreeAnimatorFromPresentable->decl, aliasName: "turret_e");
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v26, result: TreeAnimatorFromPresentable->decl, aliasName: "turret_sw");
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v27, result: TreeAnimatorFromPresentable->decl, aliasName: "turret_s");
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v28, result: TreeAnimatorFromPresentable->decl, aliasName: "turret_se");
  v13 = this->GetAnimStack_2(this);
  v14 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_TurretNxN<3>::SetParameters(
    this: &this->turretAnimator,
    gametimeManager: v14,
    animStack: v13,
    _vertexAliasHandles: &v20,
    additive: false);
  if ( this->idleAnimHandle.value != 0xFFFF )
  {
    blendParms_t::blendParms_t(this: &v29);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v16 = this->GetAnimStack_2(this);
    LODWORD(v17) = &v29;
    idAnimator_Channel::CycleAnim(
      this: &this->channelAnimator,
      stack: v16,
      ah: &this->idleAnimHandle,
      curTime: GameMs,
      rateScale: 1.0,
      leafStarted: v17,
      a7: nullptr);
  }
  v18 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v19 = this->GetAnimStack_2(this);
  idAnimator_Base::Start(this: &this->turretAnimator, stack: v19, curTime: v18, blendDurationMS: 250, reset: true);
  idEntity::BecomeActive(this, flags: 4);
}


// ========================================================================
// ?ForceStartRagdoll@idAFEntity_Dummy@@QAAXPAVidEntity@@PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82BEE2D8
// RVA : 0x00BEE2D8
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Dummy::ForceStartRagdoll(
        idAFEntity_Dummy *this,
        idAFEntity_Dummy *inflictor,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        int a7)
{
  double v12; // fp13
  double v13; // fp12
  idAFEntity_Dummy *v14; // r3
  idPhysics *Physics; // r3
  float *v16; // r3
  int v17; // r29
  int v18; // r30
  int value; // r9
  idEntity *v20; // r3
  idTurret *v21; // r3
  idTurret *v22; // r3
  int v23; // r5
  idAFEntity_Dummy_vtbl *v24; // r11
  double v25; // fp9
  double v26; // fp8
  void (__fastcall *ApplyImpulseFromEntity)(struct idAFEntity_Dummy *, const idEntity *, const int, const idVec3 *, const idVec3 *); // ctr
  float v28; // [sp+50h] [-70h] BYREF
  float v29; // [sp+54h] [-6Ch]
  float v30; // [sp+58h] [-68h]
  float v31[24]; // [sp+60h] [-60h] BYREF

  idAFEntity_Dummy::StartRagdoll(this);
  if ( a7 != 0 )
  {
    v12 = *(float *)(a7 + 8);
    v13 = *(float *)(a7 + 12);
    v28 = *(float *)(a7 + 4);
    v29 = v12;
  }
  else
  {
    v14 = inflictor;
    if ( inflictor == nullptr )
      v14 = this;
    Physics = idEntity::GetPhysics(this: v14);
    v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v28 = *v16;
    v29 = v16[1];
    v13 = v16[2];
  }
  v30 = v13;
  if ( this->TakesDamage(this) )
  {
    v17 = 0;
    if ( this->targets.num > 0 )
    {
      v18 = 0;
      do
      {
        value = this->targets.list[v18].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v20 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v21 = (idTurret *)idEntity::CastTo(c: v20);
        }
        else
        {
          v21 = nullptr;
        }
        v22 = idTurret::CastTo(c: v21);
        if ( v22 != nullptr )
          idTurret::SetState(this: v22, state: TS_DISABLED);
        ++v17;
        ++v18;
      }
      while ( v17 < this->targets.num );
    }
  }
  if ( damageDef->radius <= 0.0 )
  {
    if ( a7 != 0 )
      v23 = *(_DWORD *)(a7 + 116);
    else
      v23 = -1;
    v24 = this->__vftable;
    v25 = (float)(trace->endpos.x * damageDef->ragdollImpulseMag);
    v26 = (float)(trace->endpos.y * damageDef->ragdollImpulseMag);
    v31[0] = trace->fraction * damageDef->ragdollImpulseMag;
    v31[1] = v25;
    ApplyImpulseFromEntity = v24->ApplyImpulseFromEntity;
    v31[2] = v26;
    ApplyImpulseFromEntity(this, a2: inflictor, a3: v23, a4: (const idVec3 *)&v28, a5: (const idVec3 *)v31);
  }
}


// ========================================================================
// ?Spawn@idAFEntity_Generic@@QAAXXZ
// EA  : 0x82BEE550
// RVA : 0x00BEE550
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Generic::Spawn(idAFEntity_Generic *this)
{
  idAnimator_AF *p_afProperties; // r29
  idGameTimeManager *v3; // r3
  const idDeclAF *articulatedFigure; // [sp+50h] [-70h]
  idAnimatorParms_Base v5; // [sp+60h] [-60h] BYREF

  p_afProperties = &this->afProperties;
  v5.animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v5.name, text: "af");
  memset(&v5.originBlend, 0, 12);
  v5.blendOp = BOP_LERP;
  v5.alpha = 1.0;
  v3 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: p_afProperties, gametimeManager: v3, parms: &v5);
  articulatedFigure = this->afProperties.articulatedFigure;
  if ( articulatedFigure != nullptr )
    idAFEntity_Generic::LoadAF(this, decl: articulatedFigure);
  *(_BYTE *)&this->flags |= 2u;
  idEntity::UpdateVisuals(this);
  idStr::FreeData(this: &v5.name);
}


// ========================================================================
// __unwind$490470
// EA  : 0x82BEE618
// RVA : 0x00BEE618
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490470()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 192 + 96));
}


// ========================================================================
// ??0idAFEntity_Dummy@@QAA@XZ
// EA  : 0x82BEE648
// RVA : 0x00BEE648
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

idAFEntity_Dummy *__fastcall idAFEntity_Dummy::idAFEntity_Dummy(idAFEntity_Dummy *this)
{
  char flags; // r4

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idAFEntity_Dummy_vtbl *)&idAFEntity_Dummy::`vftable';
  idAnimator_AF::idAnimator_AF(this: &this->afProperties);
  idPhysics_Static::idPhysics_Static(this: &this->phys);
  idAnimator_Channel::idAnimator_Channel(this: &this->channelAnimator);
  this->idleAnimHandle.value = -1;
  this->deathAnimHandle.value = -1;
  this->radiusDamageJointNames.granularity = 0;
  this->radiusDamageJointNames.listStatic = 0;
  this->radiusDamageJointNames.memTag = 5;
  this->radiusDamageJointNames.list = nullptr;
  this->radiusDamageJointNames.size = 0;
  this->radiusDamageJointNames.num = 0;
  idGoreComponent::idGoreComponent(this: &this->goreComponent);
  idAnimator_TurretNxN<3>::idAnimator_TurretNxN<3>(this: &this->turretAnimator);
  idMQBuffer::idMQBuffer(this: &this->attachments);
  flags = (char)this->flags;
  this->attachments.parent = this;
  this->playedDeathAnim = false;
  this->takesDamage = true;
  this->isEnemyOfPlayer = false;
  this->hasRagDolledYet = false;
  this->useSphereModels = false;
  this->goreDef = nullptr;
  this->numHitsToKill = 1;
  *(_BYTE *)&this->flags = flags | 0x40;
  return this;
}


// ========================================================================
// __unwind$490513
// EA  : 0x82BEE724
// RVA : 0x00BEE724
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490513()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490514
// EA  : 0x82BEE74C
// RVA : 0x00BEE74C
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490514()
{
  int v0; // r12

  idAnimator_AF::~idAnimator_AF(this: (idAnimator_AF *)(*(_DWORD *)(v0 - 128 + 148) + 5200));
}


// ========================================================================
// __unwind$490515
// EA  : 0x82BEE778
// RVA : 0x00BEE778
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490515()
{
  int v0; // r12

  idPhysics_Static::~idPhysics_Static(this: (idPhysics_Static *)(*(_DWORD *)(v0 - 128 + 148) + 6808));
}


// ========================================================================
// __unwind$490516
// EA  : 0x82BEE7A4
// RVA : 0x00BEE7A4
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490516()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 6976));
}


// ========================================================================
// __unwind$490517
// EA  : 0x82BEE7D0
// RVA : 0x00BEE7D0
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490517()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 7084));
}


// ========================================================================
// __unwind$490518
// EA  : 0x82BEE7FC
// RVA : 0x00BEE7FC
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490518()
{
  int v0; // r12

  idGoreComponent::~idGoreComponent(this: (idGoreComponent *)(*(_DWORD *)(v0 - 128 + 148) + 7112));
}


// ========================================================================
// __unwind$490519
// EA  : 0x82BEE828
// RVA : 0x00BEE828
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490519()
{
  int v0; // r12

  idAnimator_TurretNxN<3>::~idAnimator_TurretNxN<3>(this: (idAnimator_TurretNxN<3> *)(*(_DWORD *)(v0 - 128 + 148) + 7232));
}


// ========================================================================
// ??1idAFEntity_Dummy@@UAA@XZ
// EA  : 0x82BEE880
// RVA : 0x00BEE880
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Dummy::~idAFEntity_Dummy(idAFEntity_Dummy *this)
{
  idStr *list; // r3

  this->__vftable = (idAFEntity_Dummy_vtbl *)&idAFEntity_Dummy::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachments);
  idAnimator_Synced::~idAnimator_Synced(this: &this->turretAnimator);
  idGoreComponent::~idGoreComponent(this: &this->goreComponent);
  if ( this->radiusDamageJointNames.listStatic == 0 || this->radiusDamageJointNames.listStatic == 2 )
  {
    list = this->radiusDamageJointNames.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->radiusDamageJointNames.size);
    this->radiusDamageJointNames.list = nullptr;
    this->radiusDamageJointNames.size = 0;
  }
  this->radiusDamageJointNames.num = 0;
  idAnimator_Channel::~idAnimator_Channel(this: &this->channelAnimator);
  idPhysics_Static::~idPhysics_Static(this: &this->phys);
  idAnimator_AF::~idAnimator_AF(this: &this->afProperties);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$490607
// EA  : 0x82BEE91C
// RVA : 0x00BEE91C
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490607()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490608
// EA  : 0x82BEE944
// RVA : 0x00BEE944
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490608()
{
  int v0; // r12

  idAnimator_AF::~idAnimator_AF(this: (idAnimator_AF *)(*(_DWORD *)(v0 - 112 + 132) + 5200));
}


// ========================================================================
// __unwind$490609
// EA  : 0x82BEE970
// RVA : 0x00BEE970
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490609()
{
  int v0; // r12

  idPhysics_Static::~idPhysics_Static(this: (idPhysics_Static *)(*(_DWORD *)(v0 - 112 + 132) + 6808));
}


// ========================================================================
// __unwind$490610
// EA  : 0x82BEE99C
// RVA : 0x00BEE99C
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490610()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 6976));
}


// ========================================================================
// __unwind$490611
// EA  : 0x82BEE9C8
// RVA : 0x00BEE9C8
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490611()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 7084));
}


// ========================================================================
// __unwind$490612
// EA  : 0x82BEE9F4
// RVA : 0x00BEE9F4
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490612()
{
  int v0; // r12

  idGoreComponent::~idGoreComponent(this: (idGoreComponent *)(*(_DWORD *)(v0 - 112 + 132) + 7112));
}


// ========================================================================
// __unwind$490613
// EA  : 0x82BEEA20
// RVA : 0x00BEEA20
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490613()
{
  int v0; // r12

  idAnimator_TurretNxN<3>::~idAnimator_TurretNxN<3>(this: (idAnimator_TurretNxN<3> *)(*(_DWORD *)(v0 - 112 + 132) + 7232));
}


// ========================================================================
// ?Damage@idAFEntity_Dummy@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82BEEA50
// RVA : 0x00BEEA50
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

float __fastcall idAFEntity_Dummy::Damage(
        idAFEntity_Dummy *this,
        idAFEntity_Dummy *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        int a8)
{
  int v14; // r11
  int GameMs; // r27
  const idAnimStack *v16; // r3
  const blendParms_t *v17; // r7
  double v18; // fp1
  blendParms_t v20; // [sp+50h] [-70h] BYREF

  if ( this->takesDamage )
  {
    v14 = this->numHitsToKill - 1;
    this->numHitsToKill = v14;
    if ( v14 <= 0 )
    {
      if ( this->isEnemyOfPlayer && !this->hasRagDolledYet )
      {
        this->hasRagDolledYet = true;
        if ( attacker != nullptr )
          ++attacker->entitiesKilled;
        if ( inflictor != nullptr )
          ++inflictor->entitiesKilled;
        idRageMetrics::Kill(this: clientGame->rageMetrics, killer: attacker, victim: this, inflictor, damageDef);
      }
      if ( this->deathAnimHandle.value == 0xFFFF || this->playedDeathAnim )
      {
        if ( !this->playedDeathAnim )
          idAFEntity_Dummy::ForceStartRagdoll(
            this,
            inflictor,
            damageDef,
            damageScale,
            dir: (const idVec3 *)damageDef,
            trace,
            a7: a8);
      }
      else
      {
        blendParms_t::blendParms_t(this: &v20);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v16 = this->GetAnimStack_2(this);
        idAnimator_Channel::PlayAnim(
          this: &this->channelAnimator,
          stack: v16,
          ah: &this->deathAnimHandle,
          curTime: GameMs,
          rateScale: 1.0,
          blendParms: v17,
          blendOutDurationMS_: &v20,
          leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
          a9: nullptr);
        this->playedDeathAnim = true;
      }
    }
    if ( damageDef != nullptr && a8 != 0 && *(_DWORD *)(a8 + 52) == 4 )
      idGoreComponent::AddDamage(
        this: &this->goreComponent,
        hitJoint: (idIndex<short,enum invalidJointIndex_t> *)(__int16)*(_DWORD *)(a8 + 104),
        damageDecl: damageDef,
        damage: (float)(damageDef->maxDamage * (float)2.0),
        impulse: (const idVec3 *)damageDef,
        pos: (const idVec3 *)trace,
        normal: (const idVec3 *)(a8 + 4),
        damageGroup: (const idDamageGroup *)(a8 + 68));
  }
  v18 = 0.0;
  return *((float *)&v18 + 1);
}


// ========================================================================
// ?Think@idAFEntity_Dummy@@UAAXXZ
// EA  : 0x82BEEC78
// RVA : 0x00BEEC78
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __fastcall idAFEntity_Dummy::Think(idAFEntity_Dummy *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  bool v4; // r28
  int v5; // r3
  char v6; // r11
  int num; // r11
  int v8; // r28
  int v9; // r29
  int value; // r9
  idEntity *v11; // r3
  idTurret *v12; // r3
  idTurret *v13; // r3
  idPresentable *presentable; // r11
  double v15; // fp1
  double v16; // fp31
  double v17; // fp1
  double v18; // fp0
  double v19; // fp30
  double v20; // fp0
  double v21; // fp31
  idTreeAnimator *TreeAnimatorFromPresentable; // r29
  int GameMs; // r3
  idPhysics *Physics; // r3
  const idBounds *v25; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v27; // r30
  int v28; // r3
  __int64 totalTicks; // r11
  __int64 v30; // r9
  idPLogScope v31; // [sp+58h] [-98h] BYREF
  idVec3 v32; // [sp+60h] [-90h] BYREF
  idVec3 v33; // [sp+70h] [-80h] BYREF
  idMat3 v34; // [sp+80h] [-70h] BYREF

  RD_EventBegin(name: "idAFEntity_Dummy::Think");
  LODWORD(v2) = "idAFEntity_Dummy::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v31, pl: &::pLog, gMask: v2, label: v3);
  if ( idEntity::UpdateDormant(this) )
  {
    idPLogScope::~idPLogScope(this: &v31);
  }
  else
  {
    v4 = idEntity::GetPhysics(this) != (idPhysics *)&this->afProperties.physicsObj;
    v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAnimator_AF::Sync(this: &this->afProperties, time: v5, runPhysics: v4);
    idEntity::RunPhysics(this);
    idEntity::BecomeActive(this, flags: 4);
    if ( this->afProperties.isActive || (v6 = 0, this->afProperties.isClientAuthoritativeActive) )
      v6 = 1;
    if ( v6 == 0 )
    {
      v8 = 0;
      num = this->targets.num;
      if ( num > 0 )
      {
        v9 = 0;
        while ( 1 )
        {
          if ( v8 < num
            && (value = this->targets.list[v9].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
            && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v12 = (idTurret *)idEntity::CastTo(c: v11);
          }
          else
          {
            v12 = nullptr;
          }
          v13 = idTurret::CastTo(c: v12);
          if ( v13 != nullptr )
            break;
          ++v8;
          ++v9;
          num = this->targets.num;
          if ( v8 >= num )
            goto LABEL_34;
        }
        idTurret::GetMuzzleDirection(this: v13, dir: (idVec3 *)&v34.mat[1].y);
        idVec3::ToAngles(this: &v33, result: (idAngles *)&v34.mat[1].y);
        presentable = this->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        idMat3::ToAngles(this: &v34, result: (idAngles *)&presentable->axis);
        v15 = idMath::AngleNormalize360(angle: (float)(v33.y - v34.mat[0].y));
        v16 = v15;
        if ( v15 > 180.0 )
          v16 = (float)((float)v15 - (float)360.0);
        v17 = idMath::AngleNormalize360(angle: (float)(v33.x - v34.mat[0].x));
        if ( v17 > 180.0 )
          v17 = (float)((float)v17 - (float)360.0);
        v18 = (float)((float)((float)-1.0 / g_maxTurretYaw.valueFloat) * (float)v16);
        if ( v18 >= -0.99000001 )
        {
          if ( v18 <= 0.99000001 )
            v19 = (float)((float)((float)-1.0 / g_maxTurretYaw.valueFloat) * (float)v16);
          else
            v19 = 0.99000001;
        }
        else
        {
          v19 = -0.99000001;
        }
        v20 = -(float)((float)v17 / g_maxTurretPitch.valueFloat);
        if ( v20 >= -0.99000001 )
        {
          if ( v20 <= 0.99000001 )
            v21 = -(float)((float)v17 / g_maxTurretPitch.valueFloat);
          else
            v21 = 0.99000001;
        }
        else
        {
          v21 = -0.99000001;
        }
        TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v32.x = v19;
        v32.y = v21;
        v32.z = 1.0;
        idAnimator_TurretNxN<3>::Update(
          this: &this->turretAnimator,
          point: &v32,
          time: GameMs,
          animator: TreeAnimatorFromPresentable);
      }
    }
LABEL_34:
    idAnimatedEntity::UpdateImpacts(this);
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    idGoreComponent::UpdateGore(this: &this->goreComponent);
    idGoreComponent::CheckForGore(this: &this->goreComponent);
    Physics = idEntity::GetPhysics(this);
    v25 = Physics->GetAbsBounds(this: Physics, a2: -1);
    idEntity::UpdatePVSAreas(this, bounds: v25);
    if ( v31.logIndex >= 0 )
    {
      pLog = v31.pLog;
      v27 = &v31.pLog->logEntries.list[v31.logIndex];
      v28 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v27->totalTicks;
      HIDWORD(totalTicks) = v27->parent;
      LODWORD(v30) = v28 - totalTicks;
      v27->totalTicks = v30;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$490768
// EA  : 0x82BEEFF0
// RVA : 0x00BEEFF0
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490768()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 156));
}


// ========================================================================
// __unwind$490769_0
// EA  : 0x82BEF018
// RVA : 0x00BEF018
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void _unwind_490769_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 88));
}


// ========================================================================
// `dynamic initializer for 'g_maxTurretYaw''
// EA  : 0x83374918
// RVA : 0x01374918
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_maxTurretYaw__()
{
  idCVar::idCVar(
    this: &g_maxTurretYaw,
    name: "g_maxTurretYaw",
    value: "70",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_maxTurretYaw__);
}


// ========================================================================
// `dynamic initializer for 'g_maxTurretPitch''
// EA  : 0x83374970
// RVA : 0x01374970
// PDB : w:\tech5\tungsten\game\entities\afentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_maxTurretPitch__()
{
  idCVar::idCVar(
    this: &g_maxTurretPitch,
    name: "g_maxTurretPitch",
    value: "40",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_maxTurretPitch__);
}

