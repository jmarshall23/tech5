
// ========================================================================
// ?GetJointsForAnimFrame@idMD6Model@@QBA_NPAVidJointMat@@PBVidMD6Anim@@HABVidVec3@@_N@Z
// EA  : 0x82844ED0
// RVA : 0x00844ED0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

BOOL __fastcall idMD6Model::GetJointsForAnimFrame(
        idMD6Model *this,
        idJointMat *joints,
        const idMD6Anim *anim,
        int frame,
        const idVec3 *offset,
        bool removeOriginOffset)
{
  return idMD6Skel::GetJointsForAnimFrame(this: this->skeleton, joints, anim, frame, offset, removeOriginOffset);
}


// ========================================================================
// ?GetJointsForAnimTime@idMD6Model@@QBA_NPAVidJointMat@@PBVidMD6Anim@@HABVidVec3@@_N@Z
// EA  : 0x82844ED8
// RVA : 0x00844ED8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

BOOL __fastcall idMD6Model::GetJointsForAnimTime(
        idMD6Model *this,
        idJointMat *joints,
        const idMD6Anim *anim,
        int timeMS,
        const idVec3 *offset,
        bool removeOriginOffset)
{
  return idMD6Skel::GetJointsForAnimTime(this: this->skeleton, joints, anim, timeMS, offset, removeOriginOffset);
}


// ========================================================================
// ?GetUserChannelsForAnimFrame@idMD6Model@@QBA_NPIAMIPBVidMD6Anim@@M@Z
// EA  : 0x82844EE0
// RVA : 0x00844EE0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

BOOL __fastcall idMD6Model::GetUserChannelsForAnimFrame(
        idMD6Model *this,
        float *userChannels,
        unsigned int userChannelsSize,
        const idMD6Anim *anim,
        double frame)
{
  return idMD6Skel::GetUserChannelsForAnimFrame(this: this->skeleton, userChannels, userChannelsSize, anim, frame);
}


// ========================================================================
// ?Print@idMD6Model@@UBAXXZ
// EA  : 0x82845058
// RVA : 0x00845058
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __fastcall idMD6Model::Print(idMD6Model *this)
{
  int v2; // r26
  int v3; // r25
  int v4; // r30
  int v5; // r29
  idMD6Mesh *v6; // r10
  idDecl *v7; // r3
  int numVerts; // r28
  int numTris; // r27
  const char *str; // r23
  const char *FileName; // r3
  int v12; // r29
  int v13; // r30
  char *v14; // r9
  int *p_lastVertex; // r10
  int i; // ctr
  const char *v17; // r27
  const char *v18; // r3
  char v19; // [sp+4Ch] [-74h] BYREF
  idDecl *v20; // [sp+50h] [-70h]
  int v21; // [sp+58h] [-68h]
  int v22; // [sp+5Ch] [-64h]
  int v23; // [sp+60h] [-60h]

  idLib::Printf(fmt: "%s\n", this->name.str);
  idLib::Printf(fmt: "Dynamic model.\n");
  idLib::Printf(fmt: "    verts tris  material\n");
  v2 = 0;
  v3 = 0;
  v4 = 0;
  if ( this->meshes.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this->meshes.list[v5];
      v7 = &v6->material->idDecl;
      numVerts = v6->numVerts;
      numTris = v6->numTris;
      v2 += numVerts;
      v3 += numTris;
      str = v7->name.str;
      FileName = idDecl::GetFileName(this: v7);
      idLib::Printf(fmt: "%2i: %5i %5i %s (%s)\n", v4++, numVerts, numTris, str, FileName);
      ++v5;
    }
    while ( v4 < this->meshes.num );
  }
  idLib::Printf(fmt: "-----\n");
  idLib::Printf(fmt: "%4i verts.\n", v2);
  idLib::Printf(fmt: "%4i tris.\n", v3);
  idLib::Printf(fmt: "%4i joints.\n", this->skeleton->data->numJoints);
  idLib::Printf(fmt: "%4i meshes before splitting.\n", this->numMeshesBeforeSplitting);
  v12 = 0;
  if ( this->sourceSurfaces.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = &v19;
      p_lastVertex = &this->sourceSurfaces.list[v13 - 1].lastVertex;
      for ( i = 5; i != 0; --i )
      {
        ++p_lastVertex;
        v14 += 4;
        *(_DWORD *)v14 = *p_lastVertex;
      }
      v17 = v20->name.str;
      v18 = idDecl::GetFileName(this: v20);
      idLib::Printf(fmt: "sourceSurface %2i: %2i %5i %5i %s (%s)\n", v12++, v21, v22, v23, v17, v18);
      ++v13;
    }
    while ( v12 < this->sourceSurfaces.num );
  }
}


// ========================================================================
// ?GetUserChannelName@idMD6Model@@QBAPBDV?$idIndex@FW4invalidUserChannelIndex_t@@@@@Z
// EA  : 0x828451E8
// RVA : 0x008451E8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

const char *__fastcall idMD6Model::GetUserChannelName(
        idMD6Model *this,
        const idIndex<short,enum invalidUserChannelIndex_t> *index)
{
  _BYTE v3[8]; // [sp+50h] [-10h] BYREF

  idMD6Skel::GetUserChannelHandle(
    this: (idMD6Skel *)v3,
    result: (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)this->skeleton,
    userChannelIdx: (__int16)index);
  return animation->GetUserChannelName(
           this: animation,
           a2: (const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)v3);
}


// ========================================================================
// ?RemapSourceSurfaces@idMD6Model@@IAAXXZ
// EA  : 0x82845298
// RVA : 0x00845298
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __fastcall idMD6Model::RemapSourceSurfaces(idMD6Model *this)
{
  idCollisionModelLocal *v2; // r27
  idDeclSkins *v3; // r3
  int v4; // r28
  int v5; // r29
  idStr v6[2]; // [sp+50h] [-50h] BYREF

  idStr::idStr(this: v6, text: this->name.str);
  idStr::StripFileExtension(this: v6);
  if ( v6[0].data != nullptr )
  {
    v3 = (idDeclSkins *)idDeclInfo::FindWithInheritance(
                          this: &idDeclSkins::resourceList,
                          name: v6[0].data,
                          makeDefault: false);
    v2 = (idCollisionModelLocal *)v3;
    if ( v3 != nullptr )
    {
      this->morphSkin = idDeclSkins::IndexForSkin(this: v3, name: this->morphSkinName.data);
      this->skinChecksum = idLexer::GetScriptP(this: v2);
    }
  }
  else
  {
    v2 = nullptr;
  }
  if ( r_skipMergeMeshes.valueInteger == 0 )
  {
    v4 = 0;
    if ( this->meshes.num > 0 )
    {
      v5 = 0;
      do
      {
        if ( !idMaterial::MaterialIsUniqueMap(this: this->meshes.list[v5]->material) )
          idTriangles::VmtrMapTexCoordsWithSkins(
            this: this->meshes.list[v5]->tris,
            sourceSurfaces: &this->sourceSurfaces,
            renderSurface: v4,
            originalMaterial: this->meshes.list[v5]->material,
            skins: !this->meshes.list[v5]->allowSkinRemapping ? nullptr : (const idDeclSkins *)v2,
            skinRemaps: &this->meshes.list[v5]->skinRemaps,
            usedMaterials: &this->materials);
        ++v4;
        ++v5;
      }
      while ( v4 < this->meshes.num );
    }
  }
  idStr::FreeData(this: v6);
}


