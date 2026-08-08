
// ========================================================================
// ?Connect@Connection@idRpc@@QAA_NPBDI@Z
// EA  : 0x82F121E8
// RVA : 0x00F121E8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

BOOL __fastcall idRpc::Connection::Connect(idRpc::Connection *this, const char *host, unsigned __int16 port)
{
  idStr::operator=(this: &this->host, text: host);
  this->rest = 0;
  return idTCP::Connect(this: &this->sock, host, port, nonBlocking: true, silent: false, nagle: false);
}


// ========================================================================
// ?Recv@Connection@idRpc@@QAA_NPAXH@Z
// EA  : 0x82F12240
// RVA : 0x00F12240
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idRpc::Connection::Recv(idRpc::Connection *this, void *buf, int size)
{
  idTCP *p_sock; // r29
  int Blocking; // r4

  p_sock = &this->sock;
  Blocking = idTCP::ReadBlocking(this: &this->sock, data: buf, size, timeoutMS: 5000);
  if ( Blocking == size )
  {
    this->rest -= size;
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "NFS: data read failed, %d of %d bytes received", Blocking, size);
    idTCP::Close(this: p_sock);
    return 0;
  }
}


// ========================================================================
// ?NfsErrToStr@idNfsClient@@QAAPBDW4NfsErr@1@@Z
// EA  : 0x82F122B0
// RVA : 0x00F122B0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

const char *__fastcall idNfsClient::NfsErrToStr(idNfsClient *this, unsigned int err)
{
  if ( err > 4 )
    return "unknown";
  switch ( err )
  {
    case 1u:
      return "NFS_ERR_CON";
    case 2u:
      return "NFS_ERR_NOENT";
    case 3u:
      return "NFS_ERR_ACCESS";
    default:
      break;
  }
  if ( err != 0 )
    return "NFS_ERR_OTHER";
  return "NFS_OK";
}


// ========================================================================
// ?DecodeNfs4Error@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@I@Z
// EA  : 0x82F12318
// RVA : 0x00F12318
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::DecodeNfs4Error(idNfs4Client *this, unsigned int nfs4Err)
{
  if ( nfs4Err <= 0xD )
  {
    if ( nfs4Err != 13 )
    {
      if ( nfs4Err == 0 )
        return 0;
      if ( nfs4Err != 1 )
      {
        if ( nfs4Err < 3 )
          return 2;
        return 4;
      }
    }
  }
  else if ( nfs4Err != 30 )
  {
    if ( nfs4Err != 10036 )
      return 4;
    return 1;
  }
  return 3;
}


// ========================================================================
// ?DecodeMnt3Error@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@I@Z
// EA  : 0x82F12370
// RVA : 0x00F12370
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::DecodeMnt3Error(idNfs3Client *this, unsigned int nfs4Err)
{
  if ( nfs4Err > 2 )
  {
    if ( nfs4Err == 13 )
      return 3;
    if ( nfs4Err == 10006 )
      return 1;
    else
      return 4;
  }
  else if ( nfs4Err == 2 )
  {
    return 2;
  }
  else
  {
    if ( nfs4Err != 0 )
      return 3;
    return 0;
  }
}


// ========================================================================
// ?Write@idNfs3Client@@UAAIPAVNfsFh@idNfsClient@@_JIPBX@Z
// EA  : 0x82F123C0
// RVA : 0x00F123C0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

unsigned int __fastcall idNfs3Client::Write(
        idNfs3Client *this,
        idNfsClient::NfsFh *fh,
        __int64 offset,
        unsigned int len,
        const void *buffer)
{
  idLib::Warning(fmt: "idNfs3Client::Write: not implemented in nfs3", fh, offset, len, buffer);
  return 0;
}


// ========================================================================
// ?SetSize@idNfs3Client@@UAA_NPAVNfsFh@idNfsClient@@_J@Z
// EA  : 0x82F123F0
// RVA : 0x00F123F0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::SetSize(idNfs3Client *this, idNfsClient::NfsFh *fh, __int64 size)
{
  idLib::Warning(fmt: "idNfs3Client::SetSize: not implemented in nfs3", fh, size);
  return 0;
}


// ========================================================================
// ?CreateDir@idNfs3Client@@UAA_NPBD@Z
// EA  : 0x82F12420
// RVA : 0x00F12420
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::CreateDir(idNfs3Client *this, const char *path)
{
  idLib::Warning(fmt: "idNfs3Client::CreateDir: not implemented in nfs3 (%s)", path);
  return 0;
}


// ========================================================================
// ?RemoveFileDir@idNfs3Client@@UAA_NPBD@Z
// EA  : 0x82F12450
// RVA : 0x00F12450
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::RemoveFileDir(idNfs3Client *this, const char *path)
{
  idLib::Warning(fmt: "idNfs3Client::RemoveFileDir: not implemented in nfs3 (%s)", path);
  return 0;
}


// ========================================================================
// ?Commit@idNfs3Client@@UAA_NPAVNfsFh@idNfsClient@@_J1@Z
// EA  : 0x82F12480
// RVA : 0x00F12480
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::Commit(idNfs3Client *this, idNfsClient::NfsFh *fh, __int64 offset, __int64 size)
{
  idLib::Warning(fmt: "idNfs3Client::Commit: not implemented in nfs3", fh, offset, size);
  return 0;
}


// ========================================================================
// ?ReadOfs@idFile_Nfs@@UAAI_JPAXI@Z
// EA  : 0x82F124B0
// RVA : 0x00F124B0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient *__fastcall idFile_Nfs::ReadOfs(idFile_Nfs *this, int a2, __int64 offset, void *buffer, unsigned int len)
{
  idNfsClient *result; // r3
  unsigned __int64 v8; // r9

  result = this->nfsClient;
  this->demandSeek = false;
  if ( result != nullptr )
  {
    result = (idNfsClient *)((int (__fastcall *)(idNfsClient *, idFile_Nfs::NfsInternalFh *, int, _DWORD, _DWORD, unsigned int))result->Read)(
                              a1: result,
                              a2: &this->fh,
                              a3: a2,
                              a4: offset,
                              a5: HIDWORD(offset),
                              a6: len);
    LODWORD(v8) = (char *)result + a2;
    this->position = v8;
  }
  return result;
}


// ========================================================================
// ?WriteOfs@idFile_Nfs@@UAAI_JPBXI@Z
// EA  : 0x82F12520
// RVA : 0x00F12520
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient *__fastcall idFile_Nfs::WriteOfs(
        idFile_Nfs *this,
        int a2,
        __int64 offset,
        const void *buffer,
        unsigned int len)
{
  idNfsClient *result; // r3
  unsigned __int64 v8; // r9

  result = this->nfsClient;
  this->demandSeek = false;
  if ( result != nullptr )
  {
    result = (idNfsClient *)((int (__fastcall *)(idNfsClient *, idFile_Nfs::NfsInternalFh *, int, _DWORD, _DWORD, unsigned int))result->Write)(
                              a1: result,
                              a2: &this->fh,
                              a3: a2,
                              a4: offset,
                              a5: HIDWORD(offset),
                              a6: len);
    LODWORD(v8) = (char *)result + a2;
    this->position = v8;
  }
  return result;
}


// ========================================================================
// ?Read@idFile_Nfs@@UAAIPAXI@Z
// EA  : 0x82F12590
// RVA : 0x00F12590
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

unsigned int __fastcall idFile_Nfs::Read(idFile_Nfs *this, void *buffer, unsigned int len)
{
  if ( this->demandSeek
    && AssertFailed(
         file: "w:\\tech5\\shared\\idlib\\filesystem\\File_NFS.cpp",
         line: 3688,
         expression: "!demandSeek",
         inlineBreak: true) )
  {
    __trap();
  }
  return this->ReadOfs(this, a2: LODWORD(this->position), a3: buffer, a4: len);
}


// ========================================================================
// ?Write@idFile_Nfs@@UAAIPBXI@Z
// EA  : 0x82F12608
// RVA : 0x00F12608
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

unsigned int __fastcall idFile_Nfs::Write(idFile_Nfs *this, const void *buffer, unsigned int len)
{
  if ( this->demandSeek
    && AssertFailed(
         file: "w:\\tech5\\shared\\idlib\\filesystem\\File_NFS.cpp",
         line: 3698,
         expression: "!demandSeek",
         inlineBreak: true) )
  {
    __trap();
  }
  return this->WriteOfs(this, a2: LODWORD(this->position), a3: buffer, a4: len);
}


// ========================================================================
// ?Flush@idFile_Nfs@@UAAXXZ
// EA  : 0x82F12680
// RVA : 0x00F12680
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idFile_Nfs::Flush(idFile_Nfs *this)
{
  idNfsClient *nfsClient; // r11

  nfsClient = this->nfsClient;
  if ( nfsClient != nullptr )
    nfsClient->Commit(this: this->nfsClient, a2: (idNfsClient::NfsFh *)&this->fh, a3: 0, a4: 0);
}


// ========================================================================
// ?Tell@idFile_Nfs@@UBA_JXZ
// EA  : 0x82F126B8
// RVA : 0x00F126B8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idFile_Nfs::Tell(idFile_Nfs *this)
{
  __int64 result; // r4 OVERLAPPED

  *(__int64 *)((char *)&result + 4) = this->position;
  return result;
}


// ========================================================================
// ?Length@idFile_Nfs@@UBA_JXZ
// EA  : 0x82F126C0
// RVA : 0x00F126C0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idFile_Nfs::Length(idFile_Nfs *this)
{
  int result; // r3
  bool v2; // zf
  _QWORD v3[3]; // [sp+50h] [-20h] BYREF

  if ( this->nfsClient == nullptr )
    return 0;
  v2 = !this->nfsClient->GetAttr(
          this: this->nfsClient,
          a2: (idNfsClient::NfsFh *)&this->fh,
          a3: (idNfsClient::NfsFileAttr *)v3);
  result = 0;
  if ( !v2 )
    return v3[0];
  return result;
}


// ========================================================================
// ?SetLength@idFile_Nfs@@UAAXI@Z
// EA  : 0x82F12730
// RVA : 0x00F12730
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idFile_Nfs::SetLength(idFile_Nfs *this, unsigned int len)
{
  idNfsClient *nfsClient; // r3

  nfsClient = this->nfsClient;
  this->demandSeek = true;
  if ( nfsClient != nullptr )
    nfsClient->SetSize(this: nfsClient, a2: (idNfsClient::NfsFh *)&this->fh, a3: len);
}


// ========================================================================
// ?Timestamp@idFile_Nfs@@UBAIXZ
// EA  : 0x82F12768
// RVA : 0x00F12768
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

unsigned int __fastcall idFile_Nfs::Timestamp(idFile_Nfs *this)
{
  _BYTE v2[8]; // [sp+50h] [-20h] BYREF
  __int64 v3; // [sp+58h] [-18h]

  if ( this->nfsClient != nullptr
    && this->nfsClient->GetAttr(
         this: this->nfsClient,
         a2: (idNfsClient::NfsFh *)&this->fh,
         a3: (idNfsClient::NfsFileAttr *)v2) )
  {
    return v3;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Seek@idFile_Nfs@@UAAH_JW4fsOrigin_t@@@Z
// EA  : 0x82F127D8
// RVA : 0x00F127D8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idFile_Nfs::Seek(idFile_Nfs *this, int a2, __int64 offset, fsOrigin_t origin)
{
  idFile_Nfs_vtbl *v4; // r10
  int v7; // r29
  unsigned __int64 position; // r11
  int result; // r3 OVERLAPPED

  v4 = this->__vftable;
  this->demandSeek = false;
  v7 = HIDWORD(offset);
  result = ((int (*)(void))v4->Length)();
  switch ( v7 )
  {
    case 1:
      LODWORD(position) = result - a2;
      break;
    case 2:
      LODWORD(position) = a2;
      break;
    case 0:
      position = this->position;
      LODWORD(position) = position + a2;
      break;
    default:
      LODWORD(position) = 0;
      goto LABEL_11;
  }
  if ( (position & 0x80000000) != 0LL )
  {
    LODWORD(position) = 0;
LABEL_5:
    this->position = position;
    return position;
  }
LABEL_11:
  if ( (int)position <= result )
    goto LABEL_5;
  this->position = *(_QWORD *)&result;
  return result;
}


// ========================================================================
// ?RenameFile@idFile_Nfs@@SA_NPBD0@Z
// EA  : 0x82F12870
// RVA : 0x00F12870
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idFile_Nfs::RenameFile(const char *path, const char *newPath)
{
  if ( path != nullptr )
    idLib::FatalError(fmt: "idFile_NFS::RenameFile: Not implemented for nfs filesystems (path: %s, %s)", path, newPath);
}


// ========================================================================
// ?NfsStatusToStr@Nfs4Const@@YAPBDI@Z
// EA  : 0x82F12898
// RVA : 0x00F12898
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

const char *__fastcall Nfs4Const::NfsStatusToStr(unsigned int val)
{
  const char *result; // r3

  if ( val > 0x3F )
  {
    if ( val > 0x2728 )
    {
      switch ( val )
      {
        case 0x2729u:
          result = "NFS4ERR_BAD_STATEID";
          break;
        case 0x272Au:
          result = "NFS4ERR_BAD_SEQID";
          break;
        case 0x272Bu:
          result = "NFS4ERR_NOT_SAME";
          break;
        case 0x272Cu:
          result = "NFS4ERR_LOCK_RANGE";
          break;
        case 0x272Du:
          result = "NFS4ERR_SYMLINK";
          break;
        case 0x272Eu:
          result = "NFS4ERR_RESTOREFH";
          break;
        case 0x272Fu:
          result = "NFS4ERR_LEASE_MOVED";
          break;
        case 0x2730u:
          result = "NFS4ERR_ATTRNOTSUPP";
          break;
        case 0x2731u:
          result = "NFS4ERR_NO_GRACE";
          break;
        case 0x2732u:
          result = "NFS4ERR_RECLAIM_BAD";
          break;
        case 0x2733u:
          result = "NFS4ERR_RECLAIM_CONFLICT";
          break;
        case 0x2734u:
          result = "NFS4ERR_BADXDR";
          break;
        case 0x2735u:
          result = "NFS4ERR_LOCKS_HELD";
          break;
        case 0x2736u:
          result = "NFS4ERR_OPENMODE";
          break;
        case 0x2737u:
          result = "NFS4ERR_BADOWNER";
          break;
        case 0x2738u:
          result = "NFS4ERR_BADCHAR";
          break;
        case 0x2739u:
          result = "NFS4ERR_BADNAME";
          break;
        case 0x273Au:
          result = "NFS4ERR_BAD_RANGE";
          break;
        case 0x273Bu:
          result = "NFS4ERR_LOCK_NOTSUPP";
          break;
        case 0x273Cu:
          result = "NFS4ERR_OP_ILLEGAL";
          break;
        case 0x273Du:
          result = "NFS4ERR_DEADLOCK";
          break;
        case 0x273Eu:
          result = "NFS4ERR_FILE_OPEN";
          break;
        case 0x273Fu:
          result = "NFS4ERR_ADMIN_REVOKED";
          break;
        case 0x2740u:
          result = "NFS4ERR_CB_PATH_DOWN";
          break;
        default:
          return "unknown";
      }
    }
    else if ( val == 10024 )
    {
      return "NFS4ERR_OLD_STATEID";
    }
    else if ( val > 0x271B )
    {
      switch ( val )
      {
        case 0x271Cu:
          result = "NFS4ERR_LOCKED";
          break;
        case 0x271Du:
          result = "NFS4ERR_GRACE";
          break;
        case 0x271Eu:
          result = "NFS4ERR_FHEXPIRED";
          break;
        case 0x271Fu:
          result = "NFS4ERR_SHARE_DENIED";
          break;
        case 0x2720u:
          result = "NFS4ERR_WRONGSEC";
          break;
        case 0x2721u:
          result = "NFS4ERR_CLID_INUSE";
          break;
        case 0x2722u:
          result = "NFS4ERR_RESOURCE";
          break;
        case 0x2723u:
          result = "NFS4ERR_MOVED";
          break;
        case 0x2724u:
          result = "NFS4ERR_NOFILEHANDLE";
          break;
        case 0x2725u:
          result = "NFS4ERR_MINOR_VERS_MISMATCH";
          break;
        case 0x2726u:
          result = "NFS4ERR_STALE_CLIENTID";
          break;
        case 0x2727u:
          result = "NFS4ERR_STALE_STATEID";
          break;
      }
    }
    else if ( val == 10011 )
    {
      return "NFS4ERR_EXPIRED";
    }
    else if ( val > 0x2715 )
    {
      switch ( val )
      {
        case 0x2717u:
          return "NFS4ERR_BADTYPE";
        case 0x2718u:
          return "NFS4ERR_DELAY";
        case 0x2719u:
          return "NFS4ERR_SAME";
        case 0x2716u:
          return "NFS4ERR_SERVERFAULT";
        default:
          return "NFS4ERR_DENIED";
      }
    }
    else if ( val == 10005 )
    {
      return "NFS4ERR_TOOSMALL";
    }
    else
    {
      if ( val > 0x2711 )
      {
        if ( val == 10003 )
          return "NFS4ERR_BAD_COOKIE";
        if ( val == 10004 )
          return "NFS4ERR_NOTSUPP";
      }
      else
      {
        switch ( val )
        {
          case 0x2711u:
            return "NFS4ERR_BADHANDLE";
          case 0x42u:
            return "NFS4ERR_NOTEMPTY";
          case 0x45u:
            return "NFS4ERR_DQUOT";
          case 0x46u:
            return "NFS4ERR_STALE";
          default:
            break;
        }
      }
      return "unknown";
    }
  }
  else if ( val == 63 )
  {
    return "NFS4ERR_NAMETOOLONG";
  }
  else
  {
    switch ( val )
    {
      case 0u:
        result = "NFS4_OK";
        break;
      case 1u:
        result = "NFS4ERR_PERM";
        break;
      case 2u:
        result = "NFS4ERR_NOENT";
        break;
      case 5u:
        result = "NFS4ERR_IO";
        break;
      case 6u:
        result = "NFS4ERR_NXIO";
        break;
      case 0xDu:
        result = "NFS4ERR_ACCESS";
        break;
      case 0x11u:
        result = "NFS4ERR_EXIST";
        break;
      case 0x12u:
        result = "NFS4ERR_XDEV";
        break;
      case 0x14u:
        result = "NFS4ERR_NOTDIR";
        break;
      case 0x15u:
        result = "NFS4ERR_ISDIR";
        break;
      case 0x16u:
        result = "NFS4ERR_INVAL";
        break;
      case 0x1Bu:
        result = "NFS4ERR_FBIG";
        break;
      case 0x1Cu:
        result = "NFS4ERR_NOSPC";
        break;
      case 0x1Eu:
        result = "NFS4ERR_ROFS";
        break;
      case 0x1Fu:
        result = "NFS4ERR_MLINK";
        break;
      default:
        return "unknown";
    }
  }
  return result;
}


// ========================================================================
// ?NfsOpToStr@Nfs4Const@@YAPBDI@Z
// EA  : 0x82F12DC0
// RVA : 0x00F12DC0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

const char *__fastcall Nfs4Const::NfsOpToStr(unsigned int val)
{
  const char *result; // r3

  if ( val > 0x273C )
    return "unknown";
  if ( val == 10044 )
    return "OP_ILLEGAL";
  switch ( val )
  {
    case 3u:
      result = "OP_ACCESS";
      break;
    case 4u:
      result = "OP_CLOSE";
      break;
    case 5u:
      result = "OP_COMMIT";
      break;
    case 6u:
      result = "OP_CREATE";
      break;
    case 7u:
      result = "OP_DELEGPURGE";
      break;
    case 8u:
      result = "OP_DELEGRETURN";
      break;
    case 9u:
      result = "OP_GETATTR";
      break;
    case 0xAu:
      result = "OP_GETFH";
      break;
    case 0xBu:
      result = "OP_LINK";
      break;
    case 0xCu:
      result = "OP_LOCK";
      break;
    case 0xDu:
      result = "OP_LOCKT";
      break;
    case 0xEu:
      result = "OP_LOCKU";
      break;
    case 0xFu:
      result = "OP_LOOKUP";
      break;
    case 0x10u:
      result = "OP_LOOKUPP";
      break;
    case 0x11u:
      result = "OP_NVERIFY";
      break;
    case 0x12u:
      result = "OP_OPEN";
      break;
    case 0x13u:
      result = "OP_OPENATTR";
      break;
    case 0x14u:
      result = "OP_OPEN_CONFIRM";
      break;
    case 0x15u:
      result = "OP_OPEN_DOWNGRADE";
      break;
    case 0x16u:
      result = "OP_PUTFH";
      break;
    case 0x17u:
      result = "OP_PUTPUBFH";
      break;
    case 0x18u:
      result = "OP_PUTROOTFH";
      break;
    case 0x19u:
      result = "OP_READ";
      break;
    case 0x1Au:
      result = "OP_READDIR";
      break;
    case 0x1Bu:
      result = "OP_READLINK";
      break;
    case 0x1Cu:
      result = "OP_REMOVE";
      break;
    case 0x1Du:
      result = "OP_RENAME";
      break;
    case 0x1Eu:
      result = "OP_RENEW";
      break;
    case 0x1Fu:
      result = "OP_RESTOREFH";
      break;
    case 0x20u:
      result = "OP_SAVEFH";
      break;
    case 0x21u:
      result = "OP_SECINFO";
      break;
    case 0x22u:
      result = "OP_SETATTR";
      break;
    case 0x23u:
      result = "OP_SETCLIENTID";
      break;
    case 0x24u:
      result = "OP_SETCLIENTID_CONFIRM";
      break;
    case 0x25u:
      result = "OP_VERIFY";
      break;
    case 0x26u:
      result = "OP_WRITE";
      break;
    case 0x27u:
      result = "OP_RELEASE_LOCKOWNER";
      break;
    default:
      return "unknown";
  }
  return result;
}


// ========================================================================
// ?NfsStatusToStr@Nfs3Const@@YAPBDH@Z
// EA  : 0x82F13058
// RVA : 0x00F13058
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

const char *__fastcall Nfs3Const::NfsStatusToStr(int err)
{
  const char *result; // r3

  if ( err > 63 )
  {
    if ( err > 10003 )
    {
      if ( (unsigned int)(err - 10004) <= 4 )
      {
        switch ( err )
        {
          case 10005:
            return "NFS3ERR_TOOSMALL";
          case 10006:
            return "NFS3ERR_SERVERFAULT";
          case 10007:
            return "NFS3ERR_BADTYPE";
          case 10004:
            return "NFS3ERR_NOTSUPP";
          default:
            break;
        }
        return "NFS3ERR_JUKEBOX";
      }
    }
    else
    {
      if ( err == 10003 )
        return "NFS3ERR_BAD_COOKIE";
      if ( err > 71 )
      {
        if ( err == 10001 )
          return "NFS3ERR_BADHANDLE";
        if ( err == 10002 )
          return "NFS3ERR_NOT_SYNC";
      }
      else
      {
        switch ( err )
        {
          case 'G':
            return "NFS3ERR_REMOTE";
          case 'B':
            return "NFS3ERR_NOTEMPTY";
          case 'E':
            return "NFS3ERR_DQUOT";
          case 'F':
            return "NFS3ERR_STALE";
          default:
            break;
        }
      }
    }
    return "Unknown";
  }
  if ( err == 63 )
    return "NFS3ERR_NAMETOOLONG";
  switch ( err )
  {
    case 0:
      result = "NFS3_OK";
      break;
    case 1:
      result = "NFS3ERR_PERM";
      break;
    case 2:
      result = "NFS3ERR_NOENT";
      break;
    case 5:
      result = "NFS3ERR_IO";
      break;
    case 6:
      result = "NFS3ERR_NXIO";
      break;
    case 13:
      result = "NFS3ERR_ACCES";
      break;
    case 17:
      result = "NFS3ERR_EXIST";
      break;
    case 18:
      result = "NFS3ERR_XDEV";
      break;
    case 19:
      result = "NFS3ERR_NODEV";
      break;
    case 20:
      result = "NFS3ERR_NOTDIR";
      break;
    case 21:
      result = "NFS3ERR_ISDIR";
      break;
    case 22:
      result = "NFS3ERR_INVAL";
      break;
    case 27:
      result = "NFS3ERR_FBIG";
      break;
    case 28:
      result = "NFS3ERR_NOSPC";
      break;
    case 30:
      result = "NFS3ERR_ROFS";
      break;
    case 31:
      result = "NFS3ERR_MLINK";
      break;
    default:
      return "Unknown";
  }
  return result;
}


// ========================================================================
// ?MntStatusToStr@Nfs3Const@@YAPBDH@Z
// EA  : 0x82F132D0
// RVA : 0x00F132D0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

const char *__fastcall Nfs3Const::MntStatusToStr(int err)
{
  const char *result; // r3

  if ( err > 20 )
  {
    if ( err > 10004 )
    {
      if ( err == 10006 )
        return "MNT3ERR_SERVERFAULT";
    }
    else
    {
      switch ( err )
      {
        case 10004:
          return "MNT3ERR_NOTSUPP";
        case 22:
          return "MNT3ERR_INVAL";
        case 63:
          return "MNT3ERR_NAMETOOLONG";
        default:
          break;
      }
    }
    return "Unknown";
  }
  if ( err == 20 )
    return "MNT3ERR_NOTDIR";
  switch ( err )
  {
    case 0:
      result = "MNT3_OK";
      break;
    case 1:
      result = "MNT3ERR_PERM";
      break;
    case 2:
      result = "MNT3ERR_NOENT";
      break;
    case 5:
      result = "MNT3ERR_IO";
      break;
    case 13:
      result = "MNT3ERR_ACCES";
      break;
    default:
      return "Unknown";
  }
  return result;
}


// ========================================================================
// ?RpcAcceptStatToStr@RpcConst@@YAPBDI@Z
// EA  : 0x82F133E0
// RVA : 0x00F133E0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

const char *__fastcall RpcConst::RpcAcceptStatToStr(unsigned int err)
{
  if ( err > 4 )
    return "Unknown";
  switch ( err )
  {
    case 1u:
      return "PROG_UNAVAIL";
    case 2u:
      return "PROG_MISMATCH";
    case 3u:
      return "PROC_UNAVAIL";
    default:
      break;
  }
  if ( err != 0 )
    return "GARBAGE_ARGS";
  return "SUCCESS";
}


// ========================================================================
// ?OpaqueWrite@RpcIOBuffer@idRpc@@QAAXPBXI@Z
// EA  : 0x82F13448
// RVA : 0x00F13448
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idRpc::RpcIOBuffer::OpaqueWrite(idRpc::RpcIOBuffer *this, const void *data, unsigned int len)
{
  unsigned int *cur; // r11
  int v6; // r11
  unsigned int v7; // ctr
  unsigned int v8; // r10

  *this->cur = len;
  cur = this->cur;
  this->cur = cur + 1;
  memcpy(Dst: cur + 1, Src: data, Size: len);
  v6 = 0;
  if ( (len & 3) != 0 )
  {
    v7 = len & 3;
    v8 = len;
    do
    {
      ++v6;
      *((_BYTE *)this->cur + v8) = 0;
      v8 = v6 + len;
      --v7;
    }
    while ( v7 != 0 );
  }
  this->cur = (unsigned int *)((char *)this->cur + ((len + 3) & 0xFFFFFFFC));
}


// ========================================================================
// ?ReadFromCon@RpcIOBuffer@idRpc@@QAA_NPAVConnection@2@I@Z
// EA  : 0x82F134D8
// RVA : 0x00F134D8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idRpc::RpcIOBuffer::ReadFromCon(idRpc::RpcIOBuffer *this, idRpc::Connection *con, unsigned int maxRead)
{
  unsigned int rest; // r31
  int Blocking; // r4
  char v7; // r11

  this->cur = (unsigned int *)this;
  this->end = (unsigned int *)&this->cur;
  rest = con->rest;
  if ( rest > 0x1000 )
    rest = 4096;
  if ( maxRead != 0 && rest >= maxRead )
    rest = maxRead;
  Blocking = idTCP::ReadBlocking(this: &con->sock, data: this, size: rest, timeoutMS: 5000);
  if ( Blocking == rest )
  {
    v7 = 1;
    con->rest -= rest;
  }
  else
  {
    idLib::Warning(fmt: "NFS: data read failed, %d of %d bytes received", Blocking, rest);
    idTCP::Close(this: &con->sock);
    v7 = 0;
  }
  if ( v7 == 0 )
    return 0;
  this->end = (unsigned int *)((char *)this->buffer + ((rest + 3) & 0xFFFFFFFC));
  return 1;
}


// ========================================================================
// ?ReadRestFromCon@RpcIOBuffer@idRpc@@QAA_NPAVConnection@2@@Z
// EA  : 0x82F135A8
// RVA : 0x00F135A8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idRpc::RpcIOBuffer::ReadRestFromCon(idRpc::RpcIOBuffer *this, idRpc::Connection *con)
{
  unsigned int rest; // r29
  unsigned int *end; // r11
  unsigned int *cur; // r4
  unsigned int v7; // r30

  rest = con->rest;
  if ( rest != 0 )
  {
    end = this->end;
    cur = this->cur;
    v7 = ((char *)end - (char *)cur) & 0xFFFFFFFC;
    if ( v7 != 0 )
      memmove(Dst: this, Src: cur, Size: ((char *)end - (char *)cur) & 0xFFFFFFFC);
    this->cur = (unsigned int *)this;
    if ( 4096 - v7 < rest )
      rest = 4096 - v7;
    if ( (unsigned __int8)idRpc::Connection::Recv(this: con, buf: (char *)this + (v7 & 0xFFFFFFFC), size: rest) == 0 )
      return 0;
    this->end = (unsigned int *)((char *)this->buffer + ((rest + v7 + 3) & 0xFFFFFFFC));
  }
  return 1;
}


// ========================================================================
// ?RecvHeader@Connection@idRpc@@QAA_NXZ
// EA  : 0x82F13648
// RVA : 0x00F13648
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idRpc::Connection::RecvHeader(idRpc::Connection *this)
{
  idTCP *p_sock; // r30
  int v3; // r4
  int v5; // [sp+50h] [-20h] BYREF

  p_sock = &this->sock;
  v3 = idTCP::ReadBlocking(this: &this->sock, data: &v5, size: 4, timeoutMS: 5000);
  if ( v3 == 4 )
  {
    if ( v5 < 0 )
    {
      this->rest = v5 & 0x7FFFFFFF;
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "NFS: Multi fragment rpc message not supported", 4);
      idTCP::Close(this: p_sock);
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "NFS: fragment header read failed, %d bytes received", v3);
    idTCP::Close(this: p_sock);
    return 0;
  }
}


// ========================================================================
// ?RPCRecv@idRpc@@QAA_NPAVRpcIOBuffer@1@I@Z
// EA  : 0x82F136F0
// RVA : 0x00F136F0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

BOOL __fastcall idRpc::RPCRecv(idRpc *this, idRpc::RpcIOBuffer *buf, unsigned int maxRead)
{
  return (unsigned __int8)idRpc::Connection::RecvHeader(this: &this->con) != 0
      && (unsigned __int8)idRpc::RpcIOBuffer::ReadFromCon(this: buf, con: &this->con, maxRead) != 0;
}


// ========================================================================
// ?RPCWriteRPCCallHeader@idRpc@@SAXPAVRpcIOBuffer@1@IIII@Z
// EA  : 0x82F13748
// RVA : 0x00F13748
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idRpc::RPCWriteRPCCallHeader(
        idRpc::RpcIOBuffer *buf,
        unsigned int rpcIdx,
        unsigned int prog,
        unsigned int version,
        unsigned int proc)
{
  unsigned int *v5; // r11
  unsigned int *v6; // r11
  unsigned int *v7; // r11
  unsigned int *v9; // r11
  unsigned int *v10; // r11
  unsigned int *v11; // r11
  unsigned int *v12; // r11
  unsigned int *v13; // r11
  unsigned int *v14; // r11
  unsigned int *v15; // r11
  unsigned int *v16; // r11
  unsigned int *v17; // r11
  unsigned int *v18; // r11

  buf->cur = (unsigned int *)buf;
  buf->end = (unsigned int *)&buf->cur;
  buf->buffer[0] = 0;
  v5 = buf->cur + 1;
  buf->cur = v5;
  *v5 = rpcIdx;
  v6 = buf->cur + 1;
  buf->cur = v6;
  *v6 = 0;
  v7 = buf->cur + 1;
  buf->cur = v7;
  *v7 = 2;
  v9 = buf->cur + 1;
  buf->cur = v9;
  *v9 = prog;
  v10 = buf->cur + 1;
  buf->cur = v10;
  *v10 = version;
  v11 = buf->cur + 1;
  buf->cur = v11;
  *v11 = proc;
  v12 = buf->cur + 1;
  buf->cur = v12;
  *v12 = 1;
  v13 = buf->cur + 1;
  buf->cur = v13;
  *v13 = 20;
  v14 = buf->cur + 1;
  buf->cur = v14;
  *v14 = 0;
  ++buf->cur;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: &byte_8200D768, len: 0);
  *buf->cur = 0;
  v15 = buf->cur + 1;
  buf->cur = v15;
  *v15 = 0;
  v16 = buf->cur + 1;
  buf->cur = v16;
  *v16 = 0;
  v17 = buf->cur + 1;
  buf->cur = v17;
  *v17 = 0;
  v18 = buf->cur + 1;
  buf->cur = v18;
  *v18 = 0;
  ++buf->cur;
}


