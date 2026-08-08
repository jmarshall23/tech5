
// ========================================================================
// ?Init@idProfileMgr@@QAAXPAVidLocalUser@@@Z
// EA  : 0x829BAA98
// RVA : 0x009BAA98
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void __fastcall idProfileMgr::Init(idProfileMgr *this, idLocalUser *user_)
{
  this->user = user_;
  this->handle = 0;
}


// ========================================================================
// ??1idProfileMgr@@QAA@XZ
// EA  : 0x829BAB18
// RVA : 0x009BAB18
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void __fastcall idProfileMgr::~idProfileMgr(idProfileMgr *this)
{
  idSaveGameProcessorLoadProfile *Myptr; // r3

  Myptr = this->profileLoadProcessor._Myptr;
  if ( Myptr != nullptr )
    ((void (__fastcall *)(idSaveGameProcessorLoadProfile *, int))Myptr->dtr_idSaveGameProcessor)(a1: Myptr, a2: 1);
  if ( this->profileSaveProcessor._Myptr != nullptr )
    ((void (__fastcall *)(idSaveGameProcessorSaveProfile *, int))this->profileSaveProcessor._Myptr->dtr_idSaveGameProcessor)(
      a1: this->profileSaveProcessor._Myptr,
      a2: 1);
}


// ========================================================================
// __unwind$221129
// EA  : 0x829BAB90
// RVA : 0x009BAB90
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_221129()
{
  int v0; // r12

  std::auto_ptr<idSaveGameProcessorSaveProfile>::~auto_ptr<idSaveGameProcessorSaveProfile>(this: *(std::auto_ptr<idSaveGameProcessorSaveProfile> **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetProfile@idProfileMgr@@QAAPAVidPlayerProfile@@XZ
// EA  : 0x829BABB8
// RVA : 0x009BABB8
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

idPlayerProfile *__fastcall idProfileMgr::GetProfile(idProfileMgr *this)
{
  idPlayerProfile *profile; // r11
  idGame *v3; // r29
  idGame_vtbl *v4; // r30
  int v5; // r3
  idPlayerProfile *v6; // r3
  char v8; // r10

  profile = this->profile;
  if ( profile == nullptr )
  {
    if ( common->Game(this: common) != nullptr )
    {
      v3 = common->Game(this: common);
      v4 = v3->__vftable;
      v5 = this->user->GetInputDevice(this: this->user);
      v6 = v4->CreatePlayerProfile(this: v3, a2: v5);
      this->profile = v6;
      v6->SetDefaults(this: v6);
    }
    profile = this->profile;
    if ( profile == nullptr )
      return nullptr;
  }
  if ( profile->state == LOADING || (v8 = 0, profile->requestedState == LOAD_REQUESTED) )
    v8 = 1;
  return v8 != 0 ? nullptr : profile;
}


// ========================================================================
// ?Initialize@idSaveGameProcessorSaveProfile@@AAA_NXZ
// EA  : 0x829BACB8
// RVA : 0x009BACB8
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorSaveProfile::Initialize(idSaveGameProcessorSaveProfile *this)
{
  int v2; // r26
  unsigned int *v3; // r30
  const unsigned int *v4; // r29
  void *v5; // r3

  v2 = 0;
  v3 = &this->writeableSettings[0].dwSettingId + 3;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v4 = settingsIDs;
  do
  {
    *(v3 - 5) = *v4;
    if ( v2 < 1 )
    {
      if ( *v4 >> 28 == 4 )
      {
        *v3 = (unsigned int)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                              size: 0x200u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
        *(v3 - 1) = 512;
      }
    }
    else
    {
      *((_BYTE *)v3 - 12) = 6;
      v5 = idMem::AllocWithLocation(
             this: &mem,
             location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
             size: 0x3E8u,
             tag: TAG_NEW,
             zeroBuffer: false,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
      *(v3 - 1) = 1000;
      *v3 = (unsigned int)v5;
      memset(Dst: v5, Val: 0, Size: 0x3E8u);
    }
    ++v4;
    ++v2;
    v3 += 10;
  }
  while ( (int)v4 < (int)&off_8226B2D0 );
  HIBYTE(this->writeableSettings[2].data.string.pwszData) = 1;
  Sys_SignalRaise(handle: &this->parms.callbackSignal.handle);
  idMem::PopHeap(this: &mem);
  return 1;
}


// ========================================================================
// __unwind$221196
// EA  : 0x829BADC8
// RVA : 0x009BADC8
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_221196()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 192 + 80));
}


// ========================================================================
// ?SaveWait@idSaveGameProcessorSaveProfile@@AAA_NXZ
// EA  : 0x829BADF0
// RVA : 0x009BADF0
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorSaveProfile::SaveWait(idSaveGameProcessorSaveProfile *this)
{
  Sys_SignalRaise(handle: &this->parms.callbackSignal.handle);
  if ( *(&this->writeableSettings[2].dwSettingId + 2) == 997 )
    return 1;
  common->ShowSaveIndicator(this: common, a2: false, a3: false);
  if ( XGetOverlappedExtendedError(lpXOverlapped: (_XOVERLAPPED *)(&this->writeableSettings[2].dwSettingId + 2)) != 0 )
    this->parms.errorCode = 16;
  return 0;
}


// ========================================================================
// ?Initialize@idSaveGameProcessorLoadProfile@@AAA_NXZ
// EA  : 0x829BAE80
// RVA : 0x009BAE80
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorLoadProfile::Initialize(idSaveGameProcessorLoadProfile *this)
{
  unsigned int *v2; // r11
  int i; // ctr
  unsigned int ProfileSettings; // r30

  v2 = &this->baseSettings[2].dwSettingId + 2;
  for ( i = 7; i != 0; --i )
    *++v2 = 0;
  *((_DWORD *)&this->baseSettings[2].data.ftData + 2) = 0;
  ProfileSettings = XUserReadProfileSettings(
                      dwTitleId: 0,
                      dwUserIndex: 0,
                      dwNumSettingIds: 4u,
                      pdwSettingIds: settingsIDs,
                      pcbResults: (unsigned int *)&this->baseSettings[2].data.ftData + 2,
                      pResults: nullptr,
                      pXOverlapped: (_XOVERLAPPED *)(&this->baseSettings[2].dwSettingId + 3));
  Sys_SignalRaise(handle: &this->parms.callbackSignal.handle);
  if ( ProfileSettings == 122 )
    return 1;
  idLib::Warning(fmt: "XUserReadProfileSettings FAILED, error = %d.", ProfileSettings);
  this->parms.errorCode = 16;
  return 0;
}


// ========================================================================
// ?InitializeWait@idSaveGameProcessorLoadProfile@@AAA_NXZ
// EA  : 0x829BAF30
// RVA : 0x009BAF30
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorLoadProfile::InitializeWait(idSaveGameProcessorLoadProfile *this)
{
  int v2; // r26
  unsigned int *v3; // r30
  const unsigned int *v4; // r29
  void *v5; // r3

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  Sys_SignalRaise(handle: &this->parms.callbackSignal.handle);
  if ( *(&this->baseSettings[2].dwSettingId + 3) != 997 )
  {
    *(&this->baseSettings[2].dwSettingId + 2) = (unsigned int)idMem::AllocWithLocation(
                                                                this: &mem,
                                                                location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                                                size: *((_DWORD *)&this->baseSettings[2].data.ftData + 2),
                                                                tag: TAG_NEW,
                                                                zeroBuffer: false,
                                                                align: ALIGN_16,
                                                                heap: HEAP_DEFAULTHEAP);
    v2 = 0;
    v3 = &this->baseSettings[0].dwSettingId + 3;
    v4 = settingsIDs;
    do
    {
      *(v3 - 5) = *v4;
      if ( v2 < 1 )
      {
        if ( *v4 >> 28 == 4 )
        {
          *v3 = (unsigned int)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                size: 0x200u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
          *(v3 - 1) = 512;
        }
      }
      else
      {
        *((_BYTE *)v3 - 12) = 6;
        v5 = idMem::AllocWithLocation(
               this: &mem,
               location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
               size: 0x3E8u,
               tag: TAG_NEW,
               zeroBuffer: false,
               align: ALIGN_16,
               heap: HEAP_DEFAULTHEAP);
        *(v3 - 1) = 1000;
        *v3 = (unsigned int)v5;
        memset(Dst: v5, Val: 0, Size: 0x3E8u);
      }
      ++v4;
      ++v2;
      v3 += 10;
    }
    while ( (int)v4 < (int)&off_8226B2D0 );
    this->state = STATE_LOAD;
  }
  idMem::PopHeap(this: &mem);
  return 1;
}


// ========================================================================
// __unwind$221272
// EA  : 0x829BB070
// RVA : 0x009BB070
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_221272()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 192 + 80));
}


