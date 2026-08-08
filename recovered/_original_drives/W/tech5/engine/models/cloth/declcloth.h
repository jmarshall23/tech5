
// ========================================================================
// ?GetDeclInfo@idDeclCloth@@UBAPAVidDeclInfo@@XZ
// EA  : 0x827ABEB0
// RVA : 0x007ABEB0
// PDB : w:\tech5\engine\models\cloth\declcloth.h
// ========================================================================

idDeclInfoTemplate<idDeclCloth> *__fastcall idDeclCloth::GetDeclInfo(idDeclCloth *this)
{
  return &idDeclCloth::resourceList;
}


// ========================================================================
// ??1idDeclCloth@@UAA@XZ
// EA  : 0x827ABF98
// RVA : 0x007ABF98
// PDB : w:\tech5\engine\models\cloth\declcloth.h
// ========================================================================

void __fastcall idDeclCloth::~idDeclCloth(idDeclCloth *this)
{
  idDeclCloth::ropeInfo *list; // r3
  idDeclCloth::ropeInfo *v3; // r3

  this->__vftable = (idDeclCloth_vtbl *)&idDeclCloth::`vftable';
  if ( this->ropeData.listStatic == 0 || this->ropeData.listStatic == 2 )
  {
    list = this->ropeData.list;
    if ( list != nullptr )
      idListArrayDelete<idDeclCloth::ropeInfo>(ptr: list, num: this->ropeData.size);
    this->ropeData.list = nullptr;
    this->ropeData.size = 0;
  }
  this->ropeData.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->springData);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->particleData);
  if ( this->ropeData.listStatic == 0 || this->ropeData.listStatic == 2 )
  {
    v3 = this->ropeData.list;
    if ( v3 != nullptr )
      idListArrayDelete<idDeclCloth::ropeInfo>(ptr: v3, num: this->ropeData.size);
    this->ropeData.list = nullptr;
    this->ropeData.size = 0;
  }
  this->ropeData.num = 0;
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$221898
// EA  : 0x827AC048
// RVA : 0x007AC048
// PDB : w:\tech5\engine\models\cloth\declcloth.h
// ========================================================================

void _unwind_221898()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$221899
// EA  : 0x827AC070
// RVA : 0x007AC070
// PDB : w:\tech5\engine\models\cloth\declcloth.h
// ========================================================================

void _unwind_221899()
{
  int v0; // r12

  idList<idDeclCloth::ropeInfo,5>::~idList<idDeclCloth::ropeInfo,5>(this: (idList<idDeclCloth::ropeInfo,5> *)(*(_DWORD *)(v0 - 112 + 132) + 124));
}


// ========================================================================
// __unwind$221900
// EA  : 0x827AC09C
// RVA : 0x007AC09C
// PDB : w:\tech5\engine\models\cloth\declcloth.h
// ========================================================================

void _unwind_221900()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 140));
}


// ========================================================================
// __unwind$221901
// EA  : 0x827AC0C8
// RVA : 0x007AC0C8
// PDB : w:\tech5\engine\models\cloth\declcloth.h
// ========================================================================

void _unwind_221901()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 156));
}

