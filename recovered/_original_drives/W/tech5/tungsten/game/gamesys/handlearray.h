
// ========================================================================
// ?Add@?$idHandleArray@VidSpawnResult@@$09@@QAAIABVidSpawnResult@@@Z
// EA  : 0x82EA6768
// RVA : 0x00EA6768
// PDB : w:\tech5\tungsten\game\gamesys\handlearray.h
// ========================================================================

unsigned int __fastcall idHandleArray<idSpawnResult,10>::Add(
        idHandleArray<idSpawnResult,10> *this,
        const idSpawnResult *element)
{
  unsigned int maxHandles; // r9
  unsigned int result; // r3
  unsigned int v5; // r10
  int v6; // r9
  char v7; // r9
  unsigned int v8; // r9
  int v9; // r7
  unsigned int *handles; // r4
  unsigned int v11; // r10
  unsigned int back_chain; // [sp+0h] [-10h]

  maxHandles = this->maxHandles;
  result = 0;
  v5 = 0;
  if ( maxHandles != 0 )
  {
    v6 = 0;
    while ( this->handles[v6] != 0 )
    {
      ++v5;
      ++v6;
      if ( v5 >= this->maxHandles )
        goto LABEL_5;
    }
    v7 = 1;
  }
  else
  {
LABEL_5:
    v5 = back_chain;
    v7 = 0;
  }
  if ( v7 != 0 )
  {
    v8 = v5 << 22;
    v9 = v5;
    this->data[v5] = *element;
    handles = this->handles;
    v11 = this->counter + 1;
    this->counter = v11;
    handles[v9] = v8 + v11;
    return v8 + v11;
  }
  return result;
}


// ========================================================================
// ??0?$idHandleArray@VidSpawnResult@@$09@@QAA@XZ
// EA  : 0x82EA6E88
// RVA : 0x00EA6E88
// PDB : w:\tech5\tungsten\game\gamesys\handlearray.h
// ========================================================================

idHandleArray<idSpawnResult,10> *__fastcall idHandleArray<idSpawnResult,10>::idHandleArray<idSpawnResult,10>(
        idHandleArray<idSpawnResult,10> *this)
{
  idSpawnResult *v2; // r3
  idSpawnLocation **p_location; // r11
  int i; // ctr
  unsigned int maxHandles; // r11
  unsigned int v6; // r5
  unsigned int *v7; // r3
  unsigned int v8; // r11

  this->data = nullptr;
  this->maxHandles = 1024;
  this->handles = nullptr;
  this->counter = 0;
  v2 = (idSpawnResult *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                          size: 0x3000u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
  {
    p_location = &v2[-1].location;
    for ( i = 1024; i != 0; --i )
    {
      p_location[1] = (idSpawnLocation *)1;
      p_location[2] = (idSpawnLocation *)0x1FFF;
      p_location += 3;
      *p_location = nullptr;
    }
  }
  else
  {
    v2 = nullptr;
  }
  maxHandles = this->maxHandles;
  this->data = v2;
  v6 = 4 * maxHandles;
  if ( maxHandles > 0x3FFFFFFF )
    v6 = -1;
  v7 = (unsigned int *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                         size: v6,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v8 = this->maxHandles;
  this->handles = v7;
  memset(Dst: this->data, Val: 0, Size: 12 * v8);
  memset(Dst: this->handles, Val: 0, Size: 4 * this->maxHandles);
  return this;
}

