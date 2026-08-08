
// ========================================================================
// ?GetLocalOrigin@idPhysics_DynamicBase@@UBAABVidVec3@@H@Z
// EA  : 0x824E3498
// RVA : 0x004E3498
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.h
// ========================================================================

const idVec3 *__fastcall idPhysics_DynamicBase::GetLocalOrigin(idVehicleOccupant *this)
{
  return &vec3_origin;
}


// ========================================================================
// ?GetView@idVehicleOccupant@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x824E34A8
// RVA : 0x004E34A8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.h
// ========================================================================

void __fastcall idVehicleOccupant::GetView(idVehicleOccupant *this, idVec3 *origin, idMat3 *axis)
{
  this->GetModelTransform(this, a2: origin, a3: axis);
}


// ========================================================================
// ?GetAF@idVehicleOccupant@@UBAPBVidAnimator_AF@@XZ
// EA  : 0x824E34B8
// RVA : 0x004E34B8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.h
// ========================================================================

const idAnimator_AF *__fastcall idVehicleOccupant::GetAF(idVehicleOccupant *this)
{
  return &this->afProperties;
}


// ========================================================================
// ?GetLookPoint@idVehicleOccupant_Car@@UBAABVidVec3@@XZ
// EA  : 0x82D358C0
// RVA : 0x00D358C0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.h
// ========================================================================

const idVec3 *__fastcall idVehicleOccupant_Car::GetLookPoint(idVehicleOccupant_Car *this)
{
  return &this->lookPoint;
}


// ========================================================================
// ?GetLookAimPoint@idVehicleOccupant_Car@@UBA?AW4aimPoint_t@@XZ
// EA  : 0x82D358C8
// RVA : 0x00D358C8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.h
// ========================================================================

aimPoint_t __fastcall idVehicleOccupant_Car::GetLookAimPoint(idVehicleOccupant_Car *this)
{
  return this->lookAimPoint;
}


// ========================================================================
// ?GetLookEntity@idVehicleOccupant_Car@@UBAPBVidEntity@@XZ
// EA  : 0x82D358D0
// RVA : 0x00D358D0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.h
// ========================================================================

const idEntity *__fastcall idVehicleOccupant_Car::GetLookEntity(idVehicleOccupant_Car *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->lookEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}

