
// ========================================================================
// ?PristineLoadResource@idStaticModel@@QAAXXZ
// EA  : 0x82867848
// RVA : 0x00867848
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::PristineLoadResource(idStaticModel *this)
{
  idStaticModel_vtbl *v1; // r10

  v1 = this->__vftable;
  this->pristine = true;
  ((void (*)(void))v1->LoadResource)();
}


// ========================================================================
// AddExtrudeBoxFace
// EA  : 0x82867890
// RVA : 0x00867890
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall AddExtrudeBoxFace(
        idDrawVert *verts,
        const idVec3 *center,
        const idVec3 *right,
        const idVec3 *up,
        int a5,
        __int64 a6)
{
  unsigned __int8 *tangent; // r11
  int i; // ctr
  int v11; // ctr
  double v18; // fp8
  double v19; // fp6
  double y; // fp4
  double z; // fp3
  double v22; // fp8
  double v23; // fp7
  double v24; // fp3
  double v25; // fp4
  double v26; // fp7
  double v27; // fp6
  double v28; // fp3
  double v29; // fp2
  double v30; // fp6
  double v31; // fp5
  double v32; // fp2
  double v33; // fp1

  tangent = verts[-1].tangent;
  LODWORD(a6) = 0;
  for ( i = 16; i != 0; --i )
  {
    tangent += 8;
    *(_QWORD *)tangent = a6;
  }
  __asm { vspltisw128 v62, 0 }
  _R10 = &center->z;
  _R9 = &center->y;
  v11 = 4;
  _R11 = &verts->normal[2];
  _R29 = -2;
  _R30 = -1;
  _R8 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
  _R7 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
  _R31 = &_vmx_3f8000003f8000003f8000003f800000;
  do
  {
    __asm
    {
      vor128    v61, v94, v62
      lvlx128   v60, r0, r4
      lvlx128   v59, r0, r9
      lvlx128   v58, r0, r10
      lvx128    v63, r0, r31
      vrlimi128 v61, v60, 8, 0
      lvx128    v0, r0, r7
      lvx128    v13, r0, r8
      vrlimi128 v61, v59, 4, 3
      vrlimi128 v61, v58, 2, 2
      vaddfp128 v12, v93, v63
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v57, v0, 0
      vpkswss128 v56, v89, v57
      vpkshus128 v0, v88, v56
      stvebx    v0, r11, r29
      stvebx    v0, r11, r30
      stvebx    v0, 0, r11
    }
    _R11 += 32;
    --v11;
  }
  while ( v11 != 0 );
  v18 = (float)(*_R9 - right->y);
  v19 = (float)(*_R10 - right->z);
  y = up->y;
  z = up->z;
  verts->xyz.x = up->x + (float)(center->x - right->x);
  verts->xyz.y = (float)y + (float)v18;
  verts->xyz.z = (float)z + (float)v19;
  v22 = up->y;
  v23 = up->z;
  v24 = (float)(*_R9 + right->y);
  v25 = (float)(right->z + *_R10);
  verts[1].xyz.x = up->x + (float)(center->x + right->x);
  verts[1].xyz.y = (float)v22 + (float)v24;
  verts[1].xyz.z = (float)v23 + (float)v25;
  v26 = up->y;
  v27 = up->z;
  v28 = (float)(right->z + *_R10);
  v29 = (float)(*_R9 + right->y);
  verts[2].xyz.x = (float)(center->x + right->x) - up->x;
  verts[2].xyz.z = (float)v28 - (float)v27;
  verts[2].xyz.y = (float)v29 - (float)v26;
  v30 = up->y;
  v31 = up->z;
  v32 = (float)(*_R10 - right->z);
  v33 = (float)(*_R9 - right->y);
  verts[3].xyz.x = (float)(center->x - right->x) - up->x;
  verts[3].xyz.z = (float)v32 - (float)v31;
  verts[3].xyz.y = (float)v33 - (float)v30;
}


// ========================================================================
// ?UpdateBuffers@idStaticModel@@AAAXXZ
// EA  : 0x82867A60
// RVA : 0x00867A60
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::UpdateBuffers(idStaticModel *this)
{
  int v2; // r28
  int v3; // r30
  idStaticModelSurface *v4; // r31
  idTriangles *geometry; // r3
  idStaticModel *v6; // r3

  v2 = 0;
  if ( this->surfaces.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->surfaces.list[v3];
      geometry = v4->geometry;
      if ( (*((_BYTE *)v4->material + 72) & 8) != 0 )
      {
        idTriangles::TurnIntoQuads(this: geometry);
        if ( v4->geometry->numVerts > 0x200u )
        {
          idLib::Error(
            fmt: "static model '%s' has transparency sort surface '%s' with more than %d quads",
            this->name.str,
            v4->material->name.str,
            512);
          idStaticModel::FreeCPUData(this: v6);
          return;
        }
      }
      else
      {
        idTriangles::UpdateVertexBuffer(this: geometry);
        idTriangles::UpdateIndexBuffer(this: v4->geometry);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->surfaces.num );
  }
}


// ========================================================================
// ?FreeCPUData@idStaticModel@@QAAXXZ
// EA  : 0x82867B00
// RVA : 0x00867B00
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::FreeCPUData(idStaticModel *this)
{
  int v2; // r29
  int v3; // r31
  idStaticModelSurface *v4; // r11

  if ( r_freeTriangleCPUData.valueInteger != 0 )
  {
    v2 = 0;
    if ( this->surfaces.num > 0 )
    {
      v3 = 0;
      do
      {
        v4 = &this->surfaces.list[v3];
        if ( (*((_BYTE *)v4->material + 72) & 8) == 0 )
          idTriangles::FreeCPUData(this: v4->geometry);
        ++v2;
        ++v3;
      }
      while ( v2 < this->surfaces.num );
    }
  }
}


// ========================================================================
// ?FindMaterialOrAutoMaterial@@YAPBVidMaterial@@PBD@Z
// EA  : 0x82867B80
// RVA : 0x00867B80
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

const idMaterial *__fastcall FindMaterialOrAutoMaterial(const char *name)
{
  idDecl *v2; // r3
  idDecl *v3; // r29
  __int64 v5; // r10
  __int64 v6; // r8
  int v7; // r11
  idStr *v8; // r27
  size_t len; // r30
  va *v10; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  const idDecl *v13; // r30
  __int64 v14; // r6
  va *v15; // r3
  char *data; // r4
  int v17; // [sp+8h] [-20F8h]
  int v18; // [sp+8h] [-20F8h]
  int v19; // [sp+Ch] [-20F4h]
  int v20; // [sp+Ch] [-20F4h]
  int v21; // [sp+10h] [-20F0h]
  int v22; // [sp+10h] [-20F0h]
  int v23; // [sp+14h] [-20ECh]
  int v24; // [sp+14h] [-20ECh]
  int v25; // [sp+18h] [-20E8h]
  int v26; // [sp+18h] [-20E8h]
  int v27; // [sp+1Ch] [-20E4h]
  int v28; // [sp+1Ch] [-20E4h]
  idStr v29; // [sp+50h] [-20B0h] BYREF
  idStr v30; // [sp+70h] [-2090h] BYREF
  idStr v31; // [sp+90h] [-2070h] BYREF
  idStr v32; // [sp+B0h] [-2050h] BYREF
  va v33; // [sp+D0h] [-2030h] BYREF
  va v34; // [sp+10D0h] [-1030h] BYREF

  if ( name != nullptr )
  {
    v2 = (idDecl *)idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name, makeDefault: false);
    v3 = v2;
    if ( v2 != nullptr && !idDecl::IsImplicit(this: v2) )
      return (const idMaterial *)v3;
  }
  idStr::idStr(this: &v29, text: name);
  idStr::StripFileExtension(this: &v29);
  HIDWORD(v5) = idStr::Find(
                  searchIn: v29.data,
                  searchFor: AUTO_MATERIAL_PREFIX,
                  casesensitive: false,
                  start: 0,
                  end: v29.len);
  if ( HIDWORD(v5) != -1 )
  {
    v7 = 0;
    if ( *AUTO_MATERIAL_PREFIX != 0 )
    {
      do
        ++v7;
      while ( AUTO_MATERIAL_PREFIX[v7] != 0 );
    }
    v8 = idStr::Right(this: &v32, result: &v29, len: v29.len - v7 - HIDWORD(v5));
    len = v8->len;
    idStr::EnsureAlloced(this: &v29, amount: v8->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v29.data, Src: v8->data, Size: len);
    v29.data[len] = 0;
    v29.len = len;
    idStr::FreeData(this: &v32);
  }
  v10 = va::va(
          this: &v33,
          fmt: "%s%s.decl",
          a3: __SPAIR64__((unsigned int)AUTO_MATERIAL_PREFIX, (unsigned int)v29.data),
          a4: v6,
          a5: v5,
          a6: v17,
          a7: v19,
          a8: v21,
          a9: v23,
          a10: v25,
          a11: v27);
  idStr::idStr(this: &v30, text: v10);
  if ( v30.data == nullptr
    || (v13 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v30.data, makeDefault: false)) == nullptr )
  {
    HIDWORD(v12) = v29.data;
    LODWORD(v14) = v29.data;
    HIDWORD(v14) = v29.data;
    v15 = va::va(
            this: &v34,
            fmt: "{\ndiffusemap %s\nspecularmap %s_s\nbumpmap %s_local\n}\n",
            a3: v14,
            a4: v12,
            a5: v11,
            a6: v18,
            a7: v20,
            a8: v22,
            a9: v24,
            a10: v26,
            a11: v28);
    idStr::idStr(this: &v31, text: v15);
    fileSystem->WriteFile(this: fileSystem, a2: v30.data, a3: v31.data, a4: v31.len, a5: FSPATH_BASE);
    data = v30.data;
    if ( v30.data != nullptr )
    {
      v13 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v30.data, makeDefault: false);
      if ( v13 != nullptr )
      {
LABEL_17:
        idStr::FreeData(this: &v31);
        idStr::FreeData(this: &v30);
        goto LABEL_18;
      }
      data = v30.data;
    }
    else
    {
      v13 = nullptr;
    }
    idLib::Warning(fmt: "FindMaterialOrAutoMaterial: failed to load %s", data);
    goto LABEL_17;
  }
  idStr::FreeData(this: &v30);
LABEL_18:
  idStr::FreeData(this: &v29);
  return (const idMaterial *)v13;
}


// ========================================================================
// __unwind$233521
// EA  : 0x82867DA0
// RVA : 0x00867DA0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_233521()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8448 + 80));
}


// ========================================================================
// __unwind$233522
// EA  : 0x82867DC8
// RVA : 0x00867DC8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_233522()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8448 + 176));
}


// ========================================================================
// __unwind$233523
// EA  : 0x82867DF0
// RVA : 0x00867DF0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_233523()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8448 + 112));
}


// ========================================================================
// __unwind$233524
// EA  : 0x82867E18
// RVA : 0x00867E18
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_233524()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8448 + 144));
}


// ========================================================================
// ?ReloadIfStale@idStaticModel@@UAA_NXZ
// EA  : 0x82867E40
// RVA : 0x00867E40
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

int __fastcall idStaticModel::ReloadIfStale(idStaticModel *this)
{
  bool v3; // r25
  unsigned int v4; // r3
  unsigned int binaryTimeStamp; // r6
  bool v6; // r11
  BOOL v7; // r10
  int v8; // r29
  int v9; // r30
  const idMaterial *mtr; // r11
  const char *str; // r4
  idCollisionModelLocal *v12; // r3
  int mtrChecksum; // r24
  cmType_t ScriptP; // r3

  if ( !this->isReloadable )
    return 0;
  v3 = strstr(str1: this->name.str, str2: ".bmodel") != nullptr;
  v4 = fileSystem->GetTimestamp(this: fileSystem, a2: this->binaryFileName, a3: false);
  binaryTimeStamp = this->binaryTimeStamp;
  v6 = binaryTimeStamp != v4;
  if ( binaryTimeStamp == v4 )
  {
    if ( v3 )
      return 0;
    if ( binaryTimeStamp == v4 )
      v6 = this->sourceTimeStamp != fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false);
  }
  v7 = v6;
  if ( !v6 )
  {
    v8 = 0;
    if ( this->sourceSurfaces.num > 0 )
    {
      v9 = 0;
      do
      {
        mtr = this->sourceSurfaces.list[v9].mtr;
        if ( mtr != nullptr )
        {
          str = mtr->name.str;
          v12 = str != nullptr
              ? (idCollisionModelLocal *)idDeclInfo::FindWithInheritance(
                                           this: &idMaterial::resourceList,
                                           name: str,
                                           makeDefault: true)
              : nullptr;
          mtrChecksum = this->sourceSurfaces.list[v9].mtrChecksum;
          ScriptP = idLexer::GetScriptP(this: v12);
          v7 = ScriptP != mtrChecksum;
          if ( ScriptP != mtrChecksum )
            goto LABEL_17;
        }
        ++v8;
        ++v9;
      }
      while ( v8 < this->sourceSurfaces.num );
    }
    if ( !v7 )
      return 0;
  }
LABEL_17:
  if ( !v3 )
    fileSystem->RemoveFile(this: fileSystem, a2: this->binaryFileName, a3: FSPATH_BASE);
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// ?RemapSourceSurfaces@idStaticModel@@AAAXXZ
// EA  : 0x82867FF0
// RVA : 0x00867FF0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::RemapSourceSurfaces(idStaticModel *this)
{
  const idDeclSkins *v2; // r25
  int v3; // r30
  int v4; // r29
  idStr v5[3]; // [sp+50h] [-60h] BYREF

  idStr::idStr(this: v5, text: this->name.str);
  idStr::StripFileExtension(this: v5);
  if ( v5[0].data != nullptr )
    v2 = (const idDeclSkins *)idDeclInfo::FindWithInheritance(
                                this: &idDeclSkins::resourceList,
                                name: v5[0].data,
                                makeDefault: false);
  else
    v2 = nullptr;
  v3 = 0;
  if ( this->surfaces.num > 0 )
  {
    v4 = 0;
    do
    {
      idTriangles::VmtrMapTexCoordsWithSkins(
        this: this->surfaces.list[v4].geometry,
        sourceSurfaces: &this->sourceSurfaces,
        renderSurface: v3++,
        originalMaterial: this->surfaces.list[v4].material,
        skins: v2,
        skinRemaps: &this->surfaces.list[v4].skinRemaps,
        usedMaterials: &this->materials);
      ++v4;
    }
    while ( v3 < this->surfaces.num );
  }
  idStr::FreeData(this: v5);
}


