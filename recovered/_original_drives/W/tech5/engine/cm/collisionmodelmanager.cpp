
// ========================================================================
// ?FirstActive@idCollisionGridState@@QBAHXZ
// EA  : 0x825D3960
// RVA : 0x005D3960
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

int __fastcall idCollisionGridState::FirstActive(idCollisionGridState *this)
{
  if ( this->numActive <= 0 )
    return -1;
  else
    return this->firstActive;
}


// ========================================================================
// ?Shutdown@idCollisionModelManager@@QAAXXZ
// EA  : 0x825D3980
// RVA : 0x005D3980
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionModelManager::Shutdown(idCollisionModelManager *this, memTag_t a2)
{
  if ( baseTraceWork != nullptr )
  {
    operator delete(p: baseTraceWork, tag: a2);
    baseTraceWork = nullptr;
  }
  idCollisionQueryJobManager::Shutdown(this: &cdQuery);
}


// ========================================================================
// ?FindStreamArea@idCollisionModelManager@@QAAHPAVidCollisionModel@@PBD@Z
// EA  : 0x825D39D0
// RVA : 0x005D39D0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

int __fastcall idCollisionModelManager::FindStreamArea(
        idCollisionModelManager *this,
        idCollisionModel *model,
        const char *areaName)
{
  int v5; // r30
  int i; // r31
  streamAreasPtrs_t v8; // [sp+50h] [-40h] BYREF

  if ( LOBYTE(model[2].trackedMemory) == 0 )
    return -1;
  SetupStreamAreaPtrs(header: (streamAreasHeader_t *)model[3].__vftable, ptrs: &v8);
  v5 = 0;
  if ( (int)model[3].LoadResource <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: &v8.streamAreaNameBytes[v8.streamAreas[i].volumeNameOffset], s2: areaName) != 0; ++i )
  {
    if ( ++v5 >= (int)model[3].LoadResource )
      return -1;
  }
  return v5;
}


// ========================================================================
// ?BuildModelsForMapFile@idCollisionModelManager@@QAAXPBVidMapFile@@_N@Z
// EA  : 0x825D3A68
// RVA : 0x005D3A68
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionModelManager::BuildModelsForMapFile(
        idCollisionModelManager *this,
        idDeclEntityDef *mapFile,
        bool mapModelOnly)
{
  int v5; // r29
  int v6; // r3

  v5 = Sys_Milliseconds();
  idCollisionModelBuilder::BuildForMapFile(mapFile, inlineStatic: true, mapModelOnly);
  v6 = Sys_Milliseconds();
  idLib::Printf(fmt: "%d seconds to build collision data.\n", (v6 - v5) / 1000);
}


// ========================================================================
// ?StartQueryFrame@idCollisionModelManager@@QAAXXZ
// EA  : 0x825D3AB8
// RVA : 0x005D3AB8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionModelManager::StartQueryFrame(idCollisionModelManager *this)
{
  idQueryData::StartFrame(this: cdQuery.queryData);
}


// ========================================================================
// ?LocalTranslation@idCollisionModelManager@@QAA?AVidCollisionQuery@@V2@ABVidVec3@@1ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D3AC8
// RVA : 0x005D3AC8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::LocalTranslation(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        idCollisionQuery *localSpace,
        const idVec3 *start,
        const idVec3 *end,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName)
{
  const idMat3 *v15; // [sp+8h] [-A8h]
  int v16; // [sp+Ch] [-A4h]
  const idPositionedCollisionModel *v17; // [sp+10h] [-A0h]
  int v18; // [sp+14h] [-9Ch]
  const char *v19; // [sp+18h] [-98h]

  idCollisionQueryJobManager::SubmitLocalTranslationQuery(
    (idCollisionQueryJobManager *)this,
    result: (idCollisionQuery *)&cdQuery,
    localSpace,
    start,
    end,
    globalBounds,
    trms,
    numTrms,
    trmAxis: v15,
    contentMask: v16,
    models: v17,
    numModels: v18,
    userName: v19);
  return this;
}


// ========================================================================
// ?GetContentsResult@idCollisionModelManager@@QAA_NPAUtrace_t@@AAVidCollisionQuery@@_N@Z
// EA  : 0x825D3B18
// RVA : 0x005D3B18
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

BOOL __fastcall idCollisionModelManager::GetContentsResult(
        idCollisionModelManager *this,
        trace_t *result,
        idCollisionQuery *query,
        bool peek)
{
  return idCollisionQueryJobManager::GetRotationResult(this: &cdQuery, tw: baseTraceWork, result, query, peek);
}


// ========================================================================
// ?GetMotionContactsResult@idCollisionModelManager@@QAA_NPAUtrace_t@@PAUcontactsResult_t@@AAVidCollisionQuery@@_N@Z
// EA  : 0x825D3B38
// RVA : 0x005D3B38
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

BOOL __fastcall idCollisionModelManager::GetMotionContactsResult(
        idCollisionModelManager *this,
        trace_t *result,
        contactsResult_t *contacts,
        idCollisionQuery *query,
        bool peek)
{
  return idCollisionQueryJobManager::GetMotionContactsResult(
           this: &cdQuery,
           tw: baseTraceWork,
           result,
           contacts,
           query,
           peek);
}


// ========================================================================
// ?LocalContents@idCollisionModelManager@@QAA?AVidCollisionQuery@@V2@ABVidVec3@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D3B60
// RVA : 0x005D3B60
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::LocalContents(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        idCollisionQuery *localSpace,
        const idVec3 *start,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName)
{
  int v14; // [sp+8h] [-98h]
  const idPositionedCollisionModel *v15; // [sp+Ch] [-94h]
  int v16; // [sp+10h] [-90h]
  const char *v17; // [sp+14h] [-8Ch]

  idCollisionQueryJobManager::SubmitLocalContentsQuery(
    (idCollisionQueryJobManager *)this,
    result: (idCollisionQuery *)&cdQuery,
    localSpace,
    start,
    globalBounds,
    trms,
    numTrms,
    trmAxis,
    contentMask: v14,
    models: v15,
    numModels: v16,
    userName: v17);
  return this;
}


// ========================================================================
// ?GetClipResult@idCollisionModelManager@@QAA_NPAUclipResult_t@@AAVidCollisionQuery@@_N@Z
// EA  : 0x825D3BA8
// RVA : 0x005D3BA8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

BOOL __fastcall idCollisionModelManager::GetClipResult(
        idCollisionModelManager *this,
        clipResult_t *result,
        idCollisionQuery *query,
        bool peek)
{
  return idCollisionQueryJobManager::GetClipResult(this: &cdQuery, tw: baseTraceWork, result, query, peek);
}


// ========================================================================
// ?GetStepMoveContactsResult@idCollisionModelManager@@QAA_NPAUtrace_t@@PAUcontactsResult_t@@AAVidCollisionQuery@@_N@Z
// EA  : 0x825D3BC8
// RVA : 0x005D3BC8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

BOOL __fastcall idCollisionModelManager::GetStepMoveContactsResult(
        idCollisionModelManager *this,
        trace_t *result,
        contactsResult_t *contacts,
        idCollisionQuery *query,
        bool peek)
{
  return idCollisionQueryJobManager::GetSlideMoveContactsResult(
           this: &cdQuery,
           tw: baseTraceWork,
           result,
           contacts,
           query,
           peek);
}


// ========================================================================
// ?SubmitQueries@idCollisionModelManager@@QAAXXZ
// EA  : 0x825D3BF0
// RVA : 0x005D3BF0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionModelManager::SubmitQueries(idCollisionModelManager *this)
{
  idCollisionQueryJobManager::SubmitQueries(this: &cdQuery);
}


// ========================================================================
// PrintSubModelInfo
// EA  : 0x825D3C00
// RVA : 0x005D3C00
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall PrintSubModelInfo(const cm_subModelData_t *subModelData)
{
  idLib::Printf(
    fmt: "  %6i nodes (%i kB)\n",
    subModelData->numNodes,
    ((unsigned int)subModelData->numNodes >> 6) & 0x3FFFFF);
  idLib::Printf(
    fmt: "  %6i primitive indices (%i kB)\n",
    subModelData->numPrimitiveIndices,
    ((unsigned int)subModelData->numPrimitiveIndices >> 9) & 0x3FFFFF);
  idLib::Printf(
    fmt: "  %6i materials (%i kB)\n",
    subModelData->numMaterials,
    ((unsigned int)subModelData->numMaterials >> 6) & 0x3FFFFF);
  idLib::Printf(
    fmt: "  %6i polygons (%i kB)\n",
    subModelData->numPolygons,
    ((unsigned int)subModelData->numPolygons >> 6) & 0x3FFFFF);
  idLib::Printf(
    fmt: "  %6i polygon edges (%i kB)\n",
    subModelData->numPolygonEdges,
    ((unsigned int)subModelData->numPolygonEdges >> 9) & 0x3FFFFF);
  idLib::Printf(
    fmt: "  %6i edges (%i kB)\n",
    subModelData->numEdges,
    ((unsigned int)subModelData->numEdges >> 8) & 0x3FFFFF);
  idLib::Printf(
    fmt: "  %6i vertices (%i kB)\n",
    subModelData->numVertices,
    ((unsigned int)subModelData->numVertices >> 6) & 0x3FFFFF);
  idLib::Printf(
    fmt: "  %6i polytopes (%i kB)\n",
    subModelData->numPolytopes,
    ((unsigned int)subModelData->numPolytopes >> 6) & 0x3FFFFF);
  idLib::Printf(
    fmt: "  %6i polytope planes (%i kB)\n",
    subModelData->numPolytopePlanes,
    ((unsigned int)subModelData->numPolytopePlanes >> 6) & 0x3FFFFF);
}


// ========================================================================
// AddCollisionModelInfo
// EA  : 0x825D3CE0
// RVA : 0x005D3CE0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall AddCollisionModelInfo(const idCollisionModelLocal *model, cm_subModelData_t *stats)
{
  int v4; // r28
  int v5; // r30
  const cm_subModelData_t *v6; // r3
  int numPrimitiveIndices; // r9
  int numMaterials; // r10
  int numPolygons; // r5
  int numPolygonEdges; // r6
  int numEdges; // r7
  int numVertices; // r8
  int numPolytopes; // r9
  int numPolytopePlanes; // r10

  v4 = 0;
  if ( model->polygonModel.numSubModels > 0 )
  {
    v5 = 0;
    do
    {
      v6 = AcquireSubModelData(subModel: &model->polygonModel.subModels[v5]);
      if ( v6->header.loadedSize != 32 )
      {
        numPrimitiveIndices = stats->numPrimitiveIndices;
        numMaterials = stats->numMaterials;
        numPolygons = stats->numPolygons;
        stats->numNodes += v6->numNodes;
        stats->numPrimitiveIndices = v6->numPrimitiveIndices + numPrimitiveIndices;
        stats->numMaterials = v6->numMaterials + numMaterials;
        numPolygonEdges = stats->numPolygonEdges;
        stats->numPolygons = v6->numPolygons + numPolygons;
        numEdges = stats->numEdges;
        stats->numPolygonEdges = v6->numPolygonEdges + numPolygonEdges;
        numVertices = stats->numVertices;
        stats->numEdges = v6->numEdges + numEdges;
        numPolytopes = stats->numPolytopes;
        stats->numVertices = v6->numVertices + numVertices;
        numPolytopePlanes = stats->numPolytopePlanes;
        stats->numPolytopes = v6->numPolytopes + numPolytopes;
        stats->numPolytopePlanes = v6->numPolytopePlanes + numPolytopePlanes;
      }
      ReleaseSubModelData(subModel: (const cm_subModelData_t *)&model->polygonModel.subModels[v5], data: v6);
      ++v4;
      ++v5;
    }
    while ( v4 < model->polygonModel.numSubModels );
  }
}


// ========================================================================
// ?WaitForAllQueries@idCollisionModelManager@@QAAXXZ
// EA  : 0x825D3DE0
// RVA : 0x005D3DE0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionModelManager::WaitForAllQueries(idCollisionModelManager *this)
{
  idCollisionQueryJobManager::WaitForAllQueries(this: &cdQuery);
}


// ========================================================================
// ?LoadModel@idCollisionModelManager@@QAAPAVidCollisionModel@@PBD@Z
// EA  : 0x825D4528
// RVA : 0x005D4528
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModel *__fastcall idCollisionModelManager::LoadModel(idCollisionModelManager *this, const char *modelName)
{
  return (idCollisionModel *)idResourceList::Load(
                               this: &idCollisionModelLocal::resourceList,
                               name: modelName,
                               makeDefault: true,
                               skipStaleCheck: false);
}


// ========================================================================
// ?LoadGrid@idCollisionModelManager@@QAAPAVidCollisionGrid@@PBD@Z
// EA  : 0x825D4540
// RVA : 0x005D4540
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionGrid *__fastcall idCollisionModelManager::LoadGrid(idCollisionModelManager *this, const char *modelName)
{
  return (idCollisionGrid *)idResourceList::Load(
                              this: &idCollisionGridLocal::resourceList,
                              name: modelName,
                              makeDefault: false,
                              skipStaleCheck: false);
}


