
// ========================================================================
// ?FreeDynamic@idAtomicStringManager@@QAAXXZ
// EA  : 0x82F869F8
// RVA : 0x00F869F8
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

void __fastcall idAtomicStringManager::FreeDynamic(idAtomicStringManager *this)
{
  atomicStringBlock_t **p_blocks; // r31
  atomicStringBlock_t *v3; // r4
  atomicStringBlock_t *nextBlock; // r27

  p_blocks = &this->blocks;
  memcpy(Dst: this, Src: this->hashTableAtMarkStatic, Size: 0x40000u);
  if ( this->blocks != nullptr )
  {
    do
    {
      v3 = *p_blocks;
      if ( *p_blocks == this->blocksAtMarkStatic )
        break;
      nextBlock = v3->nextBlock;
      idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
      *p_blocks = nextBlock;
    }
    while ( nextBlock != nullptr );
  }
  if ( *p_blocks != nullptr )
    (*p_blocks)->usedBytes = this->usedBytesAtMarkStatic;
}


// ========================================================================
// ?ReportAtomicStrings_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F86A88
// RVA : 0x00F86A88
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ReportAtomicStrings_f(const idCmdArgs *args)
{
  __int64 v1; // r4
  __int64 v2; // r8 OVERLAPPED
  _DWORD *i; // r11
  unsigned __int8 *v4; // r10
  unsigned __int8 *v5; // r9
  int v6; // r6
  int v7; // r6
  unsigned int v8; // r10
  atomicStringBlock_t *j; // r11
  int bufferBytes; // r9
  __int128 v11; // r11
  double v12; // fp0
  __int64 v13; // r6
  int v14; // [sp+8h] [-58h]
  int v15; // [sp+Ch] [-54h]
  int v16; // [sp+10h] [-50h]
  int v17; // [sp+14h] [-4Ch]

  LODWORD(v1) = 0;
  LODWORD(v2) = 0;
  HIDWORD(v2) = &atomicStringManager;
  do
  {
    for ( i = *(_DWORD **)HIDWORD(v2); i != nullptr; LODWORD(v2) = v4 - v5 - 1 + v2 )
    {
      v4 = (unsigned __int8 *)(i + 1);
      LODWORD(v1) = v1 + 1;
      v5 = (unsigned __int8 *)(i + 1);
      do
        v6 = *v4++;
      while ( v6 != 0 );
      i = (_DWORD *)*i;
    }
    HIDWORD(v2) += 4;
  }
  while ( SHIDWORD(v2) < (int)atomicStringManager.hashTableAtMarkStatic );
  v7 = 0;
  v8 = 0;
  for ( j = atomicStringManager.blocks; j != nullptr; v8 += bufferBytes + 12 )
  {
    bufferBytes = j->bufferBytes;
    ++v7;
    j = j->nextBlock;
  }
  *((_QWORD *)&v11 + 1) = __PAIR64__(&unk_821C0000, v8);
  v12 = *(float *)(DWORD2(v11) + 14668);
  HIDWORD(v1) = "%i strings of %i average character length in %i block for %4.1f megs\n";
  HIDWORD(v13) = (int)v2 / (int)v1;
  DWORD1(v11) = __ROL4__(v2, 1) - 1;
  __twllei(v1, 0);
  __twlgei(v1 & ~DWORD1(v11), 0xFFFFFFFF);
  *(double *)((char *)&v2 + 4) = (float)((float)(__int64)v11 * (float)v12);
  idLib::Printf(fmt: v1, a2: v13, a3: v2, a4: *(__int64 *)((char *)&v11 + 4), a5: v14, a6: v15, a7: v16, a8: v17);
}


// ========================================================================
// ?MarkStatic@idAtomicString@@SAXXZ
// EA  : 0x82F86B90
// RVA : 0x00F86B90
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

static void __fastcall idAtomicString::MarkStatic()
{
  memcpy(
    Dst: atomicStringManager.hashTableAtMarkStatic,
    Src: &atomicStringManager,
    Size: sizeof(atomicStringManager.hashTableAtMarkStatic));
  atomicStringManager.blocksAtMarkStatic = atomicStringManager.blocks;
  if ( atomicStringManager.blocks != nullptr )
    atomicStringManager.usedBytesAtMarkStatic = atomicStringManager.blocks->usedBytes;
}


// ========================================================================
// ?FreeDynamic@idAtomicString@@SAXXZ
// EA  : 0x82F86BF8
// RVA : 0x00F86BF8
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

static void __fastcall idAtomicString::FreeDynamic()
{
  idAtomicStringManager::FreeDynamic(this: &atomicStringManager);
}


// ========================================================================
// ?MakeAtomic@idAtomicStringManager@@QAAPBDQBD@Z
// EA  : 0x82F86C08
// RVA : 0x00F86C08
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

