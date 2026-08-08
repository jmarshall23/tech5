
// ========================================================================
// ?Clear@?$idHashTableT@HPBVidDeclVehicleUnlock@@@@QAAXXZ
// EA  : 0x829F5BF8
// RVA : 0x009F5BF8
// PDB : w:\tech5\shared\idlib\containers\hashtable.h
// ========================================================================

void __fastcall idHashTableT<int,idDeclVehicleUnlock const *>::Clear(idHashTableT<int,idAIAction *> *this)
{
  int v2; // r28
  int v3; // r30
  idHashNodeT<int,idAIAction *> *v4; // r31
  idHashNodeT<int,idAIAction *> *v5; // r4

  v2 = 0;
  if ( this->tableSize > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->heads[v3];
      while ( v4 != nullptr )
      {
        v5 = v4;
        v4 = v4->next;
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      }
      ++v2;
      this->heads[v3++] = nullptr;
    }
    while ( v2 < this->tableSize );
  }
  this->numEntries = 0;
}


// ========================================================================
// ??1?$idHashTableT@HPAVidAIAction@@@@QAA@XZ
// EA  : 0x829FBB90
// RVA : 0x009FBB90
// PDB : w:\tech5\shared\idlib\containers\hashtable.h
// ========================================================================

void __fastcall idHashTableT<int,idAIAction *>::~idHashTableT<int,idAIAction *>(idHashTableT<int,idAIAction *> *this)
{
  idHashTableT<int,idDeclVehicleUnlock const *>::Clear(this);
  idMem::Free(this: &mem, ptr: this->heads, align: ALIGN_16);
  this->heads = nullptr;
  this->tableSize = 0;
  this->tableSizeMask = 0;
  this->numEntries = 0;
}


// ========================================================================
// ?Get@?$idHashTableT@HPAVidAIAction@@@@QAA_NABHPAPAPAVidAIAction@@@Z
// EA  : 0x82AA3018
// RVA : 0x00AA3018
// PDB : w:\tech5\shared\idlib\containers\hashtable.h
// ========================================================================

int __fastcall idHashTableT<int,idAIAction *>::Get(idHashTableT<int,idAIAction *> *this, int *key, idAIAction ***value)
{
  int v3; // r9
  idHashNodeT<int,idAIAction *> *v4; // r11

  v3 = *key;
  v4 = this->heads[this->tableSizeMask & *key];
  if ( v4 == nullptr )
    goto LABEL_4;
  while ( v4->key < v3 )
  {
    v4 = v4->next;
    if ( v4 == nullptr )
      goto LABEL_4;
  }
  if ( v4->key <= v3 )
  {
    if ( value != nullptr )
      *value = &v4->value;
    return 1;
  }
  else
  {
LABEL_4:
    if ( value != nullptr )
      *value = nullptr;
    return 0;
  }
}


// ========================================================================
// ?Set@?$idHashTableT@HPAVidAIAction@@@@QAAAAPAVidAIAction@@ABHABQAV2@@Z
// EA  : 0x82BCBEB8
// RVA : 0x00BCBEB8
// PDB : w:\tech5\shared\idlib\containers\hashtable.h
// ========================================================================

