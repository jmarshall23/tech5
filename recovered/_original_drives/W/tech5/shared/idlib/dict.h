
// ========================================================================
// ??1idDict@@QAA@XZ
// EA  : 0x829BBD18
// RVA : 0x009BBD18
// PDB : w:\tech5\shared\idlib\dict.h
// ========================================================================

void __fastcall idDict::~idDict(idDict *this)
{
  idDict::Clear(this);
  idHashIndex::Free(this: &this->argHash);
  if ( this->args.listStatic == 0 || this->args.listStatic == 2 )
  {
    if ( this->args.list != nullptr )
      idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &this->args.list->key, num: this->args.size);
    this->args.list = nullptr;
    this->args.size = 0;
  }
  this->args.num = 0;
}


// ========================================================================
// __unwind$222110
// EA  : 0x829BBD9C
// RVA : 0x009BBD9C
// PDB : w:\tech5\shared\idlib\dict.h
// ========================================================================

void _unwind_222110()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: *(idList<idLoadScreenInfo,5> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$222111
// EA  : 0x829BBDC4
// RVA : 0x009BBDC4
// PDB : w:\tech5\shared\idlib\dict.h
// ========================================================================

void _unwind_222111()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ??0idDict@@QAA@XZ
// EA  : 0x829BD7B8
// RVA : 0x009BD7B8
// PDB : w:\tech5\shared\idlib\dict.h
// ========================================================================

idDict *__fastcall idDict::idDict(idDict *this)
{
  idHashIndex *p_argHash; // r29

  this->args.granularity = 0;
  this->args.memTag = 5;
  this->args.listStatic = 0;
  this->args.list = nullptr;
  this->args.size = 0;
  this->args.num = 0;
  p_argHash = &this->argHash;
  this->argHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->argHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->args.granularity = 16;
  this->argHash.granularity = 16;
  idHashIndex::Free(this: p_argHash);
  this->argHash.indexSize = 16;
  this->argHash.hashSize = 128;
  this->argHash.hashMask = 127;
  return this;
}


// ========================================================================
// __unwind$230808_0
// EA  : 0x829BD848
// RVA : 0x009BD848
// PDB : w:\tech5\shared\idlib\dict.h
// ========================================================================

void _unwind_230808_0()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: *(idList<idLoadScreenInfo,5> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$230809
// EA  : 0x829BD870
// RVA : 0x009BD870
// PDB : w:\tech5\shared\idlib\dict.h
// ========================================================================

void _unwind_230809()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ??0idDict@@QAA@ABV0@@Z
// EA  : 0x829CCFF8
// RVA : 0x009CCFF8
// PDB : w:\tech5\shared\idlib\dict.h
// ========================================================================

idDict *__fastcall idDict::idDict(idDict *this, const idDict *other)
{
  this->args.granularity = 0;
  this->args.memTag = 5;
  this->args.listStatic = 0;
  this->args.list = nullptr;
  this->args.size = 0;
  this->args.num = 0;
  this->argHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->argHash, initialHashSize: 1024, initialIndexSize: 1024);
  idDict::operator=(this, other);
  return this;
}


// ========================================================================
// __unwind$240701
// EA  : 0x829CD064
// RVA : 0x009CD064
// PDB : w:\tech5\shared\idlib\dict.h
// ========================================================================

void _unwind_240701()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: *(idList<idLoadScreenInfo,5> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$240702
// EA  : 0x829CD08C
// RVA : 0x009CD08C
// PDB : w:\tech5\shared\idlib\dict.h
// ========================================================================

void _unwind_240702()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}

