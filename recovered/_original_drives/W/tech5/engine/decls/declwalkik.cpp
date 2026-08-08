
// ========================================================================
// ??1idDeclWalkIK@@UAA@XZ
// EA  : 0x8262C028
// RVA : 0x0062C028
// PDB : w:\tech5\engine\decls\declwalkik.cpp
// ========================================================================

void __fastcall idDeclWalkIK::~idDeclWalkIK(idDeclWalkIK *this)
{
  this->__vftable = (idDeclWalkIK_vtbl *)&idDeclWalkIK::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->legJoints);
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$219333
// EA  : 0x8262C07C
// RVA : 0x0062C07C
// PDB : w:\tech5\engine\decls\declwalkik.cpp
// ========================================================================

void _unwind_219333()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?FreeData@idDeclWalkIK@@UAAXXZ
// EA  : 0x8262C118
// RVA : 0x0062C118
// PDB : w:\tech5\engine\decls\declwalkik.cpp
// ========================================================================

void __fastcall idDeclWalkIK::FreeData(idDeclWalkIK *this)
{
  idList<idIKLeg,83> *p_legJoints; // r30

  p_legJoints = &this->legJoints;
  if ( this->legJoints.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->legJoints);
  p_legJoints->num = __CFADD__(-p_legJoints->size, p_legJoints->size ^ 0x80000000) ? 0 : p_legJoints->size;
  this->kneeDir.x = 1.0;
  this->kneeDir.y = 0.0;
  this->kneeDir.z = 0.0;
  this->usePivot = false;
  this->dirsFromBasePose = false;
  this->restrictToBounds = false;
  this->checkFeetForSolids = false;
  this->smoothing = 0.75;
  this->waistSmoothing = 0.5;
  this->stairSmoothing = 0.85000002;
  this->stairWaistSmoothing = 0.75;
  this->footSmoothing = 0.0;
  this->footShift = 0.0;
  this->waistShift = 0.0;
  this->minWaistFloorDist = 0.0;
  this->minWaistAnkleDist = 0.0;
  this->footSize = 4.0;
  this->footUpTrace = 32.0;
  this->footDownTrace = 32.0;
  this->footDownTraceDead = 256.0;
  this->restrictToBoundsTolerance = 0.0;
}


// ========================================================================
// ??0idDeclWalkIK@@QAA@XZ
// EA  : 0x8262C220
// RVA : 0x0062C220
// PDB : w:\tech5\engine\decls\declwalkik.cpp
// ========================================================================

idDeclWalkIK *__fastcall idDeclWalkIK::idDeclWalkIK(idDeclWalkIK *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclWalkIK_vtbl *)&idDeclWalkIK::`vftable';
  this->legJoints.list = nullptr;
  this->legJoints.granularity = 0;
  this->legJoints.memTag = 83;
  this->legJoints.listStatic = 0;
  this->legJoints.size = 0;
  this->legJoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->legJoints);
  this->waistJoint.str = &byte_8200D768;
  idDeclWalkIK::FreeData(this);
  return this;
}


// ========================================================================
// __unwind$219559
// EA  : 0x8262C2B0
// RVA : 0x0062C2B0
// PDB : w:\tech5\engine\decls\declwalkik.cpp
// ========================================================================

void _unwind_219559()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$219560
// EA  : 0x8262C2D8
// RVA : 0x0062C2D8
// PDB : w:\tech5\engine\decls\declwalkik.cpp
// ========================================================================

void _unwind_219560()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}