// ========================================================================
// ?RPCReadRPCHeader@idRpc@@SA_NPAVRpcIOBuffer@1@AAI@Z
// EA  : 0x82F13888
// RVA : 0x00F13888
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idRpc::RPCReadRPCHeader(idRpc::RpcIOBuffer *buf, unsigned int *rpcIdx)
{
  unsigned int *cur; // r11
  unsigned int v3; // r9
  unsigned int *v4; // r10
  _DWORD *v5; // r11
  bool v6; // cr58
  int v7; // r10
  unsigned int *v8; // r11
  unsigned int *v9; // r11
  unsigned int v10; // r4
  bool v11; // cr58

  cur = buf->cur;
  v3 = *cur;
  buf->cur = cur + 1;
  *rpcIdx = v3;
  v4 = buf->cur;
  v5 = v4 + 1;
  v6 = *v4 == 1;
  buf->cur = v4 + 1;
  if ( v6 )
  {
    v7 = *v5;
    v8 = v5 + 1;
    buf->cur = v8;
    if ( v7 != 0 )
    {
      buf->cur = v8 + 1;
      idLib::Warning(fmt: "NFS: rpc msg reject: %d (%s)");
    }
    else
    {
      buf->cur = v8 + 1;
      v9 = &v8[((v8[1] + 3) >> 2) + 2];
      buf->cur = v9;
      v10 = *v9;
      v11 = *v9 == 0;
      buf->cur = v9 + 1;
      if ( v11 )
        return 1;
      RpcConst::RpcAcceptStatToStr(err: v10);
      idLib::Warning(fmt: "NFS: Rpc call error; %d, (%s)");
    }
  }
  else
  {
    idLib::Warning(fmt: "idNfs4Client::RPCReadRPCHeader: Rpc call error; %d, (%s)");
  }
  return 0;
}


// ========================================================================
// ?Read@NfsFh@idNfsClient@@QAAXPAVRpcIOBuffer@idRpc@@@Z
// EA  : 0x82F139D8
// RVA : 0x00F139D8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idNfsClient::NfsFh::Read(idNfsClient::NfsFh *this, idRpc::RpcIOBuffer *buf)
{
  unsigned int *cur; // r11
  size_t v5; // r30

  cur = buf->cur;
  v5 = *cur;
  buf->cur = cur + 1;
  if ( v5 > 0x80 )
    v5 = 128;
  memcpy(Dst: this->fhData, Src: cur + 1, Size: v5);
  buf->cur = (unsigned int *)((char *)buf->cur + ((v5 + 3) & 0xFFFFFFFC));
  this->fhSize = v5;
}


// ========================================================================
// ??0NfsLeaseControl@idNfs4Client@@QAA@XZ
// EA  : 0x82F13A40
// RVA : 0x00F13A40
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfs4Client::NfsLeaseControl *__fastcall idNfs4Client::NfsLeaseControl::NfsLeaseControl(
        idNfs4Client::NfsLeaseControl *this)
{
  idSysThread::idSysThread(this);
  this->client = nullptr;
  this->__vftable = (idNfs4Client::NfsLeaseControl_vtbl *)&idNfs4Client::NfsLeaseControl::`vftable';
  Sys_SignalCreate(handle: &this->terminateSignal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$117731
// EA  : 0x82F13AA0
// RVA : 0x00F13AA0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_117731()
{
  int v0; // r12

  idSysThread::~idSysThread(this: *(idSysThread **)(v0 - 112 + 132));
}


// ========================================================================
// ?RPCWriteCompHeader@idNfs4Client@@AAAXPAVRpcIOBuffer@idRpc@@IIPBD@Z
// EA  : 0x82F13C48
// RVA : 0x00F13C48
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idNfs4Client::RPCWriteCompHeader(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        unsigned int rpcIdx,
        unsigned int numOp,
        const char *tag)
{
  unsigned int v8; // r5
  unsigned int *v9; // r11

  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx, prog: 0x186A3u, version: 4u, proc: 1u);
  v8 = 0;
  if ( *tag != 0 )
  {
    do
      ++v8;
    while ( tag[v8] != 0 );
  }
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: tag, len: v8);
  *buf->cur = 0;
  v9 = buf->cur + 1;
  buf->cur = v9;
  *v9 = numOp;
  ++buf->cur;
}


// ========================================================================
// ?RPCCompSubHeaderRead@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@I@Z
// EA  : 0x82F13CD8
// RVA : 0x00F13CD8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::RPCCompSubHeaderRead(idNfs4Client *this, idRpc::RpcIOBuffer *buf, unsigned int op)
{
  unsigned int *cur; // r10
  unsigned int v5; // r7
  unsigned int v6; // r7
  const char *v7; // r3
  const char *v8; // r10
  int v9; // r7
  int v10; // r5
  unsigned int v12; // r31
  bool v13; // cr58
  char v14; // r11
  unsigned int v15; // r5
  const char *v16; // r3
  const char *v17; // r6
  int v18; // r5

  cur = buf->cur;
  v5 = *cur;
  buf->cur = cur + 1;
  if ( v5 != op )
  {
    Nfs4Const::NfsOpToStr(val: op);
    v7 = Nfs4Const::NfsOpToStr(val: v6);
    idLib::Warning(fmt: "NFS %s result Op mismatch: %d (%s) %d (%s)", v8, v10, v8, v9, v7);
    return 1;
  }
  v12 = cur[1];
  buf->cur = cur + 2;
  if ( v12 == 0 )
    return 0;
  if ( v12 > 0x11 )
  {
    if ( v12 == 30 )
    {
LABEL_12:
      v14 = 1;
      goto LABEL_13;
    }
    v13 = v12 == 10048;
  }
  else
  {
    if ( v12 == 17 || v12 <= 2 )
      goto LABEL_12;
    v13 = v12 == 13;
  }
  if ( v13 )
    goto LABEL_12;
  v14 = 0;
LABEL_13:
  if ( v14 == 0 )
  {
    Nfs4Const::NfsStatusToStr(val: v12);
    v16 = Nfs4Const::NfsOpToStr(val: v15);
    idLib::Warning(fmt: "NFS %s result error: %d (%s)", v16, v18, v17);
  }
  return idNfs4Client::DecodeNfs4Error(this, nfs4Err: v12);
}


// ========================================================================
// ?ProtocolHelperFattrMaskRead@idNfs4Client@@AAA_KPAVRpcIOBuffer@idRpc@@@Z
// EA  : 0x82F13DF0
// RVA : 0x00F13DF0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idNfs4Client::ProtocolHelperFattrMaskRead(idNfs4Client *this, idRpc::RpcIOBuffer *buf)
{
  unsigned int *cur; // r9
  _DWORD *v4; // r11
  unsigned int v5; // r4
  int result; // r3 OVERLAPPED

  cur = buf->cur;
  v4 = cur + 1;
  v5 = *cur;
  buf->cur = cur + 1;
  if ( v5 == 1 )
  {
    result = __ROL4__(*v4, 32);
    buf->cur = cur + 2;
  }
  else if ( v5 == 2 )
  {
    *(_QWORD *)&result = *(_QWORD *)v4;
    buf->cur = cur + 3;
  }
  else
  {
    idLib::Warning(fmt: "NFS: Unsupported attrib mask size %d from server", v5);
    return 0;
  }
  return result;
}


// ========================================================================
// ?SubOpLookUpChainWrite@idNfs4Client@@AAAHPAVRpcIOBuffer@idRpc@@PBDPAPBD@Z
// EA  : 0x82F13E80
// RVA : 0x00F13E80
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::SubOpLookUpChainWrite(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        const char *path,
        const char **last)
{
  int v7; // r29
  char *v8; // r28
  unsigned int v10; // r5

  v7 = 0;
  while ( 1 )
  {
    v8 = strchr(Str: path, Val: 47);
    if ( v8 == nullptr )
    {
      v8 = strchr(Str: path, Val: 92);
      if ( v8 == nullptr )
        break;
    }
    if ( v8 != path )
    {
      ++v7;
      *buf->cur++ = 15;
      idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: path, len: v8 - path);
    }
    path = v8 + 1;
  }
  if ( *path != 0 )
  {
    if ( last != nullptr )
    {
      *last = path;
      return v7;
    }
    ++v7;
    v10 = 0;
    *buf->cur++ = 15;
    if ( *path != 0 )
    {
      do
        ++v10;
      while ( path[v10] != 0 );
    }
    idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: path, len: v10);
  }
  return v7;
}


// ========================================================================
// ?SubOpGetFileAttrRead@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFileAttr@3@@Z
// EA  : 0x82F13F78
// RVA : 0x00F13F78
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::SubOpGetFileAttrRead(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFileAttr *attr)
{
  idNfsClient::NfsErr result; // r3
  int v7; // r3
  unsigned int *cur; // r10
  __int64 v9; // r9
  unsigned int *v10; // r11
  __int64 v11; // r8
  __int64 v12; // r6
  unsigned __int64 v13; // r10
  unsigned int *v14; // r11
  unsigned __int64 v15; // r7
  unsigned int *v16; // r11
  unsigned int v17; // r5

  result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 9u);
  if ( result == NFS_OK )
  {
    v7 = idNfs4Client::ProtocolHelperFattrMaskRead(this, buf);
    cur = buf->cur;
    LODWORD(v9) = 32769;
    v10 = cur + 1;
    v11 = v9 << 21;
    HIDWORD(v12) = *cur;
    buf->cur = cur + 1;
    if ( __PAIR64__(v7, HIDWORD(v12)) == __PAIR64__(v11, 20) )
    {
      v13 = *(_QWORD *)v10;
      HIDWORD(v13) = v10 + 2;
      buf->cur = v10 + 2;
      attr->size = v13;
      v14 = buf->cur;
      v15 = *(_QWORD *)v14;
      buf->cur = v14 + 2;
      attr->mTimeSec = v15;
      v16 = buf->cur;
      v17 = *v16;
      buf->cur = v16 + 1;
      attr->mTimeNano = v17;
      return NFS_OK;
    }
    else
    {
      idLib::Warning(
        fmt: "NFS SubOpGetFileAttrRead getattr attrib or attrib size missmatch: attr: %llu, size: %u",
        v12,
        HIDWORD(v11));
      return NFS_ERR_OTHER;
    }
  }
  return result;
}


// ========================================================================
// ?Dissconnect@idNfs4Client@@UAAXXZ
// EA  : 0x82F14040
// RVA : 0x00F14040
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idNfs4Client::Dissconnect(idNfs4Client *this)
{
  idSysMutex *p_mutex; // r29

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( this->connected )
  {
    Sys_SignalRaise(handle: &this->leaseControlThread.terminateSignal.handle);
    idSysThread::StopThread(this: &this->leaseControlThread, wait: true);
    idTCP::Close(this: &this->rpcCon.con.sock);
    this->connected = false;
  }
  Sys_MutexUnlock(handle: &p_mutex->handle);
}


// ========================================================================
// __unwind$118366
// EA  : 0x82F140A8
// RVA : 0x00F140A8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_118366()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?Read@Nfs3Fh@idNfs3Client@@QAAXPAVRpcIOBuffer@idRpc@@@Z
// EA  : 0x82F140D0
// RVA : 0x00F140D0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idNfs3Client::Nfs3Fh::Read(idNfs3Client::Nfs3Fh *this, idRpc::RpcIOBuffer *buf)
{
  unsigned int *cur; // r11
  size_t v5; // r30

  cur = buf->cur;
  v5 = *cur;
  buf->cur = cur + 1;
  if ( v5 > 0x40 )
    v5 = 64;
  memcpy(Dst: this->fhData, Src: cur + 1, Size: v5);
  buf->cur = (unsigned int *)((char *)buf->cur + ((v5 + 3) & 0xFFFFFFFC));
  this->fhSize = v5;
}


// ========================================================================
// ?FindMount@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PBDPAPAVNfs3Fh@1@PAPBD@Z
// EA  : 0x82F14130
// RVA : 0x00F14130
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::FindMount(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        const char *path,
        idNfs3Client::Nfs3Fh **resFh,
        const char **resPath)
{
  int status; // r26
  int v10; // r27
  int i; // r29
  idNfs3Client::Nfs3Mount *v12; // r31

  status = 2;
  v10 = 0;
  if ( this->mounts.num <= 0 )
    return status;
  for ( i = 0; ; ++i )
  {
    v12 = &this->mounts.list[i];
    if ( idStr::IcmpnPath(s1: v12->path.data, s2: path, n: v12->path.len) == 0 )
      break;
LABEL_6:
    if ( ++v10 >= this->mounts.num )
      return status;
  }
  if ( v12->status != NFS_OK )
  {
    status = v12->status;
    goto LABEL_6;
  }
  *resFh = &v12->fh;
  *resPath = &path[v12->path.len];
  return 0;
}


// ========================================================================
// ??0idFile_Nfs@@QAA@XZ
// EA  : 0x82F141E8
// RVA : 0x00F141E8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idFile_Nfs *__fastcall idFile_Nfs::idFile_Nfs(idFile_Nfs *this)
{
  unsigned __int64 v1; // r29

  LODWORD(v1) = 0;
  idFile::idFile(this);
  this->__vftable = (idFile_Nfs_vtbl *)&idFile_Nfs::`vftable';
  this->fullPath.len = 0;
  this->fullPath.data = this->fullPath.baseBuffer;
  this->fullPath.allocedAndFlag = 20;
  this->fullPath.baseBuffer[0] = 0;
  this->openRemote = false;
  idStr::operator=(this: &this->fullPath, text: "invalid");
  this->position = v1;
  this->mode = FS_READ;
  this->demandSeek = false;
  this->nfsClient = nullptr;
  this->ro = false;
  return this;
}


// ========================================================================
// __unwind$118695
// EA  : 0x82F14264
// RVA : 0x00F14264
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_118695()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$118696
// EA  : 0x82F1428C
// RVA : 0x00F1428C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_118696()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// ??1idFile_Nfs@@UAA@XZ
// EA  : 0x82F142C8
// RVA : 0x00F142C8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idFile_Nfs::~idFile_Nfs(idFile_Nfs *this)
{
  idNfsClient *nfsClient; // r3

  this->__vftable = (idFile_Nfs_vtbl *)&idFile_Nfs::`vftable';
  if ( this->openRemote )
  {
    nfsClient = this->nfsClient;
    if ( nfsClient != nullptr )
      nfsClient->Close(this: nfsClient, a2: (idNfsClient::NfsFh *)&this->fh);
  }
  idStr::FreeData(this: &this->fullPath);
  this->__vftable = (idFile_Nfs_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$118756
// EA  : 0x82F1434C
// RVA : 0x00F1434C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_118756()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$118757
// EA  : 0x82F14374
// RVA : 0x00F14374
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_118757()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// ?ForceFlush@idFile_Nfs@@UAAXXZ
// EA  : 0x82F143A0
// RVA : 0x00F143A0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idFile_Nfs::ForceFlush(idFile_Nfs *this)
{
  idLib::FatalError(fmt: "idFile_NFS::ForceFlush: cannot flush nfs file %s", this->fullPath.data);
}


// ========================================================================
// ?StrRead@RpcIOBuffer@idRpc@@QAA?AVidStr@@XZ
// EA  : 0x82F14498
// RVA : 0x00F14498
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idRpc::RpcIOBuffer *__fastcall idRpc::RpcIOBuffer::StrRead(idRpc::RpcIOBuffer *this, idStr *result)
{
  int len; // r11
  int v4; // r30

  len = result[128].len;
  v4 = *(_DWORD *)len;
  result[128].len = len + 4;
  this->buffer[2] = 20;
  this->buffer[1] = (unsigned int)&this->buffer[3];
  this->buffer[0] = 0;
  HIBYTE(this->buffer[3]) = 0;
  idStr::CopyRange((idStr *)this, text: (const char *)(len + 4), start: 0, end: v4);
  result[128].len += (v4 + 3) & 0xFFFFFFFC;
  return this;
}


// ========================================================================
// ?RPCSend@idRpc@@QAA_NPAVRpcIOBuffer@1@@Z
// EA  : 0x82F14508
// RVA : 0x00F14508
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

BOOL __fastcall idRpc::RPCSend(idRpc *this, idRpc::RpcIOBuffer *buf)
{
  idTCP *p_sock; // r31
  unsigned int v3; // r30
  char v4; // r11

  p_sock = &this->con.sock;
  v3 = ((char *)buf->cur - (char *)buf) & 0xFFFFFFFC;
  buf->buffer[0] = (v3 - 4) | 0x80000000;
  if ( idTCP::WriteBlocking(this: &this->con.sock, data: buf, size: v3, timeoutMS: 5000) == v3 )
  {
    v4 = 1;
  }
  else
  {
    idTCP::Close(this: p_sock);
    v4 = 0;
  }
  return v4 != 0;
}


// ========================================================================
// ??1idNfs4Client@@UAA@XZ
// EA  : 0x82F14600
// RVA : 0x00F14600
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idNfs4Client::~idNfs4Client(idNfs4Client *this)
{
  this->__vftable = (idNfs4Client_vtbl *)&idNfs4Client::`vftable';
  if ( this->connected )
    idNfs4Client::Dissconnect(this);
  idRpc::Connection::~Connection(this: &this->rpcCon.con);
  Sys_MutexDestroy(handle: &this->mutex.handle);
  idNfs4Client::NfsLeaseControl::~NfsLeaseControl(this: &this->leaseControlThread);
}