// ========================================================================
// ?Load@idSaveGameProcessorLoadProfile@@AAA_NXZ
// EA  : 0x829BB098
// RVA : 0x009BB098
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorLoadProfile::Load(idSaveGameProcessorLoadProfile *this)
{
  unsigned int *v2; // r11
  int i; // ctr
  unsigned int ProfileSettings; // r30

  v2 = &this->baseSettings[2].dwSettingId + 2;
  for ( i = 7; i != 0; --i )
    *++v2 = 0;
  ProfileSettings = XUserReadProfileSettings(
                      dwTitleId: 0,
                      dwUserIndex: this->profile->deviceNum,
                      dwNumSettingIds: 4u,
                      pdwSettingIds: settingsIDs,
                      pcbResults: (unsigned int *)&this->baseSettings[2].data.ftData + 2,
                      pResults: *((_XUSER_READ_PROFILE_SETTING_RESULT **)&this->baseSettings[2].dwSettingId + 2),
                      pXOverlapped: (_XOVERLAPPED *)(&this->baseSettings[2].dwSettingId + 3));
  Sys_SignalRaise(handle: &this->parms.callbackSignal.handle);
  if ( ProfileSettings == 997 )
  {
    this->state = STATE_LOAD_WAIT;
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "XUserReadProfileSettings error = %d", ProfileSettings);
    this->parms.errorCode = 16;
    return 0;
  }
}