// ========================================================================
// __unwind$227842
// EA  : 0x828453A8
// RVA : 0x008453A8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_227842()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?WriteBinary@idMD6Model@@QAA_NPBD@Z
// EA  : 0x828453D8
// RVA : 0x008453D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

int __fastcall idMD6Model::WriteBinary(idMD6Model *this, const char *filename)
{
  int v5; // r29
  int v6; // r28
  int v7; // r28
  int v8; // r29
  _DWORD *v9; // r9
  int *p_lastVertex; // r10
  int i; // ctr
  idFileLocal v12; // [sp+50h] [-60h] BYREF
  int num; // [sp+54h] [-5Ch] BYREF
  int v14; // [sp+58h] [-58h] BYREF
  _DWORD v15[2]; // [sp+5Ch] [-54h] BYREF
  int v16; // [sp+64h] [-4Ch] BYREF
  int v17; // [sp+68h] [-48h] BYREF
  int v18; // [sp+6Ch] [-44h] BYREF
  int v19; // [sp+70h] [-40h] BYREF

  if ( this->jointRemap.num != ((this->skeleton->data->numJoints + 7) & 0xFFF8) )
    return 0;
  v12.file = (idFile *)((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  if ( v12.file == nullptr )
  {
    idLib::Warning(fmt: "Could not open %s", filename);
    idFileLocal::~idFileLocal(this: &v12);
    return 0;
  }
  idLib::Printf(fmt: "Writing %s\n", filename);
  v12.file->Write(this: v12.file, a2: &MD6_MESH_MAGIC, a3: 4u);
  v12.file->Write(this: v12.file, a2: &this->timestamp, a3: 4u);
  v12.file->Write(this: v12.file, a2: &this->skelTimestamp, a3: 4u);
  idFile::WriteString(this: v12.file, string: this->skeleton->name.str);
  v12.file->Write(this: v12.file, a2: &this->minBoundsExpansion, a3: 12u);
  v12.file->Write(this: v12.file, a2: &this->maxBoundsExpansion, a3: 12u);
  v12.file->Write(this: v12.file, a2: &this->remapForSkinning, a3: 1u);
  idFile::WriteString(this: v12.file, string: &this->morphSkinName);
  v12.file->Write(this: v12.file, a2: this->jointRemap.list, a3: this->jointRemap.num);
  v12.file->Write(this: v12.file, a2: &this->defaultBounds, a3: 24u);
  num = this->meshes.num;
  v12.file->Write(this: v12.file, a2: &num, a3: 4u);
  v5 = 0;
  if ( this->meshes.num > 0 )
  {
    v6 = 0;
    do
    {
      idMD6Mesh::WriteMesh_Binary(this: this->meshes.list[v6], file: v12.file);
      ++v5;
      ++v6;
    }
    while ( v5 < this->meshes.num );
  }
  v14 = this->sourceSurfaces.num;
  v12.file->Write(this: v12.file, a2: &v14, a3: 4u);
  v7 = 0;
  if ( this->sourceSurfaces.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = v15;
      p_lastVertex = &this->sourceSurfaces.list[v8 - 1].lastVertex;
      for ( i = 5; i != 0; --i )
        *++v9 = *++p_lastVertex;
      idFile::WriteString(this: v12.file, string: *(const char **)(v15[1] + 8));
      v12.file->Write(this: v12.file, a2: &v16, a3: 4u);
      v12.file->Write(this: v12.file, a2: &v17, a3: 4u);
      v12.file->Write(this: v12.file, a2: &v18, a3: 4u);
      v12.file->Write(this: v12.file, a2: &v19, a3: 4u);
      ++v7;
      ++v8;
    }
    while ( v7 < this->sourceSurfaces.num );
  }
  v12.file->Write(this: v12.file, a2: &MD6_MESH_MAGIC, a3: 4u);
  idFileLocal::~idFileLocal(this: &v12);
  return 1;
}


// ========================================================================
// __unwind$227948_0
// EA  : 0x828456E4
// RVA : 0x008456E4
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_227948_0()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 176 + 80));
}


// ========================================================================
// ?Memory@idMD6Model@@QBAIXZ
// EA  : 0x82845710
// RVA : 0x00845710
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

int __fastcall idMD6Model::Memory(idMD6Model *this)
{
  int v2; // r30
  int v3; // r28
  int v4; // r29

  v2 = 0;
  v3 = this->skeleton->data->size + 20 * (this->sourceSurfaces.size + 12) + this->jointRemap.size;
  if ( this->meshes.num > 0 )
  {
    v4 = 0;
    do
    {
      ++v2;
      v3 += idMD6Mesh::Memory(this: this->meshes.list[v4++]);
    }
    while ( v2 < this->meshes.num );
  }
  return v3;
}


// ========================================================================
// ?TrianglesAreEqual@@YA_NABVidTriangles@@0@Z
// EA  : 0x82845798
// RVA : 0x00845798
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