// ========================================================================
// __unwind$119285
// EA  : 0x82F1466C
// RVA : 0x00F1466C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_119285()
{
  int v0; // r12

  idNfs4Client::NfsLeaseControl::~NfsLeaseControl(this: (idNfs4Client::NfsLeaseControl *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$119286
// EA  : 0x82F14698
// RVA : 0x00F14698
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_119286()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$119287
// EA  : 0x82F146C4
// RVA : 0x00F146C4
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_119287()
{
  int v0; // r12

  idRpc::~idRpc(this: (idRpc *)(*(_DWORD *)(v0 - 112 + 132) + 76));
}


// ========================================================================
// ?RPCSendRecv@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PBDIAAI2@Z
// EA  : 0x82F146F0
// RVA : 0x00F146F0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::RPCSendRecv(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        const char *opName,
        unsigned int idx,
        unsigned int *numOps,
        unsigned int *replyCompStatus)
{
  idRpc *p_rpcCon; // r30
  char v13; // r11
  unsigned int *cur; // r11
  unsigned int v16; // r5
  bool v17; // cr58
  char v18; // r11
  const char *v19; // r3
  int v20; // r5
  unsigned int *v21; // r11
  unsigned int v22; // r7
  unsigned int v23; // [sp+50h] [-50h] BYREF

  p_rpcCon = &this->rpcCon;
  if ( !idRpc::RPCSend(this: &this->rpcCon, buf) )
    return 1;
  v13 = idRpc::Connection::RecvHeader(this: &p_rpcCon->con);
  if ( v13 != 0 )
    v13 = (unsigned __int8)idRpc::RpcIOBuffer::ReadFromCon(this: buf, con: &p_rpcCon->con, maxRead: 0) != 0;
  if ( v13 == 0 || (unsigned __int8)idRpc::RPCReadRPCHeader(buf, rpcIdx: &v23) == 0 )
    return 1;
  if ( v23 != idx )
  {
    idLib::Warning(fmt: "NFS %s incorrect seq id %d, %d", opName, idx, v23);
    return 1;
  }
  cur = buf->cur;
  v16 = *cur;
  buf->cur = cur + 1;
  *replyCompStatus = v16;
  if ( v16 != 0 )
  {
    if ( v16 > 0x11 )
    {
      if ( v16 == 30 )
        goto LABEL_18;
      v17 = v16 == 10048;
    }
    else
    {
      if ( v16 == 17 || v16 <= 2 )
        goto LABEL_18;
      v17 = v16 == 13;
    }
    if ( !v17 )
    {
      v18 = 0;
      goto LABEL_19;
    }
LABEL_18:
    v18 = 1;
LABEL_19:
    if ( v18 == 0 )
    {
      v19 = Nfs4Const::NfsStatusToStr(val: v16);
      idLib::Warning(fmt: "idNfs4Client::RPCSendRecv: %s compound header status: %d (%s)", opName, v20, v19);
    }
  }
  v21 = &buf->cur[((*buf->cur + 3) >> 2) + 1];
  buf->cur = v21;
  v22 = *v21;
  buf->cur = v21 + 1;
  *numOps = v22;
  return idNfs4Client::DecodeNfs4Error(this, nfs4Err: *replyCompStatus);
}


// ========================================================================
// ?OpOpen@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsClientId@1@PAVNfsFh@3@PBV73@PBDW4fsMode_t@@_N6PAVNfsFileAttr@3@@Z
// EA  : 0x82F14878
// RVA : 0x00F14878
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpOpen(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs4Client::NfsClientId *clientId,
        idNfsClient::NfsFh *dst,
        const idNfsClient::NfsFh *src,
        const char *path,
        fsMode_t mode,
        bool create,
        bool trunc,
        idNfsClient::NfsFileAttr *attrAtOpen,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned __int8 a28,
        int a29,
        idNfsClient::NfsFileAttr *a30)
{
  unsigned int v31; // r21
  __int64 v38; // r26
  unsigned int v39; // r5
  const char *v40; // r11
  unsigned int *v41; // r11
  unsigned int *v42; // r11
  int v43; // r24
  int v44; // r10
  int v45; // r9
  unsigned int v46; // r8
  unsigned int *v47; // r11
  unsigned int *v48; // r11
  unsigned int *v49; // r11
  unsigned int *v50; // r11
  unsigned int nextOwner; // r11
  unsigned int *v52; // r11
  unsigned int *v53; // r11
  unsigned int *v54; // r11
  __int64 v55; // r10
  unsigned int *v56; // r11
  unsigned int *v57; // r11
  unsigned int v58; // r5
  const char *v59; // r4
  unsigned int *v60; // r11
  unsigned __int64 v61; // r7
  unsigned int *v62; // r11
  unsigned int *v63; // r11
  unsigned int *v64; // r11
  idNfsClient::NfsErr result; // r3
  unsigned int *cur; // r11
  unsigned int v67; // r9
  unsigned int *v68; // r11
  unsigned int v69; // r7
  unsigned int *v70; // r11
  unsigned int v71; // r5
  unsigned int *v72; // r11
  unsigned int v73; // r3
  unsigned int *v74; // r11
  unsigned int *v75; // r10
  int v76; // r26
  unsigned int *v77; // r11
  unsigned int v78; // r4
  bool v79; // cr58
  unsigned int *v80; // r11
  size_t v81; // r29
  unsigned int v82; // r29
  unsigned int *v83; // r9
  unsigned int *v84; // r11
  unsigned int *v85; // r11
  unsigned int *v86; // r11
  unsigned int *v87; // r11
  unsigned int *v88; // r11
  unsigned int v89; // r9
  unsigned int *v90; // r11
  unsigned int v91; // r7
  unsigned int *v92; // r11
  unsigned int v93; // r5
  unsigned int *v94; // r11
  unsigned int v95; // r3
  const char *v96; // [sp+50h] [-70h] BYREF
  unsigned int v97[27]; // [sp+54h] [-6Ch] BYREF

  v31 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v31;
  HIDWORD(v38) = mode;
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v31, prog: 0x186A3u, version: 4u, proc: 1u);
  LODWORD(v38) = 0;
  v39 = 0;
  v40 = "<open>";
  do
  {
    ++v40;
    ++v39;
  }
  while ( *v40 != 0 );
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: "<open>", len: v39);
  *buf->cur = 0;
  v41 = buf->cur + 1;
  buf->cur = v41;
  *v41 = 0;
  v42 = buf->cur + 1;
  buf->cur = v42;
  *v42 = 22;
  ++buf->cur;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: src->fhData, len: src->fhSize);
  v43 = idNfs4Client::SubOpLookUpChainWrite(this, buf, path, last: &v96);
  v44 = 0;
  v45 = 0;
  if ( HIDWORD(v38) <= 4 )
  {
    switch ( HIDWORD(v38) )
    {
      case 1:
        v45 = 3;
LABEL_11:
        v44 = 2;
        break;
      case 2:
        v44 = 3;
        break;
      case 3:
      case 0:
        v44 = 1;
        break;
      default:
        goto LABEL_11;
    }
  }
  v46 = 4;
  *buf->cur++ = 18;
  dst->seqId = 0;
  *buf->cur = 0;
  v47 = buf->cur + 1;
  buf->cur = v47;
  *v47 = v44;
  v48 = buf->cur + 1;
  buf->cur = v48;
  *v48 = v45;
  v49 = buf->cur + 1;
  buf->cur = v49;
  *(_QWORD *)v49 = clientId->clientId;
  v50 = buf->cur + 2;
  buf->cur = v50;
  *v50 = 4;
  ++buf->cur;
  nextOwner = clientId->nextOwner;
  clientId->nextOwner = nextOwner + 1;
  *buf->cur = nextOwner;
  v52 = buf->cur + 1;
  buf->cur = v52;
  if ( create )
  {
    *v52 = 1;
    LODWORD(v55) = 2;
    v53 = buf->cur + 1;
    buf->cur = v53;
    *v53 = 0;
    v54 = buf->cur + 1;
    HIDWORD(v55) = a28;
    buf->cur = v54;
    if ( a28 != 0 )
    {
      v46 = 12;
      LODWORD(v55) = 18;
    }
    *v54 = 2;
    v56 = buf->cur + 1;
    buf->cur = v56;
    *(_QWORD *)v56 = v55;
    buf->cur += 2;
    *buf->cur = v46;
    v57 = buf->cur + 1;
    buf->cur = v57;
    if ( a28 != 0 )
    {
      *(_QWORD *)v57 = v38;
      buf->cur += 2;
    }
    *buf->cur = 438;
  }
  else
  {
    *v52 = 0;
  }
  v58 = 0;
  v59 = v96;
  v60 = buf->cur + 1;
  buf->cur = v60;
  *v60 = 0;
  ++buf->cur;
  if ( *v59 != 0 )
  {
    do
      ++v58;
    while ( v59[v58] != 0 );
  }
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: v59, len: v58);
  LODWORD(v61) = 32769;
  *buf->cur = 10;
  v62 = buf->cur + 1;
  buf->cur = v62;
  *v62 = 9;
  v63 = buf->cur + 1;
  buf->cur = v63;
  *v63 = 2;
  v64 = buf->cur + 1;
  buf->cur = v64;
  *(_QWORD *)v64 = v61 << 21;
  buf->cur += 2;
  *(_DWORD *)(v61 >> 11) = v43 + 4;
  if ( idNfs4Client::RPCSendRecv(
         this,
         buf,
         opName: "OpOpen",
         idx: v31,
         numOps: v97,
         replyCompStatus: (unsigned int *)&v96) == 1 )
    return NFS_ERR_CON;
  result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
  if ( result == NFS_OK )
  {
    if ( v43 > 0 )
    {
      do
      {
        result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0xFu);
        if ( result != NFS_OK )
          return result;
        LODWORD(v38) = v38 + 1;
      }
      while ( (int)v38 < v43 );
    }
    ++dst->seqId;
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x12u);
    if ( result != NFS_OK )
      return result;
    cur = buf->cur;
    v67 = *cur;
    buf->cur = cur + 1;
    dst->stateId.data[0] = v67;
    v68 = buf->cur;
    v69 = *v68;
    buf->cur = v68 + 1;
    dst->stateId.data[1] = v69;
    v70 = buf->cur;
    v71 = *v70;
    buf->cur = v70 + 1;
    dst->stateId.data[2] = v71;
    v72 = buf->cur;
    v73 = *v72;
    buf->cur = v72 + 1;
    dst->stateId.data[3] = v73;
    v74 = buf->cur + 5;
    v75 = buf->cur + 6;
    buf->cur = v74;
    v76 = *v74 & 2;
    buf->cur = v75;
    v77 = &v75[v74[1] + 1];
    buf->cur = v77;
    v78 = *v77;
    v79 = *v77 == 0;
    buf->cur = v77 + 1;
    if ( !v79 )
    {
      idLib::Warning(fmt: "NFS OPOpen returned delegation (%d), not implemented", v78);
      return NFS_ERR_OTHER;
    }
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0xAu);
    if ( result == NFS_OK )
    {
      v80 = buf->cur;
      v81 = *v80;
      buf->cur = v80 + 1;
      if ( v81 > 0x80 )
        v81 = 128;
      memcpy(Dst: dst->fhData, Src: v80 + 1, Size: v81);
      buf->cur = (unsigned int *)((char *)buf->cur + ((v81 + 3) & 0xFFFFFFFC));
      dst->fhSize = v81;
      result = idNfs4Client::SubOpGetFileAttrRead(this, buf, attr: a30);
      if ( result == NFS_OK )
      {
        if ( v76 == 0 )
          return NFS_OK;
        v82 = this->nextRpcIdx + 1;
        this->nextRpcIdx = v82;
        idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v82, numOp: 2u, tag: "<path open confirm>");
        *buf->cur++ = 22;
        idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: dst->fhData, len: dst->fhSize);
        *buf->cur = 20;
        v83 = buf->cur + 1;
        buf->cur = v83;
        *v83 = dst->stateId.data[0];
        v84 = buf->cur + 1;
        buf->cur = v84;
        *v84 = dst->stateId.data[1];
        v85 = buf->cur + 1;
        buf->cur = v85;
        *v85 = dst->stateId.data[2];
        v86 = buf->cur + 1;
        buf->cur = v86;
        *v86 = dst->stateId.data[3];
        v87 = buf->cur + 1;
        buf->cur = v87;
        *v87 = dst->seqId;
        ++buf->cur;
        if ( idNfs4Client::RPCSendRecv(
               this,
               buf,
               opName: "OpOpen",
               idx: v82,
               numOps: (unsigned int *)&v96,
               replyCompStatus: v97) == 1 )
          return NFS_ERR_CON;
        result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
        if ( result == NFS_OK )
        {
          ++dst->seqId;
          result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x14u);
          if ( result == NFS_OK )
          {
            v88 = buf->cur;
            v89 = *v88;
            buf->cur = v88 + 1;
            dst->stateId.data[0] = v89;
            v90 = buf->cur;
            v91 = *v90;
            buf->cur = v90 + 1;
            dst->stateId.data[1] = v91;
            v92 = buf->cur;
            v93 = *v92;
            buf->cur = v92 + 1;
            dst->stateId.data[2] = v93;
            v94 = buf->cur;
            v95 = *v94;
            buf->cur = v94 + 1;
            dst->stateId.data[3] = v95;
            return NFS_OK;
          }
        }
      }
    }
  }
  return result;
}


// ========================================================================
// ?OpClose@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsClientId@1@PAVNfsFh@3@@Z
// EA  : 0x82F14F18
// RVA : 0x00F14F18
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpClose(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs4Client::NfsClientId *clientId,
        idNfsClient::NfsFh *fh)
{
  unsigned int v5; // r28
  unsigned int *v8; // r11
  unsigned int *v9; // r11
  unsigned int *v10; // r11
  unsigned int *v11; // r11
  unsigned int *v12; // r11
  idNfsClient::NfsErr result; // r3
  unsigned int *cur; // r11
  unsigned int v15; // r9
  unsigned int *v16; // r11
  unsigned int v17; // r7
  unsigned int *v18; // r11
  unsigned int v19; // r5
  unsigned int *v20; // r11
  unsigned int *v21; // r4
  unsigned int v22; // r11
  unsigned int v23; // [sp+50h] [-30h] BYREF
  unsigned int v24; // [sp+54h] [-2Ch] BYREF

  v5 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v5;
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v5, numOp: 2u, tag: "<close>");
  *buf->cur++ = 22;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fh->fhData, len: fh->fhSize);
  *buf->cur = 4;
  v8 = buf->cur + 1;
  buf->cur = v8;
  *v8 = fh->seqId;
  v9 = buf->cur + 1;
  buf->cur = v9;
  *v9 = fh->stateId.data[0];
  v10 = buf->cur + 1;
  buf->cur = v10;
  *v10 = fh->stateId.data[1];
  v11 = buf->cur + 1;
  buf->cur = v11;
  *v11 = fh->stateId.data[2];
  v12 = buf->cur + 1;
  buf->cur = v12;
  *v12 = fh->stateId.data[3];
  ++buf->cur;
  result = idNfs4Client::RPCSendRecv(this, buf, opName: "OpClose", idx: v5, numOps: &v24, replyCompStatus: &v23);
  if ( result != NFS_ERR_CON )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
    if ( result == NFS_OK )
    {
      ++fh->seqId;
      result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 4u);
      if ( result == NFS_OK )
      {
        cur = buf->cur;
        v15 = *cur;
        buf->cur = cur + 1;
        fh->stateId.data[0] = v15;
        v16 = buf->cur;
        v17 = *v16;
        buf->cur = v16 + 1;
        fh->stateId.data[1] = v17;
        v18 = buf->cur;
        v19 = *v18;
        buf->cur = v18 + 1;
        fh->stateId.data[2] = v19;
        v20 = buf->cur;
        v21 = v20 + 1;
        v22 = *v20;
        buf->cur = v21;
        fh->stateId.data[3] = v22;
      }
    }
  }
  return result;
}


// ========================================================================
// ?OpRead@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@_KIPAXAA_NAAI@Z
// EA  : 0x82F150C0
// RVA : 0x00F150C0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpRead(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *fh,
        int a4,
        unsigned __int64 offset,
        bool *count,
        size_t *buffer,
        bool *eof,
        unsigned int *resCount)
{
  __int64 v9; // r21
  unsigned int v12; // r26
  unsigned int v13; // r28
  char *v16; // r22
  unsigned int *v18; // r10
  unsigned int *v19; // r11
  unsigned int *v20; // r11
  unsigned int *v21; // r11
  unsigned int *v22; // r11
  unsigned int *v23; // r11
  unsigned int *v24; // r11
  unsigned int v25; // r30
  char v26; // r11
  char v27; // r11
  unsigned int *cur; // r11
  _DWORD *v29; // r10
  unsigned int v30; // r30
  bool v31; // cr58
  char v32; // r11
  const char *v33; // r3
  idNfsClient::NfsErr result; // r3
  unsigned int v35; // r6
  bool v36; // cr58
  unsigned int *v37; // r11
  unsigned int v38; // r9
  unsigned int *v39; // r10
  size_t v40; // r30
  int v41; // r5
  unsigned int v42; // r28
  int rest; // r27
  unsigned int v44; // r4
  size_t v45; // r5
  int v46; // r4
  unsigned int v47; // [sp+50h] [-70h] BYREF

  LODWORD(v9) = a4;
  *buffer = 0;
  v12 = HIDWORD(offset);
  v13 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v13;
  v16 = (char *)offset;
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v13, numOp: 2u, tag: "<read>");
  *buf->cur++ = 22;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fh->fhData, len: fh->fhSize);
  *buf->cur = 25;
  v18 = buf->cur + 1;
  buf->cur = v18;
  *v18 = fh->stateId.data[0];
  v19 = buf->cur + 1;
  buf->cur = v19;
  *v19 = fh->stateId.data[1];
  v20 = buf->cur + 1;
  buf->cur = v20;
  *v20 = fh->stateId.data[2];
  v21 = buf->cur + 1;
  buf->cur = v21;
  *v21 = fh->stateId.data[3];
  v22 = buf->cur + 1;
  buf->cur = v22;
  *(_QWORD *)v22 = v9;
  v23 = buf->cur + 2;
  buf->cur = v23;
  *v23 = v12;
  v24 = buf->cur + 1;
  buf->cur = v24;
  v25 = ((char *)v24 - (char *)buf) & 0xFFFFFFFC;
  buf->buffer[0] = (v25 - 4) | 0x80000000;
  if ( idTCP::WriteBlocking(this: &this->rpcCon.con.sock, data: buf, size: v25, timeoutMS: 5000) == v25 )
  {
    v26 = 1;
  }
  else
  {
    idTCP::Close(this: &this->rpcCon.con.sock);
    v26 = 0;
  }
  if ( v26 == 0 )
    return NFS_ERR_CON;
  v27 = idRpc::Connection::RecvHeader(this: &this->rpcCon.con);
  if ( v27 != 0 )
    v27 = (unsigned __int8)idRpc::RpcIOBuffer::ReadFromCon(this: buf, con: &this->rpcCon.con, maxRead: 0x80u) != 0;
  if ( v27 == 0 || (unsigned __int8)idRpc::RPCReadRPCHeader(buf, rpcIdx: &v47) == 0 )
    return NFS_ERR_CON;
  cur = buf->cur;
  v29 = cur + 1;
  v30 = *cur;
  buf->cur = cur + 1;
  if ( v30 != 0 )
  {
    if ( v30 > 0x11 )
    {
      if ( v30 == 30 )
        goto LABEL_18;
      v31 = v30 == 10048;
    }
    else
    {
      if ( v30 == 17 || v30 <= 2 )
        goto LABEL_18;
      v31 = v30 == 13;
    }
    if ( !v31 )
    {
      v32 = 0;
      goto LABEL_19;
    }
LABEL_18:
    v32 = 1;
LABEL_19:
    if ( v32 == 0 )
    {
      v33 = Nfs4Const::NfsStatusToStr(val: v30);
      idLib::Warning(fmt: "idNfs4Client::OpRead: compound header status: %d (%s)", v30, v33);
      return idNfs4Client::DecodeNfs4Error(this, nfs4Err: v30);
    }
  }
  v35 = v47;
  v36 = v47 == v13;
  buf->cur = &v29[((unsigned int)(*v29 + 3) >> 2) + 2];
  if ( !v36 )
  {
    idLib::Warning(fmt: "NFS %s incorrect seq id %d, %d", "OpRead", v13, v35);
    return NFS_ERR_CON;
  }
  result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
  if ( result == NFS_OK )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x19u);
    if ( result == NFS_OK )
    {
      v37 = buf->cur;
      v38 = *v37;
      buf->cur = v37 + 1;
      *count = v38 != 0;
      v39 = buf->cur;
      v40 = *v39;
      v41 = (char *)buf->end - (char *)(v39 + 1);
      buf->cur = v39 + 1;
      v42 = v41 & 0xFFFFFFFC;
      rest = this->rpcCon.con.rest;
      v44 = (v41 & 0xFFFFFFFC) + rest;
      if ( v44 != ((v40 + 3) & 0xFFFFFFFC) || v40 > v12 )
        idLib::Warning(
          fmt: "NFS OPRead result count error, in fragment: %d, reported: %d, requested: %d",
          v44,
          v40,
          v12);
      if ( v42 != 0 )
      {
        v45 = v42;
        if ( v42 >= v40 )
          v45 = v40;
        memcpy(Dst: v16, Src: buf->cur, Size: v45);
      }
      if ( rest != 0
        && (unsigned __int8)idRpc::Connection::Recv(this: &this->rpcCon.con, buf: &v16[v42], size: v40 - v42) == 0 )
      {
        return NFS_ERR_CON;
      }
      v46 = this->rpcCon.con.rest;
      if ( v46 != 0 )
      {
        if ( v46 != 4 - (v40 & 3) )
          idLib::FatalError(
            fmt: "NFS OPRead incomplete fragment read; rest: %d, replySize: %d (conrest: %d, bufres: %d)",
            v46,
            v40,
            rest,
            v42);
        idRpc::RpcIOBuffer::ReadFromCon(this: buf, con: &this->rpcCon.con, maxRead: 0);
      }
      *buffer = v40;
      return NFS_OK;
    }
  }
  return result;
}