// ========================================================================
// ?Save@idSaveGameProcessorSaveProfile@@AAA_NXZ
// EA  : 0x829BB1D8
// RVA : 0x009BB1D8
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorSaveProfile::Save(idSaveGameProcessorSaveProfile *this)
{
  int v2; // r4
  int v4; // r3
  char *buffer; // r29
  idFile_SaveGame *profileFile; // r3
  char *filePtr; // r28
  size_t v8; // r3
  __int64 v9; // r11
  unsigned int v10; // r28
  idTempArray<char> v11; // [sp+58h] [-38h] BYREF

  v2 = this->profileFile->Length(this: this->profileFile) + 4;
  if ( v2 <= 3000 )
  {
    idTempArray<char>::idTempArray<char>(this: &v11, num: 0xBB8u);
    v4 = this->profileFile->Length(this: this->profileFile);
    buffer = v11.buffer;
    *(_DWORD *)v11.buffer = v4;
    profileFile = this->profileFile;
    filePtr = profileFile->filePtr;
    v8 = profileFile->Length(this: profileFile);
    memcpy(Dst: buffer + 4, Src: filePtr, Size: v8);
    memcpy(Dst: *((void **)&this->writeableSettings[1].source + 1), Src: buffer, Size: 0x3E8u);
    memcpy(Dst: *((void **)&this->writeableSettings[1].data.type + 3), Src: buffer + 1000, Size: 0x3E8u);
    memcpy(Dst: *((void **)&this->writeableSettings[2].dwSettingId + 1), Src: buffer + 2000, Size: 0x3E8u);
    common->ShowSaveIndicator(this: common, a2: true, a3: false);
    LODWORD(v9) = 0;
    *((_QWORD *)&this->writeableSettings[2].dwSettingId + 1) = v9;
    *(_QWORD *)&this->writeableSettings[2].data.type = v9;
    *((_QWORD *)&this->writeableSettings[2].data.type + 1) = v9;
    this->writeableSettings[2].data.nData = 0;
    v10 = XUserWriteProfileSettings(
            dwUserIndex: this->profile->deviceNum,
            dwNumSettings: 3u,
            pSettings: (_XUSER_PROFILE_SETTING *const)&this->writeableSettings[0].data,
            pXOverlapped: (_XOVERLAPPED *)(&this->writeableSettings[2].dwSettingId + 2));
    Sys_SignalRaise(handle: &this->parms.callbackSignal.handle);
    if ( v10 == 997 )
    {
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "XUserWriteProfileSettings error = %d", v10);
      this->parms.errorCode = 16;
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "Profile file is too large, failing save (req %d, avail %d).", v2, 3000);
    return 0;
  }
}


// ========================================================================
// __unwind$221625
// EA  : 0x829BB364
// RVA : 0x009BB364
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_221625()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 144 + 88));
}


// ========================================================================
// ?LoadWait@idSaveGameProcessorLoadProfile@@AAA_NXZ
// EA  : 0x829BB398
// RVA : 0x009BB398
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idSaveGameProcessorLoadProfile::LoadWait(idSaveGameProcessorLoadProfile *this)
{
  const unsigned int *v3; // r26
  int v4; // r24
  unsigned int *v5; // r28
  int i; // r23
  void **v7; // r29
  char *v8; // r30
  __int64 v9; // r11 OVERLAPPED
  unsigned int v10; // r11
  const void *v11; // r4
  const void *v12; // r4
  size_t v13; // r5
  _DWORD *v14; // r30
  idFile_SaveGame *profileFile; // r3
  int v16; // r11
  unsigned int v17; // r9

  Sys_SignalRaise(handle: &this->parms.callbackSignal.handle);
  if ( *(&this->baseSettings[2].dwSettingId + 3) == 997 )
    return 1;
  if ( XGetOverlappedExtendedError(lpXOverlapped: (_XOVERLAPPED *)(&this->baseSettings[2].dwSettingId + 3)) != 0 )
  {
    this->parms.errorCode = 16;
    return 0;
  }
  v3 = settingsIDs;
  v4 = 0;
  v5 = &this->baseSettings[0].dwSettingId + 2;
  for ( i = 4; i != 0; --i )
  {
    v7 = (void **)(v5 + 1);
    v8 = (char *)v5 + *(_DWORD *)(*(&this->baseSettings[2].dwSettingId + 2) + 4) + -3128 - (_DWORD)this;
    *(__int64 *)((char *)&v9 + 4) = *((_QWORD *)v8 + 1);
    *((_QWORD *)v5 - 3) = *(__int64 *)((char *)&v9 + 4);
    *(v5 - 8) = *(_DWORD *)v8;
    *(v5 - 4) = *v3;
    *((_BYTE *)v5 - 8) = v8[24];
    if ( (unsigned int)(unsigned __int8)v8[24] - 1 > 5 )
      goto LABEL_31;
    if ( v8[24] == 2 )
    {
      LODWORD(v9) = 0;
      if ( *(_DWORD *)v8 != 0 )
        v9 = *((_QWORD *)v8 + 4);
      *(_QWORD *)v5 = v9;
    }
    else
    {
      if ( v8[24] == 3 )
      {
        if ( *(_DWORD *)v8 != 0 )
          *(_QWORD *)v5 = *((_QWORD *)v8 + 4);
        else
          *(_QWORD *)v5 = 0;
        goto LABEL_31;
      }
      if ( v8[24] != 4 )
      {
        if ( v8[24] == 5 )
        {
          if ( *(_DWORD *)v8 != 0 )
            *v5 = *((unsigned int *)v8 + 8);
          else
            *(float *)v5 = 0.0;
          goto LABEL_31;
        }
        if ( v8[24] == 1 )
        {
          v10 = 0;
          if ( *(_DWORD *)v8 != 0 )
            goto LABEL_29;
        }
        else
        {
          v11 = *((const void **)v8 + 9);
          if ( v11 == nullptr )
          {
            *(_DWORD *)*v7 = 0;
            *v5 = 1000;
            goto LABEL_31;
          }
          memcpy(Dst: *v7, Src: v11, Size: *((_DWORD *)v8 + 8));
          ++v4;
LABEL_29:
          v10 = *((_DWORD *)v8 + 8);
        }
        *v5 = v10;
        goto LABEL_31;
      }
      memset(Dst: *v7, Val: 0, Size: *v5);
      v12 = *((const void **)v8 + 9);
      if ( v12 != nullptr )
      {
        v13 = *((_DWORD *)v8 + 8);
        if ( v13 != 0 )
        {
          memcpy(Dst: *v7, Src: v12, Size: v13);
          goto LABEL_29;
        }
      }
    }
LABEL_31:
    v5 += 10;
    ++v3;
  }
  if ( v4 == 3 )
  {
    v14 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
            size: 0xBB8u,
            tag: TAG_TEMP,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    memcpy(Dst: v14, Src: *((const void **)&this->baseSettings[1].source + 1), Size: 0x3E8u);
    memcpy(Dst: v14 + 250, Src: *((const void **)&this->baseSettings[1].data.type + 3), Size: 0x3E8u);
    memcpy(Dst: v14 + 500, Src: *((const void **)&this->baseSettings[2].dwSettingId + 1), Size: 0x3E8u);
    if ( *v14 >= 0xBB4u )
    {
      v16 = 4;
    }
    else
    {
      profileFile = this->profileFile;
      if ( profileFile != nullptr )
      {
        ((void (__fastcall *)(idFile_SaveGame *, _DWORD *))profileFile->Write)(a1: profileFile, a2: v14 + 1);
        goto LABEL_39;
      }
      v16 = 256;
    }
    this->parms.errorCode = v16;
LABEL_39:
    idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
    return 0;
  }
  else
  {
    v17 = *(&this->baseSettings[0].dwSettingId + 2) - 1;
    *((_BYTE *)&this->baseSettings[2].data.ftData + 13) = 1;
    *((_BYTE *)&this->baseSettings[2].data.ftData + 14) = (_cntlzw(v17) & 0x20) != 0;
    return 0;
  }
}


