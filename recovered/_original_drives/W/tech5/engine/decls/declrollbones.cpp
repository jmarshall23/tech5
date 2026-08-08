
// ========================================================================
// ??0idDeclRollBones@@QAA@XZ
// EA  : 0x82629C48
// RVA : 0x00629C48
// PDB : w:\tech5\engine\decls\declrollbones.cpp
// ========================================================================

idDeclRollBones *__fastcall idDeclRollBones::idDeclRollBones(idDeclRollBones *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclRollBones_vtbl *)&idDeclRollBones::`vftable';
  this->rollBones.granularity = 0;
  this->rollBones.memTag = 5;
  this->rollBones.listStatic = 0;
  this->rollBones.list = nullptr;
  this->rollBones.size = 0;
  this->rollBones.num = 0;
  return this;
}


// ========================================================================
// __unwind$219161
// EA  : 0x82629CB8
// RVA : 0x00629CB8
// PDB : w:\tech5\engine\decls\declrollbones.cpp
// ========================================================================

void _unwind_219161()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDeclRollBones@@UAA@XZ
// EA  : 0x82629CF8
// RVA : 0x00629CF8
// PDB : w:\tech5\engine\decls\declrollbones.cpp
// ========================================================================

void __fastcall idDeclRollBones::~idDeclRollBones(idDeclRollBones *this)
{
  idDeclRollBones::idDeclRollBoneInstance *list; // r3

  this->__vftable = (idDeclRollBones_vtbl *)&idDeclRollBones::`vftable';
  if ( this->rollBones.listStatic == 0 || this->rollBones.listStatic == 2 )
  {
    list = this->rollBones.list;
    if ( list != nullptr )
      idListArrayDelete<idDeclRollBones::idDeclRollBoneInstance>(ptr: list, num: this->rollBones.size);
    this->rollBones.list = nullptr;
    this->rollBones.size = 0;
  }
  this->rollBones.num = 0;
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$219195
// EA  : 0x82629D64
// RVA : 0x00629D64
// PDB : w:\tech5\engine\decls\declrollbones.cpp
// ========================================================================

void _unwind_219195()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}

