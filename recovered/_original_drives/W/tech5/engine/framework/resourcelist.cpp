
// ========================================================================
// ?GetResourceTypeName@idResourceList@@QBAPBDXZ
// EA  : 0x82694A80
// RVA : 0x00694A80
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idResourceList::GetResourceTypeName(idResourceList *this)
{
  if ( this->resourceTypeName == nullptr )
    idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
}


// ========================================================================
// ?GetNetworkChecksum@idResourceList@@SAKXZ
// EA  : 0x82694AA0
// RVA : 0x00694AA0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

unsigned int __fastcall idResourceList::GetNetworkChecksum()
{
  return networkResourceInfo.networkChecksum;
}


// ========================================================================
// ?ForTypeName@idResourceList@@SAPAV1@PBD@Z
// EA  : 0x82694AB0
// RVA : 0x00694AB0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idResourceList *__fastcall idResourceList::ForTypeName(const char *typeName)
{
  idResourceList *v2; // r31
  const char *resourceTypeName; // r3

  v2 = listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    while ( 1 )
    {
      resourceTypeName = v2->resourceTypeName;
      if ( resourceTypeName == nullptr )
        break;
      if ( idStr::Icmp(s1: resourceTypeName, s2: typeName) == 0 )
        return v2;
      v2 = v2->nextResourceList;
      if ( v2 == nullptr )
        goto LABEL_5;
    }
    idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
    return v2;
  }
  else
  {
LABEL_5:
    idLib::Printf(fmt: "Unknown resource type '%s'\n", typeName);
    return nullptr;
  }
}


// ========================================================================
// ?GetNumNetworkResources@idResourceList@@SAHXZ
// EA  : 0x82694B98
// RVA : 0x00694B98
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

int __fastcall idResourceList::GetNumNetworkResources()
{
  return networkResourceInfo.networkResources.num;
}


// ========================================================================
// ?GetNetworkResource@idResourceList@@SAPBVidResource@@H@Z
// EA  : 0x82694BA8
// RVA : 0x00694BA8
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idResourceList::GetNetworkResource(int networkID)
{
  if ( networkID < 0 || networkID >= networkResourceInfo.networkResources.num )
    idLib::Error(
      fmt: "Network resource %d out of range. Valid range [0-%d]",
      networkID,
      networkResourceInfo.networkResources.num - 1);
}


// ========================================================================
// ?ForStaticID@idResourceList@@SAPAV1@H@Z
// EA  : 0x82694BE8
// RVA : 0x00694BE8
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idResourceList *__fastcall idResourceList::ForStaticID(int id)
{
  idResourceList *v1; // r11

  v1 = listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    while ( v1->staticID != id )
    {
      v1 = v1->nextResourceList;
      if ( v1 == nullptr )
        goto LABEL_4;
    }
    return v1;
  }
  else
  {
LABEL_4:
    idLib::Printf(fmt: "Unknown resource type id '%i'\n", id);
    return nullptr;
  }
}


// ========================================================================
// ?ShouldPerformNetworkResourceExchange@idResourceList@@SA_NXZ
// EA  : 0x82694C58
// RVA : 0x00694C58
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

int __fastcall idResourceList::ShouldPerformNetworkResourceExchange()
{
  if ( net_forceNetDeclExchange.valueInteger != 0 )
    return 1;
  else
    return ((idLib::production >= PROD_DEVELOPMENT) + ((unsigned int)idLib::production >= PROD_PRODUCTION)) & 1;
}


// ========================================================================
// ?Resources_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82694C98
// RVA : 0x00694C98
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall Resources_f(const idCmdArgs *args)
{
  int v1; // r29
  idResourceList *v2; // r31
  const char *resourceTypeName; // r30
  int num; // r27
  int v5; // r3
  unsigned int v6; // r5
  idResource **v7; // r4
  idSort_Quick<idResource *,idSort_ResourceName> *v8; // r3

  v1 = 0;
  v2 = listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    while ( 1 )
    {
      resourceTypeName = v2->resourceTypeName;
      if ( resourceTypeName == nullptr )
        break;
      num = v2->num;
      v5 = v2->AllocSize(this: v2);
      idLib::Printf(fmt: "%4i : %4i %s\n", num, v5, resourceTypeName);
      v1 += v2->num;
      v2 = v2->nextResourceList;
      if ( v2 == nullptr )
        goto LABEL_4;
    }
    idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
    idSort_Quick<idResource *,idSort_ResourceName>::Sort(this: v8, base: v7, num: v6);
  }
  else
  {
LABEL_4:
    idLib::Printf(fmt: "%i total resources\n", v1);
  }
}


// ========================================================================
// ?Mutex@idResourceList@@CAPAVidSysMutex@@XZ
// EA  : 0x826953A0
// RVA : 0x006953A0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idSysMutex *__fastcall idResourceList::Mutex()
{
  if ( (_S13_3 & 1) == 0 )
  {
    _S13_3 |= 1u;
    Sys_MutexCreate(handle: &mutex.handle);
    atexit(func: (void (__fastcall *)())_idResourceList::Mutex_::_2_::_dynamic_atexit_destructor_for__mutex__);
  }
  return &mutex;
}


// ========================================================================
// __unwind$222683
// EA  : 0x82695418
// RVA : 0x00695418
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_222683()
{
  _S13_3 &= ~1u;
}


// ========================================================================
// ?ClearHashTable@idResourceList@@QAAXXZ
// EA  : 0x82695438
// RVA : 0x00695438
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idResourceList::ClearHashTable(idResourceList *this)
{
  idSysMutex *v2; // r30
  int *p_staticID; // r11
  int v4; // ctr
  idResource *v5; // r10

  v2 = idResourceList::Mutex();
  Sys_MutexLock(handle: &v2->handle, blocking: true);
  p_staticID = &this->staticID;
  v4 = 256;
  v5 = RESOURCE_TAIL_LINK;
  do
  {
    *++p_staticID = (int)v5;
    --v4;
  }
  while ( v4 != 0 );
  this->num = 0;
  Sys_MutexUnlock(handle: &v2->handle);
}


// ========================================================================
// ?Index@idResourceList@@QBAPAVidResource@@H@Z
// EA  : 0x826954B0
// RVA : 0x006954B0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idResource *__fastcall idResourceList::Index(idResourceList *this, int index)
{
  idSysMutex *v4; // r28
  int v5; // r9
  idResource **hashTable; // r10
  idResource *v7; // r30

  v4 = idResourceList::Mutex();
  Sys_MutexLock(handle: &v4->handle, blocking: true);
  if ( index >= this->num )
    idLib::FatalError(fmt: "Resource index exceeds current count");
  v5 = 0;
  hashTable = this->hashTable;
  while ( 1 )
  {
    v7 = *hashTable;
    if ( *hashTable != RESOURCE_TAIL_LINK )
      break;
LABEL_7:
    ++v5;
    ++hashTable;
    if ( v5 >= 256 )
    {
      idLib::FatalError(fmt: "Resource index count was incorrect");
      goto _LN40;
    }
  }
  while ( index != 0 )
  {
    v7 = v7->nextOnHashChain;
    --index;
    if ( v7 == RESOURCE_TAIL_LINK )
      goto LABEL_7;
  }
_LN40:
  Sys_MutexUnlock(handle: &v4->handle);
  return v7;
}


// ========================================================================
// $M222776_0
// EA  : 0x82695558
// RVA : 0x00695558
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _M222776_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?Remove_Locked@idResourceList@@AAAXPAVidResource@@@Z
// EA  : 0x82695590
// RVA : 0x00695590
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idResourceList::Remove_Locked(idResourceList *this, idResource *ptr)
{
  const char *str; // r29
  idResource **p_nextOnHashChain; // r10
  idResource *i; // r11

  str = ptr->name.str;
  p_nextOnHashChain = &this->hashTable[(unsigned __int8)idStr::IHash(string: str)];
  for ( i = *p_nextOnHashChain; i != RESOURCE_TAIL_LINK; i = i->nextOnHashChain )
  {
    if ( i == ptr )
      break;
    p_nextOnHashChain = &i->nextOnHashChain;
  }
  if ( *p_nextOnHashChain == nullptr )
    idLib::FatalError(fmt: "idResourceList::Remove( %s ) not found", str);
  *p_nextOnHashChain = ptr->nextOnHashChain;
  ptr->nextOnHashChain = nullptr;
  --this->num;
}


// ========================================================================
// ?Remove@idResourceList@@QAAXPAVidResource@@@Z
// EA  : 0x82695638
// RVA : 0x00695638
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idResourceList::Remove(idResourceList *this, idResource *ptr)
{
  idSysMutex *v4; // r30

  v4 = idResourceList::Mutex();
  Sys_MutexLock(handle: &v4->handle, blocking: true);
  idResourceList::Remove_Locked(this, ptr);
  Sys_MutexUnlock(handle: &v4->handle);
}


// ========================================================================
// __unwind$222865
// EA  : 0x82695680
// RVA : 0x00695680
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_222865()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?ReloadStaleResources@idResourceList@@QBA_NXZ
// EA  : 0x826956B0
// RVA : 0x006956B0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

