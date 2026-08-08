
// ========================================================================
// ?QueueSpawnPlayer@idDoomSpawnManager@@QAAIHABW4gameTeam_t@@HABVidSpawnNodeGroup@@_N2@Z
// EA  : 0x82EA5888
// RVA : 0x00EA5888
// PDB : w:\tech5\tungsten\game\spawning\doomspawnmanager.cpp
// ========================================================================

unsigned int __fastcall idDoomSpawnManager::QueueSpawnPlayer(
        idDoomSpawnManager *this,
        int playerIndex,
        const gameTeam_t *allowedTeams,
        int loadoutIndex,
        const idSpawnNodeGroup *spawnNodeGroup,
        bool useInitialNodes,
        bool returnHandle)
{
  int v9; // r3

  v9 = idSpawnPlayerCmd::SpawnPlayer(
         this: &this->spawnPlayerCmd,
         playerIndex,
         allowedTeams,
         loadoutIndex,
         spawnNodeGroup,
         useInitialNodes);
  return idSpawnManager::PushCommand(this, type: 0, dataIndex: v9, returnHandle);
}


// ========================================================================
// ?GetExecutor@idDoomSpawnManager@@EAAPAVCommandExecutor@idSpawnManager@@H@Z
// EA  : 0x82EA58D8
// RVA : 0x00EA58D8
// PDB : w:\tech5\tungsten\game\spawning\doomspawnmanager.cpp
// ========================================================================

idSpawnPlayerCmd *__fastcall idDoomSpawnManager::GetExecutor(idDoomSpawnManager *this, int commandType)
{
  if ( commandType != 0 )
    return nullptr;
  else
    return &this->spawnPlayerCmd;
}


// ========================================================================
// ??0idDoomSpawnManager@@QAA@XZ
// EA  : 0x82EA5DC0
// RVA : 0x00EA5DC0
// PDB : w:\tech5\tungsten\game\spawning\doomspawnmanager.cpp
// ========================================================================

idDoomSpawnManager *__fastcall idDoomSpawnManager::idDoomSpawnManager(idDoomSpawnManager *this)
{
  idSpawnManager::idSpawnManager(this);
  this->__vftable = (idDoomSpawnManager_vtbl *)&idDoomSpawnManager::`vftable';
  idSpawnPlayerCmd::idSpawnPlayerCmd(this: &this->spawnPlayerCmd);
  return this;
}


// ========================================================================
// __unwind$487564
// EA  : 0x82EA5E14
// RVA : 0x00EA5E14
// PDB : w:\tech5\tungsten\game\spawning\doomspawnmanager.cpp
// ========================================================================

void _unwind_487564()
{
  int v0; // r12

  idSpawnManager::~idSpawnManager(this: *(idSpawnManager **)(v0 - 112 + 132));
}