// ========================================================================
// ?BuildModel@idCollisionModelManager@@QAAPAVidCollisionModel@@PBDPBVidStaticModel@@PAHH@Z
// EA  : 0x825D4560
// RVA : 0x005D4560
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelLocal *__fastcall idCollisionModelManager::BuildModel(
        idCollisionModelManager *this,
        char *modelName,
        const idStaticModel *staticModel,
        int *submodelIndices,
        int numSubmodelIndices)
{
  idCollisionModelLocal *v9; // r3
  idCollisionModelLocal *v10; // r30

  v9 = (idCollisionModelLocal *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x74u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v10 = idCollisionModelLocal::idCollisionModelLocal(this: v9);
  else
    v10 = nullptr;
  idCollisionModelBuilder::BuildForStaticModel(
    model: v10,
    staticModel,
    submodelIndices,
    numSubmodelIndices,
    optionalModelName: modelName);
  idResourceList::Add(this: &idCollisionModelLocal::resourceList, ptr: v10);
  return v10;
}


// ========================================================================
// __unwind$227542
// EA  : 0x825D45F8
// RVA : 0x005D45F8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall _unwind_227542(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?StreamModel@idCollisionModelManager@@QAAXPAVidCollisionModel@@PBHH_N@Z
// EA  : 0x825D4620
// RVA : 0x005D4620
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __fastcall idCollisionModelManager::StreamModel(
        idCollisionModelManager *this,
        idCollisionModel *model,
        const int *areas,
        int numAreas,
        bool wait,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        int a14,
        int a15,
        int a16,
        double a17,
        double a18,
        double a19,
        double a20,
        double a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float a40,
        float a41,
        float a42,
        float a43,
        float a44,
        float a45,
        float a46,
        float a47,
        float a48,
        float a49,
        float a50,
        float a51,
        float a52,
        float a53,
        float a54,
        float a55,
        float a56,
        float a57,
        float a58,
        float a59,
        float a60,
        int a61)
{
  int v61; // r4
  int v62; // r16
  _DWORD *v63; // r5
  _DWORD *v64; // r28
  int v65; // r6
  int v66; // r29
  unsigned __int8 v67; // r7
  unsigned __int8 v68; // r27
  int v69; // r26
  int v70; // r25
  signed int v71; // r5
  int v73; // r12
  unsigned int i; // r21
  _DWORD *v76; // r8
  int j; // ctr
  int v78; // r11
  streamArea_t *v79; // r10
  int v80; // r5
  int v81; // r20
  char v82; // r15
  char v83; // r23
  int v84; // r18
  int v85; // r27
  int v86; // r28
  int v87; // r29
  _QWORD *v88; // r24
  float *v89; // r26
  int v90; // r11
  __int64 v91; // r6 OVERLAPPED
  int v92; // r11
  _DWORD *v93; // r11
  int v94; // r7
  char v95; // r20
  int v96; // r19
  __int64 v97; // r8 OVERLAPPED
  __int64 v98; // r6 OVERLAPPED
  int v99; // r2 OVERLAPPED
  char v100; // r21
  int v101; // r26
  int v102; // r23
  int v103; // r28
  int v104; // r29
  int *v105; // r24
  _QWORD *v106; // r22
  int v107; // r27
  idMemoryMappedFile *v108; // r3
  _DWORD *v109; // r11
  int v110; // r11
  int *v111; // r11
  int v112; // r3
  int v113; // r11
  const unsigned __int8 *v114; // r3
  idMemoryMappedFile *v115; // r29
  unsigned __int64 v116; // r4
  double v117; // fp30
  int v118; // r4
  double v119; // fp29
  int v120; // r4
  double v121; // fp1
  int v122; // r29
  idRenderWorld *v123; // r3
  int v124; // r29
  idRenderWorld *v125; // r3
  int v126; // [sp+54h] [-C6FCh]
  int v127; // [sp+5Ch] [-C6F4h]
  int v128; // [sp+64h] [-C6ECh]
  streamAreasPtrs_t v129; // [sp+68h] [-C6E8h] BYREF
  float v130[4]; // [sp+80h] [-C6D0h] BYREF
  _BYTE v131[12]; // [sp+90h] [-C6C0h] BYREF
  float v132; // [sp+9Ch] [-C6B4h] BYREF
  void *v133; // [sp+A0h] [-C6B0h] BYREF
  void **v134[64]; // [sp+1A0h] [-C5B0h] BYREF
  volatile bool *v135[64]; // [sp+2A0h] [-C4B0h] BYREF
  int v136[62]; // [sp+3A0h] [-C3B0h] BYREF
  int v137; // [sp+498h] [-C2B8h] BYREF
  __int64 v138[64]; // [sp+4A0h] [-C2B0h] BYREF
  _BYTE v139[16384]; // [sp+6A0h] [-C0B0h] BYREF
  idMemoryMappedFile::fileRange_t v140[1024]; // [sp+46A0h] [-80B0h] BYREF
  _QWORD v141[2048]; // [sp+86A0h] [-40B0h] BYREF
  int pre_back_chain; // [sp+C750h] [+0h]

  ((void (*)(void))RtlCheckStack12)();
  v62 = v61;
  v64 = v63;
  v66 = v65;
  v68 = v67;
  if ( v65 != 0 && *(_BYTE *)(v61 + 79) != 0 )
  {
    v69 = Sys_Microseconds() >> 32;
    v127 = v69;
    ((void (*)(void))RtlCheckStack12)();
    v70 = 0;
    v71 = *(_DWORD *)(v62 + 88);
    _R11 = 0;
    *(int *)((char *)&pre_back_chain + v73) = pre_back_chain;
    for ( i = ((unsigned int)&a61 + 3) & 0xFFFFFF80; _R11 < v71; v71 = *(_DWORD *)(v62 + 88) )
    {
      __asm { dcbz128   r11, r21 }
      _R10 = *(_DWORD *)(v62 + 100);
      __asm { dcbt      r11, r10 }
      _R11 += 128;
    }
    if ( v66 == -1 )
    {
      memset(Dst: (void *)(((unsigned int)&a61 + 3) & 0xFFFFFF80), Val: 1, Size: v71);
    }
    else
    {
      SetupStreamAreaPtrs(header: *(streamAreasHeader_t **)(v62 + 108), ptrs: &v129);
      if ( v66 > 0 )
      {
        v76 = v64;
        for ( j = v66; j != 0; --j )
        {
          v78 = 0;
          v79 = &v129.streamAreas[*v76];
          if ( v79->numSubModels > 0 )
          {
            do
            {
              v80 = v79->subModelsOffset + v78++;
              *(_BYTE *)(v129.streamAreaSubModels[v80] + i) = 1;
            }
            while ( v78 < v79->numSubModels );
          }
          ++v76;
        }
      }
    }
    v81 = v68;
    v128 = (Sys_Microseconds() >> 32) - v69;
    v82 = 0;
    v126 = v68;
    while ( 1 )
    {
      v83 = 0;
      v84 = 0;
      v85 = 0;
      v86 = 0;
      if ( *(int *)(v62 + 88) > 0 )
      {
        v87 = 0;
        v88 = v139;
        v89 = &v132;
        do
        {
          if ( *(_BYTE *)(v86 + i) == 0 )
          {
            v90 = *(_DWORD *)(v62 + 100);
            if ( *(_BYTE *)(v90 + v86) == 1 )
            {
              *(_BYTE *)(v90 + v86) = -1;
              if ( Sys_InterlockedDecrement(value: (int *)(*(_DWORD *)(v62 + 96) + v87 + 40)) >= 0 )
              {
                if ( *(_DWORD *)(v62 + 112) != 0 && (((v84 >= 0) + ((unsigned int)v84 >= 0x400)) & 1) != 0 )
                {
                  ++v84;
                  v93 = (_DWORD *)(*(_DWORD *)(v62 + 96) + v87);
                  v94 = v93[9];
                  LODWORD(v91) = *v93;
                  *v88 = *(__int64 *)((char *)&v91 - 4);
                  v88[1] = v91;
                  v88 += 2;
                }
                *(_BYTE *)(*(_DWORD *)(v62 + 100) + v86) = 1;
                Sys_InterlockedIncrement(value: (int *)(*(_DWORD *)(v62 + 96) + v87 + 40));
              }
              else
              {
                Sys_InterlockedIncrement(value: (int *)(*(_DWORD *)(v62 + 96) + v87 + 40));
                v92 = *(_DWORD *)(v62 + 96) + v87;
                if ( *(_DWORD *)(v62 + 112) != 0 )
                {
                  *(_DWORD *)(v92 + 32) = 0;
                }
                else
                {
                  ++v85;
                  v82 = 1;
                  v83 = 1;
                  *++v89 = *(float *)(v92 + 32);
                  *(_DWORD *)(v92 + 32) = 0;
                  if ( v85 >= 64 )
                    break;
                }
              }
            }
          }
          ++v86;
          v87 += 48;
        }
        while ( v86 < *(_DWORD *)(v62 + 88) );
        if ( v85 > 0 )
          idStreamFileCache::BatchFreeMemory(this: streamFileCache, block: &v133, numBlocks: v85);
      }
      if ( v81 == 0 || v83 == 0 )
        break;
      idStreamFileCache::SignalWork(this: streamFileCache);
      mgthread_sleep(ms: 2);
    }
    v95 = 0;
    v96 = (Sys_Microseconds() >> 32) - v128 - v127;
    while ( 1 )
    {
      v100 = 0;
      v101 = 0;
      v102 = 0;
      v103 = 0;
      if ( *(int *)(v62 + 88) > 0 )
      {
        v104 = 0;
        v105 = &v137;
        v106 = v141;
        v107 = 0;
        do
        {
          if ( *(_BYTE *)(v103 + (((unsigned int)&a61 + 3) & 0xFFFFFF80)) != 0 )
          {
            v108 = *(idMemoryMappedFile **)(v62 + 112);
            if ( v108 != nullptr )
            {
              LODWORD(v97) = v101 >= 0;
              HIDWORD(v97) = v97 + ((unsigned int)v101 >= 0x400);
              LODWORD(v98) = BYTE3(v97) & 1;
              if ( (v97 & 0x100000000LL) != 0 )
              {
                ++v101;
                v109 = (_DWORD *)(*(_DWORD *)(v62 + 96) + v104);
                LODWORD(v97) = *v109;
                HIDWORD(v97) = v109[9];
                LODWORD(v98) = *v109;
                *v106 = *(__int64 *)((char *)&v97 + 4);
                v106[1] = v98;
                v106 += 2;
              }
            }
            v110 = *(_DWORD *)(v62 + 100);
            if ( *(_BYTE *)(v110 + v103) != 1 )
            {
              if ( *(unsigned __int8 *)(v110 + v103) == 255 )
              {
                v100 = 1;
                v95 = 1;
                *(_DWORD *)(*(_DWORD *)(v62 + 96) + v104 + 32) = 0;
                *(_BYTE *)(*(_DWORD *)(v62 + 100) + v103) = 0;
                if ( *(_DWORD *)(v62 + 112) == 0 )
                {
                  LODWORD(v97) = v134;
                  v111 = (int *)(*(_DWORD *)(v62 + 96) + v104);
                  HIDWORD(v97) = v135;
                  LODWORD(v98) = v111 + 8;
                  HIDWORD(v98) = *(_DWORD *)(v62 + 100) + v103;
                  ++v102;
                  v112 = v111[9];
                  v105 += 2;
                  *(_QWORD *)v105 = *(_QWORD *)(&v99 - 1);
                  v113 = *v111;
                  v134[v107] = (void **)v98;
                  v135[v107] = (volatile bool *)HIDWORD(v98);
                  v136[v107++] = v113;
                  if ( v107 >= 64 )
                    break;
                }
              }
              else if ( *(_BYTE *)(v110 + v103) == 0 )
              {
                v100 = 1;
                if ( v108 != nullptr )
                {
                  HIDWORD(v98) = *(_DWORD *)(*(_DWORD *)(v62 + 96) + v104);
                  v114 = idMemoryMappedFile::PointerForFileBlock(this: v108, fileOffset: v98, length: v97);
                  LODWORD(v97) = *(_DWORD *)(v62 + 96) + v104;
                  *(_DWORD *)(v97 + 32) = v114;
                  HIDWORD(v97) = *(_DWORD *)(v62 + 96) + v104;
                  LODWORD(v98) = *(_DWORD *)(HIDWORD(v97) + 32);
                  if ( (_DWORD)v98 != 0 )
                    *(_BYTE *)(*(_DWORD *)(v62 + 100) + v103) = 1;
                }
              }
            }
          }
          ++v103;
          v104 += 48;
        }
        while ( v103 < *(_DWORD *)(v62 + 88) );
      }
      v115 = *(idMemoryMappedFile **)(v62 + 112);
      if ( v115 != nullptr )
      {
        if ( v84 >= 1024 )
          v84 = 1024;
        if ( v101 >= 1024 - v84 )
          v101 = 1024 - v84;
        if ( v84 > 0 )
          blkmov(a1: v140, a2: v139, a3: 16 * v84);
        if ( v101 > 0 )
          blkmov(a1: v140, a2: &v141[2 * v84], a3: 16 * v101);
        idMemoryMappedFile::SetBatchState(this: v115, ranges: v140, numRanges: v101 + v84);
      }
      else if ( v102 > 0 )
      {
        idStreamFileCache::BatchUncachedBackgroundRead(
          this: streamFileCache,
          cacheFile: *(idFile **)(v62 + 80),
          ofs: v138,
          length: v136,
          dest: v134,
          tag: TAG_COLLISION,
          completionFlag: v135,
          numReads: v102);
      }
      if ( v126 == 0 || v100 == 0 )
        break;
      idStreamFileCache::SignalWork(this: streamFileCache);
      mgthread_sleep(ms: 2);
    }
    if ( *(_DWORD *)(v62 + 112) == 0 && (v82 != 0 || v95 != 0) )
      idStreamFileCache::SignalWork(this: streamFileCache);
    v116 = Sys_Microseconds();
    HIDWORD(v116) = HIDWORD(v116) - v96 - v128 - v127;
    if ( v82 != 0 || v95 != 0 )
    {
      v117 = (float)((float)_u64tod(a1: HIDWORD(v116), a2: v116) * (float)0.001);
      v119 = (float)((float)_u64tod(a1: v96, a2: v118) * (float)0.001);
      v121 = _u64tod(a1: v128, a2: v120);
      a20 = v119;
      a21 = v117;
      a19 = (float)((float)v121 * (float)0.001);
      idLib::Printf(fmt: (const char *)HIDWORD(a19), HIDWORD(v119), LODWORD(v119), LODWORD(v117));
    }
    if ( cm_showStreamedData.valueInteger != 0 )
    {
      if ( cm_showStreamedData.valueInteger == 1 )
      {
        if ( *(int *)(v62 + 88) > 0 )
        {
          v122 = 0;
          do
          {
            if ( *(unsigned __int8 *)(*(_DWORD *)(v62 + 100) + v70) == 255 )
            {
              v130[0] = idColor::colorRed.r;
              v130[1] = idColor::colorRed.g;
              v130[2] = idColor::colorRed.b;
              v130[3] = 0.5;
              v123 = common->RW(this: common);
              v123->DebugFilledBounds(
                this: v123,
                a2: (const idVec4 *)v130,
                a3: (const idBounds *)(*(_DWORD *)(v62 + 96) + v122 + 8),
                a4: &vec3_origin,
                a5: 0,
                a6: true);
            }
            ++v70;
            v122 += 48;
          }
          while ( v70 < *(_DWORD *)(v62 + 88) );
        }
      }
      else if ( cm_showStreamedData.valueInteger == 2 && *(int *)(v62 + 88) > 0 )
      {
        v124 = 0;
        do
        {
          if ( *(_BYTE *)(*(_DWORD *)(v62 + 100) + v70) == 0 )
          {
            qmemcpy(v131, &idColor::colorYellow, sizeof(v131));
            v132 = 0.5;
            v125 = common->RW(this: common);
            v125->DebugFilledBounds(
              this: v125,
              a2: (const idVec4 *)v131,
              a3: (const idBounds *)(*(_DWORD *)(v62 + 96) + v124 + 8),
              a4: &vec3_origin,
              a5: 0,
              a6: true);
          }
          ++v70;
          v124 += 48;
        }
        while ( v70 < *(_DWORD *)(v62 + 88) );
      }
    }
  }
}


// ========================================================================
// ?IsResident@idCollisionModelManager@@QAA_NABVidBounds@@PBVidPositionedCollisionModel@@H@Z
// EA  : 0x825D4E08
// RVA : 0x005D4E08
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

int __fastcall idCollisionModelManager::IsResident(
        idCollisionModelManager *this,
        const idBounds *globalBounds,
        const idPositionedCollisionModel *models,
        int numModels)
{
  double v6; // fp6
  int v7; // r28
  double v8; // fp4
  float *i; // r31
  int v10; // r30
  double v11; // fp10
  double v12; // fp7
  double v13; // fp2
  double v14; // fp0
  int SubModelsForTrace; // r3
  int v16; // r10
  int *v17; // r11
  idVec3 v19; // [sp+50h] [-270h] BYREF
  idVec3 v20; // [sp+60h] [-260h] BYREF
  idVec3 v21; // [sp+70h] [-250h] BYREF
  int v22[144]; // [sp+80h] [-240h] BYREF

  v6 = (float)(globalBounds->b[1].z + globalBounds->b[0].z);
  v7 = 0;
  v8 = (float)((float)(globalBounds->b[1].y + globalBounds->b[0].y) * (float)0.5);
  v19.x = (float)(globalBounds->b[1].x + globalBounds->b[0].x) * (float)0.5;
  v19.y = v8;
  v19.z = (float)v6 * (float)0.5;
  if ( numModels <= 0 )
    return 1;
  for ( i = &models->modelOrigin.z; ; i += 20 )
  {
    v10 = *((_DWORD *)i - 4);
    if ( *(int *)(v10 + 88) <= 1 )
    {
      SubModelsForTrace = 1;
      v22[0] = 0;
    }
    else
    {
      v11 = (float)(v19.y - *(i - 1));
      v12 = i[8];
      v13 = (float)((float)(i[7] * (float)(v19.x - *(i - 2))) + (float)(i[9] * (float)(v19.z - *i)));
      v14 = (float)((float)(i[5] * (float)(v19.y - *(i - 1)))
                  + (float)((float)(i[4] * (float)(v19.x - *(i - 2))) + (float)(i[6] * (float)(v19.z - *i))));
      v20.x = (float)(i[1] * (float)(v19.x - *(i - 2)))
            + (float)((float)(i[3] * (float)(v19.z - *i)) + (float)(i[2] * (float)(v19.y - *(i - 1))));
      v20.y = v14;
      v20.z = (float)((float)v12 * (float)v11) + (float)v13;
      idPolygonModelCollisionDetection::LocalExtentsFromUnTransformedBounds(
        result: &v21,
        globalBounds,
        globalStart: &v19,
        globalEnd: &v19,
        modelAxis: (const idMat3 *)(i + 1));
      SubModelsForTrace = idPolygonModelCollisionDetection::GetSubModelsForTrace(
                            model: (const cm_polygonModel_t *)(v10 + 84),
                            start: &v20,
                            end: &v20,
                            extents: &v21,
                            subModelNums: v22);
    }
    v16 = 0;
    if ( SubModelsForTrace > 0 )
      break;
LABEL_10:
    if ( ++v7 >= numModels )
      return 1;
  }
  v17 = v22;
  while ( *(_BYTE *)(*v17 + *(_DWORD *)(v10 + 100)) == 1 )
  {
    ++v16;
    ++v17;
    if ( v16 >= SubModelsForTrace )
      goto LABEL_10;
  }
  return 0;
}


// ========================================================================
// ?ModelFromTrm@idCollisionModelManager@@QAAPAVidCollisionModel@@PBDABVidTraceModel@@PBVidMaterial@@@Z
// EA  : 0x825D4FA0
// RVA : 0x005D4FA0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelLocal *__fastcall idCollisionModelManager::ModelFromTrm(
        idCollisionModelManager *this,
        const char *modelName,
        const idTraceModel *trm,
        const idMaterial *material)
{
  idCollisionModelLocal *v7; // r3
  idCollisionModelLocal *v8; // r30

  v7 = (idCollisionModelLocal *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x74u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idCollisionModelLocal::idCollisionModelLocal(this: v7);
  else
    v8 = nullptr;
  idCollisionModelBuilder::BuildForTrm(model: v8, modelName, trm, material);
  return v8;
}


// ========================================================================
// __unwind$227808
// EA  : 0x825D5020
// RVA : 0x005D5020
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall _unwind_227808(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?ModelFromRender@idCollisionModelManager@@QAAPAVidCollisionModel@@PBDPBVidRenderModel@@@Z
// EA  : 0x825D5050
// RVA : 0x005D5050
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelLocal *__fastcall idCollisionModelManager::ModelFromRender(
        idCollisionModelManager *this,
        const char *modelName,
        const idRenderModel *renderModel)
{
  idCollisionModelLocal *v4; // r3
  idCollisionModelLocal *v5; // r30

  v4 = (idCollisionModelLocal *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x74u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idCollisionModelLocal::idCollisionModelLocal(this: v4);
  else
    v5 = nullptr;
  idCollisionModelBuilder::BuildForRenderModel(model: v5, renderModel);
  return v5;
}


// ========================================================================
// __unwind$227833
// EA  : 0x825D50C0
// RVA : 0x005D50C0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall _unwind_227833(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?ModelFromGrid@idCollisionModelManager@@QAAPAVidCollisionModel@@PBDPBVidCollisionGrid@@ABVidCollisionGridState@@PBVidMaterial@@@Z
// EA  : 0x825D50F0
// RVA : 0x005D50F0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelLocal *__fastcall idCollisionModelManager::ModelFromGrid(
        idCollisionModelManager *this,
        const char *modelName,
        const idCollisionGrid *grid,
        idCollisionGridState *state,
        const idMaterial *material)
{
  idCollisionModelLocal *v9; // r3
  idCollisionModelLocal *v10; // r30

  v9 = (idCollisionModelLocal *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x74u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v10 = idCollisionModelLocal::idCollisionModelLocal(this: v9);
  else
    v10 = nullptr;
  idCollisionModelBuilder::BuildForGrid(
    model: v10,
    modelName,
    genModel: (const idGenGridModel *)&grid[1],
    state,
    material);
  return v10;
}


// ========================================================================
// __unwind$227858
// EA  : 0x825D5178
// RVA : 0x005D5178
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall _unwind_227858(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Contacts@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUcontactsResult_t@@ABVidVec3@@1MABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D51A0
// RVA : 0x005D51A0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::Contacts(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        contactsResult_t *a3,
        const idVec3 *start,
        const idVec3 *dir,
        double depth,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        const int a9,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        const idMat3 *a29,
        int a30,
        int a31,
        int a32,
        const idBounds *a33,
        int a34,
        int a35,
        int a36,
        int numTrms_0)
{
  __int64 numTrms; // r11
  int v44; // r25
  idTraceWork *v45; // r28
  const idMat3 **v46; // r24
  int *v47; // r31
  int i; // r19
  int v49; // r27
  const idTraceModel *v50; // r7
  int numContacts; // r14
  const idMat3 *v52; // [sp+8h] [-118h]
  int v53; // [sp+8h] [-118h]
  const idPositionedCollisionModel *v54; // [sp+Ch] [-114h]
  int v55; // [sp+10h] [-110h]
  const char *v56; // [sp+14h] [-10Ch]

  if ( a3 != nullptr )
  {
    v44 = 0;
    v45 = baseTraceWork;
    a3->numContacts = 0;
    if ( (int)a29 > 0 )
    {
      v46 = (const idMat3 **)HIDWORD(numTrms);
      do
      {
        if ( numTrms_0 > 0 )
        {
          v47 = (int *)(a35 + 64);
          for ( i = numTrms_0; i != 0; --i )
          {
            v49 = *(v47 - 16);
            if ( (*(int (__fastcall **)(int))(*(_DWORD *)v49 + 28))(a1: v49) != 0 )
            {
              (*(void (__fastcall **)(int))(*(_DWORD *)v49 + 28))(a1: v49);
            }
            else
            {
              numContacts = a3->numContacts;
              idPolygonModelCollisionDetection::StartContacts(
                tw: v45,
                result: a3,
                start,
                dir,
                depth,
                trm: v50,
                trmAxis: *v46,
                contentMask: a31,
                modelOrigin: a33->b,
                modelAxis: v52);
              idPolygonModelCollisionDetection::TraceThroughModel(tw: v45, model: (const cm_polygonModel_t *)(v49 + 84));
              idPolygonModelCollisionDetection::FinishContacts(
                tw: v45,
                firstContact: numContacts,
                modelOrigin: (const idVec3 *)(v47 - 14),
                modelAxis: (const idMat3 *)(v47 - 11),
                modelEntityNum: *(v47 - 2),
                modelPhysicsId: *(v47 - 1),
                modelBodyId: *v47,
                selfId: v44,
                modelContentsOverride: v53);
            }
            v47 += 20;
          }
        }
        ++v44;
        ++v46;
      }
      while ( v44 < (int)a29 );
    }
    LODWORD(numTrms) = 0;
    *(_QWORD *)this = numTrms;
    return this;
  }
  else
  {
    idCollisionQueryJobManager::SubmitContactsQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start,
      dir,
      depth,
      globalBounds: a33,
      trms,
      numTrms: SHIDWORD(numTrms),
      trmAxis: a29,
      contentMask: (int)v52,
      models: v54,
      numModels: v55,
      userName: v56);
    return this;
  }
}


// ========================================================================
// ?Clip@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUclipResult_t@@ABVidVec3@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D5340
// RVA : 0x005D5340
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::Clip(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        clipResult_t *a3,
        const idVec3 *start,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32)
{
  __int64 v32; // r18
  idTraceWork *v38; // r29
  const idTraceModel **v39; // r27
  int i; // r21
  int v41; // r31
  int j; // r23
  int v43; // r30
  const idPositionedCollisionModel *v44; // [sp+8h] [-E8h]
  int v45; // [sp+Ch] [-E4h]
  const char *v46; // [sp+10h] [-E0h]

  if ( a3 != nullptr )
  {
    LODWORD(v32) = 0;
    v38 = baseTraceWork;
    a3->numIndices = 0;
    a3->numVerts = 0;
    if ( numTrms > 0 )
    {
      v39 = trms;
      for ( i = numTrms; i != 0; --i )
      {
        if ( a32 > 0 )
        {
          v41 = a30 + 8;
          for ( j = a32; j != 0; --j )
          {
            v43 = *(_DWORD *)(v41 - 8);
            if ( (*(int (__fastcall **)(int))(*(_DWORD *)v43 + 28))(a1: v43) != 0 )
            {
              (*(void (__fastcall **)(int))(*(_DWORD *)v43 + 28))(a1: v43);
            }
            else
            {
              HIDWORD(v32) = a3->numVerts;
              idPolygonModelCollisionDetection::StartClip(
                tw: v38,
                result: a3,
                start,
                trm: *v39,
                trmAxis,
                contentMask: a28,
                modelOrigin: (const idVec3 *)v41,
                modelAxis: (const idMat3 *)(v41 + 12));
              idPolygonModelCollisionDetection::TraceThroughModel(
                tw: v38,
                model: (const cm_polygonModel_t *)(*(_DWORD *)(v41 - 8) + 84));
              idPolygonModelCollisionDetection::FinishClip(
                tw: v38,
                firstClipVert: SHIDWORD(v32),
                modelOrigin: (const idVec3 *)v41,
                modelAxis: (const idMat3 *)(v41 + 12));
            }
            v41 += 80;
          }
        }
        ++v39;
      }
    }
    *(_QWORD *)this = v32;
    return this;
  }
  else
  {
    idCollisionQueryJobManager::SubmitClipQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start,
      globalBounds,
      trms,
      numTrms,
      trmAxis,
      contentMask: a28,
      models: v44,
      numModels: v45,
      userName: v46);
    return this;
  }
}


// ========================================================================
// ListCollisionModels
// EA  : 0x825D54A0
// RVA : 0x005D54A0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void ListCollisionModels()
{
  int v0; // r26
  int v1; // r25
  int v2; // r24
  int v3; // r31
  int i; // r5
  idCollisionModelLocal *v5; // r22
  int TotalMemory; // r30
  int LoadedMemory; // r29
  int MaxResidentMemory; // r28

  v0 = 0;
  v1 = 0;
  v2 = 0;
  v3 = 0;
  for ( i = idCollisionModelLocal::resourceList.num; v3 < idCollisionModelLocal::resourceList.num; v2 += MaxResidentMemory )
  {
    v5 = (idCollisionModelLocal *)idResourceList::Index(this: &idCollisionModelLocal::resourceList, index: v3);
    TotalMemory = idCollisionModelLocal::GetTotalMemory(this: v5);
    LoadedMemory = idCollisionModelLocal::GetLoadedMemory(this: v5);
    MaxResidentMemory = idCollisionModelLocal::GetMaxResidentMemory(this: v5, location: nullptr);
    idLib::Printf(
      fmt: "%4d: %6d kB / %6d kB / %6d / %4d / %s\n",
      v3,
      TotalMemory >> 10,
      LoadedMemory >> 10,
      MaxResidentMemory >> 10,
      v5->polygonModel.numSubModels,
      v5->name.str);
    i = idCollisionModelLocal::resourceList.num;
    ++v3;
    v0 += TotalMemory;
    v1 += LoadedMemory;
  }
  idLib::Printf(fmt: "%d kB in %d models (%d kB loaded, %d kB max resident)\n", v0 >> 10, i, v1 >> 10, v2 >> 10);
}


// ========================================================================
// ListCollisionModels_f
// EA  : 0x825D5568
// RVA : 0x005D5568
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

// attributes: thunk
void __fastcall ListCollisionModels_f(const idCmdArgs *args)
{
  ListCollisionModels();
}


// ========================================================================
// ??0idCollisionGridState@@QAA@XZ
// EA  : 0x825D57E8
// RVA : 0x005D57E8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionGridState *__fastcall idCollisionGridState::idCollisionGridState(idCollisionGridState *this)
{
  this->numActive = 0;
  this->firstActive = -1;
  this->active.buffer = nullptr;
  this->active.bits = 0;
  this->active.memTag = 9;
  this->active.free = false;
  return this;
}


// ========================================================================
// ?Create@idCollisionGridState@@QAAXHPBVidMaterial@@@Z
// EA  : 0x825D5810
// RVA : 0x005D5810
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionGridState::Create(idCollisionGridState *this, int num, const idMaterial *material_)
{
  idBitArray *p_active; // r31
  unsigned int v7; // r9
  int i; // ctr
  unsigned __int8 *v9; // r11
  char v10; // r10
  char v11; // r8

  p_active = &this->active;
  idBitArray::Alloc(this: &this->active, numBits: num);
  v7 = 0;
  if ( num > 0 )
  {
    for ( i = num; i != 0; --i )
    {
      if ( v7 >= p_active->bits )
      {
        v9 = nullptr;
        v10 = 0;
        v11 = 0;
      }
      else
      {
        v9 = &p_active->buffer[v7 >> 3];
        v10 = 1 << (v7 & 7);
        v11 = 1;
      }
      if ( v11 != 0 )
        *v9 |= v10;
      ++v7;
    }
  }
  this->numActive = num;
  this->material = material_;
  this->firstActive = 0;
}


// ========================================================================
// ?Activate@idCollisionGridState@@QAAXH@Z
// EA  : 0x825D58C0
// RVA : 0x005D58C0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionGridState::Activate(idCollisionGridState *this, unsigned int id)
{
  idBitArray *p_active; // r7
  char v3; // r9
  unsigned __int8 *v4; // r11
  char v5; // r10
  char v6; // r8
  int firstActive; // r11
  unsigned __int8 *v9; // r11
  char v10; // r10

  p_active = &this->active;
  v3 = 1;
  if ( id >= this->active.bits )
  {
    v4 = nullptr;
    v5 = 0;
    v6 = 0;
  }
  else
  {
    v4 = &p_active->buffer[id >> 3];
    v5 = 1 << (id & 7);
    v6 = 1;
  }
  if ( v6 == 0 || (unsigned __int8)(*v4 & v5) == 0 )
  {
    firstActive = this->firstActive;
    if ( firstActive >= (int)id )
      firstActive = id;
    this->firstActive = firstActive;
    if ( id >= this->active.bits )
    {
      v9 = nullptr;
      v10 = 0;
      v3 = 0;
    }
    else
    {
      v9 = &p_active->buffer[id >> 3];
      v10 = 1 << (id & 7);
    }
    if ( v3 != 0 )
      *v9 |= v10;
    ++this->numActive;
  }
}


// ========================================================================
// ?NextActive@idCollisionGridState@@QBAHH@Z
// EA  : 0x825D59A8
// RVA : 0x005D59A8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

unsigned int __fastcall idCollisionGridState::NextActive(idCollisionGridState *this, int id)
{
  signed int bits; // r6
  unsigned int v3; // r9
  unsigned __int8 *v4; // r11
  char v5; // r10
  char v6; // r8

  bits = this->active.bits;
  v3 = id + 1;
  if ( id + 1 >= bits )
    return -1;
  while ( 1 )
  {
    if ( v3 >= bits )
    {
      v4 = nullptr;
      v5 = 0;
      v6 = 0;
    }
    else
    {
      v4 = &this->active.buffer[v3 >> 3];
      v5 = 1 << (v3 & 7);
      v6 = 1;
    }
    if ( v6 != 0 && (unsigned __int8)(*v4 & v5) != 0 )
      break;
    if ( (int)++v3 >= bits )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?Rotation@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUtrace_t@@ABVidVec3@@ABVidRotation@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D5A48
// RVA : 0x005D5A48
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::Rotation(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        trace_t *a3,
        const idMat3 *start,
        idRotation *rotation,
        const idBounds *globalBounds,
        const idMat3 **trms,
        int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idMat3 *a28,
        int a29,
        const idVec3 *a30,
        int a31,
        int a32,
        int a33,
        int a34)
{
  __int64 v40; // r9
  __int64 v41; // r11
  int v42; // r20
  idTraceWork *v43; // r27
  const idMat3 **v44; // r18
  int v45; // r31
  int i; // r19
  int v47; // r22
  const idVec3 *v48; // r7
  double angle; // fp1
  idVec3 *p_vec; // r6
  __int64 v51; // r8
  const idVec3 *v52; // [sp+8h] [-198h]
  const idMat3 *v53; // [sp+Ch] [-194h]
  int v54; // [sp+10h] [-190h]
  const char *v55; // [sp+14h] [-18Ch]
  trace_t v56[2]; // [sp+80h] [-120h] BYREF

  if ( a3 != nullptr )
  {
    if ( rotation->angle == 0.0
      || ((LODWORD(rotation->vec.z) | LODWORD(rotation->vec.y) | LODWORD(rotation->vec.x)) & 0x7FFFFFFF) == 0 )
    {
      a3->fraction = 1.0;
      a3->endpos = start->mat[0];
      a3->endAxis = *a28;
      memset(Dst: &a3->c, Val: 0, Size: sizeof(a3->c));
      LODWORD(v51) = 0;
      *(_QWORD *)this = v51;
      return this;
    }
    else if ( a34 > 0 )
    {
      HIDWORD(v41) = &idDeclReachIK::resourceList.hashTable[243];
      v42 = 0;
      v43 = baseTraceWork;
      a3->fraction = 2.0;
      if ( numTrms > 0 )
      {
        v44 = trms;
        do
        {
          v45 = a32 + 64;
          for ( i = a34; i != 0; --i )
          {
            v47 = *(_DWORD *)(v45 - 64);
            if ( (*(int (__fastcall **)(int))(*(_DWORD *)v47 + 28))(a1: v47) != 0 )
            {
              (*(void (__fastcall **)(int))(*(_DWORD *)v47 + 28))(a1: v47);
            }
            else
            {
              angle = rotation->angle;
              p_vec = &rotation->vec;
              if ( *v44 != nullptr )
                idPolygonModelCollisionDetection::StartRotation(
                  tw: v43,
                  result: v56,
                  rorg: &rotation->origin,
                  axis: p_vec,
                  angle,
                  start: v48,
                  trm: (const idTraceModel *)start,
                  trmAxis: *v44,
                  contentMask: (int)a28,
                  modelOrigin: v52,
                  modelAxis: v53);
              else
                idPolygonModelCollisionDetection::StartRotationPoint(
                  tw: v43,
                  result: v56,
                  rorg: &rotation->origin,
                  axis: p_vec,
                  angle,
                  start: v48,
                  contentMask: (int)start,
                  modelOrigin: a30,
                  modelAxis: (const idMat3 *)(v45 - 56));
              idPolygonModelCollisionDetection::TraceThroughModel(tw: v43, model: (const cm_polygonModel_t *)(v47 + 84));
              idPolygonModelCollisionDetection::FinishRotation(
                tw: v43,
                rorg: &rotation->origin,
                axis: &rotation->vec,
                angle: rotation->angle,
                start: *(const idVec3 **)(v45 + 4),
                trmAxis: start,
                modelOrigin: a28->mat,
                modelAxis: (const idMat3 *)(v45 - 56),
                modelEntityNum: v45 - 44,
                modelPhysicsId: (int)v52,
                modelBodyId: (int)v53,
                selfId: v54,
                modelContentsOverride: (int)v55);
              if ( v56[0].fraction < (double)a3->fraction )
                trace_t::operator=(this: a3, __that: v56);
            }
            v45 += 80;
          }
          ++v42;
          ++v44;
        }
        while ( v42 < numTrms );
      }
      LODWORD(v41) = 0;
      *(_QWORD *)this = v41;
      return this;
    }
    else
    {
      a3->fraction = 1.0;
      a3->endpos = start->mat[0];
      a3->endAxis = *a28;
      idRotation::RotatePoint(this: rotation, point: &a3->endpos);
      idRotation::RotateAxis(this: rotation, axis: &a3->endAxis);
      memset(Dst: &a3->c, Val: 0, Size: sizeof(a3->c));
      LODWORD(v40) = 0;
      *(_QWORD *)this = v40;
      return this;
    }
  }
  else
  {
    idCollisionQueryJobManager::SubmitRotationQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start: start->mat,
      rotation,
      globalBounds,
      (const idTraceModel **)trms,
      numTrms,
      trmAxis: a28,
      contentMask: (int)v52,
      models: (const idPositionedCollisionModel *)v53,
      numModels: v54,
      userName: v55);
    return this;
  }
}


// ========================================================================
// ?Contents@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUtrace_t@@ABVidVec3@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D5DC0
// RVA : 0x005D5DC0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::Contents(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        trace_t *a3,
        const idVec3 *start,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32)
{
  __int64 v38; // r11
  int v39; // r26
  int v40; // r25
  int v41; // r21
  idTraceWork *v42; // r28
  const idTraceModel **v43; // r18
  int *v44; // r31
  int i; // r19
  int v46; // r27
  const idPositionedCollisionModel *v47; // [sp+8h] [-188h]
  int v48; // [sp+Ch] [-184h]
  const char *v49; // [sp+10h] [-180h]
  trace_t v50; // [sp+70h] [-120h] BYREF

  if ( a3 != nullptr )
  {
    HIDWORD(v38) = 0x82000000;
    v39 = 0;
    v40 = 0;
    v41 = 0;
    v42 = baseTraceWork;
    a3->fraction = 1.0;
    if ( numTrms > 0 )
    {
      v43 = trms;
      do
      {
        if ( a32 > 0 )
        {
          v44 = (int *)(a30 + 64);
          for ( i = a32; i != 0; --i )
          {
            v46 = *(v44 - 16);
            if ( (*(int (__fastcall **)(int))(*(_DWORD *)v46 + 28))(a1: v46) != 0 )
            {
              (*(void (__fastcall **)(int))(*(_DWORD *)v46 + 28))(a1: v46);
            }
            else
            {
              if ( *v43 != nullptr )
                idPolygonModelCollisionDetection::StartContents(
                  tw: v42,
                  result: &v50,
                  start,
                  trm: *v43,
                  trmAxis,
                  contentMask: a28,
                  modelOrigin: (const idVec3 *)(v44 - 14),
                  modelAxis: (const idMat3 *)(v44 - 11));
              else
                idPolygonModelCollisionDetection::StartContentsPoint(
                  tw: v42,
                  result: &v50,
                  start,
                  contentMask: a28,
                  modelOrigin: (const idVec3 *)(v44 - 14),
                  modelAxis: (const idMat3 *)(v44 - 11));
              idPolygonModelCollisionDetection::TraceThroughModel(tw: v42, model: (const cm_polygonModel_t *)(v46 + 84));
              idPolygonModelCollisionDetection::FinishContents(
                tw: v42,
                modelOrigin: (const idVec3 *)(v44 - 14),
                modelAxis: (const idMat3 *)(v44 - 11),
                modelEntityNum: *(v44 - 2),
                modelPhysicsId: *(v44 - 1),
                modelId: *v44,
                selfId: v41,
                modelContentsOverride: v44[1]);
              v39 |= v50.c.contentFlags;
              v40 |= v50.c.surfaceFlags;
              if ( a3->fraction >= 1.0
                || (HIDWORD(v38) = a3->c.contentFlags, HIDWORD(v38) == 0) && v50.c.contentFlags != 0 )
              {
                trace_t::operator=(this: a3, __that: &v50);
              }
            }
            v44 += 20;
          }
        }
        ++v41;
        ++v43;
      }
      while ( v41 < numTrms );
    }
    LODWORD(v38) = 0;
    a3->c.contentFlags = v39;
    a3->c.surfaceFlags = v40;
    *(_QWORD *)this = v38;
    return this;
  }
  else
  {
    idCollisionQueryJobManager::SubmitContentsQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start,
      globalBounds,
      trms,
      numTrms,
      trmAxis,
      contentMask: a28,
      models: v47,
      numModels: v48,
      userName: v49);
    return this;
  }
}


