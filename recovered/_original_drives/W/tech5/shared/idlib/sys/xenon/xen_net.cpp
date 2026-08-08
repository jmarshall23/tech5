
// ========================================================================
// ?NET_ErrorString@@YAPADXZ
// EA  : 0x82F84EF0
// RVA : 0x00F84EF0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

char *__fastcall NET_ErrorString()
{
  int Error; // r3
  char *result; // r3

  Error = WSAGetLastError();
  if ( Error > 10051 )
  {
    if ( Error > 10101 )
    {
      if ( (unsigned int)(Error - 11001) > 3 )
      {
        return "UNKNOWN ERROR";
      }
      else
      {
        switch ( Error )
        {
          case 11002:
            return "WSATRY_AGAIN";
          case 11003:
            return "WSANO_RECOVERY";
          case 11001:
            return "WSAHOST_NOT_FOUND";
          default:
            return "WSANO_DATA";
        }
      }
    }
    else if ( Error == 10101 )
    {
      return "WSAEDISCON";
    }
    else
    {
      switch ( Error )
      {
        case 10052:
          result = "WSAENETRESET";
          break;
        case 10053:
          result = "WSAECONNABORTED";
          break;
        case 10054:
          result = "WSAECONNRESET";
          break;
        case 10055:
          result = "WSAENOBUFS";
          break;
        case 10056:
          result = "WSAEISCONN";
          break;
        case 10057:
          result = "WSAENOTCONN";
          break;
        case 10058:
          result = "WSAESHUTDOWN";
          break;
        case 10059:
          result = "WSAETOOMANYREFS";
          break;
        case 10060:
          result = "WSAETIMEDOUT";
          break;
        case 10061:
          result = "WSAECONNREFUSED";
          break;
        case 10062:
          result = "WSAELOOP";
          break;
        case 10063:
          result = "WSAENAMETOOLONG";
          break;
        case 10064:
          result = "WSAEHOSTDOWN";
          break;
        case 10065:
          result = "WSAEHOSTUNREACH";
          break;
        case 10091:
          result = "WSASYSNOTREADY";
          break;
        case 10092:
          result = "WSAVERNOTSUPPORTED";
          break;
        case 10093:
          result = "WSANOTINITIALISED";
          break;
        default:
          return "UNKNOWN ERROR";
      }
    }
  }
  else if ( Error == 10051 )
  {
    return "WSAENETUNREACH";
  }
  else
  {
    switch ( Error )
    {
      case 10004:
        result = "WSAEINTR";
        break;
      case 10009:
        result = "WSAEBADF";
        break;
      case 10013:
        result = "WSAEACCES";
        break;
      case 10014:
        result = "WSAEFAULT";
        break;
      case 10022:
        result = "WSAEINVAL";
        break;
      case 10024:
        result = "WSAEMFILE";
        break;
      case 10035:
        result = "WSAEWOULDBLOCK";
        break;
      case 10036:
        result = "WSAEINPROGRESS";
        break;
      case 10037:
        result = "WSAEALREADY";
        break;
      case 10038:
        result = "WSAENOTSOCK";
        break;
      case 10039:
        result = "WSAEDESTADDRREQ";
        break;
      case 10040:
        result = "WSAEMSGSIZE";
        break;
      case 10041:
        result = "WSAEPROTOTYPE";
        break;
      case 10042:
        result = "WSAENOPROTOOPT";
        break;
      case 10043:
        result = "WSAEPROTONOSUPPORT";
        break;
      case 10044:
        result = "WSAESOCKTNOSUPPORT";
        break;
      case 10045:
        result = "WSAEOPNOTSUPP";
        break;
      case 10046:
        result = "WSAEPFNOSUPPORT";
        break;
      case 10047:
        result = "WSAEAFNOSUPPORT";
        break;
      case 10048:
        result = "WSAEADDRINUSE";
        break;
      case 10049:
        result = "WSAEADDRNOTAVAIL";
        break;
      case 10050:
        result = "WSAENETDOWN";
        break;
      default:
        return "UNKNOWN ERROR";
    }
  }
  return result;
}


// ========================================================================
// ?Net_NetadrToSockadr@@YAXPBUnetadr_t@@PAUsockaddr_in@@@Z
// EA  : 0x82F85538
// RVA : 0x00F85538
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

void __fastcall Net_NetadrToSockadr(const netadr_t *a, sockaddr_in *s)
{
  netadrtype_t type; // r11

  *(_DWORD *)&s->sin_family = 0;
  s->sin_addr.S_un.S_addr = 0;
  *(_DWORD *)s->sin_zero = 0;
  *(_DWORD *)&s->sin_zero[4] = 0;
  type = a->type;
  if ( a->type == NA_BROADCAST )
  {
    s->sin_family = 2;
    s->sin_addr.S_un.S_addr = -1;
    s->sin_port = a->port;
  }
  else if ( type == NA_IP || type == NA_LOOPBACK )
  {
    s->sin_family = 2;
    s->sin_addr.S_un.S_addr = *(_DWORD *)a->ip;
    s->sin_port = a->port;
  }
  else
  {
    s->sin_port = a->port;
  }
}


// ========================================================================
// ?Net_WaitForData@@YA_NHH@Z
// EA  : 0x82F855A8
// RVA : 0x00F855A8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

