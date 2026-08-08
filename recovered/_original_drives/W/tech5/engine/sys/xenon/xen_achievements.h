
// ========================================================================
// ?Reset@achievementAction_t@idAchievementSystemXbox@@QAAXXZ
// EA  : 0x829D0C88
// RVA : 0x009D0C88
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.h
// ========================================================================

void __fastcall idAchievementSystemXbox::achievementAction_t::Reset(idAchievementSystemXbox::achievementAction_t *this)
{
  idAchievementSystemXbox::state_t *p_state; // r11
  int i; // ctr

  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->achievements);
  p_state = &this->state;
  this->state = 0;
  for ( i = 7; i != 0; --i )
    *++p_state = 0;
}


// ========================================================================
// ??0achievementAction_t@idAchievementSystemXbox@@QAA@XZ
// EA  : 0x829E4A30
// RVA : 0x009E4A30
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.h
// ========================================================================

idAchievementSystemXbox::achievementAction_t *__fastcall idAchievementSystemXbox::achievementAction_t::achievementAction_t(
        idAchievementSystemXbox::achievementAction_t *this)
{
  idList<idVehicleState *,5> *p_achievements; // r29
  idAchievementSystemXbox::state_t *p_state; // r10
  int i; // ctr

  this->pendingAchievments.granularity = 1;
  this->pendingAchievments.size = 128;
  this->pendingAchievments.num = 0;
  this->pendingAchievments.memTag = 5;
  this->pendingAchievments.list = this->pendingAchievments.staticList;
  this->pendingAchievments.listStatic = 1;
  p_achievements = (idList<idVehicleState *,5> *)&this->achievements;
  this->achievements.num = 0;
  this->achievements.size = 128;
  this->achievements.list = this->achievements.staticList;
  this->achievements.granularity = 1;
  this->achievements.memTag = 5;
  this->achievements.listStatic = 1;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear(this: p_achievements);
  this->state = 0;
  p_state = &this->state;
  for ( i = 7; i != 0; --i )
    *++p_state = 0;
  return this;
}


// ========================================================================
// __unwind$240563
// EA  : 0x829E4AC8
// RVA : 0x009E4AC8
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.h
// ========================================================================

void _unwind_240563()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$240564_0
// EA  : 0x829E4AF0
// RVA : 0x009E4AF0
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.h
// ========================================================================

void _unwind_240564_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1040));
}

