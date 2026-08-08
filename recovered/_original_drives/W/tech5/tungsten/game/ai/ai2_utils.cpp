
// ========================================================================
// ?CalcTrajectories@idAI2@@QAAXABVidVec3@@0PBV?$idTypesafeNumber@MW4secondUnique_t@@@@HPAVidTrajectory_Parabolic@@_N@Z
// EA  : 0x82A39898
// RVA : 0x00A39898
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

void __fastcall idAI2::CalcTrajectories(
        idAI2 *this,
        const idVec3 *start,
        const idVec3 *dest,
        const idTypesafeNumber<float,enum secondUnique_t> *travelTimes,
        const int numTravelTimes,
        idTrajectory_Parabolic *trajectories,
        const bool deferred)
{
  char v7; // r27
  double v13; // fp31
  double v14; // fp30
  const idTypesafeNumber<float,enum secondUnique_t> *v15; // r29
  idClipModel *v16; // r4

  v7 = (char)this;
  v13 = __fabs(gameLocal->clientGame.gravity.z);
  v14 = (float)((float)__SPAIR64__(&off_82040000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED))
              * (float)0.001);
  if ( numTravelTimes > 0 )
  {
    v15 = travelTimes - 1;
    do
    {
      ++v15;
      idTrajectory_Parabolic::Calc(this: trajectories, start, target: dest, g: v13, t: v15->value);
      idTrajectory_Parabolic::Test(
        this: trajectories,
        timeStep: v14,
        clipModel: v16,
        modelAxis: nullptr,
        clipMask: (const int)&mat3_identity,
        ignoreEnt: (const idEntity *)1,
        deferred: v7);
      --numTravelTimes;
      ++trajectories;
    }
    while ( numTravelTimes != 0 );
  }
}


// ========================================================================
// ?CanThrowGrenade@idAI2@@QBA_NW4aiSelectCondition_t@@@Z
// EA  : 0x82A39980
// RVA : 0x00A39980
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

BOOL __fastcall idAI2::CanThrowGrenade(idAI2 *this, const aiSelectCondition_t condition)
{
  idAI2::aiCondition_t v3; // r11

  return ai_useGrenades.valueInteger != 0
      && ((v3 = this->aiVolatile.groupStatus.condition) & 0x400) != 0
      && (v3 & 8) == 0
      && this->aiEditable.behaviors.decl->itemSelect[condition] != AIITEMSELECT_NONE
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->aiVolatile.memory.nextThrowTime;
}


// ========================================================================
// ?SelectThrowable@idAI2@@QBA_NW4aiItemSelect_t@@ABVidVec3@@W4coverAction_t@@AAVidAIProjectileInfo@@@Z
// EA  : 0x82A39A48
// RVA : 0x00A39A48
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

int __fastcall idAI2::SelectThrowable(
        idAI2 *this,
        aiItemSelect_t selectorType,
        const idVec3 *targetPos,
        coverAction_t coverAction,
        idAIProjectileInfo *info)
{
  double x; // fp10
  double y; // fp9
  double z; // fp11
  idPhysics *Physics; // r3
  float *v12; // r3
  double v13; // fp4
  double v14; // fp2
  double v15; // fp0
  idThrowableSelector *ThrowableSelector; // r3
  idItemSelector *v17; // r29
  const idInventoryCollection *v18; // r3
  idInventoryItem *v20; // [sp+50h] [-50h] BYREF
  float v21; // [sp+60h] [-40h] BYREF
  float v22; // [sp+64h] [-3Ch]
  float v23; // [sp+68h] [-38h]
  float v24; // [sp+6Ch] [-34h]
  float v25; // [sp+70h] [-30h]
  float v26; // [sp+74h] [-2Ch]
  float v27; // [sp+78h] [-28h]

  info->coverAction = coverAction;
  info->predictedTargetPos = *targetPos;
  x = targetPos->x;
  y = targetPos->y;
  z = targetPos->z;
  v24 = 0.0;
  v25 = 0.0;
  v26 = 0.0;
  v27 = 0.0;
  v23 = z;
  v22 = y;
  v21 = x;
  Physics = idEntity::GetPhysics(this);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v13 = (float)(v22 - v12[1]);
  v14 = (float)(v23 - v12[2]);
  v15 = (float)(v21 - *v12);
  v26 = v22 - v12[1];
  v25 = v15;
  v27 = v14;
  v24 = (float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13));
  ThrowableSelector = idGameLocal::GetThrowableSelector(this: gameLocal, selector: selectorType);
  v17 = ThrowableSelector;
  if ( ThrowableSelector == nullptr )
    return 0;
  ThrowableSelector->owner = this;
  ThrowableSelector->target = (const idItemTarget *)&v21;
  v20 = nullptr;
  v18 = this->GetInventory(this);
  idItemSelector::SelectItem(selector: v17, items: &v18->inventory, selectedItem: &v20);
  if ( v20 == nullptr )
    return 0;
  info->itemDecl = v20->decl;
  return 1;
}


// ========================================================================
// ?SelectAmmo@idAI2@@QBA_NW4aiItemSelect_t@@PBVidWeapon@@ABVidVec3@@W4coverAction_t@@AAVidAIProjectileInfo@@@Z
// EA  : 0x82A39B88
// RVA : 0x00A39B88
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

int __fastcall idAI2::SelectAmmo(
        idAI2 *this,
        aiItemSelect_t selectorType,
        const idWeapon *weapon,
        const idVec3 *targetPos,
        coverAction_t coverAction,
        idAIProjectileInfo *info)
{
  double x; // fp10
  double y; // fp9
  double z; // fp11
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp4
  double v16; // fp2
  double v17; // fp0
  idAmmoSelector *AmmoSelector; // r3
  idItemSelector *v19; // r31
  const idInventoryCollection *v20; // r3
  idInventoryItem *v22; // [sp+50h] [-60h] BYREF
  float v23; // [sp+60h] [-50h] BYREF
  float v24; // [sp+64h] [-4Ch]
  float v25; // [sp+68h] [-48h]
  float v26; // [sp+6Ch] [-44h]
  float v27; // [sp+70h] [-40h]
  float v28; // [sp+74h] [-3Ch]
  float v29; // [sp+78h] [-38h]

  info->coverAction = coverAction;
  info->predictedTargetPos = *targetPos;
  x = targetPos->x;
  y = targetPos->y;
  z = targetPos->z;
  v26 = 0.0;
  v27 = 0.0;
  v28 = 0.0;
  v29 = 0.0;
  v25 = z;
  v24 = y;
  v23 = x;
  Physics = idEntity::GetPhysics(this);
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v15 = (float)(v24 - v14[1]);
  v16 = (float)(v25 - v14[2]);
  v17 = (float)(v23 - *v14);
  v28 = v24 - v14[1];
  v27 = v17;
  v29 = v16;
  v26 = (float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15));
  AmmoSelector = idGameLocal::GetAmmoSelector(this: gameLocal, selector: selectorType);
  v19 = AmmoSelector;
  if ( AmmoSelector == nullptr )
    return 0;
  AmmoSelector->owner = this;
  AmmoSelector->weapon = weapon;
  AmmoSelector->target = (const idItemTarget *)&v23;
  v22 = nullptr;
  v20 = this->GetInventory(this);
  idItemSelector::SelectItem(selector: v19, items: &v20->inventory, selectedItem: &v22);
  if ( v22 == nullptr )
    return 0;
  info->itemDecl = v22->decl;
  return 1;
}


// ========================================================================
// ?WaitingOnTrajectoryTest@idAI2@@QBA_NXZ
// EA  : 0x82A39CD0
// RVA : 0x00A39CD0
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

