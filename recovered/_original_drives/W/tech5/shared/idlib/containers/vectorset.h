
// ========================================================================
// ??0?$idVectorSubset@VidVec3@@$02@@QAA@XZ
// EA  : 0x8286DC20
// RVA : 0x0086DC20
// PDB : w:\tech5\shared\idlib\containers\vectorset.h
// ========================================================================

idVectorSubset<idVec3,3> *__fastcall idVectorSubset<idVec3,3>::idVectorSubset<idVec3,3>(idVectorSubset<idVec3,3> *this)
{
  int v2; // r29

  this->hash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->hash, initialHashSize: 1024, initialIndexSize: 1024);
  v2 = this->boxHashSize * this->boxHashSize * this->boxHashSize;
  idHashIndex::Free(this: &this->hash);
  this->hash.hashSize = v2;
  this->hash.indexSize = 128;
  this->hash.hashMask = v2 - 1;
  this->boxHashSize = 16;
  this->boxInvSize[0] = 0.0;
  this->boxInvSize[1] = 0.0;
  this->boxInvSize[2] = 0.0;
  this->boxHalfSize[0] = 0.0;
  this->boxHalfSize[1] = 0.0;
  this->boxHalfSize[2] = 0.0;
  return this;
}


// ========================================================================
// __unwind$237038
// EA  : 0x8286DCA4
// RVA : 0x0086DCA4
// PDB : w:\tech5\shared\idlib\containers\vectorset.h
// ========================================================================

void _unwind_237038()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: *(idHashIndex **)(v0 - 112 + 132));
}


// ========================================================================
// ?Init@?$idVectorSubset@VidVec3@@$02@@QAAXABVidVec3@@0HH@Z
// EA  : 0x8286DCD0
// RVA : 0x0086DCD0
// PDB : w:\tech5\shared\idlib\containers\vectorset.h
// ========================================================================

void __fastcall idVectorSubset<idVec3,3>::Init(
        idVectorSubset<idVec3,3> *this,
        const idVec3 *mins,
        const idVec3 *maxs,
        int boxHashSize,
        int initialSize)
{
  int v10; // r31
  __int64 v11; // r9
  double v12; // fp12
  double v13; // fp6
  double v14; // fp11

  v10 = boxHashSize * boxHashSize * boxHashSize;
  idHashIndex::Free(this: &this->hash);
  this->hash.hashSize = v10;
  this->hash.indexSize = initialSize;
  LODWORD(v11) = boxHashSize;
  this->hash.hashMask = v10 - 1;
  this->mins = *mins;
  this->maxs = *maxs;
  this->boxHashSize = boxHashSize;
  v12 = (float)((float)(maxs->x - mins->x) / (float)v11);
  this->boxInvSize[0] = (float)1.0 / (float)((float)(maxs->x - mins->x) / (float)v11);
  this->boxHalfSize[0] = (float)v12 * (float)0.5;
  v13 = (float)((float)(maxs->y - mins->y) / (float)v11);
  this->boxInvSize[1] = (float)1.0 / (float)((float)(maxs->y - mins->y) / (float)v11);
  this->boxHalfSize[1] = (float)v13 * (float)0.5;
  v14 = (float)((float)(maxs->z - mins->z) / (float)v11);
  this->boxInvSize[2] = (float)1.0 / (float)((float)(maxs->z - mins->z) / (float)v11);
  this->boxHalfSize[2] = (float)v14 * (float)0.5;
}


// ========================================================================
// ?FindVector@?$idVectorSubset@VidVec3@@$02@@QAAHPBVidVec3@@HM@Z
// EA  : 0x8286DDD0
// RVA : 0x0086DDD0
// PDB : w:\tech5\shared\idlib\containers\vectorset.h
// ========================================================================

