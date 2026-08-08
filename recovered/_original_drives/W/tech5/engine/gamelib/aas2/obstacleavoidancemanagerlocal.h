
// ========================================================================
// ??0idObstacleAvoidanceManagerLocal@@QAA@XZ
// EA  : 0x826C8788
// RVA : 0x006C8788
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.h
// ========================================================================

idObstacleAvoidanceManagerLocal *__fastcall idObstacleAvoidanceManagerLocal::idObstacleAvoidanceManagerLocal(
        idObstacleAvoidanceManagerLocal *this)
{
  this->jobList = nullptr;
  this->__vftable = (idObstacleAvoidanceManagerLocal_vtbl *)&idObstacleAvoidanceManagerLocal::`vftable';
  this->usedBuffers.list = nullptr;
  this->usedBuffers.granularity = 0;
  this->usedBuffers.memTag = 5;
  this->usedBuffers.listStatic = 0;
  this->usedBuffers.size = 0;
  this->usedBuffers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->usedBuffers);
  this->freeBuffers.list = nullptr;
  this->freeBuffers.granularity = 0;
  this->freeBuffers.memTag = 5;
  this->freeBuffers.listStatic = 0;
  this->freeBuffers.size = 0;
  this->freeBuffers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->freeBuffers);
  this->toBeFreedBuffers.list = nullptr;
  this->toBeFreedBuffers.granularity = 0;
  this->toBeFreedBuffers.memTag = 5;
  this->toBeFreedBuffers.listStatic = 0;
  this->toBeFreedBuffers.size = 0;
  this->toBeFreedBuffers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->toBeFreedBuffers);
  return this;
}


// ========================================================================
// __unwind$246382
// EA  : 0x826C8824
// RVA : 0x006C8824
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.h
// ========================================================================

void _unwind_246382()
{
  int v0; // r12

  idObstacleAvoidanceManager::~idObstacleAvoidanceManager(this: *(idObstacleAvoidanceManager **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$246383
// EA  : 0x826C884C
// RVA : 0x006C884C
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.h
// ========================================================================

void _unwind_246383()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$246384
// EA  : 0x826C8878
// RVA : 0x006C8878
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.h
// ========================================================================

void _unwind_246384()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}

