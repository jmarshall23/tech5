
// ========================================================================
// SortTriangleIndexes
// EA  : 0x82878890
// RVA : 0x00878890
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

int __fastcall SortTriangleIndexes(unsigned __int16 *a, unsigned __int16 *b)
{
  unsigned int v2; // r11
  unsigned int v3; // r10
  unsigned int v5; // r11
  unsigned int v6; // r10
  unsigned int v7; // r11
  unsigned int v8; // r10

  v2 = *b;
  v3 = *a;
  if ( v3 < v2 )
    return -1;
  if ( v3 > v2 )
    return 1;
  v5 = b[1];
  v6 = a[1];
  if ( v6 < v5 )
    return -1;
  if ( v6 > v5 )
    return 1;
  v7 = b[2];
  v8 = a[2];
  if ( v8 < v7 )
    return -1;
  return v7 < v8;
}


// ========================================================================
// ?PutIndexesInSortedOrderForComparison@@YAXHPAG@Z
// EA  : 0x828788E8
// RVA : 0x008788E8
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void __fastcall PutIndexesInSortedOrderForComparison(int numIndexes, unsigned __int16 *indexes)
{
  int v4; // r31
  unsigned __int16 *v6; // r27
  char *v7; // r9
  int v8; // r10
  int i; // ctr
  int v10; // r8
  int v11; // r7
  int v12; // r6
  __int16 v13; // r5
  unsigned __int16 v14; // r4
  int v15; // r10
  unsigned int v16; // r8
  unsigned __int16 v17; // r9
  unsigned __int16 v18; // r8
  char v19; // [sp+4Eh] [-52h] BYREF
  unsigned __int16 v20; // [sp+50h] [-50h] BYREF
  _WORD v21[2]; // [sp+52h] [-4Eh] BYREF
  unsigned __int16 v22; // [sp+56h] [-4Ah]
  unsigned __int16 v23; // [sp+58h] [-48h]
  unsigned __int16 v24; // [sp+5Ch] [-44h]
  unsigned __int16 v25; // [sp+5Eh] [-42h]

  v4 = 0;
  if ( numIndexes > 0 )
  {
    v6 = indexes - 1;
    do
    {
      v7 = &v19;
      v8 = 0;
      for ( i = 3; i != 0; --i )
      {
        v10 = 2 * (v8 % 3 + v4);
        v11 = (v8 + 1) % 3 + v4;
        v12 = (v8 + 2) % 3 + v4;
        ++v8;
        v13 = *(unsigned __int16 *)((char *)indexes + v10);
        v14 = indexes[v11];
        LOWORD(v10) = indexes[v12];
        *((_WORD *)v7 + 1) = v13;
        *((_WORD *)v7 + 2) = v14;
        v7 += 6;
        *(_WORD *)v7 = v10;
      }
      v15 = 0;
      if ( v22 < (unsigned int)v20 || v22 == v20 && v23 < (unsigned int)v21[0] )
        v15 = 1;
      v16 = v21[3 * v15 - 1];
      if ( v24 < v16 || v24 == v16 && v25 < (unsigned int)(unsigned __int16)v21[3 * v15] )
        v15 = 2;
      v4 += 3;
      v17 = v21[3 * v15];
      v18 = v21[3 * v15 + 1];
      v6[1] = v21[3 * v15 - 1];
      v6[2] = v17;
      v6 += 3;
      *v6 = v18;
    }
    while ( v4 < numIndexes );
  }
  qsort(
    base: indexes,
    num: numIndexes / 3,
    width: 6u,
    comp: (int (__fastcall *)(const void *, const void *))SortTriangleIndexes);
}


// ========================================================================
// ?RemoveDuplicatedTrianglesFromSortedList@@YAHHPAG@Z
// EA  : 0x82878A78
// RVA : 0x00878A78
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

int __fastcall RemoveDuplicatedTrianglesFromSortedList(int numIndexes, unsigned __int16 *indexes)
{
  int v2; // r9
  int v4; // r28
  unsigned __int16 *v5; // r30
  int v6; // r11
  int v7; // r31
  unsigned __int16 *v8; // r10

  v2 = numIndexes - 3;
  v4 = numIndexes;
  if ( numIndexes - 3 >= 3 )
  {
    v5 = &indexes[v2];
    do
    {
      v6 = 0;
      v7 = v2 - 3;
      v8 = v5;
      do
      {
        if ( *v8 != indexes[v7 + v6] )
          break;
        ++v6;
        ++v8;
      }
      while ( v6 < 3 );
      if ( v6 == 3 )
      {
        v4 -= 3;
        memmove(Dst: v5, Src: v5 + 3, Size: 2 * (v4 - v2));
      }
      v2 = v7;
      v5 -= 3;
    }
    while ( v7 >= 3 );
  }
  return v4;
}


