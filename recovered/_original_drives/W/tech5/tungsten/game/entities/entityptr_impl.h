
// ========================================================================
// ??C?$idEntityPtr@$$CBVidEntity@@@@QBAPBVidEntity@@XZ
// EA  : 0x824FA4C0
// RVA : 0x004FA4C0
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idEntity *__fastcall idEntityPtr<idEntity const>::operator->(idEntityPtr<idEntity> *this)
{
  idEntity *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidPlayer@@@@QBAPAVidPlayer@@XZ
// EA  : 0x829FB968
// RVA : 0x009FB968
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idPlayer *__fastcall idEntityPtr<idPlayer>::operator->(idEntityPtr<idPlayer> *this)
{
  idPlayer *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idPlayer *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idPlayer::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidVehicle_Car@@@@QBAPAVidVehicle_Car@@XZ
// EA  : 0x82B04F38
// RVA : 0x00B04F38
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idVehicle_Car *__fastcall idEntityPtr<idVehicle_Car>::GetEntity(idEntityPtr<idVehicle_Car> *this)
{
  idVehicle_Car *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idVehicle_Car *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idVehicle_Car::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidVehicleAI@@@@QBAPAVidVehicleAI@@XZ
// EA  : 0x82B04F80
// RVA : 0x00B04F80
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idVehicleAI *__fastcall idEntityPtr<idVehicleAI>::GetEntity(idEntityPtr<idVehicleAI> *this)
{
  idVehicleAI *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idVehicleAI *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idVehicleAI::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidSplineWaypoint@@@@QBAPAVidSplineWaypoint@@XZ
// EA  : 0x82B0AE68
// RVA : 0x00B0AE68
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idSplineWaypoint *__fastcall idEntityPtr<idSplineWaypoint>::GetEntity(idEntityPtr<idSplineWaypoint> *this)
{
  idSplineWaypoint *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idSplineWaypoint *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idSplineWaypoint::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidNavSplinePath@@@@QBAPAVidNavSplinePath@@XZ
// EA  : 0x82B0AEB0
// RVA : 0x00B0AEB0
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idNavSplinePath *__fastcall idEntityPtr<idNavSplinePath>::GetEntity(idEntityPtr<idNavSplinePath> *this)
{
  idNavSplinePath *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idNavSplinePath *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idNavSplinePath::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidVehicle@@@@QBAPAVidVehicle@@XZ
// EA  : 0x82B0B100
// RVA : 0x00B0B100
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idVehicle *__fastcall idEntityPtr<idVehicle>::GetEntity(idEntityPtr<idVehicle> *this)
{
  idVehicle *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idVehicle *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idVehicle::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??B?$idEntityPtr@VidSplinePath@@@@QBAPAVidSplinePath@@XZ
// EA  : 0x82C360A0
// RVA : 0x00C360A0
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idSplinePath *__fastcall idEntityPtr<idSplinePath>::operator idSplinePath *(idEntityPtr<idSplinePath> *this)
{
  idSplinePath *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idSplinePath *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idSplinePath::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidAlignedEntity@@@@QBAPAVidAlignedEntity@@XZ
// EA  : 0x82C4C3F8
// RVA : 0x00C4C3F8
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idAlignedEntity *__fastcall idEntityPtr<idAlignedEntity>::GetEntity(idEntityPtr<idAlignedEntity> *this)
{
  idAlignedEntity *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idAlignedEntity *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAlignedEntity::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidVolume@@@@QBAPAVidVolume@@XZ
// EA  : 0x82C621A0
// RVA : 0x00C621A0
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idVolume *__fastcall idEntityPtr<idVolume>::GetEntity(idEntityPtr<idVolume> *this)
{
  idVolume *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idVolume *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idVolume::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidDynamicEntity@@@@QBAPAVidDynamicEntity@@XZ
// EA  : 0x82C621E8
// RVA : 0x00C621E8
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idDynamicEntity *__fastcall idEntityPtr<idDynamicEntity>::GetEntity(idEntityPtr<idDynamicEntity> *this)
{
  idDynamicEntity *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idDynamicEntity *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idDynamicEntity::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidInfoGarageBay@@@@QBAPAVidInfoGarageBay@@XZ
// EA  : 0x82D1F2A0
// RVA : 0x00D1F2A0
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idInfoGarageBay *__fastcall idEntityPtr<idInfoGarageBay>::GetEntity(idEntityPtr<idInfoGarageBay> *this)
{
  idInfoGarageBay *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idInfoGarageBay *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idInfoGarageBay::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidDynamicWaterEntity@@@@QBAPAVidDynamicWaterEntity@@XZ
// EA  : 0x82D4D370
// RVA : 0x00D4D370
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idDynamicWaterEntity *__fastcall idEntityPtr<idDynamicWaterEntity>::GetEntity(idEntityPtr<idDynamicWaterEntity> *this)
{
  idDynamicWaterEntity *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idDynamicWaterEntity *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idDynamicWaterEntity::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidMover@@@@QBAPAVidMover@@XZ
// EA  : 0x82D59F80
// RVA : 0x00D59F80
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idMover *__fastcall idEntityPtr<idMover>::GetEntity(idEntityPtr<idMover> *this)
{
  idMover *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idMover *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idMover::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidLedge@@@@QBAPAVidLedge@@XZ
// EA  : 0x82E42C38
// RVA : 0x00E42C38
// PDB : w:\tech5\tungsten\game\entities\entityptr_impl.h
// ========================================================================

idLedge *__fastcall idEntityPtr<idLedge>::GetEntity(idEntityPtr<idLedge> *this)
{
  idLedge *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idLedge *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idLedge::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}

