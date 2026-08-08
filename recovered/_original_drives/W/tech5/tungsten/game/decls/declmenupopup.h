
// ========================================================================
// ?GetDeclInfo@idDeclMenuPopup@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC8688
// RVA : 0x00BC8688
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.h
// ========================================================================

idDeclInfoTemplate<idDeclMenuPopup> *__fastcall idDeclMenuPopup::GetDeclInfo(idDeclMenuPopup *this)
{
  return &idDeclMenuPopup::resourceList;
}


// ========================================================================
// ??1idDeclMenuPopup@@UAA@XZ
// EA  : 0x82BC86A0
// RVA : 0x00BC86A0
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.h
// ========================================================================

void __fastcall idDeclMenuPopup::~idDeclMenuPopup(idDeclMenuPopup *this)
{
  this->__vftable = (idDeclMenuPopup_vtbl *)&idDeclMenuPopup::`vftable';
  idStr::FreeData(this: &this->fileName);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$487338
// EA  : 0x82BC86F4
// RVA : 0x00BC86F4
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.h
// ========================================================================

void _unwind_487338()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idDeclCredits@@QAA@XZ
// EA  : 0x82BD5C98
// RVA : 0x00BD5C98
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.h
// ========================================================================

idDeclCredits *__fastcall idDeclCredits::idDeclCredits(idDeclCredits *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclCredits_vtbl *)&idDeclCredits::`vftable';
  this->creditList.granularity = 0;
  this->creditList.memTag = 5;
  this->creditList.listStatic = 0;
  this->creditList.list = nullptr;
  this->creditList.size = 0;
  this->creditList.num = 0;
  return this;
}


// ========================================================================
// __unwind$503929
// EA  : 0x82BD5D08
// RVA : 0x00BD5D08
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.h
// ========================================================================

void _unwind_503929()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetDeclInfo@idDeclCredits@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD5D30
// RVA : 0x00BD5D30
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.h
// ========================================================================

idDeclInfoTemplate<idDeclCredits> *__fastcall idDeclCredits::GetDeclInfo(idDeclCredits *this)
{
  return &idDeclCredits::resourceList;
}


// ========================================================================
// ??1idDeclCredits@@UAA@XZ
// EA  : 0x82BD5D48
// RVA : 0x00BD5D48
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.h
// ========================================================================

void __fastcall idDeclCredits::~idDeclCredits(idDeclCredits *this)
{
  char *list; // r3

  this->__vftable = (idDeclCredits_vtbl *)&idDeclCredits::`vftable';
  if ( this->creditList.listStatic == 0 || this->creditList.listStatic == 2 )
  {
    list = (char *)this->creditList.list;
    if ( list != nullptr )
      idListArrayDelete<idDeclCredits::creditInfo_t const>(ptr: list, num: this->creditList.size);
    this->creditList.list = nullptr;
    this->creditList.size = 0;
  }
  this->creditList.num = 0;
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$503961
// EA  : 0x82BD5DB4
// RVA : 0x00BD5DB4
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.h
// ========================================================================

void _unwind_503961()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}

