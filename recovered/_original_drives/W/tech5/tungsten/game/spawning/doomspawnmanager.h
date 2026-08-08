
// ========================================================================
// ??1idDoomSpawnManager@@UAA@XZ
// EA  : 0x82EA5E48
// RVA : 0x00EA5E48
// PDB : w:\tech5\tungsten\game\spawning\doomspawnmanager.h
// ========================================================================

void __fastcall idDoomSpawnManager::~idDoomSpawnManager(idDoomSpawnManager *this)
{
  this->__vftable = (idDoomSpawnManager_vtbl *)&idDoomSpawnManager::`vftable';
  idSpawnPlayerCmd::~idSpawnPlayerCmd(this: &this->spawnPlayerCmd);
  idSpawnManager::~idSpawnManager(this);
}


// ========================================================================
// __unwind$487581
// EA  : 0x82EA5E9C
// RVA : 0x00EA5E9C
// PDB : w:\tech5\tungsten\game\spawning\doomspawnmanager.h
// ========================================================================

void _unwind_487581()
{
  int v0; // r12

  idSpawnManager::~idSpawnManager(this: *(idSpawnManager **)(v0 - 112 + 132));
}

