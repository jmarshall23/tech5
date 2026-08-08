
// ========================================================================
// ?IsStringId@idLangDict@@SA_NPBD@Z
// EA  : 0x82F2CD90
// RVA : 0x00F2CD90
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

BOOL __fastcall idLangDict::IsStringId(const char *str)
{
  return (_cntlzw(idStr::Icmpn(s1: str, s2: idLangDict::KEY_PREFIX, n: idLangDict::KEY_PREFIX_LEN)) & 0x20) != 0;
}


// ========================================================================
// ?Save@idLangDict@@QAA_NPBD@Z
// EA  : 0x82F2CDC8
// RVA : 0x00F2CDC8
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

int __fastcall idLangDict::Save(idLangDict *this, const char *fileName)
{
  int v4; // r3
  int v5; // r31
  int v7; // r20
  int v8; // r23
  idLangKeyValue *v9; // r29
  char *value; // r11
  int v11; // r30
  const char *v12; // r4
  int v13; // r3
  void (__fastcall *v14)(int, const char *, int); // ctr
  int v15; // r5
  char v16; // [sp+50h] [-70h] BYREF
  _BYTE v17[110]; // [sp+52h] [-6Eh] BYREF

  v4 = ((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  v5 = v4;
  if ( v4 == 0 )
  {
    idLib::Warning(fmt: "Error saving: %s", fileName);
    return 0;
  }
  v17[0] = -17;
  v17[1] = -69;
  v17[2] = -65;
  (*(void (__fastcall **)(int, _BYTE *, int))(*(_DWORD *)v4 + 16))(a1: v4, a2: v17, a3: 3);
  (*(void (__fastcall **)(int, const char *))(*(_DWORD *)v5 + 60))(a1: v5, a2: "// string table\n//\n\n{\n");
  v7 = 0;
  if ( this->keyVals.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &this->keyVals.list[v8];
      if ( v9->value != nullptr )
      {
        (*(void (**)(int, const char *, ...))(*(_DWORD *)v5 + 60))(a1: v5, a2: "\t\"%s\"\t\"", v9->key);
        value = v9->value;
        v11 = 0;
        if ( *value != 0 )
        {
          while ( 1 )
          {
            v16 = value[v11];
            if ( v16 == 9 )
            {
              v12 = "\\t";
              goto LABEL_17;
            }
            if ( v16 == 10 || v16 == 13 )
              break;
            if ( v16 == 34 )
            {
              v12 = "\\\"";
LABEL_17:
              v13 = v5;
              v14 = *(void (__fastcall **)(int, const char *, int))(*(_DWORD *)v5 + 16);
              goto LABEL_18;
            }
            v13 = v5;
            v14 = *(void (__fastcall **)(int, const char *, int))(*(_DWORD *)v5 + 16);
            if ( v16 == 92 )
            {
              v12 = "\\\\";
LABEL_18:
              v15 = 2;
              goto LABEL_19;
            }
            v15 = 1;
            v12 = &v16;
LABEL_19:
            v14(a1: v13, a2: v12, a3: v15);
            value = v9->value;
            if ( value[++v11] == 0 )
              goto LABEL_20;
          }
          v12 = "\\n";
          goto LABEL_17;
        }
LABEL_20:
        (*(void (__fastcall **)(int, const char *))(*(_DWORD *)v5 + 60))(a1: v5, a2: "\"\n");
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->keyVals.num );
  }
  (*(void (__fastcall **)(int, const char *))(*(_DWORD *)v5 + 60))(a1: v5, a2: "\n}\n");
  (**(void (__fastcall ***)(int, int))v5)(a1: v5, a2: 1);
  return 1;
}


// ========================================================================
// ?GetKeyVal@idLangDict@@QBAPBVidLangKeyValue@@H@Z
// EA  : 0x82F2D000
// RVA : 0x00F2D000
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

const idLangKeyValue *__fastcall idLangDict::GetKeyVal(idLangDict *this, int i)
{
  return &this->keyVals.list[i];
}


// ========================================================================
// ?GetKey@idStrId@@QBAPBDXZ
// EA  : 0x82F2D010
// RVA : 0x00F2D010
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

char *__fastcall idStrId::GetKey(idStrId *this)
{
  int index; // r10

  index = this->index;
  if ( this->index < 0 || index >= idLocalization::languageDict.keyVals.num )
    return &byte_8200D768;
  else
    return idLocalization::languageDict.keyVals.list[index].key;
}


// ========================================================================
// ?GetLocalizedString@idStrId@@QBAPBDXZ
// EA  : 0x82F2D050
// RVA : 0x00F2D050
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

char *__fastcall idStrId::GetLocalizedString(idStrId *this)
{
  int index; // r10
  idLangKeyValue *v2; // r11
  char *result; // r3

  index = this->index;
  if ( this->index < 0 || index >= idLocalization::languageDict.keyVals.num )
    return &byte_8200D768;
  v2 = &idLocalization::languageDict.keyVals.list[index];
  result = v2->value;
  if ( result == nullptr )
    return v2->key;
  return result;
}


// ========================================================================
// ?FindStringIndex@idLangDict@@ABAHPBD@Z
// EA  : 0x82F2D0A0
// RVA : 0x00F2D0A0
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

int __fastcall idLangDict::FindStringIndex(idLangDict *this, const char *str)
{
  int v4; // r31

  if ( str == nullptr )
    return -1;
  v4 = this->keyIndex.hash[idStr::IHash(string: str) & this->keyIndex.hashMask & this->keyIndex.lookupMask];
  if ( v4 < 0 )
    return -1;
  while ( idStr::Icmp(s1: str, s2: this->keyVals.list[v4].key) != 0 )
  {
    v4 = this->keyIndex.indexChain[v4 & this->keyIndex.lookupMask];
    if ( v4 < 0 )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?FindString_r@idLangDict@@ABAPBDPBDAAH@Z
// EA  : 0x82F2D140
// RVA : 0x00F2D140
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

const char *__fastcall idLangDict::FindString_r(idLangDict *this, const char *str, int *depth)
{
  int v5; // r11
  int StringIndex; // r3
  idLangKeyValue *v7; // r11
  const char *value; // r31
  int v9; // r11

  v5 = *depth + 1;
  *depth = v5;
  if ( v5 > 2 )
  {
LABEL_8:
    idLib::Warning(fmt: "String '%s', indirection depth > %d", str, 2);
  }
  else
  {
    while ( str != nullptr )
    {
      if ( *str == 0 )
        break;
      StringIndex = idLangDict::FindStringIndex(this, str);
      if ( StringIndex < 0 )
        break;
      v7 = &this->keyVals.list[StringIndex];
      value = v7->value;
      if ( value == nullptr )
        break;
      if ( idStr::Icmpn(s1: v7->value, s2: idLangDict::KEY_PREFIX, n: idLangDict::KEY_PREFIX_LEN) != 0 )
        return value;
      str = value;
      v9 = *depth + 1;
      *depth = v9;
      if ( v9 > 2 )
        goto LABEL_8;
    }
  }
  return nullptr;
}


// ========================================================================
// ?Set@idStrId@@QAAXPBD@Z
// EA  : 0x82F2D208
// RVA : 0x00F2D208
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void __fastcall idStrId::Set(idStrId *this, const char *key)
{
  int StringIndex; // r3

  if ( key != nullptr && *key != 0 )
  {
    StringIndex = idLangDict::FindStringIndex(this: &idLocalization::languageDict, str: key);
    this->index = StringIndex;
    if ( StringIndex < 0 )
      idLib::Warning(fmt: "Attempted to set unknown string ID '%s'", key);
  }
  else
  {
    this->index = -1;
  }
}


// ========================================================================
// ?FindString@idLocalization@@SAPBDPBD@Z
// EA  : 0x82F2D288
// RVA : 0x00F2D288
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

const char *__fastcall idLocalization::FindString(const char *inString)
{
  int v2; // [sp+50h] [-10h] BYREF

  v2 = 0;
  return idLangDict::FindString_r(this: &idLocalization::languageDict, str: inString, depth: &v2);
}


// ========================================================================
// ?GetString@idLocalization@@SAPBDPBD@Z
// EA  : 0x82F2D550
// RVA : 0x00F2D550
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

const char *__fastcall idLocalization::GetString(const char *inString)
{
  const char *result; // r3
  int v3[4]; // [sp+50h] [-20h] BYREF

  v3[0] = 0;
  result = idLangDict::FindString_r(this: &idLocalization::languageDict, str: inString, depth: v3);
  if ( result == nullptr )
    return inString;
  return result;
}


// ========================================================================
// ?Clear@idLangDict@@QAAXXZ
// EA  : 0x82F2DAF8
// RVA : 0x00F2DAF8
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void __fastcall idLangDict::Clear(idLangDict *this)
{
  int v2; // r29
  int v3; // r30
  char *value; // r11
  int usedBlockMemory; // r9

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v2 = 0;
  if ( this->keyVals.num > 0 )
  {
    v3 = 0;
    do
    {
      value = this->keyVals.list[v3].value;
      if ( value != nullptr )
      {
        ++this->blockAlloc.numFrees;
        usedBlockMemory = this->blockAlloc.usedBlockMemory;
        --this->blockAlloc.numUsedBlocks;
        this->blockAlloc.usedBlockMemory = usedBlockMemory - abs32(*((_DWORD *)value - 4));
        idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
          (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
          block: (idDynamicBlock<unsigned char,60> *)value - 1);
        this->keyVals.list[v3].value = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->keyVals.num );
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// ?DeleteString@idLangDict@@QAA_NH@Z
// EA  : 0x82F2DBC0
// RVA : 0x00F2DBC0
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

int __fastcall idLangDict::DeleteString(idLangDict *this, int idx)
{
  int v4; // r29
  char *value; // r11
  int usedBlockMemory; // r9

  if ( idx < 0 || idx >= this->keyVals.num )
    return 0;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v4 = idx;
  value = this->keyVals.list[v4].value;
  ++this->blockAlloc.numFrees;
  if ( value != nullptr )
  {
    usedBlockMemory = this->blockAlloc.usedBlockMemory;
    --this->blockAlloc.numUsedBlocks;
    this->blockAlloc.usedBlockMemory = usedBlockMemory - abs32(*((_DWORD *)value - 4));
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
      block: (idDynamicBlock<unsigned char,60> *)value - 1);
  }
  this->keyVals.list[v4].value = nullptr;
  idMem::PopHeap(this: &mem);
  return 1;
}


// ========================================================================
// ??0idLangDict@@QAA@XZ
// EA  : 0x82F2DDF0
// RVA : 0x00F2DDF0
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

idLangDict *__fastcall idLangDict::idLangDict(idLangDict *this)
{
  this->blockAlloc.freeTree.nodeAllocator.blocks = nullptr;
  this->blockAlloc.freeTree.nodeAllocator.free = nullptr;
  this->blockAlloc.freeTree.nodeAllocator.total = 0;
  this->blockAlloc.freeTree.nodeAllocator.active = 0;
  this->blockAlloc.freeTree.nodeAllocator.allowAllocs = true;
  this->blockAlloc.freeTree.nodeAllocator.clearAllocs = false;
  this->blockAlloc.freeTree.root = nullptr;
  this->blockAlloc.clearAllocs = false;
  this->blockAlloc.lastBlock = nullptr;
  this->blockAlloc.firstBlock = nullptr;
  this->blockAlloc.allowAllocs = true;
  this->blockAlloc.numBaseBlocks = 0;
  this->blockAlloc.baseBlockMemory = 0;
  this->blockAlloc.numUsedBlocks = 0;
  this->blockAlloc.usedBlockMemory = 0;
  this->blockAlloc.numFreeBlocks = 0;
  this->blockAlloc.freeBlockMemory = 0;
  this->blockAlloc.numAllocs = 0;
  this->blockAlloc.numResizes = 0;
  this->blockAlloc.numFrees = 0;
  this->keyVals.list = nullptr;
  this->keyVals.granularity = 0;
  this->keyVals.memTag = 119;
  this->keyVals.listStatic = 0;
  this->keyVals.size = 0;
  this->keyVals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->keyVals);
  this->keyIndex.memTag = TAG_LANGDICT;
  idHashIndex::InternalInit(this: &this->keyIndex, initialHashSize: 4096, initialIndexSize: 4096);
  return this;
}


// ========================================================================
// __unwind$113332
// EA  : 0x82F2DEB0
// RVA : 0x00F2DEB0
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void _unwind_113332()
{
  int v0; // r12

  idDynamicBlockAlloc<unsigned char,1024,16,89>::~idDynamicBlockAlloc<unsigned char,1024,16,89>(this: *(idDynamicBlockAlloc<unsigned char,1048576,16,60> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$113333
// EA  : 0x82F2DED8
// RVA : 0x00F2DED8
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void _unwind_113333()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// ??1idLangDict@@QAA@XZ
// EA  : 0x82F2DF10
// RVA : 0x00F2DF10
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void __fastcall idLangDict::~idLangDict(idLangDict *this)
{
  idLangDict::Clear(this);
  idHashIndex::Free(this: &this->keyIndex);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->keyVals);
  idDynamicBlockAlloc<unsigned char,1024,16,89>::~idDynamicBlockAlloc<unsigned char,1024,16,89>((idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this);
}


// ========================================================================
// __unwind$113386
// EA  : 0x82F2DF64
// RVA : 0x00F2DF64
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void _unwind_113386()
{
  int v0; // r12

  idDynamicBlockAlloc<unsigned char,1024,16,89>::~idDynamicBlockAlloc<unsigned char,1024,16,89>(this: *(idDynamicBlockAlloc<unsigned char,1048576,16,60> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$113387
// EA  : 0x82F2DF8C
// RVA : 0x00F2DF8C
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void _unwind_113387()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$113388
// EA  : 0x82F2DFB8
// RVA : 0x00F2DFB8
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void _unwind_113388()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// ?SetString@idLangDict@@QAA_NPBD0@Z
// EA  : 0x82F2DFE8
// RVA : 0x00F2DFE8
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

int __fastcall idLangDict::SetString(idLangDict *this, const char *key, const char *val)
{
  int StringIndex; // r30
  int v7; // r29
  char *value; // r11
  int usedBlockMemory; // r9
  int v10; // r11
  int v11; // r30
  idLangKeyValue *v12; // r28

  StringIndex = idLangDict::FindStringIndex(this, str: key);
  if ( StringIndex < 0 )
    return 0;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v7 = StringIndex;
  value = this->keyVals.list[StringIndex].value;
  if ( value != nullptr )
  {
    ++this->blockAlloc.numFrees;
    usedBlockMemory = this->blockAlloc.usedBlockMemory;
    --this->blockAlloc.numUsedBlocks;
    this->blockAlloc.usedBlockMemory = usedBlockMemory - abs32(*((_DWORD *)value - 4));
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
      block: (idDynamicBlock<unsigned char,60> *)value - 1);
  }
  v10 = 0;
  if ( *val != 0 )
  {
    do
      ++v10;
    while ( val[v10] != 0 );
  }
  v11 = v10 + 1;
  v12 = &this->keyVals.list[v7];
  v12->value = (char *)idDynamicBlockAlloc<char,102400,16,119>::Alloc(this: &this->blockAlloc, num: v10 + 1);
  idStr::Copynz(dest: this->keyVals.list[v7].value, src: val, destsize: v11);
  idMem::PopHeap(this: &mem);
  return 1;
}


// ========================================================================
// ?AddKeyVal@idLangDict@@QAAXPBD0@Z
// EA  : 0x82F2E0F8
// RVA : 0x00F2E0F8
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void __fastcall idLangDict::AddKeyVal(idLangDict *this, const char *key, const char *val)
{
  int v6; // r11
  int v7; // r31
  char *v8; // r26
  char *v9; // r31
  int v10; // r11
  int v11; // r28
  int v12; // r31
  int v13; // r3
  loadedMapEntity_t v14; // [sp+50h] [-50h] BYREF

  if ( (unsigned __int8)idLangDict::SetString(this, key, val) == 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v6 = 0;
    if ( *key != 0 )
    {
      do
        ++v6;
      while ( key[v6] != 0 );
    }
    v7 = v6 + 1;
    v8 = (char *)idDynamicBlockAlloc<char,102400,16,119>::Alloc(this: &this->blockAlloc, num: v6 + 1);
    idStr::Copynz(dest: v8, src: key, destsize: v7);
    v9 = nullptr;
    if ( val != nullptr )
    {
      v10 = 0;
      if ( *val != 0 )
      {
        do
          ++v10;
        while ( val[v10] != 0 );
      }
      v11 = v10 + 1;
      v9 = (char *)idDynamicBlockAlloc<char,102400,16,119>::Alloc(this: &this->blockAlloc, num: v10 + 1);
      idStr::Copynz(dest: v9, src: val, destsize: v11);
    }
    v14.ent = (idEntity *)v8;
    v14.mapEnt = (idMapEntity *)v9;
    v12 = idList<idLangKeyValue,119>::Append(this: (idList<loadedMapEntity_t,5> *)&this->keyVals, obj: &v14);
    v13 = idStr::IHash(string: key);
    idHashIndex::Add(this: &this->keyIndex, key: v13, index: v12);
    idMem::PopHeap(this: &mem);
  }
}


// ========================================================================
// ?Load@idLangDict@@QAA_NPBEHPBD@Z
// EA  : 0x82F2E208
// RVA : 0x00F2E208
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

int __fastcall idLangDict::Load(idLangDict *this, const char *buffer, int bufferLen, const char *name)
{
  bool v8; // r11
  BOOL v9; // r17
  int v10; // r11
  int v11; // r25
  int v12; // r18
  int v13; // r10
  int v14; // r10
  int v16; // r5
  int v17; // r6
  int v18; // r10
  int v19; // r11
  int v20; // r10
  int v21; // r27
  int v22; // r29
  unsigned int v23; // r3
  unsigned int v24; // r30
  int v25[4]; // [sp+50h] [-E0h] BYREF
  idStr v26; // [sp+60h] [-D0h] BYREF
  idStr v27[5]; // [sp+80h] [-B0h] BYREF

  idLangDict::Clear(this);
  if ( buffer != nullptr && bufferLen > 0 )
  {
    idLib::Printf(fmt: "Reading %s", name);
    v8 = false;
    if ( bufferLen > 3 && *(unsigned __int8 *)buffer == 239 && *((unsigned __int8 *)buffer + 1) == 187 )
      v8 = *((unsigned __int8 *)buffer + 2) == 191;
    v9 = v8;
    if ( v8 )
      idLib::Printf(fmt: " as UTF-8\n");
    else
      idLib::Printf(fmt: " as ASCII\n");
    v27[0].len = 0;
    v27[0].baseBuffer[0] = 0;
    v27[0].allocedAndFlag = 20;
    v27[0].data = v27[0].baseBuffer;
    v26.allocedAndFlag = 20;
    v26.data = v26.baseBuffer;
    v26.len = 0;
    v26.baseBuffer[0] = 0;
    v10 = 0;
    v11 = 1;
    v25[0] = 0;
    v12 = 0;
    while ( 1 )
    {
      v13 = (unsigned __int8)buffer[v10];
      v25[0] = ++v10;
      if ( v13 == 47 )
        break;
      switch ( v13 )
      {
        case 125:
          goto LABEL_15;
        case 10:
          goto LABEL_18;
        case 34:
          v16 = v10;
          v17 = -1;
          if ( v10 < bufferLen )
          {
            while ( 1 )
            {
              v18 = (unsigned __int8)buffer[v10];
              v25[0] = ++v10;
              if ( v18 == 34 )
                break;
              if ( v10 >= bufferLen )
                goto LABEL_25;
            }
            v17 = v10 - 1;
          }
LABEL_25:
          if ( v17 < v16 )
          {
            idLib::FatalError(fmt: "%s File ended while reading key at line %d", name, v11);
_LN134_1:
            idLib::FatalError(fmt: "Language file %s is supposed to be plain ASCII, but has byte values > 127!", name);
_LN135_0:
            idLib::FatalError(fmt: "%s File ended while reading value at line %d", name, v11);
            return 0;
          }
          idStr::CopyRange(this: v27, text: buffer, start: v16, end: v17);
          v19 = v25[0];
          if ( v25[0] < bufferLen )
          {
            while ( 1 )
            {
              v20 = (unsigned __int8)buffer[v19];
              v25[0] = ++v19;
              if ( v20 == 34 )
                goto _LN133_0;
              if ( v19 >= bufferLen )
                goto LABEL_29;
            }
          }
          do
          {
LABEL_29:
            idLib::FatalError(fmt: "%s File ended while reading value at line %d", name, v11);
_LN133_0:
            v21 = v19;
          }
          while ( v19 < 0 );
          v22 = -1;
          if ( v26.len > 0 )
          {
            *v26.data = 0;
            v19 = v25[0];
            v26.len = 0;
          }
          while ( v19 < bufferLen )
          {
            if ( v9 )
            {
              v23 = idStr::UTF8Char(s: (const unsigned __int8 *)buffer, idx: v25);
              v19 = v25[0];
              v24 = v23;
            }
            else
            {
              v24 = (unsigned __int8)buffer[v19];
              v25[0] = ++v19;
              if ( v24 >= 0x80 )
                goto _LN134_1;
            }
            if ( v24 == 34 )
            {
              v22 = v19 - 1;
            }
            else
            {
              if ( v24 == 10 )
              {
                ++v11;
                break;
              }
              if ( v24 != 13 )
              {
                if ( v24 == 92 )
                {
                  if ( v9 )
                  {
                    v24 = idStr::UTF8Char(s: (const unsigned __int8 *)buffer, idx: v25);
                  }
                  else
                  {
                    v24 = (unsigned __int8)buffer[v19];
                    v25[0] = v19 + 1;
                  }
                  switch ( v24 )
                  {
                    case 'n':
                      v24 = 10;
                      break;
                    case 't':
                      v24 = 9;
                      break;
                    case '"':
                    case '\\':
LABEL_76:
                      break;
                    default:
                      idLib::Warning(fmt: "Unknown escape sequence %x at line %d", v24, v11);
                      goto LABEL_76;
                  }
                }
                if ( v22 < 0 )
                  idStr::AppendUTF8Char(this: &v26, c: v24);
                else
                  idLib::Warning(
                    fmt: "%s File has additional character, %c, after the ending quotes on line %d",
                    name,
                    v24,
                    v11);
                v19 = v25[0];
              }
            }
          }
          if ( v22 < v21 )
            goto _LN135_0;
          if ( lang_maskLocalizedStrings.valueInteger != 0
            && v26.len > 0
            && idStr::Find(searchIn: v27[0].data, searchFor: "#font_", casesensitive: true, start: 0, end: v27[0].len) == -1 )
          {
            if ( v26.len <= 0 )
              idStr::Empty(this: &v26);
            else
              idStr::Fill(this: &v26, ch: 87, newlen: v26.len - 1);
            idStr::Append(this: &v26, a: 88);
          }
          idLangDict::AddKeyVal(this, key: v27[0].data, val: v26.data);
          v10 = v25[0];
          ++v12;
          break;
        default:
          break;
      }
LABEL_68:
      if ( v10 >= bufferLen )
      {
LABEL_15:
        idLib::Printf(fmt: "%i strings read\n", v12);
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        idList<idStateTransition::transDest_t,111>::Resize(
          this: (idList<swfGlyphEntry_t,72> *)&this->keyVals,
          newsize: this->keyVals.num);
        idMem::PopHeap(this: &mem);
        idStr::FreeData(this: &v26);
        idStr::FreeData(this: v27);
        return 1;
      }
    }
    if ( v10 >= bufferLen )
      goto LABEL_15;
    while ( 1 )
    {
      v14 = (unsigned __int8)buffer[v10];
      v25[0] = ++v10;
      if ( v14 == 10 )
        break;
      if ( v10 >= bufferLen )
        goto LABEL_15;
    }
LABEL_18:
    ++v11;
    goto LABEL_68;
  }
  return 0;
}


// ========================================================================
// $LN118_3
// EA  : 0x82F2E648
// RVA : 0x00F2E648
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void _LN118_3()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$113620
// EA  : 0x82F2E670
// RVA : 0x00F2E670
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void _unwind_113620()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 96));
}


// ========================================================================
// ?LoadDictionary@idLocalization@@SA_NPBEHPBD@Z
// EA  : 0x82F2E698
// RVA : 0x00F2E698
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

int __fastcall idLocalization::LoadDictionary(const char *data, int dataLen, const char *fileName)
{
  idLangDict::Clear(this: &idLocalization::languageDict);
  return idLangDict::Load(this: &idLocalization::languageDict, buffer: data, bufferLen: dataLen, name: fileName);
}


// ========================================================================
// `dynamic initializer for 'idLocalization::languageDict''
// EA  : 0x83395588
// RVA : 0x01395588
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idLocalization::languageDict__()
{
  idLangDict::idLangDict(this: &idLocalization::languageDict);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idLocalization::languageDict__);
}


// ========================================================================
// `dynamic initializer for 'lang_maskLocalizedStrings''
// EA  : 0x833955C0
// RVA : 0x013955C0
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lang_maskLocalizedStrings__()
{
  idCVar::idCVar(
    this: &lang_maskLocalizedStrings,
    name: "lang_maskLocalizedStrings",
    value: "0",
    flags: 1,
    description: "Masks all localized strings to help debugging.  When set will replace strings with an equal length of W's and ending"
    " in an X.  Note: The masking occurs at string table load time.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lang_maskLocalizedStrings__);
}


// ========================================================================
// `dynamic initializer for 'idLangDict::KEY_PREFIX_LEN''
// EA  : 0x83395618
// RVA : 0x01395618
// PDB : w:\tech5\shared\idlib\langdict.cpp
// ========================================================================

void _dynamic_initializer_for__idLangDict::KEY_PREFIX_LEN__()
{
  int v0; // r11

  v0 = 0;
  if ( *idLangDict::KEY_PREFIX != 0 )
  {
    do
      ++v0;
    while ( idLangDict::KEY_PREFIX[v0] != 0 );
  }
  idLangDict::KEY_PREFIX_LEN = v0;
}

