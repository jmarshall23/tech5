
// ========================================================================
// ??0idDeclPonytail@@QAA@XZ
// EA  : 0x82622FF8
// RVA : 0x00622FF8
// PDB : w:\tech5\engine\decls\declponytail.h
// ========================================================================

idDeclPonytail *__fastcall idDeclPonytail::idDeclPonytail(idDeclPonytail *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->modelDef = nullptr;
  this->__vftable = (idDeclPonytail_vtbl *)&idDeclPonytail::`vftable';
  this->tagName.str = &byte_8200D768;
  this->jointInfo.granularity = 0;
  this->jointInfo.memTag = 30;
  this->jointInfo.listStatic = 0;
  this->jointInfo.list = nullptr;
  this->jointInfo.size = 0;
  this->jointInfo.num = 0;
  this->springInfo.list = nullptr;
  this->springInfo.granularity = 0;
  this->springInfo.memTag = 30;
  this->springInfo.listStatic = 0;
  this->springInfo.size = 0;
  this->springInfo.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->springInfo);
  return this;
}


// ========================================================================
// __unwind$224092
// EA  : 0x826230A4
// RVA : 0x006230A4
// PDB : w:\tech5\engine\decls\declponytail.h
// ========================================================================

void _unwind_224092()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$224093
// EA  : 0x826230CC
// RVA : 0x006230CC
// PDB : w:\tech5\engine\decls\declponytail.h
// ========================================================================

void _unwind_224093()
{
  int v0; // r12

  idList<idDeclSpecialEvent_Area::jobStinger_t,5>::~idList<idDeclSpecialEvent_Area::jobStinger_t,5>(this: (idList<idDeclPonytail::idPonytailJointInfo,30> *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ?GetDeclInfo@idDeclPonytail@@UBAPAVidDeclInfo@@XZ
// EA  : 0x826230F8
// RVA : 0x006230F8
// PDB : w:\tech5\engine\decls\declponytail.h
// ========================================================================

idDeclInfoTemplate<idDeclPonytail> *__fastcall idDeclPonytail::GetDeclInfo(idDeclPonytail *this)
{
  return &idDeclPonytail::resourceList;
}

