
// ========================================================================
// ?IndexForName@?$idAnimHash@VidStr@@V1@V?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@W4jointTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@VidStr@@W4jointTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@VidStr@@W4jointTypeId@idAnimationLocal@@@4@@@ABAHW4jointTypeId@idAnimationLocal@@PBDAAH@Z
// EA  : 0x82803680
// RVA : 0x00803680
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

int __fastcall idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::IndexForName(
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *this,
        const idAnimationLocal::jointConversionTypeId typeId,
        const char *name,
        int *key)
{
  int KeyForString; // r3
  int v9; // r30
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *v10; // r11
  idStr v12; // [sp+60h] [-160h] BYREF
  char v13; // [sp+80h] [-140h] BYREF

  v12.baseBuffer[0] = 0;
  v13 = 0;
  v12.data = &v13;
  v12.len = 0;
  v12.allocedAndFlag = -2147483392;
  idStr::operator=(this: &v12, text: name);
  KeyForString = idHashIndex::GenerateKeyForString(this: &this->nameHash, string: v12.data, caseSensitive: false);
  *key = KeyForString;
  v9 = this->nameHash.hash[this->nameHash.hashMask & this->nameHash.lookupMask & KeyForString];
  if ( v9 == -1 )
  {
LABEL_5:
    idStr::FreeData(this: &v12);
    return -1;
  }
  else
  {
    while ( 1 )
    {
      v10 = &this->list.list[v9];
      if ( v10->typeId == typeId && idStr::Icmp(s1: v10->name.data, s2: name) == 0 )
        break;
      v9 = this->nameHash.indexChain[this->nameHash.lookupMask & v9];
      if ( v9 == -1 )
        goto LABEL_5;
    }
    idStr::FreeData(this: &v12);
    return v9;
  }
}


// ========================================================================
// __unwind$231485
// EA  : 0x8280377C
// RVA : 0x0080377C
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_231485()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 96));
}


// ========================================================================
// ?FindEntry@?$idAnimHash@VidJointConversion@@V1@V?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@W4jointConversionTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@XW4jointConversionTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@XW4jointConversionTypeId@idAnimationLocal@@@4@@@QAAPAUentry_t@1@W4jointConversionTypeId@idAnimationLocal@@PBD@Z
// EA  : 0x82804270
// RVA : 0x00804270
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *__fastcall idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::FindEntry(
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *this,
        idAnimationLocal::jointConversionTypeId typeId,
        const char *name)
{
  int v4; // r3
  int v6[4]; // [sp+50h] [-20h] BYREF

  v4 = idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::IndexForName(
         this,
         typeId,
         name,
         key: v6);
  if ( v4 >= 0 )
    return &this->list.list[v4];
  else
    return nullptr;
}


// ========================================================================
// ?FindHandle@?$idAnimHash@VidStr@@V1@V?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@W4jointTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@VidStr@@W4jointTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@VidStr@@W4jointTypeId@idAnimationLocal@@@4@@@QBA?BV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@W4jointTypeId@idAnimationLocal@@PBD@Z
// EA  : 0x828042D0
// RVA : 0x008042D0
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *__fastcall idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::FindHandle(
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *this,
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *result,
        idAnimationLocal::jointConversionTypeId typeId,
        const char *name)
{
  int v6; // r3
  int v8; // [sp+50h] [-20h] BYREF

  if ( name != nullptr
    && *name != 0
    && (v6 = idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::IndexForName(
               this: result,
               typeId,
               name,
               key: &v8)) >= 0 )
  {
    HIWORD(this->list.list) = result->list.list[v6].handle.value;
  }
  else
  {
    HIWORD(this->list.list) = -1;
  }
  return this;
}


// ========================================================================
// ??0?$idAnimHash@VidStr@@V1@V?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@W4jointTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@VidStr@@W4jointTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@VidStr@@W4jointTypeId@idAnimationLocal@@@4@@@QAA@XZ
// EA  : 0x828085C8
// RVA : 0x008085C8
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *__fastcall idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>(
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *this)
{
  int size; // r9

  this->list.granularity = 0;
  this->list.memTag = 30;
  this->list.listStatic = 0;
  this->list.list = nullptr;
  this->list.size = 0;
  this->list.num = 0;
  this->nameHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->nameHash, initialHashSize: 256, initialIndexSize: 256);
  size = this->list.size;
  this->markStaticNum = 0;
  if ( size < 256 )
    idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::entry_t,30>::Resize(
      this: &this->list,
      newsize: 256);
  return this;
}


