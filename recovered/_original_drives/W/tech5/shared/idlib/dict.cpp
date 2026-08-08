
// ========================================================================
// ?Print@idDict@@QBAXXZ
// EA  : 0x82F01AD0
// RVA : 0x00F01AD0
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void __fastcall idDict::Print(idDict *this)
{
  int v2; // r30
  int v3; // r31

  idLib::Printf(fmt: "Num args: %i\n", this->args.num);
  v2 = 0;
  if ( this->args.num > 0 )
  {
    v3 = 0;
    do
    {
      idLib::Printf(fmt: "%s = %s\n", this->args.list[v3].key.data, this->args.list[v3].value.data);
      ++v2;
      ++v3;
    }
    while ( v2 < this->args.num );
  }
}


// ========================================================================
// ?FindKey@idDict@@QBAPBVidKeyValue@@PBD@Z
// EA  : 0x82F01BA8
// RVA : 0x00F01BA8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

const idKeyValue *__fastcall idDict::FindKey(idDict *this, const char *key)
{
  idHashIndex *p_argHash; // r29
  int v5; // r31

  if ( key == nullptr || *key == 0 )
  {
    idLib::Warning(fmt: "idDict::FindKey: empty key");
    return nullptr;
  }
  p_argHash = &this->argHash;
  v5 = this->argHash.hash[idHashIndex::GenerateKeyForString(this: &this->argHash, string: key, caseSensitive: false)
                        & this->argHash.hashMask
                        & this->argHash.lookupMask];
  if ( v5 == -1 )
    return nullptr;
  while ( idStr::Icmp(s1: this->args.list[v5].key.data, s2: key) != 0 )
  {
    v5 = p_argHash->indexChain[v5 & p_argHash->lookupMask];
    if ( v5 == -1 )
      return nullptr;
  }
  return &this->args.list[v5];
}


// ========================================================================
// ?FindKeyIndex@idDict@@QBAHPBD@Z
// EA  : 0x82F01C78
// RVA : 0x00F01C78
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

int __fastcall idDict::FindKeyIndex(idDict *this, const char *key)
{
  idHashIndex *p_argHash; // r30
  int v5; // r31

  p_argHash = &this->argHash;
  v5 = this->argHash.hash[idHashIndex::GenerateKeyForString(this: &this->argHash, string: key, caseSensitive: false)
                        & this->argHash.hashMask
                        & this->argHash.lookupMask];
  if ( v5 == -1 )
    return -1;
  while ( idStr::Icmp(s1: this->args.list[v5].key.data, s2: key) != 0 )
  {
    v5 = p_argHash->indexChain[p_argHash->lookupMask & v5];
    if ( v5 == -1 )
      return -1;
  }
  return v5;
}


// ========================================================================
// ?Clear@idDict@@QAAXXZ
// EA  : 0x82F01EA8
// RVA : 0x00F01EA8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void __fastcall idDict::Clear(idDict *this)
{
  idKeyValue *list; // r3

  if ( this->args.listStatic == 0 || this->args.listStatic == 2 )
  {
    list = this->args.list;
    if ( this->args.list != nullptr )
      idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &list->key, num: this->args.size);
    this->args.list = nullptr;
    this->args.size = 0;
  }
  this->args.num = 0;
  idHashIndex::Free(this: &this->argHash);
}


// ========================================================================
// ?GetFloat@idDict@@QBA_NPBDMAAM@Z
// EA  : 0x82F01F18
// RVA : 0x00F01F18
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

int __fastcall idDict::GetFloat(idDict *this, const char *key, double defaultFloat, float *out, float *a5)
{
  const idKeyValue *v7; // r3
  const char *data; // r3
  long double v9; // fp2

  v7 = idDict::FindKey(this, key);
  if ( v7 != nullptr && (data = v7->value.data) != nullptr )
  {
    v9 = atof(nptr: data);
    *a5 = *(double *)&v9;
    return 1;
  }
  else
  {
    *a5 = defaultFloat;
    return 0;
  }
}


// ========================================================================
// ?GetInt@idDict@@QBA_NPBDHAAH@Z
// EA  : 0x82F01F80
// RVA : 0x00F01F80
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

int __fastcall idDict::GetInt(idDict *this, const char *key, int defaultInt, int *out)
{
  const idKeyValue *v6; // r3
  const char *data; // r3

  v6 = idDict::FindKey(this, key);
  if ( v6 != nullptr && (data = v6->value.data) != nullptr )
  {
    *out = atol(nptr: data);
    return 1;
  }
  else
  {
    *out = defaultInt;
    return 0;
  }
}


