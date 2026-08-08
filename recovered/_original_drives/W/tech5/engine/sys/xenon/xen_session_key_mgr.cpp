
// ========================================================================
// ?KeepSecurityAssociation@idSessionKeyMgr@@QAAXABUXNKID@@@Z
// EA  : 0x829E0D28
// RVA : 0x009E0D28
// PDB : w:\tech5\engine\sys\xenon\xen_session_key_mgr.cpp
// ========================================================================

void __fastcall idSessionKeyMgr::KeepSecurityAssociation(idSessionKeyMgr *this, const XNKID *sessionID)
{
  int v4; // r29
  int v5; // r31
  int v6; // r11
  char v7; // r11

  v4 = this->sessionKeys.num - 1;
  if ( v4 >= 0 )
  {
    v5 = v4;
    do
    {
      v6 = 0;
      while ( this->sessionKeys.list[v5].sessionID.ab[v6] == sessionID->ab[v6] )
      {
        if ( (unsigned int)++v6 >= 8 )
        {
          v7 = 1;
          goto LABEL_7;
        }
      }
      v7 = 0;
LABEL_7:
      if ( v7 != 0 )
        idList<idSessionKeyMgr::sessionKey_t,5>::RemoveIndex(this: &this->sessionKeys, index: v4);
      --v4;
      --v5;
    }
    while ( v4 >= 0 );
  }
}


// ========================================================================
// ?UnregisterAllKeys@idSessionKeyMgr@@QAAXPAVidLobbyBackend@@_N@Z
// EA  : 0x829E0DB0
// RVA : 0x009E0DB0
// PDB : w:\tech5\engine\sys\xenon\xen_session_key_mgr.cpp
// ========================================================================

void __fastcall idSessionKeyMgr::UnregisterAllKeys(idSessionKeyMgr *this, idLobbyBackend *lobbyOwner, bool force)
{
  int v6; // r30
  int v7; // r29
  idSessionKeyMgr::sessionKey_t *v8; // r11

  v6 = this->sessionKeys.num - 1;
  if ( v6 >= 0 )
  {
    v7 = v6;
    do
    {
      v8 = &this->sessionKeys.list[v7];
      if ( v8->lobbyOwner == lobbyOwner || force )
      {
        XNetUnregisterKey(pxnkid: &v8->sessionID);
        idList<idSessionKeyMgr::sessionKey_t,5>::RemoveIndex(this: &this->sessionKeys, index: v6);
      }
      --v6;
      --v7;
    }
    while ( v6 >= 0 );
  }
  if ( this->sessionKeys.listStatic != 0 && this->sessionKeys.listStatic != 2 )
  {
    this->sessionKeys.num = 0;
  }
  else
  {
    if ( this->sessionKeys.list != nullptr )
      idMem::Free(this: &mem, ptr: this->sessionKeys.list, align: ALIGN_16);
    this->sessionKeys.list = nullptr;
    this->sessionKeys.size = 0;
    this->sessionKeys.num = 0;
  }
}


// ========================================================================
// ??1idSessionKeyMgr@@QAA@XZ
// EA  : 0x829E0E78
// RVA : 0x009E0E78
// PDB : w:\tech5\engine\sys\xenon\xen_session_key_mgr.cpp
// ========================================================================

void __fastcall idSessionKeyMgr::~idSessionKeyMgr(idSessionKeyMgr *this)
{
  if ( this->sessionKeys.num != 0 )
    idSessionKeyMgr::UnregisterAllKeys(this, lobbyOwner: nullptr, force: true);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$219674
// EA  : 0x829E0ED0
// RVA : 0x009E0ED0
// PDB : w:\tech5\engine\sys\xenon\xen_session_key_mgr.cpp
// ========================================================================

void _unwind_219674()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ?RegisterKey@idSessionKeyMgr@@QAA_NABUXNKID@@ABUXNKEY@@PAVidLobbyBackend@@@Z
// EA  : 0x829E0EF8
// RVA : 0x009E0EF8
// PDB : w:\tech5\engine\sys\xenon\xen_session_key_mgr.cpp
// ========================================================================

BOOL __fastcall idSessionKeyMgr::RegisterKey(
        idSessionKeyMgr *this,
        const XNKID *sessionID,
        const XNKEY *keyExchangeKey,
        idLobbyBackend *lobbyOwner)
{
  int num; // r7
  int v9; // r8
  idLobbyBackend **p_lobbyOwner; // r9
  int v11; // r11
  char v12; // r11
  idSessionKeyMgr::sessionKey_t v14; // [sp+50h] [-50h] BYREF

  num = this->sessionKeys.num;
  v9 = 0;
  if ( num <= 0 )
  {
LABEL_10:
    if ( num >= 16 )
      idLib::Printf(fmt: "***** MAX REGISTERED SESSION KEYS *****\n");
    v14.sessionID = *sessionID;
    v14.keyExchangeKey = *keyExchangeKey;
    v14.lobbyOwner = lobbyOwner;
    v14.refCount = 1;
    idList<idSessionKeyMgr::sessionKey_t,5>::Append(this: &this->sessionKeys, obj: &v14);
    return (_cntlzw(XNetRegisterKey(pxnkid: sessionID, pxnkey: keyExchangeKey)) & 0x20) != 0;
  }
  else
  {
    p_lobbyOwner = &this->sessionKeys.list->lobbyOwner;
    while ( 1 )
    {
      v11 = 0;
      while ( *((unsigned __int8 *)p_lobbyOwner + v11 - 24) == sessionID->ab[v11] )
      {
        if ( (unsigned int)++v11 >= 8 )
        {
          v12 = 1;
          goto LABEL_7;
        }
      }
      v12 = 0;
LABEL_7:
      if ( v12 != 0 && *p_lobbyOwner == lobbyOwner )
        break;
      ++v9;
      p_lobbyOwner += 8;
      if ( v9 >= num )
        goto LABEL_10;
    }
    ++this->sessionKeys.list[v9].refCount;
    return true;
  }
}


// ========================================================================
// `dynamic initializer for 'g_sessionKeyMgr''
// EA  : 0x83363F40
// RVA : 0x01363F40
// PDB : w:\tech5\engine\sys\xenon\xen_session_key_mgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_sessionKeyMgr__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_sessionKeyMgr__);
}