char *__fastcall idAtomicStringManager::MakeAtomic(idAtomicStringManager *this, const char *str)
{
  char *result; // r3
  unsigned __int8 v5; // r8
  int v6; // r11
  const char *v7; // r9
  int v8; // r26
  int *v9; // r8
  const char *v10; // r10
  unsigned __int8 *v11; // r11
  int v12; // r9
  int v13; // r9
  bool v14; // zf
  const char *v15; // r11
  int v16; // r10
  atomicStringBlock_t **p_blocks; // r31
  int v18; // r29
  atomicStringBlock_t *blocks; // r11
  int v20; // r10
  signed int v21; // r30
  unsigned int v22; // r28
  atomicStringBlock_t *v23; // r3
  atomicStringBlock_t *v24; // r11
  int usedBytes; // r10
  char *v26; // r31

  if ( str == nullptr )
    return &byte_8200D768;
  v5 = *str;
  v6 = 0;
  if ( *str != 0 )
  {
    v7 = str;
    do
    {
      ++v7;
      v6 = 31 * v6 + v5;
      v5 = *v7;
    }
    while ( *v7 != 0 );
  }
  v8 = (4 * v6) & 0x3FFFC;
  v9 = *(int **)((char *)this->hashTable + v8);
  if ( v9 != nullptr )
  {
    while ( 1 )
    {
      result = (char *)(v9 + 1);
      v10 = str;
      v11 = (unsigned __int8 *)(v9 + 1);
      do
      {
        v12 = *v11;
        v14 = v12 == 0;
        v13 = v12 - *(unsigned __int8 *)v10;
        if ( v14 )
          break;
        ++v11;
        ++v10;
      }
      while ( v13 == 0 );
      if ( v13 == 0 )
        break;
      v9 = (int *)*v9;
      if ( v9 == nullptr )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v15 = str;
    do
      v16 = *(unsigned __int8 *)v15++;
    while ( v16 != 0 );
    p_blocks = &this->blocks;
    v18 = v15 - str;
    v20 = v15 - str + 7;
    blocks = this->blocks;
    v21 = v20 & 0xFFFFFFFC;
    if ( blocks == nullptr || v21 > blocks->bufferBytes - blocks->usedBytes )
    {
      v22 = v21 + 12;
      if ( v21 + 12 < 0x10000 )
        v22 = 0x10000;
      v23 = (atomicStringBlock_t *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\text\\AtomicString.cpp(151) : TAG_ATOMIC_STRING",
                                     size: v22,
                                     tag: TAG_ATOMIC_STRING,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      v23->bufferBytes = v22 - 12;
      v23->usedBytes = 0;
      v23->nextBlock = *p_blocks;
      *p_blocks = v23;
    }
    v24 = *p_blocks;
    usedBytes = (*p_blocks)->usedBytes;
    v26 = (char *)*p_blocks + usedBytes;
    v24->usedBytes = usedBytes + v21;
    idStr::Copynz(dest: v26 + 16, src: str, destsize: v18);
    *((_DWORD *)v26 + 3) = *(void ***)((char *)this->hashTable + v8);
    *(void ***)((char *)this->hashTable + v8) = (void **)(v26 + 12);
    return v26 + 16;
  }
  return result;
}


// ========================================================================
// ?Set@idAtomicString@@QAAXQBD@Z
// EA  : 0x82F86DB0
// RVA : 0x00F86DB0
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

void __fastcall idAtomicString::Set(idAtomicString *this, const char *str_)
{
  this->str = idAtomicStringManager::MakeAtomic(this: &atomicStringManager, str: str_);
}


// ========================================================================
// ?TestAtomicString_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F86DE8
// RVA : 0x00F86DE8
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

void __fastcall TestAtomicString_f(const idCmdArgs *args, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // [sp+8h] [-68h]
  int v6; // [sp+Ch] [-64h]
  int v7; // [sp+10h] [-60h]
  int v8; // [sp+14h] [-5Ch]

  LODWORD(a5) = &unk_82390000;
  idLib::Printf(
    fmt: __SPAIR64__("atsTestStatic: %s\n", (unsigned int)atsTestStatic.str),
    a2: a3,
    a3: a4,
    a4: a5,
    a5: v5,
    a6: v6,
    a7: v7,
    a8: v8);
  idAtomicStringManager::MakeAtomic(this: &atomicStringManager, str: "aStaticAtomicString");
  idAtomicStringManager::MakeAtomic(this: &atomicStringManager, str: "test");
  idAtomicStringManager::MakeAtomic(this: &atomicStringManager, str: "test");
  idAtomicStringManager::MakeAtomic(this: &atomicStringManager, str: "Test");
  memcpy(
    Dst: atomicStringManager.hashTableAtMarkStatic,
    Src: &atomicStringManager,
    Size: sizeof(atomicStringManager.hashTableAtMarkStatic));
  atomicStringManager.blocksAtMarkStatic = atomicStringManager.blocks;
  if ( atomicStringManager.blocks != nullptr )
    atomicStringManager.usedBytesAtMarkStatic = atomicStringManager.blocks->usedBytes;
  idAtomicStringManager::MakeAtomic(this: &atomicStringManager, str: "Test");
  idAtomicStringManager::FreeDynamic(this: &atomicStringManager);
}


// ========================================================================
// `dynamic initializer for 'atsTestStatic''
// EA  : 0x83397328
// RVA : 0x01397328
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

char *_dynamic_initializer_for__atsTestStatic__()
{
  char *result; // r3

  result = idAtomicStringManager::MakeAtomic(this: &atomicStringManager, str: "aStaticAtomicString");
  atsTestStatic.str = result;
  return result;
}


// ========================================================================
// `dynamic initializer for 'TestAtomicString_v''
// EA  : 0x83397360
// RVA : 0x01397360
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestAtomicString_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestAtomicString_v,
           cmdName: "TestAtomicString",
           function: (void (__fastcall *)(const idCmdArgs *))TestAtomicString_f,
           description: "Exercises idAtomicString",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ReportAtomicStrings_v''
// EA  : 0x83397388
// RVA : 0x01397388
// PDB : w:\tech5\shared\idlib\text\atomicstring.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ReportAtomicStrings_v__()
{
  return idCommandLink::idCommandLink(
           this: &ReportAtomicStrings_v,
           cmdName: "ReportAtomicStrings",
           function: ReportAtomicStrings_f,
           description: "Stats for idAtomicString",
           argCompletion: nullptr);
}