int __fastcall TrianglesAreEqual(idTriangles *a, idTriangles *b)
{
  idTriangles *standardTris; // r28
  idTriangles *v5; // r27
  int v6; // r10
  int numIndexes; // r9
  int v8; // r11
  int numVerts; // r3
  int v10; // r4
  int v11; // r9
  idDrawVert *verts; // r5
  idDrawVert *v13; // r11
  idDrawVert *v14; // r10
  int x_high; // r30
  int v16; // r8
  idAutoStandardTriangles v18; // [sp+50h] [-40h] BYREF
  idAutoStandardTriangles v19[7]; // [sp+58h] [-38h] BYREF

  if ( a->numIndexes != b->numIndexes
    || a->numVerts != b->numVerts
    || (unsigned __int8)idBounds::Compare(this: &a->bounds, a: &b->bounds) == 0 )
  {
    return 0;
  }
  idAutoStandardTriangles::idAutoStandardTriangles(this: v19, tri: a);
  idAutoStandardTriangles::idAutoStandardTriangles(this: &v18, tri: b);
  standardTris = (idTriangles *)v19[0].standardTris;
  v5 = (idTriangles *)v18.standardTris;
  v6 = 0;
  numIndexes = v19[0].standardTris->numIndexes;
  if ( numIndexes > 0 )
  {
    v8 = 0;
    while ( v19[0].standardTris->indexes[v8] == v18.standardTris->indexes[v8] )
    {
      ++v6;
      ++v8;
      if ( v6 >= numIndexes )
        goto LABEL_8;
    }
    idAutoStandardTriangles::~idAutoStandardTriangles(this: &v18);
    idAutoStandardTriangles::~idAutoStandardTriangles(this: v19);
    return 0;
  }
LABEL_8:
  numVerts = a->numVerts;
  v10 = 0;
  if ( numVerts <= 0 )
  {
LABEL_15:
    if ( v18.freeOnDelete && v18.standardTris != nullptr )
    {
      idTriangles::~idTriangles(this: (idTriangles *)v18.standardTris);
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    }
    if ( v19[0].freeOnDelete )
    {
      idTriangles::~idTriangles(this: standardTris);
      idMem::Free(this: &mem, ptr: standardTris, align: ALIGN_16);
    }
    return 1;
  }
  else
  {
    v11 = 0;
    verts = v19[0].standardTris->verts;
    while ( 1 )
    {
      v13 = &verts[v11];
      v14 = &v18.standardTris->verts[v11];
      do
      {
        x_high = HIBYTE(v14->xyz.x);
        v16 = HIBYTE(v13->xyz.x) - x_high;
        if ( HIBYTE(v13->xyz.x) != x_high )
          break;
        v13 = (idDrawVert *)((char *)v13 + 1);
        v14 = (idDrawVert *)((char *)v14 + 1);
      }
      while ( v13 != &verts[v11 + 1] );
      if ( v16 != 0 )
        break;
      ++v10;
      ++v11;
      if ( v10 >= numVerts )
        goto LABEL_15;
    }
    if ( v18.freeOnDelete )
    {
      idTriangles::~idTriangles(this: (idTriangles *)v18.standardTris);
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    }
    if ( v19[0].freeOnDelete )
    {
      idTriangles::~idTriangles(this: standardTris);
      idMem::Free(this: &mem, ptr: standardTris, align: ALIGN_16);
    }
    return 0;
  }
}


