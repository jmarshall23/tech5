
// ========================================================================
// ??0detachable_t@@QAA@XZ
// EA  : 0x8256FA50
// RVA : 0x0056FA50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// ========================================================================

detachable_t *__fastcall detachable_t::detachable_t(detachable_t *this)
{
  int v2; // ctr
  float *p_y; // r11
  float *p_z; // r10

  this->decl = nullptr;
  idStr::idStr(this: &this->tagName, text: "detachable");
  this->jointIndex.value = -1;
  this->tagData.trans.x = 0.0;
  this->tagData.trans.y = 0.0;
  this->tagData.trans.z = 0.0;
  this->tagData.rot.x = 0.0;
  v2 = 9;
  this->tagData.rot.y = 0.0;
  p_y = &mat2_identity.mat[1].y;
  this->tagData.rot.z = 0.0;
  p_z = &this->origin.z;
  this->tagData.rot.w = 0.0;
  this->tagData.parentJoint.value = -1;
  this->origin = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->transformFrame = 0;
  return this;
}


// ========================================================================
// ??0clientDetachable_t@idPresentableVehicle@@QAA@XZ
// EA  : 0x8256FB20
// RVA : 0x0056FB20
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// ========================================================================

idPresentableVehicle::clientDetachable_t *__fastcall idPresentableVehicle::clientDetachable_t::clientDetachable_t(
        idPresentableVehicle::clientDetachable_t *this)
{
  detachable_t::detachable_t(this: &this->item);
  this->attached = false;
  this->permDetach = false;
  this->lastAddCount = 0;
  this->lastRemoveCount = 0;
  this->addCount = 0;
  this->removeCount = 0;
  this->damageLeft = 1;
  return this;
}


// ========================================================================
// ?GetFireCount@idPresentableVehicle@@QBAHXZ
// EA  : 0x82B4B080
// RVA : 0x00B4B080
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// ========================================================================

int __fastcall idPresentableVehicle::GetFireCount(idPresentableVehicle *this)
{
  if ( idPresentableVehicle::GetClientFire(this) != nullptr )
    return idPresentableVehicle::GetClientFire(this)->fireCount;
  else
    return 0;
}


// ========================================================================
// ?GetOccupantAsEntity@vehicleOccupant_t@@QBAPAVidEntity@@XZ
// EA  : 0x82B9B560
// RVA : 0x00B9B560
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// ========================================================================

idEntity *__fastcall vehicleOccupant_t::GetOccupantAsEntity(vehicleOccupant_t *this)
{
  if ( idPresentablePtr<idPresentable>::IsValid((idPresentablePtr<idPresentableActor> *)this) )
    return idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable)->entity;
  else
    return nullptr;
}


// ========================================================================
// ??0collisionInfo_t@@QAA@XZ
// EA  : 0x82B9B5C0
// RVA : 0x00B9B5C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// ========================================================================

collisionInfo_t *__fastcall collisionInfo_t::collisionInfo_t(collisionInfo_t *this)
{
  this->entity.spawnId.value = 0x1FFF;
  this->presentable.spawnId = 0;
  this->time = 0;
  this->frameNumber = 0;
  this->vehicleHeadOn = false;
  this->entity.spawnId.value = 0x1FFF;
  this->presentable.spawnId = 0;
  this->point.z = 0.0;
  this->point.y = 0.0;
  this->point.x = 0.0;
  this->normal.z = 0.0;
  this->normal.y = 0.0;
  this->normal.x = 0.0;
  this->isCollider = false;
  this->dist = 0.0;
  this->hitWorld = false;
  this->damage = 0.0;
  this->surfaceType = -1;
  this->physId = -1;
  this->flags = 0;
  this->endAxis = mat3_identity;
  return this;
}


// ========================================================================
// ?GetImpactMgrPtr@idPresentableVehicle@@UAAPAVidImpactManager@@XZ
// EA  : 0x82BA1C40
// RVA : 0x00BA1C40
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// ========================================================================

idImpactManager *__fastcall idPresentableVehicle::GetImpactMgrPtr(idPresentableVehicle *this)
{
  return &this->impactManager;
}


// ========================================================================
// ?GetInventory@idPresentableVehicle@@UBAPBVidInventoryCollection@@XZ
// EA  : 0x82BA1C48
// RVA : 0x00BA1C48
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// ========================================================================

idInventoryCollection *__fastcall idPresentableVehicle::GetInventory(idPresentableVehicle *this)
{
  return this->activeInventory;
}


// ========================================================================
// ?GetControllingPlayerIndex@idPresentableVehicle@@UAAHXZ
// EA  : 0x82BA1C50
// RVA : 0x00BA1C50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// ========================================================================

int __fastcall idPresentableVehicle::GetControllingPlayerIndex(idPresentableVehicle *this)
{
  unsigned int spawnId; // r11
  int v3; // r30

  spawnId = this->controller.idPresentableAnimatedEntity::idPresentable::spawnId;
  v3 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v3)->spawnId == this->controller.idPresentableAnimatedEntity::idPresentable::spawnId )
  {
    return idPresentable::GetController(this: &this->idPresentableAnimatedEntity)->index;
  }
  else
  {
    return -1;
  }
}


// ========================================================================
// ?GetControllingPlayer@idPresentableVehicle@@UAAPAVidPresentablePlayer@@XZ
// EA  : 0x82BA1CC8
// RVA : 0x00BA1CC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// ========================================================================

idPresentablePlayer *__fastcall idPresentableVehicle::GetControllingPlayer(idPresentableVehicle *this)
{
  unsigned int spawnId; // r11
  int v3; // r30
  idPresentablePlayer *result; // r3

  spawnId = this->controller.idPresentableAnimatedEntity::idPresentable::spawnId;
  v3 = spawnId & 0x3FFF;
  if ( spawnId == 0 )
    return nullptr;
  if ( !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
    return nullptr;
  result = (idPresentablePlayer *)idClientGame::GetPresentableByIndex(this: clientGame, index: v3);
  if ( result->spawnId != this->controller.idPresentableAnimatedEntity::idPresentable::spawnId )
    return nullptr;
  return result;
}