int __fastcall idAI2::WaitingOnTrajectoryTest(idAI2 *this)
{
  int v1; // r30
  idArray<idTrajectory_Parabolic,4> *i; // r31

  v1 = 0;
  for ( i = &this->aiVolatile.trajectories;
        !i->ptr[0].WaitingOnJob(this: i->ptr);
        i = (idArray<idTrajectory_Parabolic,4> *)((char *)i + 380) )
  {
    if ( ++v1 >= 4 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?HasWaitingTrajectoryResults@idAI2@@QBA_NXZ
// EA  : 0x82A39D48
// RVA : 0x00A39D48
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

int __fastcall idAI2::HasWaitingTrajectoryResults(idAI2 *this)
{
  int v1; // r30
  idArray<idTrajectory_Parabolic,4> *i; // r31

  v1 = 0;
  for ( i = &this->aiVolatile.trajectories;
        !i->ptr[0].HasResults(this: i->ptr);
        i = (idArray<idTrajectory_Parabolic,4> *)((char *)i + 380) )
  {
    if ( ++v1 >= 4 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?ClearTrajectoryResults@idAI2@@QAAXXZ
// EA  : 0x82A39DC0
// RVA : 0x00A39DC0
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

void __fastcall idAI2::ClearTrajectoryResults(idAI2 *this)
{
  int v1; // r30
  idArray<idTrajectory_Parabolic,4> *p_trajectories; // r31

  v1 = 4;
  p_trajectories = &this->aiVolatile.trajectories;
  do
  {
    p_trajectories->ptr[0].ClearResults(this: p_trajectories->ptr);
    --v1;
    p_trajectories = (idArray<idTrajectory_Parabolic,4> *)((char *)p_trajectories + 380);
  }
  while ( v1 != 0 );
}


// ========================================================================
// ?GetAnimForOverride@idAI2@@QBAPBVidMD6Anim@@W4overrideAnim_t@@@Z
// EA  : 0x82A39E18
// RVA : 0x00A39E18
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

const idMD6Anim *__fastcall idAI2::GetAnimForOverride(idAI2 *this, overrideAnim_t ot)
{
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v4; // [sp+50h] [-20h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v5[7]; // [sp+52h] [-1Eh] BYREF

  v5[0].value = -1;
  v4.value = -1;
  if ( idAI2::GetAnimWebNodeForOverride(this, ot, swi: v5, si: &v4) )
    return idAI2::GetAnimForAnimWebNode(this, swi: v5, si: &v4);
  else
    return nullptr;
}


// ========================================================================
// ?GetMuzzlePoint@idAI2@@QBA_NPAVidWeapon@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82A39E90
// RVA : 0x00A39E90
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

BOOL __fastcall idAI2::GetMuzzlePoint(idAI2 *this, idWeapon *weapon, idVec3 *muzzlePos, idMat3 *muzzleAxis)
{
  idHandle<int,enum invalidAttachment_t,-1> *v8; // r3
  idAI2 *v9; // r3
  idWeapon::attack_t attackType; // r31
  const idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idAttachmentCollection *v13; // r3
  const idAttachment *v14; // r3
  const idTreeAnimator *v15; // r3
  const idTreeAnimator *v16; // r31
  float *p_x; // r11
  float *p_deferredAxis; // r11
  idAttachmentCollection v19[2]; // [sp+50h] [-30h] BYREF

  v8 = (idHandle<int,enum invalidAttachment_t,-1> *)this->GetAttachments(this);
  idAttachmentCollection::FindAttachment(this: v19, result: v8, item: weapon);
  if ( v19[0].attachments.list == (idAttachment *)-1 )
  {
    v9 = this;
    attackType = weapon->attackType;
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v9);
    return idWeapon::GetMuzzleFlashWorldTransform(
             this: weapon,
             ta: TreeAnimatorFromPresentable,
             attackType,
             origin: muzzlePos,
             axis: muzzleAxis);
  }
  v13 = (idAttachmentCollection *)this->GetAttachments(this);
  v14 = idAttachmentCollection::Get(this: v13, handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v19);
  if ( v14 == nullptr || v14->handle.value == -1 )
    return false;
  if ( v14->presentable == nullptr )
  {
    idLib::Warning(fmt: "GetMuzzlePoint - attachment has no model");
    return false;
  }
  v15 = (const idTreeAnimator *)_RTDynamicCast(
                                  inptr: v14->presentable->model,
                                  VfDelta: 0,
                                  SrcType: &idRenderModel `RTTI Type Descriptor',
                                  TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                  isReference: 0);
  v16 = v15;
  if ( v15 != nullptr
    && !idWeapon::GetMuzzleFlashWorldTransform(
          this: weapon,
          ta: v15,
          attackType: weapon->attackType,
          origin: muzzlePos,
          axis: muzzleAxis) )
  {
    p_x = &v16->deferredOrigin.x;
    if ( !v16->useDeferredPosition )
      p_x = &v16->g.origin.x;
    muzzlePos->x = *p_x;
    muzzlePos->y = p_x[1];
    muzzlePos->z = p_x[2];
    p_deferredAxis = (float *)&v16->deferredAxis;
    if ( !v16->useDeferredPosition )
      p_deferredAxis = (float *)&v16->g.axis;
    muzzleAxis->mat[0].x = *p_deferredAxis;
    muzzleAxis->mat[0].y = p_deferredAxis[1];
    muzzleAxis->mat[0].z = p_deferredAxis[2];
    muzzleAxis->mat[1].x = p_deferredAxis[3];
    muzzleAxis->mat[1].y = p_deferredAxis[4];
    muzzleAxis->mat[1].z = p_deferredAxis[5];
    muzzleAxis->mat[2].x = p_deferredAxis[6];
    muzzleAxis->mat[2].y = p_deferredAxis[7];
    muzzleAxis->mat[2].z = p_deferredAxis[8];
  }
  return true;
}


// ========================================================================
// ?GetLaserSightPoint@idAI2@@QBA_NPAVidWeapon@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82A3A040
// RVA : 0x00A3A040
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

BOOL __fastcall idAI2::GetLaserSightPoint(idAI2 *this, idWeapon *weapon, idVec3 *laserPos, idMat3 *laserAxis)
{
  idHandle<int,enum invalidAttachment_t,-1> *v8; // r3
  const idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idAttachmentCollection *v11; // r3
  const idAttachment *v12; // r3
  const idTreeAnimator *v13; // r3
  const idTreeAnimator *v14; // r31
  float *p_x; // r11
  float *p_deferredAxis; // r11
  idAttachmentCollection v17[2]; // [sp+50h] [-30h] BYREF

  v8 = (idHandle<int,enum invalidAttachment_t,-1> *)this->GetAttachments(this);
  idAttachmentCollection::FindAttachment(this: v17, result: v8, item: weapon);
  if ( v17[0].attachments.list == (idAttachment *)-1 )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    return idWeapon::GetLaserSightWorldTransform(
             this: weapon,
             ta: TreeAnimatorFromPresentable,
             origin: laserPos,
             axis: laserAxis);
  }
  v11 = (idAttachmentCollection *)this->GetAttachments(this);
  v12 = idAttachmentCollection::Get(this: v11, handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v17);
  if ( v12 == nullptr || v12->handle.value == -1 )
    return false;
  if ( v12->presentable == nullptr )
  {
    idLib::Warning(fmt: "GetLaserSightPoint - attachment has no model");
    return false;
  }
  v13 = (const idTreeAnimator *)_RTDynamicCast(
                                  inptr: v12->presentable->model,
                                  VfDelta: 0,
                                  SrcType: &idRenderModel `RTTI Type Descriptor',
                                  TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                  isReference: 0);
  v14 = v13;
  if ( v13 != nullptr
    && !idWeapon::GetLaserSightWorldTransform(this: weapon, ta: v13, origin: laserPos, axis: laserAxis) )
  {
    p_x = &v14->deferredOrigin.x;
    if ( !v14->useDeferredPosition )
      p_x = &v14->g.origin.x;
    laserPos->x = *p_x;
    laserPos->y = p_x[1];
    laserPos->z = p_x[2];
    p_deferredAxis = (float *)&v14->deferredAxis;
    if ( !v14->useDeferredPosition )
      p_deferredAxis = (float *)&v14->g.axis;
    laserAxis->mat[0].x = *p_deferredAxis;
    laserAxis->mat[0].y = p_deferredAxis[1];
    laserAxis->mat[0].z = p_deferredAxis[2];
    laserAxis->mat[1].x = p_deferredAxis[3];
    laserAxis->mat[1].y = p_deferredAxis[4];
    laserAxis->mat[1].z = p_deferredAxis[5];
    laserAxis->mat[2].x = p_deferredAxis[6];
    laserAxis->mat[2].y = p_deferredAxis[7];
    laserAxis->mat[2].z = p_deferredAxis[8];
  }
  return true;
}


// ========================================================================
// ?GetMinMaxRangedAttackDistancesForTargetPos@idAI2@@QBA_NW4aiItemSelect_t@@ABVidVec3@@AAVidAIProjectileInfo@@AAM333@Z
// EA  : 0x82A3A298
// RVA : 0x00A3A298
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAI2::GetMinMaxRangedAttackDistancesForTargetPos(
        idAI2 *this,
        const aiItemSelect_t selector,
        const idVec3 *targetPos,
        idAIProjectileInfo *outProjectileInfo,
        float *outMinRange,
        float *outMinOptimalRange,
        float *outMaxOptimalRange,
        float *outMaxRange)
{
  __int64 v13; // r9
  __int64 v14; // r7
  __int64 v15; // r5
  const idDeclAmmo *v16; // r3
  int v17; // r2 OVERLAPPED
  _DWORD *v18; // r11
  int v19; // r3
  idWeapon *v21; // r3
  float *decl; // r11

  *outMinRange = 0.0;
  *outMinOptimalRange = 0.0;
  *outMaxOptimalRange = 0.0;
  *outMaxRange = 0.0;
  if ( selector == AIITEMSELECT_IMP )
  {
    idAI2::SelectThrowable(
      this,
      selectorType: AIITEMSELECT_IMP,
      targetPos,
      coverAction: COVERACTION_NONE,
      info: outProjectileInfo);
    if ( outProjectileInfo->itemDecl != nullptr )
    {
      v16 = idDeclInfoTemplate<idDeclWeapon>::CastTo(
              this: (idDeclInfoTemplate<idDeclAmmo> *)&idDeclThrowable::resourceList,
              decl: outProjectileInfo->itemDecl);
      if ( v16 != nullptr
        || (v16 = idDeclInfoTemplate<idDeclWeapon>::CastTo(
                    this: &idDeclAmmo::resourceList,
                    decl: outProjectileInfo->itemDecl)) != nullptr )
      {
        v18 = &v16->projectileDecl->__vftable;
        LODWORD(v13) = v18[118];
        *outMinRange = (float)v13;
        LODWORD(v14) = v18[117];
        *outMaxRange = (float)v14;
        LODWORD(v15) = v18[119];
        *outMinOptimalRange = (float)v15;
        v19 = v18[120];
        *outMaxOptimalRange = (float)*(__int64 *)(&v17 - 1);
        return 1;
      }
      return 1;
    }
    return 0;
  }
  v21 = this->GetEquippedWeapon(this);
  if ( v21 == nullptr )
    return 0;
  decl = (float *)v21->decl;
  *outMinRange = decl[147];
  *outMinOptimalRange = decl[146];
  *outMaxOptimalRange = decl[145];
  *outMaxRange = decl[144];
  return 1;
}


// ========================================================================
// ?TestParabolicTrajectories@idAI2@@QAA_NAAVidAIProjectileInfo@@PBVidCachedJoint@@ABVidVec3@@ABVidMat3@@V?$idTypesafeNumber@MW4secondUnique_t@@@@4@Z
// EA  : 0x82A3A4A8
// RVA : 0x00A3A4A8
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

int __fastcall idAI2::TestParabolicTrajectories(
        idAI2 *this,
        idAIProjectileInfo *info,
        const idCachedJoint *cj,
        const idVec3 *origin,
        const idMat3 *axis,
        const idTypesafeNumber<float,enum secondUnique_t> *minTimeSec,
        const idTypesafeNumber<float,enum secondUnique_t> *maxTimeSec)
{
  double value; // fp12
  double v8; // fp10
  idTypesafeNumber<float,enum secondUnique_t> v13[4]; // [sp+60h] [-1C0h] BYREF
  idTrajectory_Parabolic v14; // [sp+70h] [-1B0h] BYREF

  value = minTimeSec->value;
  v8 = (float)(maxTimeSec->value - minTimeSec->value);
  v13[0] = LODWORD(maxTimeSec->value);
  v13[3].value = value;
  v13[1].value = (float)((float)v8 * (float)0.66000003) + (float)value;
  v13[2].value = (float)((float)v8 * (float)0.33000001) + (float)value;
  idTrajectory_Parabolic::idTrajectory_Parabolic(this: &v14);
  idAI2::CalcTrajectories(
    this,
    start: origin,
    dest: &info->predictedTargetPos,
    travelTimes: v13,
    numTravelTimes: 4,
    trajectories: this->aiVolatile.trajectories.ptr,
    deferred: true);
  idTrajectory_Parabolic::~idTrajectory_Parabolic(this: &v14);
  return 1;
}


// ========================================================================
// __unwind$489687
// EA  : 0x82A3A540
// RVA : 0x00A3A540
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

void _unwind_489687()
{
  int v0; // r12

  idTrajectory_Parabolic::~idTrajectory_Parabolic(this: (idTrajectory_Parabolic *)(v0 - 544 + 112));
}


// ========================================================================
// ?TargetMovingPoint@idAI2@@SAXABVidVec3@@M00V?$idTypesafeNumber@MW4secondUnique_t@@@@1AAV2@2@Z
// EA  : 0x82A3A568
// RVA : 0x00A3A568
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

void __fastcall idAI2::TargetMovingPoint(
        const idVec3 *launchPoint,
        double launchSpeed,
        const idVec3 *targetPos,
        const idVec3 *targetVel,
        const idTypesafeNumber<float,enum secondUnique_t> *lagTime,
        const idTypesafeNumber<float,enum secondUnique_t> *animationDelay,
        idVec3 *outLaunchDir,
        idVec3 *outTargetPos,
        float *a9)
{
  double z; // fp10
  double v10; // fp8
  double y; // fp7
  double v12; // fp5
  double v13; // fp11
  double v14; // fp2
  double v15; // fp1
  double v16; // fp13
  double v17; // fp10
  double v18; // fp9
  double x; // fp8
  double v20; // fp6
  double v21; // fp5
  double v22; // fp3
  double v23; // fp1
  double v26; // fp9
  double v27; // fp8
  double v28; // fp1
  double v29; // fp11
  double v30; // fp9

  z = targetVel->z;
  v10 = (float)(targetVel->z - launchPoint->z);
  y = targetVel->y;
  v12 = (float)(targetVel->y - launchPoint->y);
  v13 = __fsqrts((float)((float)((float)v12 * (float)v12)
                       + (float)((float)((float)v10 * (float)v10)
                               + (float)((float)(targetVel->x - launchPoint->x) * (float)(targetVel->x - launchPoint->x)))));
  v14 = (float)(lagTime[1].value
              * (float)((float)((float)((float)v13 / (float)launchSpeed) + outLaunchDir->x) + animationDelay->value));
  v16 = (float)(targetVel->x
              + (float)(lagTime->value
                      * (float)((float)((float)((float)v13 / (float)launchSpeed) + outLaunchDir->x)
                              + animationDelay->value)));
  v15 = (float)(lagTime[2].value
              * (float)((float)((float)((float)v13 / (float)launchSpeed) + outLaunchDir->x) + animationDelay->value));
  *a9 = v16;
  a9[1] = (float)y + (float)v14;
  v17 = (float)((float)z + (float)v15);
  a9[2] = v17;
  v18 = launchPoint->z;
  x = launchPoint->x;
  v20 = (float)((float)((float)y + (float)v14) - launchPoint->y);
  outTargetPos->y = (float)((float)y + (float)v14) - launchPoint->y;
  v21 = (float)((float)v17 - (float)v18);
  outTargetPos->z = (float)v17 - (float)v18;
  v22 = (float)((float)v16 - (float)x);
  outTargetPos->x = (float)v16 - (float)x;
  v23 = (float)((float)((float)((float)v16 - (float)x) * (float)((float)v16 - (float)x))
              + (float)((float)((float)((float)v17 - (float)v18) * (float)((float)v17 - (float)v18))
                      + (float)((float)v20 * (float)v20)));
  _FP11 = (float)((float)((float)((float)((float)v16 - (float)x) * (float)((float)v16 - (float)x))
                        + (float)((float)((float)((float)v17 - (float)v18) * (float)((float)v17 - (float)v18))
                                + (float)((float)v20 * (float)v20)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f11, f1, f13 }
  v26 = (float)((float)v23 * (float)0.5);
  v27 = __frsqrte(_FP10);
  v28 = (float)((float)-(float)((float)((float)((float)v27 * (float)((float)v23 * (float)0.5)) * (float)v27) - (float)1.5)
              * (float)v27);
  v29 = (float)((float)-(float)((float)((float)((float)v28 * (float)v26) * (float)v28) - (float)1.5) * (float)v28);
  v30 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)v26) * (float)v28)
                                                              - (float)1.5)
                                              * (float)v28)
                                      * (float)v26)
                              * (float)((float)-(float)((float)((float)((float)v28 * (float)v26) * (float)v28)
                                                      - (float)1.5)
                                      * (float)v28))
                      - (float)1.5);
  outTargetPos->x = (float)v22 * (float)((float)v30 * (float)v29);
  outTargetPos->y = (float)v20 * (float)((float)v30 * (float)v29);
  outTargetPos->z = (float)v21 * (float)((float)v30 * (float)v29);
}


