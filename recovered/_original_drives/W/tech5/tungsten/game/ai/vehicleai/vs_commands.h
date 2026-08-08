
// ========================================================================
// ??0idVS_cs_TravelTilDead@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x824FB5B0
// RVA : 0x004FB5B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.h
// ========================================================================

idVS_cs_TravelTilDead *__fastcall idVS_cs_TravelTilDead::idVS_cs_TravelTilDead(
        idVS_cs_TravelTilDead *this,
        const idTypeInfo *stateType)
{
  idVehicleState::idVehicleState(this, stateType);
  this->__vftable = (idVS_cs_TravelTilDead_vtbl *)&idVS_cs_TravelTilDead::`vftable';
  this->mTravelGoal.navSpline = nullptr;
  this->mTravelGoal.distance = 0.0;
  this->mTravelGoal.rightDistance = 0.0;
  this->mOccupants.list = nullptr;
  this->mOccupants.granularity = 0;
  this->mOccupants.memTag = 5;
  this->mOccupants.listStatic = 0;
  this->mOccupants.size = 0;
  this->mOccupants.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mOccupants);
  this->mTravelSpeed = 0.0;
  this->mWasMissingOccupant = false;
  this->mIsStoppingGoal = false;
  return this;
}


// ========================================================================
// __unwind$584916
// EA  : 0x824FB63C
// RVA : 0x004FB63C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.h
// ========================================================================

void _unwind_584916()
{
  int v0; // r12

  idVehicleState::~idVehicleState(this: *(idVehicleState **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idVS_cs_Travel@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x8253D888
// RVA : 0x0053D888
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.h
// ========================================================================

idVS_cs_Travel *__fastcall idVS_cs_Travel::idVS_cs_Travel(idVS_cs_Travel *this, const idTypeInfo *stateType)
{
  idVehicleState::idVehicleState(this, stateType);
  this->__vftable = (idVS_cs_Travel_vtbl *)&idVS_cs_Travel::`vftable';
  this->mTravelGoal.navSpline = nullptr;
  this->mTravelGoal.distance = 0.0;
  this->mTravelGoal.rightDistance = 0.0;
  this->mOccupants.list = nullptr;
  this->mOccupants.granularity = 0;
  this->mOccupants.memTag = 5;
  this->mOccupants.listStatic = 0;
  this->mOccupants.size = 0;
  this->mOccupants.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mOccupants);
  this->mTravelSpeed = 0.0;
  this->mWasMissingOccupant = false;
  this->mIsStoppingGoal = false;
  return this;
}


// ========================================================================
// __unwind$582784
// EA  : 0x8253D914
// RVA : 0x0053D914
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_commands.h
// ========================================================================

void _unwind_582784()
{
  int v0; // r12

  idVehicleState::~idVehicleState(this: *(idVehicleState **)(v0 - 128 + 148));
}