// ========================================================================
// __unwind$221693
// EA  : 0x829BB684
// RVA : 0x009BB684
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_221693()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 224 + 88));
}


// ========================================================================
// ?OnLoadSettingsCompleted@idProfileMgr@@AAAXPAVidSaveLoadParms@@@Z
// EA  : 0x829BB750
// RVA : 0x009BB750
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void __fastcall idProfileMgr::OnLoadSettingsCompleted(idProfileMgr *this, idSaveLoadParms *parms)
{
  idFile_SaveGame **v4; // r3
  __int64 v5; // r28
  idFile_Memory *v6; // r30
  int v7; // r3
  char v8; // r11
  int v9; // r3
  unsigned int v10; // r29
  unsigned int v11; // r3
  idSaveGameProcessorLoadProfile *Myptr; // r11
  int v13; // [sp+50h] [-90h] BYREF
  int v14; // [sp+54h] [-8Ch] BYREF
  idTempArray<char> v15; // [sp+58h] [-88h] BYREF
  _DWORD v16[4]; // [sp+60h] [-80h] BYREF
  _QWORD v17[3]; // [sp+70h] [-70h] BYREF
  int v18; // [sp+88h] [-58h]
  __int16 v19; // [sp+8Ch] [-54h]
  __int64 v20; // [sp+90h] [-50h]

  if ( parms->errorCode != 0 )
    return;
  v4 = FindFromGenericPtr<idFile_SaveGame *,char const [13],5>(
         list: &parms->files,
         other: (const char (*)[12])"profile.bin");
  LODWORD(v5) = 0;
  if ( v4 == nullptr )
  {
    v6 = nullptr;
LABEL_6:
    v8 = 0;
    goto LABEL_7;
  }
  v6 = *v4;
  if ( *v4 == nullptr )
    goto LABEL_6;
  v7 = v6->Length(this: *v4);
  v8 = 1;
  if ( v7 <= 0 )
    goto LABEL_6;
LABEL_7:
  if ( v8 != 0 )
  {
    idTempArray<char>::idTempArray<char>(this: &v15, num: 0xBB8u);
    idFile_Memory::MakeReadOnly(this: v6);
    v6->Read(this: v6, a2: &v13, a3: 4u);
    v6->Read(this: v6, a2: &v14, a3: 4u);
    v9 = v6->Length(this: v6);
    HIDWORD(v5) = v15.buffer;
    v10 = v9 - 8;
    v6->Read(this: v6, a2: v15.buffer, a3: v9 - 8);
    v11 = MD5_BlockChecksum(data: (const void *)HIDWORD(v5), length: v10);
    if ( v13 == v11 )
    {
      if ( v14 == 1 )
      {
        v17[0] = HIDWORD(v5);
        v17[2] = 0;
        HIDWORD(v17[1]) = v15.num;
        LODWORD(v17[1]) = v15.num;
        v18 = 0;
        v19 = 0;
        v20 = v5;
        HIBYTE(v16[0]) = 0;
        v16[1] = v17;
        if ( !this->profile->Serialize(this: this->profile, a2: (idSerializer *)v16) )
          parms->errorCode = 4;
      }
      else
      {
        idLib::Warning(fmt: "Version: %d, currentVersion: %d", v14, 1);
        parms->errorCode = 0x2000;
      }
    }
    else
    {
      idLib::Warning(fmt: "Checksum: 0x%08x, originalChecksum: 0x%08x, size = %d", v11, v13, v10);
      parms->errorCode = 4;
    }
    idKeyInput::SetUserDeviceNumForBind(inputDeviceNum: this->profile->deviceNum);
    Myptr = this->profileLoadProcessor._Myptr;
    if ( *((_BYTE *)&Myptr->baseSettings[2].data.ftData + 13) != 0 )
      Myptr->profile->SetInvertLook(
        this: Myptr->profile,
        a2: *((unsigned __int8 *)&Myptr->baseSettings[2].data.ftData + 14));
    if ( HIDWORD(v5) != 0 )
      idMem::Free(this: &mem, ptr: (void *)HIDWORD(v5), align: ALIGN_16);
  }
  else
  {
    parms->errorCode = 256;
  }
}


