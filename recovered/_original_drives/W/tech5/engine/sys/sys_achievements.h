
// ========================================================================
// ??1idAchievementSystem@@UAA@XZ
// EA  : 0x829E4E98
// RVA : 0x009E4E98
// PDB : w:\tech5\engine\sys\sys_achievements.h
// ========================================================================

void __fastcall idAchievementSystem::~idAchievementSystem(idAchievementSystem *this)
{
  this->__vftable = (idAchievementSystem_vtbl *)&idAchievementSystem::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->users);
}