// ========================================================================
// ?Delete@idDict@@QAAXPBD@Z
// EA  : 0x82F01FE8
// RVA : 0x00F01FE8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void __fastcall idDict::Delete(idDict *this, const char *key)
{
  idHashIndex *p_argHash; // r30
  int KeyForString; // r27
  int v6; // r31

  p_argHash = &this->argHash;
  KeyForString = idHashIndex::GenerateKeyForString(this: &this->argHash, string: key, caseSensitive: false);
  v6 = this->argHash.hash[this->argHash.hashMask & this->argHash.lookupMask & KeyForString];
  if ( v6 != -1 )
  {
    while ( idStr::Icmp(s1: this->args.list[v6].key.data, s2: key) != 0 )
    {
      v6 = p_argHash->indexChain[p_argHash->lookupMask & v6];
      if ( v6 == -1 )
        return;
    }
    idList<idKeyValue,5>::RemoveIndex(this: &this->args, index: v6);
    idHashIndex::RemoveIndex(this: p_argHash, key: KeyForString, index: v6);
  }
}


// ========================================================================
// ??4idDict@@QAAAAV0@ABV0@@Z
// EA  : 0x82F02450
// RVA : 0x00F02450
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

idDict *__fastcall idDict::operator=(idDict *this, const idDict *other)
{
  idDict *v2; // r31

  v2 = this;
  if ( this != other )
  {
    idDict::Clear(this);
    idList<idKeyValue,5>::operator=(this: &v2->args, other: &other->args);
    idHashIndex::operator=(this: &v2->argHash, other: &other->argHash);
    return v2;
  }
  return this;
}


// ========================================================================
// ?Checksum@idDict@@QBAIXZ
// EA  : 0x82F024B8
// RVA : 0x00F024B8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

unsigned int __fastcall idDict::Checksum(idDict *this)
{
  __int64 v1; // r10
  int v2; // r8
  int v3; // r7
  int v4; // r6
  idStrId *v5; // r4
  idKeyValue *list; // r27
  int num; // r29
  char **p_data; // r30
  _BYTE *v9; // r4
  int v10; // r5
  char *v11; // r4
  int v12; // r5
  unsigned int v13; // r30
  unsigned int v15; // [sp+50h] [-50h] BYREF
  idSort_Quick<idKeyValue,idSort_KeyValue> v16; // [sp+54h] [-4Ch] BYREF
  char *v17; // [sp+58h] [-48h]
  idList<idKeyValue,5> v18[4]; // [sp+60h] [-40h] BYREF

  *(_WORD *)&v18[0].memTag = 1280;
  memset(v18, 0, 14);
  idList<idKeyValue,5>::operator=(this: v18, other: &this->args);
  v16.__vftable = (idSort_Quick<idKeyValue,idSort_KeyValue>_vtbl *)&idSort_KeyValue::`vftable';
  list = v18[0].list;
  num = v18[0].num;
  if ( v18[0].list != nullptr )
    idSort_Quick<idKeyValue,idSort_KeyValue>::Sort(
      this: &v16,
      base: v18[0].list,
      num: v18[0].num,
      a4: v4,
      a5: v3,
      a6: v2,
      a7: v1);
  v16.__vftable = (idSort_Quick<idKeyValue,idSort_KeyValue>_vtbl *)&idSort<idKeyValue>::`vftable';
  idDragEntity::~idDragEntity(this: (idActor *)&v15, result: v5);
  if ( num > 0 )
  {
    p_data = &list->value.data;
    do
    {
      v9 = *(p_data - 8);
      v10 = 0;
      if ( *v9 != 0 )
      {
        do
          ++v10;
        while ( v9[v10] != 0 );
      }
      v17 = *(p_data - 8);
      CRC32_UpdateChecksum(crcvalue: &v15, data: v9, length: v10);
      v11 = *p_data;
      v12 = 0;
      if ( **p_data != 0 )
      {
        do
          ++v12;
        while ( v11[v12] != 0 );
      }
      v17 = *p_data;
      CRC32_UpdateChecksum(crcvalue: &v15, data: v11, length: v12);
      --num;
      p_data += 16;
    }
    while ( num != 0 );
  }
  CRC32_FinishChecksum(crcvalue: &v15);
  v13 = v15;
  if ( (v18[0].listStatic == 0 || v18[0].listStatic == 2) && list != nullptr )
    idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &list->key, num: v18[0].size);
  return v13;
}


// ========================================================================
// __unwind$115031
// EA  : 0x82F025F4
// RVA : 0x00F025F4
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_115031()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$115032
// EA  : 0x82F0261C
// RVA : 0x00F0261C
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_115032()
{
  int v0; // r12

  idSort_KeyValue::~idSort_KeyValue(this: (idSort_KeyValue *)(v0 - 160 + 84));
}


// ========================================================================
// ?Set@idDict@@QAA_NPBD0@Z
// EA  : 0x82F027C8
// RVA : 0x00F027C8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

