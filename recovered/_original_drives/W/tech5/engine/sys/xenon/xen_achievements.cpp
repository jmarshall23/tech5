
// ========================================================================
// ?RemoveLocalUser@idAchievementSystemXbox@@UAAXPAVidLocalUser@@@Z
// EA  : 0x829D0CD8
// RVA : 0x009D0CD8
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.cpp
// ========================================================================

void __fastcall idAchievementSystemXbox::RemoveLocalUser(idAchievementSystemXbox *this, idLocalUser *user)
{
  this->Reset(this, a2: user);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->users);
}


// ========================================================================
// ?GetAchievementDescription@idAchievementSystemXbox@@UBA_NPAVidLocalUser@@HAAUachievementDescription_t@@@Z
// EA  : 0x829D0D18
// RVA : 0x009D0D18
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.cpp
// ========================================================================

int __fastcall idAchievementSystemXbox::GetAchievementDescription(
        idAchievementSystemXbox *this,
        idLocalUser *user,
        const int id,
        achievementDescription_t *data)
{
  int num; // r9
  int v7; // r10
  int i; // r11
  int v10; // r28
  unsigned int v11; // r3
  _DWORD *v12; // r29
  unsigned int v13; // r11
  _DWORD *v14; // r10
  const wchar_t **v15; // r31
  int v16; // r3
  unsigned int v17; // r3
  void **v18; // [sp+8h] [-98h]
  unsigned int v19; // [sp+50h] [-50h] BYREF
  void *v20; // [sp+54h] [-4Ch] BYREF
  unsigned int v21; // [sp+58h] [-48h] BYREF

  num = this->users.num;
  v7 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0; this->users.list[i] != user; ++i )
  {
    if ( ++v7 >= num )
      return 0;
  }
  if ( v7 == -1 )
    return 0;
  v10 = 0;
  v11 = user->GetInputDevice(this: user);
  if ( XUserCreateAchievementEnumerator(
         dwTitleId: 0,
         dwUserIndex: v11,
         xuid: 3u,
         dwDetailFlags: 0,
         dwStartingIndex: 0x32u,
         cItem: (unsigned int)&v19,
         pcbBuffer: (unsigned int *)&v20,
         ph: v18) == 0 )
  {
    v12 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\engine\\sys\\xenon\\xen_achievements.cpp(86) : TAG_TEMP",
            size: v19,
            tag: TAG_TEMP,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    if ( XEnumerate(hEnum: v20, pvBuffer: v12, cbBuffer: v19, pcItemsReturned: &v21, pOverlapped: nullptr) == 0 )
    {
      v13 = 0;
      if ( v21 != 0 )
      {
        v14 = v12;
        while ( *v14 != id )
        {
          ++v13;
          v14 += 9;
          if ( v13 >= v21 )
            goto LABEL_19;
        }
        v15 = (const wchar_t **)&v12[9 * v13];
        v16 = wcstombs(s: data->name, pwcs: v15[1], n: 0x1F4u);
        if ( v16 < 0
          || (data->name[v16] = 0, ((v17 = wcstombs(s: data->description, pwcs: v15[2], n: 0x3E8u)) & 0x80000000) != 0) )
        {
          strcpy(data->name, "ERROR PARSING");
        }
        else
        {
          v10 = 1;
          data->description[v17] = 0;
          data->hidden = (~(unsigned int)v15[8] & 8) != 0;
        }
      }
    }
LABEL_19:
    CloseHandle(hObject: v20);
    idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
  }
  return v10;
}


// ========================================================================
// ?GetAchievementState@idAchievementSystemXbox@@UBA_NPAVidLocalUser@@AAV?$idArray@_N$0IA@@@@Z
// EA  : 0x829D0EF0
// RVA : 0x009D0EF0
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.cpp
// ========================================================================