BOOL __fastcall Net_WaitForData(unsigned int netSocket, int timeout)
{
  int v3; // r3
  int *v4; // r3
  char *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  int v9; // [sp+8h] [-168h]
  int v10; // [sp+Ch] [-164h]
  int v11; // [sp+10h] [-160h]
  int v12; // [sp+14h] [-15Ch]
  timeval v13; // [sp+50h] [-120h] BYREF
  fd_set v14; // [sp+60h] [-110h] BYREF

  if ( netSocket == 0 )
    return false;
  if ( timeout <= 0 )
    return true;
  v14.fd_array[0] = netSocket;
  v13.tv_usec = 1000 * timeout;
  v14.fd_count = 1;
  v13.tv_sec = 0;
  v3 = select(nfds: netSocket + 1, readfds: &v14, writefds: nullptr, exceptfds: nullptr, timeout: &v13);
  if ( v3 == -1 )
  {
    v4 = errno();
    v5 = strerror(errnum: *v4);
    idLib::Printf(
      fmt: __SPAIR64__("Net_WaitForUPDPacket select(): %s\n", (unsigned int)v5),
      a2: v8,
      a3: v7,
      a4: v6,
      a5: v9,
      a6: v10,
      a7: v11,
      a8: v12);
    return false;
  }
  return v3 != 0;
}


// ========================================================================
// ?Net_SendUDPPacket@@YAXHHPBXUnetadr_t@@@Z
// EA  : 0x82F85660
// RVA : 0x00F85660
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall Net_SendUDPPacket(
        unsigned int netSocket,
        int length,
        const char *data,
        __int64 to,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  char *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  int v21; // [sp+8h] [-78h]
  int v22; // [sp+Ch] [-74h]
  int v23; // [sp+10h] [-70h]
  int v24; // [sp+14h] [-6Ch]
  sockaddr_in v25[3]; // [sp+50h] [-30h] BYREF

  a13 = *(__int64 *)((char *)&to + 4);
  a14 = to;
  if ( netSocket != 0 )
  {
    Net_NetadrToSockadr(a: (const netadr_t *)&a13, s: v25);
    if ( sendto(s: netSocket, buf: data, len: length, flags: 0, to: (const sockaddr *)v25, tolen: 16) == -1
      && (WSAGetLastError() != 10049 || HIDWORD(a13) != 2) )
    {
      v17 = NET_ErrorString();
      idLib::Printf(
        fmt: __SPAIR64__("UDP sendto error - packet dropped: %s\n", (unsigned int)v17),
        a2: v20,
        a3: v19,
        a4: v18,
        a5: v21,
        a6: v22,
        a7: v23,
        a8: v24);
    }
  }
}


// ========================================================================
// ?Sys_InitNetworking@@YAXXZ
// EA  : 0x82F856F0
// RVA : 0x00F856F0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

void __fastcall Sys_InitNetworking()
{
  __int64 v0; // r10
  __int64 v1; // r8
  __int64 v2; // r6
  __int64 v3; // r4
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r4
  __int64 v8; // r4
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]
  XNetStartupParams v13; // [sp+50h] [-20h] BYREF

  v13.cfgSockMaxStreamSockets = 0;
  v13.cfgSecRegMax = 0;
  *(_DWORD *)&v13.cfgQosDataLimitDiv4 = 0;
  v13.cfgQosPairWaitTimeInSeconds = 0;
  v13.cfgSizeOfStruct = 13;
  v13.cfgFlags = 1;
  v13.cfgSockMaxDgramSockets = 64;
  v13.cfgSockDefaultRecvBufsizeInK = 32;
  v13.cfgSockDefaultSendBufsizeInK = 64;
  v13.cfgKeyRegMax = 16;
  if ( XNetStartup(pxnsp: &v13) != 0 )
  {
    HIDWORD(v3) = "XNetStartup failed.\n";
  }
  else
  {
    LODWORD(v7) = WSAStartup(wVersionRequired: 0x202u, lpWSAData: &winsockdata);
    if ( (_DWORD)v7 != 0 )
    {
      HIDWORD(v7) = "WARNING: Winsock initialization failed, returned %d\n";
      idLib::Printf(fmt: v7, a2: v6, a3: v5, a4: v4, a5: v9, a6: v10, a7: v11, a8: v12);
      return;
    }
    if ( winsockdata.wVersion != 514 )
    {
      HIDWORD(v4) = &unk_82390000;
      HIDWORD(v6) = HIBYTE(winsockdata.wVersion);
      LODWORD(v8) = LOBYTE(winsockdata.wVersion);
      HIDWORD(v8) = "Failed to get proper version of Winsock, got %d.%d.\n";
      idLib::Printf(fmt: v8, a2: v6, a3: v5, a4: v4, a5: v9, a6: v10, a7: v11, a8: v12);
    }
    winsockInitialized = true;
    if ( XOnlineStartup() != 0 )
      HIDWORD(v3) = "XOnlineStartup failed.\n";
    else
      HIDWORD(v3) = "Winsock Initialized\n";
  }
  idLib::Printf(fmt: v3, a2: v2, a3: v1, a4: v0, a5: v9, a6: v10, a7: v11, a8: v12);
}


// ========================================================================
// ?Sys_NetAdrToString@@YAPBDUnetadr_t@@@Z
// EA  : 0x82F85800
// RVA : 0x00F85800
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

char *__fastcall Sys_NetAdrToString(const netadr_t *a)
{
  int v1; // r2
  char *v2; // r31

  v2 = buf_0[index_0];
  index_0 = (index_0 + 1) & 3;
  if ( v1 == 1 )
  {
    if ( HIWORD(a) != 0 )
      idStr::snPrintf(dest: v2, size: 64, fmt: "localhost:%i", HIWORD(a));
    else
      idStr::snPrintf(dest: v2, size: 64, fmt: "localhost");
  }
  else if ( v1 == 3 )
  {
    idStr::snPrintf(
      dest: v2,
      size: 64,
      fmt: "%i.%i.%i.%i:%i",
      HIBYTE(a),
      BYTE1(a),
      BYTE2(a),
      (unsigned __int8)a,
      HIWORD(a));
  }
  return v2;
}


// ========================================================================
// ?Sys_CompareNetAdrBase@@YA_NUnetadr_t@@0@Z
// EA  : 0x82F858C8
// RVA : 0x00F858C8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