BOOL __fastcall idResourceList::ReloadStaleResources(idResourceList *this)
{
  int v3; // r24
  int v4; // r26
  int v5; // r29
  idSysMutex *v6; // r28
  int v7; // r9
  idResource **hashTable; // r10
  idResource *v9; // r30

  if ( idLib::production != PROD_DEVELOPMENT )
    return false;
  v3 = 0;
  v4 = 0;
  if ( this->num <= 0 )
    return v3;
LABEL_4:
  v5 = v4;
  v6 = idResourceList::Mutex();
  Sys_MutexLock(handle: &v6->handle, blocking: true);
  if ( v4 >= this->num )
  {
    idLib::FatalError(fmt: "Resource index exceeds current count");
  }
  else
  {
    v7 = 0;
    hashTable = this->hashTable;
    while ( v7 < 256 )
    {
      v9 = *hashTable;
      if ( *hashTable != RESOURCE_TAIL_LINK )
      {
        while ( v5 != 0 )
        {
          v9 = v9->nextOnHashChain;
          --v5;
          if ( v9 == RESOURCE_TAIL_LINK )
            goto LABEL_10;
        }
        Sys_MutexUnlock(handle: &v6->handle);
        if ( (*((_BYTE *)v9 + 32) & 0x80) != 0 && v9->ReloadIfStale(this: v9) )
        {
          idLib::Printf(fmt: "reloaded %s\n", v9->name.str);
          v3 = 1;
        }
        if ( ++v4 < this->num )
          goto LABEL_4;
        return v3;
      }
LABEL_10:
      ++v7;
      ++hashTable;
    }
  }
  idLib::FatalError(fmt: "Resource index count was incorrect");
  return _LN58();
}


// ========================================================================
// $LN58
// EA  : 0x826957E0
// RVA : 0x006957E0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _LN58()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 80));
}


// ========================================================================
// ?MarkAllStaticResources@idResourceList@@SAXXZ
// EA  : 0x82695808
// RVA : 0x00695808
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

static void __fastcall idResourceList::MarkAllStaticResources()
{
  idSysMutex *v0; // r31
  idResourceList *v1; // r8
  idResource *v2; // r10
  idResource **hashTable; // r9
  int i; // ctr
  idResource *j; // r11

  v0 = idResourceList::Mutex();
  Sys_MutexLock(handle: &v0->handle, blocking: true);
  v1 = listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    v2 = RESOURCE_TAIL_LINK;
    do
    {
      hashTable = v1->hashTable;
      for ( i = 256; i != 0; --i )
      {
        for ( j = *hashTable; j != v2; j = j->nextOnHashChain )
          *((_BYTE *)j + 32) |= 0x40u;
        ++hashTable;
      }
      v1 = v1->nextResourceList;
    }
    while ( v1 != nullptr );
  }
  networkResourceInfo.staticNetworkChecksum = networkResourceInfo.networkChecksum;
  networkResourceInfo.firstDynamicNetworkResource = networkResourceInfo.networkResources.num;
  Sys_MutexUnlock(handle: &v0->handle);
}


// ========================================================================
// ?FreeAllDynamicResources@idResourceList@@SAXXZ
// EA  : 0x826958C8
// RVA : 0x006958C8
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

static void __fastcall idResourceList::FreeAllDynamicResources()
{
  idSysMutex *v0; // r15
  idResourceList *v1; // r26
  const char *resourceTypeName; // r5
  idResource **hashTable; // r20
  int i; // r18
  idResource **v5; // r27
  idResource *v6; // r30
  int v7; // r6
  int v8; // r8
  idResource **p_nextOnHashChain; // r29
  int v10; // r3

  idLib::PrintfIf(
    condition: (resource_showLoads.valueInteger >> 31) + (resource_showLoads.valueInteger != 0),
    fmt: "FreeAllDynamicResources... \n");
  v0 = idResourceList::Mutex();
  Sys_MutexLock(handle: &v0->handle, blocking: true);
  v1 = listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    while ( 1 )
    {
      resourceTypeName = v1->resourceTypeName;
      if ( resourceTypeName == nullptr )
        break;
      idLib::PrintfIf(
        condition: (resource_showLoads.valueInteger >> 31) + (resource_showLoads.valueInteger != 0),
        fmt: " Res List: %s\n",
        resourceTypeName);
      hashTable = v1->hashTable;
      for ( i = 256; i != 0; --i )
      {
        v5 = hashTable;
        if ( *hashTable != RESOURCE_TAIL_LINK )
        {
          while ( 1 )
          {
            v6 = *v5;
            if ( *v5 == nullptr )
              break;
            idLib::PrintfIf(
              condition: (resource_showLoads.valueInteger >> 31) + (resource_showLoads.valueInteger != 0),
              fmt: "  Resource: %s ",
              v6->name.str);
            v7 = *((unsigned __int8 *)v6 + 32);
            v8 = resource_showLoads.valueInteger - 1;
            p_nextOnHashChain = &v6->nextOnHashChain;
            v10 = (resource_showLoads.valueInteger >> 31) + (resource_showLoads.valueInteger != 0);
            if ( (v7 & 0x40) != 0 )
            {
              idLib::PrintfIf(condition: v10, fmt: "STATIC\n", v7 & 0x40, v7, 0, v8);
            }
            else
            {
              idLib::PrintfIf(condition: v10, fmt: "DELETING\n", 0, v7, 0, v8);
              *v5 = *p_nextOnHashChain;
              p_nextOnHashChain = v5;
              v6->nextOnHashChain = nullptr;
              --v1->num;
              ((void (__fastcall *)(idResource *, int))v6->dtr_idResource)(a1: v6, a2: 1);
            }
            v5 = p_nextOnHashChain;
            if ( *p_nextOnHashChain == RESOURCE_TAIL_LINK )
              goto LABEL_12;
          }
          idLib::Warning(fmt: "Resource was NULL in ::FreeAllDynamicResources");
        }
LABEL_12:
        ++hashTable;
      }
      v1 = v1->nextResourceList;
      if ( v1 == nullptr )
        goto LABEL_14;
    }
    idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
    _LN73();
  }
  else
  {
LABEL_14:
    Sys_MutexUnlock(handle: &v0->handle);
  }
}


// ========================================================================
// $LN73
// EA  : 0x82695AA0
// RVA : 0x00695AA0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _LN73()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 240 + 80));
}


// ========================================================================
// ?ForceAllResourcesToReload@idResourceList@@SAXXZ
// EA  : 0x82695AD0
// RVA : 0x00695AD0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

static void __fastcall idResourceList::ForceAllResourcesToReload()
{
  idResourceList *v0; // r26
  int num; // r24
  int v2; // r28
  int v3; // r29
  int v4; // r9
  idResource **hashTable; // r10
  idResource *v6; // r30

  v0 = listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    while ( 1 )
    {
      num = v0->num;
      v2 = 0;
      if ( num > 0 )
        break;
LABEL_13:
      v0 = v0->nextResourceList;
      if ( v0 == nullptr )
        return;
    }
LABEL_3:
    v3 = v2;
    if ( (_S13_3 & 1) == 0 )
    {
      _S13_3 |= 1u;
      Sys_MutexCreate(handle: &mutex.handle);
      atexit(func: (void (__fastcall *)())_idResourceList::Mutex_::_2_::_dynamic_atexit_destructor_for__mutex__);
    }
    Sys_MutexLock(handle: &mutex.handle, blocking: true);
    if ( v2 >= v0->num )
    {
      idLib::FatalError(fmt: "Resource index exceeds current count");
    }
    else
    {
      v4 = 0;
      hashTable = v0->hashTable;
      while ( v4 < 256 )
      {
        v6 = *hashTable;
        if ( *hashTable != RESOURCE_TAIL_LINK )
        {
          while ( v3 != 0 )
          {
            v6 = v6->nextOnHashChain;
            --v3;
            if ( v6 == RESOURCE_TAIL_LINK )
              goto LABEL_11;
          }
          Sys_MutexUnlock(handle: &mutex.handle);
          ++v2;
          *((_BYTE *)v6 + 32) |= 0x10u;
          if ( v2 < num )
            goto LABEL_3;
          goto LABEL_13;
        }
LABEL_11:
        ++v4;
        ++hashTable;
      }
    }
    idLib::FatalError(fmt: "Resource index count was incorrect");
    _LN66();
  }
}


// ========================================================================
// $LN66
// EA  : 0x82695BEC
// RVA : 0x00695BEC
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _LN66()
{
  _S13_3 &= ~1u;
}


// ========================================================================
// __unwind$223168
// EA  : 0x82695C0C
// RVA : 0x00695C0C
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_223168()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 80));
}