BOOL __fastcall idAchievementSystemXbox::GetAchievementState(
        idAchievementSystemXbox *this,
        idLocalUser *user,
        idArray<bool,128> *achievements)
{
  int num; // r9
  int v7; // r10
  int i; // r11
  BOOL v10; // r31
  unsigned int v11; // r3
  char *v12; // r30
  unsigned int v13; // r9
  unsigned int v14; // r10
  char *v15; // r11
  int v16; // r8
  void **v17; // [sp+8h] [-88h]
  unsigned int v18; // [sp+50h] [-40h] BYREF
  unsigned int v19; // [sp+54h] [-3Ch] BYREF
  void *v20; // [sp+58h] [-38h] BYREF

  memset(Dst: achievements, Val: 0, Size: sizeof(idArray<bool,128>));
  num = this->users.num;
  v7 = 0;
  if ( num <= 0 )
    return false;
  for ( i = 0; this->users.list[i] != user; ++i )
  {
    if ( ++v7 >= num )
      return false;
  }
  if ( v7 == -1 )
    return false;
  v10 = false;
  v11 = user->GetInputDevice(this: user);
  if ( XUserCreateAchievementEnumerator(
         dwTitleId: 0,
         dwUserIndex: v11,
         xuid: 0,
         dwDetailFlags: 0,
         dwStartingIndex: 0x80u,
         cItem: (unsigned int)&v18,
         pcbBuffer: (unsigned int *)&v20,
         ph: v17) == 0 )
  {
    v12 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\engine\\sys\\xenon\\xen_achievements.cpp(153) : TAG_NETWORKING",
                    size: v18,
                    tag: TAG_NETWORKING,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( XEnumerate(hEnum: v20, pvBuffer: v12, cbBuffer: v18, pcItemsReturned: &v19, pOverlapped: nullptr) == 0 )
    {
      v13 = v19;
      v14 = 0;
      if ( v19 != 0 )
      {
        v15 = v12 - 4;
        do
        {
          v16 = *((_DWORD *)v15 + 1);
          ++v14;
          v15 += 36;
          achievements->ptr[v16] = (*(_DWORD *)v15 & 0x20000) != 0;
          v13 = v19;
        }
        while ( v14 < v19 );
      }
      v10 = v13 != 0;
    }
    CloseHandle(hObject: v20);
    idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
  }
  return v10;
}


// ========================================================================
// ?Reset@idAchievementSystemXbox@@UAAXPAVidLocalUser@@@Z
// EA  : 0x829D1060
// RVA : 0x009D1060
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.cpp
// ========================================================================

void __fastcall idAchievementSystemXbox::Reset(idAchievementSystemXbox *this, idLocalUser *user)
{
  int v3; // r29
  unsigned __int8 *p_listStatic; // r31
  void *v5; // r4
  void *v6; // r4
  _DWORD *v7; // r11
  int j; // ctr
  int num; // r8
  int v10; // r10
  int i; // r11

  if ( user != nullptr )
  {
    num = this->users.num;
    v10 = 0;
    if ( num > 0 )
    {
      for ( i = 0; this->users.list[i] != user; ++i )
      {
        if ( ++v10 >= num )
          return;
      }
      if ( v10 != -1 )
        idAchievementSystemXbox::achievementAction_t::Reset(this: &this->achievementAction.ptr[v10]);
    }
  }
  else
  {
    v3 = 0;
    if ( this->users.num > 0 )
    {
      p_listStatic = &this->achievementAction.ptr[0].achievements.listStatic;
      do
      {
        if ( *(p_listStatic - 1040) == 0 || *(p_listStatic - 1040) == 2 )
        {
          v5 = *(void **)(p_listStatic - 1055);
          if ( v5 != nullptr )
            idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
          *(_DWORD *)(p_listStatic - 1055) = 0;
          *(_DWORD *)(p_listStatic - 1047) = 0;
        }
        *(_DWORD *)(p_listStatic - 1051) = 0;
        if ( *p_listStatic == 0 || *p_listStatic == 2 )
        {
          v6 = *(void **)(p_listStatic - 15);
          if ( v6 != nullptr )
            idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
          *(_DWORD *)(p_listStatic - 15) = 0;
          *(_DWORD *)(p_listStatic - 7) = 0;
        }
        *(_DWORD *)(p_listStatic - 11) = 0;
        v7 = p_listStatic + 1025;
        *(_DWORD *)(p_listStatic + 1025) = 0;
        for ( j = 7; j != 0; --j )
          *++v7 = 0;
        ++v3;
        p_listStatic += 2112;
      }
      while ( v3 < this->users.num );
    }
  }
}


// ========================================================================
// ?Cancel@idAchievementSystemXbox@@UAAXPAVidLocalUser@@@Z
// EA  : 0x829D11A0
// RVA : 0x009D11A0
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.cpp
// ========================================================================

