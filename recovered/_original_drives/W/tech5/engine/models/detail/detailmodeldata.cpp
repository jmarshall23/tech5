
// ========================================================================
// ?FreeData@idDetailPaletteData@@AAAXXZ
// EA  : 0x827CBC08
// RVA : 0x007CBC08
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

void __fastcall idDetailPaletteData::FreeData(idDetailPaletteData *this)
{
  idDetailModelSurface *surfaces; // r4

  surfaces = this->surfaces;
  this->material = nullptr;
  this->numSurfaces = 0;
  idMem::Free(this: &mem, ptr: surfaces, align: ALIGN_16);
  this->surfaces = nullptr;
  this->bounds.b[1].z = 0.0;
  this->bounds.b[1].y = 0.0;
  this->bounds.b[1].x = 0.0;
  this->bounds.b[0].z = 0.0;
  this->bounds.b[0].y = 0.0;
  this->bounds.b[0].x = 0.0;
}


// ========================================================================
// ?CreateDefault@idDetailPaletteData@@QAAXXZ
// EA  : 0x827CBC88
// RVA : 0x007CBC88
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

void __fastcall idDetailPaletteData::CreateDefault(idDetailPaletteData *this)
{
  idMaterial *v2; // r3
  idDetailModelSurface *v3; // r3
  idDetailModelSurface *surfaces; // r3
  detailPaletteVert_t *verts; // r31
  unsigned __int16 *indices; // r3

  v2 = (idMaterial *)idDeclInfo::FindWithInheritance(
                       this: &idMaterial::resourceList,
                       name: "genericDetailVmtr",
                       makeDefault: true);
  this->material = v2;
  if ( idMaterial::CompatibleGenericMaterial(this: v2) != nullptr )
    this->material = idMaterial::CompatibleGenericMaterial(this: this->material);
  v3 = (idDetailModelSurface *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\models\\detail\\DetailModelData.cpp(103) : TAG_DETAIL",
                                 size: 0x10u,
                                 tag: TAG_DETAIL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  this->surfaces = v3;
  v3->numIndices = 36;
  this->surfaces->numVerts = 8;
  this->surfaces->indices = (unsigned __int16 *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\engine\\models\\detail\\DetailModelData.cpp(107) : TAG_DETAIL",
                                                  size: 0x48u,
                                                  tag: TAG_DETAIL,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
  this->surfaces->verts = (detailPaletteVert_t *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\engine\\models\\detail\\DetailModelData.cpp(109) : TAG_DETAIL",
                                                   size: 0x50u,
                                                   tag: TAG_DETAIL,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
  surfaces = this->surfaces;
  verts = surfaces->verts;
  indices = surfaces->indices;
  verts->xyz[0] = -1;
  verts->xyz[1] = -1;
  verts->xyz[2] = -1;
  verts->st[0] = 0;
  *(_DWORD *)&verts->st[1] = 1;
  verts[1].xyz[1] = -1;
  verts[1].xyz[2] = -1;
  verts[1].st[0] = 0;
  *(_DWORD *)&verts[1].st[1] = 1;
  verts[2].xyz[1] = 1;
  verts[2].xyz[2] = -1;
  verts[2].st[0] = 0;
  verts[2].st[1] = 0;
  verts[3].xyz[0] = -1;
  verts[3].xyz[1] = 1;
  verts[3].xyz[2] = -1;
  verts[3].st[0] = 0;
  verts[3].st[1] = 0;
  verts[4].xyz[0] = -1;
  verts[4].xyz[1] = -1;
  verts[4].xyz[2] = 1;
  verts[4].st[0] = 0;
  *(_DWORD *)&verts[4].st[1] = 1;
  verts[5].xyz[1] = -1;
  verts[5].xyz[2] = 1;
  verts[5].st[0] = 0;
  verts[5].st[1] = 0;
  verts[7].xyz[0] = -1;
  verts[6].xyz[0] = 1;
  verts[6].xyz[1] = 1;
  verts[6].xyz[2] = 1;
  verts[6].st[0] = 0;
  verts[6].st[1] = 0;
  verts[7].xyz[1] = 1;
  verts[7].xyz[2] = 1;
  verts[7].st[0] = 0;
  verts[7].st[1] = 0;
  *indices = 2;
  indices[1] = 3;
  *((_DWORD *)indices + 1) = 1;
  indices[4] = 2;
  *(_DWORD *)(indices + 5) = 5;
  indices[7] = 1;
  *((_DWORD *)indices + 4) = 4;
  indices[10] = 5;
  *(_DWORD *)(indices + 11) = 7;
  indices[13] = 4;
  *((_DWORD *)indices + 7) = 3;
  indices[16] = 7;
  *(_DWORD *)(indices + 17) = 1;
  indices[19] = 5;
  indices[20] = 6;
  indices[21] = 2;
  indices[22] = 1;
  indices[23] = 6;
  indices[24] = 3;
  indices[25] = 2;
  indices[26] = 6;
  indices[27] = 7;
  indices[28] = 3;
  indices[29] = 6;
  indices[30] = 4;
  indices[31] = 7;
  indices[32] = 6;
  indices[33] = 5;
  indices[34] = 4;
  indices[35] = 6;
}


// ========================================================================
// ?Generate@idDetailPaletteData@@QAA_NPBD@Z
// EA  : 0x827CBEF0
// RVA : 0x007CBEF0
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

int __fastcall idDetailPaletteData::Generate(idDetailPaletteData *this, const char *name)
{
  int v2; // r23
  int v3; // r22
  char *v4; // r21
  void *v5; // r20
  char *v6; // r18
  idStaticModelSurface *v7; // r17
  idMem *v8; // r16
  char *v9; // r15
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  double v13; // fp28
  double v14; // fp27
  const idStaticModel *v17; // r3
  const idStaticModel *v18; // r14
  const idMaterial *material; // r3
  int v21; // r24
  int v22; // r27
  float *v23; // r30
  int geometry; // r25
  int v25; // r26
  idMaterial **v26; // r31
  int v27; // r29
  const idMaterial *v28; // r28
  int v30; // r11
  char *v31; // r10
  char *v32; // r9
  int v33; // r11
  double y; // fp13
  double z; // fp12
  double w; // fp11
  double v37; // fp13
  int v38; // r10
  float *v39; // r10
  double v40; // fp13
  double v41; // fp12
  double v42; // fp11
  double v43; // fp10
  double v45; // fp7
  idDetailModelSurface *v56; // r3
  idDetailModelSurface *surfaces; // r6
  detailPaletteVert_t *verts; // r30
  int v59; // [sp+50h] [-E0h]
  int v60; // [sp+54h] [-DCh]
  double v61; // [sp+58h] [-D8h] BYREF
  float x; // [sp+60h] [-D0h]
  float v63; // [sp+64h] [-CCh]
  float v64; // [sp+68h] [-C8h]
  float v65; // [sp+6Ch] [-C4h]

  v17 = staticModelManager->FindStaticModel(this: staticModelManager, a2: name, a3: false);
  v18 = v17;
  if ( v17 == nullptr || v17->surfaces.num == 0 )
    return 0;
  material = v17->surfaces.list->material;
  this->material = material;
  if ( ((LODWORD(material->virtualMapping.w)
       | LODWORD(material->virtualMapping.z)
       | LODWORD(material->virtualMapping.y)
       | LODWORD(material->virtualMapping.x))
      & 0x7FFFFFFF) == 0 )
  {
    idLib::Warning(fmt: "Detail model %s has invalid material %s", name, material->name.str);
    return 0;
  }
  if ( idMaterial::CompatibleGenericMaterial(this: material) != nullptr )
    this->material = idMaterial::CompatibleGenericMaterial(this: this->material);
  v21 = 0;
  v22 = 0;
  v23 = nullptr;
  geometry = 0;
  if ( v18->surfaces.num > 0 )
  {
    v25 = 0;
    do
    {
      v26 = (const idMaterial **)((char *)&v18->surfaces.list->material + v25);
      if ( v26 != nullptr )
      {
        v27 = (int)v26[4];
        if ( v27 != 0 )
        {
          if ( *v26 != this->material )
          {
            v28 = this->material;
            if ( idMaterial::CompatibleGenericMaterial(this: *v26) != v28 )
            {
              idLib::Error(
                fmt: "idDetailModel: material '%s' and '%s' are not compatible generic materials on '%s'",
                v28->name.str,
                (*v26)->name.str,
                v18->name.str);
              goto _LN186;
            }
          }
          v22 += *(_DWORD *)(v27 + 28);
          v23 = (float *)((char *)v23 + *(_DWORD *)(v27 + 32));
        }
      }
      ++geometry;
      v25 += 72;
    }
    while ( geometry < v18->surfaces.num );
  }
  v8 = &mem;
  v9 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\models\\detail\\DetailModelData.cpp(236) : TAG_DETAIL",
                 size: 2 * v22,
                 tag: TAG_DETAIL,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v4 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\models\\detail\\DetailModelData.cpp(237) : TAG_DETAIL",
                 size: 10 * (_DWORD)v23,
                 tag: TAG_DETAIL,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v60 = 0;
  v3 = 0;
  if ( v18->surfaces.num > 0 )
  {
    v59 = 0;
    v12 = 65535.0;
    v11 = 0.0;
    v14 = 1.0;
    v13 = -0.0099999998;
    do
    {
      v7 = &v18->surfaces.list[v59];
      if ( v7 != nullptr )
      {
        geometry = (int)v7->geometry;
        if ( geometry != 0 )
        {
          v6 = *(char **)(geometry + 92);
          if ( v6 == nullptr )
            v6 = (char *)idIndexBuffer::MapBuffer(this: (idIndexBuffer *)(geometry + 116), mapType: BM_READ);
          v5 = *(void **)(geometry + 88);
          if ( v5 == nullptr )
            v5 = idVertexBuffer::MapBuffer(this: (idVertexBuffer *)(geometry + 100), mapType: BM_READ);
          v30 = 0;
          if ( *(int *)(geometry + 28) > 0 )
          {
            v31 = v6 - 2;
            v32 = &v9[2 * v3 - 2];
            do
            {
              v31 += 2;
              ++v30;
              ++v3;
              v32 += 2;
              *(_WORD *)v32 = v21 + *(_WORD *)v31;
            }
            while ( v30 < *(_DWORD *)(geometry + 28) );
          }
          v2 = 0;
          v33 = *(_DWORD *)(geometry + 32);
          y = v7->material->virtualMapping.y;
          z = v7->material->virtualMapping.z;
          w = v7->material->virtualMapping.w;
          x = v7->material->virtualMapping.x;
          v63 = y;
          v64 = z;
          v65 = w;
          if ( v33 > 0 )
          {
            v25 = 5 * v21 + 3;
            v22 = (int)&v4[10 * v21 + 4];
            v27 = (int)v5 + 32 * v21 + 8;
            do
            {
              LODWORD(v61) = (int)*(float *)(v27 - 8);
              v26 = nullptr;
              v23 = (float *)&v61 + 1;
              v28 = (const idMaterial *)(v27 + 4);
              *(_WORD *)(v22 - 4) = LOWORD(v61);
              LODWORD(v61) = (int)*(float *)(v27 - 4);
              *(_WORD *)(v22 - 2) = LOWORD(v61);
              LODWORD(v61) = (int)*(float *)v27;
              *(_WORD *)v22 = LOWORD(v61);
              do
              {
                v10 = *(float *)&v28->__vftable;
                if ( v10 <= v13 || v10 >= v14 )
                {
_LN186:
                  *(double *)&_FP2 = v10;
                  _FP2 = floor(x: _FP2);
                  v10 = (float)((float)v10 - (float)*(double *)&_FP2);
                }
                else if ( v10 < v11 )
                {
                  v10 = v11;
                }
                v37 = v23[3];
                ++v23;
                v38 = 2 * ((_DWORD)v26 + v25);
                v26 = (idMaterial **)((char *)v26 + 1);
                v28 = (const idMaterial *)((char *)v28 + 4);
                LODWORD(v61) = (int)(float)((float)((float)(*v23 * (float)v10) + (float)v37) * (float)v12);
                *(_WORD *)&v4[v38] = LOWORD(v61);
              }
              while ( (int)v26 < 2 );
              v33 = *(_DWORD *)(geometry + 32);
              ++v2;
              v27 += 32;
              v22 += 10;
              v25 += 5;
            }
            while ( v2 < v33 );
          }
          v21 += v33;
          if ( v6 != *(char **)(geometry + 92) )
            idIndexBuffer::UnmapBuffer(this: (idIndexBuffer *)(geometry + 116));
          if ( v5 != *(void **)(geometry + 88) )
            idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)(geometry + 100));
          v39 = (float *)v7->geometry;
          v40 = this->bounds.b[0].y;
          v41 = this->bounds.b[0].z;
          v42 = this->bounds.b[1].x;
          v43 = this->bounds.b[1].y;
          _FP8 = (float)(this->bounds.b[0].x - *v39);
          v45 = this->bounds.b[1].z;
          __asm { fsel      f6, f8, f9, f0 }
          this->bounds.b[0].x = _FP6;
          _FP4 = (float)((float)v40 - v39[1]);
          __asm { fsel      f3, f4, f5, f13 }
          this->bounds.b[0].y = _FP3;
          *((double *)&_FP2 + 1) = v39[2];
          *(double *)&_FP2 = (float)((float)v41 - v39[2]);
          __asm { fsel      f0, f1, f2, f12 }
          this->bounds.b[0].z = _FP0;
          _FP12 = (float)(v39[3] - (float)v42);
          __asm { fsel      f11, f12, f13, f11 }
          this->bounds.b[1].x = _FP11;
          _FP8 = (float)(v39[4] - (float)v43);
          __asm { fsel      f6, f8, f9, f10 }
          this->bounds.b[1].y = _FP6;
          _FP4 = (float)(v39[5] - (float)v45);
          __asm { fsel      f3, f4, f5, f7 }
          this->bounds.b[1].z = _FP3;
        }
      }
      ++v59;
      ++v60;
    }
    while ( v60 < v18->surfaces.num );
  }
  v56 = (idDetailModelSurface *)idMem::AllocWithLocation(
                                  this: v8,
                                  location: "w:\\tech5\\engine\\models\\detail\\DetailModelData.cpp(303) : TAG_DETAIL",
                                  size: 0x10u,
                                  tag: TAG_DETAIL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  this->surfaces = v56;
  v56->numIndices = v3;
  this->surfaces->numVerts = v21;
  this->surfaces->indices = (unsigned __int16 *)idMem::AllocWithLocation(
                                                  this: v8,
                                                  location: "w:\\tech5\\engine\\models\\detail\\DetailModelData.cpp(308) : TAG_DETAIL",
                                                  size: (2 * (v3 + 1)) & 0xFFFFFFFC,
                                                  tag: TAG_DETAIL,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
  this->surfaces->verts = (detailPaletteVert_t *)idMem::AllocWithLocation(
                                                   this: v8,
                                                   location: "w:\\tech5\\engine\\models\\detail\\DetailModelData.cpp(309) : TAG_DETAIL",
                                                   size: 10 * v21,
                                                   tag: TAG_DETAIL,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
  surfaces = this->surfaces;
  verts = surfaces->verts;
  memcpy(Dst: surfaces->indices, Src: v9, Size: 2 * v3);
  memcpy(Dst: verts, Src: v4, Size: 10 * v21);
  ++this->numSurfaces;
  idMem::Free(this: v8, ptr: v9, align: ALIGN_16);
  idMem::Free(this: v8, ptr: v4, align: ALIGN_16);
  return 1;
}


// ========================================================================
// ?FreeData@idDetailModelData@@QAAXXZ
// EA  : 0x827CC498
// RVA : 0x007CC498
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

void __fastcall idDetailModelData::FreeData(idDetailModelData *this)
{
  idDetailPaletteData *paletteData; // r30

  paletteData = this->paletteData;
  if ( paletteData != nullptr )
  {
    idDetailPaletteData::FreeData(this: this->paletteData);
    idMem::Free(this: &mem, ptr: paletteData, align: ALIGN_16);
    this->paletteData = nullptr;
    this->paletteIdx = -1;
  }
  else
  {
    this->paletteIdx = -1;
  }
}


// ========================================================================
// ??0idDetailModelData@@QAA@XZ
// EA  : 0x827CC518
// RVA : 0x007CC518
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

idDetailModelData *__fastcall idDetailModelData::idDetailModelData(idDetailModelData *this)
{
  idResource::idResource(this);
  this->paletteData = nullptr;
  this->__vftable = (idDetailModelData_vtbl *)&idDetailModelData::`vftable';
  this->paletteIdx = -1;
  idDetailModelData::FreeData(this);
  return this;
}


// ========================================================================
// __unwind$231397
// EA  : 0x827CC57C
// RVA : 0x007CC57C
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

void _unwind_231397()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDetailModelData@@UAA@XZ
// EA  : 0x827CC5C0
// RVA : 0x007CC5C0
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

void __fastcall idDetailModelData::~idDetailModelData(idDetailModelData *this)
{
  this->__vftable = (idDetailModelData_vtbl *)&idDetailModelData::`vftable';
  idDetailModelData::FreeData(this);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$231416
// EA  : 0x827CC610
// RVA : 0x007CC610
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

void _unwind_231416()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?Generate@idDetailModelData@@QAA_NXZ
// EA  : 0x827CC740
// RVA : 0x007CC740
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

int __fastcall idDetailModelData::Generate(idDetailModelData *this)
{
  idDetailPaletteData *v2; // r3
  idDetailPaletteData **p_paletteData; // r30
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  int v7; // r10
  idDetailPaletteData **list; // r11
  idDetailModelSurface *surfaces; // r6
  int numVerts; // r5
  int numIndices; // r9
  idDetailPaletteData *v13; // r31
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  int v17; // [sp+14h] [-6Ch]
  int v18; // [sp+18h] [-68h]
  int v19; // [sp+1Ch] [-64h]

  v2 = (idDetailPaletteData *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x24u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
  {
    v2->material = nullptr;
    v2->numSurfaces = 0;
    v2->surfaces = nullptr;
    v2->bounds.b[1].z = 0.0;
    v2->bounds.b[1].y = 0.0;
    v2->bounds.b[1].x = 0.0;
    v2->bounds.b[0].z = 0.0;
    v2->bounds.b[0].y = 0.0;
    v2->bounds.b[0].x = 0.0;
  }
  else
  {
    v2 = nullptr;
  }
  this->paletteData = v2;
  p_paletteData = &this->paletteData;
  if ( (unsigned __int8)idDetailPaletteData::Generate(this: v2, name: this->name.str) == 0 )
  {
    HIDWORD(v6) = this->name.str;
    idResource::SetResourceError(
      this,
      fmt: "defaulted '%s'",
      a3: v6,
      a4: v5,
      a5: v4,
      a6: v14,
      a7: v15,
      a8: v16,
      a9: v17,
      a10: v18,
      a11: v19);
    idDetailPaletteData::CreateDefault(this: *p_paletteData);
  }
  v7 = 0;
  if ( idDetailModelData::palette.num > 0 )
  {
    list = idDetailModelData::palette.list;
    while ( *list != *p_paletteData )
    {
      ++v7;
      ++list;
      if ( v7 >= idDetailModelData::palette.num )
        goto LABEL_12;
    }
    if ( v7 >= 0 )
      goto LABEL_16;
  }
LABEL_12:
  surfaces = (*p_paletteData)->surfaces;
  numVerts = surfaces->numVerts;
  if ( surfaces->numVerts <= 50 )
  {
    numIndices = surfaces->numIndices;
    if ( numIndices <= 300
      && 2 * (5 * (numVerts + paletteStats_0.totalNumVerts) + numIndices + paletteStats_0.totalNumIndices) <= 0x8000 )
    {
      paletteStats_0.totalNumVerts += numVerts;
      paletteStats_0.totalNumIndices += numIndices;
      ++paletteStats_0.totalNumModels;
LABEL_16:
      this->paletteIdx = idList<idDeclMD6 const *,5>::AddUnique(
                           this: (idList<idVoiceEvent const *,5> *)&idDetailModelData::palette,
                           obj: (const idVoiceEvent *const *)&this->paletteData);
      return 1;
    }
  }
  idLib::Warning(
    fmt: "Can't add model %s - exceeds limitations: numverts %d numindices %d palette full",
    this->name.str,
    numVerts,
    surfaces->numIndices);
  v13 = *p_paletteData;
  if ( *p_paletteData != nullptr )
  {
    idDetailPaletteData::FreeData(this: *p_paletteData);
    idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
  }
  *p_paletteData = nullptr;
  this->paletteIdx = -1;
  return 0;
}


// ========================================================================
// ?LoadResource@idDetailModelData@@UAAXXZ
// EA  : 0x827CC918
// RVA : 0x007CC918
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

void __fastcall idDetailModelData::LoadResource(idDetailModelData *this)
{
  idDetailModelData::FreeData(this);
  idDetailModelData::Generate(this);
}


// ========================================================================
// `dynamic initializer for 'idDetailModelData::resourceList''
// EA  : 0x83342618
// RVA : 0x01342618
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDetailModelData::resourceList__()
{
  idResourceList::idResourceList(this: &idDetailModelData::resourceList, typeName: "detailModelData");
  idDetailModelData::resourceList.__vftable = (idTypedResourceList<idDetailModelData>_vtbl *)&idTypedResourceList<idDetailModelData>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDetailModelData::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'idDetailModelData::palette''
// EA  : 0x83342668
// RVA : 0x01342668
// PDB : w:\tech5\engine\models\detail\detailmodeldata.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDetailModelData::palette__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDetailModelData::palette__);
}

