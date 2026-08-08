
// ========================================================================
// ?InternalInit@idHashIndex@@QAAXHH@Z
// EA  : 0x82EFB310
// RVA : 0x00EFB310
// PDB : w:\tech5\shared\idlib\containers\hashindex.cpp
// ========================================================================

void __fastcall idHashIndex::InternalInit(idHashIndex *this, int initialHashSize, int initialIndexSize)
{
  this->hashSize = initialHashSize;
  this->indexSize = initialIndexSize;
  this->granularity = 1024;
  this->hash = idHashIndex::INVALID_INDEX;
  this->indexChain = idHashIndex::INVALID_INDEX;
  this->hashMask = initialHashSize - 1;
  this->lookupMask = 0;
}


// ========================================================================
// ?Free@idHashIndex@@QAAXXZ
// EA  : 0x82EFB348
// RVA : 0x00EFB348
// PDB : w:\tech5\shared\idlib\containers\hashindex.cpp
// ========================================================================

void __fastcall idHashIndex::Free(idHashIndex *this)
{
  int *indexChain; // r4

  if ( this->hash != idHashIndex::INVALID_INDEX )
  {
    idMem::Free(this: &mem, ptr: this->hash, align: ALIGN_16);
    this->hash = idHashIndex::INVALID_INDEX;
  }
  indexChain = this->indexChain;
  if ( indexChain != idHashIndex::INVALID_INDEX )
  {
    idMem::Free(this: &mem, ptr: indexChain, align: ALIGN_16);
    this->indexChain = idHashIndex::INVALID_INDEX;
  }
  this->lookupMask = 0;
}


// ========================================================================
// ?ResizeIndex@idHashIndex@@QAAXH@Z
// EA  : 0x82EFB3B0
// RVA : 0x00EFB3B0
// PDB : w:\tech5\shared\idlib\containers\hashindex.cpp
// ========================================================================

void __fastcall idHashIndex::ResizeIndex(idHashIndex *this, int newIndexSize)
{
  signed int granularity; // r11
  int v4; // r30
  int *indexChain; // r29
  int *v6; // r3

  if ( newIndexSize > this->indexSize )
  {
    granularity = this->granularity;
    __twllei(granularity, 0);
    __twlgei(granularity & ~(__ROL4__(newIndexSize, 1) - 1), 0xFFFFFFFF);
    if ( newIndexSize % granularity != 0 )
      v4 = granularity - newIndexSize % granularity + newIndexSize;
    else
      v4 = newIndexSize;
    indexChain = this->indexChain;
    if ( indexChain != idHashIndex::INVALID_INDEX )
    {
      v6 = (int *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\containers\\HashIndex.cpp(96) : memTag",
                    size: 4 * v4,
                    tag: this->memTag,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
      this->indexChain = v6;
      memcpy(Dst: v6, Src: indexChain, Size: 4 * this->indexSize);
      memset(Dst: &this->indexChain[this->indexSize], Val: 255, Size: 4 * (v4 - this->indexSize));
      idMem::Free(this: &mem, ptr: indexChain, align: ALIGN_16);
    }
    this->indexSize = v4;
  }
}


// ========================================================================
// ?GetSpread@idHashIndex@@QBAHXZ
// EA  : 0x82EFB498
// RVA : 0x00EFB498
// PDB : w:\tech5\shared\idlib\containers\hashindex.cpp
// ========================================================================

int __fastcall idHashIndex::GetSpread(idHashIndex *this)
{
  signed int v2; // r30
  _DWORD *v3; // r3
  signed int v4; // r7
  int v5; // r8
  _DWORD *v6; // r11
  int v7; // r10
  int v8; // r10
  int v9; // r6
  signed int hashSize; // r10
  int v12; // r31
  _DWORD *v13; // r9
  signed int i; // ctr
  int v15; // r11

  if ( this->hash == idHashIndex::INVALID_INDEX )
    return 100;
  v2 = 0;
  v3 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\containers\\HashIndex.cpp(116) : memTag",
         size: 4 * this->hashSize,
         tag: this->memTag,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v4 = 0;
  if ( this->hashSize > 0 )
  {
    v5 = 0;
    v6 = v3 - 1;
    do
    {
      v6[1] = 0;
      v7 = this->hash[v5];
      if ( v7 >= 0 )
      {
        v8 = v7;
        do
        {
          ++v6[1];
          v9 = this->indexChain[v8];
          v8 = v9;
        }
        while ( v9 >= 0 );
      }
      ++v6;
      ++v4;
      hashSize = this->hashSize;
      ++v5;
      v2 += *v6;
    }
    while ( v4 < hashSize );
    if ( v2 > 1 )
    {
      __twllei(hashSize, 0);
      v12 = 0;
      __twlgei(hashSize & ~(__ROL4__(v2, 1) - 1), 0xFFFFFFFF);
      if ( hashSize > 0 )
      {
        v13 = v3;
        for ( i = hashSize; i != 0; --i )
        {
          v15 = abs32(*v13 - v2 / hashSize);
          if ( v15 > 1 )
            v12 = v15 + v12 - 1;
          ++v13;
        }
      }
      idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
      __twllei(v2, 0);
      __twlgei(v2 & ~(__ROL4__(100 * v12, 1) - 1), 0xFFFFFFFF);
      return 100 - 100 * v12 / v2;
    }
  }
  idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  return 100;
}


// ========================================================================
// ?Allocate@idHashIndex@@QAAXHH@Z
// EA  : 0x82EFB610
// RVA : 0x00EFB610
// PDB : w:\tech5\shared\idlib\containers\hashindex.cpp
// ========================================================================

void __fastcall idHashIndex::Allocate(idHashIndex *this, int newHashSize, int newIndexSize)
{
  int *indexChain; // r4
  memTag_t memTag; // r6
  int *v8; // r3
  int hashSize; // r9
  int *v10; // r3
  int indexSize; // r7
  int v12; // r5

  if ( this->hash != idHashIndex::INVALID_INDEX )
  {
    idMem::Free(this: &mem, ptr: this->hash, align: ALIGN_16);
    this->hash = idHashIndex::INVALID_INDEX;
  }
  indexChain = this->indexChain;
  if ( indexChain != idHashIndex::INVALID_INDEX )
  {
    idMem::Free(this: &mem, ptr: indexChain, align: ALIGN_16);
    this->indexChain = idHashIndex::INVALID_INDEX;
  }
  this->hashSize = newHashSize;
  memTag = this->memTag;
  this->lookupMask = 0;
  v8 = (int *)idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\containers\\HashIndex.cpp(45) : memTag",
                size: 4 * newHashSize,
                tag: memTag,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
  hashSize = this->hashSize;
  this->hash = v8;
  memset(Dst: v8, Val: 255, Size: 4 * hashSize);
  this->indexSize = newIndexSize;
  v10 = (int *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\containers\\HashIndex.cpp(48) : memTag",
                 size: 4 * newIndexSize,
                 tag: this->memTag,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  indexSize = this->indexSize;
  this->indexChain = v10;
  memset(Dst: v10, Val: 255, Size: 4 * indexSize);
  v12 = this->hashSize - 1;
  this->lookupMask = -1;
  this->hashMask = v12;
}

