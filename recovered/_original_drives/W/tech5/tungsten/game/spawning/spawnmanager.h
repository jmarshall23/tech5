
// ========================================================================
// ??1CommandExecutor@idSpawnManager@@UAA@XZ
// EA  : 0x82EA58F0
// RVA : 0x00EA58F0
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.h
// ========================================================================

void __fastcall idSpawnManager::CommandExecutor::~CommandExecutor(idSpawnManager::CommandExecutor *this)
{
  this->__vftable = (idSpawnManager::CommandExecutor_vtbl *)&idSpawnManager::CommandExecutor::`vftable';
}


// ========================================================================
// ??0?$CommandExecutorT@VidSpawnPlayerCmdData@@@idSpawnManager@@QAA@XZ
// EA  : 0x82EA5A10
// RVA : 0x00EA5A10
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.h
// ========================================================================

idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData> *__fastcall idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>::CommandExecutorT<idSpawnPlayerCmdData>(
        idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData> *this)
{
  this->__vftable = (idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>_vtbl *)&idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>::`vftable';
  this->freeDataIndices.list = nullptr;
  this->freeDataIndices.granularity = 0;
  this->freeDataIndices.memTag = 5;
  this->freeDataIndices.listStatic = 0;
  this->freeDataIndices.size = 0;
  this->freeDataIndices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->freeDataIndices);
  this->dataArray.list = nullptr;
  this->dataArray.granularity = 0;
  this->dataArray.memTag = 5;
  this->dataArray.listStatic = 0;
  this->dataArray.size = 0;
  this->dataArray.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dataArray);
  return this;
}


// ========================================================================
// __unwind$487423
// EA  : 0x82EA5A88
// RVA : 0x00EA5A88
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.h
// ========================================================================

void _unwind_487423()
{
  int v0; // r12

  idSpawnManager::CommandExecutor::~CommandExecutor(this: *(idSpawnManager::CommandExecutor **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$487424
// EA  : 0x82EA5AB0
// RVA : 0x00EA5AB0
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.h
// ========================================================================

void _unwind_487424()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// ?Reset@Context@idSpawnManager@@QAAXXZ
// EA  : 0x82EA68E0
// RVA : 0x00EA68E0
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.h
// ========================================================================

void __fastcall idSpawnManager::Context::Reset(idSpawnManager::Context *this)
{
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->currentLocationIndex = 0;
  this->minLocationValue = 1.0;
  this->maxLocactionValue = 0.0;
}


// ========================================================================
// ??0Context@idSpawnManager@@QAA@XZ
// EA  : 0x82EA74B0
// RVA : 0x00EA74B0
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.h
// ========================================================================

idSpawnManager::Context *__fastcall idSpawnManager::Context::Context(idSpawnManager::Context *this)
{
  this->spawnLocations.list = nullptr;
  this->spawnLocations.granularity = 0;
  this->spawnLocations.memTag = 5;
  this->spawnLocations.listStatic = 0;
  this->spawnLocations.size = 0;
  this->spawnLocations.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->currentLocationIndex = 0;
  this->minLocationValue = 1.0;
  this->maxLocactionValue = 0.0;
  return this;
}


// ========================================================================
// __unwind$490237
// EA  : 0x82EA751C
// RVA : 0x00EA751C
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.h
// ========================================================================

void _unwind_490237()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetFreeDataIndex@?$CommandExecutorT@VidSpawnPlayerCmdData@@@idSpawnManager@@IAAHXZ
// EA  : 0x82EAAF50
// RVA : 0x00EAAF50
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.h
// ========================================================================

int __fastcall idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>::GetFreeDataIndex(
        idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData> *this)
{
  int v2; // r10
  int result; // r3
  int num; // r9
  idList<int,5> *p_freeDataIndices; // r11
  int v6; // r9

  v2 = this->freeDataIndices.num - 1;
  if ( v2 >= 0 )
  {
    num = this->freeDataIndices.num;
    p_freeDataIndices = &this->freeDataIndices;
    result = this->freeDataIndices.list[v2];
    if ( v2 < num )
    {
      v6 = num - 1;
      this->freeDataIndices.num = v6;
      if ( v2 != v6 )
        p_freeDataIndices->list[v2] = p_freeDataIndices->list[v6];
    }
  }
  else
  {
    idList<idSpawnPlayerCmdData,5>::Alloc(this: &this->dataArray);
    return this->dataArray.num - 1;
  }
  return result;
}