int __fastcall idDict::Set(idDict *this, const char *key, const char *value)
{
  int KeyIndex; // r3
  int v7; // r28
  idHashIndex *p_argHash; // r30
  char *data; // r29
  int v11; // r3
  int v12; // r28
  int KeyForString; // r3
  idXMLAttribute v14; // [sp+50h] [-70h] BYREF

  v14.name.len = 0;
  v14.name.baseBuffer[0] = 0;
  v14.name.allocedAndFlag = 20;
  v14.value.len = 0;
  v14.name.data = v14.name.baseBuffer;
  v14.value.data = v14.value.baseBuffer;
  v14.value.baseBuffer[0] = 0;
  v14.value.allocedAndFlag = 20;
  KeyIndex = idDict::FindKeyIndex(this, key);
  if ( KeyIndex == -1 )
  {
    idStr::operator=(this: &v14.name, text: key);
    idStr::operator=(this: &v14.value, text: value);
    data = v14.name.data;
    v11 = idList<idXMLAttribute,44>::Append(
            (idList<idXMLAttribute,44> *)this,
            obj: (const idTarget_Cvar::keyVal_t *)&v14);
    p_argHash = &this->argHash;
    v12 = v11;
    KeyForString = idHashIndex::GenerateKeyForString(this: p_argHash, string: data, caseSensitive: false);
    idHashIndex::Add(this: p_argHash, key: KeyForString, index: v12);
  }
  else
  {
    v7 = KeyIndex << 6;
    if ( idStr::Icmp(s1: this->args.list[KeyIndex].value.data, s2: value) == 0 )
    {
      idKeyValue::~idKeyValue(this: &v14);
      return 0;
    }
    idStr::operator=(this: (idStr *)((char *)&this->args.list->value + v7), text: value);
  }
  idKeyValue::~idKeyValue(this: &v14);
  return 1;
}


// ========================================================================
// __unwind$115632
// EA  : 0x82F028DC
// RVA : 0x00F028DC
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_115632()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 192 + 80));
}