// ========================================================================
// __unwind$239462
// EA  : 0x82808644
// RVA : 0x00808644
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_239462()
{
  int v0; // r12

  idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::entry_t,30>::Clear(this: *(idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t,30> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$239463
// EA  : 0x8280866C
// RVA : 0x0080866C
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_239463()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ?FreeDynamic@?$idAnimHash@VidStr@@V1@V?$idHandle@GW4invalidUserChannelHandle_t@@$0PPPP@@@W4userChannelTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@VidStr@@W4userChannelTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@VidStr@@W4userChannelTypeId@idAnimationLocal@@@4@@@QAAXXZ
// EA  : 0x828086A0
// RVA : 0x008086A0
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::FreeDynamic(
        idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> > *this)
{
  int markStaticNum; // r29
  int v3; // r30
  idStr *ptr; // r27
  int v5; // r30
  int size; // r11
  idHashIndex *p_nameHash; // r30
  int v8; // r27
  int v9; // r26
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> >::entry_t *list; // r11
  int KeyForString; // r3
  int indexSize; // r11
  int v13; // r24
  int v14; // r6
  idStr v15; // [sp+50h] [-180h] BYREF
  char v16; // [sp+70h] [-160h] BYREF

  markStaticNum = this->markStaticNum;
  if ( markStaticNum < this->list.num )
  {
    v3 = markStaticNum;
    do
    {
      ptr = (idStr *)this->list.list[v3].ptr;
      if ( ptr != nullptr )
      {
        idStr::FreeData(this: (idStr *)this->list.list[v3].ptr);
        idMem::Free(this: &mem, ptr, align: ALIGN_16);
      }
      ++markStaticNum;
      this->list.list[v3++].ptr = nullptr;
    }
    while ( markStaticNum < this->list.num );
  }
  v5 = this->markStaticNum;
  if ( v5 <= this->list.size
    || (unsigned __int8)idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::entry_t,30>::Resize(
                          (idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t,30> *)this,
                          newsize: this->markStaticNum) != 0 )
  {
    size = this->list.size;
    if ( v5 < size )
      size = v5;
    this->list.num = size;
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  p_nameHash = &this->nameHash;
  idHashIndex::Free(this: &this->nameHash);
  v8 = 0;
  if ( this->list.num > 0 )
  {
    v9 = 0;
    do
    {
      list = this->list.list;
      v15.baseBuffer[0] = 0;
      v16 = 0;
      v15.data = &v16;
      v15.len = 0;
      v15.allocedAndFlag = -2147483392;
      idStr::operator=(this: &v15, text: list[v9].name.data);
      KeyForString = idHashIndex::GenerateKeyForString(this: &this->nameHash, string: v15.data, caseSensitive: false);
      indexSize = this->nameHash.indexSize;
      v13 = KeyForString;
      if ( p_nameHash->hash == idHashIndex::INVALID_INDEX )
      {
        if ( (unsigned __int16)v8 >= indexSize )
          indexSize = (unsigned __int16)v8 + 1;
        idHashIndex::Allocate(this: &this->nameHash, newHashSize: this->nameHash.hashSize, newIndexSize: indexSize);
      }
      else if ( (unsigned __int16)v8 >= indexSize )
      {
        idHashIndex::ResizeIndex(this: &this->nameHash, newIndexSize: (unsigned __int16)v8 + 1);
      }
      v14 = this->nameHash.hashMask & v13;
      this->nameHash.indexChain[(unsigned __int16)v8] = p_nameHash->hash[v14];
      p_nameHash->hash[v14] = (unsigned __int16)v8;
      idStr::FreeData(this: &v15);
      ++v8;
      ++v9;
    }
    while ( v8 < this->list.num );
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$238509
// EA  : 0x8280886C
// RVA : 0x0080886C
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_238509()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// ?Free@?$idAnimHash@VidStr@@V1@V?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@W4jointTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@VidStr@@W4jointTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@VidStr@@W4jointTypeId@idAnimationLocal@@@4@@@QAAXXZ
// EA  : 0x82808898
// RVA : 0x00808898
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::Free(
        idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> > *this)
{
  int v2; // r28
  int v3; // r30
  idStr *ptr; // r29
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> >::entry_t *list; // r28
  int size; // r30
  idStr *p_name; // r29

  v2 = 0;
  if ( this->list.num > 0 )
  {
    v3 = 0;
    do
    {
      ptr = (idStr *)this->list.list[v3].ptr;
      if ( ptr != nullptr )
      {
        idStr::FreeData(this: (idStr *)this->list.list[v3].ptr);
        idMem::Free(this: &mem, ptr, align: ALIGN_16);
      }
      ++v2;
      this->list.list[v3++].ptr = nullptr;
    }
    while ( v2 < this->list.num );
  }
  idHashIndex::Free(this: &this->nameHash);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    list = this->list.list;
    if ( this->list.list != nullptr )
    {
      size = this->list.size;
      if ( size > 0 )
      {
        p_name = &list->name;
        do
        {
          idStr::FreeData(this: p_name);
          --size;
          p_name = (idStr *)((char *)p_name + 52);
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// ??0?$idAnimHash@VidAliasGroup@@VidDeclMD6@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@W4aliasTypeId@idAnimationLocal@@$0BAAA@$0BAAA@V?$idAllocNew@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@V?$idGenNameNormal@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@@@QAA@XZ
// EA  : 0x82808988
// RVA : 0x00808988
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *__fastcall idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>(
        idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *this)
{
  int size; // r9

  this->list.granularity = 0;
  this->list.memTag = 30;
  this->list.listStatic = 0;
  this->list.list = nullptr;
  this->list.size = 0;
  this->list.num = 0;
  this->nameHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->nameHash, initialHashSize: 4096, initialIndexSize: 4096);
  size = this->list.size;
  this->markStaticNum = 0;
  if ( size < 4096 )
    idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::entry_t,30>::Resize(
      (idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t,30> *)this,
      newsize: 4096);
  return this;
}


// ========================================================================
// __unwind$238847
// EA  : 0x82808A04
// RVA : 0x00808A04
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_238847()
{
  int v0; // r12

  idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::entry_t,30>::Clear(this: *(idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t,30> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$238848
// EA  : 0x82808A2C
// RVA : 0x00808A2C
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_238848()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ?FreeDynamic@?$idAnimHash@VidAliasGroup@@VidDeclMD6@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@W4aliasTypeId@idAnimationLocal@@$0BAAA@$0BAAA@V?$idAllocNew@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@V?$idGenNameNormal@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@@@QAAXXZ
// EA  : 0x82808A60
// RVA : 0x00808A60
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::FreeDynamic(
        idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *this)
{
  int markStaticNum; // r28
  int v3; // r29
  const idAliasGroup *ptr; // r30
  int v5; // r30
  int size; // r11
  idHashIndex *p_nameHash; // r30
  int v8; // r28
  int v9; // r26
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *list; // r11
  int KeyForString; // r3
  int indexSize; // r11
  int v13; // r24
  int v14; // r6
  idStr v15; // [sp+60h] [-180h] BYREF
  char v16; // [sp+80h] [-160h] BYREF

  markStaticNum = this->markStaticNum;
  if ( markStaticNum < this->list.num )
  {
    v3 = markStaticNum;
    do
    {
      ptr = this->list.list[v3].ptr;
      if ( ptr != nullptr )
      {
        if ( ptr->declRefs.listStatic == 0 || ptr->declRefs.listStatic == 2 )
        {
          if ( ptr->declRefs.list != nullptr )
            idMem::Free(this: &mem, ptr: ptr->declRefs.list, align: ALIGN_16);
          ptr->declRefs.list = nullptr;
          ptr->declRefs.size = 0;
        }
        ptr->declRefs.num = 0;
        idMem::Free(this: &mem, (void *)ptr, align: ALIGN_16);
      }
      ++markStaticNum;
      this->list.list[v3++].ptr = nullptr;
    }
    while ( markStaticNum < this->list.num );
  }
  v5 = this->markStaticNum;
  if ( v5 <= this->list.size
    || (unsigned __int8)idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::entry_t,30>::Resize(
                          (idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t,30> *)this,
                          newsize: this->markStaticNum) != 0 )
  {
    size = this->list.size;
    if ( v5 < size )
      size = v5;
    this->list.num = size;
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  p_nameHash = &this->nameHash;
  idHashIndex::Free(this: &this->nameHash);
  v8 = 0;
  if ( this->list.num > 0 )
  {
    v9 = 0;
    do
    {
      list = this->list.list;
      v15.baseBuffer[0] = 0;
      v16 = 0;
      v15.data = &v16;
      v15.len = 0;
      v15.allocedAndFlag = -2147483392;
      idStr::operator=(this: &v15, text: list[v9].name.data);
      KeyForString = idHashIndex::GenerateKeyForString(this: &this->nameHash, string: v15.data, caseSensitive: false);
      indexSize = this->nameHash.indexSize;
      v13 = KeyForString;
      if ( p_nameHash->hash == idHashIndex::INVALID_INDEX )
      {
        if ( (unsigned __int16)v8 >= indexSize )
          indexSize = (unsigned __int16)v8 + 1;
        idHashIndex::Allocate(this: &this->nameHash, newHashSize: this->nameHash.hashSize, newIndexSize: indexSize);
      }
      else if ( (unsigned __int16)v8 >= indexSize )
      {
        idHashIndex::ResizeIndex(this: &this->nameHash, newIndexSize: (unsigned __int16)v8 + 1);
      }
      v14 = this->nameHash.hashMask & v13;
      this->nameHash.indexChain[(unsigned __int16)v8] = p_nameHash->hash[v14];
      p_nameHash->hash[v14] = (unsigned __int16)v8;
      idStr::FreeData(this: &v15);
      ++v8;
      ++v9;
    }
    while ( v8 < this->list.num );
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$238896
// EA  : 0x82808C60
// RVA : 0x00808C60
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_238896()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 96));
}


// ========================================================================
// ?Free@?$idAnimHash@VidAliasGroup@@VidDeclMD6@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@W4aliasTypeId@idAnimationLocal@@$0BAAA@$0BAAA@V?$idAllocNew@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@V?$idGenNameNormal@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@@@QAAXXZ
// EA  : 0x82808C88
// RVA : 0x00808C88
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::Free(
        idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *this)
{
  int v2; // r28
  int v3; // r30
  const idAliasGroup *ptr; // r31
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *list; // r28
  int size; // r31
  idStr *p_name; // r30

  v2 = 0;
  if ( this->list.num > 0 )
  {
    v3 = 0;
    do
    {
      ptr = this->list.list[v3].ptr;
      if ( ptr != nullptr )
      {
        if ( ptr->declRefs.listStatic == 0 || ptr->declRefs.listStatic == 2 )
        {
          if ( ptr->declRefs.list != nullptr )
            idMem::Free(this: &mem, ptr: ptr->declRefs.list, align: ALIGN_16);
          ptr->declRefs.list = nullptr;
          ptr->declRefs.size = 0;
        }
        ptr->declRefs.num = 0;
        idMem::Free(this: &mem, (void *)ptr, align: ALIGN_16);
      }
      ++v2;
      this->list.list[v3++].ptr = nullptr;
    }
    while ( v2 < this->list.num );
  }
  idHashIndex::Free(this: &this->nameHash);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    list = this->list.list;
    if ( this->list.list != nullptr )
    {
      size = this->list.size;
      if ( size > 0 )
      {
        p_name = &list->name;
        do
        {
          idStr::FreeData(this: p_name);
          --size;
          p_name = (idStr *)((char *)p_name + 52);
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// ?Remove@?$idAnimHash@VidAliasGroup@@VidDeclMD6@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@W4aliasTypeId@idAnimationLocal@@$0BAAA@$0BAAA@V?$idAllocNew@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@V?$idGenNameNormal@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@@Z
// EA  : 0x82808DA0
// RVA : 0x00808DA0
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::Remove(
        idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *handle)
{
  int value; // r11
  int v3; // r11
  const idAliasGroup *ptr; // r30
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *v5; // r31

  value = handle->value;
  if ( value != 0xFFFF && value < this->list.num )
  {
    v3 = value;
    ptr = this->list.list[v3].ptr;
    v5 = &this->list.list[v3];
    if ( ptr != nullptr )
    {
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)this->list.list[v3].ptr);
      idMem::Free(this: &mem, (void *)ptr, align: ALIGN_16);
      v5->ptr = nullptr;
      v5->parent = nullptr;
      v5->refType = REF_FREED;
    }
  }
}


// ========================================================================
// ?FreeDynamic@?$idAnimHash@VidJointConversion@@V1@V?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@W4jointConversionTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@XW4jointConversionTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@XW4jointConversionTypeId@idAnimationLocal@@@4@@@QAAXXZ
// EA  : 0x82808E40
// RVA : 0x00808E40
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::FreeDynamic(
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *this)
{
  int markStaticNum; // r30
  int v3; // r28
  int v4; // r30
  int size; // r11
  idHashIndex *p_nameHash; // r30
  int v7; // r27
  int v8; // r25
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *list; // r11
  int KeyForString; // r3
  int indexSize; // r11
  int v12; // r24
  int v13; // r6
  idStr v14; // [sp+50h] [-180h] BYREF
  char v15; // [sp+70h] [-160h] BYREF

  markStaticNum = this->markStaticNum;
  if ( markStaticNum < this->list.num )
  {
    v3 = markStaticNum;
    do
    {
      idMem::Free(this: &mem, ptr: (void *)this->list.list[v3].ptr, align: ALIGN_16);
      ++markStaticNum;
      this->list.list[v3++].ptr = nullptr;
    }
    while ( markStaticNum < this->list.num );
  }
  v4 = this->markStaticNum;
  if ( v4 <= this->list.size
    || (unsigned __int8)idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::entry_t,30>::Resize(
                          this: &this->list,
                          newsize: this->markStaticNum) != 0 )
  {
    size = this->list.size;
    if ( v4 < size )
      size = v4;
    this->list.num = size;
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  p_nameHash = &this->nameHash;
  idHashIndex::Free(this: &this->nameHash);
  v7 = 0;
  if ( this->list.num > 0 )
  {
    v8 = 0;
    do
    {
      list = this->list.list;
      v14.baseBuffer[0] = 0;
      v15 = 0;
      v14.data = &v15;
      v14.len = 0;
      v14.allocedAndFlag = -2147483392;
      idStr::operator=(this: &v14, text: list[v8].name.data);
      KeyForString = idHashIndex::GenerateKeyForString(this: &this->nameHash, string: v14.data, caseSensitive: false);
      indexSize = this->nameHash.indexSize;
      v12 = KeyForString;
      if ( p_nameHash->hash == idHashIndex::INVALID_INDEX )
      {
        if ( (unsigned __int16)v7 >= indexSize )
          indexSize = (unsigned __int16)v7 + 1;
        idHashIndex::Allocate(this: &this->nameHash, newHashSize: this->nameHash.hashSize, newIndexSize: indexSize);
      }
      else if ( (unsigned __int16)v7 >= indexSize )
      {
        idHashIndex::ResizeIndex(this: &this->nameHash, newIndexSize: (unsigned __int16)v7 + 1);
      }
      v13 = this->nameHash.hashMask & v12;
      this->nameHash.indexChain[(unsigned __int16)v7] = p_nameHash->hash[v13];
      p_nameHash->hash[v13] = (unsigned __int16)v7;
      idStr::FreeData(this: &v14);
      ++v7;
      ++v8;
    }
    while ( v7 < this->list.num );
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$239511_0
// EA  : 0x82808FF8
// RVA : 0x00808FF8
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_239511_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// ?Free@?$idAnimHash@VidJointConversion@@V1@V?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@W4jointConversionTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@XW4jointConversionTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@XW4jointConversionTypeId@idAnimationLocal@@@4@@@QAAXXZ
// EA  : 0x82809020
// RVA : 0x00809020
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::Free(
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *this)
{
  int v2; // r29
  int v3; // r30
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *list; // r28
  int size; // r30
  idStr *p_name; // r29

  v2 = 0;
  if ( this->list.num > 0 )
  {
    v3 = 0;
    do
    {
      idMem::Free(this: &mem, ptr: (void *)this->list.list[v3].ptr, align: ALIGN_16);
      ++v2;
      this->list.list[v3++].ptr = nullptr;
    }
    while ( v2 < this->list.num );
  }
  idHashIndex::Free(this: &this->nameHash);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    list = this->list.list;
    if ( this->list.list != nullptr )
    {
      size = this->list.size;
      if ( size > 0 )
      {
        p_name = &list->name;
        do
        {
          idStr::FreeData(this: p_name);
          --size;
          p_name = (idStr *)((char *)p_name + 52);
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// ?Add@?$idAnimHash@VidJointConversion@@V1@V?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@W4jointConversionTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@XW4jointConversionTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@XW4jointConversionTypeId@idAnimationLocal@@@4@@@QAA?AV?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@W4jointConversionTypeId@idAnimationLocal@@PBVidJointConversion@@1PBDPAPAUentry_t@1@@Z
// EA  : 0x8280C220
// RVA : 0x0080C220
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *__fastcall idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::Add(
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *this,
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *result,
        idAnimationLocal::jointConversionTypeId typeId,
        const idJointConversion *obj,
        const idJointConversion *parent,
        const char *name,
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t **e)
{
  int size; // r11
  int v15; // r3
  int num; // r30
  int v18; // r31
  int v19; // [sp+50h] [-60h] BYREF

  size = result->list.size;
  if ( 52 * size == 0 && size < 256 )
    idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::entry_t,30>::Resize(
      this: &result->list,
      newsize: 256);
  v15 = idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::IndexForName(
          this: result,
          typeId,
          name,
          key: &v19);
  if ( v15 >= 0 && result->list.list[v15].ptr != nullptr )
  {
    HIWORD(this->list.list) = v15;
    return this;
  }
  else
  {
    LOWORD(num) = v15;
    if ( v15 < 0 )
    {
      num = (unsigned __int16)result->list.num;
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::entry_t,30>::Alloc(this: &result->list);
      idHashIndex::Add(this: &result->nameHash, key: v19, index: num);
      idMem::PopHeap(this: &mem);
    }
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v18 = (int)&result->list.list[(unsigned __int16)num];
    *(_WORD *)(v18 + 44) = num;
    idStr::operator=(this: (idStr *)(v18 + 8), text: name);
    *(_DWORD *)v18 = obj;
    *(_DWORD *)(v18 + 4) = parent;
    *(_DWORD *)(v18 + 40) = typeId;
    idMem::PopHeap(this: &mem);
    *(_DWORD *)(v18 + 48) = ((_cntlzw((unsigned int)obj) & 0x20) == 0) + 2;
    if ( e != nullptr )
      *e = (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *)v18;
    HIWORD(this->list.list) = *(_WORD *)(v18 + 44);
    return this;
  }
}


// ========================================================================
// ??1?$idAnimHash@VidStr@@V1@V?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@W4jointTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@VidStr@@W4jointTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@VidStr@@W4jointTypeId@idAnimationLocal@@@4@@@QAA@XZ
// EA  : 0x8280C378
// RVA : 0x0080C378
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::~idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>(
        idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> > *this)
{
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::Free(this);
  idHashIndex::Free(this: &this->nameHash);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    if ( this->list.list != nullptr )
      idListArrayDelete<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::entry_t>(
        ptr: (char *)this->list.list,
        num: this->list.size);
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// __unwind$243318
// EA  : 0x8280C3FC
// RVA : 0x0080C3FC
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_243318()
{
  int v0; // r12

  idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::entry_t,30>::Clear(this: *(idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t,30> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$243319
// EA  : 0x8280C424
// RVA : 0x0080C424
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_243319()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ??1?$idAnimHash@VidAliasGroup@@VidDeclMD6@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@W4aliasTypeId@idAnimationLocal@@$0BAAA@$0BAAA@V?$idAllocNew@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@V?$idGenNameNormal@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@@@QAA@XZ
// EA  : 0x8280C458
// RVA : 0x0080C458
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::~idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>(
        idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *this)
{
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::Free(this);
  idHashIndex::Free(this: &this->nameHash);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    if ( this->list.list != nullptr )
      idListArrayDelete<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::entry_t>(
        ptr: (char *)this->list.list,
        num: this->list.size);
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// __unwind$243409
// EA  : 0x8280C4DC
// RVA : 0x0080C4DC
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_243409()
{
  int v0; // r12

  idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::entry_t,30>::Clear(this: *(idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t,30> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$243410
// EA  : 0x8280C504
// RVA : 0x0080C504
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_243410()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ?Add@?$idAnimHash@VidAliasGroup@@VidDeclMD6@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@W4aliasTypeId@idAnimationLocal@@$0BAAA@$0BAAA@V?$idAllocNew@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@V?$idGenNameNormal@VidAliasGroup@@W4aliasTypeId@idAnimationLocal@@@5@@@QAA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@W4aliasTypeId@idAnimationLocal@@PBVidAliasGroup@@PBVidDeclMD6@@PBDPAPAUentry_t@1@@Z
// EA  : 0x8280C530
// RVA : 0x0080C530
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *__fastcall idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::Add(
        idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *this,
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *result,
        idAnimationLocal::jointConversionTypeId typeId,
        const idAliasGroup *obj,
        const idDeclMD6 *parent,
        const char *name,
        idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t **e)
{
  int size; // r11
  int v15; // r3
  int num; // r30
  int v18; // r31
  int v19; // [sp+50h] [-60h] BYREF

  size = result->list.size;
  if ( 52 * size == 0 && size < 4096 )
    idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::entry_t,30>::Resize(
      this: &result->list,
      newsize: 4096);
  v15 = idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::IndexForName(
          this: result,
          typeId,
          name,
          key: &v19);
  if ( v15 >= 0 && result->list.list[v15].ptr != nullptr )
  {
    HIWORD(this->list.list) = v15;
    return this;
  }
  else
  {
    LOWORD(num) = v15;
    if ( v15 < 0 )
    {
      num = (unsigned __int16)result->list.num;
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::entry_t,30>::Alloc(this: &result->list);
      idHashIndex::Add(this: &result->nameHash, key: v19, index: num);
      idMem::PopHeap(this: &mem);
    }
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v18 = (int)&result->list.list[(unsigned __int16)num];
    *(_WORD *)(v18 + 44) = num;
    idStr::operator=(this: (idStr *)(v18 + 8), text: name);
    *(_DWORD *)v18 = obj;
    *(_DWORD *)(v18 + 4) = parent;
    *(_DWORD *)(v18 + 40) = typeId;
    idMem::PopHeap(this: &mem);
    *(_DWORD *)(v18 + 48) = ((_cntlzw((unsigned int)obj) & 0x20) == 0) + 2;
    if ( e != nullptr )
      *e = (idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *)v18;
    HIWORD(this->list.list) = *(_WORD *)(v18 + 44);
    return this;
  }
}


// ========================================================================
// ??1?$idAnimHash@VidJointConversion@@V1@V?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@W4jointConversionTypeId@idAnimationLocal@@$0BAA@$0BAA@V?$idAllocNew@XW4jointConversionTypeId@idAnimationLocal@@@4@V?$idGenNameNormal@XW4jointConversionTypeId@idAnimationLocal@@@4@@@QAA@XZ
// EA  : 0x8280C688
// RVA : 0x0080C688
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void __fastcall idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::~idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>(
        idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *this)
{
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::Free(this);
  idHashIndex::Free(this: &this->nameHash);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    if ( this->list.list != nullptr )
      idListArrayDelete<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::entry_t>(
        ptr: (char *)this->list.list,
        num: this->list.size);
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// __unwind$243500
// EA  : 0x8280C70C
// RVA : 0x0080C70C
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_243500()
{
  int v0; // r12

  idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::entry_t,30>::Clear(this: *(idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t,30> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$243501
// EA  : 0x8280C734
// RVA : 0x0080C734
// PDB : w:\tech5\engine\models\skeletalanimation\animhash.h
// ========================================================================

void _unwind_243501()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}

