
// ========================================================================
// ?SetStatInt@idLocalUser@@UAAXHH@Z
// EA  : 0x829BA520
// RVA : 0x009BA520
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

void __fastcall idLocalUser::SetStatInt(idLocalUser *this, int stat, profileStatValue_t *value)
{
  idPlayerProfile *v5; // r31
  idGame *v6; // r3

  v5 = this->GetProfile(this);
  if ( v5 != nullptr )
  {
    v6 = common->Game(this: common);
    if ( !v6->GetConsoleUsed(this: v6) )
      idPlayerProfile::StatSetInt(this: v5, stat, value);
  }
}


// ========================================================================
// ?SetStatFloat@idLocalUser@@UAAXHM@Z
// EA  : 0x829BA5A0
// RVA : 0x009BA5A0
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

void __fastcall idLocalUser::SetStatFloat(idLocalUser *this, int stat, double value)
{
  idPlayerProfile *v5; // r31
  idGame *v6; // r3

  v5 = this->GetProfile(this);
  if ( v5 != nullptr )
  {
    v6 = common->Game(this: common);
    if ( !v6->GetConsoleUsed(this: v6) )
      idPlayerProfile::StatSetFloat(this: v5, stat, value);
  }
}


// ========================================================================
// ??0idLocalUser@@QAA@XZ
// EA  : 0x829BA648
// RVA : 0x009BA648
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

idLocalUser *__fastcall idLocalUser::idLocalUser(idLocalUser *this)
{
  idProfileMgr *p_profileMgr; // r29

  p_profileMgr = &this->profileMgr;
  this->__vftable = (idLocalUser_vtbl *)&idLocalUser::`vftable';
  this->localUserHandle.handle = 0;
  idProfileMgr::idProfileMgr(this: &this->profileMgr);
  *(_WORD *)this->joiningLobby = 0;
  idProfileMgr::Init(this: p_profileMgr, user_: this);
  this->syncAchievementsRequested = false;
  return this;
}


// ========================================================================
// __unwind$219158
// EA  : 0x829BA6A8
// RVA : 0x009BA6A8
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

void _unwind_219158()
{
  int v0; // r12

  idProfileMgr::~idProfileMgr(this: (idProfileMgr *)(*(_DWORD *)(v0 - 128 + 148) + 12));
}


// ========================================================================
// ?Pump@idLocalUser@@QAAXXZ
// EA  : 0x829BA6E8
// RVA : 0x009BA6E8
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

void __fastcall idLocalUser::Pump(idLocalUser *this)
{
  if ( this->syncAchievementsRequested && session->achievementSystem->IsInitialized(this: session->achievementSystem) )
  {
    idAchievementSystem::SyncAchievementBits(this: session->achievementSystem, user: this);
    this->syncAchievementsRequested = false;
  }
  idProfileMgr::Pump(this: &this->profileMgr);
  if ( idProfileMgr::GetProfile(this: &this->profileMgr) != nullptr
    && idProfileMgr::GetProfile(this: &this->profileMgr)->state == 0 )
  {
    session->achievementSystem->Pump(this: session->achievementSystem);
  }
  this->PumpPlatform(this);
}


// ========================================================================
// ?IsStorageDeviceAvailable@idLocalUser@@UBA_NXZ
// EA  : 0x829BA7A8
// RVA : 0x009BA7A8
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

BOOL __fastcall idLocalUser::IsStorageDeviceAvailable(idLocalUser *this)
{
  return saveGame_enable.valueInteger != 0;
}


// ========================================================================
// ?StorageSizeAvailable@idLocalUser@@UAA_N_KAA_J@Z
// EA  : 0x829BA7C0
// RVA : 0x009BA7C0
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

BOOL __fastcall idLocalUser::StorageSizeAvailable(
        idLocalUser *this,
        int a2,
        unsigned __int64 minSizeInBytes,
        __int64 *neededBytes)
{
  _QWORD *v5; // r31
  int v6; // r3
  __int64 v7; // r11

  v5 = (_QWORD *)HIDWORD(minSizeInBytes);
  v6 = (unsigned __int64)Sys_GetDriveFreeSpaceInBytes(path: fs_savepath.valueString.data) >> 32;
  LODWORD(v7) = a2 - v6;
  *v5 = v7;
  if ( a2 - v6 >= 0 )
  {
    return a2 == v6;
  }
  else
  {
    LODWORD(v7) = 0;
    *v5 = v7;
    return true;
  }
}


// ========================================================================
// ?GetStatInt@idLocalUser@@UBAHH@Z
// EA  : 0x829BA838
// RVA : 0x009BA838
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

int __fastcall idLocalUser::GetStatInt(idLocalUser *this, int stat)
{
  idPlayerProfile *v3; // r3

  v3 = this->GetProfile(this);
  if ( v3 != nullptr )
    return idPlayerProfile::StatGetInt(this: v3, stat);
  else
    return 0;
}


// ========================================================================
// ?GetStatFloat@idLocalUser@@UBAMH@Z
// EA  : 0x829BA898
// RVA : 0x009BA898
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

float __fastcall idLocalUser::GetStatFloat(idLocalUser *this, int stat)
{
  idPlayerProfile *v3; // r3
  double Float; // fp1

  v3 = this->GetProfile(this);
  if ( v3 != nullptr )
    Float = idPlayerProfile::StatGetFloat(this: v3, stat);
  else
    Float = 0.0;
  return *((float *)&Float + 1);
}


// ========================================================================
// ?LoadProfileSettings@idLocalUser@@QAAXXZ
// EA  : 0x829BA908
// RVA : 0x009BA908
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

void __fastcall idLocalUser::LoadProfileSettings(idLocalUser *this)
{
  idPlayerProfile *Profile; // r30
  idGame *v3; // r27
  idGame_vtbl *v4; // r30
  int v5; // r3

  Profile = idProfileMgr::GetProfile(this: &this->profileMgr);
  if ( Profile == nullptr )
  {
    if ( common->Game(this: common) == nullptr )
      return;
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v3 = common->Game(this: common);
    v4 = v3->__vftable;
    v5 = this->GetInputDevice(this);
    Profile = v4->CreatePlayerProfile(this: v3, a2: v5);
    Profile->SetDefaults(this: Profile);
    idMem::PopHeap(this: &mem);
  }
  idPlayerProfile::LoadSettings(this: Profile);
}


// ========================================================================
// __unwind$219281
// EA  : 0x829BA9E0
// RVA : 0x009BA9E0
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

void _unwind_219281()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 144 + 80));
}


// ========================================================================
// ?SaveProfileSettings@idLocalUser@@QAAXXZ
// EA  : 0x829BAA08
// RVA : 0x009BAA08
// PDB : w:\tech5\engine\sys\sys_localuser.cpp
// ========================================================================

void __fastcall idLocalUser::SaveProfileSettings(idLocalUser *this)
{
  idPlayerProfile *Profile; // r3

  Profile = idProfileMgr::GetProfile(this: &this->profileMgr);
  if ( Profile != nullptr )
    idPlayerProfile::SaveSettings(this: Profile);
}

