
// ========================================================================
// ?GetDeclInfo@idDeclVehicleUnlock@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCC2E0
// RVA : 0x00BCC2E0
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleUnlock> *__fastcall idDeclVehicleUnlock::GetDeclInfo(idDeclVehicleUnlock *this)
{
  return &idDeclVehicleUnlock::resourceList;
}


// ========================================================================
// ??1idDeclVehicleUnlock@@UAA@XZ
// EA  : 0x82BCC2F8
// RVA : 0x00BCC2F8
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.h
// ========================================================================

void __fastcall idDeclVehicleUnlock::~idDeclVehicleUnlock(idDeclVehicleUnlock *this)
{
  idDeclVehicleUnlock::inventoryUnlock_t *list; // r3

  this->__vftable = (idDeclVehicleUnlock_vtbl *)&idDeclVehicleUnlock::`vftable';
  if ( this->items.listStatic == 0 || this->items.listStatic == 2 )
  {
    list = this->items.list;
    if ( list != nullptr )
      idListArrayDelete<idDeclVehicleUnlock::inventoryUnlock_t>(ptr: (testReportField_t *)list, num: this->items.size);
    this->items.list = nullptr;
    this->items.size = 0;
  }
  this->items.num = 0;
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$488670
// EA  : 0x82BCC364
// RVA : 0x00BCC364
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.h
// ========================================================================

void _unwind_488670()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}

