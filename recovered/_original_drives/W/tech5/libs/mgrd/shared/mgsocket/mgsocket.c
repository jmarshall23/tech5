
// ========================================================================
// int_platforminit
// EA  : 0x832338E8
// RVA : 0x012338E8
// PDB : w:\tech5\libs\mgrd\shared\mgsocket\mgsocket.c
// ========================================================================

void int_platforminit()
{
  XNetStartupParams v0; // [sp+50h] [-1C0h] BYREF
  WSAData v1; // [sp+60h] [-1B0h] BYREF

  if ( inited == 0 )
  {
    memset(&v1, 0, sizeof(v1));
    v0.cfgSecRegMax = 0;
    *(_DWORD *)&v0.cfgQosDataLimitDiv4 = 0;
    v0.cfgQosPairWaitTimeInSeconds = 0;
    v0.cfgSizeOfStruct = 13;
    v0.cfgFlags = 9;
    v0.cfgSockMaxDgramSockets = 64;
    v0.cfgSockMaxStreamSockets = 32;
    v0.cfgSockDefaultRecvBufsizeInK = 32;
    v0.cfgSockDefaultSendBufsizeInK = 64;
    v0.cfgKeyRegMax = 16;
    if ( XNetStartup(pxnsp: &v0) != 0 )
      __trap();
    WSAStartup(wVersionRequired: 0x202u, lpWSAData: &v1);
    inited = 1;
  }
}


// ========================================================================
// mgsocket_close
// EA  : 0x832339A8
// RVA : 0x012339A8
// PDB : w:\tech5\libs\mgrd\shared\mgsocket\mgsocket.c
// ========================================================================

// attributes: thunk
void __fastcall mgsocket_close(SOCKET sock)
{
  closesocket(s: sock);
}


// ========================================================================
// mgsocket_send
// EA  : 0x832339B0
// RVA : 0x012339B0
// PDB : w:\tech5\libs\mgrd\shared\mgsocket\mgsocket.c
// ========================================================================

int __fastcall mgsocket_send(SOCKET sock, const char *data, int size)
{
  return send(s: sock, buf: data, len: size, flags: 0);
}


// ========================================================================
// mgsocket_recv
// EA  : 0x832339B8
// RVA : 0x012339B8
// PDB : w:\tech5\libs\mgrd\shared\mgsocket\mgsocket.c
// ========================================================================

int __fastcall mgsocket_recv(SOCKET sock, char *data, int size)
{
  return recv(s: sock, buf: data, len: size, flags: 0);
}


// ========================================================================
// mgsocket_createserver
// EA  : 0x832339C0
// RVA : 0x012339C0
// PDB : w:\tech5\libs\mgrd\shared\mgsocket\mgsocket.c
// ========================================================================

SOCKET __fastcall mgsocket_createserver(const char *listenaddr)
{
  __int64 v1; // r11
  int v3; // r3
  SOCKET v4; // r31
  SOCKET result; // r3
  bool v6; // zf
  int v7[4]; // [sp+50h] [-30h] BYREF
  sockaddr v8; // [sp+60h] [-20h] BYREF

  HIDWORD(v1) = &v8;
  LODWORD(v1) = 0;
  *(_QWORD *)HIDWORD(v1) = v1;
  *(_QWORD *)(HIDWORD(v1) + 8) = v1;
  int_platforminit();
  v8.sa_family = 2;
  *(_WORD *)v8.sa_data = atol(nptr: listenaddr);
  v3 = socket(af: 2, type: 1, protocol: 0);
  v4 = v3;
  if ( v3 < 0 )
    return -1;
  v7[0] = 1;
  setsockopt(s: v3, level: 0xFFFF, optname: 4, optval: (const char *)v7, optlen: 4);
  v6 = bind(s: v4, name: &v8, namelen: 16) != 0;
  result = v4;
  if ( v6 || (v6 = listen(s: v4, backlog: 1) == 0, result = v4, !v6) )
  {
    closesocket(s: result);
    return -1;
  }
  return result;
}


// ========================================================================
// mgsocket_accept
// EA  : 0x83233A88
// RVA : 0x01233A88
// PDB : w:\tech5\libs\mgrd\shared\mgsocket\mgsocket.c
// ========================================================================

SOCKET __fastcall mgsocket_accept(SOCKET sock)
{
  int v2[4]; // [sp+50h] [-30h] BYREF
  sockaddr v3; // [sp+60h] [-20h] BYREF

  v2[0] = 16;
  return accept(s: sock, addr: &v3, addrlen: v2);
}


// ========================================================================
// mgsocket_wait
// EA  : 0x83233AB8
// RVA : 0x01233AB8
// PDB : w:\tech5\libs\mgrd\shared\mgsocket\mgsocket.c
// ========================================================================

int __fastcall mgsocket_wait(SOCKET sock, char mask)
{
  BOOL v3; // r30
  int v4; // r10
  timeval v6; // [sp+50h] [-350h] BYREF
  fd_set v7; // [sp+60h] [-340h] BYREF
  fd_set v8; // [sp+170h] [-230h] BYREF
  fd_set v9; // [sp+280h] [-120h] BYREF

  v7.fd_count = 0;
  v8.fd_count = 0;
  v9.fd_count = 0;
  if ( (mask & 1) != 0 )
  {
    v7.fd_array[0] = sock;
    v7.fd_count = 1;
  }
  if ( (mask & 2) != 0 )
  {
    v8.fd_array[0] = sock;
    v8.fd_count = 1;
  }
  if ( (mask & 4) != 0 )
  {
    v9.fd_array[0] = sock;
    v9.fd_count = 1;
  }
  v6.tv_sec = 0;
  v6.tv_usec = 100000;
  select(nfds: sock + 1, readfds: &v7, writefds: &v8, exceptfds: &v9, timeout: &v6);
  v3 = _WSAFDIsSet(s: sock, fds: &v7) != 0;
  v4 = _WSAFDIsSet(s: sock, fds: &v8) == 0 ? 0 : 2;
  return (_WSAFDIsSet(s: sock, fds: &v9) == 0 ? 0 : 4) | v4 | v3;
}


// ========================================================================
// mgsocket_check
// EA  : 0x83233BB8
// RVA : 0x01233BB8
// PDB : w:\tech5\libs\mgrd\shared\mgsocket\mgsocket.c
// ========================================================================

int __fastcall mgsocket_check(SOCKET sock)
{
  BOOL v2; // r30
  char v3; // r6
  timeval v5; // [sp+50h] [-350h] BYREF
  fd_set v6; // [sp+60h] [-340h] BYREF
  fd_set v7; // [sp+170h] [-230h] BYREF
  fd_set v8; // [sp+280h] [-120h] BYREF

  v6.fd_array[0] = sock;
  v7.fd_array[0] = sock;
  v8.fd_array[0] = sock;
  v5.tv_sec = 0;
  v5.tv_usec = 0;
  v6.fd_count = 1;
  v7.fd_count = 1;
  v8.fd_count = 1;
  select(nfds: sock + 1, readfds: &v6, writefds: &v7, exceptfds: &v8, timeout: &v5);
  v2 = _WSAFDIsSet(s: sock, fds: &v6) != 0;
  v3 = (_WSAFDIsSet(s: sock, fds: &v7) == 0) - 1;
  return (_WSAFDIsSet(s: sock, fds: &v8) == 0 ? 0 : 4) | v3 & 2 | v2;
}