// ========================================================================
// __unwind$233752
// EA  : 0x828680A8
// RVA : 0x008680A8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_233752()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?Print@idStaticModel@@UBAXXZ
// EA  : 0x828680D8
// RVA : 0x008680D8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::Print(idStaticModel *this)
{
  bool *p_freeOnDelete; // r10
  bool *p_modelIsAutosprite; // r11
  int i; // ctr
  int v5; // r22
  double v6; // fp31
  int v7; // r19
  idStaticModelSurface *v8; // r11
  idTriangles *geometry; // r30
  const idMaterial *material; // r11
  unsigned int cpuVertexMask; // r11
  char v12; // r10
  unsigned int vertexMask; // r11
  const char *v14; // r3
  idTriangles *standardTris; // r29
  int v16; // r28
  int v17; // r30
  int v18; // r29
  int v19; // r28
  sourceSurface_t *v20; // r30
  char *FileName; // r9
  idDeclSource *v22; // r3
  idAutoStandardTriangles v23; // [sp+58h] [-B8h] BYREF
  float v24; // [sp+60h] [-B0h]
  float v25; // [sp+64h] [-ACh]
  float v26; // [sp+68h] [-A8h]
  float v27; // [sp+6Ch] [-A4h]
  float v28; // [sp+70h] [-A0h]
  float v29; // [sp+74h] [-9Ch]

  idLib::Printf(fmt: "%s\n", this->name.str);
  idLib::Printf(fmt: "Static model.\n");
  p_freeOnDelete = (bool *)&v23.freeOnDelete;
  p_modelIsAutosprite = &this->modelIsAutosprite;
  for ( i = 6; i != 0; --i )
  {
    p_modelIsAutosprite += 4;
    p_freeOnDelete += 4;
    *(_DWORD *)p_freeOnDelete = *(_DWORD *)p_modelIsAutosprite;
  }
  idLib::Printf(
    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v24)),
    (unsigned int)COERCE_UNSIGNED_INT64(v24),
    (unsigned int)COERCE_UNSIGNED_INT64(v25),
    (unsigned int)COERCE_UNSIGNED_INT64(v26),
    (unsigned int)COERCE_UNSIGNED_INT64(v27),
    (unsigned int)COERCE_UNSIGNED_INT64(v28),
    (unsigned int)COERCE_UNSIGNED_INT64(v29));
  idLib::Printf(fmt: "    verts  indx material (render surfaces)\n");
  v5 = 0;
  v6 = 0.0;
  if ( this->surfaces.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &this->surfaces.list[v7];
      geometry = v8->geometry;
      material = v8->material;
      if ( geometry != nullptr )
      {
        idLib::Printf(fmt: "%2i: %5i %5i %s", v5, geometry->numVerts, geometry->numIndexes, material->name.str);
        cpuVertexMask = geometry->cpuVertexMask;
        if ( cpuVertexMask != 31 || (v12 = 1, geometry->verts == nullptr) )
          v12 = 0;
        if ( v12 == 0 && geometry->verts != nullptr )
          idLib::Printf(
            fmt: " (%i byte CPU verts)",
            ((cpuVertexMask & 0x1000) == 0 ? 0 : 0xC)
          + ((cpuVertexMask >> 9) & 4)
          + ((cpuVertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
          + ((cpuVertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
          + ((cpuVertexMask >> 2) & 4)
          + ((cpuVertexMask >> 1) & 4)
          + (cpuVertexMask & 4)
          + ((4 * cpuVertexMask) & 8)
          + ((cpuVertexMask & 1) == 0 ? 0 : 0xC));
        vertexMask = geometry->vertexMask;
        if ( (vertexMask & 0xFFFFFDFF) != 0x1F )
          idLib::Printf(
            fmt: " (%i byte GPU verts)",
            ((vertexMask & 0x1000) == 0 ? 0 : 0xC)
          + ((vertexMask >> 9) & 4)
          + ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
          + ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
          + ((vertexMask >> 2) & 4)
          + ((vertexMask >> 1) & 4)
          + (vertexMask & 4)
          + ((4 * vertexMask) & 8)
          + ((vertexMask & 1) == 0 ? 0 : 0xC));
        v14 = " (smoothed)\n";
        if ( !geometry->generateNormals )
          v14 = "\n";
        idLib::Printf(fmt: v14);
        idAutoStandardTriangles::idAutoStandardTriangles(this: &v23, tri: geometry);
        standardTris = (idTriangles *)v23.standardTris;
        v16 = 0;
        if ( v23.standardTris->numIndexes > 0 )
        {
          v17 = 0;
          do
          {
            v16 += 3;
            v6 = (float)(idGeometry::AreaOfTriangle(
                           a: (const idVec3 *)((char *)&standardTris->verts->xyz + __ROL4__(standardTris->indexes[v17], 5)),
                           b: (const idVec3 *)((char *)&standardTris->verts->xyz
                                          + __ROL4__(standardTris->indexes[v17 + 1], 5)),
                           c: (const idVec3 *)((char *)&standardTris->verts->xyz
                                          + __ROL4__(standardTris->indexes[v17 + 2], 5)))
                       + (float)v6);
            v17 += 3;
          }
          while ( v16 < standardTris->numIndexes );
        }
        if ( v23.freeOnDelete )
        {
          idTriangles::~idTriangles(this: standardTris);
          idMem::Free(this: &mem, ptr: standardTris, align: ALIGN_16);
        }
      }
      else
      {
        idLib::Printf(fmt: "%2i: %s, NULL surface geometry\n", v5, material->name.str);
      }
      ++v5;
      ++v7;
    }
    while ( v5 < this->surfaces.num );
  }
  if ( this->sourceSurfaces.num != 0 )
  {
    idLib::Printf(fmt: "\nSS  RS start verts material (source surfaces)\n");
    v18 = 0;
    if ( this->sourceSurfaces.num > 0 )
    {
      v19 = 0;
      do
      {
        v20 = &this->sourceSurfaces.list[v19];
        if ( function_t::Name(this: &v20->mtr->idDecl) != nullptr )
        {
          v22 = function_t::Name(this: &v20->mtr->idDecl);
          FileName = idDeclSource::GetFileName(this: v22);
        }
        else
        {
          FileName = "(IMPLICIT)";
        }
        idLib::Printf(
          fmt: "%2i: %2i %5i %5i %s from %s\n",
          v18++,
          v20->renderSurface,
          v20->firstVertex,
          v20->lastVertex - v20->firstVertex + 1,
          v20->mtr->name.str,
          FileName);
        ++v19;
      }
      while ( v18 < this->sourceSurfaces.num );
    }
  }
  idLib::Printf(fmt: "\n%f units of total surface area\n\n", v6);
  this->List(this);
}


// ========================================================================
// __unwind$233827
// EA  : 0x82868510
// RVA : 0x00868510
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_233827()
{
  int v0; // r12

  idAutoStandardTriangles::~idAutoStandardTriangles(this: (idAutoStandardTriangles *)(v0 - 272 + 88));
}


// ========================================================================
// ?CPUMemory@idStaticModel@@QBAHXZ
// EA  : 0x82868538
// RVA : 0x00868538
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

int __fastcall idStaticModel::CPUMemory(idStaticModel *this)
{
  int v2; // r28
  int v3; // r29
  int v4; // r31
  idTriangles *geometry; // r3

  v2 = 0;
  v3 = 0;
  if ( this->surfaces.num > 0 )
  {
    v4 = 0;
    do
    {
      geometry = this->surfaces.list[v4].geometry;
      if ( geometry != nullptr )
        v2 += idTriangles::CPUMemoryUsed(this: geometry);
      ++v3;
      ++v4;
    }
    while ( v3 < this->surfaces.num );
  }
  return v2;
}


// ========================================================================
// ?GPUMemory@idStaticModel@@QBAHXZ
// EA  : 0x828685A0
// RVA : 0x008685A0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

int __fastcall idStaticModel::GPUMemory(idStaticModel *this)
{
  int v2; // r28
  int v3; // r29
  int v4; // r31
  idTriangles *geometry; // r3

  v2 = 0;
  v3 = 0;
  if ( this->surfaces.num > 0 )
  {
    v4 = 0;
    do
    {
      geometry = this->surfaces.list[v4].geometry;
      if ( geometry != nullptr )
        v2 += idTriangles::GPUMemoryUsed(this: geometry);
      ++v3;
      ++v4;
    }
    while ( v3 < this->surfaces.num );
  }
  return v2;
}


// ========================================================================
// ?List@idStaticModel@@UBAXXZ
// EA  : 0x82868608
// RVA : 0x00868608
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::List(idStaticModel *this)
{
  int num; // r28
  int v3; // r31
  int v4; // r30
  int v5; // r9
  int v6; // ctr
  idTriangles *geometry; // r10
  const char *str; // r27
  int v9; // r3
  const char *resourceError; // r4
  char *v11; // r10
  bool *p_modelIsAutosprite; // r11
  int i; // ctr
  char v14; // [sp+4Ch] [-54h] BYREF
  float v15; // [sp+50h] [-50h]
  float v16; // [sp+5Ch] [-44h]

  num = this->surfaces.num;
  v3 = 0;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    v6 = this->surfaces.num;
    do
    {
      geometry = this->surfaces.list[v5].geometry;
      if ( geometry != nullptr )
      {
        v3 += geometry->numIndexes;
        v4 += geometry->numVerts;
      }
      ++v5;
      --v6;
    }
    while ( v6 != 0 );
  }
  str = this->name.str;
  v9 = idStaticModel::GPUMemory(this);
  idLib::Printf(fmt: " %5ik %3i %6i %6i %s", v9 / 1024, num, v4, v3, str);
  resourceError = this->resourceError;
  if ( resourceError != nullptr )
    idLib::Printf(fmt: " %s", resourceError);
  v11 = &v14;
  p_modelIsAutosprite = &this->modelIsAutosprite;
  for ( i = 6; i != 0; --i )
  {
    p_modelIsAutosprite += 4;
    v11 += 4;
    *(_DWORD *)v11 = *(_DWORD *)p_modelIsAutosprite;
  }
  if ( v15 >= (double)v16 )
    idLib::Printf(fmt: " (EMPTY BOUNDS)");
  idLib::Printf(fmt: "\n");
}


// ========================================================================
// ?ReloadModel_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82868700
// RVA : 0x00868700
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall ReloadModel_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r4
  idResource *Existing; // r30
  idStr v4; // [sp+50h] [-460h] BYREF
  int v5; // [sp+70h] [-440h]
  char v6[1072]; // [sp+80h] [-430h] BYREF

  argc = args->argc;
  v5 = args->argc;
  if ( v5 != 2 )
  {
    idLib::Printf(fmt: "USAGE: reloadModel <modelname>\n");
    return;
  }
  if ( argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  idStr::idStr(this: &v4, text: v2);
  idStr::MakeNameCanonical(this: &v4);
  if ( strstr(str1: v4.data, str2: ".bmodel") != nullptr )
  {
    idLib::Printf(fmt: "Can't reload explicit bmodels.\n");
  }
  else
  {
    renderSystem->SyncRenderThread(this: renderSystem, a2: true);
    fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bmodel", a4: v4.data, a5: v6, a6: 1024);
    idLib::Printf(fmt: "Removing %s\n", v6);
    fileSystem->RemoveFile(this: fileSystem, a2: v6, a3: FSPATH_BASE);
    Existing = idResourceList::FindExisting(this: &idStaticModel::resourceList, name: v4.data, skipStaleCheck: true);
    if ( Existing != nullptr )
    {
      idLib::Printf(fmt: "Forcing existing model to reload.\n");
      Existing->LoadResource(this: Existing);
    }
    else
    {
      Existing = idResourceList::Load(
                   this: &idStaticModel::resourceList,
                   name: v4.data,
                   makeDefault: true,
                   skipStaleCheck: false);
      if ( Existing == nullptr )
      {
        idLib::Printf(fmt: "Model failed to load.\n");
        goto LABEL_11;
      }
    }
    Existing->Print(this: Existing);
    renderSystem->RegenerateReferences(this: renderSystem);
  }
LABEL_11:
  idStr::FreeData(this: &v4);
}


// ========================================================================
// __unwind$234297
// EA  : 0x828688A8
// RVA : 0x008688A8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_234297()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1200 + 80));
}


