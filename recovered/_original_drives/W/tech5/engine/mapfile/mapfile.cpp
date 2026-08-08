
// ========================================================================
// ?GetPlane@idMapBrushSide@@QBAABVidPlane@@XZ
// EA  : 0x8279E7C8
// RVA : 0x0079E7C8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

const idPlane *__fastcall idMapBrushSide::GetPlane(idMapBrushSide *this)
{
  return &this->plane;
}


// ========================================================================
// ?GetHorzSubdivisions@idMapPatch@@QBAHXZ
// EA  : 0x8279E7D0
// RVA : 0x0079E7D0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapPatch::GetHorzSubdivisions(idMapPatch *this)
{
  return this->horzSubdivisions;
}


// ========================================================================
// ?GetExplicitlySubdivided@idMapPatch@@QBA_NXZ
// EA  : 0x8279E7D8
// RVA : 0x0079E7D8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

BOOL __fastcall idMapPatch::GetExplicitlySubdivided(idMapPatch *this)
{
  return this->explicitSubdivisions;
}


// ========================================================================
// ?SetEntityDef@idMapEntity@@QAAXPAVidDeclEntityDef@@@Z
// EA  : 0x8279E7E0
// RVA : 0x0079E7E0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapEntity::SetEntityDef(idMapEntity *this, idDeclEntityDef *def)
{
  idDeclEntityDef *entityDef; // r3

  entityDef = this->entityDef;
  if ( entityDef != nullptr )
    ((void (__fastcall *)(idDeclEntityDef *, int))entityDef->dtr_idResource)(a1: entityDef, a2: 1);
  this->entityDef = def;
}


// ========================================================================
// ?IsSoundEntity@@YA_NPBVidMapFile@@PAVidMapEntity@@PAVidGame@@@Z
// EA  : 0x8279EB50
// RVA : 0x0079EB50
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

BOOL __fastcall IsSoundEntity(const idMapFile *mapFile, idMapEntity *entity, idGame *game)
{
  const char *v3; // r31

  v3 = entity->entityDef->GetClass(this: entity->entityDef);
  return idStr::Icmp(s1: v3, s2: "idWorldspawn") == 0
      || (_cntlzw(idStr::Icmpn(s1: v3, s2: "idSound", n: 7)) & 0x20) != 0;
}


// ========================================================================
// ?IsNotSoundEntity@@YA_NPBVidMapFile@@PAVidMapEntity@@PAVidGame@@@Z
// EA  : 0x8279EBD8
// RVA : 0x0079EBD8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

BOOL __fastcall IsNotSoundEntity(const idMapFile *mapFile, idMapEntity *entity, idGame *game)
{
  const char *v6; // r3

  v6 = entity->entityDef->GetClass(this: entity->entityDef);
  return idStr::Icmp(s1: v6, s2: "idWorldspawn") == 0 || (_cntlzw(IsSoundEntity(mapFile, entity, game)) & 0x20) != 0;
}


// ========================================================================
// ?GetTypeDef@idScriptObject@@QBAPAVidTypeDef@@XZ
// EA  : 0x8279EEA0
// RVA : 0x0079EEA0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

bfx::Space *__fastcall idScriptObject::GetTypeDef(bfx::Planner3D *this)
{
  return this->m_pSpace;
}


// ========================================================================
// ?GetNumLocalUsers@idSignInManagerXbox@@UBAHXZ
// EA  : 0x8279EEA8
// RVA : 0x0079EEA8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

unsigned int __fastcall idSignInManagerXbox::GetNumLocalUsers(D3DXShader::CTErrors *this)
{
  return this->m_uErrorCount;
}


// ========================================================================
// ?GetLocalUserByIndex@idSignInManagerXbox@@UBAPBVidLocalUser@@H@Z
// EA  : 0x8279EEB0
// RVA : 0x0079EEB0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapBrushSide *__fastcall idSignInManagerXbox::GetLocalUserByIndex(idMapBrush *this, int i)
{
  return this->sides.list[i];
}


// ========================================================================
// ?GetGeometryCRC@idMapBrush@@UBAIXZ
// EA  : 0x8279EEC0
// RVA : 0x0079EEC0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapBrush::GetGeometryCRC(idMapBrush *this)
{
  int num; // r11
  int result; // r3
  idMapBrushSide **list; // r7
  int i; // ctr
  int v6; // r10
  int v7; // r11
  char *data; // r8
  int v9; // r9
  unsigned int v10; // r6
  int v11; // r4
  char v12; // r3

  num = this->sides.num;
  result = 0;
  if ( num > 0 )
  {
    list = this->sides.list;
    for ( i = num; i != 0; --i )
    {
      v6 = 0;
      v7 = 0;
      data = (*list)->material.data;
      v9 = *data;
      v10 = COERCE_UNSIGNED_INT((*list)->plane.d)
          ^ COERCE_UNSIGNED_INT((*list)->plane.c)
          ^ COERCE_UNSIGNED_INT((*list)->plane.b)
          ^ COERCE_UNSIGNED_INT((*list)->plane.a)
          ^ result;
      if ( *data != 0 )
      {
        do
        {
          v11 = v9 << (v7++ & 3);
          v12 = data[v7];
          v6 ^= v11;
          v9 = v12;
        }
        while ( v12 != 0 );
      }
      result = v6 ^ v10;
      ++list;
    }
  }
  return result;
}


// ========================================================================
// ?Transform@idMapBrush@@UAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x8279EF70
// RVA : 0x0079EF70
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapBrush::Transform(idMapBrush *this, const idVec3 *origin, const idMat3 *axis)
{
  int v3; // r10
  int v4; // r9
  float *p_len; // r11
  double x; // fp8
  double z; // fp6
  double v8; // fp5
  double v9; // fp1
  double v10; // fp12
  double v11; // fp4
  double v12; // fp3
  double v13; // fp2

  v3 = 0;
  if ( this->sides.num > 0 )
  {
    v4 = 0;
    do
    {
      ++v3;
      p_len = (float *)&this->sides.list[v4]->material.len;
      x = axis->mat[1].x;
      ++v4;
      p_len += 8;
      z = axis->mat[2].z;
      v8 = p_len[1];
      v9 = p_len[2];
      v10 = p_len[3];
      v11 = (float)((float)(axis->mat[2].x * p_len[2]) + (float)(axis->mat[0].x * *p_len));
      v12 = (float)((float)(*p_len * axis->mat[0].z) + (float)(axis->mat[1].z * p_len[1]));
      v13 = (float)((float)(axis->mat[2].y * p_len[2])
                  + (float)((float)(axis->mat[0].y * *p_len) + (float)(axis->mat[1].y * p_len[1])));
      p_len[1] = (float)(axis->mat[2].y * p_len[2])
               + (float)((float)(axis->mat[0].y * *p_len) + (float)(axis->mat[1].y * p_len[1]));
      *p_len = (float)((float)v8 * (float)x) + (float)v11;
      p_len[2] = (float)((float)z * (float)v9) + (float)v12;
      p_len[3] = (float)v10
               - (float)((float)(origin->x * (float)((float)((float)v8 * (float)x) + (float)v11))
                       + (float)((float)(origin->y * (float)v13)
                               + (float)(origin->z * (float)((float)((float)z * (float)v9) + (float)v12))));
    }
    while ( v3 < this->sides.num );
  }
}


// ========================================================================
// ?GetGeometryCRC@idMapPatch@@UBAIXZ
// EA  : 0x8279F038
// RVA : 0x0079F038
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapPatch::GetGeometryCRC(idMapPatch *this)
{
  int v1; // r7
  int width; // r28
  unsigned int v3; // r31
  int height; // r29
  int v5; // r11
  int v6; // r9
  idDrawVert *list; // r8
  int v8; // r10
  float *p_x; // r6
  float *v10; // r6
  float *v11; // r5
  float v12; // r27
  float *v13; // r4
  double v14; // fp6
  double v15; // fp4
  unsigned int v16; // r4
  int v17; // ctr
  int v18; // r10
  char *data; // r8
  int v20; // r9
  int v21; // r11
  int v22; // r10
  int v23; // r6
  char v24; // r5
  float v26; // [sp+0h] [-60h]
  float v27; // [sp+4h] [-5Ch]
  float v28; // [sp+4h] [-5Ch]
  float back_chain; // [sp+8h] [-58h]
  float back_chaina; // [sp+8h] [-58h]

  v1 = 0;
  width = this->width;
  v3 = this->vertSubdivisions ^ this->horzSubdivisions;
  if ( width > 0 )
  {
    height = this->height;
    do
    {
      v5 = 0;
      if ( height >= 4 )
      {
        v6 = this->width;
        list = this->verts.list;
        v8 = 2;
        do
        {
          p_x = &list[v6 * v5 + v1].xyz.x;
          v27 = p_x[1];
          back_chain = p_x[2];
          v11 = &list[v8 * v6 + v1].xyz.x;
          v12 = *p_x;
          v10 = &list[(v8 - 1) * v6 + v1].xyz.x;
          v13 = &list[(v8 + 1) * v6 + v1].xyz.x;
          v5 += 4;
          v14 = v13[1];
          v15 = v13[2];
          v8 += 4;
          v26 = *v13;
          v16 = COERCE_UNSIGNED_INT(v10[2])
              ^ COERCE_UNSIGNED_INT(v10[1])
              ^ COERCE_UNSIGNED_INT(*v10)
              ^ LODWORD(back_chain)
              ^ LODWORD(v27)
              ^ LODWORD(v12)
              ^ v3;
          v28 = v14;
          back_chaina = v15;
          v3 = LODWORD(back_chaina)
             ^ LODWORD(v28)
             ^ LODWORD(v26)
             ^ COERCE_UNSIGNED_INT(v11[2])
             ^ COERCE_UNSIGNED_INT(v11[1])
             ^ COERCE_UNSIGNED_INT(*v11)
             ^ v16;
        }
        while ( v5 < height - 3 );
      }
      if ( v5 < height )
      {
        v17 = height - v5;
        do
        {
          v18 = this->width * v5++ + v1;
          v3 ^= COERCE_UNSIGNED_INT(this->verts.list[v18].xyz.z)
              ^ COERCE_UNSIGNED_INT(this->verts.list[v18].xyz.y)
              ^ COERCE_UNSIGNED_INT(this->verts.list[v18].xyz.x);
          --v17;
        }
        while ( v17 != 0 );
      }
      ++v1;
    }
    while ( v1 < width );
  }
  data = this->material.data;
  v20 = 0;
  v21 = 0;
  v22 = *data;
  if ( *data != 0 )
  {
    do
    {
      v23 = v22 << (v21++ & 3);
      v24 = data[v21];
      v20 ^= v23;
      v22 = v24;
    }
    while ( v24 != 0 );
  }
  return v20 ^ v3;
}


// ========================================================================
// ?PeerIndexOnHost@idLobby@@UBAHXZ
// EA  : 0x8279F248
// RVA : 0x0079F248
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

unsigned int __fastcall idLobby::PeerIndexOnHost(LEAPCORE::CXboxRendererConnection *this)
{
  return this->m_uDriverLatencySamples;
}


// ========================================================================
// ?TransformPrimitives@idMapModel@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x8279F250
// RVA : 0x0079F250
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapModel::TransformPrimitives(idMapModel *this, const idVec3 *origin, const idMat3 *axis)
{
  int v6; // r31
  int v7; // r30

  v6 = 0;
  if ( this->primitives.num > 0 )
  {
    v7 = 0;
    do
    {
      this->primitives.list[v7]->Transform(this: this->primitives.list[v7], a2: origin, a3: axis);
      ++v6;
      ++v7;
    }
    while ( v6 < this->primitives.num );
  }
}


// ========================================================================
// ?Write@idMapReference@@UBA_NPAVidFile@@H@Z
// EA  : 0x8279F2B8
// RVA : 0x0079F2B8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapReference::Write(idMapReference *this, idFile *fp, int refNum)
{
  fp->WriteFloatString(this: fp, a2: "\t// reference %d\n\t{\n", refNum);
  fp->WriteFloatString(this: fp, a2: "\t\treference {\n");
  fp->WriteFloatString(this: fp, a2: "\t\t\t\"%s\"\n", this->mapName.data);
  fp->WriteFloatString(this: fp, a2: "\t\t}\n");
  fp->WriteFloatString(this: fp, a2: "\t}\n");
  return 1;
}


// ========================================================================
// ?GetGeometryCRC@idMapReference@@UBAIXZ
// EA  : 0x8279F380
// RVA : 0x0079F380
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

unsigned int __fastcall idMapReference::GetGeometryCRC(idMapReference *this)
{
  char *data; // r9
  unsigned int result; // r3
  int v3; // r11
  int v4; // r10
  int v5; // r7
  char v6; // r6

  data = this->mapName.data;
  result = 0;
  v3 = 0;
  v4 = *data;
  if ( *data != 0 )
  {
    do
    {
      v5 = v4 << (v3++ & 3);
      v6 = data[v3];
      result ^= v5;
      v4 = v6;
    }
    while ( v6 != 0 );
  }
  return result;
}


// ========================================================================
// ?GetNumContactPhysics@idPhysics_Static@@UBAHXZ
// EA  : 0x8279F3C0
// RVA : 0x0079F3C0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

const char *__fastcall idPhysics_Static::GetNumContactPhysics(idDeclEntityDef *this)
{
  return this->inherit.str;
}


// ========================================================================
// ?GetEntity@idMapFile@@QBAPAVidMapEntity@@H@Z
// EA  : 0x8279F3C8
// RVA : 0x0079F3C8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapEntity *__fastcall idMapFile::GetEntity(idMapFile *this, int i)
{
  return this->entities.list[i];
}


// ========================================================================
// ?SetGeometryCRC@idMapFile@@AAAXXZ
// EA  : 0x8279F3D8
// RVA : 0x0079F3D8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapFile::SetGeometryCRC(idMapFile *this)
{
  int num; // r11
  int v3; // r25
  int v4; // r26
  int v5; // r28
  int v6; // r31
  idMapEntity *v7; // r11
  idMapModel *p_model; // r30
  int v9; // r29

  num = this->entities.num;
  v3 = 0;
  this->geometryCRC = 0;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = 0;
      v6 = 0;
      v7 = this->entities.list[v4];
      p_model = &v7->model;
      if ( v7->model.primitives.num > 0 )
      {
        v9 = 0;
        do
        {
          ++v6;
          v5 ^= p_model->primitives.list[v9]->GetGeometryCRC(this: p_model->primitives.list[v9]);
          ++v9;
        }
        while ( v6 < p_model->primitives.num );
      }
      ++v3;
      ++v4;
      this->geometryCRC ^= v5;
    }
    while ( v3 < this->entities.num );
  }
}


// ========================================================================
// ?FindEntity@idMapFile@@QBAPAVidMapEntity@@PBDPAH@Z
// EA  : 0x8279F480
// RVA : 0x0079F480
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapEntity *__fastcall idMapFile::FindEntity(idMapFile *this, const char *name, int *index)
{
  int v6; // r31
  int i; // r29
  idMapEntity *v8; // r30
  idDeclEntityDef *entityDef; // r11

  v6 = 0;
  if ( this->entities.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v8 = this->entities.list[i];
    if ( v8 == nullptr || (entityDef = v8->entityDef) == nullptr )
    {
      idLib::Warning(fmt: "idMapFile::FindEntity - Invalid or NULL entity in list (index = %d)", v6);
      goto LABEL_10;
    }
    if ( idStr::Icmp(s1: entityDef->name.str, s2: name) == 0 )
      break;
LABEL_10:
    if ( ++v6 >= this->entities.num )
      return nullptr;
  }
  if ( index != nullptr )
    *index = v6;
  return v8;
}


// ========================================================================
// ?FindReferenceMap@idMapFile@@QAAHPBD@Z
// EA  : 0x8279F528
// RVA : 0x0079F528
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapFile::FindReferenceMap(idMapFile *this, const char *name)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->referenceMaps.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: this->referenceMaps.list[i].mapName.data, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->referenceMaps.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?IsSoundPrimitive@@YA_NPAVidMapPrimitive@@PAVidGame@@@Z
// EA  : 0x8279FA30
// RVA : 0x0079FA30
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

BOOL __fastcall IsSoundPrimitive(idMapPrimitive *primitive, idGame *game)
{
  int v4; // r29
  int v5; // r31
  int v6; // r30
  const char *v7; // r4
  const idDecl *v8; // r3

  if ( primitive->type != 0 )
    return false;
  v4 = 0;
  v5 = 0;
  if ( (int)primitive[1].groupList.list > 0 )
  {
    v6 = 0;
    do
    {
      v7 = (const char *)(*(_DWORD **)((char *)&primitive[1].dtr_idMapGroups + v6))[1];
      if ( v7 != nullptr )
        v8 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v7, makeDefault: true);
      else
        v8 = nullptr;
      ++v5;
      v4 |= idParmBlock::GetInteger(this: (idParmBlock *)&v8[1].staleCount, parm: rp->toolsFlags);
      v6 += 4;
    }
    while ( v5 < (int)primitive[1].groupList.list );
  }
  return (v4 & 0x7E) != 0;
}


// ========================================================================
// ?IsNotSoundPrimitive@@YA_NPAVidMapPrimitive@@PAVidGame@@@Z
// EA  : 0x8279FAE0
// RVA : 0x0079FAE0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

BOOL __fastcall IsNotSoundPrimitive(idMapPrimitive *primitive, idGame *game)
{
  return (_cntlzw(IsSoundPrimitive(primitive, game)) & 0x20) != 0;
}


// ========================================================================
// ?WriteGroups@idMapGroups@@QBAXPAVidFile@@PBD@Z
// EA  : 0x8279FB78
// RVA : 0x0079FB78
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapGroups::WriteGroups(idMapGroups *this, idFile *fp, const char *tabs)
{
  int v6; // r31
  int v7; // r30

  if ( this->groupList.num != 0 )
  {
    fp->WriteFloatString(this: fp, a2: "%sgroups {\n");
    v6 = 0;
    if ( this->groupList.num > 0 )
    {
      v7 = 0;
      do
      {
        fp->WriteFloatString(this: fp, a2: "%s\t\"%s\"\n", tabs, this->groupList.list[v7].data);
        ++v6;
        ++v7;
      }
      while ( v6 < this->groupList.num );
    }
    fp->WriteFloatString(this: fp, a2: "%s}\n", tabs);
  }
}


// ========================================================================
// ?RenameReferenceGroups@idMapGroups@@QAAXPBD@Z
// EA  : 0x8279FC40
// RVA : 0x0079FC40
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapGroups::RenameReferenceGroups(idMapGroups *this, const char *refname, int a3, int a4, __int64 a5)
{
  int v7; // r25
  __int64 v8; // r10
  int v9; // r29
  __int64 v10; // r6
  va *v11; // r3
  idStr *v12; // r30
  size_t len; // r28
  int v14; // r4
  int allocedAndFlag; // r11
  int v16; // [sp+8h] [-10C8h]
  int v17; // [sp+Ch] [-10C4h]
  int v18; // [sp+10h] [-10C0h]
  int v19; // [sp+14h] [-10BCh]
  int v20; // [sp+18h] [-10B8h]
  int v21; // [sp+1Ch] [-10B4h]
  idStr v22; // [sp+50h] [-1080h] BYREF
  va v23; // [sp+70h] [-1060h] BYREF

  v7 = 0;
  if ( this->groupList.num > 0 )
  {
    LODWORD(v8) = 0x82000000;
    HIDWORD(v8) = 0x82000000;
    v9 = 0;
    do
    {
      HIDWORD(v10) = refname;
      LODWORD(v10) = this->groupList.list[v9].data;
      v11 = va::va(
              this: &v23,
              fmt: "$%s/%s",
              a3: v10,
              a4: a5,
              a5: v8,
              a6: v16,
              a7: v17,
              a8: v18,
              a9: v19,
              a10: v20,
              a11: v21);
      idStr::idStr(this: &v22, text: v11);
      v12 = &this->groupList.list[v9];
      len = v22.len;
      v14 = v22.len + 1;
      allocedAndFlag = v12->allocedAndFlag;
      if ( allocedAndFlag >= 0 )
      {
        if ( v14 > (allocedAndFlag & 0x7FFFFFFF) )
          idStr::ReAllocate(this: &this->groupList.list[v9], amount: v14, keepold: false);
      }
      else if ( v14 > (allocedAndFlag & 0x7FFFFFFF)
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      memcpy(Dst: v12->data, Src: v22.data, Size: len);
      v12->data[len] = 0;
      v12->len = len;
      idStr::FreeData(this: &v22);
      LODWORD(v8) = this->groupList.num;
      ++v7;
      ++v9;
    }
    while ( v7 < (int)v8 );
  }
}


// ========================================================================
// __unwind$233120
// EA  : 0x8279FD64
// RVA : 0x0079FD64
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_233120()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 80));
}


// ========================================================================
// ?RemoveLeadingReferencePaths@idMapGroups@@QAA?AVidStr@@XZ
// EA  : 0x8279FD98
// RVA : 0x0079FD98
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapGroups *__fastcall idMapGroups::RemoveLeadingReferencePaths(idMapGroups *this, idStr *result)
{
  int v4; // r21
  int v5; // r28
  int v6; // r3
  int v7; // r26
  idStr *v8; // r20
  idMapGroups_vtbl *len; // r30
  idStr *v10; // r30
  size_t v11; // r26
  idStr v13; // [sp+60h] [-B0h] BYREF
  idStr v14[4]; // [sp+80h] [-90h] BYREF

  this->__vftable = nullptr;
  this->groupList.num = 20;
  this->groupList.list = (idStr *)&this->groupList.size;
  HIBYTE(this->groupList.size) = 0;
  v4 = 0;
  if ( result->allocedAndFlag > 0 )
  {
    v5 = 0;
    do
    {
      if ( idStr::Find(
             searchIn: *(const char **)&result->data[v5 + 4],
             searchFor: "$func_reference",
             casesensitive: true,
             start: 0,
             end: *(_DWORD *)&result->data[v5]) != 0 )
      {
        v6 = idStr::Find(
               searchIn: *(const char **)&result->data[v5 + 4],
               searchFor: "/",
               casesensitive: true,
               start: 0,
               end: *(_DWORD *)&result->data[v5]);
        v7 = v6;
        if ( this->__vftable == nullptr )
        {
          v8 = idStr::Left(this: v14, result: (idStr *)&result->data[v5], len: v6);
          len = (idMapGroups_vtbl *)v8->len;
          idStr::EnsureAlloced((idStr *)this, amount: v8->len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: this->groupList.list, Src: v8->data, Size: (size_t)len);
          *((_BYTE *)&this->groupList.list->len + (unsigned int)len) = 0;
          this->__vftable = len;
          idStr::FreeData(this: v14);
          idStr::StripLeadingOnce((idStr *)this, string: "$");
        }
        idStr::Right(this: &v13, result: (idStr *)&result->data[v5], len: *(_DWORD *)&result->data[v5] - v7 - 1);
        v10 = (idStr *)&result->data[v5];
        v11 = v13.len;
        idStr::EnsureAlloced(this: v10, amount: v13.len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v10->data, Src: v13.data, Size: v11);
        v10->data[v11] = 0;
        v10->len = v11;
        idStr::FreeData(this: &v13);
      }
      ++v4;
      v5 += 32;
    }
    while ( v4 < result->allocedAndFlag );
  }
  return this;
}