idAIAction **__fastcall idHashTableT<int,idAIAction *>::Set(
        idHashTableT<int,idAIAction *> *this,
        int *key,
        idAIAction **value)
{
  int v3; // r11
  int v7; // r27
  idHashNodeT<int,idAIAction *> **p_next; // r29
  idHashNodeT<int,idAIAction *> *v9; // r31
  idHashNodeT<int,idAIAction *> *v10; // r3
  idHashNodeT<int,idAIAction *> *v11; // r11
  idHashNodeT<int,idAIAction *> *v12; // r8

  v3 = *key;
  v7 = this->tableSizeMask & *key;
  p_next = &this->heads[v7];
  v9 = *p_next;
  if ( *p_next == nullptr )
    goto LABEL_4;
  while ( v9->key < v3 )
  {
    p_next = &v9->next;
    v9 = v9->next;
    if ( v9 == nullptr )
      goto LABEL_4;
  }
  if ( v9->key <= v3 )
  {
    v9->value = *value;
    return &v9->value;
  }
  else
  {
LABEL_4:
    ++this->numEntries;
    v10 = (idHashNodeT<int,idAIAction *> *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                             size: 0xCu,
                                             tag: TAG_HASHTABLE,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
    if ( v10 != nullptr )
    {
      v11 = v10;
      v12 = this->heads[v7];
      v10->key = *key;
      v10->value = *value;
      v10->next = v12;
    }
    else
    {
      v11 = nullptr;
    }
    *p_next = v11;
    v11->next = v9;
    return &(*p_next)->value;
  }
}


// ========================================================================
// ?GetIndex@?$idHashTableT@PBDVidMetricFile@@@@QBAPAVidMetricFile@@H@Z
// EA  : 0x82F3CBD8
// RVA : 0x00F3CBD8
// PDB : w:\tech5\shared\idlib\containers\hashtable.h
// ========================================================================

idMetricFile *__fastcall idHashTableT<char const *,idMetricFile>::GetIndex(
        idHashTableT<char const *,idMetricFile> *this,
        int index)
{
  int tableSize; // r7
  int v3; // r10
  int v4; // r8
  int i; // r9
  idHashNodeT<char const *,idMetricFile> *v6; // r11

  if ( index < 0 )
    return nullptr;
  if ( index > this->numEntries )
    return nullptr;
  tableSize = this->tableSize;
  v3 = 0;
  v4 = 0;
  if ( tableSize <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v6 = this->heads[i];
    if ( v6 != nullptr )
      break;
LABEL_8:
    if ( ++v4 >= tableSize )
      return nullptr;
  }
  while ( v3 != index )
  {
    v6 = v6->next;
    ++v3;
    if ( v6 == nullptr )
      goto LABEL_8;
  }
  return &v6->value;
}


// ========================================================================
// ?Get@?$idHashTableT@PBDVidMetricFile@@@@QAA_NABQBDPAPAVidMetricFile@@@Z
// EA  : 0x82F3D138
// RVA : 0x00F3D138
// PDB : w:\tech5\shared\idlib\containers\hashtable.h
// ========================================================================

int __fastcall idHashTableT<char const *,idMetricFile>::Get(
        idHashTableT<char const *,idMetricFile> *this,
        const char **key,
        idMetricFile **value)
{
  const char *v3; // r9
  int v6; // r11
  unsigned __int8 v7; // r8
  idHashNodeT<char const *,idMetricFile> *v8; // r31
  int v9; // r3

  v3 = *key;
  v6 = 0;
  v7 = **key;
  if ( v7 != 0 )
  {
    do
    {
      ++v3;
      v6 = 31 * v6 + v7;
      v7 = *v3;
    }
    while ( *v3 != 0 );
  }
  v8 = this->heads[this->tableSizeMask & v6];
  if ( v8 != nullptr )
  {
    while ( 1 )
    {
      v9 = idStr::Icmp(s1: v8->key.data, s2: *key);
      if ( v9 == 0 )
        break;
      if ( v9 <= 0 )
      {
        v8 = v8->next;
        if ( v8 != nullptr )
          continue;
      }
      goto LABEL_7;
    }
    if ( value != nullptr )
      *value = &v8->value;
    return 1;
  }
  else
  {
LABEL_7:
    if ( value != nullptr )
      *value = nullptr;
    return 0;
  }
}


// ========================================================================
// ?Set@?$idHashTableT@PBDVidMetricFile@@@@QAAAAVidMetricFile@@ABQBDABV2@@Z
// EA  : 0x82F3D208
// RVA : 0x00F3D208
// PDB : w:\tech5\shared\idlib\containers\hashtable.h
// ========================================================================

idMetricFile *__fastcall idHashTableT<char const *,idMetricFile>::Set(
        idHashTableT<char const *,idMetricFile> *this,
        const char **key,
        const idMetricFile *value)
{
  const char *v3; // r9
  int v7; // r11
  unsigned __int8 v8; // r8
  int v9; // r26
  idHashNodeT<char const *,idMetricFile> **p_next; // r28
  idHashNodeT<char const *,idMetricFile> *v11; // r29
  int v12; // r3
  idStr *v13; // r3
  idStr *v14; // r30
  idHashNodeT<char const *,idMetricFile> *v15; // r26
  idHashNodeT<char const *,idMetricFile> *v16; // r11

  v3 = *key;
  v7 = 0;
  v8 = **key;
  if ( v8 != 0 )
  {
    do
    {
      ++v3;
      v7 = 31 * v7 + v8;
      v8 = *v3;
    }
    while ( *v3 != 0 );
  }
  v9 = this->tableSizeMask & v7;
  p_next = &this->heads[v9];
  v11 = *p_next;
  if ( *p_next != nullptr )
  {
    while ( 1 )
    {
      v12 = idStr::Icmp(s1: v11->key.data, s2: *key);
      if ( v12 == 0 )
        break;
      if ( v12 <= 0 )
      {
        p_next = &v11->next;
        v11 = v11->next;
        if ( v11 != nullptr )
          continue;
      }
      goto LABEL_7;
    }
    *(_QWORD *)&v11->value.fileHandle = *(_QWORD *)&value->fileHandle;
    v11->value.startTime = value->startTime;
    return &v11->value;
  }
  else
  {
LABEL_7:
    ++this->numEntries;
    v13 = (idStr *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x38u,
                     tag: TAG_HASHTABLE,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
    v14 = v13;
    if ( v13 != nullptr )
    {
      v15 = this->heads[v9];
      idStr::idStr(this: v13, text: *key);
      v16 = (idHashNodeT<char const *,idMetricFile> *)v14;
      v14[1].len = (int)value->fileHandle;
      v14[1].data = *(char **)&value->headerWritten;
      v14[1].allocedAndFlag = HIDWORD(value->startTime);
      *(_DWORD *)v14[1].baseBuffer = value->startTime;
      *(_DWORD *)&v14[1].baseBuffer[4] = v15;
    }
    else
    {
      v16 = nullptr;
    }
    *p_next = v16;
    v16->next = v11;
    return &(*p_next)->value;
  }
}


// ========================================================================
// __unwind$112170
// EA  : 0x82F3D358
// RVA : 0x00F3D358
// PDB : w:\tech5\shared\idlib\containers\hashtable.h
// ========================================================================

void _unwind_112170()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_HASHTABLE);
}


// ========================================================================
// ?Clear@?$idHashTableT@PBDVidMetricFile@@@@QAAXXZ
// EA  : 0x82F3D388
// RVA : 0x00F3D388
// PDB : w:\tech5\shared\idlib\containers\hashtable.h
// ========================================================================

void __fastcall idHashTableT<char const *,idMetricFile>::Clear(idHashTableT<char const *,idMetricFile> *this)
{
  int v2; // r28
  int v3; // r30
  idHashNodeT<char const *,idMetricFile> *v4; // r31
  idHashNodeT<char const *,idMetricFile> *v5; // r25
  idStr *p_key; // r3

  v2 = 0;
  if ( this->tableSize > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->heads[v3];
      while ( v4 != nullptr )
      {
        v5 = v4;
        p_key = &v4->key;
        v4 = v4->next;
        idStr::FreeData(this: p_key);
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      }
      ++v2;
      this->heads[v3++] = nullptr;
    }
    while ( v2 < this->tableSize );
  }
  this->numEntries = 0;
}