int __fastcall Sys_CompareNetAdrBase(__int64 b, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // r2
  int v6; // [sp+8h] [-58h]
  int v7; // [sp+Ch] [-54h]
  int v8; // [sp+10h] [-50h]
  int v9; // [sp+14h] [-4Ch]

  LODWORD(a4) = b;
  if ( v4 == (_DWORD)b )
  {
    if ( v4 == 1 )
      return 1;
    if ( v4 == 3 )
    {
      if ( HIBYTE(b) == HIBYTE(a2) && BYTE1(b) == BYTE1(a2) && BYTE2(b) == BYTE2(a2) && BYTE3(b) == BYTE3(a2) )
        return 1;
    }
    else
    {
      HIDWORD(b) = "Sys_CompareNetAdrBase: bad address type\n";
      idLib::Printf(fmt: b, a2, a3, a4, a5: v6, a6: v7, a7: v8, a8: v9);
    }
  }
  return 0;
}


// ========================================================================
// ??0idUDP@@QAA@XZ
// EA  : 0x82F85978
// RVA : 0x00F85978
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

idUDP *__fastcall idUDP::idUDP(idUDP *this)
{
  this->netSocket = 0;
  this->__vftable = (idUDP_vtbl *)&idUDP::`vftable';
  this->bound_to.type = NA_BAD;
  *(_DWORD *)this->bound_to.ip = 0;
  *(_DWORD *)&this->bound_to.port = 0;
  return this;
}


// ========================================================================
// ?Close@idUDP@@QAAXXZ
// EA  : 0x82F859A0
// RVA : 0x00F859A0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

void __fastcall idUDP::Close(idUDP *this)
{
  unsigned int netSocket; // r3

  netSocket = this->netSocket;
  if ( netSocket != 0 )
  {
    closesocket(s: netSocket);
    this->netSocket = 0;
    this->bound_to.type = NA_BAD;
    *(_DWORD *)this->bound_to.ip = 0;
    *(_DWORD *)&this->bound_to.port = 0;
  }
}


// ========================================================================
// ?SendPacket@idUDP@@QAAXUnetadr_t@@PBXH@Z
// EA  : 0x82F859F0
// RVA : 0x00F859F0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idUDP::SendPacket(idUDP *this, const netadr_t *to, __int64 size, __int64 a4)
{
  int v4; // r3
  int v5; // r11
  int v6; // r10
  const char *v7; // r3
  _DWORD *v8; // r3
  int v9; // r9
  __int64 v10; // r8
  unsigned int v11; // r3
  int v12; // [sp+8h] [-58h]
  int v13; // [sp+Ch] [-54h]
  __int64 v14; // [sp+10h] [-50h]
  __int64 v15; // [sp+18h] [-48h]
  __int64 v16; // [sp+20h] [-40h]
  __int64 v17; // [sp+28h] [-38h]
  __int64 v18; // [sp+30h] [-30h]
  __int64 v19; // [sp+38h] [-28h]
  __int64 v20; // [sp+40h] [-20h]

  v5 = v4;
  v6 = HIDWORD(a4);
  if ( v4 != 0 )
  {
    v9 = v8[4];
    LODWORD(v10) = v8[3] + 1;
    v11 = v8[8];
    *(_DWORD *)(v5 + 12) = v10;
    HIDWORD(v10) = __ROL4__(to, 32);
    *(_DWORD *)(v5 + 16) = v9 + v6;
    Net_SendUDPPacket(
      netSocket: v11,
      length: v6,
      data: (const char *)size,
      to: v10,
      a5: v9,
      a6: v6,
      a7: v12,
      a8: v14,
      a9: v15,
      a10: v16,
      a11: v17,
      a12: v18,
      a13: v19,
      a14: v20);
  }
  else
  {
    v7 = "idUDP::SendPacket: bad address type NA_BAD - ignored";
    idLib::Warning(
      fmt: *(__int64 *)&to,
      a2: size,
      a3: a4,
      a4: HIDWORD(a4),
      a5: v12,
      a6: v13,
      a7: SHIDWORD(v14),
      a8: v14);
  }
}


// ========================================================================
// ??0idTCP@@QAA@XZ
// EA  : 0x82F85A80
// RVA : 0x00F85A80
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

idTCP *__fastcall idTCP::idTCP(idTCP *this)
{
  this->fd = 0;
  this->__vftable = (idTCP_vtbl *)&idTCP::`vftable';
  this->address.type = NA_BAD;
  *(_DWORD *)this->address.ip = 0;
  *(_DWORD *)&this->address.port = 0;
  return this;
}


// ========================================================================
// ?Select@idTCP@@QAA_NH@Z
// EA  : 0x82F85AA8
// RVA : 0x00F85AA8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

BOOL __fastcall idTCP::Select(idTCP *this, int timeoutMS)
{
  return Net_WaitForData(netSocket: this->fd, timeout: timeoutMS);
}


// ========================================================================
// ?IsOpen@idTCP@@QBA_NXZ
// EA  : 0x82F85AB0
// RVA : 0x00F85AB0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

int __fastcall idTCP::IsOpen(idTCP *this)
{
  unsigned __int8 v1; // r11

  if ( this->fd == 0 )
    return 0;
  v1 = 1;
  if ( !winsockInitialized )
    return 0;
  return v1;
}


// ========================================================================
// ?Close@idTCP@@QAAXXZ
// EA  : 0x82F85AE0
// RVA : 0x00F85AE0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

void __fastcall idTCP::Close(idTCP *this)
{
  unsigned int fd; // r3

  fd = this->fd;
  if ( fd != 0 )
    closesocket(s: fd);
  this->fd = 0;
}