// ========================================================================
// ?WriteStaticModel@idStaticModel@@SAXPBDIABV?$idList@VidStaticModelSurface@@$04@@W4fsPath_t@@@Z
// EA  : 0x828688D8
// RVA : 0x008688D8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::WriteStaticModel(
        const char *filename,
        unsigned int timestamp,
        const idList<idStaticModelSurface,5> *surfaces,
        fsPath_t basePath)
{
  int v7; // r11
  idStr *v8; // r27
  float v9; // r29
  idFile *v10; // r3
  idFile *v11; // r29
  int v12; // r16
  int v13; // r19
  idStaticModelSurface *v14; // r11
  idTriangles *geometry; // r27
  __int64 v16; // r8
  int v17; // r5
  int v18; // r28
  int v19; // r26
  const idVec3 *p_xyz; // r30
  int v21; // r30
  int v22; // r28
  idDrawVert v23; // [sp+60h] [-E0h] BYREF
  idStr v24[5]; // [sp+90h] [-B0h] BYREF

  idStr::idStr(this: (idStr *)&v23.st.y, text: filename);
  v7 = 0;
  if ( *filename != 0 )
  {
    do
      ++v7;
    while ( filename[v7] != 0 );
  }
  if ( filename[v7 - 1] == 46 )
  {
    idStr::StripTrailing(this: (idStr *)&v23.st.y, c: 46);
  }
  else
  {
    idStr::StripFileExtension(this: (idStr *)&v23.st.y);
    v8 = operator+(result: v24, a: (const idStr *)&v23.st.y, b: ".model");
    v9 = *(float *)&v8->len;
    idStr::EnsureAlloced(this: (idStr *)&v23.st.y, amount: v8->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: *(void **)v23.normal, Src: v8->data, Size: LODWORD(v9));
    *(_BYTE *)(*(_DWORD *)v23.normal + LODWORD(v9)) = 0;
    v23.st.y = v9;
    idStr::FreeData(this: v24);
  }
  v10 = fileSystem->OpenFileWrite(this: fileSystem, a2: *(_DWORD *)v23.normal, a3: basePath);
  v11 = v10;
  if ( v10 != nullptr )
  {
    v10->Printf(this: v10, a2: "%i\n", surfaces->num);
    v12 = 0;
    if ( surfaces->num > 0 )
    {
      v13 = 0;
      do
      {
        v14 = &surfaces->list[v13];
        geometry = v14->geometry;
        if ( v14->material != nullptr && geometry != nullptr )
        {
          v11->Printf(
            this: v11,
            a2: "{\n\"%s\" %i %i\n",
            v14->material->name.str,
            geometry->numVerts,
            geometry->numIndexes);
          v18 = 0;
          if ( geometry->numVerts > 0 )
          {
            v19 = 0;
            do
            {
              p_xyz = &geometry->verts[v19].xyz;
              idDrawVert::GetNormal(this: &v23, result: p_xyz, a3: v17, a4: v16);
              v11->Printf(
                this: v11,
                a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(p_xyz->x)),
                COERCE_UNSIGNED_INT64(p_xyz->x),
                COERCE_UNSIGNED_INT64(p_xyz->y),
                COERCE_UNSIGNED_INT64(p_xyz->z),
                COERCE_UNSIGNED_INT64(p_xyz[1].x),
                COERCE_UNSIGNED_INT64(p_xyz[1].y),
                COERCE_UNSIGNED_INT64(v23.xyz.x));
              if ( v18 % 3 == 2 )
                v11->Printf(this: v11, a2: "\n");
              ++v18;
              ++v19;
            }
            while ( v18 < geometry->numVerts );
          }
          v11->Printf(this: v11, a2: "\n");
          v21 = 0;
          if ( geometry->numIndexes > 0 )
          {
            v22 = 0;
            do
            {
              v11->Printf(this: v11, a2: "%i ", geometry->indexes[v22]);
              if ( v21 % 20 == 19 )
                v11->Printf(this: v11, a2: "\n");
              ++v21;
              ++v22;
            }
            while ( v21 < geometry->numIndexes );
          }
          v11->Printf(this: v11, a2: "}\n");
        }
        ++v12;
        ++v13;
      }
      while ( v12 < surfaces->num );
    }
    ((void (__fastcall *)(idFile *, int))v11->dtr_idFile)(a1: v11, a2: 1);
  }
  else
  {
    idLib::Warning(fmt: "idStaticModel::WriteStaticModel() - Could not open %s", filename);
  }
  idStr::FreeData(this: (idStr *)&v23.st.y);
}


// ========================================================================
// __unwind$234549
// EA  : 0x82868C68
// RVA : 0x00868C68
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_234549()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$234550
// EA  : 0x82868C90
// RVA : 0x00868C90
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_234550()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 144));
}


// ========================================================================
// ?reportStaticModelMemory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82868CC0
// RVA : 0x00868CC0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall reportStaticModelMemory_f(const idCmdArgs *args)
{
  int v1; // r22
  int v2; // r26
  unsigned int v3; // r24
  unsigned int v4; // r25
  int v5; // r20
  int v6; // r19
  unsigned int v7; // r21
  int i; // r30
  _DWORD *v9; // r23
  int v10; // r16
  int v11; // r18
  int v12; // r15
  _DWORD *v13; // r27
  idTriangles *v14; // r30
  unsigned int vertexMask; // r11
  int numVerts; // r10
  idTriangles *StandardTriangles; // r3
  int numIndexes; // r9
  int v19; // r10
  unsigned int v20; // r7
  double v21; // fp12
  double v22; // r4
  double v23; // r4
  __int64 v24; // r11
  double v25; // r4
  __int64 v26; // r8
  double v27; // r4
  double v28; // r4
  double v29; // [sp+18h] [-128h]
  int v30; // [sp+50h] [-F0h]
  unsigned int v31; // [sp+54h] [-ECh]
  unsigned int v32; // [sp+58h] [-E8h]
  int v33; // [sp+5Ch] [-E4h]
  idTriangles *v34; // [sp+68h] [-D8h]
  idList<idVehicleState *,5> v35; // [sp+90h] [-B0h] BYREF

  v1 = 0;
  memset(&v35, 0, 14);
  *(_WORD *)&v35.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v35);
  idResourceList::GetLoadedResources(this: &idStaticModel::resourceList, resourceList: &v35);
  v31 = 0;
  v2 = 0;
  v32 = 0;
  v33 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  if ( v35.num > 0 )
  {
    v30 = 0;
    for ( i = 0; ; i += 4 )
    {
      v9 = _RTDynamicCast(
             inptr: *(void **)((char *)v35.list + i),
             VfDelta: 0,
             SrcType: &idResource `RTTI Type Descriptor',
             TargetType: &idStaticModel `RTTI Type Descriptor',
             isReference: 0);
      v10 = 0;
      v11 = 0;
      v12 = 0;
      if ( (int)v9[90] > 0 )
      {
        do
        {
          v13 = (_DWORD *)(v1 + v9[89]);
          v14 = (idTriangles *)v13[4];
          vertexMask = v14->vertexMask;
          numVerts = v14->numVerts;
          v2 += numVerts;
          v4 += 2 * v14->numIndexes;
          v3 += (((vertexMask & 0x1000) == 0 ? 0 : 0xC)
               + ((vertexMask >> 9) & 4)
               + ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
               + ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
               + ((vertexMask >> 2) & 4)
               + ((vertexMask >> 1) & 4)
               + (vertexMask & 4)
               + ((4 * vertexMask) & 8)
               + ((vertexMask & 1) == 0 ? 0 : 0xC))
              * numVerts;
          if ( vertexMask != 31 )
            v10 += (((vertexMask & 0x1000) == 0 ? -32 : -20)
                  - ((vertexMask >> 9) & 4)
                  - ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
                  - ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
                  - ((vertexMask >> 2) & 4)
                  - ((vertexMask >> 1) & 4)
                  - (vertexMask & 4)
                  - ((4 * vertexMask) & 8)
                  - ((vertexMask & 1) == 0 ? 0 : 0xC))
                 * numVerts;
          if ( (vertexMask & 0x200) != 0 )
          {
            StandardTriangles = idTriangles::CreateStandardTriangles(this: v14);
            numIndexes = StandardTriangles->numIndexes;
            v34 = StandardTriangles;
            v11 += 2 * (numIndexes - v14->numIndexes);
            v5 += numIndexes / 3;
            v6 += (numIndexes - StandardTriangles->detailOffset) / 3;
            idTriangles::~idTriangles(this: StandardTriangles);
            idMem::Free(this: &mem, ptr: v34, align: ALIGN_16);
          }
          else
          {
            v19 = v14->numIndexes;
            v5 += v19 / 3;
            v6 += (v19 - v14->detailOffset) / 3;
          }
          if ( *v13 == 0 || *(_DWORD *)(*v13 + 268) == 1 )
          {
            v20 = v14->vertexMask;
            v7 += (((v20 & 0x1000) == 0 ? 0 : 0xC)
                 + ((v20 >> 9) & 4)
                 + ((v20 & 0x40) == 0 ? 0 : 0xFFFFFFFC)
                 + ((v20 & 0x20) == 0 ? 0 : 0xFFFFFFFC)
                 + ((v20 >> 2) & 4)
                 + ((v20 >> 1) & 4)
                 + (v20 & 4)
                 + ((4 * v20) & 8)
                 + ((v20 & 1) == 0 ? 0 : 0xC))
                * v14->numVerts
                + 2 * v14->numIndexes;
          }
          ++v12;
          v1 += 72;
        }
        while ( v12 < v9[90] );
        if ( v10 > 0 || v11 > 0 )
        {
          v21 = (double)__SPAIR64__(v32, v11);
          v29 = (float)((float)__SPAIR64__(v31, v10) * (float)0.0009765625);
          v31 += v10;
          v32 += v11;
          idLib::Printf(
            fmt: (const char *)HIDWORD(v29),
            (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v21 * (float)0.0009765625))),
            (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v21 * (float)0.0009765625)),
            v9[2]);
        }
        i = v30;
        v1 = 0;
      }
      v30 = i + 4;
      if ( ++v33 >= v35.num )
        break;
    }
  }
  idLib::Printf(fmt: "%i total verts\n", v2);
  idLib::Printf(fmt: "%i total tris\n", v5);
  idLib::Printf(fmt: "%i total detail tris\n", v6);
  v22 = (float)((float)__SPAIR64__("ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY", v3) * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v22), LODWORD(v22));
  v23 = (float)((float)__SPAIR64__("ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY", v4) * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v23), LODWORD(v23));
  LODWORD(v24) = v31;
  v25 = (float)((float)v24 * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v25), LODWORD(v25));
  LODWORD(v26) = v32;
  v27 = (float)((float)v26 * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v27), LODWORD(v27));
  v28 = (float)((float)__SPAIR64__("ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY", v7) * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v28), LODWORD(v28));
  if ( (v35.listStatic == 0 || v35.listStatic == 2) && v35.list != nullptr )
    idMem::Free(this: &mem, ptr: v35.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$234704
// EA  : 0x8286922C
// RVA : 0x0086922C
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_234704()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 144));
}


// ========================================================================
// ?reportMeshMemory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82869260
// RVA : 0x00869260
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall reportMeshMemory_f(const idCmdArgs *args)
{
  int v1; // r27
  unsigned int v2; // r25
  unsigned int v3; // r26
  int v4; // r22
  int v5; // r21
  int v6; // r14
  _DWORD *v7; // r24
  int v8; // r18
  int v9; // r20
  int v10; // r17
  int v11; // r23
  idTriangles *v12; // r30
  unsigned int vertexMask; // r11
  int numVerts; // r10
  idTriangles *StandardTriangles; // r3
  int numIndexes; // r9
  int v17; // r10
  double v18; // fp12
  double v19; // r4
  double v20; // r4
  __int64 v21; // r11
  double v22; // r4
  __int64 v23; // r8
  double v24; // r4
  double v25; // [sp+18h] [-118h]
  unsigned int v26; // [sp+50h] [-E0h]
  unsigned int v27; // [sp+54h] [-DCh]
  int v28; // [sp+58h] [-D8h]
  idTriangles *v29; // [sp+64h] [-CCh]
  idList<idVehicleState *,5> v30; // [sp+80h] [-B0h] BYREF

  memset(&v30, 0, 14);
  *(_WORD *)&v30.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v30);
  idResourceList::GetLoadedResources(this: &idMD6Model::resourceList, resourceList: &v30);
  v26 = 0;
  v1 = 0;
  v27 = 0;
  v2 = 0;
  v28 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( v30.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = _RTDynamicCast(
             inptr: v30.list[v6],
             VfDelta: 0,
             SrcType: &idResource `RTTI Type Descriptor',
             TargetType: (void *)&idMD6Model `RTTI Type Descriptor',
             isReference: 0);
      v8 = 0;
      v9 = 0;
      v10 = 0;
      if ( (int)v7[38] > 0 )
      {
        v11 = 0;
        do
        {
          v12 = *(idTriangles **)(*(_DWORD *)(v11 + v7[37]) + 104);
          vertexMask = v12->vertexMask;
          numVerts = v12->numVerts;
          v1 += numVerts;
          v3 += 2 * v12->numIndexes;
          v2 += (((vertexMask & 0x1000) == 0 ? 0 : 0xC)
               + ((vertexMask >> 9) & 4)
               + ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
               + ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
               + ((vertexMask >> 2) & 4)
               + ((vertexMask >> 1) & 4)
               + (vertexMask & 4)
               + ((4 * vertexMask) & 8)
               + ((vertexMask & 1) == 0 ? 0 : 0xC))
              * numVerts;
          if ( vertexMask != 31 )
            v8 += (((vertexMask & 0x1000) == 0 ? -32 : -20)
                 - ((vertexMask >> 9) & 4)
                 - ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
                 - ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
                 - ((vertexMask >> 2) & 4)
                 - ((vertexMask >> 1) & 4)
                 - (vertexMask & 4)
                 - ((4 * vertexMask) & 8)
                 - ((vertexMask & 1) == 0 ? 0 : 0xC))
                * numVerts;
          if ( (vertexMask & 0x200) != 0 )
          {
            StandardTriangles = idTriangles::CreateStandardTriangles(this: v12);
            numIndexes = StandardTriangles->numIndexes;
            v29 = StandardTriangles;
            v9 += 2 * (numIndexes - v12->numIndexes);
            v4 += numIndexes / 3;
            v5 += (numIndexes - StandardTriangles->detailOffset) / 3;
            idTriangles::~idTriangles(this: StandardTriangles);
            idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
          }
          else
          {
            v17 = v12->numIndexes;
            v4 += v17 / 3;
            v5 += (v17 - v12->detailOffset) / 3;
          }
          ++v10;
          v11 += 4;
        }
        while ( v10 < v7[38] );
        if ( v8 > 0 || v9 > 0 )
        {
          v18 = (double)__SPAIR64__(v27, v9);
          v25 = (float)((float)__SPAIR64__(v26, v8) * (float)0.0009765625);
          v26 += v8;
          v27 += v9;
          idLib::Printf(
            fmt: (const char *)HIDWORD(v25),
            (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v18 * (float)0.0009765625))),
            (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v18 * (float)0.0009765625)),
            v7[2]);
        }
      }
      ++v6;
      ++v28;
    }
    while ( v28 < v30.num );
  }
  idLib::Printf(fmt: "%i total verts\n", v1);
  idLib::Printf(fmt: "%i total tris\n", v4);
  idLib::Printf(fmt: "%i total detail tris\n", v5);
  v19 = (float)((float)__SPAIR64__("ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY", v2) * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v19), LODWORD(v19));
  v20 = (float)((float)__SPAIR64__("ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY", v3) * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v20), LODWORD(v20));
  LODWORD(v21) = v26;
  v22 = (float)((float)v21 * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v22), LODWORD(v22));
  LODWORD(v23) = v27;
  v24 = (float)((float)v23 * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v24), LODWORD(v24));
  if ( (v30.listStatic == 0 || v30.listStatic == 2) && v30.list != nullptr )
    idMem::Free(this: &mem, ptr: v30.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$234869
// EA  : 0x828696D8
// RVA : 0x008696D8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_234869()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 304 + 128));
}


// ========================================================================
// ?WriteStaticModel@idStaticModel@@QBAXXZ
// EA  : 0x82869700
// RVA : 0x00869700
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::WriteStaticModel(idStaticModel *this)
{
  idStaticModel::WriteStaticModel(
    filename: this->name.str,
    timestamp: this->sourceTimeStamp,
    surfaces: (const idList<idStaticModelSurface,5> *)&this->surfaces,
    basePath: FSPATH_BASE);
}