// ========================================================================
// ?LaunchParabolicProjectile@idAI2@@QAA_NPBVidDeclProjectile@@ABUparabolicParms_t@idTrajectory_Parabolic@@ABVidVec3@@2H@Z
// EA  : 0x82A3A688
// RVA : 0x00A3A688
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

idProjectile *__fastcall idAI2::LaunchParabolicProjectile(
        idAI2 *this,
        const idDeclProjectile *projDecl,
        const idTrajectory_Parabolic::parabolicParms_t *trajectoryParms,
        const idVec3 *targetPos,
        const idVec3 *startPos,
        int startTime)
{
  idProjectile *v11; // r3
  idProjectile *result; // r3
  idProjectile *v13; // r27
  double v14; // fp8
  double v15; // fp5
  double v18; // fp9
  double v19; // fp13
  double v20; // fp10
  double v21; // fp9
  double v22; // fp7
  double speed; // fp1
  __int64 v24; // [sp+50h] [-C0h]
  idAngles v25; // [sp+58h] [-B8h] BYREF
  idVec3 v26[2]; // [sp+68h] [-A8h] BYREF
  idProjectileTarget v27; // [sp+80h] [-90h] BYREF
  idMat3 v28[3]; // [sp+A0h] [-70h] BYREF

  v11 = (idProjectile *)gameLocal->SpawnEntityFromDef(
                          this: gameLocal,
                          a2: projDecl->notHitscanInfo.entityDef,
                          a3: -1,
                          a4: -1,
                          a5: -1);
  result = idProjectile::CastTo(c: v11);
  v13 = result;
  if ( result != nullptr )
  {
    v14 = (float)(targetPos->z - startPos->z);
    v15 = (float)(targetPos->y - startPos->y);
    _FP1 = (float)((float)((float)((float)v15 * (float)v15)
                         + (float)((float)((float)v14 * (float)v14)
                                 + (float)((float)(targetPos->x - startPos->x) * (float)(targetPos->x - startPos->x))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f10, f1, f2, f13 }
    v18 = __frsqrte(_FP10);
    v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                        * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)(targetPos->x - startPos->x) * (float)(targetPos->x - startPos->x))))
                                                                                                * (float)0.5))
                                                                                * (float)v18)
                                                                        - (float)1.5)
                                                        * (float)v18)
                                                * (float)((float)((float)((float)v15 * (float)v15)
                                                                + (float)((float)((float)v14 * (float)v14)
                                                                        + (float)((float)(targetPos->x - startPos->x)
                                                                                * (float)(targetPos->x - startPos->x))))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v18
                                                                                * (float)((float)((float)((float)v15 * (float)v15)
                                                                                                + (float)((float)((float)v14 * (float)v14) + (float)((float)(targetPos->x - startPos->x) * (float)(targetPos->x - startPos->x))))
                                                                                        * (float)0.5))
                                                                        * (float)v18)
                                                                - (float)1.5)
                                                * (float)v18))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v18
                                                        * (float)((float)((float)((float)v15 * (float)v15)
                                                                        + (float)((float)((float)v14 * (float)v14)
                                                                                + (float)((float)(targetPos->x
                                                                                                - startPos->x)
                                                                                        * (float)(targetPos->x
                                                                                                - startPos->x))))
                                                                * (float)0.5))
                                                * (float)v18)
                                        - (float)1.5)
                        * (float)v18));
    v20 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)(targetPos->x - startPos->x) * (float)(targetPos->x - startPos->x)))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                        * (float)v18)
                                                                                * (float)((float)((float)((float)v15 * (float)v15)
                                                                                                + (float)((float)((float)v14 * (float)v14) + (float)((float)(targetPos->x - startPos->x) * (float)(targetPos->x - startPos->x))))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)(targetPos->x - startPos->x) * (float)(targetPos->x - startPos->x)))) * (float)0.5)) * (float)v18)
                                                                                                - (float)1.5)
                                                                                * (float)v18))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v18
                                                                                        * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)(targetPos->x - startPos->x) * (float)(targetPos->x - startPos->x))))
                                                                                                * (float)0.5))
                                                                                * (float)v18)
                                                                        - (float)1.5)
                                                        * (float)v18))
                                        * (float)((float)((float)((float)v15 * (float)v15)
                                                        + (float)((float)((float)v14 * (float)v14)
                                                                + (float)((float)(targetPos->x - startPos->x)
                                                                        * (float)(targetPos->x - startPos->x))))
                                                * (float)0.5))
                                * (float)v19)
                        - (float)1.5);
    v21 = (float)((float)v20
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                                * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)(targetPos->x - startPos->x) * (float)(targetPos->x - startPos->x)))) * (float)0.5))
                                                                                        * (float)v18)
                                                                                - (float)1.5)
                                                                * (float)v18)
                                                        * (float)((float)((float)((float)v15 * (float)v15)
                                                                        + (float)((float)((float)v14 * (float)v14)
                                                                                + (float)((float)(targetPos->x
                                                                                                - startPos->x)
                                                                                        * (float)(targetPos->x
                                                                                                - startPos->x))))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v18
                                                                                        * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)(targetPos->x - startPos->x) * (float)(targetPos->x - startPos->x))))
                                                                                                * (float)0.5))
                                                                                * (float)v18)
                                                                        - (float)1.5)
                                                        * (float)v18))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v18
                                                                * (float)((float)((float)((float)v15 * (float)v15)
                                                                                + (float)((float)((float)v14 * (float)v14)
                                                                                        + (float)((float)(targetPos->x - startPos->x)
                                                                                                * (float)(targetPos->x - startPos->x))))
                                                                        * (float)0.5))
                                                        * (float)v18)
                                                - (float)1.5)
                                * (float)v18)));
    v22 = (float)((float)(targetPos->x - startPos->x) * (float)v21);
    v25.yaw = (float)v21 * (float)(targetPos->y - startPos->y);
    v25.pitch = v22;
    v25.roll = (float)v14 * (float)v21;
    idVec3::ToAngles(this: v26, result: &v25);
    v26[0].x = trajectoryParms->angle;
    idAngles::ToMat3(this: (idAngles *)v28, result: (idMat3 *)v26);
    if ( g_showTrajectories.valueInteger != 0 )
    {
      v24 = __PAIR64__(&off_82040000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
      idTrajectory_Parabolic::Draw(
        color: &idColor::colorGreen,
        start: startPos,
        target: targetPos,
        parms: trajectoryParms,
        timeStep: (float)((float)v24 * (float)0.001),
        duration: (const int)&aAvSsobjectVCom[20],
        depthTest: 136);
    }
    speed = trajectoryParms->speed;
    v27.type = TARGET_NONE;
    v27.presentable.spawnId = 0;
    v27.pos = vec3_origin;
    idProjectile::Launch(
      this: v13,
      attacker_: this,
      start: startPos,
      fireAxis: v28,
      target: &v27,
      initialSpeed: speed,
      startTime: SLODWORD(vec3_origin.y),
      launchTimeOverride: startTime);
    return (idProjectile *)1;
  }
  return result;
}