// ========================================================================
// ?Read@idTCP@@QAAHPAXH@Z
// EA  : 0x82F85B20
// RVA : 0x00F85B20
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idTCP::Read(idTCP *this, char *data, __int64 size, __int64 a4, __int64 a5)
{
  int v5; // r3
  int v6; // r31
  int v7; // r3
  const char *v8; // r3
  int result; // r3
  unsigned int v10; // r3
  char *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  unsigned int v15; // r3
  unsigned int v16; // r3
  int v17; // [sp+8h] [-58h]
  int v18; // [sp+Ch] [-54h]
  int v19; // [sp+10h] [-50h]
  int v20; // [sp+14h] [-4Ch]

  v6 = v5;
  v7 = *(_DWORD *)(v5 + 16);
  if ( v7 == 0 )
  {
    v8 = "idTCP::Read: not initialized\n";
    idLib::Printf(fmt: *(__int64 *)&data, a2: size, a3: a4, a4: a5, a5: v17, a6: v18, a7: v19, a8: v20);
    return -1;
  }
  result = recv(s: v10, buf: data, len: SHIDWORD(size), flags: 0);
  if ( result == -1 )
  {
    if ( WSAGetLastError() == 10035 )
      return 0;
    v11 = NET_ErrorString();
    idLib::Printf(
      fmt: __SPAIR64__("ERROR: idTCP::Read: %s\n", (unsigned int)v11),
      a2: v14,
      a3: v13,
      a4: v12,
      a5: v17,
      a6: v18,
      a7: v19,
      a8: v20);
    v15 = *(_DWORD *)(v6 + 16);
    if ( v15 != 0 )
      closesocket(s: v15);
    result = -1;
  }
  else
  {
    if ( result != 0 )
      return result;
    v16 = *(_DWORD *)(v6 + 16);
    if ( v16 != 0 )
      closesocket(s: v16);
    result = -2;
  }
  *(_DWORD *)(v6 + 16) = 0;
  return result;
}


// ========================================================================
// ?ReadBlocking@idTCP@@QAAHPAXHH@Z
// EA  : 0x82F85C00
// RVA : 0x00F85C00
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

int __fastcall idTCP::ReadBlocking(idTCP *this, char *data, int size, int timeoutMS)
{
  int v8; // r31
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r4
  unsigned int fd; // r3
  int result; // r3
  char *v15; // r3
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  unsigned int v19; // r3
  unsigned int v20; // r3
  int v21; // [sp+8h] [-88h]
  int v22; // [sp+Ch] [-84h]
  int v23; // [sp+10h] [-80h]
  int v24; // [sp+14h] [-7Ch]

  v8 = 0;
  if ( size > 0 )
  {
    while ( Net_WaitForData(netSocket: this->fd, timeout: timeoutMS) )
    {
      fd = this->fd;
      if ( fd == 0 )
      {
        HIDWORD(v12) = "idTCP::Read: not initialized\n";
        idLib::Printf(fmt: v12, a2: v11, a3: v10, a4: v9, a5: v21, a6: v22, a7: v23, a8: v24);
        return -1;
      }
      result = recv(s: fd, buf: &data[v8], len: size - v8, flags: 0);
      if ( result == -1 )
      {
        if ( WSAGetLastError() != 10035 )
        {
          v15 = NET_ErrorString();
          idLib::Printf(
            fmt: __SPAIR64__("ERROR: idTCP::Read: %s\n", (unsigned int)v15),
            a2: v18,
            a3: v17,
            a4: v16,
            a5: v21,
            a6: v22,
            a7: v23,
            a8: v24);
          v19 = this->fd;
          if ( v19 != 0 )
            closesocket(s: v19);
          this->fd = 0;
          return -1;
        }
        result = 0;
      }
      else
      {
        if ( result == 0 )
        {
          v20 = this->fd;
          if ( v20 != 0 )
            closesocket(s: v20);
          this->fd = 0;
          return -2;
        }
        if ( result < 0 )
          return result;
      }
      v8 += result;
      if ( v8 >= size )
        return v8;
    }
  }
  return v8;
}


// ========================================================================
// ?Write@idTCP@@QAAHPBXH@Z
// EA  : 0x82F85D10
// RVA : 0x00F85D10
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idTCP::Write(idTCP *this, const char *data, __int64 size, __int64 a4, __int64 a5)
{
  int v5; // r3
  int v6; // r31
  int v7; // r3
  const char *v8; // r3
  unsigned int v9; // r3
  int result; // r3
  char *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  unsigned int v15; // r3
  int v16; // [sp+8h] [-58h]
  int v17; // [sp+Ch] [-54h]
  int v18; // [sp+10h] [-50h]
  int v19; // [sp+14h] [-4Ch]

  v6 = v5;
  v7 = *(_DWORD *)(v5 + 16);
  if ( v7 != 0 )
  {
    result = send(s: v9, buf: data, len: SHIDWORD(size), flags: 0);
    if ( result != -1 )
      return result;
    if ( WSAGetLastError() == 10035 )
      return 0;
    v11 = NET_ErrorString();
    idLib::Printf(
      fmt: __SPAIR64__("ERROR: idTCP::Write: %s\n", (unsigned int)v11),
      a2: v14,
      a3: v13,
      a4: v12,
      a5: v16,
      a6: v17,
      a7: v18,
      a8: v19);
    v15 = *(_DWORD *)(v6 + 16);
    if ( v15 != 0 )
      closesocket(s: v15);
    *(_DWORD *)(v6 + 16) = 0;
  }
  else
  {
    v8 = "idTCP::Write: not initialized\n";
    idLib::Printf(fmt: *(__int64 *)&data, a2: size, a3: a4, a4: a5, a5: v16, a6: v17, a7: v18, a8: v19);
  }
  return -1;
}


