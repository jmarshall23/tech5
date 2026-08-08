
// ========================================================================
// ?GetDeclInfo@idDeclParticle@@UBAPAVidDeclInfo@@XZ
// EA  : 0x827E1840
// RVA : 0x007E1840
// PDB : w:\tech5\engine\models\particles\declparticle.h
// ========================================================================

idDeclInfoTemplate<idDeclParticle> *__fastcall idDeclParticle::GetDeclInfo(idDeclParticle *this)
{
  return &idDeclParticle::resourceList;
}


// ========================================================================
// ??1idDeclParticle@@UAA@XZ
// EA  : 0x827E44F0
// RVA : 0x007E44F0
// PDB : w:\tech5\engine\models\particles\declparticle.h
// ========================================================================

void __fastcall idDeclParticle::~idDeclParticle(idDeclParticle *this)
{
  this->__vftable = (idDeclParticle_vtbl *)&idDeclParticle::`vftable';
  idDeclParticle::FreeData(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tables);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tableDecls);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stageInheritNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stageNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stages);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$228225
// EA  : 0x827E4568
// RVA : 0x007E4568
// PDB : w:\tech5\engine\models\particles\declparticle.h
// ========================================================================

void _unwind_228225()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$228226
// EA  : 0x827E4590
// RVA : 0x007E4590
// PDB : w:\tech5\engine\models\particles\declparticle.h
// ========================================================================

void _unwind_228226()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$228227
// EA  : 0x827E45BC
// RVA : 0x007E45BC
// PDB : w:\tech5\engine\models\particles\declparticle.h
// ========================================================================

void _unwind_228227()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$228228
// EA  : 0x827E45E8
// RVA : 0x007E45E8
// PDB : w:\tech5\engine\models\particles\declparticle.h
// ========================================================================

void _unwind_228228()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// __unwind$228229
// EA  : 0x827E4614
// RVA : 0x007E4614
// PDB : w:\tech5\engine\models\particles\declparticle.h
// ========================================================================

void _unwind_228229()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// __unwind$228230
// EA  : 0x827E4640
// RVA : 0x007E4640
// PDB : w:\tech5\engine\models\particles\declparticle.h
// ========================================================================

void _unwind_228230()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 120));
}

