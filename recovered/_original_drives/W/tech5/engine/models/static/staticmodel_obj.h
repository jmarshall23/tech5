
// ========================================================================
// ??0idOBJModel@@QAA@XZ
// EA  : 0x82870E30
// RVA : 0x00870E30
// PDB : w:\tech5\engine\models\static\staticmodel_obj.h
// ========================================================================

idOBJModel *__fastcall idOBJModel::idOBJModel(idOBJModel *this)
{
  this->materials.granularity = 0;
  this->materials.memTag = 5;
  this->materials.listStatic = 0;
  this->materials.list = nullptr;
  this->materials.size = 0;
  this->materials.num = 0;
  this->v.list = nullptr;
  this->v.granularity = 0;
  this->v.memTag = 5;
  this->v.listStatic = 0;
  this->v.size = 0;
  this->v.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->v);
  this->mrgb.list = nullptr;
  this->mrgb.granularity = 0;
  this->mrgb.memTag = 5;
  this->mrgb.listStatic = 0;
  this->mrgb.size = 0;
  this->mrgb.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mrgb);
  this->vt.list = nullptr;
  this->vt.granularity = 0;
  this->vt.memTag = 5;
  this->vt.listStatic = 0;
  this->vt.size = 0;
  this->vt.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vt);
  this->vn.list = nullptr;
  this->vn.granularity = 0;
  this->vn.memTag = 5;
  this->vn.listStatic = 0;
  this->vn.size = 0;
  this->vn.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vn);
  this->meshes.granularity = 0;
  this->meshes.memTag = 5;
  this->meshes.listStatic = 0;
  this->meshes.list = nullptr;
  this->meshes.size = 0;
  this->meshes.num = 0;
  return this;
}


// ========================================================================
// __unwind$244081
// EA  : 0x82870F14
// RVA : 0x00870F14
// PDB : w:\tech5\engine\models\static\staticmodel_obj.h
// ========================================================================

void _unwind_244081()
{
  int v0; // r12

  idList<idParsedMtl,5>::~idList<idParsedMtl,5>(this: *(idList<idParsedMtl,5> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$244082
// EA  : 0x82870F3C
// RVA : 0x00870F3C
// PDB : w:\tech5\engine\models\static\staticmodel_obj.h
// ========================================================================

void _unwind_244082()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$244083
// EA  : 0x82870F68
// RVA : 0x00870F68
// PDB : w:\tech5\engine\models\static\staticmodel_obj.h
// ========================================================================

void _unwind_244083()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// __unwind$244084
// EA  : 0x82870F94
// RVA : 0x00870F94
// PDB : w:\tech5\engine\models\static\staticmodel_obj.h
// ========================================================================

void _unwind_244084()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// __unwind$244085
// EA  : 0x82870FC0
// RVA : 0x00870FC0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.h
// ========================================================================

void _unwind_244085()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}