// ========================================================================
// ?StripIndexesToTriangleIndexes@@YAXPBGHAAV?$idList@G$04@@@Z
// EA  : 0x82878B48
// RVA : 0x00878B48
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void __fastcall StripIndexesToTriangleIndexes(
        const unsigned __int16 *stripIndexes,
        int numStripIndexes,
        idList<idVehicleState *,5> *triIndexes)
{
  int v6; // r29
  const unsigned __int16 *v7; // r11
  int v8; // r31
  unsigned __int16 *v9; // r30
  const unsigned __int16 *v10; // r11
  int v11; // r26
  unsigned __int16 v12; // r27
  unsigned __int16 v13; // r30
  unsigned __int16 *v14; // r24
  int num; // r11
  int v16; // r31
  int v17; // r9
  int v18; // r8
  int v19; // r11
  int size; // r11
  int v21; // r31
  unsigned __int16 v22[48]; // [sp+50h] [-60h] BYREF

  idList<idThread *,58>::Clear(this: triIndexes);
  v6 = 0;
  while ( v6 < numStripIndexes )
  {
    v7 = &stripIndexes[v6];
    do
    {
      if ( *v7 != 0xFFFF )
        break;
      ++v6;
      ++v7;
    }
    while ( v6 < numStripIndexes );
    if ( v6 == numStripIndexes )
      break;
    v8 = 3;
    v9 = (unsigned __int16 *)&stripIndexes[v6];
    v6 += 3;
    do
    {
      idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)triIndexes, obj: v9);
      --v8;
      ++v9;
    }
    while ( v8 != 0 );
    v10 = &stripIndexes[v6];
    v11 = 0;
    v12 = stripIndexes[v6 - 2];
    v13 = *(v10 - 1);
    if ( v6 >= numStripIndexes )
      break;
    v14 = (unsigned __int16 *)(v10 - 1);
    while ( 1 )
    {
      num = triIndexes->num;
      v16 = num - 3;
      v17 = *((unsigned __int16 *)triIndexes->list + num - 3);
      v18 = *((unsigned __int16 *)triIndexes->list + num - 2);
      if ( v17 == v18 || (v19 = *((unsigned __int16 *)triIndexes->list + num - 1), v17 == v19) || v18 == v19 )
      {
        if ( v16 <= triIndexes->size
          || (unsigned __int8)idList<unsigned short,30>::Resize(
                                this: (idList<unsigned short,5> *)triIndexes,
                                newsize: v16) != 0 )
        {
          size = triIndexes->size;
          if ( v16 < size )
            size = v16;
          triIndexes->num = size;
        }
      }
      v21 = *++v14;
      ++v6;
      if ( v21 == 0xFFFF )
        break;
      v22[0] = *v14;
      idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)triIndexes, obj: v22);
      if ( v11 != 0 )
      {
        v22[0] = v12;
        idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)triIndexes, obj: v22);
        v22[0] = v13;
      }
      else
      {
        v22[0] = v13;
        idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)triIndexes, obj: v22);
        v22[0] = v12;
      }
      idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)triIndexes, obj: v22);
      v12 = v13;
      v13 = v21;
      v11 ^= 1u;
      if ( v6 >= numStripIndexes )
        return;
    }
  }
}


