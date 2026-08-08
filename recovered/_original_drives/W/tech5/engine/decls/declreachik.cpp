
// ========================================================================
// ??0idDeclReachIK@@QAA@XZ
// EA  : 0x826298A8
// RVA : 0x006298A8
// PDB : w:\tech5\engine\decls\declreachik.cpp
// ========================================================================

idDeclReachIK *__fastcall idDeclReachIK::idDeclReachIK(idDeclReachIK *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclReachIK_vtbl *)&idDeclReachIK::`vftable';
  this->armInfo.granularity = 0;
  this->armInfo.memTag = 83;
  this->armInfo.listStatic = 0;
  this->armInfo.list = nullptr;
  this->armInfo.size = 0;
  this->armInfo.num = 0;
  return this;
}


// ========================================================================
// __unwind$219791
// EA  : 0x82629918
// RVA : 0x00629918
// PDB : w:\tech5\engine\decls\declreachik.cpp
// ========================================================================

void _unwind_219791()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDeclReachIK@@UAA@XZ
// EA  : 0x82629958
// RVA : 0x00629958
// PDB : w:\tech5\engine\decls\declreachik.cpp
// ========================================================================

void __fastcall idDeclReachIK::~idDeclReachIK(idDeclReachIK *this)
{
  idIKArm *list; // r3

  this->__vftable = (idDeclReachIK_vtbl *)&idDeclReachIK::`vftable';
  if ( this->armInfo.listStatic == 0 || this->armInfo.listStatic == 2 )
  {
    list = this->armInfo.list;
    if ( list != nullptr )
      idListArrayDelete<idPlaytestStorage::ai2FSMStateInfo_t>(ptr: (testReportField_t *)list, num: this->armInfo.size);
    this->armInfo.list = nullptr;
    this->armInfo.size = 0;
  }
  this->armInfo.num = 0;
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$219825
// EA  : 0x826299C4
// RVA : 0x006299C4
// PDB : w:\tech5\engine\decls\declreachik.cpp
// ========================================================================

void _unwind_219825()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?FreeData@idDeclReachIK@@UAAXXZ
// EA  : 0x82629A50
// RVA : 0x00629A50
// PDB : w:\tech5\engine\decls\declreachik.cpp
// ========================================================================

void __fastcall idDeclReachIK::FreeData(idDeclReachIK *this)
{
  idList<idIKArm,83> *p_armInfo; // r31

  p_armInfo = &this->armInfo;
  if ( this->armInfo.size < 0 )
    idList<idPlaytestStorage::ai2FSMStateInfo_t,5>::Clear(this: (idList<idPlaytestStorage::ai2FSMStateInfo_t,5> *)&this->armInfo);
  p_armInfo->num = __CFADD__(-p_armInfo->size, p_armInfo->size ^ 0x80000000) ? 0 : p_armInfo->size;
}

