
// ========================================================================
// ??1idPVS@@UAA@XZ
// EA  : 0x8276AA00
// RVA : 0x0076AA00
// PDB : w:\tech5\engine\gamelib\pvs\pvs.h
// ========================================================================

void __fastcall idPVS::~idPVS(idPVS *this)
{
  this->__vftable = (idPVS_vtbl *)&idPVS::`vftable';
  idPVS::Free(this);
  idStr::FreeData(this: &this->pvsName);
}


// ========================================================================
// __unwind$246836
// EA  : 0x8276AA50
// RVA : 0x0076AA50
// PDB : w:\tech5\engine\gamelib\pvs\pvs.h
// ========================================================================

void _unwind_246836()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}

