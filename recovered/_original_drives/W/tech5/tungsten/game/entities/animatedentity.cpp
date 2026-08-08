
// ========================================================================
// ?Collide@idAnimatedEntityPhysicsCallbacks@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82BF76F0
// RVA : 0x00BF76F0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

collide_t __fastcall idAnimatedEntityPhysicsCallbacks::Collide(
        idAnimatedEntityPhysicsCallbacks *this,
        int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  idAnimator_AF *af; // r3

  af = this->af;
  if ( af != nullptr )
    return idAnimator_AF::Collide(this: af, physId, collision, velocity);
  else
    return COLLIDE_CONTINUE_SIMULATION;
}


// ========================================================================
// ?ApplyForce@idAnimatedEntityPhysicsCallbacks@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82BF7708
// RVA : 0x00BF7708
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntityPhysicsCallbacks::ApplyForce(
        idAnimatedEntityPhysicsCallbacks *this,
        int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *force)
{
  idAnimator_AF *af; // r3

  af = this->af;
  if ( af != nullptr )
    idAnimator_AF::ApplyForce(this: af, physId, bodyId, point, force);
}


// ========================================================================
// ?ApplyWaterSplashEffects@idAnimatedEntityPhysicsCallbacks@@UAAXHHW4surfTypes_t@@W4splashState_t@idPhysicsCallbacks@@@Z
// EA  : 0x82BF7720
// RVA : 0x00BF7720
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntityPhysicsCallbacks::ApplyWaterSplashEffects(
        idAnimatedEntityPhysicsCallbacks *this,
        const int physId,
        const int bodyId,
        surfTypes_t surfOverride,
        idPhysicsCallbacks::splashState_t splashState)
{
  idAnimator_AF *af; // r11

  af = this->af;
  if ( af != nullptr )
    ((void (*)(void))af->ApplyWaterSplashEffects)();
}


// ========================================================================
// ?UpdateAttachments@idAnimatedEntity@@UAAXXZ
// EA  : 0x82BF7748
// RVA : 0x00BF7748
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::UpdateAttachments(idAnimatedEntity *this)
{
  idAttachmentCollection *v2; // r3

  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  if ( this->GetAttachments_2(this) != nullptr )
  {
    v2 = this->GetAttachments_2(this);
    idAttachmentCollection::UpdateRenderModelAttachments(this: v2);
  }
}


// ========================================================================
// ?FreePresentable@idAnimatedEntity@@QAAXXZ
// EA  : 0x82BF77A8
// RVA : 0x00BF77A8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::FreePresentable(idAnimatedEntity *this)
{
  idAnimStack *v2; // r3

  if ( this->GetAnimStack_2(this) != nullptr )
  {
    v2 = this->GetAnimStack_2(this);
    idAnimator_Base::Shutdown(this: &this->proxyAnimator, stack: v2);
  }
  idEntity::FreePresentable(this);
}


// ========================================================================
// ?PreBind@idAnimatedEntity@@UAAXXZ
// EA  : 0x82BF7810
// RVA : 0x00BF7810
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::PreBind(idAnimatedEntity *this)
{
  idAnimator_AF *v1; // r3

  v1 = this->GetAF_2(this);
  if ( v1 != nullptr )
    idAnimator_AF::AddBindConstraints(this: v1);
}


// ========================================================================
// ?PreUnbind@idAnimatedEntity@@UAAXXZ
// EA  : 0x82BF7848
// RVA : 0x00BF7848
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::PreUnbind(idAnimatedEntity *this)
{
  idAnimator_AF *v1; // r3

  v1 = this->GetAF_2(this);
  if ( v1 != nullptr )
    idAnimator_AF::RemoveBindConstraints(this: v1);
}


