
// ========================================================================
// ?GetMasterLocalUser@idSignInManagerBase@@QAAPAVidLocalUser@@XZ
// EA  : 0x826512C8
// RVA : 0x006512C8
// PDB : w:\tech5\engine\sys\sys_signin.h
// ========================================================================

idLocalUser *__fastcall idSignInManagerBase::GetMasterLocalUser(idSignInManagerBase *this)
{
  if ( this->GetNumLocalUsers(this) <= 0 )
    return nullptr;
  else
    return this->GetLocalUserByIndex_2(this, a2: 0);
}


// ========================================================================
// ?GetMasterLocalUser@idSignInManagerBase@@QBAPBVidLocalUser@@XZ
// EA  : 0x8265CC48
// RVA : 0x0065CC48
// PDB : w:\tech5\engine\sys\sys_signin.h
// ========================================================================

const idLocalUser *__fastcall idSignInManagerBase::GetMasterLocalUser(idSignInManagerBase *this)
{
  if ( this->GetNumLocalUsers(this) <= 0 )
    return nullptr;
  else
    return this->GetLocalUserByIndex(this, a2: 0);
}


// ========================================================================
// ?GetMasterInputDevice@idSignInManagerBase@@QBAHXZ
// EA  : 0x8265CCB8
// RVA : 0x0065CCB8
// PDB : w:\tech5\engine\sys\sys_signin.h
// ========================================================================

int __fastcall idSignInManagerBase::GetMasterInputDevice(idSignInManagerBase *this)
{
  const idLocalUser *MasterLocalUser; // r3

  if ( idSignInManagerBase::GetMasterLocalUser(this) == nullptr )
    return -1;
  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this);
  return MasterLocalUser->GetInputDevice(this: (idLocalUser *)MasterLocalUser);
}


// ========================================================================
// ?GetMasterLocalUserHandle@idSignInManagerBase@@QBA?AUlocalUserHandle_t@@XZ
// EA  : 0x829A4CB0
// RVA : 0x009A4CB0
// PDB : w:\tech5\engine\sys\sys_signin.h
// ========================================================================

idSignInManagerBase *__fastcall idSignInManagerBase::GetMasterLocalUserHandle(
        idSignInManagerBase *this,
        idSignInManagerBase *result)
{
  idSignInManagerBase_vtbl *handle; // r10

  if ( idSignInManagerBase::GetMasterLocalUser(this: result) != nullptr )
    handle = (idSignInManagerBase_vtbl *)idSignInManagerBase::GetMasterLocalUser(this: result)->localUserHandle.handle;
  else
    handle = nullptr;
  this->__vftable = handle;
  return this;
}


// ========================================================================
// ?IsMasterLocalUserOnline@idSignInManagerBase@@QBA_NXZ
// EA  : 0x829D3230
// RVA : 0x009D3230
// PDB : w:\tech5\engine\sys\sys_signin.h
// ========================================================================

BOOL __fastcall idSignInManagerBase::IsMasterLocalUserOnline(idSignInManagerBase *this)
{
  const idLocalUser *MasterLocalUser; // r3

  if ( idSignInManagerBase::GetMasterLocalUser(this) == nullptr )
    return false;
  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this);
  return MasterLocalUser->IsOnline(this: (idLocalUser *)MasterLocalUser);
}


// ========================================================================
// ??1idSignInManagerBase@@UAA@XZ
// EA  : 0x829E6E58
// RVA : 0x009E6E58
// PDB : w:\tech5\engine\sys\sys_signin.h
// ========================================================================

void __fastcall idSignInManagerBase::~idSignInManagerBase(idSignInManagerBase *this)
{
  this->__vftable = (idSignInManagerBase_vtbl *)&idSignInManagerBase::`vftable';
}

