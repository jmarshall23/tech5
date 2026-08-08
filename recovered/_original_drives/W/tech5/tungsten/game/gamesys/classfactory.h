
// ========================================================================
// ?Find@?$idClassFactory@VidStateTransition@@$0EAA@$0GP@@@QBAPAVidStateTransition@@PBD@Z
// EA  : 0x82AF6A00
// RVA : 0x00AF6A00
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

idStateData *__fastcall idClassFactory<idStateTransition,1024,111>::Find(
        idClassFactory<idStateData,256,112> *this,
        const char *hashKey)
{
  idHashIndex *p_hashIndex; // r28
  int v5; // r31

  p_hashIndex = &this->hashIndex;
  v5 = this->hashIndex.hash[idHashIndex::GenerateKeyForString(
                              this: &this->hashIndex,
                              string: hashKey,
                              caseSensitive: true)
                          & this->hashIndex.hashMask
                          & this->hashIndex.lookupMask];
  if ( v5 == -1 )
    return nullptr;
  while ( idStr::Cmp(s1: this->keyList.list[v5].data, s2: hashKey) != 0 )
  {
    v5 = p_hashIndex->indexChain[p_hashIndex->lookupMask & v5];
    if ( v5 == -1 )
      return nullptr;
  }
  return this->list.list[v5];
}


// ========================================================================
// ?Create@?$idClassFactory@VidStateTransition@@$0EAA@$0GP@@@QAAPAVidStateTransition@@ABVidTypeInfo@@PBD@Z
// EA  : 0x82AF6D88
// RVA : 0x00AF6D88
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

idStateData *__fastcall idClassFactory<idStateTransition,1024,111>::Create(
        idClassFactory<idStateData,256,112> *this,
        const idTypeInfo *classType,
        const char *hashKey)
{
  idClass *v5; // r29
  int v6; // r27
  int KeyForString; // r3
  idClass *v9; // [sp+50h] [-60h] BYREF
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  v5 = classType->CreateInstance();
  v9 = v5;
  v6 = idList<idAnimWebBlendTree *,5>::Append(
         this: (idList<enum encounterGroupRole_t,5> *)&this->list,
         obj: (const encounterGroupRole_t *)&v9);
  idStr::idStr(this: v10, text: hashKey);
  idList<idStr,5>::Append(this: &this->keyList, obj: v10);
  idStr::FreeData(this: v10);
  this = (idClassFactory<idStateData,256,112> *)((char *)this + 36);
  KeyForString = idHashIndex::GenerateKeyForString((idHashIndex *)this, string: hashKey, caseSensitive: true);
  idHashIndex::Add((idHashIndex *)this, key: KeyForString, index: v6);
  return (idStateData *)v5;
}


// ========================================================================
// __unwind$490045
// EA  : 0x82AF6E14
// RVA : 0x00AF6E14
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void _unwind_490045()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?Shutdown@?$idClassFactory@VidStateData@@$0BAA@$0HA@@@QAAXXZ
// EA  : 0x82D812F8
// RVA : 0x00D812F8
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void __fastcall idClassFactory<idStateData,256,112>::Shutdown(idClassFactory<idStateData,256,112> *this)
{
  int v2; // r29
  int v3; // r31
  idStateData *v4; // r3
  idStr *list; // r28
  int size; // r31
  idStr *v7; // r29

  v2 = 0;
  if ( this->list.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->list.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idStateData *, int))v4->dtr_idClass)(a1: v4, a2: 1);
      ++v2;
      this->list.list[v3++] = nullptr;
    }
    while ( v2 < this->list.num );
  }
  if ( this->keyList.listStatic == 0 || this->keyList.listStatic == 2 )
  {
    list = this->keyList.list;
    if ( list != nullptr )
    {
      size = this->keyList.size;
      if ( size > 0 )
      {
        v7 = this->keyList.list;
        do
        {
          idStr::FreeData(this: v7);
          --size;
          ++v7;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->keyList.list = nullptr;
    this->keyList.size = 0;
  }
  this->keyList.num = 0;
}


// ========================================================================
// ??1?$idClassFactory@VidStateData@@$0BAA@$0HA@@@UAA@XZ
// EA  : 0x82D816A0
// RVA : 0x00D816A0
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void __fastcall idClassFactory<idStateData,256,112>::~idClassFactory<idStateData,256,112>(
        idClassFactory<idStateData,256,112> *this)
{
  idStr *list; // r3

  this->__vftable = (idClassFactory<idStateData,256,112>_vtbl *)&idClassFactory<idStateData,256,112>::`vftable';
  idHashIndex::Free(this: &this->hashIndex);
  if ( this->keyList.listStatic == 0 || this->keyList.listStatic == 2 )
  {
    list = this->keyList.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->keyList.size);
    this->keyList.list = nullptr;
    this->keyList.size = 0;
  }
  this->keyList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->list);
}


// ========================================================================
// __unwind$525222
// EA  : 0x82D81714
// RVA : 0x00D81714
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void _unwind_525222()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$525223
// EA  : 0x82D81740
// RVA : 0x00D81740
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void _unwind_525223()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// ??1?$idClassFactory@VidStateTransition@@$0EAA@$0GP@@@UAA@XZ
// EA  : 0x82D81778
// RVA : 0x00D81778
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void __fastcall idClassFactory<idStateTransition,1024,111>::~idClassFactory<idStateTransition,1024,111>(
        idClassFactory<idStateTransition,1024,111> *this)
{
  idStr *list; // r3

  this->__vftable = (idClassFactory<idStateTransition,1024,111>_vtbl *)&idClassFactory<idStateTransition,1024,111>::`vftable';
  idHashIndex::Free(this: &this->hashIndex);
  if ( this->keyList.listStatic == 0 || this->keyList.listStatic == 2 )
  {
    list = this->keyList.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->keyList.size);
    this->keyList.list = nullptr;
    this->keyList.size = 0;
  }
  this->keyList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->list);
}


