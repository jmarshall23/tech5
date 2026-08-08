
// ========================================================================
// ??0idMatchResults@@QAA@XZ
// EA  : 0x82DD54D8
// RVA : 0x00DD54D8
// PDB : w:\tech5\tungsten\game\matchresults.h
// ========================================================================

idMatchResults *__fastcall idMatchResults::idMatchResults(idMatchResults *this)
{
  this->playerId = 0;
  this->lobbyUserID.localUserHandle.handle = 0;
  this->lobbyUserID.lobbyType = -1;
  this->accoladesEarned.list = nullptr;
  this->accoladesEarned.granularity = 0;
  this->accoladesEarned.memTag = 5;
  this->accoladesEarned.listStatic = 0;
  this->accoladesEarned.size = 0;
  this->accoladesEarned.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->accoladesEarned);
  this->itemsUnlocked.list = nullptr;
  this->itemsUnlocked.granularity = 0;
  this->itemsUnlocked.memTag = 5;
  this->itemsUnlocked.listStatic = 0;
  this->itemsUnlocked.size = 0;
  this->itemsUnlocked.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->itemsUnlocked);
  this->shouldShowMatchResults = false;
  return this;
}


// ========================================================================
// __unwind$487936
// EA  : 0x82DD5560
// RVA : 0x00DD5560
// PDB : w:\tech5\tungsten\game\matchresults.h
// ========================================================================

void _unwind_487936()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}

