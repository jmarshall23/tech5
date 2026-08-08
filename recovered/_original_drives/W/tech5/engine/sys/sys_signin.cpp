
// ========================================================================
// ?GetDefaultProfile@idSignInManagerBase@@QAAPAVidPlayerProfile@@XZ
// EA  : 0x829CF0F8
// RVA : 0x009CF0F8
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

idPlayerProfile *__fastcall idSignInManagerBase::GetDefaultProfile(idSignInManagerBase *this)
{
  idGame *v2; // r3
  idPlayerProfile *v3; // r3

  if ( this->defaultProfile == nullptr && common->Game(this: common) != nullptr )
  {
    v2 = common->Game(this: common);
    v3 = v2->CreatePlayerProfile(this: v2, a2: 0);
    this->defaultProfile = v3;
    v3->SetDefaults(this: v3);
  }
  return this->defaultProfile;
}


// ========================================================================
// ?GetLocalUserByInputDevice@idSignInManagerBase@@QAAPAVidLocalUser@@H@Z
// EA  : 0x829CF198
// RVA : 0x009CF198
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

idLocalUser *__fastcall idSignInManagerBase::GetLocalUserByInputDevice(idSignInManagerBase *this, int index)
{
  int v4; // r30
  idLocalUser *v5; // r3
  int v6; // r3
  idSignInManagerBase_vtbl *v7; // r11

  v4 = 0;
  if ( this->GetNumLocalUsers(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = this->GetLocalUserByIndex_2(this, a2: v4);
    v6 = v5->GetInputDevice(this: v5);
    v7 = this->__vftable;
    if ( v6 == index )
      break;
    if ( ++v4 >= v7->GetNumLocalUsers(this) )
      return nullptr;
  }
  return v7->GetLocalUserByIndex_2(this, a2: v4);
}


// ========================================================================
// ?RemoveAllLocalUsers@idSignInManagerBase@@QAAXXZ
// EA  : 0x829CF240
// RVA : 0x009CF240
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

void __fastcall idSignInManagerBase::RemoveAllLocalUsers(idSignInManagerBase *this)
{
  while ( this->GetNumLocalUsers(this) > 0 )
    this->RemoveLocalUserByIndex(this, a2: 0);
}


// ========================================================================
// ?ProcessInputEvent@idSignInManagerBase@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x829CF2B8
// RVA : 0x009CF2B8
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

int __fastcall idSignInManagerBase::ProcessInputEvent(idSignInManagerBase *this, const sysEvent_t *ev)
{
  int evValue; // r11
  idGame *v5; // r3

  if ( this->GetNumLocalUsers(this) >= this->maxDesiredLocalUsers )
    return 0;
  if ( this->IsAnyDeviceBeingRegistered(this) )
    return 0;
  if ( ev->evValue2 == 0 )
    return 0;
  evValue = ev->evValue;
  if ( evValue != 256 && evValue != 264 && evValue != 28 && evValue != 156 )
    return 0;
  if ( swf_waitForCredits.valueInteger != 0 )
  {
    v5 = common->Game(this: common);
    v5->Shell_HandleGuiEvent(this: v5, a2: ev);
    return 0;
  }
  if ( idSignInManagerBase::GetLocalUserByInputDevice(this, index: ev->inputDevice) != nullptr )
    return 0;
  this->RegisterLocalUser(this, a2: ev->inputDevice);
  return 1;
}


// ========================================================================
// ?GetLocalUserByHandle@idSignInManagerBase@@QAAPAVidLocalUser@@UlocalUserHandle_t@@@Z
// EA  : 0x829CF3D0
// RVA : 0x009CF3D0
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

idLocalUser *__fastcall idSignInManagerBase::GetLocalUserByHandle(idSignInManagerBase *this, localUserHandle_t *handle)
{
  int v4; // r30
  localUserHandle_t *v5; // r9
  idSignInManagerBase_vtbl *v6; // r11

  v4 = 0;
  if ( this->GetNumLocalUsers(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = (localUserHandle_t *)this->GetLocalUserByIndex_2(this, a2: v4)->localUserHandle.handle;
    v6 = this->__vftable;
    if ( v5 == handle )
      break;
    if ( ++v4 >= v6->GetNumLocalUsers(this) )
      return nullptr;
  }
  return v6->GetLocalUserByIndex_2(this, a2: v4);
}


// ========================================================================
// ?GetPlayerProfileByInputDevice@idSignInManagerBase@@QAAPAVidPlayerProfile@@H@Z
// EA  : 0x829CF468
// RVA : 0x009CF468
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

idPlayerProfile *__fastcall idSignInManagerBase::GetPlayerProfileByInputDevice(idSignInManagerBase *this, int index)
{
  idLocalUser *LocalUserByInputDevice; // r3

  LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(this: session->signInManager, index);
  if ( LocalUserByInputDevice != nullptr )
    return LocalUserByInputDevice->GetProfile(this: LocalUserByInputDevice);
  else
    return nullptr;
}


// ========================================================================
// ?RemoveLocalUserByHandle@idSignInManagerBase@@QAA_NUlocalUserHandle_t@@@Z
// EA  : 0x829CF4C8
// RVA : 0x009CF4C8
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

int __fastcall idSignInManagerBase::RemoveLocalUserByHandle(idSignInManagerBase *this, localUserHandle_t *handle)
{
  int v4; // r30
  localUserHandle_t *v5; // r9
  idSignInManagerBase_vtbl *v6; // r11

  v4 = 0;
  if ( this->GetNumLocalUsers(this) <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = (localUserHandle_t *)this->GetLocalUserByIndex_2(this, a2: v4)->localUserHandle.handle;
    v6 = this->__vftable;
    if ( v5 == handle )
      break;
    if ( ++v4 >= v6->GetNumLocalUsers(this) )
      return 0;
  }
  v6->RemoveLocalUserByIndex(this, a2: v4);
  return 1;
}


// ========================================================================
// ?ValidateLocalUsers@idSignInManagerBase@@QAAX_N@Z
// EA  : 0x829CF568
// RVA : 0x009CF568
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

void __fastcall idSignInManagerBase::ValidateLocalUsers(idSignInManagerBase *this, bool requireOnline)
{
  int i; // r29
  idLocalUser *v5; // r31

  for ( i = this->GetNumLocalUsers(this) - 1; i >= 0; --i )
  {
    v5 = this->GetLocalUserByIndex_2(this, a2: i);
    if ( !v5->IsProfileReady(this: v5)
      || requireOnline && (!v5->IsOnline(this: v5) || (v5->GetOnlineCaps(this: v5) & 4) == 0) )
    {
      this->RemoveLocalUserByIndex(this, a2: i);
    }
  }
}


// ========================================================================
// ?GetUniqueLocalUserHandle@idSignInManagerBase@@QAA?AUlocalUserHandle_t@@PBD@Z
// EA  : 0x829CF640
// RVA : 0x009CF640
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

idSignInManagerBase *__fastcall idSignInManagerBase::GetUniqueLocalUserHandle(
        idSignInManagerBase *this,
        localUserHandle_t *result,
        const char *name)
{
  __int64 v5; // r3
  unsigned int v6; // r5
  unsigned __int8 v8[16]; // [sp+50h] [-90h] BYREF
  unsigned __int8 v9[16]; // [sp+60h] [-80h] BYREF
  MD5_CTX v10; // [sp+70h] [-70h] BYREF

  LODWORD(v5) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  *(_QWORD *)v8 = v5;
  MD5_Init(ctx: &v10);
  v6 = 0;
  if ( *name != 0 )
  {
    do
      ++v6;
    while ( name[v6] != 0 );
  }
  MD5_Update(context: &v10, input: (const unsigned __int8 *)name, inputLen: v6);
  MD5_Update(context: &v10, input: v8, inputLen: 8u);
  MD5_Final(context: &v10, digest: v9);
  this->__vftable = (idSignInManagerBase_vtbl *)((((((unsigned __int16)((v9[15] << 8) | v9[14]) << 8) | v9[13]) << 8)
                                                | v9[12])
                                               ^ (((((unsigned __int16)((v9[11] << 8) | v9[10]) << 8) | v9[9]) << 8)
                                                | v9[8])
                                               ^ (((((unsigned __int16)((v9[7] << 8) | v9[6]) << 8) | v9[5]) << 8)
                                                | v9[4])
                                               ^ (((((unsigned __int16)((v9[3] << 8) | v9[2]) << 8) | v9[1]) << 8)
                                                | v9[0]));
  return this;
}


// ========================================================================
// `dynamic initializer for 'com_requireNonProductionSignIn''
// EA  : 0x83363AC0
// RVA : 0x01363AC0
// PDB : w:\tech5\engine\sys\sys_signin.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_requireNonProductionSignIn__()
{
  idCVar::idCVar(
    this: &com_requireNonProductionSignIn,
    name: "com_requireNonProductionSignIn",
    value: "1",
    flags: 1,
    description: "If true, will require sign in, even on non production builds.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_requireNonProductionSignIn__);
}

