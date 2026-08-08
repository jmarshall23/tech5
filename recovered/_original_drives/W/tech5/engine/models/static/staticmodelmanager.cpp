
// ========================================================================
// ?AddStaticModel@idStaticModelManagerLocal@@UAAXPAVidStaticModel@@@Z
// EA  : 0x82874E88
// RVA : 0x00874E88
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void __fastcall idStaticModelManagerLocal::AddStaticModel(idStaticModelManagerLocal *this, idResourceList_vtbl *model)
{
  BYTE1(model[3].dtr_idResourceList) = 0;
  idResourceList::Add(this: &idStaticModel::resourceList, ptr: model);
}


// ========================================================================
// ?ReloadModels@idStaticModelManagerLocal@@UAAXXZ
// EA  : 0x82874EA0
// RVA : 0x00874EA0
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void __fastcall idStaticModelManagerLocal::ReloadModels(idStaticModelManagerLocal *this)
{
  __int64 v1; // r10
  double v2; // fp31
  double v3; // r4

  idLib::Printf(fmt: "Reloading models...\n");
  LODWORD(v1) = Sys_Milliseconds();
  v2 = (float)v1;
  renderSystem->SyncRenderThread(this: renderSystem, a2: false);
  renderSystem->InhibitEndFrameRendering(this: renderSystem, a2: 1);
  if ( idResourceList::ReloadStaleResources(this: &idStaticModel::resourceList)
    || idResourceList::ReloadStaleResources(this: &idMD6Model::resourceList) )
  {
    renderSystem->RegenerateReferences(this: renderSystem);
  }
  renderSystem->InhibitEndFrameRendering(this: renderSystem, a2: -1);
  v3 = (float)((float)((float)__SPAIR64__(&off_82040000, Sys_Milliseconds()) - (float)v2) * (float)0.001);
  idLib::Printf(fmt: (const char *)HIDWORD(v3), LODWORD(v3));
}


// ========================================================================
// ?ReloadModels_f@idStaticModelManagerLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82875020
// RVA : 0x00875020
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void __fastcall idStaticModelManagerLocal::ReloadModels_f(const idCmdArgs *args)
{
  idStaticModelManagerLocal::ReloadModels(this: &localModelManager);
}


// ========================================================================
// ?CalculateStats@idStaticModelManagerLocal@@UAAXAAUidStats@idStaticModelManager@@@Z
// EA  : 0x82875030
// RVA : 0x00875030
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void __fastcall idStaticModelManagerLocal::CalculateStats(
        idStaticModelManagerLocal *this,
        idStaticModelManager::idStats *stats)
{
  int v3; // r28
  idStaticModel *v4; // r30
  int v5; // r3
  int v6; // r10
  int v7; // r11
  int totalVerts; // r7
  int totalTriangles; // r8
  idStaticModelSurface *v10; // r3

  stats->totalCPUMem = 0;
  stats->totalGPUMem = 0;
  v3 = 0;
  stats->inUse = 0;
  stats->totalVerts = 0;
  stats->totalTriangles = 0;
  for ( stats->totalSurfaces = 0; v3 < idStaticModel::resourceList.num; ++stats->inUse )
  {
    v4 = (idStaticModel *)idResourceList::Index(this: &idStaticModel::resourceList, index: v3);
    stats->totalCPUMem += idStaticModel::CPUMemory(this: v4);
    v5 = idStaticModel::GPUMemory(this: v4);
    v6 = 0;
    stats->totalGPUMem += v5;
    if ( v4->surfaces.num > 0 )
    {
      v7 = 0;
      do
      {
        ++v6;
        totalVerts = stats->totalVerts;
        totalTriangles = stats->totalTriangles;
        ++stats->totalSurfaces;
        stats->totalVerts = v4->surfaces.list[v7].geometry->numVerts + totalVerts;
        v10 = &v4->surfaces.list[v7++];
        stats->totalTriangles = v10->geometry->numIndexes / 3 + totalTriangles;
      }
      while ( v6 < v4->surfaces.num );
    }
    ++v3;
  }
}