// ========================================================================
// ??0idAnimatedEntityInterface@@QAA@PAVidGame@@PAVidAnimatedEntity@@@Z
// EA  : 0x82BF7880
// RVA : 0x00BF7880
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntityInterface *__fastcall idAnimatedEntityInterface::idAnimatedEntityInterface(
        idAnimatedEntityInterface *this,
        idGame *game,
        idAnimatedEntity *ent)
{
  idEntityInterfaceLocal::idEntityInterfaceLocal(this, game, ent);
  this->__vftable = (idAnimatedEntityInterface_vtbl *)&idAnimatedEntityInterface::`vftable';
  return this;
}


// ========================================================================
// ?GetAnimStack@idAnimatedEntityInterface@@UAAPAVidAnimStack@@XZ
// EA  : 0x82BF78C0
// RVA : 0x00BF78C0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimStack *__fastcall idAnimatedEntityInterface::GetAnimStack(idAnimatedEntityInterface *this)
{
  idAnimatedEntity *v1; // r3
  idAnimatedEntity *v2; // r3

  v1 = (idAnimatedEntity *)this->GetEntity(this);
  v2 = idAnimatedEntity::CastTo(c: v1);
  if ( v2 != nullptr )
    return v2->GetAnimStack_2(this: v2);
  else
    return nullptr;
}


// ========================================================================
// ?GetName@idAnimatedEntityPhysicsCallbacks@@UAAPBDXZ
// EA  : 0x82BF7970
// RVA : 0x00BF7970
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

const char *__fastcall idAnimatedEntityPhysicsCallbacks::GetName(idAnimatedEntityPhysicsCallbacks *this)
{
  if ( this->af != nullptr )
    return "<unknown>";
  else
    return "NULL";
}


// ========================================================================
// ?ApplyImpulse@idAnimatedEntityPhysicsCallbacks@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82BF7998
// RVA : 0x00BF7998
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntityPhysicsCallbacks::ApplyImpulse(
        idAnimatedEntityPhysicsCallbacks *this,
        int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  int GameMs; // r3

  if ( this->af != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAnimator_AF::ApplyImpulse(this: this->af, curTime: GameMs, physId, bodyId, point, impulse);
  }
}


// ========================================================================
// ?ActivatePhysics@idAnimatedEntityPhysicsCallbacks@@UAAXH@Z
// EA  : 0x82BF7A00
// RVA : 0x00BF7A00
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntityPhysicsCallbacks::ActivatePhysics(idAnimatedEntityPhysicsCallbacks *this, int physId)
{
  idAnimator_AF *af; // r11

  af = this->af;
  if ( af != nullptr )
    ((void (__fastcall *)(idPhysics_AF *, int))af->physicsObj.Activate)(a1: &af->physicsObj, a2: physId);
}


// ========================================================================
// ?DeactivatePhysics@idAnimatedEntityPhysicsCallbacks@@UAAXH@Z
// EA  : 0x82BF7A28
// RVA : 0x00BF7A28
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntityPhysicsCallbacks::DeactivatePhysics(idAnimatedEntityPhysicsCallbacks *this, int physId)
{
  idAnimator_AF *af; // r11

  af = this->af;
  if ( af != nullptr )
    ((void (__fastcall *)(idPhysics_AF *, int))af->physicsObj.PutToRest)(a1: &af->physicsObj, a2: physId);
}


// ========================================================================
// ?KillFX@idAnimatedEntity@@QAAXXZ
// EA  : 0x82BF7A50
// RVA : 0x00BF7A50
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::KillFX(idAnimatedEntity *this)
{
  idPresentable *presentable; // r11

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idFXManager::Shutdown(this: &presentable->fxManager);
  idImpactManager::Shutdown(this: &this->impactManager);
}


// ========================================================================
// ?JobSync@idAnimatedEntity@@UAAXXZ
// EA  : 0x82BF7AA0
// RVA : 0x00BF7AA0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::JobSync(idAnimatedEntity *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r30
  int GameMs; // r3
  idAttachmentCollection *v6; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idTreeAnimator::SyncJoints(this: v4, time: GameMs);
  }
  if ( this->GetAttachments_2(this) != nullptr )
  {
    v6 = this->GetAttachments_2(this);
    idAttachmentCollection::JobSync(this: v6);
  }
}


// ========================================================================
// ?SetModel@idAnimatedEntity@@UAAXPAVidRenderModel@@@Z
// EA  : 0x82BF7B58
// RVA : 0x00BF7B58
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::SetModel(idAnimatedEntity *this, idRenderModel *model)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r30

  idEntity::BecomeInactive(this, flags: 4);
  idEntity::SetModel(this, model);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v6 != nullptr && v6->decl != nullptr )
    idAnimStack::Init(this: &this->animStack, treeAnimator: v6);
  idEntity::UpdateVisuals(this);
}


// ========================================================================
// ?AllocPresentable@idAnimatedEntity@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82BF7C00
// RVA : 0x00BF7C00
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idPresentableAnimatedEntity *__fastcall idAnimatedEntity::AllocPresentable(
        idAnimatedEntity *this,
        idTreeAnimator *renderModel_)
{
  bool v4; // r27
  _DWORD *v5; // r3
  int v6; // r11
  idPresentableAnimatedEntity *v7; // r28
  int entityNumber; // r26
  const idDeclFX *v9; // r25
  idAnimStack *v10; // r3

  v4 = false;
  v5 = _RTDynamicCast(
         inptr: renderModel_,
         VfDelta: 0,
         SrcType: &idRenderModel `RTTI Type Descriptor',
         TargetType: &idTreeAnimator `RTTI Type Descriptor',
         isReference: 0);
  if ( v5 != nullptr )
  {
    v6 = v5[508];
    if ( v6 != 0 && v6 != -144 )
      v4 = idJointGroupCollection::NumJointGroupsForType(this: (idJointGroupCollection *)(v6 + 144), type: 8) != 0;
  }
  v7 = (idPresentableAnimatedEntity *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x4E0u,
                                        tag: TAG_PRESENTABLE,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  if ( v7 == nullptr )
    return nullptr;
  entityNumber = this->entityNumber;
  v9 = this->GetFXDecl(this);
  v10 = this->GetAnimStack_2(this);
  return idPresentableAnimatedEntity::idPresentableAnimatedEntity(
           this: v7,
           ent: this,
           renderModel_,
           animStack_: v10,
           entityNumber_: entityNumber,
           fxDecl_: v9,
           useSphereModel_: v4);
}


// ========================================================================
// __unwind$490399_0
// EA  : 0x82BF7D04
// RVA : 0x00BF7D04
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_490399_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?GetTagPosition@idAnimatedEntity@@QBA_NPBD0AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BF7D30
// RVA : 0x00BF7D30
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

int __fastcall idAnimatedEntity::GetTagPosition(
        idAnimatedEntity *this,
        const char *propName,
        const char *tagName,
        idVec3 *origin,
        idMat3 *axis)
{
  idPresentable *presentable; // r3
  idPhysics *Physics; // r3
  float *v12; // r3
  double v13; // fp8
  double v14; // fp6
  idPhysics *v15; // r3
  float *v16; // r3
  idPresentableAnimatedEntity *v18; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v18 = presentable->GetAnimatedEntityInterface(this: presentable);
    return idPresentableAnimatedEntity::GetPresentableTagPosition(this: v18, propName, tagName, origin, axis);
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    v12 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
    v13 = (float)(v12[4] + v12[1]);
    v14 = (float)(v12[5] + v12[2]);
    origin->x = (float)(v12[3] + *v12) * (float)0.5;
    origin->y = (float)v13 * (float)0.5;
    origin->z = (float)v14 * (float)0.5;
    v15 = idEntity::GetPhysics(this);
    v16 = (float *)v15->GetAxis(this: v15, a2: 0);
    axis->mat[0].x = *v16;
    axis->mat[0].y = v16[1];
    axis->mat[0].z = v16[2];
    axis->mat[1].x = v16[3];
    axis->mat[1].y = v16[4];
    axis->mat[1].z = v16[5];
    axis->mat[2].x = v16[6];
    axis->mat[2].y = v16[7];
    axis->mat[2].z = v16[8];
    return 0;
  }
}


// ========================================================================
// ?GetTagPosition@idAnimatedEntity@@QBA_NHHAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BF7E60
// RVA : 0x00BF7E60
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

int __fastcall idAnimatedEntity::GetTagPosition(
        idAnimatedEntity *this,
        int propIndex,
        int tagIndex,
        idVec3 *origin,
        idMat3 *axis)
{
  idPresentable *presentable; // r3
  idPhysics *Physics; // r3
  float *v12; // r3
  double v13; // fp8
  double v14; // fp6
  idPhysics *v15; // r3
  float *v16; // r3
  idPresentableAnimatedEntity *v18; // r3

  if ( propIndex == -1 || tagIndex == -1 )
    return 0;
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    v12 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
    v13 = (float)(v12[4] + v12[1]);
    v14 = (float)(v12[5] + v12[2]);
    origin->x = (float)(v12[3] + *v12) * (float)0.5;
    origin->y = (float)v13 * (float)0.5;
    origin->z = (float)v14 * (float)0.5;
    v15 = idEntity::GetPhysics(this);
    v16 = (float *)v15->GetAxis(this: v15, a2: 0);
    axis->mat[0].x = *v16;
    axis->mat[0].y = v16[1];
    axis->mat[0].z = v16[2];
    axis->mat[1].x = v16[3];
    axis->mat[1].y = v16[4];
    axis->mat[1].z = v16[5];
    axis->mat[2].x = v16[6];
    axis->mat[2].y = v16[7];
    axis->mat[2].z = v16[8];
    return 0;
  }
  v18 = presentable->GetAnimatedEntityInterface(this: presentable);
  return idPresentableAnimatedEntity::GetPresentableTagPosition(this: v18, propIndex, tagIndex, origin, axis);
}


// ========================================================================
// ?UpdateImpacts@idAnimatedEntity@@QAAXXZ
// EA  : 0x82BF7FA0
// RVA : 0x00BF7FA0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::UpdateImpacts(idAnimatedEntity *this)
{
  idPhysics *Physics; // r30
  idPhysics *v3; // r29
  signed int GameMs; // r28
  idMat3 *v5; // r30
  const idVec3 *v6; // r3

  Physics = idEntity::GetPhysics(this);
  v3 = idEntity::GetPhysics(this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = (idMat3 *)Physics->GetAxis(this: Physics, a2: 0);
  v6 = v3->GetOrigin(this: v3, a2: 0);
  idImpactManager::Update(
    this: &this->impactManager,
    parentOrigin: v6,
    parentAxis: v5,
    localTime: GameMs,
    serverTime: 0);
}


// ========================================================================
// ?ApplyImpulse@idAnimatedEntity@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82BF8038
// RVA : 0x00BF8038
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::ApplyImpulse(
        idAnimatedEntity *this,
        int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  idAnimator_AF *v10; // r3
  idAnimator_AF *v11; // r31
  int GameMs; // r3
  char v13; // r11

  v10 = this->GetAF_2(this);
  v11 = v10;
  if ( v10 == nullptr )
    goto LABEL_8;
  if ( v10->isLoaded )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAnimator_AF::ApplyImpulse(this: v11, curTime: GameMs, physId, bodyId, point, impulse);
  }
  if ( v11->isActive || (v13 = 0, v11->isClientAuthoritativeActive) )
    v13 = 1;
  if ( v13 == 0 )
LABEL_8:
    idEntity::ApplyImpulse(this, physId, bodyId, point, impulse);
}


// ========================================================================
// ?ApplyForce@idAnimatedEntity@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82BF8100
// RVA : 0x00BF8100
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::ApplyForce(
        idAnimatedEntity *this,
        int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *force)
{
  idAnimator_AF *v10; // r3
  idAnimator_AF *v11; // r31
  char v12; // r11

  v10 = this->GetAF_2(this);
  v11 = v10;
  if ( v10 == nullptr )
    goto LABEL_8;
  if ( v10->isLoaded )
    idAnimator_AF::ApplyForce(this: v10, physId, bodyId, point, force);
  if ( v11->isActive || (v12 = 0, v11->isClientAuthoritativeActive) )
    v12 = 1;
  if ( v12 == 0 )
LABEL_8:
    idEntity::ApplyForce(this, physId, bodyId, point, force);
}


// ========================================================================
// ?GetModelTransform@idAnimatedEntity@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BF81A8
// RVA : 0x00BF81A8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::GetModelTransform(idAnimatedEntity *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  idAnimator_AF *v6; // r3
  char v7; // r11
  idPhysics *Physics; // r3
  float *v9; // r3
  idPhysics *v10; // r3
  float *v11; // r3

  v6 = (idAnimator_AF *)this->GetAF(this);
  if ( v6 == nullptr )
    goto LABEL_7;
  if ( v6->isActive || (v7 = 0, v6->isClientAuthoritativeActive) )
    v7 = 1;
  if ( v7 != 0 )
  {
    idAnimator_AF::GetModelTransform(this: v6, modelOrigin, modelAxis);
  }
  else
  {
LABEL_7:
    Physics = idEntity::GetPhysics(this);
    v9 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    modelAxis->mat[0].x = *v9;
    modelAxis->mat[0].y = v9[1];
    modelAxis->mat[0].z = v9[2];
    modelAxis->mat[1].x = v9[3];
    modelAxis->mat[1].y = v9[4];
    modelAxis->mat[1].z = v9[5];
    modelAxis->mat[2].x = v9[6];
    modelAxis->mat[2].y = v9[7];
    modelAxis->mat[2].z = v9[8];
    v10 = idEntity::GetPhysics(this);
    v11 = (float *)v10->GetOrigin(this: v10, a2: 0);
    modelOrigin->x = *v11;
    modelOrigin->y = v11[1];
    modelOrigin->z = v11[2];
  }
}


// ========================================================================
// ?GetJointLocalTransform@idAnimatedEntity@@QBA_NPBDAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BF82C0
// RVA : 0x00BF82C0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

int __fastcall idAnimatedEntity::GetJointLocalTransform(
        idAnimatedEntity *this,
        const char *jointName,
        idVec3 *offset,
        idMat3 *axis)
{
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r4
  int result; // r3
  idAnimatedEntity *v10; // r3
  const idIndex<short,enum invalidJointIndex_t> *v11; // r31
  idTreeAnimator *v12; // r3
  bool v13; // zf
  unsigned __int16 v14; // [sp+50h] [-30h] BYREF

  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v14, result: TreeAnimatorFromPresentable, jointName);
    v10 = this;
    v11 = (const idIndex<short,enum invalidJointIndex_t> *)v14;
    v12 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v10);
    if ( v12 == nullptr )
      return 1;
    v13 = (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(
                             this: v12,
                             pose: DRIVER_MODEL,
                             jointIndex: v11,
                             origin: offset,
                             axis) == 0;
    result = 0;
    if ( !v13 )
      return 1;
  }
  else
  {
    idLib::Warning(
      fmt: "%s - entity <%s> has no tree animator",
      "idAnimatedEntity::GetJointLocalTransform",
      this->name.data);
    return 0;
  }
  return result;
}


// ========================================================================
// ?GetWorldSpaceJointTransform@idAnimatedEntity@@QBA_NV?$idIndex@FW4invalidJointIndex_t@@@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BF8360
// RVA : 0x00BF8360
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

int __fastcall idAnimatedEntity::GetWorldSpaceJointTransform(
        idAnimatedEntity *this,
        idIndex<short,enum invalidJointIndex_t> *jointIndex,
        idVec3 *offset,
        idMat3 *axis)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  char ModelSpaceJointTransform; // r3
  char v10; // r11

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable == nullptr
    || (ModelSpaceJointTransform = idTreeAnimator::GetModelSpaceJointTransform(
                                     this: TreeAnimatorFromPresentable,
                                     pose: DRIVER_MODEL,
                                     jointIndex,
                                     origin: offset,
                                     axis),
        v10 = 0,
        ModelSpaceJointTransform != 0) )
  {
    v10 = 1;
  }
  if ( v10 == 0 )
    return 0;
  idEntity::ConvertLocalToWorldTransform(this, offset, axis);
  return 1;
}


// ========================================================================
// ?CalcDamageImpulse@idAnimatedEntity@@UBA_NPBVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PBUtrace_t@@AAV4@4@Z
// EA  : 0x82BF83E8
// RVA : 0x00BF83E8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

int __fastcall idAnimatedEntity::CalcDamageImpulse(
        idAnimatedEntity *this,
        idEntity *inflictor,
        const idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        const trace_t *trace,
        idVec3 *impulsePoint,
        idVec3 *impulse,
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
        int a28,
        idVec3 *a29)
{
  idPhysics *Physics; // r3
  double x; // fp12
  idPhysics *v38; // r3
  float *v39; // r3
  idPhysics *v40; // r3
  double v41; // fp31
  idPhysics *v42; // r3
  float *v43; // r3
  double v44; // fp13
  double y; // fp12
  double v46; // fp5
  __int64 v47; // r10
  __int64 v48; // r8
  const idAnimator_AF *v49; // r3
  char v50; // r11
  double v51; // fp9
  double v52; // fp8
  double fraction; // fp0
  double v54; // fp13
  double v55; // fp7
  __int64 v56; // [sp+50h] [-60h] BYREF

  Physics = idEntity::GetPhysics(this);
  *impulse = *Physics->GetOrigin(this: Physics, a2: 0);
  *a29 = vec3_origin;
  if ( damageDef == nullptr )
    return 0;
  if ( impulsePoint != nullptr )
  {
    impulse->x = impulsePoint->y;
    impulse->y = impulsePoint->z;
    x = impulsePoint[1].x;
  }
  else
  {
    if ( inflictor == nullptr )
      goto LABEL_10;
    v38 = idEntity::GetPhysics(this: inflictor);
    v39 = (float *)v38->GetOrigin(this: v38, a2: 0);
    impulse->x = *v39;
    impulse->y = v39[1];
    x = v39[2];
  }
  impulse->z = x;
  if ( inflictor != nullptr && (unsigned __int8)idTrigger::IsTypeOf(c: inflictor) == 0 )
  {
    v40 = idEntity::GetPhysics(this: inflictor);
    v41 = ((double (__fastcall *)(idPhysics *, int))v40->GetMass)(a1: v40, a2: -1);
    v42 = idEntity::GetPhysics(this: inflictor);
    v43 = (float *)v42->GetLinearVelocity(this: (idPhysics *)&v56, result: (idVec3 *)v42, a3: 0);
    v44 = trace->endpos.x;
    y = trace->endpos.y;
    v46 = __fsqrts((float)((float)(v43[2] * v43[2]) + (float)((float)(*v43 * *v43) + (float)(v43[1] * v43[1]))));
    a29->x = trace->fraction * (float)((float)v46 * (float)v41);
    a29->y = (float)v44 * (float)((float)v46 * (float)v41);
    a29->z = (float)y * (float)((float)v46 * (float)v41);
    return 1;
  }
LABEL_10:
  v49 = this->GetAF(this);
  if ( v49 == nullptr )
    goto LABEL_16;
  if ( v49->isActive || (v50 = 0, v49->isClientAuthoritativeActive) )
    v50 = 1;
  if ( v50 != 0 )
  {
    v51 = (float)(trace->endpos.x * damageDef->ragdollImpulseMag);
    v52 = (float)(trace->endpos.y * damageDef->ragdollImpulseMag);
    a29->x = trace->fraction * damageDef->ragdollImpulseMag;
    a29->y = v51;
    a29->z = v52;
    return 1;
  }
  else
  {
LABEL_16:
    fraction = trace->fraction;
    a29->x = trace->fraction;
    v54 = trace->endpos.x;
    a29->y = trace->endpos.x;
    v55 = trace->endpos.y;
    a29->z = trace->endpos.y;
    LODWORD(v47) = damageDef->knockBack;
    v56 = v47;
    a29->z = (float)v55 * (float)v47;
    a29->x = (float)fraction * (float)v47;
    a29->y = (float)v54 * (float)v47;
    LODWORD(v48) = damageDef->knockUp;
    a29->z = (float)v48 + (float)((float)v55 * (float)v47);
    return 1;
  }
}


// ========================================================================
// ?PauseAnimation@idAnimatedEntity@@QAAXXZ
// EA  : 0x82BF8698
// RVA : 0x00BF8698
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::PauseAnimation(idAnimatedEntity *this)
{
  idTypesafeNumber<int,enum gameTimeUnique_t> v2; // [sp+50h] [-20h] BYREF

  v2.value = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idAnimStack::Pause(this: &this->animStack, curTime: &v2);
}


// ========================================================================
// ?IsAnimating@idAnimatedEntity@@UBA_NXZ
// EA  : 0x82BF86F0
// RVA : 0x00BF86F0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

int __fastcall idAnimatedEntity::IsAnimating(idAnimatedEntity *this)
{
  unsigned __int8 v2; // r11

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) == nullptr )
    return 0;
  v2 = 1;
  if ( (this->thinkFlags & 4) == 0 )
    return 0;
  return v2;
}


// ========================================================================
// ?Event_GetJointHandle@idAnimatedEntity@@AAA?AVeventInt@@PBD@Z
// EA  : 0x82BF8740
// RVA : 0x00BF8740
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::Event_GetJointHandle(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        const char *jointname)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idIndex<short,enum invalidJointIndex_t> *v8; // r29
  idTreeAnimator *JointIndex; // r3
  char v11; // [sp+50h] [-30h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v8 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    JointIndex = idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v11, result: v8, jointName: jointname);
    eventInt::eventInt((eventInt *)this, i: SHIWORD(JointIndex->__vftable));
  }
  else
  {
    eventInt::eventInt((eventInt *)this, i: -1);
  }
  return this;
}


// ========================================================================
// ?Event_SetJointPos@idAnimatedEntity@@AAA?AVeventVoid@@V?$idIndex@FW4invalidJointIndex_t@@@@W4jointModTransform_t@@ABVidVec3@@@Z
// EA  : 0x82BF87D8
// RVA : 0x00BF87D8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::Event_SetJointPos(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        idIndex<short,enum invalidJointIndex_t> *jointnum,
        jointModTransform_t transform_type,
        const idVec3 *pos)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v12; // r30

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v12 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v12 != nullptr )
  {
    idTreeAnimator::SetJointPos(this: v12, pose: (animationPose_t)0, jointIndex: jointnum, type: transform_type, pos);
    idEntity::BecomeActive(this: result, flags: 4);
  }
  return this;
}


// ========================================================================
// ?Event_SetJointAngle@idAnimatedEntity@@AAA?AVeventVoid@@V?$idIndex@FW4invalidJointIndex_t@@@@W4jointModTransform_t@@ABVidAngles@@@Z
// EA  : 0x82BF8860
// RVA : 0x00BF8860
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::Event_SetJointAngle(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        idIndex<short,enum invalidJointIndex_t> *jointnum,
        jointModTransform_t transform_type,
        idMat3 *angles)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v12; // r30
  float *v13; // r3
  idMat3 v15; // [sp+50h] [-90h] BYREF
  idAngles v16[8]; // [sp+80h] [-60h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v12 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v12 != nullptr )
  {
    v13 = (float *)idAngles::ToMat3(this: v16, result: angles);
    v15.mat[0].x = *v13;
    v15.mat[0].y = v13[1];
    v15.mat[0].z = v13[2];
    v15.mat[1].x = v13[3];
    v15.mat[1].y = v13[4];
    v15.mat[1].z = v13[5];
    v15.mat[2].x = v13[6];
    v15.mat[2].y = v13[7];
    v15.mat[2].z = v13[8];
    idTreeAnimator::SetJointAxis(
      this: v12,
      pose: (animationPose_t)0,
      jointIndex: jointnum,
      type: transform_type,
      axis: &v15);
    idEntity::BecomeActive(this: result, flags: 4);
  }
  return this;
}


// ========================================================================
// ?Event_GetJointPos@idAnimatedEntity@@AAA?AVeventVector@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82BF8940
// RVA : 0x00BF8940
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::Event_GetJointPos(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        idIndex<short,enum invalidJointIndex_t> *jointnum)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idVec3 v8; // [sp+50h] [-60h] BYREF
  idMat3 v9[2]; // [sp+60h] [-50h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceJointTransform(
                          this: TreeAnimatorFromPresentable,
                          pose: DRIVER_MODEL,
                          jointIndex: jointnum,
                          origin: &v8,
                          axis: v9) == 0 )
    idLib::Warning(fmt: "Joint # %d out of range on entity '%s'", (__int16)jointnum, result->name.data);
  eventVector::eventVector((eventVector *)this, v: &v8);
  return this;
}


// ========================================================================
// ?Event_GetJointAngle@idAnimatedEntity@@AAA?AVeventVector@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82BF89B0
// RVA : 0x00BF89B0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::Event_GetJointAngle(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        idIndex<short,enum invalidJointIndex_t> *jointnum)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idMat3 v8; // [sp+50h] [-80h] BYREF
  idMat3 v9[2]; // [sp+80h] [-50h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceJointTransform(
                          this: TreeAnimatorFromPresentable,
                          pose: DRIVER_MODEL,
                          jointIndex: jointnum,
                          origin: (idVec3 *)&v8.mat[2].z,
                          axis: v9) == 0 )
    idLib::Warning(fmt: "Joint # %d out of range on entity '%s'", (__int16)jointnum, result->name.data);
  idMat3::ToAngles(this: &v8, result: (idAngles *)v9);
  v8.mat[1].y = v8.mat[0].x;
  v8.mat[1].z = v8.mat[0].y;
  v8.mat[2].x = v8.mat[0].z;
  eventVector::eventVector((eventVector *)this, v: (const idVec3 *)&v8.mat[1].y);
  return this;
}


// ========================================================================
// ?StopFX@idAnimatedEntity@@QAAXW4fxCondition_t@@@Z
// EA  : 0x82BF8A40
// RVA : 0x00BF8A40
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::StopFX(idAnimatedEntity *this, int condition)
{
  idPresentable *presentable; // r11

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::StopFX(this: presentable, condition, extraCondition: FX_EXTRA_COND_NONE);
}


// ========================================================================
// ?AnimEvent_DeclParticle@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclParticle@@PBD@Z
// EA  : 0x82BF8A98
// RVA : 0x00BF8A98
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_DeclParticle(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        const idDeclParticle *particleDecl,
        const char *jointName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idIndex<short,enum invalidJointIndex_t> *v11; // r30
  idPhysics *Physics; // r3
  int v13; // r3
  float v14; // r7
  float v15; // r6
  idPhysics *v16; // r3
  int v17; // r3
  idVec3 *v18; // r10
  float *v19; // r11
  int i; // ctr
  __int64 v21; // r9
  unsigned int v22; // r5
  double v23; // fp31
  int GameMsPerFrame; // r29
  int GameMs; // r31
  idRenderModelEffects *MergeBranch; // r3
  int v28; // [sp+8h] [-D8h]
  int v29; // [sp+Ch] [-D4h]
  int v30; // [sp+10h] [-D0h]
  int v31; // [sp+14h] [-CCh]
  int v32; // [sp+18h] [-C8h]
  int v33; // [sp+1Ch] [-C4h]
  int v34; // [sp+20h] [-C0h]
  int v35; // [sp+24h] [-BCh]
  int v36; // [sp+28h] [-B8h]
  int v37; // [sp+2Ch] [-B4h]
  int v38; // [sp+30h] [-B0h]
  int v39; // [sp+34h] [-ACh]
  int v40; // [sp+38h] [-A8h]
  int v41; // [sp+3Ch] [-A4h]
  int v42; // [sp+40h] [-A0h]
  int v43; // [sp+44h] [-9Ch]
  int v44; // [sp+48h] [-98h]
  int v45; // [sp+4Ch] [-94h]
  int v46; // [sp+50h] [-90h]
  unsigned __int16 v47; // [sp+60h] [-80h] BYREF
  idVec3 v48; // [sp+64h] [-7Ch] BYREF
  idMat3 v49; // [sp+70h] [-70h] BYREF

  if ( particleDecl != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    presentable = result->presentable;
    v11 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v11 != nullptr )
    {
      idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v47, result: v11, jointName);
      Physics = idEntity::GetPhysics(this: result);
      v13 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v14 = *(float *)(v13 + 4);
      v15 = *(float *)(v13 + 8);
      v49.mat[0].x = *(float *)v13;
      v49.mat[0].y = v14;
      v49.mat[0].z = v15;
      v16 = idEntity::GetPhysics(this: result);
      v17 = (int)v16->GetAxis(this: v16, a2: 0);
      v18 = &v49.mat[1];
      v19 = (float *)(v17 - 4);
      for ( i = 9; i != 0; --i )
      {
        ++v19;
        v18 = (idVec3 *)((char *)v18 + 4);
        v18->x = *v19;
      }
      if ( (v47 & 0x8000u) == 0 )
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: (idTreeAnimator *)v11,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v47,
          origin: v49.mat,
          axis: (idMat3 *)&v49.mat[1].y);
      v48.x = NAN;
      HIDWORD(v21) = 458752;
      v22 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v22 + 1013904223;
      LODWORD(v21) = ((v22 + 1013904223) >> 10) & 0x7FFF;
      *(_QWORD *)&v48.y = v21;
      v23 = (float)((float)v21 * (float)0.000030518509);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: particleDecl,
        systemStartTime: GameMs,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v23,
        origin: &v48,
        axis: &v49,
        velocity: (const idVec3 *)&v49.mat[1].y,
        color: &vec3_origin.x,
        a10: v28,
        a11: v29,
        a12: v30,
        a13: v31,
        a14: v32,
        a15: v33,
        a16: v34,
        a17: v35,
        a18: v36,
        a19: v37,
        a20: v38,
        a21: v39,
        a22: v40,
        a23: v41,
        a24: v42,
        a25: v43,
        a26: v44,
        a27: v45,
        a28: v46,
        a29: (unsigned int *)&v48);
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_StopFX@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82BF8C60
// RVA : 0x00BF8C60
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_StopFX(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        int condition)
{
  idPresentable *presentable; // r11

  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::StopFX(this: presentable, condition, extraCondition: FX_EXTRA_COND_NONE);
  return this;
}


// ========================================================================
// ?AnimEvent_Trigger@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BF8CB0
// RVA : 0x00BF8CB0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_Trigger(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const char *entityName)
{
  idEntity *v6; // r3

  v6 = (idEntity *)((int (__fastcall *)(idGameLocal *, const char *, const idMD6Anim *))gameLocal->FindEntity)(
                     a1: gameLocal,
                     a2: entityName,
                     a3: anim);
  if ( v6 != nullptr )
    idEntity::Activate(this: v6, activator: result);
  return this;
}


// ========================================================================
// ?AnimEvent_Damage@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclDamage@@PBD2@Z
// EA  : 0x82BF8D20
// RVA : 0x00BF8D20
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_Damage(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idDeclDamage *damageDecl,
        const char *attackerName,
        const char *inflictorName)
{
  idEntity *v10; // r26
  idEntity *v11; // r3
  idStr v13[3]; // [sp+60h] [-60h] BYREF

  v13[0].len = 0;
  v13[0].allocedAndFlag = 20;
  v13[0].data = v13[0].baseBuffer;
  v13[0].baseBuffer[0] = 0;
  v10 = gameLocal->FindEntityForName(this: gameLocal, a2: attackerName, a3: result, a4: result, a5: v13);
  v11 = gameLocal->FindEntityForName(this: gameLocal, a2: inflictorName, a3: result, a4: v10, a5: v13);
  ((void (__fastcall *)(idEntity *, idEntity *, idEntity *, const idDeclDamage *))result->Damage)(
    a1: result,
    a2: v11,
    a3: v10,
    a4: damageDecl);
  idStr::FreeData(this: v13);
  return this;
}


// ========================================================================
// __unwind$491214
// EA  : 0x82BF8E08
// RVA : 0x00BF8E08
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_491214()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?AnimEvent_RadiusDamage@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclDamage@@PBD@Z
// EA  : 0x82BF8E30
// RVA : 0x00BF8E30
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_RadiusDamage(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idDeclDamage *damageDecl,
        const char *tagName)
{
  idPhysics *Physics; // r3
  const idVec3 *v9; // r3

  Physics = idEntity::GetPhysics(this: result);
  v9 = Physics->GetOrigin(this: Physics, a2: 0);
  idGameLocal::RadiusDamage(
    this: gameLocal,
    origin: v9,
    inflictor: result,
    attacker: result,
    damageDef: damageDecl,
    dmgPower: 1.0);
  return this;
}


// ========================================================================
// ?AnimEvent_Notify@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BF8E98
// RVA : 0x00BF8E98
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_Notify(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const char *notifyMsg)
{
  idEntity::SendNotify_OnAnimNotify(this: result, message: notifyMsg);
  return this;
}


// ========================================================================
// ?AnimEvent_AddPlayerWhiplash@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA  : 0x82BF8ED0
// RVA : 0x00BF8ED0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_AddPlayerWhiplash(
        idAnimatedEntity *this,
        eventVoid *result,
        const idMD6Anim *anim,
        double pitch,
        double yaw,
        double roll)
{
  idPlayer *Player; // r3
  idPresentable *presentable; // r3
  int v12; // r3
  idAngles v14; // [sp+50h] [-40h] BYREF

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  if ( Player != nullptr )
  {
    v14.pitch = pitch;
    v14.yaw = yaw;
    v14.roll = roll;
    presentable = Player->presentable;
    if ( presentable != nullptr )
      v12 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v12 = 0;
    idView::AddDefaultWhiplash(this: (idView *)(v12 + 16224), angles: &v14);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_ShowKit@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@W4meshKitComponents_t@@PBD@Z
// EA  : 0x82BF8F78
// RVA : 0x00BF8F78
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_ShowKit(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        meshKitComponents_t kitType,
        const char *kitName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( TreeAnimatorFromPresentable != nullptr )
    idTreeAnimator::HideKitsExcept(this: TreeAnimatorFromPresentable, kitType, name: kitName);
  return this;
}


// ========================================================================
// ?AnimEvent_SetSkin@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BF8FB8
// RVA : 0x00BF8FB8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SetSkin(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        const char *skinName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v8; // r31
  idDeclSkins *skinPreload; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  v8 = TreeAnimatorFromPresentable;
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    if ( skinName == nullptr )
    {
      TreeAnimatorFromPresentable->g.customSkin = -1;
      return this;
    }
    skinPreload = result->skinPreload;
    if ( skinPreload != nullptr )
    {
      v8->g.customSkin = idDeclSkins::IndexForSkin(this: skinPreload, name: skinName);
      return this;
    }
    idTreeAnimator::SetKitSkin(this: v8, skin: skinName);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_ScriptFunction@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BF9038
// RVA : 0x00BF9038
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_ScriptFunction(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const char *functionName)
{
  idGameLocal::CallFrameCommand(this: gameLocal, ent: result, frameCommand: functionName);
  return this;
}


// ========================================================================
// ?AnimEvent_ScriptFunctionObject@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BF9078
// RVA : 0x00BF9078
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_ScriptFunctionObject(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const char *functionName)
{
  idGameLocal::CallObjectFrameCommand(this: gameLocal, ent: result, frameCommand: functionName);
  return this;
}


// ========================================================================
// ?AnimEvent_Sound@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF90B8
// RVA : 0x00BF90B8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_Sound(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_ANY,
    shader,
    parms: (const soundShaderParms_t *)&result[6].renderModelInfo.scale.z,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundMusic@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF9100
// RVA : 0x00BF9100
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SoundMusic(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_MUSIC1,
    shader,
    parms: (const soundShaderParms_t *)&result[6].renderModelInfo.scale.z,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_PitchedSound@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@M@Z
// EA  : 0x82BF9148
// RVA : 0x00BF9148
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_PitchedSound(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idSoundShader *shader,
        double pitchAdj)
{
  soundShaderParms_t v7; // [sp+50h] [-C0h] BYREF

  v7 = *(soundShaderParms_t *)&result[6].renderModelInfo.scale.z;
  v7.pitch.max = pitchAdj;
  v7.pitch.min = v7.pitch.max;
  idEntity::StartSoundShader(this: result, channel: SND_CHANNEL_ANY, shader, parms: &v7, peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundWeapon@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF91A8
// RVA : 0x00BF91A8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SoundWeapon(
        idAnimatedEntity *this,
        idPlayer *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idPresentable *presentable; // r3
  int v8; // r3

  if ( (unsigned __int8)idPlayer::IsTypeOf(c: result) == 0
    || ((presentable = idPlayer::CastTo(c: result)->presentable) == nullptr
      ? (v8 = 0)
      : (v8 = (int)presentable->GetPlayerInterface_2(this: presentable)),
        (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v8 + 300))(a1: v8) == 0) )
  {
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_WEAPON,
      shader,
      parms: &result->soundOverrideParms,
      peerMask: 0xFFu);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_SoundVoice2@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF9240
// RVA : 0x00BF9240
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SoundVoice2(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_VOICE2,
    shader,
    parms: (const soundShaderParms_t *)&result[6].renderModelInfo.scale.z,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundVoiceHighPrio@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF9288
// RVA : 0x00BF9288
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SoundVoiceHighPrio(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_VOICE,
    shader,
    parms: (const soundShaderParms_t *)&result[6].renderModelInfo.scale.z,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBody@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF92D0
// RVA : 0x00BF92D0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SoundBody(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_BODY,
    shader,
    parms: (const soundShaderParms_t *)&result[6].renderModelInfo.scale.z,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBody2@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF9318
// RVA : 0x00BF9318
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SoundBody2(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_BODY2,
    shader,
    parms: (const soundShaderParms_t *)&result[6].renderModelInfo.scale.z,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBody3@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF9360
// RVA : 0x00BF9360
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SoundBody3(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_BODY3,
    shader,
    parms: (const soundShaderParms_t *)&result[6].renderModelInfo.scale.z,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundItem@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BF93A8
// RVA : 0x00BF93A8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SoundItem(
        idAnimatedEntity *this,
        idEntity *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_ITEM,
    shader,
    parms: (const soundShaderParms_t *)&result[6].renderModelInfo.scale.z,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_FadeSoundGroup@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@W4soundShaderGroups_t@@MM@Z
// EA  : 0x82BF93F0
// RVA : 0x00BF93F0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_FadeSoundGroup(
        idAnimatedEntity *this,
        eventVoid *result,
        const idMD6Anim *anim,
        soundShaderGroups_t group,
        double toDB,
        double overSec)
{
  if ( clientGame->soundWorld != nullptr )
    ((void (__fastcall *)(idSoundWorld *, soundShaderGroups_t, const idMD6Anim *, int, double))clientGame->soundWorld->Fade)(
      a1: clientGame->soundWorld,
      a2: group,
      a3: anim,
      a4: (int)(float)((float)1000.0 * (float)overSec),
      a5: toDB);
  return this;
}


// ========================================================================
// ?AnimEvent_AttachEntity@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD1@Z
// EA  : 0x82BF9460
// RVA : 0x00BF9460
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_AttachEntity(
        idAnimatedEntity *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *entityName,
        const char *tagName)
{
  idEntity *v8; // r31
  idHandle<int,enum invalidAttachment_t,-1> *v9; // r4
  idAttachmentCollection v11[2]; // [sp+50h] [-30h] BYREF

  v8 = gameLocal->FindEntity(this: gameLocal, a2: entityName);
  if ( v8 != nullptr )
  {
    v9 = (idHandle<int,enum invalidAttachment_t,-1> *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 484))(a1: result);
    if ( v9 != nullptr )
      idAttachmentCollection::AddAttachment(this: v11, result: v9, ent: v8, tag: tagName);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_DetachEntity@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BF94E0
// RVA : 0x00BF94E0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_DetachEntity(
        idAnimatedEntity *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *entityName)
{
  const idEntity *v6; // r30
  idAttachmentCollection *v7; // r3

  v6 = gameLocal->FindEntity(this: gameLocal, a2: entityName);
  if ( v6 != nullptr )
  {
    v7 = (idAttachmentCollection *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 484))(a1: result);
    if ( v7 != nullptr )
      idAttachmentCollection::RemoveAttachment(this: v7, ent: v6);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_Pause@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BF9550
// RVA : 0x00BF9550
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_Pause(
        idAnimatedEntity *this,
        eventVoid *result,
        const idMD6Anim *anim)
{
  idTypesafeNumber<int,enum gameTimeUnique_t> v6; // [sp+50h] [-20h] BYREF

  v6.value = ((int (__fastcall *)(idGameLocal *, int, const idMD6Anim *))gameLocal->GetGameMs)(
               a1: gameLocal,
               a2: 1,
               a3: anim);
  idAnimStack::Pause(this: (idAnimStack *)&result[800], curTime: &v6);
  return this;
}


// ========================================================================
// ?GetTreeAnimator@idAnimatedEntityInterface@@UAAPAVidTreeAnimator@@H@Z
// EA  : 0x82BF95B8
// RVA : 0x00BF95B8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idTreeAnimator *__fastcall idAnimatedEntityInterface::GetTreeAnimator(idAnimatedEntityInterface *this, int id)
{
  idAnimatedEntity *v2; // r3
  idAnimatedEntity *v3; // r3
  idEntity *v4; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v7; // r30

  v2 = (idAnimatedEntity *)((int (__fastcall *)(idAnimatedEntityInterface *, int))this->GetEntity)(a1: this, a2: id);
  v3 = idAnimatedEntity::CastTo(c: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v3);
  presentable = v4->presentable;
  v7 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v4);
    presentable = v4->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  return v7;
}


// ========================================================================
// ??1idAnimatedEntity@@UAA@XZ
// EA  : 0x82BF9640
// RVA : 0x00BF9640
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::~idAnimatedEntity(idAnimatedEntity *this)
{
  idAnimStack *p_animStack; // r29
  idAnimator_Proxy *p_proxyAnimator; // r27
  idDamageEffect *i; // r3
  idIndex<short,enum invalidJointIndex_t> *list; // r4

  this->__vftable = (idAnimatedEntity_vtbl *)&idAnimatedEntity::`vftable';
  p_animStack = &this->animStack;
  p_proxyAnimator = &this->proxyAnimator;
  idAnimator_Base::Shutdown(this: &this->proxyAnimator, stack: &this->animStack);
  idImpactManager::Shutdown(this: &this->impactManager);
  idAnimStack::Shutdown(this: p_animStack);
  for ( i = this->damageEffects; i != nullptr; i = this->damageEffects )
  {
    this->damageEffects = i->next;
    ((void (__fastcall *)(idDamageEffect *, int))i->dtr_idClass)(a1: i, a2: 1);
  }
  if ( this->radiusDamageJointIndices.listStatic == 0 || this->radiusDamageJointIndices.listStatic == 2 )
  {
    list = this->radiusDamageJointIndices.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->radiusDamageJointIndices.list = nullptr;
    this->radiusDamageJointIndices.size = 0;
  }
  this->radiusDamageJointIndices.num = 0;
  idAnimator_Proxy::~idAnimator_Proxy(this: p_proxyAnimator);
  idClothComponent::~idClothComponent(this: &this->clothComponent);
  idStr::FreeData(this: &this->damageSwapSkin);
  idAnimEventHandler::~idAnimEventHandler(this: &this->animEventHandler);
  idImpactManager::~idImpactManager(this: &this->impactManager);
  idAnimStack::~idAnimStack(this: p_animStack);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$491891
// EA  : 0x82BF9744
// RVA : 0x00BF9744
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_491891()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$491892
// EA  : 0x82BF976C
// RVA : 0x00BF976C
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_491892()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 144 + 164) + 800));
}


