
// ========================================================================
// ??1idPresentableAI@@UAA@XZ
// EA  : 0x82B6A420
// RVA : 0x00B6A420
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::~idPresentableAI(idPresentableAI *this)
{
  idClipModel *model; // r3

  this->__vftable = (idPresentableAI_vtbl *)&idPresentableAI::`vftable';
  model = this->attachment.model;
  if ( model != nullptr )
  {
    idClipModel::Delete(this: model);
    this->attachment.model = nullptr;
  }
  idStr::FreeData(this: &this->attachment.name);
  idStr::FreeData(this: &this->painAnimationEventInfo.weaponPrefix);
  idPresentableActor::~idPresentableActor(this);
}


// ========================================================================
// __unwind$488399
// EA  : 0x82B6A49C
// RVA : 0x00B6A49C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void _unwind_488399()
{
  int v0; // r12

  idPresentableActor::~idPresentableActor(this: *(idPresentableActor **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488400
// EA  : 0x82B6A4C4
// RVA : 0x00B6A4C4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void _unwind_488400()
{
  int v0; // r12

  idSubtitles::idPart::~idPart(this: (idSubtitles::idPart *)(*(_DWORD *)(v0 - 112 + 132) + 15632));
}


// ========================================================================
// __unwind$488401
// EA  : 0x82B6A4F0
// RVA : 0x00B6A4F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void _unwind_488401()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(*(_DWORD *)(v0 - 112 + 132) + 15696));
}


// ========================================================================
// ?InternalSplatterBlood@idPresentableAI@@AAAXXZ
// EA  : 0x82B6A530
// RVA : 0x00B6A530
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::InternalSplatterBlood(idPresentableAI *this)
{
  const idDeclGore *goreInfo; // r11
  int num; // r4
  const deferredDecalParams_t *v4; // r30
  double z; // fp7
  double v6; // fp5
  double v7; // fp3
  idDeferredDecalManager *DeferredDecalMgr; // r3
  idVec3 v9; // [sp+50h] [-30h] BYREF

  goreInfo = this->bloodSplatterEventInfo.goreInfo;
  if ( goreInfo != nullptr )
  {
    num = goreInfo->damageSplatterDecals.num;
    if ( num > 0 )
    {
      v4 = &this->bloodSplatterEventInfo.goreInfo->damageSplatterDecals.list[idRandom2::RandomInt(
                                                                               this: &clientGame->random,
                                                                               max: num)];
      if ( v4 != nullptr )
      {
        z = this->bloodSplatterEventInfo.impactPoint.z;
        v6 = (float)(this->bloodSplatterEventInfo.impactDir.z * (float)200.0);
        v7 = (float)(this->bloodSplatterEventInfo.impactPoint.y
                   + (float)(this->bloodSplatterEventInfo.impactDir.y * (float)200.0));
        v9.x = this->bloodSplatterEventInfo.impactPoint.x
             + (float)(this->bloodSplatterEventInfo.impactDir.x * (float)200.0);
        v9.y = v7;
        v9.z = (float)z + (float)v6;
        DeferredDecalMgr = idClientGame::GetDeferredDecalMgr(this: clientGame);
        idDeferredDecalManager::AddDecalFromLineTrace(
          this: DeferredDecalMgr,
          decalParam: v4,
          start: &this->bloodSplatterEventInfo.impactPoint,
          end: &v9,
          clipMask: 1);
      }
    }
  }
}


// ========================================================================
// ?InternalPlayAdditivePain@idPresentableAI@@AAAXXZ
// EA  : 0x82B6A5E8
// RVA : 0x00B6A5E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::InternalPlayAdditivePain(idPresentableAI *this)
{
  idTreeAnimator *TreeAnimator; // r29
  damageDirection_t DamageDirection; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *declTwitchPain; // r4
  idAnimStack *animStack; // r30
  int ServerGameTime; // r3
  const blendParms_t *v7; // r7
  idDeclTwitchPain v8; // [sp+50h] [-50h] BYREF

  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
  idPresentable::UpdateModelTransform(this);
  if ( (unsigned __int16)this->painAnimationEventInfo.joint.value != 0xFFFF && TreeAnimator != nullptr )
  {
    DamageDirection = idActor::GetDamageDirection(
                        axis: &this->axis,
                        dir: &this->painAnimationEventInfo.projDir,
                        numDirs: 2);
    declTwitchPain = (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)this->painAnimationEventInfo.declTwitchPain;
    if ( declTwitchPain != nullptr )
    {
      idDeclTwitchPain::GetTwitchPainAliasHandle(
        this: &v8,
        result: declTwitchPain,
        forModelDef: TreeAnimator->decl,
        weaponPrefix: this->painAnimationEventInfo.weaponPrefix.data,
        damageDir: DamageDirection,
        jointIndex: &this->painAnimationEventInfo.joint);
      if ( HIWORD(v8.__vftable) != 0xFFFF )
      {
        blendParms_t::blendParms_t(this: (blendParms_t *)&v8.resourceListPtr);
        blendParms_t::SetDurationMS(this: (blendParms_t *)&v8.resourceListPtr, ms: 0x96u);
        animStack = this->animStack;
        ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
        idAnimator_Channel::PlayAnim(
          this: this->painAnimator,
          stack: animStack,
          ah: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&v8,
          curTime: ServerGameTime,
          rateScale: 1.0,
          blendParms: v7,
          blendOutDurationMS_: (blendParms_t *)&v8.resourceListPtr,
          leafStarted: (idMD6LeafPlay **)0x12C,
          a9: nullptr);
      }
    }
  }
}


// ========================================================================
// ?InternalLootBody@idPresentableAI@@AAAXXZ
// EA  : 0x82B6A6B8
// RVA : 0x00B6A6B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::InternalLootBody(idPresentableAI *this)
{
  idPresentablePlayer *LocalPresentablePlayer; // r3
  idPresentablePlayer *v3; // r30
  idAnimator_AF *AnimatorBySerializeType; // r3
  idPhysics_AF *p_physicsObj; // r31
  int v6; // r28
  idClipModel *clipModel; // r11
  float y; // r9
  float z; // r8
  float *v10; // r3
  double v11; // fp7
  double v12; // fp6
  float x; // [sp+50h] [-60h] BYREF
  float v14; // [sp+54h] [-5Ch]
  float v15; // [sp+58h] [-58h]
  idVec3 v16; // [sp+60h] [-50h] BYREF
  float v17[16]; // [sp+70h] [-40h] BYREF

  LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this: clientGame);
  v3 = LocalPresentablePlayer;
  if ( this->animStack != nullptr )
  {
    if ( LocalPresentablePlayer == nullptr )
      return;
    AnimatorBySerializeType = (idAnimator_AF *)idAnimStack::GetAnimatorBySerializeType(
                                                 this: this->animStack,
                                                 type_: STYPE_AF);
    if ( AnimatorBySerializeType != nullptr )
    {
      p_physicsObj = &AnimatorBySerializeType->physicsObj;
      v6 = idAnimator_AF::BodyForJoint(
             this: AnimatorBySerializeType,
             joint: (idIndex<short,enum invalidJointIndex_t> *)0xFFFFFFFF);
      clipModel = idPhysics_AF::GetBody(this: p_physicsObj, id: v6)->clipModel;
      y = clipModel->origin.y;
      z = clipModel->origin.z;
      x = clipModel->origin.x;
      v14 = y;
      v15 = z;
      v10 = (float *)v3->physicsObj.GetOrigin(this: &v3->physicsObj, a2: 0);
      v11 = (float)(v10[1] - v14);
      v12 = (float)(v10[2] - v15);
      v16.x = *v10 - x;
      v16.y = v11;
      v16.z = v12;
      idVec3::NormalizeFast(this: &v16);
      v17[0] = g_ragdollLootingImpulse.valueFloat * v16.x;
      v17[1] = g_ragdollLootingImpulse.valueFloat * v16.y;
      v17[2] = g_ragdollLootingImpulse.valueFloat * v16.z;
      p_physicsObj->ApplyImpulse(this: p_physicsObj, a2: v6, a3: (const idVec3 *)&x, a4: (const idVec3 *)v17);
      if ( !common->IsServer(this: common) )
        p_physicsObj->Activate(this: p_physicsObj);
    }
  }
  if ( v3 != nullptr )
    idPresentablePlayer::PlayLootSound(this: v3, hasLoot: this->lootBodyEventInfo.hasLoot);
}


// ========================================================================
// ?Interpolate@idPresentableAI@@UAAXHM@Z
// EA  : 0x82B6A838
// RVA : 0x00B6A838
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::Interpolate(idPresentableAI *this, int curTime, double fraction)
{
  int playerIndex; // r4

  idPresentableAnimatedEntity::Interpolate(this, curTime, fraction);
  if ( this->lootBodyEventInfo.lastHandledEventTime != this->lootBodyEventInfo.eventTime )
  {
    playerIndex = this->lootBodyEventInfo.playerIndex;
    this->predictedLootBody = false;
    if ( (unsigned __int8)idClientGame::PlayerIndexIsLocal(this: clientGame, playerNum: playerIndex) == 0 )
      idPresentableAI::InternalLootBody(this);
  }
  this->lootBodyEventInfo.lastHandledEventTime = this->lootBodyEventInfo.eventTime;
}


// ========================================================================
// ?ShouldSerializeRenderModelParms@idPresentableAI@@UBA_NXZ
// EA  : 0x82B6A8A8
// RVA : 0x00B6A8A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

BOOL __fastcall idPresentableAI::ShouldSerializeRenderModelParms(idPresentableAI *this)
{
  return presentable_ai_serialize_render_parms.valueInteger != 0;
}


// ========================================================================
// ?SetDefaults@idPresentableAI@@QAAXXZ
// EA  : 0x82B6A920
// RVA : 0x00B6A920
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::SetDefaults(idPresentableAI *this)
{
  this->painAnimator = nullptr;
  this->hasLoot = false;
  this->predictedLootBody = false;
  this->dead = false;
  this->bloodSplatterEventInfo.eventTime = 0;
  this->bloodSplatterEventInfo.lastHandledEventTime = 0;
  this->bloodSplatterEventInfo.playerIndex = 0;
  this->bloodSplatterEventInfo.goreInfo = nullptr;
  this->bloodSplatterEventInfo.impactDir = vec3_origin;
  this->bloodSplatterEventInfo.impactPoint = vec3_origin;
  this->painAnimationEventInfo.eventTime = 0;
  this->painAnimationEventInfo.lastHandledEventTime = 0;
  this->painAnimationEventInfo.playerIndex = 0;
  this->painAnimationEventInfo.projDir = vec3_origin;
  this->painAnimationEventInfo.declTwitchPain = nullptr;
  this->lootBodyEventInfo.eventTime = 0;
  this->lootBodyEventInfo.lastHandledEventTime = 0;
  this->lootBodyEventInfo.playerIndex = 0;
  this->lootBodyEventInfo.hasLoot = false;
  this->attachment.enabled = false;
  this->attachment.content = 0;
  this->attachment.fxDecl = nullptr;
  this->attachment.model = nullptr;
  idInfluenceTrailManager::Enable(
    this: &clientGame->influenceTrailManager,
    presentable: this,
    trail: &this->influence,
    sndFoliage: nullptr);
}


// ========================================================================
// ?SplatterBlood@idPresentableAI@@QAAXVidVec3@@0H@Z
// EA  : 0x82B6A9E8
// RVA : 0x00B6A9E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentableAI::SplatterBlood(
        idPresentableAI *this,
        idVec3 *impactPoint_,
        __int64 playerIndex,
        int a4,
        int a5)
{
  int v5; // r3
  int v6; // r31
  int ServerGameTime; // r3
  __int64 v9; // [sp+90h] [+20h]
  float v12; // [sp+A8h] [+38h]

  v9 = *(_QWORD *)&impactPoint_;
  v6 = v5;
  v12 = *((float *)&playerIndex + 1);
  if ( common->IsServer(this: common) )
  {
    *(_DWORD *)(v6 + 15600) = a5;
    ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
    *(_DWORD *)(v6 + 15592) = ServerGameTime;
    *(_DWORD *)(v6 + 15596) = ServerGameTime;
  }
  *(_QWORD *)(v6 + 15620) = playerIndex;
  *(float *)(v6 + 15628) = v12;
  *(_QWORD *)(v6 + 15608) = v9;
  *(float *)(v6 + 15616) = *(float *)&impactPoint_;
  idPresentableAI::InternalSplatterBlood(this: (idPresentableAI *)v6);
}


// ========================================================================
// ?PlayAdditivePain@idPresentableAI@@QAAXABVidVec3@@V?$idIndex@FW4invalidJointIndex_t@@@@H@Z
// EA  : 0x82B6AAA0
// RVA : 0x00B6AAA0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::PlayAdditivePain(
        idPresentableAI *this,
        const idVec3 *projDir,
        idIndex<short,enum invalidJointIndex_t> *joint,
        int playerIndex)
{
  __int16 v6; // r28
  int ServerGameTime; // r3

  v6 = (__int16)joint;
  if ( common->IsServer(this: common) )
  {
    this->painAnimationEventInfo.playerIndex = playerIndex;
    ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
    this->painAnimationEventInfo.eventTime = ServerGameTime;
    this->painAnimationEventInfo.lastHandledEventTime = ServerGameTime;
  }
  this->painAnimationEventInfo.projDir.x = projDir->x;
  this->painAnimationEventInfo.projDir.y = projDir->y;
  this->painAnimationEventInfo.projDir.z = projDir->z;
  this->painAnimationEventInfo.joint.value = v6;
  idPresentableAI::InternalPlayAdditivePain(this);
}


// ========================================================================
// ?LootBody@idPresentableAI@@QAAXH_N@Z
// EA  : 0x82B6AB28
// RVA : 0x00B6AB28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::LootBody(idPresentableAI *this, int playerIndex, bool hasLoot)
{
  int ServerGameTime; // r3

  if ( common->IsServer(this: common) )
  {
    this->lootBodyEventInfo.playerIndex = playerIndex;
    ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
    this->lootBodyEventInfo.eventTime = ServerGameTime;
    this->lootBodyEventInfo.lastHandledEventTime = ServerGameTime;
    this->lootBodyEventInfo.hasLoot = hasLoot;
  }
  else
  {
    this->lootBodyEventInfo.hasLoot = hasLoot;
    this->predictedLootBody = true;
  }
  idPresentableAI::InternalLootBody(this);
}


// ========================================================================
// ?ClientThink@idPresentableAI@@UAAXHM_N@Z
// EA  : 0x82B6ABB0
// RVA : 0x00B6ABB0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::ClientThink(idPresentableAI *this, int curTime, double fraction, bool predict)
{
  int GameMs; // r3
  idClipModel *clipModel; // r3
  float y; // r7
  idVec3 *v8; // r10
  float z; // r6
  float *p_z; // r11
  int v11; // ctr
  const idIndex<short,enum invalidJointIndex_t> *value; // r26
  idTreeAnimator *TreeAnimator; // r3
  idVec3 v14; // [sp+50h] [-90h] BYREF
  idQuat v15; // [sp+60h] [-80h] BYREF
  idMat3 v16[3]; // [sp+70h] [-70h] BYREF

  idPresentableActor::ClientThink(this, curTime, fraction, predict);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idInfluenceTrailManager::UpdatePosition(
    this: &clientGame->influenceTrailManager,
    trail: &this->influenceHandle,
    position: &this->origin,
    time: GameMs);
  if ( this->dead )
  {
    clipModel = this->clipModel;
    if ( clipModel != nullptr )
      idClipModel::SetContents(this: clipModel, newContents: 0);
  }
  if ( this->attachment.model != nullptr )
  {
    y = this->origin.y;
    v8 = &v16[0].mat[1];
    z = this->origin.z;
    p_z = &this->origin.z;
    v14.x = this->origin.x;
    v11 = 9;
    v14.y = y;
    v14.z = z;
    do
    {
      ++p_z;
      v8 = (idVec3 *)((char *)v8 + 4);
      v8->x = *p_z;
      --v11;
    }
    while ( v11 != 0 );
    v15.x = 0.0;
    v15.y = 90.0;
    v15.z = 0.0;
    idAngles::ToQuat(this: (idAngles *)v16, result: &v15);
    value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->attachment.jointId.value;
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
    if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceAttachmentTransform(
                            this: TreeAnimator,
                            jointIndex: value,
                            translationOffset: &vec3_origin,
                            rotationOffset: v16,
                            origin: &v14,
                            axis: (idMat3 *)&v16[0].mat[1].y) != 0 )
      idClipModel::SetLinkedPosition(this: this->attachment.model, newOrigin: &v14, newAxis: (idMat3 *)&v16[0].mat[1].y);
  }
}


// ========================================================================
// ?PredictHitScanHit@idPresentableAI@@UAAXPAVidPresentable@@MABVidVec3@@1PBVidDeclProjectile@@PAUtrace_t@@@Z
// EA  : 0x82B6ACE0
// RVA : 0x00B6ACE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::PredictHitScanHit(
        idPresentableAI *this,
        idPresentable *attacker,
        double damage,
        const idVec3 *hitPos,
        const idVec3 *projDir,
        const idVec3 *projDecl,
        trace_t *trace,
        int a8)
{
  int index; // r30
  float z; // r9
  __int64 v14; // r6
  int v15; // r11

  if ( a8 != 0 )
  {
    if ( attacker != nullptr )
      index = attacker->index;
    else
      index = -1;
    z = projDir->z;
    v14 = *(_QWORD *)&projDecl->x;
    HIDWORD(v14) = __ROL4__(LODWORD(z), 32);
    idPresentableAI::SplatterBlood(
      this: (idPresentableAI *)LODWORD(projDir->x),
      impactPoint_: (idVec3 *)LODWORD(projDir->y),
      playerIndex: v14,
      a4: __ROL4__(LODWORD(projDecl->z), 32),
      a5: index);
    if ( *(_DWORD *)(a8 + 52) == 4 )
      v15 = *(_DWORD *)(a8 + 104);
    else
      LOWORD(v15) = -1;
    idPresentableAI::PlayAdditivePain(
      this,
      projDir: projDecl,
      joint: (idIndex<short,enum invalidJointIndex_t> *)(__int16)v15,
      playerIndex: index);
  }
}


// ========================================================================
// ??0idPresentableAI@@QAA@PAVidAI2@@PAVidRenderModel@@PAVidAnimStack@@PAVidAnimator_Pain@@PAVidEntityInfluenceTrail@@HPBVidDeclFX@@_N@Z
// EA  : 0x82B6AFB8
// RVA : 0x00B6AFB8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

idPresentableAI *__fastcall idPresentableAI::idPresentableAI(
        idPresentableAI *this,
        idAI2 *ent,
        idRenderModel *renderModel_,
        idAnimStack *animStack_,
        idAnimator_Pain *animPain_,
        idEntityInfluenceTrail *inf,
        int entityNumber_,
        const idDeclFX *fxDecl_,
        bool useSphereModel_,
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
        int a27,
        bool a28)
{
  idInventoryCollection *v36; // r3
  _DWORD *p_trailFadeOutTime; // r10
  idAnimator_Pain **p_painAnimator; // r9
  int i; // ctr

  v36 = ent->GetInventory_2(this: ent);
  idPresentableActor::idPresentableActor(
    this,
    ent,
    renderModel_,
    animStack_,
    inv: v36,
    entityNum_: entityNumber_,
    fxDecl_,
    useSphereModel_: a28);
  this->__vftable = (idPresentableAI_vtbl *)&idPresentableAI::`vftable';
  this->painAnimationEventInfo.weaponPrefix.len = 0;
  this->painAnimationEventInfo.weaponPrefix.allocedAndFlag = 20;
  this->painAnimationEventInfo.weaponPrefix.data = this->painAnimationEventInfo.weaponPrefix.baseBuffer;
  this->painAnimationEventInfo.weaponPrefix.baseBuffer[0] = 0;
  this->painAnimationEventInfo.joint.value = -1;
  this->attachment.name.allocedAndFlag = 20;
  this->attachment.name.len = 0;
  this->attachment.name.data = this->attachment.name.baseBuffer;
  this->attachment.name.baseBuffer[0] = 0;
  this->attachment.jointId.value = -1;
  this->influence.innerRadius = 32.0;
  this->influence.outerRadius = 64.0;
  this->influence.angle = 0.0;
  this->influence.trailDist = 32.0;
  this->influence.trailFadeInTime = 0.25;
  this->influence.trailFadeOutTime = 2.0;
  idPresentableAI::SetDefaults(this);
  this->painAnimator = animPain_;
  p_trailFadeOutTime = (_DWORD *)&inf[-1].trailFadeOutTime;
  p_painAnimator = &this->painAnimator;
  for ( i = 6; i != 0; --i )
    *++p_painAnimator = (idAnimator_Pain *)*++p_trailFadeOutTime;
  return this;
}