// ========================================================================
// ?ListModels_f@idStaticModelManagerLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82875148
// RVA : 0x00875148
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void __fastcall idStaticModelManagerLocal::ListModels_f(const idCmdArgs *args)
{
  unsigned int v1; // r17
  int v2; // r16
  int v3; // r28
  int v4; // r27
  int v5; // r29
  unsigned __int8 v6; // r30
  char *v7; // r11
  const char *v8; // r10
  int v9; // r9
  int v10; // r9
  bool v11; // zf
  int v12; // r20
  int v13; // r23
  int v14; // r26
  idStaticModel *v15; // r3
  idStaticModel *v16; // r30
  int v17; // r10
  int v18; // r11
  idStaticModelSurface *list; // r9
  idTriangles *geometry; // r7
  double v21; // r4
  int num; // [sp+50h] [-B0h]
  idList<idVehicleState *,5> v23[10]; // [sp+60h] [-A0h] BYREF

  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  if ( args->argc > 1 )
  {
    v7 = args->argv[1];
    v8 = "nonworld";
    do
    {
      v9 = (unsigned __int8)*v7;
      v11 = v9 == 0;
      v10 = v9 - *(unsigned __int8 *)v8;
      if ( v11 )
        break;
      ++v7;
      ++v8;
    }
    while ( v10 == 0 );
    if ( v10 == 0 )
      v6 = 1;
  }
  idLib::Printf(fmt: "   gmem srf  verts  index\n");
  idLib::Printf(fmt: "  ----- --- ------ ------\n");
  memset(v23, 0, 14);
  v23[0].memTag = 5;
  v23[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: v23);
  idResourceList::GetLoadedResources(this: &idStaticModel::resourceList, resourceList: v23);
  v12 = 0;
  if ( v23[0].num > 0 )
  {
    v13 = v6;
    v14 = 0;
    do
    {
      v15 = (idStaticModel *)_RTDynamicCast(
                               inptr: v23[0].list[v14],
                               VfDelta: 0,
                               SrcType: &idResource `RTTI Type Descriptor',
                               TargetType: &idStaticModel `RTTI Type Descriptor',
                               isReference: 0);
      v16 = v15;
      if ( v13 == 0 || strstr(str1: v15->name.str, str2: "_area") == nullptr )
      {
        v16->List(this: v16);
        v1 += idStaticModel::GPUMemory(this: v16);
        v17 = 0;
        num = v16->surfaces.num;
        if ( num > 0 )
        {
          v18 = 0;
          list = v16->surfaces.list;
          do
          {
            geometry = list->geometry;
            ++v17;
            ++v18;
            ++v5;
            list = &v16->surfaces.list[v18];
            v3 += geometry->numVerts;
            v4 += geometry->numIndexes;
          }
          while ( v17 < num );
        }
        ++v2;
      }
      ++v12;
      ++v14;
    }
    while ( v12 < v23[0].num );
  }
  idLib::Printf(fmt: "  ----- --- ------ ------\n");
  idLib::Printf(fmt: "   gmem srf  verts  index\n");
  idLib::Printf(fmt: "%i loaded models\n", v2);
  v21 = (float)((float)__SPAIR64__(&unk_821C0000, v1) * (float)0.00000095367432);
  idLib::Printf(fmt: (const char *)HIDWORD(v21), LODWORD(v21));
  idLib::Printf(fmt: "total Surfaces : %i\n", v5);
  idLib::Printf(fmt: "total Vertices : %i\n", v3);
  idLib::Printf(fmt: "total Indexes  : %i\n", v4);
  if ( (v23[0].listStatic == 0 || v23[0].listStatic == 2) && v23[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v23[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$220168
// EA  : 0x828753C8
// RVA : 0x008753C8
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220168()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 256 + 96));
}


// ========================================================================
// ?FindStaticModel@idStaticModelManagerLocal@@UAAPBVidStaticModel@@PBD_N@Z
// EA  : 0x828753F8
// RVA : 0x008753F8
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

const idStaticModel *__fastcall idStaticModelManagerLocal::FindStaticModel(
        idStaticModelManagerLocal *this,
        char *modelName,
        bool makeDefault)
{
  char *data; // r29
  idResource *v5; // r3
  idResource *v6; // r30
  idStr v8; // [sp+50h] [-B0h] BYREF
  idStr v9; // [sp+70h] [-90h] BYREF
  idStr v10; // [sp+90h] [-70h] BYREF
  idStr v11[2]; // [sp+B0h] [-50h] BYREF

  v8.len = 0;
  data = modelName;
  v8.allocedAndFlag = 20;
  v8.data = v8.baseBuffer;
  v8.baseBuffer[0] = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.len = 0;
  v10.baseBuffer[0] = 0;
  if ( modelName != nullptr && *modelName != 0 )
  {
    idStr::idStr(this: v11, text: modelName);
    if ( idStr::Cmpn(s1: v11[0].data, s2: "maps/", n: 5) == 0 )
    {
      v9.allocedAndFlag = 20;
      v9.len = 0;
      v9.data = v9.baseBuffer;
      v9.baseBuffer[0] = 0;
      idStr::ExtractFileExtension(this: v11, dest: &v9);
      if ( *v9.data == 0 )
      {
        idStr::Append(this: v11, text: ".bmodel");
        data = v11[0].data;
      }
      idStr::FreeData(this: &v9);
    }
    idStr::operator=(this: &v8, text: data);
    idStr::MakeNameCanonical(this: &v8);
    v5 = idResourceList::Load(this: &idStaticModel::resourceList, name: v8.data, makeDefault, skipStaleCheck: false);
    v6 = v5;
    if ( v5 != nullptr && v5->resourceError == nullptr || makeDefault )
    {
      idStr::FreeData(this: v11);
      idStr::FreeData(this: &v10);
      idStr::FreeData(this: &v8);
      return (const idStaticModel *)v6;
    }
    idStr::FreeData(this: v11);
    idStr::FreeData(this: &v10);
  }
  else
  {
    idStr::FreeData(this: &v10);
  }
  idStr::FreeData(this: &v8);
  return nullptr;
}


// ========================================================================
// __unwind$220302
// EA  : 0x82875564
// RVA : 0x00875564
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220302()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$220303
// EA  : 0x8287558C
// RVA : 0x0087558C
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220303()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$220304
// EA  : 0x828755B4
// RVA : 0x008755B4
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220304()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 176));
}