// ========================================================================
// ?convertStripsToTris_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82878D10
// RVA : 0x00878D10
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void __fastcall convertStripsToTris_f(const idCmdArgs *args)
{
  int v1; // r25
  int v2; // r18
  int v3; // r21
  _DWORD *v4; // r27
  int v5; // r24
  int v6; // r26
  idTriangles *v7; // r30
  const unsigned __int16 *v8; // r3
  int num; // r11
  unsigned __int16 *indexes; // r4
  idVehicleState **list; // r28
  idList<idVehicleState *,5> v12; // [sp+60h] [-A0h] BYREF
  idList<idVehicleState *,5> v13[9]; // [sp+70h] [-90h] BYREF

  memset(v13, 0, 14);
  v13[0].listStatic = 0;
  v13[0].memTag = 5;
  idList<idThread *,58>::Clear(this: v13);
  idResourceList::GetLoadedResources(this: &idStaticModel::resourceList, resourceList: v13);
  v1 = 0;
  v2 = 0;
  if ( v13[0].num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = _RTDynamicCast(
             inptr: v13[0].list[v3],
             VfDelta: 0,
             SrcType: &idResource `RTTI Type Descriptor',
             TargetType: &idStaticModel `RTTI Type Descriptor',
             isReference: 0);
      v5 = 0;
      if ( (int)v4[90] > 0 )
      {
        v6 = 0;
        do
        {
          v7 = *(idTriangles **)(v6 + v4[89] + 16);
          if ( (v7->vertexMask & 0x200) != 0 )
          {
            ++v1;
            *(_WORD *)&v12.memTag = 1280;
            memset(&v12, 0, 14);
            v8 = (const unsigned __int16 *)idIndexBuffer::MapBuffer(this: &v7->indexBuffer, mapType: BM_READ);
            StripIndexesToTriangleIndexes(stripIndexes: v8, numStripIndexes: v7->numIndexes, triIndexes: &v12);
            idIndexBuffer::UnmapBuffer(this: &v7->indexBuffer);
            num = v12.num;
            indexes = v7->indexes;
            v7->vertexMask &= ~0x200u;
            v7->numIndexes = num;
            idMem::Free(this: &mem, ptr: indexes, align: ALIGN_16);
            v7->indexes = nullptr;
            idTriangles::AllocStaticTriSurfIndexes(this: v7, numIndexes: v7->numIndexes);
            list = v12.list;
            memcpy(Dst: v7->indexes, Src: v12.list, Size: 2 * v7->numIndexes);
            idTriangles::UpdateIndexBuffer(this: v7);
            if ( v12.listStatic == 0 || v12.listStatic == 2 )
            {
              if ( list != nullptr )
                idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
              v12.list = nullptr;
              v12.size = 0;
            }
            v12.num = 0;
          }
          ++v5;
          v6 += 72;
        }
        while ( v5 < v4[90] );
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v13[0].num );
  }
  idLib::Printf(fmt: "%i surfaces changed\n", v1);
  if ( (v13[0].listStatic == 0 || v13[0].listStatic == 2) && v13[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v13[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$228795
// EA  : 0x82878F18
// RVA : 0x00878F18
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_228795()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$228796
// EA  : 0x82878F40
// RVA : 0x00878F40
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_228796()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 256 + 96));
}


// ========================================================================
// ?TriangleStripper@@YAXPBGHAAV?$idList@G$04@@@Z
// EA  : 0x82879258
// RVA : 0x00879258
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void __fastcall TriangleStripper(unsigned __int16 *indexes, int numIndexes, idList<unsigned short,5> *stripIndexes)
{
  int v4; // r27
  int i; // r26
  int v7; // r29
  int *Myfirst; // r4
  int v9; // r29
  char v10; // r3
  int size; // r11
  unsigned int v12; // r9
  int v13; // r10
  int v14; // r11
  unsigned __int16 v15; // r6
  unsigned __int16 v16; // [sp+50h] [-B0h] BYREF
  unsigned int v17[3]; // [sp+54h] [-ACh] BYREF
  std::vector<int,idSTLAllocator<int> > v18; // [sp+60h] [-A0h] BYREF
  std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > v19; // [sp+70h] [-90h] BYREF
  std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > v20; // [sp+80h] [-80h] BYREF
  std::vector<unsigned short,idSTLAllocator<unsigned short> > v21; // [sp+90h] [-70h] BYREF
  NvStripifier v22[3]; // [sp+A0h] [-60h] BYREF

  v4 = -1;
  memset(&v21, 0, 12);
  if ( numIndexes > 0 )
  {
    for ( i = numIndexes; i != 0; --i )
    {
      v16 = *indexes;
      v7 = v16;
      std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(this: &v21, _Val: &v16);
      if ( v7 > v4 )
        v4 = v7;
      ++indexes;
    }
  }
  memset(&v19, 0, 12);
  memset(&v20, 0, 12);
  ContourManager::ContourManager(this: (ContourManager *)v22);
  NvStripifier::Stripify(
    this: v22,
    in_indices: &v21,
    in_cacheSize: 20,
    in_minStripLength: 0,
    maxIndex: v4 + 1,
    outStrips: &v19,
    outFaceList: &v20);
  memset(&v18, 0, 12);
  v17[0] = 0;
  NvStripifier::CreateStrips(
    this: v22,
    allStrips: &v19,
    stripIndices: &v18,
    bStitchStrips: true,
    numSeparateStrips: v17,
    bRestart: true,
    restartVal: 0xFFFFu);
  Myfirst = v18._Myfirst;
  v9 = v18._Mylast - v18._Myfirst;
  if ( v9 <= stripIndexes->size
    || (v10 = idList<unsigned short,30>::Resize(this: stripIndexes, newsize: v18._Mylast - v18._Myfirst),
        Myfirst = v18._Myfirst,
        v10 != 0) )
  {
    size = stripIndexes->size;
    if ( v9 < size )
      size = v9;
    stripIndexes->num = size;
  }
  v12 = 0;
  if ( v18._Mylast - Myfirst != 0 )
  {
    v13 = 0;
    v14 = 0;
    do
    {
      ++v12;
      v15 = Myfirst[v14++];
      stripIndexes->list[v13++] = v15;
      Myfirst = v18._Myfirst;
    }
    while ( v12 < v18._Mylast - v18._Myfirst );
  }
  if ( Myfirst != nullptr )
    idMem::Free(this: &mem, ptr: Myfirst, align: ALIGN_16);
  memset(&v18, 0, 12);
  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)v22);
  if ( v20._Myfirst != nullptr )
    idMem::Free(this: &mem, ptr: v20._Myfirst, align: ALIGN_16);
  memset(&v20, 0, 12);
  if ( v19._Myfirst != nullptr )
    idMem::Free(this: &mem, ptr: v19._Myfirst, align: ALIGN_16);
  memset(&v19, 0, 12);
  if ( v21._Myfirst != nullptr )
    idMem::Free(this: &mem, ptr: v21._Myfirst, align: ALIGN_16);
}