// ========================================================================
// ?OpWrite@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@_KIPBXAAI@Z
// EA  : 0x82F154A0
// RVA : 0x00F154A0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpWrite(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *fh,
        unsigned int a4,
        unsigned __int64 offset,
        unsigned int *count,
        const void *buffer,
        unsigned int *resCount)
{
  unsigned int v9; // r26
  __int64 v10; // r24
  unsigned int v11; // r28
  const void *v14; // r25
  int v16; // r27
  unsigned int *v17; // r3
  unsigned int *v18; // r11
  unsigned int *v19; // r11
  unsigned int *v20; // r11
  unsigned int *v21; // r5
  unsigned int *v22; // r11
  unsigned int *v23; // r11
  int v24; // r28
  unsigned int v25; // r21
  char v26; // r11
  char v27; // r11
  char v28; // r11
  bool v29; // r11
  unsigned int *cur; // r11
  _DWORD *v31; // r10
  unsigned int v32; // r30
  bool v33; // cr58
  char v34; // r11
  const char *v35; // r3
  idNfsClient::NfsErr result; // r3
  unsigned int v37; // r6
  bool v38; // cr58
  unsigned int *v39; // r11
  unsigned int v40; // r9
  int v41; // [sp+50h] [-70h] BYREF
  unsigned int v42; // [sp+54h] [-6Ch] BYREF

  *count = 0;
  v9 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v9;
  v10 = a4;
  v11 = HIDWORD(offset);
  v14 = (const void *)offset;
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v9, numOp: 2u, tag: "<write>");
  *buf->cur++ = 22;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fh->fhData, len: fh->fhSize);
  *buf->cur = 38;
  v16 = 0;
  v17 = buf->cur + 1;
  buf->cur = v17;
  *v17 = fh->stateId.data[0];
  v18 = buf->cur + 1;
  buf->cur = v18;
  *v18 = fh->stateId.data[1];
  v19 = buf->cur + 1;
  buf->cur = v19;
  *v19 = fh->stateId.data[2];
  v20 = buf->cur + 1;
  buf->cur = v20;
  *v20 = fh->stateId.data[3];
  v21 = buf->cur + 1;
  buf->cur = v21;
  *(_QWORD *)v21 = v10;
  v22 = buf->cur + 2;
  buf->cur = v22;
  *v22 = 2;
  v23 = buf->cur + 1;
  buf->cur = v23;
  if ( v11 > 0x100 )
  {
    *v23 = v11;
    v16 = v11;
    ++buf->cur;
  }
  else
  {
    idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: v14, len: v11);
  }
  v24 = -v16 & 3;
  v25 = ((char *)buf->cur - (char *)buf) & 0xFFFFFFFC;
  buf->buffer[0] = (v25 + v24 + v16 - 4) | 0x80000000;
  if ( idTCP::WriteBlocking(this: &this->rpcCon.con.sock, data: buf, size: v25, timeoutMS: 5000) == v25 )
  {
    v26 = 1;
  }
  else
  {
    idTCP::Close(this: &this->rpcCon.con.sock);
    v26 = 0;
  }
  if ( v26 == 0 )
    return NFS_ERR_CON;
  if ( v16 != 0 )
  {
    if ( idTCP::WriteBlocking(this: &this->rpcCon.con.sock, data: v14, size: v16, timeoutMS: 5000) == v16 )
    {
      v27 = 1;
    }
    else
    {
      idTCP::Close(this: &this->rpcCon.con.sock);
      v27 = 0;
    }
    if ( v27 == 0 )
      return NFS_ERR_CON;
  }
  if ( v24 != 0 )
  {
    v41 = 0;
    if ( idTCP::WriteBlocking(this: &this->rpcCon.con.sock, data: &v41, size: -v16 & 3, timeoutMS: 5000) == v24 )
    {
      v28 = 1;
    }
    else
    {
      idTCP::Close(this: &this->rpcCon.con.sock);
      v28 = 0;
    }
    if ( v28 == 0 )
      return NFS_ERR_CON;
  }
  v29 = (unsigned __int8)idRpc::Connection::RecvHeader(this: &this->rpcCon.con) != 0
     && (unsigned __int8)idRpc::RpcIOBuffer::ReadFromCon(this: buf, con: &this->rpcCon.con, maxRead: 0) != 0;
  if ( !v29 || (unsigned __int8)idRpc::RPCReadRPCHeader(buf, rpcIdx: &v42) == 0 )
    return NFS_ERR_CON;
  cur = buf->cur;
  v31 = cur + 1;
  v32 = *cur;
  buf->cur = cur + 1;
  if ( v32 == 0 )
    goto LABEL_35;
  if ( v32 > 0x11 )
  {
    if ( v32 == 30 )
      goto LABEL_32;
    v33 = v32 == 10048;
  }
  else
  {
    if ( v32 == 17 || v32 <= 2 )
      goto LABEL_32;
    v33 = v32 == 13;
  }
  if ( !v33 )
  {
    v34 = 0;
    goto LABEL_33;
  }
LABEL_32:
  v34 = 1;
LABEL_33:
  if ( v34 == 0 )
  {
    v35 = Nfs4Const::NfsStatusToStr(val: v32);
    idLib::Warning(fmt: "idNfs4Client::OpWrite: compound header status: %d (%s)", v32, v35);
    return idNfs4Client::DecodeNfs4Error(this, nfs4Err: v32);
  }
LABEL_35:
  v37 = v42;
  v38 = v42 == v9;
  buf->cur = &v31[((unsigned int)(*v31 + 3) >> 2) + 2];
  if ( !v38 )
  {
    idLib::Warning(fmt: "NFS %s incorrect seq id %d, %d", "OpWrite", v9, v37);
    return NFS_ERR_CON;
  }
  result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
  if ( result == NFS_OK )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x26u);
    if ( result == NFS_OK )
    {
      v39 = buf->cur;
      v40 = *v39;
      buf->cur = v39 + 4;
      *count = v40;
    }
  }
  return result;
}


// ========================================================================
// ?OpGetAttr@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@PAVNfsFileAttr@3@@Z
// EA  : 0x82F15868
// RVA : 0x00F15868
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpGetAttr(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *fh,
        idNfsClient::NfsFileAttr *attr)
{
  unsigned int v5; // r29
  unsigned int *v9; // r11
  __int64 v10; // r9
  unsigned int *v11; // r11
  idNfsClient::NfsErr result; // r3
  unsigned int v13; // [sp+50h] [-40h] BYREF
  unsigned int v14; // [sp+54h] [-3Ch] BYREF

  v5 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v5;
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v5, numOp: 2u, tag: "<get attr>");
  *buf->cur++ = 22;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fh->fhData, len: fh->fhSize);
  *buf->cur = 9;
  v9 = buf->cur + 1;
  buf->cur = v9;
  LODWORD(v10) = 32769;
  *v9 = 2;
  v11 = buf->cur + 1;
  buf->cur = v11;
  *(_QWORD *)v11 = v10 << 21;
  buf->cur += 2;
  result = idNfs4Client::RPCSendRecv(this, buf, opName: "OpGetAttr", idx: v5, numOps: &v14, replyCompStatus: &v13);
  if ( result != NFS_ERR_CON )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
    if ( result == NFS_OK )
      return idNfs4Client::SubOpGetFileAttrRead(this, buf, attr);
  }
  return result;
}


// ========================================================================
// ?OpSetAttr@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@PAVNfsFileAttr@3@_K@Z
// EA  : 0x82F15978
// RVA : 0x00F15978
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpSetAttr(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *fh,
        idNfsClient::NfsFileAttr *attr,
        unsigned __int64 attrMask)
{
  __int64 v7; // r28
  unsigned int *v10; // r3
  unsigned int *v11; // r11
  unsigned int *v12; // r11
  unsigned int *v13; // r11
  unsigned int *v14; // r6
  unsigned int *v15; // r11
  unsigned int *v16; // r11
  unsigned int v17; // r10
  unsigned int *v18; // r11
  idNfsClient::NfsErr result; // r3
  __int64 v20; // r8
  __int64 v21; // r6
  unsigned int v22; // [sp+50h] [-40h] BYREF
  unsigned int v23; // [sp+54h] [-3Ch] BYREF

  HIDWORD(v7) = this->nextRpcIdx + 1;
  this->nextRpcIdx = HIDWORD(v7);
  LODWORD(v7) = HIDWORD(attrMask);
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: HIDWORD(v7), numOp: 2u, tag: "<set attr>");
  *buf->cur++ = 22;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fh->fhData, len: fh->fhSize);
  *buf->cur = 34;
  v10 = buf->cur + 1;
  buf->cur = v10;
  *v10 = fh->stateId.data[0];
  v11 = buf->cur + 1;
  buf->cur = v11;
  *v11 = fh->stateId.data[1];
  v12 = buf->cur + 1;
  buf->cur = v12;
  *v12 = fh->stateId.data[2];
  v13 = buf->cur + 1;
  buf->cur = v13;
  *v13 = fh->stateId.data[3];
  v14 = buf->cur + 1;
  buf->cur = v14;
  if ( (_DWORD)v7 != 0 )
  {
    *v14 = 2;
    v15 = buf->cur + 1;
    buf->cur = v15;
    *(_QWORD *)v15 = v7;
    buf->cur += 2;
  }
  else
  {
    *v14 = 1;
    v16 = buf->cur + 1;
    buf->cur = v16;
    *v16 = HIDWORD(v7);
    ++buf->cur;
  }
  v17 = 0;
  if ( (v7 & 0x10) != 0 )
    v17 = 8;
  *buf->cur = v17;
  v18 = buf->cur + 1;
  buf->cur = v18;
  if ( (v7 & 0x10) != 0 )
  {
    *(_QWORD *)v18 = attr->size;
    buf->cur += 2;
  }
  result = idNfs4Client::RPCSendRecv(
             this,
             buf,
             opName: "OpSetattr",
             idx: HIDWORD(v7),
             numOps: &v23,
             replyCompStatus: &v22);
  if ( result != NFS_ERR_CON )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
    if ( result == NFS_OK )
    {
      result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x22u);
      if ( result == NFS_OK )
      {
        HIDWORD(v21) = idNfs4Client::ProtocolHelperFattrMaskRead(this, buf);
        if ( HIDWORD(v21) == (_DWORD)v7 )
        {
          return NFS_OK;
        }
        else
        {
          idLib::Warning(fmt: "NFS OpSetAttr getattr attrib missmatch: attr: %llu, %llu", v21, v20);
          return NFS_ERR_OTHER;
        }
      }
    }
  }
  return result;
}


// ========================================================================
// ?OpCreateDir@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@PBD@Z
// EA  : 0x82F15B98
// RVA : 0x00F15B98
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::OpCreateDir(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *rootFh,
        const char *path)
{
  unsigned int v6; // r26
  unsigned int v9; // r5
  const char *v10; // r11
  unsigned int *v11; // r11
  unsigned int *v12; // r11
  int v13; // r3
  const char *v14; // r4
  __int64 v15; // r29
  int v16; // r27
  unsigned int v17; // r5
  unsigned int *v18; // r11
  unsigned int *v19; // r11
  unsigned int *v20; // r11
  unsigned int *v21; // r11
  int v23; // r29
  const char *v24; // [sp+50h] [-50h] BYREF
  unsigned int v25; // [sp+54h] [-4Ch] BYREF

  v6 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v6;
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v6, prog: 0x186A3u, version: 4u, proc: 1u);
  v9 = 0;
  v10 = "<create dir>";
  do
  {
    ++v10;
    ++v9;
  }
  while ( *v10 != 0 );
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: "<create dir>", len: v9);
  *buf->cur = 0;
  v11 = buf->cur + 1;
  buf->cur = v11;
  HIDWORD(v15) = v11;
  *v11 = 0;
  v12 = buf->cur + 1;
  buf->cur = v12;
  *v12 = 22;
  ++buf->cur;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: rootFh->fhData, len: rootFh->fhSize);
  v13 = idNfs4Client::SubOpLookUpChainWrite(this, buf, path, last: &v24);
  v14 = v24;
  LODWORD(v15) = 2;
  v16 = v13;
  v17 = 0;
  *buf->cur = 6;
  v18 = buf->cur + 1;
  buf->cur = v18;
  *v18 = 2;
  ++buf->cur;
  if ( *v14 != 0 )
  {
    do
      ++v17;
    while ( v14[v17] != 0 );
  }
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: v14, len: v17);
  *buf->cur = 2;
  v19 = buf->cur + 1;
  buf->cur = v19;
  *(_QWORD *)v19 = v15;
  v20 = buf->cur + 2;
  buf->cur = v20;
  *v20 = 4;
  v21 = buf->cur + 1;
  buf->cur = v21;
  *v21 = 511;
  ++buf->cur;
  *(_DWORD *)HIDWORD(v15) = v16 + 2;
  if ( idNfs4Client::RPCSendRecv(
         this,
         buf,
         opName: "OpCreateDir",
         idx: v6,
         numOps: &v25,
         replyCompStatus: (unsigned int *)&v24) == 1 )
    return 1;
  if ( v24 != (const char *)17 )
  {
    if ( v24 != nullptr )
      return idNfs4Client::DecodeNfs4Error(this, nfs4Err: (unsigned int)v24);
    if ( idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u) == 1 )
      return 1;
    v23 = 0;
    if ( v16 > 0 )
    {
      while ( idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0xFu) != 1 )
      {
        if ( ++v23 >= v16 )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?OpRemove@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@PBD@Z
// EA  : 0x82F15DC0
// RVA : 0x00F15DC0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpRemove(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *rootFh,
        const char *path)
{
  unsigned int v6; // r25
  unsigned int v9; // r5
  const char *v10; // r11
  unsigned int *v11; // r11
  unsigned int *v12; // r26
  unsigned int *v13; // r11
  int v14; // r3
  const char *v15; // r4
  int v16; // r29
  unsigned int v17; // r5
  idNfsClient::NfsErr result; // r3
  const char *v19; // [sp+50h] [-50h] BYREF
  unsigned int v20; // [sp+54h] [-4Ch] BYREF

  v6 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v6;
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v6, prog: 0x186A3u, version: 4u, proc: 1u);
  v9 = 0;
  v10 = "<remove>";
  do
  {
    ++v10;
    ++v9;
  }
  while ( *v10 != 0 );
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: "<remove>", len: v9);
  *buf->cur = 0;
  v11 = buf->cur + 1;
  buf->cur = v11;
  v12 = v11;
  *v11 = 0;
  v13 = buf->cur + 1;
  buf->cur = v13;
  *v13 = 22;
  ++buf->cur;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: rootFh->fhData, len: rootFh->fhSize);
  v14 = idNfs4Client::SubOpLookUpChainWrite(this, buf, path, last: &v19);
  v15 = v19;
  v16 = v14;
  v17 = 0;
  *buf->cur++ = 28;
  if ( *v15 != 0 )
  {
    do
      ++v17;
    while ( v15[v17] != 0 );
  }
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: v15, len: v17);
  *v12 = v16 + 2;
  result = idNfs4Client::RPCSendRecv(
             this,
             buf,
             opName: "OpRemove",
             idx: v6,
             numOps: &v20,
             replyCompStatus: (unsigned int *)&v19);
  if ( result != NFS_ERR_CON )
    return idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
  return result;
}


// ========================================================================
// ?OpReadServerAttr@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@PAVNfsServerAttr@1@@Z
// EA  : 0x82F15F28
// RVA : 0x00F15F28
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpReadServerAttr(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *rootFh,
        idNfs4Client::NfsServerAttr *attr)
{
  unsigned int v5; // r29
  unsigned int *v9; // r11
  unsigned int *v10; // r11
  __int64 v11; // r4
  int v12; // r3
  unsigned int *cur; // r10
  __int64 v14; // r9
  unsigned int *v15; // r11
  __int64 v16; // r8
  __int64 v17; // r6
  unsigned int v18; // r10
  unsigned int *v19; // r11
  __int64 v20; // r7
  unsigned int *v21; // r11
  unsigned int v23; // [sp+50h] [-40h] BYREF
  unsigned int v24; // [sp+54h] [-3Ch] BYREF

  v5 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v5;
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v5, numOp: 2u, tag: "<get attr>");
  *buf->cur++ = 22;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: rootFh->fhData, len: rootFh->fhSize);
  *buf->cur = 9;
  v9 = buf->cur + 1;
  buf->cur = v9;
  *v9 = 1;
  v10 = buf->cur + 1;
  buf->cur = v10;
  *v10 = -1073740800;
  ++buf->cur;
  HIDWORD(v11) = idNfs4Client::RPCSendRecv(
                   this,
                   buf,
                   opName: "OpReadServerAttr",
                   idx: v5,
                   numOps: &v24,
                   replyCompStatus: &v23);
  if ( HIDWORD(v11) != 1 )
  {
    HIDWORD(v11) = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
    if ( HIDWORD(v11) == 0 )
    {
      HIDWORD(v11) = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 9u);
      if ( HIDWORD(v11) == 0 )
      {
        v12 = idNfs4Client::ProtocolHelperFattrMaskRead(this, buf);
        cur = buf->cur;
        LODWORD(v14) = 3145729;
        v15 = cur + 1;
        v16 = v14 << 42;
        HIDWORD(v17) = *cur;
        buf->cur = cur + 1;
        if ( __PAIR64__(v12, HIDWORD(v17)) == __PAIR64__(v16, 20) )
        {
          v18 = *v15;
          buf->cur = v15 + 1;
          attr->leaseTime = v18;
          v19 = buf->cur;
          v20 = *(_QWORD *)v19;
          buf->cur = v19 + 2;
          attr->maxReadSize = v20;
          v21 = buf->cur;
          v11 = *(_QWORD *)v21;
          buf->cur = v21 + 2;
          attr->maxWriteSize = v11;
        }
        else
        {
          idLib::Warning(
            fmt: "NFS OpReadServerStat getattr attrib or attrib size missmatch: attr: %llu, size: %u",
            v17,
            HIDWORD(v16));
          HIDWORD(v11) = 4;
        }
      }
    }
  }
  return HIDWORD(v11);
}


// ========================================================================
// ?OpCommit@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@_KI@Z
// EA  : 0x82F160C8
// RVA : 0x00F160C8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpCommit(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *fh,
        unsigned int a4,
        unsigned __int64 offset,
        unsigned int count)
{
  unsigned int v7; // r29
  unsigned __int64 v8; // r27
  unsigned int *v11; // r11
  unsigned int *v12; // r11
  idNfsClient::NfsErr result; // r3
  unsigned int v14; // [sp+50h] [-40h] BYREF
  unsigned int v15; // [sp+54h] [-3Ch] BYREF

  v7 = this->nextRpcIdx + 1;
  v8 = __PAIR64__(HIDWORD(offset), a4);
  this->nextRpcIdx = v7;
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v7, numOp: 2u, tag: "commit");
  *buf->cur++ = 22;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fh->fhData, len: fh->fhSize);
  *buf->cur = 5;
  v11 = buf->cur + 1;
  buf->cur = v11;
  *(_QWORD *)v11 = v8;
  v12 = buf->cur + 2;
  buf->cur = v12;
  *v12 = HIDWORD(v8);
  ++buf->cur;
  result = idNfs4Client::RPCSendRecv(this, buf, opName: "OpCommit", idx: v7, numOps: &v15, replyCompStatus: &v14);
  if ( result != NFS_ERR_CON )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
    if ( result == NFS_OK )
      return idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 5u);
  }
  return result;
}


// ========================================================================
// ?OpRenewLease@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsClientId@1@@Z
// EA  : 0x82F161C8
// RVA : 0x00F161C8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpRenewLease(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs4Client::NfsClientId *clientId)
{
  unsigned int v4; // r29
  unsigned int *v7; // r11
  idNfsClient::NfsErr result; // r3
  unsigned int v9; // [sp+50h] [-30h] BYREF
  unsigned int v10; // [sp+54h] [-2Ch] BYREF

  v4 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v4;
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v4, numOp: 1u, tag: "<renew lease>");
  *buf->cur = 30;
  v7 = buf->cur + 1;
  buf->cur = v7;
  *(_QWORD *)v7 = clientId->clientId;
  buf->cur += 2;
  result = idNfs4Client::RPCSendRecv(this, buf, opName: "OpRenew", idx: v4, numOps: &v10, replyCompStatus: &v9);
  if ( result != NFS_ERR_CON )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x1Eu);
    if ( result == NFS_OK || v9 == 10048 )
      return NFS_OK;
  }
  return result;
}


// ========================================================================
// ?Open@idNfs4Client@@UAA_NPAVNfsFh@idNfsClient@@PBDW4fsMode_t@@_N3PAVNfsFileAttr@3@@Z
// EA  : 0x82F16298
// RVA : 0x00F16298
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::Open(
        idNfs4Client *this,
        idNfsClient::NfsFh *fh,
        const char *path,
        fsMode_t mode,
        bool create,
        unsigned __int8 trunc,
        idNfsClient::NfsFileAttr *attrAtOpen)
{
  idSysMutex *p_mutex; // r29
  bool v16; // [sp+Bh] [-B5h]
  idNfsClient::NfsFileAttr *v17; // [sp+Ch] [-B4h]
  int v18; // [sp+10h] [-B0h]
  int v19; // [sp+14h] [-ACh]
  int v20; // [sp+18h] [-A8h]
  int v21; // [sp+1Ch] [-A4h]
  int v22; // [sp+20h] [-A0h]
  int v23; // [sp+24h] [-9Ch]
  int v24; // [sp+28h] [-98h]
  int v25; // [sp+2Ch] [-94h]
  int v26; // [sp+30h] [-90h]
  int v27; // [sp+34h] [-8Ch]
  int v28; // [sp+38h] [-88h]
  int v29; // [sp+3Ch] [-84h]
  int v30; // [sp+40h] [-80h]
  int v31; // [sp+44h] [-7Ch]
  int v32; // [sp+48h] [-78h]
  int v33; // [sp+4Ch] [-74h]
  int v34; // [sp+50h] [-70h]
  int v35; // [sp+58h] [-68h]

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( idNfs4Client::OpOpen(
         this,
         buf: &this->ioBuffer,
         clientId: &this->clientId,
         dst: fh,
         src: &this->rootFh,
         path,
         mode,
         create,
         trunc: v16,
         attrAtOpen: v17,
         a11: v18,
         a12: v19,
         a13: v20,
         a14: v21,
         a15: v22,
         a16: v23,
         a17: v24,
         a18: v25,
         a19: v26,
         a20: v27,
         a21: v28,
         a22: v29,
         a23: v30,
         a24: v31,
         a25: v32,
         a26: v33,
         a27: v34,
         a28: trunc,
         a29: v35,
         a30: attrAtOpen) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$122011
// EA  : 0x82F16330
// RVA : 0x00F16330
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_122011()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 192 + 96));
}


// ========================================================================
// ?Close@idNfs4Client@@UAA_NPAVNfsFh@idNfsClient@@@Z
// EA  : 0x82F16360
// RVA : 0x00F16360
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::Close(idNfs4Client *this, idNfsClient::NfsFh *fh)
{
  idSysMutex *p_mutex; // r29

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( idNfs4Client::OpClose(this, buf: &this->ioBuffer, clientId: &this->clientId, fh) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$122058
// EA  : 0x82F163CC
// RVA : 0x00F163CC
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_122058()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?Read@idNfs4Client@@UAAIPAVNfsFh@idNfsClient@@_JIPAX@Z
// EA  : 0x82F16400
// RVA : 0x00F16400
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

unsigned int __fastcall idNfs4Client::Read(
        idNfs4Client *this,
        idNfsClient::NfsFh *fh,
        __int64 offset,
        unsigned int len,
        void *buffer)
{
  idSysMutex *p_mutex; // r23
  int v8; // r26
  unsigned int v9; // r28
  unsigned int v11; // r30
  unsigned __int64 v12; // r8
  bool *v14; // [sp+8h] [-A8h]
  unsigned int *v15; // [sp+Ch] [-A4h]
  bool v16; // [sp+50h] [-60h] BYREF
  size_t v17[23]; // [sp+54h] [-5Ch] BYREF

  p_mutex = &this->mutex;
  v17[1] = (size_t)&this->mutex;
  v8 = HIDWORD(offset);
  v9 = offset;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  v11 = 0;
  while ( v11 < v9 )
  {
    HIDWORD(v12) = v9 - v11;
    if ( v9 - v11 >= this->serverAttr.maxReadSize )
      HIDWORD(v12) = this->serverAttr.maxReadSize;
    LODWORD(v12) = v11 + len;
    if ( idNfs4Client::OpRead(
           this,
           buf: &this->ioBuffer,
           fh,
           a4: v11 + v8,
           offset: v12,
           count: &v16,
           buffer: v17,
           eof: v14,
           resCount: v15) != NFS_OK )
      break;
    v11 += v17[0];
    if ( v16 )
      break;
  }
  Sys_MutexUnlock(handle: &p_mutex->handle);
  return v11;
}


// ========================================================================
// __unwind$122104
// EA  : 0x82F164B8
// RVA : 0x00F164B8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_122104()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 88));
}


// ========================================================================
// ?Write@idNfs4Client@@UAAIPAVNfsFh@idNfsClient@@_JIPBX@Z
// EA  : 0x82F164E8
// RVA : 0x00F164E8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

unsigned int __fastcall idNfs4Client::Write(
        idNfs4Client *this,
        idNfsClient::NfsFh *fh,
        __int64 offset,
        unsigned int len,
        const void *buffer)
{
  idSysMutex *p_mutex; // r23
  int v8; // r26
  unsigned int v9; // r28
  const void *v11; // r10
  unsigned int i; // r30
  unsigned __int64 v13; // r8
  unsigned int *v15; // [sp+8h] [-A8h]
  unsigned int v16[24]; // [sp+50h] [-60h] BYREF

  p_mutex = &this->mutex;
  v16[1] = (unsigned int)&this->mutex;
  v8 = HIDWORD(offset);
  v9 = offset;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  for ( i = 0; i < v9; i += v16[0] )
  {
    HIDWORD(v13) = v9 - i;
    if ( v9 - i >= this->serverAttr.maxWriteSize )
      HIDWORD(v13) = this->serverAttr.maxWriteSize;
    LODWORD(v13) = i + len;
    if ( idNfs4Client::OpWrite(
           this,
           buf: &this->ioBuffer,
           fh,
           a4: i + v8,
           offset: v13,
           count: v16,
           buffer: v11,
           resCount: v15) != NFS_OK )
      break;
    if ( v16[0] == 0 )
      break;
  }
  Sys_MutexUnlock(handle: &p_mutex->handle);
  return i;
}


// ========================================================================
// __unwind$122153
// EA  : 0x82F16598
// RVA : 0x00F16598
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_122153()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 84));
}


