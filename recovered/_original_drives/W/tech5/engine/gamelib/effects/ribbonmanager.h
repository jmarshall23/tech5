
// ========================================================================
// ??0ribbonEffects_t@idRibbonModelManager@@QAA@XZ
// EA  : 0x8259EFF0
// RVA : 0x0059EFF0
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.h
// ========================================================================

idBreakableManager::breakables_t *__fastcall idRibbonModelManager::ribbonEffects_t::ribbonEffects_t(
        idBreakableManager::breakables_t *this)
{
  this->entity.num = 0;
  this->entity.granularity = 1;
  this->entity.list = this->entity.staticList;
  this->entity.size = 16;
  this->entity.memTag = 5;
  this->entity.listStatic = 1;
  this->next = 0;
  return this;
}