// ========================================================================
// ?WriteToIniFile@idDict@@QBAXPAVidFile@@@Z
// EA  : 0x82F02910
// RVA : 0x00F02910
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void __fastcall idDict::WriteToIniFile(idDict *this, idFile *f)
{
  __int64 v3; // r10
  int v4; // r8
  int v5; // r7
  int v6; // r6
  idKeyValue *list; // r18
  int num; // r27
  idStr *v9; // r23
  int size; // r30
  _DWORD *v11; // r20
  __int64 v12; // r10
  __int64 v13; // r8
  int *v14; // r29
  idStr *p_key; // r30
  int i; // r25
  __int64 v17; // r10
  __int64 v18; // r8
  int v19; // r6
  int len; // r23
  idStr *v21; // r3
  __int64 v22; // r6
  va *v23; // r3
  int v24; // r25
  int v25; // r29
  _DWORD *v26; // r22
  char **p_data; // r26
  __int64 v28; // r6
  idStr *v29; // r11
  __int64 v30; // r10
  va *v31; // r3
  __int64 v32; // r6
  va *v33; // r3
  idStr *v34; // r29
  int v35; // [sp+8h] [-11C8h]
  int v36; // [sp+Ch] [-11C4h]
  int v37; // [sp+10h] [-11C0h]
  int v38; // [sp+14h] [-11BCh]
  int v39; // [sp+18h] [-11B8h]
  int v40; // [sp+1Ch] [-11B4h]
  idSort_Quick<idKeyValue,idSort_KeyValue> v41; // [sp+50h] [-1180h] BYREF
  idList<idStr,5> v42; // [sp+60h] [-1170h] BYREF
  idList<idKeyValue,5> v43; // [sp+70h] [-1160h] BYREF
  _DWORD *v44; // [sp+80h] [-1150h]
  int v45; // [sp+84h] [-114Ch]
  idStr *v46; // [sp+88h] [-1148h]
  idStr v47; // [sp+90h] [-1140h] BYREF
  idStr v48; // [sp+B0h] [-1120h] BYREF
  idStr v49; // [sp+D0h] [-1100h] BYREF
  idStr v50; // [sp+F0h] [-10E0h] BYREF
  idStr v51; // [sp+110h] [-10C0h] BYREF
  idStr v52; // [sp+130h] [-10A0h] BYREF
  va v53; // [sp+150h] [-1080h] BYREF

  v43.list = nullptr;
  v43.listStatic = 0;
  idList<idKeyValue,5>::operator=(this: &v43, other: &this->args);
  v41.__vftable = (idSort_Quick<idKeyValue,idSort_KeyValue>_vtbl *)&idSort_KeyValue::`vftable';
  list = v43.list;
  num = v43.num;
  if ( v43.list != nullptr )
    idSort_Quick<idKeyValue,idSort_KeyValue>::Sort(
      this: &v41,
      base: v43.list,
      num: v43.num,
      a4: v6,
      a5: v5,
      a6: v4,
      a7: v3);
  *(_WORD *)&v42.memTag = 1280;
  v9 = nullptr;
  size = 0;
  v41.__vftable = (idSort_Quick<idKeyValue,idSort_KeyValue>_vtbl *)&idSort<idKeyValue>::`vftable';
  memset(&v42, 0, 14);
  v45 = num;
  v11 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
          size: 4 * num,
          tag: TAG_TEMP,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v44 = v11;
  idStr::idStr(this: &v47, text: &byte_8200D768);
  idStr::idStr(this: &v51, text: &byte_8200D768);
  if ( num > 0 )
  {
    v14 = v11;
    p_key = &list->key;
    for ( i = num; i != 0; --i )
    {
      v19 = idStr::Last(this: p_key, c: 47, index: -1);
      if ( v19 == -1 )
      {
        *v14 = 0;
        LODWORD(v22) = p_key[1].data;
        HIDWORD(v22) = p_key->data;
        v23 = va::va(
                this: &v53,
                fmt: "%s=%s\n",
                a3: v22,
                a4: v18,
                a5: v17,
                a6: v35,
                a7: v36,
                a8: v37,
                a9: v38,
                a10: v39,
                a11: v40);
        idStr::idStr(this: &v52, text: v23);
        f->Write(this: f, a2: v52.data, a3: v52.len);
        idStr::operator=(this: &v51, text: "\n");
        v21 = &v52;
      }
      else
      {
        idStr::Mid(this: &v48, result: p_key, start: 0, len: v19);
        if ( idStr::Cmp(s1: v48.data, s2: v47.data) != 0 )
        {
          len = v48.len;
          idStr::EnsureAlloced(this: &v47, amount: v48.len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: v47.data, Src: v48.data, Size: len);
          v47.data[len] = 0;
          v47.len = len;
          idList<idStr,5>::Append(this: &v42, obj: &v48);
        }
        *v14 = v42.num;
        v21 = &v48;
      }
      idStr::FreeData(this: v21);
      p_key += 2;
      ++v14;
    }
    size = v42.size;
    v9 = v42.list;
  }
  v24 = 0;
  v25 = 0;
  if ( num > 0 )
  {
    v26 = v11;
    p_data = &list->key.data;
    do
    {
      LODWORD(v12) = *v26;
      if ( *v26 != 0 )
      {
        if ( (_DWORD)v12 != v24 )
        {
          HIDWORD(v28) = v51.data;
          v24 = *v26;
          v29 = &v9[v12];
          HIDWORD(v30) = v29 - 1;
          v46 = v29 - 1;
          LODWORD(v30) = v29[-1].len;
          LODWORD(v28) = v29[-1].data;
          v25 = v30 + 1;
          v31 = va::va(
                  this: &v53,
                  fmt: "%s[%s]\n",
                  a3: v28,
                  a4: v13,
                  a5: v30,
                  a6: v35,
                  a7: v36,
                  a8: v37,
                  a9: v38,
                  a10: v39,
                  a11: v40);
          idStr::idStr(this: &v49, text: v31);
          f->Write(this: f, a2: v49.data, a3: v49.len);
          idStr::FreeData(this: &v49);
        }
        LODWORD(v32) = p_data[8];
        HIDWORD(v32) = &(*p_data)[v25];
        v33 = va::va(
                this: &v53,
                fmt: "%s=%s\n",
                a3: v32,
                a4: v13,
                a5: v12,
                a6: v35,
                a7: v36,
                a8: v37,
                a9: v38,
                a10: v39,
                a11: v40);
        idStr::idStr(this: &v50, text: v33);
        f->Write(this: f, a2: v50.data, a3: v50.len);
        idStr::FreeData(this: &v50);
      }
      --num;
      ++v26;
      p_data += 16;
    }
    while ( num != 0 );
  }
  idStr::FreeData(this: &v51);
  idStr::FreeData(this: &v47);
  if ( v11 != nullptr )
    idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
  if ( (v42.listStatic == 0 || v42.listStatic == 2) && v9 != nullptr )
  {
    if ( size > 0 )
    {
      v34 = v9;
      do
      {
        idStr::FreeData(this: v34);
        --size;
        ++v34;
      }
      while ( size != 0 );
    }
    idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
  }
  if ( (v43.listStatic == 0 || v43.listStatic == 2) && list != nullptr )
    idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &list->key, num: v43.size);
}


// ========================================================================
// __unwind$116128
// EA  : 0x82F02CB0
// RVA : 0x00F02CB0
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116128()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(v0 - 4560 + 112));
}