// ========================================================================
// __unwind$489362_0
// EA  : 0x82B6B108
// RVA : 0x00B6B108
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void _unwind_489362_0()
{
  int v0; // r12

  idPresentableActor::~idPresentableActor(this: *(idPresentableActor **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$489363_0
// EA  : 0x82B6B130
// RVA : 0x00B6B130
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void _unwind_489363_0()
{
  int v0; // r12

  idSubtitles::idPart::~idPart(this: (idSubtitles::idPart *)(*(_DWORD *)(v0 - 176 + 196) + 15632));
}


// ========================================================================
// __unwind$489364
// EA  : 0x82B6B15C
// RVA : 0x00B6B15C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void _unwind_489364()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(*(_DWORD *)(v0 - 176 + 196) + 15696));
}


// ========================================================================
// ?Serialize@idPresentableAI@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B6B190
// RVA : 0x00B6B190
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __fastcall idPresentableAI::Serialize(idPresentableAI *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  bool hasLoot; // r28
  bool dead; // r28
  idBitMsg *v7; // r3
  idBitMsg *v8; // r3
  idBitMsg *v9; // r3
  unsigned int v10; // r10
  int v11; // r28
  idBitMsg *v12; // r3
  idBitMsg *v13; // r3
  idBitMsg *v14; // r3
  idBitMsg *v15; // r3
  bool v16; // r28
  idBitMsg *v17; // r3
  idBitMsg *v18; // r3
  idBitMsg *v19; // r3
  idBitMsg *v20; // r3
  idBitMsg *v21; // r3
  idBitMsg *v22; // r3
  idBitMsg *v23; // r3
  bool enabled; // r28
  idBitMsg *v25; // r3
  idBitMsg *v26; // r3
  idBitMsg *v27; // r3
  int value; // r11
  unsigned __int16 Bits; // r28
  idBitMsg *v30; // r3
  idIndex<short,enum invalidJointIndex_t> *v31; // r11
  idBitMsg *v32; // r3
  idClipModel *v33; // r3
  idClipModel *v34; // r3
  idClipModel *model; // r3
  int v36[16]; // [sp+50h] [-40h] BYREF

  idPresentableActor::Serialize(this, ser);
  msg = ser->msg;
  hasLoot = this->hasLoot;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->hasLoot, numBits: 1);
  else
    hasLoot = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->hasLoot = hasLoot;
  dead = this->dead;
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->dead, numBits: 1);
  else
    dead = (_cntlzw(idBitMsg::ReadBits(this: v7, numBits: 1) - 1) & 0x20) != 0;
  this->dead = dead;
  v8 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v8, value: this->bloodSplatterEventInfo.eventTime, numBits: 32);
  else
    this->bloodSplatterEventInfo.eventTime = idBitMsg::ReadBits(this: v8, numBits: 32);
  v9 = ser->msg;
  v10 = _cntlzw(6u);
  v11 = 32 - v10;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v9, value: this->bloodSplatterEventInfo.playerIndex, numBits: 32 - v10);
  else
    this->bloodSplatterEventInfo.playerIndex = idBitMsg::ReadBits(this: v9, numBits: 32 - v10);
  idSerializer::Serialize<idDeclGore>(this: ser, decl: &this->bloodSplatterEventInfo.goreInfo);
  idSerializer::Serialize(this: ser, value: &this->bloodSplatterEventInfo.impactPoint);
  idSerializer::Serialize(this: ser, value: &this->bloodSplatterEventInfo.impactDir);
  v12 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v12, value: this->painAnimationEventInfo.eventTime, numBits: 32);
  else
    this->painAnimationEventInfo.eventTime = idBitMsg::ReadBits(this: v12, numBits: 32);
  v13 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v13, value: this->painAnimationEventInfo.playerIndex, numBits: v11);
  else
    this->painAnimationEventInfo.playerIndex = idBitMsg::ReadBits(this: v13, numBits: v11);
  idSerializer::Serialize(this: ser, value: &this->painAnimationEventInfo.projDir);
  idSerializer::Serialize<idDeclTwitchPain>(this: ser, decl: &this->painAnimationEventInfo.declTwitchPain);
  v14 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v14, value: this->lootBodyEventInfo.eventTime, numBits: 32);
  else
    this->lootBodyEventInfo.eventTime = idBitMsg::ReadBits(this: v14, numBits: 32);
  v15 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v15, value: this->lootBodyEventInfo.playerIndex, numBits: v11);
  else
    this->lootBodyEventInfo.playerIndex = idBitMsg::ReadBits(this: v15, numBits: v11);
  v16 = this->lootBodyEventInfo.hasLoot;
  v17 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v17, value: this->lootBodyEventInfo.hasLoot, numBits: 1);
  else
    v16 = (_cntlzw(idBitMsg::ReadBits(this: v17, numBits: 1) - 1) & 0x20) != 0;
  this->lootBodyEventInfo.hasLoot = v16;
  v18 = ser->msg;
  if ( ser->writing )
  {
    v36[0] = SLODWORD(this->influence.angle);
    idBitMsg::WriteBits(this: v18, value: v36[0], numBits: 32);
  }
  else
  {
    LODWORD(this->influence.angle) = idBitMsg::ReadBits(this: v18, numBits: 32);
  }
  v19 = ser->msg;
  if ( ser->writing )
  {
    v36[0] = SLODWORD(this->influence.innerRadius);
    idBitMsg::WriteBits(this: v19, value: v36[0], numBits: 32);
  }
  else
  {
    LODWORD(this->influence.innerRadius) = idBitMsg::ReadBits(this: v19, numBits: 32);
  }
  v20 = ser->msg;
  if ( ser->writing )
  {
    v36[0] = SLODWORD(this->influence.outerRadius);
    idBitMsg::WriteBits(this: v20, value: v36[0], numBits: 32);
  }
  else
  {
    LODWORD(this->influence.outerRadius) = idBitMsg::ReadBits(this: v20, numBits: 32);
  }
  v21 = ser->msg;
  if ( ser->writing )
  {
    v36[0] = SLODWORD(this->influence.trailDist);
    idBitMsg::WriteBits(this: v21, value: v36[0], numBits: 32);
  }
  else
  {
    LODWORD(this->influence.trailDist) = idBitMsg::ReadBits(this: v21, numBits: 32);
  }
  v22 = ser->msg;
  if ( ser->writing )
  {
    v36[0] = SLODWORD(this->influence.trailFadeInTime);
    idBitMsg::WriteBits(this: v22, value: v36[0], numBits: 32);
  }
  else
  {
    LODWORD(this->influence.trailFadeInTime) = idBitMsg::ReadBits(this: v22, numBits: 32);
  }
  v23 = ser->msg;
  if ( ser->writing )
  {
    v36[0] = SLODWORD(this->influence.trailFadeOutTime);
    idBitMsg::WriteBits(this: v23, value: v36[0], numBits: 32);
  }
  else
  {
    LODWORD(this->influence.trailFadeOutTime) = idBitMsg::ReadBits(this: v23, numBits: 32);
  }
  if ( ser->writing )
  {
    v36[0] = idAnimStack::GetAnimatorIndex(this: this->animStack, animator: this->painAnimator);
    idSerializer::SerializePacked(this: ser, original: v36);
  }
  else
  {
    idSerializer::SerializePacked(this: ser, original: v36);
    this->painAnimator = (idAnimator_Pain *)idAnimStack::GetAnimatorByIndex(this: this->animStack, index: v36[0]);
  }
  if ( ser->writing )
  {
    HIWORD(v36[0]) = this->painAnimationEventInfo.joint.value;
    idSerializer::Serialize(this: ser, value: (__int16 *)v36);
  }
  else
  {
    idSerializer::Serialize(this: ser, value: (__int16 *)v36);
    this->painAnimationEventInfo.joint.value = HIWORD(v36[0]);
  }
  enabled = this->attachment.enabled;
  v25 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v25, value: this->attachment.enabled, numBits: 1);
  else
    enabled = (_cntlzw(idBitMsg::ReadBits(this: v25, numBits: 1) - 1) & 0x20) != 0;
  this->attachment.enabled = enabled;
  v26 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteString(this: v26, s: this->attachment.name.data, maxLength: -1, make7Bit: true);
  else
    idBitMsg::ReadString(this: v26, str: &this->attachment.name);
  v27 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v27, value: this->attachment.content, numBits: 32);
  else
    this->attachment.content = idBitMsg::ReadBits(this: v27, numBits: 32);
  value = this->attachment.jointId.value;
  if ( value == NULL_JOINT_INDEX.value )
    LOWORD(value) = -1;
  Bits = value;
  v30 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v30, (unsigned __int16)value, numBits: 16);
  else
    Bits = idBitMsg::ReadBits(this: v30, numBits: 16);
  if ( Bits == 0xFFFF )
  {
    v31 = &NULL_JOINT_INDEX;
  }
  else
  {
    HIWORD(v36[0]) = Bits;
    v31 = (idIndex<short,enum invalidJointIndex_t> *)v36;
  }
  this->attachment.jointId = (idIndex<short,enum invalidJointIndex_t>)v31->value;
  v32 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteString(this: v32, s: this->painAnimationEventInfo.weaponPrefix.data, maxLength: -1, make7Bit: true);
  else
    idBitMsg::ReadString(this: v32, str: &this->painAnimationEventInfo.weaponPrefix);
  if ( !ser->writing )
  {
    if ( this->attachment.enabled
      && idStr::Cmp(s1: this->attachment.name.data, s2: &byte_8200D768) != 0
      && !this->hidden )
    {
      if ( this->attachment.model == nullptr )
      {
        v33 = (idClipModel *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xD8u,
                               tag: TAG_CLIPMODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        v36[0] = (int)v33;
        if ( v33 != nullptr )
          v34 = idClipModel::idClipModel(
                  this: v33,
                  clip: &clientGame->clip,
                  name: this->attachment.name.data,
                  overrideClipMaterial: nullptr);
        else
          v34 = nullptr;
        this->attachment.model = v34;
        idClipModel::Link(
          this: v34,
          newEntityNumber: this->entityNumber,
          newPhysicsId: -1,
          newBodyId: 1,
          newOrigin: &vec3_origin,
          newAxis: &mat3_identity);
        this->attachment.model->enabled = true;
      }
      idClipModel::SetContents(this: this->attachment.model, newContents: this->attachment.content);
    }
    else if ( !this->attachment.enabled )
    {
      model = this->attachment.model;
      if ( model != nullptr )
      {
        idClipModel::Delete(this: model);
        this->attachment.model = nullptr;
      }
    }
  }
}


// ========================================================================
// __unwind$489494
// EA  : 0x82B6B7A4
// RVA : 0x00B6B7A4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void _unwind_489494()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// `dynamic initializer for 'presentable_ai_serialize_render_parms''
// EA  : 0x8336D9A0
// RVA : 0x0136D9A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentable_ai_serialize_render_parms__()
{
  idCVar::idCVar(
    this: &presentable_ai_serialize_render_parms,
    name: "presentable_ai_serialize_render_parms",
    value: "0",
    flags: 1,
    description: "Serialize renderparm",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentable_ai_serialize_render_parms__);
}