// ========================================================================
// __unwind$220305
// EA  : 0x828755DC
// RVA : 0x008755DC
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220305()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 112));
}


// ========================================================================
// ?Init@idStaticModelManagerLocal@@UAAXXZ
// EA  : 0x82875610
// RVA : 0x00875610
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void __fastcall idStaticModelManagerLocal::Init(idStaticModelManagerLocal *this)
{
  idStaticModelManagerLocal *v1; // r16
  idStaticModel *v2; // r3
  idStaticModel *v4; // r30
  idStaticModel *v5; // r3
  idStaticModel *v6; // r30
  idStaticModel *v7; // r3
  idStaticModel *v8; // r30
  idStaticModel *v9; // r3
  idStaticModel *v10; // r30
  int v11; // r20
  idStaticModel *v16; // r3
  idStaticModel *v17; // r21
  const char *v18; // r4
  idTriangles *v19; // r3
  idTriangles *v20; // r30
  __int64 v22; // r5
  idDrawVert **p_verts; // r11
  int v24; // r8
  float *p_x; // r10
  float *v26; // r10
  float *v27; // r10
  idDrawVert *verts; // r10
  idDrawVert *v29; // r10
  idDrawVert *v30; // r10
  idDrawVert *v31; // r10
  int v35; // r10
  idDrawVert *v42; // r9
  idStaticModelSurface v43; // [sp+70h] [-160h] BYREF
  __int64 v44; // [sp+B8h] [-118h]
  int v45; // [sp+C0h] [-110h] BYREF
  int v46; // [sp+D0h] [-100h] BYREF
  int v47; // [sp+E0h] [-F0h] BYREF
  int v48; // [sp+F0h] [-E0h] BYREF
  int v49; // [sp+100h] [-D0h] BYREF
  idTriangles v50; // [sp+110h] [-C0h] BYREF

  v1 = this;
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listModels",
    a3: idStaticModelManagerLocal::ListModels_f,
    a4: "lists all models",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "reloadModels",
    a3: idStaticModelManagerLocal::ReloadModels_f,
    a4: "reloads models",
    a5: nullptr);
  v2 = (idStaticModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x194u,
                          tag: TAG_STATICMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  LODWORD(_R26) = 0;
  if ( v2 != nullptr )
    v4 = idStaticModel::idStaticModel(this: v2);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: "_default");
  idStaticModel::MakeDefaultModel(this: v4, low: -8.0, high: 8.0);
  v1->AddStaticModel(this: v1, a2: v4);
  v5 = (idStaticModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x194u,
                          tag: TAG_STATICMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idStaticModel::idStaticModel(this: v5);
  else
    v6 = nullptr;
  idResource::SetName(this: v6, _name: "_unitCube");
  idStaticModel::MakeSimpleCube(this: v6, low: -1.0, high: 1.0);
  v1->AddStaticModel(this: v1, a2: v6);
  v7 = (idStaticModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x194u,
                          tag: TAG_STATICMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idStaticModel::idStaticModel(this: v7);
  else
    v8 = nullptr;
  idResource::SetName(this: v8, _name: "_zeroOneCube");
  idStaticModel::MakeSimpleCube(this: v8, low: 0.0, high: 1.0);
  v1->AddStaticModel(this: v1, a2: v8);
  v9 = (idStaticModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x194u,
                          tag: TAG_STATICMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v10 = idStaticModel::idStaticModel(this: v9);
  else
    v10 = nullptr;
  idResource::SetName(this: v10, _name: "_extrudeBox");
  idStaticModel::MakeExtrudeBox(this: v10);
  v1->AddStaticModel(this: v1, a2: v10);
  v11 = -1;
  _R27 = 2;
  HIDWORD(_R26) = 1;
  _R24 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
  _R23 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
  _R22 = &_vmx_3f8000003f8000003f8000003f800000;
  do
  {
    v16 = (idStaticModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x194u,
                             tag: TAG_STATICMODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
    if ( v16 != nullptr )
      v17 = idStaticModel::idStaticModel(this: v16);
    else
      v17 = nullptr;
    if ( v11 == -1 )
      v18 = "_unitSquare";
    else
      v18 = "_zeroOneSquare";
    idResource::SetName(this: v17, _name: v18);
    v19 = (idTriangles *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x84u,
                           tag: TAG_TRIANGLES,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v19 != nullptr )
      v20 = idTriangles::idTriangles(this: v19);
    else
      v20 = nullptr;
    v20->numIndexes = 6;
    v20->numVerts = 4;
    idTriangles::AllocStaticTriSurfVerts(this: v20, numVerts: 4);
    idTriangles::AllocStaticTriSurfIndexes(this: v20, numIndexes: v20->numIndexes);
    *v20->indexes = 3;
    v20->indexes[1] = 0;
    v20->indexes[2] = 2;
    v20->indexes[3] = 2;
    v20->indexes[4] = 0;
    v20->indexes[5] = 1;
    idTriangles::UpdateIndexBuffer(this: v20);
    LODWORD(v22) = v11;
    HIDWORD(v22) = v20->verts;
    p_verts = &v20->verts;
    v44 = v22;
    v24 = 0;
    *(float *)HIDWORD(v22) = (float)v22;
    *(float *)(HIDWORD(v22) + 4) = (float)v22;
    *(float *)(HIDWORD(v22) + 8) = 0.0;
    p_x = &v20->verts->xyz.x;
    p_x[8] = 1.0;
    p_x[9] = (float)v22;
    p_x[10] = 0.0;
    v26 = &v20->verts->xyz.x;
    v26[16] = 1.0;
    v26[17] = 1.0;
    v26[18] = 0.0;
    v27 = &v20->verts->xyz.x;
    v27[24] = (float)v22;
    v27[25] = 1.0;
    v27[26] = 0.0;
    verts = v20->verts;
    verts->st.x = 0.0;
    verts->st.y = 0.0;
    v29 = v20->verts;
    v29[1].st.x = 1.0;
    v29[1].st.y = 0.0;
    v30 = v20->verts;
    v30[2].st.x = 1.0;
    v30[2].st.y = 1.0;
    v31 = v20->verts;
    v31[3].st.x = 0.0;
    v31[3].st.y = 1.0;
    if ( v20->numVerts > 0 )
    {
      __asm { vspltisw128 v59, 0 }
      _R9 = &_real_3f800000;
      _R7 = &_real_00000000;
      _R6 = &v48;
      v35 = 0;
      __asm
      {
        vor128    v60, v91, v59
        lvlx128   v62, r0, r9
        lvlx128   v63, r0, r7
        stvx128   v62, r0, r6
        vrlimi128 v60, v62, 8, 0
      }
      do
      {
        __asm
        {
          vor128    v58, v91, v59
          lvx128    v61, r0, r22
          lvx128    v13, r0, r24
        }
        __asm { lvx128    v0, r0, r23 }
        _R7 = &v49;
        __asm
        {
          vor128    v57, v92, v60
          vrlimi128 v58, v63, 8, 0
        }
        _R6 = &v47;
        _R5 = &v45;
        _R4 = &v46;
        _R9 = (int)(*p_verts)[v35].normal;
        __asm
        {
          stvx128   v63, r0, r7
          vrlimi128 v58, v63, 4, 3
        }
        ++v24;
        __asm
        {
          stvx128   v63, r0, r6
          vrlimi128 v57, v63, 4, 3
          stvx128   v62, r0, r5
          stvx128   v63, r0, r4
          vrlimi128 v58, v62, 2, 2
          vrlimi128 v57, v63, 2, 2
          vaddfp128 v12, v90, v61
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v56, v0, 0
          vpkswss128 v55, v88, v56
          vpkshus128 v0, v87, v55
          stvebx    v0, 0, r9
          stvebx    v0, r9, r25
          stvebx    v0, r9, r27
        }
        __asm { lvx128    v61, r0, r22 }
        __asm
        {
          vaddfp128 v12, v89, v61
          lvx128    v0, r0, r23
          lvx128    v13, r0, r24
        }
        _R9 = (int)(*p_verts)[v35].tangent;
        __asm
        {
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v54, v0, 0
          vpkswss128 v53, v86, v54
          vpkshus128 v0, v85, v53
          stvebx    v0, 0, r9
          stvebx    v0, r9, r25
          stvebx    v0, r9, r27
        }
        v42 = &(*p_verts)[v35];
        v42->color[1] = -1;
        ++v35;
        v42->color[0] = -1;
        v42->color[3] = -1;
        v42->color[2] = -1;
      }
      while ( v24 < v20->numVerts );
      v1 = this;
    }
    v20->bounds = *idTriangles::BoundsFromVertScan(this: &v50, result: &v20->bounds);
    idTriangles::UpdateVertexBuffer(this: v20);
    v43.skinOffsets.x = 0.0;
    v43.materialNum = 0;
    v43.skinOffsets.y = 0.0;
    v43.extraGLState = _R26;
    v43.skinOffsets.z = 0.0;
    v43.geometryIsReference = false;
    v43.skinOffsets.w = 0.0;
    v43.referenceMask = 0;
    memset(&v43.binaryModelId, 0, 16);
    v43.skinRemaps.memTag = 5;
    v43.skinRemaps.listStatic = 0;
    memset(&v43.skinRemaps, 0, 14);
    v43.geometry = v20;
    v43.material = nullptr;
    idStaticModel::AddSurface(this: v17, surf: &v43);
    v1->AddStaticModel(this: v1, a2: v17);
    if ( v43.skinRemaps.listStatic == 0 || v43.skinRemaps.listStatic == 2 )
    {
      if ( v43.skinRemaps.list != nullptr )
        idMem::Free(this: &mem, ptr: v43.skinRemaps.list, align: ALIGN_16);
      v43.skinRemaps.list = nullptr;
      v43.skinRemaps.size = 0;
    }
    ++v11;
    v43.skinRemaps.num = 0;
  }
  while ( v11 <= 0 );
}


// ========================================================================
// __unwind$220519
// EA  : 0x82875CA8
// RVA : 0x00875CA8
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220519()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 84), tag: TAG_STATICMODEL);
}


// ========================================================================
// __unwind$220520
// EA  : 0x82875CD4
// RVA : 0x00875CD4
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220520()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 84), tag: TAG_STATICMODEL);
}


// ========================================================================
// __unwind$220521
// EA  : 0x82875D00
// RVA : 0x00875D00
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220521()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 84), tag: TAG_STATICMODEL);
}


// ========================================================================
// __unwind$220522
// EA  : 0x82875D2C
// RVA : 0x00875D2C
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220522()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 92), tag: TAG_STATICMODEL);
}


// ========================================================================
// __unwind$220523_0
// EA  : 0x82875D58
// RVA : 0x00875D58
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220523_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 88), tag: TAG_STATICMODEL);
}


// ========================================================================
// __unwind$220524
// EA  : 0x82875D84
// RVA : 0x00875D84
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220524()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 88), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$220525
// EA  : 0x82875DB0
// RVA : 0x00875DB0
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void _unwind_220525()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 464 + 112));
}


// ========================================================================
// `dynamic initializer for 'localModelManager''
// EA  : 0x83344F70
// RVA : 0x01344F70
// PDB : w:\tech5\engine\models\static\staticmodelmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__localModelManager__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__localModelManager__);
}