// ========================================================================
// __unwind$228212
// EA  : 0x82845970
// RVA : 0x00845970
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_228212()
{
  int v0; // r12

  idAutoStandardTriangles::~idAutoStandardTriangles(this: (idAutoStandardTriangles *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$228213
// EA  : 0x82845998
// RVA : 0x00845998
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_228213()
{
  int v0; // r12

  idAutoStandardTriangles::~idAutoStandardTriangles(this: (idAutoStandardTriangles *)(v0 - 144 + 80));
}


// ========================================================================
// ?Equals@idMD6Model@@QBA_NABV1@@Z
// EA  : 0x828459C0
// RVA : 0x008459C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

int __fastcall idMD6Model::Equals(idMD6Model *this, const idMD6Model *other)
{
  idBounds *p_defaultBounds; // r31
  idBounds *v3; // r30
  char v7; // r11
  char v8; // r11
  int num; // r5
  int v10; // r6
  sourceSurface_t *list; // r8
  int v12; // r9
  sourceSurface_t *v13; // r7
  sourceSurface_t *v14; // r11
  sourceSurface_t *v15; // r10
  int v16; // r11
  int v17; // r28
  int i; // r29
  idMD6Mesh *v19; // r31
  idMD6Mesh *v20; // r30

  p_defaultBounds = &this->defaultBounds;
  v3 = &other->defaultBounds;
  if ( (unsigned __int8)idBounds::Compare(this: &other->defaultBounds, a: &this->defaultBounds) == 0
    || other->remapForSkinning != this->remapForSkinning
    || (unsigned __int8)idBounds::Compare(this: v3, a: p_defaultBounds) == 0 )
  {
    return 0;
  }
  if ( other->minBoundsExpansion.x != this->minBoundsExpansion.x
    || other->minBoundsExpansion.y != this->minBoundsExpansion.y
    || (v7 = 1, other->minBoundsExpansion.z != this->minBoundsExpansion.z) )
  {
    v7 = 0;
  }
  if ( v7 == 0 )
    return 0;
  if ( other->maxBoundsExpansion.x != this->maxBoundsExpansion.x
    || other->maxBoundsExpansion.y != this->maxBoundsExpansion.y
    || (v8 = 1, other->maxBoundsExpansion.z != this->maxBoundsExpansion.z) )
  {
    v8 = 0;
  }
  if ( v8 == 0 )
    return 0;
  num = this->sourceSurfaces.num;
  if ( other->sourceSurfaces.num != num )
    return 0;
  v10 = 0;
  if ( num > 0 )
  {
    list = this->sourceSurfaces.list;
    v12 = 0;
    v13 = other->sourceSurfaces.list;
    do
    {
      v14 = &list[v12];
      v15 = &v13[v12];
      if ( list[v12].firstVertex != v13[v12].firstVertex
        || v14->lastVertex != v15->lastVertex
        || v14->renderSurface != v15->renderSurface
        || v14->mtr != v15->mtr )
      {
        return 0;
      }
      ++v10;
      ++v12;
    }
    while ( v10 < num );
  }
  v16 = this->meshes.num;
  if ( other->meshes.num != v16 )
    return 0;
  v17 = 0;
  if ( v16 > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v19 = this->meshes.list[i];
      v20 = other->meshes.list[i];
      if ( idStr::Cmp(s1: v19->name.data, s2: v20->name.data) != 0
        || v19->material != v20->material
        || v19->allowSkinRemapping != v20->allowSkinRemapping
        || (unsigned __int8)idBounds::Compare(this: &v19->bounds, a: &v20->bounds) == 0
        || (unsigned __int8)TrianglesAreEqual(a: v19->tris, b: v20->tris) == 0 )
      {
        break;
      }
      if ( ++v17 >= this->meshes.num )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ??0idMD6Model@@QAA@XZ
// EA  : 0x82845DD8
// RVA : 0x00845DD8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

idMD6Model *__fastcall idMD6Model::idMD6Model(idMD6Model *this)
{
  idResource::idResource(this: &this->idResource);
  this->__vftable = (idMD6Model_vtbl *)&idMD6Model::`vftable';
  this->filename.len = 0;
  this->filename.allocedAndFlag = 20;
  this->filename.data = this->filename.baseBuffer;
  this->filename.baseBuffer[0] = 0;
  this->skinChecksum = 0;
  this->timestamp = -1;
  this->skelTimestamp = -1;
  this->remapForSkinning = true;
  this->morphSkinName.allocedAndFlag = 20;
  this->morphSkinName.data = this->morphSkinName.baseBuffer;
  this->morphSkinName.len = 0;
  this->morphSkinName.baseBuffer[0] = 0;
  this->numMeshesBeforeSplitting = 0;
  this->morphSkin = -1;
  this->meshes.list = nullptr;
  this->meshes.granularity = 0;
  this->meshes.memTag = 19;
  this->meshes.listStatic = 0;
  this->meshes.size = 0;
  this->meshes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->meshes);
  this->jointRemap.list = nullptr;
  this->jointRemap.granularity = 0;
  this->jointRemap.memTag = 19;
  this->jointRemap.listStatic = 0;
  this->jointRemap.size = 0;
  this->jointRemap.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointRemap);
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
  this->skeleton = nullptr;
  this->minBoundsExpansion = vec3_origin;
  this->maxBoundsExpansion = vec3_origin;
  this->defaultBounds.b[0].z = 1.0e30;
  this->defaultBounds.b[0].y = 1.0e30;
  this->defaultBounds.b[0].x = 1.0e30;
  this->defaultBounds.b[1].z = -1.0e30;
  this->defaultBounds.b[1].y = -1.0e30;
  this->defaultBounds.b[1].x = -1.0e30;
  return this;
}


// ========================================================================
// __unwind$228837
// EA  : 0x82845F68
// RVA : 0x00845F68
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_228837()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$228838
// EA  : 0x82845F90
// RVA : 0x00845F90
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_228838()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// __unwind$228839
// EA  : 0x82845FBC
// RVA : 0x00845FBC
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_228839()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$228840
// EA  : 0x82845FE8
// RVA : 0x00845FE8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_228840()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 148));
}


// ========================================================================
// __unwind$228841
// EA  : 0x82846014
// RVA : 0x00846014
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_228841()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$228842
// EA  : 0x82846040
// RVA : 0x00846040
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_228842()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 180));
}


// ========================================================================
// ?List@idMD6Model@@UBAXXZ
// EA  : 0x82846080
// RVA : 0x00846080
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __fastcall idMD6Model::List(idMD6Model *this)
{
  int num; // r27
  int v2; // r30
  int v3; // r28
  int v4; // r31
  int v5; // r29
  int numTris; // r26
  int numVerts; // r25
  int v8; // r10
  idMD6Mesh **list; // r9
  int v10; // r11
  idMD6Mesh *v11; // r7
  idMD6Mesh *v12; // r5
  idMD6Mesh *v13; // r9
  const char *str; // r24
  int numMeshesBeforeSplitting; // r23
  unsigned int v16; // r3

  num = this->meshes.num;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  numTris = 0;
  numVerts = 0;
  v8 = 0;
  if ( num >= 2 )
  {
    list = this->meshes.list;
    v10 = 0;
    do
    {
      v11 = list[v10];
      v8 += 2;
      v12 = list[v10 + 1];
      v10 += 2;
      v4 += v11->numTris;
      v2 += v11->numVerts;
      v5 += v12->numTris;
      v3 += v12->numVerts;
    }
    while ( v8 < num - 1 );
  }
  if ( v8 < num )
  {
    v13 = this->meshes.list[v8];
    numTris = v13->numTris;
    numVerts = v13->numVerts;
  }
  str = this->name.str;
  numMeshesBeforeSplitting = this->numMeshesBeforeSplitting;
  v16 = idMD6Model::Memory(this);
  idLib::Printf(
    fmt: " %4ik %3i(%3i) %5i %5i %s",
    v16 >> 10,
    num,
    numMeshesBeforeSplitting,
    v3 + v2 + numVerts,
    v5 + v4 + numTris,
    str);
  idLib::Printf(fmt: "\n");
}


// ========================================================================
// ?mergeSkeletons_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828462E0
// RVA : 0x008462E0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __fastcall mergeSkeletons_f(const idCmdArgs *args)
{
  int argc; // r11
  idFileList *v2; // r30
  int v3; // r28
  int v4; // r29
  idFileList *v5; // r30
  int v6; // r28
  int v7; // r29
  int num; // r16
  int v9; // r24
  idMD6Node **list; // r15
  int v11; // r26
  int v12; // r18
  int *v13; // r17
  int v14; // r28
  const idMD6Skel *v15; // r27
  idMD6Model **v16; // r23
  idMD6Model *v17; // r30
  const idMD6Skel *skeleton; // r29
  idMD6Model **v19; // r11
  int v20; // ctr
  idMD6Model **v21; // r11
  int v22; // ctr
  int v23[4]; // [sp+50h] [-270h] BYREF
  idList<idMD6Node *,5> v24; // [sp+60h] [-260h] BYREF
  idList<int,5> v25; // [sp+70h] [-250h] BYREF
  idStr v26; // [sp+80h] [-240h] BYREF
  idList<int,5> v27; // [sp+A0h] [-220h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v28; // [sp+B0h] [-210h] BYREF
  idStr v29; // [sp+C0h] [-200h] BYREF
  idStr v30; // [sp+E0h] [-1E0h] BYREF
  idStr v31; // [sp+100h] [-1C0h] BYREF
  char v32[416]; // [sp+120h] [-1A0h] BYREF

  argc = args->argc;
  if ( args->argc == 1 || (v23[0] = args->argc, argc > 2) )
  {
    idLib::Printf(fmt: "USAGE: mergeSkeletons <path>\n");
  }
  else
  {
    v26.len = 0;
    v26.allocedAndFlag = 20;
    v26.data = v26.baseBuffer;
    v26.baseBuffer[0] = 0;
    v23[0] = argc;
    if ( argc == 2 )
      idStr::operator=(this: &v26, text: args->argv[1]);
    common->SetRefreshOnPrint(this: common, a2: true);
    if ( fileSystem->IsFolder(this: fileSystem, a2: v26.data, a3: FSPATH_BASE) == FOLDER_YES )
    {
      v2 = fileSystem->ListFilesTree(this: fileSystem, a2: v26.data, a3: MD6_MESH_EXT, a4: 0);
      if ( v2 != nullptr )
      {
        idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v25);
        v23[0] = 0;
        idList<int,5>::PreAllocate(this: &v25, newSize: v2->list.num, initValue: v23);
        v3 = 0;
        if ( v2->list.num > 0 )
        {
          v4 = 0;
          do
          {
            idStr::idStr(this: &v30, text: v2->list.list[v4].data);
            v23[0] = (int)idResourceList::Load(
                            this: &idMD6Model::resourceList,
                            name: v30.data,
                            makeDefault: true,
                            skipStaleCheck: false);
            if ( v23[0] != 0 )
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&v25,
                obj: (const encounterGroupRole_t *)v23);
            idStr::FreeData(this: &v30);
            ++v3;
            ++v4;
          }
          while ( v3 < v2->list.num );
        }
        idFileList::~idFileList(this: v2);
        idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
        v24.list = nullptr;
        v24.listStatic = 0;
        idList<idMaterial const *,59>::operator=(this: &v24, other: (const idList<idMD6Node *,5> *)&v25);
        v5 = fileSystem->ListFilesTree(this: fileSystem, a2: v26.data, a3: MD6_SKEL_EXT, a4: 0);
        if ( v5 != nullptr )
        {
          idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v28);
          idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v27);
          v23[0] = 0;
          idList<int,5>::PreAllocate(this: &v27, newSize: v5->list.num, initValue: v23);
          v6 = 0;
          if ( v5->list.num > 0 )
          {
            v7 = 0;
            do
            {
              idStr::idStr(this: &v31, text: v5->list.list[v7].data);
              v23[0] = (int)idResourceList::Load(
                              this: &idMD6Skel::resourceList,
                              name: v31.data,
                              makeDefault: true,
                              skipStaleCheck: false);
              if ( v23[0] != 0 )
                idList<idAnimWebBlendTree *,5>::Append(
                  this: (idList<enum encounterGroupRole_t,5> *)&v27,
                  obj: (const encounterGroupRole_t *)v23);
              idStr::FreeData(this: &v31);
              ++v6;
              ++v7;
            }
            while ( v6 < v5->list.num );
          }
          idFileList::~idFileList(this: v5);
          idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
          num = v25.num;
          v9 = 0;
          list = v24.list;
          v11 = v24.num;
          v12 = v25.num - 1;
          if ( v25.num - 1 >= 0 )
          {
            v13 = &v25.list[v12];
            do
            {
              v14 = v11 - 1;
              v15 = *(const idMD6Skel **)(*v13 + 212);
              if ( v11 - 1 >= 0 )
              {
                v16 = (idMD6Model **)&list[v14];
                do
                {
                  v17 = *v16;
                  skeleton = (*v16)->skeleton;
                  if ( skeleton == v15 )
                  {
                    if ( v14 >= 0 && v14 < v11 )
                    {
                      v24.num = --v11;
                      if ( v14 < v11 )
                      {
                        v19 = v16;
                        v20 = v11 - v14;
                        do
                        {
                          *v19 = v19[1];
                          ++v19;
                          --v20;
                        }
                        while ( v20 != 0 );
                      }
                    }
                  }
                  else if ( v15->data->parentTblCrc.value == skeleton->data->parentTblCrc.value )
                  {
                    v17->skeleton = v15;
                    fileSystem->FixLongFilename(
                      this: fileSystem,
                      a2: "generated",
                      a3: "bmd6model",
                      a4: v17->name.str,
                      a5: v32,
                      a6: 256);
                    idMD6Model::WriteBinary(this: v17, filename: v32);
                    idStr::idStr(this: &v29, text: skeleton->name.str);
                    idStr::SetFileExtension(this: &v29, extension: "md6skl_merged");
                    fileSystem->RemoveFile(this: fileSystem, a2: v29.data, a3: FSPATH_BASE);
                    fileSystem->RenameFile(this: fileSystem, a2: skeleton->name.str, a3: v29.data, a4: FSPATH_BASE);
                    ++v9;
                    idLib::Printf(fmt: "Merged model '%s' to skeleton '%s'\n", v17->name.str, v15->name.str);
                    if ( v14 >= 0 && v14 < v11 )
                    {
                      v24.num = --v11;
                      if ( v14 < v11 )
                      {
                        v21 = v16;
                        v22 = v11 - v14;
                        do
                        {
                          *v21 = v21[1];
                          ++v21;
                          --v22;
                        }
                        while ( v22 != 0 );
                      }
                    }
                    idStr::FreeData(this: &v29);
                  }
                  --v14;
                  --v16;
                }
                while ( v14 >= 0 );
              }
              --v12;
              --v13;
            }
            while ( v12 >= 0 );
          }
          idLib::Printf(fmt: "Total skeletons: %d\n", v27.num);
          idLib::Printf(fmt: "Total models: %d\n", num);
          idLib::Printf(fmt: "Merged skeletons: %d\n", v9);
          idLib::Printf(fmt: "Unique skeletons: %d\n", v11);
          common->SetRefreshOnPrint(this: common, a2: false);
          if ( (v27.listStatic == 0 || v27.listStatic == 2) && v27.list != nullptr )
            idMem::Free(this: &mem, ptr: v27.list, align: ALIGN_16);
          if ( (v28.listStatic == 0 || v28.listStatic == 2) && v28.list != nullptr )
            idMem::Free(this: &mem, ptr: v28.list, align: ALIGN_16);
          if ( (v24.listStatic == 0 || v24.listStatic == 2) && list != nullptr )
            idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
          if ( (v25.listStatic == 0 || v25.listStatic == 2) && v25.list != nullptr )
            idMem::Free(this: &mem, ptr: v25.list, align: ALIGN_16);
          idStr::FreeData(this: &v26);
        }
        else
        {
          idLib::Warning(fmt: "No %s files were found.", MD6_SKEL_EXT);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v24);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v25);
          idStr::FreeData(this: &v26);
        }
      }
      else
      {
        idLib::Warning(fmt: "No %s files were found.", MD6_MESH_EXT);
        idStr::FreeData(this: &v26);
      }
    }
    else
    {
      idLib::Warning(fmt: "<path> parameter must specify a folder and not a file");
      idStr::FreeData(this: &v26);
    }
  }
}


// ========================================================================
// __unwind$229550
// EA  : 0x828468C0
// RVA : 0x008468C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_229550()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 128));
}


// ========================================================================
// __unwind$229551
// EA  : 0x828468E8
// RVA : 0x008468E8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_229551()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 112));
}


// ========================================================================
// __unwind$229552
// EA  : 0x82846910
// RVA : 0x00846910
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_229552()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 224));
}


// ========================================================================
// __unwind$229553
// EA  : 0x82846938
// RVA : 0x00846938
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_229553()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 96));
}


// ========================================================================
// __unwind$229554_0
// EA  : 0x82846960
// RVA : 0x00846960
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_229554_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 176));
}


// ========================================================================
// __unwind$229555
// EA  : 0x82846988
// RVA : 0x00846988
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_229555()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 160));
}


// ========================================================================
// __unwind$229556
// EA  : 0x828469B0
// RVA : 0x008469B0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_229556()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 256));
}


// ========================================================================
// __unwind$229557
// EA  : 0x828469D8
// RVA : 0x008469D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_229557()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 192));
}


// ========================================================================
// ?convertMeshes_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82846A08
// RVA : 0x00846A08
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __fastcall convertMeshes_f(const idCmdArgs *args)
{
  int argc; // r11
  int v2; // r29
  idFileList *v3; // r3
  idFileList *v4; // r30
  int v5; // r28
  idStr v6; // [sp+60h] [-70h] BYREF
  idStr v7[2]; // [sp+80h] [-50h] BYREF

  argc = args->argc;
  if ( args->argc == 1 || argc > 2 )
  {
    idLib::Printf(fmt: "USAGE: convertMeshes <path>\n");
  }
  else
  {
    v2 = 0;
    v6.len = 0;
    v6.allocedAndFlag = 20;
    v6.data = v6.baseBuffer;
    v6.baseBuffer[0] = 0;
    if ( argc == 2 )
      idStr::operator=(this: &v6, text: args->argv[1]);
    common->SetRefreshOnPrint(this: common, a2: true);
    if ( fileSystem->IsFolder(this: fileSystem, a2: v6.data, a3: FSPATH_BASE) == FOLDER_YES )
    {
      v3 = fileSystem->ListFilesTree(this: fileSystem, a2: v6.data, a3: MD6_MESH_EXT, a4: 0);
      v4 = v3;
      if ( v3 != nullptr )
      {
        v5 = 0;
        if ( v3->list.num > 0 )
        {
          do
          {
            idStr::idStr(this: v7, text: v4->list.list[v2].data);
            idResourceList::Load(
              this: &idMD6Model::resourceList,
              name: v7[0].data,
              makeDefault: true,
              skipStaleCheck: false);
            idStr::FreeData(this: v7);
            ++v5;
            ++v2;
          }
          while ( v5 < v4->list.num );
        }
        idFileList::~idFileList(this: v4);
        idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
        idStr::FreeData(this: &v6);
      }
      else
      {
        idLib::Warning(fmt: "No %s files were found.", MD6_MESH_EXT);
        idStr::FreeData(this: &v6);
      }
    }
    else
    {
      idLib::Warning(fmt: "<path> parameter must specify a folder and not a file");
      idStr::FreeData(this: &v6);
    }
  }
}


// ========================================================================
// __unwind$230333
// EA  : 0x82846BBC
// RVA : 0x00846BBC
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_230333()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$230334
// EA  : 0x82846BE4
// RVA : 0x00846BE4
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_230334()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ??1idMD6Model@@UAA@XZ
// EA  : 0x82847188
// RVA : 0x00847188
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __fastcall idMD6Model::~idMD6Model(idMD6Model *this)
{
  idList<idMD6Mesh *,19> *p_meshes; // r29

  this->__vftable = (idMD6Model_vtbl *)&idMD6Model::`vftable';
  p_meshes = &this->meshes;
  this->skeleton = nullptr;
  idList<idMD6Mesh *,19>::DeleteContents(this: &this->meshes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->materials);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointRemap);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_meshes);
  idStr::FreeData(this: &this->morphSkinName);
  idStr::FreeData(this: &this->filename);
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$231074_0
// EA  : 0x82847200
// RVA : 0x00847200
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231074_0()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$231075_0
// EA  : 0x82847228
// RVA : 0x00847228
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231075_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$231076_0
// EA  : 0x82847254
// RVA : 0x00847254
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231076_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$231077_0
// EA  : 0x82847280
// RVA : 0x00847280
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231077_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 148));
}


// ========================================================================
// __unwind$231078_0
// EA  : 0x828472AC
// RVA : 0x008472AC
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231078_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$231079_0
// EA  : 0x828472D8
// RVA : 0x008472D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231079_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 180));
}