// ========================================================================
// __unwind$221817_0
// EA  : 0x829BB984
// RVA : 0x009BB984
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_221817_0()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 224 + 88));
}


// ========================================================================
// ?Process@idSaveGameProcessorSaveProfile@@UAA_NXZ
// EA  : 0x829BB9B0
// RVA : 0x009BB9B0
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorSaveProfile::Process(idSaveGameProcessorSaveProfile *this)
{
  idSaveGameProcessorSaveProfile::state_t state; // r11
  int result; // r3
  idSaveGameProcessorSaveProfile::state_t v4; // r11

  state = this->state;
  result = 1;
  if ( state == 0 )
  {
    result = idSaveGameProcessorSaveProfile::Initialize(this);
    v4 = STATE_SAVE;
    goto LABEL_7;
  }
  if ( state == STATE_SAVE )
  {
    result = idSaveGameProcessorSaveProfile::Save(this);
    v4 = STATE_SAVE_WAIT;
LABEL_7:
    this->state = v4;
    return result;
  }
  if ( (unsigned int)state < (STATE_SAVE|STATE_SAVE_WAIT) )
    return idSaveGameProcessorSaveProfile::SaveWait(this);
  return result;
}


// ========================================================================
// ?Process@idSaveGameProcessorLoadProfile@@UAA_NXZ
// EA  : 0x829BBA30
// RVA : 0x009BBA30
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorLoadProfile::Process(idSaveGameProcessorLoadProfile *this)
{
  idSaveGameProcessorLoadProfile::state_t state; // r11
  int result; // r3

  state = this->state;
  result = 1;
  if ( (unsigned int)state <= STATE_LOAD_WAIT )
  {
    if ( state == STATE_INITIALIZE_WAIT )
    {
      return idSaveGameProcessorLoadProfile::InitializeWait(this);
    }
    else if ( state == STATE_LOAD )
    {
      result = idSaveGameProcessorLoadProfile::Load(this);
      this->state = STATE_LOAD_WAIT;
    }
    else if ( state != STATE_INITIALIZE )
    {
      return idSaveGameProcessorLoadProfile::LoadWait(this);
    }
    else
    {
      result = idSaveGameProcessorLoadProfile::Initialize(this);
      this->state = STATE_INITIALIZE_WAIT;
    }
  }
  return result;
}