// ========================================================================
// StepMoveInternal
// EA  : 0x825D5FB0
// RVA : 0x005D5FB0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall StepMoveInternal(
        trace_t *result,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *downNormal,
        double stepUp,
        double stepDown,
        const idTraceModel **trms,
        const int numTrms,
        const idTraceModel **trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        bool slideMove,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        const idMat3 *a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        bool trmAxis_0_3)
{
  float y; // r7
  float z; // r5
  int v48; // r26
  float x; // r4
  float v50; // r3
  float v51; // r11
  idTraceWork *v52; // r30
  const idTraceModel **v53; // r25
  int *v54; // r31
  int i; // r23
  int v56; // r27
  double fraction; // fp29
  double v58; // fp11
  double v59; // fp9
  double v60; // fp8
  int v61; // r25
  const idTraceModel **v62; // r26
  int *v63; // r31
  int j; // r23
  int v65; // r27
  double v66; // fp12
  int v67; // r25
  double v68; // fp11
  double v69; // fp10
  double v70; // fp9
  double v71; // fp8
  double v72; // fp4
  const idTraceModel **v73; // r26
  int *v74; // r31
  int k; // r23
  int v76; // r27
  int v77; // r25
  double v78; // fp11
  double v79; // fp9
  double v80; // fp8
  const idTraceModel **v81; // r26
  int *v82; // r31
  int m; // r23
  int v84; // r27
  const idVec3 *v85; // [sp+8h] [-3A8h]
  const idMat3 *v86; // [sp+Ch] [-3A4h]
  idVec3 v87; // [sp+60h] [-350h] BYREF
  idVec3 v88; // [sp+70h] [-340h] BYREF
  trace_t v89; // [sp+80h] [-330h] BYREF
  trace_t v90; // [sp+100h] [-2B0h] BYREF
  trace_t v91; // [sp+180h] [-230h] BYREF
  trace_t v92; // [sp+200h] [-1B0h] BYREF
  trace_t v93; // [sp+280h] [-130h] BYREF

  result->fraction = 1.0;
  result->endpos = *end;
  result->endAxis = *a30;
  memset(Dst: &result->c, Val: 0, Size: sizeof(result->c));
  y = start->y;
  z = start->z;
  v48 = 0;
  x = end->x;
  v50 = end->y;
  v51 = end->z;
  v52 = baseTraceWork;
  v87.x = start->x;
  v92.fraction = 2.0;
  v87.y = y;
  v87.z = z;
  v88.x = x;
  v88.y = v50;
  v88.z = v51;
  if ( contentMask > 0 )
  {
    v53 = trmAxis;
    do
    {
      if ( a36 > 0 )
      {
        v54 = (int *)(a34 + 64);
        for ( i = a36; i != 0; --i )
        {
          v56 = *(v54 - 16);
          if ( (*(int (__fastcall **)(int))(*(_DWORD *)v56 + 28))(a1: v56) != 0 )
          {
            (*(void (__fastcall **)(int))(*(_DWORD *)v56 + 28))(a1: v56);
          }
          else
          {
            if ( idPolygonModelCollisionDetection::StartTranslation(
                   tw: v52,
                   result: &v90,
                   contacts: nullptr,
                   start: &v87,
                   end: &v88,
                   trm: *v53,
                   trmAxis: a30,
                   contentMask: a32,
                   modelOrigin: v85,
                   modelAxis: v86) )
            {
              idPolygonModelCollisionDetection::TraceThroughModel(tw: v52, model: (const cm_polygonModel_t *)(v56 + 84));
              idPolygonModelCollisionDetection::FinishTranslation(
                tw: v52,
                start: &v87,
                end: &v88,
                modelOrigin: (const idVec3 *)(v54 - 14),
                modelAxis: (const idMat3 *)(v54 - 11),
                modelEntityNum: *(v54 - 2),
                modelPhysicsId: *(v54 - 1),
                modelBodyId: *v54,
                selfId: (int)v85,
                modelContentsOverride: (int)v86);
            }
            if ( v90.fraction < (double)v92.fraction )
              trace_t::operator=(this: &v92, __that: &v90);
          }
          v54 += 20;
        }
      }
      ++v48;
      ++v53;
    }
    while ( v48 < contentMask );
  }
  fraction = 2.0;
  v58 = (float)(downNormal->x * (float)stepUp);
  v59 = (float)(downNormal->y * (float)stepUp);
  v60 = (float)(downNormal->z * (float)stepUp);
  v61 = 0;
  v90.fraction = 2.0;
  v87.x = v92.endpos.x;
  v87.y = v92.endpos.y;
  v87.z = v92.endpos.z;
  v88.x = v92.endpos.x - (float)v58;
  v88.y = v92.endpos.y - (float)v59;
  v88.z = v92.endpos.z - (float)v60;
  if ( contentMask > 0 )
  {
    v62 = trmAxis;
    do
    {
      if ( a36 > 0 )
      {
        v63 = (int *)(a34 + 64);
        for ( j = a36; j != 0; --j )
        {
          v65 = *(v63 - 16);
          if ( (*(int (__fastcall **)(int))(*(_DWORD *)v65 + 28))(a1: v65) != 0 )
          {
            (*(void (__fastcall **)(int))(*(_DWORD *)v65 + 28))(a1: v65);
          }
          else
          {
            if ( idPolygonModelCollisionDetection::StartTranslation(
                   tw: v52,
                   result: &v89,
                   contacts: nullptr,
                   start: &v87,
                   end: &v88,
                   trm: *v62,
                   trmAxis: a30,
                   contentMask: a32,
                   modelOrigin: v85,
                   modelAxis: v86) )
            {
              idPolygonModelCollisionDetection::TraceThroughModel(tw: v52, model: (const cm_polygonModel_t *)(v65 + 84));
              idPolygonModelCollisionDetection::FinishTranslation(
                tw: v52,
                start: &v87,
                end: &v88,
                modelOrigin: (const idVec3 *)(v63 - 14),
                modelAxis: (const idMat3 *)(v63 - 11),
                modelEntityNum: *(v63 - 2),
                modelPhysicsId: *(v63 - 1),
                modelBodyId: *v63,
                selfId: (int)v85,
                modelContentsOverride: (int)v86);
            }
            if ( v89.fraction < fraction )
            {
              trace_t::operator=(this: &v90, __that: &v89);
              fraction = v90.fraction;
            }
          }
          v63 += 20;
        }
      }
      ++v61;
      ++v62;
    }
    while ( v61 < contentMask );
  }
  v66 = downNormal->y;
  v67 = 0;
  v68 = downNormal->z;
  v69 = end->x;
  v70 = end->y;
  v71 = end->z;
  v72 = (float)(downNormal->x * (float)((float)fraction * (float)stepUp));
  v87.x = v90.endpos.x;
  v87.y = v90.endpos.y;
  v87.z = v90.endpos.z;
  v91.fraction = 2.0;
  v88.x = (float)v69 - (float)v72;
  v88.z = (float)v71 - (float)((float)v68 * (float)((float)fraction * (float)stepUp));
  v88.y = (float)v70 - (float)((float)v66 * (float)((float)fraction * (float)stepUp));
  if ( contentMask > 0 )
  {
    v73 = trmAxis;
    do
    {
      if ( a36 > 0 )
      {
        v74 = (int *)(a34 + 64);
        for ( k = a36; k != 0; --k )
        {
          v76 = *(v74 - 16);
          if ( (*(int (__fastcall **)(int))(*(_DWORD *)v76 + 28))(a1: v76) != 0 )
          {
            (*(void (__fastcall **)(int))(*(_DWORD *)v76 + 28))(a1: v76);
          }
          else
          {
            if ( idPolygonModelCollisionDetection::StartTranslation(
                   tw: v52,
                   result: &v89,
                   contacts: nullptr,
                   start: &v87,
                   end: &v88,
                   trm: *v73,
                   trmAxis: a30,
                   contentMask: a32,
                   modelOrigin: v85,
                   modelAxis: v86) )
            {
              idPolygonModelCollisionDetection::TraceThroughModel(tw: v52, model: (const cm_polygonModel_t *)(v76 + 84));
              idPolygonModelCollisionDetection::FinishTranslation(
                tw: v52,
                start: &v87,
                end: &v88,
                modelOrigin: (const idVec3 *)(v74 - 14),
                modelAxis: (const idMat3 *)(v74 - 11),
                modelEntityNum: *(v74 - 2),
                modelPhysicsId: *(v74 - 1),
                modelBodyId: *v74,
                selfId: (int)v85,
                modelContentsOverride: (int)v86);
            }
            if ( v89.fraction < (double)v91.fraction )
              trace_t::operator=(this: &v91, __that: &v89);
          }
          v74 += 20;
        }
      }
      ++v67;
      ++v73;
    }
    while ( v67 < contentMask );
  }
  v77 = 0;
  v78 = (float)(downNormal->x * (float)stepDown);
  v79 = (float)(downNormal->y * (float)stepDown);
  v80 = (float)(downNormal->z * (float)stepDown);
  v87.x = v91.endpos.x;
  v87.y = v91.endpos.y;
  v87.z = v91.endpos.z;
  v93.fraction = 2.0;
  v88.x = (float)v78 + v91.endpos.x;
  v88.y = (float)v79 + v91.endpos.y;
  v88.z = (float)v80 + v91.endpos.z;
  if ( contentMask > 0 )
  {
    v81 = trmAxis;
    do
    {
      if ( a36 > 0 )
      {
        v82 = (int *)(a34 + 64);
        for ( m = a36; m != 0; --m )
        {
          v84 = *(v82 - 16);
          if ( (*(int (__fastcall **)(int))(*(_DWORD *)v84 + 28))(a1: v84) != 0 )
          {
            (*(void (__fastcall **)(int))(*(_DWORD *)v84 + 28))(a1: v84);
          }
          else
          {
            if ( idPolygonModelCollisionDetection::StartTranslation(
                   tw: v52,
                   result: &v89,
                   contacts: nullptr,
                   start: &v87,
                   end: &v88,
                   trm: *v81,
                   trmAxis: a30,
                   contentMask: a32,
                   modelOrigin: v85,
                   modelAxis: v86) )
            {
              idPolygonModelCollisionDetection::TraceThroughModel(tw: v52, model: (const cm_polygonModel_t *)(v84 + 84));
              idPolygonModelCollisionDetection::FinishTranslation(
                tw: v52,
                start: &v87,
                end: &v88,
                modelOrigin: (const idVec3 *)(v82 - 14),
                modelAxis: (const idMat3 *)(v82 - 11),
                modelEntityNum: *(v82 - 2),
                modelPhysicsId: *(v82 - 1),
                modelBodyId: *v82,
                selfId: (int)v85,
                modelContentsOverride: (int)v86);
            }
            if ( v89.fraction < (double)v93.fraction )
              trace_t::operator=(this: &v93, __that: &v89);
          }
          v82 += 20;
        }
      }
      ++v77;
      ++v81;
    }
    while ( v77 < contentMask );
  }
  idCollisionDetectionMerge::MergeStepMoveResults(
    result,
    down: &v93,
    forward2: &v91,
    forward1: &v92,
    slideMove: trmAxis_0_3);
}


