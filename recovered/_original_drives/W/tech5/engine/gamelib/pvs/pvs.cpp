
// ========================================================================
// ?DecompressAddPVS@idPVS@@CAXPAEHPBE@Z
// EA  : 0x8276A008
// RVA : 0x0076A008
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

void __fastcall idPVS::DecompressAddPVS(unsigned __int8 *pvs, int numBytes, const unsigned __int8 *compressed)
{
  int v3; // r6
  int v4; // r11
  const unsigned __int8 *v5; // r7
  unsigned __int8 v6; // r10
  int v7; // r8
  int v8; // r10
  bool v9; // zf
  int v10; // r10
  int v11; // r5

  v3 = 8 * numBytes;
  v4 = 0;
  if ( 8 * numBytes > 0 )
  {
    v5 = compressed - 1;
    while ( 1 )
    {
      v6 = v5[1];
      v7 = v6;
      ++v5;
      if ( (v6 & 0x80) == 0 )
        break;
      v9 = (v6 & 0x40) == 0;
      v8 = v6 & 0x3F;
      if ( !v9 )
        v8 |= __ROL4__(*++v5, 6);
      v4 += v8 + 1;
LABEL_10:
      if ( v4 >= v3 )
        return;
    }
    v10 = 0;
    while ( v4 < v3 )
    {
      v11 = (v7 >> v10++) & 1;
      pvs[v4 >> 3] |= (_BYTE)v11 << (v4 & 7);
      ++v4;
      if ( v10 >= 7 )
        goto LABEL_10;
    }
  }
}


// ========================================================================
// ?GetPVSAreas@idPVS@@QBAHABVidBounds@@PAHH@Z
// EA  : 0x8276A0B0
// RVA : 0x0076A0B0
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

int __fastcall idPVS::GetPVSAreas(idPVS *this, idBounds *bounds, int *areas, int maxAreas)
{
  int v9; // r27
  int v10; // r11
  int v11; // r29
  char *v12; // r30
  int *v13; // r24
  int v14; // r9
  int v15; // r10
  int *v16; // r11
  pvsNode_t *v17; // r31
  const idPlane *v18; // r4
  int v19; // r3
  char v20; // [sp+50h] [-260h] BYREF

  if ( this->header.numNodes <= 1 )
  {
    *areas = 0;
    return 1;
  }
  v9 = 0;
  v10 = 1;
  v11 = 0;
  v12 = &v20;
  v13 = areas - 1;
  while ( 1 )
  {
    while ( v10 > 0 )
    {
      v17 = &this->nodes[v10];
      v18 = &this->planes[v17->planeNum];
      *(_DWORD *)v12 = v17->children[1];
      v19 = idBounds::PlaneSide(this: bounds, plane: v18, epsilon: 0.1);
      if ( v19 == 3 )
      {
        ++v9;
        v12 += 4;
        v10 = v17->children[0];
      }
      else
      {
        v10 = v17->children[v19];
      }
    }
    if ( v10 < 0 )
    {
      v14 = -1 - v10;
      v15 = 0;
      if ( v11 <= 0 )
        break;
      v16 = areas;
      while ( *v16 != v14 )
      {
        ++v15;
        ++v16;
        if ( v15 >= v11 )
          goto LABEL_10;
      }
    }
LABEL_12:
    if ( v9 == 0 )
      return v11;
    v12 -= 4;
    v10 = *(_DWORD *)v12;
    --v9;
  }
LABEL_10:
  if ( v14 < 0 )
    goto LABEL_12;
  ++v11;
  *++v13 = v14;
  if ( v11 < maxAreas )
    goto LABEL_12;
  return v11;
}


// ========================================================================
// ?FreePVS@idPVS@@QBAXUpvsHandle_t@@@Z
// EA  : 0x8276A1E0
// RVA : 0x0076A1E0
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