int __fastcall idVectorSubset<idVec3,3>::FindVector(
        idVectorSubset<idVec3,3> *this,
        const idVec3 *vectorList,
        int vectorNum,
        double epsilon)
{
  double x; // fp0
  double y; // fp13
  int lookupMask; // r26
  double z; // fp12
  const idVec3 *v9; // r8
  double v10; // fp11
  double v11; // fp10
  int boxHashSize; // r6
  double v13; // fp9
  int *hash; // r5
  int v16; // r7
  int v17; // r30
  double v18; // fp2
  double v19; // fp5
  double v20; // fp4
  int result; // r3
  int v22; // r9
  float *i; // r11
  int v24; // r30
  int indexSize; // r11
  int v26; // r6

  x = this->mins.x;
  y = this->mins.y;
  lookupMask = this->hash.lookupMask;
  z = this->mins.z;
  v9 = &vectorList[vectorNum];
  v10 = this->boxInvSize[0];
  v11 = this->boxInvSize[1];
  boxHashSize = this->boxHashSize;
  v13 = this->boxInvSize[2];
  v16 = 0;
  v17 = this->hash.hashMask & lookupMask;
  v18 = (float)((float)((float)(v9->x - this->mins.x) - this->boxHalfSize[0]) * this->boxInvSize[0]);
  v19 = (float)((float)((float)(v9->y - this->mins.y) - this->boxHalfSize[1]) * this->boxInvSize[1]);
  v20 = (float)((float)((float)(v9->z - this->mins.z) - this->boxHalfSize[2]) * this->boxInvSize[2]);
  hash = this->hash.hash;
  do
  {
    for ( result = hash[v17
                      & ((((v16 & 1) + (int)v18) * boxHashSize + ((v16 >> 1) & 1) + (int)v19) * boxHashSize
                       + ((v16 >> 2) & 1)
                       + (int)v20)]; result != -1; result = this->hash.indexChain[lookupMask & result] )
    {
      v22 = 0;
      for ( i = &v9->x;
            __fabs((float)(*(float *)((char *)i + (char *)&vectorList[result] - (char *)v9) - *i)) <= epsilon;
            ++i )
      {
        if ( ++v22 >= 3 )
          return result;
      }
    }
    ++v16;
  }
  while ( v16 < 8 );
  v24 = ((int)(float)((float)(v9->x - (float)x) * (float)v10) * boxHashSize
       + (int)(float)((float)(v9->y - (float)y) * (float)v11))
      * boxHashSize
      + (int)(float)((float)(v9->z - (float)z) * (float)v13);
  indexSize = this->hash.indexSize;
  if ( hash == idHashIndex::INVALID_INDEX )
  {
    if ( vectorNum >= indexSize )
      indexSize = vectorNum + 1;
    idHashIndex::Allocate(this: &this->hash, newHashSize: this->hash.hashSize, newIndexSize: indexSize);
  }
  else if ( vectorNum >= indexSize )
  {
    idHashIndex::ResizeIndex(this: &this->hash, newIndexSize: vectorNum + 1);
  }
  v26 = this->hash.hashMask & v24;
  this->hash.indexChain[vectorNum] = this->hash.hash[v26];
  this->hash.hash[v26] = vectorNum;
  return vectorNum;
}


// ========================================================================
// ??0?$idVectorSubset@VidVec2@@$01@@QAA@XZ
// EA  : 0x8286E028
// RVA : 0x0086E028
// PDB : w:\tech5\shared\idlib\containers\vectorset.h
// ========================================================================

idVectorSubset<idVec2,2> *__fastcall idVectorSubset<idVec2,2>::idVectorSubset<idVec2,2>(idVectorSubset<idVec2,2> *this)
{
  int v2; // r29

  this->hash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->hash, initialHashSize: 1024, initialIndexSize: 1024);
  v2 = this->boxHashSize * this->boxHashSize;
  idHashIndex::Free(this: &this->hash);
  this->hash.hashSize = v2;
  this->hash.indexSize = 128;
  this->hash.hashMask = v2 - 1;
  this->boxHashSize = 16;
  this->boxInvSize[0] = 0.0;
  this->boxInvSize[1] = 0.0;
  this->boxHalfSize[0] = 0.0;
  this->boxHalfSize[1] = 0.0;
  return this;
}


// ========================================================================
// __unwind$237254
// EA  : 0x8286E0A0
// RVA : 0x0086E0A0
// PDB : w:\tech5\shared\idlib\containers\vectorset.h
// ========================================================================

void _unwind_237254()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: *(idHashIndex **)(v0 - 112 + 132));
}


// ========================================================================
// ?Init@?$idVectorSubset@VidVec2@@$01@@QAAXABVidVec2@@0HH@Z
// EA  : 0x8286E0C8
// RVA : 0x0086E0C8
// PDB : w:\tech5\shared\idlib\containers\vectorset.h
// ========================================================================