// ========================================================================
// __unwind$231080_0
// EA  : 0x82847304
// RVA : 0x00847304
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231080_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 196));
}


// ========================================================================
// ?LoadBinary@idMD6Model@@IAA_NPBD_N@Z
// EA  : 0x82847338
// RVA : 0x00847338
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

BOOL __fastcall idMD6Model::LoadBinary(idMD6Model *this, const char *filename, const bool explicitFile)
{
  idFile *v6; // r3
  const idMD6Skel *v8; // r3
  idList<idMD6Mesh *,19> *p_meshes; // r25
  int v10; // r28
  int v11; // r29
  idMD6Mesh *v12; // r3
  idMD6Mesh *v13; // r3
  idList<sourceSurface_t,5> *p_sourceSurfaces; // r29
  int v15; // r28
  int v16; // r30
  const idDecl *v17; // r3
  _DWORD *v18; // r10
  int v19; // ctr
  int *p_lastVertex; // r11
  idFileLocal v21; // [sp+50h] [-E0h] BYREF
  unsigned int v22; // [sp+54h] [-DCh] BYREF
  int v23; // [sp+58h] [-D8h] BYREF
  int v24[4]; // [sp+5Ch] [-D4h] BYREF
  _DWORD v25[2]; // [sp+6Ch] [-C4h] BYREF
  int v26; // [sp+74h] [-BCh] BYREF
  int v27; // [sp+78h] [-B8h] BYREF
  int v28; // [sp+7Ch] [-B4h] BYREF
  int v29; // [sp+80h] [-B0h] BYREF
  idStr v30; // [sp+90h] [-A0h] BYREF
  idStr v31[4]; // [sp+B0h] [-80h] BYREF

  v6 = fileSystem->OpenFileRead(this: fileSystem, a2: filename, a3: 1, a4: 0);
  v21.file = v6;
  if ( v6 == nullptr )
    goto LABEL_3;
  v6->Read(this: v6, a2: &v22, a3: 4u);
  if ( v22 != 557206861 )
    goto LABEL_3;
  v21.file->Read(this: v21.file, a2: &this->timestamp, a3: 4u);
  if ( !explicitFile
    && idLib::production != PROD_PRODUCTION
    && fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false) != this->timestamp )
  {
    goto LABEL_3;
  }
  v21.file->Read(this: v21.file, a2: &this->skelTimestamp, a3: 4u);
  v30.len = 0;
  v30.allocedAndFlag = 20;
  v30.data = v30.baseBuffer;
  v30.baseBuffer[0] = 0;
  idFile::ReadString(this: v21.file, string: &v30);
  if ( !explicitFile
    && idLib::production != PROD_PRODUCTION
    && fileSystem->GetTimestamp(this: fileSystem, a2: v30.data, a3: false) != this->skelTimestamp
    || (v21.file->Read(this: v21.file, a2: &this->minBoundsExpansion, a3: 12u),
        v21.file->Read(this: v21.file, a2: &this->maxBoundsExpansion, a3: 12u),
        v21.file->Read(this: v21.file, a2: &this->remapForSkinning, a3: 1u),
        idFile::ReadString(this: v21.file, string: &this->morphSkinName),
        v8 = (const idMD6Skel *)idResourceList::Load(
                                  this: &idMD6Skel::resourceList,
                                  name: v30.data,
                                  makeDefault: true,
                                  skipStaleCheck: false),
        this->skeleton = v8,
        v8 == nullptr) )
  {
    idStr::FreeData(this: &v30);
LABEL_3:
    idFileLocal::~idFileLocal(this: &v21);
    return false;
  }
  idList<unsigned char,19>::SetNum(
    this: (idList<unsigned char,37> *)&this->jointRemap,
    newNum: (v8->data->numJoints + 7) & 0xFFF8);
  v21.file->Read(this: v21.file, a2: this->jointRemap.list, a3: this->jointRemap.num);
  v21.file->Read(this: v21.file, a2: &this->defaultBounds, a3: 24u);
  v21.file->Read(this: v21.file, a2: &v23, a3: 4u);
  p_meshes = &this->meshes;
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->meshes, newNum: v23);
  v10 = 0;
  if ( v23 > 0 )
  {
    v11 = 0;
    do
    {
      v12 = (idMD6Mesh *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xACu,
                           tag: TAG_MD6,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
      v24[1] = (int)v12;
      if ( v12 != nullptr )
        v13 = idMD6Mesh::idMD6Mesh(this: v12);
      else
        v13 = nullptr;
      p_meshes->list[v11] = v13;
      idMD6Mesh::LoadMesh_Binary(this: p_meshes->list[v11], file: v21.file, magic: v22);
      ++v10;
      ++v11;
    }
    while ( v10 < v23 );
  }
  p_sourceSurfaces = &this->sourceSurfaces;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  v21.file->Read(this: v21.file, a2: v24, a3: 4u);
  idList<sourceSurface_t,5>::SetNum(this: &this->sourceSurfaces, newNum: v24[0]);
  v15 = 0;
  if ( v24[0] > 0 )
  {
    v16 = 0;
    do
    {
      v31[0].allocedAndFlag = 20;
      v31[0].len = 0;
      v31[0].data = v31[0].baseBuffer;
      v31[0].baseBuffer[0] = 0;
      idFile::ReadString(this: v21.file, string: v31);
      if ( v31[0].data != nullptr )
        v17 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v31[0].data, makeDefault: true);
      else
        v17 = nullptr;
      v25[1] = v17;
      v21.file->Read(this: v21.file, a2: &v26, a3: 4u);
      v21.file->Read(this: v21.file, a2: &v27, a3: 4u);
      v21.file->Read(this: v21.file, a2: &v28, a3: 4u);
      v21.file->Read(this: v21.file, a2: &v29, a3: 4u);
      v18 = v25;
      v19 = 5;
      p_lastVertex = &p_sourceSurfaces->list[v16 - 1].lastVertex;
      do
      {
        *++p_lastVertex = *++v18;
        --v19;
      }
      while ( v19 != 0 );
      idStr::FreeData(this: v31);
      ++v15;
      ++v16;
    }
    while ( v15 < v24[0] );
  }
  if ( v21.file->Read(this: v21.file, a2: &v22, a3: 4u) != 0 && v22 == 557206861 )
  {
    idStr::FreeData(this: &v30);
    idFileLocal::~idFileLocal(this: &v21);
    return true;
  }
  else
  {
    idList<idMD6Mesh *,19>::DeleteContents(this: p_meshes);
    idLib::Error(fmt: "%s is corrupt! ( %d != %d )", filename, v22, 557206861);
    return _LN235();
  }
}