void __fastcall idAchievementSystemXbox::Cancel(idAchievementSystemXbox *this, idLocalUser *user)
{
  int num; // r9
  int v3; // r10
  int i; // r11
  char *v5; // r11

  num = this->users.num;
  v3 = 0;
  if ( num > 0 )
  {
    for ( i = 0; this->users.list[i] != user; ++i )
    {
      if ( ++v3 >= num )
        return;
    }
    if ( v3 != -1 )
    {
      v5 = (char *)this + 2112 * v3;
      if ( *((_DWORD *)v5 + 527) != 0 )
        idAchievementSystemXbox::achievementAction_t::Reset(this: (idAchievementSystemXbox::achievementAction_t *)(v5 + 28));
    }
  }
}


// ========================================================================
// ?AchievementUnlock@idAchievementSystemXbox@@UAAXPAVidLocalUser@@H@Z
// EA  : 0x829D1268
// RVA : 0x009D1268
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.cpp
// ========================================================================

void __fastcall idAchievementSystemXbox::AchievementUnlock(
        idAchievementSystemXbox *this,
        idLocalUser *user,
        const idMaterial *achievementID)
{
  int num; // r10
  int v6; // r31
  int i; // r11
  const idMaterial *v8; // r3
  char *v9; // r11
  const idMaterial *v10; // r7
  idList<idSkinMapping,46> *v11; // r3
  int v12; // r9
  int v13; // r8
  idSkinMapping *list; // r6
  int v15; // r11
  idSkinMapping v16; // [sp+50h] [-30h] BYREF

  num = this->users.num;
  v6 = 0;
  if ( num > 0 )
  {
    for ( i = 0; this->users.list[i] != user; ++i )
    {
      if ( ++v6 >= num )
        return;
    }
    if ( v6 != -1 )
    {
      v8 = (const idMaterial *)user->GetInputDevice(this: user);
      v16.to = achievementID;
      v9 = (char *)this + 2112 * v6;
      v10 = v8;
      v16.from = v8;
      v11 = (idList<idSkinMapping,46> *)(v9 + 28);
      v12 = 0;
      v13 = *((_DWORD *)v9 + 8);
      if ( v13 <= 0 )
      {
LABEL_12:
        idList<cachedPageFile_t,5>::Append(this: v11, obj: &v16);
      }
      else
      {
        list = v11->list;
        v15 = 0;
        while ( list[v15].from != v10 || list[v15].to != achievementID )
        {
          ++v12;
          ++v15;
          if ( v12 >= v13 )
            goto LABEL_12;
        }
      }
    }
  }
}


// ========================================================================
// ?FlushPending@idAchievementSystemXbox@@AAAXXZ
// EA  : 0x829D1340
// RVA : 0x009D1340
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.cpp
// ========================================================================

void __fastcall idAchievementSystemXbox::FlushPending(idAchievementSystemXbox *this)
{
  int v2; // r28
  unsigned __int8 *i; // r31
  void **v4; // r30
  unsigned int v5; // r4

  v2 = 0;
  if ( this->users.num > 0 )
  {
    for ( i = &this->achievementAction.ptr[0].pendingAchievments.listStatic;
          *(_DWORD *)(i + 2065) == 0 && *(_DWORD *)(i - 11) != 0;
          i += 2112 )
    {
      v4 = (void **)(i - 15);
      idStaticList<XUSER_ACHIEVEMENT,128>::operator=(
        this: (idStaticList<XUSER_ACHIEVEMENT,128> *)(i + 1025),
        __that: (const idList<idSkinMapping,46> *)(i - 15));
      if ( *i == 0 || *i == 2 )
      {
        if ( *v4 != nullptr )
          idMem::Free(this: &mem, ptr: *v4, align: ALIGN_16);
        *v4 = nullptr;
        *(_DWORD *)(i - 7) = 0;
      }
      *(_DWORD *)(i - 11) = 0;
      v5 = XUserWriteAchievements(
             dwNumAchievements: *(_DWORD *)(i + 1029),
             pAchievements: *(const XUSER_ACHIEVEMENT **)(i + 1025),
             pOverlapped: (_XOVERLAPPED *)(i + 2069));
      if ( v5 != 997 )
      {
        idLib::Warning(fmt: "XUserWriteAchievements error = %d", v5);
        return;
      }
      ++v2;
      *(_DWORD *)(i + 2065) = 1;
      if ( v2 >= this->users.num )
        return;
    }
  }
}


// ========================================================================
// ?Pump@idAchievementSystemXbox@@UAAXXZ
// EA  : 0x829D1428
// RVA : 0x009D1428
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.cpp
// ========================================================================

