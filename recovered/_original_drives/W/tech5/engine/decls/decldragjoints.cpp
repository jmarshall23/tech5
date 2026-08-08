
// ========================================================================
// ??0idDeclDragJoints@@QAA@XZ
// EA  : 0x826182E0
// RVA : 0x006182E0
// PDB : w:\tech5\engine\decls\decldragjoints.cpp
// ========================================================================

idDeclDragJoints *__fastcall idDeclDragJoints::idDeclDragJoints(idDeclDragJoints *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclDragJoints_vtbl *)&idDeclDragJoints::`vftable';
  this->baseJoint.len = 0;
  this->baseJoint.allocedAndFlag = 20;
  this->baseJoint.data = this->baseJoint.baseBuffer;
  this->baseJoint.baseBuffer[0] = 0;
  this->joints.granularity = 0;
  this->joints.listStatic = 0;
  this->joints.memTag = 5;
  this->joints.list = nullptr;
  this->joints.size = 0;
  this->joints.num = 0;
  this->subWebs.granularity = 0;
  this->subWebs.memTag = 5;
  this->subWebs.listStatic = 0;
  this->subWebs.list = nullptr;
  this->subWebs.size = 0;
  this->subWebs.num = 0;
  this->ghostJointDistance = 16.0;
  return this;
}


// ========================================================================
// __unwind$219278
// EA  : 0x82618398
// RVA : 0x00618398
// PDB : w:\tech5\engine\decls\decldragjoints.cpp
// ========================================================================

void _unwind_219278()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$219279
// EA  : 0x826183C0
// RVA : 0x006183C0
// PDB : w:\tech5\engine\decls\decldragjoints.cpp
// ========================================================================

void _unwind_219279()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// __unwind$219280
// EA  : 0x826183EC
// RVA : 0x006183EC
// PDB : w:\tech5\engine\decls\decldragjoints.cpp
// ========================================================================

void _unwind_219280()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// ??1idDeclDragJoints@@UAA@XZ
// EA  : 0x82618430
// RVA : 0x00618430
// PDB : w:\tech5\engine\decls\decldragjoints.cpp
// ========================================================================

void __fastcall idDeclDragJoints::~idDeclDragJoints(idDeclDragJoints *this)
{
  idStr *list; // r3
  idJointName *v3; // r3

  this->__vftable = (idDeclDragJoints_vtbl *)&idDeclDragJoints::`vftable';
  if ( this->subWebs.listStatic == 0 || this->subWebs.listStatic == 2 )
  {
    list = this->subWebs.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->subWebs.size);
    this->subWebs.list = nullptr;
    this->subWebs.size = 0;
  }
  this->subWebs.num = 0;
  if ( this->joints.listStatic == 0 || this->joints.listStatic == 2 )
  {
    v3 = this->joints.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->joints.size);
    this->joints.list = nullptr;
    this->joints.size = 0;
  }
  this->joints.num = 0;
  idStr::FreeData(this: &this->baseJoint);
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$219375
// EA  : 0x826184D8
// RVA : 0x006184D8
// PDB : w:\tech5\engine\decls\decldragjoints.cpp
// ========================================================================

void _unwind_219375()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$219376
// EA  : 0x82618500
// RVA : 0x00618500
// PDB : w:\tech5\engine\decls\decldragjoints.cpp
// ========================================================================

void _unwind_219376()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// __unwind$219377
// EA  : 0x8261852C
// RVA : 0x0061852C
// PDB : w:\tech5\engine\decls\decldragjoints.cpp
// ========================================================================

void _unwind_219377()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}