// ========================================================================
// __unwind$116129
// EA  : 0x82F02CD8
// RVA : 0x00F02CD8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116129()
{
  int v0; // r12

  idSort_KeyValue::~idSort_KeyValue(this: (idSort_KeyValue *)(v0 - 4560 + 80));
}


// ========================================================================
// __unwind$116130
// EA  : 0x82F02D00
// RVA : 0x00F02D00
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116130()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4560 + 96));
}


// ========================================================================
// __unwind$116131
// EA  : 0x82F02D28
// RVA : 0x00F02D28
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116131()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 4560 + 128));
}


// ========================================================================
// __unwind$116132
// EA  : 0x82F02D50
// RVA : 0x00F02D50
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116132()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 144));
}


// ========================================================================
// __unwind$116133
// EA  : 0x82F02D78
// RVA : 0x00F02D78
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116133()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 272));
}


// ========================================================================
// __unwind$116134
// EA  : 0x82F02DA0
// RVA : 0x00F02DA0
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116134()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 176));
}


// ========================================================================
// __unwind$116135
// EA  : 0x82F02DC8
// RVA : 0x00F02DC8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116135()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 304));
}


// ========================================================================
// __unwind$116136
// EA  : 0x82F02DF0
// RVA : 0x00F02DF0
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116136()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 208));
}


// ========================================================================
// __unwind$116137
// EA  : 0x82F02E18
// RVA : 0x00F02E18
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116137()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 240));
}


// ========================================================================
// ?ReadFromIniFile@idDict@@QAA_NPAVidFile@@@Z
// EA  : 0x82F02E48
// RVA : 0x00F02E48
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

int __fastcall idDict::ReadFromIniFile(idDict *this, idFile *f)
{
  unsigned int v4; // r29
  void *v5; // r25
  const char *v7; // r3
  int v8; // r29
  bool v9; // r3
  char v10; // r11
  char v11; // r29
  bool v12; // r3
  unsigned __int8 v13; // r11
  __int64 v14; // r10
  __int64 v15; // r8
  bool v16; // r3
  char v17; // r11
  bool v18; // r3
  char v19; // r11
  const char *v20; // r3
  unsigned __int8 v21; // r11
  va *v22; // r3
  int v23; // [sp+8h] [-1258h]
  int v24; // [sp+Ch] [-1254h]
  int v25; // [sp+10h] [-1250h]
  int v26; // [sp+14h] [-124Ch]
  int v27; // [sp+18h] [-1248h]
  int v28; // [sp+1Ch] [-1244h]
  idStr v29; // [sp+50h] [-1210h] BYREF
  idToken v30; // [sp+70h] [-11F0h] BYREF
  idStr v31; // [sp+C0h] [-11A0h] BYREF
  void *v32; // [sp+E0h] [-1180h]
  unsigned int v33; // [sp+E4h] [-117Ch]
  idToken v34; // [sp+F0h] [-1170h] BYREF
  idStr v35; // [sp+140h] [-1120h] BYREF
  idStr v36; // [sp+160h] [-1100h] BYREF
  idLexer v37; // [sp+180h] [-10E0h] BYREF
  va v38; // [sp+210h] [-1050h] BYREF

  v4 = f->Length(this: f);
  v33 = v4;
  v5 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
         size: v4,
         tag: TAG_TEMP,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v32 = v5;
  if ( f->Read(this: f, a2: v5, a3: v4) != v4 )
  {
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    return 0;
  }
  idLexer::idLexer(this: &v37, flags_: 516);
  v7 = f->GetName(this: f);
  idStr::idStr(this: &v35, text: v7);
  idStr::Append(this: &v35, text: " dictionary INI reader");
  if ( idLexer::LoadMemory(this: &v37, ptr: (const char *)v5, length_: v4, name: v35.data) )
  {
    v30.len = 0;
    v30.allocedAndFlag = 20;
    v30.data = v30.baseBuffer;
    v30.floatvalue = -3.4028235e38;
    v30.baseBuffer[0] = 0;
    v30.intvalue = 0;
    memset(&v30.whiteSpaceStart_p, 0, 12);
    v34.floatvalue = -3.4028235e38;
    v34.allocedAndFlag = 20;
    v34.data = v34.baseBuffer;
    v34.len = 0;
    v34.baseBuffer[0] = 0;
    v34.intvalue = 0;
    memset(&v34.whiteSpaceStart_p, 0, 12);
    idStr::idStr(this: &v29, text: &byte_8200D768);
    v31.allocedAndFlag = 20;
    v31.data = v31.baseBuffer;
    v31.len = 0;
    v31.baseBuffer[0] = 0;
    v8 = 1;
    idDict::Clear(this);
    do
    {
      if ( idLexer::EndOfFile(this: &v37) )
        break;
      if ( idLexer::PeekTokenType(this: &v37, type: 5, subtype: 48, token: &v30) )
      {
        if ( (_BYTE)v8 == 0
          || (v9 = idLexer::ExpectTokenType(this: &v37, type: 5, subtype: 48, token: &v30), v10 = 1, !v9) )
        {
          v10 = 0;
        }
        if ( v10 == 0 || (v11 = 1, !idLexer::ReadToken(this: &v37, token: &v30)) )
          v11 = 0;
        idStr::operator=(this: &v29, text: v30.data);
        idStr::EnsureAlloced(this: &v29, amount: v29.len + 2, keepold: true, geometricGrowth: true);
        v29.data[v29.len++] = 47;
        v29.data[v29.len] = 0;
        if ( v11 == 0 || (v12 = idLexer::ExpectTokenType(this: &v37, type: 5, subtype: 49, token: &v30), v13 = 1, !v12) )
          v13 = 0;
        v8 = v13;
      }
      if ( !idLexer::PeekTokenType(this: &v37, type: 4, subtype: 0, token: &v30) )
        break;
      if ( (_BYTE)v8 != 0 )
      {
        v16 = idLexer::ExpectTokenType(this: &v37, type: 4, subtype: 0, token: &v30);
        v17 = 1;
        if ( v16 )
          continue;
      }
      v17 = 0;
      if ( v17 != 0 )
      {
        v18 = idLexer::ExpectTokenType(this: &v37, type: 5, subtype: 32, token: &v34);
        v19 = 1;
        if ( v18 )
          continue;
      }
      v19 = 0;
      if ( v19 != 0 )
      {
        v20 = idLexer::ParseRestOfLine(this: &v37, out: &v31);
        v21 = 1;
        if ( v20 != nullptr )
          continue;
      }
      v21 = 0;
      v8 = v21;
      v22 = va::va(
              this: &v38,
              fmt: "%s%s",
              a3: __SPAIR64__((unsigned int)v29.data, (unsigned int)v30.data),
              a4: v15,
              a5: v14,
              a6: v23,
              a7: v24,
              a8: v25,
              a9: v26,
              a10: v27,
              a11: v28);
      idStr::idStr(this: &v36, text: v22);
      if ( idDict::FindKey(this, key: v36.data) != nullptr )
        idLexer::Warning(this: &v37, str: "'%s' already defined", v36.data);
      idDict::Set(this, key: v36.data, value: v31.data);
      idStr::FreeData(this: &v36);
    }
    while ( (_BYTE)v8 != 0 );
    idStr::FreeData(this: &v31);
    idStr::FreeData(this: &v29);
    idStr::FreeData(this: &v34);
    idStr::FreeData(this: &v30);
    idStr::FreeData(this: &v35);
    idLexer::~idLexer(this: &v37);
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    return v8;
  }
  else
  {
    idStr::FreeData(this: &v35);
    idLexer::~idLexer(this: &v37);
    if ( v5 == nullptr )
      return 0;
    idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    return 0;
  }
}