// ========================================================================
// ?GetAttr@idNfs4Client@@UAA_NPAVNfsFh@idNfsClient@@PAVNfsFileAttr@3@@Z
// EA  : 0x82F165C8
// RVA : 0x00F165C8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::GetAttr(idNfs4Client *this, idNfsClient::NfsFh *fh, idNfsClient::NfsFileAttr *attr)
{
  idSysMutex *p_mutex; // r29

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( idNfs4Client::OpGetAttr(this, buf: &this->ioBuffer, fh, attr) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$122203
// EA  : 0x82F16638
// RVA : 0x00F16638
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_122203()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?SetSize@idNfs4Client@@UAA_NPAVNfsFh@idNfsClient@@_J@Z
// EA  : 0x82F16668
// RVA : 0x00F16668
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::SetSize(idNfs4Client *this, idNfsClient::NfsFh *fh, __int64 size)
{
  unsigned __int64 v3; // r27
  idSysMutex *p_mutex; // r29
  unsigned __int64 v7; // r8
  idNfsClient::NfsFileAttr v9[3]; // [sp+60h] [-50h] BYREF

  p_mutex = &this->mutex;
  LODWORD(v3) = HIDWORD(size);
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  v9[0].size = v3;
  HIDWORD(v7) = 16;
  if ( idNfs4Client::OpSetAttr(this, buf: &this->ioBuffer, fh, attr: v9, attrMask: v7) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$122250
// EA  : 0x82F166E4
// RVA : 0x00F166E4
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_122250()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 80));
}


// ========================================================================
// ?CreateDir@idNfs4Client@@UAA_NPBD@Z
// EA  : 0x82F16718
// RVA : 0x00F16718
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::CreateDir(idNfs4Client *this, const char *path)
{
  idSysMutex *p_mutex; // r29

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( idNfs4Client::OpCreateDir(this, buf: &this->ioBuffer, rootFh: &this->rootFh, path) != 0 )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$122297
// EA  : 0x82F16784
// RVA : 0x00F16784
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_122297()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?RemoveFileDir@idNfs4Client@@UAA_NPBD@Z
// EA  : 0x82F167B8
// RVA : 0x00F167B8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::RemoveFileDir(idNfs4Client *this, const char *path)
{
  idSysMutex *p_mutex; // r29

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( idNfs4Client::OpRemove(this, buf: &this->ioBuffer, rootFh: &this->rootFh, path) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$122344
// EA  : 0x82F16824
// RVA : 0x00F16824
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_122344()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?Commit@idNfs4Client@@UAA_NPAVNfsFh@idNfsClient@@_J1@Z
// EA  : 0x82F16858
// RVA : 0x00F16858
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::Commit(idNfs4Client *this, idNfsClient::NfsFh *fh, __int64 offset, __int64 size)
{
  idSysMutex *p_mutex; // r29
  unsigned int v7; // r27
  int v8; // r26
  unsigned __int64 v9; // r8
  unsigned int v10; // r9

  p_mutex = &this->mutex;
  v7 = HIDWORD(offset);
  v8 = offset;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  HIDWORD(v9) = v8;
  if ( idNfs4Client::OpCommit(this, buf: &this->ioBuffer, fh, a4: v7, offset: v9, count: v10) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$122391
// EA  : 0x82F168D0
// RVA : 0x00F168D0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_122391()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?NfsSendRecv@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PBDIAAI@Z
// EA  : 0x82F168F8
// RVA : 0x00F168F8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::NfsSendRecv(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        const char *opName,
        unsigned int idx,
        unsigned int *replyStatus)
{
  idRpc *p_nfsCon; // r30
  char v11; // r11
  unsigned int *cur; // r11
  unsigned int v14; // r5
  bool v15; // cr58
  char v16; // r11
  const char *v17; // r3
  int v18; // r5
  unsigned int v19; // [sp+50h] [-40h] BYREF

  p_nfsCon = &this->nfsCon;
  if ( !idRpc::RPCSend(this: &this->nfsCon, buf) )
    return 1;
  v11 = idRpc::Connection::RecvHeader(this: &p_nfsCon->con);
  if ( v11 != 0 )
    v11 = (unsigned __int8)idRpc::RpcIOBuffer::ReadFromCon(this: buf, con: &p_nfsCon->con, maxRead: 0) != 0;
  if ( v11 == 0 || (unsigned __int8)idRpc::RPCReadRPCHeader(buf, rpcIdx: &v19) == 0 )
    return 1;
  if ( v19 != idx )
  {
    idLib::Warning(fmt: "NFS %s incorrect seq id %d, %d", opName, idx, v19);
    return 1;
  }
  cur = buf->cur;
  v14 = *cur;
  buf->cur = cur + 1;
  *replyStatus = v14;
  if ( v14 != 0 )
  {
    if ( v14 > 0x11 )
    {
      v15 = v14 == 30;
    }
    else
    {
      if ( v14 == 17 || v14 <= 2 )
        goto LABEL_17;
      v15 = v14 == 13;
    }
    if ( !v15 )
    {
      v16 = 0;
      goto LABEL_18;
    }
LABEL_17:
    v16 = 1;
LABEL_18:
    if ( v16 == 0 )
    {
      v17 = Nfs3Const::NfsStatusToStr(err: v14);
      idLib::Warning(fmt: "idNfs4Client::RPCSendRecv: %s compound header status: %d (%s)", opName, v18, v17);
    }
  }
  return idNfs3Client::DecodeMnt3Error(this, nfs4Err: *replyStatus);
}


// ========================================================================
// ?MntSendRecv@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PBDI@Z
// EA  : 0x82F16A40
// RVA : 0x00F16A40
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::MntSendRecv(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        const char *opName,
        unsigned int idx)
{
  idRpc *p_mntCon; // r31
  char v8; // r11
  unsigned int v10; // [sp+50h] [-30h] BYREF

  p_mntCon = &this->mntCon;
  if ( !idRpc::RPCSend(this: &this->mntCon, buf) )
    return 1;
  v8 = idRpc::Connection::RecvHeader(this: &p_mntCon->con);
  if ( v8 != 0 )
    v8 = (unsigned __int8)idRpc::RpcIOBuffer::ReadFromCon(this: buf, con: &p_mntCon->con, maxRead: 0) != 0;
  if ( v8 == 0 || (unsigned __int8)idRpc::RPCReadRPCHeader(buf, rpcIdx: &v10) == 0 )
    return 1;
  if ( v10 != idx )
  {
    idLib::Warning(fmt: "NFS %s incorrect seq id %d, %d", opName, idx, v10);
    return 1;
  }
  return 0;
}


// ========================================================================
// ?OpMount@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfs3Fh@1@PBD@Z
// EA  : 0x82F16B00
// RVA : 0x00F16B00
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::OpMount(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::Nfs3Fh *rootFh,
        const char *mntPath)
{
  unsigned int v6; // r28
  unsigned int v9; // r5
  idNfsClient::NfsErr result; // r3
  unsigned int *cur; // r11
  unsigned int v12; // r30
  const char *v13; // r3
  unsigned int *v14; // r10
  char v15; // r9
  unsigned int *v16; // r11
  unsigned int v17; // r10
  unsigned int i; // ctr
  unsigned int v19; // r10

  v6 = this->nextMntIdx + 1;
  this->nextMntIdx = v6;
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v6, prog: 0x186A5u, version: 3u, proc: 1u);
  v9 = 0;
  if ( *mntPath != 0 )
  {
    do
      ++v9;
    while ( mntPath[v9] != 0 );
  }
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: mntPath, len: v9);
  result = idNfs3Client::MntSendRecv(this, buf, opName: "OpMount", idx: v6);
  if ( result == NFS_OK )
  {
    cur = buf->cur;
    v12 = *cur;
    buf->cur = cur + 1;
    if ( v12 != 0 )
    {
      v13 = Nfs3Const::MntStatusToStr(err: v12);
      idLib::Warning(fmt: "idNfs3Client::MntSendRecv: %s status: %d (%s)", "OpMount", v12, v13);
      if ( v12 > 2 )
      {
        if ( v12 == 13 )
          return NFS_ERR_ACCESS;
        if ( v12 == 10006 )
          return NFS_ERR_CON;
        else
          return NFS_ERR_OTHER;
      }
      else
      {
        if ( v12 != 2 )
          return NFS_ERR_ACCESS;
        return NFS_ERR_NOENT;
      }
    }
    else
    {
      idNfs3Client::Nfs3Fh::Read(this: rootFh, buf);
      v14 = buf->cur;
      v15 = 0;
      v16 = v14 + 1;
      v17 = *v14;
      buf->cur = v16;
      if ( v17 != 0 )
      {
        for ( i = v17; i != 0; --i )
        {
          v19 = *v16++;
          buf->cur = v16;
          if ( v19 == 1 )
            v15 = 1;
        }
      }
      if ( v15 == 0 )
        idLib::Error(fmt: "idNfs3Client::OpMount don't support AUTH_UNIX");
      return NFS_OK;
    }
  }
  return result;
}


// ========================================================================
// ?OpLookUp@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsClientId@1@PAVNfs3Fh@1@PBV71@PBDPAVNfsFileAttr@3@@Z
// EA  : 0x82F16C90
// RVA : 0x00F16C90
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::OpLookUp(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::NfsClientId *clientId,
        unsigned __int64 src,
        const char *path,
        idNfsClient::NfsFileAttr *attrAtOpen)
{
  unsigned int v7; // r29
  unsigned int v12; // r5
  idNfsClient::NfsErr result; // r3
  unsigned int *cur; // r11
  size_t v15; // r30
  unsigned int *v16; // r11
  unsigned __int64 v17; // r9
  bool v18; // cr58
  unsigned __int64 v19; // r11
  unsigned int v20; // [sp+50h] [-50h] BYREF

  v7 = this->nextNfsIdx + 1;
  this->nextNfsIdx = v7;
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v7, prog: 0x186A3u, version: 3u, proc: 3u);
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: (const void *)(src + 4), len: *(_DWORD *)src);
  LODWORD(src) = 0;
  v12 = 0;
  if ( *path != 0 )
  {
    do
      ++v12;
    while ( path[v12] != 0 );
  }
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: path, len: v12);
  result = idNfs3Client::NfsSendRecv(this, buf, opName: "OpLookUp", idx: v7, replyStatus: &v20);
  if ( result == NFS_OK )
  {
    cur = buf->cur;
    v15 = *cur;
    buf->cur = cur + 1;
    if ( v15 > 0x40 )
      v15 = 64;
    memcpy(Dst: (void *)(HIDWORD(src) + 4), Src: cur + 1, Size: v15);
    buf->cur = (unsigned int *)((char *)buf->cur + ((v15 + 3) & 0xFFFFFFFC));
    *(_DWORD *)HIDWORD(src) = v15;
    v16 = buf->cur;
    HIDWORD(v17) = *v16;
    v18 = *v16 == 0;
    buf->cur = v16 + 1;
    if ( v18 )
    {
      attrAtOpen->size = src;
      attrAtOpen->mTimeSec = src;
      attrAtOpen->mTimeNano = 0;
      return NFS_OK;
    }
    else
    {
      v19 = *((_QWORD *)v16 + 3);
      attrAtOpen->size = v19;
      LODWORD(v17) = *(_DWORD *)(HIDWORD(v19) + 68);
      attrAtOpen->mTimeSec = v17;
      attrAtOpen->mTimeNano = *(_DWORD *)(HIDWORD(v19) + 72);
      return NFS_OK;
    }
  }
  return result;
}


// ========================================================================
// ?OpRead@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfs3Fh@1@_KIPAXAA_NAAI@Z
// EA  : 0x82F16DD8
// RVA : 0x00F16DD8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::OpRead(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::Nfs3Fh *fh,
        int a4,
        unsigned __int64 offset,
        bool *count,
        size_t *buffer,
        bool *eof,
        unsigned int *resCount)
{
  __int64 v9; // r22
  unsigned int v12; // r29
  unsigned int v14; // r26
  char *v15; // r24
  unsigned int *v18; // r11
  char v19; // r11
  unsigned int *cur; // r10
  _DWORD *v22; // r11
  unsigned int v23; // r30
  bool v24; // cr58
  char v25; // r11
  const char *v26; // r3
  int v27; // r10
  unsigned int *v28; // r11
  unsigned int *v29; // r10
  size_t v30; // r30
  unsigned int v31; // r8
  unsigned int *v32; // r11
  int v33; // r10
  int rest; // r27
  unsigned int v35; // r29
  unsigned int v36; // r4
  size_t v37; // r5
  int v38; // r4
  unsigned int v39; // [sp+50h] [-60h] BYREF

  v12 = this->nextNfsIdx + 1;
  this->nextNfsIdx = v12;
  LODWORD(v9) = a4;
  v14 = HIDWORD(offset);
  v15 = (char *)offset;
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v12, prog: 0x186A3u, version: 3u, proc: 6u);
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fh->fhData, len: fh->fhSize);
  *(_QWORD *)buf->cur = v9;
  v18 = buf->cur + 2;
  buf->cur = v18;
  *v18 = v14;
  ++buf->cur;
  if ( !idRpc::RPCSend(this: &this->nfsCon, buf) )
    return 1;
  v19 = idRpc::Connection::RecvHeader(this: &this->nfsCon.con);
  if ( v19 != 0 )
    v19 = (unsigned __int8)idRpc::RpcIOBuffer::ReadFromCon(this: buf, con: &this->nfsCon.con, maxRead: 0x100u) != 0;
  if ( v19 == 0 || (unsigned __int8)idRpc::RPCReadRPCHeader(buf, rpcIdx: &v39) == 0 )
    return 1;
  if ( v39 != v12 )
  {
    idLib::Warning(fmt: "idNfs3Client::OpRead %s incorrect seq id %d, %d", "OpReadUp", v12, v39);
    return 1;
  }
  cur = buf->cur;
  v22 = cur + 1;
  v23 = *cur;
  buf->cur = cur + 1;
  if ( v23 != 0 )
  {
    if ( v23 > 0x11 )
    {
      v24 = v23 == 30;
    }
    else
    {
      if ( v23 == 17 || v23 <= 2 )
        goto LABEL_17;
      v24 = v23 == 13;
    }
    if ( !v24 )
    {
      v25 = 0;
LABEL_18:
      if ( v25 == 0 )
      {
        v26 = Nfs3Const::NfsStatusToStr(err: v23);
        idLib::Warning(fmt: "idNfs3Client::OpRead: nfs call status: %d (%s)", v23, v26);
      }
      return idNfs3Client::DecodeMnt3Error(this, nfs4Err: v23);
    }
LABEL_17:
    v25 = 1;
    goto LABEL_18;
  }
  v27 = *v22;
  v28 = v22 + 1;
  buf->cur = v28;
  if ( v27 != 0 )
    buf->cur = v28 + 21;
  v29 = buf->cur;
  v30 = *v29;
  buf->cur = v29 + 1;
  v31 = v29[1];
  buf->cur = v29 + 2;
  *count = v31 != 0;
  v32 = buf->cur + 1;
  v33 = (char *)buf->end - (char *)v32;
  buf->cur = v32;
  rest = this->nfsCon.con.rest;
  v35 = v33 & 0xFFFFFFFC;
  v36 = (v33 & 0xFFFFFFFC) + rest;
  if ( v36 != ((v30 + 3) & 0xFFFFFFFC) || v30 > v14 )
    idLib::Warning(fmt: "NFS OPRead result count error, in fragment: %d, reported: %d, requested: %d", v36, v30, v14);
  if ( v35 != 0 )
  {
    v37 = v35;
    if ( v35 >= v30 )
      v37 = v30;
    memcpy(Dst: v15, Src: buf->cur, Size: v37);
  }
  if ( rest != 0
    && (unsigned __int8)idRpc::Connection::Recv(this: &this->nfsCon.con, buf: &v15[v35], size: v30 - v35) == 0 )
  {
    return 1;
  }
  v38 = this->nfsCon.con.rest;
  if ( v38 != 0 )
  {
    if ( v38 != 4 - (v30 & 3) )
      idLib::FatalError(
        fmt: "NFS OPRead incomplete fragment read; rest: %d, replySize: %d (conrest: %d, bufres: %d)",
        v38,
        v30,
        rest,
        v35);
    idRpc::RpcIOBuffer::ReadFromCon(this: buf, con: &this->nfsCon.con, maxRead: 0);
  }
  *buffer = v30;
  return 0;
}


// ========================================================================
// ?OpGetAttr@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfs3Fh@1@PAVNfsFileAttr@3@@Z
// EA  : 0x82F170B8
// RVA : 0x00F170B8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::OpGetAttr(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::Nfs3Fh *fh,
        idNfsClient::NfsFileAttr *attr)
{
  unsigned int v6; // r30
  idNfsClient::NfsErr result; // r3
  unsigned int *cur; // r11
  unsigned __int64 v11; // r9
  unsigned int v12; // [sp+50h] [-40h] BYREF

  v6 = this->nextNfsIdx + 1;
  this->nextNfsIdx = v6;
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v6, prog: 0x186A3u, version: 3u, proc: 1u);
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fh->fhData, len: fh->fhSize);
  result = idNfs3Client::NfsSendRecv(this, buf, opName: "OpGetAttr", idx: v6, replyStatus: &v12);
  if ( result == NFS_OK )
  {
    cur = buf->cur;
    HIDWORD(v11) = ((char *)buf->end - (char *)cur) & 0xFFFFFFFC;
    if ( HIDWORD(v11) >= 0x54 )
    {
      attr->size = *(_QWORD *)(cur + 5);
      LODWORD(v11) = cur[17];
      attr->mTimeSec = v11;
      attr->mTimeNano = cur[18];
      return NFS_OK;
    }
    else
    {
      idLib::Warning(fmt: "idNfs3Client::OpGetAttr short fragment");
      return NFS_ERR_CON;
    }
  }
  return result;
}


// ========================================================================
// ?OpGetServerAttr@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfs3Fh@1@PAVNfsServerAttr@1@@Z
// EA  : 0x82F17188
// RVA : 0x00F17188
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::OpGetServerAttr(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::Nfs3Fh *rootFh,
        idNfs3Client::NfsServerAttr *attr)
{
  unsigned int v6; // r30
  idNfsClient::NfsErr result; // r3
  unsigned int *cur; // r11
  unsigned int *v11; // r10
  unsigned int v12; // r11
  unsigned int *v13; // r11
  unsigned int v14; // r9
  unsigned int *v15; // r11
  unsigned int *v16; // r8
  unsigned int v17; // r7
  unsigned int v18; // [sp+50h] [-40h] BYREF

  v6 = this->nextNfsIdx + 1;
  this->nextNfsIdx = v6;
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v6, prog: 0x186A3u, version: 3u, proc: 0x13u);
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: rootFh->fhData, len: rootFh->fhSize);
  result = idNfs3Client::NfsSendRecv(this, buf, opName: "OpGetServerAttr", idx: v6, replyStatus: &v18);
  if ( result == NFS_OK )
  {
    cur = buf->cur;
    v11 = cur + 1;
    v12 = *cur;
    buf->cur = v11;
    if ( v12 != 0 )
      buf->cur = v11 + 21;
    v13 = buf->cur;
    v14 = *v13;
    buf->cur = v13 + 1;
    attr->maxReadSize = v14;
    v15 = buf->cur + 2;
    v16 = buf->cur + 3;
    buf->cur = v15;
    v17 = *v15;
    buf->cur = v16;
    attr->maxWriteSize = v17;
    return NFS_OK;
  }
  return result;
}


// ========================================================================
// ?UnMountMounts@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@XZ
// EA  : 0x82F17260
// RVA : 0x00F17260
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::UnMountMounts(idNfs3Client *this)
{
  int v2; // r24
  int i; // r26
  idNfs3Client::Nfs3Mount *v4; // r27
  char *data; // r29
  unsigned int v6; // r30
  unsigned int v7; // r5

  v2 = 0;
  if ( this->mounts.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v4 = &this->mounts.list[i];
    if ( v4->status == NFS_OK )
      break;
LABEL_8:
    if ( ++v2 >= this->mounts.num )
      return 0;
  }
  data = v4->path.data;
  v6 = this->nextMntIdx + 1;
  this->nextMntIdx = v6;
  idRpc::RPCWriteRPCCallHeader(buf: &this->ioBuffer, rpcIdx: v6, prog: 0x186A5u, version: 3u, proc: 3u);
  v7 = 0;
  if ( *data != 0 )
  {
    do
      ++v7;
    while ( data[v7] != 0 );
  }
  idRpc::RpcIOBuffer::OpaqueWrite(this: &this->ioBuffer, data, len: v7);
  if ( idNfs3Client::MntSendRecv(this, buf: &this->ioBuffer, opName: "OpUnMount", idx: v6) != 1 )
  {
    v4->status = NFS_ERR_NOENT;
    goto LABEL_8;
  }
  return 1;
}


// ========================================================================
// ?Dissconnect@idNfs3Client@@UAAXXZ
// EA  : 0x82F17360
// RVA : 0x00F17360
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idNfs3Client::Dissconnect(idNfs3Client *this)
{
  idSysMutex *p_mutex; // r28

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( this->connected )
  {
    if ( idTCP::IsOpen(this: &this->mntCon.con.sock) )
      idNfs3Client::UnMountMounts(this);
    idTCP::Close(this: &this->mntCon.con.sock);
    idTCP::Close(this: &this->nfsCon.con.sock);
    this->connected = false;
  }
  Sys_MutexUnlock(handle: &p_mutex->handle);
}


// ========================================================================
// __unwind$123078
// EA  : 0x82F173DC
// RVA : 0x00F173DC
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_123078()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?ConnectWithPortMap@idRpc@@QAA_NPAVRpcIOBuffer@1@PBDII@Z
// EA  : 0x82F174B8
// RVA : 0x00F174B8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idRpc::ConnectWithPortMap(
        idRpc *this,
        idRpc::RpcIOBuffer *buf,
        const char *host,
        unsigned int prog,
        unsigned int version)
{
  unsigned int *v11; // r11
  unsigned int *v12; // r11
  unsigned int *v13; // r11
  unsigned int *cur; // r11
  unsigned int v15; // r29
  unsigned int v16; // [sp+50h] [-50h] BYREF

  idStr::operator=(this: &this->con.host, text: host);
  this->con.rest = 0;
  if ( !idTCP::Connect(this: &this->con.sock, host, port: 0x6Fu, nonBlocking: true, silent: false, nagle: false) )
  {
    idLib::Warning(fmt: "Could not connect to rpc portmap on %s", host);
    return 0;
  }
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: 0, prog: 0x186A0u, version: 2u, proc: 3u);
  *buf->cur = prog;
  v11 = buf->cur + 1;
  buf->cur = v11;
  *v11 = version;
  v12 = buf->cur + 1;
  buf->cur = v12;
  *v12 = 6;
  v13 = buf->cur + 1;
  buf->cur = v13;
  *v13 = 0;
  ++buf->cur;
  if ( !idRpc::RPCSend(this, buf)
    || !idRpc::RPCRecv(this, buf, maxRead: 0)
    || (unsigned __int8)idRpc::RPCReadRPCHeader(buf, rpcIdx: &v16) == 0 )
  {
    return 0;
  }
  if ( v16 != 0 )
  {
    idLib::Warning(fmt: "RpcPortap GEtPORT reply incorrect seq id %d, %d", 0, v16);
    return 0;
  }
  else
  {
    cur = buf->cur;
    v15 = *cur;
    buf->cur = cur + 1;
    idTCP::Close(this: &this->con.sock);
    if ( idRpc::Connection::Connect(this: &this->con, host, port: v15) )
    {
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "Could not connect to rpc service on  %s:%d", host, v15);
      return 0;
    }
  }
}