// ========================================================================
// ?FreeSurfaces@idStaticModel@@QAAXXZ
// EA  : 0x82869780
// RVA : 0x00869780
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::FreeSurfaces(idStaticModel *this)
{
  BOOL sharedSurfaces; // r10
  int v3; // r27
  int v4; // r28
  idStaticModelSurface *v5; // r30
  idTriangles *geometry; // r29
  char *list; // r3

  sharedSurfaces = this->sharedSurfaces;
  ++this->reloadCount;
  if ( !sharedSurfaces )
  {
    v3 = 0;
    if ( this->surfaces.num > 0 )
    {
      v4 = 0;
      do
      {
        v5 = &this->surfaces.list[v4];
        if ( !v5->geometryIsReference )
        {
          geometry = v5->geometry;
          if ( geometry != nullptr )
          {
            idTriangles::~idTriangles(this: v5->geometry);
            idMem::Free(this: &mem, ptr: geometry, align: ALIGN_16);
          }
          v5->geometry = nullptr;
        }
        ++v3;
        ++v4;
      }
      while ( v3 < this->surfaces.num );
    }
  }
  if ( this->surfaces.listStatic == 0 || this->surfaces.listStatic == 2 )
  {
    list = (char *)this->surfaces.list;
    if ( list != nullptr )
      idListArrayDelete<idStaticModelSurface>(ptr: list, num: this->surfaces.size);
    this->surfaces.list = nullptr;
    this->surfaces.size = 0;
  }
  this->surfaces.num = 0;
}


// ========================================================================
// ??0idStaticModel@@QAA@XZ
// EA  : 0x82869920
// RVA : 0x00869920
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

idStaticModel *__fastcall idStaticModel::idStaticModel(idStaticModel *this)
{
  idResource::idResource(this);
  this->__vftable = (idStaticModel_vtbl *)&idStaticModel::`vftable';
  this->surfaces.granularity = 0;
  this->surfaces.memTag = 84;
  this->surfaces.listStatic = 0;
  this->surfaces.list = nullptr;
  this->surfaces.size = 0;
  this->surfaces.num = 0;
  this->sourceSurfaces.list = nullptr;
  this->sourceSurfaces.granularity = 0;
  this->sourceSurfaces.memTag = 5;
  this->sourceSurfaces.listStatic = 0;
  this->sourceSurfaces.size = 0;
  this->sourceSurfaces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  this->materials.list = nullptr;
  this->materials.granularity = 0;
  this->materials.memTag = 5;
  this->materials.listStatic = 0;
  this->materials.size = 0;
  this->materials.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->materials);
  this->pristine = false;
  this->isReloadable = false;
  this->modelIsAutosprite = false;
  this->binaryTimeStamp = -1;
  this->sourceTimeStamp = -1;
  this->usesTransparencySort = false;
  this->reloadCount = 0;
  this->modelLoadFlags = 2;
  this->referenceBounds.b[1].z = 0.0;
  this->referenceBounds.b[1].y = 0.0;
  this->referenceBounds.b[1].x = 0.0;
  this->referenceBounds.b[0].z = 0.0;
  this->referenceBounds.b[0].y = 0.0;
  this->referenceBounds.b[0].x = 0.0;
  this->referencePosition = vec3_origin;
  this->sharedSurfaces = false;
  return this;
}


// ========================================================================
// __unwind$235458_0
// EA  : 0x82869A3C
// RVA : 0x00869A3C
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_235458_0()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$235459_0
// EA  : 0x82869A64
// RVA : 0x00869A64
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_235459_0()
{
  int v0; // r12

  idList<idStaticModelSurface,5>::~idList<idStaticModelSurface,5>(this: (idList<idStaticModelSurface,5> *)(*(_DWORD *)(v0 - 128 + 148) + 356));
}


// ========================================================================
// __unwind$235460
// EA  : 0x82869A90
// RVA : 0x00869A90
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_235460()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 372));
}


// ========================================================================
// ??1idStaticModel@@UAA@XZ
// EA  : 0x82869AD8
// RVA : 0x00869AD8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::~idStaticModel(idStaticModel *this)
{
  char *list; // r3

  this->__vftable = (idStaticModel_vtbl *)&idStaticModel::`vftable';
  idStaticModel::FreeSurfaces(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->materials);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  if ( this->surfaces.listStatic == 0 || this->surfaces.listStatic == 2 )
  {
    list = (char *)this->surfaces.list;
    if ( list != nullptr )
      idListArrayDelete<idStaticModelSurface>(ptr: list, num: this->surfaces.size);
    this->surfaces.list = nullptr;
    this->surfaces.size = 0;
  }
  this->surfaces.num = 0;
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$235595
// EA  : 0x82869B58
// RVA : 0x00869B58
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_235595()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$235596
// EA  : 0x82869B80
// RVA : 0x00869B80
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_235596()
{
  int v0; // r12

  idList<idStaticModelSurface,5>::~idList<idStaticModelSurface,5>(this: (idList<idStaticModelSurface,5> *)(*(_DWORD *)(v0 - 112 + 132) + 356));
}


// ========================================================================
// __unwind$235597
// EA  : 0x82869BAC
// RVA : 0x00869BAC
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_235597()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 372));
}


// ========================================================================
// __unwind$235598
// EA  : 0x82869BD8
// RVA : 0x00869BD8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_235598()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 388));
}


// ========================================================================
// ?AddSurface@idStaticModel@@QAAXABVidStaticModelSurface@@@Z
// EA  : 0x82869E90
// RVA : 0x00869E90
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::AddSurface(idStaticModel *this, const idStaticModelSurface *surf)
{
  idList<idStaticModelSurface,5>::Append(this: (idList<idStaticModelSurface,5> *)&this->surfaces, obj: surf);
}


// ========================================================================
// ?MakeDefaultModel@idStaticModel@@QAAXMM@Z
// EA  : 0x82869EA0
// RVA : 0x00869EA0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::MakeDefaultModel(idStaticModel *this, double low, double high)
{
  idTriangles *v6; // r3
  idTriangles *v7; // r30
  idVec3 v8; // [sp+50h] [-200h] BYREF
  idVec3 v9; // [sp+60h] [-1F0h] BYREF
  idVec3 v10; // [sp+70h] [-1E0h] BYREF
  idVec3 v11; // [sp+80h] [-1D0h] BYREF
  idVec3 v12; // [sp+90h] [-1C0h] BYREF
  idVec3 v13; // [sp+A0h] [-1B0h] BYREF
  idVec3 v14; // [sp+B0h] [-1A0h] BYREF
  idVec3 v15; // [sp+C0h] [-190h] BYREF
  idVec3 v16; // [sp+D0h] [-180h] BYREF
  idVec3 v17; // [sp+E0h] [-170h] BYREF
  idVec3 v18; // [sp+F0h] [-160h] BYREF
  idVec3 v19; // [sp+100h] [-150h] BYREF
  idVec3 v20; // [sp+110h] [-140h] BYREF
  idVec3 v21; // [sp+120h] [-130h] BYREF
  idVec3 v22; // [sp+130h] [-120h] BYREF
  idVec3 v23; // [sp+140h] [-110h] BYREF
  idVec3 v24; // [sp+150h] [-100h] BYREF
  idVec3 v25; // [sp+160h] [-F0h] BYREF
  idVec3 v26; // [sp+170h] [-E0h] BYREF
  idVec3 v27; // [sp+180h] [-D0h] BYREF
  idVec3 v28; // [sp+190h] [-C0h] BYREF
  idVec3 v29; // [sp+1A0h] [-B0h] BYREF
  idVec3 v30; // [sp+1B0h] [-A0h] BYREF
  idVec3 v31; // [sp+1C0h] [-90h] BYREF
  idTriangles *v32; // [sp+1CCh] [-84h]
  idStaticModelSurface v33; // [sp+1D0h] [-80h] BYREF

  idStaticModel::FreeSurfaces(this);
  v6 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v32 = v6;
  if ( v6 != nullptr )
    v7 = idTriangles::idTriangles(this: v6);
  else
    v7 = nullptr;
  idTriangles::AllocStaticTriSurfVerts(this: v7, numVerts: 24);
  idTriangles::AllocStaticTriSurfIndexes(this: v7, numIndexes: 36);
  v10.x = low;
  v10.y = low;
  v10.z = high;
  v22.x = high;
  v22.y = low;
  v22.z = high;
  v12.x = high;
  v12.y = high;
  v12.z = high;
  v28.x = low;
  v28.y = high;
  v28.z = high;
  idTriangles::AddCubeFace(this: v7, v1: &v28, v2: &v12, v3: &v22, v4: &v10);
  v14.x = high;
  v14.y = high;
  v14.z = low;
  v24.x = high;
  v24.y = low;
  v24.z = low;
  v16.x = low;
  v16.y = low;
  v16.z = low;
  v31.x = low;
  v31.y = high;
  v31.z = low;
  idTriangles::AddCubeFace(this: v7, v1: &v31, v2: &v16, v3: &v24, v4: &v14);
  v18.x = high;
  v18.y = low;
  v18.z = low;
  v26.x = high;
  v26.y = high;
  v26.z = low;
  v20.x = high;
  v20.y = high;
  v20.z = high;
  v8.x = high;
  v8.y = low;
  v8.z = high;
  idTriangles::AddCubeFace(this: v7, v1: &v8, v2: &v20, v3: &v26, v4: &v18);
  v9.x = low;
  v9.y = high;
  v9.z = high;
  v11.x = low;
  v11.y = high;
  v11.z = low;
  v13.x = low;
  v13.y = low;
  v13.z = low;
  v15.x = low;
  v15.y = low;
  v15.z = high;
  idTriangles::AddCubeFace(this: v7, v1: &v15, v2: &v13, v3: &v11, v4: &v9);
  v17.x = low;
  v17.y = low;
  v17.z = low;
  v19.x = high;
  v19.y = low;
  v19.z = low;
  v21.x = high;
  v21.y = low;
  v21.z = high;
  v23.x = low;
  v23.y = low;
  v23.z = high;
  idTriangles::AddCubeFace(this: v7, v1: &v23, v2: &v21, v3: &v19, v4: &v17);
  v25.x = high;
  v25.y = high;
  v25.z = high;
  v27.x = high;
  v27.y = high;
  v27.z = low;
  v29.x = low;
  v29.y = high;
  v29.z = low;
  v30.x = low;
  v30.y = high;
  v30.z = high;
  idTriangles::AddCubeFace(this: v7, v1: &v30, v2: &v29, v3: &v27, v4: &v25);
  v7->generateNormals = true;
  idStaticModelSurface::idStaticModelSurface(this: &v33);
  v33.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                       this: &idMaterial::resourceList,
                                       name: "_default",
                                       makeDefault: true);
  v33.geometry = v7;
  idList<idStaticModelSurface,5>::Append(this: (idList<idStaticModelSurface,5> *)&this->surfaces, obj: &v33);
  idStaticModel::FinishStaticModel(this, cleanup: true);
  idStaticModel::UpdateBuffers(this);
  idStaticModel::FreeCPUData(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33.skinRemaps);
}


// ========================================================================
// __unwind$235732
// EA  : 0x8286A144
// RVA : 0x0086A144
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_235732()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 592 + 460), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$235733
// EA  : 0x8286A170
// RVA : 0x0086A170
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_235733()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 592 + 464));
}


