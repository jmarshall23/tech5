
// ========================================================================
// ?IsDone_Default@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D2D70
// RVA : 0x009D2D70
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.h
// ========================================================================

BOOL __fastcall idLobbyBackend360::IsDone_Default(idLobbyBackend360 *this)
{
  return (_cntlzw(this->waitingForOverlapped) & 0x20) != 0;
}


// ========================================================================
// ?EndTask_SetShutdown@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D2D80
// RVA : 0x009D2D80
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.h
// ========================================================================

int __fastcall idLobbyBackend360::EndTask_SetShutdown(idLobbyBackend360 *this)
{
  this->isHost = false;
  return 1;
}


// ========================================================================
// ?SetState@idLobbyBackend360@@AAAXW4lobbyBackendState_t@idLobbyBackend@@@Z
// EA  : 0x829D3298
// RVA : 0x009D3298
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.h
// ========================================================================

void __fastcall idLobbyBackend360::SetState(idLobbyBackend360 *this, idLobbyBackend::lobbyBackendState_t state_)
{
  const char *v4; // r6

  if ( net_verbose.valueInteger != 0 )
  {
    if ( this->type != TYPE_PARTY )
      v4 = "Game";
    else
      v4 = "Party";
    idLib::Printf(
      fmt: "idLobbyBackend360::SetState: %s to %s (%s)\n",
      idLobbyBackend360::stateNames[this->state],
      idLobbyBackend360::stateNames[state_],
      v4);
  }
  this->state = state_;
}


// ========================================================================
// ?StartTask_SetReady@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D5C48
// RVA : 0x009D5C48
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.h
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_SetReady(idLobbyBackend360 *this)
{
  idLobbyBackend360::SetState(this, state_: STATE_READY);
  return 1;
}


// ========================================================================
// ?IsSessionStarted@idLobbyBackend360@@UAA_NXZ
// EA  : 0x829D9430
// RVA : 0x009D9430
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.h
// ========================================================================

int __fastcall idLobbyBackend360::IsSessionStarted(idLobbyBackend360 *this)
{
  return this->sessionInfo.hostAddress.abOnline[13];
}