// ========================================================================
// __unwind$491893
// EA  : 0x82BF9798
// RVA : 0x00BF9798
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_491893()
{
  int v0; // r12

  idImpactManager::~idImpactManager(this: (idImpactManager *)(*(_DWORD *)(v0 - 144 + 164) + 2376));
}


// ========================================================================
// __unwind$491894
// EA  : 0x82BF97C4
// RVA : 0x00BF97C4
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_491894()
{
  int v0; // r12

  idAnimEventHandler::~idAnimEventHandler(this: (idAnimEventHandler *)(*(_DWORD *)(v0 - 144 + 164) + 3468));
}


// ========================================================================
// __unwind$491895
// EA  : 0x82BF97F0
// RVA : 0x00BF97F0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_491895()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 4912));
}


// ========================================================================
// __unwind$491896
// EA  : 0x82BF981C
// RVA : 0x00BF981C
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_491896()
{
  int v0; // r12

  idClothComponent::~idClothComponent(this: (idClothComponent *)(*(_DWORD *)(v0 - 144 + 164) + 5096));
}


// ========================================================================
// __unwind$491897
// EA  : 0x82BF9848
// RVA : 0x00BF9848
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_491897()
{
  int v0; // r12

  idAnimator_Proxy::~idAnimator_Proxy(this: (idAnimator_Proxy *)(*(_DWORD *)(v0 - 144 + 164) + 5124));
}


