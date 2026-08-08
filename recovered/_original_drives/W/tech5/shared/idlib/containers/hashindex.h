
// ========================================================================
// ?Add@idHashIndex@@QAAXHH@Z
// EA  : 0x825C38A0
// RVA : 0x005C38A0
// PDB : w:\tech5\shared\idlib\containers\hashindex.h
// ========================================================================

void __fastcall idHashIndex::Add(idHashIndex *this, const int key, int index)
{
  int indexSize; // r11
  int v7; // r6

  indexSize = this->indexSize;
  if ( this->hash == idHashIndex::INVALID_INDEX )
  {
    if ( index >= indexSize )
      indexSize = index + 1;
    idHashIndex::Allocate(this, newHashSize: this->hashSize, newIndexSize: indexSize);
  }
  else if ( index >= indexSize )
  {
    idHashIndex::ResizeIndex(this, newIndexSize: index + 1);
  }
  v7 = this->hashMask & key;
  this->indexChain[index] = this->hash[v7];
  this->hash[v7] = index;
}


// ========================================================================
// ?Clear@idHashIndex@@QAAXXZ
// EA  : 0x825C3938
// RVA : 0x005C3938
// PDB : w:\tech5\shared\idlib\containers\hashindex.h
// ========================================================================

void __fastcall idHashIndex::Clear(idHashIndex *this)
{
  int *hash; // r3
  int *indexChain; // r3

  hash = this->hash;
  if ( hash != idHashIndex::INVALID_INDEX )
    memset(Dst: hash, Val: 255, Size: 4 * this->hashSize);
  indexChain = this->indexChain;
  if ( indexChain != idHashIndex::INVALID_INDEX )
    memset(Dst: indexChain, Val: 255, Size: 4 * this->indexSize);
}


// ========================================================================
// ?Remove@idHashIndex@@QAAXHH@Z
// EA  : 0x82624420
// RVA : 0x00624420
// PDB : w:\tech5\shared\idlib\containers\hashindex.h
// ========================================================================

void __fastcall idHashIndex::Remove(idHashIndex *this, const int key, const int index)
{
  int *hash; // r11
  int v4; // r10
  int v5; // r9
  int v6; // r10
  int v7; // r11
  int v8; // r10

  hash = this->hash;
  v4 = this->hashMask & key;
  if ( this->hash != idHashIndex::INVALID_INDEX )
  {
    v5 = v4;
    v6 = hash[v4];
    if ( v6 == index )
    {
      hash[v5] = this->indexChain[index];
      this->indexChain[index] = -1;
    }
    else
    {
      v7 = v6;
      if ( v6 != -1 )
      {
        while ( 1 )
        {
          v8 = v7;
          v7 = this->indexChain[v7];
          if ( v7 == index )
            break;
          if ( v7 == -1 )
          {
            this->indexChain[index] = -1;
            return;
          }
        }
        this->indexChain[v8] = this->indexChain[index];
      }
      this->indexChain[index] = -1;
    }
  }
}


// ========================================================================
// ?RemoveIndex@idHashIndex@@QAAXHH@Z
// EA  : 0x826244D0
// RVA : 0x006244D0
// PDB : w:\tech5\shared\idlib\containers\hashindex.h
// ========================================================================