// ========================================================================
// __unwind$116540
// EA  : 0x82F032A8
// RVA : 0x00F032A8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116540()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 4704 + 224));
}


// ========================================================================
// __unwind$116541
// EA  : 0x82F032D0
// RVA : 0x00F032D0
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116541()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 4704 + 384));
}


// ========================================================================
// __unwind$116542
// EA  : 0x82F032F8
// RVA : 0x00F032F8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116542()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4704 + 320));
}


// ========================================================================
// __unwind$116543
// EA  : 0x82F03320
// RVA : 0x00F03320
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116543()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4704 + 112));
}


// ========================================================================
// __unwind$116544
// EA  : 0x82F03348
// RVA : 0x00F03348
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116544()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4704 + 240));
}


// ========================================================================
// __unwind$116545
// EA  : 0x82F03370
// RVA : 0x00F03370
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116545()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4704 + 80));
}


// ========================================================================
// __unwind$116546
// EA  : 0x82F03398
// RVA : 0x00F03398
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116546()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4704 + 192));
}


// ========================================================================
// __unwind$116547
// EA  : 0x82F033C0
// RVA : 0x00F033C0
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116547()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4704 + 352));
}


// ========================================================================
// ?Parse@idDict@@QAA_NAAVidLexer@@PBD1@Z
// EA  : 0x82F033F0
// RVA : 0x00F033F0
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