// ========================================================================
// ?LeadTargetWithLinearProjectile@idAI2@@QBA_NABVidAIProjectileInfo@@ABVidVec3@@11AAV3@2@Z
// EA  : 0x82A3A868
// RVA : 0x00A3A868
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

BOOL __fastcall idAI2::LeadTargetWithLinearProjectile(
        idAI2 *this,
        const idAIProjectileInfo *info,
        const idVec3 *curTargetPos,
        const idTypesafeNumber<float,enum secondUnique_t> *curTargetVel,
        const idVec3 *projStartPos,
        idVec3 *extrapolatedPos,
        idVec3 *dirToExtrapolatedPos)
{
  float y; // r7
  float z; // r11
  float v14; // r5
  float x; // r24
  double v17; // fp11
  float v18; // r11
  double v19; // fp4
  double v20; // fp6
  double v25; // fp1
  double v26; // fp13
  double v27; // fp2
  double v28; // fp6
  double v29; // fp2
  double v30; // fp3
  double v31; // fp1
  double v32; // fp0
  double v33; // fp13
  double v34; // fp12
  BOOL v35; // r28
  const idDeclAIBehavior *decl; // r24
  const idVec3 *v37; // r4
  aiSkill_t ModifiedSkill; // r3
  double speed; // fp1
  const idVec3 *v40; // r5
  double v41; // fp5
  double v42; // fp3
  idTypesafeNumber<float,enum secondUnique_t> v44; // [sp+50h] [-80h] BYREF
  idVec3 v45; // [sp+54h] [-7Ch] BYREF
  float v46; // [sp+60h] [-70h]
  float v47; // [sp+68h] [-68h] BYREF
  float v48; // [sp+6Ch] [-64h]
  float value; // [sp+70h] [-60h]

  y = info->actualTargetVel.y;
  z = info->actualTargetVel.z;
  value = curTargetVel[2].value;
  v45.z = y;
  v14 = curTargetVel->value;
  x = info->actualTargetVel.x;
  v46 = z;
  v17 = z;
  v19 = (float)(z * z);
  v18 = curTargetVel[1].value;
  v47 = v14;
  v45.y = x;
  v48 = v18;
  v20 = (float)((float)(x * x) + (float)((float)(y * y) + (float)v19));
  _FP2 = (float)((float)((float)(x * x) + (float)((float)(y * y) + (float)v19)) - idMath::FLT_SMALLEST_NON_DENORMAL);
  _FP4 = (float)((float)((float)(v14 * v14) + (float)((float)(value * value) + (float)(v18 * v18)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm
  {
    fsel      f1, f4, f1, f13
    fsel      f2, f2, f6, f13
  }
  v25 = __frsqrte(_FP1);
  v26 = __frsqrte(_FP2);
  v27 = (float)((float)-(float)((float)((float)((float)v26 * (float)((float)v20 * (float)0.5)) * (float)v26) - (float)1.5)
              * (float)v26);
  v29 = (float)((float)-(float)((float)((float)((float)v27 * (float)((float)v20 * (float)0.5)) * (float)v27) - (float)1.5)
              * (float)v27);
  v30 = (float)-(float)((float)((float)((float)v29 * (float)((float)v20 * (float)0.5)) * (float)v29) - (float)1.5);
  v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25
                                                                                      * (float)((float)((float)(v14 * v14) + (float)((float)(value * value) + (float)(v18 * v18)))
                                                                                              * (float)0.5))
                                                                              * (float)v25)
                                                                      - (float)1.5)
                                                      * (float)v25)
                                              * (float)((float)((float)(v14 * v14)
                                                              + (float)((float)(value * value) + (float)(v18 * v18)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v25
                                                                              * (float)((float)((float)(v14 * v14)
                                                                                              + (float)((float)(value * value) + (float)(v18 * v18)))
                                                                                      * (float)0.5))
                                                                      * (float)v25)
                                                              - (float)1.5)
                                              * (float)v25))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v25
                                                      * (float)((float)((float)(v14 * v14)
                                                                      + (float)((float)(value * value)
                                                                              + (float)(v18 * v18)))
                                                              * (float)0.5))
                                              * (float)v25)
                                      - (float)1.5)
                      * (float)v25));
  v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v14 * v14) + (float)((float)(value * value) + (float)(v18 * v18))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                              * (float)v25)
                                                                                      * (float)((float)((float)(v14 * v14) + (float)((float)(value * value) + (float)(v18 * v18)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v14 * v14) + (float)((float)(value * value) + (float)(v18 * v18))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                      * (float)v25))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v25
                                                                                              * (float)((float)((float)(v14 * v14) + (float)((float)(value * value) + (float)(v18 * v18))) * (float)0.5))
                                                                                      * (float)v25)
                                                                              - (float)1.5)
                                                              * (float)v25))
                                              * (float)((float)((float)(v14 * v14)
                                                              + (float)((float)(value * value) + (float)(v18 * v18)))
                                                      * (float)0.5))
                                      * (float)v28)
                              - (float)1.5)
              * (float)v28);
  v32 = (float)(y * (float)((float)v30 * (float)v29));
  v33 = (float)((float)v17 * (float)((float)v30 * (float)v29));
  v34 = (float)(x * (float)((float)v30 * (float)v29));
  v35 = (float)((float)((float)(v14 * (float)v31) * (float)(x * (float)((float)v30 * (float)v29)))
              + (float)((float)((float)(value * (float)v31) * (float)((float)v17 * (float)((float)v30 * (float)v29)))
                      + (float)((float)(v18 * (float)v31) * (float)(y * (float)((float)v30 * (float)v29))))) > -0.000000050005699;
  if ( (float)((float)((float)v34 * (float)v34)
             + (float)((float)((float)v32 * (float)v32) + (float)((float)v33 * (float)v33))) < 0.5
    || (float)((float)((float)(v14 * (float)v31) * (float)(v14 * (float)v31))
             + (float)((float)((float)(value * (float)v31) * (float)(value * (float)v31))
                     + (float)((float)(v18 * (float)v31) * (float)(v18 * (float)v31)))) < 0.5 )
  {
    v35 = false;
  }
  decl = this->aiEditable.behaviors.decl;
  ModifiedSkill = idAI2::GetModifiedSkill(this);
  speed = info->linearParms.speed;
  v44.value = decl->throwLag.setting[ModifiedSkill];
  if ( v35 )
  {
    v40 = curTargetPos;
  }
  else
  {
    v40 = (const idVec3 *)&v47;
    v41 = (float)(info->actualTargetPos.z + curTargetPos->z);
    v42 = (float)((float)(info->actualTargetPos.y + curTargetPos->y) * (float)0.5);
    v47 = (float)(curTargetPos->x + info->actualTargetPos.x) * (float)0.5;
    v48 = v42;
    value = (float)v41 * (float)0.5;
  }
  v45.x = 0.0;
  idAI2::TargetMovingPoint(
    launchPoint: projStartPos,
    launchSpeed: speed,
    targetPos: v37,
    targetVel: v40,
    lagTime: curTargetVel,
    animationDelay: &v44,
    outLaunchDir: &v45,
    outTargetPos: dirToExtrapolatedPos,
    a9: &extrapolatedPos->x);
  return v35;
}


