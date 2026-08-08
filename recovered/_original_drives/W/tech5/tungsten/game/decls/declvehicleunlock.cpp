
// ========================================================================
// ?GetUnlockTypeForSlot@idDeclVehicleUnlock@@SA?BW4vehicleUnlockType_t@@W4vehicleLoadoutSlot_t@@@Z
// EA  : 0x82BCBDD8
// RVA : 0x00BCBDD8
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

int __fastcall idDeclVehicleUnlock::GetUnlockTypeForSlot(unsigned int slot)
{
  if ( slot > 5 )
    return 0;
  switch ( slot )
  {
    case 0u:
      return 1;
    case 1u:
      return 2;
    case 2u:
      return 3;
    case 3u:
      return 4;
    case 4u:
      return 5;
    default:
      break;
  }
  return 6;
}


// ========================================================================
// ?Parse@idDeclVehicleUnlock@@UAAXAAVidParser@@@Z
// EA  : 0x82BCBE38
// RVA : 0x00BCBE38
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

void __fastcall idDeclVehicleUnlock::Parse(idDeclVehicleUnlock *this, idParser *src)
{
  const char *str; // r3
  int v4; // r4

  idDeclTypeInfo::Parse(this: &this->idDeclTypeInfo, src);
  str = this->name.str;
  v4 = 0;
  if ( *str != 0 )
  {
    do
      ++v4;
    while ( str[v4] != 0 );
  }
  this->ordinal = MurMur32_HashData(key: str, len: v4, seed: 0);
}


// ========================================================================
// ?GetBigLoadoutImageName@idDeclVehicleUnlock@@QBAPBDXZ
// EA  : 0x82BCBE98
// RVA : 0x00BCBE98
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