// ========================================================================
// __unwind$233206
// EA  : 0x8279FF4C
// RVA : 0x0079FF4C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_233206()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 272;
  if ( (*(_DWORD *)(v0 - 272 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 292));
  }
}


// ========================================================================
// __unwind$233209
// EA  : 0x8279FF90
// RVA : 0x0079FF90
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_233209()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$233210
// EA  : 0x8279FFB8
// RVA : 0x0079FFB8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_233210()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// ?Write@idMapBrush@@UBA_NPAVidFile@@H@Z
// EA  : 0x8279FFE0
// RVA : 0x0079FFE0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapBrush::Write(idMapBrush *this, idFile *fp, int primitiveNum)
{
  int v5; // r30
  int v6; // r29
  float *p_len; // r25

  fp->WriteFloatString(this: fp, a2: "\t{\n");
  idMapGroups::WriteGroups(this, fp, tabs: "\t\t");
  fp->WriteFloatString(this: fp, a2: "\t\tbrushDef3 {\n");
  v5 = 0;
  if ( this->sides.num > 0 )
  {
    v6 = 0;
    do
    {
      p_len = (float *)&this->sides.list[v6]->material.len;
      fp->WriteFloatString(
        this: fp,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(p_len[8])),
        COERCE_UNSIGNED_INT64(p_len[8]),
        COERCE_UNSIGNED_INT64(p_len[9]),
        COERCE_UNSIGNED_INT64(p_len[10]),
        COERCE_UNSIGNED_INT64(p_len[11]));
      fp->WriteFloatString(
        this: fp,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(p_len[12])),
        COERCE_UNSIGNED_INT64(p_len[12]),
        COERCE_UNSIGNED_INT64(p_len[13]),
        COERCE_UNSIGNED_INT64(p_len[14]),
        COERCE_UNSIGNED_INT64(p_len[15]),
        COERCE_UNSIGNED_INT64(p_len[16]),
        COERCE_UNSIGNED_INT64(p_len[17]));
      ++v5;
      ++v6;
    }
    while ( v5 < this->sides.num );
  }
  fp->WriteFloatString(this: fp, a2: "\t\t}\n");
  fp->WriteFloatString(this: fp, a2: "\t}\n");
  return 1;
}


// ========================================================================
// ?Write@idMapPatch@@UBA_NPAVidFile@@H@Z
// EA  : 0x827A0178
// RVA : 0x007A0178
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapPatch::Write(idMapPatch *this, idFile *fp, int primitiveNum)
{
  unsigned int (*WriteFloatString)(idFile *, const char *, ...); // ctr
  int i; // r28
  int j; // r29
  idDrawVert *v8; // r11

  WriteFloatString = fp->WriteFloatString;
  if ( this->explicitSubdivisions )
  {
    WriteFloatString(this: fp, a2: "\t// primitive %d\n\t{\n");
    idMapGroups::WriteGroups(this, fp, tabs: "\t\t");
    fp->WriteFloatString(this: fp, a2: "\t\tpatchDef3 {\n");
    fp->WriteFloatString(this: fp, a2: "\t\t\t\"%s\"\n", this->material.data);
    fp->WriteFloatString(
      this: fp,
      a2: "\t\t\t( %d %d %d %d 0 0 0 )\n",
      this->width,
      this->height,
      this->horzSubdivisions,
      this->vertSubdivisions);
  }
  else
  {
    WriteFloatString(this: fp, a2: "\t// primitive %d\n\t{\n");
    idMapGroups::WriteGroups(this, fp, tabs: "\t\t");
    fp->WriteFloatString(this: fp, a2: "\t\tpatchDef2 {\n");
    fp->WriteFloatString(this: fp, a2: "\t\t\t\"%s\"\n", this->material.data);
    fp->WriteFloatString(this: fp, a2: "\t\t\t( %d %d 0 0 0 )\n", this->width, this->height);
  }
  fp->WriteFloatString(this: fp, a2: "\t\t\t(\n");
  for ( i = 0; i < this->width; ++i )
  {
    fp->WriteFloatString(this: fp, a2: "\t\t\t\t(");
    for ( j = 0; j < this->height; ++j )
    {
      v8 = &this->verts.list[this->width * j + i];
      fp->WriteFloatString(
        this: fp,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v8->xyz.x)),
        COERCE_UNSIGNED_INT64(v8->xyz.x),
        COERCE_UNSIGNED_INT64(v8->xyz.y),
        COERCE_UNSIGNED_INT64(v8->xyz.z),
        COERCE_UNSIGNED_INT64(v8->st.x),
        COERCE_UNSIGNED_INT64(v8->st.y));
    }
    fp->WriteFloatString(this: fp, a2: " )\n");
  }
  fp->WriteFloatString(this: fp, a2: "\t\t\t)\n");
  fp->WriteFloatString(this: fp, a2: "\t\t}\n");
  fp->WriteFloatString(this: fp, a2: "\t}\n");
  return 1;
}


// ========================================================================
// ?Transform@idMapPatch@@UAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x827A0420
// RVA : 0x007A0420
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapPatch::Transform(idMapPatch *this, const idVec3 *origin, idMat3 *axis, int a4, __int64 a5)
{
  idSurface_Patch *v5; // r31

  v5 = &this->idSurface_Patch;
  idSurface::RotateSelf(this: &this->idSurface_Patch, rotation: axis, _R5: (float *)axis, a4, _R8: a5);
  idSurface::TranslateSelf(this: v5, translation: origin);
}


// ========================================================================
// ?Write@idMapEntity@@QBA_NPAVidFile@@PAVidGame@@HP6A_NPAVidMapPrimitive@@1@Z_N@Z
// EA  : 0x827A0478
// RVA : 0x007A0478
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapEntity::Write(
        idMapEntity *this,
        idFile *fp,
        idGame *game,
        int entityNum,
        bool (__fastcall *ShouldWritePrimitive)(idMapPrimitive *, idGame *),
        bool isEntitiesFile)
{
  BOOL v11; // r25
  int v12; // r28
  int v13; // r27
  char *Text; // r3
  int v15; // r27
  int v16; // r28
  idStr v18[4]; // [sp+50h] [-80h] BYREF

  v11 = isEntitiesFile;
  fp->WriteFloatString(this: fp, a2: "entity {\n");
  if ( !isEntitiesFile )
    idMapGroups::WriteGroups(this, fp, tabs: "\t");
  if ( this->layerList.num > 0 )
  {
    fp->WriteFloatString(this: fp, a2: "\tlayers {\n");
    v12 = 0;
    if ( this->layerList.num > 0 )
    {
      v13 = 0;
      do
      {
        fp->WriteFloatString(this: fp, a2: "\t\t\"%s\"\n", this->layerList.list[v13].data);
        ++v12;
        ++v13;
      }
      while ( v12 < this->layerList.num );
    }
    fp->WriteFloatString(this: fp, a2: "\t}\n");
  }
  this->entityDef->SetInheritedClass(this: this->entityDef, a2: false);
  v18[0].len = 0;
  v18[0].baseBuffer[0] = 0;
  v18[0].allocedAndFlag = 20;
  v18[0].data = v18[0].baseBuffer;
  if ( v11 && com_useExpandedEntityDefs.valueInteger != 0 )
  {
    this->entityDef->GetTextWithInheritance(this: this->entityDef, a2: v18, a3: false);
  }
  else
  {
    Text = idDecl::GetText(this: &this->entityDef->idDecl);
    idStr::operator=(this: v18, text: Text);
  }
  fp->Printf(this: fp, a2: "\tentityDef %s ", this->entityDef->name.str);
  fp->Write(this: fp, a2: v18[0].data, a3: v18[0].len);
  fp->Write(this: fp, a2: "\n", a3: 1u);
  v15 = 0;
  if ( this->model.primitives.num > 0 )
  {
    v16 = 0;
    do
    {
      if ( ShouldWritePrimitive(a1: this->model.primitives.list[v16], a2: game) )
        this->model.primitives.list[v16]->Write(this: this->model.primitives.list[v16], a2: fp, a3: v15);
      ++v15;
      ++v16;
    }
    while ( v15 < this->model.primitives.num );
  }
  fp->WriteFloatString(this: fp, a2: "}\n");
  idStr::FreeData(this: v18);
  return 1;
}


// ========================================================================
// __unwind$233571
// EA  : 0x827A06EC
// RVA : 0x007A06EC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_233571()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?RemoveEntity@idMapFile@@QAAXPAVidMapEntity@@@Z
// EA  : 0x827A0718
// RVA : 0x007A0718
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapFile::RemoveEntity(idMapFile *this, idMapEntity *mapEnt)
{
  idList<idEntityPtr<idEntity>,58> *p_entities; // r3
  int v4; // r4
  int num; // r10
  int v6; // r11

  p_entities = (idList<idEntityPtr<idEntity>,58> *)&this->entities;
  v4 = 0;
  num = p_entities->num;
  if ( num > 0 )
  {
    v6 = 0;
    while ( (idMapEntity *)p_entities->list[v6].spawnId.value != mapEnt )
    {
      ++v4;
      ++v6;
      if ( v4 >= num )
        goto LABEL_8;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_entities, index: v4);
  }
LABEL_8:
  if ( mapEnt != nullptr )
    ((void (__fastcall *)(idMapEntity *, int))mapEnt->dtr_idMapGroups)(a1: mapEnt, a2: 1);
}


// ========================================================================
// ?ClearCopiedEntities@idMapFile@@QAAXABVidStr@@@Z
// EA  : 0x827A07A8
// RVA : 0x007A07A8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapFile::ClearCopiedEntities(idMapFile *this, const idStr *refname, int a3, int a4, __int64 a5)
{
  int v7; // r29
  int v8; // r30
  idMapEntity **list; // r4

  if ( refname->len != 0 )
  {
    v7 = 0;
    if ( this->entities.num > 0 )
    {
      v8 = 0;
      do
      {
        idMapGroups::RenameReferenceGroups(this: this->entities.list[v8], refname: refname->data, a3, a4, a5);
        ++v7;
        ++v8;
      }
      while ( v7 < this->entities.num );
    }
  }
  if ( this->entities.listStatic == 0 || this->entities.listStatic == 2 )
  {
    list = this->entities.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->entities.list = nullptr;
    this->entities.size = 0;
  }
  this->entities.num = 0;
  this->entitiesAreReference = false;
}


// ========================================================================
// ?Write@idMapEditorStates@@QBAXPAVidFile@@@Z
// EA  : 0x827A09D0
// RVA : 0x007A09D0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapEditorStates::Write(idMapEditorStates *this, idFile *fp)
{
  int v4; // r27
  int v5; // r26
  idGroupState *v6; // r28
  int v7; // r27
  int v8; // r26
  idGroupState *v9; // r28
  __int128 v10; // r7
  __int64 v11; // r10
  double v12; // fp27
  double v13; // fp29
  double v14; // fp28
  idStr v15; // [sp+70h] [-D0h] BYREF
  unsigned int state; // [sp+90h] [-B0h]
  idStr v17; // [sp+A0h] [-A0h] BYREF
  unsigned int v18; // [sp+C0h] [-80h]

  if ( this->groupStates.num != 0 )
  {
    fp->WriteFloatString(this: fp, a2: "groupstates {\n");
    v4 = 0;
    if ( this->groupStates.num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = &this->groupStates.list[v5];
        idStr::idStr(this: &v15, text: &v6->groupName);
        state = v6->state;
        fp->WriteFloatString(this: fp, a2: "\t\"%s\" \"%s\"\n", v15.data, groupStateTokens[state]);
        idStr::FreeData(this: &v15);
        ++v4;
        ++v5;
      }
      while ( v4 < this->groupStates.num );
    }
    fp->WriteFloatString(this: fp, a2: "}\n");
  }
  if ( this->groupColors.num != 0 )
  {
    fp->WriteFloatString(this: fp, a2: "groupcolors {\n");
    v7 = 0;
    if ( this->groupColors.num > 0 )
    {
      v8 = 0;
      do
      {
        v9 = &this->groupColors.list[v8];
        idStr::idStr(this: &v17, text: &v9->groupName);
        v18 = v9->state;
        DWORD2(v10) = BYTE2(v18);
        LODWORD(v11) = BYTE1(v18);
        LODWORD(v10) = (unsigned __int8)v18;
        v12 = (float)((float)(__int64)v10 * (float)0.0039215689);
        v13 = (float)((float)v11 * (float)0.0039215689);
        v14 = (float)((float)*(__int64 *)((char *)&v10 + 4) * (float)0.0039215689);
        fp->WriteFloatString(this: fp, a2: "\t\"%s\" ", v17.data);
        fp->WriteFloatString(
          this: fp,
          a2: "%.3f %.3f %.3f %.3f\n",
          LODWORD(v12),
          LODWORD(v14),
          LODWORD(v13),
          0,
          v12,
          v14,
          v13,
          1.0);
        idStr::FreeData(this: &v17);
        ++v7;
        ++v8;
      }
      while ( v7 < this->groupColors.num );
    }
    fp->WriteFloatString(this: fp, a2: "}\n");
  }
}


// ========================================================================
// __unwind$234206
// EA  : 0x827A0C20
// RVA : 0x007A0C20
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234206()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$234207
// EA  : 0x827A0C48
// RVA : 0x007A0C48
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234207()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// ??0idMapModel@@QAA@XZ
// EA  : 0x827A0C78
// RVA : 0x007A0C78
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapModel *__fastcall idMapModel::idMapModel(idMapModel *this)
{
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->primitives.list = nullptr;
  this->primitives.granularity = 0;
  this->primitives.memTag = 5;
  this->primitives.listStatic = 0;
  this->primitives.size = 0;
  this->primitives.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->primitives);
  return this;
}


// ========================================================================
// __unwind$234332
// EA  : 0x827A0CF4
// RVA : 0x007A0CF4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234332()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idMapModel@@QAA@XZ
// EA  : 0x827A0D28
// RVA : 0x007A0D28
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapModel::~idMapModel(idMapModel *this)
{
  idList<idMapPrimitive *,5> *p_primitives; // r29

  p_primitives = &this->primitives;
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->primitives);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_primitives);
  idStr::FreeData(this: &this->name);
}


// ========================================================================
// __unwind$234375
// EA  : 0x827A0D64
// RVA : 0x007A0D64
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234375()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$234376
// EA  : 0x827A0D8C
// RVA : 0x007A0D8C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234376()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// ?Transform@idMapEntity@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x827A0DC0
// RVA : 0x007A0DC0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapEntity::Transform(idMapEntity *this, const idVec3 *origin, const idMat3 *axis)
{
  const char *v6; // r3
  idDeclEntityDef *entityDef; // r27
  int v8; // r26
  const char *v9; // r3
  double y; // fp8
  double x; // fp9
  double v12; // fp4
  double v13; // fp3
  idVec3 v14; // [sp+50h] [-90h] BYREF
  idTypeInfoTree v15; // [sp+60h] [-80h] BYREF
  idMat3 v16[2]; // [sp+80h] [-60h] BYREF

  v6 = this->entityDef->GetClass(this: this->entityDef);
  if ( idStr::Icmp(s1: v6, s2: "idWorldSpawn") != 0 )
  {
    entityDef = this->entityDef;
    v8 = entityDef->GetEntityStateWithInheritanceLength(this: entityDef);
    v9 = entityDef->GetEntityStateWithInheritance(this: entityDef);
    idTypeInfoTree::idTypeInfoTree(this: &v15, text: v9, length: v8);
    idTypeInfoTree::GetVec3(this: &v15, path: "spawnPosition", value: &v14);
    idTypeInfoTree::GetMat3(this: &v15, path: "spawnOrientation", value: v16);
    y = origin->y;
    x = origin->x;
    v12 = (float)((float)(axis->mat[2].y * v14.z)
                + (float)((float)(axis->mat[0].y * v14.x) + (float)(axis->mat[1].y * v14.y)));
    v13 = (float)((float)(axis->mat[0].x * v14.x)
                + (float)((float)(axis->mat[1].x * v14.y) + (float)(axis->mat[2].x * v14.z)));
    v14.z = origin->z
          + (float)((float)(axis->mat[2].z * v14.z)
                  + (float)((float)(axis->mat[0].z * v14.x) + (float)(axis->mat[1].z * v14.y)));
    v14.y = (float)y + (float)v12;
    v14.x = (float)x + (float)v13;
    idMat3::operator*=(this: v16, a: axis);
    idTypeInfoTree::SetVec3(this: &v15, path: "spawnPosition", value: &v14);
    idTypeInfoTree::SetMat3(this: &v15, path: "spawnOrientation", value: v16);
    this->entityDef->SetEntityState_2(this: this->entityDef, a2: &v15, a3: true, a4: false);
    idTypeInfoTree::~idTypeInfoTree(this: &v15);
  }
  else
  {
    idMapModel::TransformPrimitives(this: &this->model, origin, axis);
  }
}


// ========================================================================
// __unwind$234407
// EA  : 0x827A0F5C
// RVA : 0x007A0F5C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234407()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 224 + 96));
}


// ========================================================================
// ?FixMapModelNames@idMapEntity@@QAAXPBD0@Z
// EA  : 0x827A0F90
// RVA : 0x007A0F90
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapEntity::FixMapModelNames(idMapEntity *this, const char *mapName, const char *name)
{
  idDeclEntityDef *entityDef; // r28
  int v6; // r26
  const char *v7; // r3
  char v8; // r26
  idStr *v9; // r3
  BOOL v10; // r23
  __int64 v11; // r10
  int v12; // r7
  __int64 v13; // r6
  idStr *MapModelName; // r3
  __int64 v15; // r6
  __int64 v16; // r10
  int v17; // r7
  idStr *v18; // r3
  __int64 v19; // [sp+8h] [-1F8h]
  __int64 v20; // [sp+8h] [-1F8h]
  idStr v21; // [sp+50h] [-1B0h] BYREF
  idTypeInfoTree v22; // [sp+70h] [-190h] BYREF
  idStr v23; // [sp+90h] [-170h] BYREF
  idStr v24; // [sp+B0h] [-150h] BYREF
  idStr v25; // [sp+D0h] [-130h] BYREF
  idStr v26; // [sp+F0h] [-110h] BYREF
  idStr v27; // [sp+110h] [-F0h] BYREF
  idStr v28; // [sp+130h] [-D0h] BYREF
  idStr v29; // [sp+150h] [-B0h] BYREF
  idStr v30; // [sp+170h] [-90h] BYREF
  idStr v31[3]; // [sp+190h] [-70h] BYREF

  if ( idLib::production != PROD_PRODUCTION )
  {
    v21.len = 0;
    v21.allocedAndFlag = 20;
    v21.data = v21.baseBuffer;
    v21.baseBuffer[0] = 0;
    entityDef = this->entityDef;
    v6 = entityDef->GetEntityStateWithInheritanceLength(this: entityDef);
    v7 = entityDef->GetEntityStateWithInheritance(this: entityDef);
    idTypeInfoTree::idTypeInfoTree(this: &v22, text: v7, length: v6);
    idTypeInfoTree::GetStrType(this: &v22, path: "renderModelInfo.model", value: &v21);
    if ( v21.len != 0 )
    {
      v27.allocedAndFlag = 20;
      v27.len = 0;
      v27.data = v27.baseBuffer;
      v27.baseBuffer[0] = 0;
      idStr::ExtractFileExtension(this: &v21, dest: &v27);
      if ( (idStr::Icmpn(s1: v21.data, s2: "maps/", n: 5) == 0 || idStr::Icmpn(s1: v21.data, s2: "prefabs/", n: 8) == 0)
        && v27.len == 0 )
      {
        v25.allocedAndFlag = 20;
        v25.len = 0;
        v25.data = v25.baseBuffer;
        v25.baseBuffer[0] = 0;
        idStr::ExtractFileBase(this: &v21, dest: &v25);
        idStr::idStr(this: &v28, text: name);
        v8 = 0;
        v9 = idStr::Right(this: &v29, result: &v28, len: v25.len);
        v10 = (_cntlzw(idStr::Icmp(s1: v25.data, s2: v9->data)) & 0x20) != 0;
        idStr::FreeData(this: &v29);
        if ( v10 )
        {
          HIDWORD(v13) = name;
          MapModelName = idMapFile::GetMapModelName(result: &v30, entityName: v13, a3: v12, a4: v11, a5: v19);
          idStr::operator=(this: &v28, text: MapModelName);
          idStr::FreeData(this: &v30);
          if ( idStr::Cmp(s1: v28.data, s2: v21.data) != 0 )
          {
            v8 = 1;
            idTypeInfoTree::SetStrType(this: &v22, path: "renderModelInfo.model", value: v28.data);
          }
          v24.allocedAndFlag = 20;
          v24.len = 0;
          v24.data = v24.baseBuffer;
          v24.baseBuffer[0] = 0;
          idTypeInfoTree::GetStrType(this: &v22, path: "clipModelInfo.type", value: &v24);
          v26.allocedAndFlag = 20;
          v26.data = v26.baseBuffer;
          v26.len = 0;
          v26.baseBuffer[0] = 0;
          v23.allocedAndFlag = 20;
          v23.data = v23.baseBuffer;
          v23.len = 0;
          v23.baseBuffer[0] = 0;
          if ( idStr::Cmp(s1: v24.data, s2: "CLIPMODEL_CUSTOM") != 0
            && idStr::Cmp(s1: v24.data, s2: "CLIPMODEL_NONE") != 0 )
          {
            idTypeInfoTree::GetStrType(this: &v22, path: "clipModelInfo.clipModelName", value: &v26);
            HIDWORD(v15) = name;
            v18 = idMapFile::GetMapModelName(result: v31, entityName: v15, a3: v17, a4: v16, a5: v20);
            idStr::operator=(this: &v23, text: v18);
            idStr::FreeData(this: v31);
            if ( idStr::Cmp(s1: v23.data, s2: v26.data) != 0 )
            {
              v8 = 1;
              idTypeInfoTree::SetStrType(this: &v22, path: "clipModelInfo.clipModelName", value: v23.data);
            }
          }
          if ( v8 != 0 )
            this->entityDef->SetEntityState_2(this: this->entityDef, a2: &v22, a3: true, a4: false);
          idStr::FreeData(this: &v23);
          idStr::FreeData(this: &v26);
          idStr::FreeData(this: &v24);
        }
        idStr::FreeData(this: &v28);
        idStr::FreeData(this: &v25);
      }
      idStr::FreeData(this: &v27);
      idTypeInfoTree::~idTypeInfoTree(this: &v22);
    }
    else
    {
      idTypeInfoTree::~idTypeInfoTree(this: &v22);
    }
    idStr::FreeData(this: &v21);
  }
}