// ========================================================================
// ?WriteBlocking@idTCP@@QAAHPBXHH@Z
// EA  : 0x82F85DB8
// RVA : 0x00F85DB8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idTCP::WriteBlocking(idTCP *this, const char *data, __int64 timeoutMS, __int64 a4, __int64 a5)
{
  int v5; // r3
  int v6; // r29
  int v8; // r30
  int v9; // r27
  int v10; // r31
  unsigned int v11; // r3
  int result; // r3
  unsigned int v13; // r11
  int *v14; // r3
  char *v15; // r3
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  const char *v19; // r3
  char *v20; // r3
  __int64 v21; // r10
  __int64 v22; // r8
  __int64 v23; // r6
  unsigned int v24; // r3
  int v25; // [sp+8h] [-1A8h]
  int v26; // [sp+Ch] [-1A4h]
  int v27; // [sp+10h] [-1A0h]
  int v28; // [sp+14h] [-19Ch]
  timeval v29; // [sp+50h] [-160h] BYREF
  fd_set v30; // [sp+60h] [-150h] BYREF

  v6 = v5;
  v8 = HIDWORD(timeoutMS);
  v9 = timeoutMS;
  v10 = 0;
  if ( SHIDWORD(timeoutMS) <= 0 )
    return v10;
  while ( 1 )
  {
    v11 = *(_DWORD *)(v6 + 16);
    if ( v11 == 0 )
    {
      v19 = "idTCP::Write: not initialized\n";
      idLib::Printf(fmt: *(__int64 *)&data, a2: timeoutMS, a3: a4, a4: a5, a5: v25, a6: v26, a7: v27, a8: v28);
      return -1;
    }
    result = send(s: v11, buf: &data[v10], len: v8 - v10, flags: 0);
    if ( result != -1 )
    {
      if ( result < 0 )
        return result;
      goto LABEL_7;
    }
    if ( WSAGetLastError() != 10035 )
      break;
    result = 0;
LABEL_7:
    v10 += result;
    if ( v10 != v8 )
    {
      v13 = *(_DWORD *)(v6 + 16);
      v30.fd_count = 1;
      v29.tv_sec = 0;
      v29.tv_usec = 1000 * v9;
      v30.fd_array[0] = v13;
      if ( select(nfds: v13 + 1, readfds: nullptr, writefds: &v30, exceptfds: nullptr, timeout: &v29) == -1 )
      {
        v14 = errno();
        v15 = strerror(errnum: *v14);
        idLib::Printf(
          fmt: __SPAIR64__("idTCP::WriteBlocking select(): %s\n", (unsigned int)v15),
          a2: v18,
          a3: v17,
          a4: v16,
          a5: v25,
          a6: v26,
          a7: v27,
          a8: v28);
      }
      if ( v10 < v8 )
        continue;
    }
    return v10;
  }
  v20 = NET_ErrorString();
  idLib::Printf(
    fmt: __SPAIR64__("ERROR: idTCP::Write: %s\n", (unsigned int)v20),
    a2: v23,
    a3: v22,
    a4: v21,
    a5: v25,
    a6: v26,
    a7: v27,
    a8: v28);
  v24 = *(_DWORD *)(v6 + 16);
  if ( v24 != 0 )
    closesocket(s: v24);
  *(_DWORD *)(v6 + 16) = 0;
  return -1;
}


// ========================================================================
// Net_ExtractPort
// EA  : 0x82F85EF0
// RVA : 0x00F85EF0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

char *__fastcall Net_ExtractPort(const char *src, char *buf, int bufsize, int *port)
{
  int v8; // r11
  char *result; // r3
  int *v10; // r3

  idStr::Copynz(dest: buf, src, destsize: bufsize);
  v8 = 0;
  if ( *src != 0 )
  {
    do
      ++v8;
    while ( src[v8] != 0 );
  }
  if ( bufsize - 1 < v8 )
    v8 = bufsize - 1;
  buf[v8] = 0;
  result = strchr(Str: buf, Val: 58);
  if ( result != nullptr )
  {
    *result = 0;
    *port = strtol(nptr: result + 1, endptr: nullptr, ibase: 10);
    v10 = errno();
    return (char *)(*v10 - 34 - (*v10 - 35 + (*v10 == 34)));
  }
  return result;
}


// ========================================================================
// Net_StringToSockaddr
// EA  : 0x82F85FA0
// RVA : 0x00F85FA0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

unsigned int __fastcall Net_StringToSockaddr(const char *s, sockaddr_in *sadr, bool doDNSResolve)
{
  in_addr::<unnamed_type_S_un> v5; // r3
  in_addr::<unnamed_type_S_un> v7; // r3
  unsigned __int16 v8; // r11
  unsigned __int8 Port; // r28
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  XNDNS *v13; // r3
  int cina; // r29
  __int64 v15; // r4
  int v16; // [sp+8h] [-188h]
  int v17; // [sp+Ch] [-184h]
  int v18; // [sp+10h] [-180h]
  int v19; // [sp+14h] [-17Ch]
  XNDNS *v20; // [sp+50h] [-140h] BYREF
  int v21[3]; // [sp+54h] [-13Ch] BYREF
  char v22[304]; // [sp+60h] [-130h] BYREF

  *(_DWORD *)&sadr->sin_family = 0;
  sadr->sin_addr.S_un.S_addr = 0;
  *(_DWORD *)sadr->sin_zero = 0;
  *(_DWORD *)&sadr->sin_zero[4] = 0;
  sadr->sin_family = 2;
  sadr->sin_port = 0;
  if ( *s >= 48 && *s <= 57 )
  {
    v5.S_addr = inet_addr(cp: s);
    if ( v5.S_addr != -1 )
    {
      sadr->sin_addr.S_un = v5;
      return 1;
    }
    if ( (unsigned __int8)Net_ExtractPort(src: s, buf: v22, bufsize: 256, port: v21) != 0 )
    {
      v7.S_addr = inet_addr(cp: v22);
      if ( v7.S_addr != -1 )
      {
        v8 = v21[0];
        sadr->sin_addr.S_un = v7;
        sadr->sin_port = v8;
        return 1;
      }
    }
    return 0;
  }
  if ( !doDNSResolve )
    return 1;
  v20 = nullptr;
  Port = (unsigned __int8)Net_ExtractPort(src: s, buf: v22, bufsize: 256, port: v21);
  if ( XNetDnsLookup(pszHost: v22, hEvent: nullptr, ppxndns: &v20) != 0 )
    return 0;
  v13 = v20;
  for ( HIDWORD(v12) = v20->iStatus; v20->iStatus == 10036; HIDWORD(v12) = v20->iStatus )
  {
    mgthread_sleep(ms: 50);
    v13 = v20;
  }
  cina = 0;
  if ( HIDWORD(v12) != 0 )
  {
    LODWORD(v15) = v22;
    HIDWORD(v15) = "Failed to resolved hostname '%s' with status %d";
    idLib::Warning(fmt: v15, a2: v12, a3: v11, a4: v10, a5: v16, a6: v17, a7: v18, a8: v19);
    v13 = v20;
  }
  else
  {
    cina = v13->cina;
    if ( cina > 0 )
    {
      sadr->sin_addr.S_un.S_addr = v13->aina[0].S_un.S_addr;
      if ( Port != 0 )
        sadr->sin_port = v21[0];
      else
        sadr->sin_port = 0;
    }
  }
  XNetDnsRelease(pxndns: v13);
  return (-cina & (unsigned int)~cina) >> 31;
}


