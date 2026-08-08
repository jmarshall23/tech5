
// ========================================================================
// ??0idIESfile@@QAA@XZ
// EA  : 0x828C1150
// RVA : 0x008C1150
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

idIESfile *__fastcall idIESfile::idIESfile(idIESfile *this)
{
  idResource::idResource(this: &this->idResource);
  this->__vftable = (idIESfile_vtbl *)&idIESfile::`vftable';
  this->factorAngles.list = nullptr;
  this->factorAngles.granularity = 0;
  this->factorAngles.memTag = 5;
  this->factorAngles.listStatic = 0;
  this->factorAngles.size = 0;
  this->factorAngles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->factorAngles);
  this->factorScales.list = nullptr;
  this->factorScales.granularity = 0;
  this->factorScales.memTag = 5;
  this->factorScales.listStatic = 0;
  this->factorScales.size = 0;
  this->factorScales.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->factorScales);
  this->verticalAngles.list = nullptr;
  this->verticalAngles.granularity = 0;
  this->verticalAngles.memTag = 5;
  this->verticalAngles.listStatic = 0;
  this->verticalAngles.size = 0;
  this->verticalAngles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->verticalAngles);
  this->horizontalAngles.list = nullptr;
  this->horizontalAngles.granularity = 0;
  this->horizontalAngles.memTag = 5;
  this->horizontalAngles.listStatic = 0;
  this->horizontalAngles.size = 0;
  this->horizontalAngles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->horizontalAngles);
  this->candela.list = nullptr;
  this->candela.granularity = 0;
  this->candela.memTag = 5;
  this->candela.listStatic = 0;
  this->candela.size = 0;
  this->candela.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->candela);
  this->editorModelName.len = 0;
  this->editorModelName.allocedAndFlag = 20;
  this->editorModelName.data = this->editorModelName.baseBuffer;
  this->editorModelName.baseBuffer[0] = 0;
  this->editorModel = nullptr;
  return this;
}


// ========================================================================
// __unwind$221197
// EA  : 0x828C124C
// RVA : 0x008C124C
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221197()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$221198
// EA  : 0x828C1274
// RVA : 0x008C1274
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221198()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// __unwind$221199
// EA  : 0x828C12A0
// RVA : 0x008C12A0
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221199()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// __unwind$221200
// EA  : 0x828C12CC
// RVA : 0x008C12CC
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221200()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 132));
}


// ========================================================================
// __unwind$221201
// EA  : 0x828C12F8
// RVA : 0x008C12F8
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221201()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 148));
}


// ========================================================================
// ?GetResourceList@idIESfile@@UBAPAVidResourceList@@XZ
// EA  : 0x828C1328
// RVA : 0x008C1328
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

idTypedResourceList<idIESfile> *__fastcall idIESfile::GetResourceList(idIESfile *this)
{
  return &idIESfile::resourceList;
}


// ========================================================================
// ??1idIESfile@@UAA@XZ
// EA  : 0x828C1340
// RVA : 0x008C1340
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void __fastcall idIESfile::~idIESfile(idIESfile *this)
{
  this->__vftable = (idIESfile_vtbl *)&idIESfile::`vftable';
  idStr::FreeData(this: &this->editorModelName);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->candela);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->horizontalAngles);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->verticalAngles);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->factorScales);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->factorAngles);
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$221290
// EA  : 0x828C13BC
// RVA : 0x008C13BC
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221290()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$221291
// EA  : 0x828C13E4
// RVA : 0x008C13E4
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221291()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$221292
// EA  : 0x828C1410
// RVA : 0x008C1410
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221292()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// __unwind$221293
// EA  : 0x828C143C
// RVA : 0x008C143C
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221293()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 132));
}


// ========================================================================
// __unwind$221294
// EA  : 0x828C1468
// RVA : 0x008C1468
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221294()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 148));
}


// ========================================================================
// __unwind$221295
// EA  : 0x828C1494
// RVA : 0x008C1494
// PDB : w:\tech5\engine\renderer\iesfile.h
// ========================================================================

void _unwind_221295()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}