// ========================================================================
// __unwind$234483
// EA  : 0x827A12B4
// RVA : 0x007A12B4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234483()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 80));
}


// ========================================================================
// __unwind$234484
// EA  : 0x827A12DC
// RVA : 0x007A12DC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234484()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 512 + 112));
}


// ========================================================================
// __unwind$234485
// EA  : 0x827A1304
// RVA : 0x007A1304
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234485()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 272));
}


// ========================================================================
// __unwind$234486
// EA  : 0x827A132C
// RVA : 0x007A132C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 208));
}


// ========================================================================
// __unwind$234487
// EA  : 0x827A1354
// RVA : 0x007A1354
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234487()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 304));
}


// ========================================================================
// __unwind$234488
// EA  : 0x827A137C
// RVA : 0x007A137C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234488()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 336));
}


// ========================================================================
// __unwind$234489
// EA  : 0x827A13A4
// RVA : 0x007A13A4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234489()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 368));
}


// ========================================================================
// __unwind$234490
// EA  : 0x827A13CC
// RVA : 0x007A13CC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234490()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 176));
}


// ========================================================================
// __unwind$234491
// EA  : 0x827A13F4
// RVA : 0x007A13F4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234491()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 240));
}


// ========================================================================
// __unwind$234492
// EA  : 0x827A141C
// RVA : 0x007A141C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234492()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 144));
}


// ========================================================================
// __unwind$234493
// EA  : 0x827A1444
// RVA : 0x007A1444
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234493()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 400));
}


// ========================================================================
// ?FixTargetNames@idMapEntity@@QAAXPBD@Z
// EA  : 0x827A1478
// RVA : 0x007A1478
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapEntity::FixTargetNames(idMapEntity *this, const char *baseName)
{
  idDeclEntityDef *entityDef; // r30
  int v5; // r29
  const char *v6; // r3
  int v7; // r25
  int v8; // r30
  const char *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  va *v12; // r3
  idTypeInfoNode **list; // r29
  const char *v14; // r3
  int v15; // [sp+8h] [-10E8h]
  int v16; // [sp+Ch] [-10E4h]
  int v17; // [sp+10h] [-10E0h]
  int v18; // [sp+14h] [-10DCh]
  int v19; // [sp+18h] [-10D8h]
  int v20; // [sp+1Ch] [-10D4h]
  idList<idTypeInfoNode *,5> v21; // [sp+50h] [-10A0h] BYREF
  idStr v22; // [sp+60h] [-1090h] BYREF
  idTypeInfoTree v23; // [sp+80h] [-1070h] BYREF
  idTypeInfoNode **v24; // [sp+98h] [-1058h]
  va v25; // [sp+A0h] [-1050h] BYREF

  v22.len = 0;
  v22.baseBuffer[0] = 0;
  v22.allocedAndFlag = 20;
  v22.data = v22.baseBuffer;
  entityDef = this->entityDef;
  v5 = entityDef->GetEntityStateWithInheritanceLength(this: entityDef);
  v6 = entityDef->GetEntityStateWithInheritance(this: entityDef);
  idTypeInfoTree::idTypeInfoTree(this: &v23, text: v6, length: v5);
  memset(&v21, 0, 14);
  *(_WORD *)&v21.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v21);
  idTypeInfoTree::GetTypes(this: &v23, type: "idEntity", ops: "*", nodes: &v21);
  idTypeInfoTree::GetTypes(this: &v23, type: "idEntityPtr", ops: &byte_8200D768, nodes: &v21);
  v7 = 0;
  if ( v21.num > 0 )
  {
    v8 = 0;
    do
    {
      v24 = &v21.list[v8];
      v9 = idStr::CStyleUnQuote(str: v21.list[v8]->value.data);
      idStr::operator=(this: &v22, text: v9);
      LODWORD(v11) = v22.len;
      if ( v22.len != 0 )
      {
        v12 = va::va(
                this: &v25,
                fmt: "%s_%s",
                a3: __SPAIR64__((unsigned int)baseName, (unsigned int)v22.data),
                a4: v11,
                a5: v10,
                a6: v15,
                a7: v16,
                a8: v17,
                a9: v18,
                a10: v19,
                a11: v20);
        list = v21.list;
        v14 = idStr::CStyleQuote(str: v12->buffer);
        idStr::operator=(this: &list[v8]->value, text: v14);
      }
      ++v7;
      ++v8;
    }
    while ( v7 < v21.num );
  }
  this->entityDef->SetEntityState_2(this: this->entityDef, a2: &v23, a3: true, a4: false);
  if ( v21.listStatic == 0 || v21.listStatic == 2 )
  {
    if ( v21.list != nullptr )
      idMem::Free(this: &mem, ptr: v21.list, align: ALIGN_16);
    v21.list = nullptr;
    v21.size = 0;
  }
  v21.num = 0;
  idTypeInfoTree::Clear(this: &v23);
  idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(this: &v23.nodeBlockAlloc);
  idStr::FreeData(this: &v22);
}


// ========================================================================
// __unwind$234833
// EA  : 0x827A1654
// RVA : 0x007A1654
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234833()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 96));
}


// ========================================================================
// __unwind$234834
// EA  : 0x827A167C
// RVA : 0x007A167C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234834()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 4336 + 128));
}


// ========================================================================
// __unwind$234835
// EA  : 0x827A16A4
// RVA : 0x007A16A4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234835()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4336 + 80));
}


// ========================================================================
// __unwind$234941
// EA  : 0x827A16CC
// RVA : 0x007A16CC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234941()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(v0 - 4336 + 132));
}


// ========================================================================
// ?ConvertMapModelNames@idMapFile@@AAAXXZ
// EA  : 0x827A1700
// RVA : 0x007A1700
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapFile::ConvertMapModelNames(idMapFile *this)
{
  int v2; // r26
  int v3; // r27
  idDeclEntityDef *entityDef; // r30
  int v5; // r29
  const char *v6; // r3
  idTypeInfoNode *Path; // r3
  idStr *p_type; // r29
  const char *v9; // r3
  __int64 v10; // r10
  int v11; // r7
  __int64 v12; // r6
  idStr *MapModelName; // r3
  const char *v14; // r3
  __int64 v15; // [sp+8h] [-E8h]
  idTypeInfoTree v16; // [sp+50h] [-A0h] BYREF
  idStr v17; // [sp+70h] [-80h] BYREF
  idStr v18[3]; // [sp+90h] [-60h] BYREF

  v2 = 0;
  if ( this->entities.num > 0 )
  {
    v3 = 0;
    do
    {
      entityDef = this->entities.list[v3]->entityDef;
      v5 = entityDef->GetEntityStateLength(this: entityDef);
      v6 = entityDef->GetEntityState(this: entityDef);
      idTypeInfoTree::idTypeInfoTree(this: &v16, text: v6, length: v5);
      Path = idTypeInfoTree::FindPath(this: &v16, startNode: v16.root, path: "renderModelInfo.model");
      p_type = &Path->type;
      if ( Path != nullptr )
      {
        v9 = idStr::CStyleUnQuote(str: Path->value.data);
        idStr::idStr(this: &v17, text: v9);
        if ( idStr::Icmp(s1: v17.data, s2: entityDef->name.str) == 0 )
        {
          HIDWORD(v12) = v17.data;
          MapModelName = idMapFile::GetMapModelName(result: v18, entityName: v12, a3: v11, a4: v10, a5: v15);
          v14 = idStr::CStyleQuote(str: MapModelName->data);
          idStr::operator=(this: p_type + 3, text: v14);
          idStr::FreeData(this: v18);
          entityDef->SetEntityState_2(this: entityDef, a2: &v16, a3: false, a4: false);
        }
        idStr::FreeData(this: &v17);
      }
      idTypeInfoTree::Clear(this: &v16);
      idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(this: &v16.nodeBlockAlloc);
      ++v2;
      ++v3;
    }
    while ( v2 < this->entities.num );
  }
}


// ========================================================================
// __unwind$234991
// EA  : 0x827A183C
// RVA : 0x007A183C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234991()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$234992
// EA  : 0x827A1864
// RVA : 0x007A1864
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234992()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$234993
// EA  : 0x827A188C
// RVA : 0x007A188C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_234993()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$235063
// EA  : 0x827A18B4
// RVA : 0x007A18B4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235063()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(v0 - 240 + 84));
}


// ========================================================================
// ?WriteInternal@idMapFile@@AAAXPAVidFile@@_NP6A_NPBV1@PAVidMapEntity@@PAVidGame@@@ZP6A_NPAVidMapPrimitive@@4@Z@Z
// EA  : 0x827A18E0
// RVA : 0x007A18E0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapFile::WriteInternal(
        idMapFile *this,
        idFile *fp,
        bool writeEntitiesFile,
        bool (__fastcall *ShouldWriteEntity)(const idMapFile *, idMapEntity *, idGame *),
        bool (__fastcall *ShouldWritePrimitive)(idMapPrimitive *, idGame *))
{
  int v10; // r29
  int v11; // r30

  fp->WriteFloatString(this: fp, a2: "Version %d\n", 3);
  v10 = 0;
  if ( this->entities.num > 0 )
  {
    v11 = 0;
    do
    {
      if ( ShouldWriteEntity(a1: this, a2: this->entities.list[v11], a3: this->game) )
        idMapEntity::Write(
          this: this->entities.list[v11],
          fp,
          game: this->game,
          entityNum: v10,
          ShouldWritePrimitive,
          isEntitiesFile: writeEntitiesFile);
      ++v10;
      ++v11;
    }
    while ( v10 < this->entities.num );
  }
  if ( !writeEntitiesFile )
    idMapEditorStates::Write(this: &this->groupStates, fp);
}


// ========================================================================
// ?WriteInternal@idMapFile@@AAA_NPBD_N1P6A_NPBV1@PAVidMapEntity@@PAVidGame@@@ZP6A_NPAVidMapPrimitive@@4@Z@Z
// EA  : 0x827A19B0
// RVA : 0x007A19B0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapFile::WriteInternal(
        idMapFile *this,
        const char *path,
        bool osPath,
        bool writeEntitiesFile,
        bool (__fastcall *ShouldWriteEntity)(const idMapFile *, idMapEntity *, idGame *),
        bool (__fastcall *ShouldWritePrimitive)(idMapPrimitive *, idGame *))
{
  idFile *v11; // r3
  idFile *v12; // r31

  idLib::Printf(fmt: "writing %s...\n", path);
  v11 = fileSystem->OpenFileWrite(this: fileSystem, a2: path, a3: 0);
  v12 = v11;
  if ( v11 != nullptr )
  {
    idMapFile::WriteInternal(this, fp: v11, writeEntitiesFile, ShouldWriteEntity, ShouldWritePrimitive);
    ((void (__fastcall *)(idFile *, int))v12->dtr_idFile)(a1: v12, a2: 1);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "Couldn't open %s", path);
    return 0;
  }
}


// ========================================================================
// ?Write@idMapFile@@QAA_NPBD_N@Z
// EA  : 0x827A1A68
// RVA : 0x007A1A68
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapFile::Write(idMapFile *this, const char *fileName, bool osPath)
{
  idStr *p_name; // r30
  idStr v8; // [sp+50h] [-160h] BYREF
  char v9[320]; // [sp+70h] [-140h] BYREF

  v8.len = 0;
  v8.allocedAndFlag = 20;
  v8.data = v8.baseBuffer;
  v8.baseBuffer[0] = 0;
  p_name = &this->name;
  if ( this->name.len == 0 )
  {
    fileSystem->OSPathToRelativePath(this: fileSystem, a2: fileName, a3: v9, a4: 256);
    idStr::operator=(this: p_name, text: v9);
    idStr::BackSlashesToSlashes(this: p_name);
    idStr::StripFileExtension(this: p_name);
  }
  idStr::operator=(this: &v8, text: fileName);
  idStr::DefaultFileExtension(this: &v8, extension: "map");
  if ( (unsigned __int8)idMapFile::WriteInternal(
                          this,
                          path: v8.data,
                          osPath,
                          writeEntitiesFile: false,
                          ShouldWriteEntity: (bool (__fastcall *)(const idMapFile *, idMapEntity *, idGame *))IsNotSoundEntity,
                          ShouldWritePrimitive: (bool (__fastcall *)(idMapPrimitive *, idGame *))IsNotSoundPrimitive) == 0 )
    goto LABEL_4;
  if ( this->fileTime == 0 )
    this->fileTime = fileSystem->GetTimestamp(this: fileSystem, a2: v8.data, a3: false);
  idStr::SetFileExtension(this: &v8, extension: "sound");
  if ( Sys_IsFileWritable(path: v8.data) )
  {
    if ( (unsigned __int8)idMapFile::WriteInternal(
                            this,
                            path: v8.data,
                            osPath,
                            writeEntitiesFile: false,
                            ShouldWriteEntity: (bool (__fastcall *)(const idMapFile *, idMapEntity *, idGame *))IsSoundEntity,
                            ShouldWritePrimitive: (bool (__fastcall *)(idMapPrimitive *, idGame *))IsSoundPrimitive) == 0 )
    {
LABEL_4:
      idStr::FreeData(this: &v8);
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "Skipping '%s'.  Sound file not checked out.", v8.data);
  }
  idStr::FreeData(this: &v8);
  return 1;
}


// ========================================================================
// __unwind$235292
// EA  : 0x827A1BFC
// RVA : 0x007A1BFC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235292()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 80));
}


// ========================================================================
// ?WriteSounds@idMapFile@@QAA_NPBD_N@Z
// EA  : 0x827A1C30
// RVA : 0x007A1C30
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapFile::WriteSounds(idMapFile *this, const char *fileName, bool osPath)
{
  idStr *p_name; // r30
  idStr v8; // [sp+50h] [-150h] BYREF
  char v9[304]; // [sp+70h] [-130h] BYREF

  v8.len = 0;
  v8.allocedAndFlag = 20;
  v8.data = v8.baseBuffer;
  v8.baseBuffer[0] = 0;
  p_name = &this->name;
  if ( this->name.len == 0 )
  {
    fileSystem->OSPathToRelativePath(this: fileSystem, a2: fileName, a3: v9, a4: 256);
    idStr::operator=(this: p_name, text: v9);
    idStr::BackSlashesToSlashes(this: p_name);
    idStr::StripFileExtension(this: p_name);
  }
  idStr::operator=(this: &v8, text: fileName);
  idStr::SetFileExtension(this: &v8, extension: "sound");
  if ( (unsigned __int8)idMapFile::WriteInternal(
                          this,
                          path: v8.data,
                          osPath,
                          writeEntitiesFile: false,
                          ShouldWriteEntity: (bool (__fastcall *)(const idMapFile *, idMapEntity *, idGame *))IsSoundEntity,
                          ShouldWritePrimitive: (bool (__fastcall *)(idMapPrimitive *, idGame *))IsSoundPrimitive) != 0 )
  {
    idStr::FreeData(this: &v8);
    return 1;
  }
  else
  {
    idStr::FreeData(this: &v8);
    return 0;
  }
}


// ========================================================================
// __unwind$235390
// EA  : 0x827A1D24
// RVA : 0x007A1D24
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235390()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 80));
}