// ========================================================================
// __unwind$491898
// EA  : 0x82BF9874
// RVA : 0x00BF9874
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_491898()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5168));
}


// ========================================================================
// ?Spawn@idAnimatedEntity@@QAAXXZ
// EA  : 0x82BF98A8
// RVA : 0x00BF98A8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::Spawn(idAnimatedEntity *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r24
  idPresentable *presentable; // r3
  idPhysics *Physics; // r28
  idPhysics *v5; // r27
  int GameMs; // r26
  idPresentable *v7; // r25
  const idMat3 *v8; // r28
  const idVec3 *v9; // r3
  __int64 v10; // r7
  unsigned int seed; // r4
  unsigned int v12; // r10
  double v13; // fp31
  idEffectsModelManager *Axis; // r3
  int v15; // r5
  double initialMorphValue; // fp1
  char *data; // r4
  idAnimator_AnimWeb *v18; // r27
  idDeclMD6 *decl; // r26
  int num; // r24
  md6WeightGroup_t UserChannelWeightGroup; // r29
  idGameTimeManager *v22; // r3
  idGameTimeManager *v23; // r3
  idAnimatorParms_Base v24; // [sp+60h] [-D0h] BYREF
  idAnimatorParms_Base v25; // [sp+A0h] [-90h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  idAnimStack::Init(this: &this->animStack, treeAnimator: TreeAnimatorFromPresentable);
  Physics = idEntity::GetPhysics(this);
  v5 = idEntity::GetPhysics(this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v7 = this->presentable;
  v8 = Physics->GetAxis(this: Physics, a2: 0);
  v9 = v5->GetOrigin(this: v5, a2: 0);
  idFXManager::StartFX(this: &v7->fxManager, org: v9, axis: v8, time: GameMs, startCondition: 0);
  HIDWORD(v10) = &unk_822D0000;
  seed = clientGame->random.seed;
  v12 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v12;
  LODWORD(v10) = (v12 >> 10) & 0x7FFF;
  v13 = (float)((float)v10 * (float)0.000030518509);
  Axis = (idEffectsModelManager *)idPhysics_Static::GetAxis(this: (idPhysics_Static *)clientGame, id: seed);
  idImpactManager::Init(
    this: &this->impactManager,
    effectsModelManager_: Axis,
    diversity: v13,
    maxImpacts: v15,
    playerIndex: 8,
    a6: 0);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    if ( TreeAnimatorFromPresentable->decl->morphVertices != nullptr )
    {
      if ( this->damageSwapSkin.len != 0 )
      {
        if ( g_EnableGore.valueInteger != 0 )
        {
          initialMorphValue = this->initialMorphValue;
          data = this->damageSwapSkin.data;
        }
        else
        {
          data = this->damageSwapSkin.data;
          initialMorphValue = 0.0;
        }
      }
      else
      {
        if ( g_EnableGore.valueInteger != 0 )
          initialMorphValue = this->initialMorphValue;
        else
          initialMorphValue = 0.0;
        data = nullptr;
      }
      idTreeAnimator::SetMorphSkin(
        this: TreeAnimatorFromPresentable,
        skinName: data,
        skinIndex: -1,
        morphAmount: initialMorphValue);
    }
    v18 = this->GetAnimatorAnimWeb(this);
    if ( v18 != nullptr )
    {
      decl = TreeAnimatorFromPresentable->decl;
      num = decl->userChannelToAnimationAliasMap.num;
      UserChannelWeightGroup = idDeclMD6::GetUserChannelWeightGroup(this: decl);
      if ( num > 0 && decl->baseUserChannelAlias.value != 0xFFFF )
      {
        v24.animStack = this->GetAnimStack_2(this);
        idStr::idStr(this: &v24.name, text: "ChannelWeight");
        v24.alpha = 0.0;
        v24.originBlend = ORIGINBLEND_BRANCH;
        v24.blendOp = BOP_ADD_RIGHT;
        v24.weightGroup = UserChannelWeightGroup;
        v24.filterGroup = UserChannelWeightGroup;
        v22 = gameLocal->GetGameTimeManager(this: gameLocal);
        idAnimator_Base::Init(this: &v18->channelWeightAnimator, gametimeManager: v22, parms: &v24);
        if ( (_cntlzw((unsigned int)v18->channelWeightAnimator.lockOwner) & 0x20) != 0 )
          v18->channelWeightAnimator.entityNumber = this->entityNumber;
        idStr::FreeData(this: &v24.name);
      }
    }
    v25.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v25.name, text: "Proxy");
    memset(&v25.originBlend, 0, 12);
    v25.blendOp = BOP_LERP;
    v25.alpha = 1.0;
    v23 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->proxyAnimator, gametimeManager: v23, parms: &v25);
    idStr::FreeData(this: &v25.name);
  }
  idClothComponent::Init(this: &this->clothComponent, inAnimtedEntity: this);
}