// ========================================================================
// ?Reload_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82695C38
// RVA : 0x00695C38
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall Reload_f(const idCmdArgs *args)
{
  idResourceList *i; // r29
  const char *resourceTypeName; // r31
  char *v4; // r3
  int num; // r28
  int j; // r30
  idResource *v7; // r3
  idResource *v8; // r31

  if ( idLib::production != PROD_DEVELOPMENT )
  {
    idLib::Printf(fmt: "Only available in development runs\n");
  }
  else if ( args->argc <= 2 )
  {
    ++idResourceList::staleCount;
    common->SyncAllBackgroundOperations(this: common, a2: true);
    for ( i = listOfResourceLists; i != nullptr; i = i->nextResourceList )
    {
      if ( args->argc == 2 )
      {
        resourceTypeName = i->resourceTypeName;
        if ( resourceTypeName == nullptr )
        {
          idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
          JUMPOUT(0x82695D90);
        }
        v4 = idCmdArgs::Argv(this: args, arg: 1);
        if ( idStr::Icmp(s1: resourceTypeName, s2: v4) != 0 )
          continue;
      }
      num = i->num;
      for ( j = 0; j < num; ++j )
      {
        v7 = idResourceList::Index(this: i, index: j);
        v8 = v7;
        if ( (*((_BYTE *)v7 + 32) & 0x80) != 0 && v7->ReloadIfStale(this: v7) )
          v8->List(this: v8);
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: reload [resourceName]\n");
  }
}


// ========================================================================
// ?ResourceErrors_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82695D98
// RVA : 0x00695D98
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall ResourceErrors_f(const idCmdArgs *args)
{
  idResourceList *v1; // r26
  int num; // r24
  int v3; // r28
  int v4; // r29
  int v5; // r9
  idResource **hashTable; // r10
  idResource *v7; // r30
  const char *resourceError; // r29
  idResource *v9; // r3
  const char *str; // r30
  const char *ResourceTypeName; // r3

  v1 = listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    while ( 1 )
    {
      num = v1->num;
      v3 = 0;
      if ( num > 0 )
        break;
LABEL_15:
      v1 = v1->nextResourceList;
      if ( v1 == nullptr )
        return;
    }
LABEL_3:
    v4 = v3;
    if ( (_S13_3 & 1) == 0 )
    {
      _S13_3 |= 1u;
      Sys_MutexCreate(handle: &mutex.handle);
      atexit(func: (void (__fastcall *)())_idResourceList::Mutex_::_2_::_dynamic_atexit_destructor_for__mutex__);
    }
    Sys_MutexLock(handle: &mutex.handle, blocking: true);
    if ( v3 >= v1->num )
    {
      idLib::FatalError(fmt: "Resource index exceeds current count");
    }
    else
    {
      v5 = 0;
      hashTable = v1->hashTable;
      while ( v5 < 256 )
      {
        v7 = *hashTable;
        if ( *hashTable != RESOURCE_TAIL_LINK )
        {
          while ( v4 != 0 )
          {
            v7 = v7->nextOnHashChain;
            --v4;
            if ( v7 == RESOURCE_TAIL_LINK )
              goto LABEL_11;
          }
          Sys_MutexUnlock(handle: &mutex.handle);
          resourceError = v7->resourceError;
          if ( resourceError != nullptr )
          {
            v9 = v7;
            str = v7->name.str;
            ResourceTypeName = idResource::GetResourceTypeName(this: v9);
            idLib::Printf(fmt: "%s:%s:%s\n", ResourceTypeName, str, resourceError);
          }
          if ( ++v3 < num )
            goto LABEL_3;
          goto LABEL_15;
        }
LABEL_11:
        ++v5;
        ++hashTable;
      }
    }
    idLib::FatalError(fmt: "Resource index count was incorrect");
    _LN75();
  }
}


// ========================================================================
// $LN75
// EA  : 0x82695EE0
// RVA : 0x00695EE0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _LN75()
{
  _S13_3 &= ~1u;
}


// ========================================================================
// __unwind$223374
// EA  : 0x82695F00
// RVA : 0x00695F00
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_223374()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 80));
}