// ========================================================================
// ?IsProductionEntity@@YA_NPBVidMapFile@@PAVidMapEntity@@PAVidGame@@@Z
// EA  : 0x827A1F58
// RVA : 0x007A1F58
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall IsProductionEntity(idMapFile *mapFile, idMapEntity *entity, idGame *game)
{
  char *data; // r4
  const idDecl *v7; // r3
  bool v8; // r30
  idDeclEntityDef *entityDef; // r15
  const char *v11; // r3
  int num; // r23
  encounterGroupRole_t *list; // r21
  int v14; // r28
  encounterGroupRole_t *v15; // r30
  encounterGroupRole_t v16; // r11
  int v17; // r3
  idGame_vtbl *v18; // r30
  idDeclEntityDef *v19; // r28
  idTypeInfoSettings *v20; // r3
  idEntity *v21; // r30
  const idTypeInfoTools *v22; // r28
  const char *v23; // r3
  int v24; // r30
  const char *v25; // r3
  __int64 v26; // r8
  __int64 v27; // r6
  __int64 v28; // r10
  va *v29; // r3
  int v30; // r17
  __int64 v31; // r10
  __int64 v32; // r8
  va *v33; // r3
  const char *v34; // r3
  __int64 v35; // r10
  __int64 v36; // r8
  va *v37; // r3
  const char *v38; // r3
  idMapEntity *v39; // r3
  idDeclEntityDef *v40; // r3
  const char *v41; // r3
  idGame_vtbl *v42; // r30
  idDeclEntityDef *v43; // r28
  idTypeInfoSettings *v44; // r3
  idEntity *v45; // r30
  const idTypeInfoTools *v46; // r28
  const char *v47; // r3
  int v48; // r30
  const char *v49; // r3
  int v50; // r28
  char v51; // r22
  int v52; // r27
  encounterGroupRole_t *v53; // r29
  encounterGroupRole_t v54; // r30
  int (__fastcall *v55)(int); // r9
  const char *v56; // r3
  int v57; // r3
  int v58; // r11
  const char *v59; // r3
  const classTypeInfo_t *i; // r28
  int v61; // r27
  encounterGroupRole_t *v62; // r29
  encounterGroupRole_t v63; // r30
  const char *name; // r4
  int v65; // r29
  const char *v66; // r3
  int v67; // r29
  const char *v68; // r3
  idTypeInfoTree *v69; // r3
  int v70; // r29
  const char *v71; // r3
  __int64 v72; // r10
  __int64 v73; // r8
  __int64 v74; // r6
  va *v75; // r3
  int v76; // [sp+8h] [-33B8h]
  int v77; // [sp+8h] [-33B8h]
  int v78; // [sp+Ch] [-33B4h]
  int v79; // [sp+Ch] [-33B4h]
  int v80; // [sp+10h] [-33B0h]
  int v81; // [sp+10h] [-33B0h]
  int v82; // [sp+14h] [-33ACh]
  int v83; // [sp+14h] [-33ACh]
  int v84; // [sp+18h] [-33A8h]
  int v85; // [sp+18h] [-33A8h]
  int v86; // [sp+1Ch] [-33A4h]
  int v87; // [sp+1Ch] [-33A4h]
  bool v88; // [sp+50h] [-3370h] BYREF
  bool v89; // [sp+51h] [-336Fh] BYREF
  int v90[3]; // [sp+54h] [-336Ch] BYREF
  idList<enum encounterGroupRole_t,5> v91; // [sp+60h] [-3360h] BYREF
  idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> > v92; // [sp+70h] [-3350h] BYREF
  idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> > v93; // [sp+74h] [-334Ch] BYREF
  idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> > v94; // [sp+78h] [-3348h] BYREF
  idTypeInfoTree v95; // [sp+80h] [-3340h] BYREF
  idStr v96; // [sp+A0h] [-3320h] BYREF
  idStr v97; // [sp+C0h] [-3300h] BYREF
  idStr v98; // [sp+E0h] [-32E0h] BYREF
  idStr v99; // [sp+100h] [-32C0h] BYREF
  idStr v100; // [sp+120h] [-32A0h] BYREF
  idStr v101; // [sp+140h] [-3280h] BYREF
  idTypeInfoTree v102; // [sp+160h] [-3260h] BYREF
  idTypeInfoTree v103; // [sp+180h] [-3240h] BYREF
  idStr v104; // [sp+1A0h] [-3220h] BYREF
  idStr v105; // [sp+1C0h] [-3200h] BYREF
  idTypeInfoTree v106; // [sp+1E0h] [-31E0h] BYREF
  idStr v107; // [sp+200h] [-31C0h] BYREF
  idStr v108; // [sp+220h] [-31A0h] BYREF
  idStr v109; // [sp+240h] [-3180h] BYREF
  idStr v110; // [sp+260h] [-3160h] BYREF
  idStr v111; // [sp+280h] [-3140h] BYREF
  idStr v112; // [sp+2A0h] [-3120h] BYREF
  idTypeInfoObject v113; // [sp+2C0h] [-3100h] BYREF
  idTypeInfoObject v114; // [sp+2F0h] [-30D0h] BYREF
  va v115; // [sp+320h] [-30A0h] BYREF
  va v116; // [sp+1320h] [-20A0h] BYREF
  va v117; // [sp+2320h] [-10A0h] BYREF

  memset(&v91, 0, 14);
  *(_WORD *)&v91.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v91);
  v90[0] = (int)idDeclInfo::FindWithInheritance(
                  this: &idDeclProductionFilter::resourceList,
                  name: "common",
                  makeDefault: false);
  if ( v90[0] != 0 )
    idList<idAnimWebBlendTree *,5>::Append(this: &v91, obj: (const encounterGroupRole_t *)v90);
  data = mapFile->name.data;
  if ( data != nullptr )
    v7 = idDeclInfo::FindWithInheritance(this: &idDeclProductionFilter::resourceList, name: data, makeDefault: false);
  else
    v7 = nullptr;
  v90[0] = (int)v7;
  if ( v7 != nullptr )
    idList<idAnimWebBlendTree *,5>::Append(this: &v91, obj: (const encounterGroupRole_t *)v90);
  idStr::idStr(this: &v112, text: "spawn_target_layer");
  v8 = idList<idStr,5>::FindIndex(this: &entity->layerList, obj: &v112, startIndex: 0) >= 0;
  idStr::FreeData(this: &v112);
  if ( v8 )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v91);
    return 0;
  }
  entityDef = entity->entityDef;
  v11 = entityDef->GetClass(this: entityDef);
  idStr::idStr(this: &v97, text: v11);
  num = v91.num;
  list = v91.list;
  v14 = 0;
  if ( v91.num > 0 )
  {
    v15 = v91.list;
    while ( 1 )
    {
      v16 = *v15;
      v90[0] = *v15 + 64;
      v94.__vftable = (idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> >_vtbl *)&idSearch_BinaryDefault<idStr>::`vftable';
      v17 = idSearch_Binary<idStr,idSearch_BinaryDefault<idStr>>::Search(
              this: &v94,
              base: *(const idStr **)(v16 + 64),
              num: *(_DWORD *)(v16 + 68),
              value: &v97);
      v94.__vftable = (idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> >_vtbl *)&idSearch<idStr>::`vftable';
      if ( v17 >= 0 )
        break;
      ++v14;
      ++v15;
      if ( v14 >= num )
        goto LABEL_14;
    }
    idStr::FreeData(this: &v97);
    if ( (v91.listStatic == 0 || v91.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    return 0;
  }
LABEL_14:
  if ( idStr::Icmp(s1: v97.data, s2: "idInfoTraversal") == 0 )
  {
    v18 = game->__vftable;
    v19 = entity->entityDef;
    v20 = idTypeInfoSettings::idTypeInfoSettings(
            this: (idTypeInfoSettings *)&v95,
            resolveEntityPointers: false,
            resolveModelPointers: false);
    v21 = v18->CreateEntityFromDef(this: game, a2: v19, a3: v20);
    if ( v21 == nullptr )
    {
LABEL_16:
      idStr::FreeData(this: &v97);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v91);
      return 0;
    }
    v22 = game->GetTypeInfoTools(this: game);
    v23 = entityDef->GetClass(this: entityDef);
    idTypeInfoObject::idTypeInfoObject(this: &v113, objectPtr: v21, objectType: v23, ti: v22);
    v89 = false;
    idTypeInfoObject::GetBool(this: &v113, variable: &TIV_idInfoTraversal_aasTraversal, b: &v89);
    game->DeleteEntity(this: game, a2: v21);
    if ( v89 )
    {
      idStr::FreeData(this: &v113.objectType);
      idStr::FreeData(this: &v97);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v91);
      return 0;
    }
    idStr::FreeData(this: &v113.objectType);
    idStr::FreeData(this: &v97);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v91);
    return 1;
  }
  if ( com_useExpandedEntityDefs.valueInteger != 0 && idStr::Icmp(s1: v97.data, s2: "idTarget_Spawn") == 0 )
  {
    v24 = entityDef->GetEntityStateLength(this: entityDef);
    v25 = entityDef->GetEntityState(this: entityDef);
    idTypeInfoTree::idTypeInfoTree(this: &v95, text: v25, length: v24);
    HIDWORD(v26) = "rmState::parmStack_t::parmBlockStack_t";
    LODWORD(v27) = &unk_82200000;
    HIDWORD(v27) = "num";
    v29 = va::va(
            this: &v115,
            fmt: "entityDefs.%s",
            a3: v27,
            a4: v26,
            a5: v28,
            a6: v76,
            a7: v78,
            a8: v80,
            a9: v82,
            a10: v84,
            a11: v86);
    idStr::idStr(this: &v111, text: v29);
    v90[0] = 0;
    if ( idTypeInfoTree::GetInt(this: &v95, path: v111.data, value: v90) )
    {
      v30 = 0;
      if ( v90[0] > 0 )
      {
        LODWORD(v31) = &unk_82200000;
        HIDWORD(v31) = &unk_82200000;
        LODWORD(v32) = &unk_82200000;
        HIDWORD(v32) = &unk_82200000;
        do
        {
          v33 = va::va(
                  this: &v116,
                  fmt: "entityDefs.%s[%i].text",
                  a3: __SPAIR64__("item", v30),
                  a4: v32,
                  a5: v31,
                  a6: v77,
                  a7: v79,
                  a8: v81,
                  a9: v83,
                  a10: v85,
                  a11: v87);
          idStr::idStr(this: &v105, text: v33);
          v99.allocedAndFlag = 20;
          v99.data = v99.baseBuffer;
          v99.len = 0;
          v99.baseBuffer[0] = 0;
          v96.allocedAndFlag = 20;
          v96.data = v96.baseBuffer;
          v96.len = 0;
          v96.baseBuffer[0] = 0;
          if ( idTypeInfoTree::GetStr(this: &v95, path: v105.data, value: &v96) )
          {
            if ( idStr::Find(searchIn: v96.data, searchFor: ".decl", casesensitive: false, start: 0, end: v96.len) <= -1 )
            {
              v34 = idStr::CStyleUnQuote(str: v96.data);
              idStr::operator=(this: &v96, text: v34);
              idStr::Replace(this: &v96, old: "'", nw: "\"");
              v37 = va::va(
                      this: &v117,
                      fmt: "entityDefs.%s[%i].name",
                      a3: __SPAIR64__("item", v30),
                      a4: v36,
                      a5: v35,
                      a6: v77,
                      a7: v79,
                      a8: v81,
                      a9: v83,
                      a10: v85,
                      a11: v87);
              idStr::idStr(this: &v107, text: v37);
              if ( idTypeInfoTree::GetStr(this: &v95, path: v107.data, value: &v99) )
              {
                v38 = idStr::CStyleUnQuote(str: v99.data);
                idStr::operator=(this: &v99, text: v38);
                v39 = idMapFile::FindEntity(this: mapFile, name: v99.data, index: nullptr);
                if ( v39 != nullptr )
                {
                  v40 = v39->entityDef;
                  if ( v40 != nullptr )
                    v40->GetTextWithInheritance(this: v40, a2: &v96, a3: true);
                }
                v98.allocedAndFlag = 20;
                v98.len = 0;
                v98.data = v98.baseBuffer;
                v98.baseBuffer[0] = 0;
                idStr::Format(this: &v98, fmt: "generated/%s/%s.decl", mapFile->name.data, v99.data);
                idLib::Printf(fmt: "   + writing entityDef '%s'...\n", v98.data);
                fileSystem->WriteFile(this: fileSystem, a2: v98.data, a3: v96.data, a4: v96.len, a5: FSPATH_BASE);
                v41 = idStr::CStyleQuote(str: v98.data);
                idStr::operator=(this: &v98, text: v41);
                if ( !idTypeInfoTree::SetStr(this: &v95, path: v105.data, value: v98.data) )
                  idLib::Warning(
                    fmt: "Could not set decl name %s for target/spawn '%s'!",
                    v98.data,
                    entityDef->name.str);
                entityDef->SetEntityState_2(this: entityDef, a2: &v95, a3: false, a4: false);
                idStr::FreeData(this: &v98);
              }
              else
              {
                idLib::Warning(fmt: "Missing target/spawn name data for '%s'!", entityDef->name.str);
              }
              idStr::FreeData(this: &v107);
            }
          }
          else
          {
            idLib::Warning(fmt: "Missing target/spawn entityDefs data for '%s'!", entityDef->name.str);
          }
          idStr::FreeData(this: &v96);
          idStr::FreeData(this: &v99);
          idStr::FreeData(this: &v105);
          ++v30;
        }
        while ( v30 < v90[0] );
      }
    }
    idStr::FreeData(this: &v111);
    idTypeInfoTree::~idTypeInfoTree(this: &v95);
    idStr::FreeData(this: &v97);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v91);
    return 1;
  }
  if ( idStr::Icmp(s1: v97.data, s2: "idLight") == 0 )
  {
    v42 = game->__vftable;
    v43 = entity->entityDef;
    v44 = idTypeInfoSettings::idTypeInfoSettings(
            this: (idTypeInfoSettings *)&v95,
            resolveEntityPointers: false,
            resolveModelPointers: false);
    v45 = v42->CreateEntityFromDef(this: game, a2: v43, a3: v44);
    if ( v45 == nullptr )
      goto LABEL_16;
    v46 = game->GetTypeInfoTools(this: game);
    v47 = entityDef->GetClass(this: entityDef);
    idTypeInfoObject::idTypeInfoObject(this: &v114, objectPtr: v45, objectType: v47, ti: v46);
    v100.allocedAndFlag = 20;
    v100.data = v100.baseBuffer;
    v100.len = 0;
    v100.baseBuffer[0] = 0;
    idTypeInfoObject::GetStr(this: &v114, variable: (const idTypeInfoVariable_idStr *)&TIV_idLight_lightClass, s: &v100);
    game->DeleteEntity(this: game, a2: v45);
    if ( idStr::Cmp(s1: v100.data, s2: "LIGHT_PRELIGHT_ONLY") == 0 )
    {
      idStr::FreeData(this: &v100);
      idStr::FreeData(this: &v114.objectType);
      idStr::FreeData(this: &v97);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v91);
      return 0;
    }
    if ( idStr::Cmp(s1: v100.data, s2: "LIGHT_BLENDED_ONLY") != 0 )
    {
      v48 = entityDef->GetEntityStateLength(this: entityDef);
      v49 = entityDef->GetEntityState(this: entityDef);
      idTypeInfoTree::idTypeInfoTree(this: &v95, text: v49, length: v48);
      v104.allocedAndFlag = 20;
      v104.data = v104.baseBuffer;
      v104.len = 0;
      v104.baseBuffer[0] = 0;
      if ( idTypeInfoTree::GetStrType(this: &v95, path: "lightMaterial", value: &v104) )
      {
        idTypeInfoTree::SetStrType(this: &v95, path: "lightMaterial", value: nullptr);
        entityDef->SetEntityState_2(this: entityDef, a2: &v95, a3: false, a4: false);
      }
      idStr::FreeData(this: &v104);
      idTypeInfoTree::~idTypeInfoTree(this: &v95);
    }
    idStr::FreeData(this: &v100);
    idStr::FreeData(this: &v114.objectType);
  }
  v50 = (int)entityDef->GetListedParent(this: entityDef);
  v51 = 0;
  if ( v50 != 0 )
  {
    while ( 1 )
    {
      v52 = 0;
      if ( num > 0 )
      {
        v53 = list;
        while ( 1 )
        {
          v54 = *v53;
          v55 = *(int (__fastcall **)(int))(*(_DWORD *)v50 + 76);
          v90[0] = *v53 + 80;
          v56 = (const char *)v55(a1: v50);
          idStr::idStr(this: &v109, text: v56);
          v93.__vftable = (idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> >_vtbl *)&idSearch_BinaryDefault<idStr>::`vftable';
          LOBYTE(v54) = idSearch_Binary<idStr,idSearch_BinaryDefault<idStr>>::Search(
                          this: &v93,
                          base: *(const idStr **)(v54 + 80),
                          num: *(_DWORD *)(v54 + 84),
                          value: &v109) >= 0;
          v93.__vftable = (idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> >_vtbl *)&idSearch<idStr>::`vftable';
          idStr::FreeData(this: &v109);
          if ( (_BYTE)v54 != ROLE_NONE )
            break;
          ++v52;
          ++v53;
          if ( v52 >= num )
            goto LABEL_60;
        }
        v51 = 1;
      }
LABEL_60:
      v57 = (*(int (__fastcall **)(int))(*(_DWORD *)v50 + 116))(a1: v50);
      v58 = *(_DWORD *)v50;
      if ( v50 == v57 )
        break;
      v50 = (*(int (__fastcall **)(int))(v58 + 116))(a1: v50);
      if ( v50 == 0 )
        goto LABEL_71;
    }
    v59 = (const char *)(*(int (__fastcall **)(int))(v58 + 76))(a1: v50);
    for ( i = idTypeInfoTools::FindClassInfo(this: typeInfoTools, typeName: v59);
          i != nullptr;
          i = idTypeInfoTools::FindClassInfo(this: typeInfoTools, typeName: i->superType) )
    {
      v61 = 0;
      if ( num > 0 )
      {
        v62 = list;
        while ( 1 )
        {
          v63 = *v62;
          name = i->name;
          v90[0] = *v62 + 80;
          idStr::idStr(this: &v110, text: name);
          v92.__vftable = (idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> >_vtbl *)&idSearch_BinaryDefault<idStr>::`vftable';
          LOBYTE(v63) = idSearch_Binary<idStr,idSearch_BinaryDefault<idStr>>::Search(
                          this: &v92,
                          base: *(const idStr **)(v63 + 80),
                          num: *(_DWORD *)(v63 + 84),
                          value: &v110) >= 0;
          v92.__vftable = (idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> >_vtbl *)&idSearch<idStr>::`vftable';
          idStr::FreeData(this: &v110);
          if ( (_BYTE)v63 != ROLE_NONE )
            break;
          ++v61;
          ++v62;
          if ( v61 >= num )
            goto LABEL_70;
        }
        v51 = 1;
      }
LABEL_70:
      ;
    }
  }
LABEL_71:
  if ( v51 != 0 )
  {
    v65 = entityDef->GetEntityStateLength(this: entityDef);
    v66 = entityDef->GetEntityState(this: entityDef);
    idTypeInfoTree::idTypeInfoTree(this: &v103, text: v66, length: v65);
    v101.allocedAndFlag = 20;
    v101.data = v101.baseBuffer;
    v101.len = 0;
    v101.baseBuffer[0] = 0;
    if ( idTypeInfoTree::GetStrType(this: &v103, path: "renderModelInfo.model", value: &v101) && v101.len != 0 )
    {
      idLib::Printf(fmt: "Removing model '%s' used by '%s'!\n", v101.data, entityDef->name.str);
      idTypeInfoTree::SetStrType(this: &v103, path: "renderModelInfo.model", value: nullptr);
      entityDef->SetEntityState_2(this: entityDef, a2: &v103, a3: false, a4: false);
    }
    idStr::FreeData(this: &v101);
    idTypeInfoTree::Clear(this: &v103);
    idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(this: &v103.nodeBlockAlloc);
  }
  if ( idStr::Icmp(s1: v97.data, s2: "idStaticEntity") != 0
    || (v67 = entityDef->GetEntityStateLength(this: entityDef),
        v68 = entityDef->GetEntityState(this: entityDef),
        v69 = idTypeInfoTree::idTypeInfoTree(this: &v106, text: v68, length: v67),
        LOBYTE(v67) = idTypeInfoTree::IsSkipped(this: v69, path: "clipModelInfo"),
        idTypeInfoTree::Clear(this: &v106),
        idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(this: &v106.nodeBlockAlloc),
        (_BYTE)v67 == 0) )
  {
    v70 = entityDef->GetEntityStateLength(this: entityDef);
    v71 = entityDef->GetEntityState(this: entityDef);
    idTypeInfoTree::idTypeInfoTree(this: &v102, text: v71, length: v70);
    v88 = false;
    if ( idTypeInfoTree::GetBool(this: &v102, path: "renderModelInfo.megatexturedModel", value: &v88) )
    {
      LODWORD(v72) = v88;
      if ( v88 )
      {
        LODWORD(v74) = entityDef->name.str;
        HIDWORD(v74) = mapFile->name.data;
        v75 = va::va(
                this: &v117,
                fmt: "%s/_combo/megamodel_%s.bmodel",
                a3: v74,
                a4: v73,
                a5: v72,
                a6: v76,
                a7: v78,
                a8: v80,
                a9: v82,
                a10: v84,
                a11: v86);
        idStr::idStr(this: &v108, text: v75);
        idTypeInfoTree::SetStrType(this: &v102, path: "renderModelInfo.model", value: v108.data);
        entityDef->SetEntityState_2(this: entityDef, a2: &v102, a3: false, a4: false);
        idStr::FreeData(this: &v108);
      }
    }
    idTypeInfoTree::Clear(this: &v102);
    idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(this: &v102.nodeBlockAlloc);
    idStr::FreeData(this: &v97);
    if ( (v91.listStatic == 0 || v91.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    return 1;
  }
  idStr::FreeData(this: &v97);
  if ( v91.listStatic != 0 && v91.listStatic != 2 || list == nullptr )
    return 0;
  idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  return 0;
}


// ========================================================================
// __unwind$235917
// EA  : 0x827A2C8C
// RVA : 0x007A2C8C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235917()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13248 + 96));
}


// ========================================================================
// __unwind$235918
// EA  : 0x827A2CB4
// RVA : 0x007A2CB4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235918()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 672));
}


// ========================================================================
// __unwind$235919
// EA  : 0x827A2CDC
// RVA : 0x007A2CDC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235919()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 192));
}


// ========================================================================
// __unwind$235920
// EA  : 0x827A2D04
// RVA : 0x007A2D04
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235920()
{
  int v0; // r12

  idSearch_BinaryDefault<idStr>::~idSearch_BinaryDefault<idStr>(this: (idSearch_BinaryDefault<idStr> *)(v0 - 13248 + 120));
}


// ========================================================================
// __unwind$235921
// EA  : 0x827A2D2C
// RVA : 0x007A2D2C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235921()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 13248 + 704));
}


// ========================================================================
// __unwind$235922
// EA  : 0x827A2D54
// RVA : 0x007A2D54
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235922()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 13248 + 128));
}


// ========================================================================
// __unwind$235923
// EA  : 0x827A2D7C
// RVA : 0x007A2D7C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235923()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 640));
}


// ========================================================================
// __unwind$235924
// EA  : 0x827A2DA4
// RVA : 0x007A2DA4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235924()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 448));
}


// ========================================================================
// __unwind$235925
// EA  : 0x827A2DCC
// RVA : 0x007A2DCC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235925()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 256));
}


// ========================================================================
// __unwind$235926
// EA  : 0x827A2DF4
// RVA : 0x007A2DF4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235926()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 160));
}


// ========================================================================
// __unwind$235927
// EA  : 0x827A2E1C
// RVA : 0x007A2E1C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235927()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 512));
}


// ========================================================================
// __unwind$235928
// EA  : 0x827A2E44
// RVA : 0x007A2E44
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235928()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 224));
}


// ========================================================================
// __unwind$235929
// EA  : 0x827A2E6C
// RVA : 0x007A2E6C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235929()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 13248 + 752));
}


// ========================================================================
// __unwind$235930
// EA  : 0x827A2E94
// RVA : 0x007A2E94
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235930()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 288));
}


// ========================================================================
// __unwind$235931
// EA  : 0x827A2EBC
// RVA : 0x007A2EBC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235931()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 13248 + 128));
}


// ========================================================================
// __unwind$235932
// EA  : 0x827A2EE4
// RVA : 0x007A2EE4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235932()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 416));
}


// ========================================================================
// __unwind$235933
// EA  : 0x827A2F0C
// RVA : 0x007A2F0C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235933()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 576));
}


// ========================================================================
// __unwind$235934
// EA  : 0x827A2F34
// RVA : 0x007A2F34
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235934()
{
  int v0; // r12

  idSearch_BinaryDefault<idStr>::~idSearch_BinaryDefault<idStr>(this: (idSearch_BinaryDefault<idStr> *)(v0 - 13248 + 116));
}


// ========================================================================
// __unwind$235935
// EA  : 0x827A2F5C
// RVA : 0x007A2F5C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235935()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 608));
}


// ========================================================================
// __unwind$235936_0
// EA  : 0x827A2F84
// RVA : 0x007A2F84
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235936_0()
{
  int v0; // r12

  idSearch_BinaryDefault<idStr>::~idSearch_BinaryDefault<idStr>(this: (idSearch_BinaryDefault<idStr> *)(v0 - 13248 + 112));
}


// ========================================================================
// __unwind$235937_0
// EA  : 0x827A2FAC
// RVA : 0x007A2FAC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235937_0()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 13248 + 384));
}


// ========================================================================
// __unwind$235938_0
// EA  : 0x827A2FD4
// RVA : 0x007A2FD4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235938_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 320));
}


// ========================================================================
// __unwind$236672
// EA  : 0x827A2FFC
// RVA : 0x007A2FFC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_236672()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(v0 - 13248 + 388));
}


// ========================================================================
// __unwind$235939_0
// EA  : 0x827A3028
// RVA : 0x007A3028
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235939_0()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 13248 + 480));
}


// ========================================================================
// __unwind$236684
// EA  : 0x827A3050
// RVA : 0x007A3050
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_236684()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(v0 - 13248 + 484));
}


// ========================================================================
// __unwind$235940_0
// EA  : 0x827A307C
// RVA : 0x007A307C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235940_0()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 13248 + 352));
}


// ========================================================================
// __unwind$235941_0
// EA  : 0x827A30A4
// RVA : 0x007A30A4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_235941_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 13248 + 544));
}


// ========================================================================
// __unwind$236768
// EA  : 0x827A30CC
// RVA : 0x007A30CC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_236768()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(v0 - 13248 + 356));
}


// ========================================================================
// ?ParseGroups@idMapGroups@@SAXAAVidLexer@@AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x827A3100
// RVA : 0x007A3100
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapGroups::ParseGroups(idLexer *src, idList<idStr,5> *groups)
{
  idToken v4; // [sp+50h] [-70h] BYREF

  if ( idLexer::CheckTokenString(this: src, string: "groups") )
  {
    idLexer::ExpectTokenString(this: src, string: "{");
    v4.len = 0;
    v4.allocedAndFlag = 20;
    v4.data = v4.baseBuffer;
    v4.floatvalue = -3.4028235e38;
    v4.baseBuffer[0] = 0;
    v4.intvalue = 0;
    memset(&v4.whiteSpaceStart_p, 0, 12);
    while ( idLexer::ReadToken(this: src, token: &v4) )
    {
      if ( idStr::Cmp(s1: v4.data, s2: "}") == 0 )
        break;
      if ( v4.type == 1 && idList<idStr,5>::FindIndex(this: groups, obj: &v4, startIndex: 0) < 0 )
        idList<idStr,5>::Append(this: groups, obj: &v4);
    }
    idStr::FreeData(this: &v4);
  }
}


