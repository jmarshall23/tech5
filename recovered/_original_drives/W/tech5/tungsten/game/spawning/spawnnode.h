
// ========================================================================
// ??0idSpawnNodeSplines@@QAA@XZ
// EA  : 0x824FBEA8
// RVA : 0x004FBEA8
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

idSpawnNodeSplines *__fastcall idSpawnNodeSplines::idSpawnNodeSplines(idSpawnNodeSplines *this)
{
  idEntity::idEntity(this);
  this->nodeType = TYPE_STANDARD;
  this->team = TEAM_NONE;
  this->isActive = true;
  this->initial = false;
  this->__vftable = (idSpawnNodeSplines_vtbl *)&idSpawnNodeSplines::`vftable';
  this->splinePaths.list = nullptr;
  this->splinePaths.granularity = 0;
  this->splinePaths.memTag = 5;
  this->splinePaths.listStatic = 0;
  this->splinePaths.size = 0;
  this->splinePaths.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splinePaths);
  this->splineCurves.list = nullptr;
  this->splineCurves.granularity = 0;
  this->splineCurves.memTag = 5;
  this->splineCurves.listStatic = 0;
  this->splineCurves.size = 0;
  this->splineCurves.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineCurves);
  this->totalLocationCount = 0;
  return this;
}


// ========================================================================
// __unwind$585813
// EA  : 0x824FBF3C
// RVA : 0x004FBF3C
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

void _unwind_585813()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$585814
// EA  : 0x824FBF64
// RVA : 0x004FBF64
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

void _unwind_585814()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 816));
}


// ========================================================================
// ?GetApproximateLocationCount@idSpawnNodeSplines@@UBAHXZ
// EA  : 0x824FBF90
// RVA : 0x004FBF90
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

int __fastcall idSpawnNodeSplines::GetApproximateLocationCount(idSpawnNodeSplines *this)
{
  return this->totalLocationCount;
}


// ========================================================================
// ??0idSpawnArea@@QAA@XZ
// EA  : 0x8251A4B0
// RVA : 0x0051A4B0
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

idSpawnArea *__fastcall idSpawnArea::idSpawnArea(idSpawnArea *this)
{
  idEntity::idEntity(this);
  this->nodeType = TYPE_STANDARD;
  this->team = TEAM_NONE;
  this->isActive = true;
  this->initial = false;
  this->__vftable = (idSpawnArea_vtbl *)&idSpawnArea::`vftable';
  this->debug_positions.list = nullptr;
  this->debug_positions.granularity = 0;
  this->debug_positions.memTag = 5;
  this->debug_positions.listStatic = 0;
  this->debug_positions.size = 0;
  this->debug_positions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->debug_positions);
  this->generatedPositions.list = nullptr;
  this->generatedPositions.granularity = 0;
  this->generatedPositions.memTag = 5;
  this->generatedPositions.listStatic = 0;
  this->generatedPositions.size = 0;
  this->generatedPositions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->generatedPositions);
  this->obstructedPositions.memTag = 5;
  this->obstructedPositions.list = nullptr;
  this->obstructedPositions.granularity = 0;
  this->obstructedPositions.listStatic = 0;
  this->obstructedPositions.size = 0;
  this->obstructedPositions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->obstructedPositions);
  this->lastPositionUsed = 0;
  this->yaw = 0.0;
  this->facingTargetObj.spawnId.value = 0x1FFF;
  if ( this->obstructedPositions.size < 16 )
    idList<idNavSpline *,5>::Resize(this: &this->obstructedPositions, newsize: 16);
  return this;
}


// ========================================================================
// __unwind$573836
// EA  : 0x8251A5A4
// RVA : 0x0051A5A4
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

void _unwind_573836()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$573837
// EA  : 0x8251A5CC
// RVA : 0x0051A5CC
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

void _unwind_573837()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 816));
}


// ========================================================================
// __unwind$573838
// EA  : 0x8251A5F8
// RVA : 0x0051A5F8
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

void _unwind_573838()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 832));
}


// ========================================================================
// __unwind$573839
// EA  : 0x8251A624
// RVA : 0x0051A624
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

void _unwind_573839()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 848));
}


// ========================================================================
// ?GetApproximateLocationCount@idSpawnArea@@UBAHXZ
// EA  : 0x8251A650
// RVA : 0x0051A650
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

int __fastcall idSpawnArea::GetApproximateLocationCount(idSpawnArea *this)
{
  return this->generatedPositions.num;
}


// ========================================================================
// ?Debug_IsValid@idSpawnArea@@UBA_NXZ
// EA  : 0x8251A658
// RVA : 0x0051A658
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

unsigned int __fastcall idSpawnArea::Debug_IsValid(idSpawnArea *this)
{
  return (-this->generatedPositions.num & (unsigned int)~this->generatedPositions.num) >> 31;
}


// ========================================================================
// ??0idPlayerStart@@QAA@XZ
// EA  : 0x82558158
// RVA : 0x00558158
// PDB : w:\tech5\tungsten\game\spawning\spawnnode.h
// ========================================================================

idPlayerStart *__fastcall idPlayerStart::idPlayerStart(idPlayerStart *this)
{
  idEntity::idEntity(this);
  this->nodeType = TYPE_STANDARD;
  this->__vftable = (idPlayerStart_vtbl *)&idPlayerStart::`vftable';
  this->team = TEAM_NONE;
  this->isActive = true;
  this->initial = false;
  this->deathTrigger.spawnId.value = 0x1FFF;
  this->vehicle.spawnId.value = 0x1FFF;
  return this;
}