// ========================================================================
// ?StepMove@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUtrace_t@@ABVidVec3@@11MMABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D6608
// RVA : 0x005D6608
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::StepMove(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        trace_t *a3,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *downNormal,
        double stepUp,
        double stepDown,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        const int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        const idTraceModel **a32,
        int a33,
        int a34,
        int a35,
        const idMat3 *a36,
        int a37,
        const idBounds *globalBounds_0,
        int a39,
        const idTraceModel **trms_0,
        int a41,
        int numTrmsa,
        int a43,
        const idTraceModel **trmAxisa)
{
  __int64 v44; // r30
  const idPositionedCollisionModel *v47; // [sp+8h] [-B8h]
  int v48; // [sp+Ch] [-B4h]
  const idPositionedCollisionModel *v49; // [sp+10h] [-B0h]
  int v50; // [sp+14h] [-ACh]
  const char *v51; // [sp+18h] [-A8h]
  int v52; // [sp+1Ch] [-A4h]
  int v53; // [sp+20h] [-A0h]
  int v54; // [sp+24h] [-9Ch]
  int v55; // [sp+28h] [-98h]
  int v56; // [sp+2Ch] [-94h]
  int v57; // [sp+30h] [-90h]
  int v58; // [sp+34h] [-8Ch]
  int v59; // [sp+38h] [-88h]
  int v60; // [sp+3Ch] [-84h]
  int v61; // [sp+40h] [-80h]
  int v62; // [sp+44h] [-7Ch]
  int v63; // [sp+48h] [-78h]
  int v64; // [sp+4Ch] [-74h]
  int v65; // [sp+50h] [-70h]
  int v66; // [sp+58h] [-68h]
  int v67; // [sp+60h] [-60h]
  int v68; // [sp+68h] [-58h]
  int v69; // [sp+70h] [-50h]

  if ( a3 != nullptr )
  {
    LODWORD(v44) = 0;
    StepMoveInternal(
      result: a3,
      start,
      end,
      downNormal,
      stepUp,
      stepDown,
      trms: trms_0,
      numTrms: numTrmsa,
      trmAxis: a32,
      contentMask: a34,
      models: v47,
      numModels: v48,
      slideMove: (bool)v49,
      a14: v50,
      a15: (int)v51,
      a16: v52,
      a17: v53,
      a18: v54,
      a19: v55,
      a20: v56,
      a21: v57,
      a22: v58,
      a23: v59,
      a24: v60,
      a25: v61,
      a26: v62,
      a27: v63,
      a28: v64,
      a29: v65,
      a30: a36,
      a31: v66,
      a32: (int)globalBounds_0,
      a33: v67,
      a34: (int)trms_0,
      a35: v68,
      a36: numTrmsa,
      a37: v69,
      trmAxis_0_3: false);
    *(_QWORD *)this = v44;
  }
  else
  {
    idCollisionQueryJobManager::SubmitStepMoveQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start,
      end,
      downNormal,
      stepUp,
      stepDown,
      globalBounds: globalBounds_0,
      trms: trmAxisa,
      numTrms: a30,
      trmAxis: (const idMat3 *)v47,
      contentMask: v48,
      models: v49,
      numModels: v50,
      userName: v51);
  }
  return this;
}


// ========================================================================
// ?StepMoveContacts@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUtrace_t@@PAUcontactsResult_t@@ABVidVec3@@22MMABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D66E0
// RVA : 0x005D66E0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::StepMoveContacts(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        trace_t *a3,
        contactsResult_t *contacts,
        idVec3 *start,
        const idVec3 *end,
        const idVec3 *downNormal,
        double stepUp,
        double stepDown,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        const int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        const idTraceModel **a32,
        int a33,
        const idTraceModel **a34,
        int a35,
        const idMat3 *a36,
        int a37,
        const idMat3 *a38,
        int a39,
        const idBounds *globalBounds_0,
        int a41,
        const idTraceModel **trmsa,
        int a43,
        int numTrmsa,
        int a45,
        const idTraceModel **trmAxisa)
{
  __int64 v50; // r29
  const idPositionedCollisionModel *v52; // [sp+8h] [-F8h]
  const idMat3 *v53; // [sp+8h] [-F8h]
  int v54; // [sp+Ch] [-F4h]
  int v55; // [sp+Ch] [-F4h]
  const idPositionedCollisionModel *v56; // [sp+10h] [-F0h]
  const idPositionedCollisionModel *v57; // [sp+10h] [-F0h]
  int v58; // [sp+14h] [-ECh]
  int v59; // [sp+14h] [-ECh]
  const char *v60; // [sp+18h] [-E8h]
  const char *v61; // [sp+18h] [-E8h]
  int v62; // [sp+1Ch] [-E4h]
  int v63; // [sp+1Ch] [-E4h]
  int v64; // [sp+20h] [-E0h]
  int v65; // [sp+20h] [-E0h]
  int v66; // [sp+24h] [-DCh]
  int v67; // [sp+24h] [-DCh]
  int v68; // [sp+28h] [-D8h]
  int v69; // [sp+28h] [-D8h]
  int v70; // [sp+2Ch] [-D4h]
  int v71; // [sp+2Ch] [-D4h]
  int v72; // [sp+30h] [-D0h]
  int v73; // [sp+30h] [-D0h]
  int v74; // [sp+34h] [-CCh]
  int v75; // [sp+34h] [-CCh]
  int v76; // [sp+38h] [-C8h]
  int v77; // [sp+38h] [-C8h]
  int v78; // [sp+3Ch] [-C4h]
  int v79; // [sp+3Ch] [-C4h]
  int v80; // [sp+40h] [-C0h]
  int v81; // [sp+40h] [-C0h]
  int v82; // [sp+44h] [-BCh]
  int v83; // [sp+44h] [-BCh]
  int v84; // [sp+48h] [-B8h]
  int v85; // [sp+48h] [-B8h]
  int v86; // [sp+4Ch] [-B4h]
  int v87; // [sp+4Ch] [-B4h]
  int v88; // [sp+50h] [-B0h]
  int v89; // [sp+50h] [-B0h]
  int v90; // [sp+58h] [-A8h]
  int v91; // [sp+58h] [-A8h]
  int v92; // [sp+60h] [-A0h]
  int v93; // [sp+60h] [-A0h]
  int v94; // [sp+68h] [-98h]
  int v95; // [sp+68h] [-98h]
  int v96; // [sp+70h] [-90h]
  int v97; // [sp+70h] [-90h]
  idCollisionModelManager v98; // [sp+90h] [-70h] BYREF

  HIDWORD(v50) = downNormal;
  if ( a3 != nullptr )
  {
    LODWORD(v50) = 0;
    StepMoveInternal(
      result: a3,
      start,
      end,
      downNormal,
      stepUp,
      stepDown,
      trms: (const idTraceModel **)start,
      numTrms: (const int)end,
      trmAxis: a34,
      contentMask: (int)a36,
      models: v52,
      numModels: v54,
      slideMove: (bool)v56,
      a14: v58,
      a15: (int)v60,
      a16: v62,
      a17: v64,
      a18: v66,
      a19: v68,
      a20: v70,
      a21: v72,
      a22: v74,
      a23: v76,
      a24: v78,
      a25: v80,
      a26: v82,
      a27: v84,
      a28: v86,
      a29: v88,
      a30: a38,
      a31: v90,
      a32: (int)globalBounds_0,
      a33: v92,
      a34: (int)trmsa,
      a35: v94,
      a36: numTrmsa,
      a37: v96,
      trmAxis_0_3: false);
    idCollisionModelManager::Contacts(
      this: &v98,
      result,
      a3: contacts,
      start: &a3->endpos,
      dir: (const idVec3 *)HIDWORD(v50),
      depth: 0.5,
      globalBounds: (const idBounds *)0x82000000,
      trms: a32,
      a9: (const int)a34,
      trmAxis: v53,
      contentMask: v55,
      models: v57,
      numModels: v59,
      userName: v61,
      a15: v63,
      a16: v65,
      a17: v67,
      a18: v69,
      a19: v71,
      a20: v73,
      a21: v75,
      a22: v77,
      a23: v79,
      a24: v81,
      a25: v83,
      a26: v85,
      a27: v87,
      a28: v89,
      a29: a36,
      a30: v91,
      a31: (int)&a3->endAxis,
      a32: v93,
      a33: globalBounds_0,
      a34: v95,
      a35: (int)trmsa,
      a36: v97,
      numTrms_0: numTrmsa);
    *(_QWORD *)this = v50;
  }
  else
  {
    idCollisionQueryJobManager::SubmitStepMoveContactsQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start,
      end,
      downNormal,
      stepUp,
      stepDown,
      globalBounds: (const idBounds *)a38,
      trms: trmAxisa,
      numTrms: (const int)a32,
      trmAxis: (const idMat3 *)v52,
      contentMask: v54,
      models: v56,
      numModels: v58,
      userName: v60);
  }
  return this;
}


