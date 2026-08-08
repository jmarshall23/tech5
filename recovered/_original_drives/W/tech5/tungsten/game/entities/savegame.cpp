
// ========================================================================
// ??0mgFuncSaveGame@@QAA@XZ
// EA  : 0x82CB4298
// RVA : 0x00CB4298
// PDB : w:\tech5\tungsten\game\entities\savegame.cpp
// ========================================================================

mgFuncSaveGame *__fastcall mgFuncSaveGame::mgFuncSaveGame(mgFuncSaveGame *this)
{
  idEntity::idEntity(this);
  this->maxTension = PLAYER_TENSION_NONE;
  this->__vftable = (mgFuncSaveGame_vtbl *)&mgFuncSaveGame::`vftable';
  this->delayedSave = -1;
  return this;
}


// ========================================================================
// ?Think@mgFuncSaveGame@@MAAXXZ
// EA  : 0x82CB42E8
// RVA : 0x00CB42E8
// PDB : w:\tech5\tungsten\game\entities\savegame.cpp
// ========================================================================

void __fastcall mgFuncSaveGame::Think(mgFuncSaveGame *this)
{
  int delayedSave; // r11
  int v2; // r11

  delayedSave = this->delayedSave;
  if ( delayedSave >= 0 )
  {
    v2 = delayedSave - 1;
    this->delayedSave = v2;
    if ( v2 < 0 )
    {
      idEntity::BecomeInactive(this, flags: 1);
      gameLocal->SaveGame(this: gameLocal, a2: "autosave", a3: true, a4: false);
    }
  }
}


// ========================================================================
// ?OnActivate@mgFuncSaveGame@@MAAXPAVidEntity@@@Z
// EA  : 0x82CB43B8
// RVA : 0x00CB43B8
// PDB : w:\tech5\tungsten\game\entities\savegame.cpp
// ========================================================================

void __fastcall mgFuncSaveGame::OnActivate(mgFuncSaveGame *this, idEntity *__formal)
{
  idPlayer::tensionType_t currentPlayerTension; // r30
  int i; // r31
  idPlayer *Player; // r3
  int v6; // r3

  currentPlayerTension = PLAYER_TENSION_NONE;
  for ( i = 0; i < 6; ++i )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i);
    if ( Player != nullptr && currentPlayerTension <= Player->currentPlayerTension )
      currentPlayerTension = Player->currentPlayerTension;
  }
  if ( currentPlayerTension <= this->maxTension )
  {
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    if ( v6 > 10 )
    {
      gameLocal->SaveGame(this: gameLocal, a2: "autosave", a3: true, a4: false);
    }
    else
    {
      this->delayedSave = 11 - v6;
      idEntity::BecomeActive(this, flags: 1);
    }
  }
}