// ========================================================================
// ?NET_IPSocket@@YAHPBDHPAUnetadr_t@@_N@Z
// EA  : 0x82F86158
// RVA : 0x00F86158
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

unsigned int __fastcall NET_IPSocket(const char *net_interface, int port, __int64 useBackend, __int64 a4, __int64 a5)
{
  const char *v5; // r31
  int v7; // r26
  char v8; // r30
  int v9; // r5
  unsigned int v10; // r3
  unsigned int v11; // r27
  char *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  char *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  char *v21; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  char *v25; // r3
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  __int16 v29; // r9
  bool v30; // cr58
  int v31; // [sp+8h] [-A8h]
  int v32; // [sp+Ch] [-A4h]
  int v33; // [sp+10h] [-A0h]
  int v34; // [sp+14h] [-9Ch]
  unsigned int v35; // [sp+50h] [-60h] BYREF
  int v36[3]; // [sp+54h] [-5Ch] BYREF
  sockaddr v37[5]; // [sp+60h] [-50h] BYREF

  v5 = net_interface;
  v35 = 1;
  v7 = HIDWORD(useBackend);
  v8 = useBackend;
  if ( net_interface == nullptr )
    v5 = "localhost";
  if ( port != -1 )
  {
    HIDWORD(useBackend) = port;
    idLib::Printf(
      fmt: __SPAIR64__("Opening IP socket: %s:%i\n", (unsigned int)v5),
      a2: useBackend,
      a3: a4,
      a4: a5,
      a5: v31,
      a6: v32,
      a7: v33,
      a8: v34);
  }
  v9 = 254;
  if ( v8 == 0 )
    v9 = 17;
  v10 = socket(af: 2, type: 2, protocol: v9);
  v11 = v10;
  if ( v10 == -1 )
  {
    if ( WSAGetLastError() != 10047 )
    {
      v12 = NET_ErrorString();
      idLib::Printf(
        fmt: __SPAIR64__("WARNING: UDP_OpenSocket: socket: %s\n", (unsigned int)v12),
        a2: v15,
        a3: v14,
        a4: v13,
        a5: v31,
        a6: v32,
        a7: v33,
        a8: v34);
    }
    return 0;
  }
  else
  {
    if ( ioctlsocket(s: v10, cmd: -2147195266, argp: &v35) == -1 )
    {
      v17 = NET_ErrorString();
      idLib::Printf(
        fmt: __SPAIR64__("WARNING: UDP_OpenSocket: ioctl FIONBIO: %s\n", (unsigned int)v17),
        a2: v20,
        a3: v19,
        a4: v18,
        a5: v31,
        a6: v32,
        a7: v33,
        a8: v34);
      closesocket(s: v11);
      return 0;
    }
    if ( v8 == 0 && setsockopt(s: v11, level: 0xFFFF, optname: 32, optval: (const char *)&v35, optlen: 4) == -1 )
    {
      v21 = NET_ErrorString();
      idLib::Printf(
        fmt: __SPAIR64__("WARNING: UDP_OpenSocket: setsockopt SO_BROADCAST: %s\n", (unsigned int)v21),
        a2: v24,
        a3: v23,
        a4: v22,
        a5: v31,
        a6: v32,
        a7: v33,
        a8: v34);
      closesocket(s: v11);
      return 0;
    }
    if ( idStr::Icmp(s1: v5, s2: "localhost") != 0 )
      Net_StringToSockaddr(s: v5, sadr: (sockaddr_in *)v37, doDNSResolve: true);
    else
      *(_DWORD *)&v37[0].sa_data[2] = 0;
    *(_WORD *)v37[0].sa_data = 0;
    if ( port != -1 )
      *(_WORD *)v37[0].sa_data = port;
    v37[0].sa_family = 2;
    if ( bind(s: v11, name: v37, namelen: 16) == -1 )
    {
      v25 = NET_ErrorString();
      idLib::Printf(
        fmt: __SPAIR64__("WARNING: UDP_OpenSocket: bind: %s\n", (unsigned int)v25),
        a2: v28,
        a3: v27,
        a4: v26,
        a5: v31,
        a6: v32,
        a7: v33,
        a8: v34);
      closesocket(s: v11);
      return 0;
    }
    if ( v7 != 0 )
    {
      v36[0] = 16;
      getsockname(s: v11, name: v37, namelen: v36);
      if ( v37[0].sa_family == 2 )
      {
        v29 = *(_WORD *)v37[0].sa_data;
        v30 = *(_DWORD *)&v37[0].sa_data[2] == 2130706433;
        *(_DWORD *)(v7 + 4) = *(_DWORD *)&v37[0].sa_data[2];
        *(_WORD *)(v7 + 8) = v29;
        if ( v30 )
        {
          *(_DWORD *)v7 = 1;
          return v11;
        }
        *(_DWORD *)v7 = 3;
      }
    }
    return v11;
  }
}