// ========================================================================
// __unwind$237035
// EA  : 0x827A3204
// RVA : 0x007A3204
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237035()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?WriteEntities@idMapFile@@QAA_NPBD_N@Z
// EA  : 0x827A3238
// RVA : 0x007A3238
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapFile::WriteEntities(idMapFile *this, const char *fileName, bool osPath)
{
  idStr *p_name; // r30
  char *data; // r4
  unsigned int fileTime; // r11
  idStr v10; // [sp+50h] [-160h] BYREF
  char v11[320]; // [sp+70h] [-140h] BYREF

  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  p_name = &this->name;
  if ( this->name.len == 0 )
  {
    fileSystem->OSPathToRelativePath(this: fileSystem, a2: fileName, a3: v11, a4: 256);
    idStr::operator=(this: p_name, text: v11);
    idStr::BackSlashesToSlashes(this: p_name);
    idStr::StripFileExtension(this: p_name);
  }
  idStr::operator=(this: &v10, text: fileName);
  idStr::DefaultFileExtension(this: &v10, extension: "entities");
  data = v10.data;
  this->ignoreGroupInfo = true;
  if ( (unsigned __int8)idMapFile::WriteInternal(
                          this,
                          path: data,
                          osPath,
                          writeEntitiesFile: true,
                          ShouldWriteEntity: (bool (__fastcall *)(const idMapFile *, idMapEntity *, idGame *))IsProductionEntity,
                          ShouldWritePrimitive: (bool (__fastcall *)(idMapPrimitive *, idGame *))idLobbyBackend360::StartArbitration) != 0 )
  {
    fileTime = this->fileTime;
    this->ignoreGroupInfo = false;
    if ( fileTime == 0 )
      this->fileTime = fileSystem->GetTimestamp(this: fileSystem, a2: v10.data, a3: false);
    idStr::FreeData(this: &v10);
    return 1;
  }
  else
  {
    idStr::FreeData(this: &v10);
    return 0;
  }
}


// ========================================================================
// __unwind$237127
// EA  : 0x827A3364
// RVA : 0x007A3364
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237127()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 80));
}


// ========================================================================
// ?AddEntity@idMapFile@@QAAHPAVidMapEntity@@@Z
// EA  : 0x827A3390
// RVA : 0x007A3390
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapFile::AddEntity(
        idMapFile *this,
        idMapEntity *mapEnt,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idMapEntity *a14)
{
  a14 = mapEnt;
  return idList<idAnimWebBlendTree *,5>::Append(
           this: (idList<enum encounterGroupRole_t,5> *)&this->entities,
           obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?CopyMapEntities@idMapFile@@QAA?AVidStr@@PBV1@PBD@Z
// EA  : 0x827A33C8
// RVA : 0x007A33C8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapFile *__fastcall idMapFile::CopyMapEntities(
        idMapFile *this,
        idStr *result,
        const idMapFile *map,
        const char *refId)
{
  int v8; // r26
  int v9; // r27
  idMapEntity *v10; // r29
  idMapGroups *v11; // r21
  size_t v12; // r30
  idMapGroups *v13; // r3
  idMapEntity *v15; // [sp+54h] [-ECh] BYREF
  idStr v16; // [sp+60h] [-E0h] BYREF
  idStr v17; // [sp+80h] [-C0h] BYREF
  idMapGroups v18; // [sp+A0h] [-A0h] BYREF
  idMapGroups v19[6]; // [sp+C0h] [-80h] BYREF

  v16.allocedAndFlag = 20;
  v16.len = 0;
  v16.data = v16.baseBuffer;
  v16.baseBuffer[0] = 0;
  if ( map != nullptr )
  {
    v8 = 0;
    if ( map->entities.num <= 0 )
    {
LABEL_17:
      result[4].baseBuffer[8] = 1;
      idStr::idStr((idStr *)this, text: &v16);
      goto LABEL_18;
    }
    v9 = 0;
    while ( 1 )
    {
      v10 = map->entities.list[v9];
      if ( v10 != nullptr )
      {
        if ( refId == nullptr )
          goto LABEL_12;
        idStr::idStr(this: &v17, text: v10->refId.data);
        if ( *refId != 0 )
        {
          if ( idStr::Icmp(s1: v17.data, s2: refId) == 0 )
          {
_M237321:
            idStr::FreeData(this: &v17);
LABEL_12:
            if ( v16.len != 0 )
            {
              idMapGroups::RemoveLeadingReferencePaths(this: v19, result: (idStr *)v10);
              v13 = v19;
            }
            else
            {
              v11 = idMapGroups::RemoveLeadingReferencePaths(this: &v18, result: (idStr *)v10);
              v12 = (size_t)v11->__vftable;
              idStr::EnsureAlloced(
                this: &v16,
                amount: (int)&v11->dtr_idMapGroups + 1,
                keepold: false,
                geometricGrowth: false);
              memcpy(Dst: v16.data, Src: v11->groupList.list, Size: v12);
              v16.data[v12] = 0;
              v16.len = v12;
              v13 = &v18;
            }
            idStr::FreeData(this: (idStr *)v13);
            v15 = v10;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&result[1].baseBuffer[8],
              obj: (const encounterGroupRole_t *)&v15);
            goto LABEL_16;
          }
        }
        else if ( v17.len == 0 )
        {
          goto _M237321;
        }
        idStr::FreeData(this: &v17);
      }
LABEL_16:
      ++v8;
      ++v9;
      if ( v8 >= map->entities.num )
        goto LABEL_17;
    }
  }
  idStr::idStr((idStr *)this, text: &v16);
LABEL_18:
  idStr::FreeData(this: &v16);
  return this;
}


// ========================================================================
// __unwind$237204
// EA  : 0x827A3564
// RVA : 0x007A3564
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237204()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$237205
// EA  : 0x827A358C
// RVA : 0x007A358C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237205()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 320;
  if ( (*(_DWORD *)(v0 - 320 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 340));
  }
}


// ========================================================================
// __unwind$237208
// EA  : 0x827A35D0
// RVA : 0x007A35D0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237208()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$237209
// EA  : 0x827A35F8
// RVA : 0x007A35F8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237209()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// ??0idMapBrush@@QAA@XZ
// EA  : 0x827A39A0
// RVA : 0x007A39A0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapBrush *__fastcall idMapBrush::idMapBrush(idMapBrush *this)
{
  idList<idSpawnArea::GeneratedPosition *,5> *p_sides; // r28

  this->groupList.granularity = 0;
  this->groupList.memTag = 5;
  this->groupList.listStatic = 0;
  this->groupList.list = nullptr;
  this->groupList.size = 0;
  this->groupList.num = 0;
  this->type = -1;
  p_sides = (idList<idSpawnArea::GeneratedPosition *,5> *)&this->sides;
  this->__vftable = (idMapBrush_vtbl *)&idMapBrush::`vftable';
  this->sides.list = nullptr;
  this->sides.granularity = 0;
  this->sides.memTag = 5;
  this->sides.listStatic = 0;
  this->sides.size = 0;
  this->sides.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sides);
  this->type = 0;
  if ( this->sides.size < 8 )
    idList<idNavSpline *,5>::Resize(this: p_sides, newsize: 8);
  return this;
}


// ========================================================================
// __unwind$237609
// EA  : 0x827A3A48
// RVA : 0x007A3A48
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237609()
{
  int v0; // r12

  idMapPrimitive::~idMapPrimitive(this: *(idMapPrimitive **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$237610
// EA  : 0x827A3A70
// RVA : 0x007A3A70
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237610()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}


// ========================================================================
// ??1idMapBrush@@UAA@XZ
// EA  : 0x827A3AA8
// RVA : 0x007A3AA8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapBrush::~idMapBrush(idMapBrush *this)
{
  idList<idVehicleState *,5> *p_sides; // r29

  this->__vftable = (idMapBrush_vtbl *)&idMapBrush::`vftable';
  p_sides = (idList<idVehicleState *,5> *)&this->sides;
  idList<idVarDefName *,58>::DeleteContents(this: &this->sides);
  idList<idThread *,58>::Clear(this: p_sides);
  this->__vftable = (idMapBrush_vtbl *)&idMapPrimitive::`vftable';
  idMapGroups::~idMapGroups(this);
}


// ========================================================================
// __unwind$237683
// EA  : 0x827A3AFC
// RVA : 0x007A3AFC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237683()
{
  int v0; // r12

  idMapPrimitive::~idMapPrimitive(this: *(idMapPrimitive **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$237684
// EA  : 0x827A3B24
// RVA : 0x007A3B24
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237684()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// ?Parse@idMapBrush@@SAPAV1@AAVidLexer@@ABVidVec3@@_NH@Z
// EA  : 0x827A3B58
// RVA : 0x007A3B58
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapBrush *__fastcall idMapBrush::Parse(idLexer *src, const idVec3 *origin, bool newFormat, int version)
{
  idMapBrush *v4; // r28
  int len; // r30
  char *v10; // r10
  char *v11; // r9
  char v12; // r11
  _DWORD *v13; // r3
  encounterGroupRole_t v14; // r30
  double v15; // fp5
  double v16; // fp1
  double v17; // fp7
  double v18; // fp3
  double v19; // fp10
  double v20; // fp6
  double v21; // fp2
  double v22; // fp0
  idStr *v23; // r17
  size_t v24; // r29
  size_t v25; // r29
  idMapBrush *v26; // r3
  int num; // r30
  encounterGroupRole_t *v28; // r29
  encounterGroupRole_t v30[4]; // [sp+50h] [-170h] BYREF
  idList<enum encounterGroupRole_t,5> v31; // [sp+60h] [-160h] BYREF
  idVec3 v32; // [sp+70h] [-150h] BYREF
  idVec3 v33; // [sp+7Ch] [-144h] BYREF
  idVec3 v34[2]; // [sp+88h] [-138h] BYREF
  idToken v35; // [sp+A0h] [-120h] BYREF
  idStr v36; // [sp+F0h] [-D0h] BYREF
  idStr v37; // [sp+110h] [-B0h] BYREF

  v4 = nullptr;
  v35.len = 0;
  v35.allocedAndFlag = 20;
  v35.floatvalue = -3.4028235e38;
  v35.data = v35.baseBuffer;
  v35.baseBuffer[0] = 0;
  v35.intvalue = 0;
  memset(&v35.whiteSpaceStart_p, 0, 12);
  memset(&v31, 0, 14);
  *(_WORD *)&v31.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
LABEL_52:
    idStr::FreeData(this: &v35);
    return nullptr;
  }
  if ( !idLexer::ReadToken(this: src, token: &v35) )
  {
LABEL_34:
    idLexer::Error(this: src, str: "idMapBrush::Parse: unexpected EOF");
    idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v31);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
    goto LABEL_52;
  }
  while ( idStr::Cmp(s1: v35.data, s2: "}") != 0 )
  {
    if ( idStr::Cmp(s1: v35.data, s2: "(") != 0 )
    {
      while ( 1 )
      {
        if ( v35.type != 1 )
        {
          idLexer::Error(this: src, str: "idMapBrush::Parse: unexpected %s, expected ( or epair key string", v35.data);
          idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v31);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
          goto LABEL_52;
        }
        v36.allocedAndFlag = 20;
        v36.data = v36.baseBuffer;
        v36.len = 0;
        len = v35.len;
        v36.baseBuffer[0] = 0;
        if ( v35.len + 1 > 20 )
          idStr::ReAllocate(this: &v36, amount: v35.len + 1, keepold: true);
        v10 = v35.data - 1;
        v11 = v36.data - 1;
        do
        {
          v12 = *++v10;
          *++v11 = *v10;
        }
        while ( v12 != 0 );
        v36.len = len;
        if ( !idLexer::ReadTokenOnLine(this: src, token: &v35) || v35.type != 1 )
          break;
        if ( !idLexer::ReadToken(this: src, token: &v35) )
        {
          idLexer::Error(this: src, str: "idMapBrush::Parse: unexpected EOF");
          idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v31);
          idStr::FreeData(this: &v36);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
          goto LABEL_52;
        }
        idStr::FreeData(this: &v36);
        if ( idStr::Cmp(s1: v35.data, s2: "(") == 0 )
          goto LABEL_15;
      }
      idLexer::Error(this: src, str: "idMapBrush::Parse: expected epair value string not found");
      idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v31);
      idStr::FreeData(this: &v36);
      if ( (v31.listStatic == 0 || v31.listStatic == 2) && v31.list != nullptr )
        idMem::Free(this: &mem, ptr: v31.list, align: ALIGN_16);
      goto LABEL_52;
    }
LABEL_15:
    idLexer::UnreadToken(this: src);
    v13 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
            size: 0x54u,
            tag: TAG_NEW,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    if ( v13 != nullptr )
    {
      v13[2] = 20;
      *v13 = 0;
      v13[1] = v13 + 3;
      *((_BYTE *)v13 + 12) = 0;
      *((float *)v13 + 11) = 0.0;
      *((float *)v13 + 10) = 0.0;
      *((float *)v13 + 9) = 0.0;
      *((float *)v13 + 8) = 0.0;
      *((float *)v13 + 14) = 0.0;
      v30[0] = (encounterGroupRole_t)(v13 + 18);
      *((float *)v13 + 13) = 0.0;
      v14 = (encounterGroupRole_t)v13;
      *((float *)v13 + 12) = 0.0;
      *((float *)v13 + 17) = 0.0;
      *((float *)v13 + 16) = 0.0;
      *((float *)v13 + 15) = 0.0;
      *((float *)v13 + 20) = 0.0;
      *((float *)v13 + 19) = 0.0;
      *((float *)v13 + 18) = 0.0;
    }
    else
    {
      v14 = ROLE_NONE;
    }
    v30[0] = v14;
    idList<idAnimWebBlendTree *,5>::Append(this: &v31, obj: v30);
    if ( newFormat )
    {
      if ( !idLexer::Parse1DMatrix(this: src, x: 4, m: (float *)(v14 + 32), expectCommas: false) )
        goto LABEL_20;
    }
    else
    {
      if ( !idLexer::Parse1DMatrix(this: src, x: 3, m: &v32.x, expectCommas: false)
        || !idLexer::Parse1DMatrix(this: src, x: 3, m: &v33.x, expectCommas: false)
        || !idLexer::Parse1DMatrix(this: src, x: 3, m: &v34[0].x, expectCommas: false) )
      {
LABEL_20:
        idLexer::Error(this: src, str: "idMapBrush::Parse: unable to read brush side plane definition");
        idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v31);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
        goto LABEL_52;
      }
      v15 = (float)(v32.z - origin->z);
      v16 = (float)(v33.y - origin->y);
      v17 = (float)(v32.y - origin->y);
      v18 = (float)(v33.x - origin->x);
      v19 = (float)(v33.z - origin->z);
      v20 = (float)(v34[0].x - origin->x);
      v21 = (float)(v34[0].y - origin->y);
      v22 = (float)(v34[0].z - origin->z);
      v32.x = v32.x - origin->x;
      v32.y = v17;
      v32.z = v15;
      v33.x = v18;
      v33.y = v16;
      v33.z = v19;
      v34[0].x = v20;
      v34[0].y = v21;
      v34[0].z = v22;
      idPlane::FromPoints(this: (idPlane *)(v14 + 32), p1: &v32, p2: &v33, p3: v34, fixDegenerate: true);
    }
    if ( !idLexer::Parse2DMatrix(this: src, y: 2, x: 3, m: (float *)(v14 + 48)) )
    {
      idLexer::Error(this: src, str: "idMapBrush::Parse: unable to read brush side texture matrix");
      idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v31);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
      goto LABEL_52;
    }
    *(float *)(v14 + 72) = origin->x;
    *(float *)(v14 + 76) = origin->y;
    v30[0] = v14 + 72;
    *(float *)(v14 + 80) = origin->z;
    if ( !idLexer::ReadTokenOnLine(this: src, token: &v35) )
    {
      idLexer::Error(this: src, str: "idMapBrush::Parse: unable to read brush side material");
      idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v31);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
      goto LABEL_52;
    }
    if ( version >= 2 )
    {
      v25 = v35.len;
      idStr::EnsureAlloced(this: (idStr *)v14, amount: v35.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: *(void **)(v14 + 4), Src: v35.data, Size: v25);
      *(_BYTE *)(*(_DWORD *)(v14 + 4) + v25) = 0;
      *(_DWORD *)v14 = v25;
    }
    else
    {
      v23 = operator+(result: &v37, a: "textures/", b: &v35);
      v24 = v23->len;
      idStr::EnsureAlloced(this: (idStr *)v14, amount: v23->len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: *(void **)(v14 + 4), Src: v23->data, Size: v24);
      *(_BYTE *)(*(_DWORD *)(v14 + 4) + v24) = 0;
      *(_DWORD *)v14 = v24;
      idStr::FreeData(this: &v37);
    }
    if ( idLexer::ReadTokenOnLine(this: src, token: &v35) && idLexer::ReadTokenOnLine(this: src, token: &v35) )
      idLexer::ReadTokenOnLine(this: src, token: &v35);
    if ( !idLexer::ReadToken(this: src, token: &v35) )
      goto LABEL_34;
  }
  if ( !idLexer::ExpectTokenString(this: src, string: "}") )
  {
    idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v31);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
    goto LABEL_52;
  }
  v26 = (idMapBrush *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x28u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v30[0] = (encounterGroupRole_t)v26;
  if ( v26 != nullptr )
    v4 = idMapBrush::idMapBrush(this: v26);
  num = v31.num;
  if ( v31.num > 0 )
  {
    v28 = v31.list - 1;
    do
    {
      v30[0] = *++v28;
      idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v4->sides, obj: v30);
      --num;
    }
    while ( num != 0 );
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
  idStr::FreeData(this: &v35);
  return v4;
}


// ========================================================================
// __unwind$237734
// EA  : 0x827A4250
// RVA : 0x007A4250
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237734()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 160));
}


// ========================================================================
// __unwind$237735
// EA  : 0x827A4278
// RVA : 0x007A4278
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237735()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 96));
}


// ========================================================================
// __unwind$237736
// EA  : 0x827A42A0
// RVA : 0x007A42A0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237736()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 240));
}


// ========================================================================
// __unwind$237738
// EA  : 0x827A42C8
// RVA : 0x007A42C8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_237738()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 272));
}


// ========================================================================
// __unwind$237739
// EA  : 0x827A42F0
// RVA : 0x007A42F0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall _unwind_237739(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 448 + 80), tag: a2);
}


// ========================================================================
// ?ParseQ3@idMapBrush@@SAPAV1@AAVidLexer@@ABVidVec3@@@Z
// EA  : 0x827A4320
// RVA : 0x007A4320
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapBrush *__fastcall idMapBrush::ParseQ3(idLexer *src, const idVec3 *origin)
{
  idMapBrush *v2; // r29
  _DWORD *v5; // r3
  encounterGroupRole_t v6; // r30
  double v7; // fp7
  double v8; // fp5
  double v9; // fp3
  double v10; // fp1
  double v11; // fp11
  double v12; // fp8
  double v13; // fp4
  double v14; // fp2
  idStr *v15; // r26
  int v16; // r11
  size_t len; // r27
  int v18; // r4
  double y; // fp13
  idMapBrush *v20; // r3
  int num; // r30
  encounterGroupRole_t *list; // r26
  encounterGroupRole_t *v23; // r28
  encounterGroupRole_t v25[4]; // [sp+50h] [-150h] BYREF
  idList<enum encounterGroupRole_t,5> v26; // [sp+60h] [-140h] BYREF
  idVec3 v27; // [sp+70h] [-130h] BYREF
  idVec3 v28; // [sp+7Ch] [-124h] BYREF
  idVec3 v29[2]; // [sp+88h] [-118h] BYREF
  idToken v30; // [sp+A0h] [-100h] BYREF
  idStr v31; // [sp+F0h] [-B0h] BYREF

  v2 = nullptr;
  v30.len = 0;
  v30.allocedAndFlag = 20;
  v30.floatvalue = -3.4028235e38;
  v30.data = v30.baseBuffer;
  v30.baseBuffer[0] = 0;
  v30.intvalue = 0;
  memset(&v30.whiteSpaceStart_p, 0, 12);
  memset(&v26, 0, 14);
  *(_WORD *)&v26.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v26);
  if ( idLexer::CheckTokenString(this: src, string: "}") )
  {
LABEL_19:
    v20 = (idMapBrush *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x28u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v25[0] = (encounterGroupRole_t)v20;
    if ( v20 != nullptr )
      v2 = idMapBrush::idMapBrush(this: v20);
    num = v26.num;
    list = v26.list;
    if ( v26.num > 0 )
    {
      v23 = v26.list - 1;
      do
      {
        v25[0] = *++v23;
        idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v2->sides, obj: v25);
        --num;
      }
      while ( num != 0 );
    }
    if ( (v26.listStatic == 0 || v26.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    idStr::FreeData(this: &v30);
    return v2;
  }
  else
  {
    while ( 1 )
    {
      v5 = idMem::AllocWithLocation(
             this: &mem,
             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
             size: 0x54u,
             tag: TAG_NEW,
             zeroBuffer: false,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
      if ( v5 != nullptr )
      {
        v5[2] = 20;
        *v5 = 0;
        v5[1] = v5 + 3;
        *((_BYTE *)v5 + 12) = 0;
        *((float *)v5 + 11) = 0.0;
        *((float *)v5 + 10) = 0.0;
        *((float *)v5 + 9) = 0.0;
        *((float *)v5 + 8) = 0.0;
        *((float *)v5 + 14) = 0.0;
        v25[0] = (encounterGroupRole_t)(v5 + 18);
        *((float *)v5 + 13) = 0.0;
        v6 = (encounterGroupRole_t)v5;
        *((float *)v5 + 12) = 0.0;
        *((float *)v5 + 17) = 0.0;
        *((float *)v5 + 16) = 0.0;
        *((float *)v5 + 15) = 0.0;
        *((float *)v5 + 20) = 0.0;
        *((float *)v5 + 19) = 0.0;
        *((float *)v5 + 18) = 0.0;
      }
      else
      {
        v6 = ROLE_NONE;
      }
      v25[0] = v6;
      idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: v25);
      if ( !idLexer::Parse1DMatrix(this: src, x: 3, m: &v27.x, expectCommas: false)
        || !idLexer::Parse1DMatrix(this: src, x: 3, m: &v28.x, expectCommas: false)
        || !idLexer::Parse1DMatrix(this: src, x: 3, m: &v29[0].x, expectCommas: false) )
      {
        break;
      }
      v7 = (float)(v28.x - origin->x);
      v8 = (float)(v29[0].x - origin->x);
      v9 = (float)(v27.y - origin->y);
      v10 = (float)(v27.z - origin->z);
      v11 = (float)(v28.y - origin->y);
      v12 = (float)(v28.z - origin->z);
      v13 = (float)(v29[0].y - origin->y);
      v14 = (float)(v29[0].z - origin->z);
      v27.x = v27.x - origin->x;
      v28.x = v7;
      v29[0].x = v8;
      v27.y = v9;
      v27.z = v10;
      v28.y = v11;
      v28.z = v12;
      v29[0].y = v13;
      v29[0].z = v14;
      idPlane::FromPoints(this: (idPlane *)(v6 + 32), p1: &v27, p2: &v28, p3: v29, fixDegenerate: true);
      if ( !idLexer::ReadTokenOnLine(this: src, token: &v30) )
      {
        idLexer::Error(this: src, str: "idMapBrush::ParseQ3: unable to read brush side material");
        idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v26);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v26);
        goto LABEL_31;
      }
      v15 = operator+(result: &v31, a: "textures/", b: &v30);
      v16 = *(_DWORD *)(v6 + 8);
      len = v15->len;
      v18 = v15->len + 1;
      if ( v16 >= 0 )
      {
        if ( v18 > (v16 & 0x7FFFFFFF) )
          idStr::ReAllocate(this: (idStr *)v6, amount: v18, keepold: false);
      }
      else if ( v18 > (v16 & 0x7FFFFFFF)
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      memcpy(Dst: *(void **)(v6 + 4), Src: v15->data, Size: len);
      *(_BYTE *)(len + *(_DWORD *)(v6 + 4)) = 0;
      *(_DWORD *)v6 = len;
      idStr::FreeData(this: &v31);
      idLexer::ParseInt(this: src);
      idLexer::ParseInt(this: src);
      idLexer::ParseInt(this: src);
      idLexer::ParseFloat(this: src, errorFlag: nullptr);
      idLexer::ParseFloat(this: src, errorFlag: nullptr);
      *(float *)(v6 + 48) = 0.03125;
      *(float *)(v6 + 52) = 0.0;
      *(float *)(v6 + 56) = 0.0;
      *(float *)(v6 + 60) = 0.0;
      *(float *)(v6 + 64) = 0.03125;
      v25[0] = v6 + 48;
      *(float *)(v6 + 68) = 0.0;
      *(float *)(v6 + 72) = origin->x;
      v25[0] = v6 + 60;
      y = origin->y;
      v25[0] = v6 + 72;
      *(float *)(v6 + 76) = y;
      *(float *)(v6 + 80) = origin->z;
      if ( idLexer::ReadTokenOnLine(this: src, token: &v30) && idLexer::ReadTokenOnLine(this: src, token: &v30) )
        idLexer::ReadTokenOnLine(this: src, token: &v30);
      if ( idLexer::CheckTokenString(this: src, string: "}") )
        goto LABEL_19;
    }
    idLexer::Error(this: src, str: "idMapBrush::ParseQ3: unable to read brush side plane definition");
    idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v26);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v26);
LABEL_31:
    idStr::FreeData(this: &v30);
    return nullptr;
  }
}


// ========================================================================
// __unwind$238309
// EA  : 0x827A4814
// RVA : 0x007A4814
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_238309()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 160));
}


// ========================================================================
// __unwind$238310
// EA  : 0x827A483C
// RVA : 0x007A483C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_238310()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$238312
// EA  : 0x827A4864
// RVA : 0x007A4864
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_238312()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 240));
}


// ========================================================================
// __unwind$238313
// EA  : 0x827A488C
// RVA : 0x007A488C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall _unwind_238313(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 416 + 80), tag: a2);
}


// ========================================================================
// ??0idMapPatch@@QAA@HH@Z
// EA  : 0x827A49E8
// RVA : 0x007A49E8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapPatch *__fastcall idMapPatch::idMapPatch(idMapPatch *this, int maxPatchWidth, int maxPatchHeight)
{
  idSurface_Patch *v6; // r28
  int size; // r11

  this->groupList.granularity = 0;
  this->groupList.memTag = 5;
  this->groupList.listStatic = 0;
  this->groupList.list = nullptr;
  this->groupList.size = 0;
  this->groupList.num = 0;
  this->__vftable = (idMapPatch_vtbl *)&idMapPrimitive::`vftable';
  this->type = -1;
  v6 = &this->idSurface_Patch;
  idSurface::idSurface(this: &this->idSurface_Patch);
  this->maxWidth = 0;
  this->maxHeight = 0;
  this->width = 0;
  this->height = 0;
  this->expanded = false;
  this->__vftable = (idMapPatch_vtbl *)&idMapPatch::`vftable';
  this->material.allocedAndFlag = 20;
  this->material.data = this->material.baseBuffer;
  this->material.len = 0;
  this->material.baseBuffer[0] = 0;
  this->maxWidth = maxPatchWidth;
  this->maxHeight = maxPatchHeight;
  this->type = 1;
  this->vertSubdivisions = 0;
  this->horzSubdivisions = 0;
  this->explicitSubdivisions = false;
  this->height = 0;
  this->width = 0;
  if ( maxPatchWidth * maxPatchHeight <= this->verts.size
    || (unsigned __int8)idList<idDrawVert,44>::Resize(this: &v6->verts, newsize: maxPatchWidth * maxPatchHeight) != 0 )
  {
    size = v6->verts.size;
    if ( maxPatchWidth * maxPatchHeight < size )
      size = maxPatchWidth * maxPatchHeight;
    v6->verts.num = size;
  }
  this->expanded = false;
  return this;
}


// ========================================================================
// __unwind$238809
// EA  : 0x827A4B00
// RVA : 0x007A4B00
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_238809()
{
  int v0; // r12

  idMapPrimitive::~idMapPrimitive(this: *(idMapPrimitive **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$238810_0
// EA  : 0x827A4B28
// RVA : 0x007A4B28
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_238810_0()
{
  int v0; // r12

  idSurface_Patch::~idSurface_Patch(this: (idSurface_Patch *)(*(_DWORD *)(v0 - 160 + 180) + 24));
}


// ========================================================================
// __unwind$238811
// EA  : 0x827A4B54
// RVA : 0x007A4B54
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_238811()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 120));
}


// ========================================================================
// ?Parse@idMapPatch@@SAPAV1@AAVidLexer@@ABVidVec3@@_NH@Z
// EA  : 0x827A4B88
// RVA : 0x007A4B88
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapPatch *__fastcall idMapPatch::Parse(idLexer *src, const idVec3 *origin, bool patchDef3, int version)
{
  idMapPatch *v8; // r3
  idMapPatch *v9; // r29
  idStr *v10; // r3
  int v11; // r9
  int v12; // r27
  int v13; // r30
  int v14; // r9
  float *p_x; // r11
  idToken v17; // [sp+70h] [-130h] BYREF
  float v18[8]; // [sp+C0h] [-E0h] BYREF
  float v19[8]; // [sp+E0h] [-C0h] BYREF
  idStr v20; // [sp+100h] [-A0h] BYREF
  idStr v21[4]; // [sp+120h] [-80h] BYREF

  v17.len = 0;
  v17.allocedAndFlag = 20;
  v17.floatvalue = -3.4028235e38;
  v17.data = v17.baseBuffer;
  v17.baseBuffer[0] = 0;
  v17.intvalue = 0;
  memset(&v17.whiteSpaceStart_p, 0, 12);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    goto LABEL_42;
  if ( !idLexer::ReadToken(this: src, token: &v17) )
  {
    idLexer::Error(this: src, str: "idMapPatch::Parse: unexpected EOF");
LABEL_42:
    idStr::FreeData(this: &v17);
    return nullptr;
  }
  if ( patchDef3 )
  {
    if ( !idLexer::Parse1DMatrix(this: src, x: 7, m: v19, expectCommas: false) )
    {
      idLexer::Error(this: src, str: "idMapPatch::Parse: unable to Parse patchDef3 info");
      goto LABEL_42;
    }
  }
  else if ( !idLexer::Parse1DMatrix(this: src, x: 5, m: v19, expectCommas: false) )
  {
    idLexer::Error(this: src, str: "idMapPatch::Parse: unable to parse patchDef2 info");
    goto LABEL_42;
  }
  v8 = (idMapPatch *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                       size: 0xA4u,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
    v9 = idMapPatch::idMapPatch(this: v8, maxPatchWidth: (int)v19[0], maxPatchHeight: (int)v19[1]);
  else
    v9 = nullptr;
  idSurface_Patch::SetSize(this: &v9->idSurface_Patch, patchWidth: (int)v19[0], patchHeight: (int)v19[1]);
  v9->origin.x = origin->x;
  v9->origin.y = origin->y;
  v9->origin.z = origin->z;
  if ( version >= 2 )
  {
    idStr::operator=(this: &v9->material, text: v17.data);
  }
  else
  {
    v10 = operator+(result: v21, a: "textures/", b: &v17);
    idStr::operator=(this: &v9->material, text: v10->data);
    idStr::FreeData(this: v21);
  }
  if ( patchDef3 )
  {
    v9->horzSubdivisions = (int)v19[2];
    v11 = (int)v19[3];
    v9->explicitSubdivisions = true;
    v9->vertSubdivisions = v11;
  }
  if ( v9->width < 0 || v9->height < 0 )
  {
    idLexer::Error(this: src, str: "idMapPatch::Parse: bad size");
    ((void (__fastcall *)(idMapPatch *, int))v9->dtr_idMapGroups)(a1: v9, a2: 1);
    goto LABEL_42;
  }
  if ( !idLexer::ExpectTokenString(this: src, string: "(") )
  {
    idLexer::Error(this: src, str: "idMapPatch::Parse: bad patch vertex data");
    ((void (__fastcall *)(idMapPatch *, int))v9->dtr_idMapGroups)(a1: v9, a2: 1);
    goto LABEL_42;
  }
  v12 = 0;
  if ( v9->width > 0 )
  {
    while ( 1 )
    {
      if ( !idLexer::ExpectTokenString(this: src, string: "(") )
      {
        idLexer::Error(this: src, str: "idMapPatch::Parse: bad vertex row data");
        ((void (__fastcall *)(idMapPatch *, int))v9->dtr_idMapGroups)(a1: v9, a2: 1);
        goto LABEL_42;
      }
      v13 = 0;
      if ( v9->height > 0 )
        break;
LABEL_26:
      if ( !idLexer::ExpectTokenString(this: src, string: ")") )
      {
        ((void (__fastcall *)(idMapPatch *, int))v9->dtr_idMapGroups)(a1: v9, a2: 1);
        idLexer::Error(this: src, str: "idMapPatch::Parse: unable to parse patch control points");
        goto LABEL_42;
      }
      if ( ++v12 >= v9->width )
        goto LABEL_28;
    }
    while ( idLexer::Parse1DMatrix(this: src, x: 5, m: v18, expectCommas: false) )
    {
      v14 = v9->width * v13++ + v12;
      p_x = &v9->verts.list[v14].xyz.x;
      *p_x = v18[0] - origin->x;
      p_x[1] = v18[1] - origin->y;
      p_x[2] = v18[2] - origin->z;
      p_x[3] = v18[3];
      p_x[4] = v18[4];
      if ( v13 >= v9->height )
        goto LABEL_26;
    }
    idLexer::Error(this: src, str: "idMapPatch::Parse: bad vertex column data");
    ((void (__fastcall *)(idMapPatch *, int))v9->dtr_idMapGroups)(a1: v9, a2: 1);
    goto LABEL_42;
  }
LABEL_28:
  if ( !idLexer::ExpectTokenString(this: src, string: ")") )
  {
    idLexer::Error(this: src, str: "idMapPatch::Parse: unable to parse patch control points, no closure");
    ((void (__fastcall *)(idMapPatch *, int))v9->dtr_idMapGroups)(a1: v9, a2: 1);
    goto LABEL_42;
  }
  if ( idLexer::ReadToken(this: src, token: &v17) )
  {
    while ( idStr::Cmp(s1: v17.data, s2: "}") != 0 )
    {
      if ( v17.type == 1 )
      {
        idStr::idStr(this: &v20, text: &v17);
        idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v17);
        idStr::FreeData(this: &v20);
      }
      if ( !idLexer::ReadToken(this: src, token: &v17) )
        goto LABEL_40;
    }
    idLexer::ExpectTokenString(this: src, string: "}");
  }
LABEL_40:
  idStr::FreeData(this: &v17);
  return v9;
}


// ========================================================================
// __unwind$238966
// EA  : 0x827A50B0
// RVA : 0x007A50B0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_238966()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 112));
}


// ========================================================================
// __unwind$238967
// EA  : 0x827A50D8
// RVA : 0x007A50D8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall _unwind_238967(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 416 + 96), tag: a2);
}


// ========================================================================
// __unwind$238968
// EA  : 0x827A5100
// RVA : 0x007A5100
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_238968()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 288));
}


// ========================================================================
// __unwind$238969
// EA  : 0x827A5128
// RVA : 0x007A5128
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_238969()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 256));
}


// ========================================================================
// ??1idMapReference@@UAA@XZ
// EA  : 0x827A5158
// RVA : 0x007A5158
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapReference::~idMapReference(idMapReference *this)
{
  idMapFile *map; // r3

  this->__vftable = (idMapReference_vtbl *)&idMapReference::`vftable';
  map = this->map;
  if ( map != nullptr )
    ((void (__fastcall *)(idMapFile *, int))map->dtr_idMapFile)(a1: map, a2: 1);
  idStr::FreeData(this: &this->worldSpawnText);
  idStr::FreeData(this: &this->mapName);
  this->__vftable = (idMapReference_vtbl *)&idMapPrimitive::`vftable';
  idMapGroups::~idMapGroups(this);
}


// ========================================================================
// __unwind$239443
// EA  : 0x827A51E0
// RVA : 0x007A51E0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239443()
{
  int v0; // r12

  idMapPrimitive::~idMapPrimitive(this: *(idMapPrimitive **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$239444
// EA  : 0x827A5208
// RVA : 0x007A5208
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239444()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// __unwind$239445
// EA  : 0x827A5234
// RVA : 0x007A5234
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239445()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// ??0idMapEntity@@QAA@XZ
// EA  : 0x827A5268
// RVA : 0x007A5268
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapEntity *__fastcall idMapEntity::idMapEntity(idMapEntity *this)
{
  this->groupList.granularity = 0;
  this->groupList.listStatic = 0;
  this->groupList.memTag = 5;
  this->groupList.list = nullptr;
  this->groupList.size = 0;
  this->groupList.num = 0;
  this->__vftable = (idMapEntity_vtbl *)&idMapEntity::`vftable';
  idMapModel::idMapModel(this: &this->model);
  this->refId.len = 0;
  this->refId.allocedAndFlag = 20;
  this->refId.data = this->refId.baseBuffer;
  this->refId.baseBuffer[0] = 0;
  this->layerList.granularity = 0;
  this->layerList.memTag = 5;
  this->layerList.listStatic = 0;
  this->layerList.list = nullptr;
  this->layerList.size = 0;
  this->layerList.num = 0;
  this->entityDef = nullptr;
  this->parentReference = nullptr;
  return this;
}