// ========================================================================
// ??0idNfs4Client@@QAA@XZ
// EA  : 0x82F17680
// RVA : 0x00F17680
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfs4Client *__fastcall idNfs4Client::idNfs4Client(idNfs4Client *this)
{
  unsigned __int64 v2; // r11

  this->__vftable = (idNfs4Client_vtbl *)&idNfs4Client::`vftable';
  idNfs4Client::NfsLeaseControl::NfsLeaseControl(this: &this->leaseControlThread);
  Sys_MutexCreate(handle: &this->mutex.handle);
  idRpc::Connection::Connection(this: &this->rpcCon.con);
  LODWORD(v2) = 0;
  this->connected = false;
  this->clientId.clientId = v2;
  this->clientId.verf = 0;
  this->clientId.seq = 0;
  this->clientId.nextOwner = 0;
  return this;
}


// ========================================================================
// __unwind$123358
// EA  : 0x82F17700
// RVA : 0x00F17700
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_123358()
{
  int v0; // r12

  idNfs4Client::NfsLeaseControl::~NfsLeaseControl(this: (idNfs4Client::NfsLeaseControl *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$123359
// EA  : 0x82F1772C
// RVA : 0x00F1772C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_123359()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ?Run@NfsLeaseControl@idNfs4Client@@UAAHXZ
// EA  : 0x82F177C0
// RVA : 0x00F177C0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::NfsLeaseControl::Run(idNfs4Client::NfsLeaseControl *this)
{
  idSysSignal *p_terminateSignal; // r27
  idNfs4Client *client; // r30

  p_terminateSignal = &this->terminateSignal;
  while ( !Sys_SignalWait(handle: &p_terminateSignal->handle, timeout: this->leaseTimeMS / 2) )
  {
    client = this->client;
    Sys_MutexLock(handle: &client->mutex.handle, blocking: true);
    idNfs4Client::OpRenewLease(this: client, buf: &client->ioBuffer, clientId: &client->clientId);
    Sys_MutexUnlock(handle: &client->mutex.handle);
  }
  return 0;
}


// ========================================================================
// __unwind$123414
// EA  : 0x82F17864
// RVA : 0x00F17864
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_123414()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?OpSetClientId@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsClientId@1@@Z
// EA  : 0x82F17890
// RVA : 0x00F17890
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpSetClientId(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs4Client::NfsClientId *id)
{
  unsigned int v4; // r29
  unsigned int *v7; // r11
  __int64 v8; // r7
  idNfsClient::NfsErr result; // r3
  unsigned int *cur; // r11
  __int64 v11; // r28
  __int64 v12; // r26
  unsigned int v13; // r29
  unsigned int *v14; // r11
  unsigned int *v15; // r11
  unsigned int v16; // [sp+50h] [-40h] BYREF
  unsigned int v17[15]; // [sp+54h] [-3Ch] BYREF

  v4 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v4;
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v4, numOp: 1u, tag: "OPSetClientId");
  *buf->cur = 35;
  v7 = buf->cur + 1;
  buf->cur = v7;
  LODWORD(v8) = id->verf;
  *(_QWORD *)v7 = v8;
  buf->cur += 2;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: id, len: 8u);
  *buf->cur++ = 0;
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: &byte_8200D768, len: 0);
  idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: &byte_8200D768, len: 0);
  *buf->cur++ = 0;
  result = idNfs4Client::RPCSendRecv(this, buf, opName: "OpSetClientId", idx: v4, numOps: v17, replyCompStatus: &v16);
  if ( result == NFS_OK )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x23u);
    if ( result == NFS_OK )
    {
      cur = buf->cur;
      v11 = *(_QWORD *)cur;
      buf->cur = cur + 2;
      v12 = *((_QWORD *)cur + 1);
      buf->cur = cur + 4;
      v13 = this->nextRpcIdx + 1;
      this->nextRpcIdx = v13;
      idNfs4Client::RPCWriteCompHeader(
        this,
        buf,
        rpcIdx: v13,
        numOp: 1u,
        tag: "<OP_SETCLIENTID_CONFIRM set client confirm id>");
      *buf->cur = 36;
      v14 = buf->cur + 1;
      buf->cur = v14;
      *(_QWORD *)v14 = v11;
      v15 = buf->cur + 2;
      buf->cur = v15;
      *(_QWORD *)v15 = v12;
      buf->cur += 2;
      result = idNfs4Client::RPCSendRecv(
                 this,
                 buf,
                 opName: "OpSetClientId_confirm",
                 idx: v13,
                 numOps: v17,
                 replyCompStatus: &v16);
      if ( result == NFS_OK )
      {
        result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x24u);
        if ( result == NFS_OK )
          *(_QWORD *)HIDWORD(v11) = v11;
      }
    }
  }
  return result;
}


// ========================================================================
// ?OpGetRoot@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@@Z
// EA  : 0x82F17A60
// RVA : 0x00F17A60
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs4Client::OpGetRoot(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *rootFh)
{
  unsigned int v4; // r29
  unsigned int *v7; // r11
  idNfsClient::NfsErr result; // r3
  unsigned int v9; // [sp+50h] [-30h] BYREF
  unsigned int v10; // [sp+54h] [-2Ch] BYREF

  v4 = this->nextRpcIdx + 1;
  this->nextRpcIdx = v4;
  idNfs4Client::RPCWriteCompHeader(this, buf, rpcIdx: v4, numOp: 2u, tag: "<get root fh>");
  *buf->cur = 24;
  v7 = buf->cur + 1;
  buf->cur = v7;
  *v7 = 10;
  ++buf->cur;
  result = idNfs4Client::RPCSendRecv(this, buf, opName: "OpGetRoot", idx: v4, numOps: &v10, replyCompStatus: &v9);
  if ( result == NFS_OK )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x18u);
    if ( result == NFS_OK )
    {
      result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0xAu);
      if ( result == NFS_OK )
      {
        idNfsClient::NfsFh::Read(this: rootFh, buf);
        return NFS_OK;
      }
    }
  }
  return result;
}


// ========================================================================
// ?Connect@idNfs4Client@@UAA_NPBD0_N@Z
// EA  : 0x82F17B40
// RVA : 0x00F17B40
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::Connect(idNfs4Client *this, const char *host, const char *path, bool forceRO)
{
  unsigned __int64 v6; // r27
  unsigned __int64 v8; // r10
  int v9; // r9

  if ( forceRO )
    idLib::Warning(fmt: "idNfs4Client::Connect: forceRO is not implemented in the nfs4 client, consider using nfs3 with ro");
  HIDWORD(v6) = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  idStr::operator=(this: &this->rpcCon.con.host, text: host);
  LODWORD(v6) = 0;
  this->rpcCon.con.rest = 0;
  if ( idTCP::Connect(this: &this->rpcCon.con.sock, host, port: 0x801u, nonBlocking: true, silent: false, nagle: false) )
  {
    this->nextRpcIdx = 0;
    this->clientId.clientId = v6;
    LODWORD(v8) = (Sys_CurrentSystemTime() >> 32) + LODWORD(this->clientId.clientId);
    this->clientId.clientId = v8;
    this->clientId.verf = Sys_Microseconds() >> 32;
    this->clientId.nextOwner = 0;
    if ( idNfs4Client::OpSetClientId(this, buf: &this->ioBuffer, id: &this->clientId) != NFS_OK
      || idNfs4Client::OpGetRoot(this, buf: &this->ioBuffer, rootFh: &this->rootFh) != NFS_OK
      || idNfs4Client::OpReadServerAttr(this, buf: &this->ioBuffer, rootFh: &this->rootFh, attr: &this->serverAttr) != NFS_OK )
    {
      idTCP::Close(this: &this->rpcCon.con.sock);
      this->connected = false;
      Sys_MutexUnlock(handle: &this->mutex.handle);
      return 0;
    }
    else
    {
      v9 = 1000 * this->serverAttr.leaseTime;
      this->connected = true;
      this->leaseControlThread.client = this;
      this->leaseControlThread.leaseTimeMS = v9;
      idSysThread::StartThread(
        this: &this->leaseControlThread,
        name_: "leaseControl",
        core: CORE_ANY,
        priority: THREAD_NORMAL,
        stackSize: 0x20000);
      Sys_MutexUnlock(handle: &this->mutex.handle);
      return 1;
    }
  }
  else
  {
    Sys_MutexUnlock(handle: &this->mutex.handle);
    return 0;
  }
}


// ========================================================================
// __unwind$123698
// EA  : 0x82F17CD0
// RVA : 0x00F17CD0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_123698()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 160 + 80));
}


// ========================================================================
// ?OpListFiles@idNfs4Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsFh@3@PBD2PAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F17E10
// RVA : 0x00F17E10
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idNfsClient::NfsErr __fastcall idNfs4Client::OpListFiles(
        idNfs4Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfsClient::NfsFh *rootFh,
        const char *path,
        const char *extension,
        idList<idStr,5> *list)
{
  char *fhData; // r15
  __int64 v11; // r25 OVERLAPPED
  const char *v12; // r23 OVERLAPPED
  unsigned int v13; // r27
  const char *v14; // r11
  unsigned int v15; // r5
  unsigned int *v16; // r11
  unsigned int *v17; // r10
  unsigned int *v18; // r11
  int v19; // r28
  unsigned int *v20; // r11
  unsigned int *v21; // r11
  unsigned int *v22; // r11
  unsigned int *v23; // r11
  unsigned int *v24; // r11
  unsigned int *v25; // r11
  idNfsClient::NfsErr result; // r3
  int v27; // r27
  bool v28; // r28
  unsigned int *cur; // r10
  unsigned int v30; // r8
  unsigned int *v31; // r11
  int v32; // r7
  __int64 v33; // r6 OVERLAPPED
  unsigned int *v34; // r10
  _DWORD *v35; // r11
  unsigned int v36; // r4
  __int64 v37; // r5 OVERLAPPED
  int v38; // r4 OVERLAPPED
  unsigned int *v39; // r10
  _DWORD *v40; // r11
  int v41; // r10
  unsigned int *v42; // r11
  unsigned int v43; // r9
  unsigned int *v44; // r11
  unsigned int v45; // r9
  unsigned int *v46; // [sp+50h] [-D0h]
  unsigned int v47; // [sp+58h] [-C8h] BYREF
  unsigned int v48; // [sp+5Ch] [-C4h] BYREF
  idStr v49[6]; // [sp+60h] [-C0h] BYREF

  fhData = rootFh->fhData;
  v11 = 0;
  v12 = "<list files>";
  while ( 1 )
  {
    v13 = this->nextRpcIdx + 1;
    this->nextRpcIdx = v13;
    idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v13, prog: 0x186A3u, version: 4u, proc: 1u);
    v14 = v12;
    v15 = 0;
    do
    {
      ++v14;
      ++v15;
    }
    while ( *v14 != 0 );
    idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: v12, len: v15);
    *buf->cur = 0;
    v16 = buf->cur + 1;
    buf->cur = v16;
    v17 = v16;
    *v16 = 0;
    v18 = buf->cur + 1;
    buf->cur = v18;
    *v18 = 22;
    ++buf->cur;
    v46 = v17;
    idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fhData, len: rootFh->fhSize);
    v19 = idNfs4Client::SubOpLookUpChainWrite(this, buf, path, last: nullptr);
    *buf->cur = 26;
    v20 = buf->cur + 1;
    buf->cur = v20;
    *(_QWORD *)v20 = v11;
    v21 = buf->cur + 2;
    buf->cur = v21;
    *(_QWORD *)v21 = *(__int64 *)((char *)&v11 + 4);
    v22 = buf->cur + 2;
    buf->cur = v22;
    *v22 = this->serverAttr.maxReadSize;
    v23 = buf->cur + 1;
    buf->cur = v23;
    *v23 = this->serverAttr.maxReadSize;
    v24 = buf->cur + 1;
    buf->cur = v24;
    *v24 = 1;
    v25 = buf->cur + 1;
    buf->cur = v25;
    *v25 = 2;
    ++buf->cur;
    *v46 = v19 + 2;
    if ( idNfs4Client::RPCSendRecv(this, buf, opName: "OpListFiles", idx: v13, numOps: &v48, replyCompStatus: &v47) == 1 )
      return NFS_ERR_CON;
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x16u);
    if ( result != NFS_OK )
      return result;
    v27 = 0;
    if ( v19 > 0 )
      break;
LABEL_9:
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0x1Au);
    if ( result != NFS_OK )
      return result;
    v28 = false;
    if ( *extension == 47 )
      v28 = extension[1] == 0;
    cur = buf->cur;
    *(__int64 *)((char *)&v11 + 4) = *(_QWORD *)cur;
    buf->cur = cur + 2;
    v30 = cur[2];
    buf->cur = cur + 3;
    if ( v30 != 0 )
    {
      while ( 1 )
      {
        if ( this->rpcCon.con.rest != 0
          && (((char *)buf->end - (char *)buf->cur) & 0xFFFFFFFC) < 0x128
          && (unsigned __int8)idRpc::RpcIOBuffer::ReadRestFromCon(this: buf, con: &this->rpcCon.con) == 0 )
        {
          return NFS_ERR_CON;
        }
        v31 = buf->cur;
        v11 = *(_QWORD *)v31;
        buf->cur = v31 + 2;
        idRpc::RpcIOBuffer::StrRead(this: (idRpc::RpcIOBuffer *)v49, result: (idStr *)buf);
        v34 = buf->cur;
        v35 = v34 + 1;
        v36 = *v34;
        buf->cur = v34 + 1;
        if ( v36 == 1 )
        {
          HIDWORD(v37) = __ROL4__(*v35, 32);
          buf->cur = v34 + 2;
        }
        else if ( v36 == 2 )
        {
          *(__int64 *)((char *)&v37 + 4) = *(_QWORD *)v35;
          buf->cur = v34 + 3;
        }
        else
        {
          idLib::Warning(fmt: "NFS: Unsupported attrib mask size %d from server");
          v38 = 0;
        }
        v39 = buf->cur;
        v40 = v39 + 1;
        HIDWORD(v33) = *v39;
        buf->cur = v39 + 1;
        if ( *(__int64 *)((char *)&v33 + 4) != 0x200000004LL )
        {
          idLib::Warning(fmt: "NFS READDIR getattr attrib or attrib size missmatch: attr: %llu, size: %u", v33, v32);
          idStr::FreeData(this: v49);
          return NFS_ERR_OTHER;
        }
        v41 = *v40;
        buf->cur = v40 + 1;
        if ( !v28 )
          break;
        if ( v41 == 2 )
          goto LABEL_28;
        if ( !v28 )
          break;
LABEL_29:
        idStr::FreeData(this: v49);
        v42 = buf->cur;
        v43 = *v42;
        buf->cur = v42 + 1;
        if ( v43 == 0 )
          goto LABEL_30;
      }
      if ( v41 != 1 || *extension != 0 && !idStr::CheckExtension(name: v49[0].data, ext: extension) )
        goto LABEL_29;
LABEL_28:
      idList<idStr,5>::Append(this: list, obj: v49);
      goto LABEL_29;
    }
LABEL_30:
    v44 = buf->cur;
    v45 = *v44;
    buf->cur = v44 + 1;
    if ( v45 != 0 )
      return NFS_OK;
  }
  while ( 1 )
  {
    result = idNfs4Client::RPCCompSubHeaderRead(this, buf, op: 0xFu);
    if ( result != NFS_OK )
      return result;
    if ( ++v27 >= v19 )
      goto LABEL_9;
  }
}


// ========================================================================
// __unwind$124011
// EA  : 0x82F18210
// RVA : 0x00F18210
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_124011()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ?ListFiles@idNfs4Client@@UAA_NPBD0PAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F18240
// RVA : 0x00F18240
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs4Client::ListFiles(
        idNfs4Client *this,
        const char *path,
        const char *extension,
        idList<idStr,5> *list)
{
  idSysMutex *p_mutex; // r29

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( idNfs4Client::OpListFiles(this, buf: &this->ioBuffer, rootFh: &this->rootFh, path, extension, list) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$124454_0
// EA  : 0x82F182BC
// RVA : 0x00F182BC
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_124454_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?OpGetExports@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F182F0
// RVA : 0x00F182F0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::OpGetExports(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idList<idStr,5> *list)
{
  idNfsClient::NfsErr result; // r3
  unsigned int *cur; // r11
  unsigned int v8; // r9
  unsigned int *v9; // r11
  unsigned int v10; // r9
  unsigned int *v11; // r11
  unsigned int v12; // r9
  unsigned int *v13; // r11
  unsigned int v14; // r9
  unsigned int v15; // [sp+50h] [-60h]
  idStr v16[2]; // [sp+60h] [-50h] BYREF

  v15 = this->nextMntIdx + 1;
  this->nextMntIdx = v15;
  idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v15, prog: 0x186A5u, version: 3u, proc: 5u);
  result = idNfs3Client::MntSendRecv(this, buf, opName: "OpMount", idx: v15);
  if ( result == NFS_OK )
  {
    cur = buf->cur;
    v8 = *cur;
    buf->cur = cur + 1;
    if ( v8 != 0 )
    {
      while ( this->nfsCon.con.rest == 0
           || (((char *)buf->end - (char *)buf->cur) & 0xFFFFFFFC) >= 0x160
           || (unsigned __int8)idRpc::RpcIOBuffer::ReadRestFromCon(this: buf, con: &this->nfsCon.con) != 0 )
      {
        idRpc::RpcIOBuffer::StrRead(this: (idRpc::RpcIOBuffer *)v16, result: (idStr *)buf);
        idList<idStr,5>::Append(this: list, obj: v16);
        v9 = buf->cur;
        v10 = *v9;
        buf->cur = v9 + 1;
        if ( v10 != 0 )
        {
          do
          {
            if ( this->nfsCon.con.rest != 0 && (((char *)buf->end - (char *)buf->cur) & 0xFFFFFFFC) < 0x160 )
            {
              if ( (unsigned __int8)idRpc::RpcIOBuffer::ReadRestFromCon(this: buf, con: &this->nfsCon.con) == 0 )
              {
                idStr::FreeData(this: v16);
                return NFS_ERR_CON;
              }
              buf->cur += ((*buf->cur + 3) >> 2) + 1;
            }
            v11 = buf->cur;
            v12 = *v11;
            buf->cur = v11 + 1;
          }
          while ( v12 != 0 );
        }
        idStr::FreeData(this: v16);
        v13 = buf->cur;
        v14 = *v13;
        buf->cur = v13 + 1;
        if ( v14 == 0 )
          return NFS_OK;
      }
      return NFS_ERR_CON;
    }
    else
    {
      return NFS_OK;
    }
  }
  return result;
}


// ========================================================================
// __unwind$124500
// EA  : 0x82F1848C
// RVA : 0x00F1848C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_124500()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?OpListFiles@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfs3Fh@1@PBDPAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F184C0
// RVA : 0x00F184C0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::OpListFiles(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::Nfs3Fh *fh,
        const char *extension,
        idList<idStr,5> *list)
{
  __int64 v5; // r28
  bool v11; // r19
  __int64 v12; // r24
  unsigned int v13; // r29
  unsigned int *v14; // r11
  unsigned int *v15; // r11
  unsigned int *v16; // r11
  idNfsClient::NfsErr result; // r3
  unsigned int *cur; // r11
  unsigned int *v19; // r10
  unsigned int v20; // r11
  unsigned int *v21; // r10
  unsigned int v22; // r8
  unsigned int *v23; // r4
  unsigned int *end; // r11
  unsigned int v25; // r27
  unsigned int rest; // r29
  int Blocking; // r4
  char v28; // r11
  char v29; // r10
  unsigned int *v30; // r9
  _DWORD *v31; // r11
  unsigned int v32; // r10
  int v33; // r9
  unsigned int *v34; // r10
  unsigned int *v35; // r11
  unsigned int v36; // r10
  unsigned int *v37; // r11
  unsigned int v38; // r9
  unsigned int *v39; // r11
  unsigned int v40; // r9
  unsigned int v41; // [sp+54h] [-ACh] BYREF
  idStr v42[5]; // [sp+60h] [-A0h] BYREF

  v11 = false;
  if ( *extension == 47 )
    v11 = extension[1] == 0;
  LODWORD(v5) = 0;
  LODWORD(v12) = 0;
  HIDWORD(v12) = "OpGetAttr";
  do
  {
    v13 = this->nextNfsIdx + 1;
    this->nextNfsIdx = v13;
    idRpc::RPCWriteRPCCallHeader(buf, rpcIdx: v13, prog: 0x186A3u, version: 3u, proc: 0x11u);
    idRpc::RpcIOBuffer::OpaqueWrite(this: buf, data: fh->fhData, len: fh->fhSize);
    *(_QWORD *)buf->cur = v5;
    v14 = buf->cur + 2;
    buf->cur = v14;
    *(_QWORD *)v14 = v12;
    v15 = buf->cur + 2;
    buf->cur = v15;
    *v15 = this->serverAttr.maxReadSize;
    v16 = buf->cur + 1;
    buf->cur = v16;
    *v16 = this->serverAttr.maxReadSize;
    ++buf->cur;
    result = idNfs3Client::NfsSendRecv(this, buf, opName: (const char *)HIDWORD(v12), idx: v13, replyStatus: &v41);
    if ( result != NFS_OK )
      return result;
    cur = buf->cur;
    v19 = cur + 1;
    v20 = *cur;
    buf->cur = v19;
    if ( v20 != 0 )
      buf->cur = v19 + 21;
    v21 = buf->cur;
    v12 = *(_QWORD *)v21;
    buf->cur = v21 + 2;
    v22 = v21[2];
    buf->cur = v21 + 3;
    if ( v22 != 0 )
    {
      while ( 1 )
      {
        if ( this->nfsCon.con.rest != 0 )
        {
          v23 = buf->cur;
          end = buf->end;
          v25 = ((char *)end - (char *)v23) & 0xFFFFFFFC;
          if ( v25 < 0x1BC )
            break;
        }
LABEL_23:
        buf->cur += 2;
        idRpc::RpcIOBuffer::StrRead(this: (idRpc::RpcIOBuffer *)v42, result: (idStr *)buf);
        v30 = buf->cur;
        v31 = v30 + 3;
        v5 = *(_QWORD *)v30;
        buf->cur = v30 + 2;
        v32 = v30[2];
        buf->cur = v30 + 3;
        if ( v32 != 0 )
        {
          v33 = *v31;
          buf->cur = v31 + 21;
          if ( !v11 )
            goto LABEL_40;
          if ( v33 == 2 )
            goto LABEL_30;
          if ( !v11 )
          {
LABEL_40:
            if ( v33 == 1 && (*extension == 0 || idStr::CheckExtension(name: v42[0].data, ext: extension)) )
LABEL_30:
              idList<idStr,5>::Append(this: list, obj: v42);
          }
        }
        v34 = buf->cur;
        v35 = v34 + 1;
        v36 = *v34;
        buf->cur = v35;
        if ( v36 != 0 )
          buf->cur = &v35[((*v35 + 3) >> 2) + 1];
        idStr::FreeData(this: v42);
        v37 = buf->cur;
        v38 = *v37;
        buf->cur = v37 + 1;
        if ( v38 == 0 )
          goto LABEL_34;
      }
      rest = this->nfsCon.con.rest;
      if ( rest != 0 )
      {
        if ( v25 != 0 )
          memmove(Dst: buf, Src: v23, Size: ((char *)end - (char *)v23) & 0xFFFFFFFC);
        buf->cur = (unsigned int *)buf;
        if ( 4096 - v25 < rest )
          rest = 4096 - v25;
        Blocking = idTCP::ReadBlocking(
                     this: &this->nfsCon.con.sock,
                     data: (char *)buf + (v25 & 0xFFFFFFFC),
                     size: rest,
                     timeoutMS: 5000);
        if ( Blocking == rest )
        {
          v28 = 1;
          this->nfsCon.con.rest -= rest;
        }
        else
        {
          idLib::Warning(fmt: "NFS: data read failed, %d of %d bytes received", Blocking, rest);
          idTCP::Close(this: &this->nfsCon.con.sock);
          v28 = 0;
        }
        if ( v28 == 0 )
        {
          v29 = 0;
          goto LABEL_22;
        }
        buf->end = (unsigned int *)((char *)buf->buffer + ((rest + v25 + 3) & 0xFFFFFFFC));
      }
      v29 = 1;
LABEL_22:
      if ( v29 == 0 )
        return NFS_ERR_CON;
      goto LABEL_23;
    }
LABEL_34:
    v39 = buf->cur;
    v40 = *v39;
    buf->cur = v39 + 1;
  }
  while ( v40 == 0 );
  return NFS_OK;
}


// ========================================================================
// $M124911
// EA  : 0x82F18814
// RVA : 0x00F18814
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _M124911()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// ??1idNfs3Client@@UAA@XZ
// EA  : 0x82F18A30
// RVA : 0x00F18A30
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idNfs3Client::~idNfs3Client(idNfs3Client *this)
{
  this->__vftable = (idNfs3Client_vtbl *)&idNfs3Client::`vftable';
  if ( this->connected )
    idNfs3Client::Dissconnect(this);
  idStaticList<idNfs3Client::Nfs3Mount,32>::~idStaticList<idNfs3Client::Nfs3Mount,32>(this: &this->mounts);
  idRpc::Connection::~Connection(this: &this->mntCon.con);
  idRpc::Connection::~Connection(this: &this->nfsCon.con);
  idStr::FreeData(this: &this->host);
  Sys_MutexDestroy(handle: &this->mutex.handle);
}