BOOL __fastcall idDict::Parse(idDict *this, idLexer *parser, const char *start, const char *end)
{
  unsigned __int8 v7; // r28
  idToken v9; // [sp+50h] [-D0h] BYREF
  idToken v10; // [sp+A0h] [-80h] BYREF

  v9.len = 0;
  v9.baseBuffer[0] = 0;
  v9.floatvalue = -3.4028235e38;
  v9.intvalue = 0;
  memset(&v9.whiteSpaceStart_p, 0, 12);
  v9.allocedAndFlag = 20;
  v9.data = v9.baseBuffer;
  v10.floatvalue = -3.4028235e38;
  v10.len = 0;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v7 = 0;
  if ( idLexer::ExpectTokenString(this: parser, string: start) )
  {
    idLexer::ReadToken(this: parser, token: &v9);
    while ( v9.type != 5 || idStr::Cmp(s1: v9.data, s2: end) != 0 )
    {
      if ( v9.type != 1 )
      {
        idLexer::Error(this: parser, str: "Expected quoted string, but found '%s'", v9.data);
        break;
      }
      if ( idLexer::ReadToken(this: parser, token: &v10) )
      {
        if ( idDict::FindKey(this, key: v9.data) != nullptr )
        {
          idLexer::Warning(this: parser, str: "'%s' already defined", v9.data);
          v7 = 1;
        }
        idDict::Set(this, key: v9.data, value: v10.data);
        if ( idLexer::ReadToken(this: parser, token: &v9) )
          continue;
      }
      idLexer::Error(this: parser, str: "Unexpected end of file");
      break;
    }
    idStr::FreeData(this: &v10);
    idStr::FreeData(this: &v9);
    return (_cntlzw(v7) & 0x20) != 0;
  }
  else
  {
    idStr::FreeData(this: &v10);
    idStr::FreeData(this: &v9);
    return false;
  }
}


// ========================================================================
// __unwind$116827
// EA  : 0x82F03594
// RVA : 0x00F03594
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116827()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$116828
// EA  : 0x82F035BC
// RVA : 0x00F035BC
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116828()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 160));
}