// ========================================================================
// ?MakeExtrudeBox@idStaticModel@@QAAXXZ
// EA  : 0x8286A1A0
// RVA : 0x0086A1A0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idStaticModel::MakeExtrudeBox(idStaticModel *this)
{
  idTriangles *v1; // r3
  __int64 v2; // r25
  __int64 v3; // r29 OVERLAPPED
  __int64 v4; // r10
  int v5; // r7
  idDrawVert *v6; // r3
  __int64 v7; // r10
  __int64 v8; // r10
  int v9; // r7
  __int64 v10; // r10
  int v11; // r7
  __int64 v12; // r10
  int v13; // r7
  __int64 v14; // r10
  int v15; // r7
  _WORD *v16; // r30
  __int128 v17; // r26
  int v18; // r27
  __int64 v19; // r28
  float y; // r29
  idMem *v21; // r28
  idVec3 v22; // [sp+58h] [-158h] BYREF
  idVec3 v23; // [sp+68h] [-148h] BYREF
  idVec3 v24; // [sp+78h] [-138h] BYREF
  _WORD *v25; // [sp+84h] [-12Ch]
  idTriangles *v26; // [sp+88h] [-128h]
  idMem *v27; // [sp+8Ch] [-124h]
  _WORD *v28; // [sp+90h] [-120h]
  int v29; // [sp+94h] [-11Ch]
  int v30; // [sp+98h] [-118h]
  int v31; // [sp+9Ch] [-114h]
  __int64 v32; // [sp+A0h] [-110h]
  idStaticModelSurface v33; // [sp+B0h] [-100h] BYREF

  idStaticModel::FreeSurfaces(this);
  v27 = &mem;
  v1 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v26 = v1;
  LODWORD(v2) = 0;
  if ( v1 != nullptr )
    HIDWORD(v3) = idTriangles::idTriangles(this: v1);
  else
    HIDWORD(v3) = 0;
  *(_DWORD *)(HIDWORD(v3) + 32) = 24;
  v31 = 24;
  LODWORD(v3) = idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                  size: 0x300u,
                  tag: TAG_TEMP,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v30 = v3;
  HIDWORD(v4) = 0x82000000;
  v22.x = 0.0;
  v22.y = 1.0;
  v22.z = 0.0;
  v23.x = 1.0;
  v23.y = 0.0;
  v23.z = 0.0;
  v24.x = 0.0;
  v24.y = 0.0;
  v24.z = 1.0;
  AddExtrudeBoxFace(verts: (idDrawVert *)v3, center: &v24, right: &v23, up: &v22, a5: v5, a6: v4);
  v22.x = 0.0;
  v22.y = 0.0;
  v22.z = 1.0;
  v23.x = 1.0;
  v23.y = 0.0;
  v23.z = 0.0;
  v24.x = 0.0;
  v24.y = -1.0;
  v24.z = 0.0;
  AddExtrudeBoxFace(verts: v6 + 4, center: &v24, right: &v23, up: &v22, a5: 0x82000000, a6: v7);
  v22.x = 0.0;
  v22.y = 0.0;
  v22.z = 1.0;
  v23.x = 0.0;
  v23.y = 1.0;
  v23.z = 0.0;
  v24.x = 1.0;
  v24.y = 0.0;
  v24.z = 0.0;
  AddExtrudeBoxFace(verts: (idDrawVert *)(v3 + 256), center: &v24, right: &v23, up: &v22, a5: v9, a6: v8);
  v22.x = 0.0;
  v22.y = -1.0;
  v22.z = 0.0;
  v23.x = 1.0;
  v23.y = 0.0;
  v23.z = 0.0;
  v24.x = 0.0;
  v24.y = 0.0;
  v24.z = -1.0;
  AddExtrudeBoxFace(verts: (idDrawVert *)(v3 + 384), center: &v24, right: &v23, up: &v22, a5: v11, a6: v10);
  v22.x = 0.0;
  v22.y = 0.0;
  v22.z = 1.0;
  v23.x = -1.0;
  v23.y = 0.0;
  v23.z = 0.0;
  v24.x = 0.0;
  v24.y = 1.0;
  v24.z = 0.0;
  AddExtrudeBoxFace(verts: (idDrawVert *)(v3 + 512), center: &v24, right: &v23, up: &v22, a5: v13, a6: v12);
  v22.x = 0.0;
  v22.y = 0.0;
  v22.z = 1.0;
  v23.x = 0.0;
  v23.y = -1.0;
  v23.z = 0.0;
  v24.x = -1.0;
  v24.y = 0.0;
  v24.z = 0.0;
  AddExtrudeBoxFace(verts: (idDrawVert *)(v3 + 640), center: &v24, right: &v23, up: &v22, a5: v15, a6: v14);
  idVertexBuffer::AllocBufferObject(
    this: (idVertexBuffer *)(HIDWORD(v3) + 100),
    data: (const void *)v3,
    allocSize: 32 * *(_DWORD *)(HIDWORD(v3) + 32),
    vertexMask: 31,
    allocUsage: BU_DYNAMIC);
  *(_DWORD *)(HIDWORD(v3) + 28) = 108;
  v29 = 108;
  v16 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
          size: 0xD8u,
          tag: TAG_TEMP,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v28 = v16;
  HIDWORD(v2) = 5;
  LODWORD(v17) = 2;
  *v16 = 3;
  v16[1] = 5;
  v18 = 4;
  v16[2] = 2;
  v16[3] = 3;
  v16[4] = 4;
  v16[5] = 5;
  v16[6] = 1;
  v16[7] = 17;
  v16[8] = 0;
  v16[9] = 1;
  v16[10] = 16;
  v16[11] = 17;
  v16[12] = 2;
  v16[13] = 9;
  v16[14] = 1;
  v16[17] = 9;
  v16[15] = 2;
  v16[16] = 8;
  v16[18] = 0;
  v16[21] = 0;
  v16[20] = 3;
  v16[19] = 21;
  v16[22] = 20;
  v16[23] = 21;
  v32 = v2;
  v16[28] = 5;
  v16[24] = 8;
  v16[25] = 6;
  v16[26] = 11;
  v16[27] = 8;
  v16[29] = 6;
  v16[32] = 9;
  v16[30] = 10;
  v16[31] = 16;
  v16[33] = 10;
  v16[34] = 19;
  v16[35] = 16;
  v16[36] = 11;
  v16[37] = 14;
  v16[38] = 10;
  v16[39] = 11;
  v16[40] = 13;
  v16[41] = 14;
  DWORD2(v17) = v16 + 48;
  v16[42] = 19;
  v16[43] = 15;
  v16[44] = 18;
  v16[45] = 19;
  v16[46] = 14;
  v16[47] = 15;
  *(_QWORD *)&v22.x = v3;
  v16[48] = 7;
  v16[49] = 13;
  v16[50] = 6;
  v16[51] = 7;
  v16[52] = 12;
  v16[53] = 13;
  v16[54] = 23;
  v16[55] = 12;
  v16[56] = 22;
  v16[57] = 23;
  v16[58] = 15;
  v16[59] = 12;
  v16[60] = 4;
  v16[61] = 22;
  v16[62] = 7;
  v16[63] = 4;
  v16[64] = 21;
  v16[65] = 22;
  *(_QWORD *)&v23.x = *(__int64 *)((char *)&v3 + 4);
  *(_QWORD *)&v24.x = v17;
  v16[66] = 20;
  v16[67] = 18;
  v16[68] = 23;
  v16[69] = 20;
  v16[70] = 17;
  v16[71] = 18;
  LOWORD(v17) = LOWORD(v24.y);
  v16[74] = 1;
  v19 = *(_QWORD *)&v23.x;
  v16[73] = v17;
  v16[77] = v17;
  *(_QWORD *)((char *)&v17 + 4) = v32;
  v16[76] = 3;
  v16[72] = WORD5(v17);
  v16[78] = WORD1(v19);
  v16[75] = WORD5(v17);
  v16[79] = 6;
  v16[80] = 5;
  v16[81] = WORD1(v19);
  v16[82] = 7;
  v16[83] = 6;
  v16[84] = 8;
  v16[85] = 10;
  v26 = (idTriangles *)(v16 + 66);
  v16[86] = 9;
  v16[87] = 8;
  v16[88] = 11;
  v16[89] = 10;
  v16[90] = 12;
  v16[91] = 14;
  v16[92] = 13;
  v16[93] = 12;
  v16[94] = 15;
  v16[95] = 14;
  v16[96] = 16;
  v16[97] = 18;
  v16[98] = 17;
  v16[99] = 16;
  v16[100] = 19;
  v16[101] = 18;
  v16[102] = 20;
  v16[103] = 22;
  v16[104] = 21;
  v16[105] = 20;
  v16[106] = WORD3(v17);
  v16[107] = 22;
  v25 = v16 + 102;
  idIndexBuffer::AllocBufferObject(
    this: (idIndexBuffer *)(v19 + 116),
    data: v16,
    allocSize: 2 * *(_DWORD *)(v19 + 28),
    allocUsage: BU_DYNAMIC);
  idStaticModelSurface::idStaticModelSurface(this: &v33);
  v33.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                       this: &idMaterial::resourceList,
                                       name: "_default",
                                       makeDefault: true);
  v33.geometry = (idTriangles *)v19;
  idList<idStaticModelSurface,5>::Append(this: (idList<idStaticModelSurface,5> *)&this->surfaces, obj: &v33);
  y = v22.y;
  if ( (v33.skinRemaps.listStatic == 0 || v33.skinRemaps.listStatic == 2) && v33.skinRemaps.list != nullptr )
  {
    v21 = v27;
    idMem::Free(this: v27, ptr: v33.skinRemaps.list, align: ALIGN_16);
  }
  else
  {
    v21 = v27;
  }
  idMem::Free(this: v21, ptr: v16, align: ALIGN_16);
  if ( y != 0.0 )
    idMem::Free(this: v21, ptr: (void *)LODWORD(y), align: ALIGN_16);
}


// ========================================================================
// __unwind$236201
// EA  : 0x8286A7A8
// RVA : 0x0086A7A8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_236201()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 432 + 136), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$236202
// EA  : 0x8286A7D4
// RVA : 0x0086A7D4
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_236202()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 432 + 152));
}


// ========================================================================
// __unwind$236203
// EA  : 0x8286A7FC
// RVA : 0x0086A7FC
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_236203()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 432 + 144));
}


// ========================================================================
// __unwind$236204
// EA  : 0x8286A824
// RVA : 0x0086A824
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_236204()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 432 + 176));
}


// ========================================================================
// ?FinishStaticModel@idStaticModel@@QAAX_N@Z
// EA  : 0x8286A850
// RVA : 0x0086A850
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::FinishStaticModel(idStaticModel *this, bool cleanup)
{
  int num; // r10
  autospriteType_t materialAutospriteType; // r9
  int v6; // r7
  float *p_referenceBounds; // r31
  int v8; // r27
  int v9; // r28
  idStaticModelSurface *v10; // r29
  idTriangles *geometry; // r3
  float *v12; // r11
  double v13; // fp13
  double v14; // fp12
  double v15; // fp11
  double v16; // fp10
  double v18; // fp7

  num = this->surfaces.num;
  ++this->reloadCount;
  if ( num != 0 )
  {
    materialAutospriteType = this->surfaces.list->material->materialAutospriteType;
    v6 = -materialAutospriteType & ~materialAutospriteType;
    this->modelIsAutosprite = v6 < 0;
    if ( v6 >= 0 )
    {
      p_referenceBounds = (float *)&this->referenceBounds;
      v8 = 0;
      this->referenceBounds.b[0].z = 1.0e30;
      this->referenceBounds.b[0].y = 1.0e30;
      this->referenceBounds.b[0].x = 1.0e30;
      this->referenceBounds.b[1].z = -1.0e30;
      this->referenceBounds.b[1].y = -1.0e30;
      this->referenceBounds.b[1].x = -1.0e30;
      if ( this->surfaces.num > 0 )
      {
        v9 = 0;
        do
        {
          v10 = &this->surfaces.list[v9];
          geometry = v10->geometry;
          if ( geometry == nullptr )
          {
            idStaticModel::MakeDefaultModel(this, low: -8.0, high: 8.0);
            idLib::Error(fmt: "Model %s, surface %i had NULL geometry", this->name.str, v8);
_LN144_1:
            idStaticModel::MakeDefaultModel(this, low: -8.0, high: 8.0);
            idLib::Error(fmt: "Model %s, surface %i had NULL shader", this->name.str, v8);
            JUMPOUT(0x8286AA6C);
          }
          if ( v10->material == nullptr )
            goto _LN144_1;
          if ( cleanup )
            idTriangles::Cleanup(this: geometry, optimize: true);
          v12 = (float *)v10->geometry;
          v13 = p_referenceBounds[1];
          v14 = p_referenceBounds[2];
          v15 = p_referenceBounds[3];
          v16 = p_referenceBounds[4];
          _FP8 = (float)(*p_referenceBounds - *v12);
          v18 = p_referenceBounds[5];
          __asm { fsel      f6, f8, f9, f0 }
          *p_referenceBounds = _FP6;
          _FP4 = (float)((float)v13 - v12[1]);
          __asm { fsel      f3, f4, f5, f13 }
          p_referenceBounds[1] = _FP3;
          _FP1 = (float)((float)v14 - v12[2]);
          __asm { fsel      f0, f1, f2, f12 }
          p_referenceBounds[2] = _FP0;
          _FP12 = (float)(v12[3] - (float)v15);
          __asm { fsel      f11, f12, f13, f11 }
          p_referenceBounds[3] = _FP11;
          _FP8 = (float)(v12[4] - (float)v16);
          __asm { fsel      f6, f8, f9, f10 }
          p_referenceBounds[4] = _FP6;
          _FP4 = (float)(v12[5] - (float)v18);
          __asm { fsel      f3, f4, f5, f7 }
          p_referenceBounds[5] = _FP3;
          if ( (*((_BYTE *)v10->material + 72) & 8) != 0 )
            this->usesTransparencySort = true;
          ++v8;
          ++v9;
        }
        while ( v8 < this->surfaces.num );
      }
      if ( *p_referenceBounds > (double)p_referenceBounds[3] )
      {
        p_referenceBounds[5] = 0.0;
        p_referenceBounds[4] = 0.0;
        p_referenceBounds[3] = 0.0;
        p_referenceBounds[2] = 0.0;
        p_referenceBounds[1] = 0.0;
        *p_referenceBounds = 0.0;
      }
    }
  }
}


// ========================================================================
// ?PristineModelFromOptimizedModel@@YAPAVidStaticModel@@ABV1@@Z
// EA  : 0x8286AA78
// RVA : 0x0086AA78
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

