
// ========================================================================
// ?PackMaterials@idMaterial@@SAPBV1@PBDABV?$idList@PBVidMaterial@@$04@@I@Z
// EA  : 0x82939280
// RVA : 0x00939280
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
const idMaterial *__fastcall idMaterial::PackMaterials(
        char *name,
        const idList<idMaterial const *,5> *materials,
        unsigned int skinFileTimeStamp)
{
  char v3; // r19
  __int64 v5; // r10
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r3
  int size; // r11
  int num; // r30
  bool v12; // cr56
  signed int v13; // r27
  int v14; // r26
  imageProperties_t *list; // r29
  int v16; // r28
  int *p_y; // r30
  idMaterial *v18; // r24
  int *v19; // r30
  int v20; // r20
  int width; // r10
  int x; // r11
  int v23; // r22
  int v24; // r19
  int v25; // r23
  int v26; // r18
  int v27; // r24
  int v28; // ctr
  int v29; // r14
  int i; // r21
  int v31; // r28
  int v32; // r26
  int v33; // r25
  int v34; // r6
  int v35; // r5
  int v36; // r29
  int v37; // r30
  int v38; // r11
  int v39; // r3
  int *v40; // r11
  int v41; // r7
  int v42; // r8
  int *v43; // r11
  int v44; // r10
  idMaterialMap *v45; // r3
  idMaterialMap *v46; // r28
  int v47; // r11
  char v48; // r17
  char v49; // r16
  char v50; // r18
  char v51; // r15
  int *v52; // r29
  idCollisionModelLocal *v53; // r30
  __int64 v54; // r9 OVERLAPPED
  __int128 v55; // r7 OVERLAPPED
  __int64 v56; // fp12
  __int64 v57; // fp13
  int height; // r10
  double v59; // fp13
  double v60; // fp12
  const char *String; // r3
  const char *v62; // r3
  const char *v63; // r3
  const char *v64; // r3
  const char *v65; // r3
  bool v66; // r11
  __int64 v67; // r8
  __int64 v68; // r6
  __int64 v69; // r10
  va *v70; // r3
  va *v71; // r29
  size_t j; // r30
  int v73; // r4
  int v74; // r11
  int v75; // r27
  int v76; // r26
  idMaterialMapping *v77; // r30
  idMaterialMapping *v78; // r4
  idDecl *v79; // r30
  idDecl *v80; // r30
  __int64 v81; // r7
  double v82; // r4
  int v84; // [sp+8h] [-1328h]
  int v85; // [sp+Ch] [-1324h]
  int v86; // [sp+10h] [-1320h]
  int v87; // [sp+14h] [-131Ch]
  int v88; // [sp+18h] [-1318h]
  int v89; // [sp+1Ch] [-1314h]
  int *p_x; // [sp+50h] [-12E0h]
  __int64 v91; // [sp+58h] [-12D8h] BYREF
  __int64 v92; // [sp+60h] [-12D0h] BYREF
  idList<idSWF::imageToPack_t,72> v93; // [sp+70h] [-12C0h] BYREF
  __int64 v94; // [sp+80h] [-12B0h]
  unsigned __int64 v95; // [sp+88h] [-12A8h]
  idSort_Quick<imageProperties_t,idSort_ImageProperties> v96; // [sp+90h] [-12A0h] BYREF
  __int64 v97; // [sp+98h] [-1298h]
  int v98; // [sp+A0h] [-1290h]
  idStr v99; // [sp+B0h] [-1280h] BYREF
  idMaterialMapping v100; // [sp+D0h] [-1260h] BYREF
  __int64 v101; // [sp+128h] [-1208h]
  __int64 v102; // [sp+130h] [-1200h]
  __int64 v103; // [sp+138h] [-11F8h]
  idFile_Memory v104; // [sp+140h] [-11F0h] BYREF
  va v105; // [sp+290h] [-10A0h] BYREF

  v3 = 0;
  memset(&v93, 0, 14);
  *(_WORD *)&v93.memTag = 11776;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v93);
  v9 = Sys_Milliseconds();
  size = v93.size;
  num = materials->num;
  v98 = v9;
  v12 = num < v93.size;
  if ( num > v93.size )
  {
    if ( !idList<HQDXTjob_t,34>::Resize(this: &v93, newsize: num) )
    {
      v13 = v93.num;
      goto LABEL_8;
    }
    size = v93.size;
    v12 = num < v93.size;
  }
  if ( v12 )
  {
    v13 = num;
    v93.num = num;
  }
  else
  {
    v13 = size;
    v93.num = size;
  }