// ========================================================================
// __unwind$124992
// EA  : 0x82F18AAC
// RVA : 0x00F18AAC
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_124992()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$124993
// EA  : 0x82F18AD8
// RVA : 0x00F18AD8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_124993()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$124994
// EA  : 0x82F18B04
// RVA : 0x00F18B04
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_124994()
{
  int v0; // r12

  idRpc::~idRpc(this: (idRpc *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// __unwind$124995
// EA  : 0x82F18B30
// RVA : 0x00F18B30
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_124995()
{
  int v0; // r12

  idRpc::~idRpc(this: (idRpc *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// __unwind$124996
// EA  : 0x82F18B5C
// RVA : 0x00F18B5C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_124996()
{
  int v0; // r12

  idStaticList<idNfs3Client::Nfs3Mount,32>::~idStaticList<idNfs3Client::Nfs3Mount,32>(this: (idStaticList<idNfs3Client::Nfs3Mount,32> *)(*(_DWORD *)(v0 - 112 + 132) + 4296));
}


// ========================================================================
// ??0idNfs3Client@@QAA@XZ
// EA  : 0x82F18D18
// RVA : 0x00F18D18
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfs3Client *__fastcall idNfs3Client::idNfs3Client(idNfs3Client *this)
{
  unsigned __int64 v1; // r29

  this->__vftable = (idNfs3Client_vtbl *)&idNfs3Client::`vftable';
  Sys_MutexCreate(handle: &this->mutex.handle);
  LODWORD(v1) = 0;
  this->host.len = 0;
  this->host.allocedAndFlag = 20;
  this->host.data = this->host.baseBuffer;
  this->host.baseBuffer[0] = 0;
  this->RO = false;
  idRpc::Connection::Connection(this: &this->nfsCon.con);
  idRpc::Connection::Connection(this: &this->mntCon.con);
  this->connected = false;
  this->clientId.clientId = v1;
  this->clientId.verf = 0;
  this->clientId.seq = 0;
  this->clientId.nextOwner = 0;
  idStaticList<idNfs3Client::Nfs3Mount,32>::idStaticList<idNfs3Client::Nfs3Mount,32>(this: &this->mounts);
  return this;
}


// ========================================================================
// __unwind$125111
// EA  : 0x82F18DA8
// RVA : 0x00F18DA8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125111()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$125112
// EA  : 0x82F18DD4
// RVA : 0x00F18DD4
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125112()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$125113
// EA  : 0x82F18E00
// RVA : 0x00F18E00
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125113()
{
  int v0; // r12

  idRpc::~idRpc(this: (idRpc *)(*(_DWORD *)(v0 - 128 + 148) + 44));
}


// ========================================================================
// __unwind$125114
// EA  : 0x82F18E2C
// RVA : 0x00F18E2C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125114()
{
  int v0; // r12

  idRpc::~idRpc(this: (idRpc *)(*(_DWORD *)(v0 - 128 + 148) + 100));
}


// ========================================================================
// ??0idNfsSystem@@QAA@XZ
// EA  : 0x82F18EC0
// RVA : 0x00F18EC0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsSystem *__fastcall idNfsSystem::idNfsSystem(idNfsSystem *this)
{
  Sys_MutexCreate(handle: &this->mutex.handle);
  this->nfsClients.granularity = 0;
  this->nfsClients.listStatic = 0;
  this->nfsClients.memTag = 5;
  this->nfsClients.list = nullptr;
  this->nfsClients.size = 0;
  this->nfsClients.num = 0;
  return this;
}


// ========================================================================
// __unwind$125200
// EA  : 0x82F18F24
// RVA : 0x00F18F24
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125200()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: *(idSysMutex **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idNfsSystem@@QAA@XZ
// EA  : 0x82F18F58
// RVA : 0x00F18F58
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __fastcall idNfsSystem::~idNfsSystem(idNfsSystem *this)
{
  int v2; // r28
  int v3; // r29
  idNfsClient *nfsClient; // r4
  idNfsSystem::Client *list; // r27
  int size; // r29
  idNfsSystem::Client *v7; // r28
  idNfsSystem::Client *v8; // r27
  int v9; // r29
  idNfsSystem::Client *v10; // r28

  v2 = 0;
  if ( this->nfsClients.num > 0 )
  {
    v3 = 0;
    do
    {
      nfsClient = this->nfsClients.list[v3].nfsClient;
      if ( nfsClient != nullptr )
      {
        idMem::Free(this: &mem, ptr: nfsClient, align: ALIGN_16);
        this->nfsClients.list[v3].nfsClient = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->nfsClients.num );
  }
  if ( this->nfsClients.listStatic == 0 || this->nfsClients.listStatic == 2 )
  {
    list = this->nfsClients.list;
    if ( list != nullptr )
    {
      size = this->nfsClients.size;
      if ( size > 0 )
      {
        v7 = this->nfsClients.list;
        do
        {
          idStr::FreeData(this: &v7->desc);
          --size;
          ++v7;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->nfsClients.list = nullptr;
    this->nfsClients.size = 0;
  }
  this->nfsClients.num = 0;
  if ( this->nfsClients.listStatic == 0 || this->nfsClients.listStatic == 2 )
  {
    v8 = this->nfsClients.list;
    if ( v8 != nullptr )
    {
      v9 = this->nfsClients.size;
      if ( v9 > 0 )
      {
        v10 = this->nfsClients.list;
        do
        {
          idStr::FreeData(this: &v10->desc);
          --v9;
          ++v10;
        }
        while ( v9 != 0 );
      }
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    }
    this->nfsClients.list = nullptr;
    this->nfsClients.size = 0;
  }
  this->nfsClients.num = 0;
  Sys_MutexDestroy(handle: &this->mutex.handle);
}


// ========================================================================
// __unwind$125234
// EA  : 0x82F190A4
// RVA : 0x00F190A4
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125234()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: *(idSysMutex **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$125235
// EA  : 0x82F190CC
// RVA : 0x00F190CC
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125235()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                         + 4));
}


// ========================================================================
// ?InitMounts@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@XZ
// EA  : 0x82F19190
// RVA : 0x00F19190
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::InitMounts(idNfs3Client *this)
{
  int v2; // r11
  int v3; // r10
  idNfsClient::NfsErr Exports; // r30
  int v6; // r14
  idStr *list; // r28
  idStr *v8; // r27
  int allocedAndFlag; // r10
  int v10; // r11
  char *data; // r8
  int v12; // r11
  int v13; // r29
  int v14; // r30
  idNfs3Client::Nfs3Mount *v15; // r30
  int num; // r11
  int v18; // r10
  idNfs3Client::Nfs3Mount *v19; // r9
  size_t len; // r28
  int v21; // r4
  unsigned int v22; // r11
  int v23; // r11
  bool v24; // zf
  idNfsClient::NfsErr v25; // r3
  idNfsClient::NfsErr v26; // r29
  const char *v27; // r5
  int size; // r30
  idStr *v29; // r29
  int v30; // r30
  idStr *v31; // r29
  idList<idStr,5> v32[11]; // [sp+60h] [-B0h] BYREF

  v2 = 0;
  if ( this->mounts.num > 0 )
  {
    v3 = 0;
    do
    {
      ++v2;
      this->mounts.list[v3++].status = NFS_ERR_NOENT;
    }
    while ( v2 < this->mounts.num );
  }
  *(_WORD *)&v32[0].memTag = 1280;
  memset(v32, 0, 14);
  Exports = idNfs3Client::OpGetExports(this, buf: &this->ioBuffer, list: v32);
  if ( Exports != NFS_OK )
  {
    if ( (v32[0].listStatic == 0 || v32[0].listStatic == 2) && v32[0].list != nullptr )
      idListArrayDelete<idStr>(ptr: v32[0].list, num: v32[0].size);
    return Exports;
  }
  v6 = 0;
  list = v32[0].list;
  if ( v32[0].num <= 0 )
  {
LABEL_54:
    if ( (v32[0].listStatic == 0 || v32[0].listStatic == 2) && list != nullptr )
    {
      size = v32[0].size;
      if ( v32[0].size > 0 )
      {
        v29 = list;
        do
        {
          idStr::FreeData(this: v29);
          --size;
          ++v29;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    return 0;
  }
  v8 = v32[0].list;
  while ( 1 )
  {
    if ( v8->data[v8->len - 1] != 47 )
    {
      allocedAndFlag = v8->allocedAndFlag;
      v10 = v8->len + 2;
      if ( allocedAndFlag >= 0 )
      {
        if ( v10 > (allocedAndFlag & 0x7FFFFFFF) )
          idStr::ReAllocate(this: v8, amount: (v10 >> 1) + v10, keepold: true);
      }
      else if ( v10 > (allocedAndFlag & 0x7FFFFFFF)
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      v8->data[v8->len] = 47;
      data = v8->data;
      v12 = v8->len + 1;
      v8->len = v12;
      data[v12] = 0;
    }
    v13 = 0;
    if ( this->mounts.num > 0 )
    {
      v14 = 0;
      while ( idStr::Cmp(s1: this->mounts.list[v14].path.data, s2: v8->data) != 0 )
      {
        ++v13;
        ++v14;
        if ( v13 >= this->mounts.num )
          goto LABEL_26;
      }
      v15 = &this->mounts.list[v13];
      if ( v15 != nullptr )
        break;
    }
LABEL_26:
    if ( this->mounts.listStatic == 0 || this->mounts.num < this->mounts.size )
    {
      idList<idNfs3Client::Nfs3Mount,5>::PreAllocateWithGranularity(this: &this->mounts, newSize: this->mounts.num + 1);
      num = this->mounts.num;
      v18 = this->mounts.size;
      v19 = this->mounts.list;
      if ( num >= v18 )
      {
        v15 = &v19[v18 - 1];
      }
      else
      {
        v15 = &v19[num];
        this->mounts.num = num + 1;
      }
      v15->status = NFS_ERR_NOENT;
      len = v8->len;
      v21 = v8->len + 1;
      v22 = v15->path.allocedAndFlag;
      v24 = v22 >> 31 == 0;
      v23 = v22 & 0x7FFFFFFF;
      if ( v24 )
      {
        if ( v21 > v23 )
          idStr::ReAllocate(this: &v15->path, amount: v21, keepold: false);
      }
      else if ( v21 > v23
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      memcpy(Dst: v15->path.data, Src: v8->data, Size: len);
      v15->path.data[len] = 0;
      v15->path.len = len;
      list = v32[0].list;
      break;
    }
    idLib::Warning(
      fmt: "idNfs3Client::InitMounts: more than %d mounts in total, can't add more, offending add: '%s'\n",
      this->mounts.num,
      v8->data);
LABEL_53:
    ++v6;
    ++v8;
    if ( v6 >= v32[0].num )
      goto LABEL_54;
  }
  v25 = idNfs3Client::OpMount(this, buf: &this->ioBuffer, rootFh: &v15->fh, mntPath: v15->path.data);
  v15->status = v25;
  v26 = v25;
  if ( (unsigned int)v25 > NFS_ERR_OTHER )
  {
    v27 = "unknown";
  }
  else
  {
    switch ( v25 )
    {
      case NFS_ERR_CON:
        v27 = "NFS_ERR_CON";
        break;
      case NFS_ERR_NOENT:
        v27 = "NFS_ERR_NOENT";
        break;
      case NFS_ERR_ACCESS:
        v27 = "NFS_ERR_ACCESS";
        break;
      default:
        if ( v25 != NFS_OK )
          v27 = "NFS_ERR_OTHER";
        else
          v27 = "NFS_OK";
        break;
    }
  }
  idLib::Printf(fmt: "exp[%d](%s): %s\n", v6, v27, v8->data);
  if ( v26 != NFS_ERR_CON )
    goto LABEL_53;
  if ( (v32[0].listStatic == 0 || v32[0].listStatic == 2) && list != nullptr )
  {
    v30 = v32[0].size;
    if ( v32[0].size > 0 )
    {
      v31 = list;
      do
      {
        idStr::FreeData(this: v31);
        --v30;
        ++v31;
      }
      while ( v30 != 0 );
    }
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
  return 1;
}


// ========================================================================
// __unwind$125447
// EA  : 0x82F1961C
// RVA : 0x00F1961C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125447()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 272 + 96));
}


// ========================================================================
// ?InternalConnect@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PBD1@Z
// EA  : 0x82F19648
// RVA : 0x00F19648
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::InternalConnect(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        const char *host,
        const char *path)
{
  unsigned __int64 v4; // r27
  idNfsClient::NfsErr inited; // r30
  unsigned __int64 v10; // r10
  unsigned int v11; // r3
  idNfs3Client::Nfs3Fh *p_fh; // r5
  int Mount; // r3
  int num; // r11
  int v16; // r10
  idNfs3Client::Nfs3Mount *list; // r9
  int v18; // r11
  idNfs3Client::Nfs3Fh *v19; // [sp+50h] [-40h] BYREF
  const char *v20; // [sp+54h] [-3Ch] BYREF

  LODWORD(v4) = 0;
  this->nextMntIdx = 0;
  this->nextNfsIdx = 0;
  if ( (unsigned __int8)idRpc::ConnectWithPortMap(this: &this->mntCon, buf, host, prog: 0x186A5u, version: 3u) == 0
    || (unsigned __int8)idRpc::ConnectWithPortMap(this: &this->nfsCon, buf, host, prog: 0x186A3u, version: 3u) == 0 )
  {
    inited = NFS_ERR_CON;
    goto LABEL_9;
  }
  this->clientId.clientId = v4;
  LODWORD(v10) = (Sys_CurrentSystemTime() >> 32) + LODWORD(this->clientId.clientId);
  this->clientId.clientId = v10;
  v11 = Sys_Microseconds() >> 32;
  this->clientId.nextOwner = 0;
  this->clientId.verf = v11;
  inited = idNfs3Client::InitMounts(this);
  if ( inited != NFS_OK )
    goto LABEL_9;
  p_fh = nullptr;
  v19 = nullptr;
  if ( path != nullptr )
  {
    Mount = idNfs3Client::FindMount(this, buf, path, resFh: &v19, resPath: &v20);
    p_fh = v19;
    inited = Mount;
LABEL_7:
    if ( inited != NFS_OK )
      goto LABEL_9;
  }
  else
  {
    num = this->mounts.num;
    if ( num == 0 )
    {
      inited = NFS_ERR_NOENT;
      goto LABEL_9;
    }
    v16 = 0;
    if ( num > 0 )
    {
      list = this->mounts.list;
      v18 = 0;
      while ( 1 )
      {
        inited = list[v18].status;
        if ( inited == NFS_OK )
          break;
        ++v16;
        ++v18;
        if ( v16 >= this->mounts.num )
          goto LABEL_7;
      }
      p_fh = &list[v16].fh;
    }
  }
  inited = idNfs3Client::OpGetServerAttr(this, buf, rootFh: p_fh, attr: &this->serverAttr);
  if ( inited != NFS_OK )
  {
LABEL_9:
    idTCP::Close(this: &this->mntCon.con.sock);
    idTCP::Close(this: &this->nfsCon.con.sock);
    this->connected = false;
    return inited;
  }
  idLib::Printf(
    fmt: "max read: %dkiB, max write: %dkiB\n",
    this->serverAttr.maxReadSize >> 10,
    this->serverAttr.maxWriteSize >> 10);
  this->connected = true;
  return NFS_OK;
}


// ========================================================================
// ?GetClient@idNfsSystem@@QAAPAVidNfsClient@@PBDPAPBD@Z
// EA  : 0x82F19808
// RVA : 0x00F19808
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient *__fastcall idNfsSystem::GetClient(idNfsSystem *this, const char *path, const char **resPath)
{
  int v6; // r28
  int v7; // r29
  idNfsSystem::Client *v8; // r30
  int v9; // r3
  void *nfsClient; // r30
  int v12; // r30
  int v13; // r28
  idNfs3Client *v14; // r3
  idNfs3Client *v15; // r3
  int v16; // r6
  idNfs3Client *v17; // r3
  idNfs3Client *v18; // r3
  idNfs4Client *v19; // r3
  idNfs4Client *v20; // r3
  idNfs4Client *v21; // r3
  idNfs4Client *v22; // r3
  idNfsSystem::Client *v23; // r3
  idStr *p_desc; // r24
  size_t len; // r28
  int v26; // r11
  idStr v27; // [sp+60h] [-E0h] BYREF
  idStr v28; // [sp+80h] [-C0h] BYREF
  idStr v29; // [sp+A0h] [-A0h] BYREF
  idStr v30; // [sp+C0h] [-80h] BYREF
  idNfsSystem *v31; // [sp+E0h] [-60h]

  v31 = this;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  v6 = 0;
  if ( this->nfsClients.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &this->nfsClients.list[v7];
      if ( idStr::IcmpnPath(s1: v8->desc.data, s2: path, n: v8->desc.len) == 0 )
        goto _LN213_0;
      ++v6;
      ++v7;
    }
    while ( v6 < this->nfsClients.num );
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idStr::idStr(this: &v30, text: path);
  v9 = idStr::Find(str: v30.data, c: 64, start: 0, end: v30.len);
  v8 = (idNfsSystem::Client *)v9;
  if ( v9 < 1 )
  {
    idLib::Error(fmt: "idNfsSystem::GetClient: malformed nfs path: %s", path);
_LN213_0:
    *resPath = &path[v8->desc.len];
    nfsClient = v8->nfsClient;
LABEL_8:
    Sys_MutexUnlock(handle: &this->mutex.handle);
    return (idNfsClient *)nfsClient;
  }
  v27.len = 0;
  v27.baseBuffer[0] = 0;
  v27.data = v27.baseBuffer;
  v27.allocedAndFlag = 20;
  idStr::CopyRange(this: &v27, text: v30.data, start: 0, end: v9);
  v12 = (int)&v8->desc.len + 1;
  v13 = idStr::Find(str: v30.data, c: 47, start: v12, end: v30.len);
  if ( v13 < 1 )
    idLib::Error(fmt: "idNfsSystem::GetClient: malformed nfs path: %s", path);
  v28.allocedAndFlag = 20;
  v28.len = 0;
  v28.data = v28.baseBuffer;
  v28.baseBuffer[0] = 0;
  idStr::CopyRange(this: &v28, text: v30.data, start: v12, end: v13);
  idLib::Printf(fmt: "proto: \"%s\", host; \"%s\"\n", v27.data, v28.data);
  if ( idStr::Icmp(s1: v27.data, s2: "3") != 0 )
  {
    if ( idStr::Icmp(s1: v27.data, s2: "3ro") != 0 )
    {
      if ( idStr::Icmp(s1: v27.data, s2: "4") != 0 )
      {
        if ( idStr::Icmp(s1: v27.data, s2: "4ro") != 0 )
        {
          idLib::Error(fmt: "idNfsSystem::GetClient: unsupported protocol: %s", v27.data);
          return _LN215_0();
        }
        v21 = (idNfs4Client *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x1158u,
                                tag: TAG_FILE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
        if ( v21 != nullptr )
          v22 = idNfs4Client::idNfs4Client(this: v21);
        else
          v22 = nullptr;
        nfsClient = v22;
        v16 = 1;
      }
      else
      {
        v19 = (idNfs4Client *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x1158u,
                                tag: TAG_FILE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
        if ( v19 != nullptr )
          v20 = idNfs4Client::idNfs4Client(this: v19);
        else
          v20 = nullptr;
        nfsClient = v20;
        v16 = 0;
      }
    }
    else
    {
      v17 = (idNfs3Client *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x1DE0u,
                              tag: TAG_FILE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      if ( v17 != nullptr )
        v18 = idNfs3Client::idNfs3Client(this: v17);
      else
        v18 = nullptr;
      nfsClient = v18;
      v16 = 1;
    }
  }
  else
  {
    v14 = (idNfs3Client *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x1DE0u,
                            tag: TAG_FILE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    if ( v14 != nullptr )
      v15 = idNfs3Client::idNfs3Client(this: v14);
    else
      v15 = nullptr;
    nfsClient = v15;
    v16 = 0;
  }
  if ( (*(unsigned __int8 (__fastcall **)(void *, char *, const char *, int))(*(_DWORD *)nfsClient + 4))(
         a1: nfsClient,
         a2: v28.data,
         a3: &path[v13],
         a4: v16) != 0 )
  {
    v23 = idList<idNfsSystem::Client,5>::Alloc(this: &this->nfsClients);
    v29.allocedAndFlag = 20;
    p_desc = &v23->desc;
    v29.data = v29.baseBuffer;
    v29.len = 0;
    v29.baseBuffer[0] = 0;
    idStr::CopyRange(this: &v29, text: path, start: 0, end: v13);
    len = v29.len;
    idStr::EnsureAlloced(this: p_desc, amount: v29.len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: p_desc->data, Src: v29.data, Size: len);
    p_desc->data[len] = 0;
    p_desc->len = len;
    idStr::FreeData(this: &v29);
    v26 = p_desc->len;
    p_desc[1].len = (int)nfsClient;
    *resPath = &path[v26];
    idStr::FreeData(this: &v28);
    idStr::FreeData(this: &v27);
    idStr::FreeData(this: &v30);
    idMem::PopHeap(this: &mem);
    goto LABEL_8;
  }
  idMem::Free(this: &mem, ptr: nfsClient, align: ALIGN_16);
  idLib::Warning(fmt: "could not connect to nfs %s on system %s (path: %s)", v27.data, v28.data, path);
  idStr::FreeData(this: &v28);
  idStr::FreeData(this: &v27);
  idStr::FreeData(this: &v30);
  idMem::PopHeap(this: &mem);
  Sys_MutexUnlock(handle: &this->mutex.handle);
  return nullptr;
}


// ========================================================================
// $LN215_0
// EA  : 0x82F19C40
// RVA : 0x00F19C40
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _LN215_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 320 + 224));
}


// ========================================================================
// __unwind$125928
// EA  : 0x82F19C68
// RVA : 0x00F19C68
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125928()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 320 + 228));
}


// ========================================================================
// __unwind$125929
// EA  : 0x82F19C90
// RVA : 0x00F19C90
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125929()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 192));
}


// ========================================================================
// __unwind$125930
// EA  : 0x82F19CB8
// RVA : 0x00F19CB8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125930()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$125931
// EA  : 0x82F19CE0
// RVA : 0x00F19CE0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125931()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$125932
// EA  : 0x82F19D08
// RVA : 0x00F19D08
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125932()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 320 + 80), tag: TAG_FILE);
}


// ========================================================================
// __unwind$125933
// EA  : 0x82F19D34
// RVA : 0x00F19D34
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125933()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 320 + 80), tag: TAG_FILE);
}


// ========================================================================
// __unwind$125934
// EA  : 0x82F19D60
// RVA : 0x00F19D60
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125934()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 320 + 80), tag: TAG_FILE);
}


// ========================================================================
// __unwind$125935
// EA  : 0x82F19D8C
// RVA : 0x00F19D8C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125935()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 320 + 80), tag: TAG_FILE);
}


// ========================================================================
// __unwind$125936
// EA  : 0x82F19DB8
// RVA : 0x00F19DB8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_125936()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// ?CreateOsPath@idFile_Nfs@@SA_NPBD@Z
// EA  : 0x82F19DE8
// RVA : 0x00F19DE8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idFile_Nfs::CreateOsPath(const char *path)
{
  const char *v1; // r30
  idNfsClient *Client; // r28
  int len; // r25
  int v5; // r27
  int v6; // r30
  char *data; // r10
  char v8; // r29
  int v9; // r3
  const char *v10; // [sp+50h] [-190h] BYREF
  idStr v11; // [sp+60h] [-180h] BYREF
  idStrStatic<256> v12; // [sp+80h] [-160h] BYREF

  v1 = path;
  if ( idStr::Icmpn(s1: path, s2: "nfs:", n: 4) == 0 )
    v1 += 4;
  idStrStatic<256>::idStrStatic<256>(this: &v12, text: v1);
  idStr::CollapsePath(this: &v12);
  idStr::ToLower(this: &v12);
  idStr::BackSlashesToSlashes(this: &v12);
  Client = idNfsSystem::GetClient(this: &idFile_Nfs::nfsSys, path: v12.data, resPath: &v10);
  if ( Client != nullptr )
  {
    idStr::idStr(this: &v11, text: v10);
    len = v11.len;
    v5 = 0;
    v6 = 1;
    if ( v11.len > 1 )
    {
      data = v11.data;
      do
      {
        v8 = data[v6];
        if ( v8 == 92 || v8 == 47 )
        {
          data[v6] = 0;
          v9 = ((int (__fastcall *)(idNfsClient *, char *))Client->CreateDir)(a1: Client, a2: v11.data);
          v11.data[v6] = v8;
          v5 = v9;
          data = v11.data;
        }
        ++v6;
      }
      while ( v6 < len );
    }
    idStr::FreeData(this: &v11);
    idStr::FreeData(this: &v12);
    return v5;
  }
  else
  {
    idStr::FreeData(this: &v12);
    return 0;
  }
}


// ========================================================================
// __unwind$126264
// EA  : 0x82F19F04
// RVA : 0x00F19F04
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126264()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 128));
}


// ========================================================================
// __unwind$126265
// EA  : 0x82F19F2C
// RVA : 0x00F19F2C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126265()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 96));
}


// ========================================================================
// ?ListFiles@idFile_Nfs@@SAHPBD0AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F19F60
// RVA : 0x00F19F60
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idFile_Nfs::ListFiles(const char *path, const char *extension, idList<idStr,5> *list)
{
  idNfsClient *Client; // r3
  int num; // r30
  const char *v9; // [sp+50h] [-160h] BYREF
  idStrStatic<256> v10; // [sp+60h] [-150h] BYREF

  if ( list->listStatic == 0 || list->listStatic == 2 )
  {
    if ( list->list != nullptr )
      idListArrayDelete<idStr>(ptr: list->list, num: list->size);
    list->list = nullptr;
    list->size = 0;
  }
  list->num = 0;
  if ( idStr::Icmpn(s1: path, s2: "nfs:", n: 4) == 0 )
    path += 4;
  idStrStatic<256>::idStrStatic<256>(this: &v10, text: path);
  idStr::CollapsePath(this: &v10);
  idStr::ToLower(this: &v10);
  idStr::BackSlashesToSlashes(this: &v10);
  Client = idNfsSystem::GetClient(this: &idFile_Nfs::nfsSys, path: v10.data, resPath: &v9);
  if ( Client != nullptr && Client->ListFiles(this: Client, a2: v9, a3: extension, a4: list) )
  {
    num = list->num;
    idStr::FreeData(this: &v10);
    return num;
  }
  else
  {
    idStr::FreeData(this: &v10);
    return 0;
  }
}


// ========================================================================
// __unwind$126342
// EA  : 0x82F1A074
// RVA : 0x00F1A074
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126342()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 96));
}


// ========================================================================
// ?RemoveFile@idFile_Nfs@@SA_NPBD@Z
// EA  : 0x82F1A0A8
// RVA : 0x00F1A0A8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idFile_Nfs::RemoveFile(const char *path)
{
  const char *v1; // r30
  idNfsClient *Client; // r3
  int v4; // r30
  const char *v5; // [sp+50h] [-150h] BYREF
  idStrStatic<256> v6; // [sp+60h] [-140h] BYREF

  v1 = path;
  if ( idStr::Icmpn(s1: path, s2: "nfs:", n: 4) == 0 )
    v1 += 4;
  idStrStatic<256>::idStrStatic<256>(this: &v6, text: v1);
  idStr::CollapsePath(this: &v6);
  idStr::ToLower(this: &v6);
  idStr::BackSlashesToSlashes(this: &v6);
  Client = idNfsSystem::GetClient(this: &idFile_Nfs::nfsSys, path: v6.data, resPath: &v5);
  if ( Client != nullptr )
  {
    v4 = ((int (__fastcall *)(idNfsClient *, const char *))Client->RemoveFileDir)(a1: Client, a2: v5);
    idStr::FreeData(this: &v6);
    return v4;
  }
  else
  {
    idStr::FreeData(this: &v6);
    return 0;
  }
}


// ========================================================================
// __unwind$126447
// EA  : 0x82F1A16C
// RVA : 0x00F1A16C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126447()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 96));
}


// ========================================================================
// ?TryConnectionRecovery@idNfs3Client@@AAA_NPAVRpcIOBuffer@idRpc@@H_N@Z
// EA  : 0x82F1A1A0
// RVA : 0x00F1A1A0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::TryConnectionRecovery(idNfs3Client *this, idRpc::RpcIOBuffer *buf, int tryNum, bool wait)
{
  idNfsClient::NfsErr v8; // r3
  const char *v9; // r3
  int v10; // r6
  const char *v11; // r5
  const char *v12; // r3
  const char *v13; // r10
  int v14; // r6

  if ( tryNum > fs_nfsRetries.valueInteger && fs_nfsRetries.valueInteger != -1 )
  {
    idLib::Warning(
      fmt: "idNfs3Client::TryConnectionRecovery: recovery unsuccessfull on host %s, giving upp on try %d",
      this->host.data,
      tryNum);
    return 0;
  }
  if ( wait )
    mgthread_sleep(ms: (int)(float)(fs_nfsRetryWait.valueFloat * (float)1000.0));
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idLib::Printf(fmt: "idNfs3Client::TryConnectionRecovery: recovery try %d on host %s...\n", tryNum, this->host.data);
  this->Dissconnect(this);
  v8 = idNfs3Client::InternalConnect(this, buf, host: this->host.data, path: nullptr);
  if ( v8 == NFS_ERR_CON )
  {
    v9 = idNfsClient::NfsErrToStr(this, err: 1u);
    idLib::Warning(
      fmt: "idNfs3Client::TryConnectionRecovery: recovery try %d on host %s failed with %d (%s)",
      tryNum,
      v11,
      v10,
      v9);
  }
  else
  {
    if ( v8 != NFS_OK )
    {
      v12 = idNfsClient::NfsErrToStr(this, err: v8);
      idLib::Warning(
        fmt: "idNfs3Client::TryConnectionRecovery: recovery unsuccessfull on host %s, giving upp on try %d, failed with %d (%s)",
        v13,
        tryNum,
        v14,
        v12);
      idMem::PopHeap(this: &mem);
      return 0;
    }
    idLib::Printf(fmt: "idNfs3Client::TryConnectionRecovery: recovery host %s successfull\n", this->host.data);
  }
  idMem::PopHeap(this: &mem);
  return 1;
}


// ========================================================================
// __unwind$126489
// EA  : 0x82F1A30C
// RVA : 0x00F1A30C
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126489()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 144 + 88));
}


// ========================================================================
// ?ManagedOpLookUp@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsClientId@1@PAVNfs3Fh@1@PBV71@PBDPAVNfsFileAttr@3@@Z
// EA  : 0x82F1A338
// RVA : 0x00F1A338
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::ManagedOpLookUp(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::NfsClientId *clientId,
        idNfs3Client::Nfs3Fh *dst,
        const idNfs3Client::Nfs3Fh *src,
        const char *path,
        idNfsClient::NfsFileAttr *attrAtOpen,
        idNfsClient::NfsFileAttr *a8)
{
  int v14; // r23
  idNfsClient::NfsErr v15; // r29

  v14 = 0;
  do
  {
    v15 = idNfs3Client::OpLookUp(
            this,
            buf,
            clientId,
            src: __PAIR64__((unsigned int)src, (unsigned int)path),
            path: (const char *)attrAtOpen,
            attrAtOpen: a8);
    if ( v15 != NFS_ERR_CON )
      break;
    ++v14;
  }
  while ( (unsigned __int8)idNfs3Client::TryConnectionRecovery(this, buf, tryNum: v14, wait: true) != 0 );
  return v15;
}


// ========================================================================
// ?ManagedOpRead@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfs3Fh@1@_KIPAXAA_NAAI@Z
// EA  : 0x82F1A3C0
// RVA : 0x00F1A3C0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::ManagedOpRead(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::Nfs3Fh *fh,
        int a4,
        unsigned __int64 offset,
        bool *count,
        size_t *buffer,
        bool *eof,
        unsigned int *resCount)
{
  unsigned int v13; // r26
  unsigned int v14; // r25
  int v17; // r22
  int v18; // r31
  bool *v20; // [sp+8h] [-A8h]
  unsigned int *v21; // [sp+Ch] [-A4h]

  v13 = HIDWORD(offset);
  v14 = offset;
  v17 = 0;
  do
  {
    v18 = idNfs3Client::OpRead(this, buf, fh, a4, offset: __PAIR64__(v13, v14), count, buffer, eof: v20, resCount: v21);
    if ( v18 != 1 )
      break;
    ++v17;
  }
  while ( (unsigned __int8)idNfs3Client::TryConnectionRecovery(this, buf, tryNum: v17, wait: true) != 0 );
  return v18;
}


// ========================================================================
// ?ManagedOpGetAttr@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfs3Fh@1@PAVNfsFileAttr@3@@Z
// EA  : 0x82F1A450
// RVA : 0x00F1A450
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::ManagedOpGetAttr(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::Nfs3Fh *fh,
        idNfsClient::NfsFileAttr *attr)
{
  int v8; // r28
  idNfsClient::NfsErr v9; // r29

  v8 = 0;
  do
  {
    v9 = idNfs3Client::OpGetAttr(this, buf, fh, attr);
    if ( v9 != NFS_ERR_CON )
      break;
    ++v8;
  }
  while ( (unsigned __int8)idNfs3Client::TryConnectionRecovery(this, buf, tryNum: v8, wait: true) != 0 );
  return v9;
}


// ========================================================================
// ?ManagedOpListFiles@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfs3Fh@1@PBDPAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F1A4C0
// RVA : 0x00F1A4C0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::ManagedOpListFiles(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::Nfs3Fh *fh,
        const char *extension,
        idList<idStr,5> *list)
{
  int v10; // r28
  idNfsClient::NfsErr v11; // r29

  v10 = 0;
  do
  {
    v11 = idNfs3Client::OpListFiles(this, buf, fh, extension, list);
    if ( v11 != NFS_ERR_CON )
      break;
    ++v10;
  }
  while ( (unsigned __int8)idNfs3Client::TryConnectionRecovery(this, buf, tryNum: v10, wait: true) != 0 );
  return v11;
}


// ========================================================================
// ?LookUpPath@idNfs3Client@@AAA?AW4NfsErr@idNfsClient@@PAVRpcIOBuffer@idRpc@@PAVNfsClientId@1@PAVNfs3Fh@1@PBV71@PBDPAVNfsFileAttr@3@PAPBD@Z
// EA  : 0x82F1A538
// RVA : 0x00F1A538
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

idNfsClient::NfsErr __fastcall idNfs3Client::LookUpPath(
        idNfs3Client *this,
        idRpc::RpcIOBuffer *buf,
        idNfs3Client::NfsClientId *clientId,
        idNfs3Client::Nfs3Fh *dst,
        const idNfs3Client::Nfs3Fh *src,
        char *path,
        idNfsClient::NfsFileAttr *attrAtOpen,
        char **last)
{
  char *v15; // r25
  idNfsClient::NfsFileAttr *v16; // r10
  char v17; // r22
  int v18; // r26
  idNfsClient::NfsErr v19; // r31
  idNfsClient::NfsErr result; // r3

  *dst = *src;
  while ( 1 )
  {
    v15 = strchr(Str: path, Val: 47);
    if ( v15 == nullptr )
    {
      v15 = strchr(Str: path, Val: 92);
      if ( v15 == nullptr )
        break;
    }
    if ( v15 != path )
    {
      v17 = *v15;
      v18 = 0;
      *v15 = 0;
      do
      {
        v19 = idNfs3Client::OpLookUp(
                this,
                buf,
                clientId,
                src: __PAIR64__((unsigned int)dst, (unsigned int)path),
                path: (const char *)attrAtOpen,
                attrAtOpen: v16);
        if ( v19 != NFS_ERR_CON )
          break;
        ++v18;
      }
      while ( (unsigned __int8)idNfs3Client::TryConnectionRecovery(this, buf, tryNum: v18, wait: true) != 0 );
      *v15 = v17;
      if ( v19 != NFS_OK )
        return v19;
    }
    path = v15 + 1;
  }
  if ( *path == 0 )
    return NFS_OK;
  if ( last != nullptr )
  {
    *last = path;
    return NFS_OK;
  }
  result = idNfs3Client::ManagedOpLookUp(this, buf, clientId, dst, src: dst, path, attrAtOpen, a8: v16);
  if ( result == NFS_OK )
    return NFS_OK;
  return result;
}


// ========================================================================
// ?Open@idNfs3Client@@UAA_NPAVNfsFh@idNfsClient@@PBDW4fsMode_t@@_N3PAVNfsFileAttr@3@@Z
// EA  : 0x82F1A688
// RVA : 0x00F1A688
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::Open(
        idNfs3Client *this,
        idNfs3Client::Nfs3Fh *fh,
        const char *path,
        fsMode_t mode,
        bool create,
        bool trunc,
        idNfsClient::NfsFileAttr *attrAtOpen)
{
  idSysMutex *p_mutex; // r25
  idNfsClient::NfsFileAttr *v14; // r10
  char *v15; // [sp+50h] [-50h] BYREF
  idNfs3Client::Nfs3Fh *v16[19]; // [sp+54h] [-4Ch] BYREF

  p_mutex = &this->mutex;
  v16[1] = (idNfs3Client::Nfs3Fh *)&this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( create )
  {
    idLib::Warning(fmt: "idNfs3Client::Open: create file not implemented (%s)", path);
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else if ( idNfs3Client::FindMount(this, buf: &this->ioBuffer, path, resFh: v16, resPath: (const char **)&v15) != 0 )
  {
    idLib::Warning(fmt: "idNfs3Client::Open: could not find export for path %s", path);
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else if ( idNfs3Client::LookUpPath(
              this,
              buf: &this->ioBuffer,
              clientId: &this->clientId,
              dst: fh,
              src: v16[0],
              path: v15,
              attrAtOpen,
              last: &v15) != NFS_OK
         || idNfs3Client::ManagedOpLookUp(
              this,
              buf: &this->ioBuffer,
              clientId: &this->clientId,
              dst: fh,
              src: fh,
              path: v15,
              attrAtOpen,
              a8: v14) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$126625
// EA  : 0x82F1A7BC
// RVA : 0x00F1A7BC
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126625()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 160 + 88));
}


// ========================================================================
// ?Read@idNfs3Client@@UAAIPAVNfsFh@idNfsClient@@_JIPAX@Z
// EA  : 0x82F1A7F0
// RVA : 0x00F1A7F0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

unsigned int __fastcall idNfs3Client::Read(
        idNfs3Client *this,
        idNfs3Client::Nfs3Fh *fh,
        __int64 offset,
        unsigned int len,
        void *buffer)
{
  idSysMutex *p_mutex; // r23
  int v8; // r26
  unsigned int v9; // r28
  unsigned int v11; // r30
  unsigned __int64 v12; // r8
  bool *v14; // [sp+8h] [-A8h]
  unsigned int *v15; // [sp+Ch] [-A4h]
  bool v16; // [sp+50h] [-60h] BYREF
  size_t v17[23]; // [sp+54h] [-5Ch] BYREF

  p_mutex = &this->mutex;
  v17[1] = (size_t)&this->mutex;
  v8 = HIDWORD(offset);
  v9 = offset;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  v11 = 0;
  while ( v11 < v9 )
  {
    HIDWORD(v12) = v9 - v11;
    if ( v9 - v11 >= this->serverAttr.maxReadSize )
      HIDWORD(v12) = this->serverAttr.maxReadSize;
    LODWORD(v12) = v11 + len;
    if ( idNfs3Client::ManagedOpRead(
           this,
           buf: &this->ioBuffer,
           fh,
           a4: v11 + v8,
           offset: v12,
           count: &v16,
           buffer: v17,
           eof: v14,
           resCount: v15) != 0 )
      break;
    v11 += v17[0];
    if ( v16 )
      break;
  }
  Sys_MutexUnlock(handle: &p_mutex->handle);
  return v11;
}


// ========================================================================
// __unwind$126704
// EA  : 0x82F1A8A8
// RVA : 0x00F1A8A8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126704()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 88));
}


// ========================================================================
// ?GetAttr@idNfs3Client@@UAA_NPAVNfsFh@idNfsClient@@PAVNfsFileAttr@3@@Z
// EA  : 0x82F1A8D8
// RVA : 0x00F1A8D8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::GetAttr(idNfs3Client *this, idNfs3Client::Nfs3Fh *fh, idNfsClient::NfsFileAttr *attr)
{
  idSysMutex *p_mutex; // r29

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( idNfs3Client::ManagedOpGetAttr(this, buf: &this->ioBuffer, fh, attr) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$126754
// EA  : 0x82F1A948
// RVA : 0x00F1A948
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126754()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?ListFiles@idNfs3Client@@UAA_NPBD0PAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F1A978
// RVA : 0x00F1A978
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

int __fastcall idNfs3Client::ListFiles(
        idNfs3Client *this,
        const char *path,
        const char *extension,
        idList<idStr,5> *list)
{
  idSysMutex *p_mutex; // r27
  char *v10; // [sp+50h] [-C0h] BYREF
  idNfs3Client::Nfs3Fh *v11[3]; // [sp+54h] [-BCh] BYREF
  idNfsClient::NfsFileAttr v12; // [sp+60h] [-B0h] BYREF
  idNfs3Client::Nfs3Fh v13[2]; // [sp+80h] [-90h] BYREF

  p_mutex = &this->mutex;
  v11[1] = (idNfs3Client::Nfs3Fh *)&this->mutex;
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  if ( idNfs3Client::FindMount(this, buf: &this->ioBuffer, path, resFh: v11, resPath: (const char **)&v10) != 0 )
  {
    idLib::Warning(fmt: "idNfs3Client::ListFiles: could not find export for path %s", path);
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else if ( idNfs3Client::LookUpPath(
              this,
              buf: &this->ioBuffer,
              clientId: &this->clientId,
              dst: v13,
              src: v11[0],
              path: v10,
              attrAtOpen: &v12,
              last: nullptr) != NFS_OK
         || idNfs3Client::ManagedOpListFiles(this, buf: &this->ioBuffer, fh: v13, extension, list) != NFS_OK )
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 0;
  }
  else
  {
    Sys_MutexUnlock(handle: &p_mutex->handle);
    return 1;
  }
}


// ========================================================================
// __unwind$126803
// EA  : 0x82F1AA70
// RVA : 0x00F1AA70
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126803()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 272 + 88));
}


// ========================================================================
// ?Connect@idNfs3Client@@UAA_NPBD0_N@Z
// EA  : 0x82F1AA98
// RVA : 0x00F1AA98
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

BOOL __fastcall idNfs3Client::Connect(idNfs3Client *this, const char *host, const char *path, bool forceRO)
{
  int v7; // r30
  idNfsClient::NfsErr v8; // r3

  if ( !forceRO )
    idLib::Warning(fmt: "idNfs3Client::Connect: write is not implemented in nfs3 client");
  this->RO = true;
  idStr::operator=(this: &this->host, text: host);
  v8 = idNfs3Client::InternalConnect(this, buf: &this->ioBuffer, host, path);
  v7 = 0;
  if ( (unsigned int)v8 >= NFS_ERR_NOENT )
    return false;
  do
  {
    if ( this->connected )
      break;
    ++v7;
  }
  while ( (unsigned __int8)idNfs3Client::TryConnectionRecovery(this, buf: &this->ioBuffer, tryNum: v7, wait: true) != 0 );
  return this->connected;
}


// ========================================================================
// ?Open@idFile_Nfs@@QAA_NPBDW4fsMode_t@@_N2@Z
// EA  : 0x82F1AB58
// RVA : 0x00F1AB58
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

BOOL __fastcall idFile_Nfs::Open(idFile_Nfs *this, const char *path, fsMode_t mode, int create, bool createPath)
{
  int v9; // r24
  const char *v10; // r30
  idNfsClient *Client; // r3
  idNfsClient *v12; // r30
  char v15; // r3
  const char *v16; // r28
  unsigned __int64 v17; // r11
  const idStr *v18; // r3
  const char *v19; // [sp+50h] [-1D0h] BYREF
  _QWORD v20[4]; // [sp+60h] [-1C0h] BYREF
  idStr v21; // [sp+80h] [-1A0h] BYREF
  idStrStatic<256> v22; // [sp+A0h] [-180h] BYREF

  v9 = 0;
  if ( (unsigned int)mode > FS_APPEND )
  {
    idLib::FatalError(fmt: "Invalid file open mode");
    return _LN83_1();
  }
  if ( mode == FS_WRITE )
  {
    v9 = 1;
LABEL_9:
    create = 1;
    goto LABEL_10;
  }
  if ( mode != FS_READ_WRITE )
  {
    if ( mode != FS_READ_NO_BUFFERING && mode != FS_READ )
      goto LABEL_9;
    create = 0;
  }
LABEL_10:
  v10 = path;
  if ( idStr::Icmpn(s1: path, s2: "nfs:", n: 4) == 0 )
    v10 = path + 4;
  idStrStatic<256>::idStrStatic<256>(this: &v22, text: v10);
  idStr::CollapsePath(this: &v22);
  idStr::ToLower(this: &v22);
  idStr::BackSlashesToSlashes(this: &v22);
  Client = idNfsSystem::GetClient(this: &idFile_Nfs::nfsSys, path: v22.data, resPath: &v19);
  v12 = Client;
  if ( Client == nullptr )
    goto LABEL_13;
  v15 = Client->IsRO(this: Client);
  this->ro = v15;
  if ( v15 != 0 && (_BYTE)create != 0 )
  {
    idLib::Warning(fmt: "idFile_Nfs::Open trying to create file on read only fs: %s", path);
LABEL_13:
    idStr::FreeData(this: &v22);
    return false;
  }
  v16 = v19;
  if ( !v12->Open(
          this: v12,
          a2: (idNfsClient::NfsFh *)&this->fh,
          a3: v19,
          a4: mode,
          a5: create,
          a6: v9,
          a7: (idNfsClient::NfsFileAttr *)v20)
    && (!createPath
     || (unsigned __int8)idFile_Nfs::CreateOsPath(path: v22.data) == 0
     || !v12->Open(
           this: v12,
           a2: (idNfsClient::NfsFh *)&this->fh,
           a3: v16,
           a4: mode,
           a5: create,
           a6: v9,
           a7: (idNfsClient::NfsFileAttr *)v20)) )
  {
    goto LABEL_13;
  }
  v17 = v20[0];
  this->mode = mode;
  if ( mode != FS_APPEND )
    LODWORD(v17) = 0;
  this->position = v17;
  v18 = operator+(result: &v21, a: "nfs:", b: &v22);
  idStr::operator=(this: &this->fullPath, text: v18);
  idStr::FreeData(this: &v21);
  this->nfsClient = v12;
  this->openRemote = true;
  idStr::FreeData(this: &v22);
  return true;
}


// ========================================================================
// $LN83_1
// EA  : 0x82F1AD88
// RVA : 0x00F1AD88
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _LN83_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 160));
}


// ========================================================================
// __unwind$126885
// EA  : 0x82F1ADB0
// RVA : 0x00F1ADB0
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void _unwind_126885()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 128));
}


// ========================================================================
// `dynamic initializer for 'fs_nfsRetries''
// EA  : 0x83395190
// RVA : 0x01395190
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_nfsRetries__()
{
  idCVar::idCVar(
    this: &fs_nfsRetries,
    name: "fs_nfsRetries",
    value: "30",
    flags: 2,
    description: "nfs connection error retries before failure, -1 for infinite",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_nfsRetries__);
}


// ========================================================================
// `dynamic initializer for 'fs_nfsRetryWait''
// EA  : 0x833951E8
// RVA : 0x013951E8
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_nfsRetryWait__()
{
  idCVar::idCVar(
    this: &fs_nfsRetryWait,
    name: "fs_nfsRetryWait",
    value: "1",
    flags: 4,
    description: "nfs connection error wait before retry in seconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_nfsRetryWait__);
}


// ========================================================================
// `dynamic initializer for 'idFile_Nfs::nfsSys''
// EA  : 0x83395240
// RVA : 0x01395240
// PDB : w:\tech5\shared\idlib\filesystem\file_nfs.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idFile_Nfs::nfsSys__()
{
  idNfsSystem::idNfsSystem(this: &idFile_Nfs::nfsSys);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idFile_Nfs::nfsSys__);
}