// ========================================================================
// __unwind$492237_0
// EA  : 0x82BF9BD8
// RVA : 0x00BF9BD8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_492237_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$492238
// EA  : 0x82BF9C00
// RVA : 0x00BF9C00
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_492238()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 304 + 160));
}


// ========================================================================
// ?GetWorldSpaceJointTransform@idAnimatedEntity@@QBA_NPBDAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BF9C28
// RVA : 0x00BF9C28
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

int __fastcall idAnimatedEntity::GetWorldSpaceJointTransform(
        idAnimatedEntity *this,
        const char *jointName,
        idVec3 *offset,
        idMat3 *axis)
{
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r4
  unsigned __int16 v10; // [sp+50h] [-30h] BYREF

  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v10, result: TreeAnimatorFromPresentable, jointName);
    return idAnimatedEntity::GetWorldSpaceJointTransform(
             this,
             jointIndex: (idIndex<short,enum invalidJointIndex_t> *)v10,
             offset,
             axis);
  }
  else
  {
    idLib::Warning(
      fmt: "%s - entity <%s> has no tree animator",
      "idAnimatedEntity::GetWorldSpaceJointTransform",
      this->name.data);
    return 0;
  }
}


// ========================================================================
// ?UnpauseAnimation@idAnimatedEntity@@QAAXXZ
// EA  : 0x82BF9CA0
// RVA : 0x00BF9CA0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::UnpauseAnimation(idAnimatedEntity *this)
{
  int value; // r30
  idTypesafeNumber<int,enum gameTimeUnique_t> v3[2]; // [sp+50h] [-20h] BYREF

  value = this->animStack.pauseTime.value;
  v3[0].value = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - value;
  idAnimEventHandler::OffsetTimes(this: &this->animEventHandler, timeOffset: v3);
  v3[0].value = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idAnimStack::Unpause(this: &this->animStack, curTime: v3);
}


// ========================================================================
// ?Event_StartFX@idAnimatedEntity@@AAA?AVeventVoid@@W4fxCondition_t@@@Z
// EA  : 0x82BF9D30
// RVA : 0x00BF9D30
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::Event_StartFX(
        idAnimatedEntity *this,
        idEntity *result,
        fxCondition_t condition)
{
  idPresentable *presentable; // r3

  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  presentable->StartFX(this: presentable, a2: condition, a3: FX_EXTRA_COND_NONE);
  return this;
}


// ========================================================================
// ?Event_StopFX@idAnimatedEntity@@AAA?AVeventVoid@@W4fxCondition_t@@@Z
// EA  : 0x82BF9D88
// RVA : 0x00BF9D88
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::Event_StopFX(idAnimatedEntity *this, idEntity *result, int condition)
{
  idPresentable *presentable; // r11

  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::StopFX(this: presentable, condition, extraCondition: FX_EXTRA_COND_NONE);
  return this;
}


// ========================================================================
// ?GetRepairBotTetherPoint@idAnimatedEntity@@UBA_NHHAAVidVec3@@@Z
// EA  : 0x82BF9DD8
// RVA : 0x00BF9DD8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

int __fastcall idAnimatedEntity::GetRepairBotTetherPoint(
        idAnimatedEntity *this,
        int tetherPointIdx,
        const int clipMask,
        idVec3 *outPos)
{
  int v6; // r28
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v9; // r30
  idPropsCollection *decl; // r11
  const tagData_t *Tag; // r4
  idMat3 v13[2]; // [sp+50h] [-50h] BYREF

  if ( tetherPointIdx >= 0 )
  {
    v6 = 4;
    if ( tetherPointIdx <= 4 )
      v6 = tetherPointIdx;
  }
  else
  {
    v6 = 0;
  }
  *outPos = vec3_origin;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v9 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v9 != nullptr )
    decl = (idPropsCollection *)v9->decl;
  else
    decl = nullptr;
  if ( decl == nullptr || decl == (idPropsCollection *)-352 )
    return 0;
  Tag = idPropsCollection::GetTag(
          this: decl + 22,
          propName: idPropInfo::INFO_PROP_NAME,
          tagName: tetherPointTagNames[v6]);
  if ( Tag->parentJoint.value == 0xFFFF )
  {
    idLib::Warning(fmt: "%s invalid tag data", "idAnimatedEntity::GetRepairBotTetherPoint");
    return 0;
  }
  idTreeAnimator::GetWorldSpaceTagTransform(this: v9, tagData: Tag, origin: outPos, axis: v13);
  return 1;
}


// ========================================================================
// ?AnimEvent_StartFX@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82BF9EE8
// RVA : 0x00BF9EE8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_StartFX(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        fxCondition_t condition)
{
  idPresentable *presentable; // r11
  idFXManager *p_fxManager; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idClientGame *v10; // r5
  __int64 v11; // r8
  const idDeclFX *fxDecl; // r4
  idRenderWorld *renderWorld; // r5
  idPhysics *Physics; // r26
  idPhysics *v15; // r27
  int GameMs; // r25
  const idMat3 *v17; // r26
  const idVec3 *v18; // r3
  idPresentable *v19; // r3
  fxEmitterSound_t v21[10]; // [sp+50h] [-50h] BYREF

  if ( result->fxDecl == nullptr && common->IsToolActive(this: common) && (com_editors & 0x2000) != 0 )
  {
    if ( *anim_fxDeclName.valueString.data != 0 )
      result->fxDecl = (const idDeclFX *)idDeclInfo::FindWithInheritance(
                                           this: &idDeclFX::resourceList,
                                           name: anim_fxDeclName.valueString.data,
                                           makeDefault: false);
    presentable = result->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    p_fxManager = &presentable->fxManager;
    if ( presentable->fxManager.initialized )
      idFXManager::Shutdown(this: &presentable->fxManager);
    v21[0].emitter = idEntity::GetSoundEmitter(this: result, alloc: true);
    v21[0].channel = SND_CHANNEL_FX;
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    v10 = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    LODWORD(v11) = (v10->random.seed >> 10) & 0x7FFF;
    fxDecl = result->fxDecl;
    HIDWORD(v11) = &clientGame->gameLibEffects;
    renderWorld = clientGame->renderWorld;
    v21[1] = (fxEmitterSound_t)v11;
    idFXManager::Init(
      this: p_fxManager,
      declFX: fxDecl,
      _rw: renderWorld,
      _soundInfo: v21,
      _gameLibEffects: &clientGame->gameLibEffects,
      diversity: (float)((float)v11 * (float)0.000030518509),
      _ta: (idTreeAnimator *)v11,
      a8: TreeAnimatorFromPresentable);
    Physics = idEntity::GetPhysics(this: result);
    v15 = idEntity::GetPhysics(this: result);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v17 = Physics->GetAxis(this: Physics, a2: 0);
    v18 = v15->GetOrigin(this: v15, a2: 0);
    idFXManager::StartFX(this: p_fxManager, org: v18, axis: v17, time: GameMs, startCondition: 0);
  }
  v19 = result->presentable;
  if ( v19 == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    v19 = result->presentable;
  }
  v19->StartFX(this: v19, a2: condition, a3: FX_EXTRA_COND_NONE);
  return this;
}


// ========================================================================
// ?AnimEvent_Default@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BFA0F8
// RVA : 0x00BFA0F8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_Default(
        idAnimatedEntity *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim)
{
  const char *str; // r4
  const char *v7; // r5
  idStr v9[2]; // [sp+50h] [-50h] BYREF

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result) != nullptr )
    str = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result)->decl->name.str;
  else
    str = "N/A";
  idStr::idStr(this: v9, text: str);
  if ( anim != nullptr )
    v7 = anim->name.str;
  else
    v7 = "< NULL >";
  idLib::Warning(fmt: "Defaulted anim_Event in decl '%s' anim '%s'", v9[0].data, v7);
  idStr::FreeData(this: v9);
  return this;
}