// ========================================================================
// __unwind$239482
// EA  : 0x827A530C
// RVA : 0x007A530C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239482()
{
  int v0; // r12

  idMapGroups::~idMapGroups(this: *(idMapGroups **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$239483
// EA  : 0x827A5334
// RVA : 0x007A5334
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239483()
{
  int v0; // r12

  idMapModel::~idMapModel(this: (idMapModel *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}


// ========================================================================
// __unwind$239484
// EA  : 0x827A5360
// RVA : 0x007A5360
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239484()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 76));
}


// ========================================================================
// ??1idMapEntity@@UAA@XZ
// EA  : 0x827A5398
// RVA : 0x007A5398
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapEntity::~idMapEntity(idMapEntity *this)
{
  idDeclEntityDef *entityDef; // r3
  idStr *list; // r3

  this->__vftable = (idMapEntity_vtbl *)&idMapEntity::`vftable';
  entityDef = this->entityDef;
  if ( entityDef != nullptr )
    ((void (__fastcall *)(idDeclEntityDef *, int))entityDef->dtr_idResource)(a1: entityDef, a2: 1);
  if ( this->layerList.listStatic == 0 || this->layerList.listStatic == 2 )
  {
    list = this->layerList.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->layerList.size);
    this->layerList.list = nullptr;
    this->layerList.size = 0;
  }
  this->layerList.num = 0;
  idStr::FreeData(this: &this->refId);
  idMapModel::~idMapModel(this: &this->model);
  idMapGroups::~idMapGroups(this);
}


// ========================================================================
// __unwind$239577
// EA  : 0x827A5434
// RVA : 0x007A5434
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239577()
{
  int v0; // r12

  idMapGroups::~idMapGroups(this: *(idMapGroups **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$239578
// EA  : 0x827A545C
// RVA : 0x007A545C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239578()
{
  int v0; // r12

  idMapModel::~idMapModel(this: (idMapModel *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// __unwind$239579
// EA  : 0x827A5488
// RVA : 0x007A5488
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239579()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 76));
}


// ========================================================================
// __unwind$239580
// EA  : 0x827A54B4
// RVA : 0x007A54B4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_239580()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// ??0idMapFile@@QAA@XZ
// EA  : 0x827A5AF0
// RVA : 0x007A5AF0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapFile *__fastcall idMapFile::idMapFile(idMapFile *this)
{
  idList<idMapEntity *,5> *p_entities; // r28

  this->__vftable = (idMapFile_vtbl *)&idMapFile::`vftable';
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->entities.list = nullptr;
  p_entities = &this->entities;
  this->entities.granularity = 0;
  this->entities.memTag = 5;
  this->entities.listStatic = 0;
  this->entities.size = 0;
  this->entities.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entities);
  idMapEditorStates::idMapEditorStates(this: &this->groupStates);
  this->referenceMaps.granularity = 0;
  this->referenceMaps.memTag = 5;
  this->referenceMaps.listStatic = 0;
  this->referenceMaps.list = nullptr;
  this->referenceMaps.size = 0;
  this->referenceMaps.num = 0;
  this->fileTime = 0;
  this->version = 3;
  this->geometryCRC = 0;
  if ( this->entities.size < 1024 )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)p_entities, newsize: 1024);
  this->hasPrimitiveData = false;
  this->game = nullptr;
  this->parentReference = nullptr;
  this->expandReferences = true;
  this->entitiesAreReference = false;
  this->ignoreGroupInfo = false;
  return this;
}


// ========================================================================
// __unwind$240593
// EA  : 0x827A5BD8
// RVA : 0x007A5BD8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_240593()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// __unwind$240594
// EA  : 0x827A5C04
// RVA : 0x007A5C04
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_240594()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 52));
}


// ========================================================================
// __unwind$240595
// EA  : 0x827A5C30
// RVA : 0x007A5C30
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_240595()
{
  int v0; // r12

  idMapEditorStates::~idMapEditorStates(this: (idMapEditorStates *)(*(_DWORD *)(v0 - 144 + 164) + 68));
}


// ========================================================================
// __unwind$240596
// EA  : 0x827A5C5C
// RVA : 0x007A5C5C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_240596()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(*(_DWORD *)(v0 - 144 + 164) + 120));
}