void __fastcall idHashIndex::RemoveIndex(idHashIndex *this, int key, int index)
{
  int v5; // r7
  int v6; // r8
  int v7; // r11
  int v8; // r10
  int v9; // r8
  int v10; // r11
  int v11; // r10
  int v12; // r11
  int v13; // ctr
  int *v14; // r10

  idHashIndex::Remove(this, key, index);
  if ( this->hash != idHashIndex::INVALID_INDEX )
  {
    v5 = index;
    v6 = 0;
    if ( this->hashSize > 0 )
    {
      v7 = 0;
      do
      {
        v8 = this->hash[v7];
        if ( v8 >= index )
        {
          if ( v8 > v5 )
            v5 = this->hash[v7];
          --this->hash[v7];
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->hashSize );
    }
    v9 = 0;
    if ( this->indexSize > 0 )
    {
      v10 = 0;
      do
      {
        v11 = this->indexChain[v10];
        if ( v11 >= index )
        {
          if ( v11 > v5 )
            v5 = this->indexChain[v10];
          --this->indexChain[v10];
        }
        ++v9;
        ++v10;
      }
      while ( v9 < this->indexSize );
    }
    if ( index < v5 )
    {
      v12 = index;
      v13 = v5 - index;
      do
      {
        v14 = &this->indexChain[v12++];
        *v14 = v14[1];
        --v13;
      }
      while ( v13 != 0 );
    }
    this->indexChain[v5] = -1;
  }
}


// ========================================================================
// ?GenerateKeyForString@idHashIndex@@QBAHPBD_N@Z
// EA  : 0x8265C338
// RVA : 0x0065C338
// PDB : w:\tech5\shared\idlib\containers\hashindex.h
// ========================================================================

int __fastcall idHashIndex::GenerateKeyForString(idHashIndex *this, const char *string, bool caseSensitive)
{
  const char *v3; // r9
  unsigned __int8 v4; // r8
  int v5; // r11

  v3 = string;
  if ( !caseSensitive )
    return idStr::IHash(string) & this->hashMask;
  v4 = *string;
  v5 = 0;
  if ( *string != 0 )
  {
    do
    {
      ++v3;
      v5 = 31 * v5 + v4;
      v4 = *v3;
    }
    while ( *v3 != 0 );
  }
  return this->hashMask & v5;
}


// ========================================================================
// ??4idHashIndex@@QAAAAV0@ABV0@@Z
// EA  : 0x8280D9D0
// RVA : 0x0080D9D0
// PDB : w:\tech5\shared\idlib\containers\hashindex.h
// ========================================================================

idHashIndex *__fastcall idHashIndex::operator=(idHashIndex *this, const idHashIndex *other)
{
  int hashSize; // r11
  memTag_t memTag; // r6
  int *indexChain; // r4
  int indexSize; // r11
  memTag_t v9; // r6

  this->granularity = other->granularity;
  this->hashMask = other->hashMask;
  this->lookupMask = other->lookupMask;
  if ( other->lookupMask == 0 )
  {
    this->hashSize = other->hashSize;
    this->indexSize = other->indexSize;
    idHashIndex::Free(this);
    return this;
  }
  if ( other->hashSize == this->hashSize )
  {
    if ( this->hash != idHashIndex::INVALID_INDEX )
      goto LABEL_9;
  }
  else if ( this->hash != idHashIndex::INVALID_INDEX )
  {
    idMem::Free(this: &mem, ptr: this->hash, align: ALIGN_16);
  }
  hashSize = other->hashSize;
  memTag = this->memTag;
  this->hashSize = hashSize;
  this->hash = (int *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\containers/HashIndex.h(220) : memTag",
                        size: 4 * hashSize,
                        tag: memTag,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
LABEL_9:
  if ( other->indexSize != this->indexSize || this->indexChain == idHashIndex::INVALID_INDEX )
  {
    indexChain = this->indexChain;
    if ( indexChain != idHashIndex::INVALID_INDEX )
      idMem::Free(this: &mem, ptr: indexChain, align: ALIGN_16);
    indexSize = other->indexSize;
    v9 = this->memTag;
    this->indexSize = indexSize;
    this->indexChain = (int *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\containers/HashIndex.h(227) : memTag",
                                size: 4 * indexSize,
                                tag: v9,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  }
  memcpy(Dst: this->hash, Src: other->hash, Size: 4 * this->hashSize);
  memcpy(Dst: this->indexChain, Src: other->indexChain, Size: 4 * this->indexSize);
  return this;
}


// ========================================================================
// ?RemoveIndexFast@idHashIndex@@QAAXHH@Z
// EA  : 0x8280DB38
// RVA : 0x0080DB38
// PDB : w:\tech5\shared\idlib\containers\hashindex.h
// ========================================================================

void __fastcall idHashIndex::RemoveIndexFast(idHashIndex *this, int key, int index)
{
  int hashSize; // r7
  int v6; // r31
  int v7; // r30
  int v8; // r10
  int *hash; // r8
  int i; // r11

  hashSize = this->hashSize;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( hashSize > 0 )
  {
    hash = this->hash;
    do
    {
      for ( i = *hash; i != -1; i = this->indexChain[i] )
      {
        if ( i > v6 )
        {
          v6 = i;
          v7 = v8;
        }
      }
      ++v8;
      ++hash;
    }
    while ( v8 < hashSize );
  }
  idHashIndex::Remove(this, key, index);
  if ( v6 > index )
  {
    idHashIndex::Remove(this, key: v7, index: v6);
    idHashIndex::Add(this, key: v7, index);
  }
}


// ========================================================================
// ?InsertIndex@idHashIndex@@QAAXHH@Z
// EA  : 0x82A431A8
// RVA : 0x00A431A8
// PDB : w:\tech5\shared\idlib\containers\hashindex.h
// ========================================================================

void __fastcall idHashIndex::InsertIndex(idHashIndex *this, const int key, int index)
{
  int *hash; // r10
  int v7; // r30
  int v8; // r8
  int v9; // r11
  int v10; // r9
  int indexSize; // r10
  int v12; // r8
  int v13; // r11
  int *indexChain; // r10
  int *v15; // r7
  int v16; // r11
  int v17; // ctr
  int *v18; // r10
  int v19; // r11
  int v20; // r6

  hash = this->hash;
  if ( this->hash == idHashIndex::INVALID_INDEX )
    goto LABEL_20;
  v7 = index;
  v8 = 0;
  if ( this->hashSize > 0 )
  {
    v9 = 0;
    do
    {
      v10 = hash[v9];
      if ( v10 >= index )
      {
        hash[v9] = v10 + 1;
        hash = this->hash;
        if ( this->hash[v9] > v7 )
          v7 = this->hash[v9];
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->hashSize );
  }
  indexSize = this->indexSize;
  v12 = 0;
  if ( indexSize > 0 )
  {
    v13 = 0;
    do
    {
      indexChain = this->indexChain;
      if ( indexChain[v13] >= index )
      {
        ++indexChain[v13];
        v15 = this->indexChain;
        if ( v15[v13] > v7 )
          v7 = v15[v13];
      }
      indexSize = this->indexSize;
      ++v12;
      ++v13;
    }
    while ( v12 < indexSize );
  }
  if ( v7 >= indexSize )
    idHashIndex::ResizeIndex(this, newIndexSize: v7 + 1);
  if ( v7 > index )
  {
    v16 = v7;
    v17 = v7 - index;
    do
    {
      v18 = &this->indexChain[v16--];
      *v18 = *(v18 - 1);
      --v17;
    }
    while ( v17 != 0 );
  }
  this->indexChain[index] = -1;
  if ( this->hash == idHashIndex::INVALID_INDEX )
  {
LABEL_20:
    v19 = this->indexSize;
    if ( index >= v19 )
      v19 = index + 1;
    idHashIndex::Allocate(this, newHashSize: this->hashSize, newIndexSize: v19);
  }
  else if ( index >= this->indexSize )
  {
    idHashIndex::ResizeIndex(this, newIndexSize: index + 1);
  }
  v20 = this->hashMask & key;
  this->indexChain[index] = this->hash[v20];
  this->hash[v20] = index;
}