void __fastcall idVectorSubset<idVec2,2>::Init(
        idVectorSubset<idVec2,2> *this,
        const idVec2 *mins,
        const idVec2 *maxs,
        int boxHashSize,
        int initialSize)
{
  int v10; // r31
  __int64 v11; // r10
  double v12; // fp2
  double v13; // fp8

  v10 = boxHashSize * boxHashSize;
  idHashIndex::Free(this: &this->hash);
  this->hash.hashSize = v10;
  this->hash.indexSize = initialSize;
  LODWORD(v11) = boxHashSize;
  this->hash.hashMask = v10 - 1;
  this->mins = *mins;
  this->maxs = *maxs;
  this->boxHashSize = boxHashSize;
  v12 = (float)((float)(maxs->x - mins->x) / (float)v11);
  this->boxInvSize[0] = (float)1.0 / (float)((float)(maxs->x - mins->x) / (float)v11);
  this->boxHalfSize[0] = (float)v12 * (float)0.5;
  v13 = (float)((float)(maxs->y - mins->y) / (float)v11);
  this->boxInvSize[1] = (float)1.0 / (float)((float)(maxs->y - mins->y) / (float)v11);
  this->boxHalfSize[1] = (float)v13 * (float)0.5;
}


// ========================================================================
// ?FindVector@?$idVectorSubset@VidVec2@@$01@@QAAHPBVidVec2@@HM@Z
// EA  : 0x8286E190
// RVA : 0x0086E190
// PDB : w:\tech5\shared\idlib\containers\vectorset.h
// ========================================================================

int __fastcall idVectorSubset<idVec2,2>::FindVector(
        idVectorSubset<idVec2,2> *this,
        const idVec2 *vectorList,
        int vectorNum,
        double epsilon)
{
  double x; // fp0
  double y; // fp13
  int lookupMask; // r27
  const idVec2 *v7; // r8
  double v9; // fp12
  int boxHashSize; // r6
  double v11; // fp11
  int *hash; // r5
  int v14; // r7
  int v15; // r30
  int v16; // r29
  int v17; // r28
  int result; // r3
  int v19; // r10
  float *i; // r11
  int v21; // r30
  int indexSize; // r11
  int v23; // r6

  x = this->mins.x;
  y = this->mins.y;
  lookupMask = this->hash.lookupMask;
  v7 = &vectorList[vectorNum];
  v9 = this->boxInvSize[0];
  boxHashSize = this->boxHashSize;
  v11 = this->boxInvSize[1];
  hash = this->hash.hash;
  v14 = 0;
  v15 = lookupMask & this->hash.hashMask;
  v16 = (int)(float)((float)((float)(v7->x - this->mins.x) - this->boxHalfSize[0]) * this->boxInvSize[0]);
  v17 = (int)(float)((float)((float)(v7->y - this->mins.y) - this->boxHalfSize[1]) * this->boxInvSize[1]);
  do
  {
    for ( result = hash[v15 & (((v14 & 1) + v16) * boxHashSize + ((v14 >> 1) & 1) + v17)];
          result != -1;
          result = this->hash.indexChain[lookupMask & result] )
    {
      v19 = 0;
      for ( i = &v7->x;
            __fabs((float)(*(float *)((char *)i + (char *)&vectorList[result] - (char *)v7) - *i)) <= epsilon;
            ++i )
      {
        if ( ++v19 >= 2 )
          return result;
      }
    }
    ++v14;
  }
  while ( v14 < 4 );
  v21 = (int)(float)((float)(v7->x - (float)x) * (float)v9) * boxHashSize
      + (int)(float)((float)(v7->y - (float)y) * (float)v11);
  indexSize = this->hash.indexSize;
  if ( hash == idHashIndex::INVALID_INDEX )
  {
    if ( vectorNum >= indexSize )
      indexSize = vectorNum + 1;
    idHashIndex::Allocate(this: &this->hash, newHashSize: this->hash.hashSize, newIndexSize: indexSize);
  }
  else if ( vectorNum >= indexSize )
  {
    idHashIndex::ResizeIndex(this: &this->hash, newIndexSize: vectorNum + 1);
  }
  v23 = this->hash.hashMask & v21;
  this->hash.indexChain[vectorNum] = this->hash.hash[v23];
  this->hash.hash[v23] = vectorNum;
  return vectorNum;
}