// ========================================================================
// ?InitLoadProfile@idSaveGameProcessorLoadProfile@@QAA_NPAVidPlayerProfile@@PBD@Z
// EA  : 0x829BBB58
// RVA : 0x009BBB58
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorLoadProfile::InitLoadProfile(
        idSaveGameProcessorLoadProfile *this,
        idPlayerProfile *profile_,
        const char *folder_)
{
  char *data; // r4
  char *v8; // r4
  size_t v9; // r5
  char *v10; // r3
  char *v11; // r4
  size_t v12; // r5
  char *v13; // r3
  idFile_Memory *v14; // r3
  idFile_SaveGame *v15; // r29
  idFile_SaveGame *v16; // r11
  int v17; // r11
  idSaveGameProcessorLoadProfile::state_t v18; // r11
  bool v19; // zf
  idStr v20; // [sp+60h] [-110h] BYREF
  idStrStatic<64> v21; // [sp+80h] [-F0h] BYREF
  idStrStatic<64> v22; // [sp+E0h] [-90h] BYREF

  if ( !idSaveGameProcessor::Init(this) )
    return 0;
  data = AddSaveFolderPrefix(result: &v20, folder: folder_, type: PACKAGE_PROFILE)->data;
  idStrStatic<64>::idStrStatic<64>(this: &v21, text: data);
  v8 = v21.data;
  v9 = v21.len + 1;
  v10 = this->parms.directory.data;
  this->parms.directory.len = v21.len;
  memcpy(Dst: v10, Src: v8, Size: v9);
  idStr::FreeData(this: &v21);
  idStr::FreeData(this: &v20);
  idStrStatic<64>::idStrStatic<64>(this: &v22, text: folder_);
  v11 = v22.data;
  v12 = v22.len + 1;
  v13 = this->parms.description.slotName.data;
  this->parms.description.slotName.len = v22.len;
  memcpy(Dst: v13, Src: v11, Size: v12);
  idStr::FreeData(this: &v22);
  this->parms.mode = 1;
  v14 = (idFile_Memory *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x154u,
                           tag: TAG_SAVEGAMES,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v15 = (idFile_SaveGame *)v14;
  if ( v14 != nullptr )
  {
    idFile_Memory::idFile_Memory(this: v14, name: "profile.bin");
    v15->type = 66;
    v15->__vftable = (idFile_SaveGame_vtbl *)&idFile_SaveGame::`vftable';
    v16 = v15;
    v15->error = false;
  }
  else
  {
    v16 = nullptr;
  }
  this->profileFile = v16;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->parms.files,
    obj: (const encounterGroupRole_t *)&this->profileFile);
  v17 = *((unsigned __int8 *)&this->baseSettings[2].data.ftData + 12);
  this->profile = profile_;
  v19 = v17 == 0;
  v18 = STATE_INITIALIZE;
  if ( !v19 )
    v18 = STATE_LOAD;
  this->state = v18;
  return 1;
}


// ========================================================================
// __unwind$221996
// EA  : 0x829BBCB8
// RVA : 0x009BBCB8
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_221996()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$221997
// EA  : 0x829BBCE0
// RVA : 0x009BBCE0
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_221997()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 368 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// ?LoadSettingsAsync@idProfileMgr@@AAAXXZ
// EA  : 0x829BBF08
// RVA : 0x009BBF08
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void __fastcall idProfileMgr::LoadSettingsAsync(idProfileMgr *this)
{
  idPlayerProfile *profile; // r4
  int valueInteger; // r11
  idSaveGameProcessorLoadProfile *Myptr; // r29
  idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *> *v5; // r3
  idSaveGameProcessorLoadProfile *v6; // r4
  int v7; // r3
  idPlayerProfile *v8; // r5
  idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *> v9; // [sp+60h] [-30h] BYREF

  profile = this->profile;
  valueInteger = saveGame_enable.valueInteger;
  if ( profile != nullptr )
  {
    if ( saveGame_enable.valueInteger != 0 )
    {
      if ( (unsigned __int8)idSaveGameProcessorLoadProfile::InitLoadProfile(
                              this: this->profileLoadProcessor._Myptr,
                              profile_: profile,
                              folder_: &byte_8200D768) != 0 )
      {
        this->profileLoadProcessor._Myptr->parms.skipErrorDialogMask = 384;
        Myptr = this->profileLoadProcessor._Myptr;
        v5 = MakeCallback<idProfileMgr,idSaveLoadParms *>(
               result: &v9,
               t: this,
               f: idProfileMgr::OnLoadSettingsCompleted,
               a1: &Myptr->parms);
        idSaveGameProcessor::AddCompletedCallback(this: Myptr, callback: v5);
        v6 = this->profileLoadProcessor._Myptr;
        v9.__vftable = (idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *>_vtbl *)&idCallback::`vftable';
        v7 = idSaveGameManager::ExecuteProcessor(this: session->saveGameManager, processor: v6);
        v8 = this->profile;
        this->handle = v7;
        v8->state = LOADING;
      }
      return;
    }
  }
  else
  {
    idLib::Warning(fmt: "Not loading profile, profile is NULL.");
    valueInteger = saveGame_enable.valueInteger;
  }
  if ( valueInteger == 0 )
    idLib::Warning(fmt: "Skipping profile load because saveGame_enable = 0");
}


// ========================================================================
// __unwind$222228
// EA  : 0x829BBFFC
// RVA : 0x009BBFFC
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_222228()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 144 + 96));
}


// ========================================================================
// ?InitSaveProfile@idSaveGameProcessorSaveProfile@@QAA_NPAVidPlayerProfile@@PBD@Z
// EA  : 0x829BC040
// RVA : 0x009BC040
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