// ========================================================================
// __unwind$229372
// EA  : 0x82879468
// RVA : 0x00879468
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_229372()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$229373
// EA  : 0x82879490
// RVA : 0x00879490
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_229373()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$229374
// EA  : 0x828794B8
// RVA : 0x008794B8
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_229374()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$229375
// EA  : 0x828794E0
// RVA : 0x008794E0
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_229375()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$229376
// EA  : 0x82879508
// RVA : 0x00879508
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_229376()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 256 + 96));
}


// ========================================================================
// ?convertToTriStrips_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82879538
// RVA : 0x00879538
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void __fastcall convertToTriStrips_f(const idCmdArgs *args)
{
  unsigned int v1; // r15
  unsigned int v2; // r19
  int v3; // r16
  _DWORD *v4; // r21
  int v5; // r17
  int v6; // r20
  idTriangles *v7; // r30
  int numIndexes; // r4
  const void *v9; // r3
  int v10; // r3
  int v11; // r27
  int v12; // r28
  void *v13; // r25
  __int64 v14; // kr00_8
  int v15; // r10
  __int64 v16; // r27
  int i; // r11
  double v18; // r4
  double v19; // r4
  int v20; // [sp+50h] [-F0h]
  idList<idVehicleState *,5> v21; // [sp+70h] [-D0h] BYREF
  idList<unsigned short,5> v22; // [sp+80h] [-C0h] BYREF
  idList<idVehicleState *,5> v23; // [sp+90h] [-B0h] BYREF

  memset(&v23, 0, 14);
  *(_WORD *)&v23.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v23);
  idResourceList::GetLoadedResources(this: &idStaticModel::resourceList, resourceList: &v23);
  v20 = 0;
  v1 = 0;
  v2 = 0;
  if ( v23.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = _RTDynamicCast(
             inptr: v23.list[v3],
             VfDelta: 0,
             SrcType: &idResource `RTTI Type Descriptor',
             TargetType: &idStaticModel `RTTI Type Descriptor',
             isReference: 0);
      v5 = 0;
      if ( (int)v4[90] > 0 )
      {
        v6 = 0;
        do
        {
          v7 = *(idTriangles **)(v6 + v4[89] + 16);
          if ( (v7->vertexMask & 0x200) == 0 )
          {
            numIndexes = v7->numIndexes;
            v1 += 2 * numIndexes;
            if ( v7->indexes == nullptr )
            {
              idTriangles::AllocStaticTriSurfIndexes(this: *(idTriangles **)(v6 + v4[89] + 16), numIndexes);
              v9 = idIndexBuffer::MapBuffer(this: &v7->indexBuffer, mapType: BM_READ);
              memcpy(Dst: v7->indexes, Src: v9, Size: 2 * v7->numIndexes);
              idIndexBuffer::UnmapBuffer(this: &v7->indexBuffer);
            }
            idTriangles::RemoveDegenerate(this: v7);
            PutIndexesInSortedOrderForComparison(numIndexes: v7->numIndexes, indexes: v7->indexes);
            v10 = RemoveDuplicatedTrianglesFromSortedList(numIndexes: v7->numIndexes, indexes: v7->indexes);
            v7->numIndexes = v10;
            v11 = 2 * v10;
            v12 = v10;
            v13 = idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                    size: 2 * v10,
                    tag: TAG_TEMP,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
            memcpy(Dst: v13, Src: v7->indexes, Size: 2 * v7->numIndexes);
            *(_WORD *)&v22.memTag = 1280;
            memset(&v22, 0, 14);
            TriangleStripper(indexes: v7->indexes, numIndexes: v7->numIndexes, stripIndexes: &v22);
            v14 = *(_QWORD *)&v22.list;
            if ( v22.num < v12 )
            {
              v7->numIndexes = v22.num;
              v7->detailOffset = v14;
              v15 = 0;
              v2 += 2 * v14;
              if ( (int)v14 > 0 )
              {
                do
                {
                  ++v15;
                  *(unsigned __int16 *)((char *)v7->indexes + v14) = *(_WORD *)(v14 + HIDWORD(v14));
                }
                while ( v15 < v7->numIndexes );
              }
              *(_WORD *)&v21.memTag = 1280;
              memset(&v21, 0, 14);
              StripIndexesToTriangleIndexes(
                stripIndexes: v7->indexes,
                numStripIndexes: v7->numIndexes,
                triIndexes: &v21);
              v16 = *(_QWORD *)&v21.list;
              PutIndexesInSortedOrderForComparison(numIndexes: v21.num, indexes: (unsigned __int16 *)v21.list);
              for ( i = 0; i < v12; ++i )
              {
                if ( i >= (int)v16 )
                  break;
              }
              v7->vertexMask |= 0x200u;
              idTriangles::UpdateIndexBuffer(this: v7);
              if ( v21.listStatic == 0 || v21.listStatic == 2 )
              {
                if ( HIDWORD(v16) != 0 )
                  idMem::Free(this: &mem, ptr: (void *)HIDWORD(v16), align: ALIGN_16);
                v21.list = nullptr;
                v21.size = 0;
              }
              v21.num = 0;
            }
            else
            {
              v2 += v11;
            }
            if ( v22.listStatic == 0 || v22.listStatic == 2 )
            {
              if ( HIDWORD(v14) != 0 )
                idMem::Free(this: &mem, ptr: (void *)HIDWORD(v14), align: ALIGN_16);
              v22.list = nullptr;
              v22.size = 0;
            }
            v22.num = 0;
            if ( v13 != nullptr )
              idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
          }
          ++v5;
          v6 += 72;
        }
        while ( v5 < v4[90] );
      }
      ++v3;
      ++v20;
    }
    while ( v20 < v23.num );
  }
  v18 = (float)((float)__SPAIR64__(&unk_821D0000, v1) * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v18), LODWORD(v18));
  v19 = (float)((float)__SPAIR64__("ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY", v2) * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v19), LODWORD(v19));
  if ( (v23.listStatic == 0 || v23.listStatic == 2) && v23.list != nullptr )
    idMem::Free(this: &mem, ptr: v23.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$229654
// EA  : 0x82879910
// RVA : 0x00879910
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_229654()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 144));
}


// ========================================================================
// __unwind$229655
// EA  : 0x82879938
// RVA : 0x00879938
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_229655()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$229656
// EA  : 0x82879960
// RVA : 0x00879960
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_229656()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$229657
// EA  : 0x82879988
// RVA : 0x00879988
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

void _unwind_229657()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 112));
}


// ========================================================================
// `dynamic initializer for 'convertToTriStrips_v''
// EA  : 0x83344F80
// RVA : 0x01344F80
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__convertToTriStrips_v__()
{
  return idCommandLink::idCommandLink(
           this: &convertToTriStrips_v,
           cmdName: "convertToTriStrips",
           function: convertToTriStrips_f,
           description: "convert in place for testing",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'convertStripsToTris_v''
// EA  : 0x83344FA8
// RVA : 0x01344FA8
// PDB : w:\tech5\engine\models\static\staticmodeltristrips.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__convertStripsToTris_v__()
{
  return idCommandLink::idCommandLink(
           this: &convertStripsToTris_v,
           cmdName: "convertStripsToTris",
           function: convertStripsToTris_f,
           description: "convert in place for testing",
           argCompletion: nullptr);
}