void __fastcall idPVS::FreePVS(idPVS *this, pvsHandle_t *handle)
{
  int v2; // r6
  const int *v3; // r5
  const pvsHandle_t *v4; // r4
  idPVS *v5; // r3

  if ( (unsigned int)this < 8 && handle == *(pvsHandle_t **)(13 * (_DWORD)this + 0x64) )
  {
    (&this->__vftable)[3 * (_DWORD)&this->header.numPlanes] = (idPVS_vtbl *)-1;
  }
  else
  {
    idLib::Error(fmt: "idPVS::FreePVS: invalid handle");
    idPVS::InPVS(this: v5, handle: v4, targetAreas: v3, numTargetAreas: v2);
  }
}


// ========================================================================
// ?InPVS@idPVS@@QBA_NUpvsHandle_t@@PBHH@Z
// EA  : 0x8276A258
// RVA : 0x0076A258
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

int __fastcall idPVS::InPVS(idPVS *this, const pvsHandle_t *handle, int targetAreas, int numTargetAreas)
{
  const int *v4; // r11
  int v5; // r9
  int v6; // r10
  const pvsHandle_t *v8; // [sp+7Ch] [+1Ch]

  v8 = handle;
  v4 = (const int *)targetAreas;
  if ( (unsigned int)this >= 8
    || (targetAreas = 3 * (_DWORD)this, handle = *(const pvsHandle_t **)(13 * (_DWORD)this + 0x64), v8 != handle) )
  {
    idLib::Error(fmt: "idPVS::InPVS: invalid handle", handle, targetAreas, numTargetAreas);
    JUMPOUT(0x8276A330);
  }
  v5 = 0;
  if ( numTargetAreas <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = *v4;
    if ( *v4 >= 0
      && v6 < this->header.numAreas
      && (*(unsigned __int8 *)((v6 >> 3) + *(_DWORD *)(13 * (_DWORD)this + 0x68)) & (1 << (v6 & 7))) != 0 )
    {
      break;
    }
    ++v5;
    ++v4;
    if ( v5 >= numTargetAreas )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??0idPVS@@QAA@XZ
// EA  : 0x8276A3E0
// RVA : 0x0076A3E0
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

idPVS *__fastcall idPVS::idPVS(idPVS *this)
{
  this->__vftable = (idPVS_vtbl *)&idPVS::`vftable';
  this->pvsName.len = 0;
  this->pvsName.allocedAndFlag = 20;
  this->pvsName.data = this->pvsName.baseBuffer;
  this->pvsName.baseBuffer[0] = 0;
  this->dataStart = nullptr;
  this->planes = nullptr;
  this->vertices = nullptr;
  this->nodes = nullptr;
  this->portals = nullptr;
  this->areas = nullptr;
  this->areaOffsets = nullptr;
  this->areaPVS = nullptr;
  this->bare = false;
  this->header.magic = 55793232;
  this->header.numPlanes = 0;
  this->header.numVertices = 0;
  this->header.numNodes = 0;
  this->header.numPortals = 0;
  this->header.numAreas = 0;
  this->header.numPVSBytes = 0;
  this->currentPVS[0].handle.i = -1;
  this->currentPVS[0].handle.h = 0;
  this->currentPVS[0].pvs = nullptr;
  this->currentPVS[1].handle.i = -1;
  this->currentPVS[1].handle.h = 0;
  this->currentPVS[1].pvs = nullptr;
  this->currentPVS[2].handle.i = -1;
  this->currentPVS[2].handle.h = 0;
  this->currentPVS[2].pvs = nullptr;
  this->currentPVS[3].handle.i = -1;
  this->currentPVS[3].handle.h = 0;
  this->currentPVS[3].pvs = nullptr;
  this->currentPVS[4].handle.i = -1;
  this->currentPVS[4].handle.h = 0;
  this->currentPVS[4].pvs = nullptr;
  this->currentPVS[5].handle.i = -1;
  this->currentPVS[5].handle.h = 0;
  this->currentPVS[5].pvs = nullptr;
  this->currentPVS[6].handle.i = -1;
  this->currentPVS[6].handle.h = 0;
  this->currentPVS[6].pvs = nullptr;
  this->currentPVS[7].handle.i = -1;
  this->currentPVS[7].handle.h = 0;
  this->currentPVS[7].pvs = nullptr;
  return this;
}


// ========================================================================
// ?Alloc@idPVS@@AAAH_N@Z
// EA  : 0x8276A4C0
// RVA : 0x0076A4C0
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

unsigned int __fastcall idPVS::Alloc(idPVS *this, bool bare)
{
  BOOL v2; // r29
  unsigned int v4; // r27
  unsigned __int8 *v5; // r3
  idPlane *v6; // r30
  int numAreas; // r7
  int numNodes; // r8
  int numPVSBytes; // r10
  pvsNode_t *v10; // r11
  int *v11; // r11
  unsigned __int8 *v12; // r11
  idVec3 *v13; // r11
  int numVertices; // r10
  int numPortals; // r9
  pvsPortal_t *v16; // r11
  unsigned __int8 **p_areaPVS; // r31
  int v18; // r30
  unsigned int v19; // r29
  unsigned __int8 *v20; // r3

  v2 = bare;
  if ( bare )
    v4 = 4 * (2 * (2 * this->header.numPlanes + this->header.numNodes) + this->header.numAreas)
       + this->header.numPVSBytes;
  else
    v4 = 4
       * (2 * (2 * this->header.numPlanes + this->header.numPortals + this->header.numNodes + this->header.numAreas)
        + 3 * this->header.numVertices
        + this->header.numAreas)
       + this->header.numPVSBytes;
  v5 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\gamelib\\pvs\\PVS.cpp(140) : TAG_PVS",
                            size: v4,
                            tag: TAG_PVS,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  this->dataStart = v5;
  v6 = (idPlane *)v5;
  memset(Dst: v5, Val: 0, Size: v4);
  numAreas = this->header.numAreas;
  numNodes = this->header.numNodes;
  numPVSBytes = this->header.numPVSBytes;
  v10 = (pvsNode_t *)&v6[this->header.numPlanes];
  this->planes = v6;
  this->nodes = v10;
  v11 = (int *)&v10[numNodes];
  this->areaOffsets = v11;
  v12 = (unsigned __int8 *)&v11[numAreas];
  this->areaPVS = v12;
  v13 = (idVec3 *)&v12[numPVSBytes];
  if ( v2 )
  {
    this->vertices = nullptr;
    this->portals = nullptr;
    this->areas = nullptr;
  }
  else
  {
    numVertices = this->header.numVertices;
    numPortals = this->header.numPortals;
    this->vertices = v13;
    v16 = (pvsPortal_t *)&v13[numVertices];
    this->portals = v16;
    this->areas = (pvsArea_t *)&v16[numPortals];
  }
  p_areaPVS = &this->areaPVS;
  v18 = 8;
  v19 = ((numAreas + 31) >> 3) & 0xFFFFFFFC;
  do
  {
    p_areaPVS[1] = (unsigned __int8 *)-1;
    p_areaPVS[2] = nullptr;
    v20 = (unsigned __int8 *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                               size: v19,
                               tag: TAG_PVS,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    p_areaPVS += 3;
    *p_areaPVS = v20;
    memset(Dst: v20, Val: 0, Size: v19);
    --v18;
  }
  while ( v18 != 0 );
  return v4;
}


// ========================================================================
// ?Free@idPVS@@AAAXXZ
// EA  : 0x8276A680
// RVA : 0x0076A680
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

void __fastcall idPVS::Free(idPVS *this)
{
  unsigned __int8 *dataStart; // r4
  void **p_pvs; // r31
  int i; // r29

  dataStart = this->dataStart;
  if ( dataStart != nullptr )
  {
    idMem::Free(this: &mem, ptr: dataStart, align: ALIGN_16);
    this->dataStart = nullptr;
  }
  this->planes = nullptr;
  p_pvs = (void **)&this->currentPVS[0].pvs;
  this->vertices = nullptr;
  this->nodes = nullptr;
  this->portals = nullptr;
  this->areas = nullptr;
  this->areaOffsets = nullptr;
  this->areaPVS = nullptr;
  for ( i = 8; i != 0; --i )
  {
    *(p_pvs - 2) = (void *)-1;
    *(p_pvs - 1) = nullptr;
    idMem::Free(this: &mem, ptr: *p_pvs, align: ALIGN_16);
    *p_pvs = nullptr;
    p_pvs += 3;
  }
}


// ========================================================================
// ?Default@idPVS@@AAAXXZ
// EA  : 0x8276A710
// RVA : 0x0076A710
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

void __fastcall idPVS::Default(idPVS *this)
{
  idPVS::Free(this);
  this->header.numPlanes = 0;
  this->header.magic = 55793232;
  this->header.numVertices = 0;
  this->header.numNodes = 0;
  this->header.numPortals = 0;
  this->header.numAreas = 1;
  this->header.numPVSBytes = 8;
  idPVS::Alloc(this, bare: false);
  this->areas->firstPortal = 0;
  this->areas->numPortals = 0;
  *this->areaOffsets = 0;
  *this->areaPVS = 127;
  this->areaPVS[1] = 127;
  this->areaPVS[2] = 127;
  this->areaPVS[3] = 127;
  this->areaPVS[4] = 127;
  this->areaPVS[5] = 127;
  this->areaPVS[6] = 127;
  this->areaPVS[7] = 127;
}


// ========================================================================
// ?GetPVSArea@idPVS@@QBAHABVidVec3@@@Z
// EA  : 0x8276A7E0
// RVA : 0x0076A7E0
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

int __fastcall idPVS::GetPVSArea(idPVS *this, const idVec3 *point)
{
  pvsNode_t *nodes; // r8
  idPlane *planes; // r9
  int v4; // r11
  pvsNode_t *v5; // r10
  double v6; // fp0

  if ( this->header.numNodes <= 1 )
    return 0;
  nodes = this->nodes;
  if ( nodes == nullptr )
    return 0;
  planes = this->planes;
  if ( planes == nullptr )
    return 0;
  v4 = 1;
  while ( 1 )
  {
    v5 = &nodes[v4];
    v6 = (float)((float)((float)(planes[v5->planeNum].a * point->x)
                       + (float)((float)(planes[v5->planeNum].b * point->y) + (float)(planes[v5->planeNum].c * point->z)))
               + planes[v5->planeNum].d);
    if ( v6 > 0.0 || v6 >= -0.0 )
      LOWORD(v4) = v5->children[0];
    else
      LOWORD(v4) = v5->children[1];
    v4 = (__int16)v4;
    if ( (v4 & 0x8000u) != 0 )
      break;
    if ( (_WORD)v4 == 0 )
      return 0;
  }
  return -1 - (__int16)v4;
}


// ========================================================================
// ?DecodePVS@idPVS@@QBA?AUpvsHandle_t@@PBHH@Z
// EA  : 0x8276A898
// RVA : 0x0076A898
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

pvsHandle_t *__fastcall idPVS::DecodePVS(
        pvsHandle_t *__return_ptr retstr,
        idPVS *this,
        const int *sourceAreas,
        int numSourceAreas)
{
  const int *v6; // r27
  unsigned int v8; // r7
  const int *v9; // r11
  int i; // ctr
  int v11; // r11
  pvsCurrent_t *currentPVS; // r10
  pvsCurrent_t *v13; // r10
  int numAreas; // r8
  void **v15; // r30
  unsigned int v16; // r29
  int v17; // r30

  v6 = sourceAreas;
  v8 = 0;
  if ( numSourceAreas > 0 )
  {
    v9 = sourceAreas - 1;
    for ( i = numSourceAreas; i != 0; --i )
      v8 ^= *++v9;
  }
  v11 = 0;
  currentPVS = this->currentPVS;
  while ( currentPVS->handle.i != -1 )
  {
    ++v11;
    ++currentPVS;
    if ( v11 >= 8 )
    {
      idLib::Error(fmt: "idPVS::AllocPVS: no free PVS left");
      break;
    }
  }
  v13 = &this->currentPVS[v11];
  retstr->i = v11;
  v13->handle.i = v11;
  this->currentPVS[v11].handle.h = v8;
  numAreas = this->header.numAreas;
  retstr->h = v13->handle.h;
  v15 = (void **)&(&this->__vftable)[3 * v11];
  v16 = ((numAreas + 31) >> 3) & 0xFFFFFFFC;
  memset(Dst: v15[26], Val: 0, Size: v16);
  idPVS::DecompressAddPVS(
    pvs: (unsigned __int8 *)v15[26],
    numBytes: v16,
    compressed: &this->areaPVS[this->areaOffsets[*v6]]);
  if ( numSourceAreas > 1 )
  {
    v17 = numSourceAreas - 1;
    do
    {
      idPVS::DecompressAddPVS(
        pvs: this->currentPVS[retstr->i].pvs,
        numBytes: v16,
        compressed: &this->areaPVS[this->areaOffsets[*++v6]]);
      --v17;
    }
    while ( v17 != 0 );
  }
  return retstr;
}


// ========================================================================
// ?LoadResource@idPVS@@QAAXXZ
// EA  : 0x8276AAE8
// RVA : 0x0076AAE8
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

void __fastcall idPVS::LoadResource(idPVS *this)
{
  idFileResource *v2; // r3
  idFileResource *v3; // r28
  idFile_Memory *File; // r3
  idFile_Memory *v5; // r30
  unsigned int v6; // r3
  idStr v7[2]; // [sp+50h] [-50h] BYREF

  idPVS::Free(this);
  idStr::idStr(this: v7, text: &this->pvsName);
  idStr::SetFileExtension(this: v7, extension: "pvs");
  v2 = (idFileResource *)idResourceList::Load(
                           this: &idFileResource::resourceList,
                           name: v7[0].data,
                           makeDefault: true,
                           skipStaleCheck: false);
  v3 = v2;
  if ( v2 == nullptr )
    goto LABEL_9;
  if ( (int)v2->length <= 0 )
    goto LABEL_9;
  File = idFileResource::GetFile(this: v2);
  v5 = File;
  if ( File == nullptr )
    goto LABEL_9;
  if ( (int)File->Length(this: File) <= 0 )
  {
    ((void (__fastcall *)(idFile_Memory *, int))v5->dtr_idFile)(a1: v5, a2: 1);
LABEL_9:
    idLib::Warning(fmt: "failed to open %s", v7[0].data);
    idPVS::Default(this);
    goto LABEL_10;
  }
  v5->Read(this: v5, a2: &this->header, a3: 28u);
  if ( this->header.magic == 55793232 )
  {
    v6 = idPVS::Alloc(this, bare: this->bare);
    v5->Read(this: v5, a2: this->planes, a3: v6);
    ((void (__fastcall *)(idFile_Memory *, int))v5->dtr_idFile)(a1: v5, a2: 1);
    ((void (__fastcall *)(idFileResource *, int))v3->dtr_idResource)(a1: v3, a2: 1);
  }
  else
  {
    idLib::Warning(fmt: "%s is not a PVS file or wrong version", v7[0].data);
    ((void (__fastcall *)(idFile_Memory *, int))v5->dtr_idFile)(a1: v5, a2: 1);
    idPVS::Default(this);
  }
LABEL_10:
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$246953
// EA  : 0x8276AC90
// RVA : 0x0076AC90
// PDB : w:\tech5\engine\gamelib\pvs\pvs.cpp
// ========================================================================

void _unwind_246953()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}