int __fastcall idSaveGameProcessorSaveProfile::InitSaveProfile(
        idSaveGameProcessorSaveProfile *this,
        idPlayerProfile *profile_,
        const char *folder)
{
  idFile_Memory *v6; // r3
  idFile_SaveGame *v7; // r28
  idFile_SaveGame *v8; // r3
  void *v9; // r27
  int pwszData_high; // r11
  unsigned int v12; // [sp+50h] [-190h] BYREF
  int v13[3]; // [sp+54h] [-18Ch] BYREF
  void *v14; // [sp+60h] [-180h] BYREF
  const void *v15; // [sp+64h] [-17Ch]
  int v16; // [sp+68h] [-178h]
  int v17; // [sp+6Ch] [-174h]
  int v18; // [sp+70h] [-170h]
  int v19; // [sp+74h] [-16Ch]
  int v20; // [sp+78h] [-168h]
  char v21; // [sp+7Ch] [-164h]
  char v22; // [sp+7Dh] [-163h]
  __int64 v23; // [sp+80h] [-160h]
  _DWORD v24[6]; // [sp+88h] [-158h] BYREF
  idStaticList<idFile_SaveGame *,10> v25; // [sp+A0h] [-140h] BYREF
  idSaveGameDetails v26; // [sp+E0h] [-100h] BYREF

  v6 = (idFile_Memory *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x154u,
                          tag: TAG_SAVEGAMES,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v7 = (idFile_SaveGame *)v6;
  v24[2] = v6;
  if ( v6 != nullptr )
  {
    idFile_Memory::idFile_Memory(this: v6, name: "profile.bin");
    v7->error = false;
    v7->type = 66;
    v8 = v7;
    v7->__vftable = (idFile_SaveGame_vtbl *)&idFile_SaveGame::`vftable';
  }
  else
  {
    v8 = nullptr;
  }
  this->profileFile = v8;
  idFile_Memory::MakeWritable(this: v8);
  idFile_Memory::SetMaxLength(this: this->profileFile, len: 0xBB8u);
  v24[3] = 2988;
  v9 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
         size: 0xBACu,
         tag: TAG_TEMP,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v24[2] = v9;
  v14 = v9;
  v15 = v9;
  v16 = 2988;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0x100000000LL;
  HIBYTE(v24[0]) = 1;
  v24[1] = &v14;
  profile_->Serialize(this: profile_, a2: (idSerializer *)v24);
  v12 = MD5_BlockChecksum(data: v15, length: (v18 != 0) + v17);
  this->profileFile->Write(this: this->profileFile, a2: &v12, a3: 4u);
  v13[0] = 1;
  this->profileFile->Write(this: this->profileFile, a2: v13, a3: 4u);
  idLib::PrintfIf(
    condition: profile_verbose.valueInteger != 0,
    fmt: "checksum: 0x%08x, version 0x%08x, length: %d\n",
    v12,
    v13[0],
    (v18 != 0) + v17);
  this->profileFile->Write(this: this->profileFile, a2: v15, a3: (v18 != 0) + v17);
  idFile_Memory::MakeReadOnly(this: this->profileFile);
  v25.num = 0;
  v25.granularity = 1;
  v25.size = 10;
  v25.list = v25.staticList;
  v25.memTag = 5;
  v25.listStatic = 1;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&v25,
    obj: (const encounterGroupRole_t *)&this->profileFile);
  idSaveGameDetails::idSaveGameDetails(this: &v26);
  if ( idSaveGameProcessorSaveFiles::InitSave(this, folder, files: &v25, descriptionForPS3: &v26, type: PACKAGE_PROFILE) )
  {
    idKeyInput::SetUserDeviceNumForBind(inputDeviceNum: profile_->deviceNum);
    pwszData_high = HIBYTE(this->writeableSettings[2].data.string.pwszData);
    this->profile = profile_;
    this->state = pwszData_high != 0;
    idSaveGameDetails::~idSaveGameDetails(this: &v26);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v25);
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    return 1;
  }
  else
  {
    idSaveGameDetails::~idSaveGameDetails(this: &v26);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v25);
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    return 0;
  }
}


// ========================================================================
// __unwind$222353
// EA  : 0x829BC31C
// RVA : 0x009BC31C
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_222353()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 480 + 144), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$222354
// EA  : 0x829BC348
// RVA : 0x009BC348
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_222354()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 480 + 144));
}


// ========================================================================
// __unwind$222355
// EA  : 0x829BC370
// RVA : 0x009BC370
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_222355()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 160));
}


// ========================================================================
// __unwind$222356
// EA  : 0x829BC398
// RVA : 0x009BC398
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_222356()
{
  int v0; // r12

  idSaveGameDetails::~idSaveGameDetails(this: (idSaveGameDetails *)(v0 - 480 + 224));
}


// ========================================================================
// ?SaveSettingsAsync@idProfileMgr@@AAAXXZ
// EA  : 0x829BC3E8
// RVA : 0x009BC3E8
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void __fastcall idProfileMgr::SaveSettingsAsync(idProfileMgr *this)
{
  idSaveGameProcessorSaveProfile *Myptr; // r29
  idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *> *v3; // r3
  idSaveGameProcessorSaveProfile *v4; // r4
  int v5; // r3
  idPlayerProfile *profile; // r7
  idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *> v7; // [sp+60h] [-30h] BYREF

  if ( saveGame_enable.valueInteger != 0 )
  {
    if ( idProfileMgr::GetProfile(this) != nullptr )
    {
      if ( (unsigned __int8)idSaveGameProcessorSaveProfile::InitSaveProfile(
                              this: this->profileSaveProcessor._Myptr,
                              profile_: this->profile,
                              folder: &byte_8200D768) != 0 )
      {
        Myptr = this->profileSaveProcessor._Myptr;
        v3 = MakeCallback<idProfileMgr,idSaveLoadParms *>(
               result: &v7,
               t: this,
               f: (void (__fastcall *)(idProfileMgr *, idSaveLoadParms *))idPhysics_StaticMulti::UpdateTime,
               a1: &this->profileSaveProcessor._Myptr->parms);
        idSaveGameProcessor::AddCompletedCallback(this: Myptr, callback: v3);
        v4 = this->profileSaveProcessor._Myptr;
        v7.__vftable = (idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *>_vtbl *)&idCallback::`vftable';
        v5 = idSaveGameManager::ExecuteProcessor(this: session->saveGameManager, processor: v4);
        profile = this->profile;
        this->handle = v5;
        profile->state = SAVING;
      }
    }
    else
    {
      idLib::Warning(fmt: "Not saving profile, profile is NULL.");
    }
  }
  else
  {
    idLib::Warning(fmt: "Skipping profile save because saveGame_enable = 0");
  }
}


// ========================================================================
// __unwind$222535
// EA  : 0x829BC4C4
// RVA : 0x009BC4C4
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_222535()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 144 + 96));
}


// ========================================================================
// ??0idProfileMgr@@QAA@XZ
// EA  : 0x829BC5D0
// RVA : 0x009BC5D0
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

