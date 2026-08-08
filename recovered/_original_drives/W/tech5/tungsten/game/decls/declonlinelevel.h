
// ========================================================================
// ?GetDeclInfo@idDeclOnlineLevel@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCA5D8
// RVA : 0x00BCA5D8
// PDB : w:\tech5\tungsten\game\decls\declonlinelevel.h
// ========================================================================

idDeclInfoTemplate<idDeclOnlineLevel> *__fastcall idDeclOnlineLevel::GetDeclInfo(idDeclOnlineLevel *this)
{
  return &idDeclOnlineLevel::resourceList;
}


// ========================================================================
// ??1idDeclOnlineLevel@@UAA@XZ
// EA  : 0x82BCA650
// RVA : 0x00BCA650
// PDB : w:\tech5\tungsten\game\decls\declonlinelevel.h
// ========================================================================

void __fastcall idDeclOnlineLevel::~idDeclOnlineLevel(idDeclOnlineLevel *this)
{
  this->__vftable = (idDeclOnlineLevel_vtbl *)&idDeclOnlineLevel::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->levelList);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$487633
// EA  : 0x82BCA6A4
// RVA : 0x00BCA6A4
// PDB : w:\tech5\tungsten\game\decls\declonlinelevel.h
// ========================================================================

void _unwind_487633()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}