// ========================================================================
// ?TestDictIniFile_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F035F0
// RVA : 0x00F035F0
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void __fastcall TestDictIniFile_f(const idCmdArgs *args)
{
  idFile *v1; // r30
  __int64 v2; // r6
  __int64 v3; // r10
  __int64 v4; // r8
  va *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  unsigned int v8; // r6
  va *v9; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  va *v13; // r3
  __int64 v14; // r8
  __int64 v15; // r10
  va *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  unsigned int v19; // r6
  va *v20; // r3
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  va *v24; // r3
  idFile *v25; // r30
  unsigned int v26; // r30
  int num; // r11
  int v28; // r30
  int v29; // r29
  idKeyValue *v30; // r11
  int v31; // [sp+8h] [-10E8h]
  int v32; // [sp+8h] [-10E8h]
  int v33; // [sp+8h] [-10E8h]
  int v34; // [sp+8h] [-10E8h]
  int v35; // [sp+8h] [-10E8h]
  int v36; // [sp+8h] [-10E8h]
  int v37; // [sp+Ch] [-10E4h]
  int v38; // [sp+Ch] [-10E4h]
  int v39; // [sp+Ch] [-10E4h]
  int v40; // [sp+Ch] [-10E4h]
  int v41; // [sp+Ch] [-10E4h]
  int v42; // [sp+Ch] [-10E4h]
  int v43; // [sp+10h] [-10E0h]
  int v44; // [sp+10h] [-10E0h]
  int v45; // [sp+10h] [-10E0h]
  int v46; // [sp+10h] [-10E0h]
  int v47; // [sp+10h] [-10E0h]
  int v48; // [sp+10h] [-10E0h]
  int v49; // [sp+14h] [-10DCh]
  int v50; // [sp+14h] [-10DCh]
  int v51; // [sp+14h] [-10DCh]
  int v52; // [sp+14h] [-10DCh]
  int v53; // [sp+14h] [-10DCh]
  int v54; // [sp+14h] [-10DCh]
  int v55; // [sp+18h] [-10D8h]
  int v56; // [sp+18h] [-10D8h]
  int v57; // [sp+18h] [-10D8h]
  int v58; // [sp+18h] [-10D8h]
  int v59; // [sp+18h] [-10D8h]
  int v60; // [sp+18h] [-10D8h]
  int v61; // [sp+1Ch] [-10D4h]
  int v62; // [sp+1Ch] [-10D4h]
  int v63; // [sp+1Ch] [-10D4h]
  int v64; // [sp+1Ch] [-10D4h]
  int v65; // [sp+1Ch] [-10D4h]
  int v66; // [sp+1Ch] [-10D4h]
  idDict v67; // [sp+50h] [-10A0h] BYREF
  idDict v68; // [sp+80h] [-1070h] BYREF
  va v69; // [sp+B0h] [-1040h] BYREF

  v1 = fileSystem->OpenFileWrite(this: fileSystem, a2: "idDict_ini_test.ini", a3: 2);
  if ( v1 != nullptr )
  {
    idDict::idDict(this: &v67);
    HIDWORD(v2) = -1;
    v5 = va::va(this: &v69, fmt: "%i", a3: v2, a4: v4, a5: v3, a6: v31, a7: v37, a8: v43, a9: v49, a10: v55, a11: v61);
    idDict::Set(this: &v67, key: "section1/section3/a", value: v5->buffer);
    v9 = va::va(this: &v69, fmt: "%i", a3: v8, a4: v7, a5: v6, a6: v32, a7: v38, a8: v44, a9: v50, a10: v56, a11: v62);
    idDict::Set(this: &v67, key: "section1/section3/b", value: v9->buffer);
    HIDWORD(v10) = 3;
    v13 = va::va(
            this: &v69,
            fmt: "%i",
            a3: v10,
            a4: v12,
            a5: v11,
            a6: v33,
            a7: v39,
            a8: v45,
            a9: v51,
            a10: v57,
            a11: v63);
    idDict::Set(this: &v67, key: "section1/section3/c", value: v13->buffer);
    HIDWORD(v14) = &unk_82380000;
    v16 = va::va(
            this: &v69,
            fmt: (const char *)0x40100000,
            a3: (unsigned int)&unk_821D0000,
            a4: v14,
            a5: v15,
            a6: v34,
            a7: v40,
            a8: v46,
            a9: v52,
            a10: v58,
            a11: v64);
    idDict::Set(this: &v67, key: "section2/d", value: v16->buffer);
    v20 = va::va(
            this: &v69,
            fmt: (const char *)0xC0140000,
            a3: v19,
            a4: v18,
            a5: v17,
            a6: v35,
            a7: v41,
            a8: v47,
            a9: v53,
            a10: v59,
            a11: v65);
    idDict::Set(this: &v67, key: "section2/e", value: v20->buffer);
    idDict::Set(this: &v67, key: "section2/f", value: "1");
    idDict::Set(this: &v67, key: "section1/g", value: "0");
    idDict::Set(this: &v67, key: "section1/h", value: "test1");
    idDict::Set(this: &v67, key: "i", value: "1234");
    HIDWORD(v21) = 9;
    v24 = va::va(
            this: &v69,
            fmt: "%i",
            a3: v21,
            a4: v23,
            a5: v22,
            a6: v36,
            a7: v42,
            a8: v48,
            a9: v54,
            a10: v60,
            a11: v66);
    idDict::Set(this: &v67, key: "j", value: v24->buffer);
    idDict::WriteToIniFile(this: &v67, f: v1);
    ((void (__fastcall *)(idFile *, int))v1->dtr_idFile)(a1: v1, a2: 1);
    v25 = fileSystem->OpenFileRead(this: fileSystem, a2: "idDict_ini_test.ini", a3: 1, a4: 0);
    if ( v25 == nullptr )
      idLib::Printf(fmt: "[^1FAILED^0] Couldn't open file for reading.\n");
    idDict::idDict(this: &v68);
    idDict::ReadFromIniFile(this: &v68, f: v25);
    if ( v25 != nullptr )
      ((void (__fastcall *)(idFile *, int))v25->dtr_idFile)(a1: v25, a2: 1);
    v26 = idDict::Checksum(this: &v68);
    if ( idDict::Checksum(this: &v67) == v26 )
      idLib::Printf(fmt: "[^2PASSED^0] Dictionaries match.\n");
    else
      idLib::Printf(fmt: "[^1FAILED^0] Dictionaries do not match.\n");
    num = v68.args.num;
    v28 = 0;
    if ( v68.args.num > 0 )
    {
      v29 = 0;
      do
      {
        if ( v28 < 0 || v28 >= num )
          v30 = nullptr;
        else
          v30 = &v68.args.list[v29];
        idLib::Printf(fmt: "%s=%s\n", v30->key.data, v30->value.data);
        num = v68.args.num;
        ++v28;
        ++v29;
      }
      while ( v28 < v68.args.num );
    }
    idDict::~idDict(this: &v68);
    idDict::~idDict(this: &v67);
  }
  else
  {
    idLib::Printf(fmt: "[^1FAILED^0] Couldn't open file for writing.\n");
  }
}


// ========================================================================
// __unwind$116998
// EA  : 0x82F038EC
// RVA : 0x00F038EC
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116998()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(v0 - 4336 + 80));
}


// ========================================================================
// __unwind$116999
// EA  : 0x82F03914
// RVA : 0x00F03914
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

void _unwind_116999()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(v0 - 4336 + 128));
}


// ========================================================================
// `dynamic initializer for 'TestDictIniFile_v''
// EA  : 0x833945A8
// RVA : 0x013945A8
// PDB : w:\tech5\shared\idlib\dict.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestDictIniFile_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestDictIniFile_v,
           cmdName: "TestDictIniFile",
           function: TestDictIniFile_f,
           description: "Tests the writing/reading of various items in a dict to/from an ini file",
           argCompletion: nullptr);
}