char *__fastcall idDeclVehicleUnlock::GetBigLoadoutImageName(idDeclVehicleUnlock *this)
{
  const idMaterial *bigLoadoutIcon; // r11

  bigLoadoutIcon = this->bigLoadoutIcon;
  if ( bigLoadoutIcon != nullptr )
    return (char *)bigLoadoutIcon->name.str;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetInventoryDecl@idDeclVehicleUnlock@@SAPBVidDeclInventory@@ABUinventoryUnlock_t@1@@Z
// EA  : 0x82BCBFA8
// RVA : 0x00BCBFA8
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

const idDeclInventory *__fastcall idDeclVehicleUnlock::GetInventoryDecl(
        const idDeclVehicleUnlock::inventoryUnlock_t *unlock)
{
  char *data; // r4

  if ( unlock->itemDeclStr.len != 0 && (data = unlock->itemDeclStr.data) != nullptr )
    return (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                      this: &idDeclInventory::resourceList,
                                      name: data,
                                      makeDefault: false);
  else
    return nullptr;
}


// ========================================================================
// ?GetEntityDef@idDeclVehicleUnlock@@SAPBVidDeclEntityDef@@ABUinventoryUnlock_t@1@@Z
// EA  : 0x82BCBFD8
// RVA : 0x00BCBFD8
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

const idDeclEntityDef *__fastcall idDeclVehicleUnlock::GetEntityDef(
        const idDeclVehicleUnlock::inventoryUnlock_t *unlock)
{
  char *data; // r4

  if ( unlock->entityDefStr.len != 0 && (data = unlock->entityDefStr.data) != nullptr )
    return (const idDeclEntityDef *)idDeclInfo::FindWithInheritance(
                                      this: &idDeclEntityDef::resourceList,
                                      name: data,
                                      makeDefault: false);
  else
    return nullptr;
}


// ========================================================================
// ?GetSoundShader@idDeclVehicleUnlock@@SAPBVidSoundShader@@ABUinventoryUnlock_t@1@@Z
// EA  : 0x82BCC008
// RVA : 0x00BCC008
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

const idSoundShader *__fastcall idDeclVehicleUnlock::GetSoundShader(
        const idDeclVehicleUnlock::inventoryUnlock_t *unlock)
{
  char *data; // r4

  if ( unlock->soundDeclStr.len != 0 && (data = unlock->soundDeclStr.data) != nullptr )
    return (const idSoundShader *)idDeclInfo::FindWithInheritance(
                                    this: &idSoundShader::resourceList,
                                    name: data,
                                    makeDefault: false);
  else
    return nullptr;
}


// ========================================================================
// ?GetUnlockByOrdinal@idDeclVehicleUnlock@@SAPBV1@H@Z
// EA  : 0x82BCC038
// RVA : 0x00BCC038
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

const idDeclVehicleUnlock *__fastcall idDeclVehicleUnlock::GetUnlockByOrdinal(
        int ordinal,
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
        int a12)
{
  idAIAction **v13; // [sp+50h] [-10h] BYREF

  a12 = ordinal;
  if ( ordinal == -1 )
    return nullptr;
  v13 = nullptr;
  if ( (unsigned __int8)idHashTableT<int,idAIAction *>::Get(
                          this: (idHashTableT<int,idAIAction *> *)&idDeclVehicleUnlock::unlockLookup,
                          key: &a12,
                          value: &v13) == 0 )
    return nullptr;
  else
    return (const idDeclVehicleUnlock *)*v13;
}


// ========================================================================
// ?LoadAllDecls@idDeclVehicleUnlock@@SAXXZ
// EA  : 0x82BCC0A8
// RVA : 0x00BCC0A8
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

static void __fastcall idDeclVehicleUnlock::LoadAllDecls()
{
  int v0; // r31
  int num; // r30
  const char *str; // r4
  int v3; // r30
  int v4; // r28
  idResource *v5; // r3
  int nextOnHashChain; // r5
  idHashNodeT<int,idDeclVehicleUnlock const *> *v7; // r11
  bool v8; // cr57
  char v9; // r11
  idResource *v10; // [sp+50h] [-40h] BYREF
  int v11; // [sp+54h] [-3Ch] BYREF

  if ( idDeclVehicleUnlock::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclVehicleUnlock::resourceList.declSources.num;
    do
    {
      str = idDeclVehicleUnlock::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclVehicleUnlock::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idHashTableT<int,idDeclVehicleUnlock const *>::Clear(this: (idHashTableT<int,idAIAction *> *)&idDeclVehicleUnlock::unlockLookup);
  v3 = 0;
  v4 = idDeclVehicleUnlock::resourceList.num;
  if ( idDeclVehicleUnlock::resourceList.num > 0 )
  {
    while ( 1 )
    {
      v5 = idResourceList::Index(this: &idDeclVehicleUnlock::resourceList, index: v3);
      nextOnHashChain = (int)v5[3].nextOnHashChain;
      v10 = v5;
      if ( nextOnHashChain == -1 )
        break;
      v7 = idDeclVehicleUnlock::unlockLookup.heads[idDeclVehicleUnlock::unlockLookup.tableSizeMask & nextOnHashChain];
      if ( v7 == nullptr )
        goto LABEL_13;
      while ( 1 )
      {
        v8 = v7->key > nextOnHashChain;
        if ( v7->key >= nextOnHashChain )
          break;
        v7 = v7->next;
        if ( v7 == nullptr )
          goto LABEL_13;
      }
      v9 = 1;
      if ( v8 )
LABEL_13:
        v9 = 0;
      if ( v9 != 0 )
        goto _LN84_1;
      v11 = nextOnHashChain;
      idHashTableT<int,idAIAction *>::Set(
        this: (idHashTableT<int,idAIAction *> *)&idDeclVehicleUnlock::unlockLookup,
        key: &v11,
        value: (idAIAction **)&v10);
      if ( ++v3 >= v4 )
        goto LABEL_16;
    }
    idLib::Error(
      fmt: "idDeclVehicleUnlock [ %s ] failed to load. Ordinal cannot be -1.  Rename to resolve conflict.",
      v5->name.str);
_LN84_1:
    idLib::Error(
      fmt: "idDeclVehicleUnlock [ %s ] failed to load. Ordinal %d already exists!  Rename to resolve conflict.",
      v5->name.str,
      nextOnHashChain);
    JUMPOUT(0x82BCC1EC);
  }
LABEL_16:
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// ??0idDeclVehicleUnlock@@QAA@XZ
// EA  : 0x82BCC1F8
// RVA : 0x00BCC1F8
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

idDeclVehicleUnlock *__fastcall idDeclVehicleUnlock::idDeclVehicleUnlock(idDeclVehicleUnlock *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->unlockType = UNLOCK_TYPE_NONE;
  this->__vftable = (idDeclVehicleUnlock_vtbl *)&idDeclVehicleUnlock::`vftable';
  this->levelRequired = 0;
  this->displayName.index = -1;
  this->quantity = 0;
  this->rangeRank = 0;
  this->damageRank = 0;
  this->accuracyRank = 0;
  this->rateOfFireRank = 0;
  this->description.index = -1;
  this->loadoutIcon = nullptr;
  this->bigLoadoutIcon = nullptr;
  this->upgradeTo = nullptr;
  this->spRequired = 0;
  this->metricType = RAGE_STAT_VEHICLE_KILLS;
  this->ordinal = -1;
  this->items.granularity = 0;
  this->items.memTag = 5;
  this->items.listStatic = 0;
  this->items.list = nullptr;
  this->items.size = 0;
  this->items.num = 0;
  return this;
}


// ========================================================================
// __unwind$488574
// EA  : 0x82BCC2B8
// RVA : 0x00BCC2B8
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

void _unwind_488574()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// `dynamic initializer for 'idDeclVehicleUnlock::unlockLookup''
// EA  : 0x83372438
// RVA : 0x01372438
// PDB : w:\tech5\tungsten\game\decls\declvehicleunlock.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDeclVehicleUnlock::unlockLookup__()
{
  idDeclVehicleUnlock::unlockLookup.heads = (idHashNodeT<int,idDeclVehicleUnlock const *> **)idMem::AllocWithLocation(
                                                                                               this: &mem,
                                                                                               location: "w:\\tech5\\shared\\idlib\\"
                                                                                               "Heap.h(82) : tag",
                                                                                               size: 0x400u,
                                                                                               tag: TAG_HASHTABLE,
                                                                                               zeroBuffer: false,
                                                                                               align: ALIGN_16,
                                                                                               heap: HEAP_DEFAULTHEAP);
  memset(Dst: idDeclVehicleUnlock::unlockLookup.heads, Val: 0, Size: 0x400u);
  idDeclVehicleUnlock::unlockLookup.numEntries = 0;
  idDeclVehicleUnlock::unlockLookup.tableSizeMask = 255;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDeclVehicleUnlock::unlockLookup__);
}

