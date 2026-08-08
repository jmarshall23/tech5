
// ========================================================================
// ?IsTeamGame@idGameChallenge_PVP@@UBA_NXZ
// EA  : 0x82536A58
// RVA : 0x00536A58
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.h
// ========================================================================

BOOL __fastcall idGameChallenge_PVP::IsTeamGame(idGameChallenge_PVP *this)
{
  return this->isTeamGame;
}


// ========================================================================
// ??0teamData_t@idGameChallenge@@QAA@XZ
// EA  : 0x8259F508
// RVA : 0x0059F508
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.h
// ========================================================================

idGameChallenge::teamData_t *__fastcall idGameChallenge::teamData_t::teamData_t(idGameChallenge::teamData_t *this)
{
  this->playerIndexList.num = 0;
  this->playerIndexList.granularity = 1;
  this->playerIndexList.list = this->playerIndexList.staticList;
  this->playerIndexList.size = 4;
  this->playerIndexList.memTag = 5;
  this->playerIndexList.listStatic = 1;
  this->teamScore = 0;
  this->playerIndexList.staticList[0] = 0;
  this->playerIndexList.staticList[1] = 0;
  this->playerIndexList.staticList[2] = 0;
  this->playerIndexList.staticList[3] = 0;
  return this;
}


// ========================================================================
// ?GetMaxNumCollectibles@idGameChallenge_Coop@@QBAHXZ
// EA  : 0x82C51B28
// RVA : 0x00C51B28
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.h
// ========================================================================

int __fastcall idGameChallenge_Coop::GetMaxNumCollectibles(idGameChallenge_Coop *this)
{
  int result; // r3

  result = this->numCollectiblesToComplete;
  if ( result == -1 )
    return this->collectibleList.num;
  return result;
}


// ========================================================================
// ?DidPlayerWin@idGameChallenge_Coop@@UBA_NH@Z
// EA  : 0x82C5B2B8
// RVA : 0x00C5B2B8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.h
// ========================================================================

BOOL __fastcall idGameChallenge_Coop::DidPlayerWin(idGameChallenge_Coop *this, int playerEntityNumber)
{
  return (_cntlzw(this->bGameFailed) & 0x20) != 0;
}