// ========================================================================
// ?Net_GetUDPPacket@@YA_NHAAUnetadr_t@@PADAAHH@Z
// EA  : 0x82F86398
// RVA : 0x00F86398
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

int __fastcall Net_GetUDPPacket(unsigned int netSocket, netadr_t *net_from, char *data, int *size, int maxSize)
{
  int v8; // r3
  int Error; // r3
  const char *v10; // r3
  __int64 v11; // r4
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  unsigned __int16 v16; // r9
  bool v17; // cr58
  netadrtype_t v18; // r11
  char *v19; // r3
  __int64 v20; // r4
  __int64 v21; // r10
  __int64 v22; // r8
  __int64 v23; // r6
  int v24; // [sp+8h] [-488h]
  int v25; // [sp+Ch] [-484h]
  int v26; // [sp+10h] [-480h]
  int v27; // [sp+14h] [-47Ch]
  int v28[4]; // [sp+50h] [-440h] BYREF
  sockaddr v29; // [sp+60h] [-430h] BYREF
  char v30[1056]; // [sp+70h] [-420h] BYREF

  if ( netSocket == 0 )
    return 0;
  v28[0] = 16;
  v8 = recvfrom(s: netSocket, buf: data, len: maxSize, flags: 0, from: &v29, fromlen: v28);
  if ( v8 == -1 )
  {
    Error = WSAGetLastError();
    if ( Error != 10035 && Error != 10054 )
    {
      v10 = NET_ErrorString();
      sprintf_0(string: v30, format: "Net_GetUDPPacket: %s\n", v10);
      HIDWORD(v11) = v30;
      idLib::Printf(fmt: v11, a2: v14, a3: v13, a4: v12, a5: v24, a6: v25, a7: v26, a8: v27);
    }
    return 0;
  }
  if ( v29.sa_family == 2 )
  {
    v16 = *(_WORD *)v29.sa_data;
    v17 = *(_DWORD *)&v29.sa_data[2] == 2130706433;
    *(_DWORD *)net_from->ip = *(_DWORD *)&v29.sa_data[2];
    v18 = NA_LOOPBACK;
    net_from->port = v16;
    if ( !v17 )
      v18 = NA_IP;
    net_from->type = v18;
  }
  if ( v8 <= maxSize )
  {
    *size = v8;
    return 1;
  }
  else
  {
    v19 = Sys_NetAdrToString(a: *(const netadr_t **)net_from->ip);
    sprintf_0(string: v30, format: "Net_GetUDPPacket: oversize packet from %s\n", v19);
    HIDWORD(v20) = v30;
    idLib::Printf(fmt: v20, a2: v23, a3: v22, a4: v21, a5: v24, a6: v25, a7: v26, a8: v27);
    return 0;
  }
}


// ========================================================================
// ?Sys_StringToNetAdr@@YA_NPBDPAUnetadr_t@@_N@Z
// EA  : 0x82F864A8
// RVA : 0x00F864A8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

int __fastcall Sys_StringToNetAdr(const char *s, netadr_t *a, bool doDNSResolve)
{
  unsigned __int16 sin_port; // r9
  bool v6; // cr58
  netadrtype_t v7; // r11
  sockaddr_in v8; // [sp+50h] [-20h] BYREF

  if ( (unsigned __int8)Net_StringToSockaddr(s, sadr: &v8, doDNSResolve) == 0 )
    return 0;
  if ( v8.sin_family == 2 )
  {
    sin_port = v8.sin_port;
    v6 = v8.sin_addr.S_un.S_addr == 2130706433;
    *(_DWORD *)a->ip = v8.sin_addr.S_un.S_addr;
    v7 = NA_LOOPBACK;
    a->port = sin_port;
    if ( !v6 )
      v7 = NA_IP;
    a->type = v7;
  }
  return 1;
}


// ========================================================================
// ??1idUDP@@UAA@XZ
// EA  : 0x82F86538
// RVA : 0x00F86538
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