// ========================================================================
// ?SlideMove@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUtrace_t@@ABVidVec3@@11MMABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D6810
// RVA : 0x005D6810
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::SlideMove(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        trace_t *a3,
        const idVec3 *start,
        const idVec3 *velocity,
        const idVec3 *gravityVector,
        double stepUp,
        double stepDown,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        const int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        const idTraceModel **a32,
        int a33,
        int a34,
        int a35,
        const idMat3 *a36,
        int a37,
        const idBounds *globalBounds_0,
        int a39,
        const idTraceModel **trms_0,
        int a41,
        const idTraceModel **numTrmsa)
{
  float y; // r8
  float x; // r7
  double v51; // fp8
  double v52; // fp7
  double z; // fp6
  float v54; // r5
  float v55; // r4
  float v56; // r3
  int v57; // r23
  double v60; // fp1
  double v61; // fp4
  double v62; // fp1
  double v63; // fp11
  double v64; // fp9
  double v65; // fp8
  double v66; // fp7
  double v67; // fp6
  double v68; // fp5
  __int64 v69; // r11
  const idPositionedCollisionModel *v70; // [sp+8h] [-1D8h]
  int v71; // [sp+Ch] [-1D4h]
  const idPositionedCollisionModel *v72; // [sp+10h] [-1D0h]
  int v73; // [sp+14h] [-1CCh]
  const char *v74; // [sp+18h] [-1C8h]
  int v75; // [sp+1Ch] [-1C4h]
  int v76; // [sp+20h] [-1C0h]
  int v77; // [sp+24h] [-1BCh]
  int v78; // [sp+28h] [-1B8h]
  int v79; // [sp+2Ch] [-1B4h]
  int v80; // [sp+30h] [-1B0h]
  int v81; // [sp+34h] [-1ACh]
  int v82; // [sp+38h] [-1A8h]
  int v83; // [sp+3Ch] [-1A4h]
  int v84; // [sp+40h] [-1A0h]
  int v85; // [sp+44h] [-19Ch]
  int v86; // [sp+48h] [-198h]
  int v87; // [sp+4Ch] [-194h]
  int v88; // [sp+50h] [-190h]
  int v89; // [sp+58h] [-188h]
  int v90; // [sp+60h] [-180h]
  int v91; // [sp+68h] [-178h]
  int v92; // [sp+70h] [-170h]
  idVec3 v93; // [sp+90h] [-150h] BYREF
  idVec3 v94; // [sp+A0h] [-140h] BYREF
  idVec3 v95; // [sp+B0h] [-130h] BYREF
  slideMoveState_t v96; // [sp+C0h] [-120h] BYREF

  if ( a3 != nullptr )
  {
    idCollisionDetectionMerge::InitSlideMoveState(state: &v96, velocity, gravityVector);
    v93.z = gravityVector->z;
    y = gravityVector->y;
    v51 = (float)(start->x + v96.velocity.x);
    v52 = (float)(start->y + v96.velocity.y);
    z = start->z;
    v93.x = gravityVector->x;
    x = v93.x;
    v93.y = y;
    v95.x = v51;
    v54 = start->x;
    v95.y = v52;
    v55 = start->y;
    v95.z = (float)z + v96.velocity.z;
    v56 = start->z;
    v57 = 0;
    v94.x = v54;
    v94.y = v55;
    v94.z = v56;
    _FP4 = (float)((float)((float)(x * x) + (float)((float)(v93.y * v93.y) + (float)(v93.z * v93.z)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f5, f13 }
    v60 = __frsqrte(_FP2);
    v61 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60
                                                                                        * (float)((float)((float)(x * x) + (float)((float)(v93.y * v93.y) + (float)(v93.z * v93.z)))
                                                                                                * (float)0.5))
                                                                                * (float)v60)
                                                                        - (float)1.5)
                                                        * (float)v60)
                                                * (float)((float)((float)(x * x)
                                                                + (float)((float)(v93.y * v93.y) + (float)(v93.z * v93.z)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v60
                                                                                * (float)((float)((float)(x * x)
                                                                                                + (float)((float)(v93.y * v93.y) + (float)(v93.z * v93.z)))
                                                                                        * (float)0.5))
                                                                        * (float)v60)
                                                                - (float)1.5)
                                                * (float)v60))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v60
                                                        * (float)((float)((float)(x * x)
                                                                        + (float)((float)(v93.y * v93.y)
                                                                                + (float)(v93.z * v93.z)))
                                                                * (float)0.5))
                                                * (float)v60)
                                        - (float)1.5)
                        * (float)v60));
    v62 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)(x * x) + (float)((float)(v93.y * v93.y) + (float)(v93.z * v93.z))) * (float)0.5)) * (float)v60) - (float)1.5)
                                                                                                * (float)v60)
                                                                                        * (float)((float)((float)(x * x) + (float)((float)(v93.y * v93.y) + (float)(v93.z * v93.z)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)(x * x) + (float)((float)(v93.y * v93.y) + (float)(v93.z * v93.z))) * (float)0.5)) * (float)v60) - (float)1.5)
                                                                                        * (float)v60))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v60
                                                                                                * (float)((float)((float)(x * x) + (float)((float)(v93.y * v93.y) + (float)(v93.z * v93.z))) * (float)0.5))
                                                                                        * (float)v60)
                                                                                - (float)1.5)
                                                                * (float)v60))
                                                * (float)((float)((float)(x * x)
                                                                + (float)((float)(v93.y * v93.y) + (float)(v93.z * v93.z)))
                                                        * (float)0.5))
                                        * (float)v61)
                                - (float)1.5)
                * (float)v61);
    v93.x = v93.x * (float)v62;
    v93.y = y * (float)v62;
    v93.z = v93.z * (float)v62;
    do
    {
      StepMoveInternal(
        result: a3,
        start: &v94,
        end: &v95,
        downNormal: &v93,
        stepUp,
        stepDown,
        trms: (const idTraceModel **)LODWORD(x),
        numTrms: SLODWORD(y),
        trmAxis: a32,
        contentMask: a34,
        models: v70,
        numModels: v71,
        slideMove: (bool)v72,
        a14: v73,
        a15: (int)v74,
        a16: v75,
        a17: v76,
        a18: v77,
        a19: v78,
        a20: v79,
        a21: v80,
        a22: v81,
        a23: v82,
        a24: v83,
        a25: v84,
        a26: v85,
        a27: v86,
        a28: v87,
        a29: v88,
        a30: a36,
        a31: v89,
        a32: (int)globalBounds_0,
        a33: v90,
        a34: (int)trms_0,
        a35: v91,
        a36: (int)numTrmsa,
        a37: v92,
        trmAxis_0_3: true);
      if ( idCollisionDetectionMerge::UpdateSlideMoveState(state: &v96, trace: a3) )
        break;
      ++v57;
      v63 = (float)(a3->c.normal.x * a3->c.dist);
      v64 = (float)(a3->c.normal.y * a3->c.dist);
      v65 = (float)(a3->c.normal.z * a3->c.dist);
      v66 = a3->endpos.x;
      v67 = a3->endpos.y;
      v68 = a3->endpos.z;
      v94.y = a3->endpos.y;
      v94.x = v66;
      v94.z = v68;
      v95.x = (float)v66 + (float)v63;
      v95.y = (float)v67 + (float)v64;
      v95.z = (float)v68 + (float)v65;
    }
    while ( v57 < 4 );
    idCollisionDetectionMerge::FinishSlideMoveState(state: &v96, trace: a3);
    LODWORD(v69) = 0;
    *(_QWORD *)this = v69;
    return this;
  }
  else
  {
    idCollisionQueryJobManager::SubmitSlideMoveQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start,
      velocity,
      gravityVector,
      stepUp,
      stepDown,
      globalBounds: (const idBounds *)trms_0,
      trms: numTrmsa,
      numTrms: a30,
      trmAxis: (const idMat3 *)v70,
      contentMask: v71,
      models: v72,
      numModels: v73,
      userName: v74);
    return this;
  }
}


// ========================================================================
// ?SlideMoveContacts@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUtrace_t@@PAUcontactsResult_t@@ABVidVec3@@22MMABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D6A90
// RVA : 0x005D6A90
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::SlideMoveContacts(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        trace_t *a3,
        contactsResult_t *contacts,
        const idVec3 *start,
        const idVec3 *velocity,
        const idBounds *gravityVector,
        double stepUp,
        double stepDown,
        const idTraceModel **globalBounds,
        const idTraceModel **trms,
        const int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        const idTraceModel **a32,
        int a33,
        const idTraceModel **a34,
        int a35,
        const idMat3 *a36,
        int a37,
        const idMat3 *a38,
        int a39,
        const idBounds *globalBounds_0,
        int a41,
        const idTraceModel **trmsa,
        int a43,
        const idTraceModel **numTrmsa)
{
  float z; // r11
  float y; // r8
  float x; // r31
  double v55; // fp3
  double v56; // fp4
  double v57; // fp3
  __int64 v58; // r7
  const idMat3 *v59; // [sp+8h] [-118h]
  const idMat3 *v60; // [sp+8h] [-118h]
  const idMat3 *v61; // [sp+Ch] [-114h]
  int v62; // [sp+Ch] [-114h]
  const idPositionedCollisionModel *v63; // [sp+10h] [-110h]
  const idPositionedCollisionModel *v64; // [sp+10h] [-110h]
  const idPositionedCollisionModel *v65; // [sp+14h] [-10Ch]
  int v66; // [sp+14h] [-10Ch]
  const char *v67; // [sp+18h] [-108h]
  const char *v68; // [sp+18h] [-108h]
  const char *v69; // [sp+1Ch] [-104h]
  int v70; // [sp+1Ch] [-104h]
  int v71; // [sp+20h] [-100h]
  int v72; // [sp+20h] [-100h]
  int v73; // [sp+24h] [-FCh]
  int v74; // [sp+24h] [-FCh]
  int v75; // [sp+28h] [-F8h]
  int v76; // [sp+28h] [-F8h]
  int v77; // [sp+2Ch] [-F4h]
  int v78; // [sp+2Ch] [-F4h]
  int v79; // [sp+30h] [-F0h]
  int v80; // [sp+30h] [-F0h]
  int v81; // [sp+34h] [-ECh]
  int v82; // [sp+34h] [-ECh]
  int v83; // [sp+38h] [-E8h]
  int v84; // [sp+38h] [-E8h]
  int v85; // [sp+3Ch] [-E4h]
  int v86; // [sp+3Ch] [-E4h]
  int v87; // [sp+40h] [-E0h]
  int v88; // [sp+40h] [-E0h]
  int v89; // [sp+44h] [-DCh]
  int v90; // [sp+44h] [-DCh]
  int v91; // [sp+48h] [-D8h]
  int v92; // [sp+48h] [-D8h]
  int v93; // [sp+4Ch] [-D4h]
  int v94; // [sp+4Ch] [-D4h]
  int v95; // [sp+50h] [-D0h]
  int v96; // [sp+50h] [-D0h]
  int v97; // [sp+58h] [-C8h]
  int v98; // [sp+58h] [-C8h]
  int v99; // [sp+60h] [-C0h]
  int v100; // [sp+60h] [-C0h]
  int v101; // [sp+68h] [-B8h]
  int v102; // [sp+68h] [-B8h]
  int v103; // [sp+70h] [-B0h]
  int v104; // [sp+70h] [-B0h]
  int v105; // [sp+78h] [-A8h]
  int v106; // [sp+80h] [-A0h]
  idCollisionModelManager v107[8]; // [sp+90h] [-90h] BYREF
  idVec3 v108; // [sp+98h] [-88h] BYREF

  if ( a3 != nullptr )
  {
    idCollisionModelManager::SlideMove(
      this: v107,
      result,
      a3,
      start,
      velocity,
      gravityVector: gravityVector->b,
      stepUp,
      stepDown,
      globalBounds: gravityVector,
      trms: globalBounds,
      numTrms: (const int)v59,
      trmAxis: v61,
      contentMask: (const int)v63,
      models: v65,
      numModels: (const int)v67,
      userName: v69,
      a17: v71,
      a18: v73,
      a19: v75,
      a20: v77,
      a21: v79,
      a22: v81,
      a23: v83,
      a24: v85,
      a25: v87,
      a26: v89,
      a27: v91,
      a28: v93,
      a29: v95,
      a30: (int)a32,
      a31: v97,
      a32: a34,
      a33: v99,
      a34: (int)a36,
      a35: v101,
      a36: a38,
      a37: v103,
      globalBounds_0,
      a39: v105,
      trms_0: trmsa,
      a41: v106,
      numTrmsa);
    z = gravityVector->b[0].z;
    y = gravityVector->b[0].y;
    x = gravityVector->b[0].x;
    _FP6 = (float)((float)((float)(y * y) + (float)((float)(z * z) + (float)(x * x))) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f13 }
    v55 = __frsqrte(_FP4);
    v56 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55
                                                                                        * (float)((float)((float)(y * y) + (float)((float)(z * z) + (float)(x * x)))
                                                                                                * (float)0.5))
                                                                                * (float)v55)
                                                                        - (float)1.5)
                                                        * (float)v55)
                                                * (float)((float)((float)(y * y)
                                                                + (float)((float)(z * z) + (float)(x * x)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v55
                                                                                * (float)((float)((float)(y * y)
                                                                                                + (float)((float)(z * z) + (float)(x * x)))
                                                                                        * (float)0.5))
                                                                        * (float)v55)
                                                                - (float)1.5)
                                                * (float)v55))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v55
                                                        * (float)((float)((float)(y * y)
                                                                        + (float)((float)(z * z) + (float)(x * x)))
                                                                * (float)0.5))
                                                * (float)v55)
                                        - (float)1.5)
                        * (float)v55));
    v57 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55
                                                                                                * (float)((float)((float)(y * y) + (float)((float)(z * z) + (float)(x * x))) * (float)0.5))
                                                                                        * (float)v55)
                                                                                - (float)1.5)
                                                                * (float)v55)
                                                        * (float)((float)((float)(y * y)
                                                                        + (float)((float)(z * z) + (float)(x * x)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v55
                                                                                        * (float)((float)((float)(y * y) + (float)((float)(z * z) + (float)(x * x)))
                                                                                                * (float)0.5))
                                                                                * (float)v55)
                                                                        - (float)1.5)
                                                        * (float)v55))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v55
                                                                * (float)((float)((float)(y * y)
                                                                                + (float)((float)(z * z) + (float)(x * x)))
                                                                        * (float)0.5))
                                                        * (float)v55)
                                                - (float)1.5)
                                * (float)v55))
                * (float)((float)((float)(y * y) + (float)((float)(z * z) + (float)(x * x))) * (float)0.5));
    v108.x = x * (float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5) * (float)v56);
    v108.y = (float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5) * (float)v56) * y;
    v108.z = z * (float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5) * (float)v56);
    idCollisionModelManager::Contacts(
      this: v107,
      result,
      a3: contacts,
      start: &a3->endpos,
      dir: &v108,
      depth: 0.5,
      globalBounds: (const idBounds *)LODWORD(y),
      trms: a32,
      a9: (const int)a34,
      trmAxis: v60,
      contentMask: v62,
      models: v64,
      numModels: v66,
      userName: v68,
      a15: v70,
      a16: v72,
      a17: v74,
      a18: v76,
      a19: v78,
      a20: v80,
      a21: v82,
      a22: v84,
      a23: v86,
      a24: v88,
      a25: v90,
      a26: v92,
      a27: v94,
      a28: v96,
      a29: a36,
      a30: v98,
      a31: (int)a38,
      a32: v100,
      a33: globalBounds_0,
      a34: v102,
      a35: (int)trmsa,
      a36: v104,
      numTrms_0: (int)numTrmsa);
    LODWORD(v58) = 0;
    *(_QWORD *)this = v58;
  }
  else
  {
    idCollisionQueryJobManager::SubmitSlideMoveContactsQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start,
      velocity,
      gravityVector: gravityVector->b,
      stepUp,
      stepDown,
      globalBounds: (const idBounds *)trmsa,
      trms: numTrmsa,
      numTrms: (const int)a32,
      trmAxis: v59,
      contentMask: (const int)v61,
      models: v63,
      numModels: (const int)v65,
      userName: v67);
  }
  return this;
}


// ========================================================================
// BuildCollisionModelsForMap_f
// EA  : 0x825D6C60
// RVA : 0x005D6C60
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall BuildCollisionModelsForMap_f(const idCmdArgs *args)
{
  idStr *v2; // r29
  size_t len; // r30
  bool v4; // r30
  char *v5; // r3
  int v6; // r28
  int v7; // r3
  idStr v8; // [sp+60h] [-230h] BYREF
  idStr v9; // [sp+80h] [-210h] BYREF
  idStr v10; // [sp+A0h] [-1F0h] BYREF
  idDeclEntityDef v11[2]; // [sp+C0h] [-1D0h] BYREF

  if ( args->argc > 1 )
  {
    idStr::idStr(this: &v8, text: args->argv[1]);
    idStr::BackSlashesToSlashes(this: &v8);
    if ( idStr::Icmpn(s1: v8.data, s2: "maps/", n: 5) != 0 )
    {
      v2 = operator+(result: &v10, a: "maps/", b: &v8);
      len = v2->len;
      idStr::EnsureAlloced(this: &v8, amount: v2->len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v8.data, Src: v2->data, Size: len);
      v8.data[len] = 0;
      v8.len = len;
      idStr::FreeData(this: &v10);
    }
    idMapFile::idMapFile(this: (idMapFile *)v11);
    v11[0].editorVars.animFrame = (int)common->Game(this: common);
    if ( idMapFile::Parse(this: (idMapFile *)v11, filename: v8.data, osPath: false, parent: nullptr) )
    {
      v4 = false;
      if ( args->argc > 2 )
      {
        v5 = args->argv[2];
        if ( *v5 == 45 )
          ++v5;
        if ( idStr::Icmp(s1: v5, s2: "entityOnly") == 0 )
          v4 = true;
      }
      ++idResourceList::staleCount;
      common->SetRefreshOnPrint(this: common, a2: true);
      if ( !v4 )
        idCollisionModelManager::BuildModelsForMapFile(
          this: &collisionModelManagerLocal,
          mapFile: v11,
          mapModelOnly: v4);
      v6 = Sys_Milliseconds();
      idCollisionModelBuilder::BuildForMapFile(mapFile: v11, inlineStatic: true, mapModelOnly: v4);
      v7 = Sys_Milliseconds();
      idLib::Printf(fmt: "%d seconds to build collision data.\n", (v7 - v6) / 1000);
      common->SetRefreshOnPrint(this: common, a2: false);
      idStr::idStr(this: &v9, text: &v8);
      idStr::SetFileExtension(this: &v9, extension: "map");
      fileSystem->RelativePathToOSPath_2(
        this: fileSystem,
        a2: v9.data,
        a3: (char *)&v11[0].expandInheritance,
        a4: 256,
        a5: FSPATH_BASE);
      idZipBuilder::UpdateMapFolderZip(mapFileName: (const char *)&v11[0].expandInheritance);
      idStr::FreeData(this: &v9);
      idMapFile::~idMapFile(this: (idMapFile *)v11);
    }
    else
    {
      idMapFile::~idMapFile(this: (idMapFile *)v11);
    }
    idStr::FreeData(this: &v8);
  }
  else
  {
    idLib::Printf(fmt: "bcm <map> [-entityOnly]\n");
  }
}


// ========================================================================
// __unwind$228941
// EA  : 0x825D6EC4
// RVA : 0x005D6EC4
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_228941()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 96));
}


// ========================================================================
// __unwind$228942
// EA  : 0x825D6EEC
// RVA : 0x005D6EEC
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_228942()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 160));
}


// ========================================================================
// __unwind$228943
// EA  : 0x825D6F14
// RVA : 0x005D6F14
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_228943()
{
  int v0; // r12

  idMapFile::~idMapFile(this: (idMapFile *)(v0 - 656 + 192));
}


// ========================================================================
// __unwind$228944
// EA  : 0x825D6F3C
// RVA : 0x005D6F3C
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_228944()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 128));
}


// ========================================================================
// StripBCM_f
// EA  : 0x825D6F70
// RVA : 0x005D6F70
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall StripBCM_f(const idCmdArgs *args)
{
  int argc; // r10
  const char *v3; // r4
  __int64 v4; // r10
  __int64 v5; // r6
  int v6; // r7
  idStr *MapModelName; // r3
  idCollisionModelLocal *v8; // r23
  signed int numSubModels; // r30
  signed int v10; // r7
  float *p_bounds; // r10
  int v12; // r8
  float *v13; // r11
  char v14; // r9
  int v15; // r29
  int v16; // r30
  __int64 v17; // [sp+8h] [-4138h]
  float v18[18]; // [sp+58h] [-40E8h] BYREF
  idStr v19; // [sp+A0h] [-40A0h] BYREF
  idStr v20; // [sp+C0h] [-4080h] BYREF
  _BYTE v21[96]; // [sp+E0h] [-4060h] BYREF

  argc = args->argc;
  v18[0] = -1792.0;
  v18[1] = -8056.0;
  v18[2] = 22264.0;
  v18[3] = 1936.0;
  v18[4] = -29392.0;
  v18[5] = -6672.0;
  v18[6] = -1792.0;
  v18[7] = -25584.0;
  v18[8] = 520.0;
  v18[9] = 1536.0;
  v18[10] = -26784.0;
  v18[11] = -9208.0;
  v18[12] = -1792.0;
  v18[13] = -20528.0;
  v18[14] = 8216.0;
  v18[15] = 1536.0;
  if ( argc > 1 )
  {
    idStr::idStr(this: &v19, text: "maps/");
    if ( args->argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    idStr::AppendPath(this: &v19, text: v3);
    idStr::AppendPath(this: &v19, text: "_combo");
    LODWORD(v4) = "-------- FX_SOUND specific parms ------------------------ FX_SOUND parms";
    HIDWORD(v5) = "world";
    MapModelName = idMapFile::GetMapModelName(result: &v20, entityName: v5, a3: v6, a4: v4, a5: v17);
    v8 = (idCollisionModelLocal *)idResourceList::Load(
                                    this: &idCollisionModelLocal::resourceList,
                                    name: MapModelName->data,
                                    makeDefault: true,
                                    skipStaleCheck: false);
    idStr::FreeData(this: &v20);
    numSubModels = v8->polygonModel.numSubModels;
    memset(Dst: v21, Val: 0, Size: numSubModels);
    v10 = 0;
    if ( numSubModels > 0 )
    {
      p_bounds = (float *)&v8->polygonModel.subModels->header.bounds;
      do
      {
        v12 = 0;
        v13 = v18;
        while ( 1 )
        {
          if ( p_bounds[3] < (double)*(v13 - 2)
            || p_bounds[4] < (double)*(v13 - 1)
            || p_bounds[5] < (double)*v13
            || *p_bounds > (double)v13[1]
            || p_bounds[1] > (double)v13[2]
            || (v14 = 1, p_bounds[2] > (double)v13[3]) )
          {
            v14 = 0;
          }
          if ( v14 != 0 )
            break;
          ++v12;
          v13 += 6;
          if ( v12 >= 1 )
            goto LABEL_20;
        }
        v21[v10] = 1;
LABEL_20:
        ++v10;
        p_bounds += 12;
      }
      while ( v10 < numSubModels );
    }
    v15 = 0;
    if ( numSubModels > 0 )
    {
      v16 = 0;
      do
      {
        if ( v21[v15] == 0 )
        {
          idMem::Free(this: &mem, ptr: v8->polygonModel.subModels[v16].data, align: ALIGN_16);
          v8->polygonModel.subModels[v16].data = nullptr;
          v8->polygonModel.subModelState[v15] = -1;
          v8->polygonModel.subModels[v16].header.totalSize = 32;
          v8->polygonModel.subModels[v16].header.loadedSize = 32;
        }
        ++v15;
        ++v16;
      }
      while ( v15 < v8->polygonModel.numSubModels );
    }
    idCollisionModelLocal::Write_Binary(this: v8);
    idStr::FreeData(this: &v19);
  }
  else
  {
    idLib::Printf(fmt: "stripbcm <map>\n");
  }
}


// ========================================================================
// __unwind$229069
// EA  : 0x825D7270
// RVA : 0x005D7270
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_229069()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16704 + 160));
}