// ========================================================================
// ?LaunchLinearProjectile@idAI2@@QAA_NPBVidDeclProjectile@@MABVidVec3@@11H@Z
// EA  : 0x82A3AA88
// RVA : 0x00A3AA88
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

idProjectile *__fastcall idAI2::LaunchLinearProjectile(
        idAI2 *this,
        const idDeclProjectile *projDecl,
        double speed,
        const idVec3 *startPos,
        const idVec3 *targetPos,
        const idVec3 *launchDir,
        idMat3 *startTime,
        int a8)
{
  float x; // r8
  const idDeclEntityDef *entityDef; // r4
  float z; // r10
  idProjectile *v17; // r3
  int v18; // r8
  idProjectile *result; // r3
  idProjectileTarget v20; // [sp+50h] [-80h] BYREF
  idMat3 v21; // [sp+70h] [-60h] BYREF

  idVec3::ToMat3(this: v21.mat, result: startTime);
  x = launchDir->x;
  entityDef = projDecl->notHitscanInfo.entityDef;
  v20.type = TARGET_POINT;
  v20.presentable.spawnId = 0;
  v20.pos.x = x;
  z = launchDir->z;
  v20.pos.y = launchDir->y;
  v20.pos.z = z;
  v17 = (idProjectile *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: entityDef, a3: -1, a4: -1, a5: -1);
  result = idProjectile::CastTo(c: v17);
  if ( result != nullptr )
  {
    idProjectile::Launch(
      this: result,
      attacker_: this,
      start: targetPos,
      fireAxis: &v21,
      target: &v20,
      initialSpeed: speed,
      startTime: v18,
      launchTimeOverride: a8);
    return (idProjectile *)1;
  }
  return result;
}


// ========================================================================
// ?GetModelSpaceJointTransformForAnimEvent@idAI2@@QBAPBVidCachedJoint@@PBVidEventDef@@PBVidMD6Anim@@HAAVidVec3@@AAVidMat3@@AAV?$idTypesafeNumber@HW4millisecondUnique_t@@@@@Z
// EA  : 0x82A3AB60
// RVA : 0x00A3AB60
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

idVehicleState *__fastcall idAI2::GetModelSpaceJointTransformForAnimEvent(
        idAI2 *this,
        const idEventDef *evDef,
        const idMD6Anim *anim,
        int cachedIndex,
        idVec3 *jointOrigin,
        idMat3 *jointAxis,
        idTypesafeNumber<int,enum millisecondUnique_t> *eventTime)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r25
  idPresentable *presentable; // r3
  idDeclMD6 *decl; // r3
  idVehicleState *v18; // r29
  idMD6AnimData *animData; // r11
  __int16 v20; // r4
  signed int frameRate; // r11
  idQuat v22; // [sp+60h] [-B0h] BYREF
  idList<idVehicleState *,5> v23; // [sp+90h] [-80h] BYREF
  int v24; // [sp+A0h] [-70h] BYREF

  if ( anim == nullptr )
    return nullptr;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  decl = TreeAnimatorFromPresentable->decl;
  v23.granularity = 1;
  v23.size = 8;
  v23.num = 0;
  v23.list = (idVehicleState **)&v24;
  v23.memTag = 5;
  v23.listStatic = 1;
  if ( !idDeclMD6::GetCachedJoints(this: decl, eventNum: evDef->eventnum, anim, joints: &v23) )
  {
    idList<idThread *,58>::Clear(this: &v23);
    return nullptr;
  }
  if ( cachedIndex < v23.num )
  {
    v18 = v23.list[cachedIndex];
    jointOrigin->x = *(float *)&v18->listenerList;
    jointOrigin->y = *(float *)&v18->listeningToList;
    jointOrigin->z = *(float *)&v18->stateData;
    *jointAxis = *idQuat::ToMat3(this: &v22, result: (idMat3 *)&v18->childFSMType);
    animData = anim->animData;
    v20 = (__int16)v18->__vftable;
    if ( animData != nullptr )
      frameRate = animData->frameRate;
    else
      frameRate = 30;
    __twllei(frameRate, 0);
    eventTime->value = 960 * v20 / frameRate;
    __twlgei(frameRate & ~(__ROL4__(960 * v20, 1) - 1), 0xFFFFFFFF);
    idList<idThread *,58>::Clear(this: &v23);
    return v18;
  }
  else
  {
    idList<idThread *,58>::Clear(this: &v23);
    return nullptr;
  }
}