void __fastcall idUDP::~idUDP(idUDP *this)
{
  unsigned int netSocket; // r3

  netSocket = this->netSocket;
  this->__vftable = (idUDP_vtbl *)&idUDP::`vftable';
  if ( netSocket != 0 )
  {
    closesocket(s: netSocket);
    this->netSocket = 0;
    this->bound_to.type = NA_BAD;
    *(_DWORD *)this->bound_to.ip = 0;
    *(_DWORD *)&this->bound_to.port = 0;
  }
}


// ========================================================================
// ?InitForPort@idUDP@@QAA_NH_N@Z
// EA  : 0x82F86590
// RVA : 0x00F86590
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

int __fastcall idUDP::InitForPort(idUDP *this, int portNumber, int useBackend, int a4, __int64 a5, __int64 a6)
{
  unsigned int netSocket; // r3
  __int64 v10; // r6
  signed int v11; // r3

  netSocket = this->netSocket;
  if ( netSocket != 0 )
  {
    closesocket(s: netSocket);
    this->netSocket = 0;
    this->bound_to.type = NA_BAD;
    *(_DWORD *)this->bound_to.ip = 0;
    *(_DWORD *)&this->bound_to.port = 0;
  }
  LODWORD(a6) = &net_ip;
  LODWORD(v10) = useBackend;
  HIDWORD(v10) = &this->bound_to;
  v11 = NET_IPSocket(net_interface: net_ip.valueString.data, port: portNumber, useBackend: v10, a4: a5, a5: a6);
  this->netSocket = v11;
  if ( v11 > 0 )
    return 1;
  this->netSocket = 0;
  this->bound_to.type = NA_BAD;
  *(_DWORD *)this->bound_to.ip = 0;
  *(_DWORD *)&this->bound_to.port = 0;
  return 0;
}


// ========================================================================
// ?GetPacket@idUDP@@QAA_NAAUnetadr_t@@PAXAAHH@Z
// EA  : 0x82F86620
// RVA : 0x00F86620
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

int __fastcall idUDP::GetPacket(idUDP *this, netadr_t *from, char *data, int *size, int maxSize)
{
  int bytesRead; // r10

  if ( (unsigned __int8)Net_GetUDPPacket(netSocket: this->netSocket, net_from: from, data, size, maxSize) == 0 )
    return 0;
  bytesRead = this->bytesRead;
  ++this->packetsRead;
  this->bytesRead = *size + bytesRead;
  return 1;
}


// ========================================================================
// ??1idTCP@@UAA@XZ
// EA  : 0x82F86690
// RVA : 0x00F86690
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

void __fastcall idTCP::~idTCP(idTCP *this)
{
  unsigned int fd; // r3

  fd = this->fd;
  this->__vftable = (idTCP_vtbl *)&idTCP::`vftable';
  if ( fd != 0 )
    closesocket(s: fd);
  this->fd = 0;
}


// ========================================================================
// ?Connect@idTCP@@QAA_NPBDG_N11@Z
// EA  : 0x82F866E0
// RVA : 0x00F866E0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

int __fastcall idTCP::Connect(
        idTCP *this,
        const char *host,
        unsigned __int16 port,
        bool nonBlocking,
        bool silent,
        bool nagle)
{
  netadr_t *p_address; // r30
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  int v14; // r11
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  __int64 v18; // r4
  unsigned int v19; // r3
  char *v20; // r3
  __int64 v21; // r10
  __int64 v22; // r8
  __int64 v23; // r6
  char *v24; // r3
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  unsigned int fd; // r3
  char *v29; // r3
  __int64 v30; // r10
  __int64 v31; // r8
  __int64 v32; // r6
  unsigned int v33; // r3
  int v34; // [sp+8h] [-98h]
  int v35; // [sp+Ch] [-94h]
  int v36; // [sp+10h] [-90h]
  int v37; // [sp+14h] [-8Ch]
  unsigned int v38[4]; // [sp+50h] [-50h] BYREF
  sockaddr_in v39[4]; // [sp+60h] [-40h] BYREF

  v38[0] = 1;
  p_address = &this->address;
  LODWORD(v10) = (unsigned __int8)Sys_StringToNetAdr(s: host, a: &this->address, doDNSResolve: true);
  if ( (_DWORD)v10 == 0 )
  {
    idLib::Printf(
      fmt: __SPAIR64__("Couldn't resolve server name \"%s\"\n", (unsigned int)host),
      a2: v12,
      a3: v11,
      a4: v10,
      a5: v34,
      a6: v35,
      a7: v36,
      a8: v37);
    return 0;
  }
  v14 = this->address.port;
  p_address->type = NA_IP;
  if ( v14 == 0 )
    this->address.port = port;
  Net_NetadrToSockadr(a: p_address, s: v39);
  if ( this->fd != 0 )
  {
    HIDWORD(v18) = "idTCP::Connect: already initialized?";
    idLib::Warning(fmt: v18, a2: v17, a3: v16, a4: v15, a5: v34, a6: v35, a7: v36, a8: v37);
  }
  v19 = socket(af: 2, type: 1, protocol: 0);
  this->fd = v19;
  if ( v19 == -1 )
  {
    this->fd = 0;
    v20 = NET_ErrorString();
    LODWORD(v21) = &unk_82390000;
    idLib::Printf(
      fmt: __SPAIR64__("ERROR: idTCP::Connect: socket: %s\n", (unsigned int)v20),
      a2: v23,
      a3: v22,
      a4: v21,
      a5: v34,
      a6: v35,
      a7: v36,
      a8: v37);
    return 0;
  }
  if ( connect(s: v19, name: (const sockaddr *)v39, namelen: 16) == -1 )
  {
    v24 = NET_ErrorString();
    idLib::Printf(
      fmt: __SPAIR64__("ERROR: idTCP::Connect: connect: %s\n", (unsigned int)v24),
      a2: v27,
      a3: v26,
      a4: v25,
      a5: v34,
      a6: v35,
      a7: v36,
      a8: v37);
    fd = this->fd;
    if ( fd != 0 )
      closesocket(s: fd);
    goto LABEL_12;
  }
  if ( ioctlsocket(s: this->fd, cmd: -2147195266, argp: v38) != -1 )
    return 1;
  v29 = NET_ErrorString();
  idLib::Printf(
    fmt: __SPAIR64__("ERROR: idTCP::Connect: ioctl FIONBIO: %s\n", (unsigned int)v29),
    a2: v32,
    a3: v31,
    a4: v30,
    a5: v34,
    a6: v35,
    a7: v36,
    a8: v37);
  v33 = this->fd;
  if ( v33 == 0 )
  {
LABEL_12:
    this->fd = 0;
    return 0;
  }
  closesocket(s: v33);
  this->fd = 0;
  return 0;
}


// ========================================================================
// `dynamic initializer for 'net_ip''
// EA  : 0x833972D0
// RVA : 0x013972D0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_net.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ip__()
{
  idCVar::idCVar(
    this: &net_ip,
    name: "net_ip",
    value: "localhost",
    flags: 0,
    description: "local IP address",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ip__);
}