idStaticModel *__fastcall PristineModelFromOptimizedModel(const idStaticModel *model)
{
  const char *v1; // r26
  idStaticModel *v3; // r3
  unsigned __int64 v4; // r28
  idStaticModel *v5; // r18
  float *v6; // r10
  bool *p_modelIsAutosprite; // r11
  int i; // ctr
  double v9; // fp13
  idList<sourceSurface_t,5> *p_sourceSurfaces; // r17
  double v11; // fp12
  double v12; // fp11
  int v13; // r21
  double v14; // fp10
  int v15; // r14
  double v16; // fp9
  int num; // r11
  int v18; // r16
  int renderSurface; // r11
  int v20; // r30
  idTriangles *geometry; // r3
  float *v22; // r9
  int v23; // ctr
  int *p_lastVertex; // r10
  float v25; // r23
  idStaticModelSurface *v26; // r30
  idTriangles *v27; // r4
  const idMaterial *v28; // r22
  double v29; // fp30
  double v30; // fp28
  double v31; // fp31
  double v32; // fp29
  double v33; // fp0
  float v34; // r8
  int v35; // r7
  int v36; // r6
  double v37; // fp12
  double v38; // fp11
  float v39; // r24
  const char *v40; // r4
  int v41; // r26
  idTriangles *v42; // r3
  idTriangles *v43; // r30
  idTriangles *standardTris; // r29
  int v45; // r8
  __int64 v46; // r4
  int v47; // r9
  int v48; // r7
  idDrawVert *v49; // r11
  idDrawVert *v50; // r10
  idDrawVert *v51; // r11
  double v52; // fp6
  int v53; // r11
  int v54; // r10
  idDrawVert *v55; // r11
  double v56; // fp9
  double v57; // fp10
  idDrawVert *v58; // r11
  int v59; // r10
  int v60; // r5
  idDrawVert *v61; // r11
  idStaticModelSurface *v62; // r10
  double v63; // fp13
  double v64; // fp12
  idDrawVert *verts; // r11
  idDrawVert *v66; // r11
  int v67; // r10
  idDrawVert *v68; // r11
  double v69; // fp1
  int v70; // r9
  int v71; // r8
  int v72; // ctr
  idDrawVert *v73; // r11
  idDrawVert *v74; // r10
  idDrawVert *v75; // r11
  double v76; // fp7
  unsigned __int16 *list; // r25
  int v78; // r26
  int v79; // r11
  int v80; // r10
  int v81; // r11
  idBounds *v82; // r3
  idStaticModelSurface *p_st; // [sp+50h] [-1D0h] BYREF
  idList<unsigned short,5> v85; // [sp+60h] [-1C0h] BYREF
  const char *v86; // [sp+70h] [-1B0h]
  float v87[7]; // [sp+7Ch] [-1A4h] BYREF
  idAutoStandardTriangles v88; // [sp+98h] [-188h] BYREF
  idStaticModelSurface v89; // [sp+A0h] [-180h] BYREF
  idStaticModelSurface v90; // [sp+F0h] [-130h] BYREF
  __int64 v91; // [sp+138h] [-E8h]
  idTriangles v92; // [sp+140h] [-E0h] BYREF

  v1 = "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW";
  v86 = "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW";
  v3 = (idStaticModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x194u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  p_st = (idStaticModelSurface *)v3;
  LODWORD(v4) = 0;
  if ( v3 != nullptr )
    v5 = idStaticModel::idStaticModel(this: v3);
  else
    v5 = nullptr;
  v6 = v87;
  p_modelIsAutosprite = &model->modelIsAutosprite;
  for ( i = 6; i != 0; --i )
  {
    p_modelIsAutosprite += 4;
    *++v6 = *(float *)p_modelIsAutosprite;
  }
  v9 = v87[2];
  p_sourceSurfaces = &model->sourceSurfaces;
  v11 = v87[3];
  v12 = v87[4];
  v13 = 0;
  v5->referenceBounds.b[0].x = v87[1];
  p_st = (idStaticModelSurface *)&v5->referenceBounds.b[1];
  v14 = v87[5];
  v15 = 0;
  v5->referenceBounds.b[0].y = v9;
  v5->referenceBounds.b[0].z = v11;
  v5->referenceBounds.b[1].x = v12;
  v16 = v87[6];
  v5->referenceBounds.b[1].y = v14;
  v5->referenceBounds.b[1].z = v16;
  num = model->sourceSurfaces.num;
  if ( num >= 0 )
  {
    v18 = 0;
    while ( 1 )
    {
      p_st = (idStaticModelSurface *)num;
      if ( v15 == num )
        renderSurface = model->surfaces.num;
      else
        renderSurface = p_sourceSurfaces->list[v18].renderSurface;
      if ( v13 < renderSurface )
      {
        HIDWORD(v4) = renderSurface - v13;
        v20 = v13;
        v13 = renderSurface;
        do
        {
          v89.skinOffsets.x = 0.0;
          v89.materialNum = 0;
          v89.skinOffsets.y = 0.0;
          v89.extraGLState = v4;
          v89.skinOffsets.z = 0.0;
          v89.geometry = nullptr;
          v89.skinOffsets.w = 0.0;
          v89.geometryIsReference = false;
          v89.referenceMask = 0;
          memset(&v89.binaryModelId, 0, 16);
          v89.skinRemaps.memTag = 5;
          v89.skinRemaps.listStatic = 0;
          memset(&v89.skinRemaps, 0, 14);
          p_st = &model->surfaces.list[v20];
          geometry = p_st->geometry;
          v89.material = p_st->material;
          v89.geometry = idTriangles::CreateStandardTriangles(this: geometry);
          idList<idStaticModelSurface,5>::Append(this: (idList<idStaticModelSurface,5> *)&v5->surfaces, obj: &v89);
          ++v20;
          if ( v89.skinRemaps.listStatic == 0 || v89.skinRemaps.listStatic == 2 )
          {
            if ( v89.skinRemaps.list != nullptr )
              idMem::Free(this: &mem, ptr: v89.skinRemaps.list, align: ALIGN_16);
            v89.skinRemaps.list = nullptr;
            v89.skinRemaps.size = 0;
          }
          --HIDWORD(v4);
          v89.skinRemaps.num = 0;
        }
        while ( HIDWORD(v4) != 0 );
      }
      if ( v15 == model->sourceSurfaces.num )
        break;
      v22 = v87;
      v23 = 5;
      p_lastVertex = &p_sourceSurfaces->list[v18 - 1].lastVertex;
      do
      {
        *(_DWORD *)++v22 = *++p_lastVertex;
        --v23;
      }
      while ( v23 != 0 );
      v25 = v87[5];
      v26 = &model->surfaces.list[v13];
      v27 = v26->geometry;
      if ( LODWORD(v87[5]) == v27->numVerts - 1 )
        ++v13;
      idAutoStandardTriangles::idAutoStandardTriangles(this: &v88, tri: v27);
      v28 = (const idMaterial *)LODWORD(v87[1]);
      v29 = 1.0;
      v30 = 1.0;
      v31 = 0.0;
      v32 = 0.0;
      if ( v26->material != (const idMaterial *)LODWORD(v87[1]) )
      {
        v33 = *(float *)(LODWORD(v87[1]) + 248);
        v34 = *(float *)(LODWORD(v87[1]) + 252);
        v35 = *(_DWORD *)(LODWORD(v87[1]) + 260) | *(_DWORD *)(LODWORD(v87[1]) + 256);
        v36 = *(_DWORD *)(LODWORD(v87[1]) + 248);
        p_st = (idStaticModelSurface *)(LODWORD(v87[1]) + 248);
        v37 = *(float *)(LODWORD(v87[1]) + 256);
        v38 = *(float *)(LODWORD(v87[1]) + 260);
        p_st = (idStaticModelSurface *)(LODWORD(v87[1]) + 248);
        if ( ((v35 | LODWORD(v34) | v36) & 0x7FFFFFFF) != 0 )
        {
          v31 = -v37;
          v29 = (float)((float)1.0 / (float)v33);
          v32 = -v38;
          v30 = (float)((float)1.0 / v34);
        }
      }
      v39 = v87[4];
      v40 = v1;
      v41 = LODWORD(v25) - LODWORD(v87[4]) + 1;
      v42 = (idTriangles *)idMem::AllocWithLocation(
                             this: &mem,
                             location: v40,
                             size: 0x84u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      p_st = (idStaticModelSurface *)v42;
      if ( v42 != nullptr )
        v43 = idTriangles::idTriangles(this: v42);
      else
        v43 = nullptr;
      idTriangles::AllocStaticTriSurfVerts(this: v43, numVerts: LODWORD(v25) - LODWORD(v39) + 1);
      standardTris = (idTriangles *)v88.standardTris;
      v43->numVerts = v41;
      v45 = 0;
      if ( v41 >= 4 )
      {
        LODWORD(v46) = LODWORD(v39) + 2;
        HIDWORD(v46) = LODWORD(v39) + 3;
        v47 = 0;
        v48 = LODWORD(v39);
        do
        {
          v49 = &standardTris->verts[v48];
          v50 = &v43->verts[v47];
          v50->xyz.x = v49->xyz.x;
          v50->xyz.y = v49->xyz.y;
          v50->xyz.z = v49->xyz.z;
          v50->st.x = v49->st.x;
          v50->st.y = v49->st.y;
          v50->normal[0] = v49->normal[0];
          v50->normal[1] = v49->normal[1];
          v50->normal[2] = v49->normal[2];
          v50->normal[3] = v49->normal[3];
          v50->tangent[0] = v49->tangent[0];
          v50->tangent[1] = v49->tangent[1];
          v50->tangent[2] = v49->tangent[2];
          v50->tangent[3] = v49->tangent[3];
          v50->color[0] = v49->color[0];
          v50->color[1] = v49->color[1];
          v50->color[2] = v49->color[2];
          v50->color[3] = v49->color[3];
          v51 = &v43->verts[v47];
          v52 = (float)(v51->st.y - (float)v32);
          v51->st.x = (float)(v51->st.x - (float)v31) * (float)v29;
          p_st = (idStaticModelSurface *)&v51->st;
          v51->st.y = (float)v52 * (float)v30;
          v53 = (int)&standardTris->verts[v48 + 1];
          v54 = (int)&v43->verts[v47 + 1];
          *(float *)v54 = *(float *)v53;
          *(float *)(v54 + 4) = *(float *)(v53 + 4);
          *(float *)(v54 + 8) = *(float *)(v53 + 8);
          *(float *)(v54 + 12) = *(float *)(v53 + 12);
          *(float *)(v54 + 16) = *(float *)(v53 + 16);
          *(_BYTE *)(v54 + 20) = *(_BYTE *)(v53 + 20);
          *(_BYTE *)(v54 + 21) = *(_BYTE *)(v53 + 21);
          *(_BYTE *)(v54 + 22) = *(_BYTE *)(v53 + 22);
          *(_BYTE *)(v54 + 23) = *(_BYTE *)(v53 + 23);
          *(_BYTE *)(v54 + 24) = *(_BYTE *)(v53 + 24);
          *(_BYTE *)(v54 + 25) = *(_BYTE *)(v53 + 25);
          v91 = v46;
          *(_BYTE *)(v54 + 26) = *(_BYTE *)(v53 + 26);
          *(_BYTE *)(v54 + 27) = *(_BYTE *)(v53 + 27);
          *(_BYTE *)(v54 + 28) = *(_BYTE *)(v53 + 28);
          *(_BYTE *)(v54 + 29) = *(_BYTE *)(v53 + 29);
          *(_BYTE *)(v54 + 30) = *(_BYTE *)(v53 + 30);
          *(_BYTE *)(v54 + 31) = *(_BYTE *)(v53 + 31);
          v55 = &v43->verts[v47];
          v56 = (float)(v55[1].st.y - (float)v32);
          v57 = (float)(v55[1].st.x - (float)v31);
          p_st = (idStaticModelSurface *)&v55[1].st;
          v55[1].st.x = (float)v57 * (float)v29;
          v55[1].st.y = (float)v56 * (float)v30;
          v58 = &standardTris->verts[v46 + v45];
          v59 = (int)&v43->verts[v47 + 2];
          v60 = HIDWORD(v46) + v45;
          v45 += 4;
          *(float *)v59 = v58->xyz.x;
          *(float *)(v59 + 4) = v58->xyz.y;
          *(float *)(v59 + 8) = v58->xyz.z;
          *(float *)(v59 + 12) = v58->st.x;
          *(float *)(v59 + 16) = v58->st.y;
          *(_BYTE *)(v59 + 20) = v58->normal[0];
          *(_BYTE *)(v59 + 21) = v58->normal[1];
          *(_BYTE *)(v59 + 22) = v58->normal[2];
          *(_BYTE *)(v59 + 23) = v58->normal[3];
          *(_BYTE *)(v59 + 24) = v58->tangent[0];
          *(_BYTE *)(v59 + 25) = v58->tangent[1];
          *(_BYTE *)(v59 + 26) = v58->tangent[2];
          *(_BYTE *)(v59 + 27) = v58->tangent[3];
          *(_BYTE *)(v59 + 28) = v58->color[0];
          *(_BYTE *)(v59 + 29) = v58->color[1];
          *(_BYTE *)(v59 + 30) = v58->color[2];
          *(_BYTE *)(v59 + 31) = v58->color[3];
          v61 = &v43->verts[v47];
          v62 = (idStaticModelSurface *)&v61[2].st;
          v63 = (float)(v61[2].st.x - (float)v31);
          v64 = (float)(v61[2].st.y - (float)v32);
          p_st = (idStaticModelSurface *)&v61[2].st;
          v61[2].st.x = (float)v63 * (float)v29;
          v61[2].st.y = (float)v64 * (float)v30;
          verts = standardTris->verts;
          v48 += 4;
          p_st = v62;
          v66 = &verts[v60];
          v46 = v91;
          v67 = (int)&v43->verts[v47 + 3];
          *(float *)v67 = v66->xyz.x;
          *(float *)(v67 + 4) = v66->xyz.y;
          *(float *)(v67 + 8) = v66->xyz.z;
          *(float *)(v67 + 12) = v66->st.x;
          *(float *)(v67 + 16) = v66->st.y;
          *(_BYTE *)(v67 + 20) = v66->normal[0];
          *(_BYTE *)(v67 + 21) = v66->normal[1];
          *(_BYTE *)(v67 + 22) = v66->normal[2];
          *(_BYTE *)(v67 + 23) = v66->normal[3];
          *(_BYTE *)(v67 + 24) = v66->tangent[0];
          *(_BYTE *)(v67 + 25) = v66->tangent[1];
          *(_BYTE *)(v67 + 26) = v66->tangent[2];
          *(_BYTE *)(v67 + 27) = v66->tangent[3];
          *(_BYTE *)(v67 + 28) = v66->color[0];
          *(_BYTE *)(v67 + 29) = v66->color[1];
          *(_BYTE *)(v67 + 30) = v66->color[2];
          *(_BYTE *)(v67 + 31) = v66->color[3];
          v68 = &v43->verts[v47];
          v69 = (float)(v68[3].st.y - (float)v32);
          v68[3].st.x = (float)(v68[3].st.x - (float)v31) * (float)v29;
          v47 += 4;
          p_st = (idStaticModelSurface *)&v68[3].st;
          v68[3].st.y = (float)v30 * (float)v69;
        }
        while ( v45 < LODWORD(v25) - LODWORD(v39) - 2 );
      }
      if ( v45 < v41 )
      {
        v70 = v45;
        v72 = v41 - v45;
        v71 = v45 + LODWORD(v39);
        do
        {
          v73 = &standardTris->verts[v71];
          v74 = &v43->verts[v70];
          ++v71;
          v74->xyz.x = v73->xyz.x;
          v74->xyz.y = v73->xyz.y;
          v74->xyz.z = v73->xyz.z;
          v74->st.x = v73->st.x;
          v74->st.y = v73->st.y;
          v74->normal[0] = v73->normal[0];
          v74->normal[1] = v73->normal[1];
          v74->normal[2] = v73->normal[2];
          v74->normal[3] = v73->normal[3];
          v74->tangent[0] = v73->tangent[0];
          v74->tangent[1] = v73->tangent[1];
          v74->tangent[2] = v73->tangent[2];
          v74->tangent[3] = v73->tangent[3];
          v74->color[0] = v73->color[0];
          v74->color[1] = v73->color[1];
          v74->color[2] = v73->color[2];
          v74->color[3] = v73->color[3];
          v75 = &v43->verts[v70];
          v76 = (float)(v75->st.x - (float)v31);
          v75->st.y = (float)v30 * (float)(v75->st.y - (float)v32);
          ++v70;
          p_st = (idStaticModelSurface *)&v75->st;
          v75->st.x = (float)v76 * (float)v29;
          --v72;
        }
        while ( v72 != 0 );
      }
      list = nullptr;
      HIDWORD(v4) = 0;
      *(_WORD *)&v85.memTag = 1280;
      memset(&v85, 0, 14);
      v78 = 0;
      if ( standardTris->numIndexes > 0 )
      {
        do
        {
          v79 = *(unsigned __int16 *)((char *)standardTris->indexes + HIDWORD(v4));
          if ( v79 > SLODWORD(v25) )
            break;
          if ( v79 >= SLODWORD(v39) )
          {
            HIWORD(p_st) = *(unsigned __int16 *)((char *)standardTris->indexes + HIDWORD(v4));
            idList<unsigned short,72>::Append(this: &v85, obj: (unsigned __int16 *)&p_st);
          }
          ++v78;
          HIDWORD(v4) += 2;
        }
        while ( v78 < standardTris->numIndexes );
        HIDWORD(v4) = v85.num;
        list = v85.list;
      }
      idTriangles::AllocStaticTriSurfIndexes(this: v43, numIndexes: SHIDWORD(v4));
      v80 = 0;
      v43->numIndexes = HIDWORD(v4);
      if ( SHIDWORD(v4) > 0 )
      {
        v81 = 0;
        do
        {
          ++v80;
          v43->indexes[v81] = list[v81];
          ++v81;
        }
        while ( v80 < v43->numIndexes );
      }
      v82 = idTriangles::BoundsFromVertScan(this: &v92, result: &v43->bounds);
      v43->bounds.b[0].x = v82->b[0].x;
      v90.skinOffsets.x = 0.0;
      v90.skinOffsets.y = 0.0;
      v90.skinOffsets.z = 0.0;
      p_st = (idStaticModelSurface *)&v82->b[1];
      v90.skinOffsets.w = 0.0;
      v90.materialNum = 0;
      v90.extraGLState = v4;
      v90.geometryIsReference = false;
      v90.referenceMask = 0;
      memset(&v90.binaryModelId, 0, 16);
      v90.skinRemaps.memTag = 5;
      v90.skinRemaps.listStatic = 0;
      memset(&v90.skinRemaps, 0, 14);
      v43->bounds.b[0].y = v82->b[0].y;
      v43->bounds.b[0].z = v82->b[0].z;
      v43->bounds.b[1] = v82->b[1];
      v90.material = v28;
      v90.geometry = v43;
      idList<idStaticModelSurface,5>::Append(this: (idList<idStaticModelSurface,5> *)&v5->surfaces, obj: &v90);
      if ( v90.skinRemaps.listStatic == 0 || v90.skinRemaps.listStatic == 2 )
      {
        if ( v90.skinRemaps.list != nullptr )
          idMem::Free(this: &mem, ptr: v90.skinRemaps.list, align: ALIGN_16);
        v90.skinRemaps.list = nullptr;
        v90.skinRemaps.size = 0;
      }
      v90.skinRemaps.num = 0;
      if ( v85.listStatic == 0 || v85.listStatic == 2 )
      {
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        v85.list = nullptr;
        v85.size = 0;
      }
      v85.num = 0;
      if ( v88.freeOnDelete )
      {
        idTriangles::~idTriangles(this: standardTris);
        idMem::Free(this: &mem, ptr: standardTris, align: ALIGN_16);
      }
      num = model->sourceSurfaces.num;
      ++v15;
      ++v18;
      if ( v15 > num )
        break;
      v1 = v86;
    }
  }
  return v5;
}


// ========================================================================
// __unwind$237001
// EA  : 0x8286B448
// RVA : 0x0086B448
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall _unwind_237001(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 544 + 80), tag: a2);
}