LABEL_8:
  v14 = 0;
  list = (imageProperties_t *)v93.list;
  if ( materials->num > 0 )
  {
    v16 = 0;
    p_y = &v93.list[-1].allocSize.y;
    do
    {
      v18 = materials->list[v16];
      idMaterial::GetImageDimensions(this: v18, width: (int *)&v92, height: (int *)&v91);
      p_y[1] = (int)v18;
      p_y[2] = 0;
      ++v14;
      p_y[3] = 0;
      ++v16;
      LODWORD(v5) = HIDWORD(v92);
      p_y[4] = HIDWORD(v92);
      HIDWORD(v5) = HIDWORD(v91);
      p_y[5] = HIDWORD(v91);
      v6 = HIDWORD(v91);
      v7 = HIDWORD(v92);
      v8 = HIDWORD(v92) * HIDWORD(v91);
      p_y += 6;
      *p_y = HIDWORD(v92) * HIDWORD(v91);
    }
    while ( v14 < materials->num );
  }
  v96.__vftable = (idSort_Quick<imageProperties_t,idSort_ImageProperties>_vtbl *)&idSort_ImageProperties::`vftable';
  if ( list != nullptr )
    idSort_Quick<imageProperties_t,idSort_ImageProperties>::Sort(
      this: &v96,
      base: list,
      num: v13,
      a4: v8,
      a5: v7,
      a6: v6,
      a7: v5);
  v19 = &list->y;
  p_x = &list->x;
  HIDWORD(v95) = &list->y;
  v20 = 1;
  v96.__vftable = (idSort_Quick<imageProperties_t,idSort_ImageProperties>_vtbl *)&idSort<imageProperties_t>::`vftable';
  list->x = 0;
  list->y = 0;
  width = list->width;
  x = list->x;
  HIDWORD(v91) = list->height;
  v23 = width + x;
  if ( v13 > 1 )
  {
    HIDWORD(v94) = &list->y;
    do
    {
      v24 = 0;
      v25 = 0x8000;
      v26 = 0;
      v27 = 0x8000;
      if ( v20 > 0 )
      {
        v28 = v20;
        v29 = *(_DWORD *)(HIDWORD(v94) + 28);
        HIDWORD(v92) = p_x;
        do
        {
          for ( i = 0; i < 4; ++i )
          {
            v31 = 0;
            v32 = (i & 1) * *(_DWORD *)(HIDWORD(v92) + 8) + *(_DWORD *)HIDWORD(v92);
            v33 = ((i >> 1) & 1) * *(_DWORD *)(HIDWORD(v92) + 12) + *(_DWORD *)(HIDWORD(v92) + 4);
            do
            {
              v34 = ((16 * v31) & 0x10) + v32;
              v35 = ((16 * (v31 >> 1)) & 0x10) + v33;
              v36 = v23;
              if ( v23 <= v29 + v34 )
                v36 = v29 + v34;
              v37 = HIDWORD(v91);
              v38 = *(_DWORD *)(HIDWORD(v94) + 32);
              v39 = v38 + v35;
              if ( SHIDWORD(v91) <= v38 + v35 )
                v37 = v38 + v35;
              if ( v37 * v36 < v25 * v27 )
              {
                v40 = p_x;
                v41 = 0;
                while ( 1 )
                {
                  if ( v29 + v34 + 16 > *v40 )
                  {
                    v42 = v40[1];
                    if ( v39 + 16 > v42 && v34 < v40[2] + *v40 + 16 && v35 < v40[3] + v42 + 16 )
                      break;
                  }
                  ++v41;
                  v40 += 6;
                  if ( v41 >= v20 )
                    goto LABEL_32;
                }
                if ( v41 < v20 )
                  goto LABEL_33;
LABEL_32:
                v24 = ((16 * v31) & 0x10) + v32;
                v26 = ((16 * (v31 >> 1)) & 0x10) + v33;
                v27 = v36;
                v25 = v37;
              }
LABEL_33:
              ++v31;
            }
            while ( v31 < 4 );
          }
          HIDWORD(v92) += 24;
          --v28;
        }
        while ( v28 != 0 );
      }
      v43 = (int *)HIDWORD(v94);
      ++v20;
      v44 = v93.num;
      v23 = v27;
      HIDWORD(v91) = v25;
      *(_DWORD *)(HIDWORD(v94) + 20) = v24;
      v43 += 6;
      *v43 = v26;
      HIDWORD(v94) = v43;
    }
    while ( v20 < v44 );
    v19 = (int *)HIDWORD(v95);
    v3 = 0;
    v13 = v44;
  }
  v45 = (idMaterialMap *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x3Cu,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  HIDWORD(v95) = v45;
  if ( v45 != nullptr )
    v46 = idMaterialMap::idMaterialMap(this: v45);
  else
    v46 = nullptr;
  idStr::operator=(this: &v46->name, text: name);
  v47 = HIDWORD(v91);
  v48 = 0;
  v46->width = v23;
  v49 = 0;
  v50 = 0;
  v46->height = v47;
  v51 = 0;
  if ( v13 > 0 )
  {
    v52 = v19 - 4;
    do
    {
      v53 = (idCollisionModelLocal *)v52[2];
      v100.coverFile.timeStamp = 0;
      v100.powerFile.timeStamp = 0;
      v100.diffuseFile.timeStamp = 0;
      v100.specularFile.timeStamp = 0;
      v100.bumpFile.timeStamp = 0;
      v100.powerFile.fileName.str = &byte_8200D768;
      v100.diffuseFile.fileName.str = &byte_8200D768;
      v100.specularFile.fileName.str = &byte_8200D768;
      v100.coverFile.fileName.str = &byte_8200D768;
      v100.materialName.str = &byte_8200D768;
      v100.bumpFile.fileName.str = &byte_8200D768;
      idAtomicString::Set(this: &v100.materialName, str_: v53->name.str);
      v100.materialChecksum = idLexer::GetScriptP(this: v53);
      v100.materialTimestamp = v53->GetModelType(this: v53);
      v53 = (idCollisionModelLocal *)((char *)v53 + 84);
      v100.x = v52[3];
      LODWORD(v54) = v100.x;
      v100.y = v52[4];
      HIDWORD(v54) = v100.y;
      LODWORD(v55) = v52[5];
      v56 = v55;
      v100.width = v55;
      v92 = v55;
      v52 += 6;
      DWORD2(v55) = *v52;
      v57 = *(_QWORD *)((char *)&v55 + 4);
      v100.height = *v52;
      v91 = *(_QWORD *)((char *)&v55 + 4);
      DWORD1(v55) = v46->width;
      v95 = __PAIR64__((unsigned int)v53, DWORD1(v55));
      v94 = v54;
      v101 = *(__int64 *)((char *)&v54 + 4);
      v100.scaleBias.x = (float)v56 / (float)__SPAIR64__((unsigned int)v53, DWORD1(v55));
      height = v46->height;
      v103 = *(__int64 *)((char *)&v54 - 4);
      v60 = (double)*(__int64 *)((char *)&v54 + 4);
      v100.scaleBias.y = (float)v57 / (float)*(__int64 *)((char *)&v54 - 4);
      v59 = (double)v54;
      HIDWORD(v54) = v46->width;
      v102 = *(__int64 *)((char *)&v54 + 4);
      v100.scaleBias.z = (float)v59 / (float)*(__int64 *)((char *)&v54 + 4);
      DWORD2(v55) = v46->height;
      v97 = *(_QWORD *)((char *)&v55 + 4);
      v100.scaleBias.w = (float)v60 / (float)*(__int64 *)((char *)&v55 + 4);
      String = idParmBlock::GetString(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_bumpMap_0.r);
      idAtomicString::Set(this: &v100.bumpFile.fileName, str_: String);
      v62 = idParmBlock::GetString(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_diffuseMap_0.r);
      idAtomicString::Set(this: &v100.diffuseFile.fileName, str_: v62);
      v63 = idParmBlock::GetString(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_specularMap_0.r);
      idAtomicString::Set(this: &v100.specularFile.fileName, str_: v63);
      v64 = idParmBlock::GetString(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_powerMap_0.r);
      idAtomicString::Set(this: &v100.powerFile.fileName, str_: v64);
      v65 = idParmBlock::GetString(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_coverMap_0.r);
      idAtomicString::Set(this: &v100.coverFile.fileName, str_: v65);
      v48 |= idParmBlock::SetsRenderParm(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_diffuseMap_0.r);
      v3 |= idParmBlock::SetsRenderParm(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_specularMap_0.r);
      v49 |= idParmBlock::SetsRenderParm(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_bumpMap_0.r);
      v50 |= idParmBlock::SetsRenderParm(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_coverMap_0.r);
      v66 = idParmBlock::SetsRenderParm(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_powerMap_0.r);
      v51 |= idParmBlock::SetsRenderParm(this: (idParmBlock *)v53, parm: (const idDeclRenderParm *)rp_powerMip.r) || v66;
      idList<idMaterialMapping,46>::Append(this: &v46->mappings, obj: &v100);
      --v13;
    }
    while ( v13 != 0 );
  }
  idStr::idStr(this: &v99, text: name);
  idStr::Replace(this: &v99, old: "/", nw: &byte_8200D768);
  idStr::Replace(this: &v99, old: "\\", nw: &byte_8200D768);
  LODWORD(v67) = "Mips";
  HIDWORD(v68) = v99.data;
  v70 = va::va(
          this: &v105,
          fmt: "generated/skins/m2/%s.m2",
          a3: v68,
          a4: v67,
          a5: v69,
          a6: v84,
          a7: v85,
          a8: v86,
          a9: v87,
          a10: v88,
          a11: v89);
  v71 = v70;
  for ( j = 0; v70->buffer[j] != 0; ++j )
    ;
  v73 = j + 1;
  v74 = v99.allocedAndFlag & 0x7FFFFFFF;
  if ( v99.allocedAndFlag >= 0 )
  {
    if ( v73 > v74 )
      idStr::ReAllocate(this: &v99, amount: v73, keepold: false);
  }
  else if ( v73 > v74
         && AssertFailed(
              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
              line: 463,
              expression: "amount <= GetAlloced()",
              inlineBreak: true) )
  {
    __trap();
  }
  memcpy(Dst: v99.data, Src: v71, Size: j);
  v99.data[j] = 0;
  v99.len = j;
  idFile_Memory::idFile_Memory(this: &v104);
  idFile::Printf(this: &v104, fmt: "{\n");
  idFile::Printf(this: &v104, fmt: "\tmaterialmap\n");
  idFile::Printf(this: &v104, fmt: "\t{\n");
  idFile::Printf(this: &v104, fmt: "\t\t\"%s\"\n", v46->name.data);
  idFile::Printf(this: &v104, fmt: "\t\t%d %d %d\n", v46->width, v46->height, skinFileTimeStamp);
  v75 = 0;
  if ( v46->mappings.num > 0 )
  {
    v76 = 0;
    do
    {
      v77 = &v46->mappings.list[v76];
      idFile::Printf(this: &v104, fmt: "\t\t{\n");
      idFile::Printf(
        this: &v104,
        fmt: "\t\t\t\"%s\" %d %d\n",
        v77->materialName.str,
        v77->materialChecksum,
        v77->materialTimestamp);
      idFile::Printf(this: &v104, fmt: "\t\t\t%d %d %d %d\n", v77->x, v77->y, v77->width, v77->height);
      idFile::Printf(this: &v104, fmt: "\t\t\t\"%s\" %d\n", v77->specularFile.fileName.str, v77->specularFile.timeStamp);
      idFile::Printf(this: &v104, fmt: "\t\t\t\"%s\" %d\n", v77->coverFile.fileName.str, v77->coverFile.timeStamp);
      idFile::Printf(this: &v104, fmt: "\t\t\t\"%s\" %d\n", v77->diffuseFile.fileName.str, v77->diffuseFile.timeStamp);
      idFile::Printf(this: &v104, fmt: "\t\t\t\"%s\" %d\n", v77->bumpFile.fileName.str, v77->bumpFile.timeStamp);
      idFile::Printf(this: &v104, fmt: "\t\t\t\"%s\" %d\n", v77->powerFile.fileName.str, v77->powerFile.timeStamp);
      idFile::Printf(this: &v104, fmt: "\t\t}\n");
      ++v75;
      ++v76;
    }
    while ( v75 < v46->mappings.num );
  }
  idFile::Printf(this: &v104, fmt: "\t}\n");
  if ( v3 != 0 )
    idFile::Printf(this: &v104, fmt: "\tspecularmap\t\t\tgenerated/skins/textures/%s_specular.tga\n", name);
  if ( v50 != 0 )
    idFile::Printf(this: &v104, fmt: "\tcovermap\t\t\tgenerated/skins/textures/%s_cover.tga\n", name);
  if ( v48 != 0 )
    idFile::Printf(this: &v104, fmt: "\tdiffusemap\t\t\tgenerated/skins/textures/%s_diffuse.tga\n", name);
  if ( v49 != 0 )
    idFile::Printf(this: &v104, fmt: "\tbumpmap\t\t\t\tgenerated/skins/textures/%s_bump.tga\n", name);
  if ( v51 != 0 )
    idFile::Printf(this: &v104, fmt: "\tpowermap\t\t\tgenerated/skins/textures/%s_power.tga\n", name);
  idFile::Printf(this: &v104, fmt: "}\n");
  HIDWORD(v95) = v46;
  if ( v46->mappings.listStatic == 0 || v46->mappings.listStatic == 2 )
  {
    v78 = v46->mappings.list;
    if ( v78 != nullptr )
    {
      HIDWORD(v91) = v46->mappings.list;
      idMem::Free(this: &mem, ptr: v78, align: ALIGN_16);
    }
    v46->mappings.list = nullptr;
    v46->mappings.size = 0;
  }
  v46->mappings.num = 0;
  idStr::FreeData(this: &v46->name);
  idMem::Free(this: &mem, ptr: v46, align: ALIGN_16);
  if ( name != nullptr )
    v79 = (idDecl *)idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name, makeDefault: false);
  else
    v79 = nullptr;
  if ( v79 != nullptr )
  {
    idDecl::SetText(this: v79, text: v104.filePtr, length: 0);
    idDecl::ReplaceSourceFileText(this: v79, useSourceControl: false);
    idDecl::ReParse(this: v79, fromDisk: true);
  }
  else
  {
    v80 = declManager->CreateNewDecl(
            this: declManager,
            a2: &idMaterial::resourceList,
            a3: name,
            a4: v99.data,
            a5: v104.filePtr);
    idDecl::ReplaceSourceFileText(this: v80, useSourceControl: false);
    idResourceList::Remove(this: &idMaterial::resourceList, ptr: v80);
    if ( v80 != nullptr )
      ((void (__fastcall *)(idDecl *, int))v80->dtr_idResource)(a1: v80, a2: 1);
    v79 = (idDecl *)idResourceList::Load(
                      this: &idMaterial::resourceList,
                      name,
                      makeDefault: true,
                      skipStaleCheck: false);
  }
  LODWORD(v81) = Sys_Milliseconds() - v98;
  v97 = v81;
  v82 = (float)((float)v81 * (float)0.001);
  idLib::Printf(fmt: (const char *)HIDWORD(v82), LODWORD(v82), name);
  idFile_Memory::~idFile_Memory(this: &v104);
  idStr::FreeData(this: &v99);
  if ( v93.listStatic == 0 || v93.listStatic == 2 )
    idMem::Free(this: &mem, ptr: v93.list, align: ALIGN_16);
  return (const idMaterial *)v79;
}


