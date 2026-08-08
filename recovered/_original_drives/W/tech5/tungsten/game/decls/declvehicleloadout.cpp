
// ========================================================================
// ??0idDeclVehicleLoadout@@QAA@XZ
// EA  : 0x82BCBCF8
// RVA : 0x00BCBCF8
// PDB : w:\tech5\tungsten\game\decls\declvehicleloadout.cpp
// ========================================================================

idDeclVehicleLoadout *__fastcall idDeclVehicleLoadout::idDeclVehicleLoadout(idDeclVehicleLoadout *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclVehicleLoadout_vtbl *)&idDeclVehicleLoadout::`vftable';
  this->desc.index = -1;
  this->vehicleClass = nullptr;
  this->vehicle = nullptr;
  this->weaponPrimary = nullptr;
  this->weaponSecondary = nullptr;
  this->quickUse1 = nullptr;
  this->quickUse2 = nullptr;
  this->isDefault = false;
  this->order = 0;
  return this;
}


// ========================================================================
// `dynamic initializer for 'idDeclVehicleLoadout::defaultLoadouts''
// EA  : 0x83372428
// RVA : 0x01372428
// PDB : w:\tech5\tungsten\game\decls\declvehicleloadout.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDeclVehicleLoadout::defaultLoadouts__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDeclVehicleLoadout::defaultLoadouts__);
}