// ========================================================================
// __unwind$237002
// EA  : 0x8286B470
// RVA : 0x0086B470
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237002()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 544 + 160));
}


// ========================================================================
// __unwind$237003
// EA  : 0x8286B498
// RVA : 0x0086B498
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237003()
{
  int v0; // r12

  idAutoStandardTriangles::~idAutoStandardTriangles(this: (idAutoStandardTriangles *)(v0 - 544 + 152));
}


// ========================================================================
// __unwind$237004
// EA  : 0x8286B4C0
// RVA : 0x0086B4C0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall _unwind_237004(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 544 + 80), tag: a2);
}


// ========================================================================
// __unwind$237005
// EA  : 0x8286B4E8
// RVA : 0x0086B4E8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237005()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 544 + 96));
}


// ========================================================================
// __unwind$237006
// EA  : 0x8286B510
// RVA : 0x0086B510
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237006()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 544 + 240));
}


// ========================================================================
// ?TestPristineModelFromOptimizedModel_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8286B540
// RVA : 0x0086B540
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall TestPristineModelFromOptimizedModel_f(const idCmdArgs *args)
{
  idFileList *v1; // r26
  int v2; // r24
  int v3; // r27
  const char *data; // r28
  idStaticModel *v5; // r3
  idStaticModel *v6; // r29
  idStaticModel *v7; // r3
  idStaticModel *v8; // r30
  idStaticModel *v9; // [sp+5Ch] [-84h]

  v1 = fileSystem->ListFilesTree(this: fileSystem, a2: "models", a3: "lwo", a4: 0);
  v2 = 0;
  if ( v1->list.num > 0 )
  {
    v3 = 0;
    do
    {
      data = v1->list.list[v3].data;
      idLib::Printf(fmt: "loading %s.\n", data);
      v5 = (idStaticModel *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x194u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      if ( v5 != nullptr )
        v6 = idStaticModel::idStaticModel(this: v5);
      else
        v6 = nullptr;
      idResource::SetName(this: v6, _name: data);
      v6->pristine = true;
      v6->LoadResource(this: v6);
      fileSystem->RemoveFile(this: fileSystem, a2: v6->binaryFileName, a3: FSPATH_BASE);
      v7 = (idStaticModel *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x194u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
        v8 = idStaticModel::idStaticModel(this: v7);
      else
        v8 = nullptr;
      idResource::SetName(this: v8, _name: data);
      v8->LoadResource(this: v8);
      v9 = PristineModelFromOptimizedModel(model: v8);
      idLib::Printf(fmt: "----- normal -----\n");
      v8->Print(this: v8);
      idLib::Printf(fmt: "----- pristine -----\n");
      v6->Print(this: v6);
      idLib::Printf(fmt: "----- converted -----\n");
      v9->Print(this: v9);
      ((void (__fastcall *)(idStaticModel *, int))v9->dtr_idResource)(a1: v9, a2: 1);
      ((void (__fastcall *)(idStaticModel *, int))v8->dtr_idResource)(a1: v8, a2: 1);
      ((void (__fastcall *)(idStaticModel *, int))v6->dtr_idResource)(a1: v6, a2: 1);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->list.num );
  }
  idFileList::~idFileList(this: v1);
  idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// __unwind$237687
// EA  : 0x8286B7A4
// RVA : 0x0086B7A4
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237687()
{
  int v0; // r12

  std::auto_ptr<idFileList>::~auto_ptr<idFileList>(this: (std::auto_ptr<idFileList> *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$237688
// EA  : 0x8286B7CC
// RVA : 0x0086B7CC
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall _unwind_237688(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 224 + 84), tag: a2);
}


// ========================================================================
// __unwind$237689
// EA  : 0x8286B7F4
// RVA : 0x0086B7F4
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237689()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 224 + 84));
}


// ========================================================================
// __unwind$237690
// EA  : 0x8286B81C
// RVA : 0x0086B81C
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall _unwind_237690(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 224 + 88), tag: a2);
}


// ========================================================================
// __unwind$237691
// EA  : 0x8286B844
// RVA : 0x0086B844
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237691()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 224 + 88));
}


// ========================================================================
// __unwind$237692
// EA  : 0x8286B86C
// RVA : 0x0086B86C
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237692()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 224 + 92));
}


// ========================================================================
// ?MakeSimpleCube@idStaticModel@@QAAXMM@Z
// EA  : 0x8286B8A0
// RVA : 0x0086B8A0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::MakeSimpleCube(idStaticModel *this, double low, double high)
{
  idTriangles *v5; // r3
  idTriangles *v6; // r30
  int v8; // r10
  float **p_verts; // r11
  int v11; // ctr
  float *v13; // r10
  float *v14; // r10
  float *v15; // r10
  float *v16; // r10
  float *v17; // r10
  float *v18; // r10
  float *v19; // r10
  float *v20; // r11
  idStaticModelSurface v21; // [sp+60h] [-80h] BYREF

  idStaticModel::FreeSurfaces(this);
  v5 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idTriangles::idTriangles(this: v5);
  else
    v6 = nullptr;
  idTriangles::AllocStaticTriSurfVerts(this: v6, numVerts: 8);
  idTriangles::AllocStaticTriSurfIndexes(this: v6, numIndexes: 36);
  __asm { vspltisw128 v63, 0 }
  v6->numVerts = 8;
  v8 = 0;
  __asm { vcmpequw128 v62, v95, v63 }
  v6->numIndexes = 36;
  p_verts = (float **)&v6->verts;
  _R8 = 16;
  v11 = 8;
  __asm { vsldoi128 v62, v95, v62, 4 }
  do
  {
    _R9 = &(*p_verts)[v8];
    v8 += 8;
    __asm
    {
      stvx128   v63, r0, r9
      stvx128   v62, r9, r8
    }
    --v11;
  }
  while ( v11 != 0 );
  v13 = *p_verts;
  v13[1] = low;
  v13[2] = low;
  *v13 = low;
  v14 = *p_verts;
  v14[8] = high;
  v14[9] = low;
  v14[10] = low;
  v15 = *p_verts;
  v15[16] = high;
  v15[17] = high;
  v15[18] = low;
  v16 = *p_verts;
  v16[24] = low;
  v16[25] = high;
  v16[26] = low;
  v17 = *p_verts;
  v17[32] = low;
  v17[33] = low;
  v17[34] = high;
  v18 = *p_verts;
  v18[40] = high;
  v18[41] = low;
  v18[42] = high;
  v19 = *p_verts;
  v19[48] = high;
  v19[49] = high;
  v19[50] = high;
  v20 = *p_verts;
  v20[57] = high;
  v20[58] = high;
  v20[56] = low;
  *v6->indexes = 2;
  v6->indexes[1] = 3;
  v6->indexes[2] = 0;
  v6->indexes[3] = 1;
  v6->indexes[4] = 2;
  v6->indexes[5] = 0;
  v6->indexes[6] = 5;
  v6->indexes[7] = 1;
  v6->indexes[8] = 0;
  v6->indexes[9] = 4;
  v6->indexes[10] = 5;
  v6->indexes[11] = 0;
  v6->indexes[12] = 7;
  v6->indexes[13] = 4;
  v6->indexes[14] = 0;
  v6->indexes[15] = 3;
  v6->indexes[16] = 7;
  v6->indexes[17] = 0;
  v6->indexes[18] = 1;
  v6->indexes[19] = 5;
  v6->indexes[20] = 6;
  v6->indexes[21] = 2;
  v6->indexes[22] = 1;
  v6->indexes[23] = 6;
  v6->indexes[24] = 3;
  v6->indexes[25] = 2;
  v6->indexes[26] = 6;
  v6->indexes[27] = 7;
  v6->indexes[28] = 3;
  v6->indexes[29] = 6;
  v6->indexes[30] = 4;
  v6->indexes[31] = 7;
  v6->indexes[32] = 6;
  v6->indexes[33] = 5;
  v6->indexes[34] = 4;
  v6->indexes[35] = 6;
  v6->generateNormals = true;
  idStaticModelSurface::idStaticModelSurface(this: &v21);
  v21.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                       this: &idMaterial::resourceList,
                                       name: "_default",
                                       makeDefault: true);
  v21.geometry = v6;
  idList<idStaticModelSurface,5>::Append(this: (idList<idStaticModelSurface,5> *)&this->surfaces, obj: &v21);
  idStaticModel::FinishStaticModel(this, cleanup: true);
  idStaticModel::UpdateBuffers(this);
  idStaticModel::FreeCPUData(this);
  if ( (v21.skinRemaps.listStatic == 0 || v21.skinRemaps.listStatic == 2) && v21.skinRemaps.list != nullptr )
    idMem::Free(this: &mem, ptr: v21.skinRemaps.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$237974
// EA  : 0x8286BC2C
// RVA : 0x0086BC2C
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237974()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 224 + 80), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$237975
// EA  : 0x8286BC58
// RVA : 0x0086BC58
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_237975()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 224 + 96));
}


// ========================================================================
// ?ReadStaticBModel@idStaticModel@@AAA_NPBD@Z
// EA  : 0x8286BC88
// RVA : 0x0086BC88
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