// ========================================================================
// __unwind$525268
// EA  : 0x82D817EC
// RVA : 0x00D817EC
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void _unwind_525268()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$525269
// EA  : 0x82D81818
// RVA : 0x00D81818
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void _unwind_525269()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// ??0?$idClassFactory@VidStateTransition@@$0EAA@$0GP@@@QAA@XZ
// EA  : 0x82D85E18
// RVA : 0x00D85E18
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

idClassFactory<idStateTransition,1024,111> *__fastcall idClassFactory<idStateTransition,1024,111>::idClassFactory<idStateTransition,1024,111>(
        idClassFactory<idStateTransition,1024,111> *this)
{
  this->__vftable = (idClassFactory<idStateTransition,1024,111>_vtbl *)&idClassFactory<idStateTransition,1024,111>::`vftable';
  this->list.list = nullptr;
  this->list.granularity = 0;
  this->list.memTag = 5;
  this->list.listStatic = 0;
  this->list.size = 0;
  this->list.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->list);
  this->keyList.granularity = 0;
  this->keyList.memTag = 5;
  this->keyList.listStatic = 0;
  this->keyList.list = nullptr;
  this->keyList.size = 0;
  this->keyList.num = 0;
  this->hashIndex.memTag = TAG_AI_TRANSITIONS;
  idHashIndex::InternalInit(this: &this->hashIndex, initialHashSize: 1024, initialIndexSize: 1024);
  return this;
}


// ========================================================================
// __unwind$530402
// EA  : 0x82D85EA8
// RVA : 0x00D85EA8
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void _unwind_530402()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$530403
// EA  : 0x82D85ED4
// RVA : 0x00D85ED4
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void _unwind_530403()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}


// ========================================================================
// ??0?$idClassFactory@VidStateData@@$0BAA@$0HA@@@QAA@XZ
// EA  : 0x82D85F08
// RVA : 0x00D85F08
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

idClassFactory<idStateData,256,112> *__fastcall idClassFactory<idStateData,256,112>::idClassFactory<idStateData,256,112>(
        idClassFactory<idStateData,256,112> *this)
{
  this->__vftable = (idClassFactory<idStateData,256,112>_vtbl *)&idClassFactory<idStateData,256,112>::`vftable';
  this->list.list = nullptr;
  this->list.granularity = 0;
  this->list.memTag = 5;
  this->list.listStatic = 0;
  this->list.size = 0;
  this->list.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->list);
  this->keyList.granularity = 0;
  this->keyList.memTag = 5;
  this->keyList.listStatic = 0;
  this->keyList.list = nullptr;
  this->keyList.size = 0;
  this->keyList.num = 0;
  this->hashIndex.memTag = TAG_AI_STATEDATA;
  idHashIndex::InternalInit(this: &this->hashIndex, initialHashSize: 256, initialIndexSize: 256);
  return this;
}


// ========================================================================
// __unwind$530448
// EA  : 0x82D85F98
// RVA : 0x00D85F98
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void _unwind_530448()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$530449
// EA  : 0x82D85FC4
// RVA : 0x00D85FC4
// PDB : w:\tech5\tungsten\game\gamesys\classfactory.h
// ========================================================================

void _unwind_530449()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}