// ========================================================================
// __unwind$229070
// EA  : 0x825D7298
// RVA : 0x005D7298
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_229070()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16704 + 192));
}


// ========================================================================
// ?Inactivate@idCollisionGridState@@QAAXH@Z
// EA  : 0x825D78B8
// RVA : 0x005D78B8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionGridState::Inactivate(idCollisionGridState *this, unsigned int id)
{
  unsigned int bits; // r7
  char v3; // r9
  unsigned __int8 *v4; // r11
  char v5; // r10
  char v6; // r8
  unsigned __int8 *v8; // r11
  char v9; // r10
  int v10; // r11

  bits = this->active.bits;
  v3 = 1;
  if ( id >= bits )
  {
    v4 = nullptr;
    v5 = 0;
    v6 = 0;
  }
  else
  {
    v4 = &this->active.buffer[id >> 3];
    v5 = 1 << (id & 7);
    v6 = 1;
  }
  if ( v6 != 0 && (unsigned __int8)(*v4 & v5) != 0 )
  {
    if ( id >= bits )
    {
      v8 = nullptr;
      v9 = 0;
      v3 = 0;
    }
    else
    {
      v8 = &this->active.buffer[id >> 3];
      v9 = 1 << (id & 7);
    }
    if ( v3 != 0 )
      *v8 &= ~v9;
    v10 = this->numActive - 1;
    this->numActive = v10;
    if ( v10 != 0 )
    {
      if ( this->firstActive == id )
        this->firstActive = idCollisionGridState::NextActive(this, id);
    }
    else
    {
      this->firstActive = -1;
    }
  }
}


// ========================================================================
// ?EndQueryFrame@idCollisionModelManager@@QAAXXZ
// EA  : 0x825D79E0
// RVA : 0x005D79E0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionModelManager::EndQueryFrame(idCollisionModelManager *this)
{
  idQueryData::EndFrame(this: cdQuery.queryData);
}


// ========================================================================
// ?Translation@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUtrace_t@@ABVidVec3@@1ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D79F0
// RVA : 0x005D79F0
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::Translation(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        trace_t *a3,
        const idVec3 *start,
        const idVec3 *end,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idMat3 *a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34)
{
  __int64 v34; // r17
  char v41; // r11
  idTraceWork *v42; // r26
  double v43; // fp9
  double v44; // fp6
  idRenderWorld *v45; // r3
  int v46; // r23
  const idTraceModel **v47; // r19
  int *v48; // r31
  int v49; // r20
  int v50; // r25
  double radius; // fp1
  const idVec3 *v52; // [sp+8h] [-1A8h]
  const idPositionedCollisionModel *v53; // [sp+Ch] [-1A4h]
  int v54; // [sp+10h] [-1A0h]
  const char *v55; // [sp+14h] [-19Ch]
  int v56; // [sp+18h] [-198h]
  trace_t v57; // [sp+90h] [-120h] BYREF

  if ( a3 == nullptr )
  {
    idCollisionQueryJobManager::SubmitTranslationQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start,
      end,
      globalBounds,
      trms,
      numTrms,
      trmAxis: a28,
      contentMask: (int)v52,
      models: v53,
      numModels: v54,
      userName: v55);
    return this;
  }
  LODWORD(v34) = 0;
  if ( start->x != end->x || start->y != end->y || (v41 = 1, start->z != end->z) )
    v41 = 0;
  if ( v41 != 0 || (HIDWORD(v34) = a34, a34 == 0) )
  {
    a3->fraction = 1.0;
    a3->endpos = *end;
    a3->endAxis = *a28;
    memset(Dst: &a3->c, Val: 0, Size: sizeof(a3->c));
    goto LABEL_34;
  }
  v42 = baseTraceWork;
  if ( *trms == nullptr
    || (v43 = (float)(end->y - start->y),
        v44 = (float)(end->z - start->z),
        (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
              + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43))) <= 16777216.0) )
  {
    v46 = 0;
    a3->fraction = 2.0;
    if ( numTrms > 0 )
    {
      v47 = trms;
      while ( a34 <= 0 )
      {
LABEL_31:
        ++v46;
        ++v47;
        if ( v46 >= numTrms )
        {
          *(_QWORD *)this = v34;
          return this;
        }
      }
      v48 = (int *)(a32 + 64);
      v49 = a34;
      while ( 1 )
      {
        v50 = *(v48 - 16);
        if ( (*(int (__fastcall **)(int))(*(_DWORD *)v50 + 28))(a1: v50) == 0 )
          break;
        if ( (*(int (__fastcall **)(int))(*(_DWORD *)v50 + 28))(a1: v50) == 1 )
        {
          if ( *v47 != nullptr )
            radius = (*v47)->radius;
          else
            radius = 0.0;
          idSphereModelCollisionDetection::TraceThroughModel(
            trace: &v57,
            csData: *(const cm_sphereModel_t **)(v50 + 104),
            start,
            end,
            radius,
            trmAxis: (const idMat3 *)(v48 - 11),
            modelJoints: (const idJointMat *)a28,
            modelOrigin: (const idVec3 *)*(v48 - 15),
            modelAxis: (const idMat3 *)(v48 - 14),
            modelEntityNum: (int)v52,
            modelPhysicsId: (int)v53,
            modelBodyId: v54,
            selfId: (int)v55,
            modelContentsOverride: v56);
LABEL_28:
          if ( v57.fraction < (double)a3->fraction )
            trace_t::operator=(this: a3, __that: &v57);
        }
        --v49;
        v48 += 20;
        if ( v49 == 0 )
          goto LABEL_31;
      }
      if ( *v47 != nullptr )
        idPolygonModelCollisionDetection::StartTranslation(
          tw: v42,
          result: &v57,
          contacts: nullptr,
          start,
          end,
          trm: *v47,
          trmAxis: a28,
          contentMask: a30,
          modelOrigin: v52,
          modelAxis: (const idMat3 *)v53);
      else
        idPolygonModelCollisionDetection::StartTranslationPoint(
          tw: v42,
          result: &v57,
          start,
          end,
          contentMask: a30,
          modelOrigin: (const idVec3 *)(v48 - 14),
          modelAxis: (const idMat3 *)(v48 - 11));
      idPolygonModelCollisionDetection::TraceThroughModel(tw: v42, model: (const cm_polygonModel_t *)(v50 + 84));
      idPolygonModelCollisionDetection::FinishTranslation(
        tw: v42,
        start,
        end,
        modelOrigin: (const idVec3 *)(v48 - 14),
        modelAxis: (const idMat3 *)(v48 - 11),
        modelEntityNum: *(v48 - 2),
        modelPhysicsId: *(v48 - 1),
        modelBodyId: *v48,
        selfId: (int)v52,
        modelContentsOverride: (int)v53);
      goto LABEL_28;
    }
LABEL_34:
    *(_QWORD *)this = v34;
    return this;
  }
  a3->fraction = 0.0;
  a3->endpos = *start;
  a3->endAxis = *a28;
  a3->c.normal = vec3_origin;
  a3->c.point = *start;
  a3->c.entityNum = 0;
  a3->c.bodyId = 0;
  a3->c.selfId = 0;
  if ( common->RW(this: common) != nullptr )
  {
    v45 = common->RW(this: common);
    ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, const idVec3 *, double))v45->DebugArrow)(
      a1: v45,
      a2: &idColor::colorRed,
      a3: start,
      a4: end,
      a5: 1.0);
  }
  idLib::Printf(fmt: "idPolygonModelCollisionDetection::Translation: huge translation\n");
  *(_QWORD *)this = v34;
  return this;
}


// ========================================================================
// PrintCollisionModelInfo
// EA  : 0x825D7EB8
// RVA : 0x005D7EB8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall PrintCollisionModelInfo(idCollisionModelLocal *model)
{
  int v2; // r30
  int v3; // r31
  const cm_subModelData_t *v4; // r3
  const cm_subModelData_t *v5; // r28
  char **p_streamAreaNameBytes; // r11
  int i; // ctr
  int v8; // r25
  streamArea_t *streamAreas; // r11
  int v10; // r28
  streamArea_t *v11; // r10
  int v12; // r27
  int v13; // r31
  streamArea_t *v14; // r10
  int v15; // r30
  const cm_subModelData_t *v16; // r3
  int MaxResidentMemory; // r3
  idVec3 v18; // [sp+50h] [-E0h] BYREF
  streamAreasPtrs_t v19; // [sp+60h] [-D0h] BYREF
  cm_subModelData_t v20; // [sp+70h] [-C0h] BYREF

  v2 = 0;
  if ( model->polygonModel.numSubModels > 0 )
  {
    v3 = 0;
    do
    {
      idLib::Printf(fmt: "sub model %i\n", v2);
      v4 = AcquireSubModelData(subModel: &model->polygonModel.subModels[v3]);
      v5 = v4;
      if ( v4->header.loadedSize != 32 )
        PrintSubModelInfo(subModelData: v4);
      ReleaseSubModelData(subModel: (const cm_subModelData_t *)&model->polygonModel.subModels[v3], data: v5);
      ++v2;
      ++v3;
    }
    while ( v2 < model->polygonModel.numSubModels );
  }
  idLib::Printf(fmt: "total\n");
  p_streamAreaNameBytes = &v19.streamAreaNameBytes;
  for ( i = 13; i != 0; --i )
  {
    p_streamAreaNameBytes += 2;
    *(_QWORD *)p_streamAreaNameBytes = 0xD00000000LL;
  }
  p_streamAreaNameBytes[2] = nullptr;
  AddCollisionModelInfo(model, stats: &v20);
  PrintSubModelInfo(subModelData: &v20);
  if ( model->isStreamed )
  {
    SetupStreamAreaPtrs(header: model->streamAreas, ptrs: &v19);
    v8 = 0;
    if ( model->streamAreas->numStreamAreas > 0 )
    {
      streamAreas = v19.streamAreas;
      v10 = 0;
      v11 = v19.streamAreas;
      do
      {
        v12 = 0;
        v13 = 0;
        if ( v11->numSubModels > 0 )
        {
          v14 = &streamAreas[v10];
          do
          {
            v15 = 16
                * (v19.streamAreaSubModels[v14->subModelsOffset + v13]
                 + __ROL4__(v19.streamAreaSubModels[v14->subModelsOffset + v13], 1));
            v16 = AcquireSubModelData(subModel: (const cm_subModel_t *)((char *)model->polygonModel.subModels + v15));
            v12 += v16->header.totalSize;
            ReleaseSubModelData(
              subModel: (const cm_subModelData_t *)((char *)model->polygonModel.subModels + v15),
              data: v16);
            streamAreas = v19.streamAreas;
            ++v13;
            v14 = &v19.streamAreas[v10];
          }
          while ( v13 < v19.streamAreas[v10].numSubModels );
        }
        idLib::Printf(
          fmt: "%5d kB in stream area %s\n",
          v12 >> 10,
          &v19.streamAreaNameBytes[streamAreas[v10].volumeNameOffset]);
        streamAreas = v19.streamAreas;
        ++v8;
        v11 = &v19.streamAreas[++v10];
      }
      while ( v8 < model->streamAreas->numStreamAreas );
    }
    v18.x = 0.0;
    v18.y = 0.0;
    v18.z = 0.0;
    MaxResidentMemory = idCollisionModelLocal::GetMaxResidentMemory(this: model, location: &v18);
    idLib::Printf(
      fmt: "%5d kB maximum resident size at ( %1.0f, %1.0f, %1.0f )\n",
      MaxResidentMemory >> 10,
      v18.x,
      v18.y,
      v18.z);
  }
}


// ========================================================================
// CollisionModelInfo_f
// EA  : 0x825D80C8
// RVA : 0x005D80C8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall CollisionModelInfo_f(const idCmdArgs *args)
{
  const char *v1; // r3
  int v2; // r4
  char *v3; // r11
  int i; // ctr
  int j; // r31
  const idCollisionModelLocal *v6; // r3
  idCollisionModelLocal *v7; // r3
  char v8; // [sp+48h] [-98h] BYREF
  cm_subModelData_t v9; // [sp+50h] [-90h] BYREF

  if ( args->argc >= 2 )
  {
    if ( args->argc <= 1 )
      v1 = &byte_8200D768;
    else
      v1 = args->argv[1];
    v2 = atol(nptr: v1);
    if ( v2 >= 0 )
    {
      v7 = (idCollisionModelLocal *)idResourceList::Index(this: &idCollisionModelLocal::resourceList, index: v2);
      PrintCollisionModelInfo(model: v7);
    }
    else
    {
      v3 = &v8;
      for ( i = 13; i != 0; --i )
      {
        v3 += 8;
        *(_QWORD *)v3 = 0xD00000000LL;
      }
      *((_DWORD *)v3 + 2) = 0;
      for ( j = 0; j < idCollisionModelLocal::resourceList.num; ++j )
      {
        v6 = (const idCollisionModelLocal *)idResourceList::Index(this: &idCollisionModelLocal::resourceList, index: j);
        AddCollisionModelInfo(model: v6, stats: &v9);
      }
      PrintSubModelInfo(subModelData: &v9);
    }
  }
  else
  {
    idLib::Printf(fmt: "usage: collisionModelInfo <num>\nuse -1 for accumulated info\n");
  }
}


// ========================================================================
// ?TrmFromSubModel@idTrmFromSubModel@@SA_NPBVidCollisionModelLocal@@PBUcm_subModelData_t@@AAVidTraceModel@@@Z
// EA  : 0x825D8280
// RVA : 0x005D8280
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

int __fastcall idTrmFromSubModel::TrmFromSubModel(
        idCollisionModelLocal *model,
        const cm_subModelData_t *subModelData,
        idTraceModel *trm)
{
  int numVertices; // r5
  char v7; // r31
  int numEdges; // r5
  int numPolygons; // r5
  idBounds *p_bounds; // r31
  signed int v12; // r11
  signed int v13; // r26
  unsigned __int8 *v14; // r28
  unsigned __int16 *polygonEdges; // r25
  float *polyPlaneY; // r29
  unsigned __int8 *p_numEdges; // r30
  double a; // fp11
  int v19; // r11
  double c; // fp13
  int v21; // r10
  unsigned __int8 v22; // r10
  signed int v23; // r8
  signed int v24; // r9
  float *v25; // r10
  float *p_z; // r11
  double v27; // fp0
  double v28; // fp13
  double y; // fp11
  double z; // fp0
  double v31; // fp8
  double x; // fp9
  double v43; // fp7
  signed int v46; // r9
  signed int v47; // r8
  _WORD *v48; // r10
  _WORD *v49; // r11
  double v50; // fp7
  double v51; // fp5
  idPlane v52; // [sp+50h] [-90h] BYREF
  cm_subModelPtrs_t v53[3]; // [sp+60h] [-80h] BYREF

  numVertices = subModelData->numVertices;
  v7 = 1;
  if ( numVertices > 32 )
  {
    v7 = 0;
    idLib::Printf(
      fmt: "TrmFromSubModel: model %s has too many vertices(%d) (max %d).\n",
      model->name.str,
      numVertices,
      32);
  }
  numEdges = subModelData->numEdges;
  if ( numEdges > 32 )
  {
    v7 = 0;
    idLib::Printf(fmt: "TrmFromSubModel: model %s has too many edges(%d) (max %d).\n", model->name.str, numEdges, 32);
  }
  numPolygons = subModelData->numPolygons;
  if ( numPolygons > 16 )
  {
    v7 = 0;
    idLib::Printf(
      fmt: "TrmFromSubModel: model %s has too many polygons(%d) (max %d).\n",
      model->name.str,
      numPolygons,
      16);
  }
  if ( v7 == 0 )
    goto LABEL_10;
  if ( subModelData->numVertices <= 3 )
  {
    idLib::Warning(fmt: "TrmFromSubModel: model %s has less than 4 vertices.", model->name.str);
LABEL_10:
    PrintCollisionModelInfo(model);
    return 0;
  }
  trm->type = TRM_CUSTOM;
  p_bounds = &trm->bounds;
  trm->bounds.b[0].z = 1.0e30;
  trm->bounds.b[0].y = 1.0e30;
  trm->bounds.b[0].x = 1.0e30;
  trm->bounds.b[1].z = -1.0e30;
  trm->bounds.b[1].y = -1.0e30;
  trm->bounds.b[1].x = -1.0e30;
  idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs: v53, subModelData);
  v12 = subModelData->numPolygons;
  v13 = 0;
  if ( v12 > 0 )
  {
    v14 = trm->polyEdges[0];
    polygonEdges = v53[0].polygonEdges;
    polyPlaneY = trm->polyPlaneY;
    p_numEdges = &v53[0].polygons->numEdges;
    do
    {
      CM_GetPolygonPlane(subModel: v53, polygon: (const cm_polygon_t *)(p_numEdges - 13), plane: &v52);
      a = v52.a;
      v19 = 0;
      polyPlaneY[32] = v52.d;
      *(polyPlaneY - 16) = a;
      c = v52.c;
      *polyPlaneY = v52.b;
      polyPlaneY[16] = c;
      *((_DWORD *)polyPlaneY + 112) = *p_numEdges;
      if ( *p_numEdges != 0 )
      {
        do
        {
          v21 = polygonEdges[*(unsigned __int16 *)(p_numEdges + 1) + v19];
          if ( (~v21 & 0x8000) != 0 )
            v22 = v21 & 0x7F;
          else
            v22 = v21 | 0x80;
          v14[v19++] = v22;
        }
        while ( v19 < *p_numEdges );
      }
      v12 = subModelData->numPolygons;
      ++v13;
      ++polyPlaneY;
      p_numEdges += 16;
      v14 += 16;
    }
    while ( v13 < v12 );
  }
  trm->numPolys = v12;
  v23 = 0;
  v24 = subModelData->numVertices;
  if ( v24 > 0 )
  {
    v25 = &trm->vertsY[31];
    p_z = &v53[0].vertices[-1].p.z;
    do
    {
      v27 = p_z[4];
      ++v23;
      v28 = p_z[3];
      *(v25 - 63) = p_z[2];
      *(v25 - 31) = v28;
      *++v25 = v27;
      y = trm->bounds.b[0].y;
      z = trm->bounds.b[0].z;
      v31 = trm->bounds.b[1].y;
      _FP5 = (float)(p_bounds->b[0].x - p_z[2]);
      __asm { fsel      f4, f5, f10, f6 }
      p_bounds->b[0].x = _FP4;
      _FP2 = (float)((float)y - p_z[3]);
      __asm { fsel      f1, f2, f3, f11 }
      trm->bounds.b[0].y = _FP1;
      _FP12 = (float)((float)z - p_z[4]);
      __asm { fsel      f11, f12, f13, f0 }
      x = trm->bounds.b[1].x;
      trm->bounds.b[0].z = _FP11;
      _FP6 = (float)(p_z[2] - (float)x);
      __asm { fsel      f5, f6, f10, f9 }
      trm->bounds.b[1].x = _FP5;
      _FP3 = (float)(p_z[3] - (float)v31);
      __asm { fsel      f2, f3, f4, f8 }
      v43 = trm->bounds.b[1].z;
      trm->bounds.b[1].y = _FP2;
      p_z += 4;
      _FP1 = (float)(*p_z - (float)v43);
      __asm { fsel      f0, f1, f0, f7 }
      trm->bounds.b[1].z = _FP0;
      v24 = subModelData->numVertices;
    }
    while ( v23 < v24 );
  }
  trm->numVerts = v24;
  v46 = 0;
  v47 = subModelData->numEdges;
  if ( v47 > 0 )
  {
    v48 = (_WORD *)&trm->numPolyEdges[15] + 1;
    v49 = (_WORD *)&v53[0].edges[-1] + 1;
    do
    {
      ++v46;
      v48[1] = v49[1];
      v49 += 2;
      v48 += 2;
      *v48 = *v49;
      v47 = subModelData->numEdges;
    }
    while ( v46 < v47 );
  }
  trm->numEdges = v47;
  if ( idTraceModel::IsClosedSurface(this: trm) )
  {
    idTraceModel::CalculateInsetSphereRadius(this: trm);
    v50 = (float)(trm->bounds.b[0].y + trm->bounds.b[1].y);
    v51 = (float)(trm->bounds.b[1].z + trm->bounds.b[0].z);
    trm->offset.x = (float)(trm->bounds.b[1].x + trm->bounds.b[0].x) * (float)0.5;
    trm->offset.y = (float)v50 * (float)0.5;
    trm->offset.z = (float)v51 * (float)0.5;
    idTraceModel::GenerateEdgeNormals(this: trm);
    idTraceModel::TestConvexity(this: trm);
    idTraceModel::ClearUnused(this: trm);
    return 1;
  }
  else
  {
    idLib::Printf(
      fmt: "TrmFromSubModel: model %s has dangling edges, the model has to be a closed hull.\n",
      model->name.str);
    PrintCollisionModelInfo(model);
    return 0;
  }
}