// ========================================================================
// ??1idMapFile@@UAA@XZ
// EA  : 0x827A5C90
// RVA : 0x007A5C90
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapFile::~idMapFile(idMapFile *this)
{
  idList<idMapEntity *,5> *p_entities; // r29
  idRefMapDef *list; // r3

  this->__vftable = (idMapFile_vtbl *)&idMapFile::`vftable';
  p_entities = &this->entities;
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->entities);
  if ( this->referenceMaps.listStatic == 0 || this->referenceMaps.listStatic == 2 )
  {
    list = this->referenceMaps.list;
    if ( list != nullptr )
      idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &list->mapName, num: this->referenceMaps.size);
    this->referenceMaps.list = nullptr;
    this->referenceMaps.size = 0;
  }
  this->referenceMaps.num = 0;
  idMapEditorStates::~idMapEditorStates(this: &this->groupStates);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_entities);
  idStr::FreeData(this: &this->name);
}


// ========================================================================
// __unwind$240675
// EA  : 0x827A5D18
// RVA : 0x007A5D18
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_240675()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$240676
// EA  : 0x827A5D44
// RVA : 0x007A5D44
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_240676()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// __unwind$240677
// EA  : 0x827A5D70
// RVA : 0x007A5D70
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_240677()
{
  int v0; // r12

  idMapEditorStates::~idMapEditorStates(this: (idMapEditorStates *)(*(_DWORD *)(v0 - 128 + 148) + 68));
}


// ========================================================================
// __unwind$240678
// EA  : 0x827A5D9C
// RVA : 0x007A5D9C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_240678()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(*(_DWORD *)(v0 - 128 + 148) + 120));
}


// ========================================================================
// ?Parse@idMapEditorStates@@QAAXAAVidLexer@@@Z
// EA  : 0x827A5E58
// RVA : 0x007A5E58
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapEditorStates::Parse(idMapEditorStates *this, idLexer *src)
{
  unsigned int v4; // r29
  const char **v5; // r11
  int len; // r21
  unsigned int v7; // r29
  const char **v8; // r11
  int v9; // r21
  int v10; // r29
  idGroupState v11; // [sp+50h] [-290h] BYREF
  idGroupState v12; // [sp+80h] [-260h] BYREF
  idGroupState v13; // [sp+B0h] [-230h] BYREF
  idColor v14; // [sp+E0h] [-200h] BYREF
  idToken v15; // [sp+F0h] [-1F0h] BYREF
  idToken v16; // [sp+140h] [-1A0h] BYREF
  idToken v17; // [sp+190h] [-150h] BYREF
  idToken v18; // [sp+1E0h] [-100h] BYREF
  idToken v19; // [sp+230h] [-B0h] BYREF

  if ( idLexer::PeekTokenString(this: src, string: "groupstates") )
  {
    if ( !idLexer::CheckTokenString(this: src, string: "groupstates") )
      return;
    idLexer::ExpectTokenString(this: src, string: "{");
    v15.floatvalue = -3.4028235e38;
    v15.allocedAndFlag = 20;
    v15.data = v15.baseBuffer;
    v15.len = 0;
    v15.baseBuffer[0] = 0;
    v15.intvalue = 0;
    memset(&v15.whiteSpaceStart_p, 0, 12);
    v18.floatvalue = -3.4028235e38;
    v18.allocedAndFlag = 20;
    v18.data = v18.baseBuffer;
    v18.len = 0;
    v18.baseBuffer[0] = 0;
    v18.intvalue = 0;
    memset(&v18.whiteSpaceStart_p, 0, 12);
    while ( idLexer::ReadToken(this: src, token: &v15) )
    {
      if ( idStr::Cmp(s1: v15.data, s2: "}") == 0
        || v15.type != 1
        || !idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v18) )
      {
        break;
      }
      v4 = 0;
      if ( groupStateTokens[0] != nullptr )
      {
        v5 = groupStateTokens;
        while ( idStr::Icmp(s1: v18.data, s2: *v5) != 0 )
        {
          v5 = &groupStateTokens[++v4];
          if ( *v5 == nullptr )
            goto LABEL_15;
        }
        v11.groupName.allocedAndFlag = 20;
        v11.groupName.len = 0;
        v11.groupName.data = v11.groupName.baseBuffer;
        v11.groupName.baseBuffer[0] = 0;
        len = v15.len;
        idStr::EnsureAlloced(this: &v11.groupName, amount: v15.len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v11.groupName.data, Src: v15.data, Size: len);
        v11.groupName.data[len] = 0;
        v11.groupName.len = len;
        v11.state = v4;
        if ( idList<idGroupState,5>::FindIndex(this: &this->groupStates, obj: &v11, startIndex: 0) < 0 )
          idList<idGroupState,5>::Append(this: (idList<idUniqueWarning,3> *)&this->groupStates, obj: &v11);
        idStr::FreeData(this: &v11.groupName);
      }
LABEL_15:
      ;
    }
    idStr::FreeData(this: &v18);
    idStr::FreeData(this: &v15);
  }
  if ( idLexer::PeekTokenString(this: src, string: "layerstates") )
  {
    if ( !idLexer::CheckTokenString(this: src, string: "layerstates") )
      return;
    idLexer::ExpectTokenString(this: src, string: "{");
    v17.floatvalue = -3.4028235e38;
    v17.allocedAndFlag = 20;
    v17.data = v17.baseBuffer;
    v17.len = 0;
    v17.baseBuffer[0] = 0;
    v17.intvalue = 0;
    memset(&v17.whiteSpaceStart_p, 0, 12);
    v19.floatvalue = -3.4028235e38;
    v19.allocedAndFlag = 20;
    v19.data = v19.baseBuffer;
    v19.len = 0;
    v19.baseBuffer[0] = 0;
    v19.intvalue = 0;
    memset(&v19.whiteSpaceStart_p, 0, 12);
    while ( idLexer::ReadToken(this: src, token: &v17) )
    {
      if ( idStr::Cmp(s1: v17.data, s2: "}") == 0
        || v17.type != 1
        || !idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v19) )
      {
        break;
      }
      v7 = 0;
      if ( groupStateTokens[0] != nullptr )
      {
        v8 = groupStateTokens;
        while ( idStr::Icmp(s1: v19.data, s2: *v8) != 0 )
        {
          v8 = &groupStateTokens[++v7];
          if ( *v8 == nullptr )
            goto LABEL_31;
        }
        v12.groupName.allocedAndFlag = 20;
        v12.groupName.len = 0;
        v12.groupName.data = v12.groupName.baseBuffer;
        v12.groupName.baseBuffer[0] = 0;
        v9 = v17.len;
        idStr::EnsureAlloced(this: &v12.groupName, amount: v17.len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v12.groupName.data, Src: v17.data, Size: v9);
        v12.groupName.data[v9] = 0;
        v12.groupName.len = v9;
        v12.state = v7;
        if ( idList<idGroupState,5>::FindIndex(this: &this->layerStates, obj: &v12, startIndex: 0) < 0 )
          idList<idGroupState,5>::Append(this: (idList<idUniqueWarning,3> *)&this->layerStates, obj: &v12);
        idStr::FreeData(this: &v12.groupName);
      }
LABEL_31:
      ;
    }
    idStr::FreeData(this: &v19);
    idStr::FreeData(this: &v17);
  }
  if ( idLexer::PeekTokenString(this: src, string: "groupcolors")
    && idLexer::CheckTokenString(this: src, string: "groupcolors") )
  {
    idLexer::ExpectTokenString(this: src, string: "{");
    v16.floatvalue = -3.4028235e38;
    v16.allocedAndFlag = 20;
    v16.data = v16.baseBuffer;
    v16.len = 0;
    v16.baseBuffer[0] = 0;
    v16.intvalue = 0;
    memset(&v16.whiteSpaceStart_p, 0, 12);
    while ( idLexer::ReadToken(this: src, token: &v16) )
    {
      if ( idStr::Cmp(s1: v16.data, s2: "}") == 0 || v16.type != 1 )
        break;
      v14.r = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v14.g = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v14.b = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v14.a = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v13.groupName.allocedAndFlag = 20;
      v13.groupName.data = v13.groupName.baseBuffer;
      v13.groupName.len = 0;
      v13.groupName.baseBuffer[0] = 0;
      v10 = v16.len;
      if ( v16.len + 1 > 20 )
        idStr::ReAllocate(this: &v13.groupName, amount: v16.len + 1, keepold: false);
      memcpy(Dst: v13.groupName.data, Src: v16.data, Size: v10);
      v13.groupName.data[v10] = 0;
      v13.groupName.len = v10;
      v13.state = idColor::ToColorRef(this: &v14);
      if ( idList<idGroupState,5>::FindIndex(this: &this->groupColors, obj: &v13, startIndex: 0) < 0 )
        idList<idGroupState,5>::Append(this: (idList<idUniqueWarning,3> *)&this->groupColors, obj: &v13);
      idStr::FreeData(this: &v13.groupName);
    }
    idStr::FreeData(this: &v16);
  }
}


// ========================================================================
// __unwind$241020
// EA  : 0x827A63E4
// RVA : 0x007A63E4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241020()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 240));
}


// ========================================================================
// __unwind$241021
// EA  : 0x827A640C
// RVA : 0x007A640C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241021()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 480));
}


// ========================================================================
// __unwind$241022
// EA  : 0x827A6434
// RVA : 0x007A6434
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241022()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 80));
}


// ========================================================================
// __unwind$241023
// EA  : 0x827A645C
// RVA : 0x007A645C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241023()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 400));
}


// ========================================================================
// __unwind$241024
// EA  : 0x827A6484
// RVA : 0x007A6484
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241024()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 560));
}


// ========================================================================
// __unwind$241025
// EA  : 0x827A64AC
// RVA : 0x007A64AC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241025()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 128));
}


// ========================================================================
// __unwind$241026
// EA  : 0x827A64D4
// RVA : 0x007A64D4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241026()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 320));
}


// ========================================================================
// __unwind$241027
// EA  : 0x827A64FC
// RVA : 0x007A64FC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241027()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 176));
}


// ========================================================================
// ?Parse@idMapReference@@SAPAV1@AAVidLexer@@H_NPAVidMapEntity@@@Z
// EA  : 0x827A6530
// RVA : 0x007A6530
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapReference *__fastcall idMapReference::Parse(idLexer *src, int version, bool expandReferences, idMapEntity *parent)
{
  _WORD *v7; // r3
  _WORD *v8; // r29
  idMapFile *v10; // r3
  idMapFile *v11; // r3
  idToken v12[2]; // [sp+60h] [-A0h] BYREF

  v12[0].len = 0;
  v12[0].allocedAndFlag = 20;
  v12[0].floatvalue = -3.4028235e38;
  v12[0].data = v12[0].baseBuffer;
  v12[0].baseBuffer[0] = 0;
  v12[0].intvalue = 0;
  v12[0].whiteSpaceStart_p = nullptr;
  v12[0].whiteSpaceEnd_p = nullptr;
  v12[0].next = nullptr;
  idLexer::ExpectTokenString(this: src, string: "{");
  v7 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
         size: 0x5Cu,
         tag: TAG_NEW,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
  {
    v7[8] = 0;
    *((_BYTE *)v7 + 19) = 0;
    *((_DWORD *)v7 + 1) = 0;
    *((_DWORD *)v7 + 3) = 0;
    *((_BYTE *)v7 + 18) = 5;
    *((_DWORD *)v7 + 2) = 0;
    *(_DWORD *)v7 = &idMapReference::`vftable';
    *((_DWORD *)v7 + 5) = -1;
    *((_DWORD *)v7 + 7) = v7 + 18;
    *((_DWORD *)v7 + 8) = 20;
    *((_DWORD *)v7 + 6) = 0;
    *((_BYTE *)v7 + 36) = 0;
    *((_DWORD *)v7 + 16) = 20;
    v8 = v7;
    *((_DWORD *)v7 + 15) = v7 + 34;
    *((_DWORD *)v7 + 14) = 0;
    *((_BYTE *)v7 + 68) = 0;
    *((_DWORD *)v7 + 22) = 0;
  }
  else
  {
    v8 = nullptr;
  }
  if ( idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: v12) )
  {
    idStr::operator=(this: (idStr *)(v8 + 12), text: v12[0].data);
    if ( expandReferences )
    {
      v10 = (idMapFile *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x98u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
      v11 = v10 != nullptr ? idMapFile::idMapFile(this: v10) : nullptr;
      *((_DWORD *)v8 + 22) = v11;
      if ( !idMapFile::Parse(this: v11, filename: *((const char **)v8 + 7), osPath: false, parent) )
      {
        (**(void (__fastcall ***)(_WORD *, int))v8)(a1: v8, a2: 1);
        v8 = nullptr;
      }
    }
    idLexer::ExpectTokenString(this: src, string: "}");
    idLexer::ExpectTokenString(this: src, string: "}");
    idStr::FreeData(this: &v12[0]);
    return (idMapReference *)v8;
  }
  else
  {
    idLexer::Error(this: src, str: "expected map file name not found");
    if ( v8 != nullptr )
      (**(void (__fastcall ***)(_WORD *, int))v8)(a1: v8, a2: 1);
    idStr::FreeData(this: &v12[0]);
    return nullptr;
  }
}


// ========================================================================
// __unwind$241581
// EA  : 0x827A6760
// RVA : 0x007A6760
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241581()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$241582
// EA  : 0x827A6788
// RVA : 0x007A6788
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall _unwind_241582(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 256 + 168), tag: a2);
}


// ========================================================================
// __unwind$241583
// EA  : 0x827A67B0
// RVA : 0x007A67B0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall _unwind_241583(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 256 + 80), tag: a2);
}


// ========================================================================
// ?ExpandReference@idMapReference@@QAAXPAVidMapFile@@PAVidMapEntity@@@Z
// EA  : 0x827A67E0
// RVA : 0x007A67E0
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall idMapReference::ExpandReference(idMapReference *this, idMapFile *mapFile, idMapEntity *mapEnt)
{
  int v6; // ctr
  float *p_y; // r11
  unsigned __int8 v8; // r29
  char *v9; // r10
  idDeclEntityDef *entityDef; // r30
  int v11; // r28
  const char *v12; // r3
  __int64 v13; // r8
  int v14; // r6
  int v15; // r5
  __int64 v16; // r10
  int v17; // r27
  idMapEntity *v18; // r21
  int v19; // r18
  int v20; // r26
  int v21; // r11
  int v22; // r30
  _BYTE *v23; // r10
  __int64 v24; // r6
  va *v25; // r3
  __int64 v26; // r8
  int v27; // r6
  int v28; // r5
  int v29; // r28
  int v30; // r29
  const char *v31; // r3
  idMapFile *map; // r11
  idList<idMapEntity *,5> *p_entities; // r9
  int num; // r11
  int v35; // r11
  bool v36; // zf
  int v37; // r10
  void **v38; // r29
  void *v39; // r4
  char *Text; // r3
  int v41; // [sp+8h] [-1178h]
  int v42; // [sp+Ch] [-1174h]
  int v43; // [sp+10h] [-1170h]
  int v44; // [sp+14h] [-116Ch]
  int v45; // [sp+18h] [-1168h]
  int v46; // [sp+1Ch] [-1164h]
  bool v47; // [sp+50h] [-1130h] BYREF
  void *v48; // [sp+54h] [-112Ch] BYREF
  idVec3 v49[2]; // [sp+58h] [-1128h] BYREF
  idTypeInfoTree v50; // [sp+70h] [-1110h] BYREF
  idStr v51; // [sp+90h] [-10F0h] BYREF
  idStr v52; // [sp+B0h] [-10D0h] BYREF
  idMat3 v53; // [sp+D0h] [-10B0h] BYREF
  va v54; // [sp+100h] [-1080h] BYREF

  if ( this->map != nullptr )
  {
    idStr::idStr(this: &v51, text: mapEnt->entityDef->name.str);
    v6 = 9;
    p_y = &mat2_identity.mat[1].y;
    v8 = 0;
    v47 = false;
    v9 = &v52.baseBuffer[16];
    v49[0] = vec3_origin;
    do
    {
      ++p_y;
      v9 += 4;
      *(float *)v9 = *p_y;
      --v6;
    }
    while ( v6 != 0 );
    entityDef = mapEnt->entityDef;
    v11 = entityDef->GetEntityStateWithInheritanceLength(this: entityDef);
    v12 = entityDef->GetEntityStateWithInheritance(this: entityDef);
    idTypeInfoTree::idTypeInfoTree(this: &v50, text: v12, length: v11);
    idTypeInfoTree::GetBool(this: &v50, path: "zeroTransform", value: &v47);
    v15 = v47;
    if ( !v47 )
    {
      idTypeInfoTree::GetVec3(this: &v50, path: "spawnPosition", value: v49);
      idTypeInfoTree::GetMat3(this: &v50, path: "spawnOrientation", value: &v53);
      v8 = 1;
    }
    HIDWORD(v16) = this->map;
    v17 = 0;
    v18 = *mapFile->entities.list;
    if ( *(int *)(HIDWORD(v16) + 56) > 0 )
    {
      v19 = v8;
      v20 = 0;
      do
      {
        v21 = 0;
        v22 = *(_DWORD *)(*(_DWORD *)(HIDWORD(v16) + 52) + v20);
        v23 = *(_BYTE **)(v22 + 80);
        if ( *v23 == 0 )
          goto LABEL_11;
        do
          LODWORD(v13) = (unsigned __int8)v23[++v21];
        while ( v23[v21] != 0 );
        if ( v21 == 0 )
LABEL_11:
          idStr::operator=(this: (idStr *)(v22 + 76), text: *(const char **)(HIDWORD(v16) + 8));
        LODWORD(v16) = v47;
        if ( !v47 )
          idMapEntity::Transform(this: (idMapEntity *)v22, origin: v49, axis: &v53);
        if ( v19 != 0 )
        {
          HIDWORD(v24) = v51.data;
          LODWORD(v24) = *(_DWORD *)(*(_DWORD *)(v22 + 20) + 8);
          v25 = va::va(
                  this: &v54,
                  fmt: "%s_%s",
                  a3: v24,
                  a4: v13,
                  a5: v16,
                  a6: v41,
                  a7: v42,
                  a8: v43,
                  a9: v44,
                  a10: v45,
                  a11: v46);
          idStr::idStr(this: &v52, text: v25);
          idResource::SetName(this: *(idResource **)(v22 + 20), _name: v52.data);
          idMapEntity::FixMapModelNames(this: (idMapEntity *)v22, mapName: this->map->name.data, name: v52.data);
          idMapEntity::FixTargetNames(this: (idMapEntity *)v22, baseName: v51.data);
          idStr::FreeData(this: &v52);
        }
        idMapGroups::RenameReferenceGroups(this: (idMapGroups *)v22, refname: v51.data, a3: v15, a4: v14, a5: v13);
        v29 = 0;
        if ( *(int *)(v22 + 60) > 0 )
        {
          v30 = 0;
          do
          {
            idMapGroups::RenameReferenceGroups(
              this: *(idMapGroups **)(*(_DWORD *)(v22 + 56) + v30),
              refname: v51.data,
              a3: v28,
              a4: v27,
              a5: v26);
            ++v29;
            v30 += 4;
          }
          while ( v29 < *(_DWORD *)(v22 + 60) );
        }
        v31 = (const char *)(*(int (__fastcall **)(_DWORD))(**(_DWORD **)(v22 + 20) + 76))(a1: *(_DWORD *)(v22 + 20));
        if ( idStr::Icmp(s1: v31, s2: "idWorldSpawn") != 0 )
        {
          v48 = (void *)v22;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&mapFile->entities,
            obj: (const encounterGroupRole_t *)&v48);
          map = this->map;
          p_entities = &map->entities;
          if ( v17 >= 0 )
          {
            num = map->entities.num;
            if ( v17 < num )
            {
              p_entities->num = num - 1;
              v36 = v17 >= num - 1;
              v35 = v17;
              if ( !v36 )
              {
                v37 = v20;
                do
                {
                  ++v35;
                  LODWORD(v13) = (char *)p_entities->list + v37;
                  v37 += 4;
                  HIDWORD(v13) = *(_DWORD *)(v13 + 4);
                  *(_DWORD *)v13 = HIDWORD(v13);
                  v14 = p_entities->num;
                }
                while ( v35 < v14 );
              }
            }
          }
        }
        else
        {
          v38 = (void **)(v22 + 56);
          idList<idMD6Filter *,5>::Append(
            this: (idList<idMD6Filter *,5> *)&v18->model.primitives,
            other: (const idList<idMD6Filter *,5> *)(v22 + 56));
          if ( *(_BYTE *)(v22 + 71) == 0 || *(_BYTE *)(v22 + 71) == 2 )
          {
            v39 = *v38;
            if ( *v38 != nullptr )
            {
              v48 = *v38;
              idMem::Free(this: &mem, ptr: v39, align: ALIGN_16);
            }
            *v38 = nullptr;
            *(_DWORD *)(v22 + 64) = 0;
          }
          *(_DWORD *)(v22 + 60) = 0;
          Text = idDecl::GetText(this: *(idDecl **)(v22 + 20));
          idStr::operator=(this: &this->worldSpawnText, text: Text);
          ++v17;
          v20 += 4;
        }
        HIDWORD(v16) = this->map;
      }
      while ( v17 < *(_DWORD *)(HIDWORD(v16) + 56) );
    }
    idList<idRefMapDef,5>::Append(
      this: &mapFile->referenceMaps,
      other: (const idList<idRefMapDef,5> *)(HIDWORD(v16) + 120));
    idTypeInfoTree::Clear(this: &v50);
    idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(this: &v50.nodeBlockAlloc);
    idStr::FreeData(this: &v51);
  }
}


// ========================================================================
// __unwind$241817
// EA  : 0x827A6B74
// RVA : 0x007A6B74
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241817()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 144));
}


// ========================================================================
// __unwind$241818
// EA  : 0x827A6B9C
// RVA : 0x007A6B9C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241818()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 4480 + 112));
}


// ========================================================================
// __unwind$241819
// EA  : 0x827A6BC4
// RVA : 0x007A6BC4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_241819()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 176));
}


// ========================================================================
// __unwind$242107
// EA  : 0x827A6BEC
// RVA : 0x007A6BEC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242107()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(v0 - 4480 + 116));
}


// ========================================================================
// ?Parse@idMapEntity@@SAPAV1@PAVidMapFile@@AAVidLexer@@HPAV1@@Z
// EA  : 0x827A6C20
// RVA : 0x007A6C20
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