void __fastcall idAchievementSystemXbox::Pump(idAchievementSystemXbox *this)
{
  int v2; // r23
  int v3; // r24
  _XOVERLAPPED *p_overlapped; // r28
  void (__fastcall **p_pCompletionRoutine)(unsigned int, unsigned int, _XOVERLAPPED *); // r27
  unsigned int dwExtendedError; // r11
  idLocalUser *v7; // r29
  unsigned int v8; // r3
  unsigned int v9; // r4
  signed int v10; // r30
  int v11; // r31
  int v12; // r19
  idPlayerProfile *v13; // r3
  __int64 v14; // r10
  unsigned __int64 v15; // r8
  int v16; // r5
  void (__fastcall *v17)(unsigned int, unsigned int, _XOVERLAPPED *); // r4
  _DWORD *v18; // r11
  int i; // ctr

  v2 = 0;
  if ( this->users.num > 0 )
  {
    v3 = 0;
    p_overlapped = &this->achievementAction.ptr[0].overlapped;
    do
    {
      p_pCompletionRoutine = &p_overlapped[-75].pCompletionRoutine;
      dwExtendedError = p_overlapped[-1].dwExtendedError;
      v7 = this->users.list[v3];
      if ( dwExtendedError != 0 )
      {
        if ( dwExtendedError == 1 && p_overlapped->InternalLow != 997 )
        {
          v8 = XGetOverlappedExtendedError(lpXOverlapped: p_overlapped);
          v9 = v8;
          if ( v8 != 0 )
          {
            if ( v8 == 1 )
              idLib::Printf(fmt: "Achievement already awarded\n");
            else
              idLib::Warning(fmt: "Error writing achievements, err = %d", v8);
          }
          else
          {
            v10 = 0;
            if ( (int)p_overlapped[-38].dwExtendedError > 0 )
            {
              v11 = 0;
              do
              {
                v12 = *(_DWORD *)(p_overlapped[-38].dwCompletionContext + v11 + 4);
                v13 = (idPlayerProfile *)((int (__fastcall *)(idLocalUser *, unsigned int))v7->GetProfile)(
                                           a1: v7,
                                           a2: v9);
                idPlayerProfile::SetAchievement(this: v13, id: v12, a3: v16, a4: v15, a5: v14);
                ++v10;
                v11 += 8;
              }
              while ( v10 < (signed int)p_overlapped[-38].dwExtendedError );
            }
          }
          if ( *((_BYTE *)p_pCompletionRoutine + 1055) == 0 || *((_BYTE *)p_pCompletionRoutine + 1055) == 2 )
          {
            v17 = p_pCompletionRoutine[260];
            if ( v17 != nullptr )
              idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
            p_pCompletionRoutine[260] = nullptr;
            p_pCompletionRoutine[262] = nullptr;
          }
          p_pCompletionRoutine[261] = nullptr;
          v18 = p_pCompletionRoutine + 520;
          for ( i = 7; i != 0; --i )
            *++v18 = 0;
          p_pCompletionRoutine[520] = nullptr;
        }
      }
      else
      {
        idAchievementSystemXbox::FlushPending(this);
      }
      ++v2;
      ++v3;
      p_overlapped = (_XOVERLAPPED *)((char *)p_overlapped + 2112);
    }
    while ( v2 < this->users.num );
  }
}


// ========================================================================
// ?RegisterLocalUser@idAchievementSystemXbox@@UAAXPAVidLocalUser@@@Z
// EA  : 0x829D15A0
// RVA : 0x009D15A0
// PDB : w:\tech5\engine\sys\xenon\xen_achievements.cpp
// ========================================================================

void __fastcall idAchievementSystemXbox::RegisterLocalUser(
        idAchievementSystemXbox *this,
        idLocalUser *user,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idLocalUser *a14)
{
  idList<enum encounterGroupRole_t,5> *p_users; // r3
  int v15; // r10
  int num; // r9
  int v17; // r11

  p_users = (idList<enum encounterGroupRole_t,5> *)&this->users;
  a14 = user;
  v15 = 0;
  num = p_users->num;
  if ( num <= 0 )
    goto LABEL_7;
  v17 = 0;
  while ( (idLocalUser *)p_users->list[v17] != user )
  {
    ++v15;
    ++v17;
    if ( v15 >= num )
      goto LABEL_7;
  }
  if ( v15 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_users, obj: (const encounterGroupRole_t *)&a14);
}