// ========================================================================
// __unwind$490220
// EA  : 0x82A3AD24
// RVA : 0x00A3AD24
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

void _unwind_490220()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 144));
}


// ========================================================================
// ?GetWorldSpaceJointTransformForAnimEvent@idAI2@@QBAPBVidCachedJoint@@PBVidEventDef@@PBVidMD6Anim@@HAAVidVec3@@AAVidMat3@@AAV?$idTypesafeNumber@HW4millisecondUnique_t@@@@@Z
// EA  : 0x82A3AD50
// RVA : 0x00A3AD50
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

idVehicleState *__fastcall idAI2::GetWorldSpaceJointTransformForAnimEvent(
        idAI2 *this,
        const idEventDef *evDef,
        const idMD6Anim *anim,
        int cachedIndex,
        idVec3 *worldOrigin,
        idMat3 *worldAxis,
        idTypesafeNumber<int,enum millisecondUnique_t> *eventTime)
{
  idVehicleState *ModelSpaceJointTransformForAnimEvent; // r28
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  char *v12; // r10
  idTreeAnimator *p_z; // r9
  int i; // ctr
  idTreeAnimator *v15; // r3
  float y; // r9
  double x; // fp13
  float z; // r11
  double v19; // fp8
  double v20; // fp3
  double v21; // fp2
  double v22; // fp1
  double v23; // fp0
  idVec3 v25; // [sp+50h] [-C0h] BYREF
  char v26; // [sp+5Ch] [-B4h] BYREF
  idMat3 v27; // [sp+60h] [-B0h] BYREF
  idMat3 v28; // [sp+90h] [-80h] BYREF
  idMat3 v29[2]; // [sp+C0h] [-50h] BYREF

  ModelSpaceJointTransformForAnimEvent = idAI2::GetModelSpaceJointTransformForAnimEvent(
                                           this,
                                           evDef,
                                           anim,
                                           cachedIndex,
                                           jointOrigin: &v25,
                                           jointAxis: &v28,
                                           eventTime);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v12 = &v26;
  p_z = (idTreeAnimator *)&TreeAnimatorFromPresentable->g.origin.z;
  for ( i = 9; i != 0; --i )
  {
    p_z = (idTreeAnimator *)((char *)p_z + 4);
    v12 += 4;
    *(_DWORD *)v12 = p_z->__vftable;
  }
  v15 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  y = v15->g.origin.y;
  x = v25.x;
  z = v15->g.origin.z;
  v19 = (float)(v27.mat[0].y * v25.x);
  v25.x = v15->g.origin.x;
  v20 = v25.x;
  v21 = (float)((float)(v27.mat[0].x * (float)x) + (float)((float)(v27.mat[1].x * v25.y) + (float)(v27.mat[2].x * v25.z)));
  v22 = (float)((float)(v27.mat[2].y * v25.z) + (float)((float)(v27.mat[1].y * v25.y) + (float)v19));
  v23 = (float)((float)(v27.mat[2].z * v25.z) + (float)((float)(v27.mat[1].z * v25.y) + (float)(v27.mat[0].z * (float)x)));
  v25.z = z;
  v25.y = y;
  worldOrigin->z = z + (float)v23;
  worldOrigin->y = y + (float)v22;
  worldOrigin->x = (float)v21 + (float)v20;
  *worldAxis = *idMat3::operator*(this: v29, result: &v27, a: &v28);
  return ModelSpaceJointTransformForAnimEvent;
}


// ========================================================================
// ?GetCachedMuzzlePointForAnimEvent@idAI2@@QBAPBVidCachedJoint@@PBVidEventDef@@PAVidWeapon@@PBVidMD6Anim@@AAVidVec3@@AAVidMat3@@AAV?$idTypesafeNumber@HW4millisecondUnique_t@@@@@Z
// EA  : 0x82A3AEA0
// RVA : 0x00A3AEA0
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

