
// ========================================================================
// ??0spawnables_t@idSpawnablePropManager@@QAA@XZ
// EA  : 0x8259F028
// RVA : 0x0059F028
// PDB : w:\tech5\tungsten\game\entities\spawnablepropmanager.h
// ========================================================================

idSpawnablePropManager::spawnables_t *__fastcall idSpawnablePropManager::spawnables_t::spawnables_t(
        idSpawnablePropManager::spawnables_t *this)
{
  this->entity.num = 0;
  this->entity.granularity = 1;
  this->entity.list = this->entity.staticList;
  this->entity.size = 4;
  this->entity.memTag = 5;
  this->entity.listStatic = 1;
  this->next = 0;
  return this;
}