// ========================================================================
// TrmFromModel
// EA  : 0x825D8608
// RVA : 0x005D8608
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

int __fastcall TrmFromModel(idCollisionModelLocal *model, idTraceModel *trm)
{
  const cm_subModelData_t *v5; // r29
  int v6; // r30

  if ( model->polygonModel.numSubModels == 1 )
  {
    v5 = AcquireSubModelData(subModel: model->polygonModel.subModels);
    v6 = idTrmFromSubModel::TrmFromSubModel(model, subModelData: v5, trm);
    ReleaseSubModelData(subModel: (const cm_subModelData_t *)model->polygonModel.subModels, data: v5);
    return v6;
  }
  else
  {
    idLib::Warning(fmt: "TrmFromModel: model %s has more than one sub model.", model->name.str);
    PrintCollisionModelInfo(model);
    return 0;
  }
}


// ========================================================================
// ?TrmFromModel@idCollisionModelManager@@QAA_NPBDAAVidTraceModel@@@Z
// EA  : 0x825D8688
// RVA : 0x005D8688
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

int __fastcall idCollisionModelManager::TrmFromModel(
        idCollisionModelManager *this,
        const char *modelName,
        idTraceModel *trm)
{
  idCollisionModelLocal *v5; // r3

  v5 = (idCollisionModelLocal *)idResourceList::Load(
                                  this: &idCollisionModelLocal::resourceList,
                                  name: modelName,
                                  makeDefault: true,
                                  skipStaleCheck: false);
  if ( v5 != nullptr )
    return TrmFromModel(model: v5, trm);
  idLib::Warning(fmt: "TrmFromModel: model '%s' not found.", modelName);
  return 0;
}


// ========================================================================
// ?CompoundTrmFromModel@idCollisionModelManager@@QAAHPBDPAVidTraceModel@@HPAH2@Z
// EA  : 0x825D86F8
// RVA : 0x005D86F8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

int __fastcall idCollisionModelManager::CompoundTrmFromModel(
        idCollisionModelManager *this,
        const char *modelName,
        idTraceModel *trms,
        int maxTrms,
        int *invalidSubmodelIndices,
        int *numInvalidIndices)
{
  idResource *v11; // r3
  idCollisionModelLocal *v12; // r28
  int v14; // r31
  int v15; // r22
  int v16; // r25
  int i; // r29
  const cm_subModelData_t *v18; // r21
  char v19; // r20

  v11 = idResourceList::Load(
          this: &idCollisionModelLocal::resourceList,
          name: modelName,
          makeDefault: true,
          skipStaleCheck: false);
  v12 = (idCollisionModelLocal *)v11;
  if ( v11 == nullptr )
  {
    idLib::Warning(fmt: "CompoundTrmFromModel: model '%s' not found.", modelName);
    return 0;
  }
  if ( (int)v11[2].resourceListPtr > maxTrms )
  {
    idLib::Warning(fmt: "CompoundTrmFromModel: model '%s' has more than %d sub models.", modelName, maxTrms);
    return 0;
  }
  v14 = 0;
  v15 = 0;
  v16 = 0;
  if ( numInvalidIndices != nullptr )
  {
    v16 = *numInvalidIndices;
    *numInvalidIndices = 0;
  }
  if ( (int)v11[2].resourceListPtr <= 0 )
    return v15;
  for ( i = 0; ; ++i )
  {
    v18 = AcquireSubModelData(subModel: &v12->polygonModel.subModels[i]);
    v19 = idTrmFromSubModel::TrmFromSubModel(model: v12, subModelData: v18, trm: trms);
    ReleaseSubModelData(subModel: (const cm_subModelData_t *)&v12->polygonModel.subModels[i], data: v18);
    if ( v19 == 0 )
      break;
    ++v15;
    ++trms;
LABEL_16:
    if ( ++v14 >= v12->polygonModel.numSubModels )
      return v15;
  }
  if ( invalidSubmodelIndices != nullptr && numInvalidIndices != nullptr )
  {
    idLib::Warning(
      fmt: "CompoundTrmFromModel: TrmFromSubModel failed on submodel %d, using that as part of base model.",
      v14);
    if ( *numInvalidIndices >= v16 )
      idLib::Warning(
        fmt: "CompoundTrmFromModel: TrmFromSubModel can't use any more invalid submodel indices ( > %d ).",
        *numInvalidIndices);
    invalidSubmodelIndices[(*numInvalidIndices)++] = v14 + 1;
    goto LABEL_16;
  }
  idLib::Warning(fmt: "CompoundTrmFromModel: TrmFromSubModel failed on submodel %d.", v14);
  return 0;
}


// ========================================================================
// ExportCollisionModel_f
// EA  : 0x825D8898
// RVA : 0x005D8898
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall ExportCollisionModel_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v3; // cr58
  const char *v4; // r4
  idResource *v5; // r28
  int v6; // r11
  unsigned __int64 v7; // r27
  int v8; // r17
  int v9; // r25
  int v10; // r24
  int v11; // r22
  int v12; // r21
  int v13; // r23
  idTriangles *v14; // r3
  idTriangles *v15; // r29
  int v16; // r9
  int v17; // r11
  float *v18; // r10
  unsigned __int16 *v19; // r28
  int num; // r30
  int v21; // r20
  unsigned __int8 *v22; // r28
  unsigned __int16 *list; // r24
  int v24; // r30
  unsigned int v25; // r8
  int v26; // r25
  unsigned __int16 *v27; // r30
  idBounds *v28; // r3
  double y; // fp13
  int numIndexes; // r7
  idResourceList *resourceListPtr; // r9
  int v32; // [sp+50h] [-420h]
  idTriangles *v33; // [sp+54h] [-41Ch] BYREF
  int v34; // [sp+58h] [-418h]
  idList<unsigned short,5> v35; // [sp+60h] [-410h] BYREF
  idList<unsigned short,5> v36; // [sp+70h] [-400h] BYREF
  int v37; // [sp+80h] [-3F0h]
  int v38; // [sp+84h] [-3ECh]
  int v39; // [sp+88h] [-3E8h]
  int v40; // [sp+8Ch] [-3E4h]
  int v41; // [sp+90h] [-3E0h]
  int v42; // [sp+94h] [-3DCh]
  idStaticModelSurface v43; // [sp+A0h] [-3D0h] BYREF
  idStr v44; // [sp+F0h] [-380h] BYREF
  idTriangles v45[3]; // [sp+110h] [-360h] BYREF
  char v46[256]; // [sp+2D0h] [-1A0h] BYREF

  argc = args->argc;
  v3 = args->argc == 1;
  v37 = args->argc;
  if ( v3 )
  {
    idLib::Printf(fmt: "USAGE: ExportWorldCollisionModel <world.bcm> [surfaceFlags] [contentFlags]\n");
  }
  else
  {
    if ( argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    v5 = idResourceList::Load(
           this: &idCollisionModelLocal::resourceList,
           name: v4,
           makeDefault: false,
           skipStaleCheck: false);
    v37 = (int)v5;
    if ( v5 != nullptr )
    {
      v6 = args->argc;
      LODWORD(v7) = 0;
      v39 = 0;
      v38 = 0;
      v42 = 0;
      v41 = 0;
      v40 = -1;
      if ( v6 > 2 )
        v42 = atol(nptr: args->argv[2]);
      if ( args->argc > 3 )
        v41 = atol(nptr: args->argv[3]);
      if ( args->argc > 4 )
        v39 = atol(nptr: args->argv[4]);
      if ( args->argc > 5 )
        v38 = atol(nptr: args->argv[5]);
      if ( args->argc > 6 )
        v40 = atol(nptr: args->argv[6]);
      idStaticModel::idStaticModel(this: (idStaticModel *)&v45[0].numVerts);
      v8 = 0;
      v32 = 0;
      if ( (int)v5[2].resourceListPtr > 0 )
      {
        v34 = 0;
        do
        {
          HIDWORD(v7) = *(_DWORD *)(v34 + v5[2].networkID + 32);
          if ( HIDWORD(v7) != 0 && *(_DWORD *)(HIDWORD(v7) + 84) != 0 )
          {
            v9 = *(_DWORD *)(HIDWORD(v7) + 88) + HIDWORD(v7);
            v10 = *(_DWORD *)(HIDWORD(v7) + 64) + HIDWORD(v7);
            v11 = *(_DWORD *)(HIDWORD(v7) + 72) + HIDWORD(v7);
            v12 = *(_DWORD *)(HIDWORD(v7) + 80) + HIDWORD(v7);
            v13 = *(_DWORD *)(HIDWORD(v7) + 56) + HIDWORD(v7);
            v14 = (idTriangles *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                   size: 0x84u,
                                   tag: TAG_NEW,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
            v33 = v14;
            if ( v14 != nullptr )
              v15 = idTriangles::idTriangles(this: v14);
            else
              v15 = nullptr;
            idTriangles::AllocStaticTriSurfVerts(this: v15, numVerts: *(_DWORD *)(HIDWORD(v7) + 84));
            v16 = 0;
            v15->numVerts = *(_DWORD *)(HIDWORD(v7) + 84);
            if ( *(int *)(HIDWORD(v7) + 84) > 0 )
            {
              v17 = 0;
              v18 = (float *)(v9 - 8);
              do
              {
                ++v16;
                v15->verts[v17].xyz.x = v18[2];
                v15->verts[v17].xyz.y = v18[3];
                v18 += 4;
                v15->verts[v17++].xyz.z = *v18;
              }
              while ( v16 < *(_DWORD *)(HIDWORD(v7) + 84) );
            }
            v19 = nullptr;
            num = 0;
            *(_WORD *)&v35.memTag = 3328;
            memset(&v35, 0, 14);
            v21 = 0;
            if ( *(int *)(HIDWORD(v7) + 60) > 0 )
            {
              v22 = (unsigned __int8 *)(v10 + 12);
              do
              {
                if ( (v42 == 0 || (*(_DWORD *)(__ROL4__(*v22, 4) + v13 + 4) & v42) != 0)
                  && (v41 == 0 || (*(_DWORD *)(__ROL4__(*v22, 4) + v13 + 4) & v41) == 0)
                  && (v39 == 0 || (*(_DWORD *)(__ROL4__(*v22, 4) + v13) & v39) != 0)
                  && (v38 == 0 || (*(_DWORD *)(__ROL4__(*v22, 4) + v13) & v38) == 0)
                  && (v40 == -1 || *(_DWORD *)(__ROL4__(*v22, 4) + v13 + 8) == v40) )
                {
                  list = nullptr;
                  *(_WORD *)&v36.memTag = 3328;
                  memset(&v36, 0, 14);
                  v24 = 0;
                  if ( v22[1] != 0 )
                  {
                    do
                    {
                      v25 = *(unsigned __int16 *)(2 * (*((unsigned __int16 *)v22 + 1) + v24) + v11);
                      HIWORD(v33) = *(_WORD *)(2 * ((v25 >> 15) + ((2 * v25) & 0x7FFE)) + v12);
                      idList<unsigned short,72>::Append(this: &v36, obj: (unsigned __int16 *)&v33);
                      ++v24;
                    }
                    while ( v24 < v22[1] );
                    list = v36.list;
                    if ( v36.num > 2 )
                    {
                      v26 = v36.num - 2;
                      v27 = v36.list + 2;
                      do
                      {
                        idList<unsigned short,72>::Append(this: &v35, obj: list);
                        idList<unsigned short,72>::Append(this: &v35, obj: v27 - 1);
                        idList<unsigned short,72>::Append(this: &v35, obj: v27);
                        --v26;
                        ++v27;
                      }
                      while ( v26 != 0 );
                    }
                  }
                  if ( v36.listStatic == 0 || v36.listStatic == 2 )
                  {
                    if ( list != nullptr )
                      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
                    v36.list = nullptr;
                    v36.size = 0;
                  }
                  v36.num = 0;
                }
                ++v21;
                v22 += 16;
              }
              while ( v21 < *(_DWORD *)(HIDWORD(v7) + 60) );
              num = v35.num;
              v19 = v35.list;
            }
            idTriangles::AllocStaticTriSurfIndexes(this: v15, numIndexes: num);
            v15->numIndexes = num;
            memcpy(Dst: v15->indexes, Src: v19, Size: 2 * num);
            v43.skinOffsets.x = 0.0;
            v43.material = nullptr;
            v43.skinOffsets.y = 0.0;
            v43.materialNum = 0;
            v43.skinOffsets.z = 0.0;
            v43.extraGLState = v7;
            v43.skinOffsets.w = 0.0;
            v43.geometry = nullptr;
            v43.geometryIsReference = false;
            v43.referenceMask = 0;
            memset(&v43.binaryModelId, 0, 16);
            v43.skinRemaps.memTag = 5;
            v43.skinRemaps.listStatic = 0;
            memset(&v43.skinRemaps, 0, 14);
            v28 = idTriangles::BoundsFromVertScan(this: v45, result: &v15->bounds);
            v33 = (idTriangles *)&v28->b[1];
            v15->bounds.b[0].x = v28->b[0].x;
            y = v28->b[0].y;
            v33 = (idTriangles *)&v15->bounds.b[1];
            v15->bounds.b[0].y = y;
            v15->bounds.b[0].z = v28->b[0].z;
            v15->bounds.b[1] = v28->b[1];
            numIndexes = v15->numIndexes;
            v43.geometry = v15;
            v8 += numIndexes / 3;
            v43.material = (const idMaterial *)idResourceList::Load(
                                                 this: &idMaterial::resourceList,
                                                 name: cm_showCollisionModelMaterial.valueString.data,
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
            idStaticModel::AddSurface(this: (idStaticModel *)&v45[0].numVerts, surf: &v43);
            if ( v43.skinRemaps.listStatic == 0 || v43.skinRemaps.listStatic == 2 )
            {
              if ( v43.skinRemaps.list != nullptr )
                idMem::Free(this: &mem, ptr: v43.skinRemaps.list, align: ALIGN_16);
              v43.skinRemaps.list = nullptr;
              v43.skinRemaps.size = 0;
            }
            v43.skinRemaps.num = 0;
            if ( v35.listStatic == 0 || v35.listStatic == 2 )
            {
              if ( v19 != nullptr )
                idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
              v35.list = nullptr;
              v35.size = 0;
            }
            v5 = (idResource *)v37;
            v35.num = 0;
          }
          resourceListPtr = v5[2].resourceListPtr;
          ++v32;
          v34 += 48;
        }
        while ( v32 < (int)resourceListPtr );
      }
      idStaticModel::FinishStaticModel(this: (idStaticModel *)&v45[0].numVerts, cleanup: false);
      idLib::Printf(fmt: "%i total triangles\n", v8);
      idStr::idStr(this: &v44, text: v5->name.str);
      idStr::StripFilename(this: &v44);
      idStr::Append(this: &v44, text: "/collision.bmodel");
      fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bmodel", a4: v44.data, a5: v46, a6: 256);
      idStaticModel::WriteStaticBModel(this: (idStaticModel *)&v45[0].numVerts, filename: v46, basePath: FSPATH_BASE);
      idStr::FreeData(this: &v44);
      idStaticModel::~idStaticModel(this: (idStaticModel *)&v45[0].numVerts);
    }
    else
    {
      idLib::Printf(fmt: "Collision model not found\n");
    }
  }
}


// ========================================================================
// __unwind$230383
// EA  : 0x825D8F3C
// RVA : 0x005D8F3C
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_230383()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 1136 + 304));
}


// ========================================================================
// __unwind$230384
// EA  : 0x825D8F64
// RVA : 0x005D8F64
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall _unwind_230384(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 1136 + 84), tag: a2);
}


// ========================================================================
// __unwind$230385
// EA  : 0x825D8F8C
// RVA : 0x005D8F8C
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_230385()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1136 + 96));
}


// ========================================================================
// __unwind$230386
// EA  : 0x825D8FB4
// RVA : 0x005D8FB4
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_230386()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1136 + 112));
}


// ========================================================================
// __unwind$230387
// EA  : 0x825D8FDC
// RVA : 0x005D8FDC
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_230387()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 1136 + 160));
}


// ========================================================================
// __unwind$230388
// EA  : 0x825D9004
// RVA : 0x005D9004
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_230388()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1136 + 240));
}


// ========================================================================
// ?Init@idCollisionModelManager@@QAAXXZ
// EA  : 0x825D90A8
// RVA : 0x005D90A8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __fastcall idCollisionModelManager::Init(idCollisionModelManager *this)
{
  if ( baseTraceWork == nullptr )
    baseTraceWork = idPolygonModelCollisionDetection::AllocTraceWork();
  idCollisionQueryJobManager::Init(this: &cdQuery);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "bcm",
    a3: BuildCollisionModelsForMap_f,
    a4: "build collision models for a map",
    a5: idCmdSystem::ArgCompletion_MapName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "stripbcm",
    a3: StripBCM_f,
    a4: &byte_8200D768,
    a5: idCmdSystem::ArgCompletion_MapName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listCollisionModels",
    a3: ListCollisionModels_f,
    a4: "lists collision models",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "collisionModelInfo",
    a3: CollisionModelInfo_f,
    a4: "shows collision model info",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "exportCollisionModel",
    a3: ExportCollisionModel_f,
    a4: "Writes an obj model visualizing the given collision model",
    a5: nullptr);
}