// ========================================================================
// __unwind$492646
// EA  : 0x82BFA184
// RVA : 0x00BFA184
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_492646()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?AnimEvent_SoundVoice@idAnimatedEntity@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82BFA1B0
// RVA : 0x00BFA1B0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::AnimEvent_SoundVoice(
        idAnimatedEntity *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  idAI2 *v7; // r3
  int value; // r28

  v7 = idAI2::CastTo(c: result);
  if ( v7 == nullptr
    || (value = idAI2::GetVoiceController(this: v7, vc: 0)->nextVoiceTime.value) <= idGameTimeManager::GetGameMs(
                                                                                      this: &clientGame->gameTimeManager,
                                                                                      type: GAMETIME_SCALED) )
  {
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_VOICE,
      shader,
      parms: &result->soundOverrideParms,
      peerMask: 0xFFu);
  }
  return this;
}


// ========================================================================
// ?GetMasterPosition@idAnimatedEntityPhysicsCallbacks@@UAA_NAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BFA270
// RVA : 0x00BFA270
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

int __fastcall idAnimatedEntityPhysicsCallbacks::GetMasterPosition(
        idAnimatedEntityPhysicsCallbacks *this,
        idVec3 *masterOrigin,
        idMat3 *masterAxis)
{
  int value; // r10
  idEntity *v7; // r3
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  int v11; // r9
  idEntity *v12; // r3
  idEntity *v13; // r3
  idEntity *BindMaster; // r3
  idPhysics *Physics; // r3
  float *v16; // r3
  idGameLocal *v17; // r10
  int v18; // r9
  idEntity *v19; // r3
  idEntity *v20; // r3
  idEntity *v21; // r3
  idPhysics *v22; // r3
  float *v23; // r3

  value = this->ent.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v7) != nullptr
    && ((v8 = this->ent.spawnId.value, gameLocal->spawnIds.ptr[v8 & 0x1FFF] != v8 >> 13)
     || (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) == nullptr
      ? (v10 = nullptr)
      : (v10 = idEntity::CastTo(c: v9)),
        idEntity::GetBindMaster(this: v10) != nullptr) )
  {
    v11 = this->ent.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13 && (v12 = gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
      v13 = idEntity::CastTo(c: v12);
    else
      v13 = nullptr;
    BindMaster = idEntity::GetBindMaster(this: v13);
    Physics = idEntity::GetPhysics(this: BindMaster);
    v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v17 = gameLocal;
    masterOrigin->x = *v16;
    masterOrigin->y = v16[1];
    masterOrigin->z = v16[2];
    v18 = this->ent.spawnId.value;
    if ( v17->spawnIds.ptr[v18 & 0x1FFF] == v18 >> 13 && (v19 = v17->entities.ptr[v18 & 0x1FFF]) != nullptr )
      v20 = idEntity::CastTo(c: v19);
    else
      v20 = nullptr;
    v21 = idEntity::GetBindMaster(this: v20);
    v22 = idEntity::GetPhysics(this: v21);
    v23 = (float *)v22->GetAxis(this: v22, a2: 0);
    masterAxis->mat[0].x = *v23;
    masterAxis->mat[0].y = v23[1];
    masterAxis->mat[0].z = v23[2];
    masterAxis->mat[1].x = v23[3];
    masterAxis->mat[1].y = v23[4];
    masterAxis->mat[1].z = v23[5];
    masterAxis->mat[2].x = v23[6];
    masterAxis->mat[2].y = v23[7];
    masterAxis->mat[2].z = v23[8];
    return 1;
  }
  else
  {
    masterOrigin->z = 0.0;
    masterOrigin->y = 0.0;
    masterOrigin->x = 0.0;
    masterAxis->mat[2].z = 1.0;
    masterAxis->mat[1].y = 1.0;
    masterAxis->mat[0].x = 1.0;
    masterAxis->mat[1].z = 0.0;
    masterAxis->mat[0].z = 0.0;
    masterAxis->mat[0].y = 0.0;
    masterAxis->mat[2].y = 0.0;
    masterAxis->mat[2].x = 0.0;
    masterAxis->mat[1].x = 0.0;
    return 0;
  }
}


// ========================================================================
// ?UpdateProxyAnimator@idAnimatedEntity@@QAAXXZ
// EA  : 0x82BFA500
// RVA : 0x00BFA500
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::UpdateProxyAnimator(idAnimatedEntity *this)
{
  int value; // r10
  idMD6Node *v3; // r28
  idAnimatedEntity *v4; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int v6; // r9
  const idDeclMD6 *decl; // r30
  idAnimatedEntity *v8; // r3
  idAnimatedEntity *v9; // r3
  int v10; // r3
  int v11; // r31
  int v12; // r9
  idMD6Node *v13; // r31
  __int16 v14; // [sp+50h] [-30h] BYREF

  value = this->animationMaster.spawnId.value;
  v3 = nullptr;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idAnimatedEntity *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr && idAnimatedEntity::CastTo(c: v4) != nullptr )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        v6 = this->animationMaster.spawnId.value;
        decl = TreeAnimatorFromPresentable->decl;
        if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
          && (v8 = (idAnimatedEntity *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
        {
          v9 = idAnimatedEntity::CastTo(c: v8);
        }
        else
        {
          v9 = nullptr;
        }
        v10 = (int)v9->GetAnimatorAnimWeb(this: v9);
        v11 = v10;
        if ( v10 != 0 )
        {
          idDeclAnimWeb::FindModelIndex(
            this: (idDeclAnimWeb *)&v14,
            result: *(const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> **)(v10 + 40),
            decl);
          if ( v14 >= 0 )
          {
            v12 = *(_DWORD *)(v11 + 64);
            v13 = *(idMD6Node **)(72 * v14 + v12);
            if ( v13 != nullptr && (unsigned __int8)idMD6Node::IsValid(this: *(idMD6Node **)(72 * v14 + v12)) != 0 )
              v3 = v13;
          }
        }
      }
    }
  }
  idAnimator_Proxy::SetTree(this: &this->proxyAnimator, tree: v3);
}


// ========================================================================
// ??0idAnimatedEntity@@QAA@XZ
// EA  : 0x82BFA640
// RVA : 0x00BFA640
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

idAnimatedEntity *__fastcall idAnimatedEntity::idAnimatedEntity(idAnimatedEntity *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idAnimatedEntity_vtbl *)&idAnimatedEntity::`vftable';
  idAnimStack::idAnimStack(this: &this->animStack);
  this->damageEffects = nullptr;
  idImpactManager::idImpactManager(this: &this->impactManager);
  this->skinPreload = nullptr;
  this->fxDecl = nullptr;
  idAnimEventHandler::idAnimEventHandler(this: &this->animEventHandler);
  this->damageSwapSkin.len = 0;
  this->damageSwapSkin.allocedAndFlag = 20;
  this->damageSwapSkin.data = this->damageSwapSkin.baseBuffer;
  this->damageSwapSkin.baseBuffer[0] = 0;
  this->initialMorphValue = 0.0;
  soundShaderParms_t::Clear(this: &this->soundOverrideParms);
  idRibbonManager::idRibbonManager(this: (idRibbonManager *)&this->clothComponent);
  this->pauseTime.value = 0;
  this->animationMaster.spawnId.value = 0x1FFF;
  idAnimator_Proxy::idAnimator_Proxy(this: &this->proxyAnimator);
  this->radiusDamageJointIndices.list = nullptr;
  this->radiusDamageJointIndices.granularity = 0;
  this->radiusDamageJointIndices.memTag = 5;
  this->radiusDamageJointIndices.listStatic = 0;
  this->radiusDamageJointIndices.size = 0;
  this->radiusDamageJointIndices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->radiusDamageJointIndices);
  this->defaultPhysicsCallbacks.__vftable = (idAnimatedEntityPhysicsCallbacks_vtbl *)&idAnimatedEntityPhysicsCallbacks::`vftable';
  this->defaultPhysicsCallbacks.ent.spawnId.value = 0x1FFF;
  this->defaultPhysicsCallbacks.af = nullptr;
  return this;
}


// ========================================================================
// __unwind$493626
// EA  : 0x82BFA73C
// RVA : 0x00BFA73C
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_493626()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$493627
// EA  : 0x82BFA764
// RVA : 0x00BFA764
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_493627()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// __unwind$493628
// EA  : 0x82BFA790
// RVA : 0x00BFA790
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_493628()
{
  int v0; // r12

  idImpactManager::~idImpactManager(this: (idImpactManager *)(*(_DWORD *)(v0 - 128 + 148) + 2376));
}


// ========================================================================
// __unwind$493629
// EA  : 0x82BFA7BC
// RVA : 0x00BFA7BC
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_493629()
{
  int v0; // r12

  idAnimEventHandler::~idAnimEventHandler(this: (idAnimEventHandler *)(*(_DWORD *)(v0 - 128 + 148) + 3468));
}


// ========================================================================
// __unwind$493630
// EA  : 0x82BFA7E8
// RVA : 0x00BFA7E8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_493630()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 4912));
}


// ========================================================================
// __unwind$493631
// EA  : 0x82BFA814
// RVA : 0x00BFA814
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_493631()
{
  int v0; // r12

  idClothComponent::~idClothComponent(this: (idClothComponent *)(*(_DWORD *)(v0 - 128 + 148) + 5096));
}


// ========================================================================
// __unwind$493632
// EA  : 0x82BFA840
// RVA : 0x00BFA840
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_493632()
{
  int v0; // r12

  idAnimator_Proxy::~idAnimator_Proxy(this: (idAnimator_Proxy *)(*(_DWORD *)(v0 - 128 + 148) + 5124));
}


// ========================================================================
// ?SetRadiusDamageJointIndices@idAnimatedEntity@@IAAXABV?$idList@VidStr@@$04@@@Z
// EA  : 0x82BFA870
// RVA : 0x00BFA870
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::SetRadiusDamageJointIndices(
        idAnimatedEntity *this,
        const idList<idStr,5> *jointNames)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r27
  idPresentable *presentable; // r3
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *p_radiusDamageJointIndices; // r31
  int num; // r4
  int v8; // r28
  int v9; // r30
  const idMD6Model *model; // r11
  idIndex<short,enum invalidJointIndex_t> *skeleton; // r4
  __int16 *JointIndex; // r3
  __int16 v13; // r11
  int v14; // r10
  int v15; // r7
  int v16; // r8
  int v17; // r11
  __int16 v18; // [sp+50h] [-40h] BYREF
  idIndex<short,enum invalidUserChannelIndex_t> v19; // [sp+52h] [-3Eh] BYREF
  idMD6Skel v20; // [sp+54h] [-3Ch] BYREF

  if ( jointNames->num != 0 )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    p_radiusDamageJointIndices = (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&this->radiusDamageJointIndices;
    num = jointNames->num;
    if ( num > p_radiusDamageJointIndices->size )
      idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,5>::Resize(
        this: p_radiusDamageJointIndices,
        newsize: num);
    v8 = 0;
    if ( jointNames->num > 0 )
    {
      v9 = 0;
      do
      {
        model = TreeAnimatorFromPresentable->decl->model;
        if ( model != nullptr && (skeleton = (idIndex<short,enum invalidJointIndex_t> *)model->skeleton) != nullptr )
        {
          JointIndex = (__int16 *)idMD6Skel::GetJointIndex(
                                    this: &v20,
                                    result: skeleton,
                                    name: jointNames->list[v9].data);
        }
        else
        {
          JointIndex = &v18;
          v18 = -1;
        }
        v13 = *JointIndex;
        v14 = 0;
        v15 = p_radiusDamageJointIndices->num;
        v19.value = *JointIndex;
        if ( v15 <= 0 )
          goto LABEL_19;
        v16 = v13;
        v17 = 0;
        while ( p_radiusDamageJointIndices->list[v17].value != v16 )
        {
          ++v14;
          ++v17;
          if ( v14 >= v15 )
            goto LABEL_19;
        }
        if ( v14 < 0 )
LABEL_19:
          idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(this: p_radiusDamageJointIndices, obj: &v19);
        ++v8;
        ++v9;
      }
      while ( v8 < jointNames->num );
    }
  }
  else
  {
    idList<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,5>::SetNum(
      this: (idList<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,5> *)&this->radiusDamageJointIndices,
      newNum: 0);
  }
}