// ========================================================================
// $LN235
// EA  : 0x82847804
// RVA : 0x00847804
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _LN235()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 304 + 80));
}


// ========================================================================
// __unwind$231281
// EA  : 0x8284782C
// RVA : 0x0084782C
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231281()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 144));
}


// ========================================================================
// __unwind$231282
// EA  : 0x82847854
// RVA : 0x00847854
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231282()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 304 + 96), tag: TAG_MD6);
}


// ========================================================================
// __unwind$231283
// EA  : 0x82847880
// RVA : 0x00847880
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231283()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 176));
}


// ========================================================================
// ?LoadFileNoRemap@idMD6Model@@QAA_NPBD@Z
// EA  : 0x828478B0
// RVA : 0x008478B0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

int __fastcall idMD6Model::LoadFileNoRemap(idMD6Model *this, const char *filename)
{
  unsigned __int8 v3; // r29
  char v5; // r8
  BOOL v6; // r27
  __int64 v7; // r10
  __int64 v8; // r6
  __int64 v9; // r8
  int v11; // r11
  char v12; // r10
  int v13; // [sp+8h] [-258h]
  int v14; // [sp+Ch] [-254h]
  int v15; // [sp+10h] [-250h]
  int v16; // [sp+14h] [-24Ch]
  int v17; // [sp+18h] [-248h]
  int v18; // [sp+1Ch] [-244h]
  idStr v19; // [sp+50h] [-210h] BYREF
  char v20[256]; // [sp+70h] [-1F0h] BYREF
  idMD6BinaryGenerator v21; // [sp+170h] [-F0h] BYREF

  v3 = 0;
  this->skinChecksum = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointRemap);
  idList<idMD6Mesh *,19>::DeleteContents(this: &this->meshes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  this->skeleton = nullptr;
  idStr::operator=(this: &this->filename, text: filename);
  v19.len = 0;
  v19.allocedAndFlag = 20;
  v19.data = v19.baseBuffer;
  v19.baseBuffer[0] = 0;
  idStr::ExtractFileExtension(this: &this->filename, dest: &v19);
  v5 = _cntlzw(idStr::Icmp(s1: v19.data, s2: "bmd6model"));
  v6 = (v5 & 0x20) != 0;
  if ( (v5 & 0x20) != 0 )
    idStr::Copynz(dest: v20, src: filename, destsize: 256);
  else
    fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bmd6model", a4: filename, a5: v20, a6: 256);
  if ( idLib::production != PROD_DEVELOPMENT )
  {
    if ( !idMD6Model::LoadBinary(this, filename: v20, explicitFile: v6) )
    {
      idLib::Warning(fmt: "Pre-load of '%s' failed.", v20);
      LODWORD(v7) = &unk_82210000;
      HIDWORD(v8) = this->name.str;
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "bad magic on md6model '%s'",
        a3: v8,
        a4: v9,
        a5: v7,
        a6: v13,
        a7: v14,
        a8: v15,
        a9: v16,
        a10: v17,
        a11: v18);
      idStr::FreeData(this: &v19);
      return 0;
    }
  }
  else
  {
    if ( r_skipGeneratedFileCheck.valueInteger != 0 && !v6 )
      v3 = 1;
    v11 = v3;
    if ( v3 == 0 )
    {
      v12 = _cntlzw(idMD6Model::LoadBinary(this, filename: v20, explicitFile: v6));
      v11 = (v12 & 0x20) != 0;
      if ( (v12 & 0x20) != 0 && v6 )
        idLib::Error(fmt: "Couldn't load explicit bmd6model '%s'.", filename);
    }
    if ( v11 != 0 )
    {
      idMD6BinaryGenerator::idMD6BinaryGenerator(this: &v21);
      if ( !idMD6BinaryGenerator::LoadAndProcessText(this: &v21, sourceModel: filename) )
        idLib::Error(fmt: "Failed to load md6 model '%s'.", filename);
      idMD6BinaryGenerator::WriteBinaryFile(this: &v21, filename: v20);
      if ( !idMD6Model::LoadBinary(this, filename: v20, explicitFile: true) )
        idLib::Error(fmt: "Failed to load md6 binary generated for model '%s'.", filename);
      idMD6BinaryGenerator::~idMD6BinaryGenerator(this: &v21);
    }
  }
  idStr::FreeData(this: &v19);
  return 1;
}