// ========================================================================
// ?Motion@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUtrace_t@@ABVidVec3@@1ABVidRotation@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D9288
// RVA : 0x005D9288
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::Motion(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        trace_t *a3,
        const idMat3 *start,
        const idVec3 *end,
        idRotation *rotation,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        const int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        const idVec3 *a32,
        int a33,
        int a34,
        int a35,
        int numTrmsa)
{
  __int64 v36; // r28
  unsigned __int64 v42; // r6
  int v46; // r18
  __int64 v47; // r11
  char v48; // r11
  __int64 v49; // r28
  int v50; // r11
  int v51; // r22
  idTraceWork *v52; // r29
  const idTraceModel **v53; // r21
  int v54; // r30
  int v55; // r24
  double radius; // fp1
  int v57; // r25
  const idMat3 **v58; // r24
  int v59; // r22
  int v60; // r30
  int v61; // r26
  const idVec3 *v62; // r7
  __int64 v63; // r11
  char v64; // r11
  const idMat3 *v66; // [sp+8h] [-2B8h]
  int v67; // [sp+8h] [-2B8h]
  int v68; // [sp+8h] [-2B8h]
  const idMat3 *v69; // [sp+Ch] [-2B4h]
  int v70; // [sp+Ch] [-2B4h]
  int v71; // [sp+Ch] [-2B4h]
  const idPositionedCollisionModel *v72; // [sp+10h] [-2B0h]
  int v73; // [sp+14h] [-2ACh]
  const char *v74; // [sp+18h] [-2A8h]
  int v75; // [sp+1Ch] [-2A4h]
  int v76; // [sp+20h] [-2A0h]
  int v77; // [sp+24h] [-29Ch]
  int v78; // [sp+28h] [-298h]
  int v79; // [sp+2Ch] [-294h]
  int v80; // [sp+30h] [-290h]
  int v81; // [sp+34h] [-28Ch]
  int v82; // [sp+38h] [-288h]
  int v83; // [sp+3Ch] [-284h]
  int v84; // [sp+40h] [-280h]
  int v85; // [sp+44h] [-27Ch]
  int v86; // [sp+48h] [-278h]
  int v87; // [sp+4Ch] [-274h]
  int v88; // [sp+50h] [-270h]
  int v89; // [sp+58h] [-268h]
  int v90; // [sp+60h] [-260h]
  int v91; // [sp+68h] [-258h]
  _DWORD v92[2]; // [sp+80h] [-240h] BYREF
  idPLogScope v93; // [sp+88h] [-238h] BYREF
  trace_t v94; // [sp+90h] [-230h] BYREF
  trace_t v95; // [sp+110h] [-1B0h] BYREF
  trace_t v96; // [sp+190h] [-130h] BYREF

  LODWORD(v42) = "idCollisionModelManager::Motion";
  HIDWORD(v42) = 1;
  idPLogScope::idPLogScope(this: &v93, pl: &pLog, gMask: v42, label: (const char *)end);
  if ( a3 == nullptr )
  {
    idCollisionQueryJobManager::SubmitMotionQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start: start->mat,
      end,
      rotation,
      globalBounds,
      trms,
      numTrms: a28,
      trmAxis: v66,
      contentMask: (int)v69,
      models: v72,
      numModels: v73,
      userName: v74);
    goto _M231092;
  }
  v46 = numTrmsa;
  if ( numTrmsa == 0 )
  {
    a3->fraction = 1.0;
    v92[0] = &a3->endAxis.mat[1];
    a3->endpos.x = end->x;
    a3->endpos.y = end->y;
    v92[0] = &a3->endAxis.mat[2];
    a3->endpos.z = end->z;
    a3->endAxis.mat[0].x = *(float *)a30;
    a3->endAxis.mat[0].y = *(float *)(a30 + 4);
    a3->endAxis.mat[0].z = *(float *)(a30 + 8);
    a3->endAxis.mat[1].x = *(float *)(a30 + 12);
    a3->endAxis.mat[1].y = *(float *)(a30 + 16);
    a3->endAxis.mat[1].z = *(float *)(a30 + 20);
    a3->endAxis.mat[2].x = *(float *)(a30 + 24);
    a3->endAxis.mat[2].y = *(float *)(a30 + 28);
    a3->endAxis.mat[2].z = *(float *)(a30 + 32);
    idRotation::RotatePoint(this: rotation, point: &a3->endpos);
    if ( !rotation->axisValid )
      idRotation::ToMat3(this: rotation);
    idMat3::operator*=(this: &a3->endAxis, a: &rotation->axis);
    memset(Dst: &a3->c, Val: 0, Size: sizeof(a3->c));
    LODWORD(v47) = 0;
    *(_QWORD *)this = v47;
    goto _M231092;
  }
  if ( rotation->angle == 0.0
    || ((LODWORD(rotation->vec.z) | LODWORD(rotation->vec.y) | LODWORD(rotation->vec.x)) & 0x7FFFFFFF) == 0 )
  {
    if ( start->mat[0].x == end->x && start->mat[0].y == end->y && start->mat[0].z == end->z )
    {
      v64 = 1;
      LODWORD(v36) = 0;
    }
    else
    {
      LODWORD(v36) = 0;
      v64 = 0;
    }
    if ( v64 != 0 )
    {
      a3->fraction = 1.0;
      v92[0] = &a3->endAxis.mat[2];
      a3->endpos.x = start->mat[0].x;
      a3->endpos.y = start->mat[0].y;
      a3->endpos.z = start->mat[0].z;
      a3->endAxis.mat[0].x = *(float *)a30;
      a3->endAxis.mat[0].y = *(float *)(a30 + 4);
      a3->endAxis.mat[0].z = *(float *)(a30 + 8);
      a3->endAxis.mat[1].x = *(float *)(a30 + 12);
      a3->endAxis.mat[1].y = *(float *)(a30 + 16);
      a3->endAxis.mat[1].z = *(float *)(a30 + 20);
      a3->endAxis.mat[2].x = *(float *)(a30 + 24);
      a3->endAxis.mat[2].y = *(float *)(a30 + 28);
      a3->endAxis.mat[2].z = *(float *)(a30 + 32);
      memset(Dst: &a3->c, Val: 0, Size: sizeof(a3->c));
    }
    else
    {
      idCollisionModelManager::Translation(
        this: (idCollisionModelManager *)v92,
        result,
        a3,
        start: start->mat,
        end,
        globalBounds,
        trms,
        numTrms: a28,
        trmAxis: v66,
        contentMask: (const int)v69,
        models: v72,
        numModels: v73,
        userName: v74,
        a14: v75,
        a15: v76,
        a16: v77,
        a17: v78,
        a18: v79,
        a19: v80,
        a20: v81,
        a21: v82,
        a22: v83,
        a23: v84,
        a24: v85,
        a25: v86,
        a26: v87,
        a27: v88,
        a28: (idMat3 *)a30,
        a29: v89,
        a30: (int)a32,
        a31: v90,
        a32: a34,
        a33: v91,
        a34: numTrmsa);
    }
    *(_QWORD *)this = v36;
    goto _M231092;
  }
  if ( start->mat[0].x != end->x || start->mat[0].y != end->y || (v48 = 1, start->mat[0].z != end->z) )
    v48 = 0;
  if ( v48 != 0 )
  {
    LODWORD(v49) = 0;
    HIDWORD(v49) = a32;
    idCollisionModelManager::Rotation(
      this: (idCollisionModelManager *)v92,
      result,
      a3,
      start,
      rotation,
      globalBounds,
      (const idMat3 **)trms,
      numTrms: a28,
      trmAxis: v66,
      contentMask: (const int)v69,
      models: v72,
      numModels: v73,
      userName: v74,
      a14: v75,
      a15: v76,
      a16: v77,
      a17: v78,
      a18: v79,
      a19: v80,
      a20: v81,
      a21: v82,
      a22: v83,
      a23: v84,
      a24: v85,
      a25: v86,
      a26: v87,
      a27: v88,
      a28: (const idMat3 *)a30,
      a29: v89,
      a30: a32,
      a31: v90,
      a32: a34,
      a33: v91,
      a34: numTrmsa);
    *(_QWORD *)this = v49;
    goto _M231092;
  }
  v50 = a28;
  v51 = 0;
  v52 = baseTraceWork;
  v94.fraction = 2.0;
  if ( a28 <= 0 )
    goto LABEL_31;
  v53 = trms;
  do
  {
    if ( v46 <= 0 )
      goto LABEL_30;
    v54 = a34 + 64;
    do
    {
      v55 = *(_DWORD *)(v54 - 64);
      if ( (*(int (__fastcall **)(int))(*(_DWORD *)v55 + 28))(a1: v55) != 0 )
      {
        if ( (*(int (__fastcall **)(int))(*(_DWORD *)v55 + 28))(a1: v55) != 1 )
          goto LABEL_28;
        if ( *v53 != nullptr )
          radius = (*v53)->radius;
        else
          radius = 0.0;
        idSphereModelCollisionDetection::TraceThroughModel(
          trace: &v95,
          csData: *(const cm_sphereModel_t **)(v55 + 104),
          start: start->mat,
          end,
          radius,
          trmAxis: *(const idMat3 **)(v54 + 4),
          modelJoints: (const idJointMat *)a30,
          modelOrigin: *(const idVec3 **)(v54 - 60),
          modelAxis: (const idMat3 *)(v54 - 56),
          modelEntityNum: (int)v66,
          modelPhysicsId: (int)v69,
          modelBodyId: (int)v72,
          selfId: v73,
          modelContentsOverride: (int)v74);
      }
      else
      {
        idPolygonModelCollisionDetection::StartTranslation(
          tw: v52,
          result: &v95,
          contacts: nullptr,
          start: start->mat,
          end,
          trm: *v53,
          trmAxis: (const idMat3 *)a30,
          contentMask: (int)a32,
          modelOrigin: v66->mat,
          modelAxis: v69);
        idPolygonModelCollisionDetection::TraceThroughModel(tw: v52, model: (const cm_polygonModel_t *)(v55 + 84));
        idPolygonModelCollisionDetection::FinishTranslation(
          tw: v52,
          start: start->mat,
          end,
          modelOrigin: (const idVec3 *)(v54 - 56),
          modelAxis: (const idMat3 *)(v54 - 44),
          modelEntityNum: *(_DWORD *)(v54 - 8),
          modelPhysicsId: *(_DWORD *)(v54 - 4),
          modelBodyId: *(_DWORD *)v54,
          selfId: v67,
          modelContentsOverride: v70);
      }
      if ( v95.fraction < (double)v94.fraction )
        trace_t::operator=(this: &v94, __that: &v95);
LABEL_28:
      --v46;
      v54 += 80;
    }
    while ( v46 != 0 );
    v46 = numTrmsa;
    v50 = a28;
LABEL_30:
    ++v51;
    ++v53;
  }
  while ( v51 < v50 );
LABEL_31:
  v96.fraction = 2.0;
  v57 = 0;
  if ( v50 > 0 )
  {
    v58 = (const idMat3 **)trms;
    while ( 1 )
    {
      if ( v46 > 0 )
      {
        v59 = v46;
        v60 = a34 + 64;
        do
        {
          v61 = *(_DWORD *)(v60 - 64);
          if ( (*(int (__fastcall **)(int))(*(_DWORD *)v61 + 28))(a1: v61) != 0 )
          {
            (*(void (__fastcall **)(int))(*(_DWORD *)v61 + 28))(a1: v61);
          }
          else
          {
            idPolygonModelCollisionDetection::StartRotation(
              tw: v52,
              result: &v95,
              rorg: &v94.endpos,
              axis: &rotation->vec,
              angle: rotation->angle,
              start: v62,
              trm: (const idTraceModel *)&v94.endpos,
              trmAxis: *v58,
              contentMask: a30,
              modelOrigin: v66->mat,
              modelAxis: v69);
            idPolygonModelCollisionDetection::TraceThroughModel(tw: v52, model: (const cm_polygonModel_t *)(v61 + 84));
            idPolygonModelCollisionDetection::FinishRotation(
              tw: v52,
              rorg: &v94.endpos,
              axis: &rotation->vec,
              angle: rotation->angle,
              start: *(const idVec3 **)(v60 - 8),
              trmAxis: (const idMat3 *)&v94.endpos,
              modelOrigin: (const idVec3 *)a30,
              modelAxis: (const idMat3 *)(v60 - 56),
              modelEntityNum: v60 - 44,
              modelPhysicsId: v68,
              modelBodyId: v71,
              selfId: (int)v72,
              modelContentsOverride: v73);
            if ( v95.fraction < (double)v96.fraction )
              trace_t::operator=(this: &v96, __that: &v95);
          }
          --v59;
          v60 += 80;
        }
        while ( v59 != 0 );
      }
      ++v57;
      ++v58;
      if ( v57 >= a28 )
        break;
      v46 = numTrmsa;
    }
  }
  idCollisionDetectionMerge::MergeMotionResults(result: a3, rotation: &v96, translation: &v94);
  LODWORD(v63) = 0;
  *(_QWORD *)this = v63;
_M231092:
  idPLogScope::~idPLogScope(this: &v93);
  return this;
}


// ========================================================================
// __unwind$230942
// EA  : 0x825D992C
// RVA : 0x005D992C
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void _unwind_230942()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 704 + 136));
}


// ========================================================================
// ?MotionContacts@idCollisionModelManager@@QAA?AVidCollisionQuery@@PAUtrace_t@@PAUcontactsResult_t@@ABVidVec3@@2ABVidRotation@@MABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825D9958
// RVA : 0x005D9958
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionModelManager *__fastcall idCollisionModelManager::MotionContacts(
        idCollisionModelManager *this,
        idCollisionQuery *result,
        trace_t *a3,
        contactsResult_t *contacts,
        const idMat3 *start,
        const idVec3 *end,
        idRotation *rotation,
        double depth,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        const int numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        idBounds *a29,
        int a30,
        const idTraceModel **a31,
        int a32,
        const idMat3 *a33,
        int a34,
        int a35,
        int a36,
        const idBounds *globalBounds_0,
        int a38,
        const idTraceModel **trmsa,
        int a40,
        int numTrmsa)
{
  __int64 v45; // r29
  const idMat3 *v47; // [sp+8h] [-E8h]
  const idMat3 *v48; // [sp+8h] [-E8h]
  const idMat3 *v49; // [sp+Ch] [-E4h]
  int v50; // [sp+Ch] [-E4h]
  const idPositionedCollisionModel *v51; // [sp+10h] [-E0h]
  const idPositionedCollisionModel *v52; // [sp+10h] [-E0h]
  const idPositionedCollisionModel *v53; // [sp+14h] [-DCh]
  int v54; // [sp+14h] [-DCh]
  const char *v55; // [sp+18h] [-D8h]
  const char *v56; // [sp+18h] [-D8h]
  const char *v57; // [sp+1Ch] [-D4h]
  int v58; // [sp+1Ch] [-D4h]
  int v59; // [sp+20h] [-D0h]
  int v60; // [sp+20h] [-D0h]
  int v61; // [sp+24h] [-CCh]
  int v62; // [sp+24h] [-CCh]
  int v63; // [sp+28h] [-C8h]
  int v64; // [sp+28h] [-C8h]
  int v65; // [sp+2Ch] [-C4h]
  int v66; // [sp+2Ch] [-C4h]
  int v67; // [sp+30h] [-C0h]
  int v68; // [sp+30h] [-C0h]
  int v69; // [sp+34h] [-BCh]
  int v70; // [sp+34h] [-BCh]
  int v71; // [sp+38h] [-B8h]
  int v72; // [sp+38h] [-B8h]
  int v73; // [sp+3Ch] [-B4h]
  int v74; // [sp+3Ch] [-B4h]
  int v75; // [sp+40h] [-B0h]
  int v76; // [sp+40h] [-B0h]
  int v77; // [sp+44h] [-ACh]
  int v78; // [sp+44h] [-ACh]
  int v79; // [sp+48h] [-A8h]
  int v80; // [sp+48h] [-A8h]
  int v81; // [sp+4Ch] [-A4h]
  int v82; // [sp+4Ch] [-A4h]
  int v83; // [sp+50h] [-A0h]
  int v84; // [sp+50h] [-A0h]
  int v85; // [sp+58h] [-98h]
  int v86; // [sp+58h] [-98h]
  int v87; // [sp+60h] [-90h]
  int v88; // [sp+60h] [-90h]
  int v89; // [sp+68h] [-88h]
  int v90; // [sp+68h] [-88h]
  int v91; // [sp+70h] [-80h]
  int v92; // [sp+70h] [-80h]
  idCollisionModelManager v93[8]; // [sp+80h] [-70h] BYREF

  HIDWORD(v45) = result;
  if ( a3 != nullptr )
  {
    LODWORD(v45) = 0;
    idCollisionModelManager::Motion(
      this: v93,
      result,
      a3,
      start,
      end,
      rotation,
      globalBounds: a29,
      trms: a31,
      numTrms: (const int)v47,
      trmAxis: v49,
      contentMask: (const int)v51,
      models: v53,
      numModels: (const int)v55,
      userName: v57,
      a15: v59,
      a16: v61,
      a17: v63,
      a18: v65,
      a19: v67,
      a20: v69,
      a21: v71,
      a22: v73,
      a23: v75,
      a24: v77,
      a25: v79,
      a26: v81,
      a27: v83,
      a28: (int)a33,
      a29: v85,
      a30: a35,
      a31: v87,
      a32: globalBounds_0->b,
      a33: v89,
      a34: (int)trmsa,
      a35: v91,
      numTrmsa);
    idCollisionModelManager::Contacts(
      this: v93,
      result: (idCollisionQuery *)HIDWORD(v45),
      a3: contacts,
      start: &a3->endpos,
      dir: &vec3_origin,
      depth,
      globalBounds: (const idBounds *)&a3->endAxis,
      trms: (const idTraceModel **)a29,
      a9: (const int)a31,
      trmAxis: v48,
      contentMask: v50,
      models: v52,
      numModels: v54,
      userName: v56,
      a15: v58,
      a16: v60,
      a17: v62,
      a18: v64,
      a19: v66,
      a20: v68,
      a21: v70,
      a22: v72,
      a23: v74,
      a24: v76,
      a25: v78,
      a26: v80,
      a27: v82,
      a28: v84,
      a29: a33,
      a30: v86,
      a31: (int)&a3->endAxis,
      a32: v88,
      a33: globalBounds_0,
      a34: v90,
      a35: (int)trmsa,
      a36: v92,
      numTrms_0: numTrmsa);
    *(_QWORD *)this = v45;
  }
  else
  {
    idCollisionQueryJobManager::SubmitMotionContactsQuery(
      (idCollisionQueryJobManager *)this,
      result: (idCollisionQuery *)&cdQuery,
      start: start->mat,
      end,
      rotation,
      depth,
      globalBounds: (const idBounds *)trmsa,
      trms: (const idTraceModel **)a29,
      numTrms: (const int)a31,
      trmAxis: v47,
      contentMask: (int)v49,
      models: v51,
      numModels: (int)v53,
      userName: v55);
  }
  return this;
}


// ========================================================================
// `dynamic initializer for 'cdQuery''
// EA  : 0x833352E8
// RVA : 0x013352E8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

idCollisionQueryJobManager *_dynamic_initializer_for__cdQuery__()
{
  return idCollisionQueryJobManager::idCollisionQueryJobManager(this: &cdQuery);
}


// ========================================================================
// `dynamic initializer for 'cm_showStreamedData''
// EA  : 0x833352F8
// RVA : 0x013352F8
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_showStreamedData__()
{
  idCVar::idCVar(
    this: &cm_showStreamedData,
    name: "cm_showStreamedData",
    value: "0",
    flags: 2,
    description: "1 = show all, 2 = show loaded or streamed, 3 = show streamed",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))byte_821B0000,
    a9: (int)&loc_825D0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,3>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_showStreamedData__);
}


// ========================================================================
// `dynamic initializer for 'cm_showCollisionModelMaterial''
// EA  : 0x83335360
// RVA : 0x01335360
// PDB : w:\tech5\engine\cm\collisionmodelmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_showCollisionModelMaterial__()
{
  idCVar::idCVar(
    this: &cm_showCollisionModelMaterial,
    name: "cm_showCollisionModelMaterial",
    value: "textures/common/flatShadeTwoSidedDimRed",
    flags: 0,
    description: "Material to use when debug rendering collisionmodel",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_showCollisionModelMaterial__);
}

