
// ========================================================================
// ?Hide@idDoor_Parametric@@UAAXXZ
// EA  : 0x82C24870
// RVA : 0x00C24870
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::Hide(idDoor_Parametric *this)
{
  idPhysics *Physics; // r3

  idEntity::Hide(this);
  idEntity::BecomeInactive(this, flags: 7);
  Physics = idEntity::GetPhysics(this);
  Physics->UnlinkClip(this: Physics);
}


// ========================================================================
// ?Show@idDoor_Parametric@@UAAXXZ
// EA  : 0x82C248C0
// RVA : 0x00C248C0
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::Show(idDoor_Parametric *this)
{
  idPhysics *Physics; // r3

  idEntity::Show(this);
  Physics = idEntity::GetPhysics(this);
  Physics->LinkClip(this: Physics);
}


// ========================================================================
// ?SetLocked@idDoor_Parametric@@UAAX_NPAVidEntity@@@Z
// EA  : 0x82C24908
// RVA : 0x00C24908
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::SetLocked(idDoor_Parametric *this, bool lock, idEntity *user)
{
  this->locked = lock;
  if ( !lock && this->IsClosed(this) && this->opensWhenUnlocked )
    this->Use(this, a2: user, a3: USABLE_DOOR);
  this->UpdateAASAreas(this);
}


// ========================================================================
// ?IsLockedForEntity@idDoor_Parametric@@UBA_NPBVidEntity@@M@Z
// EA  : 0x82C249A8
// RVA : 0x00C249A8
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

BOOL __fastcall idDoor_Parametric::IsLockedForEntity(idDoor_Parametric *this, idAI2 *ent, double kicked)
{
  return (kicked == 0.0 || !this->kickUnlocks || idAI2::CastTo(c: ent) == nullptr)
      && idDoor_Base::IsLockedForEntity(this, ent, kicked);
}


// ========================================================================
// ?Event_IsOpen@idDoor_Parametric@@AAA?AVeventBool@@XZ
// EA  : 0x82C24A30
// RVA : 0x00C24A30
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idDoor_Parametric *__fastcall idDoor_Parametric::Event_IsOpen(idDoor_Parametric *this, eventBool *result)
{
  char v3; // r3

  v3 = (*(int (__fastcall **)(eventBool *))(*(_DWORD *)&result->value + 672))(a1: result);
  eventBool::eventBool((eventBool *)this, b: v3);
  return this;
}


// ========================================================================
// ?Event_IsClosed@idDoor_Parametric@@AAA?AVeventBool@@XZ
// EA  : 0x82C24A80
// RVA : 0x00C24A80
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idDoor_Parametric *__fastcall idDoor_Parametric::Event_IsClosed(idDoor_Parametric *this, eventBool *result)
{
  char v3; // r3

  v3 = (*(int (__fastcall **)(eventBool *))(*(_DWORD *)&result->value + 676))(a1: result);
  eventBool::eventBool((eventBool *)this, b: v3);
  return this;
}


// ========================================================================
// ?Event_IsLockedForEntity@idDoor_Parametric@@AAA?AVeventBool@@PAVidEntity@@@Z
// EA  : 0x82C24AD0
// RVA : 0x00C24AD0
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idDoor_Parametric *__fastcall idDoor_Parametric::Event_IsLockedForEntity(
        idDoor_Parametric *this,
        eventBool *result,
        idActor *entity)
{
  idActor *v5; // r4

  v5 = idActor::CastTo(c: entity);
  if ( v5 != nullptr )
    LOBYTE(v5) = (*(int (__fastcall **)(eventBool *, idActor *, double))(*(_DWORD *)&result->value + 684))(
                   a1: result,
                   a2: v5,
                   a3: 0.0);
  eventBool::eventBool((eventBool *)this, b: (const bool)v5);
  return this;
}


// ========================================================================
// ?Event_GetCenterOfDoor@idDoor_Parametric@@AAA?AVeventVector@@XZ
// EA  : 0x82C24B48
// RVA : 0x00C24B48
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idDoor_Parametric *__fastcall idDoor_Parametric::Event_GetCenterOfDoor(idDoor_Parametric *this, eventVector *result)
{
  eventVector::eventVector((eventVector *)this, v: (const idVec3 *)&result[605].value.y);
  return this;
}


// ========================================================================
// ?AllocPresentable@idDoor_Parametric@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C24B88
// RVA : 0x00C24B88
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idPresentableAnimatedEntity *__fastcall idDoor_Parametric::AllocPresentable(
        idDoor_Parametric *this,
        idTreeAnimator *renderModel_)
{
  idPresentableAnimatedEntity *v4; // r29
  idAnimStack *v5; // r3

  v4 = (idPresentableAnimatedEntity *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x4E0u,
                                        tag: TAG_PRESENTABLE,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    return nullptr;
  v5 = this->GetAnimStack_2(this);
  return idPresentableAnimatedEntity::idPresentableAnimatedEntity(
           this: v4,
           ent: this,
           renderModel_,
           animStack_: v5,
           entityNumber_: 0x1FFF,
           fxDecl_: nullptr,
           useSphereModel_: false);
}


// ========================================================================
// __unwind$488901
// EA  : 0x82C24C1C
// RVA : 0x00C24C1C
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_488901()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?AutoClose@idDoor_Parametric@@AAAXXZ
// EA  : 0x82C24C48
// RVA : 0x00C24C48
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::AutoClose(idDoor_Parametric *this)
{
  idDoor_Parametric_vtbl *v2; // r10

  if ( this->state != DOOR_BROKEN && this->autoCloseTime != 0 && this->close_time > 0 )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->autoCloseTime <= this->close_time )
    {
      if ( !this->CanClose(this, a2: false) )
        this->autoCloseTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    }
    else
    {
      v2 = this->__vftable;
      this->autoCloseTime = 0;
      v2->Use(this, a2: this, a3: USABLE_DOOR);
    }
  }
}


// ========================================================================
// ?Unlock@idDoor_Parametric@@AAA_NPAVidActor@@M@Z
// EA  : 0x82C24D18
// RVA : 0x00C24D18
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

int __fastcall idDoor_Parametric::Unlock(idDoor_Parametric *this, idActor *user, double kicked)
{
  const idSoundShader *unlock_sound; // r5
  idPresentable *presentable; // r29
  const idDeclInventory *requiredKey; // r31
  idInventoryCollection *v10; // r3

  if ( ((unsigned __int8 (__fastcall *)(idDoor_Parametric *))this->IsLockedForEntity)(a1: this) != 0 )
  {
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BODY,
      shader: this->locked_sound,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
    return 0;
  }
  else
  {
    this->SetLocked(this, a2: false, a3: user);
    if ( kicked == 0.0 )
      unlock_sound = this->unlock_sound;
    else
      unlock_sound = this->kick_open_sound;
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BODY,
      shader: unlock_sound,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
    if ( this->removeKeyOnUse )
    {
      presentable = user->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: user);
        presentable = user->presentable;
      }
      requiredKey = this->requiredKey;
      v10 = user->GetInventory_2(this: user);
      idInventoryCollection::DeleteInventoryItem(this: v10, owner: presentable, decl: requiredKey, count: 1);
    }
    return 1;
  }
}


// ========================================================================
// ?GetUseLocation@idDoor_Parametric@@UBAXPBVidActor@@AAVidVec3@@@Z
// EA  : 0x82C24E20
// RVA : 0x00C24E20
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::GetUseLocation(idDoor_Parametric *this, const idActor *actor, idVec3 *pos)
{
  idPhysics *Physics; // r28
  const idVec3 *v7; // r27
  float *v8; // r3
  double v9; // fp28
  double v10; // fp27
  double v11; // fp26
  double v12; // fp31
  double v13; // fp30
  double v14; // fp29
  idPhysics *v15; // r3
  float *v16; // r3
  double v17; // fp0
  double v18; // fp9
  double v19; // fp7
  double v20; // fp6

  Physics = idEntity::GetPhysics(this: &actor->idAnimatedEntity);
  v7 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
  v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v9 = (float)(*v8 - v7->x);
  v10 = (float)(v8[1] - v7->y);
  v11 = (float)(v8[2] - v7->z);
  v12 = (float)((float)(this->default_axis.y * this->rotate_axis.z) - (float)(this->default_axis.z * this->rotate_axis.y));
  v13 = (float)((float)(this->default_axis.x * this->rotate_axis.y) - (float)(this->rotate_axis.x * this->default_axis.y));
  v14 = (float)((float)(this->rotate_axis.x * this->default_axis.z) - (float)(this->default_axis.x * this->rotate_axis.z));
  v15 = idEntity::GetPhysics(this: &actor->idAnimatedEntity);
  v16 = (float *)v15->GetBounds(this: v15, a2: -1);
  if ( (float)(v16[3] - *v16) <= (double)(float)(v16[4] - v16[1]) )
    v17 = (float)((float)((float)(v16[4] - v16[1]) * 0.5) + (float)1.0);
  else
    v17 = (float)((float)((float)(v16[3] - *v16) * 0.5) + (float)1.0);
  if ( (float)((float)((float)v12 * (float)v9)
             + (float)((float)((float)v14 * (float)v10) + (float)((float)v13 * (float)v11))) <= 0.0 )
  {
    v18 = (float)(this->door_center.x - (float)(this->door_ai_offset.x + (float)((float)v12 * (float)v17)));
    v19 = (float)(this->door_center.y - (float)(this->door_ai_offset.y + (float)((float)v14 * (float)v17)));
    v20 = (float)(this->door_center.z - (float)(this->door_ai_offset.z + (float)((float)v13 * (float)v17)));
  }
  else
  {
    v18 = (float)(this->door_center.x + (float)(this->door_ai_offset.x + (float)((float)v12 * (float)v17)));
    v19 = (float)(this->door_center.y + (float)(this->door_ai_offset.y + (float)((float)v14 * (float)v17)));
    v20 = (float)(this->door_center.z + (float)(this->door_ai_offset.z + (float)((float)v13 * (float)v17)));
  }
  pos->z = v20;
  pos->y = v19;
  pos->x = v18;
}