// ========================================================================
// $LN43_2
// EA  : 0x82847AE0
// RVA : 0x00847AE0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _LN43_2()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 80));
}


// ========================================================================
// __unwind$231716
// EA  : 0x82847B08
// RVA : 0x00847B08
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231716()
{
  int v0; // r12

  idMD6BinaryGenerator::~idMD6BinaryGenerator(this: (idMD6BinaryGenerator *)(v0 - 608 + 368));
}


// ========================================================================
// ?LoadResource@idMD6Model@@UAAXXZ
// EA  : 0x82847B30
// RVA : 0x00847B30
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __fastcall idMD6Model::LoadResource(idMD6Model *this)
{
  int v2; // r29
  int v3; // r30

  if ( (unsigned __int8)idMD6Model::LoadFileNoRemap(this, filename: this->name.str) != 0 )
  {
    idMD6Model::RemapSourceSurfaces(this);
    v2 = 0;
    if ( this->meshes.num > 0 )
    {
      v3 = 0;
      do
      {
        idMD6Mesh::FreeLoadData(this: this->meshes.list[v3]);
        ++v2;
        ++v3;
      }
      while ( v2 < this->meshes.num );
    }
  }
  else
  {
    this->skinChecksum = 0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointRemap);
    idList<idMD6Mesh *,19>::DeleteContents(this: &this->meshes);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
    this->skeleton = nullptr;
  }
}