// ========================================================================
// ??0idResourceList@@QAA@PBD@Z
// EA  : 0x82695F28
// RVA : 0x00695F28
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idResourceList *__fastcall idResourceList::idResourceList(idResourceList *this, const char *typeName)
{
  int v5; // r11

  this->__vftable = (idResourceList_vtbl *)&idResourceList::`vftable';
  idResourceList::ClearHashTable(this);
  v5 = currentStaticListID;
  this->nextResourceList = listOfResourceLists;
  listOfResourceLists = this;
  this->staticID = v5;
  this->resourceTypeName = typeName;
  currentStaticListID = v5 + 1;
  return this;
}


// ========================================================================
// ?GetLoadedResources@idResourceList@@QBAXAAV?$idList@PAVidResource@@$0GD@@@@Z
// EA  : 0x82695FA0
// RVA : 0x00695FA0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idResourceList::GetLoadedResources(idResourceList *this, idList<idVehicleState *,5> *resourceList)
{
  void **p_handle; // r25
  int v5; // r9
  int v6; // r8
  int v7; // r7
  __int64 v8; // r6
  idResource **hashTable; // r27
  int v10; // r26
  idResource *v11; // r11
  idResource *v12; // r30
  unsigned __int64 v13; // [sp+8h] [-A8h]
  idResource **list; // [sp+50h] [-60h] BYREF
  idSort_Quick<idResource *,idSort_ResourceName> v15; // [sp+54h] [-5Ch] BYREF
  idSysMutex *v16; // [sp+58h] [-58h]

  v16 = idResourceList::Mutex();
  p_handle = &v16->handle;
  Sys_MutexLock(handle: &v16->handle, blocking: true);
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idList<idThread *,58>::Clear(this: resourceList);
  hashTable = this->hashTable;
  v10 = 256;
  v11 = RESOURCE_TAIL_LINK;
  do
  {
    v12 = *hashTable;
    list = (idResource **)*hashTable;
    if ( list != (idResource **)v11 )
    {
      do
      {
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)resourceList,
          obj: (const encounterGroupRole_t *)&list);
        v11 = RESOURCE_TAIL_LINK;
        v12 = v12->nextOnHashChain;
        list = (idResource **)v12;
      }
      while ( v12 != RESOURCE_TAIL_LINK );
    }
    --v10;
    ++hashTable;
  }
  while ( v10 != 0 );
  v15.__vftable = (idSort_Quick<idResource *,idSort_ResourceName>_vtbl *)&idSort_ResourceName::`vftable';
  if ( resourceList->list != nullptr )
  {
    HIDWORD(v8) = resourceList->num;
    list = (idResource **)resourceList->list;
    idSort_Quick<idResource *,idSort_ResourceName>::Sort(this: &v15, num: v8, a3: v7, a4: v6, a5: v5, a6: v13);
  }
  v15.__vftable = (idSort_Quick<idResource *,idSort_ResourceName>_vtbl *)&idSort<idResource *>::`vftable';
  idMem::PopHeap(this: &mem);
  Sys_MutexUnlock(handle: p_handle);
}


// ========================================================================
// __unwind$223646
// EA  : 0x82696088
// RVA : 0x00696088
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_223646()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$223647
// EA  : 0x826960B0
// RVA : 0x006960B0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_223647()
{
  int v0; // r12

  idSort_ResourceName::~idSort_ResourceName(this: (idSort_ResourceMemory *)(v0 - 176 + 84));
}


// ========================================================================
// ?AddNetworkResource@idResourceList@@SAHPBVidResource@@@Z
// EA  : 0x826960D8
// RVA : 0x006960D8
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

int __fastcall idResourceList::AddNetworkResource(
        const idResource *r,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        const idResource *a12)
{
  int v13; // r28
  const char *str; // r4
  int v15; // r5
  const char *resourceTypeName; // r11
  int v17; // r31
  const char *v18; // r4

  a12 = r;
  if ( networkResourceInfo.networkResources.num >= 0xFFFFu )
    idLib::Error(fmt: "Too many network resources.");
  if ( resource_showLoads.valueInteger != 0 )
    idLib::Printf(fmt: "Added network resource: %s\n", r->name.str);
  if ( common->IsInGame(this: common) )
    idLib::Warning(fmt: "Registering network resource in game. %s", r->name.str);
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v13 = idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&networkResourceInfo,
          obj: (const encounterGroupRole_t *)&a12);
  idMem::PopHeap(this: &mem);
  str = r->name.str;
  v15 = 0;
  if ( *str != 0 )
  {
    do
      ++v15;
    while ( str[v15] != 0 );
  }
  CRC32_UpdateChecksum(crcvalue: &networkResourceInfo.networkChecksum, data: str, length: v15);
  resourceTypeName = r->GetResourceList(this: r)->resourceTypeName;
  if ( resourceTypeName == nullptr )
    idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
  v17 = 0;
  if ( *resourceTypeName != 0 )
  {
    do
      ++v17;
    while ( resourceTypeName[v17] != 0 );
  }
  v18 = r->GetResourceList(this: r)->resourceTypeName;
  if ( v18 == nullptr )
    idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
  CRC32_UpdateChecksum(crcvalue: &networkResourceInfo.networkChecksum, data: v18, length: v17);
  return v13;
}


// ========================================================================
// ?ResetNetworkResources@idResourceList@@SAXXZ
// EA  : 0x82696250
// RVA : 0x00696250
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

static void __fastcall idResourceList::ResetNetworkResources()
{
  char v0; // r11
  int num; // r9
  int v2; // r8
  int v3; // r11
  const idResource *v4; // r6
  char v5; // r11
  int firstDynamicNetworkResource; // r30
  char v7; // r11
  int size; // r11
  bool v9; // cr56

  if ( net_forceNetDeclExchange.valueInteger != 0 )
    v0 = 1;
  else
    v0 = ((idLib::production >= PROD_DEVELOPMENT) + ((unsigned int)idLib::production >= PROD_PRODUCTION)) & 1;
  num = networkResourceInfo.networkResources.num;
  v2 = v0 != 0 ? 0 : networkResourceInfo.firstDynamicNetworkResource;
  if ( v2 < networkResourceInfo.networkResources.num )
  {
    v3 = v2;
    do
    {
      v4 = networkResourceInfo.networkResources.list[v3];
      if ( v4 != nullptr )
      {
        v4->networkID = -1;
        num = networkResourceInfo.networkResources.num;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < num );
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( net_forceNetDeclExchange.valueInteger != 0 )
    v5 = 1;
  else
    v5 = ((idLib::production >= PROD_DEVELOPMENT) + ((unsigned int)idLib::production >= PROD_PRODUCTION)) & 1;
  if ( v5 != 0 )
  {
    if ( networkResourceInfo.networkResources.listStatic == 0 || networkResourceInfo.networkResources.listStatic == 2 )
    {
      if ( networkResourceInfo.networkResources.list != nullptr )
        idMem::Free(this: &mem, ptr: networkResourceInfo.networkResources.list, align: ALIGN_16);
      networkResourceInfo.networkResources.list = nullptr;
      networkResourceInfo.networkResources.size = 0;
    }
    size = 0;
    goto LABEL_29;
  }
  firstDynamicNetworkResource = networkResourceInfo.firstDynamicNetworkResource;
  if ( networkResourceInfo.firstDynamicNetworkResource <= 0
    || (v7 = 1, networkResourceInfo.networkResources.num < networkResourceInfo.firstDynamicNetworkResource) )
  {
    v7 = 0;
  }
  if ( v7 == 0 )
    idLib::Error(fmt: "Dynamic resources have not been initialized for networking");
  size = networkResourceInfo.networkResources.size;
  v9 = firstDynamicNetworkResource < networkResourceInfo.networkResources.size;
  if ( firstDynamicNetworkResource <= networkResourceInfo.networkResources.size )
  {
LABEL_21:
    if ( v9 )
    {
      networkResourceInfo.networkResources.num = firstDynamicNetworkResource;
      goto LABEL_30;
    }
LABEL_29:
    networkResourceInfo.networkResources.num = size;
    goto LABEL_30;
  }
  if ( idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&networkResourceInfo,
         newsize: firstDynamicNetworkResource) )
  {
    size = networkResourceInfo.networkResources.size;
    v9 = firstDynamicNetworkResource < networkResourceInfo.networkResources.size;
    goto LABEL_21;
  }
LABEL_30:
  idMem::PopHeap(this: &mem);
  networkResourceInfo.networkChecksum = networkResourceInfo.staticNetworkChecksum;
}


// ========================================================================
// ?List_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82696418
// RVA : 0x00696418
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall List_f(const idCmdArgs *args, int a2, __int64 a3, unsigned __int64 a4)
{
  int argc; // r11
  char v6; // r28
  char v7; // r17
  int v8; // r30
  const char **v9; // r29
  const char *v10; // r3
  bool v11; // cr56
  unsigned __int8 listStatic; // r19
  idResource **list; // r23
  const char *v14; // r28
  unsigned int v15; // r21
  char *v16; // r11
  __int64 v17; // r10
  bool v18; // zf
  char v19; // r26
  bool v20; // r11
  idResourceList *v21; // r27
  BOOL v22; // r25
  const char *resourceTypeName; // r30
  char *v24; // r3
  const char *v25; // r11
  int v26; // r10
  int num; // r28
  int i; // r30
  int v29; // r29
  const char *v30; // r4
  int v31; // r29
  idResourceList *v32; // r30
  const char *v33; // r4
  unsigned int v34; // r29
  __int64 v35; // r10
  const char *v36; // r30
  const char *v37; // r25
  idResource **v38; // r27
  idResource *v39; // r22
  double v40; // r4
  double v41; // r4
  idResource **v42; // r29
  const char *j; // r30
  unsigned __int64 v44; // [sp+8h] [-118h]
  idSort_Quick<idResource *,idSort_ResourceMemory> v45; // [sp+50h] [-D0h] BYREF
  idSort_Quick<idResource *,idSort_ResourceName> v46; // [sp+54h] [-CCh] BYREF
  _QWORD v47[3]; // [sp+58h] [-C8h] BYREF
  idList<enum encounterGroupRole_t,5> v48; // [sp+70h] [-B0h] BYREF

  v6 = 0;
  v7 = 0;
  v8 = 2;
  HIDWORD(v47[0]) = args->argc;
  argc = HIDWORD(v47[0]);
  if ( SHIDWORD(v47[0]) > 2 )
  {
    v9 = (const char **)&args->argv[2];
    do
    {
      if ( v8 < 0 || v8 >= argc )
        v10 = &byte_8200D768;
      else
        v10 = *v9;
      if ( idStr::Cmp(s1: v10, s2: "memory") != 0 )
        v6 = 1;
      else
        v7 = 1;
      argc = args->argc;
      ++v8;
      ++v9;
      v11 = v8 < args->argc;
      HIDWORD(v47[0]) = args->argc;
    }
    while ( v11 );
  }
  HIDWORD(v47[0]) = argc;
  if ( argc < 2 || v6 != 0 )
  {
    idLib::Printf(fmt: "Usage: list <resourceType | all> [memory]\n");
    return;
  }
  listStatic = 0;
  list = nullptr;
  v14 = nullptr;
  *(_WORD *)&v48.memTag = 1280;
  memset(&v48, 0, 14);
  v15 = 0;
  v16 = args->argv[1];
  LODWORD(v17) = "all";
  do
  {
    HIDWORD(v17) = (unsigned __int8)*v16;
    LODWORD(a4) = *(unsigned __int8 *)v17;
    v18 = HIDWORD(v17) == 0;
    HIDWORD(v17) -= a4;
    if ( v18 )
      break;
    ++v16;
    LODWORD(v17) = v17 + 1;
  }
  while ( HIDWORD(v17) == 0 );
  v19 = 0;
  v20 = (_cntlzw(HIDWORD(v17)) & 0x20) != 0;
  v21 = listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    v22 = v20;
    while ( 1 )
    {
      if ( v22 )
        goto LABEL_24;
      resourceTypeName = v21->resourceTypeName;
      if ( resourceTypeName == nullptr )
      {
        idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
_LN195_0:
        v30 = &byte_8200D768;
        goto LABEL_36;
      }
      HIDWORD(v47[0]) = v21->resourceTypeName;
      v24 = idCmdArgs::Argv(this: args, arg: 1);
      v25 = resourceTypeName;
      do
      {
        v26 = *(unsigned __int8 *)v25;
        HIDWORD(v17) = (unsigned __int8)*v24;
        v18 = v26 == 0;
        LODWORD(v17) = v26 - HIDWORD(v17);
        if ( v18 )
          break;
        ++v25;
        ++v24;
      }
      while ( (_DWORD)v17 == 0 );
      if ( (_DWORD)v17 == 0 )
      {
LABEL_24:
        num = v21->num;
        v19 = 1;
        if ( num == 0 && !v22 )
          idLib::Printf(fmt: "0 resources.\n");
        for ( i = 0; i < num; v15 += *(_DWORD *)(v29 + 4) )
        {
          HIDWORD(v47[0]) = idResourceList::Index(this: v21, index: i);
          v29 = HIDWORD(v47[0]);
          idList<idAnimWebBlendTree *,5>::Append(this: &v48, obj: (const encounterGroupRole_t *)v47);
          ++i;
        }
      }
      v21 = v21->nextResourceList;
      if ( v21 == nullptr )
      {
        listStatic = v48.listStatic;
        list = (idResource **)v48.list;
        v14 = (const char *)v48.num;
        break;
      }
    }
  }
  if ( v19 != 0 )
    goto _LN196_0;
  if ( args->argc <= 1 )
    goto _LN195_0;
  v30 = args->argv[1];
LABEL_36:
  idLib::Printf(fmt: "Unknown resource type '%s'\n", v30);
  idLib::Printf(fmt: "Valid type names are...\n");
  v31 = 0;
  v32 = listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    v14 = "\t%s\n";
    while ( 1 )
    {
      v33 = v32->resourceTypeName;
      if ( v33 == nullptr )
        break;
      HIDWORD(v47[0]) = v32->resourceTypeName;
      idLib::Printf(fmt: "\t%s\n", v33);
      ++v31;
      v32 = v32->nextResourceList;
      if ( v32 == nullptr )
        goto LABEL_40;
    }
    idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
_LN196_0:
    if ( v7 != 0 )
    {
      v45.__vftable = (idSort_Quick<idResource *,idSort_ResourceMemory>_vtbl *)&idSort_ResourceMemory::`vftable';
      if ( list != nullptr )
        idSort_Quick<idResource *,idSort_ResourceMemory>::Sort(
          this: &v45,
          base: list,
          num: (unsigned int)v14,
          a4: a3,
          a5: a4,
          a6: v17);
      v34 = 0;
      v45.__vftable = (idSort_Quick<idResource *,idSort_ResourceMemory>_vtbl *)&idSort<idResource *>::`vftable';
      if ( (int)v14 > 0 )
      {
        HIDWORD(v35) = &unk_821C0000;
        v36 = v14 - 1;
        v37 = v14;
        v38 = list;
        do
        {
          v39 = *v38;
          LODWORD(v35) = (*v38)->trackedMemory;
          v47[0] = v35;
          v40 = (float)((float)v35 * (float)0.0009765625);
          idLib::Printf(fmt: (const char *)HIDWORD(v40), LODWORD(v40));
          v34 += v39->trackedMemory;
          v39->List(this: v39);
          if ( v36 == (const char *)(10 * ((int)v36 / 10)) )
          {
            LODWORD(v35) = v15;
            v47[1] = v35;
            v47[2] = __PAIR64__(v15, v34);
            v41 = (float)((float)((float)v35 - (float)__SPAIR64__(v15, v34)) * (float)0.00000095367432);
            idLib::Printf(
              fmt: (const char *)HIDWORD(v41),
              LODWORD(v41),
              (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v35 * (float)0.00000095367432)));
          }
          --v37;
          ++v38;
          --v36;
        }
        while ( v37 != nullptr );
      }
    }
    else
    {
      v46.__vftable = (idSort_Quick<idResource *,idSort_ResourceName>_vtbl *)&idSort_ResourceName::`vftable';
      if ( list != nullptr )
      {
        HIDWORD(a3) = v14;
        idSort_Quick<idResource *,idSort_ResourceName>::Sort(
          this: &v46,
          num: a3,
          a3: SHIDWORD(a4),
          a4,
          a5: SHIDWORD(v17),
          a6: v44);
      }
      v46.__vftable = (idSort_Quick<idResource *,idSort_ResourceName>_vtbl *)&idSort<idResource *>::`vftable';
      if ( (int)v14 > 0 )
      {
        v42 = list - 1;
        for ( j = v14; j != nullptr; --j )
        {
          ++v42;
          (*v42)->List(this: *v42);
        }
      }
    }
    if ( (listStatic == 0 || listStatic == 2) && list != nullptr )
      goto LABEL_43;
    return;
  }
LABEL_40:
  idLib::Printf(fmt: "\n%i resource types\n", v31);
  if ( (listStatic == 0 || listStatic == 2) && list != nullptr )
LABEL_43:
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// $LN176
// EA  : 0x82696910
// RVA : 0x00696910
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _LN176()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$223932
// EA  : 0x82696938
// RVA : 0x00696938
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_223932()
{
  int v0; // r12

  idSort_ResourceName::~idSort_ResourceName(this: (idSort_ResourceMemory *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$223933
// EA  : 0x82696960
// RVA : 0x00696960
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_223933()
{
  int v0; // r12

  idSort_ResourceName::~idSort_ResourceName(this: (idSort_ResourceMemory *)(v0 - 288 + 84));
}


// ========================================================================
// ?InitNetworkID@idResource@@QBAHXZ
// EA  : 0x82696988
// RVA : 0x00696988
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

int __fastcall idResource::InitNetworkID(idResource *this)
{
  int v2; // r10
  int v3; // r9
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5
  int v8; // r4
  const char *str; // r4
  const char *v10; // r3
  int v12; // [sp+8h] [-68h]
  int v13; // [sp+Ch] [-64h]
  int v14; // [sp+10h] [-60h]
  const idResource *v15; // [sp+14h] [-5Ch]

  if ( this->networkID == -1 )
  {
    if ( common->IsMultiplayer(this: common)
      && idLib::production == PROD_LOADED
      && net_forceNetDeclExchange.valueInteger == 0 )
    {
      idLib::Error(fmt: "Network resource loaded when in PROD_LOADED mode: %s", this->name.str);
    }
    v3 = common->IsMultiplayer(this: common);
    if ( v3 != 0 )
    {
      v3 = common->IsServer(this: common);
      if ( v3 == 0 )
      {
        v3 = common->IsInGame(this: common);
        if ( v3 != 0 )
        {
          str = this->name.str;
          v10 = "Client trying to add network resource: %s";
          if ( resource_errorOnClientAddNetResource.valueInteger != 0 )
            idLib::Error(fmt: "Client trying to add network resource: %s", str);
          idLib::Warning(fmt: v10, str);
        }
      }
    }
    this->networkID = idResourceList::AddNetworkResource(
                        r: this,
                        a2: v8,
                        a3: v7,
                        a4: v6,
                        a5: v5,
                        a6: v4,
                        a7: v3,
                        a8: v2,
                        a9: v12,
                        a10: v13,
                        a11: v14,
                        a12: v15);
  }
  return this->networkID;
}


// ========================================================================
// ?GetNetworkID@idResource@@QBAH_N@Z
// EA  : 0x82696AC0
// RVA : 0x00696AC0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

int __fastcall idResource::GetNetworkID(idResource *this, bool alloc)
{
  if ( alloc && this->networkID == -1 )
    idResource::InitNetworkID(this);
  return this->networkID;
}


// ========================================================================
// ?UnRegisterNetworkResource@idResourceList@@SAXPAVidResource@@@Z
// EA  : 0x82696B08
// RVA : 0x00696B08
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idResourceList::UnRegisterNetworkResource(idResource *resource)
{
  int networkID; // r11

  networkID = resource->networkID;
  if ( networkID != -1 )
  {
    networkResourceInfo.networkResources.list[networkID] = nullptr;
    resource->networkID = -1;
  }
}


// ========================================================================
// ?Lookup@idResourceList@@ABAPAVidResource@@PBD@Z
// EA  : 0x82696B40
// RVA : 0x00696B40
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idResource *__fastcall idResourceList::Lookup(idResourceList *this, const char *canonicalName)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idSysMutex *v6; // r27
  unsigned __int8 v7; // r3
  idResource *v8; // r11
  idResource *v9; // r29
  int v10; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v12; // r30
  int v13; // r3
  __int64 totalTicks; // r11
  __int64 v15; // r9
  idPLog *v17; // r28
  idPLog::logEntry_t *v18; // r30
  int v19; // r3
  __int64 v20; // r11
  __int64 v21; // r9
  const char *str; // [sp+54h] [-4Ch]
  idPLogScope v23; // [sp+58h] [-48h] BYREF

  RD_EventBegin(name: "idResourceList::Lookup");
  LODWORD(v4) = "idResourceList::Lookup";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v23, pl: &::pLog, gMask: v4, label: v5);
  v6 = idResourceList::Mutex();
  Sys_MutexLock(handle: &v6->handle, blocking: true);
  v7 = idStr::IHash(string: canonicalName);
  v8 = RESOURCE_TAIL_LINK;
  v9 = this->hashTable[v7];
  if ( v9 == RESOURCE_TAIL_LINK )
    goto LABEL_7;
  while ( 1 )
  {
    str = v9->name.str;
    if ( str != nullptr )
    {
      v10 = idStr::Cmp(s1: str, s2: canonicalName);
      v8 = RESOURCE_TAIL_LINK;
      if ( v10 == 0 )
        break;
    }
    v9 = v9->nextOnHashChain;
    if ( v9 == v8 )
      goto LABEL_7;
  }
  if ( v9 == RESOURCE_TAIL_LINK )
  {
LABEL_7:
    Sys_MutexUnlock(handle: &v6->handle);
    if ( v23.logIndex >= 0 )
    {
      pLog = v23.pLog;
      v12 = &v23.pLog->logEntries.list[v23.logIndex];
      v13 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v12->totalTicks;
      HIDWORD(totalTicks) = v12->parent;
      LODWORD(v15) = v13 - totalTicks;
      v12->totalTicks = v15;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    return nullptr;
  }
  else
  {
    Sys_MutexUnlock(handle: &v6->handle);
    if ( v23.logIndex >= 0 )
    {
      v17 = v23.pLog;
      v18 = &v23.pLog->logEntries.list[v23.logIndex];
      v19 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v20 = v18->totalTicks;
      HIDWORD(v20) = v18->parent;
      LODWORD(v21) = v19 - v20;
      v18->totalTicks = v21;
      v17->lastEntry = HIDWORD(v20);
    }
    RD_EventEnd();
    return v9;
  }
}


// ========================================================================
// __unwind$224378
// EA  : 0x82696C90
// RVA : 0x00696C90
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_224378()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$224379
// EA  : 0x82696CB8
// RVA : 0x00696CB8
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_224379()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$224380
// EA  : 0x82696CE0
// RVA : 0x00696CE0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_224380()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 160 + 80));
}


// ========================================================================
// ?FindExisting@idResourceList@@QBAPAVidResource@@PBD_N@Z
// EA  : 0x82696D10
// RVA : 0x00696D10
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idResource *__fastcall idResourceList::FindExisting(idResourceList *this, char *name, bool skipStaleCheck)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  char *data; // r26
  idResource *v8; // r27
  int i; // r29
  const char *resourceTypeName; // r4
  char v12; // r9
  int v13; // r3
  int v14; // r9
  int v15; // r28
  int v16; // r3
  int v17; // r10
  unsigned int v18; // r9
  unsigned int v19; // r30
  idPLogScope v20; // [sp+50h] [-8A0h] BYREF
  const char *v21; // [sp+58h] [-898h]
  idStr v22; // [sp+60h] [-890h] BYREF
  char v23; // [sp+80h] [-870h] BYREF
  idStrStatic<1024> v24; // [sp+480h] [-470h] BYREF

  RD_EventBegin(name: "idResourceList::FindExisting");
  LODWORD(v5) = "idResourceList::FindExisting";
  HIDWORD(v5) = 2;
  idPLogScope::idPLogScope(this: &v20, pl: &pLog, gMask: v5, label: v6);
  v22.baseBuffer[0] = 0;
  data = name;
  v23 = 0;
  v22.data = &v23;
  v22.len = 0;
  v22.allocedAndFlag = -2147482624;
  if ( !idStr::IsNameCanonical(name) )
  {
    idStrStatic<1024>::idStrStatic<1024>(this: &v24, text: name);
    v22.len = v24.len;
    memcpy(Dst: v22.data, Src: v24.data, Size: v24.len + 1);
    idStr::FreeData(this: &v24);
    idStr::MakeNameCanonical(this: &v22);
    data = v22.data;
  }
  v8 = idResourceList::Lookup(this, canonicalName: data);
  if ( v8 != nullptr )
  {
    if ( resource_showLoads.valueInteger == 2 )
    {
      for ( i = 0; i < idResourceList::loadResourceRecursionLevel; ++i )
        idLib::Printf(fmt: " ");
      resourceTypeName = this->resourceTypeName;
      if ( resourceTypeName == nullptr )
        idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
      v21 = resourceTypeName;
      idLib::Printf(fmt: "idResourceList::Load( %s : %s )\n", resourceTypeName, data);
    }
    v12 = 0;
    if ( !idResourceList::deferAllResourceLoads )
    {
      if ( (*((_BYTE *)v8 + 32) & 8) != 0
        && (idResourceList::loadResourceRecursionLevel == 0 || (*((_BYTE *)v8 + 32) & 0x40) != 0) )
      {
        v12 = 1;
        *((_BYTE *)v8 + 32) = *((_BYTE *)v8 + 32) & 0x77 | 0x80;
      }
      if ( (*((_BYTE *)v8 + 32) & 0x10) != 0 && (*((_BYTE *)v8 + 32) & 0x80) != 0 )
      {
        v12 = 1;
        *((_BYTE *)v8 + 32) &= ~0x10u;
      }
      if ( v12 != 0 )
      {
        v13 = idMem::BytesCurrentlyAllocated(this: &mem);
        v14 = idResourceList::loadResourceRecursionLevel;
        v15 = v13;
        ++idResourceList::loadResourceRecursionLevel;
        idResourceList::recursiveLoads.ptr[v14] = v8;
        idResource::Load(this: v8);
        --idResourceList::loadResourceRecursionLevel;
        v16 = idMem::BytesCurrentlyAllocated(this: &mem);
        v17 = idResourceList::loadResourceRecursionLevel;
        v18 = (((unsigned int)(v16 - v15) >> 31) - 1) & (v16 - v15);
        memoryFromRecursionLevel.ptr[v17] = v18
                                          + memoryFromRecursionLevel.ptr[idResourceList::loadResourceRecursionLevel];
        v19 = (((v18 - memoryFromRecursionLevel.ptr[v17 + 1]) >> 31) - 1)
            & (v18 - memoryFromRecursionLevel.ptr[v17 + 1]);
        v8->trackedMemory = this->AllocSize(this) + v19;
      }
      if ( resourceLoadCallback != nullptr && (*((_BYTE *)v8 + 32) & 0x80) != 0 && !idLib::dontTrack )
        resourceLoadCallback(a1: v8);
    }
    idStr::FreeData(this: &v22);
    idPLogScope::~idPLogScope(this: &v20);
    RD_EventEnd();
    return v8;
  }
  else
  {
    idStr::FreeData(this: &v22);
    idPLogScope::~idPLogScope(this: &v20);
    RD_EventEnd();
    return nullptr;
  }
}


// ========================================================================
// $M224674_0
// EA  : 0x82697044
// RVA : 0x00697044
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __noreturn _M224674_0()
{
  --idResourceList::loadResourceRecursionLevel;
  CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}


// ========================================================================
// $LN133
// EA  : 0x8269706C
// RVA : 0x0069706C
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _LN133()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2288 + 2208));
}


// ========================================================================
// __unwind$224500
// EA  : 0x82697094
// RVA : 0x00697094
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_224500()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2288 + 80));
}


// ========================================================================
// __unwind$224501
// EA  : 0x826970BC
// RVA : 0x006970BC
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_224501()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2288 + 96));
}


// ========================================================================
// ?Add@idResourceList@@QAAXPAVidResource@@@Z
// EA  : 0x826970F0
// RVA : 0x006970F0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idResourceList::Add(idResourceList *this, idResourceList_vtbl *ptr)
{
  idSysMutex *v4; // r28
  char *AllocSize; // r3
  int v6; // r3
  char v7; // r11
  idResource *v8; // r4
  int v9; // r11

  v4 = idResourceList::Mutex();
  Sys_MutexLock(handle: &v4->handle, blocking: true);
  if ( ptr[1].dtr_idResourceList != nullptr )
    idLib::FatalError(fmt: "Resource with a set link added to a list");
  AllocSize = (char *)ptr->AllocSize;
  if ( AllocSize == "unnamed" || (v6 = idStr::Cmp(s1: AllocSize, s2: "unnamed"), v7 = 0, v6 == 0) )
    v7 = 1;
  if ( v7 != 0 )
    idLib::FatalError(fmt: "idResourceList::Add called on UNNAMED_RESOURCE");
  v8 = idResourceList::Lookup(this, canonicalName: (const char *)ptr->AllocSize);
  if ( v8 != nullptr )
    idResourceList::Remove_Locked(this, ptr: v8);
  v9 = 4 * ((unsigned __int8)idStr::IHash(string: (const char *)ptr->AllocSize) + 5);
  ptr[1].dtr_idResourceList = *(void (__fastcall **)(idResourceList *))((char *)&this->__vftable + v9);
  *(idResourceList_vtbl **)((char *)&this->__vftable + v9) = ptr;
  ptr[1].Alloc = (idResource *(__fastcall *)(idResourceList *, const char *))this;
  ++this->num;
  Sys_MutexUnlock(handle: &v4->handle);
}


// ========================================================================
// $LN27_0
// EA  : 0x826971D4
// RVA : 0x006971D4
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _LN27_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?Load@idResourceList@@QAAPAVidResource@@PBD_N1@Z
// EA  : 0x82697208
// RVA : 0x00697208
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idResource *__fastcall idResourceList::Load(idResourceList *this, char *name, bool makeDefault, bool skipStaleCheck)
{
  idMem *v4; // r27
  int v5; // r25
  const char *resourceTypeName; // r3
  bool v11; // r21
  idResource *Existing; // r3
  unsigned __int8 *v13; // r30
  int v15; // r30
  const char *v16; // r4
  const char *v17; // r4
  const char *v18; // r4
  unsigned __int8 v19; // r11
  bool v20; // cr58
  const char *v21; // r4
  int v22; // r11
  int v23; // r3
  int v24; // r11
  unsigned int v25; // r10

  resourceTypeName = this->resourceTypeName;
  if ( resourceTypeName == nullptr )
    idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
  v11 = idLib::PushWarningInfo(type: resourceTypeName, name);
  Existing = idResourceList::FindExisting(this, name, skipStaleCheck);
  v13 = (unsigned __int8 *)Existing;
  if ( Existing != nullptr )
  {
    if ( !makeDefault && Existing->resourceError != nullptr )
    {
      if ( v11 )
        idLib::PopWarningInfo();
      return nullptr;
    }
    if ( !v11 )
      return (idResource *)v13;
    goto LABEL_51;
  }
  if ( resource_showLoads.valueInteger >= 1 )
  {
    v15 = 0;
    if ( idResourceList::loadResourceRecursionLevel > 0 )
    {
      v4 = (idMem *)" ";
      do
      {
        idLib::Printf(fmt: " ");
        ++v15;
      }
      while ( v15 < idResourceList::loadResourceRecursionLevel );
    }
    v16 = this->resourceTypeName;
    if ( v16 == nullptr )
      idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
    idLib::Printf(fmt: "%s::LoadResource( %s )\n", v16, name);
  }
  if ( idLib::production == PROD_LOADED && strstr(str1: name, str2: ".bswf") == nullptr )
  {
    v17 = this->resourceTypeName;
    if ( v17 == nullptr )
      idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
    idLib::Warning(fmt: "Resource loaded in production mode: %s : %s", v17, name);
  }
  v13 = &consoleFont[21088];
  if ( common->IsInGame(this: common) && !common->IsToolActive(this: common) )
  {
    if ( resource_errorInGame.valueInteger == 1 )
    {
      v18 = this->resourceTypeName;
      if ( v18 == nullptr )
        idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
      idLib::Warning(fmt: "resource_errorInGame enabled: Resource loaded in game: %s : %s", v18, name);
    }
    else if ( resource_errorInGame.valueInteger == 2 )
    {
      v21 = this->resourceTypeName;
      if ( v21 == nullptr )
        idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
      idLib::FatalError(fmt: "resource_errorInGame enabled: Resource loaded in game: %s : %s", v21, name);
      goto _LN127;
    }
  }
  v4 = &mem;
  v5 = idMem::BytesCurrentlyAllocated(this: &mem);
  v13 = (unsigned __int8 *)this->Alloc(this, a2: name);
  idResourceList::Add(this, ptr: (idResourceList_vtbl *)v13);
  v19 = v13[32] | 0x80;
  v13[32] = v19;
  if ( idResourceList::deferAllResourceLoads )
  {
    v13[32] = v19 | 8;
    v20 = !v11;
    goto LABEL_50;
  }
_LN127:
  if ( idResourceList::loadResourceRecursionLevel > 0 && idLib::production == PROD_PRODUCTION )
  {
    v13[32] = v19 | 8;
    if ( v11 )
      goto LABEL_51;
    return (idResource *)v13;
  }
  v13[32] = v19 | 0x20;
  v22 = idResourceList::loadResourceRecursionLevel + 1;
  idResourceList::recursiveLoads.ptr[idResourceList::loadResourceRecursionLevel] = (idResource *)v13;
  idResourceList::loadResourceRecursionLevel = v22;
  memoryFromRecursionLevel.ptr[v22] = 0;
  idResource::Load(this: (idResource *)v13);
  if ( idLib::production == PROD_DEVELOPMENT && !skipStaleCheck )
  {
    idResourceList::insideStaleCheck = true;
    (*(void (__fastcall **)(unsigned __int8 *))(*(_DWORD *)v13 + 8))(a1: v13);
    idResourceList::insideStaleCheck = false;
  }
  --idResourceList::loadResourceRecursionLevel;
  v13[32] &= ~0x20u;
  v23 = idMem::BytesCurrentlyAllocated(this: v4);
  v24 = idResourceList::loadResourceRecursionLevel;
  v25 = (((unsigned int)(v23 - v5) >> 31) - 1) & (v23 - v5);
  memoryFromRecursionLevel.ptr[v24] = v25 + memoryFromRecursionLevel.ptr[idResourceList::loadResourceRecursionLevel];
  *((_DWORD *)v13 + 1) += (((v25 - memoryFromRecursionLevel.ptr[v24 + 1]) >> 31) - 1)
                        & (v25 - memoryFromRecursionLevel.ptr[v24 + 1]);
  if ( makeDefault || *((_DWORD *)v13 + 5) == 0 )
  {
    if ( resourceLoadCallback != nullptr && !idLib::dontTrack )
      resourceLoadCallback(a1: (idResource *)v13);
    v20 = !v11;
LABEL_50:
    if ( !v20 )
LABEL_51:
      idLib::PopWarningInfo();
    return (idResource *)v13;
  }
  if ( !v11 )
    return nullptr;
  idLib::PopWarningInfo();
  return nullptr;
}


// ========================================================================
// $M224906
// EA  : 0x82697668
// RVA : 0x00697668
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __noreturn _M224906()
{
  idResourceList::insideStaleCheck = false;
  --idResourceList::loadResourceRecursionLevel;
  CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}


// ========================================================================
// $LN128_0
// EA  : 0x8269769C
// RVA : 0x0069769C
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _LN128_0()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 192 + 80));
}


// ========================================================================
// ?RegisterNetworkResource@idResourceList@@SAXPBD0H@Z
// EA  : 0x826976C8
// RVA : 0x006976C8
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idResourceList::RegisterNetworkResource(const char *typeName, char *name, int networkID)
{
  idResourceList *v6; // r3
  idResource *v7; // r30
  int v8; // [sp+50h] [-40h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( networkID >= networkResourceInfo.networkResources.num )
  {
    v8 = 0;
    idList<idRenderModelCommitted *,5>::SetNum(
      this: (idList<int,5> *)&networkResourceInfo,
      newNum: networkID + 1,
      initValue: &v8);
  }
  idMem::PopHeap(this: &mem);
  v6 = idResourceList::ForTypeName(typeName);
  v7 = idResourceList::Load(this: v6, name, makeDefault: true, skipStaleCheck: false);
  if ( v7 != nullptr )
  {
    if ( common->IsInGame(this: common) )
      idLib::Warning(fmt: "Registering network resource in game. type: %s name: %s id: %d ", typeName, name, networkID);
    networkResourceInfo.networkResources.list[networkID] = v7;
    v7->networkID = networkID;
  }
  else
  {
    idLib::Warning(fmt: "RegisterNetworkResource: NULL resource [%s] %s", typeName, name);
  }
}


// ========================================================================
// ?resourceInfo_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826977C0
// RVA : 0x006977C0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall resourceInfo_f(const idCmdArgs *args)
{
  idResourceList *i; // r30
  char *v3; // r3
  idResource *Existing; // r3
  idResource *v5; // r31
  const char *str; // r27
  int v7; // r26
  const char *ResourceTypeName; // r3

  if ( args->argc == 2 )
  {
    for ( i = listOfResourceLists; i != nullptr; i = i->nextResourceList )
    {
      v3 = idCmdArgs::Argv(this: args, arg: 1);
      Existing = idResourceList::FindExisting(this: i, name: v3, skipStaleCheck: false);
      v5 = Existing;
      if ( Existing != nullptr )
      {
        str = Existing->name.str;
        v7 = Existing->trackedMemory / 1024;
        ResourceTypeName = idResource::GetResourceTypeName(this: Existing);
        idLib::Printf(fmt: "\n%p %s : %s = %ik\n", v5, ResourceTypeName, str, v7);
        v5->Print(this: v5);
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: resourceInfo <resourceName>\n");
  }
}


// ========================================================================
// ?Load_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82697888
// RVA : 0x00697888
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall Load_f(const idCmdArgs *args)
{
  idResourceList *v2; // r3
  idResourceList *v3; // r30
  char *v4; // r4
  idResource *Existing; // r3
  char *v6; // r4
  const char *v7; // r5

  if ( args->argc == 3 )
  {
    v2 = idResourceList::ForTypeName(typeName: args->argv[1]);
    v3 = v2;
    if ( v2 != nullptr )
    {
      if ( args->argc <= 2 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[2];
      Existing = idResourceList::FindExisting(this: v2, name: v4, skipStaleCheck: false);
      if ( Existing != nullptr )
        *((_BYTE *)Existing + 32) |= 0x10u;
      if ( args->argc <= 2 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[2];
      if ( idResourceList::Load(this: v3, name: v6, makeDefault: false, skipStaleCheck: false) == nullptr )
      {
        if ( args->argc <= 2 )
          v7 = &byte_8200D768;
        else
          v7 = args->argv[2];
        if ( args->argc <= 1 )
          idLib::Printf(fmt: "Couldn't load %s:%s\n", &byte_8200D768, v7);
        else
          idLib::Printf(fmt: "Couldn't load %s:%s\n", args->argv[1], v7);
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: load <resourceType> <resourceName>\n");
  }
}


// ========================================================================
// ?RenameResource_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82697998
// RVA : 0x00697998
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall RenameResource_f(const idCmdArgs *args)
{
  idResourceList *v2; // r3
  char *v3; // r4
  idResource *v4; // r3
  int argc; // r11
  idResource *v6; // r28
  const char *v7; // r5
  const char *v8; // r6
  const char *v9; // r5
  const char *v10; // r4
  const char *v11; // r4
  idStr v12[2]; // [sp+60h] [-50h] BYREF

  if ( args->argc == 4 )
  {
    v2 = idResourceList::ForTypeName(typeName: args->argv[1]);
    if ( v2 != nullptr )
    {
      if ( args->argc <= 2 )
        v3 = &byte_8200D768;
      else
        v3 = args->argv[2];
      v4 = idResourceList::Load(this: v2, name: v3, makeDefault: false, skipStaleCheck: false);
      argc = args->argc;
      v6 = v4;
      if ( v4 != nullptr )
      {
        if ( argc <= 3 )
          v8 = &byte_8200D768;
        else
          v8 = args->argv[3];
        if ( argc <= 2 )
          v9 = &byte_8200D768;
        else
          v9 = args->argv[2];
        if ( argc <= 1 )
          v10 = &byte_8200D768;
        else
          v10 = args->argv[1];
        idLib::Printf(fmt: "Renaming %s:%s to %s\n", v10, v9, v8);
        idStr::idStr(this: v12, text: v6->name.str);
        if ( args->argc <= 3 )
          v11 = &byte_8200D768;
        else
          v11 = args->argv[3];
        idAtomicString::Set(this: &v6->name, str_: v11);
        idResource::Load(this: v6);
        idAtomicString::Set(this: &v6->name, str_: v12[0].data);
        idStr::FreeData(this: v12);
      }
      else
      {
        if ( argc <= 2 )
          v7 = &byte_8200D768;
        else
          v7 = args->argv[2];
        if ( argc <= 1 )
          idLib::Printf(fmt: "Couldn't load %s:%s\n", &byte_8200D768, v7);
        else
          idLib::Printf(fmt: "Couldn't load %s:%s\n", args->argv[1], v7);
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: renameResource <resourceType> <oldResource> <newResource>\n");
  }
}


// ========================================================================
// __unwind$225019
// EA  : 0x82697B08
// RVA : 0x00697B08
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_225019()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?AllocateCodeResources@idBaseCodeResource@@SAXXZ
// EA  : 0x82697B38
// RVA : 0x00697B38
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

static void __fastcall idBaseCodeResource::AllocateCodeResources()
{
  idBaseCodeResource *v0; // r30
  idResourceList *rl; // r29
  idResource *v2; // r3
  int v3; // r28
  idStr v4[2]; // [sp+50h] [-50h] BYREF

  v0 = idBaseCodeResource::codeResourceList;
  for ( idBaseCodeResource::allocCodeResourcesHasBeenCalled = true; v0 != nullptr; v0 = v0->next )
  {
    rl = v0->rl;
    idStr::idStr(this: v4, text: v0->name);
    idStr::MakeNameCanonical(this: v4);
    v2 = idResourceList::Lookup(this: rl, canonicalName: v4[0].data);
    v0->r = v2;
    if ( v2 == nullptr )
    {
      v3 = (int)rl->Alloc(this: rl, a2: v4[0].data);
      v0->r = (idResource *)v3;
      idResourceList::Add(this: rl, ptr: (idResourceList_vtbl *)v3);
      *(_BYTE *)(v3 + 32) |= 0x48u;
    }
    idStr::FreeData(this: v4);
  }
}


// ========================================================================
// __unwind$225118
// EA  : 0x82697BEC
// RVA : 0x00697BEC
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_225118()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?LoadCodeResources@idBaseCodeResource@@SAXPBD@Z
// EA  : 0x82697C18
// RVA : 0x00697C18
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall idBaseCodeResource::LoadCodeResources(const char *ofType)
{
  idBaseCodeResource *v2; // r31
  const char *resourceTypeName; // r3
  idResource *v4; // r3
  const char *v5; // r4

  v2 = idBaseCodeResource::codeResourceList;
  if ( idBaseCodeResource::codeResourceList == nullptr )
    return;
  while ( 1 )
  {
    if ( (*((_BYTE *)v2->r + 32) & 8) != 0 )
    {
      if ( ofType != nullptr )
        break;
LABEL_6:
      *((_BYTE *)v2->r + 32) |= 0x80u;
      v4 = idResourceList::Load(this: v2->rl, name: (char *)v2->name, makeDefault: false, skipStaleCheck: false);
      v2->r = v4;
      if ( v4 == nullptr )
        goto _LN31;
    }
LABEL_7:
    v2 = v2->next;
    if ( v2 == nullptr )
      return;
  }
  resourceTypeName = v2->rl->resourceTypeName;
  if ( resourceTypeName != nullptr )
  {
    if ( idStr::Icmp(s1: resourceTypeName, s2: ofType) != 0 )
      goto LABEL_7;
    goto LABEL_6;
  }
  idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
_LN31:
  v5 = v2->rl->resourceTypeName;
  if ( resource_errorOnResolveFailure.valueInteger != 0 )
  {
    if ( v5 == nullptr )
      idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
    idLib::FatalError(fmt: "ResolveCodeResources: Resource name not found for %s:%s", v5, v2->name);
  }
  if ( v5 == nullptr )
    idLib::FatalError(fmt: "idResourceList::GetResourceTypeName: not set");
  idLib::Warning(fmt: "ResolveCodeResources: Resource name not found for %s:%s", v5, v2->name);
}


// ========================================================================
// `dynamic initializer for 'resource_errorInGame''
// EA  : 0x8333C168
// RVA : 0x0133C168
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_errorInGame__()
{
  idCVar::idCVar(
    this: &resource_errorInGame,
    name: "resource_errorInGame",
    value: "0",
    flags: 2,
    description: "0 - Nothing. 1 - Warning. 2 - Fatal Error - if loaded during gameplay",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_errorInGame__);
}


// ========================================================================
// `dynamic initializer for 'resource_showLoads''
// EA  : 0x8333C1C0
// RVA : 0x0133C1C0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_showLoads__()
{
  idCVar::idCVar(
    this: &resource_showLoads,
    name: "resource_showLoads",
    value: "0",
    flags: 2,
    description: "1 = show all loads, 2 = show all finds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_showLoads__);
}


// ========================================================================
// `dynamic initializer for 'resource_errorOnResolveFailure''
// EA  : 0x8333C218
// RVA : 0x0133C218
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_errorOnResolveFailure__()
{
  idCVar::idCVar(
    this: &resource_errorOnResolveFailure,
    name: "resource_errorOnResolveFailure",
    value: "1",
    flags: 1,
    description: "1 = errors on failure to resolve code resources, 0 = just warnings",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_errorOnResolveFailure__);
}


// ========================================================================
// `dynamic initializer for 'resource_errorOnClientAddNetResource''
// EA  : 0x8333C270
// RVA : 0x0133C270
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_errorOnClientAddNetResource__()
{
  idCVar::idCVar(
    this: &resource_errorOnClientAddNetResource,
    name: "resource_errorOnClientAddNetResource",
    value: "0",
    flags: 1,
    description: "Error on clients trying to add network resources",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_errorOnClientAddNetResource__);
}


// ========================================================================
// `dynamic initializer for 'networkResourceInfo''
// EA  : 0x8333C2D0
// RVA : 0x0133C2D0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __fastcall __noreturn _dynamic_initializer_for__networkResourceInfo__(int a1, idStrId *a2)
{
  idDragEntity::~idDragEntity(this: (idActor *)&networkResourceInfo.staticNetworkChecksum, result: a2);
  networkResourceInfo.firstDynamicNetworkResource = 0;
  networkResourceInfo.networkChecksum = networkResourceInfo.staticNetworkChecksum;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__networkResourceInfo__);
}


// ========================================================================
// __unwind$225234_0
// EA  : 0x8333C32C
// RVA : 0x0133C32C
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void _unwind_225234_0()
{
  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)&networkResourceInfo);
}