idVehicleState *__fastcall idAI2::GetCachedMuzzlePointForAnimEvent(
        idAI2 *this,
        const idEventDef *evDef,
        idWeapon *weapon,
        const idMD6Anim *anim,
        idVec3 *muzzlePos,
        idMat3 *muzzleAxis,
        idTypesafeNumber<int,enum millisecondUnique_t> *eventTime)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v16; // r29
  idVehicleState *ModelSpaceJointTransformForAnimEvent; // r23
  idHandle<int,enum invalidAttachment_t,-1> *v19; // r3
  idAttachmentCollection *v20; // r3
  const idAttachment *v21; // r3
  const idTreeAnimator *v22; // r4
  double x; // fp9
  double y; // fp6
  double v25; // fp3
  double v26; // fp2
  idMat3 *v27; // r3
  double v28; // fp0
  double z; // fp12
  double v30; // fp7
  double v31; // fp6
  idAttachmentCollection v32; // [sp+50h] [-130h] BYREF
  float v33; // [sp+64h] [-11Ch]
  float v34; // [sp+68h] [-118h]
  idMat3 v35; // [sp+6Ch] [-114h] BYREF
  idMat3 v36; // [sp+90h] [-F0h] BYREF
  idQuat v37; // [sp+C0h] [-C0h] BYREF
  idMat3 v38[4]; // [sp+F0h] [-90h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v16 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  muzzlePos->x = v16->g.origin.x;
  muzzlePos->y = v16->g.origin.y;
  muzzlePos->z = v16->g.origin.z;
  muzzleAxis->mat[0].x = v16->g.axis.mat[0].x;
  muzzleAxis->mat[0].y = v16->g.axis.mat[0].y;
  muzzleAxis->mat[0].z = v16->g.axis.mat[0].z;
  muzzleAxis->mat[1].x = v16->g.axis.mat[1].x;
  muzzleAxis->mat[1].y = v16->g.axis.mat[1].y;
  muzzleAxis->mat[1].z = v16->g.axis.mat[1].z;
  muzzleAxis->mat[2].x = v16->g.axis.mat[2].x;
  muzzleAxis->mat[2].y = v16->g.axis.mat[2].y;
  muzzleAxis->mat[2].z = v16->g.axis.mat[2].z;
  if ( anim == nullptr )
    return nullptr;
  ModelSpaceJointTransformForAnimEvent = idAI2::GetModelSpaceJointTransformForAnimEvent(
                                           this,
                                           evDef,
                                           anim,
                                           cachedIndex: 0,
                                           jointOrigin: (idVec3 *)&v35.mat[1].z,
                                           jointAxis: &v36,
                                           eventTime);
  if ( ModelSpaceJointTransformForAnimEvent == nullptr )
    return nullptr;
  v19 = (idHandle<int,enum invalidAttachment_t,-1> *)this->GetAttachments(this);
  idAttachmentCollection::FindAttachment(this: &v32, result: v19, item: weapon);
  if ( v32.attachments.list == (idAttachment *)-1
    || (v20 = (idAttachmentCollection *)this->GetAttachments(this),
        (v21 = idAttachmentCollection::Get(this: v20, handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v32)) == nullptr)
    || v21->handle.value == -1
    || v21->presentable == nullptr
    || (v22 = (const idTreeAnimator *)_RTDynamicCast(
                                        inptr: v21->presentable->model,
                                        VfDelta: 0,
                                        SrcType: &idRenderModel `RTTI Type Descriptor',
                                        TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                        isReference: 0)) == nullptr )
  {
    v22 = v16;
  }
  HIWORD(v35.mat[1].y) = -1;
  *(float *)&v32.parent = 0.0;
  v33 = 0.0;
  v34 = 0.0;
  v35.mat[0].x = 0.0;
  v35.mat[0].y = 0.0;
  v35.mat[0].z = 0.0;
  v35.mat[1].x = 0.0;
  if ( !idWeapon::GetMuzzleFlashTagData(
          this: weapon,
          ta: v22,
          attackType: ATTACK_DEFAULT,
          tagData: (tagData_t *)&v32.parent) )
    return nullptr;
  x = v35.mat[2].x;
  y = v35.mat[2].y;
  v25 = (float)((float)(v36.mat[2].y * v34)
              + (float)((float)(v36.mat[0].y * *(float *)&v32.parent) + (float)(v36.mat[1].y * v33)));
  v26 = (float)((float)(v36.mat[0].z * *(float *)&v32.parent)
              + (float)((float)(v36.mat[1].z * v33) + (float)(v36.mat[2].z * v34)));
  muzzlePos->x = (float)((float)(v36.mat[0].x * *(float *)&v32.parent)
                       + (float)((float)(v36.mat[1].x * v33) + (float)(v36.mat[2].x * v34)))
               + v35.mat[1].z;
  muzzlePos->y = (float)x + (float)v25;
  muzzlePos->z = (float)y + (float)v26;
  v27 = idQuat::ToMat3(this: &v37, result: &v35);
  *muzzleAxis = *idMat3::operator*(this: v38, result: v27, a: &v36);
  v28 = v16->g.origin.y;
  z = v16->g.origin.z;
  v30 = (float)((float)(muzzlePos->x * v16->g.axis.mat[0].y)
              + (float)((float)(v16->g.axis.mat[1].y * muzzlePos->y) + (float)(v16->g.axis.mat[2].y * muzzlePos->z)));
  v31 = (float)((float)(muzzlePos->x * v16->g.axis.mat[0].z)
              + (float)((float)(v16->g.axis.mat[1].z * muzzlePos->y) + (float)(v16->g.axis.mat[2].z * muzzlePos->z)));
  muzzlePos->x = (float)((float)(muzzlePos->x * v16->g.axis.mat[0].x)
                       + (float)((float)(v16->g.axis.mat[1].x * muzzlePos->y)
                               + (float)(v16->g.axis.mat[2].x * muzzlePos->z)))
               + v16->g.origin.x;
  muzzlePos->y = (float)v28 + (float)v30;
  muzzlePos->z = (float)z + (float)v31;
  idMat3::operator*=(this: muzzleAxis, a: &v16->g.axis);
  return ModelSpaceJointTransformForAnimEvent;
}


// ========================================================================
// ?LaunchProjectile@idAI2@@QAA_NPBVidEntity@@ABVaiSenseState_t@@AAVidAIProjectileInfo@@ABW4aiItemSelect_t@@@Z
// EA  : 0x82A3B1F8
// RVA : 0x00A3B1F8
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

int __fastcall idAI2::LaunchProjectile(
        idAI2 *this,
        const idEntity *target,
        aiSenseState_t *senseState,
        idAIProjectileInfo *projectileInfo,
        aiItemSelect_t *itemSelect)
{
  const idDeclAIBehavior *decl; // r22
  idWeapon *EquippedWeapon; // r3
  idWeapon *v12; // r30
  const idDeclProjectile *projectileDecl; // r27
  overrideAnim_t v14; // r11
  idPhysics *Physics; // r3
  const idDeclAIBehavior *v16; // r28
  float *v17; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  const idDeclAmmo *v19; // r3
  const idMD6Anim *AnimForOverride; // r3
  const idCachedJoint *CachedMuzzlePointForAnimEvent; // r28
  const idMD6Anim *v22; // r3
  idInventoryItem *v23; // r3
  idInventoryItem *v24; // r30
  const aiPhysicalState_t *v25; // r3
  const idDeclInventory *itemDecl; // r30
  int v27; // r6
  const idDeclAmmo *v28; // r3
  const idMD6Anim *v29; // r3
  idVec3 *v31; // r4
  double minTrajectoryTime; // fp13
  __int64 v33; // r10
  idVec3 *p_velocity; // r30
  const aiPhysicalState_t *v35; // r3
  const idVec3 *v36; // r4
  double v37; // fp8
  idTypesafeNumber<int,enum millisecondUnique_t> v38[2]; // [sp+50h] [-C0h] BYREF
  __int64 v39; // [sp+58h] [-B8h] BYREF
  idVec3 v40; // [sp+60h] [-B0h] BYREF
  float v41[4]; // [sp+70h] [-A0h] BYREF
  idVec3 v42; // [sp+80h] [-90h] BYREF
  idMat3 v43[3]; // [sp+90h] [-80h] BYREF

  decl = this->aiEditable.behaviors.decl;
  EquippedWeapon = idActor::GetEquippedWeapon(this, slot: EQUIP_RIGHT_HAND);
  projectileInfo->itemDecl = nullptr;
  v12 = EquippedWeapon;
  projectileInfo->coverAction = COVERACTION_NONE;
  projectileInfo->overrideAnim = ANIMOVERRIDE_THROW_PROJECTILE;
  projectileDecl = nullptr;
  if ( idActor::IsCrouching(this) )
  {
    v14 = ANIMOVERRIDE_CROUCHED_THROW_PROJECTILE;
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    v16 = this->aiEditable.behaviors.decl;
    v17 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)v41, result: (idVec3 *)Physics, a3: 0);
    if ( (float)((float)(*v17 * this->actorVolatile.modelInfo.modelAxis.mat[0].x)
               + (float)((float)(v17[2] * this->actorVolatile.modelInfo.modelAxis.mat[0].z)
                       + (float)(v17[1] * this->actorVolatile.modelInfo.modelAxis.mat[0].y))) <= (double)v16->damageBehaviors.movingDeathSpeed )
      goto LABEL_6;
    v14 = ANIMOVERRIDE_MOVING_THROW_PROJECTILE;
  }
  projectileInfo->overrideAnim = v14;
LABEL_6:
  if ( v12 != nullptr )
  {
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: senseState);
    idAI2::SelectAmmo(
      this,
      selectorType: *itemSelect,
      weapon: v12,
      targetPos: &ConfirmedPhysicalSafe->origin,
      coverAction: COVERACTION_NONE,
      info: projectileInfo);
    if ( projectileInfo->itemDecl != nullptr )
    {
      v19 = idDeclInfoTemplate<idDeclWeapon>::CastTo(this: &idDeclAmmo::resourceList, decl: projectileInfo->itemDecl);
      if ( v19 != nullptr )
        projectileDecl = v19->projectileDecl;
      else
        projectileDecl = nullptr;
      AnimForOverride = idAI2::GetAnimForOverride(this, ot: projectileInfo->overrideAnim);
      CachedMuzzlePointForAnimEvent = (const idCachedJoint *)idAI2::GetCachedMuzzlePointForAnimEvent(
                                                               this,
                                                               evDef: &AE_LaunchItem,
                                                               weapon: v12,
                                                               anim: AnimForOverride,
                                                               muzzlePos: &v40,
                                                               muzzleAxis: v43,
                                                               eventTime: v38);
      if ( CachedMuzzlePointForAnimEvent == nullptr )
      {
        v22 = idAI2::GetAnimForOverride(this, ot: projectileInfo->overrideAnim);
        CachedMuzzlePointForAnimEvent = (const idCachedJoint *)idAI2::GetCachedMuzzlePointForAnimEvent(
                                                                 this,
                                                                 evDef: &AE_LaunchItemFromWeapon,
                                                                 weapon: v12,
                                                                 anim: v22,
                                                                 muzzlePos: &v40,
                                                                 muzzleAxis: v43,
                                                                 eventTime: v38);
      }
      if ( *itemSelect != AIITEMSELECT_CLUB_MUTANT )
        projectileInfo->useMuzzleForLaunch = true;
      goto LABEL_24;
    }
    return 0;
  }
  v23 = this->GetEquipped(this, a2: 2);
  v24 = v23;
  if ( v23 != nullptr && v23->decl->GetDeclInfo(this: v23->decl) == &idDeclThrowable::resourceList )
  {
    projectileInfo->itemDecl = v24->decl;
  }
  else
  {
    v25 = aiSenseState_t::GetConfirmedPhysicalSafe(this: senseState);
    idAI2::SelectThrowable(
      this,
      selectorType: *itemSelect,
      targetPos: &v25->origin,
      coverAction: COVERACTION_NONE,
      info: projectileInfo);
    if ( projectileInfo->itemDecl == nullptr )
      return 0;
  }
  itemDecl = projectileInfo->itemDecl;
  v27 = (&idDeclThrowable::resourceList != projectileInfo->itemDecl->GetDeclInfo(this: projectileInfo->itemDecl)) - 1;
  if ( (v27 & (unsigned int)itemDecl) != 0 )
  {
    projectileDecl = *(const idDeclProjectile **)((v27 & (unsigned int)itemDecl) + 0x1F8);
  }
  else
  {
    v28 = idDeclInfoTemplate<idDeclWeapon>::CastTo(this: &idDeclAmmo::resourceList, decl: projectileInfo->itemDecl);
    if ( v28 != nullptr )
      projectileDecl = v28->projectileDecl;
  }
  v29 = idAI2::GetAnimForOverride(this, ot: projectileInfo->overrideAnim);
  CachedMuzzlePointForAnimEvent = (const idCachedJoint *)idAI2::GetWorldSpaceJointTransformForAnimEvent(
                                                           this,
                                                           evDef: &AE_LaunchItem,
                                                           anim: v29,
                                                           cachedIndex: 0,
                                                           worldOrigin: &v40,
                                                           worldAxis: v43,
                                                           eventTime: v38);
LABEL_24:
  if ( projectileInfo->itemDecl == nullptr || projectileDecl == nullptr )
    return 0;
  if ( CachedMuzzlePointForAnimEvent == nullptr )
  {
    idLib::Warning(fmt: "idAI2::LaunchProjectile - can't find cached joint for %s", this->name.data);
    return 0;
  }
  if ( target != nullptr )
    projectileInfo->target.spawnId.value = (gameLocal->spawnIds.ptr[target->entityNumber] << 13) | target->entityNumber;
  else
    projectileInfo->target.spawnId.value = 0x1FFF;
  projectileInfo->coverAction = COVERACTION_NONE;
  projectileInfo->actualTargetPos = aiSenseState_t::GetConfirmedPhysicalSafe(this: senseState)->eyePos;
  projectileInfo->actualTargetVel = aiSenseState_t::GetConfirmedPhysicalSafe(this: senseState)->velocity;
  projectileInfo->jointIndex.value = CachedMuzzlePointForAnimEvent->jointIndex.value;
  projectileInfo->nodeIndex.value = -1;
  if ( projectileDecl->notHitscanInfo.parabolicFlight )
  {
    projectileInfo->predictedTargetPos.x = projectileInfo->actualTargetPos.x;
    projectileInfo->predictedTargetPos.y = projectileInfo->actualTargetPos.y;
    projectileInfo->predictedTargetPos.z = projectileInfo->actualTargetPos.z;
    if ( *itemSelect == AIITEMSELECT_SCOOP_MUTANT )
      aiSenseState_t::ExtrapolatePosition(this: senseState, seconds: 1.0, futurePos: v31);
    minTrajectoryTime = projectileDecl->notHitscanInfo.minTrajectoryTime;
    v38[0] = LODWORD(projectileDecl->notHitscanInfo.maxTrajectoryTime);
    *(float *)&v39 = minTrajectoryTime;
    if ( (unsigned __int8)idAI2::TestParabolicTrajectories(
                            this,
                            info: projectileInfo,
                            cj: CachedMuzzlePointForAnimEvent,
                            origin: &v40,
                            axis: v43,
                            minTimeSec: (const idTypesafeNumber<float,enum secondUnique_t> *)&v39,
                            maxTimeSec: (const idTypesafeNumber<float,enum secondUnique_t> *)v38) == 0 )
      return 0;
  }
  else
  {
    HIDWORD(v33) = idAI2::GetModifiedSkill(this) + 54;
    LODWORD(v33) = v38[0];
    v39 = v33;
    *(float *)&v39 = *((float *)&decl->__vftable + HIDWORD(v33));
    *(float *)&v38[0].value = (float)v33 * (float)0.001;
    p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: senseState)->velocity;
    v35 = aiSenseState_t::GetConfirmedPhysicalSafe(this: senseState);
    idAI2::TargetMovingPoint(
      launchPoint: &v40,
      launchSpeed: projectileDecl->notHitscanInfo.speed,
      targetPos: v36,
      targetVel: &v35->eyePos,
      lagTime: (const idTypesafeNumber<float,enum secondUnique_t> *)p_velocity,
      animationDelay: (const idTypesafeNumber<float,enum secondUnique_t> *)&v39,
      outLaunchDir: (idVec3 *)v38,
      outTargetPos: &v42,
      a9: v41);
    projectileInfo->predictedTargetPos.z = v41[2];
    v37 = v41[1];
    projectileInfo->predictedTargetPos.x = v41[0];
    projectileInfo->predictedTargetPos.y = v37;
    projectileInfo->linearParms.speed = projectileDecl->notHitscanInfo.speed;
    projectileInfo->linearParms.time = 0.0;
    projectileInfo->linearParms.gravity = 0.0;
  }
  idAIProjectileInfo::operator=(this: &this->aiVolatile.memory.projectileInfo, __that: projectileInfo);
  return 1;
}


// ========================================================================
// ?CheckGrenadeThrow@idAI2@@QAA_NAAVidAIProjectileInfo@@@Z
// EA  : 0x82A3B758
// RVA : 0x00A3B758
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

int __fastcall idAI2::CheckGrenadeThrow(idAI2 *this, idAIProjectileInfo *info)
{
  int v4; // r29
  coverAction_t coverAction; // r6
  const idMD6Anim *AnimForAnimWebNode; // r3
  idVehicleState *WorldSpaceJointTransformForAnimEvent; // r3
  const idCachedJoint *v8; // r26
  __int16 v9; // r11
  const idDeclInventory *itemDecl; // r3
  idEncounterGroup *EncounterGroup; // r3
  int v13; // r30
  idPhysics *Physics; // r3
  idBounds *v15; // r3
  idDeclInventory_vtbl *v16; // r10
  double v17; // fp13
  int v18; // r30
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v19; // [sp+50h] [-1A0h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v20; // [sp+52h] [-19Eh] BYREF
  idTypesafeNumber<int,enum millisecondUnique_t> v21; // [sp+54h] [-19Ch] BYREF
  idTypesafeNumber<float,enum secondUnique_t> v22; // [sp+58h] [-198h] BYREF
  idVec3 v23; // [sp+60h] [-190h] BYREF
  idMat3 v24; // [sp+70h] [-180h] BYREF
  idStaticList<idAI2 *,64> v25; // [sp+A0h] [-150h] BYREF

  v4 = 0;
  if ( info->itemDecl == nullptr )
    return 0;
  coverAction = info->coverAction;
  v20.value = -1;
  v19.value = -1;
  if ( !idAI2::GetAnimWebGrenadeThrowNode(
          this,
          web: AIANIMWEB_BODY,
          subWeb: (const aiSubWeb_t)this->aiVolatile.animation.subWeb,
          coverAction,
          swi: &v20,
          si: &v19,
          nodeIndex: &info->nodeIndex) )
    return 0;
  AnimForAnimWebNode = idAI2::GetAnimForAnimWebNode(this, swi: &v20, si: &v19);
  WorldSpaceJointTransformForAnimEvent = idAI2::GetWorldSpaceJointTransformForAnimEvent(
                                           this,
                                           evDef: &AE_ThrowGrenade,
                                           anim: AnimForAnimWebNode,
                                           cachedIndex: 0,
                                           worldOrigin: &v23,
                                           worldAxis: &v24,
                                           eventTime: &v21);
  v8 = (const idCachedJoint *)WorldSpaceJointTransformForAnimEvent;
  if ( WorldSpaceJointTransformForAnimEvent == nullptr )
    return 0;
  v9 = HIWORD(WorldSpaceJointTransformForAnimEvent->__vftable);
  itemDecl = info->itemDecl;
  info->jointIndex.value = v9;
  if ( itemDecl->GetDeclInfo(this: itemDecl) != &idDeclThrowable::resourceList )
  {
    idLib::Warning(
      fmt: "AI '%s' attempted to throw a non-throwable item '%s'",
      this->name.data,
      info->itemDecl->name.str);
    return 0;
  }
  v25.num = 0;
  v25.granularity = 1;
  v25.size = 64;
  v25.list = v25.staticList;
  v25.memTag = 5;
  v25.listStatic = 1;
  if ( idAI2::GetEncounterGroup(this) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this);
    idEncounterGroup::GetLivingMembers(this: EncounterGroup, list: &v25);
  }
  if ( v25.num <= 0 )
  {
LABEL_13:
    v16 = info->itemDecl[1].__vftable;
    v17 = *(float *)&v16[6].RebuildTextSource;
    *(bool (__fastcall **)(struct idDeclInventory *))&v22.value = v16[6].SetImplicitText;
    *(float *)&v21.value = v17;
    v18 = idAI2::TestParabolicTrajectories(
            this,
            info,
            cj: v8,
            origin: &v23,
            axis: &v24,
            minTimeSec: (const idTypesafeNumber<float,enum secondUnique_t> *)&v21,
            maxTimeSec: &v22);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v25);
    return v18;
  }
  else
  {
    v13 = 0;
    while ( 1 )
    {
      v21.value = (int)&v25.list[v13];
      Physics = idEntity::GetPhysics(this: v25.list[v13]);
      v15 = (idBounds *)Physics->GetAbsBounds(this: Physics, a2: -1);
      if ( (unsigned __int8)idBounds::ContainsPoint(this: v15, p: &v23) != 0 )
        break;
      ++v4;
      ++v13;
      if ( v4 >= v25.num )
        goto LABEL_13;
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v25);
    return 0;
  }
}


// ========================================================================
// __unwind$490896
// EA  : 0x82A3B980
// RVA : 0x00A3B980
// PDB : w:\tech5\tungsten\game\ai\ai2_utils.cpp
// ========================================================================

void _unwind_490896()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 160));
}