idProfileMgr *__fastcall idProfileMgr::idProfileMgr(idProfileMgr *this)
{
  idSaveGameProcessor *v2; // r3
  idSaveGameProcessor *v3; // r30
  idSaveGameProcessorSaveProfile *v4; // r11
  idSaveGameProcessor *v5; // r3
  idSaveGameProcessor *v6; // r30
  idSaveGameProcessorLoadProfile *v7; // r11

  v2 = (idSaveGameProcessor *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xCD8u,
                                tag: TAG_SAVEGAMES,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v3 = v2;
  if ( v2 != nullptr )
  {
    idSaveGameProcessor::idSaveGameProcessor(this: v2);
    v3[1].__vftable = nullptr;
    v4 = (idSaveGameProcessorSaveProfile *)v3;
    v3->__vftable = (idSaveGameProcessor_vtbl *)&idSaveGameProcessorSaveProfile::`vftable';
    *((_DWORD *)&v3[1].__vftable + 1) = 0;
    HIBYTE(v3[1].parms.description.descriptors.args.granularity) = 0;
  }
  else
  {
    v4 = nullptr;
  }
  this->profileSaveProcessor._Myptr = v4;
  v5 = (idSaveGameProcessor *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xCE0u,
                                tag: TAG_SAVEGAMES,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v6 = v5;
  if ( v5 != nullptr )
  {
    idSaveGameProcessor::idSaveGameProcessor(this: v5);
    v6[1].__vftable = nullptr;
    v7 = (idSaveGameProcessorLoadProfile *)v6;
    *((_DWORD *)&v6[1].__vftable + 1) = 0;
    HIBYTE(v6[1].parms.description.descriptors.argHash.indexChain) = 0;
    v6->__vftable = (idSaveGameProcessor_vtbl *)&idSaveGameProcessorLoadProfile::`vftable';
    BYTE1(v6[1].parms.description.descriptors.argHash.indexChain) = 0;
    BYTE2(v6[1].parms.description.descriptors.argHash.indexChain) = 0;
  }
  else
  {
    v7 = nullptr;
  }
  this->profileLoadProcessor._Myptr = v7;
  this->profile = nullptr;
  this->handle = 0;
  return this;
}


// ========================================================================
// __unwind$222686
// EA  : 0x829BC6DC
// RVA : 0x009BC6DC
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_222686()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$222687
// EA  : 0x829BC708
// RVA : 0x009BC708
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_222687()
{
  int v0; // r12

  std::auto_ptr<idSaveGameProcessorSaveProfile>::~auto_ptr<idSaveGameProcessorSaveProfile>(this: *(std::auto_ptr<idSaveGameProcessorSaveProfile> **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$222688
// EA  : 0x829BC730
// RVA : 0x009BC730
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void _unwind_222688()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// ?Pump@idProfileMgr@@QAAXXZ
// EA  : 0x829BC760
// RVA : 0x009BC760
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void __fastcall idProfileMgr::Pump(idProfileMgr *this)
{
  idPlayerProfile *profile; // r11
  idPlayerProfile::state_t state; // r11
  char v4; // r8
  bool v5; // r29
  BOOL v6; // r30
  int errorCode; // r11
  idPlayerProfile::state_t requestedState; // r11

  profile = this->profile;
  if ( profile != nullptr )
  {
    state = profile->state;
    v4 = _cntlzw(state - 1);
    v5 = (_cntlzw(state - 2) & 0x20) != 0;
    v6 = (v4 & 0x20) != 0;
    if ( ((v4 & 0x20) != 0 || v5) && session->IsSaveGameCompletedFromHandle(this: session, a2: &this->handle) )
    {
      this->profile->state = 0;
      if ( !v6 && v5 )
      {
        errorCode = this->profileLoadProcessor._Myptr->parms.errorCode;
        if ( errorCode != 128 && errorCode != 256 )
        {
          if ( errorCode != 4 )
          {
            if ( errorCode != 0 )
              this->profile->state = ERR;
            goto LABEL_12;
          }
          idLib::Warning(fmt: "Profile corrupt, creating a new one...");
          ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
            a1: common,
            a2: 132,
            a3: 1,
            a4: 0,
            a5: 0,
            a6: 1,
            a7: 0,
            a8: 0);
          this->profile->SetDefaults(this: this->profile);
        }
        idPlayerProfile::SaveSettings(this: this->profile);
LABEL_12:
        session->OnLocalUserProfileLoaded(this: session, a2: this->user);
      }
LABEL_17:
      requestedState = this->profile->requestedState;
      if ( requestedState == SAVE_REQUESTED )
      {
        idProfileMgr::SaveSettingsAsync(this);
        this->profile->requestedState = 0;
      }
      else if ( requestedState == LOAD_REQUESTED )
      {
        idProfileMgr::LoadSettingsAsync(this);
        this->profile->requestedState = 0;
      }
      return;
    }
    if ( !v6 && !v5 )
      goto LABEL_17;
  }
}


// ========================================================================
// `dynamic initializer for 'profile_verbose''
// EA  : 0x83362B80
// RVA : 0x01362B80
// PDB : w:\tech5\engine\sys\sys_profile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__profile_verbose__()
{
  idCVar::idCVar(
    this: &profile_verbose,
    name: "profile_verbose",
    value: "0",
    flags: 1,
    description: "Turns on debug spam for profiles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__profile_verbose__);
}