// ========================================================================
// ?ReloadIfStale@idMD6Model@@UAA_NXZ
// EA  : 0x82847BD0
// RVA : 0x00847BD0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

int __fastcall idMD6Model::ReloadIfStale(idMD6Model *this)
{
  bool v3; // r29
  const idMD6Skel *skeleton; // r11
  idCollisionModelLocal *v5; // r3
  cmType_t ScriptP; // r11
  BOOL v7; // r10
  int v8; // r28
  int v9; // r29
  const idMaterial *mtr; // r11
  const char *str; // r4
  idCollisionModelLocal *v12; // r3
  int mtrChecksum; // r23
  cmType_t v14; // r3
  idStr v15; // [sp+50h] [-190h] BYREF
  idStr v16; // [sp+70h] [-170h] BYREF
  _BYTE v17[336]; // [sp+90h] [-150h] BYREF

  if ( idStr::Find(searchIn: this->name.str, searchFor: "bmd6model", casesensitive: true, start: 0, end: -1) != -1 )
    return 0;
  v3 = this->timestamp != fileSystem->GetTimestamp(this: fileSystem, a2: this->filename.data, a3: false);
  if ( !v3 )
  {
    skeleton = this->skeleton;
    if ( skeleton != nullptr )
    {
      idStr::idStr(this: &v16, text: skeleton->name.str);
      idStr::SetFileExtension(this: &v16, extension: MD6_SKEL_EXT);
      v3 = fileSystem->GetTimestamp(this: fileSystem, a2: this->skeleton->name.str, a3: false) != this->skelTimestamp;
      idStr::FreeData(this: &v16);
    }
  }
  if ( !v3 )
  {
    idStr::idStr(this: &v15, text: this->name.str);
    idStr::StripFileExtension(this: &v15);
    if ( v15.data != nullptr )
      v5 = (idCollisionModelLocal *)idDeclInfo::FindWithInheritance(
                                      this: &idDeclSkins::resourceList,
                                      name: v15.data,
                                      makeDefault: false);
    else
      v5 = nullptr;
    ScriptP = CM_POLYGONMODEL;
    if ( v5 != nullptr )
      ScriptP = idLexer::GetScriptP(this: v5);
    v3 = this->skinChecksum != ScriptP;
    idStr::FreeData(this: &v15);
  }
  v7 = v3;
  if ( !v3 )
  {
    v8 = 0;
    if ( this->sourceSurfaces.num <= 0 )
    {
LABEL_22:
      if ( !v7 )
        return 0;
    }
    else
    {
      v9 = 0;
      while ( 1 )
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
          v14 = idLexer::GetScriptP(this: v12);
          v7 = mtrChecksum != v14;
          if ( mtrChecksum != v14 )
            break;
        }
        ++v8;
        ++v9;
        if ( v8 >= this->sourceSurfaces.num )
          goto LABEL_22;
      }
    }
  }
  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: "bmd6model",
    a4: this->filename.data,
    a5: v17,
    a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v17, a3: FSPATH_BASE);
  this->skinChecksum = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointRemap);
  idList<idMD6Mesh *,19>::DeleteContents(this: &this->meshes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  this->skeleton = nullptr;
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// __unwind$231837
// EA  : 0x82847E58
// RVA : 0x00847E58
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231837()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 112));
}


// ========================================================================
// __unwind$231838
// EA  : 0x82847E80
// RVA : 0x00847E80
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void _unwind_231838()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 80));
}


// ========================================================================
// `dynamic initializer for 'idMD6Model::resourceList''
// EA  : 0x833442C8
// RVA : 0x013442C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idMD6Model::resourceList__()
{
  idResourceList::idResourceList(this: &idMD6Model::resourceList, typeName: "baseModel");
  idMD6Model::resourceList.__vftable = (idTypedResourceList<idMD6Model>_vtbl *)&idTypedResourceList<idMD6Model>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idMD6Model::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'r_skipMergeMeshes''
// EA  : 0x83344318
// RVA : 0x01344318
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipMergeMeshes__()
{
  idCVar::idCVar(
    this: &r_skipMergeMeshes,
    name: "r_skipMergeMeshes",
    value: "0",
    flags: 1,
    description: "skip combining rendermodel surface to reduce the batch count",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipMergeMeshes__);
}


// ========================================================================
// `dynamic initializer for 'r_skipGeneratedFileCheck''
// EA  : 0x83344370
// RVA : 0x01344370
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipGeneratedFileCheck__()
{
  idCVar::idCVar(
    this: &r_skipGeneratedFileCheck,
    name: "r_skipGeneratedFileCheck",
    value: "0",
    flags: 1,
    description: "override for skipping the generated file check",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipGeneratedFileCheck__);
}


// ========================================================================
// `dynamic initializer for 'convertMeshes_v''
// EA  : 0x833443C8
// RVA : 0x013443C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__convertMeshes_v__()
{
  return idCommandLink::idCommandLink(
           this: &convertMeshes_v,
           cmdName: "convertMeshes",
           function: convertMeshes_f,
           description: "Loads all md6mesh files and converts them",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'mergeSkeletons_v''
// EA  : 0x833443F0
// RVA : 0x013443F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6model.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__mergeSkeletons_v__()
{
  return idCommandLink::idCommandLink(
           this: &mergeSkeletons_v,
           cmdName: "mergeSkeletons",
           function: mergeSkeletons_f,
           description: "Loads all md6skl files and all md6mesh files and points meshes to shared skeletons",
           argCompletion: nullptr);
}