// ========================================================================
// `dynamic initializer for 'net_forceNetDeclExchange''
// EA  : 0x8333C358
// RVA : 0x0133C358
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_forceNetDeclExchange__()
{
  idCVar::idCVar(
    this: &net_forceNetDeclExchange,
    name: "net_forceNetDeclExchange",
    value: "0",
    flags: 1,
    description: "Force exchange of network decls rather than attempting a resource load",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_forceNetDeclExchange__);
}


// ========================================================================
// `dynamic initializer for 'resourceInfo_v''
// EA  : 0x8333C3B0
// RVA : 0x0133C3B0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__resourceInfo_v__()
{
  return idCommandLink::idCommandLink(
           this: &resourceInfo_v,
           cmdName: "resourceInfo",
           function: resourceInfo_f,
           description: "Prints information about all resources that match the provided name",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Reload_v''
// EA  : 0x8333C3D8
// RVA : 0x0133C3D8
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Reload_v__()
{
  return idCommandLink::idCommandLink(
           this: &Reload_v,
           cmdName: "Reload",
           function: Reload_f,
           description: "Calls ReloadIfStale() for either all resources, or a specific type",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Load_v''
// EA  : 0x8333C400
// RVA : 0x0133C400
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Load_v__()
{
  return idCommandLink::idCommandLink(
           this: &Load_v,
           cmdName: "Load",
           function: Load_f,
           description: "Loads a resource type / name",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'RenameResource_v''
// EA  : 0x8333C428
// RVA : 0x0133C428
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__RenameResource_v__()
{
  return idCommandLink::idCommandLink(
           this: &RenameResource_v,
           cmdName: "RenameResource",
           function: RenameResource_f,
           description: "Temporarily replace a resource definition with a different one",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'List_v''
// EA  : 0x8333C450
// RVA : 0x0133C450
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__List_v__()
{
  return idCommandLink::idCommandLink(
           this: &List_v,
           cmdName: "List",
           function: (void (__fastcall *)(const idCmdArgs *))List_f,
           description: "Lists all resources of a given type",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Resources_v''
// EA  : 0x8333C478
// RVA : 0x0133C478
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Resources_v__()
{
  return idCommandLink::idCommandLink(
           this: &Resources_v,
           cmdName: "Resources",
           function: Resources_f,
           description: "Reports on all the idResourceLists",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ResourceErrors_v''
// EA  : 0x8333C4A0
// RVA : 0x0133C4A0
// PDB : w:\tech5\engine\framework\resourcelist.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ResourceErrors_v__()
{
  return idCommandLink::idCommandLink(
           this: &ResourceErrors_v,
           cmdName: "ResourceErrors",
           function: ResourceErrors_f,
           description: "Reports all resource errors",
           argCompletion: nullptr);
}

