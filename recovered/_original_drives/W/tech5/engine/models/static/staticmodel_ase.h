
// ========================================================================
// ??0idASEMesh@@QAA@XZ
// EA  : 0x8287ADB0
// RVA : 0x0087ADB0
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

idASEMesh *__fastcall idASEMesh::idASEMesh(idASEMesh *this)
{
  this->vertexes.list = nullptr;
  this->vertexes.granularity = 0;
  this->vertexes.memTag = 5;
  this->vertexes.listStatic = 0;
  this->vertexes.size = 0;
  this->vertexes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertexes);
  this->tvertexes.list = nullptr;
  this->tvertexes.granularity = 0;
  this->tvertexes.memTag = 5;
  this->tvertexes.listStatic = 0;
  this->tvertexes.size = 0;
  this->tvertexes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tvertexes);
  this->cvertexes.list = nullptr;
  this->cvertexes.granularity = 0;
  this->cvertexes.memTag = 5;
  this->cvertexes.listStatic = 0;
  this->cvertexes.size = 0;
  this->cvertexes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cvertexes);
  this->timeValue = 0;
  this->numFaces = 0;
  this->numTVFaces = 0;
  this->numCVFaces = 0;
  this->transform[0].z = 0.0;
  this->transform[0].y = 0.0;
  this->transform[0].x = 0.0;
  this->transform[1].z = 0.0;
  this->transform[1].y = 0.0;
  this->transform[1].x = 0.0;
  this->transform[2].z = 0.0;
  this->transform[2].y = 0.0;
  this->transform[2].x = 0.0;
  this->transform[3].z = 0.0;
  this->transform[3].y = 0.0;
  this->transform[3].x = 0.0;
  this->colorsParsed = false;
  this->normalsParsed = false;
  this->faces = nullptr;
  return this;
}


// ========================================================================
// __unwind$222419_0
// EA  : 0x8287AEB0
// RVA : 0x0087AEB0
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222419_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 68));
}


// ========================================================================
// __unwind$222420
// EA  : 0x8287AEDC
// RVA : 0x0087AEDC
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222420()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 84));
}


// ========================================================================
// ??1idASEMesh@@QAA@XZ
// EA  : 0x8287AF10
// RVA : 0x0087AF10
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void __fastcall idASEMesh::~idASEMesh(idASEMesh *this)
{
  idMem::Free(this: &mem, ptr: this->faces, align: ALIGN_16);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cvertexes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tvertexes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertexes);
}


// ========================================================================
// __unwind$222486_0
// EA  : 0x8287AF74
// RVA : 0x0087AF74
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222486_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// __unwind$222487
// EA  : 0x8287AFA0
// RVA : 0x0087AFA0
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222487()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 84));
}


// ========================================================================
// ??0idASEObject@@QAA@XZ
// EA  : 0x8287AFD8
// RVA : 0x0087AFD8
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

idASEObject *__fastcall idASEObject::idASEObject(idASEObject *this)
{
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  idASEMesh::idASEMesh(this: &this->mesh);
  this->frames.list = nullptr;
  this->frames.granularity = 0;
  this->frames.memTag = 5;
  this->frames.listStatic = 0;
  this->frames.size = 0;
  this->frames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->frames);
  this->materialRef = 0;
  return this;
}


// ========================================================================
// __unwind$222665
// EA  : 0x8287B048
// RVA : 0x0087B048
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222665()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$222666
// EA  : 0x8287B070
// RVA : 0x0087B070
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222666()
{
  int v0; // r12

  idASEMesh::~idASEMesh(this: (idASEMesh *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// ??0encounter_t@vehicleAiSetup_t@@QAA@XZ
// EA  : 0x8287B0A8
// RVA : 0x0087B0A8
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

idASEModel *__fastcall vehicleAiSetup_t::encounter_t::encounter_t(idASEModel *this)
{
  this->materials.list = nullptr;
  this->materials.granularity = 0;
  this->materials.memTag = 5;
  this->materials.listStatic = 0;
  this->materials.size = 0;
  this->materials.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->objects.list = nullptr;
  this->objects.granularity = 0;
  this->objects.memTag = 5;
  this->objects.listStatic = 0;
  this->objects.size = 0;
  this->objects.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->objects);
  return this;
}


// ========================================================================
// __unwind$222715
// EA  : 0x8287B110
// RVA : 0x0087B110
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222715()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idASEObject@@QAA@XZ
// EA  : 0x8287B1F8
// RVA : 0x0087B1F8
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void __fastcall idASEObject::~idASEObject(idASEObject *this)
{
  idList<idVehicleState *,5> *p_frames; // r29

  p_frames = (idList<idVehicleState *,5> *)&this->frames;
  idList<idASEMesh *,5>::DeleteContents(this: &this->frames);
  idList<idThread *,58>::Clear(this: p_frames);
  idASEMesh::~idASEMesh(this: &this->mesh);
  idStr::FreeData(this: &this->name);
}


// ========================================================================
// __unwind$222907
// EA  : 0x8287B23C
// RVA : 0x0087B23C
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222907()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$222908
// EA  : 0x8287B264
// RVA : 0x0087B264
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222908()
{
  int v0; // r12

  idASEMesh::~idASEMesh(this: (idASEMesh *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$222909
// EA  : 0x8287B290
// RVA : 0x0087B290
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_222909()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 156));
}


// ========================================================================
// ??1idASEModel@@QAA@XZ
// EA  : 0x8287C590
// RVA : 0x0087C590
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void __fastcall idASEModel::~idASEModel(idASEModel *this)
{
  idList<idVarDefName *,58>::DeleteContents((idList<idMapBrushSide *,5> *)this);
  idList<idASEObject *,5>::DeleteContents(this: &this->objects);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->objects);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$223317
// EA  : 0x8287C5D0
// RVA : 0x0087C5D0
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_223317()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$223318
// EA  : 0x8287C5F8
// RVA : 0x0087C5F8
// PDB : w:\tech5\engine\models\static\staticmodel_ase.h
// ========================================================================

void _unwind_223318()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}