idMapEntity *__fastcall idMapEntity::Parse(idMapFile *mapFile, idLexer *src, int version, idMapEntity *parent)
{
  char *v6; // r3
  idMapEntity *v7; // r16
  idDeclEntityDef *v8; // r3
  const char *v9; // r3
  const char *v10; // r3
  const char *v11; // r3
  const char *v12; // r3
  idStr *v13; // r3
  idDeclEntityDef *entityDef; // r30
  int v15; // r28
  const char *v16; // r3
  int v17; // r3
  bool v18; // r5
  const idVec3 *v19; // r4
  idMapPatch *v20; // r3
  encounterGroupRole_t v21; // r30
  unsigned int v22; // r3
  idMapReference *v23; // r3
  idMapReference *v24; // r30
  idMapBrush *v25; // r3
  int len; // r30
  int v27; // r30
  int v28; // r3
  double v29; // fp11
  idDeclEntityDef *v30; // r3
  char v32; // [sp+50h] [-240h]
  char v33; // [sp+51h] [-23Fh]
  encounterGroupRole_t v34[3]; // [sp+54h] [-23Ch] BYREF
  idList<idStr,5> v35; // [sp+60h] [-230h] BYREF
  idVec3 v36; // [sp+70h] [-220h] BYREF
  idVec3 v37; // [sp+80h] [-210h] BYREF
  idToken v38; // [sp+90h] [-200h] BYREF
  char *v39; // [sp+D8h] [-1B8h]
  const char *v40; // [sp+DCh] [-1B4h]
  const char *v41; // [sp+E0h] [-1B0h]
  int v42; // [sp+E4h] [-1ACh]
  const char *v43; // [sp+E8h] [-1A8h]
  const char *v44; // [sp+ECh] [-1A4h]
  const char *v45; // [sp+F0h] [-1A0h]
  const char *v46; // [sp+F4h] [-19Ch]
  const char *v47; // [sp+F8h] [-198h]
  int v48; // [sp+FCh] [-194h]
  const char *v49; // [sp+100h] [-190h]
  const char *v50; // [sp+104h] [-18Ch]
  const char *v51; // [sp+108h] [-188h]
  const char *v52; // [sp+10Ch] [-184h]
  const char *v53; // [sp+110h] [-180h]
  const char *v54; // [sp+114h] [-17Ch]
  const char *v55; // [sp+118h] [-178h]
  idStr v56; // [sp+120h] [-170h] BYREF
  idStr v57; // [sp+140h] [-150h] BYREF
  double v58; // [sp+160h] [-130h] BYREF
  double v59; // [sp+168h] [-128h] BYREF
  double v60; // [sp+170h] [-120h] BYREF
  idStr v61; // [sp+180h] [-110h] BYREF
  idTypeInfoTree v62; // [sp+1A0h] [-F0h] BYREF
  idStr v63; // [sp+1C0h] [-D0h] BYREF

  v38.len = 0;
  v38.data = v38.baseBuffer;
  v38.floatvalue = -3.4028235e38;
  v38.allocedAndFlag = 20;
  v38.baseBuffer[0] = 0;
  v38.intvalue = 0;
  memset(&v38.whiteSpaceStart_p, 0, 12);
  v33 = 0;
  v32 = 0;
  if ( !idLexer::ReadToken(this: src, token: &v38) )
    goto LABEL_77;
  v40 = "{";
  if ( idStr::Cmp(s1: v38.data, s2: "{") != 0 )
  {
    idLexer::Error(this: src, str: "idMapEntity::Parse: { not found, found %s", v38.data);
LABEL_77:
    idStr::FreeData(this: &v38);
    return nullptr;
  }
  v6 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                 size: 0x7Cu,
                 tag: TAG_NEW,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v39 = v6;
  if ( v6 != nullptr )
    v7 = idMapEntity::idMapEntity(this: (idMapEntity *)v6);
  else
    v7 = nullptr;
  v7->parentReference = parent;
  v37.z = 0.0;
  v37.y = 0.0;
  v37.x = 0.0;
  v36.z = 0.0;
  v36.y = 0.0;
  v36.x = 0.0;
  if ( !idLexer::ReadToken(this: src, token: &v38) )
  {
LABEL_71:
    idLexer::Error(this: src, str: "idMapEntity::Parse: EOF without closing brace");
    goto LABEL_77;
  }
  v50 = "patch";
  v49 = "brushDef2";
  v45 = "brush";
  v53 = "func/gui";
  v39 = "worldspawn";
  v43 = "classname";
  v48 = -2088566784;
  v42 = -2088566784;
  v55 = "%lf %lf %lf";
  v41 = "origin";
  v52 = "Invalid map reference in entity \"%s\"";
  v46 = "reference";
  v54 = "spline";
  v44 = "splinemesh";
  v47 = "patchDef3";
  v51 = "brushDef3";
  while ( idStr::Cmp(s1: v38.data, s2: "}") != 0 )
  {
    *(_WORD *)&v35.memTag = 1280;
    memset(&v35, 0, 14);
    if ( idStr::Cmp(s1: v38.data, s2: "groups") == 0 )
    {
      idLexer::UnreadToken(this: src);
      idMapGroups::ParseGroups(src, groups: &v35);
      if ( !idLexer::ReadToken(this: src, token: &v38) )
        goto _M242748;
    }
    if ( idStr::Cmp(s1: v38.data, s2: "layers") == 0 )
    {
      idLexer::ExpectTokenString(this: src, string: v40);
      while ( idLexer::ReadToken(this: src, token: &v38) )
      {
        if ( idStr::Cmp(s1: v38.data, s2: "}") == 0 )
          break;
        if ( v38.type == 1 && idList<idStr,5>::FindIndex(this: &v7->layerList, obj: &v38, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &v7->layerList, obj: &v38);
      }
      if ( !idLexer::ReadToken(this: src, token: &v38) )
      {
_M242748:
        idLexer::Error(this: src, str: "idMapEntity::Parse: unexpected EOF");
        idList<idStr,99>::~idList<idStr,99>(this: &v35);
        goto LABEL_77;
      }
    }
    if ( idStr::Cmp(s1: v38.data, s2: "entityDef") == 0 && v7->entityDef == nullptr )
    {
      v61.len = 0;
      v61.baseBuffer[0] = 0;
      v61.data = v61.baseBuffer;
      v61.allocedAndFlag = 20;
      idLexer::ReadToken(this: src, token: &v38);
      idStr::idStr(this: &v63, text: &v38);
      idLexer::ParseBracedSectionExact(this: src, out: &v61, parseFirstBrace: true, intro: 123, outro: 125);
      idList<idStr,5>::Append(this: &v7->groupList, other: &v35);
      v8 = idDeclInfoTemplate<idDeclEntityDef>::AllocDecl(this: &idDeclEntityDef::resourceList);
      v7->entityDef = v8;
      idResource::SetName(this: &v8->idDecl, _name: v63.data);
      idDecl::SetText(this: &v7->entityDef->idDecl, text: v61.data, length: 0);
      idDecl::ReParse(this: &v7->entityDef->idDecl, fromDisk: false);
      v9 = v7->entityDef->GetInherit(this: v7->entityDef);
      if ( idStr::Icmp(s1: v9, s2: "func/static") != 0 )
      {
        v10 = v7->entityDef->GetInherit(this: v7->entityDef);
        if ( idStr::Find(searchIn: v10, searchFor: "prop/moveable", casesensitive: false, start: 0, end: -1) < 0 )
        {
          v11 = v7->entityDef->GetInherit(this: v7->entityDef);
          if ( idStr::Find(searchIn: v11, searchFor: "func/mover", casesensitive: false, start: 0, end: -1) < 0 )
          {
            v12 = v7->entityDef->GetInherit(this: v7->entityDef);
            if ( idStr::Find(searchIn: v12, searchFor: v53, casesensitive: false, start: 0, end: -1) < 0 )
            {
              v32 = 0;
              goto LABEL_27;
            }
          }
        }
      }
      v32 = 1;
      if ( *(_DWORD *)(v48 - 18116) != 0 )
      {
LABEL_27:
        v37.x = 0.0;
        v37.y = 0.0;
        v37.z = 0.0;
      }
      else
      {
        entityDef = v7->entityDef;
        v15 = entityDef->GetEntityStateWithInheritanceLength(this: entityDef);
        v16 = entityDef->GetEntityStateWithInheritance(this: entityDef);
        idTypeInfoTree::idTypeInfoTree(this: &v62, text: v16, length: v15);
        idTypeInfoTree::GetVec3(this: &v62, path: "spawnPosition", value: &v37);
        idTypeInfoTree::~idTypeInfoTree(this: &v62);
      }
      idStr::FreeData(this: &v63);
      v13 = &v61;
_M242736:
      idStr::FreeData(this: v13);
      goto LABEL_65;
    }
    if ( idStr::Cmp(s1: v38.data, s2: v40) != 0 )
    {
      v57.len = 0;
      v57.baseBuffer[0] = 0;
      v57.data = v57.baseBuffer;
      v57.allocedAndFlag = 20;
      v56.allocedAndFlag = 20;
      v56.data = v56.baseBuffer;
      v56.len = 0;
      v56.baseBuffer[0] = 0;
      len = v38.len;
      idStr::EnsureAlloced(this: &v57, amount: v38.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v57.data, Src: v38.data, Size: len);
      v57.data[len] = 0;
      v57.len = len;
      idLexer::ReadTokenOnLine(this: src, token: &v38);
      v27 = v38.len;
      idStr::EnsureAlloced(this: &v56, amount: v38.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v56.data, Src: v38.data, Size: v27);
      v56.data[v27] = 0;
      v56.len = v27;
      idStr::StripTrailingWhitespace(this: &v56);
      idStr::StripTrailingWhitespace(this: &v57);
      if ( idStr::Icmp(s1: v57.data, s2: v41) != 0 )
      {
        if ( idStr::Icmp(s1: v57.data, s2: v43) == 0 && idStr::Icmp(s1: v56.data, s2: v39) == 0 )
          v33 = 1;
      }
      else
      {
        v59 = 0.0;
        v60 = 0.0;
        v58 = 0.0;
        v28 = sscanf(string: v56.data, format: v55, &v58, &v60, &v59);
        v29 = v59;
        v36.x = v58;
        v36.y = v60;
        *(_DWORD *)(v42 - 18128) = v28;
        v36.z = v29;
      }
      idStr::FreeData(this: &v56);
      v13 = &v57;
      goto _M242736;
    }
    idMapGroups::ParseGroups(src, groups: &v35);
    if ( !idLexer::ReadToken(this: src, token: &v38) )
      goto _M242748;
    if ( v33 != 0 || v7->entityDef != nullptr )
    {
      v36.z = 0.0;
      v36.y = 0.0;
      v36.x = 0.0;
    }
    if ( idStr::Icmpn(s1: v38.data, s2: v45, n: 5) == 0 )
    {
      if ( idStr::Icmp(s1: v38.data, s2: v49) == 0 || (v17 = idStr::Icmp(s1: v38.data, s2: v51), v18 = false, v17 == 0) )
        v18 = true;
      v19 = &v37;
      if ( v32 == 0 )
        v19 = &v36;
      v20 = (idMapPatch *)idMapBrush::Parse(src, origin: v19, newFormat: v18, version);
      v21 = (encounterGroupRole_t)v20;
      if ( v20 == nullptr )
      {
_M242755:
        idList<idStr,99>::~idList<idStr,99>(this: &v35);
        goto LABEL_77;
      }
      goto LABEL_43;
    }
    if ( idStr::Icmpn(s1: v38.data, s2: v50, n: 5) == 0 )
    {
      v22 = idStr::Icmp(s1: v38.data, s2: v47);
      v20 = idMapPatch::Parse(src, origin: &v36, patchDef3: (_cntlzw(v22) & 0x20) != 0, version);
      v21 = (encounterGroupRole_t)v20;
      if ( v20 == nullptr )
        goto _M242755;
LABEL_43:
      idList<idStr,5>::Append(this: &v20->groupList, other: &v35);
      v34[0] = v21;
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&v7->model.primitives,
        obj: v34);
      goto LABEL_65;
    }
    if ( idStr::Icmpn(s1: v38.data, s2: v44, n: 10) != 0 && idStr::Icmpn(s1: v38.data, s2: v54, n: 6) != 0 )
    {
      if ( idStr::Icmp(s1: v38.data, s2: v46) != 0 )
      {
        idLexer::UnreadToken(this: src);
        v25 = idMapBrush::ParseQ3(src, origin: &v36);
        if ( v25 == nullptr )
          goto _M242755;
        v34[0] = (encounterGroupRole_t)v25;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v7->model.primitives,
          obj: v34);
      }
      else
      {
        v23 = idMapReference::Parse(src, version, expandReferences: mapFile->expandReferences, parent: v7);
        v24 = v23;
        if ( v23 != nullptr )
        {
          idList<idStr,5>::Append(this: &v23->groupList, other: &v35);
          if ( mapFile->expandReferences )
            idMapReference::ExpandReference(this: v24, mapFile, mapEnt: v7);
          idMapFile::AddReferenceMap(this: mapFile, name: v24->mapName.data, worldSpawnText: v24->worldSpawnText.data);
          v34[0] = (encounterGroupRole_t)v24;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&v7->model.primitives,
            obj: v34);
        }
        else
        {
          idLib::Warning(fmt: v52, v7->entityDef->name.str);
        }
      }
    }
    else
    {
      idLexer::SkipBracedSection(this: src, parseFirstBrace: false);
    }
LABEL_65:
    if ( v35.listStatic == 0 || v35.listStatic == 2 )
    {
      if ( v35.list != nullptr )
        idListArrayDelete<idStr>(ptr: v35.list, num: v35.size);
      v35.list = nullptr;
      v35.size = 0;
    }
    v35.num = 0;
    if ( !idLexer::ReadToken(this: src, token: &v38) )
      goto LABEL_71;
  }
  v30 = v7->entityDef;
  if ( v30 == nullptr )
  {
    ((void (__fastcall *)(idMapEntity *, int))v7->dtr_idMapGroups)(a1: v7, a2: 1);
    goto LABEL_77;
  }
  v30->SetInheritedClass(this: v30, a2: false);
  idStr::FreeData(this: &v38);
  return v7;
}


// ========================================================================
// __unwind$242188
// EA  : 0x827A766C
// RVA : 0x007A766C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242188()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 144));
}


// ========================================================================
// __unwind$242189
// EA  : 0x827A7694
// RVA : 0x007A7694
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void __fastcall _unwind_242189(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 656 + 216), tag: a2);
}


// ========================================================================
// __unwind$242190
// EA  : 0x827A76BC
// RVA : 0x007A76BC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242190()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 656 + 96));
}


// ========================================================================
// __unwind$242191
// EA  : 0x827A76E4
// RVA : 0x007A76E4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242191()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 384));
}


// ========================================================================
// __unwind$242192
// EA  : 0x827A770C
// RVA : 0x007A770C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242192()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 448));
}


// ========================================================================
// __unwind$242193
// EA  : 0x827A7734
// RVA : 0x007A7734
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242193()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 656 + 416));
}


// ========================================================================
// __unwind$242194
// EA  : 0x827A775C
// RVA : 0x007A775C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242194()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 320));
}


// ========================================================================
// __unwind$242195
// EA  : 0x827A7784
// RVA : 0x007A7784
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242195()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 288));
}


// ========================================================================
// ?ParseSingle@idMapFile@@QAA_NAAVidLexer@@@Z
// EA  : 0x827A7818
// RVA : 0x007A7818
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapFile::ParseSingle(idMapFile *this, idLexer *src)
{
  int v2; // r29
  idList<enum encounterGroupRole_t,5> *p_entities; // r27
  __int64 v6; // r10
  int v7; // r7
  __int64 v8; // r6
  int i; // r28
  idStr *MapModelName; // r3
  __int64 v12; // [sp+8h] [-118h]
  idMapEntity *v13; // [sp+50h] [-D0h] BYREF
  idStr v14; // [sp+60h] [-C0h] BYREF
  idToken v15[2]; // [sp+80h] [-A0h] BYREF

  v2 = 0;
  v15[0].len = 0;
  v15[0].allocedAndFlag = 20;
  v15[0].floatvalue = -3.4028235e38;
  v15[0].data = v15[0].baseBuffer;
  v15[0].baseBuffer[0] = 0;
  v15[0].intvalue = 0;
  v15[0].whiteSpaceStart_p = nullptr;
  v15[0].whiteSpaceEnd_p = nullptr;
  v15[0].next = nullptr;
  p_entities = (idList<enum encounterGroupRole_t,5> *)&this->entities;
  this->version = 1;
  this->fileTime = src->fileTime;
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->entities);
  if ( idLexer::CheckTokenString(this: src, string: "Version") )
  {
    idLexer::ReadTokenOnLine(this: src, token: v15);
    this->version = idToken::GetUnsignedIntValue(this: v15);
  }
  while ( idLexer::ReadToken(this: src, token: v15) )
  {
    if ( idStr::Cmp(s1: v15[0].data, s2: "entity") != 0 && idStr::Cmp(s1: v15[0].data, s2: "{") != 0 )
    {
      if ( idStr::Cmp(s1: v15[0].data, s2: "groupstates") != 0 && idStr::Cmp(s1: v15[0].data, s2: "groupcolors") != 0 )
        break;
      idLexer::UnreadToken(this: src);
      idMapEditorStates::Parse(this: &this->groupStates, src);
    }
    else
    {
      if ( idStr::Cmp(s1: v15[0].data, s2: "{") != 0 )
        idLexer::CheckTokenType(this: src, type: 3, subtype: 0, token: v15);
      else
        idLexer::UnreadToken(this: src);
      v13 = idMapEntity::Parse(mapFile: this, src, version: this->version, parent: this->parentReference);
      if ( v13 == nullptr )
      {
        idLib::Warning(fmt: "Failed to parse entity!");
        break;
      }
      idList<idAnimWebBlendTree *,5>::Append(this: p_entities, obj: (const encounterGroupRole_t *)&v13);
    }
  }
  idMapFile::SetGeometryCRC(this);
  for ( i = 0; i < this->entities.num; ++v2 )
  {
    LODWORD(v6) = *(_DWORD *)(p_entities->list[v2] + 20);
    HIDWORD(v8) = *(_DWORD *)(v6 + 8);
    MapModelName = idMapFile::GetMapModelName(result: &v14, entityName: v8, a3: v7, a4: v6, a5: v12);
    idStr::operator=(this: (idStr *)(p_entities->list[v2] + 24), text: MapModelName->data);
    idStr::FreeData(this: &v14);
    if ( this->expandReferences )
      idMapEntity::FixMapModelNames(
        this: (idMapEntity *)p_entities->list[v2],
        mapName: this->name.data,
        name: *(const char **)(*(_DWORD *)(p_entities->list[v2] + 20) + 8));
    ++i;
  }
  if ( this->version <= 2 )
    idMapFile::ConvertMapModelNames(this);
  this->hasPrimitiveData = true;
  idStr::FreeData(this: &v15[0]);
  return 1;
}


// ========================================================================
// __unwind$242812
// EA  : 0x827A7A90
// RVA : 0x007A7A90
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242812()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$242813
// EA  : 0x827A7AB8
// RVA : 0x007A7AB8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242813()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ?Parse@idMapFile@@QAA_NPBD_NPAVidMapEntity@@@Z
// EA  : 0x827A7AE8
// RVA : 0x007A7AE8
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapFile::Parse(idMapFile *this, const char *filename, bool osPath, idMapEntity *parent)
{
  const char *v5; // r28
  idStr *v9; // r3
  bool v10; // r29
  int num; // r11
  idList<idMapPrimitive *,5> *p_primitives; // r29
  int v13; // r29
  idList<enum encounterGroupRole_t,5> *p_entities; // r28
  int v15; // r30
  idStr v16; // [sp+50h] [-220h] BYREF
  idMapFile v17; // [sp+70h] [-200h] BYREF
  idStr v18; // [sp+110h] [-160h] BYREF
  idLexer v19[2]; // [sp+130h] [-140h] BYREF

  v16.len = 0;
  v16.allocedAndFlag = 20;
  v5 = filename;
  v16.data = v16.baseBuffer;
  v16.baseBuffer[0] = 0;
  if ( osPath )
  {
    fileSystem->OSPathToRelativePath(this: fileSystem, a2: filename, a3: (char *)v19, a4: 256);
    filename = (const char *)v19;
  }
  idStr::operator=(this: &this->name, text: filename);
  idStr::BackSlashesToSlashes(this: &this->name);
  idStr::StripFileExtension(this: &this->name);
  this->parentReference = parent;
  this->hasPrimitiveData = false;
  idStr::operator=(this: &v16, text: v5);
  idStr::ToLower(this: &v16);
  idStr::DefaultFileExtension(this: &v16, extension: "map");
  idLexer::idLexer(this: v19, flags_: 560);
  if ( idLexer::LoadFile(this: v19, filename_: v16.data, OSPath: osPath)
    && (unsigned __int8)idMapFile::ParseSingle(this, src: v19) != 0 )
  {
    idLexer::~idLexer(this: v19);
    v9 = idStr::Right(this: &v18, result: &v16, len: 8);
    v10 = idStr::Cmp(s1: v9->data, s2: "entities") != 0;
    idStr::FreeData(this: &v18);
    if ( v10 )
    {
      idStr::SetFileExtension(this: &v16, extension: "sound");
      idLexer::idLexer(this: v19, flags_: 560);
      if ( idLexer::LoadFile(this: v19, filename_: v16.data, OSPath: osPath) )
      {
        idMapFile::idMapFile(this: &v17);
        idStr::operator=(this: &v17.name, text: this->name.data);
        if ( (unsigned __int8)idMapFile::ParseSingle(this: &v17, src: v19) != 0 )
        {
          num = v17.entities.num;
          if ( v17.entities.num != 0 )
          {
            p_primitives = &(*v17.entities.list)->model.primitives;
            idList<idMD6Filter *,5>::Append(
              this: (idList<idMD6Filter *,5> *)&(*this->entities.list)->model.primitives,
              other: (const idList<idMD6Filter *,5> *)p_primitives);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_primitives);
            num = v17.entities.num;
          }
          v13 = 1;
          if ( num > 1 )
          {
            p_entities = (idList<enum encounterGroupRole_t,5> *)&this->entities;
            v15 = 1;
            do
            {
              idList<idAnimWebBlendTree *,5>::Append(
                this: p_entities,
                obj: (const encounterGroupRole_t *)&v17.entities.list[v15]);
              num = v17.entities.num;
              ++v13;
              ++v15;
            }
            while ( v13 < v17.entities.num );
          }
          if ( num != 0 )
          {
            if ( *v17.entities.list != nullptr )
              (***(void (__fastcall ****)(idMapEntity *, int))v17.entities.list)(a1: *v17.entities.list, a2: 1);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v17.entities);
          }
        }
        idMapFile::~idMapFile(this: &v17);
      }
      idLexer::~idLexer(this: v19);
    }
    idStr::FreeData(this: &v16);
    return 1;
  }
  else
  {
    idLexer::~idLexer(this: v19);
    idStr::FreeData(this: &v16);
    return 0;
  }
}


// ========================================================================
// __unwind$242998
// EA  : 0x827A7D8C
// RVA : 0x007A7D8C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242998()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 80));
}


// ========================================================================
// __unwind$242999
// EA  : 0x827A7DB4
// RVA : 0x007A7DB4
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_242999()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 624 + 304));
}


// ========================================================================
// __unwind$243000
// EA  : 0x827A7DDC
// RVA : 0x007A7DDC
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_243000()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 272));
}


// ========================================================================
// __unwind$243001
// EA  : 0x827A7E04
// RVA : 0x007A7E04
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_243001()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 624 + 304));
}


// ========================================================================
// __unwind$243002
// EA  : 0x827A7E2C
// RVA : 0x007A7E2C
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

void _unwind_243002()
{
  int v0; // r12

  idMapFile::~idMapFile(this: (idMapFile *)(v0 - 624 + 112));
}


// ========================================================================
// ?Reload@idMapFile@@QAA_NXZ
// EA  : 0x827A7E58
// RVA : 0x007A7E58
// PDB : w:\tech5\engine\mapfile\mapfile.cpp
// ========================================================================

int __fastcall idMapFile::Reload(idMapFile *this)
{
  char *data; // r4

  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->entities);
  data = this->name.data;
  this->hasPrimitiveData = false;
  if ( (unsigned __int8)idMapFile::Parse(this, filename: data, osPath: false, parent: nullptr) != 0 )
    return 1;
  idLib::Warning(fmt: "Map reload failed!");
  return 0;
}

