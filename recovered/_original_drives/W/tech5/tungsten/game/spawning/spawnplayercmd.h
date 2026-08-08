
// ========================================================================
// ??0idSpawnPlayerCmd@@QAA@XZ
// EA  : 0x82EA5B48
// RVA : 0x00EA5B48
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.h
// ========================================================================

idSpawnPlayerCmd *__fastcall idSpawnPlayerCmd::idSpawnPlayerCmd(idSpawnPlayerCmd *this)
{
  idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>::CommandExecutorT<idSpawnPlayerCmdData>(this);
  this->__vftable = (idSpawnPlayerCmd_vtbl *)&idSpawnPlayerCmd::`vftable';
  this->hostileGrenadeLocations.list = nullptr;
  this->hostileGrenadeLocations.granularity = 0;
  this->hostileGrenadeLocations.memTag = 5;
  this->hostileGrenadeLocations.listStatic = 0;
  this->hostileGrenadeLocations.size = 0;
  this->hostileGrenadeLocations.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hostileGrenadeLocations);
  this->hostileGrenadesDangerRadiusSq.list = nullptr;
  this->hostileGrenadesDangerRadiusSq.granularity = 0;
  this->hostileGrenadesDangerRadiusSq.memTag = 5;
  this->hostileGrenadesDangerRadiusSq.listStatic = 0;
  this->hostileGrenadesDangerRadiusSq.size = 0;
  this->hostileGrenadesDangerRadiusSq.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hostileGrenadesDangerRadiusSq);
  this->deferredVisibilityQueries.list = nullptr;
  this->deferredVisibilityQueries.granularity = 0;
  this->deferredVisibilityQueries.memTag = 5;
  this->deferredVisibilityQueries.listStatic = 0;
  this->deferredVisibilityQueries.size = 0;
  this->deferredVisibilityQueries.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deferredVisibilityQueries);
  return this;
}


// ========================================================================
// __unwind$487470
// EA  : 0x82EA5BE4
// RVA : 0x00EA5BE4
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.h
// ========================================================================

void _unwind_487470()
{
  int v0; // r12

  idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>::~CommandExecutorT<idSpawnPlayerCmdData>(this: *(idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$487471
// EA  : 0x82EA5C0C
// RVA : 0x00EA5C0C
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.h
// ========================================================================

void _unwind_487471()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// __unwind$487472
// EA  : 0x82EA5C38
// RVA : 0x00EA5C38
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.h
// ========================================================================

void _unwind_487472()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// ??1idSpawnPlayerCmd@@UAA@XZ
// EA  : 0x82EA5C70
// RVA : 0x00EA5C70
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.h
// ========================================================================

void __fastcall idSpawnPlayerCmd::~idSpawnPlayerCmd(idSpawnPlayerCmd *this)
{
  this->__vftable = (idSpawnPlayerCmd_vtbl *)&idSpawnPlayerCmd::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deferredVisibilityQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hostileGrenadesDangerRadiusSq);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hostileGrenadeLocations);
  idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>::~CommandExecutorT<idSpawnPlayerCmdData>(this);
}


// ========================================================================
// __unwind$487515
// EA  : 0x82EA5CD4
// RVA : 0x00EA5CD4
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.h
// ========================================================================

void _unwind_487515()
{
  int v0; // r12

  idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>::~CommandExecutorT<idSpawnPlayerCmdData>(this: *(idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487516
// EA  : 0x82EA5CFC
// RVA : 0x00EA5CFC
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.h
// ========================================================================

void _unwind_487516()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$487517
// EA  : 0x82EA5D28
// RVA : 0x00EA5D28
// PDB : w:\tech5\tungsten\game\spawning\spawnplayercmd.h
// ========================================================================

void _unwind_487517()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}