// ========================================================================
// ?UpdateFrameCommands@idAnimatedEntity@@QAAXXZ
// EA  : 0x82BFA9C0
// RVA : 0x00BFA9C0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::UpdateFrameCommands(idAnimatedEntity *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r28
  const idDeclMD6 *v7; // r27
  idAnimatedEntity *v8; // r3
  int v9; // r3
  int v10; // r29
  int v11; // r9
  const idMD6Node *v12; // r28
  idAnimEventHandler *p_animEventHandler; // r29
  int v14; // r25
  int v15; // r26
  const char *v16; // r6
  const idMD6Node *v17; // r5
  const idDeclMD6 *v18; // r4
  const char *v19; // r7
  int v20; // r8
  int v21; // r26
  int PreviousGameMs; // r27
  int GameMs; // r25
  const idDeclMD6 *decl; // r28
  __int16 v25; // [sp+50h] [-60h] BYREF
  idPLogScope v26[11]; // [sp+58h] [-58h] BYREF

  RD_EventBegin(name: "idAnimatedEntity::UpdateFrameCommands");
  LODWORD(v2) = "idAnimatedEntity::UpdateFrameCommands";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v26, pl: &pLog, gMask: v2, label: v3);
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 && this->animStack.pauseTime.value < 0 )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    presentable = this->presentable;
    v6 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v6 != nullptr )
    {
      if ( idEntityPtr<idAnimatedEntity>::operator idAnimatedEntity *(this: &this->animationMaster) == nullptr )
      {
        v21 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        decl = v6->decl;
        p_animEventHandler = &this->animEventHandler;
        v17 = this->GetMD6Tree(this);
        v18 = decl;
        v16 = (const char *)GameMs;
        v19 = (const char *)PreviousGameMs;
        v20 = v21;
        goto LABEL_14;
      }
      v7 = v6->decl;
      v8 = idEntityPtr<idAnimatedEntity>::operator idAnimatedEntity *(this: &this->animationMaster);
      v9 = (int)v8->GetAnimatorAnimWeb(this: v8);
      v10 = v9;
      if ( v9 != 0 )
      {
        idDeclAnimWeb::FindModelIndex(
          this: (idDeclAnimWeb *)&v25,
          result: *(const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> **)(v9 + 40),
          decl: v7);
        if ( v25 >= 0 )
        {
          v11 = *(_DWORD *)(v10 + 64);
          v12 = *(const idMD6Node **)(72 * v25 + v11);
          if ( v12 != nullptr && (unsigned __int8)idMD6Node::IsValid(this: *(idMD6Node **)(72 * v25 + v11)) != 0 )
          {
            p_animEventHandler = &this->animEventHandler;
            v14 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
            v15 = gameLocal->GetPreviousGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            v16 = (const char *)gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            v17 = v12;
            v18 = v7;
            v19 = (const char *)v15;
            v20 = v14;
LABEL_14:
            idAnimEventHandler::BuildAnimEventList(
              this: p_animEventHandler,
              decl: v18,
              tree: v17,
              curTime: v16,
              previousTime: v19,
              ticksPerSec: v20,
              onlyEvents: nullptr,
              onlyNumEvents: 0);
            idEventReceiver::ProcessAnimEvents(this, handler: p_animEventHandler);
          }
        }
      }
    }
  }
  idPLogScope::~idPLogScope(this: v26);
  RD_EventEnd();
}


// ========================================================================
// __unwind$494161
// EA  : 0x82BFAC10
// RVA : 0x00BFAC10
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494161()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$494162_0
// EA  : 0x82BFAC38
// RVA : 0x00BFAC38
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494162_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?UpdateAnimation@idAnimatedEntity@@QAAX_N@Z
// EA  : 0x82BFAC68
// RVA : 0x00BFAC68
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::UpdateAnimation(idAnimatedEntity *this, bool forceNonDeferredBlend)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idTreeAnimator *TreeAnimatorFromPresentable; // r21
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idPresentable *presentable; // r11
  const idMD6Model *model; // r11
  idIndex<short,enum invalidJointIndex_t> *skeleton; // r29
  unsigned int v12; // r5
  _WORD *v13; // r11
  int i; // ctr
  int v15; // r28
  _WORD *v16; // r30
  __int16 *v17; // r30
  idRenderWorld *v18; // r3
  double v19; // fp13
  int v20; // r11
  double v21; // fp12
  idVec3 *v22; // r11
  unsigned __int64 v23; // r6
  const char *v24; // r7
  unsigned __int64 v25; // r6
  const char *v26; // r7
  idParallelJobList *parallelJobList; // r29
  idGameTimeManager *p_gameTimeManager; // r27
  idGameTimeManager *v29; // r24
  int GameMsPerFrame; // r23
  int PreviousGameMs; // r28
  int GameMs; // r3
  unsigned __int64 v33; // r6
  const char *v34; // r7
  unsigned __int64 v35; // r6
  const char *v36; // r7
  unsigned __int64 v37; // r6
  const char *v38; // r7
  float *v39; // [sp+8h] [-428h]
  float *v40; // [sp+Ch] [-424h]
  float *v41; // [sp+10h] [-420h]
  idPLogScope v42; // [sp+70h] [-3C0h] BYREF
  idMD6Skel v43; // [sp+78h] [-3B8h] BYREF
  float v44[17]; // [sp+ACh] [-384h] BYREF
  idLexer v45; // [sp+F0h] [-340h] BYREF
  idMat3 v46; // [sp+180h] [-2B0h] BYREF
  _BYTE v47[2]; // [sp+1AEh] [-282h] BYREF
  int v48; // [sp+1B0h] [-280h] BYREF

  RD_EventBegin(name: "idAnimatedEntity::UpdateAnimation");
  LODWORD(v4) = "idAnimatedEntity::UpdateAnimation";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v43.idResource + 4, pl: &pLog, gMask: v4, label: v5);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  RD_EventBegin(name: "idAnimatedEntity::UpdateAnimation -- misc");
  LODWORD(v7) = "idAnimatedEntity::UpdateAnimation -- misc";
  HIDWORD(v7) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v43.name, pl: &pLog, gMask: v7, label: v8);
  this->UpdateModelTransform(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v43.name);
  RD_EventEnd();
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    if ( (this->thinkFlags & 4) != 0 )
    {
      if ( anim_showJointVelocities.valueInteger == this->entityNumber )
      {
        if ( (_S18_12 & 1) == 0 )
          _S18_12 |= 1u;
        if ( (anim_showJointVelocities.flags & 0x20000) != 0 )
        {
          hasPreviousJointPositions = false;
          anim_showJointVelocities.flags &= ~0x20000u;
        }
        model = TreeAnimatorFromPresentable->decl->model;
        if ( model != nullptr )
          skeleton = (idIndex<short,enum invalidJointIndex_t> *)model->skeleton;
        else
          skeleton = nullptr;
        if ( skeleton != nullptr )
        {
          idLexer::idLexer(this: &v45, flags_: 0);
          v12 = 0;
          if ( *anim_velocityJoints.valueString.data != 0 )
          {
            do
              ++v12;
            while ( anim_velocityJoints.valueString.data[v12] != 0 );
          }
          idLexer::LoadMemory(
            this: &v45,
            ptr: anim_velocityJoints.valueString.data,
            length_: v12,
            name: "anim_velocityJoints");
          v13 = v47;
          for ( i = 256; i != 0; --i )
            *++v13 = -1;
          v43.data = nullptr;
          HIBYTE(v44[0]) = 0;
          v44[10] = 0.0;
          *(_DWORD *)&v43.jointConversion.value = 20;
          v15 = 0;
          v43.timestamp = (unsigned int)v44;
          memset(&v44[12], 0, 12);
          v44[11] = -3.4028235e38;
          if ( idLexer::ReadToken(this: &v45, token: (idToken *)&v43.data) )
          {
            v16 = v47;
            do
            {
              idMD6Skel::GetJointIndex(this: &v43, result: skeleton, name: (const char *)v43.timestamp);
              if ( SHIWORD(v43.__vftable) >= 0 )
              {
                *++v16 = HIWORD(v43.__vftable);
                ++v15;
              }
            }
            while ( idLexer::ReadToken(this: &v45, token: (idToken *)&v43.data) );
          }
          if ( v15 > 0 )
          {
            v17 = (__int16 *)&v48;
            do
            {
              idTreeAnimator::GetWorldSpaceJointTransform(
                this: TreeAnimatorFromPresentable,
                pose: DRIVER_MODEL,
                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)*v17,
                origin: (idVec3 *)&v43.resourceListPtr,
                axis: &v46);
              if ( hasPreviousJointPositions )
              {
                v18 = gameLocal->GetRenderWorld(this: gameLocal);
                ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idResourceList **, double))v18->DebugArrow)(
                  a1: v18,
                  a2: &idColor::colorYellow,
                  a3: &jointPositions[*v17],
                  a4: &v43.resourceListPtr,
                  a5: 2.0);
              }
              v19 = *(float *)&v43.resourceError;
              --v15;
              v20 = *v17;
              v21 = *(float *)&v43.networkID;
              ++v17;
              v22 = &jointPositions[v20];
              v22->x = *(float *)&v43.resourceListPtr;
              v22->y = v19;
              v22->z = v21;
            }
            while ( v15 != 0 );
          }
          hasPreviousJointPositions = true;
          idStr::FreeData(this: (idStr *)&v43.data);
          idLexer::~idLexer(this: &v45);
        }
      }
      RD_EventBegin(name: "idAnimatedEntity::UpdateClothComponent");
      LODWORD(v23) = "idAnimatedEntity::UpdateClothComponent";
      HIDWORD(v23) = 2;
      idPLogScope::idPLogScope(this: (idPLogScope *)&v43.name, pl: &pLog, gMask: v23, label: v24);
      idClothComponent::Update(this: &this->clothComponent);
      idPLogScope::~idPLogScope(this: (idPLogScope *)&v43.name);
      RD_EventEnd();
      RD_EventBegin(name: "idAnimatedEntity::UpdateAnimation::BlendStack");
      LODWORD(v25) = "idAnimatedEntity::UpdateAnimation::BlendStack";
      HIDWORD(v25) = 2;
      idPLogScope::idPLogScope(this: &v42, pl: &pLog, gMask: v25, label: v26);
      if ( forceNonDeferredBlend )
        parallelJobList = nullptr;
      else
        parallelJobList = gameLocal->parallelJobList;
      p_gameTimeManager = &clientGame->gameTimeManager;
      v43.name.str = (const char *)&clientGame->gameTimeManager;
      v29 = (idGameTimeManager *)(timeManager.gameTimePerFrame.value * timeManager.gameHz);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idAnimStack::BlendStackInternal(
        this: &this->animStack,
        currentTime: GameMs,
        previousTime: PreviousGameMs,
        gameMsPerFrame: GameMsPerFrame,
        ticksPerSec: v29,
        game: p_gameTimeManager,
        parallelJobList,
        localR: nullptr,
        localS: v39,
        localT: v40,
        localU: v41);
      idPLogScope::~idPLogScope(this: &v42);
      RD_EventEnd();
      RD_EventBegin(name: "idAnimatedEntity::UpdateAnimation -- update visuals");
      LODWORD(v33) = "idAnimatedEntity::UpdateAnimation -- update visuals";
      HIDWORD(v33) = 2;
      idPLogScope::idPLogScope(this: &v42, pl: &pLog, gMask: v33, label: v34);
      idEntity::UpdateVisuals(this);
      idPLogScope::~idPLogScope(this: &v42);
      RD_EventEnd();
      RD_EventBegin(name: "idAnimatedEntity::UpdateAnimation::UpdateAttachments");
      LODWORD(v35) = "idAnimatedEntity::UpdateAnimation::UpdateAttachments";
      HIDWORD(v35) = 2;
      idPLogScope::idPLogScope(this: &v42, pl: &pLog, gMask: v35, label: v36);
      this->UpdateAttachments(this);
      idPLogScope::~idPLogScope(this: &v42);
      RD_EventEnd();
    }
    else
    {
      RD_EventBegin(name: "idAnimatedEntity::UpdateAnimation -- update visuals");
      LODWORD(v37) = "idAnimatedEntity::UpdateAnimation -- update visuals";
      HIDWORD(v37) = 2;
      idPLogScope::idPLogScope(this: &v42, pl: &pLog, gMask: v37, label: v38);
      idEntity::UpdateVisuals(this);
      idPLogScope::~idPLogScope(this: &v42);
      RD_EventEnd();
      idTreeAnimator::ClearJointMods(this: TreeAnimatorFromPresentable);
    }
  }
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v43.idResource + 4);
  RD_EventEnd();
}