int __fastcall idStaticModel::ReadStaticBModel(idStaticModel *this, const char *fileName)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  idFile *v7; // r3
  unsigned int v9; // r3
  idFile *file; // r11
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  unsigned int sourceTimeStamp; // r11
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  int v18; // r4
  idList<idStaticModelSurface,84> *p_surfaces; // r21
  int v20; // r26
  __int64 v21; // r10
  __int64 v22; // r8
  idTriangles *v23; // r3
  idTriangles *v24; // r30
  __int64 v25; // r8
  __int64 v26; // r6
  __int64 v27; // r10
  int v28; // r28
  int v29; // r29
  sourceSurface_t *list; // r11
  sourceSurface_t *v31; // r30
  const idDecl *v32; // r3
  int v33; // r28
  int v34; // r30
  idStaticModelSurface *v35; // r29
  const idMaterial *v36; // r3
  int v37; // [sp+8h] [-188h]
  int v38; // [sp+8h] [-188h]
  int v39; // [sp+Ch] [-184h]
  int v40; // [sp+Ch] [-184h]
  int v41; // [sp+10h] [-180h]
  int v42; // [sp+10h] [-180h]
  int v43; // [sp+14h] [-17Ch]
  int v44; // [sp+14h] [-17Ch]
  int v45; // [sp+18h] [-178h]
  int v46; // [sp+18h] [-178h]
  int v47; // [sp+1Ch] [-174h]
  int v48; // [sp+1Ch] [-174h]
  idFileLocal v49; // [sp+50h] [-140h] BYREF
  int v50; // [sp+54h] [-13Ch] BYREF
  int v51; // [sp+58h] [-138h] BYREF
  int v52; // [sp+5Ch] [-134h] BYREF
  int v53; // [sp+60h] [-130h] BYREF
  int v54[3]; // [sp+64h] [-12Ch] BYREF
  idStr v55; // [sp+70h] [-120h] BYREF
  idStr v56; // [sp+90h] [-100h] BYREF
  idTriangles *v57; // [sp+B0h] [-E0h]
  idStr v58; // [sp+C0h] [-D0h] BYREF
  idStaticModelSurface v59[2]; // [sp+E0h] [-B0h] BYREF

  idStaticModel::FreeSurfaces(this);
  idResource::SetResourceError(
    this,
    fmt: nullptr,
    a3: v6,
    a4: v5,
    a5: v4,
    a6: v37,
    a7: v39,
    a8: v41,
    a9: v43,
    a10: v45,
    a11: v47);
  this->binaryTimeStamp = -1;
  v7 = fileSystem->OpenFileRead(this: fileSystem, a2: fileName, a3: 1, a4: 0);
  v49.file = v7;
  if ( v7 == nullptr )
  {
    idFileLocal::~idFileLocal(this: &v49);
    return 0;
  }
  v9 = v7->Timestamp(this: v7);
  file = v49.file;
  this->binaryTimeStamp = v9;
  file->Read(this: file, a2: &v51, a3: 4u);
  HIDWORD(v12) = 457965568;
  LODWORD(v13) = v51;
  if ( v51 != 457985346 )
  {
    HIDWORD(v13) = fileName;
    idResource::SetResourceError(
      this,
      fmt: "bad magic on staticmodel '%s'",
      a3: v13,
      a4: v12,
      a5: v11,
      a6: v38,
      a7: v40,
      a8: v42,
      a9: v44,
      a10: v46,
      a11: v48);
    idFileLocal::~idFileLocal(this: &v49);
    return 0;
  }
  v49.file->Read(this: v49.file, a2: &this->sourceTimeStamp, a3: 4u);
  sourceTimeStamp = this->sourceTimeStamp;
  if ( sourceTimeStamp == 0 || sourceTimeStamp == -1 )
    this->sourceTimeStamp = this->binaryTimeStamp;
  v49.file->Read(this: v49.file, a2: &v50, a3: 4u);
  v18 = v50;
  if ( v50 < 0 )
  {
    HIDWORD(v17) = fileName;
    idResource::SetResourceError(
      this,
      fmt: "bad numSurfaces on staticmodel '%s'",
      a3: v17,
      a4: v16,
      a5: v15,
      a6: v38,
      a7: v40,
      a8: v42,
      a9: v44,
      a10: v46,
      a11: v48);
    idFileLocal::~idFileLocal(this: &v49);
    return 0;
  }
  p_surfaces = &this->surfaces;
  if ( v50 > this->surfaces.size )
  {
    idList<idStaticModelSurface,84>::Resize(this: (idList<idStaticModelSurface,5> *)&this->surfaces, newsize: v50);
    v18 = v50;
  }
  v20 = 0;
  if ( v18 <= 0 )
  {
LABEL_21:
    v49.file->Read(this: v49.file, a2: v54, a3: 4u);
    idList<sourceSurface_t,5>::SetNum(this: &this->sourceSurfaces, newNum: v54[0]);
    v28 = 0;
    if ( this->sourceSurfaces.num > 0 )
    {
      v29 = 0;
      do
      {
        list = this->sourceSurfaces.list;
        v56.allocedAndFlag = 20;
        v56.data = v56.baseBuffer;
        v31 = &list[v29];
        v56.len = 0;
        v56.baseBuffer[0] = 0;
        idFile::ReadString(this: v49.file, string: &v56);
        if ( v56.data != nullptr )
          v32 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v56.data, makeDefault: true);
        else
          v32 = nullptr;
        v31->mtr = (const idMaterial *)v32;
        v49.file->Read(this: v49.file, a2: &v31->mtrChecksum, a3: 4u);
        v49.file->Read(this: v49.file, a2: &v31->renderSurface, a3: 4u);
        v49.file->Read(this: v49.file, a2: &v31->firstVertex, a3: 4u);
        v49.file->Read(this: v49.file, a2: &v31->lastVertex, a3: 4u);
        idStr::FreeData(this: &v56);
        ++v28;
        ++v29;
      }
      while ( v28 < this->sourceSurfaces.num );
    }
    if ( idLib::production < PROD_PRODUCTION )
    {
      idStr::idStr(this: &v58, text: this->name.str);
      idStr::StripFileExtension(this: &v58);
      if ( v58.data != nullptr
        && idDeclInfo::FindWithInheritance(this: &idDeclSkins::resourceList, name: v58.data, makeDefault: false) != nullptr )
      {
        if ( this->sourceSurfaces.num == 0 )
        {
LABEL_46:
          idStaticModel::FreeSurfaces(this);
          idStr::FreeData(this: &v58);
          idFileLocal::~idFileLocal(this: &v49);
          return 0;
        }
        v33 = 0;
        if ( this->surfaces.num > 0 )
        {
          v34 = 0;
          do
          {
            v35 = p_surfaces->list;
            v36 = idMaterial::CompatibleGenericMaterial(this: p_surfaces->list[v34].material);
            if ( v36 != nullptr && v35[v34].material != v36 )
              goto LABEL_46;
            ++v33;
            ++v34;
          }
          while ( v33 < this->surfaces.num );
        }
      }
      idStr::FreeData(this: &v58);
    }
    idStaticModel::FinishStaticModel(this, cleanup: false);
    idStaticModel::RemapSourceSurfaces(this);
    if ( (this->modelLoadFlags & 2) != 0 )
      idStaticModel::UpdateBuffers(this);
    if ( (this->modelLoadFlags & 1) == 0 )
      idStaticModel::FreeCPUData(this);
    idFileLocal::~idFileLocal(this: &v49);
    return 1;
  }
  while ( 1 )
  {
    v55.allocedAndFlag = 20;
    v55.len = 0;
    v55.data = v55.baseBuffer;
    v55.baseBuffer[0] = 0;
    idFile::ReadString(this: v49.file, string: &v55);
    LODWORD(v21) = idMaterial::IsValidMaterialName(name: v55.data, allowUnderscore: true, allowAmpersand: true);
    if ( (_DWORD)v21 == 0 )
    {
      idResource::SetResourceError(
        this,
        fmt: "StaticModel '%s' contains invalid materialname '%s'",
        a3: __SPAIR64__((unsigned int)fileName, (unsigned int)v55.data),
        a4: v22,
        a5: v21,
        a6: v38,
        a7: v40,
        a8: v42,
        a9: v44,
        a10: v46,
        a11: v48);
      idStr::FreeData(this: &v55);
      idFileLocal::~idFileLocal(this: &v49);
      return 0;
    }
    v53 = 0;
    v49.file->Read(this: v49.file, a2: &v53, a3: 4u);
    v52 = 0;
    v49.file->Read(this: v49.file, a2: &v52, a3: 4u);
    v23 = (idTriangles *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x84u,
                           tag: TAG_TRIANGLES,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    v57 = v23;
    if ( v23 != nullptr )
      v24 = idTriangles::idTriangles(this: v23);
    else
      v24 = nullptr;
    if ( (this->modelLoadFlags & 2) == 0 )
      v24->allowGpuHosting = false;
    idTriangles::ReadFromFile(this: v24, file: v49.file);
    v49.file->Read(this: v49.file, a2: &v51, a3: 4u);
    HIDWORD(v27) = v51;
    if ( v51 != 457985346 )
      break;
    idStaticModelSurface::idStaticModelSurface(this: v59);
    v59[0].material = FindMaterialOrAutoMaterial(name: v55.data);
    v59[0].geometry = v24;
    v59[0].binaryModelId = v52;
    v59[0].materialNum = v53;
    idList<idStaticModelSurface,5>::Append(this: (idList<idStaticModelSurface,5> *)&this->surfaces, obj: v59);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v59[0].skinRemaps);
    idStr::FreeData(this: &v55);
    if ( ++v20 >= v50 )
      goto LABEL_21;
  }
  HIDWORD(v26) = fileName;
  idResource::SetResourceError(
    this,
    fmt: "Bad trailing magic on staticmodel '%s'",
    a3: v26,
    a4: v25,
    a5: v27,
    a6: v38,
    a7: v40,
    a8: v42,
    a9: v44,
    a10: v46,
    a11: v48);
  if ( v24 != nullptr )
  {
    idTriangles::~idTriangles(this: v24);
    idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
  }
  idStaticModel::FreeSurfaces(this);
  idStr::FreeData(this: &v55);
  idFileLocal::~idFileLocal(this: &v49);
  return 0;
}


// ========================================================================
// __unwind$238420
// EA  : 0x8286C260
// RVA : 0x0086C260
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_238420()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 400 + 80));
}


// ========================================================================
// __unwind$238421
// EA  : 0x8286C288
// RVA : 0x0086C288
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_238421()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$238422
// EA  : 0x8286C2B0
// RVA : 0x0086C2B0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_238422()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 400 + 176), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$238423
// EA  : 0x8286C2DC
// RVA : 0x0086C2DC
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_238423()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 400 + 224));
}


// ========================================================================
// __unwind$238424
// EA  : 0x8286C304
// RVA : 0x0086C304
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_238424()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 144));
}


// ========================================================================
// __unwind$238425
// EA  : 0x8286C32C
// RVA : 0x0086C32C
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void _unwind_238425()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 192));
}


// ========================================================================
// ?LoadResource@idStaticModel@@UAAXXZ
// EA  : 0x8286C358
// RVA : 0x0086C358
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __fastcall idStaticModel::LoadResource(idStaticModel *this)
{
  const char *str; // r3
  char *v3; // r3
  BOOL v4; // r28
  char *binaryFileName; // r30
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  const char *v9; // r5
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  unsigned int v13; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  int v20; // [sp+8h] [-78h]
  int v21; // [sp+Ch] [-74h]
  int v22; // [sp+10h] [-70h]
  int v23; // [sp+14h] [-6Ch]
  int v24; // [sp+18h] [-68h]
  int v25; // [sp+1Ch] [-64h]

  str = this->name.str;
  this->isReloadable = true;
  v3 = strstr(str1: str, str2: ".bmodel");
  v4 = v3 != nullptr;
  if ( v3 != nullptr )
  {
    binaryFileName = this->binaryFileName;
    idStr::Copynz(dest: this->binaryFileName, src: this->name.str, destsize: 256);
  }
  else
  {
    if ( this->pristine )
      v9 = "pmodel";
    else
      v9 = "bmodel";
    binaryFileName = this->binaryFileName;
    fileSystem->FixLongFilename(
      this: fileSystem,
      a2: "generated",
      a3: v9,
      a4: this->name.str,
      a5: this->binaryFileName,
      a6: 256);
  }
  if ( this->pristine && !v4 || (unsigned __int8)idStaticModel::ReadStaticBModel(this, fileName: binaryFileName) == 0 )
  {
    if ( idLib::production != PROD_DEVELOPMENT )
    {
      HIDWORD(v8) = this->name.str;
      idResource::SetResourceError(
        this,
        fmt: "Production model not found '%s'",
        a3: v8,
        a4: v7,
        a5: v6,
        a6: v20,
        a7: v21,
        a8: v22,
        a9: v23,
        a10: v24,
        a11: v25);
      idStaticModel::MakeDefaultModel(this, low: -8.0, high: 8.0);
      return;
    }
    v13 = fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false);
    this->sourceTimeStamp = v13;
    if ( v13 == -1 )
    {
      HIDWORD(v12) = this->name.str;
      idResource::SetResourceError(
        this,
        fmt: "Static model source file '%s' File not found",
        a3: v12,
        a4: v11,
        a5: v10,
        a6: v20,
        a7: v21,
        a8: v22,
        a9: v23,
        a10: v24,
        a11: v25);
      idStaticModel::MakeDefaultModel(this, low: -8.0, high: 8.0);
      return;
    }
    if ( idStaticModel::GenerateBinaryModelFile(this, sourceFile: this->name.str, binaryFile: binaryFileName) )
    {
      if ( (unsigned __int8)idStaticModel::ReadStaticBModel(this, fileName: binaryFileName) != 0 )
        return;
      HIDWORD(v19) = this->name.str;
      idResource::SetResourceError(
        this,
        fmt: "Static model ReadStaticBModel( '%s' ) failed",
        a3: v19,
        a4: v18,
        a5: v17,
        a6: v20,
        a7: v21,
        a8: v22,
        a9: v23,
        a10: v24,
        a11: v25);
      idLib::Warning(fmt: "Failed to load after generating %s", this->name.str);
    }
    else
    {
      HIDWORD(v16) = this->name.str;
      idResource::SetResourceError(
        this,
        fmt: "Static model GenerateBinaryModelFile( '%s' ) failed",
        a3: v16,
        a4: v15,
        a5: v14,
        a6: v20,
        a7: v21,
        a8: v22,
        a9: v23,
        a10: v24,
        a11: v25);
      idLib::Warning(fmt: "GenerateBinaryModelFile( '%s' ) failed", this->name.str);
    }
    idStaticModel::MakeDefaultModel(this, low: -8.0, high: 8.0);
  }
}


// ========================================================================
// `dynamic initializer for 'idStaticModel::resourceList''
// EA  : 0x83344BF0
// RVA : 0x01344BF0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idStaticModel::resourceList__()
{
  idResourceList::idResourceList(this: &idStaticModel::resourceList, typeName: "model");
  idStaticModel::resourceList.__vftable = (idTypedResourceList<idStaticModel>_vtbl *)&idTypedResourceList<idStaticModel>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idStaticModel::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'r_freeTriangleCPUData''
// EA  : 0x83344C40
// RVA : 0x01344C40
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_freeTriangleCPUData__()
{
  idCVar::idCVar(
    this: &r_freeTriangleCPUData,
    name: "r_freeTriangleCPUData",
    value: "1",
    flags: 1,
    description: "dump the CPU data after building vertex buffers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_freeTriangleCPUData__);
}


// ========================================================================
// `dynamic initializer for 'reportStaticModelMemory_v''
// EA  : 0x83344C98
// RVA : 0x01344C98
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportStaticModelMemory_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportStaticModelMemory_v,
           cmdName: "reportStaticModelMemory",
           function: reportStaticModelMemory_f,
           description: "Reports on different vertex/index formats used by static models",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'reportMeshMemory_v''
// EA  : 0x83344CC0
// RVA : 0x01344CC0
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportMeshMemory_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportMeshMemory_v,
           cmdName: "reportMeshMemory",
           function: reportMeshMemory_f,
           description: "Reports on different vertex/index formats used by md6 meshes",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ReloadModel_v''
// EA  : 0x83344CE8
// RVA : 0x01344CE8
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ReloadModel_v__()
{
  return idCommandLink::idCommandLink(
           this: &ReloadModel_v,
           cmdName: "ReloadModel",
           function: ReloadModel_f,
           description: "forces a reload of a single model",
           argCompletion: idCmdSystem::ArgCompletion_ModelName);
}


// ========================================================================
// `dynamic initializer for 'TestPristineModelFromOptimizedModel_v''
// EA  : 0x83344D18
// RVA : 0x01344D18
// PDB : w:\tech5\engine\models\static\staticmodel.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestPristineModelFromOptimizedModel_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestPristineModelFromOptimizedModel_v,
           cmdName: "TestPristineModelFromOptimizedModel",
           function: TestPristineModelFromOptimizedModel_f,
           description: "test model back-conversion",
           argCompletion: nullptr);
}