// ========================================================================
// __unwind$231034
// EA  : 0x82939DB0
// RVA : 0x00939DB0
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _unwind_231034()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4912 + 112));
}


// ========================================================================
// __unwind$231035
// EA  : 0x82939DD8
// RVA : 0x00939DD8
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _unwind_231035()
{
  int v0; // r12

  idSort_ImageProperties::~idSort_ImageProperties(this: (idSort_ImageProperties *)(v0 - 4912 + 144));
}


// ========================================================================
// __unwind$231036_0
// EA  : 0x82939E00
// RVA : 0x00939E00
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _unwind_231036_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4912 + 136), tag: TAG_DECL);
}


// ========================================================================
// __unwind$231038_0
// EA  : 0x82939E2C
// RVA : 0x00939E2C
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _unwind_231038_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4912 + 176));
}


// ========================================================================
// __unwind$231039_0
// EA  : 0x82939E54
// RVA : 0x00939E54
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _unwind_231039_0()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 4912 + 320));
}


// ========================================================================
// __unwind$231563_0
// EA  : 0x82939E7C
// RVA : 0x00939E7C
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _unwind_231563_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4912 + 136));
}


// ========================================================================
// `dynamic initializer for 'rp_diffuseMap''_0
// EA  : 0x83358268
// RVA : 0x01358268
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_diffuseMap___0()
{
  rp_diffuseMap_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_diffuseMap_0;
}


// ========================================================================
// `dynamic initializer for 'rp_specularMap''_0
// EA  : 0x83358288
// RVA : 0x01358288
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_specularMap___0()
{
  rp_specularMap_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_specularMap_0;
}


// ========================================================================
// `dynamic initializer for 'rp_bumpMap''_0
// EA  : 0x833582A8
// RVA : 0x013582A8
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_bumpMap___0()
{
  rp_bumpMap_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_bumpMap_0;
}


// ========================================================================
// `dynamic initializer for 'rp_powerMap''_0
// EA  : 0x833582C8
// RVA : 0x013582C8
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_powerMap___0()
{
  rp_powerMap_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_powerMap_0;
}


// ========================================================================
// `dynamic initializer for 'rp_coverMap''_0
// EA  : 0x833582E8
// RVA : 0x013582E8
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_coverMap___0()
{
  rp_coverMap_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_coverMap_0;
}


// ========================================================================
// `dynamic initializer for 'rp_powerMip''
// EA  : 0x83358308
// RVA : 0x01358308
// PDB : w:\tech5\engine\renderer\materialmapgenerator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_powerMip__()
{
  rp_powerMip.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_powerMip;
}