// ========================================================================
// __unwind$494329
// EA  : 0x82BFB1A0
// RVA : 0x00BFB1A0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494329()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1072 + 944));
}


// ========================================================================
// __unwind$494330_0
// EA  : 0x82BFB1C8
// RVA : 0x00BFB1C8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494330_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1072 + 152));
}


// ========================================================================
// __unwind$494331_0
// EA  : 0x82BFB1F0
// RVA : 0x00BFB1F0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494331_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1072 + 945));
}


// ========================================================================
// __unwind$494332
// EA  : 0x82BFB218
// RVA : 0x00BFB218
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494332()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1072 + 128));
}


// ========================================================================
// __unwind$494334
// EA  : 0x82BFB240
// RVA : 0x00BFB240
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494334()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 1072 + 240));
}


// ========================================================================
// __unwind$494335
// EA  : 0x82BFB268
// RVA : 0x00BFB268
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494335()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1072 + 160));
}


// ========================================================================
// __unwind$494336
// EA  : 0x82BFB290
// RVA : 0x00BFB290
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494336()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1072 + 946));
}


// ========================================================================
// __unwind$494337
// EA  : 0x82BFB2B8
// RVA : 0x00BFB2B8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494337()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1072 + 128));
}


// ========================================================================
// __unwind$494338
// EA  : 0x82BFB2E0
// RVA : 0x00BFB2E0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494338()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1072 + 947));
}


// ========================================================================
// __unwind$494339
// EA  : 0x82BFB308
// RVA : 0x00BFB308
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494339()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1072 + 112));
}


// ========================================================================
// __unwind$494340
// EA  : 0x82BFB330
// RVA : 0x00BFB330
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494340()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1072 + 948));
}


// ========================================================================
// __unwind$494341
// EA  : 0x82BFB358
// RVA : 0x00BFB358
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494341()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1072 + 112));
}


// ========================================================================
// __unwind$494342
// EA  : 0x82BFB380
// RVA : 0x00BFB380
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494342()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1072 + 949));
}


// ========================================================================
// __unwind$494343
// EA  : 0x82BFB3A8
// RVA : 0x00BFB3A8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494343()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1072 + 112));
}


// ========================================================================
// __unwind$494344
// EA  : 0x82BFB3D0
// RVA : 0x00BFB3D0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494344()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1072 + 950));
}


// ========================================================================
// __unwind$494345
// EA  : 0x82BFB3F8
// RVA : 0x00BFB3F8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494345()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1072 + 112));
}


// ========================================================================
// ?UpdateDamageEffects@idAnimatedEntity@@QAAXXZ
// EA  : 0x82BFB428
// RVA : 0x00BFB428
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::UpdateDamageEffects(idAnimatedEntity *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idDamageEffect **p_damageEffects; // r29
  idDamageEffect **p_next; // r30
  idDamageEffect *v6; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v9; // r20
  idDamageEffect *i; // r30
  idPresentable *v11; // r11
  float *v12; // r11
  double v13; // fp11
  double v14; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp31
  double v18; // fp30
  double v19; // fp29
  double v20; // fp0
  double v21; // fp10
  double v22; // fp9
  double y; // fp3
  __int64 v24; // r10
  double x; // fp7
  double v26; // fp7
  double v27; // fp6
  double v28; // fp5
  unsigned int v29; // r7
  double v30; // fp31
  int GameMsPerFrame; // r19
  const idDeclParticle *type; // r18
  int time; // r17
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v35; // r7
  idPLog *pLog; // r29
  idPLog::logEntry_t *v37; // r30
  int v38; // r3
  __int64 totalTicks; // r11
  __int64 v40; // r9
  int v41; // [sp+8h] [-158h]
  int v42; // [sp+Ch] [-154h]
  int v43; // [sp+10h] [-150h]
  int v44; // [sp+14h] [-14Ch]
  int v45; // [sp+18h] [-148h]
  int v46; // [sp+1Ch] [-144h]
  int v47; // [sp+20h] [-140h]
  int v48; // [sp+24h] [-13Ch]
  int v49; // [sp+28h] [-138h]
  int v50; // [sp+2Ch] [-134h]
  int v51; // [sp+30h] [-130h]
  int v52; // [sp+34h] [-12Ch]
  int v53; // [sp+38h] [-128h]
  int v54; // [sp+3Ch] [-124h]
  int v55; // [sp+40h] [-120h]
  int v56; // [sp+44h] [-11Ch]
  int v57; // [sp+48h] [-118h]
  int v58; // [sp+4Ch] [-114h]
  int v59; // [sp+50h] [-110h]
  unsigned int v60[2]; // [sp+60h] [-100h] BYREF
  idPLogScope v61[2]; // [sp+68h] [-F8h] BYREF
  idVec3 v62; // [sp+78h] [-E8h] BYREF
  idMat3 v63; // [sp+88h] [-D8h] BYREF
  float v64; // [sp+ACh] [-B4h]
  float v65; // [sp+B0h] [-B0h]
  float v66; // [sp+B4h] [-ACh]
  float v67; // [sp+B8h] [-A8h]
  float v68; // [sp+BCh] [-A4h]
  float v69; // [sp+C0h] [-A0h]

  RD_EventBegin(name: "idAnimatedEntity::UpdateDamageEffects");
  LODWORD(v2) = "idAnimatedEntity::UpdateDamageEffects";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v61, pl: &::pLog, gMask: v2, label: v3);
  p_damageEffects = &this->damageEffects;
  p_next = &this->damageEffects;
  while ( *p_next != nullptr )
  {
    v6 = *p_next;
    if ( (*p_next)->time != 0 )
    {
      p_next = &v6->next;
    }
    else
    {
      *p_next = v6->next;
      ((void (__fastcall *)(idDamageEffect *, int))v6->dtr_idClass)(a1: v6, a2: 1);
    }
  }
  if ( g_bloodEffects.valueInteger != 0 )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    presentable = this->presentable;
    v9 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v9 != nullptr )
    {
      for ( i = *p_damageEffects; i != nullptr; i = i->next )
      {
        idTreeAnimator::GetModelSpaceJointTransform(
          this: v9,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)i->jointNum.value,
          origin: &v62,
          axis: (idMat3 *)&v63.mat[2]);
        v11 = this->presentable;
        if ( v11 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v11 = this->presentable;
        }
        idMat3::operator*=(this: (idMat3 *)&v63.mat[2], a: &v11->axis);
        v12 = (float *)this->presentable;
        if ( v12 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v12 = (float *)this->presentable;
        }
        v13 = (float)(v12[41] * v62.z);
        v14 = (float)(v12[40] * v62.z);
        v15 = (float)(v12[39] * v62.z);
        v16 = v12[38];
        v60[0] = (unsigned int)(v12 + 33);
        v17 = (float)((float)(v12[35] * v62.x) + (float)((float)((float)v16 * v62.y) + (float)v13));
        v18 = (float)((float)(v12[34] * v62.x) + (float)((float)(v12[37] * v62.y) + (float)v14));
        v19 = (float)((float)(v12[33] * v62.x) + (float)((float)(v12[36] * v62.y) + (float)v15));
        if ( v12 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v12 = (float *)this->presentable;
        }
        v20 = v12[30];
        v60[0] = -1;
        v21 = (float)(v12[32] + (float)v17);
        v22 = (float)(v12[31] + (float)v18);
        v62.z = v12[32] + (float)v17;
        v62.y = v22;
        v62.x = (float)v20 + (float)v19;
        y = i->localOrigin.y;
        HIDWORD(v24) = &i->localOrigin;
        x = i->localOrigin.x;
        v60[1] = (unsigned int)&i->localOrigin;
        v27 = (float)((float)((float)y * v65)
                    + (float)((float)((float)x * v63.mat[2].y) + (float)(i->localOrigin.z * v68)));
        v28 = (float)((float)((float)((float)x * v63.mat[2].x)
                            + (float)((float)(i->localOrigin.z * v67) + (float)((float)y * v64)))
                    + v62.x);
        v26 = (float)((float)((float)y * v66)
                    + (float)((float)((float)x * v63.mat[2].z) + (float)(i->localOrigin.z * v69)));
        v63.mat[0].x = v28;
        v63.mat[0].z = (float)v26 + (float)v21;
        v63.mat[0].y = (float)v27 + (float)v22;
        v29 = 1664525 * clientGame->random.seed;
        clientGame->random.seed = v29 + 1013904223;
        LODWORD(v24) = ((v29 + 1013904223) >> 10) & 0x7FFF;
        v61[1] = (idPLogScope)v24;
        v30 = (float)((float)v24 * (float)0.000030518509);
        GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        type = i->type;
        time = i->time;
        MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
        if ( (unsigned __int8)idRenderModelEffects::AddParticles(
                                this: MergeBranch,
                                particle: type,
                                systemStartTime: time,
                                gameMsPerFrame: GameMsPerFrame,
                                diversity: v30,
                                origin: v35,
                                axis: &v63,
                                velocity: &v63.mat[2],
                                color: &vec3_origin.x,
                                a10: v41,
                                a11: v42,
                                a12: v43,
                                a13: v44,
                                a14: v45,
                                a15: v46,
                                a16: v47,
                                a17: v48,
                                a18: v49,
                                a19: v50,
                                a20: v51,
                                a21: v52,
                                a22: v53,
                                a23: v54,
                                a24: v55,
                                a25: v56,
                                a26: v57,
                                a27: v58,
                                a28: v59,
                                a29: v60) == 0 )
          i->time = 0;
      }
    }
    if ( v61[0].logIndex >= 0 )
    {
      pLog = v61[0].pLog;
      v37 = &v61[0].pLog->logEntries.list[v61[0].logIndex];
      v38 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v37->totalTicks;
      HIDWORD(totalTicks) = v37->parent;
      LODWORD(v40) = v38 - totalTicks;
      v37->totalTicks = v40;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: v61);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$494765
// EA  : 0x82BFB7A8
// RVA : 0x00BFB7A8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494765()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 196));
}


// ========================================================================
// __unwind$494766
// EA  : 0x82BFB7D0
// RVA : 0x00BFB7D0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void _unwind_494766()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 104));
}


// ========================================================================
// ?Think@idAnimatedEntity@@UAAXXZ
// EA  : 0x82BFB7F8
// RVA : 0x00BFB7F8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __fastcall idAnimatedEntity::Think(idAnimatedEntity *this)
{
  idAnimatedEntity::UpdateProxyAnimator(this);
  idAnimatedEntity::UpdateFrameCommands(this);
  idEntity::RunPhysics(this);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  idAnimatedEntity::UpdateDamageEffects(this);
  this->UpdateFX(this);
  idAnimatedEntity::UpdateImpacts(this);
}


// ========================================================================
// `dynamic initializer for 'anim_velocityJoints''
// EA  : 0x83374DC0
// RVA : 0x01374DC0
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_velocityJoints__()
{
  idCVar::idCVar(
    this: &anim_velocityJoints,
    name: "anim_velocityJoints",
    value: "hips",
    flags: 0,
    description: "list of joints to show velocities for",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_velocityJoints__);
}


// ========================================================================
// `dynamic initializer for 'anim_showJointVelocities''
// EA  : 0x83374E18
// RVA : 0x01374E18
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_showJointVelocities__()
{
  idCVar::idCVar(
    this: &anim_showJointVelocities,
    name: "anim_showJointVelocities",
    value: "-1",
    flags: 2,
    description: "number of the entity to show joint velocities for.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_showJointVelocities__);
}


// ========================================================================
// `dynamic initializer for 'anim_fxDeclName''
// EA  : 0x83374E70
// RVA : 0x01374E70
// PDB : w:\tech5\tungsten\game\entities\animatedentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_fxDeclName__()
{
  idCVar::idCVar(
    this: &anim_fxDeclName,
    name: "anim_fxDeclName",
    value: &byte_8200D768,
    flags: 0,
    description: "fxDecl to use when testing in the model editor",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_fxDeclName__);
}