// ========================================================================
// ?GetCurrentAngle@idDoor_Parametric@@ABAMXZ
// EA  : 0x82C24FC0
// RVA : 0x00C24FC0
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

float __fastcall idDoor_Parametric::GetCurrentAngle(idDoor_Parametric *this)
{
  idDoor_Parametric::axis_t heading_axis; // r30
  float *p_x; // r7
  double v4; // fp31
  double v5; // fp30
  double v6; // fp29
  long double v7; // fp2
  double v8; // fp1

  heading_axis = this->heading_axis;
  p_x = &this->physicsObj.GetAxis(this: &this->physicsObj, a2: 0)->mat[heading_axis].x;
  v4 = p_x[1];
  v5 = *p_x;
  v6 = p_x[2];
  *(double *)&v7 = (float)((float)(p_x[2] * this->default_axis.z)
                         + (float)((float)(this->default_axis.x * *p_x) + (float)(this->default_axis.y * p_x[1])));
  v8 = (float)(idMath::ACos(a: v7) * idMath::M_RAD2DEG);
  if ( (float)((float)(this->rotate_axis.x
                     * (float)((float)(this->default_axis.y * (float)v6) - (float)(this->default_axis.z * (float)v4)))
             + (float)((float)(this->rotate_axis.z
                             * (float)((float)(this->default_axis.x * (float)v4)
                                     - (float)(this->default_axis.y * (float)v5)))
                     + (float)(this->rotate_axis.y
                             * (float)((float)(this->default_axis.z * (float)v5)
                                     - (float)(this->default_axis.x * (float)v6))))) < 0.0 )
    v8 = -v8;
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?GetSoundTransform@idDoor_Parametric@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C250C0
// RVA : 0x00C250C0
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::GetSoundTransform(idDoor_Parametric *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  idPhysics *Physics; // r28
  idPhysics *v7; // r27
  idPhysics *v8; // r26
  float *v9; // r3
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  float *v13; // r3
  double v14; // fp7
  double v15; // fp5
  double v16; // fp29
  double v17; // fp31
  double v18; // fp30
  float *v19; // r3
  double v20; // fp0
  double v21; // fp13
  idPhysics *v22; // r3

  Physics = idEntity::GetPhysics(this);
  v7 = idEntity::GetPhysics(this);
  v8 = idEntity::GetPhysics(this);
  v9 = (float *)Physics->GetBounds(this: Physics, a2: -1);
  v10 = (float)((float)(v9[3] + *v9) * (float)0.5);
  v11 = (float)((float)(v9[4] + v9[1]) * (float)0.5);
  v12 = (float)((float)(v9[5] + v9[2]) * (float)0.5);
  v13 = (float *)v7->GetAxis(this: v7, a2: 0);
  v14 = (float)((float)(v13[6] * (float)v12) + (float)(v13[3] * (float)v11));
  v15 = (float)((float)(v13[8] * (float)v12) + (float)(v13[2] * (float)v10));
  v16 = (float)((float)(v13[4] * (float)v11) + (float)((float)(v13[7] * (float)v12) + (float)(v13[1] * (float)v10)));
  v17 = (float)((float)((float)v10 * *v13) + (float)v14);
  v18 = (float)((float)(v13[5] * (float)v11) + (float)v15);
  v19 = (float *)v8->GetOrigin(this: v8, a2: 0);
  v20 = (float)(v19[1] + (float)v16);
  v21 = (float)(v19[2] + (float)v18);
  soundOrigin->x = *v19 + (float)v17;
  soundOrigin->y = v20;
  soundOrigin->z = v21;
  v22 = idEntity::GetPhysics(this);
  *soundAxis = *v22->GetAxis(this: v22, a2: 0);
}


// ========================================================================
// ?Event_GetAIUsePosition@idDoor_Parametric@@AAA?AVeventVector@@PAVidEntity@@@Z
// EA  : 0x82C25278
// RVA : 0x00C25278
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idDoor_Parametric *__fastcall idDoor_Parametric::Event_GetAIUsePosition(
        idDoor_Parametric *this,
        eventVector *result,
        idEntity *entity)
{
  idVec3 v7[4]; // [sp+50h] [-30h] BYREF

  if ( (unsigned __int8)idActor::IsTypeOf(c: entity) == 0 )
    idLib::Error(fmt: "Entity '%s' is not an actor", entity->name.data);
  (*(void (__fastcall **)(eventVector *, idEntity *, idVec3 *))(LODWORD(result->value.x) + 720))(
    a1: result,
    a2: entity,
    a3: v7);
  eventVector::eventVector((eventVector *)this, v: v7);
  return this;
}


// ========================================================================
// ?Event_LockGrinderSetAngleAtTime@idDoor_Parametric@@AAA?AVeventVoid@@PAVidEntity@@ABVidVec3@@MM@Z
// EA  : 0x82C252E8
// RVA : 0x00C252E8
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idDoor_Parametric *__fastcall idDoor_Parametric::Event_LockGrinderSetAngleAtTime(
        idDoor_Parametric *this,
        idDoor_Parametric *result,
        idEntity *activator,
        const idVec3 *dir,
        double duration,
        double yaw)
{
  double v6; // fp31
  double max_angle; // fp0
  int v10; // r29
  const idAngles *v11; // r3
  __int64 v12; // r6
  __int64 v13; // r10
  float v15[4]; // [sp+58h] [-58h] BYREF
  float v16[4]; // [sp+68h] [-48h] BYREF

  v6 = yaw;
  if ( (float)((float)(dir->x
                     * (float)((float)(result->default_axis.y * result->rotate_axis.z)
                             - (float)(result->default_axis.z * result->rotate_axis.y)))
             + (float)((float)(dir->z
                             * (float)((float)(result->default_axis.x * result->rotate_axis.y)
                                     - (float)(result->rotate_axis.x * result->default_axis.y)))
                     + (float)(dir->y
                             * (float)((float)(result->rotate_axis.x * result->default_axis.z)
                                     - (float)(result->default_axis.x * result->rotate_axis.z))))) <= 0.0 )
  {
    max_angle = -yaw;
    v6 = -result->max_angle;
    if ( -yaw < v6 )
      goto LABEL_5;
    if ( max_angle <= 0.0 )
      goto LABEL_4;
LABEL_8:
    v6 = 0.0;
    goto LABEL_5;
  }
  max_angle = result->max_angle;
  if ( yaw < 0.0 )
    goto LABEL_8;
  if ( yaw > max_angle )
LABEL_4:
    v6 = max_angle;
LABEL_5:
  v16[0] = 0.0;
  v16[1] = v6;
  v16[2] = 0.0;
  v15[0] = 0.0;
  v15[2] = 0.0;
  v15[1] = idDoor_Parametric::GetCurrentAngle(this: result);
  v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v11 = (const idAngles *)gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  HIDWORD(v12) = v10;
  LODWORD(v12) = 0;
  HIDWORD(v13) = v15;
  LODWORD(v13) = v16;
  idPhysics_Parametric::SetAngularInterpolation(
    this: &result->physicsObj,
    currentTime: v11,
    accelTime: v12,
    decelTime: 0,
    startAng: v13);
  return this;
}


// ========================================================================
// ?Event_DisableObstacleFlag@idDoor_Parametric@@AAA?AVeventVoid@@XZ
// EA  : 0x82C25448
// RVA : 0x00C25448
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idDoor_Parametric *__fastcall idDoor_Parametric::Event_DisableObstacleFlag(idDoor_Parametric *this, eventVoid *result)
{
  (*(void (__fastcall **)(eventVoid *, int, int))(*(_DWORD *)&result[5304] + 24))(a1: result + 5304, a2: 1, a3: -1);
  return this;
}


// ========================================================================
// ?LockGrind@idDoor_Parametric@@UAAXPAVidEntity@@0@Z
// EA  : 0x82C25490
// RVA : 0x00C25490
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::LockGrind(idDoor_Parametric *this, idDoor_Base *source, idEntity *lockGrinder)
{
  int GameMs; // r3
  BOOL forceUnusableWhenOpened; // r10
  idPhysics *Physics; // r29
  const idVec3 *v9; // r27
  float *v10; // r3
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  double lockGrindRestAngle; // fp0
  idEventArg *v15; // r22
  idEventArg *v16; // r21
  idEventArg *v17; // r22
  idEventArg *v18; // r21
  double v19; // fp12
  idEventArg *v20; // r21
  double v21; // fp10
  idEventArg *v22; // r24
  _BYTE v23[20]; // [sp+70h] [-130h] BYREF
  _BYTE v24[20]; // [sp+90h] [-110h] BYREF
  const idEventArg *v25; // [sp+B0h] [-F0h]
  float v26; // [sp+B4h] [-ECh]
  float v27; // [sp+B8h] [-E8h]
  float v28; // [sp+BCh] [-E4h]
  float v29[5]; // [sp+D0h] [-D0h] BYREF
  float v30[5]; // [sp+F0h] [-B0h] BYREF
  idEventArg v31; // [sp+110h] [-90h] BYREF

  idDoor_Base::SetDoorState(this, activator: source, s: 3);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  forceUnusableWhenOpened = this->forceUnusableWhenOpened;
  this->autoCloseTime = GameMs;
  if ( forceUnusableWhenOpened || this->forcedUnusable )
  {
    this->forcedUnusable = true;
    this->autoCloseTime = 0;
  }
  Physics = idEntity::GetPhysics(this: lockGrinder);
  v9 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
  v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v11 = (float)(*v10 - v9->x);
  v12 = (float)(v10[1] - v9->y);
  v13 = (float)(v10[2] - v9->z);
  this->physicsObj.SetContents(this: &this->physicsObj, a2: 128, a3: -1);
  lockGrindRestAngle = this->lockGrindRestAngle;
  v26 = v11;
  v27 = v12;
  v28 = v13;
  HIBYTE(v29[0]) = 102;
  HIBYTE(v30[0]) = 102;
  HIBYTE(v25) = 118;
  if ( lockGrindRestAngle == 160.0 )
  {
    v29[1] = lockGrindRestAngle;
    v30[1] = 80.0;
    v15 = idEventArg::idEventArg(this: &v31, data: source);
    memcpy(Dst: v24, Src: v29, Size: sizeof(v24));
    memcpy(Dst: v23, Src: v30, Size: sizeof(v23));
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_LockGrinderSetAngleAtTime,
      time: *(_DWORD *)&v15->type,
      arg1: (const idEventArg *)LODWORD(v15->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v15->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v25, 32),
      arg4: (const idEventArg *)LODWORD(v27));
    v26 = v11;
    v27 = v12;
    v28 = v13;
    HIBYTE(v29[0]) = 102;
    HIBYTE(v30[0]) = 102;
    v30[1] = 110.0;
    HIBYTE(v25) = 118;
    v29[1] = this->lockGrindRestAngle * (float)0.33329999;
    v16 = idEventArg::idEventArg(this: &v31, data: source);
    memcpy(Dst: v24, Src: v29, Size: sizeof(v24));
    memcpy(Dst: v23, Src: v30, Size: sizeof(v23));
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_LockGrinderSetAngleAtTime,
      time: *(_DWORD *)&v16->type,
      arg1: (const idEventArg *)LODWORD(v16->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v16->value.v[2]),
      arg3: v25,
      arg4: (const idEventArg *)LODWORD(v27));
  }
  else
  {
    v30[1] = 90.0;
    v29[1] = 80.0;
    v17 = idEventArg::idEventArg(this: &v31, data: source);
    memcpy(Dst: v24, Src: v30, Size: sizeof(v24));
    memcpy(Dst: v23, Src: v29, Size: sizeof(v23));
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_LockGrinderSetAngleAtTime,
      time: *(_DWORD *)&v17->type,
      arg1: (const idEventArg *)LODWORD(v17->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v17->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v25, 32),
      arg4: (const idEventArg *)LODWORD(v27));
    v26 = v11;
    v27 = v12;
    v28 = v13;
    HIBYTE(v30[0]) = 102;
    HIBYTE(v29[0]) = 102;
    v30[1] = 30.0;
    HIBYTE(v25) = 118;
    v29[1] = 110.0;
    v18 = idEventArg::idEventArg(this: &v31, data: source);
    memcpy(Dst: v24, Src: v30, Size: sizeof(v24));
    memcpy(Dst: v23, Src: v29, Size: sizeof(v23));
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_LockGrinderSetAngleAtTime,
      time: *(_DWORD *)&v18->type,
      arg1: (const idEventArg *)LODWORD(v18->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v18->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v25, 32),
      arg4: (const idEventArg *)LODWORD(v27));
  }
  v19 = this->lockGrindRestAngle;
  v26 = v11;
  v27 = v12;
  v28 = v13;
  HIBYTE(v30[0]) = 102;
  v30[1] = (float)v19 + (float)10.0;
  HIBYTE(v29[0]) = 102;
  v29[1] = 510.0;
  HIBYTE(v25) = 118;
  v20 = idEventArg::idEventArg(this: &v31, data: source);
  memcpy(Dst: v24, Src: v30, Size: sizeof(v24));
  memcpy(Dst: v23, Src: v29, Size: sizeof(v23));
  idEventReceiver::PostEventMS(
    this,
    ev: &EV_LockGrinderSetAngleAtTime,
    time: *(_DWORD *)&v20->type,
    arg1: (const idEventArg *)LODWORD(v20->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v20->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(LODWORD(v20->value.q[3]), 32),
    arg4: (const idEventArg *)LODWORD(v27));
  v21 = this->lockGrindRestAngle;
  HIBYTE(v29[0]) = 102;
  HIBYTE(v30[0]) = 102;
  HIBYTE(v25) = 118;
  v26 = v11;
  v27 = v12;
  v28 = v13;
  v30[1] = 500.0;
  v29[1] = v21;
  v22 = idEventArg::idEventArg(this: &v31, data: source);
  memcpy(Dst: v24, Src: v29, Size: sizeof(v24));
  memcpy(Dst: v23, Src: v30, Size: sizeof(v23));
  idEventReceiver::PostEventMS(
    this,
    ev: &EV_LockGrinderSetAngleAtTime,
    time: *(_DWORD *)&v22->type,
    arg1: (const idEventArg *)LODWORD(v22->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v22->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(LODWORD(v22->value.q[3]), 32),
    arg4: (const idEventArg *)LODWORD(v27));
  idEventReceiver::PostEventMS(this, ev: &EV_DisableObstacleFlag, time: 700);
  this->forceUnopenedTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                          + 1250;
}


// ========================================================================
// ??1idDoor_Parametric@@UAA@XZ
// EA  : 0x82C25990
// RVA : 0x00C25990
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::~idDoor_Parametric(idDoor_Parametric *this)
{
  idClipModel *frameClip; // r3
  idPresentable *framePresentable; // r3
  idPresentable *doorAttachment; // r3
  idRenderModel *frame; // r3
  idRenderModel *door; // r3

  this->__vftable = (idDoor_Parametric_vtbl *)&idDoor_Parametric::`vftable';
  frameClip = this->frameClip;
  if ( frameClip != nullptr )
    idClipModel::Delete(this: frameClip);
  framePresentable = this->framePresentable;
  if ( framePresentable != nullptr )
  {
    idPresentable::Delete(this: framePresentable);
    this->framePresentable = nullptr;
  }
  doorAttachment = this->doorAttachment;
  if ( doorAttachment != nullptr )
  {
    idPresentable::Delete(this: doorAttachment);
    this->doorAttachment = nullptr;
  }
  idAnimatedEntity::FreePresentable(this);
  frame = this->frame;
  if ( frame != nullptr )
  {
    if ( (int)frame > 10000 )
    {
      frame->unlinked = true;
      frame->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: frame);
    }
    this->frame = nullptr;
  }
  door = this->door;
  if ( door != nullptr )
  {
    if ( (int)door > 10000 )
    {
      door->unlinked = true;
      door->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: door);
    }
    this->door = nullptr;
  }
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->rigidBodyPhysicsObj);
  idPhysics_Parametric::~idPhysics_Parametric(this: &this->physicsObj);
  idDoor_Base::~idDoor_Base(this);
}


// ========================================================================
// __unwind$489810_1
// EA  : 0x82C25A6C
// RVA : 0x00C25A6C
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_489810_1()
{
  int v0; // r12

  idDoor_Base::~idDoor_Base(this: *(idDoor_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489811_1
// EA  : 0x82C25A94
// RVA : 0x00C25A94
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_489811_1()
{
  int v0; // r12

  idPhysics_Parametric::~idPhysics_Parametric(this: (idPhysics_Parametric *)(*(_DWORD *)(v0 - 128 + 148) + 5304));
}


// ========================================================================
// __unwind$489812
// EA  : 0x82C25AC0
// RVA : 0x00C25AC0
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_489812()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 128 + 148) + 6536));
}


// ========================================================================
// ?Spawn@idDoor_Parametric@@QAAXXZ
// EA  : 0x82C25B20
// RVA : 0x00C25B20
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::Spawn(idDoor_Parametric *this)
{
  idMat3 *p_spawnOrientation; // r28
  int *v3; // r10
  float *p_z; // r11
  int i; // ctr
  double y; // fp12
  double z; // fp11
  double v8; // fp7
  double v9; // fp6
  idClipModel *v10; // r3
  idClipModel *v11; // r3
  idPhysics *Physics; // r29
  idPhysics *v13; // r26
  int entityNumber; // r23
  const idMat3 *v15; // r29
  const idVec3 *v16; // r3
  float *p_absBounds; // r10
  idPresentable *v18; // r3
  idPresentable *v19; // r11
  idClientGame *v20; // r3
  int v21; // r9
  int v22; // r7
  idPresentable *framePresentable; // r11
  idPhysics_Parametric *p_physicsObj; // r29
  idClipModel *v25; // r3
  idClipModel *v26; // r4
  int v27; // r4
  idGameTimeManager *p_gameTimeManager; // r3
  int GameMs; // r3
  int v30; // r3
  float *v31; // r11
  idDoor_Parametric::axis_t v32; // r11
  float *v33; // r11
  idDoor_Parametric::slideDir_t slideDir; // r11
  float *v35; // r3
  float *v36; // r3
  double v37; // fp12
  double v38; // fp10
  double v39; // fp6
  double v40; // fp10
  double v41; // fp11
  double v42; // fp2
  double v43; // fp1
  double v44; // fp9
  double v45; // fp4
  double v46; // fp5
  idPresentable *presentable; // r11
  char v48; // r10
  idPresentable *v49; // r3
  idPresentable *v50; // r30
  int v51; // r28
  const idMat3 *v52; // r27
  const idVec3 *v53; // r3
  int v54; // [sp+8h] [-F8h]
  int v55; // [sp+Ch] [-F4h]
  int v56; // [sp+10h] [-F0h]
  int v57; // [sp+14h] [-ECh]
  int v58; // [sp+18h] [-E8h]
  idPresentable *v59; // [sp+1Ch] [-E4h]
  float v60[5]; // [sp+58h] [-A8h] BYREF
  int v61; // [sp+6Ch] [-94h] BYREF
  idMat3 v62; // [sp+70h] [-90h] BYREF

  if ( this->max_angle <= (double)this->min_angle )
  {
    idLib::Warning(fmt: "idDoor_Parametric::Spawn: '%s' max_angle <= min_angle, removing entity", this->name.data);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    return;
  }
  if ( this->door == nullptr )
  {
    idLib::Warning(fmt: "idDoor_Parametric::Spawn: '%s' door render model isn't set, removing entity", this->name.data);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    return;
  }
  if ( idEntity::IsMegaModel(this) )
  {
    idLib::Warning(fmt: "idDoor_Parametric::Spawn: '%s' door cannot be a mega model, removing entity", this->name.data);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    return;
  }
  p_spawnOrientation = &this->spawnOrientation;
  v3 = &v61;
  p_z = &this->spawnPosition.z;
  for ( i = 9; i != 0; --i )
    *++v3 = *(_DWORD *)++p_z;
  idMat3::OrthoNormalizeSelf(this: &v62);
  p_spawnOrientation->mat[0].x = v62.mat[0].x;
  y = v62.mat[0].y;
  z = v62.mat[0].z;
  this->spawnOrientation.mat[1].x = v62.mat[1].x;
  this->spawnOrientation.mat[0].y = y;
  this->spawnOrientation.mat[0].z = z;
  this->spawnOrientation.mat[1].y = v62.mat[1].y;
  this->spawnOrientation.mat[1].z = v62.mat[1].z;
  v8 = v62.mat[2].y;
  this->spawnOrientation.mat[2].x = v62.mat[2].x;
  v9 = v62.mat[2].z;
  this->spawnOrientation.mat[2].y = v8;
  this->spawnOrientation.mat[2].z = v9;
  this->SetModel(this, a2: this->door);
  idEntity::InitRenderModel(this);
  if ( this->frame != nullptr )
  {
    v10 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v10 != nullptr )
      v11 = idClipModel::idClipModel(
              this: v10,
              clip: &clientGame->clip,
              name: this->frame->name.str,
              overrideClipMaterial: nullptr);
    else
      v11 = nullptr;
    this->frameClip = v11;
    Physics = idEntity::GetPhysics(this);
    v13 = idEntity::GetPhysics(this);
    entityNumber = this->entityNumber;
    v15 = Physics->GetAxis(this: Physics, a2: 0);
    v16 = v13->GetOrigin(this: v13, a2: 0);
    idClipModel::Link(
      this: this->frameClip,
      newEntityNumber: entityNumber,
      newPhysicsId: 0,
      newBodyId: 1,
      newOrigin: v16,
      newAxis: v15);
    p_absBounds = (float *)&this->frameClip->absBounds;
    this->bounds.b[0].x = *p_absBounds;
    this->bounds.b[0].y = p_absBounds[1];
    this->bounds.b[0].z = p_absBounds[2];
    this->bounds.b[1].x = p_absBounds[3];
    this->bounds.b[1].y = p_absBounds[4];
    this->bounds.b[1].z = p_absBounds[5];
    v18 = (idPresentable *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x4B0u,
                             tag: TAG_PRESENTABLE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
    if ( v18 != nullptr )
      v19 = idPresentable::idPresentable(
              this: v18,
              e: this,
              renderModel_: (idTreeAnimator *)this->frame,
              entityNumber_: 0x1FFF,
              fxDecl_: nullptr);
    else
      v19 = nullptr;
    this->framePresentable = v19;
    v19->axis.mat[0].x = p_spawnOrientation->mat[0].x;
    v20 = clientGame;
    v19->axis.mat[0].y = this->spawnOrientation.mat[0].y;
    v21 = (int)&v19->axis.mat[1];
    v19->axis.mat[0].z = this->spawnOrientation.mat[0].z;
    v22 = (int)&v19->axis.mat[2];
    v19->axis.mat[1].x = this->spawnOrientation.mat[1].x;
    v19->axis.mat[1].y = this->spawnOrientation.mat[1].y;
    v19->axis.mat[1].z = this->spawnOrientation.mat[1].z;
    v19->axis.mat[2].x = this->spawnOrientation.mat[2].x;
    v19->axis.mat[2].y = this->spawnOrientation.mat[2].y;
    v19->axis.mat[2].z = this->spawnOrientation.mat[2].z;
    framePresentable = this->framePresentable;
    framePresentable->origin.x = this->spawnPosition.x;
    framePresentable->origin.y = this->spawnPosition.y;
    framePresentable->origin.z = this->spawnPosition.z;
    idClientGame::AddPresentable(
      this: v20,
      presentable: this->framePresentable,
      index: -1,
      skipReplication: false,
      a5: v22,
      a6: (int)&this->spawnOrientation.mat[1],
      a7: v21,
      a8: (int)&framePresentable->origin,
      a9: v54,
      a10: v55,
      a11: v56,
      a12: v57,
      a13: v58,
      a14: v59);
  }
  p_physicsObj = &this->physicsObj;
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  idPhysics_Parametric::SetWorldOrientation(
    this: &this->physicsObj,
    _worldOrigin: &this->spawnPosition,
    _worldAxis: &this->spawnOrientation);
  this->physicsObj.SetLocalOrigin(this: &this->physicsObj, a2: &vec3_origin, a3: -1);
  this->physicsObj.SetLocalAxis(this: &this->physicsObj, a2: &mat3_identity, a3: -1);
  v25 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v25 != nullptr )
    v26 = idClipModel::idClipModel(
            this: v25,
            clip: &clientGame->clip,
            name: this->door->name.str,
            overrideClipMaterial: nullptr);
  else
    v26 = nullptr;
  ((void (__fastcall *)(idPhysics_Parametric *, idClipModel *, double))p_physicsObj->SetClipModel)(
    a1: &this->physicsObj,
    a2: v26,
    a3: 1.0);
  p_physicsObj->SetClipMask(this: &this->physicsObj, a2: 1, a3: -1);
  if ( !this->usableByAI || this->IsLocked(this) )
    v27 = 131073;
  else
    v27 = 1;
  p_physicsObj->SetContents(this: &this->physicsObj, a2: v27, a3: -1);
  idPhysics_Parametric::SetPusher(this: &this->physicsObj, push: &clientGame->push, flags: 2);
  idEntity::SetPhysics(this, phys: &this->physicsObj);
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( this->slidingDoor )
  {
    GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetLinearExtrapolation(
      this: &this->physicsObj,
      type: EXTRAPOLATION_NONE,
      currentTime: GameMs,
      duration: (unsigned int)&vec3_origin,
      base: &vec3_origin,
      speed: &vec3_origin);
  }
  else
  {
    v60[1] = this->start_angle;
    v60[0] = 0.0;
    v60[2] = 0.0;
    v30 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetAngularExtrapolation(
      this: &this->physicsObj,
      type: EXTRAPOLATION_NONE,
      currentTime: v30,
      duration: (unsigned int)v60,
      base: &ang_zero,
      speed: &ang_zero);
  }
  if ( this->rotation_axis > (unsigned int)AXIS_Z )
    this->rotation_axis = AXIS_Z;
  v31 = (float *)(&this->idEventReceiver + this->rotation_axis);
  this->rotate_axis.x = v31[14];
  this->rotate_axis.y = v31[15];
  this->rotate_axis.z = v31[16];
  v32 = (this->rotation_axis + 1) % 3;
  this->heading_axis = v32;
  v33 = (float *)(&this->idEventReceiver + v32);
  this->default_axis.x = v33[14];
  this->default_axis.y = v33[15];
  this->default_axis.z = v33[16];
  if ( this->frame != nullptr )
    idRenderModel::CommitThisFrame(this: this->door);
  slideDir = this->slideDir;
  if ( slideDir != SLIDE_UP )
  {
    if ( slideDir == SLIDE_DOWN )
    {
      this->slideVec.y = 0.0;
      this->slideVec.z = -1.0;
    }
    else
    {
      this->slideVec.z = 0.0;
      switch ( slideDir )
      {
        case SLIDE_LEFT:
          this->slideVec.y = 0.0;
          this->slideVec.x = -1.0;
          goto LABEL_43;
        case SLIDE_RIGHT:
          this->slideVec.x = 1.0;
          this->slideVec.y = 0.0;
          goto LABEL_43;
        case SLIDE_FORWARD:
          this->slideVec.y = 1.0;
          break;
        default:
          this->slideVec.y = -1.0;
          break;
      }
    }
    this->slideVec.x = 0.0;
    goto LABEL_43;
  }
  this->slideVec = vec3_up;
LABEL_43:
  this->closedPos.x = this->spawnPosition.x;
  this->closedPos.y = this->spawnPosition.y;
  this->closedPos.z = this->spawnPosition.z;
  if ( this->frame == nullptr )
  {
    v35 = (float *)p_physicsObj->GetAbsBounds(this: &this->physicsObj, a2: -1);
    this->bounds.b[0].x = *v35;
    this->bounds.b[0].y = v35[1];
    this->bounds.b[0].z = v35[2];
    this->bounds.b[1].x = v35[3];
    this->bounds.b[1].y = v35[4];
    this->bounds.b[1].z = v35[5];
  }
  v36 = (float *)p_physicsObj->GetClipModel(this: &this->physicsObj, a2: 0);
  v37 = v36[29];
  v38 = v36[26];
  v39 = (float)(v36[30] + v36[27]);
  this->door_center.z = (float)(v36[31] + v36[28]) * (float)0.5;
  this->door_center.x = (float)((float)v37 + (float)v38) * (float)0.5;
  this->door_center.y = (float)v39 * (float)0.5;
  v40 = v36[28];
  this->door_center.z = v36[28];
  v41 = this->door_center.y;
  v42 = (float)(this->spawnOrientation.mat[0].y * (float)((float)(v36[30] - v36[27]) * (float)0.5));
  v43 = (float)((float)((float)(v36[30] - v36[27]) * (float)0.5) * this->spawnOrientation.mat[0].z);
  this->door_center.x = (float)((float)((float)(v36[30] - v36[27]) * (float)0.5) * p_spawnOrientation->mat[0].x)
                      + this->door_center.x;
  this->door_center.y = (float)v42 + (float)v41;
  this->door_center.z = (float)v43 + (float)v40;
  v44 = this->spawnOrientation.mat[1].y;
  v45 = this->spawnOrientation.mat[1].z;
  v46 = (float)((float)(v36[30] - v36[27]) * (float)-0.5);
  this->door_ai_offset.x = this->spawnOrientation.mat[1].x * (float)((float)(v36[30] - v36[27]) * (float)-0.5);
  this->door_ai_offset.y = (float)v44 * (float)v46;
  this->door_ai_offset.z = (float)v45 * (float)v46;
  this->UpdateAASAreas(this);
  idDoor_Base::SetDoorState(this, activator: this, s: 0);
  idDoor_Base::UpdateState(this);
  presentable = this->presentable;
  if ( presentable == nullptr || (v48 = 1, presentable->model == nullptr) )
    v48 = 0;
  if ( v48 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->model->g.castDimShadows = DIMSHADOW_ON;
  }
  v49 = this->presentable;
  if ( v49 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v49 = this->presentable;
  }
  v49->Present(this: v49);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v50 = this->presentable;
  v51 = p_physicsObj->GetContents(this: p_physicsObj, a2: -1);
  v52 = p_physicsObj->GetAxis(this: p_physicsObj, a2: 0);
  v53 = p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
  idPresentable::SetClipModelInfo_DynamicRenderModel(
    this: v50,
    clipModelSpawnPos_: v53,
    clipModelSpawnAxis_: v52,
    contents: v51);
}


// ========================================================================
// __unwind$490109
// EA  : 0x82C264D8
// RVA : 0x00C264D8
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_490109()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$490110
// EA  : 0x82C26504
// RVA : 0x00C26504
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_490110()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// __unwind$490111
// EA  : 0x82C26530
// RVA : 0x00C26530
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_490111()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Think@idDoor_Parametric@@UAAXXZ
// EA  : 0x82C26560
// RVA : 0x00C26560
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __fastcall idDoor_Parametric::Think(idDoor_Parametric *this)
{
  idPresentable *framePresentable; // r3
  float *v3; // r3
  float *p_axis; // r11
  const idVec3 *v5; // r3
  idPresentable *doorAttachment; // r11
  idDoor_Base::doorState_t state; // r11

  idDoor_Parametric::AutoClose(this);
  idEntity::RunPhysics(this);
  idDoor_Base::UpdateState(this);
  framePresentable = this->framePresentable;
  if ( framePresentable != nullptr )
    framePresentable->Present(this: framePresentable);
  if ( this->doorAttachment != nullptr )
  {
    v3 = (float *)this->physicsObj.GetAxis(this: &this->physicsObj, a2: 0);
    p_axis = (float *)&this->doorAttachment->axis;
    *p_axis = *v3;
    p_axis[1] = v3[1];
    p_axis[2] = v3[2];
    p_axis[3] = v3[3];
    p_axis[4] = v3[4];
    p_axis[5] = v3[5];
    p_axis[6] = v3[6];
    p_axis[7] = v3[7];
    p_axis[8] = v3[8];
    v5 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
    doorAttachment = this->doorAttachment;
    doorAttachment->origin.x = v5->x;
    doorAttachment->origin.y = v5->y;
    doorAttachment->origin.z = v5->z;
    this->doorAttachment->Present(this: this->doorAttachment);
  }
  state = this->state;
  if ( state == DOOR_CLOSED || state == DOOR_BROKEN )
  {
    idEntity::BecomeInactive(this, flags: 7);
  }
  else if ( (this->autoCloseTime <= 0 || this->close_time <= 0) && state == DOOR_OPENED )
  {
    idEntity::BecomeInactive(this, flags: 7);
    this->forceUnopenedTime = 0;
  }
  else
  {
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// ?CanClose@idDoor_Parametric@@EBA_N_N@Z
// EA  : 0x82C266F0
// RVA : 0x00C266F0
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

int __fastcall idDoor_Parametric::CanClose(
        idDoor_Parametric *this,
        bool testingForUse,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  idPhysics *Physics; // r3
  const idBounds *v8; // r3
  float *v9; // r3
  double v10; // fp8
  double v11; // fp7
  double v12; // fp5
  double x; // fp13
  double y; // fp12
  double z; // fp11
  unsigned __int64 index; // r11
  idGatherQuery *p_canCloseQuery; // r27
  char v18; // r11
  bool v19; // zf
  int GatheredEntities; // r29
  int v21; // r30
  int *v22; // r31
  __int64 v24; // [sp+50h] [-D0h] BYREF
  idBounds v25; // [sp+60h] [-C0h] BYREF
  idBounds v26; // [sp+80h] [-A0h] BYREF
  int v27[32]; // [sp+A0h] [-80h] BYREF

  if ( testingForUse )
  {
    Physics = idEntity::GetPhysics(this);
    v8 = Physics->GetAbsBounds(this: Physics, a2: -1);
    v9 = (float *)idBounds::operator+(this: &v26, result: &this->bounds, a: v8);
    v25.b[0].x = *v9;
    v25.b[0].y = v9[1];
    v25.b[0].z = v9[2];
    v10 = (float)(v9[3] + g_doorClosingRange.valueFloat);
    v25.b[1].x = v9[3];
    v11 = (float)(v9[4] + g_doorClosingRange.valueFloat);
    v25.b[1].y = v9[4];
    v12 = (float)(v9[5] + g_doorClosingRange.valueFloat);
    v25.b[0].x = v25.b[0].x - g_doorClosingRange.valueFloat;
    v25.b[0].y = v25.b[0].y - g_doorClosingRange.valueFloat;
    v25.b[0].z = v25.b[0].z - g_doorClosingRange.valueFloat;
    v25.b[1].x = v10;
    v25.b[1].y = v11;
    v25.b[1].z = v12;
  }
  else
  {
    x = this->door_center.x;
    LODWORD(a6) = this->close_range;
    y = this->door_center.y;
    z = this->door_center.z;
    v25.b[0].z = this->door_center.z;
    v24 = a6;
    v25.b[1].z = (float)z + (float)64.0;
    v25.b[0].x = (float)x - (float)a6;
    v25.b[0].y = (float)y - (float)a6;
    v25.b[1].x = (float)x + (float)a6;
    v25.b[1].y = (float)y + (float)a6;
  }
  index = this->canCloseQuery.index;
  p_canCloseQuery = &this->canCloseQuery;
  if ( (unsigned int)index < LODWORD(clientGame->clip.gatherQueryFirstSubmittedIndex)
    || (v19 = (unsigned int)index <= LODWORD(clientGame->clip.gatherQueryLastSubmittedIndex), v18 = 1, !v19) )
  {
    v18 = 0;
  }
  if ( v18 != 0
    && (GatheredEntities = idClip::GetGatheredEntities(
                             this: &clientGame->clip,
                             query: &this->canCloseQuery,
                             entityList: v27,
                             maxCount: 16),
        v21 = 0,
        GatheredEntities > 0) )
  {
    v22 = v27;
    while ( (unsigned __int8)idActor::IsTypeOf(c: gameLocal->entities.ptr[*v22]) == 0 )
    {
      ++v21;
      ++v22;
      if ( v21 >= GatheredEntities )
        goto LABEL_12;
    }
    return 0;
  }
  else
  {
LABEL_12:
    p_canCloseQuery->index = *(unsigned __int64 *)&idClip::GatherTouchingBounds(
                                                     this: (idClip *)&v24,
                                                     result: (idGatherQuery *)&clientGame->clip,
                                                     bounds: &v25,
                                                     clipMask: 33792,
                                                     passEntityNumber: -1,
                                                     userName: "w:\\tech5\\tungsten\\game\\entities\\Door_Parametric.cpp(341) : Touching Bounds")->world;
    return 1;
  }
}


// ========================================================================
// ?Use@idDoor_Parametric@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C268F8
// RVA : 0x00C268F8
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

int __fastcall idDoor_Parametric::Use(idDoor_Parametric *this, idActor *user, const usableState_t usable)
{
  double min_angle; // fp30
  double max_angle; // fp29
  unsigned __int8 v7; // r27
  BOOL v8; // r29
  idActor *v9; // r4
  idClipModel *frameClip; // r3
  idPhysics_Parametric *p_physicsObj; // r28
  float *p_z; // r10
  int v13; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idClipModel *v15; // r3
  idCollisionModel *CollisionModel; // r3
  idAIEvent **v17; // r3
  idClipModel *v18; // r27
  idPhysics_RigidBody_vtbl *v19; // r27
  int v20; // r3
  idPhysics_RigidBody_vtbl *v21; // r27
  int v22; // r3
  idPhysics *Physics; // r3
  float *v24; // r27
  float *v25; // r3
  double v26; // fp0
  double v27; // fp13
  double v28; // fp9
  double v29; // fp1
  idPhysics_RigidBody_vtbl *v30; // r10
  void (__fastcall *SetLinearVelocity)(struct idPhysics_RigidBody *, const idVec3 *, int); // r9
  idPhysics *v33; // r29
  idPhysics *v34; // r28
  float *v35; // r3
  double v36; // fp27
  double v37; // fp26
  double v38; // fp25
  float *v39; // r3
  double v40; // fp27
  double v41; // fp26
  double v42; // fp25
  const idVec3 *v43; // r3
  idPhysics_Parametric_vtbl *v44; // r10
  idDoor_Parametric::axis_t heading_axis; // r28
  double v46; // fp27
  double v47; // fp26
  double v48; // fp25
  float *p_x; // r4
  int v50; // r22
  const idSoundShader *close_sound; // r5
  idPhysics *v52; // r27
  int GameMs; // r26
  idPhysics *v54; // r3
  idAIEventManager *p_aiEventManager; // r27
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v57; // r3
  idPhysics_Parametric_vtbl *v58; // r11
  float *v59; // r3
  double y; // fp10
  double v61; // fp8
  double v62; // fp6
  double v63; // fp4
  double z; // fp3
  bool (__fastcall *IsClosed)(struct idDoor_Parametric *); // ctr
  double v66; // fp13
  double v68; // fp9
  double v70; // fp7
  double v71; // fp12
  double v72; // fp9
  idVec3 *v73; // r11
  double v74; // fp9
  double v75; // fp8
  float x; // r9
  int y_low; // r8
  double slideSpeed; // fp10
  double v79; // fp1
  double v82; // fp8
  double v83; // fp0
  int v84; // r25
  const idAngles *v85; // r3
  __int64 v86; // r6
  __int64 v87; // r10
  double angularspeed; // fp29
  double CurrentAngle; // fp1
  idDoor_Parametric::axis_t rotation_axis; // r11
  double v91; // fp13
  int v92; // r26
  const idAngles *v93; // r3
  __int64 v94; // r6
  __int64 v95; // r10
  int v96; // r3
  BOOL forceUnusableWhenOpened; // r11
  idAIEventManager v98; // [sp+50h] [-6F0h] BYREF
  float v99[4]; // [sp+A0h] [-6A0h] BYREF
  idTraceModel v100; // [sp+B0h] [-690h] BYREF

  min_angle = this->min_angle;
  max_angle = this->max_angle;
  v7 = 0;
  if ( this->kicked != 0.0 )
  {
    min_angle = this->min_kick_angle;
    max_angle = this->max_kick_angle;
  }
  v8 = this->IsClosed(this);
  if ( v8 && this->locked )
  {
    v9 = idActor::CastTo(c: user);
    if ( v9 == nullptr || (unsigned __int8)idDoor_Parametric::Unlock(this, user: v9, kicked: this->kicked) == 0 )
      return 0;
    if ( this->kicked != 0.0 && this->kickOffHinges )
    {
      frameClip = this->frameClip;
      if ( frameClip != nullptr )
        idClipModel::SetContents(this: frameClip, newContents: 186);
      p_physicsObj = &this->physicsObj;
      this->physicsObj.UnlinkClip(this: &this->physicsObj);
      v100.offset.x = 0.0;
      v100.offset.y = 0.0;
      p_z = &v100.offset.z;
      v100.offset.z = 0.0;
      memset(&v100.type, 0, 20);
      v13 = 6;
      p_viewNoteMutex = &analysisClient.viewNoteMutex;
      do
      {
        ++p_viewNoteMutex;
        *++p_z = *(float *)&p_viewNoteMutex->handle;
        --v13;
      }
      while ( v13 != 0 );
      v100.radius = 0.0;
      v100.isConvex = false;
      v100.pad[2] = 0;
      v100.pad[1] = 0;
      v100.pad[0] = 0;
      v15 = p_physicsObj->GetClipModel(this: &this->physicsObj, a2: 0);
      CollisionModel = idClipModel::GetCollisionModel(this: v15, index: 0);
      idCollisionModelManager::TrmFromModel(
        this: collisionModelManager,
        modelName: CollisionModel->name.str,
        trm: &v100);
      v17 = (idAIEvent **)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0xD8u,
                            tag: TAG_CLIPMODEL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
      v98.eventList.list = v17;
      if ( v17 != nullptr )
        v18 = idClipModel::idClipModel(
                this: (idClipModel *)v17,
                clip: &clientGame->clip,
                trm: &v100,
                numTraceModels: 1,
                material: nullptr);
      else
        v18 = nullptr;
      idPhysics::InitPhysics(
        this: &this->rigidBodyPhysicsObj,
        clip_: &clientGame->clip,
        callbacks_: &this->physicsCallbacks,
        entityNumber_: this->entityNumber);
      ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))this->rigidBodyPhysicsObj.SetClipModel)(
        a1: &this->rigidBodyPhysicsObj,
        a2: v18,
        a3: 1.0);
      v19 = this->rigidBodyPhysicsObj.__vftable;
      v20 = (int)p_physicsObj->GetOrigin(this: &this->physicsObj, a2: 0);
      v19->SetOrigin(this: &this->rigidBodyPhysicsObj, a2: (const idVec3 *)v20, a3: -1);
      v21 = this->rigidBodyPhysicsObj.__vftable;
      v22 = (int)p_physicsObj->GetAxis(this: &this->physicsObj, a2: 0);
      v21->SetAxis(this: &this->rigidBodyPhysicsObj, a2: (const idMat3 *)v22, a3: -1);
      this->rigidBodyPhysicsObj.SetClipMask(this: &this->rigidBodyPhysicsObj, a2: 1, a3: -1);
      this->rigidBodyPhysicsObj.SetContents(this: &this->rigidBodyPhysicsObj, a2: 0, a3: -1);
      idPhysics_RigidBody::SetBouncyness(this: &this->rigidBodyPhysicsObj, b: 0.050000001);
      idPhysics_RigidBody::SetFriction(this: &this->rigidBodyPhysicsObj, linear: 0.0, angular: 0.0, contact: 0.85000002);
      idEntity::SetPhysics(this, phys: &this->rigidBodyPhysicsObj);
      Physics = idEntity::GetPhysics(this: user);
      v24 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v25 = (float *)p_physicsObj->GetOrigin(this: &this->physicsObj, a2: 0);
      v26 = *v24;
      v27 = v24[1];
      *(float *)&v98.eventList.size = 0.0;
      v28 = (float)(v25[1] - (float)v27);
      *(float *)&v98.eventList.list = *v25 - (float)v26;
      *(float *)&v98.eventList.num = v28;
      v29 = idVec3::NormalizeFast(this: (idVec3 *)&v98);
      v30 = this->rigidBodyPhysicsObj.__vftable;
      v99[2] = 200.0;
      v99[0] = *(float *)&v98.eventList.list * (float)150.0;
      SetLinearVelocity = v30->SetLinearVelocity;
      v99[1] = *(float *)&v98.eventList.num * (float)150.0;
      ((void (__fastcall *)(idPhysics_RigidBody *, float *, _DWORD, double))SetLinearVelocity)(
        a1: &this->rigidBodyPhysicsObj,
        a2: v99,
        a3: 0,
        a4: v29);
      idDoor_Base::SetDoorState(this, activator: (idDoor_Base *)user, s: 5);
      return 1;
    }
  }
  if ( !v8 && this->state != DOOR_CLOSING )
  {
    min_angle = 0.0;
    v7 = 1;
    goto LABEL_31;
  }
  if ( min_angle != 0.0 )
  {
    if ( max_angle == 0.0 )
      goto LABEL_31;
    if ( user != nullptr )
    {
      v33 = idEntity::GetPhysics(this: user);
      v34 = idEntity::GetPhysics(this: user);
      v35 = (float *)v33->GetBounds(this: v33, a2: -1);
      v36 = (float)((float)(v35[3] + *v35) * (float)0.5);
      v37 = (float)((float)(v35[4] + v35[1]) * (float)0.5);
      v38 = (float)((float)(v35[5] + v35[2]) * (float)0.5);
      v39 = (float *)v34->GetOrigin(this: v34, a2: 0);
      v40 = (float)((float)v36 + *v39);
      v41 = (float)(v39[1] + (float)v37);
      v42 = (float)(v39[2] + (float)v38);
      v43 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
      v44 = this->physicsObj.__vftable;
      heading_axis = this->heading_axis;
      v98.eventList.list = (idAIEvent **)&this->rotate_axis;
      v46 = (float)((float)v40 - v43->x);
      v47 = (float)((float)v41 - v43->y);
      v48 = (float)((float)v42 - v43->z);
      p_x = &v44->GetAxis(this: &this->physicsObj, a2: 0)->mat[heading_axis].x;
      if ( (float)((float)((float)((float)(p_x[1] * this->rotate_axis.z) - (float)(p_x[2] * this->rotate_axis.y))
                         * (float)v46)
                 + (float)((float)((float)((float)(*p_x * this->rotate_axis.y) - (float)(this->rotate_axis.x * p_x[1]))
                                 * (float)v48)
                         + (float)((float)((float)(this->rotate_axis.x * p_x[2]) - (float)(*p_x * this->rotate_axis.z))
                                 * (float)v47))) <= 0.0 )
      {
        if ( !this->invertRotationDir )
          goto LABEL_31;
      }
      else if ( this->invertRotationDir )
      {
        goto LABEL_31;
      }
    }
    else if ( this->invertRotationDir )
    {
      goto LABEL_31;
    }
  }
  min_angle = max_angle;
LABEL_31:
  v50 = v7;
  if ( v7 != 0 )
  {
    if ( this->CanClose(this, a2: true) )
    {
      close_sound = this->close_sound;
      goto LABEL_35;
    }
    return 0;
  }
  close_sound = this->start_sound;
LABEL_35:
  idEntity::StartSoundShader(this, channel: SND_CHANNEL_BODY, shader: close_sound, soundShaderFlags: 0, peerMask: 0xFFu);
  v52 = idEntity::GetPhysics(this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v54 = v52;
  GetOrigin = v52->GetOrigin;
  p_aiEventManager = &gameLocal->aiEventManager;
  v57 = GetOrigin(this: v54, a2: 0);
  idAIEventManager::AddEvent(
    this: &v98,
    result: p_aiEventManager,
    eventDecl: this->motionEventDecl,
    curTime: GameMs,
    originator: this,
    instigator: user,
    origin: v57,
    delay: 1000);
  if ( !this->slidingDoor )
  {
    if ( this->kicked == 0.0 )
      angularspeed = this->angularspeed;
    else
      angularspeed = (float)((float)(this->angularspeed * this->kicked) * (float)4.0);
    CurrentAngle = idDoor_Parametric::GetCurrentAngle(this);
    rotation_axis = this->rotation_axis;
    v91 = (float)((float)__fabs((float)((float)min_angle - (float)CurrentAngle)) / (float)angularspeed);
    if ( rotation_axis == AXIS_Y )
    {
      *(float *)&v98.eventHash.hash = CurrentAngle;
      *(float *)&v98.eventHash.hashSize = 0.0;
      *(float *)&v98.eventHash.granularity = min_angle;
      *(float *)&v98.eventHash.lookupMask = 0.0;
    }
    else
    {
      *(float *)&v98.eventHash.hash = 0.0;
      *(float *)&v98.eventHash.granularity = 0.0;
      if ( rotation_axis == AXIS_Z )
      {
        *(float *)&v98.eventHash.indexChain = CurrentAngle;
        *(float *)&v98.eventHash.hashSize = 0.0;
        *(float *)&v98.eventHash.hashMask = min_angle;
        *(float *)&v98.eventHash.lookupMask = 0.0;
LABEL_49:
        v98.eventList.num = (int)(float)((float)v91 * (float)1000.0);
        v92 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v93 = (const idAngles *)idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        HIDWORD(v94) = v92;
        LODWORD(v94) = 0;
        HIDWORD(v95) = &v98.eventHash;
        LODWORD(v95) = &v98.eventHash.granularity;
        idPhysics_Parametric::SetAngularInterpolation(
          this: &this->physicsObj,
          currentTime: v93,
          accelTime: v94,
          decelTime: 0,
          startAng: v95);
        goto LABEL_50;
      }
      *(float *)&v98.eventHash.hashSize = CurrentAngle;
      *(float *)&v98.eventHash.lookupMask = min_angle;
    }
    *(float *)&v98.eventHash.hashMask = 0.0;
    *(float *)&v98.eventHash.indexChain = 0.0;
    goto LABEL_49;
  }
  v58 = this->physicsObj.__vftable;
  v98.eventList.list = (idAIEvent **)&this->closedPos;
  v59 = (float *)v58->GetOrigin(this: &this->physicsObj, a2: 0);
  y = this->slideVec.y;
  v61 = (float)(v59[1] - this->closedPos.y);
  v62 = (float)(v59[2] - this->closedPos.z);
  v63 = (float)(*v59 - this->closedPos.x);
  z = this->slideVec.z;
  IsClosed = this->IsClosed;
  v66 = (float)((float)((float)v63 * (float)v63)
              + (float)((float)((float)v62 * (float)v62) + (float)((float)v61 * (float)v61)));
  _FP12 = (float)((float)((float)((float)v63 * (float)v63)
                        + (float)((float)((float)v62 * (float)v62) + (float)((float)v61 * (float)v61)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  v68 = (float)((float)((float)((float)v63 * (float)v63)
                      + (float)((float)((float)v62 * (float)v62) + (float)((float)v61 * (float)v61)))
              * (float)0.5);
  __asm { fsel      f8, f12, f13, f0 }
  v70 = __frsqrte(_FP8);
  v71 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70 * (float)v68)
                                                                              * (float)v70)
                                                                      - (float)1.5)
                                                      * (float)v70)
                                              * (float)v68)
                                      * (float)((float)-(float)((float)((float)((float)v70 * (float)v68) * (float)v70)
                                                              - (float)1.5)
                                              * (float)v70))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v70 * (float)v68) * (float)v70) - (float)1.5) * (float)v70));
  v72 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70 * (float)v68)
                                                                                      * (float)v70)
                                                                              - (float)1.5)
                                                              * (float)v70)
                                                      * (float)v68)
                                              * (float)((float)-(float)((float)((float)((float)v70 * (float)v68)
                                                                              * (float)v70)
                                                                      - (float)1.5)
                                                      * (float)v70))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v70 * (float)v68) * (float)v70) - (float)1.5)
                              * (float)v70))
              * (float)v68);
  *(float *)&v98.receivers.list = this->slideVec.x
                                * (float)((float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5)
                                                * (float)v71)
                                        * (float)v66);
  *(float *)&v98.receivers.num = (float)((float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5)
                                               * (float)v71)
                                       * (float)v66)
                               * (float)y;
  *(float *)&v98.receivers.size = (float)((float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5)
                                                * (float)v71)
                                        * (float)v66)
                                * (float)z;
  if ( IsClosed(this) )
  {
    v73 = (idVec3 *)&v98;
    v74 = (float)(this->slideDist * this->slideVec.y);
    v75 = (float)(this->slideDist * this->slideVec.z);
    *(float *)&v98.eventList.list = this->slideVec.x * this->slideDist;
    *(float *)&v98.eventList.num = v74;
    *(float *)&v98.eventList.size = v75;
  }
  else
  {
    v73 = &vec3_origin;
  }
  x = v73->x;
  y_low = SLODWORD(v73->y);
  slideSpeed = this->slideSpeed;
  v98.eventPools.size = LODWORD(v73->z);
  *(float *)&v98.eventPools.list = x;
  v98.eventPools.num = y_low;
  v79 = (float)((float)((float)(x - *(float *)&v98.receivers.list) * (float)(x - *(float *)&v98.receivers.list))
              + (float)((float)((float)(*(float *)&v98.eventPools.size - *(float *)&v98.receivers.size)
                              * (float)(*(float *)&v98.eventPools.size - *(float *)&v98.receivers.size))
                      + (float)((float)(*(float *)&y_low - *(float *)&v98.receivers.num)
                              * (float)(*(float *)&y_low - *(float *)&v98.receivers.num))));
  _FP12 = (float)((float)((float)((float)(x - *(float *)&v98.receivers.list) * (float)(x - *(float *)&v98.receivers.list))
                        + (float)((float)((float)(*(float *)&v98.eventPools.size - *(float *)&v98.receivers.size)
                                        * (float)(*(float *)&v98.eventPools.size - *(float *)&v98.receivers.size))
                                + (float)((float)(*(float *)&y_low - *(float *)&v98.receivers.num)
                                        * (float)(*(float *)&y_low - *(float *)&v98.receivers.num))))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f9, f12, f1, f0 }
  v82 = __frsqrte(_FP9);
  v83 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82
                                                                                      * (float)((float)v79 * (float)0.5))
                                                                              * (float)v82)
                                                                      - (float)1.5)
                                                      * (float)v82)
                                              * (float)((float)v79 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v82
                                                                              * (float)((float)v79 * (float)0.5))
                                                                      * (float)v82)
                                                              - (float)1.5)
                                              * (float)v82))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)v79 * (float)0.5)) * (float)v82)
                                      - (float)1.5)
                      * (float)v82));
  v98.eventList.num = (int)(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82 * (float)((float)v79 * (float)0.5)) * (float)v82) - (float)1.5) * (float)v82) * (float)((float)v79 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)v79 * (float)0.5)) * (float)v82) - (float)1.5) * (float)v82)) - (float)1.5)
                                                                                                 * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)v79 * (float)0.5)) * (float)v82) - (float)1.5) * (float)v82))
                                                                                         * (float)((float)v79
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82 * (float)((float)v79 * (float)0.5)) * (float)v82) - (float)1.5) * (float)v82) * (float)((float)v79 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)v79 * (float)0.5)) * (float)v82) - (float)1.5) * (float)v82)) - (float)1.5)
                                                                                         * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)v79 * (float)0.5)) * (float)v82) - (float)1.5)
                                                                                                 * (float)v82)))
                                                                         - (float)1.5)
                                                         * (float)v83)
                                                 / (float)slideSpeed)
                                         * (float)v79)
                                 * (float)1000.0);
  v84 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v85 = (const idAngles *)idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v86) = v84;
  LODWORD(v86) = 0;
  HIDWORD(v87) = &v98.receivers;
  LODWORD(v87) = &v98.eventPools;
  idPhysics_Parametric::SetLinearInterpolation(
    this: &this->physicsObj,
    currentTime: v85,
    accelTime: v86,
    decelTime: 0,
    startPos: v87);
LABEL_50:
  if ( v50 != 0 )
  {
    idDoor_Base::SetDoorState(this, activator: (idDoor_Base *)user, s: 1);
    if ( this->forceUnusableWhenOpened )
      this->forcedUnusable = false;
    goto LABEL_55;
  }
  idDoor_Base::SetDoorState(this, activator: (idDoor_Base *)user, s: 3);
  v96 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  forceUnusableWhenOpened = this->forceUnusableWhenOpened;
  this->autoCloseTime = v96;
  if ( forceUnusableWhenOpened )
  {
    this->forcedUnusable = true;
LABEL_55:
    this->autoCloseTime = 0;
  }
  return 1;
}


// ========================================================================
// __unwind$491011
// EA  : 0x82C272BC
// RVA : 0x00C272BC
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_491011()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1856 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?IsOpen@idDoor_Parametric@@UBA_NXZ
// EA  : 0x82C272E8
// RVA : 0x00C272E8
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

unsigned int __fastcall idDoor_Parametric::IsOpen(idDoor_Parametric *this)
{
  int GameMs; // r3
  BOOL slidingDoor; // r11
  idGameTimeManager *p_gameTimeManager; // r3
  int v6; // r29
  double v7; // fp31
  double v8; // fp30
  double v9; // fp29
  const idVec3 *v10; // r3
  double v11; // fp9
  double v12; // fp7
  unsigned __int8 v13; // r11
  int v14; // r30
  double CurrentAngle; // fp1

  if ( this->forceUnopenedTime > 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    return (GameMs >> 31)
         + ((unsigned int)GameMs >= this->forceUnopenedTime)
         + ((unsigned int)this->forceUnopenedTime >> 31);
  }
  slidingDoor = this->slidingDoor;
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( slidingDoor )
  {
    v6 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    if ( this->physicsObj.GetLinearEndTime(this: &this->physicsObj) > v6 )
      return 0;
    v7 = (float)(this->closedPos.x
               + (float)((float)((float)(this->slideVec.x * this->spawnOrientation.mat[0].x)
                               + (float)((float)(this->spawnOrientation.mat[1].x * this->slideVec.y)
                                       + (float)(this->spawnOrientation.mat[2].x * this->slideVec.z)))
                       * this->slideDist));
    v8 = (float)(this->closedPos.y
               + (float)((float)((float)(this->spawnOrientation.mat[2].y * this->slideVec.z)
                               + (float)((float)(this->spawnOrientation.mat[0].y * this->slideVec.x)
                                       + (float)(this->spawnOrientation.mat[1].y * this->slideVec.y)))
                       * this->slideDist));
    v9 = (float)(this->closedPos.z
               + (float)((float)((float)(this->spawnOrientation.mat[2].z * this->slideVec.z)
                               + (float)((float)(this->spawnOrientation.mat[0].z * this->slideVec.x)
                                       + (float)(this->spawnOrientation.mat[1].z * this->slideVec.y)))
                       * this->slideDist));
    v10 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
    v11 = (float)(v10->y - (float)v8);
    v12 = (float)(v10->z - (float)v9);
    v13 = 1;
    if ( (float)((float)((float)(v10->x - (float)v7) * (float)(v10->x - (float)v7))
               + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) > 0.000099999997 )
      return 0;
  }
  else
  {
    v14 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    if ( this->physicsObj.GetAngularEndTime(this: &this->physicsObj) > v14 )
      return 0;
    CurrentAngle = idDoor_Parametric::GetCurrentAngle(this);
    v13 = 1;
    if ( __fabs(CurrentAngle) <= 0.1 )
      return 0;
  }
  return v13;
}


// ========================================================================
// ?IsClosed@idDoor_Parametric@@UBA_NXZ
// EA  : 0x82C274E0
// RVA : 0x00C274E0
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

int __fastcall idDoor_Parametric::IsClosed(idDoor_Parametric *this)
{
  BOOL slidingDoor; // r11
  idGameTimeManager *p_gameTimeManager; // r3
  int GameMs; // r29
  const idVec3 *v6; // r3
  unsigned __int8 v7; // r11
  double v8; // fp10
  double v9; // fp8
  double v10; // fp6
  int v11; // r30

  slidingDoor = this->slidingDoor;
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( slidingDoor )
  {
    GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    if ( this->physicsObj.GetLinearEndTime(this: &this->physicsObj) > GameMs )
      return 0;
    v6 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
    v7 = 1;
    v8 = (float)(v6->y - this->closedPos.y);
    v9 = (float)(v6->z - this->closedPos.z);
    v10 = (float)(v6->x - this->closedPos.x);
    if ( (float)((float)((float)v10 * (float)v10)
               + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))) > 0.000099999997 )
      return 0;
  }
  else
  {
    v11 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    if ( this->physicsObj.GetAngularEndTime(this: &this->physicsObj) > v11 )
      return 0;
    return __fabs(idDoor_Parametric::GetCurrentAngle(this)) < 0.1;
  }
  return v7;
}


// ========================================================================
// ?Event_SetAngleAtTime@idDoor_Parametric@@AAA?AVeventVoid@@PAVidEntity@@MM@Z
// EA  : 0x82C27608
// RVA : 0x00C27608
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idDoor_Parametric *__fastcall idDoor_Parametric::Event_SetAngleAtTime(
        idDoor_Parametric *this,
        idDoor_Parametric *result,
        idEntity *source,
        double duration,
        double yaw)
{
  idPhysics *Physics; // r28
  float *v11; // r27
  float *v12; // r3
  double v13; // fp7
  double v14; // fp6
  idVec3 v16; // [sp+50h] [-50h] BYREF

  Physics = idEntity::GetPhysics(this: source);
  v11 = (float *)result->physicsObj.GetOrigin(this: &result->physicsObj, a2: 0);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v13 = (float)(v12[1] - v11[1]);
  v14 = (float)(v12[2] - v11[2]);
  v16.x = *v12 - *v11;
  v16.y = v13;
  v16.z = v14;
  idDoor_Parametric::Event_LockGrinderSetAngleAtTime(this, result, activator: source, dir: &v16, duration, yaw);
  return this;
}


// ========================================================================
// ??0idDoor_Parametric@@QAA@XZ
// EA  : 0x82C276E0
// RVA : 0x00C276E0
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

idDoor_Parametric *__fastcall idDoor_Parametric::idDoor_Parametric(idDoor_Parametric *this)
{
  unsigned __int64 v1; // r29

  idDoor_Base::idDoor_Base(this);
  LODWORD(v1) = 0;
  this->frameClip = nullptr;
  this->__vftable = (idDoor_Parametric_vtbl *)&idDoor_Parametric::`vftable';
  idPhysics_Parametric::idPhysics_Parametric(this: &this->physicsObj);
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->rigidBodyPhysicsObj);
  this->heading_axis = AXIS_X;
  this->framePresentable = nullptr;
  this->doorAttachment = nullptr;
  this->frame = nullptr;
  this->rotation_axis = AXIS_Z;
  this->door = nullptr;
  this->min_angle = -90.0;
  this->invertRotationDir = false;
  this->max_angle = 90.0;
  this->slidingDoor = false;
  this->min_kick_angle = -90.0;
  this->slideDir = SLIDE_UP;
  this->max_kick_angle = 90.0;
  this->start_angle = 0.0;
  this->angularspeed = 90.0;
  this->slideDist = 128.0;
  this->slideSpeed = 90.0;
  this->lockGrindRestAngle = 80.0;
  this->rotate_axis.x = 0.0;
  this->rotate_axis.y = 0.0;
  this->rotate_axis.z = 0.0;
  this->default_axis.x = 0.0;
  this->default_axis.y = 0.0;
  this->default_axis.z = 0.0;
  this->start_sound = nullptr;
  this->close_sound = nullptr;
  this->kick_open_sound = nullptr;
  this->door_center.x = 0.0;
  this->door_center.y = 0.0;
  this->door_center.z = 0.0;
  this->door_ai_offset.x = 0.0;
  this->door_ai_offset.y = 0.0;
  this->door_ai_offset.z = 0.0;
  this->close_time = 8000;
  this->close_range = 70;
  this->autoCloseTime = 0;
  this->forceUnopenedTime = 0;
  this->slideVec.x = 0.0;
  this->slideVec.y = 0.0;
  this->slideVec.z = 0.0;
  this->closedPos.x = 0.0;
  this->closedPos.y = 0.0;
  this->closedPos.z = 0.0;
  this->canCloseQuery.index = v1;
  return this;
}


// ========================================================================
// __unwind$491603
// EA  : 0x82C27848
// RVA : 0x00C27848
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_491603()
{
  int v0; // r12

  idDoor_Base::~idDoor_Base(this: *(idDoor_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$491604
// EA  : 0x82C27870
// RVA : 0x00C27870
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void _unwind_491604()
{
  int v0; // r12

  idPhysics_Parametric::~idPhysics_Parametric(this: (idPhysics_Parametric *)(*(_DWORD *)(v0 - 128 + 148) + 5304));
}


// ========================================================================
// `dynamic initializer for 'g_doorClosingRange''
// EA  : 0x83375CB8
// RVA : 0x01375CB8
// PDB : w:\tech5\tungsten\game\entities\door_parametric.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_doorClosingRange__()
{
  idCVar::idCVar(
    this: &g_doorClosingRange,
    name: "g_doorClosingRange",
    value: "16",
    flags: 4,
    description: "range used when testing for AI near closing door",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_doorClosingRange__);
}

